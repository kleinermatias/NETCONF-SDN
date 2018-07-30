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
 * ten_hl_config_40g_t41.c
 *
 * API's for high level 40g configuration.
 *
 * $Id: ten_hl_config_40g_t41.c,v 1.100 2013/03/18 21:20:10 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/* Bugzilla 28977 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC768 TO OTU3V             */
/*                 40G TRANSPONDER VERSION 2                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc768_otu3v_t41_v2(cs_uint16 module_id_line,
                                           cs_uint16 dyn_repro,
                                           cs_uint16 traffic_type_line,
                                           cs_uint16 fec_line,
                                           cs_uint16 term_oc768,
                                           cs_uint16 tcm_line,
                                           cs_uint16 mld_line,
                                           cs_uint16 mld_client,
                                           cs_uint16 map_oxuv,
                                           cs_uint16 timeslots,
                                           cs_uint16 deskew_ctrl)
/* INPUTS     : o Line Module Id                                */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Term OC768                                    */
/*              o TCM Line                                      */
/*              o MLD Line                                      */
/*              o MLD Client                                    */
/*              o Mapping Method                                */
/*              o Timeslots                                     */
/*              o Deskew Control                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OC768 on the client side into OTU3V on line side  */
/* Version 2 added a deskew contorl                             */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
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
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 34                               */
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
/* [term_oc768] parameter defines the way the OC192 will be     */
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
/* The [mld_client] parameter enables distributing data across  */
/* multiple lanes on client side i.e. STL256.4                  */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_oxuv] parameter specifies the client mapping method */
/*   TEN_MAP_BMP        = 1                                     */
/*   TEN_MAP_AMP        = 0                                     */
/*   TEN_MAP_AMP_PROP   = 3                                     */
/*   TEN_MAP_GMP_LO     = 5                                     */
/*                                                              */
/* The [timeslots] parameter specifies number of timeslots.     */
/* Bandwidth is always 1.25G per timeslot for GMP_HO. Whereas   */
/* for AMP it is as follows:                                    */
/* 16 timeslots  - 2.5G per timeslot                            */
/* 32 timeslots  - 1.25G per timeslot                           */
/*                                                              */
/* The [deskew_ctrl] parameter specifies the 40G deskew         */
/* facility to use                                              */
/*   TEN_SADECO_DESKEW       = 0                                */
/*   TEN_PP40G_BYPASS_DESKEW = 1                                */
/*   TEN_PP40G_DESKEW        = 2 (not applicable in this mode)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module_id_client;
  T41_t *pDev = NULL;
  cs_uint16 module_line = 0;
  cs_uint16 ncols_line;
  cs_uint16 npar_line;
  cs_uint16 ncols_client;
  cs_uint16 npar_client;
  cs_uint16 i;
  cs_status rtn = CS_OK;
  cs_uint16 traffic_type_client = TEN_TRAFFIC_TYPE_OC768;
  cs_uint16  stm256md  = 1;     /* Standard OTU fixed stuff bytes */
  cs_char8 *func = "ten_hl_config_oc768_otu3v_t41_v2";  

  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  module_id_client = module_id_line ^ TEN_MODULE_B;

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P2) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E2)) {  /* Bugzilla 28979 */
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 1, 2, 3, 23, 25, 35.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if ((term_oc768 < TEN_OC192_TERM_TRANSPARENT_CBR10) || (term_oc768 > TEN_OC192_TERM_MS_LAYER_REGENERATOR)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_oc768 %d out of range.  s/b 1..4.", func, term_oc768);
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

  if (mld_client > 1) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() mld_client %d out of range.  s/b 0..1.", func, mld_client);
    return (CS_ERROR);
  }

  if ((map_oxuv != TEN_MAP_BMP)      && (map_oxuv != TEN_MAP_AMP) &&
      (map_oxuv != TEN_MAP_AMP_PROP) && (map_oxuv != TEN_MAP_GMP_LO)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_oxuv %d out of range.  s/b 0, 1, 3 or 5.", func, map_oxuv);
    return (CS_ERROR);
  }

  /* Bugzilla 27391 Start */
  if (map_oxuv == TEN_MAP_GMP_LO) {   /* Bugzilla 31435 */
    if (timeslots != 32) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 32.", func, timeslots);
      return (CS_ERROR);
    }
  }
  else if ((map_oxuv == TEN_MAP_AMP) || (map_oxuv == TEN_MAP_AMP_DT)) {
    if ((timeslots != 16) && (timeslots != 32)) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 16 or 32.", func, timeslots);
      return (CS_ERROR);
    }
  } else {
    if (timeslots != 16){
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 16.", func, timeslots);
      return (CS_ERROR);
  } 
  }  
  /* Bugzilla 27391 Start */

  if (deskew_ctrl > TEN_PP40G_DESKEW) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() deskew_ctrl %d out of range.  s/b 0, 1, 2.", func, deskew_ctrl);
    return (CS_ERROR);
  }

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);

  CS_PRINT("%s()\n", func);
  CS_PRINT("   %s\n", ten_module_strings[module_line&1]);
  CS_PRINT("   %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("   %s\n", ten_hl_config_traffic_types_strings[traffic_type_line]);
  CS_PRINT("   %s\n", ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("   %s\n", ten_hl_config_oc192_overhead_term_strings[term_oc768]);
  CS_PRINT("   tcm_line=0x%X\n", tcm_line);
  CS_PRINT("   mld_line=%d\n", mld_line);
  CS_PRINT("   mld_client=%d\n", mld_client);
  if (map_oxuv <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("   map_oxuv=%s\n", ten_sync_type_strings[map_oxuv]);
  } else {
    CS_PRINT("   map_oxuv=%d\n", map_oxuv);
  }
  CS_PRINT("   timeslots=0x%X\n", timeslots);
  CS_PRINT("    %s\n", ten_deskew_strings[deskew_ctrl]);

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, ((line_port & 1) * 4) + 1); */  /* Bugzilla #24261 */
  /* ten_set_vco_coarse_tuning (dev_id, ((client_port & 1) * 4) + 1); */ /* Bugzilla #24261 */

 /* Bugzilla #26566 Start */
  if (map_oxuv == TEN_MAP_BMP) {
    /* Bugzilla #26250, turn off aggr mode for 40g trans */
    /* Only GPLL0 is driven with a source clock */
    ten_hsif_set_clk_40g (module_id_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0);
    ten_hsif_set_clk_40g (module_id_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0);
    
    ten_hsif_set_clk_40g (module_id_client, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0);
    ten_hsif_set_clk_40g (module_id_client, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0);
  } 
  else {
    /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
    /* Set tx pll clock and rx slice clock to slice 0 */
    /*cs_status ten_hsif_clk_40g(module_id, tx_aggr_mode, txsel, rx_aggr_mode, rxsel) */
    ten_hsif_clk_40g (module_id_line,   1, 0, 1, 0);
    ten_hsif_clk_40g (module_id_client, 1, 0, 1, 0);
  }

  /* Do not know if this is being done correctly in ten_hl_xcon_cfg(cs_uint16 dev_id, cs_uint8 slice, cs_uint8 mode) */
  for (i=0; i<8; i++) {
    ten_xcon_select_es_packet_centering (dev_id, i, XCON_PKT_CENTERING_ALL, CS_DISABLE);
    ten_xcon_set_circuit_thresholds (dev_id, i, XCON_ES_IML_THRESH, 0x1000);
  }

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_hl_n10g_config (module_id_line, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);
  rtn |= ten_hl_n10g_config (module_id_client, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);

  /* Enable clock to N40G blocks */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_ENABLE);
  /* Remove hard reset from the top of N40G block */
  rtn |= ten_mpif_global_reset_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  rtn |= ten_reg_write (dev_id,TEN_N40G_OTNT4X_WRPCFG1 + ((module_id_line & 1) * TEN_N40G_STRIDE), 0);
  rtn |= ten_reg_write (dev_id,TEN_N40G_OTNT4X_WRPCFG1 + ((module_id_client & 1) * TEN_N40G_STRIDE), 0);


  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id_line,
                                       traffic_type_client,
                                       traffic_type_line,
                                       fec_line,
                                       map_oxuv,
                                       timeslots,
                                       0xFF,
                                       term_oc768,
                                       tcm_line,
                                       mld_line,
                                       TEN_KPG_DISABLED);

  /* Bugzilla #24460, correct 40G SONET/SDH Aligner Settings */
  ten_n40g_sdfr_set_sdfcfg_fawwup_fawwdw (module_id_line, 4, 1);  /* FAWWUP, FAWWDW */
  
  /* Provision N10G part for Sonet */
  /* Disable 10G Sonet scrambler */
  rtn |= ten_n10g_soht_set_scren(module_id_line, TEN_SLICE_ALL, 0);  /* slice, scren */

  /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
  rtn |= ten_n10g_set_gblt_cfgtx0 (module_id_line, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0); /*pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie) */

  /* disable all N10G OTN wrapping */
  rtn |= ten_n10g_set_otnt_wrpcfg3(module_id_line, TEN_SLICE_ALL, 0, 0, 0, 0, 0); /*stm64md, fpsynce, c15res_en, g43md, wrmd) */

  /* Disable 10G SONET descrambler - descrambling done in N40G */
  rtn |= ten_n10g_sdfr_set_scren(module_id_line, TEN_SLICE_ALL, 0); /* slice, scren */

  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id_line, TEN_SLICE_ALL, 1, 0, 1, 0, 1, 0, 1); /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */

  /* Configure Client side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id_client,
                                       traffic_type_client,
                                       traffic_type_client,   /* No mapping */
                                       TEN_FEC_MODE_NOFEC,
                                       TEN_MAP_BMP,
                                       timeslots,
                                       0xFF,
                                       term_oc768,
                                       tcm_line,
                                       mld_client,
                                       TEN_KPG_DISABLED);
                                       
  /* Bugzilla #24460, correct 40G SONET/SDH Aligner Settings */
  ten_n40g_sdfr_set_sdfcfg_fawwup_fawwdw (module_id_client, 4, 1);  /* FAWWUP, FAWWDW */
  
  /* Disable 10G SONET descrambler - descrambling done in N40G */
  rtn |= ten_n10g_sdfr_set_scren(module_id_client, TEN_SLICE_ALL, 0);  /* slice, scren */

  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id_client, TEN_SLICE_ALL, 1, 0, 0, 0, 1, 0, 1); /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */

  /* Disable 10G Sonet scrambler */
  rtn |= ten_n10g_soht_set_scren(module_id_client, TEN_SLICE_ALL, 0);  /* slice, scren */

  /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
  rtn |= ten_n10g_set_gblt_cfgtx0 (module_id_client, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0); /*pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie)*/

  /* Disable all N10G OTN wrapping */
  rtn |= ten_n10g_otnt_set_wrmd(module_id_client, TEN_SLICE_ALL, 0);

  rtn |= ten_hl_oc768_termination (module_id_line, module_id_client, term_oc768);

  /* Provision Data Cross connect for straight accross for 40G Monolithic */
  rtn |= ten_hl_xcon_config (dev_id, 0, 4, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 1, 5, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 2, 6, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 3, 7, TEN_TRAFFIC_TYPE_OTU2);

  rtn |= ten_hl_xcon_config (dev_id, 4, 0, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 5, 1, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 6, 2, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 7, 3, TEN_TRAFFIC_TYPE_OTU2);
#if 0
  rtn |= ten_hl_xcon_config_t41 (dev_id, 0, 4, interface, mfp_mode, gfp_mode, pkt_mode, fp_align, recenter_type);
#endif

  if (deskew_ctrl == TEN_SADECO_DESKEW) {
    /* Do the deskewing in the SADECO */
    ncols_line = 254;  /* Standard OTU frame with 7% FEC */
    npar_line = 16;    /* 7% FEC */
    ncols_client = 238; /* Standard OTU payload size */
    npar_client = 0;

   #if 0
    /* ten_hl_sadeco_config (dev_id, traffic_type_module_a, traffic_type_line, client_term, ncols_module_a, ncols_module_b);*/
    rtn |= ten_hl_sadeco_config (dev_id, traffic_type_line, traffic_type_client, term_oc768, ncols_line + 1 - npar_line, ncols_client - (2*stm256md) - npar_client, module_line);
   #endif
    if (term_oc768 != TEN_OC192_TERM_TRANSPARENT_CBR10) {
      /* Bugzilla 28977 Start */
      if (ten_dev_is_t41(dev_id)) {   
        /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
        ten_xcon_sadeco_config (dev_id, module_id_client, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
        ten_xcon_sadeco_config (dev_id, module_id_line  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

        /* Enable Multi Frame Pulse mode */
        ten_xcon_es_config_t41 (dev_id, XCON_ELASTIC_STORE_ALL, XCON_ES_CONFIG_MFP_MODE, 1);
      } else {
        /* Configure the SADECO delay and compensation for Sonet SDH interleaving */
        ten_xcon_sadeco_config (dev_id, module_id_client, 0x200, 0x1F00, XCON_SONET_SDH_64);
        ten_xcon_sadeco_config (dev_id, module_id_line  , 0x200, 0x1F00, XCON_SONET_SDH_64);
      }
      /* Bugzilla 28977 End */

      /* Provision Skew and Delay Compensation Sonet Frame Length. */
      ten_xcon_sadeco_sdclen (dev_id, module_id_client, 0x97E0);    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */
      ten_xcon_sadeco_sdclen (dev_id, module_id_line,   0x97E0);    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */      
    }
    else {
      /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
      ten_xcon_sadeco_config (dev_id, module_id_client, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
      ten_xcon_sadeco_config (dev_id, module_id_line  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

      /* Provision Skew and Delay Compensation Frame Length. */
      /*ten_xcon_sadeco_sdclen (dev_id, module_id_client, 0x3B0); */   /* [255 columns - 16(FEC) - 1(OH) - 2(FS)]  * 4 */
      /*ten_xcon_sadeco_sdclen (dev_id, module_id_line,   0x3BC); */   /* [255 columns - 16(FEC)] * 4 */      
      ten_xcon_sadeco_sdclen (dev_id, module_id_client, (ncols_line - npar_line - (stm256md * 2)) * 4);    /* [255 columns - 16(FEC) - 1(OH) - 2(FS)]  * 4 */
      ten_xcon_sadeco_sdclen (dev_id, module_id_line, (ncols_client + 1) * 4);    /* [255 columns - 16(FEC)] * 4 */
      
     #if 0 
      if (ten_dev_is_t41(dev_id)) {   
        ten_n40g_rx_generate_frame_pulses_t41 (module_id_client, (ncols_line - npar_line - (stm256md * 2)) * 4));
        ten_n40g_rx_generate_frame_pulses_t41 (module_id_line, (ncols_client + 1) * 4);
      }
     #endif
    }

    /* Select incoming reference and tributary streams */
    ten_xcon_sadeco_sel_data_stream (dev_id, module_id_client, 0x0F, 0x1F);
    ten_xcon_sadeco_sel_data_stream (dev_id, module_id_line  , 0x0F, 0x1F);
    
    /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
    ten_xcon_sadeco_enable_fp (dev_id, module_id_client, CS_ENABLE);
    ten_xcon_sadeco_enable_fp (dev_id, module_id_line  , CS_ENABLE);
  } 
  else if (deskew_ctrl == TEN_PP40G_BYPASS_DESKEW) {
    /* Do the deskewing in the PP40G bypass */
    rtn |= ten_pp40g_rx_pp40g_rx_bypass_t41 (module_id_line);
    rtn |= ten_pp40g_tx_pp40g_tx_bypass_t41 (module_id_line);
    rtn |= ten_pp40g_rx_pp40g_rx_bypass_t41 (module_id_client);
    rtn |= ten_pp40g_tx_pp40g_tx_bypass_t41 (module_id_client);

    rtn |= ten_pp40g_rx_bypass_dsk_en_t41(module_id_line, 1);
    rtn |= ten_pp40g_rx_bypass_dsk_en_t41(module_id_client, 1);
  }
  else {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "TEN_PP40G_DESKEW not applicable in this mode.\n");
    return (CS_ERROR);
  }

  /* Provision FEC and frame size */
  rtn |= ten_hl_config_fec_t41 (module_id_line, 0, TEN_SLICE_40G, fec_line);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC768 TO OTU3V             */
/*                 40G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc768_otu3v_t41(cs_uint16 module_id_line,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 fec_line,
                                        cs_uint16 term_oc768,
                                        cs_uint16 tcm_line,
                                        cs_uint16 mld_line,
                                        cs_uint16 mld_client,
                                        cs_uint16 map_oxuv,
                                        cs_uint16 timeslots)
/* INPUTS     : o Line Module Id                                */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Term OC768                                    */
/*              o TCM Line                                      */
/*              o MLD Line                                      */
/*              o MLD Client                                    */
/*              o Mapping Method                                */
/*              o Timeslots                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OC768 on the client side into OTU3V on line side  */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
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
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 34                               */
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
/* [term_oc768] parameter defines the way the OC192 will be     */
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
/* The [mld_client] parameter enables distributing data across  */
/* multiple lanes on client side i.e. STL256.4                  */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_oxuv] parameter specifies the client mapping method */
/*   TEN_MAP_BMP        = 1                                     */
/*   TEN_MAP_AMP        = 0                                     */
/*   TEN_MAP_AMP_PROP   = 3                                     */
/*   TEN_MAP_GMP_LO     = 5                                     */
/*                                                              */
/* The [timeslots] parameter specifies number of timeslots.     */
/* Bandwidth is always 1.25G per timeslot for GMP_HO. Whereas   */
/* for AMP it is as follows:                                    */
/* 16 timeslots  - 2.5G per timeslot                            */
/* 32 timeslots  - 1.25G per timeslot                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_config_oc768_otu3v_t41_v2(module_id_line,
                                           dyn_repro,
                                           traffic_type_line,
                                           fec_line,
                                           term_oc768,
                                           tcm_line,
                                           mld_line,
                                           mld_client,
                                           map_oxuv,
                                           timeslots,
                                           TEN_SADECO_DESKEW));
}
/* Bugzilla 28977 End */

/* Bugzilla 28977 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU3V TO OTU3V             */
/*                 40G TRANSPONDER VERSION 2                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3v_otu3v_t41_v2(cs_uint16 module_id_line,
                                           cs_uint16 dyn_repro,
                                           cs_uint16 traffic_type_line,
                                           cs_uint16 fec_line,
                                           cs_uint16 traffic_type_client,
                                           cs_uint16 fec_client,
                                           cs_uint16 term_otu,
                                           cs_uint16 tcm_line,
                                           cs_uint16 tcm_client,
                                           cs_uint16 mld_line,
                                           cs_uint16 mld_client,
                                           cs_uint16 map_line,
                                           cs_uint16 map_client,
                                           cs_uint16 deskew_ctrl)
/* INPUTS     : o Line Module Id                                */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o FEC Type Client                               */
/*              o Term OTU                                      */
/*              o TCM Line                                      */
/*              o TCM Client                                    */
/*              o MLD Line                                      */
/*              o MLD Client                                    */
/*              o Mapping Method                                */
/*              o Deskew Control                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OTU3V on the client side into OTU3V on line side  */
/* Version 2 added a deskew control.                            */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] and [traffic_type_client] parameters     */
/* specify the traffic type of the line and client              */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 35                               */
/*                                                              */
/* [fec_line] and [fec_client] parameters define the line and   */
/* client fec type:                                             */
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
/* [term_otu] parameter defines the way the OTU2 will be        */
/* sinked and sourced                                           */
/*   TEN_OTU_TERM_TRANSPARENT = 0                               */
/*   TEN_OTU_TERM_SECTION     = 1                               */
/*                                                              */
/* The [tcm_line] and [tcm_client] parameters specify the       */
/* termination for TCM 1 through 6 for the line and client.     */
/* This is a bit encoded parameter with bits 1 through 6        */
/* specifying TCM 1 through 6 respectively.                     */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [mld_line] and [mld_client] parameters enable distribut- */
/* ing data across multiple lanes on line side i.e. OTL3.4      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_line] parameter specifies the line mapping method   */
/*   TEN_MAP_AMP        = 0                                     */
/*   TEN_MAP_BMP        = 1                                     */
/*   TEN_MAP_AMP_PROP   = 3                                     */
/*   TEN_MAP_GMP_LO     = 5                                     */
/*   TEN_MAP_GMP_HO     = 6                                     */
/*                                                              */
/* The [map_client] parameter specifies the client mapping method */
/*   TEN_MAP_AMP        = 0                                     */
/*   TEN_MAP_BMP        = 1                                     */
/*   TEN_MAP_AMP_PROP   = 3                                     */
/*   TEN_MAP_GMP_LO     = 5                                     */
/*   TEN_MAP_GMP_HO     = 6                                     */
/*                                                              */
/* The [deskew_ctrl] parameter specifies the 40G deskew         */
/* facility to use                                              */
/*   TEN_SADECO_DESKEW       = 0                                */
/*   TEN_PP40G_BYPASS_DESKEW = 1                                */
/*   TEN_PP40G_DESKEW        = 2 (not applicable in this mode)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module_id_client;
  cs_uint16 module_line;
  cs_uint16 module_client;
  cs_uint16 line_port;
  cs_uint16 client_port;
  cs_uint16 ncols_line;
  cs_uint16 npar_line;
  cs_uint16 timeslots_line;
  cs_uint16 timeslots_client;
  cs_uint16 stm64md;
  T41_t *pDev = NULL;
  cs_uint16 term_otu_line;   /* Bugzilla 26734*/
  cs_uint16 term_otu_client; /* Bugzilla 26734*/
  cs_uint16 ncols_client = 0;
  cs_uint16 npar_client = 0;
  cs_uint16 stm256md = 0;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_otu3v_otu3v_t41_v2";  

  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  module_id_client = module_id_line ^ TEN_MODULE_B;

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P2) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E2)) {  /* Bugzilla 28979 */
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 1, 2, 3, 23, 25, 35.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if ((traffic_type_client != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3P2) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E2)) {   /* Bugzilla 28979 */
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 1, 2, 3, 23, 25, 35.", func, traffic_type_client);
    return (CS_ERROR);
  }

  if (fec_client >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_client %d out of range.  s/b 0..15.", func, fec_client);
    return (CS_ERROR);
  }

  if (term_otu > TEN_OTU_TERM_SECTION) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_otu %d out of range.  s/b 0..1.", func, term_otu);
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

  if (mld_client > 1) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() mld_client %d out of range.  s/b 0..1.", func, mld_client);
    return (CS_ERROR);
  }

  if ((map_line != TEN_MAP_BMP) && (map_line != TEN_MAP_AMP) &&
      (map_line != TEN_MAP_AMP_PROP) && (map_line != TEN_MAP_GMP_LO) && (map_line != TEN_MAP_GMP_HO)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_line %d out of range.  s/b 0, 1, 3, 5 or 6.", func, map_line);
    return (CS_ERROR);
  }

  if ((map_client != TEN_MAP_BMP) && (map_client != TEN_MAP_AMP) &&
      (map_client != TEN_MAP_AMP_PROP) && (map_client != TEN_MAP_GMP_LO) && (map_client != TEN_MAP_GMP_HO)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_client %d out of range.  s/b 0, 1, 3, 5 or 6.", func, map_client);
    return (CS_ERROR);
  }

  if (deskew_ctrl > TEN_PP40G_DESKEW) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() deskew_ctrl %d out of range.  s/b 0, 1, 2.", func, deskew_ctrl);
    return (CS_ERROR);
  }

  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id_line);

  module_line   = TEN_MOD_ID_TO_MOD_NUM (module_id_line);
  module_client = module_line ^ TEN_MODULE_B;

  line_port   =  (module_id_line & 1) * 4;
  client_port =  (module_id_client & 1) * 4;

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line (%s, %s, %s)\n",  ten_module_strings[module_id_line&1], ten_hl_config_traffic_types_strings[traffic_type_line], ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("    %s\n",  ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    client (%s, %s)\n",  ten_hl_config_traffic_types_strings[traffic_type_client], ten_fec_ovhd_strings[fec_client]);
  CS_PRINT("    %s\n", ten_hl_config_otu_overhead_term_strings[term_otu]);
  CS_PRINT("    tcm_line=0x%X, mld_line=%d\n", tcm_line, mld_line);
  CS_PRINT("    tcm_client=0x%X, mld_client=%d\n", tcm_client, mld_client);
  
  if (map_line <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_line=%s\n", ten_sync_type_strings[map_line]);
  }
  else {
    CS_PRINT("    map_line=%d\n", map_line);
  }
  if (map_client <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_client=%s\n", ten_sync_type_strings[map_client]);
  }
  else {
    CS_PRINT("    map_client=%d\n", map_client);
  }
  CS_PRINT("    %s\n", ten_deskew_strings[deskew_ctrl]);
  
  /* Bugzilla 26734 Start */
  if (map_client == TEN_MAP_BMP) {
    /* Turn off aggr mode for 40g trans */
    /* Only GPLL0 is driven with a source clock */
    ten_hsif_set_clk_40g (module_id_client, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0);
    ten_hsif_set_clk_40g (module_id_client, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0);
  } else {
    /* All GPLLs are supplied with the 40G source clock.  Needed for async modes syncdsync */
    ten_hsif_set_clk_40g (module_id_client, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 1);
    ten_hsif_set_clk_40g (module_id_client, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 1);
  }
  if (map_line == TEN_MAP_BMP) {
    /* Turn off aggr mode for 40g trans */
    /* Only GPLL0 is driven with a source clock */
    ten_hsif_set_clk_40g (module_id_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0);
    ten_hsif_set_clk_40g (module_id_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0);
  } else {
    /* All GPLLs are supplied with the 40G source clock.  Needed for async modes syncdsync */
    ten_hsif_set_clk_40g (module_id_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 1);
    ten_hsif_set_clk_40g (module_id_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 1);
  }

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_hl_n10g_config (module_id_line, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);
  rtn |= ten_hl_n10g_config (module_id_client, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, TEN_INITIAL_CONFIG);  /* Bugzilla 29609 */
