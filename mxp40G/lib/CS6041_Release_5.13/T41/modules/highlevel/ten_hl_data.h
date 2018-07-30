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
 * ten_hl_data.h
 *
 * Data Header file for High Level Configs.
 *
 * $Id: ten_hl_data.h,v 1.26 2013/02/22 20:44:11 jccarlis Exp $
 *
 */

#ifndef __TEN_HL_DATA_H__
#define __TEN_HL_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

extern const cs_char8 ten_hsif_gram_table_version[];

#define TEN_HSIF_GRAM_ROWS_MAX 576
#define TEN_HSIF_GRAM_COLS_MAX 3

enum gpllx1_configs_e {
  TEN_GPLLX1_CONFIG1 = 0,
  TEN_GPLLX1_CONFIG2 = 1
};

enum hsif_dividers_e {
  TEN_HSIF_CKREFDIV1 = 0,
  TEN_HSIF_CKREFDIV2 = 1,
  TEN_HSIF_CKREFDIV4 = 2
};

enum hsif_xfi_rates_e {
  TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5  = 0,  /* Full Rate, div=64,16    */
  TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25  = 1,  /* 1/2 Rate,  div=64,80,40 */
  TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125 = 2,  /* 1/4 Rate,  div=64,80,40 */
  TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56  = 3,  /* 1/8 Rate,  div=64,80,40 */ 
  TEN_HSIF_XFI_RATE_GBPS_8__5_FC         = 4,  /* Full Rate Fiber Channel, div=64,80,40 */
  TEN_HSIF_XFI_RATE_GBPS_4__25_FC        = 5,  /* 1/2 Rate Fiber Channel,  div=64,80,40 */
  TEN_HSIF_XFI_RATE_GBPS_2__125_FC       = 6,  /* 1/4 Rate Fiber Channel,  div=64,80,40 */
  TEN_HSIF_XFI_RATE_GBPS_1__0625_FC      = 7,  /* 1/8 Rate Fiber Channel,  div=64,80,40 */
  TEN_HSIF_XFI_RATE_GBPS_9__95328        = 8,  /* Full Rate, div=64,16    */
  TEN_HSIF_XFI_RATE_GBPS_10__3125        = 9,  /* Full Rate, div=64,16    */
  TEN_HSIF_XFI_RATE_GBPS_10__52          = 10, /* Full Rate, div=64,16    */
  TEN_HSIF_XFI_RATE_GBPS_10__70          = 11, /* Full Rate, div=64,16    */
  TEN_HSIF_XFI_RATE_GBPS_11__1           = 12, /* Full Rate, div=64,16    */
  TEN_HSIF_XFI_RATE_GBPS_11__3           = 13, /* Full Rate, div=64,16    */
  TEN_HSIF_XFI_RATE_GBPS_11__7           = 14, /* Full Rate, div=64,16    */
  TEN_HSIF_XFI_RATE_GBPS_12__5           = 15, /* Full Rate, div=64,16    */
  TEN_HSIF_XFI_RATE_GBPS_5_IB            = 16, /* 1/2,  div=64,80,40      */
  TEN_HSIF_XFI_RATE_GBPS_10_IB           = 17  /* Full Rate, div=64,16    */
};

enum hsif_xfi_div_by_ref_e {
  TEN_HSIF_XFI_DIV_BY_16_REF = 0, 
  TEN_HSIF_XFI_DIV_BY_40_REF = 1, 
  TEN_HSIF_XFI_DIV_BY_64_REF = 2, 
  TEN_HSIF_XFI_DIV_BY_80_REF = 3,
  TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF = 4,
  TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF = 5,
  TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF = 6,
  TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF = 7,
  TEN_HSIF_XFI_DIV_BY_32_REF = 8,             /* Bugzilla #20384, add div 32     */
  TEN_HSIF_XFI_DIV_BY_66_REF = 9,             /* Bugzilla #23872, add other divs */
  TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF = 10,
  TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF = 11,
  TEN_HSIF_XFI_DIV_BY_MAX_PARM 
};

enum hsif_cfp_div_by_ref_e {
  TEN_HSIF_CFP_DIV_BY_16_REF = 0, 
  TEN_HSIF_CFP_DIV_BY_32_REF = 1, 
  TEN_HSIF_CFP_DIV_BY_64_REF = 2, 
  TEN_HSIF_CFP_DIV_BY_66_REF = 3, 
  TEN_HSIF_CFP_DIV_BY_40_REF = 4, 
  TEN_HSIF_CFP_DIV_BY_80_REF = 5,
  TEN_HSIF_CFP_DIV_BY_MAX_PARM 
};

enum hsif_protocols_e {
  TEN_HSIF_PROTOCOL_DISABLED = 0,
  TEN_HSIF_PROTOCOL_SFI51 = 1,
  TEN_HSIF_PROTOCOL_SFI41 = 2,
  TEN_HSIF_PROTOCOL_XFI = 3,
  TEN_HSIF_PROTOCOL_SFI42_10G = 4,
  TEN_HSIF_PROTOCOL_SFI42_40G = 5,
  TEN_HSIF_PROTOCOL_XAUI = 6,
  /* Bugzilla 24360 Start */
  TEN_HSIF_PROTOCOL_CFP = 7
  /* Bugzilla 24360 End */
};

enum hsif_loopbacks_e {
  TEN_HSIF_LOOPBACK_NONE             = 0,
  TEN_HSIF_LOOPBACK_FACILITY         = 1, /* MR40G */
  TEN_HSIF_LOOPBACK_FACILITY_EXT     = 2,
  TEN_HSIF_LOOPBACK_FACILITY_MR10G   = 3,
  TEN_HSIF_LOOPBACK_FAR_END          = 4,
  TEN_HSIF_LOOPBACK_MR_TX2RX         = 5,
  TEN_HSIF_LOOPBACK_MR_RX2TX         = 6,
  TEN_HSIF_LOOPBACK_XFI_TX2RX        = 7,
  TEN_HSIF_LOOPBACK_XFI_RX2TX        = 8,
  TEN_HSIF_LOOPBACK_MR_SERIAL        = 9,
  TEN_HSIF_LOOPBACK_FACILITY_XFI     = 10,
  TEN_HSIF_LOOPBACK_XFI_SERIAL_TX2RX = 11,
  TEN_HSIF_LOOPBACK_CFP_TX2RX        = 12,
  TEN_HSIF_LOOPBACK_CFP_RX2TX        = 13,
  TEN_HSIF_LOOPBACK_FACILITY_CFP     = 14,
  TEN_HSIF_LOOPBACK_CFP_SERIAL_TX2RX = 15,
  TEN_HSIF_LOOPBACK_MAX
};

enum hsif_timing_mode_e {
  TEN_HSIF_TIMING_MODE_LOCAL = 0,
  TEN_HSIF_TIMING_MODE_LINE  = 1,
  TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT = 2
};

enum ten_oohr_layer_e {
  TEN_OOHR_SECTION_LAYER = 1,
  TEN_OOHR_PATH_LAYER = 2,
  TEN_OOHR_TCM1_LAYER = 3,
  TEN_OOHR_TCM2_LAYER = 4,
  TEN_OOHR_TCM3_LAYER = 5,
  TEN_OOHR_TCM4_LAYER = 6,
  TEN_OOHR_TCM5_LAYER = 7,
  TEN_OOHR_TCM6_LAYER = 8,
  TEN_OOHR_ALL_LAYERS = 0xFF 
};

enum ten_n10g_rx_mode_e {
  TEN_N10G_RX_DISABLE            = 0,        
  TEN_N10G_RX_BYPASS             = 1,        
  TEN_N10G_RX_OTU2_ODU2_FS       = 2,        
  TEN_N10G_RX_OTU2_U15_10GFC     = 3,        
  TEN_N10G_RX_OTU2_OPU2          = 4,        
  TEN_N10G_RX_ODU2J_8GFC         = 5,        
  TEN_N10G_RX_OTU2_8GFC          = 6,        
  TEN_N10G_RX_ODU2_ODU2          = 7,        
  TEN_N10G_RX_OC192_OC192        = 8,        
  TEN_N10G_RX_OXU3J_ODU2E_10GE   = 9,        
  TEN_N10G_RX_OTU2E_ODU2         = 10,       
  TEN_N10G_RX_OXU3_OC192         = 11,       
  TEN_N10G_RX_OXU3_OC192P        = 12,       
  TEN_N10G_RX_OXU3_ODU2          = 13,       
  TEN_N10G_RX_OXU3_ODU2P         = 14,       
  TEN_N10G_RX_OXU3_10GEP         = 15,       
  TEN_N10G_RX_OXU3_10GE          = 16,       
  TEN_N10G_RX_OXU3_10GFC         = 17,       
  TEN_N10G_RX_OXU3_OC192_10GE    = 18,       
  TEN_N10G_RX_OTU2E_ODU2E        = 19,       
  TEN_N10G_RX_OTU1E_ODU1E        = 20,       
  TEN_N10G_RX_OTU2_ODU2          = 21,       
  TEN_N10G_RX_OTU2E_10GE         = 22,       
  TEN_N10G_RX_OXU3_ODU2E_10GE    = 23,       
  TEN_N10G_RX_OTU2FC_10GFC       = 24,       
  TEN_N10G_RX_OXU3_ODU2FC_10GFC  = 25,       
  TEN_N10G_RX_OTU1E_10GE         = 26,       
  TEN_N10G_RX_OXU3_ODU1E_10GE    = 27,       
  TEN_N10G_RX_OTU2EJ_10GE        = 28,       
  TEN_N10G_RX_OTU2EJ_10GFC       = 29,       
  TEN_N10G_RX_OTU2XJ_10GE        = 30,       
  TEN_N10G_RX_OTU2EJ_8GFC        = 31,       
  TEN_N10G_RX_ODU2_OC192         = 32,       
  TEN_N10G_RX_OTU2EJ_OC192       = 33,       
  TEN_N10G_RX_OTU2_10GE          = 34,       
  TEN_N10G_RX_OTU2_10U_ODU2      = 35,       
  TEN_N10G_RX_OTU2_OC192_10GE    = 36,       
  TEN_N10G_RX_OC192_10GE         = 37,       
  TEN_N10G_RX_OTU2_OC192         = 38,       
  TEN_N10G_RX_BYPASS_P           = 39,       
  TEN_N10G_RX_OTU2_OC192PT       = 40,       
  TEN_N10G_RX_OXU3_ODU2_10GE     = 41,       
  TEN_N10G_RX_OXU3_192_10GE      = 42,       
  TEN_N10G_RX_OTU2_34_10GE       = 43,       
  TEN_N10G_RX_OTU2_OC192_10GE_20U = 44,       
  TEN_N10G_RX_OTU2_GENRM_ODU3    = 45,       
  TEN_N10G_RX_ODU3_GENRM_OTU2    = 46,       
  TEN_N10G_RX_MAX_MODE           = 47        
};

