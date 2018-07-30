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
 * ten_mpif_api.h
 *
 * API Header file for MPIF block.
 *
 * $Id: ten_mpif_api.h,v 1.37 2013/03/13 20:59:51 jccarlis Exp $
 *
 */

#ifndef __TEN_MPIF_API_H__
#define __TEN_MPIF_API_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Bugzilla #36320 New: Prototye arguments in the T41 header file */
cs_uint32 ten_mpif_get_chip_jtag_id(cs_uint16 dev_id);

cs_status ten_mpif_print_chip_id(cs_uint16 dev_id);

cs_uint32 ten_mpif_get_chip_rev_id(cs_uint16 dev_id);

cs_uint16 ten_mpif_get_chip_dev_id_code_sku(cs_uint16 dev_id);

/* Bugzilla #36320 New: Prototye arguments in the T41 header file */
cs_status ten_mpif_global_cfg(cs_uint16 dev_id,
                          cs_uint16 tx_quad_mode_b,
                          cs_uint16 tx_quad_mode_a,
                          cs_uint16 rx_quad_mode_b,
                          cs_uint16 rx_quad_mode_a);
                          
/* Bugzilla 26130 Start */
cs_status ten_mpif_global_cfg_per_module (cs_uint16 dev_id, 
                                          cs_module_t module_num,
                                          cs_uint16 tx_quad_mode, 
                                          cs_uint16 rx_quad_mode); 
/* Bugzilla 26130 End */

/* Bugzilla #36320 New: Prototye arguments in the T41 header file */
cs_status ten_mpif_global_reset_common(cs_uint16 dev_id,
                                       cs_reset_action_t act,
                                       cs_uint16 bitfield);

cs_status ten_mpif_global_reset_hsif(cs_uint16 dev_id, 
                                     cs_module_t module_num,
                                     cs_dir_t dir, 
                                     cs_reset_action_t act);
                                    
cs_status ten_mpif_global_reset_hsif_mpif(cs_uint16 dev_id, 
                                          cs_module_t module_num,
                                          cs_reset_action_t act);

cs_status ten_mpif_global_reset_sfi41(cs_uint16 dev_id, 
                                      cs_module_t module_num,
                                      cs_dir_t dir, 
                                      cs_reset_action_t act);
                                      
cs_status ten_mpif_global_reset_sfi41_mpif(cs_uint16 dev_id, 
                                           cs_module_t module_num,
                                           cs_reset_action_t act);
                                           
cs_status ten_mpif_global_reset_gfec_10g(cs_uint16 dev_id, 
                                         cs_uint16 select,
                                         cs_dir_t dir, 
                                         cs_reset_action_t act);
                                     
cs_status ten_mpif_global_reset_gfec_40g(cs_uint16 dev_id, 
                                         cs_uint16 select,
                                         cs_dir_t dir, 
                                         cs_reset_action_t act);

cs_status ten_mpif_global_reset_ufec(cs_uint16 dev_id, 
                                     cs_uint16 select,
                                     cs_dir_t dir,
                                     cs_reset_action_t act);

cs_uint16 ten_mpif_get_global_reset_gfec_10g(cs_uint16 dev_id,
                                             cs_uint16 select,
                                             cs_dir_t dir);
                                             
cs_uint16 ten_mpif_get_global_reset_gfec_40g(cs_uint16 dev_id,
                                             cs_uint16 select,
                                             cs_dir_t dir);
                                             
cs_uint16 ten_mpif_get_global_reset_ufec(cs_uint16 dev_id,
                                         cs_uint16 select,
                                         cs_dir_t dir);
                                     
cs_status ten_mpif_global_reset_n40g(cs_uint16 dev_id, 
                                     cs_module_t module_num,
                                     cs_dir_t dir,
                                     cs_reset_action_t act);

cs_uint16 ten_mpif_get_global_reset_n40g(cs_uint16 dev_id,
                                         cs_module_t module_num,
                                         cs_dir_t dir);
                                     
