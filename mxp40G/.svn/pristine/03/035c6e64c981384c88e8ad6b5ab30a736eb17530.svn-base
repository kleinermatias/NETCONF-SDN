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
 * ten_hl_config_40g.c
 *
 * API's for high level 40g configuration.
 *
 * $Id: ten_hl_config_40g.c,v 1.29 2013/11/13 21:35:35 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"


/****************************************************************/
/* $rtn_hdr_start  CONFIG 40G MONOLITHIC                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_40g_monolithic(cs_uint16 mod_line,
                                       cs_uint16 mod_client,
                                       cs_uint16 line,
                                       cs_uint16 client,
                                       cs_uint16 dyn_repro,
                                       cs_uint16 line_fec,
                                       cs_uint16 client_fec,
                                       cs_uint16 sync_mode,
                                       cs_uint16 term_otu,
                                       cs_uint16 line_tcm_bits, 
                                       cs_uint16 client_tcm_bits, 
                                       cs_uint16 term_sonet)
/* INPUTS     : o Module Id Line                                */
/*              o Module Id Client                              */
/*              o Line                                          */
/*              o Client                                        */
/*              o Dynamic Reprovision                           */
/*              o Line Fec                                      */
/*              o Client Fec                                    */
/*              o Sync Mode                                     */
/*              o Term OTU                                      */
/*              o Line TCM bits                                 */
/*              o Client TCM bits                               */
/*              o Term Sonet                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures an N40G transmit/receive path.                    */
/*                                                              */
/* [mod_line] and [mod_client] specifies line's and client's    */
/* module ID                                                    */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* The [line] and [client] parameters are specified as:         */
/*   TEN_TRAFFIC_TYPE_OTU3               = 1,                   */
/*   TEN_TRAFFIC_TYPE_OTU3E              = 2,                   */
/*   TEN_TRAFFIC_TYPE_40GELAN            = 21,                  */
/*   TEN_TRAFFIC_TYPE_OC768              = 22,                  */
/*   TEN_TRAFFIC_TYPE_OTU3E3             = 23,                  */
/*   TEN_TRAFFIC_TYPE_CBR40G_50188149150 = 24,                  */
/*                                                              */
/* The [dyn_repro] parameter is specified as:                   */
/*  TEN_INITIAL_CONFIG (full)            = 0,                   */
/*  TEN_REPRO_CLIENT   (dynamic)         = 1,                   */
/*  TEN_REPRO_LINE_AND_CLIENT (dynamic)  = 2,                   */
/*                                                              */
/* The [line_fec] and [client_fec] parameters are specified as: */
/*   TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)           */
/*   TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)           */
/*   TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)           */
/*   TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)           */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)           */
/*   TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)           */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)          */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)          */
/*   TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)           */
/*   TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)           */
/*   TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)            */
/*   TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)     */
/*   TEN_FEC_MODE_NO_FEC            = 15   (FEC not present).   */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*                                                              */
/* The [sync_mode] parameter specifies the clock sync method    */
/*   0 = TEN_MAP_AMP                                            */
/*   1 = TEN_MAP_BMP                                            */
/*                                                              */
/* The [term_otu] parameter specifies the otu3 to otu3          */
/* termination and is specified as:                             */
/*   TEN_OTU_TERM_TRANSPARENT = 0x0000,                         */
/*   TEN_OTU_TERM_SECTION     = 0x0001,                         */
/*                                                              */
/* The [line_tcm_bits] and [client_tcm_bits] parameters         */
/* specifies the termination for TCM 1 through 6.               */
/* This is a bit encoded parameter with bits 1 through 6        */
/* specifying TCM 1 through 6 respectively.                     */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
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
  cs_uint16 dev_id;
  cs_uint16 i;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;
  /* Bugzilla 21131 Start */
  cs_uint16 payload_type = 3;
  /* Bugzilla 21131 End */
  cs_uint16 ncols_line = 254;
  cs_uint16 npar_line = 16;
  cs_uint16 ncols_client = 254;
  cs_uint16 npar_client = 16;
  cs_uint16 payload_type_byte;
  cs_uint16 stm256md = 0;
  cs_uint16 stm64md = 0;
  cs_uint16 num_cortina_em_fs = 0;  /* Number of Cortina Enhanced Mapping Fixed Stuff bytes */
 
  cs_uint16 num_pjo = 0;
  cs_uint16 jc_plus = 0;
  cs_uint16 jc_enabled = 0;
  cs_uint16 c15 = 0;
  /* Bugzilla 23776 Start */
  cs_char8 *func = "ten_hl_config_40g_monolithic";  

  #if 0
  cs_uint16 line_port   =  (mod_line & 1) * 4;
  cs_uint16 client_port =  (mod_client & 1) * 4;
  #endif

  TEN_MOD_COMMON_VALIDATE (mod_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE (mod_client, pDev, CS_ERROR);
  dev_id = TEN_MOD_ID_TO_DEV_ID(mod_line);
  /*module = TEN_MOD_ID_TO_MOD_NUM(module_id);*/

  /* Bugzilla 24940 Start */
  if ((line != TEN_TRAFFIC_TYPE_OTU3) && (line != TEN_TRAFFIC_TYPE_OTU3E) &&  
      (line != TEN_TRAFFIC_TYPE_OTU3E3) && (line != TEN_TRAFFIC_TYPE_OTU3P)) { 
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() line %d out of range.  s/b 1, 2, 23.", func, line);
    return (CS_ERROR);
  }    
  /* Bugzilla 24940 End */

  if ((client != TEN_TRAFFIC_TYPE_OTU3) && (client != TEN_TRAFFIC_TYPE_OC768) &&
      (client != TEN_TRAFFIC_TYPE_OTU3P) &&  
      (client != TEN_TRAFFIC_TYPE_40GELAN) && (client != TEN_TRAFFIC_TYPE_CBR40G_50188149150)) {
       
    CS_HNDL_ERROR(mod_client, ETEN_MOD_INVALID_USER_ARG, "%s() client %d out of range.  s/b 1, 21, 22, 24.", func, client);
    return (CS_ERROR);
  }    

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if (line_fec >= TEN_FEC_MODE_MAX_NUM) { 
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() line_fec %d out of range.  s/b 0..15.", func, line_fec);
    return (CS_ERROR);
  }
  
  if (client_fec >= TEN_FEC_MODE_MAX_NUM) { 
    CS_HNDL_ERROR(mod_client, ETEN_MOD_INVALID_USER_ARG, "%s() client_fec %d out of range.  s/b 0..15.", func, client_fec);
    return (CS_ERROR);
  }
  
  if (sync_mode > TEN_MAP_BMP) {
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() sync_mode %d > TEN_MAP_BMP out of range.  s/b 0..1.", func, sync_mode);
    return (CS_ERROR);
  }

  if (term_otu > TEN_OTU_TERM_SECTION) {
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_otu %d out of range.  s/b 0..1.", func, term_otu);
    return (CS_ERROR);
  }

  if (line_tcm_bits & ~0x7E) { 
    CS_HNDL_ERROR (mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() line_tcm_bits 0x%X out of range.  s/b 0, 0x2..0x7E.", func, line_tcm_bits);
    return(CS_ERROR);
  }

  if (client_tcm_bits & ~0x7E) { 
    CS_HNDL_ERROR (mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() client_tcm_bits 0x%X out of range.  s/b 0, 0x2..0x7E.", func, client_tcm_bits);
    return(CS_ERROR);
  }

  if ((term_sonet < TEN_OC192_TERM_TRANSPARENT_CBR10) || (term_sonet > TEN_OC192_TERM_MS_LAYER_REGENERATOR)) {
    CS_HNDL_ERROR(mod_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_sonet %d out of range.  s/b 1..4.", func, term_sonet);
    return (CS_ERROR);
  }


  CS_PRINT("%s() %s, %s, %s, %s, %s, %s, %s, %s, line_tcm_bits = 0x%X, client_tcm_bits = 0x%X, %s\n",
           func,
           ten_module_strings[mod_line & 1],
           ten_module_strings[mod_client & 1],
           ten_hl_config_traffic_types_strings[line],
           ten_hl_config_traffic_types_strings[client],
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_fec_ovhd_strings[line_fec],
           ten_fec_ovhd_strings[client_fec],
           ten_hl_config_otu_overhead_term_strings[term_otu],
           line_tcm_bits,
           client_tcm_bits,
           ten_hl_config_oc192_overhead_term_strings[term_sonet]);
  /* Bugzilla 23776 End */

  
  /* Bugzilla 21131 Start */
  /* Set Payload Type Insertion (PTI) value to what the tester expects - 03 sync, 02 - async */
  if (sync_mode == 1) {
    payload_type = TEN_PAYLOAD_TYPE_SYNC_CBR;
  }
  else {
    payload_type = TEN_PAYLOAD_TYPE_ASYNC_CBR;
  }
  /* Bugzilla 21131 End */

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, line_port + 1);  */ /* Bugzilla #24261 */
  /* ten_set_vco_coarse_tuning (dev_id, client_port + 1); */ /* Bugzilla #24261 */
  
  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  /*cs_status ten_hsif_clk_40g(module_id, tx_aggr_mode, txsel, rx_aggr_mode, rxsel) */
  ten_hsif_clk_40g (mod_line,   1, 0, 1, 0);
  ten_hsif_clk_40g (mod_client, 1, 0, 1, 0);
  
  
  /* Do not know if this is being done correctly in ten_hl_xcon_cfg(cs_uint16 dev_id, cs_uint8 slice, cs_uint8 mode) */
  for (i=0; i<8; i++) {
    ten_xcon_select_es_packet_centering (dev_id, i, XCON_PKT_CENTERING_ALL, CS_DISABLE);
    ten_xcon_set_circuit_thresholds (dev_id, i, XCON_ES_IML_THRESH, 0x1000);
  }


  /* Enable the N10G and configure it for bypass */
  ten_hl_n10g_config (mod_line, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);
  ten_hl_n10g_config (mod_client, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);



  /* Enable clock */
  ten_mpif_global_clock_disable_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_ENABLE);      
  /* Remove hard reset from the top */
  ten_mpif_global_reset_n40g (dev_id, TEN_MODULE_A_AND_B, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  ten_reg_write(dev_id,TEN_N40G_OTNT4X_WRPCFG1 + ((mod_line & 1) * TEN_N40G_STRIDE), 0);
  ten_reg_write(dev_id,TEN_N40G_OTNT4X_WRPCFG1 + ((mod_client & 1) * TEN_N40G_STRIDE), 0);
  
  

                                        
  if ((line == TEN_TRAFFIC_TYPE_OTU3) && (client == TEN_TRAFFIC_TYPE_OC768)) {
    /*############################################################*/
    /*#   Configure Line side TX N40G                             */
    /*############################################################*/

    ncols_line = 254;  /* Standard OTU frame with 7% FEC */
    npar_line = 16;    /* 7% FEC */
    stm256md  = 1;     /* Standard OTU fixed stuff bytes */
    stm64md = 0;
    num_cortina_em_fs = 0;
    if (sync_mode == 1) {
      /* Disable Justification in syncronous mode */
      jc_enabled = 0;
      payload_type_byte = 0x03;
    } else {
      jc_enabled = 1;
      payload_type_byte = 0x02;
    }
    num_pjo = 1;
    jc_plus = 0;
    c15 = 0;
    
    ncols_client = 238; /* Standard OTU payload size */
    npar_client = 0;
      
/*CS_PRINT("ncols_line = ncols_line, npar_line = npar_line\n");*/
/*CS_PRINT("ncols_client = ncols_client, npar_client = npar_client\n");*/

/*CS_PRINT ("stm256md = stm256md, stm64md = stm64md, num_cortina_em_fs = num_cortina_em_fs, num_c15 = num_c15, c15 = c15, \n");*/
/*CS_PRINT ("num_pjo = num_pjo, jc_plus = jc_plus, jc_enabled = jc_enabled\n");*/
        
    /* Configure 40g TX data path for OTU framing of data from the OC768 mapper  (KPGBY, SBY, OBY, MDPCFG) */
    ten_n40g_gblt4x_set_cfg(mod_line, 1, 0, 0, 3);
  
    /*ten_n40g_otnt4x_scrambling and ten_n40g_otnr4x_descrambling already done in config_fec_40g! */
    ten_n40g_otnt4x_scrambling(mod_line, 0, 1); /* GFEC scrambling   POSTSCR, PRESCR */
  
    /* Configure STM256, STM64, Aggregation mode Monolithic and Wrapper mode ON  (WRPCFG3: STM256MD, STM64MD, AGGRMOD, WRMD) */
    ten_n40g_otnt4x_set_wrpcfg3 (mod_line, stm256md, stm64md, 0, 1);
  
    /* Program the 40G SONET Transmit block: (b1inv, b1trans, b1ie, scren, a1a2rsh ) */
    ten_n40g_st4x_set_ohie(mod_line, 0, 0, 0, 1, 0);
  
    /* Disable 10G Sonet scrambler */
    /*cs_status ten_n10g_soht_set_scren(cs_uint16 module_id, cs_uint8 slice, cs_uint16 scren)*/
    ten_n10g_soht_set_scren(mod_line, TEN_SLICE_ALL, 0);
  
  
  
    /* Insert FAS pattern of 0xF6F6F6282828 hex row 1, columns 1 through 6   (FASIE) */
    ten_n40g_otnt4x_set_fasie(mod_line, 1);
  
    /* Enable BIP */
    ten_n40g_otnt4x_bipmsk(mod_line, 0xFF);
  
    /* Bugzilla 21131 Start */
    /* Set Payload Type Insertion (PTI) value to what the tester expects - 03 sync, 02 - async */
    ten_n40g_set_pti_byte(mod_line, payload_type);
    /* Bugzilla 21131 End */

  
    /* Enable Payload Type Insertion (PTIE) */
    ten_n40g_otnt4x_set_ptie(mod_line, 1);
  
    /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
    ten_n10g_set_gblt_cfgtx0 (mod_line, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0);
                                                                   /*pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie) */
   
    /* disable all N10G OTN wrapping */
    ten_n10g_set_otnt_wrpcfg3(mod_line, TEN_SLICE_ALL, 0, 0, 0, 0, 0);
                                                                    /*stm64md, fpsynce, c15res_en, g43md, wrmd) */
  
    ten_n40g_otnt4x_set_wrpcfg4(mod_line, jc_plus, jc_enabled);  /* Enable wrapper to generate justification commands.   Enable enhanced justification */
  
  

    /*########################################################### */
    /*#   Configure Line side RX N40G                             */
    /*############################################################*/
    /* Configure 40g RX data path for OTU Dewrapper and then through the OC768  (KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY) */
    ten_n40g_gblr4x_set_dpcfg0(mod_line, 0, 0, 3, 0, 0, 0);
     
    /* Configure STM256, STM64, Aggregation mode Monolithic and Dewrapper mode ON (DW_CONFIG: FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE) */
    ten_n40g_otnr4x_set_odwcfg (mod_line, 0, stm64md, stm256md, 0, 1); 
  
    /* Enable 40G SONET descrambler */
    ten_n40g_sdfr_enable_descrambler(mod_line, 1 );
    /* Disable 10G SONET descrambler - descrambling done in N40G */
    /*cs_status ten_n10g_sdfr_set_scren(cs_uint16 module_id, cs_uint8 slice, cs_uint16 scren)*/
    ten_n10g_sdfr_set_scren(mod_line, TEN_SLICE_ALL, 0);
  
    /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
    ten_n10g_set_gblr_dpcfg (mod_line, TEN_SLICE_ALL, 1, 0, 1, 0, 1, 0, 1);
  
    /* Bugzilla 21131 Start */
    /* Set expected Payload Type (PT) to match tester - 03 - sync , 02 - async */
    ten_n40g_set_expected_pti_byte(mod_line, payload_type);
    /* Bugzilla 21131 End */


    /* Enable enhanced justification if Async */
    ten_n40g_otnr4x_set_jc_enable(mod_line, jc_enabled);   /* Enable justification commands to be evaluated in de-wrapping. */
    ten_n40g_otnr4x_set_jc_plus(mod_line, jc_plus);     /* Provision enhanced justification. */

    /* Bugzilla 24750 Start */
    ten_hl_n40g_otn_aligner_settings (mod_line);
    /* Bugzilla 24750 End */
  
  
  
    /*##############################################################################             */
    /*#misc_info("Enable test clock outputs: GPLL RX clock, MRA RX VCO clock, MRB RX VCO clock");*/
    /*###############################################################################            */
    /* Probably not needed */
    /*cs_status ten_mpif_rxclk_refout(cs_uint16 dev_id, cs_uint16 div, cs_uint16 select) */
    ten_mpif_rxclk_refout (dev_id, 0x7, 0x4);
  
    /*cs_status ten_mpif_set_lvds_pd(cs_uint16 dev_id, cs_uint16 select, cs_uint16 value)*/
    ten_reg_write(dev_id,0x00063,0x003c); /* ??? Added for OTU3 to OC768  */
  
    ten_reg_write(dev_id,0x0006b,0x000f); /* Power down all OHPP LVDS otuput buffers */
    ten_reg_write(dev_id,0x01082,0x0237); /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
    ten_reg_write(dev_id,0x02082,0x0237); /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
    ten_reg_write(dev_id,0x0108a,0x002c); /* Receive spare control bits for SERDES analog front end */
    ten_reg_write(dev_id,0x0208a,0x002c); /* Receive spare control bits for SERDES analog front end */
  
  
  
    /*############################################################*/
    /*#   Configure Client side RX N40G                           */
    /*############################################################*/
    /* Configure 40g RX data path for OTU framing of data straight to the OC768  (KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY) */
    ten_n40g_gblr4x_set_dpcfg0(mod_client, 0, 0, 3, 0, 1, 0);
  
    /* Disabel OTU3 dewrapper  DW_ENABLE */
    ten_n40g_otnr4x_set_dw_enable(mod_client, 0); 
  
    /* Enable 40G SONET descrambler */
    ten_n40g_sdfr_enable_descrambler(mod_client, 1 );
    /* Disable 10G SONET descrambler - descrambling done in N40G */
    /*cs_status ten_n10g_sdfr_set_scren(cs_uint16 module_id, cs_uint8 slice, cs_uint16 scren) */
    ten_n10g_sdfr_set_scren(mod_client, TEN_SLICE_ALL, 0);
  
    /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
    ten_n10g_set_gblr_dpcfg (mod_client, TEN_SLICE_ALL, 1, 0, 0, 0, 1, 0, 1);   
  
    /* Set NCOLS and NPAR in case we do a CBR */
    ten_n40g_otnr4x_set_ncols (mod_client, ncols_client); 
    ten_n40g_otnr4x_set_nparb_npar (mod_client, 0, npar_client); 
  
    /*############################################################*/
    /*#   Configure Client side TX N40G                           */
    /*############################################################*/
    /* Configure 40g TX data   (KPGBY, SBY, OBY, MDPCFG) */
    ten_n40g_gblt4x_set_cfg(mod_client, 1, 0, 1, 3);

    /* Disable OTU3 scrablers  (POSTSCR, PRESCR) */
    ten_n40g_otnt4x_scrambling(mod_client, 0, 0);

    /* Turn N40G Wrapper off  (WRMD) */
    ten_n40g_otnt4x_set_wrapper_onoff(mod_client, 0);

    /* Program the 40G SONET Transmit block: (b1inv, b1trans, b1ie, scren, a1a2rsh ) */
    ten_n40g_st4x_set_ohie(mod_client, 0, 0, 0, 1, 0);

    /* Disable 10G Sonet scrambler */
    /*cs_status ten_n10g_soht_set_scren(cs_uint16 module_id, cs_uint8 slice, cs_uint16 scren)*/
    ten_n10g_soht_set_scren(mod_client, TEN_SLICE_ALL, 0);

    /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
    ten_n10g_set_gblt_cfgtx0 (mod_client, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0);
                                                                   /*pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie)*/
  
    /* Disable all N10G OTN wrapping */
    ten_n10g_otnt_set_wrmd(mod_client, TEN_SLICE_ALL, 0);

      
    ten_hl_oc768_termination (mod_line, mod_client, term_sonet);
        
    /* Bugzilla #24460, correct 40G SONET/SDH Aligner Settings */
    ten_n40g_sdfr_set_sdfcfg_fawwup_fawwdw(mod_client, 4, 1);
    ten_n40g_sdfr_set_sdfcfg_fawwup_fawwdw(mod_line, 4, 1); 
  }

  else if ((line == TEN_TRAFFIC_TYPE_OTU3) && (client == TEN_TRAFFIC_TYPE_OTU3)) {
    /*############################################################*/
    /*#   Configure Line side TX N40G                             */
    /*############################################################*/
    ten_hl_n40g_tx_init (mod_line, TEN_N40G_TX_ODU3_OTU3_SL);

    /* Bugzilla 21131 Start */
    ten_hl_40g_otu3_tx_termination (mod_line, term_otu, line_tcm_bits);

    /* Set Payload Type Insertion (PTI) value to what the tester expects - 03 sync, 02 - async */
    ten_n40g_set_pti_byte(mod_line, payload_type);
    /* Bugzilla 21131 End */


    /*############################################################*/
    /*#   Configure Line side RX N40G                             */
    /*############################################################*/
    ten_hl_n40g_rx_init (mod_line, TEN_N40G_RX_OTU3_ODU3_LS);

    /* Bugzilla 21131 Start */
    ten_hl_40g_otu3_rx_termination (mod_line, term_otu);

    /* Set expected Payload Type (PT) to match tester - 03 - sync , 02 - async */
    ten_n40g_set_expected_pti_byte(mod_line, payload_type);
    /* Bugzilla 21131 End */


    /*###############################################################################            */
    /*#misc_info("Enable test clock outputs: GPLL RX clock, MRA RX VCO clock, MRB RX VCO clock");*/
    /*###############################################################################            */
    /* Probably not needed */
    ten_mpif_rxclk_refout (dev_id, 0x7, 0x4);

    /*cs_status ten_mpif_set_lvds_pd(cs_uint16 dev_id, cs_uint16 select, cs_uint16 value)*/
    ten_reg_write(dev_id,0x0006b,0x000f);  /* Power down all OHPP LVDS otuput buffers */
    ten_reg_write(dev_id,0x01082,0x0237);  /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
    ten_reg_write(dev_id,0x02082,0x0237);  /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
    ten_reg_write(dev_id,0x0108a,0x002c);  /* Receive spare control bits for SERDES analog front end */
    ten_reg_write(dev_id,0x0208a,0x002c);  /* Receive spare control bits for SERDES analog front end */


    /*############################################################*/
    /*#   Configure Client side RX N40G                           */
    /*############################################################*/
    ten_hl_n40g_rx_init (mod_client, TEN_N40G_RX_OTU3_ODU3_LS);

    /* Bugzilla 21131 Start */
    ten_hl_40g_otu3_rx_termination (mod_client, term_otu);

    /* Set expected Payload Type (PT) to match tester - 03 - sync , 02 - async */
    ten_n40g_set_expected_pti_byte(mod_client, payload_type);
    /* Bugzilla 21131 End */
    
    /*############################################################*/
    /*#   Configure Client side TX N40G                           */
    /*############################################################*/
    ten_hl_n40g_tx_init (mod_client, TEN_N40G_TX_ODU3_OTU3_SL);

    /* Bugzilla 21131 Start */
    ten_hl_40g_otu3_tx_termination (mod_client, term_otu, client_tcm_bits);

    /* Set Payload Type Insertion (PTI) value to what the tester expects - 03 sync, 02 - async */
    ten_n40g_set_pti_byte(mod_client, payload_type);
    /* Bugzilla 21131 End */


    if (sync_mode == 1) {
      /* Disable Justification in syncronous mode */
      /*jc_enabled = 0;   */
    } else {
      jc_enabled = 1;
      num_pjo = 1;
      jc_plus = 0;
      ten_n40g_otnt4x_set_wrpcfg4(mod_line, jc_plus, jc_enabled);  /* Enable wrapper to generate justification commands.   Enable enhanced justification */
      ten_n40g_otnr4x_set_jc_enable(mod_line, jc_enabled);   /* Enable justification commands to be evaluated in de-wrapping. */
      ten_n40g_otnr4x_set_jc_plus(mod_line, jc_plus);     /* Provision enhanced justification. */

      ten_n40g_otnt4x_set_wrpcfg4(mod_client, jc_plus, jc_enabled);  /* Enable wrapper to generate justification commands.   Enable enhanced justification */
      ten_n40g_otnr4x_set_jc_enable(mod_client, jc_enabled);   /* Enable justification commands to be evaluated in de-wrapping. */
      ten_n40g_otnr4x_set_jc_plus(mod_client, jc_plus);     /* Provision enhanced justification. */
    }
    /* Bugzilla 21131 Code Removed */
  }

  /* Bugzilla 24940 Start */
  else if ((line == TEN_TRAFFIC_TYPE_OTU3P) && (client == TEN_TRAFFIC_TYPE_OTU3)){
      ncols_line = 254;
      npar_line = 16;
      stm256md  = 0;
      stm64md = 0;
      num_cortina_em_fs = 468;

    /*############################################################*/
    /*#   Configure Line side TX N40G                             */
    /*############################################################*/
    /*ten_hl_n40g_tx_init (mod_line, TEN_N40G_TX_ODU3_OTU3_SL);*/
    ten_hl_n40g_tx_init (mod_line, TEN_N40G_TX_ODTU2_OTU3P);
    
    ten_hl_40g_otu3_tx_termination (mod_line, term_otu, line_tcm_bits);

    /* Set Payload Type Insertion (PTI) value to what the tester expects - 03 sync, 02 - async */
    ten_n40g_set_pti_byte(mod_line, payload_type);

    /* Configure fixed stuff bytes on TX for Cortina enhances mapping */
    ten_n40g_otnt4x_set_wrpfs0(mod_line, num_cortina_em_fs);     

    /* Monolithic wrapping - single client */
    ten_n40g_otnt4x_set_wrapper_aggrmod(mod_line, 0);


    /*############################################################*/
    /*#   Configure Line side RX N40G                             */
    /*############################################################*/
    /*ten_hl_n40g_rx_init (mod_line, TEN_N40G_RX_OTU3_ODU3_LS);*/
    ten_hl_n40g_rx_init (mod_line, TEN_N40G_RX_OTU3_ODTU23P);

    ten_hl_40g_otu3_rx_termination (mod_line, term_otu);

    /* Set expected Payload Type (PT) to match tester - 03 - sync , 02 - async */
    ten_n40g_set_expected_pti_byte(mod_line, payload_type);

    /* Configure fixed stuff bytes on RX for Cortina enhances mapping */
    ten_n40g_otnr4x_set_odwfs(mod_line, num_cortina_em_fs, 0);

    /* Single full-rate payload de-wrapped */
    ten_n40g_otnr4x_set_aggrmod(mod_line, 0); 

    /* data is passed through dewrapper unmodified. */
    ten_n40g_otnr4x_set_dw_enable(mod_line, 0);

    /* Generic Split mode. */
    tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, mod_line, DPCFG0));
    tmp_n40g_gblr4x_dpcfg0.bf.BYPCFG = 1;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, mod_line, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);


    /*###############################################################################            */
    /*#misc_info("Enable test clock outputs: GPLL RX clock, MRA RX VCO clock, MRB RX VCO clock");*/
    /*###############################################################################            */
    /* Probably not needed */
    ten_mpif_rxclk_refout (dev_id, 0x7, 0x4);

    /*cs_status ten_mpif_set_lvds_pd(cs_uint16 dev_id, cs_uint16 select, cs_uint16 value)*/
    ten_reg_write(dev_id,0x0006b,0x000f);  /* Power down all OHPP LVDS otuput buffers */
    ten_reg_write(dev_id,0x01082,0x0237);  /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
    ten_reg_write(dev_id,0x02082,0x0237);  /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
    ten_reg_write(dev_id,0x0108a,0x002c);  /* Receive spare control bits for SERDES analog front end */
    ten_reg_write(dev_id,0x0208a,0x002c);  /* Receive spare control bits for SERDES analog front end */


    /*############################################################*/
    /*#   Configure Client side RX N40G                           */
    /*############################################################*/
    ten_hl_n40g_rx_init (mod_client, TEN_N40G_RX_OTU3_ODU3_LS); /* Long to Short  OTU->ODU */

    ten_hl_40g_otu3_rx_termination (mod_client, term_otu);

    /* Set expected Payload Type (PT) to match tester - 03 - sync , 02 - async */
    ten_n40g_set_expected_pti_byte(mod_client, payload_type);
    
    /*############################################################*/
    /*#   Configure Client side TX N40G                           */
    /*############################################################*/
    ten_hl_n40g_tx_init (mod_client, TEN_N40G_TX_ODU3_OTU3_SL); /* Short to Long  ODU->OTU */

    ten_hl_40g_otu3_tx_termination (mod_client, term_otu, client_tcm_bits);

    /* Set Payload Type Insertion (PTI) value to what the tester expects - 03 sync, 02 - async */
    ten_n40g_set_pti_byte(mod_client, payload_type);


      jc_enabled = 1;
      num_pjo = 1;
      jc_plus = 0;
      ten_n40g_otnt4x_set_wrpcfg4(mod_line, jc_plus, jc_enabled);  /* Enable wrapper to generate justification commands.   Enable enhanced justification */
      ten_n40g_otnr4x_set_jc_enable(mod_line, jc_enabled);   /* Enable justification commands to be evaluated in de-wrapping. */
      ten_n40g_otnr4x_set_jc_plus(mod_line, jc_plus);     /* Provision enhanced justification. */

      ten_n40g_otnt4x_set_wrpcfg4(mod_client, jc_plus, jc_enabled);  /* Enable wrapper to generate justification commands.   Enable enhanced justification */
      ten_n40g_otnr4x_set_jc_enable(mod_client, jc_enabled);   /* Enable justification commands to be evaluated in de-wrapping. */
      ten_n40g_otnr4x_set_jc_plus(mod_client, jc_plus);     /* Provision enhanced justification. */

  }
  /* Bugzilla 24940 End */


  else {  /* otu3 and cbr client    otu3e-40gelan */
    /* Bugzilla 21131 Code Removed */
    if ((line == TEN_TRAFFIC_TYPE_OTU3E) && (client == TEN_TRAFFIC_TYPE_40GELAN)) {
      /*'40gelan_otu3e'    => [ 3, 128, -1 ],    40GE */
      ncols_line = 254;
      npar_line = 16;
      stm256md  = 1;
      stm64md = 0;
      num_cortina_em_fs = 0;
      num_pjo = 3;
      jc_plus = 1;
      jc_enabled = 1;
      c15 = 1;

    } else {
      /*'cbr40g50188149150_otu3e3' => [ 4, 0, 0 ],    */
      ncols_line = 262;
      npar_line = 19;
      stm256md  = 0;
      stm64md = 0;
      num_cortina_em_fs = 0;
      num_pjo = 4;
      jc_plus = 1;
      jc_enabled = 1;
      c15 = 0;
    }

    ncols_client = 238;
    npar_client = 0;
    
/*CS_PRINT("ncols_line = ncols_line, npar_line = npar_line\n");*/
/*CS_PRINT("ncols_client = ncols_client, npar_client = npar_client\n");*/

/*CS_PRINT ("stm256md = stm256md, stm64md = stm64md, num_cortina_em_fs = num_cortina_em_fs, num_c15 = num_c15, c15 = c15, \n");*/
/*CS_PRINT ("num_pjo = num_pjo, jc_plus = jc_plus, jc_enabled = jc_enabled\n");*/

    /*############################################################*/
    /*#   Configure Line side TX N40G                             */
    /*############################################################*/
    /* Configure 40g TX data path for OTU framing of data straight from the cross connect (Skip OC768)  (KPGBY, SBY, OBY, MDPCFG) */
    ten_n40g_gblt4x_set_cfg (mod_line, 1, 1, 0, 0);

    /* Configure STM256, STM64, Aggregation mode Monolithic and Wrapper mode ON  (WRPCFG3: STM256MD, STM64MD, AGGRMOD, WRMD) */
    ten_n40g_otnt4x_set_wrpcfg3 (mod_line, stm256md, stm64md, 0, 1);

    /* Configure fixed stuff bytes on TX for Cortina enhances mapping */
    ten_n40g_otnt4x_set_wrpfs0(mod_line, num_cortina_em_fs);     

    /* Insert FAS pattern of 0xF6F6F6282828 hex row 1, columns 1 through 6   (FASIE) */
    ten_n40g_otnt4x_set_fasie (mod_line, 1);

    /* Enable BIP */
    /*tenabo_bf_write(DEV_ID, TEN_N40G_OTNT4X_CFG4+TEN_N40G_STRIDE * ch, 0xFF, 7, 0);*/
    ten_n40g_otnt4x_bipmsk (mod_line, 0xFF);

    /* Bugzilla 21131 Start */
    /* Set PTI value to what the tester expects - 03 sync, 02 - async */
    ten_n40g_set_pti_byte (mod_line, payload_type);
    /* Bugzilla 21131 End */
                                   
    /* Enable PTIE */
    /*tenabo_bf_write(DEV_ID, TEN_N40G_OTNT4X_CFG0+TEN_N40G_STRIDE * ch, 1, 2, 2); */
    ten_n40g_otnt4x_set_ptie (mod_line, 1);


    /*############################################################*/
    /*#   Configure Line side RX N40G                             */
    /*############################################################*/
    /* Configure 40g RX data path for OTU framing of data straight to the cross connect (Skip OC768)  KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
    ten_n40g_gblr4x_set_dpcfg0 (mod_line, 1, 1, 0, 1, 0, 1);

    /* Configure STM256, STM64, Aggregation mode Monolithic and Dewrapper mode ON (DW_CONFIG: FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE) */
    ten_n40g_otnr4x_set_odwcfg (mod_line, 1, stm64md, stm256md, 0, 1); 

    /* Configure fixed stuff bytes on RX for Cortina enhances mapping */
    ten_n40g_otnr4x_set_odwfs(mod_line, num_cortina_em_fs, 0);


    /* JAM - lab findings (in addition to predescrambling) */
    /* Bugzilla 21131 Start */
    /* Set expected PTI to match tester - 03 - sync , 02 - async */
    ten_n40g_set_expected_pti_byte (mod_line, payload_type);
    /* Bugzilla 21131 End */


    /* Enable enhanced justification */
    ten_n40g_otnr4x_set_jc_enable(mod_line, jc_enabled);   /* Enable justification commands to be evaluated in de-wrapping. */
    ten_n40g_otnr4x_set_jc_plus(mod_line, jc_plus);     /* Provision enhanced justification. */
    ten_n40g_otnt4x_set_wrpcfg4(mod_line, 1, 1);  /* Enable wrapper to generate justification commands.   Enable enhanced justification */

    /* Bugzilla 21131 Code Removed */

    /* Enable one col15 byte as payload to make up for extra PJO */
    ten_n40g_otnt4x_set_c15res_en0 (mod_line, c15);
    ten_n40g_otnr4x_set_c15res_en0 (mod_line, c15);

    /* Provision STM256 mode for Lines TX and RX */
    /* Configure STM256, STM64, Aggregation mode Monolithic and Wrapper mode ON  (WRPCFG3: STM256MD, STM64MD, AGGRMOD, WRMD) */
    ten_n40g_otnt4x_set_wrpcfg3 (mod_line, stm256md, stm64md, 0, 1);

    /* Configure STM256, STM64, Aggregation mode Monolithic and Dewrapper mode ON (DW_CONFIG: FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE) */
    ten_n40g_otnr4x_set_odwcfg (mod_line, 0, stm64md, stm256md, 0, 1); 

    /* Bugzilla 21131 Code Removed */

    /* Set stat field of PM overhead to default value of 001 */
    ten_ohpp_sfu_set_doaien (mod_line , 1);
    ten_ohpp_set_doi_ram_byte (mod_line ,0,43,0x01);
    ten_n40g_otnt4x_doaie (mod_line ,43,1);
    ten_n40g_otnt4x_mfmcfg (mod_line ,1,0x0000,0x0000);


    ten_n40g_otnr4x_set_ncols (mod_line, ncols_line); 
    ten_n40g_otnr4x_set_nparb_npar (mod_line, 0, npar_line); 
    ten_n40g_otnt4x_set_ncols (mod_line, ncols_line);
    ten_n40g_otnt4x_set_nparb_npar (mod_line, 0, npar_line);


    /* Done in ten_hl_config_global ()??? */
    /* Enable LVDS PAD for DIV clock */
    /*#ten_reg_write(DEV_ID,TEN_MPIF_LVDS_DIV_PD,0);*/
    /*ten_mpif_set_lvds_div_pd(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX_AND_RX, 0); */

    /* Bugzilla 24750 Start */
    ten_hl_n40g_otn_aligner_settings (mod_line);
    /* Bugzilla 24750 End */


    /*###############################################################################            */
    /*#misc_info("Enable test clock outputs: GPLL RX clock, MRA RX VCO clock, MRB RX VCO clock");*/
    /*###############################################################################            */
    /* Probably not needed */
    /*cs_status ten_mpif_rxclk_refout(cs_uint16 dev_id, cs_uint16 div, cs_uint16 select) */
    ten_mpif_rxclk_refout (dev_id, 0x7, 0x4);

    /*cs_status ten_mpif_set_lvds_pd(cs_uint16 dev_id, cs_uint16 select, cs_uint16 value) */
    ten_reg_write(dev_id,0x0006b,0x000f);  /* Power down all OHPP LVDS otuput buffers */
    ten_reg_write(dev_id,0x01082,0x0237);  /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
    ten_reg_write(dev_id,0x02082,0x0237);  /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
    ten_reg_write(dev_id,0x0108a,0x002c);  /* Receive spare control bits for SERDES analog front end */
    ten_reg_write(dev_id,0x0208a,0x002c);  /* Receive spare control bits for SERDES analog front end */



    /*############################################################*/
    /*#   Configure Client side RX N40G                           */
    /*############################################################*/
    /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
    ten_n40g_gblr4x_set_dpcfg0 (mod_client, 1, 1, 0, 1, 1, 1);
  
    /* Turn the OTN aligner off */
    /*tenabo_bf_write(DEV_ID, TEN_N40G_OTNR4X_OACFG0 + (TEN_N40G_STRIDE * module_id), 0, 0, 0);*/
    ten_n40g_otnr4x_alen (mod_client, 0);

    /* Set NCOLS to 239 and NPAR to 0 */
    ten_n40g_otnr4x_set_ncols (mod_client, ncols_client); 
    ten_n40g_otnr4x_set_nparb_npar (mod_client, 0, npar_client); 
    ten_n40g_otnt4x_set_ncols (mod_client, ncols_client);
    ten_n40g_otnt4x_set_nparb_npar (mod_client, 0, npar_client);

  
  
    /*############################################################*/
    /*#   Configure Client side TX N40G                           */
    /*############################################################*/
    /* Configure 40g TX data   (KPGBY, SBY, OBY, MDPCFG) */
    ten_n40g_gblt4x_set_cfg (mod_client, 1, 1, 1, 0);

    /* WRMD */
    ten_n40g_otnt4x_set_wrapper_onoff (mod_client, 0);
       
    /* Disable all N10G OTN wrapping */
    ten_n10g_otnt_set_wrmd (mod_client, TEN_SLICE_ALL, 0);
  
  }

  /* Provision Data Cross connect for straight accross for 40G Monolithic */
  ten_hl_xcon_config (dev_id, 0, 4, TEN_TRAFFIC_TYPE_OTU2);
  ten_hl_xcon_config (dev_id, 1, 5, TEN_TRAFFIC_TYPE_OTU2);
  ten_hl_xcon_config (dev_id, 2, 6, TEN_TRAFFIC_TYPE_OTU2);
  ten_hl_xcon_config (dev_id, 3, 7, TEN_TRAFFIC_TYPE_OTU2);
  
  ten_hl_xcon_config (dev_id, 4, 0, TEN_TRAFFIC_TYPE_OTU2);
  ten_hl_xcon_config (dev_id, 5, 1, TEN_TRAFFIC_TYPE_OTU2);
  ten_hl_xcon_config (dev_id, 6, 2, TEN_TRAFFIC_TYPE_OTU2);
  ten_hl_xcon_config (dev_id, 7, 3, TEN_TRAFFIC_TYPE_OTU2);

  /* Provision the Sadeco */
  if ((client == TEN_TRAFFIC_TYPE_OC768) && (term_sonet != TEN_OC192_TERM_TRANSPARENT_CBR10)) {
    /* Configure the SADECO delay and compensation for Sonet SDH interleaving */
    ten_xcon_sadeco_config (dev_id, mod_client, 0x200, 0x1F00, XCON_SONET_SDH_64);
    ten_xcon_sadeco_config (dev_id, mod_line  , 0x200, 0x1F00, XCON_SONET_SDH_64);

    /* Provision Skew and Delay Compensation Sonet Frame Length. */
    ten_xcon_sadeco_sdclen (dev_id, mod_client, 0x97E0);    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */
    ten_xcon_sadeco_sdclen (dev_id, mod_line,   0x97E0);    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */      
  }
  /* Bugzilla 24940 Start */
  /*else if ((client == TEN_TRAFFIC_TYPE_OTU3) && (line == TEN_TRAFFIC_TYPE_OTU3)) {*/
  else if (((client == TEN_TRAFFIC_TYPE_OTU3) && (line == TEN_TRAFFIC_TYPE_OTU3)) ||
           ((client == TEN_TRAFFIC_TYPE_OTU3) && (line == TEN_TRAFFIC_TYPE_OTU3P))) {
  /* Bugzilla 24940 End */
    /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
    ten_xcon_sadeco_config (dev_id, mod_client, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
    ten_xcon_sadeco_config (dev_id, mod_line  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

    /* Bugzilla 21131 Start */
    /* Provision Skew and Delay Compensation Frame Length. */
    if (term_otu == TEN_OTU_TERM_FULL) {
      ten_xcon_sadeco_sdclen (dev_id, mod_client, 0x3B0);    /* [255 columns - 16(FEC) - 2(FS) - 1(OH)]  * 4 */ 
      ten_xcon_sadeco_sdclen (dev_id, mod_line,   0x3B0);    /* [255 columns - 16(FEC) - 2(FS) - 1(OH)]  * 4 */      
    } else {
      ten_xcon_sadeco_sdclen (dev_id, mod_client, 0x3BC);    /* [255 columns - 16(FEC)]  * 4 */ 
      ten_xcon_sadeco_sdclen (dev_id, mod_line,   0x3BC);    /* [255 columns - 16(FEC)]  * 4 */      
    }  
    /* Bugzilla 21131 End */
  }
  else {
    /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
    ten_xcon_sadeco_config (dev_id, mod_client, 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);
    ten_xcon_sadeco_config (dev_id, mod_line  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

    /* Provision Skew and Delay Compensation Frame Length. */
    /*ten_xcon_sadeco_sdclen (dev_id, mod_client, 0x3B0); */   /* [255 columns - 16(FEC) - 1(OH) - 2(FS)]  * 4 */
    /*ten_xcon_sadeco_sdclen (dev_id, mod_line,   0x3BC); */   /* [255 columns - 16(FEC)] * 4 */      
    ten_xcon_sadeco_sdclen (dev_id, mod_client, (ncols_line - npar_line - (stm256md * 2) - stm64md) * 4);    /* [255 columns - 16(FEC) - 1(OH) - 2(FS)]  * 4 */
    ten_xcon_sadeco_sdclen (dev_id, mod_line, (ncols_client + 1) * 4);    /* [255 columns - 16(FEC)] * 4 */
  }
  /* Select incoming reference and tributary streams */
  ten_xcon_sadeco_sel_data_stream (dev_id, mod_client, 0x0F, 0x1F);
  ten_xcon_sadeco_sel_data_stream (dev_id, mod_line  , 0x0F, 0x1F);
  
  /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
  ten_xcon_sadeco_enable_fp (dev_id, mod_client, CS_ENABLE);
  ten_xcon_sadeco_enable_fp (dev_id, mod_line  , CS_ENABLE);

  return (CS_OK);
}

/* Bugzilla 22514 Start */
/****************************************************************/
/* $rtn_hdr_start  CONFIG OTN 40G CROSS CONNECT LOOPBACK        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3_xcon_loopback(cs_uint16 module_id,
                                           cs_uint16 traffic_type,
                                           cs_uint16 dyn_repro,
                                           cs_uint16 sync_mode,
                                           cs_uint16 term_otu,
                                           cs_uint16 tcm_bits)

/* INPUTS     : o Module Id                                     */
/*              o Traffic type                                  */
/*              o Dynamic Reprovision                           */
/*              o Sync Mode                                     */
/*              o Term OTU                                      */
/*              o TCM bits                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures an N40G transmit/receive path.                    */
/*                                                              */
/* [module_id] specifies line's module ID                       */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* The [traffic_type] parameters are specified as:              */
/*   TEN_TRAFFIC_TYPE_OTU3               = 1                    */
/*   TEN_TRAFFIC_TYPE_OTU3E              = 2                    */
/*   TEN_TRAFFIC_TYPE_OTU3P              = 3                    */
/*   TEN_TRAFFIC_TYPE_OTU3E3             = 23                   */
/*   TEN_TRAFFIC_TYPE_OTU3P2             = 25                   */
/*                                                              */
/* The [dyn_repro] parameter is specified as:                   */
/*  TEN_INITIAL_CONFIG (full)            = 0,                   */
/*  TEN_REPRO_CLIENT   (dynamic)         = 1,                   */
/*  TEN_REPRO_LINE_AND_CLIENT (dynamic)  = 2,                   */
/*                                                              */
/* The [sync_mode] parameter specifies the clock sync method    */
/*   0 = TEN_MAP_AMP                                            */
/*   1 = TEN_MAP_BMP                                            */
/*                                                              */
/* The [term_otu] parameter specifies the otu3 to otu3          */
/* termination and is specified as:                             */
/*   TEN_OTU_TERM_TRANSPARENT = 0x0000,                         */
/*   TEN_OTU_TERM_SECTION     = 0x0001,                         */
/*                                                              */
/* The [tcm_bits] parameters                                    */
/* specifies the termination for TCM 1 through 6.               */
/* This is a bit encoded parameter with bits 1 through 6        */
/* specifying TCM 1 through 6 respectively.                     */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* Bugzilla 23776 Start */
  cs_uint16 dev_id;
  cs_uint16 payload_type;
  cs_uint16 i;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_config_otu3_xcon_loopback";  

  cs_module_t module = ((module_id & 1) == 0) ? TEN_MODULE_A : TEN_MODULE_B;
 /*  cs_uint16 port   =  (module_id & 1) * 4; */

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);
  
  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }
   
  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E) && 
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3P) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E3) &&  
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3P2)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 1, 2, 3, 23, 25.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (sync_mode > TEN_MAP_BMP) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() sync_mode %d > TEN_MAP_BMP out of range.  s/b 0..1.", func, sync_mode);
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
  
  CS_PRINT("%s() %s, %s, %s, %s, tcm = 0x%X\n",
           func,
           ten_module_strings[module_id & 1],
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_hl_config_otu_overhead_term_strings[term_otu],
           tcm_bits);
  /* Bugzilla 23776 End */
  
  /* Bugzilla 26130 Start */
  /* Selects the datapath source to be the single 40G RX clock */
  ten_mpif_clock_select_40g_per_module (dev_id, module_id & 1, 1, 1);
  /* Provision  the 40G block bypass */
  ten_mpif_global_cfg_per_module (dev_id, module_id & 1, 0, 0); 
  /* Bugzilla 26130 End */
  
  payload_type = TEN_PAYLOAD_TYPE_SYNC_CBR;

  /* apply ring_oscillator fix */
  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, port + 1);  */ /* Bugzilla #24261 */
  
  
  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  ten_hsif_clk_40g (module_id,   1, 0, 1, 0);
  
  
  /* Do not know if this is being done correctly in ten_hl_xcon_cfg(cs_uint16 dev_id, cs_uint8 slice, cs_uint8 mode) */
  for (i=0; i<8; i++) {
    ten_xcon_select_es_packet_centering (dev_id, i, XCON_PKT_CENTERING_ALL, CS_DISABLE);
    ten_xcon_set_circuit_thresholds (dev_id, i, XCON_ES_IML_THRESH, 0x1000);
  }

  /* Enable the N10G and configure it for bypass */
  ten_hl_n10g_config (module_id, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, dyn_repro);

  /* Enable clock */
  ten_mpif_global_clock_disable_n40g (dev_id, module, CS_TX_AND_RX, CS_ENABLE);      
  /* Remove hard reset from the top */
  ten_mpif_global_reset_n40g (dev_id, module, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  ten_reg_write (dev_id,TEN_N40G_OTNT4X_WRPCFG1 + ((module_id & 1) * TEN_N40G_STRIDE), 0);

  /* Bugzilla 23777 Start */
  /*############################################################*/
  /*#   Configure Line side TX N40G                             */
  /*############################################################*/
  ten_hl_n40g_tx_init (module_id, TEN_N40G_TX_ODU3_OTU3_SL);

  ten_hl_40g_otu3_tx_termination (module_id, term_otu, tcm_bits);

  /* Set Payload Type Insertion (PTI) value to what the tester expects - 03 sync, 02 - async */
  ten_n40g_set_pti_byte(module_id, payload_type);


  /*############################################################*/
  /*#   Configure Line side RX N40G                             */
  /*############################################################*/
  ten_hl_n40g_rx_init (module_id, TEN_N40G_RX_OTU3_ODU3_LS);

  ten_hl_40g_otu3_rx_termination (module_id, term_otu);

  /* Set expected Payload Type (PT) to match tester - 03 - sync , 02 - async */
  ten_n40g_set_expected_pti_byte(module_id, payload_type);


  /*###############################################################################             */
  /*# misc_info("Enable test clock outputs: GPLL RX clock, MRA RX VCO clock, MRB RX VCO clock");*/
  /*###############################################################################             */
  /* Set the RX Clock Reference Output Configuration (Probably not needed) */
  ten_mpif_rxclk_refout (dev_id, 0x7, 0x4);  /* Divide by 1, RX Module A GPLL #4 output clock */

  /*cs_status ten_mpif_set_lvds_pd(cs_uint16 dev_id, cs_uint16 select, cs_uint16 value)*/
  ten_reg_write (dev_id, 0x0006b, 0x000f);  /* Power down all OHPP LVDS otuput buffers */
  ten_reg_write (dev_id, 0x01082, 0x0237);  /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
  ten_reg_write (dev_id, 0x02082, 0x0237);  /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
  ten_reg_write (dev_id, 0x0108a, 0x002c);  /* Receive spare control bits for SERDES analog front end */
  ten_reg_write (dev_id, 0x0208a, 0x002c);  /* Receive spare control bits for SERDES analog front end */

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
  
  /* Configure the SADECO delay and compensation for non Sonet SDH interleaving */
  ten_xcon_sadeco_config (dev_id, module_id  , 0x200, 0x1F00, XCON_SONET_SDH_INACTIVE);

  /* Provision Skew and Delay Compensation Frame Length. */
  if (term_otu == TEN_OTU_TERM_FULL) {
    ten_xcon_sadeco_sdclen (dev_id, module_id,   0x3B0);    /* [255 columns - 16(FEC) - 2(FS) - 1(OH)]  * 4 */      
  } else {
    ten_xcon_sadeco_sdclen (dev_id, module_id,   0x3BC);    /* [255 columns - 16(FEC)]  * 4 */      
  }  
  
  /* Bugzilla 23777 End */
  /* Select incoming reference and tributary streams */
  ten_xcon_sadeco_sel_data_stream (dev_id, module_id  , 0x0F, 0x1F);
  
  /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
  ten_xcon_sadeco_enable_fp (dev_id, module_id  , CS_ENABLE);

  return (CS_OK);
}
/* Bugzilla 22514 End */

