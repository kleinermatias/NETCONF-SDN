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
 * ten_fec10g.c
 *
 * FEC10G related code is implemented here.
 *
 * $Id: ten_gfec.c,v 1.10 2013/02/22 20:48:57 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  GFEC 10G SOFT (LOGIC) RESET                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_reset(cs_uint16 module_id, 
                             cs_uint8 slice,
                             cs_dir_t dir, 
                             cs_reset_action_t act)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Control                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Disable/enable 10G GFEC sub-block logic reset for the        */
/* specified datapath direction.                                */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FTX_TXCFG_t tmp_txcfg;
  TEN_GFEC10G_FRX_RSCFG_t tmp_rscfg;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_reset Param2"); 
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) { 
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_reset Param3"); 
    return CS_ERROR; 
  }
  if(act > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_reset Param4"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);
  
  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        tmp_rscfg.wrd = 0;
        tmp_rscfg.bf.RXRST = 1;
        ten_reset_action(TEN_GFEC10G_REG_ADDR(pDev, ii, RSCFG), tmp_rscfg.wrd, act); 
      }
            
      if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        tmp_txcfg.wrd = 0;
        tmp_txcfg.bf.TXRST = 1;
        ten_reset_action(TEN_GFEC10G_REG_ADDR(pDev, ii, TXCFG), tmp_txcfg.wrd, act); 
      }
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 10G ERROR CORRECTION ENABLE             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_ec_enable(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_ctl_t enable)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Enable                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable or disable 10G GFEC error correction                  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [enable] parameter enables error correction              */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FRX_RSCFG_t tmp_rscfg;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_ec_enable Param2");
    return(CS_ERROR);
  }
  if (enable > 1) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_ec_enable Param3");
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);
  
  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_rscfg.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, RSCFG));
      tmp_rscfg.bf.CORE = enable;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, RSCFG), tmp_rscfg.wrd);
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 10G EXCESSIVE ERROR LIMIT               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_set_excess_error_flag(cs_uint16 module_id, 
                                             cs_uint8 slice,
                                             cs_uint32 error_flag,
                                             ten_err_source_t error_src,
                                             ten_fec_time_unit_sel_t gi_sel)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Error Flag                                    */
/*              o Error Source                                  */
/*              o Global Stats Timing Gen                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the limit for setting Excessive Error Flag               */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [error_flag] parameter is specified as:                  */
/*   0 - 0xFFFFFF                                               */
/*                                                              */
/* The [error_src] parameter  selects the source for RMBYTER    */
/* threshold monitoring                                         */
/*   0 = TEN_BYTE_ERROR                                         */
/*   1 = TEN_ZERO_ERROR                                         */
/*   2 = TEN_ONE_ERROR                                          */
/*                                                              */
/* The [gi_sel] parameter is specified as:                      */
/*   0   = TEN_INT_TIME_SOURCE_1                                */
/*   1   = TEN_INT_TIME_SOURCE_2                                */
/*   2   = TEN_INT_TIME_SOURCE_3                                */
/*   3   = TEN_INT_TIME_SOURCE_4                                */
/*   4   = TEN_INT_TIME_SOURCE_5                                */
/*   5   = TEN_INT_TIME_SOURCE_6                                */
/*   6   = TEN_SW_TIME_SOURCE                                   */
/*   7   = TEN_EXT_TIME_SOURCE                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FRX_RMBYTER0_t tmp_rmbyter0;
  TEN_GFEC10G_FRX_RMBYTER0_t tmp_rmbyter1;
  TEN_GFEC10G_FRX_RSCFG_t tmp_rscfg;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_excess_error_flag Param2"); 
    return(CS_ERROR);
  }
  if (error_flag > 0xFFFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_excess_error_flag Param3"); 
    return(CS_ERROR);
  }
  if (error_src > TEN_ONE_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_excess_error_flag Param4"); 
    return(CS_ERROR);
  }
  if (gi_sel > TEN_EXT_TIME_SOURCE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_excess_error_flag Param5"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);
  
  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_rmbyter0.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, RMBYTER0));
      tmp_rmbyter0.bf.RMBYTER0 = error_flag & 0xFFFF;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, RMBYTER0), tmp_rmbyter0.wrd);

      tmp_rmbyter1.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, RMBYTER1));
      tmp_rmbyter1.bf.RMBYTER0 = (cs_uint16)((error_flag & 0xFF0000) >> 16);
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, RMBYTER1), tmp_rmbyter1.wrd);

      tmp_rscfg.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, RSCFG));
      tmp_rscfg.bf.EXESEL = error_src;
      tmp_rscfg.bf.GISEL = gi_sel;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, RSCFG), tmp_rscfg.wrd);
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 10G ENABLE G709 SCRAMBLER FOR STATS     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_stats_enable_scrambler(cs_uint16 module_id,
                                              cs_uint8 slice,
                                              cs_ctl_t scrmblr_enbl)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Scrambler Enable                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Ther data is descrambled to detect the errors. In order to   */
/* collect stats this data needs to be rescrambled before       */
/* comparing with the incoming data                             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [scrmblr_enbl] parameter enables the G.709 scrambler for */
/* the received/corrected data before the 0/1 statistics are    */
/* collected                                                    */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FRX_RSCFG_t tmp_rscfg;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_stats_enable_scrambler Param2"); 
    return(CS_ERROR);
  }
  if(scrmblr_enbl > CS_ENABLE) { 
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_stats_enable_scrambler Param3"); 
    return CS_ERROR;
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);

  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_rscfg.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, RSCFG));
      tmp_rscfg.bf.STATSCREn = scrmblr_enbl;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, RSCFG), tmp_rscfg.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 10G SET EXCESS ERROR DETECT THRESHOLDS  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_set_eed_threshold(cs_uint16 module_id, 
                                         cs_uint8 slice,
                                         cs_uint32 ceed_thres, 
                                         cs_uint32 seed_thres)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Clear EED seed threshold                      */
/*              o Set EED seed threshold                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure excessive error detect seed thresholds to set and  */
/* clear BER threshold alarms                                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [ceed_thres] parameter is specified as:                  */
/*   0 - 0xFFFFF                                                */
/*                                                              */
/* The [seed_thres] parameter is specified as:                  */
/*   0 - 0xFFFFF                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FRX_SEED_THR_LOW_t tmp_seed_thr_low;
  TEN_GFEC10G_FRX_SEED_THR_UP_t tmp_seed_thr_up;
  TEN_GFEC10G_FRX_CEED_THR_LOW_t tmp_ceed_thr_low;
  TEN_GFEC10G_FRX_CEED_THR_UP_t tmp_ceed_thr_up;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_eed_threshold Param2"); 
    return(CS_ERROR);
  }
  if (ceed_thres > 0xFFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_eed_threshold Param3"); 
    return(CS_ERROR);
  }
  if (seed_thres > 0xFFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_eed_threshold Param4"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);
  
  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      /* SEED threshold lo*/
      tmp_seed_thr_low.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, SEED_THR_LOW));
      tmp_seed_thr_low.bf.seed_thr_low = seed_thres & 0xFFFF;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, SEED_THR_LOW), tmp_seed_thr_low.wrd);

      /* SEED threshold hi*/
      tmp_seed_thr_up.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, SEED_THR_UP));
      tmp_seed_thr_up.bf.seed_thr_up = (seed_thres & 0xF0000) >> 16;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, SEED_THR_UP), tmp_seed_thr_up.wrd);

      /* CEED threshold lo */
      tmp_ceed_thr_low.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, CEED_THR_LOW));
      tmp_ceed_thr_low.bf.ceed_thr_low = ceed_thres & 0xFFFF;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, CEED_THR_LOW), tmp_ceed_thr_low.wrd);

      /* CEED threshold hi*/
      tmp_ceed_thr_up.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, CEED_THR_UP));
      tmp_ceed_thr_up.bf.ceed_thr_up = (ceed_thres & 0xF0000) >> 16;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, CEED_THR_UP), tmp_ceed_thr_up.wrd);
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 10G SET SIGNAL DEGRADE THRESHOLDS       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_set_deg_threshold(cs_uint16 module_id, 
                                         cs_uint8 slice,
                                         cs_uint32 cdeg_thres, 
                                         cs_uint32 sdeg_thres)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Clear DEG threshold                           */
