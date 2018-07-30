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
 * ten_hl_config_api.h 
 *
 * API prototypes Header file for HL Configs.
 *
 * $Id: ten_hl_config_api.h,v 1.51 2014/03/23 23:41:02 pptawade Exp $
 *
 */
 
#ifndef __TEN_HL_CONFIG_API_H__
#define __TEN_HL_CONFIG_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_hl_config_10ge6_1_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk,
                                       cs_uint16 flow_ctrl_mode);
                                       
cs_status ten_hl_config_10ge6_1_otu2(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk,
                                     cs_uint16 flow_ctrl_mode);

cs_status ten_hl_config_10ge6_1_alt_odtu23(cs_uint16 module_id_line,
                                           cs_uint8  slice_line,
                                           cs_uint16 module_id_client,
                                           cs_uint8  slice_client,
                                           cs_uint8  dyn_repro,
                                           cs_uint16 line,
                                           cs_uint16 sysclk,
                                           cs_uint16 flow_ctrl_mode);
                                       
cs_status ten_hl_config_10ge6_1_alt_otu2(cs_uint16 module_id_line,
                                         cs_uint8  slice_line,
                                         cs_uint16 module_id_client,
                                         cs_uint8  slice_client,
                                         cs_uint8  dyn_repro,
                                         cs_uint16 sysclk,
                                         cs_uint16 flow_ctrl_mode);

cs_status ten_hl_config_pbert(cs_uint16 module_id,
                              cs_uint8  slice,
                              cs_uint16 profile,
                              cs_uint16 min_len,
                              cs_uint16 max_len,
                              cs_uint16 ifg);

cs_status ten_hl_config_8gfc_enh_odtu23(cs_uint16 module_id_line,
                                        cs_uint8  slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint8  slice_client,
                                        /* Bugzilla 20308 Start */
                                        cs_uint16 line,
                                        /* Bugzilla 20308 End */
                                        cs_uint8  dyn_repro,
                                        cs_uint16 sysclk);

cs_status ten_hl_config_8gfc_enh_otu2(cs_uint16 module_id_line,
                                      cs_uint8  slice_line,
                                      cs_uint16 module_id_client,
                                      cs_uint8  slice_client,
                                      cs_uint8  dyn_repro,
                                      cs_uint16 sysclk);

cs_status ten_hl_config_pbert_odtu23(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint16 line,
                                     cs_uint16 client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk);

cs_status ten_hl_config_otu2_otu2(cs_uint16 module_id_line,
                                  cs_uint8  slice_line,
                                  cs_uint16 module_id_client,
                                  cs_uint8  slice_client,
                                  cs_uint8  dyn_repro,
                                  cs_uint8  term_otu,
                                  cs_uint8  line_tcm,
                                  cs_uint8  client_tcm,
                                  cs_uint8  sync_mode);

/* Bugzilla 22514 Start */
cs_status ten_hl_config_otu2_xcon_loopback(cs_uint16 module_id,
                                         cs_uint8  slice,
                                         cs_uint16 traffic_type,
                                         cs_uint8  dyn_repro,
                                         cs_uint8  term_otu,
                                         cs_uint8  tcm,
                                         cs_uint16 sysclk);
/* Bugzilla 22514 End */
/* Bugzilla 22970 Start */
cs_status ten_hl_config_otu2_kpga (cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 traffic_type,
                                   cs_uint8  dyn_repro,
                                   cs_uint16 pattern,
                                   cs_uint16 data_in_stuff_bytes);

cs_status ten_hl_config_oc192_otu2_kpga (cs_uint16 module_id,
                                         cs_uint8  slice,
                                         cs_uint16 traffic_type,
                                         cs_uint8  dyn_repro,
                                         cs_uint16 pattern);
/* Bugzilla 22970 End */

cs_status ten_hl_config_otu2e_otu2e(cs_uint16 module_id_line,
                                    cs_uint8  slice_line,
                                    cs_uint16 module_id_client,
                                    cs_uint8  slice_client,
                                    cs_uint8  dyn_repro,
                                    cs_uint8  term_otu,
                                    cs_uint8  line_tcm,
                                    cs_uint8  client_tcm,
                                    cs_uint8  sync_mode);

cs_status ten_hl_config_otu1f_otu1f(cs_uint16 module_id_line,
                                    cs_uint8  slice_line,
                                    cs_uint16 module_id_client,
                                    cs_uint8  slice_client,
                                    cs_uint8  dyn_repro,
                                    cs_uint8  term_otu,
                                    cs_uint8  line_tcm,
                                    cs_uint8  client_tcm,
                                    cs_uint8  sync_mode);

