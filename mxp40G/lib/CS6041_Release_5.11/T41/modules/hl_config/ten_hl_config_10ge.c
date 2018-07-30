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
 * API's for high level 10ge client configuration.
 *
 * $Id: ten_hl_config_10ge.c,v 1.32 2013/05/01 14:37:17 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE6_2 ODTU23             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge6_2_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> CBR10G G.Sup43.6.2 ->        */
/* (ODU2 -> ODTU23 -> OTU3/3e/3p2                               */
/* Assigns ODTU on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides.                       */
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
/* [slice_client] specifies client's slice:                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1,                               */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2,                               */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3.                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25.                              */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* Bugzilla 24628 Start */
  ten_dev_cb_t *pdevcb;
  /* Bugzilla 24628 End */
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;

  /* Bugzilla 24628 Start */
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  /* Bugzilla 24628 End */

  CS_PRINT("ten_hl_config_10ge6_2_odtu: 0x%X, %d, 0x%X, %d, dyn=%d, %d, %d\n",
            module_id_line, slice_line, module_id_client, slice_client, 
            dyn_repro, line, sysclk);

  if ((line != TEN_TRAFFIC_TYPE_OTU3)  && (line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (line != TEN_TRAFFIC_TYPE_OTU3P) && (line != TEN_TRAFFIC_TYPE_OTU3P2)) {
     CS_PRINT("ERROR: config_10ge_odtu23: will not carry 10GE G.Sup43 6.2 traffic");
     return (CS_ERROR);
  }
  
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OXU3_10GE, TEN_N10G_TX_10GE_OXU3, dyn_repro);
  
  /* Payload Type */
  /*rtn |= ten_n10g_otnt_set_pti_byte(module_id, slice, 3);*/
  /*rtn |= ten_n10g_set_expected_pti_byte(module_id, slice, 3);*/

  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling (module_id_line, slice_line, 0, 0); 
  rtn |= ten_n10g_otnr_descrambling (module_id_line, slice_line, 0, 0); 
  
  /* Bugzilla 24628 Start */
  /* Provision Fixed Stuff and C15 bytes */
  if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2122, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 3083, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 0);
  }
  else { /* TEN_TRAFFIC_TYPE_OTU3P */
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2121, 0);
  }
  /* Bugzilla 24628 End */
  
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0); 

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_GFP_S, TEN_PP10G_TX_GFP_S);
  
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH0_GFP_S, TEN_PP10G_TX_XAUI_GFP_S_ETH0);
  }
  else {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH0_GFP_S, TEN_PP10G_TX_GFP_S_ETH0);
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  /* cfg1.2 */
  }
  
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_6_2, 1);

  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line,
           (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_6_2);
  
  rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                         0x1,   /* idle_all   */
                                         0x0,   /* frames_all */
                                         0x1,   /* client_all */
                                         0x1,   /* seq_os_all */
                                         0x0,   /* seq_os_2nd */
                                         0x0);  /* fc_idle    */
             
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                         0x1,  /* idle_all   */
                                         0x1,  /* frames_all */ 
                                         0x1,  /* client_all */ 
                                         0x1,  /* seq_os_all */ 
                                         0x0,  /* seq_os_2nd */ 
                                         0x0); /* fc_idle    */
             
  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
             0x7,  /* map_idle_all   */ 
             0x0); /* map_seq_os_2nd */

  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_client, slice_client, 7);

  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_line, slice_line, 7);

  rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, slice_client, 2);
             
  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  rtn |= ten_n10g_otnr_set_g43md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_g43md(module_id_line, slice_line, 0);
  
   /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line, slice_line, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line, slice_line, 0);

  /* Bugzilla 24628 Start */
  /* Use just 1 PJO because deterministic justification is being used */
  rtn |= ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  rtn |= ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 1);
  rtn |= ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 0);
  rtn |= ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);

  if (pdevcb) {
    /* Configure deterministic justification */
    rtn |= ten_n40g_otnt4x_set_dthyst (module_id_line, slice_line, pdevcb->syncdsync_cb.hysteresis);
  }
  else {
    rtn = CS_ERROR;
  }
  /* Bugzilla 24628 End */

  return (rtn);
}                                                                    

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE6_1-ALT ODTU23         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge6_1_alt_odtu23(cs_uint16 module_id_line,
                                           cs_uint8  slice_line,
                                           cs_uint16 module_id_client,
                                           cs_uint8  slice_client,
                                           cs_uint8  dyn_repro,
                                           cs_uint16 line,
                                           cs_uint16 sysclk,
                                           cs_uint16 flow_ctrl_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Sysclk                                        */
/*              o Flow Control Mode                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> CBR10G G.Sup43.6.1 ->        */
/* (ODU2 -> ODTU23 -> OTU3/3e/3p2                               */
/* Assigns ODTU on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides.                       */
/* Uses alternative ETH4 method.                                */
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
/* [slice_client] specifies client's slice:                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1,                               */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2,                               */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3,                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25.                              */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* The [flow_ctrl_mode] parameter is specified as:              */
/*   TEN_PP10G_FLOW_ETH_4   (Reactive)              = 2,        */
/*   TEN_PP10G_FLOW_ETH_4_P (Preemptive)            = 3.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* Bugzilla 24628 Start */
  ten_dev_cb_t *pdevcb;
  /* Bugzilla 24628 End */
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_config_10ge6_1_alt_odtu23: 0x%X, %d, 0x%X, %d, dyn=%d, line=%d, sysclk=%d, flow=%d\n",
            module_id_line, slice_line, module_id_client, slice_client, 
            dyn_repro, line, sysclk, flow_ctrl_mode);

  /* Bugzilla 24628 Start */
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  /* Bugzilla 24628 End */

  if ((line != TEN_TRAFFIC_TYPE_OTU3)  && (line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (line != TEN_TRAFFIC_TYPE_OTU3P) && (line != TEN_TRAFFIC_TYPE_OTU3P2)) {
     CS_PRINT("ERROR: config_10ge_odtu23: will not carry 10GE G.Sup43 6.1 traffic");
     return (CS_ERROR);
  }

  if ((flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && 
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P)) {
     CS_PRINT("ERROR: flow control either TEN_PP10G_FLOW_ETH_4 or TEN_PP10G_FLOW_ETH_4_P.");
     return (CS_ERROR);
  }
  
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, 
                     TEN_N10G_RX_OXU3_192_10GE, 
                     TEN_N10G_TX_10GE_192_OXU3, dyn_repro);
  
  /* Bugzilla 24628 Start */
  /* Provision Fixed Stuff and C15 bytes */
  if (line == TEN_TRAFFIC_TYPE_OTU3P) {
    /*  rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0x849, 0x0);*/
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2121, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2122, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 3083, 0);
  }
  /* Bugzilla 24628 End */
  /* Bugzilla 20308 End */
  
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, 
                            TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
  }
  else {
   rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
   /* Bugzilla #22850, fix bus errors */
   rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  
  }                        
      
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_line, slice_line, sysclk * 125);  

  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling(module_id_line, slice_line, 0, 0);
  rtn |= ten_n10g_otnr_descrambling(module_id_line, slice_line, 0, 0);
  
  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, 
                                TEN_TRAFFIC_TYPE_10GE_6_1, 1);
                               
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x7F);
                            
  /* Set TDELON/TDELOFF for 3ms */
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 492*239/255, 492*239/255);
  rtn |= ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(module_id_line, 495, 495);

  /* Set STM 64 */
  rtn |= ten_n10g_otnr_set_stm64md(module_id_line, slice_line, 1);
  rtn |= ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 1);

  /* Configure XCON */
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
                           (module_id_client & 1) * 4 + slice_client, 
                            TEN_TRAFFIC_TYPE_10GE_6_1); 
                            
  /* cfg_xaui_b_lan2wan */
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                           0x1,  /* idle_all   */
                                           0x0,  /* frames_all */ 
                                           0x1,  /* client_all */ 
                                           0x0,  /* seq_os_all */ 
                                           0x1,  /* seq_os_2nd */ 
                                           0x0); /* fc_idle    */
                                           
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_client, slice_client, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_client, slice_client, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_pause_en(module_id_client, slice_client, 0, 1);
    
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                           0x0,   /* idle_all   */
                                           0x0,   /* frames_all */
                                           0x1,   /* client_all */
                                           0x0,   /* seq_os_all */
                                           0x0,   /* seq_os_2nd */
                                           0x0);  /* fc_idle    */
                                           
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_line, slice_line, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_line, slice_line, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

    rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
                                            0x7,  /* map_idle_all   */ 
                                            0x0); /* map_seq_os_2nd */

    rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_client, slice_client, 7);
    rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_line,   slice_line,   7);

    rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, slice_client, 2);
  }                       

  /* Flow control settings in the Ingress direction */
  rtn |= ten_hl_pp10g_flow_init(module_id_client, slice_client, flow_ctrl_mode);
  
  /* Disable Deskew function aligning 4 incoming stream by FP since not full aggr */
  if (ten_n40g_set_dsbldskw(module_id_line, 1) != CS_OK) {
    CS_PRINT("Failed to set DSBLDSKW bit");
    rtn = CS_ERROR;
  }

  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  /* Bugzilla 24628 Start */
  /* Use just 1 PJO because deterministic justification is being used */
  rtn |= ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  rtn |= ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 1);
  rtn |= ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 0);
  rtn |= ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);
  
  /* Bugzilla 24492 - Need a larger IPG for 64-9600 random frame settings */
  ten_pp10g_xgadj_rx_rate_control3(module_id_client, slice_client, 7);

  if (pdevcb) {
    /* Configure deterministic justification */
    rtn |= ten_n40g_otnt4x_set_dthyst (module_id_line, slice_line, pdevcb->syncdsync_cb.hysteresis);
  }
  else {
    rtn = CS_ERROR;
  }
  /* Bugzilla 24628 End */
  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE6_1 ODTU23             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge6_1_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk,
                                       cs_uint16 flow_ctrl_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Sysclk                                        */