/*              o Set DEG threshold                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure signal degrade thresholds to set and clear BER DEG */
/* thresholds                                                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [cdeg_thr_lo] parameter is specified as:                 */
/*   0 - 0xFFFFF                                                */
/*                                                              */
/* The [sdeg_thr_hi] parameter is specified as:                 */
/*   0 - 0xFFFFF                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FRX_SDEG_THR_LOW_t tmp_sdeg_thr_low;
  TEN_GFEC10G_FRX_SDEG_THR_UP_t tmp_sdeg_thr_up;
  TEN_GFEC10G_FRX_CDEG_THR_LOW_t tmp_cdeg_thr_low;
  TEN_GFEC10G_FRX_CDEG_THR_UP_t tmp_cdeg_thr_up;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_deg_threshold Param2"); 
    return(CS_ERROR);
  }
  if (cdeg_thres > 0xFFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_deg_threshold Param3"); 
    return(CS_ERROR);
  }
  if (sdeg_thres > 0xFFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_deg_threshold Param4"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);
  
  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      /* SDEG threshold lo*/
      tmp_sdeg_thr_low.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, SDEG_THR_LOW));
      tmp_sdeg_thr_low.bf.sdeg_thr_low = sdeg_thres & 0xFFFF;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, SDEG_THR_LOW), tmp_sdeg_thr_low.wrd);

      /* SDEG threshold hi*/
      tmp_sdeg_thr_up.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, SDEG_THR_UP));
      tmp_sdeg_thr_up.bf.sdeg_thr_up = (sdeg_thres & 0xF0000) >> 16;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, SDEG_THR_UP), tmp_sdeg_thr_up.wrd);

      /* CDEG threshold lo */
      tmp_cdeg_thr_low.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, CDEG_THR_LOW));
      tmp_cdeg_thr_low.bf.cdeg_thr_low = cdeg_thres & 0xFFFF;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, CDEG_THR_LOW), tmp_cdeg_thr_low.wrd);

      /* CDEG threshold hi*/
      tmp_cdeg_thr_up.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, CDEG_THR_UP));
      tmp_cdeg_thr_up.bf.cdeg_thr_up = (cdeg_thres & 0xF0000) >> 16;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, CDEG_THR_UP), tmp_cdeg_thr_up.wrd);
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 10G SELECT ERROR TYPE                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_select_err_type(cs_uint16 module_id, 
                                       cs_uint8 slice,
                                       ten_fec_err_sel_t err_sel, 
                                       ten_gfec_err_type_t err_type)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Error Select                                  */
/*              o Error Type                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Select the error type for EED and DEG                        */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [err_sel] parameter is specfied as:                      */
/*   0 = TEN_SEED_ERSEL  select set excessive error defect      */
/*   1 = TEN_CEED_ERSEL  select clear excessive error defect    */
/*   2 = TEN_SDEG_ERSEL  select set signal degrade error        */
/*   3 = TEN_CDEG_ERSEL  select clear signal degrade error      */
/*                                                              */
/* The [err_type] parameter applies the thresholds to the error */
/* types as specified by:                                       */
/*   0 =    TEN_N0B_N1B_NUCODEWD_NCBYTE                         */
/*   1 =    TEN_N0B_N1B_NUCODEWD_YCBYTE                         */
/*   2 =    TEN_N0B_N1B_YUCODEWD_NCBYTE                         */
/*   3 =    TEN_N0B_N1B_YUCODEWD_YCBYTE                         */
/*   4 =    TEN_N0B_Y1B_NUCODEWD_NCBYTE                         */
/*   5 =    TEN_N0B_Y1B_NUCODEWD_YCBYTE                         */
/*   6 =    TEN_N0B_Y1B_YUCODEWD_NCBYTE                         */
/*   7 =    TEN_N0B_Y1B_YUCODEWD_YCBYTE                         */
/*   8 =    TEN_Y0B_N1B_NUCODEWD_NCBYTE                         */
/*   9 =    TEN_Y0B_N1B_NUCODEWD_YCBYTE                         */
/*  10 =    TEN_Y0B_N1B_YUCODEWD_NCBYTE                         */
/*  11 =    TEN_Y0B_N1B_YUCODEWD_YCBYTE                         */
/*  12 =    TEN_Y0B_Y1B_NUCODEWD_NCBYTE                         */
/*  13 =    TEN_Y0B_Y1B_NUCODEWD_YCBYTE                         */
/*  14 =    TEN_Y0B_Y1B_YUCODEWD_NCBYTE                         */
/*  15 =    TEN_Y0B_Y1B_YUCODEWD_YCBYTE                         */
/*  The first character specifies YES or NO                     */
/*  0B      - RX bit 0 and corrected bit 1                      */
/*  1B      - RX bit 1 and corrected bit 0                      */
/*  UCODEWD - Uncorrectable codewords                           */
/*  CBYTE   - Corrected bytes                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FRX_ERSEL_t tmp_ersel;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_select_err_type Param2"); 
    return(CS_ERROR);
  }
  if (err_sel > TEN_CDEG_ERSEL) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_select_err_type Param3"); 
    return(CS_ERROR);
  }
  if (err_type > TEN_Y0B_Y1B_YUCODEWD_YCBYTE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_select_err_type Param4"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);
  
  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_ersel.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, ERSEL));

      switch(err_sel) {
        case TEN_SEED_ERSEL:
          tmp_ersel.bf.seed_ersel = err_type;
          break;

        case TEN_CEED_ERSEL:
          tmp_ersel.bf.ceed_ersel = err_type;
          break;

        case TEN_SDEG_ERSEL:
          tmp_ersel.bf.sdeg_ersel = err_type;
          break;

        case TEN_CDEG_ERSEL:
          tmp_ersel.bf.cdeg_ersel = err_type;
          break;
      }

      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, ERSEL), tmp_ersel.wrd);
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 10G SELECT TIMER UNIT                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_select_timer_unit(cs_uint16 module_id, 
                                         cs_uint8 slice,
                                         cs_boolean err_sel,
                                         ten_fec_time_unit_sel_t tu_sel)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Error Select                                  */
