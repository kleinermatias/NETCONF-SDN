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
 * ten_stats_priv.h
 *
 * $Id: ten_stats_priv.h,v 1.5 2013/02/22 20:48:50 jccarlis Exp $
 *
 * This is a PRIVATE header file.
 * It contains defines and APIs for Statistics.
 *
 */

#ifndef __TEN_STATS_PRIV_H__
#define __TEN_STATS_PRIV_H__

#ifdef __cplusplus
extern "C" {
#endif

#define TEN_STATS_FLAG_RX_VALID         (0x00000001)
#define TEN_STATS_FLAG_TX_VALID         (0x00000002)
#define TEN_STATS_FLAG_INDIRECT         (0x00000004)
#define TEN_STATS_FLAG_LSB_FIRST        (0x00000008)

#define TEN_STATS_FLAG_SPL_GET          (0x00000010)
#define TEN_STATS_FLAG_SPL_PRINT        (0x00000020)
#define TEN_STATS_FLAG_SPL_CLEAR        (0x00000040)

#define TEN_STATS_FLAG_PROTECT_RX       (0x00000100)
#define TEN_STATS_FLAG_PROTECT_TX       (0x00000200)

/* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
#define TEN_STATS_MODULE_A_ONLY         (0x00000400)    /* This stat can only be for module A */
#define TEN_STATS_MODULE_B_ONLY         (0x00000800)    /* This stat can only be for module B */
#define TEN_STATS_MODULE_PROTECTION     (0x00000C00)    /* This stat is normally for module A or B but should follow module protection */
#define TEN_STATS_MODULE_SPECIAL        (0x00000C00)    /* Flag to check to see if special handling is necessary based on module id */

#define TEN_STATS_FLAG_RX_READ_CLR      (0x00001000)
#define TEN_STATS_FLAG_TX_READ_CLR      (0x00002000)

/* NO_CLR hw counters can't be cleared and will roll over automatically */
#define TEN_STATS_FLAG_NO_CLR_RX        (0x00004000)
#define TEN_STATS_FLAG_NO_CLR_TX        (0x00008000)

#define TEN_STATS_FLAG_NO_ACCUM         (0x00010000)
#define TEN_STATS_FLAG_TIMING_INTERVAL  (0x00020000)

#define TEN_STATS_FLAG_NEXT_UNIT_TIE    (0x10000000)
#define TEN_STATS_FLAG_LAST_UNIT_TIE    (0x20000000)

#define TEN_STATS_FLAG_TX_RX_VALID      (TEN_STATS_FLAG_RX_VALID    |   \
                                         TEN_STATS_FLAG_TX_VALID    )

#define TEN_STATS_FLAG_TX_RX_READ_CLR   (TEN_STATS_FLAG_RX_READ_CLR |   \
                                         TEN_STATS_FLAG_TX_READ_CLR )

#define TEN_STATS_FLAG_NO_CLR_TX_RX     (TEN_STATS_FLAG_NO_CLR_RX   |   \
                                         TEN_STATS_FLAG_NO_CLR_TX   )

#define TEN_STATS_FLAG_PROTECT_TX_RX    (TEN_STATS_FLAG_PROTECT_RX  |   \
                                         TEN_STATS_FLAG_PROTECT_TX  )

/************************************************************************
 * Macro for determining if RX is valid
 ************************************************************************/
#define TEN_STATS_UNIT_IS_RX_VALID(FLAG)  ((FLAG) & TEN_STATS_FLAG_RX_VALID)

/************************************************************************
 * Macro for determining if TX is valid
 ***********************************************************************/
#define TEN_STATS_UNIT_IS_TX_VALID(FLAG)  ((FLAG) & TEN_STATS_FLAG_TX_VALID)

/************************************************************************
 * Macro for determining if TEN_STATS_FLAG_NEXT_UNIT_TIE is valid
 ************************************************************************/
#define TEN_STATS_UNIT_IS_NEXT_TIE(FLAG)  ((FLAG) & TEN_STATS_FLAG_NEXT_UNIT_TIE)

/************************************************************************
 * Macro for determining if TEN_STATS_FLAG_LAST_UNIT_TIE is valid
 ************************************************************************/
#define TEN_STATS_UNIT_IS_LAST_TIE(FLAG)  ((FLAG) & TEN_STATS_FLAG_LAST_UNIT_TIE)

/*********************************************************************
 * Macro for determining if the block is registered
 *********************************************************************/
#define TEN_STATS_IS_BLK_REGISTERED(DPID, DP, MODID)      \
        ( (ten_stats_get_blk_cb((DPID), (DP), (MODID))) ? TRUE : FALSE )