cs_status ten_hl_config_otu2_odtu23(cs_uint16 module_id_line,
                                    cs_uint8  slice_line,
                                    cs_uint16 module_id_client,
                                    cs_uint8  slice_client,
                                    cs_uint8  line,
                                    cs_uint8  dyn_repro,
                                    cs_uint8  term_otu,
                                    cs_uint8  line_tcm,
                                    cs_uint8  client_tcm);
                                    
cs_status ten_hl_config_otu2e_odtu23(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint8  term_otu,
                                     cs_uint8  line_tcm,
                                     cs_uint8  client_tcm);

/* Bugzilla 43359 Start */                                    
cs_status ten_hl_config_otu2v_40gep_t41(cs_uint16 module_id_line,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 traffic_type_client,
                                        cs_uint16 fec_type,
                                        cs_uint16 deskew_ctrl,
                                        cs_uint16 sysclk);
/* Bugzilla 43359 End */

/* Bugzilla 20308 Start */
cs_status ten_hl_config_otu1e_odtu23(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  line,
                                     cs_uint8  dyn_repro,
                                     cs_uint8  term_otu,
                                     cs_uint8  line_tcm,
                                     cs_uint8  client_tcm);

cs_status ten_hl_config_10ge6_2_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk);
/* Bugzilla 20308 End */

cs_status ten_hl_config_10ge7_1_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk);
                                       
/* Bugzilla 20308 Start */
cs_status ten_hl_config_10ge7_2_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk);
/* Bugzilla 20308 End */

cs_status ten_hl_config_10ge7_3_odtu23(cs_uint16 module_id_line,
                                  cs_uint8  slice_line,
                                  cs_uint16 module_id_client,
                                  cs_uint8  slice_client,
                                  cs_uint8  dyn_repro,
                                  cs_uint16 line,
                                  cs_uint16 sysclk);
                                  
cs_status ten_hl_config_10ge7_3_otu2(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk);
                                     
cs_status ten_hl_config_10ge6_2_otu2(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk);
                                     
cs_status ten_hl_config_10ge7_1_otu2e(cs_uint16 module_id_line,
                                   cs_uint8  slice_line,
                                   cs_uint16 module_id_client,
                                   cs_uint8  slice_client,
                                   cs_uint8  dyn_repro,
                                   cs_uint16 sysclk);
                                   
/* Bugzilla 20308 Start */
cs_status ten_hl_config_10ge7_2_otu1e(cs_uint16 module_id_line,
                                      cs_uint8  slice_line,
                                      cs_uint16 module_id_client,
                                      cs_uint8  slice_client,
                                      cs_uint8  dyn_repro,
                                      cs_uint16 sysclk);
/* Bugzilla 20308 End */

cs_status ten_hl_config_10ge_tc_otu2e(cs_uint16 module_id_line,
                                      cs_uint8  slice_line,
                                      cs_uint16 module_id_client,
                                      cs_uint8  slice_client,
                                      cs_uint8  gfp_frame_format,
                                      cs_uint8  dyn_repro,
                                      cs_uint16 sysclk);

cs_status ten_hl_oc192_termination(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 term_sonet);
                                   
/* Bugzilla 22970 Start */
cs_status ten_hl_config_oc192_kpga (cs_uint16 module_id,
                                    cs_uint8  slice,
                                    cs_uint8  dyn_repro,
                                    cs_uint16 pattern);

cs_status ten_tx_config_sonet_generation (cs_uint16 module_id,
                                          cs_uint8  slice);
/* Bugzilla 22970 End */

cs_status ten_hl_config_10ge_10ge(cs_uint16 module_id_line,
                                  cs_uint8  slice_line,
                                  cs_uint16 module_id_client,
                                  cs_uint8  slice_client,
                                  cs_uint8  dyn_repro,
                                  cs_uint16 sync,
                                  cs_uint16 sysclk);

cs_status ten_hl_config_10gfc_otu1f(cs_uint16 module_id_line,
                                    cs_uint8  slice_line,
                                    cs_uint16 module_id_client,
                                    cs_uint8  slice_client,
                                    cs_uint8  dyn_repro,
                                    cs_uint16 sysclk);

