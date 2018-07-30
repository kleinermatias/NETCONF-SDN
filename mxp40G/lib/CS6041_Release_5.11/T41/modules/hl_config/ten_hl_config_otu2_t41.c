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
 * API's for high level otu2 client configuration.
 *
 * $Id: ten_hl_config_otu2_t41.c,v 1.41 2013/02/22 20:44:21 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/* Bugzilla 24360 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2V  TO OTU2V            */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu2v_otu2v_t41(cs_uint16 module_id_line,
                                        cs_uint16 slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint16 slice_client,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 fec_line,
                                        cs_uint16 traffic_type_client,
                                        cs_uint16 fec_client,
                                        cs_uint16 term_otu,
                                        cs_uint16 tcm_line,
                                        cs_uint16 tcm_client,
                                        cs_uint16 map_oxuv)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o FEC Type Client                               */
/*              o Term OTU                                      */
/*              o TCM Line                                      */
/*              o TCM Client                                    */
/*              o Mapping Method                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OTU2V on the client side into OTU2V on line side. */
/*                                                              */
/* [module_id_line] and [module_id_client] parameters specify   */
/* the line's and the client's module ID.                       */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [slice_line] and [slice_client] parameters specify the   */
/* line's and the client's slice and is one of the following:   */
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
/* [traffic_type_line] and [traffic_type_client] parameters     */
/* specify the traffic type of the line and the client:         */
/*   TEN_TRAFFIC_TYPE_OTU2  = 5                                 */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                 */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                 */
/*   TEN_TRAFFIC_TYPE_OTU1E = 29                                */
/*                                                              */
/* [fec_line] and [fec_client] parameters define the            */
/* line fec and client fec type:                                */
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
/* [term_otu] parameter defines the way the OTU2 will be sinked */
/* and sourced                                                  */
/*   TEN_OTU_TERM_TRANSPARENT = 0                               */
/*   TEN_OTU_TERM_SECTION     = 1                               */
/*                                                              */
/* The [tcm_line] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [tcm_client] parameter specifies the termination for TCM */
/* 1 through 6.  This is a bit encoded parameter with bits 1    */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_oxuv] parameter specifies the client mapping method */
/*   TEN_MAP_BMP = 1                                            */
/*   TEN_MAP_AMP = 0                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_otu2v_otu2v_t41";  /* __FUNCTION__ or __func__ not available for all compilers */
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
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU1F) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU1E)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 5, 6, 7, 29.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if ((traffic_type_client != TEN_TRAFFIC_TYPE_OTU2) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU2E) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_OTU1F) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU1E)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 5, 6, 7, 29.", func, traffic_type_client);
    return (CS_ERROR);
  }

  if (fec_client >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_client %d out of range.  s/b 0..15.", func, fec_client);
    return (CS_ERROR);
  }
  if (term_otu > TEN_OTU_TERM_FULL) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_otu %d out of range.  s/b 1..2.", func, term_otu);
    return (CS_ERROR);
  }

  if (tcm_line & ~0x7E) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_line 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_line);
    return(CS_ERROR);
  }

  if (tcm_client & ~0x7E) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_client 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_client);
    return(CS_ERROR);
  }

  if ((map_oxuv != TEN_MAP_BMP) && (map_oxuv != TEN_MAP_AMP)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_oxuv=%d with s/b 0..1.", func, map_oxuv);
    return (CS_ERROR);
  }

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line %s, %s, %s, %s\n", ten_module_strings[module_id_line&1], ten_slice_strings[slice_line], ten_hl_config_traffic_types_strings[traffic_type_line], ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("    client %s, %s, %s, %s\n", ten_module_strings[module_id_client&1], ten_slice_strings[slice_client], ten_hl_config_traffic_types_strings[traffic_type_client], ten_fec_ovhd_strings[fec_client]);
  CS_PRINT("    %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    %s\n", ten_hl_config_otu_overhead_term_strings[term_otu]);
  CS_PRINT("    %s\n", ten_sync_type_strings[map_oxuv]);
  CS_PRINT("    tcm_line=0x%X, tcm_cliente=0x%X\n", tcm_line, tcm_client);


  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);


  rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                 slice_line,
                                 dyn_repro,
                                 traffic_type_line,
                                 traffic_type_line,
                                 fec_line,
                                 map_oxuv,
                                 TEN_MAP_DONT_CARE,                  /* odtu mapping not applicable */
                                 8,
                                 255,
                                 term_otu,
                                 tcm_line);

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 0,                     /* Force a N10G block reset on client side */
                                 traffic_type_client,
                                 traffic_type_client,
                                 fec_client,
                                 map_oxuv,
                                 TEN_MAP_DONT_CARE,                  /* odtu mapping not applicable on client side*/
                                 8,
                                 255,
                                 term_otu,
                                 tcm_line);


  if ((traffic_type_client == TEN_TRAFFIC_TYPE_OTU1E) || (traffic_type_client == TEN_TRAFFIC_TYPE_OTU2E)) {
    /* Enable 10GE monitoring */
    /* Bugzilla #34099 start change, refactor pp10g init/reset sequence */
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
    /* Bugzilla #34099 end change, refactor pp10g init/reset sequence */
  }
  else {
   /* Bugzilla #36717 Stats take longer to read in OTU2 mode after a dynamic reconfig from OTU2E.    */
   /* Disable 10GE monitoring for OTU2, potentially left over from dynamic reconfig from OTU2E/OTU1E */
   rtn |= ten_pp10g_tx_alarms_reset(module_id_line, slice_line, CS_RESET_ASSERT);
   rtn |= ten_pp10g_rx_alarms_reset(module_id_line, slice_line, CS_RESET_ASSERT);
   rtn |= ten_pp10g_funcen_rx(module_id_line, slice_line, 0, 0, 0, 0, 0, 0, 0, 0);
   rtn |= ten_pp10g_funcen_tx(module_id_line, slice_line, 0, 0, 0, 0, 0, 0, 0);
   rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_DISABLE, TEN_PP10G_TX_DISABLE);

   rtn |= ten_pp10g_tx_alarms_reset(module_id_client, slice_client, CS_RESET_ASSERT);
   rtn |= ten_pp10g_rx_alarms_reset(module_id_client, slice_client, CS_RESET_ASSERT);
   rtn |= ten_pp10g_funcen_rx(module_id_client, slice_client, 0, 0, 0, 0, 0, 0, 0, 0);
   rtn |= ten_pp10g_funcen_tx(module_id_client, slice_client, 0, 0, 0, 0, 0, 0, 0);
   rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_DISABLE, TEN_PP10G_TX_DISABLE);
  }

  ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, traffic_type_client);

  rtn |= ten_hl_config_fec_t41 (module_id_client, slice_client, TEN_SLICE_10G, fec_client);

  /* N10G table is overwriting scrambler bits in N10G, so FEC must be provisioned on line this table usage can be removed */
  /*if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {*/  /* Bugzilla 28474 */
  /* Provision FEC and frame size */
  rtn |= ten_hl_config_fec_t41 (module_id_line, slice_line, TEN_SLICE_10G, fec_line);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2V TO OTU3V             */
