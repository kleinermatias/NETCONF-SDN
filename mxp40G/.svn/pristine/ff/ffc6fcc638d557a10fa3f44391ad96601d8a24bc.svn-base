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
 * API's for MPIF high level configuration.
 *
 * $Id: ten_hl_mpif.c,v 1.17 2013/02/22 20:44:11 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  BLOCK LEVEL RESETS                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_resets_block(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_reset_action_t act,
                              cs_uint16 block)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Action                                        */
/*              o Block                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control the SOFT resets within each block.                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   CS_RESET_DEASSERT                                          */
/*   CS_RESET_ASSERT                                            */
/*   CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* The [block] parameter is specified as:                       */
/*   TEN_HL_RESETS_BLOCK_SYNCDSYNC = 0x0001,                    */
/*   TEN_HL_RESETS_BLOCK_FEC       = 0x0002,                    */
/*   TEN_HL_RESETS_BLOCK_N40G      = 0x0004,                    */
/*   TEN_HL_RESETS_BLOCK_N10G      = 0x0008,                    */
/*   TEN_HL_RESETS_BLOCK_PP10G     = 0x0010,                    */
/*   TEN_HL_RESETS_BLOCK_XCON      = 0x0020,                    */
/*   TEN_HL_RESETS_BLOCK_HSIF      = 0x0040,                    */
/*   TEN_HL_RESETS_BLOCK_ALL       = 0x007F                     */
/*                                                              */
/* Note: The TEN_HL_RESETS_BLOCK_PP10G option does not act on   */
/*       the PP10G_MISC_RESET register. The PP10G_MISC_RESET    */
/*       should be reset separately using the                   */
/*       ten_pp10g_misc_reset API.                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 pp10g_slices = 0;
  cs_char8 *func = "ten_hl_resets_block";

  if (act > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() act %d out of range.  s/b 0..2.", func, act); 
    return CS_ERROR; 
  }
  
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s()  %s, SLICE_ALL, %s, ", func, ten_module_strings[module_id & 1], ten_reset_act_strings[act]);
  }
  else if (slice <= TEN_SLICE3) {
    CS_PRINT("%s()  %s, %s, %s, ", func, ten_module_strings[module_id & 1], ten_slice_strings[slice], ten_reset_act_strings[act]);
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, TEN_SLICE_ALL.", func, slice);
    return(CS_ERROR);
  }

  if (block & TEN_HL_RESETS_BLOCK_SYNCDSYNC) {
    CS_PRINT("SYNCDSYNC, ");
  }
  if (block & TEN_HL_RESETS_BLOCK_FEC) {
    CS_PRINT("FEC, ");
  }
  if (block & TEN_HL_RESETS_BLOCK_N40G) {
    CS_PRINT("N40G, ");
  }
  if (block & TEN_HL_RESETS_BLOCK_PP10G) {
    CS_PRINT("PP10G, ");
  }
  if (block & TEN_HL_RESETS_BLOCK_XCON) {
    CS_PRINT("XCON, ");
  }
  if (block & TEN_HL_RESETS_BLOCK_HSIF) {
    CS_PRINT("HSIF");
  }
  CS_PRINT("\n");
  
  

  if (block & TEN_HL_RESETS_BLOCK_SYNCDSYNC) {
    ten_syncdsynctx_control_sreset(module_id, slice, act);
    ten_syncdsyncrx_control_sreset(module_id, slice, act);
  }

  if (block & TEN_HL_RESETS_BLOCK_FEC) {
    ten_gfec_40g_reset(module_id, CS_TX_AND_RX, act);

    ten_gfec_10g_reset(module_id, slice, CS_TX_AND_RX, act);
 #ifndef TEN_NO_UFEC
    ten_ufec_reset(module_id, slice, CS_TX_AND_RX, act);
 #endif
  }

#ifndef TEN_NO_N40G
  if (block & TEN_HL_RESETS_BLOCK_N40G) {
    ten_n40g_set_global_resets(module_id, act,
                               TEN_N40G_GLOBAL_RESETS_ALL);
  }
#endif

  if (block & TEN_HL_RESETS_BLOCK_N10G) {
    ten_n10g_set_global_resets(module_id, slice, act,
                               TEN_N10G_GLOBAL_RESETS_ALL);
  }

  if (block & TEN_HL_RESETS_BLOCK_PP10G) {

    /* NOTE:  PP10G blocks acted upon only if clock       */
    /* enable and function enable bits are set.           */
    /* Bugzilla #19353, fix bus errors */
    
    pp10g_slices = ten_mpif_global_get_clock_disable_pp10g(
                                     TEN_MOD_ID_TO_DEV_ID(module_id),
                                     TEN_MOD_ID_TO_MOD_NUM(module_id),
                                     CS_RX);
                                     
    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
       !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_pm_reset(module_id, TEN_SLICE0, act);
      ten_pp10g_xgadj_rx_reset(module_id, TEN_SLICE0, act);
      ten_pp10g_rs_rx_rxcntrl1(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
       !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_pm_reset(module_id, TEN_SLICE1, act);
      ten_pp10g_xgadj_rx_reset(module_id, TEN_SLICE1, act);
      ten_pp10g_rs_rx_rxcntrl1(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
       !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_pm_reset(module_id, TEN_SLICE2, act);
      ten_pp10g_xgadj_rx_reset(module_id, TEN_SLICE2, act);
      ten_pp10g_rs_rx_rxcntrl1(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
       !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_pm_reset(module_id, TEN_SLICE3, act);
      ten_pp10g_xgadj_rx_reset(module_id, TEN_SLICE3, act);
      ten_pp10g_rs_rx_rxcntrl1(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_MAC) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_mac_rx_control_sreset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_MAC) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_mac_rx_control_sreset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_MAC) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_mac_rx_control_sreset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_MAC) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_mac_rx_control_sreset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_BASEX) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_xaui_rx_reset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_BASEX) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_xaui_rx_reset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_BASEX) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_xaui_rx_reset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_BASEX) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_xaui_rx_reset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_FC) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_fc_rx_reset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_FC) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_fc_rx_reset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_FC) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_fc_rx_reset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_FC) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_fc_rx_reset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_XCODE) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_xcode_rx_reset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_XCODE) && 
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_xcode_rx_reset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_XCODE) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_xcode_rx_reset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_XCODE) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_xcode_rx_reset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_EGPCS) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_egpcs_rx_reset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_EGPCS) && 
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_egpcs_rx_reset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_EGPCS) && 
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_egpcs_rx_reset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_EGPCS) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_egpcs_rx_reset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_GFP) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_gfp_rx_control_sreset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_GFP) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_gfp_rx_control_sreset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_GFP) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_gfp_rx_control_sreset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_GFP) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_gfp_rx_control_sreset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_XGPCS) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_pcs_rx_sreset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_XGPCS) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_pcs_rx_sreset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_XGPCS) && 
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_pcs_rx_sreset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_XGPCS) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_pcs_rx_sreset(module_id, TEN_SLICE3, act);
    }
    
    /* Tx side resets */
    pp10g_slices = ten_mpif_global_get_clock_disable_pp10g(
                                     TEN_MOD_ID_TO_DEV_ID(module_id),
                                     TEN_MOD_ID_TO_MOD_NUM(module_id),
                                     CS_TX);
                                     
    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_BASEX) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_xaui_tx_reset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_BASEX) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_xaui_tx_reset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_BASEX) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_xaui_tx_reset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_BASEX) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_xaui_tx_reset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_XCODE) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_xcode_tx_reset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_XCODE) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_xcode_tx_reset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_XCODE) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_xcode_tx_reset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_XCODE) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_xcode_tx_reset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_EGPCS) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_egpcs_tx_reset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_EGPCS) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_egpcs_tx_reset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_EGPCS) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_egpcs_tx_reset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_EGPCS) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_egpcs_tx_reset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_GFP) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_gfp_tx_control_sreset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_GFP) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_gfp_tx_control_sreset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_GFP) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_gfp_tx_control_sreset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_GFP) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_gfp_tx_control_sreset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_XGPCS) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_pcs_tx_sreset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_XGPCS) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_pcs_tx_sreset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_XGPCS) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_pcs_tx_sreset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_XGPCS) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_pcs_tx_sreset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_MAC) &&
        !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_mac_tx_control_sreset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_MAC) &&
        !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_mac_tx_control_sreset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_MAC) &&
        !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_mac_tx_control_sreset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
        ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_MAC) &&
        !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_mac_tx_control_sreset(module_id, TEN_SLICE3, act);
    }

    if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
       !(pp10g_slices & TEN_SLICE0_BITMASK)) {
      ten_pp10g_rs_tx_sreset(module_id, TEN_SLICE0, act, TEN_PP10G_RS_TX_SRESET_ALL);
      ten_pp10g_xgadj_tx_reset(module_id, TEN_SLICE0, act);
    }
    if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
       !(pp10g_slices & TEN_SLICE1_BITMASK)) {
      ten_pp10g_rs_tx_sreset(module_id, TEN_SLICE1, act, TEN_PP10G_RS_TX_SRESET_ALL);
      ten_pp10g_xgadj_tx_reset(module_id, TEN_SLICE1, act);
    }
    if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
       !(pp10g_slices & TEN_SLICE2_BITMASK)) {
      ten_pp10g_rs_tx_sreset(module_id, TEN_SLICE2, act, TEN_PP10G_RS_TX_SRESET_ALL);
      ten_pp10g_xgadj_tx_reset(module_id, TEN_SLICE2, act);
    }
    if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
       !(pp10g_slices & TEN_SLICE3_BITMASK)) {
      ten_pp10g_rs_tx_sreset(module_id, TEN_SLICE3, act, TEN_PP10G_RS_TX_SRESET_ALL);
      ten_pp10g_xgadj_tx_reset(module_id, TEN_SLICE3, act);
    }
  }

  if (block & TEN_HL_RESETS_BLOCK_XCON) {
    ten_xcon_datapath_reset(TEN_MOD_ID_TO_DEV_ID(module_id), act);
    ten_xcon_es_reset(TEN_MOD_ID_TO_DEV_ID(module_id), XCON_ELASTIC_STORE_ALL, act);
  }

  if (block & TEN_HL_RESETS_BLOCK_HSIF) {
    ten_hsif_reset(module_id, act, TEN_HSIF_RESET_ALL);
  }

  return(CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  GLOBAL LEVEL RESETS                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_resets_global(cs_uint16 dev_id,
                               cs_module_t module_num,
                               cs_uint16 slice,
                               cs_dir_t dir,
                               cs_reset_action_t act,
                               cs_uint16 block)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Action                                        */
/*              o Block                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control the HARD resets located in the top MPIF level        */
/* for each block.                                              */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   CS_RESET_DEASSERT                                          */
/*   CS_RESET_ASSERT                                            */
/*   CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* The [block] parameter is specified as:                       */
/*   TEN_HL_RESETS_GLOBAL_SYNCDSYNC  = 0x0001,                  */
/*   TEN_HL_RESETS_GLOBAL_FEC        = 0x0002,                  */
/*   TEN_HL_RESETS_GLOBAL_N40G       = 0x0004,                  */
/*   TEN_HL_RESETS_GLOBAL_N10G       = 0x0008,                  */
/*   TEN_HL_RESETS_GLOBAL_PP10G      = 0x0010,                  */
/*   TEN_HL_RESETS_GLOBAL_HSIF       = 0x0020,                  */
/*   TEN_HL_RESETS_GLOBAL_XFI_DSP    = 0x0040,                  */
/*   TEN_HL_RESETS_GLOBAL_PLL        = 0x0080,                  */
/*   TEN_HL_RESETS_GLOBAL_CLOCK_LOSS = 0x0100,                  */
/*   TEN_HL_RESETS_GLOBAL_SDS_MR     = 0x0200,                  */
/*   TEN_HL_RESETS_GLOBAL_SDS_XFI    = 0x0400,                  */
/*   TEN_HL_RESETS_GLOBAL_SFI41      = 0x0800,                  */
/*   TEN_HL_RESETS_GLOBAL_COMMON     = 0x1000,                  */
/*   TEN_HL_RESETS_GLOBAL_ALL        = 0x1FFF                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  CS_PRINT("ten_hl_resets_global\n");;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, 0xFF.");
    return(CS_ERROR);
  }

  if (block & TEN_HL_RESETS_BLOCK_SYNCDSYNC) {
    ten_mpif_global_reset_syncdsync(dev_id, module_num, slice, dir, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_FEC) {
    ten_mpif_global_reset_gfec_10g(dev_id, TEN_MPIF_GLOBAL_GFEC_10G_ALL, dir, act);
    ten_mpif_global_reset_gfec_40g(dev_id, TEN_MPIF_GLOBAL_GFEC_40G_ALL, dir, act);
    ten_mpif_global_reset_ufec(dev_id, TEN_MPIF_GLOBAL_UFEC_ALL, dir, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_N40G) {
    ten_mpif_global_reset_n40g(dev_id, module_num, dir, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_N10G) {
    ten_mpif_global_reset_n10g(dev_id, module_num, slice, dir, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_PP10G) {
    ten_mpif_global_reset_pp10g(dev_id, module_num, slice, dir, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_HSIF) {
    ten_mpif_global_reset_hsif(dev_id, module_num, dir, act);
    ten_mpif_global_reset_hsif_mpif(dev_id, module_num, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_XFI_DSP) {
    ten_mpif_global_reset_xfi_dsp(dev_id, slice, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_PLL) {
    ten_mpif_global_reset_syspll(dev_id, act);
    ten_mpif_global_reset_gpll(dev_id, module_num, slice, dir, act);
  }

  if ((block & TEN_HL_RESETS_GLOBAL_CLOCK_LOSS) && (module_num & TEN_HL_RESETS_A)) {
    ten_mpif_global_reset_clock_loss(dev_id, module_num, slice, dir, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_SDS_MR) {
    ten_mpif_global_reset_sds_mr_mpif(dev_id, module_num, slice, act);
    ten_mpif_global_reset_sds_mr(dev_id, module_num, slice, dir, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_SDS_XFI) {
    ten_mpif_global_reset_sds_xfi_mpif(dev_id, slice, act);
    ten_mpif_global_reset_sds_xfi(dev_id, slice, dir, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_SFI41) {
    /* Bug #37625 - ten_hl_resets_global calls SFI4.1 resets with slice instead of module_num */
    ten_mpif_global_reset_sfi41_mpif(dev_id, module_num, act);
    ten_mpif_global_reset_sfi41(dev_id, module_num, dir, act);
  }

  if (block & TEN_HL_RESETS_GLOBAL_COMMON) {
    ten_mpif_global_reset_common(dev_id, act, TEN_MPIF_GLOBAL_RESET_COMMON_ALL);
  }

  return(CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF FEC INITIALIZATION                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_mpif_fec_init (cs_uint16 module_id,
                                cs_uint16 slice,
                                ten_fec_type_t fec_type,
                                cs_uint16 fec_en)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o FEC Type                                      */
/*              o FEC Enable                                    */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the FEC to side A/B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   10G : TEN_SLICE0, TEN_SLICE1, TEN_SLICE2, TEN_SLICE3       */
/*   40G : TEN_SLICE0                                           */
/*                                                              */
/* The [fec_type] parameter is specified as:                    */
/*   0 = TEN_FEC_GFEC_10G                                       */
/*   1 = TEN_FEC_GFEC_40G                                       */
/*   2 = TEN_FEC_UFEC_10G                                       */
/*   3 = TEN_FEC_UFEC_40G                                       */
/*                                                              */
/* The [fec_en] parameter is specified as:                      */
/*   TEN_HL_MPIF_FEC_BYPASS   = 0x0000                          */
/*   TEN_HL_MPIF_FEC_EN_GFEC  = 0x0001                          */
/*   TEN_HL_MPIF_FEC_EN_UFEC  = 0x0002                          */
/* Setting the bit position to 0 will disable the slice         */
/* specified                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_char8 *func = "ten_hl_mpif_fec_init";  

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);

  if (fec_type > TEN_FEC_UFEC_40G) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() fec_type = 0x%04X\n", func, fec_type);
    return(CS_ERROR);
  }
  if (fec_en > TEN_HL_MPIF_FEC_EN_UFEC) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() fec_en = 0x%04X\n", func, fec_en);
    return(CS_ERROR);
  }
  if ((fec_en & TEN_HL_MPIF_FEC_EN_GFEC) && (fec_en & TEN_HL_MPIF_FEC_EN_UFEC)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() fec_en = 0x%04X, GFEC and UFEC are mutually exclusive\n", func, fec_en);
    return(CS_ERROR);
  }

  CS_PRINT("%s()  %s, %s, %s]\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           ten_fec_type_strings[fec_type], 
           ten_mpif_fec_en_strings[fec_en]);


  /* Bugzilla 24339 Start */
  #if 0
  if ((fec_type == TEN_FEC_GFEC_40G) && (slice != TEN_SLICE0)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": GFEC 40G can be configured on slice 0 only\n");
    return(CS_ERROR);
  }
  if ((fec_type == TEN_FEC_UFEC_40G) && (slice > TEN_SLICE1)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": UFEC 40G can be configured on slice 0/1 only\n");
    return(CS_ERROR);
  }
  if ((fec_type == TEN_FEC_UFEC_40G) && (slice < TEN_SLICE2)) {
    if(((module_id & 0x01) == TEN_MODULE_A) && (slice != TEN_SLICE0)) {
      CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": UFEC 40G MODULE_A is slice 0 only\n");
      return(CS_ERROR);
      }
    if(((module_id & 0x01) == TEN_MODULE_B) && (slice != TEN_SLICE1)) {
      CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": UFEC 40G MODULE_B is slice 1 only\n");
        return(CS_ERROR);
      }
  }
  #endif  
  /* Bugzilla 24339 Start */

  switch(fec_type) {
    case TEN_FEC_GFEC_10G:
      /* Choose FEC side and enable clocks */
      if(slice == TEN_SLICE0) {
        if(fec_en & TEN_HL_MPIF_FEC_EN_GFEC) {
          ten_mpif_global_clock_disable_gfec_40g(dev_id, (module_id & 0x01)+1, CS_TX_AND_RX, CS_ENABLE);
          ten_mpif_global_reset_gfec_40g(dev_id, (module_id & 0x01)+1, CS_TX_AND_RX, CS_RESET_DEASSERT);
          TEN_MDELAY(100);  /* 64 Clock Cycles */
          ten_mpif_gfec_cfg_port1(dev_id, (module_id & 0x01), (fec_type & 0x01));
        }
        else {
          /* Bugzilla 20807 resets the FEC when it's being de-allocated */
          ten_mpif_global_reset_gfec_40g(dev_id, (module_id & 0x01)+1, CS_TX_AND_RX, CS_RESET_ASSERT);
          ten_mpif_global_clock_disable_gfec_40g(dev_id, (module_id & 0x01)+1, CS_TX_AND_RX, CS_DISABLE);
        }
      }
      else {
        if(fec_en & TEN_HL_MPIF_FEC_EN_GFEC) {
           ten_mpif_global_clock_disable_gfec_10g(dev_id, 1 << (slice-1), CS_TX_AND_RX, CS_ENABLE);
           ten_mpif_global_reset_gfec_10g(dev_id, 1 << (slice-1), CS_TX_AND_RX, CS_RESET_DEASSERT);
           TEN_MDELAY(100);  /* 64 Clock Cycles */
           ten_mpif_gfec_cfg_port2_4(dev_id, (module_id & 0x01), slice-1);
        }
        else {
          /* Bugzilla 20807 resets the FEC when it's being de-allocated */
          ten_mpif_global_reset_gfec_10g(dev_id, 1 << (slice-1), CS_TX_AND_RX, CS_RESET_ASSERT);
          ten_mpif_global_clock_disable_gfec_10g(dev_id, 1 << (slice-1), CS_TX_AND_RX, CS_DISABLE);
        }
      }
      break;

    case TEN_FEC_GFEC_40G:
#ifdef TEN_NO_N40G
      return CS_ERROR;
#else
      /* Choose FEC side and enable clocks */
      if(fec_en & TEN_HL_MPIF_FEC_EN_GFEC) {
        ten_mpif_global_clock_disable_gfec_40g(dev_id, (module_id & 0x01)+1, CS_TX_AND_RX, CS_ENABLE);
        ten_mpif_global_reset_gfec_40g(dev_id, (module_id & 0x01)+1, CS_TX_AND_RX, CS_RESET_DEASSERT);
        TEN_MDELAY(100);  /* 64 Clock Cycles */
        ten_mpif_gfec_cfg_port1(dev_id, (module_id & 0x01), (fec_type & 0x01));
      }
      else {
        /* Bugzilla 20807 resets the FEC when it's being de-allocated */
        ten_mpif_global_reset_gfec_40g(dev_id, (module_id & 0x01)+1, CS_TX_AND_RX, CS_RESET_ASSERT);
        ten_mpif_global_clock_disable_gfec_40g(dev_id, (module_id & 0x01)+1, CS_TX_AND_RX, CS_DISABLE);
      }
#endif
      break;

    case TEN_FEC_UFEC_10G:
#ifdef TEN_NO_UFEC
      return CS_ERROR;
#else
      /* Choose FEC side and enable clocks */
      if(fec_en & TEN_HL_MPIF_FEC_EN_UFEC) {
        ten_mpif_global_clock_disable_ufec(dev_id, 1 << slice, CS_TX_AND_RX, CS_ENABLE);
        ten_mpif_global_reset_ufec(dev_id, 1 << (slice), CS_TX_AND_RX, CS_RESET_DEASSERT);
        TEN_MDELAY(100);  /* 64 Clock Cycles */
        ten_mpif_ufec_cfg(dev_id, (module_id & 0x01), slice, (fec_type & 0x01));
      }
      else {
        /* Bugzilla 20807 resets the FEC when it's being de-allocated */
        ten_mpif_global_reset_ufec(dev_id, 1 << (slice), CS_TX_AND_RX, CS_RESET_ASSERT);
        ten_mpif_global_clock_disable_ufec(dev_id, 1 << slice, CS_TX_AND_RX, CS_DISABLE);
      }
#endif
      break;

    case TEN_FEC_UFEC_40G:
#ifdef TEN_NO_N40G
      return CS_ERROR;
#else
#ifdef TEN_NO_UFEC
      return CS_ERROR;
#else
      /* Bugzilla 24339 Start */
      /* Choose FEC side and enable clocks */
      #if 0
      if(fec_en & TEN_HL_MPIF_FEC_EN_UFEC) {
        ten_mpif_global_clock_disable_ufec(dev_id, 1 << slice, CS_TX_AND_RX, CS_ENABLE);
        ten_mpif_global_reset_ufec(dev_id, 1 << slice, CS_TX_AND_RX, CS_RESET_DEASSERT);
        TEN_MDELAY(100);  /* 64 Clock Cycles */
        ten_mpif_ufec_cfg(dev_id, (module_id & 0x01), slice, TEN_SLICE_40G);
      }
      else {
        /* Bugzilla 20807 resets the FEC when it's being de-allocated */
        ten_mpif_global_reset_ufec(dev_id, 1 << slice, CS_TX_AND_RX, CS_RESET_ASSERT);
        ten_mpif_global_clock_disable_ufec(dev_id, 1 << slice, CS_TX_AND_RX, CS_DISABLE);
      }
      #endif

      if(fec_en & TEN_HL_MPIF_FEC_EN_UFEC) {
        ten_mpif_global_clock_disable_ufec(dev_id, 1 << (module_id & 0x01), CS_TX_AND_RX, CS_ENABLE);
        ten_mpif_global_reset_ufec(dev_id, 1 << (module_id & 0x01), CS_TX_AND_RX, CS_RESET_DEASSERT);
        TEN_MDELAY(100);  /* 64 Clock Cycles */
        ten_mpif_ufec_cfg(dev_id, (module_id & 0x01), slice, TEN_SLICE_40G);
      }
      else {
        /* Bugzilla 20807 resets the FEC when it's being de-allocated */
        ten_mpif_global_reset_ufec(dev_id, 1 << (module_id & 0x01), CS_TX_AND_RX, CS_RESET_ASSERT);
        ten_mpif_global_clock_disable_ufec(dev_id, 1 << (module_id & 0x01), CS_TX_AND_RX, CS_DISABLE);
      }
      /* Bugzilla 24339 End */
#endif
#endif
      break;
  }

  return CS_OK;
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SWITCH RX CONFIGURATION               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_mpif_clock_switch_rx (cs_uint16 dev_id,
                                       cs_module_t module_num,
                                       cs_uint8 slice,
                                       cs_uint8 select,
                                       cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Select                                            */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the clock switch mux that feeds the RX GPLL. The      */
/* first select option, TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE, can      */
/* force the mux to select a backup clock derived from the system   */
/* clock. The remaining select options enable or disable various    */
/* hardware alarm-based clock switching criteria.                   */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*   Note: This field is not applicable and ignored for XFI         */
/*         oriented clock switching criteria.                       */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*   Note: This field is not applicable and ignored for 40G         */
/*         and clock loss clock switching criteria.                 */
/*                                                                  */
/* The [select] parameter is specified as:                          */
/*   TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE            =  0              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_MR          =  1              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_XFI         =  2              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_MR       =  3              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_XFI      =  4              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_CLKLOSS          =  5              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_MRB2A       = 13              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_MRB2A    = 14              */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = For select=TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE, */
/*                    software forcing of the mux to a backup       */
/*                    clock is not enabled. For the remaining       */
/*                    hardware-based select options, the selected   */
/*                    criteria is not enabled.                      */
/*   CS_ENABLE  (1) = For select=TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE, */
/*                    software forcing of the mux to a backup       */
/*                    clock is enabled. For the remaining           */
/*                    hardware-based select options, the selected   */
/*                    criteria is enabled.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn_value;

  switch(select) {
    case TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE:
      rtn_value = ten_mpif_set_clock_switch_force(dev_id, module_num, slice, CS_RX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_MR:
      rtn_value = ten_mpif_set_clock_switch_xlos_mr(dev_id, module_num, slice, CS_RX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_XFI:
      rtn_value = ten_mpif_set_clock_switch_xlos_xfi(dev_id, slice, CS_RX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_MR:
      rtn_value = ten_mpif_set_clock_switch_lockdet_mr(dev_id, module_num, slice, CS_RX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_XFI:
      rtn_value = ten_mpif_set_clock_switch_lockdet_xfi(dev_id, slice, CS_RX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_CLKLOSS:
      rtn_value = ten_mpif_set_clock_switch_clkloss(dev_id, module_num, CS_RX, ctl);
      break;
      
    /* Bugzilla #29623 - Clock Switch APIs do not support T41 mrb2a option */
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_MRB2A:
      rtn_value = ten_mpif_set_clock_switch_xlos_mrb2a(dev_id, slice, CS_RX, ctl);
      break;
    
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_MRB2A:
      rtn_value = ten_mpif_set_clock_switch_lockdet_mrb2a(dev_id, slice, CS_RX, ctl);
      break;

    default:
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
      rtn_value = CS_ERROR;
    }

  return (rtn_value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SWITCH TX CONFIGURATION               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_mpif_clock_switch_tx (cs_uint16 dev_id,
                                       cs_module_t module_num,
                                       cs_uint8 slice,
                                       cs_uint8 select,
                                       cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Select                                            */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the clock switch mux that feeds the TX Controllable   */
/* Divider. The select option TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE can */
/* force the mux to select a backup clock derived from the system   */
/* clock. The remaining select options enable or disable various    */
/* hardware alarm-based clock switching criteria.                   */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*   Note: This field is not applicable and ignored for XFI         */
/*         oriented clock switching criteria.                       */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*   Note: This field is not applicable and ignored for 40G         */
/*         and clock loss clock switching criteria.                 */
/*                                                                  */
/*                                                                  */
/* The [select] parameter is specified as:                          */
/*   TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE            =  0              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_MR          =  1              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_XFI         =  2              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_MR       =  3              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_XFI      =  4              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_CLKLOSS          =  5              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_CBRGENAIS_10G =  6              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_CBRGENAIS_40G =  7              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_PN11_10G      =  8              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_PN11_40G      =  9              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_MS_10G        = 10              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_MS_40G        = 11              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_MSAIS         = 12              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_MRB2A       = 13              */
/*   TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_MRB2A    = 14              */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = For select=TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE, */
/*                    software forcing of the mux to a backup       */
/*                    clock is not enabled. For the remaining       */
/*                    hardware-based select options, the selected   */
/*                    criteria is not enabled.                      */
/*   CS_ENABLE (1) = For select=TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE,  */
/*                    software forcing of the mux to a backup       */
/*                    clock is enabled. For the remaining           */
/*                    hardware-based select options, the selected   */
/*                    criteria is enabled.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn_value;

  switch(select) {
    case TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE:
      rtn_value = ten_mpif_set_clock_switch_force(dev_id, module_num, slice, CS_TX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_MR:
      rtn_value = ten_mpif_set_clock_switch_xlos_mr(dev_id, module_num, slice, CS_TX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_XFI:
      rtn_value = ten_mpif_set_clock_switch_xlos_xfi(dev_id, slice, CS_TX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_MR:
      rtn_value = ten_mpif_set_clock_switch_lockdet_mr(dev_id, module_num, slice, CS_TX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_XFI:
      rtn_value = ten_mpif_set_clock_switch_lockdet_xfi(dev_id, slice, CS_TX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_CLKLOSS:
      rtn_value = ten_mpif_set_clock_switch_clkloss(dev_id, module_num, CS_TX, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_CBRGENAIS_10G:
      rtn_value = ten_mpif_set_clock_switch_tx_cbrgenais_10g(dev_id, module_num, slice, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_CBRGENAIS_40G:
      rtn_value = ten_mpif_set_clock_switch_tx_cbrgenais_40g(dev_id, module_num, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_PN11_10G:
      rtn_value = ten_mpif_set_clock_switch_tx_pn11_10g(dev_id, module_num, slice, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_PN11_40G:
      rtn_value = ten_mpif_set_clock_switch_tx_pn11_40g(dev_id, module_num, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_MS_10G:
      rtn_value = ten_mpif_set_clock_switch_tx_ms_10g(dev_id, module_num, slice, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_MS_40G:
      rtn_value = ten_mpif_set_clock_switch_tx_ms_40g(dev_id, module_num, ctl);
      break;
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_MSAIS:
      rtn_value = ten_mpif_set_clock_switch_tx_msais(dev_id, module_num, slice, ctl);
      break;
      
    /* Bugzilla #29623 - Clock Switch APIs do not support T41 mrb2a option */
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_MRB2A:
      rtn_value = ten_mpif_set_clock_switch_xlos_mrb2a(dev_id, slice, CS_TX, ctl);
      break;
    
    case TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_MRB2A:
      rtn_value = ten_mpif_set_clock_switch_lockdet_mrb2a(dev_id, slice, CS_TX, ctl);
      break;

    default:
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
      rtn_value = CS_ERROR;
    }

  return (rtn_value);
}

