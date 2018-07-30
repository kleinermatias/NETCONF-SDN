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
 * ten_hl_api.h
 *
 * API Header file for High Level Configs.
 *
 * $Id: ten_hl_api.h,v 1.103 2013/03/01 21:10:09 khill Exp $
 *
 */

#ifndef __TEN_HL_API_H__
#define __TEN_HL_API_H__

#ifdef __cplusplus
extern "C" {
#endif

void long_multiply (cs_uint32 num1, cs_uint32 num2);
cs_uint32 _round(double num);
cs_uint32 _power(cs_uint16 num, cs_uint16 exponent);

cs_status ten_hl_hsif_control_loopback(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint8 loopback,
                                      cs_ctl_t ctl);
                                      
cs_status ten_hl_hsif_control_loopback_with_user_settings(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint8 loopback,
                                      cs_ctl_t ctl,
                                      ten_hsif_loopback_settings_t *settings);
 
cs_status ten_hl_hsif_set_loopback_settings_version_num_cb(cs_uint16 dev_id,
                                                           cs_uint16 ver_num);

cs_status ten_hl_hsif_set_loopback_settings_version_num(cs_uint16 dev_id,
                                                        cs_uint16 ver_num,
                                                        ten_hsif_loopback_settings_t *settings);
                                                        
cs_status ten_hl_hsif_analog_cfg(cs_uint16 module_id,
                          cs_uint8 slice,
                          cs_uint8 protocol,
                          cs_uint8 timing_mode);

cs_status ten_hl_hsif_xfi_analog_cfg(cs_uint16 module_id,
                          cs_uint8 slice,
                          cs_uint16 rate,
                          cs_uint16 div);
                          
cs_status ten_hl_hsif_xfi_analog_cfg_srx_filtr(cs_uint16 module_id,
                          cs_uint8 slice,
                          cs_uint16 rate,
                          cs_uint16 div);
                          
cs_status ten_hl_hsif_config_table15(cs_uint16 module_id,
                                     cs_uint8 slice, 
                                     cs_uint16 rate);
                                     
cs_status ten_hl_hsif_xfi_download_micro_code(cs_uint16 module_id,
                                              cs_uint8 slice);
                                              
cs_status ten_hl_hsif_xfi_control_micro_code_verify(cs_ctl_t ctl);

cs_status ten_hl_hsif_xfi_control_micro_code_running_check(cs_ctl_t ctl);
              
cs_status ten_hl_hsif_xfi_verify_micro_code_download(cs_uint16 module_id, 
                                                    cs_uint8 slice);
                                                    
cs_int16 ten_hl_hsif_xfi_check_micro_code_status(cs_uint16 module_id, 
                                                cs_uint8 slice);
                                              
cs_status ten_hl_hsif_mr_switch_clock(cs_uint16 module_id,
                                      cs_uint8 slice);

cs_status ten_hl_config_xfi_t41(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint16 client,
                                cs_uint16 invert_dir,
                                cs_uint16 invert,
                                cs_uint32 sysclk_freq,
                                cs_uint16 prot,
                                cs_uint16 sync,
                                cs_uint16 aux_clk,
                                cs_uint16 waitfor_vcotune,
                                cs_uint16 div,
                                cs_uint16 clock_distribution,
                                cs_uint16 ext1,
                                cs_uint16 ext2);
                                      
cs_status ten_hl_config_xfi_with_div(cs_uint16 module_id,
                            cs_uint8 slice, 
                            cs_uint16 client, 
                            cs_uint16 invert_dir,
                            cs_uint16 invert,
                            cs_uint32 sysclk_freq,
                            cs_uint16 prot,
                            cs_uint16 sync,
                            cs_uint16 aux_clk,
                            cs_uint16 waitfor_vcotune,
                            cs_uint16 div);
                            
cs_status ten_hl_config_xfi(cs_uint16 module_id,
                            cs_uint8 slice, 
                            cs_uint16 client, 
                            cs_uint16 invert_dir,
                            cs_uint16 invert,
                            cs_uint32 sysclk_freq,
                            cs_uint16 prot,
                            cs_uint16 sync,
                            cs_uint16 aux_clk,
                            cs_uint16 waitfor_vcotune);
                                      
cs_status ten_hl_hsif_config_xfi(cs_uint16 module_id,
                                 cs_uint8 slice, 
                                 cs_uint16 rate, 
                                 cs_uint16 div, 
                                 cs_uint16 internal_pilot);
                                      
cs_status ten_hl_hsif_config_xfi_spare_cupll(cs_uint16 module_id,
                                             cs_uint8 slice,
                                             cs_uint16 rate,
                                             cs_uint16 div,
                                             cs_uint16 internal_pilot); /* Bugzilla 35116 */

cs_int16 ten_hl_hsif_xfi_waitfor_vcotune(cs_uint16 module_id,
                                          cs_uint8 slice);
                                          
cs_int16 ten_hl_hsif_mr_waitfor_vcotune(cs_uint16 module_id,
                                          cs_uint8 slice);

cs_status ten_hl_hsif_powerdown_xfi(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_ctl_t ctl);

cs_status ten_hl_hsif_powerdown_mr(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_ctl_t ctl);

cs_int16 ten_hl_hsif_check_xfi_vcotune(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_dir_t dir);

cs_int16 ten_hl_hsif_check_xfi_filt_lock(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_dir_t dir);

cs_int16 ten_hl_hsif_check_xfi_lock(cs_uint16 module_id,
                                    cs_uint8 slice,
                                    cs_dir_t dir);
                                       
cs_int16 ten_hl_hsif_check_mr_lock(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_dir_t dir);
                                   
cs_int16 ten_hl_hsif_check_mr_vcotune(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_dir_t dir);
                        
cs_int16 ten_hl_hsif_check_mr_filt_lock(cs_uint16 module_id,
                                        cs_uint8 slice,
                                        cs_dir_t dir);

cs_status ten_hl_config_sfi42_40g_transponder(cs_uint16 module_id,
                                              cs_uint16 divider, 
                                              cs_uint16 internal_pilot,
                                              cs_uint16 mr_protect,
                                              cs_uint16 sync);
                                              
/* Bugzilla #27364, add prototype */                                              
cs_status ten_hl_config_sfi42_10g(cs_uint16 module_id,
                            cs_uint8 slice,
                            cs_uint16 line,
                            cs_uint32 sysclk_freq,
                            cs_uint16 sync,
                            cs_uint16 enhanced_deskew);
                                                                   
cs_status ten_hl_config_sfi42_40g(cs_uint16 module_id,
                                  cs_uint16 divider, 
                                  cs_uint16 internal_pilot,
                                  cs_uint16 mr_protect);
                                  
cs_status ten_hl_hsif_config_sfi42_40g(cs_uint16 module_id,
                                       cs_uint16 divider, 
                                       cs_uint16 internal_pilot,
                                       cs_uint16 mr_protect);
                                       
cs_status ten_hl_config_sfi42_10g_t41(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint16 line,
                                      cs_uint32 sysclk_freq,
                                      cs_uint16 sync,
                                      cs_uint16 enhanced_deskew,
                                      cs_uint16 internal_pilot,
                                      cs_uint16 mr_protect);
                                      
cs_status ten_hl_hsif_config_sfi42_10g(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_uint16 internal_pilot,
                                       cs_uint16 mr_protect);
                                       
cs_status ten_hl_config_sfi51_40g_transponder(cs_uint16 module_id,
                                          cs_uint16 sync);
                                       
cs_status ten_hl_config_sfi51(cs_uint16 module_id);

cs_status ten_hl_hsif_config_sfi51(cs_uint16 module_id,
                                   cs_uint16 divider, 
                                   cs_uint16 internal_pilot,
                                   cs_uint16 mr_protect);
                                   
cs_status ten_hl_config_sfi51_t41(cs_uint16 module_id,
                                  cs_uint16 divider,
                                  cs_uint16 internal_pilot,
                                  cs_uint16 mr_protect);
  
cs_status ten_hl_config_xaui(cs_uint16 module_id,
                             cs_uint8 slice,
                             cs_uint16 internal_pilot,
                             cs_uint16 mr_protect);
                                   
cs_status ten_hl_hsif_config_xaui(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 internal_pilot,
                                  cs_uint16 mr_protect);
                                  
cs_status ten_hl_config_sfi41_v2(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint16 internal_pilot,
                                 cs_uint16 launch_data_txclk,
                                 cs_uint16 launch_data_rxclk);

cs_status ten_hl_hsif_config_sfi41_v2(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint16 internal_pilot,
                                 cs_uint16 launch_data_txclk,
                                 cs_uint16 launch_data_rxclk);
  
cs_status ten_hl_config_sfi41(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_uint16 internal_pilot); 
                                  
cs_status ten_hl_hsif_config_sfi41(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 internal_pilot);

cs_status ten_hl_hsif_mr_ring_oscillator_fix(cs_uint16 module_id,
                                             cs_uint8 slice);
 
cs_status ten_hl_hsif_sfi42_reset_fix (cs_uint16 dev_id);
                        
cs_status ten_hl_hsif_mr_resync(cs_uint16 module_id, 
                                cs_uint8 slice,
                                cs_dir_t dir);
                                
cs_status ten_hl_hsif_control_mr_tx_output(cs_uint16 module_id, 
                                           cs_uint8 slice,
                                           cs_ctl_t ctl);
                                
cs_status ten_hl_xcon_config(cs_uint16 dev_id, 
                          cs_uint8 es,
                          cs_uint8 channel,
                          cs_uint16 client);
                        
cs_status ten_hl_xcon_cfg(cs_uint16 dev_id, 
                          cs_uint8 slice,
                          cs_uint8 mode);

cs_status ten_hl_xcon_set_cbert_generator(cs_uint16 dev_id, cs_uint8 channel);

cs_status ten_hl_xcon_check_cbert(cs_uint16 dev_id, cs_uint8 channel, 
                                  cs_uint16 threshold);


/* Bugzilla 27270 Start T41 Release 5.4*/
cs_status ten_xcon_es_write_cb_t41(                cs_uint16 dev_id,
                                                   ten_xcon_es_num_t es_num,
                                                   cs_uint16 type,    /* AMP                FPA            EZ */
                                                   cs_uint16 arg1,    /* margin_lower   static_depth       type */
                                                   cs_uint16 arg2,    /* margin_upper   circuit_th_lower  margin */
                                                   cs_uint16 arg3,    /* correct_lower  circuit_th_upper        */
                                                   cs_uint16 arg4,    /* correct_upper                        */
                                                   cs_uint8  duration,   /* amp only */
                                                   cs_uint32 sysclk_freq);  /* amp only */

cs_status ten_xcon_es_setup_amp_recntr_from_cb_40g_t41(
                                                   cs_uint16 dev_id,
                                                   cs_uint8  module_num);

cs_status ten_xcon_es_setup_amp_recntr_from_cb_10g_t41(
                                                   cs_uint16 dev_id,
                                                   ten_xcon_es_num_t es_num);

/* Bugzilla 27270 Start T41 Release 5.3*/
cs_status ten_hl_xcon_es_amplitude_recenter_t41(cs_uint16 dev_id,
                                                ten_xcon_es_num_t es_num,
                                                cs_uint16 margin_lower,
                                                cs_uint16 margin_upper,
                                                cs_uint16 correct_lower,
                                                cs_uint16 correct_upper,
                                                cs_uint8  duration,
                                                cs_uint32 sysclk_freq);

cs_status ten_hl_xcon_es_amplitude_recenter_40g_t41(cs_uint16 dev_id,
                                                    cs_uint8  module_num,
                                                    cs_uint16 margin_lower,
                                                    cs_uint16 margin_upper,
                                                    cs_uint16 correct_lower,
                                                    cs_uint16 correct_upper,
                                                    cs_uint8  duration,
                                                    cs_uint32 sysclk_freq);

cs_status ten_hl_xcon_es_amplitude_recenter_with_fpa_t41(cs_uint16 dev_id,
                                                         ten_xcon_es_num_t es_num,
                                                         cs_uint16 static_depth,
                                                         cs_uint16 circuit_th_lower,
                                                         cs_uint16 circuit_th_upper);

cs_status ten_hl_xcon_es_amplitude_recenter_with_fpa_40g_t41(cs_uint16 dev_id,
                                                             cs_uint8  module_num,
                                                             cs_uint16 static_depth,
                                                             cs_uint16 circuit_th_lower,
                                                             cs_uint16 circuit_th_upper);
cs_status ten_hl_xcon_es_amplitude_recenter_from_cb_t41(cs_uint16 dev_id,
                                                 ten_xcon_es_num_t es_num);
/* Bugzilla 27270 End */
                                  
/* Bugzilla 24360 Start */
cs_status ten_hl_sadeco_config (cs_uint16 dev_id, 
                                cs_uint16 line_traffic_type,
                                cs_uint16 client_traffic_type,
                                cs_uint16 client_term,
                                cs_uint16 ncols_line,
                                cs_uint16 ncols_client,
                                cs_uint16 module_line);
/* Bugzilla 24360 End */

void long_multiply (cs_uint32 num1, cs_uint32 num2);
cs_uint32 _ten_floor (cs_float y);

cs_status ten_hl_syncdsync_reset(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_hl_syncdsync_config(cs_uint16 module_id,
                                  cs_uint8 slice, 
                                  cs_uint16 mode_rx, 
                                  cs_uint16 mode_tx, 
                                  cs_uint16 rx_div_mux);

cs_status ten_hl_syncdsync_map(cs_uint16 module_id,
                               cs_uint8 slice,
                               cs_uint16 mode);

cs_status ten_hl_syncdsync_demap(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint16 mode);
                               
cs_status ten_hl_syncdsync_map_k(cs_uint16 module_id,
                               cs_uint8 slice,
                               cs_uint16 mode,
                               cs_uint16 k);

cs_status ten_hl_syncdsync_demap_k(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint16 mode,
                                 cs_uint16 k);
                                 
cs_status ten_hl_syncdsync_datapath_config(cs_uint16 module_id_line,
                                           cs_uint8 slice_line, 
                                           cs_uint16 module_id_client,
                                           cs_uint8 slice_client,
                                           cs_uint8 mode,
                                           cs_uint8 sync_mode,
                                           cs_uint16 method,
                                           cs_uint8 k_divider,
                                           cs_uint8 line_fec,
                                           cs_uint8 client_fec);

cs_status ten_hl_syncdsync_threadsafe_datapath_config(cs_uint16 module_id_line,
                                                      cs_uint8 slice_line, 
                                                      cs_uint16 module_id_client,
                                                      cs_uint8 slice_client,
                                                      cs_uint8 mode,
                                                      cs_uint8 sync_mode,
                                                      cs_uint16 method,
                                                      cs_uint8 k_divider,
                                                      cs_uint8 line_fec,
                                                      cs_uint8 client_fec);

/* Bugzilla 26608 Start */
cs_status ten_hl_syncdsync_threadsafe_datapath_config_v2(cs_uint16 module_id_line,
                                                         cs_uint8 slice_line, 
                                                         cs_uint16 module_id_client,
                                                         cs_uint8 slice_client,
                                                         cs_uint8 mode,
                                                         cs_uint8 sync_mode,
                                                         cs_uint16 method,
                                                         cs_uint8 k_divider_line,
                                                         cs_uint8 k_divider_client,
                                                         cs_uint8 line_fec,
                                                         cs_uint8 client_fec);
/* Bugzilla 26608 End */

cs_status ten_hl_syncdsync_datapath_config_t41(cs_uint16 module_id_line,
                                               cs_uint8  slice_line, 
                                               cs_uint16 module_id_client,
                                               cs_uint8  slice_client,
                                               cs_uint8 fec_line,
                                               cs_uint8 fec_client,
                                               cs_uint8  mode,
                                               cs_uint16 method,
                                               cs_uint8  k_divider,
                                               cs_uint8  map_odtu,
                                               cs_uint8  map_oxuv,
                                               cs_uint8  gmp_timeslots);

/* Bugzilla 26608 Start */
cs_status ten_hl_syncdsync_datapath_config_v2(cs_uint16 module_id_line,
                                           cs_uint8 slice_line, 
                                           cs_uint16 module_id_client,
                                           cs_uint8 slice_client,
                                           cs_uint8 mode,
                                           cs_uint8 sync_mode,
                                           cs_uint16 method,
                                           cs_uint8 k_divider_line,
                                           cs_uint8 k_divider_client,
                                           cs_uint8 line_fec,
                                           cs_uint8 client_fec);
/* Bugzilla 26608 End */

cs_status ten_syncdsync_mux_1to1_async_2level_config(cs_uint16 module_id_line,
                                                     cs_uint8  slice_line, 
                                                     cs_uint16 module_id_client,
                                                     cs_uint8  slice_client,
                                                     cs_uint8  k_divider,
                                                     cs_uint32 n1, 
                                                     cs_uint32 n2, 
                                                     cs_uint32 m1, 
                                                     cs_uint32 m2, 
                                                     cs_uint16 num_pjo_oxuv, 
                                                     cs_uint16 num_pjo_odtu);

/* Bug 38779 Start */
cs_status ten_syncdsync_mux_1to1_async_2level_config_v2(cs_uint16 module_id_line,
                                                        cs_uint8  slice_line, 
                                                        cs_uint16 module_id_client,
                                                        cs_uint8  slice_client,
                                                        cs_uint8  k_divider_line,
                                                        cs_uint8  k_divider_client,
                                                        cs_uint32 n1, 
                                                        cs_uint32 n2, 
                                                        cs_uint32 m1, 
                                                        cs_uint32 m2, 
                                                        cs_uint16 num_pjo_oxuv, 
                                                        cs_uint16 num_pjo_odtu);
/* Bug 38779 End */

cs_status ten_syncdsync_mux_sync_async_1level_config(cs_uint16 module_id_line,
                                                     cs_uint8  slice_line, 
                                                     cs_uint16 module_id_client,
                                                     cs_uint8  slice_client,
                                                     cs_uint8  fec_client,
                                                     cs_uint8  k_divider,
                                                     cs_uint32 n1, 
                                                     cs_uint32 n2, 
                                                     cs_uint32 m1, 
                                                     cs_uint32 m2, 
                                                     cs_uint16 num_pjo_oxuv, 
                                                     cs_uint16 num_pjo_odtu);

cs_status ten_syncdsync_mux_async_async_1level_config(cs_uint16 module_id_line,
                                                      cs_uint8  slice_line, 
                                                      cs_uint16 module_id_client,
                                                      cs_uint8  slice_client,
                                                      cs_uint8  k_divider,
                                                      cs_uint32 n1, 
                                                      cs_uint32 n2, 
                                                      cs_uint32 m1, 
                                                      cs_uint32 m2, 
                                                      cs_uint16 num_pjo_oxuv, 
                                                      cs_uint16 num_pjo_odtu);

cs_status ten_syncdsync_trans_1to1_async_config(cs_uint16 module_id_line,
                                                cs_uint8  slice_line, 
                                                cs_uint16 module_id_client,
                                                cs_uint8  slice_client,
                                                cs_uint8  k_divider,
                                                cs_uint32 n1, 
                                                cs_uint32 m1, 
                                                cs_uint8  mode,
                                                cs_uint16 num_pjo_oxuv,
                                                cs_uint16 rate);            /* Bugzilla 26729 */

cs_status ten_syncdsync_trans_1to1_async_config_v2(cs_uint16 module_id_line,
                                                   cs_uint8  slice_line, 
                                                   cs_uint16 module_id_client,
                                                   cs_uint8  slice_client,
                                                   cs_uint8  k_divider_line,
                                                   cs_uint8  k_divider_client,
                                                   cs_uint32 n1,  
                                                   cs_uint32 m1, 
                                                   cs_uint8  mode,
                                                   cs_uint16 num_pjo_oxuv,
                                                   cs_uint16 rate);

cs_status ten_syncdsync_trans_1to1_async_config_v2(cs_uint16 module_id_line,
                                                   cs_uint8  slice_line, 
                                                   cs_uint16 module_id_client,
                                                   cs_uint8  slice_client,
                                                   cs_uint8  k_divider_line,
                                                   cs_uint8  k_divider_client,
                                                   cs_uint32 n1,  
                                                   cs_uint32 m1, 
                                                   cs_uint8  mode,
                                                   cs_uint16 num_pjo_oxuv,
                                                   cs_uint16 rate);

cs_status ten_syncdsync_trans_1to1_async_1to1_config(cs_uint16 module_id_line,
                                                     cs_uint8  slice_line, 
                                                     cs_uint16 module_id_client,
                                                     cs_uint8  slice_client,
                                                     cs_uint8  k_divider,
                                                     cs_uint32 n1, 
                                                     cs_uint32 m1,
                                                     cs_uint8  mode,
                                                     cs_uint16 num_pjo_oxuv,
                                                     cs_uint16 rate);       /* Bugzilla 26729 */

cs_status ten_syncdsync_trans_sync_async_config(cs_uint16 module_id_line,
                                                      cs_uint8  slice_line, 
                                                      cs_uint16 module_id_client,
                                                      cs_uint8  slice_client,
                                                      cs_uint8  k_divider,
                                                      cs_uint32 n1, 
                                                      cs_uint32 m1,
                                                      cs_uint32 n2, 
                                                      cs_uint32 m2,
                                                      cs_uint8  mode,
                                                      cs_uint16 num_pjo_oxuv,
                                                      cs_uint16 rate);       /* Bugzilla 26729 */

cs_status ten_syncdsync_trans_async_asyncx4_config(cs_uint16 module_id_line,
                                                   cs_uint8  slice_line, 
                                                   cs_uint16 module_id_client,
                                                   cs_uint8  slice_client,
                                                   cs_uint8  k_divider,
                                                   cs_uint32 n1,
                                                   cs_uint32 m1, 
                                                   cs_uint32 n2, 
                                                   cs_uint32 m2, 
                                                   cs_uint8 mode,
                                                   cs_uint16 num_pjo_oxuv1,
                                                   cs_uint16 num_pjo_oxuv2,
                                                   cs_uint16 rate);       /* Bugzilla 26729 */

/* Bugzilla 28006 Start */
cs_status ten_syncdsync_trans_async_async_1level_config(cs_uint16 module_id_line,
                                                cs_uint8  slice_line, 
                                                cs_uint16 module_id_client,
                                                cs_uint8  slice_client,
                                                cs_uint8  k_divider,
                                                cs_uint32 n1,
                                                cs_uint32 m1,
                                                cs_uint32 n2, 
                                                cs_uint32 m2,
                                                cs_uint8  mode,
                                                cs_uint16 num_pjo_oxuv1,
                                                cs_uint16 num_pjo_oxuv2,
                                                cs_uint16 rate);
/* Bugzilla 28006 End */

cs_status ten_syncdsync_1_to_1_config(cs_uint16 module_id_line,
                                      cs_uint8  slice_line, 
                                      cs_uint16 module_id_client,
                                      cs_uint8  slice_client,
                                      cs_uint8  k_divider);

cs_status ten_syncdsync_set_cb_transcode(cs_uint16 dev_id,
                                         cs_uint16 num,
                                         cs_uint16 denom);

cs_status ten_syncdsync_set_cb_40g_transponder(cs_uint16 dev_id,
                                               cs_int16 num_just_oxu3,
                                               cs_uint8 num_pjo_oxu3,
                                               cs_uint16 P_line,
                                               cs_uint16 Q_line,
                                               cs_uint16 P_client,
                                               cs_uint16 Q_client,
                                               cs_uint8 line_client_same,
                                               cs_uint8 line_client_rate_equal);

cs_status ten_syncdsync_set_cb_10g_transponder(cs_uint16 dev_id,
                                               cs_int16 num_just_oxu2,
                                               cs_uint8 num_pjo_oxu2,
                                               cs_uint16 P_line,
                                               cs_uint16 Q_line,
                                               cs_uint16 P_client,
                                               cs_uint16 Q_client,
                                               cs_uint8 line_client_same,
                                               cs_uint8 line_client_rate_equal);

cs_status ten_syncdsync_set_cb_10g_transponder_t41(cs_uint16 dev_id,
                                                   cs_uint8 slice_client,
                                                   cs_int16 num_just_oxu2,
                                                   cs_uint8 num_pjo_oxu2,
                                                   cs_uint16 P_line,
                                                   cs_uint16 Q_line,
                                                   cs_uint16 P_client,
                                                   cs_uint16 Q_client,
                                                   cs_uint8 line_client_same,
                                                   cs_uint8 line_client_rate_equal,
                                                   cs_uint8 oduflex_enbl,
                                                   cs_uint8 oduflex_client_slice,
                                                   cs_uint8 oduflex_line_slice,
                                                   double client_rate, 
                                                   double xcon_client_rate,
                                                   double line_rate);

cs_status ten_syncdsync_set_cb_40g_muxponder(cs_uint16 dev_id,
                                             cs_int16 num_just_oxu2,
                                             cs_uint8 num_pjo_oxu2,
                                             cs_int16 num_just_oxu3,
                                             cs_uint8 num_pjo_oxu3,
                                             cs_uint16 P_line,
                                             cs_uint16 Q_line,
                                             cs_uint16 P_client,
                                             cs_uint16 Q_client);

cs_status ten_syncdsync_set_cb_40g_muxponder_t41(cs_uint16 dev_id,
                                                 cs_uint8 slice_client,
                                                 cs_int16 num_just_oxu2,
                                                 cs_uint8 num_pjo_oxu2,
                                                 cs_int16 num_just_oxu3,
                                                 cs_uint8 num_pjo_oxu3,
                                                 cs_uint16 P_line,
                                                 cs_uint16 Q_line,
                                                 cs_uint16 P_client,
                                                 cs_uint16 Q_client,
                                                 double client_rate,
                                                 double xcon_client_rate,
                                                 double line_rate);


cs_status ten_syncdsync_set_cb_40g_transponder_t41(cs_uint16 dev_id,
                                                   cs_uint8 slice_client,
                                                   cs_int16 num_just_oxu3,
                                                   cs_uint8 num_pjo_oxu3,
                                                   cs_uint16 P_line,
                                                   cs_uint16 Q_line,
                                                   cs_uint16 P_client,
                                                   cs_uint16 Q_client,
                                                   double client_rate, 
                                                   double xcon_client_rate,
                                                   double line_rate,
                                                   cs_uint8 line_client_same,
                                                   cs_uint8 line_client_rate_equal);


/* Bugzilla 28006 Start */
cs_status ten_syncdsync_set_cb_40g_transponder_dual_async_t41(cs_uint16 dev_id,
                                                        cs_uint8 slice_client,
                                                        cs_int16 num_just_oxu3,
                                                        cs_uint8 num_pjo_oxu3,
                                                        cs_int16 num_just_oxu3_client,
                                                        cs_uint8 num_pjo_oxu3_client,
                                                        cs_uint16 P_line,
                                                        cs_uint16 Q_line,
                                                        cs_uint16 P_client,
                                                        cs_uint16 Q_client,
                                                        double client_rate, 
                                                        double xcon_client_rate,
                                                        double line_rate);
/* Bugzilla 28006 End */

cs_status ten_syncdsync_thread_set_cb_transcode(cs_uint16 dev_id,
                                                cs_uint8 slice_client,
                                                cs_uint16 num,
                                                cs_uint16 denom);

cs_status ten_syncdsync_thread_set_cb_40g_transponder(cs_uint16 dev_id,
                                                      cs_uint8 slice_client,
                                                      cs_int16 num_just_oxu3,
                                                      cs_uint8 num_pjo_oxu3,
                                                      cs_uint16 P_line,
                                                      cs_uint16 Q_line,
                                                      cs_uint16 P_client,
                                                      cs_uint16 Q_client,
                                                      cs_uint8 line_client_same,
                                                      cs_uint8 line_client_rate_equal);

cs_status ten_syncdsync_thread_set_cb_10g_transponder(cs_uint16 dev_id,
                                                      cs_uint8 slice_client,
                                                      cs_int16 num_just_oxu2,
                                                      cs_uint8 num_pjo_oxu2,
                                                      cs_uint16 P_line,
                                                      cs_uint16 Q_line,
                                                      cs_uint16 P_client,
                                                      cs_uint16 Q_client,
                                                      cs_uint8 line_client_same,
                                                      cs_uint8 line_client_rate_equal);

cs_status ten_syncdsync_thread_set_cb_40g_muxponder(cs_uint16 dev_id,
                                                      cs_uint8 slice_client,
                                                      cs_int16 num_just_oxu2,
                                                      cs_uint8 num_pjo_oxu2,
                                                      cs_int16 num_just_oxu3,
                                                      cs_uint8 num_pjo_oxu3,
                                                      cs_uint16 P_line,
                                                      cs_uint16 Q_line,
                                                      cs_uint16 P_client,
                                                      cs_uint16 Q_client);

cs_status ten_hl_mpif_fec_init(cs_uint16 module_id,
                               cs_uint16 slice,
                               ten_fec_type_t fec_type,
                               cs_uint16 fec_en);
                                
cs_status ten_hl_ufec_ed_config(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_dir_t dir, 
                                cs_ctl_t ctrl,
                                cs_uint16 n_cols);

cs_uint16 ten_hl_mpif_wait_for_bist_done (cs_uint16 dev_id);

cs_status ten_hl_n40g_config(cs_uint16 module_id,
                              cs_uint8 mode_rx,
                              cs_uint8 mode_tx);

cs_status ten_hl_n40g_rx_init(cs_uint16 module_id,
                              cs_uint8 mode);
                              
cs_status ten_hl_n40g_tx_init(cs_uint16 module_id,
                              cs_uint8 mode);
                              
cs_status ten_hl_n40g_async_dewrap_generic_40g_client_sw_workaround(cs_uint16 module_id,
                                                      cs_uint8 block_id);

cs_status ten_hl_n40g_map_chnl_ts(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_dir_t dir,
                                  cs_uint8 timeslot1,
                                  cs_uint8 timeslot2,
                                  cs_uint8 timeslot3,
                                  cs_uint8 timeslot4);

cs_status ten_hl_n40g_cfg_async_odtu23(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_dir_t dir,
                                       cs_uint16 fs_bytes,
                                       cs_uint8 c15_bytes);
                                       
cs_status ten_hl_n40g_config_pti(cs_uint16 module_id,
                                 cs_uint16 client);

cs_status ten_hl_n40g_config_pti_t41 (cs_uint16 module_id,
                                      cs_uint16 client,
                                      cs_uint16 map_proc,
                                      cs_uint16 timeslots,
                                      cs_uint16 kpga_en);

cs_status ten_hl_n40g_otl3_4_mld_t41 (cs_uint16 module_id, 
                                      cs_uint16 client_traffic_type,
                                      cs_uint16 fec);
                                      
cs_status ten_n40g_clear_gmp_ho_client_data_entity_t41(cs_uint16 module_id,
                                                       cs_uint16 slice);                                     
                                      
cs_status ten_hl_n10g_config(cs_uint16 module_id,
                             cs_uint8 slice,
                             cs_uint8 mode_rx,
                             cs_uint8 mode_tx,
                             cs_uint16 dyn_repro);
                             
cs_status ten_hl_n10g_rx_init(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_uint8 mode);

cs_status ten_hl_n10g_reconfig_rx_init(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_uint8 mode);

cs_status ten_hl_n10g_tx_init(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_uint8 mode);

cs_status ten_hl_n10g_reconfig_tx_init(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_uint8 mode);

cs_status ten_hl_n10g_rx_trans_regen(cs_uint16 module_id,
                                     cs_uint8 slice);

cs_status ten_hl_n10g_tx_trans_regen(cs_uint16 module_id,
                                     cs_uint8 slice);

cs_status ten_hl_n10g_rx_section_term(cs_uint16 module_id,
                                      cs_uint8  slice,
                                      cs_uint8  term_otu);

cs_status ten_hl_n10g_tx_section_term(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint8  term_otu,
                                      cs_uint8 bipmsk);

cs_status ten_hl_n10g_config_termination(cs_uint16 module_id,
                                         cs_uint8  slice,
                                         cs_uint8  term_otu,
                                         cs_uint8  tcm);
                                         
cs_status ten_hl_n10g_config_pti(cs_uint16 module_id,
                                 cs_uint8  slice,
                                 cs_uint16 client,
                                 cs_uint16 sync);
                                 
cs_status ten_hl_n10g_config_pti_t41 (cs_uint16 module_id,
                                      cs_uint8  slice,
                                      cs_uint16 client,
                                      cs_uint16 mapper,
                                      cs_uint16 map_proc,
                                      cs_uint16 timeslots,
                                      cs_uint16 kpga);

cs_status ten_hl_fec_config(cs_uint16 module_id, 
                            cs_uint8 slice,
                            ten_fec_type_t fec_type,
                            ten_fec_action_t action,
                            ten_fec_ovhd_t overhead);
                              
cs_int16 ten_hl_get_fec_usage_status (cs_uint16 module_id,
                                      cs_uint8 slice,
                                      ten_fec_type_t fec_type);

/* Bugzilla 24339 Start */
cs_status ten_hl_config_fec_t41 (cs_uint16 module_id,
                                 cs_uint8  slice,
                                 cs_uint16 size,
                                 cs_uint16 overhead);
                                 
cs_status ten_dev_init_fec_cb (cs_uint16 dev_id);
/* Bugzilla 24339 End */

cs_status ten_hl_pp10g_config(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_uint8 mode_rx, 
                              cs_uint8 mode_tx);
                                 
cs_status ten_hl_pp10g_rx_init(cs_uint16 module_id,
                               cs_uint8 slice,
                               cs_uint8 mode);
                               
cs_status ten_hl_pp10g_tx_init(cs_uint16 module_id,
                               cs_uint8 slice,
                               cs_uint8 mode);

cs_status ten_hl_pp10g_flow_init(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint8 mode);
                               
cs_status ten_hl_pp10g_force_cmf_fdi(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 state);

cs_status ten_hl_pp10g_force_cmf_rdi(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 state);

cs_status ten_hl_pp10g_force_cmf_dci(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 state);
                               
cs_status ten_hl_pbert_init(cs_uint16 dev_id,
                            ten_xcon_es_num_t es_num,
                            ten_xcon_ifg_symbol_t symbol,
                            cs_uint8 column_idx,
                            ten_xcon_encoding_t encoding,
                            cs_uint8 mode);
                            
cs_status ten_hl_resets_block(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_reset_action_t act,
                              cs_uint16 block);

cs_status ten_hl_resets_global(cs_uint16 dev_id,
                               cs_module_t module_num,
                               cs_uint16 slice,
                               cs_dir_t dir, 
                               cs_reset_action_t act,
                               cs_uint16 block);
                               
cs_status ten_hl_fracdiv_config(cs_uint16 dev_id, 
                              cs_uint16 instance,
                              cs_uint32 sysclk_freq, 
                              cs_uint32 desired_freq);

cs_status ten_hl_fracdiv_init(cs_uint16 dev_id, 
                              cs_uint16 instance,
                              cs_uint32 sysclk_freq, 
                              cs_uint32 desired_freq);

#ifndef TEN_NO_N40G
cs_status ten_hl_ohpp_force_otu3_ais(cs_uint16 module_id,
                                     cs_uint16 state);
#endif

cs_status ten_hl_ohpp_force_otu2_ais(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 state);

#ifndef TEN_NO_N40G
cs_status ten_hl_ohpp_force_odu3_maintenance_signal(cs_uint16 module_id,
                                                    cs_uint8 signal,
                                                    cs_uint8 width,
                                                    cs_uint16 state);

cs_status ten_hl_ohpp_enable_odu3_maintenance_signal(cs_uint16 module_id,
                                                     cs_uint8 signal,
                                                     cs_uint8 width,
                                                     cs_uint16 state);
#endif

cs_status ten_hl_ohpp_force_odu2_maintenance_signal(cs_uint16 module_id,
                                                    cs_uint8 slice,
                                                    cs_uint8 signal,
                                                    cs_uint8 width,
                                                    cs_uint16 state);

cs_status ten_hl_ohpp_enable_odu2_maintenance_signal(cs_uint16 module_id,
                                                     cs_uint8 slice,
                                                     cs_uint8 signal,
                                                     cs_uint8 width,
                                                     cs_uint16 state);

#ifndef TEN_NO_N40G
cs_status ten_hl_ohpp_force_opu3_pn11(cs_uint16 module_id,
                                      cs_uint16 state);

cs_status ten_hl_ohpp_enable_opu3_pn11(cs_uint16 module_id,
                                       cs_uint16 state);
#endif

cs_status ten_hl_ohpp_force_opu2_pn11(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint16 state);

cs_status ten_hl_ohpp_enable_opu2_pn11(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_uint16 state);

cs_status ten_hl_ohpp_force_aisl(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint16 state);

cs_status ten_hl_ohpp_enable_aisl(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 state);

cs_status ten_hl_ohpp_force_circuit_pp10g_insert(cs_uint16 module_id,
                                                 cs_uint8  slice,
                                                 cs_uint16 state);

cs_status ten_hl_ohpp_enable_circuit_pp10g_insert(cs_uint16 module_id,
                                                  cs_uint8  slice,
                                                  cs_uint16 state);

cs_status ten_hl_ohpp_dump_msignal(cs_uint16 module_id);

cs_status ten_hl_ohpp_dump_osignal(cs_uint16 module_id);
                                         
cs_status ten_hl_ohpp_switch_sfc_ram(cs_uint16 module_id);

cs_status ten_hl_ohpp_commit_shadow_sfc_ram(cs_uint16 module_id,
                                            cs_uint16 bank);

cs_status ten_hl_ohpp_dump_consequent_action_events (cs_uint16 module_id,
                                                     cs_uint8 row);

cs_status ten_hl_ohpp_dump_shadow_consequent_action_events (cs_uint16 module_id,
                                                            cs_uint16 bank,
                                                            cs_uint8 row);

cs_status ten_hl_ohpp_dump_doe_ram(cs_uint16 module_id,
                                   cs_uint8  string);

cs_status ten_hl_ohpp_dump_doi_ram(cs_uint16 module_id,
                                   cs_uint8  string);
                                         
cs_status ten_hl_ohpp_and_shadow_ram_init(cs_uint16 dev_id);

/* Bugzilla #30405, add prototypes */
cs_status ten_hl_configure_40g_accepted_tti_unit(cs_uint16 module_id, 
                             cs_uint16 layer, 
                             cs_uint16 unit, 
                             cs_uint16 tti_str_size);
                             
cs_status ten_hl_set_40g_inserted_tti_unit(cs_uint16 module_id, 
                             cs_uint16 layer, 
                             cs_uint16 unit, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str);
                             
cs_status ten_hl_get_40g_accepted_tti_unit(cs_uint16 module_id, 
                             cs_uint16 layer, 
                             cs_uint16 unit, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str);

cs_status ten_hl_print_40g_accepted_tti_unit(cs_uint16 module_id, 
                                        cs_uint16 layer,
                                        cs_uint16 unit,
                                        cs_uint16 tti_str_size);

cs_status ten_hl_set_40g_expected_tti_unit(cs_uint16 module_id, 
                                      cs_uint16 layer, 
                                      cs_uint16 unit,
                                      cs_uint16 tti_cmp, 
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str);

cs_status ten_hl_set_40g_inserted_tti(cs_uint16 module_id, 
                             cs_uint16 layer, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str);

cs_status ten_hl_get_40g_accepted_tti(cs_uint16 module_id, 
                             cs_uint16 layer, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str);
                             
cs_status ten_hl_print_40g_accepted_tti(cs_uint16 module_id, 
                                        cs_uint16 layer,
                                        cs_uint16 tti_str_size);

cs_status ten_hl_set_40g_expected_tti(cs_uint16 module_id, 
                                      cs_uint16 layer, 
                                      cs_uint16 tti_cmp,
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str);

cs_status ten_hl_set_40g_string_hysteresis(cs_uint16 module_id, 
                                        cs_uint8 sesiv, 
                                        cs_uint8 sestv, 
                                        cs_uint8 seuiv,  
                                        cs_uint8 seutv);
                                        
                                        
cs_status ten_hl_set_40g_inserted_psi(cs_uint16 module_id, 
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str);
                             
cs_status ten_hl_get_40g_accepted_psi(cs_uint16 module_id, 
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str);
                             
cs_status ten_hl_print_40g_accepted_psi(cs_uint16 module_id, 
                                        cs_uint16 psi_str_size);
                                        
cs_status ten_hl_set_40g_expected_psi(cs_uint16 module_id, 
                                      cs_uint16 psi_cmp, 
                                      cs_uint16 psi_str_size,
                                      cs_char8 *psi_str);                                       

cs_status ten_hl_set_40g_inserted_psi_unit(cs_uint16 module_id, 
                             cs_uint16 starting_unit,
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str);
                             
cs_status ten_hl_get_40g_accepted_psi_unit(cs_uint16 module_id, 
                             cs_uint16 starting_unit,
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str);
                             
cs_status ten_hl_print_40g_accepted_psi_unit(cs_uint16 module_id, 
                                        cs_uint16 starting_unit,
                                        cs_uint16 psi_str_size);
                                        
cs_status ten_hl_set_40g_expected_psi_unit(cs_uint16 module_id, 
                                      cs_uint16 starting_unit,
                                      cs_uint16 psi_cmp, 
                                      cs_uint16 psi_str_size,
                                      cs_char8 *psi_str);
                                      
/* Bugzilla #30405, add prototypes */
cs_status ten_hl_configure_10g_accepted_tti_unit(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint16 layer, 
                             cs_uint16 unit,
                             cs_uint16 tti_str_size) ;
                                      
cs_status ten_hl_set_10g_inserted_tti_unit(cs_uint16 module_id,
                             cs_uint8 slice, 
                             cs_uint16 layer, 
                             cs_uint16 unit,
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str);
                             
cs_status ten_hl_get_10g_inserted_tti(cs_uint16 module_id, 
                                      cs_uint8 slice, 
                                      cs_uint16 layer,
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str);
                                      
cs_status ten_hl_print_10g_inserted_tti(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 layer,
                                        cs_uint16 tti_str_size);
   
cs_status ten_hl_get_10g_accepted_tti_unit(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint16 layer, 
                             cs_uint16 unit,
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str);

cs_status ten_hl_print_10g_accepted_tti_unit(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 layer,
                                        cs_uint16 unit,
                                        cs_uint16 tti_str_size);
                                        
cs_status ten_hl_set_10g_expected_tti_unit(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 layer, 
                                      cs_uint16 unit, 
                                      cs_uint16 tti_cmp, 
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str);

cs_status ten_hl_print_10g_expected_tti(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 layer,
                                        cs_uint16 tti_str_size);
                                        
cs_status ten_hl_get_10g_expected_tti(cs_uint16 module_id, 
                                      cs_uint8 slice, 
                                      cs_uint16 layer,
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str);
                                      
cs_status ten_hl_set_10g_inserted_tti(cs_uint16 module_id,
                             cs_uint8 slice, 
                             cs_uint16 layer, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str);

cs_status ten_hl_get_10g_accepted_tti(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint16 layer, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str);
                             
cs_status ten_hl_print_10g_accepted_tti(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 layer,
                                        cs_uint16 tti_str_size);

cs_status ten_hl_set_10g_expected_tti(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 layer, 
                                      cs_uint16 tti_cmp, 
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str);

cs_status ten_hl_set_10g_string_hysteresis(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint8 sesiv, 
                                        cs_uint8 sestv, 
                                        cs_uint8 seuiv,  
                                        cs_uint8 seutv);

cs_status ten_hl_set_10g_inserted_psi(cs_uint16 module_id,
                             cs_uint8 slice, 
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str);
                             
cs_status ten_hl_get_10g_accepted_psi(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str);
                             
cs_status ten_hl_print_10g_accepted_psi(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 psi_str_size);
                                        
cs_status ten_hl_set_10g_expected_psi(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 psi_cmp, 
                                      cs_uint16 psi_str_size,
                                      cs_char8 *psi_str);
                                      
cs_status ten_hl_set_10g_inserted_psi_unit(cs_uint16 module_id,
                             cs_uint8 slice, 
                             cs_uint16 starting_unit,
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str);
                             
cs_status ten_hl_get_10g_accepted_psi_unit(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint16 starting_unit,
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str);
                             
cs_status ten_hl_print_10g_accepted_psi_unit(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 starting_unit,
                                        cs_uint16 psi_str_size);
                                        
cs_status ten_hl_set_10g_expected_psi_unit(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 starting_unit,
                                      cs_uint16 psi_cmp, 
                                      cs_uint16 psi_str_size,
                                      cs_char8 *psi_str);                                     

cs_status ten_hl_pp10g_force_tx_10GE_RF(cs_uint16 module_id,
                                        cs_uint8  slice,
                                        cs_uint16 state);

cs_status ten_hl_pp10g_force_rx_10GE_RF(cs_uint16 module_id,
                                        cs_uint8  slice,
                                        cs_uint16 state);

cs_status ten_hl_pp10g_force_tx_10GE_LF(cs_uint16 module_id,
                                        cs_uint8  slice,
                                        cs_uint16 state);

cs_status ten_hl_pp10g_force_rx_10GE_LF(cs_uint16 module_id,
                                        cs_uint8  slice,
                                        cs_uint16 state);
                                        
cs_status ten_hl_pp10g_set_gsti_for_1ms(cs_uint16 dev_id, 
                                        cs_uint32 sys_clk);
                                        
cs_status ten_hl_pp10g_rx_reset(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_reset_action_t act);
                                
cs_status ten_hl_pp10g_tx_reset(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_reset_action_t act);
                                
cs_status ten_hl_ohpp_init(cs_uint16 module_id);

cs_status ten_hl_ohpp_control_oduk_oci(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_ctl_t ctl);

cs_status ten_hl_ohpp_doi_ram_config(cs_uint16 module_id,
                                     cs_uint8 doa_insert_enbl,
                                     cs_uint8 mgt_ovhd_stream,
                                     cs_uint8 ram_byte_start_idx,
                                     cs_uint8 ram_byte_stop_idx,
                                     cs_uint8 ram_byte_value,
                                     cs_uint8 insert_oh_ctrl,
                                     cs_uint8 mfas_match_unit,
                                     cs_uint8 mfas_match_cmp,
                                     cs_uint8 mfas_match_mask);

cs_status ten_hl_config_global(cs_uint16 dev_id, 
                                cs_uint16 a_mode, 
                                cs_uint16 b_mode,
                                cs_uint16 mbclksel,
                                cs_uint16 mr_mode_a_not_sfi41,
                                cs_uint16 mr_mode_b_not_sfi41); 

cs_status ten_hl_gpllx1_config_SYSGPLL(cs_uint16 dev_id, cs_uint16 mbclksel);

cs_uint16 ten_hl_gpllx1_check_lock(cs_uint16 dev_id, 
                                     cs_uint16 inst); 

cs_status ten_hl_gpllx1_init(cs_uint16 dev_id, 
                              cs_uint8  instance, 
                              cs_uint8  mode, 
                              cs_uint16 stxp_pd);
                              
cs_int16 ten_hl_gpllx1_waitfor_vcotune (cs_uint16 dev_id, 
                                        cs_uint8 instance);
 
cs_status ten_hl_gpllx1_waitfor_gpll_lock_40g(cs_uint16 dev_id, 
                                          cs_uint8 instance);

cs_status ten_hl_gpllx1_waitfor_gpll_lock_40g_t41(cs_uint16 dev_id,      /* Bugzilla 31529 */
                                                  cs_uint8  module_num);

cs_status ten_hl_gpllx1_waitfor_gpll_lock(cs_uint16 dev_id, 
                                          cs_uint8 instance);

cs_status ten_hl_gpllx1_waitfor_gpll_lock_t41(cs_uint16 dev_id,         /* Bugzilla 31529 */
                                              cs_uint8  module_num,
                                              cs_uint8  slice);
  
cs_status ten_hl_xfi_config_clockmux_t41(cs_uint16 module_id, 
                                         cs_uint8  slice, 
                                         cs_uint16 aux_clk,
                                         cs_uint16 k_value,
                                         cs_uint16 stxp_pilot_sel,
                                         cs_uint16 cupll_in_use);
  
cs_status ten_hl_xfi_config_clockmux(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 srx_rdiv_sel, 
                                     cs_uint16 srx_ctvdiv_sel, 
                                     cs_uint16 stxp_ctrdiv_sel,
                                     cs_uint16 aux_clk);
                                     
cs_status ten_hl_mr_config_clockmux(cs_uint16 module_id, cs_uint8 slice);
                                
cs_status ten_hl_mr_40g_config_clockmux(cs_uint16 module_id);

/* Bugzilla 23772 Start */
cs_status ten_hl_config_10g_hsif_kpga (cs_uint16 module_id,
                                       cs_uint8  slice,
                                       cs_uint16 hsif,
                                       cs_uint16 invertPrbs,
                                       cs_uint16 pattern);

cs_status ten_hl_config_40g_hsif_kpga (cs_uint16 module_id,
                                       cs_uint16 hsif,
                                       cs_uint16 invertPrbs,
                                       cs_uint16 pattern);
/* Bugzilla 23772 End */

cs_status ten_hl_hsif_xfi_check_kpga (cs_uint16 module_id, cs_uint8 slice);	 /* Bugzilla 26403 */

/* Bugzilla 24360 Start */
cs_status ten_hl_n10g_config_t41(cs_uint16 module_id, 
                                 cs_uint16 slice,
                                 cs_uint16 dyn_repro,
                                 cs_uint16 client,
                                 cs_uint16 mapper,
                                 cs_uint16 fec,
                                 cs_uint16 map_oxuv,
                                 cs_uint16 map_odtu,
                                 cs_uint16 timeslots,
                                 cs_uint16 gmp_timeslot_mask,
                                 cs_uint16 term_type,
                                 cs_uint16 tcm_bits);

/* Bugzilla 26565,  Network Config test 6, Dual Mux*/
cs_status ten_hl_n40g_mux_just_control (cs_uint16 module_id,
                                        cs_uint8 slice,
                                        cs_uint8 jcen,
                                        cs_uint8 jc_plus);

/* Bugzilla 24956 Start */
cs_status ten_hl_n40g_config_lom_from_traffic (cs_uint16 module_id, 
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec);

cs_status ten_hl_n40g_config_lom_from_bps (cs_uint16 module_id, 
                                           double signal_rate);

cs_status ten_hl_n10g_config_lom_from_traffic (cs_uint16 module_id, 
                                               cs_uint8  slice,
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec);

cs_status ten_hl_n10g_config_lom_from_bps (cs_uint16 module_id, 
                                           cs_uint8  slice,
                                           double signal_rate);
                                           
cs_status ten_hl_n10g_config_lof_from_traffic (cs_uint16 module_id,
                                               cs_uint8  slice,
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec);
                                               
cs_status ten_hl_n10g_config_lof_from_bps(cs_uint16 module_id,
                                          cs_uint8  slice,
                                          double signal_rate);
/* Bugzilla 24956 End */

/* Bugzilla 31127 Start */
cs_status ten_hl_n40g_config_lof_from_traffic (cs_uint16 module_id, 
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec);

cs_status ten_hl_n40g_config_lof_from_bps (cs_uint16 module_id, 
                                           double signal_rate);

cs_status ten_hl_n40g_config_lof_obfa2_from_bps (cs_uint16 module_id, 
                                                 double signal_rate);

cs_status ten_hl_n40g_config_lom_obfa2_from_bps (cs_uint16 module_id, 
                                                 double signal_rate);

cs_status ten_hl_n40g_config_lom_obfa2_from_traffic (cs_uint16 module_id, 
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec);

cs_status ten_hl_n40g_config_lof_obfa2_from_traffic (cs_uint16 module_id, 
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec);
/* Bugzilla 31127 End */


/* Bugzilla 29100 Start */
cs_status ten_n40g_mux_mapper_t41 (cs_uint16 module_id, 
                               cs_uint16 client_traffic_type,
                               cs_uint16 slice_line,
                               cs_uint16 mapper,
                               cs_uint16 map_proc,
                               cs_uint16 timeslots,
                               cs_uint16 gmp_timeslot_mask,
                               cs_int16  num_just);
/* Bugzilla 29100 End */

cs_status ten_hl_n40g_config_mux_t41(cs_uint16 line_module_id, 
                                     cs_uint16 client,
                                     cs_uint16 mapper,
                                     cs_uint16 fec_line,
                                     cs_uint16 slice_line,
                                     cs_uint16 dyn_repro,
                                     cs_uint16 map_proc,
                                     cs_uint16 timeslots,
                                     cs_uint16 gmp_timeslot_mask,
                                     cs_uint16 term_type,
                                     cs_uint16 tcm_bits,
                                     cs_uint16 mld_enbl);

cs_status ten_hl_n40g_config_trans_t41(cs_uint16 line_module_id, 
                                       cs_uint16 client,
                                       cs_uint16 mapper,
                                       cs_uint16 fec,
                                       cs_uint16 map_proc,
                                       cs_uint16 timeslots,
                                       cs_uint16 gmp_timeslot_mask,
                                       cs_uint16 term_type,
                                       cs_uint16 tcm_bits,
                                       cs_uint16 mld_enbl,
                                       cs_uint16 kpga);

cs_status ten_hl_pp10g_config_t41(cs_uint16 module_id,
                                  cs_uint16 slice,
                                  cs_uint16 client,
                                  cs_uint16 mapper,
                                  cs_uint16 sysclk,
                                  cs_uint16 flow_ctrl_mode,
                                  cs_uint16 gfp_frame_format,
                                  cs_uint16 hsif_is_xaui);

/* Bugzilla 27127 Start */
cs_status ten_hl_pp40g_config_t41(cs_uint16 module_id,
                                  cs_uint16 mode_rx,
                                  cs_uint16 mode_tx,
                                  cs_uint16 deskew_at_pp40g,
                                  cs_uint16 sysclk);
/* Bugzilla 27127 End */

cs_status ten_hl_pp40g_rx_init_t41(cs_uint16 module_id,
                                   cs_uint8 mode);

cs_status ten_hl_pp40g_tx_init_t41(cs_uint16 module_id,
                                   cs_uint8 mode);


/* Bugzilla 24360 End */

/* bugzilla #22614, debug functions moved to debug directory. */

/* Bugzilla 21101 Start: SFU Config dump enhancements */
cs_status ten_hl_ohpp_dump_osignal_loop(cs_uint16 module_id,
                                        cs_uint16 loop,
                                        cs_uint32 wait);

cs_status ten_hl_ohpp_dump_consequent_actions_all (cs_uint16 module_id);

cs_status ten_hl_ohpp_dump_shadow_consequent_actions_all (cs_uint16 module_id,
                                                          cs_uint16 bank);

cs_status ten_hl_ohpp_dump_sfu (cs_uint16 module_id);
/* Bugzilla 21101 End: SFU Config dump enhancements */

cs_status ten_hl_n40g_otn_aligner_settings(cs_uint16 module_id);

cs_status ten_hl_xcon_config_t41(cs_uint16   dev_id,
                                 cs_uint8    es_index,
                                 cs_uint8    es_source,
                                 cs_uint8    interface,
                                 cs_uint8    mfp_mode,
                                 cs_uint8    gfp_mode,
                                 cs_uint8    pkt_mode,
                                 cs_uint8    fp_align,
                                 cs_uint8    recenter_type,
                                 cs_uint32   sysclk_freq);
                                 
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
                                cs_uint16 cfp_srx_rx_misc_srx_eqadj);
  
cs_int16 ten_hl_hsif_cfp_waitfor_vcotune(cs_uint16 module_id,
                                         cs_uint8 slice);
                                         
cs_status ten_hl_cfp_config_clockmux(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 aux_clk);
                                     
cs_status ten_hl_hsif_cfp_control_power_t41(cs_uint16 module_id,
                                            cs_uint8 slice,
                                            cs_ctl_t ctl);
                                            
cs_status ten_hl_hsif_cfp_check_kpga_t41 (cs_uint16 module_id, cs_uint8 slice); /* Bugzilla 26403 */

cs_status ten_hl_cupll_config_mode_t41(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 cupll_mode);
                                       
cs_status ten_set_cb_cupll_t41(cs_uint16 dev_id,
                               cs_uint8  source,
                               cs_uint16 k_value,
                               cs_uint32 freq,
                               cs_uint16 preloadfint,
                               cs_uint32 preloadffrac,
                               cs_uint32 pdoffset,
                               cs_uint16 holdovercount,
                               cs_uint16 k1fscale,
                               cs_uint16 k1fshift,
                               cs_uint16 z1fscale,
                               cs_uint16 z1fshift,
                               cs_uint16 p1fscale,
                               cs_uint16 p1fshift,
                               cs_uint16 p2fscale,
                               cs_uint16 p2fshift,
                               cs_uint16 p3fscale,
                               cs_uint16 p3fshift,
                               cs_uint16 k1sscale,
                               cs_uint16 k1sshift,
                               cs_uint16 z1sscale,
                               cs_uint16 z1sshift,
                               cs_uint16 p1sscale,
                               cs_uint16 p1sshift,
                               cs_uint16 p2sscale,
                               cs_uint16 p2sshift,
                               cs_uint16 p3sscale,
                               cs_uint16 p3sshift,
                               cs_uint16 resetcount,
                               cs_uint16 sdmode);

cs_status ten_set_cb_cupll_calc_t41(cs_uint16 dev_id,
                                    double    rate,
                                    cs_uint8  source,
                                    cs_uint16 k_value,
                                    cs_uint32 freq,
                                    cs_uint32 pdoffset);

/* Bugzilla 35199 Start */
cs_status ten_set_cb_cupll_calc_t41_v2(cs_uint16 dev_id,
                                    double    rate,
                                    cs_uint8  source,
                                    cs_uint16 k_value,
                                    cs_uint32 freq,
                                    cs_uint32 pdoffset,
                                    cs_uint8  subrate_div);
/* Bugzilla 35199 End */

/* Bugzilla 36358  Start */
cs_status ten_set_cb_stand_alone_cupll_t41(cs_uint16 dev_id,
                                           double    rate,
                                           cs_uint8  source,
                                           cs_uint16 k_value,
                                           cs_uint32 freq,
                                           cs_uint32 pdoffset,
                                           cs_uint8  subrate_div,
                                           double    stand_alone_cupll_rate);
/* Bugzilla 36358  End */

cs_uint16 ten_cupll_make_shift(double coeffin);

cs_uint32 ten_cupll_two_pow(cs_uint16 in);

cs_status ten_hl_cupll_config_t41(cs_uint16 module_id,
                                  cs_uint8  slice);

/* Bugzilla 36358  Start */
cs_status ten_hl_stand_alone_cupll_config_t41(cs_uint16 module_id,
                                              cs_uint8  slice,
                                              cs_uint8  calibrate,
                                              cs_uint8  source_clean,
                                              cs_uint8  source_jittery,
                                              cs_uint16 rx_div_mux,
                                              double    f_in_clean,
                                              double    f_in_jittery,
                                              double    f_out);
/* Bugzilla 36358  End */

cs_status ten_hl_cupll_calibrate_config_t41(cs_uint16 dev_id,
                                            cs_uint8  slice);

cs_status ten_cupll_lockdet_filter_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stable_period);

