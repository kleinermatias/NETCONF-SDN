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
 * ten_stats.h
 *
 * $Id: ten_stats.h,v 1.12 2013/02/22 20:48:50 jccarlis Exp $
 *
 * This is a PUBLIC header file.
 * Enumeration labels for each individual statistic available.
 *
 */
 
#ifndef __TEN_STATS_H__
#define __TEN_STATS_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************
 * SYNCDSYNC Statistics  
 * Use TEN_ID_SYNCDSYNC as the block ID for these stats
 *****************************************************************/
enum ten_syncdsync_stats_e {
  TEN_SYNCDSYNC_CFGMON_ODTU23_PJO1_STAT  = 0,
  TEN_SYNCDSYNC_CFGMON_ODTU23_NJO1_STAT  = 1,
  TEN_SYNCDSYNC_CFGMON_OXUN_PJO1_STAT    = 2,
  TEN_SYNCDSYNC_CFGMON_OXUN_NJO1_STAT    = 3,
  TEN_SYNCDSYNC_MAX_STAT
};

/*****************************************************************
 * HSIF Statistics  
 * Use TEN_ID_HSIF as the block ID for these stats
 *****************************************************************/
enum ten_hsif_slc0_stats_e {
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_STAT = 0,
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK1_STAT = 1,
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK2_STAT = 2,
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK3_STAT = 3,
  TEN_HSIF_MR_SLC0_MAX_STAT
};

enum ten_hsif_slc1_stats_e {
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK0_STAT = 0,
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK1_STAT = 1,
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK2_STAT = 2,
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK3_STAT = 3,
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK4_STAT = 4,
  TEN_HSIF_MR_SLC1_MAX_STAT
};

enum ten_hsif_slc2_stats_e {
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_STAT = 0,
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK1_STAT = 1,
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK2_STAT = 2,
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK3_STAT = 3,
  TEN_HSIF_MR_SLC2_MAX_STAT
};

enum ten_hsif_slc3_stats_e {
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK0_STAT = 0,
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK1_STAT = 1,
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK2_STAT = 2,
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK3_STAT = 3,
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK4_STAT = 4,
  TEN_HSIF_MR_SLC3_MAX_STAT
};

enum ten_hsif_xfi_stats_e {
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK0_STAT = 0,
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK1_STAT = 1,
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK2_STAT = 2,
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK3_STAT = 3,
  TEN_HSIF_XFI_MAX_STAT
};
  
/* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
enum ten_CFP32X1_stats_e {
  TEN_CFP32X1_SDS_COMMON_PRBSCHK_STAT_SLICE_0 = 0,
  TEN_CFP32X1_SDS_COMMON_PRBSCHK_STAT_SLICE_1 = 1,
  TEN_CFP32X1_SDS_COMMON_PRBSCHK_STAT_SLICE_2 = 2,
  TEN_CFP32X1_SDS_COMMON_PRBSCHK_STAT_SLICE_3 = 3,
  TEN_HSIF_CFP_MAX_STAT
};

/*****************************************************************
 * XCON Statistics  
 * Use TEN_ID_XCON as the block ID for these stats
 *****************************************************************/
enum ten_xcon_stats_e {
  TEN_XCON_ES_FIFO_OVERFLOW_STAT      = 0,
  TEN_XCON_CBERT_PRBS_ERR_COUNT_STAT  = 1,
  TEN_XCON_PBERT_GOOD_UCNT_STAT       = 2,
  TEN_XCON_PBERT_GOOD_UOCNT_STAT      = 3,
  TEN_XCON_PBERT_RX_UERRCNT_STAT      = 4,
  TEN_XCON_PBERT_RX_UOERRCNT_STAT     = 5,
  TEN_XCON_PBERT_RX_PRBSERRCNT_STAT   = 6,
  TEN_XCON_MAX_STAT
};

/*****************************************************************
 * GFEC40G Statistics  
 * Use TEN_ID_GFEC_40G as the block ID for these stats
 *****************************************************************/
