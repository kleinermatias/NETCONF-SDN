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
 * ten_hl_config_misc.c
 *
 * API's for misc high level configuration functions
 *
 * $Id: ten_hl_config_misc.c,v 1.72 2013/05/07 19:20:39 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  CONFIG REMOVE SOFT RESETS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_remove_soft_resets(cs_uint16 mod_line,
                                cs_uint8 slice_line,
                                cs_uint16 mod_client,
                                cs_uint8 slice_client,
                                cs_uint16 client,
                                cs_uint16 aggr)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Remove soft resets from N10G, PP10G, ES, and SYNCDSYNC       */
/* depending on the traffic.  Assumes that the line and client  */
/* slice are the same for aggregation.                          */
/*                                                              */
/* The [slice_line] parameter is specified as:                  */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL.                                      */
/*                                                              */
/* The [slice_client] parameter is specified as:                */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL.                                      */
/*                                                              */
/* The [client] parameter is specified as:                      */
/*   TEN_TRAFFIC_TYPE_NONE = 0                                  */
/*   TEN_TRAFFIC_TYPE_OTU3 = 1                                  */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                 */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                 */
/*   TEN_TRAFFIC_TYPE_ODTU23 = 4                                */
/*   TEN_TRAFFIC_TYPE_OTU2 = 5                                  */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                 */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                 */
/*   TEN_TRAFFIC_TYPE_OC192 = 8                                 */
/*   TEN_TRAFFIC_TYPE_10GE_WAN = 9                              */
/*   TEN_TRAFFIC_TYPE_10GE_6_2 = 10                             */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11                             */
/*   TEN_TRAFFIC_TYPE_10GE_7_3 = 12                             */
/*   TEN_TRAFFIC_TYPE_10GFC = 13                                */
/*   TEN_TRAFFIC_TYPE_8GFC = 14                                 */
/*   TEN_TRAFFIC_TYPE_4GFC = 15                                 */
/*   TEN_TRAFFIC_TYPE_2GFC = 16                                 */
/*   TEN_TRAFFIC_TYPE_1GFC = 17                                 */
/*   TEN_TRAFFIC_TYPE_5GB_IB = 18                               */
/*   TEN_TRAFFIC_TYPE_OTU3_NOFEC = 19                           */
/*   TEN_TRAFFIC_TYPE_10GE = 20                                 */
/*   TEN_TRAFFIC_TYPE_40GELAN = 21                              */
/*   TEN_TRAFFIC_TYPE_OC768 = 22                                */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_CBR40G_50188149150 = 24                   */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_10GE_6_1 = 26                             */
/*   TEN_TRAFFIC_TYPE_10GE_7_2 = 27                             */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28                 */
/*   TEN_TRAFFIC_TYPE_OTU1E = 29                                */
/*   TEN_TRAFFIC_TYPE_10GE_RA = 30                              */
/*   TEN_TRAFFIC_TYPE_OC192_OTU2 = 31                           */
/*   TEN_TRAFFIC_TYPE_OC768_OTU3 = 32                           */
/*   TEN_TRAFFIC_TYPE_10GE_TC = 33                              */
/*   TEN_TRAFFIC_TYPE_10G_IB               = 39                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC             = 46                 */
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                 */
/*   TEN_TRAFFIC_TYPE_4GFC_RA              = 48                 */
/*   TEN_TRAFFIC_TYPE_2GFC_RA              = 49                 */
/*   TEN_TRAFFIC_TYPE_1GFC_RA              = 50                 */
/*   TEN_TRAFFIC_TYPE_8GFC_ENH             = 51                 */
/*   TEN_TRAFFIC_TYPE_4GFC_ENH             = 52                 */
/*   TEN_TRAFFIC_TYPE_2GFC_ENH             = 53                 */
/*   TEN_TRAFFIC_TYPE_1GFC_ENH             = 54                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_G709        = 57                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_RA          = 58                 */
/*   TEN_TRAFFIC_TYPE_2GISC                = 59                 */
/*   TEN_TRAFFIC_TYPE_1GE                  = 63                 */
/*   TEN_TRAFFIC_TYPE_FDR10_IB             = 64                 */
/*                                                              */
/* The [aggr] parameter is specified as:                        */
/*   1 = if this is aggregating into an ODTU23 and the other    */
/*       module's resets need to be removed also.               */
/*   0 = otherwise.                                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(mod_line);
  cs_status rtn = CS_OK;
  cs_uint8 actual_slice_line;
  cs_uint16 es_line;
  cs_uint16 es_client;
  cs_char8 *func = "ten_hl_config_remove_soft_resets";  /* __FUNCTION__ or __func__ not available for all compilers */
  
  CS_PRINT("%s()\n", func);
  CS_PRINT("    line  %s, %s\n", ten_module_strings[mod_line&1], ten_slice_strings[slice_line]);
  CS_PRINT("    client  %s, %s\n", ten_module_strings[mod_client&1], ten_slice_strings[slice_client]);
  CS_PRINT("    client=%s, aggr=%d\n", ten_hl_config_traffic_types_strings[client], aggr);
  
  if (aggr) {
    actual_slice_line = slice_client;
  } 
  else {
    actual_slice_line = slice_line;
  }

  /* Always remove soft resets to all N10G blocks in aggr mode */
  if ((client == TEN_TRAFFIC_TYPE_OTU2) ||
      (client == TEN_TRAFFIC_TYPE_OTU2E) ||
      /* Bugzilla 20308 Start */
      (client == TEN_TRAFFIC_TYPE_OTU1E) ||
       /* Bugzilla 20308 End */
      (client == TEN_TRAFFIC_TYPE_OTU1F) ||
      (client == TEN_TRAFFIC_TYPE_OC192) ||
      (client == TEN_TRAFFIC_TYPE_10GFC) ||
      (client == TEN_TRAFFIC_TYPE_10GFC_TC) ||  /* Bugzilla 24360 */
      (client == TEN_TRAFFIC_TYPE_10GFC_TC_G709) || /* Bug 31054 */
      (client == TEN_TRAFFIC_TYPE_10GFC_TC_RA) ||
      (client == TEN_TRAFFIC_TYPE_8GFC) ||
      (client == TEN_TRAFFIC_TYPE_4GFC) ||
      (client == TEN_TRAFFIC_TYPE_2GFC) ||
      (client == TEN_TRAFFIC_TYPE_2GISC) ||
      (client == TEN_TRAFFIC_TYPE_1GFC) ||
      (client == TEN_TRAFFIC_TYPE_8GFC_RA) ||
      (client == TEN_TRAFFIC_TYPE_4GFC_RA) ||
      (client == TEN_TRAFFIC_TYPE_2GFC_RA) ||
      (client == TEN_TRAFFIC_TYPE_1GFC_RA) ||
      (client == TEN_TRAFFIC_TYPE_8GFC_ENH) ||
      (client == TEN_TRAFFIC_TYPE_4GFC_ENH) ||
      (client == TEN_TRAFFIC_TYPE_2GFC_ENH) ||
      (client == TEN_TRAFFIC_TYPE_1GFC_ENH) ||
      (client == TEN_TRAFFIC_TYPE_10GE) ||
      (client == TEN_TRAFFIC_TYPE_10GE_6_1) ||
      (client == TEN_TRAFFIC_TYPE_10GE_6_2) ||
      (client == TEN_TRAFFIC_TYPE_10GE_7_1) ||
      /* Bugzilla 20308 Start */
      (client == TEN_TRAFFIC_TYPE_10GE_7_2) ||
      (client == TEN_TRAFFIC_TYPE_10GE_7_3) ||
      (client == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) || 
      /* Bugzilla 20308 End */
      (client == TEN_TRAFFIC_TYPE_10GE_GFPF) ||  /* Bugzilla 29991 */
      (client == TEN_TRAFFIC_TYPE_10GE_RA) ||    /* Bugzilla 22237 */
      (client == TEN_TRAFFIC_TYPE_10GE_TC) ||
      (client == TEN_TRAFFIC_TYPE_5GB_IB) ||
      (client == TEN_TRAFFIC_TYPE_10G_IB) ||
      (client == TEN_TRAFFIC_TYPE_1GE) || /* Bugzilla 38871 */
      (client == TEN_TRAFFIC_TYPE_FDR10_IB)) { /* Bugzilla 39242 */
    ten_n10g_set_global_resets(mod_client, slice_client, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL);
    ten_n10g_set_global_resets(mod_line, actual_slice_line, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL);
  }

  /*  Bug #18612 */
  /*  The PP10G and ES reset de-assertion sequence was changed to prevent ES lock-up */
  if ((client == TEN_TRAFFIC_TYPE_10GE) ||
      (client == TEN_TRAFFIC_TYPE_10GE_6_1) ||
      (client == TEN_TRAFFIC_TYPE_10GE_6_2) ||
      (client == TEN_TRAFFIC_TYPE_10GE_7_1) ||
      /* Bugzilla 20308 Start */
      (client == TEN_TRAFFIC_TYPE_10GE_7_2) ||
      (client == TEN_TRAFFIC_TYPE_10GE_7_3) ||
      (client == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) ||
      /* Bugzilla 20308 End */
      (client == TEN_TRAFFIC_TYPE_10GE_GFPF) || /* Bugzilla 29991 */
      (client == TEN_TRAFFIC_TYPE_10GFC) ||
      (client == TEN_TRAFFIC_TYPE_10GFC_TC) || /* Bugzilla 24360 */
      (client == TEN_TRAFFIC_TYPE_10GFC_TC_G709) ||  /* Bug 31054 */
      (client == TEN_TRAFFIC_TYPE_10GFC_TC_RA) ||
      (client == TEN_TRAFFIC_TYPE_8GFC) ||
      (client == TEN_TRAFFIC_TYPE_4GFC) ||
      (client == TEN_TRAFFIC_TYPE_2GFC) ||
      (client == TEN_TRAFFIC_TYPE_2GISC) ||
      (client == TEN_TRAFFIC_TYPE_1GFC) ||
      (client == TEN_TRAFFIC_TYPE_8GFC_RA) ||
      (client == TEN_TRAFFIC_TYPE_4GFC_RA) ||
      (client == TEN_TRAFFIC_TYPE_2GFC_RA) ||
      (client == TEN_TRAFFIC_TYPE_1GFC_RA) ||
      (client == TEN_TRAFFIC_TYPE_8GFC_ENH) ||
      (client == TEN_TRAFFIC_TYPE_4GFC_ENH) ||
      (client == TEN_TRAFFIC_TYPE_2GFC_ENH) ||
      (client == TEN_TRAFFIC_TYPE_1GFC_ENH) ||
      /* Bugzilla 22237 Start */
      (client == TEN_TRAFFIC_TYPE_10GE_RA) ||
      /* Bugzilla 22237 End */
      (client == TEN_TRAFFIC_TYPE_10GE_TC) ||
      (client == TEN_TRAFFIC_TYPE_5GB_IB) ||
      (client == TEN_TRAFFIC_TYPE_10G_IB) ||    
      /* Bugzilla #36420: Support OTU2E/1E/1F as a client for PP10G monitoring */
      (client == TEN_TRAFFIC_TYPE_OTU2E) ||
      (client == TEN_TRAFFIC_TYPE_OTU1E) ||
      (client == TEN_TRAFFIC_TYPE_OTU1F) ||
      (client == TEN_TRAFFIC_TYPE_1GE) || /* Bugzilla 38871 */
      (client == TEN_TRAFFIC_TYPE_FDR10_IB)) { /* Bugzilla 39242 */
    ten_hl_pp10g_tx_reset(mod_line, actual_slice_line, CS_RESET_DEASSERT);
    ten_hl_pp10g_tx_reset(mod_client, slice_client, CS_RESET_DEASSERT);
   
    ten_xcon_datapath_reset(dev_id, CS_RESET_DEASSERT);
    if (aggr) {
      ten_xcon_es_reset(dev_id, slice_client, CS_RESET_DEASSERT);
      ten_xcon_es_reset(dev_id, slice_client + 4, CS_RESET_DEASSERT);
    }
    else {
      es_line   = ((mod_line   & 1) * 4) + slice_line;
      es_client = ((mod_client & 1) * 4) + slice_client;
      ten_xcon_es_reset(dev_id, es_line, CS_RESET_DEASSERT);
      ten_xcon_es_reset(dev_id, es_client, CS_RESET_DEASSERT);
    }
    ten_hl_pp10g_rx_reset(mod_line, actual_slice_line, CS_RESET_DEASSERT);
    ten_hl_pp10g_rx_reset(mod_client, slice_client, CS_RESET_DEASSERT);
  }
  else {
    /* The es reset was de-asserted in the pp10g function, if pp10g was enabled */
    /* If pp10g is not enabled then de-assert es reset here                     */
    ten_xcon_datapath_reset(dev_id, CS_RESET_DEASSERT);
    if (aggr) {
      ten_xcon_es_reset(dev_id, slice_client, CS_RESET_DEASSERT);
      ten_xcon_es_reset(dev_id, slice_client + 4, CS_RESET_DEASSERT);
    }
    else {
      es_line   = ((mod_line   & 1) * 4) + slice_line;
      es_client = ((mod_client & 1) * 4) + slice_client;
      ten_xcon_es_reset(dev_id, es_line, CS_RESET_DEASSERT);
      ten_xcon_es_reset(dev_id, es_client, CS_RESET_DEASSERT);
    }
  }
  /* Bugzilla #19353, fix bus errors */
  #if 0
  /* End Bug #18612 */
  if (client != TEN_TRAFFIC_TYPE_NONE) {
    ten_hl_resets_block(mod_client, slice_client, CS_RESET_DEASSERT, TEN_HL_RESETS_BLOCK_SYNCDSYNC);
    ten_hl_resets_block(mod_line, actual_slice_line, CS_RESET_DEASSERT, TEN_HL_RESETS_BLOCK_SYNCDSYNC);
  }
  #endif
  ten_xcon_datapath_reset(dev_id, CS_RESET_DEASSERT);
  
  if ((client == TEN_TRAFFIC_TYPE_SERIAL_40GE) ||
      (client == TEN_TRAFFIC_TYPE_PARALLEL_40GE) || 
      (client == TEN_TRAFFIC_TYPE_TC_40GE) || 
      (client == TEN_TRAFFIC_TYPE_S64_66_40GE)) {
    if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(mod_line))) {
      ten_pp40g_pcs_tx_control_sreset_t41(mod_line, CS_RESET_DEASSERT);
      ten_pp40g_pcs_tx_control_sreset_t41(mod_client, CS_RESET_DEASSERT);
      
      ten_pp40g_mac_rx_control_sreset_t41(mod_line, CS_RESET_DEASSERT);
      ten_pp40g_rs_rx_control_sreset_t41(mod_line, CS_RESET_DEASSERT);
      ten_pp40g_pcs_rx_control_sreset_t41(mod_line, CS_RESET_DEASSERT);
      ten_pp40g_lif_rx_control_sreset_t41(mod_line, CS_RESET_DEASSERT);
      
      ten_pp40g_mac_rx_control_sreset_t41(mod_client, CS_RESET_DEASSERT);
      ten_pp40g_rs_rx_control_sreset_t41(mod_client, CS_RESET_DEASSERT);
      ten_pp40g_pcs_rx_control_sreset_t41(mod_client, CS_RESET_DEASSERT);
      ten_pp40g_lif_rx_control_sreset_t41(mod_client, CS_RESET_DEASSERT);
    }
  }  
  return (rtn);
}

