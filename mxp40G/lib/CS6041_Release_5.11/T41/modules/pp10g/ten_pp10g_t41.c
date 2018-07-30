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
 * ten_pp10g_t41.c 
 *
 * $Id: ten_pp10g_t41.c,v 1.7 2013/02/22 20:48:04 jccarlis Exp $
 *
 * API's for T41 PP10G Additions
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  PP10G CTL RX SFU FAIL ENABLE ALARM           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_ctl_rx_sfu_fail_en(cs_uint16 module_id,
                                       cs_uint8  slice, 
                                       cs_uint16 condition,
                                       cs_ctl_t ctl)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Condition                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contributing conditions for the SFU Fail Alarm.     */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/*   [condition] Specified as:                                  */
/*     TEN_PP10G_ALARMS_HSIF_OK         =  0x0001               */
/*     TEN_PP10G_ALARMS_N10G_OK         =  0x0002               */
/*     TEN_PP10G_ALARMS_XGGFP_LFD       =  0x0004               */
/*     TEN_PP10G_ALARMS_XGGFP_CSF       =  0x0008               */
/*     TEN_PP10G_ALARMS_XGGFP_FDI       =  0x0010               */
/*     TEN_PP10G_ALARMS_XGGFP_RDI       =  0x0020               */
/*     TEN_PP10G_ALARMS_XGGFP_UPM       =  0x0040               */
/*     TEN_PP10G_ALARMS_XGPCS_SYNC      =  0x0080               */
/*     TEN_PP10G_ALARMS_XGPCS_HIBER     =  0x0100               */
/*     TEN_PP10G_ALARMS_EGPCS_SYNC      =  0x0200               */
/*     TEN_PP10G_ALARMS_BASEX_SYNC_ALL  =  0x0400               */
/*     TEN_PP10G_ALARMS_BASEX_ALIGN     =  0x0800               */
/*                                                              */
/*   [ctl] parameter is specified as:                           */
/*     CS_ENABLE (1) or CS_DISABLE (0)                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
 T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_MISC_ALARMS_RX_SFU_FAIL_EN_t tmp_alarms_rx_sfu_fail_en;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_alarms_rx_sfu_fail_en.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, ALARMS_RX_SFU_FAIL_EN));
 
      if (condition & TEN_PP10G_ALARMS_HSIF_OK) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_hsif_ok = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_N10G_OK) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_n10g_ok = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_LFD) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_xggfp_lfd = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_CSF) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_xggfp_csf= ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_FDI) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_xggfp_fdi= ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_RDI) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_xggfp_rdi= ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_UPM) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_xggfp_upm= ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGPCS_SYNC) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_xgpcs_sync = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGPCS_HIBER) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_xgpcs_hiber = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_EGPCS_SYNC) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_egpcs_sync = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_BASEX_SYNC_ALL) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_basex_sync_all = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_BASEX_ALIGN) {
        tmp_alarms_rx_sfu_fail_en.bf.sfu_basex_align = ctl;
      }

      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, ALARMS_RX_SFU_FAIL_EN), tmp_alarms_rx_sfu_fail_en.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G CTL RX FORWARD LF ENABLE ALARM         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_ctl_rx_fwd_lf_en(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 condition,
                                     cs_ctl_t ctl)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Condition                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contributing conditions for the Forward LF Enable   */
