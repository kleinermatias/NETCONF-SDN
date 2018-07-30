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
 * ten_hl_xcon.c
 *
 * API's for XCON high level configuration.
 *
 * $Id: ten_hl_xcon.c,v 1.33 2014/04/02 19:03:14 pptawade Exp $
 *
 */
 
#include "tenabo40.h"

const cs_uint16 ten_xcon_table[TEN_XCON_MAX_PARM][TEN_XCON_MAX_MODE] = {
/*                                                       DISABLE                    10GE_GFP_OTU3              OTU3_GFP_10GE              10GE_RA_FC_OTU3            OTU3_RA_FC_10GE            10GFC_trans_OTU3P          10GE_RA_GFP                GFP_RA_10GE                10GE_RA_OTU2e              OTU2e_RA_10GE              10GE_OC192_OTU2            OTU2_OC192_10GE            10GE_RA                    10GE_MON_OTU2              10GFC_trans_OTU2           8GFC_MON_OTU2              10GE_OTU2e_OTU3P           10GE_OTU1e_OTU3P           10GE_OC192_OTU3P           OTU3P_OC192_10GE           GRP_T_OTU3P                10GFC_OTU2fc               8GFC_OTU2                  OTU2_8GFC                  table15p4                  table16p0                  table16mix_p0              table16mix_p1              table16mix_p2              table19p0                  table19mix_p0              table19mix_p1              table19mix_p2               */
/*                                                       ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============                */
/*                     CONFIG_PKT_MODE */  {                         0,                         1,                         1,                         1,                         1,                         0,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         0,                         0,                         0,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1 },
/*                      CONFIG_SF_MODE */  {                         0,                         1,                         1,                         1,                         1,                         0,                         1,                         1,                         1,                         1,                         0,                         0,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         1,                         0,                         1,                         0,                         0,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1 },
/*                     CONFIG_GFP_MODE */  {                         0,                         0,                         1,                         0,                         0,                         0,                         0,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*          CONFIG_AUTO_RECENTER_LOWER */  {                         0,                         0,                         0,                         0,                         0,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         1,                         1,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*          CONFIG_AUTO_RECENTER_UPPER */  {                         0,                         0,                         0,                         0,                         0,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         1,                         1,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*                  CONFIG_AUTO_CENTER */  {                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         1,                         0,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*               IML_THRESH_IML_THRESH */  {                    0x0000,                     0x400,                     0x400,                       0x0,                       0x0,                     0x080,                     0x400,                     0x400,                     0x400,                     0x400,                    0x1A5E,                     0x1F4,                     0x001,                     0x400,                     0x080,                     0x400,                     0x001,                     0x001,                     0x040,                     0x080,                     0x400,                     0x001,                     0x001,                     0x040,                     0x080,                     0x001,                     0x001,                     0x001,                     0x001,                     0x001,                     0x001,                     0x001,                     0x001 },
/*       CIRCUIT_THRESHOLD_UPPER_LEVEL */  {                    0x0000,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                     0x100,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                     0x100,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x0100,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE,                    0x1FFE },
/*       CIRCUIT_THRESHOLD_LOWER_LEVEL */  {                    0x0000,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                     0x010,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                     0x010,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0010,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002,                    0x0002 },
/*        ES_0_THRESHOLD_LEVEL_0_LEVEL */  {                       0x0,                     0x800,                     0x800,                     0x980,                     0x960,                     0x800,                     0x800,                     0x800,                     0x100,                     0x100,                     0x9C4,                     0x1F4,                     0x020,                    0x0800,                     0x800,                    0x0800,                     0x080,                     0x080,                     0x040,                     0x800,                     0x020,                     0x080,                     0x800,                     0x040,                     0x800,                     0x800,                     0x020,                     0x020,                     0x020,                     0x020,                     0x020,                     0x020,                     0x020 },
/*        ES_0_THRESHOLD_LEVEL_5_LEVEL */  {                       0x0,                     0x300,                     0x300,                     0x960,                     0x300,                     0x300,                     0x300,                     0x300,                     0x000,                     0x040,                     0x300,                    0x0C00,                     0x010,                    0x0300,                     0x300,                    0x0300,                     0x040,                     0x040,                     0x000,                     0x080,                     0x010,                     0x000,                     0x210,                     0x000,                     0x300,                     0x300,                     0x010,                     0x010,                     0x010,                     0x010,                     0x010,                     0x010,                     0x010 },
/*            ES_0_PAUSE_LEVEL_0_LEVEL */  {                    0x0000,                    0x0C00,                    0x0C00,                    0x0C00,                    0x1A1E,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x1A5E,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                     0xCB2,                     0xCB2,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00,                    0x0C00 },
/*        ES_0_THRESHOLD_LEVEL_3_LEVEL */  {                    0x0000,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020,                    0x0020 },
/*        ES_0_THRESHOLD_LEVEL_4_LEVEL */  {                    0x0000,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40,                    0x1F40 },
/*        ES_0_THRESHOLD_LEVEL_2_LEVEL */  {                    0x0000,                    0x0a00,                    0x0a00,                    0x1000,                    0x1000,                    0x1000,                    0x0a00,                    0x0a00,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000,                    0x1000 } };

const cs_char8 *ten_xcon_debug_str[TEN_XCON_MAX_MODE] = {
  "TEN_XCON_DISABLE",
  "TEN_XCON_10GE_GFP_OTU3",
  "TEN_XCON_OTU3_GFP_10GE",
  "TEN_XCON_10GE_RA_FC_OTU3",
  "TEN_XCON_OTU3_RA_FC_10GE",
  "TEN_XCON_10GFC_TRANS_OTU3P",
  "TEN_XCON_10GE_RA_GFP",
  "TEN_XCON_GFP_RA_10GE",
  "TEN_XCON_10GE_RA_OTU2E",
  "TEN_XCON_OTU2E_RA_10GE",
  "TEN_XCON_10GE_OC192_OTU2",
  "TEN_XCON_OTU2_OC192_10GE",
  "TEN_XCON_10GE_RA",
  "TEN_XCON_10GE_MON_OTU2",
  "TEN_XCON_10GFC_TRANS_OTU2",
  "TEN_XCON_8GFC_MON_OTU2",
  "TEN_XCON_10GE_OTU2E_OTU3P",
  "TEN_XCON_10GE_OTU1E_OTU3P",
  "TEN_XCON_10GE_OC192_OTU3P",
  "TEN_XCON_OTU3P_OC192_10GE",
  "TEN_XCON_GRP_T_OTU3P",
  "TEN_XCON_10GFC_OTU2FC",
  "TEN_XCON_8GFC_OTU2",
  "TEN_XCON_OTU2_8GFC",
  "TEN_XCON_TABLE15P4",
  "TEN_XCON_TABLE16P0",
  "TEN_XCON_TABLE16MIX_P0",
  "TEN_XCON_TABLE16MIX_P1",
  "TEN_XCON_TABLE16MIX_P2",
  "TEN_XCON_TABLE19P0",
  "TEN_XCON_TABLE19MIX_P0",
  "TEN_XCON_TABLE19MIX_P1",
  "TEN_XCON_TABLE19MIX_P2" 
};

/****************************************************************/
/* Prototypes for non-api functions                             */
/****************************************************************/
/* Bugzilla 27270 release 5.5                                   */
extern cs_status ten_xcon_es_amplitude_recenter_with_fpa_10g_cb(cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num_ovl,
                                           cs_uint16 static_depth,
                                           cs_uint16 circuit_th_lower,
                                           cs_uint16 circuit_th_upper,
                                           cs_uint16 cb_rw);
extern cs_status ten_xcon_es_amplitude_recenter_with_fpa_40g_cb(cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num_ovl,
                                           cs_uint16 static_depth,
                                           cs_uint16 circuit_th_lower,
                                           cs_uint16 circuit_th_upper,
                                           cs_uint16 cb_rw);
extern cs_status ten_xcon_es_amplitude_recenter_10g_cb( cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num_ovl,
                                           cs_uint16 margin_lower,
                                           cs_uint16 margin_upper,
                                           cs_uint16 correct_lower,
                                           cs_uint16 correct_upper,
                                           cs_uint8  duration,
                                           cs_uint32 sysclk_freq,
                                           cs_uint16 cb_rw);
extern cs_status ten_xcon_es_amplitude_recenter_40g_cb(cs_uint16 dev_id,
                                           cs_uint8  module_num_ov,
                                           cs_uint16 margin_lower,
                                           cs_uint16 margin_upper,
                                           cs_uint16 correct_lower,
                                           cs_uint16 correct_upper,
                                           cs_uint8  duration,
                                           cs_uint32 sysclk_freq,
                                           cs_uint16 cb_rw);

/****************************************************************/
/* Functions                                                    */
/****************************************************************/

/****************************************************************/
/* $rtn_hdr_start  XCON CONFIG                                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_xcon_config(cs_uint16 dev_id, 
                          cs_uint8 es,
                          cs_uint8 channel,
                          cs_uint16 client)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store                                 */
/*              o Channel                                       */
/*              o Client                                        */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures a bidirectional unicast cross-connect path.       */
/*                                                              */
/* The [es] parameter is specified as:                          */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*                                                              */
/* The [channel] parameter is specified as:                     */
/*   0 = XCON_MODULE_A_CHANNEL_1                                */
/*   1 = XCON_MODULE_A_CHANNEL_2                                */
/*   2 = XCON_MODULE_A_CHANNEL_3                                */
/*   3 = XCON_MODULE_A_CHANNEL_4                                */
/*   4 = XCON_MODULE_B_CHANNEL_1                                */
/*   5 = XCON_MODULE_B_CHANNEL_2                                */
/*   6 = XCON_MODULE_B_CHANNEL_3                                */
/*   7 = XCON_MODULE_B_CHANNEL_4                                */
/*                                                              */
/* The [client] parameter is specified as:                      */
/*   TEN_TRAFFIC_TYPE_OTU2 = 5,                                 */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6,                                */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7,                                */
/*   TEN_TRAFFIC_TYPE_OC192 = 8,                                */
/*   TEN_TRAFFIC_TYPE_10GE_6_2 = 10,                            */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11,                            */
/*   TEN_TRAFFIC_TYPE_10GE_7_3 = 12,                            */
/*   TEN_TRAFFIC_TYPE_10GFC = 13,                               */
/*   TEN_TRAFFIC_TYPE_10GE = 20,                                */
/*   TEN_TRAFFIC_TYPE_10GE_6_1 = 26,                            */
/*   TEN_TRAFFIC_TYPE_10GE_TC = 33.                             */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF = 56.                           */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_RA = 58.                         */
/*   TEN_TRAFFIC_TYPE_1GE = 63.                                 */
/*   TEN_TRAFFIC_TYPE_CBR_10G = 67                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 mod_line;
  cs_uint16 slice_line;
  cs_uint16 mod_client;
  cs_uint16 slice_client;
  cs_char8 *func = "ten_hl_xcon_config";  

  CS_PRINT("%s()  dev_id=%d, es=%s, channel=%s, client=%s\n", 
           func, dev_id, ten_xcon_es_mod_slice_strings[es], ten_xcon_es_mod_slice_strings[channel], 
           ten_hl_config_traffic_types_strings[client]);


  mod_line  = (dev_id << 8) + (es >= 4 ? 1 : 0);
  slice_line = es & 3;
  mod_client = (dev_id << 8) + (channel >= 4 ? 1 : 0);
  slice_client = channel & 3;
  
  /* Bugzilla #22621, these can't be reset per slice,    */
  /* so set back defaults first, so that only needed     */
  /* changes are made to these registers and that        */
  /* previously-run configs do not retain old settings.  */
  rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_0, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_0_dft);
  rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_1, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_1_dft);
  rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_2, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_2_dft );
  rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_3, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_3_dft);
  rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_4, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_4_dft);
  rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_5, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_5_dft);

  rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_0, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_0_dft);
  rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_1, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_1_dft);
  rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_2, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_2_dft );
  rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_3, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_3_dft);
  rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_4, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_4_dft);
  rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_5, TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_5_dft);

  rtn |= ten_xcon_set_circuit_thresholds(dev_id, es, XCON_ES_IML_THRESH, TEN_XCON_ES_IML_THRESH_dft);
  rtn |= ten_xcon_set_circuit_thresholds(dev_id, es, XCON_ES_CIRCUIT_THRESHOLD_LOWER, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft);
  rtn |= ten_xcon_set_circuit_thresholds(dev_id, es, XCON_ES_CIRCUIT_THRESHOLD_UPPER, TEN_XCON_ES_CIRCUIT_THRESHOLD_UPPER_dft);
   
  rtn |= ten_xcon_set_circuit_thresholds(dev_id, channel, XCON_ES_IML_THRESH, TEN_XCON_ES_IML_THRESH_dft);
  rtn |= ten_xcon_set_circuit_thresholds(dev_id, channel, XCON_ES_CIRCUIT_THRESHOLD_LOWER, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft);
  rtn |= ten_xcon_set_circuit_thresholds(dev_id, channel, XCON_ES_CIRCUIT_THRESHOLD_UPPER, TEN_XCON_ES_CIRCUIT_THRESHOLD_UPPER_dft);
   
  rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_PKT_CENTERING_ALL, CS_ENABLE);
  rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_PKT_CENTERING_ALL, CS_ENABLE);
  
  if (client == TEN_TRAFFIC_TYPE_NONE) {
    /* Bugzilla #22621, these can't be reset per slice,    */
    /* provide a valid path to cause the default resets    */
    /* for those configs that aren't setting XCON through  */
    /* this API.                                           */
    /* Eventually, all configs should go through this      */
    /* common API.                                         */
  }
  else if ((client == TEN_TRAFFIC_TYPE_OC192) || (client == TEN_TRAFFIC_TYPE_OTU1F) ||
      (client == TEN_TRAFFIC_TYPE_OTU2) || (client == TEN_TRAFFIC_TYPE_OTU2E) || 
       /* Bugzilla 20308 Start */
      (client == TEN_TRAFFIC_TYPE_OTU1E)) {
       /* Bugzilla 20308 End */
    rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_N10G);
    rtn |= ten_xcon_config_es_mode(dev_id, es, XCON_FP, XCON_NO_GFP, XCON_MODE_CUT_THRU, XCON_MODE_CCT);
    rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_N10G);
    rtn |= ten_xcon_config_es_mode(dev_id, channel, XCON_FP, XCON_NO_GFP, XCON_MODE_CUT_THRU, XCON_MODE_CCT);
    /* These are needed to go from 10ge7_3 -> null -> oc192 for config_oc192_odtu23 */
    rtn |= ten_n10g_set_pktie(mod_line, slice_line, 0);
    rtn |= ten_n10g_set_pktie(mod_client, slice_client, 0);
  }
  else if ((client == TEN_TRAFFIC_TYPE_10GE_7_1) || (client == TEN_TRAFFIC_TYPE_10GE_7_2) || 
           (client == TEN_TRAFFIC_TYPE_10GE) ||     /* Bugzilla 20308 */
           (client == TEN_TRAFFIC_TYPE_CBR_10G)) {  /* Bugzilla 43573 */
           
    if (ten_hsif_is_xaui_active(mod_client, slice_client)) {
      ten_xcon_config_es_mode(dev_id, es, XCON_FP, XCON_NO_GFP, XCON_MODE_STORE_FWD, XCON_MODE_PKT);
      ten_xcon_select_es_packet_centering(dev_id, es, XCON_AUTO_CENTER, CS_DISABLE);
      ten_xcon_select_es_packet_centering(dev_id, es, XCON_RECENTER_LOWER, CS_DISABLE);
      ten_xcon_select_es_packet_centering(dev_id, es, XCON_RECENTER_UPPER, CS_DISABLE);
      
      ten_xcon_config_es_mode(dev_id, channel, XCON_FP, XCON_NO_GFP, XCON_MODE_STORE_FWD, XCON_MODE_PKT);
      ten_xcon_select_es_packet_centering(dev_id, channel, XCON_AUTO_CENTER, CS_DISABLE);
      ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_LOWER, CS_DISABLE);
      ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_UPPER, CS_DISABLE);

      ten_n10g_set_pktie(mod_line, slice_line, 1) ;

      ten_xcon_es_select_source(dev_id, es, channel, XCON_PP10G);
      ten_xcon_es_select_source(dev_id, channel, es, XCON_PP10G);
   
      ten_xcon_set_es_watermark_level(dev_id,es,XCON_THRESHOLD_LEVEL_5,0x01F4);
      ten_xcon_set_circuit_thresholds(dev_id,es,XCON_ES_IML_THRESH,0x01F4);
      ten_xcon_set_es_watermark_level(dev_id,es,XCON_THRESHOLD_LEVEL_4,0x1F40);
      ten_xcon_set_es_watermark_level(dev_id,es,XCON_THRESHOLD_LEVEL_3,0x0a00);
      ten_xcon_set_circuit_thresholds(dev_id,es,XCON_ES_IML_THRESH,0x1A5E);

      ten_xcon_set_es_watermark_level(dev_id,channel,XCON_THRESHOLD_LEVEL_0,0x0a00);
      ten_xcon_set_es_watermark_level(dev_id,channel,XCON_THRESHOLD_LEVEL_4,0x1F40);
      ten_xcon_set_es_watermark_level(dev_id,channel,XCON_THRESHOLD_LEVEL_3,0x0a00);
      ten_xcon_set_es_watermark_level(dev_id,channel,XCON_THRESHOLD_LEVEL_5,0x0000);
    }
    else {
      rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_N10G);
      rtn |= ten_xcon_config_es_mode(dev_id, es, XCON_FP, XCON_NO_GFP, XCON_MODE_CUT_THRU, XCON_MODE_CCT);
      rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_N10G);
      rtn |= ten_xcon_config_es_mode(dev_id, channel, XCON_FP, XCON_NO_GFP, XCON_MODE_CUT_THRU, XCON_MODE_CCT);
      /* These are needed to go from 10ge7_3 -> null -> 10ge7_1 for config_10ge7_1_odtu23 */
      rtn |= ten_n10g_set_pktie(mod_line, slice_line, 0);
      rtn |= ten_n10g_set_pktie(mod_client, slice_client, 0);
    }
  }
  else if ((client == TEN_TRAFFIC_TYPE_10GE_7_3) || (client == TEN_TRAFFIC_TYPE_10GE_6_2) ||
           (client == TEN_TRAFFIC_TYPE_10GE_GFPF) || /* Bugzilla 29991  */
           (client == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2)) { /* Bugzilla 20308 */
           
    rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_PP10G);
    rtn |= ten_xcon_config_es_mode(dev_id, es, XCON_FP, XCON_GFP, XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_PP10G);
    rtn |= ten_xcon_config_es_mode(dev_id, channel, XCON_FP, XCON_NO_GFP, XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_n10g_set_pktie(mod_line, slice_line, 0x1);
    rtn |= ten_n10g_set_pktie(mod_client, slice_client, 0x1);

    /* Bugzilla #22743, fix 10ge_gfpf_oc192_odu2 mode */
    if ((client == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) || (client == TEN_TRAFFIC_TYPE_10GE_GFPF)) { /* Bugzilla 29991  */
      rtn |= ten_xcon_select_es_pause_quanta_source(dev_id, channel, channel);
      rtn |= ten_xcon_set_es_pause_threshold_select(dev_id, channel, es);
    }
    
    /* Bugzilla #20519, change rate adjust policies   */
    if (client == TEN_TRAFFIC_TYPE_10GE_7_3) {
        rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_0, 0x0200);
    }
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_2, 0x1E00);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_3, 0x20);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_4, 0x1f40);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_3, 0x20);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_4, 0x1f40);
  }
  else if (client == TEN_TRAFFIC_TYPE_10GFC) {
    /* This is really 10GFC TC */
    rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_PP10G);
    rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_PP10G);
    rtn |= ten_xcon_config_es_mode(dev_id, es,      XCON_FP, XCON_NO_GFP, XCON_MODE_CUT_THRU, XCON_MODE_CCT);
    rtn |= ten_xcon_config_es_mode(dev_id, channel, XCON_FP, XCON_NO_GFP, XCON_MODE_CUT_THRU, XCON_MODE_CCT);

    rtn |= ten_n10g_set_pktie(mod_line,   slice_line,   0x1);
    rtn |= ten_n10g_set_pktie(mod_client, slice_client, 0x1);

    rtn |= ten_xcon_set_es_watermark_level(dev_id, es,      XCON_THRESHOLD_LEVEL_2, 0xa00);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es,      XCON_THRESHOLD_LEVEL_3, 0x20);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es,      XCON_THRESHOLD_LEVEL_4, 0x1f40);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_2, 0xa00);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_3, 0x20);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_4, 0x1f40);

    rtn |= ten_xcon_set_circuit_thresholds(dev_id, es,      XCON_ES_IML_THRESH,              0x90);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, es,      XCON_ES_CIRCUIT_THRESHOLD_LOWER, 0x10);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, es,      XCON_ES_CIRCUIT_THRESHOLD_UPPER, 0x110);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, channel, XCON_ES_IML_THRESH,              0x90);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, channel, XCON_ES_CIRCUIT_THRESHOLD_LOWER, 0x10);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, channel, XCON_ES_CIRCUIT_THRESHOLD_UPPER, 0x110);

    rtn |= ten_xcon_select_es_packet_centering(dev_id, es,      XCON_AUTO_CENTER,    CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es,      XCON_RECENTER_LOWER, CS_ENABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es,      XCON_RECENTER_UPPER, CS_ENABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_AUTO_CENTER   , CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_LOWER, CS_ENABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_UPPER, CS_ENABLE);
  }
  else if (client == TEN_TRAFFIC_TYPE_10GFC_TC_RA) {
    rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_PP10G);
    rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_PP10G);
    rtn |= ten_xcon_config_es_mode(dev_id, es,      XCON_FP, XCON_NO_GFP, XCON_MODE_CUT_THRU, XCON_MODE_PKT);
    rtn |= ten_xcon_config_es_mode(dev_id, channel, XCON_FP, XCON_NO_GFP, XCON_MODE_CUT_THRU, XCON_MODE_PKT);

    rtn |= ten_n10g_set_pktie(mod_line,   slice_line,   0x1);
    rtn |= ten_n10g_set_pktie(mod_client, slice_client, 0x1);

    rtn |= ten_xcon_select_es_packet_centering(dev_id, es,      XCON_AUTO_CENTER,    CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es,      XCON_RECENTER_LOWER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es,      XCON_RECENTER_UPPER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_AUTO_CENTER   , CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_LOWER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_UPPER, CS_DISABLE);

    /* Bugzilla 37543 Start - threshold levels changed */
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es,      XCON_THRESHOLD_LEVEL_0, 0x0100);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es,      XCON_THRESHOLD_LEVEL_5, 0x0080);

    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_0, 0x0100);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_5, 0x0080);
    /* Bugzilla 37543 End */
  }
  else if (client == TEN_TRAFFIC_TYPE_10GE_6_1) {
    /* bugzilla #22577, fixes for 10GE 6.1 */
    rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_PP10G);
    rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_PP10G);

    rtn |= ten_xcon_config_es_mode(dev_id, es, XCON_FP, XCON_NO_GFP, 
                                   XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_xcon_config_es_mode(dev_id, channel, XCON_FP, XCON_NO_GFP, 
                                   XCON_MODE_STORE_FWD, XCON_MODE_PKT);

    rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_RECENTER_LOWER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_RECENTER_UPPER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_LOWER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_UPPER, CS_DISABLE);
    
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, es, XCON_ES_IML_THRESH, 0);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, channel, XCON_ES_IML_THRESH, 0);

    /* dev_id, es_num, level, value */
    rtn |= ten_xcon_set_es_pause_frame_watermark_level(dev_id, es, 
                                                       XCON_PAUSE_LEVEL_0, 0x1A5E);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es,
                                           XCON_THRESHOLD_LEVEL_0, 0x0a00);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es, 
                                           XCON_THRESHOLD_LEVEL_4, 0x1F40);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es, 
                                           XCON_THRESHOLD_LEVEL_3, 0x0a00);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es,
                                           XCON_THRESHOLD_LEVEL_5, 0x0000);
    /* Egress */   
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel,
                                           XCON_THRESHOLD_LEVEL_5, 0x960);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel,
                                           XCON_THRESHOLD_LEVEL_0, 0x980);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel,
                                           XCON_THRESHOLD_LEVEL_4, 0x1F40);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel,
                                           XCON_THRESHOLD_LEVEL_3, 0x0a00);
    rtn |= ten_xcon_select_es_pause_quanta_source(dev_id, channel, channel);
    rtn |= ten_xcon_set_es_pause_threshold_select(dev_id, channel, es);                                      
   
    /* Configure TX to receive packets form PP10G block */
    rtn |= ten_n10g_set_pktie(mod_line, slice_line, 0x1);
    rtn |= ten_n10g_set_pktie(mod_client, slice_client, 0x1);
  }
  /* Bugzilla 22237 Start */
  else if (client == TEN_TRAFFIC_TYPE_10GE_RA) {
    rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_PP10G);
    rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_PP10G);

    rtn |= ten_xcon_config_es_mode(dev_id, es, XCON_FP, XCON_NO_GFP, 
                                   XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_xcon_config_es_mode(dev_id, channel, XCON_FP, XCON_NO_GFP, 
                                   XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    
    if (ten_hsif_is_xaui_active(mod_client, slice_client)) {
      rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_AUTO_CENTER, CS_DISABLE);
      rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_AUTO_CENTER, CS_DISABLE);
    }                          
    else { 
      rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_AUTO_CENTER, CS_DISABLE);
      rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_RECENTER_LOWER, CS_ENABLE);
      rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_RECENTER_UPPER, CS_ENABLE);
      rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_AUTO_CENTER, CS_DISABLE);
      rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_LOWER, CS_ENABLE);
      rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_UPPER, CS_ENABLE);
    }
    /* Provision tx to transmit pause frames */
    rtn |= ten_xcon_set_es_pause_frame_watermark_level(dev_id, es, XCON_PAUSE_LEVEL_0,0x1A5E);
    rtn |= ten_xcon_set_es_pause_frame_watermark_level(dev_id, es, XCON_PAUSE_LEVEL_1,0x1A5E);
    rtn |= ten_xcon_set_es_pause_threshold_select(dev_id, channel, es); 
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_0,0x0A00);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_4,0x1F40);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_3,0x0A00);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, es, XCON_THRESHOLD_LEVEL_5,0x0000);
   
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_5, 0x01F4);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, channel, XCON_ES_IML_THRESH, 0x01F4);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_4, 0x1F40);
    rtn |= ten_xcon_set_es_watermark_level(dev_id, channel, XCON_THRESHOLD_LEVEL_3, 0x0A00);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, channel, XCON_ES_IML_THRESH, 0x1A5E);
    
    /* Configure TX to receive packets from PP10G block */
    rtn |= ten_n10g_set_pktie(mod_line, slice_line, 0x1);
    rtn |= ten_n10g_set_pktie(mod_client, slice_client, 0x1);
  }
  /* Bugzilla 22237 End */
  else if (client == TEN_TRAFFIC_TYPE_10GE_TC) {
    rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_PP10G);
    rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_PP10G);

    rtn |= ten_n10g_set_pktie(mod_line,   slice_line,   0x1);
    rtn |= ten_n10g_set_pktie(mod_client, slice_client, 0x1);

    rtn |= ten_xcon_config_es_mode(dev_id, es, XCON_FP, XCON_NO_GFP, 
                                   XCON_MODE_CUT_THRU, XCON_MODE_CCT);
    rtn |= ten_xcon_config_es_mode(dev_id, channel, XCON_FP, XCON_NO_GFP, 
                                   XCON_MODE_CUT_THRU, XCON_MODE_CCT);

    rtn |= ten_xcon_set_circuit_thresholds(dev_id, es, XCON_ES_IML_THRESH, 0x90);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, es, XCON_ES_CIRCUIT_THRESHOLD_LOWER, 0x10);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, es, XCON_ES_CIRCUIT_THRESHOLD_UPPER, 0x110);

    rtn |= ten_xcon_set_circuit_thresholds(dev_id, channel, XCON_ES_IML_THRESH, 0x90);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, es, XCON_ES_CIRCUIT_THRESHOLD_LOWER, 0x10);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, es, XCON_ES_CIRCUIT_THRESHOLD_UPPER, 0x110);

    rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_RECENTER_LOWER, CS_ENABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_RECENTER_UPPER, CS_ENABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_LOWER, CS_ENABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, channel, XCON_RECENTER_UPPER, CS_ENABLE);
  }

  else if (client == TEN_TRAFFIC_TYPE_8GFC_RA) {
    rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_PP10G);
    rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_PP10G);

    rtn |= ten_xcon_config_es_mode(dev_id,
                                   es,
                                   XCON_FP, XCON_NO_GFP,
                                   XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_xcon_config_es_mode(dev_id,
                                   channel,
                                   XCON_FP, XCON_NO_GFP,
                                   XCON_MODE_CUT_THRU,  XCON_MODE_PKT);

    rtn |= ten_n10g_set_pktie(mod_line,   slice_line,   1);
    rtn |= ten_n10g_set_pktie(mod_client, slice_client, 1);

    rtn |= ten_xcon_select_es_packet_centering(dev_id,
                                               es,
                                               XCON_AUTO_CENTER,    CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id,
                                               es,
                                               XCON_RECENTER_LOWER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id,
                                               es,
                                               XCON_RECENTER_UPPER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id,
                                               channel,
                                               XCON_AUTO_CENTER,    CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id,
                                               channel,
                                               XCON_RECENTER_LOWER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(dev_id,
                                               channel,
                                               XCON_RECENTER_UPPER, CS_DISABLE);
  }

  else if ((client == TEN_TRAFFIC_TYPE_8GFC_ENH) ||
           (client == TEN_TRAFFIC_TYPE_1GE)){ /* Bugzilla 38871 */
    rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_N10G);
    rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_N10G);

    rtn |= ten_xcon_config_es_mode(dev_id,
                                   es,
                                   XCON_FP, XCON_NO_GFP,
                                   XCON_MODE_CUT_THRU, XCON_MODE_CCT);
                                  
    rtn |= ten_xcon_config_es_mode(dev_id,
                                   channel,
                                   XCON_FP, XCON_NO_GFP,
                                   XCON_MODE_CUT_THRU, XCON_MODE_CCT);

    rtn |= ten_n10g_set_pktie(mod_line,   slice_line,   0);
    rtn |= ten_n10g_set_pktie(mod_client, slice_client, 0);
  }
  
  /* Bugzilla 26200 Start */
  else if (client == TEN_TRAFFIC_TYPE_SERIAL_40GE) {
    rtn |= ten_xcon_es_select_source(dev_id, es, channel, XCON_N10G);
    rtn |= ten_xcon_config_es_mode(dev_id, es, XCON_FP, XCON_NO_GFP, XCON_MODE_CUT_THRU, XCON_MODE_CCT);
    rtn |= ten_xcon_es_select_source(dev_id, channel, es, XCON_N10G);
    rtn |= ten_xcon_config_es_mode(dev_id, channel, XCON_FP, XCON_NO_GFP, XCON_MODE_CUT_THRU, XCON_MODE_CCT);
  }
  /* Bugzilla 26200 End */
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() Invalid XCON mode.", func); 
    rtn = CS_ERROR;
  }  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL XCON CFG                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_xcon_cfg(cs_uint16 dev_id, 
                          cs_uint8 slice,
                          cs_uint8 mode)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the cross connect block.                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_XCON_DISABLE                              = 0,         */
