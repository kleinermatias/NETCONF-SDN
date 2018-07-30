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
 * ten_hl_config_otu2.c
 *
 * API's for high level otu2 client configuration.
 *
 * $Id: ten_hl_config_otu2.c,v 1.22 2013/11/13 21:35:35 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

 
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2 TO OTU2               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu2_otu2(cs_uint16 module_id_line,
                                  cs_uint8  slice_line,
                                  cs_uint16 module_id_client,
                                  cs_uint8  slice_client,
                                  cs_uint8  dyn_repro,
                                  cs_uint8  term_otu,
                                  cs_uint8  line_tcm,
                                  cs_uint8  client_tcm,
                                  cs_uint8  sync_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o OTU Overhead Termination Type                 */
/*              o Line TCM termination                          */
/*              o Client TCM termination                        */
/*              o Sync Mode                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client OTU2 to OTU2 pair.                   */
/*                                                              */
/* The [module_id_line] parameter specifies the line's module   */
/* ID                                                           */
/*                                                              */
/* The [slice_line] parameter specifies line's slice and is one */
/* of the following:                                            */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [module_id_client] parameter specifies the client's      */
/* module ID                                                    */
/*                                                              */
/* The [slice_client] parameter specifies client's slice and is */
/*  one of the following:                                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dyn_repro] parameter specifies the type of dynamic      */
/* reprovisioning and is one of the following:                  */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [line_tcm] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* The [client_tcm] parameter specifies the termination for TCM */
/* 1 through 6.  This is a bit encoded parameter with bits 1    */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* The [sync_mode] parameter specifies the clock sync method    */
/*   0 = TEN_MAP_AMP                                            */
/*   1 = TEN_MAP_BMP                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  T41_t *pDev = NULL;
  
  CS_PRINT("ten_hl_config_otu2_otu2: 0x%04X, %d, 0x%04X, %d, %d, 0x%X, 0x%X\n",
           module_id_line, slice_line, module_id_client, slice_client,
           dyn_repro, term_otu, line_tcm, client_tcm);

  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);
  
  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": line slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": client slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": dyn_repro out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (term_otu > TEN_OTU_TERM_FULL) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term_otu out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (line_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  

  if (client_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  
   
  if (sync_mode > TEN_MAP_BMP) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid clk sync option");
    return (CS_ERROR);
  }

  if (sync_mode == TEN_MAP_BMP) {
    ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2_ODU2, TEN_N10G_TX_ODU2_OTU2, dyn_repro);
  }
  else {
    /* Force termination mode to full */
    term_otu = TEN_OTU_TERM_FULL;
    
    ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2_OPU2, TEN_N10G_TX_OPU2_OTU2, dyn_repro);
    ten_n10g_otnr_set_stm64md(module_id_line, slice_line, 1);
    ten_n10g_otnr_set_dwmod(module_id_line, slice_line, 3);
    ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 1);
    ten_n10g_otnt_set_wrmd(module_id_line, slice_line, 1);
    ten_n10g_set_otnt_wrpcfg4(module_id_line, slice_line, 0, 0, 0, 0, 1);
  }

  if (sync_mode == TEN_MAP_BMP) {
    ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_OTU2_ODU2, TEN_N10G_TX_ODU2_OTU2, 0);
  }
  else {
    ten_hl_n10g_config (module_id_client, slice_client, TEN_N10G_RX_OTU2_OPU2, TEN_N10G_TX_OPU2_OTU2, 0);
    ten_n10g_otnr_set_stm64md(module_id_client, slice_client, 1);
    ten_n10g_otnr_set_dwmod(module_id_client, slice_client, 3);
    ten_n10g_otnt_set_stm64md(module_id_client, slice_client, 1);
    ten_n10g_otnt_set_wrmd(module_id_client, slice_client, 1);
    ten_n10g_set_otnt_wrpcfg4(module_id_client, slice_client, 0, 0, 0, 0, 1);
  }
  
  /* Bugzilla #19353, fix bus errors */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  ten_hl_xcon_config(temp_dev_id, (module_id_line & 1) * 4 + slice_line,
                     (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OTU2);
 
  /* Setup Termination Mode */
  ten_hl_n10g_config_termination(module_id_line, slice_line, term_otu, line_tcm);
  ten_hl_n10g_config_termination(module_id_client, slice_client, term_otu, client_tcm);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2E TO OTU2E             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu2e_otu2e(cs_uint16 module_id_line,
                                    cs_uint8  slice_line,
                                    cs_uint16 module_id_client,
                                    cs_uint8  slice_client,
                                    cs_uint8  dyn_repro,
                                    cs_uint8  term_otu,
                                    cs_uint8  line_tcm,
                                    cs_uint8  client_tcm,
                                    cs_uint8  sync_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o OTU Overhead Termination Type                 */
/*              o Line TCM termination                          */
/*              o Client TCM termination                        */
/*              o Sync Mode                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client OTU2e to OTU2e pair.                 */
/*                                                              */
/* The [module_id_line] parameter specifies the line's module   */
/* ID                                                           */
/*                                                              */
/* The [slice_line] parameter specifies line's slice and is one */
/* of the following:                                            */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [module_id_client] parameter specifies the client's      */
/* module ID                                                    */
/*                                                              */
/* The [slice_client] parameter specifies client's slice and is */
/*  one of the following:                                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dyn_repro] parameter specifies the type of dynamic      */
/* reprovisioning and is one of the following:                  */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [line_tcm] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* The [client_tcm] parameter specifies the termination for TCM */
/* 1 through 6.  This is a bit encoded parameter with bits 1    */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* The [sync_mode] parameter specifies the clock sync method    */
/*   0 = TEN_MAP_AMP                                            */
/*   1 = TEN_MAP_BMP.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  T41_t *pDev = NULL;
  
  CS_PRINT("ten_hl_config_otu2e_otu2e 0x%04X, %d, 0x%04X, %d, %d, 0x%X, 0x%X\n",
            module_id_line, slice_line, module_id_client, slice_client, dyn_repro, term_otu, line_tcm, client_tcm);

  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);

  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": line slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": client slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": dyn_repro out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (term_otu > TEN_OTU_TERM_FULL) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term_otu out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (line_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  

  if (client_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  
   
  if (sync_mode > TEN_MAP_BMP) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid clk sync option");
    return (CS_ERROR);
  }
   
  ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2E_ODU2E, TEN_N10G_TX_ODU2E_OTU2E, dyn_repro);

  ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_OTU2E_ODU2E, TEN_N10G_TX_ODU2E_OTU2E, 0);

  ten_hl_xcon_config(temp_dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OTU2);
   
  /* Bugzilla #19353, fix bus errors */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  /* Setup Termination Mode */
  ten_hl_n10g_config_termination(module_id_line, slice_line, term_otu, line_tcm);
  ten_hl_n10g_config_termination(module_id_client, slice_client, term_otu, client_tcm);
  
  /* Set for 3ms delay.  TDELON and TDELOFF = 510 */
  /* (1/11,095,727,850) * 65280 * 510 = 3ms */
  ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 510, 510);
  ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_client, slice_client, 510, 510);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU1F TO OTU1F             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu1f_otu1f(cs_uint16 module_id_line,
                                    cs_uint8  slice_line,
                                    cs_uint16 module_id_client,
                                    cs_uint8  slice_client,
                                    cs_uint8  dyn_repro,
                                    cs_uint8  term_otu,
                                    cs_uint8  line_tcm,
                                    cs_uint8  client_tcm,
                                    cs_uint8  sync_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o OTU Overhead Termination Type                 */
/*              o Line TCM termination                          */
/*              o Client TCM termination                        */
/*              o Sync Mode                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client OTU1f to OTU1f pair.                 */
/*                                                              */
/* The [module_id_line] parameter specifies the line's module   */
/* ID                                                           */
/*                                                              */
/* The [slice_line] parameter specifies line's slice and is one */
/* of the following:                                            */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [module_id_client] parameter specifies the client's      */
/* module ID                                                    */
/*                                                              */
/* The [slice_client] parameter specifies client's slice and is */
/*  one of the following:                                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dyn_repro] parameter specifies the type of dynamic      */
/* reprovisioning and is one of the following:                  */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [line_tcm] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* The [client_tcm] parameter specifies the termination for TCM */
/* 1 through 6.  This is a bit encoded parameter with bits 1    */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* The [sync_mode] parameter specifies the clock sync method    */
/*   0 = TEN_MAP_AMP                                            */
/*   1 = TEN_MAP_BMP                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  T41_t *pDev = NULL;
  
  CS_PRINT ("ten_hl_config_otu1f_otu1f 0x%X, %d, 0x%X, %d, %d, 0x%X, 0x%X\n",
            module_id_line, slice_line, module_id_client, slice_client, dyn_repro, term_otu, line_tcm, client_tcm);

  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);
  
  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": line slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": client slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": dyn_repro out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (term_otu > TEN_OTU_TERM_FULL) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term_otu out of range.  s/b 0..1.");
    return (CS_ERROR);
  }
   
  if (line_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  

  if (client_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  
   
  if (sync_mode > TEN_MAP_BMP) {
    CS_HNDL_ERROR (module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid clk sync option");
    return (CS_ERROR);
  }
   
  ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2E_ODU2E, TEN_N10G_TX_ODU2E_OTU2E, dyn_repro);

  ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_OTU2E_ODU2E, TEN_N10G_TX_ODU2E_OTU2E, 0);

  ten_hl_xcon_config(temp_dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OTU2);
   
  /* Bugzilla #19353, fix bus errors */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  /* Setup Termination Mode */
  ten_hl_n10g_config_termination(module_id_line, slice_line, term_otu, line_tcm);
  ten_hl_n10g_config_termination(module_id_client, slice_client, term_otu, client_tcm);

  /* Set for 3ms delay.  TDELON and TDELOFF = 518 */
  /* (1/11,270,089,290) * 65280 * 518 = 3ms */
  ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 518, 518);
  ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_client, slice_client, 518, 518);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2 TO ODTU23             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu2_odtu23(cs_uint16 module_id_line,
                                    cs_uint8  slice_line,
                                    cs_uint16 module_id_client,
                                    cs_uint8  slice_client,
                                    cs_uint8  line,
                                    cs_uint8  dyn_repro,
                                    cs_uint8  term_otu,
                                    cs_uint8  line_tcm,
                                    cs_uint8  client_tcm)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Line                                          */
