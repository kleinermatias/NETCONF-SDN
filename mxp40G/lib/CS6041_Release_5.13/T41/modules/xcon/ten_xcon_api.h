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
 * ten_xcon_api.h
 *
 * API Header file for XCON block.
 *
 * $Id: ten_xcon_api.h,v 1.19 2013/02/22 20:48:11 jccarlis Exp $
 *
 */

#ifndef __TEN_XCON_API_H__
#define __TEN_XCON_API_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Bugzilla 27270 Start */
cs_status ten_xcon_es_setup_amplitude_recenter_t41(cs_uint16 dev_id,
                                                   ten_xcon_es_num_t es_num,
                                                   cs_uint16 margin_lower,
                                                   cs_uint16 margin_upper,
                                                   cs_uint16 correct_lower,
                                                   cs_uint16 correct_upper,
                                                   cs_uint8  duration,
                                                   cs_uint32 sysclk_freq);

cs_status ten_xcon_es_setup_amplitude_recenter_40g_t41(cs_uint16 dev_id,
                                                   cs_uint8  module_num,
                                                   cs_uint16 margin_lower,
                                                   cs_uint16 margin_upper,
                                                   cs_uint16 correct_lower,
                                                   cs_uint16 correct_upper,
                                                   cs_uint8  duration,
                                                   cs_uint32 sysclk_freq);

cs_status ten_xcon_es_setup_amplitude_recenter_with_fpa_t41(
                                                   cs_uint16 dev_id,
                                                   ten_xcon_es_num_t es_num,
                                                   cs_uint16 static_depth,
                                                   cs_uint16 circuit_th_lower,
                                                   cs_uint16 circuit_th_upper);

cs_status ten_xcon_es_setup_amplitude_recenter_with_fpa_40g_t41(
                                                   cs_uint16 dev_id,
                                                   cs_uint8  module_num,
                                                   cs_uint16 static_depth,
                                                   cs_uint16 circuit_th_lower,
                                                   cs_uint16 circuit_th_upper);

cs_status ten_xcon_es_check_amplitude_recenter_40g_t41(cs_uint16 dev_id,
                                                   cs_uint8  module_num);

cs_status ten_xcon_es_check_amplitude_recenter_t41(cs_uint16 dev_id,
                                                   ten_xcon_es_num_t es_num);

cs_status ten_dev_init_xcon_es_cb (cs_uint16 dev_id);                         /* Release 5.4 */

cs_status ten_xcon_es_handle_traffic_stable_event_10g_t41(                    /* Release 5.4 */
                                                   cs_uint16 dev_id,
                                                   cs_uint16 source_stream);

cs_status ten_xcon_es_handle_traffic_stable_event_40g_t41(                    /* Release 5.4 */
                                                   cs_uint16 dev_id,
                                                   cs_uint16 source_module);

cs_status ten_xcon_es_handle_recenter_complete_event_t41(cs_uint16 dev_id,    /* Release 5.4 */
            	                                     ten_xcon_es_num_t es_num);

void      ten_xcon_es_dump_cb                     (ten_xcon_es_cb_t *aESCB);  /* Release 5.4 */

cs_status ten_xcon_es_amp_recntr_intr_handler     (cs_uint16 dev_id,          /* Release 5.4 */
                                                   ten_xcon_es_num_t es_num);
cs_status ten_xcon_es_intr_enable                 (cs_uint16 dev_id,          /* Release 5.4 */
                                                   cs_uint16 bitfield);
cs_status ten_xcon_es_intr_handler_enable         (cs_uint16 dev_id,          /* Release 5.4 */
                                                   cs_uint16 bitfield);

cs_status ten_xcon_es_dump_level_min_max          (cs_uint16 dev_id);          /* Release 5.4 */
cs_status ten_xcon_es_reset_level_min_max         (cs_uint16 dev_id,           /* Release 5.4 */
                                                   cs_uint16 module_num,
                                                   ten_xcon_es_num_t es_num);
/* Bugzilla 27270 End */

cs_status ten_n10g_sdfr_sdfist_handler_enable (cs_uint16 module_id,
                                               cs_uint16 slice,
                                               cs_uint16 bitfield);

cs_status ten_xcon_datapath_reset(cs_uint16 dev_id, 
                                  cs_reset_action_t act);

cs_status ten_xcon_es_select_source(cs_uint16 dev_id,
                                    ten_xcon_es_num_t es_num,
                                    ten_xcon_channel_num_t chnl_num,
                                    ten_xcon_interface_t chnl_if);
                                    
