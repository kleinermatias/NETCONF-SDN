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
 * ten_stats_data.h
 *
 * $Id: ten_stats_data.h,v 1.10 2013/02/22 20:48:50 jccarlis Exp $
 *
 * It contains enums and data structures for Statistics.
 *
 */
 
#ifndef __TEN_STATS_DATA_H__
#define __TEN_STATS_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

#define TEN_STATS_MAX_SECT          (64)

/************************************************************************
 * STATISTICS OPERATION TYPE
 ************************************************************************/
typedef enum {
  TEN_STATS_GET,
  TEN_STATS_PRINT,
  TEN_STATS_CLEAR
} ten_stats_op_type_t;

/*******************************************************************
 * STATISTICS DATA ( THIS IS ATOMIC ENTITY OF STATS INFRASTRUCTURE )
 *******************************************************************/
typedef struct {
  cs_uint32 tx_ms;                 /* TX MS COUNTER VALUE */
  cs_uint32 tx_ls;                 /* TX LS COUNTER VALUE */
  cs_uint32 rx_ms;                 /* RX MS COUNTER VALUE */
  cs_uint32 rx_ls;                 /* RX LS COUNTER VALUE */
} ten_stats_data_t;

/* Stats structure for XCON block */
typedef struct {
  ten_stats_data_t stats[8][TEN_XCON_MAX_STAT];
} ten_xcon_stats_t;

/* Stats structure for SYNCDSYNC block */
typedef struct {
  ten_stats_data_t stats[4][TEN_SYNCDSYNC_MAX_STAT];
} ten_syncdsync_stats_t;