/*                 40G MUXPONDER                                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu2v_otu3v_t41(cs_uint16 module_id_line,
                                        cs_uint16 slice_line,
                                        cs_uint16 slice_client,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 fec_line,
                                        cs_uint16 traffic_type_client,
                                        cs_uint16 fec_client,
                                        cs_uint16 term_otu,
                                        cs_uint16 tcm_line,
                                        cs_uint16 tcm_client,
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
/*              o FEC Type Client                               */
/*              o Term OTU                                      */
/*              o TCM Line                                      */
/*              o TCM Client                                    */
/*              o MLD Line                                      */
/*              o Mapping Method odtu                           */
/*              o Mapping Method oxuv                           */
/*              o Timeslots                                     */
/*              o GMP Timeslot Mask                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OTU2V on the client side into OTU3V on line side. */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [slice_line] and [slice_client] parameters specify the   */
/* line's and the client's slice and is one of the following:   */
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
/* [fec_line] and [fec_client] parameters define the            */
/* line fec and client fec type:                                */
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
/*   TEN_TRAFFIC_TYPE_OTU2  = 5                                 */
/*   TEN_TRAFFIC_TYPE_OTU2e = 6                                 */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                 */
/*   TEN_TRAFFIC_TYPE_OTU1E = 29                                */
/*                                                              */
/* [term_otu] parameter defines the way the OTU2 will be sinked */
/* and sourced                                                  */
/*   TEN_OTU_TERM_TRANSPARENT = 0                               */
/*   TEN_OTU_TERM_SECTION     = 1                               */
/*                                                              */
/* The [tcm_line] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [tcm_client] parameter specifies the termination for TCM */
/* 1 through 6.  This is a bit encoded parameter with bits 1    */
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
/* The [map_odtu] parameter specifies the line mapping method   */
/*   TEN_MAP_AMP        = 0                                     */
/*   TEN_MAP_AMP_DT     = 2                                     */
/*   TEN_MAP_AMP_PROP   = 3                                     */
/*   TEN_MAP_GMP_HO     = 6                                     */
/*                                                              */
/* The [map_oxuv] parameter specifies the client mapping method */
/*   TEN_MAP_BMP = 1                                            */
/*   TEN_MAP_AMP = 0                                            */
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
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_otu2v_otu3v_t41";
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);

  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);

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
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E2) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E4) && /* Bugzilla 28237 */
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P2)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 1, 2, 3, 25, 37, 55", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if (term_otu > TEN_OTU_TERM_FULL) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_otu %d out of range.  s/b 1..2.", func, term_otu);
    return (CS_ERROR);
  }

  if (tcm_line & ~0x7E) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_line 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_line);
    return(CS_ERROR);
  }

  if (tcm_client & ~0x7E) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_client 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_client);
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


 #if 0
  CS_PRINT("%s() 0x%X, %d, %d, dyn=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",
            func,
            module_id_line, slice_line, slice_client, dyn_repro,
            traffic_type_line, fec_line, traffic_type_client,
            fec_client, term_otu, tcm_line, tcm_client, mld_line,
            map_odtu, map_oxuv, timeslots, gmp_timeslot_mask);
 #endif
  CS_PRINT("%s() \n", func);
  CS_PRINT("    line (%s, %s,  %s, %s)\n",  ten_module_strings[module_id_line&1], 
                ten_slice_strings[slice_line], 
                ten_hl_config_traffic_types_strings[traffic_type_line], 
                ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("    client (%s, %s, %s) \n", ten_slice_strings[slice_client], 
                ten_hl_config_traffic_types_strings[traffic_type_client], 
                ten_fec_ovhd_strings[fec_client]);
  CS_PRINT("    %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    %s\n", ten_hl_config_otu_overhead_term_strings[term_otu]);
  CS_PRINT("    tcm_line=0x%X\n", tcm_line);
  CS_PRINT("    tcm_cliente=0x%X\n", tcm_client);
  CS_PRINT("    mld_line=%d\n", mld_line);

  if (map_odtu <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT(", map_odtu=%s", ten_sync_type_strings[map_odtu]);
  }
  else {
    CS_PRINT(", map_odtu=%d", map_odtu);
  }
  if (map_oxuv <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT(", map_oxuv=%s", ten_sync_type_strings[map_oxuv]);
  }
  else {
    CS_PRINT(", map_oxuv=%d", map_oxuv);
  }
  CS_PRINT(", timeslots=0x%X gmp_timeslot_mask=0x%X\n",
            timeslots, 
            gmp_timeslot_mask);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);


  module_id_client = module_id_line ^ TEN_MODULE_B;


  rtn |= ten_hl_n40g_config_mux_t41 (module_id_line,      
                                     traffic_type_client,
                                     traffic_type_line,
                                     fec_line,
                                     slice_line,     
                                     dyn_repro,            
                                     map_odtu, /*map_oxuv,*/
                                     timeslots,             
                                     gmp_timeslot_mask,     
                                     term_otu,            
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
                                 term_otu,
                                 tcm_line);

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 0,                       /* Force a N10G block reset on client side */
                                 traffic_type_client,
                                 traffic_type_client,
                                 fec_client,
                                 /*map_oxuv,*/
                                 TEN_MAP_BMP,             /* Force to BMP */
                                 TEN_MAP_DONT_CARE,       /* odtu mapping not applicable on client side*/
                                 timeslots,
                                 gmp_timeslot_mask,
                                 term_otu,
                                 tcm_client);

  if ((traffic_type_client == TEN_TRAFFIC_TYPE_OTU1E) || (traffic_type_client == TEN_TRAFFIC_TYPE_OTU2E)) {
    /* Enable 10GE monitoring */
    /* Bugzilla #34099 start change, refactor pp10g init/reset sequence */
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
    /* Bugzilla #34099 end change, refactor pp10g init/reset sequence */
  }
  else {
   /* Bugzilla #36717 Stats take longer to read in OTU2 mode after a dynamic reconfig from OTU2E.    */
   /* Disable 10GE monitoring for OTU2, potentially left over from dynamic reconfig from OTU2E/OTU1E */
   rtn |= ten_pp10g_tx_alarms_reset(module_id_line, slice_line, CS_RESET_ASSERT);
   rtn |= ten_pp10g_rx_alarms_reset(module_id_line, slice_line, CS_RESET_ASSERT);
   rtn |= ten_pp10g_funcen_rx(module_id_line, slice_line, 0, 0, 0, 0, 0, 0, 0, 0);
   rtn |= ten_pp10g_funcen_tx(module_id_line, slice_line, 0, 0, 0, 0, 0, 0, 0);
   rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_DISABLE, TEN_PP10G_TX_DISABLE);

   rtn |= ten_pp10g_tx_alarms_reset(module_id_client, slice_client, CS_RESET_ASSERT);
   rtn |= ten_pp10g_rx_alarms_reset(module_id_client, slice_client, CS_RESET_ASSERT);
   rtn |= ten_pp10g_funcen_rx(module_id_client, slice_client, 0, 0, 0, 0, 0, 0, 0, 0);
   rtn |= ten_pp10g_funcen_tx(module_id_client, slice_client, 0, 0, 0, 0, 0, 0, 0);
   rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_DISABLE, TEN_PP10G_TX_DISABLE);
  }

  /*rtn |= ten_hl_oc192_termination_path (module_id_line, slice_line, module_id_client, slice_client, term_oc192);*/
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OTU2); 

  if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {
    /* Provision FEC and frame size */
    rtn |= ten_hl_config_fec_t41 (module_id_line, 0, TEN_SLICE_40G, fec_line);
  }
  
  /* Bugzilla #35897, add client fec API */
  rtn |= ten_hl_config_fec_t41(module_id_client, slice_client, TEN_SLICE_10G, fec_client);
  
  return (rtn);
}
/* Bugzilla 24360 End */