/*   TEN_XCON_10GE_GFP_OTU3                        = 1,         */
/*   TEN_XCON_OTU3_GFP_10GE                        = 2,         */
/*   TEN_XCON_10GE_RA_FC_OTU3                      = 3,         */
/*   TEN_XCON_OTU3_RA_FC_10GE                      = 4,         */
/*   TEN_XCON_10GFC_TRANS_OTU3P                    = 5,         */
/*   TEN_XCON_10GE_RA_GFP                          = 6,         */
/*   TEN_XCON_GFP_RA_10GE                          = 7,         */
/*   TEN_XCON_10GE_RA_OTU2E                        = 8,         */
/*   TEN_XCON_OTU2E_RA_10GE                        = 9,         */
/*   TEN_XCON_10GE_OC192_OTU2                      = 10,        */
/*   TEN_XCON_OTU2_OC192_10GE                      = 11,        */
/*   TEN_XCON_10GE_RA                              = 12,        */
/*   TEN_XCON_10GE_MON_OTU2                        = 13,        */
/*   TEN_XCON_10GFC_TRANS_OTU2                     = 14,        */
/*   TEN_XCON_8GFC_MON_OTU2                        = 15,        */
/*   TEN_XCON_10GE_OTU2E_OTU3P                     = 16,        */
/*   TEN_XCON_10GE_OTU1E_OTU3P                     = 17,        */
/*   TEN_XCON_10GE_OC192_OTU3P                     = 18,        */
/*   TEN_XCON_OTU3P_OC192_10GE                     = 19,        */
/*   TEN_XCON_GRP_T_OTU3P                          = 20,        */
/*   TEN_XCON_10GFC_OTU2FC                         = 21,        */
/*   TEN_XCON_8GFC_OTU2                            = 22,        */
/*   TEN_XCON_OTU2_8GFC                            = 23,        */
/*   TEN_XCON_TABLE15P4                            = 24,        */
/*   TEN_XCON_TABLE16P0                            = 25,        */
/*   TEN_XCON_TABLE16MIX_P0                        = 26,        */
/*   TEN_XCON_TABLE16MIX_P1                        = 27,        */
/*   TEN_XCON_TABLE16MIX_P2                        = 28,        */
/*   TEN_XCON_TABLE19P0                            = 29,        */
/*   TEN_XCON_TABLE19MIX_P0                        = 30,        */
/*   TEN_XCON_TABLE19MIX_P1                        = 31,        */
/*   TEN_XCON_TABLE19MIX_P2                        = 32.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;

  CS_PRINT("ten_hl_xcon_cfg\n");

  /* Assert block-level resets*/
  if (ten_xcon_datapath_reset(dev_id, CS_RESET_ASSERT) != CS_OK) {
     ret_val = CS_ERROR;
     goto RTN_EXIT;
  }
  if (ten_xcon_es_reset(dev_id, XCON_ELASTIC_STORE_ALL, CS_RESET_ASSERT) != CS_OK) {
    ret_val = CS_ERROR;
    goto RTN_EXIT;
  }
  
  /* Configure XCON */
  if (mode >= TEN_XCON_MAX_MODE) {
     CS_PRINT("Invalid Mode!\n");
     ret_val = CS_ERROR;
     goto RTN_EXIT;
  };

  CS_PRINT("mode = (%d) %s\n", mode, ten_xcon_debug_str[mode]);
  
  CS_PRINT("CONFIG_PKT_MODE                = 0x%04X\n", ten_xcon_table[TEN_XCON_CONFIG_PKT_MODE][mode]);
  CS_PRINT("CONFIG_SF_MODE                 = 0x%04X\n", ten_xcon_table[TEN_XCON_CONFIG_SF_MODE][mode]);
  CS_PRINT("CONFIG_GFP_MODE                = 0x%04X\n", ten_xcon_table[TEN_XCON_CONFIG_GFP_MODE][mode]);
  CS_PRINT("CONFIG_AUTO_RECENTER_LOWER     = 0x%04X\n", ten_xcon_table[TEN_XCON_CONFIG_AUTO_RECENTER_LOWER][mode]);
  CS_PRINT("CONFIG_AUTO_RECENTER_UPPER     = 0x%04X\n", ten_xcon_table[TEN_XCON_CONFIG_AUTO_RECENTER_UPPER][mode]);
  CS_PRINT("CONFIG_AUTO_CENTER             = 0x%04X\n", ten_xcon_table[TEN_XCON_CONFIG_AUTO_CENTER][mode]);
  CS_PRINT("IML_THRESH_IML_THRESH          = 0x%04X\n", ten_xcon_table[TEN_XCON_IML_THRESH_IML_THRESH][mode]);
  CS_PRINT("CIRCUIT_THRESHOLD_UPPER_LEVEL  = 0x%04X\n", ten_xcon_table[TEN_XCON_CIRCUIT_THRESHOLD_UPPER_LEVEL][mode]);
  CS_PRINT("CIRCUIT_THRESHOLD_LOWER_LEVEL  = 0x%04X\n", ten_xcon_table[TEN_XCON_CIRCUIT_THRESHOLD_LOWER_LEVEL][mode]);
  CS_PRINT("ES_0_THRESHOLD_LEVEL_0_LEVEL   = 0x%04X\n", ten_xcon_table[TEN_XCON_ES_0_THRESHOLD_LEVEL_0_LEVEL][mode]);
  CS_PRINT("ES_0_THRESHOLD_LEVEL_5_LEVEL   = 0x%04X\n", ten_xcon_table[TEN_XCON_ES_0_THRESHOLD_LEVEL_5_LEVEL][mode]);
  CS_PRINT("ES_0_PAUSE_LEVEL_0_LEVEL       = 0x%04X\n", ten_xcon_table[TEN_XCON_ES_0_PAUSE_LEVEL_0_LEVEL][mode]);
  CS_PRINT("ES_0_THRESHOLD_LEVEL_3_LEVEL   = 0x%04X\n", ten_xcon_table[TEN_XCON_ES_0_THRESHOLD_LEVEL_3_LEVEL][mode]);
  CS_PRINT("ES_0_THRESHOLD_LEVEL_4_LEVEL   = 0x%04X\n", ten_xcon_table[TEN_XCON_ES_0_THRESHOLD_LEVEL_4_LEVEL][mode]);
  CS_PRINT("ES_0_THRESHOLD_LEVEL_2_LEVEL   = 0x%04X\n", ten_xcon_table[TEN_XCON_ES_0_THRESHOLD_LEVEL_2_LEVEL][mode]);
 
  CS_PRINT("Begin XCON initialization (mode = %d)...\n", mode);

  ten_xcon_config_es_mode(dev_id, slice,
                          XCON_FP,
                          ten_xcon_table[TEN_XCON_CONFIG_GFP_MODE][mode],
                          ten_xcon_table[TEN_XCON_CONFIG_SF_MODE][mode],
                          ten_xcon_table[TEN_XCON_CONFIG_PKT_MODE][mode]);
  
  ten_xcon_select_es_packet_centering(dev_id, slice,
                                      XCON_RECENTER_LOWER,
                                      ten_xcon_table[TEN_XCON_CONFIG_AUTO_RECENTER_LOWER][mode]);

  ten_xcon_select_es_packet_centering(dev_id, slice,
                                      XCON_RECENTER_UPPER,
                                      ten_xcon_table[TEN_XCON_CONFIG_AUTO_RECENTER_UPPER][mode]);

  ten_xcon_select_es_packet_centering(dev_id, slice,
                                      XCON_AUTO_CENTER,
                                      ten_xcon_table[TEN_XCON_CONFIG_AUTO_CENTER][mode]);

  ten_xcon_set_circuit_thresholds(dev_id, slice,
                                  XCON_ES_IML_THRESH,
                                  ten_xcon_table[TEN_XCON_IML_THRESH_IML_THRESH][mode]);

  ten_xcon_set_circuit_thresholds(dev_id, slice,
                                  XCON_ES_CIRCUIT_THRESHOLD_UPPER,
                                  ten_xcon_table[TEN_XCON_CIRCUIT_THRESHOLD_UPPER_LEVEL][mode]);

  ten_xcon_set_circuit_thresholds(dev_id, slice,
                                  XCON_ES_CIRCUIT_THRESHOLD_LOWER,
                                  ten_xcon_table[TEN_XCON_CIRCUIT_THRESHOLD_LOWER_LEVEL][mode]);

  ten_xcon_set_es_watermark_level(dev_id, slice,
                                  XCON_THRESHOLD_LEVEL_0,
                                  ten_xcon_table[TEN_XCON_ES_0_THRESHOLD_LEVEL_0_LEVEL][mode]);

  ten_xcon_set_es_watermark_level(dev_id, slice,
                                  XCON_THRESHOLD_LEVEL_5,
                                  ten_xcon_table[TEN_XCON_ES_0_THRESHOLD_LEVEL_5_LEVEL][mode]);

  ten_xcon_set_es_pause_frame_watermark_level(dev_id, slice,
                                              XCON_PAUSE_LEVEL_0,
                                              ten_xcon_table[TEN_XCON_ES_0_PAUSE_LEVEL_0_LEVEL][mode]);

  ten_xcon_set_es_watermark_level(dev_id, slice,
                                  XCON_THRESHOLD_LEVEL_3,
                                  ten_xcon_table[TEN_XCON_ES_0_THRESHOLD_LEVEL_3_LEVEL ][mode]);

  ten_xcon_set_es_watermark_level(dev_id, slice,
                                  XCON_THRESHOLD_LEVEL_4,
                                  ten_xcon_table[TEN_XCON_ES_0_THRESHOLD_LEVEL_4_LEVEL ][mode]);

  CS_PRINT("ten_hl_xcon_cfg initialization done.\n");

