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
 * ten_hsif_sfi42.c
 *
 * HSIF SFI42 related code is implemented here.
 *
 * $Id: ten_hsif_sfi42.c,v 1.5 2013/02/22 20:49:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  HSIF SFI42 GLOBAL CONFIG                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_sfi42_global_config(cs_uint16 module_id, 
                                   cs_uint16 tx40g_en, 
                                   cs_uint16 rx40g_en)
/* INPUTS     : o Module Id                                         */
/*              o TX40G EN                                          */
/*              o RX40G EN                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets configuration that affects all SFI4.2 slices.               */
/*                                                                  */
/*   [tx40g_en]  When set, this bit enables the TX for 40G mode.    */
/*                                                                  */
/*   [rx40g_en]  When set, this bit enables the RX for 40G mode.    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_SFI42_GLOBAL_CONFIG_t tmp_sfi42_global_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_sfi42_global_config.wrd = TEN_REG_READ(TEN_HSIF_SFI42_REG_ADDR(pDev, module_id, GLOBAL_CONFIG));
  tmp_sfi42_global_config.bf.TX40G_EN = tx40g_en;
  tmp_sfi42_global_config.bf.RX40G_EN = rx40g_en;
  TEN_REG_WRITE(TEN_HSIF_SFI42_REG_ADDR(pDev, module_id, GLOBAL_CONFIG), tmp_sfi42_global_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}
 
/********************************************************************/
/* $rtn_hdr_start  HSIF SFI42 BUSREORDER                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_sfi42_busreorder(cs_uint16 module_id, 
                                    cs_dir_t dir, 
                                    cs_uint16 busreorder)
/* INPUTS     : o Module Id                                         */
/*              o Direction                                         */
/*              o BUS REORDER                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* In 10G mode, the internal 128 bit bus is divided into 4 10G      */
/* slices. Each slice is transmitted (or received) over 4 unique    */
/* sfi42 lanes. In 40G mode, this behavior is not always desired    */
/* and may require a 'reorder'. The reorder is used only in 40G     */
/* mode, and treats the internal 128 bit bus as a single 40G slice. */
/* 64 bits quantities are transmitted (or received) using the lane  */
/* order 15, 11, 7, 3, 14, 10, 6, 2, 13, 9, 5, 1, 12, 8, 4, 0.      */
/* Note: this reordering is not desired in 2x20G precoding mode,    */
/* even though the sfi42 is operating in 40G mode.                  */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [busreorder] parameter is specified as:                      */
/*   0..1                                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_SFI42_GLOBAL_CONFIG_t tmp_sfi42_global_config;
  T41_t *pDev = NULL;

  if(dir > CS_TX_AND_RX) { 
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": dir out of range"); 
    return(CS_ERROR); 
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_sfi42_global_config.wrd = TEN_REG_READ(TEN_HSIF_SFI42_REG_ADDR(pDev, module_id, GLOBAL_CONFIG));
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_sfi42_global_config.bf.RXBUSREORDER = busreorder;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_sfi42_global_config.bf.TXBUSREORDER = busreorder;
  }
  TEN_REG_WRITE(TEN_HSIF_SFI42_REG_ADDR(pDev, module_id, GLOBAL_CONFIG), tmp_sfi42_global_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}
 
/********************************************************************/
/* $rtn_hdr_start  HSIF SFI42 SLICE CONTROL                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_sfi42_slice_control(cs_uint16 module_id, cs_uint8 instance, 
                                cs_uint16 rxeds_en, 
                                cs_uint16 txeds_en, 
                                cs_uint16 rxdscr_en, 
                                cs_uint16 txscr_en)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o RXEDS EN                                          */
/*              o TXEDS EN                                          */
/*              o RXDSCR EN                                         */
/*              o TXSCR EN                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Miscellaneous control bits for SFI4.2.                      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [rxeds_en]  When set, RX is configured to receive EDS          */
/*     superframes.                                                 */
/*                                                                  */
/*   [txeds_en]  When set, TX transmit superframes for Extended     */
/*     Deskew mode.                                                 */
/*                                                                  */
/*   [rxdscr_en]  When set, enables the 64B/66B line code           */
/*     descrambler in the the SFI4.2 receive interface.             */
/*                                                                  */
/*   [txscr_en]  When set, enables the 64B/66B line code scrambler  */
/*     in the the SFI4.2 transmit interface.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_SFI42_SLICE0CTRL_t tmp_sfi42_slice0ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_SFI42_SLICE0CTRL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_SFI42_SLICE0CTRL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_sfi42_slice0ctrl.wrd = TEN_REG_READ(TEN_HSIF_SFI42_REG_ADDR(pDev, module_id, SLICE0CTRL) +
      ii * TEN_HSIF_SFI42_SLICE0CTRL_STRIDE);
      tmp_sfi42_slice0ctrl.bf.RXEDS_EN = rxeds_en;
      tmp_sfi42_slice0ctrl.bf.TXEDS_EN = txeds_en;
      tmp_sfi42_slice0ctrl.bf.RXDSCR_EN = rxdscr_en;
      tmp_sfi42_slice0ctrl.bf.TXSCR_EN = txscr_en;
      TEN_REG_WRITE(TEN_HSIF_SFI42_REG_ADDR(pDev, module_id, SLICE0CTRL) +
      ii * TEN_HSIF_SFI42_SLICE0CTRL_STRIDE, tmp_sfi42_slice0ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}
 
/********************************************************************/
/* $rtn_hdr_start  HSIF SFI42 OOS THRESHOLD                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_sfi42_oos_threshold(cs_uint16 module_id, cs_uint8 instance, 
                                       cs_uint16 value)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets SFI4.2 Out Of Sync Threshold.                               */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [value]  The number of times, within a window size established */
/*     by IS_THR, that the sync bit pattern is in error before      */
/*     declaring that the data lane is "out-of-sync".               */
/*     The default value of "100000" translates into 32, 66-bit     */
/*     data frames.                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_SFI42_OOS_THR0_t tmp_sfi42_oos_thr0;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_SFI42_OOS_THR0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_SFI42_OOS_THR0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_sfi42_oos_thr0.wrd = TEN_REG_READ(TEN_HSIF_SFI42_REG_ADDR(pDev, module_id, OOS_THR0) +
      ii * TEN_HSIF_SFI42_OOS_THR0_STRIDE);
      tmp_sfi42_oos_thr0.bf.value = value;
      TEN_REG_WRITE(TEN_HSIF_SFI42_REG_ADDR(pDev, module_id, OOS_THR0) +
      ii * TEN_HSIF_SFI42_OOS_THR0_STRIDE, tmp_sfi42_oos_thr0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}