/*              o Flow Control Mode                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> CBR10G G.Sup43.6.1 ->        */
/* (ODU2 -> ODTU23 -> OTU3/3e/3p2                               */
/* Assigns ODTU on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides.                       */
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
/* [slice_client] specifies client's slice:                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1,                               */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2,                               */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3,                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25.                              */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* The [flow_ctrl_mode] parameter is specified as:              */
/*   TEN_PP10G_FLOW_ETH_4 (Reactive)                 = 2,       */
/*   TEN_PP10G_FLOW_ETH_4_P (Pre-emptive)            = 3.       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* Bugzilla 24628 Start */
  ten_dev_cb_t *pdevcb;
  /* Bugzilla 24628 End */
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_config_10ge6_1_odtu23: 0x%X, %d, 0x%X, %d, dyn=%d, line=%d, sysclk=%d, flow=%d\n",
            module_id_line, slice_line, module_id_client, slice_client, 
            dyn_repro, line, sysclk, flow_ctrl_mode);

  /* Bugzilla 24628 Start */
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  /* Bugzilla 24628 End */

  if ((line != TEN_TRAFFIC_TYPE_OTU3)  && (line != TEN_TRAFFIC_TYPE_OTU3E) &&
      (line != TEN_TRAFFIC_TYPE_OTU3P) && (line != TEN_TRAFFIC_TYPE_OTU3P2)) {
     CS_PRINT("ERROR: config_10ge_odtu23: will not carry 10GE G.Sup43 6.1 traffic");
     return (CS_ERROR);
  }

  if ((flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && 
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P)) {
     CS_PRINT("ERROR: flow control either TEN_PP10G_FLOW_ETH_4 or TEN_PP10G_FLOW_ETH_4_P.");
     return (CS_ERROR);
  }
  
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, 
                     TEN_N10G_RX_OXU3_192_10GE, 
                     TEN_N10G_TX_10GE_192_OXU3, dyn_repro);
  
  /* Bugzilla 24628 Start */
  /* Provision Fixed Stuff and C15 bytes */
  if (line == TEN_TRAFFIC_TYPE_OTU3P) {
    /*  rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0x849, 0x0);*/
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2121, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2122, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 3083, 0);
  }
  /* Bugzilla 24628 End */
  /* Bugzilla 20308 End */
  
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, 
                            TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
  }
  else {
   rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
   /* Bugzilla #22850, fix bus errors */
   rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  
  }                        
      
  /* Bugzilla #24492, use ETH2 method */
  rtn |= ten_hl_pp10g_tx_init(module_id_client, slice_client, TEN_PP10G_TX_ETH_2);
      
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_line, slice_line, sysclk * 125);  

  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling(module_id_line, slice_line, 0, 0);
  rtn |= ten_n10g_otnr_descrambling(module_id_line, slice_line, 0, 0);
  
  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, 
                                TEN_TRAFFIC_TYPE_10GE_6_1, 1);
                               
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x7F);
                            
  /* Set TDELON/TDELOFF for 3ms */
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 492*239/255, 492*239/255);
  rtn |= ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(module_id_line, 495, 495);

  /* Set STM 64 */
  rtn |= ten_n10g_otnr_set_stm64md(module_id_line, slice_line, 1);
  rtn |= ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 1);

  /* Configure XCON */
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
                           (module_id_client & 1) * 4 + slice_client, 
                            TEN_TRAFFIC_TYPE_10GE_6_1); 
                            
  /* cfg_xaui_b_lan2wan */
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                           0x1,  /* idle_all   */
                                           0x0,  /* frames_all */ 
                                           0x1,  /* client_all */ 
                                           0x0,  /* seq_os_all */ 
                                           0x1,  /* seq_os_2nd */ 
                                           0x0); /* fc_idle    */
                                           
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_client, slice_client, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_client, slice_client, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_pause_en(module_id_client, slice_client, 0, 1);
    
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                           0x0,   /* idle_all   */
                                           0x0,   /* frames_all */
                                           0x1,   /* client_all */
                                           0x0,   /* seq_os_all */
                                           0x0,   /* seq_os_2nd */
                                           0x0);  /* fc_idle    */
                                           
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_line, slice_line, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_line, slice_line, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

    rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
                                            0x7,  /* map_idle_all   */ 
                                            0x0); /* map_seq_os_2nd */

    rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_client, slice_client, 7);
    rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_line,   slice_line,   7);

    rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, slice_client, 2);
  }                       

  /* Flow control settings in the Ingress direction */
  rtn |= ten_hl_pp10g_flow_init(module_id_client, slice_client, flow_ctrl_mode);
  
  /* Disable Deskew function aligning 4 incoming stream by FP since not full aggr */
  if (ten_n40g_set_dsbldskw(module_id_line, 1) != CS_OK) {
    CS_PRINT("Failed to set DSBLDSKW bit");
    rtn = CS_ERROR;
  }

  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  /* Bugzilla 24628 Start */
  /* Use just 1 PJO because deterministic justification is being used */
  rtn |= ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  rtn |= ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 1);
  rtn |= ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 0);
  rtn |= ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);

  /* Bugzilla #24492 - Use ETH2 method */
  rtn |= ten_pp10g_mac_tx_pause_xoff_delay(module_id_client, slice_client, 6);
  rtn |= ten_pp10g_mac_tx_pause_quanta(module_id_client, slice_client, 128);
  
  rtn |= ten_pp10g_mac_rx_set_profile(module_id_line, slice_line, 2);
  rtn |= ten_pp10g_xgadj_rx_control(module_id_line, slice_line, 0, 2, 2); 
  rtn |= ten_pp10g_rs_rx_profile(module_id_line, slice_line, 2);
  rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_client, slice_client, 5);
  
  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_client, slice_client, 0, 0);
  
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, 
                                         TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x03FF);
                                         
  if (pdevcb) {
    /* Configure deterministic justification */
    rtn |= ten_n40g_otnt4x_set_dthyst (module_id_line, slice_line, pdevcb->syncdsync_cb.hysteresis);
  }
  else {
    rtn = CS_ERROR;
  }
  /* Bugzilla 24628 End */
  
  return (rtn);
}
  
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE GFPF OC192 ODTU23     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge_gfpf_oc192_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> CBR10G G.Sup43.6.2 ->        */
/* (ODU2 -> ODTU23 -> OTU3/3e/3p2                               */
/* Assigns ODTU on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides.                       */
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
/* [slice_client] specifies client's slice:                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2,                               */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3.                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25.                              */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10ge_gfpf_oc192_odtu23: 0x%X, %d, 0x%X, %d, dyn=%d, %d, %d\n",
            module_id_line, slice_line, module_id_client, slice_client, 
            dyn_repro, line, sysclk);

  if ((line != TEN_TRAFFIC_TYPE_OTU3E) && (line != TEN_TRAFFIC_TYPE_OTU3P) && (line != TEN_TRAFFIC_TYPE_OTU3P2)) {
     CS_PRINT("ERROR: ten_hl_config_10ge_gfpf_oc192_odtu23: will not carry 10ge gfpf oc192 odu2 traffic");
     return (CS_ERROR);
  }

  /*rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OXU3_10GE, TEN_N10G_TX_10GE_OXU3, dyn_repro);*/
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OXU3_192_10GE,TEN_N10G_TX_10GE_192_OXU3, dyn_repro);
  /*set_N10G_MODE_TX($ch_A, N10G_10GE_192_OXU3);*/
  /*set_N10G_MODE_RX($ch_A, N10G_OXU3_192_10GE);*/

  /*WRPCFG3_STM64MD = 1*/
  /* Bugzilla #22743 */
  rtn |= ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 1); 

  /* Set TDELON/TDELOFF for 3ms */
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 492*239/255, 492*239/255);
  rtn |= ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(module_id_line, 495, 495);

  /* Payload Type */
  /*rtn |= ten_n10g_otnt_set_pti_byte(module_id, slice, 3);*/
  /*rtn |= ten_n10g_set_expected_pti_byte(module_id, slice, 3);*/
  
  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling (module_id_line, slice_line, 0, 0); 
  rtn |= ten_n10g_otnr_descrambling (module_id_line, slice_line, 0, 0); 
  
  /* Set OTU3 Fixed Stuff and C15s */
  if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 2); 
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    /* Bugzilla 24628 Start */
    /* rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 3083, 0); */
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 1244, 0); 
    /* Bugzilla 24628 End */ 
  }
  else { /* TEN_TRAFFIC_TYPE_OTU3P */
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 4); 
  }
  
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0); 

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_GFP_S, TEN_PP10G_TX_GFP_S);
  
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH0_GFP_S, TEN_PP10G_TX_XAUI_GFP_S_ETH0);
  }
  else {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH0_GFP_S, TEN_PP10G_TX_GFP_S_ETH0);
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);
  }
  
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  /* Bugzilla #19353, fix bus errors */
  
  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2, 1);

  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line,
           (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2);

  rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                         0x1,   /* idle_all   */
                                         0x0,   /* frames_all */
                                         0x1,   /* client_all */
                                         0x1,   /* seq_os_all */
                                         0x0,   /* seq_os_2nd */
                                         0x0);  /* fc_idle    */
             
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                         0x1,  /* idle_all   */
                                         0x1,  /* frames_all */ 
                                         0x1,  /* client_all */ 
                                         0x1,  /* seq_os_all */ 
                                         0x0,  /* seq_os_2nd */ 
                                         0x0); /* fc_idle    */
             
  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
             0x7,  /* map_idle_all   */ 
             0x0); /* map_seq_os_2nd */

  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_client, slice_client, 7);

  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_line, slice_line, 7);

  rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, slice_client, 2);
             
  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  rtn |= ten_n10g_otnr_set_g43md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_g43md(module_id_line, slice_line, 0);
  
   /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line, slice_line, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line, slice_line, 0);

  /* Bugzilla 21279 Start */

  /* Bugzilla #24441, fix line/client consistency */
  ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  if ((line == TEN_TRAFFIC_TYPE_OTU3E) || (line == TEN_TRAFFIC_TYPE_OTU3P2)) {
    ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 0);
  }
  else {
    ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 1);
  }

  ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);
  ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);
  /* Bugzilla 21279 End */
  
  return (rtn);
}                                                                    
/* Bugzilla 20308 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE7_1 ODTU23             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge7_1_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> CBR10G G.Sup43.7.1 ->        */
/* (ODU2e -> ODTU23 -> OTU3+/3e/3p2 (not OTU3)                  */
/* Assigns ODTU on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides.                       */
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
/* [slice_client] specifies client's slice:                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2,                                */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3,                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25.                              */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10ge7_1_odtu: 0x%X, %d, 0x%X, %d, dyn=%d, %d, %d\n",
            module_id_line, slice_line, module_id_client, slice_client, 
            dyn_repro, line, sysclk);

  /* Bugzilla 20308 Start */
  if ((line != TEN_TRAFFIC_TYPE_OTU3E) && (line != TEN_TRAFFIC_TYPE_OTU3P) && (line != TEN_TRAFFIC_TYPE_OTU3P2)) {
  /* Bugzilla 20308 Start */
     CS_PRINT("ERROR: config_10ge_odtu23: will not carry 10GE G.Sup43 7.1 traffic");
     return (CS_ERROR);
  }
  
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OXU3_ODU2E_10GE, TEN_N10G_TX_10GE_ODU2E_OXU3J, dyn_repro);
  
  /* Bugzilla #20657, regression fixes */
  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling (module_id_line, slice_line, 0, 0); 
  rtn |= ten_n10g_otnr_descrambling (module_id_line, slice_line, 0, 0); 
  
  /* Bugzilla #20657, regression fixes */
  if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 2); 
  }
  /* Bugzilla 20308 Start */
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 992, 0);
  }
  /* Bugzilla 20308 End */
  else { /* TEN_TRAFFIC_TYPE_OTU3P */
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 4); 
  }
  
  /* Bugzilla 20308 Start */
  /* Enable JC Plus for this slice */
    rtn |= ten_n10g_otnt_set_jc_odtu23(module_id_line, slice_line, 1, 0, 1);
    rtn |= ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
    rtn |= ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 1);
  /* Bugzilla 20308 End */

  /* Bugzilla 21279 Start */
  ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);
  ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);
  /* Bugzilla 21279 End */

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0); 

   if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4, TEN_PP10G_TX_ETH_4);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
     
    /* idle_all=1, frame_all=0, client_all=1, seq_os_all=0,seq_os_2nd=1,fc_idle=0 */
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 1,0,1,0,1,0);
    /* map_frames_all=0  ,map_client_all_hi= 4  , map_client_all_lo=3 */
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_client, slice_client, 0,4,3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_client, slice_client, 1,1,1,1,1,1);

    /* idle_all=0, frame_all=0, client_all=1, seq_os_all=0,seq_os_2nd=0,fc_idle=0 */
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line,0,0,1,0,0,0);
    /* map_frames_all=0  ,map_client_all_hi= 4  , map_client_all_lo=3 */
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_line, slice_line,0,4,3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_line, slice_line,1,1,1,1,1,1);
  }
  else {
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE); 
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE);
    
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  
  }
  
  /* Bugzilla #19353, fix bus errors */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_7_1, 1);
  
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
           (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_7_1);
  
  return (rtn);
}

