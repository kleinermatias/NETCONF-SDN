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
 * ten_pp40g_data.h
 *
 * PP40G defines
 *
 * $Id: ten_pp40g_data.h,v 1.7 2014/03/24 00:09:49 pptawade Exp $
 *
 */
 
#ifndef __TEN_PP40G_DATA_H__
#define __TEN_PP40G_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

enum ten_pp40g_lif_rx_e {
  TEN_PP40G_LIF_RX_SELECT_OVERFLOW3S                 = 1,
  TEN_PP40G_LIF_RX_SELECT_OVERFLOW2S                 = 2,
  TEN_PP40G_LIF_RX_SELECT_OVERFLOW1S                 = 3,
  TEN_PP40G_LIF_RX_SELECT_OVERFLOW0S                 = 4,
  TEN_PP40G_LIF_RX_SELECT_OVERFLOWXS                 = 5,
  TEN_PP40G_LIF_RX_SELECT_ALL                        = 0xFF
};

enum ten_pp40g_pcs_rx_amstatus_e {
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID3          = 1,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID2          = 2,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID1          = 3,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID0          = 4,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEIDX          = 5,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK3       = 6,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK2       = 7,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK1       = 8,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK0       = 9,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCKX       = 10,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK3       = 11,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK2       = 12,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK1       = 13,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK0       = 14,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCKX       = 15,
  TEN_PP40G_PCS_RX_AMSTATUS_SELECT_ALL               = 0xFF
};

enum ten_pp40g_pcs_rx_amstatus1_e {
  TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK3       = 1,
  TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK2       = 2,
  TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK1       = 3,
  TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK0       = 4,
  TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCKX       = 5,
  TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_ALL              = 0xFF
};

enum ten_pp40g_pcs_rx_intstatus_e {
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_SKEWHIGHS        = 1,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_PATDETECTS       = 2,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_BERHIGHS         = 3,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_XDCAMSTATUSS     = 4,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_XDCBLOCKLOCKS    = 5,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_MONOAMSTATUSS    = 6,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_MONOBLOCKLOCKS   = 7,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEALIGNSTATUSS = 8,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEAMSTATUSS    = 9,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK3S  = 10,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK2S  = 11,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK1S  = 12,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK0S  = 13,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCKXS  = 14,
  TEN_PP40G_PCS_RX_INTSTATUS_SELECT_ALL              = 0xFF
};

/* Bugzilla 29751 Start */
enum ten_pp40g_pcs_rx_int_e {
  TEN_PP40G_PCS_RX_INTERRUPT_LANEBLOCKLOCK0I  = 0x0001,
  TEN_PP40G_PCS_RX_INTERRUPT_LANEBLOCKLOCK1I  = 0x0002,
  TEN_PP40G_PCS_RX_INTERRUPT_LANEBLOCKLOCK2I  = 0x0004,
  TEN_PP40G_PCS_RX_INTERRUPT_LANEBLOCKLOCK3I  = 0x0008,
  TEN_PP40G_PCS_RX_INTERRUPT_LANEAMSTATUSI    = 0x0010,
  TEN_PP40G_PCS_RX_INTERRUPT_LANEALIGNSTATUSI = 0x0020,
  TEN_PP40G_PCS_RX_INTERRUPT_MONOBLOCKLOCKI   = 0x0040,
  TEN_PP40G_PCS_RX_INTERRUPT_MONOAMSTATUSI    = 0x0080,
  TEN_PP40G_PCS_RX_INTERRUPT_XDCBLOCKLOCKI    = 0x0100,
  TEN_PP40G_PCS_RX_INTERRUPT_XDCAMSTATUSI     = 0x0200,
  TEN_PP40G_PCS_RX_INTERRUPT_BERHIGHI         = 0x0400,
  TEN_PP40G_PCS_RX_INTERRUPT_ERRORDECI        = 0x0800,
  TEN_PP40G_PCS_RX_INTERRUPT_PATDETECTI       = 0x1000,
  TEN_PP40G_PCS_RX_INTERRUPT_SKEWHIGHI        = 0x2000,
  TEN_PP40G_PCS_RX_INTERRUPT_ALL              = 0x3FFF
};
/* Bugzilla 29751 End */