enum ten_gfec40g_stats_e {
TEN_GFEC40G_FRX40_RZBTER0_STAT = 0,
TEN_GFEC40G_FRX40_ROBTER0_STAT = 1,
TEN_GFEC40G_FRX40_RBYTER0_STAT = 2,
TEN_GFEC40G_FRX40_RERROV0_STAT = 3,
TEN_GFEC40G_MAX_STAT
};

/*****************************************************************
 * GFEC10G Statistics  
 * Use TEN_ID_GFEC_10G as the block ID for these stats
 *****************************************************************/
enum ten_gfec10g_stats_e {
  TEN_GFEC10G_FRX_RZBTER0_STAT = 0,
  TEN_GFEC10G_FRX_ROBTER0_STAT = 1,
  TEN_GFEC10G_FRX_RBYTER0_STAT = 2,
  TEN_GFEC10G_FRX_RERROV0_STAT = 3,
  TEN_GFEC10G_MAX_STAT
};

/*****************************************************************
 * UFEC Statistics  
 * Use TEN_ID_UFEC as the block ID for these stats
 *****************************************************************/
enum ten_ufec_stats_e {
  TEN_UFEC_URX_R1C00_STAT = 0,
  TEN_UFEC_URX_R1C10_STAT = 1,
  TEN_UFEC_URX_R1EO0_STAT = 2,
  TEN_UFEC_URX_C1C00_STAT = 3,
  TEN_UFEC_URX_C1C10_STAT = 4,
  TEN_UFEC_URX_C1EO0_STAT = 5,
  TEN_UFEC_URX_R2C00_STAT = 6,
  TEN_UFEC_URX_R2C10_STAT = 7,
  TEN_UFEC_URX_R2EO0_STAT = 8,
  TEN_UFEC_URX_C2C00_STAT = 9,
  TEN_UFEC_URX_C2C10_STAT = 10,
  TEN_UFEC_URX_C2EO0_STAT = 11,
  TEN_UFEC_URX_R3C00_STAT = 12,
  TEN_UFEC_URX_R3C10_STAT = 13,
  TEN_UFEC_URX_R3EO0_STAT = 14,
  TEN_UFEC_URX_TC00_STAT = 15,
  TEN_UFEC_URX_TC10_STAT = 16,
  TEN_UFEC_URX_TEO0_STAT = 17,
  TEN_UFEC_URX_MSYNCERRCNT_STAT = 18,
  TEN_UFEC_MAX_STAT
};

/*****************************************************************
 * N40G Statistics  
 * Use TEN_ID_N40G as the block ID for these stats
 *****************************************************************/
enum ten_n40g_stats_e {
  TEN_N40G_GBLR4X_PEC_STAT = 0,
  TEN_N40G_GBLR4X_FPCNT_STAT = 1,
  TEN_N40G_OTNR4X_LOFSTAT_STAT = 2,
  TEN_N40G_OTNR4X_OOFSTAT_STAT = 3,
  TEN_N40G_OTNR4X_PHASTAT_STAT = 4,
  TEN_N40G_SDFR_B1BTER_STAT = 5,
  TEN_N40G_SDFR_B1BLER_STAT = 6,
  TEN_N40G_SDFR_B2BTER_STAT = 7,
  TEN_N40G_SDFR_B2BLER_STAT = 8,
  TEN_N40G_SDFR_LOFEC_STAT = 9,
  TEN_N40G_SDFR_OOFEC_STAT = 10,
  TEN_N40G_OOHR_BIP0ERC1_STAT = 11,
  TEN_N40G_OOHR_BIP1ERC1_STAT = 12,
  TEN_N40G_OOHR_BIP2ERC1_STAT = 13,
  TEN_N40G_OOHR_BIP3ERC1_STAT = 14,
  TEN_N40G_OOHR_BIP4ERC1_STAT = 15,
  TEN_N40G_OOHR_BIP5ERC1_STAT = 16,
  TEN_N40G_OOHR_BIP6ERC1_STAT = 17,
  TEN_N40G_OOHR_BIP7ERC1_STAT = 18,
  TEN_N40G_OOHR_BEI0ERC1_STAT = 19,
  TEN_N40G_OOHR_BEI1ERC1_STAT = 20,
  TEN_N40G_OOHR_BEI2ERC1_STAT = 21,
  TEN_N40G_OOHR_BEI3ERC1_STAT = 22,
  TEN_N40G_OOHR_BEI4ERC1_STAT = 23,
  TEN_N40G_OOHR_BEI5ERC1_STAT = 24,
  TEN_N40G_OOHR_BEI6ERC1_STAT = 25,
  TEN_N40G_OOHR_BEI7ERC1_STAT = 26,
  TEN_N40G_MAX_STAT
};

