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
 * ten_stats_tables.c
 *
 * $Id: ten_stats_tables.c,v 1.13 2013/02/22 20:48:50 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/******************************************************************************
 * SYNCDSYNC SLICE 0 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_syncdsync_0[TEN_SYNCDSYNC_MAX_STAT] = {
  {
    "cfgmon odtu23 pjo",
    TEN_SYNCDSYNCTX_REG_OFST(ODTU23_PJO1, 0),
    TEN_SYNCDSYNCRX_REG_OFST(ODTU23_PJO1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon odtu23 njo",
    TEN_SYNCDSYNCTX_REG_OFST(ODTU23_NJO1, 0),
    TEN_SYNCDSYNCRX_REG_OFST(ODTU23_NJO1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon oxun pjo",
    TEN_SYNCDSYNCTX_REG_OFST(OXUN_PJO1, 0),
    TEN_SYNCDSYNCRX_REG_OFST(OXUN_PJO1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon oxun njo",
    TEN_SYNCDSYNCTX_REG_OFST(OXUN_NJO1, 0),
    TEN_SYNCDSYNCRX_REG_OFST(OXUN_NJO1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
};

/******************************************************************************
 * SYNCDSYNC SLICE 1 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_syncdsync_1[TEN_SYNCDSYNC_MAX_STAT] = {
  {
    "cfgmon odtu23 pjo",
    TEN_SYNCDSYNCTX_REG_OFST(ODTU23_PJO1, 1),
    TEN_SYNCDSYNCRX_REG_OFST(ODTU23_PJO1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon odtu23 njo",
    TEN_SYNCDSYNCTX_REG_OFST(ODTU23_NJO1, 1),
    TEN_SYNCDSYNCRX_REG_OFST(ODTU23_NJO1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon oxun pjo",
    TEN_SYNCDSYNCTX_REG_OFST(OXUN_PJO1, 1),
    TEN_SYNCDSYNCRX_REG_OFST(OXUN_PJO1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon oxun njo",
    TEN_SYNCDSYNCTX_REG_OFST(OXUN_NJO1, 1),
    TEN_SYNCDSYNCRX_REG_OFST(OXUN_NJO1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
};

/******************************************************************************
 * SYNCDSYNC SLICE 2 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_syncdsync_2[TEN_SYNCDSYNC_MAX_STAT] = {
  {
    "cfgmon odtu23 pjo",
    TEN_SYNCDSYNCTX_REG_OFST(ODTU23_PJO1, 2),
    TEN_SYNCDSYNCRX_REG_OFST(ODTU23_PJO1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon odtu23 njo",
    TEN_SYNCDSYNCTX_REG_OFST(ODTU23_NJO1, 2),
    TEN_SYNCDSYNCRX_REG_OFST(ODTU23_NJO1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon oxun pjo",
    TEN_SYNCDSYNCTX_REG_OFST(OXUN_PJO1, 2),
    TEN_SYNCDSYNCRX_REG_OFST(OXUN_PJO1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon oxun njo",
    TEN_SYNCDSYNCTX_REG_OFST(OXUN_NJO1, 2),
    TEN_SYNCDSYNCRX_REG_OFST(OXUN_NJO1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
};

/******************************************************************************
 * SYNCDSYNC SLICE 3 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_syncdsync_3[TEN_SYNCDSYNC_MAX_STAT] = {
  {
    "cfgmon odtu23 pjo",
    TEN_SYNCDSYNCTX_REG_OFST(ODTU23_PJO1, 3),
    TEN_SYNCDSYNCRX_REG_OFST(ODTU23_PJO1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon odtu23 njo",
    TEN_SYNCDSYNCTX_REG_OFST(ODTU23_NJO1, 3),
    TEN_SYNCDSYNCRX_REG_OFST(ODTU23_NJO1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon oxun pjo",
    TEN_SYNCDSYNCTX_REG_OFST(OXUN_PJO1, 3),
    TEN_SYNCDSYNCRX_REG_OFST(OXUN_PJO1, 3),
    4, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
  
  {
    "cfgmon oxun njo",
    TEN_SYNCDSYNCTX_REG_OFST(OXUN_NJO1, 3),
    TEN_SYNCDSYNCRX_REG_OFST(OXUN_NJO1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_SYNCDSYNC  /* block active check */
  },
};

/******************************************************************************
 * HSIF MR SLC0 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_hsif_slc0[TEN_HSIF_MR_SLC0_MAX_STAT] = {
  {
    "mr slc0 mr10x4 sds common prbschk0 count",
    0,
    TEN_HSIF_MR10X4_SLC0_REG_OFST(PRBSCHK0_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc0 mr10x4 sds common prbschk1 count",
    0,
    TEN_HSIF_MR10X4_SLC0_REG_OFST(PRBSCHK1_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc0 mr10x4 sds common prbschk2 count",
    0,
    TEN_HSIF_MR10X4_SLC0_REG_OFST(PRBSCHK2_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR   /* block active check */
  },
  
  {
    "mr slc0 mr10x4 sds common prbschk3 count",
    0,
    TEN_HSIF_MR10X4_SLC0_REG_OFST(PRBSCHK3_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR   /* block active check */
  }
};

/******************************************************************************
 * HSIF MR SLC1 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_hsif_slc1[TEN_HSIF_MR_SLC1_MAX_STAT] = {
  {
    "mr slc1 mr10x5 sds common prbschk0 count",
    0,
    TEN_HSIF_MR10X5_SLC1_REG_OFST(PRBSCHK0_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc1 mr10x5 sds common prbschk1 count",
    0,
    TEN_HSIF_MR10X5_SLC1_REG_OFST(PRBSCHK1_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc1 mr10x5 sds common prbschk2 count",
    0,
    TEN_HSIF_MR10X5_SLC1_REG_OFST(PRBSCHK2_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc1 mr10x5 sds common prbschk3 count",
    0,
    TEN_HSIF_MR10X5_SLC1_REG_OFST(PRBSCHK3_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc1 mr10x5 sds common prbschk4 count",
    0,
    TEN_HSIF_MR10X5_SLC1_REG_OFST(PRBSCHK4_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  }
};

/******************************************************************************
 * HSIF MR SLC2 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_hsif_slc2[TEN_HSIF_MR_SLC2_MAX_STAT] = {
  {
    "mr slc2 mr10x4 sds common prbschk0 count",
    0,
    TEN_HSIF_MR10X4_SLC2_REG_OFST(mr10x4_sds_common_PRBSCHK0_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc2 mr10x4 sds common prbschk1 count",
    0,
    TEN_HSIF_MR10X4_SLC2_REG_OFST(mr10x4_sds_common_PRBSCHK1_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc2 mr10x4 sds common prbschk2 count",
    0,
    TEN_HSIF_MR10X4_SLC2_REG_OFST(mr10x4_sds_common_PRBSCHK2_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc2 mr10x4 sds common prbschk3 count",
    0,
    TEN_HSIF_MR10X4_SLC2_REG_OFST(mr10x4_sds_common_PRBSCHK3_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  }
};

/******************************************************************************
 * HSIF MR SLC3 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_hsif_slc3[TEN_HSIF_MR_SLC3_MAX_STAT] = {
  {
    "mr slc3 mr10x5 sds common prbschk0 count",
    0,
    TEN_HSIF_MR10X5_SLC3_REG_OFST(mr10x5_sds_common_PRBSCHK0_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc3 mr10x5 sds common prbschk1 count",
    0,
    TEN_HSIF_MR10X5_SLC3_REG_OFST(mr10x5_sds_common_PRBSCHK1_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc3 mr10x5 sds common prbschk2 count",
    0,
    TEN_HSIF_MR10X5_SLC3_REG_OFST(mr10x5_sds_common_PRBSCHK2_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc3 mr10x5 sds common prbschk3 count",
    0,
    TEN_HSIF_MR10X5_SLC3_REG_OFST(mr10x5_sds_common_PRBSCHK3_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  },
  
  {
    "mr slc3 mr10x5 sds common prbschk4 count",
    0,
    TEN_HSIF_MR10X5_SLC3_REG_OFST(mr10x5_sds_common_PRBSCHK4_Count1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_MR  /* block active check */
  }
};

/******************************************************************************
 * HSIF XFI STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_hsif_xfi[TEN_HSIF_XFI_MAX_STAT] = {
  {
    "sds xfi32x1 sds common prbschk0 count",
    0,
    TEN_HSIF_XFI32X1_REG_OFST(PRBSCHK0_Count1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_XFI  /* block active check */
  },
  
  {
    "sds xfi32x1 sds common prbschk1 count",
    0,
    TEN_HSIF_XFI32X1_REG_OFST(PRBSCHK0_Count1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_XFI  /* block active check */
  },
  
  {
    "sds xfi32x1 sds common prbschk2 count",
    0,
    TEN_HSIF_XFI32X1_REG_OFST(PRBSCHK0_Count1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_XFI  /* block active check */
  },
  
  {
    "sds xfi32x1 sds common prbschk3 count",
    0,
    TEN_HSIF_XFI32X1_REG_OFST(PRBSCHK0_Count1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    TEN_STATS_CHECK_SDS_XFI  /* block active check */
  }
};

/******************************************************************************
 * XCON 0 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_xcon_0[TEN_XCON_MAX_STAT] = {
  {
    "es fifo overflow cnt 0",
    0,
    TEN_XCON_ES_REG_OFST(FIFO_OVERFLOW_CNT, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },

  {
    "cbert prbs err count 0",
    0,
    TEN_XCON_CBERT_REG_OFST(PRBS_ERR_COUNT, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },
  
  {
    "pbert good/ucnt",
    TEN_XCON_PBERT_REG_OFST(UCNT2, 0),
    TEN_XCON_PBERT_REG_OFST(UGOODCNT2, 0),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID, 
    0  /* block active check */
  },
  
  {
    "pbert good/uocnt",
    TEN_XCON_PBERT_REG_OFST(UOCNT2, 0),
    TEN_XCON_PBERT_REG_OFST(UOGOODCNT2, 0),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UERRCNT2, 0),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uoerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UOERRCNT2, 0),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx prbserrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(PRBSERRCNT2, 0),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
};

/******************************************************************************
 * XCON 1 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_xcon_1[TEN_XCON_MAX_STAT] = {
  
  {
    "es fifo overflow cnt",
    0,
    TEN_XCON_ES_REG_OFST(FIFO_OVERFLOW_CNT, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },

  {
    "cbert prbs err count",
    0,
    TEN_XCON_CBERT_REG_OFST(PRBS_ERR_COUNT, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },
  
  {
    "pbert good/ucnt",
    TEN_XCON_PBERT_REG_OFST(UCNT2, 1),
    TEN_XCON_PBERT_REG_OFST(UGOODCNT2, 1),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert good/uocnt",
    TEN_XCON_PBERT_REG_OFST(UOCNT2, 1),
    TEN_XCON_PBERT_REG_OFST(UOGOODCNT2, 1),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID ,
    0  /* block active check */
  },
  
  {
    "pbert rx uerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UERRCNT2, 1),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uoerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UOERRCNT2, 1),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID ,
    0  /* block active check */
  },
  
  {
    "pbert rx prbserrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(PRBSERRCNT2, 1),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
};