/* Alarm.                                                       */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/*   [condition] Specified as:                                  */
/*     TEN_PP10G_ALARMS_HSIF_OK         =  0x0001               */
/*     TEN_PP10G_ALARMS_N10G_OK         =  0x0002               */
/*     TEN_PP10G_ALARMS_XGGFP_LFD       =  0x0004               */
/*     TEN_PP10G_ALARMS_XGGFP_CSF       =  0x0008               */
/*     TEN_PP10G_ALARMS_XGGFP_FDI       =  0x0010               */
/*     TEN_PP10G_ALARMS_XGGFP_RDI       =  0x0020               */
/*     TEN_PP10G_ALARMS_XGGFP_UPM       =  0x0040               */
/*     TEN_PP10G_ALARMS_XGPCS_SYNC      =  0x0080               */
/*     TEN_PP10G_ALARMS_XGPCS_HIBER     =  0x0100               */
/*     TEN_PP10G_ALARMS_EGPCS_SYNC      =  0x0200               */
/*     TEN_PP10G_ALARMS_BASEX_SYNC_ALL  =  0x0400               */
/*     TEN_PP10G_ALARMS_BASEX_ALIGN     =  0x0800               */
/*                                                              */
/*   [ctl] parameter is specified as:                           */
/*     CS_ENABLE (1) or CS_DISABLE (0)                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_MISC_ALARMS_RX_FWD_LF_EN_t tmp_alarms_rx_fwd_lf_en;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_alarms_rx_fwd_lf_en.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, ALARMS_RX_FWD_LF_EN));
      
      if (condition & TEN_PP10G_ALARMS_HSIF_OK) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_hsif_ok = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_N10G_OK) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_n10g_ok = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_LFD) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_xggfp_lfd = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_CSF) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_xggfp_csf = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_FDI) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_xggfp_fdi = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_RDI) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_xggfp_rdi = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_UPM) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_xggfp_upm = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGPCS_SYNC) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_xgpcs_sync = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGPCS_HIBER) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_xgpcs_hiber = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_EGPCS_SYNC) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_egpcs_sync = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_BASEX_SYNC_ALL) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_basex_sync_all = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_BASEX_ALIGN) {
        tmp_alarms_rx_fwd_lf_en.bf.lf_basex_align = ctl;
      }
     
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, ALARMS_RX_FWD_LF_EN), tmp_alarms_rx_fwd_lf_en.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G CTL RX FORWARD RF ENABLE ALARM         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_ctl_rx_fwd_rf_en(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 condition,
                                     cs_ctl_t ctl)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Condition                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contributing conditions for the Forward RF Enable   */
/* Alarm.                                                       */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/*   [condition] Specified as:                                  */
/*     TEN_PP10G_ALARMS_HSIF_OK         =  0x0001               */
/*     TEN_PP10G_ALARMS_N10G_OK         =  0x0002               */
/*     TEN_PP10G_ALARMS_XGGFP_LFD       =  0x0004               */
/*     TEN_PP10G_ALARMS_XGGFP_CSF       =  0x0008               */
/*     TEN_PP10G_ALARMS_XGGFP_FDI       =  0x0010               */
/*     TEN_PP10G_ALARMS_XGGFP_RDI       =  0x0020               */
/*     TEN_PP10G_ALARMS_XGGFP_UPM       =  0x0040               */
/*     TEN_PP10G_ALARMS_XGPCS_SYNC      =  0x0080               */
/*     TEN_PP10G_ALARMS_XGPCS_HIBER     =  0x0100               */
/*     TEN_PP10G_ALARMS_EGPCS_SYNC      =  0x0200               */
/*     TEN_PP10G_ALARMS_BASEX_SYNC_ALL  =  0x0400               */
/*     TEN_PP10G_ALARMS_BASEX_ALIGN     =  0x0800               */
/*                                                              */
/*   [ctl] parameter is specified as:                           */
/*     CS_ENABLE (1) or CS_DISABLE (0)                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_MISC_ALARMS_RX_FWD_RF_EN_t tmp_alarms_rx_fwd_rf_en;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_alarms_rx_fwd_rf_en.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, ALARMS_RX_FWD_RF_EN));

      if (condition & TEN_PP10G_ALARMS_HSIF_OK) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_hsif_ok = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_N10G_OK) {
         tmp_alarms_rx_fwd_rf_en.bf.rf_n10g_ok = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_LFD) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_xggfp_lfd = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_CSF) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_xggfp_csf = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_FDI) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_xggfp_fdi = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_RDI) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_xggfp_rdi = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGGFP_UPM) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_xggfp_upm = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGPCS_SYNC) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_xgpcs_sync = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_XGPCS_HIBER) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_xgpcs_hiber = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_EGPCS_SYNC) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_egpcs_sync = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_BASEX_SYNC_ALL) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_basex_sync_all = ctl;
      }
      if (condition & TEN_PP10G_ALARMS_BASEX_ALIGN) {
        tmp_alarms_rx_fwd_rf_en.bf.rf_basex_align = ctl;
      }

      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, ALARMS_RX_FWD_RF_EN), tmp_alarms_rx_fwd_rf_en.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RECEIVE ALARMS RESET                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rx_alarms_reset(cs_uint16         module_id,
                                    cs_uint8          slice, 
                                    cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This reset affects the receive datapath of the hardware          */
