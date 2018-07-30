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
 * ten_fec_api.h
 *
 * API Header file for FEC block.
 *
 * $Id: ten_fec_api.h,v 1.7 2013/02/22 20:48:57 jccarlis Exp $
 *
 */

#ifndef __TEN_FEC_API_H__
#define __TEN_FEC_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_gfec_10g_reset(cs_uint16 module_id, 
                             cs_uint8 slice,
                             cs_dir_t dir, 
                             cs_reset_action_t act);

cs_status ten_gfec_10g_ec_enable(cs_uint16 module_id, 
                                 cs_uint8 slice,
                                 cs_ctl_t enable);

cs_status ten_gfec_10g_set_excess_error_flag(cs_uint16 module_id, 
                                             cs_uint8 slice,
                                             cs_uint32 error_flag,
                                             ten_err_source_t error_src,
                                             ten_fec_time_unit_sel_t gi_sel);

cs_status ten_gfec_10g_stats_enable_scrambler(cs_uint16 module_id,
                                              cs_uint8 slice,
                                              cs_ctl_t scrmblr_enbl);

cs_status ten_gfec_10g_set_eed_threshold(cs_uint16 module_id, 
                                         cs_uint8 slice,
                                         cs_uint32 ceed_thres, 
                                         cs_uint32 seed_thres);

cs_status ten_gfec_10g_set_deg_threshold(cs_uint16 module_id, 
                                         cs_uint8 slice,
                                         cs_uint32 cdeg_thres, 
                                         cs_uint32 sdeg_thres);

cs_status ten_gfec_10g_select_err_type(cs_uint16 module_id, 
                                       cs_uint8 slice,
                                       ten_fec_err_sel_t err_sel, 
                                       ten_gfec_err_type_t err_type);

cs_status ten_gfec_10g_select_timer_unit(cs_uint16 module_id, 
                                         cs_uint8 slice,
                                         cs_boolean err_sel,
                                         ten_fec_time_unit_sel_t tu_sel);

cs_status ten_gfec_10g_set_timing_win_size(cs_uint16 module_id,
                                           cs_uint8 slice,
                                           ten_fec_err_sel_t err_sel,
                                           cs_uint8 window_size);

cs_status ten_gfec_10g_config_fec_eed_alarm_win(cs_uint16 module_id,
                                                cs_uint8 slice,
                                                cs_uint8 seed_div,
                                                cs_uint8 seed_dtv,
                                                cs_uint8 ceed_niv,
                                                cs_uint8 ceed_ntv);

cs_status ten_gfec_10g_config_fec_deg_alarm_win(cs_uint16 module_id,
                                                cs_uint8 slice,
                                                cs_uint8 sdeg_div,
                                                cs_uint8 sdeg_dtv,
                                                cs_uint8 cdeg_niv,
                                                cs_uint8 cdeg_ntv);

cs_status ten_gfec_10g_inject_err(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  ten_err_freq_t single_err,
                                  cs_uint16 duration,
                                  cs_uint8 err_value,
                                  cs_uint8 row_offset,
                                  cs_uint16 err_mask,
                                  cs_uint8 no_cycles_2_err,
                                  cs_uint8 start_position);
                                  
/* Bugzilla 24692 Start */
/* Bugzilla 24692 End */

cs_status ten_gfec_40g_reset(cs_uint16 module_id,  
                             cs_dir_t dir, 
                             cs_reset_action_t act);

cs_status ten_gfec_40g_ec_enable(cs_uint16 module_id,
                                 cs_ctl_t enable);

cs_status ten_gfec_40g_set_gi_sel(cs_uint16 module_id,
                                  ten_fec_time_unit_sel_t gi_sel);

cs_status ten_gfec_40g_set_excess_error_flag(cs_uint16 module_id, 
                                             cs_uint32 error_flag,
                                             ten_err_source_t error_src,
                                             ten_fec_time_unit_sel_t gi_sel);

cs_status ten_gfec_40g_stats_enable_scrambler(cs_uint16 module_id,
                                              cs_ctl_t scrmblr_enbl);

cs_status ten_gfec_40g_set_eed_threshold(cs_uint16 module_id, 
                                         cs_uint32 ceed_thres, 
                                         cs_uint32 seed_thres);

cs_status ten_gfec_40g_set_deg_threshold(cs_uint16 module_id, 
                                         cs_uint32 cdeg_thres, 
                                         cs_uint32 sdeg_thres);

cs_status ten_gfec_40g_select_err_type(cs_uint16 module_id, 
                                       ten_fec_err_sel_t err_sel, 
                                       ten_gfec_err_type_t err_type);

cs_status ten_gfec_40g_select_timer_unit(cs_uint16 module_id, 
                                         cs_boolean err_sel,
                                         ten_fec_time_unit_sel_t tu_sel);

cs_status ten_gfec_40g_set_timing_win_size(cs_uint16 module_id,
                                           ten_fec_err_sel_t err_sel,
                                           cs_uint8 window_size);

cs_status ten_gfec_40g_config_fec_eed_alarm_win(cs_uint16 module_id,
                                                cs_uint8 seed_div,
                                                cs_uint8 seed_dtv,
                                                cs_uint8 ceed_niv,
                                                cs_uint8 ceed_ntv);

cs_status ten_gfec_40g_config_fec_deg_alarm_win(cs_uint16 module_id,
                                                cs_uint8 sdeg_div,
                                                cs_uint8 sdeg_dtv,
                                                cs_uint8 cdeg_niv,
                                                cs_uint8 cdeg_ntv);

