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
 * ten_xcon_data.h
 *
 * Data Header file for XCON block.
 *
 * $Id: ten_xcon_data.h,v 1.9 2013/02/22 20:48:11 jccarlis Exp $
 *
 */

#ifndef __TEN_XCON_DATA_H__
#define __TEN_XCON_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

#define XCON_TX_CHANNEL_ALL      0xFF
#define XCON_ELASTIC_STORE_ALL   0xFF
#define XCON_SADECO_ALL          0xFF
#define XCON_CAPTURE_RESULT_ALL  0xFF
    
/* Additions for T41 Amplitude Recentering */
#define TEN_XCON_AMP_RECENTER_MSEC_TIMEOUT (500)
/* Bugzilla #28471, minimum delay */
#define TEN_XCON_AMP_RECENTER_MSEC_DELAY   (1)

typedef enum {
  XCON_MODULE_A_CHANNEL_1,
  XCON_MODULE_A_CHANNEL_2,
  XCON_MODULE_A_CHANNEL_3,
  XCON_MODULE_A_CHANNEL_4,
  XCON_MODULE_B_CHANNEL_1,
  XCON_MODULE_B_CHANNEL_2,
  XCON_MODULE_B_CHANNEL_3,
  XCON_MODULE_B_CHANNEL_4
} ten_xcon_channel_num_t;

typedef enum {      /* Bugzilla 27270 Release 5.5 */
  XCON_ES_UPDATE_CB_FALSE = 0,
  XCON_ES_UPDATE_CB_TRUE
} ten_xcon_es_update_cb_t;


typedef enum {
  XCON_ELASTIC_STORE_0,
  XCON_ELASTIC_STORE_1,
  XCON_ELASTIC_STORE_2,
  XCON_ELASTIC_STORE_3,
  XCON_ELASTIC_STORE_4,
  XCON_ELASTIC_STORE_5,
  XCON_ELASTIC_STORE_6,
  XCON_ELASTIC_STORE_7
} ten_xcon_es_num_t;

typedef enum {
  XCON_TX_CHANNEL_0,
  XCON_TX_CHANNEL_1,
  XCON_TX_CHANNEL_2,
  XCON_TX_CHANNEL_3,
  XCON_TX_CHANNEL_4,
  XCON_TX_CHANNEL_5,
  XCON_TX_CHANNEL_6,
  XCON_TX_CHANNEL_7
} ten_xcon_tx_channel_t;

typedef enum {
  XCON_BERT_OFF,
  XCON_CBERT,
  XCON_PBERT
} ten_xcon_source_t;

typedef enum {
  XCON_N10G,
  XCON_PP10G
} ten_xcon_interface_t;

typedef enum {
  XCON_ES_IML_THRESH,
  XCON_ES_CIRCUIT_THRESHOLD_UPPER,
  XCON_ES_CIRCUIT_THRESHOLD_LOWER,
  /* T41 additions */
  XCON_ES_MARGIN_UPPER,
  XCON_ES_MARGIN_LOWER,
  XCON_ES_THRESHOLD_LEVEL,
  XCON_ES_PAUSE_LEVEL
} ten_xcon_circuit_threshold_t;

typedef enum {
  XCON_THRESHOLD_LEVEL_0,
  XCON_THRESHOLD_LEVEL_1,
  XCON_THRESHOLD_LEVEL_2,
  XCON_THRESHOLD_LEVEL_3,
  XCON_THRESHOLD_LEVEL_4,
  XCON_THRESHOLD_LEVEL_5
} ten_xcon_threshold_level_t;

/* Bugzilla 27270 Start, Amplitude Recentering, T41 release 5.4 */
typedef enum {
  TEN_XCON_ES_RECENTER_DEFAULT = 0,
  TEN_XCON_ES_RECENTER_IML,
  TEN_XCON_ES_RECENTER_AMP_10G,
  TEN_XCON_ES_RECENTER_AMP_40G,
  TEN_XCON_ES_RECENTER_FPA_10G,
  TEN_XCON_ES_RECENTER_FPA_40G,
  TEN_XCON_ES_RECENTER_OOR
} ten_xcon_recenter_type_t;

