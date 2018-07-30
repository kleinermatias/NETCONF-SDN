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
 * ten_debug_strings.c
 *
 * Strings for debug print messages
 *
 * $Id: ten_debug_strings.c,v 1.41 2014/04/02 18:47:19 pptawade Exp $
 *
 */

#include "tenabo40.h"

/* Printable strings for ten_hl_config_dyn_repro_enums */
cs_char8 *ten_hl_config_dyn_repro_strings[] = 
{
  "INITIAL_CONFIG",
  "REPRO_CLIENT",
  "REPRO_LINE_AND_CLIENT"
};

/* Printable strings for cs_module_t */
cs_char8 *ten_module_strings[] = 
{
  "Module A",
  "Module B",
  "Module A and B"
};

/* Printable strings for Slice */
cs_char8 *ten_slice_strings[] = 
{
  "Slice 0",
  "Slice 1",
  "Slice 2",
  "Slice 3"
};

/* Printable strings for Instances */
cs_char8 *ten_instance_strings[] = 
{
  "Instance 0",
  "Instance 1",
  "Instance 2",
  "Instance 3"
};

/* Printable strings for ten_hl_config_traffic_types_e */
cs_char8 *ten_hl_config_traffic_types_strings[] = 
{
  "NONE",
  "OTU3",
  "OTU3E",
  "OTU3P",
  "ODTU23",
  "OTU2",
  "OTU2E",
  "OTU1F",
  "OC192",
  "10GE_WAN",
  "10GE_6_2",
  "10GE_7_1",
  "10GE_7_3",
  "10GFC",
  "8GFC",
  "4GFC",
  "2GFC",
  "1GFC",
  "5GB_IB",
  "OTU3_NOFEC",
  "10GE",
  "40GELAN",
  "OC768",
  "OTU3E3",
  "CBR40G_50188149150", 
  "OTU3P2",
  "10GE_6_1",
  "10GE_7_2",
  "10GE_GFPF_OC192_ODU2",
  "OTU1E",
  "10GE_RA",
  "OC192_OTU2",
  "OC768_OTU3",
  "10GE_TC",
  "OTU2F",
  "OTU3E2",
  "OTU2P",
  "ODUFLEX",
  "ODTU",
  "10G_IB",
  "12_5G_IB",
  "SERIAL_40GE",
  "PARALLEL_40GE",
  "TC_40GE",
  "S64_66_40GE",
  "BYPASS",
  "10GFC_TC",
  "8GFC_RA",
  "4GFC_RA",
  "2GFC_RA",
  "1GFC_RA",
  "8GFC_ENH",
  "4GFC_ENH",
  "2GFC_ENH",
  "1GFC_ENH",
  "OTU3E4",
  "10GE_GFPF",
  "10GFC_TC_G709", /* Bug 31054 */
  "10GFC_TC_RA",
  "2GISC",
  "CPRI_7", /* Bugzilla 36662 */
  "OTU2E_DIV2", /* Bugzilla 37987 */
  "OTU2E_DIV4", /* Bugzilla 37987 */
  "1GE", /* Bugzilla 38871 */
  "FDR10_IB", /* Bugzilla 39242 */
  "CPRI_4", /* Bugzilla 39690 */
  "OTU2EX4",  /* Bugzilla 43359 */
  "CBR_10G",  /* Bugzilla 43573 */
};


/* Printable strings for ten_hl_config_otu_overhead_term_enums */
cs_char8 *ten_hl_config_otu_overhead_term_strings[] = 
{
  "OTU_TERM_TRANSPARENT",
  "OTU_TERM_SECTION",
  "OTU_TERM_FULL",
};


cs_char8 *ten_hl_config_oc192_overhead_term_strings[] =
{
  "",
  "OC192_TERM_TRANSPARENT_CBR10",
  "OC192_TERM_TRANSPARENT_REGENERATOR",
  "OC192_TERM_RS_LAYER_REGENERATOR",
  "OC192_TERM_MS_LAYER_REGENERATOR"
};



cs_char8 *ten_kpg_strings[] =
{
  "KPG_FIXED_PATTERN",
  "KPG_PN11",
  "KPG_PN23",
  "KPG_PN31",
  "KPG_DISABLED",  
};