enum ten_n10g_rx_parm_e {
  TEN_N10G_RX_DPCFG_OTNOFF                 = 0,        
  TEN_N10G_RX_DPCFG_SDHOFF                 = 1,        
  TEN_N10G_RX_DPCFG_OBY                    = 2,        
  TEN_N10G_RX_DPCFG_SBYFRM                 = 3,        
  TEN_N10G_RX_DPCFG_SBYPLD                 = 4,        
  TEN_N10G_RX_DPCFG_KPASEL                 = 5,        
  TEN_N10G_RX_DPCFG_XSEL                   = 6,        
  TEN_N10G_RX_FRMLENGTH_NOFCOLS            = 7,        
  TEN_N10G_RX_SDFCFG_SCREN                 = 8,        
  TEN_N10G_RX_SDFCFG_FAWWUP                = 9,        
  TEN_N10G_RX_SDFCFG_FAWWDW                = 10,       
  TEN_N10G_RX_SDFCFG_OOFHY                 = 11,       
  TEN_N10G_RX_SDFCFG_BFAEN                 = 12,       
  TEN_N10G_RX_SDFCFG1_ALTSCR               = 13,       
  TEN_N10G_RX_OACFG0_FECEN                 = 14,       
  TEN_N10G_RX_OACFG0_PREDSCR               = 15,       
  TEN_N10G_RX_OACFG0_POSTDSCR              = 16,       
  TEN_N10G_RX_ODWCFG_JC_PLUS               = 17,       
  TEN_N10G_RX_ODWCFG_FSOMD                 = 18,       
  TEN_N10G_RX_ODWCFG_G43MD                 = 19,       
  TEN_N10G_RX_ODWCFG_C15RES_EN             = 20,       
  TEN_N10G_RX_ODWCFG_STM64MD               = 21,       
  TEN_N10G_RX_ODWCFG_DWMOD                 = 22,       
  TEN_N10G_RX_OFCFG1_NPARB                 = 23,       
  TEN_N10G_RX_OFCFG1_NPAR                  = 24,       
  TEN_N10G_RX_OFCFG0_NCOLS                 = 25,       
  TEN_N10G_RX_ODWFS_FS                     = 26,       
  TEN_N10G_RX_S1CFG_B1TRANS                = 27,       
  TEN_N10G_RX_S1CFG_B2TRANS                = 28,       
  TEN_N10G_RX_NOFCOLS_NOFCOLS              = 29,       
  TEN_N10G_RX_K12CFG_KAFLEN                = 30,       
  TEN_N10G_RX_MAX_PARM                     = 31        
};

enum ten_n10g_tx_mode_e {
  TEN_N10G_TX_DISABLE            = 0,        
  TEN_N10G_TX_BYPASS             = 1,        
  TEN_N10G_TX_10GFC_OTU2_U15     = 2,        
  TEN_N10G_TX_OPU2_OTU2          = 3,        
  TEN_N10G_TX_ODU2_ODU2          = 4,        
  TEN_N10G_TX_8GFC_OTU2          = 5,        
  TEN_N10G_TX_8GFC_ODU2J         = 6,        
  TEN_N10G_TX_10GE_ODU2E_OXU3J   = 7,        
  TEN_N10G_TX_10GE_OTU2E         = 8,        
  TEN_N10G_TX_10GE_ODU2E_OXU3    = 9,        
  TEN_N10G_TX_10GE_OTU1E         = 10,       
  TEN_N10G_TX_10GE_ODU1E_OXU3    = 11,       
  TEN_N10G_TX_10GFC_OTU2FC       = 12,       
  TEN_N10G_TX_10GFC_ODU2FC_OXU3  = 13,       
  TEN_N10G_TX_OC192_OXU3         = 14,       
  TEN_N10G_TX_OC192_OXU3P        = 15,       
  TEN_N10G_TX_ODU2_OXU3          = 16,       
  TEN_N10G_TX_10GFC_OXU3         = 17,       
  TEN_N10G_TX_10GE_OXU3P         = 18,       
  TEN_N10G_TX_10GE_OXU3          = 19,       
  TEN_N10G_TX_ODU2_OXU3P         = 20,       
  TEN_N10G_TX_OC192_ODU2         = 21,       
  TEN_N10G_TX_OC192_OTU2EJ       = 22,       
  TEN_N10G_TX_10GE_OTU2          = 23,       
  TEN_N10G_TX_10GE_OTU2XJ        = 24,       
  TEN_N10G_TX_10GE_OTU2EJ        = 25,       
  TEN_N10G_TX_10GFC_OTU2EJ       = 26,       
  TEN_N10G_TX_8GFC_OTU2EJ        = 27,       
  TEN_N10G_TX_ODU1E_OTU1E        = 28,       
  TEN_N10G_TX_ODU2_OTU2          = 29,       
  TEN_N10G_TX_ODU2E_OTU2E        = 30,       
  TEN_N10G_TX_ODU2_OTU2_10U      = 31,       
  TEN_N10G_TX_10GE_OC192_OTU2    = 32,       
  TEN_N10G_TX_10GE_OC192         = 33,       
  TEN_N10G_TX_OC192_OTU2         = 34,       
  TEN_N10G_TX_OC192_OC192PT      = 35,       
  TEN_N10G_TX_10GE_192_OXU3      = 36,       
  TEN_N10G_TX_10GE_ODU2_OXU3     = 37,       
  TEN_N10G_TX_10GE_ODU2E_OXU3_DT = 38,       
  TEN_N10G_TX_10GE_OTU2_34       = 39,       
  TEN_N10G_TX_OTU2_OXU3_NT       = 40,       
  TEN_N10G_TX_FC_TRANS_OXU3_NT   = 41,       
  TEN_N10G_TX_OTU2E_OXU3_NT      = 42,       
  TEN_N10G_TX_OC192_OTU2_10U     = 43,       
  TEN_N10G_TX_10GE_OC192_OTU2_20U = 44,       
  TEN_N10G_TX_OTU2_GENRM_ODU3    = 45,       
  TEN_N10G_TX_ODU3_GENRM_OTU2    = 46,       
  TEN_N10G_TX_MAX_MODE           = 47        
};

