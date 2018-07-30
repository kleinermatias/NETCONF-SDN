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
 * ten_synsdsync_rx.c
 *
 * $Id: ten_syncdsync_rx.c,v 1.9 2013/02/22 20:50:01 jccarlis Exp $
 *
 * API's for SYNCDSYNC RX
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX CONFIG                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_cfg(cs_uint16 module_id,
                              cs_uint8  slice, 
                              cs_uint32 numerator_ms,
                              cs_uint32 numerator_ls,
                              cs_uint32 denominator_ms,
                              cs_uint32 denominator_ls,
                              cs_uint32 ac1_ms,
                              cs_uint32 ac1_ls,
                              cs_uint32 ac2_ms,
                              cs_uint32 ac2_ls,
                              cs_uint32 ad1,
                              cs_uint32 ad2,
                              cs_uint16 cfg_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures RX side of the syncdsync block.                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_syncdsyncrx_cfg, %s, %s\n", ten_module_strings[module_id&1], ten_slice_strings[slice]);
  CS_PRINT("    NUMERATOR_MS        = 0x%04X\n", numerator_ms);
  CS_PRINT("    NUMERATOR_LS        = 0x%04X\n", numerator_ls);
  CS_PRINT("    DENOMINATOR_MS      = 0x%04X\n", denominator_ms);
  CS_PRINT("    DENOMINATOR_LS      = 0x%04X\n", denominator_ls);
  CS_PRINT("    AC1_MS              = 0x%04X\n", ac1_ms);
  CS_PRINT("    AC1_LS              = 0x%04X\n", ac1_ls);
  CS_PRINT("    AC2_MS              = 0x%04X\n", ac2_ms);
  CS_PRINT("    AC2_LS              = 0x%04X\n", ac2_ls);
  CS_PRINT("    AD1                 = 0x%04X\n", ad1);
  CS_PRINT("    AD2                 = 0x%04X\n", ad2);
  CS_PRINT("    CFG_MODE            = 0x%04X\n", cfg_mode);
  
  rtn |= ten_mpif_global_reset_syncdsync(dev_id, mod_num, slice, CS_RX, CS_RESET_TOGGLE);

  rtn |= ten_syncdsyncrx_control_sreset(module_id, slice, CS_RESET_ASSERT);

  rtn |= ten_syncdsyncrx_set_numerator(module_id, slice, 
                                       TEN_SYNCDSYNC_LOWER16(numerator_ms), 
                                       TEN_SYNCDSYNC_UPPER16(numerator_ls), 
                                       TEN_SYNCDSYNC_LOWER16(numerator_ls));

  rtn |= ten_syncdsyncrx_set_denominator(module_id, slice, 
                                         TEN_SYNCDSYNC_LOWER16(denominator_ms),
                                         TEN_SYNCDSYNC_UPPER16(denominator_ls),
                                         TEN_SYNCDSYNC_LOWER16(denominator_ls));

  rtn |= ten_syncdsyncrx_set_ac1(module_id, slice, 
                                 TEN_SYNCDSYNC_LOWER16(ac1_ms),
                                 TEN_SYNCDSYNC_UPPER16(ac1_ls),
                                 TEN_SYNCDSYNC_LOWER16(ac1_ls));
                                                   
  rtn |= ten_syncdsyncrx_set_ac2(module_id, slice, 
                                 TEN_SYNCDSYNC_LOWER16(ac2_ms),
                                 TEN_SYNCDSYNC_UPPER16(ac2_ls),
                                 TEN_SYNCDSYNC_LOWER16(ac2_ls));

  rtn |= ten_syncdsyncrx_set_ad1(module_id, slice,
                                 TEN_SYNCDSYNC_UPPER16(ad1),
                                 TEN_SYNCDSYNC_LOWER16(ad1));
                                                   
  rtn |= ten_syncdsyncrx_set_ad2(module_id, slice, 
                                 TEN_SYNCDSYNC_UPPER16(ad2),
                                 TEN_SYNCDSYNC_LOWER16(ad2));
  
  rtn |= ten_syncdsyncrx_set_mode(module_id, slice, cfg_mode);

  rtn |= ten_syncdsyncrx_control_sreset(module_id, slice, CS_RESET_DEASSERT);
  
  return (rtn);
}
 
 /****************************************************************
 * Perform a reset action on the specified register.            *
 ****************************************************************/
