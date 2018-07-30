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
 * ten_hl_hsif_cfp.c
 *
 * API's for protocol high level CFP configuration.
 *
 * $Id: ten_hl_hsif_cfp.c,v 1.57 2013/04/01 17:17:46 khill Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG CFP T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_cfp_t41(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_uint16 traffic,
                                cs_uint16 div,
                                cs_uint16 ckrefdiv,
                                cs_uint16 rx_bitinv,
                                cs_uint16 tx_bitinv,
                                cs_uint16 prot,
                                cs_uint16 aux_clk,
                                cs_uint16 wait_for_vcotune,
                                cs_uint16 cfp_stx_tx_output_ctrl_drv_lower_cm,
                                cs_uint16 cfp_stx_tx_output_ctrl_level,
                                cs_uint16 cfp_stx_tx_output_ctrl_post_peak,
                                cs_uint16 cfp_srx_rx_misc_srx_eqadj)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Traffic Type                                      */
/*              o Divide Ratio                                      */
/*              o Ckrefdiv                                          */
/*              o Rx Bit Invert                                     */
/*              o Tx Bit Invert                                     */
/*              o Protection                                        */
/*              o Aux Clock                                         */
/*              o Wait For VCO Tune                                 */
/*              o cfp_stx_tx_output_ctrl_drv_lower_cm               */
/*              o cfp_stx_tx_output_ctrl_level                      */
/*              o cfp_stx_tx_output_ctrl_post_peak                  */
/*              o cfp_srx_rx_misc_srx_eqadj                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provides top-most level configuration of CFP, including          */
/* waiting for lock.                                                */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* [traffic]                                                        */
/*   TEN_TRAFFIC_TYPE_NONE = 0                                      */
/*   TEN_TRAFFIC_TYPE_OTU3 = 1                                      */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                     */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                     */
/*   TEN_TRAFFIC_TYPE_ODTU23 = 4                                    */
/*   TEN_TRAFFIC_TYPE_OTU2 = 5                                      */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                     */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                     */
/*   TEN_TRAFFIC_TYPE_OC192 = 8                                     */
/*   TEN_TRAFFIC_TYPE_10GE_WAN = 9                                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2 = 10                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3 = 12                                 */
/*   TEN_TRAFFIC_TYPE_5GB_IB = 18                                   */
/*   TEN_TRAFFIC_TYPE_10GE_6_1 = 26                                 */
/*   TEN_TRAFFIC_TYPE_10GE_TC = 33                                  */
/*                                                                  */
/* [div]  Specified as:                                             */
/*   TEN_HSIF_CFP_DIV_BY_16_REF          = 0,                       */
/*   TEN_HSIF_CFP_DIV_BY_32_REF          = 1,                       */
/*   TEN_HSIF_CFP_DIV_BY_64_REF          = 2,                       */
/*   TEN_HSIF_CFP_DIV_BY_66_REF          = 3,                       */
/*   TEN_HSIF_CFP_DIV_BY_40_REF          = 4,                       */
/*   TEN_HSIF_CFP_DIV_BY_80_REF          = 5                        */
/*                                                                  */
/* [ckrefdiv] parameter is specified as:                            */
/*   TEN_HSIF_CKREFDIV1 = 0,  (div1 to serdes)                      */
/*   TEN_HSIF_CKREFDIV2 = 1,  (div2 to serdes)                      */
/*   TEN_HSIF_CKREFDIV4 = 2   (div4 to serdes)                      */
/*                                                                  */
/* [rx_bitinv]                                                      */
/*   0 = do not invert the bit polarity of all RX data bits         */
/*   1 = invert the bit polarity of all RX data bits                */
/*   NOTE:  when using TEN_SLICE_ALL, this field is interpreted     */
/*   as a bit-masked field, bit 0 associated with slice 0, etc.     */
/*                                                                  */
/* [tx_bitinv]                                                      */
/*   0 = do not invert the bit polarity of all TX data bits         */
/*   1 = invert the bit polarity of all TX data bits                */
/*   NOTE:  when using TEN_SLICE_ALL, this field is interpreted     */
/*   as a bit-masked field, bit 0 associated with slice 0, etc.     */
/*                                                                  */
/* [prot]                                                           */
/*   0 = do not set up the receive protection clock                 */
/*   1 = set up the receive protection clock                        */
/*                                                                  */
/* [aux_clk]   (-cfp_mrb1_mrb3)                                     */
/*   NOTE:  This option is intended for 40G mode only               */
/*   0 = Use Common Clock (frequency x4, ie 600Mhz)                 */
/*   1 = Support for CFP MRB1/MRB3 (100-200Mhz)                     */
/*   2 = 10G only, set slice 0/2 with slice 1/3                     */
/*                                                                  */
/* [wait_for_vcotune]                                               */
/*   0 = do not wait for vcotune (not recommended)                  */
/*   1 = wait for vcotune (recommended)                             */
/*                                                                  */
/* [cfp_stx_tx_output_ctrl_drv_lower_cm]                            */
/*   Turns on current sources to STX_VDD_DVR                        */
/*   which increase the current through the off-chip                */
/*   12.5 ohm resistor thereby reducing the output                  */
/*   common-mode voltage. Binary weighted, 2mA LSB.                 */
/*   0000 = off                                                     */
/*   1111 = 30mA                                                    */
/*                                                                  */
/* [cfp_stx_tx_output_ctrl_level]                                   */
/*   Output driver cursor output level adjust, binary               */
/*   weighted, 0.5mA LSB:                                           */
/*   111111 = 32mA                                                  */
/*   000000 = 0.5mA                                                 */
/*                                                                  */
/* [cfp_stx_tx_output_ctrl_post_peak]                               */
/*   Output driver post-cursor level adjust, binary weighted,       */
/*     0.25mA LSB.                                                  */
/*     111111 = 15.75mA                                             */
/*     00000  = off                                                 */
/*                                                                  */
/* [cfp_srx_rx_misc_srx_eqadj]                                      */
/*     Equalizer zero adjustment:                                   */
/*     0000 = max equalization                                      */
/*     1111 = min equalization.                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  cs_uint16 instance;
  cs_status rtn = CS_OK;
  cs_uint16 tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
  cs_uint16 tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
  cs_uint16 tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 0;
  cs_uint16 tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
  cs_uint16 tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;
  cs_uint16 tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
  cs_uint16 tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 0;
  cs_uint16 tmp_lptime_sel;
  cs_uint16 tmp_pilot_sel;
  cs_uint16 cfp_is_t40g_traffic = 0;
  cs_uint16 ii;
  cs_uint16 mod_id_b;
  cs_uint16 mod_id_a;
  cs_uint16 current_traffic, new_traffic;
  cs_uint16 cfp_vco_thres;
  cs_char8 *func = "ten_hl_config_cfp_t41";  
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  if ((traffic == TEN_TRAFFIC_TYPE_NONE) || (traffic >= TEN_TRAFFIC_TYPE_MAX)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": traffic type %d out of range.", traffic);
    return (CS_ERROR);
  }
  
  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41-only feature.");
    return (CS_ERROR);
  }
  
  if ((ckrefdiv != TEN_HSIF_CKREFDIV4) && (ckrefdiv == TEN_HSIF_CKREFDIV2) && (ckrefdiv == TEN_HSIF_CKREFDIV1)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Unsupported ckrefdiv.");
    return (CS_ERROR);
  }
  
  if (div >= TEN_HSIF_CFP_DIV_BY_MAX_PARM) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": CFP unsupported div.");
    return (CS_ERROR);                  
  }
  
  CS_PRINT("%s()\n", func);
  CS_PRINT("    %s\n", ten_module_strings[module_id&1]);
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("    SLICE_ALL\n");
  }
  else {
    CS_PRINT("    %s\n", ten_slice_strings[slice]);
  }
  CS_PRINT("    %s\n", ten_hl_config_traffic_types_strings[traffic]);
  CS_PRINT("    div=%d\n", div);
  CS_PRINT("    rx_bitinv=%d\n", rx_bitinv);
  CS_PRINT("    tx_bitinv=%d\n", tx_bitinv);
  CS_PRINT("    prot=%d\n", prot);
  CS_PRINT("    aux_clk/-cfp_mrb1_mrb3=%d\n", aux_clk);
  CS_PRINT("    wait_for_vcotune=%d\n", wait_for_vcotune);
  
  mod_id_b = (dev_id << 8) | TEN_MODULE_B;
  mod_id_a = (dev_id << 8) | TEN_MODULE_A;

  switch (traffic) {
  case (TEN_TRAFFIC_TYPE_OTU3):                /* 1 */
  case (TEN_TRAFFIC_TYPE_OTU3E):               /* 2 */
  case (TEN_TRAFFIC_TYPE_OTU3P):               /* 3 */
  case (TEN_TRAFFIC_TYPE_40GELAN):             /*21 */
  case (TEN_TRAFFIC_TYPE_OC768):               /*22 */
  case (TEN_TRAFFIC_TYPE_OTU3E3):              /*23 */
  case (TEN_TRAFFIC_TYPE_CBR40G_50188149150):  /*24 */
  case (TEN_TRAFFIC_TYPE_OTU3P2):              /*25 */
  case (TEN_TRAFFIC_TYPE_OC768_OTU3):          /*32 */
  case (TEN_TRAFFIC_TYPE_OTU3E2):              /*35 */
  case (TEN_TRAFFIC_TYPE_12_5G_IB):            /*40 */
  case (TEN_TRAFFIC_TYPE_SERIAL_40GE):         /*41 */
  case (TEN_TRAFFIC_TYPE_PARALLEL_40GE):       /*42 */
  case (TEN_TRAFFIC_TYPE_TC_40GE):             /*43 */
  case (TEN_TRAFFIC_TYPE_S64_66_40GE):         /*44 */
  case (TEN_TRAFFIC_TYPE_OTU3E4):              /*55 */  /* Bugzilla 29996 */
    cfp_is_t40g_traffic = 1;
    break;
    
  default:
    cfp_is_t40g_traffic = 0;
    break;
  }
  
  /* Bugzilla #34256, Driver State Information in API5.6 */
  /* Bugzilla #33489, Reconfigure CFP MR slices independently even with shared Tx PLL */
  
  if (cfp_is_t40g_traffic == 0) {
    new_traffic = traffic;
    /* use a common traffic enum for all 10ge (into otu2) rates */
    /* Bugzilla #35898 , (10ge7.1 into otu2e) and (10ge7.2 into otu1e) require CFP reinit */
    if ((new_traffic == TEN_TRAFFIC_TYPE_10GE_WAN) || 
        (new_traffic == TEN_TRAFFIC_TYPE_10GE_6_2) ||
        (new_traffic == TEN_TRAFFIC_TYPE_10GE_7_3) ||
        (new_traffic == TEN_TRAFFIC_TYPE_10GE) ||
        (new_traffic == TEN_TRAFFIC_TYPE_10GE_6_1) ||
        (new_traffic == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) ||
        (new_traffic == TEN_TRAFFIC_TYPE_10GE_RA) ||
        (new_traffic == TEN_TRAFFIC_TYPE_10GE_TC) ||
        (new_traffic == TEN_TRAFFIC_TYPE_10GE_GFPF)) {
          new_traffic = TEN_TRAFFIC_TYPE_10GE;
    }
    
    if (slice == TEN_SLICE_ALL) {
      current_traffic = g_pTEN->p_dev_cb_tbl[dev_id]->cfp_current_traffic[0];
    }
    else {
      current_traffic = g_pTEN->p_dev_cb_tbl[dev_id]->cfp_current_traffic[slice];
    }
    
    CS_PRINT("    current_traffic = %d, new_traffic=%d\n", current_traffic, new_traffic);
    if (current_traffic == new_traffic) {
      if (ten_mpif_get_global_reset_sds_cfp_t41(dev_id, slice, CS_TX_AND_RX) == 0) {
        CS_PRINT("    current_traffic already matches new traffic, exit CFP configuration\n");
        goto RTN_EXIT; /* go to common exit point instead of having multiple return points */
      }
      else {
        CS_PRINT("    current_traffic already matches new traffic, but CFP_MR is in hard reset, reconfigure\n");
      }
    }
    else {
      /* Bugzilla #36863: 10G CFP_MR has traffic hits on dynamic reconfig */
      if (aux_clk != 2) { 
        if (slice == TEN_SLICE_ALL) {
          g_pTEN->p_dev_cb_tbl[dev_id]->cfp_current_traffic[0] = new_traffic;
        }
        else {
          g_pTEN->p_dev_cb_tbl[dev_id]->cfp_current_traffic[slice] = new_traffic;
        }
      }
    }
  }
  
  /* Set top clock mux */
  if (mod_num == TEN_MODULE_A) {
     /* Setup side A GPLL input takes output from MRB       */
     rtn |= ten_mpif_clock_select_hsif_out(dev_id, mod_num, slice, CS_TX_AND_RX, 1);
     
     /* Setup side B MR takes output from GPLL A        */
     rtn |= ten_mpif_clock_select_prot_per_slice(dev_id, mod_num, slice, CS_TX_AND_RX, 1);
     
     /* Bug #36216 Pilot clock settings in 10G transponder */
     if (slice == TEN_SLICE0) {
       rtn |= ten_mpif_clock_select_pilot_per_slice(dev_id, TEN_SLICE1, 1);
     }
     else if (slice == TEN_SLICE2) {
       rtn |= ten_mpif_clock_select_pilot_per_slice(dev_id, TEN_SLICE3, 1);
     }
     else {
       rtn |= ten_mpif_clock_select_pilot_per_slice(dev_id, slice, 1);
     }
  }
  else if (mod_num == TEN_MODULE_B) {
     /* Setup side B GPLL input takes output from MRB        */
     rtn |= ten_mpif_clock_select_hsif_out(dev_id, mod_num, slice, CS_TX_AND_RX, 0);

     /* Setup side B MR DON'T takes output from GPLL A */
     rtn |= ten_mpif_clock_select_prot_per_slice(dev_id, mod_num, slice, CS_TX_AND_RX, 0);
  }     

  /* Bugzilla #30768, fix CPF_MR 10G issues */
  ten_mpif_global_clock_disable_xfi_b(dev_id, slice, CS_TX_AND_RX, CS_ENABLE);
       
  if (cfp_is_t40g_traffic) {
    rtn = ten_mpif_clock_select_prot_40g(dev_id, 1, 1);
  }
  else {
    rtn = ten_mpif_clock_select_prot_40g(dev_id, 0, 0);
  }
  
  /* cpu.write(MPIF_CLOCK_SELECT_GPLL_IN,  16'h0000, 0);   */
  /* Setup side A and B GPLL takes input from Rx clocks    */
  /* generated from Multi-Rate or XFI serdes               */
  rtn |= ten_mpif_clock_select_gpll_in(dev_id, TEN_MODULE_B, slice, CS_TX_AND_RX, 0);
        
  /* cpu.write(MPIF_CLOCK_SELECT_SYS, 16'h0000, 0); */
  rtn |= ten_mpif_clock_select_sys(dev_id, 0); /* bypass */
  
  /* cpu.write(MPIF_GLOBAL_CLOCK_DISABLE_CFP, 16'h0000, 0);  */
  /* enable CFP clocks                                       */
  rtn |= ten_mpif_global_clock_disable_cfp_t41(dev_id, CS_TX_AND_RX, CS_ENABLE);

  /* Bugzilla #26284, CFP fixes */
  if (mod_num == TEN_MODULE_A) {
    rtn |= ten_mpif_global_clock_disable_mr_a(dev_id, slice, CS_TX_AND_RX, CS_ENABLE);
  }
  rtn |= ten_mpif_global_clock_disable_mr_b(dev_id, slice, CS_TX_AND_RX, CS_ENABLE);
      
  /* Bugzilla #26217, CFP changes */
  /* Toggle hard reset in case of dynamic reprovisioning and the clock rate has changed */
  rtn |= ten_mpif_global_reset_sds_cfp_t41(dev_id, slice, CS_TX_AND_RX, CS_RESET_TOGGLE);

  /* Bugzilla #26217, CFP changes */
  rtn |= ten_mpif_global_reset_sds_cfp_mpif_t41(dev_id, slice, CS_RESET_TOGGLE);
  
  TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
  
  /* Power down MR SERDES B */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc0_mr10x4_sds_common_srx0_srx_pd(mod_id_b, TEN_INSTANCE_ALL, CS_ENABLE);
    ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_all(mod_id_b, CS_ENABLE);
    ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(mod_id_b, 0x1F); 
  }
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc1_mr10x5_sds_common_srx0_srx_pd(mod_id_b, TEN_INSTANCE_ALL, CS_ENABLE);
    ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_pwrdn_all(mod_id_b, CS_ENABLE);
    ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_pwrdn_pd_lane(mod_id_b, 0x1F);
  }
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc2_mr10x4_sds_common_srx0_srx_pd(mod_id_b, TEN_INSTANCE_ALL, CS_ENABLE);
    ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_all(mod_id_b, CS_ENABLE);
    ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(mod_id_b, 0x1F);
  }
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc3_mr10x5_sds_common_srx0_srx_pd(mod_id_b, TEN_INSTANCE_ALL, CS_ENABLE);
    ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_pwrdn_all(mod_id_b, CS_ENABLE);
    ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_pwrdn_pd_lane(mod_id_b, 0x1F);
  }
  
  /* power up the CFP serdes */
  rtn |= ten_hl_hsif_cfp_control_power_t41(module_id, slice, CS_ENABLE);
  
  /* Provision datapath for CFP */
  if (mod_num == TEN_MODULE_A) {
    /* Use protection bus for MR on Module A */
    /* rxpstwchen=1: hsif side A rx data are from the remote interface */

    /* Set all 4 ports on module B to XFI to prevent a glitch on adjacent ports pairs when individual clients are added  (4-5 pair and 6-7 pair) */
    rtn |= ten_hsif_provision_rx_xfiselect (mod_id_b, slice, 1);   /* Bugzilla 31024 */
    rtn |= ten_hsif_provision_tx_xfiselect (mod_id_b, slice, 1);   /* Bugzilla 31024 */

    /* Bugzilla #30768, fix CPF_MR 10G issues */
    rtn |= ten_hsif_provision_datapath_t41(mod_id_a, slice, 
                                           0,                        /* tx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_CFP,    /* tx_mrprotocol */
                                           1,                        /* rx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_CFP);   /* rx_mrprotocol */
  
    rtn |= ten_hsif_provision_datapath_t41(mod_id_b, slice, 
                                           1,                        /* tx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_CFP,    /* tx_mrprotocol */
                                           0,                        /* rx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_CFP);   /* rx_mrprotocol */
  
    rtn |= ten_mpif_global_reset_sds_mr(dev_id, TEN_MODULE_B, slice, 
                                        CS_TX_AND_RX, CS_RESET_DEASSERT); 
                                        
    rtn |= ten_mpif_global_clock_disable_mr_b(dev_id, slice, CS_TX_AND_RX, CS_ENABLE);
    
    /* Bugzilla 31024 Start */
    rtn |= ten_hsif_pswtch_ok_ctrl_xlos_en(mod_id_b, slice, 0);
    /* Bugzilla 31024 End */
  }
  else {
    /* Bugzilla #30768, fix CPF_MR 10G issues */
    rtn |= ten_hsif_provision_datapath_t41(mod_id_b, slice, 
                                           0,                       /* tx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_CFP,   /* tx_mrprotocol */
                                           0,                       /* rx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_CFP);  /* rx_mrprotocol */
                                           
    /* Bugzilla #31356, fix consistency/dynamic reconfig issues with xfiselect bits */
    rtn |= ten_hsif_provision_tx_xfiselect(module_id, slice, 0);
    rtn |= ten_hsif_provision_rx_xfiselect(module_id, slice, 0);                                       
  }

  if (cfp_is_t40g_traffic) {
    if (ckrefdiv == TEN_HSIF_CKREFDIV4) {
      ten_hsif_set_refclk_cfg(mod_id_b, TEN_HSIF_REFCLK_CFG_CKREFDIV, 2);
    }
    else if (ckrefdiv == TEN_HSIF_CKREFDIV2) {
      ten_hsif_set_refclk_cfg(mod_id_b, TEN_HSIF_REFCLK_CFG_CKREFDIV, 1);
    }
    else if (ckrefdiv == TEN_HSIF_CKREFDIV1) {
      ten_hsif_set_refclk_cfg(mod_id_b, TEN_HSIF_REFCLK_CFG_CKREFDIV, 0);
    }                                  
  }
 
  rtn |= ten_cfp32x1_srx0_rx_config_xfi_en_t41(module_id, slice, 1);
  rtn |= ten_cfp32x1_stxp0_tx_config_xfi_en_t41(module_id, slice, 1);

  if (div == TEN_HSIF_CFP_DIV_BY_64_REF) {
    /* Bugzilla #32193, aux_clk==1 not applicable for CPF_MR */
    if (cfp_is_t40g_traffic) {  /* 9.2.3.1 */
      if (aux_clk) { 
        tmp_lptime_sel = 0;  /* use MRB_TX0_CLKREFP/N */
      }
      else {
        tmp_lptime_sel = 2;  /* use SFI5CKREF internal signal from 40G ref clock block */
      }
      /* Bugzilla #32887, T41 CFP MRB pilot setting */
      tmp_pilot_sel = 1;  /* always use STXP_AUXPILOTIN from Fractional Divider */
    }
    else {  /* 10G */ /* 9.2.3.3 */
      tmp_lptime_sel = 0;  /* use MRB_TX0_CLKREFP/N */
      /* Bug #36216 Pilot clock settings in 10G transponder */
      tmp_pilot_sel = 1;    /* was 0 */
    }
  }
  else {  
    if (cfp_is_t40g_traffic) {  /* 9.2.3.1 */
      tmp_lptime_sel = 2;
      tmp_pilot_sel = 2;
    }
    else {  /* 9.2.3.3 */
      tmp_lptime_sel = 0;
      tmp_pilot_sel = 0;
    }
  }
  
  /* Reference and pilot selection mode. This control signal         */
  /* only has an impact when STXP_XFI_EN = 1, i.e. reference         */
  /* and pilot selection is always MR SERDES when STXP_XFI_EN = 0    */
  /* 0 = XFI SERDES mode                                             */
  /* 1 = MR SERDES mode.                                             */
  rtn |= ten_cfp32x1_stxp0_tx_spare_ref_sel_mode_t41(module_id, slice, 1);

  /* SERDES Start-up Procedure                                        */
  /* 1. Apply reference clock on XFIn_TX_CLKREFP/N or                 */
  /*    one of the many other places to get the reference.            */
  /*    (STXP_LPTIME_SEL_MSB, STXP_LPTIME_SEL[1:0])                   */
  
  /* Selects TX PLL Reference Clock:                                  */
  /* For STXP_REF_SEL_MODE = 0 (XFI SERDES Mode):                     */
  /* For STXP_LPTIME_SEL_MSB = 0                                      */
  /* 00 = use MRB_TX0_CLKREFP/N external pads                         */
  /* 01 = use MRB_TX0_AUXPILOTP/N (test only)                         */
  /* For STXP_LPTIME_SEL_MSB = 1                                      */
  /* 01 = use STXP_AUXPILOTIN from Fractional Divider                 */
  /* For STXP_REF_SEL_MODE = 1 (MR SERDES Mode):                      */
  /* 00 = use MRB_TX0_CLKREFP/N                                       */
  /* 10 = use SFI5CKREF internal signal from 40G ref clock block      */
  /* See HSIF_PROTOCOL_REFCLK_CGF for additional configuration        */
  rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, slice, tmp_lptime_sel);
  rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_msb_t41(module_id, slice, 0);

  /* 2. Configure pilot tone: internal/external (STXP_PILOT_SEL[2:0]) */
  
  /* Selects pilot tone clock to the receiver and STXP_REF_LD signal. */
  /* For STXP_REF_SEL_MODE = 0 (XFI SERDES Mode):                     */
  /* 0x0 = use MRB_TX0_CLKREFP/N external pads                        */
  /* 0x1 = use STXP_AUXPILOTIN from Fractional Divider                */
  /* 11x = use MRB_TX0_AUXPILOTP/N                                    */
  /* For STXP_REF_SEL_MODE = 1 (MR SERDES Mode):                      */
  /* 000 = use MRB_TX0_CLKREFP/N external pad                         */
  /* 001 = use STXP_AUXPILOTIN from Fractional Divider                */
  /* 010 = use SFI5CKRXPILOT internal signal from 40G ref clock block */
  /* 011 = use MRB_TX0_AUXPILOTP/N external pad                       */
  /* 100 = use SFI5CKREF internal signal from 40G ref clock block     */
  /* See HSIF_PROTOCOL_REFCLK_CFG for additional configuration        */
  rtn |= ten_cfp32x1_stxp0_tx_config_pilot_sel_t41(module_id, slice, tmp_pilot_sel);
  
  /* Choose fractional divider output as pilot tone */
  rtn |= ten_cfp32x1_set_rxlockd0_pd_mode_t41(module_id, slice, 0);
  rtn |= ten_cfp32x1_set_rxlockd0_force_lock_t41(module_id, slice, 1);
  
  /* 3. Set divide ratios: */
  if (div == TEN_HSIF_CFP_DIV_BY_16_REF) {
    tmp_srx0_rx_clkdiv_ctrl_rdiv_sel   = 0;
    tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 2;
    tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel  = 0;
    tmp_stxp0_tx_clkdiv_ctrl_ctr_div   = 2;
    tmp_stxp0_tx_clkdiv_ctrl_ctv_div   = 2;
    tmp_srx0_rx_clkdiv_ctrl_ddiv_sel   = 0;
    tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel  = 0;
  }
  else if (div == TEN_HSIF_CFP_DIV_BY_64_REF) {
    /* Bug #36216 Pilot clock settings in 10G transponder */
    /* Bugzilla #32193, CFP MRB1/MRB3 support */
    tmp_srx0_rx_clkdiv_ctrl_rdiv_sel   = 1;    /* was 2 */
    tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;    /* was 0 */

    if ((aux_clk == 1) && (cfp_is_t40g_traffic)) { 
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel  = 0;
    }
    else {
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel  = 2;
    }
    tmp_stxp0_tx_clkdiv_ctrl_ctr_div   = 1;    /* was 0 */
  
    if ((aux_clk == 1) && (cfp_is_t40g_traffic)) { 
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div   = 2;
    }
    else {
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div   = 0;
    }
    tmp_srx0_rx_clkdiv_ctrl_ddiv_sel   = 0;
    tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel  = 0;
  }
  else if (div == TEN_HSIF_CFP_DIV_BY_32_REF) {
    tmp_srx0_rx_clkdiv_ctrl_rdiv_sel   = 1;
    tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
    tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel  = 1;
    tmp_stxp0_tx_clkdiv_ctrl_ctr_div   = 1;
    tmp_stxp0_tx_clkdiv_ctrl_ctv_div   = 1;
    tmp_srx0_rx_clkdiv_ctrl_ddiv_sel   = 0;
    tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel  = 0;
  }
  else if (div == TEN_HSIF_CFP_DIV_BY_40_REF) {
    tmp_srx0_rx_clkdiv_ctrl_rdiv_sel   = 4;
    tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
    tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel  = 4;
    tmp_stxp0_tx_clkdiv_ctrl_ctr_div   = 1;
    tmp_stxp0_tx_clkdiv_ctrl_ctv_div   = 1;
    tmp_srx0_rx_clkdiv_ctrl_ddiv_sel   = 0;
    tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel  = 0;
  }
  else if (div == TEN_HSIF_CFP_DIV_BY_66_REF) {
    tmp_srx0_rx_clkdiv_ctrl_rdiv_sel   = 3;
    tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
    tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel  = 3;
    tmp_stxp0_tx_clkdiv_ctrl_ctr_div   = 0;
    tmp_stxp0_tx_clkdiv_ctrl_ctv_div   = 0;
    tmp_srx0_rx_clkdiv_ctrl_ddiv_sel   = 0;
    tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel  = 0;
  }
  else if (div == TEN_HSIF_CFP_DIV_BY_80_REF) {
    tmp_srx0_rx_clkdiv_ctrl_rdiv_sel   = 5;
    tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
    tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel  = 5;
    tmp_stxp0_tx_clkdiv_ctrl_ctr_div   = 0;
    tmp_stxp0_tx_clkdiv_ctrl_ctv_div   = 0;
    tmp_srx0_rx_clkdiv_ctrl_ddiv_sel   = 0;
    tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel  = 0;
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": CFP unsupported div.");
    return (CS_ERROR);
  }

  rtn |= ten_cfp32x1_srx0_rx_clkdiv_ctrl_ctvdiv_t41(module_id, slice, tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel);
  rtn |= ten_cfp32x1_srx0_rx_clkdiv_ctrl_ddiv_t41(module_id, slice, tmp_srx0_rx_clkdiv_ctrl_ddiv_sel);
  rtn |= ten_cfp32x1_srx0_rx_clkdiv_ctrl_rdiv_t41(module_id, slice, tmp_srx0_rx_clkdiv_ctrl_rdiv_sel);
  rtn |= ten_cfp32x1_stxp0_tx_clkdiv_ctrl_ctrdiv_t41(module_id, slice, tmp_stxp0_tx_clkdiv_ctrl_ctr_div);
  rtn |= ten_cfp32x1_stxp0_tx_clkdiv_ctrl_ctvdiv_t41(module_id, slice, tmp_stxp0_tx_clkdiv_ctrl_ctv_div);
  rtn |= ten_cfp32x1_stxp0_tx_clkdiv_ctrl_ddiv_t41(module_id, slice, tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel);
  rtn |= ten_cfp32x1_stxp0_tx_clkdiv_ctrl_rdiv_t41(module_id, slice, tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel);
  
  /* 4. This step is not applicable for CFP */
 
  /* 5. Adjust the loop filter settings. */
  rtn |=  ten_cfp32x1_stxp0_tx_cpcur_t41(module_id, slice, 7, 7);
  rtn |= ten_cfp32x1_stxp0_tx_loop_filter_t41(module_id, slice, 5);
  rtn |= ten_cfp32x1_srx0_rx_cpa_cpcur_t41(module_id, slice, 4, 4);
  
  /* 6. Adjust VCO coarse tuning thresholds */
  /* From GS XFI SERDES General Specification 3.12, TABLE 34. LC VCO Coarse Tuning Settings vs Bit Rate. */
  /* Bugzilla #35737 - Implement TABLE 34. LC VCO Coarse Tuning Settings vs Bit Rate */
  switch (traffic) {
  case (TEN_TRAFFIC_TYPE_OC768_OTU3):
  case (TEN_TRAFFIC_TYPE_OTU3):
  case (TEN_TRAFFIC_TYPE_OTU2): /* OTU2/otu2=10709.2253 */
    cfp_vco_thres = 0x2F;  /* 10.70 Gbps */
    break;

  case (TEN_TRAFFIC_TYPE_OTU3E):
  case (TEN_TRAFFIC_TYPE_OTU3P):
  case (TEN_TRAFFIC_TYPE_OTU3E2):
  case (TEN_TRAFFIC_TYPE_OTU3E3):
  case (TEN_TRAFFIC_TYPE_OTU3P2):
  case (TEN_TRAFFIC_TYPE_OTU2E): /* OTU2e/otu210geopu2e=11095.7278 */
  case (TEN_TRAFFIC_TYPE_OTU1E): /* OTU1e/otu210geopu1e=11049.107143 */
    cfp_vco_thres = 0x3A;  /* 11.1 Gbps */
    break;

  case (TEN_TRAFFIC_TYPE_OTU1F): /* OTU1f/otu210gfcopu1e=11270.0893 */
    cfp_vco_thres = 0x3A;  /* 11.3 Gbps */
    break;
    
  case (TEN_TRAFFIC_TYPE_OC768):
  case (TEN_TRAFFIC_TYPE_10GE_WAN):
  case (TEN_TRAFFIC_TYPE_OC192): /* OC192/oc192=9953.28 */
  case (TEN_TRAFFIC_TYPE_10G_IB):
  case (TEN_TRAFFIC_TYPE_5GB_IB):
    cfp_vco_thres = 0x26;  /* 9.95328 Gbps */
    break;
    
  case (TEN_TRAFFIC_TYPE_40GELAN):
  case (TEN_TRAFFIC_TYPE_CBR40G_50188149150):
  case (TEN_TRAFFIC_TYPE_SERIAL_40GE):
  case (TEN_TRAFFIC_TYPE_PARALLEL_40GE):
  case (TEN_TRAFFIC_TYPE_TC_40GE):
  case (TEN_TRAFFIC_TYPE_S64_66_40GE):
  case (TEN_TRAFFIC_TYPE_10GE):
  case (TEN_TRAFFIC_TYPE_10GE_6_1):
  case (TEN_TRAFFIC_TYPE_10GE_6_2):
  case (TEN_TRAFFIC_TYPE_10GE_7_1):
  case (TEN_TRAFFIC_TYPE_10GE_7_2):
  case (TEN_TRAFFIC_TYPE_10GE_7_3):  /* 10GE/10gelan=10312.5 */
  case (TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2):
  case (TEN_TRAFFIC_TYPE_10GE_RA):
  case (TEN_TRAFFIC_TYPE_10GE_TC):
  case (TEN_TRAFFIC_TYPE_10GE_GFPF):
  case (TEN_TRAFFIC_TYPE_FDR10_IB): /* Bugzilla 39242 */
    cfp_vco_thres = 0x2A;  /* 10.3125 Gbps */
    break;

  case (TEN_TRAFFIC_TYPE_10GFC):  /* 10GFC/fc1200=10518.75 */
  case (TEN_TRAFFIC_TYPE_10GFC_TC_RA):
  case  TEN_TRAFFIC_TYPE_10GFC_TC:
  case  TEN_TRAFFIC_TYPE_10GFC_TC_G709:
    cfp_vco_thres = 0x2E;  /* 10.52 Gbps */
    break;

  case (TEN_TRAFFIC_TYPE_8GFC):  /* 8GFC/fc800=8500 */
  case (TEN_TRAFFIC_TYPE_8GFC_RA):  /* 8GFC/fc800=8500 */
  case (TEN_TRAFFIC_TYPE_8GFC_ENH):  /* 8GFC/fc800=8500 */
    cfp_vco_thres = 0x20;  /* default */
    /* GBPS_8__5_FC */
    break;

  case (TEN_TRAFFIC_TYPE_4GFC):
  case (TEN_TRAFFIC_TYPE_4GFC_RA):
  case (TEN_TRAFFIC_TYPE_4GFC_ENH):
    cfp_vco_thres = 0x20;  /* default */
    /* GBPS_4__25_FC */
    break;

  case (TEN_TRAFFIC_TYPE_2GFC):
  case (TEN_TRAFFIC_TYPE_2GFC_RA):
  case (TEN_TRAFFIC_TYPE_2GFC_ENH):
  case (TEN_TRAFFIC_TYPE_2GISC):
    cfp_vco_thres = 0x20;  /* default */
    /* GBPS_2__125_FC */
    break;

  case (TEN_TRAFFIC_TYPE_1GFC):
  case (TEN_TRAFFIC_TYPE_1GFC_RA):
  case (TEN_TRAFFIC_TYPE_1GFC_ENH):
  case (TEN_TRAFFIC_TYPE_1GE): /* Bugzilla 38871 */
    cfp_vco_thres = 0x20;  /* default */
    /* GBPS_1__0625_FC */
    break;
    
  default:
    CS_PRINT("traffic=%d not found, using default!\n", traffic);
    cfp_vco_thres = 0x20;
    break;
  }
  
  rtn |= ten_cfp32x1_txvco0_thres0_t41(module_id, slice, 0x01, cfp_vco_thres);
  rtn |= ten_cfp32x1_txvco0_thres1_t41(module_id, slice, 0x01, cfp_vco_thres);

  rtn |= ten_cfp32x1_rxvco0_thres0_t41(module_id, slice, 0x01, cfp_vco_thres);
  rtn |= ten_cfp32x1_rxvco0_thres1_t41(module_id, slice, 0x01, cfp_vco_thres);

  /* Additional Settings */
  /* Bugzilla #18137:  Change default from 2 to 3  */
  rtn |= ten_cfp32x1_rxlockd0_set_stable_period_t41(module_id, slice, 3);
  
  /* Bugzilla #14253, in all cases, overwrite default of 1 to 0. */
  rtn |= ten_cfp32x1_srx0_rx_clkout_ctrl_clkinven_t41(module_id, slice, 0);
  
  if (slice != TEN_SLICE_ALL) {
    rtn |= ten_cfp32x1_rx0_config_bitinv_t41(module_id, slice, rx_bitinv);
    rtn |= ten_cfp32x1_tx0_config_bitinv_t41(module_id, slice, tx_bitinv);
  }
  /* Use bitmask to set bitinv, slice 0 is least significant bit, slice 3 is most signicant bit */
  else {
    for (ii=0; ii<TEN_MAX_SLICES; ii++) {
      rtn |= ten_cfp32x1_rx0_config_bitinv_t41(module_id, ii, (rx_bitinv&(1<<ii)) == (1<<ii));
      rtn |= ten_cfp32x1_tx0_config_bitinv_t41(module_id, ii, (tx_bitinv&(1<<ii)) == (1<<ii));
    } 
  }

  /* Bugzilla #27455, set xfi xlos broadcast */
  rtn |= ten_hsif_misc_xfi_xlos_broadcast(mod_id_b, 1);
  
  /* Analog config settings */
  rtn |= ten_cfp32x1_stx0_tx_output_ctrl_drv_lower_cm_t41(module_id, slice, cfp_stx_tx_output_ctrl_drv_lower_cm);
  rtn |= ten_cfp32x1_stx0_tx_output_ctrl_level_t41(module_id, slice, cfp_stx_tx_output_ctrl_level);
  rtn |= ten_cfp32x1_stx0_tx_output_ctrl_post_peak_t41(module_id, slice, cfp_stx_tx_output_ctrl_post_peak);
  rtn |= ten_cfp32x1_srx0_rx_misc_srx_eqadj_t41(module_id, slice, cfp_srx_rx_misc_srx_eqadj);
  
  /* 7. Initiate coarse tuning.               */
  /* Bugzilla #26217, CFP changes */
  rtn |= ten_cfp32x1_txvco0_control_init_t41(module_id, slice, CS_RESET_TOGGLE);
  rtn |= ten_cfp32x1_rxvco0_control_init_t41(module_id, slice, CS_RESET_TOGGLE);
  
  /* 8. This step is not applicable for CFP */
                                    
  /* 9. Wait for lock.                        */
  if (wait_for_vcotune) {
    if (ten_hl_hsif_cfp_waitfor_vcotune(module_id, slice) != 1) {
      CS_PRINT("ERROR: ten_hl_hsif_cfp_waitfor_vcotune failed, sl=%d\n", slice);
      rtn |= CS_ERROR;
    }
  }
  
  /* Configure GPLL */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
    instance = 9;
  }
  else {
    instance = 1;
  }

  for (ii=0; ii<8; ii++) {
    /* TX/RX GPLL */
    if ((slice == (ii%4)) || (slice == TEN_SLICE_ALL)) {
      ten_hl_gpllx1_init(dev_id, instance+ii, TEN_HL_GPLL_MODE_DEFAULT, 0);
      if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance+ii) != 1) {
        CS_PRINT("ten_hl_gpllx1_waitfor_vcotune FAILED.\n");
        rtn |= CS_ERROR;
      }
    }
  }
 
  /* Bugzilla #25165, toggle resync  */
  rtn |= ten_cfp32x1_rxelst0_control_resync_t41(module_id, slice, 1);
  rtn |= ten_cfp32x1_txelst0_control_resync_t41(module_id, slice, 1);

  rtn |= ten_cfp32x1_rxelst0_control_resync_t41(module_id, slice, 0);
  rtn |= ten_cfp32x1_txelst0_control_resync_t41(module_id, slice, 0);
  
  /* Set-up the receive protection clock */
  if (prot) {
  }
  