cs_status ten_hl_config_10gfc_tc_odtu23(cs_uint16 module_id_line,
                                        cs_uint8  slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint8  slice_client,
                                        cs_uint16 line,
                                        cs_uint8  dyn_repro,
                                        cs_uint16 sysclk);

cs_status ten_hl_config_10gfc_tc_otu2e(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 sysclk);

cs_status ten_hl_config_oc192_odtu23(cs_uint16   module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint16 dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 term);

cs_status ten_hl_config_oc192_async_odtu23(cs_uint16 module_id_line,
                                           cs_uint8  slice_line,
                                           cs_uint16 module_id_client,
                                           cs_uint8  slice_client,
                                           cs_uint16 dyn_repro,
                                           cs_uint16 line,
                                           cs_uint16 term);

cs_status ten_hl_config_oc192_otu2(cs_uint16 module_id_line,
                                   cs_uint8  slice_line,
                                   cs_uint16 module_id_client,
                                   cs_uint8  slice_client,
                                   cs_uint16 dyn_repro,
                                   cs_uint16 line,
                                   cs_uint16 term,
                                   cs_uint16 fec,
                                   cs_uint16 sync,
                                   cs_uint16 k);

cs_status ten_hl_config_remove_soft_resets(cs_uint16 mod_line,
                                cs_uint8 slice_line,
                                cs_uint16 mod_client,
                                cs_uint8 slice_client,
                                cs_uint16 client,
                                cs_uint16 aggr);
                                   
cs_status ten_hl_config_remove_module_soft_resets(cs_uint16 module_id,
                                                  cs_uint8 slice,
                                                  cs_uint16 line);
                                   
cs_status ten_hl_config_aggregation_idle(cs_uint16 mod_line,
                                         cs_uint8 slice_line,
                                         cs_uint16 mod_client,
                                         cs_uint8 slice_client);
                                         
cs_status ten_hl_config_idle(cs_uint16 mod_line,
                             cs_uint8 slice_line,
                             cs_uint16 mod_client,
                             cs_uint8 slice_client,
                             cs_uint16 dyn_repro);


#ifndef TEN_NO_N40G
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
                                       cs_uint16 term_sonet);

/* Bugzilla 22514 Start */
cs_status ten_hl_config_otu3_xcon_loopback(cs_uint16 module_id,
                                         cs_uint16 traffic_type,
                                         cs_uint16 dyn_repro,
                                         cs_uint16 sync_mode,
                                         cs_uint16 term_otu,
                                         cs_uint16 tcm_bits);

cs_status ten_hl_config_oc768_xcon_loopback(cs_uint16 module_id,
                                         cs_uint16 traffic_type,
                                         cs_uint16 term_sonet);
/* Bugzilla 22514 End */

cs_status ten_hl_oc768_termination(cs_uint16 module_id_line,
                                   cs_uint16 module_id_client,
                                   cs_uint16 term);
                                       
cs_status ten_hl_40g_otu3_termination(cs_uint16 module_id,
                                      cs_uint16 term_otu,
                                      cs_uint16 tcm);

cs_status ten_hl_40g_otu3_rx_termination(cs_uint16 module_id,
                                         cs_uint16 term_otu);

cs_status ten_hl_40g_otu3_tx_termination(cs_uint16 module_id,
                                         cs_uint16 term_otu,
                                         cs_uint16 tcm);

/* Bugzilla 22970 Start */
cs_status ten_hl_config_otu3_kpga (cs_uint16 module_id,
                                   cs_uint16 traffic_type,
                                   cs_uint16 pattern,
                                   cs_uint16 data_in_stuff_bytes);

cs_status ten_hl_config_oc768_otu3_kpga (cs_uint16 module_id,
                                         cs_uint16 traffic_type,
                                         cs_uint16 pattern);

cs_status ten_hl_config_oc768_kpga (cs_uint16 module_id,
                                    cs_uint16 traffic_type,
                                    cs_uint16 pattern);
/* Bugzilla 22970 End */
#endif
                                  
cs_status ten_hl_config_pbert_otu2(cs_uint16 module_id_line,
                                   cs_uint8  slice_line,
                                   cs_uint16 module_id_client,
                                   cs_uint8  slice_client,
                                   cs_uint16 client,
                                   cs_uint8  dyn_repro,
                                   cs_uint16 sysclk);

cs_status ten_hl_config_8gfc_ra_otu2(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk);