/*              o Dynamic Reprovision Type                      */
/*              o OTU Overhead Termination Type                 */
/*              o Line TCM termination                          */
/*              o Client TCM termination                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client OTU2 to OTU2 pair.                   */
/*                                                              */
/* The [module_id_line] parameter specifies the line's module   */
/* ID                                                           */
/*                                                              */
/* The [slice_line] parameter specifies line's slice and is one */
/* of the following:                                            */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [module_id_client] parameter specifies the client's      */
/* module ID                                                    */
/*                                                              */
/* The [line] parameter specifies line's rate and is one        */
/* of the following:                                            */
/*   TEN_TRAFFIC_TYPE_OTU3 = 1,                                 */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2,                                */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                 */
/*                                                              */
/* The [slice_client] parameter specifies client's slice and    */
/* is one of the following:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dyn_repro] parameter specifies the type of dynamic      */
/* reprovisioning and is one of the following:                  */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [line_tcm] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* The [client_tcm] parameter specifies the termination for TCM */
/* 1 through 6.  This is a bit encoded parameter with bits 1    */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable.                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint8 mod_num_line;
  cs_uint8 mod_num_client;
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID (module_id_line);
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);
  
  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": line slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": client slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": dyn_repro out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (term_otu > TEN_OTU_TERM_FULL) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term_otu out of range.  s/b 0..1.");
    return (CS_ERROR);
  }
   
  if (line_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  

  if (client_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }
  
  if ((line != TEN_TRAFFIC_TYPE_OTU3) && (line != TEN_TRAFFIC_TYPE_OTU3E) && 
      /* Bugzilla 25290 OTU3e2 Not Supported Start */
      (line != TEN_TRAFFIC_TYPE_OTU3E2) &&
      /* Bugzilla 25290 OTU3e2 Not Supported End */
      /* Bugzilla 20308 Start */
      (line != TEN_TRAFFIC_TYPE_OTU3P) && (line != TEN_TRAFFIC_TYPE_OTU3P2)) {
      /* Bugzilla 20308 End */
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid line.");
    return (CS_ERROR);
  }
  
  mod_num_line = TEN_MOD_ID_TO_MOD_NUM(module_id_line);
  mod_num_client = TEN_MOD_ID_TO_MOD_NUM(module_id_client);

  ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OXU3_ODU2, TEN_N10G_TX_ODU2_OXU3, dyn_repro);

  /* Bugzilla #19353, fix bus errors */
  ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_OTU2_ODU2, TEN_N10G_TX_ODU2_OTU2, 0);
   
  /* Bugzilla #20657, regression fixes */
  /* Line side OTU scrambling done in N40G block */
  ten_n10g_otnt_scrambling(module_id_line, slice_line, 0, 0); 
  ten_n10g_otnr_descrambling(module_id_line, slice_line, 0, 0); 

 /* Bugzilla # , Fix regression failures */
  if (line == TEN_TRAFFIC_TYPE_OTU3P) {
    ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2121, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2122, 0);
  }
  /* Bugzilla 20308 Start */
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    /* Bugzilla 24628 Start */ 
    ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 3083, 0);
    /* Bugzilla 24628 End */ 
  }
  /* Bugzilla 20308 End */
  /* Bugzilla 25290 OTU3e2 Not Supported Start */
