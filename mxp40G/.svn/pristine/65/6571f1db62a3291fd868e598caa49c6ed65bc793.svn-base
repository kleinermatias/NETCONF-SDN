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
 * ten_fec40g.c
 *
 * FEC40G related code is implemented here.
 *
 * $Id: ten_ufec.c,v 1.20 2013/02/22 20:48:57 jccarlis Exp $
 *
 */

#include "tenabo40.h"


typedef struct {
  cs_uint16 configA0;
  cs_uint16 configA1;
  cs_uint16 configA2;
  cs_uint16 configA3;
  cs_uint16 configA4;
  cs_uint16 configA5;
  cs_uint16 configA6;
  cs_uint16 configA7;
  cs_uint16 configB;
  cs_uint16 configB0;
  cs_uint16 configC0;
  cs_uint16 configC1;
} ten_coder_settings_t; 

/* Datasheet, revision 1.0, Table 35 Ultra-FEC Decoder Configuration examples */
const static ten_coder_settings_t dec_val[TEN_FEC_MODE_MAX_NUM] = { /* RX */
  /* Fixed Stuff Insertion Optional */
  /* A0      A1      A2      A3      A4      A5      A6      A7      B       B0      C0      C1    */
  {0x2EF0, 0x00FF, 0x47A0, 0x0670, 0x21F4, 0x0384, 0x32C4, 0x2C23, 0x010B, 0x07FF, 0x01C7, 0x0079},
  {0x2EF0, 0x0106, 0x41A0, 0x0B28, 0x29FE, 0x03C0, 0x3140, 0x2960, 0x010B, 0x07FF, 0x01CE, 0x0170},
  {0x2EF0, 0x0111, 0x45E0, 0x0AD0, 0x49F4, 0x03FC, 0x3258, 0x2BE9, 0x010B, 0x07FF, 0x01D5, 0x00E2}, /* Bugzilla 22317 */
  {0x2EF0, 0x011D, 0x41A0, 0x0F28, 0x51FE, 0x039C, 0x3148, 0x2961, 0x010B, 0x07FF, 0x0138, 0x0061},
  {0x2EF0, 0x0129, 0x41A0, 0x1328, 0x59FE, 0x0374, 0x3150, 0x294D, 0x010B, 0x07FF, 0x0128, 0x005B},
  {0x2F20, 0x012C, 0x40A0, 0x1330, 0x59EA, 0x0398, 0x310E, 0x28F0, 0x010B, 0x07FF, 0x0124, 0x00CB}, /* Bugzilla 22317 */
  {0x2EF0, 0x012D, 0x44A0, 0x1680, 0x59E0, 0x03D8, 0x3108, 0x292C, 0x010B, 0x07FF, 0x0134, 0x01DB},
  /* Minimum of 16x Fixed Stuff columns Insertion Enabled */
  {0x4EF0, 0x00FF, 0x4580, 0x064F, 0x29FE, 0x03FC, 0x3240, 0x2BA5, 0x010B, 0x07FF, 0x0000, 0x0000}, /* Bugzilla 22317 */
  /* 32x Fixed Stuff columns Insertion Enabled */
  {0x4ee0, 0x00ff, 0x4720, 0x0658, 0x29e0, 0x03cc, 0x3183, 0x29f5, 0x010b, 0x07ff, 0x01a3, 0x0171},
  /* Fixed Stuff Insertion Disabled */
  {0x2F69, 0x00FF, 0x44E0, 0x0760, 0x09B0, 0x0344, 0x2FE0, 0x2605, 0x010B, 0x07FF, 0x011A, 0x0079},
  {0x2F4C, 0x00FF, 0x45A0, 0x064F, 0x11FE, 0x0384, 0x3240, 0x2B11, 0x010B, 0x07FF, 0x01AC, 0x00F5},
  {0x2ef0, 0x010b, 0x45e0, 0x0ad0, 0x39f4, 0x03fc, 0x3258, 0x2bdf, 0x010b, 0x07ff, 0x01a9, 0x0065},
  {0x2ef0, 0x010e, 0x45e0, 0x0ad0, 0x41f4, 0x03fc, 0x3258, 0x2be3, 0x010b, 0x07ff, 0x01ab, 0x016d},

  /* Bugzilla #32517, add new UFEC configurations */
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}
};

/* Datasheet, revision 1.0, Table 38 Ultra-FEC Encoder Configuration examples */
const static ten_coder_settings_t enc_val[TEN_FEC_MODE_MAX_NUM] = {  /* TX */
  /* Fixed Stuff Insertion Optional */
  /* A0      A1      A2      A3      A4      A5      A6      A7      B1      B0      C0      C1    */
  {0x2EF0, 0x00FF, 0x47A0, 0x0270, 0x705B, 0x0577, 0x21F4, 0x0784, 0x0003, 0x0000, 0x01C7, 0x0079},
  {0x2EF0, 0x0106, 0x41A0, 0x0328, 0x6464, 0x0974, 0x29FE, 0x07C0, 0x0003, 0x0000, 0x01CE, 0x0170},
  {0x2EF0, 0x0111, 0x45E0, 0x02D0, 0x5D6E, 0x0974, 0x49F4, 0x07FC, 0x0003, 0x0000, 0x01D5, 0x00E2}, /* Bugzilla 22317 */
  {0x2EF0, 0x011D, 0x41A0, 0x0328, 0x584C, 0x0D68, 0x51FE, 0x079C, 0x0003, 0x0000, 0x0138, 0x0061},
  {0x2EF0, 0x0129, 0x41A0, 0x0328, 0x484C, 0x116E, 0x59FE, 0x0774, 0x0003, 0x0000, 0x0128, 0x005B},
  {0x2F20, 0x012C, 0x40A0, 0x0330, 0x444C, 0x116E, 0x59EA, 0x0798, 0x0003, 0x0000, 0x0124, 0x00CB}, /* Bugzilla 22317 */
  {0x2EF0, 0x012D, 0x44A0, 0x0280, 0x4060, 0x1577, 0x59E0, 0x07D8, 0x0003, 0x0000, 0x0134, 0x01DB},
  /* Minimum of 16x Fixed Stuff columns Insertion Enabled */                  
  {0x0EF0, 0x00FF, 0x4580, 0x024F, 0x6E4B, 0x0577, 0x29FE, 0x07FC, 0x0003, 0x0000, 0x0000, 0x0000}, /* Bugzilla 22317 */
  /* 32x Fixed Stuff columns Insertion Enabled */                 
  {0x0EE0, 0x00FF, 0x4720, 0x0258, 0x6E3A, 0x0574, 0x29E0, 0x07CC, 0x0003, 0x0000, 0x01A3, 0x0171},
  /* Fixed Stuff Insertion Disabled */                  
  {0x2F69, 0x00FF, 0x44E0, 0x0360, 0x7530, 0x058C, 0x09B0, 0x0744, 0x0003, 0x0000, 0x011A, 0x0079},
  {0x2F4C, 0x00FF, 0x45A0, 0x024F, 0x7540, 0x0568, 0x11FE, 0x0784, 0x0003, 0x0000, 0x01AC, 0x00F5},
  {0x2EF0, 0x010B, 0x45E0, 0x02D0, 0x6642, 0x0974, 0x39F4, 0x07FC, 0x0003, 0x0000, 0x01A9, 0x0065},
  {0x2EF0, 0x010E, 0x45E0, 0x02D0, 0x6444, 0x0974, 0x41F4, 0x07FC, 0x0003, 0x0000, 0x01AB, 0x016D},
  
  /* Bugzilla #32517, add new UFEC configurations */
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
  {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}
};

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC ENABLE CODER MODULES                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_coder_module_enable(cs_uint16 module_id, 
                                       cs_uint8 slice,
                                       cs_uint8 enc_rc_enbl,
                                       cs_uint8 dec_rc_enbl,
                                       cs_uint8 dec_corr_ctrl)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Enable row/column encoder module              */