/* Bugzilla #31359 - 10-GE wire mode config needs adjustments */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10G WIRE V2                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10g_wire_t41_v2(cs_uint16 module_id_line,
                                        cs_uint16 slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint16 slice_client,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 traffic_type_client)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o Traffic Type Client                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a 10 Gig line/client unframed CBR pair.            */
/*                                                              */
/* [module_id_line] and [module_id_client] parameters specify   */
/* the line's and the client's module ID.                       */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [slice_line] and [slice_client] parameters specify the   */
/* line's and the client's slice and is one of the following:   */
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
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_10g_wire_t41";  /* __FUNCTION__ or __func__ not available for all compilers */

  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);


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
  
  if (traffic_type_line >=  TEN_TRAFFIC_TYPE_MAX) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 1, 2, 3, 25, 37, 55", func, traffic_type_line);
    return (CS_ERROR);
  }
  
  if (traffic_type_client >=  TEN_TRAFFIC_TYPE_MAX) {
    CS_HNDL_ERROR(module_id_client, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 1, 2, 3, 25, 37, 55", func, traffic_type_client);
    return (CS_ERROR);
  }
  
  CS_PRINT("%s() mod_line=%s, slice_line=%s, mod_client=%s,slice_client=%s\ndyn=%s, traffic_line=%s, traffic_client=%s\n",
           func,
           ten_module_strings[module_id_line&1],
           ten_slice_strings[slice_line],
           ten_module_strings[module_id_client&1],
           ten_slice_strings[slice_client],
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_hl_config_traffic_types_strings[traffic_type_line],
           ten_hl_config_traffic_types_strings[traffic_type_client]);

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_mpif_global_clock_disable_n10g (dev_id, module_id_line & 1, slice_line, CS_TX_AND_RX, CS_ENABLE);
  rtn |= ten_mpif_global_reset_n10g (dev_id, module_id_line & 1, slice_line, CS_TX_AND_RX, CS_RESET_DEASSERT);
  rtn |= ten_mpif_global_clock_disable_n10g (dev_id, module_id_client & 1, slice_client, CS_TX_AND_RX, CS_ENABLE);
  rtn |= ten_mpif_global_reset_n10g (dev_id, module_id_client & 1, slice_client, CS_TX_AND_RX, CS_RESET_DEASSERT);

  if (!dyn_repro) {
    /* Assert Block-level resets */
    rtn |= ten_n10g_set_global_resets (module_id_line, slice_line, CS_RESET_ASSERT,
                                       TEN_N10G_GLOBAL_RESETS_RSTRX |
                                       TEN_N10G_GLOBAL_RESETS_RSTOR |
                                       TEN_N10G_GLOBAL_RESETS_RSTCR |
                                       TEN_N10G_GLOBAL_RESETS_RSTSYS |

                                       TEN_N10G_GLOBAL_RESETS_RSTSYS  |
                                       TEN_N10G_GLOBAL_RESETS_RSTTX   |
                                       TEN_N10G_GLOBAL_RESETS_RSTTXNG |
                                       TEN_N10G_GLOBAL_RESETS_RSTOT   |
                                       TEN_N10G_GLOBAL_RESETS_RSTCT);

    rtn |= ten_n10g_set_global_resets (module_id_client, slice_client, CS_RESET_ASSERT,
                                       TEN_N10G_GLOBAL_RESETS_RSTRX |
                                       TEN_N10G_GLOBAL_RESETS_RSTOR |
                                       TEN_N10G_GLOBAL_RESETS_RSTCR |
                                       TEN_N10G_GLOBAL_RESETS_RSTSYS |

                                       TEN_N10G_GLOBAL_RESETS_RSTSYS  |
                                       TEN_N10G_GLOBAL_RESETS_RSTTX   |
                                       TEN_N10G_GLOBAL_RESETS_RSTTXNG |
                                       TEN_N10G_GLOBAL_RESETS_RSTOT   |
                                       TEN_N10G_GLOBAL_RESETS_RSTCT);
  }

  /* Bypass OTN and Sonet and turn them off */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id_line, slice_line, 2, 0, 1, 1, 1, 1, 1);   /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */
  rtn |= ten_n10g_set_gblt_bypasses (module_id_line, slice_line, 1, 1, 1, 1); /* OTNOFF, OBY, SBY, KPGBY*/
  rtn |= ten_n10g_set_gblr_dpcfg (module_id_client, slice_client, 2, 0, 1, 1, 1, 1, 1);   /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */
  rtn |= ten_n10g_set_gblt_bypasses (module_id_client, slice_client, 1, 1, 1, 1); /* OTNOFF, OBY, SBY, KPGBY*/

  rtn |= ten_hl_xcon_config (dev_id, (module_id_line & 1) * 4 + slice_line,
                               (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OTU2);
  
  /* Bugzilla #31359, lower latency for 10GE wire mode */
  if (traffic_type_client == TEN_TRAFFIC_TYPE_10GE) {
    CS_PRINT("Use 10GE wire low latency settings\n");
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, (4*(module_id_client&1)) + slice_client, XCON_ES_IML_THRESH, 20);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, (4*(module_id_client&1)) + slice_client, XCON_ES_CIRCUIT_THRESHOLD_LOWER, 4);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, (4*(module_id_client&1)) + slice_client, XCON_ES_CIRCUIT_THRESHOLD_UPPER, 36);

    rtn |= ten_xcon_set_circuit_thresholds(dev_id, (4*(module_id_line&1)) + slice_line, XCON_ES_IML_THRESH, 20);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, (4*(module_id_line&1)) + slice_line, XCON_ES_CIRCUIT_THRESHOLD_LOWER, 4);
    rtn |= ten_xcon_set_circuit_thresholds(dev_id, (4*(module_id_line&1)) + slice_line, XCON_ES_CIRCUIT_THRESHOLD_UPPER, 36);
  }  
  return (rtn);
}
/* Bugzilla 24645 End */

