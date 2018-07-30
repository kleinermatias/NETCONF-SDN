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
 * ten_hsif_api.h
 *
 * API Header file for HSIF block.
 *
 * $Id: ten_hsif_api.h,v 1.36 2013/02/22 20:49:56 jccarlis Exp $
 *
 */

#ifndef __TEN_HSIF_API_H__
#define __TEN_HSIF_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_hsif_reset(cs_uint16 module_id, cs_reset_action_t act, cs_uint16 bitfield);

cs_status ten_hsif_provision_datapath(cs_uint16 module_id, cs_uint8 instance,
                                      cs_uint16 tx_xfiselect, cs_uint16 rx_xfiselect,
                                      cs_uint16 tx_pswtchen, cs_uint16 tx_mrprotocol,
                                      cs_uint16 rx_pswtchen, cs_uint16 rx_mrprotocol);

cs_status ten_hsif_provision_datapath_t41(cs_uint16 module_id, 
                                          cs_uint8 instance, 
                                          cs_uint16 tx_pswtchen, 
                                          cs_uint16 tx_mrprotocol, 
                                          cs_uint16 rx_pswtchen, 
                                          cs_uint16 rx_mrprotocol);
                                          
cs_status ten_hsif_provision_mrprotocol(cs_uint16 module_id,
                                        cs_uint8  instance, 
                                        cs_dir_t  dir,
                                        cs_uint16 mrprotocol);

cs_status ten_hsif_provision_tx_xfiselect(cs_uint16 module_id,
                                          cs_uint8 instance, 
                                          cs_uint16 tx_xfiselect);
                                          
cs_status ten_hsif_provision_pswtchen(cs_uint16 module_id, 
                                      cs_uint8 instance, 
                                      cs_dir_t dir, 
                                      cs_uint16 pswtchen);
  
cs_uint16 ten_hsif_is_xaui_active(cs_uint16 module_id, cs_uint8 instance);

cs_uint16 ten_hsif_is_sfi42_active(cs_uint16 module_id, cs_uint8 instance);

cs_uint16 ten_hsif_get_provisioned_datapath(cs_uint16 module_id, cs_uint8 instance,
                                            cs_uint16 select, 
                                            cs_dir_t dir);

cs_status ten_hsif_set_tx_laneswap(cs_uint16 module_id, cs_uint8 instance,
                                   cs_uint16 lane);

cs_status ten_hsif_set_rx_laneswap(cs_uint16 module_id, cs_uint8 instance,
                                   cs_uint16 lane);

cs_status ten_hsif_facility_loopback(cs_uint16 module_id, cs_uint8 instance,
                                     cs_ctl_t ctl);

cs_status ten_hsif_far_end_loopback(cs_uint16 module_id, cs_uint8 instance, cs_ctl_t ctl);

cs_status ten_hsif_tx_rx_elastic_store_control(cs_uint16 module_id, cs_uint8 instance,
                                               cs_reset_action_t act);

cs_status ten_hsif_rx_tx_elastic_store_control(cs_uint16 module_id, cs_uint8 instance,
                                               cs_reset_action_t act);

cs_status ten_hsif_tx_protection_switching_elastic_store_control(cs_uint16 module_id,
                                                                 cs_uint8 instance,
                                                                 cs_reset_action_t act);

cs_status ten_hsif_rx_protection_switching_elastic_store_control(cs_uint16 module_id,
                                                                 cs_uint8 instance,
                                                                 cs_reset_action_t act);

cs_status ten_hsif_misc_xlos_pswtchen(cs_uint16 module_id, 
                                      cs_uint16 xlos_pswtchen);
                                      
cs_status ten_hsif_misc_hw_pswtchen(cs_uint16 module_id, 
                                    cs_uint16 hw_pswtchen);
                                    
cs_status ten_hsif_misc_sint_sel(cs_uint16 module_id, 
                                 cs_uint16 sint_sel);
                                 
cs_status ten_hsif_misc_xfi_sync_mode(cs_uint16 module_id, 
                                      cs_uint16 xfi_sync_mode);
                                      
cs_status ten_hsif_misc_xfi_xlos_broadcast(cs_uint16 module_id, 
                                           cs_uint16 xfi_xlos_broadcast);
                                           
cs_status ten_hsif_sfi41_cfg_spare(cs_uint16 module_id, cs_uint16 sfi41_spare);

cs_status ten_hsif_sfi41_cfg_spare_launch_data_rxclk(cs_uint16 module_id, 
                                                     cs_uint16 value);                                                     
 
cs_status ten_hsif_sfi41_cfg_spare_launch_data_txclk(cs_uint16 module_id, 
                                                     cs_uint16 value);  

cs_status ten_hsif_bitshuffle(cs_uint16 module_id, cs_uint16 txprecoder_stride,
                              cs_uint16 rxdecoder_stride);

cs_status ten_hsif_set_precoder_cfga(cs_uint16 module_id,
                                     cs_uint8 instance, 
                                     cs_uint16 tti);

cs_status ten_hsif_set_precoder_cfgb(cs_uint16 module_id,
                                     cs_uint8 instance, 
                                     cs_uint16 ttq);

cs_status ten_hsif_set_decoder_cfga(cs_uint16 module_id,
                                    cs_uint8 instance, 
                                    cs_uint16 tta);

cs_status ten_hsif_set_decoder_cfgb(cs_uint16 module_id,
                                    cs_uint8 instance, 
                                    cs_uint16 ttb);
                                    
cs_status ten_hsif_pswtch_ok_ctrl_synced_en(cs_uint16 module_id, 
                                            cs_uint8 slice,
                                            cs_uint16 synced_en);
                                            
cs_status ten_hsif_pswtch_ok_ctrl_datadet_en(cs_uint16 module_id, 
                                             cs_uint8 slice,
                                             cs_uint16 datadet_en);
                                             
cs_status ten_hsif_pswtch_ok_ctrl_lock_en(cs_uint16 module_id, 
                                          cs_uint8 slice,
                                          cs_uint16 lock_en);
                                          
cs_status ten_hsif_pswtch_ok_ctrl_xlos_en(cs_uint16 module_id, 
                                          cs_uint8 slice,
                                          cs_uint16 xlos_en);
                                          
cs_status ten_hsif_fp_access_enable(cs_uint16 module_id,
                                    cs_ctl_t ctl);
                                    
cs_status ten_hsif_sfu_access_enable(cs_uint16 module_id,
                                     cs_uint16 ball_select,
                                     cs_ctl_t ctl);                                   
                                    
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_config(cs_uint16 module_id,
                                                         cs_uint8 instance,
                                                         cs_uint16 srx_buswidth);

cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_config(cs_uint16 module_id,
                                                         cs_uint8 instance,
                                                         cs_uint16 srx_buswidth);

cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 srx_ddiv_sel,
                                                              cs_uint16 srx_rdiv_sel);

cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 srx_ddiv_sel,
                                                              cs_uint16 srx_rdiv_sel);

cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_loop_filter(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 srx_filtr);

cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_loop_filter(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 srx_filtr);

cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_cpa(cs_uint16 module_id,
                                                      cs_uint8 instance,
                                                      cs_uint16 srx_cpcur1,
                                                      cs_uint16 srx_cpcur0);

cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_cpa(cs_uint16 module_id,
                                                      cs_uint8 instance,
                                                      cs_uint16 srx_cpcur1,
                                                      cs_uint16 srx_cpcur0);

cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_cpb(cs_uint16 module_id,
                                                      cs_uint8 instance,
                                                      cs_uint16 srx_phsel);

cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_cpb(cs_uint16 module_id,
                                                      cs_uint8 instance,
                                                      cs_uint16 srx_phsel);

cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_misc(cs_uint16 module_id,
                                                       cs_uint8 instance,
                                                       cs_uint16 srx_eqadj);

cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_misc(cs_uint16 module_id,
                                                       cs_uint8 instance,
                                                       cs_uint16 srx_eqadj);

cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_spare(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 srx_spare);

cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_spare(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 srx_spare);

