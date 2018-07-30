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
 * ten_mpif_data.h
 *
 * $Id: ten_mpif_data.h,v 1.4 2013/02/22 20:48:36 jccarlis Exp $
 *
*/

#ifndef __TEN_MPIF_DATA_H__
#define __TEN_MPIF_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

#define TEN_MPIF_SYS_CLOCK_MAX (435000000)
#define TEN_MPIF_SYS_CLOCK_MIN (300000000)


enum ten_mpif_global_reset_gfec_10g_enums {
  TEN_MPIF_GLOBAL_GFEC_10G_0   = 0x0001,
  TEN_MPIF_GLOBAL_GFEC_10G_1   = 0x0002,
  TEN_MPIF_GLOBAL_GFEC_10G_2   = 0x0004,
  TEN_MPIF_GLOBAL_GFEC_10G_ALL = 0x0007
};

enum ten_mpif_global_reset_gfec_40g_enums {
  TEN_MPIF_GLOBAL_GFEC_40G_0   = 0x0001,
  TEN_MPIF_GLOBAL_GFEC_40G_1   = 0x0002,
  TEN_MPIF_GLOBAL_GFEC_40G_ALL = 0x0003
};

enum ten_mpif_global_reset_ufec_enums {
  TEN_MPIF_GLOBAL_UFEC_0   = 0x0001,
  TEN_MPIF_GLOBAL_UFEC_1   = 0x0002,
  TEN_MPIF_GLOBAL_UFEC_2   = 0x0004,
  TEN_MPIF_GLOBAL_UFEC_3   = 0x0008,
  TEN_MPIF_GLOBAL_UFEC_ALL = 0x000F
};

enum ten_mpif_global_reset_clock_loss_enums {
  TEN_MPIF_GLOBAL_RESET_CLOCK_LOSS_0   = 0x0001,
  TEN_MPIF_GLOBAL_RESET_CLOCK_LOSS_1   = 0x0002,
  TEN_MPIF_GLOBAL_RESET_CLOCK_LOSS_2   = 0x0004,
  TEN_MPIF_GLOBAL_RESET_CLOCK_LOSS_3   = 0x0008,
  TEN_MPIF_GLOBAL_RESET_CLOCK_LOSS_ALL = 0x000F
};

enum ten_mpif_global_reset_sds_xfi_enums {
  TEN_MPIF_GLOBAL_RESET_SDS_RX   = 0x000F,
  TEN_MPIF_GLOBAL_RESET_SDS_TX   = 0x00F0,
  TEN_MPIF_GLOBAL_RESET_SDS_MPIF = 0x0F00,
  TEN_MPIF_GLOBAL_RESET_SDS_ALL  = 0x0FFF
};

enum ten_mpif_global_reset_common_enums {
  TEN_MPIF_GLOBAL_RESET_COMMON_CHIP    = 0x0001,
  TEN_MPIF_GLOBAL_RESET_COMMON_XCON    = 0x0002,
  TEN_MPIF_GLOBAL_RESET_COMMON_SPOH    = 0x0004,
  TEN_MPIF_GLOBAL_RESET_COMMON_OHPP_A  = 0x0008,
  TEN_MPIF_GLOBAL_RESET_COMMON_OHPP_B  = 0x0010,
  TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS  = 0x0020,
  TEN_MPIF_GLOBAL_RESET_COMMON_CLKLOSS = 0x0080,
  TEN_MPIF_GLOBAL_RESET_COMMON_MPIF    = 0x0100,
  TEN_MPIF_GLOBAL_RESET_COMMON_ALL     = 0x01BF
};

enum ten_mpif_global_clock_disable_common_enums {
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON   = 0x0001,
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_SPOH   = 0x0002,
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_OHPP_A = 0x0004,
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_OHPP_B = 0x0008,
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_ALL    = 0x000F
};

enum ten_mpif_n40g_n10g_e {
  TEN_MPIF_N40G_DATAPATH = 0,
  TEN_MPIF_N10G_DATAPATH = 1,
  TEN_MPIF_XAUI_DATAPATH = 2
};

enum ten_mpif_lvds_pd_e {
  TEN_MPIF_LVDS_PD_SELECT_RXREF                      = 1,
  TEN_MPIF_LVDS_PD_SELECT_SYSREF                     = 2,
  TEN_MPIF_LVDS_PD_SELECT_OHPPO_B                    = 3,
  TEN_MPIF_LVDS_PD_SELECT_OHPPI_B                    = 4,
  TEN_MPIF_LVDS_PD_SELECT_OHPPO_A                    = 5,
  TEN_MPIF_LVDS_PD_SELECT_OHPPI_A                    = 6,
  TEN_MPIF_LVDS_PD_SELECT_OHPPO_B_OHPPI_B_SYSREF     = 7,
  TEN_MPIF_LVDS_PD_SELECT_OHPPO_A_OHPPI_A_SYSREF     = 8,
  TEN_MPIF_LVDS_PD_SELECT_ALL_EXCEPT_RXREF           = 9,
  TEN_MPIF_LVDS_PD_SELECT_ALL                        = 0xFF
};

#ifdef __cplusplus
}                               /* extern C */
#endif                          /* __cplusplus */
#endif /* __TEN_MPIF_DATA_H__ */