/*              o Decoder error correction control              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable encoder module, and set correction control for the    */
/* decoder module                                               */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [enc_rc_enbl] parameter is specified as:                 */
/*   0 = TEN_ROW_AND_COL_ENC_MODULE_DISABLED                    */
/*   1 = TEN_ROW_ENCODER_MODULE_ENABLED                         */
/*   2 = TEN_COLUMN_ENCODER_MODULE_ENABLED                      */
/*   3 = TEN_ROW_AND_COL_ENC_MODULE_ENABLED                     */
/*                                                              */
/* The [dec_rc_enbl] parameter is specified as:                 */
/*   0x00 = TEN_ALL_ROW_DEC0DER_DISABLED                        */
/*   0x01 = TEN__THIRD_ROW_DECODER                              */
/*   0x02 = TEN__SECOND_COLUMN_DECODER                          */
/*   0x04 = TEN__SECOND_ROW_DECODER                             */
/*   0x08 = TEN__FIRST_COLUMN_DECODER                           */
/*   0x10 = TEN__FIRST_ROW_DECODER                              */
/*          All 0s = Set decode inputs to all 0's and disable   */
/*                   decoders                                   */
/*          All 1s = Set up decoders for normal operation       */
/*                                                              */
/* The [dec_corr_ctrl] parameter is specified as:               */
/* Bit positions refer to                                       */
/*   0x01 = TEN_THIRD_ROW_DECODER                               */
/*   0x02 = TEN_SECOND_COLUMN_DECODER                           */
/*   0x04 = TEN_SECOND_ROW_DECODER                              */
/*   0x08 = TEN_FIRST_COLUMN_DECODER                            */
/*   0x10 = TEN_FIRST_ROW_DECODER                               */
/*          All 0s = Detect and count errors                    */
/*          All 1s = Detect, count and correct errors, if       */
/*                   possible                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_UTX_UTXCFGB1_t tmp_utxcfg1;
  TEN_UFEC_URX_URXCFGB0_t tmp_urxcfgb0;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG,
                             ": ten_ufec_coder_module_enable Param2"); 
    return(CS_ERROR);
  }
  if (enc_rc_enbl > 3) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG,
                             ": ten_ufec_coder_module_enable Param3"); 
    return(CS_ERROR);
  }
  if (dec_rc_enbl > 0x1F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG,
                             ": ten_ufec_coder_module_enable Param4"); 
    return(CS_ERROR);
  }
  if (dec_corr_ctrl > 0x1F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG,
                             ": ten_ufec_coder_module_enable Param5"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_urxcfgb0.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGB0));

      tmp_utxcfg1.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGB1));

      tmp_urxcfgb0.bf.EN = dec_rc_enbl;
      tmp_urxcfgb0.bf.CORREN = dec_corr_ctrl;

      tmp_utxcfg1.bf.EN = enc_rc_enbl;

      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGB1), tmp_utxcfg1.wrd);

      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGB0), tmp_urxcfgb0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  UFEC SET ERROR THRESHOLDS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_set_error_threshold(cs_uint16 module_id, 
                                       cs_uint8 slice,
                                       cs_uint32 thres)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Error Threshold                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the threshold value to compare against total correctable */
/* and total overflow errors                                    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [thresh] parametr is specified as:                       */
/*   0 - 0xFFFFFFFF                                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_set_error_threshold Param2"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, THR0), thres & 0x0000FFFF);

      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, THR1), thres & 0xFFFF0000 >> 16);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC SET EXCESS ERROR DETECT THRESHOLDS      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_set_eed_threshold(cs_uint16 module_id, 
                                     cs_uint8 slice,
                                     cs_uint32 ceed_thres, 
                                     cs_uint32 seed_thres)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Clear EED Seed Threshold                      */
/*              o Set EED Seed Threshold                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure excessive error detect seed thresholds to set and  */
/* clear BER threshold alarms                                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [ceed_thres] parameter is specified as:                  */
/*   0 - 0x3FFFFF                                               */
/*                                                              */
/* The [seed_thres] parameter is specified as:                  */
/*   0 - 0x3FFFFF                                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_SEED_THR_LOW_t tmp_seed_thr_low;
  TEN_UFEC_URX_SEED_THR_UP_t tmp_seed_thr_up;
  TEN_UFEC_URX_CEED_THR_LOW_t tmp_ceed_thr_low;
  TEN_UFEC_URX_CEED_THR_UP_t tmp_ceed_thr_up;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_set_eed_threshold Param2"); 
    return(CS_ERROR);
  }
  if (ceed_thres > 0x3FFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_set_eed_threshold Param3"); 
    return(CS_ERROR);
  }
  if (seed_thres > 0x3FFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_set_eed_threshold Param4"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);
  
  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      /* SEED threshold lo*/
      tmp_seed_thr_low.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, SEED_THR_LOW));
      tmp_seed_thr_low.bf.seed_thr_low = seed_thres & 0xFFFF;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, SEED_THR_LOW), tmp_seed_thr_low.wrd);

      /* SEED threshold hi*/
      tmp_seed_thr_up.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, SEED_THR_UP));
      tmp_seed_thr_up.bf.seed_thr_up = (seed_thres & 0x3F0000) >> 16;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, SEED_THR_UP), tmp_seed_thr_up.wrd);

      /* CEED threshold lo */
      tmp_ceed_thr_low.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, CEED_THR_LOW));
      tmp_ceed_thr_low.bf.ceed_thr_low = ceed_thres & 0xFFFF;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, CEED_THR_LOW), tmp_ceed_thr_low.wrd);

      /* CEED threshold hi*/
      tmp_ceed_thr_up.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, CEED_THR_UP));
      tmp_ceed_thr_up.bf.ceed_thr_up = (ceed_thres & 0x3F0000) >> 16;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, CEED_THR_UP), tmp_ceed_thr_up.wrd);
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC SET SIGNAL DEGRADE THRESHOLDS           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_set_deg_threshold(cs_uint16 module_id, 
                                     cs_uint8 slice,
                                     cs_uint32 cdeg_thres, 
                                     cs_uint32 sdeg_thres)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Clear DEG Threshold                           */