RTN_EXIT:
  /* 10.Done, run traffic (after clockmux switch and resets removed in full.pl) */
  CS_PRINT("ten_hl_config_cfp_t41 complete, rtn = ");
  if (rtn == CS_OK) {
    CS_PRINT("CS_OK.\n");
  }
  else {
    CS_PRINT("CS_ERROR.\n");
  }
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  CFP CONFIG CLOCKMUX                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_cfp_config_clockmux(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 aux_clk)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o aux_clk                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure the CLOCKMUX for an CFP interface.                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 mod_num;
  cs_uint16 dev_id;
  CS_PRINT("ten_hl_cfp_config_clockmux, mod_id=0x%04X, sl=%d, aux_clk=%d\n", module_id, slice, aux_clk);
  
  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  
  rtn |= ten_cfp32x1_set_rxlockd0_force_lock_t41(module_id, slice, 0);
  rtn |= ten_cfp32x1_set_rxlockd0_pd_mode_t41(module_id, slice, 0);

  /* Bugzilla #33868 - Set MPIF TXLOCKDET mrb2a */
  if (mod_num == TEN_MODULE_A) {
    rtn |= ten_mpif_set_clock_switch_lockdet_mrb2a(dev_id, slice, CS_TX, CS_ENABLE);
  }
  else {
    rtn |= ten_mpif_set_clock_switch_lockdet_mr(dev_id, TEN_MODULE_B, slice, CS_TX, CS_ENABLE);
  }
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CFP WAIT FOR VCO TUNE            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_hsif_cfp_waitfor_vcotune(cs_uint16 module_id,
                                         cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=locked, 0=NOT locked or CS_ERROR                  */
/* DESCRIPTION:                                                     */
/* Wait for CFP SerDes TX VCOTUNE & RX VCOTUNE & LOCK.              */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2) or TEN_SLICE3 (3).                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii, sl, freq;
  /* Bugzilla #26075, fix compiler warning */
  cs_uint16 locked = 0;
  cs_boolean short_filtpn;
  cs_int16 rtn = 1;
  cs_char8 *func = "ten_hl_hsif_cfp_waitfor_vcotune";  
  
  if (slice < TEN_MAX_SLICES) {
    CS_PRINT("%s()  %s, %s\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice]);
  }
  else if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s()  %s SLICE_ALL\n", func, ten_module_strings[module_id&1]);
  } else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3 or 0xFF.", func, slice);
    return (0);
  }
  

  for (sl=0;sl<TEN_MAX_SLICES;sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {

      /* Check TX */
      for (ii=0; ii<60; ii++) {
        /* check status of SHORT_FILTPNs bit */
        short_filtpn = ten_cfp32x1_txvco0_intstatus_t41(module_id, sl);
        
        /* The tuning process initially sets "SHORT_FILTPN" = ‘1’, */
        /* and clears this bit when the process completes.         */
        if (short_filtpn == 0) {
          /* VCO Tune FREQ value read only for information/debugging */
          freq = ten_cfp32x1_txvco0_status_t41(module_id, sl);
          CS_PRINT("    %02d:CFP TX SERDES, %s VCO Tune Freq = %d\n", ii, ten_slice_strings[sl], freq);
          if (freq == 0x3F) {
            CS_PRINT("    WARNING:  VCO Tuning completed with a FREQ value of 0x3F.\n");
            CS_PRINT("              Divider settings may be misconfigured.\n");
          }
          break;
        }
        else {
          TEN_MDELAY(50);
        }
      }
      CS_PRINT("    %02d:CFP TX SERDES %s, VCO Tune status SHORT_FILTPNs=%d\n", ii, ten_slice_strings[sl], short_filtpn);

      if (short_filtpn) {
        CS_PRINT("    %s:  CFP TX SERDES vco tune failed, %s\n", func, ten_slice_strings[sl]);
        return (0);
      }
      
      /* Check RX */
      for (ii=0; ii<60; ii++) {
        /* check status of SHORT_FILTPNs bit */
        short_filtpn = ten_cfp32x1_rxvco0_intstatus_t41(module_id, sl);

        /* The tuning process initially sets "SHORT_FILTPN" = ‘1’, */
        /* and clears this bit when the process completes.         */
        if (short_filtpn == 0) {
          /* VCO Tune FREQ value read only for information/debugging */
          freq = ten_cfp32x1_rxvco0_status_t41(module_id, sl);
          CS_PRINT("    %02d:CFP RX SERDES, %s VCO Tune Freq = %d\n", ii, ten_slice_strings[sl], freq);
          if (freq == 0x3F) {
            CS_PRINT("    WARNING:  VCO Tuning completed with a FREQ value of 0x3F.\n");
            CS_PRINT("              Divider settings may be misconfigured.\n");
          }
          break;
        }
        else {
          TEN_MDELAY(50);
        }
      }
      CS_PRINT("    %02d:CFP RX SERDES %s, VCO Tune status SHORT_FILTPNs=%d\n", ii, ten_slice_strings[sl], short_filtpn);

      if (short_filtpn) {
        CS_PRINT("    %s:  CFP RX SERDES vco tune failed, %s\n", func, ten_slice_strings[sl]);
        return (0);
      }
      
      /* Check RX lock */
      for (ii=0; ii<5; ii++) {
        locked = ten_cfp32x1_rxlockd0_filt_lock_t41(module_id, sl);
        if (locked) {
          break;
        }
        TEN_MDELAY(6);
      }
      CS_PRINT("    %02d:CFP SERDES, %s, FILT_LOCKs = %d\n", ii, ten_slice_strings[sl], locked);

      if (!locked) {
        /* Can fail for Rx LOS, FILT_LOCK failure is a warning instead of failure */
        CS_PRINT("    WARNING:  Check RX CFP FILT_LOCKs failure, %s\n", ten_slice_strings[sl]);
      }
      rtn &= 1;
    }
  }
  CS_PRINT("%s()      EXIT  rtn=%d\n", func, rtn);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CFP CONTROL POWER T41            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_cfp_control_power_t41(cs_uint16 module_id,
                                            cs_uint8 slice,
                                            cs_ctl_t ctl)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Power Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls CFP Power.                                              */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [ctl]  Power Control                                             */
