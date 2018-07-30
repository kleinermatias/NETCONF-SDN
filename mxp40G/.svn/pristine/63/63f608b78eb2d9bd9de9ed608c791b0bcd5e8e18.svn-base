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
 * ten_hl_pp10g.c
 *
 * API's for PP10G high level configuration.
 *
 * $Id: ten_hl_pp10g.c,v 1.86 2014/04/02 19:00:12 pptawade Exp $
 *
 */
 
#include "tenabo40.h"

const cs_uint16 ten_pp10g_rx_table[TEN_PP10G_RX_MAX_PARM][TEN_PP10G_RX_MAX_MODE] = {
/*                                                       DISABLE                  ETH_0                    ETH_2                    ETH_4                    GFP_S                    GFP_T                    ETH2_GFP_T               ETH0_GFP_S               XAUI_FC                  FC                       8FC                      XC_GE                    XC_FC                    ETH_4_RA                 FC_RA                    8FC_RA                   XAUI_ETH_4_RA            XAUI_ETH2_GFP_T          XAUI_FC_RA               XAUI_ETH0_GFP_S             XC_FC_RA */
/*                                                       ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============                ======== */
/*              FUNCEN_RX_RX_FEN_XGPCS */  {                       0,                       1,                       1,                       1,                       0,                       0,                       1,                       1,                       0,                       1,                       0,                       1,                       1,                       1,                       1,                       0,                       0,                       0,                       0,                       0,                       1 },
/*              FUNCEN_RX_RX_FEN_EGPCS */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0,                       0,                       0 },
/*                FUNCEN_RX_RX_FEN_GFP */  {                       0,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1 },
/*              FUNCEN_RX_RX_FEN_BASEX */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       1,                       1,                       0 },
/*                FUNCEN_RX_RX_FEN_MAC */  {                       0,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       0,                       0,                       0,                       1,                       0,                       1,                       0,                       0,                       1,                       1,                       0,                       1,                       0 },
/*             FUNCEN_RX_RX_FEN_BYPASS */  {                       0,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       1,                       1,                       1,                       1,                       1,                       0,                       1,                       1,                       0,                       0,                       1,                       0,                       1 },
/*              FUNCEN_RX_RX_FEN_XCODE */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1 },
/*                 FUNCEN_RX_RX_FEN_FC */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       1,                       0,                       1,                       0,                       1,                       1,                       0,                       0,                       1,                       0,                       1 },
/*                   RXCNTRL_RXPROFILE */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0 },
/*                           MODE_MODE */  {                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0 },
/*                     CFG_COM_PROFILE */  {                       0,                       0,                       2,                       4,                       5,                       6,                       2,                       0,                       0,                       0,                       0,                       0,                       0,                       4,                       0,                       0,                       4,                       2,                       0,                       0,                       0 },
/*                  CFG_RX_IFG_MODE_RX */  {                       0,                       0,                       0,                       0,                       8,                       8,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0 },
/*                  CFG_RX_PROMIS_MODE */  {                       0,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       0,                       0,                       0,                       1,                       0,                       1,                       0,                       0,                       1,                       1,                       0,                       1,                       1 }, /* ? */
/*                 RXCNTRL1_RX_PROFILE */  {                       0,                       0,                       2,                       4,                       5,                       6,                       2,                       0,                       7,                       7,                       7,                       4,                       7,                       4,                       7,                       7,                       4,                       2,                       7,                       0,                       7 },
/*                    CNTRL_RX_PROFILE */  {                       0,                       0,                       2,                       4,                       5,                       6,                       2,                       0,                       7,                       7,                       7,                       4,                       7,                       4,                       7,                       7,                       4,                       2,                       7,                       0,                       7 },
/*                    CNTRL_TX_PROFILE */  {                       0,                       0,                       2,                       4,                       0,                       2,                       6,                       5,                       7,                       7,                       7,                       4,                       7,                       4,                       7,                       7,                       4,                       6,                       7,                       5,                       7 },
/*             CNTRL1_DISCARD_ELIGIBLE */  {                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       1,                       0 },
/*                     CNTRL_TRANSLATE */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       0 },
/*                  RATECNTRL_IDLE_ALL */  {                       0,                       0,                       0,                       0,                       1,                       1,                       1,                       1,                       0,                       1,                       1,                       0,                       0,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1 }, /* ?? */
/*                RATECNTRL_SEQ_OS_2ND */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       1,                       1,                       0,                       1,                       0,                       1 }, /* ?? */
/*                RATECNTRL_SEQ_OS_ALL */  {                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0 },
/*             RATECNTRL1_MAP_IDLE_ALL */  {                       0,                       0,                       0,                       0,                       7,                       7,                       0,                       7,                       0,                       7,                       7,                       0,                       0,                       0,                       0,                       0,                       0,                       7,                       0,                       7,                       0 },
/*           RATECNTRL1_MAP_SEQ_OS_2ND */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       2,                       2,                       0,                       0,                       2,                       2,                       2,                       2,                       0,                       2,                       0,                       1 }, /* ?? */
/*           RATECNTRL1_MAP_SEQ_OS_ALL */  {                       0,                       0,                       0,                       0,                       0,                       2,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       2,                       0,                       0,                       0 },
/*                   RATECNTRL_FC_IDLE */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       1,                       0,                       1 }, /* ! */
/*                  RATECNTRL3_MIN_IFG */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       4,                       0,                       0,                       4,                       4,                       4,                       8,                       4,                       0,                       4,                       0,                       4 },
/*                RATECNTRL_CLIENT_ALL */  {                       0,                       0,                       0,                       0,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1,                       1 },
/*        RATECNTRL2_MAP_CLIENT_ALL_HI */  {                       0,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4,                       4 },
/*        RATECNTRL2_MAP_CLIENT_ALL_LO */  {                       0,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3,                       3 } };

const cs_uint16 ten_pp10g_tx_table[TEN_PP10G_TX_MAX_PARM][TEN_PP10G_TX_MAX_MODE] = {
/*                                                       DISABLE                  ETH_0                    ETH_2                    ETH_4                    GFP_S                    GFP_T                    GFP_T_ETH2               GFP_S_ETH0               XAUI_FC                  FC                       8FC                      XC_FC                    XC_GE                    XAUI_ETH_4               XAUI_GFP_T_ETH2          XAUI_GFP_S_ETH0              XC_FC_RA */
/*                                                       ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============             ============                 ======== */
/*              FUNCEN_TX_TX_FEN_XGPCS */  {                       0,                       1,                       1,                       1,                       0,                       0,                       1,                       1,                       0,                       1,                       0,                       1,                       1,                       0,                       0,                       0,                       1 },
/*              FUNCEN_TX_TX_FEN_EGPCS */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0,                       0,                       0,                       0 },
/*                FUNCEN_TX_TX_FEN_GFP */  {                       0,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       0,                       1 },
/*              FUNCEN_TX_TX_FEN_BASEX */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0,                       0,                       1,                       1,                       1,                       0 },
/*                FUNCEN_TX_TX_FEN_MAC */  {                       0,                       1,                       1,                       1,                       0,                       0,                       1,                       1,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       1,                       0 },
/*             FUNCEN_TX_TX_FEN_BYPASS */  {                       0,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       1,                       1,                       1,                       1,                       1,                       0,                       0,                       0,                       1 },
/*              FUNCEN_TX_TX_FEN_XCODE */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       0,                       1 },
/*                  TXCNTRL1_TXPROFILE */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0 },
/*                           MODE_MODE */  {                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       0 },
/*                     CFG_COM_PROFILE */  {                       0,                       0,                       2,                       4,                       0,                       0,                       2,                       0,                       0,                       0,                       0,                       0,                       0,                       4,                       2,                       0,                       0 },
/*                          CFG_TX_IFG */  {                   0x000,                  0x000C,                  0x000C,                  0x000C,                  0x0008,                  0x0008,                  0x0008,                  0x0008,                  0x000C,                  0x000C,                  0x000C,                  0x000C,                  0x000C,                  0x000C,                  0x0008,                  0x0008,                  0x000C },
/*                      CNTRL1_PROFILE */  {                       0,                       0,                       2,                       4,                       5,                       6,                       2,                       0,                       7,                       7,                       7,                       7,                       4,                       4,                       2,                       0,                       7 },
/*                 CNTRL1_NO_IPG_CHECK */  {                       0,                       1,                       1,                       0,                       0,                       0,                       1,                       1,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       1,                       0 },
/*                  TXCNTRL_TX_PROFILE */  {                       0,                       0,                       2,                       4,                       5,                       6,                       2,                       0,                       7,                       7,                       7,                       7,                       4,                       4,                       2,                       0,                       7 },
/*                    CNTRL1_TRANSLATE */  {                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       0,                       0,                       0,                       0,                       0,                       0,                       0,                       1,                       0 },
/*                    CNTRL1_AUTO_FILL */  {                       0,                       1,                       1,                       1,                       0,                       0,                       1,                       1,                       1,                       1,                       1,                       0,                       0,                       1,                       1,                       1,                       1 },
/*              FILLCTRL_REPEAT_ENABLE */  {                       0,                       1,                       1,                       1,                       0,                       0,                       1,                       1,                       1,                       1,                       1,                       0,                       0,                       1,                       1,                       1,                       1 },
/*                FILLCTRL_FILL_ENABLE */  {                       0,                       1,                       1,                       1,                       0,                       0,                       1,                       1,                       1,                       1,                       1,                       0,                       0,                       1,                       1,                       1,                       1 },
/*           FILLCTRL_MAX_FAULT_REPEAT */  {                     0x0,                     0x0,                     0x0,                     0x0,                    0xFF,                    0xFF,                    0xFF,                    0xFF,                     0x0,                     0x0,                     0x0,                     0x0,                     0x0,                     0x0,                    0xFF,                    0xFF,                     0x0 } };

const cs_uint16 ten_pp10g_flow_table[TEN_PP10G_FLOW_MAX_PARM][TEN_PP10G_FLOW_MAX_MODE] = {
/*                                                       GFP_S_P          GFP_S            ETH_4            ETH_4_P           */
/*                                                       ============     ============     ============     ============      */
/*          CFG_TX_PAUSE_PREEMPTIVE_EN */  {               1,               0,               0,               1 },
/*            CFG_TX_PAUSE_REACTIVE_EN */  {               0,               1,               1,               0 },
/*                          PQUANTA_PQ */  {          0x0000,          0x0016,          0x0016,          0x0000 },
/*               PRGQINC_QUANTUM_UPPER */  {            0x0A,            0x00,            0x00,            0x0A },
/*               PRGQINC_QUANTUM_LOWER */  {            0x0A,            0x00,            0x00,            0x0A },
/*                     PFMCTRL_MONITOR */  {               1,               0,               0,               1 },
/*                        PRGRATE_RATE */  {            0x0a,            0x0a,            0x0a,            0x0a },
/*         PFGCTRL_LOWER_THRESHOLD_ONE */  {               1,               0,               0,               1 } };

const cs_char8 *ten_pp10g_rx_debug_str[TEN_PP10G_RX_MAX_MODE] = {
  "TEN_PP10G_RX_DISABLE",
  "TEN_PP10G_RX_ETH_0",
  "TEN_PP10G_RX_ETH_2",
  "TEN_PP10G_RX_ETH_4",
  "TEN_PP10G_RX_GFP_S",
  "TEN_PP10G_RX_GFP_T",
  "TEN_PP10G_RX_ETH2_GFP_T",
  "TEN_PP10G_RX_ETH0_GFP_S",
  "TEN_PP10G_RX_XAUI_FC",
  "TEN_PP10G_RX_FC",
  "TEN_PP10G_RX_8FC",
  "TEN_PP10G_RX_XC_GE",
  "TEN_PP10G_RX_XC_FC",
  "TEN_PP10G_RX_ETH_4_RA",
  "TEN_PP10G_RX_FC_RA",
  "TEN_PP10G_RX_8FC_RA",
  "TEN_PP10G_RX_XAUI_ETH_4_RA",
  "TEN_PP10G_RX_XAUI_ETH2_GFP_T",
  "TEN_PP10G_RX_XAUI_FC_RA",
  "TEN_PP10G_RX_XAUI_ETH0_GFP_S",
  "TEN_PP10G_RX_FC_XC_RA" 
};

const cs_char8 *ten_pp10g_tx_debug_str[TEN_PP10G_TX_MAX_MODE] = {
  "TEN_PP10G_TX_DISABLE",
  "TEN_PP10G_TX_ETH_0",
  "TEN_PP10G_TX_ETH_2",
  "TEN_PP10G_TX_ETH_4",
  "TEN_PP10G_TX_GFP_S",
  "TEN_PP10G_TX_GFP_T",
  "TEN_PP10G_TX_GFP_T_ETH2",
  "TEN_PP10G_TX_GFP_S_ETH0",
  "TEN_PP10G_TX_XAUI_FC",
  "TEN_PP10G_TX_FC",
  "TEN_PP10G_TX_8FC",
  "TEN_PP10G_TX_XC_FC",
  "TEN_PP10G_TX_XC_GE",
  "TEN_PP10G_TX_XAUI_ETH_4",
  "TEN_PP10G_TX_XAUI_GFP_T_ETH2",
  "TEN_PP10G_TX_XAUI_GFP_S_ETH0",
  "TEN_PP10G_TX_XC_FC_RA"
};

const cs_char8 *ten_pp10g_flow_debug_str[TEN_PP10G_FLOW_MAX_MODE] = {
  "TEN_PP10G_FLOW_GFP_S_P",
  "TEN_PP10G_FLOW_GFP_S",
  "TEN_PP10G_FLOW_ETH_4",
  "TEN_PP10G_FLOW_ETH_4_P"
};

/****************************************************************/
/* $rtn_hdr_start  PP10G CONFIG                                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_config(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_uint8 mode_rx, 
                              cs_uint8 mode_tx)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode RX                                       */
