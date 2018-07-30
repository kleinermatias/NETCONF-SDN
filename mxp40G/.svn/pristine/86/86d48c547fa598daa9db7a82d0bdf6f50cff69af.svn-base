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
 * ten_hl_config_data.h
 *
 * Data Header file for HL Config defines.
 *
 * $Id: ten_hl_config_data.h,v 1.37 2014/04/02 19:08:33 pptawade Exp $
 *
 */
 
#ifndef __TEN_HL_CONFIG_DATA_H__
#define __TEN_HL_CONFIG_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

enum ten_hl_config_traffic_types_e {
  TEN_TRAFFIC_TYPE_NONE                 = 0,
  TEN_TRAFFIC_TYPE_DISABLE              = 0,
  TEN_TRAFFIC_TYPE_OTU3                 = 1,
  TEN_TRAFFIC_TYPE_OTU3E                = 2,          /* Preserved for backward compatibility */
  TEN_TRAFFIC_TYPE_OTU3E1               = 2,
  TEN_TRAFFIC_TYPE_OTU3P                = 3,
  TEN_TRAFFIC_TYPE_ODTU23               = 4,
  TEN_TRAFFIC_TYPE_OTU2                 = 5,
  TEN_TRAFFIC_TYPE_OTU2E                = 6,
  TEN_TRAFFIC_TYPE_OTU1F                = 7,
  TEN_TRAFFIC_TYPE_OC192                = 8,
  TEN_TRAFFIC_TYPE_10GE_WAN             = 9,
  TEN_TRAFFIC_TYPE_10GE_6_2             = 10,
  TEN_TRAFFIC_TYPE_10GE_7_1             = 11,
  TEN_TRAFFIC_TYPE_10GE_7_3             = 12,
  TEN_TRAFFIC_TYPE_10GFC                = 13,
  TEN_TRAFFIC_TYPE_8GFC                 = 14,
  TEN_TRAFFIC_TYPE_4GFC                 = 15,
  TEN_TRAFFIC_TYPE_2GFC                 = 16,
  TEN_TRAFFIC_TYPE_1GFC                 = 17,
  TEN_TRAFFIC_TYPE_5GB_IB               = 18,
  TEN_TRAFFIC_TYPE_OTU3_NOFEC           = 19,         /* Don't use for T41 */
  TEN_TRAFFIC_TYPE_10GE                 = 20,
  TEN_TRAFFIC_TYPE_40GELAN              = 21,
  TEN_TRAFFIC_TYPE_OC768                = 22,
  TEN_TRAFFIC_TYPE_OTU3E3               = 23,
  TEN_TRAFFIC_TYPE_CBR40G_50188149150   = 24,
  /* Bugzilla 20308 Start */
  TEN_TRAFFIC_TYPE_OTU3P2               = 25,
  TEN_TRAFFIC_TYPE_10GE_6_1             = 26,
  TEN_TRAFFIC_TYPE_10GE_7_2             = 27,
  TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28,
  TEN_TRAFFIC_TYPE_OTU1E                = 29,
  /* Bugzilla 20308 End */
  /* Bugzilla 22237 Start */
  TEN_TRAFFIC_TYPE_10GE_RA              = 30,
  /* Bugzilla 22237 End */
  /* Bugzilla 22970 Start */
  TEN_TRAFFIC_TYPE_OC192_OTU2           = 31,      /* Used for KPG inside OC192 inside OTU2 */
  TEN_TRAFFIC_TYPE_OC768_OTU3           = 32,      /* Used for KPG inside OC768 inside OTU3 */
  /* Bugzilla 22970 End */
  TEN_TRAFFIC_TYPE_10GE_TC = 33,
  TEN_TRAFFIC_TYPE_OTU2F                = 34,
  TEN_TRAFFIC_TYPE_OTU3E2               = 35,
  TEN_TRAFFIC_TYPE_OTU2P                = 36,
  TEN_TRAFFIC_TYPE_ODUFLEX              = 37, 
  TEN_TRAFFIC_TYPE_ODTU                 = 38,
  TEN_TRAFFIC_TYPE_10G_IB               = 39,
  TEN_TRAFFIC_TYPE_12_5G_IB             = 40,
  TEN_TRAFFIC_TYPE_SERIAL_40GE          = 41,
  TEN_TRAFFIC_TYPE_PARALLEL_40GE        = 42,
  TEN_TRAFFIC_TYPE_TC_40GE              = 43,
  TEN_TRAFFIC_TYPE_S64_66_40GE          = 44,
  /* Bugzilla 24360 Start */
  TEN_TRAFFIC_TYPE_BYPASS               = 45,
  TEN_TRAFFIC_TYPE_10GFC_TC             = 46,
  /* Bugzilla 24360 End */
  TEN_TRAFFIC_TYPE_8GFC_RA              = 47,
  TEN_TRAFFIC_TYPE_4GFC_RA              = 48,
  TEN_TRAFFIC_TYPE_2GFC_RA              = 49,
  TEN_TRAFFIC_TYPE_1GFC_RA              = 50,
  TEN_TRAFFIC_TYPE_8GFC_ENH             = 51,
  TEN_TRAFFIC_TYPE_4GFC_ENH             = 52,
  TEN_TRAFFIC_TYPE_2GFC_ENH             = 53,
  TEN_TRAFFIC_TYPE_1GFC_ENH             = 54,
  TEN_TRAFFIC_TYPE_OTU3E4               = 55, /* Bugzilla 28237 */
  TEN_TRAFFIC_TYPE_10GE_GFPF            = 56, /* Bugzilla 29991 */
  TEN_TRAFFIC_TYPE_10GFC_TC_G709        = 57, /* Bug 31054 */
  TEN_TRAFFIC_TYPE_10GFC_TC_RA          = 58,
  TEN_TRAFFIC_TYPE_2GISC                = 59,
  TEN_TRAFFIC_TYPE_1GE                  = 63, /* Bugzilla 38871 */
  TEN_TRAFFIC_TYPE_FDR10_IB             = 64, /* Bugzilla 39242 */
  TEN_TRAFFIC_TYPE_CPRI_4               = 65, /* Bugzilla 39690 */
  TEN_TRAFFIC_TYPE_OTU2EX4              = 66, /* Bugzilla 43359 */
  TEN_TRAFFIC_TYPE_CBR_10G              = 67, /* Bugzilla 43573 */
  TEN_TRAFFIC_TYPE_MAX
};