/* Bugzilla 22514 Start */
/****************************************************************/
/* $rtn_hdr_start  CONFIG OTN 40G CROSS CONNECT LOOPBACK        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc768_xcon_loopback(cs_uint16 module_id,
                                            cs_uint16 traffic_type,
                                            cs_uint16 term_sonet)

/* INPUTS     : o Module Id                                     */
/*              o Traffic type                                  */
/*              o Term Sonet                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures an N40G transmit/receive path.                    */
/*                                                              */
/* [module_id] specifies line's module ID                       */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* The [traffic_type] parameters are specified as:              */
/*   TEN_TRAFFIC_TYPE_OC768                 = 22,               */
/*                                                              */
/* [term_sonet] defines the way the OC768 will be sinked and    */
/* sourced                                                      */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2,                */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3,                */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 i;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_config_oc768_xcon_loopback";  
  cs_module_t module = ((module_id & 1) == 0) ? TEN_MODULE_A : TEN_MODULE_B;
  /* cs_uint16 port   =  (module_id & 1) * 4; */

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);
  
  if (traffic_type != TEN_TRAFFIC_TYPE_OC768) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b %d.", 
                  func,traffic_type, TEN_TRAFFIC_TYPE_OC768);
    return (CS_ERROR);
  }    

  if ((term_sonet < 2) || (term_sonet > TEN_OC192_TERM_MS_LAYER_REGENERATOR)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() term_sonet %d out of range.  s/b 2..4.", func, term_sonet);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_id & 1],
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_hl_config_oc192_overhead_term_strings[term_sonet]);

  /* Bugzilla 26130 Start */
  /* Selects the datapath source to be the single 40G RX clock */
  ten_mpif_clock_select_40g_per_module (dev_id, module_id & 1, 1, 1);
  /* Provision  the 40G block bypass */
  ten_mpif_global_cfg_per_module (dev_id, module_id & 1, 0, 0); 
  /* Bugzilla 26130 End */

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, port + 1); */ /* Bugzilla #24261 */
  
  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  ten_hsif_clk_40g (module_id, 1, 0, 1, 0);  /* module_id, tx_aggr_mode, txsel, rx_aggr_mode, rxsel */
  
  
  /* Do not know if this is being done correctly in ten_hl_xcon_cfg(cs_uint16 dev_id, cs_uint8 slice, cs_uint8 mode) */
  for (i=0; i<8; i++) {
    ten_xcon_select_es_packet_centering (dev_id, i, XCON_PKT_CENTERING_ALL, CS_DISABLE);
    ten_xcon_set_circuit_thresholds (dev_id, i, XCON_ES_IML_THRESH, 0x1000);
  }

  /* Enable the N10G and configure it for bypass */
  ten_hl_n10g_config (module_id, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, TEN_INITIAL_CONFIG);

  /* Enable clock */
  ten_mpif_global_clock_disable_n40g (dev_id, module, CS_TX_AND_RX, CS_ENABLE);      
  /* Remove hard reset from the top */
  ten_mpif_global_reset_n40g (dev_id, module, CS_TX_AND_RX, CS_RESET_DEASSERT);


  /*############################################################*/
  /*#   Configure RX Side N40G                                  */
  /*############################################################*/
  /* Configure 40g RX data path for OTU framing of data straight to the OC768  (KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY) */
  ten_n40g_gblr4x_set_dpcfg0 (module_id, 0, 0, 3, 0, 1, 0);
 
  /* Disabel OTU3 dewrapper  (DW_ENABLE) */
  ten_n40g_otnr4x_set_dw_enable (module_id, 0); 
 
  /* Enable 40G SONET descrambler */
  ten_n40g_sdfr_enable_descrambler (module_id, 1 );
  /* Disable 10G SONET descrambler - descrambling done in N40G */
  /*cs_status ten_n10g_sdfr_set_scren(cs_uint16 module_id, cs_uint8 slice, cs_uint16 scren) */
  ten_n10g_sdfr_set_scren (module_id, TEN_SLICE_ALL, 0);
 
  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  ten_n10g_set_gblr_dpcfg (module_id, TEN_SLICE_ALL, 1, 0, 0, 0, 1, 0, 1);   
 
 
  /*############################################################*/
  /*#   Configure TX Sid N40G                                   */
  /*############################################################*/
  /* Configure 40g TX data   (KPGBY, SBY, OBY, MDPCFG) */
  ten_n40g_gblt4x_set_cfg (module_id, 1, 0, 1, 3);

  /* Disable OTU3 scrablers  (POSTSCR, PRESCR) */
  ten_n40g_otnt4x_scrambling (module_id, 0, 0);

  /* Turn N40G Wrapper off  (WRMD) */
  ten_n40g_otnt4x_set_wrapper_onoff (module_id, 0);

  /* Program the 40G SONET Transmit block: (b1inv, b1trans, b1ie, scren, a1a2rsh ) */
  ten_n40g_st4x_set_ohie (module_id, 0, 0, 0, 1, 0);

  /* Disable 10G Sonet scrambler */
  ten_n10g_soht_set_scren (module_id, TEN_SLICE_ALL, 0);

  /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
  ten_n10g_set_gblt_cfgtx0 (module_id, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0);
                                                                 /*pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie)*/
 
  /* Disable all N10G OTN wrapping */
  ten_n10g_otnt_set_wrmd (module_id, TEN_SLICE_ALL, 0);


  ten_hl_oc768_termination (module_id, module_id, term_sonet);
        

  /*###############################################################################             */
  /*# misc_info("Enable test clock outputs: GPLL RX clock, MRA RX VCO clock, MRB RX VCO clock");*/
  /*###############################################################################             */
  /* Set the RX Clock Reference Output Configuration (Probably not needed) */
  ten_mpif_rxclk_refout (dev_id, 0x7, 0x4);  /* Divide by 1, RX Module A GPLL #4 output clock */

  /*cs_status ten_mpif_set_lvds_pd(cs_uint16 dev_id, cs_uint16 select, cs_uint16 value)*/
  ten_reg_write (dev_id, 0x0006b, 0x000f);  /* Power down all OHPP LVDS input and output buffers */
  ten_reg_write (dev_id, 0x01082, 0x0237);  /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
  ten_reg_write (dev_id, 0x02082, 0x0237);  /* SFI5 mux clk div2 serial clock divider to tx PFD. RINGVCO is source of serial clock */
  ten_reg_write (dev_id, 0x0108a, 0x002c);  /* Receive spare control bits for SERDES analog front end */
  ten_reg_write (dev_id, 0x0208a, 0x002c);  /* Receive spare control bits for SERDES analog front end */

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
  
  /* Configure the SADECO delay and compensation for Sonet SDH interleaving */
  ten_xcon_sadeco_config (dev_id, module_id, 0x200, 0x1F00, XCON_SONET_SDH_64);

  /* Provision Skew and Delay Compensation Sonet Frame Length. */
  ten_xcon_sadeco_sdclen (dev_id, module_id,   0x97E0);    /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */      
  
  /* Select incoming reference and tributary streams */
  ten_xcon_sadeco_sel_data_stream (dev_id, module_id  , 0x0F, 0x1F);
  
  /* Switches off the frame pulses used on the read side of the elastic store.    Turn on the SADECO?? */
  ten_xcon_sadeco_enable_fp (dev_id, module_id  , CS_ENABLE);

  return (CS_OK);
}
/* Bugzilla 22514 End */