/* Bugzilla 20308 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE7_2 ODTU23             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge7_2_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> CBR10G G.Sup43.7.2 ->        */
/* (ODU1e -> ODTU23 -> OTU3+/3e/3p2 (not OTU3)                  */
/* Assigns ODTU on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides.                       */
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
/* [slice_client] specifies client's slice:                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3E  = 2,                               */
/*   TEN_TRAFFIC_TYPE_OTU3P  = 3,                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25.                              */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10ge7_2_odtu: 0x%X, %d, 0x%X, %d, dyn=%d, %d, %d\n",
            module_id_line, slice_line, module_id_client, slice_client, 
            dyn_repro, line, sysclk);

  if ((line != TEN_TRAFFIC_TYPE_OTU3E) && (line != TEN_TRAFFIC_TYPE_OTU3P) && (line != TEN_TRAFFIC_TYPE_OTU3P2)) {
     CS_PRINT("ERROR: config_10ge_odtu23: will not carry 10GE G.Sup43 7.2 traffic");
     return (CS_ERROR);
  }
  
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OXU3_ODU2E_10GE, TEN_N10G_TX_10GE_ODU2E_OXU3J, dyn_repro);
  
  /* Disable STM64 */
  rtn |= ten_n10g_otnr_set_stm64md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 0);
  
  /*     ODWCFG_JC_PLUS*/
  
  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling (module_id_line, slice_line, 0, 0); 
  rtn |= ten_n10g_otnr_descrambling (module_id_line, slice_line, 0, 0); 
  
  if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 2); 
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 1244, 0);
  }
  else { /* TEN_TRAFFIC_TYPE_OTU3P */
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 4); 
  }
  
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0); 

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE); 
 
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
  }
  else {
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE); 
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_DISABLE);

    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  
  }
  
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_7_2, 1);
  
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
           (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_7_2);

  /* Bugzilla 21279 Start */
  
  /* Bugzilla #24441, fix line/client consistency */
  ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 1);
  
  ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);
  ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);
  /* Bugzilla 21279 End */

  CS_PRINT("ten_hl_config_10ge7_2_odtu() return =  %d\n", rtn);
  return (rtn);
}
/* Bugzilla 20308 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE7_3 ODTU23             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge7_3_odtu23(cs_uint16 module_id_line,
                                  cs_uint8  slice_line,
                                  cs_uint16 module_id_client,
                                  cs_uint8  slice_client,
                                  cs_uint8  dyn_repro,
                                  cs_uint16 line,
                                  cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> Transparent                  */
