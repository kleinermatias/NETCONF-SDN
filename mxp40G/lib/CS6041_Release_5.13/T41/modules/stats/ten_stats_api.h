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
 * ten_stats.h
 *
 * $Id: ten_stats_api.h,v 1.7 2013/02/22 20:48:50 jccarlis Exp $
 *
 * This is a PUBLIC header file.
 * It contains defines and APIs for TENABO Statistics.
 *
 */

#ifndef __TEN_STATS_API_H__
#define __TEN_STATS_API_H__

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 *  APIs for Device Statistics
 ******************************************************/
cs_status ten_dev_print_stats(cs_uint16 dev_id);

cs_status ten_dev_print_blk_stats(cs_uint16 dev_id, cs_uint16 block_id);

cs_status ten_dev_print_sect_stats(cs_uint16 dev_id, cs_uint16 block_id, cs_uint16 sect_id);

cs_status ten_dev_print_unit_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                   cs_uint16 sect_id, cs_uint16 unit_id);

cs_status ten_dev_clear_stats(cs_uint16 dev_id);

cs_status ten_dev_clear_dir_stats(cs_uint16 dev_id, cs_dir_t dir);

cs_status ten_dev_clear_blk_stats(cs_uint16 dev_id, cs_uint16 block_id);

cs_status ten_dev_clear_blk_dir_stats(cs_uint16 dev_id, cs_uint16 block_id, cs_dir_t dir);

cs_status ten_dev_clear_sect_stats(cs_uint16 dev_id, cs_uint16 block_id, cs_uint16 sect_id);

cs_status ten_dev_clear_sect_dir_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                       cs_uint16 sect_id, cs_dir_t dir);

cs_status ten_dev_clear_unit_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                   cs_uint16 sect_id, cs_uint16 unit_id);

cs_status ten_dev_clear_unit_dir_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                       cs_uint16 sect_id, cs_uint16 unit_id, cs_dir_t dir);

cs_status ten_dev_get_stats(cs_uint16 dev_id, ten_dev_stats_t *pStats);

cs_status ten_dev_get_blk_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                void *pStats, cs_uint16 len);

cs_status ten_dev_get_sect_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, void *pStats, cs_uint16 len);

cs_status ten_dev_get_unit_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, cs_uint16 unit_id,
                                 cs_dir_t dir,
                                 ten_stats_data_t * pUnit_Stats);

cs_status ten_dev_ctl_blk_stats(cs_uint16 dev_id, cs_uint16 block_id, cs_ctl_t ctl);

cs_status ten_dev_ctl_sect_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, cs_ctl_t ctl);

cs_status ten_dev_ctl_unit_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, cs_uint16 unit_id, cs_ctl_t ctl);

cs_status ten_dev_load_stats(cs_uint16 dev_id, ten_dev_stats_t *pStats);

cs_uint64 ten_dev_read_stat(cs_uint16 dev_id, cs_uint16 block_id,
                            cs_uint16 sect_id, cs_uint16 unit_id, 
                            cs_dir_t dir);

/*******************************************************
 *  APIs for Port Statistics
 *******************************************************/
cs_status ten_mod_print_stats(cs_uint16 module_id);

cs_status ten_mod_print_blk_stats(cs_uint16 module_id, cs_uint16 block_id);

cs_status ten_mod_print_sect_stats(cs_uint16 module_id,
                                    cs_uint16 block_id, cs_uint16 sect_id);

cs_status ten_mod_print_unit_stats(cs_uint16 module_id,
                                    cs_uint16 block_id,
                                    cs_uint16 sect_id, cs_uint16 unit_id);

cs_status ten_mod_clear_stats(cs_uint16 module_id);

cs_status ten_mod_clear_dir_stats(cs_uint16 module_id, cs_dir_t dir);

cs_status ten_mod_clear_blk_stats(cs_uint16 module_id, cs_uint16 block_id);

cs_status ten_mod_clear_blk_dir_stats(cs_uint16 module_id,
                                       cs_uint16 block_id, cs_dir_t dir);

cs_status ten_mod_clear_sect_stats(cs_uint16 module_id,
                                    cs_uint16 block_id, cs_uint16 sect_id);