/*ten_n10g_config_bypass_t41(module_id_line, TEN_SLICE_ALL, cs_uint8 mode);*/
/*ten_n10g_config_bypass_t41(module_id_client, TEN_SLICE_ALL, cs_uint8 mode);*/

  /* Enable clock */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_ENABLE);
  /* Remove hard reset from the top */
  rtn |= ten_mpif_global_reset_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_RESET_DEASSERT);
  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  rtn |= ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + ((module_id_line & 1) * TEN_N40G_STRIDE), 0);
  rtn |= ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + ((module_id_client & 1) * TEN_N40G_STRIDE), 0);

  /* Bugzilla 29481 Start */
  if ((map_line == TEN_MAP_GMP_HO)) {
    timeslots_line = 32;
  }
  else {
    timeslots_line = 16;
  }
  /* Bugzilla 29481 End */

  /* Bugzilla 26734 Start */
  /* Bugzilla 29481 Start */
  if (map_client == TEN_MAP_BMP) {
    if (map_line == TEN_MAP_BMP) {
      /* Syncronous, so allow specifed termination */
      term_otu_line = term_otu;
      term_otu_client = term_otu;
    } else {
      /* Client ODU3v must be being mapped into line OPU3v */
      /* Client header will be put inside of the lines payload, so allow specifed termination */
      term_otu_line = TEN_OTU_TERM_FULL;
      term_otu_client = term_otu;
    }
  } else {
    /* Async, so line overhead will be fully terminated */
    term_otu_line = TEN_OTU_TERM_FULL;
    
   #if 0 
    if (traffic_type_client == traffic_type_line) {
      /* Line and client are the same, so header will be fully terminated */
      term_otu_client = TEN_OTU_TERM_FULL;
    } else {
      /* Client header will be put inside of the lines payload, so allow specifed termination */
      term_otu_client = term_otu;
    }
   #endif
    term_otu_client = TEN_OTU_TERM_FULL;
  }
  /* Bugzilla 29481 End */
  /* Bugzilla 26734 End */
  
  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id_line,
                                       traffic_type_client,
                                       traffic_type_line,
                                       fec_line,       /* Bugzilla 28521 */
                                       map_line,
                                       timeslots_line,
                                       0xFF,
                                       term_otu_line,  /* Bugzilla 26734 */
                                       tcm_line,
                                       mld_line,
                                       TEN_KPG_DISABLED);

  /* Bugzilla 29481 Start */
  if ((map_client == TEN_MAP_GMP_HO)) {
    timeslots_client = 32;
  }
  else {
    timeslots_client = 16;
  }
  /* Bugzilla 29481 End */

  /* Configure Client side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id_client,
                                       traffic_type_client,
                                       traffic_type_client,
                                       fec_client,       /* Bugzilla 28521 */
                                       map_client,
                                       timeslots_client,
                                       0xFF,
                                       term_otu_client,  /* Bugzilla 26734 */
                                       tcm_client,
                                       mld_client,
                                       TEN_KPG_DISABLED);

  /* Provision Data Cross connect for straight accross for 40G Monolithic */
  rtn |= ten_hl_xcon_config (dev_id, 0, 4, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 1, 5, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 2, 6, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 3, 7, TEN_TRAFFIC_TYPE_OTU2);
 
  rtn |= ten_hl_xcon_config (dev_id, 4, 0, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 5, 1, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 6, 2, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 7, 3, TEN_TRAFFIC_TYPE_OTU2);
#if 0
  rtn |= ten_hl_xcon_config_t41 (dev_id, 0, 4, interface, mfp_mode, gfp_mode, pkt_mode, fp_align, recenter_type);
#endif

  /* Bugzilla 28977 Start */
  if (deskew_ctrl == TEN_SADECO_DESKEW) {
    /* Do the deskewing in the SADECO */
    ncols_line = 254;  /* Standard OTU frame with 7% FEC */
    npar_line = 16;    /* 7% FEC */

    if (((traffic_type_line == TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_client == TEN_TRAFFIC_TYPE_OTU3)) ||
        ((traffic_type_line == TEN_TRAFFIC_TYPE_OTU3E) && (traffic_type_client == TEN_TRAFFIC_TYPE_OTU3E)) || 
        ((traffic_type_line == TEN_TRAFFIC_TYPE_OTU3E2) && (traffic_type_client == TEN_TRAFFIC_TYPE_OTU3E2))) {   /* Bugzilla 28979 */
      ncols_client = 254;  /* Standard OTU frame with 7% FEC */
      npar_client = 16;    /* 7% FEC */
    }
    else if ((traffic_type_line == TEN_TRAFFIC_TYPE_OTU3E) && (traffic_type_client == TEN_TRAFFIC_TYPE_40GELAN)) {
        ncols_line = 254;
        npar_line = 16;
        stm256md  = 1;
        stm64md = 0;
    }
    else if ((traffic_type_line == TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type_client == TEN_TRAFFIC_TYPE_CBR40G_50188149150)) {
        ncols_line = 262;
        npar_line = 19;
        stm256md  = 0;
        stm64md = 0;
    }
    rtn |= ten_hl_sadeco_config (dev_id, traffic_type_line, traffic_type_client, term_otu, ncols_line + 1 - npar_line, ncols_client + 1 - (2*stm256md) - npar_client, module_line); /* Bugzilla 28979 */
  } 
  else if (deskew_ctrl == TEN_PP40G_BYPASS_DESKEW) {
    /* Do the deskewing in the PP40G bypass */
    rtn |= ten_pp40g_rx_pp40g_rx_bypass_t41 (module_id_line);
    rtn |= ten_pp40g_tx_pp40g_tx_bypass_t41 (module_id_line);

    rtn |= ten_pp40g_rx_pp40g_rx_bypass_t41 (module_id_client);
    rtn |= ten_pp40g_tx_pp40g_tx_bypass_t41 (module_id_client);

    rtn |= ten_pp40g_rx_bypass_dsk_en_t41(module_id_line, 1);
    rtn |= ten_pp40g_rx_bypass_dsk_en_t41(module_id_client, 1);
  }
  else {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "TEN_PP40G_DESKEW not applicable in this mode.\n");
    return (CS_ERROR);
  }
  /* Bugzilla 28977 End */
 
  /* Bug #29609 - Implement 40G transponder dynamic reprovisioning, 40GEP back to OTU3 */
  if (dyn_repro != TEN_INITIAL_CONFIG) {
    ten_mpif_global_reset_pp40g_sys_t41(dev_id, TEN_MODULE_A, CS_RESET_ASSERT);
    ten_mpif_global_reset_pp40g_t41(dev_id, TEN_MODULE_A, CS_TX_AND_RX, CS_RESET_ASSERT);
    
    ten_mpif_global_reset_pp40g_sys_t41(dev_id, TEN_MODULE_B, CS_RESET_ASSERT);
    ten_mpif_global_reset_pp40g_t41(dev_id, TEN_MODULE_B, CS_TX_AND_RX, CS_RESET_ASSERT);
   
    ten_pp40g_tx_pp40g_tx_bypass_t41(module_id_line);
    ten_pp40g_rx_pp40g_rx_bypass_t41(module_id_line);

    ten_pp40g_tx_pp40g_tx_bypass_t41(module_id_client);
    ten_pp40g_rx_pp40g_rx_bypass_t41(module_id_client);

    ten_mpif_global_cfg_per_module (dev_id, module_id_client & 1, 0, 0); 

    ten_mpif_global_clock_disable_pp40g_byp_t41(dev_id, TEN_MODULE_A_AND_B, CS_ENABLE); 

    ten_n10g_tx_pp40g_disable_t41(module_id_line, TEN_SLICE0);
    ten_n10g_tx_pp40g_disable_t41(module_id_line, TEN_SLICE1);
    ten_n10g_tx_pp40g_disable_t41(module_id_line, TEN_SLICE2);
    ten_n10g_tx_pp40g_disable_t41(module_id_line, TEN_SLICE3);
    
    ten_n10g_gbl_bypcfg_rx_bypass_10g(module_id_line, TEN_SLICE0);
    ten_n10g_gbl_bypcfg_rx_bypass_10g(module_id_line, TEN_SLICE1);
    ten_n10g_gbl_bypcfg_rx_bypass_10g(module_id_line, TEN_SLICE2);
    ten_n10g_gbl_bypcfg_rx_bypass_10g(module_id_line, TEN_SLICE3);
    
    ten_pp40g_rx_bypass_dsk_en_t41(module_id_line, 0);
    
    ten_pp40g_set_pp40g_mpif_reset_t41(module_id_line);
    ten_pp40g_set_pp40g_mpif_reset_t41(module_id_client);

    if (map_line == TEN_MAP_BMP) {
      ten_n40g_clear_gmp_ho_client_data_entity_t41(module_id_line, TEN_SLICE0);
      ten_n40g_clear_gmp_ho_client_data_entity_t41(module_id_line, TEN_SLICE1);
      ten_n40g_clear_gmp_ho_client_data_entity_t41(module_id_line, TEN_SLICE2);
      ten_n40g_clear_gmp_ho_client_data_entity_t41(module_id_line, TEN_SLICE3);
      
      ten_n40g_rx_25g_ts_t41(module_id_line);
      ten_n40g_tx_25g_ts_t41(module_id_line);
      
      rtn |= ten_n40g_set_pti_byte(module_id_line, 0);
      rtn |= ten_n40g_set_expected_pti_byte(module_id_line, 0);
    }
    
    ten_n40g_global_release_sreset_t41(module_id_line);
    ten_n40g_global_release_sreset_t41(module_id_client);

    ten_pp40g_misc_clken_clear(module_id_line);
    ten_pp40g_misc_clken_clear(module_id_client);
  }
 
  /* Provision FEC */
  rtn |= ten_hl_config_fec_t41 (module_id_line, 0, TEN_SLICE_40G, fec_line);
  rtn |= ten_hl_config_fec_t41 (module_id_client, 0, TEN_SLICE_40G, fec_client);

  if (rtn != CS_OK) {
    CS_PRINT("%s()  FAILED!\n", func);
  }

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU3V TO OTU3V             */
/*                 40G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3v_otu3v_t41(cs_uint16 module_id_line,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 fec_line,
                                        cs_uint16 traffic_type_client,
                                        cs_uint16 fec_client,
                                        cs_uint16 term_otu,
                                        cs_uint16 tcm_line,
                                        cs_uint16 tcm_client,
                                        cs_uint16 mld_line,
                                        cs_uint16 mld_client,
                                        cs_uint16 map_oxuv)
/* INPUTS     : o Line Module Id                                */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o FEC Type Client                               */
/*              o Term OTU                                      */
/*              o TCM Line                                      */
/*              o TCM Client                                    */
/*              o MLD Line                                      */
/*              o MLD Client                                    */
/*              o Mapping Method                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OTU3V on the client side into OTU3V on line side  */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] and [traffic_type_client] parameters     */
/* specify the traffic type of the line and client              */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 35                               */
/*                                                              */
/* [fec_line] and [fec_client] parameters define the line and   */
/* client fec type:                                             */
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
/* [term_otu] parameter defines the way the OTU2 will be        */
/* sinked and sourced                                           */
/*   TEN_OTU_TERM_TRANSPARENT = 0                               */
/*   TEN_OTU_TERM_SECTION     = 1                               */
/*                                                              */
/* The [tcm_line] and [tcm_client] parameters specify the       */
/* termination for TCM 1 through 6 for the line and client.     */
/* This is a bit encoded parameter with bits 1 through 6        */
/* specifying TCM 1 through 6 respectively.                     */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [mld_line] and [mld_client] parameters enable distribut- */
/* ing data across multiple lanes on line side i.e. OTL3.4      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_oxuv] parameter specifies the client mapping method */
/*   TEN_MAP_AMP        = 0                                     */
/*   TEN_MAP_BMP        = 1                                     */
/*   TEN_MAP_AMP_PROP   = 3                                     */
/*   TEN_MAP_GMP_LO     = 5                                     */
/*   TEN_MAP_GMP_HO     = 6                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_config_otu3v_otu3v_t41_v2(module_id_line,
                                           dyn_repro,
                                           traffic_type_line,
                                           fec_line,
                                           traffic_type_client,
                                           fec_client,
                                           term_otu,
                                           tcm_line,
                                           tcm_client,
                                           mld_line,
                                           mld_client,
                                           map_oxuv,
                                           TEN_MAP_BMP,
                                           TEN_SADECO_DESKEW));
}
/* Bugzilla 28977 Start */