/* Stats structure for HSIF block */
typedef struct {
  ten_stats_data_t stats_slc0[TEN_HSIF_MR_SLC0_MAX_STAT];
  ten_stats_data_t stats_slc1[TEN_HSIF_MR_SLC1_MAX_STAT];
  ten_stats_data_t stats_slc2[TEN_HSIF_MR_SLC2_MAX_STAT];
  ten_stats_data_t stats_slc3[TEN_HSIF_MR_SLC3_MAX_STAT];
  ten_stats_data_t stats_xfi[TEN_HSIF_XFI_MAX_STAT];
  /* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
  ten_stats_data_t stats_cfp[TEN_HSIF_CFP_MAX_STAT];
} ten_hsif_stats_t;

/* Stats structure for GFEC 40G block */
typedef struct {
  ten_stats_data_t stats[TEN_GFEC40G_MAX_STAT];
} ten_gfec_40g_stats_t;

/* Stats structure for GFEC 10G block */
typedef struct {
  ten_stats_data_t stats[TEN_GFEC10G_COUNT][TEN_GFEC10G_MAX_STAT];
} ten_gfec_10g_stats_t;

/* Stats structure for UFEC block */
typedef struct {
  ten_stats_data_t stats[TEN_UFEC_COUNT][TEN_UFEC_MAX_STAT];
} ten_ufec_stats_t;

/* Stats structure for N40G block */
typedef struct {
  ten_stats_data_t stats[TEN_N40G_MAX_STAT];
} ten_n40g_stats_t;

/* Stats structure for N10G block */
typedef struct {
  ten_stats_data_t stats[4][TEN_N10G_MAX_STAT];
} ten_n10g_stats_t;

/* Stats structure for PP40G block */
typedef struct {
  ten_stats_data_t stats[TEN_PP40G_MAX_STAT];
} ten_pp40g_stats_t;

/* Stats structure for PP10G block */
typedef struct {
  ten_stats_data_t stats[4][TEN_PP10G_MAX_STAT];
} ten_pp10g_stats_t;

/* Bugzilla 26512, cfp stats moved to module stats in the hsif block */

/********************************************
 * DEVICE STATS STRUCTURE
 ********************************************/
typedef struct {
  ten_xcon_stats_t      xcon;
  /* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
} ten_dev_stats_t;

typedef struct {
  ten_syncdsync_stats_t syncdsync;
  ten_hsif_stats_t      hsif;
  ten_gfec_40g_stats_t  gfec_40g;
  ten_gfec_10g_stats_t  gfec_10g;
  ten_ufec_stats_t      ufec;
  ten_n40g_stats_t      n40g;
  ten_n10g_stats_t      n10g;
  ten_pp40g_stats_t     pp40g;
  ten_pp10g_stats_t     pp10g;
} ten_mod_stats_t;

/************************************************************************
 * STATISTICS CONTROL BLOCK
 ************************************************************************/
typedef struct {
  cs_char8 *name;               /* user-friendly cntr name string          */
  cs_uint32 tx_reg_ofst;        /* register offset                         */
  cs_uint32 rx_reg_ofst;        /* register offset                         */
  cs_uint16 num_regs;           /* num of regs make up the cntr            */
  cs_uint8  slice;              /* slice value                             */
  cs_uint32 flags;              /* Flags to characterize the stat          */
  cs_uint16 blk_active_check;   /* check for block active before accessing */
} ten_stats_info_t;

#if 0 /* not needed for T40 */
/* the work area for counters, dynamic allocated to save memory usage    */
/* addition should be at least in 32 bit boundary and bits can be reused */
/* as long as they are exclusive in usage.                               */
typedef struct {
  ten_stats_data_t prev_data;   /* storage for last hw counters */
} ten_stats_work_area_t;
#endif

/************************************************************************
 * STATISTICS SECTION CONTROL BLOCK
 ************************************************************************/
typedef struct {
  cs_char8 *sect_name;          /* Section Name                 */
  cs_boolean enabled;           /* Stats enabled/Disabled state */
  cs_uint8 stride_id;           /* Stride number for addr cal   */
  cs_uint32 stride_size;        /* the size of a stride         */
  cs_uint16 num_entries;        /* Number of counter in section */
  ten_stats_data_t *pStats;     /* Pointer to stats data        */
  cs_boolean *enbl_tbl;         /* Enable/Disable control tbl   */
  const ten_stats_info_t *info_tbl;     /* Info table for counters      */
  /* ten_stats_work_area_t *work_area_tbl; */ /* working area tbl         */
} ten_stats_sect_cb_t;

/************************************************************************
 * STATISTICS BLOCK CONTROL BLOCK AND SPECIAL HANDLER PROTOTYPE
 ************************************************************************/
typedef void (*ten_stats_get_func) (cs_uint16 dpid, cs_uint16 sect_id,
                                    cs_uint16 unit_id, cs_dir_t dir,
                                    cs_boolean sect_context);

typedef void (*ten_stats_print_func) (cs_uint16 dpid, cs_uint16 sect_id,
                                      cs_uint16 unit_id, cs_dir_t dir,
                                      cs_boolean sect_context);

typedef void (*ten_stats_clear_func) (cs_uint16 dpid, cs_uint16 sect_id,
                                      cs_uint16 unit_id, cs_dir_t dir,
                                      cs_boolean sect_context);

typedef struct {
  cs_char8 *blk_name;            /* Block Name                   */
  cs_boolean enabled;           /* Stats enabled/Disable State  */
  cs_uint16 num_sect;           /* Number of sections           */
  ten_stats_sect_cb_t *p_sect_cb[TEN_STATS_MAX_SECT];
  ten_stats_get_func get_func;  /* Special get function pointer */
  ten_stats_print_func print_func;      /* Special Print function ptr   */
  ten_stats_clear_func clear_func;      /* Special clear function ptr   */
} ten_stats_blk_cb_t;

/*************************************************************
 * DEVICE STATS CONTROL BLOCK
 *************************************************************/
typedef struct {
  ten_stats_blk_cb_t *xcon;
  /* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
} ten_dev_stats_cb_t;

/*************************************************************
 * MODULE STATS CONTROL BLOCK
 *************************************************************/
typedef struct {
  ten_stats_blk_cb_t *syncdsync;
  ten_stats_blk_cb_t *hsif;
  ten_stats_blk_cb_t *gfec_40g;
  ten_stats_blk_cb_t *gfec_10g;
  ten_stats_blk_cb_t *ufec;
  ten_stats_blk_cb_t *n40g;
  ten_stats_blk_cb_t *n10g;
  ten_stats_blk_cb_t *pp10g;
  ten_stats_blk_cb_t *pp40g;
} ten_mod_stats_cb_t;

/*************************************************************
 * STRUCTURE TO HOLD SECTION INFO
 *************************************************************/
typedef struct {
  cs_char8 *sect_name;
  cs_uint32 sect_offset;
  cs_uint8 stride_id;
  const ten_stats_info_t *info_tbl;
  cs_uint16 num_unit;
} ten_stats_sect_tbl_entry_t;

enum ten_stats_check_e {
  TEN_STATS_CHECK_NONE             = 0,
  TEN_STATS_CHECK_PP10G_MISC_RESET = 100,
  TEN_STATS_CHECK_PP10G_RX_XGPCS   = 101,
  TEN_STATS_CHECK_PP10G_RX_GFP     = 102,
  TEN_STATS_CHECK_PP10G_RX_BASEX   = 103,
  TEN_STATS_CHECK_PP10G_RX_EGPCS   = 104,
  TEN_STATS_CHECK_PP10G_RX_XCODE   = 105,
  TEN_STATS_CHECK_PP10G_RX_MAC     = 106,
  TEN_STATS_CHECK_PP10G_RX_BYPASS  = 107,
  TEN_STATS_CHECK_PP10G_RX_FC      = 108,
  TEN_STATS_CHECK_PP10G_RX_MON10   = 109,
  TEN_STATS_CHECK_PP10G_RX_BER10B  = 110,
  TEN_STATS_CHECK_PP10G_TX_XGPCS   = 111, 
  TEN_STATS_CHECK_PP10G_TX_GFP     = 112,
  TEN_STATS_CHECK_PP10G_TX_BASEX   = 113,
  TEN_STATS_CHECK_PP10G_TX_EGPCS   = 114,
  TEN_STATS_CHECK_PP10G_TX_XCODE   = 115,
  TEN_STATS_CHECK_PP10G_TX_MAC     = 116,
  TEN_STATS_CHECK_PP10G_TX_BYPASS  = 117,
  TEN_STATS_CHECK_PP40G_MISC_RESET = 200,
  TEN_STATS_CHECK_SYNCDSYNC        = 210,
  TEN_STATS_CHECK_SDS_MR           = 220,
  TEN_STATS_CHECK_SDS_XFI          = 230,
  TEN_STATS_CHECK_GFEC40G          = 240,
  TEN_STATS_CHECK_GFEC10G          = 250,
  TEN_STATS_CHECK_UFEC             = 260,
  TEN_STATS_CHECK_N40G             = 270,
  TEN_STATS_CHECK_N10G             = 280,
  TEN_STATS_CHECK_N10G_SOH         = 290,
  TEN_STATS_CHECK_CFP_MR           = 300,
  TEN_STATS_CHECK_PP40G_PBERT      = 310,
  TEN_STATS_CHECK_MAX
};

#ifdef __cplusplus                                             
}  /* extern C */
#endif

#endif