cs_status ten_mod_clear_sect_dir_stats(cs_uint16 module_id,
                                        cs_uint16 block_id,
                                        cs_uint16 sect_id, cs_dir_t dir);

cs_status ten_mod_clear_unit_stats(cs_uint16 module_id,
                                    cs_uint16 block_id,
                                    cs_uint16 sect_id, cs_uint16 unit_id);

cs_status ten_mod_clear_unit_dir_stats(cs_uint16 module_id,
                                        cs_uint16 block_id,
                                        cs_uint16 sect_id,
                                        cs_uint16 unit_id, cs_dir_t dir);

cs_status ten_mod_get_stats(cs_uint16 module_id, ten_mod_stats_t *pStats);

cs_status ten_mod_get_blk_stats(cs_uint16 module_id, cs_uint16 block_id, 
                                void *pStats, cs_uint16 len);

cs_status ten_mod_get_sect_stats(cs_uint16 module_id, cs_uint16 block_id,
                                  cs_uint16 sect_id, void *pStats, cs_uint16 len);
                                  
cs_status ten_mod_get_sect_dir_stats(cs_uint16 module_id, cs_uint16 block_id,
                                     cs_uint16 sect_id, cs_dir_t dir,
                                     void *pStats, cs_uint16 len);                                  

cs_status ten_mod_get_unit_stats(cs_uint16 module_id, cs_uint16 block_id,
                                  cs_uint16 sect_id, cs_uint16 unit_id,
                                  cs_dir_t dir, 
                                  ten_stats_data_t * pUnit_Stats);

cs_status ten_mod_ctl_blk_stats(cs_uint16 module_id, cs_uint16 block_id, cs_ctl_t ctl);

cs_status ten_mod_ctl_sect_stats(cs_uint16 module_id, cs_uint16 block_id,
                                  cs_uint16 sect_id, cs_ctl_t ctl);

cs_status ten_mod_ctl_unit_stats(cs_uint16 module_id, cs_uint16 block_id,
                                  cs_uint16 sect_id, cs_uint16 unit_id, cs_ctl_t ctl);

cs_status ten_mod_load_stats(cs_uint16 module_id, ten_mod_stats_t *pStats);

cs_uint32 ten_mod_get_private_stats_data_size(cs_uint16 module_id);

cs_status ten_mod_load_private_stats_data(cs_uint16 module_id, cs_char8 *p_buff);

cs_status ten_mod_save_private_stats_data(cs_uint16 module_id, cs_char8 *p_buff);

cs_char8 *ten_get_block_name(cs_uint16 blk_id);

cs_status ten_dev_init_xcon_stats(cs_uint16 dev_id);

cs_status ten_mod_init_syncdsync_stats(cs_uint16 mod_id);
cs_status ten_mod_init_hsif_stats(cs_uint16 mod_id);
cs_status ten_mod_init_gfec_40g_stats(cs_uint16 mod_id);
cs_status ten_mod_init_gfec_10g_stats(cs_uint16 mod_id);
cs_status ten_mod_init_ufec_stats(cs_uint16 mod_id);
cs_status ten_mod_init_n40g_stats(cs_uint16 mod_id);
cs_status ten_mod_init_n10g_stats(cs_uint16 mod_id);
cs_status ten_mod_init_pp40g_stats(cs_uint16 mod_id);
cs_status ten_mod_init_pp10g_stats(cs_uint16 mod_id);

ten_dev_stats_cb_t *TEN_DEV_GET_STATS_CB(cs_uint8 dev_id);
ten_dev_stats_t *TEN_DEV_GET_STATS_PTR(cs_uint16 dev_id);

cs_uint64 ten_mod_read_stat(cs_uint16 mod_id, cs_uint16 block_id,
                            cs_uint16 sect_id, cs_uint16 unit_id, 
                            cs_dir_t dir);
                            
cs_uint16 ten_stats_blk_is_active(cs_uint16 dpid,
                                  ten_dev_or_mod_t dp,
                                  cs_uint16 sect_id,
                                  cs_uint16 unit_id,
                                  cs_uint16 blk_check_id);
#ifdef __cplusplus                                             
}  /* extern C */
#endif

#endif