/* Bugzilla 28977 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU3V OC768 OTU3V          */
/*                 40G TRANSPONDER VERSION 2                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3v_oc768_otu3v_t41_v2 (cs_uint16 module_id_line,
                                                  cs_uint16 dyn_repro,
                                                  cs_uint16 traffic_type_line,
                                                  cs_uint16 fec_line,
                                                  cs_uint16 traffic_type_client,
                                                  cs_uint16 fec_client,
                                                  cs_uint16 xcon_client_type,
                                                  cs_uint16 term_oc768,
                                                  cs_uint16 tcm_line,
                                                  cs_uint16 tcm_client,
                                                  cs_uint16 mld_line,
                                                  cs_uint16 mld_client,
                                                  cs_uint16 map_line,
                                                  cs_uint16 map_client,
                                                  cs_uint16 deskew_ctrl)

/* INPUTS     : o Line Module Id                                */
/*              o Dynamic Reprovision                           */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o FEC Type Client                               */
/*              o XCON Client Type                              */
/*              o Term OC768                                    */
/*              o TCM Line                                      */
/*              o TCM Client                                    */
/*              o MLD Line                                      */
/*              o MLD Client                                    */
/*              o Mapping Method for Line                       */
/*              o Mapping Method for Client                     */
/*              o Deskew Control                                */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Demaps OTU3V on the client side and remaps onto OTU3V on     */
/* the line side with oc768 at the xcon                         */
/* Version 2 added a deskew contorl                             */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] and [traffic_type_client] parameters     */
/* specify the traffic type of the line and client              */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*                                                              */
/* [fec_line] and [fec_client] parameters define the line and   */
/* client fec type:                                             */
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
/* [xcon_client_type] parameter defines the ODU signal type     */
/*   TEN_TRAFFIC_TYPE_OC768         = 22                        */
/*                                                              */
/* [term_oc768] parameter defines the way the OC192 will be     */
/* sinked and sourced                                           */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1                 */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2                 */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3                 */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4                 */
/*                                                              */
/* The [tcm_line] and [tcm_client] parameters specify the       */
/* termination for TCM 1 through 6 for the line and client.     */
/* This is a bit encoded parameter with bits 1 through 6        */
/* specifying TCM 1 through 6 respectively.                     */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [mld_line] and [mld_client] parameters enable distribut- */
/* ing data across multiple lanes on line or client side        */
/* i.e. OTL3.4                                                  */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_line] parameter specifies the line mapping method   */
/*   TEN_MAP_AMP           = 0                                  */
/*   TEN_MAP_BMP           = 1                                  */
/*   TEN_MAP_AMP_PROP      = 3                                  */
/*   TEN_MAP_GMP_HO        = 6                                  */
/*                                                              */
/* The [map_client] parameter specifies the client mapping      */ 
/* method                                                       */
/*   TEN_MAP_AMP           = 0                                  */
/*   TEN_MAP_BMP           = 1                                  */
/*   TEN_MAP_AMP_PROP      = 3                                  */
/*   TEN_MAP_GMP_HO        = 6                                  */
/*                                                              */
/* The [deskew_ctrl] parameter specifies the 40G deskew         */
/* facility to use                                              */
/*   TEN_SADECO_DESKEW       = 0                                */
/*   TEN_PP40G_BYPASS_DESKEW = 1                                */
/*   TEN_PP40G_DESKEW        = 2                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  T41_t *pDev = NULL;
  ten_dev_cb_t *pdevcb;         /* Bugzilla 26784 */
  cs_uint16 module_id_client;
  cs_uint16 timeslots;
  cs_uint16 i;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_otu3v_oc768_otu3v_t41";  

  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  module_id_client = module_id_line ^ TEN_MODULE_B;

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P2)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 1, 2, 3, 23, 25.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if ((traffic_type_client != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3P2)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 1, 2.", func, traffic_type_client);
    return (CS_ERROR);
  }

  if (fec_client >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_client %d out of range.  s/b 0..15.", func, fec_client);
    return (CS_ERROR);
  }

  if (xcon_client_type != TEN_TRAFFIC_TYPE_OC768) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() xcon_client_type %d out of range.  s/b 22.", func, xcon_client_type);
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

  if (mld_client > 1) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() mld_client %d out of range.  s/b 0..1.", func, mld_client);
    return (CS_ERROR);
  }

  if ((map_line != TEN_MAP_AMP) &&
      (map_line != TEN_MAP_BMP) &&
      (map_line != TEN_MAP_AMP_PROP) && (map_line != TEN_MAP_GMP_LO) && (map_line != TEN_MAP_GMP_HO)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_line %d out of range.  s/b 0, 1, 3, 5 or 6.", func, map_line);
    return (CS_ERROR);
  }
  if ((map_client != TEN_MAP_AMP) &&
      (map_client != TEN_MAP_BMP) &&
      (map_client != TEN_MAP_AMP_PROP) && (map_client != TEN_MAP_GMP_LO) && (map_client != TEN_MAP_GMP_HO)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_client %d out of range.  s/b 0, 1, 3, 5 or 6.", func, map_client);
    return (CS_ERROR);
  }

  if (deskew_ctrl > TEN_PP40G_DESKEW) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() deskew_ctrl %d out of range.  s/b 0, 1, 2.", func, deskew_ctrl);
    return (CS_ERROR);
  }

  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);    /* Bugzilla 26784 */

  CS_PRINT("%s()\n", func);
  CS_PRINT("    module_id_line = %s\n", ten_module_strings[module_id_line&1]);
  CS_PRINT("    %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    traffic_type_line = %s\n", ten_hl_config_traffic_types_strings[traffic_type_line]);
  CS_PRINT("    fec_line = %s\n", ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("    traffic_type_client = %s\n", ten_hl_config_traffic_types_strings[traffic_type_client]);
  CS_PRINT("    fec_client =%s\n", ten_fec_ovhd_strings[fec_client]);
  CS_PRINT("    xcon_client_type = %s\n", ten_hl_config_traffic_types_strings[xcon_client_type]);
  CS_PRINT("    term_oc768 = %s\n", ten_hl_config_oc192_overhead_term_strings[term_oc768]);
  CS_PRINT("    tcm_line=0x%X\n", tcm_line);
  CS_PRINT("    tcm_client=0x%X\n", tcm_client);
  CS_PRINT("    mld_line=%d\n",  mld_line);
  CS_PRINT("    mld_client=%d\n", mld_client);
  if (map_line <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_line=%s\n", ten_sync_type_strings[map_line]);
  }
  else {
    CS_PRINT("    map_line=%d\n", map_line);
  }

  if (map_client <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_client=%s\n", ten_sync_type_strings[map_client]);
  }
  else {
    CS_PRINT("    map_client=%d\n", map_client);
  }
  CS_PRINT("    %s\n", ten_deskew_strings[deskew_ctrl]);

  /* All GPLLs are supplied with the 40G source clock.  Needed for async modes syncdsync */
  rtn |= ten_hsif_set_clk_40g (module_id_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 1);
  rtn |= ten_hsif_set_clk_40g (module_id_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 1);
  
  rtn |= ten_hsif_set_clk_40g (module_id_client, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 1);
  rtn |= ten_hsif_set_clk_40g (module_id_client, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 1);

  /* duplicate call -- already done during HSIF provisioning */
  /* rtn |= ten_set_vco_coarse_tuning (dev_id, ((line_port & 1) * 4) + 1); */
  /* rtn |= ten_set_vco_coarse_tuning (dev_id, ((client_port & 1) * 4) + 1); */

  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  /*cs_status ten_hsif_clk_40g(module_id, tx_aggr_mode, txsel, rx_aggr_mode, rxsel) */
  rtn |= ten_hsif_clk_40g (module_id_line,   1, 0, 1, 0);
  rtn |= ten_hsif_clk_40g (module_id_client, 1, 0, 1, 0);

  /* Do not know if this is being done correctly in ten_hl_xcon_cfg(cs_uint16 dev_id, cs_uint8 slice, cs_uint8 mode) */
  for (i=0; i<8; i++) {
    rtn |= ten_xcon_select_es_packet_centering (dev_id, i, XCON_PKT_CENTERING_ALL, CS_DISABLE);
    rtn |= ten_xcon_set_circuit_thresholds (dev_id, i, XCON_ES_IML_THRESH, 0x1000);
  }

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_hl_n10g_config (module_id_line, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);
  rtn |= ten_hl_n10g_config (module_id_client, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);
/*ten_n10g_config_bypass_t41(module_id_line, TEN_SLICE_ALL, cs_uint8 mode);*/
/*ten_n10g_config_bypass_t41(module_id_client, TEN_SLICE_ALL, cs_uint8 mode);*/

  /* Enable clock */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_ENABLE);
  /* Remove hard reset from the top */
  rtn |= ten_mpif_global_reset_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  rtn |= ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + ((module_id_line & 1) * TEN_N40G_STRIDE), 0);
  rtn |= ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + ((module_id_client & 1) * TEN_N40G_STRIDE), 0);

  if ((map_line == TEN_MAP_GMP_HO) || (map_line == TEN_MAP_GMP_LO)) {
    timeslots = 32;
  } else {
    timeslots = 16;
  }
  
  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id_line,
                                       xcon_client_type,
                                       traffic_type_line,
                                       fec_line,
                                       map_line,
                                       timeslots,
                                       0xFF,
                                       term_oc768,
                                       tcm_line,
                                       mld_line,
                                       TEN_KPG_DISABLED);
  
  /* Provision N10G part for Sonet */
  /* Disable 10G Sonet scrambler */
  rtn |= ten_n10g_soht_set_scren(module_id_line, TEN_SLICE_ALL, 0);  /* slice, scren */

  /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
  rtn |= ten_n10g_set_gblt_cfgtx0 (module_id_line, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0); /*pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie) */

  /* disable all N10G OTN wrapping */
  rtn |= ten_n10g_set_otnt_wrpcfg3(module_id_line, TEN_SLICE_ALL, 0, 0, 0, 0, 0); /*stm64md, fpsynce, c15res_en, g43md, wrmd) */

  /* Disable 10G SONET descrambler - descrambling done in N40G */
  rtn |= ten_n10g_sdfr_set_scren(module_id_line, TEN_SLICE_ALL, 0); /* slice, scren */

  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id_line, TEN_SLICE_ALL, 1, 0, 1, 0, 1, 0, 1); /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */
  
  
  
  if ((map_client == TEN_MAP_GMP_HO) || (map_client == TEN_MAP_GMP_LO)) {
    timeslots = 32;
  } else {
    timeslots = 16;
  }
  
  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id_client,
                                       xcon_client_type,
                                       traffic_type_client,
                                       fec_client,
                                       map_client,
                                       timeslots,
                                       0xFF,
                                       term_oc768,
                                       tcm_client,
                                       mld_client,
                                       TEN_KPG_DISABLED);
  
  /* Provision N10G part for Sonet */
  /* Disable 10G Sonet scrambler */
  rtn |= ten_n10g_soht_set_scren(module_id_client, TEN_SLICE_ALL, 0);  /* slice, scren */

  /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
  rtn |= ten_n10g_set_gblt_cfgtx0 (module_id_client, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0); /*pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie) */

  /* disable all N10G OTN wrapping */
  rtn |= ten_n10g_set_otnt_wrpcfg3(module_id_client, TEN_SLICE_ALL, 0, 0, 0, 0, 0); /*stm64md, fpsynce, c15res_en, g43md, wrmd) */

  /* Disable 10G SONET descrambler - descrambling done in N40G */
  rtn |= ten_n10g_sdfr_set_scren(module_id_client, TEN_SLICE_ALL, 0); /* slice, scren */

  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id_client, TEN_SLICE_ALL, 1, 0, 1, 0, 1, 0, 1); /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */
  
  
  
  rtn |= ten_hl_oc768_termination (module_id_line, module_id_client, term_oc768);
 
  

  /* Provision Data Cross connect for straight accross for 40G Monolithic */
  rtn |= ten_hl_xcon_config (dev_id, 0, 4, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 1, 5, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 2, 6, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 3, 7, TEN_TRAFFIC_TYPE_OTU2);

  rtn |= ten_hl_xcon_config (dev_id, 4, 0, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 5, 1, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 6, 2, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 7, 3, TEN_TRAFFIC_TYPE_OTU2);
#if 0
  rtn |= ten_hl_xcon_config_t41 (dev_id, 0, 4, interface, mfp_mode, gfp_mode, pkt_mode, fp_align, recenter_type);
#endif

  if (deskew_ctrl == TEN_SADECO_DESKEW) {
   #if 0
    ncols_line = 254;  /* Standard OTU frame with 7% FEC */
    npar_line = 16;    /* 7% FEC */
      stm256md  = 1;
      stm64md = 0;

    rtn |= ten_hl_sadeco_config (dev_id, traffic_type_line, traffic_type_client, term_otu, ncols_line + 1 - npar_line, ncols_client - (2*stm256md) - npar_client, module_line);
   #endif

    /* Bugzilla 28977 Start */
    if (ten_dev_is_t41(dev_id)) {   
      /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
      rtn |= ten_xcon_sadeco_config (dev_id, module_id_client, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
      rtn |= ten_xcon_sadeco_config (dev_id, module_id_line  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

      /* Enable Multi Frame Pulse mode */
      rtn |= ten_xcon_es_config_t41 (dev_id, XCON_ELASTIC_STORE_ALL, XCON_ES_CONFIG_MFP_MODE, 1);
    } else {
      /* Configure the SADECO delay and compensation for Sonet SDH interleaving */
      rtn |= ten_xcon_sadeco_config (dev_id, module_id_client, 0x200, 0x1F00, XCON_SONET_SDH_64);
      rtn |= ten_xcon_sadeco_config (dev_id, module_id_line  , 0x200, 0x1F00, XCON_SONET_SDH_64);
    }  
    /* Bugzilla 28977 End */

    /* Provision Skew and Delay Compensation Sonet Frame Length. */
    rtn |= ten_xcon_sadeco_sdclen (dev_id, module_id_client, 0x97E0);    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */
    rtn |= ten_xcon_sadeco_sdclen (dev_id, module_id_line,   0x97E0);    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */      

    /* Select incoming reference and tributary streams */
    rtn |= ten_xcon_sadeco_sel_data_stream (dev_id, module_id_client, 0x0F, 0x1F);
    rtn |= ten_xcon_sadeco_sel_data_stream (dev_id, module_id_line  , 0x0F, 0x1F);
    
    /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
    rtn |= ten_xcon_sadeco_enable_fp (dev_id, module_id_client, CS_ENABLE);
    rtn |= ten_xcon_sadeco_enable_fp (dev_id, module_id_line  , CS_ENABLE);
  } else {
    /* Do the deskewing in the PP40G bypass */
    rtn |= ten_pp40g_rx_pp40g_rx_bypass_t41 (module_id_line);
    rtn |= ten_pp40g_tx_pp40g_tx_bypass_t41 (module_id_line);

    rtn |= ten_pp40g_rx_pp40g_rx_bypass_t41 (module_id_client);
    rtn |= ten_pp40g_tx_pp40g_tx_bypass_t41 (module_id_client);

    rtn |= ten_pp40g_rx_bypass_dsk_en_t41(module_id_line, 1);
    rtn |= ten_pp40g_rx_bypass_dsk_en_t41(module_id_client, 1);
  }
  
  rtn |= ten_hl_config_fec_t41 (module_id_line, 0, TEN_SLICE_40G, fec_line);
  rtn |= ten_hl_config_fec_t41 (module_id_client, 0, TEN_SLICE_40G, fec_client);

  #if 0 /* Bugzilla #31390, this is done in ten_hl_config_trans_t41 */
  rtn |= ten_hl_n40g_config_lom_from_traffic (module_id_line, traffic_type_line, fec_line);
  rtn |= ten_hl_n40g_config_lom_from_traffic (module_id_client, traffic_type_client, fec_client);

  /* Bugzilla #31390, set obfa2 lom */
  rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id_line, traffic_type_line, fec_line);
  rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id_client, traffic_type_client, fec_client);
  #endif
  
  rtn |= ten_hl_n40g_otn_aligner_settings (module_id_line);
  rtn |= ten_hl_n40g_otn_aligner_settings (module_id_client);

  rtn |= ten_n40g_sdfr_lofcfg2_m0byte(module_id_line, 1);
  rtn |= ten_n40g_sdfr_lofcfg2_m0byte(module_id_client, 1);

  if (rtn != CS_OK) {
    CS_PRINT("%s() FAILED!\n", func);
  }

  return (rtn);
}
/* Bugzilla 28977 End */

/* Bugzilla 28977 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU3V OC768 OTU3V          */
/*                 40G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3v_oc768_otu3v_t41 (cs_uint16 module_id_line,
                                               cs_uint16 dyn_repro,
                                               cs_uint16 traffic_type_line,
                                               cs_uint16 fec_line,
                                               cs_uint16 traffic_type_client,
                                               cs_uint16 fec_client,
                                               cs_uint16 xcon_client_type,
                                               cs_uint16 term_oc768,
                                               cs_uint16 tcm_line,
                                               cs_uint16 tcm_client,
                                               cs_uint16 mld_line,
                                               cs_uint16 mld_client,
                                               cs_uint16 map_line,
                                               cs_uint16 map_client)

/* INPUTS     : o Line Module Id                                */
/*              o Dynamic Reprovision                           */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o FEC Type Client                               */
/*              o XCON Client Type                              */
/*              o Term OC768                                    */
/*              o TCM Line                                      */
/*              o TCM Client                                    */
/*              o MLD Line                                      */
/*              o MLD Client                                    */
/*              o Mapping Method for Line                       */
/*              o Mapping Method for Client                     */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Demaps OTU3V on the client side and remaps onto OTU3V on     */
/* the line side with oc768 at the xcon                         */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] and [traffic_type_client] parameters     */
/* specify the traffic type of the line and client              */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*                                                              */
/* [fec_line] and [fec_client] parameters define the line and   */
/* client fec type:                                             */
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
/* [xcon_client_type] parameter defines the ODU signal type     */
/*   TEN_TRAFFIC_TYPE_OC768         = 22                        */
/*                                                              */
/* [term_oc768] parameter defines the way the OC192 will be     */
/* sinked and sourced                                           */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1                 */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2                 */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3                 */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4                 */
/*                                                              */
/* The [tcm_line] and [tcm_client] parameters specify the       */
/* termination for TCM 1 through 6 for the line and client.     */
/* This is a bit encoded parameter with bits 1 through 6        */
/* specifying TCM 1 through 6 respectively.                     */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [mld_line] and [mld_client] parameters enable distribut- */
/* ing data across multiple lanes on line or client side        */
/* i.e. OTL3.4                                                  */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_line] parameter specifies the line mapping method   */
/*   TEN_MAP_AMP           = 0                                  */
/*   TEN_MAP_BMP           = 1                                  */
/*   TEN_MAP_AMP_PROP      = 3                                  */
/*   TEN_MAP_GMP_HO        = 6                                  */
/*                                                              */
/* The [map_client] parameter specifies the client mapping      */ 
/* method                                                       */
/*   TEN_MAP_AMP           = 0                                  */
/*   TEN_MAP_BMP           = 1                                  */
/*   TEN_MAP_AMP_PROP      = 3                                  */
/*   TEN_MAP_GMP_HO        = 6                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_config_otu3v_oc768_otu3v_t41_v2 (module_id_line,
                                                  dyn_repro,
                                                  traffic_type_line,
                                                  fec_line,
                                                  traffic_type_client,
                                                  fec_client,
                                                  xcon_client_type,
                                                  term_oc768,
                                                  tcm_line,
                                                  tcm_client,
                                                  mld_line,
                                                  mld_client,
                                                  map_line,
                                                  map_client,
                                                  TEN_SADECO_DESKEW));
}
/* Bugzilla 28977 End */