RTN_EXIT: 
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  SET CBERT GENERATOR                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_xcon_set_cbert_generator(cs_uint16 dev_id, cs_uint8 channel)
/* INPUTS     : o Device Id                                     */
/*              o Channel                                       */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the CBERT generator.                                    */
/*                                                              */
/* The [channel] parameter is specified as:                     */
/*   0-7 or XCON_ELASTIC_STORE_ALL (0xFF)                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_status ret_val = CS_OK;

  CS_PRINT("\n");;
  CS_PRINT("Begin XCON set generator\n");

  /* Set sources for CBERT according to channel*/
  for (ii=0; ii < TEN_XCON_CBERT_COUNT; ii++) {
    if ((ii == channel) || (channel == XCON_ELASTIC_STORE_ALL)) {    
      ret_val = ten_xcon_es_select_read_source(dev_id, ii, XCON_CBERT);
      if (ret_val != CS_OK) {
        goto RTN_EXIT;
      }  

      ret_val = ten_xcon_select_bert(dev_id, ii, XCON_CBERT);
      if (ret_val != CS_OK) {
        goto RTN_EXIT;
      }  
    }    
  }
  
  /* Set ES drivers*/
  ret_val = ten_xcon_cbert_control_generator(dev_id, channel, CS_ENABLE);
  if (ret_val != CS_OK) {
    goto RTN_EXIT;
  }  

  /* Configure PRBS (always choose shortest)*/
  ret_val = ten_xcon_cbert_config(dev_id, channel, XCON_PRBS_POLY_DEGREE_07);