void ten_syncdsync_reset_action(volatile cs_reg *rst_reg, cs_uint16 bits,
                                cs_reset_action_t act)
{
  cs_uint16 rst;
  rst = TEN_REG_READ(rst_reg);

  switch (act) {
  case CS_RESET_DEASSERT:
    rst &= ~bits;
    break;

  case CS_RESET_ASSERT:
    rst |= bits;
    break;

  case CS_RESET_TOGGLE:
    rst |= bits;
    TEN_REG_WRITE(rst_reg, rst);
    /* Bugzilla #22021, use default delay, causes issues if taken out */
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY); 
    rst &= ~bits;
    break;
  }
  TEN_REG_WRITE(rst_reg, rst);
  if (act != CS_RESET_ASSERT) {
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
  }
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SOFT (LOGIC) RESET                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_control_sreset(cs_uint16 module_id,
                                         cs_uint8 slice, 
                                         cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control SYNCDSYNC RX logic reset.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [act]  Reset option specified as CS_RESET_DEASSERT,            */
/*     CS_RESET_ASSERT or CS_RESET_TOGGLE.                          */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset bit(s) for 20 milliseconds and then de-assert.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGRX_CFG_t tmp_cfgrx_cfg;
  TEN_MPIF_GLOBAL_RESET_SYNCDSYNC_t tmp_global_reset_syncdsync;
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  CS_PRINT("module_id=0x%04X, slice=%d, action=%d\n", module_id, slice, act);
  
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      /* Bugzilla #22850, fix bus errors */
      tmp_global_reset_syncdsync.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SYNCDSYNC));
      tmp = (1 << (sl + (TEN_MOD_ID_TO_MOD_NUM(module_id)*4)));
      CS_PRINT("sl=%d, tmp=%04X\n", sl, tmp);
      if (tmp_global_reset_syncdsync.bf.rx & tmp) {
        CS_PRINT("WARNING:  MPIF_GLOBAL_RESET_SYNCDSYNC RX still in hard reset\n");
      }
      else {
        tmp_cfgrx_cfg.wrd = 0;
        tmp_cfgrx_cfg.bf.RESET_SW = 1; /* set mask */
        ten_reset_action(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, cfgrx_CFG), tmp_cfgrx_cfg.wrd, act);
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET MODE                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_mode(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint16 mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Mode                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Synchronizer and Desynchronizer Rx Configuration Mode.   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [mode]                                                         */
/*     (0) = OXU2(OPU2) client (monolithic dewrapping 1 level of    */
/*           justification)                                         */
/*     (1) = OXU3(OPU3) client (monolithic dewrapping 1 level of    */
/*           justification)                                         */
/*     (2) = OXU3(ODTU23) client (deagreggation 1 level of          */
/*           justification)                                         */
/*     (3) = OXU3(ODTU23) ODU2(OPU2) client (deagreggation 2 levels */
/*           of justification).                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGRX_CFG_t tmp_cfgrx_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgrx_cfg.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, cfgrx_CFG));
      tmp_cfgrx_cfg.bf.MODE = mode;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, cfgrx_CFG), tmp_cfgrx_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SELECT GLOBAL TIMING SOURCE          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_select_global_timing_source(cs_uint16 module_id, 
                                   cs_uint8 slice, 
                                   cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects one of the eight global timing sources.  Each event      */
/* generated by that source triggers copying of statistics          */
/* counters to the appropriate registers of the processor           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [select] 0-7.                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGMONRX_CFG_t tmp_cfgmonrx_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgmonrx_cfg.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, cfgmonrx_CFG));
      tmp_cfgmonrx_cfg.bf.EOFGCFG = select;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, cfgmonrx_CFG), tmp_cfgmonrx_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET NUMERATOR                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_numerator(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 numerator2,
                                          cs_uint16 numerator1,
                                          cs_uint16 numerator0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o NUMERATOR2                                        */
/*              o NUMERATOR1                                        */
/*              o NUMERATOR0                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* For applications involving a single level mapping this is the    */
/* number of client bytes per OxUk frame in absence of asynchronous */
/* justifications (synchronous component).                          */
/* For applications involving two levels of mapping, this is the    */
/* product m = m1 * m2, where:                                      */
/* - m1 is the number of client bytes per ODTU23 frame in absence   */
/*   f asynchronous justifications (synchronous component)          */
/* - m2 is the number of client bytes per ODU2 frame in absence     */ 
/*   of asynchronous justifications (synchronous component).        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [numerator2] most significant bits                             */
/*                                                                  */
/*   [numerator1] middle significant bits                           */
/*                                                                  */
/*   [numerator2] least significant bits.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGRX_NUMERATOR2_t tmp_cfgrx_numerator2;
  TEN_SYNCDSYNCRX_CFGRX_NUMERATOR1_t tmp_cfgrx_numerator1;
  TEN_SYNCDSYNCRX_CFGRX_NUMERATOR0_t tmp_cfgrx_numerator0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgrx_numerator2.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR2));
      tmp_cfgrx_numerator2.bf.NUMERATOR2 = numerator2;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR2), tmp_cfgrx_numerator2.wrd);
      
      tmp_cfgrx_numerator1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR1));
      tmp_cfgrx_numerator1.bf.NUMERATOR1 = numerator1;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR1), tmp_cfgrx_numerator1.wrd);
     
      tmp_cfgrx_numerator0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR0));
      tmp_cfgrx_numerator0.bf.NUMERATOR0 = numerator0;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR0), tmp_cfgrx_numerator0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET DENOMINATOR                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_denominator(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 denominator2,
                                            cs_uint16 denominator1,
                                            cs_uint16 denominator0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DENOMINATOR2                                      */
/*              o DENOMINATOR1                                      */
/*              o DENOMINATOR0                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Number of bytes per OTN frame multiplied by k (n*k).             */
/* For applications involving a single level of mapping, n is the   */
/* number of bytes per OxUk frame.                                  */
/* For applications involving two levels of mapping, this is the    */
/* product n = n1 * n2, where:                                      */
/* - n1 is the number of bytes per OxU3 frame                       */
/* - n2 is the number of client bytes per ODU2 frame.               */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [denominator2]  most significant bits                          */
/*                                                                  */
/*   [denominator1]  middle significant bits                        */
/*                                                                  */
/*   [denominator0]  least significant bits.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGRX_DENOMINATOR2_t tmp_cfgrx_denominator2;
  TEN_SYNCDSYNCRX_CFGRX_DENOMINATOR1_t tmp_cfgrx_denominator1;
  TEN_SYNCDSYNCRX_CFGRX_DENOMINATOR0_t tmp_cfgrx_denominator0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgrx_denominator2.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev,
                                   module_id, sl, DENOMINATOR2));
      tmp_cfgrx_denominator2.bf.DENOMINATOR2 = denominator2;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, DENOMINATOR2), 
                                             tmp_cfgrx_denominator2.wrd);
      
       tmp_cfgrx_denominator1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, 
                                    module_id, sl, DENOMINATOR1));
      tmp_cfgrx_denominator1.bf.DENOMINATOR1 = denominator1;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, DENOMINATOR1), 
                                             tmp_cfgrx_denominator1.wrd);
      
      tmp_cfgrx_denominator0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, 
                                   module_id, sl, DENOMINATOR0));
      tmp_cfgrx_denominator0.bf.DENOMINATOR0 = denominator0;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, DENOMINATOR0), 
                                             tmp_cfgrx_denominator0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET AC1                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_ac1(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 ac12,
                                    cs_uint16 ac11,
                                    cs_uint16 ac10)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o AC12                                              */
/*              o AC11                                              */
/*              o AC10                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This parameter is only used by applications involving two levels */
/* of asynchronous mapping.  In order to ensure proper operation,   */
/* the AC1 parameter must be configured as n1 * m2, where:          */
/* - n1 is the number of bytes per OxU3 frame                       */
/* - m2 is the number of client bytes per ODU2 frame in absence     */
/*   of asynchronous justifications (synchronous component).        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ac12]  most significant bits                                  */
/*                                                                  */
/*   [ac11]  middle significant bits                                */
/*                                                                  */
/*   [ac10]  least significant bits.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGRX_AC12_t tmp_cfgrx_ac12;
  TEN_SYNCDSYNCRX_CFGRX_AC11_t tmp_cfgrx_ac11;
  TEN_SYNCDSYNCRX_CFGRX_AC10_t tmp_cfgrx_ac10;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgrx_ac12.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC12));
      tmp_cfgrx_ac12.bf.AC12 = ac12;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC12), tmp_cfgrx_ac12.wrd);
     
      tmp_cfgrx_ac11.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC11));
      tmp_cfgrx_ac11.bf.AC11 = ac11;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC11), tmp_cfgrx_ac11.wrd);
     
      tmp_cfgrx_ac10.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC10));
      tmp_cfgrx_ac10.bf.AC10 = ac10;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC10), tmp_cfgrx_ac10.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET AC2                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_ac2(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 ac22,
                                    cs_uint16 ac21, 
                                    cs_uint16 ac20)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o AC22                                              */
/*              o AC21                                              */
/*              o AC20                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This parameter is only used by applications involving            */
/* asynchronous mapping (one or two levels of mapping).             */
/* In order to ensure proper operation, the AC2 parameter must be   */
/* configured as n:                                                 */
/* For applications involving a single level of mapping, n is the   */
/* number of bytes per OxUk frame.                                  */
/* For applications involving two levels of mapping, this is the    */
/* product n = n1 * n2, where:                                      */
/* - n1 is the number of bytes per OxU3 frame                       */
/* - n2 is the number of client bytes per ODU2 frame.               */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ac22]  most significant bits                                  */
/*                                                                  */
/*   [ac21]  middle significant bits                                */
/*                                                                  */
/*   [ac20]  least significant 16 bits.                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGRX_AC22_t tmp_cfgrx_ac22;
  TEN_SYNCDSYNCRX_CFGRX_AC21_t tmp_cfgrx_ac21;
  TEN_SYNCDSYNCRX_CFGRX_AC20_t tmp_cfgrx_ac20;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgrx_ac22.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC22));
      tmp_cfgrx_ac22.bf.AC22 = ac22;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC22), tmp_cfgrx_ac22.wrd);
      
      tmp_cfgrx_ac21.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC21));
      tmp_cfgrx_ac21.bf.AC21 = ac21;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC21), tmp_cfgrx_ac21.wrd);
      
      tmp_cfgrx_ac20.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC20));
      tmp_cfgrx_ac20.bf.AC20 = ac20;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC20), tmp_cfgrx_ac20.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET AD1                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_ad1(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 ad11,
                                    cs_uint16 ad10)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o AD11                                              */