/*              o Mode TX                                       */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure a PP10G transmit/receive path.                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mode_rx] parameter is specified as:                     */
/*   the 'mode' parameter for ten_hl_pp10g_rx_init, e.g.        */
/*     TEN_PP10G_RX_GFP_T                                       */
/*     TEN_PP10G_RX_ETH2_GFP_T                                  */
/*                                                              */
/* The [mode_tx] parameter is specified as:                     */
/*   the 'mode' parameter for ten_hl_pp10g_tx_init, e.g.        */
/*     TEN_PP10G_TX_GFP_T                                       */
/*     TEN_PP10G_TX_GFP_T_ETH2.                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_pp10g_config";  
  cs_uint16 temp_dev_id;
  cs_uint16 temp_mod_num;
  cs_uint16 tmp_pp10g_clken_rx;
  cs_uint16 tmp_rs;

  if (mode_rx >= TEN_PP10G_RX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s %d is an Invalid RX Mode!", func, mode_rx);
     return (CS_ERROR);
  }
  
  if (mode_tx >= TEN_PP10G_TX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s %d is an Invalid TX Mode!", func, mode_tx);
     return (CS_ERROR);
  }

  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s()  %s, TEN_SLICE_ALL, %s, %s\n", func, ten_module_strings[module_id&1], ten_pp10g_rx_debug_str[mode_rx], ten_pp10g_tx_debug_str[mode_tx]);
  }
  else if (slice  < TEN_MAX_SLICES) {
    CS_PRINT("%s()  %s, %s, %s, %s \n", func, ten_module_strings[module_id&1], ten_slice_strings[slice], ten_pp10g_rx_debug_str[mode_rx], ten_pp10g_tx_debug_str[mode_tx]);
  } else  {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s %d is an Invalid slice!", func, slice);
     return (CS_ERROR);
  }
  
  temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  temp_mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  
  /* Bugzilla #34099, PP10G initialization sequence update */
  CS_PRINT("The initialization sequence of PP10G is as follows:\n");
  CS_PRINT("(as described in PP10G_MISC_RESET.mpif_rst section, Revision 1.1)\n");

  CS_PRINT("1) When initializing PP10G as part of a chip level reset: Deassert (set to 0)\n");
  CS_PRINT("   mpif_reset hard reset input (sources are: MPIF_GLOBAL_RESET_COMMON[chip,mpif]).\n");
  CS_PRINT("   >>>  This is already done in ten_hl_config_global\n");
  
  CS_PRINT("2) Assert (set to 1) all hard reset inputs\n");
  CS_PRINT("   (MPIF_GLOBAL_RESET_PP10G_A/B[sys,tx,rx]).\n");
  
  /* enable PP10G clock, tx/rx/sys */
  rtn |= ten_mpif_global_clock_disable_pp10g(temp_dev_id, temp_mod_num, slice, CS_TX_AND_RX, CS_ENABLE);
  TEN_MDELAY(6);

  /* this bit is high after initial config, but not after dynamic, so  */
  /* assert now, so that config runs the same for both cases */
  rtn |= ten_pp10g_misc_reset(module_id, slice, CS_RESET_ASSERT);

  /* assert PP10G hard reset, tx/rx/sys */
  rtn |= ten_mpif_global_reset_pp10g(temp_dev_id, temp_mod_num, slice, CS_TX_AND_RX, CS_RESET_ASSERT);
  
  CS_PRINT("3) Enable (set to 1) all clocks (used and unused) via PP10G_MISC_CLKEN_* registers.\n");
  rtn |= ten_pp10g_clken_line_rx_t41(module_id, slice, 1, 1);
  rtn |= ten_pp10g_clken_line_rx(module_id, slice, 1, 1, 1, 1, 1, 1, 1, 1, 1);
  rtn |= ten_pp10g_clken_sys_rx(module_id, slice, 1);
  rtn |= ten_pp10g_clken_line_tx(module_id, slice, 1, 1, 1, 1, 1, 1, 1);
  rtn |= ten_pp10g_clken_sys_tx(module_id, slice, 1, 1);
  
  CS_PRINT("4) short wait for reset to take effect\n");
  CS_PRINT("   (perform a single read access of register PP10G_MISC_CLKEN_LINE_RX).\n");
  tmp_pp10g_clken_rx = ten_pp10g_get_clken_line_rx(module_id, slice);
  
  CS_PRINT("5) Enable (set to 1) application specific required\n");
  CS_PRINT("   clocks via PP10G_MISC_CLKEN_* registers. Disable (set to 0) all other PP10G clocks.\n");
 
  rtn |= ten_pp10g_clken_line_rx_t41(module_id, slice, 0, 0);

  if (mode_rx == TEN_PP10G_RX_DISABLE) {
    tmp_rs = 0;
  }
  else {
    tmp_rs = 1;
  }

  rtn |= ten_pp10g_clken_line_rx(module_id, slice, 
                          ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_BYPASS][mode_rx], 
                          ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_FC][mode_rx], 
                          ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_XGPCS][mode_rx],  
                          ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_XCODE][mode_rx], 
                          ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_MAC][mode_rx], 
                          tmp_rs, /* rx_en_rs */
                          ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_GFP][mode_rx], 
                          ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_EGPCS][mode_rx], 
                          ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_BASEX][mode_rx]);
                          
  rtn |= ten_pp10g_clken_sys_rx(module_id, slice, ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_MAC][mode_rx]);

  if (mode_tx == TEN_PP10G_TX_DISABLE) {
    tmp_rs = 0;
  }
  else {
    tmp_rs = 1;
  }
  
  rtn |= ten_pp10g_clken_line_tx(module_id, slice, 
                          ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_XGPCS][mode_tx],
                          ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_XCODE][mode_tx], 
                          ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_MAC][mode_tx], 
                          tmp_rs, /* tx_en_rs */
                          ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_GFP][mode_tx], 
                          ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_EGPCS][mode_tx], 
                          ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_BASEX][mode_tx]);
                              
  rtn |= ten_pp10g_clken_sys_tx(module_id, slice, 
                         ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_MAC][mode_tx], 
                         ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_MAC][mode_tx]);
  
  /* Bugzilla 34099 extension - prevent releasing misc reset if in disable mode */
  /* Bugzilla 34099 typo: shouldn't deassert if tx and *RX* are are disabled */ 
  if (!((mode_tx == TEN_PP10G_TX_DISABLE) && (mode_rx == TEN_PP10G_RX_DISABLE)))  {
    CS_PRINT("6) Release (set to 0) this soft reset\n");
    CS_PRINT("   (PP10G_MISC_RESET[mpif_rst]).\n");
    rtn |= ten_pp10g_misc_reset(module_id, slice, CS_RESET_DEASSERT);
  }

  CS_PRINT("7) Deassert (set to 0) all remaining hard reset inputs\n");
  CS_PRINT("   (MPIF_GLOBAL_RESET_PP10G_A/B[sys,tx,rx]).\n");
  rtn |= ten_mpif_global_reset_pp10g_sys(temp_dev_id, temp_mod_num, slice, CS_RESET_DEASSERT);
  rtn |= ten_mpif_global_reset_pp10g(temp_dev_id, temp_mod_num , slice, CS_TX_AND_RX, CS_RESET_DEASSERT);

  CS_PRINT("8) Configure PP10G for the required application.\n");
  if (mode_rx == TEN_PP10G_RX_DISABLE) {
    /* Assert hard reset */
    rtn |= ten_mpif_global_reset_pp10g(temp_dev_id, temp_mod_num, slice, CS_RX, CS_RESET_ASSERT);
    /* Disable clock */
    rtn |= ten_mpif_global_clock_disable_pp10g(temp_dev_id, temp_mod_num, slice, CS_RX, CS_DISABLE);
  }
  else {
    rtn |= ten_hl_pp10g_rx_init(module_id, slice, mode_rx);
  }

  if (mode_tx == TEN_PP10G_TX_DISABLE) {
    /* Assert hard reset */
    rtn |= ten_mpif_global_reset_pp10g(temp_dev_id, temp_mod_num, slice, CS_TX, CS_RESET_ASSERT);
    /* Disable clock */
    rtn |= ten_mpif_global_clock_disable_pp10g(temp_dev_id, temp_mod_num, slice, CS_TX, CS_DISABLE);
  }
  else {
    rtn |= ten_hl_pp10g_tx_init(module_id, slice, mode_tx);
  }
  
  CS_PRINT("9) Release applicable PP10G sub-module soft resets in\n");
  CS_PRINT("   the recommended order (against traffic flow).\n");
  CS_PRINT("   >>>  this occurs in API ten_hl_config_remove_soft_resets\n");

  CS_PRINT("%s complete, rtn=%s\n", func, (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G RX INITIALIZATION                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_rx_init(cs_uint16 module_id,
                               cs_uint8 slice,
                               cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure PP10G RX side for traffic.                         */
/* NOTE: To bypass the RX side PP10G use the                    */
/*       ten_xcon_es_select_source API.                         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_PP10G_RX_DISABLE                          = 0,         */
/*   TEN_PP10G_RX_ETH_0 (no Idles or Ordered Sets               */
/*     transported for GFP-F mapping)              = 1,         */
/*   TEN_PP10G_RX_ETH_2 (Ordered Sets but no idles              */
/*     transported for GFP-T mapping)              = 2,         */
/*   TEN_PP10G_RX_ETH_4 (Idles and Ordered Sets                 */
/*     processed for Rate Adjust)                  = 3,         */
/*   TEN_PP10G_RX_GFP_S                            = 4,         */
/*   TEN_PP10G_RX_GFP_T                            = 5,         */
/*   TEN_PP10G_RX_ETH2_GFP_T                       = 6,         */
/*   TEN_PP10G_RX_ETH0_GFP_S                       = 7,         */
/*   TEN_PP10G_RX_XAUI_FC                          = 8,         */
/*   TEN_PP10G_RX_FC                               = 9,         */
/*   TEN_PP10G_RX_8FC                              = 10,        */
/*   TEN_PP10G_RX_XC_GE                            = 11,        */
/*   TEN_PP10G_RX_XC_FC                            = 12,        */
/*   TEN_PP10G_RX_ETH_4_RA                         = 13,        */
/*   TEN_PP10G_RX_FC_RA                            = 14,        */
/*   TEN_PP10G_RX_8FC_RA                           = 15,        */
/*   TEN_PP10G_RX_XAUI_ETH_4_RA                    = 16,        */
/*   TEN_PP10G_RX_XAUI_ETH2_GFP_T                  = 17,        */
/*   TEN_PP10G_RX_XAUI_FC_RA                       = 18,        */
/*   TEN_PP10G_RX_XAUI_ETH0_GFP_S                  = 19.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_pp10g_rx_init, slice = %d\n", slice);
   
  if (mode >= TEN_PP10G_RX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid RX Mode!");
     rtn = CS_ERROR;
     goto RTN_EXIT; 
  }

  CS_PRINT("    mode = (%d) %s\n", mode, ten_pp10g_rx_debug_str[mode]);
  
  CS_PRINT("    FUNCEN_RX_RX_FEN_XGPCS         = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_XGPCS][mode]);
  CS_PRINT("    FUNCEN_RX_RX_FEN_EGPCS         = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_EGPCS][mode]);
  CS_PRINT("    FUNCEN_RX_RX_FEN_GFP           = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_GFP][mode]);
  CS_PRINT("    FUNCEN_RX_RX_FEN_BASEX         = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_BASEX][mode]);
  CS_PRINT("    FUNCEN_RX_RX_FEN_MAC           = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_MAC][mode]);
  CS_PRINT("    FUNCEN_RX_RX_FEN_BYPASS        = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_BYPASS][mode]);
  CS_PRINT("    FUNCEN_RX_RX_FEN_XCODE         = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_XCODE][mode]);
  CS_PRINT("    FUNCEN_RX_RX_FEN_FC            = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_FC][mode]);
  CS_PRINT("    RXCNTRL_RXPROFILE              = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RXCNTRL_RXPROFILE][mode]);
  CS_PRINT("    MODE_MODE                      = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_MODE_MODE][mode]);
  CS_PRINT("    CFG_COM_PROFILE                = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_CFG_COM_PROFILE][mode]);
  CS_PRINT("    CFG_RX_IFG_MODE_RX             = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_CFG_RX_IFG_MODE_RX][mode]);
  CS_PRINT("    CFG_RX_PROMIS_MODE             = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_CFG_RX_PROMIS_MODE][mode]);
  CS_PRINT("    RXCNTRL1_RX_PROFILE            = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RXCNTRL1_RX_PROFILE][mode]);
  CS_PRINT("    CNTRL_RX_PROFILE               = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_CNTRL_RX_PROFILE][mode]);
  CS_PRINT("    CNTRL_TX_PROFILE               = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_CNTRL_TX_PROFILE][mode]);
  CS_PRINT("    CNTRL1_DISCARD_ELIGIBLE        = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_CNTRL1_DISCARD_ELIGIBLE][mode]);
  CS_PRINT("    CNTRL_TRANSLATE                = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_CNTRL_TRANSLATE][mode]);
  CS_PRINT("    RATECNTRL_IDLE_ALL             = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL_IDLE_ALL][mode]);
  CS_PRINT("    RATECNTRL_SEQ_OS_2ND           = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL_SEQ_OS_2ND][mode]);
  CS_PRINT("    RATECNTRL_SEQ_OS_ALL           = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL_SEQ_OS_ALL][mode]);
  CS_PRINT("    RATECNTRL1_MAP_IDLE_ALL        = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL1_MAP_IDLE_ALL][mode]);
  CS_PRINT("    RATECNTRL1_MAP_SEQ_OS_2ND      = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL1_MAP_SEQ_OS_2ND][mode]);
  CS_PRINT("    RATECNTRL1_MAP_SEQ_OS_ALL      = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL1_MAP_SEQ_OS_ALL][mode]);
  CS_PRINT("    RATECNTRL_FC_IDLE              = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL_FC_IDLE][mode]);
  CS_PRINT("    RATECNTRL3_MIN_IFG             = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL3_MIN_IFG][mode]);
  CS_PRINT("    RATECNTRL_CLIENT_ALL           = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL_CLIENT_ALL][mode]);
  CS_PRINT("    RATECNTRL2_MAP_CLIENT_ALL_HI   = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL2_MAP_CLIENT_ALL_HI][mode]);
  CS_PRINT("    RATECNTRL2_MAP_CLIENT_ALL_LO   = 0x%04X\n", ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL2_MAP_CLIENT_ALL_LO][mode]);

  CS_PRINT("Provision High-Level PP10G RX...\n");

  rtn |= ten_pp10g_funcen_rx(module_id, slice, 
                      ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_FC][mode], 
                      ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_BYPASS][mode], 
                      ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_MAC][mode], 
                      ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_XCODE][mode], 
                      ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_EGPCS][mode], 
                      ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_BASEX][mode], 
                      ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_GFP][mode], 
                      ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_XGPCS][mode]);

  if (ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_XGPCS][mode]) {
    rtn |= ten_pp10g_pcs_rx_control_rxprofile(module_id, slice,  
                                     ten_pp10g_rx_table[TEN_PP10G_RX_RXCNTRL_RXPROFILE][mode]);
                                     
    /* Up to sysclk 425, calculated 53125 (0xCF85) */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id, slice, 0xCF85);

    /* Bugzilla #18764, PCS stays in Sync with 16 invalid Sync headers */
    rtn |= ten_pp10g_set_pcs_rx_synoff(module_id, slice, 
                                       TEN_PP10G_PCS_RX_SYNOFF_SYNC_INVALID, 0);
  }                                     

  if (ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_GFP][mode]) {
    rtn |= ten_pp10g_gfp_rx_set_mode(module_id, slice, 
                            ten_pp10g_rx_table[TEN_PP10G_RX_MODE_MODE][mode]);
  }                          
                            
  if (ten_pp10g_rx_table[TEN_PP10G_RX_FUNCEN_RX_RX_FEN_MAC][mode]) { 
    rtn |= ten_pp10g_mac_rx_set_profile(module_id, slice, 
                                 ten_pp10g_rx_table[TEN_PP10G_RX_CFG_COM_PROFILE][mode]);
                                 
    rtn |= ten_pp10g_mac_rx_ifg_mode(module_id, slice, 
                              ten_pp10g_rx_table[TEN_PP10G_RX_CFG_RX_IFG_MODE_RX][mode]);
                              
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode_promis(module_id, slice, 
                              ten_pp10g_rx_table[TEN_PP10G_RX_CFG_RX_PROMIS_MODE][mode]);
  }
  
  rtn |= ten_pp10g_rs_rx_profile(module_id, slice, 
                          ten_pp10g_rx_table[TEN_PP10G_RX_RXCNTRL1_RX_PROFILE][mode]);

  rtn |= ten_pp10g_xgadj_rx_control(module_id, slice, 
                           ten_pp10g_rx_table[TEN_PP10G_RX_CNTRL_TRANSLATE][mode], 
                           ten_pp10g_rx_table[TEN_PP10G_RX_CNTRL_RX_PROFILE][mode], 
                           ten_pp10g_rx_table[TEN_PP10G_RX_CNTRL_TX_PROFILE][mode]);
                           
  rtn |= ten_pp10g_xgadj_rx_discard_eligible(module_id, slice, 
                                      ten_pp10g_rx_table[TEN_PP10G_RX_CNTRL1_DISCARD_ELIGIBLE][mode]);
                                      
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id, slice, 
                                  ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL_IDLE_ALL][mode], 0, 0, 0,
                                  ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL_SEQ_OS_2ND][mode], 
                                  ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL_FC_IDLE][mode]);
                                  
  /* Bugzilla #20305, this table entry was missing */                                  
  rtn |= ten_pp10g_xgadj_seq_os_all(module_id, slice,
            ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL_SEQ_OS_ALL][mode]);
  
  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id, slice, 
                                   ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL1_MAP_IDLE_ALL][mode], 
                                   ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL1_MAP_SEQ_OS_2ND][mode]);
                                   
  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id, slice, 
                                         ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL1_MAP_SEQ_OS_ALL][mode]);

  /* bugzilla #17787, change min_ifg from 4 to 8 for XAUI_ETH_4_RA */
  if (mode == TEN_PP10G_RX_XAUI_ETH_4_RA) {
    rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id, slice, 8);
  }
  else {
    rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id, slice, 
                                   ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL3_MIN_IFG][mode]);
  }
  rtn |= ten_pp10g_xgadj_rx_ratecntrl_client_all(module_id, slice,
                                          ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL_CLIENT_ALL][mode]);
                                          
  rtn |= ten_pp10g_xgadj_rx_rate_control2_hi_lo(module_id, slice,
                                         ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL2_MAP_CLIENT_ALL_HI][mode],
                                         ten_pp10g_rx_table[TEN_PP10G_RX_RATECNTRL2_MAP_CLIENT_ALL_LO][mode]);

  /* Bugzilla #18512, set discard_eligible = 0  */
  /* The default should be to *not discard* the bad FCS Ethernet frames */
  /* as this is the desired behavior in transport applications.         */
  rtn |= ten_pp10g_xgadj_rx_discard_eligible(module_id, slice, 0);
  
  /* Bugzilla #20303, rx_hsifokEn enabled only for XAUI applications. */
  if ((mode == TEN_PP10G_RX_XAUI_FC) ||
      (mode == TEN_PP10G_RX_XAUI_ETH_4_RA) ||
      (mode == TEN_PP10G_RX_XAUI_ETH2_GFP_T) ||
      (mode == TEN_PP10G_RX_XAUI_FC_RA) ||
      (mode == TEN_PP10G_RX_XAUI_ETH0_GFP_S)) {
    rtn |= ten_pp10g_rs_rx_control_hsifoken(module_id, slice, 1);
  }
  else {
    rtn |= ten_pp10g_rs_rx_control_hsifoken(module_id, slice, 0);
  }

  if (rtn == CS_OK) {                                
    CS_PRINT("High-Level PP10G RX Provisioning Complete.\n");
  }
  else {
    CS_PRINT("CS_ERROR in High-Level PP10G RX Provisioning!\n");
  }  