cs_status ten_hsif_slc0_mr10x4_sds_common_rxvco0_thres0(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 freq_thres_sign0,
                                                        cs_uint16 freq_thres0);

cs_status ten_hsif_slc0_mr10x4_sds_common_rxvco0_thres1(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 freq_thres_sign1,
                                                        cs_uint16 freq_thres1);

cs_status ten_hsif_slc2_mr10x4_sds_common_rxvco0_thres0(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 freq_thres_sign0,
                                                        cs_uint16 freq_thres0);

cs_status ten_hsif_slc2_mr10x4_sds_common_rxvco0_thres1(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 freq_thres_sign1,
                                                        cs_uint16 freq_thres1);

cs_status ten_hsif_slc0_mr10x4_sds_common_rxvco0_control(cs_uint16 module_id,
                                                         cs_uint8 instance,
                                                         cs_uint16 val);

cs_status ten_hsif_slc2_mr10x4_sds_common_rxvco0_control(cs_uint16 module_id,
                                                         cs_uint8 instance,
                                                         cs_uint16 val);

cs_status ten_hsif_slc0_mr10x4_sds_common_rxvco0_set_short_ovride(cs_uint16 module_id,
                                                                  cs_uint8 instance,
                                                                  cs_uint16 short_ovride);

cs_status ten_hsif_slc2_mr10x4_sds_common_rxvco0_set_short_ovride(cs_uint16 module_id,
                                                                  cs_uint8 instance,
                                                                  cs_uint16 short_ovride);
                                                                  
cs_status ten_hsif_slc0_mr10x4_sds_common_txlockd0_filter(cs_uint16 module_id, 
                                                      cs_uint16 stable_period);
                                                      
cs_status ten_hsif_slc2_mr10x4_sds_common_txlockd0_filter(cs_uint16 module_id, 
                                                      cs_uint16 stable_period);
                                                                 
cs_status ten_hsif_slc0_mr10x4_sds_common_txvco0_set_short_ovride(cs_uint16 module_id,
                                                                  cs_uint16 short_ovride);

cs_status ten_hsif_slc2_mr10x4_sds_common_txvco0_set_short_ovride(cs_uint16 module_id,
                                                                  cs_uint16 short_ovride);

cs_status ten_hsif_slc0_mr10x4_sds_common_rxlockd0_resolution(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 lock_res);

cs_status ten_hsif_slc2_mr10x4_sds_common_rxlockd0_resolution(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 lock_res);
                                                              
cs_status ten_hsif_slc0_mr10x4_sds_common_rxlockd0_filter(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 stable_period);

cs_status ten_hsif_slc2_mr10x4_sds_common_rxlockd0_filter(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 stable_period);

cs_boolean ten_hsif_slc0_mr10x4_get_sds_rx_lock_status(cs_uint16 module_id,
                                                       cs_uint8 instance);

cs_boolean ten_hsif_slc2_mr10x4_get_sds_rx_lock_status(cs_uint16 module_id,
                                                       cs_uint8 instance);
                                                       
cs_boolean ten_hsif_slc0_mr10x4_get_sds_rx_filt_lock_status(cs_uint16 module_id,
                                                       cs_uint8 instance);

cs_boolean ten_hsif_slc2_mr10x4_get_sds_rx_filt_lock_status(cs_uint16 module_id,
                                                       cs_uint8 instance);
                                                       
cs_status ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrla(cs_uint16 module_id,
                                                               cs_uint8 instance,
                                                               cs_uint16 stx_level);

cs_status ten_hsif_slc2_mr10x4_sds_common_stx0_tx_output_ctrla(cs_uint16 module_id,
                                                               cs_uint8 instance,
                                                               cs_uint16 stx_level);
                                                               
cs_status ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrlb(cs_uint16 module_id, 
                                                               cs_uint8 instance, 
                                                               cs_uint16 stx_pre_peak, 
                                                               cs_uint16 stx_post_peak);

cs_status ten_hsif_slc2_mr10x4_sds_common_stx0_tx_output_ctrlb(cs_uint16 module_id, 
                                                               cs_uint8 instance, 
                                                               cs_uint16 stx_pre_peak, 
                                                               cs_uint16 stx_post_peak);
                                                               
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config(cs_uint16 module_id,
                                                          cs_uint16 stxp_lptime_sel,
                                                          cs_uint16 stxp_pilot_sel,
                                                          cs_uint16 stxp_buswidth);

cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config(cs_uint16 module_id,
                                                          cs_uint16 stxp_lptime_sel,
                                                          cs_uint16 stxp_pilot_sel,
                                                          cs_uint16 stxp_buswidth);
                                                          
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lptime_sel);
                                                      
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_pilot_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_pilot_sel);
                                                      
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_buswidth(cs_uint16 module_id, 
                                                      cs_uint16 stxp_buswidth);
                                                      
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lpbken(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lpbken);
                                                      
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lptime_sel);
                                                      
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_pilot_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_pilot_sel);
                                                      
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_buswidth(cs_uint16 module_id, 
                                                      cs_uint16 stxp_buswidth);
                                                      
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lpbken(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lpbken);
                                                      
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(cs_uint16 module_id,
                                                               cs_uint16 stxp_ddiv_sel,
                                                               cs_uint16 stxp_rdiv_sel);

cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(cs_uint16 module_id,
                                                               cs_uint16 stxp_ddiv_sel,
                                                               cs_uint16 stxp_rdiv_sel);

cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl(cs_uint16 module_id,
                                                               cs_uint16 stxp_tclkien);

cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl(cs_uint16 module_id,
                                                               cs_uint16 stxp_tclkien);

cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl_clkouten(cs_uint16 module_id, 
                                                           cs_uint16 stxp_clkouten);
                                                           
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl_clkouten(cs_uint16 module_id, 
                                                           cs_uint16 stxp_clkouten);                                                               
                                                               
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_loop_filter(cs_uint16 module_id,
                                                               cs_uint16 stxp_filtr);

cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_loop_filter(cs_uint16 module_id,
                                                               cs_uint16 stxp_filtr);

cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_cp(cs_uint16 module_id,
                                                      cs_uint16 stxp_cpcur1,
                                                      cs_uint16 stxp_cpcur0);

cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_cp(cs_uint16 module_id,
                                                      cs_uint16 stxp_cpcur1,
                                                      cs_uint16 stxp_cpcur0);

cs_status ten_hsif_slc0_mr10x4_sds_common_txvco0_thres0(cs_uint16 module_id,
                                                        cs_uint16 freq_thres_sign0,
                                                        cs_uint16 freq_thres0);

cs_status ten_hsif_slc0_mr10x4_sds_common_txvco0_thres1(cs_uint16 module_id,
                                                        cs_uint16 freq_thres_sign1,
                                                        cs_uint16 freq_thres1);

cs_status ten_hsif_slc2_mr10x4_sds_common_txvco0_thres0(cs_uint16 module_id,
                                                        cs_uint16 freq_thres_sign0,
                                                        cs_uint16 freq_thres0);

cs_status ten_hsif_slc2_mr10x4_sds_common_txvco0_thres1(cs_uint16 module_id,
                                                        cs_uint16 freq_thres_sign1,
                                                        cs_uint16 freq_thres1);

cs_boolean ten_hsif_slc0_mr10x4_get_sds_tx_lock_status(cs_uint16 module_id);

cs_boolean ten_hsif_slc2_mr10x4_get_sds_tx_lock_status(cs_uint16 module_id);

cs_boolean ten_hsif_slc0_mr10x4_get_sds_tx_filt_lock_status(cs_uint16 module_id);

cs_boolean ten_hsif_slc2_mr10x4_get_sds_tx_filt_lock_status(cs_uint16 module_id);

cs_status ten_hsif_slc0_mr10x4_sds_common_tx_config(cs_uint16 module_id,
                                                    cs_uint8 instance,
                                                    cs_uint16 data_source);

cs_status ten_hsif_slc0_mr10x4_sds_common_rx_config(cs_uint16 module_id,
                                                    cs_uint8 instance,
                                                    cs_uint16 data_source);