RTN_EXIT: 
  return (ret_val);

}

/****************************************************************/
/* $rtn_hdr_start  SET CBERT CHECKER                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_xcon_set_cbert_checker(cs_uint16 dev_id, cs_uint8 channel)
/* INPUTS     : o Device Id                                     */
/*              o Path                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the CBERT checker.                                      */
/*                                                              */
/* The [channel] parameter is specified as:                     */
/*   0-7 or XCON_ELASTIC_STORE_ALL (0xFF)                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  cs_uint16 ii;
  CS_PRINT("ten_hl_xcon_set_cbert_checker\n");

  ret_val = ten_xcon_cbert_control_checker(dev_id, channel, CS_ENABLE);

  /* Clear error count (clears on read)*/
  for (ii=0; ii < TEN_XCON_CBERT_COUNT; ii++) {
    if ((ii == channel) || (channel == XCON_ELASTIC_STORE_ALL)) {    
      ret_val = ten_dev_clear_unit_stats(dev_id, TEN_ID_XCON, ii, 
                                         TEN_XCON_CBERT_PRBS_ERR_COUNT_STAT);
      if (ret_val != CS_OK) {
          CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": stats error"); 
         break;
      }
    }
  }  
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  CHECK CBERT                                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_xcon_check_cbert(cs_uint16 dev_id, cs_uint8 channel, 
                                  cs_uint16 threshold)