/************************************************************************
 * Macro for determining if there is another unit is tied with itself
 ************************************************************************/
#define TEN_STATS_UNIT_IS_TIE_VALID(FLAG)                 \
                    ((TEN_STATS_UNIT_IS_NEXT_TIE(FLAG))   \
                    ||(TEN_STATS_UNIT_IS_LAST_TIE(FLAG)))

/************************************************************************
 * Macro to convert 64bit data into 32bit data to support the OS with
 * 32bit-only printing capability without losing precisions
 ************************************************************************/
#define TEN_STATS_GET_BILLIONS_DEC(CNTS)     \
                    ((cs_uint32)((CNTS)/1000000000))
#define TEN_STATS_GET_BILLIONS_MOD_DEC(CNTS) \
                    ((cs_uint32)((CNTS)%1000000000))

/************************************************************************
 * Macro to get the RX and TX registers address
 ************************************************************************/
#define TEN_STATS_GET_RX_REG_ADDR(BASEADDR, SLICE, SLICE_SIZE, P_INFO) \
            (((cs_uint32)(BASEADDR)) + ((SLICE) * SLICE_SIZE) +        \
             ((P_INFO)->rx_reg_ofst))

#define TEN_STATS_GET_TX_REG_ADDR(BASEADDR, SLICE, SLICE_SIZE, P_INFO) \
            (((cs_uint32)(BASEADDR)) + ((SLICE) * SLICE_SIZE) +        \
             ((P_INFO)->tx_reg_ofst))

/***************************************************************
 ***************  OTHER GENERAL MACROS AND UTILITIES ***********
 ***************************************************************/
#define TEN_OFST(s_t, m)                 ((cs_uint32) (&(((s_t *)0)->m)))

#define XFI32X1_SLICE_STRIDE             0x400

#define TEN_SYNCDSYNCRX_REG_OFST(r, s)   (TEN_OFST(T41_t, SYNCDSYNCRX)) + \
                                         (TEN_OFST(TEN_SYNCDSYNCRX_t, r)) + \
                                         (s * TEN_SYNCDSYNCRX_STRIDE * sizeof(cs_reg))

#define TEN_SYNCDSYNCTX_REG_OFST(r, s)   (TEN_OFST(T41_t, SYNCDSYNCTX)) + \
                                         (TEN_OFST(TEN_SYNCDSYNCTX_t, r)) + \
                                         (s * TEN_SYNCDSYNCTX_STRIDE * sizeof(cs_reg))

#define TEN_HSIF_MR10X4_SLC0_REG_OFST(r) (TEN_OFST(T41_t, HSIF.HSIF_mr_slc0.HSIF_mr_slc0_mr10x4_sds)) + \
                                         (TEN_OFST(TEN_HSIF_mr_slc0_mr10x4_sds_t, r))

#define TEN_HSIF_MR10X5_SLC1_REG_OFST(r) (TEN_OFST(T41_t, HSIF.HSIF_mr_slc1.HSIF_mr_slc1_mr10x5_sds)) + \
                                         (TEN_OFST(TEN_HSIF_mr_slc1_mr10x5_sds_t, r))
                                        
#define TEN_HSIF_MR10X4_SLC2_REG_OFST(r) (TEN_OFST(T41_t, HSIF.HSIF_mr_slc2.HSIF_mr_slc2_mr10x4_sds)) + \
                                         (TEN_OFST(TEN_HSIF_mr_slc2_mr10x4_sds_t, r))

#define TEN_HSIF_MR10X5_SLC3_REG_OFST(r) (TEN_OFST(T41_t, HSIF.HSIF_mr_slc3.HSIF_mr_slc3_mr10x5_sds)) + \
                                         (TEN_OFST(TEN_HSIF_mr_slc3_mr10x5_sds_t, r))

/* Bugzilla #19870, XFI counter offset */
#define TEN_HSIF_XFI32X1_REG_OFST(r, s)  (TEN_OFST(T41_t, xfi32x1_sds)) + \
                                         (TEN_OFST(TEN_xfi32x1_sds_t, r)) + \
                                         (s * XFI32X1_SLICE_STRIDE * sizeof(cs_reg))
                                         
#define TEN_XCON_PBERT_REG_OFST(r,s )    (TEN_OFST(T41_t, XCON)) + (TEN_OFST(TEN_XCON_t, r)) + \
                                         (s * TEN_XCON_PBERT_RX_STRIDE * sizeof(cs_reg))