cs_status ten_hl_config_otu2e_odtu23_fix(cs_uint16 module_id_line,
                                         cs_uint8  slice_line,
                                         cs_uint16 module_id_client,
                                         cs_uint8  slice_client,
                                         cs_uint8  line,
                                         cs_uint8  dyn_repro,
                                         cs_uint8  term_otu,
                                         cs_uint8  line_tcm,
                                         cs_uint8  client_tcm);

cs_status ten_hl_config_10ge_ra_otu2(cs_uint16 module_id_line,
                                     cs_uint8  slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint8  slice_client,
                                     cs_uint8  dyn_repro,
                                     cs_uint16 sysclk,
                                     cs_uint8  flow_ctrl_mode);

cs_status ten_hl_config_10ge_ra_odtu23(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 sysclk,
                                       cs_uint8  flow_ctrl_mode);

/* Bug 23864 Start */
cs_status ten_cb_rates(cs_uint16 dev_id,
                       double line_rate,
                       double client_rate);

cs_status ten_thread_set_cb_rates (cs_uint16 dev_id,
                                   cs_uint16 slice_client,
                                   double line_rate,
                                   double client_rate);

cs_status ten_calc_hyst(cs_uint16 dev_id);
/* Bug 23864 End  */

/* Bug 28237 Start  */
cs_status ten_calc_hyst_t41(cs_uint16 dev_id, cs_uint8 slice, cs_uint8  map_odtu);
/* Bug 28237 End  */


cs_status ten_hl_config_10ge_gfpf_oc192_otu2(cs_uint16 module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint8  dyn_repro,
                                       cs_uint16 sysclk);

cs_status ten_hl_config_oc192_otu2v_t41(cs_uint16 module_id_line,
                                        cs_uint16 slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint16 slice_client,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 fec_line,
                                        cs_uint16 term_oc192,
                                        cs_uint16 tcm_line,
                                        cs_uint16 map_oxuv);

cs_status ten_hl_config_oc192_otu2_sfi41_t41(cs_uint16 dev_id,
                                             cs_uint16 dyn_repro,
                                             cs_uint16 traffic_type_line,
                                             cs_uint16 fec_line,
                                             cs_uint16 term_oc192,
                                             cs_uint16 tcm_line,
                                             cs_uint16 map_oxuv);

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
                                        cs_uint16 gmp_timeslot_mask);

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
                                        cs_uint16 map_oxuv);

cs_status ten_hl_config_otu2v_otu2v_ufec_sfi41_t41(cs_uint16 dev_id,
                                                   cs_uint16 dyn_repro,
                                                   cs_uint16 traffic_type_line,
                                                   cs_uint16 fec_line,
                                                   cs_uint16 traffic_type_client,
                                                   cs_uint16 fec_client,
                                                   cs_uint16 term_otu,
                                                   cs_uint16 tcm_line,
                                                   cs_uint16 tcm_client,
                                                   cs_uint16 map_oxuv);

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
                                        cs_uint16 gmp_timeslot_mask);

cs_status ten_hl_config_10g_wire_t41_v2(cs_uint16 module_id_line,
                                        cs_uint16 slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint16 slice_client,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 traffic_type_client);
                                        
cs_status ten_hl_config_10g_wire_t41 (cs_uint16 module_id_line,
                                      cs_uint16 slice_line,
                                      cs_uint16 module_id_client,
                                      cs_uint16 slice_client,
                                      cs_uint16 dyn_repro);

/* Bugzilla 24559 Start */
cs_status ten_hl_config_10g_cbr_kpga_t41 (cs_uint16 module_id, 
                                          cs_uint16 slice,
                                          cs_uint16 pattern,
                                          cs_uint16 dyn_repro);
/* Bugzilla 24559 End */

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
                                       cs_uint16 flow_ctrl_mode);

cs_status ten_hl_config_10ge_otu2v_ufec_sfi41_t41(cs_uint16 dev_id,
                                                  cs_uint16 dyn_repro,
                                                  cs_uint16 traffic_type_line,
                                                  cs_uint16 fec_line,
                                                  cs_uint16 traffic_type_client,
                                                  cs_uint16 sysclk,
                                                  cs_uint16 tcm_line,
                                                  cs_uint16 gfp_frame_format,
                                                  cs_uint16 flow_ctrl_mode);

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
                                        cs_uint16 flow_ctrl_mode);

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
                                     cs_uint16 gmp_timeslot_mask);

/* Bugzilla 24360 Start */
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
                                      cs_uint16 gmp_timeslot_mask);