cs_uint16 ten_cupll_lockdet_intstatus_filt_locks_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cupll_lockdet_intstatus_bad_vco_clks_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cupll_lockdet_intstatus_locks_t41(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_cupll_reset_t41(cs_uint16         module_id,
                              cs_uint8          slice, 
                              cs_uint8          select,
                              cs_reset_action_t act);

cs_status ten_xfi_cupll_pdoutsel_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 pdoutsel);

cs_status ten_xfi_cupll_countershift_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 countershift);

cs_status ten_xfi_cupll_counterctrl_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 counterctrl);

cs_status ten_xfi_cupll_pdoffset_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint32 pdoffset);

cs_status ten_xfi_cupll_holdover_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 holdover_select,
                                     cs_uint16 holdover_count);

cs_status ten_xfi_cupll_pdcal_t41(cs_uint16 module_id,
                                  cs_uint8  slice, 
                                  cs_uint16 pdcalsel,
                                  cs_uint16 pdcaloverride);

cs_status ten_xfi_cupll_filtsel_t41(cs_uint16 module_id,
                                    cs_uint8  slice, 
                                    cs_uint16 filtsels,
                                    cs_uint16 filtself);

cs_status ten_xfi_cupll_freq_t41(cs_uint16 module_id,
                                 cs_uint8  slice, 
                                 cs_uint16 select,
                                 cs_uint16 scale,
                                 cs_uint16 shift);

