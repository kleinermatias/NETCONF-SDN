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
 * ten_hl_config_otu2_t41.c
 *
 * API's for high level 10ge client configuration.
 *
 * $Id: ten_hl_config_10ge_t41.c,v 1.38 2013/03/14 18:52:24 khill Exp $
 *
 */
 
#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE TO OTU2V              */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge_otu2v_t41(cs_uint16 module_id_line,
                                       cs_uint16 slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint16 slice_client,
                                       cs_uint16 dyn_repro,
                                       cs_uint16 traffic_type_line,
                                       cs_uint16 fec_line,
                                       cs_uint16 traffic_type_client,
                                       cs_uint16 sysclk,
                                       cs_uint16 tcm_line,
                                       cs_uint16 gfp_frame_format,
                                       cs_uint16 flow_ctrl_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o System Clock                                  */
/*              o TCM Line                                      */
/*              o GFP Frame Format                              */
/*              o Flow Control Mode                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures 10GE on the client side into OTU2V on line side.  */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [slice_line] parameter specifies line's slice:               */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [module_id_client] parameter specifies client’s module ID    */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */ 
/*                                                              */
/* [slice_client] parameter specifies client's slice:           */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] parameter specifies the traffic type of  */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OTU2  = 5                                 */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                 */
/*   TEN_TRAFFIC_TYPE_OTU1E = 29                                */
/*                                                              */
/* [fec_line] parameter defines the line fec type:              */
/*   TEN_FEC_MODE_OTUkV             = 0  (7  %)                 */
/*   TEN_FEC_MODE_OTUkV_262         = 1  (10 %)                 */
/*   TEN_FEC_MODE_OTUkV_273         = 2  (15 %)                 */
/*   TEN_FEC_MODE_OTUkV_285         = 3  (20 %)                 */
/*   TEN_FEC_MODE_OTUkV_297         = 4  (25 %)                 */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5  (25 %)                 */
/*   TEN_FEC_MODE_OTUkV_301         = 6  (26 %)                 */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7  (7  %)                 */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8  (7  %)                 */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9  (3.4%)                 */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10 (4.2%)                 */
/*   TEN_FEC_MODE_OTUkV_267         = 11 (12 %)                 */
/*   TEN_FEC_MODE_OTUkV_270         = 12 (13 %)                 */
/*   TEN_FEC_MODE_GFEC              = 13 (7  %)                 */
/*   TEN_FEC_MODE_ZEROFEC           = 14                        */
/*   TEN_FEC_MODE_NOFEC             = 15                        */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*                                                              */
/* [traffic_type_client] parameter specifies the traffic type   */
/* of the client:                                               */
/*   TEN_TRAFFIC_TYPE_10GE_WAN             = 9                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2             = 10                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1             = 11                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3             = 12                 */
/*   TEN_TRAFFIC_TYPE_10GE_6_1             = 26                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_2             = 27                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28                 */
/*   TEN_TRAFFIC_TYPE_10GE_RA              = 30                 */
/*   TEN_TRAFFIC_TYPE_10GE_TC              = 33                 */
/*   TEN_TRAFFIC_TYPE_1GE                  = 63                 */
/*                                                              */
/* [sysclk] parameter specifies the sysclk frequency in MHz.    */
/*   For example, 400.                                          */
/*                                                              */
/* The [tcm_line] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* [gfp_frame_format] specifies the GFP frame format            */
/*   0 = TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4                       */
/*   1 = TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4                      */
/*   2 = TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC                      */
/*   3 = TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC                      */
/*                                                              */
/* The [flow_ctrl_mode] parameter specifies the flow control    */
/* mode                                                         */
/*   TEN_PP10G_FLOW_GFP_S_P         = 0                         */
/*   TEN_PP10G_FLOW_GFP_S           = 1                         */
/*   TEN_PP10G_FLOW_ETH_4           = 2 (Reactive)              */
/*   TEN_PP10G_FLOW_ETH_4_P         = 3 (Premptive)             */
/*   TEN_PP10G_FLOW_MAX_MODE        = 4                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint16 hsif_is_xaui;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_10ge_otu2v_t41";  
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);

  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE (module_id_client, pDev, CS_ERROR);

  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_line %d out of range.  s/b 0..3.", func, slice_line);
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_client %d out of range.  s/b 0..3.", func, slice_client);
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU2) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU2E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU1E)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 5, 6, 29.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if ((traffic_type_client != TEN_TRAFFIC_TYPE_10GE_WAN) && (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_6_2) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_7_1) && (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_7_3) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) && (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_TC) && 
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_6_1) && (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_7_2) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_1GE)) { /* Bugzilla 38871 */
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 9, 10, 11, 12, 26, 27, 28, 30, 33.", func, traffic_type_client);
    return (CS_ERROR);
  }

  if (tcm_line & ~0x7E) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_line 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_line);
    return(CS_ERROR);
  }

  if ((gfp_frame_format != TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4) && (gfp_frame_format != TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4) && 
       (gfp_frame_format != TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC) && (gfp_frame_format != TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC)) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() gfp_frame_format %d out of range.  s/b 0..3.", func, gfp_frame_format);
    return(CS_ERROR);
  }

  if ((flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S_P) && (flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S) &&
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P) &&
      (flow_ctrl_mode != TEN_PP10G_FLOW_MAX_MODE)) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() flow_ctrl_mode %d out of range.  s/b 0..4.", func, flow_ctrl_mode);
    return(CS_ERROR);
  }
  CS_PRINT("%s() %s, slice_line=%d, %s, slice_client=%d, %s, %s, %s, %s, sysclk=%d, tcm_line=0x%X, %s, %s\n",
            func,
            ten_module_strings[module_id_line&1], 
            slice_line, 
            ten_module_strings[module_id_client&1], 
            slice_client, 
            ten_hl_config_dyn_repro_strings[dyn_repro],
            ten_hl_config_traffic_types_strings[traffic_type_line], 
            ten_fec_ovhd_strings[fec_line], 
            ten_hl_config_traffic_types_strings[traffic_type_client],
            sysclk, 
            tcm_line, 
            ten_10ge_tc_frame_format_strings[gfp_frame_format],
            ten_pp10g_flow_mode_strings[flow_ctrl_mode]);





  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                 slice_line,
                                 dyn_repro,
                                 traffic_type_client,
                                 traffic_type_line,
                                 fec_line,
                                 TEN_MAP_BMP,
                                 TEN_MAP_DONT_CARE,        /* odtu mapping not applicable */
                                 8,
                                 255,
                                 TEN_OTU_TERM_TRANSPARENT,
                                 tcm_line);

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 0,                       /* Force a N10G block reset on client side */
                                 traffic_type_client,
                                 traffic_type_client,
                                 TEN_FEC_MODE_NOFEC,
                                 TEN_MAP_BMP,
                                 TEN_MAP_DONT_CARE,        /* odtu mapping not applicable */
                                 8,
                                 255,
                                 TEN_OTU_TERM_TRANSPARENT,
                                 0);

  hsif_is_xaui = ten_hsif_is_xaui_active (module_id_client, slice_client);

  rtn |= ten_hl_pp10g_config_t41 (module_id_line,
                                  slice_line,
                                  traffic_type_client,
                                  traffic_type_line,
                                  sysclk,
                                  flow_ctrl_mode,
                                  gfp_frame_format,
                                  hsif_is_xaui);


  rtn |= ten_hl_pp10g_config_t41 (module_id_client,
                                  slice_client,
                                  traffic_type_client,
                                  traffic_type_client,
                                  sysclk,
                                  flow_ctrl_mode,
                                  gfp_frame_format,
                                  hsif_is_xaui);

  ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, traffic_type_client);

  /* N10G table is overwriting scrambler bits in N10G, so FEC must be provisioned on line this table usage can be removed */
  /*if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {*/  /* Bugzilla 28474 */
    /* Provision FEC and frame size */
    rtn |= ten_hl_config_fec_t41 (module_id_line, slice_line, TEN_SLICE_10G, fec_line);
    
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE TO OTU3V              */
/*                 40G MUXPONDER                                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge_otu3v_t41 (cs_uint16 module_id_line,
                                        cs_uint16 slice_line,
                                        cs_uint16 slice_client,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 fec_line,
                                        cs_uint16 traffic_type_client,
                                        cs_uint16 sysclk,
                                        cs_uint16 tcm_line,
                                        cs_uint16 mld_line,
                                        cs_uint16 map_odtu,
                                        cs_uint16 map_oxuv,
                                        cs_uint16 timeslots,
                                        cs_uint16 gfp_frame_format,
                                        cs_uint16 flow_ctrl_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o System Clock                                  */