#if 0  
  else if (line == TEN_TRAFFIC_TYPE_OTU3E2) {
    /* Bugzilla 24628 Start */ 
    ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 1875, 0);
    /* Bugzilla 24628 End */ 
  }
#endif  
  /* Bugzilla 25290 OTU3e2 Not Supported End */

  ten_n40g_otnt4x_bipmsk(module_id_line, 0xff);
  ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0);
  ten_n10g_otnt_bipmsk(module_id_client, slice_client, 0x80);

  /* Set TDELON/TDELOFF for 3ms */
  ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 492*239/255, 492*239/255);
  ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(module_id_line, 495, 495);
  ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_client, slice_client, 492, 492);

  /* Bugzilla #19353, fix bus errors */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  /* Disable PT insertion to make up for an incorrect table entery called in  config_n10g */
  ten_n10g_otnt_set_ptie(module_id_client, slice_client, 0);

  /*config_xcon($dev_id, (module_id_line & 1) * 4 + slice_line, ($module_id_client & 1) * 4 + slice_client, 'otu2');*/
  ten_hl_xcon_config(temp_dev_id, mod_num_line * 4 + slice_line, mod_num_client * 4 + slice_client, TEN_TRAFFIC_TYPE_OTU2);
  
  /* Setup Termination Mode */
  ten_hl_n10g_config_termination(module_id_line, slice_line, term_otu, line_tcm);
  ten_hl_n10g_config_termination(module_id_client, slice_client, term_otu, client_tcm);
  
  /* Bugzilla 21279 Start */

 /* Bugzilla # , Fix regression failures */

  ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  if ((line == TEN_TRAFFIC_TYPE_OTU3) || (line == TEN_TRAFFIC_TYPE_OTU3E)) {
    ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 0);
  }
  /* Bugzilla 24628 Start */
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 0);
  }
  /* Bugzilla 24628 End */
  else {
    ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 1);
  }

  ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);
  ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);
/* Bugzilla 21279 End */

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2E TO ODTU23            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu2e_odtu23(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint8  term_otu,
                                     cs_uint8  line_tcm,
                                     cs_uint8  client_tcm)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o OTU Overhead Termination Type                 */
