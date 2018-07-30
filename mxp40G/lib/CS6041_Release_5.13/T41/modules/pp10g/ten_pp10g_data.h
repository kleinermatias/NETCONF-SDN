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
 * ten_pp10g_data.h
 *
 * $Id: ten_pp10g_data.h,v 1.12 2013/02/22 20:48:04 jccarlis Exp $
 *
 */

#ifndef __TEN_PP10G_DATA_H__
#define __TEN_PP10G_DATA_H__
   
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#define TEN_PP10G_MSEC_TIMEOUT 50
#define TEN_PP10G_MSEC_DELAY   10

#define TEN_PP40G_MSEC_TIMEOUT 50
#define TEN_PP40G_MSEC_DELAY   10

/* Bug 31054 Start: 10GFC XCODE Remap G.709 Compliance */
#define TEN_PP10G_XCODE_REMAP_INDEX_MAX 16
/* Bug 31054 End: 10GFC XCODE Remap G.709 Compliance */

enum pp10g_xgadj_rx_extr_e {
  TEN_PP10G_XGADJ_RX_EXTR_STATUS_OVR_SIZE = 1,
  TEN_PP10G_XGADJ_RX_EXTR_STATUS_ERR = 2,
  TEN_PP10G_XGADJ_RX_EXTR_STATUS_FLEN = 3,
  TEN_PP10G_XGADJ_RX_EXTR_STATUS_ALL = 0xFF
};

enum ten_pp10g_psc_rx_e {
  TEN_PP10G_PCS_RX_PATSYNCS =       0,
  TEN_PP10G_PCS_RX_BERHIGHS =       1,
  TEN_PP10G_PCS_RX_SYNCDETS =       2,
  TEN_PP10G_PCS_RX_ALL      =       0xFF
};

enum ten_pp10g_rs_tx_e {
  TEN_PP10G_RS_TX_UNDERFLOW =       0,
  TEN_PP10G_RS_TX_OVERFLOW  =       1,
  TEN_PP10G_RS_TX_ALL       =       0xFF
};

enum pp10g_rs_rx_e {
  TEN_PP10G_RS_RX_STATUS_RFS = 1,
  TEN_PP10G_RS_RX_STATUS_LFS = 2,
  TEN_PP10G_RS_RX_STATUS_UNKNOWNORDS = 3,
  TEN_PP10G_RS_RX_STATUS_REMOTEORDS = 4,
  TEN_PP10G_RS_RX_STATUS_LOCALORDS = 5,
  TEN_PP10G_RS_RX_STATUS_ALL = 0xFF
};

enum ten_pp10g_xaui_rx_e {
  TEN_PP10G_XAUI_RX_LOCALFAULT     = 0,
  TEN_PP10G_XAUI_RX_REMOTEFAULT    = 1,
  TEN_PP10G_XAUI_RX_XGXS_CPAT_LOCK = 2,
  TEN_PP10G_XAUI_RX_XGXS_ALIGN_DET = 3,
  TEN_PP10G_XAUI_RX_SYNCDET3       = 4,
  TEN_PP10G_XAUI_RX_SYNCDET2       = 5,
  TEN_PP10G_XAUI_RX_SYNCDET1       = 6,
  TEN_PP10G_XAUI_RX_SYNCDET0       = 7,
  TEN_PP10G_XAUI_RX_ALL            = 0xFF
};

enum ten_pp10g_xaui_tx_e {
  TEN_PP10G_XAUI_TX_UNDERFLOW        =  0,
  TEN_PP10G_XAUI_TX_BYPASS_UNDERFLOW =  1,
  TEN_PP10G_XAUI_TX_BYPASS_OVERFLOW  =  2,
  TEN_PP10G_XAUI_TX_ALL              =  0xFF
};

enum ten_pp10g_gfp_rx_e {
  TEN_PP10G_GFP_RX_STATUS_PTMS =               1,
  TEN_PP10G_GFP_RX_STATUS_UPMS =               2,
  TEN_PP10G_GFP_RX_STATUS_EXMS =               3,
  TEN_PP10G_GFP_RX_STATUS_RDIS =               4,
  TEN_PP10G_GFP_RX_STATUS_FDIS =               5,
  TEN_PP10G_GFP_RX_STATUS_CSFS =               6,
  TEN_PP10G_GFP_RX_STATUS_LFDS =               7,
  TEN_PP10G_GFP_RX_STATUS_ALL  =               0xFF
};