/****************************************************************/
/* $rtn_hdr_start  OC768 TERMINATION                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_oc768_termination(cs_uint16 module_id_line,
                                   cs_uint16 module_id_client,
                                   cs_uint16 term_sonet)
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
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_oc768_termination";  

  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);

  if ((term_sonet < TEN_OC192_TERM_TRANSPARENT_CBR10) || (term_sonet > TEN_OC192_TERM_MS_LAYER_REGENERATOR)) {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() term_sonet %d out of range.  s/b 1..4.", func, term_sonet);
    return (CS_ERROR);
  }

  CS_PRINT("%s()  %s, %s, %s\n",
           func, 
           ten_module_strings[module_id_line & 1],
           ten_module_strings[module_id_client & 1],
           ten_hl_config_oc192_overhead_term_strings[term_sonet]);
  /* Bugzilla 23776 End */

  
  /* Override HL provisioning */
  if (term_sonet == TEN_OC192_TERM_TRANSPARENT_CBR10) {
    /* RX Client */
    /* Configure 40g RX data path to bypass OTU and Sonet/SDH (KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY) */
    ten_n40g_gblr4x_set_dpcfg0(module_id_client, 1, 1, 0, 1, 1, 1);

    /* Configure to skip the N10G block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
    ten_n10g_set_gblr_dpcfg (module_id_client, TEN_SLICE_ALL, 0, 0, 1, 0, 1, 0, 1);   
    
    
    /* TX Line Side */
    /* Configure 40g TX data path for OTU framing and skip Sonet/SDH mapper (KPGBY, SBY, OBY, MDPCFG) */
    ten_n40g_gblt4x_set_cfg(module_id_line, 1, 1, 0, 0);

    /* Configure 10G to data path to bypass OTU and Sonet/SDH (pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie) */
    ten_n10g_set_gblt_cfgtx0 (module_id_line, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 1, 1, 0);

    
    /* RX Line Side: */
    /* Configure 40g RX data path for OTU framing and skip Sonet/SDH mapper (KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY) */
    ten_n40g_gblr4x_set_dpcfg0(module_id_line, 1, 1, 0, 1, 0, 1);

    /* Configure to skip the N10G block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
    ten_n10g_set_gblr_dpcfg (module_id_line, TEN_SLICE_ALL, 0, 0, 1, 0, 1, 0, 1);


    /* TX Client Side: */
    /* Configure 40g TX data   (KPGBY, SBY, OBY, MDPCFG) */ 
    ten_n40g_gblt4x_set_cfg(module_id_client, 1, 1, 1, 0);

    /* Configure 10G to data path to bypass OTU and Sonet/SDH (pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie) */
    ten_n10g_set_gblt_cfgtx0 (module_id_client, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 1, 1, 0);
    
    
    /* Turn the OTN aligner off */
    ten_n40g_otnr4x_alen (module_id_client, 0);
    
    /* Bugzilla 24360 Start */
    /* Set NCOLS and NPAR for frame pulse since we are doing a CBR */
    /*ten_n40g_rx_ncols_t41(module_id_client, 238); */
    /*ten_n40g_rx_npar_t41(module_id_client, 0);    */
    /* Bugzilla 24360 End */
  }

  else if (term_sonet == TEN_OC192_TERM_TRANSPARENT_REGENERATOR) {
    /* RX Client Side: */
    /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
    /* SDFR_SDFCFG.SCREN = 1 */
    /* LOS , LOF, and STM-AIS reported to OHPP */
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id_client, TEN_SLICE_ALL,
                            0,  /* b1trans  Enable insert of Calculated B1 */
                            0); /* b2trans  Disable insert of Calculated B2 */

    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_B1TRANS, 0);  /* Enable insert of Calculated B1 */              


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
    ten_n10g_soht_set_ohben0(module_id_line, TEN_SLICE_ALL,
                    0,  /* b1ie  Disable calculated B1 (BIP-8) insertion */
                    0,  /* scren  Disable SONET/SDH scrabling (Done in 40G block) */
                    /* Bugzilla 24163 Start */
                    0,  /* a1a2rsh Insert (Refresh) FAS bytes Disable (Done in 40G block) */
                    /* Bugzilla 24163 End */
                    0); /* a1a2ie   Framing timing comes from receiver */
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_B1IE, 0);     /* Disable Calculated B1 insertion */                 
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_SCREN, 1);    /* Enable SONET/SDH scrabling */                       
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_A1A2RSH, 1);  /* Enable A1 A2 insertion to refresh FAS */              
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_A1A2IE, 0);   /* Framing timing comes from receiver*/                 

    ten_n10g_soht_b2ie(module_id_line, TEN_SLICE_ALL, TEN_INSTANCE_ALL, 0); /* Disable insert of Calculated B1 */


    /* RX Line Side: */
    /* XSEL = 1, SBYFRM = 0   (Framed SONET/SDH to the XCON) */
    /* SDFR_SDFCFG.SCREN = 1 */
    /* LOF and STM-AIS reported to OHPP */
    /* OTN-layer defects reported to OHPP */
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */ 
    ten_n10g_sohr_set_byte_err_trans_mode(module_id_line, TEN_SLICE_ALL,
                            0,  /* b1trans  Enable insert of Calculated B1 */
                            0); /* b2trans  Disable insert of Calculated B2 */

    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_B1TRANS, 0);  /* Enable insert of Calculated B1 */              


    /* TX Client Side: */
    /* SBY = 0 (Do not bypass SDH Processor) */
    /* SOHT_OHBEN0 = 0x08 (A1A2RSH), SOHT_OHBEN1 = 0x00, SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion but turn on scrambling) */
    /* SFU inserts MS-AIS (AIS-L) as consequent action if LOF/STM-AIS or OTN defect detected on line RX (this must include setting SOHT_OHBEN0.B1IE=1) */
    ten_n10g_soht_set_ohben0(module_id_client, TEN_SLICE_ALL,
                    0,  /* b1ie  Disable calculated B1 (BIP-8) insertion */
                    0,  /* scren  Disable SONET/SDH scrabling (Done in 40G block) */
                    /* Bugzilla 24163 Start */
                    0,  /* a1a2rsh Insert (Refresh) FAS bytes Disable (Done in 40G block) */
                    /* Bugzilla 24163 End */
                    0); /* a1a2ie   Framing timing comes from receiver */
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_B1IE, 0);    /* Disable Calculated B1 insertion */                   
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_SCREN, 1);   /* Enable SONET/SDH scrabling */                        
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_A1A2RSH, 1); /* Enable A1 A2 insertion to refresh FAS */               
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_A1A2IE, 0);  /* Framing timing comes from receiver*/                  
                    
    ten_n10g_soht_b2ie(module_id_client, TEN_SLICE_ALL, TEN_INSTANCE_ALL, 0);  /* Disable insert of Calculated B1 */
  }

  else if (term_sonet == TEN_OC192_TERM_RS_LAYER_REGENERATOR) {
    /* Regenerator or Section overhead regeneration */

    /* RX Client Side: */
    /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
    /* SDFR_SDFCFG.SCREN = 1 */
    /* LOS , LOF, STM-AIS, RS-TIM, AIS-L defects reported to OHPP */
    /* Set SOHR_S1CFG.B1TRANS=1 */
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
    /* To enable 40G B1 transparent, slice 0, 1, 2 b1trans = 0, Slice 3 b1trans = 1 in N10G and b1trans = 1 in N40G (fizzbin) */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id_client, TEN_SLICE_ALL,
                    0,  /* b1trans  Enable insert of Calculated B1 */
                    0); /* b2trans  Enable insert of Calculated B2 */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id_client, 3,
                    1,  /* b1trans  Enable insert of Calculated B1 */
                    0); /* b2trans  Enable insert of Calculated B2 */
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_B1TRANS, 1);  /* Enable insert of Calculated B1 */              


    /* TX Line Side (Mapping): */
    /* SBY = 0 (Do not bypass SONET/SDH processing) */
    /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1 */
    /* In SOHT, enable RSOH bytes that are to be sourced  */
    /* (others will be transparently passed through) */
    /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
    /* SFU inserts MS-AIS (AIS-L) as consequent action if */
    /* LOS/LOF/STM-AIS/MS-AIS or optionally RS-TIM  detected on client RX */
    /* B1IE needs to change */
    ten_n10g_soht_set_ohben0(module_id_line, TEN_SLICE_ALL,
                    0,  /* b1ie  Enable calculated B1 (BIP-8) insertion (Done in 40G block)*/
                    0,  /* scren  Disable SONET/SDH scrabling (Done in 40G block) */
                    /* Bugzilla 24163 Start */
                    0,  /* a1a2rsh Insert (Refresh) FAS bytes Disable (Done in 40G block) */
                    /* Bugzilla 24163 End */
                    0); /* a1a2ie   Framing timing comes from receiver */

    /* N40G_ST4X_OHIE */
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_B1IE, 1);    /* Enable Calculated B1 insertion */                   
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_SCREN, 1);   /* Enable SONET/SDH scrabling */                        
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_A1A2RSH, 1); /* Enable A1 A2 insertion to refresh FAS */               
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_A1A2IE, 0);  /* Framing timing comes from receiver*/                  
                    
    ten_n10g_soht_b2ie(module_id_line, TEN_SLICE_ALL, TEN_INSTANCE_ALL, 0);  /* Disable insert of all Calculated B2s */

                    
    /* RX Line Side (Demapping): */
    /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
    /* SDFR_SDFCFG.SCREN = 1 */
    /* LOF, STM-AIS, RS-TIM, AIS-L defects reported to OHPP */
    /* OTN-layer defects reported to OHPP */
    /* Set SOHR_S1CFG.B1TRANS=1 */
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
    /* To enable 40G B1 transparent, slice 0, 1, 2 b1trans = 0, Slice 3 b1trans = 1 in N10G and b1trans = 1 in N40G */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id_line, TEN_SLICE_ALL,
                    0,  /* b1trans  Insert Calculated B1 */
                    0); /* b2trans  Insert Calculated B2 */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id_line, 3,
                    1,  /* b1trans  Insert Calculated B1 */
                    0); /* b2trans  Insert Calculated B2 */
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_B1TRANS, 1);  /* Enable insert of Calculated B1 */              


    /* TX Client Side: */
    /* SBY = 0 (Do not bypass SDH Processor) */
    /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1 */
    /* In SOHT, enable RSOH bytes that are to be sourced  */
    /*(others will be transparently passed through) */
    /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
    /* SFU inserts MS-AIS (AIS-L) as consequent action if */
    /* LOF/STM-AIS/MS-AIS or optionally RS-TIM or OTN defect detected on line RX */
    ten_n10g_soht_set_ohben0(module_id_client, TEN_SLICE_ALL,
                    0,  /* b1ie  Enable calculated B1 (BIP-8) insertion (Done in 40G block) */   
                    0,  /* scren  Disable SONET/SDH scrabling (Done in 40G block) */
                    /* Bugzilla 24163 Start */
                    0,  /* a1a2rsh Insert (Refresh) FAS bytes Disable (Done in 40G block) */
                    /* Bugzilla 24163 End */
                    0); /* a1a2ie   Framing timing comes from receiver */

    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_B1IE, 1);    /* Enable Calculated B1 insertion */                   
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_SCREN, 1);   /* Enable SONET/SDH scrabling */                        
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_A1A2RSH, 1); /* Enable A1 A2 insertion to refresh FAS */               
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_A1A2IE, 0);  /* Framing timing comes from receiver*/                  

    ten_n10g_soht_b2ie(module_id_client, TEN_SLICE_ALL, TEN_INSTANCE_ALL, 0); /* Disable insert of Calculated B2 */
  }

  else if (term_sonet == TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
    /* Multiplex or Line overhead regeneration */

    /* RX Client Side: */
    /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
    /* SDFR_SDFCFG.SCREN = 1 */
    /* LOS , LOF, STM-AIS, RS-TIM, AIS-L, dEXC, dLOP, AU-AIS  */
    /* defects reported to OHPP */
    /* Set SOHR_S1CFG.B1TRANS=1 */
    /* Set SOHR_S1CFG.B2TRANS=1 */
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
    /* To enable 40G B1 transparent, slice 0, 1, 2 b1trans = 0, Slice 3 b1trans = 1 in N10G and b1trans = 1 in N40G */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id_client, TEN_SLICE_ALL,
                    0,  /* b1trans  Enable insert of Calculated B1 */
                    1); /* b2trans  Enable insert of Calculated B2 */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id_client, 3,
                    1,  /* b1trans  Enable insert of Calculated B1 */
                    1); /* b2trans  Enable insert of Calculated B2 */

    /* N40G_ST4X_OHIE */
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_B1TRANS, 1); /* Enable insert of Calculated B1 */               

                    
    /* TX Line Side (Mapping): */
    /* SBY = 0 (Do not bypass SONET/SDH processing) */
    /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1, B2IE=1 */
    /* In SOHT, enable RSOH/MSOH bytes that are to be sourced  */
    /* (others will be transparently passed through) */
    /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
    /* If B2 error transparency is desired, set B2TRANS=1 in SOHT_OHBEN1 */
    /* SFU inserts MS-RDI (RDI-L) as consequent action if */
    /* LOF/MS-AIS detected on line RX */
    /* SFU inserts MS-REI (REI-L) based on number of B2 errors */
    /* detected on line RX */
    /* SFU inserts MS-AIS (AIS-L) as consequent action  */
    /* if LOS/LOF/STM-AIS/MS-AIS or optionally RS-TIM/dEXC  detected on client RX */
    /* Optionally insert AU-AIS as consequent action  */
    /* if dLOP/AU-AIS detected on client RX */
    ten_n10g_soht_set_ohben0(module_id_line, TEN_SLICE_ALL,
                    0,  /* b1ie  Enable calculated B1 (BIP-8) insertion (Done in 40G block) */  
                    0,  /* scren  Disable SONET/SDH scrabling (Done in 40G block) */
                    /* Bugzilla 24163 Start */
                    0,  /* a1a2rsh Insert (Refresh) FAS bytes Disable (Done in 40G block) */
                    /* Bugzilla 24163 End */
                    0); /* a1a2ie   Framing timing comes from receiver*/
                    
    /* N40G_ST4X_OHIE */
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_B1IE, 1);    /* Enable Calculated B1 insertion */             
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_SCREN, 1);   /* Enable SONET/SDH scrabling */              
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_A1A2RSH, 1); /* Enable A1 A2 insertion to refresh FAS */               
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_A1A2IE, 0);  /* Framing timing comes from receiver */              
                    
                
    ten_n10g_soht_b2ie(module_id_line, TEN_SLICE_ALL, TEN_INSTANCE_ALL, 0xFFFF);  /* Enable insert of all Calculated B2s */

    /* RX Line Side: */
    /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
    /* SDFR_SDFCFG.SCREN = 1 */
    /* LOF, STM-AIS, RS-TIM, AIS-L, dEXC, dLOP, AU-AIS defects reported to OHPP */
    /* OTN-layer defects reported to OHPP */
    /* Set SOHR_S1CFG.B1TRANS=1 */
    /* Set SOHR_S1CFG.B2TRANS=1 */
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
    /* To enable 40G B1 transparent, slice 0, 1, 2 b1trans = 0, Slice 3 b1trans = 1 in N10G and b1trans = 1 in N40G */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id_line, TEN_SLICE_ALL,
                    0,  /* b1trans  Insert Calculated B1 */
                    1); /* b2trans  Insert Calculated B2 */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id_line, 3,
                    1,  /* b1trans  Insert Calculated B1 */
                    1); /* b2trans  Insert Calculated B2 */
    ten_n40g_set_oh_insertion_enables(module_id_line, TEN_N40G_ST4X_OHIE_B1TRANS, 1); /* Enable insert of Calculated B1 */               

                    
    /* TX Client Side: */
    /* SBY = 0 (Do not bypass SDH Processor) */
    /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1, B2IE=1 */
    /* In SOHT, enable RSOH/MSOH bytes that are to be sourced */
    /* (others will be transparently passed through) */
    /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
    /* If B2 error transparency is desired, set B2TRANS=1 in SOHT_OHBEN1 */
    /* SFU inserts MS-RDI (RDI-L) as consequent action */
    /* if LOS/LOF/MS-AIS detected on client RX */
    /* SFU inserts MS-REI (REI-L) based on number of B2  */
    /* errors detected on client RX */
    /* SFU inserts MS-AIS (AIS-L) as consequent action  */
    /* if LOF/STM-AIS/MS-AIS or optionally RS-TIM/dEXC  */
    /* or OTN defect detected on line RX */
    /* Optionally insert AU-AIS as consequent action */
    /* if dLOP/AU-AIS detected on line RX */
    ten_n10g_soht_set_ohben0(module_id_client, TEN_SLICE_ALL,
                    0,  /* b1ie  Enable calculated B1 (BIP-8) insertion (Done in 40G block) */
                    0,  /* scren  Disable SONET/SDH scrabling (Done in 40G block) */
                    /* Bugzilla 24163 Start */
                    0,  /* a1a2rsh Insert (Refresh) FAS bytes Disable (Done in 40G block) */
                    /* Bugzilla 24163 End */
                    0); /* a1a2ie   Framing timing comes from receiver*/
   
    /* N40G_ST4X_OHIE */
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_B1IE, 1);    /* Enable Calculated B1 insertion */                   
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_SCREN, 1);   /* Enable SONET/SDH scrabling */                        
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_A1A2RSH, 1); /* Enable A1 A2 insertion to refresh FAS */               
    ten_n40g_set_oh_insertion_enables(module_id_client, TEN_N40G_ST4X_OHIE_A1A2IE, 0);  /* Framing timing comes from receiver*/                  

    /* N10G_SOHT_B2IE12, N10G_SOHT_B2IE0 */
    ten_n10g_soht_b2ie(module_id_client, TEN_SLICE_ALL, TEN_INSTANCE_ALL, 0xFFFF);  /* Enable insert of all Calculated B2s */
  }
  else {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term_sonet invalid.");
    return(CS_ERROR);
  }

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  40G OTU3 TERMINATION                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_40g_otu3_termination(cs_uint16 module_id,
                                      cs_uint16 term_otu,
                                      cs_uint16 tcm)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o OTU Overhead Termination Type                 */