#define TEN_XCON_ES_REG_OFST(r, s)       (TEN_OFST(T41_t, XCON.XCON_es)) + \
                                         (TEN_OFST(TEN_XCON_es_t, r)) + \
                                         (s * TEN_XCON_ES_STRIDE * sizeof(cs_reg))

#define TEN_XCON_CBERT_REG_OFST(r, s)    (TEN_OFST(T41_t, XCON.XCON_cbert)) + \
                                         (TEN_OFST(TEN_XCON_cbert_t, r)) + \
                                         (s * TEN_XCON_CBERT_STRIDE * sizeof(cs_reg))

#define TEN_GFEC40G_REG_OFST(r)          (TEN_OFST(T41_t, GFEC40g)) + (TEN_OFST(TEN_GFEC40g_t, r))

#define TEN_GFEC10G_REG_OFST(r, s)       (TEN_OFST(T41_t, GFEC10g)) + (TEN_OFST(TEN_GFEC10g_t, r)) + \
                                         (s * TEN_GFEC10G_STRIDE * sizeof(cs_reg))

#define TEN_UFEC_REG_OFST(r, s)          (TEN_OFST(T41_t, UFEC)) + (TEN_OFST(TEN_UFEC_t, r)) + \
                                         (s * TEN_UFEC_STRIDE * sizeof(cs_reg))

#define TEN_N40G_REG_OFST(r)             (TEN_OFST(T41_t, n40g)) + (TEN_OFST(TEN_n40g_t, r))
#define TEN_N40G_SDFR_REG_OFST(r)        (TEN_OFST(T41_t, n40g.n40g_sdfr)) + (TEN_OFST(TEN_n40g_sdfr_t, r))
#define TEN_N40G_OOHR_REG_OFST(r)        (TEN_OFST(T41_t, n40g.n40g_oohr)) + (TEN_OFST(TEN_n40g_oohr_t, r))

#define TEN_N10G_REG_OFST(r, s)          (TEN_OFST(T41_t, n10g)) + (TEN_OFST(TEN_n10g_t, r)) + \
                                         (s * TEN_N10G_STRIDE * sizeof(cs_reg))
                                         
#define TEN_N10G_SDFR_REG_OFST(r, s)     (TEN_OFST(T41_t, n10g.n10g_sdfr)) + \
                                         (TEN_OFST(TEN_n10g_sdfr_t, r)) + \
                                         (s * TEN_N10G_STRIDE * sizeof(cs_reg))

#define TEN_N10G_OOHR_REG_OFST(r, s)     (TEN_OFST(T41_t, n10g.n10g_oohr)) + \
                                         (TEN_OFST(TEN_n10g_oohr_t, r)) + \
                                         (s * TEN_N10G_STRIDE * sizeof(cs_reg))

#define TEN_PP40G_REG_OFST(r)            (TEN_OFST(T41_t, pp40g)) + (TEN_OFST(TEN_pp40g_t, r))

#define TEN_CFP32X1_REG_OFST(r,s)        (TEN_OFST(T41_t, cfp32x1_sds)) + (TEN_OFST(TEN_cfp32x1_sds_t, r)) + \
                                         (s * TEN_CFP32X1_SDS_STRIDE * sizeof(cs_reg))


/************************************************************************
 * Externs
 ************************************************************************/
extern const ten_stats_info_t stats_table_xcon_0[];
extern const ten_stats_info_t stats_table_xcon_1[];
extern const ten_stats_info_t stats_table_xcon_2[];
extern const ten_stats_info_t stats_table_xcon_3[];
extern const ten_stats_info_t stats_table_xcon_4[];
extern const ten_stats_info_t stats_table_xcon_5[];
extern const ten_stats_info_t stats_table_xcon_6[];
extern const ten_stats_info_t stats_table_xcon_7[];

extern const ten_stats_info_t stats_table_syncdsync_0[];
extern const ten_stats_info_t stats_table_syncdsync_1[];
extern const ten_stats_info_t stats_table_syncdsync_2[];
extern const ten_stats_info_t stats_table_syncdsync_3[];

extern const ten_stats_info_t stats_table_hsif_slc0[];
extern const ten_stats_info_t stats_table_hsif_slc1[];
extern const ten_stats_info_t stats_table_hsif_slc2[];
extern const ten_stats_info_t stats_table_hsif_slc3[];
extern const ten_stats_info_t stats_table_hsif_xfi[];
extern const ten_stats_info_t stats_table_hsif_cfp[];

extern const ten_stats_info_t stats_table_gfec40g[];

