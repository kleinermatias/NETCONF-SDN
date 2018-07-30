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
 * API's for high level OC192 client configuration.
 *
 * $Id: ten_hl_config_oc192_t41.c,v 1.37 2013/05/01 14:37:17 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"
#include <util.h>

#if 1
/****************************************************************/
/* $rtn_hdr_start  OC192 TERMINATION                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_oc192_termination_path (cs_uint16 module_id_line,
                                         cs_uint16 slice_line,
                                         cs_uint16 module_id_client,
                                         cs_uint16 slice_client,
                                         cs_uint16 term)
/* INPUTS     : o Module Id Line                                */
/*              o Module Id Client                              */
/*              o Term Overhead Termination Type                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure OC768 header termination mode.                     */
/*                                                              */
/* [mod_id_line] and [mod_id_client] specifies line's and       */
/* client's module ID                                           */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [term_sonet] defines the way the OC768 will be sinked and    */
/* sourced                                                      */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1,                */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2,                */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3,                */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* Bugzilla 23776 Start */
  /* T41_t *pDev; */
  /* cs_char8 *func = "ten_hl_oc192_termination_path"; */

  /* Override HL provisioning */
  if (ten_hl_oc192_termination_path_client_side(module_id_client, slice_client, term) != CS_OK) {
    return (CS_ERROR);  /* error already reported */
  }

  if (ten_hl_oc192_termination_path_line_side(module_id_line, slice_line, term) != CS_OK) {
    return (CS_ERROR);  /* error already reported */
  }

  return (CS_OK);
}
#endif


/****************************************************************/
/* $rtn_hdr_start  OC192 TRANSPONDER TERMINATION                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_oc192_trans_term_path (cs_uint16 module_id_line,
                                         cs_uint16 slice_line,
                                         cs_uint16 module_id_client,
                                         cs_uint16 slice_client,
                                         cs_uint16 term_oc192)
/* INPUTS     : o Module Id Line                                */
/*              o Module Id Client                              */
/*              o Term Overhead Termination Type                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure OC768 header termination mode.                     */
/*                                                              */
/* [mod_id_line] and [mod_id_client] specifies line's and       */
/* client's module ID                                           */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [term_oc192] defines the way the OC768 will be sinked and    */
/* sourced                                                      */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1,                */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2,                */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3,                */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* Bugzilla 23776 Start */
  /* T41_t *pDev; */
  /* cs_char8 *func = "ten_hl_oc192_trans_term_path"; */

  if (ten_hl_oc192_termination_path(module_id_line, slice_line, module_id_client, slice_client, term_oc192) != CS_OK) {
    return (CS_ERROR);  /* error already reported */
  }

  if (ten_n10g_tx_trans_term_line_bypass(module_id_line, slice_line, term_oc192) != CS_OK) {
    return (CS_ERROR);  /* error already reported */
  }


  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC192 TO OTU2V             */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_otu2v_t41(cs_uint16 module_id_line,
                                        cs_uint16 slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint16 slice_client,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 fec_line,
                                        cs_uint16 term_oc192,
                                        cs_uint16 tcm_line,
                                        cs_uint16 map_oxuv)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Term OC192                                    */
