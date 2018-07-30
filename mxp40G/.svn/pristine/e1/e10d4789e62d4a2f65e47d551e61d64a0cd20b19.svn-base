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
 * ten_debug_mpif.c
 *
 * APIs for debugging ASIC, MPIF, GLB, SPOH, GPLLX1.
 *
 * $Id: ten_debug_mpif.c,v 1.29 2014/04/03 20:19:35 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  DEV DUMP SETTINGS                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_dev_dump_settings(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays the entire dev's current register settings.             */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  cs_uint16 module_id_a, module_id_b;
  
  module_id_a = (dev_id << 8) | TEN_MODULE_A;
  module_id_b = (dev_id << 8) | TEN_MODULE_B;

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  ten_debug_mpif_dump_settings(dev_id);
  ten_debug_glb_dump_settings(dev_id);
  
  /* Bugzilla #32197, Add T41 registers */
  ten_debug_dm_dump_settings(dev_id);
  ten_debug_pdcal_dump_settings(dev_id);
  
  ten_debug_frac_div_dump_settings(dev_id);
  ten_debug_syncdsync_dump_settings(module_id_a, TEN_SLICE_ALL);
  ten_debug_syncdsync_dump_settings(module_id_b, TEN_SLICE_ALL);
  ten_debug_gpllx1_dump_settings(dev_id);
  ten_debug_spoh_dump_settings(dev_id);
  ten_debug_hsif_dump_settings(module_id_a);
  ten_debug_hsif_dump_settings(module_id_b);

  /* Bugzilla #24746, debug api to show entire device */
  ten_debug_hsif_slc0_mr10x4_dump_settings(module_id_a);
  ten_debug_hsif_slc1_mr10x5_dump_settings(module_id_a);
  ten_debug_hsif_slc2_mr10x4_dump_settings(module_id_a);
  ten_debug_hsif_slc3_mr10x5_dump_settings(module_id_a);

  ten_debug_hsif_slc0_mr10x4_dump_settings(module_id_b);
  ten_debug_hsif_slc1_mr10x5_dump_settings(module_id_b);
  ten_debug_hsif_slc2_mr10x4_dump_settings(module_id_b);
  ten_debug_hsif_slc3_mr10x5_dump_settings(module_id_b);

  ten_debug_xfi_dump_settings(module_id_b, TEN_SLICE_ALL);
  ten_debug_xcon_dump_settings(dev_id);
  ten_debug_gfec40g_dump_settings(module_id_a);
  ten_debug_gfec40g_dump_settings(module_id_b);
  ten_debug_gfec10g_dump_settings(module_id_a, TEN_SLICE_ALL);
  ten_debug_gfec10g_dump_settings(module_id_b, TEN_SLICE_ALL);
  ten_debug_ufec_dump_settings(module_id_a, TEN_SLICE_ALL);
  ten_debug_n40g_dump_settings(module_id_a);
  ten_debug_n40g_oohr_dump_settings(module_id_a);
  ten_debug_n40g_dump_settings(module_id_b);
  ten_debug_n40g_oohr_dump_settings(module_id_b);
  
  ten_debug_ohpp_dump_settings(module_id_a);
  ten_debug_ohpp_dump_settings(module_id_b);
  ten_debug_n10g_dump_settings(module_id_a, TEN_SLICE_ALL);
  ten_debug_n10g_oohr_dump_settings(module_id_a, TEN_SLICE_ALL);
  ten_debug_n10g_dump_settings(module_id_b, TEN_SLICE_ALL);
  ten_debug_n10g_oohr_dump_settings(module_id_b, TEN_SLICE_ALL);
  ten_debug_pp10g_dump_settings(module_id_a, TEN_SLICE_ALL);
  ten_debug_pp10g_dump_settings(module_id_b, TEN_SLICE_ALL);

  ten_debug_pp40g_dump_settings(module_id_a);
  ten_debug_pp40g_dump_settings(module_id_b);
  
  ten_debug_cfp_dump_settings(module_id_a, TEN_SLICE_ALL);
  ten_debug_cupll_dump_settings(module_id_a, TEN_SLICE_ALL);

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  return (CS_OK); 
}

/********************************************************************/
/* $rtn_hdr_start  DEV DUMP SETTINGS                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_dev_dump_module_settings(cs_uint16 dev_id, cs_uint16 module)
/* INPUTS     : o Device Id                                         */
/*              o Module                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays the entire dev's current register settings.             */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  cs_uint16 module_id;
  
  /* Bugzilla #28624, compiler warning */
  module_id = (dev_id << 8) | (module&1);

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  ten_debug_mpif_dump_settings(dev_id);
  ten_debug_glb_dump_settings(dev_id);
  ten_debug_frac_div_dump_settings(dev_id);
  ten_debug_syncdsync_dump_settings(module_id, TEN_SLICE_ALL);
  ten_debug_gpllx1_dump_settings(dev_id);
  ten_debug_spoh_dump_settings(dev_id);
  ten_debug_hsif_dump_settings(module_id);

  /* Bugzilla #24746, debug api to show entire device */
  ten_debug_hsif_slc0_mr10x4_dump_settings(module_id);
  ten_debug_hsif_slc1_mr10x5_dump_settings(module_id);
  ten_debug_hsif_slc2_mr10x4_dump_settings(module_id);
  ten_debug_hsif_slc3_mr10x5_dump_settings(module_id);


  if ((module_id & 1) == TEN_MODULE_B)
    ten_debug_xfi_dump_settings(module_id, TEN_SLICE_ALL);
  ten_debug_xcon_dump_settings(dev_id);
  ten_debug_gfec40g_dump_settings(module_id);
  ten_debug_gfec10g_dump_settings(module_id, TEN_SLICE_ALL);
  ten_debug_ufec_dump_settings(module_id, TEN_SLICE_ALL);
  ten_debug_n40g_dump_settings(module_id);
  ten_debug_n40g_oohr_dump_settings(module_id);
  
  ten_debug_ohpp_dump_settings(module_id);
  ten_debug_n10g_dump_settings(module_id, TEN_SLICE_ALL);
  ten_debug_n10g_oohr_dump_settings(module_id, TEN_SLICE_ALL);

  ten_debug_pp10g_dump_settings(module_id, TEN_SLICE_ALL);

  ten_debug_pp40g_dump_settings(module_id);
  
  if ((module_id & 1) == TEN_MODULE_A) {
    ten_debug_cfp_dump_settings(module_id, TEN_SLICE_ALL);
    ten_debug_cupll_dump_settings(module_id, TEN_SLICE_ALL);
  }

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  return (CS_OK); 
}


/********************************************************************/
/* $rtn_hdr_start  SLICE DUMP SETTINGS                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_slice_dump_settings(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays the entire dev's current register settings for a        */
/* given slice.                                                     */
/*                                                                  */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  } 
  
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  ten_debug_n10g_dump_settings(module_id, slice);
  ten_debug_pp10g_dump_settings(module_id, slice);

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  return (CS_OK); 
}

/********************************************************************/
/* $rtn_hdr_start  DEBUG HEALTH                                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_health(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays the health of the given module.                         */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  cs_uint16 tx_xfisel, rx_xfisel;
  cs_uint16 tx_mrsel, rx_mrsel;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  } 
  
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  /* Check HSIF */
  tx_xfisel = ten_hsif_get_provisioned_datapath(module_id, slice, TEN_HSIF_DATAPATH_PROV_XFISELECT, CS_TX);
  rx_xfisel = ten_hsif_get_provisioned_datapath(module_id, slice, TEN_HSIF_DATAPATH_PROV_XFISELECT, CS_RX);
                      
  tx_mrsel  = ten_hsif_get_provisioned_datapath(module_id, slice, TEN_HSIF_DATAPATH_PROV_MRPROTOCOL, CS_TX);
  rx_mrsel  = ten_hsif_get_provisioned_datapath(module_id, slice, TEN_HSIF_DATAPATH_PROV_MRPROTOCOL, CS_RX); 

  if ((tx_xfisel == 1) && (rx_xfisel == 1)) {
    CS_PRINT_OUTPUT("XFI_TXLOCKD0_INTSTATUS.FILT_LOCKs = %d\n", ten_hl_hsif_check_xfi_filt_lock(module_id, slice, CS_TX));
    CS_PRINT_OUTPUT("XFI_RXLOCKD0_INTSTATUS.FILT_LOCKs = %d\n", ten_hl_hsif_check_xfi_filt_lock(module_id, slice, CS_RX));
    
    CS_PRINT_OUTPUT("XFI_TXLOCKD0_INTSTATUS.DATA_DETs = %d\n", ten_xfi32x1_txlockd0_data_dets(module_id, slice));
    CS_PRINT_OUTPUT("XFI_RXLOCKD0_INTSTATUS.DATA_DETs = %d\n", ten_xfi32x1_rxlockd0_data_dets(module_id, slice));
   
    CS_PRINT_OUTPUT("XFI_SDS_COMMON_TXVCO0_STATUS.FREQ = %d\n", ten_xfi32x1_txvco0_status(module_id, slice));
    CS_PRINT_OUTPUT("XFI_SDS_COMMON_RXVCO0_STATUS.FREQ = %d\n", ten_xfi32x1_rxvco0_status(module_id, slice));
    
    CS_PRINT_OUTPUT("XFI MICROCODE RUNNING             = %d\n", ten_hl_hsif_xfi_check_micro_code_status(module_id, slice));
  }
  else {
    if ((tx_mrsel == TEN_HSIF_PROTOCOL_DISABLED) && (rx_mrsel == TEN_HSIF_PROTOCOL_DISABLED)) {
      CS_PRINT_OUTPUT("HSIF DISABLED\n");
    }
  }
  
  if ((tx_mrsel == TEN_HSIF_PROTOCOL_XAUI) && (rx_mrsel == TEN_HSIF_PROTOCOL_XAUI)) {
  }
  
  if ((tx_mrsel == TEN_HSIF_PROTOCOL_SFI42_10G) && (rx_mrsel == TEN_HSIF_PROTOCOL_SFI42_10G)) {
  }
  
  if ((tx_mrsel == TEN_HSIF_PROTOCOL_SFI42_40G) && (rx_mrsel == TEN_HSIF_PROTOCOL_SFI42_40G)) {
  }
  
  if ((tx_mrsel == TEN_HSIF_PROTOCOL_SFI51) && (rx_mrsel == TEN_HSIF_PROTOCOL_SFI51)) {
  }
  
  if ((tx_mrsel == TEN_HSIF_PROTOCOL_CFP) && (rx_mrsel == TEN_HSIF_PROTOCOL_CFP)) {
    CS_PRINT_OUTPUT("CFP32X1_SDS_COMMON_TXLOCKD0_INTSTATUS.FILT_LOCKs = %d\n", ten_cfp32x1_txlockd0_filt_lock_t41(module_id, slice));
    CS_PRINT_OUTPUT("CFP32X1_SDS_COMMON_RXLOCKD0_INTSTATUS.FILT_LOCKs = %d\n", ten_cfp32x1_rxlockd0_filt_lock_t41(module_id, slice));
    
    CS_PRINT_OUTPUT("CFP32X1_SDS_COMMON_TXLOCKD0_INTSTATUS.DATA_DETs = %d\n", ten_cfp32x1_txlockd0_data_dets_t41(module_id, slice));
    CS_PRINT_OUTPUT("CFP32X1_SDS_COMMON_RXLOCKD0_INTSTATUS.DATA_DETs = %d\n", ten_cfp32x1_rxlockd0_data_dets_t41(module_id, slice));

    CS_PRINT_OUTPUT("CFP32X1_SDS_COMMON_TXLOCKD0_INTSTATUS.LOCKs = %d\n", ten_cfp32x1_txlockd0_lock_t41(module_id, slice));
    CS_PRINT_OUTPUT("CFP32X1_SDS_COMMON_RXLOCKD0_INTSTATUS.LOCKs = %d\n", ten_cfp32x1_rxlockd0_lock_t41(module_id, slice));

    CS_PRINT_OUTPUT("CFP32X1_SDS_COMMON_TXVCO0_STATUS.FREQ = %d\n", ten_cfp32x1_txvco0_status_t41(module_id, slice));
    CS_PRINT_OUTPUT("CFP32X1_SDS_COMMON_RXVCO0_STATUS.FREQ = %d\n", ten_cfp32x1_rxvco0_status_t41(module_id, slice));
  }
  
  if ((tx_mrsel == TEN_HSIF_PROTOCOL_SFI41) && (rx_mrsel == TEN_HSIF_PROTOCOL_SFI41)) {
  }
 
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return (CS_OK); 
}


/********************************************************************/
/* $rtn_hdr_start  MPIF DUMP SETTINGS                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_mpif_dump_settings(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current MPIF settings.                                  */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  TEN_mpif_t *tmp_mpif, *dft_mpif;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
                                             
  tmp_mpif = (TEN_mpif_t *)CS_MALLOC(sizeof(TEN_mpif_t));
  dft_mpif = (TEN_mpif_t *)CS_MALLOC(sizeof(TEN_mpif_t));

  /* Bugzilla 28734 Klocwork fix, this block */
  /* Ckeck for failed alloc, return if failed. */
  if ((tmp_mpif == 0) || (dft_mpif == 0)) {
    if (tmp_mpif) {
      CS_FREE(tmp_mpif);
    }
    if (dft_mpif) {
      CS_FREE(dft_mpif);
    }
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  
  dft_mpif->CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft;
  dft_mpif->CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;
  dft_mpif->GLOBAL_CFG.wrd = TEN_MPIF_GLOBAL_CFG_dft;
  dft_mpif->GLOBAL_RESET_COMMON.wrd = TEN_MPIF_GLOBAL_RESET_COMMON_dft;
  dft_mpif->GLOBAL_RESET_HSIF.wrd = TEN_MPIF_GLOBAL_RESET_HSIF_dft;
  dft_mpif->GLOBAL_RESET_SDS_MRA.wrd = TEN_MPIF_GLOBAL_RESET_SDS_MRA_dft;
  dft_mpif->GLOBAL_RESET_SDS_MRB.wrd = TEN_MPIF_GLOBAL_RESET_SDS_MRB_dft;
  dft_mpif->GLOBAL_RESET_SDS_XFI.wrd = TEN_MPIF_GLOBAL_RESET_SDS_XFI_dft;
  dft_mpif->GLOBAL_RESET_SFI41.wrd = TEN_MPIF_GLOBAL_RESET_SFI41_dft;
  dft_mpif->GLOBAL_RESET_GFEC.wrd = TEN_MPIF_GLOBAL_RESET_GFEC_dft;
  dft_mpif->GLOBAL_RESET_UFEC.wrd = TEN_MPIF_GLOBAL_RESET_UFEC_dft;
  dft_mpif->GLOBAL_RESET_N40G.wrd = TEN_MPIF_GLOBAL_RESET_N40G_dft;
  dft_mpif->GLOBAL_RESET_N10G_A.wrd = TEN_MPIF_GLOBAL_RESET_N10G_A_dft;
  dft_mpif->GLOBAL_RESET_N10G_B.wrd = TEN_MPIF_GLOBAL_RESET_N10G_B_dft;
  dft_mpif->GLOBAL_RESET_PP10G_A.wrd = TEN_MPIF_GLOBAL_RESET_PP10G_A_dft;
  dft_mpif->GLOBAL_RESET_PP10G_B.wrd = TEN_MPIF_GLOBAL_RESET_PP10G_B_dft;
  dft_mpif->GLOBAL_RESET_SYNCDSYNC.wrd = TEN_MPIF_GLOBAL_RESET_SYNCDSYNC_dft;
  dft_mpif->GLOBAL_RESET_GPLL.wrd = TEN_MPIF_GLOBAL_RESET_GPLL_dft;
  dft_mpif->GLOBAL_RESET_SYSPLL.wrd = TEN_MPIF_GLOBAL_RESET_SYSPLL_dft;
  dft_mpif->GLOBAL_RESET_XFI_DSP.wrd = TEN_MPIF_GLOBAL_RESET_XFI_DSP_dft;
  dft_mpif->GLOBAL_RESET_CLOCK_LOSS.wrd = TEN_MPIF_GLOBAL_RESET_CLOCK_LOSS_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_UFEC.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_UFEC_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_A_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_B_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_A_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_B_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B_dft;
  dft_mpif->CLOCK_SELECT_HSIF_OUT.wrd = TEN_MPIF_CLOCK_SELECT_HSIF_OUT_dft;
  dft_mpif->CLOCK_SELECT_GPLL_IN.wrd = TEN_MPIF_CLOCK_SELECT_GPLL_IN_dft;
  dft_mpif->CLOCK_SELECT_GPLL_OUT.wrd = TEN_MPIF_CLOCK_SELECT_GPLL_OUT_dft;
  dft_mpif->CLOCK_SELECT_40G.wrd = TEN_MPIF_CLOCK_SELECT_40G_dft;
  dft_mpif->CLOCK_SELECT_PROT.wrd = TEN_MPIF_CLOCK_SELECT_PROT_dft;
  dft_mpif->CLOCK_SELECT_PILOT.wrd = TEN_MPIF_CLOCK_SELECT_PILOT_dft;
  dft_mpif->CLOCK_SELECT_SYS.wrd = TEN_MPIF_CLOCK_SELECT_SYS_dft;
  dft_mpif->GFEC_CFG.wrd = TEN_MPIF_GFEC_CFG_dft;   
  dft_mpif->UFEC_CFG.wrd = TEN_MPIF_UFEC_CFG_dft;   
  dft_mpif->CLOCK_SWITCH_RX_FORCE.wrd = TEN_MPIF_CLOCK_SWITCH_RX_FORCE_dft;
  dft_mpif->CLOCK_SWITCH_RX_XLOS.wrd = TEN_MPIF_CLOCK_SWITCH_RX_XLOS_dft;
  dft_mpif->CLOCK_SWITCH_RX_LOCKDET.wrd = TEN_MPIF_CLOCK_SWITCH_RX_LOCKDET_dft;
  dft_mpif->CLOCK_SWITCH_RX_CLKLOSS.wrd = TEN_MPIF_CLOCK_SWITCH_RX_CLKLOSS_dft;
  dft_mpif->CLOCK_SWITCH_RX_SOURCE.wrd = TEN_MPIF_CLOCK_SWITCH_RX_SOURCE_dft;
  dft_mpif->CLOCK_SWITCH_TX_FORCE.wrd = TEN_MPIF_CLOCK_SWITCH_TX_FORCE_dft;
  dft_mpif->CLOCK_SWITCH_TX_XLOS.wrd = TEN_MPIF_CLOCK_SWITCH_TX_XLOS_dft;
  dft_mpif->CLOCK_SWITCH_TX_LOCKDET.wrd = TEN_MPIF_CLOCK_SWITCH_TX_LOCKDET_dft;
  dft_mpif->CLOCK_SWITCH_TX_CLKLOSS.wrd = TEN_MPIF_CLOCK_SWITCH_TX_CLKLOSS_dft;
  dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.wrd = TEN_MPIF_CLOCK_SWITCH_TX_CBRGENAIS_dft;
  dft_mpif->CLOCK_SWITCH_TX_PN11.wrd = TEN_MPIF_CLOCK_SWITCH_TX_PN11_dft;
  dft_mpif->CLOCK_SWITCH_TX_MS.wrd = TEN_MPIF_CLOCK_SWITCH_TX_MS_dft;
  dft_mpif->CLOCK_SWITCH_TX_MSAIS.wrd = TEN_MPIF_CLOCK_SWITCH_TX_MSAIS_dft;
  dft_mpif->GLOBAL_INTERRUPT.wrd = TEN_MPIF_GLOBAL_INTERRUPT_dft;
  dft_mpif->GLOBAL_INTENABLE.wrd = TEN_MPIF_GLOBAL_INTENABLE_dft;
  dft_mpif->MODULE_A_INTERRUPT.wrd = TEN_MPIF_MODULE_A_INTERRUPT_dft;
  dft_mpif->MODULE_A_INTENABLE.wrd = TEN_MPIF_MODULE_A_INTENABLE_dft;
  dft_mpif->MODULE_B_INTERRUPT.wrd = TEN_MPIF_MODULE_B_INTERRUPT_dft;
  dft_mpif->MODULE_B_INTENABLE.wrd = TEN_MPIF_MODULE_B_INTENABLE_dft;
  dft_mpif->GFEC_INTERRUPT.wrd = TEN_MPIF_GFEC_INTERRUPT_dft;
  dft_mpif->GFEC_INTENABLE.wrd = TEN_MPIF_GFEC_INTENABLE_dft;
  dft_mpif->UFEC_INTERRUPT.wrd = TEN_MPIF_UFEC_INTERRUPT_dft;
  dft_mpif->UFEC_INTENABLE.wrd = TEN_MPIF_UFEC_INTENABLE_dft;
  dft_mpif->GS_INTERRUPT.wrd = TEN_MPIF_GS_INTERRUPT_dft;
  dft_mpif->GS_INTENABLE.wrd = TEN_MPIF_GS_INTENABLE_dft;
  dft_mpif->GS_ISAS.wrd = TEN_MPIF_GS_ISAS_dft;     
  dft_mpif->GPLL_INTERRUPT.wrd = TEN_MPIF_GPLL_INTERRUPT_dft;
  dft_mpif->GPLL_INTENABLE.wrd = TEN_MPIF_GPLL_INTENABLE_dft;
  dft_mpif->SYNCDSYNC_INTERRUPT.wrd = TEN_MPIF_SYNCDSYNC_INTERRUPT_dft;
  dft_mpif->SYNCDSYNC_INTENABLE.wrd = TEN_MPIF_SYNCDSYNC_INTENABLE_dft;
  dft_mpif->CLOCK_LOSS_INTERRUPT.wrd = TEN_MPIF_CLOCK_LOSS_INTERRUPT_dft;
  dft_mpif->CLOCK_LOSS_INTENABLE.wrd = TEN_MPIF_CLOCK_LOSS_INTENABLE_dft;
  dft_mpif->CLOCK_LOSS_STATUS.wrd = TEN_MPIF_CLOCK_LOSS_STATUS_dft;
  dft_mpif->CLOCK_LOSS_ISAS.wrd = TEN_MPIF_CLOCK_LOSS_ISAS_dft;
  dft_mpif->XLOS_INTERRUPT.wrd = TEN_MPIF_XLOS_INTERRUPT_dft;
  dft_mpif->XLOS_INTENABLE.wrd = TEN_MPIF_XLOS_INTENABLE_dft;
  dft_mpif->XLOS_STATUS.wrd = TEN_MPIF_XLOS_STATUS_dft;
  dft_mpif->XLOS_ISAS.wrd = TEN_MPIF_XLOS_ISAS_dft; 
  dft_mpif->SYS_INTERRUPT.wrd = TEN_MPIF_SYS_INTERRUPT_dft;
  dft_mpif->SYS_INTENABLE.wrd = TEN_MPIF_SYS_INTENABLE_dft;
  dft_mpif->MPIF_INTERRUPT.wrd = TEN_MPIF_MPIF_INTERRUPT_dft;
  dft_mpif->MPIF_INTENABLE.wrd = TEN_MPIF_MPIF_INTENABLE_dft;
  dft_mpif->MPIF_ISAS.wrd = TEN_MPIF_MPIF_ISAS_dft; 
  dft_mpif->GPIO_R_INTERRUPT.wrd = TEN_MPIF_GPIO_R_INTERRUPT_dft;
  dft_mpif->GPIO_R_INTENABLE.wrd = TEN_MPIF_GPIO_R_INTENABLE_dft;
  dft_mpif->GPIO_R_ISAS.wrd = TEN_MPIF_GPIO_R_ISAS_dft;
  dft_mpif->GPIO_F_INTERRUPT.wrd = TEN_MPIF_GPIO_F_INTERRUPT_dft;
  dft_mpif->GPIO_F_INTENABLE.wrd = TEN_MPIF_GPIO_F_INTENABLE_dft;
  dft_mpif->GPIO_F_ISAS.wrd = TEN_MPIF_GPIO_F_ISAS_dft;
  dft_mpif->XFI_INTERRUPT.wrd = TEN_MPIF_XFI_INTERRUPT_dft;
  dft_mpif->XFI_INTENABLE.wrd = TEN_MPIF_XFI_INTENABLE_dft;
  dft_mpif->XFI_ECC_INTERRUPT.wrd = TEN_MPIF_XFI_ECC_INTERRUPT_dft;
  dft_mpif->XFI_ECC_INTENABLE.wrd = TEN_MPIF_XFI_ECC_INTENABLE_dft;
  dft_mpif->XFI_ECC_ISAS.wrd = TEN_MPIF_XFI_ECC_ISAS_dft;
  dft_mpif->SYS_CLK_FAIL_INTERRUPT.wrd = TEN_MPIF_SYS_CLK_FAIL_INTERRUPT_dft;
  dft_mpif->SYS_CLK_FAIL_INTENABLE.wrd = TEN_MPIF_SYS_CLK_FAIL_INTENABLE_dft;
  dft_mpif->SYS_CLK_FAIL_STATUS.wrd = TEN_MPIF_SYS_CLK_FAIL_STATUS_dft;
  dft_mpif->SYS_CLK_FAIL_ISAS.wrd = TEN_MPIF_SYS_CLK_FAIL_ISAS_dft;
  dft_mpif->RXCLK_REFOUT.wrd = TEN_MPIF_RXCLK_REFOUT_dft;
  dft_mpif->PRBS_SYNC.wrd = TEN_MPIF_PRBS_SYNC_dft; 
  dft_mpif->SCRATCH_PAD1.wrd = TEN_MPIF_SCRATCH_PAD1_dft;
  dft_mpif->SCRATCH_PAD2.wrd = TEN_MPIF_SCRATCH_PAD2_dft;
  dft_mpif->GPIO_DIRECTION.wrd = TEN_MPIF_GPIO_DIRECTION_dft;
  dft_mpif->GPIO_CCFP.wrd = TEN_MPIF_GPIO_CCFP_dft; 
  dft_mpif->GPIO_OUTPUT.wrd = TEN_MPIF_GPIO_OUTPUT_dft;
  dft_mpif->GPIO_SAMPLE.wrd = TEN_MPIF_GPIO_SAMPLE_dft;
  dft_mpif->LVDS_PD.wrd = TEN_MPIF_LVDS_PD_dft;     
  dft_mpif->LVDS_DIV_PD.wrd = TEN_MPIF_LVDS_DIV_PD_dft;
  dft_mpif->STAR_BIST_DONE.wrd = TEN_MPIF_STAR_BIST_DONE_dft;
  dft_mpif->STAR_BIST_STATUS5.wrd = TEN_MPIF_STAR_BIST_STATUS5_dft;
  dft_mpif->STAR_BIST_STATUS4.wrd = TEN_MPIF_STAR_BIST_STATUS4_dft;
  dft_mpif->STAR_BIST_STATUS3.wrd = TEN_MPIF_STAR_BIST_STATUS3_dft;
  dft_mpif->STAR_BIST_STATUS2.wrd = TEN_MPIF_STAR_BIST_STATUS2_dft;
  dft_mpif->STAR_BIST_STATUS1.wrd = TEN_MPIF_STAR_BIST_STATUS1_dft;
  dft_mpif->STAR_BIST_STATUS0.wrd = TEN_MPIF_STAR_BIST_STATUS0_dft;
  dft_mpif->TIMEOUT_ADDRESS0.wrd = TEN_MPIF_TIMEOUT_ADDRESS0_dft;
  dft_mpif->TIMEOUT_ADDRESS1.wrd = TEN_MPIF_TIMEOUT_ADDRESS1_dft;
  dft_mpif->TIMEOUT_TRANSACTION.wrd = TEN_MPIF_TIMEOUT_TRANSACTION_dft;
  dft_mpif->GLOBAL_RESET_PP40G.wrd = TEN_MPIF_GLOBAL_RESET_PP40G_dft;
  dft_mpif->GLOBAL_RESET_SDS_CFP.wrd = TEN_MPIF_GLOBAL_RESET_SDS_CFP_dft;
  dft_mpif->GLOBAL_RESET_CUPLL.wrd = TEN_MPIF_GLOBAL_RESET_CUPLL_dft;
  dft_mpif->GLOBAL_RESET_GPLL_SDS.wrd = TEN_MPIF_GLOBAL_RESET_GPLL_SDS_dft;
  dft_mpif->GLOBAL_RESET_GPLL_MPIF.wrd = TEN_MPIF_GLOBAL_RESET_GPLL_MPIF_dft;
  dft_mpif->GLOBAL_RESET_CLOCK_SWITCH.wrd = TEN_MPIF_GLOBAL_RESET_CLOCK_SWITCH_dft;
  dft_mpif->GLOBAL_RESET_SYNCDSYNC_DP.wrd = TEN_MPIF_GLOBAL_RESET_SYNCDSYNC_DP_dft;
  dft_mpif->GLOBAL_RESET_DM.wrd = TEN_MPIF_GLOBAL_RESET_DM_dft;
  dft_mpif->GLOBAL_RESET_PDCAL.wrd = TEN_MPIF_GLOBAL_RESET_PDCAL_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP40G_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_CFP.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_CFP_dft;
  dft_mpif->GLOBAL_CLOCK_DISABLE_CUPLL.wrd = TEN_MPIF_GLOBAL_CLOCK_DISABLE_CUPLL_dft;
  dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.wrd = TEN_MPIF_CLOCK_SELECT_INTERNAL_RXDIV_dft;
  dft_mpif->MISC_INTERRUPT.wrd = TEN_MPIF_MISC_INTERRUPT_dft;
  dft_mpif->MISC_INTENABLE.wrd = TEN_MPIF_MISC_INTENABLE_dft;
  dft_mpif->CFP_INTERRUPT.wrd = TEN_MPIF_CFP_INTERRUPT_dft;
  dft_mpif->CFP_INTENABLE.wrd = TEN_MPIF_CFP_INTENABLE_dft;
  dft_mpif->CUPLL_INTERRUPT.wrd = TEN_MPIF_CUPLL_INTERRUPT_dft;
  dft_mpif->CUPLL_INTENABLE.wrd = TEN_MPIF_CUPLL_INTENABLE_dft;
  dft_mpif->CLOCK_SWITCH_INTERRUPT.wrd = TEN_MPIF_CLOCK_SWITCH_INTERRUPT_dft;
  dft_mpif->CLOCK_SWITCH_INTENABLE.wrd = TEN_MPIF_CLOCK_SWITCH_INTENABLE_dft;
  dft_mpif->CLOCK_SWITCH_STATUS.wrd = TEN_MPIF_CLOCK_SWITCH_STATUS_dft;
  dft_mpif->CLOCK_SWITCH_ISAS.wrd = TEN_MPIF_CLOCK_SWITCH_ISAS_dft;
  dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.wrd = TEN_MPIF_CLOCK_SWITCH_REV_INTERRUPT_dft;
  dft_mpif->CLOCK_SWITCH_REV_INTENABLE.wrd = TEN_MPIF_CLOCK_SWITCH_REV_INTENABLE_dft;
  dft_mpif->CLOCK_SWITCH_REV_STATUS.wrd = TEN_MPIF_CLOCK_SWITCH_REV_STATUS_dft;
  dft_mpif->CLOCK_SWITCH_REV_ISAS.wrd = TEN_MPIF_CLOCK_SWITCH_REV_ISAS_dft;
  dft_mpif->DATA_SWITCH_INTERRUPT.wrd = TEN_MPIF_DATA_SWITCH_INTERRUPT_dft;
  dft_mpif->DATA_SWITCH_INTENABLE.wrd = TEN_MPIF_DATA_SWITCH_INTENABLE_dft;
  dft_mpif->DATA_SWITCH_STATUS.wrd = TEN_MPIF_DATA_SWITCH_STATUS_dft;
  dft_mpif->DATA_SWITCH_ISAS.wrd = TEN_MPIF_DATA_SWITCH_ISAS_dft;
  dft_mpif->MR_PROT_INTERRUPT.wrd = TEN_MPIF_MR_PROT_INTERRUPT_dft;
  dft_mpif->MR_PROT_INTENABLE.wrd = TEN_MPIF_MR_PROT_INTENABLE_dft;
  dft_mpif->MR_PROT_STATUS.wrd = TEN_MPIF_MR_PROT_STATUS_dft;
  dft_mpif->MR_PROT_ISAS.wrd = TEN_MPIF_MR_PROT_ISAS_dft;
  dft_mpif->CLOCK_SWITCH_RX_NONREVERT.wrd = TEN_MPIF_CLOCK_SWITCH_RX_NONREVERT_dft;
  dft_mpif->CLOCK_SWITCH_TX_NONREVERT.wrd = TEN_MPIF_CLOCK_SWITCH_TX_NONREVERT_dft;
  dft_mpif->DATA_SWITCH_TX_NONREVERT.wrd = TEN_MPIF_DATA_SWITCH_TX_NONREVERT_dft;
  dft_mpif->CLOCK_SWITCH_TX_DW.wrd = TEN_MPIF_CLOCK_SWITCH_TX_DW_dft;
  dft_mpif->CLOCK_SWITCH_TX_TIMER0.wrd = TEN_MPIF_CLOCK_SWITCH_TX_TIMER0_dft;
  dft_mpif->CLOCK_SWITCH_TX_TIMER1.wrd = TEN_MPIF_CLOCK_SWITCH_TX_TIMER1_dft;
  dft_mpif->CLOCK_SWITCH_TX_TIMER2.wrd = TEN_MPIF_CLOCK_SWITCH_TX_TIMER2_dft;
  dft_mpif->CLOCK_SWITCH_TX_TIMER3.wrd = TEN_MPIF_CLOCK_SWITCH_TX_TIMER3_dft;
  dft_mpif->CLOCK_SWITCH_TX_TIMER4.wrd = TEN_MPIF_CLOCK_SWITCH_TX_TIMER4_dft;
  dft_mpif->CLOCK_SWITCH_TX_TIMER5.wrd = TEN_MPIF_CLOCK_SWITCH_TX_TIMER5_dft;
  dft_mpif->CLOCK_SWITCH_TX_TIMER6.wrd = TEN_MPIF_CLOCK_SWITCH_TX_TIMER6_dft;
  dft_mpif->CLOCK_SWITCH_TX_TIMER7.wrd = TEN_MPIF_CLOCK_SWITCH_TX_TIMER7_dft;
  dft_mpif->MR_PROT_CFG.wrd = TEN_MPIF_MR_PROT_CFG_dft;
  dft_mpif->OXU_FRAME_OUT_10G.wrd = TEN_MPIF_OXU_FRAME_OUT_10G_dft;
  dft_mpif->OXU_FRAME_OUT_40G.wrd = TEN_MPIF_OXU_FRAME_OUT_40G_dft;
  dft_mpif->RXDIV_CFG0.wrd = TEN_MPIF_RXDIV_CFG0_dft;
  dft_mpif->TXDIV_CFG0.wrd = TEN_MPIF_TXDIV_CFG0_dft;
  dft_mpif->RXLINE_DIV0.wrd = TEN_MPIF_RXLINE_DIV0_dft;
  dft_mpif->TXLINE_DIV0.wrd = TEN_MPIF_TXLINE_DIV0_dft;
  dft_mpif->PILOT_DIV0.wrd = TEN_MPIF_PILOT_DIV0_dft;
  dft_mpif->RXDIV_CFG1.wrd = TEN_MPIF_RXDIV_CFG1_dft;
  dft_mpif->TXDIV_CFG1.wrd = TEN_MPIF_TXDIV_CFG1_dft;
  dft_mpif->RXLINE_DIV1.wrd = TEN_MPIF_RXLINE_DIV1_dft;
  dft_mpif->TXLINE_DIV1.wrd = TEN_MPIF_TXLINE_DIV1_dft;
  dft_mpif->PILOT_DIV1.wrd = TEN_MPIF_PILOT_DIV1_dft;
  dft_mpif->RXDIV_CFG2.wrd = TEN_MPIF_RXDIV_CFG2_dft;
  dft_mpif->TXDIV_CFG2.wrd = TEN_MPIF_TXDIV_CFG2_dft;
  dft_mpif->RXLINE_DIV2.wrd = TEN_MPIF_RXLINE_DIV2_dft;
  dft_mpif->TXLINE_DIV2.wrd = TEN_MPIF_TXLINE_DIV2_dft;
  dft_mpif->PILOT_DIV2.wrd = TEN_MPIF_PILOT_DIV2_dft;
  dft_mpif->RXDIV_CFG3.wrd = TEN_MPIF_RXDIV_CFG3_dft;
  dft_mpif->TXDIV_CFG3.wrd = TEN_MPIF_TXDIV_CFG3_dft;
  dft_mpif->RXLINE_DIV3.wrd = TEN_MPIF_RXLINE_DIV3_dft;
  dft_mpif->TXLINE_DIV3.wrd = TEN_MPIF_TXLINE_DIV3_dft;
  dft_mpif->PILOT_DIV3.wrd = TEN_MPIF_PILOT_DIV3_dft;
  dft_mpif->RXDIV_CFG4.wrd = TEN_MPIF_RXDIV_CFG4_dft;
  dft_mpif->TXDIV_CFG4.wrd = TEN_MPIF_TXDIV_CFG4_dft;
  dft_mpif->RXLINE_DIV4.wrd = TEN_MPIF_RXLINE_DIV4_dft;
  dft_mpif->TXLINE_DIV4.wrd = TEN_MPIF_TXLINE_DIV4_dft;
  dft_mpif->PILOT_DIV4.wrd = TEN_MPIF_PILOT_DIV4_dft;
  dft_mpif->RXDIV_CFG5.wrd = TEN_MPIF_RXDIV_CFG5_dft;
  dft_mpif->TXDIV_CFG5.wrd = TEN_MPIF_TXDIV_CFG5_dft;
  dft_mpif->RXLINE_DIV5.wrd = TEN_MPIF_RXLINE_DIV5_dft;
  dft_mpif->TXLINE_DIV5.wrd = TEN_MPIF_TXLINE_DIV5_dft;
  dft_mpif->PILOT_DIV5.wrd = TEN_MPIF_PILOT_DIV5_dft;
  dft_mpif->RXDIV_CFG6.wrd = TEN_MPIF_RXDIV_CFG6_dft;
  dft_mpif->TXDIV_CFG6.wrd = TEN_MPIF_TXDIV_CFG6_dft;
  dft_mpif->RXLINE_DIV6.wrd = TEN_MPIF_RXLINE_DIV6_dft;
  dft_mpif->TXLINE_DIV6.wrd = TEN_MPIF_TXLINE_DIV6_dft;
  dft_mpif->PILOT_DIV6.wrd = TEN_MPIF_PILOT_DIV6_dft;
  dft_mpif->RXDIV_CFG7.wrd = TEN_MPIF_RXDIV_CFG7_dft;
  dft_mpif->TXDIV_CFG7.wrd = TEN_MPIF_TXDIV_CFG7_dft;
  dft_mpif->RXLINE_DIV7.wrd = TEN_MPIF_RXLINE_DIV7_dft;
  dft_mpif->TXLINE_DIV7.wrd = TEN_MPIF_TXLINE_DIV7_dft;
  dft_mpif->PILOT_DIV7.wrd = TEN_MPIF_PILOT_DIV7_dft;
  dft_mpif->CUPLL_HOLDOVER_INTERRUPT.wrd = TEN_MPIF_CUPLL_HOLDOVER_INTERRUPT_dft;
  dft_mpif->CUPLL_HOLDOVER_INTENABLE.wrd = TEN_MPIF_CUPLL_HOLDOVER_INTENABLE_dft;
  dft_mpif->CUPLL_HOLDOVER_STATUS.wrd = TEN_MPIF_CUPLL_HOLDOVER_STATUS_dft;
  dft_mpif->CUPLL_HOLDOVER_ISAS.wrd = TEN_MPIF_CUPLL_HOLDOVER_ISAS_dft;
  dft_mpif->CUPLL_HOLDOVER_FORCE.wrd = TEN_MPIF_CUPLL_HOLDOVER_FORCE_dft;
  dft_mpif->CUPLL_HOLDOVER_XLOS.wrd = TEN_MPIF_CUPLL_HOLDOVER_XLOS_dft;
  dft_mpif->CUPLL_HOLDOVER_LOCKDET.wrd = TEN_MPIF_CUPLL_HOLDOVER_LOCKDET_dft;
  dft_mpif->CUPLL_HOLDOVER_CLKLOSS.wrd = TEN_MPIF_CUPLL_HOLDOVER_CLKLOSS_dft;
  dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.wrd = TEN_MPIF_CUPLL_HOLDOVER_CBRGENAIS_dft;
  dft_mpif->CUPLL_HOLDOVER_PN11.wrd = TEN_MPIF_CUPLL_HOLDOVER_PN11_dft;
  dft_mpif->CUPLL_HOLDOVER_MS.wrd = TEN_MPIF_CUPLL_HOLDOVER_MS_dft;
  dft_mpif->CUPLL_HOLDOVER_MSAIS.wrd = TEN_MPIF_CUPLL_HOLDOVER_MSAIS_dft;
  dft_mpif->CUPLL_HOLDOVER_DW.wrd = TEN_MPIF_CUPLL_HOLDOVER_DW_dft;
  dft_mpif->CUPLL_HOLDOVER_NONREVERT.wrd = TEN_MPIF_CUPLL_HOLDOVER_NONREVERT_dft;
  dft_mpif->CUPLL_HOLDOVER_SELECT.wrd = TEN_MPIF_CUPLL_HOLDOVER_SELECT_dft;
  dft_mpif->CUPLL_SETTLE_FORCE.wrd = TEN_MPIF_CUPLL_SETTLE_FORCE_dft;
  dft_mpif->CUPLL_SETTLE_ENABLE.wrd = TEN_MPIF_CUPLL_SETTLE_ENABLE_dft;
  dft_mpif->CUPLL_SETTLE_TIMER0.wrd = TEN_MPIF_CUPLL_SETTLE_TIMER0_dft;
  dft_mpif->CUPLL_SETTLE_TIMER1.wrd = TEN_MPIF_CUPLL_SETTLE_TIMER1_dft;
  dft_mpif->CUPLL_SETTLE_TIMER2.wrd = TEN_MPIF_CUPLL_SETTLE_TIMER2_dft;
  dft_mpif->CUPLL_SETTLE_TIMER3.wrd = TEN_MPIF_CUPLL_SETTLE_TIMER3_dft;
  dft_mpif->CUPLL_LOCAL_FORCE.wrd = TEN_MPIF_CUPLL_LOCAL_FORCE_dft;
  dft_mpif->PREV_ADDRESS0.wrd = TEN_MPIF_PREV_ADDRESS0_dft;
  dft_mpif->PREV_ADDRESS1.wrd = TEN_MPIF_PREV_ADDRESS1_dft;
  dft_mpif->PREV_TRANSACTION.wrd = TEN_MPIF_PREV_TRANSACTION_dft;
  dft_mpif->PREV_DATA.wrd = TEN_MPIF_PREV_DATA_dft; 

  tmp_mpif->CHIP_ID_LSB.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_LSB));
  tmp_mpif->CHIP_ID_MSB.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_MSB));
  tmp_mpif->GLOBAL_CFG.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CFG));
  tmp_mpif->GLOBAL_RESET_COMMON.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_COMMON));
  tmp_mpif->GLOBAL_RESET_HSIF.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_HSIF));
  tmp_mpif->GLOBAL_RESET_SDS_MRA.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_MRA));
  tmp_mpif->GLOBAL_RESET_SDS_MRB.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_MRB));
  tmp_mpif->GLOBAL_RESET_SDS_XFI.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_XFI));
  tmp_mpif->GLOBAL_RESET_SFI41.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SFI41));
  tmp_mpif->GLOBAL_RESET_GFEC.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GFEC));
  tmp_mpif->GLOBAL_RESET_UFEC.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_UFEC));
  tmp_mpif->GLOBAL_RESET_N40G.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N40G));
  tmp_mpif->GLOBAL_RESET_N10G_A.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_A));
  tmp_mpif->GLOBAL_RESET_N10G_B.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_B));
  tmp_mpif->GLOBAL_RESET_PP10G_A.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_A));
  tmp_mpif->GLOBAL_RESET_PP10G_B.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_B));
  tmp_mpif->GLOBAL_RESET_SYNCDSYNC.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SYNCDSYNC));
  tmp_mpif->GLOBAL_RESET_GPLL.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GPLL));
  tmp_mpif->GLOBAL_RESET_SYSPLL.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SYSPLL));
  tmp_mpif->GLOBAL_RESET_XFI_DSP.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_XFI_DSP));
  tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_CLOCK_LOSS));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_COMMON));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_HSIF_A));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_HSIF_B));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_GFEC));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_UFEC.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_UFEC));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_A));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_B));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_A));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_B));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP10G_A));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP10G_B));
  tmp_mpif->CLOCK_SELECT_HSIF_OUT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_HSIF_OUT));
  tmp_mpif->CLOCK_SELECT_GPLL_IN.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_GPLL_IN));
  tmp_mpif->CLOCK_SELECT_GPLL_OUT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_GPLL_OUT));
  tmp_mpif->CLOCK_SELECT_40G.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_40G));
  tmp_mpif->CLOCK_SELECT_PROT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PROT));
  tmp_mpif->CLOCK_SELECT_PILOT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PILOT));
  tmp_mpif->CLOCK_SELECT_SYS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_SYS));
  tmp_mpif->GFEC_CFG.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GFEC_CFG));
  tmp_mpif->UFEC_CFG.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, UFEC_CFG));
  tmp_mpif->CLOCK_SWITCH_RX_FORCE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_FORCE));
  tmp_mpif->CLOCK_SWITCH_RX_XLOS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_XLOS));
  tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_LOCKDET));
  tmp_mpif->CLOCK_SWITCH_RX_CLKLOSS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_CLKLOSS));
  tmp_mpif->CLOCK_SWITCH_RX_SOURCE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_SOURCE));
  tmp_mpif->CLOCK_SWITCH_TX_FORCE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_FORCE));
  tmp_mpif->CLOCK_SWITCH_TX_XLOS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_XLOS));
  tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_LOCKDET));
  tmp_mpif->CLOCK_SWITCH_TX_CLKLOSS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_CLKLOSS));
  tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_CBRGENAIS));
  tmp_mpif->CLOCK_SWITCH_TX_PN11.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_PN11));
  tmp_mpif->CLOCK_SWITCH_TX_MS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MS));
  tmp_mpif->CLOCK_SWITCH_TX_MSAIS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MSAIS));
  tmp_mpif->GLOBAL_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_INTERRUPT));
  tmp_mpif->GLOBAL_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_INTENABLE));
  tmp_mpif->MODULE_A_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MODULE_A_INTERRUPT));
  tmp_mpif->MODULE_A_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MODULE_A_INTENABLE));
  tmp_mpif->MODULE_B_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MODULE_B_INTERRUPT));
  tmp_mpif->MODULE_B_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MODULE_B_INTENABLE));
  tmp_mpif->GFEC_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GFEC_INTERRUPT));
  tmp_mpif->GFEC_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GFEC_INTENABLE));
  tmp_mpif->UFEC_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, UFEC_INTERRUPT));
  tmp_mpif->UFEC_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, UFEC_INTENABLE));
  tmp_mpif->GS_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GS_INTERRUPT));
  tmp_mpif->GS_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GS_INTENABLE));
  tmp_mpif->GS_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GS_ISAS));
  tmp_mpif->GPLL_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPLL_INTERRUPT));
  tmp_mpif->GPLL_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPLL_INTENABLE));
  tmp_mpif->SYNCDSYNC_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SYNCDSYNC_INTERRUPT));
  tmp_mpif->SYNCDSYNC_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SYNCDSYNC_INTENABLE));
  tmp_mpif->CLOCK_LOSS_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_LOSS_INTERRUPT));
  tmp_mpif->CLOCK_LOSS_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_LOSS_INTENABLE));
  tmp_mpif->CLOCK_LOSS_STATUS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_LOSS_STATUS));
  tmp_mpif->CLOCK_LOSS_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_LOSS_ISAS));
  tmp_mpif->XLOS_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, XLOS_INTERRUPT));
  tmp_mpif->XLOS_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, XLOS_INTENABLE));
  tmp_mpif->XLOS_STATUS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, XLOS_STATUS));
  tmp_mpif->XLOS_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, XLOS_ISAS));
  tmp_mpif->SYS_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SYS_INTERRUPT));
  tmp_mpif->SYS_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SYS_INTENABLE));
  tmp_mpif->MPIF_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MPIF_INTERRUPT));
  tmp_mpif->MPIF_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MPIF_INTENABLE));
  tmp_mpif->MPIF_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MPIF_ISAS));
  tmp_mpif->GPIO_R_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_R_INTERRUPT));
  tmp_mpif->GPIO_R_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_R_INTENABLE));
  tmp_mpif->GPIO_R_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_R_ISAS));
  tmp_mpif->GPIO_F_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_F_INTERRUPT));
  tmp_mpif->GPIO_F_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_F_INTENABLE));
  tmp_mpif->GPIO_F_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_F_ISAS));
  tmp_mpif->XFI_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, XFI_INTERRUPT));
  tmp_mpif->XFI_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, XFI_INTENABLE));
  tmp_mpif->XFI_ECC_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, XFI_ECC_INTERRUPT));
  tmp_mpif->XFI_ECC_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, XFI_ECC_INTENABLE));
  tmp_mpif->XFI_ECC_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, XFI_ECC_ISAS));
  tmp_mpif->SYS_CLK_FAIL_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SYS_CLK_FAIL_INTERRUPT));
  tmp_mpif->SYS_CLK_FAIL_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SYS_CLK_FAIL_INTENABLE));
  tmp_mpif->SYS_CLK_FAIL_STATUS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SYS_CLK_FAIL_STATUS));
  tmp_mpif->SYS_CLK_FAIL_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SYS_CLK_FAIL_ISAS));
  tmp_mpif->RXCLK_REFOUT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXCLK_REFOUT));
  tmp_mpif->PRBS_SYNC.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PRBS_SYNC));
  tmp_mpif->SCRATCH_PAD1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SCRATCH_PAD1));
  tmp_mpif->SCRATCH_PAD2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SCRATCH_PAD2));
  tmp_mpif->GPIO_DIRECTION.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_DIRECTION));
  tmp_mpif->GPIO_CCFP.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_CCFP));
  tmp_mpif->GPIO_OUTPUT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_OUTPUT));
  tmp_mpif->GPIO_SAMPLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_SAMPLE));
  tmp_mpif->LVDS_PD.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, LVDS_PD));
  tmp_mpif->LVDS_DIV_PD.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, LVDS_DIV_PD));
  tmp_mpif->STAR_BIST_DONE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, STAR_BIST_DONE));
  tmp_mpif->STAR_BIST_STATUS5.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, STAR_BIST_STATUS5));
  tmp_mpif->STAR_BIST_STATUS4.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, STAR_BIST_STATUS4));
  tmp_mpif->STAR_BIST_STATUS3.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, STAR_BIST_STATUS3));
  tmp_mpif->STAR_BIST_STATUS2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, STAR_BIST_STATUS2));
  tmp_mpif->STAR_BIST_STATUS1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, STAR_BIST_STATUS1));
  tmp_mpif->STAR_BIST_STATUS0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, STAR_BIST_STATUS0));
  tmp_mpif->TIMEOUT_ADDRESS0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TIMEOUT_ADDRESS0));
  tmp_mpif->TIMEOUT_ADDRESS1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TIMEOUT_ADDRESS1));
  tmp_mpif->TIMEOUT_TRANSACTION.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TIMEOUT_TRANSACTION));
  tmp_mpif->GLOBAL_RESET_PP40G.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP40G));
  tmp_mpif->GLOBAL_RESET_SDS_CFP.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_CFP));
  tmp_mpif->GLOBAL_RESET_CUPLL.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_CUPLL));
  tmp_mpif->GLOBAL_RESET_GPLL_SDS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GPLL_SDS));
  tmp_mpif->GLOBAL_RESET_GPLL_MPIF.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GPLL_MPIF));
  tmp_mpif->GLOBAL_RESET_CLOCK_SWITCH.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_CLOCK_SWITCH));
  tmp_mpif->GLOBAL_RESET_SYNCDSYNC_DP.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SYNCDSYNC_DP));
  tmp_mpif->GLOBAL_RESET_DM.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_DM));
  tmp_mpif->GLOBAL_RESET_PDCAL.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PDCAL));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP40G));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_CFP.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_CFP));
  tmp_mpif->GLOBAL_CLOCK_DISABLE_CUPLL.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_CUPLL));
  tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_INTERNAL_RXDIV));
  tmp_mpif->MISC_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_INTERRUPT));
  tmp_mpif->MISC_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_INTENABLE));
  tmp_mpif->CFP_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CFP_INTERRUPT));
  tmp_mpif->CFP_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CFP_INTENABLE));
  tmp_mpif->CUPLL_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_INTERRUPT));
  tmp_mpif->CUPLL_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_INTENABLE));
  tmp_mpif->CLOCK_SWITCH_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_INTERRUPT));
  tmp_mpif->CLOCK_SWITCH_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_INTENABLE));
  tmp_mpif->CLOCK_SWITCH_STATUS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_STATUS));
  tmp_mpif->CLOCK_SWITCH_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_ISAS));
  tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_REV_INTERRUPT));
  tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_REV_INTENABLE));
  tmp_mpif->CLOCK_SWITCH_REV_STATUS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_REV_STATUS));
  tmp_mpif->CLOCK_SWITCH_REV_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_REV_ISAS));
  tmp_mpif->DATA_SWITCH_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, DATA_SWITCH_INTERRUPT));
  tmp_mpif->DATA_SWITCH_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, DATA_SWITCH_INTENABLE));
  tmp_mpif->DATA_SWITCH_STATUS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, DATA_SWITCH_STATUS));
  tmp_mpif->DATA_SWITCH_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, DATA_SWITCH_ISAS));
  tmp_mpif->MR_PROT_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MR_PROT_INTERRUPT));
  tmp_mpif->MR_PROT_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MR_PROT_INTENABLE));
  tmp_mpif->MR_PROT_STATUS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MR_PROT_STATUS));
  tmp_mpif->MR_PROT_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MR_PROT_ISAS));
  tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_NONREVERT));
  tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_NONREVERT));
  tmp_mpif->DATA_SWITCH_TX_NONREVERT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, DATA_SWITCH_TX_NONREVERT));
  tmp_mpif->CLOCK_SWITCH_TX_DW.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_DW));
  tmp_mpif->CLOCK_SWITCH_TX_TIMER0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_TIMER0));
  tmp_mpif->CLOCK_SWITCH_TX_TIMER1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_TIMER1));
  tmp_mpif->CLOCK_SWITCH_TX_TIMER2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_TIMER2));
  tmp_mpif->CLOCK_SWITCH_TX_TIMER3.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_TIMER3));
  tmp_mpif->CLOCK_SWITCH_TX_TIMER4.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_TIMER4));
  tmp_mpif->CLOCK_SWITCH_TX_TIMER5.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_TIMER5));
  tmp_mpif->CLOCK_SWITCH_TX_TIMER6.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_TIMER6));
  tmp_mpif->CLOCK_SWITCH_TX_TIMER7.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_TIMER7));
  tmp_mpif->MR_PROT_CFG.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MR_PROT_CFG));
  tmp_mpif->OXU_FRAME_OUT_10G.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, OXU_FRAME_OUT_10G));
  tmp_mpif->OXU_FRAME_OUT_40G.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, OXU_FRAME_OUT_40G));
  tmp_mpif->RXDIV_CFG0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG0));
  tmp_mpif->TXDIV_CFG0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG0));
  tmp_mpif->RXLINE_DIV0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV0));
  tmp_mpif->TXLINE_DIV0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV0));
  tmp_mpif->PILOT_DIV0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV0));
  tmp_mpif->RXDIV_CFG1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG1));
  tmp_mpif->TXDIV_CFG1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG1));
  tmp_mpif->RXLINE_DIV1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV1));
  tmp_mpif->TXLINE_DIV1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV1));
  tmp_mpif->PILOT_DIV1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV1));
  tmp_mpif->RXDIV_CFG2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG2));
  tmp_mpif->TXDIV_CFG2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG2));
  tmp_mpif->RXLINE_DIV2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV2));
  tmp_mpif->TXLINE_DIV2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV2));
  tmp_mpif->PILOT_DIV2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV2));
  tmp_mpif->RXDIV_CFG3.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG3));
  tmp_mpif->TXDIV_CFG3.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG3));
  tmp_mpif->RXLINE_DIV3.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV3));
  tmp_mpif->TXLINE_DIV3.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV3));
  tmp_mpif->PILOT_DIV3.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV3));
  tmp_mpif->RXDIV_CFG4.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG4));
  tmp_mpif->TXDIV_CFG4.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG4));
  tmp_mpif->RXLINE_DIV4.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV4));
  tmp_mpif->TXLINE_DIV4.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV4));
  tmp_mpif->PILOT_DIV4.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV4));
  tmp_mpif->RXDIV_CFG5.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG5));
  tmp_mpif->TXDIV_CFG5.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG5));
  tmp_mpif->RXLINE_DIV5.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV5));
  tmp_mpif->TXLINE_DIV5.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV5));
  tmp_mpif->PILOT_DIV5.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV5));
  tmp_mpif->RXDIV_CFG6.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG6));
  tmp_mpif->TXDIV_CFG6.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG6));
  tmp_mpif->RXLINE_DIV6.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV6));
  tmp_mpif->TXLINE_DIV6.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV6));
  tmp_mpif->PILOT_DIV6.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV6));
  tmp_mpif->RXDIV_CFG7.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG7));
  tmp_mpif->TXDIV_CFG7.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG7));
  tmp_mpif->RXLINE_DIV7.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV7));
  tmp_mpif->TXLINE_DIV7.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV7));
  tmp_mpif->PILOT_DIV7.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV7));
  tmp_mpif->CUPLL_HOLDOVER_INTERRUPT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_INTERRUPT));
  tmp_mpif->CUPLL_HOLDOVER_INTENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_INTENABLE));
  tmp_mpif->CUPLL_HOLDOVER_STATUS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_STATUS));
  tmp_mpif->CUPLL_HOLDOVER_ISAS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_ISAS));
  tmp_mpif->CUPLL_HOLDOVER_FORCE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_FORCE));
  tmp_mpif->CUPLL_HOLDOVER_XLOS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_XLOS));
  tmp_mpif->CUPLL_HOLDOVER_LOCKDET.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_LOCKDET));
  tmp_mpif->CUPLL_HOLDOVER_CLKLOSS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_CLKLOSS));
  tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_CBRGENAIS));
  tmp_mpif->CUPLL_HOLDOVER_PN11.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_PN11));
  tmp_mpif->CUPLL_HOLDOVER_MS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_MS));
  tmp_mpif->CUPLL_HOLDOVER_MSAIS.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_MSAIS));
  tmp_mpif->CUPLL_HOLDOVER_DW.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_DW));
  tmp_mpif->CUPLL_HOLDOVER_NONREVERT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_NONREVERT));
  tmp_mpif->CUPLL_HOLDOVER_SELECT.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_SELECT));
  tmp_mpif->CUPLL_SETTLE_FORCE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_FORCE));
  tmp_mpif->CUPLL_SETTLE_ENABLE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_ENABLE));
  tmp_mpif->CUPLL_SETTLE_TIMER0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER0));
  tmp_mpif->CUPLL_SETTLE_TIMER1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER1));
  tmp_mpif->CUPLL_SETTLE_TIMER2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER2));
  tmp_mpif->CUPLL_SETTLE_TIMER3.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER3));
  tmp_mpif->CUPLL_LOCAL_FORCE.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_LOCAL_FORCE));
  tmp_mpif->PREV_ADDRESS0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PREV_ADDRESS0));
  tmp_mpif->PREV_ADDRESS1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PREV_ADDRESS1));
  tmp_mpif->PREV_TRANSACTION.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PREV_TRANSACTION));
  tmp_mpif->PREV_DATA.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PREV_DATA));

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
  
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CHIP_ID_LSB.wrd", tmp_mpif->CHIP_ID_LSB.wrd, tmp_mpif->CHIP_ID_LSB.wrd == dft_mpif->CHIP_ID_LSB.wrd ? 0x20 : 0x2A, dft_mpif->CHIP_ID_LSB.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CHIP_ID_LSB.bf.DevIDCode_SKU", tmp_mpif->CHIP_ID_LSB.bf.DevIDCode_SKU, tmp_mpif->CHIP_ID_LSB.bf.DevIDCode_SKU == dft_mpif->CHIP_ID_LSB.bf.DevIDCode_SKU ? 0x20 : 0x2A, dft_mpif->CHIP_ID_LSB.bf.DevIDCode_SKU);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CHIP_ID_LSB.bf.ManID", tmp_mpif->CHIP_ID_LSB.bf.ManID, tmp_mpif->CHIP_ID_LSB.bf.ManID == dft_mpif->CHIP_ID_LSB.bf.ManID ? 0x20 : 0x2A, dft_mpif->CHIP_ID_LSB.bf.ManID);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CHIP_ID_LSB.bf.lsb", tmp_mpif->CHIP_ID_LSB.bf.lsb, tmp_mpif->CHIP_ID_LSB.bf.lsb == dft_mpif->CHIP_ID_LSB.bf.lsb ? 0x20 : 0x2A, dft_mpif->CHIP_ID_LSB.bf.lsb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CHIP_ID_MSB.wrd", tmp_mpif->CHIP_ID_MSB.wrd, tmp_mpif->CHIP_ID_MSB.wrd == dft_mpif->CHIP_ID_MSB.wrd ? 0x20 : 0x2A, dft_mpif->CHIP_ID_MSB.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CHIP_ID_MSB.bf.RevCode", tmp_mpif->CHIP_ID_MSB.bf.RevCode, tmp_mpif->CHIP_ID_MSB.bf.RevCode == dft_mpif->CHIP_ID_MSB.bf.RevCode ? 0x20 : 0x2A, dft_mpif->CHIP_ID_MSB.bf.RevCode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CHIP_ID_MSB.bf.DevIDCode", tmp_mpif->CHIP_ID_MSB.bf.DevIDCode, tmp_mpif->CHIP_ID_MSB.bf.DevIDCode == dft_mpif->CHIP_ID_MSB.bf.DevIDCode ? 0x20 : 0x2A, dft_mpif->CHIP_ID_MSB.bf.DevIDCode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CFG.wrd", tmp_mpif->GLOBAL_CFG.wrd, tmp_mpif->GLOBAL_CFG.wrd == dft_mpif->GLOBAL_CFG.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CFG.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CFG.bf.t100_ded_mode", tmp_mpif->GLOBAL_CFG.bf.t100_ded_mode, tmp_mpif->GLOBAL_CFG.bf.t100_ded_mode == dft_mpif->GLOBAL_CFG.bf.t100_ded_mode ? 0x20 : 0x2A, dft_mpif->GLOBAL_CFG.bf.t100_ded_mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CFG.bf.tx_quad_mode_b", tmp_mpif->GLOBAL_CFG.bf.tx_quad_mode_b, tmp_mpif->GLOBAL_CFG.bf.tx_quad_mode_b == dft_mpif->GLOBAL_CFG.bf.tx_quad_mode_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_CFG.bf.tx_quad_mode_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CFG.bf.tx_quad_mode_a", tmp_mpif->GLOBAL_CFG.bf.tx_quad_mode_a, tmp_mpif->GLOBAL_CFG.bf.tx_quad_mode_a == dft_mpif->GLOBAL_CFG.bf.tx_quad_mode_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_CFG.bf.tx_quad_mode_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CFG.bf.rx_quad_mode_b", tmp_mpif->GLOBAL_CFG.bf.rx_quad_mode_b, tmp_mpif->GLOBAL_CFG.bf.rx_quad_mode_b == dft_mpif->GLOBAL_CFG.bf.rx_quad_mode_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_CFG.bf.rx_quad_mode_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CFG.bf.rx_quad_mode_a", tmp_mpif->GLOBAL_CFG.bf.rx_quad_mode_a, tmp_mpif->GLOBAL_CFG.bf.rx_quad_mode_a == dft_mpif->GLOBAL_CFG.bf.rx_quad_mode_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_CFG.bf.rx_quad_mode_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_COMMON.wrd", tmp_mpif->GLOBAL_RESET_COMMON.wrd, tmp_mpif->GLOBAL_RESET_COMMON.wrd == dft_mpif->GLOBAL_RESET_COMMON.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_COMMON.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_COMMON.bf.mpif", tmp_mpif->GLOBAL_RESET_COMMON.bf.mpif, tmp_mpif->GLOBAL_RESET_COMMON.bf.mpif == dft_mpif->GLOBAL_RESET_COMMON.bf.mpif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_COMMON.bf.mpif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_COMMON.bf.clkloss", tmp_mpif->GLOBAL_RESET_COMMON.bf.clkloss, tmp_mpif->GLOBAL_RESET_COMMON.bf.clkloss == dft_mpif->GLOBAL_RESET_COMMON.bf.clkloss ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_COMMON.bf.clkloss);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_COMMON.bf.topsys", tmp_mpif->GLOBAL_RESET_COMMON.bf.topsys, tmp_mpif->GLOBAL_RESET_COMMON.bf.topsys == dft_mpif->GLOBAL_RESET_COMMON.bf.topsys ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_COMMON.bf.topsys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_COMMON.bf.ohpp_b", tmp_mpif->GLOBAL_RESET_COMMON.bf.ohpp_b, tmp_mpif->GLOBAL_RESET_COMMON.bf.ohpp_b == dft_mpif->GLOBAL_RESET_COMMON.bf.ohpp_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_COMMON.bf.ohpp_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_COMMON.bf.ohpp_a", tmp_mpif->GLOBAL_RESET_COMMON.bf.ohpp_a, tmp_mpif->GLOBAL_RESET_COMMON.bf.ohpp_a == dft_mpif->GLOBAL_RESET_COMMON.bf.ohpp_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_COMMON.bf.ohpp_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_COMMON.bf.spoh", tmp_mpif->GLOBAL_RESET_COMMON.bf.spoh, tmp_mpif->GLOBAL_RESET_COMMON.bf.spoh == dft_mpif->GLOBAL_RESET_COMMON.bf.spoh ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_COMMON.bf.spoh);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_COMMON.bf.xcon", tmp_mpif->GLOBAL_RESET_COMMON.bf.xcon, tmp_mpif->GLOBAL_RESET_COMMON.bf.xcon == dft_mpif->GLOBAL_RESET_COMMON.bf.xcon ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_COMMON.bf.xcon);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_COMMON.bf.chip", tmp_mpif->GLOBAL_RESET_COMMON.bf.chip, tmp_mpif->GLOBAL_RESET_COMMON.bf.chip == dft_mpif->GLOBAL_RESET_COMMON.bf.chip ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_COMMON.bf.chip);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_HSIF.wrd", tmp_mpif->GLOBAL_RESET_HSIF.wrd, tmp_mpif->GLOBAL_RESET_HSIF.wrd == dft_mpif->GLOBAL_RESET_HSIF.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_HSIF.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_HSIF.bf.mpif_b", tmp_mpif->GLOBAL_RESET_HSIF.bf.mpif_b, tmp_mpif->GLOBAL_RESET_HSIF.bf.mpif_b == dft_mpif->GLOBAL_RESET_HSIF.bf.mpif_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_HSIF.bf.mpif_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_HSIF.bf.mpif_a", tmp_mpif->GLOBAL_RESET_HSIF.bf.mpif_a, tmp_mpif->GLOBAL_RESET_HSIF.bf.mpif_a == dft_mpif->GLOBAL_RESET_HSIF.bf.mpif_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_HSIF.bf.mpif_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_HSIF.bf.tx_b", tmp_mpif->GLOBAL_RESET_HSIF.bf.tx_b, tmp_mpif->GLOBAL_RESET_HSIF.bf.tx_b == dft_mpif->GLOBAL_RESET_HSIF.bf.tx_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_HSIF.bf.tx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_HSIF.bf.tx_a", tmp_mpif->GLOBAL_RESET_HSIF.bf.tx_a, tmp_mpif->GLOBAL_RESET_HSIF.bf.tx_a == dft_mpif->GLOBAL_RESET_HSIF.bf.tx_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_HSIF.bf.tx_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_HSIF.bf.rx_b", tmp_mpif->GLOBAL_RESET_HSIF.bf.rx_b, tmp_mpif->GLOBAL_RESET_HSIF.bf.rx_b == dft_mpif->GLOBAL_RESET_HSIF.bf.rx_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_HSIF.bf.rx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_HSIF.bf.rx_a", tmp_mpif->GLOBAL_RESET_HSIF.bf.rx_a, tmp_mpif->GLOBAL_RESET_HSIF.bf.rx_a == dft_mpif->GLOBAL_RESET_HSIF.bf.rx_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_HSIF.bf.rx_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_MRA.wrd", tmp_mpif->GLOBAL_RESET_SDS_MRA.wrd, tmp_mpif->GLOBAL_RESET_SDS_MRA.wrd == dft_mpif->GLOBAL_RESET_SDS_MRA.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_MRA.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_MRA.bf.mpif", tmp_mpif->GLOBAL_RESET_SDS_MRA.bf.mpif, tmp_mpif->GLOBAL_RESET_SDS_MRA.bf.mpif == dft_mpif->GLOBAL_RESET_SDS_MRA.bf.mpif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_MRA.bf.mpif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_MRA.bf.tx", tmp_mpif->GLOBAL_RESET_SDS_MRA.bf.tx, tmp_mpif->GLOBAL_RESET_SDS_MRA.bf.tx == dft_mpif->GLOBAL_RESET_SDS_MRA.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_MRA.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_MRA.bf.rx", tmp_mpif->GLOBAL_RESET_SDS_MRA.bf.rx, tmp_mpif->GLOBAL_RESET_SDS_MRA.bf.rx == dft_mpif->GLOBAL_RESET_SDS_MRA.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_MRA.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_MRB.wrd", tmp_mpif->GLOBAL_RESET_SDS_MRB.wrd, tmp_mpif->GLOBAL_RESET_SDS_MRB.wrd == dft_mpif->GLOBAL_RESET_SDS_MRB.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_MRB.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_MRB.bf.mpif", tmp_mpif->GLOBAL_RESET_SDS_MRB.bf.mpif, tmp_mpif->GLOBAL_RESET_SDS_MRB.bf.mpif == dft_mpif->GLOBAL_RESET_SDS_MRB.bf.mpif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_MRB.bf.mpif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_MRB.bf.tx", tmp_mpif->GLOBAL_RESET_SDS_MRB.bf.tx, tmp_mpif->GLOBAL_RESET_SDS_MRB.bf.tx == dft_mpif->GLOBAL_RESET_SDS_MRB.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_MRB.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_MRB.bf.rx", tmp_mpif->GLOBAL_RESET_SDS_MRB.bf.rx, tmp_mpif->GLOBAL_RESET_SDS_MRB.bf.rx == dft_mpif->GLOBAL_RESET_SDS_MRB.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_MRB.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_XFI.wrd", tmp_mpif->GLOBAL_RESET_SDS_XFI.wrd, tmp_mpif->GLOBAL_RESET_SDS_XFI.wrd == dft_mpif->GLOBAL_RESET_SDS_XFI.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_XFI.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_XFI.bf.dsp", tmp_mpif->GLOBAL_RESET_SDS_XFI.bf.dsp, tmp_mpif->GLOBAL_RESET_SDS_XFI.bf.dsp == dft_mpif->GLOBAL_RESET_SDS_XFI.bf.dsp ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_XFI.bf.dsp);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_XFI.bf.mpif", tmp_mpif->GLOBAL_RESET_SDS_XFI.bf.mpif, tmp_mpif->GLOBAL_RESET_SDS_XFI.bf.mpif == dft_mpif->GLOBAL_RESET_SDS_XFI.bf.mpif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_XFI.bf.mpif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_XFI.bf.tx", tmp_mpif->GLOBAL_RESET_SDS_XFI.bf.tx, tmp_mpif->GLOBAL_RESET_SDS_XFI.bf.tx == dft_mpif->GLOBAL_RESET_SDS_XFI.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_XFI.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_XFI.bf.rx", tmp_mpif->GLOBAL_RESET_SDS_XFI.bf.rx, tmp_mpif->GLOBAL_RESET_SDS_XFI.bf.rx == dft_mpif->GLOBAL_RESET_SDS_XFI.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_XFI.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SFI41.wrd", tmp_mpif->GLOBAL_RESET_SFI41.wrd, tmp_mpif->GLOBAL_RESET_SFI41.wrd == dft_mpif->GLOBAL_RESET_SFI41.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SFI41.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SFI41.bf.mpif_b", tmp_mpif->GLOBAL_RESET_SFI41.bf.mpif_b, tmp_mpif->GLOBAL_RESET_SFI41.bf.mpif_b == dft_mpif->GLOBAL_RESET_SFI41.bf.mpif_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SFI41.bf.mpif_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SFI41.bf.tx_b", tmp_mpif->GLOBAL_RESET_SFI41.bf.tx_b, tmp_mpif->GLOBAL_RESET_SFI41.bf.tx_b == dft_mpif->GLOBAL_RESET_SFI41.bf.tx_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SFI41.bf.tx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SFI41.bf.rx_b", tmp_mpif->GLOBAL_RESET_SFI41.bf.rx_b, tmp_mpif->GLOBAL_RESET_SFI41.bf.rx_b == dft_mpif->GLOBAL_RESET_SFI41.bf.rx_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SFI41.bf.rx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SFI41.bf.mpif_a", tmp_mpif->GLOBAL_RESET_SFI41.bf.mpif_a, tmp_mpif->GLOBAL_RESET_SFI41.bf.mpif_a == dft_mpif->GLOBAL_RESET_SFI41.bf.mpif_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SFI41.bf.mpif_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SFI41.bf.tx_a", tmp_mpif->GLOBAL_RESET_SFI41.bf.tx_a, tmp_mpif->GLOBAL_RESET_SFI41.bf.tx_a == dft_mpif->GLOBAL_RESET_SFI41.bf.tx_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SFI41.bf.tx_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SFI41.bf.rx_a", tmp_mpif->GLOBAL_RESET_SFI41.bf.rx_a, tmp_mpif->GLOBAL_RESET_SFI41.bf.rx_a == dft_mpif->GLOBAL_RESET_SFI41.bf.rx_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SFI41.bf.rx_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GFEC.wrd", tmp_mpif->GLOBAL_RESET_GFEC.wrd, tmp_mpif->GLOBAL_RESET_GFEC.wrd == dft_mpif->GLOBAL_RESET_GFEC.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GFEC.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GFEC.bf.One0g_tx", tmp_mpif->GLOBAL_RESET_GFEC.bf.One0g_tx, tmp_mpif->GLOBAL_RESET_GFEC.bf.One0g_tx == dft_mpif->GLOBAL_RESET_GFEC.bf.One0g_tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GFEC.bf.One0g_tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GFEC.bf.One0g_rx", tmp_mpif->GLOBAL_RESET_GFEC.bf.One0g_rx, tmp_mpif->GLOBAL_RESET_GFEC.bf.One0g_rx == dft_mpif->GLOBAL_RESET_GFEC.bf.One0g_rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GFEC.bf.One0g_rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GFEC.bf.Four0g_tx", tmp_mpif->GLOBAL_RESET_GFEC.bf.Four0g_tx, tmp_mpif->GLOBAL_RESET_GFEC.bf.Four0g_tx == dft_mpif->GLOBAL_RESET_GFEC.bf.Four0g_tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GFEC.bf.Four0g_tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GFEC.bf.Four0g_rx", tmp_mpif->GLOBAL_RESET_GFEC.bf.Four0g_rx, tmp_mpif->GLOBAL_RESET_GFEC.bf.Four0g_rx == dft_mpif->GLOBAL_RESET_GFEC.bf.Four0g_rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GFEC.bf.Four0g_rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_UFEC.wrd", tmp_mpif->GLOBAL_RESET_UFEC.wrd, tmp_mpif->GLOBAL_RESET_UFEC.wrd == dft_mpif->GLOBAL_RESET_UFEC.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_UFEC.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_UFEC.bf.tx", tmp_mpif->GLOBAL_RESET_UFEC.bf.tx, tmp_mpif->GLOBAL_RESET_UFEC.bf.tx == dft_mpif->GLOBAL_RESET_UFEC.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_UFEC.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_UFEC.bf.rx", tmp_mpif->GLOBAL_RESET_UFEC.bf.rx, tmp_mpif->GLOBAL_RESET_UFEC.bf.rx == dft_mpif->GLOBAL_RESET_UFEC.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_UFEC.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N40G.wrd", tmp_mpif->GLOBAL_RESET_N40G.wrd, tmp_mpif->GLOBAL_RESET_N40G.wrd == dft_mpif->GLOBAL_RESET_N40G.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N40G.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N40G.bf.sys_b", tmp_mpif->GLOBAL_RESET_N40G.bf.sys_b, tmp_mpif->GLOBAL_RESET_N40G.bf.sys_b == dft_mpif->GLOBAL_RESET_N40G.bf.sys_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N40G.bf.sys_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N40G.bf.sys_a", tmp_mpif->GLOBAL_RESET_N40G.bf.sys_a, tmp_mpif->GLOBAL_RESET_N40G.bf.sys_a == dft_mpif->GLOBAL_RESET_N40G.bf.sys_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N40G.bf.sys_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N40G.bf.tx_b", tmp_mpif->GLOBAL_RESET_N40G.bf.tx_b, tmp_mpif->GLOBAL_RESET_N40G.bf.tx_b == dft_mpif->GLOBAL_RESET_N40G.bf.tx_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N40G.bf.tx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N40G.bf.tx_a", tmp_mpif->GLOBAL_RESET_N40G.bf.tx_a, tmp_mpif->GLOBAL_RESET_N40G.bf.tx_a == dft_mpif->GLOBAL_RESET_N40G.bf.tx_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N40G.bf.tx_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N40G.bf.rx_b", tmp_mpif->GLOBAL_RESET_N40G.bf.rx_b, tmp_mpif->GLOBAL_RESET_N40G.bf.rx_b == dft_mpif->GLOBAL_RESET_N40G.bf.rx_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N40G.bf.rx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N40G.bf.rx_a", tmp_mpif->GLOBAL_RESET_N40G.bf.rx_a, tmp_mpif->GLOBAL_RESET_N40G.bf.rx_a == dft_mpif->GLOBAL_RESET_N40G.bf.rx_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N40G.bf.rx_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N10G_A.wrd", tmp_mpif->GLOBAL_RESET_N10G_A.wrd, tmp_mpif->GLOBAL_RESET_N10G_A.wrd == dft_mpif->GLOBAL_RESET_N10G_A.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N10G_A.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N10G_A.bf.sys", tmp_mpif->GLOBAL_RESET_N10G_A.bf.sys, tmp_mpif->GLOBAL_RESET_N10G_A.bf.sys == dft_mpif->GLOBAL_RESET_N10G_A.bf.sys ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N10G_A.bf.sys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N10G_A.bf.tx", tmp_mpif->GLOBAL_RESET_N10G_A.bf.tx, tmp_mpif->GLOBAL_RESET_N10G_A.bf.tx == dft_mpif->GLOBAL_RESET_N10G_A.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N10G_A.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N10G_A.bf.rx", tmp_mpif->GLOBAL_RESET_N10G_A.bf.rx, tmp_mpif->GLOBAL_RESET_N10G_A.bf.rx == dft_mpif->GLOBAL_RESET_N10G_A.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N10G_A.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N10G_B.wrd", tmp_mpif->GLOBAL_RESET_N10G_B.wrd, tmp_mpif->GLOBAL_RESET_N10G_B.wrd == dft_mpif->GLOBAL_RESET_N10G_B.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N10G_B.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N10G_B.bf.sys", tmp_mpif->GLOBAL_RESET_N10G_B.bf.sys, tmp_mpif->GLOBAL_RESET_N10G_B.bf.sys == dft_mpif->GLOBAL_RESET_N10G_B.bf.sys ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N10G_B.bf.sys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N10G_B.bf.tx", tmp_mpif->GLOBAL_RESET_N10G_B.bf.tx, tmp_mpif->GLOBAL_RESET_N10G_B.bf.tx == dft_mpif->GLOBAL_RESET_N10G_B.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N10G_B.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_N10G_B.bf.rx", tmp_mpif->GLOBAL_RESET_N10G_B.bf.rx, tmp_mpif->GLOBAL_RESET_N10G_B.bf.rx == dft_mpif->GLOBAL_RESET_N10G_B.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_N10G_B.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP10G_A.wrd", tmp_mpif->GLOBAL_RESET_PP10G_A.wrd, tmp_mpif->GLOBAL_RESET_PP10G_A.wrd == dft_mpif->GLOBAL_RESET_PP10G_A.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP10G_A.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP10G_A.bf.sys", tmp_mpif->GLOBAL_RESET_PP10G_A.bf.sys, tmp_mpif->GLOBAL_RESET_PP10G_A.bf.sys == dft_mpif->GLOBAL_RESET_PP10G_A.bf.sys ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP10G_A.bf.sys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP10G_A.bf.tx", tmp_mpif->GLOBAL_RESET_PP10G_A.bf.tx, tmp_mpif->GLOBAL_RESET_PP10G_A.bf.tx == dft_mpif->GLOBAL_RESET_PP10G_A.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP10G_A.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP10G_A.bf.rx", tmp_mpif->GLOBAL_RESET_PP10G_A.bf.rx, tmp_mpif->GLOBAL_RESET_PP10G_A.bf.rx == dft_mpif->GLOBAL_RESET_PP10G_A.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP10G_A.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP10G_B.wrd", tmp_mpif->GLOBAL_RESET_PP10G_B.wrd, tmp_mpif->GLOBAL_RESET_PP10G_B.wrd == dft_mpif->GLOBAL_RESET_PP10G_B.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP10G_B.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP10G_B.bf.sys", tmp_mpif->GLOBAL_RESET_PP10G_B.bf.sys, tmp_mpif->GLOBAL_RESET_PP10G_B.bf.sys == dft_mpif->GLOBAL_RESET_PP10G_B.bf.sys ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP10G_B.bf.sys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP10G_B.bf.tx", tmp_mpif->GLOBAL_RESET_PP10G_B.bf.tx, tmp_mpif->GLOBAL_RESET_PP10G_B.bf.tx == dft_mpif->GLOBAL_RESET_PP10G_B.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP10G_B.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP10G_B.bf.rx", tmp_mpif->GLOBAL_RESET_PP10G_B.bf.rx, tmp_mpif->GLOBAL_RESET_PP10G_B.bf.rx == dft_mpif->GLOBAL_RESET_PP10G_B.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP10G_B.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYNCDSYNC.wrd", tmp_mpif->GLOBAL_RESET_SYNCDSYNC.wrd, tmp_mpif->GLOBAL_RESET_SYNCDSYNC.wrd == dft_mpif->GLOBAL_RESET_SYNCDSYNC.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYNCDSYNC.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYNCDSYNC.bf.tx", tmp_mpif->GLOBAL_RESET_SYNCDSYNC.bf.tx, tmp_mpif->GLOBAL_RESET_SYNCDSYNC.bf.tx == dft_mpif->GLOBAL_RESET_SYNCDSYNC.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYNCDSYNC.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYNCDSYNC.bf.rx", tmp_mpif->GLOBAL_RESET_SYNCDSYNC.bf.rx, tmp_mpif->GLOBAL_RESET_SYNCDSYNC.bf.rx == dft_mpif->GLOBAL_RESET_SYNCDSYNC.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYNCDSYNC.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GPLL.wrd", tmp_mpif->GLOBAL_RESET_GPLL.wrd, tmp_mpif->GLOBAL_RESET_GPLL.wrd == dft_mpif->GLOBAL_RESET_GPLL.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GPLL.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GPLL.bf.sds", tmp_mpif->GLOBAL_RESET_GPLL.bf.sds, tmp_mpif->GLOBAL_RESET_GPLL.bf.sds == dft_mpif->GLOBAL_RESET_GPLL.bf.sds ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GPLL.bf.sds);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYSPLL.wrd", tmp_mpif->GLOBAL_RESET_SYSPLL.wrd, tmp_mpif->GLOBAL_RESET_SYSPLL.wrd == dft_mpif->GLOBAL_RESET_SYSPLL.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYSPLL.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYSPLL.bf.fracdiv", tmp_mpif->GLOBAL_RESET_SYSPLL.bf.fracdiv, tmp_mpif->GLOBAL_RESET_SYSPLL.bf.fracdiv == dft_mpif->GLOBAL_RESET_SYSPLL.bf.fracdiv ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYSPLL.bf.fracdiv);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYSPLL.bf.sds_only", tmp_mpif->GLOBAL_RESET_SYSPLL.bf.sds_only, tmp_mpif->GLOBAL_RESET_SYSPLL.bf.sds_only == dft_mpif->GLOBAL_RESET_SYSPLL.bf.sds_only ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYSPLL.bf.sds_only);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYSPLL.bf.mpif", tmp_mpif->GLOBAL_RESET_SYSPLL.bf.mpif, tmp_mpif->GLOBAL_RESET_SYSPLL.bf.mpif == dft_mpif->GLOBAL_RESET_SYSPLL.bf.mpif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYSPLL.bf.mpif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYSPLL.bf.sds", tmp_mpif->GLOBAL_RESET_SYSPLL.bf.sds, tmp_mpif->GLOBAL_RESET_SYSPLL.bf.sds == dft_mpif->GLOBAL_RESET_SYSPLL.bf.sds ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYSPLL.bf.sds);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_XFI_DSP.wrd", tmp_mpif->GLOBAL_RESET_XFI_DSP.wrd, tmp_mpif->GLOBAL_RESET_XFI_DSP.wrd == dft_mpif->GLOBAL_RESET_XFI_DSP.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_XFI_DSP.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_XFI_DSP.bf.msmif", tmp_mpif->GLOBAL_RESET_XFI_DSP.bf.msmif, tmp_mpif->GLOBAL_RESET_XFI_DSP.bf.msmif == dft_mpif->GLOBAL_RESET_XFI_DSP.bf.msmif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_XFI_DSP.bf.msmif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_XFI_DSP.bf.agc", tmp_mpif->GLOBAL_RESET_XFI_DSP.bf.agc, tmp_mpif->GLOBAL_RESET_XFI_DSP.bf.agc == dft_mpif->GLOBAL_RESET_XFI_DSP.bf.agc ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_XFI_DSP.bf.agc);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_XFI_DSP.bf.dsp", tmp_mpif->GLOBAL_RESET_XFI_DSP.bf.dsp, tmp_mpif->GLOBAL_RESET_XFI_DSP.bf.dsp == dft_mpif->GLOBAL_RESET_XFI_DSP.bf.dsp ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_XFI_DSP.bf.dsp);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_XFI_DSP.bf.mseq", tmp_mpif->GLOBAL_RESET_XFI_DSP.bf.mseq, tmp_mpif->GLOBAL_RESET_XFI_DSP.bf.mseq == dft_mpif->GLOBAL_RESET_XFI_DSP.bf.mseq ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_XFI_DSP.bf.mseq);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CLOCK_LOSS.wrd", tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.wrd, tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.wrd == dft_mpif->GLOBAL_RESET_CLOCK_LOSS.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CLOCK_LOSS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CLOCK_LOSS.bf.TXB", tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.TXB, tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.TXB == dft_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.TXB ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.TXB);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CLOCK_LOSS.bf.RXB", tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.RXB, tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.RXB == dft_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.RXB ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.RXB);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CLOCK_LOSS.bf.TXA", tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.TXA, tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.TXA == dft_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.TXA ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.TXA);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CLOCK_LOSS.bf.RXA", tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.RXA, tmp_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.RXA == dft_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.RXA ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CLOCK_LOSS.bf.RXA);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_COMMON.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_COMMON.bf.ohpp_b", tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.ohpp_b, tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.ohpp_b == dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.ohpp_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.ohpp_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_COMMON.bf.ohpp_a", tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.ohpp_a, tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.ohpp_a == dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.ohpp_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.ohpp_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_COMMON.bf.spoh", tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.spoh, tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.spoh == dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.spoh ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.spoh);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_COMMON.bf.xcon", tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.xcon, tmp_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.xcon == dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.xcon ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_COMMON.bf.xcon);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A.bf.xfi_tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.xfi_tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.xfi_tx == dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.xfi_tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.xfi_tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A.bf.xfi_rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.xfi_rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.xfi_rx == dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.xfi_rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.xfi_rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A.bf.mr_tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.mr_tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.mr_tx == dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.mr_tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.mr_tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A.bf.mr_rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.mr_rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.mr_rx == dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.mr_rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_A.bf.mr_rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B.bf.xfi_tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.xfi_tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.xfi_tx == dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.xfi_tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.xfi_tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B.bf.xfi_rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.xfi_rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.xfi_rx == dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.xfi_rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.xfi_rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B.bf.mr_tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.mr_tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.mr_tx == dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.mr_tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.mr_tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B.bf.mr_rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.mr_rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.mr_rx == dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.mr_rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_HSIF_B.bf.mr_rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_GFEC.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_GFEC.bf.One0g_tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.One0g_tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.One0g_tx == dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.One0g_tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.One0g_tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_GFEC.bf.One0g_rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.One0g_rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.One0g_rx == dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.One0g_rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.One0g_rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_GFEC.bf.Four0g_tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.Four0g_tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.Four0g_tx == dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.Four0g_tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.Four0g_tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_GFEC.bf.Four0g_rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.Four0g_rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.Four0g_rx == dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.Four0g_rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_GFEC.bf.Four0g_rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_UFEC.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_UFEC.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_UFEC.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_UFEC.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_UFEC.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_UFEC.bf.tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_UFEC.bf.tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_UFEC.bf.tx == dft_mpif->GLOBAL_CLOCK_DISABLE_UFEC.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_UFEC.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_UFEC.bf.rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_UFEC.bf.rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_UFEC.bf.rx == dft_mpif->GLOBAL_CLOCK_DISABLE_UFEC.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_UFEC.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_A.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_A.bf.sys", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.sys, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.sys == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.sys ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.sys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_A.bf.tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.tx == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_A.bf.rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.rx == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_A.bf.tx40g", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.tx40g, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.tx40g == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.tx40g ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.tx40g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_A.bf.rx40g", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.rx40g, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.rx40g == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.rx40g ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_A.bf.rx40g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_B.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_B.bf.sys", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.sys, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.sys == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.sys ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.sys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_B.bf.tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.tx == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_B.bf.rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.rx == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_B.bf.tx40g", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.tx40g, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.tx40g == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.tx40g ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.tx40g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N40G_B.bf.rx40g", tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.rx40g, tmp_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.rx40g == dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.rx40g ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N40G_B.bf.rx40g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N10G_A.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N10G_A.bf.sys", tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.sys, tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.sys == dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.sys ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.sys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N10G_A.bf.tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.tx == dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N10G_A.bf.rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.rx == dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_A.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N10G_B.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N10G_B.bf.sys", tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.sys, tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.sys == dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.sys ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.sys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N10G_B.bf.tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.tx == dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_N10G_B.bf.rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.rx == dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_N10G_B.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A.bf.sys", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.sys, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.sys == dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.sys ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.sys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A.bf.tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.tx == dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A.bf.rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.rx == dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_A.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B.bf.sys", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.sys, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.sys == dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.sys ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.sys);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B.bf.tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.tx == dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B.bf.rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.rx == dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP10G_B.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_HSIF_OUT.wrd", tmp_mpif->CLOCK_SELECT_HSIF_OUT.wrd, tmp_mpif->CLOCK_SELECT_HSIF_OUT.wrd == dft_mpif->CLOCK_SELECT_HSIF_OUT.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_HSIF_OUT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_HSIF_OUT.bf.txb", tmp_mpif->CLOCK_SELECT_HSIF_OUT.bf.txb, tmp_mpif->CLOCK_SELECT_HSIF_OUT.bf.txb == dft_mpif->CLOCK_SELECT_HSIF_OUT.bf.txb ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_HSIF_OUT.bf.txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_HSIF_OUT.bf.rxb", tmp_mpif->CLOCK_SELECT_HSIF_OUT.bf.rxb, tmp_mpif->CLOCK_SELECT_HSIF_OUT.bf.rxb == dft_mpif->CLOCK_SELECT_HSIF_OUT.bf.rxb ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_HSIF_OUT.bf.rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_HSIF_OUT.bf.txa", tmp_mpif->CLOCK_SELECT_HSIF_OUT.bf.txa, tmp_mpif->CLOCK_SELECT_HSIF_OUT.bf.txa == dft_mpif->CLOCK_SELECT_HSIF_OUT.bf.txa ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_HSIF_OUT.bf.txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_HSIF_OUT.bf.rxa", tmp_mpif->CLOCK_SELECT_HSIF_OUT.bf.rxa, tmp_mpif->CLOCK_SELECT_HSIF_OUT.bf.rxa == dft_mpif->CLOCK_SELECT_HSIF_OUT.bf.rxa ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_HSIF_OUT.bf.rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_GPLL_IN.wrd", tmp_mpif->CLOCK_SELECT_GPLL_IN.wrd, tmp_mpif->CLOCK_SELECT_GPLL_IN.wrd == dft_mpif->CLOCK_SELECT_GPLL_IN.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_GPLL_IN.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_GPLL_IN.bf.txb", tmp_mpif->CLOCK_SELECT_GPLL_IN.bf.txb, tmp_mpif->CLOCK_SELECT_GPLL_IN.bf.txb == dft_mpif->CLOCK_SELECT_GPLL_IN.bf.txb ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_GPLL_IN.bf.txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_GPLL_IN.bf.rxb", tmp_mpif->CLOCK_SELECT_GPLL_IN.bf.rxb, tmp_mpif->CLOCK_SELECT_GPLL_IN.bf.rxb == dft_mpif->CLOCK_SELECT_GPLL_IN.bf.rxb ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_GPLL_IN.bf.rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_GPLL_IN.bf.txa", tmp_mpif->CLOCK_SELECT_GPLL_IN.bf.txa, tmp_mpif->CLOCK_SELECT_GPLL_IN.bf.txa == dft_mpif->CLOCK_SELECT_GPLL_IN.bf.txa ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_GPLL_IN.bf.txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_GPLL_IN.bf.rxa", tmp_mpif->CLOCK_SELECT_GPLL_IN.bf.rxa, tmp_mpif->CLOCK_SELECT_GPLL_IN.bf.rxa == dft_mpif->CLOCK_SELECT_GPLL_IN.bf.rxa ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_GPLL_IN.bf.rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_GPLL_OUT.wrd", tmp_mpif->CLOCK_SELECT_GPLL_OUT.wrd, tmp_mpif->CLOCK_SELECT_GPLL_OUT.wrd == dft_mpif->CLOCK_SELECT_GPLL_OUT.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_GPLL_OUT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_GPLL_OUT.bf.txb", tmp_mpif->CLOCK_SELECT_GPLL_OUT.bf.txb, tmp_mpif->CLOCK_SELECT_GPLL_OUT.bf.txb == dft_mpif->CLOCK_SELECT_GPLL_OUT.bf.txb ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_GPLL_OUT.bf.txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_GPLL_OUT.bf.rxb", tmp_mpif->CLOCK_SELECT_GPLL_OUT.bf.rxb, tmp_mpif->CLOCK_SELECT_GPLL_OUT.bf.rxb == dft_mpif->CLOCK_SELECT_GPLL_OUT.bf.rxb ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_GPLL_OUT.bf.rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_GPLL_OUT.bf.txa", tmp_mpif->CLOCK_SELECT_GPLL_OUT.bf.txa, tmp_mpif->CLOCK_SELECT_GPLL_OUT.bf.txa == dft_mpif->CLOCK_SELECT_GPLL_OUT.bf.txa ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_GPLL_OUT.bf.txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_GPLL_OUT.bf.rxa", tmp_mpif->CLOCK_SELECT_GPLL_OUT.bf.rxa, tmp_mpif->CLOCK_SELECT_GPLL_OUT.bf.rxa == dft_mpif->CLOCK_SELECT_GPLL_OUT.bf.rxa ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_GPLL_OUT.bf.rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_40G.wrd", tmp_mpif->CLOCK_SELECT_40G.wrd, tmp_mpif->CLOCK_SELECT_40G.wrd == dft_mpif->CLOCK_SELECT_40G.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_40G.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_40G.bf.txb", tmp_mpif->CLOCK_SELECT_40G.bf.txb, tmp_mpif->CLOCK_SELECT_40G.bf.txb == dft_mpif->CLOCK_SELECT_40G.bf.txb ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_40G.bf.txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_40G.bf.rxb", tmp_mpif->CLOCK_SELECT_40G.bf.rxb, tmp_mpif->CLOCK_SELECT_40G.bf.rxb == dft_mpif->CLOCK_SELECT_40G.bf.rxb ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_40G.bf.rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_40G.bf.txa", tmp_mpif->CLOCK_SELECT_40G.bf.txa, tmp_mpif->CLOCK_SELECT_40G.bf.txa == dft_mpif->CLOCK_SELECT_40G.bf.txa ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_40G.bf.txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_40G.bf.rxa", tmp_mpif->CLOCK_SELECT_40G.bf.rxa, tmp_mpif->CLOCK_SELECT_40G.bf.rxa == dft_mpif->CLOCK_SELECT_40G.bf.rxa ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_40G.bf.rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_PROT.wrd", tmp_mpif->CLOCK_SELECT_PROT.wrd, tmp_mpif->CLOCK_SELECT_PROT.wrd == dft_mpif->CLOCK_SELECT_PROT.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_PROT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_PROT.bf.tx_40g_prot", tmp_mpif->CLOCK_SELECT_PROT.bf.tx_40g_prot, tmp_mpif->CLOCK_SELECT_PROT.bf.tx_40g_prot == dft_mpif->CLOCK_SELECT_PROT.bf.tx_40g_prot ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_PROT.bf.tx_40g_prot);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_PROT.bf.rx_40g_prot", tmp_mpif->CLOCK_SELECT_PROT.bf.rx_40g_prot, tmp_mpif->CLOCK_SELECT_PROT.bf.rx_40g_prot == dft_mpif->CLOCK_SELECT_PROT.bf.rx_40g_prot ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_PROT.bf.rx_40g_prot);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_PROT.bf.tx_a2b", tmp_mpif->CLOCK_SELECT_PROT.bf.tx_a2b, tmp_mpif->CLOCK_SELECT_PROT.bf.tx_a2b == dft_mpif->CLOCK_SELECT_PROT.bf.tx_a2b ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_PROT.bf.tx_a2b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_PROT.bf.rx_a2b", tmp_mpif->CLOCK_SELECT_PROT.bf.rx_a2b, tmp_mpif->CLOCK_SELECT_PROT.bf.rx_a2b == dft_mpif->CLOCK_SELECT_PROT.bf.rx_a2b ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_PROT.bf.rx_a2b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_PILOT.wrd", tmp_mpif->CLOCK_SELECT_PILOT.wrd, tmp_mpif->CLOCK_SELECT_PILOT.wrd == dft_mpif->CLOCK_SELECT_PILOT.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_PILOT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_PILOT.bf.pilot_rxa2b", tmp_mpif->CLOCK_SELECT_PILOT.bf.pilot_rxa2b, tmp_mpif->CLOCK_SELECT_PILOT.bf.pilot_rxa2b == dft_mpif->CLOCK_SELECT_PILOT.bf.pilot_rxa2b ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_PILOT.bf.pilot_rxa2b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_SYS.wrd", tmp_mpif->CLOCK_SELECT_SYS.wrd, tmp_mpif->CLOCK_SELECT_SYS.wrd == dft_mpif->CLOCK_SELECT_SYS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_SYS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_SYS.bf.bypass", tmp_mpif->CLOCK_SELECT_SYS.bf.bypass, tmp_mpif->CLOCK_SELECT_SYS.bf.bypass == dft_mpif->CLOCK_SELECT_SYS.bf.bypass ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_SYS.bf.bypass);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_CFG.wrd", tmp_mpif->GFEC_CFG.wrd, tmp_mpif->GFEC_CFG.wrd == dft_mpif->GFEC_CFG.wrd ? 0x20 : 0x2A, dft_mpif->GFEC_CFG.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_CFG.bf.tx_b", tmp_mpif->GFEC_CFG.bf.tx_b, tmp_mpif->GFEC_CFG.bf.tx_b == dft_mpif->GFEC_CFG.bf.tx_b ? 0x20 : 0x2A, dft_mpif->GFEC_CFG.bf.tx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_CFG.bf.rx_b", tmp_mpif->GFEC_CFG.bf.rx_b, tmp_mpif->GFEC_CFG.bf.rx_b == dft_mpif->GFEC_CFG.bf.rx_b ? 0x20 : 0x2A, dft_mpif->GFEC_CFG.bf.rx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_CFG.bf.txb_10g", tmp_mpif->GFEC_CFG.bf.txb_10g, tmp_mpif->GFEC_CFG.bf.txb_10g == dft_mpif->GFEC_CFG.bf.txb_10g ? 0x20 : 0x2A, dft_mpif->GFEC_CFG.bf.txb_10g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_CFG.bf.txa_10g", tmp_mpif->GFEC_CFG.bf.txa_10g, tmp_mpif->GFEC_CFG.bf.txa_10g == dft_mpif->GFEC_CFG.bf.txa_10g ? 0x20 : 0x2A, dft_mpif->GFEC_CFG.bf.txa_10g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_CFG.bf.rxb_10g", tmp_mpif->GFEC_CFG.bf.rxb_10g, tmp_mpif->GFEC_CFG.bf.rxb_10g == dft_mpif->GFEC_CFG.bf.rxb_10g ? 0x20 : 0x2A, dft_mpif->GFEC_CFG.bf.rxb_10g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_CFG.bf.rxa_10g", tmp_mpif->GFEC_CFG.bf.rxa_10g, tmp_mpif->GFEC_CFG.bf.rxa_10g == dft_mpif->GFEC_CFG.bf.rxa_10g ? 0x20 : 0x2A, dft_mpif->GFEC_CFG.bf.rxa_10g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_CFG.wrd", tmp_mpif->UFEC_CFG.wrd, tmp_mpif->UFEC_CFG.wrd == dft_mpif->UFEC_CFG.wrd ? 0x20 : 0x2A, dft_mpif->UFEC_CFG.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_CFG.bf.tx_b", tmp_mpif->UFEC_CFG.bf.tx_b, tmp_mpif->UFEC_CFG.bf.tx_b == dft_mpif->UFEC_CFG.bf.tx_b ? 0x20 : 0x2A, dft_mpif->UFEC_CFG.bf.tx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_CFG.bf.rx_b", tmp_mpif->UFEC_CFG.bf.rx_b, tmp_mpif->UFEC_CFG.bf.rx_b == dft_mpif->UFEC_CFG.bf.rx_b ? 0x20 : 0x2A, dft_mpif->UFEC_CFG.bf.rx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_CFG.bf.tx2_10g", tmp_mpif->UFEC_CFG.bf.tx2_10g, tmp_mpif->UFEC_CFG.bf.tx2_10g == dft_mpif->UFEC_CFG.bf.tx2_10g ? 0x20 : 0x2A, dft_mpif->UFEC_CFG.bf.tx2_10g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_CFG.bf.tx1_10g", tmp_mpif->UFEC_CFG.bf.tx1_10g, tmp_mpif->UFEC_CFG.bf.tx1_10g == dft_mpif->UFEC_CFG.bf.tx1_10g ? 0x20 : 0x2A, dft_mpif->UFEC_CFG.bf.tx1_10g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_CFG.bf.rx2_10g", tmp_mpif->UFEC_CFG.bf.rx2_10g, tmp_mpif->UFEC_CFG.bf.rx2_10g == dft_mpif->UFEC_CFG.bf.rx2_10g ? 0x20 : 0x2A, dft_mpif->UFEC_CFG.bf.rx2_10g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_CFG.bf.rx1_10g", tmp_mpif->UFEC_CFG.bf.rx1_10g, tmp_mpif->UFEC_CFG.bf.rx1_10g == dft_mpif->UFEC_CFG.bf.rx1_10g ? 0x20 : 0x2A, dft_mpif->UFEC_CFG.bf.rx1_10g);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_FORCE.wrd", tmp_mpif->CLOCK_SWITCH_RX_FORCE.wrd, tmp_mpif->CLOCK_SWITCH_RX_FORCE.wrd == dft_mpif->CLOCK_SWITCH_RX_FORCE.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_FORCE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_FORCE.bf.rxb_off", tmp_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxb_off, tmp_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxb_off == dft_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxb_off ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxb_off);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_FORCE.bf.rxa_off", tmp_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxa_off, tmp_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxa_off == dft_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxa_off ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxa_off);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_FORCE.bf.rxb", tmp_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxb, tmp_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxb == dft_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxb ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_FORCE.bf.rxa", tmp_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxa, tmp_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxa == dft_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxa ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_FORCE.bf.rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_XLOS.wrd", tmp_mpif->CLOCK_SWITCH_RX_XLOS.wrd, tmp_mpif->CLOCK_SWITCH_RX_XLOS.wrd == dft_mpif->CLOCK_SWITCH_RX_XLOS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_XLOS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_XLOS.bf.mrb2a", tmp_mpif->CLOCK_SWITCH_RX_XLOS.bf.mrb2a, tmp_mpif->CLOCK_SWITCH_RX_XLOS.bf.mrb2a == dft_mpif->CLOCK_SWITCH_RX_XLOS.bf.mrb2a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_XLOS.bf.mrb2a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_XLOS.bf.xfi", tmp_mpif->CLOCK_SWITCH_RX_XLOS.bf.xfi, tmp_mpif->CLOCK_SWITCH_RX_XLOS.bf.xfi == dft_mpif->CLOCK_SWITCH_RX_XLOS.bf.xfi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_XLOS.bf.xfi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_XLOS.bf.mrb", tmp_mpif->CLOCK_SWITCH_RX_XLOS.bf.mrb, tmp_mpif->CLOCK_SWITCH_RX_XLOS.bf.mrb == dft_mpif->CLOCK_SWITCH_RX_XLOS.bf.mrb ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_XLOS.bf.mrb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_XLOS.bf.mra", tmp_mpif->CLOCK_SWITCH_RX_XLOS.bf.mra, tmp_mpif->CLOCK_SWITCH_RX_XLOS.bf.mra == dft_mpif->CLOCK_SWITCH_RX_XLOS.bf.mra ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_XLOS.bf.mra);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_LOCKDET.wrd", tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.wrd, tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.wrd == dft_mpif->CLOCK_SWITCH_RX_LOCKDET.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_LOCKDET.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_LOCKDET.bf.mrb2a", tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mrb2a, tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mrb2a == dft_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mrb2a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mrb2a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_LOCKDET.bf.xfi", tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.xfi, tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.xfi == dft_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.xfi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.xfi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_LOCKDET.bf.mrb", tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mrb, tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mrb == dft_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mrb ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mrb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_LOCKDET.bf.mra", tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mra, tmp_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mra == dft_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mra ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_LOCKDET.bf.mra);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_CLKLOSS.wrd", tmp_mpif->CLOCK_SWITCH_RX_CLKLOSS.wrd, tmp_mpif->CLOCK_SWITCH_RX_CLKLOSS.wrd == dft_mpif->CLOCK_SWITCH_RX_CLKLOSS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_CLKLOSS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_CLKLOSS.bf.mrb2a", tmp_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mrb2a, tmp_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mrb2a == dft_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mrb2a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mrb2a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_CLKLOSS.bf.mrb", tmp_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mrb, tmp_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mrb == dft_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mrb ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mrb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_CLKLOSS.bf.mra", tmp_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mra, tmp_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mra == dft_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mra ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_CLKLOSS.bf.mra);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_SOURCE.wrd", tmp_mpif->CLOCK_SWITCH_RX_SOURCE.wrd, tmp_mpif->CLOCK_SWITCH_RX_SOURCE.wrd == dft_mpif->CLOCK_SWITCH_RX_SOURCE.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_SOURCE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_SOURCE.bf.rxb", tmp_mpif->CLOCK_SWITCH_RX_SOURCE.bf.rxb, tmp_mpif->CLOCK_SWITCH_RX_SOURCE.bf.rxb == dft_mpif->CLOCK_SWITCH_RX_SOURCE.bf.rxb ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_SOURCE.bf.rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_SOURCE.bf.rxa", tmp_mpif->CLOCK_SWITCH_RX_SOURCE.bf.rxa, tmp_mpif->CLOCK_SWITCH_RX_SOURCE.bf.rxa == dft_mpif->CLOCK_SWITCH_RX_SOURCE.bf.rxa ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_SOURCE.bf.rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_FORCE.wrd", tmp_mpif->CLOCK_SWITCH_TX_FORCE.wrd, tmp_mpif->CLOCK_SWITCH_TX_FORCE.wrd == dft_mpif->CLOCK_SWITCH_TX_FORCE.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_FORCE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_FORCE.bf.txb_off", tmp_mpif->CLOCK_SWITCH_TX_FORCE.bf.txb_off, tmp_mpif->CLOCK_SWITCH_TX_FORCE.bf.txb_off == dft_mpif->CLOCK_SWITCH_TX_FORCE.bf.txb_off ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_FORCE.bf.txb_off);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_FORCE.bf.txa_off", tmp_mpif->CLOCK_SWITCH_TX_FORCE.bf.txa_off, tmp_mpif->CLOCK_SWITCH_TX_FORCE.bf.txa_off == dft_mpif->CLOCK_SWITCH_TX_FORCE.bf.txa_off ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_FORCE.bf.txa_off);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_FORCE.bf.txb", tmp_mpif->CLOCK_SWITCH_TX_FORCE.bf.txb, tmp_mpif->CLOCK_SWITCH_TX_FORCE.bf.txb == dft_mpif->CLOCK_SWITCH_TX_FORCE.bf.txb ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_FORCE.bf.txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_FORCE.bf.txa", tmp_mpif->CLOCK_SWITCH_TX_FORCE.bf.txa, tmp_mpif->CLOCK_SWITCH_TX_FORCE.bf.txa == dft_mpif->CLOCK_SWITCH_TX_FORCE.bf.txa ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_FORCE.bf.txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_XLOS.wrd", tmp_mpif->CLOCK_SWITCH_TX_XLOS.wrd, tmp_mpif->CLOCK_SWITCH_TX_XLOS.wrd == dft_mpif->CLOCK_SWITCH_TX_XLOS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_XLOS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_XLOS.bf.mrb2a", tmp_mpif->CLOCK_SWITCH_TX_XLOS.bf.mrb2a, tmp_mpif->CLOCK_SWITCH_TX_XLOS.bf.mrb2a == dft_mpif->CLOCK_SWITCH_TX_XLOS.bf.mrb2a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_XLOS.bf.mrb2a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_XLOS.bf.xfi", tmp_mpif->CLOCK_SWITCH_TX_XLOS.bf.xfi, tmp_mpif->CLOCK_SWITCH_TX_XLOS.bf.xfi == dft_mpif->CLOCK_SWITCH_TX_XLOS.bf.xfi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_XLOS.bf.xfi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_XLOS.bf.mrb", tmp_mpif->CLOCK_SWITCH_TX_XLOS.bf.mrb, tmp_mpif->CLOCK_SWITCH_TX_XLOS.bf.mrb == dft_mpif->CLOCK_SWITCH_TX_XLOS.bf.mrb ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_XLOS.bf.mrb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_XLOS.bf.mra", tmp_mpif->CLOCK_SWITCH_TX_XLOS.bf.mra, tmp_mpif->CLOCK_SWITCH_TX_XLOS.bf.mra == dft_mpif->CLOCK_SWITCH_TX_XLOS.bf.mra ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_XLOS.bf.mra);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_LOCKDET.wrd", tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.wrd, tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.wrd == dft_mpif->CLOCK_SWITCH_TX_LOCKDET.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_LOCKDET.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_LOCKDET.bf.mrb2a", tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mrb2a, tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mrb2a == dft_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mrb2a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mrb2a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_LOCKDET.bf.xfi", tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.xfi, tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.xfi == dft_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.xfi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.xfi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_LOCKDET.bf.mrb", tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mrb, tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mrb == dft_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mrb ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mrb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_LOCKDET.bf.mra", tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mra, tmp_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mra == dft_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mra ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_LOCKDET.bf.mra);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_CLKLOSS.wrd", tmp_mpif->CLOCK_SWITCH_TX_CLKLOSS.wrd, tmp_mpif->CLOCK_SWITCH_TX_CLKLOSS.wrd == dft_mpif->CLOCK_SWITCH_TX_CLKLOSS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_CLKLOSS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_CLKLOSS.bf.mrb2a", tmp_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mrb2a, tmp_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mrb2a == dft_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mrb2a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mrb2a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_CLKLOSS.bf.mrb", tmp_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mrb, tmp_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mrb == dft_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mrb ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mrb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_CLKLOSS.bf.mra", tmp_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mra, tmp_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mra == dft_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mra ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_CLKLOSS.bf.mra);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_CBRGENAIS.wrd", tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.wrd, tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.wrd == dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_CBRGENAIS.bf.Four0g_b", tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.Four0g_b, tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.Four0g_b == dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.Four0g_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.Four0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_CBRGENAIS.bf.Four0g_a", tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.Four0g_a, tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.Four0g_a == dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.Four0g_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.Four0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_CBRGENAIS.bf.One0g_b", tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.One0g_b, tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.One0g_b == dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.One0g_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.One0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_CBRGENAIS.bf.One0g_a", tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.One0g_a, tmp_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.One0g_a == dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.One0g_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_CBRGENAIS.bf.One0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_PN11.wrd", tmp_mpif->CLOCK_SWITCH_TX_PN11.wrd, tmp_mpif->CLOCK_SWITCH_TX_PN11.wrd == dft_mpif->CLOCK_SWITCH_TX_PN11.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_PN11.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_PN11.bf.Four0g_b", tmp_mpif->CLOCK_SWITCH_TX_PN11.bf.Four0g_b, tmp_mpif->CLOCK_SWITCH_TX_PN11.bf.Four0g_b == dft_mpif->CLOCK_SWITCH_TX_PN11.bf.Four0g_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_PN11.bf.Four0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_PN11.bf.Four0g_a", tmp_mpif->CLOCK_SWITCH_TX_PN11.bf.Four0g_a, tmp_mpif->CLOCK_SWITCH_TX_PN11.bf.Four0g_a == dft_mpif->CLOCK_SWITCH_TX_PN11.bf.Four0g_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_PN11.bf.Four0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_PN11.bf.One0g_b", tmp_mpif->CLOCK_SWITCH_TX_PN11.bf.One0g_b, tmp_mpif->CLOCK_SWITCH_TX_PN11.bf.One0g_b == dft_mpif->CLOCK_SWITCH_TX_PN11.bf.One0g_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_PN11.bf.One0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_PN11.bf.One0g_a", tmp_mpif->CLOCK_SWITCH_TX_PN11.bf.One0g_a, tmp_mpif->CLOCK_SWITCH_TX_PN11.bf.One0g_a == dft_mpif->CLOCK_SWITCH_TX_PN11.bf.One0g_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_PN11.bf.One0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_MS.wrd", tmp_mpif->CLOCK_SWITCH_TX_MS.wrd, tmp_mpif->CLOCK_SWITCH_TX_MS.wrd == dft_mpif->CLOCK_SWITCH_TX_MS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_MS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_MS.bf.Four0g_b", tmp_mpif->CLOCK_SWITCH_TX_MS.bf.Four0g_b, tmp_mpif->CLOCK_SWITCH_TX_MS.bf.Four0g_b == dft_mpif->CLOCK_SWITCH_TX_MS.bf.Four0g_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_MS.bf.Four0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_MS.bf.Four0g_a", tmp_mpif->CLOCK_SWITCH_TX_MS.bf.Four0g_a, tmp_mpif->CLOCK_SWITCH_TX_MS.bf.Four0g_a == dft_mpif->CLOCK_SWITCH_TX_MS.bf.Four0g_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_MS.bf.Four0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_MS.bf.One0g_b", tmp_mpif->CLOCK_SWITCH_TX_MS.bf.One0g_b, tmp_mpif->CLOCK_SWITCH_TX_MS.bf.One0g_b == dft_mpif->CLOCK_SWITCH_TX_MS.bf.One0g_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_MS.bf.One0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_MS.bf.One0g_a", tmp_mpif->CLOCK_SWITCH_TX_MS.bf.One0g_a, tmp_mpif->CLOCK_SWITCH_TX_MS.bf.One0g_a == dft_mpif->CLOCK_SWITCH_TX_MS.bf.One0g_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_MS.bf.One0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_MSAIS.wrd", tmp_mpif->CLOCK_SWITCH_TX_MSAIS.wrd, tmp_mpif->CLOCK_SWITCH_TX_MSAIS.wrd == dft_mpif->CLOCK_SWITCH_TX_MSAIS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_MSAIS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_MSAIS.bf.One0g_b", tmp_mpif->CLOCK_SWITCH_TX_MSAIS.bf.One0g_b, tmp_mpif->CLOCK_SWITCH_TX_MSAIS.bf.One0g_b == dft_mpif->CLOCK_SWITCH_TX_MSAIS.bf.One0g_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_MSAIS.bf.One0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_MSAIS.bf.One0g_a", tmp_mpif->CLOCK_SWITCH_TX_MSAIS.bf.One0g_a, tmp_mpif->CLOCK_SWITCH_TX_MSAIS.bf.One0g_a == dft_mpif->CLOCK_SWITCH_TX_MSAIS.bf.One0g_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_MSAIS.bf.One0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.wrd", tmp_mpif->GLOBAL_INTERRUPT.wrd, tmp_mpif->GLOBAL_INTERRUPT.wrd == dft_mpif->GLOBAL_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.misci", tmp_mpif->GLOBAL_INTERRUPT.bf.misci, tmp_mpif->GLOBAL_INTERRUPT.bf.misci == dft_mpif->GLOBAL_INTERRUPT.bf.misci ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.misci);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.gpio_ri", tmp_mpif->GLOBAL_INTERRUPT.bf.gpio_ri, tmp_mpif->GLOBAL_INTERRUPT.bf.gpio_ri == dft_mpif->GLOBAL_INTERRUPT.bf.gpio_ri ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.gpio_ri);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.gpio_fi", tmp_mpif->GLOBAL_INTERRUPT.bf.gpio_fi, tmp_mpif->GLOBAL_INTERRUPT.bf.gpio_fi == dft_mpif->GLOBAL_INTERRUPT.bf.gpio_fi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.gpio_fi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.mpifi", tmp_mpif->GLOBAL_INTERRUPT.bf.mpifi, tmp_mpif->GLOBAL_INTERRUPT.bf.mpifi == dft_mpif->GLOBAL_INTERRUPT.bf.mpifi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.mpifi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.SYSi", tmp_mpif->GLOBAL_INTERRUPT.bf.SYSi, tmp_mpif->GLOBAL_INTERRUPT.bf.SYSi == dft_mpif->GLOBAL_INTERRUPT.bf.SYSi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.SYSi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.XLOSi", tmp_mpif->GLOBAL_INTERRUPT.bf.XLOSi, tmp_mpif->GLOBAL_INTERRUPT.bf.XLOSi == dft_mpif->GLOBAL_INTERRUPT.bf.XLOSi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.XLOSi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.CLKLOSSi", tmp_mpif->GLOBAL_INTERRUPT.bf.CLKLOSSi, tmp_mpif->GLOBAL_INTERRUPT.bf.CLKLOSSi == dft_mpif->GLOBAL_INTERRUPT.bf.CLKLOSSi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.CLKLOSSi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.SYNCDSYNCi", tmp_mpif->GLOBAL_INTERRUPT.bf.SYNCDSYNCi, tmp_mpif->GLOBAL_INTERRUPT.bf.SYNCDSYNCi == dft_mpif->GLOBAL_INTERRUPT.bf.SYNCDSYNCi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.SYNCDSYNCi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.GPLLi", tmp_mpif->GLOBAL_INTERRUPT.bf.GPLLi, tmp_mpif->GLOBAL_INTERRUPT.bf.GPLLi == dft_mpif->GLOBAL_INTERRUPT.bf.GPLLi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.GPLLi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.GSi", tmp_mpif->GLOBAL_INTERRUPT.bf.GSi, tmp_mpif->GLOBAL_INTERRUPT.bf.GSi == dft_mpif->GLOBAL_INTERRUPT.bf.GSi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.GSi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.SPOHi", tmp_mpif->GLOBAL_INTERRUPT.bf.SPOHi, tmp_mpif->GLOBAL_INTERRUPT.bf.SPOHi == dft_mpif->GLOBAL_INTERRUPT.bf.SPOHi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.SPOHi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.XCONi", tmp_mpif->GLOBAL_INTERRUPT.bf.XCONi, tmp_mpif->GLOBAL_INTERRUPT.bf.XCONi == dft_mpif->GLOBAL_INTERRUPT.bf.XCONi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.XCONi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.UFECi", tmp_mpif->GLOBAL_INTERRUPT.bf.UFECi, tmp_mpif->GLOBAL_INTERRUPT.bf.UFECi == dft_mpif->GLOBAL_INTERRUPT.bf.UFECi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.UFECi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.GFECi", tmp_mpif->GLOBAL_INTERRUPT.bf.GFECi, tmp_mpif->GLOBAL_INTERRUPT.bf.GFECi == dft_mpif->GLOBAL_INTERRUPT.bf.GFECi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.GFECi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.MODULE_Bi", tmp_mpif->GLOBAL_INTERRUPT.bf.MODULE_Bi, tmp_mpif->GLOBAL_INTERRUPT.bf.MODULE_Bi == dft_mpif->GLOBAL_INTERRUPT.bf.MODULE_Bi ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.MODULE_Bi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTERRUPT.bf.MODULE_Ai", tmp_mpif->GLOBAL_INTERRUPT.bf.MODULE_Ai, tmp_mpif->GLOBAL_INTERRUPT.bf.MODULE_Ai == dft_mpif->GLOBAL_INTERRUPT.bf.MODULE_Ai ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTERRUPT.bf.MODULE_Ai);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.wrd", tmp_mpif->GLOBAL_INTENABLE.wrd, tmp_mpif->GLOBAL_INTENABLE.wrd == dft_mpif->GLOBAL_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.misce", tmp_mpif->GLOBAL_INTENABLE.bf.misce, tmp_mpif->GLOBAL_INTENABLE.bf.misce == dft_mpif->GLOBAL_INTENABLE.bf.misce ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.misce);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.gpio_re", tmp_mpif->GLOBAL_INTENABLE.bf.gpio_re, tmp_mpif->GLOBAL_INTENABLE.bf.gpio_re == dft_mpif->GLOBAL_INTENABLE.bf.gpio_re ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.gpio_re);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.gpio_fe", tmp_mpif->GLOBAL_INTENABLE.bf.gpio_fe, tmp_mpif->GLOBAL_INTENABLE.bf.gpio_fe == dft_mpif->GLOBAL_INTENABLE.bf.gpio_fe ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.gpio_fe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.mpife", tmp_mpif->GLOBAL_INTENABLE.bf.mpife, tmp_mpif->GLOBAL_INTENABLE.bf.mpife == dft_mpif->GLOBAL_INTENABLE.bf.mpife ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.mpife);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.SYSe", tmp_mpif->GLOBAL_INTENABLE.bf.SYSe, tmp_mpif->GLOBAL_INTENABLE.bf.SYSe == dft_mpif->GLOBAL_INTENABLE.bf.SYSe ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.SYSe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.XLOSe", tmp_mpif->GLOBAL_INTENABLE.bf.XLOSe, tmp_mpif->GLOBAL_INTENABLE.bf.XLOSe == dft_mpif->GLOBAL_INTENABLE.bf.XLOSe ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.XLOSe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.CLKLOSSe", tmp_mpif->GLOBAL_INTENABLE.bf.CLKLOSSe, tmp_mpif->GLOBAL_INTENABLE.bf.CLKLOSSe == dft_mpif->GLOBAL_INTENABLE.bf.CLKLOSSe ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.CLKLOSSe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.SYNCDSYNCe", tmp_mpif->GLOBAL_INTENABLE.bf.SYNCDSYNCe, tmp_mpif->GLOBAL_INTENABLE.bf.SYNCDSYNCe == dft_mpif->GLOBAL_INTENABLE.bf.SYNCDSYNCe ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.SYNCDSYNCe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.gplle", tmp_mpif->GLOBAL_INTENABLE.bf.gplle, tmp_mpif->GLOBAL_INTENABLE.bf.gplle == dft_mpif->GLOBAL_INTENABLE.bf.gplle ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.gplle);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.GSe", tmp_mpif->GLOBAL_INTENABLE.bf.GSe, tmp_mpif->GLOBAL_INTENABLE.bf.GSe == dft_mpif->GLOBAL_INTENABLE.bf.GSe ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.GSe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.SPOHe", tmp_mpif->GLOBAL_INTENABLE.bf.SPOHe, tmp_mpif->GLOBAL_INTENABLE.bf.SPOHe == dft_mpif->GLOBAL_INTENABLE.bf.SPOHe ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.SPOHe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.XCONe", tmp_mpif->GLOBAL_INTENABLE.bf.XCONe, tmp_mpif->GLOBAL_INTENABLE.bf.XCONe == dft_mpif->GLOBAL_INTENABLE.bf.XCONe ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.XCONe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.UFECe", tmp_mpif->GLOBAL_INTENABLE.bf.UFECe, tmp_mpif->GLOBAL_INTENABLE.bf.UFECe == dft_mpif->GLOBAL_INTENABLE.bf.UFECe ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.UFECe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.GFECe", tmp_mpif->GLOBAL_INTENABLE.bf.GFECe, tmp_mpif->GLOBAL_INTENABLE.bf.GFECe == dft_mpif->GLOBAL_INTENABLE.bf.GFECe ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.GFECe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.MODULE_Be", tmp_mpif->GLOBAL_INTENABLE.bf.MODULE_Be, tmp_mpif->GLOBAL_INTENABLE.bf.MODULE_Be == dft_mpif->GLOBAL_INTENABLE.bf.MODULE_Be ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.MODULE_Be);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_INTENABLE.bf.MODULE_Ae", tmp_mpif->GLOBAL_INTENABLE.bf.MODULE_Ae, tmp_mpif->GLOBAL_INTENABLE.bf.MODULE_Ae == dft_mpif->GLOBAL_INTENABLE.bf.MODULE_Ae ? 0x20 : 0x2A, dft_mpif->GLOBAL_INTENABLE.bf.MODULE_Ae);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.wrd", tmp_mpif->MODULE_A_INTERRUPT.wrd, tmp_mpif->MODULE_A_INTERRUPT.wrd == dft_mpif->MODULE_A_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.PP40Gi", tmp_mpif->MODULE_A_INTERRUPT.bf.PP40Gi, tmp_mpif->MODULE_A_INTERRUPT.bf.PP40Gi == dft_mpif->MODULE_A_INTERRUPT.bf.PP40Gi ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.PP40Gi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.PP10G3i", tmp_mpif->MODULE_A_INTERRUPT.bf.PP10G3i, tmp_mpif->MODULE_A_INTERRUPT.bf.PP10G3i == dft_mpif->MODULE_A_INTERRUPT.bf.PP10G3i ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.PP10G3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.PP10G2i", tmp_mpif->MODULE_A_INTERRUPT.bf.PP10G2i, tmp_mpif->MODULE_A_INTERRUPT.bf.PP10G2i == dft_mpif->MODULE_A_INTERRUPT.bf.PP10G2i ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.PP10G2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.PP10G1i", tmp_mpif->MODULE_A_INTERRUPT.bf.PP10G1i, tmp_mpif->MODULE_A_INTERRUPT.bf.PP10G1i == dft_mpif->MODULE_A_INTERRUPT.bf.PP10G1i ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.PP10G1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.PP10G0i", tmp_mpif->MODULE_A_INTERRUPT.bf.PP10G0i, tmp_mpif->MODULE_A_INTERRUPT.bf.PP10G0i == dft_mpif->MODULE_A_INTERRUPT.bf.PP10G0i ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.PP10G0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.N10G3i", tmp_mpif->MODULE_A_INTERRUPT.bf.N10G3i, tmp_mpif->MODULE_A_INTERRUPT.bf.N10G3i == dft_mpif->MODULE_A_INTERRUPT.bf.N10G3i ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.N10G3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.N10G2i", tmp_mpif->MODULE_A_INTERRUPT.bf.N10G2i, tmp_mpif->MODULE_A_INTERRUPT.bf.N10G2i == dft_mpif->MODULE_A_INTERRUPT.bf.N10G2i ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.N10G2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.N10G1i", tmp_mpif->MODULE_A_INTERRUPT.bf.N10G1i, tmp_mpif->MODULE_A_INTERRUPT.bf.N10G1i == dft_mpif->MODULE_A_INTERRUPT.bf.N10G1i ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.N10G1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.N10G0i", tmp_mpif->MODULE_A_INTERRUPT.bf.N10G0i, tmp_mpif->MODULE_A_INTERRUPT.bf.N10G0i == dft_mpif->MODULE_A_INTERRUPT.bf.N10G0i ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.N10G0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.OHPPi", tmp_mpif->MODULE_A_INTERRUPT.bf.OHPPi, tmp_mpif->MODULE_A_INTERRUPT.bf.OHPPi == dft_mpif->MODULE_A_INTERRUPT.bf.OHPPi ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.OHPPi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.N40Gi", tmp_mpif->MODULE_A_INTERRUPT.bf.N40Gi, tmp_mpif->MODULE_A_INTERRUPT.bf.N40Gi == dft_mpif->MODULE_A_INTERRUPT.bf.N40Gi ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.N40Gi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTERRUPT.bf.HSIFi", tmp_mpif->MODULE_A_INTERRUPT.bf.HSIFi, tmp_mpif->MODULE_A_INTERRUPT.bf.HSIFi == dft_mpif->MODULE_A_INTERRUPT.bf.HSIFi ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTERRUPT.bf.HSIFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.wrd", tmp_mpif->MODULE_A_INTENABLE.wrd, tmp_mpif->MODULE_A_INTENABLE.wrd == dft_mpif->MODULE_A_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.PP40Ge", tmp_mpif->MODULE_A_INTENABLE.bf.PP40Ge, tmp_mpif->MODULE_A_INTENABLE.bf.PP40Ge == dft_mpif->MODULE_A_INTENABLE.bf.PP40Ge ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.PP40Ge);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.PP10G3e", tmp_mpif->MODULE_A_INTENABLE.bf.PP10G3e, tmp_mpif->MODULE_A_INTENABLE.bf.PP10G3e == dft_mpif->MODULE_A_INTENABLE.bf.PP10G3e ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.PP10G3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.PP10G2e", tmp_mpif->MODULE_A_INTENABLE.bf.PP10G2e, tmp_mpif->MODULE_A_INTENABLE.bf.PP10G2e == dft_mpif->MODULE_A_INTENABLE.bf.PP10G2e ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.PP10G2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.PP10G1e", tmp_mpif->MODULE_A_INTENABLE.bf.PP10G1e, tmp_mpif->MODULE_A_INTENABLE.bf.PP10G1e == dft_mpif->MODULE_A_INTENABLE.bf.PP10G1e ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.PP10G1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.PP10G0e", tmp_mpif->MODULE_A_INTENABLE.bf.PP10G0e, tmp_mpif->MODULE_A_INTENABLE.bf.PP10G0e == dft_mpif->MODULE_A_INTENABLE.bf.PP10G0e ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.PP10G0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.N10G3e", tmp_mpif->MODULE_A_INTENABLE.bf.N10G3e, tmp_mpif->MODULE_A_INTENABLE.bf.N10G3e == dft_mpif->MODULE_A_INTENABLE.bf.N10G3e ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.N10G3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.N10G2e", tmp_mpif->MODULE_A_INTENABLE.bf.N10G2e, tmp_mpif->MODULE_A_INTENABLE.bf.N10G2e == dft_mpif->MODULE_A_INTENABLE.bf.N10G2e ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.N10G2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.N10G1e", tmp_mpif->MODULE_A_INTENABLE.bf.N10G1e, tmp_mpif->MODULE_A_INTENABLE.bf.N10G1e == dft_mpif->MODULE_A_INTENABLE.bf.N10G1e ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.N10G1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.N10G0e", tmp_mpif->MODULE_A_INTENABLE.bf.N10G0e, tmp_mpif->MODULE_A_INTENABLE.bf.N10G0e == dft_mpif->MODULE_A_INTENABLE.bf.N10G0e ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.N10G0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.OHPPe", tmp_mpif->MODULE_A_INTENABLE.bf.OHPPe, tmp_mpif->MODULE_A_INTENABLE.bf.OHPPe == dft_mpif->MODULE_A_INTENABLE.bf.OHPPe ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.OHPPe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.N40Ge", tmp_mpif->MODULE_A_INTENABLE.bf.N40Ge, tmp_mpif->MODULE_A_INTENABLE.bf.N40Ge == dft_mpif->MODULE_A_INTENABLE.bf.N40Ge ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.N40Ge);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_A_INTENABLE.bf.HSIFe", tmp_mpif->MODULE_A_INTENABLE.bf.HSIFe, tmp_mpif->MODULE_A_INTENABLE.bf.HSIFe == dft_mpif->MODULE_A_INTENABLE.bf.HSIFe ? 0x20 : 0x2A, dft_mpif->MODULE_A_INTENABLE.bf.HSIFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.wrd", tmp_mpif->MODULE_B_INTERRUPT.wrd, tmp_mpif->MODULE_B_INTERRUPT.wrd == dft_mpif->MODULE_B_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.CUPLLi", tmp_mpif->MODULE_B_INTERRUPT.bf.CUPLLi, tmp_mpif->MODULE_B_INTERRUPT.bf.CUPLLi == dft_mpif->MODULE_B_INTERRUPT.bf.CUPLLi ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.CUPLLi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.CFPi", tmp_mpif->MODULE_B_INTERRUPT.bf.CFPi, tmp_mpif->MODULE_B_INTERRUPT.bf.CFPi == dft_mpif->MODULE_B_INTERRUPT.bf.CFPi ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.CFPi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.PP40Gi", tmp_mpif->MODULE_B_INTERRUPT.bf.PP40Gi, tmp_mpif->MODULE_B_INTERRUPT.bf.PP40Gi == dft_mpif->MODULE_B_INTERRUPT.bf.PP40Gi ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.PP40Gi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.PP10G3i", tmp_mpif->MODULE_B_INTERRUPT.bf.PP10G3i, tmp_mpif->MODULE_B_INTERRUPT.bf.PP10G3i == dft_mpif->MODULE_B_INTERRUPT.bf.PP10G3i ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.PP10G3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.PP10G2i", tmp_mpif->MODULE_B_INTERRUPT.bf.PP10G2i, tmp_mpif->MODULE_B_INTERRUPT.bf.PP10G2i == dft_mpif->MODULE_B_INTERRUPT.bf.PP10G2i ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.PP10G2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.PP10G1i", tmp_mpif->MODULE_B_INTERRUPT.bf.PP10G1i, tmp_mpif->MODULE_B_INTERRUPT.bf.PP10G1i == dft_mpif->MODULE_B_INTERRUPT.bf.PP10G1i ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.PP10G1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.PP10G0i", tmp_mpif->MODULE_B_INTERRUPT.bf.PP10G0i, tmp_mpif->MODULE_B_INTERRUPT.bf.PP10G0i == dft_mpif->MODULE_B_INTERRUPT.bf.PP10G0i ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.PP10G0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.N10G3i", tmp_mpif->MODULE_B_INTERRUPT.bf.N10G3i, tmp_mpif->MODULE_B_INTERRUPT.bf.N10G3i == dft_mpif->MODULE_B_INTERRUPT.bf.N10G3i ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.N10G3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.N10G2i", tmp_mpif->MODULE_B_INTERRUPT.bf.N10G2i, tmp_mpif->MODULE_B_INTERRUPT.bf.N10G2i == dft_mpif->MODULE_B_INTERRUPT.bf.N10G2i ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.N10G2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.N10G1i", tmp_mpif->MODULE_B_INTERRUPT.bf.N10G1i, tmp_mpif->MODULE_B_INTERRUPT.bf.N10G1i == dft_mpif->MODULE_B_INTERRUPT.bf.N10G1i ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.N10G1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.N10G0i", tmp_mpif->MODULE_B_INTERRUPT.bf.N10G0i, tmp_mpif->MODULE_B_INTERRUPT.bf.N10G0i == dft_mpif->MODULE_B_INTERRUPT.bf.N10G0i ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.N10G0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.OHPPi", tmp_mpif->MODULE_B_INTERRUPT.bf.OHPPi, tmp_mpif->MODULE_B_INTERRUPT.bf.OHPPi == dft_mpif->MODULE_B_INTERRUPT.bf.OHPPi ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.OHPPi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.N40Gi", tmp_mpif->MODULE_B_INTERRUPT.bf.N40Gi, tmp_mpif->MODULE_B_INTERRUPT.bf.N40Gi == dft_mpif->MODULE_B_INTERRUPT.bf.N40Gi ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.N40Gi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.XFIi", tmp_mpif->MODULE_B_INTERRUPT.bf.XFIi, tmp_mpif->MODULE_B_INTERRUPT.bf.XFIi == dft_mpif->MODULE_B_INTERRUPT.bf.XFIi ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.XFIi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTERRUPT.bf.HSIFi", tmp_mpif->MODULE_B_INTERRUPT.bf.HSIFi, tmp_mpif->MODULE_B_INTERRUPT.bf.HSIFi == dft_mpif->MODULE_B_INTERRUPT.bf.HSIFi ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTERRUPT.bf.HSIFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.wrd", tmp_mpif->MODULE_B_INTENABLE.wrd, tmp_mpif->MODULE_B_INTENABLE.wrd == dft_mpif->MODULE_B_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.CUPLLe", tmp_mpif->MODULE_B_INTENABLE.bf.CUPLLe, tmp_mpif->MODULE_B_INTENABLE.bf.CUPLLe == dft_mpif->MODULE_B_INTENABLE.bf.CUPLLe ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.CUPLLe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.CFPe", tmp_mpif->MODULE_B_INTENABLE.bf.CFPe, tmp_mpif->MODULE_B_INTENABLE.bf.CFPe == dft_mpif->MODULE_B_INTENABLE.bf.CFPe ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.CFPe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.PP40Ge", tmp_mpif->MODULE_B_INTENABLE.bf.PP40Ge, tmp_mpif->MODULE_B_INTENABLE.bf.PP40Ge == dft_mpif->MODULE_B_INTENABLE.bf.PP40Ge ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.PP40Ge);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.PP10G3e", tmp_mpif->MODULE_B_INTENABLE.bf.PP10G3e, tmp_mpif->MODULE_B_INTENABLE.bf.PP10G3e == dft_mpif->MODULE_B_INTENABLE.bf.PP10G3e ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.PP10G3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.PP10G2e", tmp_mpif->MODULE_B_INTENABLE.bf.PP10G2e, tmp_mpif->MODULE_B_INTENABLE.bf.PP10G2e == dft_mpif->MODULE_B_INTENABLE.bf.PP10G2e ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.PP10G2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.PP10G1e", tmp_mpif->MODULE_B_INTENABLE.bf.PP10G1e, tmp_mpif->MODULE_B_INTENABLE.bf.PP10G1e == dft_mpif->MODULE_B_INTENABLE.bf.PP10G1e ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.PP10G1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.PP10G0e", tmp_mpif->MODULE_B_INTENABLE.bf.PP10G0e, tmp_mpif->MODULE_B_INTENABLE.bf.PP10G0e == dft_mpif->MODULE_B_INTENABLE.bf.PP10G0e ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.PP10G0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.N10G3e", tmp_mpif->MODULE_B_INTENABLE.bf.N10G3e, tmp_mpif->MODULE_B_INTENABLE.bf.N10G3e == dft_mpif->MODULE_B_INTENABLE.bf.N10G3e ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.N10G3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.N10G2e", tmp_mpif->MODULE_B_INTENABLE.bf.N10G2e, tmp_mpif->MODULE_B_INTENABLE.bf.N10G2e == dft_mpif->MODULE_B_INTENABLE.bf.N10G2e ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.N10G2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.N10G1e", tmp_mpif->MODULE_B_INTENABLE.bf.N10G1e, tmp_mpif->MODULE_B_INTENABLE.bf.N10G1e == dft_mpif->MODULE_B_INTENABLE.bf.N10G1e ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.N10G1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.N10G0e", tmp_mpif->MODULE_B_INTENABLE.bf.N10G0e, tmp_mpif->MODULE_B_INTENABLE.bf.N10G0e == dft_mpif->MODULE_B_INTENABLE.bf.N10G0e ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.N10G0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.OHPPe", tmp_mpif->MODULE_B_INTENABLE.bf.OHPPe, tmp_mpif->MODULE_B_INTENABLE.bf.OHPPe == dft_mpif->MODULE_B_INTENABLE.bf.OHPPe ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.OHPPe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.N40Ge", tmp_mpif->MODULE_B_INTENABLE.bf.N40Ge, tmp_mpif->MODULE_B_INTENABLE.bf.N40Ge == dft_mpif->MODULE_B_INTENABLE.bf.N40Ge ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.N40Ge);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.XFIe", tmp_mpif->MODULE_B_INTENABLE.bf.XFIe, tmp_mpif->MODULE_B_INTENABLE.bf.XFIe == dft_mpif->MODULE_B_INTENABLE.bf.XFIe ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.XFIe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MODULE_B_INTENABLE.bf.HSIFe", tmp_mpif->MODULE_B_INTENABLE.bf.HSIFe, tmp_mpif->MODULE_B_INTENABLE.bf.HSIFe == dft_mpif->MODULE_B_INTENABLE.bf.HSIFe ? 0x20 : 0x2A, dft_mpif->MODULE_B_INTENABLE.bf.HSIFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.wrd", tmp_mpif->GFEC_INTERRUPT.wrd, tmp_mpif->GFEC_INTERRUPT.wrd == dft_mpif->GFEC_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.bf.TX_10G3i", tmp_mpif->GFEC_INTERRUPT.bf.TX_10G3i, tmp_mpif->GFEC_INTERRUPT.bf.TX_10G3i == dft_mpif->GFEC_INTERRUPT.bf.TX_10G3i ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.bf.TX_10G3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.bf.TX_10G2i", tmp_mpif->GFEC_INTERRUPT.bf.TX_10G2i, tmp_mpif->GFEC_INTERRUPT.bf.TX_10G2i == dft_mpif->GFEC_INTERRUPT.bf.TX_10G2i ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.bf.TX_10G2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.bf.TX_10G1i", tmp_mpif->GFEC_INTERRUPT.bf.TX_10G1i, tmp_mpif->GFEC_INTERRUPT.bf.TX_10G1i == dft_mpif->GFEC_INTERRUPT.bf.TX_10G1i ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.bf.TX_10G1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.bf.RX_10G3i", tmp_mpif->GFEC_INTERRUPT.bf.RX_10G3i, tmp_mpif->GFEC_INTERRUPT.bf.RX_10G3i == dft_mpif->GFEC_INTERRUPT.bf.RX_10G3i ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.bf.RX_10G3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.bf.RX_10G2i", tmp_mpif->GFEC_INTERRUPT.bf.RX_10G2i, tmp_mpif->GFEC_INTERRUPT.bf.RX_10G2i == dft_mpif->GFEC_INTERRUPT.bf.RX_10G2i ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.bf.RX_10G2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.bf.RX_10G1i", tmp_mpif->GFEC_INTERRUPT.bf.RX_10G1i, tmp_mpif->GFEC_INTERRUPT.bf.RX_10G1i == dft_mpif->GFEC_INTERRUPT.bf.RX_10G1i ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.bf.RX_10G1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.bf.TX_40G1i", tmp_mpif->GFEC_INTERRUPT.bf.TX_40G1i, tmp_mpif->GFEC_INTERRUPT.bf.TX_40G1i == dft_mpif->GFEC_INTERRUPT.bf.TX_40G1i ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.bf.TX_40G1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.bf.TX_40G0i", tmp_mpif->GFEC_INTERRUPT.bf.TX_40G0i, tmp_mpif->GFEC_INTERRUPT.bf.TX_40G0i == dft_mpif->GFEC_INTERRUPT.bf.TX_40G0i ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.bf.TX_40G0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.bf.RX_40G1i", tmp_mpif->GFEC_INTERRUPT.bf.RX_40G1i, tmp_mpif->GFEC_INTERRUPT.bf.RX_40G1i == dft_mpif->GFEC_INTERRUPT.bf.RX_40G1i ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.bf.RX_40G1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTERRUPT.bf.RX_40G0i", tmp_mpif->GFEC_INTERRUPT.bf.RX_40G0i, tmp_mpif->GFEC_INTERRUPT.bf.RX_40G0i == dft_mpif->GFEC_INTERRUPT.bf.RX_40G0i ? 0x20 : 0x2A, dft_mpif->GFEC_INTERRUPT.bf.RX_40G0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.wrd", tmp_mpif->GFEC_INTENABLE.wrd, tmp_mpif->GFEC_INTENABLE.wrd == dft_mpif->GFEC_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.bf.TX_10G3e", tmp_mpif->GFEC_INTENABLE.bf.TX_10G3e, tmp_mpif->GFEC_INTENABLE.bf.TX_10G3e == dft_mpif->GFEC_INTENABLE.bf.TX_10G3e ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.bf.TX_10G3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.bf.TX_10G2e", tmp_mpif->GFEC_INTENABLE.bf.TX_10G2e, tmp_mpif->GFEC_INTENABLE.bf.TX_10G2e == dft_mpif->GFEC_INTENABLE.bf.TX_10G2e ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.bf.TX_10G2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.bf.TX_10G1e", tmp_mpif->GFEC_INTENABLE.bf.TX_10G1e, tmp_mpif->GFEC_INTENABLE.bf.TX_10G1e == dft_mpif->GFEC_INTENABLE.bf.TX_10G1e ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.bf.TX_10G1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.bf.RX_10G3e", tmp_mpif->GFEC_INTENABLE.bf.RX_10G3e, tmp_mpif->GFEC_INTENABLE.bf.RX_10G3e == dft_mpif->GFEC_INTENABLE.bf.RX_10G3e ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.bf.RX_10G3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.bf.RX_10G2e", tmp_mpif->GFEC_INTENABLE.bf.RX_10G2e, tmp_mpif->GFEC_INTENABLE.bf.RX_10G2e == dft_mpif->GFEC_INTENABLE.bf.RX_10G2e ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.bf.RX_10G2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.bf.RX_10G1e", tmp_mpif->GFEC_INTENABLE.bf.RX_10G1e, tmp_mpif->GFEC_INTENABLE.bf.RX_10G1e == dft_mpif->GFEC_INTENABLE.bf.RX_10G1e ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.bf.RX_10G1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.bf.TX_40G1e", tmp_mpif->GFEC_INTENABLE.bf.TX_40G1e, tmp_mpif->GFEC_INTENABLE.bf.TX_40G1e == dft_mpif->GFEC_INTENABLE.bf.TX_40G1e ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.bf.TX_40G1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.bf.TX_40G0e", tmp_mpif->GFEC_INTENABLE.bf.TX_40G0e, tmp_mpif->GFEC_INTENABLE.bf.TX_40G0e == dft_mpif->GFEC_INTENABLE.bf.TX_40G0e ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.bf.TX_40G0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.bf.RX_40G1e", tmp_mpif->GFEC_INTENABLE.bf.RX_40G1e, tmp_mpif->GFEC_INTENABLE.bf.RX_40G1e == dft_mpif->GFEC_INTENABLE.bf.RX_40G1e ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.bf.RX_40G1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GFEC_INTENABLE.bf.RX_40G0e", tmp_mpif->GFEC_INTENABLE.bf.RX_40G0e, tmp_mpif->GFEC_INTENABLE.bf.RX_40G0e == dft_mpif->GFEC_INTENABLE.bf.RX_40G0e ? 0x20 : 0x2A, dft_mpif->GFEC_INTENABLE.bf.RX_40G0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTERRUPT.wrd", tmp_mpif->UFEC_INTERRUPT.wrd, tmp_mpif->UFEC_INTERRUPT.wrd == dft_mpif->UFEC_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->UFEC_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTERRUPT.bf.UFECTX3i", tmp_mpif->UFEC_INTERRUPT.bf.UFECTX3i, tmp_mpif->UFEC_INTERRUPT.bf.UFECTX3i == dft_mpif->UFEC_INTERRUPT.bf.UFECTX3i ? 0x20 : 0x2A, dft_mpif->UFEC_INTERRUPT.bf.UFECTX3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTERRUPT.bf.UFECTX2i", tmp_mpif->UFEC_INTERRUPT.bf.UFECTX2i, tmp_mpif->UFEC_INTERRUPT.bf.UFECTX2i == dft_mpif->UFEC_INTERRUPT.bf.UFECTX2i ? 0x20 : 0x2A, dft_mpif->UFEC_INTERRUPT.bf.UFECTX2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTERRUPT.bf.UFECTX1i", tmp_mpif->UFEC_INTERRUPT.bf.UFECTX1i, tmp_mpif->UFEC_INTERRUPT.bf.UFECTX1i == dft_mpif->UFEC_INTERRUPT.bf.UFECTX1i ? 0x20 : 0x2A, dft_mpif->UFEC_INTERRUPT.bf.UFECTX1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTERRUPT.bf.UFECTX0i", tmp_mpif->UFEC_INTERRUPT.bf.UFECTX0i, tmp_mpif->UFEC_INTERRUPT.bf.UFECTX0i == dft_mpif->UFEC_INTERRUPT.bf.UFECTX0i ? 0x20 : 0x2A, dft_mpif->UFEC_INTERRUPT.bf.UFECTX0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTERRUPT.bf.UFECRX3i", tmp_mpif->UFEC_INTERRUPT.bf.UFECRX3i, tmp_mpif->UFEC_INTERRUPT.bf.UFECRX3i == dft_mpif->UFEC_INTERRUPT.bf.UFECRX3i ? 0x20 : 0x2A, dft_mpif->UFEC_INTERRUPT.bf.UFECRX3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTERRUPT.bf.UFECRX2i", tmp_mpif->UFEC_INTERRUPT.bf.UFECRX2i, tmp_mpif->UFEC_INTERRUPT.bf.UFECRX2i == dft_mpif->UFEC_INTERRUPT.bf.UFECRX2i ? 0x20 : 0x2A, dft_mpif->UFEC_INTERRUPT.bf.UFECRX2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTERRUPT.bf.UFECRX1i", tmp_mpif->UFEC_INTERRUPT.bf.UFECRX1i, tmp_mpif->UFEC_INTERRUPT.bf.UFECRX1i == dft_mpif->UFEC_INTERRUPT.bf.UFECRX1i ? 0x20 : 0x2A, dft_mpif->UFEC_INTERRUPT.bf.UFECRX1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTERRUPT.bf.UFECRX0i", tmp_mpif->UFEC_INTERRUPT.bf.UFECRX0i, tmp_mpif->UFEC_INTERRUPT.bf.UFECRX0i == dft_mpif->UFEC_INTERRUPT.bf.UFECRX0i ? 0x20 : 0x2A, dft_mpif->UFEC_INTERRUPT.bf.UFECRX0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTENABLE.wrd", tmp_mpif->UFEC_INTENABLE.wrd, tmp_mpif->UFEC_INTENABLE.wrd == dft_mpif->UFEC_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->UFEC_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTENABLE.bf.UFECTX3e", tmp_mpif->UFEC_INTENABLE.bf.UFECTX3e, tmp_mpif->UFEC_INTENABLE.bf.UFECTX3e == dft_mpif->UFEC_INTENABLE.bf.UFECTX3e ? 0x20 : 0x2A, dft_mpif->UFEC_INTENABLE.bf.UFECTX3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTENABLE.bf.UFECTX2e", tmp_mpif->UFEC_INTENABLE.bf.UFECTX2e, tmp_mpif->UFEC_INTENABLE.bf.UFECTX2e == dft_mpif->UFEC_INTENABLE.bf.UFECTX2e ? 0x20 : 0x2A, dft_mpif->UFEC_INTENABLE.bf.UFECTX2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTENABLE.bf.UFECTX1e", tmp_mpif->UFEC_INTENABLE.bf.UFECTX1e, tmp_mpif->UFEC_INTENABLE.bf.UFECTX1e == dft_mpif->UFEC_INTENABLE.bf.UFECTX1e ? 0x20 : 0x2A, dft_mpif->UFEC_INTENABLE.bf.UFECTX1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTENABLE.bf.UFECTX0e", tmp_mpif->UFEC_INTENABLE.bf.UFECTX0e, tmp_mpif->UFEC_INTENABLE.bf.UFECTX0e == dft_mpif->UFEC_INTENABLE.bf.UFECTX0e ? 0x20 : 0x2A, dft_mpif->UFEC_INTENABLE.bf.UFECTX0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTENABLE.bf.UFECRX3e", tmp_mpif->UFEC_INTENABLE.bf.UFECRX3e, tmp_mpif->UFEC_INTENABLE.bf.UFECRX3e == dft_mpif->UFEC_INTENABLE.bf.UFECRX3e ? 0x20 : 0x2A, dft_mpif->UFEC_INTENABLE.bf.UFECRX3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTENABLE.bf.UFECRX2e", tmp_mpif->UFEC_INTENABLE.bf.UFECRX2e, tmp_mpif->UFEC_INTENABLE.bf.UFECRX2e == dft_mpif->UFEC_INTENABLE.bf.UFECRX2e ? 0x20 : 0x2A, dft_mpif->UFEC_INTENABLE.bf.UFECRX2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTENABLE.bf.UFECRX1e", tmp_mpif->UFEC_INTENABLE.bf.UFECRX1e, tmp_mpif->UFEC_INTENABLE.bf.UFECRX1e == dft_mpif->UFEC_INTENABLE.bf.UFECRX1e ? 0x20 : 0x2A, dft_mpif->UFEC_INTENABLE.bf.UFECRX1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_UFEC_INTENABLE.bf.UFECRX0e", tmp_mpif->UFEC_INTENABLE.bf.UFECRX0e, tmp_mpif->UFEC_INTENABLE.bf.UFECRX0e == dft_mpif->UFEC_INTENABLE.bf.UFECRX0e ? 0x20 : 0x2A, dft_mpif->UFEC_INTENABLE.bf.UFECRX0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.wrd", tmp_mpif->GS_INTERRUPT.wrd, tmp_mpif->GS_INTERRUPT.wrd == dft_mpif->GS_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.bf.GS9IFi", tmp_mpif->GS_INTERRUPT.bf.GS9IFi, tmp_mpif->GS_INTERRUPT.bf.GS9IFi == dft_mpif->GS_INTERRUPT.bf.GS9IFi ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.bf.GS9IFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.bf.GS8IFi", tmp_mpif->GS_INTERRUPT.bf.GS8IFi, tmp_mpif->GS_INTERRUPT.bf.GS8IFi == dft_mpif->GS_INTERRUPT.bf.GS8IFi ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.bf.GS8IFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.bf.GS7IFi", tmp_mpif->GS_INTERRUPT.bf.GS7IFi, tmp_mpif->GS_INTERRUPT.bf.GS7IFi == dft_mpif->GS_INTERRUPT.bf.GS7IFi ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.bf.GS7IFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.bf.GS6IFi", tmp_mpif->GS_INTERRUPT.bf.GS6IFi, tmp_mpif->GS_INTERRUPT.bf.GS6IFi == dft_mpif->GS_INTERRUPT.bf.GS6IFi ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.bf.GS6IFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.bf.GS5IFi", tmp_mpif->GS_INTERRUPT.bf.GS5IFi, tmp_mpif->GS_INTERRUPT.bf.GS5IFi == dft_mpif->GS_INTERRUPT.bf.GS5IFi ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.bf.GS5IFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.bf.GS4IFi", tmp_mpif->GS_INTERRUPT.bf.GS4IFi, tmp_mpif->GS_INTERRUPT.bf.GS4IFi == dft_mpif->GS_INTERRUPT.bf.GS4IFi ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.bf.GS4IFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.bf.GS3IFi", tmp_mpif->GS_INTERRUPT.bf.GS3IFi, tmp_mpif->GS_INTERRUPT.bf.GS3IFi == dft_mpif->GS_INTERRUPT.bf.GS3IFi ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.bf.GS3IFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.bf.GS2IFi", tmp_mpif->GS_INTERRUPT.bf.GS2IFi, tmp_mpif->GS_INTERRUPT.bf.GS2IFi == dft_mpif->GS_INTERRUPT.bf.GS2IFi ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.bf.GS2IFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.bf.GS1IFi", tmp_mpif->GS_INTERRUPT.bf.GS1IFi, tmp_mpif->GS_INTERRUPT.bf.GS1IFi == dft_mpif->GS_INTERRUPT.bf.GS1IFi ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.bf.GS1IFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTERRUPT.bf.GS0IFi", tmp_mpif->GS_INTERRUPT.bf.GS0IFi, tmp_mpif->GS_INTERRUPT.bf.GS0IFi == dft_mpif->GS_INTERRUPT.bf.GS0IFi ? 0x20 : 0x2A, dft_mpif->GS_INTERRUPT.bf.GS0IFi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.wrd", tmp_mpif->GS_INTENABLE.wrd, tmp_mpif->GS_INTENABLE.wrd == dft_mpif->GS_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.bf.GS9IFe", tmp_mpif->GS_INTENABLE.bf.GS9IFe, tmp_mpif->GS_INTENABLE.bf.GS9IFe == dft_mpif->GS_INTENABLE.bf.GS9IFe ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.bf.GS9IFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.bf.GS8IFe", tmp_mpif->GS_INTENABLE.bf.GS8IFe, tmp_mpif->GS_INTENABLE.bf.GS8IFe == dft_mpif->GS_INTENABLE.bf.GS8IFe ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.bf.GS8IFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.bf.GS7IFe", tmp_mpif->GS_INTENABLE.bf.GS7IFe, tmp_mpif->GS_INTENABLE.bf.GS7IFe == dft_mpif->GS_INTENABLE.bf.GS7IFe ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.bf.GS7IFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.bf.GS6IFe", tmp_mpif->GS_INTENABLE.bf.GS6IFe, tmp_mpif->GS_INTENABLE.bf.GS6IFe == dft_mpif->GS_INTENABLE.bf.GS6IFe ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.bf.GS6IFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.bf.GS5IFe", tmp_mpif->GS_INTENABLE.bf.GS5IFe, tmp_mpif->GS_INTENABLE.bf.GS5IFe == dft_mpif->GS_INTENABLE.bf.GS5IFe ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.bf.GS5IFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.bf.GS4IFe", tmp_mpif->GS_INTENABLE.bf.GS4IFe, tmp_mpif->GS_INTENABLE.bf.GS4IFe == dft_mpif->GS_INTENABLE.bf.GS4IFe ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.bf.GS4IFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.bf.GS3IFe", tmp_mpif->GS_INTENABLE.bf.GS3IFe, tmp_mpif->GS_INTENABLE.bf.GS3IFe == dft_mpif->GS_INTENABLE.bf.GS3IFe ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.bf.GS3IFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.bf.GS2IFe", tmp_mpif->GS_INTENABLE.bf.GS2IFe, tmp_mpif->GS_INTENABLE.bf.GS2IFe == dft_mpif->GS_INTENABLE.bf.GS2IFe ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.bf.GS2IFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.bf.GS1IFe", tmp_mpif->GS_INTENABLE.bf.GS1IFe, tmp_mpif->GS_INTENABLE.bf.GS1IFe == dft_mpif->GS_INTENABLE.bf.GS1IFe ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.bf.GS1IFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_INTENABLE.bf.GS0IFe", tmp_mpif->GS_INTENABLE.bf.GS0IFe, tmp_mpif->GS_INTENABLE.bf.GS0IFe == dft_mpif->GS_INTENABLE.bf.GS0IFe ? 0x20 : 0x2A, dft_mpif->GS_INTENABLE.bf.GS0IFe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.wrd", tmp_mpif->GS_ISAS.wrd, tmp_mpif->GS_ISAS.wrd == dft_mpif->GS_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->GS_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.bf.GS9IFiZ", tmp_mpif->GS_ISAS.bf.GS9IFiZ, tmp_mpif->GS_ISAS.bf.GS9IFiZ == dft_mpif->GS_ISAS.bf.GS9IFiZ ? 0x20 : 0x2A, dft_mpif->GS_ISAS.bf.GS9IFiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.bf.GS8IFiZ", tmp_mpif->GS_ISAS.bf.GS8IFiZ, tmp_mpif->GS_ISAS.bf.GS8IFiZ == dft_mpif->GS_ISAS.bf.GS8IFiZ ? 0x20 : 0x2A, dft_mpif->GS_ISAS.bf.GS8IFiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.bf.GS7IFiZ", tmp_mpif->GS_ISAS.bf.GS7IFiZ, tmp_mpif->GS_ISAS.bf.GS7IFiZ == dft_mpif->GS_ISAS.bf.GS7IFiZ ? 0x20 : 0x2A, dft_mpif->GS_ISAS.bf.GS7IFiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.bf.GS6IFiZ", tmp_mpif->GS_ISAS.bf.GS6IFiZ, tmp_mpif->GS_ISAS.bf.GS6IFiZ == dft_mpif->GS_ISAS.bf.GS6IFiZ ? 0x20 : 0x2A, dft_mpif->GS_ISAS.bf.GS6IFiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.bf.GS5IFiZ", tmp_mpif->GS_ISAS.bf.GS5IFiZ, tmp_mpif->GS_ISAS.bf.GS5IFiZ == dft_mpif->GS_ISAS.bf.GS5IFiZ ? 0x20 : 0x2A, dft_mpif->GS_ISAS.bf.GS5IFiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.bf.GS4IFiZ", tmp_mpif->GS_ISAS.bf.GS4IFiZ, tmp_mpif->GS_ISAS.bf.GS4IFiZ == dft_mpif->GS_ISAS.bf.GS4IFiZ ? 0x20 : 0x2A, dft_mpif->GS_ISAS.bf.GS4IFiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.bf.GS3IFiZ", tmp_mpif->GS_ISAS.bf.GS3IFiZ, tmp_mpif->GS_ISAS.bf.GS3IFiZ == dft_mpif->GS_ISAS.bf.GS3IFiZ ? 0x20 : 0x2A, dft_mpif->GS_ISAS.bf.GS3IFiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.bf.GS2IFiZ", tmp_mpif->GS_ISAS.bf.GS2IFiZ, tmp_mpif->GS_ISAS.bf.GS2IFiZ == dft_mpif->GS_ISAS.bf.GS2IFiZ ? 0x20 : 0x2A, dft_mpif->GS_ISAS.bf.GS2IFiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.bf.GS1IFiZ", tmp_mpif->GS_ISAS.bf.GS1IFiZ, tmp_mpif->GS_ISAS.bf.GS1IFiZ == dft_mpif->GS_ISAS.bf.GS1IFiZ ? 0x20 : 0x2A, dft_mpif->GS_ISAS.bf.GS1IFiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GS_ISAS.bf.GS0IFiZ", tmp_mpif->GS_ISAS.bf.GS0IFiZ, tmp_mpif->GS_ISAS.bf.GS0IFiZ == dft_mpif->GS_ISAS.bf.GS0IFiZ ? 0x20 : 0x2A, dft_mpif->GS_ISAS.bf.GS0IFiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.wrd", tmp_mpif->GPLL_INTERRUPT.wrd, tmp_mpif->GPLL_INTERRUPT.wrd == dft_mpif->GPLL_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.TXB3i", tmp_mpif->GPLL_INTERRUPT.bf.TXB3i, tmp_mpif->GPLL_INTERRUPT.bf.TXB3i == dft_mpif->GPLL_INTERRUPT.bf.TXB3i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.TXB3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.TXB2i", tmp_mpif->GPLL_INTERRUPT.bf.TXB2i, tmp_mpif->GPLL_INTERRUPT.bf.TXB2i == dft_mpif->GPLL_INTERRUPT.bf.TXB2i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.TXB2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.TXB1i", tmp_mpif->GPLL_INTERRUPT.bf.TXB1i, tmp_mpif->GPLL_INTERRUPT.bf.TXB1i == dft_mpif->GPLL_INTERRUPT.bf.TXB1i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.TXB1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.TXB0i", tmp_mpif->GPLL_INTERRUPT.bf.TXB0i, tmp_mpif->GPLL_INTERRUPT.bf.TXB0i == dft_mpif->GPLL_INTERRUPT.bf.TXB0i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.TXB0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.TXA3i", tmp_mpif->GPLL_INTERRUPT.bf.TXA3i, tmp_mpif->GPLL_INTERRUPT.bf.TXA3i == dft_mpif->GPLL_INTERRUPT.bf.TXA3i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.TXA3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.TXA2i", tmp_mpif->GPLL_INTERRUPT.bf.TXA2i, tmp_mpif->GPLL_INTERRUPT.bf.TXA2i == dft_mpif->GPLL_INTERRUPT.bf.TXA2i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.TXA2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.TXA1i", tmp_mpif->GPLL_INTERRUPT.bf.TXA1i, tmp_mpif->GPLL_INTERRUPT.bf.TXA1i == dft_mpif->GPLL_INTERRUPT.bf.TXA1i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.TXA1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.TXA0i", tmp_mpif->GPLL_INTERRUPT.bf.TXA0i, tmp_mpif->GPLL_INTERRUPT.bf.TXA0i == dft_mpif->GPLL_INTERRUPT.bf.TXA0i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.TXA0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.RXB3i", tmp_mpif->GPLL_INTERRUPT.bf.RXB3i, tmp_mpif->GPLL_INTERRUPT.bf.RXB3i == dft_mpif->GPLL_INTERRUPT.bf.RXB3i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.RXB3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.RXB2i", tmp_mpif->GPLL_INTERRUPT.bf.RXB2i, tmp_mpif->GPLL_INTERRUPT.bf.RXB2i == dft_mpif->GPLL_INTERRUPT.bf.RXB2i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.RXB2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.RXB1i", tmp_mpif->GPLL_INTERRUPT.bf.RXB1i, tmp_mpif->GPLL_INTERRUPT.bf.RXB1i == dft_mpif->GPLL_INTERRUPT.bf.RXB1i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.RXB1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.RXB0i", tmp_mpif->GPLL_INTERRUPT.bf.RXB0i, tmp_mpif->GPLL_INTERRUPT.bf.RXB0i == dft_mpif->GPLL_INTERRUPT.bf.RXB0i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.RXB0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.RXA3i", tmp_mpif->GPLL_INTERRUPT.bf.RXA3i, tmp_mpif->GPLL_INTERRUPT.bf.RXA3i == dft_mpif->GPLL_INTERRUPT.bf.RXA3i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.RXA3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.RXA2i", tmp_mpif->GPLL_INTERRUPT.bf.RXA2i, tmp_mpif->GPLL_INTERRUPT.bf.RXA2i == dft_mpif->GPLL_INTERRUPT.bf.RXA2i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.RXA2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.RXA1i", tmp_mpif->GPLL_INTERRUPT.bf.RXA1i, tmp_mpif->GPLL_INTERRUPT.bf.RXA1i == dft_mpif->GPLL_INTERRUPT.bf.RXA1i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.RXA1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTERRUPT.bf.RXA0i", tmp_mpif->GPLL_INTERRUPT.bf.RXA0i, tmp_mpif->GPLL_INTERRUPT.bf.RXA0i == dft_mpif->GPLL_INTERRUPT.bf.RXA0i ? 0x20 : 0x2A, dft_mpif->GPLL_INTERRUPT.bf.RXA0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.wrd", tmp_mpif->GPLL_INTENABLE.wrd, tmp_mpif->GPLL_INTENABLE.wrd == dft_mpif->GPLL_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.TXB3e", tmp_mpif->GPLL_INTENABLE.bf.TXB3e, tmp_mpif->GPLL_INTENABLE.bf.TXB3e == dft_mpif->GPLL_INTENABLE.bf.TXB3e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.TXB3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.TXB2e", tmp_mpif->GPLL_INTENABLE.bf.TXB2e, tmp_mpif->GPLL_INTENABLE.bf.TXB2e == dft_mpif->GPLL_INTENABLE.bf.TXB2e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.TXB2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.TXB1e", tmp_mpif->GPLL_INTENABLE.bf.TXB1e, tmp_mpif->GPLL_INTENABLE.bf.TXB1e == dft_mpif->GPLL_INTENABLE.bf.TXB1e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.TXB1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.TXB0e", tmp_mpif->GPLL_INTENABLE.bf.TXB0e, tmp_mpif->GPLL_INTENABLE.bf.TXB0e == dft_mpif->GPLL_INTENABLE.bf.TXB0e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.TXB0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.TXA3e", tmp_mpif->GPLL_INTENABLE.bf.TXA3e, tmp_mpif->GPLL_INTENABLE.bf.TXA3e == dft_mpif->GPLL_INTENABLE.bf.TXA3e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.TXA3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.TXA2e", tmp_mpif->GPLL_INTENABLE.bf.TXA2e, tmp_mpif->GPLL_INTENABLE.bf.TXA2e == dft_mpif->GPLL_INTENABLE.bf.TXA2e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.TXA2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.TXA1e", tmp_mpif->GPLL_INTENABLE.bf.TXA1e, tmp_mpif->GPLL_INTENABLE.bf.TXA1e == dft_mpif->GPLL_INTENABLE.bf.TXA1e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.TXA1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.TXA0e", tmp_mpif->GPLL_INTENABLE.bf.TXA0e, tmp_mpif->GPLL_INTENABLE.bf.TXA0e == dft_mpif->GPLL_INTENABLE.bf.TXA0e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.TXA0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.RXB3e", tmp_mpif->GPLL_INTENABLE.bf.RXB3e, tmp_mpif->GPLL_INTENABLE.bf.RXB3e == dft_mpif->GPLL_INTENABLE.bf.RXB3e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.RXB3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.RXB2e", tmp_mpif->GPLL_INTENABLE.bf.RXB2e, tmp_mpif->GPLL_INTENABLE.bf.RXB2e == dft_mpif->GPLL_INTENABLE.bf.RXB2e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.RXB2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.RXB1e", tmp_mpif->GPLL_INTENABLE.bf.RXB1e, tmp_mpif->GPLL_INTENABLE.bf.RXB1e == dft_mpif->GPLL_INTENABLE.bf.RXB1e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.RXB1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.RXB0e", tmp_mpif->GPLL_INTENABLE.bf.RXB0e, tmp_mpif->GPLL_INTENABLE.bf.RXB0e == dft_mpif->GPLL_INTENABLE.bf.RXB0e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.RXB0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.RXA3e", tmp_mpif->GPLL_INTENABLE.bf.RXA3e, tmp_mpif->GPLL_INTENABLE.bf.RXA3e == dft_mpif->GPLL_INTENABLE.bf.RXA3e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.RXA3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.RXA2e", tmp_mpif->GPLL_INTENABLE.bf.RXA2e, tmp_mpif->GPLL_INTENABLE.bf.RXA2e == dft_mpif->GPLL_INTENABLE.bf.RXA2e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.RXA2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.RXA1e", tmp_mpif->GPLL_INTENABLE.bf.RXA1e, tmp_mpif->GPLL_INTENABLE.bf.RXA1e == dft_mpif->GPLL_INTENABLE.bf.RXA1e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.RXA1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPLL_INTENABLE.bf.RXA0e", tmp_mpif->GPLL_INTENABLE.bf.RXA0e, tmp_mpif->GPLL_INTENABLE.bf.RXA0e == dft_mpif->GPLL_INTENABLE.bf.RXA0e ? 0x20 : 0x2A, dft_mpif->GPLL_INTENABLE.bf.RXA0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.wrd", tmp_mpif->SYNCDSYNC_INTERRUPT.wrd, tmp_mpif->SYNCDSYNC_INTERRUPT.wrd == dft_mpif->SYNCDSYNC_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.TXB3i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXB3i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXB3i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXB3i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXB3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.TXB2i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXB2i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXB2i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXB2i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXB2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.TXB1i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXB1i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXB1i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXB1i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXB1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.TXB0i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXB0i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXB0i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXB0i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXB0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.TXA3i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXA3i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXA3i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXA3i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXA3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.TXA2i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXA2i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXA2i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXA2i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXA2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.TXA1i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXA1i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXA1i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXA1i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXA1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.TXA0i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXA0i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.TXA0i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXA0i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.TXA0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.RXB3i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXB3i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXB3i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXB3i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXB3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.RXB2i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXB2i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXB2i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXB2i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXB2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.RXB1i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXB1i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXB1i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXB1i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXB1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.RXB0i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXB0i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXB0i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXB0i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXB0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.RXA3i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXA3i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXA3i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXA3i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXA3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.RXA2i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXA2i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXA2i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXA2i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXA2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.RXA1i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXA1i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXA1i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXA1i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXA1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTERRUPT.bf.RXA0i", tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXA0i, tmp_mpif->SYNCDSYNC_INTERRUPT.bf.RXA0i == dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXA0i ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTERRUPT.bf.RXA0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.wrd", tmp_mpif->SYNCDSYNC_INTENABLE.wrd, tmp_mpif->SYNCDSYNC_INTENABLE.wrd == dft_mpif->SYNCDSYNC_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.TXB3e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXB3e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXB3e == dft_mpif->SYNCDSYNC_INTENABLE.bf.TXB3e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.TXB3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.TXB2e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXB2e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXB2e == dft_mpif->SYNCDSYNC_INTENABLE.bf.TXB2e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.TXB2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.TXB1e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXB1e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXB1e == dft_mpif->SYNCDSYNC_INTENABLE.bf.TXB1e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.TXB1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.TXB0e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXB0e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXB0e == dft_mpif->SYNCDSYNC_INTENABLE.bf.TXB0e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.TXB0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.TXA3e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXA3e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXA3e == dft_mpif->SYNCDSYNC_INTENABLE.bf.TXA3e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.TXA3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.TXA2e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXA2e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXA2e == dft_mpif->SYNCDSYNC_INTENABLE.bf.TXA2e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.TXA2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.TXA1e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXA1e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXA1e == dft_mpif->SYNCDSYNC_INTENABLE.bf.TXA1e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.TXA1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.TXA0e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXA0e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.TXA0e == dft_mpif->SYNCDSYNC_INTENABLE.bf.TXA0e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.TXA0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.RXB3e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXB3e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXB3e == dft_mpif->SYNCDSYNC_INTENABLE.bf.RXB3e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.RXB3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.RXB2e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXB2e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXB2e == dft_mpif->SYNCDSYNC_INTENABLE.bf.RXB2e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.RXB2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.RXB1e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXB1e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXB1e == dft_mpif->SYNCDSYNC_INTENABLE.bf.RXB1e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.RXB1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.RXB0e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXB0e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXB0e == dft_mpif->SYNCDSYNC_INTENABLE.bf.RXB0e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.RXB0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.RXA3e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXA3e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXA3e == dft_mpif->SYNCDSYNC_INTENABLE.bf.RXA3e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.RXA3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.RXA2e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXA2e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXA2e == dft_mpif->SYNCDSYNC_INTENABLE.bf.RXA2e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.RXA2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.RXA1e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXA1e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXA1e == dft_mpif->SYNCDSYNC_INTENABLE.bf.RXA1e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.RXA1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYNCDSYNC_INTENABLE.bf.RXA0e", tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXA0e, tmp_mpif->SYNCDSYNC_INTENABLE.bf.RXA0e == dft_mpif->SYNCDSYNC_INTENABLE.bf.RXA0e ? 0x20 : 0x2A, dft_mpif->SYNCDSYNC_INTENABLE.bf.RXA0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_INTERRUPT.wrd", tmp_mpif->CLOCK_LOSS_INTERRUPT.wrd, tmp_mpif->CLOCK_LOSS_INTERRUPT.wrd == dft_mpif->CLOCK_LOSS_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_INTERRUPT.bf.TXBi", tmp_mpif->CLOCK_LOSS_INTERRUPT.bf.TXBi, tmp_mpif->CLOCK_LOSS_INTERRUPT.bf.TXBi == dft_mpif->CLOCK_LOSS_INTERRUPT.bf.TXBi ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_INTERRUPT.bf.TXBi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_INTERRUPT.bf.TXAi", tmp_mpif->CLOCK_LOSS_INTERRUPT.bf.TXAi, tmp_mpif->CLOCK_LOSS_INTERRUPT.bf.TXAi == dft_mpif->CLOCK_LOSS_INTERRUPT.bf.TXAi ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_INTERRUPT.bf.TXAi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_INTERRUPT.bf.RXBi", tmp_mpif->CLOCK_LOSS_INTERRUPT.bf.RXBi, tmp_mpif->CLOCK_LOSS_INTERRUPT.bf.RXBi == dft_mpif->CLOCK_LOSS_INTERRUPT.bf.RXBi ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_INTERRUPT.bf.RXBi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_INTERRUPT.bf.RXAi", tmp_mpif->CLOCK_LOSS_INTERRUPT.bf.RXAi, tmp_mpif->CLOCK_LOSS_INTERRUPT.bf.RXAi == dft_mpif->CLOCK_LOSS_INTERRUPT.bf.RXAi ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_INTERRUPT.bf.RXAi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_INTENABLE.wrd", tmp_mpif->CLOCK_LOSS_INTENABLE.wrd, tmp_mpif->CLOCK_LOSS_INTENABLE.wrd == dft_mpif->CLOCK_LOSS_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_INTENABLE.bf.TXBe", tmp_mpif->CLOCK_LOSS_INTENABLE.bf.TXBe, tmp_mpif->CLOCK_LOSS_INTENABLE.bf.TXBe == dft_mpif->CLOCK_LOSS_INTENABLE.bf.TXBe ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_INTENABLE.bf.TXBe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_INTENABLE.bf.TXAe", tmp_mpif->CLOCK_LOSS_INTENABLE.bf.TXAe, tmp_mpif->CLOCK_LOSS_INTENABLE.bf.TXAe == dft_mpif->CLOCK_LOSS_INTENABLE.bf.TXAe ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_INTENABLE.bf.TXAe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_INTENABLE.bf.RXBe", tmp_mpif->CLOCK_LOSS_INTENABLE.bf.RXBe, tmp_mpif->CLOCK_LOSS_INTENABLE.bf.RXBe == dft_mpif->CLOCK_LOSS_INTENABLE.bf.RXBe ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_INTENABLE.bf.RXBe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_INTENABLE.bf.RXAe", tmp_mpif->CLOCK_LOSS_INTENABLE.bf.RXAe, tmp_mpif->CLOCK_LOSS_INTENABLE.bf.RXAe == dft_mpif->CLOCK_LOSS_INTENABLE.bf.RXAe ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_INTENABLE.bf.RXAe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_STATUS.wrd", tmp_mpif->CLOCK_LOSS_STATUS.wrd, tmp_mpif->CLOCK_LOSS_STATUS.wrd == dft_mpif->CLOCK_LOSS_STATUS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_STATUS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_STATUS.bf.TXBiO", tmp_mpif->CLOCK_LOSS_STATUS.bf.TXBiO, tmp_mpif->CLOCK_LOSS_STATUS.bf.TXBiO == dft_mpif->CLOCK_LOSS_STATUS.bf.TXBiO ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_STATUS.bf.TXBiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_STATUS.bf.TXAiO", tmp_mpif->CLOCK_LOSS_STATUS.bf.TXAiO, tmp_mpif->CLOCK_LOSS_STATUS.bf.TXAiO == dft_mpif->CLOCK_LOSS_STATUS.bf.TXAiO ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_STATUS.bf.TXAiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_STATUS.bf.RXBiO", tmp_mpif->CLOCK_LOSS_STATUS.bf.RXBiO, tmp_mpif->CLOCK_LOSS_STATUS.bf.RXBiO == dft_mpif->CLOCK_LOSS_STATUS.bf.RXBiO ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_STATUS.bf.RXBiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_STATUS.bf.RXAiO", tmp_mpif->CLOCK_LOSS_STATUS.bf.RXAiO, tmp_mpif->CLOCK_LOSS_STATUS.bf.RXAiO == dft_mpif->CLOCK_LOSS_STATUS.bf.RXAiO ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_STATUS.bf.RXAiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_ISAS.wrd", tmp_mpif->CLOCK_LOSS_ISAS.wrd, tmp_mpif->CLOCK_LOSS_ISAS.wrd == dft_mpif->CLOCK_LOSS_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_ISAS.bf.TXBiZ", tmp_mpif->CLOCK_LOSS_ISAS.bf.TXBiZ, tmp_mpif->CLOCK_LOSS_ISAS.bf.TXBiZ == dft_mpif->CLOCK_LOSS_ISAS.bf.TXBiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_ISAS.bf.TXBiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_ISAS.bf.TXAiZ", tmp_mpif->CLOCK_LOSS_ISAS.bf.TXAiZ, tmp_mpif->CLOCK_LOSS_ISAS.bf.TXAiZ == dft_mpif->CLOCK_LOSS_ISAS.bf.TXAiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_ISAS.bf.TXAiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_ISAS.bf.RXBiZ", tmp_mpif->CLOCK_LOSS_ISAS.bf.RXBiZ, tmp_mpif->CLOCK_LOSS_ISAS.bf.RXBiZ == dft_mpif->CLOCK_LOSS_ISAS.bf.RXBiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_ISAS.bf.RXBiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_LOSS_ISAS.bf.RXAiZ", tmp_mpif->CLOCK_LOSS_ISAS.bf.RXAiZ, tmp_mpif->CLOCK_LOSS_ISAS.bf.RXAiZ == dft_mpif->CLOCK_LOSS_ISAS.bf.RXAiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_LOSS_ISAS.bf.RXAiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_INTERRUPT.wrd", tmp_mpif->XLOS_INTERRUPT.wrd, tmp_mpif->XLOS_INTERRUPT.wrd == dft_mpif->XLOS_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->XLOS_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_INTERRUPT.bf.XFIi", tmp_mpif->XLOS_INTERRUPT.bf.XFIi, tmp_mpif->XLOS_INTERRUPT.bf.XFIi == dft_mpif->XLOS_INTERRUPT.bf.XFIi ? 0x20 : 0x2A, dft_mpif->XLOS_INTERRUPT.bf.XFIi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_INTERRUPT.bf.MRBi", tmp_mpif->XLOS_INTERRUPT.bf.MRBi, tmp_mpif->XLOS_INTERRUPT.bf.MRBi == dft_mpif->XLOS_INTERRUPT.bf.MRBi ? 0x20 : 0x2A, dft_mpif->XLOS_INTERRUPT.bf.MRBi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_INTERRUPT.bf.MRAi", tmp_mpif->XLOS_INTERRUPT.bf.MRAi, tmp_mpif->XLOS_INTERRUPT.bf.MRAi == dft_mpif->XLOS_INTERRUPT.bf.MRAi ? 0x20 : 0x2A, dft_mpif->XLOS_INTERRUPT.bf.MRAi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_INTENABLE.wrd", tmp_mpif->XLOS_INTENABLE.wrd, tmp_mpif->XLOS_INTENABLE.wrd == dft_mpif->XLOS_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->XLOS_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_INTENABLE.bf.XFIe", tmp_mpif->XLOS_INTENABLE.bf.XFIe, tmp_mpif->XLOS_INTENABLE.bf.XFIe == dft_mpif->XLOS_INTENABLE.bf.XFIe ? 0x20 : 0x2A, dft_mpif->XLOS_INTENABLE.bf.XFIe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_INTENABLE.bf.MRBe", tmp_mpif->XLOS_INTENABLE.bf.MRBe, tmp_mpif->XLOS_INTENABLE.bf.MRBe == dft_mpif->XLOS_INTENABLE.bf.MRBe ? 0x20 : 0x2A, dft_mpif->XLOS_INTENABLE.bf.MRBe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_INTENABLE.bf.MRAe", tmp_mpif->XLOS_INTENABLE.bf.MRAe, tmp_mpif->XLOS_INTENABLE.bf.MRAe == dft_mpif->XLOS_INTENABLE.bf.MRAe ? 0x20 : 0x2A, dft_mpif->XLOS_INTENABLE.bf.MRAe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_STATUS.wrd", tmp_mpif->XLOS_STATUS.wrd, tmp_mpif->XLOS_STATUS.wrd == dft_mpif->XLOS_STATUS.wrd ? 0x20 : 0x2A, dft_mpif->XLOS_STATUS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_STATUS.bf.XFIiO", tmp_mpif->XLOS_STATUS.bf.XFIiO, tmp_mpif->XLOS_STATUS.bf.XFIiO == dft_mpif->XLOS_STATUS.bf.XFIiO ? 0x20 : 0x2A, dft_mpif->XLOS_STATUS.bf.XFIiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_STATUS.bf.MRBiO", tmp_mpif->XLOS_STATUS.bf.MRBiO, tmp_mpif->XLOS_STATUS.bf.MRBiO == dft_mpif->XLOS_STATUS.bf.MRBiO ? 0x20 : 0x2A, dft_mpif->XLOS_STATUS.bf.MRBiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_STATUS.bf.MRAiO", tmp_mpif->XLOS_STATUS.bf.MRAiO, tmp_mpif->XLOS_STATUS.bf.MRAiO == dft_mpif->XLOS_STATUS.bf.MRAiO ? 0x20 : 0x2A, dft_mpif->XLOS_STATUS.bf.MRAiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_ISAS.wrd", tmp_mpif->XLOS_ISAS.wrd, tmp_mpif->XLOS_ISAS.wrd == dft_mpif->XLOS_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->XLOS_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_ISAS.bf.XFIiZ", tmp_mpif->XLOS_ISAS.bf.XFIiZ, tmp_mpif->XLOS_ISAS.bf.XFIiZ == dft_mpif->XLOS_ISAS.bf.XFIiZ ? 0x20 : 0x2A, dft_mpif->XLOS_ISAS.bf.XFIiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_ISAS.bf.MRBiZ", tmp_mpif->XLOS_ISAS.bf.MRBiZ, tmp_mpif->XLOS_ISAS.bf.MRBiZ == dft_mpif->XLOS_ISAS.bf.MRBiZ ? 0x20 : 0x2A, dft_mpif->XLOS_ISAS.bf.MRBiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XLOS_ISAS.bf.MRAiZ", tmp_mpif->XLOS_ISAS.bf.MRAiZ, tmp_mpif->XLOS_ISAS.bf.MRAiZ == dft_mpif->XLOS_ISAS.bf.MRAiZ ? 0x20 : 0x2A, dft_mpif->XLOS_ISAS.bf.MRAiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_INTERRUPT.wrd", tmp_mpif->SYS_INTERRUPT.wrd, tmp_mpif->SYS_INTERRUPT.wrd == dft_mpif->SYS_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->SYS_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_INTERRUPT.bf.GPLLi", tmp_mpif->SYS_INTERRUPT.bf.GPLLi, tmp_mpif->SYS_INTERRUPT.bf.GPLLi == dft_mpif->SYS_INTERRUPT.bf.GPLLi ? 0x20 : 0x2A, dft_mpif->SYS_INTERRUPT.bf.GPLLi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_INTERRUPT.bf.CLKLOSSi", tmp_mpif->SYS_INTERRUPT.bf.CLKLOSSi, tmp_mpif->SYS_INTERRUPT.bf.CLKLOSSi == dft_mpif->SYS_INTERRUPT.bf.CLKLOSSi ? 0x20 : 0x2A, dft_mpif->SYS_INTERRUPT.bf.CLKLOSSi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_INTENABLE.wrd", tmp_mpif->SYS_INTENABLE.wrd, tmp_mpif->SYS_INTENABLE.wrd == dft_mpif->SYS_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->SYS_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_INTENABLE.bf.GPLLe", tmp_mpif->SYS_INTENABLE.bf.GPLLe, tmp_mpif->SYS_INTENABLE.bf.GPLLe == dft_mpif->SYS_INTENABLE.bf.GPLLe ? 0x20 : 0x2A, dft_mpif->SYS_INTENABLE.bf.GPLLe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_INTENABLE.bf.CLKLOSSe", tmp_mpif->SYS_INTENABLE.bf.CLKLOSSe, tmp_mpif->SYS_INTENABLE.bf.CLKLOSSe == dft_mpif->SYS_INTENABLE.bf.CLKLOSSe ? 0x20 : 0x2A, dft_mpif->SYS_INTENABLE.bf.CLKLOSSe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MPIF_INTERRUPT.wrd", tmp_mpif->MPIF_INTERRUPT.wrd, tmp_mpif->MPIF_INTERRUPT.wrd == dft_mpif->MPIF_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->MPIF_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MPIF_INTERRUPT.bf.buserri", tmp_mpif->MPIF_INTERRUPT.bf.buserri, tmp_mpif->MPIF_INTERRUPT.bf.buserri == dft_mpif->MPIF_INTERRUPT.bf.buserri ? 0x20 : 0x2A, dft_mpif->MPIF_INTERRUPT.bf.buserri);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MPIF_INTENABLE.wrd", tmp_mpif->MPIF_INTENABLE.wrd, tmp_mpif->MPIF_INTENABLE.wrd == dft_mpif->MPIF_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->MPIF_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MPIF_INTENABLE.bf.buserre", tmp_mpif->MPIF_INTENABLE.bf.buserre, tmp_mpif->MPIF_INTENABLE.bf.buserre == dft_mpif->MPIF_INTENABLE.bf.buserre ? 0x20 : 0x2A, dft_mpif->MPIF_INTENABLE.bf.buserre);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MPIF_ISAS.wrd", tmp_mpif->MPIF_ISAS.wrd, tmp_mpif->MPIF_ISAS.wrd == dft_mpif->MPIF_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->MPIF_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MPIF_ISAS.bf.buserriZ", tmp_mpif->MPIF_ISAS.bf.buserriZ, tmp_mpif->MPIF_ISAS.bf.buserriZ == dft_mpif->MPIF_ISAS.bf.buserriZ ? 0x20 : 0x2A, dft_mpif->MPIF_ISAS.bf.buserriZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_R_INTERRUPT.wrd", tmp_mpif->GPIO_R_INTERRUPT.wrd, tmp_mpif->GPIO_R_INTERRUPT.wrd == dft_mpif->GPIO_R_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->GPIO_R_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_R_INTERRUPT.bf.ri", tmp_mpif->GPIO_R_INTERRUPT.bf.ri, tmp_mpif->GPIO_R_INTERRUPT.bf.ri == dft_mpif->GPIO_R_INTERRUPT.bf.ri ? 0x20 : 0x2A, dft_mpif->GPIO_R_INTERRUPT.bf.ri);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_R_INTENABLE.wrd", tmp_mpif->GPIO_R_INTENABLE.wrd, tmp_mpif->GPIO_R_INTENABLE.wrd == dft_mpif->GPIO_R_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->GPIO_R_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_R_INTENABLE.bf.re", tmp_mpif->GPIO_R_INTENABLE.bf.re, tmp_mpif->GPIO_R_INTENABLE.bf.re == dft_mpif->GPIO_R_INTENABLE.bf.re ? 0x20 : 0x2A, dft_mpif->GPIO_R_INTENABLE.bf.re);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_R_ISAS.wrd", tmp_mpif->GPIO_R_ISAS.wrd, tmp_mpif->GPIO_R_ISAS.wrd == dft_mpif->GPIO_R_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->GPIO_R_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_R_ISAS.bf.riZ", tmp_mpif->GPIO_R_ISAS.bf.riZ, tmp_mpif->GPIO_R_ISAS.bf.riZ == dft_mpif->GPIO_R_ISAS.bf.riZ ? 0x20 : 0x2A, dft_mpif->GPIO_R_ISAS.bf.riZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_F_INTERRUPT.wrd", tmp_mpif->GPIO_F_INTERRUPT.wrd, tmp_mpif->GPIO_F_INTERRUPT.wrd == dft_mpif->GPIO_F_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->GPIO_F_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_F_INTERRUPT.bf.fi", tmp_mpif->GPIO_F_INTERRUPT.bf.fi, tmp_mpif->GPIO_F_INTERRUPT.bf.fi == dft_mpif->GPIO_F_INTERRUPT.bf.fi ? 0x20 : 0x2A, dft_mpif->GPIO_F_INTERRUPT.bf.fi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_F_INTENABLE.wrd", tmp_mpif->GPIO_F_INTENABLE.wrd, tmp_mpif->GPIO_F_INTENABLE.wrd == dft_mpif->GPIO_F_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->GPIO_F_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_F_INTENABLE.bf.fe", tmp_mpif->GPIO_F_INTENABLE.bf.fe, tmp_mpif->GPIO_F_INTENABLE.bf.fe == dft_mpif->GPIO_F_INTENABLE.bf.fe ? 0x20 : 0x2A, dft_mpif->GPIO_F_INTENABLE.bf.fe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_F_ISAS.wrd", tmp_mpif->GPIO_F_ISAS.wrd, tmp_mpif->GPIO_F_ISAS.wrd == dft_mpif->GPIO_F_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->GPIO_F_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_F_ISAS.bf.fiZ", tmp_mpif->GPIO_F_ISAS.bf.fiZ, tmp_mpif->GPIO_F_ISAS.bf.fiZ == dft_mpif->GPIO_F_ISAS.bf.fiZ ? 0x20 : 0x2A, dft_mpif->GPIO_F_ISAS.bf.fiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTERRUPT.wrd", tmp_mpif->XFI_INTERRUPT.wrd, tmp_mpif->XFI_INTERRUPT.wrd == dft_mpif->XFI_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->XFI_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTERRUPT.bf.ECCi", tmp_mpif->XFI_INTERRUPT.bf.ECCi, tmp_mpif->XFI_INTERRUPT.bf.ECCi == dft_mpif->XFI_INTERRUPT.bf.ECCi ? 0x20 : 0x2A, dft_mpif->XFI_INTERRUPT.bf.ECCi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTERRUPT.bf.XFI3i", tmp_mpif->XFI_INTERRUPT.bf.XFI3i, tmp_mpif->XFI_INTERRUPT.bf.XFI3i == dft_mpif->XFI_INTERRUPT.bf.XFI3i ? 0x20 : 0x2A, dft_mpif->XFI_INTERRUPT.bf.XFI3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTERRUPT.bf.XFI2i", tmp_mpif->XFI_INTERRUPT.bf.XFI2i, tmp_mpif->XFI_INTERRUPT.bf.XFI2i == dft_mpif->XFI_INTERRUPT.bf.XFI2i ? 0x20 : 0x2A, dft_mpif->XFI_INTERRUPT.bf.XFI2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTERRUPT.bf.XFI1i", tmp_mpif->XFI_INTERRUPT.bf.XFI1i, tmp_mpif->XFI_INTERRUPT.bf.XFI1i == dft_mpif->XFI_INTERRUPT.bf.XFI1i ? 0x20 : 0x2A, dft_mpif->XFI_INTERRUPT.bf.XFI1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTERRUPT.bf.XFI0i", tmp_mpif->XFI_INTERRUPT.bf.XFI0i, tmp_mpif->XFI_INTERRUPT.bf.XFI0i == dft_mpif->XFI_INTERRUPT.bf.XFI0i ? 0x20 : 0x2A, dft_mpif->XFI_INTERRUPT.bf.XFI0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTENABLE.wrd", tmp_mpif->XFI_INTENABLE.wrd, tmp_mpif->XFI_INTENABLE.wrd == dft_mpif->XFI_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->XFI_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTENABLE.bf.ECCe", tmp_mpif->XFI_INTENABLE.bf.ECCe, tmp_mpif->XFI_INTENABLE.bf.ECCe == dft_mpif->XFI_INTENABLE.bf.ECCe ? 0x20 : 0x2A, dft_mpif->XFI_INTENABLE.bf.ECCe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTENABLE.bf.XFI3e", tmp_mpif->XFI_INTENABLE.bf.XFI3e, tmp_mpif->XFI_INTENABLE.bf.XFI3e == dft_mpif->XFI_INTENABLE.bf.XFI3e ? 0x20 : 0x2A, dft_mpif->XFI_INTENABLE.bf.XFI3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTENABLE.bf.XFI2e", tmp_mpif->XFI_INTENABLE.bf.XFI2e, tmp_mpif->XFI_INTENABLE.bf.XFI2e == dft_mpif->XFI_INTENABLE.bf.XFI2e ? 0x20 : 0x2A, dft_mpif->XFI_INTENABLE.bf.XFI2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTENABLE.bf.XFI1e", tmp_mpif->XFI_INTENABLE.bf.XFI1e, tmp_mpif->XFI_INTENABLE.bf.XFI1e == dft_mpif->XFI_INTENABLE.bf.XFI1e ? 0x20 : 0x2A, dft_mpif->XFI_INTENABLE.bf.XFI1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_INTENABLE.bf.XFI0e", tmp_mpif->XFI_INTENABLE.bf.XFI0e, tmp_mpif->XFI_INTENABLE.bf.XFI0e == dft_mpif->XFI_INTENABLE.bf.XFI0e ? 0x20 : 0x2A, dft_mpif->XFI_INTENABLE.bf.XFI0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_ECC_INTERRUPT.wrd", tmp_mpif->XFI_ECC_INTERRUPT.wrd, tmp_mpif->XFI_ECC_INTERRUPT.wrd == dft_mpif->XFI_ECC_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->XFI_ECC_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_ECC_INTERRUPT.bf.DBLi", tmp_mpif->XFI_ECC_INTERRUPT.bf.DBLi, tmp_mpif->XFI_ECC_INTERRUPT.bf.DBLi == dft_mpif->XFI_ECC_INTERRUPT.bf.DBLi ? 0x20 : 0x2A, dft_mpif->XFI_ECC_INTERRUPT.bf.DBLi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_ECC_INTERRUPT.bf.SGLi", tmp_mpif->XFI_ECC_INTERRUPT.bf.SGLi, tmp_mpif->XFI_ECC_INTERRUPT.bf.SGLi == dft_mpif->XFI_ECC_INTERRUPT.bf.SGLi ? 0x20 : 0x2A, dft_mpif->XFI_ECC_INTERRUPT.bf.SGLi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_ECC_INTENABLE.wrd", tmp_mpif->XFI_ECC_INTENABLE.wrd, tmp_mpif->XFI_ECC_INTENABLE.wrd == dft_mpif->XFI_ECC_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->XFI_ECC_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_ECC_INTENABLE.bf.DBLe", tmp_mpif->XFI_ECC_INTENABLE.bf.DBLe, tmp_mpif->XFI_ECC_INTENABLE.bf.DBLe == dft_mpif->XFI_ECC_INTENABLE.bf.DBLe ? 0x20 : 0x2A, dft_mpif->XFI_ECC_INTENABLE.bf.DBLe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_ECC_INTENABLE.bf.SGLe", tmp_mpif->XFI_ECC_INTENABLE.bf.SGLe, tmp_mpif->XFI_ECC_INTENABLE.bf.SGLe == dft_mpif->XFI_ECC_INTENABLE.bf.SGLe ? 0x20 : 0x2A, dft_mpif->XFI_ECC_INTENABLE.bf.SGLe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_ECC_ISAS.wrd", tmp_mpif->XFI_ECC_ISAS.wrd, tmp_mpif->XFI_ECC_ISAS.wrd == dft_mpif->XFI_ECC_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->XFI_ECC_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_ECC_ISAS.bf.DBLiZ", tmp_mpif->XFI_ECC_ISAS.bf.DBLiZ, tmp_mpif->XFI_ECC_ISAS.bf.DBLiZ == dft_mpif->XFI_ECC_ISAS.bf.DBLiZ ? 0x20 : 0x2A, dft_mpif->XFI_ECC_ISAS.bf.DBLiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_XFI_ECC_ISAS.bf.SGLiZ", tmp_mpif->XFI_ECC_ISAS.bf.SGLiZ, tmp_mpif->XFI_ECC_ISAS.bf.SGLiZ == dft_mpif->XFI_ECC_ISAS.bf.SGLiZ ? 0x20 : 0x2A, dft_mpif->XFI_ECC_ISAS.bf.SGLiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_CLK_FAIL_INTERRUPT.wrd", tmp_mpif->SYS_CLK_FAIL_INTERRUPT.wrd, tmp_mpif->SYS_CLK_FAIL_INTERRUPT.wrd == dft_mpif->SYS_CLK_FAIL_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->SYS_CLK_FAIL_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_CLK_FAIL_INTERRUPT.bf.faili", tmp_mpif->SYS_CLK_FAIL_INTERRUPT.bf.faili, tmp_mpif->SYS_CLK_FAIL_INTERRUPT.bf.faili == dft_mpif->SYS_CLK_FAIL_INTERRUPT.bf.faili ? 0x20 : 0x2A, dft_mpif->SYS_CLK_FAIL_INTERRUPT.bf.faili);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_CLK_FAIL_INTENABLE.wrd", tmp_mpif->SYS_CLK_FAIL_INTENABLE.wrd, tmp_mpif->SYS_CLK_FAIL_INTENABLE.wrd == dft_mpif->SYS_CLK_FAIL_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->SYS_CLK_FAIL_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_CLK_FAIL_INTENABLE.bf.faile", tmp_mpif->SYS_CLK_FAIL_INTENABLE.bf.faile, tmp_mpif->SYS_CLK_FAIL_INTENABLE.bf.faile == dft_mpif->SYS_CLK_FAIL_INTENABLE.bf.faile ? 0x20 : 0x2A, dft_mpif->SYS_CLK_FAIL_INTENABLE.bf.faile);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_CLK_FAIL_STATUS.wrd", tmp_mpif->SYS_CLK_FAIL_STATUS.wrd, tmp_mpif->SYS_CLK_FAIL_STATUS.wrd == dft_mpif->SYS_CLK_FAIL_STATUS.wrd ? 0x20 : 0x2A, dft_mpif->SYS_CLK_FAIL_STATUS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_CLK_FAIL_STATUS.bf.failiO", tmp_mpif->SYS_CLK_FAIL_STATUS.bf.failiO, tmp_mpif->SYS_CLK_FAIL_STATUS.bf.failiO == dft_mpif->SYS_CLK_FAIL_STATUS.bf.failiO ? 0x20 : 0x2A, dft_mpif->SYS_CLK_FAIL_STATUS.bf.failiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_CLK_FAIL_ISAS.wrd", tmp_mpif->SYS_CLK_FAIL_ISAS.wrd, tmp_mpif->SYS_CLK_FAIL_ISAS.wrd == dft_mpif->SYS_CLK_FAIL_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->SYS_CLK_FAIL_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SYS_CLK_FAIL_ISAS.bf.failiZ", tmp_mpif->SYS_CLK_FAIL_ISAS.bf.failiZ, tmp_mpif->SYS_CLK_FAIL_ISAS.bf.failiZ == dft_mpif->SYS_CLK_FAIL_ISAS.bf.failiZ ? 0x20 : 0x2A, dft_mpif->SYS_CLK_FAIL_ISAS.bf.failiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXCLK_REFOUT.wrd", tmp_mpif->RXCLK_REFOUT.wrd, tmp_mpif->RXCLK_REFOUT.wrd == dft_mpif->RXCLK_REFOUT.wrd ? 0x20 : 0x2A, dft_mpif->RXCLK_REFOUT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXCLK_REFOUT.bf.div", tmp_mpif->RXCLK_REFOUT.bf.div, tmp_mpif->RXCLK_REFOUT.bf.div == dft_mpif->RXCLK_REFOUT.bf.div ? 0x20 : 0x2A, dft_mpif->RXCLK_REFOUT.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXCLK_REFOUT.bf.select", tmp_mpif->RXCLK_REFOUT.bf.select, tmp_mpif->RXCLK_REFOUT.bf.select == dft_mpif->RXCLK_REFOUT.bf.select ? 0x20 : 0x2A, dft_mpif->RXCLK_REFOUT.bf.select);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PRBS_SYNC.wrd", tmp_mpif->PRBS_SYNC.wrd, tmp_mpif->PRBS_SYNC.wrd == dft_mpif->PRBS_SYNC.wrd ? 0x20 : 0x2A, dft_mpif->PRBS_SYNC.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PRBS_SYNC.bf.txb", tmp_mpif->PRBS_SYNC.bf.txb, tmp_mpif->PRBS_SYNC.bf.txb == dft_mpif->PRBS_SYNC.bf.txb ? 0x20 : 0x2A, dft_mpif->PRBS_SYNC.bf.txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PRBS_SYNC.bf.rxb", tmp_mpif->PRBS_SYNC.bf.rxb, tmp_mpif->PRBS_SYNC.bf.rxb == dft_mpif->PRBS_SYNC.bf.rxb ? 0x20 : 0x2A, dft_mpif->PRBS_SYNC.bf.rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PRBS_SYNC.bf.txa", tmp_mpif->PRBS_SYNC.bf.txa, tmp_mpif->PRBS_SYNC.bf.txa == dft_mpif->PRBS_SYNC.bf.txa ? 0x20 : 0x2A, dft_mpif->PRBS_SYNC.bf.txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PRBS_SYNC.bf.rxa", tmp_mpif->PRBS_SYNC.bf.rxa, tmp_mpif->PRBS_SYNC.bf.rxa == dft_mpif->PRBS_SYNC.bf.rxa ? 0x20 : 0x2A, dft_mpif->PRBS_SYNC.bf.rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SCRATCH_PAD1.wrd", tmp_mpif->SCRATCH_PAD1.wrd, tmp_mpif->SCRATCH_PAD1.wrd == dft_mpif->SCRATCH_PAD1.wrd ? 0x20 : 0x2A, dft_mpif->SCRATCH_PAD1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SCRATCH_PAD1.bf.value", tmp_mpif->SCRATCH_PAD1.bf.value, tmp_mpif->SCRATCH_PAD1.bf.value == dft_mpif->SCRATCH_PAD1.bf.value ? 0x20 : 0x2A, dft_mpif->SCRATCH_PAD1.bf.value);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SCRATCH_PAD2.wrd", tmp_mpif->SCRATCH_PAD2.wrd, tmp_mpif->SCRATCH_PAD2.wrd == dft_mpif->SCRATCH_PAD2.wrd ? 0x20 : 0x2A, dft_mpif->SCRATCH_PAD2.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_SCRATCH_PAD2.bf.value", tmp_mpif->SCRATCH_PAD2.bf.value, tmp_mpif->SCRATCH_PAD2.bf.value == dft_mpif->SCRATCH_PAD2.bf.value ? 0x20 : 0x2A, dft_mpif->SCRATCH_PAD2.bf.value);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_DIRECTION.wrd", tmp_mpif->GPIO_DIRECTION.wrd, tmp_mpif->GPIO_DIRECTION.wrd == dft_mpif->GPIO_DIRECTION.wrd ? 0x20 : 0x2A, dft_mpif->GPIO_DIRECTION.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_DIRECTION.bf.dir", tmp_mpif->GPIO_DIRECTION.bf.dir, tmp_mpif->GPIO_DIRECTION.bf.dir == dft_mpif->GPIO_DIRECTION.bf.dir ? 0x20 : 0x2A, dft_mpif->GPIO_DIRECTION.bf.dir);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_CCFP.wrd", tmp_mpif->GPIO_CCFP.wrd, tmp_mpif->GPIO_CCFP.wrd == dft_mpif->GPIO_CCFP.wrd ? 0x20 : 0x2A, dft_mpif->GPIO_CCFP.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_CCFP.bf.en", tmp_mpif->GPIO_CCFP.bf.en, tmp_mpif->GPIO_CCFP.bf.en == dft_mpif->GPIO_CCFP.bf.en ? 0x20 : 0x2A, dft_mpif->GPIO_CCFP.bf.en);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_OUTPUT.wrd", tmp_mpif->GPIO_OUTPUT.wrd, tmp_mpif->GPIO_OUTPUT.wrd == dft_mpif->GPIO_OUTPUT.wrd ? 0x20 : 0x2A, dft_mpif->GPIO_OUTPUT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_OUTPUT.bf.o", tmp_mpif->GPIO_OUTPUT.bf.o, tmp_mpif->GPIO_OUTPUT.bf.o == dft_mpif->GPIO_OUTPUT.bf.o ? 0x20 : 0x2A, dft_mpif->GPIO_OUTPUT.bf.o);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_SAMPLE.wrd", tmp_mpif->GPIO_SAMPLE.wrd, tmp_mpif->GPIO_SAMPLE.wrd == dft_mpif->GPIO_SAMPLE.wrd ? 0x20 : 0x2A, dft_mpif->GPIO_SAMPLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GPIO_SAMPLE.bf.i", tmp_mpif->GPIO_SAMPLE.bf.i, tmp_mpif->GPIO_SAMPLE.bf.i == dft_mpif->GPIO_SAMPLE.bf.i ? 0x20 : 0x2A, dft_mpif->GPIO_SAMPLE.bf.i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_PD.wrd", tmp_mpif->LVDS_PD.wrd, tmp_mpif->LVDS_PD.wrd == dft_mpif->LVDS_PD.wrd ? 0x20 : 0x2A, dft_mpif->LVDS_PD.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_PD.bf.rxref", tmp_mpif->LVDS_PD.bf.rxref, tmp_mpif->LVDS_PD.bf.rxref == dft_mpif->LVDS_PD.bf.rxref ? 0x20 : 0x2A, dft_mpif->LVDS_PD.bf.rxref);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_PD.bf.sysref", tmp_mpif->LVDS_PD.bf.sysref, tmp_mpif->LVDS_PD.bf.sysref == dft_mpif->LVDS_PD.bf.sysref ? 0x20 : 0x2A, dft_mpif->LVDS_PD.bf.sysref);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_PD.bf.ohppo_b", tmp_mpif->LVDS_PD.bf.ohppo_b, tmp_mpif->LVDS_PD.bf.ohppo_b == dft_mpif->LVDS_PD.bf.ohppo_b ? 0x20 : 0x2A, dft_mpif->LVDS_PD.bf.ohppo_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_PD.bf.ohppi_b", tmp_mpif->LVDS_PD.bf.ohppi_b, tmp_mpif->LVDS_PD.bf.ohppi_b == dft_mpif->LVDS_PD.bf.ohppi_b ? 0x20 : 0x2A, dft_mpif->LVDS_PD.bf.ohppi_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_PD.bf.ohppo_a", tmp_mpif->LVDS_PD.bf.ohppo_a, tmp_mpif->LVDS_PD.bf.ohppo_a == dft_mpif->LVDS_PD.bf.ohppo_a ? 0x20 : 0x2A, dft_mpif->LVDS_PD.bf.ohppo_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_PD.bf.ohppi_a", tmp_mpif->LVDS_PD.bf.ohppi_a, tmp_mpif->LVDS_PD.bf.ohppi_a == dft_mpif->LVDS_PD.bf.ohppi_a ? 0x20 : 0x2A, dft_mpif->LVDS_PD.bf.ohppi_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_DIV_PD.wrd", tmp_mpif->LVDS_DIV_PD.wrd, tmp_mpif->LVDS_DIV_PD.wrd == dft_mpif->LVDS_DIV_PD.wrd ? 0x20 : 0x2A, dft_mpif->LVDS_DIV_PD.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_DIV_PD.bf.syncdsync_txb", tmp_mpif->LVDS_DIV_PD.bf.syncdsync_txb, tmp_mpif->LVDS_DIV_PD.bf.syncdsync_txb == dft_mpif->LVDS_DIV_PD.bf.syncdsync_txb ? 0x20 : 0x2A, dft_mpif->LVDS_DIV_PD.bf.syncdsync_txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_DIV_PD.bf.syncdsync_rxb", tmp_mpif->LVDS_DIV_PD.bf.syncdsync_rxb, tmp_mpif->LVDS_DIV_PD.bf.syncdsync_rxb == dft_mpif->LVDS_DIV_PD.bf.syncdsync_rxb ? 0x20 : 0x2A, dft_mpif->LVDS_DIV_PD.bf.syncdsync_rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_DIV_PD.bf.syncdsync_txa", tmp_mpif->LVDS_DIV_PD.bf.syncdsync_txa, tmp_mpif->LVDS_DIV_PD.bf.syncdsync_txa == dft_mpif->LVDS_DIV_PD.bf.syncdsync_txa ? 0x20 : 0x2A, dft_mpif->LVDS_DIV_PD.bf.syncdsync_txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_LVDS_DIV_PD.bf.syncdsync_rxa", tmp_mpif->LVDS_DIV_PD.bf.syncdsync_rxa, tmp_mpif->LVDS_DIV_PD.bf.syncdsync_rxa == dft_mpif->LVDS_DIV_PD.bf.syncdsync_rxa ? 0x20 : 0x2A, dft_mpif->LVDS_DIV_PD.bf.syncdsync_rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS5.wrd", tmp_mpif->STAR_BIST_STATUS5.wrd, tmp_mpif->STAR_BIST_STATUS5.wrd == dft_mpif->STAR_BIST_STATUS5.wrd ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS5.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS5.bf.fail_sms5", tmp_mpif->STAR_BIST_STATUS5.bf.fail_sms5, tmp_mpif->STAR_BIST_STATUS5.bf.fail_sms5 == dft_mpif->STAR_BIST_STATUS5.bf.fail_sms5 ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS5.bf.fail_sms5);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS4.wrd", tmp_mpif->STAR_BIST_STATUS4.wrd, tmp_mpif->STAR_BIST_STATUS4.wrd == dft_mpif->STAR_BIST_STATUS4.wrd ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS4.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS4.bf.fail_sms4", tmp_mpif->STAR_BIST_STATUS4.bf.fail_sms4, tmp_mpif->STAR_BIST_STATUS4.bf.fail_sms4 == dft_mpif->STAR_BIST_STATUS4.bf.fail_sms4 ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS4.bf.fail_sms4);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS3.wrd", tmp_mpif->STAR_BIST_STATUS3.wrd, tmp_mpif->STAR_BIST_STATUS3.wrd == dft_mpif->STAR_BIST_STATUS3.wrd ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS3.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS3.bf.fail_sms3", tmp_mpif->STAR_BIST_STATUS3.bf.fail_sms3, tmp_mpif->STAR_BIST_STATUS3.bf.fail_sms3 == dft_mpif->STAR_BIST_STATUS3.bf.fail_sms3 ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS3.bf.fail_sms3);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS2.wrd", tmp_mpif->STAR_BIST_STATUS2.wrd, tmp_mpif->STAR_BIST_STATUS2.wrd == dft_mpif->STAR_BIST_STATUS2.wrd ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS2.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS2.bf.fail_sms2", tmp_mpif->STAR_BIST_STATUS2.bf.fail_sms2, tmp_mpif->STAR_BIST_STATUS2.bf.fail_sms2 == dft_mpif->STAR_BIST_STATUS2.bf.fail_sms2 ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS2.bf.fail_sms2);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS1.wrd", tmp_mpif->STAR_BIST_STATUS1.wrd, tmp_mpif->STAR_BIST_STATUS1.wrd == dft_mpif->STAR_BIST_STATUS1.wrd ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS1.bf.fail_sms1", tmp_mpif->STAR_BIST_STATUS1.bf.fail_sms1, tmp_mpif->STAR_BIST_STATUS1.bf.fail_sms1 == dft_mpif->STAR_BIST_STATUS1.bf.fail_sms1 ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS1.bf.fail_sms1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS0.wrd", tmp_mpif->STAR_BIST_STATUS0.wrd, tmp_mpif->STAR_BIST_STATUS0.wrd == dft_mpif->STAR_BIST_STATUS0.wrd ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_STAR_BIST_STATUS0.bf.fail_sms0", tmp_mpif->STAR_BIST_STATUS0.bf.fail_sms0, tmp_mpif->STAR_BIST_STATUS0.bf.fail_sms0 == dft_mpif->STAR_BIST_STATUS0.bf.fail_sms0 ? 0x20 : 0x2A, dft_mpif->STAR_BIST_STATUS0.bf.fail_sms0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TIMEOUT_ADDRESS0.wrd", tmp_mpif->TIMEOUT_ADDRESS0.wrd, tmp_mpif->TIMEOUT_ADDRESS0.wrd == dft_mpif->TIMEOUT_ADDRESS0.wrd ? 0x20 : 0x2A, dft_mpif->TIMEOUT_ADDRESS0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TIMEOUT_ADDRESS0.bf.address", tmp_mpif->TIMEOUT_ADDRESS0.bf.address, tmp_mpif->TIMEOUT_ADDRESS0.bf.address == dft_mpif->TIMEOUT_ADDRESS0.bf.address ? 0x20 : 0x2A, dft_mpif->TIMEOUT_ADDRESS0.bf.address);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TIMEOUT_ADDRESS1.wrd", tmp_mpif->TIMEOUT_ADDRESS1.wrd, tmp_mpif->TIMEOUT_ADDRESS1.wrd == dft_mpif->TIMEOUT_ADDRESS1.wrd ? 0x20 : 0x2A, dft_mpif->TIMEOUT_ADDRESS1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TIMEOUT_ADDRESS1.bf.address", tmp_mpif->TIMEOUT_ADDRESS1.bf.address, tmp_mpif->TIMEOUT_ADDRESS1.bf.address == dft_mpif->TIMEOUT_ADDRESS1.bf.address ? 0x20 : 0x2A, dft_mpif->TIMEOUT_ADDRESS1.bf.address);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TIMEOUT_TRANSACTION.wrd", tmp_mpif->TIMEOUT_TRANSACTION.wrd, tmp_mpif->TIMEOUT_TRANSACTION.wrd == dft_mpif->TIMEOUT_TRANSACTION.wrd ? 0x20 : 0x2A, dft_mpif->TIMEOUT_TRANSACTION.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TIMEOUT_TRANSACTION.bf.rwn", tmp_mpif->TIMEOUT_TRANSACTION.bf.rwn, tmp_mpif->TIMEOUT_TRANSACTION.bf.rwn == dft_mpif->TIMEOUT_TRANSACTION.bf.rwn ? 0x20 : 0x2A, dft_mpif->TIMEOUT_TRANSACTION.bf.rwn);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP40G.wrd", tmp_mpif->GLOBAL_RESET_PP40G.wrd, tmp_mpif->GLOBAL_RESET_PP40G.wrd == dft_mpif->GLOBAL_RESET_PP40G.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP40G.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP40G.bf.sys_b", tmp_mpif->GLOBAL_RESET_PP40G.bf.sys_b, tmp_mpif->GLOBAL_RESET_PP40G.bf.sys_b == dft_mpif->GLOBAL_RESET_PP40G.bf.sys_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP40G.bf.sys_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP40G.bf.sys_a", tmp_mpif->GLOBAL_RESET_PP40G.bf.sys_a, tmp_mpif->GLOBAL_RESET_PP40G.bf.sys_a == dft_mpif->GLOBAL_RESET_PP40G.bf.sys_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP40G.bf.sys_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP40G.bf.tx_b", tmp_mpif->GLOBAL_RESET_PP40G.bf.tx_b, tmp_mpif->GLOBAL_RESET_PP40G.bf.tx_b == dft_mpif->GLOBAL_RESET_PP40G.bf.tx_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP40G.bf.tx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP40G.bf.tx_a", tmp_mpif->GLOBAL_RESET_PP40G.bf.tx_a, tmp_mpif->GLOBAL_RESET_PP40G.bf.tx_a == dft_mpif->GLOBAL_RESET_PP40G.bf.tx_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP40G.bf.tx_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP40G.bf.rx_b", tmp_mpif->GLOBAL_RESET_PP40G.bf.rx_b, tmp_mpif->GLOBAL_RESET_PP40G.bf.rx_b == dft_mpif->GLOBAL_RESET_PP40G.bf.rx_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP40G.bf.rx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PP40G.bf.rx_a", tmp_mpif->GLOBAL_RESET_PP40G.bf.rx_a, tmp_mpif->GLOBAL_RESET_PP40G.bf.rx_a == dft_mpif->GLOBAL_RESET_PP40G.bf.rx_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PP40G.bf.rx_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_CFP.wrd", tmp_mpif->GLOBAL_RESET_SDS_CFP.wrd, tmp_mpif->GLOBAL_RESET_SDS_CFP.wrd == dft_mpif->GLOBAL_RESET_SDS_CFP.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_CFP.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_CFP.bf.mpif", tmp_mpif->GLOBAL_RESET_SDS_CFP.bf.mpif, tmp_mpif->GLOBAL_RESET_SDS_CFP.bf.mpif == dft_mpif->GLOBAL_RESET_SDS_CFP.bf.mpif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_CFP.bf.mpif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_CFP.bf.tx", tmp_mpif->GLOBAL_RESET_SDS_CFP.bf.tx, tmp_mpif->GLOBAL_RESET_SDS_CFP.bf.tx == dft_mpif->GLOBAL_RESET_SDS_CFP.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_CFP.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SDS_CFP.bf.rx", tmp_mpif->GLOBAL_RESET_SDS_CFP.bf.rx, tmp_mpif->GLOBAL_RESET_SDS_CFP.bf.rx == dft_mpif->GLOBAL_RESET_SDS_CFP.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SDS_CFP.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CUPLL.wrd", tmp_mpif->GLOBAL_RESET_CUPLL.wrd, tmp_mpif->GLOBAL_RESET_CUPLL.wrd == dft_mpif->GLOBAL_RESET_CUPLL.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CUPLL.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CUPLL.bf.holdover", tmp_mpif->GLOBAL_RESET_CUPLL.bf.holdover, tmp_mpif->GLOBAL_RESET_CUPLL.bf.holdover == dft_mpif->GLOBAL_RESET_CUPLL.bf.holdover ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CUPLL.bf.holdover);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CUPLL.bf.mpif", tmp_mpif->GLOBAL_RESET_CUPLL.bf.mpif, tmp_mpif->GLOBAL_RESET_CUPLL.bf.mpif == dft_mpif->GLOBAL_RESET_CUPLL.bf.mpif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CUPLL.bf.mpif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CUPLL.bf.tx", tmp_mpif->GLOBAL_RESET_CUPLL.bf.tx, tmp_mpif->GLOBAL_RESET_CUPLL.bf.tx == dft_mpif->GLOBAL_RESET_CUPLL.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CUPLL.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GPLL_SDS.wrd", tmp_mpif->GLOBAL_RESET_GPLL_SDS.wrd, tmp_mpif->GLOBAL_RESET_GPLL_SDS.wrd == dft_mpif->GLOBAL_RESET_GPLL_SDS.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GPLL_SDS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GPLL_SDS.bf.sds", tmp_mpif->GLOBAL_RESET_GPLL_SDS.bf.sds, tmp_mpif->GLOBAL_RESET_GPLL_SDS.bf.sds == dft_mpif->GLOBAL_RESET_GPLL_SDS.bf.sds ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GPLL_SDS.bf.sds);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GPLL_MPIF.wrd", tmp_mpif->GLOBAL_RESET_GPLL_MPIF.wrd, tmp_mpif->GLOBAL_RESET_GPLL_MPIF.wrd == dft_mpif->GLOBAL_RESET_GPLL_MPIF.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GPLL_MPIF.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_GPLL_MPIF.bf.mpif", tmp_mpif->GLOBAL_RESET_GPLL_MPIF.bf.mpif, tmp_mpif->GLOBAL_RESET_GPLL_MPIF.bf.mpif == dft_mpif->GLOBAL_RESET_GPLL_MPIF.bf.mpif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_GPLL_MPIF.bf.mpif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CLOCK_SWITCH.wrd", tmp_mpif->GLOBAL_RESET_CLOCK_SWITCH.wrd, tmp_mpif->GLOBAL_RESET_CLOCK_SWITCH.wrd == dft_mpif->GLOBAL_RESET_CLOCK_SWITCH.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CLOCK_SWITCH.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CLOCK_SWITCH.bf.tx", tmp_mpif->GLOBAL_RESET_CLOCK_SWITCH.bf.tx, tmp_mpif->GLOBAL_RESET_CLOCK_SWITCH.bf.tx == dft_mpif->GLOBAL_RESET_CLOCK_SWITCH.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CLOCK_SWITCH.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_CLOCK_SWITCH.bf.rx", tmp_mpif->GLOBAL_RESET_CLOCK_SWITCH.bf.rx, tmp_mpif->GLOBAL_RESET_CLOCK_SWITCH.bf.rx == dft_mpif->GLOBAL_RESET_CLOCK_SWITCH.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_CLOCK_SWITCH.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYNCDSYNC_DP.wrd", tmp_mpif->GLOBAL_RESET_SYNCDSYNC_DP.wrd, tmp_mpif->GLOBAL_RESET_SYNCDSYNC_DP.wrd == dft_mpif->GLOBAL_RESET_SYNCDSYNC_DP.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYNCDSYNC_DP.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYNCDSYNC_DP.bf.tx", tmp_mpif->GLOBAL_RESET_SYNCDSYNC_DP.bf.tx, tmp_mpif->GLOBAL_RESET_SYNCDSYNC_DP.bf.tx == dft_mpif->GLOBAL_RESET_SYNCDSYNC_DP.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYNCDSYNC_DP.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_SYNCDSYNC_DP.bf.rx", tmp_mpif->GLOBAL_RESET_SYNCDSYNC_DP.bf.rx, tmp_mpif->GLOBAL_RESET_SYNCDSYNC_DP.bf.rx == dft_mpif->GLOBAL_RESET_SYNCDSYNC_DP.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_SYNCDSYNC_DP.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_DM.wrd", tmp_mpif->GLOBAL_RESET_DM.wrd, tmp_mpif->GLOBAL_RESET_DM.wrd == dft_mpif->GLOBAL_RESET_DM.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_DM.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_DM.bf.mpif", tmp_mpif->GLOBAL_RESET_DM.bf.mpif, tmp_mpif->GLOBAL_RESET_DM.bf.mpif == dft_mpif->GLOBAL_RESET_DM.bf.mpif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_DM.bf.mpif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_DM.bf.logic", tmp_mpif->GLOBAL_RESET_DM.bf.logic, tmp_mpif->GLOBAL_RESET_DM.bf.logic == dft_mpif->GLOBAL_RESET_DM.bf.logic ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_DM.bf.logic);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PDCAL.wrd", tmp_mpif->GLOBAL_RESET_PDCAL.wrd, tmp_mpif->GLOBAL_RESET_PDCAL.wrd == dft_mpif->GLOBAL_RESET_PDCAL.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PDCAL.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_RESET_PDCAL.bf.mpif", tmp_mpif->GLOBAL_RESET_PDCAL.bf.mpif, tmp_mpif->GLOBAL_RESET_PDCAL.bf.mpif == dft_mpif->GLOBAL_RESET_PDCAL.bf.mpif ? 0x20 : 0x2A, dft_mpif->GLOBAL_RESET_PDCAL.bf.mpif);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP40G.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP40G.bf.byp_b", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.byp_b, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.byp_b == dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.byp_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.byp_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP40G.bf.byp_a", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.byp_a, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.byp_a == dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.byp_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.byp_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP40G.bf.sys_b", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.sys_b, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.sys_b == dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.sys_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.sys_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP40G.bf.sys_a", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.sys_a, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.sys_a == dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.sys_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.sys_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP40G.bf.rx_b", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.rx_b, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.rx_b == dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.rx_b ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.rx_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_PP40G.bf.rx_a", tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.rx_a, tmp_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.rx_a == dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.rx_a ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_PP40G.bf.rx_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_CFP.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_CFP.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_CFP.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_CFP.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_CFP.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_CFP.bf.tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_CFP.bf.tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_CFP.bf.tx == dft_mpif->GLOBAL_CLOCK_DISABLE_CFP.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_CFP.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_CFP.bf.rx", tmp_mpif->GLOBAL_CLOCK_DISABLE_CFP.bf.rx, tmp_mpif->GLOBAL_CLOCK_DISABLE_CFP.bf.rx == dft_mpif->GLOBAL_CLOCK_DISABLE_CFP.bf.rx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_CFP.bf.rx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_CUPLL.wrd", tmp_mpif->GLOBAL_CLOCK_DISABLE_CUPLL.wrd, tmp_mpif->GLOBAL_CLOCK_DISABLE_CUPLL.wrd == dft_mpif->GLOBAL_CLOCK_DISABLE_CUPLL.wrd ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_CUPLL.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_GLOBAL_CLOCK_DISABLE_CUPLL.bf.tx", tmp_mpif->GLOBAL_CLOCK_DISABLE_CUPLL.bf.tx, tmp_mpif->GLOBAL_CLOCK_DISABLE_CUPLL.bf.tx == dft_mpif->GLOBAL_CLOCK_DISABLE_CUPLL.bf.tx ? 0x20 : 0x2A, dft_mpif->GLOBAL_CLOCK_DISABLE_CUPLL.bf.tx);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_INTERNAL_RXDIV.wrd", tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.wrd, tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.wrd == dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_INTERNAL_RXDIV.bf.txb", tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.txb, tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.txb == dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.txb ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_INTERNAL_RXDIV.bf.rxb", tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.rxb, tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.rxb == dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.rxb ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_INTERNAL_RXDIV.bf.txa", tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.txa, tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.txa == dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.txa ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SELECT_INTERNAL_RXDIV.bf.rxa", tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.rxa, tmp_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.rxa == dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.rxa ? 0x20 : 0x2A, dft_mpif->CLOCK_SELECT_INTERNAL_RXDIV.bf.rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTERRUPT.wrd", tmp_mpif->MISC_INTERRUPT.wrd, tmp_mpif->MISC_INTERRUPT.wrd == dft_mpif->MISC_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->MISC_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTERRUPT.bf.dmi", tmp_mpif->MISC_INTERRUPT.bf.dmi, tmp_mpif->MISC_INTERRUPT.bf.dmi == dft_mpif->MISC_INTERRUPT.bf.dmi ? 0x20 : 0x2A, dft_mpif->MISC_INTERRUPT.bf.dmi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTERRUPT.bf.mr_proti", tmp_mpif->MISC_INTERRUPT.bf.mr_proti, tmp_mpif->MISC_INTERRUPT.bf.mr_proti == dft_mpif->MISC_INTERRUPT.bf.mr_proti ? 0x20 : 0x2A, dft_mpif->MISC_INTERRUPT.bf.mr_proti);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTERRUPT.bf.data_switchi", tmp_mpif->MISC_INTERRUPT.bf.data_switchi, tmp_mpif->MISC_INTERRUPT.bf.data_switchi == dft_mpif->MISC_INTERRUPT.bf.data_switchi ? 0x20 : 0x2A, dft_mpif->MISC_INTERRUPT.bf.data_switchi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTERRUPT.bf.clk_switch_revi", tmp_mpif->MISC_INTERRUPT.bf.clk_switch_revi, tmp_mpif->MISC_INTERRUPT.bf.clk_switch_revi == dft_mpif->MISC_INTERRUPT.bf.clk_switch_revi ? 0x20 : 0x2A, dft_mpif->MISC_INTERRUPT.bf.clk_switch_revi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTERRUPT.bf.clk_switchi", tmp_mpif->MISC_INTERRUPT.bf.clk_switchi, tmp_mpif->MISC_INTERRUPT.bf.clk_switchi == dft_mpif->MISC_INTERRUPT.bf.clk_switchi ? 0x20 : 0x2A, dft_mpif->MISC_INTERRUPT.bf.clk_switchi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTENABLE.wrd", tmp_mpif->MISC_INTENABLE.wrd, tmp_mpif->MISC_INTENABLE.wrd == dft_mpif->MISC_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->MISC_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTENABLE.bf.dme", tmp_mpif->MISC_INTENABLE.bf.dme, tmp_mpif->MISC_INTENABLE.bf.dme == dft_mpif->MISC_INTENABLE.bf.dme ? 0x20 : 0x2A, dft_mpif->MISC_INTENABLE.bf.dme);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTENABLE.bf.mr_prote", tmp_mpif->MISC_INTENABLE.bf.mr_prote, tmp_mpif->MISC_INTENABLE.bf.mr_prote == dft_mpif->MISC_INTENABLE.bf.mr_prote ? 0x20 : 0x2A, dft_mpif->MISC_INTENABLE.bf.mr_prote);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTENABLE.bf.data_switche", tmp_mpif->MISC_INTENABLE.bf.data_switche, tmp_mpif->MISC_INTENABLE.bf.data_switche == dft_mpif->MISC_INTENABLE.bf.data_switche ? 0x20 : 0x2A, dft_mpif->MISC_INTENABLE.bf.data_switche);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTENABLE.bf.clk_switch_reve", tmp_mpif->MISC_INTENABLE.bf.clk_switch_reve, tmp_mpif->MISC_INTENABLE.bf.clk_switch_reve == dft_mpif->MISC_INTENABLE.bf.clk_switch_reve ? 0x20 : 0x2A, dft_mpif->MISC_INTENABLE.bf.clk_switch_reve);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MISC_INTENABLE.bf.clk_switche", tmp_mpif->MISC_INTENABLE.bf.clk_switche, tmp_mpif->MISC_INTENABLE.bf.clk_switche == dft_mpif->MISC_INTENABLE.bf.clk_switche ? 0x20 : 0x2A, dft_mpif->MISC_INTENABLE.bf.clk_switche);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CFP_INTERRUPT.wrd", tmp_mpif->CFP_INTERRUPT.wrd, tmp_mpif->CFP_INTERRUPT.wrd == dft_mpif->CFP_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->CFP_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CFP_INTERRUPT.bf.CFP3i", tmp_mpif->CFP_INTERRUPT.bf.CFP3i, tmp_mpif->CFP_INTERRUPT.bf.CFP3i == dft_mpif->CFP_INTERRUPT.bf.CFP3i ? 0x20 : 0x2A, dft_mpif->CFP_INTERRUPT.bf.CFP3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CFP_INTERRUPT.bf.CFP2i", tmp_mpif->CFP_INTERRUPT.bf.CFP2i, tmp_mpif->CFP_INTERRUPT.bf.CFP2i == dft_mpif->CFP_INTERRUPT.bf.CFP2i ? 0x20 : 0x2A, dft_mpif->CFP_INTERRUPT.bf.CFP2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CFP_INTERRUPT.bf.CFP1i", tmp_mpif->CFP_INTERRUPT.bf.CFP1i, tmp_mpif->CFP_INTERRUPT.bf.CFP1i == dft_mpif->CFP_INTERRUPT.bf.CFP1i ? 0x20 : 0x2A, dft_mpif->CFP_INTERRUPT.bf.CFP1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CFP_INTERRUPT.bf.CFP0i", tmp_mpif->CFP_INTERRUPT.bf.CFP0i, tmp_mpif->CFP_INTERRUPT.bf.CFP0i == dft_mpif->CFP_INTERRUPT.bf.CFP0i ? 0x20 : 0x2A, dft_mpif->CFP_INTERRUPT.bf.CFP0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CFP_INTENABLE.wrd", tmp_mpif->CFP_INTENABLE.wrd, tmp_mpif->CFP_INTENABLE.wrd == dft_mpif->CFP_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->CFP_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CFP_INTENABLE.bf.CFP3e", tmp_mpif->CFP_INTENABLE.bf.CFP3e, tmp_mpif->CFP_INTENABLE.bf.CFP3e == dft_mpif->CFP_INTENABLE.bf.CFP3e ? 0x20 : 0x2A, dft_mpif->CFP_INTENABLE.bf.CFP3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CFP_INTENABLE.bf.CFP2e", tmp_mpif->CFP_INTENABLE.bf.CFP2e, tmp_mpif->CFP_INTENABLE.bf.CFP2e == dft_mpif->CFP_INTENABLE.bf.CFP2e ? 0x20 : 0x2A, dft_mpif->CFP_INTENABLE.bf.CFP2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CFP_INTENABLE.bf.CFP1e", tmp_mpif->CFP_INTENABLE.bf.CFP1e, tmp_mpif->CFP_INTENABLE.bf.CFP1e == dft_mpif->CFP_INTENABLE.bf.CFP1e ? 0x20 : 0x2A, dft_mpif->CFP_INTENABLE.bf.CFP1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CFP_INTENABLE.bf.CFP0e", tmp_mpif->CFP_INTENABLE.bf.CFP0e, tmp_mpif->CFP_INTENABLE.bf.CFP0e == dft_mpif->CFP_INTENABLE.bf.CFP0e ? 0x20 : 0x2A, dft_mpif->CFP_INTENABLE.bf.CFP0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_INTERRUPT.wrd", tmp_mpif->CUPLL_INTERRUPT.wrd, tmp_mpif->CUPLL_INTERRUPT.wrd == dft_mpif->CUPLL_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_INTERRUPT.bf.CUPLL3i", tmp_mpif->CUPLL_INTERRUPT.bf.CUPLL3i, tmp_mpif->CUPLL_INTERRUPT.bf.CUPLL3i == dft_mpif->CUPLL_INTERRUPT.bf.CUPLL3i ? 0x20 : 0x2A, dft_mpif->CUPLL_INTERRUPT.bf.CUPLL3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_INTERRUPT.bf.CUPLL2i", tmp_mpif->CUPLL_INTERRUPT.bf.CUPLL2i, tmp_mpif->CUPLL_INTERRUPT.bf.CUPLL2i == dft_mpif->CUPLL_INTERRUPT.bf.CUPLL2i ? 0x20 : 0x2A, dft_mpif->CUPLL_INTERRUPT.bf.CUPLL2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_INTERRUPT.bf.CUPLL1i", tmp_mpif->CUPLL_INTERRUPT.bf.CUPLL1i, tmp_mpif->CUPLL_INTERRUPT.bf.CUPLL1i == dft_mpif->CUPLL_INTERRUPT.bf.CUPLL1i ? 0x20 : 0x2A, dft_mpif->CUPLL_INTERRUPT.bf.CUPLL1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_INTERRUPT.bf.CUPLL0i", tmp_mpif->CUPLL_INTERRUPT.bf.CUPLL0i, tmp_mpif->CUPLL_INTERRUPT.bf.CUPLL0i == dft_mpif->CUPLL_INTERRUPT.bf.CUPLL0i ? 0x20 : 0x2A, dft_mpif->CUPLL_INTERRUPT.bf.CUPLL0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_INTENABLE.wrd", tmp_mpif->CUPLL_INTENABLE.wrd, tmp_mpif->CUPLL_INTENABLE.wrd == dft_mpif->CUPLL_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_INTENABLE.bf.CUPLL3e", tmp_mpif->CUPLL_INTENABLE.bf.CUPLL3e, tmp_mpif->CUPLL_INTENABLE.bf.CUPLL3e == dft_mpif->CUPLL_INTENABLE.bf.CUPLL3e ? 0x20 : 0x2A, dft_mpif->CUPLL_INTENABLE.bf.CUPLL3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_INTENABLE.bf.CUPLL2e", tmp_mpif->CUPLL_INTENABLE.bf.CUPLL2e, tmp_mpif->CUPLL_INTENABLE.bf.CUPLL2e == dft_mpif->CUPLL_INTENABLE.bf.CUPLL2e ? 0x20 : 0x2A, dft_mpif->CUPLL_INTENABLE.bf.CUPLL2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_INTENABLE.bf.CUPLL1e", tmp_mpif->CUPLL_INTENABLE.bf.CUPLL1e, tmp_mpif->CUPLL_INTENABLE.bf.CUPLL1e == dft_mpif->CUPLL_INTENABLE.bf.CUPLL1e ? 0x20 : 0x2A, dft_mpif->CUPLL_INTENABLE.bf.CUPLL1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_INTENABLE.bf.CUPLL0e", tmp_mpif->CUPLL_INTENABLE.bf.CUPLL0e, tmp_mpif->CUPLL_INTENABLE.bf.CUPLL0e == dft_mpif->CUPLL_INTENABLE.bf.CUPLL0e ? 0x20 : 0x2A, dft_mpif->CUPLL_INTENABLE.bf.CUPLL0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_INTERRUPT.wrd", tmp_mpif->CLOCK_SWITCH_INTERRUPT.wrd, tmp_mpif->CLOCK_SWITCH_INTERRUPT.wrd == dft_mpif->CLOCK_SWITCH_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_INTERRUPT.bf.TXBi", tmp_mpif->CLOCK_SWITCH_INTERRUPT.bf.TXBi, tmp_mpif->CLOCK_SWITCH_INTERRUPT.bf.TXBi == dft_mpif->CLOCK_SWITCH_INTERRUPT.bf.TXBi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_INTERRUPT.bf.TXBi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_INTERRUPT.bf.TXAi", tmp_mpif->CLOCK_SWITCH_INTERRUPT.bf.TXAi, tmp_mpif->CLOCK_SWITCH_INTERRUPT.bf.TXAi == dft_mpif->CLOCK_SWITCH_INTERRUPT.bf.TXAi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_INTERRUPT.bf.TXAi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_INTERRUPT.bf.RXBi", tmp_mpif->CLOCK_SWITCH_INTERRUPT.bf.RXBi, tmp_mpif->CLOCK_SWITCH_INTERRUPT.bf.RXBi == dft_mpif->CLOCK_SWITCH_INTERRUPT.bf.RXBi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_INTERRUPT.bf.RXBi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_INTERRUPT.bf.RXAi", tmp_mpif->CLOCK_SWITCH_INTERRUPT.bf.RXAi, tmp_mpif->CLOCK_SWITCH_INTERRUPT.bf.RXAi == dft_mpif->CLOCK_SWITCH_INTERRUPT.bf.RXAi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_INTERRUPT.bf.RXAi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_INTENABLE.wrd", tmp_mpif->CLOCK_SWITCH_INTENABLE.wrd, tmp_mpif->CLOCK_SWITCH_INTENABLE.wrd == dft_mpif->CLOCK_SWITCH_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_INTENABLE.bf.TXBe", tmp_mpif->CLOCK_SWITCH_INTENABLE.bf.TXBe, tmp_mpif->CLOCK_SWITCH_INTENABLE.bf.TXBe == dft_mpif->CLOCK_SWITCH_INTENABLE.bf.TXBe ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_INTENABLE.bf.TXBe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_INTENABLE.bf.TXAe", tmp_mpif->CLOCK_SWITCH_INTENABLE.bf.TXAe, tmp_mpif->CLOCK_SWITCH_INTENABLE.bf.TXAe == dft_mpif->CLOCK_SWITCH_INTENABLE.bf.TXAe ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_INTENABLE.bf.TXAe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_INTENABLE.bf.RXBe", tmp_mpif->CLOCK_SWITCH_INTENABLE.bf.RXBe, tmp_mpif->CLOCK_SWITCH_INTENABLE.bf.RXBe == dft_mpif->CLOCK_SWITCH_INTENABLE.bf.RXBe ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_INTENABLE.bf.RXBe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_INTENABLE.bf.RXAe", tmp_mpif->CLOCK_SWITCH_INTENABLE.bf.RXAe, tmp_mpif->CLOCK_SWITCH_INTENABLE.bf.RXAe == dft_mpif->CLOCK_SWITCH_INTENABLE.bf.RXAe ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_INTENABLE.bf.RXAe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_STATUS.wrd", tmp_mpif->CLOCK_SWITCH_STATUS.wrd, tmp_mpif->CLOCK_SWITCH_STATUS.wrd == dft_mpif->CLOCK_SWITCH_STATUS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_STATUS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_STATUS.bf.TXBiO", tmp_mpif->CLOCK_SWITCH_STATUS.bf.TXBiO, tmp_mpif->CLOCK_SWITCH_STATUS.bf.TXBiO == dft_mpif->CLOCK_SWITCH_STATUS.bf.TXBiO ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_STATUS.bf.TXBiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_STATUS.bf.TXAiO", tmp_mpif->CLOCK_SWITCH_STATUS.bf.TXAiO, tmp_mpif->CLOCK_SWITCH_STATUS.bf.TXAiO == dft_mpif->CLOCK_SWITCH_STATUS.bf.TXAiO ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_STATUS.bf.TXAiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_STATUS.bf.RXBiO", tmp_mpif->CLOCK_SWITCH_STATUS.bf.RXBiO, tmp_mpif->CLOCK_SWITCH_STATUS.bf.RXBiO == dft_mpif->CLOCK_SWITCH_STATUS.bf.RXBiO ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_STATUS.bf.RXBiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_STATUS.bf.RXAiO", tmp_mpif->CLOCK_SWITCH_STATUS.bf.RXAiO, tmp_mpif->CLOCK_SWITCH_STATUS.bf.RXAiO == dft_mpif->CLOCK_SWITCH_STATUS.bf.RXAiO ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_STATUS.bf.RXAiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_ISAS.wrd", tmp_mpif->CLOCK_SWITCH_ISAS.wrd, tmp_mpif->CLOCK_SWITCH_ISAS.wrd == dft_mpif->CLOCK_SWITCH_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_ISAS.bf.TXBiZ", tmp_mpif->CLOCK_SWITCH_ISAS.bf.TXBiZ, tmp_mpif->CLOCK_SWITCH_ISAS.bf.TXBiZ == dft_mpif->CLOCK_SWITCH_ISAS.bf.TXBiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_ISAS.bf.TXBiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_ISAS.bf.TXAiZ", tmp_mpif->CLOCK_SWITCH_ISAS.bf.TXAiZ, tmp_mpif->CLOCK_SWITCH_ISAS.bf.TXAiZ == dft_mpif->CLOCK_SWITCH_ISAS.bf.TXAiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_ISAS.bf.TXAiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_ISAS.bf.RXBiZ", tmp_mpif->CLOCK_SWITCH_ISAS.bf.RXBiZ, tmp_mpif->CLOCK_SWITCH_ISAS.bf.RXBiZ == dft_mpif->CLOCK_SWITCH_ISAS.bf.RXBiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_ISAS.bf.RXBiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_ISAS.bf.RXAiZ", tmp_mpif->CLOCK_SWITCH_ISAS.bf.RXAiZ, tmp_mpif->CLOCK_SWITCH_ISAS.bf.RXAiZ == dft_mpif->CLOCK_SWITCH_ISAS.bf.RXAiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_ISAS.bf.RXAiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_INTERRUPT.wrd", tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.wrd, tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.wrd == dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_INTERRUPT.bf.TXBi", tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.TXBi, tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.TXBi == dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.TXBi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.TXBi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_INTERRUPT.bf.TXAi", tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.TXAi, tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.TXAi == dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.TXAi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.TXAi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_INTERRUPT.bf.RXBi", tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.RXBi, tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.RXBi == dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.RXBi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.RXBi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_INTERRUPT.bf.RXAi", tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.RXAi, tmp_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.RXAi == dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.RXAi ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_INTERRUPT.bf.RXAi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_INTENABLE.wrd", tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.wrd, tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.wrd == dft_mpif->CLOCK_SWITCH_REV_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_INTENABLE.bf.TXBe", tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.TXBe, tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.TXBe == dft_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.TXBe ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.TXBe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_INTENABLE.bf.TXAe", tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.TXAe, tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.TXAe == dft_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.TXAe ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.TXAe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_INTENABLE.bf.RXBe", tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.RXBe, tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.RXBe == dft_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.RXBe ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.RXBe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_INTENABLE.bf.RXAe", tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.RXAe, tmp_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.RXAe == dft_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.RXAe ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_INTENABLE.bf.RXAe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_STATUS.wrd", tmp_mpif->CLOCK_SWITCH_REV_STATUS.wrd, tmp_mpif->CLOCK_SWITCH_REV_STATUS.wrd == dft_mpif->CLOCK_SWITCH_REV_STATUS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_STATUS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_STATUS.bf.TXBiO", tmp_mpif->CLOCK_SWITCH_REV_STATUS.bf.TXBiO, tmp_mpif->CLOCK_SWITCH_REV_STATUS.bf.TXBiO == dft_mpif->CLOCK_SWITCH_REV_STATUS.bf.TXBiO ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_STATUS.bf.TXBiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_STATUS.bf.TXAiO", tmp_mpif->CLOCK_SWITCH_REV_STATUS.bf.TXAiO, tmp_mpif->CLOCK_SWITCH_REV_STATUS.bf.TXAiO == dft_mpif->CLOCK_SWITCH_REV_STATUS.bf.TXAiO ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_STATUS.bf.TXAiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_STATUS.bf.RXBiO", tmp_mpif->CLOCK_SWITCH_REV_STATUS.bf.RXBiO, tmp_mpif->CLOCK_SWITCH_REV_STATUS.bf.RXBiO == dft_mpif->CLOCK_SWITCH_REV_STATUS.bf.RXBiO ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_STATUS.bf.RXBiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_STATUS.bf.RXAiO", tmp_mpif->CLOCK_SWITCH_REV_STATUS.bf.RXAiO, tmp_mpif->CLOCK_SWITCH_REV_STATUS.bf.RXAiO == dft_mpif->CLOCK_SWITCH_REV_STATUS.bf.RXAiO ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_STATUS.bf.RXAiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_ISAS.wrd", tmp_mpif->CLOCK_SWITCH_REV_ISAS.wrd, tmp_mpif->CLOCK_SWITCH_REV_ISAS.wrd == dft_mpif->CLOCK_SWITCH_REV_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_ISAS.bf.TXBiZ", tmp_mpif->CLOCK_SWITCH_REV_ISAS.bf.TXBiZ, tmp_mpif->CLOCK_SWITCH_REV_ISAS.bf.TXBiZ == dft_mpif->CLOCK_SWITCH_REV_ISAS.bf.TXBiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_ISAS.bf.TXBiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_ISAS.bf.TXAiZ", tmp_mpif->CLOCK_SWITCH_REV_ISAS.bf.TXAiZ, tmp_mpif->CLOCK_SWITCH_REV_ISAS.bf.TXAiZ == dft_mpif->CLOCK_SWITCH_REV_ISAS.bf.TXAiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_ISAS.bf.TXAiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_ISAS.bf.RXBiZ", tmp_mpif->CLOCK_SWITCH_REV_ISAS.bf.RXBiZ, tmp_mpif->CLOCK_SWITCH_REV_ISAS.bf.RXBiZ == dft_mpif->CLOCK_SWITCH_REV_ISAS.bf.RXBiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_ISAS.bf.RXBiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_REV_ISAS.bf.RXAiZ", tmp_mpif->CLOCK_SWITCH_REV_ISAS.bf.RXAiZ, tmp_mpif->CLOCK_SWITCH_REV_ISAS.bf.RXAiZ == dft_mpif->CLOCK_SWITCH_REV_ISAS.bf.RXAiZ ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_REV_ISAS.bf.RXAiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_INTERRUPT.wrd", tmp_mpif->DATA_SWITCH_INTERRUPT.wrd, tmp_mpif->DATA_SWITCH_INTERRUPT.wrd == dft_mpif->DATA_SWITCH_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_INTERRUPT.bf.TXBi", tmp_mpif->DATA_SWITCH_INTERRUPT.bf.TXBi, tmp_mpif->DATA_SWITCH_INTERRUPT.bf.TXBi == dft_mpif->DATA_SWITCH_INTERRUPT.bf.TXBi ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_INTERRUPT.bf.TXBi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_INTERRUPT.bf.TXAi", tmp_mpif->DATA_SWITCH_INTERRUPT.bf.TXAi, tmp_mpif->DATA_SWITCH_INTERRUPT.bf.TXAi == dft_mpif->DATA_SWITCH_INTERRUPT.bf.TXAi ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_INTERRUPT.bf.TXAi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_INTENABLE.wrd", tmp_mpif->DATA_SWITCH_INTENABLE.wrd, tmp_mpif->DATA_SWITCH_INTENABLE.wrd == dft_mpif->DATA_SWITCH_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_INTENABLE.bf.TXBe", tmp_mpif->DATA_SWITCH_INTENABLE.bf.TXBe, tmp_mpif->DATA_SWITCH_INTENABLE.bf.TXBe == dft_mpif->DATA_SWITCH_INTENABLE.bf.TXBe ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_INTENABLE.bf.TXBe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_INTENABLE.bf.TXAe", tmp_mpif->DATA_SWITCH_INTENABLE.bf.TXAe, tmp_mpif->DATA_SWITCH_INTENABLE.bf.TXAe == dft_mpif->DATA_SWITCH_INTENABLE.bf.TXAe ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_INTENABLE.bf.TXAe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_STATUS.wrd", tmp_mpif->DATA_SWITCH_STATUS.wrd, tmp_mpif->DATA_SWITCH_STATUS.wrd == dft_mpif->DATA_SWITCH_STATUS.wrd ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_STATUS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_STATUS.bf.TXBiO", tmp_mpif->DATA_SWITCH_STATUS.bf.TXBiO, tmp_mpif->DATA_SWITCH_STATUS.bf.TXBiO == dft_mpif->DATA_SWITCH_STATUS.bf.TXBiO ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_STATUS.bf.TXBiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_STATUS.bf.TXAiO", tmp_mpif->DATA_SWITCH_STATUS.bf.TXAiO, tmp_mpif->DATA_SWITCH_STATUS.bf.TXAiO == dft_mpif->DATA_SWITCH_STATUS.bf.TXAiO ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_STATUS.bf.TXAiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_ISAS.wrd", tmp_mpif->DATA_SWITCH_ISAS.wrd, tmp_mpif->DATA_SWITCH_ISAS.wrd == dft_mpif->DATA_SWITCH_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_ISAS.bf.TXBiZ", tmp_mpif->DATA_SWITCH_ISAS.bf.TXBiZ, tmp_mpif->DATA_SWITCH_ISAS.bf.TXBiZ == dft_mpif->DATA_SWITCH_ISAS.bf.TXBiZ ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_ISAS.bf.TXBiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_ISAS.bf.TXAiZ", tmp_mpif->DATA_SWITCH_ISAS.bf.TXAiZ, tmp_mpif->DATA_SWITCH_ISAS.bf.TXAiZ == dft_mpif->DATA_SWITCH_ISAS.bf.TXAiZ ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_ISAS.bf.TXAiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_INTERRUPT.wrd", tmp_mpif->MR_PROT_INTERRUPT.wrd, tmp_mpif->MR_PROT_INTERRUPT.wrd == dft_mpif->MR_PROT_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->MR_PROT_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_INTERRUPT.bf.ohppi", tmp_mpif->MR_PROT_INTERRUPT.bf.ohppi, tmp_mpif->MR_PROT_INTERRUPT.bf.ohppi == dft_mpif->MR_PROT_INTERRUPT.bf.ohppi ? 0x20 : 0x2A, dft_mpif->MR_PROT_INTERRUPT.bf.ohppi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_INTERRUPT.bf.txclki", tmp_mpif->MR_PROT_INTERRUPT.bf.txclki, tmp_mpif->MR_PROT_INTERRUPT.bf.txclki == dft_mpif->MR_PROT_INTERRUPT.bf.txclki ? 0x20 : 0x2A, dft_mpif->MR_PROT_INTERRUPT.bf.txclki);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_INTERRUPT.bf.rxclki", tmp_mpif->MR_PROT_INTERRUPT.bf.rxclki, tmp_mpif->MR_PROT_INTERRUPT.bf.rxclki == dft_mpif->MR_PROT_INTERRUPT.bf.rxclki ? 0x20 : 0x2A, dft_mpif->MR_PROT_INTERRUPT.bf.rxclki);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_INTENABLE.wrd", tmp_mpif->MR_PROT_INTENABLE.wrd, tmp_mpif->MR_PROT_INTENABLE.wrd == dft_mpif->MR_PROT_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->MR_PROT_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_INTENABLE.bf.ohppe", tmp_mpif->MR_PROT_INTENABLE.bf.ohppe, tmp_mpif->MR_PROT_INTENABLE.bf.ohppe == dft_mpif->MR_PROT_INTENABLE.bf.ohppe ? 0x20 : 0x2A, dft_mpif->MR_PROT_INTENABLE.bf.ohppe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_INTENABLE.bf.txclke", tmp_mpif->MR_PROT_INTENABLE.bf.txclke, tmp_mpif->MR_PROT_INTENABLE.bf.txclke == dft_mpif->MR_PROT_INTENABLE.bf.txclke ? 0x20 : 0x2A, dft_mpif->MR_PROT_INTENABLE.bf.txclke);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_INTENABLE.bf.rxclke", tmp_mpif->MR_PROT_INTENABLE.bf.rxclke, tmp_mpif->MR_PROT_INTENABLE.bf.rxclke == dft_mpif->MR_PROT_INTENABLE.bf.rxclke ? 0x20 : 0x2A, dft_mpif->MR_PROT_INTENABLE.bf.rxclke);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_STATUS.wrd", tmp_mpif->MR_PROT_STATUS.wrd, tmp_mpif->MR_PROT_STATUS.wrd == dft_mpif->MR_PROT_STATUS.wrd ? 0x20 : 0x2A, dft_mpif->MR_PROT_STATUS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_STATUS.bf.ohppiO", tmp_mpif->MR_PROT_STATUS.bf.ohppiO, tmp_mpif->MR_PROT_STATUS.bf.ohppiO == dft_mpif->MR_PROT_STATUS.bf.ohppiO ? 0x20 : 0x2A, dft_mpif->MR_PROT_STATUS.bf.ohppiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_STATUS.bf.txclkiO", tmp_mpif->MR_PROT_STATUS.bf.txclkiO, tmp_mpif->MR_PROT_STATUS.bf.txclkiO == dft_mpif->MR_PROT_STATUS.bf.txclkiO ? 0x20 : 0x2A, dft_mpif->MR_PROT_STATUS.bf.txclkiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_STATUS.bf.rxclkiO", tmp_mpif->MR_PROT_STATUS.bf.rxclkiO, tmp_mpif->MR_PROT_STATUS.bf.rxclkiO == dft_mpif->MR_PROT_STATUS.bf.rxclkiO ? 0x20 : 0x2A, dft_mpif->MR_PROT_STATUS.bf.rxclkiO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_ISAS.wrd", tmp_mpif->MR_PROT_ISAS.wrd, tmp_mpif->MR_PROT_ISAS.wrd == dft_mpif->MR_PROT_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->MR_PROT_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_ISAS.bf.ohppiZ", tmp_mpif->MR_PROT_ISAS.bf.ohppiZ, tmp_mpif->MR_PROT_ISAS.bf.ohppiZ == dft_mpif->MR_PROT_ISAS.bf.ohppiZ ? 0x20 : 0x2A, dft_mpif->MR_PROT_ISAS.bf.ohppiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_ISAS.bf.txclkiZ", tmp_mpif->MR_PROT_ISAS.bf.txclkiZ, tmp_mpif->MR_PROT_ISAS.bf.txclkiZ == dft_mpif->MR_PROT_ISAS.bf.txclkiZ ? 0x20 : 0x2A, dft_mpif->MR_PROT_ISAS.bf.txclkiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_ISAS.bf.rxclkiZ", tmp_mpif->MR_PROT_ISAS.bf.rxclkiZ, tmp_mpif->MR_PROT_ISAS.bf.rxclkiZ == dft_mpif->MR_PROT_ISAS.bf.rxclkiZ ? 0x20 : 0x2A, dft_mpif->MR_PROT_ISAS.bf.rxclkiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_NONREVERT.wrd", tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.wrd, tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.wrd == dft_mpif->CLOCK_SWITCH_RX_NONREVERT.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_NONREVERT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_NONREVERT.bf.clr_b", tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.clr_b, tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.clr_b == dft_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.clr_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.clr_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_NONREVERT.bf.clr_a", tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.clr_a, tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.clr_a == dft_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.clr_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.clr_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_NONREVERT.bf.en_b", tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.en_b, tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.en_b == dft_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.en_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.en_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_RX_NONREVERT.bf.en_a", tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.en_a, tmp_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.en_a == dft_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.en_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_RX_NONREVERT.bf.en_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_NONREVERT.wrd", tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.wrd, tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.wrd == dft_mpif->CLOCK_SWITCH_TX_NONREVERT.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_NONREVERT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_NONREVERT.bf.clr_b", tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.clr_b, tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.clr_b == dft_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.clr_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.clr_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_NONREVERT.bf.clr_a", tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.clr_a, tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.clr_a == dft_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.clr_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.clr_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_NONREVERT.bf.en_b", tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.en_b, tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.en_b == dft_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.en_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.en_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_NONREVERT.bf.en_a", tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.en_a, tmp_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.en_a == dft_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.en_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_NONREVERT.bf.en_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_TX_NONREVERT.wrd", tmp_mpif->DATA_SWITCH_TX_NONREVERT.wrd, tmp_mpif->DATA_SWITCH_TX_NONREVERT.wrd == dft_mpif->DATA_SWITCH_TX_NONREVERT.wrd ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_TX_NONREVERT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_TX_NONREVERT.bf.clr_b", tmp_mpif->DATA_SWITCH_TX_NONREVERT.bf.clr_b, tmp_mpif->DATA_SWITCH_TX_NONREVERT.bf.clr_b == dft_mpif->DATA_SWITCH_TX_NONREVERT.bf.clr_b ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_TX_NONREVERT.bf.clr_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_TX_NONREVERT.bf.clr_a", tmp_mpif->DATA_SWITCH_TX_NONREVERT.bf.clr_a, tmp_mpif->DATA_SWITCH_TX_NONREVERT.bf.clr_a == dft_mpif->DATA_SWITCH_TX_NONREVERT.bf.clr_a ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_TX_NONREVERT.bf.clr_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_TX_NONREVERT.bf.en_b", tmp_mpif->DATA_SWITCH_TX_NONREVERT.bf.en_b, tmp_mpif->DATA_SWITCH_TX_NONREVERT.bf.en_b == dft_mpif->DATA_SWITCH_TX_NONREVERT.bf.en_b ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_TX_NONREVERT.bf.en_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_DATA_SWITCH_TX_NONREVERT.bf.en_a", tmp_mpif->DATA_SWITCH_TX_NONREVERT.bf.en_a, tmp_mpif->DATA_SWITCH_TX_NONREVERT.bf.en_a == dft_mpif->DATA_SWITCH_TX_NONREVERT.bf.en_a ? 0x20 : 0x2A, dft_mpif->DATA_SWITCH_TX_NONREVERT.bf.en_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_DW.wrd", tmp_mpif->CLOCK_SWITCH_TX_DW.wrd, tmp_mpif->CLOCK_SWITCH_TX_DW.wrd == dft_mpif->CLOCK_SWITCH_TX_DW.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_DW.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_DW.bf.Four0g_b", tmp_mpif->CLOCK_SWITCH_TX_DW.bf.Four0g_b, tmp_mpif->CLOCK_SWITCH_TX_DW.bf.Four0g_b == dft_mpif->CLOCK_SWITCH_TX_DW.bf.Four0g_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_DW.bf.Four0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_DW.bf.Four0g_a", tmp_mpif->CLOCK_SWITCH_TX_DW.bf.Four0g_a, tmp_mpif->CLOCK_SWITCH_TX_DW.bf.Four0g_a == dft_mpif->CLOCK_SWITCH_TX_DW.bf.Four0g_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_DW.bf.Four0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_DW.bf.One0g_b", tmp_mpif->CLOCK_SWITCH_TX_DW.bf.One0g_b, tmp_mpif->CLOCK_SWITCH_TX_DW.bf.One0g_b == dft_mpif->CLOCK_SWITCH_TX_DW.bf.One0g_b ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_DW.bf.One0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_DW.bf.One0g_a", tmp_mpif->CLOCK_SWITCH_TX_DW.bf.One0g_a, tmp_mpif->CLOCK_SWITCH_TX_DW.bf.One0g_a == dft_mpif->CLOCK_SWITCH_TX_DW.bf.One0g_a ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_DW.bf.One0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER0.wrd", tmp_mpif->CLOCK_SWITCH_TX_TIMER0.wrd, tmp_mpif->CLOCK_SWITCH_TX_TIMER0.wrd == dft_mpif->CLOCK_SWITCH_TX_TIMER0.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER0.bf.enable", tmp_mpif->CLOCK_SWITCH_TX_TIMER0.bf.enable, tmp_mpif->CLOCK_SWITCH_TX_TIMER0.bf.enable == dft_mpif->CLOCK_SWITCH_TX_TIMER0.bf.enable ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER0.bf.enable);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER0.bf.timeout", tmp_mpif->CLOCK_SWITCH_TX_TIMER0.bf.timeout, tmp_mpif->CLOCK_SWITCH_TX_TIMER0.bf.timeout == dft_mpif->CLOCK_SWITCH_TX_TIMER0.bf.timeout ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER0.bf.timeout);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER1.wrd", tmp_mpif->CLOCK_SWITCH_TX_TIMER1.wrd, tmp_mpif->CLOCK_SWITCH_TX_TIMER1.wrd == dft_mpif->CLOCK_SWITCH_TX_TIMER1.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER1.bf.enable", tmp_mpif->CLOCK_SWITCH_TX_TIMER1.bf.enable, tmp_mpif->CLOCK_SWITCH_TX_TIMER1.bf.enable == dft_mpif->CLOCK_SWITCH_TX_TIMER1.bf.enable ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER1.bf.enable);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER1.bf.timeout", tmp_mpif->CLOCK_SWITCH_TX_TIMER1.bf.timeout, tmp_mpif->CLOCK_SWITCH_TX_TIMER1.bf.timeout == dft_mpif->CLOCK_SWITCH_TX_TIMER1.bf.timeout ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER1.bf.timeout);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER2.wrd", tmp_mpif->CLOCK_SWITCH_TX_TIMER2.wrd, tmp_mpif->CLOCK_SWITCH_TX_TIMER2.wrd == dft_mpif->CLOCK_SWITCH_TX_TIMER2.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER2.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER2.bf.enable", tmp_mpif->CLOCK_SWITCH_TX_TIMER2.bf.enable, tmp_mpif->CLOCK_SWITCH_TX_TIMER2.bf.enable == dft_mpif->CLOCK_SWITCH_TX_TIMER2.bf.enable ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER2.bf.enable);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER2.bf.timeout", tmp_mpif->CLOCK_SWITCH_TX_TIMER2.bf.timeout, tmp_mpif->CLOCK_SWITCH_TX_TIMER2.bf.timeout == dft_mpif->CLOCK_SWITCH_TX_TIMER2.bf.timeout ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER2.bf.timeout);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER3.wrd", tmp_mpif->CLOCK_SWITCH_TX_TIMER3.wrd, tmp_mpif->CLOCK_SWITCH_TX_TIMER3.wrd == dft_mpif->CLOCK_SWITCH_TX_TIMER3.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER3.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER3.bf.enable", tmp_mpif->CLOCK_SWITCH_TX_TIMER3.bf.enable, tmp_mpif->CLOCK_SWITCH_TX_TIMER3.bf.enable == dft_mpif->CLOCK_SWITCH_TX_TIMER3.bf.enable ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER3.bf.enable);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER3.bf.timeout", tmp_mpif->CLOCK_SWITCH_TX_TIMER3.bf.timeout, tmp_mpif->CLOCK_SWITCH_TX_TIMER3.bf.timeout == dft_mpif->CLOCK_SWITCH_TX_TIMER3.bf.timeout ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER3.bf.timeout);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER4.wrd", tmp_mpif->CLOCK_SWITCH_TX_TIMER4.wrd, tmp_mpif->CLOCK_SWITCH_TX_TIMER4.wrd == dft_mpif->CLOCK_SWITCH_TX_TIMER4.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER4.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER4.bf.enable", tmp_mpif->CLOCK_SWITCH_TX_TIMER4.bf.enable, tmp_mpif->CLOCK_SWITCH_TX_TIMER4.bf.enable == dft_mpif->CLOCK_SWITCH_TX_TIMER4.bf.enable ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER4.bf.enable);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER4.bf.timeout", tmp_mpif->CLOCK_SWITCH_TX_TIMER4.bf.timeout, tmp_mpif->CLOCK_SWITCH_TX_TIMER4.bf.timeout == dft_mpif->CLOCK_SWITCH_TX_TIMER4.bf.timeout ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER4.bf.timeout);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER5.wrd", tmp_mpif->CLOCK_SWITCH_TX_TIMER5.wrd, tmp_mpif->CLOCK_SWITCH_TX_TIMER5.wrd == dft_mpif->CLOCK_SWITCH_TX_TIMER5.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER5.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER5.bf.enable", tmp_mpif->CLOCK_SWITCH_TX_TIMER5.bf.enable, tmp_mpif->CLOCK_SWITCH_TX_TIMER5.bf.enable == dft_mpif->CLOCK_SWITCH_TX_TIMER5.bf.enable ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER5.bf.enable);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER5.bf.timeout", tmp_mpif->CLOCK_SWITCH_TX_TIMER5.bf.timeout, tmp_mpif->CLOCK_SWITCH_TX_TIMER5.bf.timeout == dft_mpif->CLOCK_SWITCH_TX_TIMER5.bf.timeout ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER5.bf.timeout);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER6.wrd", tmp_mpif->CLOCK_SWITCH_TX_TIMER6.wrd, tmp_mpif->CLOCK_SWITCH_TX_TIMER6.wrd == dft_mpif->CLOCK_SWITCH_TX_TIMER6.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER6.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER6.bf.enable", tmp_mpif->CLOCK_SWITCH_TX_TIMER6.bf.enable, tmp_mpif->CLOCK_SWITCH_TX_TIMER6.bf.enable == dft_mpif->CLOCK_SWITCH_TX_TIMER6.bf.enable ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER6.bf.enable);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER6.bf.timeout", tmp_mpif->CLOCK_SWITCH_TX_TIMER6.bf.timeout, tmp_mpif->CLOCK_SWITCH_TX_TIMER6.bf.timeout == dft_mpif->CLOCK_SWITCH_TX_TIMER6.bf.timeout ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER6.bf.timeout);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER7.wrd", tmp_mpif->CLOCK_SWITCH_TX_TIMER7.wrd, tmp_mpif->CLOCK_SWITCH_TX_TIMER7.wrd == dft_mpif->CLOCK_SWITCH_TX_TIMER7.wrd ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER7.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER7.bf.enable", tmp_mpif->CLOCK_SWITCH_TX_TIMER7.bf.enable, tmp_mpif->CLOCK_SWITCH_TX_TIMER7.bf.enable == dft_mpif->CLOCK_SWITCH_TX_TIMER7.bf.enable ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER7.bf.enable);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CLOCK_SWITCH_TX_TIMER7.bf.timeout", tmp_mpif->CLOCK_SWITCH_TX_TIMER7.bf.timeout, tmp_mpif->CLOCK_SWITCH_TX_TIMER7.bf.timeout == dft_mpif->CLOCK_SWITCH_TX_TIMER7.bf.timeout ? 0x20 : 0x2A, dft_mpif->CLOCK_SWITCH_TX_TIMER7.bf.timeout);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_CFG.wrd", tmp_mpif->MR_PROT_CFG.wrd, tmp_mpif->MR_PROT_CFG.wrd == dft_mpif->MR_PROT_CFG.wrd ? 0x20 : 0x2A, dft_mpif->MR_PROT_CFG.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_CFG.bf.txclk_xlos", tmp_mpif->MR_PROT_CFG.bf.txclk_xlos, tmp_mpif->MR_PROT_CFG.bf.txclk_xlos == dft_mpif->MR_PROT_CFG.bf.txclk_xlos ? 0x20 : 0x2A, dft_mpif->MR_PROT_CFG.bf.txclk_xlos);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_CFG.bf.rxclk_xlos", tmp_mpif->MR_PROT_CFG.bf.rxclk_xlos, tmp_mpif->MR_PROT_CFG.bf.rxclk_xlos == dft_mpif->MR_PROT_CFG.bf.rxclk_xlos ? 0x20 : 0x2A, dft_mpif->MR_PROT_CFG.bf.rxclk_xlos);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_CFG.bf.txclk_pswtchen", tmp_mpif->MR_PROT_CFG.bf.txclk_pswtchen, tmp_mpif->MR_PROT_CFG.bf.txclk_pswtchen == dft_mpif->MR_PROT_CFG.bf.txclk_pswtchen ? 0x20 : 0x2A, dft_mpif->MR_PROT_CFG.bf.txclk_pswtchen);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_MR_PROT_CFG.bf.rxclk_pswtchen", tmp_mpif->MR_PROT_CFG.bf.rxclk_pswtchen, tmp_mpif->MR_PROT_CFG.bf.rxclk_pswtchen == dft_mpif->MR_PROT_CFG.bf.rxclk_pswtchen ? 0x20 : 0x2A, dft_mpif->MR_PROT_CFG.bf.rxclk_pswtchen);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_OXU_FRAME_OUT_10G.wrd", tmp_mpif->OXU_FRAME_OUT_10G.wrd, tmp_mpif->OXU_FRAME_OUT_10G.wrd == dft_mpif->OXU_FRAME_OUT_10G.wrd ? 0x20 : 0x2A, dft_mpif->OXU_FRAME_OUT_10G.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_OXU_FRAME_OUT_10G.bf.txb", tmp_mpif->OXU_FRAME_OUT_10G.bf.txb, tmp_mpif->OXU_FRAME_OUT_10G.bf.txb == dft_mpif->OXU_FRAME_OUT_10G.bf.txb ? 0x20 : 0x2A, dft_mpif->OXU_FRAME_OUT_10G.bf.txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_OXU_FRAME_OUT_10G.bf.rxb", tmp_mpif->OXU_FRAME_OUT_10G.bf.rxb, tmp_mpif->OXU_FRAME_OUT_10G.bf.rxb == dft_mpif->OXU_FRAME_OUT_10G.bf.rxb ? 0x20 : 0x2A, dft_mpif->OXU_FRAME_OUT_10G.bf.rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_OXU_FRAME_OUT_10G.bf.txa", tmp_mpif->OXU_FRAME_OUT_10G.bf.txa, tmp_mpif->OXU_FRAME_OUT_10G.bf.txa == dft_mpif->OXU_FRAME_OUT_10G.bf.txa ? 0x20 : 0x2A, dft_mpif->OXU_FRAME_OUT_10G.bf.txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_OXU_FRAME_OUT_10G.bf.rxa", tmp_mpif->OXU_FRAME_OUT_10G.bf.rxa, tmp_mpif->OXU_FRAME_OUT_10G.bf.rxa == dft_mpif->OXU_FRAME_OUT_10G.bf.rxa ? 0x20 : 0x2A, dft_mpif->OXU_FRAME_OUT_10G.bf.rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_OXU_FRAME_OUT_40G.wrd", tmp_mpif->OXU_FRAME_OUT_40G.wrd, tmp_mpif->OXU_FRAME_OUT_40G.wrd == dft_mpif->OXU_FRAME_OUT_40G.wrd ? 0x20 : 0x2A, dft_mpif->OXU_FRAME_OUT_40G.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_OXU_FRAME_OUT_40G.bf.txb", tmp_mpif->OXU_FRAME_OUT_40G.bf.txb, tmp_mpif->OXU_FRAME_OUT_40G.bf.txb == dft_mpif->OXU_FRAME_OUT_40G.bf.txb ? 0x20 : 0x2A, dft_mpif->OXU_FRAME_OUT_40G.bf.txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_OXU_FRAME_OUT_40G.bf.rxb", tmp_mpif->OXU_FRAME_OUT_40G.bf.rxb, tmp_mpif->OXU_FRAME_OUT_40G.bf.rxb == dft_mpif->OXU_FRAME_OUT_40G.bf.rxb ? 0x20 : 0x2A, dft_mpif->OXU_FRAME_OUT_40G.bf.rxb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_OXU_FRAME_OUT_40G.bf.txa", tmp_mpif->OXU_FRAME_OUT_40G.bf.txa, tmp_mpif->OXU_FRAME_OUT_40G.bf.txa == dft_mpif->OXU_FRAME_OUT_40G.bf.txa ? 0x20 : 0x2A, dft_mpif->OXU_FRAME_OUT_40G.bf.txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_OXU_FRAME_OUT_40G.bf.rxa", tmp_mpif->OXU_FRAME_OUT_40G.bf.rxa, tmp_mpif->OXU_FRAME_OUT_40G.bf.rxa == dft_mpif->OXU_FRAME_OUT_40G.bf.rxa ? 0x20 : 0x2A, dft_mpif->OXU_FRAME_OUT_40G.bf.rxa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG0.wrd", tmp_mpif->RXDIV_CFG0.wrd, tmp_mpif->RXDIV_CFG0.wrd == dft_mpif->RXDIV_CFG0.wrd ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG0.bf.pilot", tmp_mpif->RXDIV_CFG0.bf.pilot, tmp_mpif->RXDIV_CFG0.bf.pilot == dft_mpif->RXDIV_CFG0.bf.pilot ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG0.bf.pilot);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG0.bf.rx_sel", tmp_mpif->RXDIV_CFG0.bf.rx_sel, tmp_mpif->RXDIV_CFG0.bf.rx_sel == dft_mpif->RXDIV_CFG0.bf.rx_sel ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG0.bf.rx_sel);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG0.bf.mode", tmp_mpif->RXDIV_CFG0.bf.mode, tmp_mpif->RXDIV_CFG0.bf.mode == dft_mpif->RXDIV_CFG0.bf.mode ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG0.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG0.wrd", tmp_mpif->TXDIV_CFG0.wrd, tmp_mpif->TXDIV_CFG0.wrd == dft_mpif->TXDIV_CFG0.wrd ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG0.bf.mode1", tmp_mpif->TXDIV_CFG0.bf.mode1, tmp_mpif->TXDIV_CFG0.bf.mode1 == dft_mpif->TXDIV_CFG0.bf.mode1 ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG0.bf.mode1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG0.bf.mode", tmp_mpif->TXDIV_CFG0.bf.mode, tmp_mpif->TXDIV_CFG0.bf.mode == dft_mpif->TXDIV_CFG0.bf.mode ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG0.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV0.wrd", tmp_mpif->RXLINE_DIV0.wrd, tmp_mpif->RXLINE_DIV0.wrd == dft_mpif->RXLINE_DIV0.wrd ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV0.bf.div", tmp_mpif->RXLINE_DIV0.bf.div, tmp_mpif->RXLINE_DIV0.bf.div == dft_mpif->RXLINE_DIV0.bf.div ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV0.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV0.wrd", tmp_mpif->TXLINE_DIV0.wrd, tmp_mpif->TXLINE_DIV0.wrd == dft_mpif->TXLINE_DIV0.wrd ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV0.bf.div", tmp_mpif->TXLINE_DIV0.bf.div, tmp_mpif->TXLINE_DIV0.bf.div == dft_mpif->TXLINE_DIV0.bf.div ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV0.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV0.wrd", tmp_mpif->PILOT_DIV0.wrd, tmp_mpif->PILOT_DIV0.wrd == dft_mpif->PILOT_DIV0.wrd ? 0x20 : 0x2A, dft_mpif->PILOT_DIV0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV0.bf.div", tmp_mpif->PILOT_DIV0.bf.div, tmp_mpif->PILOT_DIV0.bf.div == dft_mpif->PILOT_DIV0.bf.div ? 0x20 : 0x2A, dft_mpif->PILOT_DIV0.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG1.wrd", tmp_mpif->RXDIV_CFG1.wrd, tmp_mpif->RXDIV_CFG1.wrd == dft_mpif->RXDIV_CFG1.wrd ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG1.bf.pilot", tmp_mpif->RXDIV_CFG1.bf.pilot, tmp_mpif->RXDIV_CFG1.bf.pilot == dft_mpif->RXDIV_CFG1.bf.pilot ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG1.bf.pilot);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG1.bf.rx_sel", tmp_mpif->RXDIV_CFG1.bf.rx_sel, tmp_mpif->RXDIV_CFG1.bf.rx_sel == dft_mpif->RXDIV_CFG1.bf.rx_sel ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG1.bf.rx_sel);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG1.bf.mode", tmp_mpif->RXDIV_CFG1.bf.mode, tmp_mpif->RXDIV_CFG1.bf.mode == dft_mpif->RXDIV_CFG1.bf.mode ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG1.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG1.wrd", tmp_mpif->TXDIV_CFG1.wrd, tmp_mpif->TXDIV_CFG1.wrd == dft_mpif->TXDIV_CFG1.wrd ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG1.bf.mode1", tmp_mpif->TXDIV_CFG1.bf.mode1, tmp_mpif->TXDIV_CFG1.bf.mode1 == dft_mpif->TXDIV_CFG1.bf.mode1 ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG1.bf.mode1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG1.bf.mode", tmp_mpif->TXDIV_CFG1.bf.mode, tmp_mpif->TXDIV_CFG1.bf.mode == dft_mpif->TXDIV_CFG1.bf.mode ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG1.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV1.wrd", tmp_mpif->RXLINE_DIV1.wrd, tmp_mpif->RXLINE_DIV1.wrd == dft_mpif->RXLINE_DIV1.wrd ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV1.bf.div", tmp_mpif->RXLINE_DIV1.bf.div, tmp_mpif->RXLINE_DIV1.bf.div == dft_mpif->RXLINE_DIV1.bf.div ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV1.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV1.wrd", tmp_mpif->TXLINE_DIV1.wrd, tmp_mpif->TXLINE_DIV1.wrd == dft_mpif->TXLINE_DIV1.wrd ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV1.bf.div", tmp_mpif->TXLINE_DIV1.bf.div, tmp_mpif->TXLINE_DIV1.bf.div == dft_mpif->TXLINE_DIV1.bf.div ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV1.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV1.wrd", tmp_mpif->PILOT_DIV1.wrd, tmp_mpif->PILOT_DIV1.wrd == dft_mpif->PILOT_DIV1.wrd ? 0x20 : 0x2A, dft_mpif->PILOT_DIV1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV1.bf.div", tmp_mpif->PILOT_DIV1.bf.div, tmp_mpif->PILOT_DIV1.bf.div == dft_mpif->PILOT_DIV1.bf.div ? 0x20 : 0x2A, dft_mpif->PILOT_DIV1.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG2.wrd", tmp_mpif->RXDIV_CFG2.wrd, tmp_mpif->RXDIV_CFG2.wrd == dft_mpif->RXDIV_CFG2.wrd ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG2.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG2.bf.pilot", tmp_mpif->RXDIV_CFG2.bf.pilot, tmp_mpif->RXDIV_CFG2.bf.pilot == dft_mpif->RXDIV_CFG2.bf.pilot ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG2.bf.pilot);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG2.bf.rx_sel", tmp_mpif->RXDIV_CFG2.bf.rx_sel, tmp_mpif->RXDIV_CFG2.bf.rx_sel == dft_mpif->RXDIV_CFG2.bf.rx_sel ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG2.bf.rx_sel);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG2.bf.mode", tmp_mpif->RXDIV_CFG2.bf.mode, tmp_mpif->RXDIV_CFG2.bf.mode == dft_mpif->RXDIV_CFG2.bf.mode ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG2.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG2.wrd", tmp_mpif->TXDIV_CFG2.wrd, tmp_mpif->TXDIV_CFG2.wrd == dft_mpif->TXDIV_CFG2.wrd ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG2.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG2.bf.mode1", tmp_mpif->TXDIV_CFG2.bf.mode1, tmp_mpif->TXDIV_CFG2.bf.mode1 == dft_mpif->TXDIV_CFG2.bf.mode1 ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG2.bf.mode1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG2.bf.mode", tmp_mpif->TXDIV_CFG2.bf.mode, tmp_mpif->TXDIV_CFG2.bf.mode == dft_mpif->TXDIV_CFG2.bf.mode ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG2.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV2.wrd", tmp_mpif->RXLINE_DIV2.wrd, tmp_mpif->RXLINE_DIV2.wrd == dft_mpif->RXLINE_DIV2.wrd ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV2.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV2.bf.div", tmp_mpif->RXLINE_DIV2.bf.div, tmp_mpif->RXLINE_DIV2.bf.div == dft_mpif->RXLINE_DIV2.bf.div ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV2.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV2.wrd", tmp_mpif->TXLINE_DIV2.wrd, tmp_mpif->TXLINE_DIV2.wrd == dft_mpif->TXLINE_DIV2.wrd ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV2.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV2.bf.div", tmp_mpif->TXLINE_DIV2.bf.div, tmp_mpif->TXLINE_DIV2.bf.div == dft_mpif->TXLINE_DIV2.bf.div ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV2.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV2.wrd", tmp_mpif->PILOT_DIV2.wrd, tmp_mpif->PILOT_DIV2.wrd == dft_mpif->PILOT_DIV2.wrd ? 0x20 : 0x2A, dft_mpif->PILOT_DIV2.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV2.bf.div", tmp_mpif->PILOT_DIV2.bf.div, tmp_mpif->PILOT_DIV2.bf.div == dft_mpif->PILOT_DIV2.bf.div ? 0x20 : 0x2A, dft_mpif->PILOT_DIV2.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG3.wrd", tmp_mpif->RXDIV_CFG3.wrd, tmp_mpif->RXDIV_CFG3.wrd == dft_mpif->RXDIV_CFG3.wrd ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG3.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG3.bf.pilot", tmp_mpif->RXDIV_CFG3.bf.pilot, tmp_mpif->RXDIV_CFG3.bf.pilot == dft_mpif->RXDIV_CFG3.bf.pilot ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG3.bf.pilot);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG3.bf.rx_sel", tmp_mpif->RXDIV_CFG3.bf.rx_sel, tmp_mpif->RXDIV_CFG3.bf.rx_sel == dft_mpif->RXDIV_CFG3.bf.rx_sel ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG3.bf.rx_sel);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG3.bf.mode", tmp_mpif->RXDIV_CFG3.bf.mode, tmp_mpif->RXDIV_CFG3.bf.mode == dft_mpif->RXDIV_CFG3.bf.mode ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG3.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG3.wrd", tmp_mpif->TXDIV_CFG3.wrd, tmp_mpif->TXDIV_CFG3.wrd == dft_mpif->TXDIV_CFG3.wrd ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG3.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG3.bf.mode1", tmp_mpif->TXDIV_CFG3.bf.mode1, tmp_mpif->TXDIV_CFG3.bf.mode1 == dft_mpif->TXDIV_CFG3.bf.mode1 ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG3.bf.mode1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG3.bf.mode", tmp_mpif->TXDIV_CFG3.bf.mode, tmp_mpif->TXDIV_CFG3.bf.mode == dft_mpif->TXDIV_CFG3.bf.mode ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG3.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV3.wrd", tmp_mpif->RXLINE_DIV3.wrd, tmp_mpif->RXLINE_DIV3.wrd == dft_mpif->RXLINE_DIV3.wrd ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV3.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV3.bf.div", tmp_mpif->RXLINE_DIV3.bf.div, tmp_mpif->RXLINE_DIV3.bf.div == dft_mpif->RXLINE_DIV3.bf.div ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV3.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV3.wrd", tmp_mpif->TXLINE_DIV3.wrd, tmp_mpif->TXLINE_DIV3.wrd == dft_mpif->TXLINE_DIV3.wrd ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV3.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV3.bf.div", tmp_mpif->TXLINE_DIV3.bf.div, tmp_mpif->TXLINE_DIV3.bf.div == dft_mpif->TXLINE_DIV3.bf.div ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV3.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV3.wrd", tmp_mpif->PILOT_DIV3.wrd, tmp_mpif->PILOT_DIV3.wrd == dft_mpif->PILOT_DIV3.wrd ? 0x20 : 0x2A, dft_mpif->PILOT_DIV3.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV3.bf.div", tmp_mpif->PILOT_DIV3.bf.div, tmp_mpif->PILOT_DIV3.bf.div == dft_mpif->PILOT_DIV3.bf.div ? 0x20 : 0x2A, dft_mpif->PILOT_DIV3.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG4.wrd", tmp_mpif->RXDIV_CFG4.wrd, tmp_mpif->RXDIV_CFG4.wrd == dft_mpif->RXDIV_CFG4.wrd ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG4.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG4.bf.pilot", tmp_mpif->RXDIV_CFG4.bf.pilot, tmp_mpif->RXDIV_CFG4.bf.pilot == dft_mpif->RXDIV_CFG4.bf.pilot ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG4.bf.pilot);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG4.bf.rx_sel", tmp_mpif->RXDIV_CFG4.bf.rx_sel, tmp_mpif->RXDIV_CFG4.bf.rx_sel == dft_mpif->RXDIV_CFG4.bf.rx_sel ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG4.bf.rx_sel);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG4.bf.mode", tmp_mpif->RXDIV_CFG4.bf.mode, tmp_mpif->RXDIV_CFG4.bf.mode == dft_mpif->RXDIV_CFG4.bf.mode ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG4.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG4.wrd", tmp_mpif->TXDIV_CFG4.wrd, tmp_mpif->TXDIV_CFG4.wrd == dft_mpif->TXDIV_CFG4.wrd ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG4.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG4.bf.mode1", tmp_mpif->TXDIV_CFG4.bf.mode1, tmp_mpif->TXDIV_CFG4.bf.mode1 == dft_mpif->TXDIV_CFG4.bf.mode1 ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG4.bf.mode1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG4.bf.mode", tmp_mpif->TXDIV_CFG4.bf.mode, tmp_mpif->TXDIV_CFG4.bf.mode == dft_mpif->TXDIV_CFG4.bf.mode ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG4.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV4.wrd", tmp_mpif->RXLINE_DIV4.wrd, tmp_mpif->RXLINE_DIV4.wrd == dft_mpif->RXLINE_DIV4.wrd ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV4.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV4.bf.div", tmp_mpif->RXLINE_DIV4.bf.div, tmp_mpif->RXLINE_DIV4.bf.div == dft_mpif->RXLINE_DIV4.bf.div ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV4.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV4.wrd", tmp_mpif->TXLINE_DIV4.wrd, tmp_mpif->TXLINE_DIV4.wrd == dft_mpif->TXLINE_DIV4.wrd ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV4.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV4.bf.div", tmp_mpif->TXLINE_DIV4.bf.div, tmp_mpif->TXLINE_DIV4.bf.div == dft_mpif->TXLINE_DIV4.bf.div ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV4.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV4.wrd", tmp_mpif->PILOT_DIV4.wrd, tmp_mpif->PILOT_DIV4.wrd == dft_mpif->PILOT_DIV4.wrd ? 0x20 : 0x2A, dft_mpif->PILOT_DIV4.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV4.bf.div", tmp_mpif->PILOT_DIV4.bf.div, tmp_mpif->PILOT_DIV4.bf.div == dft_mpif->PILOT_DIV4.bf.div ? 0x20 : 0x2A, dft_mpif->PILOT_DIV4.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG5.wrd", tmp_mpif->RXDIV_CFG5.wrd, tmp_mpif->RXDIV_CFG5.wrd == dft_mpif->RXDIV_CFG5.wrd ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG5.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG5.bf.pilot", tmp_mpif->RXDIV_CFG5.bf.pilot, tmp_mpif->RXDIV_CFG5.bf.pilot == dft_mpif->RXDIV_CFG5.bf.pilot ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG5.bf.pilot);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG5.bf.rx_sel", tmp_mpif->RXDIV_CFG5.bf.rx_sel, tmp_mpif->RXDIV_CFG5.bf.rx_sel == dft_mpif->RXDIV_CFG5.bf.rx_sel ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG5.bf.rx_sel);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG5.bf.mode", tmp_mpif->RXDIV_CFG5.bf.mode, tmp_mpif->RXDIV_CFG5.bf.mode == dft_mpif->RXDIV_CFG5.bf.mode ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG5.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG5.wrd", tmp_mpif->TXDIV_CFG5.wrd, tmp_mpif->TXDIV_CFG5.wrd == dft_mpif->TXDIV_CFG5.wrd ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG5.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG5.bf.mode1", tmp_mpif->TXDIV_CFG5.bf.mode1, tmp_mpif->TXDIV_CFG5.bf.mode1 == dft_mpif->TXDIV_CFG5.bf.mode1 ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG5.bf.mode1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG5.bf.mode", tmp_mpif->TXDIV_CFG5.bf.mode, tmp_mpif->TXDIV_CFG5.bf.mode == dft_mpif->TXDIV_CFG5.bf.mode ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG5.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV5.wrd", tmp_mpif->RXLINE_DIV5.wrd, tmp_mpif->RXLINE_DIV5.wrd == dft_mpif->RXLINE_DIV5.wrd ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV5.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV5.bf.div", tmp_mpif->RXLINE_DIV5.bf.div, tmp_mpif->RXLINE_DIV5.bf.div == dft_mpif->RXLINE_DIV5.bf.div ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV5.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV5.wrd", tmp_mpif->TXLINE_DIV5.wrd, tmp_mpif->TXLINE_DIV5.wrd == dft_mpif->TXLINE_DIV5.wrd ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV5.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV5.bf.div", tmp_mpif->TXLINE_DIV5.bf.div, tmp_mpif->TXLINE_DIV5.bf.div == dft_mpif->TXLINE_DIV5.bf.div ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV5.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV5.wrd", tmp_mpif->PILOT_DIV5.wrd, tmp_mpif->PILOT_DIV5.wrd == dft_mpif->PILOT_DIV5.wrd ? 0x20 : 0x2A, dft_mpif->PILOT_DIV5.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV5.bf.div", tmp_mpif->PILOT_DIV5.bf.div, tmp_mpif->PILOT_DIV5.bf.div == dft_mpif->PILOT_DIV5.bf.div ? 0x20 : 0x2A, dft_mpif->PILOT_DIV5.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG6.wrd", tmp_mpif->RXDIV_CFG6.wrd, tmp_mpif->RXDIV_CFG6.wrd == dft_mpif->RXDIV_CFG6.wrd ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG6.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG6.bf.pilot", tmp_mpif->RXDIV_CFG6.bf.pilot, tmp_mpif->RXDIV_CFG6.bf.pilot == dft_mpif->RXDIV_CFG6.bf.pilot ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG6.bf.pilot);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG6.bf.rx_sel", tmp_mpif->RXDIV_CFG6.bf.rx_sel, tmp_mpif->RXDIV_CFG6.bf.rx_sel == dft_mpif->RXDIV_CFG6.bf.rx_sel ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG6.bf.rx_sel);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG6.bf.mode", tmp_mpif->RXDIV_CFG6.bf.mode, tmp_mpif->RXDIV_CFG6.bf.mode == dft_mpif->RXDIV_CFG6.bf.mode ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG6.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG6.wrd", tmp_mpif->TXDIV_CFG6.wrd, tmp_mpif->TXDIV_CFG6.wrd == dft_mpif->TXDIV_CFG6.wrd ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG6.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG6.bf.mode1", tmp_mpif->TXDIV_CFG6.bf.mode1, tmp_mpif->TXDIV_CFG6.bf.mode1 == dft_mpif->TXDIV_CFG6.bf.mode1 ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG6.bf.mode1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG6.bf.mode", tmp_mpif->TXDIV_CFG6.bf.mode, tmp_mpif->TXDIV_CFG6.bf.mode == dft_mpif->TXDIV_CFG6.bf.mode ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG6.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV6.wrd", tmp_mpif->RXLINE_DIV6.wrd, tmp_mpif->RXLINE_DIV6.wrd == dft_mpif->RXLINE_DIV6.wrd ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV6.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV6.bf.div", tmp_mpif->RXLINE_DIV6.bf.div, tmp_mpif->RXLINE_DIV6.bf.div == dft_mpif->RXLINE_DIV6.bf.div ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV6.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV6.wrd", tmp_mpif->TXLINE_DIV6.wrd, tmp_mpif->TXLINE_DIV6.wrd == dft_mpif->TXLINE_DIV6.wrd ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV6.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV6.bf.div", tmp_mpif->TXLINE_DIV6.bf.div, tmp_mpif->TXLINE_DIV6.bf.div == dft_mpif->TXLINE_DIV6.bf.div ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV6.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV6.wrd", tmp_mpif->PILOT_DIV6.wrd, tmp_mpif->PILOT_DIV6.wrd == dft_mpif->PILOT_DIV6.wrd ? 0x20 : 0x2A, dft_mpif->PILOT_DIV6.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV6.bf.div", tmp_mpif->PILOT_DIV6.bf.div, tmp_mpif->PILOT_DIV6.bf.div == dft_mpif->PILOT_DIV6.bf.div ? 0x20 : 0x2A, dft_mpif->PILOT_DIV6.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG7.wrd", tmp_mpif->RXDIV_CFG7.wrd, tmp_mpif->RXDIV_CFG7.wrd == dft_mpif->RXDIV_CFG7.wrd ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG7.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG7.bf.pilot", tmp_mpif->RXDIV_CFG7.bf.pilot, tmp_mpif->RXDIV_CFG7.bf.pilot == dft_mpif->RXDIV_CFG7.bf.pilot ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG7.bf.pilot);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG7.bf.rx_sel", tmp_mpif->RXDIV_CFG7.bf.rx_sel, tmp_mpif->RXDIV_CFG7.bf.rx_sel == dft_mpif->RXDIV_CFG7.bf.rx_sel ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG7.bf.rx_sel);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXDIV_CFG7.bf.mode", tmp_mpif->RXDIV_CFG7.bf.mode, tmp_mpif->RXDIV_CFG7.bf.mode == dft_mpif->RXDIV_CFG7.bf.mode ? 0x20 : 0x2A, dft_mpif->RXDIV_CFG7.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG7.wrd", tmp_mpif->TXDIV_CFG7.wrd, tmp_mpif->TXDIV_CFG7.wrd == dft_mpif->TXDIV_CFG7.wrd ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG7.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG7.bf.mode1", tmp_mpif->TXDIV_CFG7.bf.mode1, tmp_mpif->TXDIV_CFG7.bf.mode1 == dft_mpif->TXDIV_CFG7.bf.mode1 ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG7.bf.mode1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXDIV_CFG7.bf.mode", tmp_mpif->TXDIV_CFG7.bf.mode, tmp_mpif->TXDIV_CFG7.bf.mode == dft_mpif->TXDIV_CFG7.bf.mode ? 0x20 : 0x2A, dft_mpif->TXDIV_CFG7.bf.mode);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV7.wrd", tmp_mpif->RXLINE_DIV7.wrd, tmp_mpif->RXLINE_DIV7.wrd == dft_mpif->RXLINE_DIV7.wrd ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV7.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_RXLINE_DIV7.bf.div", tmp_mpif->RXLINE_DIV7.bf.div, tmp_mpif->RXLINE_DIV7.bf.div == dft_mpif->RXLINE_DIV7.bf.div ? 0x20 : 0x2A, dft_mpif->RXLINE_DIV7.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV7.wrd", tmp_mpif->TXLINE_DIV7.wrd, tmp_mpif->TXLINE_DIV7.wrd == dft_mpif->TXLINE_DIV7.wrd ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV7.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_TXLINE_DIV7.bf.div", tmp_mpif->TXLINE_DIV7.bf.div, tmp_mpif->TXLINE_DIV7.bf.div == dft_mpif->TXLINE_DIV7.bf.div ? 0x20 : 0x2A, dft_mpif->TXLINE_DIV7.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV7.wrd", tmp_mpif->PILOT_DIV7.wrd, tmp_mpif->PILOT_DIV7.wrd == dft_mpif->PILOT_DIV7.wrd ? 0x20 : 0x2A, dft_mpif->PILOT_DIV7.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PILOT_DIV7.bf.div", tmp_mpif->PILOT_DIV7.bf.div, tmp_mpif->PILOT_DIV7.bf.div == dft_mpif->PILOT_DIV7.bf.div ? 0x20 : 0x2A, dft_mpif->PILOT_DIV7.bf.div);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_INTERRUPT.wrd", tmp_mpif->CUPLL_HOLDOVER_INTERRUPT.wrd, tmp_mpif->CUPLL_HOLDOVER_INTERRUPT.wrd == dft_mpif->CUPLL_HOLDOVER_INTERRUPT.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_INTERRUPT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_INTERRUPT.bf.REVi", tmp_mpif->CUPLL_HOLDOVER_INTERRUPT.bf.REVi, tmp_mpif->CUPLL_HOLDOVER_INTERRUPT.bf.REVi == dft_mpif->CUPLL_HOLDOVER_INTERRUPT.bf.REVi ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_INTERRUPT.bf.REVi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_INTERRUPT.bf.NONREVi", tmp_mpif->CUPLL_HOLDOVER_INTERRUPT.bf.NONREVi, tmp_mpif->CUPLL_HOLDOVER_INTERRUPT.bf.NONREVi == dft_mpif->CUPLL_HOLDOVER_INTERRUPT.bf.NONREVi ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_INTERRUPT.bf.NONREVi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_INTENABLE.wrd", tmp_mpif->CUPLL_HOLDOVER_INTENABLE.wrd, tmp_mpif->CUPLL_HOLDOVER_INTENABLE.wrd == dft_mpif->CUPLL_HOLDOVER_INTENABLE.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_INTENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_INTENABLE.bf.REVe", tmp_mpif->CUPLL_HOLDOVER_INTENABLE.bf.REVe, tmp_mpif->CUPLL_HOLDOVER_INTENABLE.bf.REVe == dft_mpif->CUPLL_HOLDOVER_INTENABLE.bf.REVe ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_INTENABLE.bf.REVe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_INTENABLE.bf.NONREVe", tmp_mpif->CUPLL_HOLDOVER_INTENABLE.bf.NONREVe, tmp_mpif->CUPLL_HOLDOVER_INTENABLE.bf.NONREVe == dft_mpif->CUPLL_HOLDOVER_INTENABLE.bf.NONREVe ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_INTENABLE.bf.NONREVe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_STATUS.wrd", tmp_mpif->CUPLL_HOLDOVER_STATUS.wrd, tmp_mpif->CUPLL_HOLDOVER_STATUS.wrd == dft_mpif->CUPLL_HOLDOVER_STATUS.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_STATUS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_STATUS.bf.REViO", tmp_mpif->CUPLL_HOLDOVER_STATUS.bf.REViO, tmp_mpif->CUPLL_HOLDOVER_STATUS.bf.REViO == dft_mpif->CUPLL_HOLDOVER_STATUS.bf.REViO ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_STATUS.bf.REViO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_STATUS.bf.NONREViO", tmp_mpif->CUPLL_HOLDOVER_STATUS.bf.NONREViO, tmp_mpif->CUPLL_HOLDOVER_STATUS.bf.NONREViO == dft_mpif->CUPLL_HOLDOVER_STATUS.bf.NONREViO ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_STATUS.bf.NONREViO);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_ISAS.wrd", tmp_mpif->CUPLL_HOLDOVER_ISAS.wrd, tmp_mpif->CUPLL_HOLDOVER_ISAS.wrd == dft_mpif->CUPLL_HOLDOVER_ISAS.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_ISAS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_ISAS.bf.REViZ", tmp_mpif->CUPLL_HOLDOVER_ISAS.bf.REViZ, tmp_mpif->CUPLL_HOLDOVER_ISAS.bf.REViZ == dft_mpif->CUPLL_HOLDOVER_ISAS.bf.REViZ ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_ISAS.bf.REViZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_ISAS.bf.NONREViZ", tmp_mpif->CUPLL_HOLDOVER_ISAS.bf.NONREViZ, tmp_mpif->CUPLL_HOLDOVER_ISAS.bf.NONREViZ == dft_mpif->CUPLL_HOLDOVER_ISAS.bf.NONREViZ ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_ISAS.bf.NONREViZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_FORCE.wrd", tmp_mpif->CUPLL_HOLDOVER_FORCE.wrd, tmp_mpif->CUPLL_HOLDOVER_FORCE.wrd == dft_mpif->CUPLL_HOLDOVER_FORCE.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_FORCE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_FORCE.bf.txb_off", tmp_mpif->CUPLL_HOLDOVER_FORCE.bf.txb_off, tmp_mpif->CUPLL_HOLDOVER_FORCE.bf.txb_off == dft_mpif->CUPLL_HOLDOVER_FORCE.bf.txb_off ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_FORCE.bf.txb_off);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_FORCE.bf.txa_off", tmp_mpif->CUPLL_HOLDOVER_FORCE.bf.txa_off, tmp_mpif->CUPLL_HOLDOVER_FORCE.bf.txa_off == dft_mpif->CUPLL_HOLDOVER_FORCE.bf.txa_off ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_FORCE.bf.txa_off);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_FORCE.bf.txb", tmp_mpif->CUPLL_HOLDOVER_FORCE.bf.txb, tmp_mpif->CUPLL_HOLDOVER_FORCE.bf.txb == dft_mpif->CUPLL_HOLDOVER_FORCE.bf.txb ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_FORCE.bf.txb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_FORCE.bf.txa", tmp_mpif->CUPLL_HOLDOVER_FORCE.bf.txa, tmp_mpif->CUPLL_HOLDOVER_FORCE.bf.txa == dft_mpif->CUPLL_HOLDOVER_FORCE.bf.txa ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_FORCE.bf.txa);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_XLOS.wrd", tmp_mpif->CUPLL_HOLDOVER_XLOS.wrd, tmp_mpif->CUPLL_HOLDOVER_XLOS.wrd == dft_mpif->CUPLL_HOLDOVER_XLOS.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_XLOS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_XLOS.bf.mrb2a", tmp_mpif->CUPLL_HOLDOVER_XLOS.bf.mrb2a, tmp_mpif->CUPLL_HOLDOVER_XLOS.bf.mrb2a == dft_mpif->CUPLL_HOLDOVER_XLOS.bf.mrb2a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_XLOS.bf.mrb2a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_XLOS.bf.xfi", tmp_mpif->CUPLL_HOLDOVER_XLOS.bf.xfi, tmp_mpif->CUPLL_HOLDOVER_XLOS.bf.xfi == dft_mpif->CUPLL_HOLDOVER_XLOS.bf.xfi ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_XLOS.bf.xfi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_XLOS.bf.mrb", tmp_mpif->CUPLL_HOLDOVER_XLOS.bf.mrb, tmp_mpif->CUPLL_HOLDOVER_XLOS.bf.mrb == dft_mpif->CUPLL_HOLDOVER_XLOS.bf.mrb ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_XLOS.bf.mrb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_XLOS.bf.mra", tmp_mpif->CUPLL_HOLDOVER_XLOS.bf.mra, tmp_mpif->CUPLL_HOLDOVER_XLOS.bf.mra == dft_mpif->CUPLL_HOLDOVER_XLOS.bf.mra ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_XLOS.bf.mra);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_LOCKDET.wrd", tmp_mpif->CUPLL_HOLDOVER_LOCKDET.wrd, tmp_mpif->CUPLL_HOLDOVER_LOCKDET.wrd == dft_mpif->CUPLL_HOLDOVER_LOCKDET.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_LOCKDET.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_LOCKDET.bf.mrb2a", tmp_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mrb2a, tmp_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mrb2a == dft_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mrb2a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mrb2a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_LOCKDET.bf.xfi", tmp_mpif->CUPLL_HOLDOVER_LOCKDET.bf.xfi, tmp_mpif->CUPLL_HOLDOVER_LOCKDET.bf.xfi == dft_mpif->CUPLL_HOLDOVER_LOCKDET.bf.xfi ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_LOCKDET.bf.xfi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_LOCKDET.bf.mrb", tmp_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mrb, tmp_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mrb == dft_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mrb ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mrb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_LOCKDET.bf.mra", tmp_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mra, tmp_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mra == dft_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mra ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_LOCKDET.bf.mra);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_CLKLOSS.wrd", tmp_mpif->CUPLL_HOLDOVER_CLKLOSS.wrd, tmp_mpif->CUPLL_HOLDOVER_CLKLOSS.wrd == dft_mpif->CUPLL_HOLDOVER_CLKLOSS.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_CLKLOSS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_CLKLOSS.bf.mrb2a", tmp_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mrb2a, tmp_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mrb2a == dft_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mrb2a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mrb2a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_CLKLOSS.bf.mrb", tmp_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mrb, tmp_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mrb == dft_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mrb ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mrb);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_CLKLOSS.bf.mra", tmp_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mra, tmp_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mra == dft_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mra ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_CLKLOSS.bf.mra);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_CBRGENAIS.wrd", tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.wrd, tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.wrd == dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_CBRGENAIS.bf.Four0g_b", tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.Four0g_b, tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.Four0g_b == dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.Four0g_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.Four0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_CBRGENAIS.bf.Four0g_a", tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.Four0g_a, tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.Four0g_a == dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.Four0g_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.Four0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_CBRGENAIS.bf.One0g_b", tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.One0g_b, tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.One0g_b == dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.One0g_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.One0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_CBRGENAIS.bf.One0g_a", tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.One0g_a, tmp_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.One0g_a == dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.One0g_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_CBRGENAIS.bf.One0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_PN11.wrd", tmp_mpif->CUPLL_HOLDOVER_PN11.wrd, tmp_mpif->CUPLL_HOLDOVER_PN11.wrd == dft_mpif->CUPLL_HOLDOVER_PN11.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_PN11.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_PN11.bf.Four0g_b", tmp_mpif->CUPLL_HOLDOVER_PN11.bf.Four0g_b, tmp_mpif->CUPLL_HOLDOVER_PN11.bf.Four0g_b == dft_mpif->CUPLL_HOLDOVER_PN11.bf.Four0g_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_PN11.bf.Four0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_PN11.bf.Four0g_a", tmp_mpif->CUPLL_HOLDOVER_PN11.bf.Four0g_a, tmp_mpif->CUPLL_HOLDOVER_PN11.bf.Four0g_a == dft_mpif->CUPLL_HOLDOVER_PN11.bf.Four0g_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_PN11.bf.Four0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_PN11.bf.One0g_b", tmp_mpif->CUPLL_HOLDOVER_PN11.bf.One0g_b, tmp_mpif->CUPLL_HOLDOVER_PN11.bf.One0g_b == dft_mpif->CUPLL_HOLDOVER_PN11.bf.One0g_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_PN11.bf.One0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_PN11.bf.One0g_a", tmp_mpif->CUPLL_HOLDOVER_PN11.bf.One0g_a, tmp_mpif->CUPLL_HOLDOVER_PN11.bf.One0g_a == dft_mpif->CUPLL_HOLDOVER_PN11.bf.One0g_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_PN11.bf.One0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_MS.wrd", tmp_mpif->CUPLL_HOLDOVER_MS.wrd, tmp_mpif->CUPLL_HOLDOVER_MS.wrd == dft_mpif->CUPLL_HOLDOVER_MS.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_MS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_MS.bf.Four0g_b", tmp_mpif->CUPLL_HOLDOVER_MS.bf.Four0g_b, tmp_mpif->CUPLL_HOLDOVER_MS.bf.Four0g_b == dft_mpif->CUPLL_HOLDOVER_MS.bf.Four0g_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_MS.bf.Four0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_MS.bf.Four0g_a", tmp_mpif->CUPLL_HOLDOVER_MS.bf.Four0g_a, tmp_mpif->CUPLL_HOLDOVER_MS.bf.Four0g_a == dft_mpif->CUPLL_HOLDOVER_MS.bf.Four0g_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_MS.bf.Four0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_MS.bf.One0g_b", tmp_mpif->CUPLL_HOLDOVER_MS.bf.One0g_b, tmp_mpif->CUPLL_HOLDOVER_MS.bf.One0g_b == dft_mpif->CUPLL_HOLDOVER_MS.bf.One0g_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_MS.bf.One0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_MS.bf.One0g_a", tmp_mpif->CUPLL_HOLDOVER_MS.bf.One0g_a, tmp_mpif->CUPLL_HOLDOVER_MS.bf.One0g_a == dft_mpif->CUPLL_HOLDOVER_MS.bf.One0g_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_MS.bf.One0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_MSAIS.wrd", tmp_mpif->CUPLL_HOLDOVER_MSAIS.wrd, tmp_mpif->CUPLL_HOLDOVER_MSAIS.wrd == dft_mpif->CUPLL_HOLDOVER_MSAIS.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_MSAIS.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_MSAIS.bf.One0g_b", tmp_mpif->CUPLL_HOLDOVER_MSAIS.bf.One0g_b, tmp_mpif->CUPLL_HOLDOVER_MSAIS.bf.One0g_b == dft_mpif->CUPLL_HOLDOVER_MSAIS.bf.One0g_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_MSAIS.bf.One0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_MSAIS.bf.One0g_a", tmp_mpif->CUPLL_HOLDOVER_MSAIS.bf.One0g_a, tmp_mpif->CUPLL_HOLDOVER_MSAIS.bf.One0g_a == dft_mpif->CUPLL_HOLDOVER_MSAIS.bf.One0g_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_MSAIS.bf.One0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_DW.wrd", tmp_mpif->CUPLL_HOLDOVER_DW.wrd, tmp_mpif->CUPLL_HOLDOVER_DW.wrd == dft_mpif->CUPLL_HOLDOVER_DW.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_DW.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_DW.bf.Four0g_b", tmp_mpif->CUPLL_HOLDOVER_DW.bf.Four0g_b, tmp_mpif->CUPLL_HOLDOVER_DW.bf.Four0g_b == dft_mpif->CUPLL_HOLDOVER_DW.bf.Four0g_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_DW.bf.Four0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_DW.bf.Four0g_a", tmp_mpif->CUPLL_HOLDOVER_DW.bf.Four0g_a, tmp_mpif->CUPLL_HOLDOVER_DW.bf.Four0g_a == dft_mpif->CUPLL_HOLDOVER_DW.bf.Four0g_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_DW.bf.Four0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_DW.bf.One0g_b", tmp_mpif->CUPLL_HOLDOVER_DW.bf.One0g_b, tmp_mpif->CUPLL_HOLDOVER_DW.bf.One0g_b == dft_mpif->CUPLL_HOLDOVER_DW.bf.One0g_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_DW.bf.One0g_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_DW.bf.One0g_a", tmp_mpif->CUPLL_HOLDOVER_DW.bf.One0g_a, tmp_mpif->CUPLL_HOLDOVER_DW.bf.One0g_a == dft_mpif->CUPLL_HOLDOVER_DW.bf.One0g_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_DW.bf.One0g_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_NONREVERT.wrd", tmp_mpif->CUPLL_HOLDOVER_NONREVERT.wrd, tmp_mpif->CUPLL_HOLDOVER_NONREVERT.wrd == dft_mpif->CUPLL_HOLDOVER_NONREVERT.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_NONREVERT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_NONREVERT.bf.clr_b", tmp_mpif->CUPLL_HOLDOVER_NONREVERT.bf.clr_b, tmp_mpif->CUPLL_HOLDOVER_NONREVERT.bf.clr_b == dft_mpif->CUPLL_HOLDOVER_NONREVERT.bf.clr_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_NONREVERT.bf.clr_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_NONREVERT.bf.clr_a", tmp_mpif->CUPLL_HOLDOVER_NONREVERT.bf.clr_a, tmp_mpif->CUPLL_HOLDOVER_NONREVERT.bf.clr_a == dft_mpif->CUPLL_HOLDOVER_NONREVERT.bf.clr_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_NONREVERT.bf.clr_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_NONREVERT.bf.en_b", tmp_mpif->CUPLL_HOLDOVER_NONREVERT.bf.en_b, tmp_mpif->CUPLL_HOLDOVER_NONREVERT.bf.en_b == dft_mpif->CUPLL_HOLDOVER_NONREVERT.bf.en_b ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_NONREVERT.bf.en_b);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_NONREVERT.bf.en_a", tmp_mpif->CUPLL_HOLDOVER_NONREVERT.bf.en_a, tmp_mpif->CUPLL_HOLDOVER_NONREVERT.bf.en_a == dft_mpif->CUPLL_HOLDOVER_NONREVERT.bf.en_a ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_NONREVERT.bf.en_a);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_SELECT.wrd", tmp_mpif->CUPLL_HOLDOVER_SELECT.wrd, tmp_mpif->CUPLL_HOLDOVER_SELECT.wrd == dft_mpif->CUPLL_HOLDOVER_SELECT.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_SELECT.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_SELECT.bf.sel3", tmp_mpif->CUPLL_HOLDOVER_SELECT.bf.sel3, tmp_mpif->CUPLL_HOLDOVER_SELECT.bf.sel3 == dft_mpif->CUPLL_HOLDOVER_SELECT.bf.sel3 ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_SELECT.bf.sel3);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_SELECT.bf.sel2", tmp_mpif->CUPLL_HOLDOVER_SELECT.bf.sel2, tmp_mpif->CUPLL_HOLDOVER_SELECT.bf.sel2 == dft_mpif->CUPLL_HOLDOVER_SELECT.bf.sel2 ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_SELECT.bf.sel2);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_SELECT.bf.sel1", tmp_mpif->CUPLL_HOLDOVER_SELECT.bf.sel1, tmp_mpif->CUPLL_HOLDOVER_SELECT.bf.sel1 == dft_mpif->CUPLL_HOLDOVER_SELECT.bf.sel1 ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_SELECT.bf.sel1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_HOLDOVER_SELECT.bf.sel0", tmp_mpif->CUPLL_HOLDOVER_SELECT.bf.sel0, tmp_mpif->CUPLL_HOLDOVER_SELECT.bf.sel0 == dft_mpif->CUPLL_HOLDOVER_SELECT.bf.sel0 ? 0x20 : 0x2A, dft_mpif->CUPLL_HOLDOVER_SELECT.bf.sel0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_FORCE.wrd", tmp_mpif->CUPLL_SETTLE_FORCE.wrd, tmp_mpif->CUPLL_SETTLE_FORCE.wrd == dft_mpif->CUPLL_SETTLE_FORCE.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_FORCE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_FORCE.bf.settle", tmp_mpif->CUPLL_SETTLE_FORCE.bf.settle, tmp_mpif->CUPLL_SETTLE_FORCE.bf.settle == dft_mpif->CUPLL_SETTLE_FORCE.bf.settle ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_FORCE.bf.settle);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_FORCE.bf.slow", tmp_mpif->CUPLL_SETTLE_FORCE.bf.slow, tmp_mpif->CUPLL_SETTLE_FORCE.bf.slow == dft_mpif->CUPLL_SETTLE_FORCE.bf.slow ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_FORCE.bf.slow);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_FORCE.bf.fast", tmp_mpif->CUPLL_SETTLE_FORCE.bf.fast, tmp_mpif->CUPLL_SETTLE_FORCE.bf.fast == dft_mpif->CUPLL_SETTLE_FORCE.bf.fast ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_FORCE.bf.fast);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_ENABLE.wrd", tmp_mpif->CUPLL_SETTLE_ENABLE.wrd, tmp_mpif->CUPLL_SETTLE_ENABLE.wrd == dft_mpif->CUPLL_SETTLE_ENABLE.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_ENABLE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_ENABLE.bf.holover_off", tmp_mpif->CUPLL_SETTLE_ENABLE.bf.holover_off, tmp_mpif->CUPLL_SETTLE_ENABLE.bf.holover_off == dft_mpif->CUPLL_SETTLE_ENABLE.bf.holover_off ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_ENABLE.bf.holover_off);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_ENABLE.bf.protect_off", tmp_mpif->CUPLL_SETTLE_ENABLE.bf.protect_off, tmp_mpif->CUPLL_SETTLE_ENABLE.bf.protect_off == dft_mpif->CUPLL_SETTLE_ENABLE.bf.protect_off ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_ENABLE.bf.protect_off);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_ENABLE.bf.protect_on", tmp_mpif->CUPLL_SETTLE_ENABLE.bf.protect_on, tmp_mpif->CUPLL_SETTLE_ENABLE.bf.protect_on == dft_mpif->CUPLL_SETTLE_ENABLE.bf.protect_on ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_ENABLE.bf.protect_on);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_TIMER0.wrd", tmp_mpif->CUPLL_SETTLE_TIMER0.wrd, tmp_mpif->CUPLL_SETTLE_TIMER0.wrd == dft_mpif->CUPLL_SETTLE_TIMER0.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_TIMER0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_TIMER0.bf.timer", tmp_mpif->CUPLL_SETTLE_TIMER0.bf.timer, tmp_mpif->CUPLL_SETTLE_TIMER0.bf.timer == dft_mpif->CUPLL_SETTLE_TIMER0.bf.timer ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_TIMER0.bf.timer);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_TIMER1.wrd", tmp_mpif->CUPLL_SETTLE_TIMER1.wrd, tmp_mpif->CUPLL_SETTLE_TIMER1.wrd == dft_mpif->CUPLL_SETTLE_TIMER1.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_TIMER1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_TIMER1.bf.timer", tmp_mpif->CUPLL_SETTLE_TIMER1.bf.timer, tmp_mpif->CUPLL_SETTLE_TIMER1.bf.timer == dft_mpif->CUPLL_SETTLE_TIMER1.bf.timer ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_TIMER1.bf.timer);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_TIMER2.wrd", tmp_mpif->CUPLL_SETTLE_TIMER2.wrd, tmp_mpif->CUPLL_SETTLE_TIMER2.wrd == dft_mpif->CUPLL_SETTLE_TIMER2.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_TIMER2.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_TIMER2.bf.timer", tmp_mpif->CUPLL_SETTLE_TIMER2.bf.timer, tmp_mpif->CUPLL_SETTLE_TIMER2.bf.timer == dft_mpif->CUPLL_SETTLE_TIMER2.bf.timer ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_TIMER2.bf.timer);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_TIMER3.wrd", tmp_mpif->CUPLL_SETTLE_TIMER3.wrd, tmp_mpif->CUPLL_SETTLE_TIMER3.wrd == dft_mpif->CUPLL_SETTLE_TIMER3.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_TIMER3.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_SETTLE_TIMER3.bf.timer", tmp_mpif->CUPLL_SETTLE_TIMER3.bf.timer, tmp_mpif->CUPLL_SETTLE_TIMER3.bf.timer == dft_mpif->CUPLL_SETTLE_TIMER3.bf.timer ? 0x20 : 0x2A, dft_mpif->CUPLL_SETTLE_TIMER3.bf.timer);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_LOCAL_FORCE.wrd", tmp_mpif->CUPLL_LOCAL_FORCE.wrd, tmp_mpif->CUPLL_LOCAL_FORCE.wrd == dft_mpif->CUPLL_LOCAL_FORCE.wrd ? 0x20 : 0x2A, dft_mpif->CUPLL_LOCAL_FORCE.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_LOCAL_FORCE.bf.follow", tmp_mpif->CUPLL_LOCAL_FORCE.bf.follow, tmp_mpif->CUPLL_LOCAL_FORCE.bf.follow == dft_mpif->CUPLL_LOCAL_FORCE.bf.follow ? 0x20 : 0x2A, dft_mpif->CUPLL_LOCAL_FORCE.bf.follow);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_LOCAL_FORCE.bf.off", tmp_mpif->CUPLL_LOCAL_FORCE.bf.off, tmp_mpif->CUPLL_LOCAL_FORCE.bf.off == dft_mpif->CUPLL_LOCAL_FORCE.bf.off ? 0x20 : 0x2A, dft_mpif->CUPLL_LOCAL_FORCE.bf.off);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_CUPLL_LOCAL_FORCE.bf.on", tmp_mpif->CUPLL_LOCAL_FORCE.bf.on, tmp_mpif->CUPLL_LOCAL_FORCE.bf.on == dft_mpif->CUPLL_LOCAL_FORCE.bf.on ? 0x20 : 0x2A, dft_mpif->CUPLL_LOCAL_FORCE.bf.on);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PREV_ADDRESS0.wrd", tmp_mpif->PREV_ADDRESS0.wrd, tmp_mpif->PREV_ADDRESS0.wrd == dft_mpif->PREV_ADDRESS0.wrd ? 0x20 : 0x2A, dft_mpif->PREV_ADDRESS0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PREV_ADDRESS0.bf.address", tmp_mpif->PREV_ADDRESS0.bf.address, tmp_mpif->PREV_ADDRESS0.bf.address == dft_mpif->PREV_ADDRESS0.bf.address ? 0x20 : 0x2A, dft_mpif->PREV_ADDRESS0.bf.address);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PREV_ADDRESS1.wrd", tmp_mpif->PREV_ADDRESS1.wrd, tmp_mpif->PREV_ADDRESS1.wrd == dft_mpif->PREV_ADDRESS1.wrd ? 0x20 : 0x2A, dft_mpif->PREV_ADDRESS1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PREV_ADDRESS1.bf.address", tmp_mpif->PREV_ADDRESS1.bf.address, tmp_mpif->PREV_ADDRESS1.bf.address == dft_mpif->PREV_ADDRESS1.bf.address ? 0x20 : 0x2A, dft_mpif->PREV_ADDRESS1.bf.address);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PREV_TRANSACTION.wrd", tmp_mpif->PREV_TRANSACTION.wrd, tmp_mpif->PREV_TRANSACTION.wrd == dft_mpif->PREV_TRANSACTION.wrd ? 0x20 : 0x2A, dft_mpif->PREV_TRANSACTION.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PREV_TRANSACTION.bf.rwn", tmp_mpif->PREV_TRANSACTION.bf.rwn, tmp_mpif->PREV_TRANSACTION.bf.rwn == dft_mpif->PREV_TRANSACTION.bf.rwn ? 0x20 : 0x2A, dft_mpif->PREV_TRANSACTION.bf.rwn);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PREV_DATA.wrd", tmp_mpif->PREV_DATA.wrd, tmp_mpif->PREV_DATA.wrd == dft_mpif->PREV_DATA.wrd ? 0x20 : 0x2A, dft_mpif->PREV_DATA.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "MPIF_PREV_DATA.bf.data", tmp_mpif->PREV_DATA.bf.data, tmp_mpif->PREV_DATA.bf.data == dft_mpif->PREV_DATA.bf.data ? 0x20 : 0x2A, dft_mpif->PREV_DATA.bf.data);
 
  CS_FREE(tmp_mpif);
  CS_FREE(dft_mpif);
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif                                       
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB DUMP SETTINGS                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_glb_dump_settings(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current GLB settings.                                   */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  TEN_glb_misc_t *tmp_glb, *dft_glb;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
                                             
  tmp_glb = (TEN_glb_misc_t *)CS_MALLOC(sizeof(TEN_glb_misc_t));
  dft_glb = (TEN_glb_misc_t *)CS_MALLOC(sizeof(TEN_glb_misc_t));

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
          
  tmp_glb->GSTI01.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI01));
  dft_glb->GSTI01.wrd = TEN_GLB_MISC_GSTI01_dft;   
  tmp_glb->GSTI00.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI00));
  dft_glb->GSTI00.wrd = TEN_GLB_MISC_GSTI00_dft;   
  tmp_glb->GSTI11.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI11));
  dft_glb->GSTI11.wrd = TEN_GLB_MISC_GSTI11_dft;    
  tmp_glb->GSTI10.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI10));
  dft_glb->GSTI10.wrd = TEN_GLB_MISC_GSTI10_dft;    
  tmp_glb->GSTI21.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI21));
  dft_glb->GSTI21.wrd = TEN_GLB_MISC_GSTI21_dft;    
  tmp_glb->GSTI20.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI20));
  dft_glb->GSTI20.wrd = TEN_GLB_MISC_GSTI20_dft;    
  tmp_glb->GSTI31.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI31));
  dft_glb->GSTI31.wrd = TEN_GLB_MISC_GSTI31_dft;    
  tmp_glb->GSTI30.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI30));
  dft_glb->GSTI30.wrd = TEN_GLB_MISC_GSTI30_dft;    
  tmp_glb->GSTI41.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI41));
  dft_glb->GSTI41.wrd = TEN_GLB_MISC_GSTI41_dft;    
  tmp_glb->GSTI40.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI40));
  dft_glb->GSTI40.wrd = TEN_GLB_MISC_GSTI40_dft;    
  tmp_glb->GSTI51.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI51));
  dft_glb->GSTI51.wrd = TEN_GLB_MISC_GSTI51_dft;    
  tmp_glb->GSTI50.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI50));
  dft_glb->GSTI50.wrd = TEN_GLB_MISC_GSTI50_dft;    
  tmp_glb->GSTI61.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI61));
  dft_glb->GSTI61.wrd = TEN_GLB_MISC_GSTI61_dft;    
  tmp_glb->GSTI60.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI60));
  dft_glb->GSTI60.wrd = TEN_GLB_MISC_GSTI60_dft;    
  tmp_glb->GSTI71.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI71));
  dft_glb->GSTI71.wrd = TEN_GLB_MISC_GSTI71_dft;    
  tmp_glb->GSTI70.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI70));
  dft_glb->GSTI70.wrd = TEN_GLB_MISC_GSTI70_dft;    
  tmp_glb->GSTI.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI));
  dft_glb->GSTI.wrd = TEN_GLB_MISC_GSTI_dft;        
  tmp_glb->MRA1_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRA1_LOSAF0));
  dft_glb->MRA1_LOSAF0.wrd = TEN_GLB_MISC_MRA1_LOSAF0_dft;
  tmp_glb->MRA1_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRA1_LOSAF1));
  dft_glb->MRA1_LOSAF1.wrd = TEN_GLB_MISC_MRA1_LOSAF1_dft;
  tmp_glb->MRA2_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRA2_LOSAF0));
  dft_glb->MRA2_LOSAF0.wrd = TEN_GLB_MISC_MRA2_LOSAF0_dft;
  tmp_glb->MRA2_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRA2_LOSAF1));
  dft_glb->MRA2_LOSAF1.wrd = TEN_GLB_MISC_MRA2_LOSAF1_dft;
  tmp_glb->MRA3_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRA3_LOSAF0));
  dft_glb->MRA3_LOSAF0.wrd = TEN_GLB_MISC_MRA3_LOSAF0_dft;
  tmp_glb->MRA3_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRA3_LOSAF1));
  dft_glb->MRA3_LOSAF1.wrd = TEN_GLB_MISC_MRA3_LOSAF1_dft;
  tmp_glb->MRA4_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRA4_LOSAF0));
  dft_glb->MRA4_LOSAF0.wrd = TEN_GLB_MISC_MRA4_LOSAF0_dft;
  tmp_glb->MRA4_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRA4_LOSAF1));
  dft_glb->MRA4_LOSAF1.wrd = TEN_GLB_MISC_MRA4_LOSAF1_dft;
  tmp_glb->MRB1_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRB1_LOSAF0));
  dft_glb->MRB1_LOSAF0.wrd = TEN_GLB_MISC_MRB1_LOSAF0_dft;
  tmp_glb->MRB1_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRB1_LOSAF1));
  dft_glb->MRB1_LOSAF1.wrd = TEN_GLB_MISC_MRB1_LOSAF1_dft;
  tmp_glb->MRB2_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRB2_LOSAF0));
  dft_glb->MRB2_LOSAF0.wrd = TEN_GLB_MISC_MRB2_LOSAF0_dft;
  tmp_glb->MRB2_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRB2_LOSAF1));
  dft_glb->MRB2_LOSAF1.wrd = TEN_GLB_MISC_MRB2_LOSAF1_dft;
  tmp_glb->MRB3_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRB3_LOSAF0));
  dft_glb->MRB3_LOSAF0.wrd = TEN_GLB_MISC_MRB3_LOSAF0_dft;
  tmp_glb->MRB3_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRB3_LOSAF1));
  dft_glb->MRB3_LOSAF1.wrd = TEN_GLB_MISC_MRB3_LOSAF1_dft;
  tmp_glb->MRB4_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRB4_LOSAF0));
  dft_glb->MRB4_LOSAF0.wrd = TEN_GLB_MISC_MRB4_LOSAF0_dft;
  tmp_glb->MRB4_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, MRB4_LOSAF1));
  dft_glb->MRB4_LOSAF1.wrd = TEN_GLB_MISC_MRB4_LOSAF1_dft;
  tmp_glb->XFI1_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XFI1_LOSAF0));
  dft_glb->XFI1_LOSAF0.wrd = TEN_GLB_MISC_XFI1_LOSAF0_dft;
  tmp_glb->XFI1_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XFI1_LOSAF1));
  dft_glb->XFI1_LOSAF1.wrd = TEN_GLB_MISC_XFI1_LOSAF1_dft;
  tmp_glb->XFI2_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XFI2_LOSAF0));
  dft_glb->XFI2_LOSAF0.wrd = TEN_GLB_MISC_XFI2_LOSAF0_dft;
  tmp_glb->XFI2_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XFI2_LOSAF1));
  dft_glb->XFI2_LOSAF1.wrd = TEN_GLB_MISC_XFI2_LOSAF1_dft;
  tmp_glb->XFI3_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XFI3_LOSAF0));
  dft_glb->XFI3_LOSAF0.wrd = TEN_GLB_MISC_XFI3_LOSAF0_dft;
  tmp_glb->XFI3_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XFI3_LOSAF1));
  dft_glb->XFI3_LOSAF1.wrd = TEN_GLB_MISC_XFI3_LOSAF1_dft;
  tmp_glb->XFI4_LOSAF0.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XFI4_LOSAF0));
  dft_glb->XFI4_LOSAF0.wrd = TEN_GLB_MISC_XFI4_LOSAF0_dft;
  tmp_glb->XFI4_LOSAF1.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XFI4_LOSAF1));
  dft_glb->XFI4_LOSAF1.wrd = TEN_GLB_MISC_XFI4_LOSAF1_dft;
  tmp_glb->XLOS_CFG.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XLOS_CFG));
  dft_glb->XLOS_CFG.wrd = TEN_GLB_MISC_XLOS_CFG_dft;
  tmp_glb->XLOS_INV.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XLOS_INV));
  dft_glb->XLOS_INV.wrd = TEN_GLB_MISC_XLOS_INV_dft;

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI01.wrd", tmp_glb->GSTI01.wrd, tmp_glb->GSTI01.wrd == dft_glb->GSTI01.wrd ? 0x20 : 0x2A, dft_glb->GSTI01.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI01.bf.BASE1", tmp_glb->GSTI01.bf.BASE1, tmp_glb->GSTI01.bf.BASE1 == dft_glb->GSTI01.bf.BASE1 ? 0x20 : 0x2A, dft_glb->GSTI01.bf.BASE1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI00.wrd", tmp_glb->GSTI00.wrd, tmp_glb->GSTI00.wrd == dft_glb->GSTI00.wrd ? 0x20 : 0x2A, dft_glb->GSTI00.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI00.bf.BASE0", tmp_glb->GSTI00.bf.BASE0, tmp_glb->GSTI00.bf.BASE0 == dft_glb->GSTI00.bf.BASE0 ? 0x20 : 0x2A, dft_glb->GSTI00.bf.BASE0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI11.wrd", tmp_glb->GSTI11.wrd, tmp_glb->GSTI11.wrd == dft_glb->GSTI11.wrd ? 0x20 : 0x2A, dft_glb->GSTI11.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI11.bf.BASE1", tmp_glb->GSTI11.bf.BASE1, tmp_glb->GSTI11.bf.BASE1 == dft_glb->GSTI11.bf.BASE1 ? 0x20 : 0x2A, dft_glb->GSTI11.bf.BASE1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI10.wrd", tmp_glb->GSTI10.wrd, tmp_glb->GSTI10.wrd == dft_glb->GSTI10.wrd ? 0x20 : 0x2A, dft_glb->GSTI10.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI10.bf.BASE0", tmp_glb->GSTI10.bf.BASE0, tmp_glb->GSTI10.bf.BASE0 == dft_glb->GSTI10.bf.BASE0 ? 0x20 : 0x2A, dft_glb->GSTI10.bf.BASE0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI21.wrd", tmp_glb->GSTI21.wrd, tmp_glb->GSTI21.wrd == dft_glb->GSTI21.wrd ? 0x20 : 0x2A, dft_glb->GSTI21.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI21.bf.BASE1", tmp_glb->GSTI21.bf.BASE1, tmp_glb->GSTI21.bf.BASE1 == dft_glb->GSTI21.bf.BASE1 ? 0x20 : 0x2A, dft_glb->GSTI21.bf.BASE1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI20.wrd", tmp_glb->GSTI20.wrd, tmp_glb->GSTI20.wrd == dft_glb->GSTI20.wrd ? 0x20 : 0x2A, dft_glb->GSTI20.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI20.bf.BASE0", tmp_glb->GSTI20.bf.BASE0, tmp_glb->GSTI20.bf.BASE0 == dft_glb->GSTI20.bf.BASE0 ? 0x20 : 0x2A, dft_glb->GSTI20.bf.BASE0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI31.wrd", tmp_glb->GSTI31.wrd, tmp_glb->GSTI31.wrd == dft_glb->GSTI31.wrd ? 0x20 : 0x2A, dft_glb->GSTI31.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI31.bf.BASE1", tmp_glb->GSTI31.bf.BASE1, tmp_glb->GSTI31.bf.BASE1 == dft_glb->GSTI31.bf.BASE1 ? 0x20 : 0x2A, dft_glb->GSTI31.bf.BASE1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI30.wrd", tmp_glb->GSTI30.wrd, tmp_glb->GSTI30.wrd == dft_glb->GSTI30.wrd ? 0x20 : 0x2A, dft_glb->GSTI30.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI30.bf.BASE0", tmp_glb->GSTI30.bf.BASE0, tmp_glb->GSTI30.bf.BASE0 == dft_glb->GSTI30.bf.BASE0 ? 0x20 : 0x2A, dft_glb->GSTI30.bf.BASE0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI41.wrd", tmp_glb->GSTI41.wrd, tmp_glb->GSTI41.wrd == dft_glb->GSTI41.wrd ? 0x20 : 0x2A, dft_glb->GSTI41.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI41.bf.BASE1", tmp_glb->GSTI41.bf.BASE1, tmp_glb->GSTI41.bf.BASE1 == dft_glb->GSTI41.bf.BASE1 ? 0x20 : 0x2A, dft_glb->GSTI41.bf.BASE1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI40.wrd", tmp_glb->GSTI40.wrd, tmp_glb->GSTI40.wrd == dft_glb->GSTI40.wrd ? 0x20 : 0x2A, dft_glb->GSTI40.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI40.bf.BASE0", tmp_glb->GSTI40.bf.BASE0, tmp_glb->GSTI40.bf.BASE0 == dft_glb->GSTI40.bf.BASE0 ? 0x20 : 0x2A, dft_glb->GSTI40.bf.BASE0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI51.wrd", tmp_glb->GSTI51.wrd, tmp_glb->GSTI51.wrd == dft_glb->GSTI51.wrd ? 0x20 : 0x2A, dft_glb->GSTI51.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI51.bf.BASE1", tmp_glb->GSTI51.bf.BASE1, tmp_glb->GSTI51.bf.BASE1 == dft_glb->GSTI51.bf.BASE1 ? 0x20 : 0x2A, dft_glb->GSTI51.bf.BASE1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI50.wrd", tmp_glb->GSTI50.wrd, tmp_glb->GSTI50.wrd == dft_glb->GSTI50.wrd ? 0x20 : 0x2A, dft_glb->GSTI50.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI50.bf.BASE0", tmp_glb->GSTI50.bf.BASE0, tmp_glb->GSTI50.bf.BASE0 == dft_glb->GSTI50.bf.BASE0 ? 0x20 : 0x2A, dft_glb->GSTI50.bf.BASE0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI61.wrd", tmp_glb->GSTI61.wrd, tmp_glb->GSTI61.wrd == dft_glb->GSTI61.wrd ? 0x20 : 0x2A, dft_glb->GSTI61.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI61.bf.BASE1", tmp_glb->GSTI61.bf.BASE1, tmp_glb->GSTI61.bf.BASE1 == dft_glb->GSTI61.bf.BASE1 ? 0x20 : 0x2A, dft_glb->GSTI61.bf.BASE1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI60.wrd", tmp_glb->GSTI60.wrd, tmp_glb->GSTI60.wrd == dft_glb->GSTI60.wrd ? 0x20 : 0x2A, dft_glb->GSTI60.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI60.bf.BASE0", tmp_glb->GSTI60.bf.BASE0, tmp_glb->GSTI60.bf.BASE0 == dft_glb->GSTI60.bf.BASE0 ? 0x20 : 0x2A, dft_glb->GSTI60.bf.BASE0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI71.wrd", tmp_glb->GSTI71.wrd, tmp_glb->GSTI71.wrd == dft_glb->GSTI71.wrd ? 0x20 : 0x2A, dft_glb->GSTI71.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI71.bf.BASE1", tmp_glb->GSTI71.bf.BASE1, tmp_glb->GSTI71.bf.BASE1 == dft_glb->GSTI71.bf.BASE1 ? 0x20 : 0x2A, dft_glb->GSTI71.bf.BASE1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI70.wrd", tmp_glb->GSTI70.wrd, tmp_glb->GSTI70.wrd == dft_glb->GSTI70.wrd ? 0x20 : 0x2A, dft_glb->GSTI70.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI70.bf.BASE0", tmp_glb->GSTI70.bf.BASE0, tmp_glb->GSTI70.bf.BASE0 == dft_glb->GSTI70.bf.BASE0 ? 0x20 : 0x2A, dft_glb->GSTI70.bf.BASE0);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI.wrd", tmp_glb->GSTI.wrd, tmp_glb->GSTI.wrd == dft_glb->GSTI.wrd ? 0x20 : 0x2A, dft_glb->GSTI.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI.bf.SW", tmp_glb->GSTI.bf.SW, tmp_glb->GSTI.bf.SW == dft_glb->GSTI.bf.SW ? 0x20 : 0x2A, dft_glb->GSTI.bf.SW);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI.bf.PRESCALE", tmp_glb->GSTI.bf.PRESCALE, tmp_glb->GSTI.bf.PRESCALE == dft_glb->GSTI.bf.PRESCALE ? 0x20 : 0x2A, dft_glb->GSTI.bf.PRESCALE);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_GSTI.bf.INIT", tmp_glb->GSTI.bf.INIT, tmp_glb->GSTI.bf.INIT == dft_glb->GSTI.bf.INIT ? 0x20 : 0x2A, dft_glb->GSTI.bf.INIT);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA1_LOSAF0.wrd", tmp_glb->MRA1_LOSAF0.wrd, tmp_glb->MRA1_LOSAF0.wrd == dft_glb->MRA1_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->MRA1_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA1_LOSAF0.bf.LOS_SIV", tmp_glb->MRA1_LOSAF0.bf.LOS_SIV, tmp_glb->MRA1_LOSAF0.bf.LOS_SIV == dft_glb->MRA1_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->MRA1_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA1_LOSAF0.bf.LOS_STV", tmp_glb->MRA1_LOSAF0.bf.LOS_STV, tmp_glb->MRA1_LOSAF0.bf.LOS_STV == dft_glb->MRA1_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->MRA1_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA1_LOSAF1.wrd", tmp_glb->MRA1_LOSAF1.wrd, tmp_glb->MRA1_LOSAF1.wrd == dft_glb->MRA1_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->MRA1_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA1_LOSAF1.bf.LOS_UIV", tmp_glb->MRA1_LOSAF1.bf.LOS_UIV, tmp_glb->MRA1_LOSAF1.bf.LOS_UIV == dft_glb->MRA1_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->MRA1_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA1_LOSAF1.bf.LOS_UTV", tmp_glb->MRA1_LOSAF1.bf.LOS_UTV, tmp_glb->MRA1_LOSAF1.bf.LOS_UTV == dft_glb->MRA1_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->MRA1_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA2_LOSAF0.wrd", tmp_glb->MRA2_LOSAF0.wrd, tmp_glb->MRA2_LOSAF0.wrd == dft_glb->MRA2_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->MRA2_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA2_LOSAF0.bf.LOS_SIV", tmp_glb->MRA2_LOSAF0.bf.LOS_SIV, tmp_glb->MRA2_LOSAF0.bf.LOS_SIV == dft_glb->MRA2_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->MRA2_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA2_LOSAF0.bf.LOS_STV", tmp_glb->MRA2_LOSAF0.bf.LOS_STV, tmp_glb->MRA2_LOSAF0.bf.LOS_STV == dft_glb->MRA2_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->MRA2_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA2_LOSAF1.wrd", tmp_glb->MRA2_LOSAF1.wrd, tmp_glb->MRA2_LOSAF1.wrd == dft_glb->MRA2_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->MRA2_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA2_LOSAF1.bf.LOS_UIV", tmp_glb->MRA2_LOSAF1.bf.LOS_UIV, tmp_glb->MRA2_LOSAF1.bf.LOS_UIV == dft_glb->MRA2_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->MRA2_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA2_LOSAF1.bf.LOS_UTV", tmp_glb->MRA2_LOSAF1.bf.LOS_UTV, tmp_glb->MRA2_LOSAF1.bf.LOS_UTV == dft_glb->MRA2_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->MRA2_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA3_LOSAF0.wrd", tmp_glb->MRA3_LOSAF0.wrd, tmp_glb->MRA3_LOSAF0.wrd == dft_glb->MRA3_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->MRA3_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA3_LOSAF0.bf.LOS_SIV", tmp_glb->MRA3_LOSAF0.bf.LOS_SIV, tmp_glb->MRA3_LOSAF0.bf.LOS_SIV == dft_glb->MRA3_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->MRA3_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA3_LOSAF0.bf.LOS_STV", tmp_glb->MRA3_LOSAF0.bf.LOS_STV, tmp_glb->MRA3_LOSAF0.bf.LOS_STV == dft_glb->MRA3_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->MRA3_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA3_LOSAF1.wrd", tmp_glb->MRA3_LOSAF1.wrd, tmp_glb->MRA3_LOSAF1.wrd == dft_glb->MRA3_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->MRA3_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA3_LOSAF1.bf.LOS_UIV", tmp_glb->MRA3_LOSAF1.bf.LOS_UIV, tmp_glb->MRA3_LOSAF1.bf.LOS_UIV == dft_glb->MRA3_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->MRA3_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA3_LOSAF1.bf.LOS_UTV", tmp_glb->MRA3_LOSAF1.bf.LOS_UTV, tmp_glb->MRA3_LOSAF1.bf.LOS_UTV == dft_glb->MRA3_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->MRA3_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA4_LOSAF0.wrd", tmp_glb->MRA4_LOSAF0.wrd, tmp_glb->MRA4_LOSAF0.wrd == dft_glb->MRA4_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->MRA4_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA4_LOSAF0.bf.LOS_SIV", tmp_glb->MRA4_LOSAF0.bf.LOS_SIV, tmp_glb->MRA4_LOSAF0.bf.LOS_SIV == dft_glb->MRA4_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->MRA4_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA4_LOSAF0.bf.LOS_STV", tmp_glb->MRA4_LOSAF0.bf.LOS_STV, tmp_glb->MRA4_LOSAF0.bf.LOS_STV == dft_glb->MRA4_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->MRA4_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA4_LOSAF1.wrd", tmp_glb->MRA4_LOSAF1.wrd, tmp_glb->MRA4_LOSAF1.wrd == dft_glb->MRA4_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->MRA4_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA4_LOSAF1.bf.LOS_UIV", tmp_glb->MRA4_LOSAF1.bf.LOS_UIV, tmp_glb->MRA4_LOSAF1.bf.LOS_UIV == dft_glb->MRA4_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->MRA4_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRA4_LOSAF1.bf.LOS_UTV", tmp_glb->MRA4_LOSAF1.bf.LOS_UTV, tmp_glb->MRA4_LOSAF1.bf.LOS_UTV == dft_glb->MRA4_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->MRA4_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB1_LOSAF0.wrd", tmp_glb->MRB1_LOSAF0.wrd, tmp_glb->MRB1_LOSAF0.wrd == dft_glb->MRB1_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->MRB1_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB1_LOSAF0.bf.LOS_SIV", tmp_glb->MRB1_LOSAF0.bf.LOS_SIV, tmp_glb->MRB1_LOSAF0.bf.LOS_SIV == dft_glb->MRB1_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->MRB1_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB1_LOSAF0.bf.LOS_STV", tmp_glb->MRB1_LOSAF0.bf.LOS_STV, tmp_glb->MRB1_LOSAF0.bf.LOS_STV == dft_glb->MRB1_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->MRB1_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB1_LOSAF1.wrd", tmp_glb->MRB1_LOSAF1.wrd, tmp_glb->MRB1_LOSAF1.wrd == dft_glb->MRB1_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->MRB1_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB1_LOSAF1.bf.LOS_UIV", tmp_glb->MRB1_LOSAF1.bf.LOS_UIV, tmp_glb->MRB1_LOSAF1.bf.LOS_UIV == dft_glb->MRB1_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->MRB1_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB1_LOSAF1.bf.LOS_UTV", tmp_glb->MRB1_LOSAF1.bf.LOS_UTV, tmp_glb->MRB1_LOSAF1.bf.LOS_UTV == dft_glb->MRB1_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->MRB1_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB2_LOSAF0.wrd", tmp_glb->MRB2_LOSAF0.wrd, tmp_glb->MRB2_LOSAF0.wrd == dft_glb->MRB2_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->MRB2_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB2_LOSAF0.bf.LOS_SIV", tmp_glb->MRB2_LOSAF0.bf.LOS_SIV, tmp_glb->MRB2_LOSAF0.bf.LOS_SIV == dft_glb->MRB2_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->MRB2_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB2_LOSAF0.bf.LOS_STV", tmp_glb->MRB2_LOSAF0.bf.LOS_STV, tmp_glb->MRB2_LOSAF0.bf.LOS_STV == dft_glb->MRB2_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->MRB2_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB2_LOSAF1.wrd", tmp_glb->MRB2_LOSAF1.wrd, tmp_glb->MRB2_LOSAF1.wrd == dft_glb->MRB2_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->MRB2_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB2_LOSAF1.bf.LOS_UIV", tmp_glb->MRB2_LOSAF1.bf.LOS_UIV, tmp_glb->MRB2_LOSAF1.bf.LOS_UIV == dft_glb->MRB2_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->MRB2_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB2_LOSAF1.bf.LOS_UTV", tmp_glb->MRB2_LOSAF1.bf.LOS_UTV, tmp_glb->MRB2_LOSAF1.bf.LOS_UTV == dft_glb->MRB2_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->MRB2_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB3_LOSAF0.wrd", tmp_glb->MRB3_LOSAF0.wrd, tmp_glb->MRB3_LOSAF0.wrd == dft_glb->MRB3_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->MRB3_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB3_LOSAF0.bf.LOS_SIV", tmp_glb->MRB3_LOSAF0.bf.LOS_SIV, tmp_glb->MRB3_LOSAF0.bf.LOS_SIV == dft_glb->MRB3_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->MRB3_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB3_LOSAF0.bf.LOS_STV", tmp_glb->MRB3_LOSAF0.bf.LOS_STV, tmp_glb->MRB3_LOSAF0.bf.LOS_STV == dft_glb->MRB3_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->MRB3_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB3_LOSAF1.wrd", tmp_glb->MRB3_LOSAF1.wrd, tmp_glb->MRB3_LOSAF1.wrd == dft_glb->MRB3_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->MRB3_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB3_LOSAF1.bf.LOS_UIV", tmp_glb->MRB3_LOSAF1.bf.LOS_UIV, tmp_glb->MRB3_LOSAF1.bf.LOS_UIV == dft_glb->MRB3_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->MRB3_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB3_LOSAF1.bf.LOS_UTV", tmp_glb->MRB3_LOSAF1.bf.LOS_UTV, tmp_glb->MRB3_LOSAF1.bf.LOS_UTV == dft_glb->MRB3_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->MRB3_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB4_LOSAF0.wrd", tmp_glb->MRB4_LOSAF0.wrd, tmp_glb->MRB4_LOSAF0.wrd == dft_glb->MRB4_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->MRB4_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB4_LOSAF0.bf.LOS_SIV", tmp_glb->MRB4_LOSAF0.bf.LOS_SIV, tmp_glb->MRB4_LOSAF0.bf.LOS_SIV == dft_glb->MRB4_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->MRB4_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB4_LOSAF0.bf.LOS_STV", tmp_glb->MRB4_LOSAF0.bf.LOS_STV, tmp_glb->MRB4_LOSAF0.bf.LOS_STV == dft_glb->MRB4_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->MRB4_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB4_LOSAF1.wrd", tmp_glb->MRB4_LOSAF1.wrd, tmp_glb->MRB4_LOSAF1.wrd == dft_glb->MRB4_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->MRB4_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB4_LOSAF1.bf.LOS_UIV", tmp_glb->MRB4_LOSAF1.bf.LOS_UIV, tmp_glb->MRB4_LOSAF1.bf.LOS_UIV == dft_glb->MRB4_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->MRB4_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_MRB4_LOSAF1.bf.LOS_UTV", tmp_glb->MRB4_LOSAF1.bf.LOS_UTV, tmp_glb->MRB4_LOSAF1.bf.LOS_UTV == dft_glb->MRB4_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->MRB4_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI1_LOSAF0.wrd", tmp_glb->XFI1_LOSAF0.wrd, tmp_glb->XFI1_LOSAF0.wrd == dft_glb->XFI1_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->XFI1_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI1_LOSAF0.bf.LOS_SIV", tmp_glb->XFI1_LOSAF0.bf.LOS_SIV, tmp_glb->XFI1_LOSAF0.bf.LOS_SIV == dft_glb->XFI1_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->XFI1_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI1_LOSAF0.bf.LOS_STV", tmp_glb->XFI1_LOSAF0.bf.LOS_STV, tmp_glb->XFI1_LOSAF0.bf.LOS_STV == dft_glb->XFI1_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->XFI1_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI1_LOSAF1.wrd", tmp_glb->XFI1_LOSAF1.wrd, tmp_glb->XFI1_LOSAF1.wrd == dft_glb->XFI1_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->XFI1_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI1_LOSAF1.bf.LOS_UIV", tmp_glb->XFI1_LOSAF1.bf.LOS_UIV, tmp_glb->XFI1_LOSAF1.bf.LOS_UIV == dft_glb->XFI1_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->XFI1_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI1_LOSAF1.bf.LOS_UTV", tmp_glb->XFI1_LOSAF1.bf.LOS_UTV, tmp_glb->XFI1_LOSAF1.bf.LOS_UTV == dft_glb->XFI1_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->XFI1_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI2_LOSAF0.wrd", tmp_glb->XFI2_LOSAF0.wrd, tmp_glb->XFI2_LOSAF0.wrd == dft_glb->XFI2_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->XFI2_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI2_LOSAF0.bf.LOS_SIV", tmp_glb->XFI2_LOSAF0.bf.LOS_SIV, tmp_glb->XFI2_LOSAF0.bf.LOS_SIV == dft_glb->XFI2_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->XFI2_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI2_LOSAF0.bf.LOS_STV", tmp_glb->XFI2_LOSAF0.bf.LOS_STV, tmp_glb->XFI2_LOSAF0.bf.LOS_STV == dft_glb->XFI2_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->XFI2_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI2_LOSAF1.wrd", tmp_glb->XFI2_LOSAF1.wrd, tmp_glb->XFI2_LOSAF1.wrd == dft_glb->XFI2_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->XFI2_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI2_LOSAF1.bf.LOS_UIV", tmp_glb->XFI2_LOSAF1.bf.LOS_UIV, tmp_glb->XFI2_LOSAF1.bf.LOS_UIV == dft_glb->XFI2_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->XFI2_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI2_LOSAF1.bf.LOS_UTV", tmp_glb->XFI2_LOSAF1.bf.LOS_UTV, tmp_glb->XFI2_LOSAF1.bf.LOS_UTV == dft_glb->XFI2_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->XFI2_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI3_LOSAF0.wrd", tmp_glb->XFI3_LOSAF0.wrd, tmp_glb->XFI3_LOSAF0.wrd == dft_glb->XFI3_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->XFI3_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI3_LOSAF0.bf.LOS_SIV", tmp_glb->XFI3_LOSAF0.bf.LOS_SIV, tmp_glb->XFI3_LOSAF0.bf.LOS_SIV == dft_glb->XFI3_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->XFI3_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI3_LOSAF0.bf.LOS_STV", tmp_glb->XFI3_LOSAF0.bf.LOS_STV, tmp_glb->XFI3_LOSAF0.bf.LOS_STV == dft_glb->XFI3_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->XFI3_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI3_LOSAF1.wrd", tmp_glb->XFI3_LOSAF1.wrd, tmp_glb->XFI3_LOSAF1.wrd == dft_glb->XFI3_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->XFI3_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI3_LOSAF1.bf.LOS_UIV", tmp_glb->XFI3_LOSAF1.bf.LOS_UIV, tmp_glb->XFI3_LOSAF1.bf.LOS_UIV == dft_glb->XFI3_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->XFI3_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI3_LOSAF1.bf.LOS_UTV", tmp_glb->XFI3_LOSAF1.bf.LOS_UTV, tmp_glb->XFI3_LOSAF1.bf.LOS_UTV == dft_glb->XFI3_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->XFI3_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI4_LOSAF0.wrd", tmp_glb->XFI4_LOSAF0.wrd, tmp_glb->XFI4_LOSAF0.wrd == dft_glb->XFI4_LOSAF0.wrd ? 0x20 : 0x2A, dft_glb->XFI4_LOSAF0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI4_LOSAF0.bf.LOS_SIV", tmp_glb->XFI4_LOSAF0.bf.LOS_SIV, tmp_glb->XFI4_LOSAF0.bf.LOS_SIV == dft_glb->XFI4_LOSAF0.bf.LOS_SIV ? 0x20 : 0x2A, dft_glb->XFI4_LOSAF0.bf.LOS_SIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI4_LOSAF0.bf.LOS_STV", tmp_glb->XFI4_LOSAF0.bf.LOS_STV, tmp_glb->XFI4_LOSAF0.bf.LOS_STV == dft_glb->XFI4_LOSAF0.bf.LOS_STV ? 0x20 : 0x2A, dft_glb->XFI4_LOSAF0.bf.LOS_STV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI4_LOSAF1.wrd", tmp_glb->XFI4_LOSAF1.wrd, tmp_glb->XFI4_LOSAF1.wrd == dft_glb->XFI4_LOSAF1.wrd ? 0x20 : 0x2A, dft_glb->XFI4_LOSAF1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI4_LOSAF1.bf.LOS_UIV", tmp_glb->XFI4_LOSAF1.bf.LOS_UIV, tmp_glb->XFI4_LOSAF1.bf.LOS_UIV == dft_glb->XFI4_LOSAF1.bf.LOS_UIV ? 0x20 : 0x2A, dft_glb->XFI4_LOSAF1.bf.LOS_UIV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XFI4_LOSAF1.bf.LOS_UTV", tmp_glb->XFI4_LOSAF1.bf.LOS_UTV, tmp_glb->XFI4_LOSAF1.bf.LOS_UTV == dft_glb->XFI4_LOSAF1.bf.LOS_UTV ? 0x20 : 0x2A, dft_glb->XFI4_LOSAF1.bf.LOS_UTV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XLOS_CFG.wrd", tmp_glb->XLOS_CFG.wrd, tmp_glb->XLOS_CFG.wrd == dft_glb->XLOS_CFG.wrd ? 0x20 : 0x2A, dft_glb->XLOS_CFG.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XLOS_CFG.bf.CLEAR", tmp_glb->XLOS_CFG.bf.CLEAR, tmp_glb->XLOS_CFG.bf.CLEAR == dft_glb->XLOS_CFG.bf.CLEAR ? 0x20 : 0x2A, dft_glb->XLOS_CFG.bf.CLEAR);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XLOS_CFG.bf.PRESCALE", tmp_glb->XLOS_CFG.bf.PRESCALE, tmp_glb->XLOS_CFG.bf.PRESCALE == dft_glb->XLOS_CFG.bf.PRESCALE ? 0x20 : 0x2A, dft_glb->XLOS_CFG.bf.PRESCALE);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XLOS_INV.wrd", tmp_glb->XLOS_INV.wrd, tmp_glb->XLOS_INV.wrd == dft_glb->XLOS_INV.wrd ? 0x20 : 0x2A, dft_glb->XLOS_INV.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XLOS_INV.bf.XFI", tmp_glb->XLOS_INV.bf.XFI, tmp_glb->XLOS_INV.bf.XFI == dft_glb->XLOS_INV.bf.XFI ? 0x20 : 0x2A, dft_glb->XLOS_INV.bf.XFI);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XLOS_INV.bf.MRB", tmp_glb->XLOS_INV.bf.MRB, tmp_glb->XLOS_INV.bf.MRB == dft_glb->XLOS_INV.bf.MRB ? 0x20 : 0x2A, dft_glb->XLOS_INV.bf.MRB);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "GLB_MISC_XLOS_INV.bf.MRA", tmp_glb->XLOS_INV.bf.MRA, tmp_glb->XLOS_INV.bf.MRA == dft_glb->XLOS_INV.bf.MRA ? 0x20 : 0x2A, dft_glb->XLOS_INV.bf.MRA);
 
  CS_FREE(tmp_glb);
  CS_FREE(dft_glb);
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV DUMP SETTINGS                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_frac_div_dump_settings(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current FRAC DIV settings.                              */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  TEN_frac_div_t *tmp_frac_div, *dft_frac_div;
  cs_uint16 ii;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
                                             
  tmp_frac_div = (TEN_frac_div_t *)CS_MALLOC(sizeof(TEN_frac_div_t));
  dft_frac_div = (TEN_frac_div_t *)CS_MALLOC(sizeof(TEN_frac_div_t));

  /* Bugzilla 28734 Klocwork fix, this block */
  /* Ckeck for failed alloc, return if failed. */
  if ((tmp_frac_div == 0) || (dft_frac_div == 0)) {
    if (tmp_frac_div) CS_FREE(tmp_frac_div);
    if (dft_frac_div) CS_FREE(dft_frac_div);
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  printf("FRAC_DIV_S2PL1: %08x\n",TEN_FRAC_DIV_REG_ADDR(pDev, FRAC_DIV_S2PL1));
  tmp_frac_div->FRAC_DIV_S2PL1.wrd = TEN_REG_READ(TEN_FRAC_DIV_REG_ADDR(pDev, FRAC_DIV_S2PL1));
  dft_frac_div->FRAC_DIV_S2PL1.wrd = TEN_FRAC_DIV_COMMON_FRAC_DIV_S2PL1_dft;
   printf("FRAC_DIV_S2PL0: %08x\n",TEN_FRAC_DIV_REG_ADDR(pDev, FRAC_DIV_S2PL0));
  tmp_frac_div->FRAC_DIV_S2PL0.wrd = TEN_REG_READ(TEN_FRAC_DIV_REG_ADDR(pDev, FRAC_DIV_S2PL0));
  dft_frac_div->FRAC_DIV_S2PL0.wrd = TEN_FRAC_DIV_COMMON_FRAC_DIV_S2PL0_dft;
 
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "TEN_FRAC_DIV_COMMON_FRAC_DIV_S2PL1.wrd", tmp_frac_div->FRAC_DIV_S2PL1.wrd, tmp_frac_div->FRAC_DIV_S2PL1.wrd == dft_frac_div->FRAC_DIV_S2PL1.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S2PL1.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "TEN_FRAC_DIV_COMMON_FRAC_DIV_S2PL1.bf.value1", tmp_frac_div->FRAC_DIV_S2PL1.bf.value1, tmp_frac_div->FRAC_DIV_S2PL1.bf.value1 == dft_frac_div->FRAC_DIV_S2PL1.bf.value1 ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S2PL1.bf.value1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "TEN_FRAC_DIV_COMMON_FRAC_DIV_S2PL0.wrd", tmp_frac_div->FRAC_DIV_S2PL0.wrd, tmp_frac_div->FRAC_DIV_S2PL0.wrd == dft_frac_div->FRAC_DIV_S2PL0.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S2PL0.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "TEN_FRAC_DIV_COMMON_FRAC_DIV_S2PL0.bf.value0", tmp_frac_div->FRAC_DIV_S2PL0.bf.value0, tmp_frac_div->FRAC_DIV_S2PL0.bf.value0 == dft_frac_div->FRAC_DIV_S2PL0.bf.value0 ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S2PL0.bf.value0);
 
  dft_frac_div->cfg_FRAC_DIV_RESET.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_RESET_dft;
  dft_frac_div->FRAC_DIV_ENABLE.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_ENABLE_dft;
  dft_frac_div->FRAC_DIV_N1.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_N1_dft;
  dft_frac_div->FRAC_DIV_N0.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_N0_dft;
  dft_frac_div->FRAC_DIV_WIDTH.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_WIDTH_dft;
  dft_frac_div->FRAC_DIV_S1EN.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_S1EN_dft;
  dft_frac_div->FRAC_DIV_S2EN.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_S2EN_dft;
  dft_frac_div->FRAC_DIV_S1PL1.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_S1PL1_dft;
  dft_frac_div->FRAC_DIV_S1PL0.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_S1PL0_dft;
  dft_frac_div->FRAC_DIV_DITHER.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_DITHER_dft;
  dft_frac_div->FRAC_DIV_DS.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_DS_dft;
  dft_frac_div->FRAC_DIV_INT.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_INT_dft;
  dft_frac_div->FRAC_DIV_CC.wrd = TEN_FRAC_DIV_CFG_FRAC_DIV_CC_dft;
  
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
              
    tmp_frac_div->cfg_FRAC_DIV_RESET.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, cfg_FRAC_DIV_RESET));
    tmp_frac_div->FRAC_DIV_ENABLE.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_ENABLE));
    tmp_frac_div->FRAC_DIV_N1.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_N1));
    tmp_frac_div->FRAC_DIV_N0.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_N0));
    tmp_frac_div->FRAC_DIV_WIDTH.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_WIDTH));
    tmp_frac_div->FRAC_DIV_S1EN.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S1EN));
    tmp_frac_div->FRAC_DIV_S2EN.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S2EN));
    tmp_frac_div->FRAC_DIV_S1PL1.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S1PL1));
    tmp_frac_div->FRAC_DIV_S1PL0.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S1PL0));
    tmp_frac_div->FRAC_DIV_DITHER.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_DITHER));
    tmp_frac_div->FRAC_DIV_DS.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_DS));
    tmp_frac_div->FRAC_DIV_INT.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_INT));
    tmp_frac_div->FRAC_DIV_CC.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_CC));

    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "cfg_FRAC_DIV_RESET.wrd", tmp_frac_div->cfg_FRAC_DIV_RESET.wrd, tmp_frac_div->cfg_FRAC_DIV_RESET.wrd == dft_frac_div->cfg_FRAC_DIV_RESET.wrd ? 0x20 : 0x2A, dft_frac_div->cfg_FRAC_DIV_RESET.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "cfg_FRAC_DIV_RESET.bf.value", tmp_frac_div->cfg_FRAC_DIV_RESET.bf.value, tmp_frac_div->cfg_FRAC_DIV_RESET.bf.value == dft_frac_div->cfg_FRAC_DIV_RESET.bf.value ? 0x20 : 0x2A, dft_frac_div->cfg_FRAC_DIV_RESET.bf.value, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_ENABLE.wrd", tmp_frac_div->FRAC_DIV_ENABLE.wrd, tmp_frac_div->FRAC_DIV_ENABLE.wrd == dft_frac_div->FRAC_DIV_ENABLE.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_ENABLE.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_ENABLE.bf.value", tmp_frac_div->FRAC_DIV_ENABLE.bf.value, tmp_frac_div->FRAC_DIV_ENABLE.bf.value == dft_frac_div->FRAC_DIV_ENABLE.bf.value ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_ENABLE.bf.value, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_N1.wrd", tmp_frac_div->FRAC_DIV_N1.wrd, tmp_frac_div->FRAC_DIV_N1.wrd == dft_frac_div->FRAC_DIV_N1.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_N1.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_N1.bf.value1", tmp_frac_div->FRAC_DIV_N1.bf.value1, tmp_frac_div->FRAC_DIV_N1.bf.value1 == dft_frac_div->FRAC_DIV_N1.bf.value1 ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_N1.bf.value1, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_N0.wrd", tmp_frac_div->FRAC_DIV_N0.wrd, tmp_frac_div->FRAC_DIV_N0.wrd == dft_frac_div->FRAC_DIV_N0.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_N0.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_N0.bf.value0", tmp_frac_div->FRAC_DIV_N0.bf.value0, tmp_frac_div->FRAC_DIV_N0.bf.value0 == dft_frac_div->FRAC_DIV_N0.bf.value0 ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_N0.bf.value0, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_WIDTH.wrd", tmp_frac_div->FRAC_DIV_WIDTH.wrd, tmp_frac_div->FRAC_DIV_WIDTH.wrd == dft_frac_div->FRAC_DIV_WIDTH.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_WIDTH.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_WIDTH.bf.value", tmp_frac_div->FRAC_DIV_WIDTH.bf.value, tmp_frac_div->FRAC_DIV_WIDTH.bf.value == dft_frac_div->FRAC_DIV_WIDTH.bf.value ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_WIDTH.bf.value, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_S1EN.wrd", tmp_frac_div->FRAC_DIV_S1EN.wrd, tmp_frac_div->FRAC_DIV_S1EN.wrd == dft_frac_div->FRAC_DIV_S1EN.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S1EN.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_S1EN.bf.value", tmp_frac_div->FRAC_DIV_S1EN.bf.value, tmp_frac_div->FRAC_DIV_S1EN.bf.value == dft_frac_div->FRAC_DIV_S1EN.bf.value ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S1EN.bf.value, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_S2EN.wrd", tmp_frac_div->FRAC_DIV_S2EN.wrd, tmp_frac_div->FRAC_DIV_S2EN.wrd == dft_frac_div->FRAC_DIV_S2EN.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S2EN.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_S2EN.bf.value", tmp_frac_div->FRAC_DIV_S2EN.bf.value, tmp_frac_div->FRAC_DIV_S2EN.bf.value == dft_frac_div->FRAC_DIV_S2EN.bf.value ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S2EN.bf.value, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_S1PL1.wrd", tmp_frac_div->FRAC_DIV_S1PL1.wrd, tmp_frac_div->FRAC_DIV_S1PL1.wrd == dft_frac_div->FRAC_DIV_S1PL1.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S1PL1.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_S1PL1.bf.value1", tmp_frac_div->FRAC_DIV_S1PL1.bf.value1, tmp_frac_div->FRAC_DIV_S1PL1.bf.value1 == dft_frac_div->FRAC_DIV_S1PL1.bf.value1 ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S1PL1.bf.value1, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_S1PL0.wrd", tmp_frac_div->FRAC_DIV_S1PL0.wrd, tmp_frac_div->FRAC_DIV_S1PL0.wrd == dft_frac_div->FRAC_DIV_S1PL0.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S1PL0.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_S1PL0.bf.value0", tmp_frac_div->FRAC_DIV_S1PL0.bf.value0, tmp_frac_div->FRAC_DIV_S1PL0.bf.value0 == dft_frac_div->FRAC_DIV_S1PL0.bf.value0 ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_S1PL0.bf.value0, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_DITHER.wrd", tmp_frac_div->FRAC_DIV_DITHER.wrd, tmp_frac_div->FRAC_DIV_DITHER.wrd == dft_frac_div->FRAC_DIV_DITHER.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_DITHER.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_DITHER.bf.value", tmp_frac_div->FRAC_DIV_DITHER.bf.value, tmp_frac_div->FRAC_DIV_DITHER.bf.value == dft_frac_div->FRAC_DIV_DITHER.bf.value ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_DITHER.bf.value, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_DS.wrd", tmp_frac_div->FRAC_DIV_DS.wrd, tmp_frac_div->FRAC_DIV_DS.wrd == dft_frac_div->FRAC_DIV_DS.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_DS.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_DS.bf.value", tmp_frac_div->FRAC_DIV_DS.bf.value, tmp_frac_div->FRAC_DIV_DS.bf.value == dft_frac_div->FRAC_DIV_DS.bf.value ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_DS.bf.value, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_INT.wrd", tmp_frac_div->FRAC_DIV_INT.wrd, tmp_frac_div->FRAC_DIV_INT.wrd == dft_frac_div->FRAC_DIV_INT.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_INT.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_INT.bf.value", tmp_frac_div->FRAC_DIV_INT.bf.value, tmp_frac_div->FRAC_DIV_INT.bf.value == dft_frac_div->FRAC_DIV_INT.bf.value ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_INT.bf.value, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_CC.wrd", tmp_frac_div->FRAC_DIV_CC.wrd, tmp_frac_div->FRAC_DIV_CC.wrd == dft_frac_div->FRAC_DIV_CC.wrd ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_CC.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "FRAC_DIV_CC.bf.value", tmp_frac_div->FRAC_DIV_CC.bf.value, tmp_frac_div->FRAC_DIV_CC.bf.value == dft_frac_div->FRAC_DIV_CC.bf.value ? 0x20 : 0x2A, dft_frac_div->FRAC_DIV_CC.bf.value, ii);
  }
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  CS_FREE(tmp_frac_div);
  CS_FREE(dft_frac_div);
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 DUMP SETTINGS                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_gpllx1_dump_settings(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current GPLLX1 settings.                                */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  TEN_gpllx1_sds_t *tmp_gpllx, *dft_gpllx;
  cs_uint16 ii;
  T41_t *pDev = NULL;
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  tmp_gpllx = (TEN_gpllx1_sds_t *)CS_MALLOC(sizeof(TEN_gpllx1_sds_t));
  dft_gpllx = (TEN_gpllx1_sds_t *)CS_MALLOC(sizeof(TEN_gpllx1_sds_t));

  /* Bug #42300 - fix klocwork warnings */
  if ((!tmp_gpllx) || (!dft_gpllx)) {
     CS_PRINT_OUTPUT("Out of memory.\n");
     if (tmp_gpllx) {
       CS_FREE(tmp_gpllx);
     }
     if (dft_gpllx) {
       CS_FREE(dft_gpllx);
     }
     return (CS_ERROR);
  }
  
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
 
  dft_gpllx->STXP0_TX_CONFIG.wrd = TEN_GPLLX1_SDS_COMMON_STXP0_TX_CONFIG_dft;
  dft_gpllx->STXP0_TX_PWRDN.wrd = TEN_GPLLX1_SDS_COMMON_STXP0_TX_PWRDN_dft;
  dft_gpllx->STXP0_TX_CLKDIV_CTRL.wrd = TEN_GPLLX1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_dft;
  dft_gpllx->STXP0_TX_CLKOUT_CTRL.wrd = TEN_GPLLX1_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_dft;
  dft_gpllx->STXP0_TX_LOOP_FILTER.wrd = TEN_GPLLX1_SDS_COMMON_STXP0_TX_LOOP_FILTER_dft;
  dft_gpllx->STXP0_TX_CP.wrd = TEN_GPLLX1_SDS_COMMON_STXP0_TX_CP_dft;
  dft_gpllx->STXP0_TX_VCO_FILT.wrd = TEN_GPLLX1_SDS_COMMON_STXP0_TX_VCO_FILT_dft;
  dft_gpllx->STXP0_TX_VCO_CTRL.wrd = TEN_GPLLX1_SDS_COMMON_STXP0_TX_VCO_CTRL_dft;
  dft_gpllx->STXP0_TX_SPARE.wrd = TEN_GPLLX1_SDS_COMMON_STXP0_TX_SPARE_dft;
  dft_gpllx->TXVCO0_THRES0.wrd = TEN_GPLLX1_SDS_COMMON_TXVCO0_THRES0_dft;
  dft_gpllx->TXVCO0_THRES1.wrd = TEN_GPLLX1_SDS_COMMON_TXVCO0_THRES1_dft;
  dft_gpllx->TXVCO0_VCOMAX.wrd = TEN_GPLLX1_SDS_COMMON_TXVCO0_VCOMAX_dft;
  dft_gpllx->TXVCO0_CONTROL.wrd = TEN_GPLLX1_SDS_COMMON_TXVCO0_CONTROL_dft;
  dft_gpllx->TXVCO0_STATUS.wrd = TEN_GPLLX1_SDS_COMMON_TXVCO0_STATUS_dft;
  dft_gpllx->TXVCO0_INTERRUPT.wrd = TEN_GPLLX1_SDS_COMMON_TXVCO0_INTERRUPT_dft;
  dft_gpllx->TXVCO0_INTSTATUS.wrd = TEN_GPLLX1_SDS_COMMON_TXVCO0_INTSTATUS_dft;
  dft_gpllx->TXVCO0_INTENABLE.wrd = TEN_GPLLX1_SDS_COMMON_TXVCO0_INTENABLE_dft;
  dft_gpllx->TXVCO0_INTERRUPTZ.wrd = TEN_GPLLX1_SDS_COMMON_TXVCO0_INTERRUPTZ_dft;
  dft_gpllx->TXLOCKD0_FILTER.wrd = TEN_GPLLX1_SDS_COMMON_TXLOCKD0_FILTER_dft;
  dft_gpllx->TXLOCKD0_CONTROL.wrd = TEN_GPLLX1_SDS_COMMON_TXLOCKD0_CONTROL_dft;
  dft_gpllx->TXLOCKD0_INTERRUPT.wrd = TEN_GPLLX1_SDS_COMMON_TXLOCKD0_INTERRUPT_dft;
  dft_gpllx->TXLOCKD0_INTSTATUS.wrd = TEN_GPLLX1_SDS_COMMON_TXLOCKD0_INTSTATUS_dft;
  dft_gpllx->TXLOCKD0_INTENABLE.wrd = TEN_GPLLX1_SDS_COMMON_TXLOCKD0_INTENABLE_dft;
  dft_gpllx->TXLOCKD0_INTERRUPTZ.wrd = TEN_GPLLX1_SDS_COMMON_TXLOCKD0_INTERRUPTZ_dft;
  dft_gpllx->TXVCOLEVEL0_OSTATUS.wrd = TEN_GPLLX1_SDS_COMMON_TXVCOLEVEL0_OSTATUS_dft;
  dft_gpllx->TXVCOLEVEL0_CSTATUS.wrd = TEN_GPLLX1_SDS_COMMON_TXVCOLEVEL0_CSTATUS_dft;
  dft_gpllx->Int.wrd = TEN_GPLLX1_SDS_COMMON_Int_dft;
  dft_gpllx->IntEn.wrd = TEN_GPLLX1_SDS_COMMON_IntEn_dft;
  dft_gpllx->TXVCOi.wrd = TEN_GPLLX1_SDS_COMMON_TXVCOi_dft;
  dft_gpllx->TXVCOe.wrd = TEN_GPLLX1_SDS_COMMON_TXVCOe_dft;
  dft_gpllx->TXLOCKDi.wrd = TEN_GPLLX1_SDS_COMMON_TXLOCKDi_dft;
  dft_gpllx->TXLOCKDe.wrd = TEN_GPLLX1_SDS_COMMON_TXLOCKDe_dft;
     
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    tmp_gpllx->STXP0_TX_CONFIG.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CONFIG, ii));
    tmp_gpllx->STXP0_TX_PWRDN.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_PWRDN, ii));
    tmp_gpllx->STXP0_TX_CLKDIV_CTRL.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKDIV_CTRL, ii));
    tmp_gpllx->STXP0_TX_CLKOUT_CTRL.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKOUT_CTRL, ii));
    tmp_gpllx->STXP0_TX_LOOP_FILTER.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_LOOP_FILTER, ii));
    tmp_gpllx->STXP0_TX_CP.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CP, ii));
    tmp_gpllx->STXP0_TX_VCO_FILT.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_VCO_FILT, ii));
    tmp_gpllx->STXP0_TX_VCO_CTRL.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_VCO_CTRL, ii));
    tmp_gpllx->STXP0_TX_SPARE.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_SPARE, ii));
    tmp_gpllx->TXVCO0_THRES0.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_THRES0, ii));
    tmp_gpllx->TXVCO0_THRES1.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_THRES1, ii));
    tmp_gpllx->TXVCO0_VCOMAX.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_VCOMAX, ii));
    tmp_gpllx->TXVCO0_CONTROL.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_CONTROL, ii));
    tmp_gpllx->TXVCO0_STATUS.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_STATUS, ii));
    tmp_gpllx->TXVCO0_INTERRUPT.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_INTERRUPT, ii));
    tmp_gpllx->TXVCO0_INTSTATUS.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_INTSTATUS, ii));
    tmp_gpllx->TXVCO0_INTENABLE.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_INTENABLE, ii));
    tmp_gpllx->TXVCO0_INTERRUPTZ.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_INTERRUPTZ, ii));
    tmp_gpllx->TXLOCKD0_FILTER.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKD0_FILTER, ii));
    tmp_gpllx->TXLOCKD0_CONTROL.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKD0_CONTROL, ii));
    tmp_gpllx->TXLOCKD0_INTERRUPT.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKD0_INTERRUPT, ii));
    tmp_gpllx->TXLOCKD0_INTSTATUS.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKD0_INTSTATUS, ii));
    tmp_gpllx->TXLOCKD0_INTENABLE.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKD0_INTENABLE, ii));
    tmp_gpllx->TXLOCKD0_INTERRUPTZ.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKD0_INTERRUPTZ, ii));
    tmp_gpllx->TXVCOLEVEL0_OSTATUS.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCOLEVEL0_OSTATUS, ii));
    tmp_gpllx->TXVCOLEVEL0_CSTATUS.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCOLEVEL0_CSTATUS, ii));
    tmp_gpllx->Int.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, Int, ii));
    tmp_gpllx->IntEn.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, IntEn, ii));
    tmp_gpllx->TXVCOi.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCOi, ii));
    tmp_gpllx->TXVCOe.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCOe, ii));
    tmp_gpllx->TXLOCKDi.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKDi, ii));
    tmp_gpllx->TXLOCKDe.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKDe, ii));
    
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CONFIG.wrd", tmp_gpllx->STXP0_TX_CONFIG.wrd, tmp_gpllx->STXP0_TX_CONFIG.wrd == dft_gpllx->STXP0_TX_CONFIG.wrd ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CONFIG.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL", tmp_gpllx->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL, tmp_gpllx->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL == dft_gpllx->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CONFIG.bf.STXP_LPTIME_SEL, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CONFIG.bf.STXP_PILOT_SEL", tmp_gpllx->STXP0_TX_CONFIG.bf.STXP_PILOT_SEL, tmp_gpllx->STXP0_TX_CONFIG.bf.STXP_PILOT_SEL == dft_gpllx->STXP0_TX_CONFIG.bf.STXP_PILOT_SEL ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CONFIG.bf.STXP_PILOT_SEL, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CONFIG.bf.STXP_BUSWIDTH", tmp_gpllx->STXP0_TX_CONFIG.bf.STXP_BUSWIDTH, tmp_gpllx->STXP0_TX_CONFIG.bf.STXP_BUSWIDTH == dft_gpllx->STXP0_TX_CONFIG.bf.STXP_BUSWIDTH ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CONFIG.bf.STXP_BUSWIDTH, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CONFIG.bf.STXP_LPBKEN", tmp_gpllx->STXP0_TX_CONFIG.bf.STXP_LPBKEN, tmp_gpllx->STXP0_TX_CONFIG.bf.STXP_LPBKEN == dft_gpllx->STXP0_TX_CONFIG.bf.STXP_LPBKEN ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CONFIG.bf.STXP_LPBKEN, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_PWRDN.wrd", tmp_gpllx->STXP0_TX_PWRDN.wrd, tmp_gpllx->STXP0_TX_PWRDN.wrd == dft_gpllx->STXP0_TX_PWRDN.wrd ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_PWRDN.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_PWRDN.bf.STXP_PD", tmp_gpllx->STXP0_TX_PWRDN.bf.STXP_PD, tmp_gpllx->STXP0_TX_PWRDN.bf.STXP_PD == dft_gpllx->STXP0_TX_PWRDN.bf.STXP_PD ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_PWRDN.bf.STXP_PD, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_PWRDN.bf.STXP_PD_LANE", tmp_gpllx->STXP0_TX_PWRDN.bf.STXP_PD_LANE, tmp_gpllx->STXP0_TX_PWRDN.bf.STXP_PD_LANE == dft_gpllx->STXP0_TX_PWRDN.bf.STXP_PD_LANE ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_PWRDN.bf.STXP_PD_LANE, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CLKDIV_CTRL.wrd", tmp_gpllx->STXP0_TX_CLKDIV_CTRL.wrd, tmp_gpllx->STXP0_TX_CLKDIV_CTRL.wrd == dft_gpllx->STXP0_TX_CLKDIV_CTRL.wrd ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CLKDIV_CTRL.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CLKDIV_CTRL.bf.STXP_FASTDIV_SEL", tmp_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_FASTDIV_SEL, tmp_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_FASTDIV_SEL == dft_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_FASTDIV_SEL ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_FASTDIV_SEL, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CLKDIV_CTRL.bf.STXP_CTRDIV_SEL", tmp_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTRDIV_SEL, tmp_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTRDIV_SEL == dft_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTRDIV_SEL ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTRDIV_SEL, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CLKDIV_CTRL.bf.STXP_CTVDIV_SEL", tmp_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTVDIV_SEL, tmp_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTVDIV_SEL == dft_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTVDIV_SEL ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_CTVDIV_SEL, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CLKDIV_CTRL.bf.STXP_DDIV_SEL", tmp_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_DDIV_SEL, tmp_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_DDIV_SEL == dft_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_DDIV_SEL ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_DDIV_SEL, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CLKDIV_CTRL.bf.STXP_RDIV_SEL", tmp_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_RDIV_SEL, tmp_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_RDIV_SEL == dft_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_RDIV_SEL ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CLKDIV_CTRL.bf.STXP_RDIV_SEL, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CLKOUT_CTRL.wrd", tmp_gpllx->STXP0_TX_CLKOUT_CTRL.wrd, tmp_gpllx->STXP0_TX_CLKOUT_CTRL.wrd == dft_gpllx->STXP0_TX_CLKOUT_CTRL.wrd ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CLKOUT_CTRL.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKIEN", tmp_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKIEN, tmp_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKIEN == dft_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKIEN ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKIEN, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CLKOUT_CTRL.bf.STXP_CLKOUTEN", tmp_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_CLKOUTEN, tmp_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_CLKOUTEN == dft_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_CLKOUTEN ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_CLKOUTEN, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKO_SEL", tmp_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKO_SEL, tmp_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKO_SEL == dft_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKO_SEL ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CLKOUT_CTRL.bf.STXP_TCLKO_SEL, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_LOOP_FILTER.wrd", tmp_gpllx->STXP0_TX_LOOP_FILTER.wrd, tmp_gpllx->STXP0_TX_LOOP_FILTER.wrd == dft_gpllx->STXP0_TX_LOOP_FILTER.wrd ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_LOOP_FILTER.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_LOOP_FILTER.bf.STXP_FILTR", tmp_gpllx->STXP0_TX_LOOP_FILTER.bf.STXP_FILTR, tmp_gpllx->STXP0_TX_LOOP_FILTER.bf.STXP_FILTR == dft_gpllx->STXP0_TX_LOOP_FILTER.bf.STXP_FILTR ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_LOOP_FILTER.bf.STXP_FILTR, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CP.wrd", tmp_gpllx->STXP0_TX_CP.wrd, tmp_gpllx->STXP0_TX_CP.wrd == dft_gpllx->STXP0_TX_CP.wrd ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CP.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CP.bf.STXP_CPTSTDN", tmp_gpllx->STXP0_TX_CP.bf.STXP_CPTSTDN, tmp_gpllx->STXP0_TX_CP.bf.STXP_CPTSTDN == dft_gpllx->STXP0_TX_CP.bf.STXP_CPTSTDN ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CP.bf.STXP_CPTSTDN, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CP.bf.STXP_CPCUR1", tmp_gpllx->STXP0_TX_CP.bf.STXP_CPCUR1, tmp_gpllx->STXP0_TX_CP.bf.STXP_CPCUR1 == dft_gpllx->STXP0_TX_CP.bf.STXP_CPCUR1 ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CP.bf.STXP_CPCUR1, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_CP.bf.STXP_CPCUR0", tmp_gpllx->STXP0_TX_CP.bf.STXP_CPCUR0, tmp_gpllx->STXP0_TX_CP.bf.STXP_CPCUR0 == dft_gpllx->STXP0_TX_CP.bf.STXP_CPCUR0 ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_CP.bf.STXP_CPCUR0, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_SPARE.wrd", tmp_gpllx->STXP0_TX_SPARE.wrd, tmp_gpllx->STXP0_TX_SPARE.wrd == dft_gpllx->STXP0_TX_SPARE.wrd ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_SPARE.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_STXP0_TX_SPARE.bf.STXP_SPARE", tmp_gpllx->STXP0_TX_SPARE.bf.STXP_SPARE, tmp_gpllx->STXP0_TX_SPARE.bf.STXP_SPARE == dft_gpllx->STXP0_TX_SPARE.bf.STXP_SPARE ? 0x20 : 0x2A, dft_gpllx->STXP0_TX_SPARE.bf.STXP_SPARE, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_THRES0.wrd", tmp_gpllx->TXVCO0_THRES0.wrd, tmp_gpllx->TXVCO0_THRES0.wrd == dft_gpllx->TXVCO0_THRES0.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCO0_THRES0.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_THRES0.bf.FREQ_THRES_SIGN0", tmp_gpllx->TXVCO0_THRES0.bf.FREQ_THRES_SIGN0, tmp_gpllx->TXVCO0_THRES0.bf.FREQ_THRES_SIGN0 == dft_gpllx->TXVCO0_THRES0.bf.FREQ_THRES_SIGN0 ? 0x20 : 0x2A, dft_gpllx->TXVCO0_THRES0.bf.FREQ_THRES_SIGN0, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_THRES0.bf.FREQ_THRES0", tmp_gpllx->TXVCO0_THRES0.bf.FREQ_THRES0, tmp_gpllx->TXVCO0_THRES0.bf.FREQ_THRES0 == dft_gpllx->TXVCO0_THRES0.bf.FREQ_THRES0 ? 0x20 : 0x2A, dft_gpllx->TXVCO0_THRES0.bf.FREQ_THRES0, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_THRES1.wrd", tmp_gpllx->TXVCO0_THRES1.wrd, tmp_gpllx->TXVCO0_THRES1.wrd == dft_gpllx->TXVCO0_THRES1.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCO0_THRES1.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_THRES1.bf.FREQ_THRES_SIGN1", tmp_gpllx->TXVCO0_THRES1.bf.FREQ_THRES_SIGN1, tmp_gpllx->TXVCO0_THRES1.bf.FREQ_THRES_SIGN1 == dft_gpllx->TXVCO0_THRES1.bf.FREQ_THRES_SIGN1 ? 0x20 : 0x2A, dft_gpllx->TXVCO0_THRES1.bf.FREQ_THRES_SIGN1, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_THRES1.bf.FREQ_THRES1", tmp_gpllx->TXVCO0_THRES1.bf.FREQ_THRES1, tmp_gpllx->TXVCO0_THRES1.bf.FREQ_THRES1 == dft_gpllx->TXVCO0_THRES1.bf.FREQ_THRES1 ? 0x20 : 0x2A, dft_gpllx->TXVCO0_THRES1.bf.FREQ_THRES1, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_VCOMAX.wrd", tmp_gpllx->TXVCO0_VCOMAX.wrd, tmp_gpllx->TXVCO0_VCOMAX.wrd == dft_gpllx->TXVCO0_VCOMAX.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCO0_VCOMAX.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_VCOMAX.bf.VCOMAX", tmp_gpllx->TXVCO0_VCOMAX.bf.VCOMAX, tmp_gpllx->TXVCO0_VCOMAX.bf.VCOMAX == dft_gpllx->TXVCO0_VCOMAX.bf.VCOMAX ? 0x20 : 0x2A, dft_gpllx->TXVCO0_VCOMAX.bf.VCOMAX, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_CONTROL.wrd", tmp_gpllx->TXVCO0_CONTROL.wrd, tmp_gpllx->TXVCO0_CONTROL.wrd == dft_gpllx->TXVCO0_CONTROL.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCO0_CONTROL.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_CONTROL.bf.INIT", tmp_gpllx->TXVCO0_CONTROL.bf.INIT, tmp_gpllx->TXVCO0_CONTROL.bf.INIT == dft_gpllx->TXVCO0_CONTROL.bf.INIT ? 0x20 : 0x2A, dft_gpllx->TXVCO0_CONTROL.bf.INIT, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_CONTROL.bf.SHORT_OVRIDE", tmp_gpllx->TXVCO0_CONTROL.bf.SHORT_OVRIDE, tmp_gpllx->TXVCO0_CONTROL.bf.SHORT_OVRIDE == dft_gpllx->TXVCO0_CONTROL.bf.SHORT_OVRIDE ? 0x20 : 0x2A, dft_gpllx->TXVCO0_CONTROL.bf.SHORT_OVRIDE, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_STATUS.wrd", tmp_gpllx->TXVCO0_STATUS.wrd, tmp_gpllx->TXVCO0_STATUS.wrd == dft_gpllx->TXVCO0_STATUS.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCO0_STATUS.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_STATUS.bf.FREQ", tmp_gpllx->TXVCO0_STATUS.bf.FREQ, tmp_gpllx->TXVCO0_STATUS.bf.FREQ == dft_gpllx->TXVCO0_STATUS.bf.FREQ ? 0x20 : 0x2A, dft_gpllx->TXVCO0_STATUS.bf.FREQ, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_INTERRUPT.wrd", tmp_gpllx->TXVCO0_INTERRUPT.wrd, tmp_gpllx->TXVCO0_INTERRUPT.wrd == dft_gpllx->TXVCO0_INTERRUPT.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCO0_INTERRUPT.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_INTERRUPT.bf.SHORT_FILTPNi", tmp_gpllx->TXVCO0_INTERRUPT.bf.SHORT_FILTPNi, tmp_gpllx->TXVCO0_INTERRUPT.bf.SHORT_FILTPNi == dft_gpllx->TXVCO0_INTERRUPT.bf.SHORT_FILTPNi ? 0x20 : 0x2A, dft_gpllx->TXVCO0_INTERRUPT.bf.SHORT_FILTPNi, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_INTSTATUS.wrd", tmp_gpllx->TXVCO0_INTSTATUS.wrd, tmp_gpllx->TXVCO0_INTSTATUS.wrd == dft_gpllx->TXVCO0_INTSTATUS.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCO0_INTSTATUS.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_INTSTATUS.bf.SHORT_FILTPNs", tmp_gpllx->TXVCO0_INTSTATUS.bf.SHORT_FILTPNs, tmp_gpllx->TXVCO0_INTSTATUS.bf.SHORT_FILTPNs == dft_gpllx->TXVCO0_INTSTATUS.bf.SHORT_FILTPNs ? 0x20 : 0x2A, dft_gpllx->TXVCO0_INTSTATUS.bf.SHORT_FILTPNs, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_INTENABLE.wrd", tmp_gpllx->TXVCO0_INTENABLE.wrd, tmp_gpllx->TXVCO0_INTENABLE.wrd == dft_gpllx->TXVCO0_INTENABLE.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCO0_INTENABLE.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_INTENABLE.bf.SHORT_FILTPNe", tmp_gpllx->TXVCO0_INTENABLE.bf.SHORT_FILTPNe, tmp_gpllx->TXVCO0_INTENABLE.bf.SHORT_FILTPNe == dft_gpllx->TXVCO0_INTENABLE.bf.SHORT_FILTPNe ? 0x20 : 0x2A, dft_gpllx->TXVCO0_INTENABLE.bf.SHORT_FILTPNe, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_INTERRUPTZ.wrd", tmp_gpllx->TXVCO0_INTERRUPTZ.wrd, tmp_gpllx->TXVCO0_INTERRUPTZ.wrd == dft_gpllx->TXVCO0_INTERRUPTZ.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCO0_INTERRUPTZ.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ", tmp_gpllx->TXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ, tmp_gpllx->TXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ == dft_gpllx->TXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ ? 0x20 : 0x2A, dft_gpllx->TXVCO0_INTERRUPTZ.bf.SHORT_FILTPNiZ, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_FILTER.wrd", tmp_gpllx->TXLOCKD0_FILTER.wrd, tmp_gpllx->TXLOCKD0_FILTER.wrd == dft_gpllx->TXLOCKD0_FILTER.wrd ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_FILTER.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_FILTER.bf.STABLE_PERIOD", tmp_gpllx->TXLOCKD0_FILTER.bf.STABLE_PERIOD, tmp_gpllx->TXLOCKD0_FILTER.bf.STABLE_PERIOD == dft_gpllx->TXLOCKD0_FILTER.bf.STABLE_PERIOD ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_FILTER.bf.STABLE_PERIOD, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_CONTROL.wrd", tmp_gpllx->TXLOCKD0_CONTROL.wrd, tmp_gpllx->TXLOCKD0_CONTROL.wrd == dft_gpllx->TXLOCKD0_CONTROL.wrd ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_CONTROL.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_CONTROL.bf.PD_MODE", tmp_gpllx->TXLOCKD0_CONTROL.bf.PD_MODE, tmp_gpllx->TXLOCKD0_CONTROL.bf.PD_MODE == dft_gpllx->TXLOCKD0_CONTROL.bf.PD_MODE ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_CONTROL.bf.PD_MODE, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_CONTROL.bf.FORCE_LOCK", tmp_gpllx->TXLOCKD0_CONTROL.bf.FORCE_LOCK, tmp_gpllx->TXLOCKD0_CONTROL.bf.FORCE_LOCK == dft_gpllx->TXLOCKD0_CONTROL.bf.FORCE_LOCK ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_CONTROL.bf.FORCE_LOCK, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPT.wrd", tmp_gpllx->TXLOCKD0_INTERRUPT.wrd, tmp_gpllx->TXLOCKD0_INTERRUPT.wrd == dft_gpllx->TXLOCKD0_INTERRUPT.wrd ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPT.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPT.bf.FILT_LOCKi", tmp_gpllx->TXLOCKD0_INTERRUPT.bf.FILT_LOCKi, tmp_gpllx->TXLOCKD0_INTERRUPT.bf.FILT_LOCKi == dft_gpllx->TXLOCKD0_INTERRUPT.bf.FILT_LOCKi ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPT.bf.FILT_LOCKi, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPT.bf.CIDONEi", tmp_gpllx->TXLOCKD0_INTERRUPT.bf.CIDONEi, tmp_gpllx->TXLOCKD0_INTERRUPT.bf.CIDONEi == dft_gpllx->TXLOCKD0_INTERRUPT.bf.CIDONEi ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPT.bf.CIDONEi, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPT.bf.CIDZEROi", tmp_gpllx->TXLOCKD0_INTERRUPT.bf.CIDZEROi, tmp_gpllx->TXLOCKD0_INTERRUPT.bf.CIDZEROi == dft_gpllx->TXLOCKD0_INTERRUPT.bf.CIDZEROi ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPT.bf.CIDZEROi, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPT.bf.DATA_DETi", tmp_gpllx->TXLOCKD0_INTERRUPT.bf.DATA_DETi, tmp_gpllx->TXLOCKD0_INTERRUPT.bf.DATA_DETi == dft_gpllx->TXLOCKD0_INTERRUPT.bf.DATA_DETi ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPT.bf.DATA_DETi, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi", tmp_gpllx->TXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi, tmp_gpllx->TXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi == dft_gpllx->TXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPT.bf.SHORT_FILTPNi, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi", tmp_gpllx->TXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi, tmp_gpllx->TXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi == dft_gpllx->TXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPT.bf.BAD_VCO_CLKi, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPT.bf.LOCKi", tmp_gpllx->TXLOCKD0_INTERRUPT.bf.LOCKi, tmp_gpllx->TXLOCKD0_INTERRUPT.bf.LOCKi == dft_gpllx->TXLOCKD0_INTERRUPT.bf.LOCKi ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPT.bf.LOCKi, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTSTATUS.wrd", tmp_gpllx->TXLOCKD0_INTSTATUS.wrd, tmp_gpllx->TXLOCKD0_INTSTATUS.wrd == dft_gpllx->TXLOCKD0_INTSTATUS.wrd ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTSTATUS.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTSTATUS.bf.FILT_LOCKs", tmp_gpllx->TXLOCKD0_INTSTATUS.bf.FILT_LOCKs, tmp_gpllx->TXLOCKD0_INTSTATUS.bf.FILT_LOCKs == dft_gpllx->TXLOCKD0_INTSTATUS.bf.FILT_LOCKs ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTSTATUS.bf.FILT_LOCKs, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTSTATUS.bf.CIDONEs", tmp_gpllx->TXLOCKD0_INTSTATUS.bf.CIDONEs, tmp_gpllx->TXLOCKD0_INTSTATUS.bf.CIDONEs == dft_gpllx->TXLOCKD0_INTSTATUS.bf.CIDONEs ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTSTATUS.bf.CIDONEs, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTSTATUS.bf.CIDZEROs", tmp_gpllx->TXLOCKD0_INTSTATUS.bf.CIDZEROs, tmp_gpllx->TXLOCKD0_INTSTATUS.bf.CIDZEROs == dft_gpllx->TXLOCKD0_INTSTATUS.bf.CIDZEROs ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTSTATUS.bf.CIDZEROs, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTSTATUS.bf.DATA_DETs", tmp_gpllx->TXLOCKD0_INTSTATUS.bf.DATA_DETs, tmp_gpllx->TXLOCKD0_INTSTATUS.bf.DATA_DETs == dft_gpllx->TXLOCKD0_INTSTATUS.bf.DATA_DETs ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTSTATUS.bf.DATA_DETs, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs", tmp_gpllx->TXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs, tmp_gpllx->TXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs == dft_gpllx->TXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTSTATUS.bf.SHORT_FILTPNs, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs", tmp_gpllx->TXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs, tmp_gpllx->TXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs == dft_gpllx->TXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTSTATUS.bf.BAD_VCO_CLKs, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTSTATUS.bf.LOCKs", tmp_gpllx->TXLOCKD0_INTSTATUS.bf.LOCKs, tmp_gpllx->TXLOCKD0_INTSTATUS.bf.LOCKs == dft_gpllx->TXLOCKD0_INTSTATUS.bf.LOCKs ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTSTATUS.bf.LOCKs, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTENABLE.wrd", tmp_gpllx->TXLOCKD0_INTENABLE.wrd, tmp_gpllx->TXLOCKD0_INTENABLE.wrd == dft_gpllx->TXLOCKD0_INTENABLE.wrd ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTENABLE.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTENABLE.bf.FILT_LOCKe", tmp_gpllx->TXLOCKD0_INTENABLE.bf.FILT_LOCKe, tmp_gpllx->TXLOCKD0_INTENABLE.bf.FILT_LOCKe == dft_gpllx->TXLOCKD0_INTENABLE.bf.FILT_LOCKe ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTENABLE.bf.FILT_LOCKe, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTENABLE.bf.CIDONEe", tmp_gpllx->TXLOCKD0_INTENABLE.bf.CIDONEe, tmp_gpllx->TXLOCKD0_INTENABLE.bf.CIDONEe == dft_gpllx->TXLOCKD0_INTENABLE.bf.CIDONEe ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTENABLE.bf.CIDONEe, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTENABLE.bf.CIDZEROe", tmp_gpllx->TXLOCKD0_INTENABLE.bf.CIDZEROe, tmp_gpllx->TXLOCKD0_INTENABLE.bf.CIDZEROe == dft_gpllx->TXLOCKD0_INTENABLE.bf.CIDZEROe ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTENABLE.bf.CIDZEROe, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTENABLE.bf.DATA_DETe", tmp_gpllx->TXLOCKD0_INTENABLE.bf.DATA_DETe, tmp_gpllx->TXLOCKD0_INTENABLE.bf.DATA_DETe == dft_gpllx->TXLOCKD0_INTENABLE.bf.DATA_DETe ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTENABLE.bf.DATA_DETe, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTENABLE.bf.SHORT_FILTPNe", tmp_gpllx->TXLOCKD0_INTENABLE.bf.SHORT_FILTPNe, tmp_gpllx->TXLOCKD0_INTENABLE.bf.SHORT_FILTPNe == dft_gpllx->TXLOCKD0_INTENABLE.bf.SHORT_FILTPNe ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTENABLE.bf.SHORT_FILTPNe, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe", tmp_gpllx->TXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe, tmp_gpllx->TXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe == dft_gpllx->TXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTENABLE.bf.BAD_VCO_CLKe, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTENABLE.bf.LOCKe", tmp_gpllx->TXLOCKD0_INTENABLE.bf.LOCKe, tmp_gpllx->TXLOCKD0_INTENABLE.bf.LOCKe == dft_gpllx->TXLOCKD0_INTENABLE.bf.LOCKe ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTENABLE.bf.LOCKe, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPTZ.wrd", tmp_gpllx->TXLOCKD0_INTERRUPTZ.wrd, tmp_gpllx->TXLOCKD0_INTERRUPTZ.wrd == dft_gpllx->TXLOCKD0_INTERRUPTZ.wrd ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPTZ.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ", tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ, tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ == dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.FILT_LOCKiZ, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPTZ.bf.CIDONEiZ", tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.CIDONEiZ, tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.CIDONEiZ == dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.CIDONEiZ ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.CIDONEiZ, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPTZ.bf.CIDZEROiZ", tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.CIDZEROiZ, tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.CIDZEROiZ == dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.CIDZEROiZ ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.CIDZEROiZ, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ", tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ, tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ == dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.DATA_DETiZ, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ", tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ, tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ == dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.SHORT_FILTPNiZ, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ", tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ, tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ == dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.BAD_VCO_CLKiZ, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKD0_INTERRUPTZ.bf.LOCKiZ", tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.LOCKiZ, tmp_gpllx->TXLOCKD0_INTERRUPTZ.bf.LOCKiZ == dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.LOCKiZ ? 0x20 : 0x2A, dft_gpllx->TXLOCKD0_INTERRUPTZ.bf.LOCKiZ, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCOLEVEL0_OSTATUS.wrd", tmp_gpllx->TXVCOLEVEL0_OSTATUS.wrd, tmp_gpllx->TXVCOLEVEL0_OSTATUS.wrd == dft_gpllx->TXVCOLEVEL0_OSTATUS.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCOLEVEL0_OSTATUS.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS", tmp_gpllx->TXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS, tmp_gpllx->TXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS == dft_gpllx->TXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS ? 0x20 : 0x2A, dft_gpllx->TXVCOLEVEL0_OSTATUS.bf.VCO_LEVEL_STATUS, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCOLEVEL0_CSTATUS.wrd", tmp_gpllx->TXVCOLEVEL0_CSTATUS.wrd, tmp_gpllx->TXVCOLEVEL0_CSTATUS.wrd == dft_gpllx->TXVCOLEVEL0_CSTATUS.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCOLEVEL0_CSTATUS.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS", tmp_gpllx->TXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS, tmp_gpllx->TXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS == dft_gpllx->TXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS ? 0x20 : 0x2A, dft_gpllx->TXVCOLEVEL0_CSTATUS.bf.VCO_COMP_OUT_STATUS, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_INT.wrd", tmp_gpllx->Int.wrd, tmp_gpllx->Int.wrd == dft_gpllx->Int.wrd ? 0x20 : 0x2A, dft_gpllx->Int.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_INT.bf.TXLOCKDi", tmp_gpllx->Int.bf.TXLOCKDi, tmp_gpllx->Int.bf.TXLOCKDi == dft_gpllx->Int.bf.TXLOCKDi ? 0x20 : 0x2A, dft_gpllx->Int.bf.TXLOCKDi, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_INT.bf.TXVCOi", tmp_gpllx->Int.bf.TXVCOi, tmp_gpllx->Int.bf.TXVCOi == dft_gpllx->Int.bf.TXVCOi ? 0x20 : 0x2A, dft_gpllx->Int.bf.TXVCOi, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_INTEN.wrd", tmp_gpllx->IntEn.wrd, tmp_gpllx->IntEn.wrd == dft_gpllx->IntEn.wrd ? 0x20 : 0x2A, dft_gpllx->IntEn.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_INTEN.bf.TXLOCKDe", tmp_gpllx->IntEn.bf.TXLOCKDe, tmp_gpllx->IntEn.bf.TXLOCKDe == dft_gpllx->IntEn.bf.TXLOCKDe ? 0x20 : 0x2A, dft_gpllx->IntEn.bf.TXLOCKDe, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_INTEN.bf.TXVCOe", tmp_gpllx->IntEn.bf.TXVCOe, tmp_gpllx->IntEn.bf.TXVCOe == dft_gpllx->IntEn.bf.TXVCOe ? 0x20 : 0x2A, dft_gpllx->IntEn.bf.TXVCOe, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCOI.wrd", tmp_gpllx->TXVCOi.wrd, tmp_gpllx->TXVCOi.wrd == dft_gpllx->TXVCOi.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCOi.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCOI.bf.TXVCO0i", tmp_gpllx->TXVCOi.bf.TXVCO0i, tmp_gpllx->TXVCOi.bf.TXVCO0i == dft_gpllx->TXVCOi.bf.TXVCO0i ? 0x20 : 0x2A, dft_gpllx->TXVCOi.bf.TXVCO0i, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCOE.wrd", tmp_gpllx->TXVCOe.wrd, tmp_gpllx->TXVCOe.wrd == dft_gpllx->TXVCOe.wrd ? 0x20 : 0x2A, dft_gpllx->TXVCOe.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXVCOE.bf.TXVCO0e", tmp_gpllx->TXVCOe.bf.TXVCO0e, tmp_gpllx->TXVCOe.bf.TXVCO0e == dft_gpllx->TXVCOe.bf.TXVCO0e ? 0x20 : 0x2A, dft_gpllx->TXVCOe.bf.TXVCO0e, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKDI.wrd", tmp_gpllx->TXLOCKDi.wrd, tmp_gpllx->TXLOCKDi.wrd == dft_gpllx->TXLOCKDi.wrd ? 0x20 : 0x2A, dft_gpllx->TXLOCKDi.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKDI.bf.TXLOCKD0i", tmp_gpllx->TXLOCKDi.bf.TXLOCKD0i, tmp_gpllx->TXLOCKDi.bf.TXLOCKD0i == dft_gpllx->TXLOCKDi.bf.TXLOCKD0i ? 0x20 : 0x2A, dft_gpllx->TXLOCKDi.bf.TXLOCKD0i, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKDE.wrd", tmp_gpllx->TXLOCKDe.wrd, tmp_gpllx->TXLOCKDe.wrd == dft_gpllx->TXLOCKDe.wrd ? 0x20 : 0x2A, dft_gpllx->TXLOCKDe.wrd, ii);
    CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X   I%d\n", "GPLLX1_TXLOCKDE.bf.TXLOCKD0e", tmp_gpllx->TXLOCKDe.bf.TXLOCKD0e, tmp_gpllx->TXLOCKDe.bf.TXLOCKD0e == dft_gpllx->TXLOCKDe.bf.TXLOCKD0e ? 0x20 : 0x2A, dft_gpllx->TXLOCKDe.bf.TXLOCKD0e, ii);
  }   
  
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
  
  CS_FREE(tmp_gpllx);
  CS_FREE(dft_gpllx);

  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SPOH DUMP SETTINGS                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DEBUG                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_debug_spoh_dump_settings(cs_uint16 dev_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Displays current SPOH settings.                                  */
/* The left column is the current word/bitfield value and the       */
/* right column is the default value.  An asterisk indicates that   */
/* the default value of the chip has been changed.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  #ifdef INCLUDE_TEN_DEBUG_APIS

  TEN_spoh_t *tmp_spoh, *dft_spoh;
  T41_t *pDev = NULL;
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  tmp_spoh = (TEN_spoh_t *)CS_MALLOC(sizeof(TEN_spoh_t));
  dft_spoh = (TEN_spoh_t *)CS_MALLOC(sizeof(TEN_spoh_t));

  /* Bugzilla 28734 Klocwork fix, this block */
  /* Ckeck for failed alloc, return if failed. */
  if ((tmp_spoh == 0) || (dft_spoh == 0)) {
    if (tmp_spoh) CS_FREE(tmp_spoh);
    if (dft_spoh) CS_FREE(dft_spoh);
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": out of memory.");
    return (CS_ERROR);
  }
  
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  tmp_spoh->Enable.wrd = TEN_REG_READ(TEN_SPOH_REG_ADDR(pDev, Enable));
  tmp_spoh->SerIntfCtrl.wrd = TEN_REG_READ(TEN_SPOH_REG_ADDR(pDev, SerIntfCtrl));
  tmp_spoh->SRESET.wrd = TEN_REG_READ(TEN_SPOH_REG_ADDR(pDev, SRESET));
  tmp_spoh->RDIREIMappingA.wrd = TEN_REG_READ(TEN_SPOH_REG_ADDR(pDev, RDIREIMappingA));
  tmp_spoh->RDIREIMappingB.wrd = TEN_REG_READ(TEN_SPOH_REG_ADDR(pDev, RDIREIMappingB));
  tmp_spoh->SerIntfClkCtrl.wrd = TEN_REG_READ(TEN_SPOH_REG_ADDR(pDev, SerIntfClkCtrl));
  tmp_spoh->TxResponseLimit.wrd = TEN_REG_READ(TEN_SPOH_REG_ADDR(pDev, TxResponseLimit));
  tmp_spoh->SerIntfInt.wrd = TEN_REG_READ(TEN_SPOH_REG_ADDR(pDev, SerIntfInt));
  tmp_spoh->SerIntfIntEnable.wrd = TEN_REG_READ(TEN_SPOH_REG_ADDR(pDev, SerIntfIntEnable));
  tmp_spoh->SerIntfIntZ.wrd = TEN_REG_READ(TEN_SPOH_REG_ADDR(pDev, SerIntfIntZ));

  dft_spoh->Enable.wrd = TEN_SPOH_Enable_dft;       
  dft_spoh->SerIntfCtrl.wrd = TEN_SPOH_SerIntfCtrl_dft;
  dft_spoh->SRESET.wrd = TEN_SPOH_SRESET_dft;       
  dft_spoh->RDIREIMappingA.wrd = TEN_SPOH_RDIREIMappingA_dft;
  dft_spoh->RDIREIMappingB.wrd = TEN_SPOH_RDIREIMappingB_dft;
  dft_spoh->SerIntfClkCtrl.wrd = TEN_SPOH_SerIntfClkCtrl_dft;
  dft_spoh->TxResponseLimit.wrd = TEN_SPOH_TxResponseLimit_dft;
  dft_spoh->SerIntfInt.wrd = TEN_SPOH_SerIntfInt_dft;
  dft_spoh->SerIntfIntEnable.wrd = TEN_SPOH_SerIntfIntEnable_dft;
  dft_spoh->SerIntfIntZ.wrd = TEN_SPOH_SerIntfIntZ_dft;

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_ENABLE.wrd", tmp_spoh->Enable.wrd, tmp_spoh->Enable.wrd == dft_spoh->Enable.wrd ? 0x20 : 0x2A, dft_spoh->Enable.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_ENABLE.bf.TxEn", tmp_spoh->Enable.bf.TxEn, tmp_spoh->Enable.bf.TxEn == dft_spoh->Enable.bf.TxEn ? 0x20 : 0x2A, dft_spoh->Enable.bf.TxEn);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_ENABLE.bf.RxEn", tmp_spoh->Enable.bf.RxEn, tmp_spoh->Enable.bf.RxEn == dft_spoh->Enable.bf.RxEn ? 0x20 : 0x2A, dft_spoh->Enable.bf.RxEn);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFCTRL.wrd", tmp_spoh->SerIntfCtrl.wrd, tmp_spoh->SerIntfCtrl.wrd == dft_spoh->SerIntfCtrl.wrd ? 0x20 : 0x2A, dft_spoh->SerIntfCtrl.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFCTRL.bf.TxCRCEn", tmp_spoh->SerIntfCtrl.bf.TxCRCEn, tmp_spoh->SerIntfCtrl.bf.TxCRCEn == dft_spoh->SerIntfCtrl.bf.TxCRCEn ? 0x20 : 0x2A, dft_spoh->SerIntfCtrl.bf.TxCRCEn);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFCTRL.bf.TxSerEn", tmp_spoh->SerIntfCtrl.bf.TxSerEn, tmp_spoh->SerIntfCtrl.bf.TxSerEn == dft_spoh->SerIntfCtrl.bf.TxSerEn ? 0x20 : 0x2A, dft_spoh->SerIntfCtrl.bf.TxSerEn);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFCTRL.bf.RxSerEn", tmp_spoh->SerIntfCtrl.bf.RxSerEn, tmp_spoh->SerIntfCtrl.bf.RxSerEn == dft_spoh->SerIntfCtrl.bf.RxSerEn ? 0x20 : 0x2A, dft_spoh->SerIntfCtrl.bf.RxSerEn);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SRESET.wrd", tmp_spoh->SRESET.wrd, tmp_spoh->SRESET.wrd == dft_spoh->SRESET.wrd ? 0x20 : 0x2A, dft_spoh->SRESET.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SRESET.bf.SRESET", tmp_spoh->SRESET.bf.SRESET, tmp_spoh->SRESET.bf.SRESET == dft_spoh->SRESET.bf.SRESET ? 0x20 : 0x2A, dft_spoh->SRESET.bf.SRESET);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_RDIREIMAPPINGA.wrd", tmp_spoh->RDIREIMappingA.wrd, tmp_spoh->RDIREIMappingA.wrd == dft_spoh->RDIREIMappingA.wrd ? 0x20 : 0x2A, dft_spoh->RDIREIMappingA.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_RDIREIMAPPINGA.bf.MapA4", tmp_spoh->RDIREIMappingA.bf.MapA4, tmp_spoh->RDIREIMappingA.bf.MapA4 == dft_spoh->RDIREIMappingA.bf.MapA4 ? 0x20 : 0x2A, dft_spoh->RDIREIMappingA.bf.MapA4);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_RDIREIMAPPINGA.bf.MapA3", tmp_spoh->RDIREIMappingA.bf.MapA3, tmp_spoh->RDIREIMappingA.bf.MapA3 == dft_spoh->RDIREIMappingA.bf.MapA3 ? 0x20 : 0x2A, dft_spoh->RDIREIMappingA.bf.MapA3);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_RDIREIMAPPINGA.bf.MapA2", tmp_spoh->RDIREIMappingA.bf.MapA2, tmp_spoh->RDIREIMappingA.bf.MapA2 == dft_spoh->RDIREIMappingA.bf.MapA2 ? 0x20 : 0x2A, dft_spoh->RDIREIMappingA.bf.MapA2);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_RDIREIMAPPINGA.bf.MapA1", tmp_spoh->RDIREIMappingA.bf.MapA1, tmp_spoh->RDIREIMappingA.bf.MapA1 == dft_spoh->RDIREIMappingA.bf.MapA1 ? 0x20 : 0x2A, dft_spoh->RDIREIMappingA.bf.MapA1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_RDIREIMAPPINGB.wrd", tmp_spoh->RDIREIMappingB.wrd, tmp_spoh->RDIREIMappingB.wrd == dft_spoh->RDIREIMappingB.wrd ? 0x20 : 0x2A, dft_spoh->RDIREIMappingB.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_RDIREIMAPPINGB.bf.MapB4", tmp_spoh->RDIREIMappingB.bf.MapB4, tmp_spoh->RDIREIMappingB.bf.MapB4 == dft_spoh->RDIREIMappingB.bf.MapB4 ? 0x20 : 0x2A, dft_spoh->RDIREIMappingB.bf.MapB4);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_RDIREIMAPPINGB.bf.MapB3", tmp_spoh->RDIREIMappingB.bf.MapB3, tmp_spoh->RDIREIMappingB.bf.MapB3 == dft_spoh->RDIREIMappingB.bf.MapB3 ? 0x20 : 0x2A, dft_spoh->RDIREIMappingB.bf.MapB3);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_RDIREIMAPPINGB.bf.MapB2", tmp_spoh->RDIREIMappingB.bf.MapB2, tmp_spoh->RDIREIMappingB.bf.MapB2 == dft_spoh->RDIREIMappingB.bf.MapB2 ? 0x20 : 0x2A, dft_spoh->RDIREIMappingB.bf.MapB2);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_RDIREIMAPPINGB.bf.MapB1", tmp_spoh->RDIREIMappingB.bf.MapB1, tmp_spoh->RDIREIMappingB.bf.MapB1 == dft_spoh->RDIREIMappingB.bf.MapB1 ? 0x20 : 0x2A, dft_spoh->RDIREIMappingB.bf.MapB1);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFCLKCTRL.wrd", tmp_spoh->SerIntfClkCtrl.wrd, tmp_spoh->SerIntfClkCtrl.wrd == dft_spoh->SerIntfClkCtrl.wrd ? 0x20 : 0x2A, dft_spoh->SerIntfClkCtrl.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFCLKCTRL.bf.TCLKINV", tmp_spoh->SerIntfClkCtrl.bf.TCLKINV, tmp_spoh->SerIntfClkCtrl.bf.TCLKINV == dft_spoh->SerIntfClkCtrl.bf.TCLKINV ? 0x20 : 0x2A, dft_spoh->SerIntfClkCtrl.bf.TCLKINV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFCLKCTRL.bf.RCLKINV", tmp_spoh->SerIntfClkCtrl.bf.RCLKINV, tmp_spoh->SerIntfClkCtrl.bf.RCLKINV == dft_spoh->SerIntfClkCtrl.bf.RCLKINV ? 0x20 : 0x2A, dft_spoh->SerIntfClkCtrl.bf.RCLKINV);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_TXRESPONSELIMIT.wrd", tmp_spoh->TxResponseLimit.wrd, tmp_spoh->TxResponseLimit.wrd == dft_spoh->TxResponseLimit.wrd ? 0x20 : 0x2A, dft_spoh->TxResponseLimit.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_TXRESPONSELIMIT.bf.RSPLMT", tmp_spoh->TxResponseLimit.bf.RSPLMT, tmp_spoh->TxResponseLimit.bf.RSPLMT == dft_spoh->TxResponseLimit.bf.RSPLMT ? 0x20 : 0x2A, dft_spoh->TxResponseLimit.bf.RSPLMT);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.wrd", tmp_spoh->SerIntfInt.wrd, tmp_spoh->SerIntfInt.wrd == dft_spoh->SerIntfInt.wrd ? 0x20 : 0x2A, dft_spoh->SerIntfInt.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.TXCRC4i", tmp_spoh->SerIntfInt.bf.TXCRC4i, tmp_spoh->SerIntfInt.bf.TXCRC4i == dft_spoh->SerIntfInt.bf.TXCRC4i ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.TXCRC4i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.TXCLKLOSSi", tmp_spoh->SerIntfInt.bf.TXCLKLOSSi, tmp_spoh->SerIntfInt.bf.TXCLKLOSSi == dft_spoh->SerIntfInt.bf.TXCLKLOSSi ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.TXCLKLOSSi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.TXFRMLOSSi", tmp_spoh->SerIntfInt.bf.TXFRMLOSSi, tmp_spoh->SerIntfInt.bf.TXFRMLOSSi == dft_spoh->SerIntfInt.bf.TXFRMLOSSi ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.TXFRMLOSSi);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.NORSP7i", tmp_spoh->SerIntfInt.bf.NORSP7i, tmp_spoh->SerIntfInt.bf.NORSP7i == dft_spoh->SerIntfInt.bf.NORSP7i ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.NORSP7i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.NORSP6i", tmp_spoh->SerIntfInt.bf.NORSP6i, tmp_spoh->SerIntfInt.bf.NORSP6i == dft_spoh->SerIntfInt.bf.NORSP6i ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.NORSP6i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.NORSP5i", tmp_spoh->SerIntfInt.bf.NORSP5i, tmp_spoh->SerIntfInt.bf.NORSP5i == dft_spoh->SerIntfInt.bf.NORSP5i ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.NORSP5i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.NORSP4i", tmp_spoh->SerIntfInt.bf.NORSP4i, tmp_spoh->SerIntfInt.bf.NORSP4i == dft_spoh->SerIntfInt.bf.NORSP4i ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.NORSP4i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.NORSP3i", tmp_spoh->SerIntfInt.bf.NORSP3i, tmp_spoh->SerIntfInt.bf.NORSP3i == dft_spoh->SerIntfInt.bf.NORSP3i ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.NORSP3i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.NORSP2i", tmp_spoh->SerIntfInt.bf.NORSP2i, tmp_spoh->SerIntfInt.bf.NORSP2i == dft_spoh->SerIntfInt.bf.NORSP2i ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.NORSP2i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.NORSP1i", tmp_spoh->SerIntfInt.bf.NORSP1i, tmp_spoh->SerIntfInt.bf.NORSP1i == dft_spoh->SerIntfInt.bf.NORSP1i ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.NORSP1i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINT.bf.NORSP0i", tmp_spoh->SerIntfInt.bf.NORSP0i, tmp_spoh->SerIntfInt.bf.NORSP0i == dft_spoh->SerIntfInt.bf.NORSP0i ? 0x20 : 0x2A, dft_spoh->SerIntfInt.bf.NORSP0i);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.wrd", tmp_spoh->SerIntfIntEnable.wrd, tmp_spoh->SerIntfIntEnable.wrd == dft_spoh->SerIntfIntEnable.wrd ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.TXCRC4e", tmp_spoh->SerIntfIntEnable.bf.TXCRC4e, tmp_spoh->SerIntfIntEnable.bf.TXCRC4e == dft_spoh->SerIntfIntEnable.bf.TXCRC4e ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.TXCRC4e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.TXCLKLOSSe", tmp_spoh->SerIntfIntEnable.bf.TXCLKLOSSe, tmp_spoh->SerIntfIntEnable.bf.TXCLKLOSSe == dft_spoh->SerIntfIntEnable.bf.TXCLKLOSSe ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.TXCLKLOSSe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.TXFRMLOSSe", tmp_spoh->SerIntfIntEnable.bf.TXFRMLOSSe, tmp_spoh->SerIntfIntEnable.bf.TXFRMLOSSe == dft_spoh->SerIntfIntEnable.bf.TXFRMLOSSe ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.TXFRMLOSSe);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.NORSP7e", tmp_spoh->SerIntfIntEnable.bf.NORSP7e, tmp_spoh->SerIntfIntEnable.bf.NORSP7e == dft_spoh->SerIntfIntEnable.bf.NORSP7e ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.NORSP7e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.NORSP6e", tmp_spoh->SerIntfIntEnable.bf.NORSP6e, tmp_spoh->SerIntfIntEnable.bf.NORSP6e == dft_spoh->SerIntfIntEnable.bf.NORSP6e ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.NORSP6e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.NORSP5e", tmp_spoh->SerIntfIntEnable.bf.NORSP5e, tmp_spoh->SerIntfIntEnable.bf.NORSP5e == dft_spoh->SerIntfIntEnable.bf.NORSP5e ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.NORSP5e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.NORSP4e", tmp_spoh->SerIntfIntEnable.bf.NORSP4e, tmp_spoh->SerIntfIntEnable.bf.NORSP4e == dft_spoh->SerIntfIntEnable.bf.NORSP4e ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.NORSP4e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.NORSP3e", tmp_spoh->SerIntfIntEnable.bf.NORSP3e, tmp_spoh->SerIntfIntEnable.bf.NORSP3e == dft_spoh->SerIntfIntEnable.bf.NORSP3e ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.NORSP3e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.NORSP2e", tmp_spoh->SerIntfIntEnable.bf.NORSP2e, tmp_spoh->SerIntfIntEnable.bf.NORSP2e == dft_spoh->SerIntfIntEnable.bf.NORSP2e ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.NORSP2e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.NORSP1e", tmp_spoh->SerIntfIntEnable.bf.NORSP1e, tmp_spoh->SerIntfIntEnable.bf.NORSP1e == dft_spoh->SerIntfIntEnable.bf.NORSP1e ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.NORSP1e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTENABLE.bf.NORSP0e", tmp_spoh->SerIntfIntEnable.bf.NORSP0e, tmp_spoh->SerIntfIntEnable.bf.NORSP0e == dft_spoh->SerIntfIntEnable.bf.NORSP0e ? 0x20 : 0x2A, dft_spoh->SerIntfIntEnable.bf.NORSP0e);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.wrd", tmp_spoh->SerIntfIntZ.wrd, tmp_spoh->SerIntfIntZ.wrd == dft_spoh->SerIntfIntZ.wrd ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.wrd);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.TXCRC4iZ", tmp_spoh->SerIntfIntZ.bf.TXCRC4iZ, tmp_spoh->SerIntfIntZ.bf.TXCRC4iZ == dft_spoh->SerIntfIntZ.bf.TXCRC4iZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.TXCRC4iZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.TXCLKLOSSiZ", tmp_spoh->SerIntfIntZ.bf.TXCLKLOSSiZ, tmp_spoh->SerIntfIntZ.bf.TXCLKLOSSiZ == dft_spoh->SerIntfIntZ.bf.TXCLKLOSSiZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.TXCLKLOSSiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.TXFRMLOSSiZ", tmp_spoh->SerIntfIntZ.bf.TXFRMLOSSiZ, tmp_spoh->SerIntfIntZ.bf.TXFRMLOSSiZ == dft_spoh->SerIntfIntZ.bf.TXFRMLOSSiZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.TXFRMLOSSiZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.NORSP7iZ", tmp_spoh->SerIntfIntZ.bf.NORSP7iZ, tmp_spoh->SerIntfIntZ.bf.NORSP7iZ == dft_spoh->SerIntfIntZ.bf.NORSP7iZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.NORSP7iZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.NORSP6iZ", tmp_spoh->SerIntfIntZ.bf.NORSP6iZ, tmp_spoh->SerIntfIntZ.bf.NORSP6iZ == dft_spoh->SerIntfIntZ.bf.NORSP6iZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.NORSP6iZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.NORSP5iZ", tmp_spoh->SerIntfIntZ.bf.NORSP5iZ, tmp_spoh->SerIntfIntZ.bf.NORSP5iZ == dft_spoh->SerIntfIntZ.bf.NORSP5iZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.NORSP5iZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.NORSP4iZ", tmp_spoh->SerIntfIntZ.bf.NORSP4iZ, tmp_spoh->SerIntfIntZ.bf.NORSP4iZ == dft_spoh->SerIntfIntZ.bf.NORSP4iZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.NORSP4iZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.NORSP3iZ", tmp_spoh->SerIntfIntZ.bf.NORSP3iZ, tmp_spoh->SerIntfIntZ.bf.NORSP3iZ == dft_spoh->SerIntfIntZ.bf.NORSP3iZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.NORSP3iZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.NORSP2iZ", tmp_spoh->SerIntfIntZ.bf.NORSP2iZ, tmp_spoh->SerIntfIntZ.bf.NORSP2iZ == dft_spoh->SerIntfIntZ.bf.NORSP2iZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.NORSP2iZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.NORSP1iZ", tmp_spoh->SerIntfIntZ.bf.NORSP1iZ, tmp_spoh->SerIntfIntZ.bf.NORSP1iZ == dft_spoh->SerIntfIntZ.bf.NORSP1iZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.NORSP1iZ);
  CS_PRINT_OUTPUT("%-60s = 0x%04X%c  0x%04X\n", "SPOH_SERINTFINTZ.bf.NORSP0iZ", tmp_spoh->SerIntfIntZ.bf.NORSP0iZ, tmp_spoh->SerIntfIntZ.bf.NORSP0iZ == dft_spoh->SerIntfIntZ.bf.NORSP0iZ ? 0x20 : 0x2A, dft_spoh->SerIntfIntZ.bf.NORSP0iZ);

  CS_FREE(tmp_spoh);
  CS_FREE(dft_spoh);
  
  #else
  CS_PRINT_OUTPUT("Debug APIs are not compiled in.\n");
  #endif
  
  return (CS_OK);
}




