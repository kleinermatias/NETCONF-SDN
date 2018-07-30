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
 * $Id: ten_hsif_xfi32x1.c,v 1.26 2013/02/22 20:49:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 PRBSGEN CONFIG                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_prbsgen_config(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 prbs_mode, 
                               cs_uint16 invertprbs, 
                               cs_uint16 fixed_pattern, 
                               cs_uint16 prbs_enable)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Prbs Mode                                         */
/*              o InvertPrbs                                        */
/*              o Fixed Pattern                                     */
/*              o Prbs Enable                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the  PRBS Generator.                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [prbs_mode]  Selects PRBS generation polynomial.               */
/*                                                                  */
/*   [invertprbs]  Inverts the transmit PRBS pattern.               */
/*                                                                  */
/*   [fixed_pattern]  When set to 1, Enables transmitting a fixed   */
/*      repeating pattern from the FixedPat register.               */
/*                                                                  */
/*   [prbs_enable]  Enables PRBS generator.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSGEN0_Cfg_t tmp_prbsgen0_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbsgen0_cfg.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Cfg));
      tmp_prbsgen0_cfg.bf.prbs_mode = prbs_mode;
      tmp_prbsgen0_cfg.bf.invertPrbs = invertprbs;
      tmp_prbsgen0_cfg.bf.fixed_pattern = fixed_pattern;
      tmp_prbsgen0_cfg.bf.prbs_enable = prbs_enable;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Cfg), tmp_prbsgen0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 PRBSGEN ENABLE                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_prbsgen_enable(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 prbs_enable)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Prbs Enable                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables the PRBS Generator.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [prbs_enable]  Enables PRBS generator.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSGEN0_Cfg_t tmp_prbsgen0_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbsgen0_cfg.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Cfg));
      tmp_prbsgen0_cfg.bf.prbs_enable = prbs_enable;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Cfg), tmp_prbsgen0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 PRBSGEN CONTROL                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_prbsgen_control(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 inserterror, 
                                cs_uint16 insertonebiterror, 
                                cs_uint16 inserterroronce, 
                                cs_uint16 insertonebiterroronce)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o InsertError                                       */
/*              o InsertOneBitError                                 */
/*              o InsertErrorOnce                                   */
/*              o InsertOneBitErrorOnce                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the PRBS Generator.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [inserterror]  Continuously injects word errors into the       */
/*     transmit PRBS pattern until cleared.                         */
/*                                                                  */
/*   [insertonebiterror]  Continuously injects one bit error per    */
/*     word into the transmit PRBS pattern until cleared.           */
/*                                                                  */
/*   [inserterroronce]  Injects only one word error into the        */
/*     transmit PRBS pattern.  The error is injected on the rising  */
/*     edge of this bit.                                            */
/*                                                                  */
/*   [insertonebiterroronce]  Injects only one bit error into the   */
/*     transmit PRBS pattern.  The error is injected on the rising  */
/*     edge of this bit.                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSGEN0_Ctrl_t tmp_prbsgen0_ctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbsgen0_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Ctrl));
      tmp_prbsgen0_ctrl.bf.insertError = inserterror;
      tmp_prbsgen0_ctrl.bf.insertOneBitError = insertonebiterror;
      tmp_prbsgen0_ctrl.bf.insertErrorOnce = inserterroronce;
      tmp_prbsgen0_ctrl.bf.insertOneBitErrorOnce = insertonebiterroronce;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Ctrl), tmp_prbsgen0_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 PRBSGEN SET FIXED0 PATTERN               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_prbsgen_set_fixed0_pattern(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 value1,
                                              cs_uint16 value0)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o VALUE1                                            */
/*              o VALUE0                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets pattern to transmit when fixed_pattern is set.              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [value1]  Data pattern to transmit.                            */
/*                                                                  */
/*   [value0]  Data pattern to transmit.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSGEN0_Fixed0_Pattern1_t tmp_prbsgen0_fixed0_pattern1;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSGEN0_Fixed0_Pattern0_t tmp_prbsgen0_fixed0_pattern0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbsgen0_fixed0_pattern1.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed0_Pattern1));
      tmp_prbsgen0_fixed0_pattern1.bf.VALUE1 = value1;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed0_Pattern1), tmp_prbsgen0_fixed0_pattern1.wrd);
      
      tmp_prbsgen0_fixed0_pattern0.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed0_Pattern0));
      tmp_prbsgen0_fixed0_pattern0.bf.VALUE0 = value0;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed0_Pattern0), tmp_prbsgen0_fixed0_pattern0.wrd);
      
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 PRBSGEN FIXED1 PATTERN                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_prbsgen_fixed1_pattern1(cs_uint16 module_id, cs_uint8 slice, 
                                               cs_uint16 value1,
                                               cs_uint16 value0)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o VALUE1                                            */
/*              o VALUE0                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets pattern to transmit when fixed_pattern is set.              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [value1]  Data pattern to transmit.                            */
/*                                                                  */
/*   [value0]  Data pattern to transmit.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSGEN0_Fixed1_Pattern1_t tmp_prbsgen0_fixed1_pattern1;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSGEN0_Fixed1_Pattern0_t tmp_prbsgen0_fixed1_pattern0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
    
      tmp_prbsgen0_fixed1_pattern1.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed1_Pattern1));
      tmp_prbsgen0_fixed1_pattern1.bf.VALUE1 = value1;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed1_Pattern1), tmp_prbsgen0_fixed1_pattern1.wrd);
      
      tmp_prbsgen0_fixed1_pattern0.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed1_Pattern0));
      tmp_prbsgen0_fixed1_pattern0.bf.VALUE0 = value0;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed1_Pattern0), tmp_prbsgen0_fixed1_pattern0.wrd);
      
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 PRBSGEN SET REPEAT PATTERN               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_prbsgen_set_repeat_pattern(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 repeat1, 
                                          cs_uint16 repeat0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Repeat1                                           */
/*              o Repeat0                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the number of times to transmit patterns when fixed_pattern */
/* is selected.                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [repeat1]  Number of times to repeat pattern 1                 */
/*                                                                  */
/*   [repeat0]  Number of times to repeat pattern 0                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSGEN0_Repeat_Pattern_t tmp_prbsgen0_repeat_pattern;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbsgen0_repeat_pattern.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Repeat_Pattern));
      tmp_prbsgen0_repeat_pattern.bf.repeat1 = repeat1;
      tmp_prbsgen0_repeat_pattern.bf.repeat0 = repeat0;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Repeat_Pattern), tmp_prbsgen0_repeat_pattern.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 PRBSCHK CONFIG                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_prbschk_config(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 prbs_mode, 
                               cs_uint16 invertprbs)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Prbs Mode                                         */
/*              o InvertPrbs                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the PRBS checker.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [prbs_mode]  Selects PRBS generation polynomial.               */
/*                                                                  */
/*   [invertprbs]  Inverts the receive bit pattern.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK0_Cfg_t tmp_prbschk0_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbschk0_cfg.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Cfg));
      tmp_prbschk0_cfg.bf.prbs_mode = prbs_mode;
      tmp_prbschk0_cfg.bf.invertPrbs = invertprbs;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Cfg), tmp_prbschk0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 PRBSCHK ENABLE                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_prbschk_enable(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 enable)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Enable                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables the PRBS checker.                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [enable]  Enables receive PRBS monitoring function.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK0_Cfg_t tmp_prbschk0_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbschk0_cfg.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Cfg));
      tmp_prbschk0_cfg.bf.enable = enable;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Cfg), tmp_prbschk0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 PRBSCHK CONTROL HUNT                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_prbschk_control_hunt(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 loadprbsstate)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o LoadPrbsState                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Causes the PRBS monitor to synchronize to the input stream.      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [loadprbsstate]  When set to one, the PRBS monitor enters the  */
/*     HUNT state and will stay in this state until the bit is      */
/*     cleared.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK0_Ctrl_t tmp_prbschk0_ctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbschk0_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Ctrl));
      tmp_prbschk0_ctrl.bf.loadPrbsState = loadprbsstate;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Ctrl), tmp_prbschk0_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 PRBSCHK GET STATUS                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_boolean ten_xfi32x1_prbschk_get_status(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE or FALSE                                       */
/* DESCRIPTION:                                                     */
/* Indicates that the receive PRBS monitor is synchronized.         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3).                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK0_INTSTATUS_t tmp_prbschk0_intstatus;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  tmp_prbschk0_intstatus.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, 
                               slice, PRBSCHK0_INTSTATUS));
  /*  When this bit is set it indicates that the receive  */
  /*  PRBS monitor is currently unable to synchronize.    */
  return (tmp_prbschk0_intstatus.bf.PRBS_SYNCs == 0);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 TX0 CONFIG                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_tx0_config(cs_uint16 module_id, cs_uint8 slice, 
                             cs_uint16 data_source)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Data Source                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Contains tx configuration for lane 0.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [data_source]  selects the input source for the TX  datapath.  */