/*              o Set DEG Threshold                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure signal degrade thresholds to set and clear BER DEG */
/* thresholds                                                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [cdeg_thr_lo] parameter is specified as:                 */
/*   0 - 0x3FFFFF                                               */
/*                                                              */
/* The [sdeg_thr_hi] parameter is specified as:                 */
/*   0 - 0x3FFFFF                                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_SDEG_THR_LOW_t tmp_sdeg_thr_low;
  TEN_UFEC_URX_SDEG_THR_UP_t tmp_sdeg_thr_up;
  TEN_UFEC_URX_CDEG_THR_LOW_t tmp_cdeg_thr_low;
  TEN_UFEC_URX_CDEG_THR_UP_t tmp_cdeg_thr_up;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_set_deg_threshold Param2"); 
    return(CS_ERROR);
  }
  if (cdeg_thres > 0x3FFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_set_deg_threshold Param3"); 
    return(CS_ERROR);
  }
  if (sdeg_thres > 0x3FFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_set_deg_threshold Param4"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);
  
  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      /* SDEG threshold lo*/
      tmp_sdeg_thr_low.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, SDEG_THR_LOW));
      tmp_sdeg_thr_low.bf.sdeg_thr_low = sdeg_thres & 0xFFFF;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, SDEG_THR_LOW), tmp_sdeg_thr_low.wrd);

      /* SDEG threshold hi*/
      tmp_sdeg_thr_up.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, SDEG_THR_UP));
      tmp_sdeg_thr_up.bf.sdeg_thr_up = (sdeg_thres & 0x3F0000) >> 16;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, SDEG_THR_UP), tmp_sdeg_thr_up.wrd);

      /* CDEG threshold lo */
      tmp_cdeg_thr_low.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, CDEG_THR_LOW));
      tmp_cdeg_thr_low.bf.cdeg_thr_low = cdeg_thres & 0xFFFF;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, CDEG_THR_LOW), tmp_cdeg_thr_low.wrd);

      /* CDEG threshold hi*/
      tmp_cdeg_thr_up.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, CDEG_THR_UP));
      tmp_cdeg_thr_up.bf.cdeg_thr_up = (cdeg_thres & 0x3F0000) >> 16;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, CDEG_THR_UP), tmp_cdeg_thr_up.wrd);
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC SELECT ERROR TYPE                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_select_err_type(cs_uint16 module_id, 
                                   cs_uint8 slice,
                                   ten_fec_err_sel_t err_sel,
                                   ten_fec_err_src_t err_src,
                                   ten_ufec_err_type_t err_type)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Error Select                                  */
/*              o Error Source                                  */
/*              o Error Type                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Select the error type for EED and DEG                        */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [err_sel] parameter is specfied as:                      */
/*   0 = TEN_SEED_ERSEL  select set excessive error defect      */
/*   1 = TEN_CEED_ERSEL  select clear excessive error defect    */
/*   2 = TEN_SDEG_ERSEL  select set signal degrade error        */
/*   3 = TEN_CDEG_ERSEL  select clear signal degrade error      */
/*                                                              */
/* The [err_src] parameter selects the decoding stage specified */
/* as:                                                          */
/*   0  = TEN_NLDS_N4DS_N3DS_N2DS_N1DS                          */   
/*   1  = TEN_NLDS_N4DS_N3DS_N2DS_Y1DS                          */
/*   2  = TEN_NLDS_N4DS_N3DS_Y2DS_N1DS                          */
/*   3  = TEN_NLDS_N4DS_N3DS_Y2DS_Y1DS                          */
/*   4  = TEN_NLDS_N4DS_Y3DS_N2DS_N1DS                          */
/*   5  = TEN_NLDS_N4DS_Y3DS_N2DS_Y1DS                          */
/*   6  = TEN_NLDS_N4DS_Y3DS_Y2DS_N1DS                          */
/*   7  = TEN_NLDS_N4DS_Y3DS_Y2DS_Y1DS                          */
/*   8  = TEN_NLDS_Y4DS_N3DS_N2DS_N1DS                          */
/*   9  = TEN_NLDS_Y4DS_N3DS_N2DS_Y1DS                          */
/*   10 = TEN_NLDS_Y4DS_N3DS_Y2DS_N1DS                          */
/*   11 = TEN_NLDS_Y4DS_N3DS_Y2DS_Y1DS                          */
/*   12 = TEN_NLDS_Y4DS_Y3DS_N2DS_N1DS                          */
/*   13 = TEN_NLDS_Y4DS_Y3DS_N2DS_Y1DS                          */
/*   14 = TEN_NLDS_Y4DS_Y3DS_Y2DS_N1DS                          */
/*   15 = TEN_NLDS_Y4DS_Y3DS_Y2DS_Y1DS                          */
/*   16 = TEN_YLDS_N4DS_N3DS_N2DS_N1DS                          */
/*   17 = TEN_YLDS_N4DS_N3DS_N2DS_Y1DS                          */
/*   18 = TEN_YLDS_N4DS_N3DS_Y2DS_N1DS                          */
/*   19 = TEN_YLDS_N4DS_N3DS_Y2DS_Y1DS                          */
/*   20 = TEN_YLDS_N4DS_Y3DS_N2DS_N1DS                          */
/*   21 = TEN_YLDS_N4DS_Y3DS_N2DS_Y1DS                          */
/*   22 = TEN_YLDS_N4DS_Y3DS_Y2DS_N1DS                          */
/*   23 = TEN_YLDS_N4DS_Y3DS_Y2DS_Y1DS                          */
/*   24 = TEN_YLDS_Y4DS_N3DS_N2DS_N1DS                          */
/*   25 = TEN_YLDS_Y4DS_N3DS_N2DS_Y1DS                          */
/*   26 = TEN_YLDS_Y4DS_N3DS_Y2DS_N1DS                          */
/*   27 = TEN_YLDS_Y4DS_N3DS_Y2DS_Y1DS                          */
/*   28 = TEN_YLDS_Y4DS_Y3DS_N2DS_N1DS                          */
/*   29 = TEN_YLDS_Y4DS_Y3DS_N2DS_Y1DS                          */
/*   30 = TEN_YLDS_Y4DS_Y3DS_Y2DS_N1DS                          */
/*   31 = TEN_YLDS_Y4DS_Y3DS_Y2DS_Y1DS                          */
/*  First char  : YES or NO                                     */
/*  Second char : L=last, 4=fourth, 3=third ... Decoding Stage  */
/*                                                              */
/* The [err_type] parameter applies the thresholds to the error */
/* types as specified by:                                       */
/*   0 =    TEN_N0B_N1B_NUCODEWD                                */
/*   1 =    TEN_N0B_N1B_YUCODEWD                                */
/*   2 =    TEN_N0B_Y1B_NUCODEWD                                */
/*   3 =    TEN_N0B_Y1B_YUCODEWD                                */
/*   4 =    TEN_Y0B_N1B_NUCODEWD                                */
/*   5 =    TEN_Y0B_N1B_YUCODEWD                                */
/*   6 =    TEN_Y0B_Y1B_NUCODEWD                                */
/*   7 =    TEN_Y0B_Y1B_YUCODEWD                                */
/*  First char  : YES or NO                                     */
/*  Second char : 0B      - RX bit 0 and corrected bit 1        */
/*  Third char  : 1B      - RX bit 1 and corrected bit 0        */
/*  Fourth char : UCODEWD - Uncorrectable codewords             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_ERSEL_t tmp_ersel;
  TEN_UFEC_URX_DEG_GLB_t tmp_deg_glb;
  TEN_UFEC_URX_EED_GLB_t tmp_eed_glb;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_select_err_type Param2"); 
    return(CS_ERROR);
  }
  if (err_sel > TEN_CDEG_ERSEL) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_select_err_type Param3"); 
    return(CS_ERROR);
  }
  if (err_src > TEN_YLDS_Y4DS_Y3DS_Y2DS_Y1DS) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_select_err_type Param4"); 
    return(CS_ERROR);
  }
  if (err_type > TEN_Y0B_Y1B_YUCODEWD) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_select_err_type Param5"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);
  
  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_ersel.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, ERSEL));

      tmp_eed_glb.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, EED_GLB));

      tmp_deg_glb.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, DEG_GLB));

      switch(err_sel) {
        case TEN_SEED_ERSEL:
          tmp_ersel.bf.seed_ersel = err_type;
          tmp_eed_glb.bf.seed_glb = err_src;
          break;

        case TEN_CEED_ERSEL:
          tmp_ersel.bf.ceed_ersel = err_type;
          tmp_eed_glb.bf.ceed_glb = err_src;
          break;

        case TEN_SDEG_ERSEL:
          tmp_ersel.bf.sdeg_ersel = err_type;
          tmp_deg_glb.bf.sdeg_glb = err_src;
          break;

        case TEN_CDEG_ERSEL:
          tmp_ersel.bf.cdeg_ersel = err_type;
          tmp_deg_glb.bf.cdeg_glb = err_src;
          break;
      }

      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, ERSEL), tmp_ersel.wrd);

      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, EED_GLB), tmp_eed_glb.wrd);

      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, DEG_GLB), tmp_deg_glb.wrd);
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC SELECT TIMER UNIT                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_select_timer_unit(cs_uint16 module_id, 
                                     cs_uint8 slice,
                                     cs_boolean err_sel,
                                     ten_fec_time_unit_sel_t tu_sel)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Error Select                                  */