/* Bugzilla 28006 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU3V 40GE OTU3V           */
/*                 40G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3v_40ge_otu3v_t41 (cs_uint16 module_id_line,
                                              cs_uint16 dyn_repro,
                                              cs_uint16 traffic_type_line,
                                              cs_uint16 fec_line,
                                              cs_uint16 traffic_type_client,
                                              cs_uint16 fec_client,
                                              cs_uint16 xcon_client_type,
                                              cs_uint16 pre_line_rx,
                                              cs_uint16 pre_line_tx,
                                              cs_uint16 pre_client_rx,
                                              cs_uint16 pre_client_tx,
                                              cs_uint16 tcm_line,
                                              cs_uint16 tcm_client,
                                              cs_uint16 mld_line,
                                              cs_uint16 mld_client,
                                              cs_uint16 map_line,
                                              cs_uint16 map_client,
                                              cs_uint16 deskew_ctrl,
                                              cs_uint16 sysclk)

/* INPUTS     : o Line Module Id                                */
/*              o Dynamic Reprovision                           */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o FEC Type Client                               */
/*              o XCON Client Type                              */
/*              o Pre Line RX                                   */
/*              o Pre Line TX                                   */
/*              o Pre Client RX                                 */
/*              o Pre Client TX                                 */
/*              o TCM Line                                      */
/*              o TCM Client                                    */
/*              o MLD Line                                      */
/*              o MLD Client                                    */
/*              o Mapping Method for Line                       */
/*              o Mapping Method for Client                     */
/*              o Deskew at PP40G                               */
/*              o System Clock                                  */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Demaps OTU3V on the client side and remaps onto OTU3V on     */
/* the line side with oc768 at the xcon                         */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type_line] and [traffic_type_client] parameters     */
/* specify the traffic type of the line and client              */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*                                                              */
/* [fec_line] and [fec_client] parameters define the line and   */
/* client fec type:                                             */
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
/* [xcon_client_type] parameter defines the ODU signal type     */
/*   TEN_TRAFFIC_TYPE_OC768         = 22                        */
/*   TEN_TRAFFIC_TYPE_SERIAL_40GE   = 41                        */
/*                                                              */
/* [pre_line_rx], and [pre_client_rx] parameters are specified  */
/* as:                                                          */
/*   TEN_PP40G_RX_DISABLE              = 0                      */
/*   TEN_PP40G_RX_BYPASS               = 1                      */
/*   TEN_PP40G_RX_40GEP_XCON           = 2                      */
/*   TEN_PP40G_RX_40GESBI_XCON         = 3                      */
/*   TEN_PP40G_RX_40GES6466_XCON       = 4                      */
/*   TEN_PP40G_RX_40GEX_XCON           = 5                      */
/*   TEN_PP40G_RX_40GEP_XCON_RA        = 6                      */
/*   TEN_PP40G_RX_40GESBI_XCON_RA      = 7                      */
/*   TEN_PP40G_RX_40GES6466_XCON_RA    = 8                      */
/*   TEN_PP40G_RX_40GEX_XCON_RA        = 9                      */
/*                                                              */
/* [pre_line_tx], and [pre_client_tx] parameters are specified  */
/* as:                                                          */
/*   TEN_PP40G_TX_DISABLE              = 0                      */
/*   TEN_PP40G_TX_BYPASS               = 1                      */
/*   TEN_PP40G_TX_XCON_40GEP           = 2                      */
/*   TEN_PP40G_TX_XCON_40GESBI         = 3                      */
/*   TEN_PP40G_TX_XCON_40GES6466       = 4                      */
/*   TEN_PP40G_TX_XCON_40GEX           = 5                      */
/*   TEN_PP40G_TX_XCON_40GEP_RA        = 6                      */
/*   TEN_PP40G_TX_XCON_40GESBI_RA      = 7                      */
/*   TEN_PP40G_TX_XCON_40GES6466_RA    = 8                      */
/*   TEN_PP40G_TX_XCON_40GEX_RA        = 9                      */
/*   TEN_PP40G_TX_PBERT_40GEP          = 10                     */
/*   TEN_PP40G_TX_PBERT_40GESBI        = 11                     */
/*   TEN_PP40G_TX_PBERT_40GES6466      = 12                     */
/*   TEN_PP40G_TX_PBERT_40GEX          = 13                     */
/*                                                              */
/* The [tcm_line] and [tcm_client] parameters specify the       */
/* termination for TCM 1 through 6 for the line and client.     */
/* This is a bit encoded parameter with bits 1 through 6        */
/* specifying TCM 1 through 6 respectively.                     */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [mld_line] and [mld_client] parameters enable distribut- */
/* ing data across multiple lanes on line or client side        */
/* i.e. OTL3.4                                                  */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_line] parameter specifies the line mapping method   */
/*   TEN_MAP_AMP           = 0                                  */
/*   TEN_MAP_BMP           = 1                                  */
/*   TEN_MAP_AMP_PROP      = 3                                  */
/*   TEN_MAP_GMP_HO        = 6                                  */
/*                                                              */
/* The [map_client] parameter specifies the client mapping      */ 
/* method                                                       */
/*   TEN_MAP_AMP           = 0                                  */
/*   TEN_MAP_BMP           = 1                                  */
/*   TEN_MAP_AMP_PROP      = 3                                  */
/*   TEN_MAP_GMP_HO        = 6                                  */
/*                                                              */
/* The [deskew_ctrl] parameter is specified as:                 */
/*   TEN_SADECO_DESKEW       = 0	                            */
/*   TEN_PP40G_BYPASS_DESKEW = 1                                */
/*   TEN_PP40G_DESKEW        = 2                                */
/*                                                              */
/* [sysclk] parameter specifies the sysclk frequency in MHz.    */
/*   For example, 400.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  T41_t *pDev = NULL;
  ten_dev_cb_t *pdevcb;         /* Bugzilla 26784 */
  cs_uint16 module_id_client;
  cs_uint16 timeslots;
  cs_uint16 i;

  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_otu3v_40ge_otu3v_t41";  

  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  module_id_client = module_id_line ^ TEN_MODULE_B;

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P2)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 1, 2, 3, 23, 25.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if ((traffic_type_client != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3P2)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 1, 2.", func, traffic_type_client);
    return (CS_ERROR);
  }

  if (fec_client >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_client %d out of range.  s/b 0..15.", func, fec_client);
    return (CS_ERROR);
  }

  if (pre_line_rx >= TEN_PP40G_RX_MAX_MODE) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() pre_line_rx %d out of range.  s/b 0..%d.", func, pre_line_rx, TEN_PP40G_RX_MAX_MODE);
    return(CS_ERROR);
  }
  if (pre_line_tx >= TEN_PP40G_TX_MAX_MODE) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() pre_line_tx %d out of range.  s/b 0..%d.", func, pre_line_tx, TEN_PP40G_TX_MAX_MODE);
    return(CS_ERROR);
  }
  if (pre_client_rx >= TEN_PP40G_RX_MAX_MODE) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() pre_client_rx %d out of range.  s/b 0..%d.", func, pre_client_rx,TEN_PP40G_RX_MAX_MODE);
    return(CS_ERROR);
  }
  if (pre_client_tx >= TEN_PP40G_TX_MAX_MODE) {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() pre_client_tx %d out of range.  s/b 0..%d.", func, pre_client_tx, TEN_PP40G_TX_MAX_MODE);
    return(CS_ERROR);
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

  if (mld_client > 1) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() mld_client %d out of range.  s/b 0..1.", func, mld_client);
    return (CS_ERROR);
  }

  if ((map_line != TEN_MAP_AMP) &&
      (map_line != TEN_MAP_BMP) &&
      (map_line != TEN_MAP_AMP_PROP) && (map_line != TEN_MAP_GMP_LO) && (map_line != TEN_MAP_GMP_HO)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_line %d out of range.  s/b 0, 1, 3, 5 or 6.", func, map_line);
    return (CS_ERROR);
  }
  if ((map_client != TEN_MAP_AMP) &&
      (map_client != TEN_MAP_BMP) &&
      (map_client != TEN_MAP_AMP_PROP) && (map_client != TEN_MAP_GMP_LO) && (map_client != TEN_MAP_GMP_HO)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_client %d out of range.  s/b 0, 1, 3, 5 or 6.", func, map_client);
    return (CS_ERROR);
  }

  if (deskew_ctrl > TEN_PP40G_DESKEW) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() deskew_ctrl %d out of range.  s/b 0, 1, 2.", func, deskew_ctrl);
    return (CS_ERROR);
  }

  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);    /* Bugzilla 26784 */

  CS_PRINT("%s()\n", func);
  CS_PRINT("    module_id_line = %s\n", ten_module_strings[module_id_line&1]);
  CS_PRINT("    %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    traffic_type_line = %s\n", ten_hl_config_traffic_types_strings[traffic_type_line]);
  CS_PRINT("    fec_line = %s\n", ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("    traffic_type_client = %s\n", ten_hl_config_traffic_types_strings[traffic_type_client]);
  CS_PRINT("    fec_client =%s\n", ten_fec_ovhd_strings[fec_client]);
  CS_PRINT("    xcon_client_type = %s\n", ten_hl_config_traffic_types_strings[xcon_client_type]);
  CS_PRINT("    pre_line_rx = %s\n", ten_pp40g_rx_debug_str[pre_line_rx]);
  CS_PRINT("    pre_line_tx = %s\n", ten_pp40g_tx_debug_str[pre_line_tx]);
  CS_PRINT("    pre_client_rx = %s\n", ten_pp40g_rx_debug_str[pre_client_rx]);
  CS_PRINT("    pre_client_tx = %s\n", ten_pp40g_tx_debug_str[pre_client_tx]);
  CS_PRINT("    tcm_line=0x%X\n", tcm_line);
  CS_PRINT("    tcm_client=0x%X\n", tcm_client);
  CS_PRINT("    mld_line=%d\n",  mld_line);
  CS_PRINT("    mld_client=%d\n", mld_client);
  if (map_line <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_line=%s\n", ten_sync_type_strings[map_line]);
  }
  else {
    CS_PRINT("    map_line=%d\n", map_line);
  }

  if (map_client <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_client=%s\n", ten_sync_type_strings[map_client]);
  }
  else {
    CS_PRINT("    map_client=%d\n", map_client);
  }
  CS_PRINT("    %s\n", ten_deskew_strings[deskew_ctrl]);
  CS_PRINT("    sysclk=%d\n",  sysclk);

  /* duplicate call -- already done during HSIF provisioning */
  /*  rtn |= ten_set_vco_coarse_tuning (dev_id, ((line_port & 1) * 4) + 1); */
  /* rtn |= ten_set_vco_coarse_tuning (dev_id, ((client_port & 1) * 4) + 1); */

  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  /*cs_status ten_hsif_clk_40g(module_id, tx_aggr_mode, txsel, rx_aggr_mode, rxsel) */
  rtn |= ten_hsif_clk_40g (module_id_line,   1, 0, 1, 0);
  rtn |= ten_hsif_clk_40g (module_id_client, 1, 0, 1, 0);

  /* Do not know if this is being done correctly in ten_hl_xcon_cfg(cs_uint16 dev_id, cs_uint8 slice, cs_uint8 mode) */
  for (i=0; i<8; i++) {
    rtn |= ten_xcon_select_es_packet_centering (dev_id, i, XCON_PKT_CENTERING_ALL, CS_DISABLE);
    rtn |= ten_xcon_set_circuit_thresholds (dev_id, i, XCON_ES_IML_THRESH, 0x1000);
  }

  /* Bugzilla #29143, fix warm start mode with 40G transponder */
  if (!ten_dev_is_ws_in_progress(dev_id)) {
    /* Enable the N10G and configure it for bypass */
    rtn |= ten_hl_n10g_config (module_id_line, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);
    rtn |= ten_hl_n10g_config (module_id_client, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);

    /* Disable all N10G OTN wrapping */
    rtn |= ten_n10g_set_otnt_wrpcfg3(module_id_line, TEN_SLICE_ALL, 0, 0, 0, 0, 0); /* stm64md, fpsynce, c15res_en, g43md, wrmd) */
    /* Disable all N10G OTN wrapping */
    rtn |= ten_n10g_otnt_set_wrmd(module_id_client, TEN_SLICE_ALL, 0);  /* WRMD=0 */

    /* N10G block sould be bypassed */
    rtn |= ten_n10g_set_pktie (module_id_line, TEN_SLICE_ALL, 1);    /* Tx is receiving packets */
    rtn |= ten_n10g_set_pktie (module_id_client, TEN_SLICE_ALL, 1);
  }
  
  /* Enable PP40G data interface (This should be done inside of the T41 hl n10g config */
  for (i=0; i<4; i++) {
    rtn |= ten_n10g_tx_pp40g_enable_t41 (module_id_line, i);   /* PP40G_EN = 1 */
    rtn |= ten_n10g_tx_pp40g_enable_t41 (module_id_client, i); /* PP40G_EN = 1 */

    rtn |= ten_n10g_rx_bypass_external_t41 (module_id_line, i );  /* RX_BYPASS10G=1, RX_BYPASS40G=0 */
    rtn |= ten_n10g_rx_bypass_external_t41 (module_id_client, i );  /* RX_BYPASS10G=1, RX_BYPASS40G=0 */

    rtn |= ten_n10g_tx_circuit_bypass_t41 (module_id_line, i);  /* PKTIE=0, TX_BYPASS=1, CLKTX_DIS=1 */
    rtn |= ten_n10g_tx_circuit_bypass_t41 (module_id_client, i);  /* PKTIE=0, TX_BYPASS=1, CLKTX_DIS=1 */
  }

  /* Enable clock */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_ENABLE);
  /* Bugzilla #27275, byp not needed */
  /* rtn |= ten_mpif_global_clock_disable_pp40g_byp_t41(dev_id, TEN_MODULE_A_AND_B, CS_ENABLE); */
  rtn |= ten_mpif_global_clock_disable_pp40g_sys_t41(dev_id, TEN_MODULE_A_AND_B, CS_ENABLE);
  rtn |= ten_mpif_global_clock_disable_pp40g_rx_t41(dev_id, TEN_MODULE_A_AND_B, CS_ENABLE);

  /* Remove hard reset from the top */
  rtn |= ten_mpif_global_reset_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_RESET_DEASSERT);
  rtn |= ten_mpif_global_reset_pp40g_sys_t41(dev_id, TEN_MODULE_A_AND_B, CS_RESET_DEASSERT);
  rtn |= ten_mpif_global_reset_pp40g_t41(dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  rtn |= ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + ((module_id_line & 1) * TEN_N40G_STRIDE), 0);
  rtn |= ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + ((module_id_client & 1) * TEN_N40G_STRIDE), 0);

  /*if ((map_line == TEN_MAP_GMP_HO)) {*/
  if ((map_line == TEN_MAP_GMP_HO) || (map_line == TEN_MAP_GMP_LO)) {
    timeslots = 32;
  } else {
    timeslots = 16;
  }
  
  
  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id_line,
                                       xcon_client_type,
                                       traffic_type_line,
                                       fec_line,
                                       map_line,
                                       timeslots,
                                       0xFF,
                                       TEN_OTU_TERM_TRANSPARENT,
                                       tcm_line,
                                       mld_line,
                                       TEN_KPG_DISABLED);
  
  
  /*if ((map_client == TEN_MAP_GMP_HO)) {*/
  if ((map_client == TEN_MAP_GMP_HO) || (map_client == TEN_MAP_GMP_LO)) {
    timeslots = 32;
  } else {
    timeslots = 16;
  }
  
  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id_client,
                                       xcon_client_type,
                                       traffic_type_client,
                                       fec_client,
                                       map_client,
                                       timeslots,
                                       0xFF,
                                       TEN_OTU_TERM_TRANSPARENT,
                                       tcm_client,
                                       mld_client,
                                       TEN_KPG_DISABLED);
  
  /* Configure PP40G */
  rtn |= ten_hl_pp40g_config_t41(module_id_line, pre_line_rx, pre_line_tx, deskew_ctrl, sysclk);
  rtn |= ten_hl_pp40g_config_t41(module_id_client, pre_client_rx, pre_client_tx, deskew_ctrl, sysclk);
  



  /* Provision Data Cross connect for straight accross for 40G Monolithic */
 #if 0
  rtn |= ten_hl_xcon_config (dev_id, 0, 4, TEN_TRAFFIC_TYPE_OTU2);  TEN_TRAFFIC_TYPE_SERIAL_40GE
  rtn |= ten_hl_xcon_config (dev_id, 1, 5, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 2, 6, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 3, 7, TEN_TRAFFIC_TYPE_OTU2);

  rtn |= ten_hl_xcon_config (dev_id, 4, 0, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 5, 1, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 6, 2, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 7, 3, TEN_TRAFFIC_TYPE_OTU2);
 #endif
  rtn |= ten_hl_xcon_config (dev_id, 0, 4, TEN_TRAFFIC_TYPE_SERIAL_40GE);  
  rtn |= ten_hl_xcon_config (dev_id, 1, 5, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config (dev_id, 2, 6, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config (dev_id, 3, 7, TEN_TRAFFIC_TYPE_SERIAL_40GE);

  rtn |= ten_hl_xcon_config (dev_id, 4, 0, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config (dev_id, 5, 1, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config (dev_id, 6, 2, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config (dev_id, 7, 3, TEN_TRAFFIC_TYPE_SERIAL_40GE);
#if 0
  rtn |= ten_hl_xcon_config_t41 (dev_id, 0, 4, interface, mfp_mode, gfp_mode, pkt_mode, fp_align, recenter_type);
#endif

 #if 0
  ncols_line = 254;  /* Standard OTU frame with 7% FEC */
  npar_line = 16;    /* 7% FEC */
      stm256md  = 1;
      stm64md = 0;

  rtn |= ten_hl_sadeco_config (dev_id, traffic_type_line, traffic_type_client, term_otu, ncols_line + 1 - npar_line, ncols_client - (2*stm256md) - npar_client, module_line);
 #endif

  if (deskew_ctrl == TEN_SADECO_DESKEW) {   /* Bugzilla 28977 */
    /* Configure the SADECO delay and compensation for Sonet SDH interleaving */
    /*rtn |= ten_xcon_sadeco_config (dev_id, module_id_client, 0x200, 0x1F00, XCON_SONET_SDH_64);*/
    /*rtn |= ten_xcon_sadeco_config (dev_id, module_id_line  , 0x200, 0x1F00, XCON_SONET_SDH_64);*/
    rtn |= ten_xcon_sadeco_config (dev_id, module_id_client, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
    rtn |= ten_xcon_sadeco_config (dev_id, module_id_line  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

    /* Provision Skew and Delay Compensation Frame Length. */
    rtn |= ten_xcon_sadeco_sdclen(dev_id, module_id_client, 0x3B0);   /* [255 columns - 16(FEC) - 1(OH) - 2(FS)]  * 4 */
    rtn |= ten_xcon_sadeco_sdclen(dev_id, module_id_line,   0x3BC);   /* [255 columns - 16(FEC)] * 4 */      

    /* Select incoming reference and tributary streams */
    rtn |= ten_xcon_sadeco_sel_data_stream (dev_id, module_id_client, 0x0F, 0x1F);
    rtn |= ten_xcon_sadeco_sel_data_stream (dev_id, module_id_line  , 0x0F, 0x1F);
    
    /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
    rtn |= ten_xcon_sadeco_enable_fp (dev_id, module_id_client, CS_ENABLE);
    rtn |= ten_xcon_sadeco_enable_fp (dev_id, module_id_line  , CS_ENABLE);
  }

  rtn |= ten_hl_config_fec_t41 (module_id_line, 0, TEN_SLICE_40G, fec_line);
  rtn |= ten_hl_config_fec_t41 (module_id_client, 0, TEN_SLICE_40G, fec_client);

  #if 0 /* Bugzilla #31390, this is done in ten_hl_config_trans_t41 */
  rtn |= ten_hl_n40g_config_lom_from_traffic (module_id_line, traffic_type_line, fec_line);
  rtn |= ten_hl_n40g_config_lom_from_traffic (module_id_client, traffic_type_client, fec_client);
  
  /* Bugzilla #31390, set obfa2 lom */
  rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id_line, traffic_type_line, fec_line);
  rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id_client, traffic_type_client, fec_client);
  #endif
  
  rtn |= ten_hl_n40g_otn_aligner_settings (module_id_line);
  rtn |= ten_hl_n40g_otn_aligner_settings (module_id_client);

  rtn |= ten_n40g_sdfr_lofcfg2_m0byte(module_id_line, 1);
  rtn |= ten_n40g_sdfr_lofcfg2_m0byte(module_id_client, 1);

  if (rtn != CS_OK) {
    CS_PRINT("%s() FAILED!\n", func);
  }

  return (rtn);
}
/* Bugzilla 28006 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU3V TO 4xCLIENT TO OTU3V */
/*                 40G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3v_odtu_otu3v_t41(cs_uint16 module_id_line,
                                             cs_uint16 traffic_type_line,
                                             cs_uint16 fec_line,
                                             cs_uint16 traffic_type_client,
                                             cs_uint16 fec_client,
                                             cs_uint16 xcon_client_type,
                                             cs_uint16 term_otu,
                                             cs_uint16 tcm_line,
                                             cs_uint16 tcm_client,
                                             cs_uint16 mld_line,
                                             cs_uint16 mld_client,
                                             cs_uint16 map_line,
                                             cs_uint16 map_client)
/* INPUTS     : o Line Module Id                                */
/*              o Traffic Type Line                             */
/*              o FEC Type Line                                 */
/*              o Traffic Type Client                           */
/*              o FEC Type Client                               */
/*              o ODU Signal Type                               */
/*              o Term OTU                                      */
/*              o TCM Line                                      */
/*              o TCM Client                                    */
/*              o MLD Line                                      */
/*              o MLD Client                                    */
/*              o Mapping Method for Line                       */
/*              o Mapping Method for Client                     */

/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Demaps OTU3V on the client side and remaps the 4x10G clients */
/* onto OTU3V on line side                                      */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [traffic_type_line] and [traffic_type_client] parameters     */
/* specify the traffic type of the line and client              */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*                                                              */
/* [fec_line] and [fec_client] parameters define the line and   */
/* client fec type:                                             */
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
/* [xcon_client_type] parameter defines the ODU signal type     */
/*   TEN_TRAFFIC_TYPE_OTU1E   = 0                               */
/*   TEN_TRAFFIC_TYPE_OTU1F   = 1                               */
/*   TEN_TRAFFIC_TYPE_OTU2    = 2                               */
/*   TEN_TRAFFIC_TYPE_OTU2E   = 3                               */
/*                                                              */
/* [term_otu] parameter defines the way the OTU2 will be        */
/* sinked and sourced                                           */
/*   TEN_OTU_TERM_TRANSPARENT = 0                               */
/*   TEN_OTU_TERM_SECTION     = 1                               */
/*                                                              */
/* The [tcm_line] and [tcm_client] parameters specify the       */
/* termination for TCM 1 through 6 for the line and client.     */
/* This is a bit encoded parameter with bits 1 through 6        */
/* specifying TCM 1 through 6 respectively.                     */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [mld_line] and [mld_client] parameters enable distribut- */
/* ing data across multiple lanes on line or client side        */
/* i.e. OTL3.4                                                  */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_line] parameter specifies the line mapping method   */
/*   TEN_MAP_AMP           = 0                                  */
/*   TEN_MAP_AMP_PROP      = 3                                  */
/*   TEN_MAP_GMP_HO        = 6                                  */
/*                                                              */
/* The [map_client] parameter specifies the client mapping      */ 
/* method                                                       */
/*   TEN_MAP_AMP           = 0                                  */
/*   TEN_MAP_AMP_PROP      = 3                                  */
/*   TEN_MAP_GMP_HO        = 6                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  T41_t *pDev = NULL;
  ten_dev_cb_t *pdevcb;         /* Bugzilla 26784 */
  cs_uint16 module_id_client;
  cs_uint16 slice;
  cs_uint16 timeslots_line;   /* Bugzilla 29100 */
  cs_uint16 timeslots_client; /* Bugzilla 29100 */

  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_otu3v_odtu_otu3v_t41";  


  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  module_id_client = module_id_line ^ TEN_MODULE_B;

  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P2) && (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E2)) {  /* Bugzilla 29100 */
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.  s/b 1, 2, 3, 23, 25, 35.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
    return (CS_ERROR);
  }

  if ((traffic_type_client != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3P2) && (traffic_type_client != TEN_TRAFFIC_TYPE_OTU3E2)) {  /* Bugzilla 29100 */
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_client %d out of range.  s/b 1, 2, 3, 23, 25, 35.", func, traffic_type_client);
    return (CS_ERROR);
  }

  if (fec_client >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_client %d out of range.  s/b 0..15.", func, fec_client);
    return (CS_ERROR);
  }

  if ((xcon_client_type != TEN_TRAFFIC_TYPE_OTU1F) && (xcon_client_type != TEN_TRAFFIC_TYPE_OTU2) && 
      (xcon_client_type != TEN_TRAFFIC_TYPE_OTU2E) && (xcon_client_type != TEN_TRAFFIC_TYPE_OTU1E)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() xcon_client_type %d out of range.  s/b 0..3.", func, xcon_client_type);
    return (CS_ERROR);
  }

  if (term_otu > TEN_OTU_TERM_SECTION) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_otu %d out of range.  s/b 0..1.", func, term_otu);
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

  if (mld_client > 1) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() mld_client %d out of range.  s/b 0..1.", func, mld_client);
    return (CS_ERROR);
  }

  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);    /* Bugzilla 26784 */

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line (%s, %s, %s)\n", ten_module_strings[module_id_line&1], ten_hl_config_traffic_types_strings[traffic_type_line], ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("    client (%s, %s)\n", ten_hl_config_traffic_types_strings[traffic_type_client], ten_fec_ovhd_strings[fec_client]);
  CS_PRINT("    xcon_client_type %s\n", ten_hl_config_traffic_types_strings[xcon_client_type]);
  CS_PRINT("    %s\n", ten_hl_config_otu_overhead_term_strings[term_otu]);
  CS_PRINT("    tcm_line = 0x%X, mld_line = %d\n", tcm_line, mld_line);
  CS_PRINT("    tcm_client = 0x%X, mld_client = %d\n", tcm_client, mld_client);
  if (map_line <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_line=%s\n", ten_sync_type_strings[map_line]);
  } else {
    CS_PRINT("    map_line=%d\n", map_line);
  }
  if (map_client <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_client=%s\n", ten_sync_type_strings[map_client]);
  } else {
    CS_PRINT("    map_client=%d\n", map_client);
  }

  /* Bugzilla 29100 Start */
  if ((map_line == TEN_MAP_GMP_HO) || (map_line == TEN_MAP_GMP_LO)) {
    timeslots_line = 8;
  }
  else {
    timeslots_line = 4;
  }
  /* Bugzilla 29100 Start */

  /* Bugzilla 29100   if condition removed */
  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_mux_t41 (module_id_line,      
                                     xcon_client_type,
                                     traffic_type_line,
                                     fec_line,
                                     0,     
                                     0,            
                                     map_line,
                                     timeslots_line,             
                                     255,     
                                     term_otu,            
                                     tcm_line,              
                                     mld_line); 

  /* Bugzilla 29100 Start */
  if ((map_client == TEN_MAP_GMP_HO) || (map_client == TEN_MAP_GMP_LO)) {
    timeslots_client = 8;
  }
  else {
    timeslots_client = 4;
  }
  /* Bugzilla 29100 Start */

  /* Configure Client side N40g block */
  rtn |= ten_hl_n40g_config_mux_t41 (module_id_client,      
                                     xcon_client_type,
                                     traffic_type_client,
                                     fec_client,
                                     0,     
                                     0,            
                                     map_client, /* Bugzilla 26565, fix incorrect parameter here to fix cust config */
                                     timeslots_client,             
                                     255,     
                                     term_otu,            
                                     tcm_client,              
                                     mld_client); 




  for(slice=0;slice<4;slice++) {
    rtn |= ten_hl_n10g_config_t41 (module_id_line, 
                                   slice,
                                   0,
                                   xcon_client_type,
                                   TEN_TRAFFIC_TYPE_ODTU,
                                   TEN_FEC_MODE_NOFEC,
                                   TEN_MAP_BMP,                  /* Bugzilla 26784 */
                                   map_line,                     /* Bugzilla 29100 */
                                   8,
                                   255,
                                   TEN_OTU_TERM_TRANSPARENT,
                                   tcm_line);

    rtn |= ten_hl_n10g_config_t41 (module_id_client, 
                                   slice,
                                   0,
                                   xcon_client_type,
                                   TEN_TRAFFIC_TYPE_ODTU,
                                   TEN_FEC_MODE_NOFEC,
                                   TEN_MAP_BMP,                  /* Bugzilla 26784 */
                                   map_client,                   /* Bugzilla 29100 */
                                   8,
                                   255,
                                   TEN_OTU_TERM_TRANSPARENT,
                                   tcm_client);
    /* Bugzilla 29100 code removed */
  }

  for(slice=0;slice<4;slice++) {
    rtn |= ten_hl_xcon_config(dev_id, (module_id_line*4)+slice, (module_id_client*4)+slice, TEN_TRAFFIC_TYPE_OTU2);
    rtn |= ten_hl_xcon_config(dev_id, (module_id_client*4)+slice,(module_id_line*4)+slice, TEN_TRAFFIC_TYPE_OTU2);
  }

  /* Bugzilla 29100 Start */
  for(slice=0;slice<4;slice++) {
    /* Provision all the mapping related registers */
    rtn |= ten_n40g_mux_mapper_t41 (module_id_line, xcon_client_type, slice, traffic_type_line, map_line, timeslots_line, 255, pdevcb->syncdsync_thread_cb[0].num_just_oxu3);

    /* Provision all the mapping related registers */
    rtn |= ten_n40g_mux_mapper_t41 (module_id_client, xcon_client_type, slice, traffic_type_client, map_client, timeslots_client, 255, pdevcb->syncdsync_thread_cb[0].num_just_oxu2);
  }
  /* Bugzilla 29100 End */

  rtn |= ten_hl_config_fec_t41 (module_id_line, 0, TEN_SLICE_40G, fec_line);
  rtn |= ten_hl_config_fec_t41 (module_id_client, 0, TEN_SLICE_40G, fec_client);

  return (rtn);
}