/*              o Line TCM termination                          */
/*              o Client TCM termination                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision line-client pair for OTU2e to ODTU23.              */
/*                                                              */
/* The [module_id_line] parameter specifies the line's module   */
/* ID                                                           */
/*                                                              */
/* The [slice_line] parameter specifies line's slice and is one */
/* of the following:                                            */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [module_id_client] parameter specifies the client's      */
/* module ID                                                    */
/*                                                              */
/* The [slice_client] parameter specifies client's slice and    */
/* is one of the following:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dyn_repro] parameter specifies the type of dynamic      */
/* reprovisioning and is one of the following:                  */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [line_tcm] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* The [client_tcm] parameter specifies the termination for TCM */
/* 1 through 6.  This is a bit encoded parameter with bits 1    */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable.                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint8 mod_num_line;
  cs_uint8 mod_num_client;
  cs_status rtn = CS_OK;
  T41_t *pDev = NULL;

  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID (module_id_line);
  
  CS_PRINT("ten_hl_config_otu2e_odtu23: 0x%04X, sl=%d, 0x%04X, sl=%d, dyn_repro=%d, 0x%X, 0x%X\n",
            module_id_line, slice_line, module_id_client, slice_client, dyn_repro, term_otu, line_tcm, client_tcm);
  
  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);
  
  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": line slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": client slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": dyn_repro out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (term_otu > TEN_OTU_TERM_FULL) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term_otu out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (line_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  

  if (client_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  
   
  mod_num_line = TEN_MOD_ID_TO_MOD_NUM(module_id_line);
  mod_num_client = TEN_MOD_ID_TO_MOD_NUM(module_id_client);
  
  /* Bugzilla #34099 start change, refactor pp10g init/reset sequence */
  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
  /* Bugzilla #34099 end change, refactor pp10g init/reset sequence */
                              
  rtn |= ten_hl_n10g_rx_init(module_id_client, slice_client, TEN_N10G_RX_OTU2E_ODU2E);
  rtn |= ten_hl_n10g_tx_init(module_id_line, slice_line, TEN_N10G_TX_ODU2_OXU3P);
  rtn |= ten_hl_n10g_rx_init(module_id_line, slice_line, TEN_N10G_RX_OXU3_ODU2P);
  rtn |= ten_hl_n10g_tx_init(module_id_client, slice_client, TEN_N10G_TX_ODU2E_OTU2E);

  /* bugzilla #20657, regression fixes */
  rtn |= ten_n10g_otnt_scrambling(module_id_line, slice_line, 0, 0); 
  rtn |= ten_n10g_otnr_descrambling(module_id_line, slice_line, 0, 0); 

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  /* Bugzilla 20308 Start */
  /*if (line == TEN_TRAFFIC_TYPE_OTU3E) { */
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_client, CS_TX_AND_RX, 0, 2);
  /*}
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 992, 0);
  } */
  /* Bugzilla 20308 End */


  rtn |= ten_n40g_otnt4x_set_ptie(module_id_line, 1);
  rtn |= ten_n40g_set_pti_byte(module_id_line, 0x20);
  rtn |= ten_n40g_set_expected_pti_byte(module_id_line, 0x20);

  rtn |= ten_n40g_otnt4x_bipmsk(module_id_line, 0xff);

  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x00);
  rtn |= ten_n10g_otnt_bipmsk(module_id_client, slice_client, 0x80);

  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 1.036*492*239/255, 1.036*492*239/255);
  rtn |= ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(module_id_line, 1.036*495, 1.036*495);
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_client, slice_client, 1.036*492, 1.036*492);
    
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line,
                            (module_id_client & 1) * 4 + slice_client,
                            TEN_TRAFFIC_TYPE_OTU2E);
    
  /* Bugzilla 21604 Start */
  /* Setup Termination Mode */
  ten_hl_n10g_config_termination(module_id_line, slice_line, term_otu, line_tcm);
  ten_hl_n10g_config_termination(module_id_client, slice_client, term_otu, client_tcm);
  /* Bugzilla 21604 End */

/* Bugzilla 21279 Start */

 /* Bugzilla # , Fix regression failures */

  ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 1);

  ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);
  ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);
/* Bugzilla 21279 End */
  
  return (rtn);
}

/* Bugzilla 20308 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU1E TO ODTU23            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu1e_odtu23(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  line,
                                     cs_uint8  dyn_repro,
                                     cs_uint8  term_otu,
                                     cs_uint8  line_tcm,
                                     cs_uint8  client_tcm)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o OTU Overhead Termination Type                 */
/*              o Line TCM termination                          */
/*              o Client TCM termination                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision line-client pair for OTU2e to ODTU23.              */
/*                                                              */
/* The [module_id_line] parameter specifies the line's module   */
/* ID                                                           */
/*                                                              */
/* The [slice_line] parameter specifies line's slice and is one */
/* of the following:                                            */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [module_id_client] parameter specifies the client's      */
/* module ID                                                    */
/*                                                              */
/* The [line] parameter specifies line's rate and is one        */
/* of the following:                                            */
/*   0x01 = TEN_OTU3                                            */
/*   0x02 = TEN_OTU3E                                           */
/*   0x03 = TEN_OTU3P                                           */
/*   0x19 = TEN_TRAFFIC_TYPE_OTU3P2                             */
/*                                                              */
/* The [slice_client] parameter specifies client's slice and    */
/* is one of the following:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dyn_repro] parameter specifies the type of dynamic      */
/* reprovisioning and is one of the following:                  */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [line_tcm] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* The [client_tcm] parameter specifies the termination for TCM */
/* 1 through 6.  This is a bit encoded parameter with bits 1    */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable.                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint8 mod_num_line;
  cs_uint8 mod_num_client;
  cs_status rtn = CS_OK;
  T41_t *pDev = NULL;

  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID (module_id_line);
  
  CS_PRINT("ten_hl_config_otu1e_odtu23: 0x%04X, sl=%d, 0x%04X, sl=%d, dyn_repro=%d, 0x%X, 0x%X\n",
            module_id_line, slice_line, module_id_client, slice_client, dyn_repro, term_otu, line_tcm, client_tcm);
  
  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);
  
  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": line slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": client slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (line != TEN_TRAFFIC_TYPE_OTU3P2) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid line.");
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": dyn_repro out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (term_otu > TEN_OTU_TERM_FULL) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term_otu out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (line_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  

  if (client_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  
   
  mod_num_line = TEN_MOD_ID_TO_MOD_NUM(module_id_line);
  mod_num_client = TEN_MOD_ID_TO_MOD_NUM(module_id_client);
  
  /* Bugzilla #34099 start change, refactor pp10g init/reset sequence */
  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
  /* Bugzilla #34099 end change, refactor pp10g init/reset sequence */
     
  rtn |= ten_hl_n10g_rx_init(module_id_client, slice_client, TEN_N10G_RX_OTU2E_ODU2E);
  rtn |= ten_hl_n10g_tx_init(module_id_line, slice_line, TEN_N10G_TX_ODU2_OXU3P);
  rtn |= ten_hl_n10g_rx_init(module_id_line, slice_line, TEN_N10G_RX_OXU3_ODU2P);
  rtn |= ten_hl_n10g_tx_init(module_id_client, slice_client, TEN_N10G_TX_ODU2E_OTU2E);

  /* Disable scrabling in 10G block */
  rtn |= ten_n10g_otnt_scrambling(module_id_line, slice_line, 0, 0); 
  rtn |= ten_n10g_otnr_descrambling(module_id_line, slice_line, 0, 0); 

  /* OTU1e has no fixed stuff */
  rtn |= ten_n10g_otnr_set_stm64md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 0);

  rtn |= ten_n10g_otnr_set_stm64md(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_set_stm64md(module_id_client, slice_client, 0);

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 1244, 0);
  }

  rtn |= ten_n40g_otnt4x_set_ptie(module_id_line, 1);
  rtn |= ten_n40g_set_pti_byte(module_id_line, 0x20);
  rtn |= ten_n40g_set_expected_pti_byte(module_id_line, 0x20);

  rtn |= ten_n40g_otnt4x_bipmsk(module_id_line, 0xff);

  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x00);
  rtn |= ten_n10g_otnt_bipmsk(module_id_client, slice_client, 0x80);

  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 1.036*492*239/255, 1.036*492*239/255);
  rtn |= ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(module_id_line, 1.036*495, 1.036*495);
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_client, slice_client, 1.036*492, 1.036*492);
    
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line,
                            (module_id_client & 1) * 4 + slice_client,
                            TEN_TRAFFIC_TYPE_OTU1E);

  /* Bugzilla 21604 Start */
  /* Setup Termination Mode */
  ten_hl_n10g_config_termination(module_id_line, slice_line, term_otu, line_tcm);
  ten_hl_n10g_config_termination(module_id_client, slice_client, term_otu, client_tcm);
  /* Bugzilla 21604 End */
  