/*              o Time Unit Selection                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure one of the eight independent global timers used    */
/* to determine the window size used by BER monitor             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [err_sel] parameter is specfied as:                      */
/*   0 = EED - Excessive error defect                           */
/*   1 = DEG - Signal degrade                                   */
/*                                                              */
/* The [tu_sel] parameter is specified as:                      */
/*   0   = TEN_INT_TIME_SOURCE_1                                */
/*   1   = TEN_INT_TIME_SOURCE_2                                */
/*   2   = TEN_INT_TIME_SOURCE_3                                */
/*   3   = TEN_INT_TIME_SOURCE_4                                */
/*   4   = TEN_INT_TIME_SOURCE_5                                */
/*   5   = TEN_INT_TIME_SOURCE_6                                */
/*   6   = TEN_SW_TIME_SOURCE                                   */
/*   7   = TEN_EXT_TIME_SOURCE                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_TUSEL_t tmp_tusel;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice > TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_select_timer_unit Param2"); 
    return(CS_ERROR);
  }
  if (err_sel > 1) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_select_timer_unit Param3"); 
    return(CS_ERROR);
  }
  if (tu_sel > TEN_EXT_TIME_SOURCE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_select_timer_unit Param4"); 
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {  
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_tusel.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, TUSEL));
      
      switch(err_sel) {
        case 0:
          tmp_tusel.bf.eed_tusel = tu_sel;
          break;

        case 1:
          tmp_tusel.bf.deg_tusel = tu_sel;
          break;
      }
      
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, TUSEL), tmp_tusel.wrd);  
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC CONFIG FEC EED ALARM WINDOW PARAMS      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_config_fec_eed_alarm_win(cs_uint16 module_id,
                                            cs_uint8 slice,
                                            cs_uint8 seed_div,
                                            cs_uint8 seed_dtv,
                                            cs_uint8 ceed_niv,
                                            cs_uint8 ceed_ntv)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Set EED Defect Intermittant Value             */
/*              o Set EED Defect Threshold Value                */
/*              o Clear EED No Defect Intermittant Value        */
/*              o Clear EED No Defect Threshold Value           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure UFEC dFECEED alarm windows settings                */
/* When more than SEED_DTV excessively-errored time windows are */
/* detected and no intervening error-free sequence occur for    */
/* longer than SEED_DIV intervals of SEED_WIN[5:0] x Selected   */
/* Time Unit, the Excessive Error Defect alarm (dFECEED) is set */
/* The Excessive Error Defect alarm (dFECEED) is cleared when   */
/* more than CEED_NTV non-excessively errored time windows are  */
/* detected without been intermitted by CEED_NIV errored time   */
/* windows                                                      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [seed_div] parameter is the set excessive error defect   */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [seed_dtv] parameter is the set excessive error defect   */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [ceed_niv] parameter is the clear excessive error defect */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [ceed_ntv] parameter is the clear excessive error defect */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_EED_DTV_DIV_t tmp_eed_dtv_div;
  TEN_UFEC_URX_EED_NTV_NIV_t tmp_eed_ntv_niv;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_fec_eed_alarm_win Param2"); 
    return(CS_ERROR);
  }
  if (seed_div > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_fec_eed_alarm_win Param3"); 
    return(CS_ERROR);
  }
  if (seed_dtv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_fec_eed_alarm_win Param4"); 
    return(CS_ERROR);
  }
  if (ceed_niv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_fec_eed_alarm_win Param5"); 
    return(CS_ERROR);
  }
  if (ceed_ntv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_fec_eed_alarm_win Param6"); 
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_eed_dtv_div.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, EED_DTV_DIV));
      tmp_eed_dtv_div.bf.seed_div = seed_div;
      tmp_eed_dtv_div.bf.seed_dtv = seed_dtv;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, EED_DTV_DIV), tmp_eed_dtv_div.wrd);

      tmp_eed_ntv_niv.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, EED_NTV_NIV));
      tmp_eed_ntv_niv.bf.ceed_niv = ceed_niv;
      tmp_eed_ntv_niv.bf.ceed_ntv = ceed_ntv;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, EED_NTV_NIV), tmp_eed_ntv_niv.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC CONFIG FEC DEG ALARM WINDOW PARAMS      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_config_fec_deg_alarm_win(cs_uint16 module_id,
                                            cs_uint8 slice,
                                            cs_uint8 sdeg_div,
                                            cs_uint8 sdeg_dtv,
                                            cs_uint8 cdeg_niv,
                                            cs_uint8 cdeg_ntv)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Set DEG Defect Intermittant Value             */
/*              o Set DEG Defect Threshold Value                */
/*              o Clear DEG Defect Intermittant Value           */
/*              o Clear DEG Defect Threshold Value              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure UFEC dFECDEG alarm windows settings                */
/* When more than SDEG_DTV degraded time windows are detected   */
/* and no intervening error-free sequence occur for longer than */
/* SDEG_DIV intervals of SDEG_WIN[5:0] x Selected Time Unit, the*/
/* Degraded Defect alarm (dFECDEG) is set.                      */
/* The Degraded Defect alarm (dFECDEG) is cleared when more than*/
/* CDEG_NTV non-degraded errored time windows are detected      */
/* without been intermitted by CDEG_NIV errored time windows.   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [sdeg_div] parameter is the set signal degrade defect    */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [sdeg_dtv] parameter is the set signal degrade defect    */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [cdeg_niv] parameter is the clear signal degrade defect  */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [cdeg_ntv] parameter is the clear signal degrade defect  */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_DEG_DTV_DIV_t tmp_deg_dtv_div;
  TEN_UFEC_URX_DEG_NTV_NIV_t tmp_deg_ntv_niv;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_fec_deg_alarm_win Param2"); 
    return(CS_ERROR);
  }
  if (sdeg_div > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_fec_deg_alarm_win Param2"); 
    return(CS_ERROR);
  }
  if (sdeg_dtv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_fec_deg_alarm_win Param4"); 
    return(CS_ERROR);
  }
  if (cdeg_niv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_fec_deg_alarm_win Param5"); 
    return(CS_ERROR);
  }
  if (cdeg_ntv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_fec_deg_alarm_win Param6"); 
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_deg_dtv_div.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, DEG_DTV_DIV));
      tmp_deg_dtv_div.bf.sdeg_div = sdeg_div;
      tmp_deg_dtv_div.bf.sdeg_dtv = sdeg_dtv;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, DEG_DTV_DIV), tmp_deg_dtv_div.wrd);

      tmp_deg_ntv_niv.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, DEG_NTV_NIV));
      tmp_deg_ntv_niv.bf.cdeg_niv = cdeg_niv;
      tmp_deg_ntv_niv.bf.cdeg_ntv = cdeg_ntv;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, DEG_NTV_NIV), tmp_deg_ntv_niv.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC SET TIMING WINDOW SIZE                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_set_timing_win_size(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       ten_fec_err_sel_t err_sel,
                                       cs_uint8 window_size)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Error Select                                  */