/* INPUTS     : o Device Id                                     */
/*              o Channel                                       */
/*              o Threshold                                     */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Check CBERT.                                                 */
/*                                                              */
/* The [channel] parameter is specified as:                     */
/*   0-7 or XCON_ELASTIC_STORE_ALL (0xFF)                       */
/*                                                              */
/* The [threshold] parameter is specified as:                   */
/*   0-0xFFFF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_status ret_val = CS_OK;
  ten_stats_data_t cntval;
  cs_int16 status;

  CS_PRINT("ten_hl_xcon_check_cbert\n");

  for (ii=0; ii < TEN_XCON_CBERT_COUNT; ii++) {
    if ((ii == channel) || (channel == XCON_ELASTIC_STORE_ALL)) {    
      /* See if PRBS is in sync state */
      if ((status = ten_xcon_cbert_get_sync_status(dev_id, ii)) != CS_OK) {
        CS_PRINT("Invalid parameter \n");
        return CS_ERROR;
      } 
      else {
        if(status == 1)
        CS_PRINT("CBERT channel #(%d) in sync.\n", ii);
      else {
        CS_PRINT("CBERT channel #(%d) not in sync.\n", ii);
          return CS_ERROR;
        }
      }

      /* Read error count */
      /* For XCON, section IDs are used for channel number identifiers  */
      if (ten_dev_get_unit_stats(dev_id, TEN_ID_XCON, ii, 
                                 TEN_XCON_CBERT_PRBS_ERR_COUNT_STAT,
                                 CS_RX, &cntval) != CS_OK) {
        CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": stats error"); 
        ret_val = CS_ERROR;
        goto RTN_EXIT;                              
      }       
      /* Compare to threshold */
      if ((cntval.rx_ms) || (cntval.rx_ls > threshold)) {
        CS_PRINT("CBERT channel #(%d) errors (%016lX) exceeded threshold 0x(%08X)_(%08X)\n", 
                 ii, cntval.rx_ms, cntval.rx_ls, threshold);
        CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": CBERT error mismatch."); 
        ret_val = CS_ERROR;
        goto RTN_EXIT;     
      }
      else {
        CS_PRINT("Successful CBERT channel #(%d) compare.\n", ii);
      }
    }
    else {
      CS_PRINT("CBERT channel #(%d) not checked.\n", ii);
    }  
  }
RTN_EXIT:
  return (ret_val);
}