/* GFP-F G.Sup43.7.3 -> ODU2 -> ODTU23 -> OTU3/3+/3e            */
/* Assigns ODTU on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides.                       */
/*                                                              */
/* [module_id_line]  specifies line's module ID                 */ 
/*                                                              */
/* [slice_line]  specifies line's slice:                        */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client]  specifies the client's module ID         */
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
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3 = 1,                                 */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2,                                */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3.                                */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25.                              */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* Bugzilla 24628 Start */
  ten_dev_cb_t *pdevcb;
  /* Bugzilla 24628 End */
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;

  /* Bugzilla 24628 Start */
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  /* Bugzilla 24628 End */

  CS_PRINT("config_10ge7_3_odtu23 0x%X, %d, 0x%X, %d, dyn=%d, %d %d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           line, sysclk);

  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OXU3_10GE, TEN_N10G_TX_10GE_OXU3, dyn_repro);
  
    
  /* Bugzilla #20657, regression fixes */
  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling (module_id_line, slice_line, 0, 0); 
  rtn |= ten_n10g_otnr_descrambling (module_id_line, slice_line, 0, 0); 

  /* Bugzilla 24628 Start */
  /* Provision Fixed Stuff and C15 bytes */
  if (line == TEN_TRAFFIC_TYPE_OTU3P) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2121, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2122, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 3083, 0);
  }
  /* Bugzilla 24628 End */
  /* Bugzilla 20308 End */
  
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_GFP_T, TEN_PP10G_TX_GFP_T);
 
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH2_GFP_T, TEN_PP10G_TX_XAUI_GFP_T_ETH2);
  }
  else {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH2_GFP_T, TEN_PP10G_TX_GFP_T_ETH2);
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  
  }

  /* Bugzilla #19353, fix bus errors */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_7_3, 1);
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
           (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_7_3);


  rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_client, slice_client, 0x8);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

  /* Bugzilla #20519, change rate adjust policies   */
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                         0x1,       /* idle_all   */
                                         0x0,       /* frames_all */
                                         0x1,       /* client_all */
                                         0x0,       /* seq_os_all */
                                         0x0,       /* seq_os_2nd */
                                         0x0);      /* fc_idle    */
  
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                         0x1,       /* idle_all   */
                                         0x1,       /* frames_all */
                                         0x1,       /* client_all */
                                         0x1,       /* seq_os_all */
                                         0x0,       /* seq_os_2nd */
                                         0x0);      /* fc_idle    */
                                                    
  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
                                          0x7,      /* map_idle_all   */ 
                                          0x0);     /* map_seq_os_2nd */
 
 /* Bugzilla #20519, change rate adjust policies   */
  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_client, slice_client, 
                                          0x7,      /* map_idle_all   */ 
                                          0x0);     /* map_seq_os_2nd */
 
  rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, 
                                                         slice_client, 2);
 
  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);


  /* Bugzilla 24628 Start */
  /* Use just 1 PJO because deterministic justification is being used */
  rtn |= ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  rtn |= ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 1);
  rtn |= ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 0);
  rtn |= ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);

  if (pdevcb) {
    /* Configure deterministic justification */
    rtn |= ten_n40g_otnt4x_set_dthyst (module_id_line, slice_line, pdevcb->syncdsync_cb.hysteresis);
  }
  else {
    rtn = CS_ERROR;
  }
  /* Bugzilla 24628 End */

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE7_3 OTU2               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge7_3_otu2(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> Transparent                  */
/* GFP-F G.Sup43.7.3 -> OTU2.                                   */
/* Assigns OTU2 on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides. (Ported from cfg35d). */
/*                                                              */
/* [module_id_line]  specifies line's module ID                 */ 
/*                                                              */
/* [slice_line]  specifies line's slice:                        */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client]  specifies the client's module ID         */
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
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("config_10ge7_3_otu2: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk);
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2_10GE, TEN_N10G_TX_10GE_OTU2, dyn_repro);

  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0xFF);  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_GFP_T, TEN_PP10G_TX_GFP_T);

  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH2_GFP_T, TEN_PP10G_TX_XAUI_GFP_T_ETH2);
  }
  else {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH2_GFP_T, TEN_PP10G_TX_GFP_T_ETH2);
    
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  /* cfg1.2 */
  }

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_7_3, 1);
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
           (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_7_3);

  rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

  /* Bugzilla #20519, change rate adjust policies   */
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line,
                                         0x1,   /* idle_all   */
                                         0x0,   /* frames_all */
                                         0x1,   /* client_all */
                                         0x0,   /* seq_os_all */
                                         0x0,   /* seq_os_2nd */
                                         0x0);  /* fc_idle    */
  
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                         0x1,   /* idle_all   */
                                         0x1,   /* frames_all */
                                         0x1,   /* client_all */
                                         0x1,   /* seq_os_all */
                                         0x0,   /* seq_os_2nd */
                                         0x0);  /* fc_idle    */
  
  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
                                          0x7,    /* map_idle_all   */ 
                                          0x0);   /* map_seq_os_2nd */
                                          
  /* Bugzilla #20519, change rate adjust policies   */
  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_client, slice_client, 
                                          0x7,      /* map_idle_all   */ 
                                          0x0);     /* map_seq_os_2nd */
 
  rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, 
                                                         slice_client, 2);
  
  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  rtn |= ten_n10g_otnr_set_g43md(module_id_line, slice_line, 1);
  rtn |= ten_n10g_otnt_set_g43md(module_id_line, slice_line, 1);

  /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line, slice_line, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line, slice_line, 0);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE6_2 OTU2               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge6_2_otu2(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> GFP-S G.Sup43.6.2 -> OTU2    */
/* Assigns OTU2 on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides. (Ported from cfg35d)  */
/*                                                              */
/* [module_id_line]  specifies line's module ID                 */ 
/*                                                              */
/* [slice_line]  specifies line's slice:                        */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client]  specifies the client's module ID         */
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
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10ge6_2_otu2: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk);
     
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2_10GE, TEN_N10G_TX_10GE_OTU2, dyn_repro);
  
  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0xFF);  

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_GFP_S, TEN_PP10G_TX_GFP_S);
  
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH0_GFP_S, TEN_PP10G_TX_XAUI_GFP_S_ETH0);
  }
  else {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH0_GFP_S, TEN_PP10G_TX_GFP_S_ETH0);
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  /* cfg1.2 */
  }
  
  /* Bugzilla #19353, fix bus errors */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_6_2, 1);
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line,
           (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_6_2);

  rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

  /* Bugzilla #20519, change rate adjust policies   */
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                         0x1,   /* idle_all   */
                                         0x0,   /* frames_all */
                                         0x1,   /* client_all */
                                         0x1,   /* seq_os_all */
                                         0x0,   /* seq_os_2nd */
                                         0x0);  /* fc_idle    */
             
  /* Bugzilla #20519, change rate adjust policies   */
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                         0x1,  /* idle_all   */
                                         0x1,  /* frames_all */ 
                                         0x1,  /* client_all */ 
                                         0x1,  /* seq_os_all */ 
                                         0x0,  /* seq_os_2nd */ 
                                         0x0); /* fc_idle    */
             
  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
             0x7,  /* map_idle_all   */ 
             0x0); /* map_seq_os_2nd */

  /* Bugzilla #20519, change rate adjust policies   */
  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_client, slice_client, 7);

  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_line, slice_line, 7);

  rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, slice_client, 2);
             
  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  rtn |= ten_n10g_otnr_set_g43md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_g43md(module_id_line, slice_line, 0);
  
   /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line, slice_line, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line, slice_line, 0);
  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE6_1 ALT OTU2           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge6_1_alt_otu2(cs_uint16 module_id_line,
                                         cs_uint8  slice_line,
                                         cs_uint16 module_id_client,
                                         cs_uint8  slice_client,
                                         cs_uint8  dyn_repro,
                                         cs_uint16 sysclk,
                                         cs_uint16 flow_ctrl_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/*              o Flow Control Mode                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> GFP-S G.Sup43.6.1 -> OTU2    */
/* Assigns OTU2 on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides. (Ported from cfg35d)  */
/* Uses alternate ETH4 method.                                  */
/*                                                              */
/* [module_id_line]  specifies line's module ID                 */ 
/*                                                              */
/* [slice_line]  specifies line's slice:                        */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client]  specifies the client's module ID         */
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
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* The [flow_ctrl_mode] parameter is specified as:              */
/*   TEN_PP10G_FLOW_ETH_4 (Reactive)               = 2,         */
/*   TEN_PP10G_FLOW_ETH_4_P (Premptive)            = 3.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10ge6_1_alt_otu2: 0x%X, %d, 0x%X, %d, dyn=%d, sysclk=%d, flow=%d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk, flow_ctrl_mode);
     
  if ((flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && 
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P)) {
     CS_PRINT("ERROR: flow control either TEN_PP10G_FLOW_ETH_4 or TEN_PP10G_FLOW_ETH_4_P.");
     return (CS_ERROR);
  }
    
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, 
                           TEN_N10G_RX_OTU2_OC192_10GE, 
                           TEN_N10G_TX_10GE_OC192_OTU2, dyn_repro);
                           
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, 
                           TEN_N10G_RX_BYPASS,
                           TEN_N10G_TX_BYPASS, 0);
                           
  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
  }
  else {
   rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  
  }                        
   
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_line, slice_line, sysclk * 125);  

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, 
                                TEN_TRAFFIC_TYPE_10GE_6_1, 1);
                               
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x7F);
                            
  /* Set TDELON/TDELOFF for 3ms */
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 492, 492);

  /* Configure XCON */
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
                           (module_id_client & 1) * 4 + slice_client, 
                            TEN_TRAFFIC_TYPE_10GE_6_1); 
  
  /* cfg_xaui_b_lan2wan */
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                           0x1,  /* idle_all   */
                                           0x0,  /* frames_all */ 
                                           0x1,  /* client_all */ 
                                           0x0,  /* seq_os_all */ 
                                           0x1,  /* seq_os_2nd */ 
                                           0x0); /* fc_idle    */
                                           
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_client, slice_client, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_client, slice_client, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_pause_en(module_id_client, slice_client, 0, 1);
    
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                           0x0,   /* idle_all   */
                                           0x0,   /* frames_all */
                                           0x1,   /* client_all */
                                           0x0,   /* seq_os_all */
                                           0x0,   /* seq_os_2nd */
                                           0x0);  /* fc_idle    */
                                           
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_line, slice_line, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_line, slice_line, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

    rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
                                            0x7,  /* map_idle_all   */ 
                                            0x0); /* map_seq_os_2nd */

    rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_client, slice_client, 7);
    rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_line,   slice_line,   7);

    rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, slice_client, 2);
  }
  /* Flow control settings in the Ingress direction */
  rtn |= ten_hl_pp10g_flow_init(module_id_client, slice_client, flow_ctrl_mode);
  
  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  /* Bugzilla 24492 - Need a larger IPG for 64-9600 random frame settings */
  ten_pp10g_xgadj_rx_rate_control3(module_id_client, slice_client, 7);
  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE6_1 OTU2               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge6_1_otu2(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk,
                                     cs_uint16 flow_ctrl_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/*              o Flow Control Mode                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> GFP-S G.Sup43.6.1 -> OTU2    */
/* Assigns OTU2 on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides. (Ported from cfg35d)  */
/*                                                              */
/* [module_id_line]  specifies line's module ID                 */ 
/*                                                              */
/* [slice_line]  specifies line's slice:                        */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client]  specifies the client's module ID         */
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
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* The [flow_ctrl_mode] parameter is specified as:              */
/*   TEN_PP10G_FLOW_ETH_4 (Reactive)               = 2,         */
/*   TEN_PP10G_FLOW_ETH_4_P (Premptive)            = 3.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10ge6_1_otu2: 0x%X, %d, 0x%X, %d, dyn=%d, sysclk=%d, flow=%d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk, flow_ctrl_mode);
     
  if ((flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && 
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P)) {
     CS_PRINT("ERROR: flow control either TEN_PP10G_FLOW_ETH_4 or TEN_PP10G_FLOW_ETH_4_P.");
     return (CS_ERROR);
  }
    
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, 
                           TEN_N10G_RX_OTU2_OC192_10GE, 
                           TEN_N10G_TX_10GE_OC192_OTU2, dyn_repro);
                           
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, 
                           TEN_N10G_RX_BYPASS,
                           TEN_N10G_TX_BYPASS, 0);
                           
  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
  }
  else {
   rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  
   
    /* Bugzilla #24492, use ETH2 method */
    rtn |= ten_hl_pp10g_tx_init(module_id_client, slice_client, TEN_PP10G_TX_ETH_2);
  }                        

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_line, slice_line, sysclk * 125);  

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, 
                                TEN_TRAFFIC_TYPE_10GE_6_1, 1);
                               
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x7F);
                            
  /* Set TDELON/TDELOFF for 3ms */
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 492, 492);

  /* Configure XCON */
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
                           (module_id_client & 1) * 4 + slice_client, 
                            TEN_TRAFFIC_TYPE_10GE_6_1); 
  
  /* cfg_xaui_b_lan2wan */
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                           0x1,  /* idle_all   */
                                           0x0,  /* frames_all */ 
                                           0x1,  /* client_all */ 
                                           0x0,  /* seq_os_all */ 
                                           0x1,  /* seq_os_2nd */ 
                                           0x0); /* fc_idle    */
                                           
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_client, slice_client, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_client, slice_client, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_pause_en(module_id_client, slice_client, 0, 1);
    
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                           0x0,   /* idle_all   */
                                           0x0,   /* frames_all */
                                           0x1,   /* client_all */
                                           0x0,   /* seq_os_all */
                                           0x0,   /* seq_os_2nd */
                                           0x0);  /* fc_idle    */
                                           
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_line, slice_line, 0, 4, 3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_line, slice_line, 1, 1, 1, 1, 1, 1);

    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

    rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
                                            0x7,  /* map_idle_all   */ 
                                            0x0); /* map_seq_os_2nd */

    rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_client, slice_client, 7);
    rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_line,   slice_line,   7);

    rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, slice_client, 2);
  }
  /* Flow control settings in the Ingress direction */
  rtn |= ten_hl_pp10g_flow_init(module_id_client, slice_client, flow_ctrl_mode);
  
  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  if (!ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    /* Bugzilla #24492 - Need a larger IPG for 64-9600 random frame settings */
    rtn |= ten_pp10g_mac_tx_pause_xoff_delay(module_id_client, slice_client, 6);
    rtn |= ten_pp10g_mac_tx_pause_quanta(module_id_client, slice_client, 128);
    
    rtn |= ten_pp10g_mac_rx_set_profile(module_id_line, slice_line, 2);
    rtn |= ten_pp10g_xgadj_rx_control(module_id_line, slice_line, 0, 2, 2); 
    rtn |= ten_pp10g_rs_rx_profile(module_id_line, slice_line, 2);
    rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_client, slice_client, 5);
    
    rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_client, slice_client, 0, 0);
    
    rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, 
                                           TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x03FF);
  }                                       
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE GFPF OC192 OTU2       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge_gfpf_oc192_otu2(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> CBR10G G.Sup43.6.2 ->        */
/* Assigns OTU2 on module_id_line and 10GE on module_id_client. */
/* Enables 10GE monitoring on both sides. (Ported from cfg35d)  */
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
/* [slice_client] specifies client's slice:                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10ge_gfpf_oc192_otu2: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
            module_id_line, slice_line, module_id_client, slice_client, 
            dyn_repro, sysclk);

 rtn |= ten_hl_n10g_config(module_id_line, slice_line, 
                           TEN_N10G_RX_OTU2_OC192_10GE, 
                           TEN_N10G_TX_10GE_OC192_OTU2, dyn_repro);
                           
  /*WRPCFG3_STM64MD = 1*/
  /* Bugzilla #22743 */
  rtn |= ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 1);                        

  /* Set TDELON/TDELOFF for 3ms */
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 492*239/255, 492*239/255);
  
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0); 

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_GFP_S, TEN_PP10G_TX_GFP_S);
  
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH0_GFP_S, TEN_PP10G_TX_XAUI_GFP_S_ETH0);
  }
  else {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH0_GFP_S, TEN_PP10G_TX_GFP_S_ETH0);
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);
  }
  
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  /* Bugzilla #19353, fix bus errors */
  
  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2, 1);

  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line,
           (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2);

  rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                         0x1,   /* idle_all   */
                                         0x0,   /* frames_all */
                                         0x1,   /* client_all */
                                         0x1,   /* seq_os_all */
                                         0x0,   /* seq_os_2nd */
                                         0x0);  /* fc_idle    */
             
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                         0x1,  /* idle_all   */
                                         0x1,  /* frames_all */ 
                                         0x1,  /* client_all */ 
                                         0x1,  /* seq_os_all */ 
                                         0x0,  /* seq_os_2nd */ 
                                         0x0); /* fc_idle    */
             
  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
             0x7,  /* map_idle_all   */ 
             0x0); /* map_seq_os_2nd */

  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_client, slice_client, 7);

  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_line, slice_line, 7);

  rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, slice_client, 2);
             
  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  rtn |= ten_n10g_otnr_set_g43md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_g43md(module_id_line, slice_line, 0);
  
   /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line, slice_line, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line, slice_line, 0);

  return (rtn);
}                                                                    