/*              o Time Unit Selection                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure one of the eight independent global timers used    */
/* to determine the window size used by BER monitor             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [err_sel] parameter is specfied as:                      */
/*   0 = EED - Excessive error defect                           */
/*   1 = DEG - Signal degrade                                   */
/*                                                              */
/* The [tu_sel] parameter is specified as:                      */
/*   0   = TEN_INT_TIME_SOURCE_1                                */
/*   1   = TEN_INT_TIME_SOURCE_2                                */
/*   2   = TEN_INT_TIME_SOURCE_3                                */
/*   3   = TEN_INT_TIME_SOURCE_4                                */
/*   4   = TEN_INT_TIME_SOURCE_5                                */
/*   5   = TEN_INT_TIME_SOURCE_6                                */
/*   6   = TEN_SW_TIME_SOURCE                                   */
/*   7   = TEN_EXT_TIME_SOURCE                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FRX_TUSEL_t tmp_tusel;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_select_timer_unit Param2"); 
    return(CS_ERROR);
  }
  if (err_sel > 1) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_select_timer_unit Param3"); 
    return(CS_ERROR);
  }
  if (tu_sel > TEN_EXT_TIME_SOURCE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_select_timer_unit Param4"); 
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);

  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {  
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_tusel.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, TUSEL));
      
      switch(err_sel) {
        case 0:
          tmp_tusel.bf.eed_tusel = tu_sel;
          break;

        case 1:
          tmp_tusel.bf.deg_tusel = tu_sel;
          break;
      }
      
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, TUSEL), tmp_tusel.wrd);  
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 10G SET TIMING WINDOW SIZE              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_set_timing_win_size(cs_uint16 module_id,
                                           cs_uint8 slice,
                                           ten_fec_err_sel_t err_sel,
                                           cs_uint8 window_size)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Error Select                                  */
/*              o Window Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the size of timing window to clear the alarms      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [err_sel] parameter is specfied as:                      */
/*   0 = TEN_SEED_ERSEL  select "set excessive error defect"    */
/*   1 = TEN_CEED_ERSEL  select "clear excessive error defect"  */
/*   2 = TEN_SDEG_ERSEL  select "set signal degrade error"      */
/*   3 = TEN_CDEG_ERSEL  select "clear signal degrade error"    */
/*                                                              */
/* The [window_size] parameter is specified as:                 */
/*   0 - 0x2F                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FRX_EED_WIN_t tmp_eed_win;
  TEN_GFEC10G_FRX_DEG_WIN_t tmp_deg_win;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_timing_window_size Param2"); 
    return(CS_ERROR);
  }
  if (err_sel > TEN_CDEG_ERSEL) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_timing_window_size Param3"); 
    return(CS_ERROR);
  }
  if (window_size > 0x2F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_timing_window_size Param4"); 
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);

  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_eed_win.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, EED_WIN));

      tmp_deg_win.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, DEG_WIN));

      switch(err_sel) {
        case TEN_SEED_ERSEL:
          tmp_eed_win.bf.seed_win = window_size;
          break;

        case TEN_CEED_ERSEL:
          tmp_eed_win.bf.ceed_win = window_size;
          break;

        case TEN_SDEG_ERSEL:
          tmp_deg_win.bf.sdeg_win = window_size;
          break;

        case TEN_CDEG_ERSEL:
          tmp_deg_win.bf.cdeg_win = window_size;
          break;
      }

      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, EED_WIN), tmp_eed_win.wrd);

      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, DEG_WIN), tmp_deg_win.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 10G CONFIG FEC EED ALARM WINDOW PARAMS  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_config_fec_eed_alarm_win(cs_uint16 module_id,
                                                cs_uint8 slice,
                                                cs_uint8 seed_div,
                                                cs_uint8 seed_dtv,
                                                cs_uint8 ceed_niv,
                                                cs_uint8 ceed_ntv)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Set EED Defect Intermittant Value             */
/*              o Set EED Defect Threshold Value                */
/*              o Clear EED No Defect Intermittant Value        */
/*              o Clear EED No Defect Threshold Value           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure 10G GFEC dFECEED alarm windows settings            */
/* When more than SEED_DTV excessively-errored time windows are */
/* detected and no intervening error-free sequence occur for    */
/* longer than SEED_DIV intervals of SEED_WIN[5:0] x Selected   */
/* Time Unit, the Excessive Error Defect alarm (dFECEED) is set */
/* The Excessive Error Defect alarm (dFECEED) is cleared when   */
/* more than CEED_NTV non-excessively errored time windows are  */
/* detected without been intermitted by CEED_NIV errored time   */
/* windows                                                      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [seed_div] parameter is the set excessive error defect   */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [seed_dtv] parameter is the set excessive error defect   */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [ceed_niv] parameter is the clear excessive error defect */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [ceed_ntv] parameter is the clear excessive error defect */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FRX_EED_DTV_DIV_t tmp_eed_dtv_div;
  TEN_GFEC10G_FRX_EED_NTV_NIV_t tmp_eed_ntv_niv;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_fec_eed_alarm_win Param2"); 
    return(CS_ERROR);
  }
  if (seed_div > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_fec_eed_alarm_win Param3");
    return(CS_ERROR);
  }
  if (seed_dtv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_fec_eed_alarm_win Param4");
    return(CS_ERROR);
  }
  if (ceed_niv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_fec_eed_alarm_win Param5");
    return(CS_ERROR);
  }
  if (ceed_ntv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_fec_eed_alarm_win Param6");
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);

  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_eed_dtv_div.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, EED_DTV_DIV));
      tmp_eed_dtv_div.bf.seed_div = seed_div;
      tmp_eed_dtv_div.bf.seed_dtv = seed_dtv;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, EED_DTV_DIV), tmp_eed_dtv_div.wrd);

      tmp_eed_ntv_niv.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, EED_NTV_NIV));
      tmp_eed_ntv_niv.bf.ceed_niv = ceed_niv;
      tmp_eed_ntv_niv.bf.ceed_ntv = ceed_ntv;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, EED_NTV_NIV), tmp_eed_ntv_niv.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  GFEC 10G CONFIG FEC DEG ALARM WINDOW PARAMS  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_config_fec_deg_alarm_win(cs_uint16 module_id,
                                                cs_uint8 slice,
                                                cs_uint8 sdeg_div,
                                                cs_uint8 sdeg_dtv,
                                                cs_uint8 cdeg_niv,
                                                cs_uint8 cdeg_ntv)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Set DEG Defect Intermittant Value             */