cs_status ten_mpif_global_reset_n10g(cs_uint16 dev_id, 
                                     cs_module_t module_num,
                                     cs_uint8 slice,
                                     cs_dir_t dir,
                                     cs_reset_action_t act);

cs_uint16 ten_mpif_get_global_reset_n10g(cs_uint16 dev_id,
                                         cs_module_t module_num,
                                         cs_uint8 slice,
                                         cs_dir_t dir);
                                         
cs_status ten_mpif_global_reset_pp10g(cs_uint16 dev_id, 
                                      cs_module_t module_num,
                                      cs_uint8 slice,
                                      cs_dir_t dir,
                                      cs_reset_action_t act);
                                      
cs_status ten_mpif_global_reset_pp10g_sys(cs_uint16 dev_id, 
                                      cs_module_t module_num,
                                      cs_uint8 slice, 
                                      cs_reset_action_t act);
                                      
cs_status ten_mpif_global_reset_syncdsync(cs_uint16 dev_id, 
                                          cs_module_t module_num,
                                          cs_uint8 slice,
                                          cs_dir_t dir,
                                          cs_reset_action_t act);

cs_uint16 ten_mpif_get_global_reset_syncdsync(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_uint8 slice,
                                              cs_dir_t dir);
                                              
cs_status ten_mpif_global_reset_gpll(cs_uint16 dev_id, 
                                     cs_module_t module_num,
                                     cs_uint8 slice,
                                     cs_dir_t dir,
                                     cs_reset_action_t act);

/* Bugzilla #36320 New: Prototye arguments in the T41 header file */
cs_status ten_mpif_global_reset_syspll(cs_uint16 dev_id,
                                       cs_reset_action_t act);
                                       
cs_status ten_mpif_global_reset_xfi_dsp(cs_uint16 dev_id, 
                                           cs_uint8 slice,
                                           cs_reset_action_t act);

cs_status ten_mpif_global_reset_clock_loss(cs_uint16 dev_id, 
                                           cs_module_t module_num,
                                           cs_uint8 slice,
                                           cs_dir_t dir,
                                           cs_reset_action_t act);
                                           
/* Bugzilla #36320 New: Prototye arguments in the T41 header file */
cs_status ten_mpif_global_clock_disable_common(cs_uint16 dev_id,
                                               cs_ctl_t  ctl,
                                               cs_uint16 bitfield);
                                               
cs_status ten_mpif_global_clock_disable_mr_a(cs_uint16 dev_id, 
                                             cs_uint8 slice, 
                                             cs_dir_t dir,
                                             cs_ctl_t ctl);

cs_status ten_mpif_global_clock_disable_mr_b(cs_uint16 dev_id, 
                                             cs_uint8 slice, 
                                             cs_dir_t dir,
                                             cs_ctl_t ctl);

cs_status ten_mpif_global_clock_disable_xfi_b(cs_uint16 dev_id, 
                                              cs_uint8 slice, 
                                              cs_dir_t dir,
                                              cs_ctl_t ctl);

cs_status ten_mpif_global_clock_disable_gfec_10g(cs_uint16 dev_id, 
                                                 cs_uint16 select,
                                                 cs_dir_t dir, 
                                                 cs_ctl_t ctl);

cs_status ten_mpif_global_clock_disable_gfec_40g(cs_uint16 dev_id, 
                                                 cs_uint16 select,
                                                 cs_dir_t dir, 
                                                 cs_ctl_t ctl);

cs_status ten_mpif_global_clock_disable_ufec(cs_uint16 dev_id, 
                                             cs_uint16 select,
                                             cs_dir_t dir,
                                             cs_ctl_t  ctl);

cs_status ten_mpif_global_clock_disable_n40g(cs_uint16 dev_id, 
                                             cs_module_t module_num,
                                             cs_dir_t dir,
                                             cs_ctl_t ctl);