cs_status ten_xfi_cupll_preloadfint_t41(cs_uint16 module_id,
                                        cs_uint8  slice, 
                                        cs_uint16 preloadfint);

cs_status ten_xfi_cupll_preloadffrac_t41(cs_uint16 module_id,
                                         cs_uint8  slice, 
                                         cs_uint32 preloadffrac);

cs_status ten_xfi_cupll_sden_t41(cs_uint16 module_id,
                                 cs_uint8  slice, 
                                 cs_ctl_t  sden);

cs_status ten_xfi_cupll_sdmode_t41(cs_uint16 module_id,
                                   cs_uint8  slice, 
                                   cs_uint16 sdmode);
                                           
cs_status ten_xfi_cupll_ringerrorctrl_t41(cs_uint16 module_id,
                                          cs_uint16 slice, 
                                          cs_uint16 resetcount, 
                                          cs_uint16 hiloerroren, 
                                          cs_uint16 fixbubble, 
                                          cs_uint16 timeouten, 
                                          cs_uint16 ringerroren);

cs_status ten_pdcal_reset_seq_t41(cs_uint16  dev_id);

cs_status ten_pdcal_ctrl_t41(cs_uint16 dev_id,
                             cs_uint16 PDcounter,
                             cs_uint16 CounterShift,
                             cs_uint16 SignInv,
                             cs_uint16 bwsel2,
                             cs_uint16 CounterCtrl,
                             cs_uint16 bwsel1,
                             cs_uint16 skip2,
                             cs_uint16 skip1,
                             cs_uint16 monSel,
                             cs_uint16 PDen);