/*              o Window Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the size of timing window to clear the alarms      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [err_sel] parameter is specfied as:                      */
/*   0 = TEN_SEED_ERSEL  select set excessive error defect      */
/*   1 = TEN_CEED_ERSEL  select clear excessive error defect    */
/*   2 = TEN_SDEG_ERSEL  select set signal degrade error        */
/*   3 = TEN_CDEG_ERSEL  select clear signal degrade error      */
/*                                                              */
/* The [window_size] parameter is specified as:                 */
/*   0 - 0x3F                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_EED_WIN_t tmp_eed_win;
  TEN_UFEC_URX_DEG_WIN_t tmp_deg_win;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_set_timing_win_size Param2"); 
    return(CS_ERROR);
  }
  if (err_sel > TEN_CDEG_ERSEL) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_set_timing_win_size Param3"); 
    return(CS_ERROR);
  }
  if (window_size > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_set_timing_win_size Param4"); 
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_eed_win.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, EED_WIN));

      tmp_deg_win.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, DEG_WIN));

      switch(err_sel) {
        case TEN_SEED_ERSEL:
          tmp_eed_win.bf.seed_win = window_size;
          break;

        case TEN_CEED_ERSEL:
          tmp_eed_win.bf.ceed_win = window_size;
          break;

        case TEN_SDEG_ERSEL:
          tmp_deg_win.bf.sdeg_win = window_size;
          break;

        case TEN_CDEG_ERSEL:
          tmp_deg_win.bf.cdeg_win = window_size;
          break;
      }

      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, EED_WIN), tmp_eed_win.wrd);

      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, DEG_WIN), tmp_deg_win.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC INJECT ERROR                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_inject_err(cs_uint16 module_id,
                              cs_uint8 slice,
                              ten_err_freq_t single_err,
                              cs_uint16 duration,
                              cs_uint16 err_value)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Single or Continuous                          */
/*              o Duration                                      */
/*              o Error Value                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure UFEC Error Insertion.                              */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [single_err] parameter is specified as:                  */
/*   0 = Inject continuously until cleared                      */
/*   1 = Inject single err                                      */
/*                                                              */
/* The [duration] parameter is specified as:                    */
/*   Number of milliseconds to inject errors before clearing.   */
/*   0          = For single error                              */
/*   0 - 0xFFFF = For continuous errors                         */
/* NOTE:  This function might block for the duration if         */
/* continuous errors need to be generated and duration is       */
/* non-zero.                                                    */
/*                                                              */
/* The [err_value] parameter is specified as:                   */
/*   Number of bits to be corrupted for Row Code.               */
/*   0 - 0x7FFF                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_UTX_ERRINSCFG1_t tmp_errinscfg1;
  TEN_UFEC_UTX_ERRINSCFG2_t tmp_errinscfg2;
  TEN_UFEC_UTX_UTXCFGA7_t tmp_utxcfga7;
  T41_t *pDev = NULL;
/*  double BER = 0; */

  /* Parameter Checking */
  if ((slice>=TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_inject_err Param2"); 
    return(CS_ERROR);
  }
  if(single_err > TEN_SINGLE_ERR) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_inject_err Param3"); 
    return CS_ERROR;
  }
  if(err_value > 32767) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_inject_err Param5"); 
    return CS_ERROR;
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_errinscfg2.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, ERRINSCFG2));
      
      if(single_err) {
          
        /* Bugzilla #27461, Following a positive transition of this bit, */
        /* ERRINSCFG1 number of bits will be corrupted for the first     */
        /* codeword following the next Frame Pulse                       */
        tmp_errinscfg2.bf.errinjOnce = 0;
        tmp_errinscfg2.bf.errinjCont = 0;
        TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, ERRINSCFG2), tmp_errinscfg2.wrd);
      
        tmp_errinscfg2.bf.errinjOnce = 1;
        tmp_errinscfg2.bf.errinjCont = 0;
      }
      else {
        tmp_errinscfg2.bf.errinjOnce = 0;
        tmp_errinscfg2.bf.errinjCont = 1;
      }
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, ERRINSCFG2), tmp_errinscfg2.wrd);

      tmp_errinscfg1.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, ERRINSCFG1));
      tmp_errinscfg1.bf.errvalue = err_value;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, ERRINSCFG1), tmp_errinscfg1.wrd);

      /* Compute the BER */
      tmp_utxcfga7.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGA7));
      /*BER = (double)((1 / (32 * tmp_utxcfga7.wrd))* tmp_errinscfg1.bf.errvalue) ; */
      /* CS_PRINT("TEN_UFEC stride %d BER = %f\n", ii, BER); */
    }
  }

  if(!single_err) {
    /* Bugzilla #28471, 6 ms minimum delay */
    TEN_MDELAY(duration);

    for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
      if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
        tmp_errinscfg2.bf.errinjCont = 0;
        TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, ERRINSCFG2), tmp_errinscfg2.wrd);
      }
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC ERROR DECORELATOR SOFT (LOGIC) RESET    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_ed_reset(cs_uint16 module_id, 
                            cs_uint8 slice,
                            cs_dir_t dir, 
                            cs_reset_action_t act)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Control                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Disable/enable UFEC ED sub-block logic reset for the         */
/* specified datapath direction.                                */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_URXCFGED_t tmp_urxcfged;
  TEN_UFEC_UTX_UTXCFGED_t tmp_utxcfged;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_ufec_ed_reset";  /* __FUNCTION__ or __func__ not available for all compilers */

  /* Parameter Checking */
  if ((slice>=TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s()  slice=%d", func, slice); 
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s()  dir=%d", func, dir); 
    return CS_ERROR;
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s()  act=%d", func, act); 
    return CS_ERROR;
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        tmp_urxcfged.wrd = 0;
        tmp_urxcfged.bf.rxEdSoftReset = 1;
        ten_reset_action(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGED), tmp_urxcfged.wrd, act); 
      }
            
      if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        tmp_utxcfged.wrd = 0;
        tmp_utxcfged.bf.txEdSoftReset = 1;
        ten_reset_action(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGED), tmp_utxcfged.wrd, act); 
      }
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC ENABLE ERROR DECORELATOR                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_ed_enable(cs_uint16 module_id,
                             cs_uint8 slice,
                             cs_dir_t dir, 
                             cs_ctl_t ctrl)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable error decorelator                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctrl] parameter is specified as:                        */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_URXCFGED_t tmp_urxcfged;
  TEN_UFEC_UTX_UTXCFGED_t tmp_utxcfged;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_ufec_ed_enable";  /* __FUNCTION__ or __func__ not available for all compilers */

  /* Parameter Checking */
  if ((slice>=TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() slice=%d", func, slice); 
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() dir=%d", func, dir); 
    return CS_ERROR;
  }
  if(ctrl > CS_ENABLE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() ctrl=%d", func, ctrl); 
    return CS_ERROR;
  }
  
  CS_PRINT("%s() %s, %s, %s, ctrl=%d\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           ten_dir_strings[dir],
           ctrl);
  

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        tmp_urxcfged.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGED));
        if(ctrl == CS_ENABLE)
          tmp_urxcfged.bf.rxEdEnable = 1;
        else
          tmp_urxcfged.bf.rxEdEnable = 0;

        TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGED), tmp_urxcfged.wrd);
      }
            
      if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        tmp_utxcfged.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGED));
        if(ctrl == CS_ENABLE)
          tmp_utxcfged.bf.txEdEnable = 1;
        else
          tmp_utxcfged.bf.txEdEnable = 0;
        
        TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGED), tmp_utxcfged.wrd);
      }
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC CONFIGURE ED BUFFER SIZE                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_ed_config_buffer_size(cs_uint16 module_id,
                                         cs_uint8 slice,
                                         cs_dir_t dir, 
                                         ten_ed_buffer_type_t type,
                                         cs_uint16 size)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Buffer Type                                   */