/* Bugzilla 21279 Start */
  
  /* Bugzilla # , fix regression failures */
  ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 1);
  
  ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);
  ten_n40g_otnt4x_set_jc_plus(module_id_line, 0); 
/* Bugzilla 21279 End */
 
  return (rtn);
}
/* Bugzilla 20308 End */

/* Bugzilla 22514 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2 Cross Connect Loopback */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu2_xcon_loopback(cs_uint16 module_id,
                                         cs_uint8  slice,
                                         cs_uint16 traffic_type,
                                         cs_uint8  dyn_repro,
                                         cs_uint8  term_otu,
                                         cs_uint8  tcm,
                                         cs_uint16 sysclk)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Line                                          */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a traffic_type OTU2 to 10GE pair.                  */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [slice] specifies slice:                                     */      
/*   0x00 = TEN_SLICE0                                          */      
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [traffic_type] specifies the traffic type:                   */
/*   0x05 = TEN_TRAFFIC_TYPE_OTU2                               */
/*   0x06 = TEN_TRAFFIC_TYPE_OTU2E                              */
/*   0x07 = TEN_TRAFFIC_TYPE_OTU1F                              */
/*   0x1D = TEN_TRAFFIC_TYPE_OTU1E                              */
/*                                                              */
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [tcm] parameter specifies the termination for TCM 1      */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in MHz,              */
/*   For example, 400.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* Bugzilla 23776 Start */
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_otu2_xcon_loopback";  /* __FUNCTION__ or __func__ not available for all compilers */
  
  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255.", func, slice);
    return (CS_ERROR);
  }

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU2) && (traffic_type != TEN_TRAFFIC_TYPE_OTU2E) &&  
      (traffic_type != TEN_TRAFFIC_TYPE_OTU1F) && (traffic_type != TEN_TRAFFIC_TYPE_OTU1E)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 5, 6, 7, 29.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if (term_otu > TEN_OTU_TERM_SECTION) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() term_otu %d out of range.  s/b 0..1.", func, term_otu);
    return (CS_ERROR);
  }

  if (tcm & ~0x7E) { 
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() tcm 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm);
    return(CS_ERROR);
  }

  CS_PRINT("%s() %s, Slice %d, %s, %s, %s, tcm = %d, sysclk = %d\n",
           func,
           ten_module_strings[module_id & 1],
           slice,
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_hl_config_otu_overhead_term_strings[term_otu],
           tcm,
           sysclk);
  /* Bugzilla 23776 End */


  rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2_ODU2, TEN_N10G_TX_ODU2_OTU2, dyn_repro);
  
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci(module_id, slice, CS_DISABLE);
  #endif
  
  rtn |= ten_hl_xcon_config(dev_id, (module_id & 1) * 4 + slice, (module_id & 1) * 4 + slice, TEN_TRAFFIC_TYPE_OTU2);
 
  /* Setup Termination Mode */
  rtn |= ten_hl_n10g_config_termination(module_id, slice, term_otu, tcm);

  return (rtn);
}
/* Bugzilla 22514 End */


/* Bugzilla 24047 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2E TO ODTU23            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu2e_odtu23_fix(cs_uint16 module_id_line,
                                         cs_uint8  slice_line,
                                         cs_uint16 module_id_client,
                                         cs_uint8  slice_client,
                                         cs_uint8  line,
                                         cs_uint8  dyn_repro,
                                         cs_uint8  term_otu,
                                         cs_uint8  line_tcm,
                                         cs_uint8  client_tcm)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Line Type                                     */
