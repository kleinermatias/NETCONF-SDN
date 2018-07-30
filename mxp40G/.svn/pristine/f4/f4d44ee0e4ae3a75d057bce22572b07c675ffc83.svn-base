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
 * ten_gen_data.h
 *
 * $Id: ten_gen_data.h,v 1.85 2013/11/27 19:27:28 jccarlis Exp $
 *
 * This is a PUBLIC header file.
 * This is the exported header file for this module.
 *
 */

#ifndef __TEN_GEN_DATA_H__
#define __TEN_GEN_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

#define TEN_INVALID_MODULE_ID       (0xFFFF)
#define TEN_MAX_NUM_DEVICES         (16)        /* can be bumped up to 256 */
#define TEN_ALL_INSTANCES           (0xFF)

/***************************************************************************/
/* Modify TEN_DRVR_UDELAY_MIN when tighter timing intervals are necessary. */
/* Modify with care, CS tests with TEN_DRVR_UDELAY_MIN as 6000.            */
/*                                                                         */
/* This is the minimum useful timer setting available to TEN_UDELAY(),     */
/* which is dependent on the driver environment. Smaller values passed to  */
/* TEN_UDELAY(), whether directly or via TEN_MDELAY(), are forced up to    */
/* TEN_DRVR_UDELAY_MIN. Setting TEN_DRVR_UDELAY_MIN to a lower value, if   */
/* supported in the driver environment, allows the driver to specify       */
/* smaller timers as desired for tighter timing constraints.               */
/*                                                                         */
/* Driver functions should not use TEN_DRVR_UDELAY_MIN when calling TEN_   */
/* UDELAY() or TEN_MDELAY(). The smallest desired parameter should be      */
/* passed. This allows tighter constraints to be enabled by explicitly     */
/* modifying TEN_DRVR_UDELAY_MIN.                        Bugzilla #30990.  */
/***************************************************************************/
#define TEN_DRVR_UDELAY_MIN         (6000)              /* in microseconds */
#define TEN_DRVR_MDELAY_MIN  (TEN_DRVR_UDELAY_MIN/1000) /* in milliseconds */

/* T41 literal definitions */ /* Bugzilla 26156, identify T41 */
#define TEN_CHIP_ID_CS6041          (0x200913e5)    /* T41 dev id = 9 */
#define TEN_CHIP_ID_CS6044          (0x100943e5)
#define TEN_CHIP_ID_MAN_MASK        (0x0FFE) /* LS WORD ONLY. Leaves manufacturer ID, masks out SKU ID and lsbit   */
#define TEN_CHIP_ID_DEV_MASK        (0x0FFF) /* MS WORD ONLY. Leaves DEV_ID, masks out revision code */
#define TEN_CHIP_ID_MASK            ((TEN_CHIP_ID_DEV_MASK << 16) | TEN_CHIP_ID_MAN_MASK) /* test manufacturer ID and device id */

/* T40 literal definitions */
#define TEN_CHIP_ID_CS6001          (0x100813e5) /* for now, good for skus 1,2,3,5, and 70xx */
#define TEN_CHIP_ID_CS6004          (0x100843e5) /* for now, 60x4 is the only special sku */
#define TEN_CHIP_ID_MSB_T40_dft     (0x1008)   /* replaces TEN_MPIF_CHIP_ID_MSB_dft for T40 */ 

#define TEN_REG_ADDR_UNUSED 0xFFFFFFFF

/* valid chip types */
typedef enum {
  TEN_CHIP_T40 = 0,                /* chip is a T40 */
  TEN_CHIP_T41 = 1                 /* chip is a T41 */
/* This tool is piggy-backed on Bugzilla 26186, PP40G stats. */
, TEN_CHIP_OVERRIDE_DEF  = 0x000,   /* use actual registered chip type */
  TEN_CHIP_OVERRIDE_T40  = 0x080,   /* 1000 0000 */
  TEN_CHIP_OVERRIDE_T41  = 0x0C0,   /* 1100 0000 */
  TEN_CHIP_OVERRIDE_MASK = 0xFF3F
} cs_chip_t4n_t;


typedef enum {
  TEN_T41_REV_ID_1 = 1,
  TEN_T41_REV_ID_2 = 2
} cs_chip_t41_rev_id_t;

enum ten_dev_id_code_sku_enums {
  TEN_DEV_ID_CODE_SKU_CS6041 = 1,
  TEN_DEV_ID_CODE_SKU_CS6042 = 2,
  TEN_DEV_ID_CODE_SKU_CS6043 = 3,
  TEN_DEV_ID_CODE_SKU_CS6045 = 5,
  TEN_DEV_ID_CODE_SKU_CS6046 = 6,
  TEN_DEV_ID_CODE_SKU_CS6048 = 8,
  TEN_DEV_ID_CODE_SKU_CS6049 = 7
};

typedef enum {
  TEN_MODULE_A = 0,
  TEN_MODULE_B = 1,
  TEN_MODULE_A_AND_B = 2,
  TEN_MODULE_NULL    = 0xFF
} cs_module_t;

typedef enum {
  TEN_SLICE0 = 0,
  TEN_SLICE1 = 1,
  TEN_SLICE2 = 2,
  TEN_SLICE3 = 3,
  TEN_MAX_SLICES = 4,
  TEN_SLICE_ALL = 0xFF
} ten_slice_id_t;

enum ten_slice_bitmasks_e {
  TEN_SLICE0_BITMASK = 0x01,
  TEN_SLICE1_BITMASK = 0x02,
  TEN_SLICE2_BITMASK = 0x04,
  TEN_SLICE3_BITMASK = 0x08
};

typedef enum {
  TEN_SLICE_10G,
  TEN_SLICE_40G
} ten_slice_mode_t;

typedef enum {
  TEN_WS_METHOD_TOP_DOWN,     /* Restore hardware from system memory */
  TEN_WS_METHOD_BOTTOM_UP     /* Restore system memory from hardware */
} ten_ws_method_t;