/* Bugzilla 22514 Start */
/****************************************************************/
/* $rtn_hdr_start  CONFIG REMOVE MODULE SOFT RESETS             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_remove_module_soft_resets(cs_uint16 module_id,
                                                  cs_uint8 slice,
                                                  cs_uint16 line)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Line                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Remove soft resets from N10G, PP10G, ES, and SYNCDSYNC       */
/* depending on the traffic.                                    */
/*                                                              */
/* [module_id] specifies line's module ID                       */ 
/*   0xXX00 = Side A                                            */      
/*   0xXX01 = Side B                                            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL.                                      */
/*                                                              */
/* The [line] parameter is specified as:                        */
/*   TEN_TRAFFIC_TYPE_NONE = 0                                  */
/*   TEN_TRAFFIC_TYPE_OTU3 = 1                                  */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                 */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                 */
/*   TEN_TRAFFIC_TYPE_ODTU23 = 4                                */
/*   TEN_TRAFFIC_TYPE_OTU2 = 5                                  */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                 */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                 */
/*   TEN_TRAFFIC_TYPE_OC192 = 8                                 */
/*   TEN_TRAFFIC_TYPE_10GE_WAN = 9                              */
/*   TEN_TRAFFIC_TYPE_10GE_6_2 = 10                             */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11                             */
/*   TEN_TRAFFIC_TYPE_10GE_7_3 = 12                             */
/*   TEN_TRAFFIC_TYPE_10GFC = 13                                */
/*   TEN_TRAFFIC_TYPE_8GFC = 14                                 */
/*   TEN_TRAFFIC_TYPE_4GFC = 15                                 */
/*   TEN_TRAFFIC_TYPE_2GFC = 16                                 */
/*   TEN_TRAFFIC_TYPE_1GFC = 17                                 */
/*   TEN_TRAFFIC_TYPE_5GB_IB = 18                               */
/*   TEN_TRAFFIC_TYPE_OTU3_NOFEC = 19                           */
/*   TEN_TRAFFIC_TYPE_10GE = 20                                 */
/*   TEN_TRAFFIC_TYPE_40GELAN = 21                              */
/*   TEN_TRAFFIC_TYPE_OC768 = 22                                */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_CBR40G_50188149150 = 24                   */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_10GE_6_1 = 26                             */
/*   TEN_TRAFFIC_TYPE_10GE_7_2 = 27                             */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28                 */
/*   TEN_TRAFFIC_TYPE_OTU1E = 29                                */
/*   TEN_TRAFFIC_TYPE_10GE_RA = 30                              */
/*   TEN_TRAFFIC_TYPE_OC192_OTU2 = 31                           */
/*   TEN_TRAFFIC_TYPE_OC768_OTU3 = 32                           */
/*   TEN_TRAFFIC_TYPE_10GE_TC = 33                              */
/*   TEN_TRAFFIC_TYPE_10G_IB               = 39                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC             = 46                 */
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                 */
/*   TEN_TRAFFIC_TYPE_4GFC_RA              = 48                 */
/*   TEN_TRAFFIC_TYPE_2GFC_RA              = 49                 */
/*   TEN_TRAFFIC_TYPE_1GFC_RA              = 50                 */
/*   TEN_TRAFFIC_TYPE_8GFC_ENH             = 51                 */
/*   TEN_TRAFFIC_TYPE_4GFC_ENH             = 52                 */
/*   TEN_TRAFFIC_TYPE_2GFC_ENH             = 53                 */
/*   TEN_TRAFFIC_TYPE_1GFC_ENH             = 54                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF            = 56                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_G709        = 57                 */
/*   TEN_TRAFFIC_TYPE_2GISC                = 59                 */
/*   TEN_TRAFFIC_TYPE_1GE                  = 63                 */
/*   TEN_TRAFFIC_TYPE_FDR10_IB             = 64                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_status rtn = CS_OK;
/*  cs_uint8 actual_slice_line; */
  cs_uint16 es_line;
  
  CS_PRINT("ten_hl_config_remove_module_soft_resets: %s, Slice %d, %s\n",
           ten_module_strings[module_id & 1],
           slice,
           ten_hl_config_traffic_types_strings[line]);
  
  
  es_line = ((module_id  & 1) * 4) + slice;
  
  /* Always remove soft resets to all N10G blocks in aggr mode */
  if ((line == TEN_TRAFFIC_TYPE_OTU2) ||
      (line == TEN_TRAFFIC_TYPE_OTU2E) ||
      (line == TEN_TRAFFIC_TYPE_OTU1E) ||
      (line == TEN_TRAFFIC_TYPE_OTU1F) ||
      (line == TEN_TRAFFIC_TYPE_OC192) ||
      /* Bugzilla 22970 Start */
      (line == TEN_TRAFFIC_TYPE_OC192_OTU2) ||
      /* Bugzilla 22970 End */
      (line == TEN_TRAFFIC_TYPE_10GFC) ||
      (line == TEN_TRAFFIC_TYPE_10GFC_TC) ||  /* Bugzilla 24360 */
      (line == TEN_TRAFFIC_TYPE_10GFC_TC_G709) || /* Bug 31054 */
      (line == TEN_TRAFFIC_TYPE_8GFC) ||
      (line == TEN_TRAFFIC_TYPE_4GFC) ||
      (line == TEN_TRAFFIC_TYPE_2GFC) ||
      (line == TEN_TRAFFIC_TYPE_2GISC) ||
      (line == TEN_TRAFFIC_TYPE_1GFC) ||
      (line == TEN_TRAFFIC_TYPE_10GE) ||
      (line == TEN_TRAFFIC_TYPE_8GFC_RA) ||
      (line == TEN_TRAFFIC_TYPE_4GFC_RA) ||
      (line == TEN_TRAFFIC_TYPE_2GFC_RA) ||
      (line == TEN_TRAFFIC_TYPE_1GFC_RA) ||
      (line == TEN_TRAFFIC_TYPE_8GFC_ENH) ||
      (line == TEN_TRAFFIC_TYPE_4GFC_ENH) ||
      (line == TEN_TRAFFIC_TYPE_2GFC_ENH) ||
      (line == TEN_TRAFFIC_TYPE_1GFC_ENH) ||
      (line == TEN_TRAFFIC_TYPE_10GE_6_1) ||
      (line == TEN_TRAFFIC_TYPE_10GE_6_2) ||
      (line == TEN_TRAFFIC_TYPE_10GE_7_1) ||
      (line == TEN_TRAFFIC_TYPE_10GE_7_2) ||
      (line == TEN_TRAFFIC_TYPE_10GE_7_3) ||
      (line == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) || 
      (line == TEN_TRAFFIC_TYPE_10GE_GFPF) ||   /* Bugzilla 29991 */
      (line == TEN_TRAFFIC_TYPE_10GE_RA) ||
      (line == TEN_TRAFFIC_TYPE_10GE_TC) ||
      (line == TEN_TRAFFIC_TYPE_5GB_IB) ||
      (line == TEN_TRAFFIC_TYPE_10G_IB) ||
      (line == TEN_TRAFFIC_TYPE_1GE) ||  /* Bugzilla 38871 */
      (line == TEN_TRAFFIC_TYPE_FDR10_IB)) { /* Bugzilla 39242 */
    ten_n10g_set_global_resets(module_id, slice, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL);
  }

  /*  The PP10G and ES reset de-assertion sequence was changed to prevent ES lock-up */
  if ((line == TEN_TRAFFIC_TYPE_10GE) ||
      (line == TEN_TRAFFIC_TYPE_10GE_6_1) ||
      (line == TEN_TRAFFIC_TYPE_10GE_6_2) ||
      (line == TEN_TRAFFIC_TYPE_10GE_7_1) ||
      (line == TEN_TRAFFIC_TYPE_10GE_7_2) ||
      (line == TEN_TRAFFIC_TYPE_10GE_7_3) ||
      (line == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) ||
      (line == TEN_TRAFFIC_TYPE_10GE_GFPF) ||       /* Bugzilla 29991 */
      (line == TEN_TRAFFIC_TYPE_10GFC) ||
      (line == TEN_TRAFFIC_TYPE_10GFC_TC) ||  /* Bugzilla 24360 */
      (line == TEN_TRAFFIC_TYPE_10GFC_TC_G709) || /* Bug 31054 */
      (line == TEN_TRAFFIC_TYPE_8GFC) ||
      (line == TEN_TRAFFIC_TYPE_4GFC) ||
      (line == TEN_TRAFFIC_TYPE_2GFC) ||
      (line == TEN_TRAFFIC_TYPE_2GISC) ||
      (line == TEN_TRAFFIC_TYPE_1GFC) ||
      (line == TEN_TRAFFIC_TYPE_8GFC_RA) ||
      (line == TEN_TRAFFIC_TYPE_4GFC_RA) ||
      (line == TEN_TRAFFIC_TYPE_2GFC_RA) ||
      (line == TEN_TRAFFIC_TYPE_1GFC_RA) ||
      (line == TEN_TRAFFIC_TYPE_8GFC_ENH) ||
      (line == TEN_TRAFFIC_TYPE_4GFC_ENH) ||
      (line == TEN_TRAFFIC_TYPE_2GFC_ENH) ||
      (line == TEN_TRAFFIC_TYPE_1GFC_ENH) ||
      (line == TEN_TRAFFIC_TYPE_10GE_RA) ||
      (line == TEN_TRAFFIC_TYPE_10GE_TC) ||
      (line == TEN_TRAFFIC_TYPE_5GB_IB) ||
      (line == TEN_TRAFFIC_TYPE_10G_IB) ||
      (line == TEN_TRAFFIC_TYPE_1GE) ||  /* Bugzilla 38871 */
      (line == TEN_TRAFFIC_TYPE_FDR10_IB)) { /* Bugzilla 39242 */
    ten_hl_pp10g_tx_reset(module_id, slice, CS_RESET_DEASSERT);
   
    ten_xcon_datapath_reset(dev_id, CS_RESET_DEASSERT);
    ten_xcon_es_reset(dev_id, es_line, CS_RESET_DEASSERT);

    ten_hl_pp10g_rx_reset(module_id, slice, CS_RESET_DEASSERT);
  }
  else {
    /* The es reset was de-asserted in the pp10g function, if pp10g was enabled */
    /* If pp10g is not enabled then de-assert es reset here                     */
    ten_xcon_datapath_reset(dev_id, CS_RESET_DEASSERT);

    ten_xcon_es_reset(dev_id, es_line, CS_RESET_DEASSERT);
  }

  #if 0
  if (line != TEN_TRAFFIC_TYPE_NONE) {
    ten_hl_resets_block(module_id, slice, CS_RESET_DEASSERT, TEN_HL_RESETS_BLOCK_SYNCDSYNC);
  }
  #endif
  ten_xcon_datapath_reset(dev_id, CS_RESET_DEASSERT);
  
  return (rtn);
}
/* Bugzilla 22514 End */