/*     00 = DIG_TX_DIN                                              */
/*     01 = PRBS                                                    */
/*     10 = RX Loopback Data                                        */
/*     11 = Reserved                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TX0_Config_t tmp_tx0_config;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_tx0_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TX0_Config));
      tmp_tx0_config.bf.data_source = data_source;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TX0_Config), tmp_tx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 RX0 CONFIG                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_rx0_config(cs_uint16 module_id, cs_uint8 slice, 
                             cs_uint16 data_source)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Data Source                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Contains rx configuration for lane 0.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [data_source]  Selects the input source for the RX datapath.   */
/*     0 = SRX_DOUT (Serdes data)                                   */
/*     1 = TX Loopback Data.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RX0_Config_t tmp_rx0_config;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rx0_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RX0_Config));
      tmp_rx0_config.bf.data_source = data_source;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RX0_Config), tmp_rx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CLKDIV CTRL                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 stxp_fastdiv_sel, 
                                       cs_uint16 stxp_ctrdiv_sel, 
                                       cs_uint16 stxp_ctvdiv_sel, 
                                       cs_uint16 stxp_ddiv_sel, 
                                       cs_uint16 stxp_rdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP FASTDIV SEL                                  */
/*              o STXP CTRDIV SEL                                   */
/*              o STXP CTVDIV SEL                                   */
/*              o STXP DDIV SEL                                     */
/*              o STXP RDIV SEL                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls all of the TX clock dividers.                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_fastdiv_sel]  Select the serial clock divider to         */
/*     transmit PFD for comparison to the clock reference           */
/*                                                                  */
/*   [stxp_ctrdiv_sel]  Select to divide the clock reference        */
/*     before reaching the digital core for use in coarse tuning    */
/*                                                                  */
/*   [stxp_ctvdiv_sel]  Select to divide CLK_LD before reaching     */
/*     the digital core for use in coarse tuning                    */
/*                                                                  */
/*   [stxp_ddiv_sel]  Select clock rate for transmit data path      */
/*                                                                  */
/*   [stxp_rdiv_sel]  Select the serial clock divider to            */
/*     transmit PFD for comparison to the clock reference           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_FASTDIV_SEL = stxp_fastdiv_sel;
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_CTRDIV_SEL = stxp_ctrdiv_sel;
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_CTVDIV_SEL = stxp_ctvdiv_sel;
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_DDIV_SEL = stxp_ddiv_sel;
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL = stxp_rdiv_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CLKDIV CTRL CTV DIV             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctv_div(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 stxp_ctvdiv_sel) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP CTVDIV SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_ctvdiv_sel]                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_CTVDIV_SEL = stxp_ctvdiv_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CLKDIV CTRL CTR DIV             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 stxp_ctrdiv_sel) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP CTRDIV SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_ctrdiv_sel]                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_CTRDIV_SEL = stxp_ctrdiv_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CLKDIV CTRL FASTDIV SEL         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl_fastdiv_sel(cs_uint16 module_id,
                                                       cs_uint8  slice, 
                                                       cs_uint16 stxp_fastdiv_sel) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP FASTDIV SEL                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_fastdiv_sel]  Select the serial clock divider to         */
/*     transmit PFD for comparison to the clock reference           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_FASTDIV_SEL = stxp_fastdiv_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CLKDIV CTRL DDIV SEL            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ddiv_sel(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 stxp_ddiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP DDIV SEL                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls all of the TX clock dividers.                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_ddiv_sel]  Select clock rate for transmit data path      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_DDIV_SEL = stxp_ddiv_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CLKDIV CTRL RDIV SEL            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl_rdiv_sel(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 stxp_rdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP RDIV SEL                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_rdiv_sel]                                                */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL = stxp_rdiv_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 SRX0 RX CLKDIV CTRL CTVDIV SEL           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 srx_ctvdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX CTVDIV SEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_ctvdiv_sel]                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL));
      tmp_srx0_rx_clkdiv_ctrl.bf.SRX_CTVDIV_SEL = srx_ctvdiv_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL), tmp_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 SRX0 RX CLKDIV CTRL RDIV SEL             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 srx_rdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX RDIV SEL                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_rdiv_sel]                                                 */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL));
      tmp_srx0_rx_clkdiv_ctrl.bf.SRX_RDIV_SEL = srx_rdiv_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL), tmp_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 SRX0 RX CLKDIV CTRL DDIV SEL             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_srx0_rx_clkdiv_ctrl_ddiv_sel(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 srx_ddiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX DDIV SEL                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_ddiv_sel]                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL));
      tmp_srx0_rx_clkdiv_ctrl.bf.SRX_DDIV_SEL = srx_ddiv_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL), tmp_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 ENABLE1 LSB SRX FILTR                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_enable1_lsb_srx_filtr(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 srx_filtr)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX FILTR                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_filtr]                                                    */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_SDS_DSP_MSEQ_ENABLE1_LSB_t tmp_enable1_lsb;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_enable1_lsb.wrd = TEN_REG_READ(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, ENABLE1_LSB));
      tmp_enable1_lsb.bf.SRX_FILTR = srx_filtr;
      TEN_REG_WRITE(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, ENABLE1_LSB), tmp_enable1_lsb.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 CAL RX EQADJ                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_cal_rx_eqadj(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 srx_eqadj)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX EQADJ                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value applied to the SRX_EQADJ[3:0] input of the rx SerDes. */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_eqadj]  Microcode calibration parameter: the input        */
/*     equalizer setting of the rx SerDes.                          */
/*     Connects directly to the SRX_EQADJ input of the rx SerDes.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_SDS_DSP_MSEQ_CAL_RX_EQADJ_t tmp_cal_rx_eqadj;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cal_rx_eqadj.wrd = TEN_REG_READ(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, CAL_RX_EQADJ));
      tmp_cal_rx_eqadj.bf.SRX_EQADJ = srx_eqadj;
      TEN_REG_WRITE(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, CAL_RX_EQADJ), tmp_cal_rx_eqadj.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 CAL RX PHSEL                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_cal_rx_phsel(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 srx_phsel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX PHSEL                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value applied to the SRX_PHSEL input of the rx SerDes.      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_phsel]  Microcode calibration parameter: data sampling    */