cs_status ten_hsif_slc2_mr10x4_sds_common_tx_config(cs_uint16 module_id,
                                                    cs_uint8 instance,
                                                    cs_uint16 data_source);

cs_status ten_hsif_slc2_mr10x4_sds_common_rx_config(cs_uint16 module_id,
                                                    cs_uint8 instance,
                                                    cs_uint16 data_source);

cs_boolean ten_hsif_get_vco_tune_intstatus(cs_uint16 module_id, cs_uint8 slice,
                                           cs_dir_t dir, cs_uint8 instance);

cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_rx_config(cs_uint16 module_id,
                                                         cs_uint8 instance,
                                                         cs_uint16 srx_buswidth);

cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_rx_config(cs_uint16 module_id,
                                                         cs_uint8 instance,
                                                         cs_uint16 srx_buswidth);

cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 srx_ddiv_sel,
                                                              cs_uint16 srx_rdiv_sel);

cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 srx_ddiv_sel,
                                                              cs_uint16 srx_rdiv_sel);

cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_rx_loop_filter(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 srx_filtr);

cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_rx_loop_filter(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 srx_filtr);

cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_rx_cpa(cs_uint16 module_id,
                                                      cs_uint8 instance,
                                                      cs_uint16 srx_cpcur1,
                                                      cs_uint16 srx_cpcur0);

cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_rx_cpa(cs_uint16 module_id,
                                                      cs_uint8 instance,
                                                      cs_uint16 srx_cpcur1,
                                                      cs_uint16 srx_cpcur0);

cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_rx_cpb(cs_uint16 module_id,
                                                      cs_uint8 instance,
                                                      cs_uint16 srx_phsel);

cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_rx_cpb(cs_uint16 module_id,
                                                      cs_uint8 instance,
                                                      cs_uint16 srx_phsel);

cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_rx_misc(cs_uint16 module_id,
                                                       cs_uint8 instance,
                                                       cs_uint16 srx_eqadj);

cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_rx_misc(cs_uint16 module_id,
                                                       cs_uint8 instance,
                                                       cs_uint16 srx_eqadj);

cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_rx_spare(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 srx_spare);

cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_rx_spare(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 srx_spare);

cs_status ten_hsif_slc1_mr10x5_sds_common_rxvco0_thres0(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 freq_thres_sign0,
                                                        cs_uint16 freq_thres0);

cs_status ten_hsif_slc1_mr10x5_sds_common_rxvco0_thres1(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 freq_thres_sign1,
                                                        cs_uint16 freq_thres1);

cs_status ten_hsif_slc3_mr10x5_sds_common_rxvco0_thres0(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 freq_thres_sign0,
                                                        cs_uint16 freq_thres0);

cs_status ten_hsif_slc3_mr10x5_sds_common_rxvco0_thres1(cs_uint16 module_id,
                                                        cs_uint8 instance,
                                                        cs_uint16 freq_thres_sign1,
                                                        cs_uint16 freq_thres1);

cs_status ten_hsif_slc1_mr10x5_sds_common_rxvco0_control(cs_uint16 module_id,
                                                         cs_uint8 instance,
                                                         cs_uint16 val);

cs_status ten_hsif_slc3_mr10x5_sds_common_rxvco0_control(cs_uint16 module_id,
                                                         cs_uint8 instance,
                                                         cs_uint16 val);

cs_status ten_hsif_slc1_mr10x5_sds_common_rxlockd0_resolution(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 lock_res);

cs_status ten_hsif_slc3_mr10x5_sds_common_rxlockd0_resolution(cs_uint16 module_id,
                                                              cs_uint8 instance,
                                                              cs_uint16 lock_res);
                                                              
cs_status ten_hsif_slc1_mr10x5_sds_common_rxlockd0_filter(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 stable_period);

cs_status ten_hsif_slc3_mr10x5_sds_common_rxlockd0_filter(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 stable_period);

cs_boolean ten_hsif_slc1_mr10x5_get_sds_rx_lock_status(cs_uint16 module_id,
                                                       cs_uint8 instance);

cs_boolean ten_hsif_slc3_mr10x5_get_sds_rx_lock_status(cs_uint16 module_id,
                                                       cs_uint8 instance);
  
cs_boolean ten_hsif_slc1_mr10x5_get_sds_rx_filt_lock_status(cs_uint16 module_id,
                                                       cs_uint8 instance);

cs_boolean ten_hsif_slc3_mr10x5_get_sds_rx_filt_lock_status(cs_uint16 module_id,
                                                       cs_uint8 instance);
                                                       
cs_status ten_hsif_slc1_mr10x5_sds_common_stx0_tx_output_ctrla(cs_uint16 module_id,
                                                               cs_uint8 instance,
                                                               cs_uint16 stx_level);

cs_status ten_hsif_slc3_mr10x5_sds_common_stx0_tx_output_ctrla(cs_uint16 module_id,
                                                               cs_uint8 instance,
                                                               cs_uint16 stx_level);

cs_status ten_hsif_slc1_mr10x5_sds_common_stx0_tx_output_ctrlb(cs_uint16 module_id, cs_uint8 instance, 
                                                               cs_uint16 stx_pre_peak, 
                                                               cs_uint16 stx_post_peak);
                                                           
cs_status ten_hsif_slc3_mr10x5_sds_common_stx0_tx_output_ctrlb(cs_uint16 module_id, cs_uint8 instance, 
                                                               cs_uint16 stx_pre_peak, 
                                                               cs_uint16 stx_post_peak);
                                                               
cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config(cs_uint16 module_id,
                                                          cs_uint16 stxp_lptime_sel,
                                                          cs_uint16 stxp_pilot_sel,
                                                          cs_uint16 stxp_buswidth);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config(cs_uint16 module_id,
                                                          cs_uint16 stxp_lptime_sel,
                                                          cs_uint16 stxp_pilot_sel,
                                                          cs_uint16 stxp_buswidth);

cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(cs_uint16 module_id,
                                                               cs_uint16 stxp_ddiv_sel,
                                                               cs_uint16 stxp_rdiv_sel);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(cs_uint16 module_id,
                                                               cs_uint16 stxp_ddiv_sel,
                                                               cs_uint16 stxp_rdiv_sel);

cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl(cs_uint16 module_id,
                                                               cs_uint16 stxp_tclkien);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl(cs_uint16 module_id,
                                                               cs_uint16 stxp_tclkien);
                                                               
cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl_clkouten(cs_uint16 module_id, 
                                                           cs_uint16 stxp_clkouten);
                                                           
cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl_clkouten(cs_uint16 module_id, 
                                                           cs_uint16 stxp_clkouten);
                                                           
cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_loop_filter(cs_uint16 module_id,
                                                               cs_uint16 stxp_filtr);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_loop_filter(cs_uint16 module_id,
                                                               cs_uint16 stxp_filtr);

cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_cp(cs_uint16 module_id,
                                                      cs_uint16 stxp_cpcur1,
                                                      cs_uint16 stxp_cpcur0);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_cp(cs_uint16 module_id,
                                                      cs_uint16 stxp_cpcur1,
                                                      cs_uint16 stxp_cpcur0);

cs_status ten_hsif_slc1_mr10x5_sds_common_txvco0_thres0(cs_uint16 module_id,
                                                        cs_uint16 freq_thres_sign0,
                                                        cs_uint16 freq_thres0);

cs_status ten_hsif_slc1_mr10x5_sds_common_txvco0_thres1(cs_uint16 module_id,
                                                        cs_uint16 freq_thres_sign1,
                                                        cs_uint16 freq_thres1);

cs_status ten_hsif_slc3_mr10x5_sds_common_txvco0_thres0(cs_uint16 module_id,
                                                        cs_uint16 freq_thres_sign0,
                                                        cs_uint16 freq_thres0);

cs_status ten_hsif_slc3_mr10x5_sds_common_txvco0_thres1(cs_uint16 module_id,
                                                        cs_uint16 freq_thres_sign1,
                                                        cs_uint16 freq_thres1);

cs_boolean ten_hsif_slc1_mr10x5_get_sds_tx_lock_status(cs_uint16 module_id);