/*              o Dynamic Reprovision Type                      */
/*              o OTU Overhead Termination Type                 */
/*              o Line TCM termination                          */
/*              o Client TCM termination                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision line-client pair for OTU2e to ODTU23. This is a    */
/* modified version of ten_hl_config_otu2e_odtu23 that accounts */
/* for justifications for specified line rates                  */ 
/*                                                              */
/* The [module_id_line] parameter specifies the line's module   */
/* ID                                                           */
/*                                                              */
/* The [slice_line] parameter specifies line's slice and is one */
/* of the following:                                            */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [module_id_client] parameter specifies the client's      */
/* module ID                                                    */
/*                                                              */
/* The [line] parameter specifies line's rate and is one        */
/* of the following:                                            */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 0x19                             */
/*                                                              */
/* The [slice_client] parameter specifies client's slice and    */
/* is one of the following:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dyn_repro] parameter specifies the type of dynamic      */
/* reprovisioning and is one of the following:                  */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [line_tcm] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* The [client_tcm] parameter specifies the termination for TCM */
/* 1 through 6.  This is a bit encoded parameter with bits 1    */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable.                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint8 mod_num_line;
  cs_uint8 mod_num_client;
  cs_status rtn = CS_OK;
  T41_t *pDev = NULL;

  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID (module_id_line);
  
  CS_PRINT("ten_hl_config_otu2e_odtu23: 0x%04X, sl=%d, 0x%04X, sl=%d, dyn_repro=%d, 0x%X, 0x%X\n",
            module_id_line, slice_line, module_id_client, slice_client, dyn_repro, term_otu, line_tcm, client_tcm);
  
  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);
  
  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": line slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": client slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": dyn_repro out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (term_otu > TEN_OTU_TERM_FULL) { 
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term_otu out of range.  s/b 0..2.");
    return (CS_ERROR);
  }
   
  if (line_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  

  if (client_tcm & 0x81) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid line_tcm.");
    return (CS_ERROR);
  }  

  if ((line != TEN_TRAFFIC_TYPE_OTU3E) && 
      /* Bugzilla 20308 Start */
      (line != TEN_TRAFFIC_TYPE_OTU3P) && (line != TEN_TRAFFIC_TYPE_OTU3P2)) {
      /* Bugzilla 20308 End */
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, ": invalid line.");
    return (CS_ERROR);
  }
  mod_num_line = TEN_MOD_ID_TO_MOD_NUM(module_id_line);
  mod_num_client = TEN_MOD_ID_TO_MOD_NUM(module_id_client);
  
  /* Bugzilla #34099 start change, refactor pp10g init/reset sequence */
  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
  /* Bugzilla #34099 end change, refactor pp10g init/reset sequence */
     
  rtn |= ten_hl_n10g_rx_init(module_id_client, slice_client, TEN_N10G_RX_OTU2E_ODU2E);
  rtn |= ten_hl_n10g_tx_init(module_id_line, slice_line, TEN_N10G_TX_ODU2_OXU3P);
  rtn |= ten_hl_n10g_rx_init(module_id_line, slice_line, TEN_N10G_RX_OXU3_ODU2P);
  rtn |= ten_hl_n10g_tx_init(module_id_client, slice_client, TEN_N10G_TX_ODU2E_OTU2E);

  /* bugzilla #20657, regression fixes */
  rtn |= ten_n10g_otnt_scrambling(module_id_line, slice_line, 0, 0); 
  rtn |= ten_n10g_otnr_descrambling(module_id_line, slice_line, 0, 0); 

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  /* Bugzilla 20308 Start */
  if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 2);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 4);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 992, 0);
  }
  /* Bugzilla 20308 End */


  rtn |= ten_n40g_otnt4x_set_ptie(module_id_line, 1);
  rtn |= ten_n40g_set_pti_byte(module_id_line, 0x20);
  rtn |= ten_n40g_set_expected_pti_byte(module_id_line, 0x20);

  rtn |= ten_n40g_otnt4x_bipmsk(module_id_line, 0xff);

  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x00);
  rtn |= ten_n10g_otnt_bipmsk(module_id_client, slice_client, 0x80);

  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 1.036*492*239/255, 1.036*492*239/255);
  rtn |= ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(module_id_line, 1.036*495, 1.036*495);
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_client, slice_client, 1.036*492, 1.036*492);
    
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line,
                            (module_id_client & 1) * 4 + slice_client,
                            TEN_TRAFFIC_TYPE_OTU2E);
    
  /* Bugzilla 21604 Start */
  /* Setup Termination Mode */
  ten_hl_n10g_config_termination(module_id_line, slice_line, term_otu, line_tcm);
  ten_hl_n10g_config_termination(module_id_client, slice_client, term_otu, client_tcm);
  /* Bugzilla 21604 End */

/* Bugzilla 21279 Start */
  ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 1);

  ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);
  ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);
/* Bugzilla 21279 End */
  
  return (rtn);
}
/* Bugzilla 24047 End */


/* Bugzilla 22970 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2 KPGA                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu2_kpga (cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 traffic_type,
                                   cs_uint8  dyn_repro,
                                   cs_uint16 pattern,
                                   cs_uint16 data_in_stuff_bytes)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Traffic Type                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Pattern Selection                             */
