/***********************************************************************/
/* This file contains information proprietary to Cortina Systems, Inc. */
/* (Cortina). Any use or disclosure, in whole or in part, of this      */
/* information to any unauthorized party, for any purposes other than  */
/* that for which it is provided is expressly prohibited except as     */
/* authorized by Cortina in writing. Cortina reserves its rights to    */
/* pursue both civil and criminal penalties for copying or disclosure  */
/* of this material without authorization. Cortina Systems (R),        */
/* Cortina (TM) and the Cortina Systems Earth Logo are the trademarks  */
/* or registered trademarks of Cortina Systems, Inc. and its           */
/* subsidiaries in the U.S. and other countries. Any other product     */
/* and company names are the trademarks of their respective owners.    */
/* Copyright (C) 2006-2013 Cortina Systems, Inc. All rights reserved.  */
/***********************************************************************/
/*
 * ten_hsif.c
 *
 * HSIF related code is implemented here.
 *
 * $Id: ten_hsif.c,v 1.15 2013/02/22 20:49:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  HSIF RESET                                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_reset(cs_uint16 module_id, 
                         cs_reset_action_t act,
                         cs_uint16 bitfield)
/* INPUTS     : o Module Id                                         */
/*              o Reset Action                                      */
/*              o Bitfield                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a logic reset for the affected (masked on) HSIF         */
/* selections.                                                      */
/*                                                                  */
/* The [act] parameter is specified as:                             */
/*   Reset option specified as CS_RESET_DEASSERT,                   */
/*   CS_RESET_ASSERT or CS_RESET_TOGGLE.                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset bit(s) for 20 milliseconds and then de-assert.           */
/*                                                                  */
/* The [bitfield] parameter is specified as:                        */
/*   TEN_HSIF_RESET_TX_MASTER  = 0x0001,                            */
/*   TEN_HSIF_RESET_TX_SFI5    = 0x0002,                            */
/*   TEN_HSIF_RESET_TX_SFI41   = 0x0004,                            */
/*   TEN_HSIF_RESET_TX_SFI42_0 = 0x0010,                            */
/*   TEN_HSIF_RESET_TX_SFI42_1 = 0x0020,                            */
/*   TEN_HSIF_RESET_TX_SFI42_2 = 0x0040,                            */
/*   TEN_HSIF_RESET_TX_SFI42_3 = 0x0080,                            */
/*   TEN_HSIF_RESET_RX_MASTER  = 0x0100,                            */
/*   TEN_HSIF_RESET_RX_SFI5    = 0x0200,                            */
/*   TEN_HSIF_RESET_RX_SFI41   = 0x0400,                            */
/*   TEN_HSIF_RESET_RX_SFI42_0 = 0x1000,                            */
/*   TEN_HSIF_RESET_RX_SFI42_1 = 0x2000,                            */
/*   TEN_HSIF_RESET_RX_SFI42_2 = 0x4000,                            */
/*   TEN_HSIF_RESET_RX_SFI42_3 = 0x8000,                            */
/*   TEN_HSIF_RESET_ALL        = 0xF7F7                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_Reset_t tmp_reset;
  T41_t *pDev = NULL;

  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": act = 0x%04X\n", act);
      return (CS_ERROR);
  }
  if (bitfield > TEN_HSIF_RESET_ALL) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": bitfield = 0x%04X\n", bitfield);
      return (CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);

  /* set mask bits for affected selections */
  tmp_reset.wrd = bitfield;
  ten_reset_action(TEN_HSIF_REG_ADDR(pDev, module_id, Reset), tmp_reset.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF PROVISION DATAPATH                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_provision_datapath(cs_uint16 module_id, cs_uint8 instance, 
                              cs_uint16 tx_xfiselect, 
                              cs_uint16 rx_xfiselect, 
                              cs_uint16 tx_pswtchen, 
                              cs_uint16 tx_mrprotocol, 
                              cs_uint16 rx_pswtchen, 
                              cs_uint16 rx_mrprotocol)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Tx Xfiselect                                      */
/*              o Rx Xfiselect                                      */
/*              o Tx Pswtchen                                       */
/*              o Tx Mrprotocol                                     */
/*              o Rx Pswtchen                                       */
/*              o Rx Mrprotocol                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the line protocol for each slice.                     */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [tx_xfiselect]                                                 */
/*    1 = XFI                                                       */
/*    0 = protocol selected by tx_mrprotocol (default)              */
/*                                                                  */
/*   [rx_xfiselect]                                                 */
/*    1 = XFI                                                       */
/*    0 = protocol selected by rx_mrprotocol (default)              */
/*                                                                  */
/*   [tx_pswtchen]                                                  */
/*    1 = Enabled.  Data is driven from remote interface.           */
/*    0 = disabled                                                  */
/*                                                                  */
/*   [tx_mrprotocol]                                                */
/*    110 = XAUI                                                    */
/*    101 = SFI4. 2 (40G)                                           */
/*    100 = SFI4. 2 (10G)                                           */
/*    010 = SFI4. 1                                                 */
/*    001 = SFI5 (default)                                          */
/*    000 = disabled                                                */
/*                                                                  */
/*   [rx_pswtchen]                                                  */
/*    1 = Enabled.  Data is driven from remote interface.           */
/*    0 = disabled.                                                 */
/*                                                                  */
/*   [rx_mrprotocol]                                                */
/*    110 = XAUI                                                    */
/*    101 = SFI4. 2 (40G)                                           */
/*    100 = SFI4. 2 (10G)                                           */
/*    010 = SFI4. 1                                                 */
/*    001 = SFI5 (default)                                          */
/*    000 = disabled                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_Datapath_Prov0_t tmp_datapath_prov0;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hsif_provision_datapath";  

  if ((instance>=TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..3.", func, instance);
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  /* CS_PRINT("%s()\n", func); */
  CS_PRINT("   %s\n", ten_module_strings[module_id&1]);
  if (instance < TEN_INSTANCE_ALL) {
    CS_PRINT("   %s\n", ten_slice_strings[instance]);
  } else {
    CS_PRINT("   TEN_INSTANCE_ALL\n");
  }
  CS_PRINT("   tx_xfiselect = %s\n", (tx_xfiselect==1) ? "XFI" : "protocol selected by tx_mrprotocol");
  CS_PRINT("   rx_xfiselect = %s\n", (rx_xfiselect==1) ? "XFI" : "protocol selected by rx_mrprotocol");
  CS_PRINT("   tx_pswtchen = %d\n", tx_pswtchen);
  CS_PRINT("   tx_mrprotocol = %s\n", ten_hsif_protocols_strings[tx_mrprotocol]);
  CS_PRINT("   rx_pswtchen = %d\n", rx_pswtchen);
  CS_PRINT("   rx_mrprotocol = %s\n", ten_hsif_protocols_strings[rx_mrprotocol]);
  
  

  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_datapath_prov0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE);
      tmp_datapath_prov0.bf.tx_xfiselect = tx_xfiselect;
      tmp_datapath_prov0.bf.rx_xfiselect = rx_xfiselect;
      tmp_datapath_prov0.bf.tx_pswtchen = tx_pswtchen;
      tmp_datapath_prov0.bf.tx_mrprotocol = tx_mrprotocol;
      tmp_datapath_prov0.bf.rx_pswtchen = rx_pswtchen;
      tmp_datapath_prov0.bf.rx_mrprotocol = rx_mrprotocol;
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE, tmp_datapath_prov0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF PROVISION DATAPATH T41                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_provision_datapath_t41(cs_uint16 module_id, 
                                          cs_uint8 instance, 
                                          cs_uint16 tx_pswtchen, 
                                          cs_uint16 tx_mrprotocol, 
                                          cs_uint16 rx_pswtchen, 
                                          cs_uint16 rx_mrprotocol)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Tx Pswtchen                                       */