cs_boolean ten_hsif_slc3_mr10x5_get_sds_tx_lock_status(cs_uint16 module_id);

cs_boolean ten_hsif_slc1_mr10x5_get_sds_tx_filt_lock_status(cs_uint16 module_id);

cs_boolean ten_hsif_slc3_mr10x5_get_sds_tx_filt_lock_status(cs_uint16 module_id);

cs_status ten_hsif_slc1_mr10x5_sds_common_tx_config(cs_uint16 module_id,
                                                    cs_uint8 instance,
                                                    cs_uint16 data_source);

cs_status ten_hsif_slc1_mr10x5_sds_common_rx_config(cs_uint16 module_id,
                                                    cs_uint8 instance,
                                                    cs_uint16 data_source);

cs_status ten_hsif_slc3_mr10x5_sds_common_tx_config(cs_uint16 module_id,
                                                    cs_uint8 instance,
                                                    cs_uint16 data_source);

cs_status ten_hsif_slc3_mr10x5_sds_common_rx_config(cs_uint16 module_id,
                                                    cs_uint8 instance,
                                                    cs_uint16 data_source);

cs_status ten_hsif_sfi42_global_config(cs_uint16 module_id, cs_uint16 tx40g_en,
                                       cs_uint16 rx40g_en);

cs_status ten_hsif_sfi42_slice_control(cs_uint16 module_id, cs_uint8 instance,
                                       cs_uint16 rxeds_en, cs_uint16 txeds_en,
                                       cs_uint16 rxdscr_en, cs_uint16 txscr_en);
                                       
cs_status ten_hsif_sfi42_oos_threshold(cs_uint16 module_id, cs_uint8 instance, 
                                       cs_uint16 value);

cs_status ten_xfi32x1_prbsgen_config(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 prbs_mode, cs_uint16 invertprbs,
                                     cs_uint16 fixed_pattern, cs_uint16 prbs_enable);

cs_status ten_xfi32x1_prbsgen_enable(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 prbs_enable);

cs_status ten_xfi32x1_prbsgen_control(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint16 inserterror, cs_uint16 insertonebiterror,
                                      cs_uint16 inserterroronce,
                                      cs_uint16 insertonebiterroronce);

cs_status ten_xfi32x1_prbsgen_set_fixed0_pattern(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint16 value1, cs_uint16 value0);

/* Bugzilla #36328:  Fix header/API consistency */
cs_status ten_xfi32x1_prbsgen_fixed1_pattern1(cs_uint16 module_id, cs_uint8 slice,
                                             cs_uint16 value1, cs_uint16 value0);

cs_status ten_xfi32x1_prbsgen_set_repeat_pattern(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint16 repeat1, cs_uint16 repeat0);

cs_status ten_xfi32x1_prbschk_config(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 prbs_mode, cs_uint16 invertprbs);

cs_status ten_xfi32x1_prbschk_enable(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 enable);

cs_status ten_xfi32x1_prbschk_control_hunt(cs_uint16 module_id, cs_uint8 slice,
                                           cs_uint16 loadprbsstate);

cs_boolean ten_xfi32x1_prbschk_get_status(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_xfi32x1_tx0_config(cs_uint16 module_id, cs_uint8 slice,
                                 cs_uint16 data_source);

cs_status ten_xfi32x1_rx0_config(cs_uint16 module_id, cs_uint8 slice,
                                 cs_uint16 data_source);

cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl(cs_uint16 module_id, cs_uint8 slice,
                                           cs_uint16 stxp_fastdiv_sel,
                                           cs_uint16 stxp_ctrdiv_sel,
                                           cs_uint16 stxp_ctvdiv_sel,
                                           cs_uint16 stxp_ddiv_sel,
                                           cs_uint16 stxp_rdiv_sel);

cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctv_div(cs_uint16 module_id, cs_uint8 slice,
                                                   cs_uint16 stxp_ctvdiv_sel);

cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ddiv_sel(cs_uint16 module_id, cs_uint8 slice,
                                                    cs_uint16 stxp_ddiv_sel);

cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl_rdiv_sel(cs_uint16 module_id, cs_uint8 slice,
                                                    cs_uint16 stxp_rdiv_sel);

cs_status ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(cs_uint16 module_id, cs_uint8 slice,
                                                     cs_uint16 srx_ctvdiv_sel);

cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 stxp_ctrdiv_sel) ;

cs_status ten_xfi32x1_stxp0_tx_clkdiv_ctrl_fastdiv_sel(cs_uint16 module_id,
                                                       cs_uint8  slice, 
                                                       cs_uint16 stxp_fastdiv_sel);

cs_status ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(cs_uint16 module_id, cs_uint8 slice,
                                                   cs_uint16 srx_rdiv_sel);

cs_status ten_xfi32x1_srx0_rx_clkdiv_ctrl_ddiv_sel(cs_uint16 module_id, cs_uint8 slice,
                                                   cs_uint16 srx_ddiv_sel);

cs_status ten_xfi32x1_enable1_lsb_srx_filtr(cs_uint16 module_id, cs_uint8 slice,
                                            cs_uint16 srx_filtr);

cs_status ten_xfi32x1_stxp0_tx_spare(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 stxp_spare);

cs_status ten_xfi32x1_stxp0_gro_spare_refclk_div_sel_t41(cs_uint16 module_id,
                                                         cs_uint8  slice, 
                                                         cs_uint16 spare);

cs_status ten_xfi32x1_stxp0_tx_cp_t41(cs_uint16 module_id,
                                      cs_uint8  slice, 
                                      cs_uint16 stxp_cptstdn,
                                      cs_uint16 stxp_cpcur1,
                                      cs_uint16 stxp_cpcur0);

cs_status ten_xfi32x1_rxlockd0_resolution(cs_uint16 module_id, cs_uint8 slice,
                                          cs_uint16 lock_res);

cs_status ten_xfi32x1_txlockd0_resolution(cs_uint16 module_id, cs_uint8 slice,
                                          cs_uint16 lock_res);

cs_status ten_xfi32x1_stxp0_tx_lptime_sel(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 stxp_lptime_sel);

cs_status ten_xfi32x1_stxp0_tx_config(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint16 stxp_lptime_sel, cs_uint16 stxp_pilot_sel,
                                      cs_uint16 stxp_fcen, cs_uint16 stxp_buswidth,
                                      cs_uint16 stxp_lpbken);

cs_status ten_xfi32x1_stxp0_tx_config_lpbken(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 stxp_lpbken);
                                  
cs_status ten_xfi32x1_stxp0_tx_config_pilot_sel(cs_uint16 module_id, cs_uint8 slice,
                                                cs_uint16 stxp_pilot_sel);

cs_status ten_xfi32x1_stxp0_tx_config_fcen(cs_uint16 module_id, cs_uint8 slice,
                                           cs_uint16 stxp_fcen);

cs_status ten_xfi32x1_srx0_rx_config(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 srx_fcen, cs_uint16 srx_amp_pd,
                                     cs_uint16 srx_pd, cs_uint16 srx_buswidth,
                                     cs_uint16 srx_lpbken);

cs_status ten_xfi32x1_srx0_rx_config_lpbken(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 srx_lpbken);
                                 
cs_status ten_xfi32x1_srx0_rx_srx_pd(cs_uint16 module_id,
                                     cs_uint8 slice, 
                                     cs_uint16 srx_pd);

cs_status ten_xfi32x1_srx0_rx_config_fcen(cs_uint16 module_id, cs_uint8 slice,
                                          cs_uint16 srx_fcen);
                                          
cs_status ten_xfi32x1_cal_rx_eqadj(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 srx_eqadj);

cs_status ten_xfi32x1_cal_rx_phsel(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 srx_phsel);
                                          
cs_status ten_xfi32x1_stx0_tx_output_ctrl(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 stx_drv_lower_cm, 
                                          cs_uint16 stx_level,
                                          cs_uint16 stx_pre_peak, 
                                          cs_uint16 stx_post_peak);