cs_status ten_mpif_global_clock_disable_n10g(cs_uint16 dev_id, 
                                             cs_module_t module_num,
                                             cs_uint8 slice, 
                                             cs_dir_t dir,
                                             cs_ctl_t ctl);

cs_status ten_mpif_global_clock_disable_pp10g(cs_uint16 dev_id, 
                                              cs_module_t module_num,
                                              cs_uint8 slice, 
                                              cs_dir_t dir,
                                              cs_ctl_t ctl);
                                              
cs_int16 ten_mpif_global_get_clock_disable_pp10g(cs_uint16 dev_id, 
                                     cs_module_t module_num,
                                     cs_dir_t dir);

cs_status ten_mpif_clock_select_hsif_out(cs_uint16 dev_id, 
                                              cs_module_t module_num,
                                              cs_uint8 slice, 
                                              cs_dir_t dir,
                                              cs_ctl_t select);
                                              
cs_status ten_mpif_clock_select_gpll_in(cs_uint16 dev_id, 
                                         cs_module_t module_num,
                                         cs_uint8 slice, 
                                         cs_dir_t dir,
                                         cs_ctl_t select);
                                         
cs_status ten_mpif_clock_select_gpll_out(cs_uint16 dev_id, 
                                         cs_module_t module_num,
                                         cs_uint8 slice, 
                                         cs_dir_t dir,
                                         cs_ctl_t select);

/* Bugzilla #36320 New: Prototye arguments in the T41 header file */
cs_status ten_mpif_clock_select_40g(cs_uint16 dev_id,
                                    cs_uint16 txb,
                                    cs_uint16 rxb,
                                    cs_uint16 txa,
                                    cs_uint16 rxa);
                                    
cs_status ten_mpif_clock_select_40g_per_module(cs_uint16 dev_id, 
                                               cs_module_t module_num,
                                               cs_uint16 tx, 
                                               cs_uint16 rx);

/* Bugzilla #36320 New: Prototye arguments in the T41 header file */
cs_status ten_mpif_clock_select_prot(cs_uint16 dev_id,
                                     cs_uint16 tx_40g_prot,
                                     cs_uint16 rx_40g_prot,
                                     cs_uint16 tx_a2b,
                                     cs_uint16 rx_a2b);

cs_status ten_mpif_clock_select_prot_40g(cs_uint16 dev_id,
                                         cs_uint16 tx_40g_prot,
                                         cs_uint16 rx_40g_prot);
                                     
cs_status ten_mpif_clock_select_prot_per_slice(cs_uint16 dev_id, 
                                               cs_module_t module_num,
                                               cs_uint8 slice, 
                                               cs_dir_t dir,
                                               cs_ctl_t select);

cs_uint16 ten_mpif_get_clock_select_prot(cs_uint16 dev_id,
                                         cs_dir_t dir);

/* Bugzilla #36320 New: Prototye arguments in the T41 header file */
cs_status ten_mpif_clock_select_sys(cs_uint16 dev_id,
                                    cs_uint16 bypass);
  
cs_status ten_mpif_gfec_cfg_port2_4(cs_uint16 dev_id,
                                    cs_uint16 module_num,
                                    cs_uint16 slice);
                                    
cs_status ten_mpif_gfec_cfg_port1(cs_uint16 dev_id,
                                  cs_uint16 module_num,
                                  cs_uint16 mode);
                                  
cs_status ten_mpif_ufec_cfg(cs_uint16 dev_id,
                            cs_uint16 module_num,
                            cs_uint16 slice,
                            cs_uint16 mode);
                            
cs_status ten_mpif_rxclk_refout(cs_uint16 dev_id,
                                cs_uint16 div,
                                cs_uint16 select);
                                
cs_status ten_mpif_prbs_sync(cs_uint16 dev_id,
                             cs_uint16 txb,
                             cs_uint16 rxb,
                             cs_uint16 txa,
                             cs_uint16 rxa);
                             
