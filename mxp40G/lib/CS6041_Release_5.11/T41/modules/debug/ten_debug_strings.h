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
 * ten_debug_strings.h 
 *
 * $Id: ten_debug_strings.h,v 1.25 2013/02/22 20:42:45 jccarlis Exp $
 *
 * API prototypes for Debug APIs 
 *
 */
 
#ifndef __TEN_DEBUG_STRINGS_H__
#define __TEN_DEBUG_STRINGS_H__

#ifdef __cplusplus
extern "C" {
#endif

extern cs_char8 *ten_hl_config_dyn_repro_strings[];
extern cs_char8 *ten_module_strings[];
extern cs_char8 *ten_slice_strings[];
extern cs_char8 *ten_instance_strings[]; 
extern cs_char8 *ten_hl_config_traffic_types_strings[];
extern cs_char8 *ten_hl_config_otu_overhead_term_strings[];
extern cs_char8 *ten_hl_config_oc192_overhead_term_strings[];
extern cs_char8 *ten_kpg_strings[];
extern cs_char8 *ten_fec_ovhd_strings[];
extern cs_char8 *ten_traffic_mode_strings[];
extern cs_char8 *ten_hsif_prbs_pn_strings[];
extern cs_char8 *ten_hsif_mr_data_source_strings[];
extern cs_char8 *ten_hsif_protocols_strings[];
/* Bugzilla 24339 Start */
extern cs_char8 *ten_10g_40g_gfec_strings[];
extern cs_char8 *ten_10g_gfec_strings[];
extern cs_char8 *ten_10g_40g_ufec_strings[];
extern cs_char8 *ten_slice_mode_strings[];
extern cs_char8 *ten_fec_type_strings[];
extern cs_char8 *ten_mpif_fec_en_strings[];
/* Bugzilla 24339 End */
/* Bugzilla 24360 Start */
extern cs_char8 *ten_sync_type_strings[];
/* Bugzilla 24360 End */
extern cs_char8 *ten_tributary_slot_bw_strings[];
extern cs_char8 *ten_dir_strings[];
extern cs_char8 *ten_pp10g_flow_mode_strings[];
extern cs_char8 *ten_10ge_tc_frame_format_strings[];
/* Bugzilla 26200 Start */
extern cs_char8 *ten_pp40g_rx_parm_strings[];
extern cs_char8 *ten_pp40g_tx_parm_strings[];
/* Bugzilla 26200 End */
extern cs_char8 *ten_reset_act_strings[];
extern cs_char8 *ten_method_strings[];
extern cs_char8 *ten_hl_syncdsync_mode_strings[];
extern cs_char8 *ten_hsif_clk_40g_strings[];
extern cs_char8 *ten_sadeco_fp_type_strings[];
extern cs_char8 *ten_ex_circuit_threshold_strings[];
extern cs_char8 *ten_ctrl_strings[];

extern const cs_char8 *ten_pp40g_rx_debug_str[TEN_PP40G_RX_MAX_MODE];
extern const cs_char8 *ten_pp40g_tx_debug_str[TEN_PP40G_TX_MAX_MODE];

extern const cs_char8 *ten_gpll_instance_strings[];
extern const cs_char8 *ten_gpllx1_mode_strings[];
extern const cs_char8 *ten_deskew_strings[];
extern const cs_char8 *ten_xcon_es_num_strings[];
extern const cs_char8 *ten_xcon_input_strings[];
extern const cs_char8 *ten_xcon_es_mod_slice_strings[];
extern const cs_char8 *ten_nx0g_otnr_strings[];
extern const cs_char8 *ten_xcon_center_type_strings[];
extern const cs_char8 *ten_pp10g_rx_mode_strings[];
extern const cs_char8 *ten_pp10g_tx_mode_strings[];
extern const cs_char8 *ten_fracdiv_instance_strings[];
extern const cs_char8 *ten_mpif_n40g_n10g_strings[];
extern const cs_char8 *ten_ohpp_signals_strings[];
extern const cs_char8 *ten_ohpp_widths_strings[];
extern const cs_char8 *ten_xcon_interface_strings[];
extern const cs_char8 *ten_syncdsync_rx_div_mux_strings[];


#ifdef __cplusplus
}
#endif
#endif

