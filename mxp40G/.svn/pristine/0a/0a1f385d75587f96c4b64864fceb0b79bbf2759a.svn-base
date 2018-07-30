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
 * ten_debug_cuppl.c
 *
 * APIs for debugging cuppl
 *
 * $Id: ten_debug_cupll.c,v 1.9 2013/03/05 16:11:52 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  CUPLL DUMP SETTINGS                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_cupll_dump_settings(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current CUPLL settings.                                 */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  TEN_xfi_cupll_t *tmp_cupll, *dft_cupll;
  cs_uint16 sl;
  cs_char8 ch1, ch2;
  T41_t *pDev = NULL;
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
        
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  } 
  
  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }
     
  tmp_cupll = (TEN_xfi_cupll_t *)CS_MALLOC(sizeof(TEN_xfi_cupll_t));
  dft_cupll = (TEN_xfi_cupll_t *)CS_MALLOC(sizeof(TEN_xfi_cupll_t));
  
  /* Bug #38811: Debug APIs need malloc check for Klocwork warning */
  if ((tmp_cupll == 0) || (dft_cupll == 0)) {
    if (tmp_cupll) {
      CS_FREE(tmp_cupll);
    }
    if (dft_cupll) {
      CS_FREE(dft_cupll);
    }
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  CS_MEMSET((TEN_xfi_cupll_t *)tmp_cupll, 0, sizeof(TEN_xfi_cupll_t));
  CS_MEMSET((TEN_xfi_cupll_t *)dft_cupll, 0, sizeof(TEN_xfi_cupll_t));

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  
  dft_cupll->RESET.wrd = TEN_XFI_CUPLL_RESET_dft;   
  dft_cupll->CFG.wrd = TEN_XFI_CUPLL_CFG_dft;       
  dft_cupll->PDOFFSET1.wrd = TEN_XFI_CUPLL_PDOFFSET1_dft;
  dft_cupll->PDOFFSET0.wrd = TEN_XFI_CUPLL_PDOFFSET0_dft;
  dft_cupll->HOLDOVER.wrd = TEN_XFI_CUPLL_HOLDOVER_dft;
  dft_cupll->PDCAL.wrd = TEN_XFI_CUPLL_PDCAL_dft;   
  dft_cupll->K1F.wrd = TEN_XFI_CUPLL_K1F_dft;       
  dft_cupll->Z1F.wrd = TEN_XFI_CUPLL_Z1F_dft;       
  dft_cupll->P1F.wrd = TEN_XFI_CUPLL_P1F_dft;       
  dft_cupll->P2F.wrd = TEN_XFI_CUPLL_P2F_dft;       
  dft_cupll->P3F.wrd = TEN_XFI_CUPLL_P3F_dft;       
  dft_cupll->K1S.wrd = TEN_XFI_CUPLL_K1S_dft;       
  dft_cupll->Z1S.wrd = TEN_XFI_CUPLL_Z1S_dft;       
  dft_cupll->P1S.wrd = TEN_XFI_CUPLL_P1S_dft;       
  dft_cupll->P2S.wrd = TEN_XFI_CUPLL_P2S_dft;       
  dft_cupll->P3S.wrd = TEN_XFI_CUPLL_P3S_dft;       
  dft_cupll->PRELOADFINT.wrd = TEN_XFI_CUPLL_PRELOADFINT_dft;
  dft_cupll->PRELOADFFRAC1.wrd = TEN_XFI_CUPLL_PRELOADFFRAC1_dft;
  dft_cupll->PRELOADFFRAC0.wrd = TEN_XFI_CUPLL_PRELOADFFRAC0_dft;
  dft_cupll->SD_CFG.wrd = TEN_XFI_CUPLL_SD_CFG_dft; 
  dft_cupll->LOCKDET_FILTER.wrd = TEN_XFI_CUPLL_LOCKDET_FILTER_dft;
  dft_cupll->LOCKDET_CONTROL.wrd = TEN_XFI_CUPLL_LOCKDET_CONTROL_dft;
  dft_cupll->LOCKDET_INTERRUPT.wrd = TEN_XFI_CUPLL_LOCKDET_INTERRUPT_dft;
  dft_cupll->LOCKDET_INTSTATUS.wrd = TEN_XFI_CUPLL_LOCKDET_INTSTATUS_dft;
  dft_cupll->LOCKDET_INTENABLE.wrd = TEN_XFI_CUPLL_LOCKDET_INTENABLE_dft;
  dft_cupll->LOCKDET_INTERRUPTZ.wrd = TEN_XFI_CUPLL_LOCKDET_INTERRUPTZ_dft;

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cupll->RESET.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, RESET));
      tmp_cupll->CFG.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, CFG));
      tmp_cupll->PDOFFSET1.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PDOFFSET1));
      tmp_cupll->PDOFFSET0.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PDOFFSET0));
      tmp_cupll->HOLDOVER.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, HOLDOVER));
      tmp_cupll->PDCAL.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PDCAL));
      tmp_cupll->K1F.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, K1F));
      tmp_cupll->Z1F.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, Z1F));
      tmp_cupll->P1F.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P1F));
      tmp_cupll->P2F.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P2F));
      tmp_cupll->P3F.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P3F));
      tmp_cupll->K1S.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, K1S));
      tmp_cupll->Z1S.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, Z1S));
      tmp_cupll->P1S.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P1S));
      tmp_cupll->P2S.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P2S));
      tmp_cupll->P3S.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P3S));
      tmp_cupll->PRELOADFINT.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PRELOADFINT));
      tmp_cupll->PRELOADFFRAC1.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PRELOADFFRAC1));
      tmp_cupll->PRELOADFFRAC0.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PRELOADFFRAC0));
      tmp_cupll->SD_CFG.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, SD_CFG));
      tmp_cupll->LOCKDET_FILTER.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_FILTER));
      tmp_cupll->LOCKDET_CONTROL.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_CONTROL));
      tmp_cupll->LOCKDET_INTERRUPT.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_INTERRUPT));
      tmp_cupll->LOCKDET_INTSTATUS.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_INTSTATUS));
      tmp_cupll->LOCKDET_INTENABLE.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_INTENABLE));
      tmp_cupll->LOCKDET_INTERRUPTZ.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_INTERRUPTZ));
    
      ch1 = (module_id & 1) ? 'B' : 'A';
      ch2 = sl + '0';

      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_RESET.wrd", tmp_cupll->RESET.wrd, tmp_cupll->RESET.wrd == dft_cupll->RESET.wrd ? 0x20 : 0x2A, dft_cupll->RESET.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_RESET.bf.SDreset", tmp_cupll->RESET.bf.SDreset, tmp_cupll->RESET.bf.SDreset == dft_cupll->RESET.bf.SDreset ? 0x20 : 0x2A, dft_cupll->RESET.bf.SDreset, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_RESET.bf.lockdet", tmp_cupll->RESET.bf.lockdet, tmp_cupll->RESET.bf.lockdet == dft_cupll->RESET.bf.lockdet ? 0x20 : 0x2A, dft_cupll->RESET.bf.lockdet, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_RESET.bf.gro", tmp_cupll->RESET.bf.gro, tmp_cupll->RESET.bf.gro == dft_cupll->RESET.bf.gro ? 0x20 : 0x2A, dft_cupll->RESET.bf.gro, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_RESET.bf.cupll_dig", tmp_cupll->RESET.bf.cupll_dig, tmp_cupll->RESET.bf.cupll_dig == dft_cupll->RESET.bf.cupll_dig ? 0x20 : 0x2A, dft_cupll->RESET.bf.cupll_dig, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_CFG.wrd", tmp_cupll->CFG.wrd, tmp_cupll->CFG.wrd == dft_cupll->CFG.wrd ? 0x20 : 0x2A, dft_cupll->CFG.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_CFG.bf.PDoutsel", tmp_cupll->CFG.bf.PDoutsel, tmp_cupll->CFG.bf.PDoutsel == dft_cupll->CFG.bf.PDoutsel ? 0x20 : 0x2A, dft_cupll->CFG.bf.PDoutsel, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PDOFFSET1.wrd", tmp_cupll->PDOFFSET1.wrd, tmp_cupll->PDOFFSET1.wrd == dft_cupll->PDOFFSET1.wrd ? 0x20 : 0x2A, dft_cupll->PDOFFSET1.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PDOFFSET1.bf.PDoffset1", tmp_cupll->PDOFFSET1.bf.PDoffset1, tmp_cupll->PDOFFSET1.bf.PDoffset1 == dft_cupll->PDOFFSET1.bf.PDoffset1 ? 0x20 : 0x2A, dft_cupll->PDOFFSET1.bf.PDoffset1, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PDOFFSET0.wrd", tmp_cupll->PDOFFSET0.wrd, tmp_cupll->PDOFFSET0.wrd == dft_cupll->PDOFFSET0.wrd ? 0x20 : 0x2A, dft_cupll->PDOFFSET0.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PDOFFSET0.bf.PDoffset0", tmp_cupll->PDOFFSET0.bf.PDoffset0, tmp_cupll->PDOFFSET0.bf.PDoffset0 == dft_cupll->PDOFFSET0.bf.PDoffset0 ? 0x20 : 0x2A, dft_cupll->PDOFFSET0.bf.PDoffset0, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_HOLDOVER.wrd", tmp_cupll->HOLDOVER.wrd, tmp_cupll->HOLDOVER.wrd == dft_cupll->HOLDOVER.wrd ? 0x20 : 0x2A, dft_cupll->HOLDOVER.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_HOLDOVER.bf.HoldoverSelect", tmp_cupll->HOLDOVER.bf.HoldoverSelect, tmp_cupll->HOLDOVER.bf.HoldoverSelect == dft_cupll->HOLDOVER.bf.HoldoverSelect ? 0x20 : 0x2A, dft_cupll->HOLDOVER.bf.HoldoverSelect, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_HOLDOVER.bf.HoldoverCount", tmp_cupll->HOLDOVER.bf.HoldoverCount, tmp_cupll->HOLDOVER.bf.HoldoverCount == dft_cupll->HOLDOVER.bf.HoldoverCount ? 0x20 : 0x2A, dft_cupll->HOLDOVER.bf.HoldoverCount, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PDCAL.wrd", tmp_cupll->PDCAL.wrd, tmp_cupll->PDCAL.wrd == dft_cupll->PDCAL.wrd ? 0x20 : 0x2A, dft_cupll->PDCAL.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PDCAL.bf.PDcalSel", tmp_cupll->PDCAL.bf.PDcalSel, tmp_cupll->PDCAL.bf.PDcalSel == dft_cupll->PDCAL.bf.PDcalSel ? 0x20 : 0x2A, dft_cupll->PDCAL.bf.PDcalSel, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_K1F.wrd", tmp_cupll->K1F.wrd, tmp_cupll->K1F.wrd == dft_cupll->K1F.wrd ? 0x20 : 0x2A, dft_cupll->K1F.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_K1F.bf.K1Fscale", tmp_cupll->K1F.bf.K1Fscale, tmp_cupll->K1F.bf.K1Fscale == dft_cupll->K1F.bf.K1Fscale ? 0x20 : 0x2A, dft_cupll->K1F.bf.K1Fscale, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_K1F.bf.K1Fshift", tmp_cupll->K1F.bf.K1Fshift, tmp_cupll->K1F.bf.K1Fshift == dft_cupll->K1F.bf.K1Fshift ? 0x20 : 0x2A, dft_cupll->K1F.bf.K1Fshift, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_Z1F.wrd", tmp_cupll->Z1F.wrd, tmp_cupll->Z1F.wrd == dft_cupll->Z1F.wrd ? 0x20 : 0x2A, dft_cupll->Z1F.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_Z1F.bf.Z1Fscale", tmp_cupll->Z1F.bf.Z1Fscale, tmp_cupll->Z1F.bf.Z1Fscale == dft_cupll->Z1F.bf.Z1Fscale ? 0x20 : 0x2A, dft_cupll->Z1F.bf.Z1Fscale, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_Z1F.bf.Z1Fshift", tmp_cupll->Z1F.bf.Z1Fshift, tmp_cupll->Z1F.bf.Z1Fshift == dft_cupll->Z1F.bf.Z1Fshift ? 0x20 : 0x2A, dft_cupll->Z1F.bf.Z1Fshift, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P1F.wrd", tmp_cupll->P1F.wrd, tmp_cupll->P1F.wrd == dft_cupll->P1F.wrd ? 0x20 : 0x2A, dft_cupll->P1F.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P1F.bf.P1Fscale", tmp_cupll->P1F.bf.P1Fscale, tmp_cupll->P1F.bf.P1Fscale == dft_cupll->P1F.bf.P1Fscale ? 0x20 : 0x2A, dft_cupll->P1F.bf.P1Fscale, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P1F.bf.P1Fshift", tmp_cupll->P1F.bf.P1Fshift, tmp_cupll->P1F.bf.P1Fshift == dft_cupll->P1F.bf.P1Fshift ? 0x20 : 0x2A, dft_cupll->P1F.bf.P1Fshift, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P2F.wrd", tmp_cupll->P2F.wrd, tmp_cupll->P2F.wrd == dft_cupll->P2F.wrd ? 0x20 : 0x2A, dft_cupll->P2F.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P2F.bf.P2Fscale", tmp_cupll->P2F.bf.P2Fscale, tmp_cupll->P2F.bf.P2Fscale == dft_cupll->P2F.bf.P2Fscale ? 0x20 : 0x2A, dft_cupll->P2F.bf.P2Fscale, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P2F.bf.P2Fshift", tmp_cupll->P2F.bf.P2Fshift, tmp_cupll->P2F.bf.P2Fshift == dft_cupll->P2F.bf.P2Fshift ? 0x20 : 0x2A, dft_cupll->P2F.bf.P2Fshift, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P3F.wrd", tmp_cupll->P3F.wrd, tmp_cupll->P3F.wrd == dft_cupll->P3F.wrd ? 0x20 : 0x2A, dft_cupll->P3F.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P3F.bf.P3Fscale", tmp_cupll->P3F.bf.P3Fscale, tmp_cupll->P3F.bf.P3Fscale == dft_cupll->P3F.bf.P3Fscale ? 0x20 : 0x2A, dft_cupll->P3F.bf.P3Fscale, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P3F.bf.P3Fshift", tmp_cupll->P3F.bf.P3Fshift, tmp_cupll->P3F.bf.P3Fshift == dft_cupll->P3F.bf.P3Fshift ? 0x20 : 0x2A, dft_cupll->P3F.bf.P3Fshift, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_K1S.wrd", tmp_cupll->K1S.wrd, tmp_cupll->K1S.wrd == dft_cupll->K1S.wrd ? 0x20 : 0x2A, dft_cupll->K1S.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_K1S.bf.K1Sscale", tmp_cupll->K1S.bf.K1Sscale, tmp_cupll->K1S.bf.K1Sscale == dft_cupll->K1S.bf.K1Sscale ? 0x20 : 0x2A, dft_cupll->K1S.bf.K1Sscale, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_K1S.bf.K1Sshift", tmp_cupll->K1S.bf.K1Sshift, tmp_cupll->K1S.bf.K1Sshift == dft_cupll->K1S.bf.K1Sshift ? 0x20 : 0x2A, dft_cupll->K1S.bf.K1Sshift, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_Z1S.wrd", tmp_cupll->Z1S.wrd, tmp_cupll->Z1S.wrd == dft_cupll->Z1S.wrd ? 0x20 : 0x2A, dft_cupll->Z1S.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_Z1S.bf.Z1Sscale", tmp_cupll->Z1S.bf.Z1Sscale, tmp_cupll->Z1S.bf.Z1Sscale == dft_cupll->Z1S.bf.Z1Sscale ? 0x20 : 0x2A, dft_cupll->Z1S.bf.Z1Sscale, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_Z1S.bf.Z1Sshift", tmp_cupll->Z1S.bf.Z1Sshift, tmp_cupll->Z1S.bf.Z1Sshift == dft_cupll->Z1S.bf.Z1Sshift ? 0x20 : 0x2A, dft_cupll->Z1S.bf.Z1Sshift, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P1S.wrd", tmp_cupll->P1S.wrd, tmp_cupll->P1S.wrd == dft_cupll->P1S.wrd ? 0x20 : 0x2A, dft_cupll->P1S.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P1S.bf.P1Sscale", tmp_cupll->P1S.bf.P1Sscale, tmp_cupll->P1S.bf.P1Sscale == dft_cupll->P1S.bf.P1Sscale ? 0x20 : 0x2A, dft_cupll->P1S.bf.P1Sscale, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P1S.bf.P1Sshift", tmp_cupll->P1S.bf.P1Sshift, tmp_cupll->P1S.bf.P1Sshift == dft_cupll->P1S.bf.P1Sshift ? 0x20 : 0x2A, dft_cupll->P1S.bf.P1Sshift, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P2S.wrd", tmp_cupll->P2S.wrd, tmp_cupll->P2S.wrd == dft_cupll->P2S.wrd ? 0x20 : 0x2A, dft_cupll->P2S.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P2S.bf.P2Sscale", tmp_cupll->P2S.bf.P2Sscale, tmp_cupll->P2S.bf.P2Sscale == dft_cupll->P2S.bf.P2Sscale ? 0x20 : 0x2A, dft_cupll->P2S.bf.P2Sscale, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P2S.bf.P2Sshift", tmp_cupll->P2S.bf.P2Sshift, tmp_cupll->P2S.bf.P2Sshift == dft_cupll->P2S.bf.P2Sshift ? 0x20 : 0x2A, dft_cupll->P2S.bf.P2Sshift, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P3S.wrd", tmp_cupll->P3S.wrd, tmp_cupll->P3S.wrd == dft_cupll->P3S.wrd ? 0x20 : 0x2A, dft_cupll->P3S.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P3S.bf.P3Sscale", tmp_cupll->P3S.bf.P3Sscale, tmp_cupll->P3S.bf.P3Sscale == dft_cupll->P3S.bf.P3Sscale ? 0x20 : 0x2A, dft_cupll->P3S.bf.P3Sscale, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_P3S.bf.P3Sshift", tmp_cupll->P3S.bf.P3Sshift, tmp_cupll->P3S.bf.P3Sshift == dft_cupll->P3S.bf.P3Sshift ? 0x20 : 0x2A, dft_cupll->P3S.bf.P3Sshift, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PRELOADFINT.wrd", tmp_cupll->PRELOADFINT.wrd, tmp_cupll->PRELOADFINT.wrd == dft_cupll->PRELOADFINT.wrd ? 0x20 : 0x2A, dft_cupll->PRELOADFINT.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PRELOADFINT.bf.PreloadFint", tmp_cupll->PRELOADFINT.bf.PreloadFint, tmp_cupll->PRELOADFINT.bf.PreloadFint == dft_cupll->PRELOADFINT.bf.PreloadFint ? 0x20 : 0x2A, dft_cupll->PRELOADFINT.bf.PreloadFint, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PRELOADFFRAC1.wrd", tmp_cupll->PRELOADFFRAC1.wrd, tmp_cupll->PRELOADFFRAC1.wrd == dft_cupll->PRELOADFFRAC1.wrd ? 0x20 : 0x2A, dft_cupll->PRELOADFFRAC1.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PRELOADFFRAC1.bf.PreloadFfrac1", tmp_cupll->PRELOADFFRAC1.bf.PreloadFfrac1, tmp_cupll->PRELOADFFRAC1.bf.PreloadFfrac1 == dft_cupll->PRELOADFFRAC1.bf.PreloadFfrac1 ? 0x20 : 0x2A, dft_cupll->PRELOADFFRAC1.bf.PreloadFfrac1, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PRELOADFFRAC0.wrd", tmp_cupll->PRELOADFFRAC0.wrd, tmp_cupll->PRELOADFFRAC0.wrd == dft_cupll->PRELOADFFRAC0.wrd ? 0x20 : 0x2A, dft_cupll->PRELOADFFRAC0.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_PRELOADFFRAC0.bf.PreloadFfrac0", tmp_cupll->PRELOADFFRAC0.bf.PreloadFfrac0, tmp_cupll->PRELOADFFRAC0.bf.PreloadFfrac0 == dft_cupll->PRELOADFFRAC0.bf.PreloadFfrac0 ? 0x20 : 0x2A, dft_cupll->PRELOADFFRAC0.bf.PreloadFfrac0, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_SD_CFG.wrd", tmp_cupll->SD_CFG.wrd, tmp_cupll->SD_CFG.wrd == dft_cupll->SD_CFG.wrd ? 0x20 : 0x2A, dft_cupll->SD_CFG.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_SD_CFG.bf.SDen", tmp_cupll->SD_CFG.bf.SDen, tmp_cupll->SD_CFG.bf.SDen == dft_cupll->SD_CFG.bf.SDen ? 0x20 : 0x2A, dft_cupll->SD_CFG.bf.SDen, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_FILTER.wrd", tmp_cupll->LOCKDET_FILTER.wrd, tmp_cupll->LOCKDET_FILTER.wrd == dft_cupll->LOCKDET_FILTER.wrd ? 0x20 : 0x2A, dft_cupll->LOCKDET_FILTER.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_FILTER.bf.STABLE_PERIOD", tmp_cupll->LOCKDET_FILTER.bf.STABLE_PERIOD, tmp_cupll->LOCKDET_FILTER.bf.STABLE_PERIOD == dft_cupll->LOCKDET_FILTER.bf.STABLE_PERIOD ? 0x20 : 0x2A, dft_cupll->LOCKDET_FILTER.bf.STABLE_PERIOD, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTERRUPT.wrd", tmp_cupll->LOCKDET_INTERRUPT.wrd, tmp_cupll->LOCKDET_INTERRUPT.wrd == dft_cupll->LOCKDET_INTERRUPT.wrd ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTERRUPT.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTERRUPT.bf.FILT_LOCKi", tmp_cupll->LOCKDET_INTERRUPT.bf.FILT_LOCKi, tmp_cupll->LOCKDET_INTERRUPT.bf.FILT_LOCKi == dft_cupll->LOCKDET_INTERRUPT.bf.FILT_LOCKi ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTERRUPT.bf.FILT_LOCKi, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTERRUPT.bf.BAD_VCO_CLKi", tmp_cupll->LOCKDET_INTERRUPT.bf.BAD_VCO_CLKi, tmp_cupll->LOCKDET_INTERRUPT.bf.BAD_VCO_CLKi == dft_cupll->LOCKDET_INTERRUPT.bf.BAD_VCO_CLKi ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTERRUPT.bf.BAD_VCO_CLKi, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTERRUPT.bf.LOCKi", tmp_cupll->LOCKDET_INTERRUPT.bf.LOCKi, tmp_cupll->LOCKDET_INTERRUPT.bf.LOCKi == dft_cupll->LOCKDET_INTERRUPT.bf.LOCKi ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTERRUPT.bf.LOCKi, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTSTATUS.wrd", tmp_cupll->LOCKDET_INTSTATUS.wrd, tmp_cupll->LOCKDET_INTSTATUS.wrd == dft_cupll->LOCKDET_INTSTATUS.wrd ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTSTATUS.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTSTATUS.bf.FILT_LOCKs", tmp_cupll->LOCKDET_INTSTATUS.bf.FILT_LOCKs, tmp_cupll->LOCKDET_INTSTATUS.bf.FILT_LOCKs == dft_cupll->LOCKDET_INTSTATUS.bf.FILT_LOCKs ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTSTATUS.bf.FILT_LOCKs, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTSTATUS.bf.BAD_VCO_CLKs", tmp_cupll->LOCKDET_INTSTATUS.bf.BAD_VCO_CLKs, tmp_cupll->LOCKDET_INTSTATUS.bf.BAD_VCO_CLKs == dft_cupll->LOCKDET_INTSTATUS.bf.BAD_VCO_CLKs ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTSTATUS.bf.BAD_VCO_CLKs, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTSTATUS.bf.LOCKs", tmp_cupll->LOCKDET_INTSTATUS.bf.LOCKs, tmp_cupll->LOCKDET_INTSTATUS.bf.LOCKs == dft_cupll->LOCKDET_INTSTATUS.bf.LOCKs ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTSTATUS.bf.LOCKs, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTENABLE.wrd", tmp_cupll->LOCKDET_INTENABLE.wrd, tmp_cupll->LOCKDET_INTENABLE.wrd == dft_cupll->LOCKDET_INTENABLE.wrd ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTENABLE.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTENABLE.bf.FILT_LOCKe", tmp_cupll->LOCKDET_INTENABLE.bf.FILT_LOCKe, tmp_cupll->LOCKDET_INTENABLE.bf.FILT_LOCKe == dft_cupll->LOCKDET_INTENABLE.bf.FILT_LOCKe ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTENABLE.bf.FILT_LOCKe, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTENABLE.bf.BAD_VCO_CLKe", tmp_cupll->LOCKDET_INTENABLE.bf.BAD_VCO_CLKe, tmp_cupll->LOCKDET_INTENABLE.bf.BAD_VCO_CLKe == dft_cupll->LOCKDET_INTENABLE.bf.BAD_VCO_CLKe ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTENABLE.bf.BAD_VCO_CLKe, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTENABLE.bf.LOCKe", tmp_cupll->LOCKDET_INTENABLE.bf.LOCKe, tmp_cupll->LOCKDET_INTENABLE.bf.LOCKe == dft_cupll->LOCKDET_INTENABLE.bf.LOCKe ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTENABLE.bf.LOCKe, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTERRUPTZ.wrd", tmp_cupll->LOCKDET_INTERRUPTZ.wrd, tmp_cupll->LOCKDET_INTERRUPTZ.wrd == dft_cupll->LOCKDET_INTERRUPTZ.wrd ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTERRUPTZ.wrd, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTERRUPTZ.bf.FILT_LOCKiZ", tmp_cupll->LOCKDET_INTERRUPTZ.bf.FILT_LOCKiZ, tmp_cupll->LOCKDET_INTERRUPTZ.bf.FILT_LOCKiZ == dft_cupll->LOCKDET_INTERRUPTZ.bf.FILT_LOCKiZ ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTERRUPTZ.bf.FILT_LOCKiZ, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTERRUPTZ.bf.BAD_VCO_CLKiZ", tmp_cupll->LOCKDET_INTERRUPTZ.bf.BAD_VCO_CLKiZ, tmp_cupll->LOCKDET_INTERRUPTZ.bf.BAD_VCO_CLKiZ == dft_cupll->LOCKDET_INTERRUPTZ.bf.BAD_VCO_CLKiZ ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTERRUPTZ.bf.BAD_VCO_CLKiZ, ch1, ch2);
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "XFI_CUPLL_LOCKDET_INTERRUPTZ.bf.LOCKiZ", tmp_cupll->LOCKDET_INTERRUPTZ.bf.LOCKiZ, tmp_cupll->LOCKDET_INTERRUPTZ.bf.LOCKiZ == dft_cupll->LOCKDET_INTERRUPTZ.bf.LOCKiZ ? 0x20 : 0x2A, dft_cupll->LOCKDET_INTERRUPTZ.bf.LOCKiZ, ch1, ch2);
    }   
  } 
  
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
                                                                                                                                                   
  CS_FREE(tmp_cupll);                                                                                                             
  CS_FREE(dft_cupll); 
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
                                                                                                                                                      
  return (CS_OK);                                                                                                                                      
}                                                                                                                                                      
                                                                                                                                                       