/* Bugzilla 22237 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE RA OTU2               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge_ra_otu2(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk,
                                     cs_uint8  flow_ctrl_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client OTU2 to 10GE pair.                   */
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
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000                                     */
/*                                                              */
/* The [flow_ctrl_mode] parameter is specified as:              */
/*   TEN_PP10G_FLOW_ETH_4    (Reactive)           = 2,          */
/*   TEN_PP10G_FLOW_ETH_4_P  (Premptive)          = 3.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  cs_uint16 instance_line = (module_id_line & 1) * 4 + slice_line;
  cs_uint16 instance_client = (module_id_client & 1) * 4 + slice_client;
  
  CS_PRINT("ten_hl_config_10ge_ra_otu2: 0x%X, %d, 0x%X, %d, dyn=%d, sysclk=%d, flow=%d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk, flow_ctrl_mode);

  if ((flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && 
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P)) {
     CS_PRINT("ERROR: flow control either TEN_PP10G_FLOW_ETH_4 or TEN_PP10G_FLOW_ETH_4_P.");
     return (CS_ERROR);
  }    

  /* Configure Line N10G */
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2_10GE, TEN_N10G_TX_10GE_OTU2, dyn_repro);
  
  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0xFF);  

  /* Configure Client N10G */
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
 

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
  }
  else {
   rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
   
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  /* cfg1.2 */
  }  

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_RA, 1);
  
  rtn |= ten_hl_xcon_config(dev_id, instance_line, instance_client, TEN_TRAFFIC_TYPE_10GE_RA);

  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                         0x1,  /* idle_all   */
                                         0x0,  /* frames_all */ 
                                         0x1,  /* client_all */ 
                                         0x0,  /* seq_os_all */ 
                                         0x1,  /* seq_os_2nd */ 
                                         0x0); /* fc_idle    */
                                         
  rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_client, slice_client, 0, 4, 3);
  rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_client, slice_client, 1, 1, 1, 1, 1, 1);

  rtn |= ten_pp10g_mac_tx_cfg_pause_en(module_id_client, slice_client, 0, 1);
  
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                         0x0,   /* idle_all   */
                                         0x0,   /* frames_all */
                                         0x1,   /* client_all */
                                         0x0,   /* seq_os_all */
                                         0x0,   /* seq_os_2nd */
                                         0x0);  /* fc_idle    */
                                         
  rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_line, slice_line, 0, 4, 3);
  rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_line, slice_line, 1, 1, 1, 1, 1, 1);

  rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
                                          0x7,  /* map_idle_all   */ 
                                          0x0); /* map_seq_os_2nd */

  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_client, slice_client, 7);
  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_line,   slice_line,   7);

  rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, slice_client, 2);
             
  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  /* Provision Flow Control */
  rtn |= ten_hl_pp10g_flow_init(module_id_client, slice_client, flow_ctrl_mode);

  rtn |= ten_n10g_otnr_set_g43md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_g43md(module_id_line, slice_line, 0);
  
   /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line, slice_line, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line, slice_line, 0);

  return (rtn);
}
/* Bugzilla 22237 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE RA OTU2               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge_ra_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk,
                                       cs_uint8  flow_ctrl_mode)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE -> CBR10G G.Sup43.6.2 ->        */