/*   CS_DISABLE (0) = Set Power DOWN                                */
/*   CS_ENABLE (1)  = Set Power UP.                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, ": ctl out of range.");
    return (CS_ERROR);
  }
  
  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if (ctl == CS_DISABLE) {  /* POWER DOWN */
    /* Select MR disabled */
    rtn |= ten_hsif_provision_tx_xfiselect(module_id, slice, 0);
    rtn |= ten_hsif_provision_rx_xfiselect(module_id, slice, 0);
    rtn |= ten_hsif_provision_mrprotocol(module_id, slice, CS_TX_AND_RX, 0);
  }
  else {
    rtn |= ten_hsif_provision_mrprotocol(module_id, slice, CS_TX_AND_RX, TEN_HSIF_PROTOCOL_CFP);
  }
  
  /* Bugzilla #26217, CFP changes */
  /* Control TX Power */
  rtn |= ten_cfp32x1_stxp0_tx_pd_41(module_id, slice, !ctl);

  /* Bugzilla #28476 - fix CFP MR powerdown, need to power down unused HSIF SERDES lanes/slices */
  if (ctl == CS_DISABLE) {  /* POWER DOWN */
    rtn |= ten_cfp32x1_stxp0_tx_pd_lane_t41(module_id, slice, 0x1F);
  }
  else {  /* POWER UP */
    rtn |= ten_cfp32x1_stxp0_tx_pd_lane_t41(module_id, slice, 0);
  }
  
  /* Control RX Power */
  rtn |= ten_cfp32x1_srx0_rx_srx_pd_t41(module_id, slice, !ctl);

  if (ctl == CS_ENABLE) {
    /* allow settling time for the SERDES to power up before proceeding */
    TEN_MDELAY(10);
  }

  return (rtn);
}
  