/****************************************************************/
/* $rtn_hdr_start  CONFIG PERFORM RECOVERY SEQUENCE             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
void ten_hl_config_perform_recovery_sequence(ten_irq_handler_data_t handler_data)
/* INPUTS     : o Handler Data                                  */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Toggle soft resets from N10G, PP10G, and ES.                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_uint16 es;
  cs_uint8 slice;
  cs_uint16 module_id;
  cs_boolean n10g_active;
  cs_boolean pp10g_active;
  volatile cs_reg *tmp_addr;

  dev_id = handler_data.dev_id;
  /* convert slice0-7 to module_id and slice0-3 */ 
  /* Bugzilla #34183, ten_hl_config_perform_recovery_sequence support for multiple T41s */
  module_id = (dev_id<<8) | ((handler_data.slice < 4) ? TEN_MODULE_A : TEN_MODULE_B);
  slice = handler_data.slice % 4;
  es = handler_data.slice;

  /* Turn prints on (temporarily)*/
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
  CS_PRINT("ten_hl_config_perform_recovery_sequence: dev_id=%d, mod_id=0x%04X, sl=%d\n",
           dev_id, module_id, slice);

  TEN_DEV_COMMON_VALIDATE_INTERNAL (dev_id, &pDev);

  /* Determine if n10g is active */
  n10g_active = ten_mpif_n10g_rx_is_active(module_id, slice);
  /* Determine if pp10g is active */
  pp10g_active = ten_mpif_pp10g_rx_is_active(module_id, slice);

  /* Only run the recovery sequence if the n10g LOS status has gone away (circuit mode)
     or the pp10g has regained PCS sync (packet mode) */