/* Bugzilla 26200 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 40GE TO OTU3V              */
/*                 40G TRANSPONDER                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_40ge_otu3v_t41(cs_uint16 module_id_line,
                                       cs_uint16 dyn_repro,
                                       cs_uint16 traffic_type_line,
                                       cs_uint16 traffic_type_client,
                                       cs_uint16 pp40g_tx_line_mode,
                                       cs_uint16 pp40g_rx_line_mode,
                                       cs_uint16 pp40g_tx_client_mode,
                                       cs_uint16 pp40g_rx_client_mode,
                                       cs_uint16 fec_line,
                                       cs_uint16 tcm_line,
                                       cs_uint16 mld_line,
                                       cs_uint16 mld_client,
                                       cs_uint16 map_oxuv,
                                       cs_uint16 timeslots,
                                       cs_uint16 deskew_ctrl,
                                       cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type Line                             */
/*              o Traffic Type Client                           */
/*              o FEC Type Line                                 */
/*              o TCM Line                                      */
/*              o TCM Client                                    */
/*              o MLD Line                                      */
/*              o MLD Client                                    */
/*              o Mapping Method                                */
/*              o Timeslots                                     */
/*              o Deskew at PP40G                               */
/*              o System Clock                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures 40G ethernet on the client side into OTU3V on     */
/* line side                                                    */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 - dev_id, Bits 7:1 - don’t care, Bit 0 - module  */
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
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 34                               */
/*                                                              */
/* [[traffic_type_client] parameter specifies the traffic type  */
/* of the client:                                               */
/*   TEN_TRAFFIC_TYPE_SERIAL_40GE   = 41                        */
/*   TEN_TRAFFIC_TYPE_PARALLEL_40GE = 42                        */
/*   TEN_TRAFFIC_TYPE_TC_40GE       = 43                        */
/*   TEN_TRAFFIC_TYPE_S64_66_40GE   = 44                        */
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
/* The [mld_client] parameter enables distributing data across  */
/* multiple lanes on client side (Serial 40GE)                  */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [map_oxuv] parameter specifies the client mapping method */
/*   TEN_MAP_BMP        = 1                                     */
/*   TEN_MAP_AMP_PROP   = 3                                     */
/*   TEN_MAP_GMP_LO     = 5                                     */
/*   TEN_MAP_GMP_HO     = 6                                     */
/*                                                              */
/* The [timeslots] parameter specifies number of timeslots.     */
/* Bandwidth is always 1.25G per timeslot for GMP_HO. Whereas   */
/* for AMP it is as follows:                                    */
/* 16 timeslots  - 2.5G per timeslot                            */
/* 32 timeslots  - 1.25G per timeslot                           */
/*                                                              */
/* The [deskew_ctrl] parameter is specified as:                 */
/*   TEN_SADECO_DESKEW       = 0	                            */
/*   TEN_PP40G_BYPASS_DESKEW = 1                                */
/*   TEN_PP40G_DESKEW        = 2                                */
/*                                                              */
/* [sysclk] parameter specifies the sysclk frequency in MHz.    */
/*   For example, 400.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_uint16 module_id_client = 0;
  cs_uint16 i;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_40ge_otu3v_t41";  

  module_id_client = ((TEN_MOD_ID_TO_MOD_NUM(module_id_line))^TEN_MODULE_B) | (dev_id << 8);
  
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);

  /* Parameter checking */
  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if ((traffic_type_line != TEN_TRAFFIC_TYPE_OTU3) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type_line != TEN_TRAFFIC_TYPE_OTU3E2)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type_line %d out of range.", func, traffic_type_line);
    return (CS_ERROR);
  }

  if (fec_line >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() fec_line %d out of range.  s/b 0..15.", func, fec_line);
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

  if (mld_client > 1) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() mld_client %d out of range.  s/b 0..1.", func, mld_client);
    return (CS_ERROR);
  }

  if ((map_oxuv != TEN_MAP_BMP) &&
      (map_oxuv != TEN_MAP_AMP) &&
      (map_oxuv != TEN_MAP_GMP_LO) &&
      (map_oxuv != TEN_MAP_GMP_HO) &&
      (map_oxuv != TEN_MAP_GMP_HO_DT) &&
      (map_oxuv != TEN_MAP_AMP_PROP)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() map_oxuv %d out of range.", func, map_oxuv);
    return (CS_ERROR);
  }

  /* Bugzilla 27391 Start */
  if ((map_oxuv == TEN_MAP_GMP_HO) || (map_oxuv == TEN_MAP_GMP_HO_DT) || (map_oxuv == TEN_MAP_GMP_LO)) {
    if (timeslots != 32) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 32.", func, timeslots);
      return (CS_ERROR);
    }
  }
  else if ((map_oxuv == TEN_MAP_AMP) || (map_oxuv == TEN_MAP_AMP_DT)) {
    if ((timeslots != 16) && (timeslots != 32)) {
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 16 or 32.", func, timeslots);
      return (CS_ERROR);
    }
  } else {
    if (timeslots != 16){
      CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 16.", func, timeslots);
      return (CS_ERROR);
    }
  }  
  /* Bugzilla 27391 Start */
  if (deskew_ctrl > TEN_PP40G_DESKEW) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() deskew_ctrl %d out of range.  s/b 0, 1, 2.", func, deskew_ctrl);
    return (CS_ERROR);
  }
     
  CS_PRINT("%s()\n", func);
  CS_PRINT("    %s,\n", ten_module_strings[module_id_line&1]);
  CS_PRINT("    %s\n",  ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    line=%s\n", ten_hl_config_traffic_types_strings[traffic_type_line]);
  CS_PRINT("    client=%s\n", ten_hl_config_traffic_types_strings[traffic_type_client]);
  CS_PRINT("    pp40g_tx_line=%s\n", ten_pp40g_tx_parm_strings[pp40g_tx_line_mode]);
  CS_PRINT("    pp40g_rx_line=%s\n", ten_pp40g_rx_parm_strings[pp40g_rx_line_mode]);
  CS_PRINT("    pp40g_tx_client=%s\n", ten_pp40g_tx_parm_strings[pp40g_tx_client_mode]);
  CS_PRINT("    pp40g_rx_client=%s\n", ten_pp40g_rx_parm_strings[pp40g_rx_client_mode]);
  CS_PRINT("    %s\n", ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("    tcm_line=0x%X\n", tcm_line);
  CS_PRINT("    mld_line=%d\n", mld_line);
  CS_PRINT("    mld_client=%d\n", mld_client);
  if (map_oxuv <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_oxuv=%s\n", ten_sync_type_strings[map_oxuv]);
  }
  else {
    CS_PRINT("    map_oxuv=%d\n", map_oxuv);
  }
  CS_PRINT("    timeslots=0x%X\n", timeslots);
  CS_PRINT("    %s\n", ten_deskew_strings[deskew_ctrl]);
  CS_PRINT("    sysclk=%d\n", sysclk);

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, ((line_port & 1) * 4) + 1);  */ /* Bugzilla #24261 */
  /* ten_set_vco_coarse_tuning (dev_id, ((client_port & 1) * 4) + 1); */ /* Bugzilla #24261 */

  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  /*cs_status ten_hsif_clk_40g(module_id, tx_aggr_mode, txsel, rx_aggr_mode, rxsel) */
  ten_hsif_clk_40g (module_id_line,   1, 0, 1, 0);
  ten_hsif_clk_40g (module_id_client, 1, 0, 1, 0);

  /* Do not know if this is being done correctly in ten_hl_xcon_cfg(cs_uint16 dev_id, cs_uint8 slice, cs_uint8 mode) */
  for (i=0; i<8; i++) {
    ten_xcon_select_es_packet_centering (dev_id, i, XCON_PKT_CENTERING_ALL, CS_DISABLE);
    ten_xcon_set_circuit_thresholds (dev_id, i, XCON_ES_IML_THRESH, 0x1000);
  }

  /* Bugzilla #29143, fix warm start mode with 40G transponder */
  if (!ten_dev_is_ws_in_progress(dev_id)) {
    /* Enable the N10G and configure it for bypass */
    rtn |= ten_hl_n10g_config (module_id_line, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);
    rtn |= ten_hl_n10g_config (module_id_client, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);

    /* disable all N10G OTN wrapping */
    rtn |= ten_n10g_set_otnt_wrpcfg3(module_id_line, TEN_SLICE_ALL, 0, 0, 0, 0, 0); /* stm64md, fpsynce, c15res_en, g43md, wrmd) */
    /* Disable all N10G OTN wrapping */
    rtn |= ten_n10g_otnt_set_wrmd(module_id_client, TEN_SLICE_ALL, 0);  /* WRMD=0 */

    /* N10G block sould be bypassed */
    rtn |= ten_n10g_set_pktie (module_id_line, TEN_SLICE_ALL, 1);
    rtn |= ten_n10g_set_pktie (module_id_client, TEN_SLICE_ALL, 1);
  }

  /* Bugzilla 26194 Start */
  /* Enable PP40G data interface (This should be done inside of the T41 hl n10g config */
  for (i=0; i<4; i++) {
    rtn |= ten_n10g_tx_pp40g_enable_t41 (module_id_line, i);   /* PP40G_EN = 1 */
    rtn |= ten_n10g_tx_pp40g_enable_t41 (module_id_client, i); /* PP40G_EN = 1 */

    rtn |= ten_n10g_rx_bypass_external_t41 (module_id_line, i );  /* RX_BYPASS10G=1, RX_BYPASS40G=0 */
    rtn |= ten_n10g_rx_bypass_external_t41 (module_id_client, i );  /* RX_BYPASS10G=1, RX_BYPASS40G=0 */

    rtn |= ten_n10g_tx_circuit_bypass_t41 (module_id_line, i);  /* PKTIE=0, TX_BYPASS=1, CLKTX_DIS=1 */
    rtn |= ten_n10g_tx_circuit_bypass_t41 (module_id_client, i);  /* PKTIE=0, TX_BYPASS=1, CLKTX_DIS=1 */

/*CS_PRINT("%s(), 1c\n", func);*/
/*ten_n10g_set_otnt_wrpcfg3(module_id_line, TEN_SLICE_ALL, 0, 0, 0, 0, 0);*/
  }
  /* Bugzilla 26194 Start */

  /* Enable clock */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_ENABLE);
  /* Bugzilla #27275, byp not needed */
  /* rtn |= ten_mpif_global_clock_disable_pp40g_byp_t41(dev_id, TEN_MODULE_A_AND_B, CS_ENABLE); */
  rtn |= ten_mpif_global_clock_disable_pp40g_sys_t41(dev_id, TEN_MODULE_A_AND_B, CS_ENABLE);
  rtn |= ten_mpif_global_clock_disable_pp40g_rx_t41(dev_id, TEN_MODULE_A_AND_B, CS_ENABLE);

 /* Remove hard reset from the top */
  rtn |= ten_mpif_global_reset_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_RESET_DEASSERT);
  rtn |= ten_mpif_global_reset_pp40g_sys_t41(dev_id, TEN_MODULE_A_AND_B, CS_RESET_DEASSERT);
  rtn |= ten_mpif_global_reset_pp40g_t41(dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  rtn |= ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + ((module_id_line & 1) * TEN_N40G_STRIDE), 0);
  rtn |= ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + ((module_id_client & 1) * TEN_N40G_STRIDE), 0);

  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41(module_id_line,
                                      traffic_type_client,
                                      traffic_type_line,
                                      fec_line,
                                      map_oxuv,
                                      timeslots,
                                      0xFF,
                                      TEN_OTU_TERM_FULL,  /* Bugzilla 29830 */
                                      tcm_line,
                                      mld_line,
                                      TEN_KPG_DISABLED);

  /* Configure Client side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41(module_id_client,
                                      traffic_type_client,
                                      traffic_type_client,
                                      fec_line,
                                      TEN_MAP_BMP,
                                      timeslots,
                                      0xFF,
                                      TEN_OTU_TERM_TRANSPARENT,
                                      0,
                                      mld_client,
                                      TEN_KPG_DISABLED);


  /* Bugzilla 27127 Start */
  /* Configure PP40G */
  rtn |= ten_hl_pp40g_config_t41(module_id_line, pp40g_rx_line_mode, pp40g_tx_line_mode, deskew_ctrl, sysclk);
  rtn |= ten_hl_pp40g_config_t41(module_id_client, pp40g_rx_client_mode, pp40g_tx_client_mode, deskew_ctrl, sysclk);
  /* Bugzilla 27127 End */

  /* Provision Data Cross connect for straight accross for 40G Monolithic */
 #if 0 
  //rtn |= ten_hl_xcon_config(dev_id, 0, 4, TEN_TRAFFIC_TYPE_OTU2);
  //rtn |= ten_hl_xcon_config(dev_id, 1, 5, TEN_TRAFFIC_TYPE_OTU2);
  //rtn |= ten_hl_xcon_config(dev_id, 2, 6, TEN_TRAFFIC_TYPE_OTU2);
  //rtn |= ten_hl_xcon_config(dev_id, 3, 7, TEN_TRAFFIC_TYPE_OTU2);
  //
  //rtn |= ten_hl_xcon_config(dev_id, 4, 0, TEN_TRAFFIC_TYPE_OTU2);
  //rtn |= ten_hl_xcon_config(dev_id, 5, 1, TEN_TRAFFIC_TYPE_OTU2);
  //rtn |= ten_hl_xcon_config(dev_id, 6, 2, TEN_TRAFFIC_TYPE_OTU2);
  //rtn |= ten_hl_xcon_config(dev_id, 7, 3, TEN_TRAFFIC_TYPE_OTU2);
 #endif
  rtn |= ten_hl_xcon_config(dev_id, 0, 4, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config(dev_id, 1, 5, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config(dev_id, 2, 6, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config(dev_id, 3, 7, TEN_TRAFFIC_TYPE_SERIAL_40GE);

  rtn |= ten_hl_xcon_config(dev_id, 4, 0, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config(dev_id, 5, 1, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config(dev_id, 6, 2, TEN_TRAFFIC_TYPE_SERIAL_40GE);
  rtn |= ten_hl_xcon_config(dev_id, 7, 3, TEN_TRAFFIC_TYPE_SERIAL_40GE);



  if (deskew_ctrl == TEN_SADECO_DESKEW) {   /* Bugzilla 28977 */
    /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
    ten_xcon_sadeco_config (dev_id, module_id_client, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
    ten_xcon_sadeco_config (dev_id, module_id_line  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

    /* Provision Skew and Delay Compensation Frame Length. */
    ten_xcon_sadeco_sdclen(dev_id, module_id_client, 0x3B0);   /* [255 columns - 16(FEC) - 1(OH) - 2(FS)]  * 4 */
    ten_xcon_sadeco_sdclen(dev_id, module_id_line,   0x3BC);   /* [255 columns - 16(FEC)] * 4 */      
  
    /* Select incoming reference and tributary streams */
    ten_xcon_sadeco_sel_data_stream(dev_id, module_id_client, 0x0F, 0x1F);
    ten_xcon_sadeco_sel_data_stream(dev_id, module_id_line  , 0x0F, 0x1F);
    
    /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
    ten_xcon_sadeco_enable_fp(dev_id, module_id_client, CS_ENABLE);
    ten_xcon_sadeco_enable_fp(dev_id, module_id_line  , CS_ENABLE);
  }

  /* Provision FEC */
  rtn |= ten_hl_config_fec_t41(module_id_line, 0, TEN_SLICE_40G, fec_line);  /* Bugzilla 29929 */

  #if 0 /* Bugzilla #31390, this is done in ten_hl_config_trans_t41 */
  /* Bugzilla 24956 Start */ 
  rtn |= ten_hl_n40g_config_lom_from_traffic(module_id_line, traffic_type_line, fec_line);
  /* Bugzilla 24956 End */

  /* Bugzilla #31390, set obfa2 lom */
  rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id_line, traffic_type_line, fec_line);
  #endif
  
  /* Bugzilla 24750 Start */
  ten_hl_n40g_otn_aligner_settings(module_id_line);
  /* Bugzilla 24750 End */

  /* Bugzilla 13005 Start  M0BYTE description inverted in T40 DS */
  ten_n40g_sdfr_lofcfg2_m0byte(module_id_line, 1);
  /* Bugzilla 13005 End */
  
  /* Bugzilla 29647 Start */
  if (traffic_type_client == TEN_TRAFFIC_TYPE_PARALLEL_40GE) {
    /* Provision the 40G RX block for bypass.   Provision the 40G TX block enabled*/
    rtn |= ten_mpif_global_cfg_per_module (dev_id, module_id_client & 1, 0, 1); 

    /* Provision RX datapaths source to be 4 independent 10G clocks.  Provision TX datapaths source to be 1 single 40G clock */
    
    /* Bugzilla #33065, RXB and TXB clock needs to be 1 so the datapath uses single 40G clock. */
    rtn |= ten_mpif_clock_select_40g_per_module (dev_id, module_id_client & 1, 1, 1); 
  } else {
    /* Provision the 40G TX and RX blocks enabled */
    rtn |= ten_mpif_global_cfg_per_module (dev_id, module_id_client & 1, 0, 0); 

    /* Provision TX and RX datapaths source to be 1 single 40G clock */
    rtn |= ten_mpif_clock_select_40g_per_module (dev_id, module_id_client & 1, 1, 1);
  }
  /* Bugzilla 29647 End */
  
  CS_PRINT("ten_hl_config_40ge_otu3v_t41 complete, rtn=%s.\n", (rtn == CS_OK ? "CS_OK" : "CS_ERROR"));
  if (rtn != CS_OK) {
    CS_PRINT("%s() FAILED!\n", func);
  }

  return (rtn);
}
/* Bugzilla 26200 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC768 KPGA                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc768_kpga_t41(cs_uint16 module_id,
                                        cs_uint16 pattern,
                                        cs_uint16 mld,
                                        cs_uint16 data_in_stuff_bytes)
/* INPUTS     : o Line Module Id                                */
/*              o Pattern                                       */
/*              o MLD                                           */
/*              o Data In Stuff Bytes                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an OC768 KPGA tester                               */
/* The tester will see B3 errors because of a problem with the  */
/* T40 chip                                                     */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   0x00 = TEN_KPG_FIXED_PATTERN                               */
/*   0x01 = TEN_KPG_PN11                                        */
/*   0x02 = TEN_KPG_PN23                                        */
/*   0x03 = TEN_KPG_PN31                                        */
/*                                                              */
/* The [mld] parameter enables distributing data across         */
/* multiple lanes on line side i.e. OTL3.4                      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* [data_in_stuff_bytes] specifies if the test patter will be   */
/*                       inserted in the stuff bytes            */
/*   0x00 = Do not place or retrieve data in the stuff bytes    */
/*   0x01 = Place and retrieve data in the stuff bytes          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 module;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_hl_config_oc768_kpga_t41";  
  cs_status rtn = CS_OK;

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  module = TEN_MOD_ID_TO_MOD_NUM (module_id);

  if (pattern > TEN_KPG_PN31) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }

  if (mld > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() mld %d out of range.  s/b 0..1.", func, mld);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, mld = %d, data_in_stuff_bytes = %d\n",
           func,
           ten_kpg_strings[pattern],
           mld,
           data_in_stuff_bytes);

  /* Bugzilla 26130 Start */
  /* Selects the datapath source to be the single 40G RX clock */
  rtn |= ten_mpif_clock_select_40g_per_module (dev_id, module_id & 1, 1, 1);
  /* Provision  the 40G block bypass */
  rtn |= ten_mpif_global_cfg_per_module (dev_id, module_id & 1, 0, 0); 
  /* Bugzilla 26130 End */

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, ((module_id & 1) * 4) + 1); */

  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  ten_hsif_clk_40g (module_id, 1, 0, 1, 0);  /* tx_aggr_mode, txsel, rx_aggr_mode, rxsel */

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_hl_n10g_config (module_id, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, TEN_INITIAL_CONFIG);

  /* Enable clock */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, module, CS_TX_AND_RX, CS_ENABLE);
  /* Remove hard reset from the top */
  rtn |= ten_mpif_global_reset_n40g (dev_id, module, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id,
                                       TEN_TRAFFIC_TYPE_OC768,
                                       TEN_TRAFFIC_TYPE_OC768,
                                       TEN_FEC_MODE_NOFEC,
                                       /*TEN_MAP_AMP,*/
                                       TEN_MAP_BMP,
                                       32,
                                       0xFF,
                                       TEN_OC192_TERM_MS_LAYER_REGENERATOR,
                                       0,
                                       mld,
                                       pattern);


  /* Provision N10G part for Sonet */
  /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
  rtn |= ten_n10g_set_gblt_cfgtx0 (module_id, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0); /* PPLF_EN, CBRSTMAISINS, PN11AUTO, OTNOFF, OBY, SBY, KPGBY, PKTIE */

  /* Bugzilla  #38621 - For OC768 KPGA configuration, the N10G SCREN and A1A2IE should be disabled */
  rtn |= ten_n10g_soht_set_a1a2ie (module_id, TEN_SLICE_ALL, 0);  /* A1A2IE */
  rtn |= ten_n10g_sdfr_set_scren(module_id, TEN_SLICE_ALL, 0);
  rtn |= ten_n10g_soht_set_scren(module_id, TEN_SLICE_ALL, 0);
  
  /* POH insertion needs to be set POHIE */
  rtn |= ten_n10g_soht_pohben0 (module_id, TEN_SLICE_ALL, 1, 1);  /* PRBSIE, POHIE */

  /* disable all OTN wrapping */
  rtn |= ten_n10g_otnt_set_wrmd (module_id, TEN_SLICE_ALL, 0);  /* WRMD */

  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id, TEN_SLICE_ALL, 2, 0, 0, 0, 1, 0, 1); /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU3 KPGA                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3v_kpga_t41(cs_uint16 module_id,
                                        cs_uint16 traffic_type,
                                        cs_uint16 fec,
                                        cs_uint16 pattern,
                                        cs_uint16 mld,
                                        cs_uint16 data_in_stuff_bytes)
/* INPUTS     : o Line Module Id                                */
/*              o Traffic Type                                  */
/*              o FEC Type                                      */
/*              o Pattern                                       */
/*              o MLD                                           */
/*              o Data In Stuff Bytes                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an OC768 KPGA tester                               */
/* The tester will see B3 errors because of a problem with the  */
/* T40 chip                                                     */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type of  */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 35                               */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   0x00 = TEN_KPG_FIXED_PATTERN                               */
/*   0x01 = TEN_KPG_PN11                                        */
/*   0x02 = TEN_KPG_PN23                                        */
/*   0x03 = TEN_KPG_PN31                                        */
/*                                                              */
/* The [mld] parameter enables distributing data across         */
/* multiple lanes on line side i.e. OTL3.4                      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* [data_in_stuff_bytes] specifies if the test patter will be   */
/*                       inserted in the stuff bytes            */
/*   0x00 = Do not place or retrieve data in the stuff bytes    */
/*   0x01 = Place and retrieve data in the stuff bytes          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 module;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_hl_config_otu3v_kpga_t41";  
  cs_status rtn = CS_OK;

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  module = TEN_MOD_ID_TO_MOD_NUM (module_id);

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3P) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3P2) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E2) &&
      /* Bugzilla #31577, support OTU3E4 */
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E4) ) {   /* Bugzilla 28979 */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 1, 2, 3, 23, 25, 35, or 55.", func, traffic_type);
    return (CS_ERROR);
  }

  if (fec >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() fec %d out of range.  s/b 0..15.", func, fec);
    return (CS_ERROR);
  }

  if (pattern > TEN_KPG_PN31) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }

  if (mld > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() mld %d out of range.  s/b 0..1.", func, mld);
    return (CS_ERROR);
  }

  if (data_in_stuff_bytes > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() data_in_stuff_bytes %d out of range.  s/b 0..1.", func, data_in_stuff_bytes);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, %s, mld = %d, data_in_stuff_bytes = %d\n",
           func,
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_fec_ovhd_strings[fec],
           ten_kpg_strings[pattern],
           mld,
           data_in_stuff_bytes);
  
  /* Bugzilla 26130 Start */
  /* Selects the datapath source to be the single 40G RX clock */
  rtn |= ten_mpif_clock_select_40g_per_module (dev_id, module_id & 1, 1, 1);
  /* Provision  the 40G block bypass */
  rtn |= ten_mpif_global_cfg_per_module (dev_id, module_id & 1, 0, 0); 
  /* Bugzilla 26130 End */

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, port + 1);  */ /* Bugzilla #24261 */

  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  ten_hsif_clk_40g (module_id, 1, 0, 1, 0);

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_hl_n10g_config (module_id, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, TEN_INITIAL_CONFIG);

  /* Enable clock */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, module, CS_TX_AND_RX, CS_ENABLE);
  /* Remove hard reset from the top */
  rtn |= ten_mpif_global_reset_n40g (dev_id, module, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  rtn |= ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + (module * TEN_N40G_STRIDE), 0);

  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id,
                                       traffic_type,
                                       traffic_type,
                                       fec,
                                       /*TEN_MAP_AMP,*/
                                       TEN_MAP_BMP,
                                       16,           /* Bugzilla 27106 */
                                       0xFF,
                                       TEN_OTU_TERM_FULL,
                                       0,
                                       mld,
                                       pattern);

  rtn |= ten_hl_config_fec_t41 (module_id, 0, TEN_SLICE_40G, fec);

  /* Bugzilla 24750 Start */
  ten_hl_n40g_otn_aligner_settings (module_id);
  /* Bugzilla 24750 End */

  /* Bugzilla 13005 Start  M0BYTE description inverted in T40 DS */
  ten_n40g_sdfr_lofcfg2_m0byte(module_id, 1);
  /* Bugzilla 13005 End */

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC768 inside OTU3v KPGA    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc768_otu3v_kpga_t41(cs_uint16 module_id,
                                             cs_uint16 traffic_type,
                                             cs_uint16 fec,
                                             cs_uint16 pattern,
                                             cs_uint16 mld,
                                             cs_uint16 data_in_stuff_bytes)