/*              o TCM Line                                      */
/*              o MLD Line                                      */
/*              o Mapping Method ODTU                           */
/*              o Mapping Method OXUV                           */
/*              o Timeslots                                     */
/*              o GMP Fame Format                               */
/*              o Flow Control Mode                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures 10GE on the client side into OTU3V on line side.  */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [slice_line] parameter specifies line's slice:               */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [slice_client] parameter specifies client's slice:           */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] parameter specifies the traffic type of  */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 34                               */
/*   TEN_TRAFFIC_TYPE_OTU3E4 = 55                               */
/*                                                              */
/* [fec_line] parameter defines the line fec type:              */
/*   TEN_FEC_MODE_OTUkV             = 0  (7  %)                 */
/*   TEN_FEC_MODE_OTUkV_262         = 1  (10 %)                 */
/*   TEN_FEC_MODE_OTUkV_273         = 2  (15 %)                 */
/*   TEN_FEC_MODE_OTUkV_285         = 3  (20 %)                 */
/*   TEN_FEC_MODE_OTUkV_297         = 4  (25 %)                 */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5  (25 %)                 */
/*   TEN_FEC_MODE_OTUkV_301         = 6  (26 %)                 */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7  (7  %)                 */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8  (7  %)                 */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9  (3.4%)                 */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10 (4.2%)                 */
/*   TEN_FEC_MODE_OTUkV_267         = 11 (12 %)                 */
/*   TEN_FEC_MODE_OTUkV_270         = 12 (13 %)                 */
/*   TEN_FEC_MODE_GFEC              = 13 (7  %)                 */
/*   TEN_FEC_MODE_ZEROFEC           = 14                        */
/*   TEN_FEC_MODE_NOFEC             = 15                        */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*                                                              */
/* [traffic_type_client] parameter specifies the traffic type   */
/* of the client:                                               */
/*   TEN_TRAFFIC_TYPE_10GE_WAN             = 9                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2             = 10                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1             = 11                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3             = 12                 */
/*   TEN_TRAFFIC_TYPE_10GE_6_1             = 26                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_2             = 27                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28                 */
/*   TEN_TRAFFIC_TYPE_1GE                  = 63                 */
/*                                                              */
/* [sysclk] parameter specifies the sysclk frequency in MHz.    */
/*   For example, 400.                                          */
/*                                                              */
/* The [tcm_line] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [mld_line] parameter enables distributing data across    */
/* multiple lanes on line side i.e. OTL3.4                      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_odtu] parameter specifies the client mapping method */
/*   TEN_MAP_AMP_DT        = 2                                  */
/*   TEN_MAP_AMP_PROP      = 3                                  */
/*   TEN_MAP_AMP_PROP_DT   = 4                                  */
/*   TEN_MAP_GMP_HO        = 6                                  */
/*   TEN_MAP_GMP_HO_DT     = 7                                  */
/*                                                              */
/* The [map_oxuv] parameter specifies the client mapping method */
/*   TEN_MAP_BMP           = 1                                  */
/*   TEN_MAP_AMP_DT        = 2                                  */
/*   TEN_MAP_AMP_PROP      = 3                                  */
/*   TEN_MAP_AMP_PROP_DT   = 4                                  */
/*   TEN_MAP_GMP_HO        = 6                                  */
/*   TEN_MAP_GMP_HO_DT     = 7                                  */
/*                                                              */
/* The [timeslots] parameter specifies number of timeslots.     */
/* Bandwidth for map_proc = GMP_HO is always 1.25G per timeslot.*/
/*   timeslots = 1 - 8                                          */
/* Bandwidth for map_proc = AMP or AMP_DT is as follows:        */
/*   timeslots = 4 for 2.5G per timeslot                        */
/*   timeslots = 8 for 1.25G per timeslot                       */
/* Bandwidth for all other map_proc is 2.5G so timeslots = 4    */
/*                                                              */
/* The [gfp_frame_format] parameter specifies the GFP frame     */
/* format                                                       */
/*   TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4  = 0                      */
/*   TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4 = 1                      */
/*   TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC = 2                      */
/*   TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC = 3                      */
/*                                                              */
/* The [flow_ctrl_mode] parameter specifies the flow control    */
/* mode                                                         */
/*   TEN_PP10G_FLOW_GFP_S_P         = 0                         */
/*   TEN_PP10G_FLOW_GFP_S           = 1                         */
/*   TEN_PP10G_FLOW_ETH_4           = 2 (Reactive)              */
/*   TEN_PP10G_FLOW_ETH_4_P         = 3 (Premptive)             */
/*   TEN_PP10G_FLOW_MAX_MODE        = 4                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint16 module_id_client;
  cs_uint16 hsif_is_xaui;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_10ge_otu3v_t41";  

  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);

  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_line %d out of range.  s/b 0..3.", func, slice_line);
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_client %d out of range.  s/b 0..3.", func, slice_client);
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E2) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E4) &&   /* Bugzilla 28237 */
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P2)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 1, 2, 3, 25, 37, 55.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if ((traffic_type_client != TEN_TRAFFIC_TYPE_10GE_WAN) && (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_6_2) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) && (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_7_1) && (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_7_2) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_7_3) && (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_6_1) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_1GE)) { /* Bugzilla 38871 */
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 9, 10, 11, 12, 26, 27, 28, 30.", func, traffic_type_client);
    return (CS_ERROR);
  }

  if (tcm_line & ~0x7E) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_line 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_line);
    return(CS_ERROR);
  }

  if (mld_line > 1) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() mld_line %d out of range.  s/b 0..1.", func, mld_line);
    return (CS_ERROR);
  }

  /* first and second level mapping checks need to be done here ! */

  if ((map_odtu == TEN_MAP_GMP_HO) || (map_odtu == TEN_MAP_GMP_HO_DT)) {
    if ((timeslots > 8) || (timeslots < 1)) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 1..8.", func, timeslots);
      return (CS_ERROR);
    }
  }
  else if ((map_odtu == TEN_MAP_AMP) || (map_odtu == TEN_MAP_AMP_DT) || (map_odtu == TEN_MAP_AMP_PROP)) {  /* Bugzilla 28237 */
    if ((timeslots != 4) && (timeslots != 8)) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 1..8.", func, timeslots);
      return (CS_ERROR);
    }
  } else {
    /*if (timeslots != 4){                                                                                                          */
    /*  CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 16 or 32.", func, timeslots);*/
    /*  return (CS_ERROR);                                                                                                          */
    /*}                                                                                                                             */
    /* All other mapping procedures have 2.5G time slots */
    timeslots = 4;
  }  

  if ((gfp_frame_format != TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4) && (gfp_frame_format != TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4) && 
       (gfp_frame_format != TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC) && (gfp_frame_format != TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC)) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() gfp_frame_format %d out of range.  s/b 0..3.", func, gfp_frame_format);
    return(CS_ERROR);
  }

  if ((flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S_P) && (flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S) &&
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P) &&
      (flow_ctrl_mode != TEN_PP10G_FLOW_MAX_MODE)) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() flow_ctrl_mode %d out of range.  s/b 0..4.", func, flow_ctrl_mode);
    return(CS_ERROR);
  }

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line %s, %s, %s  \n",  ten_module_strings[module_id_line&1], ten_slice_strings[slice_line], ten_hl_config_traffic_types_strings[traffic_type_line]);
  CS_PRINT("    client  %s, %s\n", ten_hl_config_traffic_types_strings[traffic_type_client], ten_slice_strings[slice_client]);
  CS_PRINT("    %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    %s\n", ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("    sysclk=%d\n", sysclk);
  CS_PRINT("    tcm_line=0x%X\n", tcm_line);
  CS_PRINT("    mld_line=%d\n", mld_line);
  if (map_odtu <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_odtu=%s\n", ten_sync_type_strings[map_odtu]);
  }
  else {
    CS_PRINT("    map_odtu=%d\n", map_odtu);
  }
  if (map_oxuv <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_oxuv=%s\n", ten_sync_type_strings[map_oxuv]);
  }
  else {
    CS_PRINT("    map_oxuv=%d\n", map_oxuv);
  }
  CS_PRINT("    timeslots=0x%X\n", timeslots);
  CS_PRINT("    %s\n", ten_10ge_tc_frame_format_strings[gfp_frame_format]);
  CS_PRINT("    %s\n", ten_pp10g_flow_mode_strings[flow_ctrl_mode]);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);

  module_id_client = module_id_line ^ TEN_MODULE_B;

  rtn |= ten_hl_n40g_config_mux_t41 (module_id_line,      
                                     traffic_type_client,
                                     traffic_type_line,
                                     fec_line,
                                     slice_line,     
                                     dyn_repro,            
                                     map_odtu, /*map_oxuv,*/
                                     timeslots,             
                                     255,     
                                     0,            
                                     tcm_line,              
                                     mld_line);             

  if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {
    /* Enable the N10G and configure it for bypass */
    rtn |= ten_hl_n40g_config (module_id_client, TEN_N40G_RX_BYPASS_SNT_MON, TEN_N40G_TX_DISABLE);

    rtn |= ten_mpif_global_clock_disable_n40g_n10g (dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, TEN_MPIF_N40G_DATAPATH, CS_TX_AND_RX, CS_ENABLE);
  }

  rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                 slice_line,
                                 dyn_repro,
                                 traffic_type_client,
                                 TEN_TRAFFIC_TYPE_ODTU,
                                 TEN_FEC_MODE_NOFEC,   /* FEC done in N40G */
                                 map_oxuv,             /* OTU2 mapping */
                                 map_odtu,             /* OTU3 mapping */
                                 timeslots,
                                 255,
                                 0,
                                 tcm_line);

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 0,                       /* Force a N10G block reset on client side */
                                 traffic_type_client,
                                 traffic_type_client,
                                 TEN_FEC_MODE_NOFEC,
                                 map_oxuv,
                                 TEN_MAP_DONT_CARE,                  /* odtu mapping not applicable on client side*/
                                 timeslots,
                                 255,
                                 0,
                                 tcm_line);

  hsif_is_xaui = ten_hsif_is_xaui_active (module_id_client, slice_client);

  rtn |= ten_hl_pp10g_config_t41 (module_id_line,
                                  slice_line,
                                  traffic_type_client,
                                  TEN_TRAFFIC_TYPE_ODTU,
                                  sysclk,
                                  flow_ctrl_mode,
                                  gfp_frame_format,
                                  hsif_is_xaui);

  rtn |= ten_hl_pp10g_config_t41 (module_id_client,
                                  slice_client,
                                  traffic_type_client,
                                  traffic_type_client,
                                  sysclk,
                                  flow_ctrl_mode,
                                  gfp_frame_format,
                                  hsif_is_xaui);

  /*rtn |= ten_hl_oc192_termination (module_id_line, module_id_client, term_oc192);*/
  rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, traffic_type_client);

  if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {
    /* Provision FEC and frame size */
    rtn |= ten_hl_config_fec_t41 (module_id_line, 0, TEN_SLICE_40G, fec_line);
  }

  if (rtn != CS_OK) {
    CS_PRINT("%s()  FAILED!\n", func);
  }

  return (rtn);
}

