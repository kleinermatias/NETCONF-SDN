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
 * ten_hl_config_fc_t41.c
 *
 * API's for high level Fibre Channel client configuration.
 *
 * $Id: ten_hl_config_fc_t41.c,v 1.42 2013/06/04 17:48:08 khill Exp $
 *
 */
 
#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG FIBER CHANNEL TO OTU2V     */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_fc_otu2v_t41(cs_uint16 module_id_line,
                                     cs_uint16 slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint16 slice_client,
                                     cs_uint16 dyn_repro,
                                     cs_uint16 traffic_type_line,
                                     cs_uint16 fec_line,
                                     cs_uint16 traffic_type_client,
                                     cs_uint16 sysclk,
                                     cs_uint16 tcm_line,
                                     cs_uint16 map_oxuv,
                                     cs_uint16 timeslots,
                                     cs_uint16 gmp_timeslot_mask)
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
/*              o Mapping Method                                */
/*              o Timeslots                                     */
/*              o GMP Timeslot Mask                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures Fiber Channel on the client side into OTU2V on    */
/* line side. Transcode ratio is read from the control block.   */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 - dev_id, Bits 7:1 - don't care, Bit 0 - module  */
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
/* [traffic_type_line] parameter specifies the traffic type     */
/* of the line:                                                 */
/*   TEN_TRAFFIC_TYPE_OTU2  = 5                                 */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                 */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                 */
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
/*                                                              */
/* [traffic_type_client] parameter specifies the traffic type   */
/* of the client:                                               */
/*   TEN_TRAFFIC_TYPE_10GFC                = 13                 */
/*   TEN_TRAFFIC_TYPE_8GFC                 = 14                 */
/*   TEN_TRAFFIC_TYPE_4GFC                 = 15                 */
/*   TEN_TRAFFIC_TYPE_2GFC                 = 16                 */
/*   TEN_TRAFFIC_TYPE_1GFC                 = 17                 */
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
/* The [map_oxuv] parameter specifies the client mapping method */
/*   TEN_MAP_AMP         = 0                                    */
/*   TEN_MAP_BMP         = 1                                    */
/*   TEN_MAP_AMP_PROP    = 3                                    */
/*   TEN_MAP_GMP_LO      = 5                                    */
/*                                                              */
/* The [gmp_timeslots] parameter specifies number of timeslots. */
/* Applicable to GMP_HO only if [map_proc] = TEN_MAP_GMP_HO     */
/* Bandwidth is always 1.25G per timeslot                       */
/*   1 – 8                                                      */
/*                                                              */
/* The [gmp_timeslot_mask] parameter specifies the timeslots to */
/* use for GMP mapping. Applicable to GMP_HO only.              */
/*   Bit 0- Timeslot 1 through Bit 7 – Timeslot 8               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint16 hsif_is_xaui;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_fc_otu2v_t41";
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);


  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE (module_id_client, pDev, CS_ERROR);


  /* Parameter checking */
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

  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU2) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU2E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU1F) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU1E)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 5, 6, 29.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if ((traffic_type_client != TEN_TRAFFIC_TYPE_10GFC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GFC_TC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GFC_TC_G709) && /* Bug 31054 */
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GFC_TC_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_8GFC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_4GFC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_2GFC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_2GISC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_CPRI_4) && /* Bugzilla 39690 */
      (traffic_type_client != TEN_TRAFFIC_TYPE_1GFC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_8GFC_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_4GFC_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_2GFC_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_1GFC_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_8GFC_ENH) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_4GFC_ENH) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_2GFC_ENH) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_1GFC_ENH)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 13, 14, 15.", func, traffic_type_client);
    return (CS_ERROR);
  }

  if (tcm_line & ~0x7E) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_line 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_line);
    return(CS_ERROR);
  }

  if ((map_oxuv != TEN_MAP_AMP) &&
      (map_oxuv != TEN_MAP_BMP) &&
      (map_oxuv != TEN_MAP_AMP_PROP) &&
      (map_oxuv != TEN_MAP_GMP_LO)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_oxuv %d out of range.  s/b 0, 1, 3 or 5.", func, map_oxuv);
    return (CS_ERROR);
  }


  CS_PRINT("%s:  0x%X, %d, 0x%X, %d, dyn=%d, %d, %d, %d, %d, %d, %d, %d, %d\n",
            func,
            module_id_line,	slice_line, module_id_client, slice_client,
            dyn_repro, traffic_type_line, fec_line, traffic_type_client,
            sysclk, tcm_line, map_oxuv, timeslots, gmp_timeslot_mask);


  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                 slice_line,
                                 dyn_repro,
                                 traffic_type_client,
                                 traffic_type_line,
                                 fec_line,
                                 map_oxuv,
                                 TEN_MAP_DONT_CARE,                    /* odtu mapping not applicable */
                                 8,
                                 255,
                                 TEN_OTU_TERM_TRANSPARENT,
                                 tcm_line);

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 /*dyn_repro,*/
                                 0,                       /* Force a N10G block reset on client side */
                                 traffic_type_client,
                                 traffic_type_client,
                                 TEN_FEC_MODE_NOFEC,
                                 map_oxuv,
                                 TEN_MAP_DONT_CARE,                    /* odtu mapping not applicable */
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
                                  TEN_PP10G_FLOW_GFP_S_P, /* flow_ctrl_mode, Dummy value for GFC */
                                  TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4, /* gfp_frame_format, Dummy value for GFC*/
                                  hsif_is_xaui);


  rtn |= ten_hl_pp10g_config_t41 (module_id_client,
                                  slice_client,
                                  traffic_type_client,
                                  traffic_type_client,
                                  sysclk,
                                  TEN_PP10G_FLOW_GFP_S_P, /* flow_ctrl_mode, A dummy value for GFC */
                                  TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4, /* gfp_frame_format, Dummy value for GFC*/
                                  hsif_is_xaui);

  /* Configure XCON */
  /* Bugzilla 35707 Start */
  if ((traffic_type_client == TEN_TRAFFIC_TYPE_10GFC) ||
      (traffic_type_client == TEN_TRAFFIC_TYPE_8GFC) ||
      (traffic_type_client == TEN_TRAFFIC_TYPE_4GFC) ||
      (traffic_type_client == TEN_TRAFFIC_TYPE_2GFC) ||
      (traffic_type_client == TEN_TRAFFIC_TYPE_1GFC) ||
      (traffic_type_client == TEN_TRAFFIC_TYPE_2GISC)) {
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_8GFC_ENH);
  }
  /* Bugzilla 35707 End */
  else if (traffic_type_client == TEN_TRAFFIC_TYPE_CPRI_4) {  /* Bugzilla 39690 */
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_8GFC_ENH);
  }
  else if ((traffic_type_client == TEN_TRAFFIC_TYPE_10GFC_TC) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_10GFC_TC_G709)) { /* Bug 31054 */
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GFC);
  }   
  else if ((traffic_type_client == TEN_TRAFFIC_TYPE_8GFC_RA) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_4GFC_RA) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_2GFC_RA) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_1GFC_RA)) {
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_8GFC_RA);
  }
  else if ((traffic_type_client == TEN_TRAFFIC_TYPE_8GFC_ENH) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_4GFC_ENH) ||
           /* Bugzilla 35707 Start */
           (traffic_type_client == TEN_TRAFFIC_TYPE_2GFC_ENH) ||
           /* Bugzilla 35707 End */
           (traffic_type_client == TEN_TRAFFIC_TYPE_1GFC_ENH)) {
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_8GFC_ENH);
  }
  else if (traffic_type_client == TEN_TRAFFIC_TYPE_10GFC_TC_RA) {
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GFC_TC_RA);
  }

  /* N10G table is overwriting scrambler bits in N10G, so FEC must be provisioned on line this table usage can be removed */
  /*if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {*/  /* Bugzilla 28474 */
    /* Provision FEC and frame size */
    rtn |= ten_hl_config_fec_t41 (module_id_line, slice_line, TEN_SLICE_10G, fec_line);
  /*}*/ /* Bugzilla 28474 */

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start HIGH LEVEL CONFIG FIBER CHANNEL TO OTU3V      */
/*                 40G MUXPONDER                                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_fc_otu3v_t41 (cs_uint16 module_id_line,
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
                                      cs_uint16 gmp_timeslot_mask)

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
/*              o Mapping Method odtu                           */
/*              o Mapping Method oxuv                           */
/*              o Timeslots                                     */
/*              o GMP Timeslot Mask                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures Fiber Channel on the client side into OTU3V on    */
/* line side. Transcode ratio is read from the control block.   */
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
/*   TEN_TRAFFIC_TYPE_10GFC                = 13                 */
/*   TEN_TRAFFIC_TYPE_8GFC                 = 14                 */
/*   TEN_TRAFFIC_TYPE_4GFC                 = 15                 */
/*   TEN_TRAFFIC_TYPE_2GFC                 = 16                 */
/*   TEN_TRAFFIC_TYPE_1GFC                 = 17                 */
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
/*   TEN_MAP_GMP_HO        = 6                                  */
/*   TEN_MAP_GMP_HO_DT     = 7                                  */
/*                                                              */
/* The [map_oxuv] parameter specifies the client mapping method */
/*   TEN_MAP_AMP         = 0                                    */
/*   TEN_MAP_BMP         = 1                                    */
/*   TEN_MAP_AMP_PROP    = 3                                    */
/*   TEN_MAP_GMP_LO      = 5                                    */
/*                                                              */
/* The [timeslots] parameter specifies number of timeslots.     */
/* Bandwidth for map_proc = GMP_HO is always 1.25G per timeslot.*/
/*   timeslots = 1 - 8                                          */
/* Bandwidth for map_proc = AMP or AMP_DT is as follows:        */
/*   timeslots = 4 for 2.5G per timeslot                        */
/*   timeslots = 8 for 1.25G per timeslot                       */
/* Bandwidth for all other map_proc is 2.5G so timeslots = 4    */
/*                                                              */
/* The [gmp_timeslot_mask] parameter specifies the timeslots to */
/* use for GMP mapping. Applicable to GMP_HO only.              */
/*   Bit 0- Timeslot 1 through Bit 7 – Timeslot 8               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint16 module_id_client;
  cs_uint16 hsif_is_xaui;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_fc_otu3v_t41";  
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);


  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);


  /* Parameter checking */
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

  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU3) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E4) && /* Bugzilla 28237 */
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P2) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E2)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 1, 2, 3, 25, 35, 55.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if ((traffic_type_client != TEN_TRAFFIC_TYPE_10GFC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GFC_TC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_10GFC_TC_G709) && /* Bug 31054 */
      (traffic_type_client != TEN_TRAFFIC_TYPE_8GFC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_4GFC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_2GFC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_1GFC) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_2GISC) && /* Bug 38779 */
      (traffic_type_client != TEN_TRAFFIC_TYPE_CPRI_4) && /* Bugzilla 39690 */
      (traffic_type_client != TEN_TRAFFIC_TYPE_8GFC_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_4GFC_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_2GFC_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_1GFC_RA) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_8GFC_ENH) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_4GFC_ENH) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_2GFC_ENH) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_1GFC_ENH)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 13, 14, 15.", func, traffic_type_client);
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

  if ((map_oxuv != TEN_MAP_AMP) &&
      (map_oxuv != TEN_MAP_BMP) &&
      (map_oxuv != TEN_MAP_AMP_PROP) &&
      (map_oxuv != TEN_MAP_GMP_LO)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_oxuv %d out of range.  s/b 0, 1, 3, 5 or 8.", func, map_oxuv);
    return (CS_ERROR);
  }

  if ((map_odtu == TEN_MAP_GMP_HO) || (map_odtu == TEN_MAP_GMP_HO_DT)) {
    if ((timeslots > 8) || (timeslots < 1)) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 1..8.", func, timeslots);
      return (CS_ERROR);
    }
  }
  else if ((map_odtu == TEN_MAP_AMP) || (map_odtu == TEN_MAP_AMP_DT)) {
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


  CS_PRINT("ten_hl_config_fc_otu3v_t41: 0x%X, %d, %d, dyn=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",
            module_id_line,	slice_line, slice_client, dyn_repro,
            traffic_type_line, fec_line, traffic_type_client,
            sysclk, tcm_line, mld_line, map_odtu, map_oxuv,
            timeslots, gmp_timeslot_mask);


  module_id_client = module_id_line ^ TEN_MODULE_B;

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  rtn |= ten_hl_n40g_config_mux_t41 (module_id_line,      
                                     traffic_type_client,
                                     traffic_type_line,
                                     fec_line,
                                     slice_line,     
                                     dyn_repro,            
                                     map_odtu, /*map_oxuv,*/
                                     timeslots,             
                                     gmp_timeslot_mask,     
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
                                 TEN_FEC_MODE_NOFEC,      /* FEC done in N40G */
                                 map_oxuv,                /* OTU2 mapping */
                                 map_odtu,                /* OTU3 mapping */
                                 timeslots,
                                 gmp_timeslot_mask,
                                 0,
                                 tcm_line);

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 0,                       /* Force a N10G block reset on client side */
                                 traffic_type_client,
                                 traffic_type_client,
                                 TEN_FEC_MODE_NOFEC,
                                 map_oxuv,
                                 TEN_MAP_DONT_CARE,                    /* odtu mapping not applicable on client side */
                                 timeslots,
                                 gmp_timeslot_mask,
                                 0,
                                 tcm_line);


  hsif_is_xaui = ten_hsif_is_xaui_active (module_id_client, slice_client);

  rtn |= ten_hl_pp10g_config_t41 (module_id_line,
                                  slice_line,
                                  traffic_type_client,
                                  TEN_TRAFFIC_TYPE_ODTU,
                                  sysclk,
                                  TEN_PP10G_FLOW_GFP_S_P, /* flow_ctrl_mode, Dummy value for GFC */
                                  TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4, /* gfp_frame_format, Dummy value for GFC*/
                                  hsif_is_xaui);


  rtn |= ten_hl_pp10g_config_t41 (module_id_client,
                                  slice_client,
                                  traffic_type_client,
                                  traffic_type_client,
                                  sysclk,
                                  TEN_PP10G_FLOW_GFP_S_P, /* flow_ctrl_mode, Dummy value for GFC */
                                  TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4, /* gfp_frame_format, Dummy value for GFC*/
                                  hsif_is_xaui);

  /* Configure XCON */
  if ((traffic_type_client == TEN_TRAFFIC_TYPE_10GFC) ||
      (traffic_type_client == TEN_TRAFFIC_TYPE_8GFC) ||
      (traffic_type_client == TEN_TRAFFIC_TYPE_4GFC) ||
      (traffic_type_client == TEN_TRAFFIC_TYPE_2GFC) ||
      (traffic_type_client == TEN_TRAFFIC_TYPE_1GFC)) {
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OTU2E);
  }
  else if (traffic_type_client == TEN_TRAFFIC_TYPE_CPRI_4) {  /* Bugzilla 39690 */
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_8GFC_ENH);
  }
  else if ((traffic_type_client == TEN_TRAFFIC_TYPE_10GFC_TC) || (traffic_type_client == TEN_TRAFFIC_TYPE_10GFC_TC_G709)) { /* Bug 31054 */
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GFC);
  }   
  else if ((traffic_type_client == TEN_TRAFFIC_TYPE_8GFC_RA) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_4GFC_RA) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_2GFC_RA) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_1GFC_RA)) {
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_8GFC_RA);
  }
  else if ((traffic_type_client == TEN_TRAFFIC_TYPE_8GFC_ENH) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_4GFC_ENH) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_2GFC_ENH) ||
           (traffic_type_client == TEN_TRAFFIC_TYPE_1GFC_ENH)) {
    rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_8GFC_ENH);
  }

  if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {
    /* Provision FEC and frame size */
    rtn |= ten_hl_config_fec_t41 (module_id_line, 0, TEN_SLICE_40G, fec_line);
  }

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG FIBER CHANNEL TO OTU2V     */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_fc_oc192_t41(cs_uint16 module_id_line,
                                     cs_uint16 slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint16 slice_client,
                                     cs_uint16 dyn_repro,
                                     cs_uint16 traffic_type_line,
                                     cs_uint16 traffic_type_client,
                                     cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o Traffic Type Client                           */
/*              o System Clock                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures Fiber Channel on the client side into OC192 on    */
/* line side using Rate Adjust on the line side.                */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 - dev_id, Bits 7:1 - don't care, Bit 0 - module  */
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
/* [traffic_type_line] parameter specifies the traffic type     */
/* of the line:                                                 */
/*   TEN_TRAFFIC_TYPE_OC192 = 8                                 */
/*                                                              */
/* [traffic_type_client] parameter specifies the traffic type   */
/* of the client:                                               */
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                 */
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
  cs_char8 *func = "ten_hl_config_fc_oc192_t41";
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);


  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE (module_id_client, pDev, CS_ERROR);


  /* Parameter checking */
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
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 5, 6, 29.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (traffic_type_client != TEN_TRAFFIC_TYPE_8GFC_RA) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 13, 14, 15.", func, traffic_type_client);
    return (CS_ERROR);
  }


  CS_PRINT("%s:  0x%X, %d, 0x%X, %d, dyn=%d, %d, %d, %d\n",
            func,
            module_id_line,	slice_line, module_id_client, slice_client,
            dyn_repro, traffic_type_line, traffic_type_client, sysclk);


  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                 slice_line,
                                 dyn_repro,
                                 traffic_type_client,
                                 traffic_type_line,
                                 TEN_FEC_MODE_NOFEC,                   /* FEC not applicable */
                                 TEN_MAP_AMP,
                                 TEN_MAP_DONT_CARE,                    /* odtu mapping not applicable */
                                 8,
                                 255,
                                 TEN_OTU_TERM_TRANSPARENT,
                                 0);

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 /*dyn_repro,*/
                                 0,                       /* Force a N10G block reset on client side */
                                 traffic_type_client,
                                 traffic_type_client,
                                 TEN_FEC_MODE_NOFEC,
                                 TEN_MAP_AMP,
                                 TEN_MAP_DONT_CARE,                    /* odtu mapping not applicable */
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
                                  TEN_PP10G_FLOW_GFP_S_P, /* flow_ctrl_mode, Dummy value for GFC */
                                  TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4, /* gfp_frame_format, Dummy value for GFC*/
                                  hsif_is_xaui);


  rtn |= ten_hl_pp10g_config_t41 (module_id_client,
                                  slice_client,
                                  traffic_type_client,
                                  traffic_type_client,
                                  sysclk,
                                  TEN_PP10G_FLOW_GFP_S_P, /* flow_ctrl_mode, A dummy value for GFC */
                                  TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4, /* gfp_frame_format, Dummy value for GFC*/
                                  hsif_is_xaui);

  rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_8GFC_RA);

  return (rtn);
}


