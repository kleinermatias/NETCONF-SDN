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
 * ten_pp10g_rs.c
 *
 * $Id: ten_pp10g_rs.c,v 1.5 2013/02/22 20:48:04 jccarlis Exp $
 *
 * APIs for PP10G RS
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  PP10G RS TX SRESET                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_tx_sreset(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_reset_action_t act,
                                 cs_uint16 bitfield)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Bitfield                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a hard reset on the specified (masked on) selections.   */
/* The selections that are masked off will not be affected.         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* The [act] parameter specifies the reset option and is one of the */
/* following:                                                       */
/*   CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.         */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset for 20 milliseconds and then de-assert the reset bit(s). */
/*                                                                  */
/* The [bitfield] parameter is specified as:                        */
/*   TEN_PP10G_RS_TX_SRESET_SYSTX_LOGICRESET = 0x4000,              */
/*   TEN_PP10G_RS_TX_SRESET_TX_LOGICRESET    = 0x8000,              */
/*   TEN_PP10G_RS_TX_SRESET_ALL              = 0xC000               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_TX_TXCNTRL_t tmp_rs_tx_txcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": act = 0x%04X\n", act);
      return (CS_ERROR);
  }
  if (bitfield > TEN_PP10G_RS_TX_SRESET_ALL) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": bitfield = 0x%04X\n", bitfield);
      return (CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_tx_txcntrl.wrd = bitfield;
      ten_reset_action(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXCNTRL), 
                        tmp_rs_tx_txcntrl.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS TX PROFILE                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_tx_profile(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 tx_profile)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Tx Profile                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the RS Tx Profile.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tx_profile]  Identify the client signal profile employed by   */
/*     the data path through the transmit reconciliation sub-layer. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_TX_TXCNTRL_t tmp_rs_tx_txcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_tx_txcntrl.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXCNTRL));
      tmp_rs_tx_txcntrl.bf.tx_profile = tx_profile;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXCNTRL), tmp_rs_tx_txcntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS TX CONTROL USER DEFINED ORDERED SET     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_tx_port_ctl_user_defined_ordered_set(cs_uint16 module_id,
                              cs_uint8 slice, 
                              cs_boolean tx_userorden)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Tx UserOrdEn                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control (disable/enable) the transmission of the user            */
/* defined ordered set in PP10G RS block.                           */
/* The API ten_pp10g_rs_port_set_user_defined_ordered_set           */
/* defines the contents of lanes 1, 2 and 3.                        */
/* Lane 0 is always 9'h19C.                                         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tx_userorden]  Set this configuration bit to enable the       */
/*     transmission of user defined ordered sets.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_TX_TXCNTRL_t tmp_rs_tx_txcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_tx_txcntrl.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXCNTRL));
      tmp_rs_tx_txcntrl.bf.tx_userOrdEn = tx_userorden ? 1 : 0;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXCNTRL), tmp_rs_tx_txcntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS TX CONTROL INSERTION OF FAULT ORDERED SET */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_tx_port_ctl_fault_ordered_set_insert(cs_uint16 module_id,
                              cs_uint8 slice, 
                              cs_boolean tx_remoteorden, 
                              cs_boolean tx_localorden)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Tx RemoteOrdEn                                    */
/*              o Tx LocalOrdEn                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control(disable/enable) the insertion of ordered set /I/         */
/* when remote fault is detected as well as order set SOS upon      */
/* detecting a local fault.                                         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tx_remoteorden]                                               */
/*     Set this configuration bit to enables the transmission of    */
/*     /I/ whenever a remote fault condition is detected.           */
/*                                                                  */
/*   [tx_localorden]                                                */
/*     When set enables the transmission of SOS whenever a local    */
/*     fault condition is detected.                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_TX_TXCNTRL_t tmp_rs_tx_txcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_tx_txcntrl.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXCNTRL));
      tmp_rs_tx_txcntrl.bf.tx_remoteOrdEn = tx_remoteorden ? 1 : 0;
      tmp_rs_tx_txcntrl.bf.tx_localOrdEn = tx_localorden ? 1 : 0;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXCNTRL), tmp_rs_tx_txcntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/**********************************************************************/
/* $rtn_hdr_start  PP10G RS TX CONTROL DATA TRUNCATION ON ORDERED SET */ 
/* CATEGORY   : API                                                   */
/* ACCESS     : Public                                                */
/* BLOCK      : PP10G                                                 */
/* CHIP       : Tenabo                                                */
cs_status ten_pp10g_rs_tx_control_data_truncation_on_ordered_set(cs_uint16 module_id,
                              cs_uint8 slice, 
                              cs_boolean tx_datatruncen)
