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
 * ten_gen_api.h
 *
 * $Id: ten_gen_api.h,v 1.19 2013/02/22 20:48:25 jccarlis Exp $
 *
 * This is a PUBLIC header file.
 * This is the exported header file for this module.
 *
 */

#ifndef __TEN_GEN_API_H__
#define __TEN_GEN_API_H__

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

/*******************************************************
 *                  Driver Externs                     *
 *******************************************************/
cs_status ten_drvr_load(void);
cs_status ten_drvr_unload(void);
cs_status ten_drvr_start_output_to_file(const cs_char8 *fname);
cs_status ten_drvr_stop_output_to_file(void);
void ten_drvr_ctl_stats_hex_format(cs_ctl_t hex_ctl);
void ten_drvr_ctl_stats_mask_zero(cs_ctl_t mask_zero_ctl);
void ten_drvr_ctl_logging(cs_uint16 log_ctl);
void ten_drvr_ctl_esc_code_print(cs_ctl_t ctl);
void ten_drvr_print_ver(void);
void ten_drvr_print_summary(void);
cs_boolean ten_drvr_is_stats_in_hex_fmt(void);
cs_boolean ten_drvr_is_mask_zero_cntr(void);
cs_boolean ten_drvr_is_esc_code_enbld(void);
void ten_drvr_ctl_stats_timing_interval(cs_ctl_t mask_zero_ctl);
void ten_drvr_udelay_hi_res(cs_uint32 usecs);

/*******************************************************
 *                 Device Externs                      *
 *******************************************************/
cs_status ten_dev_register(cs_uint16 dev_id, cs_uint32 base_addr);
cs_status ten_dev_unregister(cs_uint16 dev_id);
cs_status ten_dev_init(cs_uint16 dev_id);
cs_status ten_dev_print_cfg(cs_uint16 dev_id);
cs_status ten_dev_print_status(cs_uint16 dev_id);
cs_status ten_dev_start_ws(cs_uint16 dev_id, ten_ws_method_t method);
cs_status ten_dev_stop_ws(cs_uint16 dev_id);
cs_boolean ten_dev_is_ws_in_progress(cs_uint16 dev_id);
cs_status ten_dev_init_hw(cs_uint16 dev_id);
cs_status ten_dev_restore_cb(cs_uint16 dev_id);
void ten_dev_update_sysclock(cs_uint16 dev_id,
                             cs_uint32 freq);


/* This tool is piggy-backed on Bugzilla 26186, PP40G stats. */
cs_status ten_dev_override_chiptype(cs_uint16 dev_id, cs_uint16 chip); /* use TEN_CHIP_OVERRIDE_T40 or TEN_CHIP_OVERRIDE_T41 */


cs_boolean ten_dev_is_t41(cs_uint16 dev_id);
cs_boolean ten_dev_is_t41_hsif_fix(cs_uint16 dev_id);
cs_boolean ten_dev_is_t41_ptr(ten_dev_cb_t *pdevcb);

/*******************************************************
 *                 Module Externs                      *
 *******************************************************/
cs_uint16 ten_mod_open(cs_uint16 dev_id, cs_uint8 mod_num);
cs_status ten_mod_close(cs_uint16 mod_id);
cs_status ten_mod_init(cs_uint16 mod_id);
cs_status ten_mod_print_cfg(cs_uint16 mod_id);
cs_status ten_mod_print_status(cs_uint16 mod_id);
cs_status ten_dev_main_init(cs_uint16 dev_id);
cs_uint16 ten_mod_main_init(cs_uint16 dev_id, cs_uint8 mod_num);

/*******************************************************
 *                 Debug Externs                       *
 *******************************************************/
void ten_drvr_dump_cb(void);
void ten_dev_dump_cb(cs_uint16 dev_id);
void ten_mod_dump_cb(cs_uint16 module_id);
cs_uint16 ten_reg_read(cs_uint16 dev_id, cs_uint32 reg_offset);
cs_status ten_reg_write(cs_uint16 dev_id, cs_uint32 reg_offset, cs_uint16 data);
cs_uint16 ten_dev_multi_reg_read(cs_uint16 dev_id, 
                                 cs_uint32 write_reg_offset,
                                 cs_uint16 write_reg_val,
                                 cs_uint32 reg_offset1, 
                                 cs_uint32 reg_offset2, 
                                 cs_uint32 reg_offset3,
                                 cs_uint16 repetitions, 
                                 cs_uint16 cr_lf);
cs_uint16 TEN_REG_READ(volatile cs_uint16 *); 
void TEN_REG_WRITE(volatile cs_uint16 *addr, cs_uint16 data);
void ten_reg_dump_range(cs_uint16 dev_id, cs_uint32 start_addr,
                        cs_uint32 end_addr);
void ten_print(const cs_char8 *s);
cs_uint16 ten_drvr_get_last_str_len(void);
cs_int16 ten_drvr_get_last_str_char(void);
void ten_drvr_str_dump(cs_char8 *dbg_str, cs_uint16 str_size);
cs_status TEN_DEV_COMMON_VALIDATE_INTERNAL(cs_uint16 DEV_ID, T41_t **BASE_ADDR);
cs_status TEN_MOD_COMMON_VALIDATE_INTERNAL(cs_uint16 MODULE_ID,  T41_t **BASE_ADDR);
cs_status ten_dev_print_bus_error_info(cs_uint16 dev_id);
cs_uint16 ten_dev_get_bus_error_count(cs_uint16 dev_id);
cs_status ten_dev_clear_bus_error_count(cs_uint16 dev_id);
void ten_debug_reg_write_trace(cs_uint16 dev_id, 
                               cs_uint8  trc_id, 
                               cs_uint32 offset);