/* INPUTS     : o Line Module Id                                */
/*              o Traffic Type                                  */
/*              o FEC Type                                      */
/*              o Pattern                                       */
/*              o MLD                                           */
/*              o Data In Stuff Bytes                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an OC768 KPGA tester                               */
/* The tester will see B3 errors because of a problem with the  */
/* T40 chip                                                     */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [traffic_type_line] parameter specifies the traffic type of  */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 34                               */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   0x00 = TEN_KPG_FIXED_PATTERN                               */
/*   0x01 = TEN_KPG_PN11                                        */
/*   0x02 = TEN_KPG_PN23                                        */
/*   0x03 = TEN_KPG_PN31                                        */
/*                                                              */
/* The [mld] parameter enables distributing data across         */
/* multiple lanes on line side i.e. OTL3.4                      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* [data_in_stuff_bytes] specifies if the test patter will be   */
/*                       inserted in the stuff bytes            */
/*   0x00 = Do not place or retrieve data in the stuff bytes    */
/*   0x01 = Place and retrieve data in the stuff bytes          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 module;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_hl_config_oc768_otu3v_kpga_t41";  
  cs_status rtn = CS_OK;

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  module = TEN_MOD_ID_TO_MOD_NUM (module_id);


  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E3)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 1, 2, 23.", func, traffic_type);
    return (CS_ERROR);
  }

  if (fec >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() fec %d out of range.  s/b 0..15.", func, fec);
    return (CS_ERROR);
  }


  if (pattern > TEN_KPG_PN31) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }

  if (mld > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() mld %d out of range.  s/b 0..1.", func, mld);
    return (CS_ERROR);
  }

  if (data_in_stuff_bytes > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() data_in_stuff_bytes %d out of range.  s/b 0..1.", func, data_in_stuff_bytes);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, %s, mld = %d, data_in_stuff_bytes = %d\n",
           func,
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_fec_ovhd_strings[fec],
           ten_kpg_strings[pattern],
           mld,
           data_in_stuff_bytes);

  /* Bugzilla 26130 Start */
  /* Selects the datapath source to be the single 40G RX clock */
  rtn |= ten_mpif_clock_select_40g_per_module (dev_id, module_id & 1, 1, 1);
  /* Provision  the 40G block bypass */
  rtn |= ten_mpif_global_cfg_per_module (dev_id, module_id & 1, 0, 0); 
  /* Bugzilla 26130 End */

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, ((module_id & 1) * 4) + 1); */

  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  ten_hsif_clk_40g (module_id, 1, 0, 1, 0);  /* tx_aggr_mode, txsel, rx_aggr_mode, rxsel */

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_hl_n10g_config (module_id, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, TEN_INITIAL_CONFIG);

  /* Enable clock */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, module, CS_TX_AND_RX, CS_ENABLE);
  /* Remove hard reset from the top */
  rtn |= ten_mpif_global_reset_n40g (dev_id, module, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  rtn |= ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + (module * TEN_N40G_STRIDE), 0);

  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id,
                                       TEN_TRAFFIC_TYPE_OC768,
                                       traffic_type,
                                       fec,
                                       /*TEN_MAP_AMP,*/
                                       TEN_MAP_BMP,
                                       32,
                                       0xFF,
                                       /*TEN_OC192_TERM_TRANSPARENT_CBR10,*/
                                       TEN_OC192_TERM_MS_LAYER_REGENERATOR,
                                       0,
                                       mld,
                                       pattern);

  /* Provision N10G part for Sonet */
  /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
  rtn |= ten_n10g_set_gblt_cfgtx0 (module_id, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0); /* PPLF_EN, CBRSTMAISINS, PN11AUTO, OTNOFF, OBY, SBY, KPGBY, PKTIE */

  /* A1A2 insertion needs to be set A1A2IE */
  rtn |= ten_n10g_soht_set_a1a2ie (module_id, TEN_SLICE_ALL, 1);  /* A1A2IE */

  /* POH insertion needs to be set POHIE */
  rtn |= ten_n10g_soht_pohben0 (module_id, TEN_SLICE_ALL, 1, 1);  /* PRBSIE, POHIE */

  /* disable all OTN wrapping */
  rtn |= ten_n10g_otnt_set_wrmd (module_id, TEN_SLICE_ALL, 0);  /* WRMD */

  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id, TEN_SLICE_ALL, 2, 0, 0, 0, 1, 0, 1); /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */

  rtn |= ten_hl_config_fec_t41 (module_id, 0, TEN_SLICE_40G, fec);

  /* Bugzilla 24956 Start */ 
  rtn |= ten_hl_n40g_config_lom_from_traffic (module_id, traffic_type, fec);
  /* Bugzilla 24956 End */
  /* Bugzilla #31390, set obfa2 lom */
  rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id, traffic_type, fec);
  
  /* Bugzilla 24750 Start */
  ten_hl_n40g_otn_aligner_settings (module_id);
  /* Bugzilla 24750 End */

  /* Bugzilla 13005 Start  M0BYTE description inverted in T40 DS */
  ten_n40g_sdfr_lofcfg2_m0byte(module_id, 1);
  /* Bugzilla 13005 End */

  return (rtn);
}
/* Bugzilla 24360 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 40G WIRE                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_40g_wire_t41(cs_uint16 module_id_line)
/* INPUTS     : o Line Module Id                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a 40 Gig line/client unframed CBR pair.            */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_config_40g_wire_t41_v2(module_id_line, 
                                        TEN_TRAFFIC_TYPE_NONE,
                                        0,  
                                        TEN_TRAFFIC_TYPE_NONE,
                                        0));
}