/*              o Set DEG Defect Threshold Value                */
/*              o Clear DEG Defect Intermittant Value           */
/*              o Clear DEG Defect Threshold Value              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure 10G GFEC dFECDEG alarm windows settings            */
/* When more than SDEG_DTV degraded time windows are detected   */
/* and no intervening error-free sequence occur for longer than */
/* SDEG_DIV intervals of SDEG_WIN[5:0] x Selected Time Unit, the*/
/* Degraded Defect alarm (dFECDEG) is set.                      */
/* The Degraded Defect alarm (dFECDEG) is cleared when more than*/
/* CDEG_NTV non-degraded errored time windows are detected      */
/* without been intermitted by CDEG_NIV errored time windows.   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [sdeg_div] parameter is the set signal degrade defect    */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [sdeg_dtv] parameter is the set signal degrade defect    */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [cdeg_niv] parameter is the clear signal degrade defect  */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [cdeg_ntv] parameter is the clear signal degrade defect  */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GFEC10G_FRX_DEG_DTV_DIV_t tmp_deg_dtv_div;
  TEN_GFEC10G_FRX_DEG_NTV_NIV_t tmp_deg_ntv_niv;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_deg_eed_alarm_win Param2"); 
    return(CS_ERROR);
  }
  if (sdeg_div > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_deg_eed_alarm_win Param3"); 
    return(CS_ERROR);
  }
  if (sdeg_dtv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_deg_eed_alarm_win Param4"); 
    return(CS_ERROR);
  }
  if (cdeg_niv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_deg_eed_alarm_win Param5"); 
    return(CS_ERROR);
  }
  if (cdeg_ntv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_set_deg_eed_alarm_win Param6"); 
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);

  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_deg_dtv_div.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, DEG_DTV_DIV));
      tmp_deg_dtv_div.bf.sdeg_div = sdeg_div;
      tmp_deg_dtv_div.bf.sdeg_dtv = sdeg_dtv;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, DEG_DTV_DIV), tmp_deg_dtv_div.wrd);

      tmp_deg_ntv_niv.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, DEG_NTV_NIV));
      tmp_deg_ntv_niv.bf.cdeg_niv = cdeg_niv;
      tmp_deg_ntv_niv.bf.cdeg_ntv = cdeg_ntv;
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, DEG_NTV_NIV), tmp_deg_ntv_niv.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  GFEC INJECT ERROR IN 10G                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_10g_inject_err(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  ten_err_freq_t single_err,
                                  cs_uint16 duration,
                                  cs_uint8 err_value,
                                  cs_uint8 row_offset,
                                  cs_uint16 err_mask,
                                  cs_uint8 no_cycles_2_err,
                                  cs_uint8 start_position)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Single or Continuous                          */
/*              o Duration                                      */
/*              o Error Value                                   */
/*              o Row Offset                                    */
/*              o Error Mask                                    */
/*              o Number of Cycles to Error                     */
/*              o Start Position                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure 10G GFEC Error Insertion.                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [single_err] parameter is specified as:                  */
/*   0 = Inject continuously until cleared                      */
/*   1 = Inject single err                                      */
/*                                                              */
/* The [duration] parameter is specified as:                    */
/*   Number of milliseconds to inject errors before clearing.   */
/*   0 - 0xFFFF                                                 */
/* NOTE:  This function might block for the duration if         */
/* continuous errors need to be generated and duration is       */
/* non-zero.                                                    */
/*                                                              */
/* The [err_value] parameter is specified as:                   */
/*   Error Value, XORed with the individual symbols of the RX   */
/*   codewords.                                                 */
/*   0 - 0xFF = For continuous errors                           */
/*   0        = For single error                                */
/*                                                              */
/* The [row_offset] parameter is specified as:                  */
/*   Row Offset, sets which row of the OTU frame has the errors */
/*   inserted.                                                  */
/*   0 - 3                                                      */
/*                                                              */
/* The [err_mask] parameter is specified as:                    */
/*   Error Mask, enables particular RS codewords to be errored, */
/*   first RS codeword is considered to be the one who has the  */
/*   first symbol the 0xF6 byte.                                */
/*   0 - 0xFFFF                                                 */
/*                                                              */
/* The [no_cycles_2_err] parameter is specified as:             */
/*   Number of Cycles to Error.                                 */
/*   0 - 0xFF                                                   */
/*                                                              */
/* The [start_position] parameter is specified as:              */
/*   Start Position, how many cycles to error from the starting */
/*   position.                                                  */
/*   0 - 0xFF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii, jj;
  TEN_GFEC10G_FTX_ERRINS1_t tmp_errins1;
  TEN_GFEC10G_FTX_ERRINS2_t tmp_errins2;
  TEN_GFEC10G_FTX_ERRINS3_t tmp_errins3;
  T41_t *pDev = NULL;
  /* double BER = 0; */

  /* Parameter Checking */
  if ((slice >= TEN_GFEC10G_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_inject_err Param2"); 
    return(CS_ERROR);
  }
  if(single_err > TEN_SINGLE_ERR) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_inject_err Param3"); 
    return CS_ERROR;
  }
  if(row_offset > 3) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_10g_inject_err Param6"); 
    return CS_ERROR;
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_10G);

  for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
    if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
      tmp_errins1.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, ERRINS1));
      tmp_errins2.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, ERRINS2));
      tmp_errins3.wrd = TEN_REG_READ(TEN_GFEC10G_REG_ADDR(pDev, ii, ERRINS3));

      if(single_err) {
        tmp_errins1.bf.insErrorOnce = 1;
        tmp_errins1.bf.insError = 0;
      }
      else {
        tmp_errins1.bf.insErrorOnce = 0;
        tmp_errins1.bf.insError = 1;
      }

      tmp_errins1.bf.rowOffset = row_offset;
      tmp_errins1.bf.errValue = err_value;

      tmp_errins2.bf.errMask = err_mask;
      
      tmp_errins3.bf.startPosition = start_position;
      tmp_errins3.bf.noCycles2Error = no_cycles_2_err;

      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, ERRINS2), tmp_errins2.wrd);
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, ERRINS3), tmp_errins3.wrd);
      TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, ERRINS1), tmp_errins1.wrd);

      /* Compute the BER */
      for(jj=0; jj<16; jj++) {
        /* BER = BER + (double)((tmp_errins2.bf.errMask & (1<<jj)) >> jj) *  */
        /*                      tmp_errins1.bf.errValue / 130560 ;           */
      }
      /* CS_PRINT("BER = %f\n", BER); */
    }
  }

  if(!single_err) {
    /* Bugzilla #28471, 6 ms minimum delay */
    TEN_MDELAY(duration);

    for (ii=0; ii<TEN_GFEC10G_COUNT; ii++) {
      if ((slice == ii) || (slice == TEN_SLICE_ALL)) {
        tmp_errins1.bf.insError = 0;
        TEN_REG_WRITE(TEN_GFEC10G_REG_ADDR(pDev, ii, ERRINS1), tmp_errins1.wrd);
      }
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_10G);

  return (CS_OK);
}

/* Bugzilla 24692 Start */
/* Bugzilla 24692 End */

/****************************************************************/
/* $rtn_hdr_start  GFEC 40G SOFT (LOGIC) RESET                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_reset(cs_uint16 module_id,
                             cs_dir_t dir, 
                             cs_reset_action_t act)
/* INPUTS     : o Module Id                                     */
/*              o Direction                                     */
/*              o Reset Control                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Disable/enable 40G GFEC sub-block logic reset for the        */
/* specified datapath direction.                                */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FTX40_TXCFG_t tmp_txcfg;
  TEN_GFEC40G_FRX40_RSCFG_t tmp_rscfg;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_reset Param3"); 
    return CS_ERROR;
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_reset Param4"); 
    return CS_ERROR;
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);

  if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_rscfg.wrd = 0;
    tmp_rscfg.bf.RXRST = 1;
    ten_reset_action(TEN_GFEC40G_REG_ADDR(pDev, module_id, RSCFG), tmp_rscfg.wrd, act); 
  }
            
  if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_txcfg.wrd = 0;
    tmp_txcfg.bf.TXRST = 1;
    ten_reset_action(TEN_GFEC40G_REG_ADDR(pDev, module_id, TXCFG), tmp_txcfg.wrd, act); 
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 40G ERROR CORRECTION ENABLE             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_ec_enable(cs_uint16 module_id,
                                 cs_ctl_t enable)
