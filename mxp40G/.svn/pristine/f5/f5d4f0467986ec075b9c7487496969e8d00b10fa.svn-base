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
 * ten_ohpp_data.h
 *
 * $Id: ten_ohpp_data.h 
 *
 */

#ifndef __TEN_OHPP_DATA_H__
#define __TEN_OHPP_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#define TEN_OHPP_DO_RAM_UNIT_NUM 4
#define TEN_OHPP_DO_RAM_UNIT_SIZE 0x20
#define TEN_OHPP_SFC_RAM_UNIT_NUM 78
#define TEN_OHPP_SFC_RAM_UNIT_SIZE 0x40
#define TEN_OHPP_GPB_INSTANCE_STRIDE 8
#define TEN_OHPP_GPB_REGISTER_STRIDE 2

#define TEN_CONSEQUENT_ACTION_ROW_COUNT 78
#define TEN_CONSEQUENT_ACTION_BIT_COUNT 984
/* bugzilla #21917, allow more actions bits for T41 */
#define TEN_CONSEQUENT_ACTION_BIT_COUNT_T41 1024

#define TEN_CONSEQUENT_ACTION_EVENT_GLOBAL_COUNT   40
#define TEN_CONSEQUENT_ACTION_EVENT_OXUX_COUNT     84
#define TEN_CONSEQUENT_ACTION_EVENT_OC192_COUNT     8

#define TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET  492
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL   0
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_GLOBAL    39
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3     40
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3     123
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1  124
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_1   207
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2  208
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_2   291
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3  292
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_3   375
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4  376
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_4   459
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1 460
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_1  467
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2 468
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_2  475
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3 476
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_3  483
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4 484
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_4  491

/* Bugzilla #38149 - update ten_hl_ohpp_dump_sfu API for T41 events  */
#define TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41   20

#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM   984
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3_TERM    986
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1 987
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_1  989
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2 990
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_2  992
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3 993
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_3  995
#define TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4 996
#define TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_4  998
#define TEN_CONSEQUENT_ACTION_EVENT_40G_PP            999
#define TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1     1000
#define TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN4     1003

#define TEN_OHPP_MAX_DPA_ACCESS_ATTEMPTS 20

enum ohpp_signals {
  TEN_OHPP_INSERT_ZERO  = 0,
  TEN_OHPP_INSERT_AIS   = 1,
  TEN_OHPP_INSERT_OCI   = 2,
  TEN_OHPP_INSERT_LCK   = 3
};

enum ohpp_widths {
  TEN_OHPP_WIDTH_ONLY_PAYLOAD = 0,
  TEN_OHPP_WIDTH_OH_PAYLOAD   = 1,
  TEN_OHPP_WIDTH_FRAME        = 2
};

enum ohpp_priorities {
  TEN_OHPP_PRIORITY_HIGH      = 0,
  TEN_OHPP_PRIORITY_LOW       = 1
};

enum ohpp_status {
  TEN_OHPP_SFU_STATE_SFCINIT  = 0,
  TEN_OHPP_SFU_STATE_SFCBANK  = 1,
  TEN_OHPP_SFU_STATE_DOAIRF   = 2,
  TEN_OHPP_SFU_STATE_DOAIBFF  = 3,
  TEN_OHPP_SFU_STATE_PHLOST   = 4,
  TEN_OHPP_SFU_STATE_ALL      = 0xFF
};