/*              o TCM Line                                      */
/*              o Mapping Method                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OC192 on the client side into OTU2 on line side.  */
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
/* [module_id_client] parameter specifies the client's module ID*/
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
/*   TEN_TRAFFIC_TYPE_OTU2E = 6,                                */
/*   TEN_TRAFFIC_TYPE_OTU2E = 29,                               */
/*                                                              */
/* [fec_line] parameter defines fec type:                       */
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
/* [term_oc192] parameter defines the way the OC192 will be     */
/* sinked and sourced                                           */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1                 */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2                 */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3                 */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4                 */
/*                                                              */
/* The [tcm_line] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_oxuv] parameter specifies the mapping method        */
/*   TEN_MAP_BMP = 1                                            */
/*   TEN_MAP_AMP = 0                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_oc192_otu2v_t41";  
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);

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
  
  /* Bug #38686:  Add support for OC192 (10GE WAN) into OTU2E and OTU21E */
  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU2) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU2E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU1E)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 5, 6 or 29.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if (term_oc192 > TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_oc192 %d out of range.  s/b 1..4.", func, term_oc192);
    return (CS_ERROR);
  }

  if (tcm_line & ~0x7E) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_line 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_line);
    return(CS_ERROR);
  }

  /* Block-level code is to validate oxuv mapping */

 #if 0
  CS_PRINT("ten_hl_config_oc192_otu2v_t41: 0x%X, %d, 0x%X, %d, dyn=%d, %d, %d, %d, %d\n",
            module_id_line, slice_line, module_id_client, slice_client,
            dyn_repro, traffic_type_line, fec_line, term_oc192,
            tcm_line, map_oxuv);
 #endif
  CS_PRINT("%s() %s, slice_line=%d, slice_client=%d, %s, %s, %s, %s, tcm_line = %d, %s\n",
           func,
           ten_module_strings[module_id_line & 1],
           slice_line,
           slice_client,
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_hl_config_traffic_types_strings[traffic_type_line],
           ten_fec_ovhd_strings[fec_line],
           ten_hl_config_oc192_overhead_term_strings[term_oc192],
           tcm_line,
           ten_sync_type_strings[map_oxuv]);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                 slice_line,
                                 dyn_repro,
                                 TEN_TRAFFIC_TYPE_OC192,
                                 traffic_type_line,
                                 fec_line,
                                 map_oxuv,
                                 TEN_MAP_DONT_CARE,
                                 8,
                                 255,
                                 term_oc192,
                                 tcm_line);

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 0,                       /* Force a N10G block reset on client side */
                                 TEN_TRAFFIC_TYPE_OC192,
                                 TEN_TRAFFIC_TYPE_OC192,
                                 TEN_FEC_MODE_NOFEC,
                                 map_oxuv,
                                 TEN_MAP_DONT_CARE,
                                 8,
                                 255,
                                 term_oc192,
                                 tcm_line);

  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OC192); 

  /* Provision FEC and frame size */
  rtn |= ten_hl_config_fec_t41 (module_id_line, slice_line, TEN_SLICE_10G, fec_line);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC192 TO OTU3V             */
/*                 40G MUXPONDER                                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_otu3v_t41(cs_uint16 module_id_line,
                                        cs_uint16 slice_line,
                                        cs_uint16 slice_client,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 fec_line,
                                        cs_uint16 term_oc192,
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
/*              o Term OC192                                    */
/*              o TCM Line                                      */
/*              o MLD Line                                      */
/*              o Mapping Method OxU3v                          */
/*              o Mapping Method OxU2v                          */
/*              o Timeslots                                     */
/*              o GMP Timeslot Mask                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OC192 on the client side into OTU3v on line side. */
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
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 37                               */
/*   TEN_TRAFFIC_TYPE_OTU3E4 = 55                               */
/*                                                              */
/* [fec_line] parameter defines fec type:                       */
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
/* [term_oc192] parameter defines the way the OC192 will be     */
/* sinked and sourced                                           */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1                 */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2                 */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3                 */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4                 */
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
/* The [map_oxuv] parameter specifies the client mapping method */
/* See customer docs for valid mapping combinations.            */
/*   TEN_MAP_BMP          = 1                                   */
/*   TEN_MAP_AMP          = 0                                   */
/*   TEN_MAP_AMP_PROP     = 3 (Requires entry in syncdsync CB!) */
/*   TEN_MAP_GMP_LO       = 5                                   */
/*                                                              */
/* The [map_odtu] parameter specifies the line mapping method   */
/* See customer docs for valid mapping combinations.            */
/*   TEN_MAP_AMP          = 0                                   */
/*   TEN_MAP_AMP_DT       = 2                                   */
/*   TEN_MAP_AMP_PROP     = 3                                   */
/*   TEN_MAP_AMP_PROP_DT  = 4                                   */
/*   TEN_MAP_GMP_HO       = 6                                   */
/*   TEN_MAP_GMP_HO_DT    = 7                                   */
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
/*   Bit 0- Timeslot 1 through Bit 7 - Timeslot 8               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint16 module_id_client;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_oc192_otu3v_t41";  
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
#if 0
//  cs_uint32 hysteresis;
#endif

  /* Validate arguments */
  /* Validation of mappings for OC192 to muxponder and transponder is to be handled at block level */
  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);

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
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E2) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E4) &&    /* Bugzilla 28237 */
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P2)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 1, 2, 3, 25, 37, 55", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if (term_oc192 > TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_oc192 %d out of range.  s/b 1..4.", func, term_oc192);
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
  /* End of argument validation */

  CS_PRINT("%s() %s, slice_line=%d, slice_client=%d, %s, %s, %s, %s, tcm_line = %d, mld_line = %d",
           func,
           ten_module_strings[module_id_line & 1],
           slice_line,
           slice_client,
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_hl_config_traffic_types_strings[traffic_type_line],
           ten_fec_ovhd_strings[fec_line],
           ten_hl_config_oc192_overhead_term_strings[term_oc192],
           tcm_line,
           mld_line);
  if (map_odtu <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT(", %s", ten_sync_type_strings[map_odtu]);
  }
  else {
    CS_PRINT(", map_odtu = %d", map_odtu);
  }
  if (map_oxuv <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT(", %s", ten_sync_type_strings[map_oxuv]);
  }
  else {
    CS_PRINT(", map_oxuv = %d", map_oxuv);
  }
  CS_PRINT(", timeslots = %d, gmp_timeslot_mask = %d\n", timeslots, gmp_timeslot_mask);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR (dev_id);

  module_id_client = module_id_line ^ TEN_MODULE_B;
  if (rtn != CS_OK) { JUST_LOG_1(LOG_ERR, "T41", "Failed BEFORE ten_hl_n40g_config_mux_t41(), rc=%d\n", rtn);  return (CS_ERROR);}

  rtn |= ten_hl_n40g_config_mux_t41 (module_id_line,      
                                     TEN_TRAFFIC_TYPE_OC192,
                                     traffic_type_line,
                                     fec_line,
                                     slice_line,     
                                     dyn_repro,            
                                     map_odtu,
                                     timeslots,             
                                     gmp_timeslot_mask,     
                                     term_oc192,            
                                     tcm_line,              
                                     mld_line);             