/*     "phase select" setting of the rx SerDes.                     */
/*     Connects directly to the SRX_PHSEL input of the rx SerDes.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_SDS_DSP_MSEQ_CAL_RX_PHSEL_t tmp_cal_rx_phsel;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cal_rx_phsel.wrd = TEN_REG_READ(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, CAL_RX_PHSEL));
      tmp_cal_rx_phsel.bf.SRX_PHSEL = srx_phsel;
      TEN_REG_WRITE(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, CAL_RX_PHSEL), tmp_cal_rx_phsel.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX SPARE                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_spare(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 stxp_spare)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP SPARE                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_spare]                                                   */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SPARE_t tmp_stxp0_tx_spare;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_spare.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SPARE));
      tmp_stxp0_tx_spare.bf.STXP_SPARE = stxp_spare;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SPARE), tmp_stxp0_tx_spare.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 GRO SPARE REFCLK DIV SEL T41       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_gro_spare_refclk_div_sel_t41(cs_uint16 module_id,
                                                         cs_uint8  slice, 
                                                         cs_uint16 spare)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP REFCLK DIV SEL                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [spare]                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_GRO_SPARE_t tmp_stxp0_gro_spare;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_gro_spare.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_SPARE));
      tmp_stxp0_gro_spare.bf.STXP_GRO_SPARE = spare;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_SPARE), tmp_stxp0_gro_spare.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CP T41                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_cp_t41(cs_uint16 module_id,
                                      cs_uint8  slice, 
                                      cs_uint16 stxp_cptstdn,
                                      cs_uint16 stxp_cpcur1,
                                      cs_uint16 stxp_cpcur0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP_CPTSTDN                                      */
/*              o STXP_CPCUR1                                       */
/*              o STXP_CPCUR0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register controls aspects of the transmit PLL charge pump.  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   The [stxp_cptstdn] parameter is specified as:                  */
/*     Test input to force charge pump to down state.               */
/*     0 = not forced                                               */
/*     1 = forced                                                   */
/*                                                                  */
/*   The [stxp_cpcur1] parameter is specified as:                   */
/*     Charge pump current setting. This setting is used when the   */
/*     STXP_FREQ msb is 1.                                          */
/*                                                                  */
/*   The [stxp_cpcur0] parameter is specified as:                   */
/*     Charge pump current setting. This setting is used when the   */
/*     STXP_FREQ msb is 0.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CP_t tmp_stxp0_tx_cp;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_cp.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CP));
      tmp_stxp0_tx_cp.bf.STXP_CPTSTDN = stxp_cptstdn;
      tmp_stxp0_tx_cp.bf.STXP_CPCUR1  = stxp_cpcur1;
      tmp_stxp0_tx_cp.bf.STXP_CPCUR0  = stxp_cpcur0;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CP), tmp_stxp0_tx_cp.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX SPARE REFCLK DIV SEL T41        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_spare_refclk_div_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                        cs_uint16 stxp_refclk_div_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP REFCLK DIV SEL                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_refclk_div_sel]                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SPARE_t tmp_stxp0_tx_spare;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_spare.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SPARE));
      tmp_stxp0_tx_spare.bf.STXP_REFCLK_DIV_SEL = stxp_refclk_div_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SPARE), tmp_stxp0_tx_spare.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX LOOPTIME SELECT                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_lptime_sel(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 stxp_lptime_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP LPTIME SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_lptime_sel]  Enable Loop time mode in which one RX       */
/*     channel recovered clock is supplied as the reference         */
/*     for transmit.                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_LPTIME_SEL = stxp_lptime_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CONFIG                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_config(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 stxp_lptime_sel, 
                                  cs_uint16 stxp_pilot_sel, 
                                  cs_uint16 stxp_fcen,
                                  cs_uint16 stxp_buswidth, 
                                  cs_uint16 stxp_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP LPTIME SEL                                   */
/*              o STXP PILOT SEL                                    */
/*              o STXP FCEN                                         */
/*              o STXP BUSWIDTH                                     */
/*              o STXP LPBKEN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_lptime_sel]  Enable Loop time mode in which one RX       */
/*     channel recovered clock is supplied as the reference         */
/*     for transmit.                                                */
/*                                                                  */
/*   [stxp_pilot_sel]  Provide pilot tone clock to the receiver     */
/*     and the STXP_REF_LD pin                                      */
/*                                                                  */
/*   [stxp_fcen]  Enable 8.5GHz LC VCO for 8GFC mode                */
/*                                                                  */
/*   [stxp_buswidth]  MUX bus width at output.                      */
/*                                                                  */
/*   [stxp_lpbken]  Power drivers to enable serial loopback         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_LPTIME_SEL = stxp_lptime_sel;
      tmp_stxp0_tx_config.bf.STXP_PILOT_SEL = stxp_pilot_sel;
      tmp_stxp0_tx_config.bf.STXP_FCEN = stxp_fcen;
      tmp_stxp0_tx_config.bf.STXP_BUSWIDTH = stxp_buswidth;
      tmp_stxp0_tx_config.bf.STXP_LPBKEN = stxp_lpbken;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CONFIG LPBKEN                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_config_lpbken(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 stxp_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP LPBKEN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_lpbken]  Power drivers to enable serial loopback         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_LPBKEN = stxp_lpbken;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CONFIG PILOT SEL                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_config_pilot_sel(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 stxp_pilot_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP PILOT SEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_pilot_sel]  Provide pilot tone clock to the receiver     */
/*     and the STXP_REF_LD pin                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xfi32x1_stxp0_tx_config_pilot_sel";  

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s(): slice %d out of range.  s/b 0..3.", func, slice);
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s, SLICE_ALL, stxp_pilot_sel=%d\n", ten_module_strings[module_id&1], stxp_pilot_sel);
  } else {
    CS_PRINT("%s, %s, stxp_pilot_sel=%d\n", ten_module_strings[module_id&1], ten_slice_strings[slice], stxp_pilot_sel);
  }

  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_PILOT_SEL = stxp_pilot_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CONFIG FCEN                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_config_fcen(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 stxp_fcen)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP FCEN                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_fcen]  Enable 8.5GHz LC VCO for 8GFC mode                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_FCEN = stxp_fcen;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CONFIG LPTIME SEL MSB T41       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_config_lptime_sel_msb_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                         cs_uint16 stxp_lptime_sel_msb)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP LPTIME SEL MSB                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_lptime_sel_msb]                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_LPTIME_SEL_MSB = stxp_lptime_sel_msb;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STX0 TX OUTPUT CTRL                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stx0_tx_output_ctrl(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 stx_drv_lower_cm, 
                                          cs_uint16 stx_level,
                                          cs_uint16 stx_pre_peak, 
                                          cs_uint16 stx_post_peak)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STX DRV LOWER CM                                  */
/*              o STX LEVEL                                         */
/*              o STX PRE PEAK                                      */
/*              o STX POST PEAK                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure SERDES Analog Front End Adjustments.                   */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)        */
/*                                                                  */
/* [stx_drv_lower_cm]  Turns on current source to STX_DOUTP/N       */
/*   which increases the bias voltage thereby improving headroom.   */
/*   This is used primarily when STX_DOUTP/N is AC coupled.         */
/*   1111 = high bias,                                              */
/*   0000 = off                                                     */
/*                                                                  */
/* [stx_level]  Output driver cursor output level adjust, binary    */
/*   weighted, 0.5mA LSB.                                           */
/*   111111 = 31mA                                                  */
/*   000000 = off                                                   */
/*                                                                  */
/* [stx_pre_peak]  Output driver pre-cursor level adjust, binary    */
/*   weighted, 0.25mA LSB.                                          */
/*   11111 = 7.75mA                                                 */
/*   00000 = off                                                    */
/*                                                                  */
/* [stx_post_peak]  Output driver post-cursor level adjust, binary  */
/*   weighted, 0.25mA LSB.                                          */
/*   111111 = 15.75mA                                               */
/*   00000 = off.                                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_t tmp_stx0_tx_output_ctrla;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_t tmp_stx0_tx_output_ctrlb;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stx0_tx_output_ctrla.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLA));
      tmp_stx0_tx_output_ctrla.bf.STX_DRV_LOWER_CM = stx_drv_lower_cm;
      tmp_stx0_tx_output_ctrla.bf.STX_LEVEL = stx_level;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLA), tmp_stx0_tx_output_ctrla.wrd);
    
      tmp_stx0_tx_output_ctrlb.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLB));
      tmp_stx0_tx_output_ctrlb.bf.STX_PRE_PEAK = stx_pre_peak;
      tmp_stx0_tx_output_ctrlb.bf.STX_POST_PEAK = stx_post_peak;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLB), tmp_stx0_tx_output_ctrlb.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 SRX0 RX CONFIG                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_srx0_rx_config(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 srx_fcen, 
                                 cs_uint16 srx_amp_pd, 
                                 cs_uint16 srx_pd, 
                                 cs_uint16 srx_buswidth, 
                                 cs_uint16 srx_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX FCEN                                          */
/*              o SRX AMP PD                                        */
/*              o SRX PD                                            */
/*              o SRX BUSWIDTH                                      */
/*              o SRX LPBKEN                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for RX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_fcen]  Enable 8.5GHz LC VCO for 8GFC mode.                */
/*                                                                  */
/*   [srx_amp_pd]  Loop amplifier powerdown                         */
/*                                                                  */
/*   [srx_pd]  Power down the entire receive slice:                 */
/*                                                                  */
/*   [srx_buswidth]  Set DEMUX bus width:                           */
/*                                                                  */
/*   [srx_lpbken]  Enable serial loop back at Equalizer input.      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CONFIG_t tmp_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG));
      tmp_srx0_rx_config.bf.SRX_FCEN = srx_fcen;
      tmp_srx0_rx_config.bf.SRX_AMP_PD = srx_amp_pd;
      tmp_srx0_rx_config.bf.SRX_PD = srx_pd;
      tmp_srx0_rx_config.bf.SRX_BUSWIDTH = srx_buswidth;
      tmp_srx0_rx_config.bf.SRX_LPBKEN = srx_lpbken;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG), tmp_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 SRX0 RX CONFIG LPBKEN                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_srx0_rx_config_lpbken(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 srx_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX LPBKEN                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets lpbken bit for RX.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_lpbken]  Enable serial loop back at Equalizer input.      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CONFIG_t tmp_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG));
      tmp_srx0_rx_config.bf.SRX_LPBKEN = srx_lpbken;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG), tmp_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 SRX0 RX SRX_PD                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_srx0_rx_srx_pd(cs_uint16 module_id,
                                     cs_uint8 slice, 
                                     cs_uint16 srx_pd)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX PD                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for RX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_pd]  Power down the entire receive slice:                 */
/*                                                                  */