/*****************************************************************
 * N10G Statistics  
 * Use TEN_ID_N10G as the block ID for these stats
 *****************************************************************/
enum ten_n10g_stats_e {
  TEN_N10G_GBLR_PEC_STAT = 0,
  TEN_N10G_GBLR_FPCNT_STAT = 1,
  TEN_N10G_OTNR_LOFSTAT_STAT = 2,
  TEN_N10G_OTNR_OOFSTAT_STAT = 3,
  TEN_N10G_OTNR_PHASTAT_STAT = 4,
  TEN_N10G_SDFR_B1BTER_STAT = 5,
  TEN_N10G_SDFR_B1BLER_STAT = 6,
  TEN_N10G_SDFR_B2BTER_STAT = 7,
  TEN_N10G_SDFR_B2BLER_STAT = 8,
  TEN_N10G_SDFR_LOFEC_STAT = 9,
  TEN_N10G_SDFR_OOFEC_STAT = 10,
  TEN_N10G_OOHR_BIP0ERC1_STAT = 11,
  TEN_N10G_OOHR_BIP1ERC1_STAT = 12,
  TEN_N10G_OOHR_BIP2ERC1_STAT = 13,
  TEN_N10G_OOHR_BIP3ERC1_STAT = 14,
  TEN_N10G_OOHR_BIP4ERC1_STAT = 15,
  TEN_N10G_OOHR_BIP5ERC1_STAT = 16,
  TEN_N10G_OOHR_BIP6ERC1_STAT = 17,
  TEN_N10G_OOHR_BIP7ERC1_STAT = 18,
  TEN_N10G_OOHR_BEI0ERC1_STAT = 19,
  TEN_N10G_OOHR_BEI1ERC1_STAT = 20,
  TEN_N10G_OOHR_BEI2ERC1_STAT = 21,
  TEN_N10G_OOHR_BEI3ERC1_STAT = 22,
  TEN_N10G_OOHR_BEI4ERC1_STAT = 23,
  TEN_N10G_OOHR_BEI5ERC1_STAT = 24,
  TEN_N10G_OOHR_BEI6ERC1_STAT = 25,
  TEN_N10G_OOHR_BEI7ERC1_STAT = 26,
  TEN_N10G_SOHR_M1BTER_STAT = 27,
  TEN_N10G_SOHR_M1BLER_STAT = 28,
  TEN_N10G_SOHR_PJINC1_STAT = 29,
  TEN_N10G_SOHR_PJINC2_STAT = 30,
  TEN_N10G_SOHR_PJINC3_STAT = 31,
  TEN_N10G_SOHR_PJDEC1_STAT = 32,
  TEN_N10G_SOHR_PJDEC2_STAT = 33,
  TEN_N10G_SOHR_PJDEC3_STAT = 34,
  TEN_N10G_SOHR_PNDF1_STAT = 35,
  TEN_N10G_SOHR_PNDF2_STAT = 36,
  TEN_N10G_SOHR_PNDF3_STAT = 37,
  TEN_N10G_SOHR_PNPT1_STAT = 38,
  TEN_N10G_SOHR_PNPT2_STAT = 39,
  TEN_N10G_SOHR_PNPT3_STAT = 40,
  TEN_N10G_POHR_B3BTER_STAT = 41,
  TEN_N10G_POHR_B3BLER_STAT = 42,
  TEN_N10G_POHR_REIPBTER_STAT = 43,
  TEN_N10G_POHR_REIPBLER_STAT = 44,
  TEN_N10G_MAX_STAT
};

/*****************************************************************
 * PP10G Statistics/PM Counters 
 * Use TEN_ID_PP10G as the block ID for these stats
 *****************************************************************/