cs_status ten_gfec_40g_inject_err(cs_uint16 module_id,
                                  ten_err_freq_t single_err,
                                  cs_uint16 duration,
                                  cs_uint8 err_value,
                                  cs_uint8 row_offset,
                                  cs_uint16 err_mask,
                                  cs_uint8 no_cycles_2_err,
                                  cs_uint8 start_position);

cs_status ten_gfec_40g_inject_cont_err(cs_uint16 module_id,
                                       ten_err_freq_t insError,
                                       cs_uint8 err_value,
                                       cs_uint8 row_offset,
                                       cs_uint16 err_mask,
                                       cs_uint8 no_cycles_2_err,
                                       cs_uint8 start_position);
                                       
/* Bugzilla 24692 Start */
/* Bugzilla 24692 End */

#ifndef TEN_NO_UFEC
cs_status ten_ufec_coder_module_enable(cs_uint16 module_id, 
                                       cs_uint8 slice,
                                       cs_uint8 enc_rc_enbl,
                                       cs_uint8 dec_rc_enbl,
                                       cs_uint8 dec_corr_ctrl);

cs_status ten_ufec_set_error_threshold(cs_uint16 module_id, 
                                       cs_uint8 slice,
                                       cs_uint32 thres);

cs_status ten_ufec_set_eed_threshold(cs_uint16 module_id, 
                                     cs_uint8 slice,
                                     cs_uint32 ceed_thres, 
                                     cs_uint32 seed_thres);

cs_status ten_ufec_set_deg_threshold(cs_uint16 module_id, 
                                     cs_uint8 slice,
                                     cs_uint32 cdeg_thres, 
                                     cs_uint32 sdeg_thres);

cs_status ten_ufec_select_err_type(cs_uint16 module_id, 
                                   cs_uint8 slice,
                                   ten_fec_err_sel_t err_sel,
                                   ten_fec_err_src_t err_src,
                                   ten_ufec_err_type_t err_type);

cs_status ten_ufec_select_timer_unit(cs_uint16 module_id, 
                                     cs_uint8 slice,
                                     cs_boolean err_sel,
                                     ten_fec_time_unit_sel_t tu_sel);

cs_status ten_ufec_config_fec_eed_alarm_win(cs_uint16 module_id,
                                            cs_uint8 slice,
                                            cs_uint8 seed_div,
                                            cs_uint8 seed_dtv,
                                            cs_uint8 ceed_niv,
                                            cs_uint8 ceed_ntv);

cs_status ten_ufec_config_fec_deg_alarm_win(cs_uint16 module_id,
                                            cs_uint8 slice,
                                            cs_uint8 sdeg_div,
                                            cs_uint8 sdeg_dtv,
                                            cs_uint8 cdeg_niv,
                                            cs_uint8 cdeg_ntv);

cs_status ten_ufec_set_timing_win_size(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       ten_fec_err_sel_t err_sel,
                                       cs_uint8 window_size);

cs_status ten_ufec_inject_err(cs_uint16 module_id,
                              cs_uint8 slice,
                              ten_err_freq_t single_err,
                              cs_uint16 duration,
                              cs_uint16 err_value);

cs_status ten_ufec_ed_reset(cs_uint16 module_id, 
                            cs_uint8 slice,
                            cs_dir_t dir, 
                            cs_reset_action_t act);

cs_status ten_ufec_ed_burst_insertion(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      ten_err_freq_t single_err,
                                      cs_uint16 ed_burst_x,
                                      cs_uint16 ed_burst_y);

cs_status ten_ufec_reset(cs_uint16 module_id, 
                         cs_uint8 slice,
                         cs_dir_t dir, 
                         cs_reset_action_t act);

cs_status ten_ufec_ed_enable(cs_uint16 module_id,
                             cs_uint8 slice,
                             cs_dir_t dir, 
                             cs_ctl_t ctrl);

cs_status ten_ufec_ed_config_buffer_size(cs_uint16 module_id,
                                         cs_uint8 slice,
                                         cs_dir_t dir, 
                                         ten_ed_buffer_type_t type,
                                         cs_uint16 size);

cs_int16 ten_ufec_get_rx_sync_status(cs_uint16 module_id,
                                     cs_uint8 slice);

cs_status ten_ufec_config_decoder(cs_uint16 module_id, 
                                  cs_uint8 slice,
                                  ten_fec_ovhd_t fec_ovhd);

cs_status ten_ufec_config_encoder(cs_uint16 module_id, 
                                  cs_uint8 slice,
                                  ten_fec_ovhd_t fec_ovhd);
                                  
cs_status ten_ufec_select_global_timing_source(cs_uint16 module_id,
                                               cs_uint8 instance, 
                                               cs_uint16 select);
                                               
cs_status ten_ufec_debug(cs_uint16 module_id, cs_uint8 instance, 
                     cs_uint16 debug_value);
                                               
cs_status ten_ufec_ctrl1(cs_uint16 module_id, cs_uint8 instance, 
                     cs_uint16 ctrlword);
                     
/* Bugzilla 24692 Start */
/* Bugzilla 24692 End */

cs_status ten_ufec_custom_config(cs_uint16 module_id, cs_uint16 custom_ufec_mode);
                                 
#endif

#ifdef __cplusplus
}
#endif
#endif  /* __TEN_FEC10_API_H__ */