/*              o Tx Mrprotocol                                     */
/*              o Rx Pswtchen                                       */
/*              o Rx Mrprotocol                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the line protocol for each slice.                     */
/* Avoids setting xfiselect bits so that protection switching on    */
/* the same port can be used, ie, XFI on a port and MR on that same */
/* port but in protection switch mode.                              */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [tx_pswtchen]                                                  */
/*    1 = Enabled.  Data is driven from remote interface.           */
/*    0 = disabled                                                  */
/*                                                                  */
/*   [tx_mrprotocol]                                                */
/*    110 = XAUI                                                    */
/*    101 = SFI4. 2 (40G)                                           */
/*    100 = SFI4. 2 (10G)                                           */
/*    010 = SFI4. 1                                                 */
/*    001 = SFI5 (default)                                          */
/*    000 = disabled                                                */
/*                                                                  */
/*   [rx_pswtchen]                                                  */
/*    1 = Enabled.  Data is driven from remote interface.           */
/*    0 = disabled.                                                 */
/*                                                                  */
/*   [rx_mrprotocol]                                                */
/*    110 = XAUI                                                    */
/*    101 = SFI4. 2 (40G)                                           */
/*    100 = SFI4. 2 (10G)                                           */
/*    010 = SFI4. 1                                                 */
/*    001 = SFI5 (default)                                          */
/*    000 = disabled                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_Datapath_Prov0_t tmp_datapath_prov0;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hsif_provision_datapath_t41";

  if ((instance>=TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..3.", func, instance);
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  CS_PRINT("%s()\n", func);
  CS_PRINT("   %s\n", ten_module_strings[module_id&1]);
  if (instance < TEN_INSTANCE_ALL) {
    CS_PRINT("   %s\n", ten_slice_strings[instance]);
  } else {
    CS_PRINT("   TEN_INSTANCE_ALL\n");
  }
  CS_PRINT("   tx_pswtchen = %d\n", tx_pswtchen);
  CS_PRINT("   tx_mrprotocol = %s\n", ten_hsif_protocols_strings[tx_mrprotocol]);
  CS_PRINT("   rx_pswtchen = %d\n", rx_pswtchen);
  CS_PRINT("   rx_mrprotocol = %s\n", ten_hsif_protocols_strings[rx_mrprotocol]);
  
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_datapath_prov0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE);
      tmp_datapath_prov0.bf.tx_pswtchen = tx_pswtchen;
      tmp_datapath_prov0.bf.tx_mrprotocol = tx_mrprotocol;
      tmp_datapath_prov0.bf.rx_pswtchen = rx_pswtchen;
      tmp_datapath_prov0.bf.rx_mrprotocol = rx_mrprotocol;
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE, tmp_datapath_prov0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF PROVISION MR PROTOCOL                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_provision_mrprotocol(cs_uint16 module_id,
                                        cs_uint8  instance, 
                                        cs_dir_t  dir,
                                        cs_uint16 mrprotocol)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Direction                                         */
/*              o Multirate Protocol                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the line protocol for each slice.                     */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [dir] parameter is specified as:                               */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/*   [mrprotocol]                                                   */
/*    110 = XAUI                                                    */
/*    101 = SFI4. 2 (40G)                                           */
/*    100 = SFI4. 2 (10G)                                           */
/*    010 = SFI4. 1                                                 */
/*    001 = SFI5 (default)                                          */
/*    000 = disabled                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_Datapath_Prov0_t tmp_datapath_prov0;
  T41_t *pDev = NULL;

  if ((instance>=TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) { 
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": dir out of range"); 
    return(CS_ERROR); 
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_datapath_prov0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE);
      if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        tmp_datapath_prov0.bf.tx_mrprotocol = mrprotocol;
      }
      if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        tmp_datapath_prov0.bf.rx_mrprotocol = mrprotocol;
      }
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE, tmp_datapath_prov0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF PROVISION TX_XFISELECT                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_provision_tx_xfiselect(cs_uint16 module_id,
                                          cs_uint8 instance, 
                                          cs_uint16 tx_xfiselect)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Tx Xfiselect                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the line protocol for each slice.                     */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [tx_xfiselect]                                                 */
/*    1 = XFI                                                       */
/*    0 = protocol selected by tx_mrprotocol (default)              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_Datapath_Prov0_t tmp_datapath_prov0;
  T41_t *pDev = NULL;

  if ((instance>=TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_datapath_prov0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE);
      tmp_datapath_prov0.bf.tx_xfiselect = tx_xfiselect;
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE, tmp_datapath_prov0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF PROVISION RX_XFISELECT                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_provision_rx_xfiselect(cs_uint16 module_id,
                                          cs_uint8 instance, 
                                          cs_uint16 rx_xfiselect)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Rx Xfiselect                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the line protocol for each slice.                     */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [rx_xfiselect]                                                 */
/*    1 = XFI                                                       */
/*    0 = protocol selected by rx_mrprotocol (default)              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_Datapath_Prov0_t tmp_datapath_prov0;
  T41_t *pDev = NULL;

  if ((instance>=TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_datapath_prov0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE);
      tmp_datapath_prov0.bf.rx_xfiselect = rx_xfiselect;
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE, tmp_datapath_prov0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF PROVISION PSWTCHEN                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_provision_pswtchen(cs_uint16 module_id, 
                                      cs_uint8 instance, 
                                      cs_dir_t dir, 
                                      cs_uint16 pswtchen)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Direction                                         */
/*              o Pswtchen                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the pswtchen.                                         */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [dir]                                                          */
/*                                                                  */
/*   [pswtchen]                                                     */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_Datapath_Prov0_t tmp_datapath_prov0;
  T41_t *pDev = NULL;

  if ((instance>=TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if ((dir != CS_RX) && (dir != CS_TX)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dir out of range.  s/b 0..1.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_datapath_prov0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE);
      if (dir == CS_TX) {
        tmp_datapath_prov0.bf.tx_pswtchen = pswtchen;
      }
      else if (dir == CS_RX) {
        tmp_datapath_prov0.bf.rx_pswtchen = pswtchen;
      }
      
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
      ii * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE, tmp_datapath_prov0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF IS XAUI ACTIVE                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_hsif_is_xaui_active(cs_uint16 module_id, cs_uint8 instance)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* Returns whether XAUI is active or not.                           */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 tx_xfisel, rx_xfisel;
  cs_uint16 tx_mrsel, rx_mrsel;

  /* Check for XFI or XAUI */
  tx_xfisel = ten_hsif_get_provisioned_datapath(module_id, instance,
                      TEN_HSIF_DATAPATH_PROV_XFISELECT, CS_TX);
  rx_xfisel = ten_hsif_get_provisioned_datapath(module_id, instance,
                      TEN_HSIF_DATAPATH_PROV_XFISELECT, CS_RX);
                      
  tx_mrsel  = ten_hsif_get_provisioned_datapath(module_id, instance,
                     TEN_HSIF_DATAPATH_PROV_MRPROTOCOL, CS_TX);
  rx_mrsel  = ten_hsif_get_provisioned_datapath(module_id, instance,
                     TEN_HSIF_DATAPATH_PROV_MRPROTOCOL, CS_RX); 

  if ((!tx_xfisel) && (!rx_xfisel) && 
      (tx_mrsel == TEN_HSIF_PROTOCOL_XAUI) && 
      (rx_mrsel == TEN_HSIF_PROTOCOL_XAUI)) {
    return (1); 
  }
  else {
    return (0); /* non-XAUI active */
  }
}

/********************************************************************/
/* $rtn_hdr_start  HSIF IS SFI42 ACTIVE                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_hsif_is_sfi42_active(cs_uint16 module_id, cs_uint8 instance)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* Returns whether SFI4.2 is active or not.                         */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 tx_xfisel, rx_xfisel;
  cs_uint16 tx_mrsel, rx_mrsel;

  /* Check for SFI4.2 */
  tx_xfisel = ten_hsif_get_provisioned_datapath(module_id, instance,
                      TEN_HSIF_DATAPATH_PROV_XFISELECT, CS_TX);
  rx_xfisel = ten_hsif_get_provisioned_datapath(module_id, instance,
                      TEN_HSIF_DATAPATH_PROV_XFISELECT, CS_RX);
                      
  tx_mrsel  = ten_hsif_get_provisioned_datapath(module_id, instance,
                     TEN_HSIF_DATAPATH_PROV_MRPROTOCOL, CS_TX);
  rx_mrsel  = ten_hsif_get_provisioned_datapath(module_id, instance,
                     TEN_HSIF_DATAPATH_PROV_MRPROTOCOL, CS_RX); 

  if ((!tx_xfisel) && (!rx_xfisel) && 
      (tx_mrsel == TEN_HSIF_PROTOCOL_SFI42_10G) && 
      (rx_mrsel == TEN_HSIF_PROTOCOL_SFI42_10G)) {
    return (1); 
  }
  else if ((!tx_xfisel) && (!rx_xfisel) && 
      (tx_mrsel == TEN_HSIF_PROTOCOL_SFI42_40G) && 
      (rx_mrsel == TEN_HSIF_PROTOCOL_SFI42_40G)) {
    return (1); 
  }
  else {
    return (0); 
  }
}