/* INPUTS     : o Module Id                                     */
/*              o Enable                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable or disable 40G GFEC error correction                  */
/*                                                              */
/* The [enable] parameter enables error correction              */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FRX40_RSCFG_t tmp_rscfg;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if (enable > 1) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_enable Param3");
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);
  
  tmp_rscfg.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RSCFG));
  tmp_rscfg.bf.CORE = enable;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, RSCFG), tmp_rscfg.wrd);
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 40G GI_SEL                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_set_gi_sel(cs_uint16 module_id,
                                  ten_fec_time_unit_sel_t gi_sel)
/* INPUTS     : o Module Id                                     */
/*              o Global Stats Timing Gen                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the limit for setting Excessive Error Flag               */
/*                                                              */
/* The [gi_sel] parameter is specified as:                      */
/*   0   = TEN_INT_TIME_SOURCE_1                                */
/*   1   = TEN_INT_TIME_SOURCE_2                                */
/*   2   = TEN_INT_TIME_SOURCE_3                                */
/*   3   = TEN_INT_TIME_SOURCE_4                                */
/*   4   = TEN_INT_TIME_SOURCE_5                                */
/*   5   = TEN_INT_TIME_SOURCE_6                                */
/*   6   = TEN_SW_TIME_SOURCE                                   */
/*   7   = TEN_EXT_TIME_SOURCE                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FRX40_RSCFG_t tmp_rscfg;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if (gi_sel > TEN_EXT_TIME_SOURCE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_excess_error_flag Param5"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);

  tmp_rscfg.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RSCFG));
  tmp_rscfg.bf.GISEL = gi_sel;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, RSCFG), tmp_rscfg.wrd);
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 40G ENABLE G709 SCRAMBLER FOR STATS     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_stats_enable_scrambler(cs_uint16 module_id,
                                              cs_ctl_t scrmblr_enbl)
/* INPUTS     : o Module Id                                     */
/*              o Scrambler Enable                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Ther data is descrambled to detect the errors. In order to   */
/* collect stats this data needs to be rescrambled before       */
/* comparing with the incoming data                             */
/*                                                              */
/* The [scrmblr_enbl] parameter enables the G.709 scrambler for */
/* the received/corrected data before the 0/1 statistics are    */
/* collected                                                    */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FRX40_RSCFG_t tmp_rscfg;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(scrmblr_enbl > CS_ENABLE) { 
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_stats_enable_scrambler Param3"); 
    return CS_ERROR;
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);

  tmp_rscfg.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, RSCFG));
  tmp_rscfg.bf.STATSCREn = scrmblr_enbl;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, RSCFG), tmp_rscfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 40G SET EXCESS ERROR DETECT THRESHOLDS  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_set_eed_threshold(cs_uint16 module_id,
                                         cs_uint32 ceed_thres, 
                                         cs_uint32 seed_thres)
/* INPUTS     : o Module Id                                     */
/*              o Clear EED Seed Threshold                      */
/*              o Set EED Seed Threshold                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure excessive error detect seed thresholds to set and  */
/* clear BER threshold alarms                                   */
/*                                                              */
/* The [ceed_thres] parameter is specified as:                  */
/*   0 - 0xFFFFF                                                */
/*                                                              */
/* The [seed_thres] parameter is specified as:                  */
/*   0 - 0xFFFFF                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FRX40_SEED_THR_LOW_t tmp_seed_thr_low;
  TEN_GFEC40G_FRX40_SEED_THR_UP_t tmp_seed_thr_up;
  TEN_GFEC40G_FRX40_CEED_THR_LOW_t tmp_ceed_thr_low;
  TEN_GFEC40G_FRX40_CEED_THR_UP_t tmp_ceed_thr_up;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if (ceed_thres > 0xFFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_eed_threshold Param3"); 
    return(CS_ERROR);
  }
  if (seed_thres > 0xFFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_eed_threshold Param4"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);
  
  /* SEED threshold lo*/
  tmp_seed_thr_low.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, SEED_THR_LOW));
  tmp_seed_thr_low.bf.seed_thr_low = seed_thres & 0xFFFF;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, SEED_THR_LOW), tmp_seed_thr_low.wrd);

  /* SEED threshold hi*/
  tmp_seed_thr_up.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, SEED_THR_UP));
  tmp_seed_thr_up.bf.seed_thr_up = (seed_thres & 0xF0000) >> 16;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, SEED_THR_UP), tmp_seed_thr_up.wrd);

  /* CEED threshold lo */
  tmp_ceed_thr_low.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, CEED_THR_LOW));
  tmp_ceed_thr_low.bf.ceed_thr_low = ceed_thres & 0xFFFF;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, CEED_THR_LOW), tmp_ceed_thr_low.wrd);

  /* CEED threshold hi*/
  tmp_ceed_thr_up.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, CEED_THR_UP));
  tmp_ceed_thr_up.bf.ceed_thr_up = (ceed_thres & 0xF0000) >> 16;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, CEED_THR_UP), tmp_ceed_thr_up.wrd);
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 40G SET SIGNAL DEGRADE THRESHOLDS       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_set_deg_threshold(cs_uint16 module_id,
                                         cs_uint32 cdeg_thres, 
                                         cs_uint32 sdeg_thres)
/* INPUTS     : o Module Id                                     */
/*              o Clear DEG Threshold                           */
/*              o Set DEG Threshold                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure signal degrade thresholds to set and clear BER DEG */
/* thresholds                                                   */
/*                                                              */
/* The [cdeg_thr_lo] parameter is specified as:                 */
/*   0 - 0xFFFFF                                                */
/*                                                              */
/* The [sdeg_thr_hi] parameter is specified as:                 */
/*   0 - 0xFFFFF                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FRX40_SDEG_THR_LOW_t tmp_sdeg_thr_low;
  TEN_GFEC40G_FRX40_SDEG_THR_UP_t tmp_sdeg_thr_up;
  TEN_GFEC40G_FRX40_CDEG_THR_LOW_t tmp_cdeg_thr_low;
  TEN_GFEC40G_FRX40_CDEG_THR_UP_t tmp_cdeg_thr_up;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if (cdeg_thres > 0xFFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_deg_threshold Param3"); 
    return(CS_ERROR);
  }
  if (sdeg_thres > 0xFFFFF) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_deg_threshold Param4"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);
  
  /* SDEG threshold lo*/
  tmp_sdeg_thr_low.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, SDEG_THR_LOW));
  tmp_sdeg_thr_low.bf.sdeg_thr_low = sdeg_thres & 0xFFFF;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, SDEG_THR_LOW), tmp_sdeg_thr_low.wrd);

  /* SDEG threshold hi*/
  tmp_sdeg_thr_up.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, SDEG_THR_UP));
  tmp_sdeg_thr_up.bf.sdeg_thr_up = (sdeg_thres & 0xF0000) >> 16;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, SDEG_THR_UP), tmp_sdeg_thr_up.wrd);

  /* CDEG threshold lo */
  tmp_cdeg_thr_low.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, CDEG_THR_LOW));
  tmp_cdeg_thr_low.bf.cdeg_thr_low = cdeg_thres & 0xFFFF;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, CDEG_THR_LOW), tmp_cdeg_thr_low.wrd);

  /* CDEG threshold hi*/
  tmp_cdeg_thr_up.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, CDEG_THR_UP));
  tmp_cdeg_thr_up.bf.cdeg_thr_up = (cdeg_thres & 0xF0000) >> 16;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, CDEG_THR_UP), tmp_cdeg_thr_up.wrd);
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 40G SELECT ERROR TYPE                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_select_err_type(cs_uint16 module_id,
                                       ten_fec_err_sel_t err_sel, 
                                       ten_gfec_err_type_t err_type)