/* (ODU2 -> ODTU23 -> OTU3/3e/3p2                               */
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
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3   = 1,                               */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000                                     */
/*                                                              */
/* The [flow_ctrl_mode] parameter is specified as:              */
/*   TEN_PP10G_FLOW_ETH_4    = 2,  (Reactive)                   */
/*   TEN_PP10G_FLOW_ETH_4_P  = 3   (Preemptive).                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  cs_uint16 instance_line = (module_id_line & 1) * 4 + slice_line;
  cs_uint16 instance_client = (module_id_client & 1) * 4 + slice_client;
  
  CS_PRINT("ten_hl_config_10ge_ra_odtu23: 0x%X, %d, 0x%X, %d, dyn=%d, line=%d, sysclk=%d, flow=%d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           line, sysclk, flow_ctrl_mode);

  if ((flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4) && 
      (flow_ctrl_mode != TEN_PP10G_FLOW_ETH_4_P)) {
     CS_PRINT("ERROR: flow control either TEN_PP10G_FLOW_ETH_4 or TEN_PP10G_FLOW_ETH_4_P.");
     return (CS_ERROR);
  }    
           
  /* Configure Line N10G */
  /* rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2_10GE, TEN_N10G_TX_10GE_OTU2, dyn_repro); */
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OXU3_10GE, TEN_N10G_TX_10GE_OXU3, dyn_repro);
  
  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
  /* rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0xFF);  */

  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling (module_id_line, slice_line, 0, 0); 
  rtn |= ten_n10g_otnr_descrambling (module_id_line, slice_line, 0, 0); 
  
  rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 0);

  /* Configure Client N10G */
  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
 
  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
  }
  else {
   rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
    /* Bugzilla #22850, fix bus errors */
    rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);  /* cfg1.2 */
  }  
  
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_RA, 1);
  
  rtn |= ten_hl_xcon_config(dev_id, instance_line, instance_client, TEN_TRAFFIC_TYPE_10GE_RA);

  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 
                                         0x1,  /* idle_all   */
                                         0x0,  /* frames_all */ 
                                         0x1,  /* client_all */ 
                                         0x0,  /* seq_os_all */ 
                                         0x1,  /* seq_os_2nd */ 
                                         0x0); /* fc_idle    */
                                         
  rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_client, slice_client, 0, 4, 3);
  rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_client, slice_client, 1, 1, 1, 1, 1, 1);

  rtn |= ten_pp10g_mac_tx_cfg_pause_en(module_id_client, slice_client, 0, 1);
  
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line, 
                                         0x0,   /* idle_all   */
                                         0x0,   /* frames_all */
                                         0x1,   /* client_all */
                                         0x0,   /* seq_os_all */
                                         0x0,   /* seq_os_2nd */
                                         0x0);  /* fc_idle    */
                                         
  rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_line, slice_line, 0, 4, 3);
  rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_line, slice_line, 1, 1, 1, 1, 1, 1);

  rtn |= ten_pp10g_mac_tx_cfg_programmable_ifg(module_id_line, slice_line, 0x8);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0xFF);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0FF);

  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_line, slice_line, 
                                          0x7,  /* map_idle_all   */ 
                                          0x0); /* map_seq_os_2nd */

  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_client, slice_client, 7);
  rtn |= ten_pp10g_xgadj_map_seq_os_all(module_id_line,   slice_line,   7);

  rtn |= ten_pp10g_xgadj_rx_rate_control2_map_frames_all(module_id_client, slice_client, 2);
             
  /* These are for jumbo frames */
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 0x2710);
  rtn |= ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0x0, 0x2710);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0x0, 0x2710);

  /* Provision Flow Control */
  rtn |= ten_hl_pp10g_flow_init(module_id_client, slice_client, flow_ctrl_mode);

  rtn |= ten_n10g_otnr_set_g43md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_g43md(module_id_line, slice_line, 0);
  
   /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line, slice_line, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line, slice_line, 0);

  /* Bugzilla #24441, fix line/client consistency */
  /* jc_plus_odtu23=1, jc_plus_otu2=0, jcen_dt=0, jcen_odtu23=1, jcen_otu2=0*/
  rtn |= ten_n10g_set_otnt_wrpcfg4(module_id_line, slice_line, 1, 0, 0, 1, 0);

  /* Bugzilla 21279 Start */
  ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 1);

  ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);
  ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);
  /* Bugzilla 21279 End */

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE 7.1 OTU2E             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge7_1_otu2e(cs_uint16 module_id_line,
                                      cs_uint8  slice_line,
                                      cs_uint16 module_id_client,
                                      cs_uint8  slice_client,
                                      cs_uint8  dyn_repro,
                                      cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client OTU2 to 10GE pair.                   */
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
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10ge7_1_otu2e: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk);

  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0xFF);  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4, TEN_PP10G_TX_ETH_4);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
     
    /* idle_all=1, frame_all=0, client_all=1, seq_os_all=0,seq_os_2nd=1,fc_idle=0 */
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 1,0,1,0,1,0);
    /* map_frames_all=0  ,map_client_all_hi= 4  , map_client_all_lo=3 */
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_client, slice_client, 0,4,3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_client, slice_client, 1,1,1,1,1,1);

    /* idle_all=0, frame_all=0, client_all=1, seq_os_all=0,seq_os_2nd=0,fc_idle=0 */
    rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line, slice_line,0,0,1,0,0,0);
    /* map_frames_all=0  ,map_client_all_hi= 4  , map_client_all_lo=3 */
    rtn |= ten_pp10g_xgadj_rx_rate_control2(module_id_line, slice_line,0,4,3);
    rtn |= ten_pp10g_mac_rx_cfg_ethernet_mode(module_id_line, slice_line,1,1,1,1,1,1);
  }
  else {
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
  }
  
  /* Bugzilla #19353, fix bus errors */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE, 1);
  
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
            (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_7_1);
  
  /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line, slice_line, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line, slice_line, 0);

  return (rtn);
}