cs_status ten_mpif_scratch_pad1(cs_uint16 dev_id, cs_uint16 value);
                            
cs_uint16 ten_mpif_read_scratch_pad1(cs_uint16 dev_id);

cs_status ten_mpif_scratch_pad2(cs_uint16 dev_id, cs_uint16 value);

cs_uint16 ten_mpif_read_scratch_pad2(cs_uint16 dev_id);

cs_status ten_mpif_gpio_direction(cs_uint16 dev_id, cs_uint16 map, cs_uint16 mask);

cs_status ten_mpif_gpio_ccfp(cs_uint16 dev_id, cs_uint16 en);

cs_status ten_mpif_gpio_output(cs_uint16 dev_id, cs_uint16 data,
                               cs_uint16 mask);
                               
cs_uint16 ten_mpif_gpio_sample(cs_uint16 dev_id, cs_uint16 mask);

cs_status ten_mpif_global_reset_sds_mr(cs_uint16 dev_id, 
                                       cs_module_t module_num,
                                       cs_uint8 slice, 
                                       cs_dir_t dir,
                                       cs_reset_action_t act);
                                       
cs_uint16 ten_mpif_get_global_reset_sds_mr(cs_uint16 dev_id,
                                           cs_module_t module_num,
                                           cs_uint8 slice,
                                           cs_dir_t dir);                                      
                                           
cs_status ten_mpif_global_reset_sds_mr_mpif(cs_uint16 dev_id, 
                                            cs_module_t module_num,
                                            cs_uint8 slice, 
                                            cs_reset_action_t act);

cs_status ten_mpif_global_reset_sds_xfi(cs_uint16 dev_id, 
                                        cs_uint8 slice, 
                                        cs_dir_t dir,
                                        cs_reset_action_t act);
  
cs_uint16 ten_mpif_get_global_reset_sds_xfi(cs_uint16 dev_id,
                                            cs_uint8 slice,
                                            cs_dir_t dir);
  
cs_status ten_mpif_global_reset_sds_xfi_mpif(cs_uint16 dev_id, 
                                             cs_uint8 slice, 
                                             cs_reset_action_t act);

cs_status ten_mpif_global_reset_sds_xfi_dsp_t41(cs_uint16 dev_id,
                                                cs_uint8 slice,
                                                cs_reset_action_t act);

cs_status ten_mpif_set_lvds_pd(cs_uint16 dev_id, 
                               cs_uint16 select,
                               cs_uint16 value);
                               
cs_status ten_mpif_set_lvds_div_pd(cs_uint16 dev_id, 
                                   cs_module_t module_num,
                                   cs_uint8 slice, 
                                   cs_dir_t dir, 
                                   cs_uint16 value);

