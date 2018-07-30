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
 * ten_debug_gfec40g.c
 *
 * APIs for debugging gfec40g
 *
 * $Id: ten_debug_gfec40g.c,v 1.12 2013/03/05 16:11:52 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  GFEC40G DUMP SETTINGS                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_gfec40g_dump_settings(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current GFEC40G settings.                               */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  TEN_GFEC40g_t *tmp_gfec40g, *dft_gfec40g;
  cs_char8 ch1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_gfec40g = (TEN_GFEC40g_t *)CS_MALLOC(sizeof(TEN_GFEC40g_t));
  dft_gfec40g = (TEN_GFEC40g_t *)CS_MALLOC(sizeof(TEN_GFEC40g_t));
  
  /* Bug #38811: Debug APIs need malloc check for Klocwork warning */
  if ((tmp_gfec40g == 0) || (dft_gfec40g == 0)) {
    if (tmp_gfec40g) {
      CS_FREE(tmp_gfec40g);
    }
    if (dft_gfec40g) {
      CS_FREE(dft_gfec40g);
    }
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  CS_MEMSET((TEN_GFEC40g_t *)tmp_gfec40g, 0, sizeof(TEN_GFEC40g_t));
  CS_MEMSET((TEN_GFEC40g_t *)dft_gfec40g, 0, sizeof(TEN_GFEC40g_t));

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  dft_gfec40g->RMBYTER0.wrd = TEN_GFEC40G_FRX40_RMBYTER0_dft;
  dft_gfec40g->RMBYTER1.wrd = TEN_GFEC40G_FRX40_RMBYTER1_dft;
  dft_gfec40g->RZBTER0.wrd = TEN_GFEC40G_FRX40_RZBTER0_dft;
  dft_gfec40g->RZBTER1.wrd = TEN_GFEC40G_FRX40_RZBTER1_dft;
  dft_gfec40g->ROBTER0.wrd = TEN_GFEC40G_FRX40_ROBTER0_dft;
  dft_gfec40g->ROBTER1.wrd = TEN_GFEC40G_FRX40_ROBTER1_dft;
  dft_gfec40g->RBYTER0.wrd = TEN_GFEC40G_FRX40_RBYTER0_dft;
  dft_gfec40g->RBYTER1.wrd = TEN_GFEC40G_FRX40_RBYTER1_dft;
  dft_gfec40g->RERROV0.wrd = TEN_GFEC40G_FRX40_RERROV0_dft;
  dft_gfec40g->RERROV1.wrd = TEN_GFEC40G_FRX40_RERROV1_dft;
  dft_gfec40g->INTR.wrd = TEN_GFEC40G_FRX40_INTR_dft;
  dft_gfec40g->INTRE.wrd = TEN_GFEC40G_FRX40_INTRE_dft;
  dft_gfec40g->INTRS.wrd = TEN_GFEC40G_FRX40_INTRS_dft;
  dft_gfec40g->INTRZ.wrd = TEN_GFEC40G_FRX40_INTRZ_dft;
  dft_gfec40g->RSCFG.wrd = TEN_GFEC40G_FRX40_RSCFG_dft;
  dft_gfec40g->SEED_THR_LOW.wrd = TEN_GFEC40G_FRX40_SEED_THR_LOW_dft;
  dft_gfec40g->SEED_THR_UP.wrd = TEN_GFEC40G_FRX40_SEED_THR_UP_dft;
  dft_gfec40g->CEED_THR_LOW.wrd = TEN_GFEC40G_FRX40_CEED_THR_LOW_dft;
  dft_gfec40g->CEED_THR_UP.wrd = TEN_GFEC40G_FRX40_CEED_THR_UP_dft;
  dft_gfec40g->SDEG_THR_LOW.wrd = TEN_GFEC40G_FRX40_SDEG_THR_LOW_dft;
  dft_gfec40g->SDEG_THR_UP.wrd = TEN_GFEC40G_FRX40_SDEG_THR_UP_dft;
  dft_gfec40g->CDEG_THR_LOW.wrd = TEN_GFEC40G_FRX40_CDEG_THR_LOW_dft;
  dft_gfec40g->CDEG_THR_UP.wrd = TEN_GFEC40G_FRX40_CDEG_THR_UP_dft;
  dft_gfec40g->ERSEL.wrd = TEN_GFEC40G_FRX40_ERSEL_dft;
  dft_gfec40g->TUSEL.wrd = TEN_GFEC40G_FRX40_TUSEL_dft;
  dft_gfec40g->EED_WIN.wrd = TEN_GFEC40G_FRX40_EED_WIN_dft;
  dft_gfec40g->DEG_WIN.wrd = TEN_GFEC40G_FRX40_DEG_WIN_dft;
  dft_gfec40g->EED_DTV_DIV.wrd = TEN_GFEC40G_FRX40_EED_DTV_DIV_dft;
  dft_gfec40g->EED_NTV_NIV.wrd = TEN_GFEC40G_FRX40_EED_NTV_NIV_dft;
  dft_gfec40g->DEG_DTV_DIV.wrd = TEN_GFEC40G_FRX40_DEG_DTV_DIV_dft;
  dft_gfec40g->DEG_NTV_NIV.wrd = TEN_GFEC40G_FRX40_DEG_NTV_NIV_dft;
  dft_gfec40g->TXCFG.wrd = TEN_GFEC40G_FTX40_TXCFG_dft;
  dft_gfec40g->INTT.wrd = TEN_GFEC40G_FTX40_INTT_dft;
  dft_gfec40g->INTTE.wrd = TEN_GFEC40G_FTX40_INTTE_dft;
  dft_gfec40g->INTTS.wrd = TEN_GFEC40G_FTX40_INTTS_dft;
  dft_gfec40g->INTTZ.wrd = TEN_GFEC40G_FTX40_INTTZ_dft;
  dft_gfec40g->ERRINS1.wrd = TEN_GFEC40G_FTX40_ERRINS1_dft;
  dft_gfec40g->ERRINS2.wrd = TEN_GFEC40G_FTX40_ERRINS2_dft;
  dft_gfec40g->ERRINS3.wrd = TEN_GFEC40G_FTX40_ERRINS3_dft;
  
  tmp_gfec40g->RMBYTER0.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RMBYTER0));
  tmp_gfec40g->RMBYTER1.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RMBYTER1));
  tmp_gfec40g->RZBTER0.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RZBTER0));
  tmp_gfec40g->RZBTER1.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RZBTER1));
  tmp_gfec40g->ROBTER0.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ROBTER0));
  tmp_gfec40g->ROBTER1.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ROBTER1));
  tmp_gfec40g->RBYTER0.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RBYTER0));
  tmp_gfec40g->RBYTER1.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RBYTER1));
  tmp_gfec40g->RERROV0.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RERROV0));
  tmp_gfec40g->RERROV1.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RERROV1));
  tmp_gfec40g->INTR.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, INTR));
  tmp_gfec40g->INTRE.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, INTRE));
  tmp_gfec40g->INTRS.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, INTRS));
  tmp_gfec40g->INTRZ.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, INTRZ));
  tmp_gfec40g->RSCFG.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RSCFG));
  tmp_gfec40g->SEED_THR_LOW.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, SEED_THR_LOW));
  tmp_gfec40g->SEED_THR_UP.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, SEED_THR_UP));
  tmp_gfec40g->CEED_THR_LOW.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, CEED_THR_LOW));
  tmp_gfec40g->CEED_THR_UP.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, CEED_THR_UP));
  tmp_gfec40g->SDEG_THR_LOW.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, SDEG_THR_LOW));
  tmp_gfec40g->SDEG_THR_UP.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, SDEG_THR_UP));
  tmp_gfec40g->CDEG_THR_LOW.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, CDEG_THR_LOW));
  tmp_gfec40g->CDEG_THR_UP.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, CDEG_THR_UP));
  tmp_gfec40g->ERSEL.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERSEL));
  tmp_gfec40g->TUSEL.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, TUSEL));
  tmp_gfec40g->EED_WIN.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, EED_WIN));
  tmp_gfec40g->DEG_WIN.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, DEG_WIN));
  tmp_gfec40g->EED_DTV_DIV.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, EED_DTV_DIV));
  tmp_gfec40g->EED_NTV_NIV.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, EED_NTV_NIV));
  tmp_gfec40g->DEG_DTV_DIV.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, DEG_DTV_DIV));
  tmp_gfec40g->DEG_NTV_NIV.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, DEG_NTV_NIV));
  tmp_gfec40g->TXCFG.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, TXCFG));
  tmp_gfec40g->INTT.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, INTT));
  tmp_gfec40g->INTTE.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, INTTE));
  tmp_gfec40g->INTTS.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, INTTS));
  tmp_gfec40g->INTTZ.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, INTTZ));
  tmp_gfec40g->ERRINS1.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS1));
  tmp_gfec40g->ERRINS2.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS2));
  tmp_gfec40g->ERRINS3.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS3));

  /* Bugzilla #26763, fix formatting */
  ch1 = (module_id & 1) ? 'B' : 'A';
  
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RMBYTER0.wrd", tmp_gfec40g->RMBYTER0.wrd, tmp_gfec40g->RMBYTER0.wrd == dft_gfec40g->RMBYTER0.wrd ? 0x20 : 0x2A, dft_gfec40g->RMBYTER0.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RMBYTER0.bf.RMBYTER0", tmp_gfec40g->RMBYTER0.bf.RMBYTER0, tmp_gfec40g->RMBYTER0.bf.RMBYTER0 == dft_gfec40g->RMBYTER0.bf.RMBYTER0 ? 0x20 : 0x2A, dft_gfec40g->RMBYTER0.bf.RMBYTER0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RMBYTER1.wrd", tmp_gfec40g->RMBYTER1.wrd, tmp_gfec40g->RMBYTER1.wrd == dft_gfec40g->RMBYTER1.wrd ? 0x20 : 0x2A, dft_gfec40g->RMBYTER1.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RMBYTER1.bf.RMBYTER1", tmp_gfec40g->RMBYTER1.bf.RMBYTER1, tmp_gfec40g->RMBYTER1.bf.RMBYTER1 == dft_gfec40g->RMBYTER1.bf.RMBYTER1 ? 0x20 : 0x2A, dft_gfec40g->RMBYTER1.bf.RMBYTER1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RZBTER0.wrd", tmp_gfec40g->RZBTER0.wrd, tmp_gfec40g->RZBTER0.wrd == dft_gfec40g->RZBTER0.wrd ? 0x20 : 0x2A, dft_gfec40g->RZBTER0.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RZBTER0.bf.RZBTER0", tmp_gfec40g->RZBTER0.bf.RZBTER0, tmp_gfec40g->RZBTER0.bf.RZBTER0 == dft_gfec40g->RZBTER0.bf.RZBTER0 ? 0x20 : 0x2A, dft_gfec40g->RZBTER0.bf.RZBTER0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RZBTER1.wrd", tmp_gfec40g->RZBTER1.wrd, tmp_gfec40g->RZBTER1.wrd == dft_gfec40g->RZBTER1.wrd ? 0x20 : 0x2A, dft_gfec40g->RZBTER1.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RZBTER1.bf.RZBTER1", tmp_gfec40g->RZBTER1.bf.RZBTER1, tmp_gfec40g->RZBTER1.bf.RZBTER1 == dft_gfec40g->RZBTER1.bf.RZBTER1 ? 0x20 : 0x2A, dft_gfec40g->RZBTER1.bf.RZBTER1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_ROBTER0.wrd", tmp_gfec40g->ROBTER0.wrd, tmp_gfec40g->ROBTER0.wrd == dft_gfec40g->ROBTER0.wrd ? 0x20 : 0x2A, dft_gfec40g->ROBTER0.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_ROBTER0.bf.ROBTER0", tmp_gfec40g->ROBTER0.bf.ROBTER0, tmp_gfec40g->ROBTER0.bf.ROBTER0 == dft_gfec40g->ROBTER0.bf.ROBTER0 ? 0x20 : 0x2A, dft_gfec40g->ROBTER0.bf.ROBTER0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_ROBTER1.wrd", tmp_gfec40g->ROBTER1.wrd, tmp_gfec40g->ROBTER1.wrd == dft_gfec40g->ROBTER1.wrd ? 0x20 : 0x2A, dft_gfec40g->ROBTER1.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_ROBTER1.bf.ROBTER1", tmp_gfec40g->ROBTER1.bf.ROBTER1, tmp_gfec40g->ROBTER1.bf.ROBTER1 == dft_gfec40g->ROBTER1.bf.ROBTER1 ? 0x20 : 0x2A, dft_gfec40g->ROBTER1.bf.ROBTER1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RBYTER0.wrd", tmp_gfec40g->RBYTER0.wrd, tmp_gfec40g->RBYTER0.wrd == dft_gfec40g->RBYTER0.wrd ? 0x20 : 0x2A, dft_gfec40g->RBYTER0.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RBYTER0.bf.RBYTER0", tmp_gfec40g->RBYTER0.bf.RBYTER0, tmp_gfec40g->RBYTER0.bf.RBYTER0 == dft_gfec40g->RBYTER0.bf.RBYTER0 ? 0x20 : 0x2A, dft_gfec40g->RBYTER0.bf.RBYTER0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RBYTER1.wrd", tmp_gfec40g->RBYTER1.wrd, tmp_gfec40g->RBYTER1.wrd == dft_gfec40g->RBYTER1.wrd ? 0x20 : 0x2A, dft_gfec40g->RBYTER1.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RBYTER1.bf.RBYTER1", tmp_gfec40g->RBYTER1.bf.RBYTER1, tmp_gfec40g->RBYTER1.bf.RBYTER1 == dft_gfec40g->RBYTER1.bf.RBYTER1 ? 0x20 : 0x2A, dft_gfec40g->RBYTER1.bf.RBYTER1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RERROV0.wrd", tmp_gfec40g->RERROV0.wrd, tmp_gfec40g->RERROV0.wrd == dft_gfec40g->RERROV0.wrd ? 0x20 : 0x2A, dft_gfec40g->RERROV0.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RERROV0.bf.RERROV0", tmp_gfec40g->RERROV0.bf.RERROV0, tmp_gfec40g->RERROV0.bf.RERROV0 == dft_gfec40g->RERROV0.bf.RERROV0 ? 0x20 : 0x2A, dft_gfec40g->RERROV0.bf.RERROV0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RERROV1.wrd", tmp_gfec40g->RERROV1.wrd, tmp_gfec40g->RERROV1.wrd == dft_gfec40g->RERROV1.wrd ? 0x20 : 0x2A, dft_gfec40g->RERROV1.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RERROV1.bf.RERROV1", tmp_gfec40g->RERROV1.bf.RERROV1, tmp_gfec40g->RERROV1.bf.RERROV1 == dft_gfec40g->RERROV1.bf.RERROV1 ? 0x20 : 0x2A, dft_gfec40g->RERROV1.bf.RERROV1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.wrd", tmp_gfec40g->INTR.wrd, tmp_gfec40g->INTR.wrd == dft_gfec40g->INTR.wrd ? 0x20 : 0x2A, dft_gfec40g->INTR.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.bf.DBLERR", tmp_gfec40g->INTR.bf.DBLERR, tmp_gfec40g->INTR.bf.DBLERR == dft_gfec40g->INTR.bf.DBLERR ? 0x20 : 0x2A, dft_gfec40g->INTR.bf.DBLERR, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.bf.SGLERR", tmp_gfec40g->INTR.bf.SGLERR, tmp_gfec40g->INTR.bf.SGLERR == dft_gfec40g->INTR.bf.SGLERR ? 0x20 : 0x2A, dft_gfec40g->INTR.bf.SGLERR, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.bf.PTRADJUSTRX40OUT", tmp_gfec40g->INTR.bf.PTRADJUSTRX40OUT, tmp_gfec40g->INTR.bf.PTRADJUSTRX40OUT == dft_gfec40g->INTR.bf.PTRADJUSTRX40OUT ? 0x20 : 0x2A, dft_gfec40g->INTR.bf.PTRADJUSTRX40OUT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.bf.PTRADJUSTRX40IN", tmp_gfec40g->INTR.bf.PTRADJUSTRX40IN, tmp_gfec40g->INTR.bf.PTRADJUSTRX40IN == dft_gfec40g->INTR.bf.PTRADJUSTRX40IN ? 0x20 : 0x2A, dft_gfec40g->INTR.bf.PTRADJUSTRX40IN, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.bf.PTRADJUSTRXOUT", tmp_gfec40g->INTR.bf.PTRADJUSTRXOUT, tmp_gfec40g->INTR.bf.PTRADJUSTRXOUT == dft_gfec40g->INTR.bf.PTRADJUSTRXOUT ? 0x20 : 0x2A, dft_gfec40g->INTR.bf.PTRADJUSTRXOUT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.bf.PTRADJUSTRXIN", tmp_gfec40g->INTR.bf.PTRADJUSTRXIN, tmp_gfec40g->INTR.bf.PTRADJUSTRXIN == dft_gfec40g->INTR.bf.PTRADJUSTRXIN ? 0x20 : 0x2A, dft_gfec40g->INTR.bf.PTRADJUSTRXIN, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.bf.DEGINT", tmp_gfec40g->INTR.bf.DEGINT, tmp_gfec40g->INTR.bf.DEGINT == dft_gfec40g->INTR.bf.DEGINT ? 0x20 : 0x2A, dft_gfec40g->INTR.bf.DEGINT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.bf.EEDINT", tmp_gfec40g->INTR.bf.EEDINT, tmp_gfec40g->INTR.bf.EEDINT == dft_gfec40g->INTR.bf.EEDINT ? 0x20 : 0x2A, dft_gfec40g->INTR.bf.EEDINT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.bf.IEOV", tmp_gfec40g->INTR.bf.IEOV, tmp_gfec40g->INTR.bf.IEOV == dft_gfec40g->INTR.bf.IEOV ? 0x20 : 0x2A, dft_gfec40g->INTR.bf.IEOV, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTR.bf.IEXE", tmp_gfec40g->INTR.bf.IEXE, tmp_gfec40g->INTR.bf.IEXE == dft_gfec40g->INTR.bf.IEXE ? 0x20 : 0x2A, dft_gfec40g->INTR.bf.IEXE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.wrd", tmp_gfec40g->INTRE.wrd, tmp_gfec40g->INTRE.wrd == dft_gfec40g->INTRE.wrd ? 0x20 : 0x2A, dft_gfec40g->INTRE.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.bf.DBLERRE", tmp_gfec40g->INTRE.bf.DBLERRE, tmp_gfec40g->INTRE.bf.DBLERRE == dft_gfec40g->INTRE.bf.DBLERRE ? 0x20 : 0x2A, dft_gfec40g->INTRE.bf.DBLERRE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.bf.SGLERRE", tmp_gfec40g->INTRE.bf.SGLERRE, tmp_gfec40g->INTRE.bf.SGLERRE == dft_gfec40g->INTRE.bf.SGLERRE ? 0x20 : 0x2A, dft_gfec40g->INTRE.bf.SGLERRE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.bf.PTRADJUSTRX40OUTE", tmp_gfec40g->INTRE.bf.PTRADJUSTRX40OUTE, tmp_gfec40g->INTRE.bf.PTRADJUSTRX40OUTE == dft_gfec40g->INTRE.bf.PTRADJUSTRX40OUTE ? 0x20 : 0x2A, dft_gfec40g->INTRE.bf.PTRADJUSTRX40OUTE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.bf.PTRADJUSTRX40INE", tmp_gfec40g->INTRE.bf.PTRADJUSTRX40INE, tmp_gfec40g->INTRE.bf.PTRADJUSTRX40INE == dft_gfec40g->INTRE.bf.PTRADJUSTRX40INE ? 0x20 : 0x2A, dft_gfec40g->INTRE.bf.PTRADJUSTRX40INE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.bf.PTRADJUSTRXOUTE", tmp_gfec40g->INTRE.bf.PTRADJUSTRXOUTE, tmp_gfec40g->INTRE.bf.PTRADJUSTRXOUTE == dft_gfec40g->INTRE.bf.PTRADJUSTRXOUTE ? 0x20 : 0x2A, dft_gfec40g->INTRE.bf.PTRADJUSTRXOUTE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.bf.PTRADJUSTRXINE", tmp_gfec40g->INTRE.bf.PTRADJUSTRXINE, tmp_gfec40g->INTRE.bf.PTRADJUSTRXINE == dft_gfec40g->INTRE.bf.PTRADJUSTRXINE ? 0x20 : 0x2A, dft_gfec40g->INTRE.bf.PTRADJUSTRXINE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.bf.DEGINTE", tmp_gfec40g->INTRE.bf.DEGINTE, tmp_gfec40g->INTRE.bf.DEGINTE == dft_gfec40g->INTRE.bf.DEGINTE ? 0x20 : 0x2A, dft_gfec40g->INTRE.bf.DEGINTE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.bf.EEDINTE", tmp_gfec40g->INTRE.bf.EEDINTE, tmp_gfec40g->INTRE.bf.EEDINTE == dft_gfec40g->INTRE.bf.EEDINTE ? 0x20 : 0x2A, dft_gfec40g->INTRE.bf.EEDINTE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.bf.IEOVE", tmp_gfec40g->INTRE.bf.IEOVE, tmp_gfec40g->INTRE.bf.IEOVE == dft_gfec40g->INTRE.bf.IEOVE ? 0x20 : 0x2A, dft_gfec40g->INTRE.bf.IEOVE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRE.bf.IEXEE", tmp_gfec40g->INTRE.bf.IEXEE, tmp_gfec40g->INTRE.bf.IEXEE == dft_gfec40g->INTRE.bf.IEXEE ? 0x20 : 0x2A, dft_gfec40g->INTRE.bf.IEXEE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.wrd", tmp_gfec40g->INTRS.wrd, tmp_gfec40g->INTRS.wrd == dft_gfec40g->INTRS.wrd ? 0x20 : 0x2A, dft_gfec40g->INTRS.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.bf.DBLERRS", tmp_gfec40g->INTRS.bf.DBLERRS, tmp_gfec40g->INTRS.bf.DBLERRS == dft_gfec40g->INTRS.bf.DBLERRS ? 0x20 : 0x2A, dft_gfec40g->INTRS.bf.DBLERRS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.bf.SGLERRS", tmp_gfec40g->INTRS.bf.SGLERRS, tmp_gfec40g->INTRS.bf.SGLERRS == dft_gfec40g->INTRS.bf.SGLERRS ? 0x20 : 0x2A, dft_gfec40g->INTRS.bf.SGLERRS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.bf.PTRADJUSTRX40OUTS", tmp_gfec40g->INTRS.bf.PTRADJUSTRX40OUTS, tmp_gfec40g->INTRS.bf.PTRADJUSTRX40OUTS == dft_gfec40g->INTRS.bf.PTRADJUSTRX40OUTS ? 0x20 : 0x2A, dft_gfec40g->INTRS.bf.PTRADJUSTRX40OUTS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.bf.PTRADJUSTRX40INS", tmp_gfec40g->INTRS.bf.PTRADJUSTRX40INS, tmp_gfec40g->INTRS.bf.PTRADJUSTRX40INS == dft_gfec40g->INTRS.bf.PTRADJUSTRX40INS ? 0x20 : 0x2A, dft_gfec40g->INTRS.bf.PTRADJUSTRX40INS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.bf.PTRADJUSTRXOUTS", tmp_gfec40g->INTRS.bf.PTRADJUSTRXOUTS, tmp_gfec40g->INTRS.bf.PTRADJUSTRXOUTS == dft_gfec40g->INTRS.bf.PTRADJUSTRXOUTS ? 0x20 : 0x2A, dft_gfec40g->INTRS.bf.PTRADJUSTRXOUTS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.bf.PTRADJUSTRXINS", tmp_gfec40g->INTRS.bf.PTRADJUSTRXINS, tmp_gfec40g->INTRS.bf.PTRADJUSTRXINS == dft_gfec40g->INTRS.bf.PTRADJUSTRXINS ? 0x20 : 0x2A, dft_gfec40g->INTRS.bf.PTRADJUSTRXINS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.bf.DEGINTS", tmp_gfec40g->INTRS.bf.DEGINTS, tmp_gfec40g->INTRS.bf.DEGINTS == dft_gfec40g->INTRS.bf.DEGINTS ? 0x20 : 0x2A, dft_gfec40g->INTRS.bf.DEGINTS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.bf.EEDINTS", tmp_gfec40g->INTRS.bf.EEDINTS, tmp_gfec40g->INTRS.bf.EEDINTS == dft_gfec40g->INTRS.bf.EEDINTS ? 0x20 : 0x2A, dft_gfec40g->INTRS.bf.EEDINTS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.bf.IEOVS", tmp_gfec40g->INTRS.bf.IEOVS, tmp_gfec40g->INTRS.bf.IEOVS == dft_gfec40g->INTRS.bf.IEOVS ? 0x20 : 0x2A, dft_gfec40g->INTRS.bf.IEOVS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRS.bf.IEXES", tmp_gfec40g->INTRS.bf.IEXES, tmp_gfec40g->INTRS.bf.IEXES == dft_gfec40g->INTRS.bf.IEXES ? 0x20 : 0x2A, dft_gfec40g->INTRS.bf.IEXES, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.wrd", tmp_gfec40g->INTRZ.wrd, tmp_gfec40g->INTRZ.wrd == dft_gfec40g->INTRZ.wrd ? 0x20 : 0x2A, dft_gfec40g->INTRZ.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.bf.DBLERRZ", tmp_gfec40g->INTRZ.bf.DBLERRZ, tmp_gfec40g->INTRZ.bf.DBLERRZ == dft_gfec40g->INTRZ.bf.DBLERRZ ? 0x20 : 0x2A, dft_gfec40g->INTRZ.bf.DBLERRZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.bf.SGLERRZ", tmp_gfec40g->INTRZ.bf.SGLERRZ, tmp_gfec40g->INTRZ.bf.SGLERRZ == dft_gfec40g->INTRZ.bf.SGLERRZ ? 0x20 : 0x2A, dft_gfec40g->INTRZ.bf.SGLERRZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.bf.PTRADJUSTRX40OUTZ", tmp_gfec40g->INTRZ.bf.PTRADJUSTRX40OUTZ, tmp_gfec40g->INTRZ.bf.PTRADJUSTRX40OUTZ == dft_gfec40g->INTRZ.bf.PTRADJUSTRX40OUTZ ? 0x20 : 0x2A, dft_gfec40g->INTRZ.bf.PTRADJUSTRX40OUTZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.bf.PTRADJUSTRX40INZ", tmp_gfec40g->INTRZ.bf.PTRADJUSTRX40INZ, tmp_gfec40g->INTRZ.bf.PTRADJUSTRX40INZ == dft_gfec40g->INTRZ.bf.PTRADJUSTRX40INZ ? 0x20 : 0x2A, dft_gfec40g->INTRZ.bf.PTRADJUSTRX40INZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.bf.PTRADJUSTRXOUTZ", tmp_gfec40g->INTRZ.bf.PTRADJUSTRXOUTZ, tmp_gfec40g->INTRZ.bf.PTRADJUSTRXOUTZ == dft_gfec40g->INTRZ.bf.PTRADJUSTRXOUTZ ? 0x20 : 0x2A, dft_gfec40g->INTRZ.bf.PTRADJUSTRXOUTZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.bf.PTRADJUSTRXINZ", tmp_gfec40g->INTRZ.bf.PTRADJUSTRXINZ, tmp_gfec40g->INTRZ.bf.PTRADJUSTRXINZ == dft_gfec40g->INTRZ.bf.PTRADJUSTRXINZ ? 0x20 : 0x2A, dft_gfec40g->INTRZ.bf.PTRADJUSTRXINZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.bf.DEGINTZ", tmp_gfec40g->INTRZ.bf.DEGINTZ, tmp_gfec40g->INTRZ.bf.DEGINTZ == dft_gfec40g->INTRZ.bf.DEGINTZ ? 0x20 : 0x2A, dft_gfec40g->INTRZ.bf.DEGINTZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.bf.EEDINTZ", tmp_gfec40g->INTRZ.bf.EEDINTZ, tmp_gfec40g->INTRZ.bf.EEDINTZ == dft_gfec40g->INTRZ.bf.EEDINTZ ? 0x20 : 0x2A, dft_gfec40g->INTRZ.bf.EEDINTZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.bf.IEOVZ", tmp_gfec40g->INTRZ.bf.IEOVZ, tmp_gfec40g->INTRZ.bf.IEOVZ == dft_gfec40g->INTRZ.bf.IEOVZ ? 0x20 : 0x2A, dft_gfec40g->INTRZ.bf.IEOVZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_INTRZ.bf.IEXEZ", tmp_gfec40g->INTRZ.bf.IEXEZ, tmp_gfec40g->INTRZ.bf.IEXEZ == dft_gfec40g->INTRZ.bf.IEXEZ ? 0x20 : 0x2A, dft_gfec40g->INTRZ.bf.IEXEZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.wrd", tmp_gfec40g->RSCFG.wrd, tmp_gfec40g->RSCFG.wrd == dft_gfec40g->RSCFG.wrd ? 0x20 : 0x2A, dft_gfec40g->RSCFG.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.bf.RXRST", tmp_gfec40g->RSCFG.bf.RXRST, tmp_gfec40g->RSCFG.bf.RXRST == dft_gfec40g->RSCFG.bf.RXRST ? 0x20 : 0x2A, dft_gfec40g->RSCFG.bf.RXRST, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.bf.CORE", tmp_gfec40g->RSCFG.bf.CORE, tmp_gfec40g->RSCFG.bf.CORE == dft_gfec40g->RSCFG.bf.CORE ? 0x20 : 0x2A, dft_gfec40g->RSCFG.bf.CORE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.bf.DECE", tmp_gfec40g->RSCFG.bf.DECE, tmp_gfec40g->RSCFG.bf.DECE == dft_gfec40g->RSCFG.bf.DECE ? 0x20 : 0x2A, dft_gfec40g->RSCFG.bf.DECE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.bf.STATSCREn", tmp_gfec40g->RSCFG.bf.STATSCREn, tmp_gfec40g->RSCFG.bf.STATSCREn == dft_gfec40g->RSCFG.bf.STATSCREn ? 0x20 : 0x2A, dft_gfec40g->RSCFG.bf.STATSCREn, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.bf.PTRREINITRX40OUT", tmp_gfec40g->RSCFG.bf.PTRREINITRX40OUT, tmp_gfec40g->RSCFG.bf.PTRREINITRX40OUT == dft_gfec40g->RSCFG.bf.PTRREINITRX40OUT ? 0x20 : 0x2A, dft_gfec40g->RSCFG.bf.PTRREINITRX40OUT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.bf.PTRREINITRX40IN", tmp_gfec40g->RSCFG.bf.PTRREINITRX40IN, tmp_gfec40g->RSCFG.bf.PTRREINITRX40IN == dft_gfec40g->RSCFG.bf.PTRREINITRX40IN ? 0x20 : 0x2A, dft_gfec40g->RSCFG.bf.PTRREINITRX40IN, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.bf.PTRREINITRXOUT", tmp_gfec40g->RSCFG.bf.PTRREINITRXOUT, tmp_gfec40g->RSCFG.bf.PTRREINITRXOUT == dft_gfec40g->RSCFG.bf.PTRREINITRXOUT ? 0x20 : 0x2A, dft_gfec40g->RSCFG.bf.PTRREINITRXOUT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.bf.PTRREINITRXIN", tmp_gfec40g->RSCFG.bf.PTRREINITRXIN, tmp_gfec40g->RSCFG.bf.PTRREINITRXIN == dft_gfec40g->RSCFG.bf.PTRREINITRXIN ? 0x20 : 0x2A, dft_gfec40g->RSCFG.bf.PTRREINITRXIN, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.bf.EXESEL", tmp_gfec40g->RSCFG.bf.EXESEL, tmp_gfec40g->RSCFG.bf.EXESEL == dft_gfec40g->RSCFG.bf.EXESEL ? 0x20 : 0x2A, dft_gfec40g->RSCFG.bf.EXESEL, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_RSCFG.bf.GISEL", tmp_gfec40g->RSCFG.bf.GISEL, tmp_gfec40g->RSCFG.bf.GISEL == dft_gfec40g->RSCFG.bf.GISEL ? 0x20 : 0x2A, dft_gfec40g->RSCFG.bf.GISEL, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_SEED_THR_LOW.wrd", tmp_gfec40g->SEED_THR_LOW.wrd, tmp_gfec40g->SEED_THR_LOW.wrd == dft_gfec40g->SEED_THR_LOW.wrd ? 0x20 : 0x2A, dft_gfec40g->SEED_THR_LOW.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_SEED_THR_LOW.bf.seed_thr_low", tmp_gfec40g->SEED_THR_LOW.bf.seed_thr_low, tmp_gfec40g->SEED_THR_LOW.bf.seed_thr_low == dft_gfec40g->SEED_THR_LOW.bf.seed_thr_low ? 0x20 : 0x2A, dft_gfec40g->SEED_THR_LOW.bf.seed_thr_low, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_SEED_THR_UP.wrd", tmp_gfec40g->SEED_THR_UP.wrd, tmp_gfec40g->SEED_THR_UP.wrd == dft_gfec40g->SEED_THR_UP.wrd ? 0x20 : 0x2A, dft_gfec40g->SEED_THR_UP.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_SEED_THR_UP.bf.seed_thr_up", tmp_gfec40g->SEED_THR_UP.bf.seed_thr_up, tmp_gfec40g->SEED_THR_UP.bf.seed_thr_up == dft_gfec40g->SEED_THR_UP.bf.seed_thr_up ? 0x20 : 0x2A, dft_gfec40g->SEED_THR_UP.bf.seed_thr_up, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_CEED_THR_LOW.wrd", tmp_gfec40g->CEED_THR_LOW.wrd, tmp_gfec40g->CEED_THR_LOW.wrd == dft_gfec40g->CEED_THR_LOW.wrd ? 0x20 : 0x2A, dft_gfec40g->CEED_THR_LOW.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_CEED_THR_LOW.bf.ceed_thr_low", tmp_gfec40g->CEED_THR_LOW.bf.ceed_thr_low, tmp_gfec40g->CEED_THR_LOW.bf.ceed_thr_low == dft_gfec40g->CEED_THR_LOW.bf.ceed_thr_low ? 0x20 : 0x2A, dft_gfec40g->CEED_THR_LOW.bf.ceed_thr_low, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_CEED_THR_UP.wrd", tmp_gfec40g->CEED_THR_UP.wrd, tmp_gfec40g->CEED_THR_UP.wrd == dft_gfec40g->CEED_THR_UP.wrd ? 0x20 : 0x2A, dft_gfec40g->CEED_THR_UP.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_CEED_THR_UP.bf.ceed_thr_up", tmp_gfec40g->CEED_THR_UP.bf.ceed_thr_up, tmp_gfec40g->CEED_THR_UP.bf.ceed_thr_up == dft_gfec40g->CEED_THR_UP.bf.ceed_thr_up ? 0x20 : 0x2A, dft_gfec40g->CEED_THR_UP.bf.ceed_thr_up, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_SDEG_THR_LOW.wrd", tmp_gfec40g->SDEG_THR_LOW.wrd, tmp_gfec40g->SDEG_THR_LOW.wrd == dft_gfec40g->SDEG_THR_LOW.wrd ? 0x20 : 0x2A, dft_gfec40g->SDEG_THR_LOW.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_SDEG_THR_LOW.bf.sdeg_thr_low", tmp_gfec40g->SDEG_THR_LOW.bf.sdeg_thr_low, tmp_gfec40g->SDEG_THR_LOW.bf.sdeg_thr_low == dft_gfec40g->SDEG_THR_LOW.bf.sdeg_thr_low ? 0x20 : 0x2A, dft_gfec40g->SDEG_THR_LOW.bf.sdeg_thr_low, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_SDEG_THR_UP.wrd", tmp_gfec40g->SDEG_THR_UP.wrd, tmp_gfec40g->SDEG_THR_UP.wrd == dft_gfec40g->SDEG_THR_UP.wrd ? 0x20 : 0x2A, dft_gfec40g->SDEG_THR_UP.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_SDEG_THR_UP.bf.sdeg_thr_up", tmp_gfec40g->SDEG_THR_UP.bf.sdeg_thr_up, tmp_gfec40g->SDEG_THR_UP.bf.sdeg_thr_up == dft_gfec40g->SDEG_THR_UP.bf.sdeg_thr_up ? 0x20 : 0x2A, dft_gfec40g->SDEG_THR_UP.bf.sdeg_thr_up, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_CDEG_THR_LOW.wrd", tmp_gfec40g->CDEG_THR_LOW.wrd, tmp_gfec40g->CDEG_THR_LOW.wrd == dft_gfec40g->CDEG_THR_LOW.wrd ? 0x20 : 0x2A, dft_gfec40g->CDEG_THR_LOW.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_CDEG_THR_LOW.bf.cdeg_thr_low", tmp_gfec40g->CDEG_THR_LOW.bf.cdeg_thr_low, tmp_gfec40g->CDEG_THR_LOW.bf.cdeg_thr_low == dft_gfec40g->CDEG_THR_LOW.bf.cdeg_thr_low ? 0x20 : 0x2A, dft_gfec40g->CDEG_THR_LOW.bf.cdeg_thr_low, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_CDEG_THR_UP.wrd", tmp_gfec40g->CDEG_THR_UP.wrd, tmp_gfec40g->CDEG_THR_UP.wrd == dft_gfec40g->CDEG_THR_UP.wrd ? 0x20 : 0x2A, dft_gfec40g->CDEG_THR_UP.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_CDEG_THR_UP.bf.cdeg_thr_up", tmp_gfec40g->CDEG_THR_UP.bf.cdeg_thr_up, tmp_gfec40g->CDEG_THR_UP.bf.cdeg_thr_up == dft_gfec40g->CDEG_THR_UP.bf.cdeg_thr_up ? 0x20 : 0x2A, dft_gfec40g->CDEG_THR_UP.bf.cdeg_thr_up, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_ERSEL.wrd", tmp_gfec40g->ERSEL.wrd, tmp_gfec40g->ERSEL.wrd == dft_gfec40g->ERSEL.wrd ? 0x20 : 0x2A, dft_gfec40g->ERSEL.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_ERSEL.bf.cdeg_ersel", tmp_gfec40g->ERSEL.bf.cdeg_ersel, tmp_gfec40g->ERSEL.bf.cdeg_ersel == dft_gfec40g->ERSEL.bf.cdeg_ersel ? 0x20 : 0x2A, dft_gfec40g->ERSEL.bf.cdeg_ersel, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_ERSEL.bf.sdeg_ersel", tmp_gfec40g->ERSEL.bf.sdeg_ersel, tmp_gfec40g->ERSEL.bf.sdeg_ersel == dft_gfec40g->ERSEL.bf.sdeg_ersel ? 0x20 : 0x2A, dft_gfec40g->ERSEL.bf.sdeg_ersel, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_ERSEL.bf.ceed_ersel", tmp_gfec40g->ERSEL.bf.ceed_ersel, tmp_gfec40g->ERSEL.bf.ceed_ersel == dft_gfec40g->ERSEL.bf.ceed_ersel ? 0x20 : 0x2A, dft_gfec40g->ERSEL.bf.ceed_ersel, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_ERSEL.bf.seed_ersel", tmp_gfec40g->ERSEL.bf.seed_ersel, tmp_gfec40g->ERSEL.bf.seed_ersel == dft_gfec40g->ERSEL.bf.seed_ersel ? 0x20 : 0x2A, dft_gfec40g->ERSEL.bf.seed_ersel, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_TUSEL.wrd", tmp_gfec40g->TUSEL.wrd, tmp_gfec40g->TUSEL.wrd == dft_gfec40g->TUSEL.wrd ? 0x20 : 0x2A, dft_gfec40g->TUSEL.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_TUSEL.bf.deg_tusel", tmp_gfec40g->TUSEL.bf.deg_tusel, tmp_gfec40g->TUSEL.bf.deg_tusel == dft_gfec40g->TUSEL.bf.deg_tusel ? 0x20 : 0x2A, dft_gfec40g->TUSEL.bf.deg_tusel, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_TUSEL.bf.eed_tusel", tmp_gfec40g->TUSEL.bf.eed_tusel, tmp_gfec40g->TUSEL.bf.eed_tusel == dft_gfec40g->TUSEL.bf.eed_tusel ? 0x20 : 0x2A, dft_gfec40g->TUSEL.bf.eed_tusel, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_EED_WIN.wrd", tmp_gfec40g->EED_WIN.wrd, tmp_gfec40g->EED_WIN.wrd == dft_gfec40g->EED_WIN.wrd ? 0x20 : 0x2A, dft_gfec40g->EED_WIN.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_EED_WIN.bf.ceed_win", tmp_gfec40g->EED_WIN.bf.ceed_win, tmp_gfec40g->EED_WIN.bf.ceed_win == dft_gfec40g->EED_WIN.bf.ceed_win ? 0x20 : 0x2A, dft_gfec40g->EED_WIN.bf.ceed_win, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_EED_WIN.bf.seed_win", tmp_gfec40g->EED_WIN.bf.seed_win, tmp_gfec40g->EED_WIN.bf.seed_win == dft_gfec40g->EED_WIN.bf.seed_win ? 0x20 : 0x2A, dft_gfec40g->EED_WIN.bf.seed_win, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_DEG_WIN.wrd", tmp_gfec40g->DEG_WIN.wrd, tmp_gfec40g->DEG_WIN.wrd == dft_gfec40g->DEG_WIN.wrd ? 0x20 : 0x2A, dft_gfec40g->DEG_WIN.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_DEG_WIN.bf.cdeg_win", tmp_gfec40g->DEG_WIN.bf.cdeg_win, tmp_gfec40g->DEG_WIN.bf.cdeg_win == dft_gfec40g->DEG_WIN.bf.cdeg_win ? 0x20 : 0x2A, dft_gfec40g->DEG_WIN.bf.cdeg_win, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_DEG_WIN.bf.sdeg_win", tmp_gfec40g->DEG_WIN.bf.sdeg_win, tmp_gfec40g->DEG_WIN.bf.sdeg_win == dft_gfec40g->DEG_WIN.bf.sdeg_win ? 0x20 : 0x2A, dft_gfec40g->DEG_WIN.bf.sdeg_win, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_EED_DTV_DIV.wrd", tmp_gfec40g->EED_DTV_DIV.wrd, tmp_gfec40g->EED_DTV_DIV.wrd == dft_gfec40g->EED_DTV_DIV.wrd ? 0x20 : 0x2A, dft_gfec40g->EED_DTV_DIV.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_EED_DTV_DIV.bf.seed_div", tmp_gfec40g->EED_DTV_DIV.bf.seed_div, tmp_gfec40g->EED_DTV_DIV.bf.seed_div == dft_gfec40g->EED_DTV_DIV.bf.seed_div ? 0x20 : 0x2A, dft_gfec40g->EED_DTV_DIV.bf.seed_div, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_EED_DTV_DIV.bf.seed_dtv", tmp_gfec40g->EED_DTV_DIV.bf.seed_dtv, tmp_gfec40g->EED_DTV_DIV.bf.seed_dtv == dft_gfec40g->EED_DTV_DIV.bf.seed_dtv ? 0x20 : 0x2A, dft_gfec40g->EED_DTV_DIV.bf.seed_dtv, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_EED_NTV_NIV.wrd", tmp_gfec40g->EED_NTV_NIV.wrd, tmp_gfec40g->EED_NTV_NIV.wrd == dft_gfec40g->EED_NTV_NIV.wrd ? 0x20 : 0x2A, dft_gfec40g->EED_NTV_NIV.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_EED_NTV_NIV.bf.ceed_niv", tmp_gfec40g->EED_NTV_NIV.bf.ceed_niv, tmp_gfec40g->EED_NTV_NIV.bf.ceed_niv == dft_gfec40g->EED_NTV_NIV.bf.ceed_niv ? 0x20 : 0x2A, dft_gfec40g->EED_NTV_NIV.bf.ceed_niv, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_EED_NTV_NIV.bf.ceed_ntv", tmp_gfec40g->EED_NTV_NIV.bf.ceed_ntv, tmp_gfec40g->EED_NTV_NIV.bf.ceed_ntv == dft_gfec40g->EED_NTV_NIV.bf.ceed_ntv ? 0x20 : 0x2A, dft_gfec40g->EED_NTV_NIV.bf.ceed_ntv, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_DEG_DTV_DIV.wrd", tmp_gfec40g->DEG_DTV_DIV.wrd, tmp_gfec40g->DEG_DTV_DIV.wrd == dft_gfec40g->DEG_DTV_DIV.wrd ? 0x20 : 0x2A, dft_gfec40g->DEG_DTV_DIV.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_DEG_DTV_DIV.bf.sdeg_div", tmp_gfec40g->DEG_DTV_DIV.bf.sdeg_div, tmp_gfec40g->DEG_DTV_DIV.bf.sdeg_div == dft_gfec40g->DEG_DTV_DIV.bf.sdeg_div ? 0x20 : 0x2A, dft_gfec40g->DEG_DTV_DIV.bf.sdeg_div, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_DEG_DTV_DIV.bf.sdeg_dtv", tmp_gfec40g->DEG_DTV_DIV.bf.sdeg_dtv, tmp_gfec40g->DEG_DTV_DIV.bf.sdeg_dtv == dft_gfec40g->DEG_DTV_DIV.bf.sdeg_dtv ? 0x20 : 0x2A, dft_gfec40g->DEG_DTV_DIV.bf.sdeg_dtv, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_DEG_NTV_NIV.wrd", tmp_gfec40g->DEG_NTV_NIV.wrd, tmp_gfec40g->DEG_NTV_NIV.wrd == dft_gfec40g->DEG_NTV_NIV.wrd ? 0x20 : 0x2A, dft_gfec40g->DEG_NTV_NIV.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_DEG_NTV_NIV.bf.cdeg_niv", tmp_gfec40g->DEG_NTV_NIV.bf.cdeg_niv, tmp_gfec40g->DEG_NTV_NIV.bf.cdeg_niv == dft_gfec40g->DEG_NTV_NIV.bf.cdeg_niv ? 0x20 : 0x2A, dft_gfec40g->DEG_NTV_NIV.bf.cdeg_niv, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FRX40_DEG_NTV_NIV.bf.cdeg_ntv", tmp_gfec40g->DEG_NTV_NIV.bf.cdeg_ntv, tmp_gfec40g->DEG_NTV_NIV.bf.cdeg_ntv == dft_gfec40g->DEG_NTV_NIV.bf.cdeg_ntv ? 0x20 : 0x2A, dft_gfec40g->DEG_NTV_NIV.bf.cdeg_ntv, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_TXCFG.wrd", tmp_gfec40g->TXCFG.wrd, tmp_gfec40g->TXCFG.wrd == dft_gfec40g->TXCFG.wrd ? 0x20 : 0x2A, dft_gfec40g->TXCFG.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_TXCFG.bf.TXRST", tmp_gfec40g->TXCFG.bf.TXRST, tmp_gfec40g->TXCFG.bf.TXRST == dft_gfec40g->TXCFG.bf.TXRST ? 0x20 : 0x2A, dft_gfec40g->TXCFG.bf.TXRST, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_TXCFG.bf.PTRREINITTX40OUT", tmp_gfec40g->TXCFG.bf.PTRREINITTX40OUT, tmp_gfec40g->TXCFG.bf.PTRREINITTX40OUT == dft_gfec40g->TXCFG.bf.PTRREINITTX40OUT ? 0x20 : 0x2A, dft_gfec40g->TXCFG.bf.PTRREINITTX40OUT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_TXCFG.bf.PTRREINITTX40IN", tmp_gfec40g->TXCFG.bf.PTRREINITTX40IN, tmp_gfec40g->TXCFG.bf.PTRREINITTX40IN == dft_gfec40g->TXCFG.bf.PTRREINITTX40IN ? 0x20 : 0x2A, dft_gfec40g->TXCFG.bf.PTRREINITTX40IN, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_TXCFG.bf.PTRREINITTXOUT", tmp_gfec40g->TXCFG.bf.PTRREINITTXOUT, tmp_gfec40g->TXCFG.bf.PTRREINITTXOUT == dft_gfec40g->TXCFG.bf.PTRREINITTXOUT ? 0x20 : 0x2A, dft_gfec40g->TXCFG.bf.PTRREINITTXOUT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_TXCFG.bf.PTRREINITTXIN", tmp_gfec40g->TXCFG.bf.PTRREINITTXIN, tmp_gfec40g->TXCFG.bf.PTRREINITTXIN == dft_gfec40g->TXCFG.bf.PTRREINITTXIN ? 0x20 : 0x2A, dft_gfec40g->TXCFG.bf.PTRREINITTXIN, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_TXCFG.bf.disTxpar", tmp_gfec40g->TXCFG.bf.disTxpar, tmp_gfec40g->TXCFG.bf.disTxpar == dft_gfec40g->TXCFG.bf.disTxpar ? 0x20 : 0x2A, dft_gfec40g->TXCFG.bf.disTxpar, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTT.wrd", tmp_gfec40g->INTT.wrd, tmp_gfec40g->INTT.wrd == dft_gfec40g->INTT.wrd ? 0x20 : 0x2A, dft_gfec40g->INTT.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTT.bf.PTRADJUSTTX40OUT", tmp_gfec40g->INTT.bf.PTRADJUSTTX40OUT, tmp_gfec40g->INTT.bf.PTRADJUSTTX40OUT == dft_gfec40g->INTT.bf.PTRADJUSTTX40OUT ? 0x20 : 0x2A, dft_gfec40g->INTT.bf.PTRADJUSTTX40OUT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTT.bf.PTRADJUSTTX40IN", tmp_gfec40g->INTT.bf.PTRADJUSTTX40IN, tmp_gfec40g->INTT.bf.PTRADJUSTTX40IN == dft_gfec40g->INTT.bf.PTRADJUSTTX40IN ? 0x20 : 0x2A, dft_gfec40g->INTT.bf.PTRADJUSTTX40IN, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTT.bf.PTRADJUSTTXOUT", tmp_gfec40g->INTT.bf.PTRADJUSTTXOUT, tmp_gfec40g->INTT.bf.PTRADJUSTTXOUT == dft_gfec40g->INTT.bf.PTRADJUSTTXOUT ? 0x20 : 0x2A, dft_gfec40g->INTT.bf.PTRADJUSTTXOUT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTT.bf.PTRADJUSTTXIN", tmp_gfec40g->INTT.bf.PTRADJUSTTXIN, tmp_gfec40g->INTT.bf.PTRADJUSTTXIN == dft_gfec40g->INTT.bf.PTRADJUSTTXIN ? 0x20 : 0x2A, dft_gfec40g->INTT.bf.PTRADJUSTTXIN, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTE.wrd", tmp_gfec40g->INTTE.wrd, tmp_gfec40g->INTTE.wrd == dft_gfec40g->INTTE.wrd ? 0x20 : 0x2A, dft_gfec40g->INTTE.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTE.bf.PTRADJUSTTX40OUTE", tmp_gfec40g->INTTE.bf.PTRADJUSTTX40OUTE, tmp_gfec40g->INTTE.bf.PTRADJUSTTX40OUTE == dft_gfec40g->INTTE.bf.PTRADJUSTTX40OUTE ? 0x20 : 0x2A, dft_gfec40g->INTTE.bf.PTRADJUSTTX40OUTE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTE.bf.PTRADJUSTTX40INE", tmp_gfec40g->INTTE.bf.PTRADJUSTTX40INE, tmp_gfec40g->INTTE.bf.PTRADJUSTTX40INE == dft_gfec40g->INTTE.bf.PTRADJUSTTX40INE ? 0x20 : 0x2A, dft_gfec40g->INTTE.bf.PTRADJUSTTX40INE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTE.bf.PTRADJUSTTXOUTE", tmp_gfec40g->INTTE.bf.PTRADJUSTTXOUTE, tmp_gfec40g->INTTE.bf.PTRADJUSTTXOUTE == dft_gfec40g->INTTE.bf.PTRADJUSTTXOUTE ? 0x20 : 0x2A, dft_gfec40g->INTTE.bf.PTRADJUSTTXOUTE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTE.bf.PTRADJUSTTXINE", tmp_gfec40g->INTTE.bf.PTRADJUSTTXINE, tmp_gfec40g->INTTE.bf.PTRADJUSTTXINE == dft_gfec40g->INTTE.bf.PTRADJUSTTXINE ? 0x20 : 0x2A, dft_gfec40g->INTTE.bf.PTRADJUSTTXINE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTS.wrd", tmp_gfec40g->INTTS.wrd, tmp_gfec40g->INTTS.wrd == dft_gfec40g->INTTS.wrd ? 0x20 : 0x2A, dft_gfec40g->INTTS.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTS.bf.PTRADJUSTTX40OUTS", tmp_gfec40g->INTTS.bf.PTRADJUSTTX40OUTS, tmp_gfec40g->INTTS.bf.PTRADJUSTTX40OUTS == dft_gfec40g->INTTS.bf.PTRADJUSTTX40OUTS ? 0x20 : 0x2A, dft_gfec40g->INTTS.bf.PTRADJUSTTX40OUTS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTS.bf.PTRADJUSTTX40INS", tmp_gfec40g->INTTS.bf.PTRADJUSTTX40INS, tmp_gfec40g->INTTS.bf.PTRADJUSTTX40INS == dft_gfec40g->INTTS.bf.PTRADJUSTTX40INS ? 0x20 : 0x2A, dft_gfec40g->INTTS.bf.PTRADJUSTTX40INS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTS.bf.PTRADJUSTTXOUTS", tmp_gfec40g->INTTS.bf.PTRADJUSTTXOUTS, tmp_gfec40g->INTTS.bf.PTRADJUSTTXOUTS == dft_gfec40g->INTTS.bf.PTRADJUSTTXOUTS ? 0x20 : 0x2A, dft_gfec40g->INTTS.bf.PTRADJUSTTXOUTS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTS.bf.PTRADJUSTTXINS", tmp_gfec40g->INTTS.bf.PTRADJUSTTXINS, tmp_gfec40g->INTTS.bf.PTRADJUSTTXINS == dft_gfec40g->INTTS.bf.PTRADJUSTTXINS ? 0x20 : 0x2A, dft_gfec40g->INTTS.bf.PTRADJUSTTXINS, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTZ.wrd", tmp_gfec40g->INTTZ.wrd, tmp_gfec40g->INTTZ.wrd == dft_gfec40g->INTTZ.wrd ? 0x20 : 0x2A, dft_gfec40g->INTTZ.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTZ.bf.PTRADJUSTTX40OUTZ", tmp_gfec40g->INTTZ.bf.PTRADJUSTTX40OUTZ, tmp_gfec40g->INTTZ.bf.PTRADJUSTTX40OUTZ == dft_gfec40g->INTTZ.bf.PTRADJUSTTX40OUTZ ? 0x20 : 0x2A, dft_gfec40g->INTTZ.bf.PTRADJUSTTX40OUTZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTZ.bf.PTRADJUSTTX40INZ", tmp_gfec40g->INTTZ.bf.PTRADJUSTTX40INZ, tmp_gfec40g->INTTZ.bf.PTRADJUSTTX40INZ == dft_gfec40g->INTTZ.bf.PTRADJUSTTX40INZ ? 0x20 : 0x2A, dft_gfec40g->INTTZ.bf.PTRADJUSTTX40INZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTZ.bf.PTRADJUSTTXOUTZ", tmp_gfec40g->INTTZ.bf.PTRADJUSTTXOUTZ, tmp_gfec40g->INTTZ.bf.PTRADJUSTTXOUTZ == dft_gfec40g->INTTZ.bf.PTRADJUSTTXOUTZ ? 0x20 : 0x2A, dft_gfec40g->INTTZ.bf.PTRADJUSTTXOUTZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_INTTZ.bf.PTRADJUSTTXINZ", tmp_gfec40g->INTTZ.bf.PTRADJUSTTXINZ, tmp_gfec40g->INTTZ.bf.PTRADJUSTTXINZ == dft_gfec40g->INTTZ.bf.PTRADJUSTTXINZ ? 0x20 : 0x2A, dft_gfec40g->INTTZ.bf.PTRADJUSTTXINZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_ERRINS1.wrd", tmp_gfec40g->ERRINS1.wrd, tmp_gfec40g->ERRINS1.wrd == dft_gfec40g->ERRINS1.wrd ? 0x20 : 0x2A, dft_gfec40g->ERRINS1.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_ERRINS1.bf.errValue", tmp_gfec40g->ERRINS1.bf.errValue, tmp_gfec40g->ERRINS1.bf.errValue == dft_gfec40g->ERRINS1.bf.errValue ? 0x20 : 0x2A, dft_gfec40g->ERRINS1.bf.errValue, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_ERRINS1.bf.rowOffset", tmp_gfec40g->ERRINS1.bf.rowOffset, tmp_gfec40g->ERRINS1.bf.rowOffset == dft_gfec40g->ERRINS1.bf.rowOffset ? 0x20 : 0x2A, dft_gfec40g->ERRINS1.bf.rowOffset, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_ERRINS1.bf.insErrorOnce", tmp_gfec40g->ERRINS1.bf.insErrorOnce, tmp_gfec40g->ERRINS1.bf.insErrorOnce == dft_gfec40g->ERRINS1.bf.insErrorOnce ? 0x20 : 0x2A, dft_gfec40g->ERRINS1.bf.insErrorOnce, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_ERRINS1.bf.insError", tmp_gfec40g->ERRINS1.bf.insError, tmp_gfec40g->ERRINS1.bf.insError == dft_gfec40g->ERRINS1.bf.insError ? 0x20 : 0x2A, dft_gfec40g->ERRINS1.bf.insError, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_ERRINS2.wrd", tmp_gfec40g->ERRINS2.wrd, tmp_gfec40g->ERRINS2.wrd == dft_gfec40g->ERRINS2.wrd ? 0x20 : 0x2A, dft_gfec40g->ERRINS2.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_ERRINS2.bf.errMask", tmp_gfec40g->ERRINS2.bf.errMask, tmp_gfec40g->ERRINS2.bf.errMask == dft_gfec40g->ERRINS2.bf.errMask ? 0x20 : 0x2A, dft_gfec40g->ERRINS2.bf.errMask, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_ERRINS3.wrd", tmp_gfec40g->ERRINS3.wrd, tmp_gfec40g->ERRINS3.wrd == dft_gfec40g->ERRINS3.wrd ? 0x20 : 0x2A, dft_gfec40g->ERRINS3.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_ERRINS3.bf.noCycles2Error", tmp_gfec40g->ERRINS3.bf.noCycles2Error, tmp_gfec40g->ERRINS3.bf.noCycles2Error == dft_gfec40g->ERRINS3.bf.noCycles2Error ? 0x20 : 0x2A, dft_gfec40g->ERRINS3.bf.noCycles2Error, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X  %c\n", "GFEC40G_FTX40_ERRINS3.bf.startPosition", tmp_gfec40g->ERRINS3.bf.startPosition, tmp_gfec40g->ERRINS3.bf.startPosition == dft_gfec40g->ERRINS3.bf.startPosition ? 0x20 : 0x2A, dft_gfec40g->ERRINS3.bf.startPosition, ch1);

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  CS_FREE(tmp_gfec40g);
  CS_FREE(dft_gfec40g);
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  
  return (CS_OK);
}