/********************************************************************/
/* $rtn_hdr_start  HSIF GET PROVISIONED DATAPATH                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_hsif_get_provisioned_datapath(cs_uint16 module_id, cs_uint8 instance,
                                            cs_uint16 select, 
                                            cs_dir_t dir)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Select                                            */
/*              o Dir                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* Returns the provisioned datapath.                                */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3                                            */
/*                                                                  */
/*   [select]                                                       */
/*    TEN_HSIF_DATAPATH_PROV_MRPROTOCOL = 0,                        */
/*    TEN_HSIF_DATAPATH_PROV_XFISELECT  = 1                         */
/*                                                                  */
/*   [dir] parameter is specified as:                               */
/*     0 = CS_TX                                                    */
/*     1 = CS_RX                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 rtn;
  TEN_HSIF_PROTOCOL_Datapath_Prov0_t tmp_datapath_prov0;
  T41_t *pDev = NULL;

  if (instance>=TEN_HSIF_PROTOCOL_Datapath_Prov0_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(0);
  }

  if ((select != TEN_HSIF_DATAPATH_PROV_MRPROTOCOL) && 
      (select != TEN_HSIF_DATAPATH_PROV_XFISELECT)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..1.");
    return(0);
  }
  
  if ((dir != CS_RX) && (dir != CS_TX)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dir out of range.  s/b 0..1.");
    return(0);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_datapath_prov0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0) +
                           instance * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE);
  if (select == TEN_HSIF_DATAPATH_PROV_MRPROTOCOL) {
    if (dir == CS_RX) {
      rtn = tmp_datapath_prov0.bf.rx_mrprotocol;
    }  
    else {
      rtn = tmp_datapath_prov0.bf.tx_mrprotocol;
    }
  }
  else {
    if (dir == CS_RX) {
      rtn = tmp_datapath_prov0.bf.rx_xfiselect;
    }  
    else {
      rtn = tmp_datapath_prov0.bf.tx_xfiselect;
    }
  }
  return (rtn);
}


/********************************************************************/
/* $rtn_hdr_start  HSIF SET TX LANESWAP                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_tx_laneswap(cs_uint16 module_id, cs_uint8 instance, 
                                   cs_uint16 lane)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Lane                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Allows MR TX lane 'instance' to be remapped to any other         */
/* functional lane.  NOTE: These values are not retimed to any      */
/* particular functional clock because depending on the             */
/* configuration, the functional clock may vary.  This API should   */
/* only be called when the datapath is held in reset to avoid       */
/* metastability issues.                                            */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [lane]  Determines what internal lane serdes tx lane           */
/*     'instance' is mapped to.  Only 0-16 are valid values.        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_TXLANESWAP0_t tmp_txlaneswap0;
  T41_t *pDev = NULL;

  if ((instance>=TEN_HSIF_PROTOCOL_TXLANESWAP0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_TXLANESWAP0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_txlaneswap0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP0) +
      ii * TEN_HSIF_PROTOCOL_TXLANESWAP0_STRIDE);
      tmp_txlaneswap0.bf.lane = lane;
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP0) +
      ii * TEN_HSIF_PROTOCOL_TXLANESWAP0_STRIDE, tmp_txlaneswap0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SET RX LANESWAP                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_rx_laneswap(cs_uint16 module_id, cs_uint8 instance, 
                                   cs_uint16 lane)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Lane                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Allows MR RX lane 'instance' to be remapped to any other         */
/* functional lane.  NOTE:  These values are not retimed to any     */
/* particular functional clock because depending on the             */
/* configuration, the functional clock may vary.  This API should   */
/* only be called when the datapath is held in reset to avoid       */
/* metastability issues.                                            */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [lane]  Determines what internal lane serdes tx lane           */
/*     'instance' is mapped to.  Only 0-16 are valid values.        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_RXLANESWAP0_t tmp_rxlaneswap0;
  T41_t *pDev = NULL;

  if ((instance>=TEN_HSIF_PROTOCOL_RXLANESWAP0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..17.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_RXLANESWAP0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_rxlaneswap0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP0) +
      ii * TEN_HSIF_PROTOCOL_RXLANESWAP0_STRIDE);
      tmp_rxlaneswap0.bf.lane = lane;
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP0) +
      ii * TEN_HSIF_PROTOCOL_RXLANESWAP0_STRIDE, tmp_rxlaneswap0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF FACILITY LOOPBACK                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_facility_loopback(cs_uint16 module_id, 
                                     cs_uint8 instance, 
                                     cs_ctl_t ctl)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the device in RX-TX (facility) loopback on a 10G      */
/* slice basis.                                                     */
/*                                                                  */
/* [instance]  Slice 0..3 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/* [ctl]  Controls loopback.                                        */
/*   0 = CS_DISABLE                                                 */
/*   1 = CS_ENABLE                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_LBCFG_t tmp_lbcfg;
  T41_t *pDev = NULL;
   
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_lbcfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG));

  if ((instance == 3) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbcfg.bf.rxtxlb3_en = (ctl == CS_ENABLE);
  }
  
  if ((instance == 2) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbcfg.bf.rxtxlb2_en = (ctl == CS_ENABLE);
  }
  
  if ((instance == 1) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbcfg.bf.rxtxlb1_en = (ctl == CS_ENABLE);
  }
  
  if ((instance == 0) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbcfg.bf.rxtxlb0_en = (ctl == CS_ENABLE);
  }
  
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG), tmp_lbcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF FAR END LOOPBACK                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_far_end_loopback(cs_uint16 module_id, 
                                     cs_uint8 instance, 
                                     cs_ctl_t ctl)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the device in TX-RX (far end) loopback on a 10G       */
/* slice basis.                                                     */
/*                                                                  */
/* [instance]  Slice 0..3 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/* [ctl]  Controls loopback.                                        */
/*   0 = CS_DISABLE                                                 */
/*   1 = CS_ENABLE                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_LBCFG_t tmp_lbcfg;
  T41_t *pDev = NULL;
   
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_lbcfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG));

  if ((instance == 3) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbcfg.bf.txrxlb3_en = (ctl == CS_ENABLE);
  }
  
  if ((instance == 2) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbcfg.bf.txrxlb2_en = (ctl == CS_ENABLE);
  }
  
  if ((instance == 1) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbcfg.bf.txrxlb1_en = (ctl == CS_ENABLE);
  }
  
  if ((instance == 0) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbcfg.bf.txrxlb0_en = (ctl == CS_ENABLE);
  }
  
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG), tmp_lbcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF TX RX ELASTIC STORE CONTROL                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_tx_rx_elastic_store_control(cs_uint16 module_id, 
                                               cs_uint8 instance,  
                                               cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the reinitialization of all loopback elastic stores.    */