cs_status ten_xcon_es_select_source_no_rx_thresh(cs_uint16 dev_id,
                                    ten_xcon_es_num_t es_num,
                                    ten_xcon_channel_num_t chnl_num,
                                    ten_xcon_interface_t chnl_if);
                                    
cs_status ten_xcon_es_rx_threshold_select(cs_uint16 dev_id, 
                                          cs_uint16 input,
                                          cs_uint16 source);
                                
cs_status ten_xcon_es_select_read_source(cs_uint16 dev_id,
                                    ten_xcon_channel_num_t chnl_num,
                                    ten_xcon_source_t source);


cs_status ten_xcon_select_es_pause_quanta_source(cs_uint16 dev_id,
                                                 ten_xcon_tx_channel_t chnl_num,
                                                 ten_xcon_channel_num_t pause_quanta_chnl);

cs_status ten_xcon_set_es_pause_frame_watermark_level(cs_uint16 dev_id,
                                                      ten_xcon_es_num_t es_num,
                                                      ten_xcon_pause_wmark_level_t level,
                                                      cs_uint16 value);

cs_status ten_xcon_set_es_pause_threshold_select(cs_uint16 dev_id,
                                                 ten_xcon_es_num_t es_num,
                                                 ten_xcon_channel_num_t chnl_num);

cs_status ten_xcon_set_es_watermark_level(cs_uint16 dev_id,
                                          ten_xcon_es_num_t es_num,
                                          ten_xcon_threshold_level_t level,
                                          cs_uint16 value);
                                          
cs_status ten_xcon_select_bert(cs_uint16 dev_id,
                                ten_xcon_channel_num_t chnl_num,
                                ten_xcon_source_t source);
                                

cs_status ten_xcon_es_reset(cs_uint16 dev_id, 
                            ten_xcon_es_num_t es_num,
                            cs_reset_action_t act);

cs_status ten_xcon_config_es_mode(cs_uint16 dev_id, 
                                  ten_xcon_es_num_t es_num,
                                  ten_xcon_mfp_mode_t mfp_mode,
                                  ten_xcon_gfp_mode_t gfp_mode,
                                  ten_xcon_sf_mode_t sf_mode,
                                  ten_xcon_pkt_mode_t pkt_mode);

cs_status ten_xcon_select_es_packet_centering(cs_uint16 dev_id, 
                                              ten_xcon_es_num_t es_num,
                                              ten_xcon_center_type_t type,
                                              cs_ctl_t ctl);

cs_status ten_xcon_set_circuit_thresholds(cs_uint16 dev_id, 
                                          ten_xcon_es_num_t es_num,
                                          ten_xcon_circuit_threshold_t type, 
                                          cs_uint16 value);

cs_status ten_xcon_set_pbert_mode(cs_uint16 dev_id,
                                  ten_xcon_es_num_t es_num,
                                  ten_xcon_traffic_type_t traffic,
                                  ten_xcon_pbert_profile_t profile);

cs_status ten_xcon_set_pbert_protocol(cs_uint16 dev_id,
                                      ten_xcon_es_num_t es_num,
                                      ten_xcon_fc_sof_t sof_delimiter,
                                      ten_xcon_fc_eof_t eof_delimiter, 
                                      ten_xcon_da_type_t da_type);

cs_status ten_xcon_pbert_prbs_reset(cs_uint16 dev_id,
                                    ten_xcon_es_num_t es_num,
                                    cs_dir_t dir,
                                    cs_reset_action_t act);

cs_status ten_xcon_control_pbert_frame_payload(cs_uint16 dev_id,
                                               ten_xcon_es_num_t es_num,
                                               ten_xcon_payload_type_t payload,
                                               cs_ctl_t seqnum_enbl);

cs_status ten_xcon_pbert_select_fixed_pattern(cs_uint16 dev_id,
                                              ten_xcon_es_num_t es_num,
                                              ten_xcon_fixed_pattern_t type,
                                              cs_uint8 value_n,
                                              cs_uint8 value_n_plus_1);

cs_status ten_xcon_control_pbert_unit_len(cs_uint16 dev_id, 
                                          ten_xcon_es_num_t es_num,
                                          ten_xcon_len_mode_t mode, 
                                          cs_uint16 rndmask,
                                          cs_uint16 min_len,
                                          cs_uint16 max_len);

cs_status ten_xcon_pbert_control_ifg(cs_uint16 dev_id, 
                                     ten_xcon_es_num_t es_num,
                                     ten_xcon_ifg_symbol_t symbol,
                                     cs_uint16 ifg);

cs_status ten_xcon_pbert_control_traffic(cs_uint16 dev_id, 
                                         ten_xcon_es_num_t es_num,
                                         cs_uint16 units);