/* INPUTS     : o Module Id                                           */
/*              o Slice                                               */
/*              o Tx DataTruncEn                                      */
/* OUTPUTS    : ----                                                  */
/* RETURNS    : CS_OK or CS_ERROR                                     */
/* DESCRIPTION:                                                       */
/* Enables packet truncation whenever an ordered set requires         */
/* insertion into the transmitted stream.                             */
/*                                                                    */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)        */
/*                                                                    */
/*   [tx_datatruncen]  Set this configuration bit to enable packet    */
/*     truncation whenever an ordered set requires insertion into     */
/*     the transmitted stream.  Clear to prevent the truncation of    */
/*     packet being transmitted, thus is not the ordered set          */
/*     insertion starts after the end of the current packet.  If      */
/*     the packet is truncated /E/ codes are inserted before          */
/*     terminating the packet.                                        */
/*                                                                    */
/* $rtn_hdr_end                                                       */
/**********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_TX_TXCNTRL_t tmp_rs_tx_txcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_tx_txcntrl.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXCNTRL));
      tmp_rs_tx_txcntrl.bf.tx_dataTruncEn = tx_datatruncen;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXCNTRL), tmp_rs_tx_txcntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start   PP10G RS TX SET USER DEFINED ORDERED SET        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_tx_port_set_user_defined_ordered_set(cs_uint16 module_id,
                                 cs_uint8 slice, 
                                 cs_uint8 tx_userordl1,
                                 cs_uint8 tx_userordl2, 
                                 cs_uint8 tx_userordl3)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o User Defined Content for Lane 1                   */
/*              o User Defined Content for Lane 2                   */
/*              o User Defined Content for Lane 3                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the user defined ordered set.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tx_userordl1]  This is the user defined content for lane 1    */
/*     when a user defined ordered set is inserted.                 */
/*                                                                  */
/*   [tx_userordl2]  This is the user defined content for lane 2    */
/*     when a user defined ordered set is inserted.                 */
/*                                                                  */
/*   [tx_userordl3]  This is the user defined content for lane 3    */
/*     when a user defined ordered set is inserted.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_TX_TXUSERORD1_t tmp_rs_tx_txuserord1;
  TEN_PP10G_RS_TX_TXUSERORD2_t tmp_rs_tx_txuserord2;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_tx_txuserord1.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXUSERORD1));
      tmp_rs_tx_txuserord1.bf.tx_userOrdL2 = tx_userordl2;
      tmp_rs_tx_txuserord1.bf.tx_userOrdL1 = tx_userordl1;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXUSERORD1), tmp_rs_tx_txuserord1.wrd);
      
      tmp_rs_tx_txuserord2.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXUSERORD2));
      tmp_rs_tx_txuserord2.bf.tx_userOrdL3 = tx_userordl3;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, TXUSERORD2), tmp_rs_tx_txuserord2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS TX GET STATUS                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_rs_tx_get_status(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns XGRS status information for the transmit direction.      */   
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP10G_RS_UNDERFLOW (0)                                   */
/*     TEN_PP10G_RS_OVERFLOW (1)                                    */
/*     TEN_PP10G_RS_ALL (0xFF), (whole register at once)            */ 
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_PP10G_RS_TX_STATUS_t tmp_rs_tx_status;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  tmp_rs_tx_status.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, slice, STATUS));
  
  switch (select) {
  case (TEN_PP10G_RS_TX_UNDERFLOW):
    rtn = tmp_rs_tx_status.bf.underflow;
    break;
  
  case (TEN_PP10G_RS_TX_OVERFLOW):
    rtn = tmp_rs_tx_status.bf.overflow;
    break;
  
  case (TEN_PP10G_RS_TX_ALL):
    rtn = tmp_rs_tx_status.wrd;
    break;

  default:
      rtn = CS_ERROR;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..2.");
      break;
  }    
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS TX OIDLECOUNT                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_tx_oidlecount(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 oidle_pkt_tx)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Oidle Pkt Tx                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the number of Idle XGMII cycles required before |O|         */
/* characters are inserted.                                         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [oidle_pkt_tx]   Specifies the number of Idle (XGMII) cycles.  */
/*     Legal values are 0x1 to 0xf.                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_TX_OIDLECOUNT_t tmp_rs_tx_oidlecount;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_tx_oidlecount.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, OIDLECOUNT));
      tmp_rs_tx_oidlecount.bf.oidle_pkt_tx = oidle_pkt_tx;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, OIDLECOUNT), tmp_rs_tx_oidlecount.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS RX SRESET                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_rx_rxcntrl1(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs an sreset on the RS RX.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_RX_RXCNTRL1_t tmp_rs_rx_rxcntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_rx_rxcntrl1.wrd = 0;
      tmp_rs_rx_rxcntrl1.bf.rx_logicReset = 1;
      ten_reset_action(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, RXCNTRL1), 
                       tmp_rs_rx_rxcntrl1.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS RX PROFILE                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_rx_profile(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 rx_profile)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rx Profile                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Identifies the client signal profile employed by the data path   */