enum ten_n10g_tx_parm_e {
  TEN_N10G_TX_CFGTX0_SBY                   = 0,        
  TEN_N10G_TX_CFGTX0_OBY                   = 1,        
  TEN_N10G_TX_CFGTX0_KPGBY                 = 2,        
  TEN_N10G_TX_CFGTX0_OTNOFF                = 3,        
  TEN_N10G_TX_FRMLEN_FRMLEN                = 4,        
  TEN_N10G_TX_OHBEN0_SCREN                 = 5,        
  TEN_N10G_TX_OHBEN0_A1A2RSH               = 6,        
  TEN_N10G_TX_OHBEN0_B1IE                  = 7,        
  TEN_N10G_TX_OHBEN0_A1A2IE                = 8,        
  TEN_N10G_TX_OHBEN0_J0IE                  = 9,        
  TEN_N10G_TX_OHBEN0_DEFIE                 = 10,       
  TEN_N10G_TX_OHBEN0_NU1IE                 = 11,       
  TEN_N10G_TX_OHBEN1_B2INV                 = 12,       
  TEN_N10G_TX_OHBEN1_B1INV                 = 13,       
  TEN_N10G_TX_OHBEN1_B1TRANS               = 14,       
  TEN_N10G_TX_OHBEN1_B2TRANS               = 15,       
  TEN_N10G_TX_OHBEN1_K1IE                  = 16,       
  TEN_N10G_TX_OHBEN1_K2IE                  = 17,       
  TEN_N10G_TX_OHBEN2_M0IE                  = 18,       
  TEN_N10G_TX_OHBEN2_M1IE                  = 19,       
  TEN_N10G_TX_SOHBYTES5_NU1                = 20,       
  TEN_N10G_TX_OHBEN3_ALT_SCREN             = 21,       
  TEN_N10G_TX_B1ERRINS_B1ERRMSK            = 22,       
  TEN_N10G_TX_B2ERRINS_B2ERRMSK            = 23,       
  TEN_N10G_TX_SOHBYTES2_K2BYTE             = 24,       
  TEN_N10G_TX_SOHBYTES2_K1BYTE             = 25,       
  TEN_N10G_TX_SOHBYTES3_OHDEF              = 26,       
  TEN_N10G_TX_POHBEN0_PRBSIE               = 27,       
  TEN_N10G_TX_POHBEN0_POHIE                = 28,       
  TEN_N10G_TX_POHBEN0_B3IE                 = 29,       
  TEN_N10G_TX_POHBEN0_C2IE                 = 30,       
  TEN_N10G_TX_POHBEN0_J1IE                 = 31,       
  TEN_N10G_TX_POHBYTES0_C2BYTE             = 32,       
  TEN_N10G_TX_J0STRG0_J0STRG0              = 33,       
  TEN_N10G_TX_B2IE0_B2IE0                  = 34,       
  TEN_N10G_TX_B2IE1_B2IE1                  = 35,       
  TEN_N10G_TX_B2IE2_B2IE2                  = 36,       
  TEN_N10G_TX_B2IE3_B2IE3                  = 37,       
  TEN_N10G_TX_B2IE4_B2IE4                  = 38,       
  TEN_N10G_TX_B2IE5_B2IE5                  = 39,       
  TEN_N10G_TX_B2IE6_B2IE6                  = 40,       
  TEN_N10G_TX_B2IE7_B2IE7                  = 41,       
  TEN_N10G_TX_B2IE8_B2IE8                  = 42,       
  TEN_N10G_TX_B2IE9_B2IE9                  = 43,       
  TEN_N10G_TX_B2IE10_B2IE10                = 44,       
  TEN_N10G_TX_B2IE11_B2IE11                = 45,       
  TEN_N10G_TX_B2IE12_B2IE12                = 46,       
  TEN_N10G_TX_OCFG_PRESCR                  = 47,       
  TEN_N10G_TX_OCFG_POSTSCR                 = 48,       
  TEN_N10G_TX_WRPCFG3_WRMD                 = 49,       
  TEN_N10G_TX_WRPCFG3_C15RES_EN            = 50,       
  TEN_N10G_TX_WRPCFG3_STM64MD              = 51,       
  TEN_N10G_TX_WRPCFG3_G43MD                = 52,       
  TEN_N10G_TX_WRPCFG0_NCOLS                = 53,       
  TEN_N10G_TX_WRPCFG2_NPAR                 = 54,       
  TEN_N10G_TX_WRPCFG2_NPARB                = 55,       
  TEN_N10G_TX_WRPCFG4_JCEN_OTU2            = 56,       
  TEN_N10G_TX_WRPCFG4_JCEN_ODTU23          = 57,       
  TEN_N10G_TX_WRPCFG4_JCEN_DT              = 58,       
  TEN_N10G_TX_WRPCFG4_JC_PLUS_OTU2         = 59,       
  TEN_N10G_TX_WRPCFG4_JC_PLUS_ODTU23       = 60,       
  TEN_N10G_TX_WRPFS_FS                     = 61,       
  TEN_N10G_TX_CFG4_BIPMSK                  = 62,       
  TEN_N10G_TX_CFG0_PTIE                    = 63,       
  TEN_N10G_TX_CFG2_PT                      = 64,       
  TEN_N10G_TX_EXPTI_EXPTI                  = 65,       
  TEN_N10G_TX_MAX_PARM                     = 66        
};

enum ten_n40g_rx_mode_e {
  TEN_N40G_RX_DISABLE            = 0,        
  TEN_N40G_RX_BYPASS             = 1,        
  TEN_N40G_RX_BYPASS_SNT_MON     = 2,        
  TEN_N40G_RX_OTU3_ODTU23_10U_6J = 3,        
  TEN_N40G_RX_OTU3_ODTU23_10U    = 4,        
  TEN_N40G_RX_OTU3_ODTU23_7U     = 5,        
  TEN_N40G_RX_OTU3_ODU3_ORX      = 6,        
  TEN_N40G_RX_OTU3_ODTU23        = 7,        
  TEN_N40G_RX_OC768_ODU3         = 8,        
  TEN_N40G_RX_ODU3_ODU3          = 9,        
  TEN_N40G_RX_OTU3_ODU3          = 10,       
  TEN_N40G_RX_OTU3_ODTU23P_T21   = 11,       
  TEN_N40G_RX_OTU3_ODTU23P       = 12,       
  TEN_N40G_RX_OTU3_ODTU23P14     = 13,       
  TEN_N40G_RX_OTU3_ODU3_LS       = 14,       
  TEN_N40G_RX_OTU3_ODTU23P3      = 15,       
  TEN_N40G_RX_OTU3_ODTU23P7      = 16,       
  TEN_N40G_RX_ODU3_ODTU23        = 17,       
  TEN_N40G_RX_OTU2_GENRM_ODU3    = 18,       
  TEN_N40G_RX_ODU3_GENRM_OTU2    = 19,       
  TEN_N40G_RX_OTU3E_ODTU23P      = 20,       
  /* Bugzilla 20308 Start */
  TEN_N40G_RX_OTU3_ODTU23P2      = 21,       
  TEN_N40G_RX_MAX_MODE           = 22        
  /* Bugzilla 20308 End */
};

enum ten_n40g_rx_parm_e {
  TEN_N40G_RX_DPCFG0_BYSEL                 = 0,        
  TEN_N40G_RX_DPCFG0_BYPCFG                = 1,        
  TEN_N40G_RX_DPCFG0_OBY                   = 2,        
  TEN_N40G_RX_DPCFG0_SBY                   = 3,        
  TEN_N40G_RX_DPCFG0_MDPCFG                = 4,        
  TEN_N40G_RX_DPCFG0_KPASEL                = 5,        
  TEN_N40G_RX_FRMLENGTH_NOFCOLS            = 6,        
  TEN_N40G_RX_SDFCFG_SCREN                 = 7,        
  TEN_N40G_RX_SDFCFG_FAWWUP                = 8,        
  TEN_N40G_RX_SDFCFG_FAWWDW                = 9,        
  TEN_N40G_RX_SDFCFG_OOFHY                 = 10,       
  TEN_N40G_RX_SDFCFG1_ALTSCR               = 11,       
  TEN_N40G_RX_OACFG0_PREDSCR               = 12,       
  TEN_N40G_RX_OACFG0_POSTDSCR              = 13,       
  TEN_N40G_RX_OACFG0_ALEN                  = 14,       
  TEN_N40G_RX_ODWCFG_STM256MD              = 15,       
  TEN_N40G_RX_ODWCFG_FSOMD                 = 16,       
  TEN_N40G_RX_ODWCFG_DW_ENABLE             = 17,       
  TEN_N40G_RX_ODWCFG_AGGRMOD               = 18,       
  TEN_N40G_RX_ODWCFG_STM64MD               = 19,       
  TEN_N40G_RX_ODWCFG1_JC_ENABLE            = 20,       
  TEN_N40G_RX_ODWCFG1_JC_PLUS              = 21,       
  TEN_N40G_RX_OFCFG1_NPARB                 = 22,       
  TEN_N40G_RX_OFCFG1_NPAR                  = 23,       
  TEN_N40G_RX_OFCFG0_NCOLS                 = 24,       
  TEN_N40G_RX_MAX_PARM                     = 25        
};

enum ten_n40g_tx_mode_e {
  TEN_N40G_TX_DISABLE            = 0,        
  TEN_N40G_TX_BYPASS             = 1,        
  TEN_N40G_TX_BYPASS_SNT_MON     = 2,        
  TEN_N40G_TX_ODTU2_OTU3_10U_6J  = 3,        
  TEN_N40G_TX_ODTU2_OTU3_10U     = 4,        
  TEN_N40G_TX_ODTU2_OTU3_7U      = 5,        
  TEN_N40G_TX_ODU3_OTU3_ORV      = 6,        
  TEN_N40G_TX_ODTU2_OTU_T21A     = 7,        
  TEN_N40G_TX_ODTU2_OTU3         = 8,        
  TEN_N40G_TX_ODTU2_OTU3P_T21    = 9,        
  TEN_N40G_TX_ODTU2_OTU3P        = 10,       
  TEN_N40G_TX_ODTU2_OTU3P14      = 11,       
  TEN_N40G_TX_OC192_OTU3         = 12,       
  TEN_N40G_TX_ODU3_ODU3          = 13,       
  TEN_N40G_TX_ODU3_OTU3          = 14,       
  TEN_N40G_TX_ODU3_OTU3_SL       = 15,       
  TEN_N40G_TX_ODTU2_OTU3P3       = 16,       
  TEN_N40G_TX_ODTU2_OTU3P7       = 17,       
  TEN_N40G_TX_ODTU2_ODU3         = 18,       
  TEN_N40G_TX_OTU2_GENRM_ODU3    = 19,       
  TEN_N40G_TX_ODU3_GENRM_OTU2    = 20,       
  TEN_N40G_TX_OTU3E_ODTU23P      = 21,       
  /* Bugzilla 20308 Start */
  TEN_N40G_TX_ODTU2_OTU3P2       = 22,       
  TEN_N40G_TX_MAX_MODE           = 23        
  /* Bugzilla 20308 End */
};