/* New for Release 5.5, Amplitude Recenter Recovery enum:           */
/*                                                                  */
/* Although this gets its own field in the XCON ES control block,   */
/* for backward compatibility with previous release APIs it must    */
/* be, for 5.3, bit OR'd with the LSB of the elastic store number,  */
/* and for release 5.4 APIs, bit-or'd with the upper byte of ten_   */
/* xcon_recenter_type_t and passed as the recenter 'type'           */
/* paramenter.                                                      */
/*                                                                  */
/* TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):                    */
/*   None for 5.3 APIs,                                             */
/*   AUTO for 5.4 APIs.                                             */
/* TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended): Framer and     */
/*   upper/lower ES violation event handlers kick off recenter,     */
/*   which completes using recenter status polling and system       */
/*   timers.                                                        */
/* TEN_XCON_ES_RECENTER_RECOVERY_INTP (Interrupt driven): The       */
/*   Framer event handlers kick off recenter. The recenter-complete */
/*   event handler completes it. Application code is responsible    */
/*   for enabling the required interrupts and registering their     */
/*   handlers as needed.                                            */
typedef enum {
  TEN_XCON_ES_RECENTER_RECOVERY_DFLT = 0x00,
  TEN_XCON_ES_RECENTER_RECOVERY_AUTO = 0x40,  
  TEN_XCON_ES_RECENTER_RECOVERY_INTP = 0x80,
  TEN_XCON_ES_RECENTER_RECOVERY_NONE = 0xC0,
  TEN_XCON_ES_RECENTER_RECOVERY_MASK = 0xC0
} ten_xcon_recenter_recovery_t;
/* Bugzilla 27270 End, Amplitude Recentering, T41 release 5.4 */

typedef enum {
  XCON_PAUSE_LEVEL_0,
  XCON_PAUSE_LEVEL_1
} ten_xcon_pause_wmark_level_t;

typedef enum {
  XCON_CAPTURE_RESULT_0,
  XCON_CAPTURE_RESULT_1,
  XCON_CAPTURE_RESULT_2,
  XCON_CAPTURE_RESULT_3,
  XCON_CAPTURE_RESULT_4,
  XCON_CAPTURE_RESULT_5,
  XCON_CAPTURE_RESULT_6,
  XCON_CAPTURE_RESULT_7
} ten_xcon_capture_result_t;

typedef enum {
  XCON_MODE_CUT_THRU,
  XCON_MODE_STORE_FWD
} ten_xcon_sf_mode_t;

typedef enum {
  XCON_MODE_CCT,
  XCON_MODE_PKT
} ten_xcon_pkt_mode_t;

typedef enum {
  XCON_PBERT_PROFILE_ETH_0,
  XCON_PBERT_PROFILE_ETH_1,
  XCON_PBERT_PROFILE_ETH_2,
  XCON_PBERT_PROFILE_ETH_3,
  XCON_PBERT_PROFILE_ETH_4,
  XCON_PBERT_PROFILE_GFP_S,
  XCON_PBERT_PROFILE_GFP_T_FC,
  XCON_PBERT_PROFILE_FC
} ten_xcon_pbert_profile_t;

typedef enum {
  XCON_TRAFFIC_FRAME,
  XCON_TRAFFIC_ORDERED_SETS
} ten_xcon_traffic_type_t;

typedef enum {
  XCON_SOF_CONNECT_CLASS1,
  XCON_SOF_INITIATE_CLASS1,
  XCON_SOF_NORMAL_CLASS1,
  XCON_SOF_INITIATE_CLASS2,
  XCON_SOF_NORMAL_CLASS2,
  XCON_SOF_INITIATE_CLASS3,
  XCON_SOF_NORMAL_CLASS3,
  XCON_SOF_ACTIVATE_CLASS4,
  XCON_SOF_INITIATE_CLASS4,
  XCON_SOF_NORMAL_CLASS4,
  XCON_SOF_FABRIC
} ten_xcon_fc_sof_t;

