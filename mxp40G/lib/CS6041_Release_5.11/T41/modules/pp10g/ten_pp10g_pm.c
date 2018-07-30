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
 * ten_pp10g_pm.c
 *
 * $Id: ten_pp10g_pm.c,v 1.14 2013/02/22 20:48:04 jccarlis Exp $
 *
 * API's for PP10G PM
 *
 */

#include "tenabo40.h"

cs_status _ten_ppblk_pm_sample_indir_cntr(cs_uint16 module_id,cs_uint16 blk_id,
                                          cs_uint16 access_wrd,
                                          cs_uint16 ACCESS_ACC_MASK,
                                          cs_uint16 ACCESS_CNTR_MASK,
                                          volatile cs_reg *p_access_reg,
                                          volatile cs_reg *p_data0_reg,
                                          volatile cs_reg *p_data1_reg,
                                          volatile cs_reg *p_data2_reg,
                                          cs_uint16 delay, cs_uint16 timeout,
                                          cs_uint32 *cnt_ms, cs_uint32 *cnt_ls);

/********************************************************************/
/* $rtn_hdr_start  PP10G PM RESET                                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pm_reset(cs_uint16 module_id, cs_uint8 slice,
                             cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a logic reset of PP10G PM.                              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
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
  TEN_PP10G_PM_CTRL_t tmp_pm_ctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pm_ctrl.wrd = 0;
      tmp_pm_ctrl.bf.rst = 1;
      ten_reset_action(TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, sl, CTRL),
                       tmp_pm_ctrl.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PM CONTROL                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pm_control(cs_uint16 module_id, cs_uint8 slice,
                        cs_uint16 sel_tick1sec,
                        cs_uint16 mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Sel Tick1sec                                      */
/*              o Mode                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various aspects of the PM Control.                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [sel_tick1sec]   This applies to mode=TICK.                    */
/*     Select which one of eight internal ticks is used as the      */
/*     source for the 1 second Performance Monitoring Tick.         */
/*     Also refer to API: ten_glb_misc_set_gsti                     */
/*     0 = Selects Global Statistics Unit 0 Time Interval Base      */
/*     1 = Selects Global Statistics Unit 1 Time Interval Base      */
/*     2 = Selects Global Statistics Unit 2 Time Interval Base      */
/*     3 = Selects Global Statistics Unit 3 Time Interval Base      */
/*     4 = Selects Global Statistics Unit 4 Time Interval Base      */
/*     5 = Selects Global Statistics Unit 5 Time Interval Base      */
/*     6 = Selects Global Statistics Unit 6 Time Interval Base      */
/*     7 = Selects Global Statistics Unit 7 Time Interval Base      */
/*                                                                  */
/*   [mode]  Configures the mode of operation for PM counters:      */
/*      1 = TICK Performance monitoring, counters are updated on    */
/*          every tick (1sec).                                      */
/*      0 = IEEE Performance monitoring, counters are of            */
/*          non-resetable, rollover type.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PM_CTRL_t tmp_pm_ctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pm_ctrl.wrd = TEN_REG_READ(TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, sl, CTRL));
      tmp_pm_ctrl.bf.sel_tick1sec = sel_tick1sec;
      tmp_pm_ctrl.bf.mode = mode;
      TEN_REG_WRITE(TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, sl, CTRL), tmp_pm_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PM CLEAR                                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pm_clear(cs_uint16 module_id, cs_uint8 slice,
                         cs_uint16 clear)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Clear                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the PM clear process.                                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [clear]  Applies to mode=IEEE or TICK.                         */