/*              o Buffer Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure UFEC Error Decorelator buffer type and size.       */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [type] parameter selects the type of buffer:             */
/*   0 = TEN_ED_BUF_5KB                                         */
/*   1 = TEN_ED_BUF_10KB                                        */
/*   2 = TEN_ED_BUF_15KB                                        */
/*                                                              */
/* The [size] parameter configures the chosen buffer size:      */
/*   0 - 0x3FF, for TEN_ED_BUF_5KB                              */
/*   0 - 0x7FF, for TEN_ED_BUF_10KB and TEN_ED_BUF_10KB.        */
/*                                                              */
/* NOTE:                                                        */
/*                                                              */
/* 5K buffer:  The size of this buffer must be set to           */
/*             (N / 32) - 1, where                              */
/*             N = NCOLS*16*4, NCOLS assumes 128 bits/column.   */
/*                                                              */
/* 10K buffer: The size of this buffer must be set to           */
/*             (N / 16) - 1, where                              */
/*             N = NCOLS*16*4, NCOLS assumes 128 bits/column.   */
/*                                                              */
/* 15K buffer: The size of this buffer must be set to           */
/*             (N * 3/32) - 1, where                            */
/*             N = NCOLS*16*4, NCOLS assumes 128 bits/column.   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice>=TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_ed_config_buffer_size Param2");
    return(CS_ERROR);
  }
  if (dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_ed_config_buffer_size Param3"); 
    return CS_ERROR;
  }
  if (type > TEN_ED_BUF_15KB) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_ed_config_buffer_size Param4"); 
    return CS_ERROR;
  }
  
  if ((size > 0x3FF) && (type == TEN_ED_BUF_5KB)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_ed_config_buffer_size Param5"); 
    return CS_ERROR;
  }
  if (size > 0x7FF) {  /* for TEN_ED_BUF_10KB and TEN_ED_BUF_15KB */
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_ed_config_buffer_size Param5"); 
    return CS_ERROR;
  }
  
  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        switch(type) {
          case TEN_ED_BUF_5KB:
            TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGED1), size);
            break;

          case TEN_ED_BUF_10KB:
            TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGED2), size);
            break;

          case TEN_ED_BUF_15KB:       
            TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGED3), size);
            break;
        }
      }

      if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        switch(type) {
          case TEN_ED_BUF_5KB:
            TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGED1), size);
            break;

          case TEN_ED_BUF_10KB:
            TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGED2), size);
            break;

          case TEN_ED_BUF_15KB:       
            TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGED3), size);
            break;
        }
      }

    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC ED BURST INSERTION                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_ed_burst_insertion(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      ten_err_freq_t single_err,
                                      cs_uint16 ed_burst_x,
                                      cs_uint16 ed_burst_y)

/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Single or Continuous Burst Error              */
/*              o ED Burst X                                    */
/*              o ED Burst Y                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure UFEC Error Insertion.                              */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [single_err] parameter is specified as:                  */
/*   0 = Data going out is inverted between cycles X and Y      */
/*       every frame                                            */
/*   1 = Data going out is inverted between cycles X and Y once */
/*                                                              */
/* The [ed_burst_x] parameter specifies the start cycle of      */
/* the burst                                                    */
/*   0 - 0x07FF                                                 */
/*                                                              */
/* The [ed_burst_y] parameter specifies the end cycle of        */
/* the burst                                                    */
/*   0 - 0x07FF                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_UTX_UTXCFGBURSTINSED_t tmp_utxcfgburstinsed;
  TEN_UFEC_UTX_UTXCFGBURSTINSED1_t tmp_utxcfgburstinsed1;
  TEN_UFEC_UTX_UTXCFGBURSTINSED2_t tmp_utxcfgburstinsed2;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice>=TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_ed_burst_insertion Param2");
    return(CS_ERROR);
  }
  if(single_err > TEN_SINGLE_ERR) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_ed_burst_insertion Param3");
    return CS_ERROR;
  }
  if(ed_burst_x > 2047) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_ed_burst_insertion Param4");
    return CS_ERROR;
  }
  if(ed_burst_y > 2047) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_ed_burst_insertion Param5");
    return CS_ERROR;
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_utxcfgburstinsed.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGBURSTINSED));
      if(single_err)
        tmp_utxcfgburstinsed.bf.burstEnOnce = 1;
      else
        tmp_utxcfgburstinsed.bf.burstEn = 1;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGBURSTINSED), tmp_utxcfgburstinsed.wrd);

      tmp_utxcfgburstinsed1.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGBURSTINSED1));
      tmp_utxcfgburstinsed1.bf.edBurstX = ed_burst_x;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGBURSTINSED1), tmp_utxcfgburstinsed1.wrd);

      tmp_utxcfgburstinsed2.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGBURSTINSED2));
      tmp_utxcfgburstinsed2.bf.edBurstY = ed_burst_y;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGBURSTINSED2), tmp_utxcfgburstinsed2.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC SOFT (LOGIC) RESET                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_reset(cs_uint16 module_id, 
                         cs_uint8 slice,
                         cs_dir_t dir, 
                         cs_reset_action_t act)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Control                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Disable/enable UFEC sub-block logic reset for the specified  */
/* datapath direction.                                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_UTX_UTXCFGB0_t tmp_utxcfgb0;
  TEN_UFEC_URX_URXCFGB_t tmp_urxcfgb;  
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_reset Param2"); 
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_reset Param3"); 
    return CS_ERROR;
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_reset Param4"); 
    return CS_ERROR;
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        tmp_urxcfgb.wrd = 0;
        tmp_urxcfgb.bf.RXRST = 1;
        ten_reset_action(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGB), tmp_urxcfgb.wrd, act);
      }

      if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        tmp_utxcfgb0.wrd = 0;
        tmp_utxcfgb0.bf.TXRST = 1;

        ten_reset_action(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGB0), tmp_utxcfgb0.wrd, act);
      }
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC GET RX SYNC STATUS                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_int16 ten_ufec_get_rx_sync_status(cs_uint16 module_id,
                                      cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Bitmapped Status:                               */