/*              o TCM termination                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N40G TX for section termination mode.              */
/*                                                              */
/* [module_id] specifies the module ID                          */
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [tcm] parameter specifies the termination for TCM 1      */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 thourgh 6 respectively.           */
/* These bits are defined as follows:                           */ 
/*   0 = disable                                                */
/*   1 = enable.                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* Bugzilla 23776 Start */
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_40g_otu3_termination";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if (term_otu > TEN_OTU_TERM_FULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() term_otu %d out of range.  s/b 0..2.", func, term_otu);
    return(CS_ERROR);
  }

  if (tcm & ~0x7E) { 
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() tcm 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm);
    return(CS_ERROR);
  }

  CS_PRINT("%s()  %s, %s, tcm = 0x%X\n", 
           func, 
           ten_module_strings[module_id & 1],
           ten_hl_config_otu_overhead_term_strings[term_otu],
           tcm);
  /* Bugzilla 23776 End */


  ten_hl_40g_otu3_rx_termination (module_id, term_otu);
  ten_hl_40g_otu3_tx_termination (module_id, term_otu, tcm);
  
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  40G OTU3 RX TERMINATION                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_40g_otu3_rx_termination(cs_uint16 module_id,
                                         cs_uint16 term_otu)
/* INPUTS     : o Module Id                                     */
/*              o OTU Overhead Termination Type                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N40G RX for termination mode.                      */
/*                                                              */
/* [module_id] specifies the module ID                          */
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*   0x02 = TEN_OTU_TERM_FULL                                   */   
/*                                                              */
/* LOS , LOF, and OTUk-AIS reported to OHPP                     */
/* SM-dTIM, SM-dDEG, SM-dIAE, SM-dBDI, SM-dBIAE  defects        */
/* reported to OHPP                                             */
/* TCM and PM layers may optionally be used for non-intrusive   */
/* monitoring.                                                  */
/* SDH Processor and PP10G may optionally be used for           */
/* non-intrusive monitoring.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_gblr4x_dpcfg0;
  TEN_N40G_OTNR4X_ODWCFG_t tmp_otnr4x_odwcfg;
  TEN_N40G_OOHR_CFG5_t tmp_oohr_cfg5;
  T41_t *pDev = NULL;
  /* Bugzilla 23776 Start */
  cs_char8 *func = "ten_hl_40g_otu3_rx_termination";  
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  if (term_otu > TEN_OTU_TERM_FULL) { 
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() term_otu %d out of range.  s/b 0..2.", func, term_otu);
    return(CS_ERROR);
  }
  
  CS_PRINT("%s()  %s, %s\n",
           func,
           ten_module_strings[module_id & 1],
           ten_hl_config_otu_overhead_term_strings[term_otu]);
  /* Bugzilla 23776 End */

  