/*                                                                  */
/* [instance]  Slice 0..3 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/* [act]  specifies the reset option and is one of the following:   */
/*   0 = CS_RESET_DEASSERT                                          */
/*   1 = CS_RESET_ASSERT                                            */
/*   2 = CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset for a while and then de-assert the reset bit(s).         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_LBELSTCTRL_t tmp_lbelstctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_lbelstctrl.wrd = TEN_HSIF_PROTOCOL_LBELSTCTRL_dft;

  if ((instance == 3) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbelstctrl.bf.TXRXLB3_INIT = 1;
  }
  
  if ((instance == 2) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbelstctrl.bf.TXRXLB2_INIT = 1;
  }
  
  if ((instance == 1) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbelstctrl.bf.TXRXLB1_INIT = 1;
  }
  
  if ((instance == 0) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbelstctrl.bf.TXRXLB0_INIT = 1;
  }

  ten_reset_action(TEN_HSIF_REG_ADDR(pDev, module_id, LBELSTCTRL), tmp_lbelstctrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);
  return (CS_OK);
}  

/********************************************************************/
/* $rtn_hdr_start  HSIF RX TX ELASTIC STORE CONTROL                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_rx_tx_elastic_store_control(cs_uint16 module_id, 
                                               cs_uint8 instance,  
                                               cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the reinitialization of all loopback elastic stores.    */
/*                                                                  */
/* [instance]  Slice 0..3 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/* [act]  specifies the reset option and is one of the following:   */
/*   0 = CS_RESET_DEASSERT                                          */
/*   1 = CS_RESET_ASSERT                                            */
/*   2 = CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset for a while and then de-assert the reset bit(s).         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_LBELSTCTRL_t tmp_lbelstctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_lbelstctrl.wrd = TEN_HSIF_PROTOCOL_LBELSTCTRL_dft;

  if ((instance == 3) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbelstctrl.bf.RXTXLB3_INIT = 1;
  }
  
  if ((instance == 2) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbelstctrl.bf.RXTXLB2_INIT = 1;
  }
  
  if ((instance == 1) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbelstctrl.bf.RXTXLB1_INIT = 1;
  }
  
  if ((instance == 0) || (instance == TEN_INSTANCE_ALL)) {
    tmp_lbelstctrl.bf.RXTXLB0_INIT = 1;
  }

  ten_reset_action(TEN_HSIF_REG_ADDR(pDev, module_id, LBELSTCTRL), tmp_lbelstctrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);
  return (CS_OK);
}  

/********************************************************************/
/* $rtn_hdr_start  HSIF TX PROTECTION SWITCHING ELASTIC STORE CONTROL */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_tx_protection_switching_elastic_store_control(cs_uint16 module_id, 
                                               cs_uint8 instance,  
                                               cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the reinitialization of all TX protection switching     */
/* elastic stores.                                                  */
/*                                                                  */
/* [instance]  Slice 0..3 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/* [act]  specifies the reset option and is one of the following:   */
/*   0 = CS_RESET_DEASSERT                                          */
/*   1 = CS_RESET_ASSERT                                            */
/*   2 = CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset for a while and then de-assert the reset bit(s).         */
/*                                                                  */
/* $rtn_hdr_end                                                     */                                               
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_PSELSTCTRL_t tmp_pselstctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  
  tmp_pselstctrl.wrd = TEN_HSIF_PROTOCOL_LBELSTCTRL_dft;

  if ((instance == 3) || (instance == TEN_INSTANCE_ALL)) {
    tmp_pselstctrl.bf.TX3INIT = 1;
  }
  
  if ((instance == 2) || (instance == TEN_INSTANCE_ALL)) {
    tmp_pselstctrl.bf.TX2INIT = 1;
  }
  
  if ((instance == 1) || (instance == TEN_INSTANCE_ALL)) {
    tmp_pselstctrl.bf.TX1INIT = 1;
  }
  
  if ((instance == 0) || (instance == TEN_INSTANCE_ALL)) {
    tmp_pselstctrl.bf.TX0INIT = 1;
  }

  ten_reset_action(TEN_HSIF_REG_ADDR(pDev, module_id, PSELSTCTRL), tmp_pselstctrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);
  return (CS_OK);
}  

/********************************************************************/
/* $rtn_hdr_start  HSIF RX PROTECTION SWITCHING ELASTIC STORE CONTROL */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_rx_protection_switching_elastic_store_control(cs_uint16 module_id, 
                                               cs_uint8 instance,  
                                               cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the reinitialization of all RX protection switching     */
/* elastic stores.                                                  */
/*                                                                  */
/* [instance]  Slice 0..3 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/* [act]  specifies the reset option and is one of the following:   */
/*   0 = CS_RESET_DEASSERT                                          */
/*   1 = CS_RESET_ASSERT                                            */
/*   2 = CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset for a while and then de-assert the reset bit(s).         */
/*                                                                  */
/* $rtn_hdr_end                                                     */                                               
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_PSELSTCTRL_t tmp_pselstctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  
  tmp_pselstctrl.wrd = TEN_HSIF_PROTOCOL_LBELSTCTRL_dft;

  if ((instance == 3) || (instance == TEN_INSTANCE_ALL)) {
    tmp_pselstctrl.bf.RX3INIT = 1;
  }
  
  if ((instance == 2) || (instance == TEN_INSTANCE_ALL)) {
    tmp_pselstctrl.bf.RX2INIT = 1;
  }
  
  if ((instance == 1) || (instance == TEN_INSTANCE_ALL)) {
    tmp_pselstctrl.bf.RX1INIT = 1;
  }
  
  if ((instance == 0) || (instance == TEN_INSTANCE_ALL)) {
    tmp_pselstctrl.bf.RX0INIT = 1;
  }

  ten_reset_action(TEN_HSIF_REG_ADDR(pDev, module_id, PSELSTCTRL), tmp_pselstctrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);
  return (CS_OK);
}  

/********************************************************************/
/* $rtn_hdr_start  HSIF SFI41 CFG SPARE                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_sfi41_cfg_spare(cs_uint16 module_id, 
                         cs_uint16 sfi41_spare)
/* INPUTS     : o Module Id                                         */
/*              o SFI41 SPARE                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure Spare bits for SFI41 clock/data mux block.             */
/*                                                                  */
/*   [sfi41_spare]  Launch clock configuration                      */
/*     7:6 reserved                                                 */
/*       5 Launch data on rising (=0) or                            */
/*         falling (=1) edge SFI41_RXCLK.                           */
/*       4 Launch data on rising (=0) or                            */
/*         falling (=1) edge SFI41_TXCLK.                           */
/*     3:0 reserved                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_SFI41_CFG_t tmp_sfi41_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_sfi41_cfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, SFI41_CFG));
  tmp_sfi41_cfg.bf.SFI41_SPARE = sfi41_spare;
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, SFI41_CFG), tmp_sfi41_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SFI41 CFG SPARE LAUNCH DATA RX CLK          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_sfi41_cfg_spare_launch_data_rxclk(cs_uint16 module_id, 
                                                     cs_uint16 value)
/* INPUTS     : o Module Id                                         */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls bit #5, Launch data on rising or falling edge           */
/* SFI41_RXCLK.                                                     */
/*                                                                  */
/* [value]  Launch clock configuration:                             */
/*          0 = Launch data on rising or                            */
/*          1 = Launch data on falling edge.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_SFI41_CFG_t tmp_sfi41_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_sfi41_cfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, SFI41_CFG));
  if (value) {
    tmp_sfi41_cfg.bf.SFI41_SPARE |= 0x20;
  }
  else {
    tmp_sfi41_cfg.bf.SFI41_SPARE &= ~0x20;
  }
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, SFI41_CFG), tmp_sfi41_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SFI41 CFG SPARE LAUNCH DATA TX CLK          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_sfi41_cfg_spare_launch_data_txclk(cs_uint16 module_id, 
                                                     cs_uint16 value)
/* INPUTS     : o Module Id                                         */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls bit #4, Launch data on rising or falling edge           */
/* SFI41_TXCLK.                                                     */
/*                                                                  */
/* [value]  Launch clock configuration:                             */
/*          0 = Launch data on rising or                            */
/*          1 = Launch data on falling edge.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_SFI41_CFG_t tmp_sfi41_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_sfi41_cfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, SFI41_CFG));
  if (value) {
    tmp_sfi41_cfg.bf.SFI41_SPARE |= 0x10;
  }
  else {
    tmp_sfi41_cfg.bf.SFI41_SPARE &= ~0x10;
  }
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, SFI41_CFG), tmp_sfi41_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF BITSHUFFLE                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_bitshuffle(cs_uint16 module_id, 
                          cs_uint16 txprecoder_stride, 
                          cs_uint16 rxdecoder_stride)
/* INPUTS     : o Module Id                                         */
/*              o Txprecoder Stride                                 */
/*              o Rxdecoder Stride                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the bit shuffle applied to the RX and TX 128 (4x32) bit */
/* datapaths.  The portions of the datapath dedicated solely to     */
/* XAUI (4x40) are not affected.                                    */
/* NOTE:  These values are not retimed to any particular functional */
/* clock because depending on the configuration, the functional     */
/* clock may vary.  This register should only be changed when the   */
/* datapath is held in reset to avoid metastability issues.         */
/*                                                                  */
/*   [txprecoder_stride] This bit shuffle is applied before the     */
/*                       TX precoder.                               */
/*                                                                  */
/*   [rxdecoder_stride]  This bit shuffle is applied after the      */
/*                       RX precoder.                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_BITSHUFFLE_t tmp_bitshuffle;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_bitshuffle.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, BITSHUFFLE));
  tmp_bitshuffle.bf.txprecoder_stride = txprecoder_stride;
  tmp_bitshuffle.bf.rxdecoder_stride = rxdecoder_stride;
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, BITSHUFFLE), tmp_bitshuffle.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HSIF SET PRECODER CFGA                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_hsif_set_precoder_cfga(cs_uint16 module_id,
                                     cs_uint8 instance, 
                                     cs_uint16 tti)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o TTI                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Precoder for 10G Configuration Register A.                   */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)             */