/* Bugzilla 24645 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 40G WIRE V2                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_40g_wire_t41_v2(cs_uint16 module_id_line, 
                                        cs_uint16 line_traffic,
                                        cs_uint16 line_fec,
                                        cs_uint16 client_traffic,
                                        cs_uint16 client_fec)
/* INPUTS     : o Line Module Id                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a 40 Gig line/client unframed CBR pair.            */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module_id_client;
  cs_uint16 module_line;
  cs_uint16 module_client;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_40g_wire_t41_v2";  

  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);
  module_id_client = module_id_line ^ TEN_MODULE_B;

  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id_line);

  module_line   = TEN_MOD_ID_TO_MOD_NUM (module_id_line);
  module_client = module_line ^ TEN_MODULE_B;

  CS_PRINT("%s() %s\n", func, ten_module_strings[module_id_line&1]);

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_mpif_global_clock_disable_n10g (dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX_AND_RX, CS_ENABLE);
  rtn |= ten_mpif_global_reset_n10g (dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Bypass OTN and Sonet and turn them off */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id_line, TEN_SLICE_ALL, 0, 0, 1, 1, 1, 1, 1);   /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id_client, TEN_SLICE_ALL, 0, 0, 1, 1, 1, 1, 1); /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */

  rtn |= ten_n10g_set_gblt_bypasses (module_id_line, TEN_SLICE_ALL, 1, 1, 1, 1); /* OTNOFF, OBY, SBY, KPGBY*/
  rtn |= ten_n10g_set_gblt_bypasses (module_id_client, TEN_SLICE_ALL, 1, 1, 1, 1);
  
  /* Enable N40G clocks */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_ENABLE);
  /* Remove hard reset from the top */
  rtn |= ten_mpif_global_reset_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Configure 40g TX data   (KPGBY, SBY, OBY, MDPCFG) */
  rtn |= ten_n40g_gblt4x_set_cfg (module_id_line, 1, 1, 1, 0); /* KPGBY, SBY, OBY, MDPCFG */
  rtn |= ten_n40g_gblt4x_set_cfg (module_id_client, 1, 1, 1, 0);
  rtn |= ten_n40g_gblr4x_set_dpcfg0 (module_id_line, 0, 1, 0, 1, 1, 1); /* KPASEL(dontcare), BYPCFG, MDPCFG(dontcare), BYSEL, OBY, SBY */
  rtn |= ten_n40g_gblr4x_set_dpcfg0 (module_id_client, 0, 1, 0, 1, 1, 1); /* KPASEL(dontcare), BYPCFG, MDPCFG(dontcare), BYSEL, OBY, SBY */
  
  /* Turn the OTN aligner off */
  rtn |= ten_n40g_otnr4x_alen (module_id_line, 0);
  rtn |= ten_n40g_otnr4x_alen (module_id_client, 0);

  /* Provision Data Cross connect for straight accross for 40G Monolithic */
  rtn |= ten_hl_xcon_config (dev_id, 0, 4, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 1, 5, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 2, 6, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 3, 7, TEN_TRAFFIC_TYPE_OTU2);

  rtn |= ten_hl_xcon_config (dev_id, 4, 0, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 5, 1, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 6, 2, TEN_TRAFFIC_TYPE_OTU2);
  rtn |= ten_hl_xcon_config (dev_id, 7, 3, TEN_TRAFFIC_TYPE_OTU2);
  
  /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
  rtn |= ten_xcon_sadeco_config (dev_id, module_client, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
  rtn |= ten_xcon_sadeco_config (dev_id, module_line  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

  /* Provision Skew and Delay Compensation Sonet Frame Length. */
  rtn |= ten_xcon_sadeco_sdclen (dev_id, module_client, 0x3FC);
  rtn |= ten_xcon_sadeco_sdclen (dev_id, module_line,   0x3FC);

  /* Select incoming reference and tributary streams */
  rtn |= ten_xcon_sadeco_sel_data_stream (dev_id, module_client, 0x0F, 0x1F);
  rtn |= ten_xcon_sadeco_sel_data_stream (dev_id, module_line  , 0x0F, 0x1F);

  /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
  rtn |= ten_xcon_sadeco_enable_fp (dev_id, module_client, CS_ENABLE);
  rtn |= ten_xcon_sadeco_enable_fp (dev_id, module_line  , CS_ENABLE);

  if ((line_traffic == TEN_TRAFFIC_TYPE_OTU3) || (line_traffic == TEN_TRAFFIC_TYPE_OTU3E) ||
     (line_traffic == TEN_TRAFFIC_TYPE_OTU3P) || (line_traffic == TEN_TRAFFIC_TYPE_OTU3P2) ||
     (line_traffic == TEN_TRAFFIC_TYPE_OTU3E2) || (line_traffic == TEN_TRAFFIC_TYPE_OTU3E4) ||
     (line_traffic == TEN_TRAFFIC_TYPE_OTU3E3) ) {
    rtn |= ten_hl_n40g_config_lom_from_traffic (module_id_line, line_traffic, line_fec);
    rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id_line, line_traffic, line_fec);
    rtn |= ten_hl_n40g_config_lof_from_traffic(module_id_line, line_traffic, line_fec);
    rtn |= ten_hl_n40g_config_lof_obfa2_from_traffic(module_id_line, line_traffic, line_fec);
  }
  
  if ((client_traffic == TEN_TRAFFIC_TYPE_OTU3) || (client_traffic == TEN_TRAFFIC_TYPE_OTU3E) ||
     (client_traffic == TEN_TRAFFIC_TYPE_OTU3P) || (client_traffic == TEN_TRAFFIC_TYPE_OTU3P2) ||
     (client_traffic == TEN_TRAFFIC_TYPE_OTU3E2) || (client_traffic == TEN_TRAFFIC_TYPE_OTU3E4) ||
     (client_traffic == TEN_TRAFFIC_TYPE_OTU3E3) ) {
    rtn |= ten_hl_n40g_config_lom_from_traffic (module_id_client, client_traffic, client_fec);
    rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id_client, client_traffic, client_fec);
    rtn |= ten_hl_n40g_config_lof_from_traffic(module_id_client, client_traffic, client_fec);
    rtn |= ten_hl_n40g_config_lof_obfa2_from_traffic(module_id_client, client_traffic, client_fec);
  }
  
  return (rtn);
}
/* Bugzilla 24645 End */

/* Bugzilla 24559 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 40G CBR KPGA               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_40g_cbr_kpga_t41 (cs_uint16 module_id,
                                          cs_uint16 pattern)
/* INPUTS     : o Module Id                                     */
/*              o Traffic Type                                  */
/*              o Pattern                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a 40 Gig unframed Constant Bit Rate Known Pattern  */
/* Generator/Analyzer                                           */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
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
  cs_uint16 dev_id;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_n40g_gblt4x_kpgcfg;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_40g_cbr_kpga_t41";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);

  if (pattern > TEN_KPG_PN31) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s\n", func, ten_module_strings[module_id&1], ten_kpg_strings[pattern]);

  /* Bugzilla 26130 Start */
  /* Selects the datapath source to be the single 40G RX clock */
  rtn |= ten_mpif_clock_select_40g_per_module (dev_id, module_id & 1, 1, 1);
  /* Provision  the 40G block bypass */
  rtn |= ten_mpif_global_cfg_per_module (dev_id, module_id & 1, 0, 0); 
  /* Bugzilla 26130 End */

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_mpif_global_clock_disable_n10g (dev_id, module_id & 1, TEN_SLICE_ALL, CS_TX_AND_RX, CS_ENABLE);
  rtn |= ten_mpif_global_reset_n10g (dev_id, module_id & 1, TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Bypass OTN and Sonet and turn them off */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id, TEN_SLICE_ALL, 0, 0, 1, 1, 1, 1, 1);   /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */
  rtn |= ten_n10g_set_gblt_bypasses (module_id, TEN_SLICE_ALL, 1, 1, 1, 1); /* OTNOFF, OBY, SBY, KPGBY*/


  /* Enable N40G clocks */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, module_id & 1, CS_TX_AND_RX, CS_ENABLE);
  /* Remove hard reset from the top */
  rtn |= ten_mpif_global_reset_n40g (dev_id, module_id & 1, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Configure 40g TX data   (KPGBY, SBY, OBY, MDPCFG) */
  rtn |= ten_n40g_gblt4x_set_cfg (module_id, 0, 1, 1, 0); /* KPGBY, SBY, OBY, MDPCFG */
  rtn |= ten_n40g_gblr4x_set_dpcfg0 (module_id, 1, 1, 0, 1, 1, 1); /* KPASEL, BYPCFG, MDPCFG(dontcare), BYSEL, OBY, SBY */

  /* Turn the OTN aligner off */
  rtn |= ten_n40g_otnr4x_alen (module_id, 0);

  /* Config KPG - PATSEL */
  /*rtn |= ten_n40g_config_kpg (module_id, 1, 0, pattern, 0, 0, 0, 0, 0, 0, 0, 0);*/
  tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
  tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);


  return (rtn);
}
/* Bugzilla 24559 End */