/*  if ((n10g_active) && 
      ten_n10g_get_global_losf_status(module_id, slice)) {
      CS_PRINT("Framer is LOS - do not recover.\n");
      return; 
  } */
  if ((n10g_active) && 
      ten_n10g_get_otu_framer_status(module_id, slice, TEN_NX0G_OTNR_OFSTAT_SLOF)) {
      CS_PRINT("Framer is LOF - do not recover.\n");
  }
  if ((pp10g_active) && 
      (ten_pp10g_pcs_rx_status(module_id, slice, TEN_PP10G_PCS_RX_SYNCDETS) == 0)) {
      CS_PRINT("PCS is out of sync - do not recover.\n");
  }

  /* Optional – Tx N10G assert reset – depends on the configuration */
  if (n10g_active) { /* n10g_active */
    /* N10G TX */
    rtn |= ten_n10g_set_global_resets(module_id, slice, CS_RESET_ASSERT,
                                      TEN_N10G_GLOBAL_RESETS_RSTSYS  |
                                      TEN_N10G_GLOBAL_RESETS_RSTTX   |
                                      TEN_N10G_GLOBAL_RESETS_RSTTXNG |
                                      TEN_N10G_GLOBAL_RESETS_RSTOT   |
                                      TEN_N10G_GLOBAL_RESETS_RSTCT);
  }
  
  if (pp10g_active) { /* pp10g_active */
    rtn |= ten_hl_pp10g_tx_reset(module_id, slice, CS_RESET_ASSERT);
  }
   
  if (1) {
    rtn |= ten_xcon_es_reset(dev_id, es, CS_RESET_ASSERT);
  }

  if (pp10g_active) { /* pp10g_active */
    rtn |= ten_hl_pp10g_rx_reset(module_id, slice, CS_RESET_ASSERT);
  }
    
  if (n10g_active) { /* n10g_active */
    /* N10G RX */ 
    rtn |= ten_n10g_set_global_resets(module_id, slice, CS_RESET_ASSERT,
                                      TEN_N10G_GLOBAL_RESETS_RSTRX | 
                                      TEN_N10G_GLOBAL_RESETS_RSTOR |
                                      TEN_N10G_GLOBAL_RESETS_RSTCR | 
                                      TEN_N10G_GLOBAL_RESETS_RSTSYS);
  }

  /* Bugzilla #28471, minimum delay */
  TEN_MDELAY(6);
  
  /* Optional – Tx N10G de-assert reset – depends on the configuration */
  if (n10g_active) { /* n10g_active) */
    /* N10G TX */
    rtn |= ten_n10g_set_global_resets(module_id, slice, CS_RESET_DEASSERT,
                                      TEN_N10G_GLOBAL_RESETS_RSTSYS  |
                                      TEN_N10G_GLOBAL_RESETS_RSTTX   |
                                      TEN_N10G_GLOBAL_RESETS_RSTTXNG |
                                      TEN_N10G_GLOBAL_RESETS_RSTOT   |
                                      TEN_N10G_GLOBAL_RESETS_RSTCT);
  }
  
  /* Optional – Insert Tx HSIF EX Resync here */
  /* TODO */
  
  /* Insert Rx HSIF ES Resync here */
  /* TODO */
  
  if (pp10g_active) { /* pp10g_active */
    rtn |= ten_hl_pp10g_tx_reset(module_id, slice, CS_RESET_DEASSERT);
  }
  
  if (1) {
    rtn |= ten_xcon_es_reset(dev_id, es, CS_RESET_DEASSERT);
  }

  /* check this: ten_xcon_select_es_packet_centering */
  /* TODO */


  if (pp10g_active) { /* pp10g_active */
    rtn |= ten_hl_pp10g_rx_reset(module_id, slice, CS_RESET_DEASSERT);
  }
  
  if (n10g_active) { /* n10g_active) */
    /* RX N10G */
    rtn |= ten_n10g_set_global_resets(module_id, slice, CS_RESET_DEASSERT,
                                      TEN_N10G_GLOBAL_RESETS_RSTRX | 
                                      TEN_N10G_GLOBAL_RESETS_RSTOR |
                                      TEN_N10G_GLOBAL_RESETS_RSTCR | 
                                      TEN_N10G_GLOBAL_RESETS_RSTSYS);
  }

  /* Insert Xcon Force Recenter here */
  if (pp10g_active == 0) {
     rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_FORCE_CENTER, CS_ENABLE);
     TEN_MDELAY(6);
     rtn |= ten_xcon_select_es_packet_centering(dev_id, es, XCON_FORCE_CENTER, CS_DISABLE);
  }

  /* Bugzilla #28471, minimum delay */
  TEN_MDELAY(6);
  
  /* Finally, clear TEN_N10G_GBLR_INTR interrupts for dLOS interrupting */
  if (n10g_active) {
    tmp_addr  = (volatile cs_reg *)&(pDev->n10g.gblr_INTR);
    tmp_addr += ((module_id & 0x0001) * 4 + slice) * TEN_N10G_STRIDE;
    TEN_REG_WRITE(tmp_addr, 0xFFFF);
  }
  
  /* and the TEN_N10G_OTNR_INTR interrupts for LOF interrupting*/
  if (n10g_active) {
    tmp_addr  = (volatile cs_reg *)&(pDev->n10g.otnr_INTR);
    tmp_addr += ((module_id & 0x0001) * 4 + slice) * TEN_N10G_STRIDE;
    TEN_REG_WRITE(tmp_addr, 0xFFFF);
  }
  
  /* and the TEN_PP10G_PCS_RX_RXINT interrupts for PCS interrupting*/
  if (pp10g_active) {
    tmp_addr = (volatile cs_reg *)&(pDev->pp10g.pp10g_pcs.RXINT);
    tmp_addr += ((module_id & 0x0001) * 4 + slice) * TEN_PP10G_STRIDE;
    TEN_REG_WRITE(tmp_addr, 0xFFFF);
  }

  /* Turn prints back off */
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
}

/* Bug 28921 start */
/****************************************************************/
/* $rtn_hdr_start  CONFIG PERFORM CUPLL RECOVERY SEQUENCE       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
void ten_hl_config_perform_cupll_recovery_sequence(ten_irq_handler_data_t handler_data)
/* INPUTS     : o Handler Data                                  */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Toggle soft resets for CUPLL.                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint8 sl;
  cs_uint16 ireg_data;
  cs_uint16 ereg_data;
  cs_uint16 sreg_data;
  cs_uint16 entering_holdover;
  cs_uint16 exiting_holdover;
  cs_uint16 mask;
  T41_t *pDev = NULL;
  

  dev_id            = handler_data.dev_id;
  ireg_data         = handler_data.ireg_data;
  ereg_data         = handler_data.ereg_data;
  sreg_data         = handler_data.sreg_data;
  entering_holdover = ereg_data & ireg_data &  sreg_data;
  exiting_holdover  = ereg_data & ireg_data & ~sreg_data;

  /* Turn prints on (temporarily)*/
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
  CS_PRINT("ten_hl_config_perform_cupll_recovery_sequence: dev_id=%d\n", dev_id);
  /* CS_PRINT("  ireg_data:         0x%04X\n", ireg_data);
  CS_PRINT("  ereg_data:         0x%04X\n", ereg_data);
  CS_PRINT("  sreg_data:         0x%04X\n", sreg_data);
  CS_PRINT("  entering_holdover: 0x%04X\n", entering_holdover);
  CS_PRINT("  exiting_holdover:  0x%04X\n", exiting_holdover); */

  TEN_DEV_COMMON_VALIDATE_INTERNAL (dev_id, &pDev);

  /* For each of the four reverting interrupts, bits 7..4, reset the CUPLL */
  /* if enabled, interrupting, & exiting the holdover state (status=0).    */
  for(sl=TEN_SLICE0;sl<=TEN_SLICE3;sl++) {
    mask = 1<<(sl+4);
    if ((entering_holdover & mask) > 0) {
      CS_PRINT("CUPLL %d is entering holdover - do not recover.\n", sl);
    }
    else if ((exiting_holdover & mask) > 0) {
      CS_PRINT("CUPLL %d is exiting holdover - toggle reset.\n", sl);
      /* The CS_RESET_TOGGLE method results in a 20ms reset pulse. This      */
      /* method should work on any architecture at the expense of delay      */
      /* (20ms).Resetting the CUPLL can be done faster but the pulse must    */
      /* be at least 200ns.                                                  */
      ten_cupll_reset_t41(TEN_MODULE_B, sl, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE);
    }
  }

  /* Turn prints back off */
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
}

/* Bug 28921 start */ 

/*###############################################################################*/
/*#                                                                              */
/*# Client traffic provisioning functions                                        */
/*#                                                                              */
/*###############################################################################*/

