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
 * ten_hl_mpif.c
 *
 * APIs for debugging syncdsync
 *
 * $Id: ten_debug_syncdsync.c,v 1.21 2013/03/05 16:11:53 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC DUMP SETTINGS                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_syncdsync_dump_settings(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current SYNCDSYNC settings.                             */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  cs_uint16 sl;
  TEN_SYNCDSYNCTX_t *dft_syncdsync_tx;
  TEN_SYNCDSYNCTX_t *tmp_syncdsync_tx;
  TEN_SYNCDSYNCRX_t *dft_syncdsync_rx;
  TEN_SYNCDSYNCRX_t *tmp_syncdsync_rx;
  cs_char8 ch1, ch2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  } 
  
  dft_syncdsync_tx = (TEN_SYNCDSYNCTX_t *)CS_MALLOC(sizeof(TEN_SYNCDSYNCTX_t));
  tmp_syncdsync_tx = (TEN_SYNCDSYNCTX_t *)CS_MALLOC(sizeof(TEN_SYNCDSYNCTX_t));
  
  /* Bug #38811: Debug APIs need malloc check for Klocwork warning */
  if ((tmp_syncdsync_tx == 0) || (dft_syncdsync_tx == 0)) {
    if (tmp_syncdsync_tx) {
      CS_FREE(tmp_syncdsync_tx);
    }
    if (dft_syncdsync_tx) {
      CS_FREE(dft_syncdsync_tx);
    }
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  dft_syncdsync_rx = (TEN_SYNCDSYNCRX_t *)CS_MALLOC(sizeof(TEN_SYNCDSYNCRX_t));
  tmp_syncdsync_rx = (TEN_SYNCDSYNCRX_t *)CS_MALLOC(sizeof(TEN_SYNCDSYNCRX_t));
  
  /* Bug #38811: Debug APIs need malloc check for Klocwork warning */
  if ((tmp_syncdsync_rx == 0) || (dft_syncdsync_rx == 0)) {
    if (tmp_syncdsync_rx) {
      CS_FREE(tmp_syncdsync_rx);
    }
    if (dft_syncdsync_rx) {
      CS_FREE(dft_syncdsync_rx);
    }
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  dft_syncdsync_rx->NUMERATOR2.wrd = TEN_SYNCDSYNCRX_CFGRX_NUMERATOR2_dft;
  dft_syncdsync_rx->NUMERATOR1.wrd = TEN_SYNCDSYNCRX_CFGRX_NUMERATOR1_dft;
  dft_syncdsync_rx->NUMERATOR0.wrd = TEN_SYNCDSYNCRX_CFGRX_NUMERATOR0_dft;
  dft_syncdsync_rx->DENOMINATOR2.wrd = TEN_SYNCDSYNCRX_CFGRX_DENOMINATOR2_dft;
  dft_syncdsync_rx->DENOMINATOR1.wrd = TEN_SYNCDSYNCRX_CFGRX_DENOMINATOR1_dft;
  dft_syncdsync_rx->DENOMINATOR0.wrd = TEN_SYNCDSYNCRX_CFGRX_DENOMINATOR0_dft;
  dft_syncdsync_rx->AC12.wrd = TEN_SYNCDSYNCRX_CFGRX_AC12_dft;
  dft_syncdsync_rx->AC11.wrd = TEN_SYNCDSYNCRX_CFGRX_AC11_dft;
  dft_syncdsync_rx->AC10.wrd = TEN_SYNCDSYNCRX_CFGRX_AC10_dft;
  dft_syncdsync_rx->AC22.wrd = TEN_SYNCDSYNCRX_CFGRX_AC22_dft;
  dft_syncdsync_rx->AC21.wrd = TEN_SYNCDSYNCRX_CFGRX_AC21_dft;
  dft_syncdsync_rx->AC20.wrd = TEN_SYNCDSYNCRX_CFGRX_AC20_dft;
  dft_syncdsync_rx->AD11.wrd = TEN_SYNCDSYNCRX_CFGRX_AD11_dft;
  dft_syncdsync_rx->AD10.wrd = TEN_SYNCDSYNCRX_CFGRX_AD10_dft;
  dft_syncdsync_rx->AD21.wrd = TEN_SYNCDSYNCRX_CFGRX_AD21_dft;
  dft_syncdsync_rx->AD20.wrd = TEN_SYNCDSYNCRX_CFGRX_AD20_dft;
  dft_syncdsync_rx->cfgrx_CFG.wrd = TEN_SYNCDSYNCRX_CFGRX_CFG_dft;
  dft_syncdsync_rx->cfgmonrx_CFG.wrd = TEN_SYNCDSYNCRX_CFGMONRX_CFG_dft;
  dft_syncdsync_rx->ODTU23_PJO_TH1.wrd = TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_PJO_TH1_dft;
  dft_syncdsync_rx->ODTU23_PJO_TH0.wrd = TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_PJO_TH0_dft;
  dft_syncdsync_rx->ODTU23_NJO_TH1.wrd = TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_NJO_TH1_dft;
  dft_syncdsync_rx->ODTU23_NJO_TH0.wrd = TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_NJO_TH0_dft;
  dft_syncdsync_rx->OXUN_PJO_TH1.wrd = TEN_SYNCDSYNCRX_CFGMONRX_OXUN_PJO_TH1_dft;
  dft_syncdsync_rx->OXUN_PJO_TH0.wrd = TEN_SYNCDSYNCRX_CFGMONRX_OXUN_PJO_TH0_dft;
  dft_syncdsync_rx->OXUN_NJO_TH1.wrd = TEN_SYNCDSYNCRX_CFGMONRX_OXUN_NJO_TH1_dft;
  dft_syncdsync_rx->OXUN_NJO_TH0.wrd = TEN_SYNCDSYNCRX_CFGMONRX_OXUN_NJO_TH0_dft;
  dft_syncdsync_rx->ODTU23_PJO1.wrd = TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_PJO1_dft;
  dft_syncdsync_rx->ODTU23_PJO0.wrd = TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_PJO0_dft;
  dft_syncdsync_rx->ODTU23_NJO1.wrd = TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_NJO1_dft;
  dft_syncdsync_rx->ODTU23_NJO0.wrd = TEN_SYNCDSYNCRX_CFGMONRX_ODTU23_NJO0_dft;
  dft_syncdsync_rx->OXUN_PJO1.wrd = TEN_SYNCDSYNCRX_CFGMONRX_OXUN_PJO1_dft;
  dft_syncdsync_rx->OXUN_PJO0.wrd = TEN_SYNCDSYNCRX_CFGMONRX_OXUN_PJO0_dft;
  dft_syncdsync_rx->OXUN_NJO1.wrd = TEN_SYNCDSYNCRX_CFGMONRX_OXUN_NJO1_dft;
  dft_syncdsync_rx->OXUN_NJO0.wrd = TEN_SYNCDSYNCRX_CFGMONRX_OXUN_NJO0_dft;
  dft_syncdsync_rx->INT.wrd = TEN_SYNCDSYNCRX_CFGMONRX_INT_dft;
  dft_syncdsync_rx->INTE.wrd = TEN_SYNCDSYNCRX_CFGMONRX_INTE_dft;
  dft_syncdsync_rx->INTZ.wrd = TEN_SYNCDSYNCRX_CFGMONRX_INTZ_dft;
  
  dft_syncdsync_tx->DENOMINATOR2.wrd = TEN_SYNCDSYNCTX_CFGTX_DENOMINATOR2_dft;
  dft_syncdsync_tx->DENOMINATOR1.wrd = TEN_SYNCDSYNCTX_CFGTX_DENOMINATOR1_dft;
  dft_syncdsync_tx->DENOMINATOR0.wrd = TEN_SYNCDSYNCTX_CFGTX_DENOMINATOR0_dft;
  dft_syncdsync_tx->NUMERATOR2.wrd = TEN_SYNCDSYNCTX_CFGTX_NUMERATOR2_dft;
  dft_syncdsync_tx->NUMERATOR1.wrd = TEN_SYNCDSYNCTX_CFGTX_NUMERATOR1_dft;
  dft_syncdsync_tx->NUMERATOR0.wrd = TEN_SYNCDSYNCTX_CFGTX_NUMERATOR0_dft;
  dft_syncdsync_tx->AC12.wrd = TEN_SYNCDSYNCTX_CFGTX_AC12_dft;
  dft_syncdsync_tx->AC11.wrd = TEN_SYNCDSYNCTX_CFGTX_AC11_dft;
  dft_syncdsync_tx->AC10.wrd = TEN_SYNCDSYNCTX_CFGTX_AC10_dft;
  dft_syncdsync_tx->AC22.wrd = TEN_SYNCDSYNCTX_CFGTX_AC22_dft;
  dft_syncdsync_tx->AC21.wrd = TEN_SYNCDSYNCTX_CFGTX_AC21_dft;
  dft_syncdsync_tx->AC20.wrd = TEN_SYNCDSYNCTX_CFGTX_AC20_dft;
  dft_syncdsync_tx->AD11.wrd = TEN_SYNCDSYNCTX_CFGTX_AD11_dft;
  dft_syncdsync_tx->AD10.wrd = TEN_SYNCDSYNCTX_CFGTX_AD10_dft;
  dft_syncdsync_tx->AD21.wrd = TEN_SYNCDSYNCTX_CFGTX_AD21_dft;
  dft_syncdsync_tx->AD20.wrd = TEN_SYNCDSYNCTX_CFGTX_AD20_dft;
  dft_syncdsync_tx->cfgtx_CFG.wrd = TEN_SYNCDSYNCTX_CFGTX_CFG_dft;
  dft_syncdsync_tx->CFGPD0.wrd = TEN_SYNCDSYNCTX_CFGTX_CFGPD0_dft;
  dft_syncdsync_tx->CFGJCGEN.wrd = TEN_SYNCDSYNCTX_CFGTX_CFGJCGEN_dft;
  dft_syncdsync_tx->cfgmontx_CFG.wrd = TEN_SYNCDSYNCTX_CFGMONTX_CFG_dft;
  dft_syncdsync_tx->ODTU23_PJO_TH1.wrd = TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_PJO_TH1_dft;
  dft_syncdsync_tx->ODTU23_PJO_TH0.wrd = TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_PJO_TH0_dft;
  dft_syncdsync_tx->ODTU23_NJO_TH1.wrd = TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_NJO_TH1_dft;
  dft_syncdsync_tx->ODTU23_NJO_TH0.wrd = TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_NJO_TH0_dft;
  dft_syncdsync_tx->OXUN_PJO_TH1.wrd = TEN_SYNCDSYNCTX_CFGMONTX_OXUN_PJO_TH1_dft;
  dft_syncdsync_tx->OXUN_PJO_TH0.wrd = TEN_SYNCDSYNCTX_CFGMONTX_OXUN_PJO_TH0_dft;
  dft_syncdsync_tx->OXUN_NJO_TH1.wrd = TEN_SYNCDSYNCTX_CFGMONTX_OXUN_NJO_TH1_dft;
  dft_syncdsync_tx->OXUN_NJO_TH0.wrd = TEN_SYNCDSYNCTX_CFGMONTX_OXUN_NJO_TH0_dft;
  dft_syncdsync_tx->ODTU23_PJO1.wrd = TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_PJO1_dft;
  dft_syncdsync_tx->ODTU23_PJO0.wrd = TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_PJO0_dft;
  dft_syncdsync_tx->ODTU23_NJO1.wrd = TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_NJO1_dft;
  dft_syncdsync_tx->ODTU23_NJO0.wrd = TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_NJO0_dft;
  dft_syncdsync_tx->OXUN_PJO1.wrd = TEN_SYNCDSYNCTX_CFGMONTX_OXUN_PJO1_dft;
  dft_syncdsync_tx->OXUN_PJO0.wrd = TEN_SYNCDSYNCTX_CFGMONTX_OXUN_PJO0_dft;
  dft_syncdsync_tx->OXUN_NJO1.wrd = TEN_SYNCDSYNCTX_CFGMONTX_OXUN_NJO1_dft;
  dft_syncdsync_tx->OXUN_NJO0.wrd = TEN_SYNCDSYNCTX_CFGMONTX_OXUN_NJO0_dft;
  dft_syncdsync_tx->STAT.wrd = TEN_SYNCDSYNCTX_CFGMONTX_STAT_dft;
  dft_syncdsync_tx->INT.wrd = TEN_SYNCDSYNCTX_CFGMONTX_INT_dft;
  dft_syncdsync_tx->INTE.wrd = TEN_SYNCDSYNCTX_CFGMONTX_INTE_dft;
  dft_syncdsync_tx->INTZ.wrd = TEN_SYNCDSYNCTX_CFGMONTX_INTZ_dft;

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {

    tmp_syncdsync_rx->NUMERATOR2.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR2));
    tmp_syncdsync_rx->NUMERATOR1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR1));
    tmp_syncdsync_rx->NUMERATOR0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR0));
    tmp_syncdsync_rx->DENOMINATOR2.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, DENOMINATOR2));
    tmp_syncdsync_rx->DENOMINATOR1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, DENOMINATOR1));
    tmp_syncdsync_rx->DENOMINATOR0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, DENOMINATOR0));
    tmp_syncdsync_rx->AC12.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC12));
    tmp_syncdsync_rx->AC11.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC11));
    tmp_syncdsync_rx->AC10.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC10));
    tmp_syncdsync_rx->AC22.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC22));
    tmp_syncdsync_rx->AC21.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC21));
    tmp_syncdsync_rx->AC20.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC20));
    tmp_syncdsync_rx->AD11.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD11));
    tmp_syncdsync_rx->AD10.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD10));
    tmp_syncdsync_rx->AD21.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD21));
    tmp_syncdsync_rx->AD20.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD20));
    tmp_syncdsync_rx->cfgrx_CFG.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, cfgrx_CFG));
    tmp_syncdsync_rx->cfgmonrx_CFG.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, cfgmonrx_CFG));
    tmp_syncdsync_rx->ODTU23_PJO_TH1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO_TH1));
    tmp_syncdsync_rx->ODTU23_PJO_TH0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO_TH0));
    tmp_syncdsync_rx->ODTU23_NJO_TH1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO_TH1));
    tmp_syncdsync_rx->ODTU23_NJO_TH0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO_TH0));
    tmp_syncdsync_rx->OXUN_PJO_TH1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_PJO_TH1));
    tmp_syncdsync_rx->OXUN_PJO_TH0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_PJO_TH0));
    tmp_syncdsync_rx->OXUN_NJO_TH1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_NJO_TH1));
    tmp_syncdsync_rx->OXUN_NJO_TH0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_NJO_TH0));
    tmp_syncdsync_rx->ODTU23_PJO1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO1));
    tmp_syncdsync_rx->ODTU23_PJO0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO0));
    tmp_syncdsync_rx->ODTU23_NJO1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO1));
    tmp_syncdsync_rx->ODTU23_NJO0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO0));
    tmp_syncdsync_rx->OXUN_PJO1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_PJO1));
    tmp_syncdsync_rx->OXUN_PJO0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_PJO0));
    tmp_syncdsync_rx->OXUN_NJO1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_NJO1));
    tmp_syncdsync_rx->OXUN_NJO0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, OXUN_NJO0));
    tmp_syncdsync_rx->INT.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, INT));
    tmp_syncdsync_rx->INTE.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, INTE));
    tmp_syncdsync_rx->INTZ.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, INTZ));
   
    tmp_syncdsync_tx->DENOMINATOR2.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, DENOMINATOR2));
    tmp_syncdsync_tx->DENOMINATOR1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, DENOMINATOR1));
    tmp_syncdsync_tx->DENOMINATOR0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, DENOMINATOR0));
    tmp_syncdsync_tx->NUMERATOR2.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR2));
    tmp_syncdsync_tx->NUMERATOR1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR1));
    tmp_syncdsync_tx->NUMERATOR0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR0));
    tmp_syncdsync_tx->AC12.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC12));
    tmp_syncdsync_tx->AC11.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC11));
    tmp_syncdsync_tx->AC10.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC10));
    tmp_syncdsync_tx->AC22.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC22));
    tmp_syncdsync_tx->AC21.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC21));
    tmp_syncdsync_tx->AC20.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC20));
    tmp_syncdsync_tx->AD11.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD11));
    tmp_syncdsync_tx->AD10.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD10));
    tmp_syncdsync_tx->AD21.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD21));
    tmp_syncdsync_tx->AD20.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD20));
    tmp_syncdsync_tx->cfgtx_CFG.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG));
    tmp_syncdsync_tx->CFGPD0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, CFGPD0));
    tmp_syncdsync_tx->CFGJCGEN.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, CFGJCGEN));
    tmp_syncdsync_tx->cfgmontx_CFG.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgmontx_CFG));
    tmp_syncdsync_tx->ODTU23_PJO_TH1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO_TH1));
    tmp_syncdsync_tx->ODTU23_PJO_TH0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO_TH0));
    tmp_syncdsync_tx->ODTU23_NJO_TH1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO_TH1));
    tmp_syncdsync_tx->ODTU23_NJO_TH0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO_TH0));
    tmp_syncdsync_tx->OXUN_PJO_TH1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_PJO_TH1));
    tmp_syncdsync_tx->OXUN_PJO_TH0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_PJO_TH0));
    tmp_syncdsync_tx->OXUN_NJO_TH1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_NJO_TH1));
    tmp_syncdsync_tx->OXUN_NJO_TH0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_NJO_TH0));
    tmp_syncdsync_tx->ODTU23_PJO1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO1));
    tmp_syncdsync_tx->ODTU23_PJO0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO0));
    tmp_syncdsync_tx->ODTU23_NJO1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO1));
    tmp_syncdsync_tx->ODTU23_NJO0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO0));
    tmp_syncdsync_tx->OXUN_PJO1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_PJO1));
    tmp_syncdsync_tx->OXUN_PJO0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_PJO0));
    tmp_syncdsync_tx->OXUN_NJO1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_NJO1));
    tmp_syncdsync_tx->OXUN_NJO0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_NJO0));
    tmp_syncdsync_tx->STAT.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, STAT));
    tmp_syncdsync_tx->INT.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, INT));
    tmp_syncdsync_tx->INTE.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, INTE));
    tmp_syncdsync_tx->INTZ.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, INTZ));
 
    ch1 = (module_id & 1) ? 'B' : 'A';
    ch2 = sl + '0';
 
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_NUMERATOR2.wrd", tmp_syncdsync_rx->NUMERATOR2.wrd, tmp_syncdsync_rx->NUMERATOR2.wrd == dft_syncdsync_rx->NUMERATOR2.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->NUMERATOR2.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_NUMERATOR2.bf.NUMERATOR2", tmp_syncdsync_rx->NUMERATOR2.bf.NUMERATOR2, tmp_syncdsync_rx->NUMERATOR2.bf.NUMERATOR2 == dft_syncdsync_rx->NUMERATOR2.bf.NUMERATOR2 ? 0x20 : 0x2A, dft_syncdsync_rx->NUMERATOR2.bf.NUMERATOR2, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_NUMERATOR1.wrd", tmp_syncdsync_rx->NUMERATOR1.wrd, tmp_syncdsync_rx->NUMERATOR1.wrd == dft_syncdsync_rx->NUMERATOR1.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->NUMERATOR1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_NUMERATOR1.bf.NUMERATOR1", tmp_syncdsync_rx->NUMERATOR1.bf.NUMERATOR1, tmp_syncdsync_rx->NUMERATOR1.bf.NUMERATOR1 == dft_syncdsync_rx->NUMERATOR1.bf.NUMERATOR1 ? 0x20 : 0x2A, dft_syncdsync_rx->NUMERATOR1.bf.NUMERATOR1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_NUMERATOR0.wrd", tmp_syncdsync_rx->NUMERATOR0.wrd, tmp_syncdsync_rx->NUMERATOR0.wrd == dft_syncdsync_rx->NUMERATOR0.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->NUMERATOR0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_NUMERATOR0.bf.NUMERATOR0", tmp_syncdsync_rx->NUMERATOR0.bf.NUMERATOR0, tmp_syncdsync_rx->NUMERATOR0.bf.NUMERATOR0 == dft_syncdsync_rx->NUMERATOR0.bf.NUMERATOR0 ? 0x20 : 0x2A, dft_syncdsync_rx->NUMERATOR0.bf.NUMERATOR0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_DENOMINATOR2.wrd", tmp_syncdsync_rx->DENOMINATOR2.wrd, tmp_syncdsync_rx->DENOMINATOR2.wrd == dft_syncdsync_rx->DENOMINATOR2.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->DENOMINATOR2.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_DENOMINATOR2.bf.DENOMINATOR2", tmp_syncdsync_rx->DENOMINATOR2.bf.DENOMINATOR2, tmp_syncdsync_rx->DENOMINATOR2.bf.DENOMINATOR2 == dft_syncdsync_rx->DENOMINATOR2.bf.DENOMINATOR2 ? 0x20 : 0x2A, dft_syncdsync_rx->DENOMINATOR2.bf.DENOMINATOR2, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_DENOMINATOR1.wrd", tmp_syncdsync_rx->DENOMINATOR1.wrd, tmp_syncdsync_rx->DENOMINATOR1.wrd == dft_syncdsync_rx->DENOMINATOR1.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->DENOMINATOR1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_DENOMINATOR1.bf.DENOMINATOR1", tmp_syncdsync_rx->DENOMINATOR1.bf.DENOMINATOR1, tmp_syncdsync_rx->DENOMINATOR1.bf.DENOMINATOR1 == dft_syncdsync_rx->DENOMINATOR1.bf.DENOMINATOR1 ? 0x20 : 0x2A, dft_syncdsync_rx->DENOMINATOR1.bf.DENOMINATOR1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_DENOMINATOR0.wrd", tmp_syncdsync_rx->DENOMINATOR0.wrd, tmp_syncdsync_rx->DENOMINATOR0.wrd == dft_syncdsync_rx->DENOMINATOR0.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->DENOMINATOR0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_DENOMINATOR0.bf.DENOMINATOR0", tmp_syncdsync_rx->DENOMINATOR0.bf.DENOMINATOR0, tmp_syncdsync_rx->DENOMINATOR0.bf.DENOMINATOR0 == dft_syncdsync_rx->DENOMINATOR0.bf.DENOMINATOR0 ? 0x20 : 0x2A, dft_syncdsync_rx->DENOMINATOR0.bf.DENOMINATOR0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC12.wrd", tmp_syncdsync_rx->AC12.wrd, tmp_syncdsync_rx->AC12.wrd == dft_syncdsync_rx->AC12.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->AC12.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC12.bf.AC12", tmp_syncdsync_rx->AC12.bf.AC12, tmp_syncdsync_rx->AC12.bf.AC12 == dft_syncdsync_rx->AC12.bf.AC12 ? 0x20 : 0x2A, dft_syncdsync_rx->AC12.bf.AC12, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC11.wrd", tmp_syncdsync_rx->AC11.wrd, tmp_syncdsync_rx->AC11.wrd == dft_syncdsync_rx->AC11.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->AC11.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC11.bf.AC11", tmp_syncdsync_rx->AC11.bf.AC11, tmp_syncdsync_rx->AC11.bf.AC11 == dft_syncdsync_rx->AC11.bf.AC11 ? 0x20 : 0x2A, dft_syncdsync_rx->AC11.bf.AC11, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC10.wrd", tmp_syncdsync_rx->AC10.wrd, tmp_syncdsync_rx->AC10.wrd == dft_syncdsync_rx->AC10.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->AC10.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC10.bf.AC10", tmp_syncdsync_rx->AC10.bf.AC10, tmp_syncdsync_rx->AC10.bf.AC10 == dft_syncdsync_rx->AC10.bf.AC10 ? 0x20 : 0x2A, dft_syncdsync_rx->AC10.bf.AC10, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC22.wrd", tmp_syncdsync_rx->AC22.wrd, tmp_syncdsync_rx->AC22.wrd == dft_syncdsync_rx->AC22.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->AC22.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC22.bf.AC22", tmp_syncdsync_rx->AC22.bf.AC22, tmp_syncdsync_rx->AC22.bf.AC22 == dft_syncdsync_rx->AC22.bf.AC22 ? 0x20 : 0x2A, dft_syncdsync_rx->AC22.bf.AC22, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC21.wrd", tmp_syncdsync_rx->AC21.wrd, tmp_syncdsync_rx->AC21.wrd == dft_syncdsync_rx->AC21.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->AC21.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC21.bf.AC21", tmp_syncdsync_rx->AC21.bf.AC21, tmp_syncdsync_rx->AC21.bf.AC21 == dft_syncdsync_rx->AC21.bf.AC21 ? 0x20 : 0x2A, dft_syncdsync_rx->AC21.bf.AC21, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC20.wrd", tmp_syncdsync_rx->AC20.wrd, tmp_syncdsync_rx->AC20.wrd == dft_syncdsync_rx->AC20.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->AC20.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AC20.bf.AC20", tmp_syncdsync_rx->AC20.bf.AC20, tmp_syncdsync_rx->AC20.bf.AC20 == dft_syncdsync_rx->AC20.bf.AC20 ? 0x20 : 0x2A, dft_syncdsync_rx->AC20.bf.AC20, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AD11.wrd", tmp_syncdsync_rx->AD11.wrd, tmp_syncdsync_rx->AD11.wrd == dft_syncdsync_rx->AD11.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->AD11.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AD11.bf.AD11", tmp_syncdsync_rx->AD11.bf.AD11, tmp_syncdsync_rx->AD11.bf.AD11 == dft_syncdsync_rx->AD11.bf.AD11 ? 0x20 : 0x2A, dft_syncdsync_rx->AD11.bf.AD11, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AD10.wrd", tmp_syncdsync_rx->AD10.wrd, tmp_syncdsync_rx->AD10.wrd == dft_syncdsync_rx->AD10.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->AD10.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AD10.bf.AD10", tmp_syncdsync_rx->AD10.bf.AD10, tmp_syncdsync_rx->AD10.bf.AD10 == dft_syncdsync_rx->AD10.bf.AD10 ? 0x20 : 0x2A, dft_syncdsync_rx->AD10.bf.AD10, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AD21.wrd", tmp_syncdsync_rx->AD21.wrd, tmp_syncdsync_rx->AD21.wrd == dft_syncdsync_rx->AD21.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->AD21.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AD21.bf.AD21", tmp_syncdsync_rx->AD21.bf.AD21, tmp_syncdsync_rx->AD21.bf.AD21 == dft_syncdsync_rx->AD21.bf.AD21 ? 0x20 : 0x2A, dft_syncdsync_rx->AD21.bf.AD21, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AD20.wrd", tmp_syncdsync_rx->AD20.wrd, tmp_syncdsync_rx->AD20.wrd == dft_syncdsync_rx->AD20.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->AD20.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_AD20.bf.AD20", tmp_syncdsync_rx->AD20.bf.AD20, tmp_syncdsync_rx->AD20.bf.AD20 == dft_syncdsync_rx->AD20.bf.AD20 ? 0x20 : 0x2A, dft_syncdsync_rx->AD20.bf.AD20, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_CFG.wrd", tmp_syncdsync_rx->cfgrx_CFG.wrd, tmp_syncdsync_rx->cfgrx_CFG.wrd == dft_syncdsync_rx->cfgrx_CFG.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->cfgrx_CFG.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_CFG.bf.MODE", tmp_syncdsync_rx->cfgrx_CFG.bf.MODE, tmp_syncdsync_rx->cfgrx_CFG.bf.MODE == dft_syncdsync_rx->cfgrx_CFG.bf.MODE ? 0x20 : 0x2A, dft_syncdsync_rx->cfgrx_CFG.bf.MODE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGRX_CFG.bf.RESET_SW", tmp_syncdsync_rx->cfgrx_CFG.bf.RESET_SW, tmp_syncdsync_rx->cfgrx_CFG.bf.RESET_SW == dft_syncdsync_rx->cfgrx_CFG.bf.RESET_SW ? 0x20 : 0x2A, dft_syncdsync_rx->cfgrx_CFG.bf.RESET_SW, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_CFG.wrd", tmp_syncdsync_rx->cfgmonrx_CFG.wrd, tmp_syncdsync_rx->cfgmonrx_CFG.wrd == dft_syncdsync_rx->cfgmonrx_CFG.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->cfgmonrx_CFG.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_CFG.bf.EOFGCFG", tmp_syncdsync_rx->cfgmonrx_CFG.bf.EOFGCFG, tmp_syncdsync_rx->cfgmonrx_CFG.bf.EOFGCFG == dft_syncdsync_rx->cfgmonrx_CFG.bf.EOFGCFG ? 0x20 : 0x2A, dft_syncdsync_rx->cfgmonrx_CFG.bf.EOFGCFG, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_PJO_TH1.wrd", tmp_syncdsync_rx->ODTU23_PJO_TH1.wrd, tmp_syncdsync_rx->ODTU23_PJO_TH1.wrd == dft_syncdsync_rx->ODTU23_PJO_TH1.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_PJO_TH1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_PJO_TH1.bf.ODTU23_PJO_TH1", tmp_syncdsync_rx->ODTU23_PJO_TH1.bf.ODTU23_PJO_TH1, tmp_syncdsync_rx->ODTU23_PJO_TH1.bf.ODTU23_PJO_TH1 == dft_syncdsync_rx->ODTU23_PJO_TH1.bf.ODTU23_PJO_TH1 ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_PJO_TH1.bf.ODTU23_PJO_TH1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_PJO_TH0.wrd", tmp_syncdsync_rx->ODTU23_PJO_TH0.wrd, tmp_syncdsync_rx->ODTU23_PJO_TH0.wrd == dft_syncdsync_rx->ODTU23_PJO_TH0.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_PJO_TH0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_PJO_TH0.bf.ODTU23_PJO_TH0", tmp_syncdsync_rx->ODTU23_PJO_TH0.bf.ODTU23_PJO_TH0, tmp_syncdsync_rx->ODTU23_PJO_TH0.bf.ODTU23_PJO_TH0 == dft_syncdsync_rx->ODTU23_PJO_TH0.bf.ODTU23_PJO_TH0 ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_PJO_TH0.bf.ODTU23_PJO_TH0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_NJO_TH1.wrd", tmp_syncdsync_rx->ODTU23_NJO_TH1.wrd, tmp_syncdsync_rx->ODTU23_NJO_TH1.wrd == dft_syncdsync_rx->ODTU23_NJO_TH1.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_NJO_TH1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_NJO_TH1.bf.ODTU23_NJO_TH1", tmp_syncdsync_rx->ODTU23_NJO_TH1.bf.ODTU23_NJO_TH1, tmp_syncdsync_rx->ODTU23_NJO_TH1.bf.ODTU23_NJO_TH1 == dft_syncdsync_rx->ODTU23_NJO_TH1.bf.ODTU23_NJO_TH1 ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_NJO_TH1.bf.ODTU23_NJO_TH1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_NJO_TH0.wrd", tmp_syncdsync_rx->ODTU23_NJO_TH0.wrd, tmp_syncdsync_rx->ODTU23_NJO_TH0.wrd == dft_syncdsync_rx->ODTU23_NJO_TH0.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_NJO_TH0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_NJO_TH0.bf.ODTU23_NJO_TH0", tmp_syncdsync_rx->ODTU23_NJO_TH0.bf.ODTU23_NJO_TH0, tmp_syncdsync_rx->ODTU23_NJO_TH0.bf.ODTU23_NJO_TH0 == dft_syncdsync_rx->ODTU23_NJO_TH0.bf.ODTU23_NJO_TH0 ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_NJO_TH0.bf.ODTU23_NJO_TH0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_PJO_TH1.wrd", tmp_syncdsync_rx->OXUN_PJO_TH1.wrd, tmp_syncdsync_rx->OXUN_PJO_TH1.wrd == dft_syncdsync_rx->OXUN_PJO_TH1.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_PJO_TH1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_PJO_TH1.bf.OXUN_PJO_TH1", tmp_syncdsync_rx->OXUN_PJO_TH1.bf.OXUN_PJO_TH1, tmp_syncdsync_rx->OXUN_PJO_TH1.bf.OXUN_PJO_TH1 == dft_syncdsync_rx->OXUN_PJO_TH1.bf.OXUN_PJO_TH1 ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_PJO_TH1.bf.OXUN_PJO_TH1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_PJO_TH0.wrd", tmp_syncdsync_rx->OXUN_PJO_TH0.wrd, tmp_syncdsync_rx->OXUN_PJO_TH0.wrd == dft_syncdsync_rx->OXUN_PJO_TH0.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_PJO_TH0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_PJO_TH0.bf.OXUN_PJO_TH0", tmp_syncdsync_rx->OXUN_PJO_TH0.bf.OXUN_PJO_TH0, tmp_syncdsync_rx->OXUN_PJO_TH0.bf.OXUN_PJO_TH0 == dft_syncdsync_rx->OXUN_PJO_TH0.bf.OXUN_PJO_TH0 ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_PJO_TH0.bf.OXUN_PJO_TH0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_NJO_TH1.wrd", tmp_syncdsync_rx->OXUN_NJO_TH1.wrd, tmp_syncdsync_rx->OXUN_NJO_TH1.wrd == dft_syncdsync_rx->OXUN_NJO_TH1.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_NJO_TH1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_NJO_TH1.bf.OXUN_NJO_TH1", tmp_syncdsync_rx->OXUN_NJO_TH1.bf.OXUN_NJO_TH1, tmp_syncdsync_rx->OXUN_NJO_TH1.bf.OXUN_NJO_TH1 == dft_syncdsync_rx->OXUN_NJO_TH1.bf.OXUN_NJO_TH1 ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_NJO_TH1.bf.OXUN_NJO_TH1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_NJO_TH0.wrd", tmp_syncdsync_rx->OXUN_NJO_TH0.wrd, tmp_syncdsync_rx->OXUN_NJO_TH0.wrd == dft_syncdsync_rx->OXUN_NJO_TH0.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_NJO_TH0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_NJO_TH0.bf.OXUN_NJO_TH0", tmp_syncdsync_rx->OXUN_NJO_TH0.bf.OXUN_NJO_TH0, tmp_syncdsync_rx->OXUN_NJO_TH0.bf.OXUN_NJO_TH0 == dft_syncdsync_rx->OXUN_NJO_TH0.bf.OXUN_NJO_TH0 ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_NJO_TH0.bf.OXUN_NJO_TH0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_PJO1.wrd", tmp_syncdsync_rx->ODTU23_PJO1.wrd, tmp_syncdsync_rx->ODTU23_PJO1.wrd == dft_syncdsync_rx->ODTU23_PJO1.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_PJO1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_PJO1.bf.ODTU23_PJO1", tmp_syncdsync_rx->ODTU23_PJO1.bf.ODTU23_PJO1, tmp_syncdsync_rx->ODTU23_PJO1.bf.ODTU23_PJO1 == dft_syncdsync_rx->ODTU23_PJO1.bf.ODTU23_PJO1 ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_PJO1.bf.ODTU23_PJO1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_PJO0.wrd", tmp_syncdsync_rx->ODTU23_PJO0.wrd, tmp_syncdsync_rx->ODTU23_PJO0.wrd == dft_syncdsync_rx->ODTU23_PJO0.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_PJO0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_PJO0.bf.ODTU23_PJO0", tmp_syncdsync_rx->ODTU23_PJO0.bf.ODTU23_PJO0, tmp_syncdsync_rx->ODTU23_PJO0.bf.ODTU23_PJO0 == dft_syncdsync_rx->ODTU23_PJO0.bf.ODTU23_PJO0 ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_PJO0.bf.ODTU23_PJO0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_NJO1.wrd", tmp_syncdsync_rx->ODTU23_NJO1.wrd, tmp_syncdsync_rx->ODTU23_NJO1.wrd == dft_syncdsync_rx->ODTU23_NJO1.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_NJO1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_NJO1.bf.ODTU23_NJO1", tmp_syncdsync_rx->ODTU23_NJO1.bf.ODTU23_NJO1, tmp_syncdsync_rx->ODTU23_NJO1.bf.ODTU23_NJO1 == dft_syncdsync_rx->ODTU23_NJO1.bf.ODTU23_NJO1 ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_NJO1.bf.ODTU23_NJO1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_NJO0.wrd", tmp_syncdsync_rx->ODTU23_NJO0.wrd, tmp_syncdsync_rx->ODTU23_NJO0.wrd == dft_syncdsync_rx->ODTU23_NJO0.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_NJO0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_ODTU23_NJO0.bf.ODTU23_NJO0", tmp_syncdsync_rx->ODTU23_NJO0.bf.ODTU23_NJO0, tmp_syncdsync_rx->ODTU23_NJO0.bf.ODTU23_NJO0 == dft_syncdsync_rx->ODTU23_NJO0.bf.ODTU23_NJO0 ? 0x20 : 0x2A, dft_syncdsync_rx->ODTU23_NJO0.bf.ODTU23_NJO0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_PJO1.wrd", tmp_syncdsync_rx->OXUN_PJO1.wrd, tmp_syncdsync_rx->OXUN_PJO1.wrd == dft_syncdsync_rx->OXUN_PJO1.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_PJO1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_PJO1.bf.OXUN_PJO1", tmp_syncdsync_rx->OXUN_PJO1.bf.OXUN_PJO1, tmp_syncdsync_rx->OXUN_PJO1.bf.OXUN_PJO1 == dft_syncdsync_rx->OXUN_PJO1.bf.OXUN_PJO1 ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_PJO1.bf.OXUN_PJO1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_PJO0.wrd", tmp_syncdsync_rx->OXUN_PJO0.wrd, tmp_syncdsync_rx->OXUN_PJO0.wrd == dft_syncdsync_rx->OXUN_PJO0.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_PJO0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_PJO0.bf.OXUN_PJO0", tmp_syncdsync_rx->OXUN_PJO0.bf.OXUN_PJO0, tmp_syncdsync_rx->OXUN_PJO0.bf.OXUN_PJO0 == dft_syncdsync_rx->OXUN_PJO0.bf.OXUN_PJO0 ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_PJO0.bf.OXUN_PJO0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_NJO1.wrd", tmp_syncdsync_rx->OXUN_NJO1.wrd, tmp_syncdsync_rx->OXUN_NJO1.wrd == dft_syncdsync_rx->OXUN_NJO1.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_NJO1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_NJO1.bf.OXUN_NJO1", tmp_syncdsync_rx->OXUN_NJO1.bf.OXUN_NJO1, tmp_syncdsync_rx->OXUN_NJO1.bf.OXUN_NJO1 == dft_syncdsync_rx->OXUN_NJO1.bf.OXUN_NJO1 ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_NJO1.bf.OXUN_NJO1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_NJO0.wrd", tmp_syncdsync_rx->OXUN_NJO0.wrd, tmp_syncdsync_rx->OXUN_NJO0.wrd == dft_syncdsync_rx->OXUN_NJO0.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_NJO0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_OXUN_NJO0.bf.OXUN_NJO0", tmp_syncdsync_rx->OXUN_NJO0.bf.OXUN_NJO0, tmp_syncdsync_rx->OXUN_NJO0.bf.OXUN_NJO0 == dft_syncdsync_rx->OXUN_NJO0.bf.OXUN_NJO0 ? 0x20 : 0x2A, dft_syncdsync_rx->OXUN_NJO0.bf.OXUN_NJO0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INT.wrd", tmp_syncdsync_rx->INT.wrd, tmp_syncdsync_rx->INT.wrd == dft_syncdsync_rx->INT.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->INT.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INT.bf.OXUN_NJOI", tmp_syncdsync_rx->INT.bf.OXUN_NJOI, tmp_syncdsync_rx->INT.bf.OXUN_NJOI == dft_syncdsync_rx->INT.bf.OXUN_NJOI ? 0x20 : 0x2A, dft_syncdsync_rx->INT.bf.OXUN_NJOI, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INT.bf.OXUN_PJOI", tmp_syncdsync_rx->INT.bf.OXUN_PJOI, tmp_syncdsync_rx->INT.bf.OXUN_PJOI == dft_syncdsync_rx->INT.bf.OXUN_PJOI ? 0x20 : 0x2A, dft_syncdsync_rx->INT.bf.OXUN_PJOI, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INT.bf.ODTU23_NJOI", tmp_syncdsync_rx->INT.bf.ODTU23_NJOI, tmp_syncdsync_rx->INT.bf.ODTU23_NJOI == dft_syncdsync_rx->INT.bf.ODTU23_NJOI ? 0x20 : 0x2A, dft_syncdsync_rx->INT.bf.ODTU23_NJOI, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INT.bf.ODTU23_PJOI", tmp_syncdsync_rx->INT.bf.ODTU23_PJOI, tmp_syncdsync_rx->INT.bf.ODTU23_PJOI == dft_syncdsync_rx->INT.bf.ODTU23_PJOI ? 0x20 : 0x2A, dft_syncdsync_rx->INT.bf.ODTU23_PJOI, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INTE.wrd", tmp_syncdsync_rx->INTE.wrd, tmp_syncdsync_rx->INTE.wrd == dft_syncdsync_rx->INTE.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->INTE.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INTE.bf.OXUN_NJOIE", tmp_syncdsync_rx->INTE.bf.OXUN_NJOIE, tmp_syncdsync_rx->INTE.bf.OXUN_NJOIE == dft_syncdsync_rx->INTE.bf.OXUN_NJOIE ? 0x20 : 0x2A, dft_syncdsync_rx->INTE.bf.OXUN_NJOIE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INTE.bf.OXUN_PJOIE", tmp_syncdsync_rx->INTE.bf.OXUN_PJOIE, tmp_syncdsync_rx->INTE.bf.OXUN_PJOIE == dft_syncdsync_rx->INTE.bf.OXUN_PJOIE ? 0x20 : 0x2A, dft_syncdsync_rx->INTE.bf.OXUN_PJOIE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INTE.bf.ODTU23_NJOIE", tmp_syncdsync_rx->INTE.bf.ODTU23_NJOIE, tmp_syncdsync_rx->INTE.bf.ODTU23_NJOIE == dft_syncdsync_rx->INTE.bf.ODTU23_NJOIE ? 0x20 : 0x2A, dft_syncdsync_rx->INTE.bf.ODTU23_NJOIE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INTE.bf.ODTU23_PJOIE", tmp_syncdsync_rx->INTE.bf.ODTU23_PJOIE, tmp_syncdsync_rx->INTE.bf.ODTU23_PJOIE == dft_syncdsync_rx->INTE.bf.ODTU23_PJOIE ? 0x20 : 0x2A, dft_syncdsync_rx->INTE.bf.ODTU23_PJOIE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INTZ.wrd", tmp_syncdsync_rx->INTZ.wrd, tmp_syncdsync_rx->INTZ.wrd == dft_syncdsync_rx->INTZ.wrd ? 0x20 : 0x2A, dft_syncdsync_rx->INTZ.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INTZ.bf.OXUN_NJOIZ", tmp_syncdsync_rx->INTZ.bf.OXUN_NJOIZ, tmp_syncdsync_rx->INTZ.bf.OXUN_NJOIZ == dft_syncdsync_rx->INTZ.bf.OXUN_NJOIZ ? 0x20 : 0x2A, dft_syncdsync_rx->INTZ.bf.OXUN_NJOIZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INTZ.bf.OXUN_PJOIZ", tmp_syncdsync_rx->INTZ.bf.OXUN_PJOIZ, tmp_syncdsync_rx->INTZ.bf.OXUN_PJOIZ == dft_syncdsync_rx->INTZ.bf.OXUN_PJOIZ ? 0x20 : 0x2A, dft_syncdsync_rx->INTZ.bf.OXUN_PJOIZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INTZ.bf.ODTU23_NJOIZ", tmp_syncdsync_rx->INTZ.bf.ODTU23_NJOIZ, tmp_syncdsync_rx->INTZ.bf.ODTU23_NJOIZ == dft_syncdsync_rx->INTZ.bf.ODTU23_NJOIZ ? 0x20 : 0x2A, dft_syncdsync_rx->INTZ.bf.ODTU23_NJOIZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCRX_CFGMONRX_INTZ.bf.ODTU23_PJOIZ", tmp_syncdsync_rx->INTZ.bf.ODTU23_PJOIZ, tmp_syncdsync_rx->INTZ.bf.ODTU23_PJOIZ == dft_syncdsync_rx->INTZ.bf.ODTU23_PJOIZ ? 0x20 : 0x2A, dft_syncdsync_rx->INTZ.bf.ODTU23_PJOIZ, ch1, ch2);
   
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_DENOMINATOR2.wrd", tmp_syncdsync_tx->DENOMINATOR2.wrd, tmp_syncdsync_tx->DENOMINATOR2.wrd == dft_syncdsync_tx->DENOMINATOR2.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->DENOMINATOR2.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_DENOMINATOR2.bf.DENOMINATOR2", tmp_syncdsync_tx->DENOMINATOR2.bf.DENOMINATOR2, tmp_syncdsync_tx->DENOMINATOR2.bf.DENOMINATOR2 == dft_syncdsync_tx->DENOMINATOR2.bf.DENOMINATOR2 ? 0x20 : 0x2A, dft_syncdsync_tx->DENOMINATOR2.bf.DENOMINATOR2, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_DENOMINATOR1.wrd", tmp_syncdsync_tx->DENOMINATOR1.wrd, tmp_syncdsync_tx->DENOMINATOR1.wrd == dft_syncdsync_tx->DENOMINATOR1.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->DENOMINATOR1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_DENOMINATOR1.bf.DENOMINATOR1", tmp_syncdsync_tx->DENOMINATOR1.bf.DENOMINATOR1, tmp_syncdsync_tx->DENOMINATOR1.bf.DENOMINATOR1 == dft_syncdsync_tx->DENOMINATOR1.bf.DENOMINATOR1 ? 0x20 : 0x2A, dft_syncdsync_tx->DENOMINATOR1.bf.DENOMINATOR1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_DENOMINATOR0.wrd", tmp_syncdsync_tx->DENOMINATOR0.wrd, tmp_syncdsync_tx->DENOMINATOR0.wrd == dft_syncdsync_tx->DENOMINATOR0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->DENOMINATOR0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_DENOMINATOR0.bf.DENOMINATOR0", tmp_syncdsync_tx->DENOMINATOR0.bf.DENOMINATOR0, tmp_syncdsync_tx->DENOMINATOR0.bf.DENOMINATOR0 == dft_syncdsync_tx->DENOMINATOR0.bf.DENOMINATOR0 ? 0x20 : 0x2A, dft_syncdsync_tx->DENOMINATOR0.bf.DENOMINATOR0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_NUMERATOR2.wrd", tmp_syncdsync_tx->NUMERATOR2.wrd, tmp_syncdsync_tx->NUMERATOR2.wrd == dft_syncdsync_tx->NUMERATOR2.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->NUMERATOR2.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_NUMERATOR2.bf.NUMERATOR2", tmp_syncdsync_tx->NUMERATOR2.bf.NUMERATOR2, tmp_syncdsync_tx->NUMERATOR2.bf.NUMERATOR2 == dft_syncdsync_tx->NUMERATOR2.bf.NUMERATOR2 ? 0x20 : 0x2A, dft_syncdsync_tx->NUMERATOR2.bf.NUMERATOR2, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_NUMERATOR1.wrd", tmp_syncdsync_tx->NUMERATOR1.wrd, tmp_syncdsync_tx->NUMERATOR1.wrd == dft_syncdsync_tx->NUMERATOR1.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->NUMERATOR1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_NUMERATOR1.bf.NUMERATOR1", tmp_syncdsync_tx->NUMERATOR1.bf.NUMERATOR1, tmp_syncdsync_tx->NUMERATOR1.bf.NUMERATOR1 == dft_syncdsync_tx->NUMERATOR1.bf.NUMERATOR1 ? 0x20 : 0x2A, dft_syncdsync_tx->NUMERATOR1.bf.NUMERATOR1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_NUMERATOR0.wrd", tmp_syncdsync_tx->NUMERATOR0.wrd, tmp_syncdsync_tx->NUMERATOR0.wrd == dft_syncdsync_tx->NUMERATOR0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->NUMERATOR0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_NUMERATOR0.bf.NUMERATOR0", tmp_syncdsync_tx->NUMERATOR0.bf.NUMERATOR0, tmp_syncdsync_tx->NUMERATOR0.bf.NUMERATOR0 == dft_syncdsync_tx->NUMERATOR0.bf.NUMERATOR0 ? 0x20 : 0x2A, dft_syncdsync_tx->NUMERATOR0.bf.NUMERATOR0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC12.wrd", tmp_syncdsync_tx->AC12.wrd, tmp_syncdsync_tx->AC12.wrd == dft_syncdsync_tx->AC12.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->AC12.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC12.bf.AC12", tmp_syncdsync_tx->AC12.bf.AC12, tmp_syncdsync_tx->AC12.bf.AC12 == dft_syncdsync_tx->AC12.bf.AC12 ? 0x20 : 0x2A, dft_syncdsync_tx->AC12.bf.AC12, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC11.wrd", tmp_syncdsync_tx->AC11.wrd, tmp_syncdsync_tx->AC11.wrd == dft_syncdsync_tx->AC11.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->AC11.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC11.bf.AC11", tmp_syncdsync_tx->AC11.bf.AC11, tmp_syncdsync_tx->AC11.bf.AC11 == dft_syncdsync_tx->AC11.bf.AC11 ? 0x20 : 0x2A, dft_syncdsync_tx->AC11.bf.AC11, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC10.wrd", tmp_syncdsync_tx->AC10.wrd, tmp_syncdsync_tx->AC10.wrd == dft_syncdsync_tx->AC10.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->AC10.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC10.bf.AC10", tmp_syncdsync_tx->AC10.bf.AC10, tmp_syncdsync_tx->AC10.bf.AC10 == dft_syncdsync_tx->AC10.bf.AC10 ? 0x20 : 0x2A, dft_syncdsync_tx->AC10.bf.AC10, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC22.wrd", tmp_syncdsync_tx->AC22.wrd, tmp_syncdsync_tx->AC22.wrd == dft_syncdsync_tx->AC22.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->AC22.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC22.bf.AC22", tmp_syncdsync_tx->AC22.bf.AC22, tmp_syncdsync_tx->AC22.bf.AC22 == dft_syncdsync_tx->AC22.bf.AC22 ? 0x20 : 0x2A, dft_syncdsync_tx->AC22.bf.AC22, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC21.wrd", tmp_syncdsync_tx->AC21.wrd, tmp_syncdsync_tx->AC21.wrd == dft_syncdsync_tx->AC21.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->AC21.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC21.bf.AC21", tmp_syncdsync_tx->AC21.bf.AC21, tmp_syncdsync_tx->AC21.bf.AC21 == dft_syncdsync_tx->AC21.bf.AC21 ? 0x20 : 0x2A, dft_syncdsync_tx->AC21.bf.AC21, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC20.wrd", tmp_syncdsync_tx->AC20.wrd, tmp_syncdsync_tx->AC20.wrd == dft_syncdsync_tx->AC20.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->AC20.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AC20.bf.AC20", tmp_syncdsync_tx->AC20.bf.AC20, tmp_syncdsync_tx->AC20.bf.AC20 == dft_syncdsync_tx->AC20.bf.AC20 ? 0x20 : 0x2A, dft_syncdsync_tx->AC20.bf.AC20, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AD11.wrd", tmp_syncdsync_tx->AD11.wrd, tmp_syncdsync_tx->AD11.wrd == dft_syncdsync_tx->AD11.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->AD11.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AD11.bf.AD11", tmp_syncdsync_tx->AD11.bf.AD11, tmp_syncdsync_tx->AD11.bf.AD11 == dft_syncdsync_tx->AD11.bf.AD11 ? 0x20 : 0x2A, dft_syncdsync_tx->AD11.bf.AD11, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AD10.wrd", tmp_syncdsync_tx->AD10.wrd, tmp_syncdsync_tx->AD10.wrd == dft_syncdsync_tx->AD10.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->AD10.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AD10.bf.AD10", tmp_syncdsync_tx->AD10.bf.AD10, tmp_syncdsync_tx->AD10.bf.AD10 == dft_syncdsync_tx->AD10.bf.AD10 ? 0x20 : 0x2A, dft_syncdsync_tx->AD10.bf.AD10, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AD21.wrd", tmp_syncdsync_tx->AD21.wrd, tmp_syncdsync_tx->AD21.wrd == dft_syncdsync_tx->AD21.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->AD21.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AD21.bf.AD21", tmp_syncdsync_tx->AD21.bf.AD21, tmp_syncdsync_tx->AD21.bf.AD21 == dft_syncdsync_tx->AD21.bf.AD21 ? 0x20 : 0x2A, dft_syncdsync_tx->AD21.bf.AD21, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AD20.wrd", tmp_syncdsync_tx->AD20.wrd, tmp_syncdsync_tx->AD20.wrd == dft_syncdsync_tx->AD20.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->AD20.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_AD20.bf.AD20", tmp_syncdsync_tx->AD20.bf.AD20, tmp_syncdsync_tx->AD20.bf.AD20 == dft_syncdsync_tx->AD20.bf.AD20 ? 0x20 : 0x2A, dft_syncdsync_tx->AD20.bf.AD20, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFG.wrd", tmp_syncdsync_tx->cfgtx_CFG.wrd, tmp_syncdsync_tx->cfgtx_CFG.wrd == dft_syncdsync_tx->cfgtx_CFG.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->cfgtx_CFG.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFG.bf.GMP_ENABLE", tmp_syncdsync_tx->cfgtx_CFG.bf.GMP_ENABLE, tmp_syncdsync_tx->cfgtx_CFG.bf.GMP_ENABLE == dft_syncdsync_tx->cfgtx_CFG.bf.GMP_ENABLE ? 0x20 : 0x2A, dft_syncdsync_tx->cfgtx_CFG.bf.GMP_ENABLE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFG.bf.RX_DIV_MUX", tmp_syncdsync_tx->cfgtx_CFG.bf.RX_DIV_MUX, tmp_syncdsync_tx->cfgtx_CFG.bf.RX_DIV_MUX == dft_syncdsync_tx->cfgtx_CFG.bf.RX_DIV_MUX ? 0x20 : 0x2A, dft_syncdsync_tx->cfgtx_CFG.bf.RX_DIV_MUX, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFG.bf.MODE", tmp_syncdsync_tx->cfgtx_CFG.bf.MODE, tmp_syncdsync_tx->cfgtx_CFG.bf.MODE == dft_syncdsync_tx->cfgtx_CFG.bf.MODE ? 0x20 : 0x2A, dft_syncdsync_tx->cfgtx_CFG.bf.MODE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFG.bf.INIT_PROT_EN", tmp_syncdsync_tx->cfgtx_CFG.bf.INIT_PROT_EN, tmp_syncdsync_tx->cfgtx_CFG.bf.INIT_PROT_EN == dft_syncdsync_tx->cfgtx_CFG.bf.INIT_PROT_EN ? 0x20 : 0x2A, dft_syncdsync_tx->cfgtx_CFG.bf.INIT_PROT_EN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFG.bf.INIT_FORCE", tmp_syncdsync_tx->cfgtx_CFG.bf.INIT_FORCE, tmp_syncdsync_tx->cfgtx_CFG.bf.INIT_FORCE == dft_syncdsync_tx->cfgtx_CFG.bf.INIT_FORCE ? 0x20 : 0x2A, dft_syncdsync_tx->cfgtx_CFG.bf.INIT_FORCE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFG.bf.RESET_SW", tmp_syncdsync_tx->cfgtx_CFG.bf.RESET_SW, tmp_syncdsync_tx->cfgtx_CFG.bf.RESET_SW == dft_syncdsync_tx->cfgtx_CFG.bf.RESET_SW ? 0x20 : 0x2A, dft_syncdsync_tx->cfgtx_CFG.bf.RESET_SW, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFGPD0.wrd", tmp_syncdsync_tx->CFGPD0.wrd, tmp_syncdsync_tx->CFGPD0.wrd == dft_syncdsync_tx->CFGPD0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->CFGPD0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFGPD0.bf.PHASE_0_EN", tmp_syncdsync_tx->CFGPD0.bf.PHASE_0_EN, tmp_syncdsync_tx->CFGPD0.bf.PHASE_0_EN == dft_syncdsync_tx->CFGPD0.bf.PHASE_0_EN ? 0x20 : 0x2A, dft_syncdsync_tx->CFGPD0.bf.PHASE_0_EN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFGPD0.bf.DSYNC_PD_MD", tmp_syncdsync_tx->CFGPD0.bf.DSYNC_PD_MD, tmp_syncdsync_tx->CFGPD0.bf.DSYNC_PD_MD == dft_syncdsync_tx->CFGPD0.bf.DSYNC_PD_MD ? 0x20 : 0x2A, dft_syncdsync_tx->CFGPD0.bf.DSYNC_PD_MD, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFGJCGEN.wrd", tmp_syncdsync_tx->CFGJCGEN.wrd, tmp_syncdsync_tx->CFGJCGEN.wrd == dft_syncdsync_tx->CFGJCGEN.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->CFGJCGEN.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFGJCGEN.bf.JC_GEN_THRLD", tmp_syncdsync_tx->CFGJCGEN.bf.JC_GEN_THRLD, tmp_syncdsync_tx->CFGJCGEN.bf.JC_GEN_THRLD == dft_syncdsync_tx->CFGJCGEN.bf.JC_GEN_THRLD ? 0x20 : 0x2A, dft_syncdsync_tx->CFGJCGEN.bf.JC_GEN_THRLD, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGTX_CFGJCGEN.bf.JC_GEN_MAX_JP", tmp_syncdsync_tx->CFGJCGEN.bf.JC_GEN_MAX_JP, tmp_syncdsync_tx->CFGJCGEN.bf.JC_GEN_MAX_JP == dft_syncdsync_tx->CFGJCGEN.bf.JC_GEN_MAX_JP ? 0x20 : 0x2A, dft_syncdsync_tx->CFGJCGEN.bf.JC_GEN_MAX_JP, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_CFG.wrd", tmp_syncdsync_tx->cfgmontx_CFG.wrd, tmp_syncdsync_tx->cfgmontx_CFG.wrd == dft_syncdsync_tx->cfgmontx_CFG.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->cfgmontx_CFG.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_CFG.bf.EOFGCFG", tmp_syncdsync_tx->cfgmontx_CFG.bf.EOFGCFG, tmp_syncdsync_tx->cfgmontx_CFG.bf.EOFGCFG == dft_syncdsync_tx->cfgmontx_CFG.bf.EOFGCFG ? 0x20 : 0x2A, dft_syncdsync_tx->cfgmontx_CFG.bf.EOFGCFG, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_PJO_TH1.wrd", tmp_syncdsync_tx->ODTU23_PJO_TH1.wrd, tmp_syncdsync_tx->ODTU23_PJO_TH1.wrd == dft_syncdsync_tx->ODTU23_PJO_TH1.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_PJO_TH1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_PJO_TH1.bf.ODTU23_PJO_TH1", tmp_syncdsync_tx->ODTU23_PJO_TH1.bf.ODTU23_PJO_TH1, tmp_syncdsync_tx->ODTU23_PJO_TH1.bf.ODTU23_PJO_TH1 == dft_syncdsync_tx->ODTU23_PJO_TH1.bf.ODTU23_PJO_TH1 ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_PJO_TH1.bf.ODTU23_PJO_TH1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_PJO_TH0.wrd", tmp_syncdsync_tx->ODTU23_PJO_TH0.wrd, tmp_syncdsync_tx->ODTU23_PJO_TH0.wrd == dft_syncdsync_tx->ODTU23_PJO_TH0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_PJO_TH0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_PJO_TH0.bf.ODTU23_PJO_TH0", tmp_syncdsync_tx->ODTU23_PJO_TH0.bf.ODTU23_PJO_TH0, tmp_syncdsync_tx->ODTU23_PJO_TH0.bf.ODTU23_PJO_TH0 == dft_syncdsync_tx->ODTU23_PJO_TH0.bf.ODTU23_PJO_TH0 ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_PJO_TH0.bf.ODTU23_PJO_TH0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_NJO_TH1.wrd", tmp_syncdsync_tx->ODTU23_NJO_TH1.wrd, tmp_syncdsync_tx->ODTU23_NJO_TH1.wrd == dft_syncdsync_tx->ODTU23_NJO_TH1.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_NJO_TH1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_NJO_TH1.bf.ODTU23_NJO_TH1", tmp_syncdsync_tx->ODTU23_NJO_TH1.bf.ODTU23_NJO_TH1, tmp_syncdsync_tx->ODTU23_NJO_TH1.bf.ODTU23_NJO_TH1 == dft_syncdsync_tx->ODTU23_NJO_TH1.bf.ODTU23_NJO_TH1 ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_NJO_TH1.bf.ODTU23_NJO_TH1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_NJO_TH0.wrd", tmp_syncdsync_tx->ODTU23_NJO_TH0.wrd, tmp_syncdsync_tx->ODTU23_NJO_TH0.wrd == dft_syncdsync_tx->ODTU23_NJO_TH0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_NJO_TH0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_NJO_TH0.bf.ODTU23_NJO_TH0", tmp_syncdsync_tx->ODTU23_NJO_TH0.bf.ODTU23_NJO_TH0, tmp_syncdsync_tx->ODTU23_NJO_TH0.bf.ODTU23_NJO_TH0 == dft_syncdsync_tx->ODTU23_NJO_TH0.bf.ODTU23_NJO_TH0 ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_NJO_TH0.bf.ODTU23_NJO_TH0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_PJO_TH1.wrd", tmp_syncdsync_tx->OXUN_PJO_TH1.wrd, tmp_syncdsync_tx->OXUN_PJO_TH1.wrd == dft_syncdsync_tx->OXUN_PJO_TH1.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_PJO_TH1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_PJO_TH1.bf.OXUN_PJO_TH1", tmp_syncdsync_tx->OXUN_PJO_TH1.bf.OXUN_PJO_TH1, tmp_syncdsync_tx->OXUN_PJO_TH1.bf.OXUN_PJO_TH1 == dft_syncdsync_tx->OXUN_PJO_TH1.bf.OXUN_PJO_TH1 ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_PJO_TH1.bf.OXUN_PJO_TH1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_PJO_TH0.wrd", tmp_syncdsync_tx->OXUN_PJO_TH0.wrd, tmp_syncdsync_tx->OXUN_PJO_TH0.wrd == dft_syncdsync_tx->OXUN_PJO_TH0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_PJO_TH0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_PJO_TH0.bf.OXUN_PJO_TH0", tmp_syncdsync_tx->OXUN_PJO_TH0.bf.OXUN_PJO_TH0, tmp_syncdsync_tx->OXUN_PJO_TH0.bf.OXUN_PJO_TH0 == dft_syncdsync_tx->OXUN_PJO_TH0.bf.OXUN_PJO_TH0 ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_PJO_TH0.bf.OXUN_PJO_TH0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_NJO_TH1.wrd", tmp_syncdsync_tx->OXUN_NJO_TH1.wrd, tmp_syncdsync_tx->OXUN_NJO_TH1.wrd == dft_syncdsync_tx->OXUN_NJO_TH1.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_NJO_TH1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_NJO_TH1.bf.OXUN_NJO_TH1", tmp_syncdsync_tx->OXUN_NJO_TH1.bf.OXUN_NJO_TH1, tmp_syncdsync_tx->OXUN_NJO_TH1.bf.OXUN_NJO_TH1 == dft_syncdsync_tx->OXUN_NJO_TH1.bf.OXUN_NJO_TH1 ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_NJO_TH1.bf.OXUN_NJO_TH1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_NJO_TH0.wrd", tmp_syncdsync_tx->OXUN_NJO_TH0.wrd, tmp_syncdsync_tx->OXUN_NJO_TH0.wrd == dft_syncdsync_tx->OXUN_NJO_TH0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_NJO_TH0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_NJO_TH0.bf.OXUN_NJO_TH0", tmp_syncdsync_tx->OXUN_NJO_TH0.bf.OXUN_NJO_TH0, tmp_syncdsync_tx->OXUN_NJO_TH0.bf.OXUN_NJO_TH0 == dft_syncdsync_tx->OXUN_NJO_TH0.bf.OXUN_NJO_TH0 ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_NJO_TH0.bf.OXUN_NJO_TH0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_PJO1.wrd", tmp_syncdsync_tx->ODTU23_PJO1.wrd, tmp_syncdsync_tx->ODTU23_PJO1.wrd == dft_syncdsync_tx->ODTU23_PJO1.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_PJO1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_PJO1.bf.ODTU23_PJO1", tmp_syncdsync_tx->ODTU23_PJO1.bf.ODTU23_PJO1, tmp_syncdsync_tx->ODTU23_PJO1.bf.ODTU23_PJO1 == dft_syncdsync_tx->ODTU23_PJO1.bf.ODTU23_PJO1 ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_PJO1.bf.ODTU23_PJO1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_PJO0.wrd", tmp_syncdsync_tx->ODTU23_PJO0.wrd, tmp_syncdsync_tx->ODTU23_PJO0.wrd == dft_syncdsync_tx->ODTU23_PJO0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_PJO0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_PJO0.bf.ODTU23_PJO0", tmp_syncdsync_tx->ODTU23_PJO0.bf.ODTU23_PJO0, tmp_syncdsync_tx->ODTU23_PJO0.bf.ODTU23_PJO0 == dft_syncdsync_tx->ODTU23_PJO0.bf.ODTU23_PJO0 ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_PJO0.bf.ODTU23_PJO0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_NJO1.wrd", tmp_syncdsync_tx->ODTU23_NJO1.wrd, tmp_syncdsync_tx->ODTU23_NJO1.wrd == dft_syncdsync_tx->ODTU23_NJO1.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_NJO1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_NJO1.bf.ODTU23_NJO1", tmp_syncdsync_tx->ODTU23_NJO1.bf.ODTU23_NJO1, tmp_syncdsync_tx->ODTU23_NJO1.bf.ODTU23_NJO1 == dft_syncdsync_tx->ODTU23_NJO1.bf.ODTU23_NJO1 ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_NJO1.bf.ODTU23_NJO1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_NJO0.wrd", tmp_syncdsync_tx->ODTU23_NJO0.wrd, tmp_syncdsync_tx->ODTU23_NJO0.wrd == dft_syncdsync_tx->ODTU23_NJO0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_NJO0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_ODTU23_NJO0.bf.ODTU23_NJO0", tmp_syncdsync_tx->ODTU23_NJO0.bf.ODTU23_NJO0, tmp_syncdsync_tx->ODTU23_NJO0.bf.ODTU23_NJO0 == dft_syncdsync_tx->ODTU23_NJO0.bf.ODTU23_NJO0 ? 0x20 : 0x2A, dft_syncdsync_tx->ODTU23_NJO0.bf.ODTU23_NJO0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_PJO1.wrd", tmp_syncdsync_tx->OXUN_PJO1.wrd, tmp_syncdsync_tx->OXUN_PJO1.wrd == dft_syncdsync_tx->OXUN_PJO1.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_PJO1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_PJO1.bf.OXUN_PJO1", tmp_syncdsync_tx->OXUN_PJO1.bf.OXUN_PJO1, tmp_syncdsync_tx->OXUN_PJO1.bf.OXUN_PJO1 == dft_syncdsync_tx->OXUN_PJO1.bf.OXUN_PJO1 ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_PJO1.bf.OXUN_PJO1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_PJO0.wrd", tmp_syncdsync_tx->OXUN_PJO0.wrd, tmp_syncdsync_tx->OXUN_PJO0.wrd == dft_syncdsync_tx->OXUN_PJO0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_PJO0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_PJO0.bf.OXUN_PJO0", tmp_syncdsync_tx->OXUN_PJO0.bf.OXUN_PJO0, tmp_syncdsync_tx->OXUN_PJO0.bf.OXUN_PJO0 == dft_syncdsync_tx->OXUN_PJO0.bf.OXUN_PJO0 ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_PJO0.bf.OXUN_PJO0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_NJO1.wrd", tmp_syncdsync_tx->OXUN_NJO1.wrd, tmp_syncdsync_tx->OXUN_NJO1.wrd == dft_syncdsync_tx->OXUN_NJO1.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_NJO1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_NJO1.bf.OXUN_NJO1", tmp_syncdsync_tx->OXUN_NJO1.bf.OXUN_NJO1, tmp_syncdsync_tx->OXUN_NJO1.bf.OXUN_NJO1 == dft_syncdsync_tx->OXUN_NJO1.bf.OXUN_NJO1 ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_NJO1.bf.OXUN_NJO1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_NJO0.wrd", tmp_syncdsync_tx->OXUN_NJO0.wrd, tmp_syncdsync_tx->OXUN_NJO0.wrd == dft_syncdsync_tx->OXUN_NJO0.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_NJO0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_OXUN_NJO0.bf.OXUN_NJO0", tmp_syncdsync_tx->OXUN_NJO0.bf.OXUN_NJO0, tmp_syncdsync_tx->OXUN_NJO0.bf.OXUN_NJO0 == dft_syncdsync_tx->OXUN_NJO0.bf.OXUN_NJO0 ? 0x20 : 0x2A, dft_syncdsync_tx->OXUN_NJO0.bf.OXUN_NJO0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_STAT.wrd", tmp_syncdsync_tx->STAT.wrd, tmp_syncdsync_tx->STAT.wrd == dft_syncdsync_tx->STAT.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->STAT.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_STAT.bf.JC_OUT_RANGE", tmp_syncdsync_tx->STAT.bf.JC_OUT_RANGE, tmp_syncdsync_tx->STAT.bf.JC_OUT_RANGE == dft_syncdsync_tx->STAT.bf.JC_OUT_RANGE ? 0x20 : 0x2A, dft_syncdsync_tx->STAT.bf.JC_OUT_RANGE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_STAT.bf.OUT_RANGE", tmp_syncdsync_tx->STAT.bf.OUT_RANGE, tmp_syncdsync_tx->STAT.bf.OUT_RANGE == dft_syncdsync_tx->STAT.bf.OUT_RANGE ? 0x20 : 0x2A, dft_syncdsync_tx->STAT.bf.OUT_RANGE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INT.wrd", tmp_syncdsync_tx->INT.wrd, tmp_syncdsync_tx->INT.wrd == dft_syncdsync_tx->INT.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->INT.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INT.bf.JC_OUT_RANGE", tmp_syncdsync_tx->INT.bf.JC_OUT_RANGE, tmp_syncdsync_tx->INT.bf.JC_OUT_RANGE == dft_syncdsync_tx->INT.bf.JC_OUT_RANGE ? 0x20 : 0x2A, dft_syncdsync_tx->INT.bf.JC_OUT_RANGE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INT.bf.OUT_RANGEI", tmp_syncdsync_tx->INT.bf.OUT_RANGEI, tmp_syncdsync_tx->INT.bf.OUT_RANGEI == dft_syncdsync_tx->INT.bf.OUT_RANGEI ? 0x20 : 0x2A, dft_syncdsync_tx->INT.bf.OUT_RANGEI, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INT.bf.OXUN_NJOI", tmp_syncdsync_tx->INT.bf.OXUN_NJOI, tmp_syncdsync_tx->INT.bf.OXUN_NJOI == dft_syncdsync_tx->INT.bf.OXUN_NJOI ? 0x20 : 0x2A, dft_syncdsync_tx->INT.bf.OXUN_NJOI, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INT.bf.OXUN_PJOI", tmp_syncdsync_tx->INT.bf.OXUN_PJOI, tmp_syncdsync_tx->INT.bf.OXUN_PJOI == dft_syncdsync_tx->INT.bf.OXUN_PJOI ? 0x20 : 0x2A, dft_syncdsync_tx->INT.bf.OXUN_PJOI, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INT.bf.ODTU23_NJOI", tmp_syncdsync_tx->INT.bf.ODTU23_NJOI, tmp_syncdsync_tx->INT.bf.ODTU23_NJOI == dft_syncdsync_tx->INT.bf.ODTU23_NJOI ? 0x20 : 0x2A, dft_syncdsync_tx->INT.bf.ODTU23_NJOI, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INT.bf.ODTU23_PJOI", tmp_syncdsync_tx->INT.bf.ODTU23_PJOI, tmp_syncdsync_tx->INT.bf.ODTU23_PJOI == dft_syncdsync_tx->INT.bf.ODTU23_PJOI ? 0x20 : 0x2A, dft_syncdsync_tx->INT.bf.ODTU23_PJOI, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTE.wrd", tmp_syncdsync_tx->INTE.wrd, tmp_syncdsync_tx->INTE.wrd == dft_syncdsync_tx->INTE.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->INTE.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTE.bf.JC_OUT_RANGEE", tmp_syncdsync_tx->INTE.bf.JC_OUT_RANGEE, tmp_syncdsync_tx->INTE.bf.JC_OUT_RANGEE == dft_syncdsync_tx->INTE.bf.JC_OUT_RANGEE ? 0x20 : 0x2A, dft_syncdsync_tx->INTE.bf.JC_OUT_RANGEE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTE.bf.OUT_RANGEIE", tmp_syncdsync_tx->INTE.bf.OUT_RANGEIE, tmp_syncdsync_tx->INTE.bf.OUT_RANGEIE == dft_syncdsync_tx->INTE.bf.OUT_RANGEIE ? 0x20 : 0x2A, dft_syncdsync_tx->INTE.bf.OUT_RANGEIE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTE.bf.OXUN_NJOIE", tmp_syncdsync_tx->INTE.bf.OXUN_NJOIE, tmp_syncdsync_tx->INTE.bf.OXUN_NJOIE == dft_syncdsync_tx->INTE.bf.OXUN_NJOIE ? 0x20 : 0x2A, dft_syncdsync_tx->INTE.bf.OXUN_NJOIE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTE.bf.OXUN_PJOIE", tmp_syncdsync_tx->INTE.bf.OXUN_PJOIE, tmp_syncdsync_tx->INTE.bf.OXUN_PJOIE == dft_syncdsync_tx->INTE.bf.OXUN_PJOIE ? 0x20 : 0x2A, dft_syncdsync_tx->INTE.bf.OXUN_PJOIE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTE.bf.ODTU23_NJOIE", tmp_syncdsync_tx->INTE.bf.ODTU23_NJOIE, tmp_syncdsync_tx->INTE.bf.ODTU23_NJOIE == dft_syncdsync_tx->INTE.bf.ODTU23_NJOIE ? 0x20 : 0x2A, dft_syncdsync_tx->INTE.bf.ODTU23_NJOIE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTE.bf.ODTU23_PJOIE", tmp_syncdsync_tx->INTE.bf.ODTU23_PJOIE, tmp_syncdsync_tx->INTE.bf.ODTU23_PJOIE == dft_syncdsync_tx->INTE.bf.ODTU23_PJOIE ? 0x20 : 0x2A, dft_syncdsync_tx->INTE.bf.ODTU23_PJOIE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTZ.wrd", tmp_syncdsync_tx->INTZ.wrd, tmp_syncdsync_tx->INTZ.wrd == dft_syncdsync_tx->INTZ.wrd ? 0x20 : 0x2A, dft_syncdsync_tx->INTZ.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTZ.bf.JC_OUT_RANGEZ", tmp_syncdsync_tx->INTZ.bf.JC_OUT_RANGEZ, tmp_syncdsync_tx->INTZ.bf.JC_OUT_RANGEZ == dft_syncdsync_tx->INTZ.bf.JC_OUT_RANGEZ ? 0x20 : 0x2A, dft_syncdsync_tx->INTZ.bf.JC_OUT_RANGEZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTZ.bf.OUT_RANGEIZ", tmp_syncdsync_tx->INTZ.bf.OUT_RANGEIZ, tmp_syncdsync_tx->INTZ.bf.OUT_RANGEIZ == dft_syncdsync_tx->INTZ.bf.OUT_RANGEIZ ? 0x20 : 0x2A, dft_syncdsync_tx->INTZ.bf.OUT_RANGEIZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTZ.bf.OXUN_NJOIZ", tmp_syncdsync_tx->INTZ.bf.OXUN_NJOIZ, tmp_syncdsync_tx->INTZ.bf.OXUN_NJOIZ == dft_syncdsync_tx->INTZ.bf.OXUN_NJOIZ ? 0x20 : 0x2A, dft_syncdsync_tx->INTZ.bf.OXUN_NJOIZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTZ.bf.OXUN_PJOIZ", tmp_syncdsync_tx->INTZ.bf.OXUN_PJOIZ, tmp_syncdsync_tx->INTZ.bf.OXUN_PJOIZ == dft_syncdsync_tx->INTZ.bf.OXUN_PJOIZ ? 0x20 : 0x2A, dft_syncdsync_tx->INTZ.bf.OXUN_PJOIZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTZ.bf.ODTU23_NJOIZ", tmp_syncdsync_tx->INTZ.bf.ODTU23_NJOIZ, tmp_syncdsync_tx->INTZ.bf.ODTU23_NJOIZ == dft_syncdsync_tx->INTZ.bf.ODTU23_NJOIZ ? 0x20 : 0x2A, dft_syncdsync_tx->INTZ.bf.ODTU23_NJOIZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "SYNCDSYNCTX_CFGMONTX_INTZ.bf.ODTU23_PJOIZ", tmp_syncdsync_tx->INTZ.bf.ODTU23_PJOIZ, tmp_syncdsync_tx->INTZ.bf.ODTU23_PJOIZ == dft_syncdsync_tx->INTZ.bf.ODTU23_PJOIZ ? 0x20 : 0x2A, dft_syncdsync_tx->INTZ.bf.ODTU23_PJOIZ, ch1, ch2);
  }
  }
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  CS_FREE(dft_syncdsync_tx);
  CS_FREE(tmp_syncdsync_tx);
  CS_FREE(dft_syncdsync_rx);
  CS_FREE(tmp_syncdsync_rx);
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC CB DUMP SETTINGS                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_syncdsync_cb_dump_settings (cs_uint16 dev_id, cs_uint8 instance)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current SYNCDSYNC CB settings.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  ten_dev_cb_t *pdevcb;
  ten_syncdsync_cb_t *psyncdsync_cb;
  cs_uint32 err_code = 0;
  cs_char8 *func = "ten_debug_syncdsync_cb_dump_settings";  

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_PRINT("ERROR: %s Dev-Id (%d) is invalid!\n", func, dev_id);
    return (CS_ERROR);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  if (instance > 4) { 
    CS_PRINT("%s() instance %d out of range.  s/b 0..4.", func, instance);
    return (CS_ERROR);
  }

  if (pdevcb) {
    cs_bar();
    if (instance == 0) {
      psyncdsync_cb =  &pdevcb->syncdsync_cb;
      CS_PRINT_OUTPUT("Tenabo     syncdsync_cb\n");
    } else {  
      psyncdsync_cb =  &pdevcb->syncdsync_thread_cb[instance-1];
      CS_PRINT_OUTPUT("Tenabo     syncdsync_cb[%d]\n", instance-1);
    }
    cs_bar();

    CS_PRINT_OUTPUT("num_just_oxu2          = %d\n", psyncdsync_cb->num_just_oxu2);
    CS_PRINT_OUTPUT("num_pjo_oxu2           = %d\n", psyncdsync_cb->num_pjo_oxu2);
    CS_PRINT_OUTPUT("num_just_oxu3          = %d\n", psyncdsync_cb->num_just_oxu3);
    CS_PRINT_OUTPUT("num_pjo_oxu3           = %d\n", psyncdsync_cb->num_pjo_oxu3);
    CS_PRINT_OUTPUT("P_line                 = %d\n", psyncdsync_cb->P_line);
    CS_PRINT_OUTPUT("Q_line                 = %d\n", psyncdsync_cb->Q_line);
    CS_PRINT_OUTPUT("P_client               = %d\n", psyncdsync_cb->P_client);
    CS_PRINT_OUTPUT("Q_client               = %d\n", psyncdsync_cb->Q_client);
    CS_PRINT_OUTPUT("line_client_same       = %d\n", psyncdsync_cb->line_client_same);
    CS_PRINT_OUTPUT("line_client_rate_equal = %d\n", psyncdsync_cb->line_client_rate_equal);
    CS_PRINT_OUTPUT("transcode_num          = %d\n", psyncdsync_cb->transcode_num);
    CS_PRINT_OUTPUT("transcode_denom        = %d\n", psyncdsync_cb->transcode_denom);
    CS_PRINT_OUTPUT("client_map_proc        = %d\n", psyncdsync_cb->client_map_proc);
    CS_PRINT_OUTPUT("line_map_proc          = %d\n", psyncdsync_cb->line_map_proc);
    CS_PRINT_OUTPUT("client_rate            = %f\n", psyncdsync_cb->client_rate);
    CS_PRINT_OUTPUT("xcon_client_rate       = %f\n", psyncdsync_cb->xcon_client_rate);
    CS_PRINT_OUTPUT("line_rate              = %f\n", psyncdsync_cb->line_rate);
    CS_PRINT_OUTPUT("cn_bytes_n10g          = %d\n", psyncdsync_cb->cn_bytes_n10g);  /*Bugzilla 26308, 36501*/
    CS_PRINT_OUTPUT("cn_bytes_n40g          = %d\n", psyncdsync_cb->cn_bytes_n40g);  /*Bugzilla 36501*/
    CS_PRINT_OUTPUT("hysteresis             = %d\n", psyncdsync_cb->hysteresis);

  }
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  DEBUG SYNCDSYNC SETTINGS                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_syncdsync_settings(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current SYNCDSYNC settings.                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_t *tmp_syncdsync_tx;
  TEN_SYNCDSYNCRX_t *tmp_syncdsync_rx;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  } 

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  /* Create temporary storage */
  tmp_syncdsync_tx = (TEN_SYNCDSYNCTX_t *)CS_MALLOC(sizeof(TEN_SYNCDSYNCTX_t));
  tmp_syncdsync_rx = (TEN_SYNCDSYNCRX_t *)CS_MALLOC(sizeof(TEN_SYNCDSYNCRX_t));

  if ((tmp_syncdsync_tx == 0) || (tmp_syncdsync_rx == 0)) {
    /* Bugzilla 28734 Klocwork fix, 2 lines */
    if (tmp_syncdsync_tx) CS_FREE(tmp_syncdsync_tx);
    if (tmp_syncdsync_rx) CS_FREE(tmp_syncdsync_rx);
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_syncdsync_rx->NUMERATOR2.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR2));
      tmp_syncdsync_rx->NUMERATOR1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR1));
      tmp_syncdsync_rx->NUMERATOR0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, NUMERATOR0));
      tmp_syncdsync_rx->DENOMINATOR2.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, DENOMINATOR2));
      tmp_syncdsync_rx->DENOMINATOR1.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, DENOMINATOR1));
      tmp_syncdsync_rx->DENOMINATOR0.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, DENOMINATOR0));
      tmp_syncdsync_rx->AC12.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC12));
      tmp_syncdsync_rx->AC11.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC11));
      tmp_syncdsync_rx->AC10.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC10));
      tmp_syncdsync_rx->AC22.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC22));
      tmp_syncdsync_rx->AC21.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC21));
      tmp_syncdsync_rx->AC20.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AC20));
      tmp_syncdsync_rx->AD11.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD11));
      tmp_syncdsync_rx->AD10.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD10));
      tmp_syncdsync_rx->AD21.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD21));
      tmp_syncdsync_rx->AD20.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, AD20));
      tmp_syncdsync_rx->cfgrx_CFG.wrd = TEN_REG_READ(TEN_SYNCDSYNCRX_REG_ADDR(pDev, module_id, sl, cfgrx_CFG));

      CS_PRINT_OUTPUT("SYNCDSYNC RX %s, %s\n", ten_module_strings[module_id&1], ten_slice_strings[slice]);
      CS_PRINT_OUTPUT("    Numerator   = 0x%04X,%04X,%04X\n",  tmp_syncdsync_rx->NUMERATOR2.wrd, tmp_syncdsync_rx->NUMERATOR1.wrd, tmp_syncdsync_rx->NUMERATOR0.wrd);
      CS_PRINT_OUTPUT("    Denominator = 0x%04X,%04X,%04X\n",  tmp_syncdsync_rx->DENOMINATOR2.wrd, tmp_syncdsync_rx->DENOMINATOR1.wrd, tmp_syncdsync_rx->DENOMINATOR0.wrd);
      CS_PRINT_OUTPUT("    AC1         = 0x%04X,%04X,%04X\n",  tmp_syncdsync_rx->AC12.wrd, tmp_syncdsync_rx->AC11.wrd, tmp_syncdsync_rx->AC10.wrd);
      CS_PRINT_OUTPUT("    AC2         = 0x%04X,%04X,%04X\n",  tmp_syncdsync_rx->AC22.wrd, tmp_syncdsync_rx->AC21.wrd, tmp_syncdsync_rx->AC20.wrd);
      CS_PRINT_OUTPUT("    AD1         = 0x%04X,%04X\n",  tmp_syncdsync_rx->AD11.wrd, tmp_syncdsync_rx->AD10.wrd);
      CS_PRINT_OUTPUT("    AD2         = 0x%04X,%04X\n",  tmp_syncdsync_rx->AD21.wrd, tmp_syncdsync_rx->AD20.wrd);
      CS_PRINT_OUTPUT("    CFG         = 0x%04X\n",  tmp_syncdsync_rx->cfgrx_CFG.wrd);
      CS_PRINT_OUTPUT("        MODE        = %d\n",  tmp_syncdsync_rx->cfgrx_CFG.bf.MODE);
      CS_PRINT_OUTPUT("        RESET_SW    = %d\n",  tmp_syncdsync_rx->cfgrx_CFG.bf.RESET_SW);

      tmp_syncdsync_tx->DENOMINATOR2.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, DENOMINATOR2));
      tmp_syncdsync_tx->DENOMINATOR1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, DENOMINATOR1));
      tmp_syncdsync_tx->DENOMINATOR0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, DENOMINATOR0));
      tmp_syncdsync_tx->NUMERATOR2.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR2));
      tmp_syncdsync_tx->NUMERATOR1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR1));
      tmp_syncdsync_tx->NUMERATOR0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR0));
      tmp_syncdsync_tx->AC12.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC12));
      tmp_syncdsync_tx->AC11.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC11));
      tmp_syncdsync_tx->AC10.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC10));
      tmp_syncdsync_tx->AC22.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC22));
      tmp_syncdsync_tx->AC21.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC21));
      tmp_syncdsync_tx->AC20.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC20));
      tmp_syncdsync_tx->AD11.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD11));
      tmp_syncdsync_tx->AD10.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD10));
      tmp_syncdsync_tx->AD21.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD21));
      tmp_syncdsync_tx->AD20.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD20));
      tmp_syncdsync_tx->cfgtx_CFG.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG));
      tmp_syncdsync_tx->CFGPD0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, CFGPD0));
      tmp_syncdsync_tx->CFGJCGEN.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, CFGJCGEN));

      CS_PRINT_OUTPUT("SYNCDSYNC TX %s, %s\n", ten_module_strings[module_id&1], ten_slice_strings[slice]);
      CS_PRINT_OUTPUT("    Denominator = 0x%04X,%04X,%04X\n",  tmp_syncdsync_tx->DENOMINATOR2.wrd, tmp_syncdsync_tx->DENOMINATOR1.wrd, tmp_syncdsync_tx->DENOMINATOR0.wrd);
      CS_PRINT_OUTPUT("    Numerator   = 0x%04X,%04X,%04X\n",  tmp_syncdsync_tx->NUMERATOR2.wrd, tmp_syncdsync_tx->NUMERATOR1.wrd, tmp_syncdsync_tx->NUMERATOR0.wrd);
      CS_PRINT_OUTPUT("    AC1         = 0x%04X,%04X,%04X\n",  tmp_syncdsync_tx->AC12.wrd, tmp_syncdsync_tx->AC11.wrd, tmp_syncdsync_tx->AC10.wrd);
      CS_PRINT_OUTPUT("    AC2         = 0x%04X,%04X,%04X\n",  tmp_syncdsync_tx->AC22.wrd, tmp_syncdsync_tx->AC21.wrd, tmp_syncdsync_tx->AC20.wrd);
      CS_PRINT_OUTPUT("    AD1         = 0x%04X,%04X\n",  tmp_syncdsync_tx->AD11.wrd, tmp_syncdsync_tx->AD10.wrd);
      CS_PRINT_OUTPUT("    AD2         = 0x%04X,%04X\n",  tmp_syncdsync_tx->AD21.wrd, tmp_syncdsync_tx->AD20.wrd);
      CS_PRINT_OUTPUT("    CFG         = 0x%04X\n",  tmp_syncdsync_tx->cfgtx_CFG.wrd);
      CS_PRINT_OUTPUT("        GMP_ENABLE  = %d\n",  tmp_syncdsync_tx->cfgtx_CFG.bf.GMP_ENABLE);
      CS_PRINT_OUTPUT("        RX_DIV_MUX  = %d\n",  tmp_syncdsync_tx->cfgtx_CFG.bf.RX_DIV_MUX);
      CS_PRINT_OUTPUT("        MODE        = %d\n",  tmp_syncdsync_tx->cfgtx_CFG.bf.MODE);
      CS_PRINT_OUTPUT("        INIT_PROT_EN= %d\n",  tmp_syncdsync_tx->cfgtx_CFG.bf.INIT_PROT_EN);
      CS_PRINT_OUTPUT("        INIT_FORCE  = %d\n",  tmp_syncdsync_tx->cfgtx_CFG.bf.INIT_FORCE);
      CS_PRINT_OUTPUT("        RESET_SW    = %d\n",  tmp_syncdsync_tx->cfgtx_CFG.bf.RESET_SW);
      CS_PRINT_OUTPUT("    CFGPD0      = 0x%04X\n",  tmp_syncdsync_tx->CFGPD0.wrd);
      CS_PRINT_OUTPUT("        PHASE_0_EN       = %d\n",  tmp_syncdsync_tx->CFGPD0.bf.PHASE_0_EN);
      CS_PRINT_OUTPUT("        DSYNC_PD_MD      = %d\n",  tmp_syncdsync_tx->CFGPD0.bf.DSYNC_PD_MD);
      CS_PRINT_OUTPUT("    CFGJCGEN    = 0x%04X\n",  tmp_syncdsync_tx->CFGJCGEN.wrd);
    }
  }
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  CS_FREE(tmp_syncdsync_tx);
  CS_FREE(tmp_syncdsync_rx);
  
  return (CS_OK);
}