typedef enum {
  XCON_EOF_TERMINATE,
  XCON_EOF_DISCON_TERMINATE,
  XCON_EOF_NORM_TERMINATE,
  XCON_EOF_REMOVE_TERMINATE,
  XCON_EOF_ABORT,
  XCON_EOF_DISCON_TERMINATE_INVLD_CLASS,
  XCON_EOF_NORMAL_TERMINATE_INVLD_CLASS,
  XCON_EOF_REMOVE_TERMINATE_INVLD_CLASS
} ten_xcon_fc_eof_t;

typedef enum {
  XCON_DA_UCAST,
  XCON_DA_MCAST,
  XCON_DA_BCAST
} ten_xcon_da_type_t;

typedef enum {
  XCON_PAYLOAD_FIXED,
  XCON_PAYLOAD_PRBS
} ten_xcon_payload_type_t;

typedef enum {
  XCON_XGMII_ENC,
  XCON_64B_66B_ENC
} ten_xcon_encoding_t;

typedef enum {
  XCON_DATA_CHAR,
  XCON_CTRL_CHAR
} ten_xcon_ctrl_code_t;

typedef enum {
  XCON_FIXED_PATTERN_01,
  XCON_FIXED_PATTERN_23,
  XCON_FIXED_PATTERN_45,
  XCON_FIXED_PATTERN_67
} ten_xcon_fixed_pattern_t;

typedef enum {
  XCON_UNIT_LEN_RANDOM,
  XCON_UNIT_LEN_LINEAR
} ten_xcon_len_mode_t;

typedef enum {
  XCON_IFG_SYMBOL_IDLE,
  XCON_IFG_SYMBOL_ARBFF
} ten_xcon_ifg_symbol_t;

typedef enum {
  XCON_CONTINUOUS_PRBS_ERROR,
  XCON_SINGLE_PRBS_ERROR,
  XCON_CONTINUOUS_FCS_ERROR,
  XCON_SINGLE_FCS_ERROR
} ten_xcon_error_type_t;

typedef enum {
  XCON_FP,
  XCON_MFP
} ten_xcon_mfp_mode_t;

typedef enum {
  XCON_NO_GFP,
  XCON_GFP
} ten_xcon_gfp_mode_t;

typedef enum {
  XCON_AUTO_CENTER,
  XCON_FORCE_CENTER,
  XCON_RECENTER_LOWER,
  XCON_RECENTER_UPPER,
  XCON_PKT_CENTERING_ALL
} ten_xcon_center_type_t;

typedef enum {
  XCON_PRBS_POLY_DEGREE_07,
  XCON_PRBS_POLY_DEGREE_15,
  XCON_PRBS_POLY_DEGREE_23,
  XCON_PRBS_POLY_DEGREE_31
} ten_xcon_prbs_poly_t;

typedef enum {
  XCON_SADECO_0,
  XCON_SADECO_1
} ten_xcon_sadeco_num_t;

typedef enum {
  XCON_SONET_SDH_INACTIVE = 0,
  XCON_SONET_SDH_16 = 1,
  XCON_SONET_SDH_64 = 2 
} ten_xcon_sadeco_fp_type_t;

typedef enum {
  XCON_BLOCK_RESET,
  XCON_FIFO_RESET
} ten_xcon_sadeco_blk_reset_t;

typedef enum {
  XCON_SEQNUM_RESET,
  XCON_SEQNUM_RESYNC_DSBL,
  XCON_SEQNUM_RESYNC_ENBL
} ten_xcon_seqnum_ctrl_t;

typedef enum {
  XCON_ES_RECENTER_ACCUMULATE_EN,
  XCON_ES_RECENTER_AMPLITUDE_RECENTER_EN, 
  XCON_ES_RECENTER_FP_ALIGN_EN, 
  XCON_ES_RECENTER_LOWER_VIOLATION_EN, 
  XCON_ES_RECENTER_UPPER_VIOLATION_EN, 
  XCON_ES_RECENTER_TX_DRAIN_EN, 
  XCON_ES_RECENTER_STATIC_DEPTH_EN, 
  XCON_ES_RECENTER_DEPTH_CAPTURE_EN, 
  XCON_ES_RECENTER_MEASURE_EN, 
  XCON_ES_RECENTER_AMPLITUDE_ADJUST_EN, 
  XCON_ES_RECENTER_REPLACE_STALE_EN
} ten_xcon_es_recenter_enables_t;