#if 0
  TEN_N10G_GBLR_DPCFG_t tmp_gblr_dpcfg;

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    tmp_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG));
    if ((term_otu == TEN_OTU_TERM_TRANSPARENT) || (term_otu == TEN_OTU_TERM_SECTION)) {
      tmp_gblr_dpcfg.bf.XSEL   = 1;     /* Align OxU3 in N10G block */
    } else {
      tmp_gblr_dpcfg.bf.XSEL   = 2;     /* Align payload in N10G block */
    }
    TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG), tmp_gblr_dpcfg.wrd);
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
#endif

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_otnr4x_odwcfg.bf.FSOMD = 1;   /* Remove FEC  OTU->ODU (Long to short) */
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_otnr4x_odwcfg.wrd);

  tmp_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  if ((term_otu == TEN_OTU_TERM_TRANSPARENT) || (term_otu == TEN_OTU_TERM_SECTION)) {
    tmp_gblr4x_dpcfg0.bf.BYSEL = 0; /* Use output of OXU3 Terminator */
  } else {
    /* TEN_OTU_TERM_FULL */
    tmp_gblr4x_dpcfg0.bf.BYSEL = 1; /* Use output of OXU3 Dewrapper */
  }
  tmp_gblr4x_dpcfg0.bf.OBY = 0;    /* Do not Bypass OTN */
  tmp_gblr4x_dpcfg0.bf.MDPCFG = 0;   /* Generic Split (OxU deaggregation, OxU payload, or line data) */  /* Bugzilla 29609 */
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_gblr4x_dpcfg0.wrd);

  tmp_oohr_cfg5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5));
  if (term_otu == TEN_OTU_TERM_TRANSPARENT) {
    tmp_oohr_cfg5.bf.BIPMSK = 0x01;
  } else {
    tmp_oohr_cfg5.bf.BIPMSK = 0xFF;
  }
  tmp_oohr_cfg5.bf.MFALGNE = 1;    /* MFAS Alignment Enabled */
  
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5), tmp_oohr_cfg5.wrd);
 
  /* Bugzilla 21131 Start */
  if (term_otu == TEN_OTU_TERM_FULL) {
    /* Enable STM256MD fixed stuff, enable OTN Dewrapper , Aggregation mode Monolithic*/
    ten_n40g_otnr4x_set_odwcfg (module_id, 0, 0, 1, 0, 1);  /*(DW_CONFIG: FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE) */
  }
  /* Bugzilla 21131 End */
 
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  40G OTU3 TX TERMINATION                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_40g_otu3_tx_termination(cs_uint16 module_id,
                                         cs_uint16 term_otu,
                                         cs_uint16 tcm)