cs_char8 *ten_fec_ovhd_strings[TEN_FEC_MODE_MAX_NUM] =
{
  "FEC_MODE_OTUkV",
  "FEC_MODE_OTUkV_262",
  "FEC_MODE_OTUkV_273",
  "FEC_MODE_OTUkV_285",
  "FEC_MODE_OTUkV_297",
  "FEC_MODE_OTUkV_5_4",
  "FEC_MODE_OTUkV_301",
  "FEC_MODE_OTUkV_SDH_A",
  "FEC_MODE_OTUkV_SDH_B",
  "FEC_MODE_OTUkV_4080_3929",
  "FEC_MODE_OTUkV_68_65",
  "FEC_MODE_OTUkV_267",
  "FEC_MODE_OTUkV_270",
  "FEC_MODE_GFEC",
  "FEC_MODE_ZEROFEC",
  "FEC_MODE_NOFEC",
  "FEC_MODE_DEALLOCATE",
  "FEC_MODE_OTUkV_263",
  "FEC_MODE_OTUkV_280",
  "FEC_MODE_OTUkV_295",
};

cs_char8 *ten_traffic_mode_strings[] =
{
  "40G_TRANSPONDER",
  "40G_MUXPONDER",
  "10G_TRANSPONDER",
  "10G_LOOPBACK",
  "40G_LOOPBACK",
  "10G_KPGA",
  "40G_KPGA",
  "10G_PBERT",
  "10G_HSIF_KPGA",
  "40G_HSIF_KPGA",
  /* Bugzilla 24559 Start */
  "10G_CBR_KPGA",
  "40G_CBR_KPGA",
  /* Bugzilla 24559 End */
  /* Bugzilla 24645 Start */
  "10G_WIRE",
  "40G_WIRE",
  /* Bugzilla 24645 Start */
};

cs_char8 *ten_hsif_prbs_pn_strings[] =
{
  "HSIF_PRBS_PN31",
  "HSIF_PRBS_PN23",
  "HSIF_PRBS_PN15",
  "HSIF_PRBS_PN7",
  "HSIF_PRBS_PN9",
};


cs_char8 *ten_hsif_mr_data_source_strings[] =
{
  "HSIF_MR_DATASOURCE_DIG_TX_DIN",
  "HSIF_MR_DATASOURCE_PRBS",
  "HSIF_MR_DATASOURCE_RX_LOOPBACK",
};
      
cs_char8 *ten_hsif_protocols_strings[] =
{
  "HSIF_PROTOCOL_DISABLED",
  "SFI51",
  "SFI41",
  "XFI",
  "SFI42_10G",
  "SFI42_40G",
  "XAUI",
};

/* Bugzilla 24339 Start */
cs_char8 *ten_10g_40g_gfec_strings[] =
{
  "10G_40G_GFEC_DISABLED",
  "10G_40G_GFEC_10G_MODE",
  "10G_40G_GFEC_40G_MODE",
};

cs_char8 *ten_10g_gfec_strings[] =
{
  "10G_GFEC_DISABLED",
  "10G_GFEC_MODULE_A",
  "10G_GFEC_MODULE_B",
};

cs_char8 *ten_10g_40g_ufec_strings[] =
{
  "UFEC_DISABLED",
  "10G_UFEC_MODULE_A",
  "10G_UFEC_MODULE_B",
  "40G_UFEC_MODE",
};

cs_char8 *ten_slice_mode_strings[] =
{
  "10G",
  "40G",
};

cs_char8 *ten_fec_type_strings[] =
{
  "GFEC_10G",
  "GFEC_40G",
  "UFEC_10G",    
  "UFEC_40G",
};

cs_char8 *ten_mpif_fec_en_strings[] =
{
  "MPIF_FEC_BYPASS",
  "MPIF_FEC_EN_GFEC",
  "MPIF_FEC_EN_UFEC",
};
/* Bugzilla 24339 End */


cs_char8 *ten_tributary_slot_bw_strings[] =
{
  "TRIB_SLOT_BW_1_25",
  "TRIB_SLOT_BW_2_5",
};

/* Bugzilla 24360 Start */
cs_char8 *ten_sync_type_strings[] =
{
  "AMP",
  "BMP",
  "AMP_DT",
  "AMP_PROP",
  "AMP_PROP_DT",
  "GMP_LO",
  "GMP_HO",
  "GMP_HO_DT",
  "RATE_ADJUST",
  "TRANSCODE",
};
/* Bugzilla 24360 End */