enum ohpp_consequent_actions {
  TEN_CA_MAINT_SIG_INSERT_OXU3         = 0,
  TEN_CA_MAINT_SIG_INSERT_OXU2_1       = 1,
  TEN_CA_MAINT_SIG_INSERT_OXU2_2       = 2,
  TEN_CA_MAINT_SIG_INSERT_OXU2_3       = 3,
  TEN_CA_MAINT_SIG_INSERT_OXU2_4       = 4,
  TEN_CA_OTN_PM_BDI_CTRL_OXU3          = 5,
  TEN_CA_OTN_TCM1_BDI_CTRL_OXU3        = 6,
  TEN_CA_OTN_TCM2_BDI_CTRL_OXU3        = 7,
  TEN_CA_OTN_TCM3_BDI_CTRL_OXU3        = 8,
  TEN_CA_OTN_TCM4_BDI_CTRL_OXU3        = 9,
  TEN_CA_OTN_TCM5_BDI_CTRL_OXU3        = 10,
  TEN_CA_OTN_TCM6_BDI_CTRL_OXU3        = 11,
  TEN_CA_OTN_SM_BDI_CTRL_OXU3          = 12,
  TEN_CA_OTN_PM_BDI_CTRL_OXU2_1        = 13,
  TEN_CA_OTN_TCM1_BDI_CTRL_OXU2_1      = 14,
  TEN_CA_OTN_TCM2_BDI_CTRL_OXU2_1      = 15,
  TEN_CA_OTN_TCM3_BDI_CTRL_OXU2_1      = 16,
  TEN_CA_OTN_TCM4_BDI_CTRL_OXU2_1      = 17,
  TEN_CA_OTN_TCM5_BDI_CTRL_OXU2_1      = 18,
  TEN_CA_OTN_TCM6_BDI_CTRL_OXU2_1      = 19,
  TEN_CA_OTN_SM_BDI_CTRL_OXU2_1        = 20,
  TEN_CA_OTN_PM_BDI_CTRL_OXU2_2        = 21,
  TEN_CA_OTN_TCM1_BDI_CTRL_OXU2_2      = 22,
  TEN_CA_OTN_TCM2_BDI_CTRL_OXU2_2      = 23,
  TEN_CA_OTN_TCM3_BDI_CTRL_OXU2_2      = 24,
  TEN_CA_OTN_TCM4_BDI_CTRL_OXU2_2      = 25,
  TEN_CA_OTN_TCM5_BDI_CTRL_OXU2_2      = 26,
  TEN_CA_OTN_TCM6_BDI_CTRL_OXU2_2      = 27,
  TEN_CA_OTN_SM_BDI_CTRL_OXU2_2        = 28,
  TEN_CA_OTN_PM_BDI_CTRL_OXU2_3        = 29,
  TEN_CA_OTN_TCM1_BDI_CTRL_OXU2_3      = 30,
  TEN_CA_OTN_TCM2_BDI_CTRL_OXU2_3      = 31,
  TEN_CA_OTN_TCM3_BDI_CTRL_OXU2_3      = 32,
  TEN_CA_OTN_TCM4_BDI_CTRL_OXU2_3      = 33,
  TEN_CA_OTN_TCM5_BDI_CTRL_OXU2_3      = 34,
  TEN_CA_OTN_TCM6_BDI_CTRL_OXU2_3      = 35,
  TEN_CA_OTN_SM_BDI_CTRL_OXU2_3        = 36,
  TEN_CA_OTN_PM_BDI_CTRL_OXU2_4        = 37,
  TEN_CA_OTN_TCM1_BDI_CTRL_OXU2_4      = 38,
  TEN_CA_OTN_TCM2_BDI_CTRL_OXU2_4      = 39,
  TEN_CA_OTN_TCM3_BDI_CTRL_OXU2_4      = 40,
  TEN_CA_OTN_TCM4_BDI_CTRL_OXU2_4      = 41,
  TEN_CA_OTN_TCM5_BDI_CTRL_OXU2_4      = 42,
  TEN_CA_OTN_TCM6_BDI_CTRL_OXU2_4      = 43,
  TEN_CA_OTN_SM_BDI_CTRL_OXU2_4        = 44,
  TEN_CA_OTN_IAE_CTRL_OXU3             = 45,
  TEN_CA_OTN_IAE_CTRL_OXU2_1           = 46,
  TEN_CA_OTN_IAE_CTRL_OXU2_2           = 47,
  TEN_CA_OTN_IAE_CTRL_OXU2_3           = 48,
  TEN_CA_OTN_IAE_CTRL_OXU2_4           = 49,
  TEN_CA_OXU3_AIS_PN11_INSERT_CTRL     = 50,
  TEN_CA_OXU2_AIS_PN11_INSERT_CTRL_1   = 51,
  TEN_CA_OXU2_AIS_PN11_INSERT_CTRL_2   = 52,
  TEN_CA_OXU2_AIS_PN11_INSERT_CTRL_3   = 53,
  TEN_CA_OXU2_AIS_PN11_INSERT_CTRL_4   = 54,
  TEN_CA_OXU3_CBR_GEN_PAY_INSERT_AIS   = 55,
  TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_1 = 56,
  TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_2 = 57,
  TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_3 = 58,
  TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_4 = 59,
  TEN_CA_RDI_INSERT_OC_192_1           = 60,
  TEN_CA_RDI_INSERT_OC_192_2           = 61,
  TEN_CA_RDI_INSERT_OC_192_3           = 62,
  TEN_CA_RDI_INSERT_OC_192_4           = 63,
  TEN_CA_MUX_AIS_INSERT_OC_192_1       = 64,
  TEN_CA_MUX_AIS_INSERT_OC_192_2       = 65,
  TEN_CA_MUX_AIS_INSERT_OC_192_3       = 66,
  TEN_CA_MUX_AIS_INSERT_OC_192_4       = 67,
  TEN_CA_GPSB_INSERT_0                 = 68,
  TEN_CA_GPSB_INSERT_1                 = 69,
  TEN_CA_GPSB_INSERT_2                 = 70,
  TEN_CA_GPSB_INSERT_3                 = 71,
  TEN_CA_GPSB_INSERT_4                 = 72,
  TEN_CA_GPSB_INSERT_5                 = 73,
  TEN_CA_GPSB_INSERT_6                 = 74,
  TEN_CA_GPSB_INSERT_7                 = 75,
  TEN_CA_GPSB_INSERT_8                 = 76,
  TEN_CA_GPSB_INSERT_9                 = 77
};