/********************************************************************/
/* $rtn_hdr_start  CONFIG GLOBAL                                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_global (cs_uint16 dev_id,
                                cs_uint16 a_mode,
                                cs_uint16 b_mode,
                                cs_uint16 mbclksel,
                                cs_uint16 mr_mode_a_not_sfi41,
                                cs_uint16 mr_mode_b_not_sfi41)
/* INPUTS     : o Device Id                                         */
/*              o a_mode                                            */
/*              o b_mode                                            */
/*              o mbclksel                                          */
/*              o mr_mode_a                                         */
/*              o mr_mode_b                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*   Config Top level                                               */
/*                                                                  */
/* The [a_mode] and [b_mode] parameters determins if the side is a  */
/* single pipe 40G or 4 10B pipes and is specified as:              */
/*   0 = TEN_GLOBAL_MODE_S_40G for 40G module is enabled            */
/*   1 = TEN_GLOBAL_MODE_QUAD_10G for 40G module is bypassed and    */
/*       should only be set for quad 10G applications               */
/*                                                                  */
/* The [mbclksel], also know as the system clock reference          */
/* frequency select pin, is specified as:                           */
/*   0 for system reference frequency <= 200000000Hz                */
/*   1 for system reference frequency > 200000000Hz                 */
/*                                                                  */
/* The [mr_mode_a_not_sfi41] and [mr_mode_b_not_sfi41] (multi-rate  */
/* mode not SFI41) parameters are specified as:                     */
/*   0 = port's Multi-Rate mode is SFI41                            */
/*   1 = port's Multi-Rate mode is not SFI41 or Multi-Rate mode is  */
/*       disabled                                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
    CS_PRINT("ten_hl_config_global\n");
    
    /* Wait for BIST_DONE */
    /*if (0 != ten_hl_mpif_wait_for_bist_done(dev_id))
    {
        CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": BIST not done.");*/
        /* BIST is not done! */
    /*    return (CS_ERROR);
    }*/

    /* Remove chip and mpif hard reset from common reset register */
    ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT,
                                 TEN_MPIF_GLOBAL_RESET_COMMON_MPIF |
                                 TEN_MPIF_GLOBAL_RESET_COMMON_CHIP);

    /* Disable reset to SPLL reset */
    ten_mpif_global_reset_syspll(dev_id, CS_RESET_DEASSERT);

    /* Config SPLL */
    if (ten_hl_gpllx1_config_SYSGPLL(dev_id, mbclksel) != 0)
    {
        /* ten_hl_gpllx1_config_SYSGPLL failed */
        return (CS_ERROR);
    }

    /* Check SPLL LOCK status */
    /*if (ten_hl_gpllx1_check_lock(dev_id, 0) == 0)
    {*/
        /* SPLL failed to lock */
    /*    return (CS_ERROR);
    }*/

    ten_mpif_global_reset_xfi_dsp(dev_id, TEN_SLICE_ALL, CS_RESET_DEASSERT);

    ten_mpif_global_reset_gpll(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_DEASSERT);

    ten_mpif_global_reset_hsif_mpif(dev_id, TEN_MODULE_A_AND_B, CS_RESET_DEASSERT);

    ten_mpif_global_reset_sds_mr_mpif(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_RESET_DEASSERT);

    ten_mpif_global_reset_sds_xfi_mpif(dev_id, TEN_SLICE_ALL, CS_RESET_DEASSERT);

    /*#tenabo_bf_write(DEV_ID,main::TEN_MPIF_GLOBAL_RESET_XFI_DSP,0,15,0);*/
    ten_mpif_global_reset_xfi_dsp(dev_id, 0, CS_RESET_DEASSERT);

    /* Setup GPLL Clocking Mux */
    /* configure RX & TX GPLL reference & pilot to come from RX SerDes */

    /*if ($MR_MODE[0] ne SFI41) {*/
    if (mr_mode_a_not_sfi41)
        ten_mpif_clock_select_gpll_in(dev_id, TEN_MODULE_A, TEN_SLICE_ALL, CS_TX, 1);
    
    /*if ($MR_MODE[4] ne SFI41) {*/
    if (mr_mode_b_not_sfi41)
        ten_mpif_clock_select_gpll_in(dev_id, TEN_MODULE_B, TEN_SLICE_ALL, CS_TX, 1);
    
    ten_mpif_clock_select_gpll_in(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_RX, 0);

    ten_mpif_clock_select_gpll_out(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX_AND_RX, 1);


    /* Select 40G clocking Mux */
    ten_mpif_clock_select_40g(dev_id, !b_mode, !b_mode, !a_mode, !a_mode);

    /* Select QUAD Mode Mux */
    ten_mpif_global_cfg(dev_id, b_mode, a_mode, b_mode, a_mode);

    /* Enable LVDS PAD for DIV clock */
    /*#main::ten_reg_write(DEV_ID,main::TEN_MPIF_LVDS_DIV_PD,0);*/
    ten_mpif_set_lvds_div_pd(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX_AND_RX, 0);

    /*if (T40_6004) {*/
    if (TEN_CHIP_ID_CS6004 == ten_mpif_get_chip_jtag_id(dev_id))
    {
        /* This is a CS6004 chip */
        ten_reg_write(dev_id, TEN_MPIF_CLOCK_SELECT_PROT, 0x33);
        ten_reg_write(dev_id, TEN_MPIF_CLOCK_SELECT_PILOT, 0x3);
    }

    ten_hl_hsif_sfi42_reset_fix(dev_id);

    return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  TENABO WAIT FOR BIST DONE                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_hl_mpif_wait_for_bist_done (cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 0: Done,  1: NOT Done                               */
/* DESCRIPTION:                                                     */
/*  Waiting for udr_rdy signal                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
    cs_uint16 read_count = 0;
    TEN_MPIF_STAR_BIST_DONE_t  star_bist_tone;
    T41_t *pDev = NULL;

    TEN_DEV_COMMON_VALIDATE(dev_id, pDev, FALSE);
    /* Bugzilla #25633: ten_hl_mpif_wait_for_bist_done waits for too long. */
    while (read_count++ < 30)
    {
        star_bist_tone.wrd =  TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, STAR_BIST_DONE));
        star_bist_tone.wrd &= 0x7;
        if (star_bist_tone.wrd == 0x7)
        {
            /* UDR_RDY completed */
            return 0;
        }
        TEN_MDELAY(100);
    }
    /* UDR_RDY cycle never completed. */
    CS_PRINT("ten_hl_mpif_wait_for_bist_done TIMED OUT.\n");
    return 1;
}

