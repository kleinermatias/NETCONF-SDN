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
 * ten_pp10g_xaui.c 
 *
 * $Id: ten_pp10g_xaui.c,v 1.5 2013/02/22 20:48:04 jccarlis Exp $
 *
 * API's for PP10G XAUI
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI RX RESET                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_rx_reset(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control XAUI sub-block RX logic reset.                           */
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
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_RX_Reset_t tmp_xaui_rx_reset;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_rx_reset.wrd = 0;
      tmp_xaui_rx_reset.bf.rxrst = 1;
      ten_reset_action(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, xaui_rx_Reset), 
                       tmp_xaui_rx_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI RX CONTROL 0                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_rx_control0(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_fpat_sel, 
                                 cs_uint16 xgxs_ddsa_enable, 
                                 cs_uint16 xgxs_lf_enable, 
                                 cs_uint16 xgxs_rx_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Fpat Sel                                     */
/*              o Xgxs Ddsa Enable                                  */
/*              o Xgxs Lf Enable                                    */
/*              o Xgxs Rx Mode                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_fpat_sel]  XGXS frequency test pattern monitor.          */
/*                                                                  */
/*   [xgxs_ddsa_enable]  XGXS data detect to synchronization        */
/*     algorithm enable.                                            */
/*                                                                  */
/*   [xgxs_lf_enable]  XGXS insert local fault                      */
/*                                                                  */
/*   [xgxs_rx_mode]  XGXS receive main mode configuration.          */
/*     0 = Data Normal data mode                                    */
/*     1 = Frequency Frequency Test Pattern                         */
/*     2 = Random Continuous Random Test Pattern                    */
/*     3 = Jitter Continuous Jitter Test Pattern.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_RX_RxCntrl0_t tmp_xaui_rx_rxcntrl0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_rx_rxcntrl0.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, RxCntrl0));
      tmp_xaui_rx_rxcntrl0.bf.xgxs_fpat_sel = xgxs_fpat_sel;
      tmp_xaui_rx_rxcntrl0.bf.xgxs_ddsa_enable = xgxs_ddsa_enable;
      tmp_xaui_rx_rxcntrl0.bf.xgxs_lf_enable = xgxs_lf_enable;
      tmp_xaui_rx_rxcntrl0.bf.xgxs_rx_mode = xgxs_rx_mode;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, RxCntrl0), tmp_xaui_rx_rxcntrl0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI RX CONTROL 1                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_rx_control1(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_fpat_0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Fpat 0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_fpat_0]  XGXS frequency test pattern register for lane 0.*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_RX_RxCntrl1_t tmp_xaui_rx_rxcntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_rx_rxcntrl1.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, RxCntrl1));
      tmp_xaui_rx_rxcntrl1.bf.xgxs_fpat_0 = xgxs_fpat_0;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, RxCntrl1), tmp_xaui_rx_rxcntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI RX CONTROL 2                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_rx_control2(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_fpat_1)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Fpat 1                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_fpat_1]  XGXS frequency test pattern register for lane 1.*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_RX_RxCntrl2_t tmp_xaui_rx_rxcntrl2;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_rx_rxcntrl2.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, RxCntrl2));
      tmp_xaui_rx_rxcntrl2.bf.xgxs_fpat_1 = xgxs_fpat_1;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, RxCntrl2), tmp_xaui_rx_rxcntrl2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI RX CONTROL 3                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_rx_control3(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_fpat_2)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Fpat 2                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_fpat_2]  XGXS frequency test pattern register for lane 2.*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_RX_RxCntrl3_t tmp_xaui_rx_rxcntrl3;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_rx_rxcntrl3.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, RxCntrl3));
      tmp_xaui_rx_rxcntrl3.bf.xgxs_fpat_2 = xgxs_fpat_2;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, RxCntrl3), tmp_xaui_rx_rxcntrl3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI RX CONTROL 4                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_rx_control4(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_fpat_3)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Fpat 3                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_fpat_3]  XGXS frequency test pattern register for lane 3.*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_RX_RxCntrl4_t tmp_xaui_rx_rxcntrl4;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_rx_rxcntrl4.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, RxCntrl4));
      tmp_xaui_rx_rxcntrl4.bf.xgxs_fpat_3 = xgxs_fpat_3;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, RxCntrl4), tmp_xaui_rx_rxcntrl4.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI RX GET STATUS                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_xaui_rx_get_status(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Get XAUI RX status.                                              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP10G_XAUI_RX_LOCALFAULT (0)                             */
/*     TEN_PP10G_XAUI_RX_REMOTEFAULT (1)                            */
/*     TEN_PP10G_XAUI_RX_XGXS_CPAT_LOCK (2)                         */
/*     TEN_PP10G_XAUI_RX_XGXS_ALIGN_DET (3)                         */
/*     TEN_PP10G_XAUI_RX_SYNCDET3 (4)                               */
/*     TEN_PP10G_XAUI_RX_SYNCDET2 (5)                               */
/*     TEN_PP10G_XAUI_RX_SYNCDET1 (6)                               */
/*     TEN_PP10G_XAUI_RX_SYNCDET0 (7)                               */
/*     TEN_PP10G_XAUI_RX_ALL (8) (whole register at once)           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;
  TEN_PP10G_BASEX_XAUI_RX_RX_INTSTAT_t tmp_xaui_rx_rx_intstat;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_xaui_rx_rx_intstat.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, slice, RX_INTSTAT));

  switch (select)
  {
  case (TEN_PP10G_XAUI_RX_LOCALFAULT):
  rtn = tmp_xaui_rx_rx_intstat.bf.LocalFault;
  break;
  
  case (TEN_PP10G_XAUI_RX_REMOTEFAULT):
  rtn = tmp_xaui_rx_rx_intstat.bf.RemoteFault;
  break;
  
  case (TEN_PP10G_XAUI_RX_XGXS_CPAT_LOCK):
  rtn = tmp_xaui_rx_rx_intstat.bf.xgxs_cpat_lock;
  break;
  
  case (TEN_PP10G_XAUI_RX_XGXS_ALIGN_DET):
  rtn = tmp_xaui_rx_rx_intstat.bf.xgxs_align_det;
  break;
  
  case (TEN_PP10G_XAUI_RX_SYNCDET3):
  rtn = tmp_xaui_rx_rx_intstat.bf.SyncDet3;
  break;
  
  case (TEN_PP10G_XAUI_RX_SYNCDET2):
  rtn = tmp_xaui_rx_rx_intstat.bf.SyncDet2;
  break;
  
  case (TEN_PP10G_XAUI_RX_SYNCDET1):
  rtn = tmp_xaui_rx_rx_intstat.bf.SyncDet1;
  break;
  
  case (TEN_PP10G_XAUI_RX_SYNCDET0):
  rtn = tmp_xaui_rx_rx_intstat.bf.SyncDet0;
  break;
  
  case (TEN_PP10G_XAUI_RX_ALL):
  rtn = tmp_xaui_rx_rx_intstat.wrd;
  break;
  
  default:
  rtn = CS_ERROR;
  CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..2.");
  break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI RX CHECK INSYNC                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_xaui_rx_check_insync(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status (1=locked, 0=not locked)                     */
/* DESCRIPTION:                                                     */
/* Checks XAUI RX sync status.                                      */
/* Returns 1 if insync and 0 is not.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3).                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;
  TEN_PP10G_BASEX_XAUI_RX_RX_INTSTAT_t tmp_xaui_rx_rx_intstat;
  cs_uint16 ii;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  for (ii=0; ii<25; ii++) {
    tmp_xaui_rx_rx_intstat.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, slice, RX_INTSTAT));

    rtn = tmp_xaui_rx_rx_intstat.bf.LocalFault;
    rtn = tmp_xaui_rx_rx_intstat.bf.RemoteFault;
    rtn = tmp_xaui_rx_rx_intstat.bf.xgxs_cpat_lock;
    rtn = tmp_xaui_rx_rx_intstat.bf.xgxs_align_det;
    rtn = tmp_xaui_rx_rx_intstat.bf.SyncDet3;
    rtn = tmp_xaui_rx_rx_intstat.bf.SyncDet2;
    rtn = tmp_xaui_rx_rx_intstat.bf.SyncDet1;
    rtn = tmp_xaui_rx_rx_intstat.bf.SyncDet0;

    CS_PRINT("PP10G XAUI Status: ii=%2d, module_id=%04X, slice=%d\n", ii, module_id, slice);
    CS_PRINT("Alignment   = %d\n", tmp_xaui_rx_rx_intstat.bf.xgxs_align_det);
    CS_PRINT("lane0 Sync  = %d\n", tmp_xaui_rx_rx_intstat.bf.SyncDet0);
    CS_PRINT("lane1 Sync  = %d\n", tmp_xaui_rx_rx_intstat.bf.SyncDet1);
    CS_PRINT("lane2 Sync  = %d\n", tmp_xaui_rx_rx_intstat.bf.SyncDet2);
    CS_PRINT("lane3 Sync  = %d\n", tmp_xaui_rx_rx_intstat.bf.SyncDet3);
    CS_PRINT("Local Fault = %d\n", tmp_xaui_rx_rx_intstat.bf.LocalFault);
    
    if ((tmp_xaui_rx_rx_intstat.bf.SyncDet3) &&
        (tmp_xaui_rx_rx_intstat.bf.SyncDet2) &&
        (tmp_xaui_rx_rx_intstat.bf.SyncDet1) &&
        (tmp_xaui_rx_rx_intstat.bf.SyncDet0) &&
        (tmp_xaui_rx_rx_intstat.bf.xgxs_align_det) &&
        (!tmp_xaui_rx_rx_intstat.bf.LocalFault)) {
        CS_PRINT("PP10G XAUI is Aligned & In Sync\n");
        return (1);
    }
    TEN_MDELAY(100);
  }
  return (0);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI TX RESET                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_tx_reset(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control XAUI sub-block TX logic reset.                           */
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
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_TX_Reset_t tmp_xaui_tx_reset;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_tx_reset.wrd = 0;
      tmp_xaui_tx_reset.bf.txrst = 1;
      ten_reset_action(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, xaui_tx_Reset), 
                       tmp_xaui_tx_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI TX CONTROL 0                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_tx_txcntrl0(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_fpat_sel, 
                                 cs_uint16 xgxs_tx_err_inj, 
                                 cs_uint16 xgxs_tx_random_6, 
                                 cs_uint16 xgxs_tx_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Fpat Sel                                     */
/*              o Xgxs Tx Err Inj                                   */
/*              o Xgxs Tx Random 6                                  */
/*              o Xgxs Tx Mode                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_fpat_sel]  XGXS frequency test pattern select.           */
/*                                                                  */
/*   [xgxs_tx_err_inj]  XGXS transmit test pattern single error     */
/*     inject                                                       */
/*                                                                  */
/*   [xgxs_tx_random_6]  XGXS transmit random generator control.    */
/*                                                                  */
/*   [xgxs_tx_mode]  XGXS transmit main mode configuration.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_TX_TxCntrl0_t tmp_xaui_tx_txcntrl0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_tx_txcntrl0.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl0));
      tmp_xaui_tx_txcntrl0.bf.xgxs_fpat_sel = xgxs_fpat_sel;
      tmp_xaui_tx_txcntrl0.bf.xgxs_tx_err_inj = xgxs_tx_err_inj;
      tmp_xaui_tx_txcntrl0.bf.xgxs_tx_random_6 = xgxs_tx_random_6;
      tmp_xaui_tx_txcntrl0.bf.xgxs_tx_mode = xgxs_tx_mode;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl0), tmp_xaui_tx_txcntrl0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI TX CONTROL 1                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_tx_control1(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_fpat_0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Fpat 0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_fpat_0]  XGXS frequency test pattern register for lane 0.*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_TX_TxCntrl1_t tmp_xaui_tx_txcntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_tx_txcntrl1.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl1));
      tmp_xaui_tx_txcntrl1.bf.xgxs_fpat_0 = xgxs_fpat_0;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl1), tmp_xaui_tx_txcntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI TX CONTROL 2                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_tx_control2(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_fpat_1)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Fpat 1                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_fpat_1]  XGXS frequency test pattern register for lane 1.*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_TX_TxCntrl2_t tmp_xaui_tx_txcntrl2;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_tx_txcntrl2.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl2));
      tmp_xaui_tx_txcntrl2.bf.xgxs_fpat_1 = xgxs_fpat_1;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl2), tmp_xaui_tx_txcntrl2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI TX CONTROL 3                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_tx_control3(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_fpat_2)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Fpat 2                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_fpat_2]  XGXS frequency test pattern register for lane 2.*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_TX_TxCntrl3_t tmp_xaui_tx_txcntrl3;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_tx_txcntrl3.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl3));
      tmp_xaui_tx_txcntrl3.bf.xgxs_fpat_2 = xgxs_fpat_2;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl3), tmp_xaui_tx_txcntrl3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI TX CONTROL 4                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_tx_control4(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_fpat_3)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Fpat 3                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_fpat_3]  XGXS frequency test pattern register for lane 3.*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_TX_TxCntrl4_t tmp_xaui_tx_txcntrl4;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_tx_txcntrl4.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl4));
      tmp_xaui_tx_txcntrl4.bf.xgxs_fpat_3 = xgxs_fpat_3;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl4), tmp_xaui_tx_txcntrl4.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI TX CONTROL 5                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_tx_control5(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 xgxs_tx_fone, 
                                 cs_uint16 xgxs_tx_fzero, 
                                 cs_uint16 rs_truncate, 
                                 cs_uint16 rs_force_output, 
                                 cs_uint16 xgxs_tx_phase)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Xgxs Tx Fone                                      */
/*              o Xgxs Tx Fzero                                     */
/*              o Rs Truncate                                       */
/*              o Rs Force Output                                   */
/*              o Xgxs Tx Phase                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xgxs_tx_fone]  This signal allows software to create a fault  */
/*     condition per XGXS transmit lane.                            */
/*                                                                  */
/*   [xgxs_tx_fzero]  This signal allows software to create a fault */
/*     condition per XGXS transmit lane.                            */
/*                                                                  */
/*   [rs_truncate]  When set any frame currently being output       */
/*     when a fault condition occurs is immediately truncated       */
/*                                                                  */
/*   [rs_force_output]  When set a user defined ordered set is      */
/*     continuously transmitted.                                    */
/*                                                                  */
/*   [xgxs_tx_phase]  XGXS transmit phase hit (per lane).           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_TX_TxCntrl5_t tmp_xaui_tx_txcntrl5;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_tx_txcntrl5.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl5));
      tmp_xaui_tx_txcntrl5.bf.xgxs_tx_fone = xgxs_tx_fone;
      tmp_xaui_tx_txcntrl5.bf.xgxs_tx_fzero = xgxs_tx_fzero;
      tmp_xaui_tx_txcntrl5.bf.rs_truncate = rs_truncate;
      tmp_xaui_tx_txcntrl5.bf.rs_force_output = rs_force_output;
      tmp_xaui_tx_txcntrl5.bf.xgxs_tx_phase = xgxs_tx_phase;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl5), tmp_xaui_tx_txcntrl5.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI TX CONTROL 6                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_tx_control6(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 rs_lane_2, 
                                 cs_uint16 rs_lane_1)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rs Lane 2                                         */
/*              o Rs Lane 1                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rs_lane_2]  Code to transmit on lane 2 when tx_force_output   */
/*     is set.                                                      */
/*                                                                  */
/*   [rs_lane_1]  Code to transmit on lane 1 when tx_force_output   */
/*     is set.                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_TX_TxCntrl6_t tmp_xaui_tx_txcntrl6;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_tx_txcntrl6.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl6));
      tmp_xaui_tx_txcntrl6.bf.rs_lane_2 = rs_lane_2;
      tmp_xaui_tx_txcntrl6.bf.rs_lane_1 = rs_lane_1;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl6), tmp_xaui_tx_txcntrl6.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI TX CONTROL 7                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xaui_tx_control7(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 rs_lane_3)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rs Lane 3                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the XGXS.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rs_lane_3]  Code to transmit on lane 3 when tx_force_output   */
/*     is set.                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BASEX_XAUI_TX_TxCntrl7_t tmp_xaui_tx_txcntrl7;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xaui_tx_txcntrl7.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl7));
      tmp_xaui_tx_txcntrl7.bf.rs_lane_3 = rs_lane_3;
      TEN_REG_WRITE(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, sl, TxCntrl7), tmp_xaui_tx_txcntrl7.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XAUI TX GET STATUS                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_xaui_tx_get_status(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Get the XGXS transmit status register.                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP10G_XAUI_TX_UNDERFLOW = 0,                             */
/*     TEN_PP10G_XAUI_TX_ALL = 1.                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;
  TEN_PP10G_BASEX_XAUI_TX_TX_INTSTAT_t tmp_xaui_tx_tx_intstat;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_xaui_tx_tx_intstat.wrd = TEN_REG_READ(TEN_PP10G_BASEX_REG_ADDR(pDev, module_id, slice, TX_INTSTAT));
  switch (select)
  {  
  case (TEN_PP10G_XAUI_TX_UNDERFLOW):
    rtn = tmp_xaui_tx_tx_intstat.bf.Underflow;
    break;
    
  case (TEN_PP10G_XAUI_TX_ALL):
    rtn = tmp_xaui_tx_tx_intstat.wrd;
    break;
    
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..3.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}