enum ten_n40g_tx_parm_e {
  TEN_N40G_TX_CFG_MDPCFG                   = 0,        
  TEN_N40G_TX_CFG_SBY                      = 1,        
  TEN_N40G_TX_CFG_OBY                      = 2,        
  TEN_N40G_TX_CFG_KPGBY                    = 3,        
  TEN_N40G_TX_OHIE_B1INV                   = 4,        
  TEN_N40G_TX_OHIE_SCREN                   = 5,        
  TEN_N40G_TX_OHIE_A1A2RSH                 = 6,        
  TEN_N40G_TX_OHIE_B1IE                    = 7,        
  TEN_N40G_TX_OHIE_B1TRANS                 = 8,        
  TEN_N40G_TX_B1ERRINS_B1ERRMSK            = 9,        
  TEN_N40G_TX_FRMLEN_FRMLEN                = 10,       
  TEN_N40G_TX_OCFG_PRESCR                  = 11,       
  TEN_N40G_TX_OCFG_POSTSCR                 = 12,       
  TEN_N40G_TX_WRPCFG3_WRMD                 = 13,       
  TEN_N40G_TX_WRPCFG3_STM256MD             = 14,       
  TEN_N40G_TX_WRPCFG3_STM64MD              = 15,       
  TEN_N40G_TX_WRPCFG3_AGGRMOD              = 16,       
  TEN_N40G_TX_WRPCFG4_JCEN                 = 17,       
  TEN_N40G_TX_WRPCFG4_JC_PLUS              = 18,       
  TEN_N40G_TX_WRPCFG0_NCOLS                = 19,       
  TEN_N40G_TX_WRPCFG2_NPAR                 = 20,       
  TEN_N40G_TX_WRPCFG2_NPARB                = 21,       
  TEN_N40G_TX_WRP0DH1_DTHYST01             = 22,       
  TEN_N40G_TX_WRP0DH0_DTHYST00             = 23,       
  TEN_N40G_TX_WRP1DH1_DTHYST11             = 24,       
  TEN_N40G_TX_WRP1DH0_DTHYST10             = 25,       
  TEN_N40G_TX_WRP2DH1_DTHYST21             = 26,       
  TEN_N40G_TX_WRP2DH0_DTHYST20             = 27,       
  TEN_N40G_TX_WRP3DH1_DTHYST31             = 28,       
  TEN_N40G_TX_WRP3DH0_DTHYST30             = 29,       
  TEN_N40G_TX_CFG0_PTIE                    = 30,       
  TEN_N40G_TX_CFG2_PT                      = 31,       
  TEN_N40G_TX_EXPTI_EXPTI                  = 32,       
  TEN_N40G_TX_MAX_PARM                     = 33        
};

enum ten_pp40g_rx_parm_e {
  TEN_PP40G_RX_DISABLE              = 0,  /* Disable */
  TEN_PP40G_RX_BYPASS               = 1,  /* Bypass */
  TEN_PP40G_RX_40GEP_XCON           = 2,  /* 40 GE parallel mode RX */
  TEN_PP40G_RX_40GESBI_XCON         = 3,  /* 40 GE Serial mode RX */
  TEN_PP40G_RX_40GES6466_XCON       = 4,  /* Monolithic mode RX */
  TEN_PP40G_RX_40GEX_XCON           = 5,  /* Transcoding mode for RX */
  TEN_PP40G_RX_40GEP_XCON_RA        = 6,  /* 40 GE parallel mode RX with rate adjust */
  TEN_PP40G_RX_40GESBI_XCON_RA      = 7,  /* 40 GE Serial mode RX with rate adjust */
  TEN_PP40G_RX_40GES6466_XCON_RA    = 8,  /* Monolithic mode RX with rate adjust */
  TEN_PP40G_RX_40GEX_XCON_RA        = 9,  /* Transcoding mode for RX with rate adjust */
  TEN_PP40G_RX_MAX_MODE                     
};

enum ten_pp40g_tx_parm_e {
  TEN_PP40G_TX_DISABLE              = 0,  /*  Disable  */
  TEN_PP40G_TX_BYPASS               = 1,  /*  Bypass  */
  TEN_PP40G_TX_XCON_40GEP           = 2,  /*  40 GE parallel mode TX */
  TEN_PP40G_TX_XCON_40GESBI         = 3,  /*  40 GE Serial mode TX  */
  TEN_PP40G_TX_XCON_40GES6466       = 4,  /*  Monolithic mode TX */
  TEN_PP40G_TX_XCON_40GEX           = 5,  /*  Transcoding mode for TX */
  TEN_PP40G_TX_XCON_40GEP_RA        = 6,  /*  40 GE parallel mode TX with rate adjust */
  TEN_PP40G_TX_XCON_40GESBI_RA      = 7,  /*  40 GE Serial mode TX with rate adjust */
  TEN_PP40G_TX_XCON_40GES6466_RA    = 8,  /*  Monolithic mode TX with rate adjust */
  TEN_PP40G_TX_XCON_40GEX_RA        = 9,  /*  Transcoding mode for TX with rate adjust */
  TEN_PP40G_TX_PBERT_40GEP          = 10, /*  40 GE parallel mode TX */
  TEN_PP40G_TX_PBERT_40GESBI        = 11, /*  40 GE Serial mode TX  */
  TEN_PP40G_TX_PBERT_40GES6466      = 12, /*  Monolithic mode TX */
  TEN_PP40G_TX_PBERT_40GEX          = 13, /*  Transcoding mode for TX */
  TEN_PP40G_TX_MAX_MODE
};

enum ten_pp10g_flow_mode_e {
  TEN_PP10G_FLOW_GFP_S_P         = 0,        
  TEN_PP10G_FLOW_GFP_S           = 1,        
  TEN_PP10G_FLOW_ETH_4           = 2,  /* Reactive   */
  TEN_PP10G_FLOW_ETH_4_P         = 3,  /* Premptive  */ 
  TEN_PP10G_FLOW_MAX_MODE        = 4
};

enum ten_pp10g_flow_parm_e {
  TEN_PP10G_FLOW_CFG_TX_PAUSE_PREEMPTIVE_EN = 0,        
  TEN_PP10G_FLOW_CFG_TX_PAUSE_REACTIVE_EN  = 1,        
  TEN_PP10G_FLOW_PQUANTA_PQ                = 2,        
  TEN_PP10G_FLOW_PRGQINC_QUANTUM_UPPER     = 3,        
  TEN_PP10G_FLOW_PRGQINC_QUANTUM_LOWER     = 4,        
  TEN_PP10G_FLOW_PFMCTRL_MONITOR           = 5,        
  TEN_PP10G_FLOW_PRGRATE_RATE              = 6,        
  TEN_PP10G_FLOW_PFGCTRL_LOWER_THRESHOLD_ONE = 7,        
  TEN_PP10G_FLOW_MAX_PARM                  = 8         
};

enum ten_pp10g_rx_mode_e {
  TEN_PP10G_RX_DISABLE           = 0,        
  TEN_PP10G_RX_ETH_0             = 1,        
  TEN_PP10G_RX_ETH_2             = 2,        
  TEN_PP10G_RX_ETH_4             = 3,        
  TEN_PP10G_RX_GFP_S             = 4,        
  TEN_PP10G_RX_GFP_T             = 5,        
  TEN_PP10G_RX_ETH2_GFP_T        = 6,        
  TEN_PP10G_RX_ETH0_GFP_S        = 7,        
  TEN_PP10G_RX_XAUI_FC           = 8,        
  TEN_PP10G_RX_FC                = 9,        
  TEN_PP10G_RX_8FC               = 10,       
  TEN_PP10G_RX_XC_GE             = 11,       
  TEN_PP10G_RX_XC_FC             = 12,       
  TEN_PP10G_RX_ETH_4_RA          = 13,       
  TEN_PP10G_RX_FC_RA             = 14,       
  TEN_PP10G_RX_8FC_RA            = 15,       
  TEN_PP10G_RX_XAUI_ETH_4_RA     = 16,       
  TEN_PP10G_RX_XAUI_ETH2_GFP_T   = 17,       
  TEN_PP10G_RX_XAUI_FC_RA        = 18,       
  TEN_PP10G_RX_XAUI_ETH0_GFP_S   = 19,       
  TEN_PP10G_RX_XC_FC_RA          = 20,     
  TEN_PP10G_RX_MAX_MODE          = 21        
};