/* Bugzilla 26403 Start */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CFP CHECK_KPGA T41               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_cfp_check_kpga_t41 (cs_uint16 module_id, 
                                          cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Checkes status of CFP HSIF KPGA                                  */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  cs_uint32 prbs_count;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_hsif_cfp_check_kpga_t41";  

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3 or 0xFF.", func);
    return (CS_ERROR);
  }
  
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s() SLICE_ALL\n", func);
  } else {  
    CS_PRINT("%s(), %s\n", func, ten_slice_strings[slice]);
  }  


  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      if (ten_cfp32x1_txlockd0_lock_t41 (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s TX not locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_cfp32x1_txlockd0_filt_lock_t41 (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s TX not filt locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_cfp32x1_txlockd0_data_dets_t41 (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s TX data not detected!\n", func, ten_slice_strings[sl]);
      }    

      if (ten_cfp32x1_rxlockd0_lock_t41 (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s RX not locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_cfp32x1_rxlockd0_filt_lock_t41 (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s RX not filt locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_cfp32x1_rxlockd0_data_dets_t41 (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s RX data not detected!\n", func, ten_slice_strings[sl]);
      }
      
      if (!ten_cfp32x1_prbschk_get_status_t41 (module_id, sl)) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s PRBS not in sync!\n", func, ten_slice_strings[sl]);
      }
      
          
      /* Read prbs error count to clear it */
      prbs_count = ten_cfp32x1_rx0_get_prbsck0_count_t41 (module_id, sl);
      
      /* insertonebiterroronce.  Must be a transition from 0 to 1 */
      ten_cfp32x1_prbsgen_control_t41 (module_id, sl, 0, 0, 0, 0);
      ten_cfp32x1_prbsgen_control_t41 (module_id, sl, 0, 0, 0, 1);
      
      prbs_count = ten_cfp32x1_rx0_get_prbsck0_count_t41 (module_id, sl);
      if (prbs_count != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test ERROR: slice %s error count = 0x%X!  it should = 1\n", func, ten_slice_strings[sl], prbs_count);
      }
    }
  }
  return (rtn);  
}
/* Bugzilla 26403 End */

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CFP RETUNE VCO                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_cfp_retune_vco(cs_uint16 module_id, 
                                     cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a VCO retune.                                           */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 instance;
  cs_uint16 base_slice = TEN_SLICE0;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  
  CS_PRINT("ten_hl_hsif_cfp_retune_vco\n");

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE1)) {
    base_slice = TEN_SLICE0;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE3)) {
    base_slice = TEN_SLICE2;
  }
  else {
    CS_PRINT("Not applicable for TEN_SLICE_ALL\n");
  }

  rtn |= ten_cfp32x1_txvco0_control_init_t41(module_id, base_slice, CS_RESET_TOGGLE);
  rtn |= ten_cfp32x1_rxvco0_control_init_t41(module_id, base_slice, CS_RESET_TOGGLE);
  rtn |= ten_cfp32x1_rxvco0_control_init_t41(module_id, base_slice+1, CS_RESET_TOGGLE);
  
  if (ten_hl_hsif_cfp_waitfor_vcotune(module_id, base_slice) != 1) {
   CS_PRINT("WARNING:  first wait for VCO tune failed\n");
  }

  if (ten_hl_hsif_cfp_waitfor_vcotune(module_id, base_slice+1) != 1) {
   CS_PRINT("WARNING:  second wait for VCO tune failed\n");
  }
  
  /* Configure GPLL */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
    instance = 9;
  }
  else {
    instance = 1;
  }

  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice, 1);
  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice, 0);

  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 4, 1);
  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 4, 0);

  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 1, 1);
  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 1, 0);

  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 4 + 1, 1);
  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 4 + 1, 0);
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CFP RETUNE VCO V2                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_cfp_retune_vco_v2(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint8  dyn_repro,
                                        cs_uint16 traffic)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a VCO retune.  Not performed on a dynamic reprovision   */