/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CONFIG_t tmp_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG));
      tmp_srx0_rx_config.bf.SRX_PD = srx_pd;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG), tmp_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 SRX0 RX CONFIG FCEN                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_srx0_rx_config_fcen(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 srx_fcen)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX FCEN                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for RX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_fcen]  Enable 8.5GHz LC VCO for 8GFC mode.                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CONFIG_t tmp_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG));
      tmp_srx0_rx_config.bf.SRX_FCEN = srx_fcen;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG), tmp_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 TXLOCKD0 CHECK LOCK                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_boolean ten_xfi32x1_txlockd0_lock(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Indicates if the SerDes is locked.                           */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_txlockd0_intstatus;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if (slice == sl) {
      tmp_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTSTATUS));
      ret_val = ret_val & ((tmp_txlockd0_intstatus.bf.FILT_LOCKs == 1) &
                           (tmp_txlockd0_intstatus.bf.LOCKs == 1));
    }
  }

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 RXLOCKD0 CHECK LOCK                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_boolean ten_xfi32x1_rxlockd0_lock(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Indicates if the SerDes is locked.                           */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_rxlockd0_intstatus;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if (slice == sl) {
      tmp_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTSTATUS));
      ret_val = ret_val & ((tmp_rxlockd0_intstatus.bf.FILT_LOCKs == 1) &
                           (tmp_rxlockd0_intstatus.bf.LOCKs == 1));
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 TXLOCKD0 CHECK FILT LOCK             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_boolean ten_xfi32x1_txlockd0_filt_lock(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Indicates status of FILT_LOCKs.                              */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_txlockd0_intstatus;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if (slice == sl) {
      tmp_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTSTATUS));
      ret_val = ret_val & (tmp_txlockd0_intstatus.bf.FILT_LOCKs == 1);
    }
  }
  return (ret_val);
}

/* Bugzilla 26403 Start */
/****************************************************************/
/* $rtn_hdr_start  XFI32X1 TXLOCKD0 CHECK FILT LOCK             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_boolean ten_xfi32x1_txlockd0_data_dets(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Current state of the "receive data detected" signal in       */
/* normal operation. (When tx to rx loopback is activated in    */
/* the digital core, this signal is forced to "1").             */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_txlockd0_intstatus;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTSTATUS));
      ret_val = ret_val & (tmp_txlockd0_intstatus.bf.DATA_DETs == 1);
    }
  }
  return (ret_val);
}
/* Bugzilla 26403 End */

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 RXLOCKD0 CHECK FILT LOCK             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_boolean ten_xfi32x1_rxlockd0_filt_lock(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Indicates status of FILT_LOCKs.                              */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_rxlockd0_intstatus;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if (slice == sl) {
      tmp_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTSTATUS));
      ret_val = ret_val & (tmp_rxlockd0_intstatus.bf.FILT_LOCKs == 1);
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 RXLOCKD0 CHECK DATA DETS             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_boolean ten_xfi32x1_rxlockd0_data_dets(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Indicates status of DATA_DETs.                               */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_rxlockd0_intstatus;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if (slice == sl) {
      tmp_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTSTATUS));
      ret_val = ret_val & (tmp_rxlockd0_intstatus.bf.DATA_DETs == 1);
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 RXVCO0 SET SHORT OVERRIDE CONTROL    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_xfi32x1_rxvco0_set_short_ovride(cs_uint16 module_id,
                                              cs_uint8 slice,  
                                              cs_uint16 short_ovride)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o SHORT OVRIDE                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Override control of the Coarse Tuner's "Filter Short" output,*/
/* SHORT_FILTPN. Either use SHORT_FILTPN directly from the      */
/* Coarse Tuner or else use the value contained in this         */
/* register.                                                    */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* The [short_ovride] parameter is specified as:                */
/*   2'b0x USE_CT_RESULT Use the SHORT_FILTPN output of the     */
/*         coarse tuner                                         */
/*   2'b10 FORCE_OFF Force SHORT_FILTPN output off              */
/*   2'b11 FORCE_ON Force                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXVCO0_CONTROL_t tmp_rxvco0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxvco0_control.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_CONTROL));
      tmp_rxvco0_control.bf.SHORT_OVRIDE = short_ovride;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_CONTROL), tmp_rxvco0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 TXVCO0 SET SHORT OVERRIDE CONTROL    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_xfi32x1_txvco0_set_short_ovride(cs_uint16 module_id,
                                              cs_uint8 slice,  
                                              cs_uint16 short_ovride)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o SHORT OVRIDE                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Override control of the Coarse Tuner's "Filter Short" output,*/
/* SHORT_FILTPN. Either use SHORT_FILTPN directly from the      */
/* Coarse Tuner or else use the value contained in this         */
/* register.                                                    */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* The [short_ovride] parameter is specified as:                */
/*   2'b0x USE_CT_RESULT Use the SHORT_FILTPN output of the     */
/*         coarse tuner                                         */
/*   2'b10 FORCE_OFF Force SHORT_FILTPN output off              */
/*   2'b11 FORCE_ON Force                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXVCO0_CONTROL_t tmp_txvco0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txvco0_control.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_CONTROL));
      tmp_txvco0_control.bf.SHORT_OVRIDE = short_ovride;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_CONTROL), tmp_txvco0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 RXLOCKD0 SET STABLE PERIOD           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_xfi32x1_rxlockd0_set_stable_period(cs_uint16 module_id,
                                                 cs_uint8 slice, 
                                                 cs_uint16 stable_period)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o STABLE PERIOD                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Controls the Lock Detect interrupt filter.                   */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* The [stable_period] parameter is specified as:               */
/*   0 - FF hex                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_FILTER_t tmp_rxlockd0_filter;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_filter.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_FILTER));
      tmp_rxlockd0_filter.bf.STABLE_PERIOD = stable_period;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_FILTER), tmp_rxlockd0_filter.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 TXLOCKD0 SET STABLE PERIOD           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_xfi32x1_txlockd0_set_stable_period(cs_uint16 module_id,
                                                 cs_uint8 slice, 
                                                 cs_uint16 stable_period)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o STABLE PERIOD                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Controls the Lock Detect interrupt filter.                   */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* The [stable_period] parameter is specified as:               */
/*   0 - FF hex                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXLOCKD0_FILTER_t tmp_txlockd0_filter;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txlockd0_filter.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_FILTER));
      tmp_txlockd0_filter.bf.STABLE_PERIOD = stable_period;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_FILTER), tmp_txlockd0_filter.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 GET VC0 TUNE INTSTATUS               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_boolean ten_xfi32x1_get_vco_tune_intstatus(cs_uint16 module_id,
                                              cs_uint8 slice,
                                              cs_dir_t dir)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Returns the Current state of the Coarse Tuning Algorithm's   */
/* "SHORT_FILTPN" output signal.                                */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_boolean ret_val;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }
  
  if (dir == CS_RX) {
    TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXVCO0_INTSTATUS_t tmp_rxvco0_intstatus;
    tmp_rxvco0_intstatus.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, RXVCO0_INTSTATUS));
    ret_val = (tmp_rxvco0_intstatus.bf.SHORT_FILTPNs == 1);
  }
  else if (dir == CS_TX) {
    TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXVCO0_INTSTATUS_t tmp_txvco0_intstatus;
    tmp_txvco0_intstatus.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, TXVCO0_INTSTATUS));
    ret_val = (tmp_txvco0_intstatus.bf.SHORT_FILTPNs == 1);
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dir out of range.  s/b 0..1");
    ret_val = FALSE;
  }

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 SET GRAM CONTROL REGISTER            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_xfi32x1_set_gram_cr(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 value)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Value                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* In combination with GRAM_D1 and GRAM_D0, this control        */
/* register provides indirect access to two storage areas and   */
/* six registers associated with the Microsequencer. The        */
/* storage areas are the program store and the data store. The  */
/* six registers are MS_STAT, MS_IMM, MS_A_OP, MS_B_OP, MS_ACC  */
/* and MS_RND. For read operations, first write the read        */
/* instruction and the indirect address to this register, then  */
/* read the data from the GRAM_D1 and GRAM_D0 registers. For    */
/* write operations, first write the data to the GRAM_D1 and    */
/* GRAM_D0 registers, then write the write instruction plus the */
/* indirect address to this register.                           */
/* Programming Notes:                                           */
/* 1. It is necessary to stall the Microsequencer by setting    */
/*    the OPTIONS.STALL bit before accessing the data store,    */
/*    the program store, or any of the six visible              */
/*    Microsequencer registers.                                 */
/* 2. MS_STAT, MS_IMM, MS_A_OP and MS_B_OP are read-only        */
/*    registers from the perspective of the external host.      */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   0x0000..0xFFFF,  a 16-bit concatenation of the bitfields   */
/*   within XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_CR                    */
/*                                                              */
/*   SEL[3:0] - Select the region to access:                    */
/*     4'h8 = USEQ_DATA_STORE_REGS Microsequencer Data Store or */
/*            Microsequencer Registers                          */
/*     4'h9 = USEQ_PROGRAM_STORE Microsequencer Program Store   */
/*                                                              */
/*   GRWN - Select Read (1) or Write (0) access.                */
/*                                                              */
/*   GRAM_A[10:0] - Address of the selected region              */
/*     SEL[3:0]*  GRAM_A[10:0]*  Width  Permissions  Region     */
/*     -------------------------------------------------------  */
/*       4'h8        0-63          32       R/W  Microsequencer */
/*                                               Data Store     */
/*       4'h8        1024          32       RO   Microsequencer */
/*                                               MS_STAT Reg    */
/*       4'h8        1025          32       R/W  Microsequencer */
/*                                               MS_ACC Reg     */
/*       4'h8        1026          32       R/W  Microsequencer */
/*                                               MS_RND Reg     */
/*       4'h8        1027          32       RO   Microsequencer */
/*                                               MS_IMM Reg     */
/*       4'h8        1028          32       RO   Microsequencer */
/*                                               MS_A_OP Reg    */
/*       4'h8        1029          32       RO   Microsequencer */
/*                                               MS_B_OP Reg    */
/*       4'h9        0-511         24       R/W  Microsequencer */
/*                                               Program Store  */
/*     * Invalid combinations of SEL[3:0] or GRAM_A[10:0]       */
/*       should not be attempted.                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_CR_t tmp_gram_cr;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gram_cr.wrd = TEN_REG_READ(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, GRAM_CR));
      tmp_gram_cr.wrd = value;
      TEN_REG_WRITE(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, GRAM_CR), tmp_gram_cr.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 GET GRAM CONTROL REGISTER            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_int16 ten_xfi32x1_get_gram_cr(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0x0000..0xFFFF                                  */
