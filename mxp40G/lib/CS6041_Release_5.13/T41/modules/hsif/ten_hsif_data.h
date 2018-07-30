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
 * ten_hsif_data.h
 *
 * HSIF header related code is implemented here.
 *
 * $Id: ten_hsif_data.h,v 1.5 2013/02/22 20:49:56 jccarlis Exp $
 *
 */
 
#ifndef __TEN_HSIF_DATA_H__
#define __TEN_HSIF_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

enum ten_hsif_reset_enums {
  TEN_HSIF_RESET_TX_MASTER  = 0x0001,
  TEN_HSIF_RESET_TX_SFI5    = 0x0002,
  TEN_HSIF_RESET_TX_SFI41   = 0x0004,
  TEN_HSIF_RESET_TX_SFI42_0 = 0x0010,
  TEN_HSIF_RESET_TX_SFI42_1 = 0x0020,
  TEN_HSIF_RESET_TX_SFI42_2 = 0x0040,
  TEN_HSIF_RESET_TX_SFI42_3 = 0x0080,
  TEN_HSIF_RESET_RX_MASTER  = 0x0100,
  TEN_HSIF_RESET_RX_SFI5    = 0x0200,
  TEN_HSIF_RESET_RX_SFI41   = 0x0400,
  TEN_HSIF_RESET_RX_SFI42_0 = 0x1000,
  TEN_HSIF_RESET_RX_SFI42_1 = 0x2000,
  TEN_HSIF_RESET_RX_SFI42_2 = 0x4000,
  TEN_HSIF_RESET_RX_SFI42_3 = 0x8000,
  TEN_HSIF_RESET_ALL        = 0xF7F7
};

enum ten_hsif_clk_40g_enums {
  TEN_HSIF_CLK_40G_RXSEL        = 0,
  TEN_HSIF_CLK_40G_RX_AGGR_MODE = 1,
  TEN_HSIF_CLK_40G_TXSEL        = 2,
  TEN_HSIF_CLK_40G_TX_AGGR_MODE = 3
};

enum ten_hsif_ok_ctrl_enums {
  TEN_HSIF_OK_CTRL_XLOS_EN     = 0,
  TEN_HSIF_OK_CTRL_LOCK_EN     = 1,
  TEN_HSIF_OK_CTRL_DATADET_EN  = 2,
  TEN_HSIF_OK_CTRL_SYNCED_EN   = 3
};

enum ten_hsif_refclk_cfg_enums {
  TEN_HSIF_REFCLK_CFG_SPARE         = 0,
  TEN_HSIF_REFCLK_CFG_CKREFDIV      = 1,
  TEN_HSIF_REFCLK_CFG_LOOPCKSEL     = 2,
  TEN_HSIF_REFCLK_CFG_SFI5PILOT_SEL = 3,
  TEN_HSIF_REFCLK_CFG_ALL           = 4 
};

enum ten_hsif_datapath_prov_e {
  TEN_HSIF_DATAPATH_PROV_MRPROTOCOL = 0,
  TEN_HSIF_DATAPATH_PROV_XFISELECT  = 1
};

/* Bugzilla 23772 Start */
enum ten_hsif_prbs_pn_e {
  TEN_HSIF_PRBS_PN31 = 0,
  TEN_HSIF_PRBS_PN23 = 1,
  TEN_HSIF_PRBS_PN15 = 2,
  TEN_HSIF_PRBS_PN7  = 3,
  TEN_HSIF_PRBS_PN9  = 4
};


enum ten_hsif_mr_data_source_e {
  TEN_HSIF_MR_DATASOURCE_DIG_TX_DIN = 0,
  TEN_HSIF_MR_DATASOURCE_PRBS = 1,
  TEN_HSIF_MR_DATASOURCE_RX_LOOPBACK = 2
};
/* Bugzilla 23772 End */


#ifdef __cplusplus
}
#endif
#endif