/* Bugzilla 29991 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE TO OC192              */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_10ge_t41(cs_uint16 module_id_line,
                                       cs_uint16 slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint16 slice_client,
                                       cs_uint16 dyn_repro,
                                       cs_uint16 traffic_type_line,
                                       cs_uint16 traffic_type_client,
                                       cs_uint16 gfp_frame_format,
                                       cs_uint16 flow_ctrl_mode,
                                       cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o Traffic Type Client                           */
/*              o GFP Frame Format                              */
/*              o Flow Control Mode                             */
/*              o System Clock                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures 10GE on the client side into OC192 on line side.  */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [slice_line] parameter specifies line's slice:               */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [module_id_client] parameter specifies client’s module ID    */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */ 
/*                                                              */
/* [slice_client] parameter specifies client's slice:           */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] parameter specifies the traffic type of  */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OC192 = 8                                 */
/*                                                              */
/* [traffic_type_client] parameter specifies the traffic type   */
/* of the client:                                               */
/*   TEN_TRAFFIC_TYPE_10GE  = 20                                */
/*                                                              */
/* [gfp_frame_format] specifies the GFP frame format            */
/*   0 = TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4                       */
/*   1 = TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4                      */
/*   2 = TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC                      */
/*   3 = TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC                      */
/*                                                              */
/* The [flow_ctrl_mode] parameter specifies the flow control    */
/* mode                                                         */
/*   TEN_PP10G_FLOW_GFP_S_P         = 0                         */
/*   TEN_PP10G_FLOW_GFP_S           = 1                         */
/*   TEN_PP10G_FLOW_ETH_4           = 2 (Reactive)              */
/*   TEN_PP10G_FLOW_ETH_4_P         = 3 (Premptive)             */
/*   TEN_PP10G_FLOW_MAX_MODE        = 4                         */
/*                                                              */
/* [sysclk] parameter specifies the sysclk frequency in MHz.    */
/*   For example, 400.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint16 hsif_is_xaui;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_oc192_10ge_t41";  
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);

  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE (module_id_client, pDev, CS_ERROR);

  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_line %d out of range.  s/b 0..3.", func, slice_line);
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_client %d out of range.  s/b 0..3.", func, slice_client);
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if (traffic_type_line != TEN_TRAFFIC_TYPE_OC192) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 8.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_GFPF) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 56.", func, traffic_type_client);
    return (CS_ERROR);
  }

  if ((gfp_frame_format != TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4) && (gfp_frame_format != TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4) && 
       (gfp_frame_format != TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC) && (gfp_frame_format != TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC)) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() gfp_frame_format %d out of range.  s/b 0..3.", func, gfp_frame_format);
    return(CS_ERROR);
  }

  if ((flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S_P) && (flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S) &&
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P) &&
      (flow_ctrl_mode != TEN_PP10G_FLOW_MAX_MODE)) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() flow_ctrl_mode %d out of range.  s/b 0..4.", func, flow_ctrl_mode);
    return(CS_ERROR);
  }
           

  CS_PRINT("%s() \n", func);
  CS_PRINT("    line %s, %s, %s\n", ten_module_strings[module_id_line&1], ten_slice_strings[slice_line], ten_hl_config_traffic_types_strings[traffic_type_line]);
  CS_PRINT("    client %s, %s, %s\n", ten_module_strings[module_id_client&1], ten_slice_strings[slice_client], ten_hl_config_traffic_types_strings[traffic_type_client]);
  CS_PRINT("    %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    sysclk=%d\n", sysclk);
  CS_PRINT("    %s\n", ten_10ge_tc_frame_format_strings[gfp_frame_format]);
  CS_PRINT("    %s\n", ten_pp10g_flow_mode_strings[flow_ctrl_mode]);
            
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                 slice_line,
                                 dyn_repro,
                                 traffic_type_client,
                                 traffic_type_line,
                                 TEN_FEC_MODE_NOFEC,
                                 TEN_MAP_BMP,
                                 TEN_MAP_DONT_CARE,        /* odtu mapping not applicable */
                                 8,
                                 255,
                                 TEN_OTU_TERM_TRANSPARENT,
                                 0);

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 0,                       /* Force a N10G block reset on client side */
                                 traffic_type_client,
                                 traffic_type_client,
                                 TEN_FEC_MODE_NOFEC,
                                 TEN_MAP_BMP,
                                 TEN_MAP_DONT_CARE,        /* odtu mapping not applicable */
                                 8,
                                 255,
                                 TEN_OTU_TERM_TRANSPARENT,
                                 0);

  hsif_is_xaui = ten_hsif_is_xaui_active (module_id_client, slice_client);

  rtn |= ten_hl_pp10g_config_t41 (module_id_line,
                                  slice_line,
                                  traffic_type_client,
                                  traffic_type_line,
                                  sysclk,
                                  flow_ctrl_mode,
                                  gfp_frame_format,
                                  hsif_is_xaui);


  rtn |= ten_hl_pp10g_config_t41 (module_id_client,
                                  slice_client,
                                  traffic_type_client,
                                  traffic_type_client,
                                  sysclk,
                                  flow_ctrl_mode,
                                  gfp_frame_format,
                                  hsif_is_xaui);

  rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, traffic_type_client);

  return (rtn);
}