cs_boolean ten_xfi32x1_txlockd0_lock(cs_uint16 module_id, cs_uint8 slice);

cs_boolean ten_xfi32x1_rxlockd0_lock(cs_uint16 module_id, cs_uint8 slice);

cs_boolean ten_xfi32x1_txlockd0_filt_lock(cs_uint16 module_id, cs_uint8 slice);

/* Bugzilla 26403 Start */
cs_boolean ten_xfi32x1_txlockd0_data_dets(cs_uint16 module_id, cs_uint8 slice);
/* Bugzilla 26403 End */

cs_boolean ten_xfi32x1_rxlockd0_filt_lock(cs_uint16 module_id, cs_uint8 slice);

cs_boolean ten_xfi32x1_get_vco_tune_intstatus(cs_uint16 module_id, cs_uint8 slice,
                                              cs_dir_t dir);
                                              


cs_status ten_xfi32x1_rxlockd0_set_stable_period(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint16 stable_period);

cs_status ten_xfi32x1_txlockd0_set_stable_period(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint16 stable_period);
                                                 
cs_status ten_xfi32x1_set_gram_cr(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 value);

cs_int16 ten_xfi32x1_get_gram_cr(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_xfi32x1_set_gram_d1(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 gram_d1);

cs_int16 ten_xfi32x1_get_gram_d1(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_xfi32x1_set_gram_d0(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 gram_d0);
                                               
cs_int16 ten_xfi32x1_get_gram_d0(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_xfi32x1_bit_invert(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint8 invert);
                                
cs_status ten_xfi32x1_invert(cs_uint16 module_id,
                            cs_uint8 slice, 
                            cs_dir_t dir, 
                            cs_uint8 invert);
                                
cs_status ten_xfi32x1_srx0_rx_clkout_ctrl_clkinven(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 srx_clkinven);  

cs_status ten_xfi32x1_set_rxlockd0_force_lock(cs_uint16 module_id,
                                              cs_uint8 slice, 
                                              cs_uint16 pd_mode, 
                                              cs_uint16 force_lock);   

cs_status ten_xfi32x1_stxp0_tx_pwrdn_all(cs_uint16 module_id,
                                         cs_uint8 slice, 
                                         cs_uint16 stxp_pd);    

cs_status ten_xfi32x1_txvco0_control_init(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_reset_action_t act);
                                          
cs_status ten_xfi32x1_rxvco0_control_init(cs_uint16 module_id, cs_uint8 slice,
                                          cs_reset_action_t act);
                                          
cs_uint16 ten_xfi32x1_txvco0_status(cs_uint16 module_id, cs_uint8 slice);
                                          
cs_uint16 ten_xfi32x1_rxvco0_status(cs_uint16 module_id, cs_uint8 slice);

cs_boolean ten_xfi32x1_rxlockd0_data_dets(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_hsif_clk_40g(cs_uint16 module_id, 
                       cs_uint16 tx_aggr_mode, 
                       cs_uint16 txsel, 
                       cs_uint16 rx_aggr_mode, 
                       cs_uint16 rxsel);

cs_status ten_hsif_set_clk_40g(cs_uint16 module_id, 
                               cs_uint16 select, 
                               cs_uint16 value);

cs_status ten_hsif_set_ok_ctrl(cs_uint16 module_id, 
                               cs_uint8 slice, 
                               cs_uint16 select, 
                               cs_uint16 value);

cs_status ten_hsif_set_refclk_cfg(cs_uint16 module_id, 
                                  cs_uint16 select, 
                                  cs_uint16 value);

cs_status ten_hsif_set_slc0_mr10x4_rxlockd0_force_lock(cs_uint16 module_id,
                                                       cs_uint8  instance, 
                                                       cs_uint16 pd_mode, 
                                                       cs_uint16 force_lock);

cs_status ten_hsif_set_slc2_mr10x4_rxlockd0_force_lock(cs_uint16 module_id,
                                                       cs_uint8  instance, 
                                                       cs_uint16 pd_mode, 
                                                       cs_uint16 force_lock);

cs_status ten_hsif_set_slc1_mr10x5_rxlockd0_force_lock(cs_uint16 module_id,
                                                       cs_uint8  instance, 
                                                       cs_uint16 pd_mode, 
                                                       cs_uint16 force_lock);

cs_status ten_hsif_set_slc3_mr10x5_rxlockd0_force_lock(cs_uint16 module_id,
                                                       cs_uint8  instance, 
                                                       cs_uint16 pd_mode, 
                                                       cs_uint16 force_lock);

cs_status ten_hsif_set_slc0_mr10x4_rxlockd0_data_lock(cs_uint16 module_id,
                                                      cs_uint8  instance, 
                                                      cs_uint16 data_lock);

cs_status ten_hsif_set_slc2_mr10x4_rxlockd0_data_lock(cs_uint16 module_id,
                                                      cs_uint8  instance, 
                                                      cs_uint16 data_lock);

cs_status ten_hsif_set_slc1_mr10x5_rxlockd0_data_lock(cs_uint16 module_id,
                                                      cs_uint8  instance, 
                                                      cs_uint16 data_lock);

cs_status ten_hsif_set_slc3_mr10x5_rxlockd0_data_lock(cs_uint16 module_id,
                                                      cs_uint8  instance, 
                                                      cs_uint16 data_lock);

cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_lpbken(cs_uint16 module_id, 
                                                       cs_uint16 stxp_lpbken);

cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_lpbken(cs_uint16 module_id, 
                                                       cs_uint16 stxp_lpbken);

cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_lpbken(cs_uint16 module_id, 
                                                       cs_uint16 stxp_lpbken);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_lpbken(cs_uint16 module_id, 
                                                       cs_uint16 stxp_lpbken);
 
cs_status ten_hsif_slc1_mr10x5_sds_common_txlockd0_filter(cs_uint16 module_id, 
                                                      cs_uint16 stable_period);
 
cs_status ten_hsif_slc3_mr10x5_sds_common_txlockd0_filter(cs_uint16 module_id, 
                                                      cs_uint16 stable_period);

cs_status ten_hsif_slc1_mr10x5_sds_common_txvco0_set_short_ovride(cs_uint16 module_id, 
                                                     cs_uint16 short_ovride);

cs_status ten_hsif_slc3_mr10x5_sds_common_txvco0_set_short_ovride(cs_uint16 module_id, 
                                                     cs_uint16 short_ovride);

cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_pilot_sel(cs_uint16 module_id, 
                                                             cs_uint16 stxp_pilot_sel);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_pilot_sel(cs_uint16 module_id, 
                                                             cs_uint16 stxp_pilot_sel);

cs_status ten_hsif_set_slc0_mr10x4_sds_common_rxvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint8  instance, 
                                                            cs_uint16 vcomax);

cs_status ten_hsif_set_slc2_mr10x4_sds_common_rxvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint8  instance, 
                                                            cs_uint16 vcomax);

cs_status ten_hsif_set_slc1_mr10x5_sds_common_rxvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint8  instance, 
                                                            cs_uint16 vcomax);

cs_status ten_hsif_set_slc3_mr10x5_sds_common_rxvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint8  instance, 
                                                            cs_uint16 vcomax);

cs_status ten_hsif_set_slc0_mr10x4_sds_common_txvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint16 vcomax);

cs_status ten_hsif_set_slc2_mr10x4_sds_common_txvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint16 vcomax);

cs_status ten_hsif_set_slc1_mr10x5_sds_common_txvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint16 vcomax);

cs_status ten_hsif_set_slc3_mr10x5_sds_common_txvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint16 vcomax);

cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_all(cs_uint16 module_id, 
                                                             cs_uint16 stxp_pd);

cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_all(cs_uint16 module_id, 
                                                             cs_uint16 stxp_pd);

cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_pwrdn_all(cs_uint16 module_id, 
                                                             cs_uint16 stxp_pd);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_pwrdn_all(cs_uint16 module_id, 
                                                             cs_uint16 stxp_pd);

cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(cs_uint16 module_id, 
                                                                 cs_uint16 stxp_pd_lane);
                                                             
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(cs_uint16 module_id, 
                                                                 cs_uint16 stxp_pd_lane);

cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_pwrdn_pd_lane(cs_uint16 module_id, 
                                                                 cs_uint16 stxp_pd_lane);
                                                                 
cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_pwrdn_pd_lane(cs_uint16 module_id, 
                                                                 cs_uint16 stxp_pd_lane);
                                                           
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_srx_pd(cs_uint16 module_id, 
                                                      cs_uint8 instance, 
                                                      cs_uint16 srx_pd);

cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_srx_pd(cs_uint16 module_id, 
                                                      cs_uint8 instance, 
                                                      cs_uint16 srx_pd);

cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_srx_pd(cs_uint16 module_id, 
                                                      cs_uint8 instance, 
                                                      cs_uint16 srx_pd);

cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_srx_pd(cs_uint16 module_id, 
                                                      cs_uint8 instance, 
                                                      cs_uint16 srx_pd);

cs_status ten_hsif_slc0_mr10x4_sds_common_rxelst0_resync(cs_uint16 module_id,
                                                         cs_uint8 instance, 
                                                         cs_uint16 resync);

cs_status ten_hsif_slc2_mr10x4_sds_common_rxelst0_resync(cs_uint16 module_id,
                                                         cs_uint8 instance, 
                                                         cs_uint16 resync);

cs_status ten_hsif_slc1_mr10x5_sds_common_rxelst0_resync(cs_uint16 module_id,
                                                         cs_uint8 instance, 
                                                         cs_uint16 resync);

cs_status ten_hsif_slc3_mr10x5_sds_common_rxelst0_resync(cs_uint16 module_id,
                                                         cs_uint8 instance, 
                                                         cs_uint16 resync);

cs_status ten_hsif_slc0_mr10x4_sds_common_txelst0_resync(cs_uint16 module_id,
                                                         cs_uint16 resync);

cs_status ten_hsif_slc2_mr10x4_sds_common_txelst0_resync(cs_uint16 module_id,
                                                         cs_uint16 resync);

cs_status ten_hsif_slc1_mr10x5_sds_common_txelst0_resync(cs_uint16 module_id,
                                                         cs_uint16 resync);

cs_status ten_hsif_slc3_mr10x5_sds_common_txelst0_resync(cs_uint16 module_id,
                                                         cs_uint16 resync);

cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_srx_lpbken(cs_uint16 module_id, 
                                                          cs_uint8 instance, 
                                                          cs_uint16 srx_lpbken);

cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_srx_lpbken(cs_uint16 module_id, 
                                                          cs_uint8 instance, 
                                                          cs_uint16 srx_lpbken);

cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_srx_lpbken(cs_uint16 module_id, 
                                                          cs_uint8 instance, 
                                                          cs_uint16 srx_lpbken);

cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_srx_lpbken(cs_uint16 module_id, 
                                                          cs_uint8 instance, 
                                                          cs_uint16 srx_lpbken);

cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_spare(cs_uint16 module_id, 
                                                     cs_uint16 stxp_spare);

cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_spare(cs_uint16 module_id, 
                                                     cs_uint16 stxp_spare);

cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_spare(cs_uint16 module_id, 
                                                     cs_uint16 stxp_spare);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_spare(cs_uint16 module_id, 
                                                     cs_uint16 stxp_spare);

cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_srx_ctvdiv_sel(cs_uint16 module_id, 
                                                              cs_uint8 instance, 
                                                              cs_uint16 srx_ctvdiv_sel);

cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_srx_ctvdiv_sel(cs_uint16 module_id, 
                                                              cs_uint8 instance, 
                                                              cs_uint16 srx_ctvdiv_sel);

cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_srx_ctvdiv_sel(cs_uint16 module_id, 
                                                              cs_uint8 instance, 
                                                              cs_uint16 srx_ctvdiv_sel);

cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_srx_ctvdiv_sel(cs_uint16 module_id, 
                                                              cs_uint8 instance, 
                                                              cs_uint16 srx_ctvdiv_sel);

cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_stxp_ctrdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctrdiv_sel);

cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_stxp_ctrdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctrdiv_sel);

cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_stxp_ctrdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctrdiv_sel);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_stxp_ctrdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctrdiv_sel);

cs_status ten_hsif_provision_rx_xfiselect(cs_uint16 module_id,
                                          cs_uint8 instance, 
                                          cs_uint16 rx_xfiselect);

cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_stxp_ctvdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctvdiv_sel);

cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_stxp_ctvdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctvdiv_sel);

cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_stxp_ctvdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctvdiv_sel);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_stxp_ctvdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctvdiv_sel);

cs_status ten_hsif_sfi42_busreorder(cs_uint16 module_id, 
                                    cs_dir_t dir, 
                                    cs_uint16 busreorder);

cs_status ten_hsif_slc0_mr10x4_sds_common_prbschk0_enable(cs_uint16 module_id,
                                                          cs_uint8  instance, 
                                                          cs_uint16 enable);

cs_status ten_hsif_slc2_mr10x4_sds_common_prbschk0_enable(cs_uint16 module_id,
                                                          cs_uint8  instance, 
                                                          cs_uint16 enable);

cs_status ten_hsif_slc1_mr10x5_sds_common_prbschk0_enable(cs_uint16 module_id,
                                                          cs_uint8  instance, 
                                                          cs_uint16 enable);

cs_status ten_hsif_slc3_mr10x5_sds_common_prbschk0_enable(cs_uint16 module_id,
                                                          cs_uint8  instance, 
                                                          cs_uint16 enable);

/* Bugzilla 23772 Start */
cs_status ten_hsif_mr10_sds_common_prbschk0_cfg (cs_uint16 module_id,
                                                 cs_uint8  slice, 
                                                 cs_uint8  instance, 
                                                 cs_uint16 hsif,
                                                 cs_uint16 enable,
                                                 cs_uint16 invertPrbs,
                                                 cs_uint16 pattern);
                                                      
cs_status ten_hsif_mr10_sds_common_prbsgen0_prbs_cfg (cs_uint16 module_id,
                                                      cs_uint8  slice, 
                                                      cs_uint8  instance, 
                                                      cs_uint16 hsif,
                                                      cs_uint16 enable,
                                                      cs_uint16 invertPrbs,
                                                      cs_uint16 pattern);

cs_status ten_hsif_mr10_sds_common_tx_config (cs_uint16 module_id, 
                                              cs_uint8  slice, 
                                              cs_uint8 instance, 
                                              cs_uint16 data_source);

cs_status ten_hsif_mr10_sds_common_prbchk0_intstatus (cs_uint16 module_id,
                                                      cs_uint8  slice, 
                                                      cs_uint8  instance);
/* Bugzilla 23772 End */

cs_status ten_hsif_slc0_mr10x4_sds_common_prbsgen0_prbs_enable(cs_uint16 module_id,
                                                               cs_uint8  instance, 
                                                               cs_uint16 prbs_enable);

cs_status ten_hsif_slc2_mr10x4_sds_common_prbsgen0_prbs_enable(cs_uint16 module_id,
                                                               cs_uint8  instance, 
                                                               cs_uint16 prbs_enable);

cs_status ten_hsif_slc1_mr10x5_sds_common_prbsgen0_prbs_enable(cs_uint16 module_id,
                                                               cs_uint8  instance, 
                                                               cs_uint16 prbs_enable);

cs_status ten_hsif_slc3_mr10x5_sds_common_prbsgen0_prbs_enable(cs_uint16 module_id,
                                                               cs_uint8  instance, 
                                                               cs_uint16 prbs_enable);
                                                               
cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_pilot_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_pilot_sel);

cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_pilot_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_pilot_sel);
                                                      
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(cs_uint16 module_id, cs_uint8 instance, 
                                                          cs_uint16 srx_tclko_sel);
                                                          
cs_status ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(cs_uint16 module_id, cs_uint8 instance, 
                                                          cs_uint16 srx_tclko_sel);
                                                          
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(cs_uint16 module_id, cs_uint8 instance, 
                                                          cs_uint16 srx_tclko_sel);                                                   
                                                          