/*                                                              */
/* The [tti] parameter is specified as:                         */
/*   0x0000..0xFFFF: Truth table configuration. Default value   */
/*                   has no effect on pass through data.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_PRECODER0_CFGA_t tmp_precoder0_cfga;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_PROTOCOL_PRECODER0_CFGA_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_PRECODER0_CFGA_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_precoder0_cfga.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER0_CFGA) +
      ii * TEN_HSIF_PROTOCOL_PRECODER0_CFGA_STRIDE);
      tmp_precoder0_cfga.bf.TTI = tti;
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER0_CFGA) +
      ii * TEN_HSIF_PROTOCOL_PRECODER0_CFGA_STRIDE, tmp_precoder0_cfga.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HSIF SET PRECODER CFGB                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_hsif_set_precoder_cfgb(cs_uint16 module_id,
                                     cs_uint8 instance, 
                                     cs_uint16 ttq)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o TTQ                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Precoder for 10G Configuration Register B.                   */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)             */
/*                                                              */
/* The [ttq] parameter is specified as:                         */
/*   0x0000..0xFFFF: Truth table configuration. Default value   */
/*                   has no effect on pass through data.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_PRECODER0_CFGB_t tmp_precoder0_cfgb;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_PROTOCOL_PRECODER0_CFGB_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_PRECODER0_CFGB_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_precoder0_cfgb.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER0_CFGB) +
      ii * TEN_HSIF_PROTOCOL_PRECODER0_CFGB_STRIDE);
      tmp_precoder0_cfgb.bf.TTQ = ttq;
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER0_CFGB) +
      ii * TEN_HSIF_PROTOCOL_PRECODER0_CFGB_STRIDE, tmp_precoder0_cfgb.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HSIF SET DECODER CFGA                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_hsif_set_decoder_cfga(cs_uint16 module_id,
                                    cs_uint8 instance, 
                                    cs_uint16 tta)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o TTA                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Decoder for 10G Configuration Register A.                    */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)             */
/*                                                              */
/* The [tta] parameter is specified as:                         */
/*   0x0000..0xFFFF: Truth table configuration. Default value   */
/*                   has no effect on pass through data.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_DECODER0_CFGA_t tmp_decoder0_cfga;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_PROTOCOL_DECODER0_CFGA_COUNT) && (instance != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_DECODER0_CFGA_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_SLICE_ALL)) {
      tmp_decoder0_cfga.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER0_CFGA) +
      ii * TEN_HSIF_PROTOCOL_DECODER0_CFGA_STRIDE);
      tmp_decoder0_cfga.bf.TTA = tta;
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER0_CFGA) +
      ii * TEN_HSIF_PROTOCOL_DECODER0_CFGA_STRIDE, tmp_decoder0_cfga.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HSIF SET DECODER CFGB                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_hsif_set_decoder_cfgb(cs_uint16 module_id,
                                    cs_uint8 instance, 
                                    cs_uint16 ttb)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o TTB                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Decoder for 10G Configuration Register B.                    */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)             */