/* INPUTS     : o Module Id                                     */
/*              o OTU Overhead Termination Type                 */
/*              o TCM termination                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N40G TX for section termination mode.              */
/*                                                              */
/* [module_id] specifies the module ID                          */
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
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
/* SFU inserts ODUk-AIS as consequent action if LOS/LOF/OTUk-AIS*/ 
/* or optionally SM-dTIM  detected on opposite RX               */
/* SFU inserts SM-IAE as consequent action if LOS/LOF/OTUk-AIS  */
/* detected on opposite RX, else set SM-IAE = 0                 */
/* SFU inserts SM-BEI based on SM-BIP errors detected on same   */
/* side RX                                                      */
/* SFU inserts SM-BIAE as consequent action when SM-dIAE        */
/* detected on same side RX                                     */
/* SFU inserts SM-BDI as consequent action when LOS/LOF/OTUk-AIS*/ 
/* or optionally SM-dTIM  detected on same side RX, else set    */
/* SM-BDI=0                                                     */
/* SM-TTI,  GCC0, and RES overhead may optionally be inserted.  */
/* ODU-layer GCC1/GCC2, FTFL, APS/PCC, EXP, and RES overhead    */
/* may optionally be inserted.                                  */
/* SFU inserts TCMi-BEI based on TCMi-BIP errors detected on    */
/* TCM-Terminating side RX                                      */
/* SFU inserts TCMi-BIAE as consequent action when TCMi-dIAE    */
/* detected on TCM-Terminating side RX                          */
/* SFU inserts TCMi-BDI as consequent action when LOS/LOF/      */
/* OTUk-AIS or optionally SM-dTIM or TCMi-ODUkAIS/dOCI/dLCK/dLTC*/ 
/* or optionally TCMi-dTIM detected on TCM-Terminating side RX, */
/* else set TCMi-BDI=0                                          */
/* SFU inserts TCMi-aIAE (TCMi -STAT = 010) as consequent action*/ 
/* if LOS/LOF/OTUk-AIS on opposite RX, else set TCMi- STAT = 001*/
/* TCMi-TTI inserted.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint8 bipmsk;
  T41_t *pDev = NULL;

  TEN_N40G_GBLT4X_CFG_t tmp_gblt4x_cfg;
  TEN_N40G_OTNT4X_CFG0_t tmp_otnt4x_cfg0;
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_otnt4x_wrpcfg3;
  TEN_N40G_OTNT4X_CFG4_t tmp_otnt4x_cfg4;
  /* Bugzilla 23776 Start */
  cs_char8 *func = "ten_hl_40g_otu3_tx_termination";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  if (term_otu > TEN_OTU_TERM_FULL) { 
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  term_otu %d out of range.  s/b 0..2.", func, term_otu);
    return(CS_ERROR);
  }

  if (tcm & ~0x7E) { 
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() tcm 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm);
    return(CS_ERROR);
  }

  CS_PRINT("%s()  %s, %s, tcm = 0x%X\n", 
           func,
           ten_module_strings[module_id & 1],
           ten_hl_config_otu_overhead_term_strings[term_otu],
           tcm);
  /* Bugzilla 23776 End */

  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_gblt4x_cfg.bf.OBY   = 0;   /* OTN Bypass Disabled */
  tmp_gblt4x_cfg.bf.SBY   = 1;   /* SDH Bypass Enabled */
  tmp_gblt4x_cfg.bf.KPGBY = 1;   /* KPG Bypass Enabled */
  tmp_gblt4x_cfg.bf.MDPCFG = 0;  /* 	OTN Aggregation Mode and Generic Splitting */ /* Bugzilla 29609 */
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_gblt4x_cfg.wrd);
  
  tmp_otnt4x_cfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG0));
  /* Bugzilla 21131 Start */
  if (term_otu == TEN_OTU_TERM_FULL) {
    tmp_otnt4x_cfg0.bf.PTIE = 1;     /* Enable Payload Type Identifier insertion enabled */
  } else {  
    tmp_otnt4x_cfg0.bf.PTIE = 0;     /* Disable Payload Type Identifier insertion disabled */
  }
  /* Bugzilla 21131 End */
  if (term_otu == TEN_OTU_TERM_TRANSPARENT) {
    tmp_otnt4x_cfg0.bf.FASIE   = 0;    /* Do not insert FAS Pattern */
    tmp_otnt4x_cfg0.bf.MFASINS = 0;    /* Never insert MFAS Counter */
  } else {
    tmp_otnt4x_cfg0.bf.FASIE   = 1;     /* Insert FAS Pattern */
    tmp_otnt4x_cfg0.bf.MFASINS = 3;     /* Always Insert MFAS Counter */
  }
  tmp_otnt4x_cfg0.bf.MFALGNE = 1;     /* Enable MFAS Alignment */
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG0), tmp_otnt4x_cfg0.wrd);

  tmp_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
  if ((term_otu == TEN_OTU_TERM_TRANSPARENT) || (term_otu == TEN_OTU_TERM_SECTION)) {
    tmp_otnt4x_wrpcfg3.bf.WRMD = 3;     /* OTU Wrapper on; map short to long frame (ODU to OTU) */
  } else {
    /* Bugzilla 21131 Start */
    /* TEN_OTU_TERM_FULL */
    tmp_otnt4x_wrpcfg3.bf.WRMD = 1;     /* OTU Wrapper on */
    tmp_otnt4x_wrpcfg3.bf.STM256MD = 1; /* Enable STM256MD fixed stuff */
    /* Bugzilla 21131 End */
  }  
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_otnt4x_wrpcfg3.wrd);

  /* Setup Termination Mode */
  if (term_otu == TEN_OTU_TERM_TRANSPARENT) {
    /* All BIP-8 (Path Monitoring, Section Monitoring and all 6 Tandem Connection Monitoring) are passed through */
    bipmsk = 0;  
  }
  else if (term_otu == TEN_OTU_TERM_SECTION) {
    /* Set Section Monitoring BIP-8 update plus selected Tandem Connection Monitoring */
    bipmsk = 0x80 | tcm;
  } else {  /* term_otu == TEN_OTU_TERM_FULL  */
    /* Set Section Monitoring and Path Monitoring BIP-8 update plus selected Tandem Connection Monitoring */
    bipmsk = 0x81 | tcm;
  }
  /*CS_PRINT ("bipmsk = 0x%X\n", bipmsk); */
  tmp_otnt4x_cfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG4));
  tmp_otnt4x_cfg4.bf.BIPMSK = bipmsk;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG4), tmp_otnt4x_cfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}