/*     Assert HIGH (1) to initiate the clear process.               */
/*     This bit self clears when the operation is done.             */
/*     For mode=TICK, this clears the current HW counter bank,      */
/*     the current CPU accessible counter bank is untouched by the  */
/*     clear process.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_status = CS_OK;
  cs_uint16 sl;
  TEN_PP10G_PM_CLEAR_t tmp_pm_clear;
  cs_uint32 msec_elapsed = 0;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  /* Bugzilla #   , suspend logging information during stats clear */
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  if (TEN_MOD_COMMON_VALIDATE_INTERNAL(module_id, &pDev) == CS_ERROR) {
    g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
    return (CS_ERROR);
  }
  
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pm_clear.wrd = TEN_REG_READ(TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, sl, CLEAR));
      tmp_pm_clear.bf.clear = clear;
      TEN_REG_WRITE(TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, sl, CLEAR), tmp_pm_clear.wrd);

      /* wait for self-clear */
      do {
        TEN_MDELAY(TEN_PP10G_MSEC_DELAY);
        msec_elapsed += TEN_PP10G_MSEC_DELAY;
        if (msec_elapsed >= TEN_PP10G_MSEC_TIMEOUT) {
          /* CS_HNDL_ERROR(module_id, ETEN_MOD_REG_ACCESS_TIMEOUT, ": timeout waiting for clear.");  */
          ret_status = CS_ERROR;
          break;
        }
        tmp_pm_clear.wrd = TEN_REG_READ(TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, sl, CLEAR));
      } while (tmp_pm_clear.bf.clear);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return (ret_status);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PM GET BUSY STATUS                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_boolean ten_pp10g_pm_get_busy_status(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE or FALSE                                       */
/* DESCRIPTION:                                                     */
/* Returns pm busy status.                                          */
/* Only applies when mode=TICK.  When the internal tick is asserted */
/* there is a nonzero delay in switching the PM counter bank.       */
/* This 'busy' bit asserted denotes that the tick has arrived,      */
/* but the switch has not happened yet.  Any CPU read access will   */
/* return all zeroes if busy is asserted.                           */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3).                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_PM_STATUS_t tmp_pm_status;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  tmp_pm_status.wrd = TEN_REG_READ(TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, slice, STATUS));
  return (tmp_pm_status.bf.busy == 1);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PM GET INIT DONE STATUS                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_boolean ten_pp10g_pm_get_init_done_status(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE or FALSE                                       */
/* DESCRIPTION:                                                     */
/* The memory array is auto initialized upon releasing the reset.   */
/* When asserted, this status indicates that initialization is      */
/* done.                                                            */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3).                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_PM_STATUS_t tmp_pm_status;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  tmp_pm_status.wrd = TEN_REG_READ(TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, slice, STATUS));
  return (tmp_pm_status.bf.init_done == 1);
}

/********************************************************************/
/* $rtn_hdr_start  PP-BLK PM SAMPLE INDIRECT COUNTER                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pm_sample_counter(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint32 cntr_id,
                                      cs_uint32 *cnt_ms, cs_uint32 *cnt_ls)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Counter Id                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 48-bit PM Counter.                                  */
/* DESCRIPTION:                                                     */
/* Reads the selected 48-bit PM counter and returns the sampled     */
/* value in two 32-bit segments, without applying any workarounds.  */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/* [cntr_id]  Refer the the header file ten_stats.h for the         */
/*   complete list of 136 PP10G PM Counters.                        */
/*   /design/sw/drivers/T41/modules/stats/ten_stats.h            */
/*                                                                  */
/* [cnt_ms]  Pointer to most significant 32 bits                    */
/*                                                                  */
/* [cnt_ls]  Pointer to least significant 32 bits.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_PM_STATS_ACCESS_t tmp_pm_stats_access;
  TEN_PP10G_PM_STATS_ACCESS_t access_bit_mask;
  TEN_PP10G_PM_STATS_ACCESS_t cntr_id_bit_mask;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;

  access_bit_mask.wrd = 0xFFFF;
  cntr_id_bit_mask.wrd = 0xFFFF;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (cntr_id >= TEN_PP10G_MAX_STAT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": stat out of range.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  /* when set logic HIGH an access is initiated.  */

  /* get access field bit mask */
  access_bit_mask.bf.access = 0; /* clear access bit(s) */
  access_bit_mask.wrd = ~access_bit_mask.wrd;
  /* get control id field bit mask */
  cntr_id_bit_mask.bf.cntr_id = 0; /* clear cntrid bits */
  cntr_id_bit_mask.wrd = ~cntr_id_bit_mask.wrd;

  /* when set logic HIGH an access is initiated.  */
  /* Bugzilla #30689, initialize to 0 */  
  tmp_pm_stats_access.wrd = 0;
  tmp_pm_stats_access.bf.access = 1;
  tmp_pm_stats_access.bf.cntr_id = cntr_id;

  rtn = _ten_ppblk_pm_sample_indir_cntr(module_id,TEN_ID_PP10G,
                                        tmp_pm_stats_access.wrd,
                                        access_bit_mask.wrd, cntr_id_bit_mask.wrd,
                TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, slice, STATS_ACCESS),
                TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, slice, STATS_DATA0 ),
                TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, slice, STATS_DATA1 ),
                TEN_PP10G_XGPM_REG_ADDR(pDev, module_id, slice, STATS_DATA2 ),
                                        TEN_PP10G_MSEC_DELAY,
                                        TEN_PP10G_MSEC_TIMEOUT,
                                        cnt_ms, cnt_ls);

  return (rtn);
}