/****************************************************************/
/* $rtn_hdr_start  CONFIG AGGREGATION IDLE                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_aggregation_idle(cs_uint16 mod_line,
                                         cs_uint8 slice_line,
                                         cs_uint16 mod_client,
                                         cs_uint8 slice_client)
/* INPUTS     : o Module Id Line                                */
/*              o Slice Line                                    */
/*              o Module Id Client                              */
/*              o Slice Client                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Config Aggregation Idle.                                     */
/*                                                              */
/* The [slice_line] parameter is specified as:                  */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mod_client] parameter is specified as:                  */
/*   Module Id of the client                                    */
/*                                                              */
/* The [slice_client] parameter is specified as:                */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL.                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* cs_uint16 n40g_jc_en = 0; */
  ten_dev_cb_t *pdevcb;
  cs_uint32 hysteresis;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(mod_line);
  cs_char8 *func = "ten_hl_config_aggregation_idle";  /* __FUNCTION__ or __func__ not available for all compilers */


  TEN_MOD_COMMON_VALIDATE (mod_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE (mod_client, pDev, CS_ERROR);

  CS_PRINT("%s()\n", func);
  if (slice_line < TEN_MAX_SLICES) {
    CS_PRINT("    line   %s, %s\n", ten_module_strings[mod_line&1], ten_slice_strings[slice_line]);
  }
  else if(slice_line == TEN_SLICE_ALL) {
    CS_PRINT("    line   %s, SLICE_ALL\n", ten_module_strings[mod_line&1]);
  } else {
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_line %d out of range.  s/b 0..3. 255", func, slice_line);
    return (CS_ERROR);
  }
  if (slice_client < TEN_MAX_SLICES) {
    CS_PRINT("    client %s, %s\n", ten_module_strings[mod_client&1], ten_slice_strings[slice_client]);
  }
  else if(slice_client == TEN_SLICE_ALL) {
    CS_PRINT("    client %s, SLICE_ALL\n", ten_module_strings[mod_client&1]);
  } else {
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_client %d out of range.  s/b 0..3. 255", func, slice_client);
    return (CS_ERROR);
  }

  /* Bugzilla #30991:  Corrections needed in null config autogen scripts */
  if (ten_hl_config_fec_t41(mod_client, slice_client, TEN_SLICE_10G, TEN_FEC_MODE_DEALLOCATE) == CS_ERROR) {
    CS_PRINT("10G FEC Provisioning failed on module!\n");
    return (CS_ERROR);
  }
        
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  /* Bugzilla #25663, use module_num instead of module_id for mpif APIs */
  /* Soft reset on ES, Hard reset on PP10G and disable PP10G and N10G clock for 10G channel $slice_b */
  rtn |= ten_xcon_es_reset(dev_id, (mod_client & 1) * 4 + slice_client, CS_RESET_ASSERT);
  rtn |= ten_mpif_global_reset_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_client), slice_client, CS_TX_AND_RX, CS_RESET_ASSERT);
  rtn |= ten_mpif_global_reset_pp10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_client), slice_client, CS_TX_AND_RX, CS_RESET_ASSERT);
  rtn |= ten_mpif_global_clock_disable_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_client), slice_client, CS_TX_AND_RX, CS_DISABLE);
  rtn |= ten_mpif_global_clock_disable_pp10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_client), slice_client, CS_TX_AND_RX, CS_DISABLE);
  rtn |= ten_mpif_global_clock_disable_n40g_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_client), slice_client, 
                                                 TEN_MPIF_N40G_DATAPATH, CS_TX_AND_RX, CS_ENABLE);

  /* Soft reset ES, Hard reset on PP10G for 10G channel $slice_a */
  /* config_n10g(mod_line, slice_line, TEN_N10G_RX_OXU3_ODU2, TEN_N10G_TX_ODU2_OXU3, $dyn_repro); */
  rtn |= ten_xcon_es_reset(dev_id, (mod_line & 1) * 4 + slice_line, CS_RESET_ASSERT);
  rtn |= ten_mpif_global_reset_pp10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_line), slice_line, CS_TX_AND_RX, CS_RESET_ASSERT);
  rtn |= ten_mpif_global_clock_disable_pp10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_line), slice_line, CS_TX_AND_RX, CS_DISABLE);
  rtn |= ten_mpif_global_clock_disable_n40g_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_line), slice_line, TEN_MPIF_N40G_DATAPATH, 
                                                 CS_TX_AND_RX, CS_ENABLE);

  /* Bugzilla 31356, clear XFI bits in MR software instead of here */

  /* Configure the line-side N10G TX */
  /* The N10G TX must be provisioned so that N40G can determine */
  /* how to multiplex the four ODTU23s together */
  rtn |= ten_mpif_global_reset_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_line), slice_line, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* OTN_OFF=0, OBY=0, SBY=1, KPGBY=1 */
  rtn |= ten_n10g_set_gblt_bypasses(mod_line, slice_line, 0, 0, 1, 1);

  /* FASIE */
  rtn |= ten_n10g_otnt_set_fasie(mod_line, slice_line, 1);

  /* OTNT WRPCFG3 */
  rtn |= ten_n10g_otnt_set_g43md(mod_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_c15res_en(mod_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_wrmd(mod_line, slice_line, 1);

  /* OTNT WRPCFG4 - turn off justification */
  rtn |= ten_n10g_set_otnt_wrpcfg4(mod_line, slice_line, 0, 0, 0, 0, 0);
  rtn |= ten_n10g_otnt_set_wrpcfg5(mod_line, slice_line, 0);

  /* Config KPG - PATSEL */  /* Bugzilla #33766, fix warnings, use cs_ctl_t enums */
  rtn |= ten_n10g_config_kpg(mod_line, slice_line, CS_DISABLE, CS_DISABLE, 2, 0, 0);

  /* POSTSCR, PRESCR */
  /* #   ten_n10g_otnt_scrambling(mod_line, slice_line, 1, 0); */
  rtn |= ten_n10g_otnt_scrambling(mod_line, slice_line, 0, 0);
  /* #   ten_n10g_otnr_descrambling(mod_line, slice_line, 0, 1); */
  rtn |= ten_n10g_otnr_descrambling(mod_line, slice_line, 0, 0);

  rtn |= ten_n10g_set_global_resets(mod_line, slice_line, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL);

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci(mod_line, slice_line, CS_ENABLE);
  #endif
  
  /* Set N40G determistic justification    */
  /* Turn off jc enable in ODTU23 and ODU2 */

  /* Bugzilla 23948 Start - These functions are tributary based */
  /* rtn |= ten_n40g_otnt4x_set_wrp0dh1(mod_line, 0xFF);
  rtn |= ten_n40g_otnt4x_set_wrp0dh0(mod_line, 0x03); */

  /* Bug 23864 Start */
  if (pdevcb) {
    hysteresis = pdevcb->syncdsync_cb.hysteresis;
    /* Hysteresis value for DT Just */
    if      ( slice_line == 0 ) {
      rtn |= ten_n40g_otnt4x_set_wrp3dh1(mod_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp3dh0(mod_line, (cs_uint16) (hysteresis & 0xFFFF));
  }
    else if ( slice_line == 1 ) {
      rtn |= ten_n40g_otnt4x_set_wrp2dh1(mod_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp2dh0(mod_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
    else if ( slice_line == 2 ) {
      rtn |= ten_n40g_otnt4x_set_wrp1dh1(mod_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp1dh0(mod_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
    else if ( slice_line == 3 ) {
      rtn |= ten_n40g_otnt4x_set_wrp0dh1(mod_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp0dh0(mod_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
  }
  else {
    rtn = CS_ERROR;
  }
  /* Bug 23864 End  */

  /* Bug 23864 Start */
  /* n40g jc_plus is only for monolithic, should be 0 for aggregation */
  /* rtn |= ten_n40g_otnt4x_set_wrpcfg4(mod_line, 1, n40g_jc_en); */
  /* Bug 23864 End */

  rtn |= ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(mod_line, slice_line, 1);

  /* Bugzilla 23948 End */

  rtn |= ten_n10g_set_otnt_wrpcfg4(mod_line, slice_line, 0, 0, 1, 0, 0);

  /* Bug #36717: Stats take longer to read in OTU2 mode after a dynamic reconfig from OTU2E */
  rtn |= ten_pp10g_misc_reset(mod_line, slice_line, CS_RESET_ASSERT); 
  rtn |= ten_pp10g_misc_reset(mod_client, slice_client, CS_RESET_ASSERT); 
  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIG IDLE                                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_idle(cs_uint16 mod_line,
                             cs_uint8 slice_line,
                             cs_uint16 mod_client,
                             cs_uint8 slice_client,
                             cs_uint16 dyn_repro)
/* INPUTS     : o Module Id Line                                */
/*              o Slice Line                                    */
/*              o Module Id Client                              */
/*              o Slice Client                                  */
/*              o Dynamic Reprovision                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Config Idle.                                                 */
/*                                                              */
/* The [slice_line] parameter is specified as:                  */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mod_client] parameter is specified as:                  */
/*   Module Id of the client                                    */
/*                                                              */
/* The [slice_client] parameter is specified as:                */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL.                                      */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/*             reprovisioning:                                  */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_config_idle";  /* __FUNCTION__ or __func__ not available for all compilers */
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(mod_line);

  TEN_MOD_COMMON_VALIDATE (mod_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE (mod_client, pDev, CS_ERROR);

  if (slice_line < TEN_MAX_SLICES) {
    CS_PRINT("    line   %s, %s\n", ten_module_strings[mod_line&1], ten_slice_strings[slice_line]);
  }
  else if(slice_line == TEN_SLICE_ALL) {
    CS_PRINT("    line   %s, SLICE_ALL\n", ten_module_strings[mod_line&1]);
  } else {
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_line %d out of range.  s/b 0..3. 255", func, slice_line);
    return (CS_ERROR);
  }
  if (slice_client < TEN_MAX_SLICES) {
    CS_PRINT("    client %s, %s\n", ten_module_strings[mod_client&1], ten_slice_strings[slice_client]);
  }
  else if(slice_client == TEN_SLICE_ALL) {
    CS_PRINT("    client %s, SLICE_ALL\n", ten_module_strings[mod_client&1]);
  } else {
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_client %d out of range.  s/b 0..3. 255", func, slice_client);
    return (CS_ERROR);
  }
  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }
  CS_PRINT("    %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  
  /* Bugzilla #30991:  Corrections needed in null config autogen scripts */
  /* De-allocate any FECs */
  /* This must be done before ten_hl_config_idle otherwise there will be n10g bus errors */
  if (ten_hl_config_fec_t41(mod_client, slice_client, TEN_SLICE_10G, TEN_FEC_MODE_DEALLOCATE) == CS_ERROR) {
    CS_PRINT("10G FEC Client Provisioning failed!\n");
    return (CS_ERROR);
  }
  
  if (dyn_repro == TEN_REPRO_LINE_AND_CLIENT) {
    if (ten_hl_config_fec_t41(mod_line, slice_line, TEN_SLICE_10G, TEN_FEC_MODE_DEALLOCATE) == CS_ERROR) {
      CS_PRINT("10G FEC Line Provisioning failed!\n");
      return (CS_ERROR);
    }
  }
  
  rtn |= ten_xcon_es_reset(dev_id, (mod_client & 1) * 4 + slice_client, CS_RESET_ASSERT);

  /* Bugzilla #25663, use module_num instead of module_id for mpif APIs */
  rtn |= ten_mpif_global_reset_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_client), slice_client, CS_TX_AND_RX, CS_RESET_ASSERT);
  rtn |= ten_mpif_global_reset_pp10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_client), slice_client, CS_TX_AND_RX, CS_RESET_ASSERT);

  rtn |= ten_mpif_global_clock_disable_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_client), slice_client, CS_TX_AND_RX, CS_DISABLE);
  rtn |= ten_mpif_global_clock_disable_pp10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_client), slice_client, CS_TX_AND_RX, CS_DISABLE);

  rtn |= ten_mpif_global_clock_disable_n40g_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_client), slice_client,
                                          TEN_MPIF_N40G_DATAPATH, CS_TX_AND_RX, CS_ENABLE);

  rtn |= ten_xcon_es_reset(dev_id, (mod_line & 1) * 4 + slice_line, CS_RESET_ASSERT);

  rtn |= ten_mpif_global_reset_pp10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_line), slice_line, CS_TX_AND_RX, CS_RESET_ASSERT);
  rtn |= ten_mpif_global_clock_disable_pp10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_line), slice_line, CS_TX_AND_RX, CS_DISABLE);
  rtn |= ten_mpif_global_clock_disable_n40g_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_line), slice_line,
                                          TEN_MPIF_N40G_DATAPATH, CS_TX_AND_RX, CS_ENABLE);

  /* Bugzilla 31356, clear XFI bits in MR software instead of here */

  /* If the line is being de-provisioned too, then put its */
  /* n10g and the syncdsync blocks into reset              */
  if (dyn_repro == TEN_REPRO_LINE_AND_CLIENT) {
    rtn |= ten_mpif_global_reset_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_line), slice_line, CS_TX_AND_RX, CS_RESET_ASSERT);
    rtn |= ten_hl_resets_block(mod_client, slice_client, CS_RESET_ASSERT, TEN_HL_RESETS_BLOCK_SYNCDSYNC);
    rtn |= ten_hl_resets_block(mod_line, slice_line, CS_RESET_ASSERT, TEN_HL_RESETS_BLOCK_SYNCDSYNC);
    
    /* Bugzilla 31356, clear XFI bits in MR software instead of here */
  }
  else {
    /* Configure the line-side N10G TX */
    rtn |= ten_mpif_global_reset_n10g(dev_id, TEN_MOD_ID_TO_MOD_NUM(mod_line), slice_line, CS_TX_AND_RX, CS_RESET_DEASSERT);

    /* OTN_OFF=0, OBY=0, SBY=1, KPGBY=1 */
    rtn |= ten_n10g_set_gblt_bypasses(mod_line, slice_line, 0, 0, 1, 1);

    /* FASIE */
    rtn |= ten_n10g_otnt_set_fasie(mod_line, slice_line, 1);

    /* OTNT WRPCFG3 */
    rtn |= ten_n10g_otnt_set_g43md(mod_line, slice_line, 0);
    rtn |= ten_n10g_otnt_set_c15res_en(mod_line, slice_line, 0);
    rtn |= ten_n10g_otnt_set_wrmd(mod_line, slice_line, 1);

    /* OTNT WRPCFG4 - turn off justification */
    /* #     ten_n10g_set_otnt_wrpcfg4(mod_line, slice_line, 0, 0, 0, 0, 0); */
    rtn |= ten_n10g_otnt_set_wrpcfg5(mod_line, slice_line, 0);

    /* config KPG - PATSEL */  /* Bugzilla #33766, fix warnings, use cs_ctl_t enums */
    rtn |= ten_n10g_config_kpg(mod_line, slice_line, CS_DISABLE, CS_DISABLE, 2, 0, 0);

    /* POSTSCR, PRESCR */
    rtn |= ten_n10g_otnt_scrambling(mod_line, slice_line, 1, 0);
    /* #     ten_n10g_otnt_scrambling(mod_line, slice_line, 0, 0); */
    rtn |= ten_n10g_otnr_descrambling(mod_line, slice_line, 0, 1);
    /* #     ten_n10g_otnr_descrambling(mod_line, slice_line, 0, 0); */

    rtn |= ten_n10g_set_global_resets(mod_line, slice_line, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL);
    
    /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
    #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
    rtn |= ten_hl_ohpp_control_oduk_oci(mod_line, slice_line, CS_ENABLE);
    #endif
  }
  
  /* Bug #36717: Stats take longer to read in OTU2 mode after a dynamic reconfig from OTU2E */
  rtn |= ten_pp10g_misc_reset(mod_line, slice_line, CS_RESET_ASSERT); 
  rtn |= ten_pp10g_misc_reset(mod_client, slice_client, CS_RESET_ASSERT); 
  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OF PBERT                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_pbert(cs_uint16 module_id,
                              cs_uint8  slice,
                              cs_uint16 profile,
                              cs_uint16 min_len,
                              cs_uint16 max_len,
                              cs_uint16 ifg)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Profile Selection                             */