cs_status ten_pdcal_scale_t41(cs_uint16 dev_id,
                              cs_uint32 scale);

cs_status ten_pdcal_gro_ctrl_t41(cs_uint16 dev_id,
                                 cs_uint16 RefSel,
                                 cs_uint16 CLKINV,
                                 cs_uint16 mode,
                                 cs_uint16 pd);

cs_status ten_pdcal_gro_refdiv_t41(cs_uint16 dev_id,
                                   cs_uint16 RefDiv);

cs_status ten_pdcal_gro_spare_t41(cs_uint16 dev_id,
                                   cs_uint16 spare);

/* Bugzilla 35376 Start */
cs_status ten_pdcal_ringerrorctrl_t41(cs_uint16 dev_id,
                                      cs_uint16 ResetCount,
                                      cs_uint16 hiloErrorEn,
                                      cs_uint16 fixBubble,
                                      cs_uint16 TimeoutEn,
                                      cs_uint16 RingErrorEn);
/* Bugzilla 35376 End */

cs_status ten_cupll_toggle_cupll_reset_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_setup_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_ref_pilot_setup_1_xfi_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_311m_r_10m_c_9_95_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_311m_r_10m_c_11_05_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_311m_r_10m_c_11_7_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_425m_r_10m_c_9_95_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_425m_r_10m_c_11_05_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_425m_r_10m_c_11_7_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_311m_r_160m_c_9_95_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_311m_r_160m_c_11_05_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_311m_r_160m_c_11_7_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_425m_r_160m_c_9_95_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_425m_r_160m_c_11_05_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_loop_425m_r_160m_c_11_7_data_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_enable_cupll_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_start_tuning_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_start_rx_cfp_tuning_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_start_cfp_tuning_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_cupll_rxdiv_is_ref_t41 (cs_uint16 module_id, cs_uint8);