/*              o AD10                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This parameter is only used by applications involving two levels */
/* of asynchronous mapping. In order to ensure proper operation,    */
/* the AD1 parameter must be configured as m2 * dr1, where:         */
/* - m2 is the number of client bytes per ODU2 frame in absence     */
/*   of asynchronous justifications (synchronous component)         */
/* - dr1 is the maximum number of positive justifications used by   */
/*   the ODTU23 structure: 4*1, 4*2, 4*3, ..., or 4*6.              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ad11]  most significant bits                                  */
/*                                                                  */
/*   [ad10]  least significant bits.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGRX_AD11_t tmp_cfgrx_ad11;
  TEN_SYNCDSYNCRX_CFGRX_AD10_t tmp_cfgrx_ad10;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgrx_ad11.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD11));
      tmp_cfgrx_ad11.bf.AD11 = ad11;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD11), tmp_cfgrx_ad11.wrd);
      
      tmp_cfgrx_ad10.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD10));
      tmp_cfgrx_ad10.bf.AD10 = ad10;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD10), tmp_cfgrx_ad10.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET AD2                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_ad2(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 ad21,
                                  cs_uint16 ad20)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o AD21                                              */
/*              o AD20                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This parameter is only used by applications involving            */
/* asynchronous mapping (one or two levels of mapping).  In order   */
/* to ensure proper operation, the AD2 parameter must be configured */
/* as follows:                                                      */
/* For applications involving a single level of mapping, AD2 must   */
/* be configured as dr, where dr is the maximum number of positive  */
/* justifications:                                                  */
/* - dr = 1, 2, 3, ... or 6 for applications using a single level   */ 
/*   of mapping over OxU2                                           */
/* - dr = 4*1, 4*2, 4*3, ... or 4*6 for applications using a single */
/*   level of mapping over OxU3                                     */
/* - dr = 4*1, 4*2, 4*3, ... or 4*6 for applications using a single */
/*   level of mapping over ODTU23                                   */
/* For applications involving two levels of mapping, AD2 must be    */
/* configured as m1*dr2, where:                                     */
/* - m1 is the number of client bytes per ODTU23 structure in       */
/* absence of asynchronous justifications (synchronous component)   */
/* - dr2 is the number positive justifications used by the ODU2     */
/* frame: 1, 2, 3, ..., or 6.                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ad21]  most significant bits                                  */
/*                                                                  */
/*   [ad20]  least significant bits.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGRX_AD21_t tmp_cfgrx_ad21;
  TEN_SYNCDSYNCRX_CFGRX_AD20_t tmp_cfgrx_ad20;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgrx_ad21.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD21));
      tmp_cfgrx_ad21.bf.AD21 = ad21;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD21), tmp_cfgrx_ad21.wrd);
      
      tmp_cfgrx_ad20.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD20));
      tmp_cfgrx_ad20.bf.AD20 = ad20;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD20), tmp_cfgrx_ad20.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET ODTU23 PJO THRESHOLD             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_odtu23_pjo_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 odtu23_pjo_th1,
                                              cs_uint16 odtu23_pjo_th0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o ODTU23 PJO TH1                                    */