/* consequent action logic. When set, the receive datapath is reset.*/
/* This does not affect configuration registers.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_MISC_ALARMS_RX_RESET_t tmp_alarms_rx_reset;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_PRINT("Skip ten_pp10g_rx_alarms_reset, T40\n");
    return (CS_OK);
  }  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_alarms_rx_reset.wrd = 0;
      tmp_alarms_rx_reset.bf.rxrst = 1;
      ten_reset_action(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, ALARMS_RX_RESET),
                       tmp_alarms_rx_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G TRANSMIT ALARMS RESET                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_tx_alarms_reset(cs_uint16         module_id,
                                    cs_uint8          slice, 
                                    cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This reset affects the transmit datapath of the hardware         */
/* consequent action logic. When set, the transmit datapath is      */
/* reset. This does not affect configuration registers.             */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_MISC_ALARMS_TX_RESET_t tmp_alarms_tx_reset;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_PRINT("Skip ten_pp10g_tx_alarms_reset, T40\n");
    return (CS_OK);
  } 

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_alarms_tx_reset.wrd = 0;
      tmp_alarms_tx_reset.bf.txrst = 1;
      ten_reset_action(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, ALARMS_TX_RESET), 
                       tmp_alarms_tx_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G CTL TX ALARM ACTION                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_ctl_tx_alarm_action(cs_uint16 module_id,
                                        cs_uint8  slice, 
                                        cs_uint16 condition,
                                        cs_ctl_t ctl)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Condition                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contributing conditions for the TX Alarm Action.    */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/*   [condition] Specified as:                                  */
/*     TEN_PP10G_ACTIONS_FWD_LF_EN      =  0x0001               */
/*     TEN_PP10G_ACTIONS_FORCE_FWD_LF   =  0x0002               */
/*     TEN_PP10G_ACTIONS_FWD_LF_CODE0   =  0x0004               */
/*     TEN_PP10G_ACTIONS_FWD_LF_CODE1   =  0x0008               */
/*     TEN_PP10G_ACTIONS_FWD_RF_EN      =  0x0010               */
/*     TEN_PP10G_ACTIONS_FORCE_FWD_RF   =  0x0020               */
/*     TEN_PP10G_ACTIONS_LINKFAULT_DIS  =  0x0040               */
/*     TEN_PP10G_ACTIONS_PROTECT_LF_EN  =  0x0080               */
/*                                                              */
/*   [ctl] parameter is specified as:                           */
/*     CS_ENABLE (1) or CS_DISABLE (0)                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_MISC_ALARMS_TX_ACTION_t tmp_alarms_tx_action;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_alarms_tx_action.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, ALARMS_TX_ACTION));
      
      if (condition & TEN_PP10G_ACTIONS_FWD_LF_EN) {
        tmp_alarms_tx_action.bf.fwd_lf_en = ctl;
      }
      if (condition & TEN_PP10G_ACTIONS_FORCE_FWD_LF) {
        tmp_alarms_tx_action.bf.force_fwd_lf = ctl;
      }
      if (condition & TEN_PP10G_ACTIONS_FWD_LF_CODE0) {
        if (ctl) {
          tmp_alarms_tx_action.bf.fwd_lf_code = tmp_alarms_tx_action.bf.fwd_lf_code | 0x01;
        }
        else {
          /* Bug #38258 - Fix bitmask in ten_pp10g_ctl_tx_alarm_action API */
          tmp_alarms_tx_action.bf.fwd_lf_code = tmp_alarms_tx_action.bf.fwd_lf_code & 0x02;
        }
      }
      if (condition & TEN_PP10G_ACTIONS_FWD_LF_CODE1) {
        if (ctl) {
          /* Bug #38258 - Fix bitmask in ten_pp10g_ctl_tx_alarm_action API */
          tmp_alarms_tx_action.bf.fwd_lf_code = tmp_alarms_tx_action.bf.fwd_lf_code | 0x02;
        }
        else {
          tmp_alarms_tx_action.bf.fwd_lf_code = tmp_alarms_tx_action.bf.fwd_lf_code & 0x01;
        }
      }
      if (condition & TEN_PP10G_ACTIONS_FWD_RF_EN) {
        tmp_alarms_tx_action.bf.fwd_rf_en = ctl;
      }
      if (condition & TEN_PP10G_ACTIONS_FORCE_FWD_RF) {
        tmp_alarms_tx_action.bf.force_fwd_rf = ctl;
      }
      if (condition & TEN_PP10G_ACTIONS_LINKFAULT_DIS) {
        tmp_alarms_tx_action.bf.linkfault_dis = ctl;
      }
      if (condition & TEN_PP10G_ACTIONS_PROTECT_LF_EN) {
        tmp_alarms_tx_action.bf.protect_lf_en = ctl;
      }
      
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, ALARMS_TX_ACTION), tmp_alarms_tx_action.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