/******************************************************************************
 * XCON 2 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_xcon_2[TEN_XCON_MAX_STAT] = {
  
  {
    "es fifo overflow cnt",
    0,
    TEN_XCON_ES_REG_OFST(FIFO_OVERFLOW_CNT, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },

  {
    "cbert prbs err count",
    0,
    TEN_XCON_CBERT_REG_OFST(PRBS_ERR_COUNT, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },
  
  {
    "pbert good/ucnt",
    TEN_XCON_PBERT_REG_OFST(UCNT2, 2),
    TEN_XCON_PBERT_REG_OFST(UGOODCNT2, 2),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert good/uocnt",
    TEN_XCON_PBERT_REG_OFST(UOCNT2, 2),
    TEN_XCON_PBERT_REG_OFST(UOGOODCNT2, 2),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UERRCNT2, 2),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uoerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UOERRCNT2, 2),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx prbserrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(PRBSERRCNT2, 2),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
};

/******************************************************************************
 * XCON 3 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_xcon_3[TEN_XCON_MAX_STAT] = {
  
  {
    "es fifo overflow cnt",
    0,
    TEN_XCON_ES_REG_OFST(FIFO_OVERFLOW_CNT, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },

  {
    "cbert prbs err count",
    0,
    TEN_XCON_CBERT_REG_OFST(PRBS_ERR_COUNT, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },
  
  {
    "pbert good/ucnt",
    TEN_XCON_PBERT_REG_OFST(UCNT2, 3),
    TEN_XCON_PBERT_REG_OFST(UGOODCNT2, 3),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert good/uocnt",
    TEN_XCON_PBERT_REG_OFST(UOCNT2, 3),
    TEN_XCON_PBERT_REG_OFST(UOGOODCNT2, 3),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UERRCNT2, 3),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uoerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UOERRCNT2, 3),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx prbserrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(PRBSERRCNT2, 3),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
};

/******************************************************************************
 * XCON 4 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_xcon_4[TEN_XCON_MAX_STAT] = {
  
  {
    "es fifo overflow cnt",
    0,
    TEN_XCON_ES_REG_OFST(FIFO_OVERFLOW_CNT, 4),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },

  {
    "cbert prbs err count",
    0,
    TEN_XCON_CBERT_REG_OFST(PRBS_ERR_COUNT, 4),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },
  
  {
    "pbert good/ucnt",
    TEN_XCON_PBERT_REG_OFST(UCNT2, 4),
    TEN_XCON_PBERT_REG_OFST(UGOODCNT2, 4),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */

  },
  
  {
    "pbert good/uocnt",
    TEN_XCON_PBERT_REG_OFST(UOCNT2, 4),
    TEN_XCON_PBERT_REG_OFST(UOGOODCNT2, 4),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UERRCNT2, 4),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uoerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UOERRCNT2, 4),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx prbserrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(PRBSERRCNT2, 4),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
};

/******************************************************************************
 * XCON 5 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_xcon_5[TEN_XCON_MAX_STAT] = {
  
  {
    "es fifo overflow cnt",
    0,
    TEN_XCON_ES_REG_OFST(FIFO_OVERFLOW_CNT, 5),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },

  {
    "cbert prbs err count",
    0,
    TEN_XCON_CBERT_REG_OFST(PRBS_ERR_COUNT, 5),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },
  
  {
    "pbert good/ucnt",
    TEN_XCON_PBERT_REG_OFST(UCNT2, 5),
    TEN_XCON_PBERT_REG_OFST(UGOODCNT2, 5),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID  | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert good/uocnt",
    TEN_XCON_PBERT_REG_OFST(UOCNT2, 5),
    TEN_XCON_PBERT_REG_OFST(UOGOODCNT2, 5),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UERRCNT2, 5),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID ,
    0  /* block active check */
  },
  
  {
    "pbert rx uoerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UOERRCNT2, 5),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID ,
    0  /* block active check */
  },
  
  {
    "pbert rx prbserrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(PRBSERRCNT2, 5),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID ,
    0  /* block active check */
  },
};

/******************************************************************************
 * XCON 6 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_xcon_6[TEN_XCON_MAX_STAT] = {
  
  {
    "es fifo overflow cnt",
    0,
    TEN_XCON_ES_REG_OFST(FIFO_OVERFLOW_CNT, 6),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },

  {
    "cbert prbs err count",
    0,
    TEN_XCON_CBERT_REG_OFST(PRBS_ERR_COUNT, 6),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },
  
  {
    "pbert good/ucnt",
    TEN_XCON_PBERT_REG_OFST(UCNT2, 6),
    TEN_XCON_PBERT_REG_OFST(UGOODCNT2, 6),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */

  },
  
  {
    "pbert good/uocnt",
    TEN_XCON_PBERT_REG_OFST(UOCNT2, 6),
    TEN_XCON_PBERT_REG_OFST(UOGOODCNT2, 6),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID,
    0  /* block active check */
  },
  
  {
    "pbert rx uerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UERRCNT2, 6),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID ,
    0  /* block active check */
  },
  
  {
    "pbert rx uoerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UOERRCNT2, 6),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID ,
    0  /* block active check */
  },
  
  {
    "pbert rx prbserrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(PRBSERRCNT2, 6),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID,
    0  /* block active check */
  },
};

/******************************************************************************
 * XCON 7 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_xcon_7[TEN_XCON_MAX_STAT] = {
  
  {
    "es fifo overflow cnt",
    0,
    TEN_XCON_ES_REG_OFST(FIFO_OVERFLOW_CNT, 7),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },

  {
    "cbert prbs err count",
    0,
    TEN_XCON_CBERT_REG_OFST(PRBS_ERR_COUNT, 7),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR,
    0  /* block active check */
  },
  
  {
    "pbert good/ucnt",
    TEN_XCON_PBERT_REG_OFST(UCNT2, 7),
    TEN_XCON_PBERT_REG_OFST(UGOODCNT2, 7),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID ,
    0  /* block active check */
  },
  
  {
    "pbert good/uocnt",
    TEN_XCON_PBERT_REG_OFST(UOCNT2, 7),
    TEN_XCON_PBERT_REG_OFST(UOGOODCNT2, 7),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TX_VALID ,
    0  /* block active check */
  },
  
  {
    "pbert rx uerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UERRCNT2, 7),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID ,
    0  /* block active check */
  },
  
  {
    "pbert rx uoerrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(UOERRCNT2, 7),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID ,
    0  /* block active check */
  },
  
  {
    "pbert rx prbserrcnt",
    0,
    TEN_XCON_PBERT_REG_OFST(PRBSERRCNT2, 7),
    3, /* 48 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID ,
    0  /* block active check */
  },
};

/******************************************************************************
 * GFEC40G STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_gfec40g[TEN_GFEC40G_MAX_STAT] = {
  {
    "frx40 rzbter",
    0,
    TEN_GFEC40G_REG_OFST(RZBTER0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC40G  /* block active check */
  },
  
  {
    "frx40 robter",
    0,
    TEN_GFEC40G_REG_OFST(ROBTER0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC40G  /* block active check */
  },
  
  {
    "frx40 rbyter",
    0,
    TEN_GFEC40G_REG_OFST(RBYTER0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC40G  /* block active check */
  },
  
  {
    "frx40 rerrov",
    0,
    TEN_GFEC40G_REG_OFST(RERROV0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC40G  /* block active check */
  },
};

  
/******************************************************************************
 * GFEC10G STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_gfec10g_0[TEN_GFEC10G_MAX_STAT] = {
  {
    "frx rzbter",
    0,
    TEN_GFEC10G_REG_OFST(RZBTER0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
  
  {
    "frx robter",
    0,
    TEN_GFEC10G_REG_OFST(ROBTER0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
  
  {
    "frx rbyter",
    0,
    TEN_GFEC10G_REG_OFST(RBYTER0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
  
  {
    "frx rerrov",
    0,
    TEN_GFEC10G_REG_OFST(RERROV0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
};

const ten_stats_info_t stats_table_gfec10g_1[TEN_GFEC10G_MAX_STAT] = {
  {
    "frx rzbter",
    0,
    TEN_GFEC10G_REG_OFST(RZBTER0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
  
  {
    "frx robter",
    0,
    TEN_GFEC10G_REG_OFST(ROBTER0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
  
  {
    "frx rbyter",
    0,
    TEN_GFEC10G_REG_OFST(RBYTER0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
  
  {
    "frx rerrov",
    0,
    TEN_GFEC10G_REG_OFST(RERROV0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
};

const ten_stats_info_t stats_table_gfec10g_2[TEN_GFEC10G_MAX_STAT] = {
  {
    "frx rzbter",
    0,
    TEN_GFEC10G_REG_OFST(RZBTER0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
  
  {
    "frx robter",
    0,
    TEN_GFEC10G_REG_OFST(ROBTER0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
  
  {
    "frx rbyter",
    0,
    TEN_GFEC10G_REG_OFST(RBYTER0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
  
  {
    "frx rerrov",
    0,
    TEN_GFEC10G_REG_OFST(RERROV0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_GFEC10G  /* block active check */
  },
};

/******************************************************************************
 * UFEC INSTANCE 0 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_ufec_0[TEN_UFEC_MAX_STAT] = {
  {
    "urx r1c0",
    0,
    TEN_UFEC_REG_OFST(R1C00, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r1c1",
    0,
    TEN_UFEC_REG_OFST(R1C10, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r1eo",
    0,
    TEN_UFEC_REG_OFST(R1EO0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1c0",
    0,
    TEN_UFEC_REG_OFST(C1C00, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1c1",
    0,
    TEN_UFEC_REG_OFST(C1C10, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1eo",
    0,
    TEN_UFEC_REG_OFST(C1EO0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2c0",
    0,
    TEN_UFEC_REG_OFST(R2C00, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2c1",
    0,
    TEN_UFEC_REG_OFST(R2C10, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2eo",
    0,
    TEN_UFEC_REG_OFST(R2EO0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },  
  
  {
    "urx c2c0",
    0,
    TEN_UFEC_REG_OFST(C2C00, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2c1",
    0,
    TEN_UFEC_REG_OFST(C2C10, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2eo",
    0,
    TEN_UFEC_REG_OFST(C2EO0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3c0",
    0,
    TEN_UFEC_REG_OFST(R3C00, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3c1",
    0,
    TEN_UFEC_REG_OFST(R3C10, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3eo",
    0,
    TEN_UFEC_REG_OFST(R3EO0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx tc0",
    0,
    TEN_UFEC_REG_OFST(TC00, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx tc1",
    0,
    TEN_UFEC_REG_OFST(TC10, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx teo",
    0,
    TEN_UFEC_REG_OFST(TEO0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx msyncerrcnt",
    0,
    TEN_UFEC_REG_OFST(MSYNCERRCNT, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
};
  
/******************************************************************************
 * UFEC INSTANCE 1 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_ufec_1[TEN_UFEC_MAX_STAT] = {
  {
    "urx r1c0",
    0,
    TEN_UFEC_REG_OFST(R1C00, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r1c1",
    0,
    TEN_UFEC_REG_OFST(R1C10, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r1eo",
    0,
    TEN_UFEC_REG_OFST(R1EO0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1c0",
    0,
    TEN_UFEC_REG_OFST(C1C00, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1c1",
    0,
    TEN_UFEC_REG_OFST(C1C10, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1eo",
    0,
    TEN_UFEC_REG_OFST(C1EO0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2c0",
    0,
    TEN_UFEC_REG_OFST(R2C00, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2c1",
    0,
    TEN_UFEC_REG_OFST(R2C10, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2eo",
    0,
    TEN_UFEC_REG_OFST(R2EO0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2c0",
    0,
    TEN_UFEC_REG_OFST(C2C00, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2c1",
    0,
    TEN_UFEC_REG_OFST(C2C10, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2eo",
    0,
    TEN_UFEC_REG_OFST(C2EO0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3c0",
    0,
    TEN_UFEC_REG_OFST(R3C00, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3c1",
    0,
    TEN_UFEC_REG_OFST(R3C10, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3eo",
    0,
    TEN_UFEC_REG_OFST(R3EO0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx tc0",
    0,
    TEN_UFEC_REG_OFST(TC00, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx tc1",
    0,
    TEN_UFEC_REG_OFST(TC10, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx teo",
    0,
    TEN_UFEC_REG_OFST(TEO0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx msyncerrcnt",
    0,
    TEN_UFEC_REG_OFST(MSYNCERRCNT, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
};
  
/******************************************************************************
 * UFEC INSTANCE 2 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_ufec_2[TEN_UFEC_MAX_STAT] = {
  {
    "urx r1c0",
    0,
    TEN_UFEC_REG_OFST(R1C00, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r1c1",
    0,
    TEN_UFEC_REG_OFST(R1C10, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r1eo",
    0,
    TEN_UFEC_REG_OFST(R1EO0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1c0",
    0,
    TEN_UFEC_REG_OFST(C1C00, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1c1",
    0,
    TEN_UFEC_REG_OFST(C1C10, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1eo",
    0,
    TEN_UFEC_REG_OFST(C1EO0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2c0",
    0,
    TEN_UFEC_REG_OFST(R2C00, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2c1",
    0,
    TEN_UFEC_REG_OFST(R2C10, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2eo",
    0,
    TEN_UFEC_REG_OFST(R2EO0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2c0",
    0,
    TEN_UFEC_REG_OFST(C2C00, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2c1",
    0,
    TEN_UFEC_REG_OFST(C2C10, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2eo",
    0,
    TEN_UFEC_REG_OFST(C2EO0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3c0",
    0,
    TEN_UFEC_REG_OFST(R3C00, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3c1",
    0,
    TEN_UFEC_REG_OFST(R3C10, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3eo",
    0,
    TEN_UFEC_REG_OFST(R3EO0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx tc0",
    0,
    TEN_UFEC_REG_OFST(TC00, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx tc1",
    0,
    TEN_UFEC_REG_OFST(TC10, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx teo",
    0,
    TEN_UFEC_REG_OFST(TEO0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx msyncerrcnt",
    0,
    TEN_UFEC_REG_OFST(MSYNCERRCNT, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
};
  
/******************************************************************************
 * UFEC INSTANCE 3 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_ufec_3[TEN_UFEC_MAX_STAT] = {
  {
    "urx r1c0",
    0,
    TEN_UFEC_REG_OFST(R1C00, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r1c1",
    0,
    TEN_UFEC_REG_OFST(R1C10, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r1eo",
    0,
    TEN_UFEC_REG_OFST(R1EO0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1c0",
    0,
    TEN_UFEC_REG_OFST(C1C00, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1c1",
    0,
    TEN_UFEC_REG_OFST(C1C10, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c1eo",
    0,
    TEN_UFEC_REG_OFST(C1EO0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2c0",
    0,
    TEN_UFEC_REG_OFST(R2C00, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2c1",
    0,
    TEN_UFEC_REG_OFST(R2C10, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r2eo",
    0,
    TEN_UFEC_REG_OFST(R2EO0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2c0",
    0,
    TEN_UFEC_REG_OFST(C2C00, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2c1",
    0,
    TEN_UFEC_REG_OFST(C2C10, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx c2eo",
    0,
    TEN_UFEC_REG_OFST(C2EO0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3c0",
    0,
    TEN_UFEC_REG_OFST(R3C00, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3c1",
    0,
    TEN_UFEC_REG_OFST(R3C10, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx r3eo",
    0,
    TEN_UFEC_REG_OFST(R3EO0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx tc0",
    0,
    TEN_UFEC_REG_OFST(TC00, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx tc1",
    0,
    TEN_UFEC_REG_OFST(TC10, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx teo",
    0,
    TEN_UFEC_REG_OFST(TEO0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
  
  {
    "urx msyncerrcnt",
    0,
    TEN_UFEC_REG_OFST(MSYNCERRCNT, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_UFEC  /* block active check */
  },
};
  