/*              o ODTU23 PJO TH0                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the threshold for number of PJO to be compared with count   */
/* in ODU23_PJO and produce an interrupt if the threshold is        */
/* exceeded.                                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [odtu23_pjo_th1]  most significant bits                        */
/*                                                                  */
/*   [odtu23_pjo_th0]  least significant bits.                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_PJO_TH1_t tmp_cfgmonrx_odtu23_pjo_th1;
  TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_PJO_TH0_t tmp_cfgmonrx_odtu23_pjo_th0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgmonrx_odtu23_pjo_th1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev,
                                        module_id, sl, ODTU23_PJO_TH1));
      tmp_cfgmonrx_odtu23_pjo_th1.bf.ODTU23_PJO_TH1 = odtu23_pjo_th1;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO_TH1),
                    tmp_cfgmonrx_odtu23_pjo_th1.wrd);
                    
       tmp_cfgmonrx_odtu23_pjo_th0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, 
                                         module_id, sl, ODTU23_PJO_TH0));
      tmp_cfgmonrx_odtu23_pjo_th0.bf.ODTU23_PJO_TH0 = odtu23_pjo_th0;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO_TH0),
                    tmp_cfgmonrx_odtu23_pjo_th0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET ODTU23 NJO THRESHOLD             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_odtu23_njo_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 odtu23_njo_th1,
                                              cs_uint16 odtu23_njo_th0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o ODTU23 NJO TH1                                    */
