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
 * ten_debug_cfp.c
 *
 * APIs for debugging cfp
 *
 * $Id: ten_debug_cfp.c,v 1.8 2013/03/05 16:11:52 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  CFP DUMP SETTINGS                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_cfp_dump_settings(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current CFP settings.                                   */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  TEN_cfp32x1_sds_t *tmp_cfp, *dft_cfp;
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
     
  tmp_cfp = (TEN_cfp32x1_sds_t *)CS_MALLOC(sizeof(TEN_cfp32x1_sds_t));
  dft_cfp = (TEN_cfp32x1_sds_t *)CS_MALLOC(sizeof(TEN_cfp32x1_sds_t));
  
  /* Bug #38811: Debug APIs need malloc check for Klocwork warning */
  if ((tmp_cfp == 0) || (dft_cfp == 0)) {
    if (tmp_cfp) {
      CS_FREE(tmp_cfp);
    }
    if (dft_cfp) {
      CS_FREE(dft_cfp);
    }
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  CS_MEMSET((TEN_cfp32x1_sds_t *)tmp_cfp, 0, sizeof(TEN_cfp32x1_sds_t));
  CS_MEMSET((TEN_cfp32x1_sds_t *)dft_cfp, 0, sizeof(TEN_cfp32x1_sds_t));

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  dft_cfp->SRX0_RX_CONFIG.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_CONFIG_dft;
  dft_cfp->SRX0_RX_CLKDIV_CTRL.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_dft;
  dft_cfp->SRX0_RX_CLKOUT_CTRL.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_dft;
  dft_cfp->SRX0_RX_LOOP_FILTER.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_LOOP_FILTER_dft;
  dft_cfp->SRX0_RX_CPA.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_CPA_dft;
  dft_cfp->SRX0_RX_CPB.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_CPB_dft;
  dft_cfp->SRX0_RX_VCO_FILT.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_VCO_FILT_dft;
  dft_cfp->SRX0_RX_VCO_CTRL.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_VCO_CTRL_dft;
  dft_cfp->SRX0_RX_MISC.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_MISC_dft;
  dft_cfp->SRX0_RX_PKDET.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_PKDET_dft;
  dft_cfp->SRX0_RX_SPARE.wrd = TEN_CFP32X1_SDS_COMMON_SRX0_RX_SPARE_dft;
  dft_cfp->RXVCO0_THRES0.wrd = TEN_CFP32X1_SDS_COMMON_RXVCO0_THRES0_dft;
  dft_cfp->RXVCO0_THRES1.wrd = TEN_CFP32X1_SDS_COMMON_RXVCO0_THRES1_dft;
  dft_cfp->RXVCO0_VCOMAX.wrd = TEN_CFP32X1_SDS_COMMON_RXVCO0_VCOMAX_dft;
  dft_cfp->RXVCO0_CONTROL.wrd = TEN_CFP32X1_SDS_COMMON_RXVCO0_CONTROL_dft;
  dft_cfp->RXVCO0_STATUS.wrd = TEN_CFP32X1_SDS_COMMON_RXVCO0_STATUS_dft;
  dft_cfp->RXVCO0_INTERRUPT.wrd = TEN_CFP32X1_SDS_COMMON_RXVCO0_INTERRUPT_dft;
  dft_cfp->RXVCO0_INTSTATUS.wrd = TEN_CFP32X1_SDS_COMMON_RXVCO0_INTSTATUS_dft;
  dft_cfp->RXVCO0_INTENABLE.wrd = TEN_CFP32X1_SDS_COMMON_RXVCO0_INTENABLE_dft;
  dft_cfp->RXVCO0_INTERRUPTZ.wrd = TEN_CFP32X1_SDS_COMMON_RXVCO0_INTERRUPTZ_dft;
  dft_cfp->RXLOCKD0_FILTER.wrd = TEN_CFP32X1_SDS_COMMON_RXLOCKD0_FILTER_dft;
  dft_cfp->RXLOCKD0_CONTROL.wrd = TEN_CFP32X1_SDS_COMMON_RXLOCKD0_CONTROL_dft;
  dft_cfp->RXLOCKD0_INTERRUPT.wrd = TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTERRUPT_dft;
  dft_cfp->RXLOCKD0_INTSTATUS.wrd = TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTSTATUS_dft;
  dft_cfp->RXLOCKD0_INTENABLE.wrd = TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTENABLE_dft;
  dft_cfp->RXLOCKD0_INTERRUPTZ.wrd = TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTERRUPTZ_dft;
  dft_cfp->RXVCOLEVEL0_OSTATUS.wrd = TEN_CFP32X1_SDS_COMMON_RXVCOLEVEL0_OSTATUS_dft;
  dft_cfp->RXVCOLEVEL0_CSTATUS.wrd = TEN_CFP32X1_SDS_COMMON_RXVCOLEVEL0_CSTATUS_dft;
  dft_cfp->STX0_TX_OUTPUT_CTRLA.wrd = TEN_CFP32X1_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_dft;
  dft_cfp->STX0_TX_OUTPUT_CTRLB.wrd = TEN_CFP32X1_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_dft;
  dft_cfp->STXP0_TX_CONFIG.wrd = TEN_CFP32X1_SDS_COMMON_STXP0_TX_CONFIG_dft;
  dft_cfp->STXP0_TX_PWRDN.wrd = TEN_CFP32X1_SDS_COMMON_STXP0_TX_PWRDN_dft;
  dft_cfp->STXP0_TX_CLKDIV_CTRL.wrd = TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_dft;
  dft_cfp->STXP0_TX_CLKOUT_CTRL.wrd = TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_dft;
  dft_cfp->STXP0_TX_LOOP_FILTER.wrd = TEN_CFP32X1_SDS_COMMON_STXP0_TX_LOOP_FILTER_dft;
  dft_cfp->STXP0_TX_CP.wrd = TEN_CFP32X1_SDS_COMMON_STXP0_TX_CP_dft;
  dft_cfp->STXP0_TX_VCO_FILT.wrd = TEN_CFP32X1_SDS_COMMON_STXP0_TX_VCO_FILT_dft;
  dft_cfp->STXP0_TX_VCO_CTRL.wrd = TEN_CFP32X1_SDS_COMMON_STXP0_TX_VCO_CTRL_dft;
  dft_cfp->STXP0_TX_SPARE.wrd = TEN_CFP32X1_SDS_COMMON_STXP0_TX_SPARE_dft;
  dft_cfp->TXVCO0_THRES0.wrd = TEN_CFP32X1_SDS_COMMON_TXVCO0_THRES0_dft;
  dft_cfp->TXVCO0_THRES1.wrd = TEN_CFP32X1_SDS_COMMON_TXVCO0_THRES1_dft;
  dft_cfp->TXVCO0_VCOMAX.wrd = TEN_CFP32X1_SDS_COMMON_TXVCO0_VCOMAX_dft;
  dft_cfp->TXVCO0_CONTROL.wrd = TEN_CFP32X1_SDS_COMMON_TXVCO0_CONTROL_dft;
  dft_cfp->TXVCO0_STATUS.wrd = TEN_CFP32X1_SDS_COMMON_TXVCO0_STATUS_dft;
  dft_cfp->TXVCO0_INTERRUPT.wrd = TEN_CFP32X1_SDS_COMMON_TXVCO0_INTERRUPT_dft;
  dft_cfp->TXVCO0_INTSTATUS.wrd = TEN_CFP32X1_SDS_COMMON_TXVCO0_INTSTATUS_dft;
  dft_cfp->TXVCO0_INTENABLE.wrd = TEN_CFP32X1_SDS_COMMON_TXVCO0_INTENABLE_dft;
  dft_cfp->TXVCO0_INTERRUPTZ.wrd = TEN_CFP32X1_SDS_COMMON_TXVCO0_INTERRUPTZ_dft;
  dft_cfp->TXLOCKD0_FILTER.wrd = TEN_CFP32X1_SDS_COMMON_TXLOCKD0_FILTER_dft;
  dft_cfp->TXLOCKD0_CONTROL.wrd = TEN_CFP32X1_SDS_COMMON_TXLOCKD0_CONTROL_dft;
  dft_cfp->TXLOCKD0_INTERRUPT.wrd = TEN_CFP32X1_SDS_COMMON_TXLOCKD0_INTERRUPT_dft;
  dft_cfp->TXLOCKD0_INTSTATUS.wrd = TEN_CFP32X1_SDS_COMMON_TXLOCKD0_INTSTATUS_dft;
  dft_cfp->TXLOCKD0_INTENABLE.wrd = TEN_CFP32X1_SDS_COMMON_TXLOCKD0_INTENABLE_dft;
  dft_cfp->TXLOCKD0_INTERRUPTZ.wrd = TEN_CFP32X1_SDS_COMMON_TXLOCKD0_INTERRUPTZ_dft;
  dft_cfp->TXVCOLEVEL0_OSTATUS.wrd = TEN_CFP32X1_SDS_COMMON_TXVCOLEVEL0_OSTATUS_dft;
  dft_cfp->TXVCOLEVEL0_CSTATUS.wrd = TEN_CFP32X1_SDS_COMMON_TXVCOLEVEL0_CSTATUS_dft;
  dft_cfp->RXELST0_Control.wrd = TEN_CFP32X1_SDS_COMMON_RXELST0_Control_dft;
  dft_cfp->TXELST0_Control.wrd = TEN_CFP32X1_SDS_COMMON_TXELST0_Control_dft;
  dft_cfp->PRBSGEN0_Cfg.wrd = TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Cfg_dft;
  dft_cfp->PRBSGEN0_Ctrl.wrd = TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Ctrl_dft;
  dft_cfp->PRBSGEN0_Fixed0_Pattern1.wrd = TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Fixed0_Pattern1_dft;
  dft_cfp->PRBSGEN0_Fixed0_Pattern0.wrd = TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Fixed0_Pattern0_dft;
  dft_cfp->PRBSGEN0_Fixed1_Pattern1.wrd = TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Fixed1_Pattern1_dft;
  dft_cfp->PRBSGEN0_Fixed1_Pattern0.wrd = TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Fixed1_Pattern0_dft;
  dft_cfp->PRBSGEN0_Repeat_Pattern.wrd = TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Repeat_Pattern_dft;
  dft_cfp->PRBSCHK0_Cfg.wrd = TEN_CFP32X1_SDS_COMMON_PRBSCHK0_Cfg_dft;
  dft_cfp->PRBSCHK0_Ctrl.wrd = TEN_CFP32X1_SDS_COMMON_PRBSCHK0_Ctrl_dft;
  dft_cfp->PRBSCHK0_Count1.wrd = TEN_CFP32X1_SDS_COMMON_PRBSCHK0_Count1_dft;
  dft_cfp->PRBSCHK0_Count0.wrd = TEN_CFP32X1_SDS_COMMON_PRBSCHK0_Count0_dft;
  dft_cfp->PRBSCHK0_INTERRUPT.wrd = TEN_CFP32X1_SDS_COMMON_PRBSCHK0_INTERRUPT_dft;
  dft_cfp->PRBSCHK0_INTSTATUS.wrd = TEN_CFP32X1_SDS_COMMON_PRBSCHK0_INTSTATUS_dft;
  dft_cfp->PRBSCHK0_INTENABLE.wrd = TEN_CFP32X1_SDS_COMMON_PRBSCHK0_INTENABLE_dft;
  dft_cfp->PRBSCHK0_INTERRUPTZ.wrd = TEN_CFP32X1_SDS_COMMON_PRBSCHK0_INTERRUPTZ_dft;
  dft_cfp->TX0_Config.wrd = TEN_CFP32X1_SDS_COMMON_TX0_Config_dft;
  dft_cfp->RX0_Config.wrd = TEN_CFP32X1_SDS_COMMON_RX0_Config_dft;
  dft_cfp->Int.wrd = TEN_CFP32X1_SDS_COMMON_Int_dft;
  dft_cfp->IntEn.wrd = TEN_CFP32X1_SDS_COMMON_IntEn_dft;
  dft_cfp->PRBSCHKi.wrd = TEN_CFP32X1_SDS_COMMON_PRBSCHKi_dft;
  dft_cfp->PRBSCHKe.wrd = TEN_CFP32X1_SDS_COMMON_PRBSCHKe_dft;
  dft_cfp->RXELSTi.wrd = TEN_CFP32X1_SDS_COMMON_RXELSTi_dft;
  dft_cfp->RXELSTe.wrd = TEN_CFP32X1_SDS_COMMON_RXELSTe_dft;
  dft_cfp->RXELSTZ.wrd = TEN_CFP32X1_SDS_COMMON_RXELSTZ_dft;
  dft_cfp->RXVCOi.wrd = TEN_CFP32X1_SDS_COMMON_RXVCOi_dft;
  dft_cfp->RXVCOe.wrd = TEN_CFP32X1_SDS_COMMON_RXVCOe_dft;
  dft_cfp->RXLOCKDi.wrd = TEN_CFP32X1_SDS_COMMON_RXLOCKDi_dft;
  dft_cfp->RXLOCKDe.wrd = TEN_CFP32X1_SDS_COMMON_RXLOCKDe_dft;
  dft_cfp->TXELSTi.wrd = TEN_CFP32X1_SDS_COMMON_TXELSTi_dft;
  dft_cfp->TXELSTe.wrd = TEN_CFP32X1_SDS_COMMON_TXELSTe_dft;
  dft_cfp->TXELSTZ.wrd = TEN_CFP32X1_SDS_COMMON_TXELSTZ_dft;
  dft_cfp->TXVCOi.wrd = TEN_CFP32X1_SDS_COMMON_TXVCOi_dft;
  dft_cfp->TXVCOe.wrd = TEN_CFP32X1_SDS_COMMON_TXVCOe_dft;
  dft_cfp->TXLOCKDi.wrd = TEN_CFP32X1_SDS_COMMON_TXLOCKDi_dft;
  dft_cfp->TXLOCKDe.wrd = TEN_CFP32X1_SDS_COMMON_TXLOCKDe_dft;


  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {

    tmp_cfp->SRX0_RX_CONFIG.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG));
    tmp_cfp->SRX0_RX_CLKDIV_CTRL.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL));
    tmp_cfp->SRX0_RX_CLKOUT_CTRL.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKOUT_CTRL));
    tmp_cfp->SRX0_RX_LOOP_FILTER.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_LOOP_FILTER));
    tmp_cfp->SRX0_RX_CPA.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CPA));
    tmp_cfp->SRX0_RX_CPB.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CPB));
    tmp_cfp->SRX0_RX_VCO_FILT.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_VCO_FILT));
    tmp_cfp->SRX0_RX_VCO_CTRL.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_VCO_CTRL));
    tmp_cfp->SRX0_RX_MISC.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_MISC));
    tmp_cfp->SRX0_RX_PKDET.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_PKDET));
    tmp_cfp->SRX0_RX_SPARE.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_SPARE));
    tmp_cfp->RXVCO0_THRES0.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_THRES0));
    tmp_cfp->RXVCO0_THRES1.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_THRES1));
    tmp_cfp->RXVCO0_VCOMAX.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_VCOMAX));
    tmp_cfp->RXVCO0_CONTROL.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_CONTROL));
    tmp_cfp->RXVCO0_STATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_STATUS));
    tmp_cfp->RXVCO0_INTERRUPT.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_INTERRUPT));
    tmp_cfp->RXVCO0_INTSTATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_INTSTATUS));
    tmp_cfp->RXVCO0_INTENABLE.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_INTENABLE));
    tmp_cfp->RXVCO0_INTERRUPTZ.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_INTERRUPTZ));
    tmp_cfp->RXLOCKD0_FILTER.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_FILTER));
    tmp_cfp->RXLOCKD0_CONTROL.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_CONTROL));
    tmp_cfp->RXLOCKD0_INTERRUPT.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTERRUPT));
    tmp_cfp->RXLOCKD0_INTSTATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTSTATUS));
    tmp_cfp->RXLOCKD0_INTENABLE.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTENABLE));
    tmp_cfp->RXLOCKD0_INTERRUPTZ.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTERRUPTZ));
    tmp_cfp->RXVCOLEVEL0_OSTATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCOLEVEL0_OSTATUS));
    tmp_cfp->RXVCOLEVEL0_CSTATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCOLEVEL0_CSTATUS));
    tmp_cfp->STX0_TX_OUTPUT_CTRLA.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLA));
    tmp_cfp->STX0_TX_OUTPUT_CTRLB.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLB));
    tmp_cfp->STXP0_TX_CONFIG.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
    tmp_cfp->STXP0_TX_PWRDN.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_PWRDN));
    tmp_cfp->STXP0_TX_CLKDIV_CTRL.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
    tmp_cfp->STXP0_TX_CLKOUT_CTRL.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL));
    tmp_cfp->STXP0_TX_LOOP_FILTER.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_LOOP_FILTER));
    tmp_cfp->STXP0_TX_CP.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CP));
    tmp_cfp->STXP0_TX_VCO_FILT.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_VCO_FILT));
    tmp_cfp->STXP0_TX_VCO_CTRL.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_VCO_CTRL));
    tmp_cfp->STXP0_TX_SPARE.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SPARE));
    tmp_cfp->TXVCO0_THRES0.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_THRES0));
    tmp_cfp->TXVCO0_THRES1.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_THRES1));
    tmp_cfp->TXVCO0_VCOMAX.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_VCOMAX));
    tmp_cfp->TXVCO0_CONTROL.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_CONTROL));
    tmp_cfp->TXVCO0_STATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_STATUS));
    tmp_cfp->TXVCO0_INTERRUPT.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_INTERRUPT));
    tmp_cfp->TXVCO0_INTSTATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_INTSTATUS));
    tmp_cfp->TXVCO0_INTENABLE.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_INTENABLE));
    tmp_cfp->TXVCO0_INTERRUPTZ.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_INTERRUPTZ));
    tmp_cfp->TXLOCKD0_FILTER.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_FILTER));
    tmp_cfp->TXLOCKD0_CONTROL.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_CONTROL));
    tmp_cfp->TXLOCKD0_INTERRUPT.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTERRUPT));
    tmp_cfp->TXLOCKD0_INTSTATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTSTATUS));
    tmp_cfp->TXLOCKD0_INTENABLE.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTENABLE));
    tmp_cfp->TXLOCKD0_INTERRUPTZ.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTERRUPTZ));
    tmp_cfp->TXVCOLEVEL0_OSTATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCOLEVEL0_OSTATUS));
    tmp_cfp->TXVCOLEVEL0_CSTATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCOLEVEL0_CSTATUS));
    tmp_cfp->RXELST0_Control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXELST0_Control));
    tmp_cfp->TXELST0_Control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXELST0_Control));
    tmp_cfp->PRBSGEN0_Cfg.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Cfg));
    tmp_cfp->PRBSGEN0_Ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Ctrl));
    tmp_cfp->PRBSGEN0_Fixed0_Pattern1.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed0_Pattern1));
    tmp_cfp->PRBSGEN0_Fixed0_Pattern0.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed0_Pattern0));
    tmp_cfp->PRBSGEN0_Fixed1_Pattern1.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed1_Pattern1));
    tmp_cfp->PRBSGEN0_Fixed1_Pattern0.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed1_Pattern0));
    tmp_cfp->PRBSGEN0_Repeat_Pattern.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Repeat_Pattern));
    tmp_cfp->PRBSCHK0_Cfg.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Cfg));
    tmp_cfp->PRBSCHK0_Ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Ctrl));
    tmp_cfp->PRBSCHK0_Count1.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Count1));
    tmp_cfp->PRBSCHK0_Count0.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Count0));
    tmp_cfp->PRBSCHK0_INTERRUPT.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_INTERRUPT));
    tmp_cfp->PRBSCHK0_INTSTATUS.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_INTSTATUS));
    tmp_cfp->PRBSCHK0_INTENABLE.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_INTENABLE));
    tmp_cfp->PRBSCHK0_INTERRUPTZ.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_INTERRUPTZ));
    tmp_cfp->TX0_Config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TX0_Config));
    tmp_cfp->RX0_Config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RX0_Config));
    tmp_cfp->Int.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, Int));
    tmp_cfp->IntEn.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, IntEn));
    tmp_cfp->PRBSCHKi.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHKi));
    tmp_cfp->PRBSCHKe.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHKe));
    tmp_cfp->RXELSTi.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXELSTi));
    tmp_cfp->RXELSTe.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXELSTe));
    tmp_cfp->RXELSTZ.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXELSTZ));
    tmp_cfp->RXVCOi.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCOi));
    tmp_cfp->RXVCOe.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCOe));
    tmp_cfp->RXLOCKDi.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKDi));
    tmp_cfp->RXLOCKDe.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKDe));
    tmp_cfp->TXELSTi.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXELSTi));
    tmp_cfp->TXELSTe.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXELSTe));
    tmp_cfp->TXELSTZ.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXELSTZ));
    tmp_cfp->TXVCOi.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCOi));
    tmp_cfp->TXVCOe.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCOe));
    tmp_cfp->TXLOCKDi.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKDi));
    tmp_cfp->TXLOCKDe.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKDe));

    ch1 = (module_id & 1) ? 'B' : 'A';
    ch2 = sl + '0';
    
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CONFIG.wrd", tmp_cfp->SRX0_RX_CONFIG.wrd, tmp_cfp->SRX0_RX_CONFIG.wrd == dft_cfp->SRX0_RX_CONFIG.wrd ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CONFIG.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CONFIG.bf.SRX_AMP_PD", tmp_cfp->SRX0_RX_CONFIG.bf.SRX_AMP_PD, tmp_cfp->SRX0_RX_CONFIG.bf.SRX_AMP_PD == dft_cfp->SRX0_RX_CONFIG.bf.SRX_AMP_PD ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CONFIG.bf.SRX_AMP_PD, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CONFIG.bf.SRX_PD", tmp_cfp->SRX0_RX_CONFIG.bf.SRX_PD, tmp_cfp->SRX0_RX_CONFIG.bf.SRX_PD == dft_cfp->SRX0_RX_CONFIG.bf.SRX_PD ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CONFIG.bf.SRX_PD, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CONFIG.bf.SRX_BUSWIDTH", tmp_cfp->SRX0_RX_CONFIG.bf.SRX_BUSWIDTH, tmp_cfp->SRX0_RX_CONFIG.bf.SRX_BUSWIDTH == dft_cfp->SRX0_RX_CONFIG.bf.SRX_BUSWIDTH ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CONFIG.bf.SRX_BUSWIDTH, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CONFIG.bf.SRX_XFI_EN", tmp_cfp->SRX0_RX_CONFIG.bf.SRX_XFI_EN, tmp_cfp->SRX0_RX_CONFIG.bf.SRX_XFI_EN == dft_cfp->SRX0_RX_CONFIG.bf.SRX_XFI_EN ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CONFIG.bf.SRX_XFI_EN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CONFIG.bf.SRX_LPBKEN", tmp_cfp->SRX0_RX_CONFIG.bf.SRX_LPBKEN, tmp_cfp->SRX0_RX_CONFIG.bf.SRX_LPBKEN == dft_cfp->SRX0_RX_CONFIG.bf.SRX_LPBKEN ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CONFIG.bf.SRX_LPBKEN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CLKDIV_CTRL.wrd", tmp_cfp->SRX0_RX_CLKDIV_CTRL.wrd, tmp_cfp->SRX0_RX_CLKDIV_CTRL.wrd == dft_cfp->SRX0_RX_CLKDIV_CTRL.wrd ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CLKDIV_CTRL.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CLKDIV_CTRL.bf.SRX_FASTDIV_SEL", tmp_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_FASTDIV_SEL, tmp_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_FASTDIV_SEL == dft_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_FASTDIV_SEL ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_FASTDIV_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CLKDIV_CTRL.bf.SRX_CTVDIV_SEL", tmp_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_CTVDIV_SEL, tmp_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_CTVDIV_SEL == dft_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_CTVDIV_SEL ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_CTVDIV_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CLKDIV_CTRL.bf.SRX_DDIV_SEL", tmp_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_DDIV_SEL, tmp_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_DDIV_SEL == dft_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_DDIV_SEL ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_DDIV_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CLKDIV_CTRL.bf.SRX_RDIV_SEL", tmp_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_RDIV_SEL, tmp_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_RDIV_SEL == dft_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_RDIV_SEL ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CLKDIV_CTRL.bf.SRX_RDIV_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CLKOUT_CTRL.wrd", tmp_cfp->SRX0_RX_CLKOUT_CTRL.wrd, tmp_cfp->SRX0_RX_CLKOUT_CTRL.wrd == dft_cfp->SRX0_RX_CLKOUT_CTRL.wrd ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CLKOUT_CTRL.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CLKOUT_CTRL.bf.SRX_CLKINVEN", tmp_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_CLKINVEN, tmp_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_CLKINVEN == dft_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_CLKINVEN ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_CLKINVEN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CLKOUT_CTRL.bf.SRX_TCLKIEN", tmp_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_TCLKIEN, tmp_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_TCLKIEN == dft_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_TCLKIEN ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_TCLKIEN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CLKOUT_CTRL.bf.SRX_TCLKO_SEL", tmp_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_TCLKO_SEL, tmp_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_TCLKO_SEL == dft_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_TCLKO_SEL ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CLKOUT_CTRL.bf.SRX_TCLKO_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CPA.wrd", tmp_cfp->SRX0_RX_CPA.wrd, tmp_cfp->SRX0_RX_CPA.wrd == dft_cfp->SRX0_RX_CPA.wrd ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CPA.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CPA.bf.SRX_CPCUR1", tmp_cfp->SRX0_RX_CPA.bf.SRX_CPCUR1, tmp_cfp->SRX0_RX_CPA.bf.SRX_CPCUR1 == dft_cfp->SRX0_RX_CPA.bf.SRX_CPCUR1 ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CPA.bf.SRX_CPCUR1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_CPA.bf.SRX_CPCUR0", tmp_cfp->SRX0_RX_CPA.bf.SRX_CPCUR0, tmp_cfp->SRX0_RX_CPA.bf.SRX_CPCUR0 == dft_cfp->SRX0_RX_CPA.bf.SRX_CPCUR0 ? 0x20 : 0x2A, dft_cfp->SRX0_RX_CPA.bf.SRX_CPCUR0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_MISC.wrd", tmp_cfp->SRX0_RX_MISC.wrd, tmp_cfp->SRX0_RX_MISC.wrd == dft_cfp->SRX0_RX_MISC.wrd ? 0x20 : 0x2A, dft_cfp->SRX0_RX_MISC.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_MISC.bf.SRX_HI_GAIN", tmp_cfp->SRX0_RX_MISC.bf.SRX_HI_GAIN, tmp_cfp->SRX0_RX_MISC.bf.SRX_HI_GAIN == dft_cfp->SRX0_RX_MISC.bf.SRX_HI_GAIN ? 0x20 : 0x2A, dft_cfp->SRX0_RX_MISC.bf.SRX_HI_GAIN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_SRX0_RX_MISC.bf.SRX_EQADJ", tmp_cfp->SRX0_RX_MISC.bf.SRX_EQADJ, tmp_cfp->SRX0_RX_MISC.bf.SRX_EQADJ == dft_cfp->SRX0_RX_MISC.bf.SRX_EQADJ ? 0x20 : 0x2A, dft_cfp->SRX0_RX_MISC.bf.SRX_EQADJ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_THRES0.wrd", tmp_cfp->RXVCO0_THRES0.wrd, tmp_cfp->RXVCO0_THRES0.wrd == dft_cfp->RXVCO0_THRES0.wrd ? 0x20 : 0x2A, dft_cfp->RXVCO0_THRES0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_THRES0.bf.FREQ_THRES_SIGN0", tmp_cfp->RXVCO0_THRES0.bf.FREQ_THRES_SIGN0, tmp_cfp->RXVCO0_THRES0.bf.FREQ_THRES_SIGN0 == dft_cfp->RXVCO0_THRES0.bf.FREQ_THRES_SIGN0 ? 0x20 : 0x2A, dft_cfp->RXVCO0_THRES0.bf.FREQ_THRES_SIGN0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_THRES0.bf.FREQ_THRES0", tmp_cfp->RXVCO0_THRES0.bf.FREQ_THRES0, tmp_cfp->RXVCO0_THRES0.bf.FREQ_THRES0 == dft_cfp->RXVCO0_THRES0.bf.FREQ_THRES0 ? 0x20 : 0x2A, dft_cfp->RXVCO0_THRES0.bf.FREQ_THRES0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_THRES1.wrd", tmp_cfp->RXVCO0_THRES1.wrd, tmp_cfp->RXVCO0_THRES1.wrd == dft_cfp->RXVCO0_THRES1.wrd ? 0x20 : 0x2A, dft_cfp->RXVCO0_THRES1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_THRES1.bf.FREQ_THRES_SIGN1", tmp_cfp->RXVCO0_THRES1.bf.FREQ_THRES_SIGN1, tmp_cfp->RXVCO0_THRES1.bf.FREQ_THRES_SIGN1 == dft_cfp->RXVCO0_THRES1.bf.FREQ_THRES_SIGN1 ? 0x20 : 0x2A, dft_cfp->RXVCO0_THRES1.bf.FREQ_THRES_SIGN1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_THRES1.bf.FREQ_THRES1", tmp_cfp->RXVCO0_THRES1.bf.FREQ_THRES1, tmp_cfp->RXVCO0_THRES1.bf.FREQ_THRES1 == dft_cfp->RXVCO0_THRES1.bf.FREQ_THRES1 ? 0x20 : 0x2A, dft_cfp->RXVCO0_THRES1.bf.FREQ_THRES1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_VCOMAX.wrd", tmp_cfp->RXVCO0_VCOMAX.wrd, tmp_cfp->RXVCO0_VCOMAX.wrd == dft_cfp->RXVCO0_VCOMAX.wrd ? 0x20 : 0x2A, dft_cfp->RXVCO0_VCOMAX.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_VCOMAX.bf.VCOMAX", tmp_cfp->RXVCO0_VCOMAX.bf.VCOMAX, tmp_cfp->RXVCO0_VCOMAX.bf.VCOMAX == dft_cfp->RXVCO0_VCOMAX.bf.VCOMAX ? 0x20 : 0x2A, dft_cfp->RXVCO0_VCOMAX.bf.VCOMAX, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_CONTROL.wrd", tmp_cfp->RXVCO0_CONTROL.wrd, tmp_cfp->RXVCO0_CONTROL.wrd == dft_cfp->RXVCO0_CONTROL.wrd ? 0x20 : 0x2A, dft_cfp->RXVCO0_CONTROL.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_CONTROL.bf.INIT", tmp_cfp->RXVCO0_CONTROL.bf.INIT, tmp_cfp->RXVCO0_CONTROL.bf.INIT == dft_cfp->RXVCO0_CONTROL.bf.INIT ? 0x20 : 0x2A, dft_cfp->RXVCO0_CONTROL.bf.INIT, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_CONTROL.bf.SHORT_OVRIDE", tmp_cfp->RXVCO0_CONTROL.bf.SHORT_OVRIDE, tmp_cfp->RXVCO0_CONTROL.bf.SHORT_OVRIDE == dft_cfp->RXVCO0_CONTROL.bf.SHORT_OVRIDE ? 0x20 : 0x2A, dft_cfp->RXVCO0_CONTROL.bf.SHORT_OVRIDE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_STATUS.wrd", tmp_cfp->RXVCO0_STATUS.wrd, tmp_cfp->RXVCO0_STATUS.wrd == dft_cfp->RXVCO0_STATUS.wrd ? 0x20 : 0x2A, dft_cfp->RXVCO0_STATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_STATUS.bf.FREQ", tmp_cfp->RXVCO0_STATUS.bf.FREQ, tmp_cfp->RXVCO0_STATUS.bf.FREQ == dft_cfp->RXVCO0_STATUS.bf.FREQ ? 0x20 : 0x2A, dft_cfp->RXVCO0_STATUS.bf.FREQ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_INTERRUPT.wrd", tmp_cfp->RXVCO0_INTERRUPT.wrd, tmp_cfp->RXVCO0_INTERRUPT.wrd == dft_cfp->RXVCO0_INTERRUPT.wrd ? 0x20 : 0x2A, dft_cfp->RXVCO0_INTERRUPT.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_INTERRUPT.bf.SHORT_FILTPNi", tmp_cfp->RXVCO0_INTERRUPT.bf.SHORT_FILTPNi, tmp_cfp->RXVCO0_INTERRUPT.bf.SHORT_FILTPNi == dft_cfp->RXVCO0_INTERRUPT.bf.SHORT_FILTPNi ? 0x20 : 0x2A, dft_cfp->RXVCO0_INTERRUPT.bf.SHORT_FILTPNi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_INTSTATUS.wrd", tmp_cfp->RXVCO0_INTSTATUS.wrd, tmp_cfp->RXVCO0_INTSTATUS.wrd == dft_cfp->RXVCO0_INTSTATUS.wrd ? 0x20 : 0x2A, dft_cfp->RXVCO0_INTSTATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_INTSTATUS.bf.SHORT_FILTPNs", tmp_cfp->RXVCO0_INTSTATUS.bf.SHORT_FILTPNs, tmp_cfp->RXVCO0_INTSTATUS.bf.SHORT_FILTPNs == dft_cfp->RXVCO0_INTSTATUS.bf.SHORT_FILTPNs ? 0x20 : 0x2A, dft_cfp->RXVCO0_INTSTATUS.bf.SHORT_FILTPNs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_INTENABLE.wrd", tmp_cfp->RXVCO0_INTENABLE.wrd, tmp_cfp->RXVCO0_INTENABLE.wrd == dft_cfp->RXVCO0_INTENABLE.wrd ? 0x20 : 0x2A, dft_cfp->RXVCO0_INTENABLE.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_INTENABLE.bf.SHORT_FILTPNe", tmp_cfp->RXVCO0_INTENABLE.bf.SHORT_FILTPNe, tmp_cfp->RXVCO0_INTENABLE.bf.SHORT_FILTPNe == dft_cfp->RXVCO0_INTENABLE.bf.SHORT_FILTPNe ? 0x20 : 0x2A, dft_cfp->RXVCO0_INTENABLE.bf.SHORT_FILTPNe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_INTERRUPTZ.wrd", tmp_cfp->RXVCO0_INTERRUPTZ.wrd, tmp_cfp->RXVCO0_INTERRUPTZ.wrd == dft_cfp->RXVCO0_INTERRUPTZ.wrd ? 0x20 : 0x2A, dft_cfp->RXVCO0_INTERRUPTZ.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ", tmp_cfp->RXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ, tmp_cfp->RXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ == dft_cfp->RXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ ? 0x20 : 0x2A, dft_cfp->RXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_FILTER.wrd", tmp_cfp->RXLOCKD0_FILTER.wrd, tmp_cfp->RXLOCKD0_FILTER.wrd == dft_cfp->RXLOCKD0_FILTER.wrd ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_FILTER.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_FILTER.bf.STABLE_PERIOD", tmp_cfp->RXLOCKD0_FILTER.bf.STABLE_PERIOD, tmp_cfp->RXLOCKD0_FILTER.bf.STABLE_PERIOD == dft_cfp->RXLOCKD0_FILTER.bf.STABLE_PERIOD ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_FILTER.bf.STABLE_PERIOD, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_CONTROL.wrd", tmp_cfp->RXLOCKD0_CONTROL.wrd, tmp_cfp->RXLOCKD0_CONTROL.wrd == dft_cfp->RXLOCKD0_CONTROL.wrd ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_CONTROL.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_CONTROL.bf.DATA_LOCK", tmp_cfp->RXLOCKD0_CONTROL.bf.DATA_LOCK, tmp_cfp->RXLOCKD0_CONTROL.bf.DATA_LOCK == dft_cfp->RXLOCKD0_CONTROL.bf.DATA_LOCK ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_CONTROL.bf.DATA_LOCK, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_CONTROL.bf.PD_MODE", tmp_cfp->RXLOCKD0_CONTROL.bf.PD_MODE, tmp_cfp->RXLOCKD0_CONTROL.bf.PD_MODE == dft_cfp->RXLOCKD0_CONTROL.bf.PD_MODE ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_CONTROL.bf.PD_MODE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_CONTROL.bf.FORCE_LOCK", tmp_cfp->RXLOCKD0_CONTROL.bf.FORCE_LOCK, tmp_cfp->RXLOCKD0_CONTROL.bf.FORCE_LOCK == dft_cfp->RXLOCKD0_CONTROL.bf.FORCE_LOCK ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_CONTROL.bf.FORCE_LOCK, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPT.wrd", tmp_cfp->RXLOCKD0_INTERRUPT.wrd, tmp_cfp->RXLOCKD0_INTERRUPT.wrd == dft_cfp->RXLOCKD0_INTERRUPT.wrd ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPT.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPT.bf.FILT_LOCKi", tmp_cfp->RXLOCKD0_INTERRUPT.bf.FILT_LOCKi, tmp_cfp->RXLOCKD0_INTERRUPT.bf.FILT_LOCKi == dft_cfp->RXLOCKD0_INTERRUPT.bf.FILT_LOCKi ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPT.bf.FILT_LOCKi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPT.bf.DATA_DETi", tmp_cfp->RXLOCKD0_INTERRUPT.bf.DATA_DETi, tmp_cfp->RXLOCKD0_INTERRUPT.bf.DATA_DETi == dft_cfp->RXLOCKD0_INTERRUPT.bf.DATA_DETi ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPT.bf.DATA_DETi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi", tmp_cfp->RXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi, tmp_cfp->RXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi == dft_cfp->RXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi", tmp_cfp->RXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi, tmp_cfp->RXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi == dft_cfp->RXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPT.bf.LOCKi", tmp_cfp->RXLOCKD0_INTERRUPT.bf.LOCKi, tmp_cfp->RXLOCKD0_INTERRUPT.bf.LOCKi == dft_cfp->RXLOCKD0_INTERRUPT.bf.LOCKi ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPT.bf.LOCKi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTSTATUS.wrd", tmp_cfp->RXLOCKD0_INTSTATUS.wrd, tmp_cfp->RXLOCKD0_INTSTATUS.wrd == dft_cfp->RXLOCKD0_INTSTATUS.wrd ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTSTATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTSTATUS.bf.FILT_LOCKs", tmp_cfp->RXLOCKD0_INTSTATUS.bf.FILT_LOCKs, tmp_cfp->RXLOCKD0_INTSTATUS.bf.FILT_LOCKs == dft_cfp->RXLOCKD0_INTSTATUS.bf.FILT_LOCKs ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTSTATUS.bf.FILT_LOCKs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTSTATUS.bf.DATA_DETs", tmp_cfp->RXLOCKD0_INTSTATUS.bf.DATA_DETs, tmp_cfp->RXLOCKD0_INTSTATUS.bf.DATA_DETs == dft_cfp->RXLOCKD0_INTSTATUS.bf.DATA_DETs ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTSTATUS.bf.DATA_DETs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs", tmp_cfp->RXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs, tmp_cfp->RXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs == dft_cfp->RXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs", tmp_cfp->RXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs, tmp_cfp->RXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs == dft_cfp->RXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTSTATUS.bf.LOCKs", tmp_cfp->RXLOCKD0_INTSTATUS.bf.LOCKs, tmp_cfp->RXLOCKD0_INTSTATUS.bf.LOCKs == dft_cfp->RXLOCKD0_INTSTATUS.bf.LOCKs ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTSTATUS.bf.LOCKs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTENABLE.wrd", tmp_cfp->RXLOCKD0_INTENABLE.wrd, tmp_cfp->RXLOCKD0_INTENABLE.wrd == dft_cfp->RXLOCKD0_INTENABLE.wrd ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTENABLE.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTENABLE.bf.FILT_LOCKe", tmp_cfp->RXLOCKD0_INTENABLE.bf.FILT_LOCKe, tmp_cfp->RXLOCKD0_INTENABLE.bf.FILT_LOCKe == dft_cfp->RXLOCKD0_INTENABLE.bf.FILT_LOCKe ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTENABLE.bf.FILT_LOCKe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTENABLE.bf.DATA_DETe", tmp_cfp->RXLOCKD0_INTENABLE.bf.DATA_DETe, tmp_cfp->RXLOCKD0_INTENABLE.bf.DATA_DETe == dft_cfp->RXLOCKD0_INTENABLE.bf.DATA_DETe ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTENABLE.bf.DATA_DETe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTENABLE.bf.SHORT_FILTPNe", tmp_cfp->RXLOCKD0_INTENABLE.bf.SHORT_FILTPNe, tmp_cfp->RXLOCKD0_INTENABLE.bf.SHORT_FILTPNe == dft_cfp->RXLOCKD0_INTENABLE.bf.SHORT_FILTPNe ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTENABLE.bf.SHORT_FILTPNe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe", tmp_cfp->RXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe, tmp_cfp->RXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe == dft_cfp->RXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTENABLE.bf.LOCKe", tmp_cfp->RXLOCKD0_INTENABLE.bf.LOCKe, tmp_cfp->RXLOCKD0_INTENABLE.bf.LOCKe == dft_cfp->RXLOCKD0_INTENABLE.bf.LOCKe ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTENABLE.bf.LOCKe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPTZ.wrd", tmp_cfp->RXLOCKD0_INTERRUPTZ.wrd, tmp_cfp->RXLOCKD0_INTERRUPTZ.wrd == dft_cfp->RXLOCKD0_INTERRUPTZ.wrd ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPTZ.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ", tmp_cfp->RXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ, tmp_cfp->RXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ == dft_cfp->RXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ", tmp_cfp->RXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ, tmp_cfp->RXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ == dft_cfp->RXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ", tmp_cfp->RXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ, tmp_cfp->RXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ == dft_cfp->RXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ", tmp_cfp->RXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ, tmp_cfp->RXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ == dft_cfp->RXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKD0_INTERRUPTZ.bf.LOCKiZ", tmp_cfp->RXLOCKD0_INTERRUPTZ.bf.LOCKiZ, tmp_cfp->RXLOCKD0_INTERRUPTZ.bf.LOCKiZ == dft_cfp->RXLOCKD0_INTERRUPTZ.bf.LOCKiZ ? 0x20 : 0x2A, dft_cfp->RXLOCKD0_INTERRUPTZ.bf.LOCKiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCOLEVEL0_OSTATUS.wrd", tmp_cfp->RXVCOLEVEL0_OSTATUS.wrd, tmp_cfp->RXVCOLEVEL0_OSTATUS.wrd == dft_cfp->RXVCOLEVEL0_OSTATUS.wrd ? 0x20 : 0x2A, dft_cfp->RXVCOLEVEL0_OSTATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS", tmp_cfp->RXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS, tmp_cfp->RXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS == dft_cfp->RXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS ? 0x20 : 0x2A, dft_cfp->RXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCOLEVEL0_CSTATUS.wrd", tmp_cfp->RXVCOLEVEL0_CSTATUS.wrd, tmp_cfp->RXVCOLEVEL0_CSTATUS.wrd == dft_cfp->RXVCOLEVEL0_CSTATUS.wrd ? 0x20 : 0x2A, dft_cfp->RXVCOLEVEL0_CSTATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS", tmp_cfp->RXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS, tmp_cfp->RXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS == dft_cfp->RXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS ? 0x20 : 0x2A, dft_cfp->RXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STX0_TX_OUTPUT_CTRLA.wrd", tmp_cfp->STX0_TX_OUTPUT_CTRLA.wrd, tmp_cfp->STX0_TX_OUTPUT_CTRLA.wrd == dft_cfp->STX0_TX_OUTPUT_CTRLA.wrd ? 0x20 : 0x2A, dft_cfp->STX0_TX_OUTPUT_CTRLA.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STX0_TX_OUTPUT_CTRLA.bf.STX_DRV_LOWER_CM", tmp_cfp->STX0_TX_OUTPUT_CTRLA.bf.STX_DRV_LOWER_CM, tmp_cfp->STX0_TX_OUTPUT_CTRLA.bf.STX_DRV_LOWER_CM == dft_cfp->STX0_TX_OUTPUT_CTRLA.bf.STX_DRV_LOWER_CM ? 0x20 : 0x2A, dft_cfp->STX0_TX_OUTPUT_CTRLA.bf.STX_DRV_LOWER_CM, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STX0_TX_OUTPUT_CTRLA.bf.STX_LEVEL", tmp_cfp->STX0_TX_OUTPUT_CTRLA.bf.STX_LEVEL, tmp_cfp->STX0_TX_OUTPUT_CTRLA.bf.STX_LEVEL == dft_cfp->STX0_TX_OUTPUT_CTRLA.bf.STX_LEVEL ? 0x20 : 0x2A, dft_cfp->STX0_TX_OUTPUT_CTRLA.bf.STX_LEVEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STX0_TX_OUTPUT_CTRLB.wrd", tmp_cfp->STX0_TX_OUTPUT_CTRLB.wrd, tmp_cfp->STX0_TX_OUTPUT_CTRLB.wrd == dft_cfp->STX0_TX_OUTPUT_CTRLB.wrd ? 0x20 : 0x2A, dft_cfp->STX0_TX_OUTPUT_CTRLB.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STX0_TX_OUTPUT_CTRLB.bf.STX_PRE_PEAK", tmp_cfp->STX0_TX_OUTPUT_CTRLB.bf.STX_PRE_PEAK, tmp_cfp->STX0_TX_OUTPUT_CTRLB.bf.STX_PRE_PEAK == dft_cfp->STX0_TX_OUTPUT_CTRLB.bf.STX_PRE_PEAK ? 0x20 : 0x2A, dft_cfp->STX0_TX_OUTPUT_CTRLB.bf.STX_PRE_PEAK, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STX0_TX_OUTPUT_CTRLB.bf.STX_POST_PEAK", tmp_cfp->STX0_TX_OUTPUT_CTRLB.bf.STX_POST_PEAK, tmp_cfp->STX0_TX_OUTPUT_CTRLB.bf.STX_POST_PEAK == dft_cfp->STX0_TX_OUTPUT_CTRLB.bf.STX_POST_PEAK ? 0x20 : 0x2A, dft_cfp->STX0_TX_OUTPUT_CTRLB.bf.STX_POST_PEAK, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CONFIG.wrd", tmp_cfp->STXP0_TX_CONFIG.wrd, tmp_cfp->STXP0_TX_CONFIG.wrd == dft_cfp->STXP0_TX_CONFIG.wrd ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CONFIG.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL", tmp_cfp->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL, tmp_cfp->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL == dft_cfp->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL_MSB", tmp_cfp->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL_MSB, tmp_cfp->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL_MSB == dft_cfp->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL_MSB ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL_MSB, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CONFIG.bf.STXP_PILOT_SEL", tmp_cfp->STXP0_TX_CONFIG.bf.STXP_PILOT_SEL, tmp_cfp->STXP0_TX_CONFIG.bf.STXP_PILOT_SEL == dft_cfp->STXP0_TX_CONFIG.bf.STXP_PILOT_SEL ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CONFIG.bf.STXP_PILOT_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CONFIG.bf.STXP_BUSWIDTH", tmp_cfp->STXP0_TX_CONFIG.bf.STXP_BUSWIDTH, tmp_cfp->STXP0_TX_CONFIG.bf.STXP_BUSWIDTH == dft_cfp->STXP0_TX_CONFIG.bf.STXP_BUSWIDTH ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CONFIG.bf.STXP_BUSWIDTH, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CONFIG.bf.STXP_XFI_EN", tmp_cfp->STXP0_TX_CONFIG.bf.STXP_XFI_EN, tmp_cfp->STXP0_TX_CONFIG.bf.STXP_XFI_EN == dft_cfp->STXP0_TX_CONFIG.bf.STXP_XFI_EN ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CONFIG.bf.STXP_XFI_EN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CONFIG.bf.STXP_LPBKEN", tmp_cfp->STXP0_TX_CONFIG.bf.STXP_LPBKEN, tmp_cfp->STXP0_TX_CONFIG.bf.STXP_LPBKEN == dft_cfp->STXP0_TX_CONFIG.bf.STXP_LPBKEN ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CONFIG.bf.STXP_LPBKEN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_PWRDN.wrd", tmp_cfp->STXP0_TX_PWRDN.wrd, tmp_cfp->STXP0_TX_PWRDN.wrd == dft_cfp->STXP0_TX_PWRDN.wrd ? 0x20 : 0x2A, dft_cfp->STXP0_TX_PWRDN.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_PWRDN.bf.STXP_PD", tmp_cfp->STXP0_TX_PWRDN.bf.STXP_PD, tmp_cfp->STXP0_TX_PWRDN.bf.STXP_PD == dft_cfp->STXP0_TX_PWRDN.bf.STXP_PD ? 0x20 : 0x2A, dft_cfp->STXP0_TX_PWRDN.bf.STXP_PD, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_PWRDN.bf.STXP_PD_LANE", tmp_cfp->STXP0_TX_PWRDN.bf.STXP_PD_LANE, tmp_cfp->STXP0_TX_PWRDN.bf.STXP_PD_LANE == dft_cfp->STXP0_TX_PWRDN.bf.STXP_PD_LANE ? 0x20 : 0x2A, dft_cfp->STXP0_TX_PWRDN.bf.STXP_PD_LANE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CLKDIV_CTRL.wrd", tmp_cfp->STXP0_TX_CLKDIV_CTRL.wrd, tmp_cfp->STXP0_TX_CLKDIV_CTRL.wrd == dft_cfp->STXP0_TX_CLKDIV_CTRL.wrd ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CLKDIV_CTRL.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CLKDIV_CTRL.bf.STXP_FASTDIV_SEL", tmp_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_FASTDIV_SEL, tmp_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_FASTDIV_SEL == dft_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_FASTDIV_SEL ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_FASTDIV_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CLKDIV_CTRL.bf.STXP_CTRDIV_SEL", tmp_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTRDIV_SEL, tmp_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTRDIV_SEL == dft_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTRDIV_SEL ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTRDIV_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CLKDIV_CTRL.bf.STXP_CTVDIV_SEL", tmp_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTVDIV_SEL, tmp_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTVDIV_SEL == dft_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTVDIV_SEL ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTVDIV_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CLKDIV_CTRL.bf.STXP_DDIV_SEL", tmp_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_DDIV_SEL, tmp_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_DDIV_SEL == dft_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_DDIV_SEL ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_DDIV_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CLKDIV_CTRL.bf.STXP_RDIV_SEL", tmp_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_RDIV_SEL, tmp_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_RDIV_SEL == dft_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_RDIV_SEL ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CLKDIV_CTRL.bf.STXP_RDIV_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CLKOUT_CTRL.wrd", tmp_cfp->STXP0_TX_CLKOUT_CTRL.wrd, tmp_cfp->STXP0_TX_CLKOUT_CTRL.wrd == dft_cfp->STXP0_TX_CLKOUT_CTRL.wrd ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CLKOUT_CTRL.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKIEN", tmp_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKIEN, tmp_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKIEN == dft_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKIEN ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKIEN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CLKOUT_CTRL.bf.STXP_CLKOUTEN", tmp_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_CLKOUTEN, tmp_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_CLKOUTEN == dft_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_CLKOUTEN ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_CLKOUTEN, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKO_SEL", tmp_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKO_SEL, tmp_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKO_SEL == dft_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKO_SEL ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKO_SEL, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_LOOP_FILTER.wrd", tmp_cfp->STXP0_TX_LOOP_FILTER.wrd, tmp_cfp->STXP0_TX_LOOP_FILTER.wrd == dft_cfp->STXP0_TX_LOOP_FILTER.wrd ? 0x20 : 0x2A, dft_cfp->STXP0_TX_LOOP_FILTER.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_LOOP_FILTER.bf.STXP_FILTR", tmp_cfp->STXP0_TX_LOOP_FILTER.bf.STXP_FILTR, tmp_cfp->STXP0_TX_LOOP_FILTER.bf.STXP_FILTR == dft_cfp->STXP0_TX_LOOP_FILTER.bf.STXP_FILTR ? 0x20 : 0x2A, dft_cfp->STXP0_TX_LOOP_FILTER.bf.STXP_FILTR, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CP.wrd", tmp_cfp->STXP0_TX_CP.wrd, tmp_cfp->STXP0_TX_CP.wrd == dft_cfp->STXP0_TX_CP.wrd ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CP.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CP.bf.STXP_CPCUR1", tmp_cfp->STXP0_TX_CP.bf.STXP_CPCUR1, tmp_cfp->STXP0_TX_CP.bf.STXP_CPCUR1 == dft_cfp->STXP0_TX_CP.bf.STXP_CPCUR1 ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CP.bf.STXP_CPCUR1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_CP.bf.STXP_CPCUR0", tmp_cfp->STXP0_TX_CP.bf.STXP_CPCUR0, tmp_cfp->STXP0_TX_CP.bf.STXP_CPCUR0 == dft_cfp->STXP0_TX_CP.bf.STXP_CPCUR0 ? 0x20 : 0x2A, dft_cfp->STXP0_TX_CP.bf.STXP_CPCUR0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_SPARE.wrd", tmp_cfp->STXP0_TX_SPARE.wrd, tmp_cfp->STXP0_TX_SPARE.wrd == dft_cfp->STXP0_TX_SPARE.wrd ? 0x20 : 0x2A, dft_cfp->STXP0_TX_SPARE.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_STXP0_TX_SPARE.bf.STXP_REF_SEL_MODE", tmp_cfp->STXP0_TX_SPARE.bf.STXP_REF_SEL_MODE, tmp_cfp->STXP0_TX_SPARE.bf.STXP_REF_SEL_MODE == dft_cfp->STXP0_TX_SPARE.bf.STXP_REF_SEL_MODE ? 0x20 : 0x2A, dft_cfp->STXP0_TX_SPARE.bf.STXP_REF_SEL_MODE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_THRES0.wrd", tmp_cfp->TXVCO0_THRES0.wrd, tmp_cfp->TXVCO0_THRES0.wrd == dft_cfp->TXVCO0_THRES0.wrd ? 0x20 : 0x2A, dft_cfp->TXVCO0_THRES0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_THRES0.bf.FREQ_THRES_SIGN0", tmp_cfp->TXVCO0_THRES0.bf.FREQ_THRES_SIGN0, tmp_cfp->TXVCO0_THRES0.bf.FREQ_THRES_SIGN0 == dft_cfp->TXVCO0_THRES0.bf.FREQ_THRES_SIGN0 ? 0x20 : 0x2A, dft_cfp->TXVCO0_THRES0.bf.FREQ_THRES_SIGN0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_THRES0.bf.FREQ_THRES0", tmp_cfp->TXVCO0_THRES0.bf.FREQ_THRES0, tmp_cfp->TXVCO0_THRES0.bf.FREQ_THRES0 == dft_cfp->TXVCO0_THRES0.bf.FREQ_THRES0 ? 0x20 : 0x2A, dft_cfp->TXVCO0_THRES0.bf.FREQ_THRES0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_THRES1.wrd", tmp_cfp->TXVCO0_THRES1.wrd, tmp_cfp->TXVCO0_THRES1.wrd == dft_cfp->TXVCO0_THRES1.wrd ? 0x20 : 0x2A, dft_cfp->TXVCO0_THRES1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_THRES1.bf.FREQ_THRES_SIGN1", tmp_cfp->TXVCO0_THRES1.bf.FREQ_THRES_SIGN1, tmp_cfp->TXVCO0_THRES1.bf.FREQ_THRES_SIGN1 == dft_cfp->TXVCO0_THRES1.bf.FREQ_THRES_SIGN1 ? 0x20 : 0x2A, dft_cfp->TXVCO0_THRES1.bf.FREQ_THRES_SIGN1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_THRES1.bf.FREQ_THRES1", tmp_cfp->TXVCO0_THRES1.bf.FREQ_THRES1, tmp_cfp->TXVCO0_THRES1.bf.FREQ_THRES1 == dft_cfp->TXVCO0_THRES1.bf.FREQ_THRES1 ? 0x20 : 0x2A, dft_cfp->TXVCO0_THRES1.bf.FREQ_THRES1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_VCOMAX.wrd", tmp_cfp->TXVCO0_VCOMAX.wrd, tmp_cfp->TXVCO0_VCOMAX.wrd == dft_cfp->TXVCO0_VCOMAX.wrd ? 0x20 : 0x2A, dft_cfp->TXVCO0_VCOMAX.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_VCOMAX.bf.VCOMAX", tmp_cfp->TXVCO0_VCOMAX.bf.VCOMAX, tmp_cfp->TXVCO0_VCOMAX.bf.VCOMAX == dft_cfp->TXVCO0_VCOMAX.bf.VCOMAX ? 0x20 : 0x2A, dft_cfp->TXVCO0_VCOMAX.bf.VCOMAX, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_CONTROL.wrd", tmp_cfp->TXVCO0_CONTROL.wrd, tmp_cfp->TXVCO0_CONTROL.wrd == dft_cfp->TXVCO0_CONTROL.wrd ? 0x20 : 0x2A, dft_cfp->TXVCO0_CONTROL.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_CONTROL.bf.INIT", tmp_cfp->TXVCO0_CONTROL.bf.INIT, tmp_cfp->TXVCO0_CONTROL.bf.INIT == dft_cfp->TXVCO0_CONTROL.bf.INIT ? 0x20 : 0x2A, dft_cfp->TXVCO0_CONTROL.bf.INIT, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_CONTROL.bf.SHORT_OVRIDE", tmp_cfp->TXVCO0_CONTROL.bf.SHORT_OVRIDE, tmp_cfp->TXVCO0_CONTROL.bf.SHORT_OVRIDE == dft_cfp->TXVCO0_CONTROL.bf.SHORT_OVRIDE ? 0x20 : 0x2A, dft_cfp->TXVCO0_CONTROL.bf.SHORT_OVRIDE, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_STATUS.wrd", tmp_cfp->TXVCO0_STATUS.wrd, tmp_cfp->TXVCO0_STATUS.wrd == dft_cfp->TXVCO0_STATUS.wrd ? 0x20 : 0x2A, dft_cfp->TXVCO0_STATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_STATUS.bf.FREQ", tmp_cfp->TXVCO0_STATUS.bf.FREQ, tmp_cfp->TXVCO0_STATUS.bf.FREQ == dft_cfp->TXVCO0_STATUS.bf.FREQ ? 0x20 : 0x2A, dft_cfp->TXVCO0_STATUS.bf.FREQ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_INTERRUPT.wrd", tmp_cfp->TXVCO0_INTERRUPT.wrd, tmp_cfp->TXVCO0_INTERRUPT.wrd == dft_cfp->TXVCO0_INTERRUPT.wrd ? 0x20 : 0x2A, dft_cfp->TXVCO0_INTERRUPT.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_INTERRUPT.bf.SHORT_FILTPNi", tmp_cfp->TXVCO0_INTERRUPT.bf.SHORT_FILTPNi, tmp_cfp->TXVCO0_INTERRUPT.bf.SHORT_FILTPNi == dft_cfp->TXVCO0_INTERRUPT.bf.SHORT_FILTPNi ? 0x20 : 0x2A, dft_cfp->TXVCO0_INTERRUPT.bf.SHORT_FILTPNi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_INTSTATUS.wrd", tmp_cfp->TXVCO0_INTSTATUS.wrd, tmp_cfp->TXVCO0_INTSTATUS.wrd == dft_cfp->TXVCO0_INTSTATUS.wrd ? 0x20 : 0x2A, dft_cfp->TXVCO0_INTSTATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_INTSTATUS.bf.SHORT_FILTPNs", tmp_cfp->TXVCO0_INTSTATUS.bf.SHORT_FILTPNs, tmp_cfp->TXVCO0_INTSTATUS.bf.SHORT_FILTPNs == dft_cfp->TXVCO0_INTSTATUS.bf.SHORT_FILTPNs ? 0x20 : 0x2A, dft_cfp->TXVCO0_INTSTATUS.bf.SHORT_FILTPNs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_INTENABLE.wrd", tmp_cfp->TXVCO0_INTENABLE.wrd, tmp_cfp->TXVCO0_INTENABLE.wrd == dft_cfp->TXVCO0_INTENABLE.wrd ? 0x20 : 0x2A, dft_cfp->TXVCO0_INTENABLE.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_INTENABLE.bf.SHORT_FILTPNe", tmp_cfp->TXVCO0_INTENABLE.bf.SHORT_FILTPNe, tmp_cfp->TXVCO0_INTENABLE.bf.SHORT_FILTPNe == dft_cfp->TXVCO0_INTENABLE.bf.SHORT_FILTPNe ? 0x20 : 0x2A, dft_cfp->TXVCO0_INTENABLE.bf.SHORT_FILTPNe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_INTERRUPTZ.wrd", tmp_cfp->TXVCO0_INTERRUPTZ.wrd, tmp_cfp->TXVCO0_INTERRUPTZ.wrd == dft_cfp->TXVCO0_INTERRUPTZ.wrd ? 0x20 : 0x2A, dft_cfp->TXVCO0_INTERRUPTZ.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ", tmp_cfp->TXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ, tmp_cfp->TXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ == dft_cfp->TXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ ? 0x20 : 0x2A, dft_cfp->TXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_FILTER.wrd", tmp_cfp->TXLOCKD0_FILTER.wrd, tmp_cfp->TXLOCKD0_FILTER.wrd == dft_cfp->TXLOCKD0_FILTER.wrd ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_FILTER.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_FILTER.bf.STABLE_PERIOD", tmp_cfp->TXLOCKD0_FILTER.bf.STABLE_PERIOD, tmp_cfp->TXLOCKD0_FILTER.bf.STABLE_PERIOD == dft_cfp->TXLOCKD0_FILTER.bf.STABLE_PERIOD ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_FILTER.bf.STABLE_PERIOD, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPT.wrd", tmp_cfp->TXLOCKD0_INTERRUPT.wrd, tmp_cfp->TXLOCKD0_INTERRUPT.wrd == dft_cfp->TXLOCKD0_INTERRUPT.wrd ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPT.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPT.bf.FILT_LOCKi", tmp_cfp->TXLOCKD0_INTERRUPT.bf.FILT_LOCKi, tmp_cfp->TXLOCKD0_INTERRUPT.bf.FILT_LOCKi == dft_cfp->TXLOCKD0_INTERRUPT.bf.FILT_LOCKi ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPT.bf.FILT_LOCKi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPT.bf.CIDONEi", tmp_cfp->TXLOCKD0_INTERRUPT.bf.CIDONEi, tmp_cfp->TXLOCKD0_INTERRUPT.bf.CIDONEi == dft_cfp->TXLOCKD0_INTERRUPT.bf.CIDONEi ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPT.bf.CIDONEi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPT.bf.CIDZEROi", tmp_cfp->TXLOCKD0_INTERRUPT.bf.CIDZEROi, tmp_cfp->TXLOCKD0_INTERRUPT.bf.CIDZEROi == dft_cfp->TXLOCKD0_INTERRUPT.bf.CIDZEROi ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPT.bf.CIDZEROi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPT.bf.DATA_DETi", tmp_cfp->TXLOCKD0_INTERRUPT.bf.DATA_DETi, tmp_cfp->TXLOCKD0_INTERRUPT.bf.DATA_DETi == dft_cfp->TXLOCKD0_INTERRUPT.bf.DATA_DETi ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPT.bf.DATA_DETi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi", tmp_cfp->TXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi, tmp_cfp->TXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi == dft_cfp->TXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi", tmp_cfp->TXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi, tmp_cfp->TXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi == dft_cfp->TXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPT.bf.LOCKi", tmp_cfp->TXLOCKD0_INTERRUPT.bf.LOCKi, tmp_cfp->TXLOCKD0_INTERRUPT.bf.LOCKi == dft_cfp->TXLOCKD0_INTERRUPT.bf.LOCKi ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPT.bf.LOCKi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTSTATUS.wrd", tmp_cfp->TXLOCKD0_INTSTATUS.wrd, tmp_cfp->TXLOCKD0_INTSTATUS.wrd == dft_cfp->TXLOCKD0_INTSTATUS.wrd ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTSTATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTSTATUS.bf.FILT_LOCKs", tmp_cfp->TXLOCKD0_INTSTATUS.bf.FILT_LOCKs, tmp_cfp->TXLOCKD0_INTSTATUS.bf.FILT_LOCKs == dft_cfp->TXLOCKD0_INTSTATUS.bf.FILT_LOCKs ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTSTATUS.bf.FILT_LOCKs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTSTATUS.bf.CIDONEs", tmp_cfp->TXLOCKD0_INTSTATUS.bf.CIDONEs, tmp_cfp->TXLOCKD0_INTSTATUS.bf.CIDONEs == dft_cfp->TXLOCKD0_INTSTATUS.bf.CIDONEs ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTSTATUS.bf.CIDONEs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTSTATUS.bf.CIDZEROs", tmp_cfp->TXLOCKD0_INTSTATUS.bf.CIDZEROs, tmp_cfp->TXLOCKD0_INTSTATUS.bf.CIDZEROs == dft_cfp->TXLOCKD0_INTSTATUS.bf.CIDZEROs ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTSTATUS.bf.CIDZEROs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTSTATUS.bf.DATA_DETs", tmp_cfp->TXLOCKD0_INTSTATUS.bf.DATA_DETs, tmp_cfp->TXLOCKD0_INTSTATUS.bf.DATA_DETs == dft_cfp->TXLOCKD0_INTSTATUS.bf.DATA_DETs ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTSTATUS.bf.DATA_DETs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs", tmp_cfp->TXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs, tmp_cfp->TXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs == dft_cfp->TXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs", tmp_cfp->TXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs, tmp_cfp->TXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs == dft_cfp->TXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTSTATUS.bf.LOCKs", tmp_cfp->TXLOCKD0_INTSTATUS.bf.LOCKs, tmp_cfp->TXLOCKD0_INTSTATUS.bf.LOCKs == dft_cfp->TXLOCKD0_INTSTATUS.bf.LOCKs ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTSTATUS.bf.LOCKs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTENABLE.wrd", tmp_cfp->TXLOCKD0_INTENABLE.wrd, tmp_cfp->TXLOCKD0_INTENABLE.wrd == dft_cfp->TXLOCKD0_INTENABLE.wrd ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTENABLE.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTENABLE.bf.FILT_LOCKe", tmp_cfp->TXLOCKD0_INTENABLE.bf.FILT_LOCKe, tmp_cfp->TXLOCKD0_INTENABLE.bf.FILT_LOCKe == dft_cfp->TXLOCKD0_INTENABLE.bf.FILT_LOCKe ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTENABLE.bf.FILT_LOCKe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTENABLE.bf.CIDONEe", tmp_cfp->TXLOCKD0_INTENABLE.bf.CIDONEe, tmp_cfp->TXLOCKD0_INTENABLE.bf.CIDONEe == dft_cfp->TXLOCKD0_INTENABLE.bf.CIDONEe ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTENABLE.bf.CIDONEe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTENABLE.bf.CIDZEROe", tmp_cfp->TXLOCKD0_INTENABLE.bf.CIDZEROe, tmp_cfp->TXLOCKD0_INTENABLE.bf.CIDZEROe == dft_cfp->TXLOCKD0_INTENABLE.bf.CIDZEROe ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTENABLE.bf.CIDZEROe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTENABLE.bf.DATA_DETe", tmp_cfp->TXLOCKD0_INTENABLE.bf.DATA_DETe, tmp_cfp->TXLOCKD0_INTENABLE.bf.DATA_DETe == dft_cfp->TXLOCKD0_INTENABLE.bf.DATA_DETe ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTENABLE.bf.DATA_DETe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTENABLE.bf.SHORT_FILTPNe", tmp_cfp->TXLOCKD0_INTENABLE.bf.SHORT_FILTPNe, tmp_cfp->TXLOCKD0_INTENABLE.bf.SHORT_FILTPNe == dft_cfp->TXLOCKD0_INTENABLE.bf.SHORT_FILTPNe ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTENABLE.bf.SHORT_FILTPNe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe", tmp_cfp->TXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe, tmp_cfp->TXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe == dft_cfp->TXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTENABLE.bf.LOCKe", tmp_cfp->TXLOCKD0_INTENABLE.bf.LOCKe, tmp_cfp->TXLOCKD0_INTENABLE.bf.LOCKe == dft_cfp->TXLOCKD0_INTENABLE.bf.LOCKe ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTENABLE.bf.LOCKe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPTZ.wrd", tmp_cfp->TXLOCKD0_INTERRUPTZ.wrd, tmp_cfp->TXLOCKD0_INTERRUPTZ.wrd == dft_cfp->TXLOCKD0_INTERRUPTZ.wrd ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPTZ.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ", tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ, tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ == dft_cfp->TXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPTZ.bf.CIDONEiZ", tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.CIDONEiZ, tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.CIDONEiZ == dft_cfp->TXLOCKD0_INTERRUPTZ.bf.CIDONEiZ ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPTZ.bf.CIDONEiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPTZ.bf.CIDZEROiZ", tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.CIDZEROiZ, tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.CIDZEROiZ == dft_cfp->TXLOCKD0_INTERRUPTZ.bf.CIDZEROiZ ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPTZ.bf.CIDZEROiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ", tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ, tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ == dft_cfp->TXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ", tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ, tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ == dft_cfp->TXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ", tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ, tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ == dft_cfp->TXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKD0_INTERRUPTZ.bf.LOCKiZ", tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.LOCKiZ, tmp_cfp->TXLOCKD0_INTERRUPTZ.bf.LOCKiZ == dft_cfp->TXLOCKD0_INTERRUPTZ.bf.LOCKiZ ? 0x20 : 0x2A, dft_cfp->TXLOCKD0_INTERRUPTZ.bf.LOCKiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCOLEVEL0_OSTATUS.wrd", tmp_cfp->TXVCOLEVEL0_OSTATUS.wrd, tmp_cfp->TXVCOLEVEL0_OSTATUS.wrd == dft_cfp->TXVCOLEVEL0_OSTATUS.wrd ? 0x20 : 0x2A, dft_cfp->TXVCOLEVEL0_OSTATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS", tmp_cfp->TXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS, tmp_cfp->TXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS == dft_cfp->TXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS ? 0x20 : 0x2A, dft_cfp->TXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCOLEVEL0_CSTATUS.wrd", tmp_cfp->TXVCOLEVEL0_CSTATUS.wrd, tmp_cfp->TXVCOLEVEL0_CSTATUS.wrd == dft_cfp->TXVCOLEVEL0_CSTATUS.wrd ? 0x20 : 0x2A, dft_cfp->TXVCOLEVEL0_CSTATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS", tmp_cfp->TXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS, tmp_cfp->TXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS == dft_cfp->TXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS ? 0x20 : 0x2A, dft_cfp->TXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXELST0_CONTROL.wrd", tmp_cfp->RXELST0_Control.wrd, tmp_cfp->RXELST0_Control.wrd == dft_cfp->RXELST0_Control.wrd ? 0x20 : 0x2A, dft_cfp->RXELST0_Control.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXELST0_CONTROL.bf.use_lockdet", tmp_cfp->RXELST0_Control.bf.use_lockdet, tmp_cfp->RXELST0_Control.bf.use_lockdet == dft_cfp->RXELST0_Control.bf.use_lockdet ? 0x20 : 0x2A, dft_cfp->RXELST0_Control.bf.use_lockdet, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXELST0_CONTROL.bf.resync", tmp_cfp->RXELST0_Control.bf.resync, tmp_cfp->RXELST0_Control.bf.resync == dft_cfp->RXELST0_Control.bf.resync ? 0x20 : 0x2A, dft_cfp->RXELST0_Control.bf.resync, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXELST0_CONTROL.wrd", tmp_cfp->TXELST0_Control.wrd, tmp_cfp->TXELST0_Control.wrd == dft_cfp->TXELST0_Control.wrd ? 0x20 : 0x2A, dft_cfp->TXELST0_Control.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXELST0_CONTROL.bf.use_lockdet", tmp_cfp->TXELST0_Control.bf.use_lockdet, tmp_cfp->TXELST0_Control.bf.use_lockdet == dft_cfp->TXELST0_Control.bf.use_lockdet ? 0x20 : 0x2A, dft_cfp->TXELST0_Control.bf.use_lockdet, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXELST0_CONTROL.bf.resync", tmp_cfp->TXELST0_Control.bf.resync, tmp_cfp->TXELST0_Control.bf.resync == dft_cfp->TXELST0_Control.bf.resync ? 0x20 : 0x2A, dft_cfp->TXELST0_Control.bf.resync, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_CFG.wrd", tmp_cfp->PRBSGEN0_Cfg.wrd, tmp_cfp->PRBSGEN0_Cfg.wrd == dft_cfp->PRBSGEN0_Cfg.wrd ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Cfg.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_CFG.bf.prbs_mode", tmp_cfp->PRBSGEN0_Cfg.bf.prbs_mode, tmp_cfp->PRBSGEN0_Cfg.bf.prbs_mode == dft_cfp->PRBSGEN0_Cfg.bf.prbs_mode ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Cfg.bf.prbs_mode, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_CFG.bf.invertPrbs", tmp_cfp->PRBSGEN0_Cfg.bf.invertPrbs, tmp_cfp->PRBSGEN0_Cfg.bf.invertPrbs == dft_cfp->PRBSGEN0_Cfg.bf.invertPrbs ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Cfg.bf.invertPrbs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_CFG.bf.fixed_pattern", tmp_cfp->PRBSGEN0_Cfg.bf.fixed_pattern, tmp_cfp->PRBSGEN0_Cfg.bf.fixed_pattern == dft_cfp->PRBSGEN0_Cfg.bf.fixed_pattern ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Cfg.bf.fixed_pattern, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_CFG.bf.prbs_enable", tmp_cfp->PRBSGEN0_Cfg.bf.prbs_enable, tmp_cfp->PRBSGEN0_Cfg.bf.prbs_enable == dft_cfp->PRBSGEN0_Cfg.bf.prbs_enable ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Cfg.bf.prbs_enable, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_CTRL.wrd", tmp_cfp->PRBSGEN0_Ctrl.wrd, tmp_cfp->PRBSGEN0_Ctrl.wrd == dft_cfp->PRBSGEN0_Ctrl.wrd ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Ctrl.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_CTRL.bf.insertError", tmp_cfp->PRBSGEN0_Ctrl.bf.insertError, tmp_cfp->PRBSGEN0_Ctrl.bf.insertError == dft_cfp->PRBSGEN0_Ctrl.bf.insertError ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Ctrl.bf.insertError, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_CTRL.bf.insertOneBitError", tmp_cfp->PRBSGEN0_Ctrl.bf.insertOneBitError, tmp_cfp->PRBSGEN0_Ctrl.bf.insertOneBitError == dft_cfp->PRBSGEN0_Ctrl.bf.insertOneBitError ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Ctrl.bf.insertOneBitError, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_CTRL.bf.insertErrorOnce", tmp_cfp->PRBSGEN0_Ctrl.bf.insertErrorOnce, tmp_cfp->PRBSGEN0_Ctrl.bf.insertErrorOnce == dft_cfp->PRBSGEN0_Ctrl.bf.insertErrorOnce ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Ctrl.bf.insertErrorOnce, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_CTRL.bf.insertOneBitErrorOnce", tmp_cfp->PRBSGEN0_Ctrl.bf.insertOneBitErrorOnce, tmp_cfp->PRBSGEN0_Ctrl.bf.insertOneBitErrorOnce == dft_cfp->PRBSGEN0_Ctrl.bf.insertOneBitErrorOnce ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Ctrl.bf.insertOneBitErrorOnce, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_FIXED0_PATTERN1.wrd", tmp_cfp->PRBSGEN0_Fixed0_Pattern1.wrd, tmp_cfp->PRBSGEN0_Fixed0_Pattern1.wrd == dft_cfp->PRBSGEN0_Fixed0_Pattern1.wrd ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Fixed0_Pattern1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_FIXED0_PATTERN1.bf.VALUE1", tmp_cfp->PRBSGEN0_Fixed0_Pattern1.bf.VALUE1, tmp_cfp->PRBSGEN0_Fixed0_Pattern1.bf.VALUE1 == dft_cfp->PRBSGEN0_Fixed0_Pattern1.bf.VALUE1 ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Fixed0_Pattern1.bf.VALUE1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_FIXED0_PATTERN0.wrd", tmp_cfp->PRBSGEN0_Fixed0_Pattern0.wrd, tmp_cfp->PRBSGEN0_Fixed0_Pattern0.wrd == dft_cfp->PRBSGEN0_Fixed0_Pattern0.wrd ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Fixed0_Pattern0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_FIXED0_PATTERN0.bf.VALUE0", tmp_cfp->PRBSGEN0_Fixed0_Pattern0.bf.VALUE0, tmp_cfp->PRBSGEN0_Fixed0_Pattern0.bf.VALUE0 == dft_cfp->PRBSGEN0_Fixed0_Pattern0.bf.VALUE0 ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Fixed0_Pattern0.bf.VALUE0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_FIXED1_PATTERN1.wrd", tmp_cfp->PRBSGEN0_Fixed1_Pattern1.wrd, tmp_cfp->PRBSGEN0_Fixed1_Pattern1.wrd == dft_cfp->PRBSGEN0_Fixed1_Pattern1.wrd ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Fixed1_Pattern1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_FIXED1_PATTERN1.bf.VALUE1", tmp_cfp->PRBSGEN0_Fixed1_Pattern1.bf.VALUE1, tmp_cfp->PRBSGEN0_Fixed1_Pattern1.bf.VALUE1 == dft_cfp->PRBSGEN0_Fixed1_Pattern1.bf.VALUE1 ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Fixed1_Pattern1.bf.VALUE1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_FIXED1_PATTERN0.wrd", tmp_cfp->PRBSGEN0_Fixed1_Pattern0.wrd, tmp_cfp->PRBSGEN0_Fixed1_Pattern0.wrd == dft_cfp->PRBSGEN0_Fixed1_Pattern0.wrd ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Fixed1_Pattern0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_FIXED1_PATTERN0.bf.VALUE0", tmp_cfp->PRBSGEN0_Fixed1_Pattern0.bf.VALUE0, tmp_cfp->PRBSGEN0_Fixed1_Pattern0.bf.VALUE0 == dft_cfp->PRBSGEN0_Fixed1_Pattern0.bf.VALUE0 ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Fixed1_Pattern0.bf.VALUE0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_REPEAT_PATTERN.wrd", tmp_cfp->PRBSGEN0_Repeat_Pattern.wrd, tmp_cfp->PRBSGEN0_Repeat_Pattern.wrd == dft_cfp->PRBSGEN0_Repeat_Pattern.wrd ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Repeat_Pattern.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_REPEAT_PATTERN.bf.repeat1", tmp_cfp->PRBSGEN0_Repeat_Pattern.bf.repeat1, tmp_cfp->PRBSGEN0_Repeat_Pattern.bf.repeat1 == dft_cfp->PRBSGEN0_Repeat_Pattern.bf.repeat1 ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Repeat_Pattern.bf.repeat1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSGEN0_REPEAT_PATTERN.bf.repeat0", tmp_cfp->PRBSGEN0_Repeat_Pattern.bf.repeat0, tmp_cfp->PRBSGEN0_Repeat_Pattern.bf.repeat0 == dft_cfp->PRBSGEN0_Repeat_Pattern.bf.repeat0 ? 0x20 : 0x2A, dft_cfp->PRBSGEN0_Repeat_Pattern.bf.repeat0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_CFG.wrd", tmp_cfp->PRBSCHK0_Cfg.wrd, tmp_cfp->PRBSCHK0_Cfg.wrd == dft_cfp->PRBSCHK0_Cfg.wrd ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_Cfg.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_CFG.bf.prbs_mode", tmp_cfp->PRBSCHK0_Cfg.bf.prbs_mode, tmp_cfp->PRBSCHK0_Cfg.bf.prbs_mode == dft_cfp->PRBSCHK0_Cfg.bf.prbs_mode ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_Cfg.bf.prbs_mode, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_CFG.bf.invertPrbs", tmp_cfp->PRBSCHK0_Cfg.bf.invertPrbs, tmp_cfp->PRBSCHK0_Cfg.bf.invertPrbs == dft_cfp->PRBSCHK0_Cfg.bf.invertPrbs ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_Cfg.bf.invertPrbs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_CFG.bf.enable", tmp_cfp->PRBSCHK0_Cfg.bf.enable, tmp_cfp->PRBSCHK0_Cfg.bf.enable == dft_cfp->PRBSCHK0_Cfg.bf.enable ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_Cfg.bf.enable, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_CTRL.wrd", tmp_cfp->PRBSCHK0_Ctrl.wrd, tmp_cfp->PRBSCHK0_Ctrl.wrd == dft_cfp->PRBSCHK0_Ctrl.wrd ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_Ctrl.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_CTRL.bf.loadPrbsState", tmp_cfp->PRBSCHK0_Ctrl.bf.loadPrbsState, tmp_cfp->PRBSCHK0_Ctrl.bf.loadPrbsState == dft_cfp->PRBSCHK0_Ctrl.bf.loadPrbsState ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_Ctrl.bf.loadPrbsState, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_COUNT1.wrd", tmp_cfp->PRBSCHK0_Count1.wrd, tmp_cfp->PRBSCHK0_Count1.wrd == dft_cfp->PRBSCHK0_Count1.wrd ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_Count1.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_COUNT1.bf.VALUE1", tmp_cfp->PRBSCHK0_Count1.bf.VALUE1, tmp_cfp->PRBSCHK0_Count1.bf.VALUE1 == dft_cfp->PRBSCHK0_Count1.bf.VALUE1 ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_Count1.bf.VALUE1, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_COUNT0.wrd", tmp_cfp->PRBSCHK0_Count0.wrd, tmp_cfp->PRBSCHK0_Count0.wrd == dft_cfp->PRBSCHK0_Count0.wrd ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_Count0.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_COUNT0.bf.VALUE0", tmp_cfp->PRBSCHK0_Count0.bf.VALUE0, tmp_cfp->PRBSCHK0_Count0.bf.VALUE0 == dft_cfp->PRBSCHK0_Count0.bf.VALUE0 ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_Count0.bf.VALUE0, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTERRUPT.wrd", tmp_cfp->PRBSCHK0_INTERRUPT.wrd, tmp_cfp->PRBSCHK0_INTERRUPT.wrd == dft_cfp->PRBSCHK0_INTERRUPT.wrd ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTERRUPT.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTERRUPT.bf.PRBS_RX_EFi", tmp_cfp->PRBSCHK0_INTERRUPT.bf.PRBS_RX_EFi, tmp_cfp->PRBSCHK0_INTERRUPT.bf.PRBS_RX_EFi == dft_cfp->PRBSCHK0_INTERRUPT.bf.PRBS_RX_EFi ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTERRUPT.bf.PRBS_RX_EFi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTERRUPT.bf.PRBS_SYNCi", tmp_cfp->PRBSCHK0_INTERRUPT.bf.PRBS_SYNCi, tmp_cfp->PRBSCHK0_INTERRUPT.bf.PRBS_SYNCi == dft_cfp->PRBSCHK0_INTERRUPT.bf.PRBS_SYNCi ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTERRUPT.bf.PRBS_SYNCi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTSTATUS.wrd", tmp_cfp->PRBSCHK0_INTSTATUS.wrd, tmp_cfp->PRBSCHK0_INTSTATUS.wrd == dft_cfp->PRBSCHK0_INTSTATUS.wrd ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTSTATUS.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTSTATUS.bf.PRBS_SYNCs", tmp_cfp->PRBSCHK0_INTSTATUS.bf.PRBS_SYNCs, tmp_cfp->PRBSCHK0_INTSTATUS.bf.PRBS_SYNCs == dft_cfp->PRBSCHK0_INTSTATUS.bf.PRBS_SYNCs ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTSTATUS.bf.PRBS_SYNCs, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTENABLE.wrd", tmp_cfp->PRBSCHK0_INTENABLE.wrd, tmp_cfp->PRBSCHK0_INTENABLE.wrd == dft_cfp->PRBSCHK0_INTENABLE.wrd ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTENABLE.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTENABLE.bf.PRBS_RX_EFe", tmp_cfp->PRBSCHK0_INTENABLE.bf.PRBS_RX_EFe, tmp_cfp->PRBSCHK0_INTENABLE.bf.PRBS_RX_EFe == dft_cfp->PRBSCHK0_INTENABLE.bf.PRBS_RX_EFe ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTENABLE.bf.PRBS_RX_EFe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTENABLE.bf.PRBS_SYNCe", tmp_cfp->PRBSCHK0_INTENABLE.bf.PRBS_SYNCe, tmp_cfp->PRBSCHK0_INTENABLE.bf.PRBS_SYNCe == dft_cfp->PRBSCHK0_INTENABLE.bf.PRBS_SYNCe ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTENABLE.bf.PRBS_SYNCe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTERRUPTZ.wrd", tmp_cfp->PRBSCHK0_INTERRUPTZ.wrd, tmp_cfp->PRBSCHK0_INTERRUPTZ.wrd == dft_cfp->PRBSCHK0_INTERRUPTZ.wrd ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTERRUPTZ.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTERRUPTZ.bf.PRBS_RX_EFiZ", tmp_cfp->PRBSCHK0_INTERRUPTZ.bf.PRBS_RX_EFiZ, tmp_cfp->PRBSCHK0_INTERRUPTZ.bf.PRBS_RX_EFiZ == dft_cfp->PRBSCHK0_INTERRUPTZ.bf.PRBS_RX_EFiZ ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTERRUPTZ.bf.PRBS_RX_EFiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHK0_INTERRUPTZ.bf.PRBS_SYNCiZ", tmp_cfp->PRBSCHK0_INTERRUPTZ.bf.PRBS_SYNCiZ, tmp_cfp->PRBSCHK0_INTERRUPTZ.bf.PRBS_SYNCiZ == dft_cfp->PRBSCHK0_INTERRUPTZ.bf.PRBS_SYNCiZ ? 0x20 : 0x2A, dft_cfp->PRBSCHK0_INTERRUPTZ.bf.PRBS_SYNCiZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TX0_CONFIG.wrd", tmp_cfp->TX0_Config.wrd, tmp_cfp->TX0_Config.wrd == dft_cfp->TX0_Config.wrd ? 0x20 : 0x2A, dft_cfp->TX0_Config.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TX0_CONFIG.bf.bitinv", tmp_cfp->TX0_Config.bf.bitinv, tmp_cfp->TX0_Config.bf.bitinv == dft_cfp->TX0_Config.bf.bitinv ? 0x20 : 0x2A, dft_cfp->TX0_Config.bf.bitinv, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TX0_CONFIG.bf.data_source", tmp_cfp->TX0_Config.bf.data_source, tmp_cfp->TX0_Config.bf.data_source == dft_cfp->TX0_Config.bf.data_source ? 0x20 : 0x2A, dft_cfp->TX0_Config.bf.data_source, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RX0_CONFIG.wrd", tmp_cfp->RX0_Config.wrd, tmp_cfp->RX0_Config.wrd == dft_cfp->RX0_Config.wrd ? 0x20 : 0x2A, dft_cfp->RX0_Config.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RX0_CONFIG.bf.bitinv", tmp_cfp->RX0_Config.bf.bitinv, tmp_cfp->RX0_Config.bf.bitinv == dft_cfp->RX0_Config.bf.bitinv ? 0x20 : 0x2A, dft_cfp->RX0_Config.bf.bitinv, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RX0_CONFIG.bf.data_source", tmp_cfp->RX0_Config.bf.data_source, tmp_cfp->RX0_Config.bf.data_source == dft_cfp->RX0_Config.bf.data_source ? 0x20 : 0x2A, dft_cfp->RX0_Config.bf.data_source, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INT.wrd", tmp_cfp->Int.wrd, tmp_cfp->Int.wrd == dft_cfp->Int.wrd ? 0x20 : 0x2A, dft_cfp->Int.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INT.bf.PRBSCHKi", tmp_cfp->Int.bf.PRBSCHKi, tmp_cfp->Int.bf.PRBSCHKi == dft_cfp->Int.bf.PRBSCHKi ? 0x20 : 0x2A, dft_cfp->Int.bf.PRBSCHKi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INT.bf.TXELSTi", tmp_cfp->Int.bf.TXELSTi, tmp_cfp->Int.bf.TXELSTi == dft_cfp->Int.bf.TXELSTi ? 0x20 : 0x2A, dft_cfp->Int.bf.TXELSTi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INT.bf.TXLOCKDi", tmp_cfp->Int.bf.TXLOCKDi, tmp_cfp->Int.bf.TXLOCKDi == dft_cfp->Int.bf.TXLOCKDi ? 0x20 : 0x2A, dft_cfp->Int.bf.TXLOCKDi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INT.bf.TXVCOi", tmp_cfp->Int.bf.TXVCOi, tmp_cfp->Int.bf.TXVCOi == dft_cfp->Int.bf.TXVCOi ? 0x20 : 0x2A, dft_cfp->Int.bf.TXVCOi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INT.bf.RXELSTi", tmp_cfp->Int.bf.RXELSTi, tmp_cfp->Int.bf.RXELSTi == dft_cfp->Int.bf.RXELSTi ? 0x20 : 0x2A, dft_cfp->Int.bf.RXELSTi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INT.bf.RXLOCKDi", tmp_cfp->Int.bf.RXLOCKDi, tmp_cfp->Int.bf.RXLOCKDi == dft_cfp->Int.bf.RXLOCKDi ? 0x20 : 0x2A, dft_cfp->Int.bf.RXLOCKDi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INT.bf.RXVCOi", tmp_cfp->Int.bf.RXVCOi, tmp_cfp->Int.bf.RXVCOi == dft_cfp->Int.bf.RXVCOi ? 0x20 : 0x2A, dft_cfp->Int.bf.RXVCOi, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INTEN.wrd", tmp_cfp->IntEn.wrd, tmp_cfp->IntEn.wrd == dft_cfp->IntEn.wrd ? 0x20 : 0x2A, dft_cfp->IntEn.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INTEN.bf.PRBSCHKe", tmp_cfp->IntEn.bf.PRBSCHKe, tmp_cfp->IntEn.bf.PRBSCHKe == dft_cfp->IntEn.bf.PRBSCHKe ? 0x20 : 0x2A, dft_cfp->IntEn.bf.PRBSCHKe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INTEN.bf.TXELSTe", tmp_cfp->IntEn.bf.TXELSTe, tmp_cfp->IntEn.bf.TXELSTe == dft_cfp->IntEn.bf.TXELSTe ? 0x20 : 0x2A, dft_cfp->IntEn.bf.TXELSTe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INTEN.bf.TXLOCKDe", tmp_cfp->IntEn.bf.TXLOCKDe, tmp_cfp->IntEn.bf.TXLOCKDe == dft_cfp->IntEn.bf.TXLOCKDe ? 0x20 : 0x2A, dft_cfp->IntEn.bf.TXLOCKDe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INTEN.bf.TXVCOe", tmp_cfp->IntEn.bf.TXVCOe, tmp_cfp->IntEn.bf.TXVCOe == dft_cfp->IntEn.bf.TXVCOe ? 0x20 : 0x2A, dft_cfp->IntEn.bf.TXVCOe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INTEN.bf.RXELSTe", tmp_cfp->IntEn.bf.RXELSTe, tmp_cfp->IntEn.bf.RXELSTe == dft_cfp->IntEn.bf.RXELSTe ? 0x20 : 0x2A, dft_cfp->IntEn.bf.RXELSTe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INTEN.bf.RXLOCKDe", tmp_cfp->IntEn.bf.RXLOCKDe, tmp_cfp->IntEn.bf.RXLOCKDe == dft_cfp->IntEn.bf.RXLOCKDe ? 0x20 : 0x2A, dft_cfp->IntEn.bf.RXLOCKDe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_INTEN.bf.RXVCOe", tmp_cfp->IntEn.bf.RXVCOe, tmp_cfp->IntEn.bf.RXVCOe == dft_cfp->IntEn.bf.RXVCOe ? 0x20 : 0x2A, dft_cfp->IntEn.bf.RXVCOe, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHKI.wrd", tmp_cfp->PRBSCHKi.wrd, tmp_cfp->PRBSCHKi.wrd == dft_cfp->PRBSCHKi.wrd ? 0x20 : 0x2A, dft_cfp->PRBSCHKi.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHKI.bf.PRBSCHK0i", tmp_cfp->PRBSCHKi.bf.PRBSCHK0i, tmp_cfp->PRBSCHKi.bf.PRBSCHK0i == dft_cfp->PRBSCHKi.bf.PRBSCHK0i ? 0x20 : 0x2A, dft_cfp->PRBSCHKi.bf.PRBSCHK0i, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHKE.wrd", tmp_cfp->PRBSCHKe.wrd, tmp_cfp->PRBSCHKe.wrd == dft_cfp->PRBSCHKe.wrd ? 0x20 : 0x2A, dft_cfp->PRBSCHKe.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_PRBSCHKE.bf.PRBSCHK0e", tmp_cfp->PRBSCHKe.bf.PRBSCHK0e, tmp_cfp->PRBSCHKe.bf.PRBSCHK0e == dft_cfp->PRBSCHKe.bf.PRBSCHK0e ? 0x20 : 0x2A, dft_cfp->PRBSCHKe.bf.PRBSCHK0e, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXELSTI.wrd", tmp_cfp->RXELSTi.wrd, tmp_cfp->RXELSTi.wrd == dft_cfp->RXELSTi.wrd ? 0x20 : 0x2A, dft_cfp->RXELSTi.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXELSTI.bf.RXELST0i", tmp_cfp->RXELSTi.bf.RXELST0i, tmp_cfp->RXELSTi.bf.RXELST0i == dft_cfp->RXELSTi.bf.RXELST0i ? 0x20 : 0x2A, dft_cfp->RXELSTi.bf.RXELST0i, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXELSTE.wrd", tmp_cfp->RXELSTe.wrd, tmp_cfp->RXELSTe.wrd == dft_cfp->RXELSTe.wrd ? 0x20 : 0x2A, dft_cfp->RXELSTe.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXELSTE.bf.RXELST0e", tmp_cfp->RXELSTe.bf.RXELST0e, tmp_cfp->RXELSTe.bf.RXELST0e == dft_cfp->RXELSTe.bf.RXELST0e ? 0x20 : 0x2A, dft_cfp->RXELSTe.bf.RXELST0e, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXELSTZ.wrd", tmp_cfp->RXELSTZ.wrd, tmp_cfp->RXELSTZ.wrd == dft_cfp->RXELSTZ.wrd ? 0x20 : 0x2A, dft_cfp->RXELSTZ.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXELSTZ.bf.RXELST0iZ", tmp_cfp->RXELSTZ.bf.RXELST0iZ, tmp_cfp->RXELSTZ.bf.RXELST0iZ == dft_cfp->RXELSTZ.bf.RXELST0iZ ? 0x20 : 0x2A, dft_cfp->RXELSTZ.bf.RXELST0iZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCOI.wrd", tmp_cfp->RXVCOi.wrd, tmp_cfp->RXVCOi.wrd == dft_cfp->RXVCOi.wrd ? 0x20 : 0x2A, dft_cfp->RXVCOi.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCOI.bf.RXVCO0i", tmp_cfp->RXVCOi.bf.RXVCO0i, tmp_cfp->RXVCOi.bf.RXVCO0i == dft_cfp->RXVCOi.bf.RXVCO0i ? 0x20 : 0x2A, dft_cfp->RXVCOi.bf.RXVCO0i, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCOE.wrd", tmp_cfp->RXVCOe.wrd, tmp_cfp->RXVCOe.wrd == dft_cfp->RXVCOe.wrd ? 0x20 : 0x2A, dft_cfp->RXVCOe.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXVCOE.bf.RXVCO0e", tmp_cfp->RXVCOe.bf.RXVCO0e, tmp_cfp->RXVCOe.bf.RXVCO0e == dft_cfp->RXVCOe.bf.RXVCO0e ? 0x20 : 0x2A, dft_cfp->RXVCOe.bf.RXVCO0e, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKDI.wrd", tmp_cfp->RXLOCKDi.wrd, tmp_cfp->RXLOCKDi.wrd == dft_cfp->RXLOCKDi.wrd ? 0x20 : 0x2A, dft_cfp->RXLOCKDi.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKDI.bf.RXLOCKD0i", tmp_cfp->RXLOCKDi.bf.RXLOCKD0i, tmp_cfp->RXLOCKDi.bf.RXLOCKD0i == dft_cfp->RXLOCKDi.bf.RXLOCKD0i ? 0x20 : 0x2A, dft_cfp->RXLOCKDi.bf.RXLOCKD0i, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKDE.wrd", tmp_cfp->RXLOCKDe.wrd, tmp_cfp->RXLOCKDe.wrd == dft_cfp->RXLOCKDe.wrd ? 0x20 : 0x2A, dft_cfp->RXLOCKDe.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_RXLOCKDE.bf.RXLOCKD0e", tmp_cfp->RXLOCKDe.bf.RXLOCKD0e, tmp_cfp->RXLOCKDe.bf.RXLOCKD0e == dft_cfp->RXLOCKDe.bf.RXLOCKD0e ? 0x20 : 0x2A, dft_cfp->RXLOCKDe.bf.RXLOCKD0e, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXELSTI.wrd", tmp_cfp->TXELSTi.wrd, tmp_cfp->TXELSTi.wrd == dft_cfp->TXELSTi.wrd ? 0x20 : 0x2A, dft_cfp->TXELSTi.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXELSTI.bf.TXELST0i", tmp_cfp->TXELSTi.bf.TXELST0i, tmp_cfp->TXELSTi.bf.TXELST0i == dft_cfp->TXELSTi.bf.TXELST0i ? 0x20 : 0x2A, dft_cfp->TXELSTi.bf.TXELST0i, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXELSTE.wrd", tmp_cfp->TXELSTe.wrd, tmp_cfp->TXELSTe.wrd == dft_cfp->TXELSTe.wrd ? 0x20 : 0x2A, dft_cfp->TXELSTe.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXELSTE.bf.TXELST0e", tmp_cfp->TXELSTe.bf.TXELST0e, tmp_cfp->TXELSTe.bf.TXELST0e == dft_cfp->TXELSTe.bf.TXELST0e ? 0x20 : 0x2A, dft_cfp->TXELSTe.bf.TXELST0e, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXELSTZ.wrd", tmp_cfp->TXELSTZ.wrd, tmp_cfp->TXELSTZ.wrd == dft_cfp->TXELSTZ.wrd ? 0x20 : 0x2A, dft_cfp->TXELSTZ.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXELSTZ.bf.TXELST0iZ", tmp_cfp->TXELSTZ.bf.TXELST0iZ, tmp_cfp->TXELSTZ.bf.TXELST0iZ == dft_cfp->TXELSTZ.bf.TXELST0iZ ? 0x20 : 0x2A, dft_cfp->TXELSTZ.bf.TXELST0iZ, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCOI.wrd", tmp_cfp->TXVCOi.wrd, tmp_cfp->TXVCOi.wrd == dft_cfp->TXVCOi.wrd ? 0x20 : 0x2A, dft_cfp->TXVCOi.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCOI.bf.TXVCO0i", tmp_cfp->TXVCOi.bf.TXVCO0i, tmp_cfp->TXVCOi.bf.TXVCO0i == dft_cfp->TXVCOi.bf.TXVCO0i ? 0x20 : 0x2A, dft_cfp->TXVCOi.bf.TXVCO0i, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCOE.wrd", tmp_cfp->TXVCOe.wrd, tmp_cfp->TXVCOe.wrd == dft_cfp->TXVCOe.wrd ? 0x20 : 0x2A, dft_cfp->TXVCOe.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXVCOE.bf.TXVCO0e", tmp_cfp->TXVCOe.bf.TXVCO0e, tmp_cfp->TXVCOe.bf.TXVCO0e == dft_cfp->TXVCOe.bf.TXVCO0e ? 0x20 : 0x2A, dft_cfp->TXVCOe.bf.TXVCO0e, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKDI.wrd", tmp_cfp->TXLOCKDi.wrd, tmp_cfp->TXLOCKDi.wrd == dft_cfp->TXLOCKDi.wrd ? 0x20 : 0x2A, dft_cfp->TXLOCKDi.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKDI.bf.TXLOCKD0i", tmp_cfp->TXLOCKDi.bf.TXLOCKD0i, tmp_cfp->TXLOCKDi.bf.TXLOCKD0i == dft_cfp->TXLOCKDi.bf.TXLOCKD0i ? 0x20 : 0x2A, dft_cfp->TXLOCKDi.bf.TXLOCKD0i, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKDE.wrd", tmp_cfp->TXLOCKDe.wrd, tmp_cfp->TXLOCKDe.wrd == dft_cfp->TXLOCKDe.wrd ? 0x20 : 0x2A, dft_cfp->TXLOCKDe.wrd, ch1, ch2);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   %c%c\n", "CFP32X1_TXLOCKDE.bf.TXLOCKD0e", tmp_cfp->TXLOCKDe.bf.TXLOCKD0e, tmp_cfp->TXLOCKDe.bf.TXLOCKD0e == dft_cfp->TXLOCKDe.bf.TXLOCKD0e ? 0x20 : 0x2A, dft_cfp->TXLOCKDe.bf.TXLOCKD0e, ch1, ch2);
    }   
  } 
  
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
                                                                                                                                                   
  CS_FREE(tmp_cfp);                                                                                                             
  CS_FREE(dft_cfp); 
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
                                                                                                                                                      
  return (CS_OK);                                                                                                                                      
}                                                                                                                                                      
                                                                                                                                                       