/*              PHIOK                                           */
/*                Ultra FEC receiver demap:                     */
/*                 phi check received/expected status           */
/*              PTRSYNC                                         */
/*                 Ultra FEC receiver pointer sync status       */
/*              ST9SYNC                                         */
/*                 Ultra FEC receiver state9 sync status        */
/*              SYNCED                                          */
/*                 Ultra FEC receiver sync status               */
/* DESCRIPTION:                                                 */
/* Returns the bitmapped Ultra FEC Receiver Sync status.        */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_URXSTAT_t tmp_urxstat;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_get_rx_sync_status Param2"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_urxstat.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, URXSTAT));

      CS_PRINT("Ultra FEC slice %d RX SYNC status            = %s\n", ii, 
                              tmp_urxstat.bf.SYNCED ? "SYNCED" : "NOT SYNCED");
      CS_PRINT("Ultra FEC slice %d RX state9 SYNC status     = %s\n", ii, 
                              tmp_urxstat.bf.ST9SYNC ? "SYNCED" : "NOT SYNCED");
      CS_PRINT("Ultra FEC slice %d RX pointer SYNC status    = %s\n", ii, 
                              tmp_urxstat.bf.PTRSYNC ? "SYNCED" : "NOT SYNCED");
      CS_PRINT("Ultra FEC slice %d RX demap phi check status = %s\n", ii, 
                              tmp_urxstat.bf.PHIOK ? "SYNCED" : "NOT SYNCED");
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return tmp_urxstat.wrd;
}
#endif


#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC DECODER CONFIG                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_config_decoder(cs_uint16 module_id, 
                                  cs_uint8 slice,
                                  ten_fec_ovhd_t fec_ovhd)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FEC mode                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Setup UFEC decoder configuration.                            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [fec_ovhd] parameter is specified as:                    */
/*   TEN_FEC_MODE_OTUkV             = 0,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_262         = 1,   ( 10%)               */
/*   TEN_FEC_MODE_OTUkV_273         = 2,   ( 15%)               */
/*   TEN_FEC_MODE_OTUkV_285         = 3,   ( 20%)               */
/*   TEN_FEC_MODE_OTUkV_297         = 4,   ( 25%)               */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5,   ( 25%)               */
/*   TEN_FEC_MODE_OTUkV_301         = 6,   ( 26%)               */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (3.4%)               */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10,  (4.2%)               */
/*   TEN_FEC_MODE_OTUkV_267         = 11,  ( 12%)               */
/*   TEN_FEC_MODE_OTUkV_270         = 12,  ( 13%).              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, ": ten_ufec_config_decoder Param2"); 
    return (CS_ERROR);
  }
  if(fec_ovhd >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, ": ten_ufec_config_decoder Param3"); 
    return (CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGA0), dec_val[fec_ovhd].configA0);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGA1), dec_val[fec_ovhd].configA1);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGA2), dec_val[fec_ovhd].configA2);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGA3), dec_val[fec_ovhd].configA3);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGA4), dec_val[fec_ovhd].configA4);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGA5), dec_val[fec_ovhd].configA5);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGA7), dec_val[fec_ovhd].configA7);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGB) , dec_val[fec_ovhd].configB);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGB0), dec_val[fec_ovhd].configB0);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGC0), dec_val[fec_ovhd].configC0);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGC1), dec_val[fec_ovhd].configC1);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGA6), dec_val[fec_ovhd].configA6);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}
#endif

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC ENCODER CONFIG                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_config_encoder(cs_uint16 module_id, 
                                  cs_uint8 slice,
                                  ten_fec_ovhd_t fec_ovhd)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FEC mode                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Setup UFEC encoder configuration                             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [fec_ovhd] parameter is specified as:                    */
/*   TEN_FEC_MODE_OTUkV             = 0,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_262         = 1,   ( 10%)               */
/*   TEN_FEC_MODE_OTUkV_273         = 2,   ( 15%)               */
/*   TEN_FEC_MODE_OTUkV_285         = 3,   ( 20%)               */
/*   TEN_FEC_MODE_OTUkV_297         = 4,   ( 25%)               */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5,   ( 25%)               */
/*   TEN_FEC_MODE_OTUkV_301         = 6,   ( 26%)               */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (3.4%)               */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10,  (4.2%)               */
/*   TEN_FEC_MODE_OTUkV_267         = 11,  ( 12%)               */
/*   TEN_FEC_MODE_OTUkV_270         = 12,  ( 13%).              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;

/* Parameter Checking */
  if ((slice >= TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_encoder Param2"); 
    return(CS_ERROR);
  }
  if(fec_ovhd >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_ufec_config_encoder Param3"); 
    return CS_ERROR;
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);

  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGA0), enc_val[fec_ovhd].configA0);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGA1), enc_val[fec_ovhd].configA1);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGA2), enc_val[fec_ovhd].configA2);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGA3), enc_val[fec_ovhd].configA3);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGA4), enc_val[fec_ovhd].configA4);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGA5), enc_val[fec_ovhd].configA5);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGA6), enc_val[fec_ovhd].configA6);
      
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGB0), enc_val[fec_ovhd].configB0);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGB1), enc_val[fec_ovhd].configB);
      
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGC0), enc_val[fec_ovhd].configC0);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGC1), enc_val[fec_ovhd].configC1);
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, UTXCFGA7), enc_val[fec_ovhd].configA7);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  UFEC SELECT GLOBAL TIMING SOURCE             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : UFEC                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_select_global_timing_source(cs_uint16 module_id,
                                               cs_uint8 instance, 
                                               cs_uint16 select)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Error Correction statistics Time Interval Selection. Selects */
/* one out of eight different statistics timing generators.     */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*     0..3 or TEN_INSTANCE_ALL (0xFF)                          */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   0 = 1st internal timing generator                          */
/*   1 = 2nd internal timing generator                          */
/*   2 = 3rd internal timing generator                          */
/*   3 = 4th internal timing generator                          */
/*   4 = 5th internal timing generator                          */
/*   5 = 6th internal timing generator                          */
/*   6 = Software controlled timing generator                   */
/*   7 = Timing generator controlled by external hardware       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_URX_URXCFGB0_t tmp_urxcfgb0;
  T41_t *pDev = NULL;

  if ((instance >= TEN_UFEC_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);
  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_urxcfgb0.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGB0));
      tmp_urxcfgb0.bf.ECTISEL = select;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, ii, URXCFGB0), tmp_urxcfgb0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  UFEC DEBUG                                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : UFEC                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ufec_debug(cs_uint16 module_id, cs_uint8 instance, 
                     cs_uint16 debug_value)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Debug Value                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This is an indirect access feature, may be used for debugging    */
/* addresses 0-'d35. Write the address which is desired to be       */
/* loaded, next, read back this address.  The returned value        */
/* corresponds to the value existing at the indirect address.       */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [debug_value]  Indirect address value.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  #if 0
  cs_uint16 ii;
  TEN_UFEC_BERGEN_DEBUG_t tmp_debug;
  #endif

  if ((instance >= TEN_UFEC_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);
  #if 0
  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_debug.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, module_id, ufec_DEBUG) +
      ii * TEN_UFEC_STRIDE);
      tmp_debug.bf.debug_value = debug_value;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, module_id, ufec_DEBUG) +
      ii * TEN_UFEC_STRIDE, tmp_debug.wrd);
    }
  }
  #endif
  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}

#endif

/********************************************************************/
/* $rtn_hdr_start  UFEC CTRL1                                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : UFEC                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ufec_ctrl1(cs_uint16 module_id, cs_uint8 instance, 
                     cs_uint16 ctrlword)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Ctrlword                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* BERGEN Control. Note the upper 8 bits are used for trigger-on    */