cs_char8 *ten_dir_strings[] =
{
  "TX",
  "RX",
  "TX_AND_RX",
};

cs_char8 *ten_pp10g_flow_mode_strings[] =
{
  "PP10G_FLOW_GFP_S_P",
  "PP10G_FLOW_GFP_S",
  "PP10G_FLOW_ETH_4",
  "PP10G_FLOW_ETH_4_P",
  "PP10G_FLOW_MAX_MODE",
};

cs_char8 *ten_10ge_tc_frame_format_strings[] =
{
  "28_BLOCKS_5_SUPERBLOCKS_CRC4",
  "28_BLOCKS_11_SUPERBLOCKS_CRC4",
  "32_BLOCKS_4_SUPERBLOCKS_NOCRC",
  "32_BLOCKS_8_SUPERBLOCKS_NOCRC",
};


/* Bugzilla 26200 Start */
cs_char8 *ten_pp40g_rx_parm_strings[] =
{
  "PP40G_RX_DISABLE",
  "PP40G_RX_BYPASS",
  "PP40G_RX_40GEP_XCON",
  "PP40G_RX_40GESBI_XCON",
  "PP40G_RX_40GES6466_XCON",
  "PP40G_RX_40GEX_XCON",
  "PP40G_RX_40GEP_XCON_RA",
  "PP40G_RX_40GESBI_XCON_RA",
  "PP40G_RX_40GES6466_XCON_RA",
  "PP40G_RX_40GEX_XCON_RA",
  "PP40G_RX_MAX_MODE",
};

cs_char8 *ten_pp40g_tx_parm_strings[] =
{
  "PP40G_TX_DISABLE",
  "PP40G_TX_BYPASS",
  "PP40G_TX_XCON_40GEP",
  "PP40G_TX_XCON_40GESBI",
  "PP40G_TX_XCON_40GES6466",
  "PP40G_TX_XCON_40GEX",
  "PP40G_TX_XCON_40GEP_RA",
  "PP40G_TX_XCON_40GESBI_RA",
  "PP40G_TX_XCON_40GES6466_RA",
  "PP40G_TX_XCON_40GEX_RA",
  "PP40G_TX_PBERT_40GEP",
  "PP40G_TX_PBERT_40GESBI",
  "PP40G_TX_PBERT_40GES6466",
  "PP40G_TX_PBERT_40GEX",
  "PP40G_TX_MAX_MODE",
};
/* Bugzilla 26200 End */

cs_char8 *ten_reset_act_strings[] =
{
  "RESET_DEASSERT",
  "RESET_ASSERT",
  "RESET_TOGGLE",
};

cs_char8 *ten_method_strings[] =
{
  "1TO1_ASYNC_2LEVEL",
  "SYNC_ASYNC_1LEVEL",
  "1TO1_ASYNC_1LEVEL",
  "BOTH_1TO1",
  "ASYNC_ASYNC_1LEVEL",
  "1TO1_ASYNC_1TO1_1LEVEL",
  "ASYNC_ASYNCX4_1LEVEL",
};

cs_char8 *ten_hl_syncdsync_mode_strings[] =
{
  "OXU2_MONO_ONE_LEVEL",
  "OXU3_MONO_ONE_LEVEL",
  "ODTU23_MUX_ONE_LEVEL",
  "ODTU23_ODU2_MUX_TWO_LEVEL",
};

cs_char8 *ten_hsif_clk_40g_strings[] =
{
  "HSIF_CLK_40G_RXSEL",
  "HSIF_CLK_40G_RX_AGGR_MODE",
  "HSIF_CLK_40G_TXSEL",
  "HSIF_CLK_40G_TX_AGGR_MODE",
};

cs_char8 *ten_sadeco_fp_type_strings[] =
{
  "SONET_SDH_INACTIVE",
  "SONET_SDH_16",
  "SONET_SDH_64", 
};


cs_char8 *ten_ex_circuit_threshold_strings[] =
{
  "ES_IML_THRESH",
  "ES_CIRCUIT_THRESHOLD_UPPER",
  "ES_CIRCUIT_THRESHOLD_LOWER",
  "ES_MARGIN_UPPER",
  "ES_MARGIN_LOWER",
  "ES_THRESHOLD_LEVEL",
  "ES_PAUSE_LEVEL",
};

cs_char8 *ten_ctrl_strings[] =
{
  "DISABLE",
  "ENABLE",
};