typedef enum {
  TEN_ID_MPIF       = 0,
  TEN_ID_GLB        = 1,
  TEN_ID_XCON       = 2,
  TEN_ID_SYNCDSYNC  = 3,
  TEN_ID_GPLLX1     = 4,
  TEN_ID_SPOH       = 5,
  TEN_ID_HSIF       = 6,
  TEN_ID_XFI32X1    = 7,
  TEN_ID_GFEC_40G   = 8,
  TEN_ID_GFEC_10G   = 9,
  TEN_ID_UFEC       = 10,
  TEN_ID_N40G       = 11,
  TEN_ID_OHPP       = 12,
  TEN_ID_N10G       = 13,
  TEN_ID_PP10G      = 14,
  TEN_ID_IRQ        = 15,
  TEN_ID_FRACDIV    = 16,
  TEN_ID_PP40G      = 17,
  TEN_ID_CFP32X1      = 18,
  TEN_ID_SYNCDSYNC_CB = 19,
  TEN_ID_PDCAL        = 20,
  TEN_ID_DM           = 21

} ten_block_id_t;

typedef enum {
  TEN_DEVICE = 0,
  TEN_MOD = 1
} ten_dev_or_mod_t;

#define TEN_INVALID_MODULE_NUM  (0xFF)
#define TEN_MAX_NUM_MODULES        (2)
#define TEN_INSTANCE_ALL        (0xFF)
#define TEN_HRESET_MSEC_DELAY     (20)
#define TEN_DEBUG_BUFFER_SIZE    (512)

#define TEN_MAX_TTI_SIZE          (64) 
#define TEN_OOHR_MAX_NUM_LAYERS    (8)

/*************************************************************
 ************     MOD CONTROL BLOCK (mod_cb)  ****************
 *************************************************************/
/* Module states */
#define  TEN_MOD_STATE_INVALID         (0)     /* Pwron reset default */
#define  TEN_MOD_STATE_OPENED          (1)
#define  TEN_MOD_STATE_DATA_INIT_DONE  (2)     /* data structs init'ed */
#define  TEN_MOD_STATE_HW_INIT_DONE    (3)     /* hw cfg done */

typedef struct {
  cs_uint16 mod_id;
  cs_uint32 state;
  CS_SEM sem_syncdsync;
  CS_SEM sem_spoh;
  CS_SEM sem_hsif;
  CS_SEM sem_xfi32x1;
  CS_SEM sem_n40g;
  CS_SEM sem_ohpp;
  CS_SEM sem_n10g;
  CS_SEM sem_pp10g;
  CS_SEM sem_pp40g;
  CS_SEM sem_gfec10g;
  CS_SEM sem_gfec40g;
  CS_SEM sem_ufec;
  CS_SEM sem_cfp32x1;
  ten_mod_stats_cb_t stats_cb;
  ten_mod_stats_t stats;
  cs_uint16 ten_shadow_sfc_ram_0 [TEN_OHPP_SFC_RAM_COUNT];
  cs_uint16 ten_shadow_sfc_ram_1 [TEN_OHPP_SFC_RAM_COUNT];
  cs_uint16 ten_shadow_sfc_ram_active; /* FALSE is for bank 0, TRUE for bank 1 */
  cs_char8 inserted_tti_10g[TEN_MAX_SLICES][TEN_OOHR_MAX_NUM_LAYERS][TEN_MAX_TTI_SIZE];
  cs_char8 expected_tti_10g[TEN_MAX_SLICES][TEN_OOHR_MAX_NUM_LAYERS][TEN_MAX_TTI_SIZE];
} ten_mod_cb_t;

 /* Bug #41675: Save/Restore HSIF_PROTOCOL_PSWTCH_OK_CTRL during FAR END loopback */ 