enum ten_hl_config_payload_types_e {
  TEN_PAYLOAD_TYPE_EXPERIMENTAL            = 0x01,
  TEN_PAYLOAD_TYPE_ASYNC_CBR               = 0x02, /* Sonet->OTU2, 10GE6_1->OTU2 or 10GE7_1->OTU2e */
  TEN_PAYLOAD_TYPE_SYNC_CBR                = 0x03, /* Sonet->OTU2 or 10GE7_1->OTU2e or 10GFC_TC->OTU2 */
  TEN_PAYLOAD_TYPE_ATM                     = 0x04,
  TEN_PAYLOAD_TYPE_GFP                     = 0x05, /* 10GE6_2->OTU2 or 10GE_TC->OTU2 */
  TEN_PAYLOAD_TYPE_VIRTUAL_CONCAT          = 0x06,
  TEN_PAYLOAD_TYPE_40GBASE_R               = 0x07, /* 40GE->OTU3  */
  TEN_PAYLOAD_TYPE_FC_1200_OTU2E           = 0x08, /* 10GFC->OTU2e */
  TEN_PAYLOAD_TYPE_10G_GFP_EXT_OTU2        = 0x09,  /* 10GE7_3->OTU2 or 10GE_RA->OTU2 */
  TEN_PAYLOAD_TYPE_FC_400_ODUFEX           = 0x0E, 
  TEN_PAYLOAD_TYPE_FC_800_ODUFEX           = 0x0f, 
  TEN_PAYLOAD_TYPE_BITSTREAM_WITH_OCTET    = 0x10, 
  TEN_PAYLOAD_TYPE_BITSTREAM_WITHOUT_OCTET = 0x11, 
  TEN_PAYLOAD_TYPE_ODU_MUX                 = 0x20, /* ODU->ODTUjk (AMP 2.5G time slots) */
  TEN_PAYLOAD_TYPE_ODU_ODTUK_MUX           = 0x21,  /* ODU->ODTUk.ts (AMP 1.25G time slots or GMP) */
  TEN_PAYLOAD_TYPE_10GE7_3                 = 0x80,  /* 10GE7_3->OTU1e */
  TEN_PAYLOAD_TYPE_CORTINA_MAPPING         = 0x81,  /* ??????? */
  TEN_PAYLOAD_TYPE_NULL                    = 0xFD,
  TEN_PAYLOAD_TYPE_PRBS                    = 0xFE /* KPGA payload */
};

