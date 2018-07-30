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
 * ten_dm_api.h
 *
 * API Header file for DM block.
 *
 * $Id: ten_dm_api.h,v 1.4 2013/02/22 20:48:18 jccarlis Exp $
 *
 */

#ifndef __TEN_DM_API_H__
#define __TEN_DM_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_dm_set_dmsel_cfg_n10g_txsrc(cs_uint16 dev_id, 
                                          cs_uint16 module_num,
                                          cs_uint8  slice);
                                          
cs_status ten_dm_set_dmsel_cfg_n10g_rxsrc(cs_uint16 dev_id, 
                                          cs_uint16 module_num,
                                          cs_uint8  slice);
                                          
cs_status ten_dm_set_dmsel_cfg_n40g_txsrc(cs_uint16 dev_id, 
                                          cs_uint16 module_num);
                                          
cs_status ten_dm_set_dmsel_cfg_n40g_rxsrc(cs_uint16 dev_id, 
                                          cs_uint16 module_num);
                                          
cs_status ten_dm_dmsel_cfg_cnt_stop(cs_uint16 dev_id, 
                                    cs_uint16 dm_cnt_stop);
                                    
cs_status ten_dm_set_threshold(cs_uint16 dev_id, 
                               cs_uint32 dm_thresh);
                               
cs_uint32 ten_dm_get_delay(cs_uint16 dev_id);

double ten_dm_get_delay_us(cs_uint16 dev_id);

cs_status ten_dm_intr(cs_uint16 dev_id, 
                      cs_uint16 dm_int);
                      
cs_uint16 ten_dm_get_intr(cs_uint16 dev_id);

#ifdef __cplusplus
}
#endif
#endif
