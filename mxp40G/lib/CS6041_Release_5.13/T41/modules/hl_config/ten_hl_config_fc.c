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
 * ten_hl_config_fc.c
 *
 * API's for high level Fibre Channel client configuration.
 *
 * $Id: ten_hl_config_fc.c,v 1.10 2013/05/01 14:37:17 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GFC OTU1F                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10gfc_otu1f(cs_uint16 module_id_line,
                                    cs_uint8  slice_line,
                                    cs_uint16 module_id_client,
                                    cs_uint8  slice_client,
                                    cs_uint8  dyn_repro,
                                    cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a 10gfc client directly mapped into an otu1f.      */
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
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10gfc_otu1f: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk);

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0xFF);  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */

  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_FC, TEN_PP10G_TX_FC);
  rtn |= ten_hl_pp10g_config(module_id_line,   slice_line,   TEN_PP10G_RX_FC, TEN_PP10G_TX_FC);

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GFC, 1);

  /* Borrowing otu2e xcon config to bypass PP10G (passively monitoring here) */
  rtn |= ten_hl_xcon_config(temp_dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OTU2E);
  
  rtn |= ten_n10g_otnr_set_stm64md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 0);

 /* Set BER timer */
 rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk*125);
 rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_line,   slice_line,   sysclk*125); 


 rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
 rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
 rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0);
 rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line,   slice_line,   TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
 rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line,   slice_line,   TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
 rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line,   slice_line,   TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0);

  /* Idle_all, client_all */
 rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client,  1, 0, 1, 0, 0, 0);
  /* client_all */
 rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line,   slice_line,    0, 0, 1, 0, 0, 0);

 rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_client, slice_client, 7, 2);
  /* ifg = 4 */
 rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id_client, slice_client, 4);
 rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id_line,   slice_line,   4);

  /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line,   slice_line,   3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line,   slice_line,   0);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GFC TRANSCODED ODTU23    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10gfc_tc_odtu23(cs_uint16 module_id_line,
                                        cs_uint8  slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint8  slice_client,
                                        cs_uint16 line,
                                        cs_uint8  dyn_repro,
                                        cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a 10gfc muxponder client using transcoding to fit. */
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
/* [line] specifies the traffic type of the line:               */
/*   0x02 = TEN_TRAFFIC_TYPE_OTU3E                              */
/*   0x03 = TEN_TRAFFIC_TYPE_OTU3P                              */
/*   0x19 = TEN_TRAFFIC_TYPE_OTU3P2                             */
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
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10gfc_tc_odtu23: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk);

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OXU3_10GEP, TEN_N10G_TX_10GE_OXU3P, dyn_repro);

  /* Bugzilla #20657, regression fixes */
  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling (module_id_line, slice_line, 0, 0); 
  rtn |= ten_n10g_otnr_descrambling (module_id_line, slice_line, 0, 0); 

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  /* Bugzilla 20308 Start */
  /* Configure 40G Fixed Stuff and C15s */
  if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 2); 
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 992, 0);
  }
  else { /* TEN_TRAFFIC_TYPE_OTU3P */
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 4); 
  }

  /* Enable JC Plus for this slice */
  rtn |= ten_n10g_otnt_set_jc_odtu23(module_id_line, slice_line, 1, 0, 1);
  rtn |= ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);     /* Bugzilla 21279 */
  rtn |= ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 1);
  /* Bugzilla 20308 End */

   rtn |= ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);  /* Bugzilla 21279 */
  rtn |= ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);                               /* Bugzilla 21279 */

  rtn |= ten_n40g_otnt4x_bipmsk(module_id_line, 0xff);
  /* 7F or FF? */
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x7F);  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */

  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 1.036*492*239/255, 1.036*492*239/255);
  rtn |= ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(module_id_line, 1.036*495, 1.036*495);

  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_FC, TEN_PP10G_TX_FC);
  rtn |= ten_hl_pp10g_config(module_id_line,   slice_line,   TEN_PP10G_RX_XC_FC, TEN_PP10G_TX_XC_FC);

  rtn |= ten_hl_n40g_config_pti(module_id_line, TEN_TRAFFIC_TYPE_ODTU23);

  rtn |= ten_hl_xcon_config(temp_dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GFC);

  /* Set BER timer */
  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk*125);
  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_line,   slice_line,   sysclk*125); 

  rtn |= ten_pp10g_gfp_tx_set_payload_header(module_id_line, slice_line, 0, 1);

  /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line,   slice_line,   3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line,   slice_line,   0);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10GFC TRANSCODED OTU2E     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10gfc_tc_otu2e(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision a 10gfc client trascoded into otu2e.               */
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
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_10gfc_tc_otu2e: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk);

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);
  rtn |= ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0xFF);  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */

  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_FC, TEN_PP10G_TX_FC);
  rtn |= ten_hl_pp10g_config(module_id_line,   slice_line,   TEN_PP10G_RX_XC_FC, TEN_PP10G_TX_XC_FC);

  rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GFC, 1);
  /*rtn |= ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_10GFC_TC, 1);*/

  rtn |= ten_hl_xcon_config(temp_dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_10GFC);

  /* Set BER timer */
  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_client, slice_client, sysclk*125);
  rtn |= ten_pp10g_set_pcs_rx_ber_timer(module_id_line,   slice_line,   sysclk*125); 

  rtn |= ten_pp10g_gfp_tx_set_payload_header(module_id_line, slice_line, 0, 1);
  rtn |= ten_pp10g_gfp_tx_upi( module_id_line, slice_line, 0xfe, 0x15);
  rtn |= ten_pp10g_gfp_rx_set_expected_upi(module_id_line, slice_line, 0xfe, 0x15);

  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 1);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_client, slice_client, TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line,   slice_line,   TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line,   slice_line,   TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE, 0);
  rtn |= ten_pp10g_set_xgadj_tx_fillctrl(module_id_line,   slice_line,   TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT, 0x0);

   /* Idle_all, client_all */
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_client, slice_client,  1, 0, 1, 0, 0, 0);
   /* client_all */
  rtn |= ten_pp10g_xgadj_rx_rate_control(module_id_line,   slice_line,    0, 0, 1, 0, 0, 0);

  rtn |= ten_pp10g_xgadj_rx_rate_control1(module_id_client, slice_client, 7, 2);
   /* ifg = 4 */
  rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id_client, slice_client, 4);
  rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id_line,   slice_line,   4);

  /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line,   slice_line,   3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line,   slice_line,   0);
  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL 8GFC ENHANCED MODE MAP ODTU23     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_8gfc_enh_odtu23(cs_uint16 module_id_line,
                                        cs_uint8  slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint8  slice_client,
                                        cs_uint16 line,
                                        cs_uint8  dyn_repro,
                                        cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an 8GFC muxponder client using enhanced mode.      */
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
/* [line] specifies the traffic type of the line:               */
/*   0x02 = TEN_TRAFFIC_TYPE_OTU3E                              */
/*   0x03 = TEN_TRAFFIC_TYPE_OTU3P                              */
/*   0x19 = TEN_TRAFFIC_TYPE_OTU3P2                             */
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
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  ten_dev_cb_t *pdevcb;
  cs_uint32 hysteresis;

  CS_PRINT("ten_hl_config_8gfc_enh_odtu23:  0x%04X, sl=%d, 0x%04X, sl=%d\n, dyn=%d, sysclk=%d\n",
           module_id_line, slice_line, module_id_client, 
           slice_client, dyn_repro, sysclk);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(temp_dev_id);

  rtn |= ten_hl_n10g_config(module_id_line, slice_line, 
                            TEN_N10G_RX_ODU2J_8GFC, 
                            TEN_N10G_TX_8GFC_ODU2J, dyn_repro);
  

  rtn |= ten_n10g_set_otnr_odwfs(module_id_line, slice_line, 2278);
  rtn |= ten_n10g_otnt_set_wrpfs(module_id_line, slice_line, 2278);

  /* Bugzilla 20308 Start */
  /* Configure 40G Fixed Stuff and C15s */
  if (line == TEN_TRAFFIC_TYPE_OTU3) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 0, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 3082, 0);
  }
  else if (line == TEN_TRAFFIC_TYPE_OTU3E) {
    rtn |= ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2122, 0);
    }
  /* Bugzilla 20308 End */
  
  /* Bug 23864 Start */
  if (pdevcb) {
    hysteresis = pdevcb->syncdsync_cb.hysteresis;
    /* Hysteresis value for DT Just */
    if      ( slice_line == 0 ) {
      rtn |= ten_n40g_otnt4x_set_wrp3dh1(module_id_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp3dh0(module_id_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
    else if ( slice_line == 1 ) {
      rtn |= ten_n40g_otnt4x_set_wrp2dh1(module_id_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp2dh0(module_id_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
    else if ( slice_line == 2 ) {
      rtn |= ten_n40g_otnt4x_set_wrp1dh1(module_id_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp1dh0(module_id_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
    else if ( slice_line == 3 ) {
      rtn |= ten_n40g_otnt4x_set_wrp0dh1(module_id_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp0dh0(module_id_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
  }
  else {
    rtn = CS_ERROR;
  }
  /* Bug 23864 End  */

  /* N40G JC_PLUS=0, JC_EN=1 */
  rtn |= ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  /* rtn |= ten_n40g_otnr4x_set_jc_plus(module_id_line, 0); */
  rtn |= ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 0);    /* Bugzilla 21279 */

  rtn |= ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 1);
  rtn |= ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, 
                            TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, 
                             TEN_PP10G_RX_8FC, TEN_PP10G_TX_DISABLE);
                            
  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, 
                             TEN_PP10G_RX_8FC, TEN_PP10G_TX_DISABLE);
    
  /* Bugzilla #19353, fix bus errors */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  /* Bugzilla #24586, not needed for 8gfc */

  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling(module_id_line, slice_line, 0, 0);
  rtn |= ten_n10g_otnr_descrambling(module_id_line, slice_line, 0, 0);
  
  /* PTI setting for 8GFC */
  rtn |= ten_n10g_otnt_set_pti_byte(module_id_line, slice_line, 0x02);
  rtn |= ten_n10g_set_expected_pti_byte(module_id_line, slice_line, 0x02);

  rtn |= ten_n10g_otnt_set_ptie(module_id_line, slice_line,  1);
                               
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x7F);
                            
  /* Set TDELON/TDELOFF for 3ms */
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 492*239/255, 492*239/255);
  rtn |= ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(module_id_line, 495, 495);

  rtn |= ten_n10g_gblr_set_xsel(module_id_line, slice_line, 0x2);

  /* Set STM 64 */
  rtn |= ten_n10g_otnr_set_stm64md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 0);

  /* Configure XCON */
  rtn |= ten_xcon_es_select_source(temp_dev_id,
                                   (module_id_line & 1) * 4 + slice_line,
                                   (module_id_client & 1) * 4 + slice_client, 
                                   XCON_N10G);
                                  
  rtn |= ten_xcon_es_select_source(temp_dev_id,
                                   (module_id_client & 1) * 4 + slice_client,
                                   (module_id_line & 1) * 4 + slice_line,
                                   XCON_N10G);

  rtn |= ten_xcon_config_es_mode(temp_dev_id,
                                 (module_id_line & 1) * 4 + slice_line,
                                 XCON_FP, XCON_NO_GFP,
                                 XCON_MODE_CUT_THRU, XCON_MODE_CCT);
                                
  rtn |= ten_xcon_config_es_mode(temp_dev_id,
                                 (module_id_client & 1) * 4 + slice_client,
                                 XCON_FP, XCON_NO_GFP,
                                 XCON_MODE_CUT_THRU, XCON_MODE_CCT);

  /* Disable Deskew function aligning 4 incoming stream by FP since not full aggr */
  ten_n40g_set_dsbldskw(module_id_line, 1);

  return (rtn);
}


/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL 8GFC ENHANCED MODE MAP OTU2       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_8gfc_enh_otu2(cs_uint16 module_id_line,
                                      cs_uint8  slice_line,
                                      cs_uint16 module_id_client,
                                      cs_uint8  slice_client,
                                      cs_uint8  dyn_repro,
                                      cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an 8GFC client mapped into OTU2 using enhanced     */
/* mode.                                                        */
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
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_config_8gfc_enh_otu2:  0x%04X, sl=%d, 0x%04X, sl=%d\n, dyn=%d, sysclk=%d\n",
           module_id_line, slice_line, module_id_client, 
           slice_client, dyn_repro, sysclk);

  rtn |= ten_hl_n10g_config(module_id_line, slice_line, 
                            TEN_N10G_RX_OTU2EJ_8GFC, 
                            TEN_N10G_TX_8GFC_OTU2EJ, dyn_repro);
  
  rtn |= ten_n10g_set_otnr_odwfs(module_id_line, slice_line, 2278);
  rtn |= ten_n10g_otnt_set_wrpfs(module_id_line, slice_line, 2278);

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, 
                            TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 0);

  rtn |= ten_hl_pp10g_config(module_id_line, slice_line, 
                             TEN_PP10G_RX_8FC, TEN_PP10G_TX_DISABLE);
                            
  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, 
                             TEN_PP10G_RX_8FC, TEN_PP10G_TX_DISABLE);
    
  /* Bugzilla #19353, fix bus errors */
  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  /* Bugzilla #24586, not needed for 8gfc */

  /* Line side OTU scrambling done in N40G block */
  rtn |= ten_n10g_otnt_scrambling(module_id_line, slice_line, 0, 0);
  rtn |= ten_n10g_otnr_descrambling(module_id_line, slice_line, 0, 0);
  
  /* PTI setting for 8GFC */
  rtn |= ten_n10g_otnt_set_pti_byte(module_id_line, slice_line, 0x02);
  rtn |= ten_n10g_set_expected_pti_byte(module_id_line, slice_line, 0x02);

  rtn |= ten_n10g_otnt_set_ptie(module_id_line, slice_line,  1);
                               
  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x7F);
                            
  /* Set TDELON/TDELOFF for 3ms */
  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id_line, slice_line, 492*239/255, 492*239/255);

  rtn |= ten_n10g_gblr_set_xsel(module_id_line, slice_line, 0x2);

  /* Set STM 64 */
  rtn |= ten_n10g_otnr_set_stm64md(module_id_line, slice_line, 0);
  rtn |= ten_n10g_otnt_set_stm64md(module_id_line, slice_line, 0);

  /* Configure XCON */
  rtn |= ten_xcon_es_select_source(temp_dev_id,
                                   (module_id_line & 1) * 4 + slice_line,
                                   (module_id_client & 1) * 4 + slice_client,
                                   XCON_N10G);
                                  
  rtn |= ten_xcon_es_select_source(temp_dev_id,
                                   (module_id_client & 1) * 4 + slice_client,
                                   (module_id_line & 1) * 4 + slice_line,
                                   XCON_N10G);

  rtn |= ten_xcon_config_es_mode(temp_dev_id,
                                 (module_id_line & 1) * 4 + slice_line,
                                 XCON_FP, XCON_NO_GFP,
                                 XCON_MODE_CUT_THRU, XCON_MODE_CCT);
                                
  rtn |= ten_xcon_config_es_mode(temp_dev_id,
                                 (module_id_client & 1) * 4 + slice_client,
                                 XCON_FP, XCON_NO_GFP,
                                 XCON_MODE_CUT_THRU, XCON_MODE_CCT);
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL 8GFC RATE ADAPTED INTO OTU2       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_8gfc_ra_otu2(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an 8GFC client rate adapted into OTU2 per section  */
/* 2.2.5.2 of the datasheet.                                    */
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
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_8gfc_ra_otu2: 0x%X, %d, 0x%X, %d, dyn=%d, %d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk);

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS,    TEN_N10G_TX_BYPASS, 0);
  rtn |= ten_hl_n10g_config(module_id_line, slice_line,     TEN_N10G_RX_OTU2_8GFC, TEN_N10G_TX_8GFC_OTU2, dyn_repro);

  /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
  #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
  rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
  #endif

  rtn |= ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0x7F);  /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */

  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_8FC,    TEN_PP10G_TX_8FC);
  rtn |= ten_hl_pp10g_config(module_id_line,   slice_line,   TEN_PP10G_RX_8FC_RA, TEN_PP10G_TX_8FC);

  /* PTI setting for 8GFC */
  rtn |= ten_n10g_otnt_set_pti_byte(module_id_line, slice_line, 0x03);
  rtn |= ten_n10g_set_expected_pti_byte(module_id_line, slice_line, 0x03);

  rtn |= ten_n10g_otnt_set_ptie(module_id_line, slice_line,  1);

  /* Configure XCON */
  rtn |= ten_xcon_es_select_source(temp_dev_id,
                                   (module_id_line & 1) * 4 + slice_line,
                                   (module_id_client & 1) * 4 + slice_client,
                                   XCON_PP10G);
  rtn |= ten_xcon_es_select_source(temp_dev_id,
                                   (module_id_client & 1) * 4 + slice_client,
                                   (module_id_line & 1) * 4 + slice_line,
                                   XCON_PP10G);

  rtn |= ten_xcon_config_es_mode(temp_dev_id,
                                 (module_id_line & 1) * 4 + slice_line,
                                 XCON_FP, XCON_NO_GFP,
                                 XCON_MODE_STORE_FWD, XCON_MODE_PKT);
  rtn |= ten_xcon_config_es_mode(temp_dev_id,
                                 (module_id_client & 1) * 4 + slice_client,
                                 XCON_FP, XCON_NO_GFP,
                                 XCON_MODE_CUT_THRU,  XCON_MODE_PKT);

  rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id_line, slice_line, 8);

  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_line & 1) * 4 + slice_line,
                                             XCON_AUTO_CENTER,    CS_DISABLE);
  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_line & 1) * 4 + slice_line,
                                             XCON_RECENTER_LOWER, CS_DISABLE);
  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_line & 1) * 4 + slice_line,
                                             XCON_RECENTER_UPPER, CS_DISABLE);
  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_client & 1) * 4 + slice_client,
                                             XCON_AUTO_CENTER,    CS_DISABLE);
  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_client & 1) * 4 + slice_client,
                                             XCON_RECENTER_LOWER, CS_DISABLE);
  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_client & 1) * 4 + slice_client,
                                             XCON_RECENTER_UPPER, CS_DISABLE);

  rtn |= ten_n10g_set_pktie(module_id_line, slice_line, 1);
  rtn |= ten_n10g_set_pktie(module_id_client, slice_client, 1);

  /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line,   slice_line,   3);
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line,   slice_line,   0);
  
  return (rtn);
}