enum ten_pp10g_stats_e {
  TEN_PP10G_MAC_DROP_RX_ALIGN_ERR_FRAMES_STAT                   = 0,
  TEN_PP10G_MAC_DROP_RX_CRC_ERR_FRAMES_STAT                     = 1,
  TEN_PP10G_MAC_RX_1024B_TO_1518B_FRAMES_STAT                   = 2,
  TEN_PP10G_MAC_RX_128B_TO_255B_FRAMES_STAT                     = 3,
  TEN_PP10G_MAC_RX_1519B_TO_MAXB_FRAMES_STAT                    = 4,
  TEN_PP10G_MAC_RX_256B_TO_511B_FRAMES_STAT                     = 5,
  TEN_PP10G_MAC_RX_512B_TO_1023B_FRAMES_STAT                    = 6,
  TEN_PP10G_MAC_RX_64B_FRAMES_STAT                              = 7,
  TEN_PP10G_MAC_RX_65B_TO_127B_FRAMES_STAT                      = 8,
  TEN_PP10G_MAC_RX_ALIGN_ERR_FRAMES_STAT                        = 9,
  TEN_PP10G_MAC_RX_BCAST_FRAMES_STAT                            = 10,
  TEN_PP10G_MAC_RX_CRC_ERR_FRAMES_STAT                          = 11,
  TEN_PP10G_MAC_RX_ERR_FRAMES_STAT                              = 12,
  TEN_PP10G_MAC_RX_FRAMES_STAT                                  = 13,
  TEN_PP10G_MAC_RX_GIANT_FRAMES_STAT                            = 14,
  TEN_PP10G_MAC_RX_GOOD_FRAMES_STAT                             = 15,
  TEN_PP10G_MAC_RX_JABBER_FRAMES_STAT                           = 16,
  TEN_PP10G_MAC_RX_MCAST_FRAMES_STAT                            = 17,
  TEN_PP10G_MAC_RX_PAUSE_FRAMES_STAT                            = 18,
  TEN_PP10G_MAC_RX_RUNT_FRAMES_STAT                             = 19,
  TEN_PP10G_MAC_RX_SHORT_FRAMES_STAT                            = 20,
  TEN_PP10G_MAC_RX_UCAST_FRAMES_STAT                            = 21,
  TEN_PP10G_MAC_RX_UNDERSIZE_FRAMES_STAT                        = 22,
  TEN_PP10G_MAC_TX_1024B_TO_1518B_FRAMES_STAT                   = 23,
  TEN_PP10G_MAC_TX_128B_TO_255B_FRAMES_STAT                     = 24,
  TEN_PP10G_MAC_TX_1519B_FRAMES_STAT                            = 25,
  TEN_PP10G_MAC_TX_256B_TO_511B_FRAMES_STAT                     = 26,
  TEN_PP10G_MAC_TX_512B_TO_1023B_FRAMES_STAT                    = 27,
  TEN_PP10G_MAC_TX_64B_FRAMES_STAT                              = 28,
  TEN_PP10G_MAC_TX_65B_TO_127B_FRAMES_STAT                      = 29,
  TEN_PP10G_MAC_TX_BCAST_FRAMES_STAT                            = 30,
  TEN_PP10G_MAC_TX_ERR_FRAMES_STAT                              = 31,
  TEN_PP10G_MAC_TX_FRAMES_STAT                                  = 32,
  TEN_PP10G_MAC_TX_GOOD_FRAMES_STAT                             = 33,
  TEN_PP10G_MAC_TX_MCAST_FRAMES_STAT                            = 34,
  TEN_PP10G_MAC_TX_PAUSE_DETECTED_FRAMES_STAT                   = 35,
  TEN_PP10G_MAC_TX_PAUSE_ERR_FRAMES_STAT                        = 36,
  TEN_PP10G_MAC_TX_PAUSE_FRAMES_STAT                            = 37,
  TEN_PP10G_MAC_TX_UCAST_FRAMES_STAT                            = 38,
  TEN_PP10G_MAC_RX_GOOD_OCTETS_STAT                             = 39,
  TEN_PP10G_MAC_RX_OCTETS_STAT                                  = 40,
  TEN_PP10G_MAC_TX_GOOD_OCTETS_STAT                             = 41,
  TEN_PP10G_MAC_TX_INSERTED_PAUSE_QUANTA_STAT                   = 42,
  TEN_PP10G_MAC_TX_OCTETS_STAT                                  = 43,
  TEN_PP10G_MAC_TX_TOTAL_PAUSE_QUANTA_STAT                      = 44,
  TEN_PP10G_RS_TX_TRUNK_FRAMES_STAT                             = 45,
  TEN_PP10G_PCS49_RX_ERR_FRAMES_STAT                            = 46,
  TEN_PP10G_PCS49_RX_GOOD_FRAMES_STAT                           = 47,
  TEN_PP10G_PCS49_TX_ERR_FRAMES_STAT                            = 48,
  TEN_PP10G_PCS49_TX_GOOD_FRAMES_STAT                           = 49,
  TEN_PP10G_PCS49_RX_ERR_BER_STAT                               = 50,
  TEN_PP10G_PCS49_RX_ERR_DEC_STAT                               = 51,
  TEN_PP10G_PCS49_RX_ERR_PAT_STAT                               = 52,
  TEN_PP10G_XAUI_RX_ERR_FRAMES_STAT                             = 53,
  TEN_PP10G_XAUI_RX_GOOD_FRAMES_STAT                            = 54,
  TEN_PP10G_XAUI_TX_ERR_FRAMES_STAT                             = 55,
  TEN_PP10G_XAUI_TX_GOOD_FRAMES_STAT                            = 56,
  TEN_PP10G_XAUI_RX_ICC_LN0_STAT                                = 57,
  TEN_PP10G_XAUI_RX_ICC_LN1_STAT                                = 58,
  TEN_PP10G_XAUI_RX_ICC_LN2_STAT                                = 59,
  TEN_PP10G_XAUI_RX_ICC_LN3_STAT                                = 60,
  TEN_PP10G_XAUI_RX_PEC_LN0_STAT                                = 61,
  TEN_PP10G_XAUI_RX_PEC_LN1_STAT                                = 62,
  TEN_PP10G_XAUI_RX_PEC_LN2_STAT                                = 63,
  TEN_PP10G_XAUI_RX_PEC_LN3_STAT                                = 64,
  TEN_PP10G_GFP_RX_CH_ERR_FRAMES_STAT                           = 65,
  TEN_PP10G_GFP_RX_CMF_FRAMES_STAT                              = 66,
  TEN_PP10G_GFP_RX_DISCARD_FRAMES_STAT                          = 67,
  TEN_PP10G_GFP_RX_EXM_FRAMES_STAT                              = 68,
  TEN_PP10G_GFP_RX_FCS_ERR_FRAMES_STAT                          = 69,
  TEN_PP10G_GFP_RX_GOOD_FRAMES_STAT                             = 70,
  TEN_PP10G_GFP_RX_LONG_FRAMES_STAT                             = 71,
  TEN_PP10G_GFP_RX_MCF_FRAMES_STAT                              = 72,
  TEN_PP10G_GFP_RX_PH_ERR_FRAMES_STAT                           = 73,
  TEN_PP10G_GFP_RX_PTM_FRAMES_STAT                              = 74,
  TEN_PP10G_GFP_RX_UPM_FRAMES_STAT                              = 75,
  TEN_PP10G_GFP_TX_CMF_FRAMES_STAT                              = 76,
  TEN_PP10G_GFP_TX_ERR_FRAMES_STAT                              = 77,
  TEN_PP10G_GFP_TX_GOOD_FRAMES_STAT                             = 78,
  TEN_PP10G_GFP_TX_MCF_FRAMES_STAT                              = 79,
  TEN_PP10G_GFP_RX_GOOD_OCTETS_STAT                             = 80,
  TEN_PP10G_GFP_RX_OCTETS_STAT                                  = 81,
  TEN_PP10G_GFP_TX_GOOD_OCTETS_STAT                             = 82,
  TEN_PP10G_GFP_TX_OCTETS_STAT                                  = 83,
  TEN_PP10G_FC_RX_CRC_ERR_FRAMES_STAT                           = 84,
  TEN_PP10G_FC_RX_GOOD_FRAMES_STAT                              = 85,
  TEN_PP10G_FC_RX_OVERSIZE_FRAMES_STAT                          = 86,
  TEN_PP10G_FC_RX_TOO_LONG_FRAMES_STAT                          = 87,
  TEN_PP10G_FC_RX_TOTAL_FRAMES_STAT                             = 88,
  TEN_PP10G_FC_RX_TRUNC_FRAMES_STAT                             = 89,
  TEN_PP10G_FC_RX_GOOD_OCTETS_STAT                              = 90,
  TEN_PP10G_FC_RX_PRIM_STAT                                     = 91,
  TEN_PP10G_FC_RX_R_RDY_STAT                                    = 92,
  TEN_PP10G_FC_RX_TOTAL_OCTETS_STAT                             = 93,
  TEN_PP10G_XCODE_RX_ERRCOR_SUPERBLOCKS_STAT                    = 94,
  TEN_PP10G_XCODE_RX_ERR_FRAMES_STAT                            = 95,
  TEN_PP10G_XCODE_RX_ERR_SUPERBLOCKS_STAT                       = 96,
  TEN_PP10G_XCODE_RX_FRAMES_STAT                                = 97,
  TEN_PP10G_XCODE_RX_GOOD_SUPERBLOCKS_STAT                      = 98,
  TEN_PP10G_XCODE_RX_LONG_FRAMES_STAT                           = 99,
  TEN_PP10G_XCODE_RX_SHORT_FRAMES_STAT                          = 100,
  TEN_PP10G_XCODE_TX_ERR_FRAMES_STAT                            = 101,
  TEN_PP10G_XCODE_TX_GOOD_FRAMES_STAT                           = 102,
  TEN_PP10G_XCODE_TX_GOOD_SUPERBLOCKS_STAT                      = 103,
  TEN_PP10G_XCODE_RX_OCTETS_STAT                                = 104,
  TEN_PP10G_XCODE_TX_ERR_CODEWORDS_STAT                         = 105,
  TEN_PP10G_XCODE_TX_ERR_SYNCWORDS_STAT                         = 106,
  TEN_PP10G_XCODE_TX_OCTETS_STAT                                = 107,
  TEN_PP10G_EGPCS_RX_ERR_FRAMES_STAT                            = 108,
  TEN_PP10G_EGPCS_RX_GOOD_FRAMES_STAT                           = 109,
  TEN_PP10G_EGPCS_TX_ERR_FRAMES_STAT                            = 110,
  TEN_PP10G_EGPCS_TX_GOOD_FRAMES_STAT                           = 111,
  TEN_PP10G_EGPCS_RX_TC_ERR_STAT                                = 112,
  TEN_PP10G_EGPCS_RX_TW_ERR_STAT                                = 113,
  TEN_PP10G_XGADJ_RX_DISCARDED_FRAMES_STAT                      = 114,
  TEN_PP10G_XGADJ_RX_ERRORED_FRAMES_STAT                        = 115,
  TEN_PP10G_XGADJ_RX_MICRO_EXTRACTED_FRAMES_STAT                = 116,
  TEN_PP10G_XGADJ_RX_TOTAL_FRAMES_STAT                          = 117,
  TEN_PP10G_XGADJ_TX_DISCARDED_FRAMES_STAT                      = 118,
  TEN_PP10G_XGADJ_TX_ERRORED_FRAMES_STAT                        = 119,
  TEN_PP10G_XGADJ_TX_MICRO_INSERTED_FRAMES_STAT                 = 120,
  TEN_PP10G_XGADJ_TX_TOTAL_FRAMES_STAT                          = 121,
  TEN_PP10G_XGADJ_RX_DISCARDED_IDLE_OCTETS_STAT                 = 122,
  TEN_PP10G_XGADJ_RX_DISCARDED_OCTETS_STAT                      = 123,
  TEN_PP10G_XGADJ_RX_DISCARDED_SEQUENCE_ORDERED_SETS_STAT       = 124,
  TEN_PP10G_XGADJ_RX_ERRORED_OCTETS_STAT                        = 125,
  TEN_PP10G_XGADJ_RX_MICRO_EXTRACTED_OCTETS_STAT                = 126,
  TEN_PP10G_XGADJ_RX_TOTAL_OCTETS_STAT                          = 127,
  TEN_PP10G_XGADJ_TX_DISCARDED_OCTETS_STAT                      = 128,
  TEN_PP10G_XGADJ_TX_ERRORED_OCTETS_STAT                        = 129,
  TEN_PP10G_XGADJ_TX_INSERTED_IDLE_OCTETS_STAT                  = 130,
  TEN_PP10G_XGADJ_TX_MICRO_INSERTED_OCTETS_STAT                 = 131,
  TEN_PP10G_XGADJ_TX_TOTAL_OCTETS_STAT                          = 132,
  /* New for T41 */
  /* Bugzilla #30084, PP10G_MON10B Stats - Good/Err Frames are switched */
  TEN_PP10G_MON10B_RX_GOOD_FRAMES                               = 0x85,
  TEN_PP10G_MON10B_RX_ERR_FRAMES                                = 0x86,
  TEN_PP10G_MON10B_RX_ERR_OCTETS                                = 0x87,
  TEN_PP10G_MON10B_RX_GOOD_OCTETS                               = 0x88,
  TEN_PP10G_MON10B_RX_SYMBOL_ERR                                = 0x89,
  TEN_PP10G_MAC_RX_BAD_OCTETS                                   = 0x8A,
  TEN_PP10G_MAC_TX_BAD_OCTETS                                   = 0x8B,
  TEN_PP10G_MAX_STAT
};
  