/*                                                              */
/* The [ttb] parameter is specified as:                         */
/*   0x0000..0xFFFF: Truth table configuration. Default value   */
/*                   has no effect on pass through data.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_DECODER0_CFGB_t tmp_decoder0_cfgb;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_PROTOCOL_DECODER0_CFGB_COUNT) && (instance != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_PROTOCOL_DECODER0_CFGB_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_SLICE_ALL)) {
      tmp_decoder0_cfgb.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER0_CFGB) +
      ii * TEN_HSIF_PROTOCOL_DECODER0_CFGB_STRIDE);
      tmp_decoder0_cfgb.bf.TTB = ttb;
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER0_CFGB) +
      ii * TEN_HSIF_PROTOCOL_DECODER0_CFGB_STRIDE, tmp_decoder0_cfgb.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HSIF PROTOCOL CLK 40G                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_hsif_clk_40g(cs_uint16 module_id, 
                       cs_uint16 tx_aggr_mode, 
                       cs_uint16 txsel, 
                       cs_uint16 rx_aggr_mode, 
                       cs_uint16 rxsel)
/* INPUTS     : o Module Id                                     */
/*              o Tx Aggr Mode                                  */
/*              o Txsel                                         */
/*              o Rx Aggr Mode                                  */
/*              o Rxsel                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the serdes clock to be used for 40G                */
/*                                                              */
/* The [tx_aggr_mode] parameter enables TX aggregation mode     */
/*   0 = Only GPLL0 driven with a source clock                  */
/*   1 = All GPLLs driven with 40G source clock                 */
/*                                                              */
/* The [txsel] parameter selects the TX pll clock               */
/*   0 = TX PLL CLOCK 0 (Default)                               */
/*   1 = TX PLL CLOCK 1                                         */
/*   2 = TX PLL CLOCK 2                                         */
/*   3 = TX PLL CLOCK 3                                         */
/*                                                              */
/* The [rx_aggr_mode] parameter enables RX aggregation mode     */
/*   0 = Only GPLL0 driven with a source clock                  */
/*   1 = All GPLLs driven with 40G source clock                 */
/*                                                              */
/* The [rxsel] parameter selects the RX lane clock controlled by*/
/*   0 = RX slice 0 clock (RXCLK_10G lane sel0) Default         */
/*   1 = RX slice 1 clock (RXCLK_10G lane sel1)                 */
/*   2 = RX slice 2 clock (RXCLK_10G lane sel2)                 */
/*   3 = RX slice 3 clock (RXCLK_10G lane sel3)                 */
/*   4 = SFI serdes RX clk 16 (SFI protocol only)               */
/*   5 = SFI serdes RX clk 17 (SFI protocol only)               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_HSIF_PROTOCOL_CLK_40G_t tmp_clk_40g;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hsif_clk_40g";  


  if (tx_aggr_mode > 1) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, "%s() tx_aggr_mode = 0x%04X\n", func, tx_aggr_mode);
      return (CS_ERROR);
  }
  if (txsel > 3) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, "%s() txsel = 0x%04X\n", func, txsel);
      return (CS_ERROR);
  }
  if (rx_aggr_mode > 1) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, "%s() rx_aggr_mode = 0x%04X\n", func, rx_aggr_mode);
      return (CS_ERROR);
  }
  if (rxsel > 5) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, "%s() rxsel = 0x%04X\n", func, rxsel);
      return (CS_ERROR);
  }
  CS_PRINT("%s() %s, tx_aggr_mode=%d, txsel=%d, rx_aggr_mode=%d, rxsel=%d\n", 
            func,
            ten_module_strings[module_id&1], 
            tx_aggr_mode, 
            txsel, 
            rx_aggr_mode, 
            rxsel);


  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);

  tmp_clk_40g.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, CLK_40G));
  tmp_clk_40g.bf.tx_aggr_mode = tx_aggr_mode;
  tmp_clk_40g.bf.txsel = txsel;
  tmp_clk_40g.bf.rx_aggr_mode = rx_aggr_mode;
  tmp_clk_40g.bf.rxsel = rxsel;
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, CLK_40G), tmp_clk_40g.wrd);
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}                        

/****************************************************************/
/* $rtn_hdr_start  HSIF SET PROTOCOL CLK 40G                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_hsif_set_clk_40g(cs_uint16 module_id, 
                               cs_uint16 select, 
                               cs_uint16 value)
/* INPUTS     : o Module Id                                     */
/*              o Select                                        */
/*              o Value                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the serdes clock to be used for 40G                */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_HSIF_CLK_40G_TX_AGGR_MODE = 3                          */
/*   TEN_HSIF_CLK_40G_TXSEL        = 2                          */
/*   TEN_HSIF_CLK_40G_RX_AGGR_MODE = 1                          */
/*   TEN_HSIF_CLK_40G_RXSEL        = 0                          */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   For select = TEN_HSIF_CLK_40G_TX_AGGR_MODE                 */
/*     0 = Only GPLL0 driven with a source clock                */
/*     1 = All GPLLs driven with 40G source clock               */
/*                                                              */
/*   For select = TEN_HSIF_CLK_40G_TXSEL                        */
/*     0 = TX PLL CLOCK 0 (Default)                             */
/*     1 = TX PLL CLOCK 1                                       */
/*     2 = TX PLL CLOCK 2                                       */
/*     3 = TX PLL CLOCK 3                                       */
/*                                                              */
/*   For select = TEN_HSIF_CLK_40G_RX_AGGR_MODE                 */
/*     0 = Only GPLL0 driven with a source clock                */
/*     1 = All GPLLs driven with 40G source clock               */
/*                                                              */
/*   For select = TEN_HSIF_CLK_40G_RXSEL                        */
/*     0 = RX slice 0 clock (RXCLK_10G lane sel0) Default       */
/*     1 = RX slice 1 clock (RXCLK_10G lane sel1)               */
/*     2 = RX slice 2 clock (RXCLK_10G lane sel2)               */
/*     3 = RX slice 3 clock (RXCLK_10G lane sel3)               */
/*     4 = SFI serdes RX clk 16 (SFI protocol only)             */
/*     5 = SFI serdes RX clk 17 (SFI protocol only)             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_HSIF_PROTOCOL_CLK_40G_t tmp_clk_40g;
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;
  cs_char8 *func = "ten_hsif_set_clk_40g";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  CS_PRINT("%s() %s, %s, value=%d\n", 
            func,
            ten_module_strings[module_id&1], 
            ten_hsif_clk_40g_strings[select], 
            value); 


  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);

  tmp_clk_40g.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, CLK_40G));
  switch (select) {
    case TEN_HSIF_CLK_40G_RXSEL :
      {
        tmp_clk_40g.bf.rxsel = value;
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, CLK_40G), tmp_clk_40g.wrd);
        break;
      }
    case TEN_HSIF_CLK_40G_RX_AGGR_MODE :
      {
        tmp_clk_40g.bf.rx_aggr_mode = value;
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, CLK_40G), tmp_clk_40g.wrd);
        break;
      }
    case TEN_HSIF_CLK_40G_TXSEL :
      {
        tmp_clk_40g.bf.txsel = value;
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, CLK_40G), tmp_clk_40g.wrd);
        break;
      }
    case TEN_HSIF_CLK_40G_TX_AGGR_MODE :
      {
        tmp_clk_40g.bf.tx_aggr_mode = value;
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, CLK_40G), tmp_clk_40g.wrd);
        break;
      }
    default :
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() select %d out of range.  s/b 0..3.", func, select);
        ret_val = CS_ERROR;
      }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (ret_val);
}    

/****************************************************************/
/* $rtn_hdr_start  HSIF SET OK CTRL REGISTER                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_hsif_set_ok_ctrl(cs_uint16 module_id, 
                               cs_uint8 slice, 
                               cs_uint16 select, 
                               cs_uint16 value)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Select                                        */
/*              o Value                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Controls the OK signals sent to PP10G/N40G.                  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_HSIF_OK_CTRL_SYNCED_EN   = 3                           */
/*   TEN_HSIF_OK_CTRL_DATADET_EN  = 2                           */
/*   TEN_HSIF_OK_CTRL_LOCK_EN     = 1                           */
/*   TEN_HSIF_OK_CTRL_XLOS_EN     = 0                           */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   For select = TEN_HSIF_OK_CTRL_SYNCED_EN                    */
/*     When this bit is set, the corresponding 10G lane OK      */
/*     status signal will take protocol sync into consideration.*/
/*                                                              */
/*   For select = TEN_HSIF_OK_CTRL_DATADET_EN                   */
/*     When this bit is set, the corresponding 10G lane OK      */
/*     status signal will take datadet into consideration.      */
/*                                                              */
/*   For select = TEN_HSIF_OK_CTRL_LOCK_EN                      */
/*     When this bit is set, the corresponding 10G lane OK      */
/*     status signal will take lock into consideration.         */
/*                                                              */
/*   For select = TEN_HSIF_OK_CTRL_XLOS_EN                      */
/*     When this bit is set, the corresponding 10G lane OK      */
/*     status signal will take external LOS into consideration. */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_HSIF_PROTOCOL_OK_CTRL_t tmp_ok_ctrl;
  T41_t *pDev = NULL;
  cs_uint16 which_slices = 0;
  cs_status ret_val = CS_OK;

  if(select > TEN_HSIF_OK_CTRL_SYNCED_EN) { 

  }
  if(value > 1) { 
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": value out of range"); 
    return(CS_ERROR); 
  }
  if (slice == TEN_SLICE_ALL) {
    which_slices = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slices = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_ok_ctrl.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, OK_CTRL));
  switch (select) {
    case TEN_HSIF_OK_CTRL_XLOS_EN : 
      {
        if (value == 1) {
          tmp_ok_ctrl.bf.xlos_en |= which_slices;
        }
        else {
          tmp_ok_ctrl.bf.xlos_en &= ~which_slices;
        }
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, OK_CTRL), tmp_ok_ctrl.wrd);
        break;
      }
    case TEN_HSIF_OK_CTRL_LOCK_EN : 
      {
        if (value == 1) {
          tmp_ok_ctrl.bf.lock_en |= which_slices;
        }
        else {
          tmp_ok_ctrl.bf.lock_en &= ~which_slices;
        }
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, OK_CTRL), tmp_ok_ctrl.wrd);
        break;
      }
    case TEN_HSIF_OK_CTRL_DATADET_EN : 
      {
        if (value == 1) {
          tmp_ok_ctrl.bf.datadet_en |= which_slices;
        }
        else {
          tmp_ok_ctrl.bf.datadet_en &= ~which_slices;
        }
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, OK_CTRL), tmp_ok_ctrl.wrd);
        break;
      }
    case TEN_HSIF_OK_CTRL_SYNCED_EN : 
      {
        if (value == 1) {
          tmp_ok_ctrl.bf.synced_en |= which_slices;
        }
        else {
          tmp_ok_ctrl.bf.synced_en &= ~which_slices;
        }
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, OK_CTRL), tmp_ok_ctrl.wrd);
        break;
      }
    default : 
      {
        CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, ": select out of range"); 
        ret_val = CS_ERROR; 
      }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SET REFCLK CFG REGISTER                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_refclk_cfg(cs_uint16 module_id, 
                                  cs_uint16 select, 
                                  cs_uint16 value)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register controls the analog ref clk block that provides    */