/* Bugzilla 24645 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10G WIRE                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10g_wire_t41 (cs_uint16 module_id_line,
                                      cs_uint16 slice_line,
                                      cs_uint16 module_id_client,
                                      cs_uint16 slice_client,
                                      cs_uint16 dyn_repro)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a 10 Gig line/client unframed CBR pair.            */
/*                                                              */
/* [module_id_line] and [module_id_client] parameters specify   */
/* the line's and the client's module ID.                       */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [slice_line] and [slice_client] parameters specify the   */
/* line's and the client's slice and is one of the following:   */
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
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_config_10g_wire_t41_v2(module_id_line,
                                        slice_line,
                                        module_id_client,
                                        slice_client,
                                        dyn_repro,
                                        TEN_TRAFFIC_TYPE_OTU2,
                                        TEN_TRAFFIC_TYPE_OTU2));
}
/* Bugzilla 24645 End */

/* Bugzilla 24559 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10G CBR KPGA               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10g_cbr_kpga_t41 (cs_uint16 module_id,
                                          cs_uint16 slice,
                                          cs_uint16 pattern,
                                          cs_uint16 dyn_repro)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Pattern                                       */
/*              o Dynamic Reprovision Type                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a 10 Gig unframed Constant Bit Rate Known Pattern  */
/* Generator/Analyzer                                           */
/*                                                              */
/* [module_id] parameters specifies the module ID.              */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [slice] parameters specify the slice and is one of the   */
/* following:                                                   */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   0x00 = TEN_KPG_FIXED_PATTERN                               */
/*   0x01 = TEN_KPG_PN11                                        */
/*   0x02 = TEN_KPG_PN23                                        */
/*   0x03 = TEN_KPG_PN31                                        */
/*                                                              */
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_10g_cbr_kpga_t41";  /* __FUNCTION__ or __func__ not available for all compilers */

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3.", func, slice);
    return (CS_ERROR);
  }

  if (pattern > TEN_KPG_PN31) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           ten_kpg_strings[pattern],
           ten_hl_config_dyn_repro_strings[dyn_repro]);

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_mpif_global_clock_disable_n10g (dev_id, module_id & 1, slice, CS_TX_AND_RX, CS_ENABLE);
  rtn |= ten_mpif_global_reset_n10g (dev_id, module_id & 1, slice, CS_TX_AND_RX, CS_RESET_DEASSERT);

  if (!dyn_repro) {
    /* Assert Block-level resets */
    rtn |= ten_n10g_set_global_resets (module_id, slice, CS_RESET_ASSERT,
                                       TEN_N10G_GLOBAL_RESETS_RSTRX |
                                       TEN_N10G_GLOBAL_RESETS_RSTOR |
                                       TEN_N10G_GLOBAL_RESETS_RSTCR |
                                       TEN_N10G_GLOBAL_RESETS_RSTSYS |

                                       TEN_N10G_GLOBAL_RESETS_RSTSYS  |
                                       TEN_N10G_GLOBAL_RESETS_RSTTX   |
                                       TEN_N10G_GLOBAL_RESETS_RSTTXNG |
                                       TEN_N10G_GLOBAL_RESETS_RSTOT   |
                                       TEN_N10G_GLOBAL_RESETS_RSTCT);
  }


  /* Bypass OTN and Sonet and turn them off */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id, slice, 0, 2, 1, 1, 1, 1, 1);   /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */
  rtn |= ten_n10g_set_gblt_bypasses (module_id, slice, 1, 1, 1, 0); /* OTNOFF, OBY, SBY, KPGBY*/

  /* Config KPG - PATSEL */   /* Bugzilla #33766, fix warnings, use cs_ctl_t enums */
  rtn |= ten_n10g_config_kpg (module_id, slice, CS_DISABLE, CS_DISABLE, pattern, 0, 0);  /* kpg_bypass, kpg_auto, pattern, fpat1, fpat0 */

  return (rtn);
}
/* Bugzilla 24559 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU2V TO OTU2V UFEC SFI4.1 */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu2v_otu2v_ufec_sfi41_t41(cs_uint16 dev_id,
                                                   cs_uint16 dyn_repro,
                                                   cs_uint16 traffic_type_line,
                                                   cs_uint16 fec_line,
                                                   cs_uint16 traffic_type_client,
                                                   cs_uint16 fec_client,
                                                   cs_uint16 term_otu,
                                                   cs_uint16 tcm_line,
                                                   cs_uint16 tcm_client,
                                                   cs_uint16 map_oxuv)