/* if the traffic type has already been run on this port.           */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [dyn_repro] specifies the type of dynamic reprovisioning:        */
/*   0x00 = TEN_INITIAL_CONFIG                                      */
/*   0x01 = TEN_REPRO_CLIENT                                        */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                               */
/*                                                                  */
/* [traffic]                                                        */
/*   TEN_TRAFFIC_TYPE_NONE = 0                                      */
/*   TEN_TRAFFIC_TYPE_OTU3 = 1                                      */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                     */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                     */
/*   TEN_TRAFFIC_TYPE_ODTU23 = 4                                    */
/*   TEN_TRAFFIC_TYPE_OTU2 = 5                                      */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                     */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                     */
/*   TEN_TRAFFIC_TYPE_OC192 = 8                                     */
/*   TEN_TRAFFIC_TYPE_10GE_WAN = 9                                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2 = 10                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3 = 12                                 */
/*   TEN_TRAFFIC_TYPE_5GB_IB = 18                                   */
/*   TEN_TRAFFIC_TYPE_10GE_6_1 = 26                                 */
/*   TEN_TRAFFIC_TYPE_10GE_TC = 33                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 instance;
  cs_uint16 base_slice = TEN_SLICE0;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 current_traffic;
  
  CS_PRINT("ten_hl_hsif_cfp_retune_vco_v2, mod_id=0x%04X, sl=%d, dyn_repro=%d, traffic=%d\n", module_id, slice, dyn_repro, traffic);

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE1)) {
    base_slice = TEN_SLICE0;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE3)) {
    base_slice = TEN_SLICE2;
  }
  else {
    CS_PRINT("Not applicable for TEN_SLICE_ALL\n");
    return (CS_OK);
  }
  
  if (dyn_repro != TEN_INITIAL_CONFIG) {
    current_traffic = g_pTEN->p_dev_cb_tbl[dev_id]->cfp_current_traffic[slice];
    CS_PRINT("CFP_MR current_traffic = %d, new_traffic=%d\n", current_traffic, traffic);
    if (traffic == current_traffic) {
      CS_PRINT("    current_traffic already matches new traffic, exit\n");
      return (CS_OK);
    }
  }

  rtn |= ten_cfp32x1_txvco0_control_init_t41(module_id, base_slice, CS_RESET_TOGGLE);
  rtn |= ten_cfp32x1_rxvco0_control_init_t41(module_id, base_slice, CS_RESET_TOGGLE);
  rtn |= ten_cfp32x1_rxvco0_control_init_t41(module_id, base_slice+1, CS_RESET_TOGGLE);
  
  if (ten_hl_hsif_cfp_waitfor_vcotune(module_id, base_slice) != 1) {
   CS_PRINT("WARNING:  first wait for VCO tune failed\n");
  }

  if (ten_hl_hsif_cfp_waitfor_vcotune(module_id, base_slice+1) != 1) {
   CS_PRINT("WARNING:  second wait for VCO tune failed\n");
  }
  
  /* Configure GPLL */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
    instance = 9;
  }
  else {
    instance = 1;
  }

  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice, 1);
  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice, 0);

  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 4, 1);
  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 4, 0);

  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 1, 1);
  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 1, 0);

  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 4 + 1, 1);
  rtn |= ten_gpllx1_set_txvco0_init(dev_id, instance + base_slice + 4 + 1, 0);
  
  return (rtn);
}