/* Bugzilla 29991 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE TO OTU2V UFEC SFI4.1  */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge_otu2v_ufec_sfi41_t41(cs_uint16 dev_id,
                                                  cs_uint16 dyn_repro,
                                                  cs_uint16 traffic_type_line,
                                                  cs_uint16 fec_line,
                                                  cs_uint16 traffic_type_client,
                                                  cs_uint16 sysclk,
                                                  cs_uint16 tcm_line,
                                                  cs_uint16 gfp_frame_format,
                                                  cs_uint16 flow_ctrl_mode)
/* INPUTS     : o Device Id                                     */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o System Clock                                  */
/*              o TCM Line                                      */
/*              o GFP Frame Format                              */
/*              o Flow Control Mode                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures 10GE on the client side into OTU2V on line side   */
/* with UFEC on SFI 4.1                                         */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] parameter specifies the traffic type of  */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                 */
/*   TEN_TRAFFIC_TYPE_OTU1E = 29                                */
/*                                                              */
/* [fec_line] parameter defines the line fec type:              */
/*   TEN_FEC_MODE_OTUkV             = 0  (7  %)                 */
/*   TEN_FEC_MODE_OTUkV_262         = 1  (10 %)                 */
/*   TEN_FEC_MODE_OTUkV_273         = 2  (15 %)                 */
/*   TEN_FEC_MODE_OTUkV_285         = 3  (20 %)                 */
/*   TEN_FEC_MODE_OTUkV_297         = 4  (25 %)                 */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5  (25 %)                 */
/*   TEN_FEC_MODE_OTUkV_301         = 6  (26 %)                 */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7  (7  %)                 */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8  (7  %)                 */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9  (3.4%)                 */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10 (4.2%)                 */
/*   TEN_FEC_MODE_OTUkV_267         = 11 (12 %)                 */
/*   TEN_FEC_MODE_OTUkV_270         = 12 (13 %)                 */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*                                                              */
/* [traffic_type_client] parameter specifies the traffic type   */
/* of the client:                                               */
/*   TEN_TRAFFIC_TYPE_10GE_7_1             = 11                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_2             = 27                 */
/*                                                              */
/* [sysclk] parameter specifies the sysclk frequency in MHz.    */
/*   For example, 400.                                          */
/*                                                              */
/* The [tcm_line] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* [gfp_frame_format] specifies the GFP frame format            */
/*   0 = TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4                       */
/*   1 = TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4                      */
/*   2 = TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC                      */
/*   3 = TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC                      */
/*                                                              */
/* The [flow_ctrl_mode] parameter specifies the flow control    */
/* mode                                                         */
/*   TEN_PP10G_FLOW_GFP_S_P         = 0                         */
/*   TEN_PP10G_FLOW_GFP_S           = 1                         */
/*   TEN_PP10G_FLOW_ETH_4           = 2 (Reactive)              */
/*   TEN_PP10G_FLOW_ETH_4_P         = 3 (Premptive)             */
/*   TEN_PP10G_FLOW_MAX_MODE        = 4                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
    cs_uint16 module_id_line=0;
    cs_uint16 slice_line;
    cs_uint16 module_id_client=1;
    cs_uint16 slice_client;
    cs_uint16 module_id_line_int;
    cs_uint16 slice_line_int;
    cs_uint16 module_id_client_int;
    cs_uint16 slice_client_int;
    cs_uint16 hsif_is_xaui;

    T41_t *pDev = NULL;
    cs_status rtn = CS_OK;
    cs_char8 *func = "ten_hl_config_10ge_otu2v_t41";  

    TEN_MOD_COMMON_VALIDATE (dev_id, pDev, CS_ERROR); /* Bugzilla 35949 */

    if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
        CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
        return (CS_ERROR);
    }

    if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU2E) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU1E)) {
        CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 5, 6, 29.", func, traffic_type_line);
        return (CS_ERROR);
    }

    if((fec_line == TEN_FEC_MODE_GFEC) || (fec_line == TEN_FEC_MODE_ZEROFEC) || (fec_line == TEN_FEC_MODE_NOFEC))  {
        CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d must be UFEC.  s/b 0..15.", func, fec_line);
        return (CS_ERROR);
    }

    if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
        CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
        return (CS_ERROR);
    }

    if ((traffic_type_client != TEN_TRAFFIC_TYPE_10GE_7_1) && (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_7_2)) {
        CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 9, 10, 11, 12, 26, 27, 28, 30, 33.", func, traffic_type_client);
        return (CS_ERROR);
    }

    if (tcm_line & ~0x7E) {
        CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_line 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_line);
        return(CS_ERROR);
    }

    if ((gfp_frame_format != TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4) && (gfp_frame_format != TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4) && 
        (gfp_frame_format != TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC) && (gfp_frame_format != TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC)) {
        CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() gfp_frame_format %d out of range.  s/b 0..3.", func, gfp_frame_format);
        return(CS_ERROR);
    }

    if ((flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S_P) && (flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S) &&
        (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P) &&
        (flow_ctrl_mode != TEN_PP10G_FLOW_MAX_MODE)) {
        CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() flow_ctrl_mode %d out of range.  s/b 0..4.", func, flow_ctrl_mode);
        return(CS_ERROR);
    }

    CS_PRINT("%s() %s, %s, %s, %s, sysclk=%d, tcm_line=0x%X, %s, %s\n",
            func,
            ten_hl_config_dyn_repro_strings[dyn_repro],
            ten_hl_config_traffic_types_strings[traffic_type_line], 
            ten_fec_ovhd_strings[fec_line], 
            ten_hl_config_traffic_types_strings[traffic_type_client],
            sysclk, 
            tcm_line, 
            ten_10ge_tc_frame_format_strings[gfp_frame_format],
            ten_pp10g_flow_mode_strings[flow_ctrl_mode]);


    /******************** First Path *********************/
    module_id_line = 0;          /* A0 */
    slice_line = 0;
    module_id_client = 1;        /* B1 */
    slice_client = 1;
      
    /*rtn |= ten_hl_config_10ge_otu2v_t41(module_id_line,
                                slice_line,
                                module_id_client,
                                slice_client,
                                dyn_repro,
                                traffic_type_line,
                                fec_line,
                                traffic_type_client,
                                sysclk,
                                tcm_line,
                                gfp_frame_format,
                                flow_ctrl_mode);*/

    rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                   slice_line,
                                   dyn_repro,
                                   traffic_type_client,
                                   traffic_type_line,
                                   fec_line,
                                   TEN_MAP_BMP,
                                   TEN_MAP_DONT_CARE,        /* odtu mapping not applicable */
                                   8,
                                   255,
                                   TEN_OTU_TERM_TRANSPARENT,
                                   tcm_line);
    
    rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                   slice_client,
                                   0,                       /* Force a N10G block reset on client side */
                                   traffic_type_client,
                                   traffic_type_client,
                                   TEN_FEC_MODE_NOFEC,
                                   TEN_MAP_BMP,
                                   TEN_MAP_DONT_CARE,        /* odtu mapping not applicable */
                                   8,
                                   255,
                                   TEN_OTU_TERM_TRANSPARENT,
                                   0);
    
    hsif_is_xaui = ten_hsif_is_xaui_active (module_id_client, slice_client);
    
    rtn |= ten_hl_pp10g_config_t41 (module_id_line,
                                    slice_line,
                                    traffic_type_client,
                                    traffic_type_line,
                                    sysclk,
                                    flow_ctrl_mode,
                                    gfp_frame_format,
                                    hsif_is_xaui);


    rtn |= ten_hl_pp10g_config_t41 (module_id_client,
                                    slice_client,
                                    traffic_type_client,
                                    traffic_type_client,
                                    sysclk,
                                    flow_ctrl_mode,
                                    gfp_frame_format,
                                    hsif_is_xaui);

    /*ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, traffic_type_client);*/

    /* rtn |= ten_hl_config_fec_t41 (module_id_line, slice_line, TEN_SLICE_10G, fec_line); */

    /***** A0 - Line TX/RX bypass *****/
    rtn |= ten_hl_n10g_config (module_id_line, 
                               slice_line, 
                               TEN_N10G_RX_BYPASS, 
                               TEN_N10G_TX_BYPASS, 
                               dyn_repro);

    rtn |= ten_hl_pp10g_config (module_id_line, 
                                slice_line,  
                                TEN_PP10G_RX_DISABLE,
                                TEN_PP10G_TX_DISABLE);

    /******************** Second Path *********************/                                
    module_id_line_int = 0;      /* A2 */
    slice_line_int = 2;
    module_id_client_int = 0;    /* A1 */
    slice_client_int = 1;
    
    /***** A2 *****/
    if(traffic_type_line == TEN_TRAFFIC_TYPE_OTU2E) { 
        rtn |= ten_hl_n10g_config (module_id_line_int, 
                                   slice_line_int, 
                                   TEN_N10G_RX_BYPASS, 
                                   TEN_N10G_TX_10GE_OTU2E, 
                                   dyn_repro);
    }
    else {
        rtn |= ten_hl_n10g_config (module_id_line_int, 
                                   slice_line_int, 
                                   TEN_N10G_RX_BYPASS, 
                                   TEN_N10G_TX_10GE_OTU1E, 
                                   dyn_repro);
    }

    rtn |= ten_hl_pp10g_config (module_id_line_int, 
                                slice_line_int, 
                                TEN_PP10G_RX_DISABLE, 
                                TEN_PP10G_TX_ETH_0);

    rtn |= ten_hl_config_fec_t41 (module_id_line_int, slice_line_int, TEN_SLICE_10G, fec_line);

    /***** A1 *****/
    if(traffic_type_line == TEN_TRAFFIC_TYPE_OTU2E) { 
        rtn |= ten_hl_n10g_config (module_id_client_int, 
                                   slice_client_int, 
                                   TEN_N10G_RX_OTU2E_10GE, 
                                   TEN_N10G_TX_BYPASS, 
                                   dyn_repro);
    }
    else {
        rtn |= ten_hl_n10g_config (module_id_client_int, 
                                   slice_client_int, 
                                   TEN_N10G_RX_OTU1E_10GE, 
                                   TEN_N10G_TX_BYPASS, 
                                   dyn_repro);
    }

    rtn |= ten_hl_pp10g_config (module_id_client_int, 
                                slice_client_int, 
                                TEN_PP10G_RX_ETH_0,
                                TEN_PP10G_TX_DISABLE);

    rtn |= ten_hl_config_fec_t41 (module_id_client_int, slice_client_int, TEN_SLICE_10G, fec_line);
    
    /******************** Setup cross connects ********************/
    ten_hl_xcon_config (dev_id, 
                        (module_id_line_int & 1) * 4 + slice_line_int,
                        (module_id_client & 1) * 4 + slice_client,
                        traffic_type_client);

    ten_hl_xcon_config (dev_id, 
                        (module_id_client_int & 1) * 4 + slice_client_int,
                        (module_id_line & 1) * 4 + slice_line,
                        traffic_type_client);

    rtn |= ten_xcon_es_select_source(dev_id,                                              /* 2=7 */
                                     (module_id_line_int & 1) * 4 + slice_line_int,     
                                     (module_id_client & 1) * 4 + slice_client,
                                     XCON_N10G);

    rtn |= ten_xcon_es_select_source(dev_id,                                              /* 0=2 */
                                     (module_id_line & 1) * 4 + slice_line,
                                     (module_id_line_int & 1) * 4 + slice_line_int,
                                     XCON_N10G);

    rtn |= ten_xcon_es_select_source(dev_id,                                              /* 1=0 */
                                     (module_id_client_int & 1) * 4 + slice_client_int,
                                     (module_id_line & 1) * 4 + slice_line,
                                     XCON_N10G);

    rtn |= ten_xcon_es_select_source(dev_id,                                              /* 7=1 */
                                     (module_id_client & 1) * 4 + slice_client,
                                     (module_id_client_int & 1) * 4 + slice_client_int,
                                     XCON_N10G);

    return (rtn);
}

