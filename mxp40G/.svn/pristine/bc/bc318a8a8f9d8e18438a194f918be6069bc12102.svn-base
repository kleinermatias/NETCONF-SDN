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
 * ten_gpllx1_api.h
 *
 * API Header file for GPLLX1 block.
 *
 * $Id: ten_gpllx1_api.h,v 1.8 2013/12/02 18:26:18 jccarlis Exp $
 *
 */

#ifndef __TEN_GPLLX1_API_H__
#define __TEN_GPLLX1_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_gpllx1_set_stxp0_tx_config(cs_uint16 dev_id, cs_uint8 instance, cs_uint16 stxp_buswidth, cs_uint16 stxp_pilot_sel);

cs_status ten_gpllx1_stxp0_tx_config_lptime_sel(cs_uint16 dev_id, cs_uint8 instance, cs_uint16 stxp_lptime_sel);

cs_status ten_gpllx1_stxp0_tx_pwrdn(cs_uint16 dev_id, cs_uint8 instance, cs_uint16 stxp_pd_lane);

cs_status ten_gpllx1_stxp0_tx_pwrdn_all(cs_uint16 dev_id,
                                        cs_uint8 instance, 
                                        cs_uint16 stxp_pd);

cs_status ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(cs_uint16 dev_id, cs_uint8 instance, cs_uint16 stxp_fastdiv_sel, cs_uint16 stxp_ctrdiv_sel, cs_uint16 stxp_ctvdiv_sel, cs_uint16 stxp_ddiv_sel, cs_uint16 stxp_rdiv_sel);

cs_status ten_gpllx1_set_stxp0_tx_ddiv_sel(cs_uint16 dev_id,
                                           cs_uint8  instance, 
                                           cs_uint16 stxp_ddiv_sel);

/* Bugzilla 37987 Start */
cs_status ten_gpllx1_set_stxp0_tx_fastdiv_sel(cs_uint16 dev_id,
                                              cs_uint8  instance, 
                                              cs_uint16 stxp_fastdiv_sel);
/* Bugzilla 37987 End */

cs_status ten_gpllx1_set_stxp0_tx_clkdiv_rdiv_ctrl(cs_uint16 dev_id, 
                                                   cs_uint8 instance, 
                                                   cs_uint16 stxp_rdiv_sel);

cs_status ten_gpllx1_set_stxp0_tx_clkout_ctrl(cs_uint16 dev_id, cs_uint8 instance, cs_uint16 stxp_tclkien, cs_uint16 stxp_clkouten, cs_uint16 stxp_tclko_sel);

cs_status ten_gpllx1_stxp0_tx_loop_filter(cs_uint16 dev_id, cs_uint8 instance, cs_uint16 stxp_filtr);

cs_status ten_gpllx1_stxp0_tx_cp(cs_uint16 dev_id, cs_uint8 instance, cs_uint16 stxp_cpcur1, cs_uint16 stxp_cpcur0);

cs_status ten_gpllx1_txvco0_thres0(cs_uint16 dev_id, cs_uint8 instance, cs_uint16 freq_thres_sign0, cs_uint16 freq_thres0);

cs_status ten_gpllx1_txvco0_thres1(cs_uint16 dev_id, cs_uint8 instance, cs_uint16 freq_thres_sign1, cs_uint16 freq_thres1);

cs_boolean ten_gpllx1_txlockd0_lock(cs_uint16 dev_id, cs_uint8 instance);

cs_boolean ten_gpllx1_get_txvco_tune_intstatus(cs_uint16 module_id,
                                               cs_uint8 instance);
                                               
cs_status ten_gpllx1_set_txvco0_vcomax(cs_uint16 dev_id,
                                       cs_uint8  instance, 
                                       cs_uint16 vcomax);

cs_status ten_gpllx1_set_txvco0_init(cs_uint16 dev_id,
                                     cs_uint8  instance, 
                                     cs_uint16 init);

cs_status ten_gpllx1_set_stxp0_stxp_clkouten(cs_uint16 dev_id,
                                             cs_uint8 instance, 
                                             cs_uint16 stxp_clkouten);

cs_boolean ten_gpllx1_txlockd0_filt_lock(cs_uint16 dev_id, cs_uint8 instance);

cs_status ten_gpllx1_txlockd0_filter(cs_uint16 dev_id, cs_uint8 instance, 
                                 cs_uint16 stable_period);

cs_status ten_set_vco_coarse_tuning (cs_uint16 dev_id, cs_uint8 instance);

#ifdef __cplusplus
}
#endif
#endif
