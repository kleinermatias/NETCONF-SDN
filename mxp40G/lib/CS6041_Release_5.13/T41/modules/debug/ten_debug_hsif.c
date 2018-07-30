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
 * ten_debug_hsif.c
 *
 * APIs for debugging hsif
 *
 * $Id: ten_debug_hsif.c,v 1.9 2013/03/05 16:11:52 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  HSIF DUMP SETTINGS                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_hsif_dump_settings(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current HSIF settings.                                  */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  TEN_HSIF_t *tmp_hsif_prot, *dft_hsif_prot;
  cs_char8 ch1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
                               
  tmp_hsif_prot = (TEN_HSIF_t *)CS_MALLOC(sizeof(TEN_HSIF_t));
  dft_hsif_prot = (TEN_HSIF_t *)CS_MALLOC(sizeof(TEN_HSIF_t));

  /* Bug #38811: Debug APIs need malloc check for Klocwork warning */
  if ((tmp_hsif_prot == 0) || (dft_hsif_prot == 0)) {
    if (tmp_hsif_prot) {
      CS_FREE(tmp_hsif_prot);
    }
    if (dft_hsif_prot) {
      CS_FREE(dft_hsif_prot);
    }
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  
  dft_hsif_prot->Reset.wrd = TEN_HSIF_PROTOCOL_Reset_dft;
  dft_hsif_prot->Datapath_Prov0.wrd = TEN_HSIF_PROTOCOL_Datapath_Prov0_dft;
  dft_hsif_prot->Datapath_Prov1.wrd = TEN_HSIF_PROTOCOL_Datapath_Prov1_dft;
  dft_hsif_prot->Datapath_Prov2.wrd = TEN_HSIF_PROTOCOL_Datapath_Prov2_dft;
  dft_hsif_prot->Datapath_Prov3.wrd = TEN_HSIF_PROTOCOL_Datapath_Prov3_dft;
  dft_hsif_prot->RXCLK_10G.wrd = TEN_HSIF_PROTOCOL_RXCLK_10G_dft;
  dft_hsif_prot->CLK_40G.wrd = TEN_HSIF_PROTOCOL_CLK_40G_dft;
  dft_hsif_prot->OK_CTRL.wrd = TEN_HSIF_PROTOCOL_OK_CTRL_dft;
  dft_hsif_prot->PSWTCH_OK_CTRL.wrd = TEN_HSIF_PROTOCOL_PSWTCH_OK_CTRL_dft;
  dft_hsif_prot->SFI41_CFG.wrd = TEN_HSIF_PROTOCOL_SFI41_CFG_dft;
  dft_hsif_prot->SFI41_TXBITINV.wrd = TEN_HSIF_PROTOCOL_SFI41_TXBITINV_dft;
  dft_hsif_prot->SFI41_RXBITINV.wrd = TEN_HSIF_PROTOCOL_SFI41_RXBITINV_dft;
  dft_hsif_prot->REFCLK_CFG.wrd = TEN_HSIF_PROTOCOL_REFCLK_CFG_dft;
  dft_hsif_prot->BITSHUFFLE.wrd = TEN_HSIF_PROTOCOL_BITSHUFFLE_dft;
  dft_hsif_prot->TXLANESWAP0.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP0_dft;
  dft_hsif_prot->RXLANESWAP0.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP0_dft;
  dft_hsif_prot->TXLANESWAP1.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP1_dft;
  dft_hsif_prot->RXLANESWAP1.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP1_dft;
  dft_hsif_prot->TXLANESWAP2.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP2_dft;
  dft_hsif_prot->RXLANESWAP2.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP2_dft;
  dft_hsif_prot->TXLANESWAP3.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP3_dft;
  dft_hsif_prot->RXLANESWAP3.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP3_dft;
  dft_hsif_prot->TXLANESWAP4.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP4_dft;
  dft_hsif_prot->RXLANESWAP4.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP4_dft;
  dft_hsif_prot->TXLANESWAP5.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP5_dft;
  dft_hsif_prot->RXLANESWAP5.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP5_dft;
  dft_hsif_prot->TXLANESWAP6.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP6_dft;
  dft_hsif_prot->RXLANESWAP6.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP6_dft;
  dft_hsif_prot->TXLANESWAP7.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP7_dft;
  dft_hsif_prot->RXLANESWAP7.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP7_dft;
  dft_hsif_prot->TXLANESWAP8.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP8_dft;
  dft_hsif_prot->RXLANESWAP8.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP8_dft;
  dft_hsif_prot->TXLANESWAP9.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP9_dft;
  dft_hsif_prot->RXLANESWAP9.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP9_dft;
  dft_hsif_prot->TXLANESWAP10.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP10_dft;
  dft_hsif_prot->RXLANESWAP10.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP10_dft;
  dft_hsif_prot->TXLANESWAP11.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP11_dft;
  dft_hsif_prot->RXLANESWAP11.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP11_dft;
  dft_hsif_prot->TXLANESWAP12.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP12_dft;
  dft_hsif_prot->RXLANESWAP12.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP12_dft;
  dft_hsif_prot->TXLANESWAP13.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP13_dft;
  dft_hsif_prot->RXLANESWAP13.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP13_dft;
  dft_hsif_prot->TXLANESWAP14.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP14_dft;
  dft_hsif_prot->RXLANESWAP14.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP14_dft;
  dft_hsif_prot->TXLANESWAP15.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP15_dft;
  dft_hsif_prot->RXLANESWAP15.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP15_dft;
  dft_hsif_prot->TXLANESWAP16.wrd = TEN_HSIF_PROTOCOL_TXLANESWAP16_dft;
  dft_hsif_prot->RXLANESWAP16.wrd = TEN_HSIF_PROTOCOL_RXLANESWAP16_dft;
  dft_hsif_prot->LBCFG.wrd = TEN_HSIF_PROTOCOL_LBCFG_dft;
  dft_hsif_prot->LBELSTCTRL.wrd = TEN_HSIF_PROTOCOL_LBELSTCTRL_dft;
  dft_hsif_prot->PSELSTCTRL.wrd = TEN_HSIF_PROTOCOL_PSELSTCTRL_dft;
  dft_hsif_prot->PRECODER_CFG.wrd = TEN_HSIF_PROTOCOL_PRECODER_CFG_dft;
  dft_hsif_prot->PRECODER0_CFGA.wrd = TEN_HSIF_PROTOCOL_PRECODER0_CFGA_dft;
  dft_hsif_prot->PRECODER0_CFGB.wrd = TEN_HSIF_PROTOCOL_PRECODER0_CFGB_dft;
  dft_hsif_prot->PRECODER1_CFGA.wrd = TEN_HSIF_PROTOCOL_PRECODER1_CFGA_dft;
  dft_hsif_prot->PRECODER1_CFGB.wrd = TEN_HSIF_PROTOCOL_PRECODER1_CFGB_dft;
  dft_hsif_prot->PRECODER2_CFGA.wrd = TEN_HSIF_PROTOCOL_PRECODER2_CFGA_dft;
  dft_hsif_prot->PRECODER2_CFGB.wrd = TEN_HSIF_PROTOCOL_PRECODER2_CFGB_dft;
  dft_hsif_prot->PRECODER3_CFGA.wrd = TEN_HSIF_PROTOCOL_PRECODER3_CFGA_dft;
  dft_hsif_prot->PRECODER3_CFGB.wrd = TEN_HSIF_PROTOCOL_PRECODER3_CFGB_dft;
  dft_hsif_prot->DECODER_CFG.wrd = TEN_HSIF_PROTOCOL_DECODER_CFG_dft;
  dft_hsif_prot->DECODER0_CFGA.wrd = TEN_HSIF_PROTOCOL_DECODER0_CFGA_dft;
  dft_hsif_prot->DECODER0_CFGB.wrd = TEN_HSIF_PROTOCOL_DECODER0_CFGB_dft;
  dft_hsif_prot->DECODER1_CFGA.wrd = TEN_HSIF_PROTOCOL_DECODER1_CFGA_dft;
  dft_hsif_prot->DECODER1_CFGB.wrd = TEN_HSIF_PROTOCOL_DECODER1_CFGB_dft;
  dft_hsif_prot->DECODER2_CFGA.wrd = TEN_HSIF_PROTOCOL_DECODER2_CFGA_dft;
  dft_hsif_prot->DECODER2_CFGB.wrd = TEN_HSIF_PROTOCOL_DECODER2_CFGB_dft;
  dft_hsif_prot->DECODER3_CFGA.wrd = TEN_HSIF_PROTOCOL_DECODER3_CFGA_dft;
  dft_hsif_prot->DECODER3_CFGB.wrd = TEN_HSIF_PROTOCOL_DECODER3_CFGB_dft;
  dft_hsif_prot->Interrupt.wrd = TEN_HSIF_PROTOCOL_Interrupt_dft;
  dft_hsif_prot->Intenable.wrd = TEN_HSIF_PROTOCOL_Intenable_dft;
  dft_hsif_prot->InterruptZ.wrd = TEN_HSIF_PROTOCOL_InterruptZ_dft;
  dft_hsif_prot->LBELST_INT.wrd = TEN_HSIF_PROTOCOL_LBELST_INT_dft;
  dft_hsif_prot->LBELST_INTEN.wrd = TEN_HSIF_PROTOCOL_LBELST_INTEN_dft;
  dft_hsif_prot->LBELST_INTZ.wrd = TEN_HSIF_PROTOCOL_LBELST_INTZ_dft;
  dft_hsif_prot->PSELST_INT.wrd = TEN_HSIF_PROTOCOL_PSELST_INT_dft;
  dft_hsif_prot->PSELST_INTEN.wrd = TEN_HSIF_PROTOCOL_PSELST_INTEN_dft;
  dft_hsif_prot->PSELST_INTZ.wrd = TEN_HSIF_PROTOCOL_PSELST_INTZ_dft;
  dft_hsif_prot->SliceReset.wrd = TEN_HSIF_PROTOCOL_SliceReset_dft;
  dft_hsif_prot->Intstatus.wrd = TEN_HSIF_PROTOCOL_Intstatus_dft;
  dft_hsif_prot->XFI_LANESWAP.wrd = TEN_HSIF_PROTOCOL_XFI_LANESWAP_dft;
  dft_hsif_prot->MISC.wrd = TEN_HSIF_PROTOCOL_MISC_dft;
  dft_hsif_prot->Lane0ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane0ErrCnt_dft;
  dft_hsif_prot->Lane1ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane1ErrCnt_dft;
  dft_hsif_prot->Lane2ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane2ErrCnt_dft;
  dft_hsif_prot->Lane3ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane3ErrCnt_dft;
  dft_hsif_prot->Lane4ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane4ErrCnt_dft;
  dft_hsif_prot->Lane5ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane5ErrCnt_dft;
  dft_hsif_prot->Lane6ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane6ErrCnt_dft;
  dft_hsif_prot->Lane7ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane7ErrCnt_dft;
  dft_hsif_prot->Lane8ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane8ErrCnt_dft;
  dft_hsif_prot->Lane9ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane9ErrCnt_dft;
  dft_hsif_prot->Lane10ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane10ErrCnt_dft;
  dft_hsif_prot->Lane11ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane11ErrCnt_dft;
  dft_hsif_prot->Lane12ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane12ErrCnt_dft;
  dft_hsif_prot->Lane13ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane13ErrCnt_dft;
  dft_hsif_prot->Lane14ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane14ErrCnt_dft;
  dft_hsif_prot->Lane15ErrCnt.wrd = TEN_HSIF_PROTOCOL_Lane15ErrCnt_dft;
  dft_hsif_prot->PSWITCH_MUX_INT.wrd = TEN_HSIF_PROTOCOL_PSWITCH_MUX_INT_dft;
  dft_hsif_prot->PSWITCH_MUX_INTSTATUS.wrd = TEN_HSIF_PROTOCOL_PSWITCH_MUX_INTSTATUS_dft;
  dft_hsif_prot->PSWITCH_MUX_INTEN.wrd = TEN_HSIF_PROTOCOL_PSWITCH_MUX_INTEN_dft;
  dft_hsif_prot->PSWITCH_MUX_INTZ.wrd = TEN_HSIF_PROTOCOL_PSWITCH_MUX_INTZ_dft;

  tmp_hsif_prot->Reset.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Reset));
  tmp_hsif_prot->Datapath_Prov0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0));
  tmp_hsif_prot->Datapath_Prov1.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov1));
  tmp_hsif_prot->Datapath_Prov2.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov2));
  tmp_hsif_prot->Datapath_Prov3.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov3));
  tmp_hsif_prot->RXCLK_10G.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXCLK_10G));
  tmp_hsif_prot->CLK_40G.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, CLK_40G));
  tmp_hsif_prot->OK_CTRL.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, OK_CTRL));
  tmp_hsif_prot->PSWTCH_OK_CTRL.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSWTCH_OK_CTRL));
  tmp_hsif_prot->SFI41_CFG.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, SFI41_CFG));
  tmp_hsif_prot->SFI41_TXBITINV.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, SFI41_TXBITINV));
  tmp_hsif_prot->SFI41_RXBITINV.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, SFI41_RXBITINV));
  tmp_hsif_prot->REFCLK_CFG.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG));
  tmp_hsif_prot->BITSHUFFLE.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, BITSHUFFLE));
  tmp_hsif_prot->TXLANESWAP0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP0));
  tmp_hsif_prot->RXLANESWAP0.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP0));
  tmp_hsif_prot->TXLANESWAP1.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP1));
  tmp_hsif_prot->RXLANESWAP1.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP1));
  tmp_hsif_prot->TXLANESWAP2.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP2));
  tmp_hsif_prot->RXLANESWAP2.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP2));
  tmp_hsif_prot->TXLANESWAP3.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP3));
  tmp_hsif_prot->RXLANESWAP3.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP3));
  tmp_hsif_prot->TXLANESWAP4.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP4));
  tmp_hsif_prot->RXLANESWAP4.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP4));
  tmp_hsif_prot->TXLANESWAP5.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP5));
  tmp_hsif_prot->RXLANESWAP5.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP5));
  tmp_hsif_prot->TXLANESWAP6.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP6));
  tmp_hsif_prot->RXLANESWAP6.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP6));
  tmp_hsif_prot->TXLANESWAP7.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP7));
  tmp_hsif_prot->RXLANESWAP7.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP7));
  tmp_hsif_prot->TXLANESWAP8.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP8));
  tmp_hsif_prot->RXLANESWAP8.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP8));
  tmp_hsif_prot->TXLANESWAP9.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP9));
  tmp_hsif_prot->RXLANESWAP9.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP9));
  tmp_hsif_prot->TXLANESWAP10.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP10));
  tmp_hsif_prot->RXLANESWAP10.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP10));
  tmp_hsif_prot->TXLANESWAP11.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP11));
  tmp_hsif_prot->RXLANESWAP11.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP11));
  tmp_hsif_prot->TXLANESWAP12.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP12));
  tmp_hsif_prot->RXLANESWAP12.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP12));
  tmp_hsif_prot->TXLANESWAP13.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP13));
  tmp_hsif_prot->RXLANESWAP13.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP13));
  tmp_hsif_prot->TXLANESWAP14.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP14));
  tmp_hsif_prot->RXLANESWAP14.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP14));
  tmp_hsif_prot->TXLANESWAP15.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP15));
  tmp_hsif_prot->RXLANESWAP15.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP15));
  tmp_hsif_prot->TXLANESWAP16.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, TXLANESWAP16));
  tmp_hsif_prot->RXLANESWAP16.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, RXLANESWAP16));
  tmp_hsif_prot->LBCFG.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG));
  tmp_hsif_prot->LBELSTCTRL.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBELSTCTRL));
  tmp_hsif_prot->PSELSTCTRL.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSELSTCTRL));
  tmp_hsif_prot->PRECODER_CFG.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER_CFG));
  tmp_hsif_prot->PRECODER0_CFGA.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER0_CFGA));
  tmp_hsif_prot->PRECODER0_CFGB.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER0_CFGB));
  tmp_hsif_prot->PRECODER1_CFGA.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER1_CFGA));
  tmp_hsif_prot->PRECODER1_CFGB.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER1_CFGB));
  tmp_hsif_prot->PRECODER2_CFGA.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER2_CFGA));
  tmp_hsif_prot->PRECODER2_CFGB.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER2_CFGB));
  tmp_hsif_prot->PRECODER3_CFGA.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER3_CFGA));
  tmp_hsif_prot->PRECODER3_CFGB.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PRECODER3_CFGB));
  tmp_hsif_prot->DECODER_CFG.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER_CFG));
  tmp_hsif_prot->DECODER0_CFGA.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER0_CFGA));
  tmp_hsif_prot->DECODER0_CFGB.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER0_CFGB));
  tmp_hsif_prot->DECODER1_CFGA.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER1_CFGA));
  tmp_hsif_prot->DECODER1_CFGB.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER1_CFGB));
  tmp_hsif_prot->DECODER2_CFGA.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER2_CFGA));
  tmp_hsif_prot->DECODER2_CFGB.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER2_CFGB));
  tmp_hsif_prot->DECODER3_CFGA.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER3_CFGA));
  tmp_hsif_prot->DECODER3_CFGB.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, DECODER3_CFGB));
  tmp_hsif_prot->Interrupt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Interrupt));
  tmp_hsif_prot->Intenable.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Intenable));
  tmp_hsif_prot->InterruptZ.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, InterruptZ));
  tmp_hsif_prot->LBELST_INT.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBELST_INT));
  tmp_hsif_prot->LBELST_INTEN.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBELST_INTEN));
  tmp_hsif_prot->LBELST_INTZ.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBELST_INTZ));
  tmp_hsif_prot->PSELST_INT.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSELST_INT));
  tmp_hsif_prot->PSELST_INTEN.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSELST_INTEN));
  tmp_hsif_prot->PSELST_INTZ.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSELST_INTZ));
  tmp_hsif_prot->SliceReset.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, SliceReset));
  tmp_hsif_prot->Intstatus.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Intstatus));
  tmp_hsif_prot->XFI_LANESWAP.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, XFI_LANESWAP));
  tmp_hsif_prot->MISC.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, MISC));
  tmp_hsif_prot->Lane0ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane0ErrCnt));
  tmp_hsif_prot->Lane1ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane1ErrCnt));
  tmp_hsif_prot->Lane2ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane2ErrCnt));
  tmp_hsif_prot->Lane3ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane3ErrCnt));
  tmp_hsif_prot->Lane4ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane4ErrCnt));
  tmp_hsif_prot->Lane5ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane5ErrCnt));
  tmp_hsif_prot->Lane6ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane6ErrCnt));
  tmp_hsif_prot->Lane7ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane7ErrCnt));
  tmp_hsif_prot->Lane8ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane8ErrCnt));
  tmp_hsif_prot->Lane9ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane9ErrCnt));
  tmp_hsif_prot->Lane10ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane10ErrCnt));
  tmp_hsif_prot->Lane11ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane11ErrCnt));
  tmp_hsif_prot->Lane12ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane12ErrCnt));
  tmp_hsif_prot->Lane13ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane13ErrCnt));
  tmp_hsif_prot->Lane14ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane14ErrCnt));
  tmp_hsif_prot->Lane15ErrCnt.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, Lane15ErrCnt));
  tmp_hsif_prot->PSWITCH_MUX_INT.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSWITCH_MUX_INT));
  tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSWITCH_MUX_INTSTATUS));
  tmp_hsif_prot->PSWITCH_MUX_INTEN.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSWITCH_MUX_INTEN));
  tmp_hsif_prot->PSWITCH_MUX_INTZ.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSWITCH_MUX_INTZ));

  ch1 = (module_id & 1) ? 'B' : 'A';

  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.wrd", tmp_hsif_prot->Reset.wrd, tmp_hsif_prot->Reset.wrd == dft_hsif_prot->Reset.wrd ? 0x20 : 0x2A, dft_hsif_prot->Reset.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.rx_sfi42_3", tmp_hsif_prot->Reset.bf.rx_sfi42_3, tmp_hsif_prot->Reset.bf.rx_sfi42_3 == dft_hsif_prot->Reset.bf.rx_sfi42_3 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.rx_sfi42_3, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.rx_sfi42_2", tmp_hsif_prot->Reset.bf.rx_sfi42_2, tmp_hsif_prot->Reset.bf.rx_sfi42_2 == dft_hsif_prot->Reset.bf.rx_sfi42_2 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.rx_sfi42_2, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.rx_sfi42_1", tmp_hsif_prot->Reset.bf.rx_sfi42_1, tmp_hsif_prot->Reset.bf.rx_sfi42_1 == dft_hsif_prot->Reset.bf.rx_sfi42_1 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.rx_sfi42_1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.rx_sfi42_0", tmp_hsif_prot->Reset.bf.rx_sfi42_0, tmp_hsif_prot->Reset.bf.rx_sfi42_0 == dft_hsif_prot->Reset.bf.rx_sfi42_0 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.rx_sfi42_0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.rx_sfi41", tmp_hsif_prot->Reset.bf.rx_sfi41, tmp_hsif_prot->Reset.bf.rx_sfi41 == dft_hsif_prot->Reset.bf.rx_sfi41 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.rx_sfi41, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.rx_sfi5", tmp_hsif_prot->Reset.bf.rx_sfi5, tmp_hsif_prot->Reset.bf.rx_sfi5 == dft_hsif_prot->Reset.bf.rx_sfi5 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.rx_sfi5, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.rx_master", tmp_hsif_prot->Reset.bf.rx_master, tmp_hsif_prot->Reset.bf.rx_master == dft_hsif_prot->Reset.bf.rx_master ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.rx_master, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.tx_sfi42_3", tmp_hsif_prot->Reset.bf.tx_sfi42_3, tmp_hsif_prot->Reset.bf.tx_sfi42_3 == dft_hsif_prot->Reset.bf.tx_sfi42_3 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.tx_sfi42_3, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.tx_sfi42_2", tmp_hsif_prot->Reset.bf.tx_sfi42_2, tmp_hsif_prot->Reset.bf.tx_sfi42_2 == dft_hsif_prot->Reset.bf.tx_sfi42_2 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.tx_sfi42_2, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.tx_sfi42_1", tmp_hsif_prot->Reset.bf.tx_sfi42_1, tmp_hsif_prot->Reset.bf.tx_sfi42_1 == dft_hsif_prot->Reset.bf.tx_sfi42_1 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.tx_sfi42_1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.tx_sfi42_0", tmp_hsif_prot->Reset.bf.tx_sfi42_0, tmp_hsif_prot->Reset.bf.tx_sfi42_0 == dft_hsif_prot->Reset.bf.tx_sfi42_0 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.tx_sfi42_0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.tx_sfi41", tmp_hsif_prot->Reset.bf.tx_sfi41, tmp_hsif_prot->Reset.bf.tx_sfi41 == dft_hsif_prot->Reset.bf.tx_sfi41 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.tx_sfi41, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.tx_sfi5", tmp_hsif_prot->Reset.bf.tx_sfi5, tmp_hsif_prot->Reset.bf.tx_sfi5 == dft_hsif_prot->Reset.bf.tx_sfi5 ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.tx_sfi5, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RESET.bf.tx_master", tmp_hsif_prot->Reset.bf.tx_master, tmp_hsif_prot->Reset.bf.tx_master == dft_hsif_prot->Reset.bf.tx_master ? 0x20 : 0x2A, dft_hsif_prot->Reset.bf.tx_master, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV0.wrd", tmp_hsif_prot->Datapath_Prov0.wrd, tmp_hsif_prot->Datapath_Prov0.wrd == dft_hsif_prot->Datapath_Prov0.wrd ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov0.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV0.bf.tx_xfiselect", tmp_hsif_prot->Datapath_Prov0.bf.tx_xfiselect, tmp_hsif_prot->Datapath_Prov0.bf.tx_xfiselect == dft_hsif_prot->Datapath_Prov0.bf.tx_xfiselect ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov0.bf.tx_xfiselect, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV0.bf.rx_xfiselect", tmp_hsif_prot->Datapath_Prov0.bf.rx_xfiselect, tmp_hsif_prot->Datapath_Prov0.bf.rx_xfiselect == dft_hsif_prot->Datapath_Prov0.bf.rx_xfiselect ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov0.bf.rx_xfiselect, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV0.bf.tx_pswtchen", tmp_hsif_prot->Datapath_Prov0.bf.tx_pswtchen, tmp_hsif_prot->Datapath_Prov0.bf.tx_pswtchen == dft_hsif_prot->Datapath_Prov0.bf.tx_pswtchen ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov0.bf.tx_pswtchen, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV0.bf.tx_mrprotocol", tmp_hsif_prot->Datapath_Prov0.bf.tx_mrprotocol, tmp_hsif_prot->Datapath_Prov0.bf.tx_mrprotocol == dft_hsif_prot->Datapath_Prov0.bf.tx_mrprotocol ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov0.bf.tx_mrprotocol, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV0.bf.rx_pswtchen", tmp_hsif_prot->Datapath_Prov0.bf.rx_pswtchen, tmp_hsif_prot->Datapath_Prov0.bf.rx_pswtchen == dft_hsif_prot->Datapath_Prov0.bf.rx_pswtchen ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov0.bf.rx_pswtchen, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV0.bf.rx_mrprotocol", tmp_hsif_prot->Datapath_Prov0.bf.rx_mrprotocol, tmp_hsif_prot->Datapath_Prov0.bf.rx_mrprotocol == dft_hsif_prot->Datapath_Prov0.bf.rx_mrprotocol ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov0.bf.rx_mrprotocol, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV1.wrd", tmp_hsif_prot->Datapath_Prov1.wrd, tmp_hsif_prot->Datapath_Prov1.wrd == dft_hsif_prot->Datapath_Prov1.wrd ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov1.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV1.bf.tx_xfiselect", tmp_hsif_prot->Datapath_Prov1.bf.tx_xfiselect, tmp_hsif_prot->Datapath_Prov1.bf.tx_xfiselect == dft_hsif_prot->Datapath_Prov1.bf.tx_xfiselect ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov1.bf.tx_xfiselect, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV1.bf.rx_xfiselect", tmp_hsif_prot->Datapath_Prov1.bf.rx_xfiselect, tmp_hsif_prot->Datapath_Prov1.bf.rx_xfiselect == dft_hsif_prot->Datapath_Prov1.bf.rx_xfiselect ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov1.bf.rx_xfiselect, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV1.bf.tx_pswtchen", tmp_hsif_prot->Datapath_Prov1.bf.tx_pswtchen, tmp_hsif_prot->Datapath_Prov1.bf.tx_pswtchen == dft_hsif_prot->Datapath_Prov1.bf.tx_pswtchen ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov1.bf.tx_pswtchen, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV1.bf.tx_mrprotocol", tmp_hsif_prot->Datapath_Prov1.bf.tx_mrprotocol, tmp_hsif_prot->Datapath_Prov1.bf.tx_mrprotocol == dft_hsif_prot->Datapath_Prov1.bf.tx_mrprotocol ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov1.bf.tx_mrprotocol, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV1.bf.rx_pswtchen", tmp_hsif_prot->Datapath_Prov1.bf.rx_pswtchen, tmp_hsif_prot->Datapath_Prov1.bf.rx_pswtchen == dft_hsif_prot->Datapath_Prov1.bf.rx_pswtchen ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov1.bf.rx_pswtchen, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV1.bf.rx_mrprotocol", tmp_hsif_prot->Datapath_Prov1.bf.rx_mrprotocol, tmp_hsif_prot->Datapath_Prov1.bf.rx_mrprotocol == dft_hsif_prot->Datapath_Prov1.bf.rx_mrprotocol ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov1.bf.rx_mrprotocol, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV2.wrd", tmp_hsif_prot->Datapath_Prov2.wrd, tmp_hsif_prot->Datapath_Prov2.wrd == dft_hsif_prot->Datapath_Prov2.wrd ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov2.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV2.bf.tx_xfiselect", tmp_hsif_prot->Datapath_Prov2.bf.tx_xfiselect, tmp_hsif_prot->Datapath_Prov2.bf.tx_xfiselect == dft_hsif_prot->Datapath_Prov2.bf.tx_xfiselect ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov2.bf.tx_xfiselect, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV2.bf.rx_xfiselect", tmp_hsif_prot->Datapath_Prov2.bf.rx_xfiselect, tmp_hsif_prot->Datapath_Prov2.bf.rx_xfiselect == dft_hsif_prot->Datapath_Prov2.bf.rx_xfiselect ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov2.bf.rx_xfiselect, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV2.bf.tx_pswtchen", tmp_hsif_prot->Datapath_Prov2.bf.tx_pswtchen, tmp_hsif_prot->Datapath_Prov2.bf.tx_pswtchen == dft_hsif_prot->Datapath_Prov2.bf.tx_pswtchen ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov2.bf.tx_pswtchen, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV2.bf.tx_mrprotocol", tmp_hsif_prot->Datapath_Prov2.bf.tx_mrprotocol, tmp_hsif_prot->Datapath_Prov2.bf.tx_mrprotocol == dft_hsif_prot->Datapath_Prov2.bf.tx_mrprotocol ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov2.bf.tx_mrprotocol, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV2.bf.rx_pswtchen", tmp_hsif_prot->Datapath_Prov2.bf.rx_pswtchen, tmp_hsif_prot->Datapath_Prov2.bf.rx_pswtchen == dft_hsif_prot->Datapath_Prov2.bf.rx_pswtchen ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov2.bf.rx_pswtchen, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV2.bf.rx_mrprotocol", tmp_hsif_prot->Datapath_Prov2.bf.rx_mrprotocol, tmp_hsif_prot->Datapath_Prov2.bf.rx_mrprotocol == dft_hsif_prot->Datapath_Prov2.bf.rx_mrprotocol ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov2.bf.rx_mrprotocol, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV3.wrd", tmp_hsif_prot->Datapath_Prov3.wrd, tmp_hsif_prot->Datapath_Prov3.wrd == dft_hsif_prot->Datapath_Prov3.wrd ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov3.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV3.bf.tx_xfiselect", tmp_hsif_prot->Datapath_Prov3.bf.tx_xfiselect, tmp_hsif_prot->Datapath_Prov3.bf.tx_xfiselect == dft_hsif_prot->Datapath_Prov3.bf.tx_xfiselect ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov3.bf.tx_xfiselect, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV3.bf.rx_xfiselect", tmp_hsif_prot->Datapath_Prov3.bf.rx_xfiselect, tmp_hsif_prot->Datapath_Prov3.bf.rx_xfiselect == dft_hsif_prot->Datapath_Prov3.bf.rx_xfiselect ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov3.bf.rx_xfiselect, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV3.bf.tx_pswtchen", tmp_hsif_prot->Datapath_Prov3.bf.tx_pswtchen, tmp_hsif_prot->Datapath_Prov3.bf.tx_pswtchen == dft_hsif_prot->Datapath_Prov3.bf.tx_pswtchen ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov3.bf.tx_pswtchen, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV3.bf.tx_mrprotocol", tmp_hsif_prot->Datapath_Prov3.bf.tx_mrprotocol, tmp_hsif_prot->Datapath_Prov3.bf.tx_mrprotocol == dft_hsif_prot->Datapath_Prov3.bf.tx_mrprotocol ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov3.bf.tx_mrprotocol, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV3.bf.rx_pswtchen", tmp_hsif_prot->Datapath_Prov3.bf.rx_pswtchen, tmp_hsif_prot->Datapath_Prov3.bf.rx_pswtchen == dft_hsif_prot->Datapath_Prov3.bf.rx_pswtchen ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov3.bf.rx_pswtchen, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DATAPATH_PROV3.bf.rx_mrprotocol", tmp_hsif_prot->Datapath_Prov3.bf.rx_mrprotocol, tmp_hsif_prot->Datapath_Prov3.bf.rx_mrprotocol == dft_hsif_prot->Datapath_Prov3.bf.rx_mrprotocol ? 0x20 : 0x2A, dft_hsif_prot->Datapath_Prov3.bf.rx_mrprotocol, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXCLK_10G.wrd", tmp_hsif_prot->RXCLK_10G.wrd, tmp_hsif_prot->RXCLK_10G.wrd == dft_hsif_prot->RXCLK_10G.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXCLK_10G.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXCLK_10G.bf.lanesel3", tmp_hsif_prot->RXCLK_10G.bf.lanesel3, tmp_hsif_prot->RXCLK_10G.bf.lanesel3 == dft_hsif_prot->RXCLK_10G.bf.lanesel3 ? 0x20 : 0x2A, dft_hsif_prot->RXCLK_10G.bf.lanesel3, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXCLK_10G.bf.lanesel2", tmp_hsif_prot->RXCLK_10G.bf.lanesel2, tmp_hsif_prot->RXCLK_10G.bf.lanesel2 == dft_hsif_prot->RXCLK_10G.bf.lanesel2 ? 0x20 : 0x2A, dft_hsif_prot->RXCLK_10G.bf.lanesel2, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXCLK_10G.bf.lanesel1", tmp_hsif_prot->RXCLK_10G.bf.lanesel1, tmp_hsif_prot->RXCLK_10G.bf.lanesel1 == dft_hsif_prot->RXCLK_10G.bf.lanesel1 ? 0x20 : 0x2A, dft_hsif_prot->RXCLK_10G.bf.lanesel1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXCLK_10G.bf.lanesel0", tmp_hsif_prot->RXCLK_10G.bf.lanesel0, tmp_hsif_prot->RXCLK_10G.bf.lanesel0 == dft_hsif_prot->RXCLK_10G.bf.lanesel0 ? 0x20 : 0x2A, dft_hsif_prot->RXCLK_10G.bf.lanesel0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_CLK_40G.wrd", tmp_hsif_prot->CLK_40G.wrd, tmp_hsif_prot->CLK_40G.wrd == dft_hsif_prot->CLK_40G.wrd ? 0x20 : 0x2A, dft_hsif_prot->CLK_40G.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_CLK_40G.bf.xfi_txsel", tmp_hsif_prot->CLK_40G.bf.xfi_txsel, tmp_hsif_prot->CLK_40G.bf.xfi_txsel == dft_hsif_prot->CLK_40G.bf.xfi_txsel ? 0x20 : 0x2A, dft_hsif_prot->CLK_40G.bf.xfi_txsel, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_CLK_40G.bf.xfi_rxsel", tmp_hsif_prot->CLK_40G.bf.xfi_rxsel, tmp_hsif_prot->CLK_40G.bf.xfi_rxsel == dft_hsif_prot->CLK_40G.bf.xfi_rxsel ? 0x20 : 0x2A, dft_hsif_prot->CLK_40G.bf.xfi_rxsel, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_CLK_40G.bf.tx_aggr_mode", tmp_hsif_prot->CLK_40G.bf.tx_aggr_mode, tmp_hsif_prot->CLK_40G.bf.tx_aggr_mode == dft_hsif_prot->CLK_40G.bf.tx_aggr_mode ? 0x20 : 0x2A, dft_hsif_prot->CLK_40G.bf.tx_aggr_mode, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_CLK_40G.bf.txsel", tmp_hsif_prot->CLK_40G.bf.txsel, tmp_hsif_prot->CLK_40G.bf.txsel == dft_hsif_prot->CLK_40G.bf.txsel ? 0x20 : 0x2A, dft_hsif_prot->CLK_40G.bf.txsel, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_CLK_40G.bf.rx_aggr_mode", tmp_hsif_prot->CLK_40G.bf.rx_aggr_mode, tmp_hsif_prot->CLK_40G.bf.rx_aggr_mode == dft_hsif_prot->CLK_40G.bf.rx_aggr_mode ? 0x20 : 0x2A, dft_hsif_prot->CLK_40G.bf.rx_aggr_mode, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_CLK_40G.bf.rxsel", tmp_hsif_prot->CLK_40G.bf.rxsel, tmp_hsif_prot->CLK_40G.bf.rxsel == dft_hsif_prot->CLK_40G.bf.rxsel ? 0x20 : 0x2A, dft_hsif_prot->CLK_40G.bf.rxsel, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_OK_CTRL.wrd", tmp_hsif_prot->OK_CTRL.wrd, tmp_hsif_prot->OK_CTRL.wrd == dft_hsif_prot->OK_CTRL.wrd ? 0x20 : 0x2A, dft_hsif_prot->OK_CTRL.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_OK_CTRL.bf.synced_en", tmp_hsif_prot->OK_CTRL.bf.synced_en, tmp_hsif_prot->OK_CTRL.bf.synced_en == dft_hsif_prot->OK_CTRL.bf.synced_en ? 0x20 : 0x2A, dft_hsif_prot->OK_CTRL.bf.synced_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_OK_CTRL.bf.datadet_en", tmp_hsif_prot->OK_CTRL.bf.datadet_en, tmp_hsif_prot->OK_CTRL.bf.datadet_en == dft_hsif_prot->OK_CTRL.bf.datadet_en ? 0x20 : 0x2A, dft_hsif_prot->OK_CTRL.bf.datadet_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_OK_CTRL.bf.lock_en", tmp_hsif_prot->OK_CTRL.bf.lock_en, tmp_hsif_prot->OK_CTRL.bf.lock_en == dft_hsif_prot->OK_CTRL.bf.lock_en ? 0x20 : 0x2A, dft_hsif_prot->OK_CTRL.bf.lock_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_OK_CTRL.bf.xlos_en", tmp_hsif_prot->OK_CTRL.bf.xlos_en, tmp_hsif_prot->OK_CTRL.bf.xlos_en == dft_hsif_prot->OK_CTRL.bf.xlos_en ? 0x20 : 0x2A, dft_hsif_prot->OK_CTRL.bf.xlos_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWTCH_OK_CTRL.wrd", tmp_hsif_prot->PSWTCH_OK_CTRL.wrd, tmp_hsif_prot->PSWTCH_OK_CTRL.wrd == dft_hsif_prot->PSWTCH_OK_CTRL.wrd ? 0x20 : 0x2A, dft_hsif_prot->PSWTCH_OK_CTRL.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWTCH_OK_CTRL.bf.synced_en", tmp_hsif_prot->PSWTCH_OK_CTRL.bf.synced_en, tmp_hsif_prot->PSWTCH_OK_CTRL.bf.synced_en == dft_hsif_prot->PSWTCH_OK_CTRL.bf.synced_en ? 0x20 : 0x2A, dft_hsif_prot->PSWTCH_OK_CTRL.bf.synced_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWTCH_OK_CTRL.bf.datadet_en", tmp_hsif_prot->PSWTCH_OK_CTRL.bf.datadet_en, tmp_hsif_prot->PSWTCH_OK_CTRL.bf.datadet_en == dft_hsif_prot->PSWTCH_OK_CTRL.bf.datadet_en ? 0x20 : 0x2A, dft_hsif_prot->PSWTCH_OK_CTRL.bf.datadet_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWTCH_OK_CTRL.bf.lock_en", tmp_hsif_prot->PSWTCH_OK_CTRL.bf.lock_en, tmp_hsif_prot->PSWTCH_OK_CTRL.bf.lock_en == dft_hsif_prot->PSWTCH_OK_CTRL.bf.lock_en ? 0x20 : 0x2A, dft_hsif_prot->PSWTCH_OK_CTRL.bf.lock_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWTCH_OK_CTRL.bf.xlos_en", tmp_hsif_prot->PSWTCH_OK_CTRL.bf.xlos_en, tmp_hsif_prot->PSWTCH_OK_CTRL.bf.xlos_en == dft_hsif_prot->PSWTCH_OK_CTRL.bf.xlos_en ? 0x20 : 0x2A, dft_hsif_prot->PSWTCH_OK_CTRL.bf.xlos_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SFI41_CFG.wrd", tmp_hsif_prot->SFI41_CFG.wrd, tmp_hsif_prot->SFI41_CFG.wrd == dft_hsif_prot->SFI41_CFG.wrd ? 0x20 : 0x2A, dft_hsif_prot->SFI41_CFG.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SFI41_CFG.bf.SFI41_TXINIT", tmp_hsif_prot->SFI41_CFG.bf.SFI41_TXINIT, tmp_hsif_prot->SFI41_CFG.bf.SFI41_TXINIT == dft_hsif_prot->SFI41_CFG.bf.SFI41_TXINIT ? 0x20 : 0x2A, dft_hsif_prot->SFI41_CFG.bf.SFI41_TXINIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SFI41_CFG.bf.SFI41_RXINIT", tmp_hsif_prot->SFI41_CFG.bf.SFI41_RXINIT, tmp_hsif_prot->SFI41_CFG.bf.SFI41_RXINIT == dft_hsif_prot->SFI41_CFG.bf.SFI41_RXINIT ? 0x20 : 0x2A, dft_hsif_prot->SFI41_CFG.bf.SFI41_RXINIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SFI41_CFG.bf.SFI41_FULLREN", tmp_hsif_prot->SFI41_CFG.bf.SFI41_FULLREN, tmp_hsif_prot->SFI41_CFG.bf.SFI41_FULLREN == dft_hsif_prot->SFI41_CFG.bf.SFI41_FULLREN ? 0x20 : 0x2A, dft_hsif_prot->SFI41_CFG.bf.SFI41_FULLREN, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SFI41_CFG.bf.SFI41_SPARE", tmp_hsif_prot->SFI41_CFG.bf.SFI41_SPARE, tmp_hsif_prot->SFI41_CFG.bf.SFI41_SPARE == dft_hsif_prot->SFI41_CFG.bf.SFI41_SPARE ? 0x20 : 0x2A, dft_hsif_prot->SFI41_CFG.bf.SFI41_SPARE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SFI41_TXBITINV.wrd", tmp_hsif_prot->SFI41_TXBITINV.wrd, tmp_hsif_prot->SFI41_TXBITINV.wrd == dft_hsif_prot->SFI41_TXBITINV.wrd ? 0x20 : 0x2A, dft_hsif_prot->SFI41_TXBITINV.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SFI41_TXBITINV.bf.ENABLE", tmp_hsif_prot->SFI41_TXBITINV.bf.ENABLE, tmp_hsif_prot->SFI41_TXBITINV.bf.ENABLE == dft_hsif_prot->SFI41_TXBITINV.bf.ENABLE ? 0x20 : 0x2A, dft_hsif_prot->SFI41_TXBITINV.bf.ENABLE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SFI41_RXBITINV.wrd", tmp_hsif_prot->SFI41_RXBITINV.wrd, tmp_hsif_prot->SFI41_RXBITINV.wrd == dft_hsif_prot->SFI41_RXBITINV.wrd ? 0x20 : 0x2A, dft_hsif_prot->SFI41_RXBITINV.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SFI41_RXBITINV.bf.ENABLE", tmp_hsif_prot->SFI41_RXBITINV.bf.ENABLE, tmp_hsif_prot->SFI41_RXBITINV.bf.ENABLE == dft_hsif_prot->SFI41_RXBITINV.bf.ENABLE ? 0x20 : 0x2A, dft_hsif_prot->SFI41_RXBITINV.bf.ENABLE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_REFCLK_CFG.wrd", tmp_hsif_prot->REFCLK_CFG.wrd, tmp_hsif_prot->REFCLK_CFG.wrd == dft_hsif_prot->REFCLK_CFG.wrd ? 0x20 : 0x2A, dft_hsif_prot->REFCLK_CFG.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_REFCLK_CFG.bf.SFI5PILOT_SEL", tmp_hsif_prot->REFCLK_CFG.bf.SFI5PILOT_SEL, tmp_hsif_prot->REFCLK_CFG.bf.SFI5PILOT_SEL == dft_hsif_prot->REFCLK_CFG.bf.SFI5PILOT_SEL ? 0x20 : 0x2A, dft_hsif_prot->REFCLK_CFG.bf.SFI5PILOT_SEL, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_REFCLK_CFG.bf.LOOPCKSEL", tmp_hsif_prot->REFCLK_CFG.bf.LOOPCKSEL, tmp_hsif_prot->REFCLK_CFG.bf.LOOPCKSEL == dft_hsif_prot->REFCLK_CFG.bf.LOOPCKSEL ? 0x20 : 0x2A, dft_hsif_prot->REFCLK_CFG.bf.LOOPCKSEL, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_REFCLK_CFG.bf.CKREFDIV", tmp_hsif_prot->REFCLK_CFG.bf.CKREFDIV, tmp_hsif_prot->REFCLK_CFG.bf.CKREFDIV == dft_hsif_prot->REFCLK_CFG.bf.CKREFDIV ? 0x20 : 0x2A, dft_hsif_prot->REFCLK_CFG.bf.CKREFDIV, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_REFCLK_CFG.bf.SPARE", tmp_hsif_prot->REFCLK_CFG.bf.SPARE, tmp_hsif_prot->REFCLK_CFG.bf.SPARE == dft_hsif_prot->REFCLK_CFG.bf.SPARE ? 0x20 : 0x2A, dft_hsif_prot->REFCLK_CFG.bf.SPARE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_BITSHUFFLE.wrd", tmp_hsif_prot->BITSHUFFLE.wrd, tmp_hsif_prot->BITSHUFFLE.wrd == dft_hsif_prot->BITSHUFFLE.wrd ? 0x20 : 0x2A, dft_hsif_prot->BITSHUFFLE.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_BITSHUFFLE.bf.txprecoder_stride", tmp_hsif_prot->BITSHUFFLE.bf.txprecoder_stride, tmp_hsif_prot->BITSHUFFLE.bf.txprecoder_stride == dft_hsif_prot->BITSHUFFLE.bf.txprecoder_stride ? 0x20 : 0x2A, dft_hsif_prot->BITSHUFFLE.bf.txprecoder_stride, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_BITSHUFFLE.bf.rxdecoder_stride", tmp_hsif_prot->BITSHUFFLE.bf.rxdecoder_stride, tmp_hsif_prot->BITSHUFFLE.bf.rxdecoder_stride == dft_hsif_prot->BITSHUFFLE.bf.rxdecoder_stride ? 0x20 : 0x2A, dft_hsif_prot->BITSHUFFLE.bf.rxdecoder_stride, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP0.wrd", tmp_hsif_prot->TXLANESWAP0.wrd, tmp_hsif_prot->TXLANESWAP0.wrd == dft_hsif_prot->TXLANESWAP0.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP0.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP0.bf.lane", tmp_hsif_prot->TXLANESWAP0.bf.lane, tmp_hsif_prot->TXLANESWAP0.bf.lane == dft_hsif_prot->TXLANESWAP0.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP0.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP0.wrd", tmp_hsif_prot->RXLANESWAP0.wrd, tmp_hsif_prot->RXLANESWAP0.wrd == dft_hsif_prot->RXLANESWAP0.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP0.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP0.bf.lane", tmp_hsif_prot->RXLANESWAP0.bf.lane, tmp_hsif_prot->RXLANESWAP0.bf.lane == dft_hsif_prot->RXLANESWAP0.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP0.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP1.wrd", tmp_hsif_prot->TXLANESWAP1.wrd, tmp_hsif_prot->TXLANESWAP1.wrd == dft_hsif_prot->TXLANESWAP1.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP1.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP1.bf.lane", tmp_hsif_prot->TXLANESWAP1.bf.lane, tmp_hsif_prot->TXLANESWAP1.bf.lane == dft_hsif_prot->TXLANESWAP1.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP1.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP1.wrd", tmp_hsif_prot->RXLANESWAP1.wrd, tmp_hsif_prot->RXLANESWAP1.wrd == dft_hsif_prot->RXLANESWAP1.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP1.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP1.bf.lane", tmp_hsif_prot->RXLANESWAP1.bf.lane, tmp_hsif_prot->RXLANESWAP1.bf.lane == dft_hsif_prot->RXLANESWAP1.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP1.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP2.wrd", tmp_hsif_prot->TXLANESWAP2.wrd, tmp_hsif_prot->TXLANESWAP2.wrd == dft_hsif_prot->TXLANESWAP2.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP2.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP2.bf.lane", tmp_hsif_prot->TXLANESWAP2.bf.lane, tmp_hsif_prot->TXLANESWAP2.bf.lane == dft_hsif_prot->TXLANESWAP2.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP2.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP2.wrd", tmp_hsif_prot->RXLANESWAP2.wrd, tmp_hsif_prot->RXLANESWAP2.wrd == dft_hsif_prot->RXLANESWAP2.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP2.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP2.bf.lane", tmp_hsif_prot->RXLANESWAP2.bf.lane, tmp_hsif_prot->RXLANESWAP2.bf.lane == dft_hsif_prot->RXLANESWAP2.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP2.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP3.wrd", tmp_hsif_prot->TXLANESWAP3.wrd, tmp_hsif_prot->TXLANESWAP3.wrd == dft_hsif_prot->TXLANESWAP3.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP3.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP3.bf.lane", tmp_hsif_prot->TXLANESWAP3.bf.lane, tmp_hsif_prot->TXLANESWAP3.bf.lane == dft_hsif_prot->TXLANESWAP3.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP3.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP3.wrd", tmp_hsif_prot->RXLANESWAP3.wrd, tmp_hsif_prot->RXLANESWAP3.wrd == dft_hsif_prot->RXLANESWAP3.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP3.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP3.bf.lane", tmp_hsif_prot->RXLANESWAP3.bf.lane, tmp_hsif_prot->RXLANESWAP3.bf.lane == dft_hsif_prot->RXLANESWAP3.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP3.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP4.wrd", tmp_hsif_prot->TXLANESWAP4.wrd, tmp_hsif_prot->TXLANESWAP4.wrd == dft_hsif_prot->TXLANESWAP4.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP4.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP4.bf.lane", tmp_hsif_prot->TXLANESWAP4.bf.lane, tmp_hsif_prot->TXLANESWAP4.bf.lane == dft_hsif_prot->TXLANESWAP4.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP4.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP4.wrd", tmp_hsif_prot->RXLANESWAP4.wrd, tmp_hsif_prot->RXLANESWAP4.wrd == dft_hsif_prot->RXLANESWAP4.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP4.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP4.bf.lane", tmp_hsif_prot->RXLANESWAP4.bf.lane, tmp_hsif_prot->RXLANESWAP4.bf.lane == dft_hsif_prot->RXLANESWAP4.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP4.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP5.wrd", tmp_hsif_prot->TXLANESWAP5.wrd, tmp_hsif_prot->TXLANESWAP5.wrd == dft_hsif_prot->TXLANESWAP5.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP5.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP5.bf.lane", tmp_hsif_prot->TXLANESWAP5.bf.lane, tmp_hsif_prot->TXLANESWAP5.bf.lane == dft_hsif_prot->TXLANESWAP5.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP5.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP5.wrd", tmp_hsif_prot->RXLANESWAP5.wrd, tmp_hsif_prot->RXLANESWAP5.wrd == dft_hsif_prot->RXLANESWAP5.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP5.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP5.bf.lane", tmp_hsif_prot->RXLANESWAP5.bf.lane, tmp_hsif_prot->RXLANESWAP5.bf.lane == dft_hsif_prot->RXLANESWAP5.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP5.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP6.wrd", tmp_hsif_prot->TXLANESWAP6.wrd, tmp_hsif_prot->TXLANESWAP6.wrd == dft_hsif_prot->TXLANESWAP6.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP6.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP6.bf.lane", tmp_hsif_prot->TXLANESWAP6.bf.lane, tmp_hsif_prot->TXLANESWAP6.bf.lane == dft_hsif_prot->TXLANESWAP6.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP6.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP6.wrd", tmp_hsif_prot->RXLANESWAP6.wrd, tmp_hsif_prot->RXLANESWAP6.wrd == dft_hsif_prot->RXLANESWAP6.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP6.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP6.bf.lane", tmp_hsif_prot->RXLANESWAP6.bf.lane, tmp_hsif_prot->RXLANESWAP6.bf.lane == dft_hsif_prot->RXLANESWAP6.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP6.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP7.wrd", tmp_hsif_prot->TXLANESWAP7.wrd, tmp_hsif_prot->TXLANESWAP7.wrd == dft_hsif_prot->TXLANESWAP7.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP7.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP7.bf.lane", tmp_hsif_prot->TXLANESWAP7.bf.lane, tmp_hsif_prot->TXLANESWAP7.bf.lane == dft_hsif_prot->TXLANESWAP7.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP7.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP7.wrd", tmp_hsif_prot->RXLANESWAP7.wrd, tmp_hsif_prot->RXLANESWAP7.wrd == dft_hsif_prot->RXLANESWAP7.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP7.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP7.bf.lane", tmp_hsif_prot->RXLANESWAP7.bf.lane, tmp_hsif_prot->RXLANESWAP7.bf.lane == dft_hsif_prot->RXLANESWAP7.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP7.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP8.wrd", tmp_hsif_prot->TXLANESWAP8.wrd, tmp_hsif_prot->TXLANESWAP8.wrd == dft_hsif_prot->TXLANESWAP8.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP8.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP8.bf.lane", tmp_hsif_prot->TXLANESWAP8.bf.lane, tmp_hsif_prot->TXLANESWAP8.bf.lane == dft_hsif_prot->TXLANESWAP8.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP8.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP8.wrd", tmp_hsif_prot->RXLANESWAP8.wrd, tmp_hsif_prot->RXLANESWAP8.wrd == dft_hsif_prot->RXLANESWAP8.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP8.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP8.bf.lane", tmp_hsif_prot->RXLANESWAP8.bf.lane, tmp_hsif_prot->RXLANESWAP8.bf.lane == dft_hsif_prot->RXLANESWAP8.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP8.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP9.wrd", tmp_hsif_prot->TXLANESWAP9.wrd, tmp_hsif_prot->TXLANESWAP9.wrd == dft_hsif_prot->TXLANESWAP9.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP9.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP9.bf.lane", tmp_hsif_prot->TXLANESWAP9.bf.lane, tmp_hsif_prot->TXLANESWAP9.bf.lane == dft_hsif_prot->TXLANESWAP9.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP9.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP9.wrd", tmp_hsif_prot->RXLANESWAP9.wrd, tmp_hsif_prot->RXLANESWAP9.wrd == dft_hsif_prot->RXLANESWAP9.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP9.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP9.bf.lane", tmp_hsif_prot->RXLANESWAP9.bf.lane, tmp_hsif_prot->RXLANESWAP9.bf.lane == dft_hsif_prot->RXLANESWAP9.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP9.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP10.wrd", tmp_hsif_prot->TXLANESWAP10.wrd, tmp_hsif_prot->TXLANESWAP10.wrd == dft_hsif_prot->TXLANESWAP10.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP10.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP10.bf.lane", tmp_hsif_prot->TXLANESWAP10.bf.lane, tmp_hsif_prot->TXLANESWAP10.bf.lane == dft_hsif_prot->TXLANESWAP10.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP10.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP10.wrd", tmp_hsif_prot->RXLANESWAP10.wrd, tmp_hsif_prot->RXLANESWAP10.wrd == dft_hsif_prot->RXLANESWAP10.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP10.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP10.bf.lane", tmp_hsif_prot->RXLANESWAP10.bf.lane, tmp_hsif_prot->RXLANESWAP10.bf.lane == dft_hsif_prot->RXLANESWAP10.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP10.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP11.wrd", tmp_hsif_prot->TXLANESWAP11.wrd, tmp_hsif_prot->TXLANESWAP11.wrd == dft_hsif_prot->TXLANESWAP11.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP11.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP11.bf.lane", tmp_hsif_prot->TXLANESWAP11.bf.lane, tmp_hsif_prot->TXLANESWAP11.bf.lane == dft_hsif_prot->TXLANESWAP11.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP11.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP11.wrd", tmp_hsif_prot->RXLANESWAP11.wrd, tmp_hsif_prot->RXLANESWAP11.wrd == dft_hsif_prot->RXLANESWAP11.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP11.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP11.bf.lane", tmp_hsif_prot->RXLANESWAP11.bf.lane, tmp_hsif_prot->RXLANESWAP11.bf.lane == dft_hsif_prot->RXLANESWAP11.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP11.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP12.wrd", tmp_hsif_prot->TXLANESWAP12.wrd, tmp_hsif_prot->TXLANESWAP12.wrd == dft_hsif_prot->TXLANESWAP12.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP12.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP12.bf.lane", tmp_hsif_prot->TXLANESWAP12.bf.lane, tmp_hsif_prot->TXLANESWAP12.bf.lane == dft_hsif_prot->TXLANESWAP12.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP12.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP12.wrd", tmp_hsif_prot->RXLANESWAP12.wrd, tmp_hsif_prot->RXLANESWAP12.wrd == dft_hsif_prot->RXLANESWAP12.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP12.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP12.bf.lane", tmp_hsif_prot->RXLANESWAP12.bf.lane, tmp_hsif_prot->RXLANESWAP12.bf.lane == dft_hsif_prot->RXLANESWAP12.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP12.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP13.wrd", tmp_hsif_prot->TXLANESWAP13.wrd, tmp_hsif_prot->TXLANESWAP13.wrd == dft_hsif_prot->TXLANESWAP13.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP13.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP13.bf.lane", tmp_hsif_prot->TXLANESWAP13.bf.lane, tmp_hsif_prot->TXLANESWAP13.bf.lane == dft_hsif_prot->TXLANESWAP13.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP13.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP13.wrd", tmp_hsif_prot->RXLANESWAP13.wrd, tmp_hsif_prot->RXLANESWAP13.wrd == dft_hsif_prot->RXLANESWAP13.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP13.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP13.bf.lane", tmp_hsif_prot->RXLANESWAP13.bf.lane, tmp_hsif_prot->RXLANESWAP13.bf.lane == dft_hsif_prot->RXLANESWAP13.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP13.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP14.wrd", tmp_hsif_prot->TXLANESWAP14.wrd, tmp_hsif_prot->TXLANESWAP14.wrd == dft_hsif_prot->TXLANESWAP14.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP14.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP14.bf.lane", tmp_hsif_prot->TXLANESWAP14.bf.lane, tmp_hsif_prot->TXLANESWAP14.bf.lane == dft_hsif_prot->TXLANESWAP14.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP14.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP14.wrd", tmp_hsif_prot->RXLANESWAP14.wrd, tmp_hsif_prot->RXLANESWAP14.wrd == dft_hsif_prot->RXLANESWAP14.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP14.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP14.bf.lane", tmp_hsif_prot->RXLANESWAP14.bf.lane, tmp_hsif_prot->RXLANESWAP14.bf.lane == dft_hsif_prot->RXLANESWAP14.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP14.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP15.wrd", tmp_hsif_prot->TXLANESWAP15.wrd, tmp_hsif_prot->TXLANESWAP15.wrd == dft_hsif_prot->TXLANESWAP15.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP15.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP15.bf.lane", tmp_hsif_prot->TXLANESWAP15.bf.lane, tmp_hsif_prot->TXLANESWAP15.bf.lane == dft_hsif_prot->TXLANESWAP15.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP15.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP15.wrd", tmp_hsif_prot->RXLANESWAP15.wrd, tmp_hsif_prot->RXLANESWAP15.wrd == dft_hsif_prot->RXLANESWAP15.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP15.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP15.bf.lane", tmp_hsif_prot->RXLANESWAP15.bf.lane, tmp_hsif_prot->RXLANESWAP15.bf.lane == dft_hsif_prot->RXLANESWAP15.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP15.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP16.wrd", tmp_hsif_prot->TXLANESWAP16.wrd, tmp_hsif_prot->TXLANESWAP16.wrd == dft_hsif_prot->TXLANESWAP16.wrd ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP16.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_TXLANESWAP16.bf.lane", tmp_hsif_prot->TXLANESWAP16.bf.lane, tmp_hsif_prot->TXLANESWAP16.bf.lane == dft_hsif_prot->TXLANESWAP16.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->TXLANESWAP16.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP16.wrd", tmp_hsif_prot->RXLANESWAP16.wrd, tmp_hsif_prot->RXLANESWAP16.wrd == dft_hsif_prot->RXLANESWAP16.wrd ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP16.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_RXLANESWAP16.bf.lane", tmp_hsif_prot->RXLANESWAP16.bf.lane, tmp_hsif_prot->RXLANESWAP16.bf.lane == dft_hsif_prot->RXLANESWAP16.bf.lane ? 0x20 : 0x2A, dft_hsif_prot->RXLANESWAP16.bf.lane, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBCFG.wrd", tmp_hsif_prot->LBCFG.wrd, tmp_hsif_prot->LBCFG.wrd == dft_hsif_prot->LBCFG.wrd ? 0x20 : 0x2A, dft_hsif_prot->LBCFG.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBCFG.bf.txrxlb3_en", tmp_hsif_prot->LBCFG.bf.txrxlb3_en, tmp_hsif_prot->LBCFG.bf.txrxlb3_en == dft_hsif_prot->LBCFG.bf.txrxlb3_en ? 0x20 : 0x2A, dft_hsif_prot->LBCFG.bf.txrxlb3_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBCFG.bf.txrxlb2_en", tmp_hsif_prot->LBCFG.bf.txrxlb2_en, tmp_hsif_prot->LBCFG.bf.txrxlb2_en == dft_hsif_prot->LBCFG.bf.txrxlb2_en ? 0x20 : 0x2A, dft_hsif_prot->LBCFG.bf.txrxlb2_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBCFG.bf.txrxlb1_en", tmp_hsif_prot->LBCFG.bf.txrxlb1_en, tmp_hsif_prot->LBCFG.bf.txrxlb1_en == dft_hsif_prot->LBCFG.bf.txrxlb1_en ? 0x20 : 0x2A, dft_hsif_prot->LBCFG.bf.txrxlb1_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBCFG.bf.txrxlb0_en", tmp_hsif_prot->LBCFG.bf.txrxlb0_en, tmp_hsif_prot->LBCFG.bf.txrxlb0_en == dft_hsif_prot->LBCFG.bf.txrxlb0_en ? 0x20 : 0x2A, dft_hsif_prot->LBCFG.bf.txrxlb0_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBCFG.bf.rxtxlb3_en", tmp_hsif_prot->LBCFG.bf.rxtxlb3_en, tmp_hsif_prot->LBCFG.bf.rxtxlb3_en == dft_hsif_prot->LBCFG.bf.rxtxlb3_en ? 0x20 : 0x2A, dft_hsif_prot->LBCFG.bf.rxtxlb3_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBCFG.bf.rxtxlb2_en", tmp_hsif_prot->LBCFG.bf.rxtxlb2_en, tmp_hsif_prot->LBCFG.bf.rxtxlb2_en == dft_hsif_prot->LBCFG.bf.rxtxlb2_en ? 0x20 : 0x2A, dft_hsif_prot->LBCFG.bf.rxtxlb2_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBCFG.bf.rxtxlb1_en", tmp_hsif_prot->LBCFG.bf.rxtxlb1_en, tmp_hsif_prot->LBCFG.bf.rxtxlb1_en == dft_hsif_prot->LBCFG.bf.rxtxlb1_en ? 0x20 : 0x2A, dft_hsif_prot->LBCFG.bf.rxtxlb1_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBCFG.bf.rxtxlb0_en", tmp_hsif_prot->LBCFG.bf.rxtxlb0_en, tmp_hsif_prot->LBCFG.bf.rxtxlb0_en == dft_hsif_prot->LBCFG.bf.rxtxlb0_en ? 0x20 : 0x2A, dft_hsif_prot->LBCFG.bf.rxtxlb0_en, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELSTCTRL.wrd", tmp_hsif_prot->LBELSTCTRL.wrd, tmp_hsif_prot->LBELSTCTRL.wrd == dft_hsif_prot->LBELSTCTRL.wrd ? 0x20 : 0x2A, dft_hsif_prot->LBELSTCTRL.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELSTCTRL.bf.TXRXLB3_INIT", tmp_hsif_prot->LBELSTCTRL.bf.TXRXLB3_INIT, tmp_hsif_prot->LBELSTCTRL.bf.TXRXLB3_INIT == dft_hsif_prot->LBELSTCTRL.bf.TXRXLB3_INIT ? 0x20 : 0x2A, dft_hsif_prot->LBELSTCTRL.bf.TXRXLB3_INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELSTCTRL.bf.TXRXLB2_INIT", tmp_hsif_prot->LBELSTCTRL.bf.TXRXLB2_INIT, tmp_hsif_prot->LBELSTCTRL.bf.TXRXLB2_INIT == dft_hsif_prot->LBELSTCTRL.bf.TXRXLB2_INIT ? 0x20 : 0x2A, dft_hsif_prot->LBELSTCTRL.bf.TXRXLB2_INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELSTCTRL.bf.TXRXLB1_INIT", tmp_hsif_prot->LBELSTCTRL.bf.TXRXLB1_INIT, tmp_hsif_prot->LBELSTCTRL.bf.TXRXLB1_INIT == dft_hsif_prot->LBELSTCTRL.bf.TXRXLB1_INIT ? 0x20 : 0x2A, dft_hsif_prot->LBELSTCTRL.bf.TXRXLB1_INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELSTCTRL.bf.TXRXLB0_INIT", tmp_hsif_prot->LBELSTCTRL.bf.TXRXLB0_INIT, tmp_hsif_prot->LBELSTCTRL.bf.TXRXLB0_INIT == dft_hsif_prot->LBELSTCTRL.bf.TXRXLB0_INIT ? 0x20 : 0x2A, dft_hsif_prot->LBELSTCTRL.bf.TXRXLB0_INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELSTCTRL.bf.RXTXLB3_INIT", tmp_hsif_prot->LBELSTCTRL.bf.RXTXLB3_INIT, tmp_hsif_prot->LBELSTCTRL.bf.RXTXLB3_INIT == dft_hsif_prot->LBELSTCTRL.bf.RXTXLB3_INIT ? 0x20 : 0x2A, dft_hsif_prot->LBELSTCTRL.bf.RXTXLB3_INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELSTCTRL.bf.RXTXLB2_INIT", tmp_hsif_prot->LBELSTCTRL.bf.RXTXLB2_INIT, tmp_hsif_prot->LBELSTCTRL.bf.RXTXLB2_INIT == dft_hsif_prot->LBELSTCTRL.bf.RXTXLB2_INIT ? 0x20 : 0x2A, dft_hsif_prot->LBELSTCTRL.bf.RXTXLB2_INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELSTCTRL.bf.RXTXLB1_INIT", tmp_hsif_prot->LBELSTCTRL.bf.RXTXLB1_INIT, tmp_hsif_prot->LBELSTCTRL.bf.RXTXLB1_INIT == dft_hsif_prot->LBELSTCTRL.bf.RXTXLB1_INIT ? 0x20 : 0x2A, dft_hsif_prot->LBELSTCTRL.bf.RXTXLB1_INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELSTCTRL.bf.RXTXLB0_INIT", tmp_hsif_prot->LBELSTCTRL.bf.RXTXLB0_INIT, tmp_hsif_prot->LBELSTCTRL.bf.RXTXLB0_INIT == dft_hsif_prot->LBELSTCTRL.bf.RXTXLB0_INIT ? 0x20 : 0x2A, dft_hsif_prot->LBELSTCTRL.bf.RXTXLB0_INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELSTCTRL.wrd", tmp_hsif_prot->PSELSTCTRL.wrd, tmp_hsif_prot->PSELSTCTRL.wrd == dft_hsif_prot->PSELSTCTRL.wrd ? 0x20 : 0x2A, dft_hsif_prot->PSELSTCTRL.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELSTCTRL.bf.TX3INIT", tmp_hsif_prot->PSELSTCTRL.bf.TX3INIT, tmp_hsif_prot->PSELSTCTRL.bf.TX3INIT == dft_hsif_prot->PSELSTCTRL.bf.TX3INIT ? 0x20 : 0x2A, dft_hsif_prot->PSELSTCTRL.bf.TX3INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELSTCTRL.bf.TX2INIT", tmp_hsif_prot->PSELSTCTRL.bf.TX2INIT, tmp_hsif_prot->PSELSTCTRL.bf.TX2INIT == dft_hsif_prot->PSELSTCTRL.bf.TX2INIT ? 0x20 : 0x2A, dft_hsif_prot->PSELSTCTRL.bf.TX2INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELSTCTRL.bf.TX1INIT", tmp_hsif_prot->PSELSTCTRL.bf.TX1INIT, tmp_hsif_prot->PSELSTCTRL.bf.TX1INIT == dft_hsif_prot->PSELSTCTRL.bf.TX1INIT ? 0x20 : 0x2A, dft_hsif_prot->PSELSTCTRL.bf.TX1INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELSTCTRL.bf.TX0INIT", tmp_hsif_prot->PSELSTCTRL.bf.TX0INIT, tmp_hsif_prot->PSELSTCTRL.bf.TX0INIT == dft_hsif_prot->PSELSTCTRL.bf.TX0INIT ? 0x20 : 0x2A, dft_hsif_prot->PSELSTCTRL.bf.TX0INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELSTCTRL.bf.RX3INIT", tmp_hsif_prot->PSELSTCTRL.bf.RX3INIT, tmp_hsif_prot->PSELSTCTRL.bf.RX3INIT == dft_hsif_prot->PSELSTCTRL.bf.RX3INIT ? 0x20 : 0x2A, dft_hsif_prot->PSELSTCTRL.bf.RX3INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELSTCTRL.bf.RX2INIT", tmp_hsif_prot->PSELSTCTRL.bf.RX2INIT, tmp_hsif_prot->PSELSTCTRL.bf.RX2INIT == dft_hsif_prot->PSELSTCTRL.bf.RX2INIT ? 0x20 : 0x2A, dft_hsif_prot->PSELSTCTRL.bf.RX2INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELSTCTRL.bf.RX1INIT", tmp_hsif_prot->PSELSTCTRL.bf.RX1INIT, tmp_hsif_prot->PSELSTCTRL.bf.RX1INIT == dft_hsif_prot->PSELSTCTRL.bf.RX1INIT ? 0x20 : 0x2A, dft_hsif_prot->PSELSTCTRL.bf.RX1INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELSTCTRL.bf.RX0INIT", tmp_hsif_prot->PSELSTCTRL.bf.RX0INIT, tmp_hsif_prot->PSELSTCTRL.bf.RX0INIT == dft_hsif_prot->PSELSTCTRL.bf.RX0INIT ? 0x20 : 0x2A, dft_hsif_prot->PSELSTCTRL.bf.RX0INIT, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER_CFG.wrd", tmp_hsif_prot->PRECODER_CFG.wrd, tmp_hsif_prot->PRECODER_CFG.wrd == dft_hsif_prot->PRECODER_CFG.wrd ? 0x20 : 0x2A, dft_hsif_prot->PRECODER_CFG.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER_CFG.bf.MODE", tmp_hsif_prot->PRECODER_CFG.bf.MODE, tmp_hsif_prot->PRECODER_CFG.bf.MODE == dft_hsif_prot->PRECODER_CFG.bf.MODE ? 0x20 : 0x2A, dft_hsif_prot->PRECODER_CFG.bf.MODE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER0_CFGA.wrd", tmp_hsif_prot->PRECODER0_CFGA.wrd, tmp_hsif_prot->PRECODER0_CFGA.wrd == dft_hsif_prot->PRECODER0_CFGA.wrd ? 0x20 : 0x2A, dft_hsif_prot->PRECODER0_CFGA.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER0_CFGA.bf.TTI", tmp_hsif_prot->PRECODER0_CFGA.bf.TTI, tmp_hsif_prot->PRECODER0_CFGA.bf.TTI == dft_hsif_prot->PRECODER0_CFGA.bf.TTI ? 0x20 : 0x2A, dft_hsif_prot->PRECODER0_CFGA.bf.TTI, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER0_CFGB.wrd", tmp_hsif_prot->PRECODER0_CFGB.wrd, tmp_hsif_prot->PRECODER0_CFGB.wrd == dft_hsif_prot->PRECODER0_CFGB.wrd ? 0x20 : 0x2A, dft_hsif_prot->PRECODER0_CFGB.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER0_CFGB.bf.TTQ", tmp_hsif_prot->PRECODER0_CFGB.bf.TTQ, tmp_hsif_prot->PRECODER0_CFGB.bf.TTQ == dft_hsif_prot->PRECODER0_CFGB.bf.TTQ ? 0x20 : 0x2A, dft_hsif_prot->PRECODER0_CFGB.bf.TTQ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER1_CFGA.wrd", tmp_hsif_prot->PRECODER1_CFGA.wrd, tmp_hsif_prot->PRECODER1_CFGA.wrd == dft_hsif_prot->PRECODER1_CFGA.wrd ? 0x20 : 0x2A, dft_hsif_prot->PRECODER1_CFGA.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER1_CFGA.bf.TTI", tmp_hsif_prot->PRECODER1_CFGA.bf.TTI, tmp_hsif_prot->PRECODER1_CFGA.bf.TTI == dft_hsif_prot->PRECODER1_CFGA.bf.TTI ? 0x20 : 0x2A, dft_hsif_prot->PRECODER1_CFGA.bf.TTI, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER1_CFGB.wrd", tmp_hsif_prot->PRECODER1_CFGB.wrd, tmp_hsif_prot->PRECODER1_CFGB.wrd == dft_hsif_prot->PRECODER1_CFGB.wrd ? 0x20 : 0x2A, dft_hsif_prot->PRECODER1_CFGB.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER1_CFGB.bf.TTQ", tmp_hsif_prot->PRECODER1_CFGB.bf.TTQ, tmp_hsif_prot->PRECODER1_CFGB.bf.TTQ == dft_hsif_prot->PRECODER1_CFGB.bf.TTQ ? 0x20 : 0x2A, dft_hsif_prot->PRECODER1_CFGB.bf.TTQ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER2_CFGA.wrd", tmp_hsif_prot->PRECODER2_CFGA.wrd, tmp_hsif_prot->PRECODER2_CFGA.wrd == dft_hsif_prot->PRECODER2_CFGA.wrd ? 0x20 : 0x2A, dft_hsif_prot->PRECODER2_CFGA.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER2_CFGA.bf.TTI", tmp_hsif_prot->PRECODER2_CFGA.bf.TTI, tmp_hsif_prot->PRECODER2_CFGA.bf.TTI == dft_hsif_prot->PRECODER2_CFGA.bf.TTI ? 0x20 : 0x2A, dft_hsif_prot->PRECODER2_CFGA.bf.TTI, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER2_CFGB.wrd", tmp_hsif_prot->PRECODER2_CFGB.wrd, tmp_hsif_prot->PRECODER2_CFGB.wrd == dft_hsif_prot->PRECODER2_CFGB.wrd ? 0x20 : 0x2A, dft_hsif_prot->PRECODER2_CFGB.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER2_CFGB.bf.TTQ", tmp_hsif_prot->PRECODER2_CFGB.bf.TTQ, tmp_hsif_prot->PRECODER2_CFGB.bf.TTQ == dft_hsif_prot->PRECODER2_CFGB.bf.TTQ ? 0x20 : 0x2A, dft_hsif_prot->PRECODER2_CFGB.bf.TTQ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER3_CFGA.wrd", tmp_hsif_prot->PRECODER3_CFGA.wrd, tmp_hsif_prot->PRECODER3_CFGA.wrd == dft_hsif_prot->PRECODER3_CFGA.wrd ? 0x20 : 0x2A, dft_hsif_prot->PRECODER3_CFGA.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER3_CFGA.bf.TTI", tmp_hsif_prot->PRECODER3_CFGA.bf.TTI, tmp_hsif_prot->PRECODER3_CFGA.bf.TTI == dft_hsif_prot->PRECODER3_CFGA.bf.TTI ? 0x20 : 0x2A, dft_hsif_prot->PRECODER3_CFGA.bf.TTI, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER3_CFGB.wrd", tmp_hsif_prot->PRECODER3_CFGB.wrd, tmp_hsif_prot->PRECODER3_CFGB.wrd == dft_hsif_prot->PRECODER3_CFGB.wrd ? 0x20 : 0x2A, dft_hsif_prot->PRECODER3_CFGB.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PRECODER3_CFGB.bf.TTQ", tmp_hsif_prot->PRECODER3_CFGB.bf.TTQ, tmp_hsif_prot->PRECODER3_CFGB.bf.TTQ == dft_hsif_prot->PRECODER3_CFGB.bf.TTQ ? 0x20 : 0x2A, dft_hsif_prot->PRECODER3_CFGB.bf.TTQ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER_CFG.wrd", tmp_hsif_prot->DECODER_CFG.wrd, tmp_hsif_prot->DECODER_CFG.wrd == dft_hsif_prot->DECODER_CFG.wrd ? 0x20 : 0x2A, dft_hsif_prot->DECODER_CFG.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER_CFG.bf.MODE", tmp_hsif_prot->DECODER_CFG.bf.MODE, tmp_hsif_prot->DECODER_CFG.bf.MODE == dft_hsif_prot->DECODER_CFG.bf.MODE ? 0x20 : 0x2A, dft_hsif_prot->DECODER_CFG.bf.MODE, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER0_CFGA.wrd", tmp_hsif_prot->DECODER0_CFGA.wrd, tmp_hsif_prot->DECODER0_CFGA.wrd == dft_hsif_prot->DECODER0_CFGA.wrd ? 0x20 : 0x2A, dft_hsif_prot->DECODER0_CFGA.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER0_CFGA.bf.TTA", tmp_hsif_prot->DECODER0_CFGA.bf.TTA, tmp_hsif_prot->DECODER0_CFGA.bf.TTA == dft_hsif_prot->DECODER0_CFGA.bf.TTA ? 0x20 : 0x2A, dft_hsif_prot->DECODER0_CFGA.bf.TTA, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER0_CFGB.wrd", tmp_hsif_prot->DECODER0_CFGB.wrd, tmp_hsif_prot->DECODER0_CFGB.wrd == dft_hsif_prot->DECODER0_CFGB.wrd ? 0x20 : 0x2A, dft_hsif_prot->DECODER0_CFGB.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER0_CFGB.bf.TTB", tmp_hsif_prot->DECODER0_CFGB.bf.TTB, tmp_hsif_prot->DECODER0_CFGB.bf.TTB == dft_hsif_prot->DECODER0_CFGB.bf.TTB ? 0x20 : 0x2A, dft_hsif_prot->DECODER0_CFGB.bf.TTB, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER1_CFGA.wrd", tmp_hsif_prot->DECODER1_CFGA.wrd, tmp_hsif_prot->DECODER1_CFGA.wrd == dft_hsif_prot->DECODER1_CFGA.wrd ? 0x20 : 0x2A, dft_hsif_prot->DECODER1_CFGA.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER1_CFGA.bf.TTA", tmp_hsif_prot->DECODER1_CFGA.bf.TTA, tmp_hsif_prot->DECODER1_CFGA.bf.TTA == dft_hsif_prot->DECODER1_CFGA.bf.TTA ? 0x20 : 0x2A, dft_hsif_prot->DECODER1_CFGA.bf.TTA, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER1_CFGB.wrd", tmp_hsif_prot->DECODER1_CFGB.wrd, tmp_hsif_prot->DECODER1_CFGB.wrd == dft_hsif_prot->DECODER1_CFGB.wrd ? 0x20 : 0x2A, dft_hsif_prot->DECODER1_CFGB.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER1_CFGB.bf.TTB", tmp_hsif_prot->DECODER1_CFGB.bf.TTB, tmp_hsif_prot->DECODER1_CFGB.bf.TTB == dft_hsif_prot->DECODER1_CFGB.bf.TTB ? 0x20 : 0x2A, dft_hsif_prot->DECODER1_CFGB.bf.TTB, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER2_CFGA.wrd", tmp_hsif_prot->DECODER2_CFGA.wrd, tmp_hsif_prot->DECODER2_CFGA.wrd == dft_hsif_prot->DECODER2_CFGA.wrd ? 0x20 : 0x2A, dft_hsif_prot->DECODER2_CFGA.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER2_CFGA.bf.TTA", tmp_hsif_prot->DECODER2_CFGA.bf.TTA, tmp_hsif_prot->DECODER2_CFGA.bf.TTA == dft_hsif_prot->DECODER2_CFGA.bf.TTA ? 0x20 : 0x2A, dft_hsif_prot->DECODER2_CFGA.bf.TTA, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER2_CFGB.wrd", tmp_hsif_prot->DECODER2_CFGB.wrd, tmp_hsif_prot->DECODER2_CFGB.wrd == dft_hsif_prot->DECODER2_CFGB.wrd ? 0x20 : 0x2A, dft_hsif_prot->DECODER2_CFGB.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER2_CFGB.bf.TTB", tmp_hsif_prot->DECODER2_CFGB.bf.TTB, tmp_hsif_prot->DECODER2_CFGB.bf.TTB == dft_hsif_prot->DECODER2_CFGB.bf.TTB ? 0x20 : 0x2A, dft_hsif_prot->DECODER2_CFGB.bf.TTB, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER3_CFGA.wrd", tmp_hsif_prot->DECODER3_CFGA.wrd, tmp_hsif_prot->DECODER3_CFGA.wrd == dft_hsif_prot->DECODER3_CFGA.wrd ? 0x20 : 0x2A, dft_hsif_prot->DECODER3_CFGA.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER3_CFGA.bf.TTA", tmp_hsif_prot->DECODER3_CFGA.bf.TTA, tmp_hsif_prot->DECODER3_CFGA.bf.TTA == dft_hsif_prot->DECODER3_CFGA.bf.TTA ? 0x20 : 0x2A, dft_hsif_prot->DECODER3_CFGA.bf.TTA, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER3_CFGB.wrd", tmp_hsif_prot->DECODER3_CFGB.wrd, tmp_hsif_prot->DECODER3_CFGB.wrd == dft_hsif_prot->DECODER3_CFGB.wrd ? 0x20 : 0x2A, dft_hsif_prot->DECODER3_CFGB.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_DECODER3_CFGB.bf.TTB", tmp_hsif_prot->DECODER3_CFGB.bf.TTB, tmp_hsif_prot->DECODER3_CFGB.bf.TTB == dft_hsif_prot->DECODER3_CFGB.bf.TTB ? 0x20 : 0x2A, dft_hsif_prot->DECODER3_CFGB.bf.TTB, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.wrd", tmp_hsif_prot->Interrupt.wrd, tmp_hsif_prot->Interrupt.wrd == dft_hsif_prot->Interrupt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.PSWITCH_MUX_INTi", tmp_hsif_prot->Interrupt.bf.PSWITCH_MUX_INTi, tmp_hsif_prot->Interrupt.bf.PSWITCH_MUX_INTi == dft_hsif_prot->Interrupt.bf.PSWITCH_MUX_INTi ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.PSWITCH_MUX_INTi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.SFI41_TXCLKLOSSi", tmp_hsif_prot->Interrupt.bf.SFI41_TXCLKLOSSi, tmp_hsif_prot->Interrupt.bf.SFI41_TXCLKLOSSi == dft_hsif_prot->Interrupt.bf.SFI41_TXCLKLOSSi ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.SFI41_TXCLKLOSSi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.SFI41_RXCLKLOSSi", tmp_hsif_prot->Interrupt.bf.SFI41_RXCLKLOSSi, tmp_hsif_prot->Interrupt.bf.SFI41_RXCLKLOSSi == dft_hsif_prot->Interrupt.bf.SFI41_RXCLKLOSSi ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.SFI41_RXCLKLOSSi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.SFI41_TXPTRSLIPi", tmp_hsif_prot->Interrupt.bf.SFI41_TXPTRSLIPi, tmp_hsif_prot->Interrupt.bf.SFI41_TXPTRSLIPi == dft_hsif_prot->Interrupt.bf.SFI41_TXPTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.SFI41_TXPTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.SFI41_RXPTRSLIPi", tmp_hsif_prot->Interrupt.bf.SFI41_RXPTRSLIPi, tmp_hsif_prot->Interrupt.bf.SFI41_RXPTRSLIPi == dft_hsif_prot->Interrupt.bf.SFI41_RXPTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.SFI41_RXPTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.PSELST_INTi", tmp_hsif_prot->Interrupt.bf.PSELST_INTi, tmp_hsif_prot->Interrupt.bf.PSELST_INTi == dft_hsif_prot->Interrupt.bf.PSELST_INTi ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.PSELST_INTi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.LBELST_INTi", tmp_hsif_prot->Interrupt.bf.LBELST_INTi, tmp_hsif_prot->Interrupt.bf.LBELST_INTi == dft_hsif_prot->Interrupt.bf.LBELST_INTi ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.LBELST_INTi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.SFI42i", tmp_hsif_prot->Interrupt.bf.SFI42i, tmp_hsif_prot->Interrupt.bf.SFI42i == dft_hsif_prot->Interrupt.bf.SFI42i ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.SFI42i, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.SFI5i", tmp_hsif_prot->Interrupt.bf.SFI5i, tmp_hsif_prot->Interrupt.bf.SFI5i == dft_hsif_prot->Interrupt.bf.SFI5i ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.SFI5i, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.MR_SLC3i", tmp_hsif_prot->Interrupt.bf.MR_SLC3i, tmp_hsif_prot->Interrupt.bf.MR_SLC3i == dft_hsif_prot->Interrupt.bf.MR_SLC3i ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.MR_SLC3i, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.MR_SLC2i", tmp_hsif_prot->Interrupt.bf.MR_SLC2i, tmp_hsif_prot->Interrupt.bf.MR_SLC2i == dft_hsif_prot->Interrupt.bf.MR_SLC2i ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.MR_SLC2i, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.MR_SLC1i", tmp_hsif_prot->Interrupt.bf.MR_SLC1i, tmp_hsif_prot->Interrupt.bf.MR_SLC1i == dft_hsif_prot->Interrupt.bf.MR_SLC1i ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.MR_SLC1i, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPT.bf.MR_SLC0i", tmp_hsif_prot->Interrupt.bf.MR_SLC0i, tmp_hsif_prot->Interrupt.bf.MR_SLC0i == dft_hsif_prot->Interrupt.bf.MR_SLC0i ? 0x20 : 0x2A, dft_hsif_prot->Interrupt.bf.MR_SLC0i, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.wrd", tmp_hsif_prot->Intenable.wrd, tmp_hsif_prot->Intenable.wrd == dft_hsif_prot->Intenable.wrd ? 0x20 : 0x2A, dft_hsif_prot->Intenable.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.PSWITCH_MUX_INTe", tmp_hsif_prot->Intenable.bf.PSWITCH_MUX_INTe, tmp_hsif_prot->Intenable.bf.PSWITCH_MUX_INTe == dft_hsif_prot->Intenable.bf.PSWITCH_MUX_INTe ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.PSWITCH_MUX_INTe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.SFI41_TXCLKLOSSe", tmp_hsif_prot->Intenable.bf.SFI41_TXCLKLOSSe, tmp_hsif_prot->Intenable.bf.SFI41_TXCLKLOSSe == dft_hsif_prot->Intenable.bf.SFI41_TXCLKLOSSe ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.SFI41_TXCLKLOSSe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.SFI41_RXCLKLOSSe", tmp_hsif_prot->Intenable.bf.SFI41_RXCLKLOSSe, tmp_hsif_prot->Intenable.bf.SFI41_RXCLKLOSSe == dft_hsif_prot->Intenable.bf.SFI41_RXCLKLOSSe ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.SFI41_RXCLKLOSSe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.SFI41_TXPTRSLIPe", tmp_hsif_prot->Intenable.bf.SFI41_TXPTRSLIPe, tmp_hsif_prot->Intenable.bf.SFI41_TXPTRSLIPe == dft_hsif_prot->Intenable.bf.SFI41_TXPTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.SFI41_TXPTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.SFI41_RXPTRSLIPe", tmp_hsif_prot->Intenable.bf.SFI41_RXPTRSLIPe, tmp_hsif_prot->Intenable.bf.SFI41_RXPTRSLIPe == dft_hsif_prot->Intenable.bf.SFI41_RXPTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.SFI41_RXPTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.PSELST_INTe", tmp_hsif_prot->Intenable.bf.PSELST_INTe, tmp_hsif_prot->Intenable.bf.PSELST_INTe == dft_hsif_prot->Intenable.bf.PSELST_INTe ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.PSELST_INTe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.LBELST_INTe", tmp_hsif_prot->Intenable.bf.LBELST_INTe, tmp_hsif_prot->Intenable.bf.LBELST_INTe == dft_hsif_prot->Intenable.bf.LBELST_INTe ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.LBELST_INTe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.SFI42e", tmp_hsif_prot->Intenable.bf.SFI42e, tmp_hsif_prot->Intenable.bf.SFI42e == dft_hsif_prot->Intenable.bf.SFI42e ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.SFI42e, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.SFI5e", tmp_hsif_prot->Intenable.bf.SFI5e, tmp_hsif_prot->Intenable.bf.SFI5e == dft_hsif_prot->Intenable.bf.SFI5e ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.SFI5e, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.MR_SLC3e", tmp_hsif_prot->Intenable.bf.MR_SLC3e, tmp_hsif_prot->Intenable.bf.MR_SLC3e == dft_hsif_prot->Intenable.bf.MR_SLC3e ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.MR_SLC3e, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.MR_SLC2e", tmp_hsif_prot->Intenable.bf.MR_SLC2e, tmp_hsif_prot->Intenable.bf.MR_SLC2e == dft_hsif_prot->Intenable.bf.MR_SLC2e ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.MR_SLC2e, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.MR_SLC1e", tmp_hsif_prot->Intenable.bf.MR_SLC1e, tmp_hsif_prot->Intenable.bf.MR_SLC1e == dft_hsif_prot->Intenable.bf.MR_SLC1e ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.MR_SLC1e, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTENABLE.bf.MR_SLC0e", tmp_hsif_prot->Intenable.bf.MR_SLC0e, tmp_hsif_prot->Intenable.bf.MR_SLC0e == dft_hsif_prot->Intenable.bf.MR_SLC0e ? 0x20 : 0x2A, dft_hsif_prot->Intenable.bf.MR_SLC0e, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.wrd", tmp_hsif_prot->InterruptZ.wrd, tmp_hsif_prot->InterruptZ.wrd == dft_hsif_prot->InterruptZ.wrd ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.PSWITCH_MUX_INTiZ", tmp_hsif_prot->InterruptZ.bf.PSWITCH_MUX_INTiZ, tmp_hsif_prot->InterruptZ.bf.PSWITCH_MUX_INTiZ == dft_hsif_prot->InterruptZ.bf.PSWITCH_MUX_INTiZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.PSWITCH_MUX_INTiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.SFI41_TXCLKLOSSiZ", tmp_hsif_prot->InterruptZ.bf.SFI41_TXCLKLOSSiZ, tmp_hsif_prot->InterruptZ.bf.SFI41_TXCLKLOSSiZ == dft_hsif_prot->InterruptZ.bf.SFI41_TXCLKLOSSiZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.SFI41_TXCLKLOSSiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.SFI41_RXCLKLOSSiZ", tmp_hsif_prot->InterruptZ.bf.SFI41_RXCLKLOSSiZ, tmp_hsif_prot->InterruptZ.bf.SFI41_RXCLKLOSSiZ == dft_hsif_prot->InterruptZ.bf.SFI41_RXCLKLOSSiZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.SFI41_RXCLKLOSSiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.SFI41_TXPTRSLIPiZ", tmp_hsif_prot->InterruptZ.bf.SFI41_TXPTRSLIPiZ, tmp_hsif_prot->InterruptZ.bf.SFI41_TXPTRSLIPiZ == dft_hsif_prot->InterruptZ.bf.SFI41_TXPTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.SFI41_TXPTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.SFI41_RXPTRSLIPiZ", tmp_hsif_prot->InterruptZ.bf.SFI41_RXPTRSLIPiZ, tmp_hsif_prot->InterruptZ.bf.SFI41_RXPTRSLIPiZ == dft_hsif_prot->InterruptZ.bf.SFI41_RXPTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.SFI41_RXPTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.PSELST_INTiZ", tmp_hsif_prot->InterruptZ.bf.PSELST_INTiZ, tmp_hsif_prot->InterruptZ.bf.PSELST_INTiZ == dft_hsif_prot->InterruptZ.bf.PSELST_INTiZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.PSELST_INTiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.LBELST_INTiZ", tmp_hsif_prot->InterruptZ.bf.LBELST_INTiZ, tmp_hsif_prot->InterruptZ.bf.LBELST_INTiZ == dft_hsif_prot->InterruptZ.bf.LBELST_INTiZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.LBELST_INTiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.SFI42iZ", tmp_hsif_prot->InterruptZ.bf.SFI42iZ, tmp_hsif_prot->InterruptZ.bf.SFI42iZ == dft_hsif_prot->InterruptZ.bf.SFI42iZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.SFI42iZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.SFI5iZ", tmp_hsif_prot->InterruptZ.bf.SFI5iZ, tmp_hsif_prot->InterruptZ.bf.SFI5iZ == dft_hsif_prot->InterruptZ.bf.SFI5iZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.SFI5iZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.MR_SLC3iZ", tmp_hsif_prot->InterruptZ.bf.MR_SLC3iZ, tmp_hsif_prot->InterruptZ.bf.MR_SLC3iZ == dft_hsif_prot->InterruptZ.bf.MR_SLC3iZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.MR_SLC3iZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.MR_SLC2iZ", tmp_hsif_prot->InterruptZ.bf.MR_SLC2iZ, tmp_hsif_prot->InterruptZ.bf.MR_SLC2iZ == dft_hsif_prot->InterruptZ.bf.MR_SLC2iZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.MR_SLC2iZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.MR_SLC1iZ", tmp_hsif_prot->InterruptZ.bf.MR_SLC1iZ, tmp_hsif_prot->InterruptZ.bf.MR_SLC1iZ == dft_hsif_prot->InterruptZ.bf.MR_SLC1iZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.MR_SLC1iZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTERRUPTZ.bf.MR_SLC0iZ", tmp_hsif_prot->InterruptZ.bf.MR_SLC0iZ, tmp_hsif_prot->InterruptZ.bf.MR_SLC0iZ == dft_hsif_prot->InterruptZ.bf.MR_SLC0iZ ? 0x20 : 0x2A, dft_hsif_prot->InterruptZ.bf.MR_SLC0iZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INT.wrd", tmp_hsif_prot->LBELST_INT.wrd, tmp_hsif_prot->LBELST_INT.wrd == dft_hsif_prot->LBELST_INT.wrd ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INT.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INT.bf.TXRXLB3_PTRSLIPi", tmp_hsif_prot->LBELST_INT.bf.TXRXLB3_PTRSLIPi, tmp_hsif_prot->LBELST_INT.bf.TXRXLB3_PTRSLIPi == dft_hsif_prot->LBELST_INT.bf.TXRXLB3_PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INT.bf.TXRXLB3_PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INT.bf.TXRXLB2_PTRSLIPi", tmp_hsif_prot->LBELST_INT.bf.TXRXLB2_PTRSLIPi, tmp_hsif_prot->LBELST_INT.bf.TXRXLB2_PTRSLIPi == dft_hsif_prot->LBELST_INT.bf.TXRXLB2_PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INT.bf.TXRXLB2_PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INT.bf.TXRXLB1_PTRSLIPi", tmp_hsif_prot->LBELST_INT.bf.TXRXLB1_PTRSLIPi, tmp_hsif_prot->LBELST_INT.bf.TXRXLB1_PTRSLIPi == dft_hsif_prot->LBELST_INT.bf.TXRXLB1_PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INT.bf.TXRXLB1_PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INT.bf.TXRXLB0_PTRSLIPi", tmp_hsif_prot->LBELST_INT.bf.TXRXLB0_PTRSLIPi, tmp_hsif_prot->LBELST_INT.bf.TXRXLB0_PTRSLIPi == dft_hsif_prot->LBELST_INT.bf.TXRXLB0_PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INT.bf.TXRXLB0_PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INT.bf.RXTXLB3_PTRSLIPi", tmp_hsif_prot->LBELST_INT.bf.RXTXLB3_PTRSLIPi, tmp_hsif_prot->LBELST_INT.bf.RXTXLB3_PTRSLIPi == dft_hsif_prot->LBELST_INT.bf.RXTXLB3_PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INT.bf.RXTXLB3_PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INT.bf.RXTXLB2_PTRSLIPi", tmp_hsif_prot->LBELST_INT.bf.RXTXLB2_PTRSLIPi, tmp_hsif_prot->LBELST_INT.bf.RXTXLB2_PTRSLIPi == dft_hsif_prot->LBELST_INT.bf.RXTXLB2_PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INT.bf.RXTXLB2_PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INT.bf.RXTXLB1_PTRSLIPi", tmp_hsif_prot->LBELST_INT.bf.RXTXLB1_PTRSLIPi, tmp_hsif_prot->LBELST_INT.bf.RXTXLB1_PTRSLIPi == dft_hsif_prot->LBELST_INT.bf.RXTXLB1_PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INT.bf.RXTXLB1_PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INT.bf.RXTXLB0_PTRSLIPi", tmp_hsif_prot->LBELST_INT.bf.RXTXLB0_PTRSLIPi, tmp_hsif_prot->LBELST_INT.bf.RXTXLB0_PTRSLIPi == dft_hsif_prot->LBELST_INT.bf.RXTXLB0_PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INT.bf.RXTXLB0_PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTEN.wrd", tmp_hsif_prot->LBELST_INTEN.wrd, tmp_hsif_prot->LBELST_INTEN.wrd == dft_hsif_prot->LBELST_INTEN.wrd ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTEN.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTEN.bf.TXRXLB3_PTRSLIPe", tmp_hsif_prot->LBELST_INTEN.bf.TXRXLB3_PTRSLIPe, tmp_hsif_prot->LBELST_INTEN.bf.TXRXLB3_PTRSLIPe == dft_hsif_prot->LBELST_INTEN.bf.TXRXLB3_PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTEN.bf.TXRXLB3_PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTEN.bf.TXRXLB2_PTRSLIPe", tmp_hsif_prot->LBELST_INTEN.bf.TXRXLB2_PTRSLIPe, tmp_hsif_prot->LBELST_INTEN.bf.TXRXLB2_PTRSLIPe == dft_hsif_prot->LBELST_INTEN.bf.TXRXLB2_PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTEN.bf.TXRXLB2_PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTEN.bf.TXRXLB1_PTRSLIPe", tmp_hsif_prot->LBELST_INTEN.bf.TXRXLB1_PTRSLIPe, tmp_hsif_prot->LBELST_INTEN.bf.TXRXLB1_PTRSLIPe == dft_hsif_prot->LBELST_INTEN.bf.TXRXLB1_PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTEN.bf.TXRXLB1_PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTEN.bf.TXRXLB0_PTRSLIPe", tmp_hsif_prot->LBELST_INTEN.bf.TXRXLB0_PTRSLIPe, tmp_hsif_prot->LBELST_INTEN.bf.TXRXLB0_PTRSLIPe == dft_hsif_prot->LBELST_INTEN.bf.TXRXLB0_PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTEN.bf.TXRXLB0_PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTEN.bf.RXTXLB3_PTRSLIPe", tmp_hsif_prot->LBELST_INTEN.bf.RXTXLB3_PTRSLIPe, tmp_hsif_prot->LBELST_INTEN.bf.RXTXLB3_PTRSLIPe == dft_hsif_prot->LBELST_INTEN.bf.RXTXLB3_PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTEN.bf.RXTXLB3_PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTEN.bf.RXTXLB2_PTRSLIPe", tmp_hsif_prot->LBELST_INTEN.bf.RXTXLB2_PTRSLIPe, tmp_hsif_prot->LBELST_INTEN.bf.RXTXLB2_PTRSLIPe == dft_hsif_prot->LBELST_INTEN.bf.RXTXLB2_PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTEN.bf.RXTXLB2_PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTEN.bf.RXTXLB1_PTRSLIPe", tmp_hsif_prot->LBELST_INTEN.bf.RXTXLB1_PTRSLIPe, tmp_hsif_prot->LBELST_INTEN.bf.RXTXLB1_PTRSLIPe == dft_hsif_prot->LBELST_INTEN.bf.RXTXLB1_PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTEN.bf.RXTXLB1_PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTEN.bf.RXTXLB0_PTRSLIPe", tmp_hsif_prot->LBELST_INTEN.bf.RXTXLB0_PTRSLIPe, tmp_hsif_prot->LBELST_INTEN.bf.RXTXLB0_PTRSLIPe == dft_hsif_prot->LBELST_INTEN.bf.RXTXLB0_PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTEN.bf.RXTXLB0_PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTZ.wrd", tmp_hsif_prot->LBELST_INTZ.wrd, tmp_hsif_prot->LBELST_INTZ.wrd == dft_hsif_prot->LBELST_INTZ.wrd ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTZ.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTZ.bf.TXRXLB3_PTRSLIPiZ", tmp_hsif_prot->LBELST_INTZ.bf.TXRXLB3_PTRSLIPiZ, tmp_hsif_prot->LBELST_INTZ.bf.TXRXLB3_PTRSLIPiZ == dft_hsif_prot->LBELST_INTZ.bf.TXRXLB3_PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTZ.bf.TXRXLB3_PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTZ.bf.TXRXLB2_PTRSLIPiZ", tmp_hsif_prot->LBELST_INTZ.bf.TXRXLB2_PTRSLIPiZ, tmp_hsif_prot->LBELST_INTZ.bf.TXRXLB2_PTRSLIPiZ == dft_hsif_prot->LBELST_INTZ.bf.TXRXLB2_PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTZ.bf.TXRXLB2_PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTZ.bf.TXRXLB1_PTRSLIPiZ", tmp_hsif_prot->LBELST_INTZ.bf.TXRXLB1_PTRSLIPiZ, tmp_hsif_prot->LBELST_INTZ.bf.TXRXLB1_PTRSLIPiZ == dft_hsif_prot->LBELST_INTZ.bf.TXRXLB1_PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTZ.bf.TXRXLB1_PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTZ.bf.TXRXLB0_PTRSLIPiZ", tmp_hsif_prot->LBELST_INTZ.bf.TXRXLB0_PTRSLIPiZ, tmp_hsif_prot->LBELST_INTZ.bf.TXRXLB0_PTRSLIPiZ == dft_hsif_prot->LBELST_INTZ.bf.TXRXLB0_PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTZ.bf.TXRXLB0_PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTZ.bf.RXTXLB3_PTRSLIPiZ", tmp_hsif_prot->LBELST_INTZ.bf.RXTXLB3_PTRSLIPiZ, tmp_hsif_prot->LBELST_INTZ.bf.RXTXLB3_PTRSLIPiZ == dft_hsif_prot->LBELST_INTZ.bf.RXTXLB3_PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTZ.bf.RXTXLB3_PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTZ.bf.RXTXLB2_PTRSLIPiZ", tmp_hsif_prot->LBELST_INTZ.bf.RXTXLB2_PTRSLIPiZ, tmp_hsif_prot->LBELST_INTZ.bf.RXTXLB2_PTRSLIPiZ == dft_hsif_prot->LBELST_INTZ.bf.RXTXLB2_PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTZ.bf.RXTXLB2_PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTZ.bf.RXTXLB1_PTRSLIPiZ", tmp_hsif_prot->LBELST_INTZ.bf.RXTXLB1_PTRSLIPiZ, tmp_hsif_prot->LBELST_INTZ.bf.RXTXLB1_PTRSLIPiZ == dft_hsif_prot->LBELST_INTZ.bf.RXTXLB1_PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTZ.bf.RXTXLB1_PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LBELST_INTZ.bf.RXTXLB0_PTRSLIPiZ", tmp_hsif_prot->LBELST_INTZ.bf.RXTXLB0_PTRSLIPiZ, tmp_hsif_prot->LBELST_INTZ.bf.RXTXLB0_PTRSLIPiZ == dft_hsif_prot->LBELST_INTZ.bf.RXTXLB0_PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->LBELST_INTZ.bf.RXTXLB0_PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INT.wrd", tmp_hsif_prot->PSELST_INT.wrd, tmp_hsif_prot->PSELST_INT.wrd == dft_hsif_prot->PSELST_INT.wrd ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INT.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INT.bf.TX3PTRSLIPi", tmp_hsif_prot->PSELST_INT.bf.TX3PTRSLIPi, tmp_hsif_prot->PSELST_INT.bf.TX3PTRSLIPi == dft_hsif_prot->PSELST_INT.bf.TX3PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INT.bf.TX3PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INT.bf.TX2PTRSLIPi", tmp_hsif_prot->PSELST_INT.bf.TX2PTRSLIPi, tmp_hsif_prot->PSELST_INT.bf.TX2PTRSLIPi == dft_hsif_prot->PSELST_INT.bf.TX2PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INT.bf.TX2PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INT.bf.TX1PTRSLIPi", tmp_hsif_prot->PSELST_INT.bf.TX1PTRSLIPi, tmp_hsif_prot->PSELST_INT.bf.TX1PTRSLIPi == dft_hsif_prot->PSELST_INT.bf.TX1PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INT.bf.TX1PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INT.bf.TX0PTRSLIPi", tmp_hsif_prot->PSELST_INT.bf.TX0PTRSLIPi, tmp_hsif_prot->PSELST_INT.bf.TX0PTRSLIPi == dft_hsif_prot->PSELST_INT.bf.TX0PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INT.bf.TX0PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INT.bf.RX3PTRSLIPi", tmp_hsif_prot->PSELST_INT.bf.RX3PTRSLIPi, tmp_hsif_prot->PSELST_INT.bf.RX3PTRSLIPi == dft_hsif_prot->PSELST_INT.bf.RX3PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INT.bf.RX3PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INT.bf.RX2PTRSLIPi", tmp_hsif_prot->PSELST_INT.bf.RX2PTRSLIPi, tmp_hsif_prot->PSELST_INT.bf.RX2PTRSLIPi == dft_hsif_prot->PSELST_INT.bf.RX2PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INT.bf.RX2PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INT.bf.RX1PTRSLIPi", tmp_hsif_prot->PSELST_INT.bf.RX1PTRSLIPi, tmp_hsif_prot->PSELST_INT.bf.RX1PTRSLIPi == dft_hsif_prot->PSELST_INT.bf.RX1PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INT.bf.RX1PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INT.bf.RX0PTRSLIPi", tmp_hsif_prot->PSELST_INT.bf.RX0PTRSLIPi, tmp_hsif_prot->PSELST_INT.bf.RX0PTRSLIPi == dft_hsif_prot->PSELST_INT.bf.RX0PTRSLIPi ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INT.bf.RX0PTRSLIPi, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTEN.wrd", tmp_hsif_prot->PSELST_INTEN.wrd, tmp_hsif_prot->PSELST_INTEN.wrd == dft_hsif_prot->PSELST_INTEN.wrd ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTEN.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTEN.bf.TX3PTRSLIPe", tmp_hsif_prot->PSELST_INTEN.bf.TX3PTRSLIPe, tmp_hsif_prot->PSELST_INTEN.bf.TX3PTRSLIPe == dft_hsif_prot->PSELST_INTEN.bf.TX3PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTEN.bf.TX3PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTEN.bf.TX2PTRSLIPe", tmp_hsif_prot->PSELST_INTEN.bf.TX2PTRSLIPe, tmp_hsif_prot->PSELST_INTEN.bf.TX2PTRSLIPe == dft_hsif_prot->PSELST_INTEN.bf.TX2PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTEN.bf.TX2PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTEN.bf.TX1PTRSLIPe", tmp_hsif_prot->PSELST_INTEN.bf.TX1PTRSLIPe, tmp_hsif_prot->PSELST_INTEN.bf.TX1PTRSLIPe == dft_hsif_prot->PSELST_INTEN.bf.TX1PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTEN.bf.TX1PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTEN.bf.TX0PTRSLIPe", tmp_hsif_prot->PSELST_INTEN.bf.TX0PTRSLIPe, tmp_hsif_prot->PSELST_INTEN.bf.TX0PTRSLIPe == dft_hsif_prot->PSELST_INTEN.bf.TX0PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTEN.bf.TX0PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTEN.bf.RX3PTRSLIPe", tmp_hsif_prot->PSELST_INTEN.bf.RX3PTRSLIPe, tmp_hsif_prot->PSELST_INTEN.bf.RX3PTRSLIPe == dft_hsif_prot->PSELST_INTEN.bf.RX3PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTEN.bf.RX3PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTEN.bf.RX2PTRSLIPe", tmp_hsif_prot->PSELST_INTEN.bf.RX2PTRSLIPe, tmp_hsif_prot->PSELST_INTEN.bf.RX2PTRSLIPe == dft_hsif_prot->PSELST_INTEN.bf.RX2PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTEN.bf.RX2PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTEN.bf.RX1PTRSLIPe", tmp_hsif_prot->PSELST_INTEN.bf.RX1PTRSLIPe, tmp_hsif_prot->PSELST_INTEN.bf.RX1PTRSLIPe == dft_hsif_prot->PSELST_INTEN.bf.RX1PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTEN.bf.RX1PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTEN.bf.RX0PTRSLIPe", tmp_hsif_prot->PSELST_INTEN.bf.RX0PTRSLIPe, tmp_hsif_prot->PSELST_INTEN.bf.RX0PTRSLIPe == dft_hsif_prot->PSELST_INTEN.bf.RX0PTRSLIPe ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTEN.bf.RX0PTRSLIPe, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTZ.wrd", tmp_hsif_prot->PSELST_INTZ.wrd, tmp_hsif_prot->PSELST_INTZ.wrd == dft_hsif_prot->PSELST_INTZ.wrd ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTZ.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTZ.bf.TX3PTRSLIPiZ", tmp_hsif_prot->PSELST_INTZ.bf.TX3PTRSLIPiZ, tmp_hsif_prot->PSELST_INTZ.bf.TX3PTRSLIPiZ == dft_hsif_prot->PSELST_INTZ.bf.TX3PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTZ.bf.TX3PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTZ.bf.TX2PTRSLIPiZ", tmp_hsif_prot->PSELST_INTZ.bf.TX2PTRSLIPiZ, tmp_hsif_prot->PSELST_INTZ.bf.TX2PTRSLIPiZ == dft_hsif_prot->PSELST_INTZ.bf.TX2PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTZ.bf.TX2PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTZ.bf.TX1PTRSLIPiZ", tmp_hsif_prot->PSELST_INTZ.bf.TX1PTRSLIPiZ, tmp_hsif_prot->PSELST_INTZ.bf.TX1PTRSLIPiZ == dft_hsif_prot->PSELST_INTZ.bf.TX1PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTZ.bf.TX1PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTZ.bf.TX0PTRSLIPiZ", tmp_hsif_prot->PSELST_INTZ.bf.TX0PTRSLIPiZ, tmp_hsif_prot->PSELST_INTZ.bf.TX0PTRSLIPiZ == dft_hsif_prot->PSELST_INTZ.bf.TX0PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTZ.bf.TX0PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTZ.bf.RX3PTRSLIPiZ", tmp_hsif_prot->PSELST_INTZ.bf.RX3PTRSLIPiZ, tmp_hsif_prot->PSELST_INTZ.bf.RX3PTRSLIPiZ == dft_hsif_prot->PSELST_INTZ.bf.RX3PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTZ.bf.RX3PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTZ.bf.RX2PTRSLIPiZ", tmp_hsif_prot->PSELST_INTZ.bf.RX2PTRSLIPiZ, tmp_hsif_prot->PSELST_INTZ.bf.RX2PTRSLIPiZ == dft_hsif_prot->PSELST_INTZ.bf.RX2PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTZ.bf.RX2PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTZ.bf.RX1PTRSLIPiZ", tmp_hsif_prot->PSELST_INTZ.bf.RX1PTRSLIPiZ, tmp_hsif_prot->PSELST_INTZ.bf.RX1PTRSLIPiZ == dft_hsif_prot->PSELST_INTZ.bf.RX1PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTZ.bf.RX1PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSELST_INTZ.bf.RX0PTRSLIPiZ", tmp_hsif_prot->PSELST_INTZ.bf.RX0PTRSLIPiZ, tmp_hsif_prot->PSELST_INTZ.bf.RX0PTRSLIPiZ == dft_hsif_prot->PSELST_INTZ.bf.RX0PTRSLIPiZ ? 0x20 : 0x2A, dft_hsif_prot->PSELST_INTZ.bf.RX0PTRSLIPiZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SLICERESET.wrd", tmp_hsif_prot->SliceReset.wrd, tmp_hsif_prot->SliceReset.wrd == dft_hsif_prot->SliceReset.wrd ? 0x20 : 0x2A, dft_hsif_prot->SliceReset.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SLICERESET.bf.rx3", tmp_hsif_prot->SliceReset.bf.rx3, tmp_hsif_prot->SliceReset.bf.rx3 == dft_hsif_prot->SliceReset.bf.rx3 ? 0x20 : 0x2A, dft_hsif_prot->SliceReset.bf.rx3, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SLICERESET.bf.rx2", tmp_hsif_prot->SliceReset.bf.rx2, tmp_hsif_prot->SliceReset.bf.rx2 == dft_hsif_prot->SliceReset.bf.rx2 ? 0x20 : 0x2A, dft_hsif_prot->SliceReset.bf.rx2, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SLICERESET.bf.rx1", tmp_hsif_prot->SliceReset.bf.rx1, tmp_hsif_prot->SliceReset.bf.rx1 == dft_hsif_prot->SliceReset.bf.rx1 ? 0x20 : 0x2A, dft_hsif_prot->SliceReset.bf.rx1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SLICERESET.bf.rx0", tmp_hsif_prot->SliceReset.bf.rx0, tmp_hsif_prot->SliceReset.bf.rx0 == dft_hsif_prot->SliceReset.bf.rx0 ? 0x20 : 0x2A, dft_hsif_prot->SliceReset.bf.rx0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SLICERESET.bf.tx3", tmp_hsif_prot->SliceReset.bf.tx3, tmp_hsif_prot->SliceReset.bf.tx3 == dft_hsif_prot->SliceReset.bf.tx3 ? 0x20 : 0x2A, dft_hsif_prot->SliceReset.bf.tx3, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SLICERESET.bf.tx2", tmp_hsif_prot->SliceReset.bf.tx2, tmp_hsif_prot->SliceReset.bf.tx2 == dft_hsif_prot->SliceReset.bf.tx2 ? 0x20 : 0x2A, dft_hsif_prot->SliceReset.bf.tx2, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SLICERESET.bf.tx1", tmp_hsif_prot->SliceReset.bf.tx1, tmp_hsif_prot->SliceReset.bf.tx1 == dft_hsif_prot->SliceReset.bf.tx1 ? 0x20 : 0x2A, dft_hsif_prot->SliceReset.bf.tx1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_SLICERESET.bf.tx0", tmp_hsif_prot->SliceReset.bf.tx0, tmp_hsif_prot->SliceReset.bf.tx0 == dft_hsif_prot->SliceReset.bf.tx0 ? 0x20 : 0x2A, dft_hsif_prot->SliceReset.bf.tx0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTSTATUS.wrd", tmp_hsif_prot->Intstatus.wrd, tmp_hsif_prot->Intstatus.wrd == dft_hsif_prot->Intstatus.wrd ? 0x20 : 0x2A, dft_hsif_prot->Intstatus.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTSTATUS.bf.SFI41_TXCLKLOSSs", tmp_hsif_prot->Intstatus.bf.SFI41_TXCLKLOSSs, tmp_hsif_prot->Intstatus.bf.SFI41_TXCLKLOSSs == dft_hsif_prot->Intstatus.bf.SFI41_TXCLKLOSSs ? 0x20 : 0x2A, dft_hsif_prot->Intstatus.bf.SFI41_TXCLKLOSSs, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_INTSTATUS.bf.SFI41_RXCLKLOSSs", tmp_hsif_prot->Intstatus.bf.SFI41_RXCLKLOSSs, tmp_hsif_prot->Intstatus.bf.SFI41_RXCLKLOSSs == dft_hsif_prot->Intstatus.bf.SFI41_RXCLKLOSSs ? 0x20 : 0x2A, dft_hsif_prot->Intstatus.bf.SFI41_RXCLKLOSSs, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_XFI_LANESWAP.wrd", tmp_hsif_prot->XFI_LANESWAP.wrd, tmp_hsif_prot->XFI_LANESWAP.wrd == dft_hsif_prot->XFI_LANESWAP.wrd ? 0x20 : 0x2A, dft_hsif_prot->XFI_LANESWAP.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_XFI_LANESWAP.bf.rx3", tmp_hsif_prot->XFI_LANESWAP.bf.rx3, tmp_hsif_prot->XFI_LANESWAP.bf.rx3 == dft_hsif_prot->XFI_LANESWAP.bf.rx3 ? 0x20 : 0x2A, dft_hsif_prot->XFI_LANESWAP.bf.rx3, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_XFI_LANESWAP.bf.rx2", tmp_hsif_prot->XFI_LANESWAP.bf.rx2, tmp_hsif_prot->XFI_LANESWAP.bf.rx2 == dft_hsif_prot->XFI_LANESWAP.bf.rx2 ? 0x20 : 0x2A, dft_hsif_prot->XFI_LANESWAP.bf.rx2, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_XFI_LANESWAP.bf.rx1", tmp_hsif_prot->XFI_LANESWAP.bf.rx1, tmp_hsif_prot->XFI_LANESWAP.bf.rx1 == dft_hsif_prot->XFI_LANESWAP.bf.rx1 ? 0x20 : 0x2A, dft_hsif_prot->XFI_LANESWAP.bf.rx1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_XFI_LANESWAP.bf.rx0", tmp_hsif_prot->XFI_LANESWAP.bf.rx0, tmp_hsif_prot->XFI_LANESWAP.bf.rx0 == dft_hsif_prot->XFI_LANESWAP.bf.rx0 ? 0x20 : 0x2A, dft_hsif_prot->XFI_LANESWAP.bf.rx0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_XFI_LANESWAP.bf.tx3", tmp_hsif_prot->XFI_LANESWAP.bf.tx3, tmp_hsif_prot->XFI_LANESWAP.bf.tx3 == dft_hsif_prot->XFI_LANESWAP.bf.tx3 ? 0x20 : 0x2A, dft_hsif_prot->XFI_LANESWAP.bf.tx3, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_XFI_LANESWAP.bf.tx2", tmp_hsif_prot->XFI_LANESWAP.bf.tx2, tmp_hsif_prot->XFI_LANESWAP.bf.tx2 == dft_hsif_prot->XFI_LANESWAP.bf.tx2 ? 0x20 : 0x2A, dft_hsif_prot->XFI_LANESWAP.bf.tx2, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_XFI_LANESWAP.bf.tx1", tmp_hsif_prot->XFI_LANESWAP.bf.tx1, tmp_hsif_prot->XFI_LANESWAP.bf.tx1 == dft_hsif_prot->XFI_LANESWAP.bf.tx1 ? 0x20 : 0x2A, dft_hsif_prot->XFI_LANESWAP.bf.tx1, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_XFI_LANESWAP.bf.tx0", tmp_hsif_prot->XFI_LANESWAP.bf.tx0, tmp_hsif_prot->XFI_LANESWAP.bf.tx0 == dft_hsif_prot->XFI_LANESWAP.bf.tx0 ? 0x20 : 0x2A, dft_hsif_prot->XFI_LANESWAP.bf.tx0, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_MISC.wrd", tmp_hsif_prot->MISC.wrd, tmp_hsif_prot->MISC.wrd == dft_hsif_prot->MISC.wrd ? 0x20 : 0x2A, dft_hsif_prot->MISC.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_MISC.bf.xlos_pswtchen", tmp_hsif_prot->MISC.bf.xlos_pswtchen, tmp_hsif_prot->MISC.bf.xlos_pswtchen == dft_hsif_prot->MISC.bf.xlos_pswtchen ? 0x20 : 0x2A, dft_hsif_prot->MISC.bf.xlos_pswtchen, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_MISC.bf.hw_pswtchen", tmp_hsif_prot->MISC.bf.hw_pswtchen, tmp_hsif_prot->MISC.bf.hw_pswtchen == dft_hsif_prot->MISC.bf.hw_pswtchen ? 0x20 : 0x2A, dft_hsif_prot->MISC.bf.hw_pswtchen, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_MISC.bf.SINT_SEL", tmp_hsif_prot->MISC.bf.SINT_SEL, tmp_hsif_prot->MISC.bf.SINT_SEL == dft_hsif_prot->MISC.bf.SINT_SEL ? 0x20 : 0x2A, dft_hsif_prot->MISC.bf.SINT_SEL, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_MISC.bf.xfi_sync_mode", tmp_hsif_prot->MISC.bf.xfi_sync_mode, tmp_hsif_prot->MISC.bf.xfi_sync_mode == dft_hsif_prot->MISC.bf.xfi_sync_mode ? 0x20 : 0x2A, dft_hsif_prot->MISC.bf.xfi_sync_mode, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_MISC.bf.xfi_XLOS_broadcast", tmp_hsif_prot->MISC.bf.xfi_XLOS_broadcast, tmp_hsif_prot->MISC.bf.xfi_XLOS_broadcast == dft_hsif_prot->MISC.bf.xfi_XLOS_broadcast ? 0x20 : 0x2A, dft_hsif_prot->MISC.bf.xfi_XLOS_broadcast, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE0ERRCNT.wrd", tmp_hsif_prot->Lane0ErrCnt.wrd, tmp_hsif_prot->Lane0ErrCnt.wrd == dft_hsif_prot->Lane0ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane0ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE0ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane0ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane0ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane0ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane0ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE1ERRCNT.wrd", tmp_hsif_prot->Lane1ErrCnt.wrd, tmp_hsif_prot->Lane1ErrCnt.wrd == dft_hsif_prot->Lane1ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane1ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE1ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane1ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane1ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane1ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane1ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE2ERRCNT.wrd", tmp_hsif_prot->Lane2ErrCnt.wrd, tmp_hsif_prot->Lane2ErrCnt.wrd == dft_hsif_prot->Lane2ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane2ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE2ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane2ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane2ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane2ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane2ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE3ERRCNT.wrd", tmp_hsif_prot->Lane3ErrCnt.wrd, tmp_hsif_prot->Lane3ErrCnt.wrd == dft_hsif_prot->Lane3ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane3ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE3ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane3ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane3ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane3ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane3ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE4ERRCNT.wrd", tmp_hsif_prot->Lane4ErrCnt.wrd, tmp_hsif_prot->Lane4ErrCnt.wrd == dft_hsif_prot->Lane4ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane4ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE4ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane4ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane4ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane4ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane4ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE5ERRCNT.wrd", tmp_hsif_prot->Lane5ErrCnt.wrd, tmp_hsif_prot->Lane5ErrCnt.wrd == dft_hsif_prot->Lane5ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane5ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE5ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane5ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane5ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane5ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane5ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE6ERRCNT.wrd", tmp_hsif_prot->Lane6ErrCnt.wrd, tmp_hsif_prot->Lane6ErrCnt.wrd == dft_hsif_prot->Lane6ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane6ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE6ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane6ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane6ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane6ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane6ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE7ERRCNT.wrd", tmp_hsif_prot->Lane7ErrCnt.wrd, tmp_hsif_prot->Lane7ErrCnt.wrd == dft_hsif_prot->Lane7ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane7ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE7ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane7ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane7ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane7ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane7ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE8ERRCNT.wrd", tmp_hsif_prot->Lane8ErrCnt.wrd, tmp_hsif_prot->Lane8ErrCnt.wrd == dft_hsif_prot->Lane8ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane8ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE8ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane8ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane8ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane8ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane8ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE9ERRCNT.wrd", tmp_hsif_prot->Lane9ErrCnt.wrd, tmp_hsif_prot->Lane9ErrCnt.wrd == dft_hsif_prot->Lane9ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane9ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE9ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane9ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane9ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane9ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane9ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE10ERRCNT.wrd", tmp_hsif_prot->Lane10ErrCnt.wrd, tmp_hsif_prot->Lane10ErrCnt.wrd == dft_hsif_prot->Lane10ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane10ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE10ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane10ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane10ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane10ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane10ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE11ERRCNT.wrd", tmp_hsif_prot->Lane11ErrCnt.wrd, tmp_hsif_prot->Lane11ErrCnt.wrd == dft_hsif_prot->Lane11ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane11ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE11ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane11ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane11ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane11ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane11ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE12ERRCNT.wrd", tmp_hsif_prot->Lane12ErrCnt.wrd, tmp_hsif_prot->Lane12ErrCnt.wrd == dft_hsif_prot->Lane12ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane12ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE12ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane12ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane12ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane12ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane12ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE13ERRCNT.wrd", tmp_hsif_prot->Lane13ErrCnt.wrd, tmp_hsif_prot->Lane13ErrCnt.wrd == dft_hsif_prot->Lane13ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane13ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE13ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane13ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane13ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane13ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane13ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE14ERRCNT.wrd", tmp_hsif_prot->Lane14ErrCnt.wrd, tmp_hsif_prot->Lane14ErrCnt.wrd == dft_hsif_prot->Lane14ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane14ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE14ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane14ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane14ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane14ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane14ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE15ERRCNT.wrd", tmp_hsif_prot->Lane15ErrCnt.wrd, tmp_hsif_prot->Lane15ErrCnt.wrd == dft_hsif_prot->Lane15ErrCnt.wrd ? 0x20 : 0x2A, dft_hsif_prot->Lane15ErrCnt.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_LANE15ERRCNT.bf.ErrCnt", tmp_hsif_prot->Lane15ErrCnt.bf.ErrCnt, tmp_hsif_prot->Lane15ErrCnt.bf.ErrCnt == dft_hsif_prot->Lane15ErrCnt.bf.ErrCnt ? 0x20 : 0x2A, dft_hsif_prot->Lane15ErrCnt.bf.ErrCnt, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INT.wrd", tmp_hsif_prot->PSWITCH_MUX_INT.wrd, tmp_hsif_prot->PSWITCH_MUX_INT.wrd == dft_hsif_prot->PSWITCH_MUX_INT.wrd ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INT.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INT.bf.RX3i", tmp_hsif_prot->PSWITCH_MUX_INT.bf.RX3i, tmp_hsif_prot->PSWITCH_MUX_INT.bf.RX3i == dft_hsif_prot->PSWITCH_MUX_INT.bf.RX3i ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INT.bf.RX3i, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INT.bf.RX2i", tmp_hsif_prot->PSWITCH_MUX_INT.bf.RX2i, tmp_hsif_prot->PSWITCH_MUX_INT.bf.RX2i == dft_hsif_prot->PSWITCH_MUX_INT.bf.RX2i ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INT.bf.RX2i, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INT.bf.RX1i", tmp_hsif_prot->PSWITCH_MUX_INT.bf.RX1i, tmp_hsif_prot->PSWITCH_MUX_INT.bf.RX1i == dft_hsif_prot->PSWITCH_MUX_INT.bf.RX1i ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INT.bf.RX1i, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INT.bf.RX0i", tmp_hsif_prot->PSWITCH_MUX_INT.bf.RX0i, tmp_hsif_prot->PSWITCH_MUX_INT.bf.RX0i == dft_hsif_prot->PSWITCH_MUX_INT.bf.RX0i ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INT.bf.RX0i, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTSTATUS.wrd", tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.wrd, tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.wrd == dft_hsif_prot->PSWITCH_MUX_INTSTATUS.wrd ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTSTATUS.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTSTATUS.bf.RX3s", tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX3s, tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX3s == dft_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX3s ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX3s, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTSTATUS.bf.RX2s", tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX2s, tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX2s == dft_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX2s ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX2s, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTSTATUS.bf.RX1s", tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX1s, tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX1s == dft_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX1s ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX1s, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTSTATUS.bf.RX0s", tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX0s, tmp_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX0s == dft_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX0s ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTSTATUS.bf.RX0s, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTEN.wrd", tmp_hsif_prot->PSWITCH_MUX_INTEN.wrd, tmp_hsif_prot->PSWITCH_MUX_INTEN.wrd == dft_hsif_prot->PSWITCH_MUX_INTEN.wrd ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTEN.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTEN.bf.RX3e", tmp_hsif_prot->PSWITCH_MUX_INTEN.bf.RX3e, tmp_hsif_prot->PSWITCH_MUX_INTEN.bf.RX3e == dft_hsif_prot->PSWITCH_MUX_INTEN.bf.RX3e ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTEN.bf.RX3e, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTEN.bf.RX2e", tmp_hsif_prot->PSWITCH_MUX_INTEN.bf.RX2e, tmp_hsif_prot->PSWITCH_MUX_INTEN.bf.RX2e == dft_hsif_prot->PSWITCH_MUX_INTEN.bf.RX2e ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTEN.bf.RX2e, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTEN.bf.RX1e", tmp_hsif_prot->PSWITCH_MUX_INTEN.bf.RX1e, tmp_hsif_prot->PSWITCH_MUX_INTEN.bf.RX1e == dft_hsif_prot->PSWITCH_MUX_INTEN.bf.RX1e ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTEN.bf.RX1e, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTEN.bf.RX0e", tmp_hsif_prot->PSWITCH_MUX_INTEN.bf.RX0e, tmp_hsif_prot->PSWITCH_MUX_INTEN.bf.RX0e == dft_hsif_prot->PSWITCH_MUX_INTEN.bf.RX0e ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTEN.bf.RX0e, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTZ.wrd", tmp_hsif_prot->PSWITCH_MUX_INTZ.wrd, tmp_hsif_prot->PSWITCH_MUX_INTZ.wrd == dft_hsif_prot->PSWITCH_MUX_INTZ.wrd ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTZ.wrd, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTZ.bf.RX3iZ", tmp_hsif_prot->PSWITCH_MUX_INTZ.bf.RX3iZ, tmp_hsif_prot->PSWITCH_MUX_INTZ.bf.RX3iZ == dft_hsif_prot->PSWITCH_MUX_INTZ.bf.RX3iZ ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTZ.bf.RX3iZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTZ.bf.RX2iZ", tmp_hsif_prot->PSWITCH_MUX_INTZ.bf.RX2iZ, tmp_hsif_prot->PSWITCH_MUX_INTZ.bf.RX2iZ == dft_hsif_prot->PSWITCH_MUX_INTZ.bf.RX2iZ ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTZ.bf.RX2iZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTZ.bf.RX1iZ", tmp_hsif_prot->PSWITCH_MUX_INTZ.bf.RX1iZ, tmp_hsif_prot->PSWITCH_MUX_INTZ.bf.RX1iZ == dft_hsif_prot->PSWITCH_MUX_INTZ.bf.RX1iZ ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTZ.bf.RX1iZ, ch1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c\n", "HSIF_PROTOCOL_PSWITCH_MUX_INTZ.bf.RX0iZ", tmp_hsif_prot->PSWITCH_MUX_INTZ.bf.RX0iZ, tmp_hsif_prot->PSWITCH_MUX_INTZ.bf.RX0iZ == dft_hsif_prot->PSWITCH_MUX_INTZ.bf.RX0iZ ? 0x20 : 0x2A, dft_hsif_prot->PSWITCH_MUX_INTZ.bf.RX0iZ, ch1);

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  CS_FREE(tmp_hsif_prot);
  CS_FREE(dft_hsif_prot);
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  
  return (CS_OK);
}

