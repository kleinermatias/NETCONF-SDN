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

#ifndef __TEN_IRQ_TEST_H__
#define __TEN_IRQ_TEST_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

typedef enum {
    TEN_IRQ_DIR_ONLY,
    TEN_IRQ_DIR_UP,
    TEN_IRQ_DIR_DOWN,
    TEN_IRQ_DIR_BOTH
} ten_irq_tree_dir_t;

cs_status ten_dev_irq_enable (cs_uint16 dev_id, ten_irq_node_ptr node, cs_uint16 enable_bits, ten_irq_tree_dir_t dir);
cs_status ten_dev_irq_disable(cs_uint16 dev_id, ten_irq_node_ptr node, cs_uint16 disable_bits, ten_irq_tree_dir_t dir);
cs_status ten_mod_irq_enable (cs_uint16 module_id, cs_uint8 slice, ten_irq_node_ptr node, cs_uint16 enable_bits, ten_irq_tree_dir_t dir);
cs_status ten_mod_irq_disable(cs_uint16 module_id, cs_uint8 slice, ten_irq_node_ptr node, cs_uint16 disable_bits, ten_irq_tree_dir_t dir);
cs_status ten_irq_isr(cs_uint16 dev_id);
cs_status ten_irq_register_handler(cs_uint16 dev_id, ten_irq_node_ptr node, ten_irq_handler_t handler);
cs_status ten_irq_print_enabled_interrupts(cs_uint16 dev_id);
/* Bugzilla 24021 Start */
void *irq_polling_thread(void *arg);
void ten_sadeco_n40g_deskew_error_handler (ten_irq_handler_data_t handler_data);
cs_status ten_sadeco_n40g_deskew_error_handler_enable (cs_uint16 module_id);
/* Bugzilla 24021 End */
/* Bugzilla 18209 Start */
cs_status ten_dev_irq_clear(cs_uint16 dev_id);
/* Bugzilla 18209 End */
void ten_hl_config_perform_recovery_sequence(ten_irq_handler_data_t handler_data);
void ten_hl_config_perform_cupll_recovery_sequence(ten_irq_handler_data_t handler_data);
cs_status ten_lof_recovery_error_handler_enable (cs_uint16 module_id, cs_uint8  slice);
cs_status ten_dlos_recovery_error_handler_enable (cs_uint16 module_id, cs_uint8  slice);
cs_status ten_pcs_recovery_error_handler_enable (cs_uint16 module_id, cs_uint8  slice);
cs_status ten_holdover_recovery_error_handler_enable (cs_uint16 module_id, cs_uint8  slice);
#ifdef __cplusplus
} /* extern C */
#endif /* __cplusplus */

#endif