/*****************************************************************
 * PP40G Statistics/PM Counters
 * The block ID for these stats is TEN_ID_PP40G 
 * Most are accessed through one register set, and are defined in
 * the pp40g section of ten_registers_public.h
 *****************************************************************/
/* PM stats accessed indirectly through TEN_PP40G_PM_STATS_DATA regs.  */
/* Bugzilla 26168, stats registers added according to updates in t41_registers file. */

/* TEN_cntr_id_PCS_RX_ERR_AM_0                   0x00 */
/* TEN_cntr_id_PCS_RX_ERR_AM_1                   0x01 */
/* TEN_cntr_id_PCS_RX_ERR_AM_2                   0x02 */
/* TEN_cntr_id_PCS_RX_ERR_AM_3                   0x03 */
/* TEN_cntr_id_PCS_RX_ERR_BER                    0x04 */
/* TEN_cntr_id_PCS_RX_ERR_BIP_0                  0x05 */
/* TEN_cntr_id_PCS_RX_ERR_BIP_1                  0x06 */
/* TEN_cntr_id_PCS_RX_ERR_BIP_2                  0x07 */
/* TEN_cntr_id_PCS_RX_ERR_BIP_3                  0x08 */
/* TEN_cntr_id_PCS_RX_XC_ADJ_BIP_0               0x09 */
/* TEN_cntr_id_PCS_RX_XC_ADJ_BIP_1               0x0a */
/* TEN_cntr_id_PCS_RX_XC_ADJ_BIP_2               0x0b */
/* TEN_cntr_id_PCS_RX_XC_ADJ_BIP_3               0x0c */
/* TEN_cntr_id_PCS_RX_XC_ERR_1027B               0x0d */
/* TEN_cntr_id_PCS_RX_XC_ERR_513B                0x0e */
/* TEN_cntr_id_PCS_RX_ERR_DEC                    0x10 */
/* TEN_cntr_id_PCS_RX_ERR_PAT                    0x11 */
/* TEN_cntr_id_PCS_RX_ERR_SH_0                   0x12 */
/* TEN_cntr_id_PCS_RX_ERR_SH_1                   0x13 */
/* TEN_cntr_id_PCS_RX_ERR_SH_2                   0x14 */
/* TEN_cntr_id_PCS_RX_ERR_SH_3                   0x15 */
/* TEN_cntr_id_RX_RA_DISCARDED_OCTETS            0x16 */
/* TEN_cntr_id_TX_ADJ_BIP_0                      0x17 */
/* TEN_cntr_id_TX_ADJ_BIP_1                      0x18 */
/* TEN_cntr_id_TX_ADJ_BIP_2                      0x19 */
/* TEN_cntr_id_TX_ADJ_BIP_3                      0x1a */
/* TEN_cntr_id_TX_XC_ERR_BIP_0                   0x1b */
/* TEN_cntr_id_TX_XC_ERR_BIP_1                   0x1c */
/* TEN_cntr_id_TX_XC_ERR_BIP_2                   0x1d */
/* TEN_cntr_id_TX_XC_ERR_BIP_3                   0x1e */
/* TEN_cntr_id_TX_FIXED_AM                       0x20 */
/* TEN_cntr_id_TX_FIXED_BIP                      0x21 */
/* TEN_cntr_id_TX_RA_INSERTED_OCTETS             0x22 */
/* TEN_cntr_id_TX_XC_ERR_BT                      0x23 */
/* TEN_cntr_id_TX_XC_ERR_SH                      0x24 */
/* TEN_cntr_id_MAC40G_RX_1024B_TO_1518B_FRAMES   0x25 */
/* TEN_cntr_id_MAC40G_RX_128B_TO_255B_FRAMES     0x26 */
/* TEN_cntr_id_MAC40G_RX_1519B_TO_MAXB_FRAMES    0x27 */
/* TEN_cntr_id_MAC40G_RX_256B_TO_511B_FRAMES     0x28 */
/* TEN_cntr_id_MAC40G_RX_512B_TO_1023B_FRAMES    0x29 */
/* TEN_cntr_id_MAC40G_RX_64B_FRAMES              0x2a */
/* TEN_cntr_id_MAC40G_RX_65B_TO_127B_FRAMES      0x2b */
/* TEN_cntr_id_MAC40G_RX_ALIGN_ERR_FRAMES        0x2c */
/* TEN_cntr_id_MAC40G_RX_BCAST_FRAMES            0x2d */
/* TEN_cntr_id_MAC40G_RX_CRC_ERR_FRAMES          0x2e */
/* TEN_cntr_id_MAC40G_RX_ERR_FRAMES              0x2f */
/* TEN_cntr_id_MAC40G_RX_FRAMES                  0x30 */
/* TEN_cntr_id_MAC40G_RX_GIANT_FRAMES            0x31 */
/* TEN_cntr_id_MAC40G_RX_GOOD_FRAMES             0x32 */
/* TEN_cntr_id_MAC40G_RX_JABBER_FRAMES           0x33 */
/* TEN_cntr_id_MAC40G_RX_MCAST_FRAMES            0x34 */
/* TEN_cntr_id_MAC40G_RX_PAUSE_FRAMES            0x35 */
/* TEN_cntr_id_MAC40G_RX_RUNT_FRAMES             0x36 */
/* TEN_cntr_id_MAC40G_RX_SHORT_FRAMES            0x37 */
/* TEN_cntr_id_MAC40G_RX_UCAST_FRAMES            0x38 */
/* TEN_cntr_id_MAC40G_RX_UNDERSIZE_FRAMES        0x39 */
/* TEN_cntr_id_MAC40G_RX_BAD_OCTETS              0x3a */
/* TEN_cntr_id_MAC40G_RX_GOOD_OCTETS             0x3b */
/* TEN_cntr_id_MAC40G_RX_OCTETS                  0x3c */

 enum ten_pp40g_stats_e {
  TEN_PP40G_MAX_PM_STAT           = 0x03c,
  TEN_PP40G_PBERT40G_TX_FRMCNT    = 0x03d, /* name: FRMCNT2        0x1b0dc Frames Transmitted Counter                read this first, then 1, then 0, write 0,1,2. Write 0 to clear */
  TEN_PP40G_PBERT40G_TX_FRMOCTCNT = 0x03e, /* name: FRMOCTCNT2     0x1b0df Frame Octets Transmitted Counter          read this first, then 1, then 0, write 0,1,2. Write 0 to clear */

  TEN_PP40G_MAX_STAT              = 0x043
};
 
/* Bugzilla 26512, cfp stats moved to module stats in the hsif block */

#ifdef __cplusplus                                             
}  /* extern C */
#endif

#endif