/* Bugzilla 28977 Start */
/* Bugzilla 26525 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU3V XCON LOOPBACK T41    */
/*                 VERSION 2                                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3v_xcon_loopback_t41_v2 (cs_uint16 module_id,
                                                    cs_uint16 dyn_repro,
                                                    cs_uint16 traffic_type,
                                                    cs_uint16 fec,
                                                    cs_uint16 term_otu,
                                                    cs_uint16 tcm_bits,
                                                    cs_uint16 mld,
                                                    cs_uint16 deskew_ctrl)
/* INPUTS     : o Module Id                                     */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type                                  */
/*              o FEC Type                                      */
/*              o Term OTU                                      */
/*              o TCM                                           */
/*              o MLD                                           */
/*              o Deskew Control                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision OTU3v XCON loopback                                */
/* V2 added the ability to select where the desckew is done     */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type of       */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 35                               */
/*                                                              */
/* [fec] parameter defines the line fec type:                   */
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
/* [term_otu] parameter defines the way the OTU2 will be        */
/* sinked and sourced                                           */
/*   TEN_OTU_TERM_TRANSPARENT = 0                               */
/*   TEN_OTU_TERM_SECTION     = 1                               */
/*                                                              */
/* The [tcm_bits] parameter specifyS the termination for TCM 1  */
/* through 6 for the line and client.                           */
/* This is a bit encoded parameter with bits 1 through 6        */
/* specifying TCM 1 through 6 respectively.                     */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [mld] parameter enables distributing data across         */
/* multiple lanes on line side i.e. OTL3.4                      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [deskew_ctrl] parameter specifies the 40G deskew         */
/* facility to use                                              */
/*   TEN_SADECO_DESKEW       = 0                                */
/*   TEN_PP40G_BYPASS_DESKEW = 1                                */
/*   TEN_PP40G_DESKEW        = 2                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 module;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_hl_config_otu3v_xcon_loopback_t41";  
  cs_status rtn = CS_OK;

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  module = TEN_MOD_ID_TO_MOD_NUM (module_id);

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3P) && 
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3P2) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E2)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 1, 2, 3, 23, 25, 35.", func, traffic_type);
    return (CS_ERROR);
  }

  if (fec >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() fec %d out of range.  s/b 0..15.", func, fec);
    return (CS_ERROR);
  }

  if (term_otu > TEN_OTU_TERM_SECTION) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() term_otu %d out of range.  s/b 0..1.", func, term_otu);
    return (CS_ERROR);
  }

  if (tcm_bits & ~0x7E) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_bits 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_bits);
    return(CS_ERROR);
  }

  if (mld > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() mld %d out of range.  s/b 0..1.", func, mld);
    return (CS_ERROR);
  }

  if (deskew_ctrl > TEN_PP40G_DESKEW) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() deskew_ctrl %d out of range.  s/b 0, 1, 2.", func, deskew_ctrl);
    return (CS_ERROR);
  }

  CS_PRINT("%s()\n", func);
  CS_PRINT("    %s\n", ten_module_strings[module_id & 1]);
  CS_PRINT("    %s\n",  ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    %s\n", ten_hl_config_traffic_types_strings[traffic_type]);
  CS_PRINT("    %s\n", ten_fec_ovhd_strings[fec]);
  CS_PRINT("    %s, tcm_bits = 0x%X, mld = %d\n", ten_hl_config_otu_overhead_term_strings[term_otu]);
  CS_PRINT("    tcm_bits = 0x%X\n", tcm_bits);
  CS_PRINT("    mld = %d\n", mld);

  /* Selects the datapath source to be the single 40G RX clock */
  rtn |= ten_mpif_clock_select_40g_per_module (dev_id, module_id & 1, 1, 1);
  /* Provision  the 40G block bypass */
  rtn |= ten_mpif_global_cfg_per_module (dev_id, module_id & 1, 0, 0); 
  
  /* duplicate call -- already done during HSIF provisioning */
  /* rtn |= ten_set_vco_coarse_tuning (dev_id, port + 1); */
  
  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  rtn |= ten_hsif_clk_40g (module_id,   1, 0, 1, 0);  /* tx_aggr_mode, txsel, rx_aggr_mode, rxsel */

  /* Enable the N10G and configure it for bypass */
  rtn |= ten_hl_n10g_config (module_id, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);

  /* Enable clock */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, module, CS_TX_AND_RX, CS_ENABLE);      
  /* Remove hard reset from the top */
  rtn |= ten_mpif_global_reset_n40g (dev_id, module, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Configure Line side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id,
                                       traffic_type,
                                       traffic_type,
                                       fec,
                                       TEN_MAP_BMP,
                                       32,
                                       0xFF,
                                       term_otu,
                                       tcm_bits,
                                       mld,
                                       TEN_KPG_DISABLED);
           
  if (module == TEN_MODULE_A) {
    /* Provision Data Cross Connect for 40G Module A loopback */
    rtn |= ten_hl_xcon_config (dev_id, 0, 0, TEN_TRAFFIC_TYPE_OTU2);
    rtn |= ten_hl_xcon_config (dev_id, 1, 1, TEN_TRAFFIC_TYPE_OTU2);
    rtn |= ten_hl_xcon_config (dev_id, 2, 2, TEN_TRAFFIC_TYPE_OTU2);
    rtn |= ten_hl_xcon_config (dev_id, 3, 3, TEN_TRAFFIC_TYPE_OTU2);
  } else {
    /* Provision Data Cross Connect for 40G Module B loopback */
    rtn |= ten_hl_xcon_config (dev_id, 4, 4, TEN_TRAFFIC_TYPE_OTU2);
    rtn |= ten_hl_xcon_config (dev_id, 5, 5, TEN_TRAFFIC_TYPE_OTU2);
    rtn |= ten_hl_xcon_config (dev_id, 6, 6, TEN_TRAFFIC_TYPE_OTU2);
    rtn |= ten_hl_xcon_config (dev_id, 7, 7, TEN_TRAFFIC_TYPE_OTU2);
  }
    
  if (deskew_ctrl == TEN_SADECO_DESKEW) {
    /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
    rtn |= ten_xcon_sadeco_config (dev_id, module_id  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

    /* Provision Skew and Delay Compensation Frame Length. */
    if (term_otu == TEN_OTU_TERM_FULL) {
      rtn |= ten_xcon_sadeco_sdclen (dev_id, module_id,   0x3B0);    /* [255 columns - 16(FEC) - 2(FS) - 1(OH)]  * 4 */      
    } else {
      rtn |= ten_xcon_sadeco_sdclen (dev_id, module_id,   0x3BC);    /* [255 columns - 16(FEC)]  * 4 */      
    }  
  
    /* Select incoming reference and tributary streams */
    rtn |= ten_xcon_sadeco_sel_data_stream (dev_id, module_id  , 0x0F, 0x1F);
  
    /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
    rtn |= ten_xcon_sadeco_enable_fp (dev_id, module_id  , CS_ENABLE);
  } else {
    /* Do the deskewing in the PP40G bypass */
    rtn |= ten_pp40g_rx_pp40g_rx_bypass_t41 (module_id);
    rtn |= ten_pp40g_tx_pp40g_tx_bypass_t41 (module_id);

    rtn |= ten_pp40g_rx_bypass_dsk_en_t41(module_id, 1);
  }

  /* Provision FEC */
  rtn |= ten_hl_config_fec_t41 (module_id, 0, TEN_SLICE_40G, fec);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU3V XCON LOOPBACK T41    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3v_xcon_loopback_t41 (cs_uint16 module_id,
                                                 cs_uint16 dyn_repro,
                                                 cs_uint16 traffic_type,
                                                 cs_uint16 fec,
                                                 cs_uint16 term_otu,
                                                 cs_uint16 tcm_bits,
                                                 cs_uint16 mld)
/* INPUTS     : o Module Id                                     */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type                                  */
/*              o FEC Type                                      */
/*              o Term OTU                                      */
/*              o TCM                                           */
/*              o MLD                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision OTU3v XCON loopback                                */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type of       */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1                                */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3                                */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*                                                              */
/* [fec] parameter defines the line fec type:                   */
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
/* [term_otu] parameter defines the way the OTU2 will be        */
/* sinked and sourced                                           */
/*   TEN_OTU_TERM_TRANSPARENT = 0                               */
/*   TEN_OTU_TERM_SECTION     = 1                               */
/*                                                              */
/* The [tcm_bits] parameter specifyS the termination for TCM 1  */
/* through 6 for the line and client.                           */
/* This is a bit encoded parameter with bits 1 through 6        */
/* specifying TCM 1 through 6 respectively.                     */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [mld] parameter enables distributing data across         */
/* multiple lanes on line side i.e. OTL3.4                      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_config_otu3v_xcon_loopback_t41_v2 (module_id,
                                                    dyn_repro,
                                                    traffic_type,
                                                    fec,
                                                    term_otu,
                                                    tcm_bits,
                                                    mld,
                                                    TEN_SADECO_DESKEW));
}
/* Bugzilla 28977 End */

/* Bugzilla 28977 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC768 XCON LOOPBACK T41    */
/*                 VERSION 2                                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc768_xcon_loopback_t41_v2 (cs_uint16 module_id,  
                                                    cs_uint16 dyn_repro, 
                                                    cs_uint16 traffic_type, 
                                                    cs_uint16 term_oc768,
                                                    cs_uint16 mld,
                                                    cs_uint16 deskew_ctrl)
/* INPUTS     : o Module Id                                     */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type                                  */
/*              o Term OC768                                    */
/*              o MLD                                           */
/*              o Deskew Control                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision OC768 XCON loopback                                */
/* Version 2 added a deskew contorl                             */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type of       */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OC768  = 22                               */
/*                                                              */
/* [term_oc768] parameter defines the way the OC192 will be     */
/* sinked and sourced                                           */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1                 */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2                 */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3                 */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4                 */
/*                                                              */
/* The [mld] parameter enables distributing data across         */
/* multiple lanes on line side i.e. OTL3.4                      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* The [deskew_ctrl] parameter specifies the 40G deskew         */
/* facility to use                                              */
/*   TEN_SADECO_DESKEW       = 0	                            */
/*   TEN_PP40G_BYPASS_DESKEW = 1                                */
/*   TEN_PP40G_DESKEW        = 2                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 module;
  cs_uint16 i;
  T41_t *pDev = NULL;
  cs_uint16 port = (module_id & 1) * 4; 
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_hl_config_oc768_xcon_loopback_t41";  
  cs_status rtn = CS_OK;

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  module = TEN_MOD_ID_TO_MOD_NUM (module_id);

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if (traffic_type != TEN_TRAFFIC_TYPE_OC768) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 22.", func, traffic_type);
    return (CS_ERROR);
  }

  if ((term_oc768 < TEN_OC192_TERM_TRANSPARENT_CBR10) || (term_oc768 > TEN_OC192_TERM_MS_LAYER_REGENERATOR)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() term_oc768 %d out of range.  s/b 1..4.", func, term_oc768);
    return (CS_ERROR);
  }

  if (mld > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() mld %d out of range.  s/b 0..1.", func, mld);
    return (CS_ERROR);
  }

  if (deskew_ctrl > TEN_PP40G_DESKEW) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() deskew_ctrl %d out of range.  s/b 0, 1, 2.", func, deskew_ctrl);
    return (CS_ERROR);
  }

  CS_PRINT("%s()\n", func);
  CS_PRINT("    %s\n", ten_module_strings[module_id&1]);
  CS_PRINT("    %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    %s\n", ten_hl_config_traffic_types_strings[traffic_type]);
  CS_PRINT("    %s\n", ten_hl_config_oc192_overhead_term_strings[term_oc768]);
  CS_PRINT("    mld=%d\n", mld);
  CS_PRINT("    %s\n", ten_deskew_strings[deskew_ctrl]);

  /* Selects the datapath source to be the single 40G RX clock */
  ten_mpif_clock_select_40g_per_module (dev_id, module_id & 1, 1, 1);
  /* Provision  the 40G block bypass */
  ten_mpif_global_cfg_per_module (dev_id, module_id & 1, 0, 0); 

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, port + 1); */
  
  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  ten_hsif_clk_40g (module_id, 1, 0, 1, 0);  /* module_id, tx_aggr_mode, txsel, rx_aggr_mode, rxsel */

  /* Enable the N10G and configure it for bypass */
  ten_hl_n10g_config (module_id, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, TEN_INITIAL_CONFIG);

  /* Enable clock to N40G blocks */
  ten_mpif_global_clock_disable_n40g (dev_id, module, CS_TX_AND_RX, CS_ENABLE);      
  /* Remove hard reset from the top of N40G block */
  ten_mpif_global_reset_n40g (dev_id, module, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Configure Client side N40g block */
  rtn |= ten_hl_n40g_config_trans_t41 (module_id,
                                       traffic_type,
                                       traffic_type,   /* No mapping */
                                       TEN_FEC_MODE_NOFEC,
                                       TEN_MAP_BMP,
                                       32,
                                       0xFF,
                                       term_oc768,
                                       0,
                                       mld,
                                       TEN_KPG_DISABLED);

  /* Disable 10G SONET descrambler - descrambling done in N40G */
  rtn |= ten_n10g_sdfr_set_scren(module_id, TEN_SLICE_ALL, 0);  /* slice, scren */

  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  rtn |= ten_n10g_set_gblr_dpcfg (module_id, TEN_SLICE_ALL, 1, 0, 0, 0, 1, 0, 1); /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */

  /* Disable 10G Sonet scrambler */
  rtn |= ten_n10g_soht_set_scren(module_id, TEN_SLICE_ALL, 0);  /* slice, scren */

  /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
  rtn |= ten_n10g_set_gblt_cfgtx0 (module_id, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0); /*pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie)*/

  /* Disable all N10G OTN wrapping */
  rtn |= ten_n10g_otnt_set_wrmd(module_id, TEN_SLICE_ALL, 0);

  rtn |= ten_hl_oc768_termination (module_id, module_id, term_oc768);

  if (module == TEN_MODULE_A) {
    /* Provision Data Cross Connect for 40G Module A loopback */
    ten_hl_xcon_config (dev_id, 0, 0, TEN_TRAFFIC_TYPE_OTU2);
    ten_hl_xcon_config (dev_id, 1, 1, TEN_TRAFFIC_TYPE_OTU2);
    ten_hl_xcon_config (dev_id, 2, 2, TEN_TRAFFIC_TYPE_OTU2);
    ten_hl_xcon_config (dev_id, 3, 3, TEN_TRAFFIC_TYPE_OTU2);
  } else {
    /* Provision Data Cross Connect for 40G Module B loopback */
    ten_hl_xcon_config (dev_id, 4, 4, TEN_TRAFFIC_TYPE_OTU2);
    ten_hl_xcon_config (dev_id, 5, 5, TEN_TRAFFIC_TYPE_OTU2);
    ten_hl_xcon_config (dev_id, 6, 6, TEN_TRAFFIC_TYPE_OTU2);
    ten_hl_xcon_config (dev_id, 7, 7, TEN_TRAFFIC_TYPE_OTU2);
  }
  
  /* Bugzilla 28977 Start */
  if (deskew_ctrl == TEN_SADECO_DESKEW) {
    if (ten_dev_is_t41(dev_id)) {   
      /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
      rtn |= ten_xcon_sadeco_config (dev_id, module_id, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

      /* Enable Multi Frame Pulse mode */
      for (i=0; i<4; i++) {
        rtn |= ten_xcon_es_config_t41 (dev_id, port + i, XCON_ES_CONFIG_MFP_MODE, 1);
      }
    } else {
      /* Configure the SADECO delay and compensation for Sonet SDH interleaving */
      rtn |= ten_xcon_sadeco_config (dev_id, module_id, 0x200, 0x1F00, XCON_SONET_SDH_64);
    }
    /* Bugzilla 28977 End */

    /* Provision Skew and Delay Compensation Sonet Frame Length. */
    rtn |= ten_xcon_sadeco_sdclen (dev_id, module_id,   0x97E0);    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */      
    
    /* Select incoming reference and tributary streams */
    rtn |= ten_xcon_sadeco_sel_data_stream (dev_id, module_id  , 0x0F, 0x1F);
    
    /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
    rtn |= ten_xcon_sadeco_enable_fp (dev_id, module_id, CS_ENABLE);
  } 
  else {
    /* Do the deskewing in the PP40G bypass */
    rtn |= ten_pp40g_rx_pp40g_rx_bypass_t41 (module_id);
    rtn |= ten_pp40g_tx_pp40g_tx_bypass_t41 (module_id);

    rtn |= ten_pp40g_rx_bypass_dsk_en_t41(module_id, 1);
  }

  return (rtn);
}
/* Bugzilla 26525 End */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC768 XCON LOOPBACK T41    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc768_xcon_loopback_t41 (cs_uint16 module_id,  
                                                 cs_uint16 dyn_repro, 
                                                 cs_uint16 traffic_type, 
                                                 cs_uint16 term_oc768,
                                                 cs_uint16 mld)
/* INPUTS     : o Module Id                                     */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type                                  */
/*              o Term OC768                                    */
/*              o MLD                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision OC768 XCON loopback                                */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_INITIAL_CONFIG        = 0                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type of       */
/* the line:                                                    */
/*   TEN_TRAFFIC_TYPE_OC768  = 22                               */
/*                                                              */
/* [term_oc768] parameter defines the way the OC192 will be     */
/* sinked and sourced                                           */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1                 */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2                 */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3                 */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4                 */
/*                                                              */
/* The [mld] parameter enables distributing data across         */
/* multiple lanes on line side i.e. OTL3.4                      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_config_oc768_xcon_loopback_t41_v2 (module_id,  
                                                    dyn_repro, 
                                                    traffic_type, 
                                                    term_oc768,
                                                    mld,
                                                    TEN_SADECO_DESKEW));
}
/* Bugzilla 28977 End */

/* Bugzilla 29609 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 40G IDLE                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_40g_idle_t41 (cs_uint16 module_id_line,
                                      cs_uint16 dyn_repro)
/* INPUTS     : o Module Id Client                              */
/*              o Dynamic Reprovision                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Config 40G OTN Idle.                                         */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [dyn_repro] parameter specifies the type of dynamic          */
/* reprovisioning:                                              */
/*   TEN_REPRO_CLIENT          = 1                              */
/*   TEN_REPRO_LINE_AND_CLIENT = 2                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 module_id_client;
  cs_uint16 slice;
  cs_uint16 client_module;
  cs_uint16 line_module;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_char8 *func = "ten_hl_config_40g_idle_t41";  

  TEN_MOD_COMMON_VALIDATE (module_id_line, pDev, CS_ERROR);

  if ((dyn_repro != TEN_REPRO_CLIENT) && (dyn_repro != TEN_REPRO_LINE_AND_CLIENT)){
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 1, 2.", func, dyn_repro);
    return (CS_ERROR);
  }
  
  CS_PRINT("%s() %s, %s\n", func, ten_module_strings[module_id_line&1], ten_hl_config_dyn_repro_strings[dyn_repro]);

  module_id_client = module_id_line ^ TEN_MODULE_B;
  client_module = TEN_MOD_ID_TO_MOD_NUM (module_id_client);
  line_module = TEN_MOD_ID_TO_MOD_NUM (module_id_line);
  
  /* Bugzilla #30991:  Corrections needed in null config autogen scripts */
  if (ten_hl_config_fec_t41 (module_id_client, 0, TEN_SLICE_40G, TEN_FEC_MODE_DEALLOCATE) == CS_ERROR) {
    CS_PRINT("40G FEC Provisioning failed!\n");
    return (CS_ERROR);
  }
  
  if (dyn_repro == TEN_REPRO_LINE_AND_CLIENT) {
    if (ten_hl_config_fec_t41 (module_id_line, 0, TEN_SLICE_40G, TEN_FEC_MODE_DEALLOCATE) == CS_ERROR) {
      CS_PRINT("10G FEC Provisioning failed!\n");
      return (CS_ERROR);
    }
  }
  
  if (dyn_repro == TEN_REPRO_CLIENT) {
    /* Enable OTN<->OHPP communications for the 40G stream */
    rtn |= ten_ohpp_sfu_set_otnohen (module_id_line, 0x10);
    rtn |= ten_ohpp_sfu_sreset (module_id_line, CS_RESET_DEASSERT);

    /* Place Open Connection Indication (OCI) siganl in the OTN frame */
    rtn |= ten_hl_ohpp_force_odu3_maintenance_signal (module_id_line, TEN_OHPP_INSERT_OCI, TEN_OHPP_WIDTH_FRAME, CS_ENABLE);
    
    /* Have OHPP buid the OTN frame (Build Own Frame) */
    rtn |= ten_ohpp_sfu_set_mssel (module_id_line, CS_ENABLE, TEN_OHPP_STREAM_OXU3);
    
#if 1
    rtn |= ten_n40g_otnt4x_set_wrapper_onoff (module_id_line, 1); /* WRMD   Enable full wrapping OPU3->OTU3 */
    
    /* Insert FAS pattern of 0xF6F6F6282828 in row 1, columns 1 through 6. */
    rtn |= ten_n40g_otnt4x_set_fasie (module_id_line, 1); /* FASIE */
#endif    
    
    /* Force FRAC_DIV provide clock to RXDIV */
    rtn |= ten_mpif_set_clock_switch_force (dev_id, line_module, 0, CS_TX, CS_ENABLE);
    /*if (($interface_type eq 'xfi') && ($mld_enable)) {*/
    rtn |= ten_mpif_set_clock_switch_force (dev_id, line_module, 2, CS_TX, CS_ENABLE);
  }
  
  /* Assert hard reset */
  rtn |= ten_mpif_global_reset_n40g (dev_id, client_module, CS_TX_AND_RX, CS_RESET_ASSERT);
  rtn |= ten_mpif_global_reset_pp40g_sys_t41 (dev_id, client_module, CS_RESET_ASSERT);
  rtn |= ten_mpif_global_reset_pp40g_t41 (dev_id, client_module, CS_TX_AND_RX, CS_RESET_ASSERT);
  /* Reset Sonet 10G  */
  rtn |= ten_mpif_global_reset_n10g (dev_id, client_module, TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_ASSERT);
  
  /* Disable clock */
  rtn |= ten_mpif_global_clock_disable_n40g (dev_id, client_module, CS_TX_AND_RX, CS_DISABLE);
  rtn |= ten_mpif_global_clock_disable_pp40g_sys_t41 (dev_id, client_module, CS_DISABLE);
  rtn |= ten_mpif_global_clock_disable_pp40g_rx_t41 (dev_id, client_module, CS_DISABLE);
  
  rtn |= ten_mpif_global_clock_disable_n10g (dev_id, client_module, TEN_SLICE_ALL, CS_TX_AND_RX, CS_DISABLE);

  rtn |= ten_mpif_global_clock_disable_n40g_n10g (dev_id, client_module, TEN_SLICE_ALL,
                                                  TEN_MPIF_N40G_DATAPATH, CS_TX_AND_RX, CS_ENABLE);
  
  /* Place all N40G sub-blocks in software reset */
  
  if (dyn_repro == TEN_REPRO_LINE_AND_CLIENT) {
    /* Assert hard reset */
    rtn |= ten_mpif_global_reset_n40g (dev_id, line_module, CS_TX_AND_RX, CS_RESET_ASSERT);
    rtn |= ten_mpif_global_reset_pp40g_sys_t41 (dev_id, line_module, CS_RESET_ASSERT);
    rtn |= ten_mpif_global_reset_pp40g_t41 (dev_id, line_module, CS_TX_AND_RX, CS_RESET_ASSERT);
    rtn |= ten_mpif_global_reset_n10g (dev_id, line_module, TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_ASSERT);

    /* Disable clock */
    rtn |= ten_mpif_global_clock_disable_n40g (dev_id, line_module, CS_TX_AND_RX, CS_DISABLE);
    rtn |= ten_mpif_global_clock_disable_pp40g_sys_t41 (dev_id, line_module, CS_DISABLE);
    rtn |= ten_mpif_global_clock_disable_pp40g_rx_t41 (dev_id, line_module, CS_DISABLE);

    rtn |= ten_hl_resets_block (module_id_client, 0, CS_RESET_ASSERT, TEN_HL_RESETS_BLOCK_SYNCDSYNC);
    rtn |= ten_hl_resets_block (module_id_line, 0, CS_RESET_ASSERT, TEN_HL_RESETS_BLOCK_SYNCDSYNC);
  } 
  
  /* Bugzilla 35494 Start */
  /* Place both Cross Connect SADECOs in reset */
  rtn |= ten_xcon_sadeco_reset (dev_id, 0, XCON_BLOCK_RESET, CS_RESET_ASSERT);
  rtn |= ten_xcon_sadeco_reset (dev_id, 1, XCON_BLOCK_RESET, CS_RESET_ASSERT);
  /* Bugzilla 35494 End */
  
  for (slice=0; slice<4; slice++) {  
    /* Place cross connect in reset */
    rtn |= ten_xcon_es_reset (dev_id, client_module * 4 + slice, CS_RESET_ASSERT);
    rtn |= ten_xcon_es_reset (dev_id, line_module * 4 + slice, CS_RESET_ASSERT);
  }

  return (rtn);
}
/* Bugzilla 29609 End */


