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
 * ten_pp10g_fc.c 
 *
 * $Id: ten_pp10g_fc.c,v 1.5 2013/02/22 20:48:04 jccarlis Exp $
 *
 * API's for PP10G FC
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  PP10G FC RX CONTROL SOFT (LOGIC) RESET           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_fc_rx_reset(cs_uint16 module_id, cs_uint8 slice, 
                                cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control FC sub-block RX logic reset.                             */
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
  TEN_PP10G_FC_RX_RESET_t tmp_fc_rx_reset;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_fc_rx_reset.wrd = 0;
      tmp_fc_rx_reset.bf.rxrst = 1;
      ten_reset_action(TEN_PP10G_FC_REG_ADDR(pDev, module_id, sl, RESET), 
                       tmp_fc_rx_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  PP10G FC RX PSQ CONTROL                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_fc_rx_psq_control(cs_uint16 module_id, cs_uint8 slice, 
                             cs_uint16 en, 
                             cs_uint16 pseq_rsvd, 
                             cs_uint16 set_thr, 
                             cs_uint16 clr_thr)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o En                                                */
/*              o Pseq Rsvd                                         */
/*              o Set Thr                                           */
/*              o Clr Thr                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of PSQ.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [en]  Enable(default)/disable the Primitive Sequence           */
/*     Qualification module.                                        */
/*                                                                  */
/*   [pseq_rsvd]  Enable(default)/disable whether a reserved        */
/*     primitive sequence is processed as a defined primitive       */
/*     sequence.                                                    */
/*                                                                  */
/*   [set_thr]  User threshold to set how many consecutive          */
/*     columns to count before qualifying a primitive sequence.     */
/*                                                                  */
/*   [clr_thr]  User threshold to set how many consecutive          */
/*     columns to count before clearing the qualified primitive     */
/*     sequence.                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_FC_RX_R_CTRL_t tmp_fc_rx_r_ctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_fc_rx_r_ctrl.wrd = TEN_REG_READ(TEN_PP10G_FC_REG_ADDR(pDev, module_id, sl, R_CTRL));
      tmp_fc_rx_r_ctrl.bf.en = en;
      tmp_fc_rx_r_ctrl.bf.pseq_rsvd = pseq_rsvd;
      tmp_fc_rx_r_ctrl.bf.set_thr = set_thr;
      tmp_fc_rx_r_ctrl.bf.clr_thr = clr_thr;
      TEN_REG_WRITE(TEN_PP10G_FC_REG_ADDR(pDev, module_id, sl, R_CTRL), tmp_fc_rx_r_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G FC RX GET PSQ STATUS                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_fc_rx_get_psq_status(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Gets RX PSQ status.                                              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_RSVDS          1                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LPE_Y_XS       2                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LPE_F_XS       3                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LPB_Y_XS       4                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LPB_F_XS       5                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LIP_Y_XS       6                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F_XS       7                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F8_XS      8                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F7_XS      9                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F8_F7S    10                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F7_F7S    11                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_RFS           12                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LFS           13                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LRRS          14                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_LRS           15                 */
/*     TEN_PP10G_FC_RX_STATUS_PRIM_OLSS          16                 */
/*     TEN_PP10G_FC_RX_STATUS_ALL                0xFF (whole reg).  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_PP10G_FC_RX_R_INTSTATUS_t tmp_fc_rx_r_intstatus;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_fc_rx_r_intstatus.wrd = TEN_REG_READ(TEN_PP10G_FC_REG_ADDR(pDev, module_id, slice, R_INTSTATUS));

  switch (select) {
  case (TEN_PP10G_FC_RX_STATUS_PRIM_RSVDS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_rsvdS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LPE_Y_XS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lpe_y_xS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LPE_F_XS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lpe_f_xS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LPB_Y_XS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lpb_y_xS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LPB_F_XS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lpb_f_xS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LIP_Y_XS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lip_y_xS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F_XS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lip_f_xS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F8_XS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lip_f8_xS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F7_XS):
  rtn =tmp_fc_rx_r_intstatus.bf.prim_lip_f7_xS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F8_F7S):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lip_f8_f7S;
  break;
  
  case (TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F7_F7S):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lip_f7_f7S;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_RFS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_rfS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LFS):
  rtn =  tmp_fc_rx_r_intstatus.bf.prim_lfS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LRRS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lrrS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_LRS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_lrS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_PRIM_OLSS):
  rtn = tmp_fc_rx_r_intstatus.bf.prim_olsS;
  break;

  case (TEN_PP10G_FC_RX_STATUS_ALL):
  rtn = tmp_fc_rx_r_intstatus.wrd;
  break;
  
  default:
  CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
  rtn = CS_ERROR;
  break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G FC RX MODE CONTROL                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_fc_rx_mode_control(cs_uint16 module_id, cs_uint8 slice, 
                             cs_uint16 idle_req)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Idle Req                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various aspects of  Mode Controls.                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [idle_req]  Controls the number of Idle columns that must      */
/*     preceed an SOF column before the frame start is considered   */
/*     valid.                                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_FC_RX_M_CTRL_t tmp_fc_rx_m_ctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_fc_rx_m_ctrl.wrd = TEN_REG_READ(TEN_PP10G_FC_REG_ADDR(pDev, module_id, sl, M_CTRL));
      tmp_fc_rx_m_ctrl.bf.idle_req = idle_req;
      TEN_REG_WRITE(TEN_PP10G_FC_REG_ADDR(pDev, module_id, sl, M_CTRL), tmp_fc_rx_m_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G FC RX M MAXLEN                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_fc_rx_m_maxlen(cs_uint16 module_id, cs_uint8 slice, 
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
/*   [max]                                                          */
/*     Maximum Frame Length. The length covers the SOF (4 octets),  */
/*     the frame content and the EOF (4 octets).  Defaults to 2148. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_FC_RX_M_MAXLEN_t tmp_fc_rx_m_maxlen;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_fc_rx_m_maxlen.wrd = TEN_REG_READ(TEN_PP10G_FC_REG_ADDR(pDev, module_id, sl, M_MAXLEN));
      tmp_fc_rx_m_maxlen.bf.Max = max;
      TEN_REG_WRITE(TEN_PP10G_FC_REG_ADDR(pDev, module_id, sl, M_MAXLEN), tmp_fc_rx_m_maxlen.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G FC RX M DIAG                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_fc_rx_m_diag(cs_uint16 module_id, cs_uint8 slice, 
                             cs_uint16 primsig)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PrimSig                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various controls for diagnostics.                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [primsig]  Select Primitive Signal for counting.               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_FC_RX_M_DIAG_t tmp_fc_rx_m_diag;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_fc_rx_m_diag.wrd = TEN_REG_READ(TEN_PP10G_FC_REG_ADDR(pDev, module_id, sl, M_DIAG));
      tmp_fc_rx_m_diag.bf.PrimSig = primsig;
      TEN_REG_WRITE(TEN_PP10G_FC_REG_ADDR(pDev, module_id, sl, M_DIAG), tmp_fc_rx_m_diag.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