if (rtn != CS_OK) { JUST_LOG_1(LOG_ERR, "T41", "Failed ten_hl_n40g_config_mux_t41, rc=%d\n", rtn);  return (CS_ERROR);}

  if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {
    /* Enable the N10G and configure it for bypass */
    rtn |= ten_hl_n40g_config (module_id_client, TEN_N40G_RX_BYPASS_SNT_MON, TEN_N40G_TX_DISABLE);
    
    rtn |= ten_mpif_global_clock_disable_n40g_n10g (dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, TEN_MPIF_N40G_DATAPATH, CS_TX_AND_RX, CS_ENABLE);
  }
if (rtn != CS_OK) { JUST_LOG_1(LOG_ERR, "T41", "Failed ten_mpif_global_clock_disable_n40g_n10g, rc=%d\n", rtn);  return (CS_ERROR);}

  rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                 slice_line,
                                 dyn_repro,
                                 TEN_TRAFFIC_TYPE_OC192,
                                 TEN_TRAFFIC_TYPE_ODTU,
                                 TEN_FEC_MODE_NOFEC,   /* FEC done in N40G */
                                 map_oxuv,             /* OTU2 mapping */
                                 map_odtu,             /* OTU3 mapping */
                                 timeslots,
                                 gmp_timeslot_mask,
                                 term_oc192,
                                 tcm_line);
if (rtn != CS_OK) { JUST_LOG_1(LOG_ERR, "T41", "Failed ten_hl_n10g_config_t41 line, rc=%d\n", rtn); return (CS_ERROR); }

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 0,                    /* Force a N10G block reset on client side */
                                 TEN_TRAFFIC_TYPE_OC192,
                                 TEN_TRAFFIC_TYPE_OC192,
                                 TEN_FEC_MODE_NOFEC,
                                 map_oxuv,             /* OTU2 mapping */
                                 TEN_MAP_DONT_CARE,    /* odtu mapping not applicable on client side*/
                                 timeslots,
                                 gmp_timeslot_mask,
                                 term_oc192,
                                 tcm_line);
if (rtn != CS_OK) { JUST_LOG_1(LOG_ERR, "T41", "Failed ten_hl_n10g_config_t41 client, rc=%d\n", rtn);  return (CS_ERROR);}

  /*rtn |= ten_hl_oc192_termination (module_id_line, module_id_client, term_oc192);*/
  /*rtn |= ten_hl_oc192_termination_path (module_id_line, slice_line, module_id_client, slice_client, term_oc192);*/
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OC192); 
if (rtn != CS_OK) { JUST_LOG_1(LOG_ERR, "T41", "Failed ten_hl_xcon_config, rc=%d\n", rtn);  return (CS_ERROR);}


  if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {
    /* Provision FEC and frame size */
    rtn |= ten_hl_config_fec_t41 (module_id_line, 0, TEN_SLICE_40G, fec_line);
if (rtn != CS_OK) { JUST_LOG_1(LOG_ERR, "T41", "Failed ten_hl_config_fec_t41() at end, rc=%d\n", rtn); return (CS_ERROR);}
  }
  return (rtn);
}