/******************************************************************************
 * N40G STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_n40g[TEN_N40G_MAX_STAT] = {
    {
    "gblr4x pec",
    0,
    TEN_N40G_REG_OFST(PEC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "gblr4x fpcnt",
    0,
    TEN_N40G_REG_OFST(FPCNT1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "otnr4x lofstat",
    0,
    TEN_N40G_REG_OFST(LOFSTAT),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "otnr4x oofstat",
    0,
    TEN_N40G_REG_OFST(OOFSTAT),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "otnr4x phastat",
    0,
    TEN_N40G_REG_OFST(PHASTAT),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "sdfr b1bter",
    0,
    TEN_N40G_SDFR_REG_OFST(B1BTER),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "sdfr b1bler",
    0,
    TEN_N40G_SDFR_REG_OFST(B1BLER),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "sdfr b2bter",
    0,
    TEN_N40G_SDFR_REG_OFST(B2BTER0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "sdfr b2bler",
    0,
    TEN_N40G_SDFR_REG_OFST(B2BLER0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "sdfr lofec",
    0,
    TEN_N40G_SDFR_REG_OFST(LOFEC),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "sdfr oofec",
    0,
    TEN_N40G_SDFR_REG_OFST(OOFEC),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bip0erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BIP0ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bip1erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BIP1ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bip2erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BIP2ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bip3erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BIP3ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bip4erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BIP4ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bip5erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BIP5ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bip6erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BIP6ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bip7erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BIP7ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bei0erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BEI0ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bei1erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BEI1ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bei2erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BEI2ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bei3erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BEI3ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bei4erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BEI4ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bei5erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BEI5ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bei6erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BEI6ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  },
  
  {
    "oohr bei7erc",
    0,
    TEN_N40G_OOHR_REG_OFST(BEI7ERC1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N40G  /* block active check */
  }
};

/******************************************************************************
 * N10G SLICE 0 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_n10g_0[TEN_N10G_MAX_STAT] = {
  {
    "gblr pec",
    0,
    TEN_N10G_REG_OFST(PEC0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "gblr fpcnt",
    0,
    TEN_N10G_REG_OFST(FPCNT0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr lofstat",
    0,
    TEN_N10G_REG_OFST(LOFSTAT, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr oofstat",
    0,
    TEN_N10G_REG_OFST(OOFSTAT, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr phastat",
    0,
    TEN_N10G_REG_OFST(PHASTAT, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "sdfr b1bter",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B1BTER, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b1bler",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B1BLER, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b2bter",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B2BTER0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b2bler",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B2BLER0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr lofec",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_LOFEC, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr oofec",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_OOFEC, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "oohr bip0erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP0ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip1erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP1ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip2erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP2ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip3erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP3ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip4erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP4ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip5erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP5ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip6erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP6ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip7erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP7ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei0erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI0ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei1erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI1ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei2erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI2ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei3erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI3ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei4erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI4ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei5erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI5ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei6erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI6ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei7erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI7ERC1, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "sohr m1bter",
    0,
    TEN_N10G_REG_OFST(M1BTER0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr m1bler",
    0,
    TEN_N10G_REG_OFST(M1BLER0, 0),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjinc1",
    0,
    TEN_N10G_REG_OFST(PJINC1, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
   "sohr pjinc2",
    0,
    TEN_N10G_REG_OFST(PJINC2, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
   {
    "sohr pjinc3",
    0,
    TEN_N10G_REG_OFST(PJINC3, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjdec1",
    0,
    TEN_N10G_REG_OFST(PJDEC1, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
    {
    "sohr pjdec2",
    0,
    TEN_N10G_REG_OFST(PJDEC2, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
    {
    "sohr pjdec3",
    0,
    TEN_N10G_REG_OFST(PJDEC3, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf1",
    0,
    TEN_N10G_REG_OFST(PNDF1, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf2",
    0,
    TEN_N10G_REG_OFST(PNDF2, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf3",
    0,
    TEN_N10G_REG_OFST(PNDF3, 0),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pnpt1",
    0,
    TEN_N10G_REG_OFST(PNPT1, 0),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },

  {
    "sohr pnpt2",
    0,
    TEN_N10G_REG_OFST(PNPT2, 0),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pnpt3",
    0,
    TEN_N10G_REG_OFST(PNPT3, 0),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr b3bter",
    0,
    TEN_N10G_REG_OFST(B3BTER, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr b3bler",
    0,
    TEN_N10G_REG_OFST(B3BLER, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr reipbter",
    0,
    TEN_N10G_REG_OFST(REIPBTER, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr reipbler",
    0,
    TEN_N10G_REG_OFST(REIPBLER, 0),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  }  
};

/******************************************************************************
 * N10G SLICE 1 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_n10g_1[TEN_N10G_MAX_STAT] = {
  {
    "gblr pec",
    0,
    TEN_N10G_REG_OFST(PEC0, 1),
    2, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "gblr fpcnt",
    0,
    TEN_N10G_REG_OFST(FPCNT0, 1),
    2, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr lofstat",
    0,
    TEN_N10G_REG_OFST(LOFSTAT, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr oofstat",
    0,
    TEN_N10G_REG_OFST(OOFSTAT, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr phastat",
    0,
    TEN_N10G_REG_OFST(PHASTAT, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
   {
    "sdfr b1bter",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B1BTER, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b1bler",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B1BLER, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b2bter",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B2BTER0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b2bler",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B2BLER0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr lofec",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_LOFEC, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr oofec",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_OOFEC, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
   {
    "oohr bip0erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP0ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip1erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP1ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip2erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP2ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip3erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP3ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip4erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP4ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip5erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP5ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip6erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP6ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip7erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP7ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei0erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI0ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei1erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI1ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei2erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI2ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei3erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI3ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei4erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI4ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei5erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI5ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei6erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI6ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei7erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI7ERC1, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "sohr m1bter",
    0,
    TEN_N10G_REG_OFST(M1BTER0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr m1bler",
    0,
    TEN_N10G_REG_OFST(M1BLER0, 1),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjinc1",
    0,
    TEN_N10G_REG_OFST(PJINC1, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
   "sohr pjinc2",
    0,
    TEN_N10G_REG_OFST(PJINC2, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
   {
    "sohr pjinc3",
    0,
    TEN_N10G_REG_OFST(PJINC3, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjdec1",
    0,
    TEN_N10G_REG_OFST(PJDEC1, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjdec2",
    0,
    TEN_N10G_REG_OFST(PJDEC2, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
    {
    "sohr pjdec3",
    0,
    TEN_N10G_REG_OFST(PJDEC3, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf1",
    0,
    TEN_N10G_REG_OFST(PNDF1, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf2",
    0,
    TEN_N10G_REG_OFST(PNDF2, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf3",
    0,
    TEN_N10G_REG_OFST(PNDF3, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pnpt1",
    0,
    TEN_N10G_REG_OFST(PNPT1, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },

  {
    "sohr pnpt2",
    0,
    TEN_N10G_REG_OFST(PNPT2, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pnpt3",
    0,
    TEN_N10G_REG_OFST(PNPT3, 1),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr b3bter",
    0,
    TEN_N10G_REG_OFST(B3BTER, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr b3bler",
    0,
    TEN_N10G_REG_OFST(B3BLER, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr reipbter",
    0,
    TEN_N10G_REG_OFST(REIPBTER, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr reipbler",
    0,
    TEN_N10G_REG_OFST(REIPBLER, 1),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  }  
};

/******************************************************************************
 * N10G SLICE 2 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_n10g_2[TEN_N10G_MAX_STAT] = {
  {
    "gblr pec",
    0,
    TEN_N10G_REG_OFST(PEC0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "gblr fpcnt",
    0,
    TEN_N10G_REG_OFST(FPCNT0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr lofstat",
    0,
    TEN_N10G_REG_OFST(LOFSTAT, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr oofstat",
    0,
    TEN_N10G_REG_OFST(OOFSTAT, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr phastat",
    0,
    TEN_N10G_REG_OFST(PHASTAT, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
   {
    "sdfr b1bter",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B1BTER, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b1bler",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B1BLER, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b2bter",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B2BTER0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b2bler",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B2BLER0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr lofec",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_LOFEC, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr oofec",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_OOFEC, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
   {
    "oohr bip0erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP0ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip1erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP1ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip2erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP2ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip3erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP3ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip4erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP4ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip5erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP5ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip6erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP6ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip7erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP7ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei0erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI0ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei1erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI1ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei2erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI2ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei3erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI3ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei4erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI4ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei5erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI5ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei6erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI6ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei7erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI7ERC1, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "sohr m1bter",
    0,
    TEN_N10G_REG_OFST(M1BTER0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr m1bler",
    0,
    TEN_N10G_REG_OFST(M1BLER0, 2),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjinc1",
    0,
    TEN_N10G_REG_OFST(PJINC1, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
   "sohr pjinc2",
    0,
    TEN_N10G_REG_OFST(PJINC2, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
   {
    "sohr pjinc3",
    0,
    TEN_N10G_REG_OFST(PJINC3, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjdec1",
    0,
    TEN_N10G_REG_OFST(PJDEC1, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjdec2",
    0,
    TEN_N10G_REG_OFST(PJDEC2, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
    {
    "sohr pjdec3",
    0,
    TEN_N10G_REG_OFST(PJDEC3, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf1",
    0,
    TEN_N10G_REG_OFST(PNDF1, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf2",
    0,
    TEN_N10G_REG_OFST(PNDF2, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf3",
    0,
    TEN_N10G_REG_OFST(PNDF3, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pnpt1",
    0,
    TEN_N10G_REG_OFST(PNPT1, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },

  {
    "sohr pnpt2",
    0,
    TEN_N10G_REG_OFST(PNPT2, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pnpt3",
    0,
    TEN_N10G_REG_OFST(PNPT3, 2),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr b3bter",
    0,
    TEN_N10G_REG_OFST(B3BTER, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr b3bler",
    0,
    TEN_N10G_REG_OFST(B3BLER, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr reipbter",
    0,
    TEN_N10G_REG_OFST(REIPBTER, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr reipbler",
    0,
    TEN_N10G_REG_OFST(REIPBLER, 2),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  }  
};

/******************************************************************************
 * N10G SLICE 3 STATS TABLE
 ******************************************************************************/
