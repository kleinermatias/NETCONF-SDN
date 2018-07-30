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
 * ten_pp10g_gfp.c 
 *
 * $Id: ten_pp10g_gfp.c,v 1.6 2013/02/22 20:48:04 jccarlis Exp $
 *
 * API's for PP10G GFP
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP RX CONTROL SRESET                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_rx_control_sreset(cs_uint16 module_id, 
                                          cs_uint8 slice, 
                                          cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control GFP sub-block RX logic reset.                            */
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
  TEN_PP10G_GFP_RX_MODE_t tmp_gfp_rx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_rx_mode.wrd = 0;
      tmp_gfp_rx_mode.bf.rxrst = 1;
      ten_reset_action(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, rx_MODE), 
                       tmp_gfp_rx_mode.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP RX SET MODE                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_rx_set_mode(cs_uint16 module_id, 
                                    cs_uint8 slice, 
                                    cs_uint16 mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Mode                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set various aspects of the GFP RX operating mode.                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [mode]                                                         */
/*     Sets the operating mode of the GFP module:                   */
/*     0 = GFP_S GFP-F: transport of MAC frames (DA/SA/../FCS) or   */
/*         transcoded frames.                                       */
/*     1 = GFP_T GFP-F: transparent transport of entire MAC         */
/*         frames (Preamble/SFD/DA/SA/../FCS) and Ordered Sets.     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_RX_MODE_t tmp_gfp_rx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_rx_mode.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, rx_MODE));
      tmp_gfp_rx_mode.bf.Mode = mode;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, rx_MODE), tmp_gfp_rx_mode.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP RX SET OUTCTRL                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_rx_set_outctrl(cs_uint16 module_id, 
                                       cs_uint8  slice, 
                                       cs_uint16 outctrl)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Mode                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set various aspects of the GFP RX operating mode.                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [outctrl]                                                      */
/*     OutCtrl[2:0]                                                 */
/*     3'h0 = NORM Output demapped frames and/or Ordered Sets       */
/*     3'h1 = OFF Override: Output is turned off                    */                          
/*     3'h2 = IDLE Override: Output continuous Idle at the OxU      */
/*            container rate                                        */
/*     3'h3 = LF Override: Output continuous Local Fault at the     */
/*            OxU container rate                                    */
/*     3'h4 = RF Override: Output continuous Remote Fault at the    */
/*            OxU container rate                                    */
/*     3'h5 = IDLEf Override: Output continuous Idle at the OxU     */
/*            rate                                                  */
/*     3'h6 = LFf Override: Output continuous Local Fault at the    */
/*            OxU rate                                              */
/*     3'h7 = RFf Override: Output continuous Remote Fault at the   */
/*            OxU rate                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_RX_MODE_t tmp_gfp_rx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_rx_mode.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, rx_MODE));
      tmp_gfp_rx_mode.bf.OutCtrl = outctrl;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, rx_MODE), tmp_gfp_rx_mode.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP RX SET CORE HEADER CONTROLS            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_rx_set_core_header_controls(cs_uint16 module_id, cs_uint8 slice, 
                          cs_uint16 chkpli, 
                          cs_uint16 delta)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o ChkPLI                                            */
/*              o Delta                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Core Header Controls.                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [chkpli]  Enable/disable(default) comparing the incoming PLI   */
/*     field to MAXLEN.                                             */
/*                                                                  */
/*   [delta]  Transition from PRESYNC to SYNC state after Delta     */
/*     number of correct Core Headers.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_RX_CH_t tmp_gfp_rx_ch;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_rx_ch.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, CH));
      tmp_gfp_rx_ch.bf.ChkPLI = chkpli;
      tmp_gfp_rx_ch.bf.Delta = delta;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, CH), tmp_gfp_rx_ch.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP RX MAXLEN                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_rx_maxlen(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 max)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Max                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Maximum Frame Length Controls.                              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [max]  Maximum Frame Length.  Only applicable if ChkPLI        */
/*      is set.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_RX_MAXLEN_t tmp_gfp_rx_maxlen;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_rx_maxlen.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, MAXLEN));
      tmp_gfp_rx_maxlen.bf.Max = max;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, MAXLEN), tmp_gfp_rx_maxlen.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP RX CONFIGURE PAYLOAD HEADER            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_rx_configure_payload_header(cs_uint16 module_id, cs_uint8 slice, 
                          cs_uint16 sberr_corr_ph, 
                          cs_uint16 chkexi, 
                          cs_uint16 chkupi, 
                          cs_uint16 chkpti)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Sberr Corr Ph                                     */
/*              o ChkEXI                                            */
/*              o ChkUPI                                            */
/*              o ChkPTI                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure various Payload Header Controls.                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [sberr_corr_ph]  Enable(default)/disable correction of         */
/*     Payload Header single bit errors.                            */
/*                                                                  */
/*   [chkexi]  When set, the GFP receiver checks the EXI field.     */
/*                                                                  */
/*   [chkupi]  When set, the GFP receiver checks the UPI field.     */
/*                                                                  */
/*   [chkpti]  When set, the GFP receiver checks the PTI field.     */
/*     When clear, all frames received are treated as client data   */
/*     frames.                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_RX_PH_t tmp_gfp_rx_ph;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_rx_ph.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, rx_PH));
      tmp_gfp_rx_ph.bf.sberr_corr_ph = sberr_corr_ph;
      tmp_gfp_rx_ph.bf.ChkEXI = chkexi;
      tmp_gfp_rx_ph.bf.ChkUPI = chkupi;
      tmp_gfp_rx_ph.bf.ChkPTI = chkpti;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, rx_PH), tmp_gfp_rx_ph.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP RX SET EXPECTED UPI VALUES             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_rx_set_expected_upi(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 exupi_o, 
                           cs_uint16 exupi_d)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o ExUPI O                                           */
/*              o ExUPI D                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Expected UPI values.                                         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [exupi_o]                                                      */
/*     In 'Transparent GFP-F' mode, this is the expected UPI value  */
/*     for incoming 64b/66b Ordered Set Frames.                     */
/*                                                                  */
/*   [exupi_d]                                                      */
/*     In 'Standard' mode, this is the expected UPI value for       */
/*     incoming frames.  In 'Transparent GFP*F' mode, this is the   */
/*     expected UPI value for incoming 64b/66b encoded data         */
/*     (recommended: 0xFD).                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_RX_UPI_t tmp_gfp_rx_upi;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_rx_upi.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, rx_UPI));
      tmp_gfp_rx_upi.bf.ExUPI_O = exupi_o;
      tmp_gfp_rx_upi.bf.ExUPI_D = exupi_d;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, rx_UPI), tmp_gfp_rx_upi.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G GFP RX GET STATUS                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_int16 ten_pp10g_gfp_rx_get_status(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 select)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Status                                          */
/* DESCRIPTION:                                                 */
/* Returns the GFP RX Status.                                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_PP10G_GFP_RX_STATUS_PTMS =               1             */
/*   TEN_PP10G_GFP_RX_STATUS_UPMS =               2             */
/*   TEN_PP10G_GFP_RX_STATUS_EXMS =               3             */
/*   TEN_PP10G_GFP_RX_STATUS_RDIS =               4             */
/*   TEN_PP10G_GFP_RX_STATUS_FDIS =               5             */
/*   TEN_PP10G_GFP_RX_STATUS_CSFS =               6             */
/*   TEN_PP10G_GFP_RX_STATUS_LFDS =               7             */
/*   TEN_PP10G_GFP_RX_STATUS_ALL  = (whole reg)   0xFF.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_PP10G_GFP_RX_INTSTATUS_t tmp_gfp_rx_intstatus;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  tmp_gfp_rx_intstatus.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, slice, INTSTATUS));
      
  switch (select) {
  case (TEN_PP10G_GFP_RX_STATUS_PTMS):
    rtn = tmp_gfp_rx_intstatus.bf.ptmS;
    break;

  case (TEN_PP10G_GFP_RX_STATUS_UPMS):
    rtn = tmp_gfp_rx_intstatus.bf.upmS;
    break;

  case (TEN_PP10G_GFP_RX_STATUS_EXMS):
    rtn = tmp_gfp_rx_intstatus.bf.exmS;
    break;

  case (TEN_PP10G_GFP_RX_STATUS_RDIS):
    rtn = tmp_gfp_rx_intstatus.bf.rdiS;
    break;

  case (TEN_PP10G_GFP_RX_STATUS_FDIS):
    rtn = tmp_gfp_rx_intstatus.bf.fdiS;
    break;

  case (TEN_PP10G_GFP_RX_STATUS_CSFS):
    rtn = tmp_gfp_rx_intstatus.bf.csfS;
    break;

  case (TEN_PP10G_GFP_RX_STATUS_LFDS):
    rtn = tmp_gfp_rx_intstatus.bf.lfdS;
    break;

  case (TEN_PP10G_GFP_RX_STATUS_ALL):
    rtn = tmp_gfp_rx_intstatus.wrd;
    break;
  
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP TX CONTROL SRESET                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_tx_control_sreset(cs_uint16 module_id, 
                                          cs_uint8 slice, 
                                          cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control GFP sub-block TX logic reset.                            */
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
  TEN_PP10G_GFP_TX_MODE_t tmp_gfp_tx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_tx_mode.wrd = 0;
      tmp_gfp_tx_mode.bf.txrst = 1;
      ten_reset_action(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_MODE), 
                       tmp_gfp_tx_mode.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP TX SET MODE                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_tx_set_mode(cs_uint16 module_id, cs_uint8 slice, 
                            cs_uint16 mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Mode                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set various aspects of the GFP TX operating mode.                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [mode]  Sets the operating mode of the GFP module.             */
/*     0 = GFP_S GFP-F: transport of MAC frames (DA/SA/../FCS) or   */
/*         transcoded frames.                                       */
/*     1 = GFP_T GFP-F: transparent transport of entire MAC         */
/*         frames (Preamble/SFD/DA/SA/../FCS) and Ordered Sets.     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_TX_MODE_t tmp_gfp_tx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_tx_mode.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_MODE));
      tmp_gfp_tx_mode.bf.Mode = mode;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_MODE), tmp_gfp_tx_mode.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP TX SET POLYNOMIAL                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_tx_set_polynomial(cs_uint16 module_id, cs_uint8 slice, 
                            cs_uint16 pscrambler_poly)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PScrambler Poly                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set various aspects of the GFP TX operating mode.                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pscrambler_poly]  By default, the Payload scrambling          */
/*     polynomial is 1 + x^43. When this bit is set, the            */
/*     Payload scrambling polynomial is 1 + x^42 + x^47.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_TX_MODE_t tmp_gfp_tx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_tx_mode.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_MODE));
      tmp_gfp_tx_mode.bf.pScrambler_poly = pscrambler_poly;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_MODE), tmp_gfp_tx_mode.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP TX SET SCHEDULER ENABLE BIT 1          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_tx_set_schen1(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 schen1)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Scheduler Enable Bit 1                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Bit 1 (Schedule CMF Frames) of the SCHen field.             */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [schen1] Specified 0,1 The Scheduler arbitrates and schedules  */
/*     traffic from three sources: Elastic Store (ES), CMF          */
/*     Insertion Buffer and MCF Insertion Buffer. Individual        */
/*     traffic sources can be turned ON/OFF via this control        */
/*     register. When no source has traffic available, Idle Frames  */
/*     are scheduled.                                               */
/*     1xx = Enable traffic sourced from the Elastic Store.         */
/*     0xx = Disable traffic sourced from the Elastic Store.        */
/*     x1x = Enable traffic sourced from the CMF Insertion Buffer.  */
/*     x0x = Disable traffic sourced from the CMF Insertion Buffer. */
/*     xx1 = Enable traffic sourced from the MCF Insertion Buffer.  */
/*     xx0 = Disable traffic sourced from the MCF Insertion Buffer. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_TX_MODE_t tmp_gfp_tx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (schen1 > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": schen1 out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_tx_mode.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_MODE));
      if (schen1 == 1) {
        tmp_gfp_tx_mode.bf.SCHen |= 0x2;
      }
      else {
        tmp_gfp_tx_mode.bf.SCHen &= 0xD;
      }
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_MODE), tmp_gfp_tx_mode.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP TX SET SCHEDULER PRIORITY 1            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_tx_set_schpri1(cs_uint16 module_id,
                                       cs_uint8 slice, 
                                       cs_uint16 schpri1)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Scheduler Priority 1                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set various aspects of the GFP TX operating mode.                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [schpri1]  Controls the static priority of traffic sourced     */
/*     from the Elastic Store vs. traffic sourced from the          */
/*     Insertion Buffer (IB) (CMF or MCF).                          */
/*     1'b0 = Elastic Store (ES) traffic is highest priority        */
/*     1'b1 = Insertion Buffer (IB) traffic is highest priority     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_TX_MODE_t tmp_gfp_tx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_tx_mode.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_MODE));
      tmp_gfp_tx_mode.bf.SCHpri1 = schpri1;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_MODE), tmp_gfp_tx_mode.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  PP10G GFP TX SET PAYLOAD HEADER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_gfp_tx_set_payload_header(cs_uint16 module_id, cs_uint8 slice, 
                          cs_uint16 pti, 
                          cs_uint16 pfi)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PTI                                           */
/*              o PFI                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets Payload Header Control.                                 */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [pti] parameter is specified as:                         */
/*   PTI[2:0]                                                   */
/*   The Payload Type Identifier used to transmit all frames    */
/*   sourced from the ES ('Transparent GFP-F' mode              */
/*   recommendation: 000).                                      */
/*                                                              */
/* The [pfi] parameter is specified as:                         */
/*   PFI                                                        */
/*   The Payload FCS Indicator used to transmit all frames      */
/*   sourced from the ES. When set, the transmitter calculates  */
/*   and appends the pFCS field ('Transparent GFP-F' mode       */
/*   recommendation: 0). The PFI field of frames from the       */
/*   Insertion Buffer are inspected to determine whether to     */
/*   calculate and insert the pFCS field for these frames.      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_TX_PH_t tmp_gfp_tx_ph;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_tx_ph.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_PH));
      tmp_gfp_tx_ph.bf.PTI = pti;
      tmp_gfp_tx_ph.bf.PFI = pfi;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_PH), tmp_gfp_tx_ph.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G GFP TX UPI                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_gfp_tx_upi(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 upi_o, 
                           cs_uint16 upi_d)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o UPI O                                         */
/*              o UPI D                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets UPI values.                                             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [upi_o] parameter is specified as:                       */
/*   UPI_O[7:0]                                                 */
/*   In 'Transparent GFP-F' mode, this UPI value is used to     */
/*   transmit 64b/66b Ordered Set Frames.                       */
/*                                                              */
/* The [upi_d] parameter is specified as:                       */
/*   UPI_D[7:0]                                                 */
/*   In 'Standard' mode, this UPI value is used to transmit all */
/*   frames sourced from the ES (defaults to 'Frame-Mapped      */
/*   Ethernet' (0x01)). In 'Transparent GFP-F' mode, this UPI   */
/*   value is used to transmit 64b/66b encoded data             */
/*   (recommended: 0xFD).                                       */
/*   GFP Mode     UPI_D                  UPI_O                  */
/*   -----------  ---------------------  ---------------------- */
/*   Standard     The value 0000 0001    Not applicable         */
/*   (STD)        (default)denotes                              */
/*                Frame-Mapped Ethernet                         */
/*                                                              */
/*   Transparent  The value 1111 1101    The value 1111 1110 is */
/*   (TRP)        is preferred for       preferred for 64B/66B  */
/*                64B/66B Encoded Data   Ordered Sets mapping   */
/*                mapping for 10GbE      for 10GbE              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_TX_UPI_t tmp_gfp_tx_upi;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_tx_upi.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_UPI));
      tmp_gfp_tx_upi.bf.UPI_O = upi_o;
      tmp_gfp_tx_upi.bf.UPI_D = upi_d;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, tx_UPI), tmp_gfp_tx_upi.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G GFP SET TX INSERT ACCESS 0             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_gfp_set_tx_insert_access_0(cs_uint16 module_id,
                                               cs_uint8 slice, 
                                               cs_uint16 data_0)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Data 0                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The Insertion Buffer has two partitions, 0 and 1. Each       */
/* partition has 64 locations (128 octets). The contents of     */
/* these are determined by the software controls MODE.SCHen[0]  */
/* and MODE.SCHen[1]. If neither is enabled, insertion is       */
/* disabled. If only one is enabled, both partitions are used   */
/* for that frame type. If both are enabled, then partition 0   */
/* is dedicated to CMF and partition 1 is dedicated to MCF.     */
/* When writing(reading) this register, the internal            */
/* write(read) pointer is reset to the first location in        */
/* partition 0 and that location is written(read). The internal */
/* write(read) pointer is automatically advanced to the next    */
/* location after the write(read) is done. Subsequent           */
/* write(read) operations are performed by writing(reading)     */
/* register INSERT_ACCESS_N. A CMF frame must be written(read)  */
/* by software in its entirety before switching to              */
/* writing(reading) a MCF frame or vice versa. The software     */
/* write(read) insertion buffer routine must be considered an   */
/* atomic function. The written PLI value is transmitted        */
/* unmodified. The PLI value accounts for the Payload Header    */
/* (4 octets), the Payload (N octets) and the optional pFCS     */
/* (4 octets) if PFI is set. If the written CMF/MCF frame has a */
/* non-zero Payload field, the required minimum number of       */
/* octets is N=4.                                               */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/*   [data_0] Specified as:                                     */
/*     First octet to be transmitted is located in [15:8],      */
/*     second octet to be transmitted is located in [7:0].      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, INSERT_ACCESS_0), data_0);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G GFP SET TX INSERT ACCESS 1             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_gfp_set_tx_insert_access_1(cs_uint16 module_id,
                                               cs_uint8 slice, 
                                               cs_uint16 data_1)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Data 1                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The Insertion Buffer has two partitions, 0 and 1. Each       */
/* partition has 64 locations (128 octets). The contents of     */
/* these are determined by the software controls MODE.SCHen[0]  */
/* and MODE.SCHen[1]. If neither is enabled, insertion is       */
/* disabled. If only one is enabled, both partitions are used   */
/* for that frame type. If both are enabled, then partition 0   */
/* is dedicated to CMF and partition 1 is dedicated to MCF.     */
/* When writing(reading) this register, the internal            */
/* write(read) pointer is reset to the first location in        */
/* partition 1 and that location is written(read). The internal */
/* write(read) pointer is automatically advanced to the next    */
/* location after the write(read) is done. Subsequent           */
/* write(read) operations are performed by writing(reading)     */
/* register INSERT_ACCESS_N. A CMF frame must be written(read)  */
/* by software in its entirety before switching to              */
/* writing(reading) a MCF frame or vice versa. The software     */
/* write(read) insertion buffer routine must be considered an   */
/* atomic function. The written PLI value is transmitted        */
/* unmodified. The PLI value accounts for the Payload Header    */
/* (4 octets), the Payload (N octets) and the optional pFCS     */
/* (4 octets) if PFI is set. If the written CMF/MCF frame has a */
/* non-zero Payload field, the required minimum number of       */
/* octets is N=4.                                               */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/*   [data_1] Specified as:                                     */
/*     First octet to be transmitted is located in [15:8],      */
/*     second octet to be transmitted is located in [7:0].      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, INSERT_ACCESS_1), data_1);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G GFP SET TX INSERT ACCESS N             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_gfp_set_tx_insert_access_n(cs_uint16 module_id,
                                               cs_uint8 slice, 
                                               cs_uint16 data_n)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Data N                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* When writing(reading) this register, the location addressed  */
/* by the internal write(read) pointer is written(read) and the */
/* write(read) pointer is automatically advanced to the next    */
/* location. The internal write(read) pointer does not advance  */
/* beyond the end of partition 1. A CMF frame must be           */
/* written(read) by software in its entirety before switching   */
/* to writing(reading) a MCF frame or vice versa. The software  */
/* write(read) insertion buffer routine must be considered an   */
/* atomic function.                                             */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/*   [data_n] Specified as:                                     */
/*     First octet to be transmitted is located in [15:8],      */
/*     second octet to be transmitted is located in [7:0].      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, INSERT_ACCESS_N), data_n);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G GFP SET TX INSERT CMF AUTO             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_gfp_set_tx_insert_cmf_auto(cs_uint16 module_id,
                                               cs_uint8 slice, 
                                               cs_uint16 num, 
                                               cs_uint16 ticks)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Num                                           */
/*              o Ticks                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Automatic CMF Transmission Control Register.         */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/*   [num] Num[3:0] This value allows transmitting 1(Num=0)-    */
/*     16(Num=15) CMF frames when INSERT[CMF_av] is asserted.   */
/*                                                              */
/*   [ticks] Ticks[9:0] This value allows for flexibility in    */
/*     setting the number of 1ms ticks between and automatic    */
/*     CMF transmission. The unit is 1ms. It defaults to 999    */
/*     which corresponds to 1sec.                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_TX_INSERT_CMF_AUTO_t tmp_gfp_tx_insert_cmf_auto;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_tx_insert_cmf_auto.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, INSERT_CMF_AUTO));
      tmp_gfp_tx_insert_cmf_auto.bf.Num = num;
      tmp_gfp_tx_insert_cmf_auto.bf.Ticks = ticks;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, INSERT_CMF_AUTO), tmp_gfp_tx_insert_cmf_auto.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G GFP SET TX INSERT CMF AUTO BIT         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_gfp_set_tx_insert_cmf_auto_bit(cs_uint16 module_id,
                                                   cs_uint8 slice, 
                                                   cs_uint16 cmf_auto)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o CMF Auto                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* When set, the contents of the CMF Insertion Buffer is        */
/* transmitted automatically at a frequency controlled by the   */
/* INSERT_CMF_AUTO[Ticks] bits. This bit has higher priority    */
/* than the CMF_av control bit. There is a 1-2 cycle delay      */
/* before this signal reaches the scheduler due to a            */
/* conditioning state machine which handles 'CMF_auto'/'CMF_av' */
/* in the path.                                                 */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/*   [cmf_auto] Specified as 0 or 1                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_TX_INSERT_t tmp_gfp_tx_insert;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_tx_insert.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, INSERT));
      tmp_gfp_tx_insert.bf.CMF_auto = cmf_auto;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, INSERT), tmp_gfp_tx_insert.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}



/********************************************************************/
/* $rtn_hdr_start  PP10G GFP SET RX CMF ENABLES                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_set_gfp_rx_cmf_enables(cs_uint16 module_id,
                                           cs_uint8  slice, 
                                           cs_uint8  select, 
                                           cs_uint8  value)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Client Management Frame Controls. ITU-T G.7041 Loss of Client    */
/* Signal and Loss of Character Synchronization UPI values are      */
/* hardwired to 0x01 and 0x02, respectively.                        */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [select] parameter is the the expected UPI value for         */
/* incoming CMF frames and is specified as:                         */
/*   TEN_PP10G_GFP_RX_CMF_ENABLE = 0                                */
/*     Enable/disable(default) extraction of incoming CMF frames.   */
/*   TEN_PP10G_GFP_RX_CMF_RDI    = 1                                */
/*     This setting does not affect CMF Extraction. Enable(default) */
/*     or disable CMF RDI frame processing. If disabled, RDI frames */
/*     have no effect on the GFP receiver.                          */
/*   TEN_PP10G_GFP_RX_CMF_FDI    = 2                                */
/*     This setting does not affect CMF Extraction. Enable(default) */
/*     or disable CMF FDI frame processing. If disabled, FDI frames */
/*     have no effect on the GFP receiver.                          */
/*   TEN_PP10G_GFP_RX_CMF_DCI    = 3                                */
/*     This setting does not affect CMF Extraction. Enable(default) */
/*     or disable consequent actions of CMF DCI frames. If enabled, */
/*     the Client Signal Fail defect (dCSF) can be cleared          */
/*     immediately upon receiving a DCI frame. If disabled, DCI     */
/*     frames have no effect on the dCSF status.                    */
/*                                                                  */
/* The [value] parameter is specified as:                           */
/*   0(disable)..1(enable)                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_RX_CMF_t tmp_gfp_rx_cmf;
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_rx_cmf.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, CMF));
      switch (select) {
        case TEN_PP10G_GFP_RX_CMF_ENABLE :
          {
            tmp_gfp_rx_cmf.bf.CMF_en = value & 0x01;
            break;
          }
        case TEN_PP10G_GFP_RX_CMF_RDI :
          {
            tmp_gfp_rx_cmf.bf.CMF_RDIen = value & 0x01;
            break;
          }
        case TEN_PP10G_GFP_RX_CMF_FDI :
          {
            tmp_gfp_rx_cmf.bf.CMF_FDIen = value & 0x01;
            break;
          }
        case TEN_PP10G_GFP_RX_CMF_DCI :
          {
            tmp_gfp_rx_cmf.bf.CMF_DCIen = value & 0x01;
            break;
          }
        default :
          {
            CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..3.");
            ret_val = CS_ERROR;
          }
      }
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, CMF), tmp_gfp_rx_cmf.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP SET RX CMF VALUES                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_set_rx_cmf_values(cs_uint16 module_id,
                                          cs_uint8  slice, 
                                          cs_uint8  select, 
                                          cs_uint8  value)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Client Management Frame Controls. ITU-T G.7041 Loss of Client    */
/* Signal and Loss of Character Synchronization UPI values are      */
/* hardwired to 0x01 and 0x02, respectively.                        */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [select] parameter is the the expected UPI value for         */
/* incoming CMF frames and is specified as:                         */
/*   TEN_PP10G_GFP_RX_CMF_RDI    = 1                                */
/*   TEN_PP10G_GFP_RX_CMF_FDI    = 2                                */
/*   TEN_PP10G_GFP_RX_CMF_DCI    = 3                                */
/*                                                                  */
/* The [value] parameter is specified as:                           */
/*   0x00..0xFF                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_RX_CMF_t tmp_gfp_rx_cmf;
  TEN_PP10G_GFP_RX_CMF2_t tmp_gfp_rx_cmf2;
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_rx_cmf.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, CMF));
      tmp_gfp_rx_cmf2.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, CMF2));
      switch (select) {
        case TEN_PP10G_GFP_RX_CMF_RDI :
          {
            tmp_gfp_rx_cmf.bf.ExUPI_RDI   = value & 0x0F;
            tmp_gfp_rx_cmf2.bf.ExUPI_RDIu = value >> 4;
            break;
          }
        case TEN_PP10G_GFP_RX_CMF_FDI :
          {
            tmp_gfp_rx_cmf.bf.ExUPI_FDI   = value & 0x0F;
            tmp_gfp_rx_cmf2.bf.ExUPI_FDIu = value >> 4;
            break;
          }
        case TEN_PP10G_GFP_RX_CMF_DCI :
          {
            tmp_gfp_rx_cmf.bf.ExUPI_DCI   = value & 0x0F;
            tmp_gfp_rx_cmf2.bf.ExUPI_DCIu = value >> 4;
            break;
          }
        default :
          {
            CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 1..3.");
            ret_val = CS_ERROR;
          }
      }
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, CMF), tmp_gfp_rx_cmf.wrd);
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, CMF2), tmp_gfp_rx_cmf2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GFP RX MARK T41                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_gfp_rx_mark_t41(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 m_pfcs_err)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o M PFCS Err                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Determines whether demapped frames are marked with error         */
/* when leaving the GFP receiver.  This is irrelevant for           */
/* terminated frames.                                               */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [m_pfcs_err]                                                   */
/*    Assert error for frames with Payload FCS error.               */
/*    When asserted, frames with pFCS error are marked              */
/*    with error. When deasserted, frames with pFCS error           */
/*    are not marked with error.                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_GFP_RX_MARK_t tmp_gfp_rx_mark;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gfp_rx_mark.wrd = TEN_REG_READ(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, MARK));
      tmp_gfp_rx_mark.bf.m_pFCS_err = m_pfcs_err;
      TEN_REG_WRITE(TEN_PP10G_GFP_REG_ADDR(pDev, module_id, sl, MARK), tmp_gfp_rx_mark.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}