/* Bugzilla 24360 Start */
/****************************************************************/
/*   SADECO CONFIG                                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_sadeco_config (cs_uint16 dev_id, 
                                cs_uint16 line_traffic_type,
                                cs_uint16 client_traffic_type,
                                cs_uint16 client_term,
                                cs_uint16 ncols_line,
                                cs_uint16 ncols_client,
                                cs_uint16 module_line)




/*                                                              */
/*                                                  */
/****************************************************************/
{

  cs_status ret_val = CS_OK;
  cs_uint16 module_client = (module_line == TEN_MODULE_A) ? TEN_MODULE_B : TEN_MODULE_A;
  cs_char8 *func = "ten_hl_sadeco_config";  


  CS_PRINT("%s() %s, %s, client_term = %d, ncols_line = %d, ncols_client = %d, module_line %s\n",
           func,
           ten_hl_config_traffic_types_strings[line_traffic_type],
           ten_hl_config_traffic_types_strings[client_traffic_type],
           client_term,
           ncols_line,
           ncols_client,
           ten_module_strings[module_line&1]);


  /* Provision the Sadeco */
  /*if ((client == TEN_TRAFFIC_TYPE_OC768) && (term_sonet != TEN_OC192_TERM_TRANSPARENT_CBR10)) {*/
  if ((client_traffic_type == TEN_TRAFFIC_TYPE_OC768) && (client_term != TEN_OC192_TERM_TRANSPARENT_CBR10)) {
  /*if (((traffic_type_module_a == TEN_TRAFFIC_TYPE_OC768) || (traffic_type_module_b == TEN_TRAFFIC_TYPE_OC768)) && */
  /*    (term_sonet != TEN_OC192_TERM_TRANSPARENT_CBR10)) {                                                         */
    /* Configure the SADECO delay and compensation for Sonet SDH interleaving */
    /*ten_xcon_sadeco_config (dev_id, mod_client, 0x200, 0x1F00, XCON_SONET_SDH_64);*/
    /*ten_xcon_sadeco_config (dev_id, mod_line  , 0x200, 0x1F00, XCON_SONET_SDH_64);*/
    ten_xcon_sadeco_config (dev_id, TEN_MODULE_A, 0x200, 0x1F00, XCON_SONET_SDH_64);
    ten_xcon_sadeco_config (dev_id, TEN_MODULE_B, 0x200, 0x1F00, XCON_SONET_SDH_64);

    /* Provision Skew and Delay Compensation Sonet Frame Length. */
    /*ten_xcon_sadeco_sdclen (dev_id, mod_client, 0x97E0);*/    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */
    /*ten_xcon_sadeco_sdclen (dev_id, mod_line,   0x97E0);*/    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */      
    ten_xcon_sadeco_sdclen (dev_id, TEN_MODULE_A, 0x97E0);    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */
    ten_xcon_sadeco_sdclen (dev_id, TEN_MODULE_B,   0x97E0);    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */      
  }
  /*else if ((client == TEN_TRAFFIC_TYPE_OTU3) && (line == TEN_TRAFFIC_TYPE_OTU3)) {*/
  /*else if ((traffic_type_module_a == TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_module_b == TEN_TRAFFIC_TYPE_OTU3)) {*/
  else if ((line_traffic_type == TEN_TRAFFIC_TYPE_OTU3) && (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3)) {
    /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
    /*ten_xcon_sadeco_config (dev_id, mod_client, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);*/
    /*ten_xcon_sadeco_config (dev_id, mod_line  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);*/
    ten_xcon_sadeco_config (dev_id, TEN_MODULE_A, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
    ten_xcon_sadeco_config (dev_id, TEN_MODULE_B, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

    /* Bugzilla 21131 Start */
    /* Provision Skew and Delay Compensation Frame Length. */
    /*if (term_otu == TEN_OTU_TERM_FULL) {*/
    if (client_term == TEN_OTU_TERM_FULL) {
      /*ten_xcon_sadeco_sdclen (dev_id, mod_client, 0x3B0);*/    /* [255 columns - 16(FEC) - 2(FS) - 1(OH)]  * 4 */ 
      /*ten_xcon_sadeco_sdclen (dev_id, mod_line,   0x3B0);*/    /* [255 columns - 16(FEC) - 2(FS) - 1(OH)]  * 4 */      
      ten_xcon_sadeco_sdclen (dev_id, TEN_MODULE_A, 0x3B0);    /* [255 columns - 16(FEC) - 2(FS) - 1(OH)]  * 4 */ 
      ten_xcon_sadeco_sdclen (dev_id, TEN_MODULE_B, 0x3B0);    /* [255 columns - 16(FEC) - 2(FS) - 1(OH)]  * 4 */      
    } else {
      /*ten_xcon_sadeco_sdclen (dev_id, mod_client, 0x3BC);*/    /* [255 columns - 16(FEC)]  * 4 */ 
      /*ten_xcon_sadeco_sdclen (dev_id, mod_line,   0x3BC);*/    /* [255 columns - 16(FEC)]  * 4 */      
      ten_xcon_sadeco_sdclen (dev_id, TEN_MODULE_A, 0x3BC);    /* [255 columns - 16(FEC)]  * 4 */ 
      ten_xcon_sadeco_sdclen (dev_id, TEN_MODULE_B, 0x3BC);    /* [255 columns - 16(FEC)]  * 4 */      
    }  
    /* Bugzilla 21131 End */
  }
  /* Bugzilla 26566 Start */
  else if (((line_traffic_type == TEN_TRAFFIC_TYPE_OTU3P) && (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3)) ||
           ((line_traffic_type == TEN_TRAFFIC_TYPE_OTU3E) && (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3)) ||
           ((line_traffic_type == TEN_TRAFFIC_TYPE_OTU3E1) && (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3)) ||
           ((line_traffic_type == TEN_TRAFFIC_TYPE_OTU3E2) && (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3))) {  /* Bugzilla 29481 */
    /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
    ten_xcon_sadeco_config (dev_id, TEN_MODULE_A, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
    ten_xcon_sadeco_config (dev_id, TEN_MODULE_B, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

    /* Provision Skew and Delay Compensation Frame Length. */
    ten_xcon_sadeco_sdclen (dev_id, TEN_MODULE_A, 0x3BC);    /* [255 columns - 16(FEC)]  * 4 */ 
    ten_xcon_sadeco_sdclen (dev_id, TEN_MODULE_B, 0x3BC);    /* [255 columns - 16(FEC)]  * 4 */      
  }
  /* Bugzilla 26566 End */
  else {
    /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
    /*ten_xcon_sadeco_config (dev_id, mod_client, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);*/
    /*ten_xcon_sadeco_config (dev_id, mod_line  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);*/
    ten_xcon_sadeco_config (dev_id, TEN_MODULE_A, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
    ten_xcon_sadeco_config (dev_id, TEN_MODULE_B, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

    /* Provision Skew and Delay Compensation Frame Length. */
    /*ten_xcon_sadeco_sdclen (dev_id, mod_client, 0x3B0); */   /* [255 columns - 16(FEC) - 1(OH) - 2(FS)]  * 4 */
    /*ten_xcon_sadeco_sdclen (dev_id, mod_line,   0x3BC); */   /* [255 columns - 16(FEC)] * 4 */      
    
    /*ten_xcon_sadeco_sdclen (dev_id, mod_client, (ncols_line - npar_line - (stm256md * 2) - stm64md) * 4);*/    /* [255 columns - 16(FEC) - 1(OH) - 2(FS)]  * 4 */
    /*ten_xcon_sadeco_sdclen (dev_id, mod_line, (ncols_client + 1) * 4);*/    /* [255 columns - 16(FEC)] * 4 */
    /*ten_xcon_sadeco_sdclen (dev_id, module_line, ncols_client * 4);*/    /* [255 columns - 16(FEC) - 1(OH) - 2(FS)]  * 4 */
    /*ten_xcon_sadeco_sdclen (dev_id, module_client, ncols_line * 4);*/    /* [255 columns - 16(FEC)] * 4 */
    ten_xcon_sadeco_sdclen (dev_id, module_client, ncols_client * 4);    /* [255 columns - 16(FEC) - 1(OH) - 2(FS)]  * 4 */
    ten_xcon_sadeco_sdclen (dev_id, module_line, ncols_line * 4);    /* [255 columns - 16(FEC)] * 4 */
  }
  /* Select incoming reference and tributary streams */
  /*ten_xcon_sadeco_sel_data_stream (dev_id, mod_client, 0x0F, 0x1F);*/
  /*ten_xcon_sadeco_sel_data_stream (dev_id, mod_line  , 0x0F, 0x1F);*/
  ten_xcon_sadeco_sel_data_stream (dev_id, TEN_MODULE_A, 0x0F, 0x1F);
  ten_xcon_sadeco_sel_data_stream (dev_id, TEN_MODULE_B, 0x0F, 0x1F);
  
  /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
  /*ten_xcon_sadeco_enable_fp (dev_id, mod_client, CS_ENABLE);*/
  /*ten_xcon_sadeco_enable_fp (dev_id, mod_line  , CS_ENABLE);*/
  ten_xcon_sadeco_enable_fp (dev_id, TEN_INSTANCE_ALL, CS_ENABLE);
                                       
  return (ret_val);
}
/* Bugzilla 24360 End */

/****************************************************************/
/* $rtn_hdr_start  XCON CONFIG T41                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_xcon_config_t41(cs_uint16   dev_id,
                                 cs_uint8    es_index,
                                 cs_uint8    es_source,
                                 cs_uint8    interface,
                                 cs_uint8    mfp_mode,
                                 cs_uint8    gfp_mode,
                                 cs_uint8    pkt_mode,
                                 cs_uint8    fp_align,
                                 cs_uint8    recenter_type,
                                 cs_uint32   sysclk_freq)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Index                           */
/*              o Elastic Store Source                          */
/*              o Interface                                     */
/*              o MFP Mode                                      */
/*              o GFP Mode                                      */
/*              o Packet Mode                                   */
/*              o FP Align                                      */
/*              o Recenter Type                                 */
/*              o System Clock Frequency                        */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures a bidirectional unicast cross-connect path.       */
/*                                                              */
/* The [es_index] parameter is specified as:                    */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*                                                              */
/* The [es_source] parameter is specified as:                   */
/*   0 = XCON_MODULE_A_CHANNEL_1                                */
/*   1 = XCON_MODULE_A_CHANNEL_2                                */
/*   2 = XCON_MODULE_A_CHANNEL_3                                */
/*   3 = XCON_MODULE_A_CHANNEL_4                                */
/*   4 = XCON_MODULE_B_CHANNEL_1                                */
/*   5 = XCON_MODULE_B_CHANNEL_2                                */
/*   6 = XCON_MODULE_B_CHANNEL_3                                */
/*   7 = XCON_MODULE_B_CHANNEL_4                                */
/*                                                              */
/* The [interface] parameter is specified as:                   */
/*                                                              */
/* The [mfp_mode] parameter is specified as:                    */
/*   0..1                                                       */
/*   When MFP_MODE is set to 1, use the mfp indicator from the  */
/*   n10g instead of the fp indicator to synchronize frames.    */
/*   MFP_MODE only affects circuit mode and not packet mode.    */
/*   MFP_MODE must be 0 when FP_ALIGN_EN is set for amplitude   */
/*   recenter operation.                                        */
/*                                                              */
/* The [gfp_mode] parameter is specified as:                    */
/*   0..1                                                       */
/*   GFP_MODE along with PKT_MODE and SF_MODE must be enabled   */
/*   whenever GFP traffic is passed through the elastic store.  */
/*   For other traffic types, GFP_MODE must be disabled.        */
/*                                                              */
/* The [pkt_mode] parameter is specified as:                    */
/*   0 = XCON_N10G (circuit mode)                               */
/*   1 = XCON_PP10G                                             */
/*                                                              */
/* The [fp_align] parameter is specified as:                    */
/*   0..1                                                       */
/*   Aligns an amplitude recenter with a receive frame pulse at */
/*   the output of the elastic store. This mode must only be    */
/*   enabled for configurations in which the transmit framer    */
/*   re-aligns to the receive frame pulse.                      */
/*                                                              */
/* The [recenter_type] parameter is specified as:               */
/*   0 = XCON_ES_RECENTER_IML                                   */
/*   1 = XCON_ES_RECENTER_AMPLITUDE                             */
/*                                                              */
/* The [sysclk_freq] parameter is specified as:                 */
/*   the sysclk frequency in hertz, i.e., 425000000             */
/*                                                              */
/* NOTE: RX Threshold select is programmed by this API and is   */
/*       the exact opposite of ES source select.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;

  CS_PRINT("config_xcon_t41: dev_id=%d, es_index=%d, es_source=%d, interface=%d\n", 
           dev_id, es_index, es_source, interface);
  CS_PRINT("                 mfp_mode=%d, gfp_mode=%d, pkt_mode=%d, fp_align=%d\n", 
           mfp_mode, gfp_mode, pkt_mode, fp_align);
  CS_PRINT("                 recenter_type=%d, sysclk_freq=%d\n",
           recenter_type, sysclk_freq);

  /* GLB_CFG */
  /* Enable clocks */
  ret_val |= ten_xcon_disable_es_clock_t41(dev_id, es_index, CS_ENABLE);
  /* TX Alignment */
  ret_val |= ten_xcon_enable_tx_algn_t41(dev_id, es_index, fp_align);

  /* Write source_select, interface_select, and rx threshold */
  ret_val |= ten_xcon_es_select_source_no_rx_thresh(dev_id, es_index, es_source, pkt_mode);
  ret_val |= ten_xcon_es_rx_threshold_select(dev_id, es_index, es_source);
  ret_val |= ten_xcon_threshold_select(dev_id, es_index, es_source, XCON_ES_RX_THRESHOLD);

  /* Interface selection: N10G or PP10G */
  ret_val |= ten_xcon_es_select_source(dev_id,es_index, es_source, pkt_mode);

  /* Write quanta_select */
  ret_val |= ten_xcon_select_es_pause_quanta_source(dev_id, es_index, es_source);

  /* Write pp_es_pause_threshold_select */
  ret_val |= ten_xcon_set_es_pause_threshold_select(dev_id, es_index, es_source);

  /* Turn BERT off */
  ret_val |= ten_xcon_select_bert(dev_id, es_index, XCON_BERT_OFF);
  ret_val |= ten_xcon_es_select_read_source(dev_id, es_index, XCON_BERT_OFF);

  /* Circuit mode: set mfp_mode */
  ret_val |= ten_xcon_es_config_t41(dev_id, es_index, XCON_ES_CONFIG_MFP_MODE, mfp_mode);

  /* Packet mode: set gfp_mode */
  ret_val |= ten_xcon_es_config_t41(dev_id, es_index, XCON_ES_CONFIG_GFP_MODE, gfp_mode);


  if (recenter_type == XCON_ES_RECENTER_AMPLITUDE) {
    /* Amplitude recenter */
    ret_val |= ten_xcon_es_recenter_enables_t41(dev_id, es_index,
                                                XCON_ES_RECENTER_AMPLITUDE_RECENTER_EN,
                                                CS_ENABLE);
    ret_val |= ten_xcon_es_recenter_enables_t41(dev_id, es_index,
                                                XCON_ES_RECENTER_ACCUMULATE_EN,
                                                CS_DISABLE);
    ret_val |= ten_xcon_es_recenter_enables_t41(dev_id, es_index,
                                                XCON_ES_RECENTER_FP_ALIGN_EN,
                                                fp_align);
    /* 2 ms measurement period */
    ret_val |= ten_xcon_es_recenter_measure_period_t41(dev_id, es_index, 2, sysclk_freq);
  }
  else {
    /* IML recenter */
    ret_val |= ten_xcon_es_recenter_enables_t41(dev_id, es_index,
                                                XCON_ES_RECENTER_AMPLITUDE_RECENTER_EN,
                                                CS_DISABLE);
    ret_val |= ten_xcon_es_recenter_enables_t41(dev_id, es_index,
                                                XCON_ES_RECENTER_ACCUMULATE_EN,
                                                CS_ENABLE);
    ret_val |= ten_xcon_es_recenter_enables_t41(dev_id, es_index,
                                                XCON_ES_RECENTER_LOWER_VIOLATION_EN,
                                                CS_ENABLE);
    ret_val |= ten_xcon_es_recenter_enables_t41(dev_id, es_index,
                                                XCON_ES_RECENTER_UPPER_VIOLATION_EN,
                                                CS_ENABLE);
  }

  return (ret_val);
}

/* Bugzilla 27270 Start */
/********************************************************************/
/* High level functions for ES autorecentering                      */
/********************************************************************/

/********************************************************************/
/* $rtn_hdr_start  XCON ES AMPL RECENTER 40G T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_xcon_es_amplitude_recenter_40g_t41(cs_uint16 dev_id,
                                                    cs_uint8  module_num_ov,
                                                    cs_uint16 margin_lower,
                                                    cs_uint16 margin_upper,
                                                    cs_uint16 correct_lower,
                                                    cs_uint16 correct_upper,
                                                    cs_uint8  duration,
                                                    cs_uint32 sysclk_freq)
/* INPUTS     : o Device Id                                         */
/*              o Module Number (overloaded in release 5.5)         */
/*              o Margin Lower                                      */
/*              o Margin Upper                                      */
/*              o Correction Lower                                  */
/*              o Correction Upper                                  */
/*              o Duration                                          */
/*              o System Clock Frequency                            */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up the specified module's ES registers for recentering      */
/* based on ES amplitude measurements over a specied duration. The  */
/* ES depth is a function of measured amplitude and specified       */
/* margins. Then recenters and enables circuit thresholds.          */
/*                                                                  */
/* DOES NOT start a recenter if setup fails.                        */
/* DOES NOT enable circuit thresholds if recenter fails             */
/*                                                                  */
/* The [module_num_ov] parameter is overloaded:                     */
/*   Module number bit-OR'd with recovery mode, where elastic       */
/*   store ID can be                                                */
/*     0 = TEN_MODULE_A (ES # 0-3)                                  */
/*     1 = TEN_MODULE_B (ES # 4-7)                                  */
/*   and (new for 5.5) recovery mode is                             */
/*     0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):         */
/*       Default is 'none' for backward compatibility.              */
/*     0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):     */
/*       Framer and upper/lower ES violation event handlers kick    */
/*       off recenter, which completes using recenter status        */
/*       polling and system timers.                                 */
/*                                                                  */
/* The [margin_lower] parameter is specified as:                    */
/*   0..0x1fff, the amount of lwoer margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [margin_upper] parameter is specified as:                    */
/*   0..0x1fff, the amount of upper margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [correct_lower] parameter is specified as:                   */
/*   0..0x01ff, the amount to increase XCON_ES_CIRCUIT_THRESHOLD_   */
/*   LOWER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [correct_upper] parameter is specified as:                   */
/*   0..0x01ff, the amount to decrease XCON_ES_CIRCUIT_THRESHOLD_   */
/*   UPPER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [duration] parameter is specified as:                        */
/*    1..157~168 milliseconds, depending on sysclk_freq             */
/*    Number of milliseconds to measure depth for Amplitude         */
/*     Recentering.                                                 */
/*                                                                  */
/* The [sysclk_freq] parameter is specified as:                     */
/*   the sysclk frequency in hertz, i.e., 425000000                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
return ten_xcon_es_amplitude_recenter_40g_cb( dev_id, module_num_ov,
                                              margin_lower,  margin_upper,
                                              correct_lower, correct_upper,
                                              duration, sysclk_freq, XCON_ES_UPDATE_CB_TRUE);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES AMPLITUDE RECENTER T41                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_xcon_es_amplitude_recenter_t41(cs_uint16 dev_id,
                                                ten_xcon_es_num_t es_num_ovl,
                                                cs_uint16 margin_lower,
                                                cs_uint16 margin_upper,
                                                cs_uint16 correct_lower,
                                                cs_uint16 correct_upper,
                                                cs_uint8  duration,
                                                cs_uint32 sysclk_freq)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id  (overloaded in Release 5.5)     */
/*              o Margin Lower                                      */
/*              o Margin Upper                                      */
/*              o Correction Lower                                  */
/*              o Correction Upper                                  */
/*              o Duration                                          */
/*              o System Clock Frequency                            */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up the specified module's ES registers for recentering      */
/* based on ES amplitude measurements over a specied duration. The  */
/* ES depth is a function of measured amplitude and specified       */
/* margins. Then recenters and enables circuit thresholds.          */
/*                                                                  */
/* DOES NOT start a recenter if setup fails.                        */
/* DOES NOT enable circuit thresholds if recenter fails             */
/*                                                                  */
/* The [es_num_ovl] parameter is overloaded:                        */
/*   Elastic store ID bit-OR'd with recovery mode, where elastic    */
/*   store ID can be                                                */
/*     0 = XCON_ELASTIC_STORE_0                                     */
/*     1 = XCON_ELASTIC_STORE_1                                     */
/*     2 = XCON_ELASTIC_STORE_2                                     */
/*     3 = XCON_ELASTIC_STORE_3                                     */
/*     4 = XCON_ELASTIC_STORE_4                                     */
/*     5 = XCON_ELASTIC_STORE_5                                     */
/*     6 = XCON_ELASTIC_STORE_6                                     */
/*     7 = XCON_ELASTIC_STORE_7                                     */
/*   and (new for 5.5) recovery mode is                             */
/*     0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):         */
/*       Default is 'none' for backward compatibility.              */
/*     0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):     */
/*       Framer and upper/lower ES violation event handlers kick    */
/*       off recenter, which completes using recenter status        */
/*       polling and system timers.                                 */
/*                                                                  */
/* The [margin_lower] parameter is specified as:                    */
/*   0..0x1fff, the amount of lwoer margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [margin_upper] parameter is specified as:                    */
/*   0..0x1fff, the amount of upper margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [correct_lower] parameter is specified as:                   */
/*   0..0x01ff, the amount to increase XCON_ES_CIRCUIT_THRESHOLD_   */
/*   LOWER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [correct_upper] parameter is specified as:                   */
/*   0..0x01ff, the amount to decrease XCON_ES_CIRCUIT_THRESHOLD_   */
/*   UPPER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [duration] parameter is specified as:                        */
/*    1..157~168 milliseconds, depending on sysclk_freq             */
/*    Number of milliseconds to measure depth for Amplitude         */
/*     Recentering.                                                 */
/*                                                                  */
/* The [sysclk_freq] parameter is specified as:                     */
/*   the sysclk frequency in hertz, i.e., 425000000                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return ten_xcon_es_amplitude_recenter_10g_cb( dev_id, es_num_ovl,
                                           margin_lower,  margin_upper,
                                           correct_lower, correct_upper,
                                           duration, sysclk_freq, XCON_ES_UPDATE_CB_TRUE);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES AMPLITUDE RECENTER WITH FPA 40G T41      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_xcon_es_amplitude_recenter_with_fpa_40g_t41(cs_uint16 dev_id,
                                                             cs_uint8  module_num_ov,
                                                             cs_uint16 static_depth,
                                                             cs_uint16 circuit_th_lower,
                                                             cs_uint16 circuit_th_upper)
/* INPUTS     : o Device Id                                         */
/*              o Module Number (overloaded in release 5.5)         */
/*              o Static Depth                                      */
/*              o Circuit Threshold Lower                           */
/*              o Circuit Threshold Upper                           */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up ES registers for amplitude recentering with frame pulse  */
/* alignment. The specified depth and circuit thresholds are used   */
/* instead of their calculated counterparts.                        */
/*                                                                  */
/* Then recenters and enables circuit thresholds.                   */
/*                                                                  */
/* DOES NOT start a recenter if setup fails.                        */
/* DOES NOT enable circuit thresholds if recenter fails             */
/*                                                                  */
/* The [module_num_ov] parameter is overloaded:                     */
/*   Module number bit-OR'd with recovery mode, where elastic       */
/*   store ID can be                                                */
/*     0 = TEN_MODULE_A (ES # 0-3)                                  */
/*     1 = TEN_MODULE_B (ES # 4-7)                                  */
/*   and (new for 5.5) recovery mode is                             */
/*     0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):         */
/*       Default is 'none' for backward compatibility.              */
/*     0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):     */
/*       Framer and upper/lower ES violation event handlers kick    */
/*       off recenter, which completes using recenter status        */
/*       polling and system timers.                                 */
/*                                                                  */
/* The [static_depth] parameter is specified as:                    */
/*    0..0x1fff, static_depth is used for an amplitude recenter     */
/*    instead of a calculated depth.                                */
/*                                                                  */
/* The [circuit_th_lower] parameter is specified as:                */
/*   1..0x1fff, Minimum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be smaller than           */
/*   IML_THRESH but no less than 1.                                 */
/*                                                                  */
/* The [circuit_th_upper] parameter is specified as:                */
/*   1..0x1ffe, Maximum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be larger than            */
/*   IML_THRESH but no larger than 8190.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return ten_xcon_es_amplitude_recenter_with_fpa_40g_cb(dev_id, module_num_ov,
                                                        static_depth, circuit_th_lower,
                                                        circuit_th_upper, XCON_ES_UPDATE_CB_TRUE);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES AMPLITUDE RECENTER WITH FPA T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_xcon_es_amplitude_recenter_with_fpa_t41(cs_uint16 dev_id,
                                                         ten_xcon_es_num_t es_num_ovl,
                                                         cs_uint16 static_depth,
                                                         cs_uint16 circuit_th_lower,
                                                         cs_uint16 circuit_th_upper)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id  (overloaded in Release 5.5)     */
/*              o Static Depth                                      */
/*              o Circuit Threshold Lower                           */
/*              o Circuit Threshold Upper                           */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up ES registers for amplitude recentering with frame pulse  */
/* alignment. The specified depth and circuit thresholds are used   */
/* instead of their calculated counterparts.                        */
/*                                                                  */
/* Then recenters and enables circuit thresholds.                   */
/*                                                                  */
/* DOES NOT start a recenter if setup fails.                        */
/* DOES NOT enable circuit thresholds if recenter fails             */
/*                                                                  */
/* The [es_num_ovl] parameter is overloaded:                        */
/*   Elastic store ID bit-OR'd with recovery mode, where elastic    */
/*   store ID can be                                                */
/*     0 = XCON_ELASTIC_STORE_0                                     */
/*     1 = XCON_ELASTIC_STORE_1                                     */
/*     2 = XCON_ELASTIC_STORE_2                                     */
/*     3 = XCON_ELASTIC_STORE_3                                     */
/*     4 = XCON_ELASTIC_STORE_4                                     */
/*     5 = XCON_ELASTIC_STORE_5                                     */
/*     6 = XCON_ELASTIC_STORE_6                                     */
/*     7 = XCON_ELASTIC_STORE_7                                     */
/*   and (new for 5.5) recovery mode is                             */
/*     0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):         */
/*       Default is 'none' for backward compatibility.              */
/*     0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):     */
/*       Framer and upper/lower ES violation event handlers kick    */
/*       off recenter, which completes using recenter status        */
/*       polling and system timers.                                 */
/*                                                                  */
/* The [static_depth] parameter is specified as:                    */
/*    0..0x1fff, static_depth is used for an amplitude recenter     */
/*    instead of a calculated depth.                                */
/*                                                                  */
/* The [circuit_th_lower] parameter is specified as:                */
/*   1..0x1fff, Minimum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be smaller than           */
/*   IML_THRESH but no less than 1.                                 */
/*                                                                  */
/* The [circuit_th_upper] parameter is specified as:                */
/*   1..0x1ffe, Maximum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be larger than            */
/*   IML_THRESH but no larger than 8190.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return ten_xcon_es_amplitude_recenter_with_fpa_10g_cb(dev_id, es_num_ovl,
                                                        static_depth, circuit_th_lower,
                                                        circuit_th_upper, XCON_ES_UPDATE_CB_TRUE);
}

/* Bugzilla 27270 Release 5.5 Amplitude Recentering                 */
/********************************************************************/
/* $rtn_hdr_start  XCON ES AMPLITUDE RECENTER FROM CB T41           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_xcon_es_amplitude_recenter_from_cb_t41(cs_uint16 dev_id,
                                                 ten_xcon_es_num_t es_num)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Using parameters stored in the xcon ES control block,  sets      */
/* up the specified module's ES registers for recentering based     */
/* on ES amplitude measurements over a specied duration. The        */
/* ES depth is a function of measured amplitude and specified       */
/* margins. Then recenters and enables circuit thresholds.          */
/*                                                                  */
/* Disables threshold interrupts and autorecentering in prep for    */
/* forced recentering and measurement phase.                        */
/*                                                                  */
/* The [es_num] parameter is specified as:                          */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint32     err_code = 0;
  ten_dev_cb_t *pdevcb = NULL;
  cs_char8     *func   = "ten_xcon_es_setup_amp_recent_from_cb_10g_t41";
  cs_status     stat   = CS_OK;
  cs_uint16     module_num  = es_num/4;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (CS_ERROR);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb == NULL) {
    CS_PRINT("Writing xcon ES CB, T41 dev-%d, ERROR: pdevcb is NULL\n", dev_id);
    return (CS_ERROR);
  }

  if(es_num > XCON_ELASTIC_STORE_7){CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": es number out of range.  s/b 0..7"); return CS_ERROR;}

  /* Retrieve the recenter type and parameters for this recenter and call its setup function. */ 
  /* Check this ES's side (module) to see if this should be a monolithic AMP recenter         */
  if (pdevcb->es_cb[module_num*4].recenter.type == TEN_XCON_ES_RECENTER_AMP_40G) {
    stat = ten_xcon_es_amplitude_recenter_40g_cb( dev_id,
                               pdevcb->es_cb[module_num*4].recenter.recovery | (module_num),
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.margin_lower ,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.margin_upper ,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.correct_lower,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.correct_upper,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.duration     ,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.sysclk_freq  , 
                               XCON_ES_UPDATE_CB_FALSE);
  }

  /* Check this ES's side (module) to see if this should be a monolithic FPA recenter         */
  else if (pdevcb->es_cb[module_num*4].recenter.type == TEN_XCON_ES_RECENTER_FPA_40G) {
    stat = ten_xcon_es_amplitude_recenter_with_fpa_40g_cb( dev_id,
                               pdevcb->es_cb[module_num*4].recenter.recovery | (module_num),
                               pdevcb->es_cb[module_num*4].recenter.parms.fpa.static_depth           ,
                               pdevcb->es_cb[module_num*4].recenter.parms.fpa.circuit_threshold_lower,
                               pdevcb->es_cb[module_num*4].recenter.parms.fpa.circuit_threshold_upper, 
                               XCON_ES_UPDATE_CB_FALSE);
  }

  /* Handle 10G recenter scenarios */
  else if (pdevcb->es_cb[es_num].recenter.type == TEN_XCON_ES_RECENTER_AMP_10G) {
    stat = ten_xcon_es_amplitude_recenter_10g_cb( dev_id,
                               pdevcb->es_cb[es_num].recenter.recovery | (es_num),
                               pdevcb->es_cb[es_num].recenter.parms.amp.margin_lower ,
                               pdevcb->es_cb[es_num].recenter.parms.amp.margin_upper ,
                               pdevcb->es_cb[es_num].recenter.parms.amp.correct_lower,
                               pdevcb->es_cb[es_num].recenter.parms.amp.correct_upper,
                               pdevcb->es_cb[es_num].recenter.parms.amp.duration     ,
                               pdevcb->es_cb[es_num].recenter.parms.amp.sysclk_freq  , 
                               XCON_ES_UPDATE_CB_FALSE);
  }
  else if (pdevcb->es_cb[es_num].recenter.type == TEN_XCON_ES_RECENTER_FPA_10G) {
    stat = ten_xcon_es_amplitude_recenter_with_fpa_10g_cb( dev_id,
                               pdevcb->es_cb[es_num].recenter.recovery | (es_num),
                               pdevcb->es_cb[es_num].recenter.parms.fpa.static_depth ,
                               pdevcb->es_cb[es_num].recenter.parms.fpa.circuit_threshold_lower,
                               pdevcb->es_cb[es_num].recenter.parms.fpa.circuit_threshold_upper, 
                               XCON_ES_UPDATE_CB_FALSE);
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s(ES %d), %s", func, es_num, "ES CB recenter type is not valid");
    return CS_ERROR;
  }

  return (stat);
}
/* Bugzilla 27270 End */






