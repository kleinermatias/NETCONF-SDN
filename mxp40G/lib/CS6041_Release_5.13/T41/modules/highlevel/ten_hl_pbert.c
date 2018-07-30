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
 * ten_hl_pbert.c
 *
 * API's for PBERT high level configuration.
 *
 * $Id: ten_hl_pbert.c,v 1.3 2013/02/22 20:44:11 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

const cs_uint16 ten_xcon_pbert_table[TEN_XCON_PBERT_MAX_PARM][TEN_XCON_PBERT_MAX_MODE] = {
/*                                              ETH_0               ETH_2               GFP_S               GFP_T               GFP_T_OS            FC                  ETH_3               ETH_0_PRBS          FC_PRBS             CUSTOM_MODE1        CUSTOM_MODE2        */
/*                                              =================== =================== =================== =================== =================== =================== =================== =================== =================== =================== =================== */
/*             CONFIG_SF_MODE */  {                  0,                  0,                  1,                  1,                  1,                  0,                  0,                  0,                  0,             0x0000,             0x0000 },
/*            CONFIG_PKT_MODE */  {                  1,                  1,                  1,                  1,                  1,                  1,                  1,                  1,                  1,             0x0000,             0x0000 },
/*            CONFIG_GFP_MODE */  {                  0,                  0,                  1,                  1,                  1,                  0,                  0,                  0,                  0,             0x0000,             0x0000 },
/*               MODE_PROFILE */  {             0x0000,             0x0002,             0x0005,             0x0006,             0x0006,             0x0007,             0x0003,             0x0000,             0x0007,             0x0000,             0x0000 },
/*               MODE_TRAFFIC */  {                  0,                  0,                  0,                  0,                  1,                  0,                  0,                  0,                  0,             0x0000,             0x0000 },
/*            PROTOCOL_ETH_DA */  {             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000 },
/*            PROTOCOL_FC_EOF */  {             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000 },
/*            PROTOCOL_FC_SOF */  {             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000 },
/*            PCTRL_FR_SEQNUM */  {                  1,                  1,                  1,                  1,                  0,                  1,                  1,                  1,                  1,             0x0000,             0x0000 },
/*              PCTRL_FR_TYPE */  {                  0,                  0,                  0,                  0,                  0,                  0,                  0,                  1,                  1,             0x0000,             0x0000 },
/*                  ULEN_MODE */  {                  0,                  0,                  0,                  0,                  0,                  0,                  0,                  0,                  0,             0x0000,             0x0000 },
/*               ULEN_RNDMASK */  {             0x07FF,             0x07FF,             0x07FF,             0x07FF,             0x07FF,             0x07FF,             0x07FF,             0x07FF,             0x07FF,             0x0000,             0x0000 },
/*                    ULENMAX */  {               1518,               1518,               1518,               1518,                  8,                 68,                 64,                 67,                 68,             0x0000,             0x0000 },
/*                    ULENMIN */  {                 64,                 64,                 64,                 64,                  4,                 64,                 64,                 64,                 64,             0x0000,             0x0000 },
/*                      UCTRL */  {               1000,               1000,               1000,               1000,                 10,                 10,                 10,                 10,                 10,             0x0000,             0x0000 },
/*                    IFG_CNT */  {                 10,                 10,                 10,                 10,                  2,                  2,                  3,                 10,                  2,             0x0000,             0x0000 },
/*               FPAT01_FPAT0 */  {             0x0000,             0x0000,             0x0000,             0x0000,             0x009C,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000 },
/*               FPAT01_FPAT1 */  {             0x0011,             0x0011,             0x0011,             0x0011,             0x00A5,             0x0011,             0x0011,             0x0011,             0x0011,             0x0000,             0x0000 },
/*               FPAT23_FPAT2 */  {             0x0022,             0x0022,             0x0022,             0x0022,             0x005A,             0x0022,             0x0022,             0x0022,             0x0022,             0x0000,             0x0000 },
/*               FPAT23_FPAT3 */  {             0x0033,             0x0033,             0x0033,             0x0033,             0x0001,             0x0033,             0x0033,             0x0033,             0x0033,             0x0000,             0x0000 },
/*               FPAT45_FPAT4 */  {             0x0008,             0x0008,             0x0008,             0x0008,             0x0000,             0x0000,             0x0008,             0x0008,             0x0000,             0x0000,             0x0000 },
/*               FPAT45_FPAT5 */  {             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000 },
/*               FPAT67_FPAT6 */  {             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000 },
/*               FPAT67_FPAT7 */  {             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000,             0x0000 },
/*           PCTRL_OS0_COL1_C */  {             0x0001,             0x0001,             0x0001,             0x0001,             0x0001,             0x0000,             0x0000,             0x0001,             0x0000,             0x0000,             0x0000 } };