enum ten_pp10g_rx_parm_e {
  TEN_PP10G_RX_FUNCEN_RX_RX_FEN_XGPCS      = 0,        
  TEN_PP10G_RX_FUNCEN_RX_RX_FEN_EGPCS      = 1,        
  TEN_PP10G_RX_FUNCEN_RX_RX_FEN_GFP        = 2,        
  TEN_PP10G_RX_FUNCEN_RX_RX_FEN_BASEX      = 3,        
  TEN_PP10G_RX_FUNCEN_RX_RX_FEN_MAC        = 4,        
  TEN_PP10G_RX_FUNCEN_RX_RX_FEN_BYPASS     = 5,        
  TEN_PP10G_RX_FUNCEN_RX_RX_FEN_XCODE      = 6,        
  TEN_PP10G_RX_FUNCEN_RX_RX_FEN_FC         = 7,        
  TEN_PP10G_RX_RXCNTRL_RXPROFILE           = 8,        
  TEN_PP10G_RX_MODE_MODE                   = 9,        
  TEN_PP10G_RX_CFG_COM_PROFILE             = 10,       
  TEN_PP10G_RX_CFG_RX_IFG_MODE_RX          = 11,       
  TEN_PP10G_RX_CFG_RX_PROMIS_MODE          = 12,       
  TEN_PP10G_RX_RXCNTRL1_RX_PROFILE         = 13,       
  TEN_PP10G_RX_CNTRL_RX_PROFILE            = 14,       
  TEN_PP10G_RX_CNTRL_TX_PROFILE            = 15,       
  TEN_PP10G_RX_CNTRL1_DISCARD_ELIGIBLE     = 16,       
  TEN_PP10G_RX_CNTRL_TRANSLATE             = 17,       
  TEN_PP10G_RX_RATECNTRL_IDLE_ALL          = 18,       
  TEN_PP10G_RX_RATECNTRL_SEQ_OS_2ND        = 19,       
  TEN_PP10G_RX_RATECNTRL_SEQ_OS_ALL        = 20,       
  TEN_PP10G_RX_RATECNTRL1_MAP_IDLE_ALL     = 21,       
  TEN_PP10G_RX_RATECNTRL1_MAP_SEQ_OS_2ND   = 22,       
  TEN_PP10G_RX_RATECNTRL1_MAP_SEQ_OS_ALL   = 23,        
  TEN_PP10G_RX_RATECNTRL_FC_IDLE           = 24,       
  TEN_PP10G_RX_RATECNTRL3_MIN_IFG          = 25,       
  TEN_PP10G_RX_RATECNTRL_CLIENT_ALL        = 26,       
  TEN_PP10G_RX_RATECNTRL2_MAP_CLIENT_ALL_HI = 27,       
  TEN_PP10G_RX_RATECNTRL2_MAP_CLIENT_ALL_LO = 28,       
  TEN_PP10G_RX_MAX_PARM                    = 29        
};

enum ten_pp10g_tx_mode_e {
  TEN_PP10G_TX_DISABLE           = 0,        
  TEN_PP10G_TX_ETH_0             = 1,        
  TEN_PP10G_TX_ETH_2             = 2,        
  TEN_PP10G_TX_ETH_4             = 3,        
  TEN_PP10G_TX_GFP_S             = 4,        
  TEN_PP10G_TX_GFP_T             = 5,        
  TEN_PP10G_TX_GFP_T_ETH2        = 6,        
  TEN_PP10G_TX_GFP_S_ETH0        = 7,        
  TEN_PP10G_TX_XAUI_FC           = 8,        
  TEN_PP10G_TX_FC                = 9,        
  TEN_PP10G_TX_8FC               = 10,       
  TEN_PP10G_TX_XC_FC             = 11,       
  TEN_PP10G_TX_XC_GE             = 12,       
  TEN_PP10G_TX_XAUI_ETH_4        = 13,       
  TEN_PP10G_TX_XAUI_GFP_T_ETH2   = 14,       
  TEN_PP10G_TX_XAUI_GFP_S_ETH0   = 15,       
  TEN_PP10G_TX_XC_FC_RA          = 16,              
  TEN_PP10G_TX_MAX_MODE          = 17        
};

enum ten_pp10g_tx_parm_e {
  TEN_PP10G_TX_FUNCEN_TX_TX_FEN_XGPCS      = 0,        
  TEN_PP10G_TX_FUNCEN_TX_TX_FEN_EGPCS      = 1,        
  TEN_PP10G_TX_FUNCEN_TX_TX_FEN_GFP        = 2,        
  TEN_PP10G_TX_FUNCEN_TX_TX_FEN_BASEX      = 3,        
  TEN_PP10G_TX_FUNCEN_TX_TX_FEN_MAC        = 4,        
  TEN_PP10G_TX_FUNCEN_TX_TX_FEN_BYPASS     = 5,        
  TEN_PP10G_TX_FUNCEN_TX_TX_FEN_XCODE      = 6,        
  TEN_PP10G_TX_TXCNTRL1_TXPROFILE          = 7,        
  TEN_PP10G_TX_MODE_MODE                   = 8,        
  TEN_PP10G_TX_CFG_COM_PROFILE             = 9,        
  TEN_PP10G_TX_CFG_TX_IFG                  = 10,       
  TEN_PP10G_TX_CNTRL1_PROFILE              = 11,       
  TEN_PP10G_TX_CNTRL1_NO_IPG_CHECK         = 12,       
  TEN_PP10G_TX_TXCNTRL_TX_PROFILE          = 13,       
  TEN_PP10G_TX_CNTRL1_TRANSLATE            = 14,       
  TEN_PP10G_TX_CNTRL1_AUTO_FILL            = 15,       
  TEN_PP10G_TX_FILLCTRL_REPEAT_ENABLE      = 16,       
  TEN_PP10G_TX_FILLCTRL_FILL_ENABLE        = 17,       
  TEN_PP10G_TX_FILLCTRL_MAX_FAULT_REPEAT   = 18,       
  TEN_PP10G_TX_MAX_PARM                    = 19        
};

enum ten_syncdesync_demap_mode_e {
  TEN_SYNCDESYNC_DEMAP_DISABLE   = 0,        
  TEN_SYNCDESYNC_DEMAP_1_TO_1    = 1,        
  TEN_SYNCDESYNC_DEMAP_OC192_OTU3_10U_8 = 2,        
  TEN_SYNCDESYNC_DEMAP_ODU2_OTU3_10P_8 = 3,        
  TEN_SYNCDESYNC_DEMAP_10GE_OTU2EJ_B = 4,        
  TEN_SYNCDESYNC_DEMAP_OC192_OTU3P_8 = 5,        
  TEN_SYNCDESYNC_DEMAP_ODU2E_OTU3P_8 = 6,        
  TEN_SYNCDESYNC_DEMAP_10GFC_OXU3_8 = 7,        
  TEN_SYNCDESYNC_DEMAP_ODU1E_OXU3_8 = 8,        
  TEN_SYNCDESYNC_DEMAP_10GE_OTU2EJ = 9,        
  TEN_SYNCDESYNC_DEMAP_OTU1E_ODU1E = 10,       
  TEN_SYNCDESYNC_DEMAP_OC192_OTU3 = 11,       
  TEN_SYNCDESYNC_DEMAP_OC192_OTU3_10U = 12,       
  TEN_SYNCDESYNC_DEMAP_OPU2_OTU2 = 13,       
  TEN_SYNCDESYNC_DEMAP_ODU2_OTU3_10P = 14,       
  TEN_SYNCDESYNC_DEMAP_OC192_OTU3P = 15,       
  TEN_SYNCDESYNC_DEMAP_8GFC_OTU2E = 16,       
  TEN_SYNCDESYNC_DEMAP_8GFC_ODU2 = 17,       
  TEN_SYNCDESYNC_DEMAP_10GEM_OTU2E = 18,       
  TEN_SYNCDESYNC_DEMAP_10GE_OTU2E = 19,       
  TEN_SYNCDESYNC_DEMAP_10GE_ODU2EP = 20,       
  TEN_SYNCDESYNC_DEMAP_10GE_ODU1EP = 21,       
  TEN_SYNCDESYNC_DEMAP_10GE_ODU2FCP = 22,       
  TEN_SYNCDESYNC_DEMAP_10GE_ODU2P = 23,       
  TEN_SYNCDESYNC_DEMAP_8GE_OTU2E = 24,       
  TEN_SYNCDESYNC_DEMAP_ODU2_OTU2 = 25,       
  TEN_SYNCDESYNC_DEMAP_ODU1E_OTU2 = 26,       
  TEN_SYNCDESYNC_DEMAP_ODU2E_OTU2 = 27,       
  TEN_SYNCDESYNC_DEMAP_OC192_ODU2 = 28,       
  TEN_SYNCDESYNC_DEMAP_OC192_OTU2 = 29,       
  TEN_SYNCDESYNC_DEMAP_ODU2_OTU2_10U = 30,       
  TEN_SYNCDESYNC_DEMAP_10GFC_OTU2FC = 31,       
  TEN_SYNCDESYNC_DEMAP_ODU2_OTU3 = 32,       
  TEN_SYNCDESYNC_DEMAP_ODU2E_OTU3 = 33,       
  TEN_SYNCDESYNC_DEMAP_ODU2E_OTU3P = 34,       
  TEN_SYNCDESYNC_DEMAP_ODU1E_OXU3 = 35,       
  TEN_SYNCDESYNC_DEMAP_10GFC_OXU3 = 36,       
  TEN_SYNCDESYNC_DEMAP_10GFC_OTU2 = 37,       
  TEN_SYNCDESYNC_DEMAP_OTU3_ODU3 = 38,       
  TEN_SYNCDESYNC_DEMAP_OTU2EJ_OC192 = 39,       
  TEN_SYNCDESYNC_DEMAP_OTU3_ODU3_LS = 40,       
  TEN_SYNCDESYNC_DEMAP_ODU2_OTU3_NT = 41,       
  TEN_SYNCDESYNC_DEMAP_FC_TRANS_OTU3_NT = 42,       
  TEN_SYNCDESYNC_DEMAP_OTU2E_OTU3_NT = 43,       
  TEN_SYNCDESYNC_DEMAP_OC192_OTU2_10P = 44,       
  TEN_SYNCDESYNC_DEMAP_OC192_ODU3 = 45,       
  TEN_SYNCDESYNC_DEMAP_OTU3_OC768_26U = 46,       
  TEN_SYNCDESYNC_DEMAP_OTU3_OC768_26U_56 = 47,       
  TEN_SYNCDESYNC_DEMAP_OTU2_GENRM_ODU3 = 48,       
  TEN_SYNCDESYNC_DEMAP_ODU3_GENRM_OTU2 = 49,       
  TEN_SYNCDESYNC_DEMAP_OTU2_OTU3 = 50,       
  /* Bugzilla #20377, add FC modes */
  TEN_SYNCDESYNC_DEMAP_8GFC_OTU2 = 51,       
  TEN_SYNCDESYNC_DEMAP_8GFC_OTU2_10U = 52,            
  TEN_SYNCDESYNC_DEMAP_10GFC_OTU2E = 53,            
  TEN_SYNCDESYNC_DEMAP_MAX_MODE  = 54        
};