/* Bugzilla 22970 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OTU3 KPGA                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_otu3_kpga (cs_uint16 module_id,
                                   cs_uint16 traffic_type,
                                   cs_uint16 pattern,
                                   cs_uint16 data_in_stuff_bytes)
/* INPUTS     : o Module Id                                     */
/*              o Traffic Type                                  */
/*              o Pattern Selection                             */
/*              o Data In Stuff Bytes                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an OTU3, OTU3e, OTU3+ or OTU2e KPGA tester         */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [traffic_type] specifies the traffic type:                   */
/*   0x01 = TEN_TRAFFIC_TYPE_OTU3                               */
/*   0x02 = TEN_TRAFFIC_TYPE_OTU3E                              */
/*   0x03 = TEN_TRAFFIC_TYPE_OTU3P                              */
/*   0x17 = TEN_TRAFFIC_TYPE_OTU3E3                             */
/*   0x19 = TEN_TRAFFIC_TYPE_OTU3P2                             */
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
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 module_num = module_id & 1;
  cs_status rtn = CS_OK;
  /* cs_uint16 port =  (module_id & 1) * 4; */
  
  cs_uint16 stm256md = 0;
  cs_uint16 stm64md = 0;
  cs_char8 *func = "ten_hl_config_otu3_kpga";  
  
  
  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E) &&  
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3P) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3P2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E3)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 1, 2, 3, 23, 25.", func, traffic_type);
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

  CS_PRINT("%s()  %s, %s, %s, data_in_stuff_bytes = %d\n",
           func,
           ten_module_strings[module_num],
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_kpg_strings[pattern],
           data_in_stuff_bytes);



  if (!data_in_stuff_bytes) {
    if ((traffic_type == TEN_TRAFFIC_TYPE_OTU3) || (traffic_type == TEN_TRAFFIC_TYPE_OTU3E)) {
      stm256md = 1;
    }
  }

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, port + 1); */ /* Bugzilla #24261 */
  
  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  ten_hsif_clk_40g (module_id, 1, 0, 1, 0);  /* tx_aggr_mode, txsel, rx_aggr_mode, rxsel */
    
  /* Enable the N10G and configure it for bypass */
  ten_hl_n10g_config (module_id, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, TEN_INITIAL_CONFIG);

  /* Enable clock */
  ten_mpif_global_clock_disable_n40g (dev_id, module_id & 1, CS_TX_AND_RX, CS_ENABLE);      
  /* Remove hard reset from the top */
  ten_mpif_global_reset_n40g (dev_id, module_id & 1, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  /*ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + ((module_id & 1) * TEN_N40G_STRIDE), 0);*/
  
  
  /*rtn |= ten_hl_n40g_config (module_id, TEN_N40G_RX_OTU3_ODU3, TEN_N40G_TX_ODU3_OTU3);*/
                           
  /***************************************************************/
  /*       Provision TX                                          */
  /***************************************************************/
  /* KPGBY, SBY, OBY, MDPCFG */
  rtn |= ten_n40g_gblt4x_set_cfg (module_id, 0, 1, 0, 3); /* KPGBY, SBY, OBY, MDPCFG */

  /* POSTSCR, PRESCR - JAM: prescrambling must be enabled to talk to tester */
  rtn |= ten_n40g_otnt4x_scrambling (module_id, 0, 1);

  /* WRMD stm256md=>, stm64md=>, aggrmod=>, wrmd=> */
  /*rtn |= ten_n40g_otnt4x_set_wrpcfg3 (module_id, 0, 0, 0, 1);  */
  rtn |= ten_n40g_otnt4x_set_wrpcfg3 (module_id, stm256md, stm64md, 0, 1);  /* STM256MD, STM64MD, AGGRMOD, WRMD */
     
  /* Enable wrapper to generate justification commands.   Enable enhanced justification */   
  /*rtn |= ten_n40g_otnt4x_set_wrpcfg4(module_id, jc_plus, jc_enabled);*/
     
  /* Config KPG - PATSEL */
  rtn |= ten_n40g_config_kpg (module_id, 0,0, pattern, 0, 0, 0, 0, 0, 0, 0, 0); /* KPGBY, KPGAUTO, PATSEL, FPAT7..FPAT0,   */

  /* FASIE */
  rtn |= ten_n40g_otnt4x_set_fasie (module_id, 1); /* FASIE */
  
  /* Enable BIP */
  rtn |= ten_n40g_otnt4x_bipmsk (module_id, 0xFF);

  /* Set PTI value to what the tester expects - FE */
  rtn |= ten_n40g_set_pti_byte (module_id, TEN_PAYLOAD_TYPE_PRBS);

  /* Enable PTIE */
  rtn |= ten_n40g_otnt4x_set_ptie (module_id, 1);

    /* Enable one col15 byte as payload to make up for extra PJO */
    /*ten_n40g_otnt4x_set_c15res_en0 (mod_line, c15);*/


  /***************************************************************/
  /*       Provision RX                                          */
  /***************************************************************/
  /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
  rtn |= ten_n40g_gblr4x_set_dpcfg0 (module_id, 1, 0, 3, 0, 0, 1); /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
  
  /* DW_CONFIG: FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE */
  /*rtn |= ten_n40g_otnr4x_set_odwcfg (module_id, 0, 0, 0, 0, 1); */
  rtn |= ten_n40g_otnr4x_set_odwcfg (module_id, 0, stm64md, stm256md, 0, 1); /*( FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE) */

  /*rtn |= ten_n40g_otnr4x_set_jc_enable(module_id, jc_enabled);*/   /* Enable justification commands to be evaluated in de-wrapping. */
  /*rtn |= ten_n40g_otnr4x_set_jc_plus(module_id, jc_plus);     */   /* Provision enhanced justification. */

  /* PDHY0/1 */
  /* Bug #40056:  OTU2 KPGA configuration sets PDHY = 0, PHYS also left at 0 */
  rtn |= ten_n40g_set_gblr4x_pdhy (module_id, 0x5F5, 0xE100);  /* PDHY1, PDHY0 */
  
  /* JAM - lab findings (in addition to predescrambling) */
  /* Set expected PTI to match tester - FE               */
  /*rtn |= ten_n40g_set_expected_pti_byte (module_id, 0xFE);*/
  rtn |= ten_n40g_set_expected_pti_byte (module_id, TEN_PAYLOAD_TYPE_PRBS); 
  

  return (CS_OK);
}
  
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC768 OTU3 KPGA            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc768_otu3_kpga (cs_uint16 module_id,
                                         cs_uint16 traffic_type,
                                         cs_uint16 pattern)