cs_status ten_mpif_set_clock_switch_force(cs_uint16 dev_id, 
                                          cs_module_t module_num,
                                          cs_uint8 slice, 
                                          cs_dir_t dir,
                                          cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_xlos_mr(cs_uint16 dev_id, 
                                            cs_module_t module_num,
                                            cs_uint8 slice, 
                                            cs_dir_t dir,
                                            cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_xlos_xfi(cs_uint16 dev_id, 
                                             cs_uint8 slice, 
                                             cs_dir_t dir,
                                             cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_xlos_mrb2a(cs_uint16 dev_id,
                                               cs_uint8 slice,
                                               cs_dir_t dir,
                                               cs_ctl_t ctl);
                                               
cs_status ten_mpif_set_clock_switch_lockdet_mr(cs_uint16 dev_id, 
                                               cs_module_t module_num,
                                               cs_uint8 slice, 
                                               cs_dir_t dir,
                                               cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_lockdet_xfi(cs_uint16 dev_id, 
                                                cs_uint8 slice, 
                                                cs_dir_t dir,
                                                cs_ctl_t ctl);
                                                
cs_status ten_mpif_set_clock_switch_lockdet_mrb2a(cs_uint16 dev_id,
                                                  cs_uint8 slice,
                                                  cs_dir_t dir,
                                                  cs_ctl_t ctl);
                                                  
cs_status ten_mpif_set_clock_switch_clkloss(cs_uint16 dev_id, 
                                               cs_module_t module_num,
                                               cs_dir_t dir,
                                               cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_rx_source(cs_uint16 dev_id, 
                                              cs_module_t module_num,
                                              cs_uint8 slice, 
                                              cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_tx_cbrgenais_10g(cs_uint16 dev_id, 
                                                     cs_module_t module_num,
                                                     cs_uint8 slice, 
                                                     cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_tx_cbrgenais_40g(cs_uint16 dev_id, 
                                                     cs_module_t module_num,
                                                     cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_tx_pn11_10g(cs_uint16 dev_id, 
                                                cs_module_t module_num,
                                                cs_uint8 slice, 
                                                cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_tx_pn11_40g(cs_uint16 dev_id, 
                                                cs_module_t module_num,
                                                cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_tx_ms_10g(cs_uint16 dev_id, 
                                              cs_module_t module_num,
                                              cs_uint8 slice, 
                                              cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_tx_ms_40g(cs_uint16 dev_id, 
                                              cs_module_t module_num,
                                              cs_ctl_t ctl);

cs_status ten_mpif_set_clock_switch_tx_msais(cs_uint16 dev_id, 
                                             cs_module_t module_num,
                                             cs_uint8 slice, 
                                             cs_ctl_t ctl);
                                             
cs_status ten_mpif_global_clock_disable_n40g_n10g(cs_uint16 dev_id, 
                                             cs_module_t module_num,
                                             cs_uint8 slice, 
                                             cs_uint8 datapath, 
                                             cs_dir_t dir,
                                             cs_ctl_t ctl);

cs_status ten_hl_mpif_clock_switch_rx (cs_uint16 dev_id, 
                                       cs_module_t module_num,
                                       cs_uint8 slice, 
                                       cs_uint8 select,
                                       cs_ctl_t ctl);
 
cs_status ten_hl_mpif_clock_switch_tx(cs_uint16 dev_id, 
                                       cs_module_t module_num,
                                       cs_uint8 slice, 
                                       cs_uint8 select,
                                       cs_ctl_t ctl);
                                       
cs_status ten_mpif_global_reset_pp40g_sys_t41(cs_uint16 dev_id, 
                                              cs_module_t module_num,
                                              cs_reset_action_t act);
                                              
cs_status ten_mpif_global_reset_pp40g_t41(cs_uint16 dev_id, 
                                          cs_module_t module_num,
                                          cs_dir_t dir,
                                          cs_reset_action_t act);
                                          
cs_status ten_mpif_global_reset_sds_cfp_t41(cs_uint16 dev_id, 
                                            cs_uint8 slice, 
                                            cs_dir_t dir,
                                            cs_reset_action_t act);
 
cs_uint16 ten_mpif_get_global_reset_sds_cfp_t41(cs_uint16 dev_id,
                                                cs_uint8 slice,
                                                cs_dir_t dir);
 
cs_status ten_mpif_global_reset_sds_cfp_mpif_t41(cs_uint16 dev_id, 
                                                 cs_uint8 slice, 
                                                 cs_reset_action_t act);
                                                 
cs_status ten_mpif_global_clock_disable_pp40g_byp_t41(cs_uint16 dev_id, 
                                                      cs_module_t module_num,
                                                      cs_ctl_t ctl);
                                                      
cs_status ten_mpif_global_clock_disable_pp40g_sys_t41(cs_uint16 dev_id, 
                                                      cs_module_t module_num,
                                                      cs_ctl_t ctl);
                                                      
cs_status ten_mpif_global_clock_disable_pp40g_rx_t41(cs_uint16 dev_id, 
                                                     cs_module_t module_num,
                                                     cs_ctl_t ctl);
                                                     
cs_status ten_mpif_global_clock_disable_cfp_t41(cs_uint16 dev_id, 
                                                cs_dir_t dir,
                                                cs_ctl_t ctl);
                                                
cs_boolean ten_mpif_n10g_rx_is_active(cs_uint16 module_id,
                                      cs_uint8  slice);

cs_boolean ten_mpif_pp10g_rx_is_active(cs_uint16 module_id,
                                       cs_uint8  slice);

cs_boolean ten_mpif_cupll_in_holdover(cs_uint16 module_id,
                                      cs_uint8  slice);

cs_status ten_mpif_global_clock_disable_cupll_t41(cs_uint16 dev_id,
                                                  cs_uint8  slice,
                                                  cs_ctl_t  ctl);

cs_status ten_mpif_global_reset_cupll_mpif_t41(cs_uint16         dev_id,
                                               cs_uint8          slice,
                                               cs_reset_action_t act);

cs_status ten_mpif_global_reset_cupll_tx_t41(cs_uint16         dev_id,
                                             cs_uint8          slice,
                                             cs_reset_action_t act);

cs_status ten_mpif_global_reset_cupll_holdover_t41(cs_uint16         dev_id,
                                                   cs_uint8          holdover,
                                                   cs_reset_action_t act);

cs_status ten_mpif_cupll_local_force_t41(cs_uint16 dev_id,
                                         cs_uint8  slice,
                                         cs_uint8  select,
                                         cs_ctl_t  ctl);

cs_status ten_mpif_cupll_settle_force_t41(cs_uint16 dev_id,
                                         cs_uint8   slice,
                                         cs_uint8   select,
                                         cs_ctl_t   ctl);

cs_status ten_mpif_cupll_settle_timer_t41(cs_uint16 dev_id,
                                          cs_uint8  slice, 
                                          cs_uint16 timer);
                                          
cs_status ten_mpif_clock_select_pilot(cs_uint16 dev_id, 
                                      cs_uint16 pilot_rxa2b);
                                      
cs_status ten_mpif_clock_select_pilot_per_slice(cs_uint16 dev_id, 
                                                cs_uint8  slice,
                                                cs_uint16 pilot_rxa2b);
                                      
 cs_status ten_mpif_mr_prot_cfg_clk_xlos(cs_uint16 dev_id, 
                                    cs_uint8  slice,
                                    cs_dir_t  dir,
                                    cs_uint16 clk_xlos);
                                    
cs_status ten_mpif_mr_prot_cfg_clk_pswtchen(cs_uint16 dev_id, 
                                    cs_uint8  slice,
                                    cs_dir_t  dir,
                                    cs_uint16 clk_pswtchen);

cs_status ten_mpif_rxdiv_cfg0_mode_t41(cs_uint16 dev_id,
                                       cs_uint8  instance, 
                                       cs_uint16 mode);
                                  
cs_status ten_mpif_rxdiv_cfg0_pilot_t41(cs_uint16 dev_id,
                                        cs_uint8  instance, 
                                        cs_uint16 pilot);

cs_status ten_mpif_pilot_div(cs_uint16 dev_id,
                             cs_uint8  instance, 
                             cs_uint16 div);
                             
cs_status ten_mpif_rxdiv_cfg0_rx_sel_t41(cs_uint16 dev_id,
                                         cs_uint8  instance, 
                                         cs_uint16 rx_sel);
                                         
cs_status ten_mpif_rxline_div0_div_t41(cs_uint16 dev_id, 
                                       cs_uint8 instance, 
                                       cs_uint16 div);
                                   
cs_status ten_mpif_txline_div0_div_t41(cs_uint16 dev_id, 
                                       cs_uint8 instance, 
                                       cs_uint16 div);
                                   
cs_status ten_mpif_txdiv_cfg0_mode1_t41(cs_uint16 dev_id, 
                                        cs_uint8 instance, 
                                        cs_uint16 mode1);
                                    
cs_status ten_mpif_txdiv_cfg0_mode_t41(cs_uint16 dev_id, 
                                       cs_uint8 instance, 
                                       cs_uint16 mode);
 
cs_status ten_mpif_cupll_holdover_lockdet(cs_uint16 dev_id,
                                          cs_uint8  slice,
                                          cs_uint8  select,
                                          cs_ctl_t  ctl);

cs_status ten_mpif_cupll_holdover_select(cs_uint16 dev_id,
                                         cs_uint8  slice,
                                         cs_ctl_t  ctl);

/* Bugzilla 30990                                            */
cs_uint32 ten_mpif_udelay_hi_res(cs_uint16 dev_id, 
                                 cs_uint32 usecs );
cs_status ten_mpif_init_access_times(cs_uint16 dev_id,
                                     cs_uint32 sysclk_freq);

void      ten_mpif_dump_cb(ten_mpif_cb_t *mpif_cb);  /* Release 5.5 */
/* end Bugzilla 30990                                        */

cs_uint16 ten_mpif_get_clock_switch_xlos_mr(cs_uint16 dev_id,
                                            cs_module_t module_num,
                                            cs_uint8 slice,
                                            cs_dir_t dir);
                                            
cs_uint16 ten_mpif_get_clock_switch_xlos_xfi(cs_uint16 dev_id,
                                             cs_uint8 slice,
                                             cs_dir_t dir);
                                             
cs_uint16 ten_mpif_get_clock_switch_xlos_mrb2a(cs_uint16 dev_id,
                                               cs_uint8 slice,
                                               cs_dir_t dir);                                           
                                               
cs_uint16 ten_mpif_get_clock_switch_lockdet_mr(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_uint8 slice,
                                              cs_dir_t dir);
                                              
cs_uint16 ten_mpif_get_clock_switch_lockdet_mrb2a(cs_uint16 dev_id,
                                                  cs_uint8 slice,
                                                  cs_dir_t dir);
 
cs_uint16 ten_mpif_get_clock_switch_lockdet_xfi(cs_uint16 dev_id,
                                                cs_uint8 slice,
                                                cs_dir_t dir);

cs_uint16 ten_mpif_get_clock_switch_tx_cbrgenais_10g(cs_uint16 dev_id,
                                                     cs_module_t module_num,
                                                     cs_uint8 slice);

cs_uint16 ten_mpif_get_clock_switch_tx_cbrgenais_40g(cs_uint16 dev_id,
                                                     cs_module_t module_num);

cs_uint16 ten_mpif_get_clock_switch_tx_pn11_10g(cs_uint16 dev_id,
                                                cs_module_t module_num,
                                                cs_uint8 slice);
                                                
cs_uint16 ten_mpif_get_clock_switch_tx_pn11_40g(cs_uint16 dev_id,
                                                cs_module_t module_num);
                                                
cs_uint16 ten_mpif_get_clock_switch_tx_ms_10g(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_uint8 slice);

cs_uint16 ten_mpif_get_clock_switch_tx_ms_40g(cs_uint16 dev_id,
                                              cs_module_t module_num);

cs_uint16 ten_mpif_get_clock_switch_tx_msais(cs_uint16 dev_id,
                                             cs_module_t module_num,
                                             cs_uint8 slice);
                                             
cs_status ten_mpif_global_reset_dm_mpif_t41(cs_uint16 dev_id,
                                            cs_reset_action_t act);
                                            
cs_status ten_mpif_global_reset_dm_logic_t41(cs_uint16 dev_id,
                                            cs_reset_action_t act);

cs_status ten_mpif_clock_select_int_rxdiv(cs_uint16 dev_id,
                                          cs_module_t module_num,
                                          cs_uint8 slice,
                                          cs_dir_t dir,
                                          cs_ctl_t select);
                                          
cs_uint16 ten_mpif_get_global_reset_cupll_mpif_t41(cs_uint16         dev_id,
                                                   cs_uint8          slice);
                                                   
#ifdef __cplusplus
}
#endif
#endif
