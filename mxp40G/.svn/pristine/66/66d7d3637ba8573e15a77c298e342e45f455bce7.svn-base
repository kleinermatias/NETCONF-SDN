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
 * ten_debug_dm.c
 *
 * APIs for debugging dm
 *
 * $Id: ten_debug_dm.c,v 1.3 2013/03/05 16:11:52 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  DM DUMP SETTINGS                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_dm_dump_settings(cs_uint16 dev_id)
/* INPUTS     : o Dev Id                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current DM settings.                                    */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS
 
  TEN_dm_t *tmp_dm, *dft_dm;
  T41_t *pDev = NULL;
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
        
  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }
     
  tmp_dm = (TEN_dm_t *)CS_MALLOC(sizeof(TEN_dm_t));
  dft_dm = (TEN_dm_t *)CS_MALLOC(sizeof(TEN_dm_t));
  
  /* Bug #38811: Debug APIs need malloc check for Klocwork warning */
  if ((tmp_dm == 0) || (dft_dm == 0)) {
    if (tmp_dm) {
      CS_FREE(tmp_dm);
    }
    if (dft_dm) {
      CS_FREE(dft_dm);
    }
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  CS_MEMSET((TEN_dm_t *)tmp_dm, 0, sizeof(TEN_dm_t));
  CS_MEMSET((TEN_dm_t *)dft_dm, 0, sizeof(TEN_dm_t));

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  
  dft_dm->DMSEL_CFG.wrd = TEN_DM_DMSEL_CFG_dft;     
  dft_dm->DM_THRESH_CFG1.wrd = TEN_DM_DM_THRESH_CFG1_dft;
  dft_dm->DM_THRESH_CFG0.wrd = TEN_DM_DM_THRESH_CFG0_dft;
  dft_dm->DM_DELAY1.wrd = TEN_DM_DM_DELAY1_dft;     
  dft_dm->DM_DELAY0.wrd = TEN_DM_DM_DELAY0_dft;     
  dft_dm->INTR.wrd = TEN_DM_INTR_dft;               
  dft_dm->INTRE.wrd = TEN_DM_INTRE_dft;             
  dft_dm->INTRZ.wrd = TEN_DM_INTRZ_dft; 
  
  tmp_dm->DMSEL_CFG.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DMSEL_CFG));
  tmp_dm->DM_THRESH_CFG1.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DM_THRESH_CFG1));
  tmp_dm->DM_THRESH_CFG0.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DM_THRESH_CFG0));
  tmp_dm->DM_DELAY1.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DM_DELAY1));
  tmp_dm->DM_DELAY0.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DM_DELAY0));
  tmp_dm->INTR.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, INTR));
  tmp_dm->INTRE.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, INTRE));
  tmp_dm->INTRZ.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, INTRZ));

  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DMSEL_CFG.wrd", tmp_dm->DMSEL_CFG.wrd, tmp_dm->DMSEL_CFG.wrd == dft_dm->DMSEL_CFG.wrd ? 0x20 : 0x2A, dft_dm->DMSEL_CFG.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DMSEL_CFG.bf.DM_CNT_STOP", tmp_dm->DMSEL_CFG.bf.DM_CNT_STOP, tmp_dm->DMSEL_CFG.bf.DM_CNT_STOP == dft_dm->DMSEL_CFG.bf.DM_CNT_STOP ? 0x20 : 0x2A, dft_dm->DMSEL_CFG.bf.DM_CNT_STOP);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DMSEL_CFG.bf.TXSRC", tmp_dm->DMSEL_CFG.bf.TXSRC, tmp_dm->DMSEL_CFG.bf.TXSRC == dft_dm->DMSEL_CFG.bf.TXSRC ? 0x20 : 0x2A, dft_dm->DMSEL_CFG.bf.TXSRC);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DMSEL_CFG.bf.RXSRC", tmp_dm->DMSEL_CFG.bf.RXSRC, tmp_dm->DMSEL_CFG.bf.RXSRC == dft_dm->DMSEL_CFG.bf.RXSRC ? 0x20 : 0x2A, dft_dm->DMSEL_CFG.bf.RXSRC);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DM_THRESH_CFG1.wrd", tmp_dm->DM_THRESH_CFG1.wrd, tmp_dm->DM_THRESH_CFG1.wrd == dft_dm->DM_THRESH_CFG1.wrd ? 0x20 : 0x2A, dft_dm->DM_THRESH_CFG1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DM_THRESH_CFG1.bf.DM_THRESH1", tmp_dm->DM_THRESH_CFG1.bf.DM_THRESH1, tmp_dm->DM_THRESH_CFG1.bf.DM_THRESH1 == dft_dm->DM_THRESH_CFG1.bf.DM_THRESH1 ? 0x20 : 0x2A, dft_dm->DM_THRESH_CFG1.bf.DM_THRESH1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DM_THRESH_CFG0.wrd", tmp_dm->DM_THRESH_CFG0.wrd, tmp_dm->DM_THRESH_CFG0.wrd == dft_dm->DM_THRESH_CFG0.wrd ? 0x20 : 0x2A, dft_dm->DM_THRESH_CFG0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DM_THRESH_CFG0.bf.DM_THRESH0", tmp_dm->DM_THRESH_CFG0.bf.DM_THRESH0, tmp_dm->DM_THRESH_CFG0.bf.DM_THRESH0 == dft_dm->DM_THRESH_CFG0.bf.DM_THRESH0 ? 0x20 : 0x2A, dft_dm->DM_THRESH_CFG0.bf.DM_THRESH0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DM_DELAY1.wrd", tmp_dm->DM_DELAY1.wrd, tmp_dm->DM_DELAY1.wrd == dft_dm->DM_DELAY1.wrd ? 0x20 : 0x2A, dft_dm->DM_DELAY1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DM_DELAY1.bf.DM_DELAY1", tmp_dm->DM_DELAY1.bf.DM_DELAY1, tmp_dm->DM_DELAY1.bf.DM_DELAY1 == dft_dm->DM_DELAY1.bf.DM_DELAY1 ? 0x20 : 0x2A, dft_dm->DM_DELAY1.bf.DM_DELAY1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DM_DELAY0.wrd", tmp_dm->DM_DELAY0.wrd, tmp_dm->DM_DELAY0.wrd == dft_dm->DM_DELAY0.wrd ? 0x20 : 0x2A, dft_dm->DM_DELAY0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_DM_DELAY0.bf.DM_DELAY0", tmp_dm->DM_DELAY0.bf.DM_DELAY0, tmp_dm->DM_DELAY0.bf.DM_DELAY0 == dft_dm->DM_DELAY0.bf.DM_DELAY0 ? 0x20 : 0x2A, dft_dm->DM_DELAY0.bf.DM_DELAY0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_INTR.wrd", tmp_dm->INTR.wrd, tmp_dm->INTR.wrd == dft_dm->INTR.wrd ? 0x20 : 0x2A, dft_dm->INTR.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_INTR.bf.DM_INT", tmp_dm->INTR.bf.DM_INT, tmp_dm->INTR.bf.DM_INT == dft_dm->INTR.bf.DM_INT ? 0x20 : 0x2A, dft_dm->INTR.bf.DM_INT);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_INTRE.wrd", tmp_dm->INTRE.wrd, tmp_dm->INTRE.wrd == dft_dm->INTRE.wrd ? 0x20 : 0x2A, dft_dm->INTRE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_INTRE.bf.DM_INTE", tmp_dm->INTRE.bf.DM_INTE, tmp_dm->INTRE.bf.DM_INTE == dft_dm->INTRE.bf.DM_INTE ? 0x20 : 0x2A, dft_dm->INTRE.bf.DM_INTE);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_INTRZ.wrd", tmp_dm->INTRZ.wrd, tmp_dm->INTRZ.wrd == dft_dm->INTRZ.wrd ? 0x20 : 0x2A, dft_dm->INTRZ.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "DM_INTRZ.bf.DM_INTZ", tmp_dm->INTRZ.bf.DM_INTZ, tmp_dm->INTRZ.bf.DM_INTZ == dft_dm->INTRZ.bf.DM_INTZ ? 0x20 : 0x2A, dft_dm->INTRZ.bf.DM_INTZ);
  
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
                                                                                                                                                   
  CS_FREE(tmp_dm);                                                                                                             
  CS_FREE(dft_dm); 
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
                                                                                                                                                      
  return (CS_OK);                                                                                                                                      
}                                                                                                                                                      
                                                                                                                                                       