enum ten_pp40g_rs_rx_intstatus_e {
  TEN_PP40G_RS_RX_INTSTATUS_SELECT_RFS               = 1,
  TEN_PP40G_RS_RX_INTSTATUS_SELECT_LFS               = 2,
  TEN_PP40G_RS_RX_INTSTATUS_SELECT_UNKNOWNORDS       = 3,
  TEN_PP40G_RS_RX_INTSTATUS_SELECT_REMOTEORDS        = 4,
  TEN_PP40G_RS_RX_INTSTATUS_SELECT_LOCALORDS         = 5,
  TEN_PP40G_RS_RX_INTSTATUS_SELECT_ALL               = 0xFF
};

enum ten_pp40g_pcs_tx_intstatus_e {
  TEN_PP40G_PCS_TX_INTSTATUS_SELECT_IDLE_REQS        = 1,
  TEN_PP40G_PCS_TX_INTSTATUS_SELECT_RF_REQS          = 2,
  TEN_PP40G_PCS_TX_INTSTATUS_SELECT_LF_REQS          = 3,
  TEN_PP40G_PCS_TX_INTSTATUS_SELECT_ALL              = 0xFF
};

/* Bugzilla 43359 Start */
enum ten_pp40g_tx_sub_block_e {
  TEN_PP40G_TX_BLK_PBT       = 1,        /* PBERT */
  TEN_PP40G_TX_BLK_PCS_PRA   = 2,        /* PCS Positive Rate Adjust */
  TEN_PP40G_TX_BLK_PCS_BDB   = 4,        /* PCS Block Distribution */
  TEN_PP40G_TX_BLK_PCS_MGB   = 8,        /* PCS Mono Gearbox */
  TEN_PP40G_TX_BLK_PCS_XEC   = 16,       /* PCS Trans-encoder */
  TEN_PP40G_TX_BLK_PCS_FPG   = 32,       /* PCS Frame Pulse Generator */
  TEN_PP40G_TX_BLK_PCS_ITP   = 64,       /* PCS Idle Test Pattern Generator */
  TEN_PP40G_TX_BLK_PCS_BIL   = 128       /* PCS Bit Interleaver */  
};

enum ten_pp40g_rx_sub_block_e {
  TEN_PP40G_RX_BLK_LIF          = 1,     /* PCS Line Function */ 
  TEN_PP40G_RX_BLK_PCS_DIL      = 2,     /* PCS Bit Deinterleaver*/ 
  TEN_PP40G_RX_BLK_PCS_LBA      = 4,     /* PCS Lane Block and Marker Aligner */ 
  TEN_PP40G_RX_BLK_PCS_LDS      = 8,     /* PCS Lane Deskew */ 
  TEN_PP40G_RX_BLK_PCS_LRO      = 16,    /* PCS Lane Reorder */   
  TEN_PP40G_RX_BLK_PCS_MBA      = 32,    /* PCS Mono Block and Marker Aligner */ 
  TEN_PP40G_RX_BLK_PCS_XDC      = 64,    /* PCS Trans-Decoder*/ 
  TEN_PP40G_RX_BLK_PCS_BDS_RXI  = 128,   /* PCS 64b/66b Descrambler for Datapath to XCON */ 
  TEN_PP40G_RX_BLK_PCS_BDS_BDC  = 256,   /* PCS 64b/66b Descrambler for Non-intrusive Monitoring */ 
  TEN_PP40G_RX_BLK_PCS_BDC      = 512,   /* PCS 64b/66b Decoder */ 
  TEN_PP40G_RX_BLK_PCS_TPC      = 1024,  /* PCS Test Patter Checker */ 
  TEN_PP40G_RX_BLK_PCS_NRA      = 2048,  /* PCS Negative Rate Adjust */
  TEN_PP40G_RX_BLK_RS           = 4096,  /* RS */ 
  TEN_PP40G_RX_BLK_MAC          = 8192,  /* MAC */ 
};
/* Bugzilla 43359 End */


#ifdef __cplusplus
}
#endif
#endif