/* Bugzilla 22516 Start */
enum ten_hl_config_dyn_repro_enums {
  TEN_INITIAL_CONFIG        = 0x0000,
  TEN_REPRO_CLIENT          = 0x0001,
  TEN_REPRO_LINE_AND_CLIENT = 0x0002
};
/* Bugzilla 22516 End */

enum ten_hl_config_otu_overhead_term_enums {
  TEN_OTU_TERM_TRANSPARENT = 0x0000,
  TEN_OTU_TERM_SECTION     = 0x0001,
  TEN_OTU_TERM_FULL        = 0x0002
};

enum ten_hl_config_oc192_overhead_term_enums {
  TEN_OC192_TERM_TRANSPARENT_CBR10       = 1,
  TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2,
  TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3,
  TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4
};

enum ten_hl_config_sync_type_enums {
  TEN_MAP_BMP          = 1,         /* Bit Synchronous Mapping Protocol */
  TEN_MAP_AMP          = 0,         /* Asynchronous Mapping Protocol */
  TEN_MAP_AMP_DT       = 2,         /* Asynchronous Deterministic Mapping Protocol */
  TEN_MAP_AMP_PROP     = 3,         /* Asynchronous Proprietary Mapping Protocol */
  TEN_MAP_AMP_PROP_DT  = 4,         /* Asynchronous Proprietary Deterministic Mapping Protocol */
  TEN_MAP_GMP_LO       = 5,         /* Generic Low Order Mapping Protocol */
  TEN_MAP_GMP_HO       = 6,         /* Generic High Order Mapping Protocol */
  TEN_MAP_GMP_HO_DT    = 7,         /* Generic High Order Deterministic Mapping Protocol */
  TEN_MAP_DONT_CARE    = 0xFF,
  TEN_MAX_SYNC_MODE
  };

enum ten_hl_syncdsync_mode_e {
  TEN_OXU2_MONO_ONE_LEVEL       = 0,
  TEN_OXU3_MONO_ONE_LEVEL       = 1,
  TEN_ODTU23_MUX_ONE_LEVEL      = 2,
  TEN_ODTU23_ODU2_MUX_TWO_LEVEL = 3
};

/* Bugzilla 24360 Start */
enum ten_hl_tributary_slot_bw_enums {
  TEN_TRIB_SLOT_BW_1_25 = 0,
  TEN_TRIB_SLOT_BW_2_5  = 1
};
/* Bugzilla 24360 End */

enum ten_hl_odu_type_enums {
  TEN_TRAFFIC_TYPE_ODU1E   = 0,
  TEN_TRAFFIC_TYPE_ODU1F   = 1,
  TEN_TRAFFIC_TYPE_ODU2    = 2,
  TEN_TRAFFIC_TYPE_ODU2E   = 3
};

#ifdef __cplusplus
}
#endif
#endif