/* INPUTS     : o Device Id                                     */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o FEC Type Client                               */
/*              o Term OTU                                      */
/*              o TCM Line                                      */
/*              o TCM Client                                    */
/*              o Mapping Method                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OTU2V on the client side into OTU2V on line side  */
/* with UFEC on SFI 4.1                                         */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] and [traffic_type_client] parameters     */
/* specify the traffic type of the line and the client:         */
/*   TEN_TRAFFIC_TYPE_OTU2  = 5                                 */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                 */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                 */
/*   TEN_TRAFFIC_TYPE_OTU1E = 29                                */
/*                                                              */
/* [fec_line] and [fec_client] parameters define the            */
/* line fec and client fec type:                                */
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
/* [term_otu] parameter defines the way the OTU2 will be sinked */
/* and sourced                                                  */
/*   TEN_OTU_TERM_TRANSPARENT = 0                               */
/*   TEN_OTU_TERM_SECTION     = 1                               */
/*                                                              */
/* The [tcm_line] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [tcm_client] parameter specifies the termination for TCM */
/* 1 through 6.  This is a bit encoded parameter with bits 1    */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_oxuv] parameter specifies the client mapping method */
/*   TEN_MAP_BMP = 1                                            */
/*   TEN_MAP_AMP = 0                                            */
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

    ten_dev_cb_t *pdevcb;
    T41_t *pDev = NULL;
    cs_status rtn = CS_OK;
    cs_char8 *func = "ten_hl_config_otu2v_otu2v_t41";  /* __FUNCTION__ or __func__ not available for all compilers */

    TEN_MOD_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);  /* Bugzilla 35949 */
  
    if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
      return (CS_ERROR);
    }
  
    if (traffic_type_line != TEN_TRAFFIC_TYPE_OTU2) {
        CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 5, 6, 7, 29.", func, traffic_type_line);
      return (CS_ERROR);
    }
  
    if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
      return (CS_ERROR);
    }
  
    if (traffic_type_client != TEN_TRAFFIC_TYPE_OTU2) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 5, 6, 7, 29.", func, traffic_type_client);
      return (CS_ERROR);
    }
  
    if (fec_client >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_client %d out of range.  s/b 0..15.", func, fec_client);
    return (CS_ERROR);
    }
    if (term_otu > TEN_OTU_TERM_FULL) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_otu %d out of range.  s/b 1..2.", func, term_otu);
      return (CS_ERROR);
    }

    if (tcm_line & ~0x7E) {
      CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_line 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_line);
      return(CS_ERROR);
    }
  
    if (tcm_client & ~0x7E) {
      CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_client 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_client);
      return(CS_ERROR);
    }
  
    /*if ((map_oxuv != TEN_MAP_BMP) && (map_oxuv != TEN_MAP_AMP)) {*/
    if (map_oxuv != TEN_MAP_BMP) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_oxuv=%d with s/b 0..1.", func, map_oxuv);
      return (CS_ERROR);
    }

    CS_PRINT("%s()\n", func);
    CS_PRINT("    line %s, %s\n", ten_hl_config_traffic_types_strings[traffic_type_line], ten_fec_ovhd_strings[fec_line]);
    CS_PRINT("    client %s, %s\n", ten_hl_config_traffic_types_strings[traffic_type_client], ten_fec_ovhd_strings[fec_client]);
    CS_PRINT("    %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
    CS_PRINT("    %s\n", ten_hl_config_otu_overhead_term_strings[term_otu]);
    CS_PRINT("    %s\n", ten_sync_type_strings[map_oxuv]);
    CS_PRINT("    tcm_line=0x%X, tcm_cliente=0x%X\n", tcm_line, tcm_client);

    pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  
   /******************** First Path *********************/
    module_id_line = 0;          /* A0 */
    slice_line = 0;
    module_id_client = 1;        /* B1 */
    slice_client = 1;
    
    rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                   slice_line,
                                   dyn_repro,
                                   traffic_type_line,
                                   traffic_type_line,
                                   fec_line,
                                   map_oxuv,
                                   TEN_MAP_DONT_CARE,                  /* odtu mapping not applicable */
                                   8,
                                   255,
                                   term_otu,
                                   tcm_line);

    rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                   slice_client,
                                   0,                     /* Force a N10G block reset on client side */
                                   traffic_type_client,
                                   traffic_type_client,
                                   fec_client,
                                   map_oxuv,
                                   TEN_MAP_DONT_CARE,                  /* odtu mapping not applicable on client side*/
                                   8,
                                   255,
                                   term_otu,
                                   tcm_line);


    rtn |= ten_hl_n10g_config(module_id_line, 
                              slice_line, 
                              TEN_N10G_RX_BYPASS, 
                              TEN_N10G_TX_BYPASS, 
                              dyn_repro);
                              
    rtn |= ten_hl_config_fec_t41 (module_id_client, slice_client, TEN_SLICE_10G, fec_client);
  
    /******************** Second Path *********************/                                
    module_id_line_int = 0;      /* A2 */
    slice_line_int = 2;
    module_id_client_int = 0;    /* A1 */
    slice_client_int = 1;                              

    rtn |= ten_hl_n10g_config_t41 (module_id_line_int, 
                                   slice_line_int,
                                   dyn_repro,
                                   traffic_type_line,
                                   traffic_type_line,
                                   fec_line,
                                   map_oxuv,
                                   TEN_MAP_DONT_CARE,                   /* odtu mapping not applicable */
                                   8,
                                   255,
                                   term_otu,
                                   tcm_line);

    rtn |= ten_hl_n10g_config(module_id_line_int, 
                              slice_line_int, 
                              TEN_N10G_RX_BYPASS, 
                              TEN_N10G_TX_ODU2_OTU2, 
                              dyn_repro);

    rtn |= ten_hl_n10g_config_t41 (module_id_client_int, 
                                   slice_client_int,
                                   0,                                   /* Force a N10G block reset on client side */
                                   traffic_type_client,
                                   traffic_type_client,
                                   fec_client,
                                   map_oxuv,
                                   TEN_MAP_DONT_CARE,                   /* odtu mapping not applicable on client side*/
                                   8,
                                   255,
                                   term_otu,
                                   tcm_line);

    rtn |= ten_hl_n10g_config(module_id_client_int, 
                              slice_client_int, 
                              TEN_N10G_RX_OTU2_ODU2, 
                              TEN_N10G_TX_BYPASS, 
                              0);


    rtn |= ten_hl_config_fec_t41 (module_id_client_int, slice_client_int, TEN_SLICE_10G, fec_line);

    /* N10G table is overwriting scrambler bits in N10G, so FEC must be provisioned on line this table usage can be removed */
    /*if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {*/  /* Bugzilla 28474 */
    /* Provision FEC and frame size */
    rtn |= ten_hl_config_fec_t41 (module_id_line_int, slice_line_int, TEN_SLICE_10G, fec_line);

    /******************** Setup cross connects ********************/
    ten_hl_xcon_config (dev_id, 
                        (module_id_line_int & 1) * 4 + slice_line_int,
                        (module_id_client & 1) * 4 + slice_client,
                        TEN_TRAFFIC_TYPE_OTU2);

    ten_hl_xcon_config (dev_id, 
                        (module_id_client_int & 1) * 4 + slice_client_int,
                        (module_id_line & 1) * 4 + slice_line,
                        TEN_TRAFFIC_TYPE_OTU2);

    rtn |= ten_xcon_es_select_source(dev_id,                                              /* 2=5 */
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

    rtn |= ten_xcon_es_select_source(dev_id,                                              /* 5=1 */
                                     (module_id_client & 1) * 4 + slice_client,
                                     (module_id_client_int & 1) * 4 + slice_client_int,
                                     XCON_N10G);

    return (rtn);
}
