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
 * ten_debug_api.h 
 *
 * $Id: ten_debug_api.h,v 1.13 2013/02/22 20:42:45 jccarlis Exp $
 *
 * API prototypes for Debug APIs 
 *
 */
 
#ifndef __TEN_DEBUG_API_H__
#define __TEN_DEBUG_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_debug_health(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_debug_dev_dump_settings(cs_uint16 dev_id);
cs_status ten_debug_slice_dump_settings(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_debug_gfec10g_dump_settings(cs_uint16 module_id, cs_uint8 instance);
cs_status ten_debug_gfec40g_dump_settings(cs_uint16 module_id);
cs_status ten_debug_ufec_dump_settings(cs_uint16 module_id, cs_uint8 instance);

cs_status ten_debug_hsif_dump_settings(cs_uint16 module_id);
cs_status ten_debug_hsif_slc0_mr10x4_dump_settings(cs_uint16 module_id);
cs_status ten_debug_hsif_slc1_mr10x5_dump_settings(cs_uint16 module_id);
cs_status ten_debug_hsif_slc2_mr10x4_dump_settings(cs_uint16 module_id);
cs_status ten_debug_hsif_slc3_mr10x5_dump_settings(cs_uint16 module_id);

cs_status ten_debug_mpif_dump_settings(cs_uint16 dev_id);
cs_status ten_debug_glb_dump_settings(cs_uint16 dev_id);
cs_status ten_debug_frac_div_dump_settings(cs_uint16 dev_id);
cs_status ten_debug_gpllx1_dump_settings(cs_uint16 dev_id);
cs_status ten_debug_spoh_dump_settings(cs_uint16 dev_id);
cs_status ten_debug_n10g_dump_settings(cs_uint16 module_id, cs_uint8 slice);
cs_status ten_debug_n10g_oohr_dump_settings(cs_uint16 module_id, cs_uint8 slice);
cs_status ten_debug_n40g_dump_settings(cs_uint16 module_id);
cs_status ten_debug_n40g_oohr_dump_settings(cs_uint16 module_id);
cs_status ten_debug_ohpp_dump_settings(cs_uint16 module_id);
cs_status ten_debug_pp10g_dump_settings(cs_uint16 module_id, cs_uint8 slice);
cs_status ten_debug_syncdsync_dump_settings(cs_uint16 module_id, cs_uint8 slice);
cs_status ten_debug_xcon_dump_settings(cs_uint16 dev_id);
cs_status ten_debug_xfi_dump_settings(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_debug_cfp_dump_settings(cs_uint16 module_id, cs_uint8 slice);
cs_status ten_debug_cupll_dump_settings(cs_uint16 module_id, cs_uint8 slice);
cs_status ten_debug_pp40g_dump_settings(cs_uint16 module_id);
cs_status ten_debug_dm_dump_settings(cs_uint16 dev_id);
cs_status ten_debug_pdcal_dump_settings(cs_uint16 dev_id);

#ifdef __cplusplus
}
#endif
#endif