/* DESCRIPTION:                                                 */
/* In combination with GRAM_D1 and GRAM_D0, this control        */
/* register provides indirect access to two storage areas and   */
/* six registers associated with the Microsequencer. The        */
/* storage areas are the program store and the data store. The  */
/* six registers are MS_STAT, MS_IMM, MS_A_OP, MS_B_OP, MS_ACC  */
/* and MS_RND. For read operations, first write the read        */
/* instruction and the indirect address to this register, then  */
/* read the data from the GRAM_D1 and GRAM_D0 registers. For    */
/* write operations, first write the data to the GRAM_D1 and    */
/* GRAM_D0 registers, then write the write instruction plus the */
/* indirect address to this register.                           */
/* Programming Notes:                                           */
/* 1. It is necessary to stall the Microsequencer by setting    */
/*    the OPTIONS.STALL bit before accessing the data store,    */
/*    the program store, or any of the six visible              */
/*    Microsequencer registers.                                 */
/* 2. MS_STAT, MS_IMM, MS_A_OP and MS_B_OP are read-only        */
/*    registers from the perspective of the external host.      */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/* The value returned is specified as:                          */
/*   0x0000..0xFFFF,  a 16-bit concatenation of the bitfields   */
/*   within XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_CR                    */
/*                                                              */
/*   SEL[3:0] - Select the region to access:                    */
/*     4'h8 = USEQ_DATA_STORE_REGS Microsequencer Data Store or */
/*            Microsequencer Registers                          */
/*     4'h9 = USEQ_PROGRAM_STORE Microsequencer Program Store   */
/*                                                              */
/*   GRWN - Select Read (1) or Write (0) access.                */
/*                                                              */
/*   GRAM_A[10:0] - Address of the selected region              */
/*     SEL[3:0]*  GRAM_A[10:0]*  Width  Permissions  Region     */
/*     -------------------------------------------------------  */
/*       4'h8        0-63          32       R/W  Microsequencer */
/*                                               Data Store     */
/*       4'h8        1024          32       RO   Microsequencer */
/*                                               MS_STAT Reg    */
/*       4'h8        1025          32       R/W  Microsequencer */
/*                                               MS_ACC Reg     */
/*       4'h8        1026          32       R/W  Microsequencer */
/*                                               MS_RND Reg     */
/*       4'h8        1027          32       RO   Microsequencer */
/*                                               MS_IMM Reg     */
/*       4'h8        1028          32       RO   Microsequencer */
/*                                               MS_A_OP Reg    */
/*       4'h8        1029          32       RO   Microsequencer */
/*                                               MS_B_OP Reg    */
/*       4'h9        0-511         24       R/W  Microsequencer */
/*                                               Program Store  */
/*     * Invalid combinations of SEL[3:0] or GRAM_A[10:0]       */
/*       should not be attempted.                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_CR_t tmp_gram_cr;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_gram_cr.wrd = TEN_REG_READ(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, slice, GRAM_CR));

  return (tmp_gram_cr.wrd);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 SET GRAM DATA REGISTER 1             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_xfi32x1_set_gram_d1(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 gram_d1)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o GRAM D1                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register contains data bits [31:16] for indirect        */
/* accesses activated through GRAM_CR.                          */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/*   [gram_d1] Specified as:                                    */
/*      0x0000..0xFFFF                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_D1_t tmp_gram_d1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gram_d1.wrd = TEN_REG_READ(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, GRAM_D1));
      tmp_gram_d1.bf.GRAM_D1 = gram_d1;
      TEN_REG_WRITE(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, GRAM_D1), tmp_gram_d1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 GET GRAM DATA REGISTER 1             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_int16 ten_xfi32x1_get_gram_d1(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0x0000..0xFFFF                                  */
/* DESCRIPTION:                                                 */
/* This register contains data bits [31:16] for indirect        */
/* accesses activated through GRAM_CR.                          */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_D1_t tmp_gram_d1;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_gram_d1.wrd = TEN_REG_READ(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, slice, GRAM_D1));

  return (tmp_gram_d1.wrd);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 SET GRAM DATA REGISTER 0             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_xfi32x1_set_gram_d0(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 gram_d0)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o GRAM D0                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register contains data bits [15:0] for indirect         */
/* accesses activated through GRAM_CR.                          */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/*   [gram_d0] Specified as:                                    */
/*      0x0000..0xFFFF                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_D0_t tmp_gram_d0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gram_d0.wrd = TEN_REG_READ(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, GRAM_D0));
      tmp_gram_d0.bf.GRAM_D0 = gram_d0;
      TEN_REG_WRITE(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, GRAM_D0), tmp_gram_d0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 GET GRAM DATA REGISTER 0             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_int16 ten_xfi32x1_get_gram_d0(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0x0000..0xFFFF                                  */
/* DESCRIPTION:                                                 */
/* This register contains data bits [15:0] for indirect         */
/* accesses activated through GRAM_CR.                          */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_D0_t tmp_gram_d0;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_gram_d0.wrd = TEN_REG_READ(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, slice, GRAM_D0));

  return (tmp_gram_d0.wrd);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 BIT INVERSION                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_xfi32x1_bit_invert(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint8 invert)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Invert                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Invert the bit polatity of all TX data bits                  */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/*   [invert] specifies whether or not to invert TX data bits   */
/*     0 = Do not invert                                        */
/*     1 = Invert                                               */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TX0_Config_t tmp_tx0_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if(invert > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": invert out of range  s/b 0..1.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_tx0_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TX0_Config));
      tmp_tx0_config.bf.bitinv = invert;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TX0_Config), tmp_tx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XFI32X1 INVERSION                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XFI32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_xfi32x1_invert(cs_uint16 module_id,
                            cs_uint8 slice, 
                            cs_dir_t dir, 
                            cs_uint8 invert)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Invert                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Invert the bit polarity of all TX/RX data bits.              */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [invert] specifies whether or not to invert data bits:   */
/*   0 = Do not invert                                          */
/*   1 = Invert.                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TX0_Config_t tmp_tx0_config;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RX0_Config_t tmp_rx0_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dir out of range.  s/b 0..2.");
    return(CS_ERROR); 
  }
  if(invert > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": invert out of range  s/b 0..1.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        tmp_tx0_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TX0_Config));
        tmp_tx0_config.bf.bitinv = invert;
        TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TX0_Config), tmp_tx0_config.wrd);
      }
      if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        tmp_rx0_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RX0_Config));
        tmp_rx0_config.bf.bitinv = invert;
        TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RX0_Config), tmp_rx0_config.wrd);
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 SRX0 RX CLKOUT CTRL CLKINVEN             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_srx0_rx_clkout_ctrl_clkinven(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 srx_clkinven)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX CLKINVEN                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive clock outputs.                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_clkinven]  Invert SRX_CLK clock to digital core:          */
/*     0 = non inverted                                             */
/*     1 = inverted.                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_t tmp_srx0_rx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKOUT_CTRL));
      tmp_srx0_rx_clkout_ctrl.bf.SRX_CLKINVEN = srx_clkinven;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKOUT_CTRL), tmp_srx0_rx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 SET RXLOCKD0 FORCE LOCK                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_set_rxlockd0_force_lock(cs_uint16 module_id,
                                              cs_uint8 slice, 
                                              cs_uint16 pd_mode, 
                                              cs_uint16 force_lock)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PD MODE                                           */