cs_status ten_xcon_pbert_inject_err(cs_uint16 dev_id, 
                                    ten_xcon_es_num_t es_num,
                                    ten_xcon_error_type_t err_type,
                                    cs_uint16 duration);

cs_status ten_xcon_pbert_control_generator(cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num,
                                           cs_ctl_t ctl);
                                           
cs_status ten_xcon_pbert_control_seq_num(cs_uint16 dev_id,
                                         ten_xcon_es_num_t es_num,
                                         ten_xcon_seqnum_ctrl_t type);

cs_status  ten_xcon_sadeco_config(cs_uint16 dev_id, 
                                  cs_uint8 block_id,
                                  cs_uint16 es_depth,
                                  cs_uint16 es_skew_length,
                                  ten_xcon_sadeco_fp_type_t fp_type);

cs_status ten_xcon_sadeco_control(cs_uint16 dev_id, 
                                  cs_uint8 block_id,
                                  cs_ctl_t ctl);

cs_status ten_xcon_sadeco_enable_fp(cs_uint16 dev_id, 
                                    cs_uint8 block_id,
                                    cs_ctl_t enable);

cs_status ten_xcon_sadeco_reset(cs_uint16 dev_id, 
                                cs_uint8 block_id,
                                ten_xcon_sadeco_blk_reset_t rst_block,
                                cs_reset_action_t act);

cs_status ten_xcon_sadeco_sel_data_stream(cs_uint16 dev_id, 
                                          cs_uint8 block_id,
                                          cs_uint8 ref_stream,
                                          cs_uint8 trib_stream);
                                          
cs_status ten_xcon_sadeco_sadcfg3_rsymsk(cs_uint16 dev_id, 
                                         cs_uint8 instance, 
                                         cs_uint16 rsymsk);

cs_status ten_xcon_sadeco_skew_delay_comp_len(cs_uint16 dev_id, 
                                              cs_uint8 block_id,
                                              cs_uint16 length);

cs_status ten_xcon_sadeco_resync(cs_uint16 dev_id, 
                                 cs_uint8 block_id);

cs_status ten_xcon_cbert_control_generator(cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num,
                                           cs_ctl_t ctl);

cs_status ten_xcon_cbert_control_checker(cs_uint16 dev_id, 
                                         ten_xcon_es_num_t es_num, 
                                         cs_ctl_t ctl);

cs_status ten_xcon_cbert_inject_err(cs_uint16 dev_id, 
                                    ten_xcon_es_num_t es_num,
                                    ten_xcon_error_type_t err_type,
                                    cs_uint8 num_err_bits,
                                    cs_uint16 duration);

cs_status ten_xcon_cbert_resync(cs_uint16 dev_id, 
                                ten_xcon_es_num_t es_num);

cs_status ten_xcon_cbert_config(cs_uint16 dev_id,
                                ten_xcon_es_num_t es_num,
                                ten_xcon_prbs_poly_t poly);

cs_status ten_xcon_cbert_config_err_threshold(cs_uint16 dev_id,
                                ten_xcon_es_num_t es_num,
                                cs_uint8 err_thresh);
                            
cs_boolean ten_xcon_cbert_get_sync_status(cs_uint16 dev_id, 
                                          ten_xcon_es_num_t es_num);
                                          
cs_status ten_xcon_pbert_rx_reset(cs_uint16 dev_id, cs_uint8 instance,
                                  cs_reset_action_t act);
                                  
cs_status ten_xcon_pbert_tx_reset(cs_uint16 dev_id, cs_uint8 instance, 
                                  cs_reset_action_t act);

cs_status ten_xcon_config(cs_uint16 dev_id,
                                ten_xcon_es_num_t es_num,
                                ten_xcon_gfp_mode_t gfp_mode,
                                ten_xcon_sf_mode_t sf_mode,
                                ten_xcon_pkt_mode_t pkt_mode);

cs_status ten_xcon_sadeco_sdclen(cs_uint16 dev_id,
                                 cs_uint8  block_id, 
                                 cs_uint16 sdclen);
                                 
cs_int16 ten_xcon_sadeco_sadstat(cs_uint16 dev_id, cs_uint8 block_id);

cs_status ten_xcon_set_circuit_threshold_level_t41(cs_uint16 dev_id,
                                                   cs_uint8 es_index,
                                                   ten_xcon_es_recenter_circuit_types_t threshold_type,
                                                   ten_xcon_circuit_threshold_t         threshold_select,
                                                   cs_uint8                             threshold_index,
                                                   cs_uint16                            threshold_lvalue);

