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
 * ten_syncdsync_api.h
 *
 * API Header file for SYNCDSYNC block.
 *
 * $Id: ten_syncdsync_api.h,v 1.6 2013/02/22 20:50:01 jccarlis Exp $
 *
 */

#ifndef __TEN_SYNCDSYNC_API_H__
#define __TEN_SYNCDSYNC_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_syncdsyncrx_cfg(cs_uint16 module_id,
                              cs_uint8  slice, 
                              cs_uint32 numerator_ms,
                              cs_uint32 numerator_ls,
                              cs_uint32 denominator_ms,
                              cs_uint32 denominator_ls,
                              cs_uint32 ac1_ms,
                              cs_uint32 ac1_ls,
                              cs_uint32 ac2_ms,
                              cs_uint32 ac2_ls,
                              cs_uint32 ad1,
                              cs_uint32 ad2,
                              cs_uint16 cfg_mode);
   
cs_status ten_syncdsync_config_1_to_1(cs_uint16 module_id,
                                         cs_uint8  slice,
                                         cs_uint16 rxdivmux,
                                         cs_dir_t  dir,
                                         cs_uint16 k);
   
cs_status ten_syncdsyncrx_control_sreset(cs_uint16 module_id, cs_uint8 slice,
                                         cs_reset_action_t act);

cs_status ten_syncdsyncrx_set_mode(cs_uint16 module_id, cs_uint8 slice, cs_uint16 mode);

cs_status ten_syncdsyncrx_select_global_timing_source(cs_uint16 module_id, cs_uint8 slice,
                                                      cs_uint16 select);

cs_status ten_syncdsyncrx_set_numerator(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 numerator2, cs_uint16 numerator1,
                                        cs_uint16 numerator0);

cs_status ten_syncdsyncrx_set_denominator(cs_uint16 module_id, cs_uint8 slice,
                                          cs_uint16 denominator2, cs_uint16 denominator1,
                                          cs_uint16 denominator0);

cs_status ten_syncdsyncrx_set_ac1(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ac12,
                                  cs_uint16 ac11, cs_uint16 ac10);

cs_status ten_syncdsyncrx_set_ac2(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ac22,
                                  cs_uint16 ac21, cs_uint16 ac20);

cs_status ten_syncdsyncrx_set_ad1(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ad11,
                                  cs_uint16 ad10);

cs_status ten_syncdsyncrx_set_ad2(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ad21,
                                  cs_uint16 ad20);

cs_status ten_syncdsyncrx_set_odtu23_pjo_threshold(cs_uint16 module_id, cs_uint8 slice,
                                                   cs_uint16 odtu23_pjo_th1,
                                                   cs_uint16 odtu23_pjo_th0);

cs_status ten_syncdsyncrx_set_odtu23_njo_threshold(cs_uint16 module_id, cs_uint8 slice,
                                                   cs_uint16 odtu23_njo_th1,
                                                   cs_uint16 odtu23_njo_th0);

cs_status ten_syncdsyncrx_set_oxun_pjo_threshold(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint16 oxun_pjo_th1,
                                                 cs_uint16 oxun_pjo_th0);

cs_status ten_syncdsyncrx_set_oxun_njo_threshold(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint16 oxun_njo_th1,
                                                 cs_uint16 oxun_njo_th0);
                                                 
cs_status ten_syncdsynctx_cfg(cs_uint16 module_id,
                              cs_uint8  slice, 
                              cs_uint16 rxdivmux,
                              cs_uint32 numerator_ms,
                              cs_uint32 numerator_ls,
                              cs_uint32 denominator_ms,
                              cs_uint32 denominator_ls,
                              cs_uint32 ac1_ms,
                              cs_uint32 ac1_ls,
                              cs_uint32 ac2_ms,
                              cs_uint32 ac2_ls,
                              cs_uint32 ad1,
                              cs_uint32 ad2,
                              cs_uint16 cfg_mode,
                              cs_uint16 cfg_pd0,
                              cs_uint16 cfg_jc_gen_thrld,
                              cs_uint16 cfg_jc_gen_max_jp);
                                                 
cs_status ten_syncdsynctx_control_sreset(cs_uint16 module_id, cs_uint8 slice,
                                         cs_reset_action_t act);

cs_status ten_syncdsynctx_set_mode(cs_uint16 module_id, cs_uint8 slice, cs_uint16 mode);

cs_status ten_syncdsynctx_set_configuration_rx_div_mux(cs_uint16 module_id,
                                                       cs_uint8 slice,
                                                       cs_uint16 rx_div_mux);

cs_status ten_syncdsynctx_set_configuration_init_prot_en(cs_uint16 module_id,
                                                         cs_uint8 slice,
                                                         cs_uint16 init_prot_en);

/* Bugzilla 23629 Start */
cs_status ten_syncdsynctx_set_configuration_init_force(cs_uint16 module_id,
                                                       cs_uint8 slice,
                                                       cs_reset_action_t act);
/* Bugzilla 23629 End */

cs_status ten_syncdsynctx_select_global_timing_source(cs_uint16 module_id, cs_uint8 slice,
                                                      cs_uint16 select);

cs_status ten_syncdsynctx_cfgtx_cfgpd0(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 dsync_pd_md);

cs_status ten_syncdsynctx_jcgen_configuration(cs_uint16 module_id, cs_uint8 slice,
                                              cs_uint16 jc_gen_thrld,
                                              cs_uint16 jc_gen_max_jp);

cs_status ten_syncdsynctx_set_denominator(cs_uint16 module_id, cs_uint8 slice,
                                          cs_uint16 denominator2, cs_uint16 denominator1,
                                          cs_uint16 denominator0);

cs_status ten_syncdsynctx_set_numerator(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 numerator2, cs_uint16 numerator1,
                                        cs_uint16 numerator0);

cs_status ten_syncdsynctx_set_ac1(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ac12,
                                  cs_uint16 ac11, cs_uint16 ac10);

cs_status ten_syncdsynctx_set_ac2(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ac22,
                                  cs_uint16 ac21, cs_uint16 ac20);

cs_status ten_syncdsynctx_set_ad1(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ad11,
                                  cs_uint16 ad10);

cs_status ten_syncdsynctx_set_ad2(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ad21,
                                  cs_uint16 ad20);

cs_status ten_syncdsynctx_set_odtu23_pjo_threshold(cs_uint16 module_id, cs_uint8 slice,
                                                   cs_uint16 odtu23_pjo_th1,
                                                   cs_uint16 odtu23_pjo_th0);

cs_status ten_syncdsynctx_set_odtu23_njo_threshold(cs_uint16 module_id, cs_uint8 slice,
                                                   cs_uint16 odtu23_njo_th1,
                                                   cs_uint16 odtu23_njo_th0);

cs_status ten_syncdsynctx_set_oxun_pjo_threshold(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint16 oxun_pjo_th1,
                                                 cs_uint16 oxun_pjo_th0);

cs_status ten_syncdsynctx_set_oxun_njo_threshold(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint16 oxun_njo_th1,
                                                 cs_uint16 oxun_njo_th0);
                                                 
cs_int16 ten_syncdsynctx_cfgmontx_get_status(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 select);                                                

cs_status ten_syncdsynctx_gmp_enbl_t41(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 select);
#ifdef __cplusplus
}
#endif
#endif