/* INPUTS     : o Module Id                                     */
/*              o Traffic Type                                  */
/*              o Pattern Selection                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an OC768 OTU3 KPGA tester                          */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [traffic_type] specifies the traffic type:                   */
/*   0x20 = TEN_TRAFFIC_TYPE_OC768_OTU3                         */
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
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 module_num = module_id & 1;
  /* cs_uint16 port = (module_id & 1) * 4; */
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_config_oc768_otu3_kpga";  
  
  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  
  if (traffic_type != TEN_TRAFFIC_TYPE_OC768_OTU3) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 32.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (pattern > TEN_KPG_PN31) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }
  
  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_num],
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_kpg_strings[pattern]);

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, port + 1);  */ /* Bugzilla #24261 */
  
  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  ten_hsif_clk_40g (module_id, 1, 0, 1, 0);  /* tx_aggr_mode, txsel, rx_aggr_mode, rxsel */
    
  /* Enable the N10G and configure it for bypass */
  ten_hl_n10g_config (module_id, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, TEN_INITIAL_CONFIG);

  /* Enable clock */
  ten_mpif_global_clock_disable_n40g (dev_id, module_id & 1, CS_TX_AND_RX, CS_ENABLE); /* MPIF_GLOBAL_CLOCK_DISABLE_N40G .rx40g, .tx40g, sys */     
  /* Remove hard reset from the top */
  ten_mpif_global_reset_n40g (dev_id, module_id & 1, CS_TX_AND_RX, CS_RESET_DEASSERT);

/*return (CS_OK);;*/

  /* Set the minimum number of frames between any two generated OTU justification commands to 0  (Only needed for async mode) */
  /* This allow sync/desync to control frequency of justification */
  /*ten_reg_write (dev_id, TEN_N40G_OTNT4X_WRPCFG1 + ((module_id & 1) * TEN_N40G_STRIDE), 0);*/
  
  
  /*rtn |= ten_hl_n40g_config (module_id, TEN_N40G_RX_OTU3_ODU3, TEN_N40G_TX_ODU3_OTU3);*/
  
  
  
  /***************************************************************/
  /*       Provision TX                                          */
  /***************************************************************/
  /* KPGBY, SBY, OBY, MDPCFG */
  ten_n40g_gblt4x_set_cfg (module_id, 1, 0, 0, 3);

  /*( POSTSCR, PRESCR */
  ten_n40g_otnt4x_scrambling (module_id, 0, 1);

  /* WRMD stm256md=>, stm64md=>, aggrmod=>, wrmd=> */
  ten_n40g_otnt4x_set_wrpcfg3 (module_id, 1, 0, 0, 1);  

  /* Program the SONET Transmit block:      b1inv, b1trans, b1ie, scren, a1a2rsh */
  /*ten_n40g_st4x_set_ohie (module_id, 0, 0, 1, 0, 0);*/
  ten_n40g_st4x_set_ohie (module_id, 0, 0, 1, 1, 0);

  /* Select PRBS data from KPG as payload PRBSIE */
  ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_PRBSIE, 1);

  /* A1A2 insertion needs to be set A1A2IE */
  ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_A1A2IE, 1);

  ten_n40g_set_poh_byte (module_id, TEN_POH_C2, 0xFE);
  ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_POHIE, 1);
  
  /* Config KPG - PATSEL */
  ten_n40g_config_kpg (module_id, 1, 0, pattern, 0, 0, 0, 0, 0, 0, 0, 0);

  /* FASIE */
  ten_n40g_otnt4x_set_fasie (module_id, 1);

  /* Enable BIP */
  ten_n40g_otnt4x_bipmsk (module_id, 0xFF);

  /* Set PTI value to what the tester expects - FE */
  /*ten_n40g_set_pti_byte (module_id, TEN_PAYLOAD_TYPE_PRBS);*/
  ten_n40g_set_pti_byte (module_id, TEN_PAYLOAD_TYPE_SYNC_CBR);

  /* Enable PTIE */
  ten_n40g_otnt4x_set_ptie (module_id, 1);

  /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
  ten_n10g_set_gblt_cfgtx0 (module_id, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0);
   
  ten_n10g_soht_set_ohben0 (module_id, TEN_SLICE_ALL, 0, 0, 0, 1);

  /* POH insertion needs to be set POHIE */
  ten_n10g_soht_pohben0 (module_id, TEN_SLICE_ALL, 1, 1);

  /* disable all OTN wrapping */
  ten_n10g_otnt_set_wrmd (module_id, TEN_SLICE_ALL, 0);


  
  
  /***************************************************************/
  /*       Provision RX                                          */
  /***************************************************************/
  /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
  ten_n40g_gblr4x_set_dpcfg0 (module_id, 0, 0, 3, 0, 0, 0);

  /* DW_CONFIG: FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE */
  ten_n40g_otnr4x_set_odwcfg (module_id, 0, 0, 1, 0, 1); 

  /* PDHY0/1 */
  /* Bug #40056:  OTU2 KPGA configuration sets PDHY = 0, PHYS also left at 0 */
  ten_n40g_set_gblr4x_pdhy (module_id, 0x5F5, 0xE100);  /* PDHY1, PDHY0 */

  /* Disable SONET scrambler - scrambling done in OTN */
  /*ten_n40g_sdfr_enable_descrambler (module_id, 0 );*/
  /* Enable SONET scrambler */
  ten_n40g_sdfr_enable_descrambler (module_id, 1 );

  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  ten_n10g_set_gblr_dpcfg (module_id, TEN_SLICE_ALL, 2, 0, 1, 0, 1, 0, 1);

  /* JAM - lab findings (in addition to predescrambling)       */
  /* Set expected PTI to match tester - 03 - sync , 02 - async */
  /*ten_n40g_set_expected_pti_byte (module_id, 0x03);*/
  /*ten_n40g_set_expected_pti_byte (module_id, TEN_PAYLOAD_TYPE_PRBS);*/
  ten_n40g_set_expected_pti_byte (module_id, TEN_PAYLOAD_TYPE_SYNC_CBR);    
  
  
  return (CS_OK);
}



/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC768 KPGA                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc768_kpga (cs_uint16 module_id,
                                    cs_uint16 traffic_type,
                                    cs_uint16 pattern)
/* INPUTS     : o Module Id                                     */
/*              o Traffic Type                                  */
/*              o Pattern Selection                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an OC768 KPGA tester                               */
/* The tester will see B3 errors because of a problem with the  */
/* T40 chip                                                     */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [traffic_type] specifies the traffic type:                   */
/*   0x22 = TEN_TRAFFIC_TYPE_OC768                              */
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
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 module_num = module_id & 1;
  /* cs_uint16 port = (module_id & 1) * 4; */
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_config_oc768_kpga";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  
  if (traffic_type != TEN_TRAFFIC_TYPE_OC768) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 22.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (pattern > TEN_KPG_PN31) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }
  
  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_num],
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_kpg_strings[pattern]);

  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, port + 1); */ /* Bugzilla #24261 */
  
  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  ten_hsif_clk_40g (module_id, 1, 0, 1, 0);  /* tx_aggr_mode, txsel, rx_aggr_mode, rxsel */
    
  /* Enable the N10G and configure it for bypass */
  ten_hl_n10g_config (module_id, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS_P, TEN_N10G_TX_BYPASS, TEN_INITIAL_CONFIG);

  /* Enable clock */
  ten_mpif_global_clock_disable_n40g (dev_id, module_id & 1, CS_TX_AND_RX, CS_ENABLE);      
  /* Remove hard reset from the top */
  ten_mpif_global_reset_n40g (dev_id, module_id & 1, CS_TX_AND_RX, CS_RESET_DEASSERT);

  
  
  
  /***************************************************************/
  /*       Provision TX                                          */
  /***************************************************************/
  /* KPGBY, SBY, OBY, MDPCFG */
  ten_n40g_gblt4x_set_cfg (module_id, 1, 0, 1, 3);  /* KPGBY, SBY, OBY, MDPCFG */

  /* POSTSCR, PRESCR */
  ten_n40g_otnt4x_scrambling (module_id, 0, 0); /* POSTSCR, PRESCR */

  /* Turn N40G OTU Wrapper off  (WRMD) */
  ten_n40g_otnt4x_set_wrapper_onoff (module_id, 0); /* WRMD */
              
  /* WRMD stm256md=>, stm64md=>, aggrmod=>, wrmd=> */
  /*ten_n40g_otnt4x_set_wrpcfg3 (module_id, 1, 0, 0, 0);*/

  /* Program the SONET Transmit block:      b1inv, b1trans, b1ie, scren, a1a2rsh */
  ten_n40g_st4x_set_ohie (module_id, 0, 0, 1, 1, 0); /* b1inv, b1trans, b1ie, scren, a1a2rsh */

  /* Select PRBS data from KPG as payload PRBSIE */
  ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_PRBSIE, 1);

  /* Select PRBS data from KPG as payload B1IE */
  ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_B1IE, 1);
  
  /* Select PRBS data from KPG as payload POHIE */
  ten_n40g_set_poh_byte (module_id, TEN_POH_C2, 0xFE);
  ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_POHIE, 1);

  /* A1A2 insertion needs to be set A1A2IE */
  ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_A1A2IE, 1);


  /* Config KPG - PATSEL */
  ten_n40g_config_kpg (module_id, 1, 0, pattern, 0, 0, 0, 0, 0, 0, 0, 0); /* KPGBY, KPGAUTO, PATSEL, FPAT7..FPAT0,   */

  /* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
  /* N10G_GBLT_CFGTX0:   PPLF_EN, CBRSTMAISINS, PN11AUTO, OTNOFF, OBY, SBY, KPGBY, PKTIE */
  ten_n10g_set_gblt_cfgtx0 (module_id, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0); /* pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie */
   
  /* A1A2 insertion needs to be set A1A2IE */
  ten_n10g_soht_set_a1a2ie (module_id, TEN_SLICE_ALL, 1); /* A1A2IE */
   
  /* N10G_SOHT_OHBEN0:  B1IE, SCREN, A1A2RSH, A1A2IE */
  /*ten_n10g_soht_set_ohben0 (module_id, TEN_SLICE_ALL, 0, 0, 0, 1);*/

  /* POH insertion needs to be set POHIE */
  /* N10G_SOHT_POHBEN0:  PRBSIE, POHIE */
  ten_n10g_soht_pohben0 (module_id, TEN_SLICE_ALL, 1, 1); /* PRBSIE, POHIE */

  /* disable all OTN wrapping */
  ten_n10g_otnt_set_wrmd (module_id, TEN_SLICE_ALL, 0); /* WRMD */

  
  /***************************************************************/
  /*       Provision RX                                          */
  /***************************************************************/
  /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
  ten_n40g_gblr4x_set_dpcfg0 (module_id, 0, 0, 3, 0, 1, 0); /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */

  /* DW_ENABLE */
  ten_n40g_otnr4x_set_dw_enable (module_id, 0); /* DW_ENABLE */

  /* DW_CONFIG: FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE */
  ten_n40g_otnr4x_set_odwcfg (module_id, 0, 0, 0, 0, 0); /* FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE */

  /* PDHY0/1 */
  /* Bug #40056:  OTU2 KPGA configuration sets PDHY = 0, PHYS also left at 0 */
  ten_n40g_set_gblr4x_pdhy (module_id, 0x5F5, 0xE100);  /* PDHY1, PDHY0 */
  
  /* Enable SONET scrambler */
  ten_n40g_sdfr_enable_descrambler (module_id, 1 ); /* SCREN */

  /* Configure the N10G SONET block - xsel=>, kpasel=>, sbypld=>, sbyfrm=>, oby=>, sdhoff=>, otnoff=> */
  ten_n10g_set_gblr_dpcfg (module_id, TEN_SLICE_ALL, 2, 0, 0, 0, 1, 0, 1); /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */

  return (CS_OK);
}
/* Bugzilla 22970 End */