cs_status ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(cs_uint16 module_id, cs_uint8 instance, 
                                                          cs_uint16 srx_tclko_sel);                                                   
  
cs_status ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_lptime_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lptime_sel);
                                                      
cs_status ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_lptime_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lptime_sel);
  
cs_status ten_hsif_slc0_mr10x4_rxlockd0_data_filtlock(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 data_filtlock);
                                                      
cs_status ten_hsif_slc2_mr10x4_rxlockd0_data_filtlock(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 data_filtlock);
                                                      
cs_status ten_hsif_slc1_mr10x5_rxlockd0_data_filtlock(cs_uint16 module_id, cs_uint8 instance, 
                                                       cs_uint16 data_filtlock);
                                                       
cs_status ten_hsif_slc3_mr10x5_rxlockd0_data_filtlock(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 data_filtlock);
  
cs_status ten_xfi32x1_rxvco0_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 thres0, cs_uint16 thres1);

cs_status ten_xfi32x1_txvco0_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_uint16 thres0, cs_uint16 thres1);
                                    
cs_status ten_xfi32x1_rxvco0_control(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 control);

cs_status ten_xfi32x1_txvco0_control(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 control);
                                 
cs_status ten_xfi32x1_stxp0_tx_config_lptime_sel_msb_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                         cs_uint16 stxp_lptime_sel_msb);                                
 
cs_status ten_xfi32x1_stxp0_tx_spare_refclk_div_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                        cs_uint16 stxp_refclk_div_sel);
                                                        
cs_status ten_xfi32x1_stxp0_tx_sfi52_clkrefouten_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                     cs_uint16 stxp_sfi5p2_clkrefouten);

cs_status ten_xfi32x1_stxp0_tx_sfi52_pilotouten_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_sfi5p2_pilotouten);
                                                    
cs_status ten_xfi32x1_stxp0_tx_sfi52_clkrefout_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                       cs_uint16 stxp_sfi5p2_clkrefout_sel);
                                                       
cs_status ten_xfi32x1_stxp0_tx_sfi52_clkrefout_div_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                           cs_uint16 stxp_sfi5p2_clkrefout_div_sel);

cs_status ten_xfi32x1_stxp0_tx_sfi52_pilotout_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                      cs_uint16 stxp_sfi5p2_pilotout_sel);
                                                      
cs_status ten_xfi32x1_stxp0_tx_sfi52_pilotout_div_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                          cs_uint16 stxp_sfi5p2_pilotout_div_sel);
                                                          
cs_status ten_xfi32x1_stxp0_gro_ctrl_refclk_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_gro_refclk_sel);
                                                    
cs_status ten_xfi32x1_stxp0_gro_ctrl_clkinven_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                  cs_uint16 stxp_gro_clkinven);

cs_status ten_xfi32x1_stxp0_gro_ctrl_mode_t41(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 stxp_gro_mode);
                                              
cs_status ten_xfi32x1_stxp0_gro_ctrl_pd_t41(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 stxp_gro_pd);
                                            
cs_status ten_xfi32x1_stxp0_gro_div_ctrl_refclk_div_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                            cs_uint16 stxp_gro_refclk_div_sel);
                                                            
cs_status ten_xfi32x1_stxp0_gro_div_ctrl_clk_div_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                         cs_uint16 stxp_gro_clk_div_sel);

cs_status ten_xfi32x1_stxp0_frac_ctrl_filt_tune_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_frac_filttune2, 
                                                    cs_uint16 stxp_frac_filttune1);
                                                    
cs_status ten_xfi32x1_stxp0_frac_ctrl_frac_filten_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                      cs_uint16 stxp_frac_filten);
                                                      
cs_status ten_xfi32x1_stxp0_frac_ctrl_mmd_clkinven_t41(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 stxp_mmd_clkinven);
                                  
cs_status ten_xfi32x1_stxp0_frac_ctrl_mmd_inv_en_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                     cs_uint16 stxp_mmd_inven);
                                                     
cs_status ten_xfi32x1_stxp0_frac_ctrl_frac_en_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                  cs_uint16 stxp_frac_en);

/* Bugzilla 26403 Start */
cs_status ten_xfi32x1_stxp0_tx_clkout_ctrl_clkouten(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_clkouten);

cs_status ten_xfi32x1_stxp0_tx_clkout_ctrl_tclko_sel(cs_uint16 module_id, cs_uint8 slice, 
                                                     cs_uint16 stxp_tclko_sel);
                                                     
cs_uint32 ten_xfi32x1_rx0_get_prbsck0_count (cs_uint16 module_id, cs_uint8 slice);
                                                    
/* Bugzilla 26403 End */
cs_status ten_hsif_xfi_check_lockd0 (cs_uint16 module_id, cs_uint8 slice);
 
cs_status ten_xfi32x1_txelst0_control_resync(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 resync);

cs_status ten_xfi32x1_rxelst0_control_resync(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 resync);
                                             
cs_uint16 ten_xfi32x1_get_stxp0_frac_ctrl_frac_en(cs_uint16 module_id, cs_uint8 slice);
 
cs_status ten_xfi32x1_mseqclkctrl_entiremspowerup(cs_uint16 module_id, cs_uint8 slice, 
                                                  cs_uint16 entiremspowerup);
                                                  
cs_status ten_xfi32x1_stxp0_tx_pwrdn_pd_lane(cs_uint16 module_id, 
                                             cs_uint8 slice, 
                                             cs_uint16 stxp_pd_lane);
                                             
cs_status ten_cfp32x1_srx0_rx_config_amp_pd_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_amp_pd);

cs_status ten_cfp32x1_srx0_rx_srx_pd_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_pd);

cs_status ten_cfp32x1_srx0_rx_config_buswidth_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_buswidth);

cs_status ten_cfp32x1_srx0_rx_config_xfi_en_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_xfi_en);

cs_status ten_cfp32x1_srx0_rx_config_lpbken_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_lpbken);

cs_status ten_cfp32x1_srx0_rx_clkdiv_ctrl_fastdiv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_fastdiv_sel);

cs_status ten_cfp32x1_srx0_rx_clkdiv_ctrl_ctvdiv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_ctvdiv_sel);

cs_status ten_cfp32x1_srx0_rx_clkdiv_ctrl_ddiv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_ddiv_sel);

cs_status ten_cfp32x1_srx0_rx_clkdiv_ctrl_rdiv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_rdiv_sel);

cs_status ten_cfp32x1_srx0_rx_clkout_ctrl_clkinven_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_clkinven);

cs_status ten_cfp32x1_srx0_rx_clkout_ctrl_tclkien_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_tclkien);

cs_status ten_cfp32x1_srx0_rx_clkout_ctrl_tclko_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_tclko_sel);

cs_status ten_cfp32x1_srx0_rx_cpa_cpcur_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_cpcur1, cs_uint16 srx_cpcur0);

cs_status ten_cfp32x1_srx0_rx_misc_hi_gain_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 srx_hi_gain);

cs_status ten_cfp32x1_srx0_rx_misc_srx_eqadj_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 srx_eqadj);
                                                 
cs_status ten_cfp32x1_rxvco0_thres0_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 freq_thres_sign0, cs_uint16 freq_thres0);

cs_status ten_cfp32x1_rxvco0_thres1_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 freq_thres_sign1, cs_uint16 freq_thres1);

cs_status ten_cfp32x1_rxvco0_vcomax_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 vcomax);

cs_status ten_cfp32x1_rxvco0_control_init_t41(cs_uint16 module_id, cs_uint8 slice, cs_reset_action_t act);

cs_status ten_cfp32x1_rxvco0_set_short_ovride_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 short_ovride);

cs_uint16 ten_cfp32x1_rxvco0_status_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_rxvco0_intstatus_t41(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_cfp32x1_rxlockd0_set_stable_period_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stable_period);

cs_status ten_cfp32x1_set_rxlockd0_data_lock_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 data_lock);

cs_status ten_cfp32x1_set_rxlockd0_pd_mode_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 pd_mode);