const ten_stats_info_t stats_table_n10g_3[TEN_N10G_MAX_STAT] = {
  {
    "gblr pec",
    0,
    TEN_N10G_REG_OFST(PEC0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "gblr fpcnt",
    0,
    TEN_N10G_REG_OFST(FPCNT0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr lofstat",
    0,
    TEN_N10G_REG_OFST(LOFSTAT, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr oofstat",
    0,
    TEN_N10G_REG_OFST(OOFSTAT, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "otnr phastat",
    0,
    TEN_N10G_REG_OFST(PHASTAT, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "sdfr b1bter",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B1BTER, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b1bler",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B1BLER, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b2bter",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B2BTER0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr b2bler",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_B2BLER0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr lofec",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_LOFEC, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sdfr oofec",
    0,
    TEN_N10G_SDFR_REG_OFST(sdfr_OOFEC, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
   {
    "oohr bip0erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP0ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip1erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP1ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip2erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP2ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip3erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP3ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip4erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP4ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip5erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP5ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip6erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP6ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bip7erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BIP7ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei0erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI0ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei1erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI1ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei2erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI2ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei3erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI3ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei4erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI4ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei5erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI5ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei6erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI6ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "oohr bei7erc",
    0,
    TEN_N10G_OOHR_REG_OFST(oohr_BEI7ERC1, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G  /* block active check */
  },
  
  {
    "sohr m1bter",
    0,
    TEN_N10G_REG_OFST(M1BTER0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr m1bler",
    0,
    TEN_N10G_REG_OFST(M1BLER0, 3),
    2, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_LSB_FIRST | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjinc1",
    0,
    TEN_N10G_REG_OFST(PJINC1, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
   "sohr pjinc2",
    0,
    TEN_N10G_REG_OFST(PJINC2, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
   {
    "sohr pjinc3",
    0,
    TEN_N10G_REG_OFST(PJINC3, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjdec1",
    0,
    TEN_N10G_REG_OFST(PJDEC1, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjdec2",
    0,
    TEN_N10G_REG_OFST(PJDEC2, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pjdec3",
    0,
    TEN_N10G_REG_OFST(PJDEC3, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf1",
    0,
    TEN_N10G_REG_OFST(PNDF1, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf2",
    0,
    TEN_N10G_REG_OFST(PNDF2, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pndf3",
    0,
    TEN_N10G_REG_OFST(PNDF3, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pnpt1",
    0,
    TEN_N10G_REG_OFST(PNPT1, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },

  {
    "sohr pnpt2",
    0,
    TEN_N10G_REG_OFST(PNPT2, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "sohr pnpt3",
    0,
    TEN_N10G_REG_OFST(PNPT3, 3),
    1, /* 32 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr b3bter",
    0,
    TEN_N10G_REG_OFST(B3BTER, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr b3bler",
    0,
    TEN_N10G_REG_OFST(B3BLER, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr reipbter",
    0,
    TEN_N10G_REG_OFST(REIPBTER, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  },
  
  {
    "pohr reipbler",
    0,
    TEN_N10G_REG_OFST(REIPBLER, 3),
    1, /* 16 bit counter */
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL | TEN_STATS_FLAG_NO_ACCUM,
    TEN_STATS_CHECK_N10G_SOH  /* block active check */
  }  
};

/******************************************************************************
 * PP40G STATS TABLE INDIRECT REGISTERS
 ******************************************************************************/
const ten_stats_info_t stats_table_pp40g[TEN_PP40G_MAX_STAT] = {

  {
    "pcs rx err am 0",
    0,
    TEN_cntr_id_PCS_RX_ERR_AM_0,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err am 1",
    0,
    TEN_cntr_id_PCS_RX_ERR_AM_1,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err am 2",
    0,
    TEN_cntr_id_PCS_RX_ERR_AM_2,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err am 3",
    0,
    TEN_cntr_id_PCS_RX_ERR_AM_3,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err ber",
    0,
    TEN_cntr_id_PCS_RX_ERR_BER,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err bip 0",
    0,
    TEN_cntr_id_PCS_RX_ERR_BIP_0,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err bip 1",
    0,
    TEN_cntr_id_PCS_RX_ERR_BIP_1,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err bip 2",
    0,
    TEN_cntr_id_PCS_RX_ERR_BIP_2,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err bip 3",
    0,
    TEN_cntr_id_PCS_RX_ERR_BIP_3,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx xc adj bip 0",
    0,
    TEN_cntr_id_PCS_RX_XC_ADJ_BIP_0,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx xc adj bip 1",
    0,
    TEN_cntr_id_PCS_RX_XC_ADJ_BIP_1,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx xc adj bip 2",
    0,
    TEN_cntr_id_PCS_RX_XC_ADJ_BIP_2,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx xc adj bip 3",
    0,
    TEN_cntr_id_PCS_RX_XC_ADJ_BIP_3,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx xc err 1027b",
    0,
    TEN_cntr_id_PCS_RX_XC_ERR_1027B,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx xc err 513b",
    0,
    TEN_cntr_id_PCS_RX_XC_ERR_513B,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  /* Bugzilla #26878, remove reserved counter */
  {
    "rsvd1",
    0,
    0,
    3,
    0,
    0,
    0  /* block active check */
  },

  {
    "pcs rx err dec",
    0,
    TEN_cntr_id_PCS_RX_ERR_DEC,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err pat",
    0,
    TEN_cntr_id_PCS_RX_ERR_PAT,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err sh 0",
    0,
    TEN_cntr_id_PCS_RX_ERR_SH_0,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err sh 1",
    0,
    TEN_cntr_id_PCS_RX_ERR_SH_1,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err sh 2",
    0,
    TEN_cntr_id_PCS_RX_ERR_SH_2,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "pcs rx err sh 3",
    0,
    TEN_cntr_id_PCS_RX_ERR_SH_3,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "rx ra discarded octets",
    0,
    TEN_cntr_id_RX_RA_DISCARDED_OCTETS,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx adj bip 0",
    TEN_cntr_id_TX_ADJ_BIP_0,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx adj bip 1",
    TEN_cntr_id_TX_ADJ_BIP_1,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx adj bip 2",
    TEN_cntr_id_TX_ADJ_BIP_2,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx adj bip 3",
    TEN_cntr_id_TX_ADJ_BIP_3,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx xc err bip 0",
    TEN_cntr_id_TX_XC_ERR_BIP_0,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx xc err bip 1",
    TEN_cntr_id_TX_XC_ERR_BIP_1,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx xc err bip 2",
    TEN_cntr_id_TX_XC_ERR_BIP_2,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx xc err bip 3",
    TEN_cntr_id_TX_XC_ERR_BIP_3,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },
  
  /* Bugzilla #26878, remove reserved counter */
  {
    "rsvd2",
    0,
    0,
    3,
    0,
    0,
    0  /* block active check */
  },

  {
    "tx fixed am",
    TEN_cntr_id_TX_FIXED_AM,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx fixed bip",
    TEN_cntr_id_TX_FIXED_BIP,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx ra inserted octets",
    TEN_cntr_id_TX_RA_INSERTED_OCTETS,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx xc err bt",
    TEN_cntr_id_TX_XC_ERR_BT,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "tx xc err sh",
    TEN_cntr_id_TX_XC_ERR_SH,
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  /* Bugzilla 26168, stats registers added according to updates in t41_registers file. */
  {
    "mac40g rx 1024b to 1518b frames",
    0,
    TEN_cntr_id_MAC40G_RX_1024B_TO_1518B_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx 128b to 255b frames",
    0,
    TEN_cntr_id_MAC40G_RX_128B_TO_255B_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx 1519b to maxb frames",
    0,
    TEN_cntr_id_MAC40G_RX_1519B_TO_MAXB_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx 256b to 511b frames",
    0,
    TEN_cntr_id_MAC40G_RX_256B_TO_511B_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx 512b to 1023b frames",
    0,
    TEN_cntr_id_MAC40G_RX_512B_TO_1023B_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx 64b frames",
    0,
    TEN_cntr_id_MAC40G_RX_64B_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx 65b to 127b frames",
    0,
    TEN_cntr_id_MAC40G_RX_65B_TO_127B_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx align err frames",
    0,
    TEN_cntr_id_MAC40G_RX_ALIGN_ERR_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET/* block active check */
  },

  {
    "mac40g rx bcast frames",
    0,
    TEN_cntr_id_MAC40G_RX_BCAST_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx crc err frames",
    0,
    TEN_cntr_id_MAC40G_RX_CRC_ERR_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx err frames",
    0,
    TEN_cntr_id_MAC40G_RX_ERR_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx frames",
    0,
    TEN_cntr_id_MAC40G_RX_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET/* block active check */
  },

  {
    "mac40g rx giant frames",
    0,
    TEN_cntr_id_MAC40G_RX_GIANT_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET/* block active check */
  },

  {
    "mac40g rx good frames",
    0,
    TEN_cntr_id_MAC40G_RX_GOOD_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx jabber frames",
    0,
    TEN_cntr_id_MAC40G_RX_JABBER_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx mcast frames",
    0,
    TEN_cntr_id_MAC40G_RX_MCAST_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx pause frames",
    0,
    TEN_cntr_id_MAC40G_RX_PAUSE_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx runt frames",
    0,
    TEN_cntr_id_MAC40G_RX_RUNT_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx short frames",
    0,
    TEN_cntr_id_MAC40G_RX_SHORT_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx ucast frames",
    0,
    TEN_cntr_id_MAC40G_RX_UCAST_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx undersize frames",
    0,
    TEN_cntr_id_MAC40G_RX_UNDERSIZE_FRAMES,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx bad octets",
    0,
    TEN_cntr_id_MAC40G_RX_BAD_OCTETS,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx good octets",
    0,
    TEN_cntr_id_MAC40G_RX_GOOD_OCTETS,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  {
    "mac40g rx octets",
    0,
    TEN_cntr_id_MAC40G_RX_OCTETS,
    3,
    0,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_MISC_RESET  /* block active check */
  },

  /*--------- PP40G Registers with direct access ---------*/ 
  {
    "ten pp40g pbert40g tx frmcnt2",
    TEN_PP40G_REG_OFST(FRMCNT2),
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_PBERT /* block active check */
  },

  {
    "ten pp40g pbert40g tx frmoctcnt2",
    TEN_PP40G_REG_OFST(FRMOCTCNT2),
    0,
    3,
    0,
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP40G_PBERT  /* block active check */
  }

};

/******************************************************************************
 * PP10G STATS TABLE (SLICE 0) INDIRECT REGISTERS
 ******************************************************************************/
const ten_stats_info_t stats_table_pp10g_0[TEN_PP10G_MAX_STAT] = {
  {
    "mac drop rx align err frames cnt",
    0,
    TEN_PP10G_MAC_DROP_RX_ALIGN_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac drop rx crc err frames cnt",
    0,
    TEN_PP10G_MAC_DROP_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 1024b to 1518b frames cnt",
    0,
    TEN_PP10G_MAC_RX_1024B_TO_1518B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 128b to 255b frames cnt",
    0,
    TEN_PP10G_MAC_RX_128B_TO_255B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 1519b to maxb frames cnt",
    0,
    TEN_PP10G_MAC_RX_1519B_TO_MAXB_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 256b to 511b frames cnt",
    0,
    TEN_PP10G_MAC_RX_256B_TO_511B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 512b to 1023b frames cnt",
    0,
    TEN_PP10G_MAC_RX_512B_TO_1023B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 64b frames cnt",
    0,
    TEN_PP10G_MAC_RX_64B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 65b to 127b frames cnt",
    0,
    TEN_PP10G_MAC_RX_65B_TO_127B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx align err frames cnt",
    0,
    TEN_PP10G_MAC_RX_ALIGN_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx bcast frames cnt",
    0,
    TEN_PP10G_MAC_RX_BCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx crc err frames cnt",
    0,
    TEN_PP10G_MAC_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx err frames cnt",
    0,
    TEN_PP10G_MAC_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx frames cnt",
    0,
    TEN_PP10G_MAC_RX_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx giant frames cnt",
    0,
    TEN_PP10G_MAC_RX_GIANT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx good frames cnt",
    0,
    TEN_PP10G_MAC_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx jabber frames cnt",
    0,
    TEN_PP10G_MAC_RX_JABBER_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx mcast frames cnt",
    0,
    TEN_PP10G_MAC_RX_MCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx pause frames cnt",
    0,
    TEN_PP10G_MAC_RX_PAUSE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx runt frames cnt",
    0,
    TEN_PP10G_MAC_RX_RUNT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx short frames cnt",
    0,
    TEN_PP10G_MAC_RX_SHORT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx ucast frames cnt",
    0,
    TEN_PP10G_MAC_RX_UCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx undersize frames cnt",
    0,
    TEN_PP10G_MAC_RX_UNDERSIZE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac tx 1024b to 1518b frames cnt",
    TEN_PP10G_MAC_TX_1024B_TO_1518B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 128b to 255b frames cnt",
    TEN_PP10G_MAC_TX_128B_TO_255B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 1519b frames cnt",
    TEN_PP10G_MAC_TX_1519B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 256b to 511b frames cnt",
    TEN_PP10G_MAC_TX_256B_TO_511B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 512b to 1023b frames cnt",
    TEN_PP10G_MAC_TX_512B_TO_1023B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 64b frames cnt",
    TEN_PP10G_MAC_TX_64B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 65b to 127b frames cnt",
    TEN_PP10G_MAC_TX_65B_TO_127B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx bcast frames cnt",
    TEN_PP10G_MAC_TX_BCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx err frames cnt",
    TEN_PP10G_MAC_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx frames cnt",
    TEN_PP10G_MAC_TX_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx good frames cnt",
    TEN_PP10G_MAC_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx mcast frames cnt",
    TEN_PP10G_MAC_TX_MCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause detected frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_DETECTED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause err frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx ucast frames cnt",
    TEN_PP10G_MAC_TX_UCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac rx good octets cnt",
    0,
    TEN_PP10G_MAC_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx octets cnt",
    0,
    TEN_PP10G_MAC_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac tx good octets cnt",
    TEN_PP10G_MAC_TX_GOOD_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx inserted pause quanta cnt",
    TEN_PP10G_MAC_TX_INSERTED_PAUSE_QUANTA_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx octets cnt",
    TEN_PP10G_MAC_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx total pause quanta cnt",
    TEN_PP10G_MAC_TX_TOTAL_PAUSE_QUANTA_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "rs tx trunk frames cnt",
    TEN_PP10G_RS_TX_TRUNK_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "pcs49 rx err frames cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx good frames cnt",
    0,
    TEN_PP10G_PCS49_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 tx err frames cnt",
    TEN_PP10G_PCS49_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 tx good frames cnt",
    TEN_PP10G_PCS49_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err ber cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_BER_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err dec cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_DEC_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err pat cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_PAT_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "xaui rx err frames cnt",
    0,
    TEN_PP10G_XAUI_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx good frames cnt",
    0,
    TEN_PP10G_XAUI_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui tx err frames cnt",
    TEN_PP10G_XAUI_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_BASEX  /* block active check */
  },
  
  {
    "xaui tx good frames cnt",
    TEN_PP10G_XAUI_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln0 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN0_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln1 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN1_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln2 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN2_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln3 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN3_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln0 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN0_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln1 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN1_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln2 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN2_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln3 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN3_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "gfp rx ch err frames cnt",
    0,
    TEN_PP10G_GFP_RX_CH_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx cmf frames cnt",
    0,
    TEN_PP10G_GFP_RX_CMF_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx discard frames cnt",
    0,
    TEN_PP10G_GFP_RX_DISCARD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx exm frames cnt",
    0,
    TEN_PP10G_GFP_RX_EXM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx fcs err frames cnt",
    0,
    TEN_PP10G_GFP_RX_FCS_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx good frames cnt",
    0,
    TEN_PP10G_GFP_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx long frames cnt",
    0,
    TEN_PP10G_GFP_RX_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx mcf frames cnt",
    0,
    TEN_PP10G_GFP_RX_MCF_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx ph err frames cnt",
    0,
    TEN_PP10G_GFP_RX_PH_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx ptm frames cnt",
    0,
    TEN_PP10G_GFP_RX_PTM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx upm frames cnt",
    0,
    TEN_PP10G_GFP_RX_UPM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp tx cmf frames cnt",
    TEN_PP10G_GFP_TX_CMF_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx err frames cnt",
    TEN_PP10G_GFP_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx good frames cnt",
    TEN_PP10G_GFP_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx mcf frames cnt",
    TEN_PP10G_GFP_TX_MCF_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp rx good octets cnt",
    0,
    TEN_PP10G_GFP_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx octets cnt",
    0,
    TEN_PP10G_GFP_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp tx good octets cnt",
    TEN_PP10G_GFP_TX_GOOD_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx octets cnt",
    TEN_PP10G_GFP_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "fc rx crc err frames cnt",
    0,
    TEN_PP10G_FC_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx good frames cnt",
    0,
    TEN_PP10G_FC_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx oversize frames cnt",
    0,
    TEN_PP10G_FC_RX_OVERSIZE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx too long frames cnt",
    0,
    TEN_PP10G_FC_RX_TOO_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx total frames cnt",
    0,
    TEN_PP10G_FC_RX_TOTAL_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx trunc frames cnt",
    0,
    TEN_PP10G_FC_RX_TRUNC_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx good octets cnt",
    0,
    TEN_PP10G_FC_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx prim cnt",
    0,
    TEN_PP10G_FC_RX_PRIM_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx r rdy cnt",
    0,
    TEN_PP10G_FC_RX_R_RDY_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx total octets cnt",
    0,
    TEN_PP10G_FC_RX_TOTAL_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "xcode rx errcor superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_ERRCOR_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx err frames cnt",
    0,
    TEN_PP10G_XCODE_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx err superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_ERR_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx frames cnt",
    0,
    TEN_PP10G_XCODE_RX_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx good superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_GOOD_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx long frames cnt",
    0,
    TEN_PP10G_XCODE_RX_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx short frames cnt",
    0,
    TEN_PP10G_XCODE_RX_SHORT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err frames cnt",
    TEN_PP10G_XCODE_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx good frames cnt",
    TEN_PP10G_XCODE_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx good superblocks cnt",
    TEN_PP10G_XCODE_TX_GOOD_SUPERBLOCKS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode rx octets cnt",
    0,
    TEN_PP10G_XCODE_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err codewords cnt",
    TEN_PP10G_XCODE_TX_ERR_CODEWORDS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err syncwords cnt",
    TEN_PP10G_XCODE_TX_ERR_SYNCWORDS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx octets cnt",
    TEN_PP10G_XCODE_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "egpcs rx err frames cnt",
    0,
    TEN_PP10G_EGPCS_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx good frames cnt",
    0,
    TEN_PP10G_EGPCS_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs tx err frames cnt",
    TEN_PP10G_EGPCS_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_EGPCS  /* block active check */
  },
  
  {
    "egpcs tx good frames cnt",
    TEN_PP10G_EGPCS_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx tc err cnt",
    0,
    TEN_PP10G_EGPCS_RX_TC_ERR_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx tw err cnt",
    0,
    TEN_PP10G_EGPCS_RX_TW_ERR_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "xgadj rx discarded frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx errored frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_ERRORED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx micro extracted frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_MICRO_EXTRACTED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx total frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_TOTAL_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx discarded frames cnt",
    TEN_PP10G_XGADJ_TX_DISCARDED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx errored frames cnt",
    TEN_PP10G_XGADJ_TX_ERRORED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx micro inserted frames cnt",
    TEN_PP10G_XGADJ_TX_MICRO_INSERTED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx total frames cnt",
    TEN_PP10G_XGADJ_TX_TOTAL_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded idle octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_IDLE_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded seq ordered sets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_SEQUENCE_ORDERED_SETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx errored octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_ERRORED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET /* block active check */
  },
  
  {
    "xgadj rx micro extracted octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_MICRO_EXTRACTED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx total octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_TOTAL_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx discarded octets cnt",
    TEN_PP10G_XGADJ_TX_DISCARDED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx errored octets cnt",
    TEN_PP10G_XGADJ_TX_ERRORED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx inserted idle octets cnt",
    TEN_PP10G_XGADJ_TX_INSERTED_IDLE_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx micro inserted octets cnt",
    TEN_PP10G_XGADJ_TX_MICRO_INSERTED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx total octets cnt",
    TEN_PP10G_XGADJ_TX_TOTAL_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },

  /* For T41 */
  /* Bugzilla #30084, PP10G_MON10B Stats - Good/Err Frames are switched */
  {
    "mon10b rx good frames",
    0,
    TEN_PP10G_MON10B_RX_GOOD_FRAMES,
    3,
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },
    
  {
    "mon10b rx err frames",
    0,
    TEN_PP10G_MON10B_RX_ERR_FRAMES,
    3,
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx err octets",
    0,
    TEN_PP10G_MON10B_RX_ERR_OCTETS,
    3,
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx good octets",
    0,
    TEN_PP10G_MON10B_RX_GOOD_OCTETS,
    3,
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx symbol err",
    0,
    TEN_PP10G_MON10B_RX_SYMBOL_ERR,
    3,
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mac rx bad octets",
    0,
    TEN_PP10G_MAC_RX_BAD_OCTETS,
    3,
    0, /* slice 0 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },

  {
    "mac tx bad octets",
    TEN_PP10G_MAC_TX_BAD_OCTETS,
    0,
    3,
    0, /* slice 0 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  }
};

/******************************************************************************
 * PP10G STATS TABLE (SLICE 1)
 ******************************************************************************/
const ten_stats_info_t stats_table_pp10g_1[TEN_PP10G_MAX_STAT] = {
  {
    "mac drop rx align err frames cnt",
    0,
    TEN_PP10G_MAC_DROP_RX_ALIGN_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac drop rx crc err frames cnt",
    0,
    TEN_PP10G_MAC_DROP_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 1024b to 1518b frames cnt",
    0,
    TEN_PP10G_MAC_RX_1024B_TO_1518B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 128b to 255b frames cnt",
    0,
    TEN_PP10G_MAC_RX_128B_TO_255B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 1519b to maxb frames cnt",
    0,
    TEN_PP10G_MAC_RX_1519B_TO_MAXB_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 256b to 511b frames cnt",
    0,
    TEN_PP10G_MAC_RX_256B_TO_511B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 512b to 1023b frames cnt",
    0,
    TEN_PP10G_MAC_RX_512B_TO_1023B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 64b frames cnt",
    0,
    TEN_PP10G_MAC_RX_64B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 65b to 127b frames cnt",
    0,
    TEN_PP10G_MAC_RX_65B_TO_127B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx align err frames cnt",
    0,
    TEN_PP10G_MAC_RX_ALIGN_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx bcast frames cnt",
    0,
    TEN_PP10G_MAC_RX_BCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx crc err frames cnt",
    0,
    TEN_PP10G_MAC_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx err frames cnt",
    0,
    TEN_PP10G_MAC_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx frames cnt",
    0,
    TEN_PP10G_MAC_RX_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx giant frames cnt",
    0,
    TEN_PP10G_MAC_RX_GIANT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx good frames cnt",
    0,
    TEN_PP10G_MAC_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx jabber frames cnt",
    0,
    TEN_PP10G_MAC_RX_JABBER_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx mcast frames cnt",
    0,
    TEN_PP10G_MAC_RX_MCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx pause frames cnt",
    0,
    TEN_PP10G_MAC_RX_PAUSE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx runt frames cnt",
    0,
    TEN_PP10G_MAC_RX_RUNT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx short frames cnt",
    0,
    TEN_PP10G_MAC_RX_SHORT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx ucast frames cnt",
    0,
    TEN_PP10G_MAC_RX_UCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx undersize frames cnt",
    0,
    TEN_PP10G_MAC_RX_UNDERSIZE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac tx 1024b to 1518b frames cnt",
    TEN_PP10G_MAC_TX_1024B_TO_1518B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 128b to 255b frames cnt",
    TEN_PP10G_MAC_TX_128B_TO_255B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 1519b frames cnt",
    TEN_PP10G_MAC_TX_1519B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 256b to 511b frames cnt",
    TEN_PP10G_MAC_TX_256B_TO_511B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 512b to 1023b frames cnt",
    TEN_PP10G_MAC_TX_512B_TO_1023B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 64b frames cnt",
    TEN_PP10G_MAC_TX_64B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 65b to 127b frames cnt",
    TEN_PP10G_MAC_TX_65B_TO_127B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx bcast frames cnt",
    TEN_PP10G_MAC_TX_BCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx err frames cnt",
    TEN_PP10G_MAC_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx frames cnt",
    TEN_PP10G_MAC_TX_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx good frames cnt",
    TEN_PP10G_MAC_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx mcast frames cnt",
    TEN_PP10G_MAC_TX_MCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause detected frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_DETECTED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause err frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx ucast frames cnt",
    TEN_PP10G_MAC_TX_UCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac rx good octets cnt",
    0,
    TEN_PP10G_MAC_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx octets cnt",
    0,
    TEN_PP10G_MAC_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac tx good octets cnt",
    TEN_PP10G_MAC_TX_GOOD_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx inserted pause quanta cnt",
    TEN_PP10G_MAC_TX_INSERTED_PAUSE_QUANTA_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx octets cnt",
    TEN_PP10G_MAC_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx total pause quanta cnt",
    TEN_PP10G_MAC_TX_TOTAL_PAUSE_QUANTA_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "rs tx trunk frames cnt",
    TEN_PP10G_RS_TX_TRUNK_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "pcs49 rx err frames cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx good frames cnt",
    0,
    TEN_PP10G_PCS49_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 tx err frames cnt",
    TEN_PP10G_PCS49_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 tx good frames cnt",
    TEN_PP10G_PCS49_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err ber cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_BER_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err dec cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_DEC_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err pat cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_PAT_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "xaui rx err frames cnt",
    0,
    TEN_PP10G_XAUI_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx good frames cnt",
    0,
    TEN_PP10G_XAUI_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui tx err frames cnt",
    TEN_PP10G_XAUI_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_BASEX  /* block active check */
  },
  
  {
    "xaui tx good frames cnt",
    TEN_PP10G_XAUI_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln0 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN0_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln1 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN1_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln2 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN2_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln3 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN3_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln0 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN0_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln1 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN1_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln2 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN2_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln3 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN3_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "gfp rx ch err frames cnt",
    0,
    TEN_PP10G_GFP_RX_CH_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx cmf frames cnt",
    0,
    TEN_PP10G_GFP_RX_CMF_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx discard frames cnt",
    0,
    TEN_PP10G_GFP_RX_DISCARD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx exm frames cnt",
    0,
    TEN_PP10G_GFP_RX_EXM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx fcs err frames cnt",
    0,
    TEN_PP10G_GFP_RX_FCS_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx good frames cnt",
    0,
    TEN_PP10G_GFP_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx long frames cnt",
    0,
    TEN_PP10G_GFP_RX_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx mcf frames cnt",
    0,
    TEN_PP10G_GFP_RX_MCF_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx ph err frames cnt",
    0,
    TEN_PP10G_GFP_RX_PH_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx ptm frames cnt",
    0,
    TEN_PP10G_GFP_RX_PTM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx upm frames cnt",
    0,
    TEN_PP10G_GFP_RX_UPM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp tx cmf frames cnt",
    TEN_PP10G_GFP_TX_CMF_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx err frames cnt",
    TEN_PP10G_GFP_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx good frames cnt",
    TEN_PP10G_GFP_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx mcf frames cnt",
    TEN_PP10G_GFP_TX_MCF_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp rx good octets cnt",
    0,
    TEN_PP10G_GFP_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx octets cnt",
    0,
    TEN_PP10G_GFP_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp tx good octets cnt",
    TEN_PP10G_GFP_TX_GOOD_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx octets cnt",
    TEN_PP10G_GFP_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "fc rx crc err frames cnt",
    0,
    TEN_PP10G_FC_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx good frames cnt",
    0,
    TEN_PP10G_FC_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx oversize frames cnt",
    0,
    TEN_PP10G_FC_RX_OVERSIZE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx too long frames cnt",
    0,
    TEN_PP10G_FC_RX_TOO_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx total frames cnt",
    0,
    TEN_PP10G_FC_RX_TOTAL_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx trunc frames cnt",
    0,
    TEN_PP10G_FC_RX_TRUNC_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx good octets cnt",
    0,
    TEN_PP10G_FC_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx prim cnt",
    0,
    TEN_PP10G_FC_RX_PRIM_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx r rdy cnt",
    0,
    TEN_PP10G_FC_RX_R_RDY_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx total octets cnt",
    0,
    TEN_PP10G_FC_RX_TOTAL_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "xcode rx errcor superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_ERRCOR_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx err frames cnt",
    0,
    TEN_PP10G_XCODE_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx err superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_ERR_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx frames cnt",
    0,
    TEN_PP10G_XCODE_RX_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx good superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_GOOD_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx long frames cnt",
    0,
    TEN_PP10G_XCODE_RX_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx short frames cnt",
    0,
    TEN_PP10G_XCODE_RX_SHORT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err frames cnt",
    TEN_PP10G_XCODE_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx good frames cnt",
    TEN_PP10G_XCODE_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx good superblocks cnt",
    TEN_PP10G_XCODE_TX_GOOD_SUPERBLOCKS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode rx octets cnt",
    0,
    TEN_PP10G_XCODE_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err codewords cnt",
    TEN_PP10G_XCODE_TX_ERR_CODEWORDS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err syncwords cnt",
    TEN_PP10G_XCODE_TX_ERR_SYNCWORDS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx octets cnt",
    TEN_PP10G_XCODE_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "egpcs rx err frames cnt",
    0,
    TEN_PP10G_EGPCS_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx good frames cnt",
    0,
    TEN_PP10G_EGPCS_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs tx err frames cnt",
    TEN_PP10G_EGPCS_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_EGPCS  /* block active check */
  },
  
  {
    "egpcs tx good frames cnt",
    TEN_PP10G_EGPCS_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx tc err cnt",
    0,
    TEN_PP10G_EGPCS_RX_TC_ERR_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx tw err cnt",
    0,
    TEN_PP10G_EGPCS_RX_TW_ERR_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "xgadj rx discarded frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx errored frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_ERRORED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx micro extracted frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_MICRO_EXTRACTED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx total frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_TOTAL_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx discarded frames cnt",
    TEN_PP10G_XGADJ_TX_DISCARDED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx errored frames cnt",
    TEN_PP10G_XGADJ_TX_ERRORED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx micro inserted frames cnt",
    TEN_PP10G_XGADJ_TX_MICRO_INSERTED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx total frames cnt",
    TEN_PP10G_XGADJ_TX_TOTAL_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded idle octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_IDLE_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded seq ordered sets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_SEQUENCE_ORDERED_SETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx errored octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_ERRORED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET /* block active check */
  },
  
  {
    "xgadj rx micro extracted octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_MICRO_EXTRACTED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx total octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_TOTAL_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx discarded octets cnt",
    TEN_PP10G_XGADJ_TX_DISCARDED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx errored octets cnt",
    TEN_PP10G_XGADJ_TX_ERRORED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx inserted idle octets cnt",
    TEN_PP10G_XGADJ_TX_INSERTED_IDLE_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx micro inserted octets cnt",
    TEN_PP10G_XGADJ_TX_MICRO_INSERTED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx total octets cnt",
    TEN_PP10G_XGADJ_TX_TOTAL_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },

  /* For T41 */
  /* Bugzilla #30084, PP10G_MON10B Stats - Good/Err Frames are switched */
  {
    "mon10b rx good frames",
    0,
    TEN_PP10G_MON10B_RX_GOOD_FRAMES,
    3,
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },
  
  {
    "mon10b rx err frames",
    0,
    TEN_PP10G_MON10B_RX_ERR_FRAMES,
    3,
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx err octets",
    0,
    TEN_PP10G_MON10B_RX_ERR_OCTETS,
    3,
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx good octets",
    0,
    TEN_PP10G_MON10B_RX_GOOD_OCTETS,
    3,
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx symbol err",
    0,
    TEN_PP10G_MON10B_RX_SYMBOL_ERR,
    3,
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mac rx bad octets",
    0,
    TEN_PP10G_MAC_RX_BAD_OCTETS,
    3,
    1, /* slice 1 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },

  {
    "mac tx bad octets",
    TEN_PP10G_MAC_TX_BAD_OCTETS,
    0,
    3,
    1, /* slice 1 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  }
};

/******************************************************************************
 * PP10G STATS TABLE (SLICE 2)
 ******************************************************************************/
const ten_stats_info_t stats_table_pp10g_2[TEN_PP10G_MAX_STAT] = {
  {
    "mac drop rx align err frames cnt",
    0,
    TEN_PP10G_MAC_DROP_RX_ALIGN_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac drop rx crc err frames cnt",
    0,
    TEN_PP10G_MAC_DROP_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 1024b to 1518b frames cnt",
    0,
    TEN_PP10G_MAC_RX_1024B_TO_1518B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 128b to 255b frames cnt",
    0,
    TEN_PP10G_MAC_RX_128B_TO_255B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 1519b to maxb frames cnt",
    0,
    TEN_PP10G_MAC_RX_1519B_TO_MAXB_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 256b to 511b frames cnt",
    0,
    TEN_PP10G_MAC_RX_256B_TO_511B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 512b to 1023b frames cnt",
    0,
    TEN_PP10G_MAC_RX_512B_TO_1023B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 64b frames cnt",
    0,
    TEN_PP10G_MAC_RX_64B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 65b to 127b frames cnt",
    0,
    TEN_PP10G_MAC_RX_65B_TO_127B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx align err frames cnt",
    0,
    TEN_PP10G_MAC_RX_ALIGN_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx bcast frames cnt",
    0,
    TEN_PP10G_MAC_RX_BCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx crc err frames cnt",
    0,
    TEN_PP10G_MAC_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx err frames cnt",
    0,
    TEN_PP10G_MAC_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx frames cnt",
    0,
    TEN_PP10G_MAC_RX_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx giant frames cnt",
    0,
    TEN_PP10G_MAC_RX_GIANT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx good frames cnt",
    0,
    TEN_PP10G_MAC_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx jabber frames cnt",
    0,
    TEN_PP10G_MAC_RX_JABBER_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx mcast frames cnt",
    0,
    TEN_PP10G_MAC_RX_MCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx pause frames cnt",
    0,
    TEN_PP10G_MAC_RX_PAUSE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx runt frames cnt",
    0,
    TEN_PP10G_MAC_RX_RUNT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx short frames cnt",
    0,
    TEN_PP10G_MAC_RX_SHORT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx ucast frames cnt",
    0,
    TEN_PP10G_MAC_RX_UCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx undersize frames cnt",
    0,
    TEN_PP10G_MAC_RX_UNDERSIZE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac tx 1024b to 1518b frames cnt",
    TEN_PP10G_MAC_TX_1024B_TO_1518B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 128b to 255b frames cnt",
    TEN_PP10G_MAC_TX_128B_TO_255B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 1519b frames cnt",
    TEN_PP10G_MAC_TX_1519B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 256b to 511b frames cnt",
    TEN_PP10G_MAC_TX_256B_TO_511B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 512b to 1023b frames cnt",
    TEN_PP10G_MAC_TX_512B_TO_1023B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 64b frames cnt",
    TEN_PP10G_MAC_TX_64B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 65b to 127b frames cnt",
    TEN_PP10G_MAC_TX_65B_TO_127B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx bcast frames cnt",
    TEN_PP10G_MAC_TX_BCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx err frames cnt",
    TEN_PP10G_MAC_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx frames cnt",
    TEN_PP10G_MAC_TX_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx good frames cnt",
    TEN_PP10G_MAC_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx mcast frames cnt",
    TEN_PP10G_MAC_TX_MCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause detected frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_DETECTED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause err frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx ucast frames cnt",
    TEN_PP10G_MAC_TX_UCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac rx good octets cnt",
    0,
    TEN_PP10G_MAC_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx octets cnt",
    0,
    TEN_PP10G_MAC_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac tx good octets cnt",
    TEN_PP10G_MAC_TX_GOOD_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx inserted pause quanta cnt",
    TEN_PP10G_MAC_TX_INSERTED_PAUSE_QUANTA_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx octets cnt",
    TEN_PP10G_MAC_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx total pause quanta cnt",
    TEN_PP10G_MAC_TX_TOTAL_PAUSE_QUANTA_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "rs tx trunk frames cnt",
    TEN_PP10G_RS_TX_TRUNK_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "pcs49 rx err frames cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx good frames cnt",
    0,
    TEN_PP10G_PCS49_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 tx err frames cnt",
    TEN_PP10G_PCS49_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 tx good frames cnt",
    TEN_PP10G_PCS49_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err ber cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_BER_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err dec cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_DEC_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err pat cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_PAT_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "xaui rx err frames cnt",
    0,
    TEN_PP10G_XAUI_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx good frames cnt",
    0,
    TEN_PP10G_XAUI_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui tx err frames cnt",
    TEN_PP10G_XAUI_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_BASEX  /* block active check */
  },
  
  {
    "xaui tx good frames cnt",
    TEN_PP10G_XAUI_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln0 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN0_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln1 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN1_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln2 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN2_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln3 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN3_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln0 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN0_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln1 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN1_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln2 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN2_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln3 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN3_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "gfp rx ch err frames cnt",
    0,
    TEN_PP10G_GFP_RX_CH_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx cmf frames cnt",
    0,
    TEN_PP10G_GFP_RX_CMF_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx discard frames cnt",
    0,
    TEN_PP10G_GFP_RX_DISCARD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx exm frames cnt",
    0,
    TEN_PP10G_GFP_RX_EXM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx fcs err frames cnt",
    0,
    TEN_PP10G_GFP_RX_FCS_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx good frames cnt",
    0,
    TEN_PP10G_GFP_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx long frames cnt",
    0,
    TEN_PP10G_GFP_RX_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx mcf frames cnt",
    0,
    TEN_PP10G_GFP_RX_MCF_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx ph err frames cnt",
    0,
    TEN_PP10G_GFP_RX_PH_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx ptm frames cnt",
    0,
    TEN_PP10G_GFP_RX_PTM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx upm frames cnt",
    0,
    TEN_PP10G_GFP_RX_UPM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp tx cmf frames cnt",
    TEN_PP10G_GFP_TX_CMF_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx err frames cnt",
    TEN_PP10G_GFP_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx good frames cnt",
    TEN_PP10G_GFP_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx mcf frames cnt",
    TEN_PP10G_GFP_TX_MCF_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp rx good octets cnt",
    0,
    TEN_PP10G_GFP_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx octets cnt",
    0,
    TEN_PP10G_GFP_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp tx good octets cnt",
    TEN_PP10G_GFP_TX_GOOD_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx octets cnt",
    TEN_PP10G_GFP_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "fc rx crc err frames cnt",
    0,
    TEN_PP10G_FC_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx good frames cnt",
    0,
    TEN_PP10G_FC_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx oversize frames cnt",
    0,
    TEN_PP10G_FC_RX_OVERSIZE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx too long frames cnt",
    0,
    TEN_PP10G_FC_RX_TOO_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx total frames cnt",
    0,
    TEN_PP10G_FC_RX_TOTAL_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx trunc frames cnt",
    0,
    TEN_PP10G_FC_RX_TRUNC_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx good octets cnt",
    0,
    TEN_PP10G_FC_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx prim cnt",
    0,
    TEN_PP10G_FC_RX_PRIM_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx r rdy cnt",
    0,
    TEN_PP10G_FC_RX_R_RDY_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx total octets cnt",
    0,
    TEN_PP10G_FC_RX_TOTAL_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "xcode rx errcor superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_ERRCOR_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx err frames cnt",
    0,
    TEN_PP10G_XCODE_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx err superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_ERR_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx frames cnt",
    0,
    TEN_PP10G_XCODE_RX_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx good superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_GOOD_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx long frames cnt",
    0,
    TEN_PP10G_XCODE_RX_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx short frames cnt",
    0,
    TEN_PP10G_XCODE_RX_SHORT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err frames cnt",
    TEN_PP10G_XCODE_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx good frames cnt",
    TEN_PP10G_XCODE_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx good superblocks cnt",
    TEN_PP10G_XCODE_TX_GOOD_SUPERBLOCKS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode rx octets cnt",
    0,
    TEN_PP10G_XCODE_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err codewords cnt",
    TEN_PP10G_XCODE_TX_ERR_CODEWORDS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err syncwords cnt",
    TEN_PP10G_XCODE_TX_ERR_SYNCWORDS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx octets cnt",
    TEN_PP10G_XCODE_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "egpcs rx err frames cnt",
    0,
    TEN_PP10G_EGPCS_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx good frames cnt",
    0,
    TEN_PP10G_EGPCS_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs tx err frames cnt",
    TEN_PP10G_EGPCS_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_EGPCS  /* block active check */
  },
  
  {
    "egpcs tx good frames cnt",
    TEN_PP10G_EGPCS_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx tc err cnt",
    0,
    TEN_PP10G_EGPCS_RX_TC_ERR_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx tw err cnt",
    0,
    TEN_PP10G_EGPCS_RX_TW_ERR_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "xgadj rx discarded frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx errored frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_ERRORED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx micro extracted frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_MICRO_EXTRACTED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx total frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_TOTAL_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx discarded frames cnt",
    TEN_PP10G_XGADJ_TX_DISCARDED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx errored frames cnt",
    TEN_PP10G_XGADJ_TX_ERRORED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx micro inserted frames cnt",
    TEN_PP10G_XGADJ_TX_MICRO_INSERTED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx total frames cnt",
    TEN_PP10G_XGADJ_TX_TOTAL_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded idle octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_IDLE_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded seq ordered sets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_SEQUENCE_ORDERED_SETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx errored octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_ERRORED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET /* block active check */
  },
  
  {
    "xgadj rx micro extracted octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_MICRO_EXTRACTED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx total octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_TOTAL_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx discarded octets cnt",
    TEN_PP10G_XGADJ_TX_DISCARDED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx errored octets cnt",
    TEN_PP10G_XGADJ_TX_ERRORED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx inserted idle octets cnt",
    TEN_PP10G_XGADJ_TX_INSERTED_IDLE_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx micro inserted octets cnt",
    TEN_PP10G_XGADJ_TX_MICRO_INSERTED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx total octets cnt",
    TEN_PP10G_XGADJ_TX_TOTAL_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },

  /* For T41 */
  /* Bugzilla #30084, PP10G_MON10B Stats - Good/Err Frames are switched */
  {
    "mon10b rx good frames",
    0,
    TEN_PP10G_MON10B_RX_GOOD_FRAMES,
    3,
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },
  
  {
    "mon10b rx err frames",
    0,
    TEN_PP10G_MON10B_RX_ERR_FRAMES,
    3,
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx err octets",
    0,
    TEN_PP10G_MON10B_RX_ERR_OCTETS,
    3,
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx good octets",
    0,
    TEN_PP10G_MON10B_RX_GOOD_OCTETS,
    3,
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx symbol err",
    0,
    TEN_PP10G_MON10B_RX_SYMBOL_ERR,
    3,
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mac rx bad octets",
    0,
    TEN_PP10G_MAC_RX_BAD_OCTETS,
    3,
    2, /* slice 2 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },

  {
    "mac tx bad octets",
    TEN_PP10G_MAC_TX_BAD_OCTETS,
    0,
    3,
    2, /* slice 2 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  }
};

/******************************************************************************
 * PP10G STATS TABLE (SLICE 3)
 ******************************************************************************/
const ten_stats_info_t stats_table_pp10g_3[TEN_PP10G_MAX_STAT] = {
  
  {
    "mac drop rx align err frames cnt",
    0,
    TEN_PP10G_MAC_DROP_RX_ALIGN_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac drop rx crc err frames cnt",
    0,
    TEN_PP10G_MAC_DROP_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 1024b to 1518b frames cnt",
    0,
    TEN_PP10G_MAC_RX_1024B_TO_1518B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 128b to 255b frames cnt",
    0,
    TEN_PP10G_MAC_RX_128B_TO_255B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 1519b to maxb frames cnt",
    0,
    TEN_PP10G_MAC_RX_1519B_TO_MAXB_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 256b to 511b frames cnt",
    0,
    TEN_PP10G_MAC_RX_256B_TO_511B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 512b to 1023b frames cnt",
    0,
    TEN_PP10G_MAC_RX_512B_TO_1023B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 64b frames cnt",
    0,
    TEN_PP10G_MAC_RX_64B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx 65b to 127b frames cnt",
    0,
    TEN_PP10G_MAC_RX_65B_TO_127B_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx align err frames cnt",
    0,
    TEN_PP10G_MAC_RX_ALIGN_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx bcast frames cnt",
    0,
    TEN_PP10G_MAC_RX_BCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx crc err frames cnt",
    0,
    TEN_PP10G_MAC_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx err frames cnt",
    0,
    TEN_PP10G_MAC_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx frames cnt",
    0,
    TEN_PP10G_MAC_RX_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx giant frames cnt",
    0,
    TEN_PP10G_MAC_RX_GIANT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx good frames cnt",
    0,
    TEN_PP10G_MAC_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx jabber frames cnt",
    0,
    TEN_PP10G_MAC_RX_JABBER_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx mcast frames cnt",
    0,
    TEN_PP10G_MAC_RX_MCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx pause frames cnt",
    0,
    TEN_PP10G_MAC_RX_PAUSE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx runt frames cnt",
    0,
    TEN_PP10G_MAC_RX_RUNT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx short frames cnt",
    0,
    TEN_PP10G_MAC_RX_SHORT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx ucast frames cnt",
    0,
    TEN_PP10G_MAC_RX_UCAST_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx undersize frames cnt",
    0,
    TEN_PP10G_MAC_RX_UNDERSIZE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac tx 1024b to 1518b frames cnt",
    TEN_PP10G_MAC_TX_1024B_TO_1518B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 128b to 255b frames cnt",
    TEN_PP10G_MAC_TX_128B_TO_255B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 1519b frames cnt",
    TEN_PP10G_MAC_TX_1519B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 256b to 511b frames cnt",
    TEN_PP10G_MAC_TX_256B_TO_511B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 512b to 1023b frames cnt",
    TEN_PP10G_MAC_TX_512B_TO_1023B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 64b frames cnt",
    TEN_PP10G_MAC_TX_64B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx 65b to 127b frames cnt",
    TEN_PP10G_MAC_TX_65B_TO_127B_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx bcast frames cnt",
    TEN_PP10G_MAC_TX_BCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx err frames cnt",
    TEN_PP10G_MAC_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx frames cnt",
    TEN_PP10G_MAC_TX_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx good frames cnt",
    TEN_PP10G_MAC_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx mcast frames cnt",
    TEN_PP10G_MAC_TX_MCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause detected frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_DETECTED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause err frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx pause frames cnt",
    TEN_PP10G_MAC_TX_PAUSE_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx ucast frames cnt",
    TEN_PP10G_MAC_TX_UCAST_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac rx good octets cnt",
    0,
    TEN_PP10G_MAC_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac rx octets cnt",
    0,
    TEN_PP10G_MAC_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },
  
  {
    "mac tx good octets cnt",
    TEN_PP10G_MAC_TX_GOOD_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx inserted pause quanta cnt",
    TEN_PP10G_MAC_TX_INSERTED_PAUSE_QUANTA_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx octets cnt",
    TEN_PP10G_MAC_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "mac tx total pause quanta cnt",
    TEN_PP10G_MAC_TX_TOTAL_PAUSE_QUANTA_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_MAC  /* block active check */
  },
  
  {
    "rs tx trunk frames cnt",
    TEN_PP10G_RS_TX_TRUNK_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "pcs49 rx err frames cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx good frames cnt",
    0,
    TEN_PP10G_PCS49_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 tx err frames cnt",
    TEN_PP10G_PCS49_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 tx good frames cnt",
    TEN_PP10G_PCS49_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err ber cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_BER_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err dec cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_DEC_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "pcs49 rx err pat cnt",
    0,
    TEN_PP10G_PCS49_RX_ERR_PAT_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XGPCS  /* block active check */
  },
  
  {
    "xaui rx err frames cnt",
    0,
    TEN_PP10G_XAUI_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx good frames cnt",
    0,
    TEN_PP10G_XAUI_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui tx err frames cnt",
    TEN_PP10G_XAUI_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_BASEX  /* block active check */
  },
  
  {
    "xaui tx good frames cnt",
    TEN_PP10G_XAUI_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln0 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN0_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln1 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN1_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln2 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN2_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx icc ln3 cnt",
    0,
    TEN_PP10G_XAUI_RX_ICC_LN3_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln0 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN0_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln1 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN1_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln2 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN2_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "xaui rx pec ln3 cnt",
    0,
    TEN_PP10G_XAUI_RX_PEC_LN3_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_BASEX  /* block active check */
  },
  
  {
    "gfp rx ch err frames cnt",
    0,
    TEN_PP10G_GFP_RX_CH_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx cmf frames cnt",
    0,
    TEN_PP10G_GFP_RX_CMF_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx discard frames cnt",
    0,
    TEN_PP10G_GFP_RX_DISCARD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx exm frames cnt",
    0,
    TEN_PP10G_GFP_RX_EXM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx fcs err frames cnt",
    0,
    TEN_PP10G_GFP_RX_FCS_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx good frames cnt",
    0,
    TEN_PP10G_GFP_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx long frames cnt",
    0,
    TEN_PP10G_GFP_RX_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx mcf frames cnt",
    0,
    TEN_PP10G_GFP_RX_MCF_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx ph err frames cnt",
    0,
    TEN_PP10G_GFP_RX_PH_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx ptm frames cnt",
    0,
    TEN_PP10G_GFP_RX_PTM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx upm frames cnt",
    0,
    TEN_PP10G_GFP_RX_UPM_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp tx cmf frames cnt",
    TEN_PP10G_GFP_TX_CMF_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx err frames cnt",
    TEN_PP10G_GFP_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx good frames cnt",
    TEN_PP10G_GFP_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx mcf frames cnt",
    TEN_PP10G_GFP_TX_MCF_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp rx good octets cnt",
    0,
    TEN_PP10G_GFP_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp rx octets cnt",
    0,
    TEN_PP10G_GFP_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_GFP  /* block active check */
  },
  
  {
    "gfp tx good octets cnt",
    TEN_PP10G_GFP_TX_GOOD_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "gfp tx octets cnt",
    TEN_PP10G_GFP_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_GFP  /* block active check */
  },
  
  {
    "fc rx crc err frames cnt",
    0,
    TEN_PP10G_FC_RX_CRC_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx good frames cnt",
    0,
    TEN_PP10G_FC_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx oversize frames cnt",
    0,
    TEN_PP10G_FC_RX_OVERSIZE_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx too long frames cnt",
    0,
    TEN_PP10G_FC_RX_TOO_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx total frames cnt",
    0,
    TEN_PP10G_FC_RX_TOTAL_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx trunc frames cnt",
    0,
    TEN_PP10G_FC_RX_TRUNC_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx good octets cnt",
    0,
    TEN_PP10G_FC_RX_GOOD_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx prim cnt",
    0,
    TEN_PP10G_FC_RX_PRIM_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx r rdy cnt",
    0,
    TEN_PP10G_FC_RX_R_RDY_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "fc rx total octets cnt",
    0,
    TEN_PP10G_FC_RX_TOTAL_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_FC  /* block active check */
  },
  
  {
    "xcode rx errcor superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_ERRCOR_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx err frames cnt",
    0,
    TEN_PP10G_XCODE_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx err superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_ERR_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx frames cnt",
    0,
    TEN_PP10G_XCODE_RX_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx good superblocks cnt",
    0,
    TEN_PP10G_XCODE_RX_GOOD_SUPERBLOCKS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx long frames cnt",
    0,
    TEN_PP10G_XCODE_RX_LONG_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode rx short frames cnt",
    0,
    TEN_PP10G_XCODE_RX_SHORT_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err frames cnt",
    TEN_PP10G_XCODE_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx good frames cnt",
    TEN_PP10G_XCODE_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx good superblocks cnt",
    TEN_PP10G_XCODE_TX_GOOD_SUPERBLOCKS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode rx octets cnt",
    0,
    TEN_PP10G_XCODE_RX_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err codewords cnt",
    TEN_PP10G_XCODE_TX_ERR_CODEWORDS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx err syncwords cnt",
    TEN_PP10G_XCODE_TX_ERR_SYNCWORDS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "xcode tx octets cnt",
    TEN_PP10G_XCODE_TX_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_XCODE  /* block active check */
  },
  
  {
    "egpcs rx err frames cnt",
    0,
    TEN_PP10G_EGPCS_RX_ERR_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx good frames cnt",
    0,
    TEN_PP10G_EGPCS_RX_GOOD_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs tx err frames cnt",
    TEN_PP10G_EGPCS_TX_ERR_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_EGPCS  /* block active check */
  },
  
  {
    "egpcs tx good frames cnt",
    TEN_PP10G_EGPCS_TX_GOOD_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_TX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx tc err cnt",
    0,
    TEN_PP10G_EGPCS_RX_TC_ERR_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "egpcs rx tw err cnt",
    0,
    TEN_PP10G_EGPCS_RX_TW_ERR_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_EGPCS  /* block active check */
  },
  
  {
    "xgadj rx discarded frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx errored frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_ERRORED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx micro extracted frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_MICRO_EXTRACTED_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx total frames cnt",
    0,
    TEN_PP10G_XGADJ_RX_TOTAL_FRAMES_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx discarded frames cnt",
    TEN_PP10G_XGADJ_TX_DISCARDED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx errored frames cnt",
    TEN_PP10G_XGADJ_TX_ERRORED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx micro inserted frames cnt",
    TEN_PP10G_XGADJ_TX_MICRO_INSERTED_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx total frames cnt",
    TEN_PP10G_XGADJ_TX_TOTAL_FRAMES_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded idle octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_IDLE_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx discarded seq ordered sets cnt",
    0,
    TEN_PP10G_XGADJ_RX_DISCARDED_SEQUENCE_ORDERED_SETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx errored octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_ERRORED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET /* block active check */
  },
  
  {
    "xgadj rx micro extracted octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_MICRO_EXTRACTED_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj rx total octets cnt",
    0,
    TEN_PP10G_XGADJ_RX_TOTAL_OCTETS_STAT,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx discarded octets cnt",
    TEN_PP10G_XGADJ_TX_DISCARDED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx errored octets cnt",
    TEN_PP10G_XGADJ_TX_ERRORED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx inserted idle octets cnt",
    TEN_PP10G_XGADJ_TX_INSERTED_IDLE_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx micro inserted octets cnt",
    TEN_PP10G_XGADJ_TX_MICRO_INSERTED_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },
  
  {
    "xgadj tx total octets cnt",
    TEN_PP10G_XGADJ_TX_TOTAL_OCTETS_STAT,
    0,
    3, /* 48 bit indirect counter */
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_MISC_RESET  /* block active check */
  },

  /* For T41 */
  /* Bugzilla #30084, PP10G_MON10B Stats - Good/Err Frames are switched */
  {
    "mon10b rx good frames",
    0,
    TEN_PP10G_MON10B_RX_GOOD_FRAMES,
    3,
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },
  
  {
    "mon10b rx err frames",
    0,
    TEN_PP10G_MON10B_RX_ERR_FRAMES,
    3,
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx err octets",
    0,
    TEN_PP10G_MON10B_RX_ERR_OCTETS,
    3,
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx good octets",
    0,
    TEN_PP10G_MON10B_RX_GOOD_OCTETS,
    3,
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mon10b rx symbol err",
    0,
    TEN_PP10G_MON10B_RX_SYMBOL_ERR,
    3,
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MON10  /* block active check */
  },

  {
    "mac rx bad octets",
    0,
    TEN_PP10G_MAC_RX_BAD_OCTETS,
    3,
    3, /* slice 3 */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  },

  {
    "mac tx bad octets",
    TEN_PP10G_MAC_TX_BAD_OCTETS,
    0,
    3,
    3, /* slice 3 */
    TEN_STATS_FLAG_TX_VALID | TEN_STATS_FLAG_INDIRECT | TEN_STATS_FLAG_TIMING_INTERVAL,
    TEN_STATS_CHECK_PP10G_RX_MAC  /* block active check */
  }
};


/******************************************************************************
 * CFP32X1 STATS TABLE ( 4 slices )
 ******************************************************************************/
/* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
const ten_stats_info_t stats_table_hsif_cfp[4] = {
  {
    "cfp32x1 sds common prbschk0 count slice 0",            /* user-friendly cntr name string */
    0,                                                      /* TX register offset             */
    TEN_CFP32X1_REG_OFST(PRBSCHK0_Count1, 0),               /* RX register offset             */
    2, /* 32 bit counter */                                 /* num of regs make up the cntr   */
    0,                                                      /* slice value                    */
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR | TEN_STATS_MODULE_B_ONLY, /* Flags to characterize the stat */
    TEN_STATS_CHECK_CFP_MR  /* block active check */
  },
    
  {
    "cfp32x1 sds common prbschk0 count slice 1",
    0,
    TEN_CFP32X1_REG_OFST(PRBSCHK0_Count1, 1),
    2, /* 32 bit counter */
    1,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR | TEN_STATS_MODULE_B_ONLY,
    TEN_STATS_CHECK_CFP_MR  /* block active check */
  },
  
  {
    "cfp32x1 sds common prbschk0 count slice 2",
    0,
    TEN_CFP32X1_REG_OFST(PRBSCHK0_Count1, 2),
    2, /* 32 bit counter */
    2,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR | TEN_STATS_MODULE_B_ONLY,
    TEN_STATS_CHECK_CFP_MR  /* block active check */
  },
  
  {
    "cfp32x1 sds common prbschk0 count slice 3",
    0,
    TEN_CFP32X1_REG_OFST(PRBSCHK0_Count1, 3),
    2, /* 32 bit counter */
    3,
    TEN_STATS_FLAG_RX_VALID | TEN_STATS_FLAG_RX_READ_CLR | TEN_STATS_MODULE_B_ONLY,
    TEN_STATS_CHECK_CFP_MR  /* block active check */
  }
};