cs_status ten_hl_config_infiniband_otu2v_t41(cs_uint16 module_id_line,
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
                                             cs_uint16 gmp_timeslot_mask);

/* Bugzilla 38565 Start */
cs_status ten_hl_config_infiniband_otu3v_t41(cs_uint16 module_id_line,
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
                                             cs_uint16 gmp_timeslot_mask);
/* Bugzilla 38565 End */

cs_status ten_hl_config_infiniband_otu3v_t41(cs_uint16 module_id_line,
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
                                             cs_uint16 gmp_timeslot_mask);

cs_status ten_hl_config_oc768_otu3v_t41(cs_uint16 module_id_line,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 traffic_type_line,
                                        cs_uint16 fec_line,
                                        cs_uint16 term_oc768,
                                        cs_uint16 tcm_line,
                                        cs_uint16 mld_line,
                                        cs_uint16 mld_client,
                                        cs_uint16 map_oxuv,
                                        cs_uint16 timeslots);
/* Bugzilla 28977 Start */
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
                                           cs_uint16 deskew_ctrl);
/* Bugzilla 28977 End */

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
                                        cs_uint16 map_oxuv);
/* Bugzilla 28977 Start */
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
                                           cs_uint16 map_odtu,
                                           cs_uint16 map_oxuv,
                                           cs_uint16 deskew_ctrl);
/* Bugzilla 28977 End */

/* Bugzilla 28977 Start */
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
                                                  cs_uint16 deskew_ctrl);
/* Bugzilla 28977 End */
/* Bugzilla 27167 Start */
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
                                               cs_uint16 map_client);
/* Bugzilla 27167 End */
/* Bugzilla 28006 Start */
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
                                              cs_uint16 deskew_at_pp40g,
                                              cs_uint16 sysclk);
/* Bugzilla 28006 End */

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
                                             cs_uint16 map_client);

/* Bugzilla 27127 Start */
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
                                       cs_uint16 deskew_at_pp40g,
                                       cs_uint16 sysclk);
/* Bugzilla 27127 End */

cs_status ten_hl_config_oc768_kpga_t41(cs_uint16 module_id,
                                        cs_uint16 pattern,
                                        cs_uint16 mld,
                                        cs_uint16 data_in_stuff_bytes);

cs_status ten_hl_config_otu3v_kpga_t41(cs_uint16 module_id,
                                        cs_uint16 traffic_type,
                                        cs_uint16 fec,
                                        cs_uint16 pattern,
                                        cs_uint16 mld,
                                        cs_uint16 data_in_stuff_bytes);

cs_status ten_hl_config_oc768_otu3v_kpga_t41(cs_uint16 module_id,
                                             cs_uint16 traffic_type,
                                             cs_uint16 fec,
                                             cs_uint16 pattern,
                                             cs_uint16 mld,
                                             cs_uint16 data_in_stuff_bytes);
/* Bugzilla 24360 End */

cs_status ten_hl_config_40g_idle_t41 (cs_uint16 module_id_line, cs_uint16 dyn_repro); /* Bugzilla 29609 */

/* Bugzilla 24645 Start */
cs_status ten_hl_config_40g_wire_t41(cs_uint16 module_id_line);

cs_status ten_hl_config_40g_wire_t41_v2(cs_uint16 module_id_line,
                                        cs_uint16 line_traffic,
                                        cs_uint16 line_fec,
                                        cs_uint16 client_traffic,
                                        cs_uint16 client_fec);
/* Bugzilla 24645 End */

/* Bugzilla 24559 Start */
cs_status ten_hl_config_40g_cbr_kpga_t41 (cs_uint16 module_id, 
                                          cs_uint16 pattern);
/* Bugzilla 24559 End */

/* Bugzilla 28977 Start */
cs_status ten_hl_config_otu3v_xcon_loopback_t41_v2 (cs_uint16 module_id,
                                                    cs_uint16 dyn_repro,
                                                    cs_uint16 traffic_type,
                                                    cs_uint16 fec,
                                                    cs_uint16 term_otu,
                                                    cs_uint16 tcm_bits,
                                                    cs_uint16 mld,
                                                    cs_uint16 deskew_ctrl);
/* Bugzilla 28977 End */
/* Bugzilla 26525 Start */
cs_status ten_hl_config_otu3v_xcon_loopback_t41 (cs_uint16 module_id,
                                                 cs_uint16 dyn_repro,
                                                 cs_uint16 traffic_type,
                                                 cs_uint16 fec,
                                                 cs_uint16 term_otu,
                                                 cs_uint16 tcm_bits,
                                                 cs_uint16 mld);