/****************************************************************
 * Error handling and logging utility                           *
 * This can be customized as needed by the user.                *
 ****************************************************************/
extern void ten_error_handler(cs_uint32 id, cs_uint32 errCode, cs_char8 *fmt, ...);

/****************************************************************
 ****************************************************************
 *   EXTERNS FOR UTILITIES AND INTERNAL FUNCTIONS               *
 ****************************************************************
 ****************************************************************/
/* DRIVER, DEVICE and PORT Utilities */
cs_boolean ten_dev_is_ws_method_default(cs_uint16 dev_id);
cs_boolean ten_mod_is_ws_in_progress(cs_uint16 mod_id);
void ten_dev_print_header(cs_uint16 dev_id, const cs_char8 *str);
void ten_sim_delay(cs_boolean is_in_msec, cs_uint32 delay);
/* Bugzilla 24139 Start */
void TEN_UDELAY(cs_uint32 usecs);
void TEN_MDELAY(cs_uint32 msecs);
/* Bugzilla 24139 End */
void ten_udelay_hi_res(cs_uint32 usecs);

/* No bugzilla. Release 5.5, delay with optional print supression */
void TEN_UDELAY_PRINT_OPT(cs_uint32 usecs, cs_uint8 print_it);
void TEN_MDELAY_PRINT_OPT(cs_uint32 msecs, cs_uint8 print_it);
/* End No bugzilla. Release 5.5.                                  */
void ten_reset_action(volatile cs_reg *, cs_uint16,cs_reset_action_t);
void ten_clock_disable(volatile cs_reg *, cs_uint16, cs_ctl_t);
int cs_trans_cb_client_dump(cs_char8 *);
cs_boolean TEN_IS_DEVICE_VALID(cs_uint16 dev_id, cs_uint32 * perr_code);
ten_dev_cb_t *TEN_MOD_ID_TO_DEVCB_PTR(cs_uint16 mod_id);
ten_mod_cb_t *TEN_MOD_ID_TO_PCB_PTR(cs_uint16 mod_id);
CS_SEM *ten_get_port_sem_ptr(cs_uint16 mod_id, ten_block_id_t blk_id);
cs_char8 *ten_get_block_name(cs_uint16 blk_id);
CS_SEM *ten_get_dev_sem_ptr(cs_uint16 dev_id, ten_block_id_t blk_id);
cs_boolean TEN_IS_MOD_VALID(cs_uint16 module_id, cs_uint32 * perr_code);
cs_boolean TEN_DRVR_IS_LOADED(void);
ten_dev_cb_t *TEN_DEV_ID_TO_DEVCB_PTR(cs_uint16 dev_id);
void cs_bar(void);
/* For Bugzilla 28734: */
volatile cs_reg *ten_get_frac_div_inst_reg_addr( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_gpllx1_inst_reg_addr  ( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_xfi32x1_inst_reg_addr ( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_GFEC10g_inst_reg_addr ( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_UFEC_inst_reg_addr    ( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_xfi_cupll_inst_reg_addr( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_xcon_es_inst_reg_addr  ( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_xcon_cbert_inst_reg_addr( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_xcon_pbert_inst_reg_addr( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_xcon_sadeco_inst_reg_addr( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_xcon_es_th_lvl_reg_addr  ( cs_reg *pReg, cs_uint16 inst, cs_uint8 level);
volatile cs_reg *ten_get_xcon_es_ps_lvl_reg_addr  ( cs_reg *pReg, cs_uint16 inst, cs_uint8 level);
volatile cs_reg *ten_get_xcon_es_ps_th_sel_reg_addr( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_xfi_cfp32x1_inst_reg_addr ( cs_reg *pReg, cs_uint16 inst);
volatile cs_reg *ten_get_xcon_es_source_sel_reg_addr( cs_reg *pReg, cs_uint16 instance );
volatile cs_reg *ten_get_n40g_reg_addr             ( cs_reg *pReg, cs_uint16 module_id );
volatile cs_reg *ten_get_n10g_reg_addr            ( cs_reg *pReg, cs_uint16 module_id, cs_uint8 slice );
volatile cs_reg *ten_get_pp10g_reg_addr         ( cs_reg *pReg, cs_uint16 module_id, cs_uint8 slice );
volatile cs_reg *ten_get_pp40g_reg_addr        ( cs_reg *pReg, cs_uint16 module_id );


#ifndef __CS_DONT_PRINT__
void CS_PRINT(cs_char8 *fmt, ...);
void CS_PRINT_OUTPUT(cs_char8 *fmt, ...);
void CS_PRINT_ERRORS(cs_char8 *fmt, ...);
void CS_PRINT_DELAYS(cs_char8 *fmt, ...);
#endif

#ifdef __cplusplus
}                               /* extern C */
#endif                          /* __cplusplus */
#endif                          /* __TEN_GEN_API_H__ */