/* through the receive reconciliation sub-layer.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rx_profile]  client signal profile                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_RX_RXCNTRL1_t tmp_rs_rx_rxcntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_rx_rxcntrl1.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, RXCNTRL1));
      tmp_rs_rx_rxcntrl1.bf.rx_profile = rx_profile;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, RXCNTRL1), tmp_rs_rx_rxcntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS RX CONTROL HSIFKEN                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_rx_control_hsifoken(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 rx_hsifoken)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rx HsifokEn                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the RS RX.                           */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/* TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)          */
/*                                                                  */
/* [rx_hsifokEn]                                                    */ 
/* Enables generation of local fault when any bit of the            */
/* hsif_pp10g_ok signal is deasserted.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_RX_RXCNTRL1_t tmp_rs_rx_rxcntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_rx_rxcntrl1.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, RXCNTRL1));
      tmp_rs_rx_rxcntrl1.bf.rx_hsifokEn = rx_hsifoken;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, RXCNTRL1), tmp_rs_rx_rxcntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS RX CONTROL LOCAL FAULT DETECTION        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_rx_control(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 rx_ofsmunhen, 
                               cs_uint16 rx_noipg, 
                               cs_uint16 rx_phyrlfen, 
                               cs_uint16 rx_siglosen, 
                               cs_uint16 rx_hsifoken)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rx OfsmUNHEn                                      */
/*              o Rx NoIpg                                          */
/*              o Rx PhyRLFEn                                       */
/*              o Rx SigLosEn                                       */
/*              o Rx HsifokEn                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the RS RX.                           */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/* TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)          */
/*                                                                  */
/* [rx_ofsmunhen]                                                   */
/* When set to 1, whenever the Link Fault FSM transitions from the  */
/* NEW_FAULT_TYPE state to the COUNT state the seq_cnt is set to    */
/* 2.  The default, which follows the IEEE RS Section guidelines,   */
/* will have the seq_cnt set to 1 after a transition from the       */
/* NEW_FAULT_TYPE state to the COUNT state.                         */
/*                                                                  */
/* [rx_noipg]                                                       */
/* Section 46. 1. 7. 2 of the IEEE802. ae spec requires to signal,  */
/* as not valid, to the MAC-sublayer, all data frames               */
/* whose /S/ was not preceded by                                    */ 
/* either four Idle characters or a Sequence ordered set.  In a     */
/* case like this, the RS-sublayer will ensure the MAC-sublayer     */
/* will report an FCS error for that particular data frame.         */
/* The rx_noIfg set to 1 disables the IEEE requirement,             */
/* data frames will be allowed to pass to the MAC                   */
/* -  sublayer uncorrupted, even if no Idle characters or Sequence  */
/* oreder sets were received prior to the /S/.  When cleared, the   */
/* IEEE is effective and all data frames will be corrupted as       */
/* specified.                                                       */
/*                                                                  */
/* [rx_phyrlfen]                                                    */
/* Enables generation of local fault when a Local Fault (0x1) is    */
/* generated by a remote layer which is placed between the remoted  */
/* RS and the local RS.                                             */
/*                                                                  */
/* [rx_siglosen]                                                    */
/* Enables generation of local fault when LOS is declared by an     */
/* external optical device from the NG10G.                          */
/*                                                                  */
/* [rx_hsifokEn]                                                    */ 
/* Enables generation of local fault when any bit of the            */
/* hsif_pp10g_ok signal is deasserted.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_RX_RXCNTRL1_t tmp_rs_rx_rxcntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_rx_rxcntrl1.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, RXCNTRL1));
      tmp_rs_rx_rxcntrl1.bf.rx_ofsmUNHEn = rx_ofsmunhen;
      tmp_rs_rx_rxcntrl1.bf.rx_noIpg = rx_noipg;
      tmp_rs_rx_rxcntrl1.bf.rx_phyRLFEn = rx_phyrlfen;
      tmp_rs_rx_rxcntrl1.bf.rx_sigLosEn = rx_siglosen;
      tmp_rs_rx_rxcntrl1.bf.rx_hsifokEn = rx_hsifoken;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, RXCNTRL1), tmp_rs_rx_rxcntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS RX SET LINK FAULT THRESHOLDS            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rs_rx_set_link_fault_thresholds(cs_uint16 module_id, cs_uint8 slice,
                               cs_uint16 rx_seq_thr, 
                               cs_uint16 rx_col_thr)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rx Seq Thr                                        */