/* Bugzilla 37022 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG TRAFFIC TYPE RA TO SAME    */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_traffic_type_ra_same(cs_uint16 module_id_line,
                                             cs_uint16 slice_line,
                                             cs_uint16 module_id_client,
                                             cs_uint16 slice_client,
                                             cs_uint16 dyn_repro,
                                             cs_uint16 traffic_type,
                                             cs_uint16 sysclk,
                                             cs_uint16 gfp_frame_format,
                                             cs_uint16 flow_ctrl_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type                                  */
/*              o System Clock                                  */
/*              o GFP Frame Format                              */
/*              o Flow Control Mode                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures 10GE on the client side into OTU2V on line side.  */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [slice_line] parameter specifies line's slice:               */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [module_id_client] parameter specifies client’s module ID    */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */ 
/*                                                              */
/* [slice_client] parameter specifies client's slice:           */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type          */
/*   TEN_TRAFFIC_TYPE_10GE_RA              = 30                 */
/*                                                              */
/* [sysclk] parameter specifies the sysclk frequency in MHz.    */
/*   For example, 400.                                          */
/*                                                              */
/* [gfp_frame_format] specifies the GFP frame format            */
/*   0 = TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4                       */
/*   1 = TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4                      */
/*   2 = TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC                      */
/*   3 = TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC                      */
/*                                                              */
/* The [flow_ctrl_mode] parameter specifies the flow control    */
/* mode                                                         */
/*   TEN_PP10G_FLOW_GFP_S_P         = 0                         */
/*   TEN_PP10G_FLOW_GFP_S           = 1                         */
/*   TEN_PP10G_FLOW_ETH_4           = 2 (Reactive)              */
/*   TEN_PP10G_FLOW_ETH_4_P         = 3 (Premptive)             */
/*   TEN_PP10G_FLOW_MAX_MODE        = 4                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint16 hsif_is_xaui;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_traffic_type_ra_same";  
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);

  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE (module_id_client, pDev, CS_ERROR);

  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_line %d out of range.  s/b 0..3.", func, slice_line);
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_client %d out of range.  s/b 0..3.", func, slice_client);
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if  (traffic_type != TEN_TRAFFIC_TYPE_10GE_RA) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 30.", func, traffic_type);
    return (CS_ERROR);
  }

  if ((gfp_frame_format != TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4) && (gfp_frame_format != TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4) && 
       (gfp_frame_format != TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC) && (gfp_frame_format != TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC)) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() gfp_frame_format %d out of range.  s/b 0..3.", func, gfp_frame_format);
    return(CS_ERROR);
  }

  if ((flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S_P) && (flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S) &&
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P) &&
      (flow_ctrl_mode != TEN_PP10G_FLOW_MAX_MODE)) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() flow_ctrl_mode %d out of range.  s/b 0..4.", func, flow_ctrl_mode);
    return(CS_ERROR);
  }
  CS_PRINT("%s() %s, slice_line=%d, %s, slice_client=%d, %s, %s, sysclk=%d, %s, %s\n",
            func,
            ten_module_strings[module_id_line&1], 
            slice_line, 
            ten_module_strings[module_id_client&1], 
            slice_client, 
            ten_hl_config_dyn_repro_strings[dyn_repro],
            ten_hl_config_traffic_types_strings[traffic_type], 
            sysclk, 
            ten_10ge_tc_frame_format_strings[gfp_frame_format],
            ten_pp10g_flow_mode_strings[flow_ctrl_mode]);


  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                 slice_line,
                                 dyn_repro,
                                 traffic_type,
                                 traffic_type,
                                 TEN_FEC_MODE_NOFEC,
                                 TEN_MAP_BMP,
                                 TEN_MAP_DONT_CARE,        /* odtu mapping not applicable */
                                 8,
                                 255,
                                 TEN_OTU_TERM_TRANSPARENT,
                                 0);

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 0,                       /* Force a N10G block reset on client side */
                                 traffic_type,
                                 traffic_type,
                                 TEN_FEC_MODE_NOFEC,
                                 TEN_MAP_BMP,
                                 TEN_MAP_DONT_CARE,        /* odtu mapping not applicable */
                                 8,
                                 255,
                                 TEN_OTU_TERM_TRANSPARENT,
                                 0);

  hsif_is_xaui = ten_hsif_is_xaui_active (module_id_client, slice_client);

  rtn |= ten_hl_pp10g_config_t41 (module_id_line,
                                  slice_line,
                                  traffic_type,
                                  traffic_type,
                                  sysclk,
                                  flow_ctrl_mode,
                                  gfp_frame_format,
                                  hsif_is_xaui);

  rtn |= ten_hl_pp10g_config_t41 (module_id_client,
                                  slice_client,
                                  traffic_type,
                                  traffic_type,
                                  sysclk,
                                  flow_ctrl_mode,
                                  gfp_frame_format,
                                  hsif_is_xaui);

  ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, traffic_type);
    
  return (rtn);
}
/* Bugzilla 37022 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE6_1 TO OC192           */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge6_1_oc192_t41(cs_uint16 module_id_line,
                                          cs_uint16 slice_line,
                                          cs_uint16 module_id_client,
                                          cs_uint16 slice_client,
                                          cs_uint16 dyn_repro,
                                          cs_uint16 traffic_type_line,
                                          cs_uint16 traffic_type_client,
                                          cs_uint16 sysclk,
                                          cs_uint16 flow_ctrl_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o Traffic Type Client                           */
/*              o System Clock                                  */
/*              o Flow Control Mode                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures 10GE6.1 on the client side into OC192/10GE_WAN    */ 
/* on line side.                                                */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device.                     */
/* The registered device is identified by the dev_id bits       */
/* specified below:                                             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [slice_line] parameter specifies line's slice:               */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [module_id_client] parameter specifies client’s module ID    */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device.                     */
/* The registered device is identified by the dev_id bits       */
/* specified below:                                             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */ 
/*                                                              */
/* [slice_client] parameter specifies client's slice:           */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] parameter specifies the traffic type of  */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OC192 = 8                                 */
/*                                                              */
/* [traffic_type_client] parameter specifies the traffic type   */
/* of the client:                                               */
/*   TEN_TRAFFIC_TYPE_10GE_6_1             = 26                 */
/*                                                              */
/* [sysclk] parameter specifies the sysclk frequency in MHz.    */
/*   For example, 400.                                          */
/*                                                              */
/* The [flow_ctrl_mode] parameter specifies the flow control    */
/* mode                                                         */
/*   TEN_PP10G_FLOW_GFP_S_P         = 0                         */
/*   TEN_PP10G_FLOW_GFP_S           = 1                         */
/*   TEN_PP10G_FLOW_ETH_4           = 2 (Reactive)              */
/*   TEN_PP10G_FLOW_ETH_4_P         = 3 (Premptive)             */
/*   TEN_PP10G_FLOW_MAX_MODE        = 4                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint16 hsif_is_xaui;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_10ge6_1_into_oc192_t41";  
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);

  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE (module_id_client, pDev, CS_ERROR);

  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_line %d out of range.  s/b 0..3.", func, slice_line);
    return (CS_ERROR);
  }

  if (slice_client >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() slice_client %d out of range.  s/b 0..3.", func, slice_client);
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if (traffic_type_line != TEN_TRAFFIC_TYPE_OC192) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b OC192.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (traffic_type_client != TEN_TRAFFIC_TYPE_10GE_6_1) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 10ge6_1.", func, traffic_type_client);
    return (CS_ERROR);
  }

  if ((flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S_P) && (flow_ctrl_mode != TEN_PP10G_FLOW_GFP_S) &&
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P) &&
      (flow_ctrl_mode != TEN_PP10G_FLOW_MAX_MODE)) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() flow_ctrl_mode %d out of range.  s/b 0..4.", func, flow_ctrl_mode);
    return(CS_ERROR);
  }
  CS_PRINT("%s() %s, slice_line=%d, %s, slice_client=%d, %s, %s, %s, sysclk=%d, %s\n",
            func,
            ten_module_strings[module_id_line&1], 
            slice_line, 
            ten_module_strings[module_id_client&1], 
            slice_client, 
            ten_hl_config_dyn_repro_strings[dyn_repro],
            ten_hl_config_traffic_types_strings[traffic_type_line], 
            ten_hl_config_traffic_types_strings[traffic_type_client],
            sysclk, 
            ten_pp10g_flow_mode_strings[flow_ctrl_mode]);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  rtn |= ten_hl_n10g_config_t41(module_id_line, 
                                slice_line,
                                dyn_repro,
                                traffic_type_client,
                                traffic_type_line,
                                TEN_FEC_MODE_NOFEC,
                                TEN_MAP_BMP,
                                TEN_MAP_DONT_CARE,        /* odtu mapping not applicable */
                                8,
                                255,
                                TEN_OTU_TERM_TRANSPARENT,
                                0);

  rtn |= ten_hl_n10g_config_t41(module_id_client, 
                                slice_client,
                                0,                       /* Force a N10G block reset on client side */
                                traffic_type_client,
                                traffic_type_client,
                                TEN_FEC_MODE_NOFEC,
                                TEN_MAP_BMP,
                                TEN_MAP_DONT_CARE,        /* odtu mapping not applicable */
                                8,
                                255,
                                TEN_OTU_TERM_TRANSPARENT,
                                0);

  hsif_is_xaui = ten_hsif_is_xaui_active (module_id_client, slice_client);

  rtn |= ten_hl_pp10g_config_t41 (module_id_line,
                                  slice_line,
                                  traffic_type_client,
                                  traffic_type_line,
                                  sysclk,
                                  flow_ctrl_mode,
                                  TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4,
                                  hsif_is_xaui);

  rtn |= ten_hl_pp10g_config_t41 (module_id_client,
                                  slice_client,
                                  traffic_type_client,
                                  traffic_type_client,
                                  sysclk,
                                  flow_ctrl_mode,
                                  TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4,
                                  hsif_is_xaui);

  ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, traffic_type_client);

  return (rtn);
}