/*              o Minimum Octets Per Unit                       */
/*              o Maximum Octets Per Unit                       */
/*              o Inter Frame Gap                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Write PBERT configuration registers fot traffic specified    */
/* by *profile*.                                                */
/*                                                              */
/* The [module_id] parameter specifies module ID                */ 
/*                                                              */
/* The [slice] parameter specifies slice:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [profile] parameter is specified as:                     */
/*   0 = XCON_PBERT_PROFILE_ETH_0                               */
/*       Ethernet : Transport of MAC frames (DA/SA/../FCS)      */
/*   1 = XCON_PBERT_PROFILE_ETH_1                               */
/*       Ethernet : Transport of MAC frames (DA/SA/../FCS) and  */
/*                  Ordered Sets                                */
/*   2 = XCON_PBERT_PROFILE_ETH_2                               */
/*       Ethernet : Transport of entire MAC frames              */
/*                  (Preamble/SFD/DA/SA/../FCS) and Ordered Sets*/
/*   3 = XCON_PBERT_PROFILE_ETH_3                               */
/*       Ethernet : Transparent transport via the IEEE          */
/*                  Std 802.3-2005 Clause 49 PCS transmitter    */
/*   4 = XCON_PBERT_PROFILE_ETH_4                               */
/*       Ethernet : Transparent transport via the IEEE          */
/*                  Std 802.3-2005 Clause 47/48 XAUI transmitter*/
/*   5 = XCON_PBERT_PROFILE_GFP_S                               */
/*       GFP-F    : transport of MAC frames (DA/SA/../FCS)      */
/*   6 = XCON_PBERT_PROFILE_GFP_T                               */
/*       GFP-T    : transparent transport of entire MAC frames  */
/*                  (Preamble/SFD/DA/SA/../FCS) and Ordered Sets*/
/*   7 = XCON_PBERT_PROFILE_FC                                  */
/*       Fibre Channel : Transport of FC frames (SOF/../EOF),   */
/*                       Primitive Signals & Primitive Sequences*/
/*                                                              */
/* The [min_len] parameter selects the unit minimum length value*/
/* (number of octets per unit). For MODE[traffic]=OS unit       */
/* minimum length must satisfy 'minlen % 4 = 0'                 */
/* When ULEN[mode]=LIN, set MINLEN=MAXLEN for fixed length units*/
/*   0 - 0x7FFF                                                 */
/*                                                              */
/* The [max_len] paramter selects the unit maximum length value */
/* (number of octets per unit). For MODE[traffic]=OS, unit      */
/* maximum length must satisfy 'maxlen % 4 = 0'                 */ 
/* When ULEN[mode]=LIN, set MAXLEN=MINLEN for fixed length units*/
/*   0 - 0x7FFF                                                 */
/*                                                              */
/* The [ifg] parameter is the inter frame gap specified as:     */
/*   0 = Line rate                                              */
/*   1 - 0x3FFF columns of inter frame gap                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 max1 =  max_len & 0x0000ffff;
  cs_uint16 max2 = (max_len & 0x00030000) >> 16;
  cs_uint8  pbert_slice = (module_id & 1) * 4 + slice;
  cs_status rtn = CS_OK;

  rtn |= ten_xcon_select_bert(temp_dev_id,pbert_slice,XCON_PBERT);

  rtn |= ten_xcon_set_pbert_mode(temp_dev_id,pbert_slice,XCON_TRAFFIC_FRAME,profile);
  
  rtn |= ten_xcon_set_pbert_protocol(temp_dev_id,pbert_slice,0,0,XCON_DA_UCAST);

  rtn |= ten_xcon_control_pbert_frame_payload(temp_dev_id,pbert_slice,XCON_PAYLOAD_PRBS,CS_ENABLE);
                                               
  rtn |= ten_xcon_control_pbert_unit_len(temp_dev_id,pbert_slice,XCON_UNIT_LEN_RANDOM,0x7ff,min_len,max_len);

  rtn |= ten_xcon_pbert_control_traffic(temp_dev_id,pbert_slice,0); 

  rtn |= ten_xcon_pbert_control_ifg(temp_dev_id,pbert_slice,0,ifg); 

  rtn |= ten_xcon_pbert_select_fixed_pattern(temp_dev_id,pbert_slice,XCON_FIXED_PATTERN_01,0x00,0x11);

  rtn |= ten_xcon_pbert_select_fixed_pattern(temp_dev_id,pbert_slice,XCON_FIXED_PATTERN_23,0x22,0x33);

  rtn |= ten_xcon_pbert_select_fixed_pattern(temp_dev_id,pbert_slice,XCON_FIXED_PATTERN_45,0x08,0x00);

  rtn |= ten_xcon_pbert_select_fixed_pattern(temp_dev_id,pbert_slice,XCON_FIXED_PATTERN_67,0x00,0x00);

  if(max_len > 1518 && profile <=4) {
    rtn |= ten_pp10g_mac_rx_maxlen(module_id,slice,max_len);
  }
  if(max_len > 1518 && (profile == 5 || profile == 6)) {
    rtn |= ten_pp10g_gfp_rx_maxlen(module_id,slice,max_len);
  }
  if(max_len > 1518) {
    rtn |= ten_pp10g_xgadj_tx_maxframe(module_id,slice,max2,max1);
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG PBERT MUX CLIENT           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_pbert_odtu23(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint16 line,
                                     cs_uint16 client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Line                                          */