const cs_char8 *ten_xcon_pbert_debug_str[TEN_XCON_PBERT_MAX_MODE] = {
  "TEN_XCON_PBERT_ETH_0",
  "TEN_XCON_PBERT_ETH_2",
  "TEN_XCON_PBERT_GFP_S",
  "TEN_XCON_PBERT_GFP_T",
  "TEN_XCON_PBERT_GFP_T_OS",
  "TEN_XCON_PBERT_FC",
  "TEN_XCON_PBERT_ETH_3",
  "TEN_XCON_PBERT_ETH_0_PRBS",
  "TEN_XCON_PBERT_FC_PRBS",
  "TEN_XCON_PBERT_CUSTOM_MODE1",
  "TEN_XCON_PBERT_CUSTOM_MODE2" 
};

/****************************************************************/
/* $rtn_hdr_start  PBERT INITIALIZATION                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pbert_init(cs_uint16 dev_id,
                            ten_xcon_es_num_t es_num,
                            ten_xcon_ifg_symbol_t symbol,
                            cs_uint8 column_idx,
                            ten_xcon_encoding_t encoding,
                            cs_uint8 mode)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Inter Frame Gap Symbol                        */
/*              o Column Index                                  */
/*              o Encoding Type                                 */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure PBERT for traffic.                                 */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [symbol] paramater selects the ifg symbol specified as:  */
/*   0 = XCON_IFG_SYMBOL_IDLE                                   */
/*       Uses XGMII idle as the ifg symbol                      */
/*   1 = XCON_IFG_SYMBOL_ARBFF                                  */
/*       Uses XGMII ARBff as th ifg symbol                      */
/*                                                              */
/* The [column_idx] parameter specifies the column index as:    */
/*   1 = Column 1                                               */
/*   2 = Column 2                                               */
/*                                                              */
/* The [encoding] parameter specifies the encoding format for   */
/* column 1 of the selected profile                             */
/*   0 = XCON_XGMII_ENC                                         */
/*   1 = XCON_64B_66B_ENC                                       */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_XCON_PBERT_ETH_0                          = 0,         */
/*   TEN_XCON_PBERT_ETH_2                          = 1,         */
/*   TEN_XCON_PBERT_GFP_S                          = 2,         */
/*   TEN_XCON_PBERT_GFP_T                          = 3,         */
/*   TEN_XCON_PBERT_GFP_T_OS                       = 4,         */
/*   TEN_XCON_PBERT_FC                             = 5,         */
/*   TEN_XCON_PBERT_ETH_3                          = 6,         */
/*   TEN_XCON_PBERT_ETH_0_PRBS                     = 7,         */
/*   TEN_XCON_PBERT_FC_PRBS                        = 8,         */
/*   TEN_XCON_PBERT_CUSTOM_MODE1                   = 9,         */
/*   TEN_XCON_PBERT_CUSTOM_MODE2                   = 10.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;

  CS_PRINT("ten_hl_pbert_init\n");
  
  if (mode >= TEN_XCON_PBERT_MAX_MODE) {
     CS_PRINT("Invalid Mode!\n");
     ret_val = CS_ERROR;
     goto RTN_EXIT;
  };

  CS_PRINT("mode = (%d) %s\n", mode, ten_xcon_pbert_debug_str[mode]);

  CS_PRINT("CONFIG_SF_MODE                 = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_CONFIG_SF_MODE][mode]);
  CS_PRINT("CONFIG_PKT_MODE                = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_CONFIG_PKT_MODE][mode]);
  CS_PRINT("CONFIG_GFP_MODE                = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_CONFIG_GFP_MODE][mode]);
  CS_PRINT("MODE_PROFILE                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_MODE_PROFILE][mode]);
  CS_PRINT("MODE_TRAFFIC                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_MODE_TRAFFIC][mode]);
  CS_PRINT("PROTOCOL_ETH_DA                = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_PROTOCOL_ETH_DA][mode]);
  CS_PRINT("PROTOCOL_FC_EOF                = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_PROTOCOL_FC_EOF][mode]);
  CS_PRINT("PROTOCOL_FC_SOF                = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_PROTOCOL_FC_SOF][mode]);
  CS_PRINT("PCTRL_FR_SEQNUM                = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_PCTRL_FR_SEQNUM][mode]);
  CS_PRINT("PCTRL_FR_TYPE                  = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_PCTRL_FR_TYPE][mode]);
  CS_PRINT("ULEN_MODE                      = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_ULEN_MODE][mode]);
  CS_PRINT("ULEN_RNDMASK                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_ULEN_RNDMASK][mode]);
  CS_PRINT("ULENMAX                        = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_ULENMAX][mode]);
  CS_PRINT("ULENMIN                        = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_ULENMIN][mode]);
  CS_PRINT("UCTRL                          = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_UCTRL][mode]);
  CS_PRINT("IFG_CNT                        = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_IFG_CNT][mode]);
  CS_PRINT("FPAT01_FPAT0                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT01_FPAT0][mode]);
  CS_PRINT("FPAT01_FPAT1                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT01_FPAT1][mode]);
  CS_PRINT("FPAT23_FPAT2                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT23_FPAT2][mode]);
  CS_PRINT("FPAT23_FPAT3                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT23_FPAT3][mode]);
  CS_PRINT("FPAT45_FPAT4                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT45_FPAT4][mode]);
  CS_PRINT("FPAT45_FPAT5                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT45_FPAT5][mode]);
  CS_PRINT("FPAT67_FPAT6                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT67_FPAT6][mode]);
  CS_PRINT("FPAT67_FPAT7                   = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT67_FPAT7][mode]);
  CS_PRINT("PCTRL_OS0_COL1_C               = 0x%04X\n", ten_xcon_pbert_table[TEN_XCON_PBERT_PCTRL_OS0_COL1_C][mode]);

  CS_PRINT("Provision XCON PBERT...\n");

  /* Assert block-level resets */
  ten_xcon_pbert_rx_reset(dev_id, TEN_INSTANCE_ALL, CS_RESET_ASSERT);
  ten_xcon_pbert_tx_reset(dev_id, TEN_INSTANCE_ALL, CS_RESET_ASSERT);
  
  ten_xcon_config(dev_id, es_num,
                  ten_xcon_pbert_table[TEN_XCON_PBERT_CONFIG_GFP_MODE][mode],
                  ten_xcon_pbert_table[TEN_XCON_PBERT_CONFIG_SF_MODE][mode],
                  ten_xcon_pbert_table[TEN_XCON_PBERT_CONFIG_PKT_MODE][mode]);
                        
  /* This function configures both RX and TX sides */
  ten_xcon_set_pbert_mode(dev_id, es_num,
                          ten_xcon_pbert_table[TEN_XCON_PBERT_MODE_TRAFFIC][mode],
                          ten_xcon_pbert_table[TEN_XCON_PBERT_MODE_PROFILE][mode]);

  /* This function configures both RX and TX sides */
  ten_xcon_set_pbert_protocol(dev_id, es_num,
                              ten_xcon_pbert_table[TEN_XCON_PBERT_PROTOCOL_FC_SOF][mode],
                              ten_xcon_pbert_table[TEN_XCON_PBERT_PROTOCOL_FC_EOF][mode], 
                              ten_xcon_pbert_table[TEN_XCON_PBERT_PROTOCOL_ETH_DA][mode]);
                              
  /* This function configures both RX and TX sides */
  ten_xcon_control_pbert_frame_payload(dev_id, es_num,
                                       ten_xcon_pbert_table[TEN_XCON_PBERT_PCTRL_FR_TYPE][mode],
                                       ten_xcon_pbert_table[TEN_XCON_PBERT_PCTRL_FR_SEQNUM][mode]);
                                       
  ten_xcon_control_pbert_unit_len(dev_id, es_num,
                                  ten_xcon_pbert_table[TEN_XCON_PBERT_ULEN_MODE][mode], 
                                  ten_xcon_pbert_table[TEN_XCON_PBERT_ULEN_RNDMASK][mode],
                                  ten_xcon_pbert_table[TEN_XCON_PBERT_ULENMIN][mode],
                                  ten_xcon_pbert_table[TEN_XCON_PBERT_ULENMAX][mode]);
                                  
  ten_xcon_pbert_control_traffic(dev_id, es_num,
                                 ten_xcon_pbert_table[TEN_XCON_PBERT_UCTRL][mode]);
                                 
  ten_xcon_pbert_control_ifg(dev_id, es_num, symbol,
                             ten_xcon_pbert_table[TEN_XCON_PBERT_IFG_CNT][mode]);
                             
  /* These functions configure both RX and TX sides */
  ten_xcon_pbert_select_fixed_pattern(dev_id, es_num, XCON_FIXED_PATTERN_01,
                                      (cs_uint8)(ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT01_FPAT0][mode] & 0x00FF),
                                      (cs_uint8)(ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT01_FPAT1][mode] & 0x00FF));
  ten_xcon_pbert_select_fixed_pattern(dev_id, es_num, XCON_FIXED_PATTERN_01,
                                      (cs_uint8)(ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT23_FPAT2][mode] & 0x00FF),
                                      (cs_uint8)(ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT23_FPAT3][mode] & 0x00FF));
  ten_xcon_pbert_select_fixed_pattern(dev_id, es_num, XCON_FIXED_PATTERN_01,
                                      (cs_uint8)(ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT45_FPAT4][mode] & 0x00FF),
                                      (cs_uint8)(ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT45_FPAT5][mode] & 0x00FF));
  ten_xcon_pbert_select_fixed_pattern(dev_id, es_num, XCON_FIXED_PATTERN_01,
                                      (cs_uint8)(ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT67_FPAT6][mode] & 0x00FF),
                                      (cs_uint8)(ten_xcon_pbert_table[TEN_XCON_PBERT_FPAT67_FPAT7][mode] & 0x00FF));

  CS_PRINT("Provision XCON PBERT.\n");

RTN_EXIT:
  return(ret_val);
}