typedef enum {
  XCON_ES_RECENTER_IML,
  XCON_ES_RECENTER_AMPLITUDE
} ten_xcon_es_recenter_circuit_types_t;

typedef enum {
  XCON_ES_RECENTER_RATE_ADAPT,
  XCON_ES_RECENTER_RATE_ADJUST
} ten_xcon_es_recenter_packet_types_t;

typedef enum {
  XCON_ES_CONFIG_PKT_MODE,
  XCON_ES_CONFIG_SF_MODE,
  XCON_ES_CONFIG_GFP_MODE,
  XCON_ES_CONFIG_AUTO_RECENTER_LOWER,
  XCON_ES_CONFIG_AUTO_RECENTER_UPPER,
  XCON_ES_CONFIG_AUTO_CENTER,
  XCON_ES_CONFIG_FORCE_CENTER,
  XCON_ES_CONFIG_MFP_MODE,
  XCON_ES_CONFIG_FLAG_ECCERR,
  XCON_ES_CONFIG_DROP_ON_ERR,
  XCON_ES_CONFIG_PP10G_LF_RECENTER_EN,
  XCON_ES_CONFIG_PP10G_RF_RECENTER_EN,
  XCON_ES_CONFIG_CPU_PTR_CFG,
  XCON_ES_CONFIG_ECC_INJ_FORWARDINGBUFF_ERR,
  XCON_ES_CONFIG_ECC_INJ_DATABUFF_ERR,
  XCON_ES_CONFIG_ECC_ERR_TYPE
} ten_xcon_es_config_t;

typedef enum {
  XCON_GLB_PP40G_CFG_FLTSRC,
  XCON_GLB_PP40G_CFG_RESET,
  XCON_GLB_PP40G_CFG_RECENTER,
  XCON_GLB_PP40G_CFG_TX_ALGN_EN,
  XCON_GLB_PP40G_CFG_LF_DIS,
  XCON_GLB_PP40G_CFG_RF_DIS,
  XCON_GLB_PP40G_CFG_IDLE_DIS
} ten_xcon_glb_pp40g_cfg_t;

typedef enum {
  XCON_ES_RX_THRESHOLD,
  XCON_PP_ES_PAUSE_THRESHOLD,
  XCON_SELECT_ES_PAUSE_QUANTA_SOURCE
} ten_xcon_threshold_select_types_t;

typedef enum  {
  TEN_XCON_ES_INTR_FIFO_OVERFLOW_CNT_OV = 0x0001,
  TEN_XCON_ES_INTR_FFIFO_SINGLE_ERR     = 0x0010,
  TEN_XCON_ES_INTR_FFIFO_DOUBLE_ERR     = 0x0020,
  TEN_XCON_ES_INTR_DFIFO_SINGLE_ERR     = 0x0040,
  TEN_XCON_ES_INTR_DFIFO_DOUBLE_ERR     = 0x0080,
  TEN_XCON_ES_INTR_SYNC_CHANGE          = 0x0100, 
  TEN_XCON_ES_INTR_SYNC_LOST            = 0x2000,
  TEN_XCON_ES_INTR_OVERFLOW             = 0x0800,   
  TEN_XCON_ES_INTR_RECENTER             = 0x1000,   
  TEN_XCON_ES_INTR_LOWER_VIOLATION      = 0x2000,   
  TEN_XCON_ES_INTR_UPPER_VIOLATION      = 0x4000,    
  TEN_XCON_ES_INTR_AMPLITUDE_RECENTER   = 0x8000,
  TEN_XCON_ES_INTR_ALL                  = 0xFFF1
} ten_xcon_es_intr_enums;

#ifdef __cplusplus
}
#endif
#endif /* __TEN_XCON_DATA_H__ */