/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC192 TO OC192             */
/*                 10G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_oc192_t41(cs_uint16 module_id_line,
                                        cs_uint16 slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint16 slice_client,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 term_oc192)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Term OC192                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OC192 on the client side into OC192 on line side. */
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
/* [module_id_client] parameter specifies the client's module ID*/
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
/* [term_oc192] parameter defines the way the OC192 will be     */
/* sinked and sourced                                           */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1                 */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2                 */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3                 */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_oc192_oc192_t41";  
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);

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

  if (term_oc192 > TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_oc192 %d out of range.  s/b 1..4.", func, term_oc192);
    return (CS_ERROR);
  }

  /* Block-level code is to validate oxuv mapping */

 #if 0
  CS_PRINT("ten_hl_config_oc192_oc192_t41: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
            module_id_line, slice_line, module_id_client, slice_client,
            dyn_repro, term_oc192);
 #endif
  CS_PRINT("%s() %s, slice_line=%d, slice_client=%d, %s, %s\n",
           func,
           ten_module_strings[module_id_line & 1],
           slice_line,
           slice_client,
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_hl_config_oc192_overhead_term_strings[term_oc192]);


  
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                 slice_line,
                                 dyn_repro,
                                 TEN_TRAFFIC_TYPE_OC192,
                                 TEN_TRAFFIC_TYPE_OC192,
                                 TEN_FEC_MODE_NOFEC,
                                 TEN_MAP_DONT_CARE,
                                 TEN_MAP_DONT_CARE,
                                 8,
                                 255,
                                 term_oc192,
                                 0); /* Dummy value, tcm=0 */

  rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                 slice_client,
                                 0,                       /* Force a N10G block reset on client side */
                                 TEN_TRAFFIC_TYPE_OC192,
                                 TEN_TRAFFIC_TYPE_OC192,
                                 TEN_FEC_MODE_NOFEC,
                                 TEN_MAP_DONT_CARE,
                                 TEN_MAP_DONT_CARE,
                                 8,
                                 255,
                                 term_oc192,
                                 0); /* Dummy value, tcm=0 */


  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OC192); 

  return (rtn);
}


/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC192 OTU2 UFEC SFI4.1     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_otu2_sfi41_t41(cs_uint16 dev_id, 
                                             cs_uint16 dyn_repro,
                                             cs_uint16 traffic_type_line,
                                             cs_uint16 fec_line,
                                             cs_uint16 term_oc192,
                                             cs_uint16 tcm_line,
                                             cs_uint16 map_oxuv)
