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
 * ten_n1g_data.h
 *
 * N10G defines
 *
 * $Id: ten_n10g_data.h,v 1.9 2013/02/22 20:47:56 jccarlis Exp $
 *
 */
 
#ifndef __TEN_N10G_DATA_H__
#define __TEN_N10G_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

/* This validates the N10G module and slice for the CS6004 and CS6005 */
#ifdef TEN_NO_N10G_A
#define TEN_N10G_VALIDATE(module_id, slice) \
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) return CS_ERROR
#else
#ifdef TEN_NO_N10G_A_234
#define TEN_N10G_VALIDATE(module_id, slice) \
  if ((TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) && \
      (slice != TEN_SLICE0)) return CS_ERROR
#else
#define TEN_N10G_VALIDATE(module_id, slice)
#endif
#endif

enum ten_n10g_set_global_resets_enums {
  TEN_N10G_GLOBAL_RESETS_RSTTX    = 0x0001,
  TEN_N10G_GLOBAL_RESETS_RSTTXNG  = 0x0002,
  TEN_N10G_GLOBAL_RESETS_RSTOT    = 0x0004,
  TEN_N10G_GLOBAL_RESETS_RSTCT    = 0x0008,
  TEN_N10G_GLOBAL_RESETS_RSTRX    = 0x0010,
  TEN_N10G_GLOBAL_RESETS_RSTOR    = 0x0020,
  TEN_N10G_GLOBAL_RESETS_RSTCR    = 0x0040,
  TEN_N10G_GLOBAL_RESETS_RSTSYS   = 0x0100,
  TEN_N10G_GLOBAL_RESETS_ALL      = 0x017F
};

enum ten_n10g_trace_size {
  TEN_N10G_TRACE_SIZE_1_BYTE       = 0x0000,
  TEN_N10G_TRACE_SIZE_16_BYTE      = 0x0001,
  TEN_N10G_TRACE_SIZE_64_BYTE      = 0x0002,
  TEN_N10G_TRACE_SIZE_16_BYTE_CRC  = 0x0003
};

enum ten_n10g_j_byte_cfg_enums {
  TEN_N10G_J_BYTE_CFG_MMONALLZERO     = 0x0000,
  TEN_N10G_J_BYTE_CFG_MMONCRC7ERR     = 0x0001,
  TEN_N10G_J_BYTE_CFG_MMONUNSTABLE    = 0x0002,
  TEN_N10G_J_BYTE_CFG_DISUPPR         = 0x0003,
  TEN_N10G_J_BYTE_CFG_DISUPST         = 0x0004,
  TEN_N10G_J_BYTE_CFG_MANU            = 0x0005,
  TEN_N10G_J_BYTE_CFG_LEN             = 0x0006,
  TEN_N10G_J_BYTE_CFG_SONET           = 0x0007,
  TEN_N10G_J_BYTE_CFG_AUTO            = 0x0008
};

enum ten_n10g_g1_config_enums {
    TEN_N10G_G1_CONFIG_RDIPEN         = 0x0000,
    TEN_N10G_G1_CONFIG_G1MLEN         = 0x0001,
    TEN_N10G_G1_CONFIG_G1AFLEN        = 0x0002,
    TEN_N10G_G1_CONFIG_PLMP2PRDIEN    = 0x0003,
    TEN_N10G_G1_CONFIG_LCD2PRDIEN     = 0x0004,
    TEN_N10G_G1_CONFIG_AIS2PRDIEN     = 0x0005,
    TEN_N10G_G1_CONFIG_AISC2PRDIEN    = 0x0006,
    TEN_N10G_G1_CONFIG_LOP2PRDIEN     = 0x0007,
    TEN_N10G_G1_CONFIG_LOPC2PRDIEN    = 0x0008,
    TEN_N10G_G1_CONFIG_UNEQ2PRDIEN    = 0x0009,
    TEN_N10G_G1_CONFIG_TIM2PRDIEN     = 0x000A
};

/* Bugzilla 29751 Start */
enum ten_n10g_otnr_intr_enums {
    TEN_N10G_OTNR_INTR_IPN11        = 0x0001,

    TEN_N10G_OTNR_INTR_IOOF         = 0x0004,
    TEN_N10G_OTNR_INTR_ILOF         = 0x0008,
    TEN_N10G_OTNR_INTR_IIF          = 0x0010,
    TEN_N10G_OTNR_INTR_FSCH         = 0x0020,
    TEN_N10G_OTNR_INTR_FSUSTSI      = 0x0040,
    TEN_N10G_OTNR_INTR_GMPI         = 0x0080,
    TEN_N10G_OTNR_INTR_FS_MMI       = 0x0100,
    TEN_N10G_OTNR_INTR_FAWMI        = 0x0200,
    TEN_N10G_OTNR_INTR_ALL          = 0x03FD
};

