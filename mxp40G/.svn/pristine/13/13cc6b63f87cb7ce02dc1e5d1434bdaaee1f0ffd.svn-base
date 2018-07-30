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
 * ten_callback_api.h
 *
 * Provides mechanism for users of this T40 APIs to register their callback
 * functions.
 *
 *
 */

#ifndef TEN_CALLBACK_API_H
#define TEN_CALLBACK_API_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

typedef cs_status (*ten_register_reg_write_t)(volatile cs_uint16* address, cs_uint16 value);

typedef cs_status (*ten_register_reg_read_t)(volatile cs_uint16* address, cs_uint16 value);

typedef void (*ten_register_swerr_t)(cs_uint16 id, 
                                     cs_uint16 errorNumber,
                                     cs_char8* errorString_p);

typedef void (*ten_register_shadow_ram_t)(cs_uint16 module_id,
                                          cs_uint16 bank,
                                          cs_uint16 *shadowRam_p, 
                                          cs_uint16 shadowRamSize);

extern ten_register_reg_write_t   register_write_ptr;
extern ten_register_reg_read_t   register_read_ptr;
extern ten_register_swerr_t      register_swerr_ptr;
extern ten_register_shadow_ram_t register_shadow_ram_ptr;

cs_status ten_init_callbacks(void);

cs_status ten_register_reg_write(ten_register_reg_write_t reg_write_cb);

cs_status ten_register_reg_read(ten_register_reg_read_t reg_read_cb);

cs_status ten_register_swerr(ten_register_swerr_t swerr_cb);

cs_status ten_register_shadow_ram(ten_register_shadow_ram_t reg_shadow_ram_cb);

cs_status ten_unregister_reg_write(void);

cs_status ten_unregister_reg_read(void);

cs_status ten_unregister_swerr(void); 

cs_status ten_unregister_shadow_ram(void);

void ten_reg_write_cb(volatile cs_uint16* address, cs_uint16 value);

void ten_reg_read_cb(volatile cs_uint16* address, cs_uint16 value);

void ten_swerr_cb(cs_uint16 id, 
                  cs_uint16 errorNumber,
                  cs_char8* errorString_p);
                  
void ten_shadow_ram_cb(cs_uint16 module_id,
                       cs_uint16 bank,
                       cs_uint16 *shadowRam_p, 
                       cs_uint16 shadowRamSize);


/* Bugzilla 30990, T41 release 5.5, new callbacks for hi-resolution usec timer */
/* By default this is registered as ten_drvr_udelay_hi_res(), which is a busy- */
/* wait timer. If a high-resolution OS sleep is available, call ten_unregister */
/* _udelay_hi_res(), and then use ten_register_udelay_hi_res to register the   */
/* OS function.                                                                */
typedef void (*ten_register_udelay_hi_res_t)(cs_uint32 usecs);
extern ten_register_udelay_hi_res_t register_udelay_hr_ptr;
cs_status ten_register_udelay_hi_res(ten_register_udelay_hi_res_t udelay_hr_cb);
cs_status ten_unregister_udelay_hi_res(void);
cs_uint16 ten_is_registered_udelay_hi_res(void);
void ten_udelay_hi_res_cb(cs_uint32 usecs);

/* Test functions */
void ten_call_swerr_cb(void);

void ten_notifyShadowRamWritten(cs_uint16 module_id,
                                cs_uint16 bank,
                                cs_uint16 *shadowRam_p, 
                                cs_uint16 shadowRamSize);
                                
void ten_verifyShadowRamWritten(void);

void ten_notifyErrorHandler(cs_uint16 id, 
                            cs_uint16 errorNumber,
                            cs_char8* errorString_p);
                            
void ten_verifyErrorHandler(void);

cs_status my_reg_write(volatile cs_uint16* addr, cs_uint16 value);

void ten_verify_reg_write(void);

cs_status my_reg_read(volatile cs_uint16*, cs_uint16 value);

void ten_verify_reg_read(void);

#ifdef __cplusplus
}                               /* extern C */
#endif                          /* __cplusplus */
#endif