/*              o ODTU23 NJO TH0                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the threshold for number of NJO to be compared with count   */
/* in ODU23_NJO and produce an interrupt if the threshold is        */
/* exceeded.                                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [odtu23_njo_th1]  most significant bits                        */
/*                                                                  */
/*   [odtu23_njo_th0]  least significant bits.                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_NJO_TH1_t tmp_cfgmonrx_odtu23_njo_th1;
  TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_NJO_TH0_t tmp_cfgmonrx_odtu23_njo_th0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgmonrx_odtu23_njo_th1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev,
                                        module_id, sl, ODTU23_NJO_TH1));
      tmp_cfgmonrx_odtu23_njo_th1.bf.ODTU23_NJO_TH1 = odtu23_njo_th1;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO_TH1),
                    tmp_cfgmonrx_odtu23_njo_th1.wrd);
                    
      tmp_cfgmonrx_odtu23_njo_th0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, 
                                        module_id, sl, ODTU23_NJO_TH0));
      tmp_cfgmonrx_odtu23_njo_th0.bf.ODTU23_NJO_TH0 = odtu23_njo_th0;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO_TH0),
                    tmp_cfgmonrx_odtu23_njo_th0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET OXUN PJO THRESHOLD               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_oxun_pjo_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 oxun_pjo_th1,
                                            cs_uint16 oxun_pjo_th0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o OXUN PJO TH1                                      */