/* INPUTS     : o Device Id                                     */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Term OC192                                    */
/*              o TCM Line                                      */
/*              o Mapping Method                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OC192 on the client side into OTU2 on line side   */
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
/*   TEN_TRAFFIC_TYPE_OTU2  = 5                                 */
/*                                                              */
/* [fec_line] parameter defines fec type:                       */
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
/* [term_oc192] parameter defines the way the OC192 will be     */
/* sinked and sourced                                           */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1                 */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2                 */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3                 */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4                 */
/*                                                              */
/* The [tcm_line] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_oxuv] parameter specifies the mapping method        */
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


    T41_t *pDev = NULL;
    cs_status rtn = CS_OK;
    cs_char8 *func = "ten_hl_config_oc192_otu2v_t41";  

    TEN_MOD_COMMON_VALIDATE(dev_id, pDev, CS_ERROR); /* Bugzilla 35949 */

    if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
      return (CS_ERROR);
    }

    if (traffic_type_line != TEN_TRAFFIC_TYPE_OTU2) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 5.", func, traffic_type_line);
      return (CS_ERROR);
    }

    if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
      return (CS_ERROR);
    }

    if (term_oc192 > TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_oc192 %d out of range.  s/b 1..4.", func, term_oc192);
      return (CS_ERROR);
    }

    if (tcm_line & ~0x7E) {
      CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_line 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_line);
      return(CS_ERROR);
    }

    /* Block-level code is to validate oxuv mapping */
    CS_PRINT("%s() %s, %s, %s, %s, tcm_line = %d, %s\n",
             func,
             ten_hl_config_dyn_repro_strings[dyn_repro],
             ten_hl_config_traffic_types_strings[traffic_type_line],
             ten_fec_ovhd_strings[fec_line],
             ten_hl_config_oc192_overhead_term_strings[term_oc192],
             tcm_line,
             ten_sync_type_strings[map_oxuv]);


    /******************** First Path *********************/
    module_id_line = 0;          /* A0 */
    slice_line = 0;
    module_id_client = 1;        /* B1 */
    slice_client = 1;
    
    rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                   slice_line,
                                   dyn_repro,
                                   TEN_TRAFFIC_TYPE_OC192,
                                   traffic_type_line,
                                   fec_line,
                                   map_oxuv,
                                   TEN_MAP_DONT_CARE,
                                   8,
                                   255,
                                   term_oc192,
                                   tcm_line);

    rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                   slice_client,
                                   0,                       /* Force a N10G block reset on client side */
                                   TEN_TRAFFIC_TYPE_OC192,
                                   TEN_TRAFFIC_TYPE_OC192,
                                   TEN_FEC_MODE_NOFEC,
                                   map_oxuv,
                                   TEN_MAP_DONT_CARE,
                                   8,
                                   255,
                                   term_oc192,
                                   tcm_line);

    rtn |= ten_hl_n10g_config(module_id_line, 
                              slice_line, 
                              TEN_N10G_RX_BYPASS, 
                              TEN_N10G_TX_BYPASS, 
                              dyn_repro);

    /******************** Second Path *********************/                                
    module_id_line_int = 0;      /* A2 */
    slice_line_int = 2;
    module_id_client_int = 0;    /* A1 */
    slice_client_int = 1;

    rtn |= ten_hl_n10g_config(module_id_line_int, 
                              slice_line_int, 
                              TEN_N10G_RX_BYPASS, 
                              TEN_N10G_TX_OC192_OTU2, 
                              dyn_repro);

    rtn |= ten_hl_n10g_config(module_id_client_int, 
                              slice_client_int, 
                              TEN_N10G_RX_OTU2_OC192, 
                              TEN_N10G_TX_BYPASS, 
                              0);
    /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
    #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1)
    rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line_int, slice_line_int, CS_DISABLE);
    #endif

    rtn |= ten_hl_n10g_config_lom_from_traffic (module_id_line_int, slice_line_int, traffic_type_line, fec_line);

    /* Set up the OC192 Termination */
    rtn |= ten_hl_oc192_termination_path_line_side(module_id_line_int, slice_line_int, term_oc192);
    ten_n10g_tx_trans_term_line_bypass(module_id_line_int, slice_line_int, term_oc192);
  
    switch (map_oxuv) {
      case TEN_MAP_BMP :
      case TEN_MAP_DONT_CARE :
        rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id_line_int, slice_line_int, 0, 0, 0, 0, 0); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
        rtn |= ten_n10g_otnr_set_dwmod (module_id_client_int, slice_client_int, 1);               /* Dewrapper enabled Justification commands are ignored */
        break;
      case TEN_MAP_AMP :
          rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id_line_int, slice_line_int, 0, 0, 0, 0, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
          rtn |= ten_n10g_otnr_set_dwmod (module_id_client_int, slice_client_int, 3);               /* Dewrapper enabled Justification commands are evaluated */
        break;
      case TEN_MAP_AMP_PROP :
        rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id_line_int, slice_line_int, 0, 1, 0, 0, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
        rtn |= ten_n10g_tx_amp_prop_t41( module_id_line_int, slice_line_int, 0); /* hardcode to 0 since 0c192 client fits. For FC use pdevcb->syncdsync_thread_cb[slice].num_just_oxu2); */
        rtn |= ten_n10g_otnr_set_dwmod ( module_id_client_int, slice_client_int, 3);              /* Dewrapper enabled Justification commands are evaluated */
        rtn |= ten_n10g_rx_amp_prop_t41( module_id_client_int, slice_client_int, 0); /* hardcode to 0 since 0c192 client fits. For FC use pdevcb->syncdsync_thread_cb[slice].num_just_oxu2); */
        break;
      default :
        CS_HNDL_ERROR(module_id_line_int, ETEN_MOD_INVALID_USER_ARG, "%s: OC192->OTU2, map_oxuv=%d not supported\n", func, map_oxuv);
        rtn |= CS_ERROR;
        break;
    }

    rtn |= ten_hl_config_fec_t41 (module_id_client_int, slice_client_int, TEN_SLICE_10G, fec_line);
     
    rtn |= ten_hl_config_fec_t41 (module_id_line_int, slice_line_int, TEN_SLICE_10G, fec_line);
     
    /******************** Termination  ********************/
    if (term_oc192 == TEN_OC192_TERM_TRANSPARENT_CBR10) {
        /* RX Client */
        /* XSEL = 2, SBYPLD = 1 (bypass SONET/SDH processing) */
        /* DPCFG_XSEL needs to change */
        ten_n10g_set_gblr_dpcfg(module_id_client_int, slice_client_int,
                        2,  /* xsel */
                        0,  /* kpasel */
                        1,  /* sbypld */
                        0,  /* sbyfrm */
                        1,  /* oby */
                        0,  /* sdhoff */
                        1); /* otnoff */

        /* LOS reported to OHPP */
        /* SDH processor may optionally be used for non-intrusive monitoring */
        /* TX Line (mapping) */
        /* SBY = 1 (bypass SONET/SDH processing) */
        /* GBLT.CFGTX0_SBY (0=bypass disabled) needs to change */
        ten_n10g_set_gblt_bypasses(module_id_line_int, slice_line_int,
                        0,  /* otnoff */
                        0,  /* oby */
                        1,  /* sby */
                        1); /* kpgby */

        /* SFU inserts CBRGENAIS as consequent action if LOS detected on client RX */
        /* Optionally do this */

        /* RX Line (demapping) */
        /* XSEL = 2, SBYPLD = 1 (bypass SONET/SDH processing) */
        /* DPCFG_XSEL needs to change */
        ten_n10g_set_gblr_dpcfg(module_id_line_int, slice_line_int,
                        2,  /* xsel */
                        0,  /* kpasel */
                        1,  /* sbypld */
                        0,  /* sbyfrm */
                        0,  /* oby */
                        0,  /* sdhoff */
                        0); /* otnoff */
        /* OTN layer defects reported to OHPP */
        /* SDH processor may optionally be used for non-intrusive monitoring, otherwise set SDHE = 0 to save power */
        /* SDHE not set by the table */
  
        /* TX Client */
        /* SBY = 0 (must not bypass SONET/SDH processor for consequent action insertion) */
        /* SOHT_OHBEN0 = 0x00, SOHT_OHBEN1 = 0x00, SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion) */
        /* SOHT.OHBEN0_SCREN (1=enable SONET scrambling) need to change */
        /* SOHT.OHBEN0_A1A2RSH (1=regenerate A1A2) need to change */
        ten_n10g_soht_set_ohben0(module_id_client_int, slice_client_int,
                        0,  /* b1ie */
                        0,  /* scren */
                        0,  /* a1a2rsh */
                        0); /* a1a2ie */

        /* SFU inserts STM-AIS as consequent action if OTN defect detected on line side */
        /* Optionally do this */
    }
    else if (term_oc192 == TEN_OC192_TERM_TRANSPARENT_REGENERATOR) {
        /* RX Client Side: */
        /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
        /* SDFR_SDFCFG.SCREN = 1 */
        /* LOS , LOF, and STM-AIS reported to OHPP */
        /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
        /* Table is OK */
  
      /* TX Line Side (Mapping): */
        /* SBY = 0 (Do not bypass SONET/SDH processing) */
        /* SOHT_OHBEN0 = 0x08 (A1A2RSH), SOHT_OHBEN1 = 0x00, SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion but turn on scrambling) */
        /* SFU inserts MS-AIS (AIS-L) as consequent action if LOS/LOF/STM-AIS detected on client RX (this must include setting SOHT_OHBEN0.B1IE=1) */
        ten_n10g_set_gblt_bypasses(module_id_line_int, slice_line_int,
                        0,  /* otnoff */
                        0,  /* oby */
                        0,  /* sby */
                        1); /* kpgby */
        ten_n10g_soht_set_ohben0(module_id_line_int, slice_line_int,
                        0,  /* b1ie */
                        1,  /* scren */
                        1,  /* a1a2rsh */
                        0); /* a1a2ie */
        ten_n10g_soht_b2ie(module_id_line_int, slice_line_int, TEN_INSTANCE_ALL, 0);

        /* config_b2(module_id_line, slice_line, 0); */
        /* RX Line Side (Demapping): */
        /* XSEL = 1, SBYFRM = 0   (Framed SONET/SDH to the XCON) */
        /* SDFR_SDFCFG.SCREN = 1 */
        /* LOF and STM-AIS reported to OHPP */
        /* OTN-layer defects reported to OHPP */
        /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
        /* Table is OK */
  
        /* TX Client Side: */
        /* SBY = 0 (Do not bypass SDH Processor) */
        /* SOHT_OHBEN0 = 0x08 (A1A2RSH), SOHT_OHBEN1 = 0x00, SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion but turn on scrambling) */
        /* SFU inserts MS-AIS (AIS-L) as consequent action if LOF/STM-AIS or OTN defect detected on line RX (this must include setting SOHT_OHBEN0.B1IE=1) */
        ten_n10g_soht_set_ohben0(module_id_client_int, slice_client_int,
                        0,  /* b1ie */
                        1,  /* scren */
                        1,  /* a1a2rsh */
                        0); /* a1a2ie */
  
        ten_n10g_soht_b2ie(module_id_client_int, slice_client_int, TEN_INSTANCE_ALL, 0);
    }
    else if (term_oc192 == TEN_OC192_TERM_RS_LAYER_REGENERATOR) {
        /* RX Client Side: */
        /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
        /* SDFR_SDFCFG.SCREN = 1 */
        /* LOS , LOF, STM-AIS, RS-TIM, AIS-L defects reported to OHPP */
        /* Set SOHR_S1CFG.B1TRANS=1 */
        /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
        /* SOHR_S1CFG.B1TRANS needs to change */
        ten_n10g_sohr_set_byte_err_trans_mode(module_id_client_int, slice_client_int,
                        1,  /* b1trans */
                        0); /* b2trans */

        /* TX Line Side (Mapping): */
        /* SBY = 0 (Do not bypass SONET/SDH processing) */
        /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1 */
        /* In SOHT, enable RSOH bytes that are to be sourced (others will be transparently passed through) */
        /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
        /* SFU inserts MS-AIS (AIS-L) as consequent action if LOS/LOF/STM-AIS/MS-AIS or optionally RS-TIM  detected on client RX */
        /* B1IE needs to change */
        ten_n10g_set_gblt_bypasses(module_id_line_int, slice_line_int,
                        0,  /* otnoff */
                        0,  /* oby */
                        0,  /* sby */
                        1); /* kpgby */
                        
        ten_n10g_soht_set_ohben0(module_id_line_int, slice_line_int,
                        1,  /* b1ie */
                        1,  /* scren */
                        1,  /* a1a2rsh */
                        0); /* a1a2ie */

        /* RX Line Side (Demapping): */
        /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
        /* SDFR_SDFCFG.SCREN = 1 */
        /* LOF, STM-AIS, RS-TIM, AIS-L defects reported to OHPP */
        /* OTN-layer defects reported to OHPP */
        /* Set SOHR_S1CFG.B1TRANS=1 */
        /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
        /* B1 TRANS needs to change */
        ten_n10g_sohr_set_byte_err_trans_mode(module_id_line_int, slice_line_int,
                        1,  /* b1trans */
                        0); /* b2trans */

        /* TX Client Side: */
        /* SBY = 0 (Do not bypass SDH Processor) */
        /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1 */
        /* In SOHT, enable RSOH bytes that are to be sourced (others will be transparently passed through) */
        /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
        /* SFU inserts MS-AIS (AIS-L) as consequent action if LOF/STM-AIS/MS-AIS or optionally RS-TIM  or OTN defect detected on line RX */
        /* Table is OK */
    }
    else if (term_oc192 == TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
        /* RX Client Side: */
        /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
        /* SDFR_SDFCFG.SCREN = 1 */
        /* LOS , LOF, STM-AIS, RS-TIM, AIS-L, dEXC, dLOP, AU-AIS defects reported to OHPP */
        /* Set SOHR_S1CFG.B1TRANS=1 */
        /* Set SOHR_S1CFG.B2TRANS=1 */
        /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
        /* B1TRANS and B2TRANS need to change */
        ten_n10g_sohr_set_byte_err_trans_mode(module_id_client_int, slice_client_int,
                        1,  /* b1trans */
                        1); /* b2trans */

        /* TX Line Side (Mapping): */
        /* SBY = 0 (Do not bypass SONET/SDH processing) */
        /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1, B2IE=1 */
        /* In SOHT, enable RSOH/MSOH bytes that are to be sourced (others will be transparently passed through) */
        /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
        /* If B2 error transparency is desired, set B2TRANS=1 in SOHT_OHBEN1 */
        /* SFU inserts MS-RDI (RDI-L) as consequent action if LOF/MS-AIS detected on line RX */
        /* SFU inserts MS-REI (REI-L) based on number of B2 errors detected on line RX */
        /* SFU inserts MS-AIS (AIS-L) as consequent action if LOS/LOF/STM-AIS/MS-AIS or optionally RS-TIM/dEXC  detected on client RX */
        /* Optionally insert AU-AIS as consequent action if dLOP/AU-AIS detected on client RX */
        /* B1IE and B2IE need to change */
        ten_n10g_set_gblt_bypasses(module_id_line_int, slice_line_int,
                        0,  /* otnoff */
                        0,  /* oby */
                        0,  /* sby */
                      1); /* kpgby */
        ten_n10g_soht_set_ohben0(module_id_line_int, slice_line_int,
                        1,  /* b1ie */
                        1,  /* scren */
                        1,  /* a1a2rsh */
                        0); /* a1a2ie */
        ten_n10g_soht_b2ie(module_id_line_int, slice_line_int, TEN_INSTANCE_ALL, 0xFFFF);

        /* config_b2(module_id_line, slice_line, 0xffff); */
        /* RX Line Side (Demapping): */
        /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
        /* SDFR_SDFCFG.SCREN = 1 */
        /* LOF, STM-AIS, RS-TIM, AIS-L, dEXC, dLOP, AU-AIS defects reported to OHPP */
        /* OTN-layer defects reported to OHPP */
        /* Set SOHR_S1CFG.B1TRANS=1 */
        /* Set SOHR_S1CFG.B2TRANS=1 */
        /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
        /* B1TRANS and B2TRANS need to change */
        ten_n10g_sohr_set_byte_err_trans_mode(module_id_line_int, slice_line_int,
                        1,  /* b1trans */
                        1); /* b2trans */

        /* TX Client Side: */
        /* SBY = 0 (Do not bypass SDH Processor) */
        /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1, B2IE=1 */
        /* In SOHT, enable RSOH/MSOH bytes that are to be sourced (others will be transparently passed through) */
        /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
        /* If B2 error transparency is desired, set B2TRANS=1 in SOHT_OHBEN1 */
        /* SFU inserts MS-RDI (RDI-L) as consequent action if LOS/LOF/MS-AIS detected on client RX */
        /* SFU inserts MS-REI (REI-L) based on number of B2 errors detected on client RX */
        /* SFU inserts MS-AIS (AIS-L) as consequent action if LOF/STM-AIS/MS-AIS or optionally RS-TIM/dEXC  or OTN defect detected on line RX */
        /* Optionally insert AU-AIS as consequent action if dLOP/AU-AIS detected on line RX */
        /* B1IE and B2IE need to change */
        ten_n10g_soht_set_ohben0(module_id_client_int, slice_client_int,
                        1,  /* b1ie */
                        1,  /* scren */
                        1,  /* a1a2rsh */
                        0); /* a1a2ie */
        ten_n10g_soht_b2ie(module_id_client_int, slice_client_int, TEN_INSTANCE_ALL, 0xFFFF);
    }
    else {
      CS_HNDL_ERROR (module_id_line_int, ETEN_MOD_INVALID_USER_ARG, ": term invalid.");
      return(CS_ERROR);
    }    
        
    ten_n10g_set_otnt_wrpcfg4(module_id_line_int, slice_line_int,    /* if (sync == TEN_MAP_BMP) */
                                  0,  /* jc_plus_odtu23, */
                                  0,  /* jc_plus_otu2, */
                                  0,  /* jcen_dt, */
                                  0,  /* jcen_odtu23, */
                                  0); /* jcen_otu2 - Was 1 */
    ten_n10g_otnr_set_dwmod(module_id_line_int, slice_line_int, 1); /* Was 3 */     /* Dewrapper enabled Justification commands are ignored */
  
    ten_hl_n10g_config_pti(module_id_line_int, slice_line_int, TEN_TRAFFIC_TYPE_OC192, 1);
  
    /******************** Setup cross connects ********************/
    ten_hl_xcon_config (dev_id, 
                        (module_id_line_int & 1) * 4 + slice_line_int,
                        (module_id_client & 1) * 4 + slice_client,
                        TEN_TRAFFIC_TYPE_OC192);

    ten_hl_xcon_config (dev_id, 
                        (module_id_client_int & 1) * 4 + slice_client_int,
                        (module_id_line & 1) * 4 + slice_line,
                        TEN_TRAFFIC_TYPE_OC192);

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