/*              o Client                                        */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision PBERT muxponder client. The line side is           */
/* only defined to provide some line-side configuration.        */
/*                                                              */
/* [module_id_line] specifies line's module ID                  */ 
/*                                                              */
/* [slice_line] specifies line's slice:                         */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client] specifies the client's module ID          */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   0x02 = TEN_TRAFFIC_TYPE_OTU3E                              */
/*   0x03 = TEN_TRAFFIC_TYPE_OTU3P                              */
/*   0x19 = TEN_TRAFFIC_TYPE_OTU3P2                             */
/*                                                              */
/* [client] specifies the traffic type of the client:           */
/*   0x13 = TEN_TRAFFIC_TYPE_10GFC                              */
/*   0x14 = TEN_TRAFFIC_TYPE_8GFC                               */
/*   20 = TEN_TRAFFIC_TYPE_10GE                                 */
/*                                                              */
/* [slice_client]  specifies client's slice:                    */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in MHz,              */
/*   For example, 400.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;

  cs_uint16 pbert_prof;
  cs_uint16 pbert_min_size  =   64;
  cs_uint16 pbert_max_size  = 1518;
  cs_uint16 pbert_ifg;


  CS_PRINT("ten_hl_config_pbert_odtu23:  0x%04X, sl=%d, 0x%04X, sl=%d\n, dyn=%d sysclk=%d\n",
           module_id_line, slice_line, module_id_client, 
           slice_client, dyn_repro, sysclk);

  if (client == TEN_TRAFFIC_TYPE_10GE) {
    pbert_prof = 0;
  }
  else {
    pbert_prof = 7;
  }

  /* The large ifg for 10ge is to slow down the bitrate for flow controlled traffic configs */
  if (client == TEN_TRAFFIC_TYPE_10GE) {
    pbert_ifg = 50;
  }
  else {
    pbert_ifg = 5;
  }

  if (client == TEN_TRAFFIC_TYPE_8GFC) {
    rtn |= ten_hl_n10g_config(module_id_line, slice_line, 
                              TEN_N10G_RX_ODU2J_8GFC, 
                              TEN_N10G_TX_8GFC_ODU2J, dyn_repro);
  }
  else if (client == TEN_TRAFFIC_TYPE_10GFC) {
    rtn |= ten_hl_n10g_config(module_id_line, slice_line,
                              TEN_N10G_RX_OXU3_10GEP,
                              TEN_N10G_TX_10GE_OXU3P, dyn_repro);
  }
  else {
    rtn |= ten_hl_n10g_config(module_id_line, slice_line,
                              TEN_N10G_RX_OTU2_10GE,
                              TEN_N10G_TX_10GE_OTU2, dyn_repro);
  }

  if (line == TEN_TRAFFIC_TYPE_OTU3) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 3082, 0);
  }

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, 
                            TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  if (client == TEN_TRAFFIC_TYPE_8GFC) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, 
                               TEN_PP10G_RX_8FC, TEN_PP10G_TX_8FC); 
  }
  else if (client == TEN_TRAFFIC_TYPE_10GFC) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client,
                               TEN_PP10G_RX_FC, TEN_PP10G_TX_FC);
  }
  else if (client == TEN_TRAFFIC_TYPE_10GE) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client,
                               TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
  }
  
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci(module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  

  /* Configure XCON */
  rtn |= ten_xcon_es_select_read_source(temp_dev_id, 
                                       (module_id_client & 1) * 4 + slice_client,
                                       XCON_PBERT);
                  
  rtn |= ten_xcon_es_select_source(temp_dev_id,
                                  (module_id_client & 1) * 4 + slice_client,
                                  (module_id_client & 1) * 4 + slice_client,
                                  XCON_PP10G);
                               
  rtn |= ten_xcon_config_es_mode(temp_dev_id,
                                 (module_id_client & 1) * 4 + slice_client,
                                 XCON_FP, XCON_NO_GFP,
                                 XCON_MODE_STORE_FWD, XCON_MODE_PKT);

  if (client == TEN_TRAFFIC_TYPE_8GFC) {
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                               (module_id_client & 1) * 4 + slice_client,
                                               XCON_RECENTER_LOWER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                               (module_id_client & 1) * 4 + slice_client, 
                                               XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                               (module_id_client & 1) * 4 + slice_client, 
                                               XCON_RECENTER_UPPER, CS_DISABLE);

  }
  else if (client == TEN_TRAFFIC_TYPE_10GFC) {
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                               (module_id_client & 1) * 4 + slice_client,
                                               XCON_RECENTER_LOWER, CS_ENABLE);
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                               (module_id_client & 1) * 4 + slice_client,
                                               XCON_AUTO_CENTER   , CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                               (module_id_client & 1) * 4 + slice_client,
                                               XCON_RECENTER_UPPER, CS_ENABLE);

    rtn |= ten_xcon_set_circuit_thresholds(temp_dev_id,
                                           (module_id_client & 1) * 4 + slice_client,
                                           XCON_ES_IML_THRESH,0x80);
    rtn |= ten_xcon_set_circuit_thresholds(temp_dev_id,
                                           (module_id_client & 1) * 4 + slice_client,
                                           XCON_ES_CIRCUIT_THRESHOLD_LOWER,0x10);
    rtn |= ten_xcon_set_circuit_thresholds(temp_dev_id,
                                           (module_id_client & 1) * 4 + slice_client,
                                           XCON_ES_CIRCUIT_THRESHOLD_UPPER,0x110);

    rtn |= ten_xcon_set_es_watermark_level(temp_dev_id,
                                           (module_id_client & 1) * 4 + slice_client, 
                                           XCON_THRESHOLD_LEVEL_2, 0x0a00);
    rtn |= ten_xcon_set_es_watermark_level(temp_dev_id,
                                           (module_id_client & 1) * 4 + slice_client, 
                                           XCON_THRESHOLD_LEVEL_3, 0x0020);
    rtn |= ten_xcon_set_es_watermark_level(temp_dev_id,
                                           (module_id_client & 1) * 4 + slice_client, 
                                           XCON_THRESHOLD_LEVEL_4, 0x1F40);
  }

  rtn |= ten_n10g_set_pktie(module_id_client, slice_client, 1);

  /* Disable Deskew function aligning 4 incoming stream by FP since not full aggr */
  rtn |= ten_n40g_set_dsbldskw(module_id_line, 1);

  rtn |= ten_hl_config_pbert(module_id_client, slice_client, pbert_prof, pbert_min_size, pbert_max_size, pbert_ifg);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL PBERT TRANSPONDER CLIENT          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_pbert_otu2(cs_uint16 module_id_line,
                                   cs_uint8  slice_line,
                                   cs_uint16 module_id_client,
                                   cs_uint8  slice_client,
                                   cs_uint16 client,
                                   cs_uint8  dyn_repro,
                                   cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Client                                        */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a PBERT transponder client. The line side is       */
/* only defined to provide some line-side configuration.        */
/*                                                              */
/* [module_id_line] specifies line's module ID                  */ 
/*                                                              */
/* [slice_line] specifies line's slice:                         */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client] specifies the client's module ID          */
/*                                                              */
/* [slice_client]  specifies client's slice:                    */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [client] specifies the traffic type of the client:           */
/*   13 = TEN_TRAFFIC_TYPE_10GFC                                */
/*   14 = TEN_TRAFFIC_TYPE_8GFC                                 */
/*   15 = TEN_TRAFFIC_TYPE_4GFC                                 */
/*   16 = TEN_TRAFFIC_TYPE_2GFC                                 */
/*   20 = TEN_TRAFFIC_TYPE_10GE                                 */
/*                                                              */
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in MHz,              */
/*   For example, 400.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  cs_uint16 instance_client = (module_id_client & 1) * 4 + slice_client;

  cs_uint16 pbert_prof;
  cs_uint16 pbert_min_size  =   64;
  cs_uint16 pbert_max_size  = 1518;
  cs_uint16 pbert_ifg;


  CS_PRINT("ten_hl_config_pbert_otu2:  0x%04X, sl=%d, 0x%04X, sl=%d\n, dyn=%d sysclk=%d\n",
           module_id_line, slice_line, module_id_client, 
           slice_client, dyn_repro, sysclk);

  if (client == TEN_TRAFFIC_TYPE_10GE) {
    pbert_prof = 0;
  }
  else {
    pbert_prof = 7;
  }

  /* The large ifg for 10ge is to slow down the bitrate for flow controlled traffic configs */
  if (client == TEN_TRAFFIC_TYPE_10GE) {
    pbert_ifg = 50;
  }
  else {
    pbert_ifg = 5;
  }

  if ((client == TEN_TRAFFIC_TYPE_8GFC) ||
      (client == TEN_TRAFFIC_TYPE_4GFC) ||
      (client == TEN_TRAFFIC_TYPE_2GFC)) {
    rtn |= ten_hl_n10g_config(module_id_line, slice_line, 
                              TEN_N10G_RX_ODU2J_8GFC, 
                              TEN_N10G_TX_8GFC_ODU2J, dyn_repro);
  }
  else if (client == TEN_TRAFFIC_TYPE_10GFC) {
    rtn |= ten_hl_n10g_config(module_id_line, slice_line,
                              TEN_N10G_RX_OXU3_10GEP,
                              TEN_N10G_TX_10GE_OXU3P, dyn_repro);
  }
  else {
    rtn |= ten_hl_n10g_config(module_id_line, slice_line,
                              TEN_N10G_RX_OTU2_10GE,
                              TEN_N10G_TX_10GE_OTU2, dyn_repro);
  }

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, 
                            TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
                            
  if ((client == TEN_TRAFFIC_TYPE_8GFC) ||
      (client == TEN_TRAFFIC_TYPE_4GFC) ||
      (client == TEN_TRAFFIC_TYPE_2GFC)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, 
                               TEN_PP10G_RX_8FC, TEN_PP10G_TX_8FC); 
  }
  else if (client == TEN_TRAFFIC_TYPE_10GFC) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client,
                               TEN_PP10G_RX_FC, TEN_PP10G_TX_FC);
  }
  else if (client == TEN_TRAFFIC_TYPE_10GE) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client,
                               TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
  }
  
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci(module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  

  /* Configure XCON */
  if ((client == TEN_TRAFFIC_TYPE_8GFC) ||
      (client == TEN_TRAFFIC_TYPE_4GFC) ||
      (client == TEN_TRAFFIC_TYPE_2GFC)) {
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id, instance_client,
                                               XCON_RECENTER_LOWER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id, instance_client, 
                                               XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id, instance_client, 
                                               XCON_RECENTER_UPPER, CS_DISABLE);
  }
  else if (client == TEN_TRAFFIC_TYPE_10GFC) {
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id, instance_client,
                                               XCON_RECENTER_LOWER, CS_ENABLE);
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id, instance_client,
                                               XCON_AUTO_CENTER   , CS_DISABLE);
    rtn |= ten_xcon_select_es_packet_centering(temp_dev_id, instance_client,
                                               XCON_RECENTER_UPPER, CS_ENABLE);

    rtn |= ten_xcon_set_circuit_thresholds(temp_dev_id, instance_client,
                                           XCON_ES_IML_THRESH,0x80);
    rtn |= ten_xcon_set_circuit_thresholds(temp_dev_id, instance_client,
                                           XCON_ES_CIRCUIT_THRESHOLD_LOWER,0x10);
    rtn |= ten_xcon_set_circuit_thresholds(temp_dev_id, instance_client,
                                           XCON_ES_CIRCUIT_THRESHOLD_UPPER,0x110);

    rtn |= ten_xcon_set_es_watermark_level(temp_dev_id, instance_client, 
                                           XCON_THRESHOLD_LEVEL_2, 0x0a00);
    rtn |= ten_xcon_set_es_watermark_level(temp_dev_id, instance_client, 
                                           XCON_THRESHOLD_LEVEL_3, 0x0020);
    rtn |= ten_xcon_set_es_watermark_level(temp_dev_id, instance_client, 
                                           XCON_THRESHOLD_LEVEL_4, 0x1F40);
  }

  rtn |= ten_xcon_es_select_read_source(temp_dev_id, instance_client,
                                        XCON_PBERT);
                                 
  rtn |= ten_xcon_es_select_source(temp_dev_id, instance_client, instance_client,
                                   XCON_PP10G);
                              
  rtn |= ten_xcon_config_es_mode(temp_dev_id, instance_client,
                                 XCON_FP, XCON_NO_GFP,
                                 XCON_MODE_STORE_FWD, 
                                 XCON_MODE_PKT);

  rtn |= ten_n10g_set_pktie(module_id_client, slice_client, 1);

  rtn |= ten_hl_config_pbert(module_id_client, slice_client, pbert_prof, pbert_min_size, pbert_max_size, pbert_ifg);

  return (rtn);
}