/* INPUTS     : o Module Id                                     */
/*              o Error Select                                  */
/*              o Error Type                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Select the error type for EED and DEG                        */
/*                                                              */
/* The [err_sel] parameter is specfied as:                      */
/*   0 = TEN_SEED_ERSEL  select set excessive error defect      */
/*   1 = TEN_CEED_ERSEL  select clear excessive error defect    */
/*   2 = TEN_SDEG_ERSEL  select set signal degrade error        */
/*   3 = TEN_CDEG_ERSEL  select clear signal degrade error      */
/*                                                              */
/* The [err_type] parameter applies the thresholds to the error */
/* types as specified by:                                       */
/*   0 =    TEN_N0B_N1B_NUCODEWD_NCBYTE                         */
/*   1 =    TEN_N0B_N1B_NUCODEWD_YCBYTE                         */
/*   2 =    TEN_N0B_N1B_YUCODEWD_NCBYTE                         */
/*   3 =    TEN_N0B_N1B_YUCODEWD_YCBYTE                         */
/*   4 =    TEN_N0B_Y1B_NUCODEWD_NCBYTE                         */
/*   5 =    TEN_N0B_Y1B_NUCODEWD_YCBYTE                         */
/*   6 =    TEN_N0B_Y1B_YUCODEWD_NCBYTE                         */
/*   7 =    TEN_N0B_Y1B_YUCODEWD_YCBYTE                         */
/*   8 =    TEN_Y0B_N1B_NUCODEWD_NCBYTE                         */
/*   9 =    TEN_Y0B_N1B_NUCODEWD_YCBYTE                         */
/*  40 =    TEN_Y0B_N1B_YUCODEWD_NCBYTE                         */
/*  11 =    TEN_Y0B_N1B_YUCODEWD_YCBYTE                         */
/*  12 =    TEN_Y0B_Y1B_NUCODEWD_NCBYTE                         */
/*  13 =    TEN_Y0B_Y1B_NUCODEWD_YCBYTE                         */
/*  14 =    TEN_Y0B_Y1B_YUCODEWD_NCBYTE                         */
/*  15 =    TEN_Y0B_Y1B_YUCODEWD_YCBYTE                         */
/*  The first character specifies YES or NO                     */
/*  0B      - RX bit 0 and corrected bit 1                      */
/*  1B      - RX bit 1 and corrected bit 0                      */
/*  UCODEWD - Uncorrectable codewords                           */
/*  CBYTE   - Corrected bytes                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FRX40_ERSEL_t tmp_ersel;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if (err_sel > TEN_CDEG_ERSEL) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_select_err_type Param3"); 
    return(CS_ERROR);
  }
  if (err_type > TEN_Y0B_Y1B_YUCODEWD_YCBYTE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_select_err_type Param4"); 
    return(CS_ERROR);
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);
  
  tmp_ersel.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERSEL));

  switch(err_sel) {
    case TEN_SEED_ERSEL:
      tmp_ersel.bf.seed_ersel = err_type;
      break;

    case TEN_CEED_ERSEL:
      tmp_ersel.bf.ceed_ersel = err_type;
      break;

    case TEN_SDEG_ERSEL:
      tmp_ersel.bf.sdeg_ersel = err_type;
      break;

    case TEN_CDEG_ERSEL:
      tmp_ersel.bf.cdeg_ersel = err_type;
      break;
  }

  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERSEL), tmp_ersel.wrd);
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 40G SELECT TIMER UNIT                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_select_timer_unit(cs_uint16 module_id,
                                         cs_boolean err_sel,
                                         ten_fec_time_unit_sel_t tu_sel)
/* INPUTS     : o Module Id                                     */
/*              o Error Select                                  */
/*              o Time Unit Selection                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure one of the eight independent global timers used    */
/* to determine the window size used by BER monitor             */
/*                                                              */
/* The [err_sel] parameter is specfied as:                      */
/*   0 = EED - Excessive error defect                           */
/*   1 = DEG - Signal degrade                                   */
/*                                                              */
/* The [tu_sel] parameter is specified as:                      */
/*   0   = TEN_INT_TIME_SOURCE_1                                */
/*   1   = TEN_INT_TIME_SOURCE_2                                */
/*   2   = TEN_INT_TIME_SOURCE_3                                */
/*   3   = TEN_INT_TIME_SOURCE_4                                */
/*   4   = TEN_INT_TIME_SOURCE_5                                */
/*   5   = TEN_INT_TIME_SOURCE_6                                */
/*   6   = TEN_SW_TIME_SOURCE                                   */
/*   7   = TEN_EXT_TIME_SOURCE                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FRX40_TUSEL_t tmp_tusel;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if (err_sel > 1) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_select_timer_unit Param3"); 
    return(CS_ERROR);
  }
  if (tu_sel > TEN_EXT_TIME_SOURCE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_select_timer_unit Param4"); 
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);

  tmp_tusel.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, TUSEL));
      
  switch(err_sel) {
    case 0:
      tmp_tusel.bf.eed_tusel = tu_sel;
      break;

    case 1:
      tmp_tusel.bf.deg_tusel = tu_sel;
      break;
  }
      
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, TUSEL), tmp_tusel.wrd);  

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 40G SET TIMING WINDOW SIZE              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_set_timing_win_size(cs_uint16 module_id,
                                           ten_fec_err_sel_t err_sel,
                                           cs_uint8 window_size)
/* INPUTS     : o Module Id                                     */
/*              o Error Select                                  */
/*              o Window Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the size of timing window to clear the alarms      */
/*                                                              */
/* The [err_sel] parameter is specfied as:                      */
/*   0 = TEN_SEED_ERSEL  select "set excessive error defect"    */
/*   1 = TEN_CEED_ERSEL  select "clear excessive error defect"  */
/*   2 = TEN_SDEG_ERSEL  select "set signal degrade error"      */
/*   3 = TEN_CDEG_ERSEL  select "clear signal degrade error"    */
/*                                                              */
/* The [window_size] parameter is specified as:                 */
/*   0 - 0x2F                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FRX40_EED_WIN_t tmp_eed_win;
  TEN_GFEC40G_FRX40_DEG_WIN_t tmp_deg_win;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if (err_sel > TEN_CDEG_ERSEL) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_timing_win_size Param3"); 
    return(CS_ERROR);
  }
  if (window_size > 0x2F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_timing_win_size Param4"); 
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);

  tmp_eed_win.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, EED_WIN));

  tmp_deg_win.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, DEG_WIN));

  switch(err_sel) {
    case TEN_SEED_ERSEL:
      tmp_eed_win.bf.seed_win = window_size;
      break;

    case TEN_CEED_ERSEL:
      tmp_eed_win.bf.ceed_win = window_size;
      break;

    case TEN_SDEG_ERSEL:
      tmp_deg_win.bf.sdeg_win = window_size;
      break;

    case TEN_CDEG_ERSEL:
      tmp_deg_win.bf.cdeg_win = window_size;
      break;
  }

  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, EED_WIN), tmp_eed_win.wrd);

  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, DEG_WIN), tmp_deg_win.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 40G CONFIG FEC EED ALARM WINDOW PARAMS  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_config_fec_eed_alarm_win(cs_uint16 module_id,
                                                cs_uint8 seed_div,
                                                cs_uint8 seed_dtv,
                                                cs_uint8 ceed_niv,
                                                cs_uint8 ceed_ntv)
/* INPUTS     : o Module Id                                     */
/*              o Set EED Defect Intermittant Value             */
/*              o Set EED Defect Threshold Value                */
/*              o Clear EED No Defect Intermittant Value        */
/*              o Clear EED No Defect Threshold Value           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure 40G GFEC dFECEED alarm windows settings            */
/* When more than SEED_DTV excessively-errored time windows are */
/* detected and no intervening error-free sequence occur for    */
/* longer than SEED_DIV intervals of SEED_WIN[5:0] x Selected   */
/* Time Unit, the Excessive Error Defect alarm (dFECEED) is set */
/* The Excessive Error Defect alarm (dFECEED) is cleared when   */
/* more than CEED_NTV non-excessively errored time windows are  */
/* detected without been intermitted by CEED_NIV errored time   */
/* windows                                                      */
/*                                                              */
/* The [seed_div] parameter is the set excessive error defect   */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [seed_dtv] parameter is the set excessive error defect   */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [ceed_niv] parameter is the clear excessive error defect */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [ceed_ntv] parameter is the clear excessive error defect */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FRX40_EED_DTV_DIV_t tmp_eed_dtv_div;
  TEN_GFEC40G_FRX40_EED_NTV_NIV_t tmp_eed_ntv_niv;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if (seed_div > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_fec_eed_alarm_win Param3");
    return(CS_ERROR);
  }
  if (seed_dtv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_fec_eed_alarm_win Param4");
    return(CS_ERROR);
  }
  if (ceed_niv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_fec_eed_alarm_win Param5");
    return(CS_ERROR);
  }
  if (ceed_ntv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_fec_eed_alarm_win Param6");
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);

  tmp_eed_dtv_div.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, EED_DTV_DIV));
  tmp_eed_dtv_div.bf.seed_div = seed_div;
  tmp_eed_dtv_div.bf.seed_dtv = seed_dtv;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, EED_DTV_DIV), tmp_eed_dtv_div.wrd);

  tmp_eed_ntv_niv.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, EED_NTV_NIV));
  tmp_eed_ntv_niv.bf.ceed_niv = ceed_niv;
  tmp_eed_ntv_niv.bf.ceed_ntv = ceed_ntv;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, EED_NTV_NIV), tmp_eed_ntv_niv.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC 40G CONFIG FEC DEG ALARM WINDOW PARAMS  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_config_fec_deg_alarm_win(cs_uint16 module_id,
                                                cs_uint8 sdeg_div,
                                                cs_uint8 sdeg_dtv,
                                                cs_uint8 cdeg_niv,
                                                cs_uint8 cdeg_ntv)