enum ten_pp10g_fc_rx_e {
  TEN_PP10G_FC_RX_STATUS_PRIM_RSVDS      =    1,
  TEN_PP10G_FC_RX_STATUS_PRIM_LPE_Y_XS   =    2,
  TEN_PP10G_FC_RX_STATUS_PRIM_LPE_F_XS   =    3,
  TEN_PP10G_FC_RX_STATUS_PRIM_LPB_Y_XS   =    4,
  TEN_PP10G_FC_RX_STATUS_PRIM_LPB_F_XS   =    5,
  TEN_PP10G_FC_RX_STATUS_PRIM_LIP_Y_XS   =    6,
  TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F_XS   =    7,
  TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F8_XS  =    8,
  TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F7_XS  =    9,
  TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F8_F7S =   10,
  TEN_PP10G_FC_RX_STATUS_PRIM_LIP_F7_F7S =   11,
  TEN_PP10G_FC_RX_STATUS_PRIM_RFS        =   12,
  TEN_PP10G_FC_RX_STATUS_PRIM_LFS        =   13,
  TEN_PP10G_FC_RX_STATUS_PRIM_LRRS       =   14,
  TEN_PP10G_FC_RX_STATUS_PRIM_LRS        =   15,
  TEN_PP10G_FC_RX_STATUS_PRIM_OLSS       =   16,
  TEN_PP10G_FC_RX_STATUS_ALL             =   0xFF
};

enum ten_pp10g_xgadj_tx_e {
  TEN_PP10G_XGADJ_TX_STATUS_UNDERFLOW =          1,
  TEN_PP10G_XGADJ_TX_STATUS_OVERFLOW  =          2,
  TEN_PP10G_XGADJ_TX_STATUS_ALL       =          0xFF
};

enum ten_pp10g_xgadj_rx_e {
  TEN_PP10G_XGADJ_RX_STATUS_UNDERFLOW =          1,
  TEN_PP10G_XGADJ_RX_STATUS_OVERFLOW  =          2,
  TEN_PP10G_XGADJ_RX_STATUS_ALL       =          0xFF
};

enum ten_pp10g_flow_control_e {
  TEN_PP10G_FLOW_PROTOCOL_GFP_S_P =     0,
  TEN_PP10G_FLOW_PROTOCOL_GFP_S   =     1,
  TEN_PP10G_FLOW_PROTOCOL_ETH_4   =     2,
  TEN_PP10G_FLOW_PROTOCOL_ETH_4_P =     3
};

enum ten_pp10g_rx_protocol_e {
  TEN_PP10G_RX_PROTOCOL_ETH_0      =    0,
  TEN_PP10G_RX_PROTOCOL_ETH_2      =    1,
  TEN_PP10G_RX_PROTOCOL_ETH_4      =    2,
  TEN_PP10G_RX_PROTOCOL_GFP_S      =    3,
  TEN_PP10G_RX_PROTOCOL_GFP_T      =    4,
  TEN_PP10G_RX_PROTOCOL_ETH2_GFP_T =    5,
  TEN_PP10G_RX_PROTOCOL_ETH0_GFP_S =    6,
  TEN_PP10G_RX_PROTOCOL_XAUI_FC    =    7,
  TEN_PP10G_RX_PROTOCOL_FC         =    8,
  TEN_PP10G_RX_PROTOCOL_8FC        =    9,
  TEN_PP10G_RX_PROTOCOL_XC_FC      =    10,
  TEN_PP10G_RX_PROTOCOL_XC_GE      =    11,
  TEN_PP10G_RX_PROTOCOL_ETH_4_RA   =    12,
  TEN_PP10G_RX_PROTOCOL_FC_RA      =    13,
  TEN_PP10G_RX_PROTOCOL_8FC_RA     =    14
};

enum ten_pp10g_tx_protocol_e {
  TEN_PP10G_TX_PROTOCOL_ETH_0      =    0,
  TEN_PP10G_TX_PROTOCOL_ETH_2      =    1,
  TEN_PP10G_TX_PROTOCOL_ETH_4      =    2,
  TEN_PP10G_TX_PROTOCOL_GFP_S      =    3,
  TEN_PP10G_TX_PROTOCOL_GFP_T      =    4,
  TEN_PP10G_TX_PROTOCOL_GFP_T_ETH2 =    5,
  TEN_PP10G_TX_PROTOCOL_GFP_S_ETH0 =    6,
  TEN_PP10G_TX_PROTOCOL_XAUI_FC    =    7,
  TEN_PP10G_TX_PROTOCOL_FC         =    8,
  TEN_PP10G_TX_PROTOCOL_8FC        =    9,
  TEN_PP10G_TX_PROTOCOL_XC_FC      =    10,
  TEN_PP10G_TX_PROTOCOL_XC_GE      =    11 
};

enum ten_pp10g_rs_tx_sreset_enums {
  TEN_PP10G_RS_TX_SRESET_SYSTX_LOGICRESET = 0x4000,
  TEN_PP10G_RS_TX_SRESET_TX_LOGICRESET    = 0x8000,
  TEN_PP10G_RS_TX_SRESET_ALL              = 0xC000
};