const cs_char8 *ten_pp40g_rx_debug_str[TEN_PP40G_RX_MAX_MODE] = {
  "TEN_PP40G_RX_DISABLE",              
  "TEN_PP40G_RX_BYPASS",
  "TEN_PP40G_RX_40GEP_XCON",
  "TEN_PP40G_RX_40GESBI_XCON",
  "TEN_PP40G_RX_40GES6466_XCON",
  "TEN_PP40G_RX_40GEX_XCON",
  "TEN_PP40G_RX_40GEP_XCON_RA",
  "TEN_PP40G_RX_40GESBI_XCON_RA",
  "TEN_PP40G_RX_40GES6466_XCON_RA",
  "TEN_PP40G_RX_40GEX_XCON_RA"
};

const cs_char8 *ten_pp40g_tx_debug_str[TEN_PP40G_TX_MAX_MODE] = {
  "TEN_PP40G_TX_DISABLE",
  "TEN_PP40G_TX_BYPASS",
  "TEN_PP40G_TX_XCON_40GEP",
  "TEN_PP40G_TX_XCON_40GESBI",
  "TEN_PP40G_TX_XCON_40GES6466",
  "TEN_PP40G_TX_XCON_40GEX",
  "TEN_PP40G_TX_XCON_40GEP_RA",
  "TEN_PP40G_TX_XCON_40GESBI_RA",
  "TEN_PP40G_TX_XCON_40GES6466_RA",
  "TEN_PP40G_TX_XCON_40GEX_RA",
  "TEN_PP40G_TX_PBERT_40GEP",
  "TEN_PP40G_TX_PBERT_40GESBI",
  "TEN_PP40G_TX_PBERT_40GES6466",
  "TEN_PP40G_TX_PBERT_40GEX"
};

const cs_char8 *ten_gpll_instance_strings[] = {
  "SYS",
  "RX_A_SLICE_0",
  "RX_A_SLICE_1",
  "RX_A_SLICE_2",
  "RX_A_SLICE_3",
  "TX_A_SLICE_0",
  "TX_A_SLICE_1",
  "TX_A_SLICE_2",
  "TX_A_SLICE_3",
  "RX_B_SLICE_0",
  "RX_B_SLICE_1",
  "RX_B_SLICE_2",
  "RX_B_SLICE_3",
  "TX_B_SLICE_0",
  "TX_B_SLICE_1",
  "TX_B_SLICE_2",
  "TX_B_SLICE_3"
};

const cs_char8 *ten_fracdiv_instance_strings[] = {
  "RX_A_SLICE_0",
  "RX_A_SLICE_1",
  "RX_A_SLICE_2",
  "RX_A_SLICE_3",
  "RX_B_SLICE_0",
  "RX_B_SLICE_1",
  "RX_B_SLICE_2",
  "RX_B_SLICE_3",
  "TX_A_SLICE_0",
  "TX_A_SLICE_1",
  "TX_A_SLICE_2",
  "TX_A_SLICE_3",
  "TX_B_SLICE_0",
  "TX_B_SLICE_1",
  "TX_B_SLICE_2",
  "TX_B_SLICE_3"
};


const cs_char8 *ten_gpllx1_mode_strings[] = {
  "GPLL_MODE_SFI42_40G",
  "GPLL_MODE_SFI42_10G",
  "GPLL_MODE_SFI41",
  "GPLL_MODE_XFI_4GFC",
  "GPLL_MODE_XFI_2GFC",
  "GPLL_MODE_XFI_1GFC",
  "GPLL_MODE_DEFAULT"
};

const cs_char8 *ten_deskew_strings[] = {
  "SADECO_DESKEW",
  "PP40G_BYPASS_DESKEW",
  "PP40G_DESKEW"
};


const cs_char8 *ten_xcon_es_num_strings[] = {
  "ELASTIC_STORE_0",
  "ELASTIC_STORE_1",
  "ELASTIC_STORE_2",
  "ELASTIC_STORE_3",
  "ELASTIC_STORE_4",
  "ELASTIC_STORE_5",
  "ELASTIC_STORE_6",
  "ELASTIC_STORE_7"
};

const cs_char8 *ten_xcon_input_strings[] = {
  "XCON_INPUT_0",
  "XCON_INPUT_1",
  "XCON_INPUT_2",
  "XCON_INPUT_3",
  "XCON_INPUT_4",
  "XCON_INPUT_5",
  "XCON_INPUT_6",
  "XCON_INPUT_7"
};