/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CFP GET CURRENT TRAFFIC          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_hl_hsif_cfp_get_current_traffic(cs_uint16 module_id, 
                                              cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Traffic                                             */
/* DESCRIPTION:                                                     */
/* Returns the current CFP_MR traffic from the control block.       */
/*   TEN_TRAFFIC_TYPE_NONE     = 0                                  */
/*   TEN_TRAFFIC_TYPE_OTU3     = 1                                  */
/*   TEN_TRAFFIC_TYPE_OTU3E    = 2                                  */
/*   TEN_TRAFFIC_TYPE_OTU3P    = 3                                  */
/*   TEN_TRAFFIC_TYPE_ODTU23   = 4                                  */
/*   TEN_TRAFFIC_TYPE_OTU2     = 5                                  */
/*   TEN_TRAFFIC_TYPE_OTU2E    = 6                                  */
/*   TEN_TRAFFIC_TYPE_OTU1F    = 7                                  */
/*   TEN_TRAFFIC_TYPE_OC192    = 8                                  */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11                                 */
/*   TEN_TRAFFIC_TYPE_5GB_IB   = 18                                 */
/*   TEN_TRAFFIC_TYPE_10GE     = 20                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_2 = 27                                 */
/*   TEN_TRAFFIC_TYPE_OTU1E    = 29                                 */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint8 sl;
  cs_uint16 traffic;
  
  CS_PRINT("ten_hl_hsif_cfp_get_current_traffic, mod_id=0x%04X, sl=%d\n", module_id, slice);
  
  if (slice <= TEN_SLICE3) {
    sl = slice;
  }
  else {
    sl = TEN_SLICE0;
  }
  traffic = g_pTEN->p_dev_cb_tbl[dev_id]->cfp_current_traffic[sl];
  CS_PRINT("CPF_MR current traffic = %d\n", traffic);
  return (traffic);
}