enum ten_syncdesync_demap_parm_e {
  TEN_SYNCDESYNC_DEMAP_CFG_MODE            = 0,        
  TEN_SYNCDESYNC_DEMAP_AD21_AD21           = 1,        
  TEN_SYNCDESYNC_DEMAP_AD20_AD20           = 2,        
  TEN_SYNCDESYNC_DEMAP_AD11_AD11           = 3,        
  TEN_SYNCDESYNC_DEMAP_AD10_AD10           = 4,        
  TEN_SYNCDESYNC_DEMAP_AC22_AC22           = 5,        
  TEN_SYNCDESYNC_DEMAP_AC21_AC21           = 6,        
  TEN_SYNCDESYNC_DEMAP_AC20_AC20           = 7,        
  TEN_SYNCDESYNC_DEMAP_AC12_AC12           = 8,        
  TEN_SYNCDESYNC_DEMAP_AC11_AC11           = 9,        
  TEN_SYNCDESYNC_DEMAP_AC10_AC10           = 10,       
  TEN_SYNCDESYNC_DEMAP_NUMERATOR2_NUMERATOR2 = 11,       
  TEN_SYNCDESYNC_DEMAP_NUMERATOR1_NUMERATOR1 = 12,       
  TEN_SYNCDESYNC_DEMAP_NUMERATOR0_NUMERATOR0 = 13,       
  TEN_SYNCDESYNC_DEMAP_DENOMINATOR2_DENOMINATOR2 = 14,       
  TEN_SYNCDESYNC_DEMAP_DENOMINATOR1_DENOMINATOR1 = 15,       
  TEN_SYNCDESYNC_DEMAP_DENOMINATOR0_DENOMINATOR0 = 16,       
  TEN_SYNCDESYNC_DEMAP_MAX_PARM            = 17        
};

enum ten_syncdesync_map_mode_e {
  TEN_SYNCDESYNC_MAP_DISABLE     = 0,        
  TEN_SYNCDESYNC_MAP_1_TO_1      = 1,        
  TEN_SYNCDESYNC_MAP_OC192_OTU3_10U_8 = 2,        
  TEN_SYNCDESYNC_MAP_ODU2_OTU3_10P_8 = 3,        
  TEN_SYNCDESYNC_MAP_10GE_OTU2EJ_B = 4,        
  TEN_SYNCDESYNC_MAP_OC192_OTU3P_8 = 5,        
  TEN_SYNCDESYNC_MAP_ODU2E_OTU3P_8 = 6,        
  TEN_SYNCDESYNC_MAP_10GFC_OXU3_8 = 7,        
  TEN_SYNCDESYNC_MAP_ODU1E_OXU3_8 = 8,        
  TEN_SYNCDESYNC_MAP_10GE_OTU2EJ = 9,        
  TEN_SYNCDESYNC_MAP_OTU1E_ODU1E = 10,       
  TEN_SYNCDESYNC_MAP_OC192_OTU3  = 11,       
  TEN_SYNCDESYNC_MAP_OC192_OTU3_10U = 12,       
  TEN_SYNCDESYNC_MAP_OPU2_OTU2   = 13,       
  TEN_SYNCDESYNC_MAP_ODU2_OTU3_10P = 14,       
  TEN_SYNCDESYNC_MAP_OC192_OTU3P = 15,       
  TEN_SYNCDESYNC_MAP_8GFC_OTU2E  = 16,       
  TEN_SYNCDESYNC_MAP_8GFC_ODU2   = 17,       
  TEN_SYNCDESYNC_MAP_10GEM_OTU2E = 18,       
  TEN_SYNCDESYNC_MAP_10GE_OTU2E  = 19,       
  TEN_SYNCDESYNC_MAP_10GE_ODU2EP = 20,       
  TEN_SYNCDESYNC_MAP_10GE_ODU1EP = 21,       
  TEN_SYNCDESYNC_MAP_10GE_ODU2FCP = 22,       
  TEN_SYNCDESYNC_MAP_10GE_ODU2P  = 23,       
  TEN_SYNCDESYNC_MAP_8GE_OTU2E   = 24,       
  TEN_SYNCDESYNC_MAP_ODU2_OTU2   = 25,       
  TEN_SYNCDESYNC_MAP_ODU1E_OTU2  = 26,       
  TEN_SYNCDESYNC_MAP_ODU2E_OTU2  = 27,       
  TEN_SYNCDESYNC_MAP_OC192_ODU2  = 28,       
  TEN_SYNCDESYNC_MAP_OC192_OTU2  = 29,       
  TEN_SYNCDESYNC_MAP_ODU2_OTU2_10U = 30,       
  TEN_SYNCDESYNC_MAP_10GFC_OTU2FC = 31,       
  TEN_SYNCDESYNC_MAP_ODU2_OTU3   = 32,       
  TEN_SYNCDESYNC_MAP_ODU2E_OTU3  = 33,       
  TEN_SYNCDESYNC_MAP_ODU2E_OTU3P = 34,       
  TEN_SYNCDESYNC_MAP_ODU1E_OXU3  = 35,       
  TEN_SYNCDESYNC_MAP_10GFC_OXU3  = 36,       
  TEN_SYNCDESYNC_MAP_10GFC_OTU2  = 37,       
  TEN_SYNCDESYNC_MAP_ODU3_OTU3   = 38,       
  TEN_SYNCDESYNC_MAP_OC192_OTU2EJ = 39,       
  TEN_SYNCDESYNC_MAP_ODU3_OTU3_SL = 40,       
  TEN_SYNCDESYNC_MAP_ODU2_OTU3_NT = 41,       
  TEN_SYNCDESYNC_MAP_FC_TRANS_OTU3_NT = 42,       
  TEN_SYNCDESYNC_MAP_OTU2E_OTU3_NT = 43,       
  TEN_SYNCDESYNC_MAP_OC192_OTU2_10P = 44,       
  TEN_SYNCDESYNC_MAP_OC192_ODU3  = 45,       
  TEN_SYNCDESYNC_MAP_OTU3_OC768_26U = 46,       
  TEN_SYNCDESYNC_MAP_OTU3_OC768_26U_56 = 47,       
  TEN_SYNCDESYNC_MAP_ODU3_GENRM_OTU2 = 48,       
  TEN_SYNCDESYNC_MAP_OTU2_GENRM_ODU3 = 49,       
  TEN_SYNCDESYNC_MAP_OTU2_OTU3   = 50,       
  /* Bugzilla #20377, add FC modes */
  TEN_SYNCDESYNC_MAP_8GFC_OTU2 = 51,       
  TEN_SYNCDESYNC_MAP_8GFC_OTU2_10U = 52,            
  TEN_SYNCDESYNC_MAP_10GFC_OTU2E = 53,            
  TEN_SYNCDESYNC_MAP_MAX_MODE    = 54
};

