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
 * ten_pp10g_api.h
 *
 * API Header file for PP10G block.
 *
 * $Id: ten_pp10g_api.h,v 1.21 2013/02/22 20:48:04 jccarlis Exp $
 *
 */

#ifndef __TEN_PP10G_API_H__
#define __TEN_PP10G_API_H__

#ifdef __cplusplus
extern "C" {
#endif

  /* @TODO: Move to pp40g api */
cs_status ten_pp40g_pm_read_counter(cs_uint16 module_id,
                                   cs_uint32 cntr_id, 
                                   cs_uint32 *counter_ms, cs_uint32 *counter_ls);
                                   
cs_uint16 ten_pp10g_get_clken_line_rx(cs_uint16 module_id,
                                      cs_uint8 slice);
                                      
cs_status ten_pp10g_clken_line_rx_t41(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 rx_en_ber10b, 
                                      cs_uint16 rx_en_mon10b);
                                   
cs_status ten_pp10g_clken_line_rx(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 rx_en_bypass, cs_uint16 rx_en_fc,
                                  cs_uint16 rx_en_xgpcs, cs_uint16 rx_en_xcode,
                                  cs_uint16 rx_en_mac, cs_uint16 rx_en_rs,
                                  cs_uint16 rx_en_gfp, cs_uint16 rx_en_egpcs,
                                  cs_uint16 rx_en_basex);

cs_status ten_pp10g_clken_line_tx(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 tx_en_xgpcs, cs_uint16 tx_en_xcode,
                                  cs_uint16 tx_en_mac, cs_uint16 tx_en_rs,
                                  cs_uint16 tx_en_gfp, cs_uint16 tx_en_egpcs,
                                  cs_uint16 tx_en_basex);

cs_status ten_pp10g_clken_sys_rx(cs_uint16 module_id, cs_uint8 slice,
                                 cs_uint16 sysrx_en_mac);

cs_status ten_pp10g_clken_sys_tx(cs_uint16 module_id, cs_uint8 slice,
                                 cs_uint16 systx_en_oam, cs_uint16 systx_en_mac);

cs_status ten_pp10g_funcen_rx(cs_uint16 module_id, cs_uint8 slice, cs_uint16 rx_fen_fc,
                              cs_uint16 rx_fen_bypass, cs_uint16 rx_fen_mac,
                              cs_uint16 rx_fen_xcode, cs_uint16 rx_fen_egpcs,
                              cs_uint16 rx_fen_basex, cs_uint16 rx_fen_gfp,
                              cs_uint16 rx_fen_xgpcs);

cs_status ten_pp10g_funcen_tx(cs_uint16 module_id, cs_uint8 slice,
                              cs_uint16 tx_fen_bypass, cs_uint16 tx_fen_mac,
                              cs_uint16 tx_fen_xcode, cs_uint16 tx_fen_egpcs,
                              cs_uint16 tx_fen_basex, cs_uint16 tx_fen_gfp,
                              cs_uint16 tx_fen_xgpcs);

cs_status ten_pp10g_rx_path_ctrl(cs_uint16 module_id, cs_uint8 slice,
                                 cs_uint16 rx_los_dis, cs_uint16 rx_data0_on_drop_en,
                                 cs_uint16 rx_byte_flip, cs_uint16 rx_bit_flip);

cs_status ten_pp10g_tx_path_ctrl(cs_uint16 module_id, cs_uint8 slice,
                                 cs_uint16 tx_sqwave_pat_en, cs_uint16 tx_sqwave_pat,
                                 cs_uint16 tx_byte_flip, cs_uint16 tx_bit_flip,
                                 cs_uint16 tx_output_en);

cs_status ten_pp10g_tx2rx_ctrl(cs_uint16 module_id, cs_uint8 slice, cs_uint16 tx2rx_bp,
                               cs_uint16 tx2rx_clken, cs_uint16 tx2rx_en);

cs_status ten_pp10g_spare(cs_uint16 module_id, cs_uint8 slice, cs_uint16 spare);

cs_status ten_pp10g_fmro(cs_uint16 module_id, cs_uint8 slice, 
                     cs_uint16 clksel, 
                     cs_uint16 modsel, 
                     cs_uint16 sel);

cs_status ten_pp10g_eccerrmask(cs_uint16 module_id, cs_uint8 slice,
                               cs_uint16 ecc_err_mask6, cs_uint16 ecc_err_mask5,
                               cs_uint16 ecc_err_mask4, cs_uint16 ecc_err_mask3,
                               cs_uint16 ecc_err_mask2, cs_uint16 ecc_err_mask1,
                               cs_uint16 ecc_err_mask0);

cs_status ten_pp10g_xcode_rx_reset(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act);

cs_status ten_pp10g_xcode_tx_reset(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act);

cs_status ten_pp10g_xcode_config(cs_uint16 module_id, 
                                 cs_uint8 slice,
                                 cs_dir_t dir,
                                 cs_uint16 sblock_size,
                                 cs_uint16 res_size,
                                 cs_uint16 frame_size);

cs_status ten_pp10g_misc_reset(cs_uint16 module_id, cs_uint8 slice,
                               cs_reset_action_t act);

cs_uint16 ten_pp10g_get_misc_reset(cs_uint16 module_id, cs_uint8 slice);
                               
cs_status ten_pp10g_egpcs_rx_reset(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act);

cs_status ten_pp10g_egpcs_rx_set_mode(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint16 align_char);
                                      
cs_status ten_pp10g_egpcs_rx_dscr_en(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 dscr_en);

/* Bugzilla #35713 Start */
cs_status ten_pp10g_egpcs_tx_scr_en(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 scr_en);
/* Bugzilla #35713 End */
                              
cs_boolean ten_pp10g_egpcs_rx_intstatus(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_pp10g_egpcs_tx_reset(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act);

cs_status ten_pp10g_egpcs_tx_set_mode(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint16 ins_mode);

cs_status ten_pp10g_egpcs_tx_inspattern0(cs_uint16 module_id, cs_uint8 slice,
                                         cs_uint16 pat0, cs_uint16 pat1, cs_uint16 pat2,
                                         cs_uint16 pat3);

cs_status ten_pp10g_fc_rx_reset(cs_uint16 module_id, cs_uint8 slice,
                                cs_reset_action_t act);

cs_status ten_pp10g_fc_rx_swap(cs_uint16 module_id, cs_uint8 slice, cs_uint16 bitswap,
                               cs_uint16 byteswap);

cs_status ten_pp10g_fc_rx_psq_control(cs_uint16 module_id, cs_uint8 slice, cs_uint16 en,
                                      cs_uint16 pseq_rsvd, cs_uint16 set_thr,
                                      cs_uint16 clr_thr);

cs_int16 ten_pp10g_fc_rx_get_psq_status(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 select);

cs_status ten_pp10g_fc_rx_mode_control(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 idle_req);

cs_status ten_pp10g_fc_rx_m_maxlen(cs_uint16 module_id, cs_uint8 slice, cs_uint16 max);

cs_status ten_pp10g_fc_rx_m_diag(cs_uint16 module_id, cs_uint8 slice, cs_uint16 primsig);

cs_status ten_pp10g_gfp_rx_control_sreset(cs_uint16 module_id, cs_uint8 slice,
                                          cs_reset_action_t act);

cs_status ten_pp10g_gfp_rx_set_mode(cs_uint16 module_id, cs_uint8 slice, cs_uint16 mode);

cs_status ten_pp10g_gfp_rx_set_core_header_controls(cs_uint16 module_id, cs_uint8 slice,
                                                    cs_uint16 chkpli, cs_uint16 delta);

cs_status ten_pp10g_gfp_rx_maxlen(cs_uint16 module_id, cs_uint8 slice, cs_uint16 max);

cs_status ten_pp10g_gfp_rx_configure_payload_header(cs_uint16 module_id, cs_uint8 slice,
                                                    cs_uint16 sberr_corr_ph,
                                                    cs_uint16 chkexi, cs_uint16 chkupi,
                                                    cs_uint16 chkpti);

cs_status ten_pp10g_gfp_rx_set_expected_upi(cs_uint16 module_id, cs_uint8 slice,
                                            cs_uint16 exupi_o, cs_uint16 exupi_d);

cs_int16 ten_pp10g_gfp_rx_get_status(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 select);

cs_status ten_pp10g_gfp_tx_control_sreset(cs_uint16 module_id, cs_uint8 slice,
                                          cs_reset_action_t act);

cs_status ten_pp10g_gfp_tx_set_mode(cs_uint16 module_id, cs_uint8 slice, cs_uint16 mode);
                                
cs_status ten_pp10g_gfp_tx_set_polynomial(cs_uint16 module_id, cs_uint8 slice,
                                cs_uint16 pscrambler_poly);

cs_status ten_pp10g_gfp_tx_set_schen1(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 schen);

cs_status ten_pp10g_gfp_tx_set_schpri1(cs_uint16 module_id,
                                       cs_uint8 slice, 
                                       cs_uint16 schpri1);
                                
cs_status ten_pp10g_gfp_tx_set_payload_header(cs_uint16 module_id, cs_uint8 slice,
                                              cs_uint16 pti, cs_uint16 pfi);

cs_status ten_pp10g_gfp_tx_upi(cs_uint16 module_id, cs_uint8 slice, cs_uint16 upi_o,
                               cs_uint16 upi_d);

cs_status ten_pp10g_gfp_set_tx_insert_access_0(cs_uint16 module_id,
                                               cs_uint8 slice, 
                                               cs_uint16 data_0);

cs_status ten_pp10g_gfp_set_tx_insert_access_1(cs_uint16 module_id,
                                               cs_uint8 slice, 
                                               cs_uint16 data_1);

cs_status ten_pp10g_gfp_set_tx_insert_access_n(cs_uint16 module_id,
                                               cs_uint8 slice, 
                                               cs_uint16 data_n);

cs_status ten_pp10g_gfp_set_tx_insert_cmf_auto(cs_uint16 module_id,
                                               cs_uint8 slice, 
                                               cs_uint16 num, 
                                               cs_uint16 ticks);

cs_status ten_pp10g_gfp_set_tx_insert_cmf_auto_bit(cs_uint16 module_id,
                                                   cs_uint8 slice, 
                                                   cs_uint16 cmf_auto);

cs_status ten_pp10g_set_gfp_rx_cmf_enables(cs_uint16 module_id,
                                           cs_uint8  slice, 
                                           cs_uint8  select, 
                                           cs_uint8  value);

cs_status ten_pp10g_gfp_set_rx_cmf_values(cs_uint16 module_id,
                                          cs_uint8  slice, 
                                          cs_uint8  select, 
                                          cs_uint8  value);
                                          
cs_status ten_pp10g_gfp_rx_mark_t41(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 m_pfcs_err);

cs_status ten_pp10g_mac_rx_control_sreset(cs_uint16 module_id, cs_uint8 slice,
                                          cs_reset_action_t act);

cs_status ten_pp10g_mac_tx_control_sreset(cs_uint16 module_id, cs_uint8 slice,
                                          cs_reset_action_t act);

cs_status ten_pp10g_mac_ctl_loopback(cs_uint16 module_id, cs_uint8 slice, cs_dir_t dir,
                                     cs_ctl_t enbl);

cs_status ten_pp10g_mac_rx_set_profile(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 profile);

cs_status ten_pp10g_mac_tx_set_profile(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 profile);

cs_status ten_pp10g_mac_rx_set_stats_err_order(cs_uint16 module_id, cs_uint8 slice,
                                               cs_uint16 stats_err_order);

cs_status ten_pp10g_mac_rx_ifg_mode(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 ifg_mode_rx);

cs_status ten_pp10g_mac_set_tx_ifg_mode(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 ifg_mode_tx);

cs_status ten_pp10g_mac_tx_cfg_programmable_ifg(cs_uint16 module_id, cs_uint8 slice,
                                                cs_uint16 ifg);

cs_status ten_pp10g_mac_rx_ctl_drop_short(cs_uint16 module_id, cs_uint8 slice,
                                          cs_ctl_t drop_short);

cs_status ten_pp10g_mac_rx_minlen(cs_uint16 module_id, cs_uint8 slice, cs_uint16 minlen);

cs_status ten_pp10g_mac_rx_maxlen(cs_uint16 module_id, cs_uint8 slice, cs_uint16 maxlen);

cs_status ten_pp10g_mac_rx_maxlen_and_xgadj_tx_maxframe(cs_uint16 module_id, 
                                                        cs_uint8 slice, 
                                                        cs_uint16 maxlen);
                                                        
cs_status ten_pp10g_mac_rx_set_maxlen_mode(cs_uint16 module_id, cs_uint8 slice,
                                           cs_uint16 maxlen_mode);

cs_status ten_pp10g_mac_rx_cfg_pause_frame(cs_uint16 module_id, cs_uint8 slice,
                                           cs_ctl_t len_chk_en_pause,
                                           cs_ctl_t pause_extract, cs_ctl_t pause_term);

cs_status ten_pp10g_mac_tx_cfg_pause_req(cs_uint16 module_id, cs_uint8 slice,
                                         cs_uint16 pause_preemptive_en,
                                         cs_uint16 pause_reactive_auto_xon,
                                         cs_uint16 pause_reactive_en,
                                         cs_uint16 lf_auto_flush_en, cs_uint16 inssa,
                                         cs_uint16 ifg_mode_tx);

cs_status ten_pp10g_mac_tx_ctl_auto_flush(cs_uint16 module_id, cs_uint8 slice,
                                          cs_ctl_t lf_auto_flush_en);

cs_status ten_pp10g_mac_rx_cfg_ethernet_mode(cs_uint16 module_id, cs_uint8 slice,
                                             cs_uint16 sfd_check, cs_uint16 crc_err_fatal,
                                             cs_uint16 fcs_chk_en,
                                             cs_uint16 len_chk_en_pad,
                                             cs_uint16 len_chk_en, cs_uint16 promis_mode);

cs_status ten_pp10g_mac_rx_cfg_ethernet_mode_promis(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 promis_mode);
                              
cs_boolean ten_pp10g_mac_rx_get_link_status(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_pp10g_mac_tx_pause_quanta(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 pq);

cs_status ten_pp10g_mac_tx_generate_pause_frame(cs_uint16 module_id, cs_uint8 slice,
                                                cs_uint16 xon_xoff);

cs_status ten_pp10g_mac_tx_mac_address(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 addr_a, cs_uint16 addr_b,
                                       cs_uint16 addr_c);

cs_status ten_pp10g_mac_tx_vlan_tag(cs_uint16 module_id, cs_uint8 slice, cs_uint16 tag1,
                                    cs_uint16 tag2, cs_uint16 tag3);

cs_status ten_pp10g_mac_rx_vlan_tag(cs_uint16 module_id, cs_uint8 slice, cs_uint16 tag1,
                                    cs_uint16 tag2, cs_uint16 tag3);

cs_status ten_pp10g_mac_tx_pause_address(cs_uint16 module_id, cs_uint8 slice,
                                         cs_uint16 addr_a, cs_uint16 addr_b,
                                         cs_uint16 addr_c);

cs_int16 ten_pp10g_mac_tx_mac_get_addr_rdonly2(cs_uint16 module_id, cs_uint8 slice);

cs_int16 ten_pp10g_mac_tx_mac_get_addr_rdonly1(cs_uint16 module_id, cs_uint8 slice);

cs_int16 ten_pp10g_mac_tx_mac_get_addr_rdonly0(cs_uint16 module_id, cs_uint8 slice);

cs_int16 ten_pp10g_mac_rx_mac_get_addr_rdonly2(cs_uint16 module_id, cs_uint8 slice);

cs_int16 ten_pp10g_mac_rx_mac_get_addr_rdonly1(cs_uint16 module_id, cs_uint8 slice);

cs_int16 ten_pp10g_mac_rx_mac_get_addr_rdonly0(cs_uint16 module_id, cs_uint8 slice);
                                       
cs_status ten_pp10g_mac_tx_pause_frame_monitor_control(cs_uint16 module_id,
                                                       cs_uint8 slice, cs_uint16 monitor,
                                                       cs_uint16 check_reserved_da,
                                                       cs_uint16 check_specified_da,
                                                       cs_uint16 check_length);

cs_int16 ten_pp10g_mac_tx_pfmscda1(cs_uint16 module_id, cs_uint8 slice);

cs_int16 ten_pp10g_mac_tx_pfmscda2(cs_uint16 module_id, cs_uint8 slice);

cs_int16 ten_pp10g_mac_tx_pfmscda3(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_pp10g_mac_tx_pause_frame_request_gen(cs_uint16 module_id, cs_uint8 slice,
                                                   cs_uint16 upper_threshold_zero,
                                                   cs_uint16 lower_threshold_one);

cs_status ten_pp10g_mac_tx_pause_request_gen_frame_ins_rate(cs_uint16 module_id,
                                                            cs_uint8 slice,
                                                            cs_uint16 rate);

cs_status ten_pp10g_mac_tx_pause_request_gen_critical_time_min(cs_uint16 module_id,
                                                               cs_uint8 slice,
                                                               cs_uint16 crit_time_min);

cs_status ten_pp10g_mac_tx_pause_request_gen_detected_quanta_limit(cs_uint16 module_id,
                                                                   cs_uint8 slice,
                                                                   cs_uint16
                                                                   quanta_limit);

cs_status ten_pp10g_mac_tx_pause_request_gen_quanta_increment(cs_uint16 module_id,
                                                              cs_uint8 slice,
                                                              cs_uint16 quantum_upper,
                                                              cs_uint16 quantum_lower);

cs_status ten_pp10g_mac_tx_cfg_pause_en(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 pause_preemptive_en,
                                        cs_uint16 pause_reactive_en);

cs_status ten_pp10g_mac_tx_pause_frame_monitor(cs_uint16 module_id, cs_uint8 slice,
                                               cs_uint16 monitor);

cs_status ten_pp10g_mac_tx_pause_frame_request_lt1(cs_uint16 module_id, cs_uint8 slice,
                                                   cs_uint16 lower_threshold_one);

cs_status ten_pp10g_mac_tx_pause_xoff_delay(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 inter_xoff_delay);
                                                   
cs_status ten_pp10g_pcs_tx_sreset(cs_uint16 module_id, cs_uint8 slice,
                                  cs_reset_action_t act);

cs_status ten_pp10g_pcs_rx_sreset(cs_uint16 module_id, cs_uint8 slice,
                                  cs_reset_action_t act);

cs_status ten_pp10g_pcs_tx_loopback(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 tx_estore_resync, cs_uint16 tx_loopback,
                                    cs_uint16 tx_loopback_data_en);

cs_status ten_pp10g_pcs_tx_control(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 square_tx_pat, cs_uint16 pseudo_tx_inv,
                                   cs_uint16 pcs6_tx_test, cs_uint16 test_tx_err,
                                   cs_uint16 scram_tx_dis, cs_uint16 txcode_control);

cs_status ten_pp10g_pcs_tx_profile(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 txprofile);

cs_status ten_pp10g_pcs_tx_seed_a(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 pseudo_tx_a3, cs_uint16 pseudo_tx_a2,
                                  cs_uint16 pseudo_tx_a1, cs_uint16 pseudo_tx_a0);

cs_status ten_pp10g_pcs_tx_seed_b(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 pseudo_tx_b3, cs_uint16 pseudo_tx_b2,
                                  cs_uint16 pseudo_tx_b1, cs_uint16 pseudo_tx_b0);

cs_status ten_pp10g_pcs_tx_seed_d(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 pseudo_tx_d3, cs_uint16 pseudo_tx_d2,
                                  cs_uint16 pseudo_tx_d1, cs_uint16 pseudo_tx_d0);

cs_status ten_pp10g_pcs_rx_loopback(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 rx_estore_resync, cs_uint16 rx_loopback);

cs_status ten_pp10g_pcs_rx_control(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 dontfilterfsig, cs_uint16 latcheach1e,
                                   cs_uint16 pseudo_rx_inv, cs_uint16 pcs6_rx_test,
                                   cs_uint16 pcs6_ddsa_enable, cs_uint16 rxprofile,
                                   cs_uint16 descram_rx_dis);

cs_status ten_pp10g_pcs_rx_control_transparency(cs_uint16 module_id, cs_uint8 slice,
                                                cs_uint16 pass_invalid_blocks,
                                                cs_uint16 pass_singles);

cs_int16 ten_pp10g_pcs_rx_status(cs_uint16 module_id, cs_uint8 slice, cs_uint16 select);

cs_status ten_pp10g_pcs_rx_seed_a(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 pseudo_rx_a3, cs_uint16 pseudo_rx_a2,
                                  cs_uint16 pseudo_rx_a1, cs_uint16 pseudo_rx_a0);

cs_status ten_pp10g_pcs_rx_seed_b(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 pseudo_rx_b3, cs_uint16 pseudo_rx_b2,
                                  cs_uint16 pseudo_rx_b1, cs_uint16 pseudo_rx_b0);

cs_status ten_pp10g_pcs_rx_seed_d(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 pseudo_rx_d3, cs_uint16 pseudo_rx_d2,
                                  cs_uint16 pseudo_rx_d1, cs_uint16 pseudo_rx_d0);

cs_status ten_pp10g_pcs_rx_control_rxprofile(cs_uint16 module_id, cs_uint8 slice,
                                             cs_uint16 rxprofile);

cs_status ten_pp10g_set_pcs_rx_ber_timer(cs_uint16 module_id,
                                         cs_uint8 slice, 
                                         cs_uint16 value);

cs_status ten_pp10g_set_pcs_rx_synoff(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 select, 
                                      cs_uint16 value);

cs_status ten_pp10g_pm_reset(cs_uint16 module_id, cs_uint8 slice, cs_reset_action_t act);

cs_status ten_pp10g_pm_control(cs_uint16 module_id, cs_uint8 slice,
                               cs_uint16 sel_tick1sec, cs_uint16 mode);

cs_status ten_pp10g_pm_clear(cs_uint16 module_id, cs_uint8 slice, cs_uint16 clear);

cs_boolean ten_pp10g_pm_get_busy_status(cs_uint16 module_id, cs_uint8 slice);

cs_boolean ten_pp10g_pm_get_init_done_status(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_pp10g_pm_read_counter(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint32 cntr_id, 
                                   cs_uint32 *counter_ms, cs_uint32 *counter_ls);

cs_status ten_pp10g_rs_tx_sreset(cs_uint16 module_id, cs_uint8 slice,
                                 cs_reset_action_t act, cs_uint16 bitfield);

cs_status ten_pp10g_rs_tx_profile(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 tx_profile);

cs_status ten_pp10g_rs_tx_port_ctl_user_defined_ordered_set(cs_uint16 module_id,
                                                            cs_uint8 slice,
                                                            cs_boolean tx_userorden);

cs_status ten_pp10g_rs_tx_port_ctl_fault_ordered_set_insert(cs_uint16 module_id,
                                                            cs_uint8 slice,
                                                            cs_boolean tx_remoteorden,
                                                            cs_boolean tx_localorden);

cs_status ten_pp10g_rs_tx_control_data_truncation_on_ordered_set(cs_uint16 module_id,
                                                                 cs_uint8 slice,
                                                                 cs_boolean
                                                                 tx_datatruncen);

cs_status ten_pp10g_rs_tx_port_set_user_defined_ordered_set(cs_uint16 module_id,
                                                            cs_uint8 slice,
                                                            cs_uint8 tx_userordl1,
                                                            cs_uint8 tx_userordl2,
                                                            cs_uint8 tx_userordl3);

cs_int16 ten_pp10g_rs_tx_get_status(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 select);

cs_status ten_pp10g_rs_tx_oidlecount(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 oidle_pkt_tx);

cs_status ten_pp10g_rs_rx_rxcntrl1(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act);

cs_status ten_pp10g_rs_rx_profile(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 rx_profile);

cs_status ten_pp10g_rs_rx_control_hsifoken(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 rx_hsifoken);
                                  
cs_status ten_pp10g_rs_rx_control(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 rx_ofsmunhen, cs_uint16 rx_noipg,
                                  cs_uint16 rx_phyrlfen, cs_uint16 rx_siglosen,
                                  cs_uint16 rx_hsifoken);

cs_status ten_pp10g_rs_rx_set_link_fault_thresholds(cs_uint16 module_id, cs_uint8 slice,
                                                    cs_uint16 rx_seq_thr,
                                                    cs_uint16 rx_col_thr);

cs_int16 ten_pp10g_rs_rx_get_status(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 select);
                                    
cs_int16 ten_pp10g_rs_rx_get_unknown_ordered_set(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint8 rx_unknownord_lane_select);

cs_status ten_pp10g_xaui_rx_reset(cs_uint16 module_id, cs_uint8 slice,
                                  cs_reset_action_t act);

cs_status ten_pp10g_xaui_rx_control0(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_fpat_sel, cs_uint16 xgxs_ddsa_enable,
                                     cs_uint16 xgxs_lf_enable, cs_uint16 xgxs_rx_mode);

cs_status ten_pp10g_xaui_rx_control1(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_fpat_0);

cs_status ten_pp10g_xaui_rx_control2(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_fpat_1);

cs_status ten_pp10g_xaui_rx_control3(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_fpat_2);

cs_status ten_pp10g_xaui_rx_control4(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_fpat_3);

cs_status ten_pp10g_xaui_rx_control5(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 sub_i4r, cs_uint16 sub_i4k,
                                     cs_uint16 sub_i4a);

cs_status ten_pp10g_xaui_rx_scratch(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 scratch);

cs_int16 ten_pp10g_xaui_rx_get_status(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint16 select);
                                      
cs_int16 ten_pp10g_xaui_rx_check_insync(cs_uint16 module_id, cs_uint8 slice);
                                      
cs_status ten_pp10g_xaui_tx_reset(cs_uint16 module_id, cs_uint8 slice,
                                  cs_reset_action_t act);

cs_status ten_pp10g_xaui_tx_txcntrl0(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_fpat_sel, cs_uint16 xgxs_tx_err_inj,
                                     cs_uint16 xgxs_tx_random_6, cs_uint16 xgxs_tx_mode);

cs_status ten_pp10g_xaui_tx_control1(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_fpat_0);

cs_status ten_pp10g_xaui_tx_control2(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_fpat_1);

cs_status ten_pp10g_xaui_tx_control3(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_fpat_2);

cs_status ten_pp10g_xaui_tx_control4(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_fpat_3);

cs_status ten_pp10g_xaui_tx_control5(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 xgxs_tx_fone, cs_uint16 xgxs_tx_fzero,
                                     cs_uint16 rs_truncate, cs_uint16 rs_force_output,
                                     cs_uint16 xgxs_tx_phase);

cs_status ten_pp10g_xaui_tx_control6(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 rs_lane_2, cs_uint16 rs_lane_1);

cs_status ten_pp10g_xaui_tx_control7(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 rs_lane_3);

cs_int16 ten_pp10g_xaui_tx_get_status(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint16 select);

cs_status ten_pp10g_xaui_tx_scratch(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 scratch);

cs_status ten_pp10g_xgadj_tx_reset(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act);

cs_status ten_pp10g_xgadj_tx_set_control(cs_uint16 module_id, cs_uint8 slice,
                                         cs_uint16 maxsize_truncate,
                                         cs_uint16 xcon_disable, cs_uint16 insert_disable,
                                         cs_uint16 translate, cs_uint16 profile,
                                         cs_uint16 sfd_check, cs_uint16 append_fcs,
                                         cs_uint16 insert_append_fcs);

cs_status ten_pp10g_xgadj_tx_fillctrl(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint16 fill_enable, cs_uint16 repeat_enable);

cs_status ten_pp10g_set_xgadj_tx_fillctrl(cs_uint16 module_id,
                                          cs_uint8 slice, 
                                          cs_uint16 select, 
                                          cs_uint16 value);

cs_status ten_pp10g_xgadj_tx_filldata(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 fill_data1, cs_uint16 fill_data0);
                                       
cs_status ten_pp10g_xgadj_tx_maxframe(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 maxsize1,
                                      cs_uint16 maxsize0);                                      

cs_int16 ten_pp10g_xgadj_tx_get_status(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 select);
                                       
cs_status ten_pp10g_xgadj_tx_insert_flen(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 flen);
                                
cs_uint16 ten_pp10g_xgadj_tx_insert_get_av(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_pp10g_xgadj_tx_insert_access_0(cs_uint16 module_id, cs_uint8 slice, 
                                         cs_uint16 data_0);
                                         
cs_status ten_pp10g_xgadj_tx_insert_access_n(cs_uint16 module_id, cs_uint8 slice, 
                                         cs_uint16 data_n);
                                         
cs_status ten_pp10g_xgadj_tx_insert_frame(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 frame_size, 
                                    cs_char8 *frame_octets);
                                       
cs_status ten_pp10g_xgadj_rx_reset(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act);

cs_status ten_pp10g_xgadj_rx_control(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 translate, cs_uint16 rx_profile,
                                     cs_uint16 tx_profile);

cs_status ten_pp10g_xgadj_rx_rate_control(cs_uint16 module_id, cs_uint8 slice,
                                          cs_uint16 idle_all, cs_uint16 frames_all,
                                          cs_uint16 client_all, cs_uint16 seq_os_all,
                                          cs_uint16 seq_os_2nd, cs_uint16 fc_idle);
                                          
cs_status ten_pp10g_xgadj_rx_rate_control_frames_all(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_uint16 frames_all);
                                   
cs_status ten_pp10g_xgadj_client_all(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 client_all);

cs_status ten_pp10g_xgadj_seq_os_all(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 seq_os_all);

cs_status ten_pp10g_xgadj_rx_rate_control1(cs_uint16 module_id, cs_uint8 slice,
                                           cs_uint16 map_idle_all,
                                           cs_uint16 map_seq_os_2nd);

cs_status ten_pp10g_xgadj_map_idle_all(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 map_idle_all);

cs_status ten_pp10g_xgadj_map_seq_os_all(cs_uint16 module_id, cs_uint8 slice,
                                         cs_uint16 map_seq_os_all);
                                         
cs_status ten_pp10g_xgadj_rx_ratecntrl_idle_all(cs_uint16 module_id,
                                                cs_uint8 slice, 
                                                cs_uint16 idle_all);
/* Bugzilla 37543 Start */
cs_status ten_pp10g_xgadj_rx_ratecntrl_idle_2nd(cs_uint16 module_id,
                                                cs_uint8 slice, 
                                                cs_uint16 idle_2nd);
/* Bugzilla 37543 End */
cs_status ten_pp10g_xgadj_rx_ratecntrl_client_all(cs_uint16 module_id, cs_uint8 slice,
                                                  cs_uint16 client_all);

cs_status ten_pp10g_xgadj_rx_rate_control2(cs_uint16 module_id, cs_uint8 slice,
                                           cs_uint16 map_frames_all,
                                           cs_uint16 map_client_all_hi,
                                           cs_uint16 map_client_all_lo);
                                           
cs_status ten_pp10g_xgadj_rx_rate_control2_map_frames_all(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 map_frames_all);
                                          
cs_status ten_pp10g_xgadj_rx_rate_control2_hi_lo(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 map_client_all_hi,
                                    cs_uint16 map_client_all_lo);                                           

cs_status ten_pp10g_xgadj_rx_rate_control3(cs_uint16 module_id, cs_uint8 slice,
                                           cs_uint16 min_ifg);

cs_uint16 ten_pp10g_xgadj_get_rx_extr_lock(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_pp10g_xgadj_rx_extr_lock(cs_uint16 module_id, cs_uint8 slice);

cs_int16 ten_pp10g_xgadj_rx_get_extr_status(cs_uint16 module_id, cs_uint8 slice,
                                             cs_uint16 select);

cs_status ten_pp10g_xgadj_rx_extr_read_0(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 data_0);

cs_status ten_pp10g_xgadj_rx_extr_read_n(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 data_n);
                                     
cs_status ten_pp10g_xgadj_rx_extract_frame(cs_uint16 module_id, cs_uint8 slice, 
                                           cs_uint16 *frame_size,
                                           cs_uint16 *frame_error, 
                                           cs_char8 *frame_octets);
                                           
cs_status ten_pp10g_xgadj_print_rx_extract_frame(cs_uint16 module_id,
                                                 cs_uint8 slice);
                                           
cs_int16 ten_pp10g_xgadj_rx_get_status(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 select);

cs_status ten_pp10g_xgadj_rx_discard_eligible(cs_uint16 module_id, cs_uint8 slice,
                                              cs_uint16 discard_eligible);

cs_status ten_pp10g_xgadj_tx_cntrl1(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 auto_fill, cs_uint16 translate,
                                    cs_uint16 profile, cs_uint16 no_ipg_check);

cs_status ten_pp10g_xgadj_below_disable(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 below_disable);

cs_boolean ten_pp10g_get_funcen_rx(cs_uint16 module_id,
                                   cs_uint8 slice, 
                                   cs_uint16 select);
                                   
cs_boolean ten_pp10g_get_funcen_tx(cs_uint16 module_id,
                                   cs_uint8 slice, 
                                   cs_uint16 select);

cs_status ten_pp10g_gfp_rx_set_outctrl(cs_uint16 module_id, 
                                       cs_uint8  slice, 
                                       cs_uint16 outctrl);

/* T41 additions */
cs_status ten_pp10g_ctl_rx_sfu_fail_en(cs_uint16 module_id,
                                       cs_uint8  slice, 
                                       cs_uint16 condition,
                                       cs_ctl_t ctl);
                                       
cs_status ten_pp10g_ctl_rx_fwd_lf_en(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 condition,
                                     cs_ctl_t ctl);
                                     
cs_status ten_pp10g_ctl_rx_fwd_rf_en(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 condition,
                                     cs_ctl_t ctl);
                                     
cs_status ten_pp10g_rx_alarms_reset(cs_uint16         module_id,
                                    cs_uint8          slice, 
                                    cs_reset_action_t act);

cs_status ten_pp10g_tx_alarms_reset(cs_uint16         module_id,
                                    cs_uint8          slice, 
                                    cs_reset_action_t act);
                                    
cs_status ten_pp10g_ctl_tx_alarm_action(cs_uint16 module_id,
                                        cs_uint8  slice, 
                                        cs_uint16 condition,
                                        cs_ctl_t ctl);

/* Bugzilla 29751 Start */
cs_status ten_pp10g_pcs_rx_rxint_handler_enable (cs_uint16 module_id,
                                                 cs_uint16 slice,
                                                 cs_uint16 bitfield);
/* Bugzilla 29751 End */

cs_status ten_pp10g_xcode_remap_write(cs_uint16 module_id,
                                      cs_uint8  slice, 
                                      cs_dir_t  dir,
                                      cs_uint16 index, 
                                      cs_uint16 data);

cs_uint16 ten_pp10g_xcode_remap_read(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_dir_t  dir,
                                     cs_uint16 index);

cs_status ten_pp10g_xcode_remap_g709_provision(cs_uint16 module_id,
                                               cs_uint8  slice);

/* Bugzilla 36089 Start */
cs_status ten_pp10g_xcode_remap_cortina_provision(cs_uint16 module_id,
                                                  cs_uint8  slice);
/* Bugzilla 36089 End */

cs_uint16 ten_pp10g_xcode_remap_dump(cs_uint16 module_id,
                                     cs_uint8  slice);

cs_status ten_pp10g_mon10b_ber10b_en_t41(cs_uint16 module_id,
                                         cs_uint8  slice, 
                                         cs_ctl_t  enbl);

cs_status ten_pp10g_mon10b_reset_t41(cs_uint16         module_id,
                                     cs_uint8          slice, 
                                     cs_reset_action_t act);

cs_status ten_pp10g_ber10b_reset_t41(cs_uint16         module_id,
                                     cs_uint8          slice, 
                                     cs_reset_action_t act);

cs_status ten_pp10g_mon10b_gb_sel_t41(cs_uint16 module_id,
                                      cs_uint8  slice, 
                                      cs_uint16 gb_sel);

cs_status ten_pp10g_mon10b_csymb_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 csymb);

cs_status ten_pp10g_mon10b_data_start_t41(cs_uint16 module_id,
                                          cs_uint8  slice, 
                                          cs_uint16 start_k28_2);

cs_status ten_pp10g_mon10b_align_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 a_timeout_ls,
                                     cs_uint16 a_timeout_ms,
                                     cs_uint16 a_align_char,
                                     cs_uint16 a_loathr,
                                     cs_uint16 a_acqthr);

cs_status ten_pp10g_mon10b_force_hunt_t41(cs_uint16 module_id,
                                          cs_uint8  slice, 
                                          cs_uint16 a_force_hunt);

cs_status ten_pp10g_mon10b_sync_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 s_timeout_ls,
                                     cs_uint16 s_timeout_ms,
                                     cs_uint16 s_loathr,
                                     cs_uint16 s_acqthr);

cs_status ten_pp10g_ber10b_interval_t41(cs_uint16 module_id,
                                        cs_uint8  slice, 
                                        cs_uint16 ns,
                                        cs_uint16 nc);

cs_status ten_pp10g_ber10b_threshold_t41(cs_uint16 module_id,
                                         cs_uint8  slice, 
                                         cs_uint16 ts,
                                         cs_uint16 tc);

cs_status ten_pp10g_ber10b_filter_t41(cs_uint16 module_id,
                                      cs_uint8  slice, 
                                      cs_uint16 ms,
                                      cs_uint16 mc);
                                      
cs_uint16 ten_pp10g_get_clken_line_rx_en_rs(cs_uint16 module_id,
                                            cs_uint8 slice);
                                            
#ifdef __cplusplus
}
#endif
#endif