/* Bugzilla 20308 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE 7.2 OTU1E             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge7_2_otu1e(cs_uint16 module_id_line,
                                      cs_uint8  slice_line,
                                      cs_uint16 module_id_client,
                                      cs_uint8  slice_client,
                                      cs_uint8  dyn_repro,
                                      cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client OTU1e to 10GE pair.                   */
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
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10ge7_2_otu1e: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk);

  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0xFF);  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */

  /* OTU1e has no fixed stuff */
  rtn |= ten_n10g_otnr_set_stm64md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 0);

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  if (ten_hsif_is_xaui_active(module_id_client, slice_client)) {
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
  }
  else {
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
  }
  
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE, 1);
  
  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
            (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_7_2);
  
  /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line, slice_line, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line, slice_line, 0);
  
  return (rtn);
}
/* Bugzilla 20308 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE 10GE                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge_10ge(cs_uint16 module_id_line,
                                  cs_uint8  slice_line,
                                  cs_uint16 module_id_client,
                                  cs_uint8  slice_client,
                                  cs_uint8  dyn_repro,
                                  cs_uint16 sync,
                                  cs_uint16 sysclk)

/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sync                                          */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a line/client 10GE to 10GE pair.                   */
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
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [sync] specifies the sync. 0=async, 1=sync                   */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in MHz,              */
/*   For example, 400.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  cs_uint16 es_line, es_client;
  cs_uint16 xaui_client_active = 0;
  cs_uint16 xaui_line_active = 0;

  CS_PRINT("ten_hl_config_10ge_10ge:  mod_line=0x%04X, slice_line=%d, mod_client=0x%04X, slice_client=%d\ndyn_repro=%d, sync=%d, sysclk=%d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro, sync, sysclk);

  /* Check for XAUI */
  xaui_line_active = ten_hsif_is_xaui_active(module_id_line, slice_line);
  xaui_client_active = ten_hsif_is_xaui_active(module_id_client, slice_client);

  es_line = (module_id_line & 1) * 4 + slice_line;
  es_client = (module_id_client & 1) * 4 + slice_client;
                 
  /* non-XAUI line to non-XAUI client */
  if (!xaui_line_active && !xaui_client_active) {
    rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
    rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

    /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
    #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
    rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
    #endif

    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);
    rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
             (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE);


  /* 10GE_RA aysnc test */
  /*  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4); */
  /*  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4); */
  /*  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, */
  /*                            (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_RA); */

  }
  /* XAUI line to non-XAUI client */
  else if (xaui_line_active && !xaui_client_active) {
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
    rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0); 
    /* Bugzilla #26401, fix bus errors */  
    rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
  
    /* Bugzilla #22621, reset xcon defaults first */
    rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
             (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_NONE);
             
    rtn |= ten_xcon_config_es_mode(dev_id, es_line, XCON_FP, XCON_NO_GFP, XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es_line, XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_es_select_source(dev_id, es_line, es_client, XCON_PP10G);
    rtn |= ten_xcon_config_es_mode(dev_id, es_client, XCON_FP, XCON_NO_GFP, XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es_client, XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_es_select_source(dev_id, es_client, es_line, XCON_PP10G);
    rtn |= ten_n10g_set_pktie(module_id_client,slice_client,1);
  }
  /* non-XAUI line to XAUI client */
  else if (!xaui_line_active && xaui_client_active) {
    rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
    /* Bugzilla #26401, fix bus errors */  
    rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_ETH_4_RA, TEN_PP10G_TX_ETH_4);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
 
    /* Bugzilla #22621, reset xcon defaults first */
    rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
             (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_NONE);
     
    rtn |= ten_xcon_config_es_mode(dev_id, es_line, XCON_FP, XCON_NO_GFP, XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es_line, XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_es_select_source(dev_id, es_line, es_client, XCON_PP10G);
    rtn |= ten_xcon_config_es_mode(dev_id, es_client, XCON_FP, XCON_NO_GFP, XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es_client, XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_es_select_source(dev_id, es_client, es_line, XCON_PP10G);
    rtn |= ten_n10g_set_pktie(module_id_line,slice_line,1);
  } 
  /* XAUI line to XAUI client */
  else if (xaui_line_active && xaui_client_active) {
    rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);
    rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_XAUI_ETH_4_RA, TEN_PP10G_TX_XAUI_ETH_4);

    /* Bugzilla #26401, fix bus errors */  
    rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
    rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

    /* Bugzilla #22621, reset xcon defaults first */
    rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
             (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_NONE);
     
    rtn |= ten_xcon_config_es_mode(dev_id, es_line, XCON_FP, XCON_NO_GFP, XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es_line, XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_es_select_source(dev_id, es_line, es_client, XCON_PP10G);
    rtn |= ten_xcon_config_es_mode(dev_id, es_client, XCON_FP, XCON_NO_GFP, XCON_MODE_STORE_FWD, XCON_MODE_PKT);
    rtn |= ten_xcon_select_es_packet_centering(dev_id, es_client, XCON_AUTO_CENTER, CS_DISABLE);
    rtn |= ten_xcon_es_select_source(dev_id, es_client, es_line, XCON_PP10G);
  }
  else {
    CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, ": hsif settings not compatible.");
    rtn = CS_ERROR;
  }
  return (rtn);
}