/* Bug 24820: feature fc_ra_fc */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL FC RATE ADAPTED to FC             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_fc_ra_fc(cs_uint16 module_id_line,
                                 cs_uint8  slice_line,
                                 cs_uint16 module_id_client,
                                 cs_uint8  slice_client,
                                 cs_uint8  dyn_repro,
                                 cs_uint16 sysclk,
                                 cs_uint8  traffic_type)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Sysclk                                        */
/*              o Traffic Type                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an FC client rate adapted into the same FC traffic */
/* type, similar to section 2.2.5.2 of the datasheet with the   */
/* OTN on the bypassed.                                         */
/*                                                              */
/* [module_id_line] specifies line's module ID                  */ 
/*   0, 1                                                       */
/*                                                              */
/* [slice_line] specifies line's slice:                         */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client] specifies the client's module ID          */
/*   0, 1                                                       */
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
/* [traffic_type] specifies the speed of the fibre channel i/f  */
/*   TEN_TRAFFIC_TYPE_8GFC = 14                                 */
/*   TEN_TRAFFIC_TYPE_4GFC = 15                                 */
/*   TEN_TRAFFIC_TYPE_2GFC = 16                                 */
/*   TEN_TRAFFIC_TYPE_1GFC = 17                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hl_config_fc_ra_fc: 0x%X, %d, 0x%X, %d, dyn=%d, sysclk=%d, traffic_type=%d\n",
           module_id_line, slice_line, module_id_client, slice_client, dyn_repro,
           sysclk, traffic_type);

  rtn |= ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_BYPASS,    TEN_N10G_TX_BYPASS, 0);
  rtn |= ten_hl_n10g_config(module_id_line, slice_line,     TEN_N10G_RX_OTU2_8GFC, TEN_N10G_TX_8GFC_OTU2, dyn_repro);

  rtn |= ten_hl_pp10g_config(module_id_client, slice_client, TEN_PP10G_RX_8FC,    TEN_PP10G_TX_8FC);
  rtn |= ten_hl_pp10g_config(module_id_line,   slice_line,   TEN_PP10G_RX_8FC_RA, TEN_PP10G_TX_8FC);

  /* Configure XCON */
  rtn |= ten_xcon_es_select_source(temp_dev_id,
                                   (module_id_line & 1) * 4 + slice_line,
                                   (module_id_client & 1) * 4 + slice_client,
                                   XCON_PP10G);
  rtn |= ten_xcon_es_select_source(temp_dev_id,
                                   (module_id_client & 1) * 4 + slice_client,
                                   (module_id_line & 1) * 4 + slice_line,
                                   XCON_PP10G);

  rtn |= ten_xcon_config_es_mode(temp_dev_id,
                                 (module_id_line & 1) * 4 + slice_line,
                                 XCON_FP, XCON_NO_GFP,
                                 XCON_MODE_STORE_FWD, XCON_MODE_PKT);
  rtn |= ten_xcon_config_es_mode(temp_dev_id,
                                 (module_id_client & 1) * 4 + slice_client,
                                 XCON_FP, XCON_NO_GFP,
                                 XCON_MODE_CUT_THRU,  XCON_MODE_PKT);

  rtn |= ten_pp10g_xgadj_rx_rate_control3(module_id_line, slice_line, 8);

  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_line & 1) * 4 + slice_line,
                                             XCON_AUTO_CENTER,    CS_DISABLE);
  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_line & 1) * 4 + slice_line,
                                             XCON_RECENTER_LOWER, CS_DISABLE);
  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_line & 1) * 4 + slice_line,
                                             XCON_RECENTER_UPPER, CS_DISABLE);
  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_client & 1) * 4 + slice_client,
                                             XCON_AUTO_CENTER,    CS_DISABLE);
  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_client & 1) * 4 + slice_client,
                                             XCON_RECENTER_LOWER, CS_DISABLE);
  rtn |= ten_xcon_select_es_packet_centering(temp_dev_id,
                                             (module_id_client & 1) * 4 + slice_client,
                                             XCON_RECENTER_UPPER, CS_DISABLE);

  rtn |= ten_n10g_set_pktie(module_id_line, slice_line, 1);
  rtn |= ten_n10g_set_pktie(module_id_client, slice_client, 1);

  /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
  rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_client, slice_client, 3);
  /* rtn |= ten_n10g_otnt_cfg0_mfasins(module_id_line,   slice_line,   3); */
                         
  /* MFALGNE = 0x0    Disables the MFAS alignment process */
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_client, slice_client, 0);
  /* rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id_line,   slice_line,   0); */

  /* Bypass OTN section: otnoff=1, oby=1, sby=1, kpgby=1 */
  ten_n10g_set_gblt_bypasses(module_id_line, slice_line, 1, 1, 1, 1);
  /* Bypass OTN section: xsel=1, kpasel=1, sbypld=1, sbyfrm=1, oby=1, sdhoff=1, otnoff=1 */
  ten_n10g_set_gblr_dpcfg(module_id_line, slice_line, 1, 1, 1, 1, 1, 1, 1);

  return (rtn);
}