/* Bug 23864 Start */
/****************************************************************/
/* $rtn_hdr_start  WRITE LINE, CLIENT RATE TO CONTROL BLOCK     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_cb_rates(cs_uint16 dev_id,
                       double line_rate,
                       double client_rate)
/* INPUTS     : o Device Id                                     */
/*              o Line Rate                                     */
/*              o Client Rate                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Write the line and client rates to the appropriate slots     */
/* of control block ten_syncdsync_cb_t.                         */
/*                                                              */
/* [line_rate] bit rate, in hz, of the line ioterface           */
/*                                                              */
/* [client_rate] bit rate, in hz, of the client ioterface       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  ten_dev_cb_t *pdevcb;

  cs_char8 *func = "ten_cb_rates";  /* __FUNCTION__ or __func__ not available for all compilers */

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  
  CS_PRINT("%s()  dev_id = %d, line_rate = %lf, client_rate = %lf\n", func, dev_id, line_rate, client_rate);

  if (pdevcb) {
    pdevcb->syncdsync_cb.line_rate   = line_rate;
    pdevcb->syncdsync_cb.client_rate = client_rate;
  }
  else {
    rtn = CS_ERROR;
  }

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  WRITE LINE, CLIENT RATE TO TREAD SAFE CONTROL BLOCK */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_thread_set_cb_rates (cs_uint16 dev_id,
                                   cs_uint16 slice_client,
                                   double line_rate,
                                   double client_rate)
/* INPUTS     : o Device Id                                     */
/*              o Line Rate                                     */
/*              o Client Rate                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Write the line and client rates to the appropriate slots     */
/* of the thread safe control block ten_syncdsync_cb_t.         */
/*                                                              */
/* [slice_client] parameter specifies the slice:                */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [line_rate] bit rate, in hz, of the line ioterface           */
/*                                                              */
/* [client_rate] bit rate, in hz, of the client ioterface       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_thread_set_cb_rates";  /* __FUNCTION__ or __func__ not available for all compilers */

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  CS_PRINT("%s()  dev_id = %d, %s, \nline_rate = %lf, client_rate = %lf\n",
           func, dev_id, ten_slice_strings[slice_client], line_rate, client_rate);

  if (pdevcb) {
    pdevcb->syncdsync_thread_cb[slice_client].line_rate   = line_rate;
    pdevcb->syncdsync_thread_cb[slice_client].client_rate = client_rate;
  }
  else {
    rtn = CS_ERROR;
  }

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  CALCULATE HYSTERESIS                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_calc_hyst(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Calculate the hysteresis value for deterministic             */
/* justificationin and write the value to the appropriate slot  */
/* of control block ten_syncdsync_cb_t.                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  ten_dev_cb_t *pdevcb;
  cs_uint32    hysteresis;
  double       line_rate;
  cs_uint16    ncols;
  cs_uint16    fs;

  CS_PRINT("ten_calc_hyst:  dev_id = %d\n", dev_id);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  if (pdevcb) {
    line_rate   = pdevcb->syncdsync_cb.line_rate;
    ncols       = pdevcb->syncdsync_cb.P_line;
    fs          = pdevcb->syncdsync_cb.num_just_oxu3;
    CS_PRINT("line_rate = %lf, ncols = %d, fs = %d\n", line_rate, ncols, fs);

    /* "client_rate" will always be odu2 rate */
    hysteresis = (cs_uint32)(64*ncols/(60928-fs-(1024*10037273920.0*ncols)/(line_rate)));
    pdevcb->syncdsync_cb.hysteresis = hysteresis;
    CS_PRINT("hyst = 0x%x\n", hysteresis);
  }
  else {
    rtn = CS_ERROR;
  }

  return (rtn);
}
/* Bug 23864 End  */

/* Bug 28237 Start  */
/****************************************************************/
/* CALCULATE HYSTERESIS                                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_calc_hyst_t41(cs_uint16 dev_id, cs_uint8 slice, cs_uint8  map_odtu)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Calculate the hysteresis value for deterministic             */
/* justificationin and write the value to the appropriate slot  */
/* of control block ten_syncdsync_cb_t.                         */
/*                                                              */
/* [slice] parameter specifies line's slice:                    */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* The [map_odtu] parameter specifies the mapping method        */
/*  TEN_MAP_BMP,           = 0                                  */
/*  TEN_MAP_AMP,           = 1                                  */
/*  TEN_MAP_AMP_DT,        = 2                                  */
/*  TEN_MAP_AMP_PROP,      = 3                                  */
/*  TEN_MAP_AMP_PROP_DT,   = 4                                  */
/*  TEN_MAP_GMP_LO,        = 5                                  */
/*  TEN_MAP_GMP_HO,        = 6                                  */
/*  TEN_MAP_GMP_HO_DT,     = 7                                  */
/*                                                              */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  ten_syncdsync_cb_t *psyncdsync_cb;
  cs_uint32    hysteresis = 0;
  double       line_rate;
  double       xcon_client_rate;
  cs_uint16    ncols;
  cs_uint16    fs;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_calc_hyst_t41";  /* __FUNCTION__ or __func__ not available for all compilers */

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3.", func, slice);
    return(CS_ERROR);
  }

  CS_PRINT("%s()  dev_id = %d, %s\n", func, dev_id, ten_slice_strings[slice]);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  psyncdsync_cb = &pdevcb->syncdsync_thread_cb[slice];

  if (pdevcb) {
    line_rate   = psyncdsync_cb->line_rate;
    xcon_client_rate = psyncdsync_cb->xcon_client_rate;
    ncols       = psyncdsync_cb->P_line;
    fs          = psyncdsync_cb->num_just_oxu3;
    CS_PRINT("    line_rate = %lf, ncols = %d, fs = %d\n", line_rate, ncols, fs);

    if (map_odtu == TEN_MAP_GMP_HO_DT) {
              /*hysteresis = (pdevcb->syncdsync_thread_cb[slice_client].P_line*128.0)/(_round(((Cm*gmp_timeslots))) -                            */
              /*          (4*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate*n1/pdevcb->syncdsync_thread_cb[slice_client].line_rate));*/
            /*  hysteresis = (ncols*128.0)/(_round(((Cm*gmp_timeslots))) - (4 * xcon_client_rate * n1/line_rate));  */
    } else {
      /* "client_rate" will always be odu2 rate */
      hysteresis = (cs_uint32)(64*ncols/(60928-fs-(1024*10037273920.0*ncols)/(line_rate)));
    }
    
    if(hysteresis > 0x3FFFFF)  /* Bugzilla 39003 */
      psyncdsync_cb->hysteresis = 0x3FFFFF;
    else
      psyncdsync_cb->hysteresis = hysteresis;
    CS_PRINT("    hyst = 0x%x\n", hysteresis);
  }
  else {
    rtn = CS_ERROR;
  }

  return (rtn);
}
/* Bug 28237 End  */