extern const ten_stats_info_t stats_table_gfec10g_0[];
extern const ten_stats_info_t stats_table_gfec10g_1[];
extern const ten_stats_info_t stats_table_gfec10g_2[];

extern const ten_stats_info_t stats_table_ufec_0[];
extern const ten_stats_info_t stats_table_ufec_1[];
extern const ten_stats_info_t stats_table_ufec_2[];
extern const ten_stats_info_t stats_table_ufec_3[];

extern const ten_stats_info_t stats_table_n40g[];

extern const ten_stats_info_t stats_table_n10g_0[];
extern const ten_stats_info_t stats_table_n10g_1[];
extern const ten_stats_info_t stats_table_n10g_2[];
extern const ten_stats_info_t stats_table_n10g_3[];

extern const ten_stats_info_t stats_table_pp40g[];

extern const ten_stats_info_t stats_table_pp10g_0[];
extern const ten_stats_info_t stats_table_pp10g_1[];
extern const ten_stats_info_t stats_table_pp10g_2[];
extern const ten_stats_info_t stats_table_pp10g_3[];

/* Bugzilla 26512, cfp stats moved to module stats in the hsif block */

/************************************************************************
 * APIs
 ************************************************************************/
ten_stats_blk_cb_t *ten_stats_register_blk_cb(cs_uint16 dpid,
                                              ten_dev_or_mod_t dp,
                                              cs_uint16 blk_id,
                                              cs_boolean ctl_enabled,
                                              ten_stats_get_func pGet_func,
                                              ten_stats_print_func pPrint_func,
                                              ten_stats_clear_func pClear_func);

cs_status ten_stats_deregister_blk_cb(cs_uint16 dpid,
                                      ten_dev_or_mod_t dp, cs_uint16 blk_id);

cs_status ten_stats_clean_all(cs_uint16 dpid, ten_dev_or_mod_t dp);

cs_status ten_stats_add_sect_tbl_entry(cs_uint16 dpid,
                                       ten_dev_or_mod_t dp,
                                       cs_uint16 blk_id,
                                       cs_char8 *sect_name,
                                       cs_uint16 sect_id,
                                       cs_uint8 stride_id,
                                       cs_uint32 stride_size,
                                       cs_boolean ctl_enabled,
                                       cs_uint16 num_child,
                                       ten_stats_data_t *p_data,
                                       const ten_stats_info_t *p_info_tbl);

cs_status ten_stats_remove_sect_tbl_entry(cs_uint16 dpid,
                                          ten_dev_or_mod_t dp,
                                          cs_uint16 blk_id, cs_uint16 sect_id);

cs_status ten_stats_sect_cmn_op(cs_uint16 dpid,
                                ten_dev_or_mod_t dp,
                                cs_uint16 blk_id,
                                cs_uint16 sect_id,
                                ten_stats_sect_cb_t *stats_sect_cb,
                                ten_stats_op_type_t op, cs_dir_t dir);

cs_status ten_stats_unit_cmn_op(cs_uint16 dpid,
                                ten_dev_or_mod_t dp,
                                cs_uint16 blk_id,
                                cs_uint16 sect_id,
                                cs_uint16 unit_id,
                                ten_stats_sect_cb_t *sect_cb,
                                ten_stats_op_type_t op,
                                cs_dir_t dir, cs_boolean sect_context);

ten_stats_blk_cb_t *ten_stats_get_blk_cb(cs_uint16 dpid,
                                         ten_dev_or_mod_t dp, cs_uint16 blk_id);

void ten_stats_print_blk_hdr(cs_uint16 dpid, ten_dev_or_mod_t dp, cs_char8 *blk_name);

void ten_stats_print_sect_hdr(cs_uint16 dpid, ten_dev_or_mod_t dp, cs_char8 *name);

void ten_stats_print_unit_cntr(const cs_char8 *name, cs_uint32 flags,
                               ten_stats_data_t *p_data);

void ten_set_sect_print_flag(cs_uint32 val);

cs_uint32 ten_get_sect_print_flag(void);

cs_uint16 ten_stats_get_private_data_size(cs_uint16 dpid, ten_dev_or_mod_t dp);

cs_status ten_stats_load_private_data(cs_uint16 dpid, ten_dev_or_mod_t dp, cs_char8 *p_buff);

cs_status ten_stats_save_private_data(cs_uint16 dpid, ten_dev_or_mod_t dp, cs_char8 *p_buff);

#ifdef __cplusplus                                             
}  /* extern C */
#endif

#endif /* __TEN_STATS_PRIV_H__ */