/* Bugzilla 28977 Start */
cs_status ten_hl_config_oc768_xcon_loopback_t41_v2 (cs_uint16 module_id,  
                                                    cs_uint16 dyn_repro, 
                                                    cs_uint16 traffic_type, 
                                                    cs_uint16 term_oc768,
                                                    cs_uint16 mld,
                                                    cs_uint16 deskew_ctrl);
/* Bugzilla 28977 End */
cs_status ten_hl_config_oc768_xcon_loopback_t41 (cs_uint16 module_id,  
                                                 cs_uint16 dyn_repro, 
                                                 cs_uint16 traffic_type, 
                                                 cs_uint16 term_oc768,
                                                 cs_uint16 mld);
/* Bugzilla 26525 End */

cs_status ten_hl_config_40g_pbert_t41(cs_uint16           module_id,
                                      ten_xcon_len_mode_t mode, 
                                      cs_uint16           min_len,
                                      cs_uint16           max_len,
                                      cs_uint8            typelength_lsb,
                                      cs_uint8            typelength_msb,
                                      cs_uint16           ifg,
                                      ten_xcon_da_type_t  da_type);

/* Bug 24820: feature fc_ra_fc */
cs_status ten_hl_config_fc_ra_fc(cs_uint16 module_id_line,
                                 cs_uint8  slice_line,
                                 cs_uint16 module_id_client,
                                 cs_uint8  slice_client,
                                 cs_uint8  dyn_repro,
                                 cs_uint16 sysclk,
                                 cs_uint8  traffic_type);

cs_status ten_hl_config_passive_monitor(cs_uint16 mod_line,
                                        cs_uint8  slice_line,
                                        cs_uint16 mod_client,
                                        cs_uint8  slice_client,
                                        cs_uint16 type);

cs_status ten_hl_config_fc_oc192_t41(cs_uint16 module_id_line,
                                     cs_uint16 slice_line,
                                     cs_uint16 module_id_client,
                                     cs_uint16 slice_client,
                                     cs_uint16 dyn_repro,
                                     cs_uint16 traffic_type_line,
                                     cs_uint16 traffic_type_client,
                                     cs_uint16 sysclk);

cs_status ten_hl_config_oc192_oc192_t41(cs_uint16 module_id_line,
                                        cs_uint16 slice_line,
                                        cs_uint16 module_id_client,
                                        cs_uint16 slice_client,
                                        cs_uint16 dyn_repro,
                                        cs_uint16 term_oc192);

/* Bugzilla 37022 Start */
cs_status ten_hl_config_traffic_type_ra_same(cs_uint16 module_id_line,
                                             cs_uint16 slice_line,
                                             cs_uint16 module_id_client,
                                             cs_uint16 slice_client,
                                             cs_uint16 dyn_repro,
                                             cs_uint16 traffic_type,
                                             cs_uint16 sysclk,
                                             cs_uint16 gfp_frame_format,
                                             cs_uint16 flow_ctrl_mode);
                                        
cs_status ten_hl_config_10ge6_1_oc192_t41(cs_uint16 module_id_line,
                                          cs_uint16 slice_line,
                                          cs_uint16 module_id_client,
                                          cs_uint16 slice_client,
                                          cs_uint16 dyn_repro,
                                          cs_uint16 traffic_type_line,
                                          cs_uint16 traffic_type_client,
                                          cs_uint16 sysclk,
                                          cs_uint16 flow_ctrl_mode);
                                        
/* Bugzilla 37022 End */

cs_status ten_hl_config_40ge_40ge_t41(cs_uint16 module_id_line,
                                      cs_uint16 dyn_repro,
                                      cs_uint16 traffic_type_line,
                                      cs_uint16 traffic_type_client,
                                       cs_uint16 pp40g_tx_line_mode,
                                       cs_uint16 pp40g_rx_line_mode,
                                       cs_uint16 pp40g_tx_client_mode,
                                       cs_uint16 pp40g_rx_client_mode,
                                       cs_uint16 mld_line,
                                       cs_uint16 mld_client,
                                       cs_uint16 map_oxuv,
                                       cs_uint16 deskew_ctrl,
                                       cs_uint16 sysclk);

#ifdef __cplusplus
}
#endif
#endif


