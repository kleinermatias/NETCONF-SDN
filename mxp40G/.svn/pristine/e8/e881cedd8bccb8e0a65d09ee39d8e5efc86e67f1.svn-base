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
 * ten_debug_gfec10g.c
 *
 * APIs for debugging gfec10g
 *
 * $Id: ten_debug_gfec10g.c,v 1.11 2013/03/05 16:11:52 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  GFEC10G DUMP SETTINGS                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_gfec10g_dump_settings(cs_uint16 module_id, cs_uint8 instance)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current GFEC10G settings.                               */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS
  cs_uint16 ii;
  TEN_GFEC10g_t *tmp_gfec10g, *dft_gfec10g;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);                          

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  /* Parameter Checking */
  if ((instance >= TEN_GFEC10G_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.");
    return (CS_ERROR);
  }
 
  tmp_gfec10g = (TEN_GFEC10g_t *)CS_MALLOC(sizeof(TEN_GFEC10g_t));
  dft_gfec10g = (TEN_GFEC10g_t *)CS_MALLOC(sizeof(TEN_GFEC10g_t));
  
  /* Bug #38811: Debug APIs need malloc check for Klocwork warning */
  if ((tmp_gfec10g == 0) || (dft_gfec10g == 0)) {
    if (tmp_gfec10g) {
      CS_FREE(tmp_gfec10g);
    }
    if (dft_gfec10g) {
      CS_FREE(dft_gfec10g);
    }
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  CS_MEMSET((TEN_GFEC10g_t *)tmp_gfec10g, 0, sizeof(TEN_GFEC10g_t));
  CS_MEMSET((TEN_GFEC10g_t *)dft_gfec10g, 0, sizeof(TEN_GFEC10g_t));
  
  dft_gfec10g->RMBYTER0.wrd = TEN_GFEC10G_FRX_RMBYTER0_dft;
  dft_gfec10g->RMBYTER1.wrd = TEN_GFEC10G_FRX_RMBYTER1_dft;
  dft_gfec10g->RZBTER0.wrd = TEN_GFEC10G_FRX_RZBTER0_dft;
  dft_gfec10g->RZBTER1.wrd = TEN_GFEC10G_FRX_RZBTER1_dft;
  dft_gfec10g->ROBTER0.wrd = TEN_GFEC10G_FRX_ROBTER0_dft;
  dft_gfec10g->ROBTER1.wrd = TEN_GFEC10G_FRX_ROBTER1_dft;
  dft_gfec10g->RBYTER0.wrd = TEN_GFEC10G_FRX_RBYTER0_dft;
  dft_gfec10g->RBYTER1.wrd = TEN_GFEC10G_FRX_RBYTER1_dft;
  dft_gfec10g->RERROV0.wrd = TEN_GFEC10G_FRX_RERROV0_dft;
  dft_gfec10g->RERROV1.wrd = TEN_GFEC10G_FRX_RERROV1_dft;
  dft_gfec10g->INTR.wrd = TEN_GFEC10G_FRX_INTR_dft; 
  dft_gfec10g->INTRE.wrd = TEN_GFEC10G_FRX_INTRE_dft;
  dft_gfec10g->INTRO.wrd = TEN_GFEC10G_FRX_INTRO_dft;
  dft_gfec10g->INTRZ.wrd = TEN_GFEC10G_FRX_INTRZ_dft;
  dft_gfec10g->RSCFG.wrd = TEN_GFEC10G_FRX_RSCFG_dft;
  dft_gfec10g->SEED_THR_LOW.wrd = TEN_GFEC10G_FRX_SEED_THR_LOW_dft;
  dft_gfec10g->SEED_THR_UP.wrd = TEN_GFEC10G_FRX_SEED_THR_UP_dft;
  dft_gfec10g->CEED_THR_LOW.wrd = TEN_GFEC10G_FRX_CEED_THR_LOW_dft;
  dft_gfec10g->CEED_THR_UP.wrd = TEN_GFEC10G_FRX_CEED_THR_UP_dft;
  dft_gfec10g->SDEG_THR_LOW.wrd = TEN_GFEC10G_FRX_SDEG_THR_LOW_dft;
  dft_gfec10g->SDEG_THR_UP.wrd = TEN_GFEC10G_FRX_SDEG_THR_UP_dft;
  dft_gfec10g->CDEG_THR_LOW.wrd = TEN_GFEC10G_FRX_CDEG_THR_LOW_dft;
  dft_gfec10g->CDEG_THR_UP.wrd = TEN_GFEC10G_FRX_CDEG_THR_UP_dft;
  dft_gfec10g->ERSEL.wrd = TEN_GFEC10G_FRX_ERSEL_dft;
  dft_gfec10g->TUSEL.wrd = TEN_GFEC10G_FRX_TUSEL_dft;
  dft_gfec10g->EED_WIN.wrd = TEN_GFEC10G_FRX_EED_WIN_dft;
  dft_gfec10g->DEG_WIN.wrd = TEN_GFEC10G_FRX_DEG_WIN_dft;
  dft_gfec10g->EED_DTV_DIV.wrd = TEN_GFEC10G_FRX_EED_DTV_DIV_dft;
  dft_gfec10g->EED_NTV_NIV.wrd = TEN_GFEC10G_FRX_EED_NTV_NIV_dft;
  dft_gfec10g->DEG_DTV_DIV.wrd = TEN_GFEC10G_FRX_DEG_DTV_DIV_dft;
  dft_gfec10g->DEG_NTV_NIV.wrd = TEN_GFEC10G_FRX_DEG_NTV_NIV_dft;
  dft_gfec10g->TXCFG.wrd = TEN_GFEC10G_FTX_TXCFG_dft;
  dft_gfec10g->INTT.wrd = TEN_GFEC10G_FTX_INTT_dft; 
  dft_gfec10g->INTTE.wrd = TEN_GFEC10G_FTX_INTTE_dft;
  dft_gfec10g->INTTO.wrd = TEN_GFEC10G_FTX_INTTO_dft;
  dft_gfec10g->INTTZ.wrd = TEN_GFEC10G_FTX_INTTZ_dft;
  dft_gfec10g->ERRINS1.wrd = TEN_GFEC10G_FTX_ERRINS1_dft;
  dft_gfec10g->ERRINS2.wrd = TEN_GFEC10G_FTX_ERRINS2_dft;
  dft_gfec10g->ERRINS3.wrd = TEN_GFEC10G_FTX_ERRINS3_dft;
  
   for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
  
      tmp_gfec10g->RMBYTER0.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, RMBYTER0) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->RMBYTER1.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, RMBYTER1) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->RZBTER0.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, RZBTER0) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->RZBTER1.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, RZBTER1) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->ROBTER0.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, ROBTER0) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->ROBTER1.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, ROBTER1) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->RBYTER0.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, RBYTER0) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->RBYTER1.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, RBYTER1) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->RERROV0.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, RERROV0) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->RERROV1.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, RERROV1) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->INTR.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, INTR) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->INTRE.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, INTRE) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->INTRO.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, INTRO) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->INTRZ.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, INTRZ) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->RSCFG.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, RSCFG) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->SEED_THR_LOW.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, SEED_THR_LOW) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->SEED_THR_UP.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, SEED_THR_UP) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->CEED_THR_LOW.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, CEED_THR_LOW) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->CEED_THR_UP.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, CEED_THR_UP) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->SDEG_THR_LOW.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, SDEG_THR_LOW) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->SDEG_THR_UP.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, SDEG_THR_UP) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->CDEG_THR_LOW.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, CDEG_THR_LOW) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->CDEG_THR_UP.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, CDEG_THR_UP) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->ERSEL.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, ERSEL) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->TUSEL.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, TUSEL) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->EED_WIN.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, EED_WIN) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->DEG_WIN.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, DEG_WIN) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->EED_DTV_DIV.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, EED_DTV_DIV) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->EED_NTV_NIV.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, EED_NTV_NIV) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->DEG_DTV_DIV.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, DEG_DTV_DIV) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->DEG_NTV_NIV.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, DEG_NTV_NIV) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->TXCFG.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, TXCFG) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->INTT.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, INTT) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->INTTE.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, INTTE) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->INTTO.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, INTTO) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->INTTZ.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, INTTZ) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->ERRINS1.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, ERRINS1) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->ERRINS2.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, ERRINS2) +ii*TEN_GFEC10G_STRIDE);
      tmp_gfec10g->ERRINS3.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, module_id, ERRINS3) +ii*TEN_GFEC10G_STRIDE);

      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RMBYTER0.wrd", tmp_gfec10g->RMBYTER0.wrd, tmp_gfec10g->RMBYTER0.wrd == dft_gfec10g->RMBYTER0.wrd ? 0x20 : 0x2A, dft_gfec10g->RMBYTER0.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RMBYTER0.bf.RMBYTER0", tmp_gfec10g->RMBYTER0.bf.RMBYTER0, tmp_gfec10g->RMBYTER0.bf.RMBYTER0 == dft_gfec10g->RMBYTER0.bf.RMBYTER0 ? 0x20 : 0x2A, dft_gfec10g->RMBYTER0.bf.RMBYTER0, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RMBYTER1.wrd", tmp_gfec10g->RMBYTER1.wrd, tmp_gfec10g->RMBYTER1.wrd == dft_gfec10g->RMBYTER1.wrd ? 0x20 : 0x2A, dft_gfec10g->RMBYTER1.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RMBYTER1.bf.RMBYTER1", tmp_gfec10g->RMBYTER1.bf.RMBYTER1, tmp_gfec10g->RMBYTER1.bf.RMBYTER1 == dft_gfec10g->RMBYTER1.bf.RMBYTER1 ? 0x20 : 0x2A, dft_gfec10g->RMBYTER1.bf.RMBYTER1, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RZBTER0.wrd", tmp_gfec10g->RZBTER0.wrd, tmp_gfec10g->RZBTER0.wrd == dft_gfec10g->RZBTER0.wrd ? 0x20 : 0x2A, dft_gfec10g->RZBTER0.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RZBTER0.bf.RZBTER0", tmp_gfec10g->RZBTER0.bf.RZBTER0, tmp_gfec10g->RZBTER0.bf.RZBTER0 == dft_gfec10g->RZBTER0.bf.RZBTER0 ? 0x20 : 0x2A, dft_gfec10g->RZBTER0.bf.RZBTER0, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RZBTER1.wrd", tmp_gfec10g->RZBTER1.wrd, tmp_gfec10g->RZBTER1.wrd == dft_gfec10g->RZBTER1.wrd ? 0x20 : 0x2A, dft_gfec10g->RZBTER1.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RZBTER1.bf.RZBTER1", tmp_gfec10g->RZBTER1.bf.RZBTER1, tmp_gfec10g->RZBTER1.bf.RZBTER1 == dft_gfec10g->RZBTER1.bf.RZBTER1 ? 0x20 : 0x2A, dft_gfec10g->RZBTER1.bf.RZBTER1, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_ROBTER0.wrd", tmp_gfec10g->ROBTER0.wrd, tmp_gfec10g->ROBTER0.wrd == dft_gfec10g->ROBTER0.wrd ? 0x20 : 0x2A, dft_gfec10g->ROBTER0.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_ROBTER0.bf.ROBTER0", tmp_gfec10g->ROBTER0.bf.ROBTER0, tmp_gfec10g->ROBTER0.bf.ROBTER0 == dft_gfec10g->ROBTER0.bf.ROBTER0 ? 0x20 : 0x2A, dft_gfec10g->ROBTER0.bf.ROBTER0, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_ROBTER1.wrd", tmp_gfec10g->ROBTER1.wrd, tmp_gfec10g->ROBTER1.wrd == dft_gfec10g->ROBTER1.wrd ? 0x20 : 0x2A, dft_gfec10g->ROBTER1.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_ROBTER1.bf.ROBTER1", tmp_gfec10g->ROBTER1.bf.ROBTER1, tmp_gfec10g->ROBTER1.bf.ROBTER1 == dft_gfec10g->ROBTER1.bf.ROBTER1 ? 0x20 : 0x2A, dft_gfec10g->ROBTER1.bf.ROBTER1, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RBYTER0.wrd", tmp_gfec10g->RBYTER0.wrd, tmp_gfec10g->RBYTER0.wrd == dft_gfec10g->RBYTER0.wrd ? 0x20 : 0x2A, dft_gfec10g->RBYTER0.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RBYTER0.bf.RBYTER0", tmp_gfec10g->RBYTER0.bf.RBYTER0, tmp_gfec10g->RBYTER0.bf.RBYTER0 == dft_gfec10g->RBYTER0.bf.RBYTER0 ? 0x20 : 0x2A, dft_gfec10g->RBYTER0.bf.RBYTER0, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RBYTER1.wrd", tmp_gfec10g->RBYTER1.wrd, tmp_gfec10g->RBYTER1.wrd == dft_gfec10g->RBYTER1.wrd ? 0x20 : 0x2A, dft_gfec10g->RBYTER1.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RBYTER1.bf.RBYTER1", tmp_gfec10g->RBYTER1.bf.RBYTER1, tmp_gfec10g->RBYTER1.bf.RBYTER1 == dft_gfec10g->RBYTER1.bf.RBYTER1 ? 0x20 : 0x2A, dft_gfec10g->RBYTER1.bf.RBYTER1, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RERROV0.wrd", tmp_gfec10g->RERROV0.wrd, tmp_gfec10g->RERROV0.wrd == dft_gfec10g->RERROV0.wrd ? 0x20 : 0x2A, dft_gfec10g->RERROV0.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RERROV0.bf.RERROV0", tmp_gfec10g->RERROV0.bf.RERROV0, tmp_gfec10g->RERROV0.bf.RERROV0 == dft_gfec10g->RERROV0.bf.RERROV0 ? 0x20 : 0x2A, dft_gfec10g->RERROV0.bf.RERROV0, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RERROV1.wrd", tmp_gfec10g->RERROV1.wrd, tmp_gfec10g->RERROV1.wrd == dft_gfec10g->RERROV1.wrd ? 0x20 : 0x2A, dft_gfec10g->RERROV1.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RERROV1.bf.RERROV1", tmp_gfec10g->RERROV1.bf.RERROV1, tmp_gfec10g->RERROV1.bf.RERROV1 == dft_gfec10g->RERROV1.bf.RERROV1 ? 0x20 : 0x2A, dft_gfec10g->RERROV1.bf.RERROV1, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.wrd", tmp_gfec10g->INTR.wrd, tmp_gfec10g->INTR.wrd == dft_gfec10g->INTR.wrd ? 0x20 : 0x2A, dft_gfec10g->INTR.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.bf.DBLERR", tmp_gfec10g->INTR.bf.DBLERR, tmp_gfec10g->INTR.bf.DBLERR == dft_gfec10g->INTR.bf.DBLERR ? 0x20 : 0x2A, dft_gfec10g->INTR.bf.DBLERR, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.bf.SGLERR", tmp_gfec10g->INTR.bf.SGLERR, tmp_gfec10g->INTR.bf.SGLERR == dft_gfec10g->INTR.bf.SGLERR ? 0x20 : 0x2A, dft_gfec10g->INTR.bf.SGLERR, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.bf.PTRADJUSTRXOUTB", tmp_gfec10g->INTR.bf.PTRADJUSTRXOUTB, tmp_gfec10g->INTR.bf.PTRADJUSTRXOUTB == dft_gfec10g->INTR.bf.PTRADJUSTRXOUTB ? 0x20 : 0x2A, dft_gfec10g->INTR.bf.PTRADJUSTRXOUTB, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.bf.PTRADJUSTRXINB", tmp_gfec10g->INTR.bf.PTRADJUSTRXINB, tmp_gfec10g->INTR.bf.PTRADJUSTRXINB == dft_gfec10g->INTR.bf.PTRADJUSTRXINB ? 0x20 : 0x2A, dft_gfec10g->INTR.bf.PTRADJUSTRXINB, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.bf.PTRADJUSTRXOUTA", tmp_gfec10g->INTR.bf.PTRADJUSTRXOUTA, tmp_gfec10g->INTR.bf.PTRADJUSTRXOUTA == dft_gfec10g->INTR.bf.PTRADJUSTRXOUTA ? 0x20 : 0x2A, dft_gfec10g->INTR.bf.PTRADJUSTRXOUTA, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.bf.PTRADJUSTRXINA", tmp_gfec10g->INTR.bf.PTRADJUSTRXINA, tmp_gfec10g->INTR.bf.PTRADJUSTRXINA == dft_gfec10g->INTR.bf.PTRADJUSTRXINA ? 0x20 : 0x2A, dft_gfec10g->INTR.bf.PTRADJUSTRXINA, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.bf.DEGINT", tmp_gfec10g->INTR.bf.DEGINT, tmp_gfec10g->INTR.bf.DEGINT == dft_gfec10g->INTR.bf.DEGINT ? 0x20 : 0x2A, dft_gfec10g->INTR.bf.DEGINT, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.bf.EEDINT", tmp_gfec10g->INTR.bf.EEDINT, tmp_gfec10g->INTR.bf.EEDINT == dft_gfec10g->INTR.bf.EEDINT ? 0x20 : 0x2A, dft_gfec10g->INTR.bf.EEDINT, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.bf.IEOV", tmp_gfec10g->INTR.bf.IEOV, tmp_gfec10g->INTR.bf.IEOV == dft_gfec10g->INTR.bf.IEOV ? 0x20 : 0x2A, dft_gfec10g->INTR.bf.IEOV, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTR.bf.IEXE", tmp_gfec10g->INTR.bf.IEXE, tmp_gfec10g->INTR.bf.IEXE == dft_gfec10g->INTR.bf.IEXE ? 0x20 : 0x2A, dft_gfec10g->INTR.bf.IEXE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.wrd", tmp_gfec10g->INTRE.wrd, tmp_gfec10g->INTRE.wrd == dft_gfec10g->INTRE.wrd ? 0x20 : 0x2A, dft_gfec10g->INTRE.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.bf.DBLERRE", tmp_gfec10g->INTRE.bf.DBLERRE, tmp_gfec10g->INTRE.bf.DBLERRE == dft_gfec10g->INTRE.bf.DBLERRE ? 0x20 : 0x2A, dft_gfec10g->INTRE.bf.DBLERRE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.bf.SGLERRE", tmp_gfec10g->INTRE.bf.SGLERRE, tmp_gfec10g->INTRE.bf.SGLERRE == dft_gfec10g->INTRE.bf.SGLERRE ? 0x20 : 0x2A, dft_gfec10g->INTRE.bf.SGLERRE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.bf.PTRADJUSTRXOUTBE", tmp_gfec10g->INTRE.bf.PTRADJUSTRXOUTBE, tmp_gfec10g->INTRE.bf.PTRADJUSTRXOUTBE == dft_gfec10g->INTRE.bf.PTRADJUSTRXOUTBE ? 0x20 : 0x2A, dft_gfec10g->INTRE.bf.PTRADJUSTRXOUTBE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.bf.PTRADJUSTRXINBE", tmp_gfec10g->INTRE.bf.PTRADJUSTRXINBE, tmp_gfec10g->INTRE.bf.PTRADJUSTRXINBE == dft_gfec10g->INTRE.bf.PTRADJUSTRXINBE ? 0x20 : 0x2A, dft_gfec10g->INTRE.bf.PTRADJUSTRXINBE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.bf.PTRADJUSTRXOUTAE", tmp_gfec10g->INTRE.bf.PTRADJUSTRXOUTAE, tmp_gfec10g->INTRE.bf.PTRADJUSTRXOUTAE == dft_gfec10g->INTRE.bf.PTRADJUSTRXOUTAE ? 0x20 : 0x2A, dft_gfec10g->INTRE.bf.PTRADJUSTRXOUTAE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.bf.PTRADJUSTRXINAE", tmp_gfec10g->INTRE.bf.PTRADJUSTRXINAE, tmp_gfec10g->INTRE.bf.PTRADJUSTRXINAE == dft_gfec10g->INTRE.bf.PTRADJUSTRXINAE ? 0x20 : 0x2A, dft_gfec10g->INTRE.bf.PTRADJUSTRXINAE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.bf.DEGINTE", tmp_gfec10g->INTRE.bf.DEGINTE, tmp_gfec10g->INTRE.bf.DEGINTE == dft_gfec10g->INTRE.bf.DEGINTE ? 0x20 : 0x2A, dft_gfec10g->INTRE.bf.DEGINTE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.bf.EEDINTE", tmp_gfec10g->INTRE.bf.EEDINTE, tmp_gfec10g->INTRE.bf.EEDINTE == dft_gfec10g->INTRE.bf.EEDINTE ? 0x20 : 0x2A, dft_gfec10g->INTRE.bf.EEDINTE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.bf.IEOVE", tmp_gfec10g->INTRE.bf.IEOVE, tmp_gfec10g->INTRE.bf.IEOVE == dft_gfec10g->INTRE.bf.IEOVE ? 0x20 : 0x2A, dft_gfec10g->INTRE.bf.IEOVE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRE.bf.IEXEE", tmp_gfec10g->INTRE.bf.IEXEE, tmp_gfec10g->INTRE.bf.IEXEE == dft_gfec10g->INTRE.bf.IEXEE ? 0x20 : 0x2A, dft_gfec10g->INTRE.bf.IEXEE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.wrd", tmp_gfec10g->INTRO.wrd, tmp_gfec10g->INTRO.wrd == dft_gfec10g->INTRO.wrd ? 0x20 : 0x2A, dft_gfec10g->INTRO.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.bf.DBLERRS", tmp_gfec10g->INTRO.bf.DBLERRS, tmp_gfec10g->INTRO.bf.DBLERRS == dft_gfec10g->INTRO.bf.DBLERRS ? 0x20 : 0x2A, dft_gfec10g->INTRO.bf.DBLERRS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.bf.SGLERRS", tmp_gfec10g->INTRO.bf.SGLERRS, tmp_gfec10g->INTRO.bf.SGLERRS == dft_gfec10g->INTRO.bf.SGLERRS ? 0x20 : 0x2A, dft_gfec10g->INTRO.bf.SGLERRS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.bf.PTRADJUSTRXOUTBS", tmp_gfec10g->INTRO.bf.PTRADJUSTRXOUTBS, tmp_gfec10g->INTRO.bf.PTRADJUSTRXOUTBS == dft_gfec10g->INTRO.bf.PTRADJUSTRXOUTBS ? 0x20 : 0x2A, dft_gfec10g->INTRO.bf.PTRADJUSTRXOUTBS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.bf.PTRADJUSTRXINBS", tmp_gfec10g->INTRO.bf.PTRADJUSTRXINBS, tmp_gfec10g->INTRO.bf.PTRADJUSTRXINBS == dft_gfec10g->INTRO.bf.PTRADJUSTRXINBS ? 0x20 : 0x2A, dft_gfec10g->INTRO.bf.PTRADJUSTRXINBS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.bf.PTRADJUSTRXOUTAS", tmp_gfec10g->INTRO.bf.PTRADJUSTRXOUTAS, tmp_gfec10g->INTRO.bf.PTRADJUSTRXOUTAS == dft_gfec10g->INTRO.bf.PTRADJUSTRXOUTAS ? 0x20 : 0x2A, dft_gfec10g->INTRO.bf.PTRADJUSTRXOUTAS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.bf.PTRADJUSTRXINAS", tmp_gfec10g->INTRO.bf.PTRADJUSTRXINAS, tmp_gfec10g->INTRO.bf.PTRADJUSTRXINAS == dft_gfec10g->INTRO.bf.PTRADJUSTRXINAS ? 0x20 : 0x2A, dft_gfec10g->INTRO.bf.PTRADJUSTRXINAS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.bf.DEGINTS", tmp_gfec10g->INTRO.bf.DEGINTS, tmp_gfec10g->INTRO.bf.DEGINTS == dft_gfec10g->INTRO.bf.DEGINTS ? 0x20 : 0x2A, dft_gfec10g->INTRO.bf.DEGINTS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.bf.EEDINTS", tmp_gfec10g->INTRO.bf.EEDINTS, tmp_gfec10g->INTRO.bf.EEDINTS == dft_gfec10g->INTRO.bf.EEDINTS ? 0x20 : 0x2A, dft_gfec10g->INTRO.bf.EEDINTS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.bf.IEOVO", tmp_gfec10g->INTRO.bf.IEOVO, tmp_gfec10g->INTRO.bf.IEOVO == dft_gfec10g->INTRO.bf.IEOVO ? 0x20 : 0x2A, dft_gfec10g->INTRO.bf.IEOVO, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRO.bf.IEXEO", tmp_gfec10g->INTRO.bf.IEXEO, tmp_gfec10g->INTRO.bf.IEXEO == dft_gfec10g->INTRO.bf.IEXEO ? 0x20 : 0x2A, dft_gfec10g->INTRO.bf.IEXEO, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.wrd", tmp_gfec10g->INTRZ.wrd, tmp_gfec10g->INTRZ.wrd == dft_gfec10g->INTRZ.wrd ? 0x20 : 0x2A, dft_gfec10g->INTRZ.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.bf.DBLERRZ", tmp_gfec10g->INTRZ.bf.DBLERRZ, tmp_gfec10g->INTRZ.bf.DBLERRZ == dft_gfec10g->INTRZ.bf.DBLERRZ ? 0x20 : 0x2A, dft_gfec10g->INTRZ.bf.DBLERRZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.bf.SGLERRZ", tmp_gfec10g->INTRZ.bf.SGLERRZ, tmp_gfec10g->INTRZ.bf.SGLERRZ == dft_gfec10g->INTRZ.bf.SGLERRZ ? 0x20 : 0x2A, dft_gfec10g->INTRZ.bf.SGLERRZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.bf.PTRADJUSTRXOUTBZ", tmp_gfec10g->INTRZ.bf.PTRADJUSTRXOUTBZ, tmp_gfec10g->INTRZ.bf.PTRADJUSTRXOUTBZ == dft_gfec10g->INTRZ.bf.PTRADJUSTRXOUTBZ ? 0x20 : 0x2A, dft_gfec10g->INTRZ.bf.PTRADJUSTRXOUTBZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.bf.PTRADJUSTRXINBZ", tmp_gfec10g->INTRZ.bf.PTRADJUSTRXINBZ, tmp_gfec10g->INTRZ.bf.PTRADJUSTRXINBZ == dft_gfec10g->INTRZ.bf.PTRADJUSTRXINBZ ? 0x20 : 0x2A, dft_gfec10g->INTRZ.bf.PTRADJUSTRXINBZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.bf.PTRADJUSTRXOUTAZ", tmp_gfec10g->INTRZ.bf.PTRADJUSTRXOUTAZ, tmp_gfec10g->INTRZ.bf.PTRADJUSTRXOUTAZ == dft_gfec10g->INTRZ.bf.PTRADJUSTRXOUTAZ ? 0x20 : 0x2A, dft_gfec10g->INTRZ.bf.PTRADJUSTRXOUTAZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.bf.PTRADJUSTRXINAZ", tmp_gfec10g->INTRZ.bf.PTRADJUSTRXINAZ, tmp_gfec10g->INTRZ.bf.PTRADJUSTRXINAZ == dft_gfec10g->INTRZ.bf.PTRADJUSTRXINAZ ? 0x20 : 0x2A, dft_gfec10g->INTRZ.bf.PTRADJUSTRXINAZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.bf.DEGINTZ", tmp_gfec10g->INTRZ.bf.DEGINTZ, tmp_gfec10g->INTRZ.bf.DEGINTZ == dft_gfec10g->INTRZ.bf.DEGINTZ ? 0x20 : 0x2A, dft_gfec10g->INTRZ.bf.DEGINTZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.bf.EEDINTZ", tmp_gfec10g->INTRZ.bf.EEDINTZ, tmp_gfec10g->INTRZ.bf.EEDINTZ == dft_gfec10g->INTRZ.bf.EEDINTZ ? 0x20 : 0x2A, dft_gfec10g->INTRZ.bf.EEDINTZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.bf.IEOVZ", tmp_gfec10g->INTRZ.bf.IEOVZ, tmp_gfec10g->INTRZ.bf.IEOVZ == dft_gfec10g->INTRZ.bf.IEOVZ ? 0x20 : 0x2A, dft_gfec10g->INTRZ.bf.IEOVZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_INTRZ.bf.IEXEZ", tmp_gfec10g->INTRZ.bf.IEXEZ, tmp_gfec10g->INTRZ.bf.IEXEZ == dft_gfec10g->INTRZ.bf.IEXEZ ? 0x20 : 0x2A, dft_gfec10g->INTRZ.bf.IEXEZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.wrd", tmp_gfec10g->RSCFG.wrd, tmp_gfec10g->RSCFG.wrd == dft_gfec10g->RSCFG.wrd ? 0x20 : 0x2A, dft_gfec10g->RSCFG.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.bf.RXRST", tmp_gfec10g->RSCFG.bf.RXRST, tmp_gfec10g->RSCFG.bf.RXRST == dft_gfec10g->RSCFG.bf.RXRST ? 0x20 : 0x2A, dft_gfec10g->RSCFG.bf.RXRST, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.bf.CORE", tmp_gfec10g->RSCFG.bf.CORE, tmp_gfec10g->RSCFG.bf.CORE == dft_gfec10g->RSCFG.bf.CORE ? 0x20 : 0x2A, dft_gfec10g->RSCFG.bf.CORE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.bf.DECE", tmp_gfec10g->RSCFG.bf.DECE, tmp_gfec10g->RSCFG.bf.DECE == dft_gfec10g->RSCFG.bf.DECE ? 0x20 : 0x2A, dft_gfec10g->RSCFG.bf.DECE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.bf.STATSCREn", tmp_gfec10g->RSCFG.bf.STATSCREn, tmp_gfec10g->RSCFG.bf.STATSCREn == dft_gfec10g->RSCFG.bf.STATSCREn ? 0x20 : 0x2A, dft_gfec10g->RSCFG.bf.STATSCREn, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.bf.PTRREINITRXOUTB", tmp_gfec10g->RSCFG.bf.PTRREINITRXOUTB, tmp_gfec10g->RSCFG.bf.PTRREINITRXOUTB == dft_gfec10g->RSCFG.bf.PTRREINITRXOUTB ? 0x20 : 0x2A, dft_gfec10g->RSCFG.bf.PTRREINITRXOUTB, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.bf.PTRREINITRXINB", tmp_gfec10g->RSCFG.bf.PTRREINITRXINB, tmp_gfec10g->RSCFG.bf.PTRREINITRXINB == dft_gfec10g->RSCFG.bf.PTRREINITRXINB ? 0x20 : 0x2A, dft_gfec10g->RSCFG.bf.PTRREINITRXINB, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.bf.PTRREINITRXOUTA", tmp_gfec10g->RSCFG.bf.PTRREINITRXOUTA, tmp_gfec10g->RSCFG.bf.PTRREINITRXOUTA == dft_gfec10g->RSCFG.bf.PTRREINITRXOUTA ? 0x20 : 0x2A, dft_gfec10g->RSCFG.bf.PTRREINITRXOUTA, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.bf.PTRREINITRXINA", tmp_gfec10g->RSCFG.bf.PTRREINITRXINA, tmp_gfec10g->RSCFG.bf.PTRREINITRXINA == dft_gfec10g->RSCFG.bf.PTRREINITRXINA ? 0x20 : 0x2A, dft_gfec10g->RSCFG.bf.PTRREINITRXINA, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.bf.EXESEL", tmp_gfec10g->RSCFG.bf.EXESEL, tmp_gfec10g->RSCFG.bf.EXESEL == dft_gfec10g->RSCFG.bf.EXESEL ? 0x20 : 0x2A, dft_gfec10g->RSCFG.bf.EXESEL, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_RSCFG.bf.GISEL", tmp_gfec10g->RSCFG.bf.GISEL, tmp_gfec10g->RSCFG.bf.GISEL == dft_gfec10g->RSCFG.bf.GISEL ? 0x20 : 0x2A, dft_gfec10g->RSCFG.bf.GISEL, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_SEED_THR_LOW.wrd", tmp_gfec10g->SEED_THR_LOW.wrd, tmp_gfec10g->SEED_THR_LOW.wrd == dft_gfec10g->SEED_THR_LOW.wrd ? 0x20 : 0x2A, dft_gfec10g->SEED_THR_LOW.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_SEED_THR_LOW.bf.seed_thr_low", tmp_gfec10g->SEED_THR_LOW.bf.seed_thr_low, tmp_gfec10g->SEED_THR_LOW.bf.seed_thr_low == dft_gfec10g->SEED_THR_LOW.bf.seed_thr_low ? 0x20 : 0x2A, dft_gfec10g->SEED_THR_LOW.bf.seed_thr_low, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_SEED_THR_UP.wrd", tmp_gfec10g->SEED_THR_UP.wrd, tmp_gfec10g->SEED_THR_UP.wrd == dft_gfec10g->SEED_THR_UP.wrd ? 0x20 : 0x2A, dft_gfec10g->SEED_THR_UP.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_SEED_THR_UP.bf.seed_thr_up", tmp_gfec10g->SEED_THR_UP.bf.seed_thr_up, tmp_gfec10g->SEED_THR_UP.bf.seed_thr_up == dft_gfec10g->SEED_THR_UP.bf.seed_thr_up ? 0x20 : 0x2A, dft_gfec10g->SEED_THR_UP.bf.seed_thr_up, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_CEED_THR_LOW.wrd", tmp_gfec10g->CEED_THR_LOW.wrd, tmp_gfec10g->CEED_THR_LOW.wrd == dft_gfec10g->CEED_THR_LOW.wrd ? 0x20 : 0x2A, dft_gfec10g->CEED_THR_LOW.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_CEED_THR_LOW.bf.ceed_thr_low", tmp_gfec10g->CEED_THR_LOW.bf.ceed_thr_low, tmp_gfec10g->CEED_THR_LOW.bf.ceed_thr_low == dft_gfec10g->CEED_THR_LOW.bf.ceed_thr_low ? 0x20 : 0x2A, dft_gfec10g->CEED_THR_LOW.bf.ceed_thr_low, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_CEED_THR_UP.wrd", tmp_gfec10g->CEED_THR_UP.wrd, tmp_gfec10g->CEED_THR_UP.wrd == dft_gfec10g->CEED_THR_UP.wrd ? 0x20 : 0x2A, dft_gfec10g->CEED_THR_UP.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_CEED_THR_UP.bf.ceed_thr_up", tmp_gfec10g->CEED_THR_UP.bf.ceed_thr_up, tmp_gfec10g->CEED_THR_UP.bf.ceed_thr_up == dft_gfec10g->CEED_THR_UP.bf.ceed_thr_up ? 0x20 : 0x2A, dft_gfec10g->CEED_THR_UP.bf.ceed_thr_up, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_SDEG_THR_LOW.wrd", tmp_gfec10g->SDEG_THR_LOW.wrd, tmp_gfec10g->SDEG_THR_LOW.wrd == dft_gfec10g->SDEG_THR_LOW.wrd ? 0x20 : 0x2A, dft_gfec10g->SDEG_THR_LOW.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_SDEG_THR_LOW.bf.sdeg_thr_low", tmp_gfec10g->SDEG_THR_LOW.bf.sdeg_thr_low, tmp_gfec10g->SDEG_THR_LOW.bf.sdeg_thr_low == dft_gfec10g->SDEG_THR_LOW.bf.sdeg_thr_low ? 0x20 : 0x2A, dft_gfec10g->SDEG_THR_LOW.bf.sdeg_thr_low, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_SDEG_THR_UP.wrd", tmp_gfec10g->SDEG_THR_UP.wrd, tmp_gfec10g->SDEG_THR_UP.wrd == dft_gfec10g->SDEG_THR_UP.wrd ? 0x20 : 0x2A, dft_gfec10g->SDEG_THR_UP.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_SDEG_THR_UP.bf.sdeg_thr_up", tmp_gfec10g->SDEG_THR_UP.bf.sdeg_thr_up, tmp_gfec10g->SDEG_THR_UP.bf.sdeg_thr_up == dft_gfec10g->SDEG_THR_UP.bf.sdeg_thr_up ? 0x20 : 0x2A, dft_gfec10g->SDEG_THR_UP.bf.sdeg_thr_up, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_CDEG_THR_LOW.wrd", tmp_gfec10g->CDEG_THR_LOW.wrd, tmp_gfec10g->CDEG_THR_LOW.wrd == dft_gfec10g->CDEG_THR_LOW.wrd ? 0x20 : 0x2A, dft_gfec10g->CDEG_THR_LOW.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_CDEG_THR_LOW.bf.cdeg_thr_low", tmp_gfec10g->CDEG_THR_LOW.bf.cdeg_thr_low, tmp_gfec10g->CDEG_THR_LOW.bf.cdeg_thr_low == dft_gfec10g->CDEG_THR_LOW.bf.cdeg_thr_low ? 0x20 : 0x2A, dft_gfec10g->CDEG_THR_LOW.bf.cdeg_thr_low, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_CDEG_THR_UP.wrd", tmp_gfec10g->CDEG_THR_UP.wrd, tmp_gfec10g->CDEG_THR_UP.wrd == dft_gfec10g->CDEG_THR_UP.wrd ? 0x20 : 0x2A, dft_gfec10g->CDEG_THR_UP.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_CDEG_THR_UP.bf.cdeg_thr_up", tmp_gfec10g->CDEG_THR_UP.bf.cdeg_thr_up, tmp_gfec10g->CDEG_THR_UP.bf.cdeg_thr_up == dft_gfec10g->CDEG_THR_UP.bf.cdeg_thr_up ? 0x20 : 0x2A, dft_gfec10g->CDEG_THR_UP.bf.cdeg_thr_up, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_ERSEL.wrd", tmp_gfec10g->ERSEL.wrd, tmp_gfec10g->ERSEL.wrd == dft_gfec10g->ERSEL.wrd ? 0x20 : 0x2A, dft_gfec10g->ERSEL.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_ERSEL.bf.cdeg_ersel", tmp_gfec10g->ERSEL.bf.cdeg_ersel, tmp_gfec10g->ERSEL.bf.cdeg_ersel == dft_gfec10g->ERSEL.bf.cdeg_ersel ? 0x20 : 0x2A, dft_gfec10g->ERSEL.bf.cdeg_ersel, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_ERSEL.bf.sdeg_ersel", tmp_gfec10g->ERSEL.bf.sdeg_ersel, tmp_gfec10g->ERSEL.bf.sdeg_ersel == dft_gfec10g->ERSEL.bf.sdeg_ersel ? 0x20 : 0x2A, dft_gfec10g->ERSEL.bf.sdeg_ersel, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_ERSEL.bf.ceed_ersel", tmp_gfec10g->ERSEL.bf.ceed_ersel, tmp_gfec10g->ERSEL.bf.ceed_ersel == dft_gfec10g->ERSEL.bf.ceed_ersel ? 0x20 : 0x2A, dft_gfec10g->ERSEL.bf.ceed_ersel, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_ERSEL.bf.seed_ersel", tmp_gfec10g->ERSEL.bf.seed_ersel, tmp_gfec10g->ERSEL.bf.seed_ersel == dft_gfec10g->ERSEL.bf.seed_ersel ? 0x20 : 0x2A, dft_gfec10g->ERSEL.bf.seed_ersel, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_TUSEL.wrd", tmp_gfec10g->TUSEL.wrd, tmp_gfec10g->TUSEL.wrd == dft_gfec10g->TUSEL.wrd ? 0x20 : 0x2A, dft_gfec10g->TUSEL.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_TUSEL.bf.deg_tusel", tmp_gfec10g->TUSEL.bf.deg_tusel, tmp_gfec10g->TUSEL.bf.deg_tusel == dft_gfec10g->TUSEL.bf.deg_tusel ? 0x20 : 0x2A, dft_gfec10g->TUSEL.bf.deg_tusel, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_TUSEL.bf.eed_tusel", tmp_gfec10g->TUSEL.bf.eed_tusel, tmp_gfec10g->TUSEL.bf.eed_tusel == dft_gfec10g->TUSEL.bf.eed_tusel ? 0x20 : 0x2A, dft_gfec10g->TUSEL.bf.eed_tusel, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_EED_WIN.wrd", tmp_gfec10g->EED_WIN.wrd, tmp_gfec10g->EED_WIN.wrd == dft_gfec10g->EED_WIN.wrd ? 0x20 : 0x2A, dft_gfec10g->EED_WIN.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_EED_WIN.bf.ceed_win", tmp_gfec10g->EED_WIN.bf.ceed_win, tmp_gfec10g->EED_WIN.bf.ceed_win == dft_gfec10g->EED_WIN.bf.ceed_win ? 0x20 : 0x2A, dft_gfec10g->EED_WIN.bf.ceed_win, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_EED_WIN.bf.seed_win", tmp_gfec10g->EED_WIN.bf.seed_win, tmp_gfec10g->EED_WIN.bf.seed_win == dft_gfec10g->EED_WIN.bf.seed_win ? 0x20 : 0x2A, dft_gfec10g->EED_WIN.bf.seed_win, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_DEG_WIN.wrd", tmp_gfec10g->DEG_WIN.wrd, tmp_gfec10g->DEG_WIN.wrd == dft_gfec10g->DEG_WIN.wrd ? 0x20 : 0x2A, dft_gfec10g->DEG_WIN.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_DEG_WIN.bf.cdeg_win", tmp_gfec10g->DEG_WIN.bf.cdeg_win, tmp_gfec10g->DEG_WIN.bf.cdeg_win == dft_gfec10g->DEG_WIN.bf.cdeg_win ? 0x20 : 0x2A, dft_gfec10g->DEG_WIN.bf.cdeg_win, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_DEG_WIN.bf.sdeg_win", tmp_gfec10g->DEG_WIN.bf.sdeg_win, tmp_gfec10g->DEG_WIN.bf.sdeg_win == dft_gfec10g->DEG_WIN.bf.sdeg_win ? 0x20 : 0x2A, dft_gfec10g->DEG_WIN.bf.sdeg_win, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_EED_DTV_DIV.wrd", tmp_gfec10g->EED_DTV_DIV.wrd, tmp_gfec10g->EED_DTV_DIV.wrd == dft_gfec10g->EED_DTV_DIV.wrd ? 0x20 : 0x2A, dft_gfec10g->EED_DTV_DIV.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_EED_DTV_DIV.bf.seed_div", tmp_gfec10g->EED_DTV_DIV.bf.seed_div, tmp_gfec10g->EED_DTV_DIV.bf.seed_div == dft_gfec10g->EED_DTV_DIV.bf.seed_div ? 0x20 : 0x2A, dft_gfec10g->EED_DTV_DIV.bf.seed_div, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_EED_DTV_DIV.bf.seed_dtv", tmp_gfec10g->EED_DTV_DIV.bf.seed_dtv, tmp_gfec10g->EED_DTV_DIV.bf.seed_dtv == dft_gfec10g->EED_DTV_DIV.bf.seed_dtv ? 0x20 : 0x2A, dft_gfec10g->EED_DTV_DIV.bf.seed_dtv, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_EED_NTV_NIV.wrd", tmp_gfec10g->EED_NTV_NIV.wrd, tmp_gfec10g->EED_NTV_NIV.wrd == dft_gfec10g->EED_NTV_NIV.wrd ? 0x20 : 0x2A, dft_gfec10g->EED_NTV_NIV.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_EED_NTV_NIV.bf.ceed_niv", tmp_gfec10g->EED_NTV_NIV.bf.ceed_niv, tmp_gfec10g->EED_NTV_NIV.bf.ceed_niv == dft_gfec10g->EED_NTV_NIV.bf.ceed_niv ? 0x20 : 0x2A, dft_gfec10g->EED_NTV_NIV.bf.ceed_niv, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_EED_NTV_NIV.bf.ceed_ntv", tmp_gfec10g->EED_NTV_NIV.bf.ceed_ntv, tmp_gfec10g->EED_NTV_NIV.bf.ceed_ntv == dft_gfec10g->EED_NTV_NIV.bf.ceed_ntv ? 0x20 : 0x2A, dft_gfec10g->EED_NTV_NIV.bf.ceed_ntv, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_DEG_DTV_DIV.wrd", tmp_gfec10g->DEG_DTV_DIV.wrd, tmp_gfec10g->DEG_DTV_DIV.wrd == dft_gfec10g->DEG_DTV_DIV.wrd ? 0x20 : 0x2A, dft_gfec10g->DEG_DTV_DIV.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_DEG_DTV_DIV.bf.sdeg_div", tmp_gfec10g->DEG_DTV_DIV.bf.sdeg_div, tmp_gfec10g->DEG_DTV_DIV.bf.sdeg_div == dft_gfec10g->DEG_DTV_DIV.bf.sdeg_div ? 0x20 : 0x2A, dft_gfec10g->DEG_DTV_DIV.bf.sdeg_div, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_DEG_DTV_DIV.bf.sdeg_dtv", tmp_gfec10g->DEG_DTV_DIV.bf.sdeg_dtv, tmp_gfec10g->DEG_DTV_DIV.bf.sdeg_dtv == dft_gfec10g->DEG_DTV_DIV.bf.sdeg_dtv ? 0x20 : 0x2A, dft_gfec10g->DEG_DTV_DIV.bf.sdeg_dtv, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_DEG_NTV_NIV.wrd", tmp_gfec10g->DEG_NTV_NIV.wrd, tmp_gfec10g->DEG_NTV_NIV.wrd == dft_gfec10g->DEG_NTV_NIV.wrd ? 0x20 : 0x2A, dft_gfec10g->DEG_NTV_NIV.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_DEG_NTV_NIV.bf.cdeg_niv", tmp_gfec10g->DEG_NTV_NIV.bf.cdeg_niv, tmp_gfec10g->DEG_NTV_NIV.bf.cdeg_niv == dft_gfec10g->DEG_NTV_NIV.bf.cdeg_niv ? 0x20 : 0x2A, dft_gfec10g->DEG_NTV_NIV.bf.cdeg_niv, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FRX_DEG_NTV_NIV.bf.cdeg_ntv", tmp_gfec10g->DEG_NTV_NIV.bf.cdeg_ntv, tmp_gfec10g->DEG_NTV_NIV.bf.cdeg_ntv == dft_gfec10g->DEG_NTV_NIV.bf.cdeg_ntv ? 0x20 : 0x2A, dft_gfec10g->DEG_NTV_NIV.bf.cdeg_ntv, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_TXCFG.wrd", tmp_gfec10g->TXCFG.wrd, tmp_gfec10g->TXCFG.wrd == dft_gfec10g->TXCFG.wrd ? 0x20 : 0x2A, dft_gfec10g->TXCFG.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_TXCFG.bf.TXRST", tmp_gfec10g->TXCFG.bf.TXRST, tmp_gfec10g->TXCFG.bf.TXRST == dft_gfec10g->TXCFG.bf.TXRST ? 0x20 : 0x2A, dft_gfec10g->TXCFG.bf.TXRST, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_TXCFG.bf.PTRREINITTXOUTB", tmp_gfec10g->TXCFG.bf.PTRREINITTXOUTB, tmp_gfec10g->TXCFG.bf.PTRREINITTXOUTB == dft_gfec10g->TXCFG.bf.PTRREINITTXOUTB ? 0x20 : 0x2A, dft_gfec10g->TXCFG.bf.PTRREINITTXOUTB, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_TXCFG.bf.PTRREINITTXINB", tmp_gfec10g->TXCFG.bf.PTRREINITTXINB, tmp_gfec10g->TXCFG.bf.PTRREINITTXINB == dft_gfec10g->TXCFG.bf.PTRREINITTXINB ? 0x20 : 0x2A, dft_gfec10g->TXCFG.bf.PTRREINITTXINB, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_TXCFG.bf.PTRREINITTXOUTA", tmp_gfec10g->TXCFG.bf.PTRREINITTXOUTA, tmp_gfec10g->TXCFG.bf.PTRREINITTXOUTA == dft_gfec10g->TXCFG.bf.PTRREINITTXOUTA ? 0x20 : 0x2A, dft_gfec10g->TXCFG.bf.PTRREINITTXOUTA, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_TXCFG.bf.PTRREINITTXINA", tmp_gfec10g->TXCFG.bf.PTRREINITTXINA, tmp_gfec10g->TXCFG.bf.PTRREINITTXINA == dft_gfec10g->TXCFG.bf.PTRREINITTXINA ? 0x20 : 0x2A, dft_gfec10g->TXCFG.bf.PTRREINITTXINA, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_TXCFG.bf.disTxpar", tmp_gfec10g->TXCFG.bf.disTxpar, tmp_gfec10g->TXCFG.bf.disTxpar == dft_gfec10g->TXCFG.bf.disTxpar ? 0x20 : 0x2A, dft_gfec10g->TXCFG.bf.disTxpar, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTT.wrd", tmp_gfec10g->INTT.wrd, tmp_gfec10g->INTT.wrd == dft_gfec10g->INTT.wrd ? 0x20 : 0x2A, dft_gfec10g->INTT.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTT.bf.PTRADJUSTTXOUTB", tmp_gfec10g->INTT.bf.PTRADJUSTTXOUTB, tmp_gfec10g->INTT.bf.PTRADJUSTTXOUTB == dft_gfec10g->INTT.bf.PTRADJUSTTXOUTB ? 0x20 : 0x2A, dft_gfec10g->INTT.bf.PTRADJUSTTXOUTB, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTT.bf.PTRADJUSTTXINB", tmp_gfec10g->INTT.bf.PTRADJUSTTXINB, tmp_gfec10g->INTT.bf.PTRADJUSTTXINB == dft_gfec10g->INTT.bf.PTRADJUSTTXINB ? 0x20 : 0x2A, dft_gfec10g->INTT.bf.PTRADJUSTTXINB, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTT.bf.PTRADJUSTTXOUTA", tmp_gfec10g->INTT.bf.PTRADJUSTTXOUTA, tmp_gfec10g->INTT.bf.PTRADJUSTTXOUTA == dft_gfec10g->INTT.bf.PTRADJUSTTXOUTA ? 0x20 : 0x2A, dft_gfec10g->INTT.bf.PTRADJUSTTXOUTA, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTT.bf.PTRADJUSTTXINA", tmp_gfec10g->INTT.bf.PTRADJUSTTXINA, tmp_gfec10g->INTT.bf.PTRADJUSTTXINA == dft_gfec10g->INTT.bf.PTRADJUSTTXINA ? 0x20 : 0x2A, dft_gfec10g->INTT.bf.PTRADJUSTTXINA, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTE.wrd", tmp_gfec10g->INTTE.wrd, tmp_gfec10g->INTTE.wrd == dft_gfec10g->INTTE.wrd ? 0x20 : 0x2A, dft_gfec10g->INTTE.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTE.bf.PTRADJUSTTXOUTBE", tmp_gfec10g->INTTE.bf.PTRADJUSTTXOUTBE, tmp_gfec10g->INTTE.bf.PTRADJUSTTXOUTBE == dft_gfec10g->INTTE.bf.PTRADJUSTTXOUTBE ? 0x20 : 0x2A, dft_gfec10g->INTTE.bf.PTRADJUSTTXOUTBE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTE.bf.PTRADJUSTTXINBE", tmp_gfec10g->INTTE.bf.PTRADJUSTTXINBE, tmp_gfec10g->INTTE.bf.PTRADJUSTTXINBE == dft_gfec10g->INTTE.bf.PTRADJUSTTXINBE ? 0x20 : 0x2A, dft_gfec10g->INTTE.bf.PTRADJUSTTXINBE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTE.bf.PTRADJUSTTXOUTAE", tmp_gfec10g->INTTE.bf.PTRADJUSTTXOUTAE, tmp_gfec10g->INTTE.bf.PTRADJUSTTXOUTAE == dft_gfec10g->INTTE.bf.PTRADJUSTTXOUTAE ? 0x20 : 0x2A, dft_gfec10g->INTTE.bf.PTRADJUSTTXOUTAE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTE.bf.PTRADJUSTTXINAE", tmp_gfec10g->INTTE.bf.PTRADJUSTTXINAE, tmp_gfec10g->INTTE.bf.PTRADJUSTTXINAE == dft_gfec10g->INTTE.bf.PTRADJUSTTXINAE ? 0x20 : 0x2A, dft_gfec10g->INTTE.bf.PTRADJUSTTXINAE, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTO.wrd", tmp_gfec10g->INTTO.wrd, tmp_gfec10g->INTTO.wrd == dft_gfec10g->INTTO.wrd ? 0x20 : 0x2A, dft_gfec10g->INTTO.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTO.bf.PTRADJUSTTXOUTBS", tmp_gfec10g->INTTO.bf.PTRADJUSTTXOUTBS, tmp_gfec10g->INTTO.bf.PTRADJUSTTXOUTBS == dft_gfec10g->INTTO.bf.PTRADJUSTTXOUTBS ? 0x20 : 0x2A, dft_gfec10g->INTTO.bf.PTRADJUSTTXOUTBS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTO.bf.PTRADJUSTTXINBS", tmp_gfec10g->INTTO.bf.PTRADJUSTTXINBS, tmp_gfec10g->INTTO.bf.PTRADJUSTTXINBS == dft_gfec10g->INTTO.bf.PTRADJUSTTXINBS ? 0x20 : 0x2A, dft_gfec10g->INTTO.bf.PTRADJUSTTXINBS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTO.bf.PTRADJUSTTXOUTAS", tmp_gfec10g->INTTO.bf.PTRADJUSTTXOUTAS, tmp_gfec10g->INTTO.bf.PTRADJUSTTXOUTAS == dft_gfec10g->INTTO.bf.PTRADJUSTTXOUTAS ? 0x20 : 0x2A, dft_gfec10g->INTTO.bf.PTRADJUSTTXOUTAS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTO.bf.PTRADJUSTTXINAS", tmp_gfec10g->INTTO.bf.PTRADJUSTTXINAS, tmp_gfec10g->INTTO.bf.PTRADJUSTTXINAS == dft_gfec10g->INTTO.bf.PTRADJUSTTXINAS ? 0x20 : 0x2A, dft_gfec10g->INTTO.bf.PTRADJUSTTXINAS, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTZ.wrd", tmp_gfec10g->INTTZ.wrd, tmp_gfec10g->INTTZ.wrd == dft_gfec10g->INTTZ.wrd ? 0x20 : 0x2A, dft_gfec10g->INTTZ.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTZ.bf.PTRADJUSTTXOUTBZ", tmp_gfec10g->INTTZ.bf.PTRADJUSTTXOUTBZ, tmp_gfec10g->INTTZ.bf.PTRADJUSTTXOUTBZ == dft_gfec10g->INTTZ.bf.PTRADJUSTTXOUTBZ ? 0x20 : 0x2A, dft_gfec10g->INTTZ.bf.PTRADJUSTTXOUTBZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTZ.bf.PTRADJUSTTXINBZ", tmp_gfec10g->INTTZ.bf.PTRADJUSTTXINBZ, tmp_gfec10g->INTTZ.bf.PTRADJUSTTXINBZ == dft_gfec10g->INTTZ.bf.PTRADJUSTTXINBZ ? 0x20 : 0x2A, dft_gfec10g->INTTZ.bf.PTRADJUSTTXINBZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTZ.bf.PTRADJUSTTXOUTAZ", tmp_gfec10g->INTTZ.bf.PTRADJUSTTXOUTAZ, tmp_gfec10g->INTTZ.bf.PTRADJUSTTXOUTAZ == dft_gfec10g->INTTZ.bf.PTRADJUSTTXOUTAZ ? 0x20 : 0x2A, dft_gfec10g->INTTZ.bf.PTRADJUSTTXOUTAZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_INTTZ.bf.PTRADJUSTTXINAZ", tmp_gfec10g->INTTZ.bf.PTRADJUSTTXINAZ, tmp_gfec10g->INTTZ.bf.PTRADJUSTTXINAZ == dft_gfec10g->INTTZ.bf.PTRADJUSTTXINAZ ? 0x20 : 0x2A, dft_gfec10g->INTTZ.bf.PTRADJUSTTXINAZ, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_ERRINS1.wrd", tmp_gfec10g->ERRINS1.wrd, tmp_gfec10g->ERRINS1.wrd == dft_gfec10g->ERRINS1.wrd ? 0x20 : 0x2A, dft_gfec10g->ERRINS1.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_ERRINS1.bf.errValue", tmp_gfec10g->ERRINS1.bf.errValue, tmp_gfec10g->ERRINS1.bf.errValue == dft_gfec10g->ERRINS1.bf.errValue ? 0x20 : 0x2A, dft_gfec10g->ERRINS1.bf.errValue, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_ERRINS1.bf.rowOffset", tmp_gfec10g->ERRINS1.bf.rowOffset, tmp_gfec10g->ERRINS1.bf.rowOffset == dft_gfec10g->ERRINS1.bf.rowOffset ? 0x20 : 0x2A, dft_gfec10g->ERRINS1.bf.rowOffset, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_ERRINS1.bf.insErrorOnce", tmp_gfec10g->ERRINS1.bf.insErrorOnce, tmp_gfec10g->ERRINS1.bf.insErrorOnce == dft_gfec10g->ERRINS1.bf.insErrorOnce ? 0x20 : 0x2A, dft_gfec10g->ERRINS1.bf.insErrorOnce, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_ERRINS1.bf.insError", tmp_gfec10g->ERRINS1.bf.insError, tmp_gfec10g->ERRINS1.bf.insError == dft_gfec10g->ERRINS1.bf.insError ? 0x20 : 0x2A, dft_gfec10g->ERRINS1.bf.insError, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_ERRINS2.wrd", tmp_gfec10g->ERRINS2.wrd, tmp_gfec10g->ERRINS2.wrd == dft_gfec10g->ERRINS2.wrd ? 0x20 : 0x2A, dft_gfec10g->ERRINS2.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_ERRINS2.bf.errMask", tmp_gfec10g->ERRINS2.bf.errMask, tmp_gfec10g->ERRINS2.bf.errMask == dft_gfec10g->ERRINS2.bf.errMask ? 0x20 : 0x2A, dft_gfec10g->ERRINS2.bf.errMask, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_ERRINS3.wrd", tmp_gfec10g->ERRINS3.wrd, tmp_gfec10g->ERRINS3.wrd == dft_gfec10g->ERRINS3.wrd ? 0x20 : 0x2A, dft_gfec10g->ERRINS3.wrd, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_ERRINS3.bf.noCycles2Error", tmp_gfec10g->ERRINS3.bf.noCycles2Error, tmp_gfec10g->ERRINS3.bf.noCycles2Error == dft_gfec10g->ERRINS3.bf.noCycles2Error ? 0x20 : 0x2A, dft_gfec10g->ERRINS3.bf.noCycles2Error, (module_id & 1) ? 'B' : 'A', ii + '0');
      CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "GFEC10G_FTX_ERRINS3.bf.startPosition", tmp_gfec10g->ERRINS3.bf.startPosition, tmp_gfec10g->ERRINS3.bf.startPosition == dft_gfec10g->ERRINS3.bf.startPosition ? 0x20 : 0x2A, dft_gfec10g->ERRINS3.bf.startPosition, (module_id & 1) ? 'B' : 'A', ii + '0');
    }
  }
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  CS_FREE(tmp_gfec10g);
  CS_FREE(dft_gfec10g);
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  
  return (CS_OK);
}