/*              o FORCE LOCK                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Clock and Data Recovery (CDR) Lock Detector Control Register.    */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [pd_mode] parameter is specified as:                         */
/*   0..1, Force the lock state to the value "PD_MODE" when         */
/*   FORCE_LOCK is asserted.                                        */
/*                                                                  */
/* The [force_lock] parameter is specified as:                      */
/*   0..1, Force the lock state to the value "PD_MODE" when         */
/*   FORCE_LOCK is asserted.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_rxlockd0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_control.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_CONTROL));
      tmp_rxlockd0_control.bf.PD_MODE = pd_mode;
      tmp_rxlockd0_control.bf.FORCE_LOCK = force_lock;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_CONTROL), tmp_rxlockd0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX PWRDN ALL LANES                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_pwrdn_all(cs_uint16 module_id,
                                         cs_uint8 slice, 
                                         cs_uint16 stxp_pd)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP PD                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_pd]  Power down the entire transmit section              */
/*     0 = powered                                                  */
/*     1 = powered down                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_PWRDN_t tmp_stxp0_tx_pwrdn;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_pwrdn.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_PWRDN));
      tmp_stxp0_tx_pwrdn.bf.STXP_PD = stxp_pd;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_PWRDN), tmp_stxp0_tx_pwrdn.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 TXVCO0 CONTROL INIT                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_txvco0_control_init(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls when the VCO Coarse Tuning Algorithm is re-initialized  */
/* and starts searching for the correct frequency range again.      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act] parameter is specified as:                               */
/*   Reset option specified as CS_RESET_DEASSERT,                   */
/*   CS_RESET_ASSERT or CS_RESET_TOGGLE.                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset bit(s) for 20 milliseconds and then de-assert.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXVCO0_CONTROL_t tmp_txvco0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": act = 0x%04X\n", act);
      return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txvco0_control.wrd = 0;
      tmp_txvco0_control.bf.INIT = 1;
      ten_reset_action(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_CONTROL),
                       tmp_txvco0_control.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 RXVCO0 CONTROL INIT                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_rxvco0_control_init(cs_uint16 module_id, cs_uint8 slice,
                                          cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls when the VCO Coarse Tuning Algorithm is re-initialized  */
/* and starts searching for the correct frequency range again.      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act] parameter is specified as:                               */
/*   Reset option specified as CS_RESET_DEASSERT,                   */
/*   CS_RESET_ASSERT or CS_RESET_TOGGLE.                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset bit(s) for 20 milliseconds and then de-assert.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXVCO0_CONTROL_t tmp_rxvco0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
 
  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": act = 0x%04X\n", act);
      return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxvco0_control.wrd = 0;
      tmp_rxvco0_control.bf.INIT = 1;
      ten_reset_action(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_CONTROL), 
                       tmp_rxvco0_control.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 TXVCO0 STATUS                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_xfi32x1_txvco0_status(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : FREQ value                                          */
/* DESCRIPTION:                                                     */
/* Returns the frequency range selected by the Coarse Tuning        */
/* Algorithm.                                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), or TEN_SLICE3 (3).                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXVCO0_STATUS_t tmp_txvco0_status;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_txvco0_status.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, TXVCO0_STATUS));
  return (tmp_txvco0_status.bf.FREQ);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 RXVCO0 STATUS                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_xfi32x1_rxvco0_status(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : FREQ Value                                          */
/* DESCRIPTION:                                                     */
/* Returns the frequency range selected by the Coarse Tuning        */
/* Algorithm.                                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3).                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXVCO0_STATUS_t tmp_rxvco0_status;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_rxvco0_status.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, RXVCO0_STATUS));
  return (tmp_rxvco0_status.bf.FREQ);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 RXVCO0 THRESHOLD                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_rxvco0_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 thres0, cs_uint16 thres1)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o THRES0                                            */
/*              o THRES1                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets thresholds used by the VCO Coarse Tuning Algorithm to       */
/* decide if the VCO 0/1 is in the correct frequency range.         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [thres0]  threshold 0                                          */
/*                                                                  */
/*   [thres1]  threshold 1.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_THRES0), thres0);
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_THRES1), thres1);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 TXVCO0 THRESHOLD                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_txvco0_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_uint16 thres0, cs_uint16 thres1)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o THRES0                                            */
/*              o THRES1                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets thresholds used by the VCO Coarse Tuning Algorithm to       */
/* decide if the VCO 0/1 is in the correct frequency range.         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [thres0]  threshold 0                                          */
/*                                                                  */
/*   [thres1]  threshold 1.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_THRES0), thres0);
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_THRES1), thres1);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 RXVCO0 CONTROL                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_rxvco0_control(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 control)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the VCO Coarse Tuning Algorithm and  */
/* its outputs.                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [control]  Control Value.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_CONTROL), control);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 TXVCO0 CONTROL                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_txvco0_control(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 control)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the VCO Coarse Tuning Algorithm and  */
/* its outputs.                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [control]  Control Value.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_CONTROL), control);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX SFI52 CLK REF OUT EN T41        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_sfi52_clkrefouten_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                     cs_uint16 stxp_sfi5p2_clkrefouten)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP SFI5P2 CLKREFOUTEN                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_sfi5p2_clkrefouten]                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SFI52_t tmp_stxp0_tx_sfi52;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_sfi52.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52));
      tmp_stxp0_tx_sfi52.bf.STXP_SFI5P2_CLKREFOUTEN = stxp_sfi5p2_clkrefouten;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52), tmp_stxp0_tx_sfi52.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX SFI52 PILOT OUT EN T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_sfi52_pilotouten_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_sfi5p2_pilotouten)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP SFI5P2 PILOTOUTEN                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_sfi5p2_pilotouten]                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SFI52_t tmp_stxp0_tx_sfi52;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_sfi52.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52));
      tmp_stxp0_tx_sfi52.bf.STXP_SFI5P2_PILOTOUTEN = stxp_sfi5p2_pilotouten;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52), tmp_stxp0_tx_sfi52.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX SFI52 CLK REF OUT SEL T41       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_sfi52_clkrefout_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                       cs_uint16 stxp_sfi5p2_clkrefout_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP SFI5P2 CLKREFOUT SEL                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_sfi5p2_clkrefout_sel]                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SFI52_t tmp_stxp0_tx_sfi52;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_sfi52.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52));
      tmp_stxp0_tx_sfi52.bf.STXP_SFI5P2_CLKREFOUT_SEL = stxp_sfi5p2_clkrefout_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52), tmp_stxp0_tx_sfi52.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX SFI52 CLK REF OUT DIV SEL T41   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_sfi52_clkrefout_div_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                           cs_uint16 stxp_sfi5p2_clkrefout_div_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP SFI5P2 CLKREFOUT DIV SEL                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_sfi5p2_clkrefout_div_sel]                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SFI52_t tmp_stxp0_tx_sfi52;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_sfi52.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52));
      tmp_stxp0_tx_sfi52.bf.STXP_SFI5P2_CLKREFOUT_DIV_SEL = stxp_sfi5p2_clkrefout_div_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52), tmp_stxp0_tx_sfi52.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX SFI52 PILOT OUT SEL T41         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_sfi52_pilotout_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                      cs_uint16 stxp_sfi5p2_pilotout_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP SFI5P2 PILOTOUT SEL                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_sfi5p2_pilotout_sel]                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SFI52_t tmp_stxp0_tx_sfi52;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_sfi52.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52));
      tmp_stxp0_tx_sfi52.bf.STXP_SFI5P2_PILOTOUT_SEL = stxp_sfi5p2_pilotout_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52), tmp_stxp0_tx_sfi52.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX SFI52 PILOT OUT DIV SEL T41     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_sfi52_pilotout_div_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                          cs_uint16 stxp_sfi5p2_pilotout_div_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP SFI5P2 PILOTOUT DIV SEL                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_sfi5p2_pilotout_div_sel]                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SFI52_t tmp_stxp0_tx_sfi52;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_sfi52.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52));
      tmp_stxp0_tx_sfi52.bf.STXP_SFI5P2_PILOTOUT_DIV_SEL = stxp_sfi5p2_pilotout_div_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SFI52), tmp_stxp0_tx_sfi52.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 GRO CTRL REF CLK SEL T41           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_gro_ctrl_refclk_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_gro_refclk_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP GRO REFCLK SEL                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_gro_refclk_sel]                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_GRO_CTRL_t tmp_stxp0_gro_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_gro_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_CTRL));
      tmp_stxp0_gro_ctrl.bf.STXP_GRO_REFCLK_SEL = stxp_gro_refclk_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_CTRL), tmp_stxp0_gro_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 GRO CTRL CLK INV EN T41            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_gro_ctrl_clkinven_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                  cs_uint16 stxp_gro_clkinven)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP GRO CLKINVEN                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_gro_clkinven]                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_GRO_CTRL_t tmp_stxp0_gro_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_gro_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_CTRL));
      tmp_stxp0_gro_ctrl.bf.STXP_GRO_CLKINVEN = stxp_gro_clkinven;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_CTRL), tmp_stxp0_gro_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 GRO CTRL MODE T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_gro_ctrl_mode_t41(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 stxp_gro_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP GRO MODE                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_gro_mode]                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_GRO_CTRL_t tmp_stxp0_gro_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_gro_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_CTRL));
      tmp_stxp0_gro_ctrl.bf.STXP_GRO_MODE = stxp_gro_mode;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_CTRL), tmp_stxp0_gro_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 GRO CTRL PD T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_gro_ctrl_pd_t41(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 stxp_gro_pd)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP GRO PD                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_gro_pd]                                                  */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_GRO_CTRL_t tmp_stxp0_gro_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_gro_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_CTRL));
      tmp_stxp0_gro_ctrl.bf.STXP_GRO_PD = stxp_gro_pd;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_CTRL), tmp_stxp0_gro_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 GRO DIV CTRL REF CLK DIV SEL T41   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_gro_div_ctrl_refclk_div_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                            cs_uint16 stxp_gro_refclk_div_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP GRO REFCLK DIV SEL                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_gro_refclk_div_sel]                                      */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_GRO_DIV_CTRL_t tmp_stxp0_gro_div_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_gro_div_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_DIV_CTRL));
      tmp_stxp0_gro_div_ctrl.bf.STXP_GRO_REFCLK_DIV_SEL = stxp_gro_refclk_div_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_DIV_CTRL), tmp_stxp0_gro_div_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 GRO DIV CTRL CLK DIV SEL T41       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_gro_div_ctrl_clk_div_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                         cs_uint16 stxp_gro_clk_div_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP GRO CLK DIV SEL                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_gro_clk_div_sel]                                         */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_GRO_DIV_CTRL_t tmp_stxp0_gro_div_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_gro_div_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_DIV_CTRL));
      tmp_stxp0_gro_div_ctrl.bf.STXP_GRO_CLK_DIV_SEL = stxp_gro_clk_div_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_GRO_DIV_CTRL), tmp_stxp0_gro_div_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 FRAC CTRL FILT TUNE T41            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_frac_ctrl_filt_tune_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_frac_filttune2, 
                                                    cs_uint16 stxp_frac_filttune1)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP FRAC FILTTUNE2                               */