cs_status ten_xcon_set_packet_threshold_level_t41(cs_uint16 dev_id,
                                                  cs_uint8  es_index,
                                                  ten_xcon_es_recenter_packet_types_t threshold_type,
                                                  ten_xcon_circuit_threshold_t        threshold_select,
                                                  cs_uint8                            threshold_index,
                                                  cs_uint16                           threshold_lvalue);

cs_status ten_xcon_threshold_select(cs_uint16 dev_id,
                                    cs_uint8  es_index,
                                    cs_uint8  threshold_source,
                                    cs_uint8  threshold_type);

cs_status ten_xcon_es_recenter_t41(cs_uint16 dev_id,
                                   cs_uint8  es_index);

cs_status ten_xcon_40g_recenter_t41(cs_uint16 dev_id,
                                    cs_uint8  module_num);

cs_status ten_xcon_pp40g_recenter_t41(cs_uint16 dev_id,
                                      cs_uint8  es_index);

cs_status ten_xcon_config_es_recenter_trigger_t41(cs_uint16 dev_id,
                                                  cs_uint8  es_index,
                                                  cs_uint8  type);

cs_status ten_xcon_config_es_delayed_recenter_period(cs_uint16 dev_id,
                                                     cs_uint8  es_index,
                                                     cs_uint8  delay);

cs_status ten_xcon_disable_es_clock_t41(cs_uint16         dev_id,
                                        ten_xcon_es_num_t es_num,
                                        cs_ctl_t          ctl);

cs_status ten_xcon_enable_tx_algn_t41(cs_uint16         dev_id,
                                      ten_xcon_es_num_t es_num,
                                      cs_ctl_t          ctl);

cs_status ten_xcon_es_recenter_enables_t41(cs_uint16         dev_id, 
                                           ten_xcon_es_num_t es_num,
                                           cs_uint8          enable_num,
                                           cs_ctl_t          ctl);

cs_status ten_xcon_es_config_t41(cs_uint16         dev_id, 
                                 ten_xcon_es_num_t es_num,
                                 cs_uint8          enable_num,
                                 cs_ctl_t          ctl);

cs_status ten_xcon_es_config_multi_t41(cs_uint16         dev_id, 
                                       ten_xcon_es_num_t es_num,
                                       cs_reg            mask,
                                       cs_reg            ctl);

cs_status ten_xcon_glb_pp40g_config_t41(cs_uint16 dev_id, 
                                        cs_uint8  module_num,
                                        cs_uint8  enable_num,
                                        cs_ctl_t  ctl);

cs_status ten_xcon_es_recenter_measure_period_t41(cs_uint16         dev_id, 
                                                  ten_xcon_es_num_t es_num,
                                                  cs_uint8          period,
                                                  cs_uint32         sysclk_freq);

cs_status ten_xcon_pp_es_pause_threshold_select(cs_uint16         dev_id,
                                                ten_xcon_es_num_t es_num,
                                                ten_xcon_es_num_t select);

cs_status ten_xcon_disable_pbert_clock_t41(cs_uint16         dev_id,
                                           ten_xcon_es_num_t es_num,
                                           cs_dir_t          dir, 
                                           cs_ctl_t          ctl);
                                           
cs_status ten_xcon_pp40g_reset_a_t41(cs_uint16         dev_id, 
                                     cs_reset_action_t act);
                                     
cs_status ten_xcon_pp40g_reset_b_t41(cs_uint16         dev_id, 
                                     cs_reset_action_t act);
                                     
cs_status ten_xcon_pp40g_reset_t41(cs_uint16         dev_id, 
                                   cs_reset_action_t act);
                                   
cs_status ten_xcon_es_correction_lower(cs_uint16 dev_id, cs_uint8 instance, 
                                       cs_uint16 level);
                                       
cs_status ten_xcon_es_correction_upper(cs_uint16 dev_id, cs_uint8 instance, 
                                       cs_uint16 level);
                                       
cs_status ten_xcon_es_static_depth(cs_uint16 dev_id, cs_uint8 instance, 
                                  cs_uint16 depth);

cs_status ten_xcon_es_pp40g_reset_t41(cs_uint16 module_id); /* Bugzilla 29751 */

cs_uint16 ten_get_xcon_es_source_t41(cs_uint16 dev_id, cs_uint16 es_num);

cs_status ten_xcon_sadeco_sadint(cs_uint16 dev_id, cs_uint8 instance, 
                                 cs_uint16 eserr, 
                                 cs_uint16 sdcerr, 
                                 cs_uint16 synci);
                                 
cs_uint16 ten_xcon_get_sadeco_sadint_synci(cs_uint16 dev_id, cs_uint8 instance);
                               
#ifdef __cplusplus
}
#endif
#endif  /* __TEN_XCON_API_H__ */