/*              o OXUN PJO TH0                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the threshold for number of PJO to be compared with count   */
/* in OXUN_PJO and produce an interrupt if the threshold is         */
/* exceeded.                                                        */
/* Note 1: X denotes D when dewrapping ODU or T when                */
/* dewrapping OTU.  N denotes 2 when dewrapping OTU2/ODU2 or 3      */
/* when dewrapping OTU3/ODU3.                                       */
/* Note 2: OXUN_PJO_TH #3 A-side and #7 B-side are used for         */
/* monolithic OXU3 (ODU3 or OTU3).                                  */
/* OXUN_PJO_TH #0, 1 and 2 are not used.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [oxun_pjo_th1]  most significant bits                          */
/*                                                                  */
/*   [oxun_pjo_th0]  least significant bits.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGMONRX_OXUN_PJO_TH1_t tmp_cfgmonrx_oxun_pjo_th1;
  TEN_SYNCDSYNCRX_CFGMONRX_OXUN_PJO_TH0_t tmp_cfgmonrx_oxun_pjo_th0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgmonrx_oxun_pjo_th1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev,
                                      module_id, sl, OXUN_PJO_TH1));
      tmp_cfgmonrx_oxun_pjo_th1.bf.OXUN_PJO_TH1 = oxun_pjo_th1;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_PJO_TH1),
                    tmp_cfgmonrx_oxun_pjo_th1.wrd);
      
      tmp_cfgmonrx_oxun_pjo_th0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, 
                                      module_id, sl, OXUN_PJO_TH0));
      tmp_cfgmonrx_oxun_pjo_th0.bf.OXUN_PJO_TH0 = oxun_pjo_th0;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_PJO_TH0),
                    tmp_cfgmonrx_oxun_pjo_th0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCRX SET OXUN NJO THRESHOLD               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsyncrx_set_oxun_njo_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 oxun_njo_th1,
                                            cs_uint16 oxun_njo_th0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o OXUN NJO TH1                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the threshold for number of NJO to be compared with count   */
/* in OXUN_NJO and produce an interrupt if the threshold is         */
/* exceeded.  Note 1: X denotes D when dewrapping ODU or T when     */
/* dewrapping OTU.  N denotes 2 when dewrapping OTU2/ODU2 or 3      */
/* when dewrapping OTU3/ODU3.  Note 2: OXUN_NJO_TH #3 A-side and #7 */
/* B-side are used for monolithic OXU3 (ODU3 or OTU3).              */
/* OXUN_NJO_TH #0, 1 and 2 are not used.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [oxun_njo_th1]  most significant bits                          */
/*                                                                  */
/*   [oxun_njo_th0]  least significant bits.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCRX_CFGMONRX_OXUN_NJO_TH1_t tmp_cfgmonrx_oxun_njo_th1;
  TEN_SYNCDSYNCRX_CFGMONRX_OXUN_NJO_TH0_t tmp_cfgmonrx_oxun_njo_th0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgmonrx_oxun_njo_th1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev,
                                      module_id, sl, OXUN_NJO_TH1));
      tmp_cfgmonrx_oxun_njo_th1.bf.OXUN_NJO_TH1 = oxun_njo_th1;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_NJO_TH1),
                    tmp_cfgmonrx_oxun_njo_th1.wrd);
      
      tmp_cfgmonrx_oxun_njo_th0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, 
                                      module_id, sl, OXUN_NJO_TH0));
      tmp_cfgmonrx_oxun_njo_th0.bf.OXUN_NJO_TH0 = oxun_njo_th0;
      TEN_REG_WRITE(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_NJO_TH0),
                    tmp_cfgmonrx_oxun_njo_th0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}