enum ten_syncdesync_map_parm_e {
  TEN_SYNCDESYNC_MAP_CFG_MODE              = 0,        
  TEN_SYNCDESYNC_MAP_CFGPD0_DSYNC_PD_MD    = 1,        
  TEN_SYNCDESYNC_MAP_AD21_AD21             = 2,        
  TEN_SYNCDESYNC_MAP_AD20_AD20             = 3,        
  TEN_SYNCDESYNC_MAP_AD11_AD11             = 4,        
  TEN_SYNCDESYNC_MAP_AD10_AD10             = 5,        
  TEN_SYNCDESYNC_MAP_AC22_AC22             = 6,        
  TEN_SYNCDESYNC_MAP_AC21_AC21             = 7,        
  TEN_SYNCDESYNC_MAP_AC20_AC20             = 8,        
  TEN_SYNCDESYNC_MAP_AC12_AC12             = 9,        
  TEN_SYNCDESYNC_MAP_AC11_AC11             = 10,       
  TEN_SYNCDESYNC_MAP_AC10_AC10             = 11,       
  TEN_SYNCDESYNC_MAP_NUMERATOR2_NUMERATOR2 = 12,       
  TEN_SYNCDESYNC_MAP_NUMERATOR1_NUMERATOR1 = 13,       
  TEN_SYNCDESYNC_MAP_NUMERATOR0_NUMERATOR0 = 14,       
  TEN_SYNCDESYNC_MAP_DENOMINATOR2_DENOMINATOR2 = 15,       
  TEN_SYNCDESYNC_MAP_DENOMINATOR1_DENOMINATOR1 = 16,       
  TEN_SYNCDESYNC_MAP_DENOMINATOR0_DENOMINATOR0 = 17,       
  TEN_SYNCDESYNC_MAP_CFGJCGEN_JC_GEN_MAX_JP = 18,       
  TEN_SYNCDESYNC_MAP_CFGJCGEN_JC_GEN_THRLD = 19,       
  TEN_SYNCDESYNC_MAP_MAX_PARM              = 20        
};

/* Bugzilla 23772 Start */
/* Bugzilla 22514 Start */
enum ten_traffic_mode_e {
  TEN_40G_TRANSPONDER = 0,
  TEN_40G_MUXPONDER   = 1,
  TEN_10G_TRANSPONDER = 2,
  TEN_10G_LOOPBACK    = 3,
  TEN_40G_LOOPBACK    = 4,
  TEN_10G_KPGA        = 5,
  TEN_40G_KPGA        = 6,
  TEN_10G_PBERT       = 7,
  TEN_10G_HSIF_KPGA   = 8,
  TEN_40G_HSIF_KPGA   = 9,
  /* Bugzilla 24559 Start */
  TEN_10G_CBR_KPGA    = 10,
  TEN_40G_CBR_KPGA    = 11,
  /* Bugzilla 24559 End */
  /* Bugzilla 24645 Start */
  TEN_10G_WIRE        = 12,
  TEN_40G_WIRE        = 13
  /* Bugzilla 24645 End */
};
/* Bugzilla 22514 End */
/* Bugzilla 23772 End */

enum ten_method_e {
  TEN_MUX_1TO1_ASYNC_2LEVEL  = 0,
  TEN_1TO1_ASYNC_2LEVEL      = TEN_MUX_1TO1_ASYNC_2LEVEL,
  TEN_MUX_SYNC_ASYNC_1LEVEL  = 1,
  TEN_SYNC_ASYNC_1LEVEL      = TEN_MUX_SYNC_ASYNC_1LEVEL,
  TEN_MUX_1TO1_ASYNC_1LEVEL  = 2,
  TEN_1TO1_ASYNC_1LEVEL      = TEN_MUX_1TO1_ASYNC_1LEVEL,
  TEN_MUX_BOTH_1TO1          = 3,
  TEN_BOTH_1TO1              = TEN_MUX_BOTH_1TO1,
  TEN_ASYNC_ASYNC_1LEVEL     = 4,
  TEN_1TO1_ASYNC_1TO1_1LEVEL = 5,   /* 40G TRANSPONDER */ 
  TEN_ASYNC_ASYNCX4_1LEVEL   = 6    /* 40G TRANSPONDER */ 
};

enum ten_xcon_mode_e {
  TEN_XCON_DISABLE               = 0,        
  TEN_XCON_10GE_GFP_OTU3         = 1,        
  TEN_XCON_OTU3_GFP_10GE         = 2,        
  TEN_XCON_10GE_RA_FC_OTU3       = 3,        
  TEN_XCON_OTU3_RA_FC_10GE       = 4,        
  TEN_XCON_10GFC_TRANS_OTU3P     = 5,        
  TEN_XCON_10GE_RA_GFP           = 6,        
  TEN_XCON_GFP_RA_10GE           = 7,        
  TEN_XCON_10GE_RA_OTU2E         = 8,        
  TEN_XCON_OTU2E_RA_10GE         = 9,        
  TEN_XCON_10GE_OC192_OTU2       = 10,       
  TEN_XCON_OTU2_OC192_10GE       = 11,       
  TEN_XCON_10GE_RA               = 12,       
  TEN_XCON_10GE_MON_OTU2         = 13,       
  TEN_XCON_10GFC_TRANS_OTU2      = 14,       
  TEN_XCON_8GFC_MON_OTU2         = 15,       
  TEN_XCON_10GE_OTU2E_OTU3P      = 16,       
  TEN_XCON_10GE_OTU1E_OTU3P      = 17,       
  TEN_XCON_10GE_OC192_OTU3P      = 18,       
  TEN_XCON_OTU3P_OC192_10GE      = 19,       
  TEN_XCON_GRP_T_OTU3P           = 20,       
  TEN_XCON_10GFC_OTU2FC          = 21,       
  TEN_XCON_8GFC_OTU2             = 22,       
  TEN_XCON_OTU2_8GFC             = 23,       
  TEN_XCON_TABLE15P4             = 24,       
  TEN_XCON_TABLE16P0             = 25,       
  TEN_XCON_TABLE16MIX_P0         = 26,       
  TEN_XCON_TABLE16MIX_P1         = 27,       
  TEN_XCON_TABLE16MIX_P2         = 28,       
  TEN_XCON_TABLE19P0             = 29,       
  TEN_XCON_TABLE19MIX_P0         = 30,       
  TEN_XCON_TABLE19MIX_P1         = 31,       
  TEN_XCON_TABLE19MIX_P2         = 32,       
  TEN_XCON_MAX_MODE              = 33        
};

enum ten_xcon_parm_e {
  TEN_XCON_CONFIG_PKT_MODE                 = 0,        
  TEN_XCON_CONFIG_SF_MODE                  = 1,        
  TEN_XCON_CONFIG_GFP_MODE                 = 2,        
  TEN_XCON_CONFIG_AUTO_RECENTER_LOWER      = 3,        
  TEN_XCON_CONFIG_AUTO_RECENTER_UPPER      = 4,        
  TEN_XCON_CONFIG_AUTO_CENTER              = 5,        
  TEN_XCON_IML_THRESH_IML_THRESH           = 6,        
  TEN_XCON_CIRCUIT_THRESHOLD_UPPER_LEVEL   = 7,        
  TEN_XCON_CIRCUIT_THRESHOLD_LOWER_LEVEL   = 8,        
  TEN_XCON_ES_0_THRESHOLD_LEVEL_0_LEVEL    = 9,        
  TEN_XCON_ES_0_THRESHOLD_LEVEL_5_LEVEL    = 10,       
  TEN_XCON_ES_0_PAUSE_LEVEL_0_LEVEL        = 11,       
  TEN_XCON_ES_0_THRESHOLD_LEVEL_3_LEVEL    = 12,       
  TEN_XCON_ES_0_THRESHOLD_LEVEL_4_LEVEL    = 13,       
  TEN_XCON_ES_0_THRESHOLD_LEVEL_2_LEVEL    = 14,       
  TEN_XCON_MAX_PARM                        = 15        
};

enum ten_xcon_pbert_mode_e {
  TEN_XCON_PBERT_ETH_0           = 0,        
  TEN_XCON_PBERT_ETH_2           = 1,        
  TEN_XCON_PBERT_GFP_S           = 2,        
  TEN_XCON_PBERT_GFP_T           = 3,        
  TEN_XCON_PBERT_GFP_T_OS        = 4,        
  TEN_XCON_PBERT_FC              = 5,        
  TEN_XCON_PBERT_ETH_3           = 6,        
  TEN_XCON_PBERT_ETH_0_PRBS      = 7,        
  TEN_XCON_PBERT_FC_PRBS         = 8,        
  TEN_XCON_PBERT_CUSTOM_MODE1    = 9,        
  TEN_XCON_PBERT_CUSTOM_MODE2    = 10,       
  TEN_XCON_PBERT_MAX_MODE        = 11        
};

