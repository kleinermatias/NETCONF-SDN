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
 * ten_debug_pdcal.c
 *
 * APIs for debugging pdcal
 *
 * $Id: ten_debug_pdcal.c,v 1.3 2013/03/05 16:11:52 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  PDCAL DUMP SETTINGS                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_pdcal_dump_settings(cs_uint16 dev_id)
/* INPUTS     : o Dev Id                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current PDCAL settings.                                 */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  TEN_pdcal_t *tmp_pdcal, *dft_pdcal;
  T41_t *pDev = NULL;
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
        
  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  } 
     
  tmp_pdcal = (TEN_pdcal_t *)CS_MALLOC(sizeof(TEN_pdcal_t));
  dft_pdcal = (TEN_pdcal_t *)CS_MALLOC(sizeof(TEN_pdcal_t));
  
  /* Bug #38811: Debug APIs need malloc check for Klocwork warning */
  if ((tmp_pdcal == 0) || (dft_pdcal == 0)) {
    if (tmp_pdcal) {
      CS_FREE(tmp_pdcal);
    }
    if (dft_pdcal) {
      CS_FREE(dft_pdcal);
    }
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  CS_MEMSET((TEN_pdcal_t *)tmp_pdcal, 0, sizeof(TEN_pdcal_t));
  CS_MEMSET((TEN_pdcal_t *)dft_pdcal, 0, sizeof(TEN_pdcal_t));

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  
  dft_pdcal->PDCAL_RESET.wrd = TEN_PDCAL_PDCAL_RESET_dft;
  dft_pdcal->PDCAL_CTRL.wrd = TEN_PDCAL_PDCAL_CTRL_dft;
  dft_pdcal->PDCAL_SCALE1.wrd = TEN_PDCAL_PDCAL_SCALE1_dft;
  dft_pdcal->PDCAL_SCALE0.wrd = TEN_PDCAL_PDCAL_SCALE0_dft;
  dft_pdcal->GRO_CTRL.wrd = TEN_PDCAL_GRO_CTRL_dft; 
  dft_pdcal->GRO_REFDIV.wrd = TEN_PDCAL_GRO_REFDIV_dft;
  dft_pdcal->GRO_SPARE.wrd = TEN_PDCAL_GRO_SPARE_dft;

  tmp_pdcal->PDCAL_RESET.wrd = TEN_REG_READ(TEN_PDCAL_REG_ADDR(pDev, PDCAL_RESET));
  tmp_pdcal->PDCAL_CTRL.wrd = TEN_REG_READ(TEN_PDCAL_REG_ADDR(pDev, PDCAL_CTRL));
  tmp_pdcal->PDCAL_SCALE1.wrd = TEN_REG_READ(TEN_PDCAL_REG_ADDR(pDev, PDCAL_SCALE1));
  tmp_pdcal->PDCAL_SCALE0.wrd = TEN_REG_READ(TEN_PDCAL_REG_ADDR(pDev, PDCAL_SCALE0));
  tmp_pdcal->GRO_CTRL.wrd = TEN_REG_READ(TEN_PDCAL_REG_ADDR(pDev, GRO_CTRL));
  tmp_pdcal->GRO_REFDIV.wrd = TEN_REG_READ(TEN_PDCAL_REG_ADDR(pDev, GRO_REFDIV));
  tmp_pdcal->GRO_SPARE.wrd = TEN_REG_READ(TEN_PDCAL_REG_ADDR(pDev, GRO_SPARE));

  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_RESET.wrd", tmp_pdcal->PDCAL_RESET.wrd, tmp_pdcal->PDCAL_RESET.wrd == dft_pdcal->PDCAL_RESET.wrd ? 0x20 : 0x2A, dft_pdcal->PDCAL_RESET.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_RESET.bf.preset2", tmp_pdcal->PDCAL_RESET.bf.preset2, tmp_pdcal->PDCAL_RESET.bf.preset2 == dft_pdcal->PDCAL_RESET.bf.preset2 ? 0x20 : 0x2A, dft_pdcal->PDCAL_RESET.bf.preset2);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_RESET.bf.preset1", tmp_pdcal->PDCAL_RESET.bf.preset1, tmp_pdcal->PDCAL_RESET.bf.preset1 == dft_pdcal->PDCAL_RESET.bf.preset1 ? 0x20 : 0x2A, dft_pdcal->PDCAL_RESET.bf.preset1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_RESET.bf.reset_GRO", tmp_pdcal->PDCAL_RESET.bf.reset_GRO, tmp_pdcal->PDCAL_RESET.bf.reset_GRO == dft_pdcal->PDCAL_RESET.bf.reset_GRO ? 0x20 : 0x2A, dft_pdcal->PDCAL_RESET.bf.reset_GRO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_RESET.bf.reset_pdcal", tmp_pdcal->PDCAL_RESET.bf.reset_pdcal, tmp_pdcal->PDCAL_RESET.bf.reset_pdcal == dft_pdcal->PDCAL_RESET.bf.reset_pdcal ? 0x20 : 0x2A, dft_pdcal->PDCAL_RESET.bf.reset_pdcal);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.wrd", tmp_pdcal->PDCAL_CTRL.wrd, tmp_pdcal->PDCAL_CTRL.wrd == dft_pdcal->PDCAL_CTRL.wrd ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.bf.PDcounter", tmp_pdcal->PDCAL_CTRL.bf.PDcounter, tmp_pdcal->PDCAL_CTRL.bf.PDcounter == dft_pdcal->PDCAL_CTRL.bf.PDcounter ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.bf.PDcounter);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.bf.CounterShift", tmp_pdcal->PDCAL_CTRL.bf.CounterShift, tmp_pdcal->PDCAL_CTRL.bf.CounterShift == dft_pdcal->PDCAL_CTRL.bf.CounterShift ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.bf.CounterShift);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.bf.SignInv", tmp_pdcal->PDCAL_CTRL.bf.SignInv, tmp_pdcal->PDCAL_CTRL.bf.SignInv == dft_pdcal->PDCAL_CTRL.bf.SignInv ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.bf.SignInv);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.bf.bwsel2", tmp_pdcal->PDCAL_CTRL.bf.bwsel2, tmp_pdcal->PDCAL_CTRL.bf.bwsel2 == dft_pdcal->PDCAL_CTRL.bf.bwsel2 ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.bf.bwsel2);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.bf.CounterCtrl", tmp_pdcal->PDCAL_CTRL.bf.CounterCtrl, tmp_pdcal->PDCAL_CTRL.bf.CounterCtrl == dft_pdcal->PDCAL_CTRL.bf.CounterCtrl ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.bf.CounterCtrl);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.bf.bwsel1", tmp_pdcal->PDCAL_CTRL.bf.bwsel1, tmp_pdcal->PDCAL_CTRL.bf.bwsel1 == dft_pdcal->PDCAL_CTRL.bf.bwsel1 ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.bf.bwsel1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.bf.skip2", tmp_pdcal->PDCAL_CTRL.bf.skip2, tmp_pdcal->PDCAL_CTRL.bf.skip2 == dft_pdcal->PDCAL_CTRL.bf.skip2 ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.bf.skip2);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.bf.skip1", tmp_pdcal->PDCAL_CTRL.bf.skip1, tmp_pdcal->PDCAL_CTRL.bf.skip1 == dft_pdcal->PDCAL_CTRL.bf.skip1 ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.bf.skip1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.bf.monSel", tmp_pdcal->PDCAL_CTRL.bf.monSel, tmp_pdcal->PDCAL_CTRL.bf.monSel == dft_pdcal->PDCAL_CTRL.bf.monSel ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.bf.monSel);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_CTRL.bf.PDen", tmp_pdcal->PDCAL_CTRL.bf.PDen, tmp_pdcal->PDCAL_CTRL.bf.PDen == dft_pdcal->PDCAL_CTRL.bf.PDen ? 0x20 : 0x2A, dft_pdcal->PDCAL_CTRL.bf.PDen);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_SCALE1.wrd", tmp_pdcal->PDCAL_SCALE1.wrd, tmp_pdcal->PDCAL_SCALE1.wrd == dft_pdcal->PDCAL_SCALE1.wrd ? 0x20 : 0x2A, dft_pdcal->PDCAL_SCALE1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_SCALE1.bf.PDCalScale1", tmp_pdcal->PDCAL_SCALE1.bf.PDCalScale1, tmp_pdcal->PDCAL_SCALE1.bf.PDCalScale1 == dft_pdcal->PDCAL_SCALE1.bf.PDCalScale1 ? 0x20 : 0x2A, dft_pdcal->PDCAL_SCALE1.bf.PDCalScale1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_SCALE0.wrd", tmp_pdcal->PDCAL_SCALE0.wrd, tmp_pdcal->PDCAL_SCALE0.wrd == dft_pdcal->PDCAL_SCALE0.wrd ? 0x20 : 0x2A, dft_pdcal->PDCAL_SCALE0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_PDCAL_SCALE0.bf.PDCalScale0", tmp_pdcal->PDCAL_SCALE0.bf.PDCalScale0, tmp_pdcal->PDCAL_SCALE0.bf.PDCalScale0 == dft_pdcal->PDCAL_SCALE0.bf.PDCalScale0 ? 0x20 : 0x2A, dft_pdcal->PDCAL_SCALE0.bf.PDCalScale0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_GRO_CTRL.wrd", tmp_pdcal->GRO_CTRL.wrd, tmp_pdcal->GRO_CTRL.wrd == dft_pdcal->GRO_CTRL.wrd ? 0x20 : 0x2A, dft_pdcal->GRO_CTRL.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_GRO_CTRL.bf.RefSel", tmp_pdcal->GRO_CTRL.bf.RefSel, tmp_pdcal->GRO_CTRL.bf.RefSel == dft_pdcal->GRO_CTRL.bf.RefSel ? 0x20 : 0x2A, dft_pdcal->GRO_CTRL.bf.RefSel);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_GRO_CTRL.bf.CLKINV", tmp_pdcal->GRO_CTRL.bf.CLKINV, tmp_pdcal->GRO_CTRL.bf.CLKINV == dft_pdcal->GRO_CTRL.bf.CLKINV ? 0x20 : 0x2A, dft_pdcal->GRO_CTRL.bf.CLKINV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_GRO_CTRL.bf.mode", tmp_pdcal->GRO_CTRL.bf.mode, tmp_pdcal->GRO_CTRL.bf.mode == dft_pdcal->GRO_CTRL.bf.mode ? 0x20 : 0x2A, dft_pdcal->GRO_CTRL.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_GRO_CTRL.bf.pd", tmp_pdcal->GRO_CTRL.bf.pd, tmp_pdcal->GRO_CTRL.bf.pd == dft_pdcal->GRO_CTRL.bf.pd ? 0x20 : 0x2A, dft_pdcal->GRO_CTRL.bf.pd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_GRO_REFDIV.wrd", tmp_pdcal->GRO_REFDIV.wrd, tmp_pdcal->GRO_REFDIV.wrd == dft_pdcal->GRO_REFDIV.wrd ? 0x20 : 0x2A, dft_pdcal->GRO_REFDIV.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_GRO_REFDIV.bf.RefDiv", tmp_pdcal->GRO_REFDIV.bf.RefDiv, tmp_pdcal->GRO_REFDIV.bf.RefDiv == dft_pdcal->GRO_REFDIV.bf.RefDiv ? 0x20 : 0x2A, dft_pdcal->GRO_REFDIV.bf.RefDiv);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_GRO_SPARE.wrd", tmp_pdcal->GRO_SPARE.wrd, tmp_pdcal->GRO_SPARE.wrd == dft_pdcal->GRO_SPARE.wrd ? 0x20 : 0x2A, dft_pdcal->GRO_SPARE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "PDCAL_GRO_SPARE.bf.spare", tmp_pdcal->GRO_SPARE.bf.spare, tmp_pdcal->GRO_SPARE.bf.spare == dft_pdcal->GRO_SPARE.bf.spare ? 0x20 : 0x2A, dft_pdcal->GRO_SPARE.bf.spare);

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
                                                                                                                                                   
  CS_FREE(tmp_pdcal);                                                                                                             
  CS_FREE(dft_pdcal); 
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
                                                                                                                                                      
  return (CS_OK);                                                                                                                                      
}                                                                                                                                                      
                                                                                                                                                       
