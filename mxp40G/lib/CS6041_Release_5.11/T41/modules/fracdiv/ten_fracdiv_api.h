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
 * ten_fracdiv_api.h
 *
 * API Header file for FRAC DIV block.
 *
 * $Id: ten_fracdiv_api.h,v 1.3 2013/02/22 20:42:54 jccarlis Exp $
 *
 */

#ifndef __TEN_FRACDIV_API_H__
#define __TEN_FRACDIV_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_frac_div_common_frac_div_s2_preload(cs_uint16 dev_id, cs_uint16 value1,
                                                  cs_uint16 value0);

cs_status ten_frac_div_cfg_frac_div_reset(cs_uint16 dev_id, cs_uint8 instance, 
                                      cs_reset_action_t act);

cs_status ten_frac_div_cfg_frac_div_enable(cs_uint16 dev_id, cs_uint8 instance,
                                           cs_uint16 value);

cs_status ten_frac_div_cfg_frac_div_n(cs_uint16 dev_id, cs_uint8 instance,
                                       cs_uint16 value1, cs_uint16 value0);

cs_status ten_frac_div_cfg_frac_div_width(cs_uint16 dev_id, cs_uint8 instance,
                                          cs_uint16 value);

cs_status ten_frac_div_cfg_frac_div_s1en(cs_uint16 dev_id, cs_uint8 instance,
                                         cs_uint16 value);

cs_status ten_frac_div_cfg_frac_div_s2en(cs_uint16 dev_id, cs_uint8 instance,
                                         cs_uint16 value);

cs_status ten_frac_div_cfg_frac_div_s1_preload(cs_uint16 dev_id, cs_uint8 instance,
                                               cs_uint16 value1, cs_uint16 value0);

cs_status ten_frac_div_cfg_frac_div_dither(cs_uint16 dev_id, cs_uint8 instance,
                                           cs_uint16 value);

cs_status ten_frac_div_cfg_frac_div_ds(cs_uint16 dev_id, cs_uint8 instance,
                                       cs_uint16 value);

cs_status ten_frac_div_cfg_frac_div_int(cs_uint16 dev_id, cs_uint8 instance,
                                        cs_uint16 value);

cs_status ten_frac_div_cfg_frac_div_cc(cs_uint16 dev_id, cs_uint8 instance,
                                       cs_uint16 value);

#ifdef __cplusplus
}
#endif
#endif