enum ten_n10g_sdfr_sdfist_enums {
    TEN_N10G_SDFR_SDFIST_OOF        = 0x0001,
    TEN_N10G_SDFR_SDFIST_LOF        = 0x0002,
    TEN_N10G_SDFR_SDFIST_LOS        = 0x0004,
    TEN_N10G_SDFR_SDFIST_FER        = 0x0008,
    TEN_N10G_SDFR_SDFIST_FOK        = 0x0010,

    TEN_N10G_SDFR_SDFIST_B1INVI     = 0x0040,
    TEN_N10G_SDFR_SDFIST_B1BTEX     = 0x0080,
    TEN_N10G_SDFR_SDFIST_B1BLEX     = 0x0100,
    TEN_N10G_SDFR_SDFIST_B2BTEX     = 0x0200,
    TEN_N10G_SDFR_SDFIST_B2BLEX     = 0x0400,
    TEN_N10G_SDFR_SDFIST_SFI        = 0x0800,
    TEN_N10G_SDFR_SDFIST_SDI        = 0x1000,
    TEN_N10G_SDFR_SDFIST_IPN11      = 0x8000,
    TEN_N10G_SDFR_SDFIST_ALL        = 0x9FDF
};

enum ten_n10g_oohr_acmsi_enums {
  TEN_N10G_OOHR_ACCEPTED_MSI_EXT7 = 15,
  TEN_N10G_OOHR_ACCEPTED_MSI_EXT6 = 14,
  TEN_N10G_OOHR_ACCEPTED_MSI_EXT5 = 13, 
  TEN_N10G_OOHR_ACCEPTED_MSI_EXT4 = 12,
  TEN_N10G_OOHR_ACCEPTED_MSI_EXT3 = 11, 
  TEN_N10G_OOHR_ACCEPTED_MSI_EXT2 = 10,
  TEN_N10G_OOHR_ACCEPTED_MSI_EXT1 = 9,
  TEN_N10G_OOHR_ACCEPTED_MSI_EXT0 = 8,
  TEN_N10G_OOHR_ACCEPTED_MSI7 = 7,
  TEN_N10G_OOHR_ACCEPTED_MSI6 = 6,
  TEN_N10G_OOHR_ACCEPTED_MSI5 = 5,
  TEN_N10G_OOHR_ACCEPTED_MSI4 = 4,
  TEN_N10G_OOHR_ACCEPTED_MSI3 = 3,
  TEN_N10G_OOHR_ACCEPTED_MSI2 = 2,
  TEN_N10G_OOHR_ACCEPTED_MSI1 = 1,
  TEN_N10G_OOHR_ACCEPTED_MSI0 = 0
};

/* Bugzilla 29751 End */

/* Bugzilla 29997 Start */
enum ten_n10g_oohr_aps_detect_state_enums {
  TEN_APS_DETECT_VALUE_CHANGED              = 1,
  TEN_APS_DETECT_VALUE_UNSTABLE             = 2,
  TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE = 3
};
/* Bugzilla 29997 End */

enum ten_dm_select_enums {
  TEN_DM_NONE = 0,
  TEN_DM_PM   = 1,
  TEN_DM_TCM6 = 2,
  TEN_DM_TCM5 = 3,
  TEN_DM_TCM4 = 4,
  TEN_DM_TCM3 = 5,
  TEN_DM_TCM2 = 6,
  TEN_DM_TCM1 = 7,
  TEN_DM_RES  = 8,
  TEN_DM_SELECT_MAX
};

enum ten_dm_gen_en_enums {
  TEN_DM_INSERTED_FROM_OHPP = 0,
  TEN_DM_INTERNALLY_GENERATED = 1,
  TEN_DM_SET_TO_0 = 2,
  TEN_DM_SET_TO_1 = 3,
  TEN_DM_GEN_EN_MAX
};     

enum ten_dm_set_filt_enums {
  TEN_DM_FILT_0_FRMS = 0, /* 0 = Accept received  */
  TEN_DM_FILT_2_FRMS = 1, /* 1 = Accept 2 matches */
  TEN_DM_FILT_3_FRMS = 2, /* 2 = Accept 3 matches */
  TEN_DM_FILT_5_FRMS = 3  /* 3 = Accept 5 matches */
};


enum ten_jcsquelch_enums {
  TEN_JCSQLCH_LOM      = 0x01, 
  TEN_JCSQLCH_FECEED   = 0x02,
  TEN_JCSQLCH_LOF      = 0x04,
  TEN_JCSQLCH_OTUAIS   = 0x08,
  TEN_JCSQLCH_LOS      = 0x10,
  TEN_JCSQLCH_XLOS     = 0x20,
  TEN_JCSQLCH_DOCIP    = 0x40,
  TEN_JCSQLCH_DLCKP    = 0x80,
  TEN_JCSQLCH_DODUAISP = 0x100,
  TEN_JCSQLCH_LOL      = 0x200
};

#ifdef __cplusplus
}
#endif
#endif