/* Bugzilla 22514 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10G XCON LOOPBACK          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge_xcon_loopback(cs_uint16 module_id,
                                        cs_uint8  slice,
                                        cs_uint16 traffic_type,
                                        cs_uint8  dyn_repro,
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
/*   0x09 = TEN_TRAFFIC_TYPE_10GE_WAN                           */
/*   0x0A = TEN_TRAFFIC_TYPE_10GE_6_2                           */
/*   0x0B = TEN_TRAFFIC_TYPE_10GE_7_1                           */
/*   0x0C = TEN_TRAFFIC_TYPE_10GE_7_3                           */
/*   0x14 = TEN_TRAFFIC_TYPE_10GE                               */
/*   0x1A = TEN_TRAFFIC_TYPE_10GE_6_1                           */
/*   0x1B = TEN_TRAFFIC_TYPE_10GE_7_2                           */
/*   0x1C = TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2               */
/*   0x1E = TEN_TRAFFIC_TYPE_10GE_RA                            */
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
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_10ge_xcon_loopback";  
  
  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255. ", func, slice);
    return (CS_ERROR);
  }

  if ((traffic_type != TEN_TRAFFIC_TYPE_10GE_WAN) && (traffic_type != TEN_TRAFFIC_TYPE_10GE_6_2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_10GE_7_1) && (traffic_type != TEN_TRAFFIC_TYPE_10GE_7_3) &&
      (traffic_type != TEN_TRAFFIC_TYPE_10GE) && (traffic_type != TEN_TRAFFIC_TYPE_10GE_6_1) &&
      (traffic_type != TEN_TRAFFIC_TYPE_10GE_7_2) && (traffic_type != TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_10GE_RA)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 9, 10, 11, 12, 20, 26, 27, 28 or 30.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, Slice %d, %s, %s, sysclk = %d\n",
           func,
           ten_module_strings[module_id & 1],
           slice,
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_hl_config_dyn_repro_strings[dyn_repro],
           sysclk);


  rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  rtn |= ten_hl_pp10g_config(module_id, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0);

  rtn |= ten_hl_xcon_config(dev_id, (module_id & 1) * 4 + slice, (module_id & 1) * 4 + slice, TEN_TRAFFIC_TYPE_10GE);

  return (rtn);
}
/* Bugzilla 22514 End */


/* Bugzilla 23775 Start */
/* ten_hl_config_10g_xcon_loopback routine removed */
/* Bugzilla 23775 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GE TC TO OTU2E           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10ge_tc_otu2e(cs_uint16 module_id_line,
                                      cs_uint8  slice_line,
                                      cs_uint16 module_id_client,
                                      cs_uint8  slice_client,
                                      cs_uint8  gfp_frame_format,
                                      cs_uint8  dyn_repro,
                                      cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o GFP Frame Format                              */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a timing-transparent transport of 64b/66b client   */
/* through 512b/513b transcoding                                */
/* Assigns OTU2e on module_id_line and 10GE on module_id_client.*/
/* Enables 10GE monitoring on both sides. (Ported from cfg21b). */
/*                                                              */
/* [module_id_line] specifies line's module ID                  */ 
/*                                                              */
/* [slice_line]  specifies line's slice:                        */
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
/* [gfp_frame_format] specifies the GFP frame format            */
/*   0 = TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4                       */
/*   1 = TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4                      */
/*   2 = TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC                      */
/*   3 = TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC                      */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [sysclk] specifies the sysclk frequency in Hz,               */
/*   For example, 400000000.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  ten_dev_cb_t *pdevcb;
  
  CS_PRINT("ten_hl_config_10ge_tc_otu2e: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
           
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2EJ_10GE, TEN_N10G_TX_10GE_OTU2EJ, dyn_repro);
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0xFF);  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, TEN_PP10G_RX_XC_GE, TEN_PP10G_TX_XC_GE);

  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_ETH_4, TEN_PP10G_TX_ETH_4);

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk * 125);
  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GE_TC, 1);

  rtn |= ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, 
           (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GE_TC);

  ten_n10g_otnt_set_wrpfs(module_id_line, slice_line, pdevcb->syncdsync_cb.num_just_oxu2);
  ten_n10g_set_otnr_odwfs(module_id_line, slice_line, pdevcb->syncdsync_cb.num_just_oxu2);

  ten_n10g_otnr_set_stm64md(module_id_line, slice_line,0);
  ten_n10g_otnt_set_stm64md(module_id_line, slice_line,0);
  ten_n10g_otnt_set_c15res_en(module_id_line, slice_line,0);
  ten_n10g_otnr_set_c15res_en(module_id_line, slice_line,0);

  if(gfp_frame_format == TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4) {
    ten_pp10g_xcode_config(module_id_line, slice_line, CS_TX_AND_RX, 
                            TEN_28_BLOCKS_PER_SUPERBLOCK_CRC4, TEN_4_RES_OCTETS, 5);
  }
  else if(gfp_frame_format == TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4) {
    ten_pp10g_xcode_config(module_id_line, slice_line, CS_TX_AND_RX, 
                            TEN_28_BLOCKS_PER_SUPERBLOCK_CRC4, TEN_4_RES_OCTETS, 11);
  }
  else if(gfp_frame_format == TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC) {
    ten_pp10g_xcode_config(module_id_line, slice_line, CS_TX_AND_RX, 
                            TEN_32_BLOCKS_PER_SUPERBLOCK_NOCRC, TEN_4_RES_OCTETS, 4);
  }
  else if(gfp_frame_format == TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC) {
    ten_pp10g_xcode_config(module_id_line, slice_line, CS_TX_AND_RX, 
                            TEN_32_BLOCKS_PER_SUPERBLOCK_NOCRC, TEN_4_RES_OCTETS, 8);
  }

  ten_pp10g_rs_rx_control(module_id_line, slice_line,0,1,1,1,0); /* disable HSIF OK signal to RS-Rx */
  ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client,0,0,1,0,0,0); /* clients all */
  ten_pp10g_gfp_tx_set_payload_header(module_id_line, slice_line,0x0,0x1); /* enable GFP PH PFI */
  ten_pp10g_gfp_tx_upi(module_id_line, slice_line,0xFE,0x15); /* set the tx UPID to 0x15 */
  ten_pp10g_gfp_rx_set_expected_upi(module_id_line, slice_line,0xFE,0x15); /* set the rx ExUPID to 0x15 */

  /* Set fault_repeat to 3FF (max'd out for now) */
  ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_CONTROL, 0xF);
  ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
  ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
  ten_pp10g_set_xgadj_tx_fillctrl(module_id_line, slice_line, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x3FF);

  ten_pp10g_rs_rx_control(module_id_client, slice_client, 0, 1, 1, 1, 0); /* disable HSIF OK signal to RS-Rx */
  ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client, 0, 0, 1 ,0 ,0, 0); /* clients all */

  /* Setting pp10g for jumbo frames") */
  ten_pp10g_mac_rx_maxlen(module_id_client, slice_client, 10000);
  ten_pp10g_xgadj_tx_maxframe(module_id_client, slice_client, 0, 10000);
  ten_pp10g_mac_rx_maxlen(module_id_line, slice_line, 10000);
  ten_pp10g_xgadj_tx_maxframe(module_id_line, slice_line, 0, 10000);

  /* unset the G43MD in N10G */
  ten_n10g_otnr_set_g43md(module_id_line, slice_line, 0);
  ten_n10g_otnt_set_g43md(module_id_line, slice_line, 0);
  
  return (rtn);
}