/*              o Data In Stuff Bytes                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an OTU1e, OTU1f, OTU2 or OTU2e KPGA tester         */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [slice] specifies slice:                                     */      
/*   0x00 = TEN_SLICE0                                          */      
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [traffic_type] specifies the traffic type:                   */
/*   0x05 = TEN_TRAFFIC_TYPE_OTU2                               */
/*   0x06 = TEN_TRAFFIC_TYPE_OTU2E                              */
/*   0x07 = TEN_TRAFFIC_TYPE_OTU1F                              */
/*   0x1D = TEN_TRAFFIC_TYPE_OTU1E                              */
/*                                                              */
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   0x00 = TEN_KPG_FIXED_PATTERN                               */
/*   0x01 = TEN_KPG_PN11                                        */
/*   0x02 = TEN_KPG_PN23                                        */
/*   0x03 = TEN_KPG_PN31                                        */
/*                                                              */
/* [data_in_stuff_bytes] specifies if the test patter will be   */
/*                       inserted in the stuff bytes            */
/*   0x00 = Do not place or retrieve data in the stuff bytes    */
/*   0x01 = Place and retrieve data in the stuff bytes          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 module_num = module_id & 1;
  cs_status rtn = CS_OK;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_config_otu2_kpga";  /* __FUNCTION__ or __func__ not available for all compilers */
  
  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255. ", func, slice);
    return (CS_ERROR);
  }

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU1E) && (traffic_type != TEN_TRAFFIC_TYPE_OTU1F) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU2) && (traffic_type != TEN_TRAFFIC_TYPE_OTU2E) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OC192_OTU2)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 5, 6, 7 or 29.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }
   
  if (pattern > TEN_KPG_PN31) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }

  if (data_in_stuff_bytes > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() data_in_stuff_bytes %d out of range.  s/b 0..1.", func, data_in_stuff_bytes);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, Slice %d, %s, %s, %s, data_in_stuff_bytes = %d\n",
           func,
           ten_module_strings[module_num],
           slice,
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_kpg_strings[pattern],
           data_in_stuff_bytes);

  /* Provision N10G block using tables */
  /*if (traffic_type == TEN_TRAFFIC_TYPE_OC192_OTU2) {                                                        */
  /*  rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_OC192, TEN_N10G_TX_OC192_OTU2, dyn_repro);*/
  /*}                                                                                                         */
  /*else {                                                                                                    */
    /* Configure for full mapping and demapping */
    rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_OPU2, TEN_N10G_TX_OPU2_OTU2, dyn_repro);
  /*}                                                                                                         */

  if (data_in_stuff_bytes) {
    rtn |= ten_n10g_otnr_set_stm64md (module_id, slice, 0); /* Bytes in the columns 1905 to 1920 of each row are data */
    rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 0); /* Inserting data bytes into columns 1905 through 1920 of each row. */
  }  else {
    if ((traffic_type == TEN_TRAFFIC_TYPE_OTU2) || (traffic_type == TEN_TRAFFIC_TYPE_OTU2E)) {
      rtn |= ten_n10g_otnr_set_stm64md (module_id, slice, 1); /* Bytes in the columns 1905 to 1920 of each row are stuff bytes and removed by dewrapper */
      rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 1); /* Inserting stuff bytes into columns 1905 through 1920 of each row. */
    } else {
      rtn |= ten_n10g_otnr_set_stm64md (module_id, slice, 0); /* Bytes in the columns 1905 to 1920 of each row are data */
      rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 0); /* Inserting data bytes into columns 1905 through 1920 of each row. */
    }
  }

  rtn |= ten_n10g_otnr_set_dwmod  (module_id, slice, 3); /* Dewrapper enabled OTU to Client payload (Justification commands are evaluated) */
  rtn |= ten_n10g_otnt_set_wrmd   (module_id, slice, 1); /* Wrapper on (Client playload to OTU) */
  rtn |= ten_n10g_set_otnt_wrpcfg4(module_id, slice, 0, 0, 0, 0, 0);  /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */

  /* Clear downstream ODUk-OCI */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
  #endif
  
  /* Setup Termination Mode */
  rtn |= ten_hl_n10g_config_termination (module_id, slice, TEN_OTU_TERM_FULL, 0);

  /* Config KPG - PATSEL */   /* Bugzilla #33766, fix warnings, use cs_ctl_t enums */
  rtn |= ten_n10g_config_kpg (module_id, slice, CS_DISABLE, CS_DISABLE, pattern, 0, 0);  /* kpg_bypass, kpg_auto, pattern, fpat1, fpat0 */

  /* Insert FAS pattern of F6F6F6282828 hex in row 1, columns 1 through 6 */
  rtn |= ten_n10g_otnt_set_fasie(module_id, slice, 1);

  /* Configure Payload Type Insertion overhead */
  rtn |= ten_n10g_otnt_set_ptie (module_id, slice, 1);
  rtn |= ten_n10g_otnt_set_pti_byte (module_id, slice, TEN_PAYLOAD_TYPE_PRBS);
  rtn |= ten_n10g_set_expected_pti_byte (module_id, slice, TEN_PAYLOAD_TYPE_PRBS);

  /* Configure input to KPA to output of OTU */
  rtn |= ten_n10g_gblr_set_kpasel (module_id, slice, 1);

  /*if ((traffic_type == TEN_TRAFFIC_TYPE_OTU2) || (traffic_type == TEN_TRAFFIC_TYPE_OC192_OTU2)){*/
  if (traffic_type == TEN_TRAFFIC_TYPE_OTU2) {
      /* Set for 3ms delay.  TDELON and TDELOFF = 492.  (1/10,709,225,320) * 65280 * 492 = 3ms */
      rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff (module_id, slice, 492, 492);
  }
  else if (traffic_type == TEN_TRAFFIC_TYPE_OTU2E) { 
      /* Set for 3ms delay.  TDELON and TDELOFF = 510.  (1/11,095,727,850) * 65280 * 510 = 3ms */
      rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff (module_id, slice, 510, 510);
  }
  else if (traffic_type == TEN_TRAFFIC_TYPE_OTU1E) { 
      /* Set for 3ms delay.  TDELON and TDELOFF = 507.  (1/11,049,107,143) * 65280 * 507 = 3ms */
      rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff (module_id, slice, 507, 507);
  }
  else if (traffic_type == TEN_TRAFFIC_TYPE_OTU1F) {
      /* Set for 3ms delay.  TDELON and TDELOFF = 518.  (1/11,270,089,290) * 65280 * 518 = 3ms */
      rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff (module_id, slice, 518, 518);
  }
  
  /* Insert BIP in Path and Section Monitoring frame and all 6 Tandem Connection Monitoring frame fields*/
  rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF);

  /* PDHY0/1  Set PRBS Deassert Hysteresis to 1 for KBA reception */
  /* Bug #40056:  OTU2 KPGA configuration sets PDHY = 0, PHYS also left at 0 */
  rtn |= ten_n10g_set_gblr_pdhy(module_id, slice, 0xE100,0x5F5);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2 KPGS                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_otu2_kpga (cs_uint16 module_id,
                                         cs_uint8  slice,
                                         cs_uint16 traffic_type,
                                         cs_uint8  dyn_repro,
                                         cs_uint16 pattern)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Traffic Type                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Pattern Selection                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an OTU1e, OTU1f, OTU2 or OTU2e KPGA tester         */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [slice] specifies slice:                                     */      