/*              o STXP FRAC FILTTUNE1                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_frac_filttune2]                                          */
/*                                                                  */
/*   [stxp_frac_filttune1]                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_FRAC_CTRL_t tmp_stxp0_frac_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_frac_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_FRAC_CTRL));
      tmp_stxp0_frac_ctrl.bf.STXP_FRAC_FILTTUNE2 = stxp_frac_filttune2;
      tmp_stxp0_frac_ctrl.bf.STXP_FRAC_FILTTUNE1 = stxp_frac_filttune1;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_FRAC_CTRL), tmp_stxp0_frac_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 FRAC CTRL FRAC FILT EN T41         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_frac_ctrl_frac_filten_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                      cs_uint16 stxp_frac_filten)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP FRAC FILTEN                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_frac_filten]                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_FRAC_CTRL_t tmp_stxp0_frac_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_frac_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_FRAC_CTRL));
      tmp_stxp0_frac_ctrl.bf.STXP_FRAC_FILTEN = stxp_frac_filten;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_FRAC_CTRL), tmp_stxp0_frac_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 FRAC CTRL MMD CLK INV EN T41       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_frac_ctrl_mmd_clkinven_t41(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 stxp_mmd_clkinven)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP MMD CLKINVEN                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_mmd_clkinven]                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_FRAC_CTRL_t tmp_stxp0_frac_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_frac_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_FRAC_CTRL));
      tmp_stxp0_frac_ctrl.bf.STXP_MMD_CLKINVEN = stxp_mmd_clkinven;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_FRAC_CTRL), tmp_stxp0_frac_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 FRAC CTRL MMD INV EN T41           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_frac_ctrl_mmd_inv_en_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                     cs_uint16 stxp_mmd_inven)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP MMD INVEN                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_mmd_inven]                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_FRAC_CTRL_t tmp_stxp0_frac_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_frac_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_FRAC_CTRL));
      tmp_stxp0_frac_ctrl.bf.STXP_MMD_INVEN = stxp_mmd_inven;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_FRAC_CTRL), tmp_stxp0_frac_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 FRAC CTRL FRAC EN T41              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_frac_ctrl_frac_en_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                  cs_uint16 stxp_frac_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP FRAC EN                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_frac_en]                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_FRAC_CTRL_t tmp_stxp0_frac_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_frac_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_FRAC_CTRL));
      tmp_stxp0_frac_ctrl.bf.STXP_FRAC_EN = stxp_frac_en;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_FRAC_CTRL), tmp_stxp0_frac_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/* Bugzilla 26403 Start */
/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CLKOUT CTRL CLKOUTEN            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_clkout_ctrl_clkouten(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_clkouten)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP CLKOUTEN                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit clock outputs.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_clkouten]                                                */
/*     Test clock output enable:                                    */
/*     0 = test clock disabled                                      */
/*     1 = test clock enabled.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xfi32x1_stxp0_tx_clkout_ctrl_clkouten";  

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3.", func);
    return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s() %s, TEN_SLICE_ALL, stxp_clkouten=%d\n", func, ten_module_strings[module_id & 1], stxp_clkouten);
  } else {
    CS_PRINT("%s() %s, %s, stxp_clkouten=%d\n", func, ten_module_strings[module_id & 1], ten_slice_strings[slice], stxp_clkouten);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL));
      tmp_stxp0_tx_clkout_ctrl.bf.STXP_CLKOUTEN = stxp_clkouten;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL), tmp_stxp0_tx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX CLKOUT CTRL TCLK0 SEL           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_clkout_ctrl_tclko_sel(cs_uint16 module_id, cs_uint8 slice, 
                                                     cs_uint16 stxp_tclko_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP TCLKO SEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit clock outputs.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_tclko_sel]                                               */
/*     Select clock to be sent on STXP_TCLKOP/N:                    */
/*     000000 = div16                                               */
/*     000001 = div32                                               */
/*     000010 = div64                                               */
/*     000011 = div66                                               */
/*     000100 = div40                                               */
/*     000101 = div80                                               */
/*     000110 = STXP_PILOT                                          */
/*     01xxxx = reserved                                            */
/*     1001xx = Data Path Divider Output.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xfi32x1_stxp0_tx_clkout_ctrl_clkouten";  

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  slice out of range.  s/b 0..3.", func);
    return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s() %s, TEN_SLICE_ALL, stxp_tclko_sel=%d\n", func, ten_module_strings[module_id & 1], stxp_tclko_sel);
  } else {
    CS_PRINT("%s() %s, %s, stxp_tclko_sel=%d\n", func, ten_module_strings[module_id & 1], ten_slice_strings[slice], stxp_tclko_sel);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL));
      tmp_stxp0_tx_clkout_ctrl.bf.STXP_TCLKO_SEL = stxp_tclko_sel;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL), tmp_stxp0_tx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}
/* Bugzilla 26403 End */

/* Bugzilla 26403 Start */
/********************************************************************/
/* $rtn_hdr_start  XFI32X1 RX0 GET PRBSCK0 COUNT                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint32 ten_xfi32x1_rx0_get_prbsck0_count (cs_uint16 module_id, cs_uint8 slice) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Get XFI32X1 SDS Common PRBS Count                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint32 count;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK0_Count0_t tmp_prbschk0_count0_t;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK0_Count1_t tmp_prbschk0_count1_t;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xfi32x1_rx0_get_prbsck0_count";  

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3.", func);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s\n", func, ten_module_strings[module_id & 1], ten_slice_strings[slice]);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  tmp_prbschk0_count1_t.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, PRBSCHK0_Count1));
  tmp_prbschk0_count0_t.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, PRBSCHK0_Count0));

  count = (tmp_prbschk0_count0_t.wrd) | (tmp_prbschk0_count1_t.wrd << 16);

  CS_PRINT("%s() count = 0x%X\n", func, count);

  return (count);
}
/* Bugzilla 26403 End */