enum ten_xcon_pbert_parm_e {
  TEN_XCON_PBERT_CONFIG_SF_MODE            = 0,        
  TEN_XCON_PBERT_CONFIG_PKT_MODE           = 1,        
  TEN_XCON_PBERT_CONFIG_GFP_MODE           = 2,        
  TEN_XCON_PBERT_MODE_PROFILE              = 3,        
  TEN_XCON_PBERT_MODE_TRAFFIC              = 4,        
  TEN_XCON_PBERT_PROTOCOL_ETH_DA           = 5,        
  TEN_XCON_PBERT_PROTOCOL_FC_EOF           = 6,        
  TEN_XCON_PBERT_PROTOCOL_FC_SOF           = 7,        
  TEN_XCON_PBERT_PCTRL_FR_SEQNUM           = 8,        
  TEN_XCON_PBERT_PCTRL_FR_TYPE             = 9,        
  TEN_XCON_PBERT_ULEN_MODE                 = 10,       
  TEN_XCON_PBERT_ULEN_RNDMASK              = 11,       
  TEN_XCON_PBERT_ULENMAX                   = 12,       
  TEN_XCON_PBERT_ULENMIN                   = 13,       
  TEN_XCON_PBERT_UCTRL                     = 14,       
  TEN_XCON_PBERT_IFG_CNT                   = 15,       
  TEN_XCON_PBERT_FPAT01_FPAT0              = 16,       
  TEN_XCON_PBERT_FPAT01_FPAT1              = 17,       
  TEN_XCON_PBERT_FPAT23_FPAT2              = 18,       
  TEN_XCON_PBERT_FPAT23_FPAT3              = 19,       
  TEN_XCON_PBERT_FPAT45_FPAT4              = 20,       
  TEN_XCON_PBERT_FPAT45_FPAT5              = 21,       
  TEN_XCON_PBERT_FPAT67_FPAT6              = 22,       
  TEN_XCON_PBERT_FPAT67_FPAT7              = 23,       
  TEN_XCON_PBERT_PCTRL_OS0_COL1_C          = 24,       
  TEN_XCON_PBERT_MAX_PARM                  = 25        
};

enum ten_hl_resets_block_enums {
  TEN_HL_RESETS_BLOCK_SYNCDSYNC = 0x0001,
  TEN_HL_RESETS_BLOCK_FEC       = 0x0002,
  TEN_HL_RESETS_BLOCK_N40G      = 0x0004,
  TEN_HL_RESETS_BLOCK_N10G      = 0x0008,
  TEN_HL_RESETS_BLOCK_PP10G     = 0x0010,
  TEN_HL_RESETS_BLOCK_XCON      = 0x0020,
  TEN_HL_RESETS_BLOCK_HSIF      = 0x0040,
  TEN_HL_RESETS_BLOCK_ALL       = 0x007F
};

enum ten_hl_resets_global_enums {
  TEN_HL_RESETS_GLOBAL_SYNCDSYNC  = 0x0001,
  TEN_HL_RESETS_GLOBAL_FEC        = 0x0002,
  TEN_HL_RESETS_GLOBAL_N40G       = 0x0004,
  TEN_HL_RESETS_GLOBAL_N10G       = 0x0008,
  TEN_HL_RESETS_GLOBAL_PP10G      = 0x0010,
  TEN_HL_RESETS_GLOBAL_HSIF       = 0x0020,
  TEN_HL_RESETS_GLOBAL_XFI_DSP    = 0x0040,
  TEN_HL_RESETS_GLOBAL_PLL        = 0x0080,
  TEN_HL_RESETS_GLOBAL_CLOCK_LOSS = 0x0100,
  TEN_HL_RESETS_GLOBAL_SDS_MR     = 0x0200,
  TEN_HL_RESETS_GLOBAL_SDS_XFI    = 0x0400,
  TEN_HL_RESETS_GLOBAL_SFI41      = 0x0800,
  TEN_HL_RESETS_GLOBAL_COMMON     = 0x1000,
  TEN_HL_RESETS_GLOBAL_ALL        = 0x1FFF
};

/* There is no "ALL" option here because MRB and XFI are mutually exclusive */
enum ten_hl_mpif_host_enums {
  TEN_HL_MPIF_HOST_MRA  = 0x0001,
  TEN_HL_MPIF_HOST_MRB  = 0x0002,
  TEN_HL_MPIF_HOST_XFI  = 0x0004,
  TEN_HL_MPIF_HOST_MAX  = 0x0007
};

/* There is no "ALL" option here because GFEC and UFEC are mutually exclusive */
enum ten_hl_mpif_block_en_enums {
  TEN_HL_MPIF_BLOCK_EN_HSIF   = 0x0001,
  TEN_HL_MPIF_BLOCK_EN_N40G   = 0x0002,
  TEN_HL_MPIF_BLOCK_EN_N10G   = 0x0004,
  TEN_HL_MPIF_BLOCK_EN_PP10G  = 0x0008,
  TEN_HL_MPIF_BLOCK_EN_MAX    = 0x000F
};

/* There is no "ALL" option here because GFEC and UFEC are mutually exclusive */
enum ten_hl_mpif_fec_en_enums {
  TEN_HL_MPIF_FEC_BYPASS  = 0x0000,
  TEN_HL_MPIF_FEC_EN_GFEC = 0x0001,
  TEN_HL_MPIF_FEC_EN_UFEC = 0x0002
};

enum ten_hl_resets_enums {
  TEN_HL_RESETS_A   = 0x0001,
  TEN_HL_RESETS_B   = 0x0002,
  TEN_HL_RESETS_ALL = 0x0003
};

enum ten_hl_mpif_clock_switch_enums {
  TEN_HL_MPIF_CLOCK_SWITCH_SW_FORCE            =  0,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_MR          =  1,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_XFI         =  2,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_MR       =  3,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_XFI      =  4,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_CLKLOSS          =  5,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_CBRGENAIS_10G =  6,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_CBRGENAIS_40G =  7,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_PN11_10G      =  8,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_PN11_40G      =  9,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_MS_10G        = 10,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_MS_40G        = 11,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_TX_MSAIS         = 12,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_XLOS_MRB2A       = 13,
  TEN_HL_MPIF_CLOCK_SWITCH_HW_LOCKDET_MRB2A    = 14
};

enum hsif_quad_mode_e {
  TEN_GLOBAL_MODE_S_40G    = 0,
  TEN_GLOBAL_MODE_QUAD_10G = 1
};

enum ten_hl_gpllx1_mode {
  TEN_HL_GPLL_MODE_SFI42_40G     = 0,
  TEN_HL_GPLL_MODE_SFI42_10G     = 1,
  TEN_HL_GPLL_MODE_SFI41         = 2,
  TEN_HL_GPLL_MODE_XFI_4GFC      = 3,
  TEN_HL_GPLL_MODE_XFI_2GFC      = 4,
  TEN_HL_GPLL_MODE_XFI_1GFC      = 5,
  TEN_HL_GPLL_MODE_DEFAULT       = 6
};

enum ten_pn11_type_e {
  TEN_PN11_OTUKAIS      = 0,       /* PN-11 unframed unscrambled in Standard OTUk-AIS*/
  TEN_PN11_FRAMED       = 1,       /* PN-11 in entire frame except FAS and FEC */
  TEN_PN11_ENTIRE_ODUK  = 2,       /* PN-11 in entire ODUk */
  TEN_PN11_ENTIRE_OPUK  = 3,       /* PN-11 in entire OPUk */
  TEN_PN11_OPUK_PAYLOAD = 4       /* PN-11 in OPUk payload */
}; 

enum ten_cupll_mode_type_e {
  CUPLL_LOOP_311M_R_10M_C_9_95   = 0,
  CUPLL_LOOP_311M_R_10M_C_11_05  = 1,
  CUPLL_LOOP_311M_R_10M_C_11_7   = 2,
  CUPLL_LOOP_425M_R_10M_C_9_95   = 3,
  CUPLL_LOOP_425M_R_10M_C_11_05  = 4,
  CUPLL_LOOP_425M_R_10M_C_11_7   = 5,
  CUPLL_LOOP_311M_R_160M_C_9_95  = 6,
  CUPLL_LOOP_311M_R_160M_C_11_05 = 7,
  CUPLL_LOOP_311M_R_160M_C_11_7  = 8,
  CUPLL_LOOP_425M_R_160M_C_9_95  = 9,
  CUPLL_LOOP_425M_R_160M_C_11_05 = 10,
  CUPLL_LOOP_425M_R_160M_C_11_7  = 11,
  CUPLL_LOOP_MAX_MODE
};

enum ten_tx_clock_source_e {
  TX_CLOCK_SOURCE_FIXED    = 0,    /* Tx FracDiv off system GPLL, through clock protection mux.  */
  TX_CLOCK_SOURCE_RXDIV    = 1,    /* Recovered/synthesized clock                                */
  TX_CLOCK_SOURCE_EXT_CLK  = 2,    /* Source is external via XFI_TX_CLKREF pin.                  */
  TX_CLOCK_SOURCE_EXT_AUX  = 3,    /* Source is external via XFI_AUX_LPTIME_CLKREF pin.          */
  TX_CLOCK_SOURCE_PILOT    = 4,    /* Fixed source via RX internal pilot, no divider.            */
  TX_CLOCK_SOURCE_PILOTDIV = 5,    /* Fixed source via RX internal pilot, divider and protection.*/
  TX_CLOCK_SOURCE_RXLINE   = 6,    /* Fixed source via RX line (MPIF_RXDIV_CFG0:mode=3).         */
  TX_CLOCK_SOURCE_MAX
};


/* Bugzilla 28006 Start */
enum ten_deskew_enums {
  TEN_SADECO_DESKEW       = 0,	/* Deskew in XCON's SADECO */
  TEN_PP40G_BYPASS_DESKEW = 1,	/* Deskew in bypass of PP40G block */
  TEN_PP40G_DESKEW        = 2   /* Deskew in PP40G block */
};
/* Bugzilla 28006 End */



#ifdef __cplusplus
}
#endif
#endif