/* write and status flags (following a write cycle the 8 MSB are    */
/* cleared and ORed with stat_ov_1). More description to be added.  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [ctrlword]                                                     */
/*     Specified as 0x0000..0xFFFF                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_UFEC_BERGEN_CTRL1_t tmp_ctrl1;
  T41_t *pDev = NULL;

  if ((instance >= TEN_UFEC_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);
  for (ii=0; ii<TEN_UFEC_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_ctrl1.wrd = TEN_REG_READ(TEN_UFEC_REG_ADDR(pDev, module_id, CTRL1) +
      ii * TEN_UFEC_STRIDE);
      tmp_ctrl1.bf.ctrlword = ctrlword;
      TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, module_id, CTRL1) +
      ii * TEN_UFEC_STRIDE, tmp_ctrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (CS_OK);
}

/* Bugzilla 24692 Start */
/* Bugzilla 24692 End */



/********************************************************************/
/* Function: ten_get_UFEC_inst_reg_addr                             */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a UFEC register.                             */
/*                                                                  */
/* Used by macro TEN_UFEC_REG_ADDR. Given the base address          */
/* of a non-common UFEC register as defined in t41_registers.h,     */
/* and its instance number (0-TEN_UFEC_COUNT), calcuates            */
/* the offset and adds it to the base register's address.           */
/********************************************************************/
volatile cs_reg *ten_get_UFEC_inst_reg_addr( cs_reg   *pReg,
                                             cs_uint16 instance )
{
  if (instance >= TEN_UFEC_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "UFEC instance %d out of range. S/b < TEN_UFEC_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_UFEC_STRIDE);
}

/****************************************************************/
/* $rtn_hdr_start  UFEC CUSTOM CONFIG                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_ufec_custom_config(cs_uint16 module_id, cs_uint16 custom_ufec_mode)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set up custom UFEC configurations.                           */
/*                                                              */
/* [custom_ufec_mode]                                           */
/*   TEN_FEC_MODE_OTUkV_263         = 17,    ( 7%)              */
/*   TEN_FEC_MODE_OTUkV_280         = 18,    (18%)              */
/*   TEN_FEC_MODE_OTUkV_295         = 19,    (25%)              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 ncols = 0;
  cs_uint16 npar = 0;
  cs_status rtn = CS_OK;

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_UFEC);
  
  rtn |= ten_mpif_global_reset_ufec (dev_id, TEN_MPIF_GLOBAL_UFEC_0, CS_TX_AND_RX, CS_RESET_TOGGLE);
  
  switch (custom_ufec_mode) {
 
  case (TEN_FEC_MODE_OTUkV_263):
    /* from full.pl */
    ncols = 263 - 1;
    npar = 263 - 243 - 1;
    
    /* Set NCOLS and NPAR for OTU3V  ncols 262, npar 19 */
    rtn |= ten_n40g_otnr4x_set_ncols(module_id, ncols);
    rtn |= ten_n40g_otnr4x_set_nparb_npar(module_id, 0, npar);
    rtn |= ten_n40g_otnt4x_set_ncols(module_id, ncols);
    rtn |= ten_n40g_otnt4x_set_nparb_npar(module_id, 0, npar);
  
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGC0, 0x01a7); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGC1, 0x0073); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGB , 0x010b); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGB0, 0x07ff); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA0, 0x2f40); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA1, 0x0107); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA2, 0x4720); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA3, 0x0640); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA4, 0x29f8); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA5, 0x039c); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA7, 0x2bff); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA6, 0x0); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA6, 0x32a3); */
    
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGC0), 0x01a7);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGC1), 0x0073);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGB),  0x010b);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGB0), 0x07ff);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA0), 0x2f40);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA1), 0x0107);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA2), 0x4720);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA3), 0x0640);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA4), 0x29f8);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA5), 0x039c);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA7), 0x2bff);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA6), 0x0000);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA6), 0x32a3);

    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGB1, 0x0003); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGC0, 0x01a7); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGC1, 0x0073); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGB0, 0x0000); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA0, 0x2f40); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA1, 0x0107); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA2, 0x4720); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA3, 0x0240); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA4, 0x6c3c); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA5, 0x0574); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA6, 0x29f8); */
    /* main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA7, 0x079c); */
      
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGB1), 0x0003);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGC0), 0x01a7);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGC1), 0x0073);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGB0), 0x0000);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA0), 0x2f40);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA1), 0x0107);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA2), 0x4720);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA3), 0x0240);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA4), 0x6c3c);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA5), 0x0574);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA6), 0x29f8);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA7), 0x079c);
    
    ten_hl_ufec_ed_config(module_id, 0, CS_TX_AND_RX, CS_ENABLE, ncols);
    ten_n40g_otnr4x_oacfg0_dsyhyst(module_id, 11);
    break;
    
  case (TEN_FEC_MODE_OTUkV_280):  /*  18%, 280,239 columns */
    ncols = 280 - 1;  /* 279 */

    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGC0), 0x01b3);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGC1), 0x005d);

    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA0), 0x2ef0);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA1), 0x0118);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA2), 0x4720);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA3), 0x0258);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA4), 0x5c4a);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA5), 0x0974);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA6), 0x59e0);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA7), 0x07f4);

    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGB1), 0x0003);

    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGB0), 0x0000);

    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGB),  0x010b);

    /*  UFEC_URX_URXCFGB0 = {2'b00, 3'b000, 1'b1, 5'b11111,5'b11111}); */
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGB0), 0x07FF);

    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGB1), 0x0000);

    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGC0), 0x01b3);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGC1), 0x005d);

    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA0), 0x2ef0);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA1), 0x0118);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA2), 0x4720);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA3), 0x0a58);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA4), 0x59e0);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA5), 0x03f4); 
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA7), 0x2a53);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA6), 0x318b);
  
    ten_hl_ufec_ed_config(module_id, 0, CS_TX_AND_RX, CS_ENABLE, ncols);
    ten_n40g_otnr4x_oacfg0_dsyhyst(module_id, 11);
    break;

  case (TEN_FEC_MODE_OTUkV_295):  /*  25%, 295/239 columns */
    ncols = 295 - 1;  /* 294 */
  
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGC0), 0x012b);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGC1), 0x0069);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA0), 0x2ef0);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA1), 0x0127);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA2), 0x4720);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA3), 0x0258);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA4), 0x5454);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA5), 0x1174);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA6), 0x59e0);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGA7), 0x07c0);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGB1), 0x0003);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, UTXCFGB0), 0x0000);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGB),  0x010b);
    
    /*  UFEC_URX_URXCFGB0 = {2'b00, 3'b000, 1'b1, 5'b11111,5'b11111}); */
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGB0), 0x07FF);
    
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGB1), 0x0000);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGC0), 0x012b);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGC1), 0x0069);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA0), 0x2ef0);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA1), 0x0127);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA2), 0x4720);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA3), 0x1258);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA4), 0x59e0);
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA5), 0x03c0); 
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA7), 0x2a34); 
    TEN_REG_WRITE(TEN_UFEC_REG_ADDR(pDev, 0, URXCFGA6), 0x319b);
    
    ten_hl_ufec_ed_config(module_id, 0, CS_TX_AND_RX, CS_ENABLE, ncols);
    ten_n40g_otnr4x_oacfg0_dsyhyst(module_id, 11);
    break;

  default:
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": customer_ufec_mode out of range.");
      rtn = CS_ERROR;
      break;
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_UFEC);

  return (rtn);
}