RTN_EXIT:
  return(rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G TX INITIALIZATION                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_tx_init(cs_uint16 module_id,
                               cs_uint8 slice,
                               cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure PP10G TX side for traffic.                         */
/* NOTE: To bypass the TX side PP10G use the                    */
/*       ten_n10g_set_pktie API.                                */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_PP10G_TX_DISABLE                          = 0,         */
/*   TEN_PP10G_TX_ETH_0                            = 1,         */
/*   TEN_PP10G_TX_ETH_2                            = 2,         */
/*   TEN_PP10G_TX_ETH_4                            = 3,         */
/*   TEN_PP10G_TX_GFP_S                            = 4,         */
/*   TEN_PP10G_TX_GFP_T                            = 5,         */
/*   TEN_PP10G_TX_GFP_T_ETH2                       = 6,         */
/*   TEN_PP10G_TX_GFP_S_ETH0                       = 7,         */
/*   TEN_PP10G_TX_XAUI_FC                          = 8,         */
/*   TEN_PP10G_TX_FC                               = 9,         */
/*   TEN_PP10G_TX_8FC                              = 10,        */
/*   TEN_PP10G_TX_XC_FC                            = 11,        */
/*   TEN_PP10G_TX_XC_GE                            = 12,        */
/*   TEN_PP10G_TX_XAUI_ETH_4                       = 13,        */
/*   TEN_PP10G_TX_XAUI_GFP_T_ETH2                  = 14,        */
/*   TEN_PP10G_TX_XAUI_GFP_S_ETH0                  = 15.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_pp10g_tx_init, slice = %d\n", slice);

  if (mode >= TEN_PP10G_TX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid TX Mode!");
     rtn = CS_ERROR;
     goto RTN_EXIT;
  }

  CS_PRINT("    mode = (%d) %s\n", mode, ten_pp10g_tx_debug_str[mode]);

  CS_PRINT("    FUNCEN_TX_TX_FEN_XGPCS         = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_XGPCS][mode]);
  CS_PRINT("    FUNCEN_TX_TX_FEN_EGPCS         = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_EGPCS][mode]);
  CS_PRINT("    FUNCEN_TX_TX_FEN_GFP           = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_GFP][mode]);
  CS_PRINT("    FUNCEN_TX_TX_FEN_BASEX         = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_BASEX][mode]);
  CS_PRINT("    FUNCEN_TX_TX_FEN_MAC           = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_MAC][mode]);
  CS_PRINT("    FUNCEN_TX_TX_FEN_BYPASS        = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_BYPASS][mode]);
  CS_PRINT("    FUNCEN_TX_TX_FEN_XCODE         = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_XCODE][mode]);
  CS_PRINT("    TXCNTRL1_TXPROFILE             = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_TXCNTRL1_TXPROFILE][mode]);
  CS_PRINT("    MODE_MODE                      = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_MODE_MODE][mode]);
  CS_PRINT("    CFG_COM_PROFILE                = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_CFG_COM_PROFILE][mode]);
  CS_PRINT("    CFG_TX_IFG                     = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_CFG_TX_IFG][mode]);
  CS_PRINT("    CNTRL1_PROFILE                 = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_CNTRL1_PROFILE][mode]);
  CS_PRINT("    CNTRL1_NO_IPG_CHECK            = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_CNTRL1_NO_IPG_CHECK][mode]);
  CS_PRINT("    TXCNTRL_TX_PROFILE             = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_TXCNTRL_TX_PROFILE][mode]);
  CS_PRINT("    CNTRL1_TRANSLATE               = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_CNTRL1_TRANSLATE][mode]);
  CS_PRINT("    CNTRL1_AUTO_FILL               = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_CNTRL1_AUTO_FILL][mode]);
  CS_PRINT("    FILLCTRL_REPEAT_ENABLE         = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_FILLCTRL_REPEAT_ENABLE][mode]);
  CS_PRINT("    FILLCTRL_FILL_ENABLE           = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_FILLCTRL_FILL_ENABLE][mode]);
  CS_PRINT("    FILLCTRL_MAX_FAULT_REPEAT      = 0x%04X\n", ten_pp10g_tx_table[TEN_PP10G_TX_FILLCTRL_MAX_FAULT_REPEAT][mode]);
  
  CS_PRINT("Provision High-Level PP10G TX...\n");

  rtn |= ten_pp10g_funcen_tx(module_id, slice, 
                      ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_BYPASS][mode], 
                      ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_MAC][mode], 
                      ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_XCODE][mode], 
                      ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_EGPCS][mode], 
                      ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_BASEX][mode], 
                      ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_GFP][mode], 
                      ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_XGPCS][mode]);
                      
  /* Transport Devices are not supposed to reflect RF upon reception of LF or transmit */
  /* Idles upon reception of RF, that’s supposed to be done by the DTE. The register   */
  /* PP10G_RS_TX_TXCNTRL has the tx_localOrdEn (LF->RF) and tx_remoteOrdEn (RF->/I/)   */
  /* bits, which are enabled by default. This API call clears them.                    */
  rtn |= ten_pp10g_rs_tx_port_ctl_fault_ordered_set_insert(module_id, slice, 0, 0);
                      
  if (ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_XGPCS][mode]) {
    rtn |= ten_pp10g_pcs_tx_profile(module_id, slice, 
                             ten_pp10g_tx_table[TEN_PP10G_TX_TXCNTRL1_TXPROFILE][mode]);
  }                         
                           
  if (ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_GFP][mode]) {
    rtn |= ten_pp10g_gfp_tx_set_mode(module_id, slice, 
                            ten_pp10g_tx_table[TEN_PP10G_TX_MODE_MODE][mode]);
  }                          

  if (ten_pp10g_tx_table[TEN_PP10G_TX_FUNCEN_TX_TX_FEN_MAC][mode]) {
    rtn |= ten_pp10g_mac_tx_set_profile(module_id, slice, 
                                 ten_pp10g_tx_table[TEN_PP10G_TX_CFG_COM_PROFILE][mode]);
                                 
    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id, slice, 
                                            ten_pp10g_tx_table[TEN_PP10G_TX_CFG_TX_IFG][mode]);
  }                             
  
  rtn |= ten_pp10g_rs_tx_profile(module_id, slice, 
                          ten_pp10g_tx_table[TEN_PP10G_TX_TXCNTRL_TX_PROFILE][mode]);
                        
  rtn |= ten_pp10g_xgadj_tx_cntrl1(module_id, slice, 
                            ten_pp10g_tx_table[TEN_PP10G_TX_CNTRL1_AUTO_FILL][mode], 
                            ten_pp10g_tx_table[TEN_PP10G_TX_CNTRL1_TRANSLATE][mode], 
                            ten_pp10g_tx_table[TEN_PP10G_TX_CNTRL1_PROFILE][mode], 
                            ten_pp10g_tx_table[TEN_PP10G_TX_CNTRL1_NO_IPG_CHECK][mode]);
                          
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 
                            ten_pp10g_tx_table[TEN_PP10G_TX_FILLCTRL_FILL_ENABLE][mode]);
                                
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 
                             ten_pp10g_tx_table[TEN_PP10G_TX_FILLCTRL_REPEAT_ENABLE][mode]);
   
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, 
                             TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT,
                             ten_pp10g_tx_table[TEN_PP10G_TX_FILLCTRL_MAX_FAULT_REPEAT][mode]);
   
  if (rtn == CS_OK) {                                
    CS_PRINT("High-Level PP10G TX Provisioning Complete.\n");
  }
  else {
      CS_PRINT("Error in High-Level PP10G TX Provisioning!\n");
  }