cs_status ten_cfp32x1_set_rxlockd0_force_lock_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 force_lock);

cs_uint16 ten_cfp32x1_rxlockd0_lock_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_rxlockd0_filt_lock_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_rxlockd0_data_dets_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_rxlockd0_short_filt_pns_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_rxlockd0_bad_vco_clks_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_rxvcolevel0_ostatus_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_rxvcolevel0_cstatus_t41(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_cfp32x1_stx0_tx_output_ctrl_drv_lower_cm_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stx_drv_lower_cm);

cs_status ten_cfp32x1_stx0_tx_output_ctrl_level_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stx_level);

cs_status ten_cfp32x1_stx0_tx_output_ctrl_pre_peak_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stx_pre_peak);

cs_status ten_cfp32x1_stx0_tx_output_ctrl_post_peak_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stx_post_peak);

cs_status ten_cfp32x1_stxp0_tx_lptime_sel_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_lptime_sel);

cs_status ten_cfp32x1_stxp0_tx_lptime_sel_msb_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_lptime_sel_msb);

cs_status ten_cfp32x1_stxp0_tx_config_pilot_sel_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_pilot_sel);

cs_status ten_cfp32x1_stxp0_tx_config_buswidth_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_buswidth);

cs_status ten_cfp32x1_stxp0_tx_config_xfi_en_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_xfi_en);

cs_status ten_cfp32x1_stxp0_tx_config_lpbken_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_lpbken);

cs_status ten_cfp32x1_stxp0_tx_pd_41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_pd);

cs_status ten_cfp32x1_stxp0_tx_pd_lane_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_pd_lane);

cs_status ten_cfp32x1_stxp0_tx_clkdiv_ctrl_fastdiv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_fastdiv_sel);

cs_status ten_cfp32x1_stxp0_tx_clkdiv_ctrl_ctrdiv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_ctrdiv_sel);

cs_status ten_cfp32x1_stxp0_tx_clkdiv_ctrl_ctvdiv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_ctvdiv_sel);

cs_status ten_cfp32x1_stxp0_tx_clkdiv_ctrl_ddiv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_ddiv_sel);

cs_status ten_cfp32x1_stxp0_tx_clkdiv_ctrl_rdiv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_rdiv_sel);

cs_status ten_cfp32x1_stxp0_tx_clkout_ctrl_tclkien_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_tclkien);

cs_status ten_cfp32x1_stxp0_tx_clkout_ctrl_clkouten_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_clkouten);

cs_status ten_cfp32x1_stxp0_tx_clkout_ctrl_tclko_sel_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_tclko_sel);

cs_status ten_cfp32x1_stxp0_tx_loop_filter_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_filtr);

cs_status ten_cfp32x1_stxp0_tx_cpcur_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_cpcur1, cs_uint16 stxp_cpcur0);

cs_status ten_cfp32x1_stxp0_tx_spare_ref_sel_mode_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stxp_ref_sel_mode);

cs_status ten_cfp32x1_txvco0_thres0_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 freq_thres_sign0, cs_uint16 freq_thres0);

cs_status ten_cfp32x1_txvco0_thres1_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 freq_thres_sign1, cs_uint16 freq_thres1);

cs_status ten_cfp32x1_txvco0_vcomax_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 vcomax);

cs_status ten_cfp32x1_txvco0_control_init_t41(cs_uint16 module_id, cs_uint8 slice, cs_reset_action_t act);

cs_status ten_cfp32x1_txvco0_set_short_ovride_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 short_ovride);

cs_uint16 ten_cfp32x1_txvco0_status_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_txvco0_intstatus_t41(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_cfp32x1_txlockd0_set_stable_period_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 stable_period);

cs_uint16 ten_cfp32x1_txlockd0_lock_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_txlockd0_filt_lock_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_txlockd0_data_dets_t41(cs_uint16 module_id, cs_uint8 slice);

cs_uint16 ten_cfp32x1_txlockd0_bad_vco_clks_t41(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_cfp32x1_txvcolevel0_ostatus_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 vco_level_status);

cs_uint16 ten_cfp32x1_txvcolevel0_cstatus_t41(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_cfp32x1_rxelst0_control_use_lockdet_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 use_lockdet);

cs_status ten_cfp32x1_rxelst0_control_resync_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 resync);

cs_status ten_cfp32x1_txelst0_control_use_lockdet_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 use_lockdet);

cs_status ten_cfp32x1_txelst0_control_resync_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 resync);

cs_status ten_cfp32x1_prbsgen_config_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 prbs_mode, cs_uint16 invertprbs, cs_uint16 fixed_pattern, cs_uint16 prbs_enable);

cs_status ten_cfp32x1_prbsgen_enable_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 prbs_enable);

cs_status ten_cfp32x1_prbsgen_control_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 inserterror, cs_uint16 insertonebiterror, cs_uint16 inserterroronce, cs_uint16 insertonebiterroronce);

cs_status ten_cfp32x1_prbsgen_set_fixed0_pattern_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 value1, cs_uint16 value0);

/* Bugzilla #36328:  Fix header/API consistency */
cs_status ten_cfp32x1_prbsgen_fixed1_pattern_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 value1,
                                                 cs_uint16 value0);

cs_status ten_cfp32x1_prbsgen_set_repeat_pattern_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 repeat1, cs_uint16 repeat0);

cs_status ten_cfp32x1_prbschk_config_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 prbs_mode, cs_uint16 invertprbs);

cs_status ten_cfp32x1_prbschk_enable_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 enable);

cs_status ten_cfp32x1_prbschk_control_hunt_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 loadprbsstate);

cs_uint16 ten_cfp32x1_prbschk_get_status_t41(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_cfp32x1_tx0_config_bitinv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 invert);

cs_status ten_cfp32x1_tx0_config_data_source_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 data_source);

cs_status ten_cfp32x1_rx0_config_bitinv_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 bitinv);

cs_status ten_cfp32x1_rx0_config_data_source_t41(cs_uint16 module_id, cs_uint8 slice, cs_uint16 data_source);

cs_uint32 ten_cfp32x1_rx0_get_prbsck0_count_t41 (cs_uint16 module_id, cs_uint8 slice); /* Bugzilla 26403 Start */

cs_uint16 ten_hsif_sfi5_get_rx_deskew_offset0(cs_uint16 module_id, cs_uint8 instance);

cs_status ten_hsif_slc0_mr10x4_sds_common_tx_config_bitinv(cs_uint16 module_id, 
                                                           cs_uint8 instance, 
                                                           cs_uint16 bitinv);
                                                           
cs_status ten_hsif_slc0_mr10x4_sds_common_rx_config_bitinv(cs_uint16 module_id, cs_uint8 instance, 
                                                           cs_uint16 bitinv);
                                                           
cs_status ten_hsif_slc2_mr10x4_sds_common_tx_config_bitinv(cs_uint16 module_id, 
                                                           cs_uint8 instance, 
                                                           cs_uint16 bitinv);
                                                           
cs_status ten_hsif_slc2_mr10x4_sds_common_rx_config_bitinv(cs_uint16 module_id, cs_uint8 instance, 
                                                           cs_uint16 bitinv);

cs_status ten_hsif_slc1_mr10x5_sds_common_tx_config_bitinv(cs_uint16 module_id, 
                                                           cs_uint8 instance, 
                                                           cs_uint16 bitinv);
                                                           
cs_status ten_hsif_slc1_mr10x5_sds_common_rx_config_bitinv(cs_uint16 module_id, cs_uint8 instance, 
                                                           cs_uint16 bitinv);
                                                           
cs_status ten_hsif_slc3_mr10x5_sds_common_tx_config_bitinv(cs_uint16 module_id, 
                                                           cs_uint8 instance, 
                                                           cs_uint16 bitinv);
                                                           
cs_status ten_hsif_slc3_mr10x5_sds_common_rx_config_bitinv(cs_uint16 module_id, cs_uint8 instance, 
                                                           cs_uint16 bitinv);
                                                           
#ifdef __cplusplus
}
#endif
#endif