/* INPUTS     : o Module Id                                     */
/*              o Set DEG Defect Intermittant Value             */
/*              o Set DEG Defect Threshold Value                */
/*              o Clear DEG Defect Intermittant Value           */
/*              o Clear DEG Defect Threshold Value              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure 40G GFEC dFECDEG alarm windows settings            */
/* When more than SDEG_DTV degraded time windows are detected   */
/* and no intervening error-free sequence occur for longer than */
/* SDEG_DIV intervals of SDEG_WIN[5:0] x Selected Time Unit, the*/
/* Degraded Defect alarm (dFECDEG) is set.                      */
/* The Degraded Defect alarm (dFECDEG) is cleared when more than*/
/* CDEG_NTV non-degraded errored time windows are detected      */
/* without been intermitted by CDEG_NIV errored time windows.   */
/*                                                              */
/* The [sdeg_div] parameter is the set signal degrade defect    */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [sdeg_dtv] parameter is the set signal degrade defect    */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [cdeg_niv] parameter is the clear signal degrade defect  */
/* intermittant value and is specified as:                      */
/*   0 - 0x3F                                                   */
/*                                                              */
/* The [cdeg_ntv] parameter is the clear signal degrade defect  */
/* threshold value and is specified as:                         */
/*   0 - 0x3F                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_GFEC40G_FRX40_DEG_DTV_DIV_t tmp_deg_dtv_div;
  TEN_GFEC40G_FRX40_DEG_NTV_NIV_t tmp_deg_ntv_niv;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if (sdeg_div > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_deg_eed_alarm_win Param3"); 
    return(CS_ERROR);
  }
  if (sdeg_dtv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_deg_eed_alarm_win Param4"); 
    return(CS_ERROR);
  }
  if (cdeg_niv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_deg_eed_alarm_win Param5"); 
    return(CS_ERROR);
  }
  if (cdeg_ntv > 0x3F) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_set_deg_eed_alarm_win Param6"); 
    return(CS_ERROR);
  }

  /* Register Setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);

  tmp_deg_dtv_div.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, DEG_DTV_DIV));
  tmp_deg_dtv_div.bf.sdeg_div = sdeg_div;
  tmp_deg_dtv_div.bf.sdeg_dtv = sdeg_dtv;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, DEG_DTV_DIV), tmp_deg_dtv_div.wrd);

  tmp_deg_ntv_niv.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, DEG_NTV_NIV));
  tmp_deg_ntv_niv.bf.cdeg_niv = cdeg_niv;
  tmp_deg_ntv_niv.bf.cdeg_ntv = cdeg_ntv;
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, DEG_NTV_NIV), tmp_deg_ntv_niv.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  GFEC INJECT ERROR IN 40G                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_inject_err(cs_uint16 module_id,
                                  ten_err_freq_t single_err,
                                  cs_uint16 duration,
                                  cs_uint8 err_value,
                                  cs_uint8 row_offset,
                                  cs_uint16 err_mask,
                                  cs_uint8 no_cycles_2_err,
                                  cs_uint8 start_position)
/* INPUTS     : o Module Id                                     */
/*              o Single or Continuous                          */
/*              o Duration                                      */
/*              o Error Value                                   */
/*              o Row Offset                                    */
/*              o Error Mask                                    */
/*              o Number of Cycles to Error                     */
/*              o Start Position                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure 40G GFEC Error Insertion.                          */
/*                                                              */
/* The [single_err] parameter is specified as:                  */
/*   0 = Inject continuously until cleared                      */
/*   1 = Inject single err                                      */
/*                                                              */
/* The [duration] parameter is specified as:                    */
/*   Number of milliseconds to inject errors before clearing.   */
/*   0          = For single error                              */
/*   0 - 0xFFFF = For continuous errors                         */
/* NOTE:  This function might block for the duration if         */
/* continuous errors need to be generated and duration is       */
/* non-zero.                                                    */
/*                                                              */
/* The [err_value] parameter is specified as:                   */
/*   Error Value, XORed with the individual symbols of the RX   */
/*   codewords.                                                 */
/*   0 - 0xFF = For continuous errors                           */
/*   0        = For single error                                */
/*                                                              */
/* The [row_offset] parameter is specified as:                  */
/*   Row Offset, sets which row of the OTU frame has the errors */
/*   inserted.                                                  */
/*   0 - 3                                                      */
/*                                                              */
/* The [err_mask] parameter is specified as:                    */
/*   Error Mask, enables particular RS codewords to be errored, */
/*   first RS codeword is considered to be the one who has the  */
/*   first symbol the 0xF6 byte.                                */
/*   0 - 0xFFFF                                                 */
/*                                                              */
/* The [no_cycles_2_err] parameter is specified as:             */
/*   Number of Cycles to Error                                  */
/*   0 - 0xFF                                                   */
/*                                                              */
/* The [start_position] parameter is specified as:              */
/*   Start Position, how many cycles to error from the starting */
/*   position.                                                  */
/*   0 - 0xFF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 jj;
  TEN_GFEC40G_FTX40_ERRINS1_t tmp_errins1;
  TEN_GFEC40G_FTX40_ERRINS2_t tmp_errins2;
  TEN_GFEC40G_FTX40_ERRINS3_t tmp_errins3;
  T41_t *pDev = NULL;
 /* double BER = 0; */

  /* Parameter Checking */
  if(single_err > TEN_SINGLE_ERR) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_inject_err Param3"); 
    return CS_ERROR;
  }
  if(row_offset > 3) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_inject_err Param6"); 
    return CS_ERROR;
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);

  tmp_errins2.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS2));
  tmp_errins3.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS3));
  tmp_errins1.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS1));

  if(single_err) {
    tmp_errins1.bf.insErrorOnce = 1;
    tmp_errins1.bf.insError = 0;
  }
  else {
    tmp_errins1.bf.insErrorOnce = 0;
    tmp_errins1.bf.insError = 1;
  }

  tmp_errins1.bf.rowOffset = row_offset;
  tmp_errins1.bf.errValue = err_value;

  tmp_errins2.bf.errMask = err_mask;
  
  tmp_errins3.bf.startPosition = start_position;
  tmp_errins3.bf.noCycles2Error = no_cycles_2_err;

  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS2), tmp_errins2.wrd);
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS3), tmp_errins3.wrd);
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS1), tmp_errins1.wrd);

  /* Compute the BER */
  for(jj=0; jj<16; jj++) {
    /* BER = BER + (double)((tmp_errins2.bf.errMask & (1<<jj)) >> jj) *  */ 
    /*                       tmp_errins1.bf.errValue / 130560 ;          */
  }
  /* CS_PRINT("BER = %f\n", BER); */

  if(!single_err) {
    /* Bugzilla #28471, 6 ms minimum delay */
    TEN_MDELAY(duration);

    tmp_errins1.bf.insError = 0;
    TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS1), tmp_errins1.wrd);
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  GFEC INJECT CONTINUAL ERRORS IN 40G           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_gfec_40g_inject_cont_err(cs_uint16 module_id,
                                       ten_err_freq_t insError,
                                       cs_uint8 err_value,
                                       cs_uint8 row_offset,
                                       cs_uint16 err_mask,
                                       cs_uint8 no_cycles_2_err,
                                       cs_uint8 start_position)