#define TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM_5100 (5100)
#define TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM_5110 (5110)
#define TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM_5120 (5120)
#define TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM (5120)
typedef struct {
  cs_uint16 save_xfi32x1_stxp0_tx_lptime_sel[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_xfi32x1_stxp0_tx_clkdiv_ctrl[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  /* #36075: TEN_HSIF_LOOPBACK_FACILITY_XFI fails with 4/2 GFC when using CUPLL */
  cs_uint16 save_xfi32x1_stxp0_tx_spare_refclk_div_sel[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  
  cs_uint16 save_cfp32x1_stxp0_tx_lptime_sel[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_cfp32x1_stxp0_tx_clkdiv_ctrl[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_hsif_set_refclk_cfg[TEN_MAX_NUM_MODULES];

  cs_uint16 save_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MAX_NUM_MODULES];
  cs_uint16 save_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel[TEN_MAX_NUM_MODULES];
  cs_uint16 save_hsif_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MAX_NUM_MODULES];
  cs_uint16 save_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_lptime_sel[TEN_MAX_NUM_MODULES];
  cs_uint16 save_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MAX_NUM_MODULES];
  cs_uint16 save_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel[TEN_MAX_NUM_MODULES];
  cs_uint16 save_hsif_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MAX_NUM_MODULES];
  cs_uint16 save_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_lptime_sel[TEN_MAX_NUM_MODULES];

  cs_uint16 save_hsif_set_ok_ctrl_xlos_en[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_hsif_set_ok_ctrl_lock_en[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_hsif_set_ok_ctrl_datadet_en[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_hsif_set_ok_ctrl_synced_en[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];

  cs_uint16 save_xfi32x1_bit_invert[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_cfp32x1_bit_invert[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];

  cs_uint16 save_hsif_slc0_mr10x4_sds_common_rxlockd0_control[TEN_MAX_NUM_MODULES];
  cs_uint16 save_hsif_slc1_mr10x5_sds_common_rxlockd0_control[TEN_MAX_NUM_MODULES];
  cs_uint16 save_hsif_slc2_mr10x4_sds_common_rxlockd0_control[TEN_MAX_NUM_MODULES];
  cs_uint16 save_hsif_slc3_mr10x5_sds_common_rxlockd0_control[TEN_MAX_NUM_MODULES];
  
  cs_uint16 save_xfi_rxlockd0_control[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_cfp_rxlockd0_control[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  
  cs_uint16 save_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];

  /* Bugzilla #26282: Loopback High-level API needs to disable all clock protection */
  cs_uint16 save_mpif_clock_switch_xlos_mr_tx[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_mpif_clock_switch_xlos_mr_rx[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];

  cs_uint16 save_mpif_clock_switch_xlos_xfi_tx[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_mpif_clock_switch_xlos_xfi_rx[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
                                     
  cs_uint16 save_mpif_clock_switch_lockdet_mr_tx[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_mpif_clock_switch_lockdet_mr_rx[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
                                      
  cs_uint16 save_mpif_clock_switch_lockdet_xfi_tx[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_mpif_clock_switch_lockdet_xfi_rx[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];

  cs_uint16 save_mpif_clock_switch_tx_cbrgenais_10g[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];

  cs_uint16 save_mpif_clock_switch_tx_cbrgenais_40g[TEN_MAX_NUM_MODULES];

  cs_uint16 save_mpif_clock_switch_tx_pn11_10g[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
                                        
  cs_uint16 save_mpif_clock_switch_tx_pn11_40g[TEN_MAX_NUM_MODULES];

  cs_uint16 save_mpif_clock_switch_tx_ms_10g[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];

  cs_uint16 save_mpif_clock_switch_tx_ms_40g[TEN_MAX_NUM_MODULES];

  cs_uint16 save_mpif_clock_switch_tx_msais[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];

  /* Bug #41675: Save/Restore HSIF_PROTOCOL_PSWTCH_OK_CTRL during FAR END loopback */ 
  cs_uint16 save_hsif_pswtch_ok_ctrl_xlos_en[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_hsif_pswtch_ok_ctrl_lock_en[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_hsif_pswtch_ok_ctrl_datadet_en[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  cs_uint16 save_hsif_pswtch_ok_ctrl_synced_en[TEN_MAX_NUM_MODULES][TEN_MAX_SLICES];
  
} ten_hsif_loopback_settings_t;

/*************************************************************
 ************  XCON ELASTIC STORE CONTROL BLOCK  *************
 *************************************************************/
typedef struct {
  /* Recenter parameters */
  struct {
    cs_uint16 type;              /* enumerated in ten_xcon_recenter_type_t */ 
    cs_uint16 recovery;          /* Rls 5.5: enumerated in ten_xcon_recenter_recovery_t */
    union {
      struct {
        cs_uint16 circuit_threshold_lower;    /* 0-0x1fff, only required for recentering on frame pulse alignment */
        cs_uint16 circuit_threshold_upper;    /* 0-0x1fff, only required for recentering on frame pulse alignment */
        cs_uint16 static_depth;
      } fpa;                    /* Use this when recentering type is FPA_10G or _40G */
      struct {
        cs_uint16 margin_lower;
        cs_uint16 margin_upper;
        cs_uint16 correct_lower;
        cs_uint16 correct_upper;
        cs_uint8  duration;
        cs_uint32 sysclk_freq;
      } amp;                    /* Use this when recentering type is AMP_10G or _40G */
    } parms;
  } recenter;
} ten_xcon_es_cb_t;

/*************************************************************
 *************    DEVICE CONTROL BLOCK (dev_cb)   ************
 *************************************************************/
#define  TEN_DEV_STATE_INVALID      0  /* Device not registered yet */
#define  TEN_DEV_STATE_REGISTERED   1  /* Device has been registered */
#define  TEN_DEV_STATE_INITIALIZED  2  /* Device has been registered and initialized */

typedef struct {
  cs_boolean enbl;
  ten_ws_method_t method;
} ten_ws_cb_t;

typedef struct {
 cs_uint8 enbl;
 cs_uint8 client_slice;
 cs_uint8 line_slice;
} ten_oduflex_cb_t;

typedef struct {
  cs_int16 num_just_oxu2;
  cs_uint8 num_pjo_oxu2;
  cs_int16 num_just_oxu3;
  cs_uint8 num_pjo_oxu3;
  cs_int16 num_just_oxu3_client;   /* Bugzilla 26729*/
  cs_uint8 num_pjo_oxu3_client;    /* Bugzilla 26729*/
  cs_uint16 P_line;
  cs_uint16 Q_line;
  cs_uint16 P_client;
  cs_uint16 Q_client;
  cs_uint8 line_client_same;
  cs_uint8 line_client_rate_equal;
  cs_uint16 transcode_num;
  cs_uint16 transcode_denom;
  /* T41 additions */
  cs_uint8 client_map_proc;
  cs_uint8 line_map_proc;
  double client_rate;
  double xcon_client_rate;
  double line_rate; 
  cs_uint32 cn_bytes_n10g;  /*Bugzilla 26308*/
  cs_uint32 cn_bytes_n40g;  /*Bugzilla 26308*/
  /* Bug 23864: need hysteresis field for deterministic justification calculations */
  cs_uint32 hysteresis;
  cs_uint8  ad2_constant;   /*Bugzilla 41096*/
  cs_uint8  multi_frames;   /*Bugzilla 41096*/
} ten_syncdsync_cb_t;

/* Bugzilla 24339 Start */
/* Enums for 10G/40G GFEC on Slice 0 */
/* Bugzilla #27953, fix compiler warnings, no trailing comma on enums */
typedef enum {
  TEN_10G_40G_GFEC_DISABLED,
  TEN_10G_40G_GFEC_10G_MODE,
  TEN_10G_40G_GFEC_40G_MODE
} ten_10g_40g_gfec_t;

/* Enums for 10G GFEC on Slice 1, 2 and 3 */
typedef enum {
  TEN_10G_GFEC_DISABLED,
  TEN_10G_GFEC_MODULE_A,
  TEN_10G_GFEC_MODULE_B
} ten_10g_gfec_t;

typedef enum {
  TEN_UFEC_DISABLED,
  TEN_10G_UFEC_MODULE_A,
  TEN_10G_UFEC_MODULE_B,
  TEN_40G_UFEC
} ten_10g_40g_ufec_t;

/* FEC allocation structure */
typedef struct {
  ten_10g_40g_gfec_t gfec0;     /* Module A 40G GFEC or Slice 0 10G GFEC */
  ten_10g_40g_gfec_t gfec1;     /* Module B 40G GFEC or Slice 0 10G GFEC */

  ten_10g_gfec_t     gfec2;     /* Slice 1 10G GFEC (Module A or B but not both) */
  ten_10g_gfec_t     gfec3;     /* Slice 2 10G GFEC (Module A or B but not both) */
  ten_10g_gfec_t     gfec4;     /* Slice 3 10G GFEC (Module A or B but not both) */

  ten_10g_40g_ufec_t ufec0;     /* Module A 40G UFEC or Slice 0 10G UFEC */
  ten_10g_40g_ufec_t ufec1;     /* Module B 40G UFEC or Slice 1 10G UFEC */

  ten_10g_40g_ufec_t ufec2;     /* Slice 2 10G UFEC (Module A or B but not both) */
  ten_10g_40g_ufec_t ufec3;     /* Slice 3 10G UFEC (Module A or B but not both) */
} ten_fec_cb_t;
/* Bugzilla 24339 End */

typedef struct {
  double    rate;
  cs_uint8  source;
  cs_uint16 k_value;
  cs_uint32 freq;
  cs_uint16 preloadfint;
  cs_uint32 preloadffrac;
  cs_uint32 pdoffset;
  cs_uint16 holdovercount;
  cs_uint16 k1fscale;
  cs_uint16 k1fshift;
  cs_uint16 z1fscale;
  cs_uint16 z1fshift;
  cs_uint16 p1fscale;
  cs_uint16 p1fshift;
  cs_uint16 p2fscale;
  cs_uint16 p2fshift;
  cs_uint16 p3fscale;
  cs_uint16 p3fshift;
  cs_uint16 k1sscale;
  cs_uint16 k1sshift;
  cs_uint16 z1sscale;
  cs_uint16 z1sshift;
  cs_uint16 p1sscale;
  cs_uint16 p1sshift;
  cs_uint16 p2sscale;
  cs_uint16 p2sshift;
  cs_uint16 p3sscale;
  cs_uint16 p3sshift;
  cs_uint16 resetcount;
  cs_uint16 sdmode;
  /* Bugzilla 35188 Start */
  cs_uint8  subrate_div;
  /* Bugzilla 35188 End */
  /* Bugzilla 36358  Start */
  cs_uint8  standalone;
  double    stand_alone_cupll_rate;
  /* Bugzilla 36358  End */
} ten_cupll_cb_t;

/*
 * MPIF rate and access characterization, One CB per chip
 * The MPIF clock frequency must be configured as 1/4 of system clock. Access time
 * and network access flag are calulated on startup and when mpif_freq is set. See
 * ten_mpif_init_access_times().
 */
typedef struct {
  cs_uint32 freq;     /* Configured, MHz. Default = 1/4 default 400 sysclock MHz. */
  cs_uint32 acctime;  /* Calculated. Average register read time in sysclk tics.   */
  cs_uint16 net_acc;  /* Calculated. True if network delay in register read times.*/
} ten_mpif_cb_t;

/*
 * Device Control Block (dev_cb)
 * One control block per chip
 */
typedef struct {
  cs_uint16 dev_id;
  cs_uint16 chip_type; /* TEN_CHIP_T40 or TEN_CHIP_T41. Can be overloaded to force chip type. */
  cs_uint32 state;
  cs_uint32 sysclock;
  CS_SEM sem_mpif;
  CS_SEM sem_glb;
  CS_SEM sem_xcon;
  CS_SEM sem_fracdiv;
  CS_SEM sem_gpllx1;
  CS_SEM sem_irq;
  CS_SEM sem_syncdsync_cb;
  CS_SEM sem_pdcal;
  CS_SEM sem_dm;
  cs_uint32 base_addr;  /* Pointer to base address of chip registers */
  cs_uint32 debug_flag;
  ten_mod_cb_t *ppcb[TEN_MAX_NUM_MODULES];  /* Pointer to Port Control Blocks for this device */
  ten_dev_stats_cb_t stats_cb;
  ten_dev_stats_t stats;
  ten_hsif_loopback_settings_t saved_settings;
  ten_oduflex_cb_t oduflex_cb;
  ten_syncdsync_cb_t syncdsync_cb;
  ten_fec_cb_t fec_cb;  /* Bugzilla 24339 */
  ten_syncdsync_cb_t syncdsync_thread_cb[TEN_MAX_SLICES];
  ten_cupll_cb_t cupll_cb;
  ten_xcon_es_cb_t es_cb[TEN_XCON_ES_COUNT]; /* use es 0 and 4 for module 0 and 1 40G configs */
  ten_mpif_cb_t mpif;
  cs_uint16 cfp_current_traffic[TEN_MAX_SLICES];
} ten_dev_cb_t;

/*************************************************************
 ***********    DRIVER CONTROL BLOCK (drvr_cb)    ************
 *************************************************************/
typedef struct {
  cs_boolean drvr_loaded;                             /* Set to TRUE when driver is loaded */
  ten_dev_cb_t *p_dev_cb_tbl[TEN_MAX_NUM_DEVICES];    /* Table of pointers to Device Control Blocks */
  ten_ws_cb_t ws_ctl;
  #ifndef CS_DONT_USE_STDLIB
  FILE *drvr_out_fp;
  #endif
  cs_char8 drvr_out_filename[256];
  cs_uint16 drvr_flag;
  cs_uint16 ucode_flag;          /* Bugzilla #19410 */
  cs_uint16 ucode_running_flag;  /* Bugzilla #21921 */
  cs_boolean esc_code_print;
  cs_uint32 debug_base_address;
  cs_uint16 drvr_last_str_idx;
  cs_uint16 drvr_last_str_len;
  cs_uint8 drvr_last_str[TEN_DEBUG_BUFFER_SIZE];
  /* Bug #40123 - Fix bus error logging APIs to work on per device basis */
  cs_uint16 debug_dev_id;
  cs_uint16 ten_bus_error_count[TEN_MAX_NUM_DEVICES]; /* Bugilla #26434 */
  cs_uint16 ten_bus_error_ctl[TEN_MAX_NUM_DEVICES]; /* Bugilla #26434 */
} ten_drvr_cb_t;

/* bugzilla #24441, fix klockwork issues */
enum ten_drvr_log_e {
  CS_LOG_DISABLE           = 0,
  CS_LOG_ENABLE            = 1,
  CS_LOG_DELAYS_AND_ERRORS = 2,
  CS_LOG_DELAYS_ONLY       = 3,
  CS_LOG_ERRORS_ONLY       = 4
};

/*
 * Driver flags
 */


#define TEN_DRVR_STATS_IN_HEX            (0x0001)      /* Display stats in hex          */
#define TEN_DRVR_STATS_MASK_ZERO         (0x0002)      /* Do not display zero counters  */
#define TEN_DRVR_STATS_TIMING_INTERVAL   (0x0004)      /* Control timing interval stats */
#define TEN_DRVR_LOG_ALL                 (0x0008)      /* Control log all output        */
#define TEN_DRVR_LOG_DELAYS_AND_ERRORS   (0x0010)      /* Control log delays and errors */
#define TEN_DRVR_LOG_DELAYS_ONLY         (0x0020)      /* Control log delays only       */
#define TEN_DRVR_LOG_ERRORS_ONLY         (0x0040)      /* Control log errors only       */
#define TEN_DRVR_LOG_SUSPEND             (0x0080)      /* Suspend logging temporarily   */
#define TEN_DRVR_ESC_CODE_PRINT          (0x0100)      /* Using VT-100 escape codes     */

#define TEN_DRVR_DEFAULT_FLAG            (TEN_DRVR_LOG_ERRORS_ONLY)

extern ten_drvr_cb_t *g_pTEN;

#define CS_PRINT_BUFFER_SIZE 1024

/* for debug, register write trace facility. See ten_debug_reg_write_trace() */
typedef enum {
  TEN_DEBUG_REG_WR_TR_STATE_NULL    = 0,
  TEN_DEBUG_REG_WR_TR_STATE_ENABLE  = 0xEABC,
  TEN_DEBUG_REG_WR_TR_STATE_DISABLE = 0xDABC,
  TEN_DEBUG_REG_WR_TR_ACTN_CLR_ALL  = 0xCC,
  TEN_DEBUG_REG_WR_TR_ACTN_DISABLE  = 0xDD,
  TEN_DEBUG_REG_WR_TR_ACTN_ENABLE   = 0xEE,
  TEN_DEBUG_REG_WR_TR_ACTN_DISPLAY  = 0xFF
} ten_debug_reg_write_trace_e;

/******************************************************
 ******************      MOD       ********************
 * Before using any of the mapping functions, the     *
 * code should first check if the module is valid.    *
 ******************************************************/
#define TEN_MOD_ID_TO_DEV_ID(mod_id)   (((mod_id) >> 8) & 0xff )
#define TEN_MOD_ID_TO_MOD_NUM(mod_id)  ((cs_uint8)((mod_id) & 0xff))
#define TEN_MOD_ID_TO_NEW_MOD_ID(mod_id, mod_num) (((mod_id) & 0xFF00) | (mod_num))
#define TEN_DEV_ID_TO_MOD_ID(dev_id,mod_num) (((dev_id) << 8) | (mod_num))


#define CS_HNDL_ERROR                                        \
        CS_PRINT("TEN ERROR @ %s:%d ", __FILE__, __LINE__);  \
        ten_error_handler

/* #define PRIVATE_CS_ONLY  */

#ifdef MAKE_STANDALONE_TESTBENCH
/* for testbench */
extern T41_t Chips[2];
extern cs_uint16 mod_id0;
extern cs_uint16 mod_id1;

#define TEN_DEV_COMMON_VALIDATE(DEV_ID, BASE_ADDR, RETCODE)          \
{                                                                    \
  BASE_ADDR = &Chips[DEV_ID];                                        \
}

#define TEN_MOD_COMMON_VALIDATE(MODULE_ID, BASE_ADDR, RETCODE)       \
{                                                                    \
  BASE_ADDR = &Chips[((MODULE_ID >> 8) & 0x00FF)];                   \
}                                                                    \

#else  /* for apish */

/***************************************************************
 ****************  BASE ADDRESS MACROS  ************************
 ***************************************************************/

#define TEN_DEV_COMMON_VALIDATE(DEV_ID, BASE_ADDR, RETCODE)                \
{                                                                          \
   if (!(g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND)) {                      \
     CS_PRINT("%s\n", CS_FUNCTION_NAME);                                   \
   }                                                                       \
                                                                           \
  if (TEN_DEV_COMMON_VALIDATE_INTERNAL(DEV_ID, &BASE_ADDR) == CS_ERROR) {  \
     return (RETCODE);                                                     \
   }                                                                       \
}

#define TEN_MOD_COMMON_VALIDATE(MODULE_ID, BASE_ADDR, RETCODE)                \
  {                                                                           \
    if (!(g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND)) {                        \
      CS_PRINT("%s\n", CS_FUNCTION_NAME);                                     \
    }                                                                         \
                                                                              \
  if (TEN_MOD_COMMON_VALIDATE_INTERNAL(MODULE_ID, &BASE_ADDR) == CS_ERROR) {  \
     return (RETCODE);                                                        \
   }                                                                          \
}
#endif

/* these semaphore functions should be macros for __LINE__ & __FILE__ debugging */

#define TEN_DEV_LOCK(dev_id, blk_id)                                        \
{                                                                           \
  CS_SEM *psem = ten_get_dev_sem_ptr(dev_id, blk_id);                       \
                                                                            \
  if ( CS_SEM_TAKE(psem) != CS_OK ) {                                       \
    CS_HNDL_ERROR(dev_id, ETEN_DEV_SEM_TAKE_FAILED, NULL);                  \
  }                                                                         \
}

#define TEN_DEV_UNLOCK(dev_id, blk_id)                                      \
{                                                                           \
    CS_SEM *psem = ten_get_dev_sem_ptr(dev_id, blk_id);                     \
    CS_SEM_GIVE(psem);                                                      \
}

#define TEN_MOD_LOCK(mod_id, blk_id)                                        \
{                                                                           \
  CS_SEM *psem = ten_get_port_sem_ptr(mod_id, blk_id);                      \
                                                                            \
  if ( CS_SEM_TAKE(psem) != CS_OK ) {                                       \
    CS_HNDL_ERROR(mod_id, ETEN_MOD_SEM_TAKE_FAILED, NULL);                  \
  }                                                                         \
}

#define TEN_MOD_UNLOCK(mod_id, blk_id)                                      \
{                                                                           \
  CS_SEM *psem = ten_get_port_sem_ptr(mod_id, blk_id);                      \
  CS_SEM_GIVE(psem);                                                        \
}

/***************************************************************
 ***************  REGISTER ACCESS MACROS  **********************
 ***************************************************************/

#define TEN_MPIF_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->mpif.reg))

#define TEN_GLB_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->glb_misc.reg))

/* Preserved for backward compatibility with customer code, not for use by API */
/* --------------------------------------------------------------------------- */
#define TEN_FRAC_DIV_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->frac_div.reg))

#define TEN_GPLLX1_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->gpllx1_sds.reg))

#define TEN_XCON_CBERT_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->XCON.XCON_cbert.reg))

#define TEN_XCON_ES_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->XCON.XCON_es.reg))
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

#define TEN_FRAC_DIV_COMMON_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->frac_div.reg))

#define TEN_FRAC_DIV_INST_REG_ADDR(p_dev, instance, reg) \
  ten_get_frac_div_inst_reg_addr( (cs_reg *) &((p_dev)->frac_div.reg), instance )

#define TEN_SYNCDSYNCRX_REG_ADDR(p_dev, module_id, slice, reg) \
  ((volatile cs_reg *)&((p_dev)->SYNCDSYNCRX.reg) + ((module_id & 0x0001) * 4 + slice) * \
  TEN_SYNCDSYNCRX_STRIDE)

#define TEN_SYNCDSYNCTX_REG_ADDR(p_dev, module_id, slice, reg) \
  ((volatile cs_reg *)&((p_dev)->SYNCDSYNCTX.reg) + ((module_id & 0x0001) * 4 + slice) * \
  TEN_SYNCDSYNCRX_STRIDE)

#define TEN_GPLLX1_INST_REG_ADDR(p_dev, reg, instance) \
  ten_get_gpllx1_inst_reg_addr( (cs_reg *)&((p_dev)->gpllx1_sds.reg), instance)

#define TEN_SPOH_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->spoh.reg))

#define TEN_HSIF_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->HSIF.reg) + ((module_id & 0x0001) * TEN_HSIF_STRIDE))

#define TEN_HSIF_SLC0_MR10X4_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->HSIF.HSIF_mr_slc0.HSIF_mr_slc0_mr10x4_sds.reg) + \
  ((module_id & 0x0001) * TEN_HSIF_STRIDE))

#define TEN_HSIF_SLC1_MR10X5_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->HSIF.HSIF_mr_slc1.HSIF_mr_slc1_mr10x5_sds.reg) + \
  ((module_id & 0x0001) * TEN_HSIF_STRIDE))

#define TEN_HSIF_SLC2_MR10X4_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->HSIF.HSIF_mr_slc2.HSIF_mr_slc2_mr10x4_sds.mr10x4_sds_common_##reg) + \
  ((module_id & 0x0001) * TEN_HSIF_STRIDE))

#define TEN_HSIF_SLC3_MR10X5_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->HSIF.HSIF_mr_slc3.HSIF_mr_slc3_mr10x5_sds.mr10x5_sds_common_##reg) + \
  ((module_id & 0x0001) * TEN_HSIF_STRIDE))

#define TEN_HSIF_SFI5_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->HSIF.HSIF_sfi5.reg) + \
  ((module_id & 0x0001) * TEN_HSIF_STRIDE))

#define TEN_HSIF_SFI42_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->HSIF.HSIF_sfi42.reg) + ((module_id & 0x0001) * TEN_HSIF_STRIDE))

#define TEN_XFI32X1_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_xfi32x1_inst_reg_addr( (cs_reg *)&((p_dev)->xfi32x1_sds.reg), slice)

#define TEN_XFI32X1_DSP_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_xfi32x1_inst_reg_addr( (cs_reg *)&((p_dev)->xfi32x1_sds.xfi32x1_sds_sds_dsp.reg), slice)

#define TEN_XCON_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->XCON.reg))

#define TEN_XCON_INST_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->XCON.reg))

#define TEN_XCON_CBERT_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->XCON.XCON_cbert.reg))

#define TEN_XCON_CBERT_INST_REG_ADDR(p_dev, reg, instance) \
ten_get_xcon_cbert_inst_reg_addr( (cs_reg *)&((p_dev)->XCON.XCON_cbert.reg), instance)

#define TEN_XCON_PBERT_INST_REG_ADDR(p_dev, reg, instance) \
ten_get_xcon_pbert_inst_reg_addr( (cs_reg *)&((p_dev)->XCON.reg), instance)

#define TEN_XCON_SADECO_INST_REG_ADDR(p_dev, reg, instance) \
ten_get_xcon_sadeco_inst_reg_addr( (cs_reg *)&((p_dev)->XCON.reg), instance)

#define TEN_XCON_ES_INST_REG_ADDR(p_dev, reg, slice) \
  ten_get_xcon_es_inst_reg_addr( (cs_reg *)&((p_dev)->XCON.XCON_es.reg), slice)

#define TEN_XCON_ES_TH_LVL_REG_ADDR(p_dev, instance, level) \
  ten_get_xcon_es_th_lvl_reg_addr( (cs_reg *)&((p_dev)->XCON.ES_0_THRESHOLD_LEVEL_0), instance, level)

#define TEN_XCON_ES_PS_LVL_REG_ADDR(p_dev, instance, level) \
  ten_get_xcon_es_ps_lvl_reg_addr( (cs_reg *)&((p_dev)->XCON.ES_0_PAUSE_LEVEL_0), instance, level)

#define TEN_XCON_ES_PS_TH_SEL_REG_ADDR(p_dev, instance) \
  ten_get_xcon_es_ps_th_sel_reg_addr( (cs_reg *)&((p_dev)->XCON.PP_ES_PAUSE_THRESHOLD_SELECT_0), instance)

#define TEN_XCON_ES_SOURCE_SEL_REG_ADDR(p_dev, instance) \
  ten_get_xcon_es_source_sel_reg_addr( (cs_reg *)&((p_dev)->XCON.ES_SOURCE_SELECT_0), instance)

#define TEN_XCON_RX_THRSHLD_SEL_REG_ADDR(p_dev, instance) \
  ten_get_xcon_es_source_sel_reg_addr( (cs_reg *)&((p_dev)->XCON.ES_RX_THRESHOLD_SELECT_0), instance)

#define TEN_GFEC40G_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->GFEC40g.reg) + ((module_id & 0x0001) * TEN_GFEC40G_STRIDE))

#define TEN_GFEC10G_REG_ADDR(p_dev, slice, reg) \
  ten_get_GFEC10g_inst_reg_addr( (cs_reg *)&((p_dev)->GFEC10g.reg), slice)

#define TEN_UFEC_REG_ADDR(p_dev, slice, reg) \
  ten_get_UFEC_inst_reg_addr( (cs_reg *)&((p_dev)->UFEC.reg), slice)

#define TEN_OHPP_SFU_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->ohpp.reg) + (module_id & 0x0001) * TEN_OHPP_STRIDE)

#define TEN_OHPP_DOE_REG_ADDR(p_dev, module_id,reg) \
  ((volatile cs_reg *)&((p_dev)->ohpp.reg) + (module_id & 0x0001) * TEN_OHPP_STRIDE)

#define TEN_OHPP_DOI_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->ohpp.reg) + (module_id & 0x0001) * TEN_OHPP_STRIDE)

#define TEN_OHPP_SFC_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->ohpp.reg) + (module_id & 0x0001) * TEN_OHPP_STRIDE)

#define TEN_N40G_REG_ADDR(p_dev, module_id, reg) \
  ten_get_n40g_reg_addr( (cs_reg *)&((p_dev)->n40g.reg), (module_id & 0x0001))

#define TEN_N40G_SDFR_REG_ADDR(p_dev, module_id, reg) \
  ten_get_n40g_reg_addr( (cs_reg *)&((p_dev)->n40g.n40g_sdfr.reg), (module_id & 0x0001))

#define TEN_N40G_OOHR_REG_ADDR(p_dev, module_id, reg) \
  ten_get_n40g_reg_addr( (cs_reg *)&((p_dev)->n40g.n40g_oohr.reg), (module_id & 0x0001))

#define TEN_N40G_OTNSM_REG_ADDR(p_dev, module_id, reg) \
  ten_get_n40g_reg_addr( (cs_reg *)&((p_dev)->n40g.n40g_otnsm.reg), (module_id & 0x0001))

#define TEN_N10G_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_n10g_reg_addr( (cs_reg *)&((p_dev)->n10g.reg), module_id, slice)

#define TEN_N10G_SDFR_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_n10g_reg_addr( (cs_reg *)&((p_dev)->n10g.n10g_sdfr.sdfr_##reg), module_id, slice)

#define TEN_N10G_OOHR_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_n10g_reg_addr( (cs_reg *)&((p_dev)->n10g.n10g_oohr.oohr_##reg), module_id, slice)

#define TEN_N10G_OTNSM_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_n10g_reg_addr( (cs_reg *)&((p_dev)->n10g.n10g_otnsm.otnsm_##reg), module_id, slice)

#define TEN_PP10G_MISC_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.reg), module_id, slice)

#define TEN_PP10G_PCS_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_pcs.reg), module_id, slice)

#define TEN_PP10G_RS_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_rs.reg), module_id, slice)

#define TEN_PP10G_MAC_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_mac.reg), module_id, slice)

#define TEN_PP10G_BASEX_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_basex.reg), module_id, slice)

#define TEN_PP10G_FC_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_fc.reg), module_id, slice)

#define TEN_PP10G_GFP_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_gfp.reg), module_id, slice)

#define TEN_PP10G_XGADJ_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_xgadj.reg), module_id, slice)

#define TEN_PP10G_XCODE_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_xcode.reg), module_id, slice)

#define TEN_PP10G_EGPCS_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_egpcs.reg), module_id, slice)

#define TEN_PP10G_XGPM_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_xgpm.reg), module_id, slice)

#define TEN_PP10G_MON10B_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_mon10b.reg), module_id, slice)
  
#define TEN_PP10G_BER10B_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_pp10g_reg_addr( (cs_reg *)&((p_dev)->pp10g.pp10g_ber10b.reg), module_id, slice)
  
/* T40 fixup */
#define TEN_XML_N10G_SDFR_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_n10g_reg_addr( (cs_reg *)&((p_dev)->n10g.n10g_sdfr.reg), module_id, slice)

#define TEN_XML_N10G_OOHR_REG_ADDR(p_dev, module_id, slice, reg) \
  ((volatile cs_reg *)&((p_dev)->n10g.n10g_oohr.reg) + \
  ((module_id & 0x0001) * 4 + slice) * TEN_N10G_STRIDE)

#define TEN_GPLLX1_FIXUP_REG_ADDR(p_dev, slice, reg) \
  ten_get_gpllx1_inst_reg_addr( (cs_reg *)&((p_dev)->gpllx1_sds.reg), slice)

/* T41 */
#define TEN_N40G_MLDRX_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->n40g.n40g_mldrx.reg) + (module_id & 0x0001) * TEN_N40G_STRIDE)

#define TEN_N40G_MLDRX_SADECO_REG_ADDR(p_dev, module_id, reg) \
  ((volatile cs_reg *)&((p_dev)->n40g.n40g_mldrx.n40g_mldrx_sadeco.reg) + (module_id & 0x0001) * TEN_N40G_STRIDE)

#define TEN_MLD_ES_REG_ADDR(p_dev, slice, reg) \
  ((volatile cs_reg *)&((p_dev)->n40g.n40g_mldrx.reg) + slice * TEN_N40G_MLDRX_MLD_ES_STRIDE)

#define TEN_PP40G_REG_ADDR(p_dev, module_id, reg) \
  ten_get_pp40g_reg_addr( (cs_reg *)&((p_dev)->pp40g.reg), (module_id & 0x0001) )

#define TEN_DM_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->dm.reg))

#define TEN_CFP32X1_REG_ADDR(p_dev, module_id, slice, reg) \
  ten_get_xfi_cfp32x1_inst_reg_addr((cs_reg *)&((p_dev)->cfp32x1_sds.reg), slice)
  
#define TEN_XFI_CUPLL_REG_ADDR(p_dev, slice, reg) \
  ten_get_xfi_cupll_inst_reg_addr( (cs_reg *)&((p_dev)->xfi_cupll.reg), slice)
  
#define TEN_PDCAL_REG_ADDR(p_dev, reg) \
  ((volatile cs_reg *)&((p_dev)->pdcal.reg))

/*****************************************************************************
 **************** useful register config enums and mask defines  *************
 *****************************************************************************/

/*- for TEN_DM_DMSEL_CFG_t --------------------------------------------------*/
typedef enum {  /* Bugzilla 24880 */ 
  TEN_DM_CNT_STOP_SAT = 0, /* DM delay counter saturate at maximum if DMACK is not received. */
  TEN_DM_CNT_STOP_THR = 1, /* DM delay counter stops when DM_DELAY = DM_THRESH. */
  TEN_DM_CNT_STOP_ROV = 2, /* DM delay counter rollover and keeps running but stops upon receiving DMRX. */
  TEN_DM_CNT_STOP_FRC = 3  /* Force stop. */
} TEN_DM_CNT_STOP_e;

typedef enum {
  TEN_HOLDOVER0    = 0,
  TEN_HOLDOVER1    = 1,
  TEN_HOLDOVER2    = 2,
  TEN_HOLDOVER3    = 3,
  TEN_HOLDOVER4    = 4,
  TEN_HOLDOVER5    = 5,
  TEN_HOLDOVER6    = 6,
  TEN_HOLDOVER7    = 7,
  TEN_MAX_HOLDOVER = 8,
  TEN_HOLDOVER_ALL = 0xFF
} ten_cupll_holdover_id_t;

typedef enum {
  TEN_XFI_CUPLL_RESET_CUPLL_DIG = 0,
  TEN_XFI_CUPLL_RESET_GRO       = 1,
  TEN_XFI_CUPLL_RESET_LOCKDET   = 2,
  TEN_XFI_CUPLL_RESET_SDRESET   = 3,
  TEN_XFI_CUPLL_RESET_ALL       = 0xFF
} ten_xfi_cupll_reset_t;

typedef enum {
  TEN_XFI_CUPLL_FREQ_K1F  = 0,
  TEN_XFI_CUPLL_FREQ_Z1F  = 1,
  TEN_XFI_CUPLL_FREQ_P1F  = 2,
  TEN_XFI_CUPLL_FREQ_P2F  = 3,
  TEN_XFI_CUPLL_FREQ_P3F  = 4,
  TEN_XFI_CUPLL_FREQ_K1S  = 5,
  TEN_XFI_CUPLL_FREQ_Z1S  = 6,
  TEN_XFI_CUPLL_FREQ_P1S  = 7,
  TEN_XFI_CUPLL_FREQ_P2S  = 8,
  TEN_XFI_CUPLL_FREQ_P3S  = 9
} ten_xfi_cupll_freq_t;

#define TEN_DM_SRC_SIDE_MASK  = (0x8)  /* valid for TXSRC and RXSRC) */
#define TEN_DM_SRC_BLOCK_MASK = (0x4)  /* valid for TXSRC and RXSRC) */
#define TEN_DM_SRC_SLICE_MASK = (0x3)  /* valid for TXSRC and RXSRC) */

/* Bugzilla 28977 Start */
typedef enum {
  TEN_INT_READ  = 0,
  TEN_INT_CLEAR	= 1
} cs_int_action_t;
/* Bugzilla 28977 End */

#ifdef __cplusplus
}                               /* extern C */
#endif                          /* __cplusplus */
#endif                          /* __TEN_GEN_DATA_H__ */