/********************************************************************/
/* FUNCTION   : PPBLOCK PM SAMPLE INDIRECT COUNTER                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Private                                             */
/* BLOCK      : PP10G/PP40G                                         */
/* CHIP       : Tenabo                                              */
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Counter Id                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 48-bit PM Counter.                                  */
/* DESCRIPTION:                                                     */
/* Reads the selected 48-bit PM counter and returns the sampled     */
/* value in two 32-bit segments, without applying any workarounds.  */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/* [cntr_id]  Refer the the header file ten_stats.h for the         */
/*   complete list of 136 PP10G PM Counters.                        */
/*   /design/sw/drivers/T41/modules/stats/ten_stats.h            */
/*                                                                  */
/* [cnt_ms]  Pointer to most significant 32 bits                    */
/*                                                                  */
/* [cnt_ls]  Pointer to least significant 32 bits.                  */
/*                                                                  */
/********************************************************************/
cs_status _ten_ppblk_pm_sample_indir_cntr(cs_uint16 module_id,cs_uint16 blk_id,
                                          cs_uint16 access_wrd,
                                          cs_uint16 ACCESS_ACC_MASK,
                                          cs_uint16 ACCESS_CNTR_MASK,
                                          volatile cs_reg *p_access_reg,
                                          volatile cs_reg *p_data0_reg,
                                          volatile cs_reg *p_data1_reg,
                                          volatile cs_reg *p_data2_reg,
                                          cs_uint16 delay, cs_uint16 timeout,
                                          cs_uint32 *cnt_ms, cs_uint32 *cnt_ls)
{
  cs_uint16 tmp_pm_stats_access;
  cs_uint16 tmp_pm_stats_data2;
  cs_uint16 tmp_pm_stats_data1;
  cs_uint16 tmp_pm_stats_data0;
  cs_uint32 msec_elapsed = 0;
  cs_uint32 counter_val_ms = 0;
  cs_uint32 counter_val_ls = 0;
  cs_boolean waiting_for_clear;
  cs_status rtn = CS_OK;

  if (!(cnt_ms) || !(cnt_ls)) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Illegal pass-by-reference, block id %d", blk_id);
      /* bugzilla #24439, klocwork */
      return (CS_ERROR);
  }

  TEN_MOD_LOCK(module_id, blk_id);
  /* update access register with desired cntr id and access ctrl */
  tmp_pm_stats_access = TEN_REG_READ(p_access_reg);
  TEN_REG_WRITE(p_access_reg, (tmp_pm_stats_access & ~(ACCESS_ACC_MASK | ACCESS_CNTR_MASK) ) | access_wrd);

  /* the 'access' bit self clears when the operation is done */
  waiting_for_clear = TRUE;
  while (waiting_for_clear) {
    tmp_pm_stats_access = TEN_REG_READ(p_access_reg);
    if ( !(tmp_pm_stats_access & ACCESS_ACC_MASK)) {
       break;
    }
    TEN_MDELAY(delay);
    msec_elapsed += delay;
    if (msec_elapsed >= timeout) {
      /* CS_HNDL_ERROR(module_id, ETEN_MOD_REG_ACCESS_TIMEOUT, ": timeout waiting for clear, block_id %d.", blk_id); */
      waiting_for_clear = FALSE;
      rtn = CS_ERROR;
      break;
    }
  }
  
  if (waiting_for_clear) {
    tmp_pm_stats_data2 = TEN_REG_READ(p_data2_reg);
    counter_val_ms = (cs_uint32)tmp_pm_stats_data2;
    /* counter_val_ms = (access_wrd&0xFF)+0x3000; */

    tmp_pm_stats_data1 = TEN_REG_READ(p_data1_reg);
    counter_val_ls |= (cs_uint32)tmp_pm_stats_data1;
    /* counter_val_ls = (access_wrd&0xFF)+0x2000; */
    counter_val_ls <<= 16;

    tmp_pm_stats_data0 = TEN_REG_READ(p_data0_reg);
    counter_val_ls |= (cs_uint32)tmp_pm_stats_data0;
    /* counter_val_ls |= (access_wrd&0xFF)+0x1000; */
  }
  else
  {
    counter_val_ms = 0x0;
    counter_val_ls = 0x0;
  }

  *cnt_ms = counter_val_ms;
  *cnt_ls = counter_val_ls;

  /* CS_PRINT("cntr_id %d = 0x%08X%08X\n", cntr_id, counter_val_ms, counter_val_ls); */
  TEN_MOD_UNLOCK(module_id, blk_id);
  return (rtn);
}