/* INPUTS     : o Module Id                                     */
/*              o Insert Error                                  */
/*              o Error Value                                   */
/*              o Row Offset                                    */
/*              o Error Mask                                    */
/*              o Number of Cycles to Error                     */
/*              o Start Position                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure 40G GFEC Continual Error Insertion.                */
/*                                                              */
/* The [insError] parameter is specified as:                    */
/*   0 = Error injection off                                    */
/*   1 = Continually Inject errors                              */
/*                                                              */
/* The [err_value] parameter is specified as:                   */
/*   Error Value, XORed with the individual symbols of the RX   */
/*   codewords.                                                 */
/*   0 - 0xFF = For continuous errors                           */
/*   0        = For single error                                */
/*                                                              */
/* The [row_offset] parameter is specified as:                  */
/*   Row Offset, sets which row of the OTU frame has the errors */
/*   inserted.                                                  */
/*   0 - 3                                                      */
/*                                                              */
/* The [err_mask] parameter is specified as:                    */
/*   Error Mask, enables particular RS codewords to be errored, */
/*   first RS codeword is considered to be the one who has the  */
/*   first symbol the 0xF6 byte.                                */
/*   0 - 0xFFFF                                                 */
/*                                                              */
/* The [no_cycles_2_err] parameter is specified as:             */
/*   Number of Cycles to Error                                  */
/*   0 - 0xFF                                                   */
/*                                                              */
/* The [start_position] parameter is specified as:              */
/*   Start Position, how many cycles to error from the starting */
/*   position.                                                  */
/*   0 - 0xFF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 jj;
  TEN_GFEC40G_FTX40_ERRINS1_t tmp_errins1;
  TEN_GFEC40G_FTX40_ERRINS2_t tmp_errins2;
  TEN_GFEC40G_FTX40_ERRINS3_t tmp_errins3;
  T41_t *pDev = NULL;
 /* double BER = 0; */

  /* Parameter Checking */
  if(insError > TEN_SINGLE_ERR) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_inject_err Param3"); 
    return CS_ERROR;
  }
  if(row_offset > 3) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_gfec_40g_inject_err Param6"); 
    return CS_ERROR;
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_GFEC_40G);

  tmp_errins1.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS1));
  tmp_errins2.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS2));
  tmp_errins3.wrd = TEN_REG_READ(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS3));

  tmp_errins1.bf.insError = insError;

  tmp_errins1.bf.rowOffset = row_offset;
  tmp_errins1.bf.errValue = err_value;

  tmp_errins2.bf.errMask = err_mask;
  
  tmp_errins3.bf.startPosition = start_position;
  tmp_errins3.bf.noCycles2Error = no_cycles_2_err;

  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS2), tmp_errins2.wrd);
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS3), tmp_errins3.wrd);
  TEN_REG_WRITE(TEN_GFEC40G_REG_ADDR(pDev, module_id, ERRINS1), tmp_errins1.wrd);

  /* Compute the BER */
  for(jj=0; jj<16; jj++) {
    /* BER = BER + (double)((tmp_errins2.bf.errMask & (1<<jj)) >> jj) *  */ 
    /*                       tmp_errins1.bf.errValue / 130560 ;          */
  }
  /* CS_PRINT("BER = %f\n", BER); */

  TEN_MOD_UNLOCK(module_id, TEN_ID_GFEC_40G);
  return (CS_OK);
}

/* Bugzilla 24692 Start */
/* Bugzilla 24692 End */

  
/********************************************************************/
/* Function: ten_get_GFEC10g_inst_reg_addr                          */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a GFEC10g register.                          */
/*                                                                  */
/* Used by macro TEN_GFEC10G_REG_ADDR. Given the base address       */
/* of a non-common GFEC10g register as defined in t41_registers.h,  */
/* and its instance number (0-TEN_GFEC10G_COUNT), calcuates         */
/* the offset and adds it to the base register's address.           */
/********************************************************************/
volatile cs_reg *ten_get_GFEC10g_inst_reg_addr( cs_reg   *pReg,
                                                cs_uint16 instance )
{
  if (instance >= TEN_GFEC10G_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "GFEC10g instance %d out of range. S/b < TEN_GFEC10G_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_GFEC10G_STRIDE);
}