RTN_EXIT:
  return(rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G FLOW CONTROL INITIALIZATION            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_flow_init(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure PP10G flow control for traffic.                    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_PP10G_FLOW_GFP_S_P = 0,                                */
/*   TEN_PP10G_FLOW_GFP_S   = 1,                                */
/*   TEN_PP10G_FLOW_ETH_4   = 2,  (Reactive)                    */
/*   TEN_PP10G_FLOW_ETH_4_P = 3   (Preemptive).                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_pp10g_flow_init\nslice = %d\n", slice);

  if (mode >= TEN_PP10G_FLOW_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid Mode!");
     rtn = CS_ERROR;
     goto RTN_EXIT;
  };

  CS_PRINT("mode = (%d) %s\n", mode, ten_pp10g_flow_debug_str[mode]);
 
  CS_PRINT("CFG_TX_PAUSE_PREEMPTIVE_EN     = 0x%04X\n", ten_pp10g_flow_table[TEN_PP10G_FLOW_CFG_TX_PAUSE_PREEMPTIVE_EN][mode]);
  CS_PRINT("CFG_TX_PAUSE_REACTIVE_EN       = 0x%04X\n", ten_pp10g_flow_table[TEN_PP10G_FLOW_CFG_TX_PAUSE_REACTIVE_EN][mode]);
  CS_PRINT("PQUANTA_PQ                     = 0x%04X\n", ten_pp10g_flow_table[TEN_PP10G_FLOW_PQUANTA_PQ][mode]);
  CS_PRINT("PRGQINC_QUANTUM_UPPER          = 0x%04X\n", ten_pp10g_flow_table[TEN_PP10G_FLOW_PRGQINC_QUANTUM_UPPER][mode]);
  CS_PRINT("PRGQINC_QUANTUM_LOWER          = 0x%04X\n", ten_pp10g_flow_table[TEN_PP10G_FLOW_PRGQINC_QUANTUM_LOWER][mode]);
  CS_PRINT("PFMCTRL_MONITOR                = 0x%04X\n", ten_pp10g_flow_table[TEN_PP10G_FLOW_PFMCTRL_MONITOR][mode]);
  CS_PRINT("PRGRATE_RATE                   = 0x%04X\n", ten_pp10g_flow_table[TEN_PP10G_FLOW_PRGRATE_RATE][mode]);
  CS_PRINT("PFGCTRL_LOWER_THRESHOLD_ONE    = 0x%04X\n", ten_pp10g_flow_table[TEN_PP10G_FLOW_PFGCTRL_LOWER_THRESHOLD_ONE][mode]);

  CS_PRINT("Provision High-Level PP10G Flow Control...\n");

  rtn |= ten_pp10g_mac_tx_cfg_pause_en(module_id, slice,
                                ten_pp10g_flow_table[TEN_PP10G_FLOW_CFG_TX_PAUSE_PREEMPTIVE_EN][mode], 
                                ten_pp10g_flow_table[TEN_PP10G_FLOW_CFG_TX_PAUSE_REACTIVE_EN][mode]);

  rtn |= ten_pp10g_mac_tx_pause_quanta(module_id, slice, 
                                ten_pp10g_flow_table[TEN_PP10G_FLOW_PQUANTA_PQ][mode]);

  rtn |= ten_pp10g_mac_tx_pause_request_gen_quanta_increment(module_id, 
                                                      slice, 
                                                      ten_pp10g_flow_table[TEN_PP10G_FLOW_PRGQINC_QUANTUM_UPPER][mode], 
                                                      ten_pp10g_flow_table[TEN_PP10G_FLOW_PRGQINC_QUANTUM_LOWER][mode]);

  rtn |= ten_pp10g_mac_tx_pause_frame_monitor(module_id, slice, 
                                       ten_pp10g_flow_table[TEN_PP10G_FLOW_PFMCTRL_MONITOR][mode]);

  rtn |= ten_pp10g_mac_tx_pause_request_gen_frame_ins_rate(module_id, slice, 
                                                    ten_pp10g_flow_table[TEN_PP10G_FLOW_PRGRATE_RATE][mode]);

  rtn |= ten_pp10g_mac_tx_pause_frame_request_lt1(module_id, slice, 
                                           ten_pp10g_flow_table[TEN_PP10G_FLOW_PFGCTRL_LOWER_THRESHOLD_ONE][mode]);

  if (rtn == CS_OK) {                                
    CS_PRINT("High-Level PP10G Flow Control Provisioning Complete.\n");
  }
  else {
    CS_PRINT("CS_ERROR in High-Level PP10G Flow Control Provisioning!\n");
  }  

RTN_EXIT:
  return(rtn);
}

/****************************************************************/
/* $rtn_hdr_start  FORCE CMF FDI                                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_force_cmf_fdi(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force a CMF FDI on the specified 10G link.                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits a CMF FDI                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 err_code = 0;
  
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (state > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": state out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 

  /* This enables CMF insertion in the Scheduler */
  ten_pp10g_gfp_tx_set_schen1(module_id, slice, state);
  /* CMF has priority over ES data traffic */
  ten_pp10g_gfp_tx_set_schpri1(module_id, slice, state);
  /* PLI=4 */
  ten_pp10g_gfp_set_tx_insert_access_0(module_id, slice, 0x0004);
  /* cHEC is inserted by PP10G */
  ten_pp10g_gfp_set_tx_insert_access_n(module_id, slice, 0x0000);
  /* FDI */
  ten_pp10g_gfp_set_tx_insert_access_n(module_id, slice, 0x8004);
  /* tHEC is inserted by PP10G */
  ten_pp10g_gfp_set_tx_insert_access_n(module_id, slice, 0x0000);
  /* 1000 ticks (equals 1 second) between CMF frames */
  /* Be sure PP10G is receiving a 1 msec tick. These */
  /* registers are used to setup the timer intervals.*/
  /* The exact interval depends on the internal      */
  /* system clock frequency.                         */
  /*  GLB_MISC_GSTI01                                */
  /*  GLB_MISC_GSTI00                                */
  /*  GLB_MISC_GSTI                                  */
  ten_pp10g_gfp_set_tx_insert_cmf_auto(module_id, slice, 0, 0x3E7);
  /* Start periodic CMF insertion */
  ten_pp10g_gfp_set_tx_insert_cmf_auto_bit(module_id, slice, state);

  return(CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  FORCE CMF RDI                                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_force_cmf_rdi(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force a CMF RDI on the specified 10G link.                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits a CMF RDI                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 err_code = 0;
  
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (state > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": state out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 

  /* This enables CMF insertion in the Scheduler */
  ten_pp10g_gfp_tx_set_schen1(module_id, slice, state);
  /* CMF has priority over ES data traffic */
  ten_pp10g_gfp_tx_set_schpri1(module_id, slice, state);
  /* PLI=4 */
  ten_pp10g_gfp_set_tx_insert_access_0(module_id, slice, 0x0004);
  /* cHEC is inserted by PP10G */
  ten_pp10g_gfp_set_tx_insert_access_n(module_id, slice, 0x0000);
  /* RDI */
  ten_pp10g_gfp_set_tx_insert_access_n(module_id, slice, 0x8005);
  /* tHEC is inserted by PP10G */
  ten_pp10g_gfp_set_tx_insert_access_n(module_id, slice, 0x0000);
  /* 1000 ticks (equals 1 second) between CMF frames */
  /* Be sure PP10G is receiving a 1 msec tick. These */
  /* registers are used to setup the timer intervals.*/
  /* The exact interval depends on the internal      */
  /* system clock frequency.                         */
  /*  GLB_MISC_GSTI01                                */
  /*  GLB_MISC_GSTI00                                */
  /*  GLB_MISC_GSTI                                  */
  ten_pp10g_gfp_set_tx_insert_cmf_auto(module_id, slice, 0, 0x3E7);
  /* Start periodic CMF insertion */
  ten_pp10g_gfp_set_tx_insert_cmf_auto_bit(module_id, slice, state);

  return(CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  FORCE CMF DCI                                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_force_cmf_dci(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force a CMF DCI on the specified 10G link.                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits a CMF DCI                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 err_code = 0;
  
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (state > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": state out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 

  /* This enables CMF insertion in the Scheduler */
  ten_pp10g_gfp_tx_set_schen1(module_id, slice, state);
  /* CMF has priority over ES data traffic */
  ten_pp10g_gfp_tx_set_schpri1(module_id, slice, state);
  /* PLI=4 */
  ten_pp10g_gfp_set_tx_insert_access_0(module_id, slice, 0x0004);
  /* cHEC is inserted by PP10G */
  ten_pp10g_gfp_set_tx_insert_access_n(module_id, slice, 0x0000);
  /* DCI */
  ten_pp10g_gfp_set_tx_insert_access_n(module_id, slice, 0x8003);
  /* tHEC is inserted by PP10G */
  ten_pp10g_gfp_set_tx_insert_access_n(module_id, slice, 0x0000);
  /* 1000 ticks (equals 1 second) between CMF frames */
  /* Be sure PP10G is receiving a 1 msec tick. These */
  /* registers are used to setup the timer intervals.*/
  /* The exact interval depends on the internal      */
  /* system clock frequency.                         */
  /*  GLB_MISC_GSTI01                                */
  /*  GLB_MISC_GSTI00                                */
  /*  GLB_MISC_GSTI                                  */
  ten_pp10g_gfp_set_tx_insert_cmf_auto(module_id, slice, 0, 0x3E7);
  /* Start periodic CMF insertion */
  ten_pp10g_gfp_set_tx_insert_cmf_auto_bit(module_id, slice, state);

  return(CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  FORCE 10GE REMOTE FAULT at TX PP10G          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_force_tx_10GE_RF(cs_uint16 module_id,
                                        cs_uint8  slice,
                                        cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force a Remote Fault directly into a 10GE stream at the TX   */
/* PP10G.                                                       */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits a 10GE Remote Fault                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  /* User defined ordered set of 0x00 0x00 0x02 = Remote Fault */
  ret_val = ten_pp10g_rs_tx_port_set_user_defined_ordered_set(module_id, slice, 0x00, 0x00, 0x02);
  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else {
    /* Turn on or off (state) insertion of user defined ordered set */
    ret_val = ten_pp10g_rs_tx_port_ctl_user_defined_ordered_set(module_id, slice, state);
  }

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  FORCE 10GE REMOTE FAULT at RX PP10G          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_force_rx_10GE_RF(cs_uint16 module_id,
                                        cs_uint8  slice,
                                        cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force a Remote Fault directly into a 10GE stream at the RX   */
/* PP10G.                                                       */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port RX PP10G injects a 10GE Remote Fault into the */
/*       XCON.                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;

  /* OutCtrl = 4 = Remote Fault at container rate */
  if (state == 1) {
    ret_val = ten_pp10g_gfp_rx_set_outctrl(module_id, slice, 4);
  }
  else {
    ret_val = ten_pp10g_gfp_rx_set_outctrl(module_id, slice, 0);
  }

  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  FORCE 10GE LOCAL FAULT at TX PP10G           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_force_tx_10GE_LF(cs_uint16 module_id,
                                        cs_uint8  slice,
                                        cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force a Local Fault directly into a 10GE stream at the TX    */
/* PP10G.                                                       */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits a 10GE Local Fault                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  /* User defined ordered set of 0x00 0x00 0x01 = Local Fault */
  ret_val = ten_pp10g_rs_tx_port_set_user_defined_ordered_set(module_id, slice, 0x00, 0x00, 0x01);
  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else {
    /* Turn on or off (state) insertion of user defined ordered set */
    ret_val = ten_pp10g_rs_tx_port_ctl_user_defined_ordered_set(module_id, slice, state);
  }

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  FORCE 10GE LOCAL FAULT at RX PP10G          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_force_rx_10GE_LF(cs_uint16 module_id,
                                        cs_uint8  slice,
                                        cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force a Local Fault directly into a 10GE stream at the RX    */
/* PP10G.                                                       */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port RX PP10G injects a 10GE Local Fault into the  */
/*       XCON.                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;

  /* OutCtrl = 3 = Local Fault at container rate */
  if (state == 1) {
    ret_val = ten_pp10g_gfp_rx_set_outctrl(module_id, slice, 3);
  }
  else {
    ret_val = ten_pp10g_gfp_rx_set_outctrl(module_id, slice, 0);
  }

  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G SET GSTI 6 AND 7                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_set_gsti_for_1ms(cs_uint16 dev_id, 
                                        cs_uint32 sys_clk)
/* INPUTS     : o Device Id                                     */
/*              o Sys Clock                                     */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets GSTI 6 and 7 for 1ms based on sys clock.                */
/*                                                              */
/* The [sys_clk] parameter is specified as:                     */
/*   integer value sys_clk in Hz, 400Mhz is 400000000.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 gsti_val_1ms_msb, gsti_val_1ms_lsb;
  
  gsti_val_1ms_msb = (cs_uint16)((sys_clk / 1000000)>>16);
  gsti_val_1ms_lsb = (cs_uint16)((sys_clk / 1000000) & 0xFFFF);
  
  /* CS_PRINT("%04X %04X\n", gsti_val_1ms_msb, gsti_val_1ms_lsb); */
  
  rtn = ten_glb_misc_set_gsti(dev_id, 6, gsti_val_1ms_msb, gsti_val_1ms_lsb);
  rtn |= ten_glb_misc_set_gsti(dev_id, 7, gsti_val_1ms_msb, gsti_val_1ms_lsb);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RX SRESET                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_pp10g_rx_reset(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control PP10G RX logic reset for all sub-blocks, by applying     */
/* reset in the correct order.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 pp10g_slices = 0;

  CS_PRINT("ten_hl_pp10g_rx_reset, slice=%d\n", slice);

  /* NOTE:  PP10G blocks acted upon only if clock       */
  /* enable and function enable bits are set.           */
  /* Bugzilla #19353, fix bus errors */
    
  pp10g_slices = ten_mpif_global_get_clock_disable_pp10g(
                                     TEN_MOD_ID_TO_DEV_ID(module_id), 
                                     TEN_MOD_ID_TO_MOD_NUM(module_id),
                                     CS_RX);
    
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_xgadj_rx_reset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_xgadj_rx_reset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_xgadj_rx_reset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&      
     !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_xgadj_rx_reset(module_id, TEN_SLICE3, act);
  }
 
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_MAC) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_mac_rx_control_sreset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_MAC) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_mac_rx_control_sreset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_MAC) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_mac_rx_control_sreset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_MAC) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_mac_rx_control_sreset(module_id, TEN_SLICE3, act);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
     /* Bugzilla #36090: fix bus errors */
     ten_pp10g_get_clken_line_rx_en_rs(module_id, TEN_SLICE0) &&
     !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_rs_rx_rxcntrl1(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
     ten_pp10g_get_clken_line_rx_en_rs(module_id, TEN_SLICE1) &&
     !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_rs_rx_rxcntrl1(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
     ten_pp10g_get_clken_line_rx_en_rs(module_id, TEN_SLICE2) &&
     !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_rs_rx_rxcntrl1(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&   
     ten_pp10g_get_clken_line_rx_en_rs(module_id, TEN_SLICE3) &&
     !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_rs_rx_rxcntrl1(module_id, TEN_SLICE3, act);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_FC) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_fc_rx_reset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_FC) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_fc_rx_reset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_FC) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_fc_rx_reset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_FC) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_fc_rx_reset(module_id, TEN_SLICE3, act);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_XGPCS) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_pcs_rx_sreset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_XGPCS) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_pcs_rx_sreset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_XGPCS) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_pcs_rx_sreset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_XGPCS) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_pcs_rx_sreset(module_id, TEN_SLICE3, act);
  } 

  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_XCODE) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_xcode_rx_reset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_XCODE) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_xcode_rx_reset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_XCODE) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_xcode_rx_reset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_XCODE) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_xcode_rx_reset(module_id, TEN_SLICE3, act);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_GFP) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_gfp_rx_control_sreset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_GFP) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_gfp_rx_control_sreset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_GFP) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_gfp_rx_control_sreset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_GFP) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_gfp_rx_control_sreset(module_id, TEN_SLICE3, act);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_EGPCS) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_egpcs_rx_reset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_EGPCS) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_egpcs_rx_reset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_EGPCS) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_egpcs_rx_reset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_EGPCS) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_egpcs_rx_reset(module_id, TEN_SLICE3, act);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_BASEX) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_xaui_rx_reset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_BASEX) &&
     !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_xaui_rx_reset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_BASEX) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_xaui_rx_reset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_rx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_BASEX) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_xaui_rx_reset(module_id, TEN_SLICE3, act);
  }
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G TX SRESET                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_pp10g_tx_reset(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control PP10G TX logic reset for each sub-block, by applying     */
/* reset in the correct order.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{  
  cs_status rtn = CS_OK;
  cs_uint16 pp10g_slices = 0;
  cs_uint32 msec_elapsed = 0;
  cs_uint16 ii;
  
  CS_PRINT("ten_hl_pp10g_tx_reset, slice=%d\n", slice);
   
  /* Bugzilla #34099, pp10g init sequence */
  rtn |= ten_pp10g_tx_alarms_reset(module_id, slice, act);
  rtn |= ten_pp10g_rx_alarms_reset(module_id, slice, act);
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
     !(ten_pp10g_get_misc_reset(module_id, TEN_SLICE0))) {
    rtn |= ten_pp10g_pm_reset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
     !(ten_pp10g_get_misc_reset(module_id, TEN_SLICE1))) {
    rtn |= ten_pp10g_pm_reset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
     !(ten_pp10g_get_misc_reset(module_id, TEN_SLICE2))) {
    rtn |= ten_pp10g_pm_reset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&      
     !(ten_pp10g_get_misc_reset(module_id, TEN_SLICE3))) {
    rtn |= ten_pp10g_pm_reset(module_id, TEN_SLICE3, act);
  }
  
  for (ii=0; ii<TEN_MAX_SLICES; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      if (act == CS_RESET_DEASSERT) {
      
        if (ten_pp10g_get_misc_reset(module_id, ii)) {
          continue;
        }
      
        if (ten_pp10g_pm_get_init_done_status(module_id, ii)) { 
          CS_PRINT("PP10G PM init done\n"); 
        }
        else {
          CS_PRINT("wait for PP10G PM init_done...\n"); 
          do {
            TEN_MDELAY(TEN_PP10G_MSEC_DELAY); 
            msec_elapsed += TEN_PP10G_MSEC_DELAY;
            if (msec_elapsed >= TEN_PP10G_MSEC_TIMEOUT) {
              CS_PRINT("WARNING:  PP10G init_done did not complete."); 
              break;
            }
          } while (!ten_pp10g_pm_get_init_done_status(module_id, ii));
        }
        rtn |= ten_mod_clear_sect_stats(module_id, TEN_ID_PP10G, ii);
      }
    }
  }
  
  /* NOTE:  PP10G blocks acted upon only if clock       */
  /* enable and function enable bits are set.           */
  /* Bugzilla #19353, fix bus errors */
  pp10g_slices = ten_mpif_global_get_clock_disable_pp10g(
                                   TEN_MOD_ID_TO_DEV_ID(module_id), 
                                   TEN_MOD_ID_TO_MOD_NUM(module_id),
                                   CS_TX);
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_BASEX) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_xaui_tx_reset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_BASEX) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_xaui_tx_reset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_BASEX) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_xaui_tx_reset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_BASEX) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_xaui_tx_reset(module_id, TEN_SLICE3, act);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_EGPCS) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_egpcs_tx_reset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_EGPCS) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_egpcs_tx_reset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_EGPCS) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_egpcs_tx_reset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_EGPCS) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_egpcs_tx_reset(module_id, TEN_SLICE3, act);
  }
 
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_GFP) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_gfp_tx_control_sreset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_GFP) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_gfp_tx_control_sreset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_GFP) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_gfp_tx_control_sreset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_GFP) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_gfp_tx_control_sreset(module_id, TEN_SLICE3, act);
  }

  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_XCODE) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_xcode_tx_reset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_XCODE) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_xcode_tx_reset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_XCODE) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_xcode_tx_reset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_XCODE) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_xcode_tx_reset(module_id, TEN_SLICE3, act);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_XGPCS) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_pcs_tx_sreset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_XGPCS) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_pcs_tx_sreset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_XGPCS) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_pcs_tx_sreset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_XGPCS) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_pcs_tx_sreset(module_id, TEN_SLICE3, act);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    ten_pp10g_rs_tx_sreset(module_id, TEN_SLICE0, act, TEN_PP10G_RS_TX_SRESET_ALL);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_rs_tx_sreset(module_id, TEN_SLICE1, act, TEN_PP10G_RS_TX_SRESET_ALL);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_rs_tx_sreset(module_id, TEN_SLICE2, act, TEN_PP10G_RS_TX_SRESET_ALL);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_rs_tx_sreset(module_id, TEN_SLICE3, act, TEN_PP10G_RS_TX_SRESET_ALL);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE0, TEN_PP10G_FUNCEN_MAC) &&
      !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_mac_tx_control_sreset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE1, TEN_PP10G_FUNCEN_MAC) &&
      !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_mac_tx_control_sreset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE2, TEN_PP10G_FUNCEN_MAC) &&
      !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_mac_tx_control_sreset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
      ten_pp10g_get_funcen_tx(module_id, TEN_SLICE3, TEN_PP10G_FUNCEN_MAC) &&
      !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_mac_tx_control_sreset(module_id, TEN_SLICE3, act);
  }
  
  if (((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE0_BITMASK)) {
    rtn |= ten_pp10g_xgadj_tx_reset(module_id, TEN_SLICE0, act);
  }
  if (((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE1_BITMASK)) {
    rtn |= ten_pp10g_xgadj_tx_reset(module_id, TEN_SLICE1, act);
  }
  if (((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE2_BITMASK)) {
    rtn |= ten_pp10g_xgadj_tx_reset(module_id, TEN_SLICE2, act);
  }
  if (((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) &&
     !(pp10g_slices & TEN_SLICE3_BITMASK)) {
    rtn |= ten_pp10g_xgadj_tx_reset(module_id, TEN_SLICE3, act);
  }
  
  return (rtn);
}

/* Bugzilla 24360 Start */
/****************************************************************/
/* $rtn_hdr_start  PP10G CONFIG                                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp10g_config_t41 (cs_uint16 module_id,
                                   cs_uint16 slice,
                                   cs_uint16 client,
                                   cs_uint16 mapper,
                                   cs_uint16 sysclk,
                                   cs_uint16 flow_ctrl_mode,
                                   cs_uint16 gfp_frame_format,
                                   cs_uint16 hsif_is_xaui)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Client Type                                   */
/*              o Mapper Type                                   */
/*              o System Clock                                  */
/*              o Flow Control Mode                             */
/*              o GMP Fame Format                               */
/*              o HSIF is XAUI                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures a PP10G transmit/receive path.                    */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registerd device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */ 
/*                                                              */
/* [slice] parameter specifies the slice:                       */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [client] parameter specifies the traffic type of the client: */
/*   TEN_TRAFFIC_TYPE_10GE_WAN             = 9                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2             = 10                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1             = 11                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3             = 12                 */
/*   TEN_TRAFFIC_TYPE_10GFC                = 13                 */
/*   TEN_TRAFFIC_TYPE_8GFC                 = 14                 */
/*   TEN_TRAFFIC_TYPE_4GFC                 = 15                 */
/*   TEN_TRAFFIC_TYPE_2GFC                 = 16                 */
/*   TEN_TRAFFIC_TYPE_1GFC                 = 17                 */
/*   TEN_TRAFFIC_TYPE_5GB_IB               = 18                 */
/*   TEN_TRAFFIC_TYPE_10GE                 = 20                 */
/*   TEN_TRAFFIC_TYPE_10GE_6_1             = 26                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_2             = 27                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28                 */
/*   TEN_TRAFFIC_TYPE_10GE_RA              = 30                 */
/*   TEN_TRAFFIC_TYPE_10G_IB               = 38                 */
/*   TEN_TRAFFIC_TYPE_12_5G_IB             = 39                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC             = 46                 */
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                 */
/*   TEN_TRAFFIC_TYPE_4GFC_RA              = 48                 */
/*   TEN_TRAFFIC_TYPE_2GFC_RA              = 49                 */
/*   TEN_TRAFFIC_TYPE_1GFC_RA              = 50                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF            = 56                 */
/*   TEN_TRAFFIC_TYPE_10GFC_STD            = 57                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_RA          = 58                 */
/*   TEN_TRAFFIC_TYPE_2GISC                = 59                 */
/*   TEN_TRAFFIC_TYPE_1GE                  = 63                 */
/*   TEN_TRAFFIC_TYPE_FDR10_IB             = 64                 */
/*   TEN_TRAFFIC_TYPE_CBR_10G              = 67                 */
/*                                                              */
/* [mapper] parameter specifies the traffic type of the line:   */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0                  */
/*   TEN_TRAFFIC_TYPE_OTU2                 = 5                  */
/*   TEN_TRAFFIC_TYPE_OTU2E                = 6                  */
/*   TEN_TRAFFIC_TYPE_OTU1F                = 7                  */
/*   TEN_TRAFFIC_TYPE_OTU1E                = 29                 */
/*                                                              */
/* [sysclk] parameter specifies the sysclk frequency in MHz.    */
/*   For example, 400.                                          */
/*                                                              */
/* The [flow_ctrl_mode] parameter specifies the flow control    */
/* mode                                                         */
/*   TEN_PP10G_FLOW_GFP_S_P         = 0                         */
/*   TEN_PP10G_FLOW_GFP_S           = 1                         */
/*   TEN_PP10G_FLOW_ETH_4           = 2  (Reactive)             */
/*   TEN_PP10G_FLOW_ETH_4_P         = 3  (Preemptive)           */
/*   TEN_PP10G_FLOW_MAX_MODE        = 4                         */
/*                                                              */
/* The [gfp_frame_format] parameter specifies the GFP frame     */
/* format                                                       */
/*   TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4  = 0                      */
/*   TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4 = 1                      */
/*   TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC = 2                      */
/*   TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC = 3                      */
/*                                                              */
/* The [hsif_is_xaui] parameter specifies if HSIF is XAUI       */
/*   HSIF is not XAUI = 0                                       */
/*   HSIF is XAUI     = 1                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  ten_syncdsync_cb_t *psyncdsync_cb;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_pp10g_config_t41";  
  cs_uint16 dev_id = 0;
  cs_uint16 temp_mod_num = 0; /* Bug 38849 */

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  temp_mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id); /* Bug 38849 */

  CS_PRINT("%s\n", func);
  CS_PRINT("    %s\n", ten_module_strings[module_id&1]);
  CS_PRINT("    %s\n", ten_slice_strings[slice]);
  CS_PRINT("    client %s\n", ten_hl_config_traffic_types_strings[client]);
  CS_PRINT("    mapper %s\n", ten_hl_config_traffic_types_strings[mapper]);
  CS_PRINT("    sysclk %d\n",  sysclk);
  CS_PRINT("    flow_ctrl_mode %s\n", ten_pp10g_flow_mode_strings[flow_ctrl_mode]);
  CS_PRINT("    gfp_frame_format %s\n", ten_10ge_tc_frame_format_strings[gfp_frame_format]);
  CS_PRINT("    hsif_is_xaui %d\n",  hsif_is_xaui);

  if ((client == TEN_TRAFFIC_TYPE_10GE_7_3) && (mapper == TEN_TRAFFIC_TYPE_OTU2)) {
    /* Line side for Transponder */
    rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_GFP_T, TEN_PP10G_TX_GFP_T);

    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 0x8);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);

    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice,
                                            0x1,   /* idle_all   */
                                            0x0,   /* frames_all */
                                            0x1,   /* client_all */
                                            0x0,   /* seq_os_all */
                                            0x0,   /* seq_os_2nd */
                                            0x0);  /* fc_idle    */
  
    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 
                                             0x7,    /* map_idle_all   */ 
                                             0x0);   /* map_seq_os_2nd */

    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);
  } 
   
   
  else if ((client == TEN_TRAFFIC_TYPE_10GE_7_3) && (mapper == TEN_TRAFFIC_TYPE_ODTU)) {
    /* Muxponder Line side */
    rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_GFP_T, TEN_PP10G_TX_GFP_T);

    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);

    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,       /* idle_all   */
                                            0x0,       /* frames_all */
                                            0x1,       /* client_all */
                                            0x0,       /* seq_os_all */
                                            0x0,       /* seq_os_2nd */
                                            0x0);      /* fc_idle    */

    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 
                                             0x7,      /* map_idle_all   */ 
                                             0x0);     /* map_seq_os_2nd */

    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);
  }

  else if ((client == TEN_TRAFFIC_TYPE_10GE_7_3) && (mapper == TEN_TRAFFIC_TYPE_10GE_7_3)) {
    /* Client side for Transponder and Muxponder */
    if (hsif_is_xaui) {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_XAUI_ETH2_GFP_T, TEN_PP10G_TX_XAUI_GFP_T_ETH2);
    }
    else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH2_GFP_T, TEN_PP10G_TX_GFP_T_ETH2);
      rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);  
    }
  
    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 0x8);

    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,       /* idle_all   */
                                            0x1,       /* frames_all */
                                            0x1,       /* client_all */
                                            0x1,       /* seq_os_all */
                                            0x0,       /* seq_os_2nd */
                                            0x0);      /* fc_idle    */

    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 
                                             0x7,      /* map_idle_all   */ 
                                             0x0);     /* map_seq_os_2nd */

    rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all (module_id, 
                                                            slice, 2);

    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);

  }


  else if ((client == TEN_TRAFFIC_TYPE_10GE_6_2) && (mapper == TEN_TRAFFIC_TYPE_ODTU)) {
    /* Muxponder Line side */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_GFP_S, TEN_PP10G_TX_GFP_S);
    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 0x8);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);

    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,   /* idle_all   */
                                            0x0,   /* frames_all */
                                            0x1,   /* client_all */
                                            0x1,   /* seq_os_all */
                                            0x0,   /* seq_os_2nd */
                                            0x0);  /* fc_idle    */
    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 
               0x7,  /* map_idle_all   */ 
               0x0); /* map_seq_os_2nd */
    rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id, slice, 7);

    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);
    
    rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
    rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);
    
  }

  else if ((client == TEN_TRAFFIC_TYPE_10GE_6_2) && (mapper == TEN_TRAFFIC_TYPE_10GE_6_2)) {
    /* Client side for Transponder and Muxponder */
    if (hsif_is_xaui) {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_XAUI_ETH0_GFP_S, TEN_PP10G_TX_XAUI_GFP_S_ETH0);
    }
    else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH0_GFP_S, TEN_PP10G_TX_GFP_S_ETH0);
      rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);  /* cfg1.2 */
    }
    
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,  /* idle_all   */
                                            0x1,  /* frames_all */ 
                                            0x1,  /* client_all */ 
                                            0x1,  /* seq_os_all */ 
                                            0x0,  /* seq_os_2nd */ 
                                            0x0); /* fc_idle    */
    rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id, slice, 7);
    rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all (module_id, slice, 2);

    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);
  }

  else if ((client == TEN_TRAFFIC_TYPE_10GE_6_1) && (mapper == TEN_TRAFFIC_TYPE_ODTU)) {
    /* Muxponder Line side */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);

    rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);  

    if (hsif_is_xaui) {
      rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                             0x0,   /* idle_all   */
                                             0x0,   /* frames_all */
                                             0x1,   /* client_all */
                                             0x0,   /* seq_os_all */
                                             0x0,   /* seq_os_2nd */
                                             0x0);  /* fc_idle    */
                                             
      rtn |= ten_pp10g_xgadj_rx_rate_control2 (module_id, slice, 0, 4, 3);
      rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice, 1, 1, 1, 1, 1, 1);
    
      rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 0x8);
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
    
      rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 
                                              0x7,  /* map_idle_all   */ 
                                              0x0); /* map_seq_os_2nd */
    
      rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id,   slice,   7);
    }                       
    
    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);

    if (!hsif_is_xaui) {
      CS_PRINT("pp10g !hsif_is_xaui\n");
      rtn |= ten_pp10g_mac_rx_set_profile (module_id, slice, 2);
      rtn |= ten_pp10g_xgadj_rx_control (module_id, slice, 0, 2, 2); 
      rtn |= ten_pp10g_rs_rx_profile (module_id, slice, 2);
    }
    else {
      CS_PRINT("pp10g hsif_is_xaui\n");
    }

  }
  
  else if ((client == TEN_TRAFFIC_TYPE_10GE_6_1) && (mapper == TEN_TRAFFIC_TYPE_10GE_6_1)) {
    /* Client side for Transponder and Muxponder */
    if (hsif_is_xaui) {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
    }
    else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
      /* Bugzilla #22850, fix bus errors */
      rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);  
      
      /* Bugzilla #24492, use ETH2 method */
      rtn |= ten_hl_pp10g_tx_init (module_id, slice, TEN_PP10G_TX_ETH_2); 
    }

    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                             0x1,  /* idle_all   */
                                             0x0,  /* frames_all */ 
                                             0x1,  /* client_all */ 
                                             0x0,  /* seq_os_all */ 
                                             0x1,  /* seq_os_2nd */ 
                                             0x0); /* fc_idle    */
                                             
      rtn |= ten_pp10g_xgadj_rx_rate_control2 (module_id, slice, 0, 4, 3);
      rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice, 1, 1, 1, 1, 1, 1);
    
      rtn |= ten_pp10g_mac_tx_cfg_pause_en (module_id, slice, 0, 1);
      
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);
    
      rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id, slice, 7);
    
      rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all (module_id, slice, 2);
    }                       

    /* Flow control settings in the Ingress direction */
    rtn |= ten_hl_pp10g_flow_init (module_id, slice, flow_ctrl_mode);

    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);

    if (!hsif_is_xaui) {
      /* Bugzilla #24492 - Use ETH2 method */
      rtn |= ten_pp10g_mac_tx_pause_xoff_delay (module_id, slice, 6);
      rtn |= ten_pp10g_mac_tx_pause_quanta (module_id, slice, 128);

      rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 5);
    
      rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 0, 0);
    
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x03FF);
    }
  }
  
  
  else if ((client == TEN_TRAFFIC_TYPE_10GE_7_1) && (mapper == TEN_TRAFFIC_TYPE_ODTU)) {
    /* Line side for Muxponder */
    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4, TEN_PP10G_TX_ETH_4);
     
      /* idle_all=0, frame_all=0, client_all=1, seq_os_all=0,seq_os_2nd=0,fc_idle=0 */
      rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice,0,0,1,0,0,0);
      /* map_frames_all=0  ,map_all_hi= 4  , map_all_lo=3 */
      rtn |= ten_pp10g_xgadj_rx_rate_control2 (module_id, slice,0,4,3);
      rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice,1,1,1,1,1,1);
    }
    else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE); 
    }

    /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
    #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
    rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
    #endif
  }
  
  else if ((client == TEN_TRAFFIC_TYPE_10GE_7_1) && (mapper == TEN_TRAFFIC_TYPE_10GE_7_1)) {
    /* Client side for Transponder and Muxponder */
    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
     
      /* idle_all=1, frame_all=0, client_all=1, seq_os_all=0,seq_os_2nd=1,fc_idle=0 */
      rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 1,0,1,0,1,0);
      /* map_frames_all=0  ,map_all_hi= 4  , map_all_lo=3 */
      rtn |= ten_pp10g_xgadj_rx_rate_control2 (module_id, slice, 0,4,3);
      rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice, 1,1,1,1,1,1);
    } 
    else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE);
      
      /* Bugzilla #22850, fix bus errors */
      rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);  
    }
  }
  /* Bug #40141: New configurations needed for 10GE using GMP_LO */
  else if (((client == TEN_TRAFFIC_TYPE_10GE) && (mapper == TEN_TRAFFIC_TYPE_ODTU)) ||
           ((client == TEN_TRAFFIC_TYPE_CBR_10G) && (mapper == TEN_TRAFFIC_TYPE_ODTU))) {   /* Bugzilla 43573 */
    /* Line side for Muxponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE); 

    /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
    #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
    rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
    #endif
  }
  
  else if (((client == TEN_TRAFFIC_TYPE_10GE) && (mapper == TEN_TRAFFIC_TYPE_10GE)) ||
           ((client == TEN_TRAFFIC_TYPE_CBR_10G) && (mapper == TEN_TRAFFIC_TYPE_CBR_10G))) {   /* Bugzilla 43573 */
    /* Client side for Transponder and Muxponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE);
      
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);  
  }
  
  else if ((client == TEN_TRAFFIC_TYPE_10GE_7_2) && (mapper == TEN_TRAFFIC_TYPE_ODTU)) {
    /* Line side for Muxponder */
    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
    } 
    else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE); 
    }
  }

  else if ((client == TEN_TRAFFIC_TYPE_10GE_7_2) && (mapper == TEN_TRAFFIC_TYPE_OTU1E)) {
    /* Line side for Transponder */
    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
       rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
    } 
    else {
      /* Bug #38916 - For 10GE 7.1/7.2 transponder mapping, use TX DISABLE */
      rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE);
    }

  }
  else if ((client == TEN_TRAFFIC_TYPE_10GE_7_2) && (mapper == TEN_TRAFFIC_TYPE_10GE_7_2)) {
    /* Client side for Transponder and Muxponder */
    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
    } 
    else {
       /* Bug #38916 - For 10GE 7.1/7.2 transponder mapping, use TX DISABLE */
      rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE); 
    }
  }
  else if ((client == TEN_TRAFFIC_TYPE_10GE_7_1) && (mapper == TEN_TRAFFIC_TYPE_OTU2E)) {
    /* Line side for Transponder */
    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
       rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4, TEN_PP10G_TX_ETH_4);

      /* idle_all=0, frame_all=0, client_all=1, seq_os_all=0,seq_os_2nd=0,fc_idle=0 */
      /* rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 0, 0, 1, 0, 0, 0); */
      /* map_frames_all=0  ,map_client_all_hi= 4  , map_client_all_lo=3 */
      /* rtn |= ten_pp10g_xgadj_rx_rate_control2 (module_id, slice, 0, 4, 3); */
      rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice, 1, 1, 1, 1, 1, 1);
    } 
    else {
      /* Bug #38916 - For 10GE 7.1/7.2 transponder mapping, use TX DISABLE */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE);
    }
  }
  /* Bug #40141: New configurations needed for 10GE using GMP_LO */
  else if ((client == TEN_TRAFFIC_TYPE_10GE) && (mapper == TEN_TRAFFIC_TYPE_OTU2E)) {
    /* Line side for Transponder */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE);
  }

  /* Bugzilla 38871 Start */
  else if ((client == TEN_TRAFFIC_TYPE_1GE) && (mapper == TEN_TRAFFIC_TYPE_OTU2)) {
    /* Line side for Transponder */
    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4, TEN_PP10G_TX_ETH_4);

      rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice, 1, 1, 1, 1, 1, 1);
    } else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE);
    }
    /* Turn off xgpcs */
    /* rx_en_bypass, rx_en_fc, rx_en_xgpcs, rx_en_xcode, rx_en_mac, rx_en_rs, rx_en_gfp, rx_en_egpcs, rx_en_basex */
    rtn |= ten_pp10g_clken_line_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    /* rx_fen_fc, rx_fen_bypass, rx_fen_mac, rx_fen_xcode, rx_fen_egpcs, rx_fen_basex, rx_fen_gfp, rx_fen_xgpcs */
    rtn |= ten_pp10g_funcen_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 0);
    /* Local clock enables and function enables */
    rtn |= ten_pp10g_mon10b_ber10b_en_t41(module_id, slice, CS_ENABLE);
    /* Toggle PP10G System reset */
    rtn |= ten_pp10g_misc_reset(module_id, slice, CS_RESET_TOGGLE);
    /* Deassert local MON10B and BER10B resets */
    rtn |= ten_pp10g_mon10b_reset_t41(module_id, slice, CS_RESET_DEASSERT);
    rtn |= ten_pp10g_ber10b_reset_t41(module_id, slice, CS_RESET_DEASSERT);
  }
  else if ((client == TEN_TRAFFIC_TYPE_1GE) && (mapper == TEN_TRAFFIC_TYPE_ODTU)) {
    /* Line side for Muxponder */
    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4, TEN_PP10G_TX_ETH_4);

      rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice,1,1,1,1,1,1);
    }
    else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE); 
    }
    
    /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
    #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
    rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
    #endif
    
    /* Turn off xgpcs */
    /* rx_en_bypass, rx_en_fc, rx_en_xgpcs, rx_en_xcode, rx_en_mac, rx_en_rs, rx_en_gfp, rx_en_egpcs, rx_en_basex */
    rtn |= ten_pp10g_clken_line_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    /* rx_fen_fc, rx_fen_bypass, rx_fen_mac, rx_fen_xcode, rx_fen_egpcs, rx_fen_basex, rx_fen_gfp, rx_fen_xgpcs */
    rtn |= ten_pp10g_funcen_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 0);
    /* Local clock enables and function enables */
    rtn |= ten_pp10g_mon10b_ber10b_en_t41(module_id, slice, CS_ENABLE);
    /* Toggle PP10G System reset */
    rtn |= ten_pp10g_misc_reset(module_id, slice, CS_RESET_TOGGLE);
    /* Deassert local MON10B and BER10B resets */
    rtn |= ten_pp10g_mon10b_reset_t41(module_id, slice, CS_RESET_DEASSERT);
    rtn |= ten_pp10g_ber10b_reset_t41(module_id, slice, CS_RESET_DEASSERT);
  }
  else if ((client == TEN_TRAFFIC_TYPE_1GE) && (mapper == TEN_TRAFFIC_TYPE_1GE)) {
    /* Client side for Transponder and Muxponder */
    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);

      rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice, 1,1,1,1,1,1);
    } else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE);
      rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);  
    }
    /* Turn off xgpcs */
    /* rx_en_bypass, rx_en_fc, rx_en_xgpcs, rx_en_xcode, rx_en_mac, rx_en_rs, rx_en_gfp, rx_en_egpcs, rx_en_basex */
    rtn |= ten_pp10g_clken_line_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    /* rx_fen_fc, rx_fen_bypass, rx_fen_mac, rx_fen_xcode, rx_fen_egpcs, rx_fen_basex, rx_fen_gfp, rx_fen_xgpcs */
    rtn |= ten_pp10g_funcen_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 0);
    /* Local clock enables and function enables */
    rtn |= ten_pp10g_mon10b_ber10b_en_t41(module_id, slice, CS_ENABLE);
    /* Toggle PP10G System reset */
    rtn |= ten_pp10g_misc_reset(module_id, slice, CS_RESET_TOGGLE);
    /* Deassert local MON10B and BER10B resets */
    rtn |= ten_pp10g_mon10b_reset_t41(module_id, slice, CS_RESET_DEASSERT);
    rtn |= ten_pp10g_ber10b_reset_t41(module_id, slice, CS_RESET_DEASSERT);
  }
  /* Bugzilla 38871 End*/

  /* Bugzilla #37204: 10ge6.1 (LAN) to WAN config */
  else if ((client == TEN_TRAFFIC_TYPE_10GE_6_1) && ((mapper == TEN_TRAFFIC_TYPE_OTU2) || 
                                                     (mapper == TEN_TRAFFIC_TYPE_OC192) )) {
    /* Line side for Transponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);

    rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);  

    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                              0x0,   /* idle_all   */
                                              0x0,   /* frames_all */
                                              0x1,   /* client_all */
                                              0x0,   /* seq_os_all */
                                              0x0,   /* seq_os_2nd */
                                              0x0);  /* fc_idle    */
      rtn |= ten_pp10g_xgadj_rx_rate_control2 (module_id, slice, 0, 4, 3);
      rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice, 1, 1, 1, 1, 1, 1);
      
      rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 0x8);
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
      rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 
                                               0x7,  /* map_idle_all   */ 
                                               0x0); /* map_seq_os_2nd */
      rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id,   slice,   7);
    } 
    else {
      /* Bugzilla #26218, fix xaui 10ge6.1 into otu2 */
      rtn |= ten_pp10g_mac_rx_set_profile (module_id, slice, 2);
      rtn |= ten_pp10g_xgadj_rx_control (module_id, slice, 0, 2, 2); 
      rtn |= ten_pp10g_rs_rx_profile (module_id, slice, 2);
    }
   
    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);
  } 
  
  else if ((client == TEN_TRAFFIC_TYPE_10GE_6_2) && (mapper == TEN_TRAFFIC_TYPE_OTU2)) {
    /* Line side for Transponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_GFP_S, TEN_PP10G_TX_GFP_S);
  
    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 0x8);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
  
    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,   /* idle_all   */
                                            0x0,   /* frames_all */
                                            0x1,   /* client_all */
                                            0x1,   /* seq_os_all */
                                            0x0,   /* seq_os_2nd */
                                            0x0);  /* fc_idle    */
  
    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 
                                             0x7,  /* map_idle_all   */ 
                                             0x0); /* map_seq_os_2nd */

    rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id, slice, 7);

    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);
  }
  
   
  else if ((client == TEN_TRAFFIC_TYPE_10GE_RA) && (mapper == TEN_TRAFFIC_TYPE_10GE_RA)) {
    /* Client side for Transponder and Muxponder */

    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
    } else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
      rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);  /* cfg1.2 */
    }

    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,  /* idle_all   */
                                            0x0,  /* frames_all */ 
                                            0x1,  /* client_all */ 
                                            0x0,  /* seq_os_all */ 
                                            0x1,  /* seq_os_2nd */ 
                                            0x0); /* fc_idle    */
                                         
    rtn |= ten_pp10g_xgadj_rx_rate_control2 (module_id, slice, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_pause_en (module_id, slice, 0, 1);

    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);
    rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id, slice, 7);
    rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all (module_id, slice, 2);
    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);

    /* Provision Flow Control */
    rtn |= ten_hl_pp10g_flow_init (module_id, slice, flow_ctrl_mode);
  } 
   
  else if ((client == TEN_TRAFFIC_TYPE_10GE_RA) && 
           ((mapper == TEN_TRAFFIC_TYPE_OTU2) || (mapper == TEN_TRAFFIC_TYPE_OTU2E))) {
    /* Line side for Transponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,   /* idle_all   */  /* Bugzilla 31786 */
                                            0x0,   /* frames_all */
                                            0x1,   /* client_all */
                                            0x0,   /* seq_os_all */
                                            0x0,   /* seq_os_2nd */
                                            0x0);  /* fc_idle    */
                                           
    rtn |= ten_pp10g_xgadj_rx_rate_control2 (module_id, slice, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 0x8);
    
    /* Bugzilla #35032 - Fix 10GE_RA into OTU2e config CRC errors with -15ppm to -105ppm */
    if (mapper == TEN_TRAFFIC_TYPE_OTU2E) {
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    }
    else {
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
      rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    }
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
    rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id, slice, 
                                             0x7,  /* map_idle_all   */ 
                                             0x0); /* map_seq_os_2nd */

    rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id, slice, 7);

    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);
  } 
   
  else if (((client == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) && (mapper == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2)) ||
           ((client == TEN_TRAFFIC_TYPE_10GE_GFPF) && (mapper == TEN_TRAFFIC_TYPE_10GE_GFPF))) {  /* Bugzilla 29991 */
    /* Client side for Transponder and Muxponder */
    if (hsif_is_xaui) {    /* TEN_HSIF_PROTOCOL_XAUI */
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_XAUI_ETH0_GFP_S, TEN_PP10G_TX_XAUI_GFP_S_ETH0);
    } else {
      rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH0_GFP_S, TEN_PP10G_TX_GFP_S_ETH0);
      rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);
    }

    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,  /* idle_all   */
                                            0x1,  /* frames_all */ 
                                            0x1,  /* client_all */ 
                                            0x1,  /* seq_os_all */ 
                                            0x0,  /* seq_os_2nd */ 
                                            0x0); /* fc_idle    */
                                            
    rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id, slice, 7);
    rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all (module_id, slice, 2);
    
    /* Bugzilla #22743, fix for 10ge_gfpf_oc192_odu mode */
    /* Flow control settings in the Ingress direction */
    rtn |= ten_hl_pp10g_flow_init (module_id, slice, flow_ctrl_mode);

    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);
  } 
  else if ((client == TEN_TRAFFIC_TYPE_10GE_RA) && (mapper == TEN_TRAFFIC_TYPE_ODTU)) {
    /* Line side for Muxponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
    
    /* Bugzilla #39308: Add support for 10GE_RA->OTU2e->OTU3V */
    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,   /* idle_all   */
                                            0x0,   /* frames_all */
                                            0x1,   /* client_all */
                                            0x0,   /* seq_os_all */
                                            0x0,   /* seq_os_2nd */
                                            0x0);  /* fc_idle    */
                                           
    rtn |= ten_pp10g_xgadj_rx_rate_control2 (module_id, slice, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode (module_id, slice, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 0x8);
    
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    
    /* Bugzilla #39308: Add support for 10GE_RA->OTU2e->OTU3V */
    pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
    if (pdevcb) {
      psyncdsync_cb = &pdevcb->syncdsync_thread_cb[slice];
      if (psyncdsync_cb) {
        /* check if OTU2E (10399525320.0), if > OTU2 (10037273920.0), using mid point value to avoid rounding problems */
        if (psyncdsync_cb->xcon_client_rate > 10100000000.0) {
          CS_PRINT("mux_odu2v_rate=OTU2E, use 10GE_RA->OTU2e->OTU3V\n");
          rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
          rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
        }
      }
    }
   
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 
                                             0x7,  /* map_idle_all   */ 
                                             0x0); /* map_seq_os_2nd */

    rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id,   slice,   7);
    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);
  }
       
  else if ((client == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) && (mapper == TEN_TRAFFIC_TYPE_ODTU)) {
    /* Line side for Muxponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_GFP_S, TEN_PP10G_TX_GFP_S);
    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 0x8);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);

    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,   /* idle_all   */
                                            0x0,   /* frames_all */
                                            0x1,   /* client_all */
                                            0x1,   /* seq_os_all */
                                            0x0,   /* seq_os_2nd */
                                            0x0);  /* fc_idle    */
      
    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 
                                             0x7,  /* map_idle_all   */ 
                                             0x0); /* map_seq_os_2nd */

    rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id, slice, 7);
    /* These are for jumbo frames */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);

    rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
    rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);
    
     /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
    rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);
                           
    /* MFALGNE = 0x0    Disables the MFAS alignment process */
    rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);
  }
    
  else if (((client == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) && (mapper == TEN_TRAFFIC_TYPE_OTU2)) ||
           ((client == TEN_TRAFFIC_TYPE_10GE_GFPF) && (mapper == TEN_TRAFFIC_TYPE_OC192))) {  /* Bugzilla 29991 */
    /* Line side for Transponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_GFP_S, TEN_PP10G_TX_GFP_S);
    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg (module_id, slice, 0x8);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 
                                            0x1,   /* idle_all   */
                                            0x0,   /* frames_all */
                                            0x1,   /* client_all */
                                            0x1,   /* seq_os_all */
                                            0x0,   /* seq_os_2nd */
                                            0x0);  /* fc_idle    */
    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 
                                             0x7,  /* map_idle_all   */ 
                                             0x0); /* map_seq_os_2nd */
    rtn |= ten_pp10g_xgadj_map_seq_os_all (module_id, slice, 7);
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 0x2710);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0x0, 0x2710);
  }
  else if ((client == TEN_TRAFFIC_TYPE_10GE_TC) && (mapper == TEN_TRAFFIC_TYPE_OTU2E)) {
    /* Line side for Transponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_XC_GE, TEN_PP10G_TX_XC_GE);
    if (gfp_frame_format == TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4) {
      rtn |= ten_pp10g_xcode_config (module_id, slice, CS_TX_AND_RX, TEN_28_BLOCKS_PER_SUPERBLOCK_CRC4, TEN_4_RES_OCTETS, 5);
    }
    else if (gfp_frame_format == TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4) {
      rtn |= ten_pp10g_xcode_config (module_id, slice, CS_TX_AND_RX, TEN_28_BLOCKS_PER_SUPERBLOCK_CRC4, TEN_4_RES_OCTETS, 11);
    }
    else if (gfp_frame_format == TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC) {
      rtn |= ten_pp10g_xcode_config (module_id, slice, CS_TX_AND_RX, TEN_32_BLOCKS_PER_SUPERBLOCK_NOCRC, TEN_4_RES_OCTETS, 4);
    }
    else if (gfp_frame_format == TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC) {
      rtn |= ten_pp10g_xcode_config (module_id, slice, CS_TX_AND_RX, TEN_32_BLOCKS_PER_SUPERBLOCK_NOCRC, TEN_4_RES_OCTETS, 8);
    }

    rtn |= ten_pp10g_rs_rx_control (module_id, slice, 0, 1, 1, 1, 0); /* disable HSIF OK signal to RS-Rx */
    rtn |= ten_pp10g_gfp_tx_set_payload_header (module_id, slice, 0x0, 0x1); /* enable GFP PH PFI */
    rtn |= ten_pp10g_gfp_tx_upi (module_id, slice, 0xFE, 0x15); /* set the tx UPID to 0x15 */
    rtn |= ten_pp10g_gfp_rx_set_expected_upi (module_id, slice, 0xFE, 0x15); /* set the rx ExUPID to 0x15 */

    /* Set fault_repeat to 3FF (max'd out for now) */
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_CONTROL, 0xF);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x3FF);

    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 10000);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0, 10000);
  }

  else if ((client == TEN_TRAFFIC_TYPE_10GE_TC) && (mapper == TEN_TRAFFIC_TYPE_10GE_TC)) {
    /* Client side for Transponder and Muxponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_ETH_4, TEN_PP10G_TX_ETH_4);
    rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk * 125);

    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice,0,0,1,0,0,0); /* clients all */
    rtn |= ten_pp10g_rs_rx_control (module_id, slice, 0, 1, 1, 1, 0); /* disable HSIF OK signal to RS-Rx */
    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 0, 0, 1 ,0 ,0, 0); /* clients all */

    /* Setting pp10g for jumbo frames") */
    rtn |= ten_pp10g_mac_rx_maxlen (module_id, slice, 10000);
    rtn |= ten_pp10g_xgadj_tx_maxframe (module_id, slice, 0, 10000);
  }
  
  else if ((client == TEN_TRAFFIC_TYPE_10GFC) && (mapper == TEN_TRAFFIC_TYPE_10GFC)) {
    /* Client side for Transponder and Muxponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_FC, TEN_PP10G_TX_FC);
    /* Set BER timer */

    rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk*125);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0);
     
     /* Idle_all, client_all */
    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice,  1, 0, 1, 0, 0, 0);
    
    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 7, 2);
     /* ifg = 4 */
    rtn |= ten_pp10g_xgadj_rx_rate_control3 (module_id, slice, 4);
  }
  
  else if ((client == TEN_TRAFFIC_TYPE_10GFC) && (mapper == TEN_TRAFFIC_TYPE_OTU1F)) {
    /* Line side for Transponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_FC, TEN_PP10G_TX_FC);
    /* Set BER timer */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk*125); 
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0);
    
     /* client_all */
    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice, 0, 0, 1, 0, 0, 0);
    rtn |= ten_pp10g_xgadj_rx_rate_control3 (module_id, slice, 4);
  }

  else if (((client == TEN_TRAFFIC_TYPE_10GFC_TC)     && (mapper == TEN_TRAFFIC_TYPE_10GFC_TC)) ||
           ((client == TEN_TRAFFIC_TYPE_10GFC_TC_G709) && (mapper == TEN_TRAFFIC_TYPE_10GFC_TC_G709))) { /* Bug 31054 */
    /* Client side for Transponder and Muxponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_FC, TEN_PP10G_TX_FC);
    /* Set BER timer */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk*125);
  
    /* Bugzilla 36463 Start: Turn off Rate Adjust */
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl (module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0);
    /* Idle_all, client_all = 0 */
    rtn |= ten_pp10g_xgadj_rx_rate_control (module_id, slice,  0, 0, 0, 0, 0, 0);
    /* Bugzilla 36463 End */
  }
  
  else if (((client == TEN_TRAFFIC_TYPE_10GFC_TC) || (client == TEN_TRAFFIC_TYPE_10GFC_TC_G709)) && /* Bug 31054 */
            (mapper == TEN_TRAFFIC_TYPE_OTU2E)) {
    /* Line side for Transponder */
    rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_XC_FC, TEN_PP10G_TX_XC_FC);
    /* Set BER timer */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id, slice, sysclk*125); 

    rtn |= ten_pp10g_gfp_tx_set_payload_header(module_id, slice, 0, 1);
    rtn |= ten_pp10g_gfp_tx_upi( module_id, slice, 0xfe, 0x15);
    rtn |= ten_pp10g_gfp_rx_set_expected_upi(module_id, slice, 0xfe, 0x15);

    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0);

    /* Bugzilla 36463 Start: Turn off Rate Adjust */
    /* Idle_all, client_all = 0 */
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id, slice, 0, 0, 0, 0, 0, 0);
    /* Bugzilla 36463 End */


    /* Standard compliant provisioning of XCODE Remapper */
    if (client == TEN_TRAFFIC_TYPE_10GFC_TC_G709) { /* Bug 31054 */
      rtn |= ten_pp10g_xcode_remap_g709_provision(module_id,  slice);
    }
  }
  
  else if (((client == TEN_TRAFFIC_TYPE_10GFC_TC) || (client == TEN_TRAFFIC_TYPE_10GFC_TC_G709)) && /* Bug 31054 */
            (mapper == TEN_TRAFFIC_TYPE_ODTU)) {
    /* Line side for Muxponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_XC_FC, TEN_PP10G_TX_XC_FC);
    rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk*125); 
    rtn |= ten_pp10g_gfp_tx_set_payload_header (module_id, slice, 0, 1);

    /* Standard compliant provisioning of XCODE Remapper */
    if (client == TEN_TRAFFIC_TYPE_10GFC_TC_G709) { /* Bug 31054 */
      rtn |= ten_pp10g_xcode_remap_g709_provision(module_id,  slice);
    }
  }
  
  else if ((client == TEN_TRAFFIC_TYPE_10GFC_TC_RA) && (mapper == TEN_TRAFFIC_TYPE_10GFC_TC_RA)) {
    /* Client side for Transponder and Muxponder */
    rtn |= ten_hl_pp10g_config (module_id, slice, TEN_PP10G_RX_FC_RA, TEN_PP10G_TX_FC);
    /* Set BER timer */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer (module_id, slice, sysclk*125);

    /* Provision Flow Control */
    /* Bugzilla 37543 Removed code - flow control doesn't belong here */

    rtn |= ten_pp10g_xgadj_below_disable(module_id, slice, 0);

    /* Bugzilla 37543 Start */
    /* Set MIN_IFG to 8 */
    rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id, slice, 8);
    /* Turn off repeat enable */
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    /* Change idle_all to idle_2nd only */
    rtn |= ten_pp10g_xgadj_rx_ratecntrl_idle_all(module_id, slice, 0);
    rtn |= ten_pp10g_xgadj_rx_ratecntrl_idle_2nd(module_id, slice, 1);
    /* Change threshold to rate adjust mappings so they are the same in both directions        */
    /* Previously was set to look at threshold one from the line side and threshold two        */
    /* from the client side - now set to threshold one for map_seq_os_2nd from both directions */
    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 0, 1);
    /* Bugzilla 37543 End */
    }
  
  else if ((client == TEN_TRAFFIC_TYPE_10GFC_TC_RA) && (mapper == TEN_TRAFFIC_TYPE_OTU2E)) {
    /* Line side for Transponder */
    rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_XC_FC_RA, TEN_PP10G_TX_XC_FC_RA);
    /* Set BER timer */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id, slice, sysclk*125); 

    rtn |= ten_pp10g_gfp_tx_set_payload_header(module_id, slice, 0, 1);
    rtn |= ten_pp10g_gfp_tx_upi( module_id, slice, 0xfe, 0x15);
    rtn |= ten_pp10g_gfp_rx_set_expected_upi(module_id, slice, 0xfe, 0x15);

    rtn |= ten_pp10g_xgadj_below_disable(module_id, slice, 0);

    /* Standard compliant provisioning of XCODE Remapper */
    rtn |= ten_pp10g_xcode_remap_g709_provision(module_id,  slice);

    /* Bugzilla 37543 Start */
    /* Set MIN_IFG to 8 */
    rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id, slice, 8);
    /* Turn off repeat enable */
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id, slice, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    /* Change idle_all to idle_2nd only */
    rtn |= ten_pp10g_xgadj_rx_ratecntrl_idle_all(module_id, slice, 0);
    rtn |= ten_pp10g_xgadj_rx_ratecntrl_idle_2nd(module_id, slice, 1);
    /* Change threshold to rate adjust mappings so they are the same in both directions        */
    /* Previously was set to look at threshold one from the line side and threshold two        */
    /* from the client side - now set to threshold one for map_seq_os_2nd from both directions */
    rtn |= ten_pp10g_xgadj_rx_rate_control1 (module_id, slice, 0, 1);
    /* Bugzilla 37543 End */
  }

   else if (((client == TEN_TRAFFIC_TYPE_8GFC_RA) && (mapper == TEN_TRAFFIC_TYPE_8GFC_RA)) ||
            ((client == TEN_TRAFFIC_TYPE_4GFC_RA) && (mapper == TEN_TRAFFIC_TYPE_4GFC_RA)) ||
            ((client == TEN_TRAFFIC_TYPE_2GFC_RA) && (mapper == TEN_TRAFFIC_TYPE_2GFC_RA)) ||
            ((client == TEN_TRAFFIC_TYPE_1GFC_RA) && (mapper == TEN_TRAFFIC_TYPE_1GFC_RA))) {
    /* Client side for Transponder */
    rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_8FC, TEN_PP10G_TX_8FC);
  }
  
   else if  ((client == TEN_TRAFFIC_TYPE_8GFC_RA) ||
             (client == TEN_TRAFFIC_TYPE_4GFC_RA) ||
             (client == TEN_TRAFFIC_TYPE_2GFC_RA) ||
             (client == TEN_TRAFFIC_TYPE_1GFC_RA)) {
    /* Line side for Transponder and Muxponder */
    rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_8FC_RA, TEN_PP10G_TX_8FC);
    rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id, slice, 8);
    /* Bug 30530 Start: RA should have below_disable=0 */
    rtn |= ten_pp10g_xgadj_below_disable(module_id, slice, 0);
    /* Bug 30530 End */
  }
  
  else if ((client == TEN_TRAFFIC_TYPE_8GFC_ENH) ||
           (client == TEN_TRAFFIC_TYPE_4GFC_ENH) ||
           (client == TEN_TRAFFIC_TYPE_2GFC_ENH) ||
           (client == TEN_TRAFFIC_TYPE_1GFC_ENH)) {
    /* Line and Client side for Transponder and Muxponder */
    rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_8FC, TEN_PP10G_TX_DISABLE);
    /* Bugzilla 37829 Start: Turn off Rate Adjust */
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id, slice, 0, 0, 0, 0, 0, 0);
    /* Bugzilla 37829 End */
  }
  
  else if ((client == TEN_TRAFFIC_TYPE_8GFC) ||
           (client == TEN_TRAFFIC_TYPE_4GFC) ||
           (client == TEN_TRAFFIC_TYPE_2GFC) ||
           (client == TEN_TRAFFIC_TYPE_1GFC)) {
    /* Line and Client side for Transponder and Muxponder */
    rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_8FC, TEN_PP10G_TX_DISABLE);
    /* Bugzilla 37829 Start: Turn off Rate Adjust */
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id, slice, 0, 0, 0, 0, 0, 0);
    /* Bugzilla 37829 End */
  }
  
  else if (client == TEN_TRAFFIC_TYPE_10G_IB) {
    /* Client and line side for Transponder */
    /* This is a T41-only section so ten_hl_pp10g_config was not modified to add this client type. */
    /* Enable global PP10G clock */
    rtn |= ten_mpif_global_clock_disable_pp10g(dev_id, temp_mod_num, slice, CS_RX, CS_ENABLE); /* Bug 38849 */

    /* rx_en_bypass, rx_en_fc, rx_en_xgpcs, rx_en_xcode, rx_en_mac, rx_en_rs, rx_en_gfp, rx_en_egpcs, rx_en_basex */
    rtn |= ten_pp10g_clken_line_rx(module_id, slice, 0, 0, 1, 0, 0, 1, 0, 0, 0);
    rtn |= ten_pp10g_clken_sys_rx(module_id, slice, 1);

    /* Bug #39491: Bus errors during dynamic reconfig testing with 10GIB */
    /* rx_fen_fc, rx_fen_bypass, rx_fen_mac, rx_fen_xcode, rx_fen_egpcs, rx_fen_basex, rx_fen_gfp, rx_fen_xgpcs */
    rtn |= ten_pp10g_funcen_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 1);
    
    /* Bugzilla 39393 Start - Make sure MON10B & BER10B turned on for T41 only */
    /* Deassert global PP10G reset */
    rtn |= ten_mpif_global_reset_pp10g(dev_id, temp_mod_num, slice, CS_RX, CS_RESET_DEASSERT); /* Bug 38849 */
    /* Toggle PP10G System reset */
    rtn |= ten_pp10g_misc_reset(module_id, slice, CS_RESET_TOGGLE);
    if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
      /* Local clock enables and function enables */
      rtn |= ten_pp10g_mon10b_ber10b_en_t41(module_id, slice, CS_ENABLE);
      /* Deassert local MON10B and BER10B resets */
      rtn |= ten_pp10g_mon10b_reset_t41(module_id, slice, CS_RESET_DEASSERT);
      rtn |= ten_pp10g_ber10b_reset_t41(module_id, slice, CS_RESET_DEASSERT);
    }
    /* Bugzilla 39393 End */
  }
  
  else if (client == TEN_TRAFFIC_TYPE_FDR10_IB) { /* Bugzilla 39242 */
    /* Client and line side for Transponder */
    /* This is a T41-only section so ten_hl_pp10g_config was not modified to add this client type. */
    /* Enable global PP10G clock */
    rtn |= ten_mpif_global_clock_disable_pp10g(dev_id, temp_mod_num, slice, CS_RX, CS_ENABLE);

    /* rx_en_bypass, rx_en_fc, rx_en_xgpcs, rx_en_xcode, rx_en_mac, rx_en_rs, rx_en_gfp, rx_en_egpcs, rx_en_basex */
    rtn |= ten_pp10g_clken_line_rx(module_id, slice, 0, 0, 1, 0, 0, 1, 0, 0, 0);
    /* rtn |= ten_pp10g_clken_sys_rx(module_id, slice, 1); */
    /* rx_fen_fc, rx_fen_bypass, rx_fen_mac, rx_fen_xcode, rx_fen_egpcs, rx_fen_basex, rx_fen_gfp, rx_fen_xgpcs */
    rtn |= ten_pp10g_funcen_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 1);
   
    /* Deassert global PP10G reset */
    rtn |= ten_mpif_global_reset_pp10g(dev_id, temp_mod_num, slice, CS_RX, CS_RESET_DEASSERT);
    /* Toggle PP10G System reset */
    rtn |= ten_pp10g_misc_reset(module_id, slice, CS_RESET_TOGGLE);
  }

  else if (client == TEN_TRAFFIC_TYPE_2GISC) {
    /* Line and Client side for Transponder and Muxponder */
    rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_8FC, TEN_PP10G_TX_DISABLE);
    /* Bugzilla 37829 Start: Turn off Rate Adjust */
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id, slice, 0, 0, 0, 0, 0, 0);
    /* Bugzilla 37829 End */

    /* Overwrite 8GFC PP10G config, turn off everything but egpcs which will indicate 8b/10b sync */
    /* rx_en_bypass, rx_en_fc, rx_en_xgpcs, rx_en_xcode, rx_en_mac, rx_en_rs, rx_en_gfp, rx_en_egpcs, rx_en_basex */
    rtn |= ten_pp10g_clken_line_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
    /* Bugzilla #36090: fix bus errors */
    /* rx_fen_fc, rx_fen_bypass, rx_fen_mac, rx_fen_xcode, rx_fen_egpcs, rx_fen_basex, rx_fen_gfp, rx_fen_xgpcs */
    rtn |= ten_pp10g_funcen_rx(module_id, slice, 0, 0, 0, 0, 1, 0, 0, 0);
  }
  
 
  else if (client == TEN_TRAFFIC_TYPE_CPRI_4) { /* Bugzilla 39690 */
    /* Line and Client side for Transponder and Muxponder */
    rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_8FC, TEN_PP10G_TX_DISABLE);
    /* Bugzilla 37829 Start: Turn off Rate Adjust */
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id, slice, 0, 0, 0, 0, 0, 0);
    /* Bugzilla 37829 End */

    /* rx_en_bypass, rx_en_fc, rx_en_xgpcs, rx_en_xcode, rx_en_mac, rx_en_rs, rx_en_gfp, rx_en_egpcs, rx_en_basex */
    rtn |= ten_pp10g_clken_line_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    /* rx_fen_fc, rx_fen_bypass, rx_fen_mac, rx_fen_xcode, rx_fen_egpcs, rx_fen_basex, rx_fen_gfp, rx_fen_xgpcs */
    rtn |= ten_pp10g_funcen_rx(module_id, slice, 0, 0, 0, 0, 0, 0, 0, 0);
    /* Local clock enables and function enables */
    rtn |= ten_pp10g_mon10b_ber10b_en_t41(module_id, slice, CS_ENABLE);
    /* Toggle PP10G System reset */
    rtn |= ten_pp10g_misc_reset(module_id, slice, CS_RESET_TOGGLE);
    /* Deassert local MON10B and BER10B resets */
    rtn |= ten_pp10g_mon10b_reset_t41(module_id, slice, CS_RESET_DEASSERT);
    rtn |= ten_pp10g_ber10b_reset_t41(module_id, slice, CS_RESET_DEASSERT);
  }

  else {
    CS_PRINT("%s() client %s and mapper %s combination not supported!\n", func, ten_hl_config_traffic_types_strings[client], ten_hl_config_traffic_types_strings[mapper]);
    rtn = CS_ERROR;
  }  

  /* Bugzilla #35713 Start: default software setting for T41 EGPCS scrambler/de-scrambler */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    if ( ((client == TEN_TRAFFIC_TYPE_8GFC_RA)  && (mapper == TEN_TRAFFIC_TYPE_8GFC_RA)) || 
         ((client == TEN_TRAFFIC_TYPE_8GFC_ENH) && (mapper == TEN_TRAFFIC_TYPE_8GFC_ENH)) ||
         ((client == TEN_TRAFFIC_TYPE_8GFC)     && (mapper == TEN_TRAFFIC_TYPE_8GFC)) ) {
      rtn |= ten_pp10g_egpcs_rx_dscr_en(module_id, slice, 1);
    }
    if ((client == TEN_TRAFFIC_TYPE_8GFC_RA)  && (mapper == TEN_TRAFFIC_TYPE_8GFC_RA)) {
      rtn |= ten_pp10g_egpcs_tx_scr_en(module_id, slice, 1);
    }
    /* Bugzilla #35713 End */

    /* Bugzilla #36847 Start */
    if ((client != TEN_TRAFFIC_TYPE_10G_IB) && 
        (client != TEN_TRAFFIC_TYPE_1GE) && /* Bugzilla 38871 */
        (client != TEN_TRAFFIC_TYPE_CPRI_4) && /* Bugzilla 39690 */
         ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_MON10B)) {
      /* Bug #39491: Bus errors during dynamic reconfig testing with 10GIB */
      /* Local clock enables and function enables */
      rtn |= ten_pp10g_mon10b_ber10b_en_t41(module_id, slice, CS_DISABLE);
    }
    /* Bugzilla #36847 End */
  } /* Bugzilla 39393 - Moved closing brace to include MON10B & BER10B resets in T41 check */

  if (rtn != CS_OK) {
    CS_PRINT("%s()  FAILED!\n", func);
  }
              
  return (rtn);
}
/* Bugzilla 24360 End */

  