/********************************************************************/
/* PP10G PM ADD 64                                                  */
/* Add two 64 bit numbers using only 32 bit  variables,             */
/* to support older compilers that cannot handle 64 bit variables.  */
/********************************************************************/
void ten_pp10g_pm_add64(cs_uint32 a_ms, cs_uint32 a_ls,
                        cs_uint32 b_ms, cs_uint32 b_ls,
                        cs_uint32 *result_ms, cs_uint32 *result_ls)
{
  cs_uint32 c_ls, c_ms;

  c_ls = a_ls + b_ls;
  c_ms = a_ms + b_ms;

  /* detect rollover */
  if ((c_ls < a_ls) || (c_ls < b_ls)) {
    c_ms++;
  }
  *result_ms = c_ms;
  *result_ls = c_ls;
}

/********************************************************************/
/* PP10G PM MUL 64                                                  */
/* Multiply two 64 bit numbers using only 32 bit variables,         */
/* to support older compilers that cannot handle 64 bit variables.  */
/********************************************************************/
void ten_pp10g_pm_mul64(cs_uint32 a_ms, cs_uint32 a_ls,
                        cs_uint32 b_ms, cs_uint32 b_ls,
                        cs_uint32 *result_ms, cs_uint32 *result_ls)
{
  cs_uint32 c_ls, c_ms;
  cs_uint32 d_ls, d_ms;
  cs_uint16 ii, jj;

  c_ls = 0;
  c_ms = 0;
  d_ls = 0;
  d_ms = 0;

  for (ii=0; ii < b_ms; ii++) {
    for (jj=0; jj<=0xFF; jj++) {
      ten_pp10g_pm_add64(c_ms, c_ls,
                         a_ms, a_ls,
                         &d_ms, &d_ls);
      c_ms = d_ms;
      c_ls = d_ls;
    }
  }
  for (jj=0; jj< b_ls; jj++) {
      ten_pp10g_pm_add64(c_ms, c_ls,
                         a_ms, a_ls,
                         &d_ms, &d_ls);
      c_ms = d_ms;
      c_ls = d_ls;
  }
  *result_ms = c_ms;
  *result_ls = c_ls;
}

/********************************************************************/
/* PP10G PM SUB 64                                                  */
/* Subtract two 64 bit numbers using only 32 bit variables,         */
/* to support older compilers that cannot handle 64 bit variables.  */
/********************************************************************/
void ten_pp10g_pm_sub64(cs_uint32 a_ms, cs_uint32 a_ls,
                        cs_uint32 b_ms, cs_uint32 b_ls,
                        cs_uint32 *result_ms, cs_uint32 *result_ls)
{
  if ((a_ls >= b_ls) && (a_ms >= b_ms)) {
    *result_ms = a_ms - b_ms;
    *result_ls = a_ls - b_ls;
  }
  else if ((a_ls < b_ls) && (a_ms > b_ms)) {
    /* borrow */
    *result_ms = a_ms - b_ms - 1;
    *result_ls = (0xFFFF - (b_ls - a_ls)) + 1;
  }
  else {
    /* counters can't be negative, so floor at 0 */
    *result_ms = 0;
    *result_ls = 0;
  }
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PM READ COUNTER                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pm_read_counter(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint32 cntr_id,
                                   cs_uint32 *counter_ms, cs_uint32 *counter_ls)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Counter Id                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 48-bit PM Counter.                                  */
/* DESCRIPTION:                                                     */
/* Reads the selected 48-bit PM counter and returns the value in    */
/* two 32-bit segments. This function is specifically for PP10G     */
/* indirect counters (accessed by id through access registers)      */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/* [cntr_id]  Refer the the header file ten_stats.h for the         */
/*   complete list of 136 PP10G PM Counters.                        */
/*   /design/sw/drivers/T41/modules/stats/ten_stats.h               */
/*                                                                  */
/* [cnt_ms]  Pointer to most significant 32 bits                    */
/*                                                                  */
/* [cnt_ls]  Pointer to least significant 32 bits.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_uint32 cnt_val_ms = 0;
  cs_uint32 cnt_val_ls = 0;
  #if 0
  cs_uint32 cnt_sum_ms = 0;
  cs_uint32 cnt_sum_ls = 0;
  cs_uint32 cnt_val_b_ms = 0;
  cs_uint32 cnt_val_b_ls = 0;
  TEN_XCON_GLB_ES_SOURCE_SELECT_0_t tmp_glb_es_source_select;
  TEN_PP10G_XGADJ_RX_CNTRL_t tmp_xgadj_rx_cntrl;
  TEN_PP10G_XGADJ_RX_CNTRL1_t tmp_xgadj_rx_cntrl1;
  TEN_PP10G_XGADJ_TX_CNTRL1_t tmp_xgadj_tx_cntrl1;
  #endif
  cs_uint16 workaround_applied = FALSE;
  #if 0
  cs_uint16 upstream_module_id = 0;
  cs_uint16 upstream_slice = 0;
  #endif

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (cntr_id >= TEN_PP10G_MAX_STAT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": stat out of range.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);


  if (!workaround_applied) {
    rtn |= ten_pp10g_pm_sample_counter(module_id, slice, cntr_id,
                                      &cnt_val_ms, &cnt_val_ls);
    /* CS_PRINT("%08X-%08X\n", cnt_val_ms, cnt_val_ls);  */
  }

  if (counter_ms) {
     *counter_ms = cnt_val_ms;
  }
  if (counter_ls) {
    *counter_ls = cnt_val_ls;
  }
  return (rtn);
}