cs_status ten_n10g_gmp_off_t41 (cs_uint16 module_id, 
                                   cs_uint16 slice);

cs_status ten_hl_syncdsync_datapath_config_t41_v2(cs_uint16 module_id_line,
                                                  cs_uint8  slice_line, 
                                                  cs_uint16 module_id_client,
                                                  cs_uint8  slice_client,
                                                  cs_uint8 fec_line,
                                                  cs_uint8 fec_client,
                                                  cs_uint8  mode,
                                                  cs_uint16 method,
                                                  cs_uint8  k_divider_line,
                                                  cs_uint8  k_divider_client,
                                                  cs_uint8  map_odtu,
                                                  cs_uint8  map_oxuv,
                                                  cs_uint8  gmp_timeslots);     

cs_status ten_hl_hsif_power_down_serdes(cs_uint16 module_id);
     
cs_status ten_hl_hsif_cfp_retune_vco(cs_uint16 module_id, 
                                     cs_uint8 slice);
                                     
cs_status ten_hl_hsif_cfp_retune_vco_v2(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint8  dyn_repro,
                                        cs_uint16 traffic);
                                        
 cs_uint16 ten_hl_hsif_cfp_get_current_traffic(cs_uint16 module_id, 
                                              cs_uint8 slice);
                                              
cs_status ten_hl_n10g_reconfig_set_defaults(cs_uint16 module_id,
                                            cs_uint8 slice);                                            
#ifdef __cplusplus
}
#endif
#endif