/* all serdes with a common reference for use in 40G mode.          */
/*                                                                  */
/* The [select] parameter is specified as:                          */
/*  TEN_HSIF_REFCLK_CFG_SPARE         = 0                           */
/*  TEN_HSIF_REFCLK_CFG_CKREFDIV      = 1                           */
/*  TEN_HSIF_REFCLK_CFG_LOOPCKSEL     = 2                           */
/*  TEN_HSIF_REFCLK_CFG_SFI5PILOT_SEL = 3                           */
/*  TEN_HSIF_REFCLK_CFG_ALL           = 4                           */
/*                                                                  */
/* The [value] parameter is specified as:                           */
/*   For select = TEN_HSIF_REFCLK_CFG_SPARE                         */
/*     SPARE[3:0] Spare bits for REFCLK block.                      */
/*                                                                  */
/*   For select = TEN_HSIF_REFCLK_CFG_CKREFDIV                      */
/*     CKREFDIV[1:0] Divider Selection. Ref clock to serdes divide  */
/*     by 2 or 4.                                                   */
/*     00 = div1 to serdes                                          */ 
/*     01 = div2 to serdes                                          */ 
/*     10 = div4 to serdes                                          */ 
/*     Default is 2'b10. 622MHz reference expected.                 */
/*                                                                  */
/*   For select = TEN_HSIF_REFCLK_CFG_LOOPCKSEL                     */
/*     LOOPCKSEL[1:0] Select source for SFI5CKREF                   */
/*     00 = select divided SFICKREFN/P pad                          */
/*     01 = select divided LOOPCKINPUT pin                          */
/*     11 = select divided ALOOPCKINPUT pin (direct connection      */
/*          from RX lane)                                           */
/*                                                                  */
/*   For select = TEN_HSIF_REFCLK_CFG_SFI5PILOT_SEL                 */
/*     SFI5PILOT_SEL[1:0] Select source for SFI5CKRXPILOT           */
/*     00 = select divided SFI5CKREFP/N pad                         */                 
/*     01 = select SFICKRXPILOTN/P pad                              */
/*     10 = select SFI5AUXPILOTIN pin (Fractional divider source)   */
/*                                                                  */
/*   For select = TEN_HSIF_REFCLK_CFG_ALL                           */
/*     Set entire register at once.                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_HSIF_PROTOCOL_REFCLK_CFG_t tmp_refclk_cfg;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);


  switch (select) {
    case TEN_HSIF_REFCLK_CFG_SPARE :
      {
        tmp_refclk_cfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG));
        tmp_refclk_cfg.bf.SPARE = value;
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG), tmp_refclk_cfg.wrd);
        break;
      }
    case TEN_HSIF_REFCLK_CFG_CKREFDIV :
      {
        tmp_refclk_cfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG));
        tmp_refclk_cfg.bf.CKREFDIV = value;
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG), tmp_refclk_cfg.wrd);
        break;
      }
    case TEN_HSIF_REFCLK_CFG_LOOPCKSEL :
      {
        tmp_refclk_cfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG));
        tmp_refclk_cfg.bf.LOOPCKSEL = value;
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG), tmp_refclk_cfg.wrd);
        break;
      }
    case TEN_HSIF_REFCLK_CFG_SFI5PILOT_SEL :
      {
        tmp_refclk_cfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG));
        tmp_refclk_cfg.bf.SFI5PILOT_SEL = value;
        TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG), tmp_refclk_cfg.wrd);
        break;
      }
    case TEN_HSIF_REFCLK_CFG_ALL:
      TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG), value);
      break;

    default :
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..4.");
        rtn = CS_ERROR;
      }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF MISC XLOS PSWTCHEN                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_misc_xlos_pswtchen(cs_uint16 module_id, 
                                      cs_uint16 xlos_pswtchen)
/* INPUTS     : o Module Id                                         */
/*              o Xlos Pswtchen                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls XLOS protection switch enable.                          */
/*                                                                  */
/* [xlos_pswtchen]                                                  */
/*   A side only. XLOS protection switch enable. Allows protection  */
/*   switch to be controlled by XLOS pins.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_MISC_t tmp_misc;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_misc.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, MISC));
  tmp_misc.bf.xlos_pswtchen = xlos_pswtchen;
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, MISC), tmp_misc.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF MISC HW PSWTCHEN                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_misc_hw_pswtchen(cs_uint16 module_id, 
                                    cs_uint16 hw_pswtchen)
/* INPUTS     : o Module Id                                         */
/*              o Hw Pswtchen                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls hardware protection switch enable.                      */
/*                                                                  */
/* [hw_pswtchen]                                                    */
/*    A side only. Hardware protection switch enable. Allows        */
/*    protection switch to be controlled by hardware via the        */
/*    OHPP interface.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_MISC_t tmp_misc;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_misc.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, MISC));
  tmp_misc.bf.hw_pswtchen = hw_pswtchen;
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, MISC), tmp_misc.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF MISC SINT SEL                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_misc_sint_sel(cs_uint16 module_id, 
                                 cs_uint16 sint_sel)
/* INPUTS     : o Module Id                                         */
/*              o SINT SEL                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects one out of eight global statistics interval              */
/* timing generators. This is used by the BER status.               */
/*                                                                  */
/* [sint_sel]                                                       */
/*    0 = 1st internal timing generator                             */ 
/*    1 = 2nd internal timing generator                             */
/*    2 = 3rd internal timing generator                             */
/*    3 = 4th internal timing generator                             */
/*    4 = 5th internal timing generator                             */
/*    5 = 6th internal timing generator                             */
/*    6 = Software controlled timing generator.                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_MISC_t tmp_misc;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_misc.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, MISC));
  tmp_misc.bf.SINT_SEL = sint_sel;
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, MISC), tmp_misc.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF MISC XFI SYNC MODE                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_misc_xfi_sync_mode(cs_uint16 module_id, 
                                      cs_uint16 xfi_sync_mode)
/* INPUTS     : o Module Id                                         */
/*              o Xfi Sync Mode                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls synchronization of the 4 XFI slices on TX.              */
/*                                                                  */
/* [xfi_sync_mode]                                                  */
/*    synchronization of the 4 XFI slices on TX.                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_MISC_t tmp_misc;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_misc.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, MISC));
  tmp_misc.bf.xfi_sync_mode = xfi_sync_mode;
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, MISC), tmp_misc.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF MISC XFI XLOS BROADCAST                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_misc_xfi_xlos_broadcast(cs_uint16 module_id, 
                                           cs_uint16 xfi_xlos_broadcast)
/* INPUTS     : o Module Id                                         */
/*              o Xfi XLOS Broadcast                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls whether XLOS 0 is broadcast internally to all           */
/* XFI slices.                                                      */
/*                                                                  */
/* [xfi_xlos_broadcast]                                             */
/*    whether XLOS 0 is broadcast internally to all                 */
/*    XFI slices.                                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_PROTOCOL_MISC_t tmp_misc;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_misc.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, MISC));
  tmp_misc.bf.xfi_XLOS_broadcast = xfi_xlos_broadcast;
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, MISC), tmp_misc.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF PSWTCH OK CTRL SYNCED ENABLE                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_pswtch_ok_ctrl_synced_en(cs_uint16 module_id, 
                                            cs_uint8 slice,
                                            cs_uint16 synced_en)
/* INPUTS     : o Module Id                                         */
/*              o Synced En                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Used for B side interface only. In the case where the MR         */
/* interface is used as a protection switched interface for side A, */
/* this register is used to control the OK signal associated        */
/* with the MR interface of side B.                                 */
/*                                                                  */
/*   [synced_en]                                                    */
/*      When this bit is set, the corresponding 10G lane OK status  */
/*      signal will take protocol sync into consideration.          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_HSIF_PROTOCOL_PSWTCH_OK_CTRL_t tmp_pswtch_ok_ctrl;
  cs_uint16 tmp;

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }
  
  if (synced_en > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": synced_en out of range.  s/b 0..1.");
    return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_pswtch_ok_ctrl.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSWTCH_OK_CTRL));
  if (synced_en) {
    tmp_pswtch_ok_ctrl.bf.synced_en |= tmp;
  }
  else {
    tmp_pswtch_ok_ctrl.bf.synced_en &= ~tmp;
  }
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, PSWTCH_OK_CTRL), tmp_pswtch_ok_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF PSWTCH OK CTRL DATADET ENABLE               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_pswtch_ok_ctrl_datadet_en(cs_uint16 module_id, 
                                             cs_uint8 slice,
                                             cs_uint16 datadet_en)
/* INPUTS     : o Module Id                                         */
/*              o Datadet En                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Used for B side interface only. In the case where the MR         */
/* interface is used as a protection switched interface for side A, */
/* this register is used to control the OK signal associated        */
/* with the MR interface of side B.                                 */
/*                                                                  */
/*   [datadet_en]                                                   */
/*     When this bit is set, the corresponding 10G lane OK status   */
/*     signal will take datadet into consideration.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_HSIF_PROTOCOL_PSWTCH_OK_CTRL_t tmp_pswtch_ok_ctrl;
  cs_uint16 tmp;

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }
  
  if (datadet_en > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": datadet_en out of range.  s/b 0..1.");
    return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_pswtch_ok_ctrl.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSWTCH_OK_CTRL));
  if (datadet_en) {
    tmp_pswtch_ok_ctrl.bf.datadet_en |= tmp;
  }
  else {
    tmp_pswtch_ok_ctrl.bf.datadet_en &= ~tmp;
  }
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, PSWTCH_OK_CTRL), tmp_pswtch_ok_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF PSWTCH OK CTRL LOCK ENABLE                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_pswtch_ok_ctrl_lock_en(cs_uint16 module_id, 
                                          cs_uint8 slice,
                                          cs_uint16 lock_en)
/* INPUTS     : o Module Id                                         */
/*              o Lock En                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Used for B side interface only. In the case where the MR         */
/* interface is used as a protection switched interface for side A, */
/* this register is used to control the OK signal associated        */
/* with the MR interface of side B.                                 */
/*                                                                  */
/*   [lock_en]                                                      */
/*      When this bit is set, the corresponding 10G lane OK status  */
/*      signal will take lock into consideration.                   */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_HSIF_PROTOCOL_PSWTCH_OK_CTRL_t tmp_pswtch_ok_ctrl;
  cs_uint16 tmp;

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }
  
  if (lock_en > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": synced_en out of range.  s/b 0..1.");
    return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_pswtch_ok_ctrl.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSWTCH_OK_CTRL));
  if (lock_en) {
    tmp_pswtch_ok_ctrl.bf.lock_en |= tmp;
  }
  else {
    tmp_pswtch_ok_ctrl.bf.lock_en &= ~tmp;
  }
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, PSWTCH_OK_CTRL), tmp_pswtch_ok_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF PSWTCH OK CTRL XLOS ENABLE                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_pswtch_ok_ctrl_xlos_en(cs_uint16 module_id, 
                                          cs_uint8 slice,
                                          cs_uint16 xlos_en)
