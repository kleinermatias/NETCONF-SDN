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
 * ten_glb_misc_api.h 
 *
 * $Id: ten_glb_misc_api.h,v 1.8 2013/02/22 21:09:38 jccarlis Exp $
 *
 * API prototypes for GLB MISC 
 *
 */
 
#ifndef __TEN_GLB_MISC_API_H__
#define __TEN_GLB_MISC_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_glb_misc_set_gsti(cs_uint16 dev_id, cs_uint8 instance, 
                                cs_uint16 base1,
                                cs_uint16 base0);
                                
cs_status ten_glb_misc_set_gsti_prescale(cs_uint16 dev_id, 
                           cs_uint16 prescale);
                           
cs_status ten_glb_misc_gsti_update(cs_uint16 dev_id, 
                        cs_ctl_t sw, 
                        cs_ctl_t init);
                        
cs_status ten_glb_misc_gsti_init(cs_uint16 dev_id, 
                        cs_ctl_t init);
                        
cs_status ten_glb_misc_gsti_sw(cs_uint16 dev_id);

cs_status ten_glb_misc_mra1_losaf0(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 los_siv, 
                                   cs_uint16 los_stv);
                                   
cs_status ten_glb_misc_mra1_losaf1(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 los_uiv, 
                                   cs_uint16 los_utv);
                                   
cs_status ten_glb_misc_mrb1_losaf0(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 los_siv, 
                                   cs_uint16 los_stv);
                                   
cs_status ten_glb_misc_mrb1_losaf1(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 los_uiv, 
                                   cs_uint16 los_utv);
                                   
cs_status ten_glb_misc_xfi1_losaf0(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 los_siv, 
                                   cs_uint16 los_stv);
                                   
cs_status ten_glb_misc_xfi1_losaf1(cs_uint16 dev_id, cs_uint8 instance, 
                               cs_uint16 los_uiv, 
                               cs_uint16 los_utv);
                               
cs_status ten_glb_misc_xlos_cfg_clear(cs_uint16 dev_id, 
                            cs_uint16 clear);
                            
cs_status ten_glb_misc_xlos_cfg_prescale(cs_uint16 dev_id, 
                            cs_uint16 clear, 
                            cs_uint16 prescale);
                            
cs_status ten_glb_misc_xlos_inv_xfi(cs_uint16 dev_id, 
                                    cs_uint16 xfi);
                                    
cs_status ten_glb_misc_xlos_inv_mrb(cs_uint16 dev_id, 
                                    cs_uint16 mrb);
                                    
cs_status ten_glb_misc_xlos_inv_mra(cs_uint16 dev_id, 
                            cs_uint16 mra);

/* Bugzilla 26510 Start */
cs_status ten_glb_misc_xlos_inv_mr(cs_uint16 module_id, 
                                   cs_uint8 slice, 
                                   cs_uint16 active_low);
/* Bugzilla 26510 End */

/* Bugzilla 24956 Start */
double ten_calculate_signal_rate (cs_uint16 traffic_type, cs_uint16 fec);
/* Bugzilla 24956 End */

#ifdef __cplusplus
}
#endif
#endif