const cs_char8 *ten_xcon_es_mod_slice_strings[] = {
  "Module A Slice 0",
  "Module A Slice 1",
  "Module A Slice 2",
  "Module A Slice 3",
  "Module B Slice 0",
  "Module B Slice 1",
  "Module B Slice 2",
  "Module B Slice 3",
};

const cs_char8 *ten_nx0g_otnr_strings[] = {
  "NX0G_OTNR_OFSTAT_FSUSTS",
  "NX0G_OTNR_OFSTAT_SIF",
  "NX0G_OTNR_OFSTAT_SOOF",
  "NX0G_OTNR_OFSTAT_SLOF",
  "NX0G_OTNR_OFSTAT_SPHA",
  "NX0G_OTNR_OFSTAT_FST",
  "NX0G_OTNR_OFSTAT_PN11S"
};

const cs_char8 *ten_xcon_center_type_strings[] = {
  "XCON_AUTO_CENTER",
  "XCON_FORCE_CENTER",
  "XCON_RECENTER_LOWER",
  "XCON_RECENTER_UPPER",
  "XCON_PKT_CENTERING_ALL"
};

const cs_char8 *ten_pp10g_rx_mode_strings[] = {
  "PP10G_RX_DISABLE",
  "PP10G_RX_ETH_0",
  "PP10G_RX_ETH_2",
  "PP10G_RX_ETH_4",
  "PP10G_RX_GFP_S",
  "PP10G_RX_GFP_T",
  "PP10G_RX_ETH2_GFP_T",
  "PP10G_RX_ETH0_GFP_S",
  "PP10G_RX_XAUI_FC",
  "PP10G_RX_FC",
  "PP10G_RX_8FC",
  "PP10G_RX_XC_GE",
  "PP10G_RX_XC_FC",
  "PP10G_RX_ETH_4_RA",
  "PP10G_RX_FC_RA",
  "PP10G_RX_8FC_RA",
  "PP10G_RX_XAUI_ETH_4_RA",
  "PP10G_RX_XAUI_ETH2_GFP_T",
  "PP10G_RX_XAUI_FC_RA",
  "PP10G_RX_XAUI_ETH0_GFP_S",
  "PP10G_RX_MAX_MODE"
};

const cs_char8 *ten_pp10g_tx_mode_strings[] = {
  "PP10G_TX_DISABLE",
  "PP10G_TX_ETH_0",
  "PP10G_TX_ETH_2",
  "PP10G_TX_ETH_4",
  "PP10G_TX_GFP_S",
  "PP10G_TX_GFP_T",
  "PP10G_TX_GFP_T_ETH2",
  "PP10G_TX_GFP_S_ETH0",
  "PP10G_TX_XAUI_FC",
  "PP10G_TX_FC",
  "PP10G_TX_8FC",
  "PP10G_TX_XC_FC",
  "PP10G_TX_XC_GE",
  "PP10G_TX_XAUI_ETH_4",
  "PP10G_TX_XAUI_GFP_T_ETH2",
  "PP10G_TX_XAUI_GFP_S_ETH0",
  "PP10G_TX_MAX_MODE"
};


const cs_char8 *ten_mpif_n40g_n10g_strings[] = {
  "N40G_DATAPATH",
  "N10G_DATAPATH",
  "XAUI_DATAPATH"
};

const cs_char8 *ten_ohpp_signals_strings[] = {
  "OHPP_INSERT_ZERO",
  "OHPP_INSERT_AIS",
  "OHPP_INSERT_OCI",
  "OHPP_INSERT_LCK"
};

const cs_char8 *ten_ohpp_widths_strings[] = {
  "OHPP_WIDTH_ONLY_PAYLOAD",
  "OHPP_WIDTH_OH_PAYLOAD",
  "OHPP_WIDTH_FRAME"
};



const cs_char8 *ten_xcon_interface_strings[] = {
  "N10G",
  "PP10G"
};

const cs_char8 *ten_syncdsync_rx_div_mux_strings[] = {
  "Side A Slice 0",
  "Side A Slice 1",
  "Side A Slice 2",
  "Side A Slice 3",
  "Side B Slice 0",
  "Side B Slice 1",
  "Side B Slice 2",
  "Side B Slice 3",
};
