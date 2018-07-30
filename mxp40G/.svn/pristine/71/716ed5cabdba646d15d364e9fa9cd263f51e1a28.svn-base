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
 * ten_pp40g_api.h
 *
 * API Header file for PP40G block.
 *
 * $Id: ten_pp40g_api.h,v 1.24 2013/02/22 20:56:33 jccarlis Exp $
 *
 */

/* Bugzilla 24881 start */
#ifdef __cplusplus
extern "C" {
#endif
/* Bugzilla 24881 end */

cs_status ten_pp40g_misc_control_sreset_t41(cs_uint16 module_id, 
                                            cs_reset_action_t act);
                                            
cs_uint16 ten_pp40g_get_misc_sreset_t41(cs_uint16 module_id);
                                      
cs_status ten_pp40g_lif_rx_control_sreset_t41(cs_uint16 module_id, 
                                              cs_reset_action_t act);
                                              
cs_status ten_pp40g_pcs_rx_control_sreset_t41(cs_uint16 module_id, 
                                              cs_reset_action_t act);
                                              
cs_status ten_pp40g_rs_rx_control_sreset_t41(cs_uint16 module_id, 
                                             cs_reset_action_t act);
                                             
cs_status ten_pp40g_mac_rx_control_sreset_t41(cs_uint16 module_id, 
                                              cs_reset_action_t act);
                                              
cs_status ten_pp40g_pcs_tx_control_sreset_t41(cs_uint16 module_id, 
                                              cs_reset_action_t act);
                                              
cs_status ten_pp40g_pbert40g_tx_control_sreset_t41(cs_uint16 module_id, 
                                                   cs_reset_action_t act);
                                                   
cs_status ten_pp40g_pm_control_sreset_t41(cs_uint16 module_id, 
                                          cs_reset_action_t act);
                                          
cs_uint16 ten_pp40g_misc_intstatus_rx_dsk_syncs_t41(cs_uint16 module_id);

cs_uint16 ten_pp40g_lif_rx_intstatus_t41(cs_uint16 module_id, 
                                         cs_uint16 select);
                                         
cs_uint16 ten_pp40g_pcs_rx_amstatus_t41(cs_uint16 module_id, 
                                        cs_uint16 select);
                                        
cs_uint16 ten_pp40g_pcs_rx_amstatus1_t41(cs_uint16 module_id, 
                                         cs_uint16 select);
                                         
cs_uint16 ten_pp40g_pcs_rx_intstatus_t41(cs_uint16 module_id, 
                                         cs_uint16 select);
                                         
cs_uint16 ten_pp40g_pcs_rx_skewstatus1_skew_t41(cs_uint16 module_id);

cs_uint16 ten_pp40g_pcs_rx_skewstatus2_ln_last_t41(cs_uint16 module_id);

cs_uint16 ten_pp40g_pcs_rx_skewstatus2_ln_first_t41(cs_uint16 module_id);

cs_uint16 ten_pp40g_rs_rx_intstatus_t41(cs_uint16 module_id, 
                                        cs_uint16 select);
                                        
cs_uint16 ten_pp40g_pcs_tx_intstatus_t41(cs_uint16 module_id, 
                                         cs_uint16 select);
                                         
cs_status ten_pp40g_pm_clear_t41(cs_uint16 module_id);
                                       
cs_status ten_pp40g_set_pbert_protocol_t41(cs_uint16          module_id,
                                           ten_xcon_da_type_t da_type);

cs_status ten_pp40g_pbert_insert_seq_num_t41(cs_uint16 module_id,
                                             cs_ctl_t  ctl);

cs_status ten_pp40g_pbert_set_frame_length_t41(cs_uint16           module_id,
                                               ten_xcon_len_mode_t mode, 
                                               cs_uint16           mask,
                                               cs_uint16           min_len,
                                               cs_uint16           max_len,
                                               cs_uint8            typelength_lsb,
                                               cs_uint8            typelength_msb);

cs_status ten_pp40g_pbert_control_traffic_t41(cs_uint16 module_id,
                                              cs_uint16 units);

cs_status ten_pp40g_pbert_select_fixed_pattern_t41(cs_uint16                module_id,
                                                   ten_xcon_fixed_pattern_t type,
                                                   cs_uint8                 value_n,
                                                   cs_uint8                 value_n_plus_1);

cs_status ten_pp40g_pbert_control_generator_t41(cs_uint16 module_id,
                                                cs_ctl_t  ctl);

cs_status ten_pp40g_pbert_tx_reset_t41(cs_uint16         module_id,
                                       cs_reset_action_t act);

cs_status ten_pp40g_pbert_control_ifg_t41(cs_uint16 module_id,
                                          cs_uint8  ifg);

cs_status ten_pp40g_pbert_inject_err_t41(cs_uint16             module_id,
                                         ten_xcon_error_type_t err_type, 
                                         cs_uint16             frames);

cs_status ten_pp40g_rx_bypass_dsk_en_t41(cs_uint16  module_id,
                                         cs_uint16  rx_dsk_en);

cs_boolean ten_pp40g_is_bypassed_t41(cs_uint16  module_id);


cs_status ten_pp40g_pbert_enable_t41(cs_uint16 module_id,
                                     cs_ctl_t  ctl);

/* Bugzilla 27126 Start */
cs_status ten_pp40g_reset_all_subblocks_t41(cs_uint16 module_id, 
                                            cs_reset_action_t act);
/* Bugzilla 27126 End */
cs_status ten_pp40g_pcs_rx_bertimer_calculate_period(cs_uint16 module_id, 
                                                     cs_uint16 sys_clk,
                                                     cs_uint16 timer_period,
                                                     cs_int16  range_percentage);

cs_status ten_pp40g_pcs_rx_bertimer(cs_uint16 module_id, 
                                    cs_uint16 timer_value);

/* XML Generated APIs */

cs_status ten_pp40g_rx_rx_soft_reset_removal_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_pp40g_rx_bypass_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40gep_xcon_clocks_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40gep_xcon_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40gep_xcon_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40gesbi_xcon_clocks_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40gesbi_xcon_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40gesbi_xcon_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40ges6466_xcon_clocks_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40ges6466_xcon_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40ges6466_xcon_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40gex_xcon_clocks_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40gex_xcon_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_40gex_xcon_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_rx_pp40g_pm_tick_mode_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pp40g_tx_bypass_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40gep_clocks_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_insert_markers_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_disable_markers_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40gep_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40gep_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40gesbi_clocks_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40gesbi_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40gesbi_ra_clocks_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40gesbi_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40ges6466_clocks_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40ges6466_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40ges6466_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40gex_clocks_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40gex_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_xcon_40gex_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_clocks_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_ifg_t41 ( cs_uint16 module_id, cs_uint16 ifg );
cs_status ten_pp40g_tx_pbert_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_40gep_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_40gesbi_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_40ges6466_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_40gex_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_40gep_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_40gesbi_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_40ges6466_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_40gex_ra_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_disable_fpg_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_go_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_tx_pbert_stop_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_common_rst_removal_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_release_pp40g_mpif_reset_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_misc_pbert_tx_soft_reset_removal_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_misc_tx_soft_reset_removal_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_misc_rx_soft_reset_removal_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_misc_all_clock_tx_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_misc_all_clock_rx_t41 ( cs_uint16 module_id );
cs_status ten_pp40g_misc_pp40g_deskew_en_t41 ( cs_uint16 module_id);

/* Bugzilla 29751 Start */
cs_status ten_pp40g_pcs_rx_interupt_handler_enable (cs_uint16 module_id,
                                                    cs_uint16 bitfield);

cs_uint16 ten_pp40g_get_misc_interrupt_rx_dsk_synci_t41(cs_uint16 module_id);

cs_status ten_pp40g_misc_interrupt_rx_dsk_synci_t41(cs_uint16 module_id, 
                                                    cs_uint16 rx_dsk_synci);
                                                    
cs_uint16 ten_pp40g_get_misc_tx_funcen_pbt(cs_uint16 module_id);

cs_uint16 ten_pp40g_misc_tx_clken_pbt(cs_uint16 module_id);

cs_status ten_pp40g_set_pp40g_mpif_reset_t41(cs_uint16 module_id);
cs_status ten_pp40g_misc_clken_clear(cs_uint16 module_id);
/* Bugzilla #28552, C++ compile support */
#ifdef __cplusplus
}
#endif