/*              o Rx Col Thr                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various thresholds of the RS RX.                        */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)        */
/*                                                                  */
/* [rx_seq_thr]                                                     */
/* User threshold to set how many errored columns to count before   */
/* declaring the link fault defect.                                 */
/*                                                                  */
/* [rx_col_thr]                                                     */
/* User threshold to set how many error free columns to count       */
/* before clearing the link fault defect.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_RS_RX_RXCNTRL2_t tmp_rs_rx_rxcntrl2;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rs_rx_rxcntrl2.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, RXCNTRL2));
      tmp_rs_rx_rxcntrl2.bf.rx_seq_thr = rx_seq_thr;
      tmp_rs_rx_rxcntrl2.bf.rx_col_thr = rx_col_thr;
      TEN_REG_WRITE(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, RXCNTRL2), tmp_rs_rx_rxcntrl2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS RX GET STATUS                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_rs_rx_get_status(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status Value                                        */
/* DESCRIPTION:                                                     */
/* Returns the PCS receive status.                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP10G_RS_RX_STATUS_RFS               1                   */
/*     TEN_PP10G_RS_RX_STATUS_LFS               2                   */
/*     TEN_PP10G_RS_RX_STATUS_UNKNOWNORDS       3                   */
/*     TEN_PP10G_RS_RX_STATUS_REMOTEORDS        4                   */
/*     TEN_PP10G_RS_RX_STATUS_LOCALORDS         5                   */
/*     TEN_PP10G_RS_RX_STATUS_ALL            0xFF (whole register)  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 rtn;
  TEN_PP10G_RS_RX_RXSTATUS_t tmp_rs_rx_rxstatus;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_rs_rx_rxstatus.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, slice, RXSTATUS));
  
  switch (select) {
  case (TEN_PP10G_RS_RX_STATUS_RFS):
    rtn = tmp_rs_rx_rxstatus.bf.RFS;
    break;

  case (TEN_PP10G_RS_RX_STATUS_LFS):
    rtn = tmp_rs_rx_rxstatus.bf.LFS;
    break;

  case (TEN_PP10G_RS_RX_STATUS_UNKNOWNORDS):
    rtn = tmp_rs_rx_rxstatus.bf.unknownordS;
    break;

  case (TEN_PP10G_RS_RX_STATUS_REMOTEORDS):
    rtn = tmp_rs_rx_rxstatus.bf.remoteordS;
    break;

  case (TEN_PP10G_RS_RX_STATUS_LOCALORDS):
    rtn = tmp_rs_rx_rxstatus.bf.localordS;
    break;
 
  case (TEN_PP10G_RS_RX_STATUS_ALL):
    rtn = tmp_rs_rx_rxstatus.wrd;
    break;
    
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RS RX GET CAPTURED UNKNOWN ORDERED SET     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_rs_rx_get_unknown_ordered_set(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint8 rx_unknownord_lane_select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Lane Selection                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Received Unknown Ordered Set.                       */
/* DESCRIPTION:                                                     */
/* Returns the captured unknown ordered set for the specified lane  */
/* selection.                                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/*   [rx_unknownord_lane_select]  Lane Selection s/b (1..3).        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 sl = slice;
  TEN_PP10G_RS_RX_UNKNOWNORD1_t tmp_rs_rx_unknownord1;
  TEN_PP10G_RS_RX_UNKNOWNORD2_t tmp_rs_rx_unknownord2;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b (0..3).");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  /* In order to properly read all the lanes UNKNOWNORD1 register must be read */
  /* first followed by reading the next register                               */
  tmp_rs_rx_unknownord1.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, UNKNOWNORD1));
  tmp_rs_rx_unknownord2.wrd = TEN_REG_READ(TEN_PP10G_RS_REG_ADDR(pDev, module_id, sl, UNKNOWNORD2));
  
  if (rx_unknownord_lane_select == 1) {
    return (tmp_rs_rx_unknownord1.bf.rx_unknownOrd_l1);
  }
  else if (rx_unknownord_lane_select == 2) {
    return (tmp_rs_rx_unknownord1.bf.rx_unknownOrd_l2);
  }
  else if (rx_unknownord_lane_select == 3) {
    return (tmp_rs_rx_unknownord2.bf.rx_unknownOrd_l3);
  }
  
  CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": lane select out of range.  s/b (1..3).");
  return (CS_ERROR);
}