enum ohpp_otn_oh_bytes {
  TEN_OTNOH_FAOH_BYTE1           = 0,
  TEN_OTNOH_FAOH_BYTE2           = 1,
  TEN_OTNOH_FAOH_BYTE3           = 2,
  TEN_OTNOH_FAOH_BYTE4           = 3,
  TEN_OTNOH_FAOH_BYTE5           = 4,
  TEN_OTNOH_FAOH_BYTE6           = 5,
  TEN_OTNOH_FAOH_BYTE7           = 6,
  TEN_OTNOH_OTUKOH_BYTE1         = 7,
  TEN_OTNOH_OTUKOH_BYTE2         = 8,
  TEN_OTNOH_OTUKOH_BYTE3         = 9,
  TEN_OTNOH_OTUKOH_BYTE4         = 10,
  TEN_OTNOH_OTUKOH_BYTE5         = 11,
  TEN_OTNOH_OTUKOH_BYTE6         = 12,
  TEN_OTNOH_OTUKOH_BYTE7         = 13,
  TEN_OTNOH_OPUKOH_BYTE1         = 14,
  TEN_OTNOH_OPUKOH_BYTE2         = 15,

  TEN_OTNOH_RES_BYTE1            = 16,
  TEN_OTNOH_RES_BYTE2            = 17,
  TEN_OTNOH_RES_BYTE3            = 18,
  TEN_OTNOH_TCMACT               = 19,
  TEN_OTNOH_TCM6_BYTE1           = 20,
  TEN_OTNOH_TCM6_BYTE2           = 21,
  TEN_OTNOH_TCM6_BYTE3           = 22,
  TEN_OTNOH_TCM5_BYTE1           = 23,
  TEN_OTNOH_TCM5_BYTE2           = 24,
  TEN_OTNOH_TCM5_BYTE3           = 25,
  TEN_OTNOH_TCM4_BYTE1           = 26,
  TEN_OTNOH_TCM4_BYTE2           = 27,
  TEN_OTNOH_TCM4_BYTE3           = 28,
  TEN_OTNOH_FTFL                 = 29,
  TEN_OTNOH_OPUKOH_BYTE3         = 30,
  TEN_OTNOH_OPUKOH_BYTE4         = 31,

  TEN_OTNOH_TCM3_BYTE1           = 32,
  TEN_OTNOH_TCM3_BYTE2           = 33,
  TEN_OTNOH_TCM3_BYTE3           = 34,
  TEN_OTNOH_TCM2_BYTE1           = 35,
  TEN_OTNOH_TCM2_BYTE2           = 36,
  TEN_OTNOH_TCM2_BYTE3           = 37,
  TEN_OTNOH_TCM1_BYTE1           = 38,
  TEN_OTNOH_TCM1_BYTE2           = 39,
  TEN_OTNOH_TCM1_BYTE3           = 40,
  TEN_OTNOH_PM_BYTE1             = 41,
  TEN_OTNOH_PM_BYTE2             = 42,
  TEN_OTNOH_PM_BYTE3             = 43,
  TEN_OTNOH_EXP_BYTE1            = 44,
  TEN_OTNOH_EXP_BYTE2            = 45,
  TEN_OTNOH_OPUKOH_BYTE5         = 46,
  TEN_OTNOH_OPUKOH_BYTE6         = 47,

  TEN_OTNOH_GCC1_BYTE1           = 48,
  TEN_OTNOH_GCC1_BYTE2           = 49,
  TEN_OTNOH_GCC2_BYTE1           = 50,
  TEN_OTNOH_GCC2_BYTE2           = 51,
  TEN_OTNOH_APSPCC_BYTE1         = 52,
  TEN_OTNOH_APSPCC_BYTE2         = 53,
  TEN_OTNOH_APSPCC_BYTE3         = 54,
  TEN_OTNOH_APSPCC_BYTE4         = 55,
  TEN_OTNOH_RES_BYTE4            = 56,
  TEN_OTNOH_RES_BYTE5            = 57,
  TEN_OTNOH_RES_BYTE6            = 58,
  TEN_OTNOH_RES_BYTE7            = 59,
  TEN_OTNOH_RES_BYTE8            = 60,
  TEN_OTNOH_RES_BYTE9            = 61,
  TEN_OTNOH_OPUKOH_BYTE7         = 62,
  TEN_OTNOH_OPUKOH_BYTE8         = 63
};

/* Bugzilla 29609 Start */
enum ohpp_stream {
  TEN_OHPP_STREAM_OXU2_1 = 1,
  TEN_OHPP_STREAM_OXU2_2 = 2,
  TEN_OHPP_STREAM_OXU2_3 = 3,
  TEN_OHPP_STREAM_OXU2_4 = 4,
  TEN_OHPP_STREAM_OXU3   = 5
};
/* Bugzilla 29609 End */

#ifdef __cplusplus
}  /* extern C */
#endif
#endif