enum ten_pp10g_funcen_enums {
  TEN_PP10G_FUNCEN_XGPCS     = 0,
  TEN_PP10G_FUNCEN_GFP       = 1,
  TEN_PP10G_FUNCEN_BASEX     = 2,
  TEN_PP10G_FUNCEN_EGPCS     = 3,
  TEN_PP10G_FUNCEN_XCODE     = 4,
  TEN_PP10G_FUNCEN_MAC       = 5,
  TEN_PP10G_FUNCEN_BYPASS    = 6,
  TEN_PP10G_FUNCEN_FC        = 7,
  TEN_PP10G_FUNCEN_MON10B    = 8,
  TEN_PP10G_FUNCEN_BER10B    = 9,
  TEN_PP10G_FUNCEN_MAX
};

enum ten_pp10g_xgadj_fillctrl_enums {
  TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT  = 0,
  TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE     = 1,
  TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE       = 2,
  TEN_PP10G_XGADJ_FILLCTRL_FILL_CONTROL      = 3
};

enum ten_pp10g_gfp_cmf_rx_enums {
  TEN_PP10G_GFP_RX_CMF_ENABLE = 0,
  TEN_PP10G_GFP_RX_CMF_RDI    = 1,
  TEN_PP10G_GFP_RX_CMF_FDI    = 2,
  TEN_PP10G_GFP_RX_CMF_DCI    = 3
};

enum ten_pp10g_pcs_rx_synoff {
  TEN_PP10G_PCS_RX_SYNOFF_SYNC_BER     = 0,
  TEN_PP10G_PCS_RX_SYNOFF_SYNC_INVALID = 1,
  TEN_PP10G_PCS_RX_SYNOFF_SYNC_VALID   = 2
};

enum ten_pp10g_gfp_blocks_per_superblocks_e {
  TEN_8_BLOCKS_PER_SUPERBLOCK_CRC24  = 0,
  TEN_28_BLOCKS_PER_SUPERBLOCK_CRC4  = 1,
  TEN_32_BLOCKS_PER_SUPERBLOCK_NOCRC = 2
};

enum ten_pp10g_gfp_reserved_octets_e {
  TEN_16_RES_OCTETS = 0,
  TEN_12_RES_OCTETS = 1,
  TEN_8_RES_OCTETS  = 2,
  TEN_4_RES_OCTETS  = 3
};

enum ten_10ge_tc_frame_format_e {
  TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4  = 0,
  TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4 = 1,
  TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC = 2,
  TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC = 3
};

/* T41 additions */
enum ten_pp10g_rx_alarms_t41 {
  TEN_PP10G_ALARMS_HSIF_OK         =  0x0001,
  TEN_PP10G_ALARMS_N10G_OK         =  0x0002,
  TEN_PP10G_ALARMS_XGGFP_LFD       =  0x0004,
  TEN_PP10G_ALARMS_XGGFP_CSF       =  0x0008,
  TEN_PP10G_ALARMS_XGGFP_FDI       =  0x0010,
  TEN_PP10G_ALARMS_XGGFP_RDI       =  0x0020,
  TEN_PP10G_ALARMS_XGGFP_UPM       =  0x0040,
  TEN_PP10G_ALARMS_XGPCS_SYNC      =  0x0080,
  TEN_PP10G_ALARMS_XGPCS_HIBER     =  0x0100,
  TEN_PP10G_ALARMS_EGPCS_SYNC      =  0x0200,
  TEN_PP10G_ALARMS_BASEX_SYNC_ALL  =  0x0400,
  TEN_PP10G_ALARMS_BASEX_ALIGN     =  0x0800
};

enum ten_pp10g_tx_actions_t41 {
  TEN_PP10G_ACTIONS_FWD_LF_EN      =  0x0001,
  TEN_PP10G_ACTIONS_FORCE_FWD_LF   =  0x0002,
  TEN_PP10G_ACTIONS_FWD_LF_CODE0   =  0x0004,
  TEN_PP10G_ACTIONS_FWD_LF_CODE1   =  0x0008,
  TEN_PP10G_ACTIONS_FWD_RF_EN      =  0x0010,
  TEN_PP10G_ACTIONS_FORCE_FWD_RF   =  0x0020,
  TEN_PP10G_ACTIONS_LINKFAULT_DIS  =  0x0040,
  TEN_PP10G_ACTIONS_PROTECT_LF_EN  =  0x0080
};

/* Bugzilla 29609 Start */
enum ten_pp10g_pcs_rx_rxint_t41 {
  TEN_PP10G_PCS_RX_RXINT_ERRORPKTI = 0x0001, 
  TEN_PP10G_PCS_RX_RXINT_ERRORDECI = 0x0008,
  TEN_PP10G_PCS_RX_RXINT_ERRORPATI = 0x0020,
  TEN_PP10G_PCS_RX_RXINT_SYNCDETI  = 0x0100,
  TEN_PP10G_PCS_RX_RXINT_BERHIGHI  = 0x0200,
  TEN_PP10G_PCS_RX_RXINT_PATSYNCI  = 0x0400
};
/* Bugzilla 29609 End */

#ifdef __cplusplus                                             
}  /* extern C */
#endif
#endif