/*   0x00 = TEN_SLICE0                                          */      
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [traffic_type] specifies the traffic type:                   */
/*   0x1F = TEN_TRAFFIC_TYPE_OC192_OTU2                         */
/*                                                              */
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   0x00 = TEN_KPG_FIXED_PATTERN                               */
/*   0x01 = TEN_KPG_PN11                                        */
/*   0x02 = TEN_KPG_PN23                                        */
/*   0x03 = TEN_KPG_PN31                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 i;
  cs_uint16 module_num = module_id & 1;
  cs_status rtn = CS_OK;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_config_oc192_otu2_kpga";  /* __FUNCTION__ or __func__ not available for all compilers */
  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255. ", func, slice);
    return (CS_ERROR);
  }

  if (traffic_type != TEN_TRAFFIC_TYPE_OC192_OTU2) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 31.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }
  
  if (pattern > TEN_KPG_PN31) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, Slice %d, %s, %s, %s\n",
           func,
           ten_module_strings[module_num],
           slice,
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_kpg_strings[pattern]);

  /* Provision N10G block using tables */
  rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_OC192, TEN_N10G_TX_OC192_OTU2, dyn_repro);

  rtn |= ten_n10g_otnr_set_dwmod  (module_id, slice, 3); /* Dewrapper enabled OTU to Client payload (Justification commands are evaluated) */
  rtn |= ten_n10g_otnt_set_wrmd   (module_id, slice, 1); /* Wrapper on (Client playload to OTU) */
  rtn |= ten_n10g_set_otnt_wrpcfg4(module_id, slice, 0, 0, 0, 0, 0);  /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
              
  /* SONET/SDH virtual container replaced with PRBS KPG.  Insert POH byte as configured bu POH register */
  rtn |= ten_n10g_soht_pohben0 (module_id, slice, 1, 1); /* PRBSIE, POHIE */
              
  /* Config KPG - PATSEL - KPGBY mux = 1 since want to pull from OC192 */ 
  /* Bugzilla #33766, fix warnings, use cs_ctl_t enums */
  rtn |= ten_n10g_config_kpg (module_id, slice, CS_ENABLE, CS_DISABLE, pattern, 0, 0);
  
  /* OTN is on, OTN and Sonet bypass off, KPG bypass on */
  rtn |= ten_n10g_set_gblt_bypasses (module_id, slice, 0, 0, 0, 1); /* OTN_OFF, OBY, SBY, KPGBY */
  
  /* POSTSCR, PRESCR */
  /*ten_n10g_otnt_scrambling (module_id, slice, 0, 1);  */
  /*ten_n10g_otnr_descrambling (module_id, slice, 0, 1);*/
  
  /* Enable Tx scrambling, B1IE, A1A2RSH (unused) and A1A2IE to create a frame */
  rtn |= ten_n10g_soht_set_ohben0 (module_id, slice, 1, 1, 0, 1);
  
  /* Enable B2IE for all B2 locations */
  for (i = 0; i < 12; i++) {
    rtn |= ten_n10g_soht_b2ie (module_id, slice, i, 0x7fff);
  }
  rtn |= ten_n10g_soht_b2ie (module_id, slice, 12, 0x0fff);

  /* Enable B3IE */
  rtn |= ten_n10g_soht_set_pohben0_b3ie (module_id, slice, 1);
  
  /* Wrapper on (Client playload to OTU) */
  /*rtn |= ten_n10g_otnt_set_wrmd (module_id, slice, 1); *//* Wrapper on (Client playload to OTU) */

  /* Insert FAS pattern of F6F6F6282828 hex in row 1, columns 1 through 6 */
  rtn |= ten_n10g_otnt_set_fasie (module_id, slice, 1);

  /* Provision an OC192 KPGA tester */
  rtn |= ten_tx_config_sonet_generation (module_id, slice);


  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id, slice, 0, 0, 0, 0, 0, 0, 0);
  
  /* KPASEL=0 - expect a SDH payload to the KPA */
  rtn |= ten_n10g_gblr_set_kpasel (module_id, slice, 0);
  
  /* Enable SDH/SONET descrambler */
  rtn |= ten_n10g_sdfr_set_scren (module_id, slice, 1);

  /* Set for 3ms delay.  TDELON and TDELOFF = 492.  (1/10,709,225,320) * 65280 * 492 = 3ms */
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff (module_id, slice, 492, 492);

  /* Insert BIP in Path and Section Monitoring frame and all 6 Tandem Connection Monitoring frame fields*/
  rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF);

  /* PDHY0/1  Set PRBS Deassert Hysteresis to 1 for KBA reception */
  /* Bug #40056:  OTU2 KPGA configuration sets PDHY = 0, PHYS also left at 0 */
  rtn |= ten_n10g_set_gblr_pdhy(module_id, slice, 0xE100,0x5F5);

  return (rtn);
}
/* Bugzilla 22970 End */