/********************************************************************/
/* $rtn_hdr_start  PP40G PM READ COUNTER                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_pm_read_counter(cs_uint16 module_id, cs_uint32 cntr_id,
                                    cs_uint32 *cnt_ms, cs_uint32 *cnt_ls)
/* INPUTS     : o Module Id                                         */
/*              o Counter Id                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 48-bit PM Counter.                                  */
/* DESCRIPTION:                                                     */
/* Reads the selected 48-bit PM counter and returns the sampled     */
/* value in two 32-bit segments, without applying any workarounds.  */
/*                                                                  */
/* [cntr_id]  Refer the the header file ten_registers_public.h for  */
/*   the complete list of PP40G PM Counters.                        */
/*   /design/sw/drivers/T41/modules/ten_registers_public.h       */
/*                                                                  */
/* [cnt_ms]  Pointer to most significant 32 bits                    */
/* [cnt_ls]  Pointer to least significant 32 bits.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PM_STATS_ACCESS_t tmp_pm_stats_access;
  TEN_PP40G_PM_STATS_ACCESS_t access_bit_mask;
  TEN_PP40G_PM_STATS_ACCESS_t cntr_id_bit_mask;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;

  access_bit_mask.wrd = 0xFFFF;
  cntr_id_bit_mask.wrd = 0xFFFF;

  /* Bugzilla #26184, fix pp40g stats */
  if (cntr_id > TEN_PP40G_MAX_PM_STAT) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": stat out of range.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  /* get access field bit mask */
  access_bit_mask.bf.access = 0; /* clear access bit(s) */
  access_bit_mask.wrd = ~access_bit_mask.wrd;
  /* get dontrol id field bit mask */
  cntr_id_bit_mask.bf.cntr_id = 0; /* clear cntrid bits */
  cntr_id_bit_mask.wrd = ~cntr_id_bit_mask.wrd;

  /* when set logic HIGH an access is initiated.  */
  /* Bugzilla #26184, fix pp40g stats */
  tmp_pm_stats_access.wrd = 0;
  tmp_pm_stats_access.bf.access = 1;
  tmp_pm_stats_access.bf.cntr_id = cntr_id;

  rtn = _ten_ppblk_pm_sample_indir_cntr(module_id,TEN_ID_PP40G,
                                        tmp_pm_stats_access.wrd,
                                        access_bit_mask.wrd, cntr_id_bit_mask.wrd,
                     TEN_PP40G_REG_ADDR(pDev, module_id, STATS_ACCESS),
                     TEN_PP40G_REG_ADDR(pDev, module_id, STATS_DATA0 ),
                     TEN_PP40G_REG_ADDR(pDev, module_id, STATS_DATA1 ),
                     TEN_PP40G_REG_ADDR(pDev, module_id, STATS_DATA2 ),
                                        TEN_PP40G_MSEC_DELAY,
                                        TEN_PP40G_MSEC_TIMEOUT,
                                        cnt_ms, cnt_ls);

  return (rtn);
}