/********************************************************************/
/* $rtn_hdr_start  HSIF XFI CHECK LOCK0                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_xfi_check_lockd0 (cs_uint16 module_id, 
                                     cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Checkes status of XFI HSIF lockd0                                */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_INTERRUPT_t tmp_rxlockd0_interrupt;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXLOCKD0_INTERRUPT_t tmp_txlockd0_interrupt;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hsif_xfi_check_lockd0";  

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%S() slice out of range.  s/b 0..3 or 0xFF.", func);
    return (CS_ERROR);
  }
  
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s() SLICE_ALL\n", func);
  } else {  
    CS_PRINT("%s(), %s\n", func, ten_slice_strings[slice]);
  }  

  /* Set bits to clear interrupts */
  tmp_rxlockd0_interrupt.bf.LOCKi = 1;
  tmp_rxlockd0_interrupt.bf.DATA_DETi = 1;
  tmp_rxlockd0_interrupt.bf.FILT_LOCKi = 1;

  tmp_txlockd0_interrupt.bf.LOCKi = 1;
  tmp_txlockd0_interrupt.bf.DATA_DETi = 1;
  tmp_txlockd0_interrupt.bf.FILT_LOCKi = 1;


  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      /* Clear interrupts */
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTERRUPT), tmp_rxlockd0_interrupt.wrd);
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTERRUPT), tmp_txlockd0_interrupt.wrd);

      /* FILT_LOCKs and LOCKs */
      if (ten_xfi32x1_txlockd0_lock (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s TX not locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_xfi32x1_txlockd0_filt_lock (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s TX not filt locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_xfi32x1_txlockd0_data_dets (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s TX data not detected!\n", func, ten_slice_strings[sl]);
      }    

      if (ten_xfi32x1_rxlockd0_lock (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s RX not locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_xfi32x1_rxlockd0_filt_lock (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s RX not filt locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_xfi32x1_rxlockd0_data_dets (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s RX data not detected!\n", func, ten_slice_strings[sl]);
      }
    }
  }
  
  /* Bugzilla #28471, minimum delay */
  TEN_MDELAY(20);
  
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_interrupt.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTERRUPT));
      if (tmp_rxlockd0_interrupt.bf.LOCKi) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s Change in the RX Lock Detector lock state!\n", func, ten_slice_strings[sl]);
      }
      if (tmp_rxlockd0_interrupt.bf.DATA_DETi) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s Change in the RX receive data detected signal!\n", func, ten_slice_strings[sl]);
      }
      if (tmp_rxlockd0_interrupt.bf.FILT_LOCKi) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s Change in the RX filtered lock state. Filtered lock declared lock after the lock status is stable!\n", func, ten_slice_strings[sl]);
      }
      
      tmp_txlockd0_interrupt.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTERRUPT));
      if (tmp_txlockd0_interrupt.bf.LOCKi) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s Change in the TX Lock Detector lock state!\n", func, ten_slice_strings[sl]);
      }
      if (tmp_txlockd0_interrupt.bf.DATA_DETi) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s Change in the TX receive data detected signal!\n", func, ten_slice_strings[sl]);
      }
      if (tmp_txlockd0_interrupt.bf.FILT_LOCKi) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() %s Change in the TX filtered lock state. Filtered lock declared lock after the lock status is stable!\n", func, ten_slice_strings[sl]);
      }
    }
  }
  
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 RXELST0 CONTROL RESYNC                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_rxelst0_control_resync(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 resync)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Resync                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control XFI RX resync.                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [resync]                                                       */
/*     When set, this bit forces a resync of the elastic store      */
/*     read pointers (datapath/loopback).  Must be cleared to 0     */
/*     to resume dataflow.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXELST0_Control_t tmp_rxelst0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxelst0_control.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXELST0_Control));
      tmp_rxelst0_control.bf.resync = resync;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RXELST0_Control), tmp_rxelst0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 TXELST0 CONTROL                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_txelst0_control_resync(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 resync)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Resync                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control XFI TX resync.                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [resync]                                                       */
/*     When set, this bit forces a resync of the elastic store      */
/*     read pointers (datapath/loopback).  Must be cleared to 0     */
/*     to resume dataflow.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXELST0_Control_t tmp_txelst0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txelst0_control.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXELST0_Control));
      tmp_txelst0_control.bf.resync = resync;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TXELST0_Control), tmp_txelst0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}



/********************************************************************/
/* Function: ten_get_xfi_cupll_inst_reg_addr                        */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a xfi_cupll register.                        */
/*                                                                  */
/* Used by macro TEN_XFI_CUPLL_REG_ADDR. Given the base address     */
/* of a non-common cupll register as defined in t41_registers.h,    */
/* and its instance number (0-TEN_XFI_CUPLL_COUNT), calcuates       */
/* the offset and adds it to the base register's address.           */
/********************************************************************/
volatile cs_reg *ten_get_xfi_cupll_inst_reg_addr( cs_reg   *pReg,
                                                  cs_uint16 instance )
{
  if (instance >= TEN_XFI_CUPLL_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "xfi_cupll instance %d out of range. S/b < TEN_XFI_CUPLL_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_XFI_CUPLL_STRIDE);
}

/********************************************************************/
/* Function: ten_get_xfi_cfp32x1_inst_reg_addr                      */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a cfp32x1_sds register.                      */
/*                                                                  */
/* Used by macro TEN_CFP32X1_REG_ADDR. Given the base address       */
/* of a cfp32x1_sds register as defined in t41_registers.h,         */
/* and its instance number (0-TEN_CFP32X1_SDS_COUNT), calcuates     */
/* the offset and adds it to the base register's address.           */
/********************************************************************/
volatile cs_reg *ten_get_xfi_cfp32x1_inst_reg_addr( cs_reg   *pReg,
                                                   cs_uint16 instance )
{
  if (instance >= TEN_CFP32X1_SDS_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "cfp32x1_sds instance %d out of range. S/b < TEN_CFP32X1_SDS_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_CFP32X1_SDS_STRIDE);
}


/********************************************************************/
/* Function: ten_get_xfi32x1_inst_reg_addr()                        */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a xfi32x1_sds register.                      */
/*                                                                  */
/* Used by macro TEN_XFI32X1_REG_ADDR. Given the base address       */
/* of a xfi32x1_sds register as defined in t41_registers.h,         */
/* and its instance number (0-TEN_XFI32X1_SDS_COUNT), calcuates     */
/* the offset and adds it to the base register's address.           */
/********************************************************************/
volatile cs_reg *ten_get_xfi32x1_inst_reg_addr( cs_reg  *pReg,
                                               cs_uint16 instance )
{
  if (instance >= TEN_XFI32X1_SDS_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "xfi32x1_sds instance %d out of range. S/b < TEN_XFI32X1_SDS_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_XFI32X1_SDS_STRIDE);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 GET STXP0 FRAC CTRL FRAC EN              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_xfi32x1_get_stxp0_frac_ctrl_frac_en(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : STXP FRAC EN                                        */
/* DESCRIPTION:                                                     */
/* Returns  STXP FRAC EN.                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_FRAC_CTRL_t tmp_stxp0_frac_ctrl;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  
  /* Bug #37958 - Bus errors occur in T40 but not T41 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    tmp_stxp0_frac_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_FRAC_CTRL));
    return (tmp_stxp0_frac_ctrl.bf.STXP_FRAC_EN);
  }
  else {
    return (0);
  }
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 MSEQCLKCTRL                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_mseqclkctrl_entiremspowerup(cs_uint16 module_id, cs_uint8 slice, 
                                                  cs_uint16 entiremspowerup)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o EntireMSPowerUp                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the Microsequencer clock branches.                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [entiremspowerup]                                              */
/*     When set to 1'b1 all the Microsequencer clock branches are   */
/*     turned on.  This bit overrides any other                     */
/*     (Microsequencer clock )related bits in the design.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_XFI32X1_SDS_SDS_DSP_DSP_MSEQCLKCTRL_t tmp_mseqclkctrl;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mseqclkctrl.wrd = TEN_REG_READ(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, MSEQCLKCTRL));
      tmp_mseqclkctrl.bf.entireMSPowerUp = entiremspowerup;
      TEN_REG_WRITE(TEN_XFI32X1_DSP_REG_ADDR(pDev, module_id, sl, MSEQCLKCTRL), tmp_mseqclkctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI32X1 STXP0 TX POWER DOWN PD LANE              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi32x1_stxp0_tx_pwrdn_pd_lane(cs_uint16 module_id, 
                                             cs_uint8 slice, 
                                             cs_uint16 stxp_pd_lane)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP PD LANE                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Power down individual lanes on the transmit section.             */
/* There are 5 lanes bitmapped with bits 0-5.                       */
/* To power down all lanes, use stxp_pd_lane = 0x1F,                */
/* To power up all lanes, use use stxp_pd_lane = 0                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_pd_lane]                                                 */
/*     0 = lane N powered                                           */
/*     1 = lane N powered down                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_PWRDN_t tmp_stxp0_tx_pwrdn;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_XFI32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_pwrdn.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_PWRDN));
      tmp_stxp0_tx_pwrdn.bf.STXP_PD_LANE = stxp_pd_lane;
      TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_PWRDN), tmp_stxp0_tx_pwrdn.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_XFI32X1);

  return (CS_OK);
}