/* INPUTS     : o Module Id                                         */
/*              o Xlos En                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Used for B side interface only. In the case where the MR         */
/* interface is used as a protection switched interface for side A, */
/* this register is used to control the OK signal associated        */
/* with the MR interface of side B.                                 */
/*                                                                  */
/*   [xlos_en]                                                      */
/*      When this bit is set, the corresponding 10G lane OK status  */
/*      signal will take external LOS into consideration.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_HSIF_PROTOCOL_PSWTCH_OK_CTRL_t tmp_pswtch_ok_ctrl;
  cs_uint16 tmp;

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }
  
  if (xlos_en > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": xlos_en out of range.  s/b 0..1.");
    return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_pswtch_ok_ctrl.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSWTCH_OK_CTRL));
  if (xlos_en) {
    tmp_pswtch_ok_ctrl.bf.xlos_en |= tmp;
  }
  else {
    tmp_pswtch_ok_ctrl.bf.xlos_en &= ~tmp;
  }
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, PSWTCH_OK_CTRL), tmp_pswtch_ok_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/* Bug #35933 - HSIF_PROTOCOL_SPARE register for CS6049  */
/****************************************************************/
/* $rtn_hdr_start  HSIF ENABLE FRAME PULSE ACCESS (CS6049 only) */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_hsif_fp_access_enable(cs_uint16 module_id,
                                    cs_ctl_t ctl)
/* INPUTS     : o Module_id                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable pin access to frame pulse in CS6049 as follows:       */
/*   B[3:0] on {SPOH_QFP,SPOH_RD,SPOH_RFP,SPOH_RCLK} pins       */
/*   A[3:0] on {GPIO15,GPIO7,FMRCLK,SPOH_QD} pins               */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev;
  TEN_HSIF_PROTOCOL_SPARE_t tmp_spare;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  if (ten_mpif_get_chip_dev_id_code_sku(TEN_MOD_ID_TO_DEV_ID(module_id))==TEN_DEV_ID_CODE_SKU_CS6049) { 
    TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
    tmp_spare.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, SPARE));
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
      tmp_spare.bf.EnTXFrmMarkA = ctl;
    }
    else {
      tmp_spare.bf.EnTXFrmMarkB = ctl;
    }
    TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, SPARE), tmp_spare.wrd);
    TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);
  }
  else {
    CS_PRINT("API not applicable to other than CS6049.\n");
  }  
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HSIF ENABLE SFU OUTPUT ACCESS (CS6049 only)  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_hsif_sfu_access_enable(cs_uint16 module_id,
                                     cs_uint16 ball_select,
                                     cs_ctl_t ctl)
/* INPUTS     : o Module_id                                     */
/*              o Ball_select                                   */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* If the Parallel Overhead Interface is unused, five Signaling */
/* Forwarding Unit consequent action outputs can be sent to     */ 
/* external hardware using the following balls on Side B:       */
/*   OHPP_RDB_P/N[0]: SFU side B output #73 on SPARE1           */
/*   OHPP_RDB_P/N[1]: SFU side B output #74 on SPARE_P/N        */
/*   OHPP_RDB_P/N[2]: SFU side B output #75 on SPARE3_P/N       */
/*   OHPP_RDB_P/N[3]: SFU side B output #76 on GPIO6            */
/* The fifth one is related to 40G and not relevant to CS6049   */
/*                                                              */
/* The [module_id] parameter is specified as:                   */
/*   1 = TEN_MODULE_B                                           */
/* Purposely specified as it includes the instance information  */
/* for multi chip applications                                  */
/*                                                              */
/* The [ball_select] parameter is specified as:                 */
/*   0 = OHPP_RDB_P/N[1] on SPARE_P/N pin                       */
/*       OHPP_RDB_P/N[2] on SPARE3_P/N pin                      */
/*   1 = OHPP_RDB_P/N[0] on SPARE1 pin                          */
/*       OHPP_RDB_P/N[3] on GPIO6 pin                           */
/*   2 = OHPP_RDB_P/N[1] on SPARE_P/N pin                       */
/*       OHPP_RDB_P/N[2] on SPARE3_P/N pin                      */
/*       OHPP_RDB_P/N[0] on SPARE1 pin                          */
/*       OHPP_RDB_P/N[3] on GPIO6 pin                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev;
  TEN_HSIF_PROTOCOL_SPARE_t tmp_spare;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  if ( (ten_mpif_get_chip_dev_id_code_sku(TEN_MOD_ID_TO_DEV_ID(module_id))==TEN_DEV_ID_CODE_SKU_CS6049) && 
       (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) ) {
    TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
    tmp_spare.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, SPARE));
    if ((ball_select == 0) || (ball_select == 2)) {
      tmp_spare.bf.EnOHPPRdB12 = ctl;
    }
    if ((ball_select == 1) || (ball_select == 2)) {
      tmp_spare.bf.EnOHPPRdB03 = ctl;
    }
    TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, SPARE), tmp_spare.wrd);
    TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);
  }
  else {
    CS_PRINT("API not applicable to other than CS6049 for Module B.\n");
  }
  return (CS_OK);
}






