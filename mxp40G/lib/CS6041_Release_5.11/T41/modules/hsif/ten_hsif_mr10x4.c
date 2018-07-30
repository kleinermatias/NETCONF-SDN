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
 * ten_hsif_mr10x4.c
 *
 * HSIF MR10X4 related code is implemented here.
 *
 * $Id: ten_hsif_mr10x4.c,v 1.20 2013/02/22 20:49:56 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"


/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON SRX0 RX CONFIG       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_config(cs_uint16 module_id, 
                                                     cs_uint8 instance, 
                                                     cs_uint16 srx_buswidth)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX BUSWIDTH                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets DEMUX bus width.                                            */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_buswidth]                                                 */
/*     00 = enable 8bit dmux mode                                   */
/*     01 = enable 10bit dmux mode                                  */
/*     10 = reserved                                                */
/*     11 = reserved.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_t tmp_slc0_mr10x4_sds_common_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_config.bf.SRX_BUSWIDTH = srx_buswidth;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON SRX0 RX CONFIG       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_config(cs_uint16 module_id, 
                                                     cs_uint8 instance, 
                                                     cs_uint16 srx_buswidth)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX BUSWIDTH                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets DEMUX bus width.                                            */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_buswidth]                                                 */
/*     00 = enable 8bit dmux mode                                   */
/*     01 = enable 10bit dmux mode                                  */
/*     10 = reserved                                                */
/*     11 = reserved.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_t tmp_slc2_mr10x4_sds_common_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_config.bf.SRX_BUSWIDTH = srx_buswidth;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON SRX0 RX CLKDIV CTRL  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(cs_uint16 module_id, 
                                                          cs_uint8 instance, 
                                                          cs_uint16 srx_ddiv_sel, 
                                                          cs_uint16 srx_rdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX DDIV SEL                                      */
/*              o SRX RDIV SEL                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the RX clock dividers.                                  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_ddiv_sel]  Select clock rate for transmit data path       */
/*                                                                  */
/*   [srx_rdiv_sel]  Select the serial clock divider to transmit    */
/*     PFD for comparison to the clock reference 1.75GHz to 3.5GHz  */
/*     VCO.                                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKDIV_CTRL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.bf.SRX_DDIV_SEL = srx_ddiv_sel;
      tmp_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.bf.SRX_RDIV_SEL = srx_rdiv_sel;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKDIV_CTRL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON SRX0 RX CLKDIV CTRL  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(cs_uint16 module_id, 
                                                          cs_uint8 instance, 
                                                          cs_uint16 srx_ddiv_sel, 
                                                          cs_uint16 srx_rdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX DDIV SEL                                      */
/*              o SRX RDIV SEL                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the RX clock dividers.                                  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_ddiv_sel]  Select clock rate for transmit data path       */
/*                                                                  */
/*   [srx_rdiv_sel]  Select the serial clock divider to transmit    */
/*     PFD for comparison to the clock reference 1.75GHz to 3.5GHz  */
/*     VCO.                                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKDIV_CTRL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.bf.SRX_DDIV_SEL = srx_ddiv_sel;
      tmp_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.bf.SRX_RDIV_SEL = srx_rdiv_sel;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKDIV_CTRL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON SRX0 RX LOOP FILTER  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_loop_filter(cs_uint16 module_id, 
                                                          cs_uint8 instance, 
                                                          cs_uint16 srx_filtr)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX FILTR                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive serdes loop filter.              */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_filtr]  Loop filter resistor adjust.                      */
/*                Binary weighted 2.0k resistor.                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_LOOP_FILTER_t tmp_slc0_mr10x4_sds_common_srx0_rx_loop_filter;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_LOOP_FILTER_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_LOOP_FILTER_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_loop_filter.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_LOOP_FILTER) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_LOOP_FILTER_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_loop_filter.bf.SRX_FILTR = srx_filtr;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_LOOP_FILTER) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_LOOP_FILTER_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_loop_filter.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON SRX0 RX LOOP FILTER  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_loop_filter(cs_uint16 module_id, 
                                                          cs_uint8 instance, 
                                                          cs_uint16 srx_filtr)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX FILTR                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive serdes loop filter.              */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_filtr]  Loop filter resistor adjust.                      */
/*                Binary weighted 2.0k resistor                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_LOOP_FILTER_t tmp_slc2_mr10x4_sds_common_srx0_rx_loop_filter;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_LOOP_FILTER_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_LOOP_FILTER_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_loop_filter.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_LOOP_FILTER) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_LOOP_FILTER_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_loop_filter.bf.SRX_FILTR = srx_filtr;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_LOOP_FILTER) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_LOOP_FILTER_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_loop_filter.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON SRX0 RX CPA          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_cpa(cs_uint16 module_id, 
                                                  cs_uint8 instance, 
                                                  cs_uint16 srx_cpcur1, 
                                                  cs_uint16 srx_cpcur0)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX CPCUR1                                        */
/*              o SRX CPCUR0                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive serdes charge pump.              */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_cpcur1]  Charge pump current setting.  This setting is    */
/*                 used when the SRX_FREQ msb is 1.                 */
/*                                                                  */
/*   [srx_cpcur0]  Charge pump current setting. This setting is     */
/*                 used when the SRX_FREQ msb is 0.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CPA_t tmp_slc0_mr10x4_sds_common_srx0_rx_cpa;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CPA_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CPA_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_cpa.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CPA) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CPA_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_cpa.bf.SRX_CPCUR1 = srx_cpcur1;
      tmp_slc0_mr10x4_sds_common_srx0_rx_cpa.bf.SRX_CPCUR0 = srx_cpcur0;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CPA) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CPA_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_cpa.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON SRX0 RX CPA          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_cpa(cs_uint16 module_id, 
                                                  cs_uint8 instance, 
                                                  cs_uint16 srx_cpcur1, 
                                                  cs_uint16 srx_cpcur0)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX CPCUR1                                        */
/*              o SRX CPCUR0                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive serdes charge pump.              */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_cpcur1]  Charge pump current setting.  This setting is    */
/*                 used when the SRX_FREQ msb is 1.                 */
/*                                                                  */
/*   [srx_cpcur0]  Charge pump current setting. This setting is     */
/*                 used when the SRX_FREQ msb is 0.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CPA_t tmp_slc2_mr10x4_sds_common_srx0_rx_cpa;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CPA_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CPA_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_cpa.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CPA) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CPA_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_cpa.bf.SRX_CPCUR1 = srx_cpcur1;
      tmp_slc2_mr10x4_sds_common_srx0_rx_cpa.bf.SRX_CPCUR0 = srx_cpcur0;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CPA) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CPA_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_cpa.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON SRX0 RX CPB          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_cpb(cs_uint16 module_id, 
                                                      cs_uint8 instance, 
                                                      cs_uint16 srx_phsel)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX PHSEL                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive serdes charge pump.              */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_phsel]  Input to charge pump to allow phase variation of  */
/*      sample point in 64 equal steps.                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CPB_t tmp_slc0_mr10x4_sds_common_srx0_rx_cpb;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CPB_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CPB_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_cpb.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CPB) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CPB_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_cpb.bf.SRX_PHSEL = srx_phsel;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CPB) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CPB_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_cpb.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON SRX0 RX CPB          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_cpb(cs_uint16 module_id, 
                                                      cs_uint8 instance, 
                                                      cs_uint16 srx_phsel)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX PHSEL                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive serdes charge pump.              */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_phsel]  Input to charge pump to allow phase variation of  */
/*      sample point in 64 equal steps.                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CPB_t tmp_slc2_mr10x4_sds_common_srx0_rx_cpb;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CPB_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CPB_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_cpb.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CPB) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CPB_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_cpb.bf.SRX_PHSEL = srx_phsel;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CPB) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CPB_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_cpb.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON SRX0 RX MISC         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_misc(cs_uint16 module_id, 
                                                   cs_uint8 instance, 
                                                   cs_uint16 srx_eqadj)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX EQADJ                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls miscellaneous control bits for RX.                      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_eqadj]  Equalizer zero adjustment.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_MISC_t tmp_slc0_mr10x4_sds_common_srx0_rx_misc;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_MISC_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_MISC_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_misc.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_MISC) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_MISC_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_misc.bf.SRX_EQADJ = srx_eqadj;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_MISC) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_MISC_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_misc.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON SRX0 RX MISC         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_misc(cs_uint16 module_id, 
                                                   cs_uint8 instance, 
                                                   cs_uint16 srx_eqadj)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX EQADJ                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls miscellaneous control bits for RX.                      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_eqadj]  Equalizer zero adjustment.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_MISC_t tmp_slc2_mr10x4_sds_common_srx0_rx_misc;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_MISC_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_MISC_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_misc.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_MISC) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_MISC_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_misc.bf.SRX_EQADJ = srx_eqadj;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_MISC) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_MISC_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_misc.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON SRX0 RX SPARE        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_spare(cs_uint16 module_id, cs_uint8 instance, 
                                                    cs_uint16 srx_spare)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX SPARE                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets spare control bits for the SERDES Analog front end.         */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_spare]                                                    */
/*     Receiver spare bits:                                         */
/*     Spare 5: Test clock driver enable                            */
/*     Spare 6: enable for RXLP_CLK SFI4.2 line timing.             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_SPARE_t tmp_slc0_mr10x4_sds_common_srx0_rx_spare;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_SPARE_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_SPARE_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_SPARE) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_SPARE_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_spare.bf.SRX_SPARE = srx_spare;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_SPARE) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_SPARE_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_spare.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON SRX0 RX SPARE        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_spare(cs_uint16 module_id, cs_uint8 instance, 
                                                    cs_uint16 srx_spare)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX SPARE                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets spare control bits for the SERDES Analog front end.         */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_spare]                                                    */
/*     Receiver spare bits:                                         */
/*     Spare 5: Test clock driver enable                            */
/*     Spare 6: enable for RXLP_CLK SFI4.2 line timing.             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_SPARE_t tmp_slc2_mr10x4_sds_common_srx0_rx_spare;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_SPARE_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_SPARE_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_SPARE) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_SPARE_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_spare.bf.SRX_SPARE = srx_spare;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_SPARE) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_SPARE_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_spare.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON RXVCO0 THRES0        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_rxvco0_thres0(cs_uint16 module_id, cs_uint8 instance, 
                                                    cs_uint16 freq_thres_sign0, 
                                                    cs_uint16 freq_thres0)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o FREQ THRES SIGN0                                  */
/*              o FREQ THRES0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets values used by the VCO Coarse Tuning Algorithm to decide    */
/* if the VCO 0 is in the correct frequency range.                  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [freq_thres_sign0]  Positive (0) or Negative (1) sign to be    */
/*     associated with FREQ_THRES0.                                 */
/*                                                                  */
/*   [freq_thres0]                                                  */
/*     Provides some flexibility for the Coarse Tuning Algorithm    */
/*     when deciding if the VCO's operating frequency range is      */
/*     such that the PLL can capture the receive data frequency.    */
/*     Larger values of FREQ_THRES0 provide more slack in making    */
/*     this decision.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_THRES0_t tmp_slc0_mr10x4_sds_common_rxvco0_thres0;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_THRES0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_THRES0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxvco0_thres0.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_THRES0) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_THRES0_STRIDE);
      tmp_slc0_mr10x4_sds_common_rxvco0_thres0.bf.FREQ_THRES_SIGN0 = freq_thres_sign0;
      tmp_slc0_mr10x4_sds_common_rxvco0_thres0.bf.FREQ_THRES0 = freq_thres0;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_THRES0) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_THRES0_STRIDE, tmp_slc0_mr10x4_sds_common_rxvco0_thres0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON RXVCO0 THRES1        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_rxvco0_thres1(cs_uint16 module_id, cs_uint8 instance, 
                                                    cs_uint16 freq_thres_sign1, 
                                                    cs_uint16 freq_thres1)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o FREQ THRES SIGN1                                  */
/*              o FREQ THRES1                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets values used by the VCO Coarse Tuning Algorithm to decide    */
/* if the VCO 0 is in the correct frequency range.                  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [freq_thres_sign1]  Positive (0) or Negative (1) sign to be    */
/*     associated with FREQ_THRES1.                                 */
/*                                                                  */
/*   [freq_thres1]                                                  */
/*     Provides some flexibility for the Coarse Tuning Algorithm    */
/*     when deciding if the VCO's operating frequency range is      */
/*     such that the PLL can capture the receive data frequency.    */
/*     Larger values of FREQ_THRES1 provide more slack in making    */
/*     this decision.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_THRES1_t tmp_slc0_mr10x4_sds_common_rxvco0_thres1;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_THRES1_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_THRES1_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxvco0_thres1.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_THRES1) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_THRES1_STRIDE);
      tmp_slc0_mr10x4_sds_common_rxvco0_thres1.bf.FREQ_THRES_SIGN1 = freq_thres_sign1;
      tmp_slc0_mr10x4_sds_common_rxvco0_thres1.bf.FREQ_THRES1 = freq_thres1;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_THRES1) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_THRES1_STRIDE, tmp_slc0_mr10x4_sds_common_rxvco0_thres1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON RXVCO0 THRES0        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_rxvco0_thres0(cs_uint16 module_id, cs_uint8 instance, 
                                                    cs_uint16 freq_thres_sign0, 
                                                    cs_uint16 freq_thres0)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o FREQ THRES SIGN0                                  */
/*              o FREQ THRES0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets values used by the VCO Coarse Tuning Algorithm to decide    */
/* if the VCO 0 is in the correct frequency range.                  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [freq_thres_sign0]  Positive (0) or Negative (1) sign to be    */
/*     associated with FREQ_THRES0.                                 */
/*                                                                  */
/*   [freq_thres0]                                                  */
/*     Provides some flexibility for the Coarse Tuning Algorithm    */
/*     when deciding if the VCO's operating frequency range is      */
/*     such that the PLL can capture the receive data frequency.    */
/*     Larger values of FREQ_THRES0 provide more slack in making    */
/*     this decision.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_THRES0_t tmp_slc2_mr10x4_sds_common_rxvco0_thres0;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_THRES0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_THRES0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxvco0_thres0.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_THRES0) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_THRES0_STRIDE);
      tmp_slc2_mr10x4_sds_common_rxvco0_thres0.bf.FREQ_THRES_SIGN0 = freq_thres_sign0;
      tmp_slc2_mr10x4_sds_common_rxvco0_thres0.bf.FREQ_THRES0 = freq_thres0;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_THRES0) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_THRES0_STRIDE, tmp_slc2_mr10x4_sds_common_rxvco0_thres0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON RXVCO0 THRES1        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_rxvco0_thres1(cs_uint16 module_id, cs_uint8 instance, 
                                                    cs_uint16 freq_thres_sign1, 
                                                    cs_uint16 freq_thres1)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o FREQ THRES SIGN1                                  */
/*              o FREQ THRES1                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets values used by the VCO Coarse Tuning Algorithm to decide    */
/* if the VCO 0 is in the correct frequency range.                  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [freq_thres_sign1]  Positive (0) or Negative (1) sign to be    */
/*     associated with FREQ_THRES1.                                 */
/*                                                                  */
/*   [freq_thres1]                                                  */
/*     Provides some flexibility for the Coarse Tuning Algorithm    */
/*     when deciding if the VCO's operating frequency range is      */
/*     such that the PLL can capture the receive data frequency.    */
/*     Larger values of FREQ_THRES1 provide more slack in making    */
/*     this decision.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_THRES1_t tmp_slc2_mr10x4_sds_common_rxvco0_thres1;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_THRES1_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_THRES1_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxvco0_thres1.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_THRES1) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_THRES1_STRIDE);
      tmp_slc2_mr10x4_sds_common_rxvco0_thres1.bf.FREQ_THRES_SIGN1 = freq_thres_sign1;
      tmp_slc2_mr10x4_sds_common_rxvco0_thres1.bf.FREQ_THRES1 = freq_thres1;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_THRES1) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_THRES1_STRIDE, tmp_slc2_mr10x4_sds_common_rxvco0_thres1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON RXVCO0 CONTROL       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_rxvco0_control(cs_uint16 module_id, cs_uint8 instance, 
                                                     cs_uint16 val)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the VCO Coarse Tuning Algorithm      */
/* and its outputs.                                                 */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [val]  Value of RXVCO0.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_CONTROL_COUNT) && 
      (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_CONTROL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_CONTROL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_CONTROL_STRIDE, val);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON RXVCO0 CONTROL       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_rxvco0_control(cs_uint16 module_id, cs_uint8 instance, 
                                                     cs_uint16 val)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the VCO Coarse Tuning Algorithm      */
/* and its outputs.                                                 */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [val]  Value of RXVCO0.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_CONTROL_COUNT) && 
      (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_CONTROL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_CONTROL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_CONTROL_STRIDE, val);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS RXVCO0 SET SHORT OVERRIDE   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_rxvco0_set_short_ovride(cs_uint16 module_id, cs_uint8 instance, 
                                                     cs_uint16 short_ovride)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SHORT OVRIDE                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Override control of the Coarse Tuner's "Filter Short" output,    */
/* SHORT_FILTPN.  Either use SHORT_FILTPN directly from the Coarse  */
/* Tuner or else use the value contained in this register.          */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [short_ovride]                                                 */
/*     0 = USE_CT_RESULT Use the SHORT_FILTPN output of the coarse  */
/*         tuner.                                                   */
/*     2 = FORCE_OFF Force SHORT_FILTPN output off                  */
/*     3 = FORCE_ON Force SHORT_FILTPN output on.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_CONTROL_t tmp_slc0_mr10x4_sds_common_rxvco0_control;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_CONTROL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_CONTROL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxvco0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_CONTROL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_CONTROL_STRIDE);
      tmp_slc0_mr10x4_sds_common_rxvco0_control.bf.SHORT_OVRIDE = short_ovride;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_CONTROL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_CONTROL_STRIDE, tmp_slc0_mr10x4_sds_common_rxvco0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS RXVCO0 SET SHORT OVERRIDE   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_rxvco0_set_short_ovride(cs_uint16 module_id, cs_uint8 instance, 
                                                     cs_uint16 short_ovride)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SHORT OVRIDE                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Override control of the Coarse Tuner's "Filter Short" output,    */
/* SHORT_FILTPN.  Either use SHORT_FILTPN directly from the Coarse  */
/* Tuner or else use the value contained in this register.          */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [short_ovride]                                                 */
/*     0 = USE_CT_RESULT Use the SHORT_FILTPN output of the coarse  */
/*         tuner.                                                   */
/*     2 = FORCE_OFF Force SHORT_FILTPN output off                  */
/*     3 = FORCE_ON Force SHORT_FILTPN output on.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_CONTROL_t tmp_slc2_mr10x4_sds_common_rxvco0_control;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_CONTROL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_CONTROL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxvco0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_CONTROL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_CONTROL_STRIDE);
      tmp_slc2_mr10x4_sds_common_rxvco0_control.bf.SHORT_OVRIDE = short_ovride;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_CONTROL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_CONTROL_STRIDE, tmp_slc2_mr10x4_sds_common_rxvco0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON TXLOCKD0 FILTER      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_txlockd0_filter(cs_uint16 module_id, 
                                                      cs_uint16 stable_period)
/* INPUTS     : o Module Id                                         */
/*              o STABLE PERIOD                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the Lock Detect interrupt filter.                       */
/*                                                                  */
/*   [stable_period]  Specifies the period of time where lock       */
/*      must be asserted before reporting lock via interrupt.       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TXLOCKD0_FILTER_t tmp_slc0_mr10x4_sds_common_txlockd0_filter;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_txlockd0_filter.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXLOCKD0_FILTER));
  tmp_slc0_mr10x4_sds_common_txlockd0_filter.bf.STABLE_PERIOD = stable_period;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXLOCKD0_FILTER), tmp_slc0_mr10x4_sds_common_txlockd0_filter.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON TXLOCKD0 FILTER      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_txlockd0_filter(cs_uint16 module_id, 
                                                      cs_uint16 stable_period)
/* INPUTS     : o Module Id                                         */
/*              o STABLE PERIOD                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the Lock Detect interrupt filter.                       */
/*                                                                  */
/*   [stable_period]  Specifies the period of time where lock       */
/*      must be asserted before reporting lock via interrupt.       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TXLOCKD0_FILTER_t tmp_slc2_mr10x4_sds_common_txlockd0_filter;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_txlockd0_filter.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXLOCKD0_FILTER));
  tmp_slc2_mr10x4_sds_common_txlockd0_filter.bf.STABLE_PERIOD = stable_period;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXLOCKD0_FILTER), tmp_slc2_mr10x4_sds_common_txlockd0_filter.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS TXVCO0 SET SHORT OVERRIDE   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_txvco0_set_short_ovride(cs_uint16 module_id, 
                                                     cs_uint16 short_ovride)
/* INPUTS     : o Module Id                                         */
/*              o SHORT OVRIDE                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Override control of the Coarse Tuner's "Filter Short" output,    */
/* SHORT_FILTPN.  Either use SHORT_FILTPN directly from the Coarse  */
/* Tuner or else use the value contained in this register.          */
/*                                                                  */
/*   [short_ovride]                                                 */
/*     0 = USE_CT_RESULT Use the SHORT_FILTPN output of the coarse  */
/*         tuner                                                    */
/*     2 = FORCE_OFF Force SHORT_FILTPN output off                  */
/*     3 = FORCE_ON Force SHORT_FILTPN output on.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TXVCO0_CONTROL_t tmp_slc0_mr10x4_sds_common_txvco0_control;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_txvco0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_CONTROL));
  tmp_slc0_mr10x4_sds_common_txvco0_control.bf.SHORT_OVRIDE = short_ovride;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_CONTROL), tmp_slc0_mr10x4_sds_common_txvco0_control.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS TXVCO0 SET SHORT OVERRIDE   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_txvco0_set_short_ovride(cs_uint16 module_id, 
                                                     cs_uint16 short_ovride)
/* INPUTS     : o Module Id                                         */
/*              o SHORT OVRIDE                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Override control of the Coarse Tuner's "Filter Short" output,    */
/* SHORT_FILTPN.  Either use SHORT_FILTPN directly from the Coarse  */
/* Tuner or else use the value contained in this register.          */
/*                                                                  */
/*   [short_ovride]                                                 */
/*     0 = USE_CT_RESULT Use the SHORT_FILTPN output of the coarse  */
/*         tuner                                                    */
/*     2 = FORCE_OFF Force SHORT_FILTPN output off                  */
/*     3 = FORCE_ON Force SHORT_FILTPN output on.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TXVCO0_CONTROL_t tmp_slc2_mr10x4_sds_common_txvco0_control;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_txvco0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_CONTROL));
  tmp_slc2_mr10x4_sds_common_txvco0_control.bf.SHORT_OVRIDE = short_ovride;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_CONTROL), tmp_slc2_mr10x4_sds_common_txvco0_control.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON RXLOCKD0 FILTER      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_rxlockd0_filter(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 stable_period)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o STABLE PERIOD                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the Lock Detect interrupt filter.                       */
/*                                                                  */
/*   [instance]  Specified as 0..3 or TEN_INSTANCE_ALL (0xFF).      */
/*                                                                  */
/*   [stable_period]  Specifies the period of time where lock must  */
/*      be asserted before reporting lock via interrupt.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_FILTER_t tmp_slc0_mr10x4_sds_common_rxlockd0_filter;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_FILTER_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_FILTER_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxlockd0_filter.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_FILTER) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_FILTER_STRIDE);
      tmp_slc0_mr10x4_sds_common_rxlockd0_filter.bf.STABLE_PERIOD = stable_period;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_FILTER) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_FILTER_STRIDE, tmp_slc0_mr10x4_sds_common_rxlockd0_filter.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON RXLOCKD0 FILTER      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_rxlockd0_filter(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 stable_period)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o STABLE PERIOD                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the Lock Detect interrupt filter.                       */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [stable_period]  Specifies the period of time where lock must  */
/*      be asserted before reporting lock via interrupt.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_FILTER_t tmp_slc2_mr10x4_sds_common_rxlockd0_filter;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_FILTER_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_FILTER_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxlockd0_filter.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_FILTER) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_FILTER_STRIDE);
      tmp_slc2_mr10x4_sds_common_rxlockd0_filter.bf.STABLE_PERIOD = stable_period;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_FILTER) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_FILTER_STRIDE, tmp_slc2_mr10x4_sds_common_rxlockd0_filter.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 GET SDS RX LOCK STATUS          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_hsif_slc0_mr10x4_get_sds_rx_lock_status(cs_uint16 module_id, cs_uint8 instance)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE (1) or FALSE (0)                               */
/* DESCRIPTION:                                                     */
/* Gets lock status for HSIF.                                       */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_slc0_mr10x4_sds_common_rxlockd0_intstatus;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_INTSTATUS) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_STRIDE);
      ret_val = ret_val && tmp_slc0_mr10x4_sds_common_rxlockd0_intstatus.bf.LOCKs;
    }
  }

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 GET SDS RX LOCK STATUS          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_hsif_slc2_mr10x4_get_sds_rx_lock_status(cs_uint16 module_id, cs_uint8 instance)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE (1) or FALSE (0)                               */
/* DESCRIPTION:                                                     */
/* Gets lock status for HSIF.                                       */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_slc2_mr10x4_sds_common_rxlockd0_intstatus;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_INTSTATUS) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_STRIDE);
      ret_val = ret_val && tmp_slc2_mr10x4_sds_common_rxlockd0_intstatus.bf.LOCKs;
    }
  }

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 GET SDS RX FILT LOCK STATUS     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_hsif_slc0_mr10x4_get_sds_rx_filt_lock_status(cs_uint16 module_id, cs_uint8 instance)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE (1) or FALSE (0)                               */
/* DESCRIPTION:                                                     */
/* Gets filt lock status for HSIF (FILT_LOCKs).                     */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_slc0_mr10x4_sds_common_rxlockd0_intstatus;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_INTSTATUS) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_STRIDE);
      ret_val = ret_val && tmp_slc0_mr10x4_sds_common_rxlockd0_intstatus.bf.FILT_LOCKs;
    }
  }

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 GET SDS RX FILT LOCK STATUS     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_hsif_slc2_mr10x4_get_sds_rx_filt_lock_status(cs_uint16 module_id, cs_uint8 instance)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE (1) or FALSE (0)                               */
/* DESCRIPTION:                                                     */
/* Gets filt lock status for HSIF (FILT_LOCKs).                     */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_slc2_mr10x4_sds_common_rxlockd0_intstatus;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_INTSTATUS) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_INTSTATUS_STRIDE);
      ret_val = ret_val && tmp_slc2_mr10x4_sds_common_rxlockd0_intstatus.bf.FILT_LOCKs;
    }
  }

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STX0 TX OUTPUT CTRLA */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrla(cs_uint16 module_id, 
                                                           cs_uint8 instance, 
                                                           cs_uint16 stx_level)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o STX LEVEL                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets SERDES Analog Front End Adjustments.                        */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [stx_level]                                                    */
/*     Output driver cursor output level adjust,                    */
/*     binary weighted, 0.5mA LSB.                                  */
/*     111111 = 31mA                                                */
/*     000000 = off.                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_t tmp_slc0_mr10x4_sds_common_stx0_tx_output_ctrla;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_stx0_tx_output_ctrla.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STX0_TX_OUTPUT_CTRLA) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_STRIDE);
      tmp_slc0_mr10x4_sds_common_stx0_tx_output_ctrla.bf.STX_LEVEL = stx_level;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STX0_TX_OUTPUT_CTRLA) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_STRIDE, tmp_slc0_mr10x4_sds_common_stx0_tx_output_ctrla.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STX0 TX OUTPUT CTRLA*/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stx0_tx_output_ctrla(cs_uint16 module_id, cs_uint8 instance, 
                                                           cs_uint16 stx_level)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o STX LEVEL                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets SERDES Analog Front End Adjustments.                        */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [stx_level]                                                    */
/*     Output driver cursor output level adjust,                    */
/*     binary weighted, 0.5mA LSB.                                  */
/*     111111 = 31mA                                                */
/*     000000 = off.                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_t tmp_slc2_mr10x4_sds_common_stx0_tx_output_ctrla;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_stx0_tx_output_ctrla.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STX0_TX_OUTPUT_CTRLA) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_STRIDE);
      tmp_slc2_mr10x4_sds_common_stx0_tx_output_ctrla.bf.STX_LEVEL = stx_level;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STX0_TX_OUTPUT_CTRLA) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_STRIDE, tmp_slc2_mr10x4_sds_common_stx0_tx_output_ctrla.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STX0 TX OUTPUT CTRLB*/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrlb(cs_uint16 module_id, 
                                                               cs_uint8 instance, 
                                                               cs_uint16 stx_pre_peak, 
                                                               cs_uint16 stx_post_peak)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o STX PRE PEAK                                      */
/*              o STX POST PEAK                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets SERDES Analog Front End Adjustments.                        */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [stx_pre_peak]                                                 */
/*      Output driver pre-cursor level adjust                       */
/*      binary weighted, 0.25mA LSB.                                */
/*      11111 = 7.75mA                                              */
/*      00000 = off                                                 */
/*                                                                  */
/*   [stx_post_peak]                                                */
/*      Output driver post-cursor level adjust                      */
/*      binary weighted, 0.25mA LSB.                                */
/*      111111 = 15.75mA                                            */
/*      000000 = off.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_t tmp_slc0_mr10x4_sds_common_stx0_tx_output_ctrlb;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_stx0_tx_output_ctrlb.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STX0_TX_OUTPUT_CTRLB) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_STRIDE);
      tmp_slc0_mr10x4_sds_common_stx0_tx_output_ctrlb.bf.STX_PRE_PEAK = stx_pre_peak;
      tmp_slc0_mr10x4_sds_common_stx0_tx_output_ctrlb.bf.STX_POST_PEAK = stx_post_peak;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STX0_TX_OUTPUT_CTRLB) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_STRIDE, tmp_slc0_mr10x4_sds_common_stx0_tx_output_ctrlb.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STX0 TX OUTPUT CTRLB */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stx0_tx_output_ctrlb(cs_uint16 module_id, 
                                                               cs_uint8 instance, 
                                                               cs_uint16 stx_pre_peak, 
                                                               cs_uint16 stx_post_peak)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o STX PRE PEAK                                      */
/*              o STX POST PEAK                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets SERDES Analog Front End Adjustments.                        */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [stx_pre_peak]                                                 */
/*      Output driver pre-cursor level adjust                       */
/*      binary weighted, 0.25mA LSB.                                */
/*      11111 = 7.75mA                                              */
/*      00000 = off                                                 */
/*                                                                  */
/*   [stx_post_peak]                                                */
/*      Output driver post-cursor level adjust                      */
/*      binary weighted, 0.25mA LSB.                                */
/*      111111 = 15.75mA                                            */
/*      000000 = off.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_t tmp_slc2_mr10x4_sds_common_stx0_tx_output_ctrlb;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_stx0_tx_output_ctrlb.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STX0_TX_OUTPUT_CTRLB) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_STRIDE);
      tmp_slc2_mr10x4_sds_common_stx0_tx_output_ctrlb.bf.STX_PRE_PEAK = stx_pre_peak;
      tmp_slc2_mr10x4_sds_common_stx0_tx_output_ctrlb.bf.STX_POST_PEAK = stx_post_peak;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STX0_TX_OUTPUT_CTRLB) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_STRIDE, tmp_slc2_mr10x4_sds_common_stx0_tx_output_ctrlb.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX CONFIG      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lptime_sel, 
                                                      cs_uint16 stxp_pilot_sel, 
                                                      cs_uint16 stxp_buswidth)
/* INPUTS     : o Module Id                                         */
/*              o STXP LPTIME SEL                                   */
/*              o STXP PILOT SEL                                    */
/*              o STXP BUSWIDTH                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [stxp_lptime_sel]                                              */
/*     Enable Loop time mode in which one RX channel                */
/*     recovered clock is supplied as the reference                 */
/*     for transmit. None of the standards supported                */
/*     require looptime mode. Test mode only.                       */
/*     00 = TX ref from local STXP_CLKREFP/N pads, Local timing     */
/*          (SFI4.2/XAUI)                                           */
/*     01 = TX ref from RX divided recovered clock,                 */
/*          Line timing mode (SFI4.2)                               */
/*     10 = TX ref from common SFI5CKREFP/N pads,                   */
/*          (Line and Local SFI5.1/SFI4.2-40G mode)                 */
/*                                                                  */
/*   [stxp_pilot_sel]                                               */
/*     00 = default reference                                       */
/*     01 = AUX refclock 1                                          */
/*     10 = AUX refclock 2                                          */
/*     11  =AUX refclock 3                                          */
/*                                                                  */
/*   [stxp_buswidth]                                                */
/*     000 = RX ref from STXP_CLKR                                  */
/*     001 = RX ref from STXP_AUXPILOTIN pin                        */
/*     010 = RX ref from STXP_AUXPILOTSFI5 pin                      */
/*     011 = RX ref from STXP_AUXPILOTP/N pads                      */
/*     100 = RX ref from STXP_AUXREFIN pin                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc0_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL = stxp_lptime_sel;
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.bf.STXP_PILOT_SEL = stxp_pilot_sel;
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.bf.STXP_BUSWIDTH = stxp_buswidth;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX CONFIG LPTIME SEL */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lptime_sel)
/* INPUTS     : o Module Id                                         */
/*              o STXP LPTIME SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/* [stxp_lptime_sel]  Enable Loop time mode in which one RX channel */
/*   recovered clock is supplied as the reference for transmit.     */
/*   None of the standards supported require looptime mode.         */
/*   Test mode only.                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc0_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL = stxp_lptime_sel;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX CONFIG PILOT SEL */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_pilot_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_pilot_sel)
/* INPUTS     : o Module Id                                         */
/*              o STXP PILOT SEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/* [stxp_pilot_sel]  Selects pilot tone clock to the receiver       */
/*   and the STXP_REF_LD signal.                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc0_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.bf.STXP_PILOT_SEL = stxp_pilot_sel;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX CONFIG BUSWIDTH */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_buswidth(cs_uint16 module_id, 
                                                      cs_uint16 stxp_buswidth)
/* INPUTS     : o Module Id                                         */
/*              o STXP BUSWIDTH                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/* [stxp_buswidth]  MUX bus width at output.                        */
/* 00 = enable 8bit mux mode                                        */
/* 01 = enable 10bit mux mode.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc0_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.bf.STXP_BUSWIDTH = stxp_buswidth;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX CONFIG LPBKEN */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lpbken(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o STXP LPBKEN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/* [stxp_lpbken]  Power drivers to enable serial loopback:          */
/*   0 = loopback disabled                                          */
/*   1 = loopback enabled.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc0_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPBKEN = stxp_lpbken;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX CONFIG LPTIME SEL */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lptime_sel)
/* INPUTS     : o Module Id                                         */
/*              o STXP LPTIME SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/* [stxp_lptime_sel]  Enable Loop time mode in which one RX channel */
/*   recovered clock is supplied as the reference for transmit.     */
/*   None of the standards supported require looptime mode.         */
/*   Test mode only.                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc2_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL = stxp_lptime_sel;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX CONFIG PILOT SEL */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_pilot_sel(cs_uint16 module_id, 
                                                      cs_uint16 stxp_pilot_sel)
/* INPUTS     : o Module Id                                         */
/*              o STXP PILOT SEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/* [stxp_pilot_sel]  Selects pilot tone clock to the receiver       */
/*   and the STXP_REF_LD signal.                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc2_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.bf.STXP_PILOT_SEL = stxp_pilot_sel;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX CONFIG BUSWIDTH */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_buswidth(cs_uint16 module_id, 
                                                      cs_uint16 stxp_buswidth)
/* INPUTS     : o Module Id                                         */
/*              o STXP BUSWIDTH                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/* [stxp_buswidth]  MUX bus width at output.                        */
/* 00 = enable 8bit mux mode                                        */
/* 01 = enable 10bit mux mode.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc2_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.bf.STXP_BUSWIDTH = stxp_buswidth;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX CONFIG LPBKEN */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lpbken(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o STXP LPBKEN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/* [stxp_lpbken]  Power drivers to enable serial loopback:          */
/*   0 = loopback disabled                                          */
/*   1 = loopback enabled.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc2_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPBKEN = stxp_lpbken;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX CONFIG      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config(cs_uint16 module_id, 
                                                      cs_uint16 stxp_lptime_sel, 
                                                      cs_uint16 stxp_pilot_sel, 
                                                      cs_uint16 stxp_buswidth)
/* INPUTS     : o Module Id                                         */
/*              o STXP LPTIME SEL                                   */
/*              o STXP PILOT SEL                                    */
/*              o STXP BUSWIDTH                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*   [stxp_lptime_sel]                                              */
/*     Enable Loop time mode in which one RX channel                */
/*     recovered clock is supplied as the reference                 */
/*     for transmit. None of the standards supported                */
/*     require looptime mode. Test mode only.                       */
/*     00 = TX ref from local STXP_CLKREFP/N pads, Local timing     */
/*          (SFI4.2/XAUI)                                           */
/*     01 = TX ref from RX divided recovered clock,                 */
/*          Line timing mode (SFI4.2)                               */
/*     10 = TX ref from common SFI5CKREFP/N pads,                   */
/*          (Line and Local SFI5.1/SFI4.2-40G mode)                 */
/*                                                                  */
/*   [stxp_pilot_sel]                                               */
/*     00 = default reference                                       */
/*     01 = AUX refclock 1                                          */
/*     10 = AUX refclock 2                                          */
/*     11  =AUX refclock 3                                          */
/*                                                                  */
/*   [stxp_buswidth]                                                */
/*     000 = RX ref from STXP_CLKR                                  */
/*     001 = RX ref from STXP_AUXPILOTIN pin                        */
/*     010 = RX ref from STXP_AUXPILOTSFI5 pin                      */
/*     011 = RX ref from STXP_AUXPILOTP/N pads                      */
/*     100 = RX ref from STXP_AUXREFIN pin                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc2_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL = stxp_lptime_sel;
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.bf.STXP_PILOT_SEL = stxp_pilot_sel;
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.bf.STXP_BUSWIDTH = stxp_buswidth;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX CLKDIV CTRL */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(cs_uint16 module_id, 
                                                           cs_uint16 stxp_ddiv_sel, 
                                                           cs_uint16 stxp_rdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o STXP DDIV SEL                                     */
/*              o STXP RDIV SEL                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls all of the TX clock dividers.                           */
/*                                                                  */
/*   [stxp_ddiv_sel]                                                */
/*     Select clock rate for transmit data path                     */
/*                                                                  */
/*   [stxp_rdiv_sel]                                                */
/*     Select the serial clock divider to transmit PFD for          */
/*     comparison to the clock reference.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_DDIV_SEL = stxp_ddiv_sel;
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL = stxp_rdiv_sel;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL), tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX CLKDIV CTRL*/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(cs_uint16 module_id, 
                                                           cs_uint16 stxp_ddiv_sel, 
                                                           cs_uint16 stxp_rdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o STXP DDIV SEL                                     */
/*              o STXP RDIV SEL                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls all of the TX clock dividers.                           */
/*                                                                  */
/*   [stxp_ddiv_sel]                                                */
/*     Select clock rate for transmit data path                     */
/*                                                                  */
/*   [stxp_rdiv_sel]                                                */
/*     Select the serial clock divider to transmit PFD for          */
/*     comparison to the clock reference.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_DDIV_SEL = stxp_ddiv_sel;
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL = stxp_rdiv_sel;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL), tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX CLKOUT CTRL*/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl(cs_uint16 module_id, 
                                                           cs_uint16 stxp_tclkien) 
/* INPUTS     : o Module Id                                         */
/*              o STXP TCLKIEN                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit clock outputs.                  */
/*                                                                  */
/*   [stxp_tclkien]  Select source for serial clock.                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKOUT_CTRL));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl.bf.STXP_TCLKIEN = stxp_tclkien;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKOUT_CTRL), tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX CLKOUT CTRL*/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl(cs_uint16 module_id, 
                                                           cs_uint16 stxp_tclkien)
/* INPUTS     : o Module Id                                         */
/*              o STXP TCLKIEN                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit clock outputs.                  */
/*                                                                  */
/*   [stxp_tclkien]  Select source for serial clock.                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKOUT_CTRL));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl.bf.STXP_TCLKIEN = stxp_tclkien;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKOUT_CTRL), tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX CLKOUT CTRL CLKOUTEN */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl_clkouten(cs_uint16 module_id, 
                                                           cs_uint16 stxp_clkouten) 
/* INPUTS     : o Module Id                                         */
/*              o STXP CLKOUTEN                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit clock outputs.                  */
/*                                                                  */
/* [stxp_clkouten]   STXP_CLKOUTEN                                  */
/*   Test clock output enable.                                      */
/*   0 = test clock disabled                                        */
/*   1 = test clock enabled.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKOUT_CTRL));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl.bf.STXP_CLKOUTEN = stxp_clkouten;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKOUT_CTRL), tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX CLKOUT CTRL CLKOUTEN */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl_clkouten(cs_uint16 module_id, 
                                                           cs_uint16 stxp_clkouten) 
/* INPUTS     : o Module Id                                         */
/*              o STXP CLKOUTEN                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit clock outputs.                  */
/*                                                                  */
/* [stxp_clkouten]   STXP_CLKOUTEN                                  */
/*   Test clock output enable.                                      */
/*   0 = test clock disabled                                        */
/*   1 = test clock enabled.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKOUT_CTRL));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl.bf.STXP_CLKOUTEN = stxp_clkouten;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKOUT_CTRL), tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX LOOP FILTER*/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_loop_filter(cs_uint16 module_id, 
                                                           cs_uint16 stxp_filtr)
/* INPUTS     : o Module Id                                         */
/*              o STXP FILTR                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit loop filter.                    */
/*                                                                  */
/*   [stxp_filtr]  Programmable PLL loop filter resistance.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_LOOP_FILTER_t tmp_slc0_mr10x4_sds_common_stxp0_tx_loop_filter;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_loop_filter.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_LOOP_FILTER));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_loop_filter.bf.STXP_FILTR = stxp_filtr;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_LOOP_FILTER), tmp_slc0_mr10x4_sds_common_stxp0_tx_loop_filter.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX LOOP FILTER*/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_loop_filter(cs_uint16 module_id, 
                                                           cs_uint16 stxp_filtr)
/* INPUTS     : o Module Id                                         */
/*              o STXP FILTR                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit loop filter.                    */
/*                                                                  */
/*   [stxp_filtr]  Programmable PLL loop filter resistance.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_LOOP_FILTER_t tmp_slc2_mr10x4_sds_common_stxp0_tx_loop_filter;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_loop_filter.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_LOOP_FILTER));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_loop_filter.bf.STXP_FILTR = stxp_filtr;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_LOOP_FILTER), tmp_slc2_mr10x4_sds_common_stxp0_tx_loop_filter.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX CP          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_cp(cs_uint16 module_id, 
                                                  cs_uint16 stxp_cpcur1, 
                                                  cs_uint16 stxp_cpcur0)
/* INPUTS     : o Module Id                                         */
/*              o STXP CPCUR1                                       */
/*              o STXP CPCUR0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit PLL charge pump.                */
/*                                                                  */
/*   [stxp_cpcur1]  Charge pump current setting. This setting is    */
/*     used when the STXP_FREQ msb is 1.                            */
/*                                                                  */
/*   [stxp_cpcur0]  Charge pump current setting. This setting is    */
/*     used when the STXP_FREQ msb is 0.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CP_t tmp_slc0_mr10x4_sds_common_stxp0_tx_cp;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_cp.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CP));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_cp.bf.STXP_CPCUR1 = stxp_cpcur1;
  tmp_slc0_mr10x4_sds_common_stxp0_tx_cp.bf.STXP_CPCUR0 = stxp_cpcur0; 
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CP), tmp_slc0_mr10x4_sds_common_stxp0_tx_cp.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX CP          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_cp(cs_uint16 module_id, 
                                                  cs_uint16 stxp_cpcur1, 
                                                  cs_uint16 stxp_cpcur0)
/* INPUTS     : o Module Id                                         */
/*              o STXP CPCUR1                                       */
/*              o STXP CPCUR0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit PLL charge pump.                */
/*                                                                  */
/*   [stxp_cpcur1]  Charge pump current setting. This setting is    */
/*     used when the STXP_FREQ msb is 1.                            */
/*                                                                  */
/*   [stxp_cpcur0]  Charge pump current setting. This setting is    */
/*     used when the STXP_FREQ msb is 0.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CP_t tmp_slc2_mr10x4_sds_common_stxp0_tx_cp;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_cp.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CP));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_cp.bf.STXP_CPCUR1 = stxp_cpcur1;
  tmp_slc2_mr10x4_sds_common_stxp0_tx_cp.bf.STXP_CPCUR0 = stxp_cpcur0;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CP), tmp_slc2_mr10x4_sds_common_stxp0_tx_cp.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON TXVCO0 THRES0        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_txvco0_thres0(cs_uint16 module_id, 
                                                    cs_uint16 freq_thres_sign0, 
                                                    cs_uint16 freq_thres0)
/* INPUTS     : o Module Id                                         */
/*              o FREQ THRES SIGN0                                  */
/*              o FREQ THRES0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets values used by the VCO Coarse Tuning Algorithm to decide    */
/* if the VCO 0 is in the correct frequency range.                  */
/*                                                                  */
/*   [freq_thres_sign0]                                             */
/*     Positive (0) or Negative (1) sign to be associated           */
/*     with FREQ_THRES0.                                            */
/*                                                                  */
/*   [freq_thres0]                                                  */
/*     Provides some flexibility for the Coarse Tuning Algorithm    */
/*     when deciding if the VCO's operating frequency range is      */
/*     such that the PLL can capture the receive data frequency.    */
/*     Larger values of FREQ_THRES0 provide more slack in making    */
/*     this decision.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TXVCO0_THRES0_t tmp_slc0_mr10x4_sds_common_txvco0_thres0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_txvco0_thres0.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_THRES0));
  tmp_slc0_mr10x4_sds_common_txvco0_thres0.bf.FREQ_THRES_SIGN0 = freq_thres_sign0;
  tmp_slc0_mr10x4_sds_common_txvco0_thres0.bf.FREQ_THRES0 = freq_thres0;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_THRES0), tmp_slc0_mr10x4_sds_common_txvco0_thres0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON TXVCO0 THRES1        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_txvco0_thres1(cs_uint16 module_id, 
                                                    cs_uint16 freq_thres_sign1, 
                                                    cs_uint16 freq_thres1)
/* INPUTS     : o Module Id                                         */
/*              o FREQ THRES SIGN1                                  */
/*              o FREQ THRES1                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets values used by the VCO Coarse Tuning Algorithm to decide    */
/* if the VCO 1 is in the correct frequency range.                  */
/*                                                                  */
/*   [freq_thres_sign1]                                             */
/*     Positive (0) or Negative (1) sign to be associated           */
/*     with FREQ_THRES1.                                            */
/*                                                                  */
/*   [freq_thres1]                                                  */
/*     Provides some flexibility for the Coarse Tuning Algorithm    */
/*     when deciding if the VCO's operating frequency range is      */
/*     such that the PLL can capture the receive data frequency.    */
/*     Larger values of FREQ_THRES1 provide more slack in making    */
/*     this decision.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TXVCO0_THRES1_t tmp_slc0_mr10x4_sds_common_txvco0_thres1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_txvco0_thres1.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_THRES1));
  tmp_slc0_mr10x4_sds_common_txvco0_thres1.bf.FREQ_THRES_SIGN1 = freq_thres_sign1;
  tmp_slc0_mr10x4_sds_common_txvco0_thres1.bf.FREQ_THRES1 = freq_thres1;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_THRES1), tmp_slc0_mr10x4_sds_common_txvco0_thres1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON TXVCO0 THRES0        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_txvco0_thres0(cs_uint16 module_id, 
                                                    cs_uint16 freq_thres_sign0, 
                                                    cs_uint16 freq_thres0)
/* INPUTS     : o Module Id                                         */
/*              o FREQ THRES SIGN0                                  */
/*              o FREQ THRES0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets values used by the VCO Coarse Tuning Algorithm to decide    */
/* if the VCO 0 is in the correct frequency range.                  */
/*                                                                  */
/*   [freq_thres_sign0]                                             */
/*     Positive (0) or Negative (1) sign to be associated           */
/*     with FREQ_THRES0.                                            */
/*                                                                  */
/*   [freq_thres0]                                                  */
/*     Provides some flexibility for the Coarse Tuning Algorithm    */
/*     when deciding if the VCO's operating frequency range is      */
/*     such that the PLL can capture the receive data frequency.    */
/*     Larger values of FREQ_THRES0 provide more slack in making    */
/*     this decision.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TXVCO0_THRES0_t tmp_slc2_mr10x4_sds_common_txvco0_thres0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_txvco0_thres0.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_THRES0));
  tmp_slc2_mr10x4_sds_common_txvco0_thres0.bf.FREQ_THRES_SIGN0 = freq_thres_sign0;
  tmp_slc2_mr10x4_sds_common_txvco0_thres0.bf.FREQ_THRES0 = freq_thres0;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_THRES0), tmp_slc2_mr10x4_sds_common_txvco0_thres0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON TXVCO0 THRES1        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_txvco0_thres1(cs_uint16 module_id, 
                                                    cs_uint16 freq_thres_sign1, 
                                                    cs_uint16 freq_thres1)
/* INPUTS     : o Module Id                                         */
/*              o FREQ THRES SIGN1                                  */
/*              o FREQ THRES1                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets values used by the VCO Coarse Tuning Algorithm to decide    */
/* if the VCO 1 is in the correct frequency range.                  */
/*                                                                  */
/*   [freq_thres_sign1]                                             */
/*     Positive (0) or Negative (1) sign to be associated           */
/*     with FREQ_THRES1.                                            */
/*                                                                  */
/*   [freq_thres1]                                                  */
/*     Provides some flexibility for the Coarse Tuning Algorithm    */
/*     when deciding if the VCO's operating frequency range is      */
/*     such that the PLL can capture the receive data frequency.    */
/*     Larger values of FREQ_THRES1 provide more slack in making    */
/*     this decision.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TXVCO0_THRES1_t tmp_slc2_mr10x4_sds_common_txvco0_thres1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_txvco0_thres1.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_THRES1));
  tmp_slc2_mr10x4_sds_common_txvco0_thres1.bf.FREQ_THRES_SIGN1 = freq_thres_sign1;
  tmp_slc2_mr10x4_sds_common_txvco0_thres1.bf.FREQ_THRES1 = freq_thres1;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_THRES1), tmp_slc2_mr10x4_sds_common_txvco0_thres1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 GET SDS TX LOCK STATUS          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_hsif_slc0_mr10x4_get_sds_tx_lock_status(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE (1) or FALSE (0)                               */
/* DESCRIPTION:                                                     */
/* Gets lock status for HSIF.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_slc0_mr10x4_sds_common_txlockd0_intstatus;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  tmp_slc0_mr10x4_sds_common_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXLOCKD0_INTSTATUS));
  return (tmp_slc0_mr10x4_sds_common_txlockd0_intstatus.bf.LOCKs == 1);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 GET SDS TX LOCK STATUS          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_hsif_slc2_mr10x4_get_sds_tx_lock_status(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE (1) or FALSE (0)                               */
/* DESCRIPTION:                                                     */
/* Gets lock status for HSIF.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_slc2_mr10x4_sds_common_txlockd0_intstatus;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  tmp_slc2_mr10x4_sds_common_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXLOCKD0_INTSTATUS));
  return (tmp_slc2_mr10x4_sds_common_txlockd0_intstatus.bf.LOCKs == 1);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 GET SDS TX FILT LOCK STATUS     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_hsif_slc0_mr10x4_get_sds_tx_filt_lock_status(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE (1) or FALSE (0)                               */
/* DESCRIPTION:                                                     */
/* Gets filt lock status for HSIF.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_slc0_mr10x4_sds_common_txlockd0_intstatus;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  tmp_slc0_mr10x4_sds_common_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXLOCKD0_INTSTATUS));
  return (tmp_slc0_mr10x4_sds_common_txlockd0_intstatus.bf.FILT_LOCKs == 1);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 GET SDS TX FILT LOCK STATUS     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_hsif_slc2_mr10x4_get_sds_tx_filt_lock_status(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE (1) or FALSE (0)                               */
/* DESCRIPTION:                                                     */
/* Gets filt lock status for HSIF.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_slc2_mr10x4_sds_common_txlockd0_intstatus;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  tmp_slc2_mr10x4_sds_common_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXLOCKD0_INTSTATUS));
  return (tmp_slc2_mr10x4_sds_common_txlockd0_intstatus.bf.FILT_LOCKs == 1);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON TX CONFIG            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_tx_config(cs_uint16 module_id, 
                                                    cs_uint8 instance, 
                                                    cs_uint16 data_source)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Data Source                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the input source for the TX datapath.                    */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..4 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [data_source]                                                  */
/*     0 = DIG_TX_DIN                                               */
/*     1 = PRBS                                                     */
/*     2 = RX Loopback Data                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_t tmp_slc0_mr10x4_sds_common_tx0_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TX0_Config) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_STRIDE);
      tmp_slc0_mr10x4_sds_common_tx0_config.bf.data_source = data_source;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TX0_Config) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_STRIDE, tmp_slc0_mr10x4_sds_common_tx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON RX CONFIG            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_rx_config(cs_uint16 module_id, cs_uint8 instance, 
                                                 cs_uint16 data_source)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Data Source                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the input source for the RX datapath.                    */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..4 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [data_source]                                                  */
/*     0 = SRX_DOUT (Serdes data)                                   */
/*     1 = TX Loopback Data.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_t tmp_slc0_mr10x4_sds_common_rx0_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RX0_Config) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_STRIDE);
      tmp_slc0_mr10x4_sds_common_rx0_config.bf.data_source = data_source;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RX0_Config) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_STRIDE, tmp_slc0_mr10x4_sds_common_rx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON TX CONFIG           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_tx_config(cs_uint16 module_id, cs_uint8 instance, 
                                                 cs_uint16 data_source)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Data Source                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the input source for the TX datapath.                    */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..4 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [data_source]                                                  */
/*     0 = DIG_TX_DIN                                               */
/*     1 = PRBS                                                     */
/*     2 = RX Loopback Data                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_t tmp_slc2_mr10x4_sds_common_tx0_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TX0_Config) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_STRIDE);
      tmp_slc2_mr10x4_sds_common_tx0_config.bf.data_source = data_source;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TX0_Config) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_STRIDE, tmp_slc2_mr10x4_sds_common_tx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON RX CONFIG            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_rx_config(cs_uint16 module_id, 
                                                    cs_uint8 instance, 
                                                    cs_uint16 data_source)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Data Source                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the input source for the RX datapath.                    */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..4 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [data_source]                                                  */
/*     0 = SRX_DOUT (Serdes data)                                   */
/*     1 = TX Loopback Data.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_t tmp_slc2_mr10x4_sds_common_rx0_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RX0_Config) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_STRIDE);
      tmp_slc2_mr10x4_sds_common_rx0_config.bf.data_source = data_source;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RX0_Config) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_STRIDE, tmp_slc2_mr10x4_sds_common_rx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON TX CONFIG BITINV     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_tx_config_bitinv(cs_uint16 module_id, 
                                                           cs_uint8 instance, 
                                                           cs_uint16 bitinv)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Bit Invert                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This bit inverts the polarity of all tx data bits when set.      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..4 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [bitinv]                                                       */
/*     0 = Do not invert                                            */
/*     1 = Invert.                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_t tmp_slc0_mr10x4_sds_common_tx0_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TX0_Config) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_STRIDE);
      tmp_slc0_mr10x4_sds_common_tx0_config.bf.bitinv = bitinv;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TX0_Config) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_STRIDE, tmp_slc0_mr10x4_sds_common_tx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON RX CONFIG BITINV     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_rx_config_bitinv(cs_uint16 module_id, cs_uint8 instance, 
                                                           cs_uint16 bitinv)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Bit Invert                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This bit inverts the polarity of all rx data bits when set.      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..4 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [bitinv]                                                       */
/*     0 = Do not invert                                            */
/*     1 = Invert.                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_t tmp_slc0_mr10x4_sds_common_rx0_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RX0_Config) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_STRIDE);
      tmp_slc0_mr10x4_sds_common_rx0_config.bf.bitinv = bitinv;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RX0_Config) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_STRIDE, tmp_slc0_mr10x4_sds_common_rx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON TX CONFIG BITINV     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_tx_config_bitinv(cs_uint16 module_id, 
                                                           cs_uint8 instance, 
                                                           cs_uint16 bitinv)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Bit Invert                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This bit inverts the polarity of all tx data bits when set.      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..4 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [bitinv]                                                       */
/*     0 = Do not invert                                            */
/*     1 = Invert.                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_t tmp_slc2_mr10x4_sds_common_tx0_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TX0_Config) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_STRIDE);
      tmp_slc2_mr10x4_sds_common_tx0_config.bf.bitinv = bitinv;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TX0_Config) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_STRIDE, tmp_slc2_mr10x4_sds_common_tx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON RX CONFIG BITINV     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_rx_config_bitinv(cs_uint16 module_id, cs_uint8 instance, 
                                                           cs_uint16 bitinv)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Bit Invert                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This bit inverts the polarity of all rx data bits when set.      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..4 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [bitinv]                                                       */
/*     0 = Do not invert                                            */
/*     1 = Invert.                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_t tmp_slc2_mr10x4_sds_common_rx0_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RX0_Config) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_STRIDE);
      tmp_slc2_mr10x4_sds_common_rx0_config.bf.bitinv = bitinv;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RX0_Config) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_STRIDE, tmp_slc2_mr10x4_sds_common_rx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HSIF GET VC0 TUNE INTSTATUS                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_boolean ten_hsif_get_vco_tune_intstatus(cs_uint16 module_id,
                                           cs_uint8 slice,
                                           cs_dir_t dir, 
                                           cs_uint8 instance)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Instance                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Returns the Current state of the Coarse Tuning Algorithm's   */
/* "SHORT_FILTPN" output signal.                                */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/* RX:  0..3 for MR10X4 and 0..4 for MR10X5                     */
/* TX:  0.                                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_boolean ret_val;
  cs_uint16 ii;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  if (dir == CS_RX) {
    switch (slice) {
    case (TEN_SLICE0):
      {
        TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_INTSTATUS_t tmp_slc0_mr10x4_sds_common_rxvco0_intstatus;
        
        if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_INTSTATUS_COUNT) && 
            (instance != TEN_INSTANCE_ALL)) {
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
          return(FALSE);
        }
        
        ret_val = 1;
        for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_INTSTATUS_COUNT; ii++) {
          if ((ii == instance) || (instance == TEN_INSTANCE_ALL)) {
            tmp_slc0_mr10x4_sds_common_rxvco0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_INTSTATUS) +
                                                                         ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_INTSTATUS_STRIDE);
            ret_val &= (tmp_slc0_mr10x4_sds_common_rxvco0_intstatus.bf.SHORT_FILTPNs == 1);
          }
        }  
        break;
      }
      
    case (TEN_SLICE1):
      {
        TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_RXVCO0_INTSTATUS_t tmp_slc1_mr10x5_sds_common_rxvco0_intstatus;
        cs_uint16 cnt; 
        TEN_HSIF_PROTOCOL_Datapath_Prov0_t tmp_datapath_prov0;

        if ((instance >= TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_RXVCO0_INTSTATUS_COUNT) &&
            (instance != TEN_INSTANCE_ALL)) {
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
          return(FALSE);
        }
        
        /* only read the 5th serdes for SFI5.                    */
        /* The first five lane instance (slice 1) has the        */
        /* fifth lane used for the SFI-5.1 deskew channel.       */
        /* Check fifth lane for lock in SFI-5.1 case             */
        /* and do not check lock for SFI-4.1.                    */
        /* bugzilla #24439, klocwork */
        tmp_addr = TEN_HSIF_REG_ADDR(pDev, module_id, Datapath_Prov0);
        tmp_addr += 1 * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE;
        tmp_datapath_prov0.wrd = TEN_REG_READ(tmp_addr);
        /* SFI-5 (default) */
        if (tmp_datapath_prov0.bf.rx_mrprotocol == 1) { 
          cnt = TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_RXVCO0_INTSTATUS_COUNT;
        }
        else {
          cnt = 4;
        }
        ret_val = 1;
        for (ii=0; ii<cnt; ii++) {
          if ((ii == instance) || (instance == TEN_INSTANCE_ALL)) {
            tmp_slc1_mr10x5_sds_common_rxvco0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, RXVCO0_INTSTATUS) +
                                                                           ii * TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_RXVCO0_INTSTATUS_STRIDE);
            ret_val &= (tmp_slc1_mr10x5_sds_common_rxvco0_intstatus.bf.SHORT_FILTPNs == 1);
          }
        }  
        break;
      }
      
    case (TEN_SLICE2):
      {
        TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_INTSTATUS_t tmp_slc2_mr10x4_sds_common_rxvco0_intstatus;

        if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_INTSTATUS_COUNT) &&
            (instance != TEN_INSTANCE_ALL)) {
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
          return(FALSE);
        }
        
        ret_val = 1;
        for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_INTSTATUS_COUNT; ii++) {
          if ((ii == instance) || (instance == TEN_INSTANCE_ALL)) {
            tmp_slc2_mr10x4_sds_common_rxvco0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_INTSTATUS) +
                                                                           ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_INTSTATUS_STRIDE);
            ret_val &= (tmp_slc2_mr10x4_sds_common_rxvco0_intstatus.bf.SHORT_FILTPNs == 1);
          }
        }
        break;
      }
      
    case (TEN_SLICE3):
      {
        TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_RXVCO0_INTSTATUS_t tmp_slc3_mr10x5_sds_common_rxvco0_intstatus;

        if ((instance >= TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_RXVCO0_INTSTATUS_COUNT) &&
            (instance != TEN_INSTANCE_ALL)) {
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
          return(FALSE);
        }
        
        ret_val = 1;
        
        /* For slice 3 the fifth lane Rx is never used as a serdes   */
        /* (Rx pad is used as an SFI-4.1 clock input).               */
        /* So never check if fifth lane is locked for slice 3.       */
              
        for (ii=0; ii<4; ii++) {
          if ((ii == instance) || (instance == TEN_INSTANCE_ALL)) {

            tmp_slc3_mr10x5_sds_common_rxvco0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, RXVCO0_INTSTATUS) +
                                                                           ii * TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_RXVCO0_INTSTATUS_STRIDE);
            ret_val &= (tmp_slc3_mr10x5_sds_common_rxvco0_intstatus.bf.SHORT_FILTPNs == 1);
          }
        }
        break;
      }
      
    default: 
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3");
        ret_val = FALSE;
        break;
      }
    }
  }
  else if (dir == CS_TX) {
  
    if (instance != 0) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0.");
      return(FALSE);
    }
        
    switch (slice) {
    case TEN_SLICE0:
      {
        TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TXVCO0_INTSTATUS_t tmp_slc0_mr10x4_sds_common_txvco0_intstatus;
        tmp_slc0_mr10x4_sds_common_txvco0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_INTSTATUS));
        ret_val = (tmp_slc0_mr10x4_sds_common_txvco0_intstatus.bf.SHORT_FILTPNs == 1);
        break;
      }
    case TEN_SLICE1:
      {
        TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_TXVCO0_INTSTATUS_t tmp_slc1_mr10x5_sds_common_txvco0_intstatus;
        tmp_slc1_mr10x5_sds_common_txvco0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, TXVCO0_INTSTATUS));
        ret_val = (tmp_slc1_mr10x5_sds_common_txvco0_intstatus.bf.SHORT_FILTPNs == 1);
        break;
      }
    case TEN_SLICE2:
      {
        TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TXVCO0_INTSTATUS_t tmp_slc2_mr10x4_sds_common_txvco0_intstatus;
        tmp_slc2_mr10x4_sds_common_txvco0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_INTSTATUS));
        ret_val = (tmp_slc2_mr10x4_sds_common_txvco0_intstatus.bf.SHORT_FILTPNs == 1);
        break;
      }
    case TEN_SLICE3:
      {
        TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_TXVCO0_INTSTATUS_t tmp_slc3_mr10x5_sds_common_txvco0_intstatus;
        tmp_slc3_mr10x5_sds_common_txvco0_intstatus.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, TXVCO0_INTSTATUS));
        ret_val = (tmp_slc3_mr10x5_sds_common_txvco0_intstatus.bf.SHORT_FILTPNs == 1);
        break;
      }
    default: 
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3");
        ret_val = FALSE;
        break;
      }
    }
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dir out of range.  s/b 0..1");
    ret_val = FALSE;
  }

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SET SLC0 MR10X4 RXLOCKD0 FORCE LOCK         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_slc0_mr10x4_rxlockd0_force_lock(cs_uint16 module_id,
                                                       cs_uint8  instance, 
                                                       cs_uint16 pd_mode, 
                                                       cs_uint16 force_lock)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o PD MODE                                           */
/*              o FORCE LOCK                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Clock and Data Recovery (CDR) Lock Detector Control Register.    */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [pd_mode] parameter is specified as:                         */
/*   0..1, Force the lock state to the value "PD_MODE" when         */
/*   FORCE_LOCK is asserted.                                        */
/*                                                                  */
/* The [force_lock] parameter is specified as:                      */
/*   0..1, Force the lock state to the value "PD_MODE" when         */
/*   FORCE_LOCK is asserted.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/

{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_slc0_mr10x4_sds_common_rxlockd0_control;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxlockd0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE);
      tmp_slc0_mr10x4_sds_common_rxlockd0_control.bf.PD_MODE = pd_mode;
      tmp_slc0_mr10x4_sds_common_rxlockd0_control.bf.FORCE_LOCK = force_lock;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE, tmp_slc0_mr10x4_sds_common_rxlockd0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SET SLC2 MR10X4 RXLOCKD0 FORCE LOCK         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_slc2_mr10x4_rxlockd0_force_lock(cs_uint16 module_id,
                                                       cs_uint8  instance, 
                                                       cs_uint16 pd_mode, 
                                                       cs_uint16 force_lock)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o PD MODE                                           */
/*              o FORCE LOCK                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Clock and Data Recovery (CDR) Lock Detector Control Register.    */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [pd_mode] parameter is specified as:                         */
/*   0..1, Force the lock state to the value "PD_MODE" when         */
/*   FORCE_LOCK is asserted.                                        */
/*                                                                  */
/* The [force_lock] parameter is specified as:                      */
/*   0..1, Force the lock state to the value "PD_MODE" when         */
/*   FORCE_LOCK is asserted.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_slc2_mr10x4_sds_common_rxlockd0_control;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxlockd0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE);
      tmp_slc2_mr10x4_sds_common_rxlockd0_control.bf.PD_MODE = pd_mode;
      tmp_slc2_mr10x4_sds_common_rxlockd0_control.bf.FORCE_LOCK = force_lock;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE, tmp_slc2_mr10x4_sds_common_rxlockd0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SET SLC0 MR10X4 RXLOCKD0 DATA LOCK         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_slc0_mr10x4_rxlockd0_data_lock(cs_uint16 module_id,
                                                      cs_uint8  instance, 
                                                      cs_uint16 data_lock)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o DATA LOCK                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Clock and Data Recovery (CDR) Lock Detector Control Register.    */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [data_lock] parameter is specified as:                       */
/*   0..1, When this bit is set, use the "receive data detected"    */
/*   signal when making the lock decision. Only pertinent in ONU    */
/*   mode; in OLT mode this control bit has no effect.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/

{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_slc0_mr10x4_sds_common_rxlockd0_control;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxlockd0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE);
      tmp_slc0_mr10x4_sds_common_rxlockd0_control.bf.DATA_LOCK = data_lock;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE, tmp_slc0_mr10x4_sds_common_rxlockd0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SET SLC2 MR10X4 RXLOCKD0 DATA LOCK         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_slc2_mr10x4_rxlockd0_data_lock(cs_uint16 module_id,
                                                      cs_uint8  instance, 
                                                      cs_uint16 data_lock)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o DATA LOCK                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Clock and Data Recovery (CDR) Lock Detector Control Register.    */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [data_lock] parameter is specified as:                       */
/*   0..1, When this bit is set, use the "receive data detected"    */
/*   signal when making the lock decision. Only pertinent in ONU    */
/*   mode; in OLT mode this control bit has no effect.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_slc2_mr10x4_sds_common_rxlockd0_control;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxlockd0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE);
      tmp_slc2_mr10x4_sds_common_rxlockd0_control.bf.DATA_LOCK = data_lock;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE, tmp_slc2_mr10x4_sds_common_rxlockd0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 RXLOCKD0 DATA FILTLOCK          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_rxlockd0_data_filtlock(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 data_filtlock)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o DATA FILTLOCK                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [data_filtlock]                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_slc0_mr10x4_sds_common_rxlockd0_control;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxlockd0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE);
      tmp_slc0_mr10x4_sds_common_rxlockd0_control.bf.DATA_FILTLOCK = data_filtlock;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE, tmp_slc0_mr10x4_sds_common_rxlockd0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 RXLOCKD0 DATA FILTLOCK          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_rxlockd0_data_filtlock(cs_uint16 module_id, cs_uint8 instance, 
                                                      cs_uint16 data_filtlock)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o DATA FILTLOCK                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [data_filtlock]                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_slc2_mr10x4_sds_common_rxlockd0_control;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxlockd0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE);
      tmp_slc2_mr10x4_sds_common_rxlockd0_control.bf.DATA_FILTLOCK = data_filtlock;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXLOCKD0_CONTROL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE, tmp_slc2_mr10x4_sds_common_rxlockd0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 STXP_LPBKEN    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_lpbken(cs_uint16 module_id, 
                                                       cs_uint16 stxp_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o STXP LPBKEN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Power drivers to enable serial loopback.                         */
/*                                                                  */
/*   [stxp_lpbken]                                                  */
/*     0 = loopback disabled                                        */
/*     1 = loopback enabled                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc0_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPBKEN=stxp_lpbken;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 STXP_LPBKEN    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_lpbken(cs_uint16 module_id, 
                                                       cs_uint16 stxp_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o STXP LPBKEN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Power drivers to enable serial loopback.                         */
/*                                                                  */
/*   [stxp_lpbken]                                                  */
/*     0 = loopback disabled                                        */
/*     1 = loopback enabled                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc2_mr10x4_sds_common_stxp0_tx_config;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPBKEN=stxp_lpbken;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG), tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SET SLC0 MR10X4 SDS COMMON RXVCO0 VCOMAX    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_slc0_mr10x4_sds_common_rxvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint8  instance, 
                                                            cs_uint16 vcomax)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o VCOMAX                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the length of time the Tuning Algorithm remains at a    */
/* particular frequency step. The value in this register, times     */
/* the period of the vco clock, equals the length of time the       */
/* Algorithm spends evaluating a particular frequency step.         */
/* Generally speaking, the longer the evaluation period, the        */
/* greater the resolution of the algorithm.                         */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [vcomax] parameter is specified as:                          */
/*   0x0000..0x0FFF                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_VCOMAX_t tmp_slc0_mr10x4_sds_common_rxvco0_vcomax;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_VCOMAX_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_VCOMAX_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxvco0_vcomax.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_VCOMAX) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_VCOMAX_STRIDE);
      tmp_slc0_mr10x4_sds_common_rxvco0_vcomax.bf.VCOMAX = vcomax;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_VCOMAX) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXVCO0_VCOMAX_STRIDE, tmp_slc0_mr10x4_sds_common_rxvco0_vcomax.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SET SLC2 MR10X4 SDS COMMON RXVCO0 VCOMAX    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_slc2_mr10x4_sds_common_rxvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint8  instance, 
                                                            cs_uint16 vcomax)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o VCOMAX                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the length of time the Tuning Algorithm remains at a    */
/* particular frequency step. The value in this register, times     */
/* the period of the vco clock, equals the length of time the       */
/* Algorithm spends evaluating a particular frequency step.         */
/* Generally speaking, the longer the evaluation period, the        */
/* greater the resolution of the algorithm.                         */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [vcomax] parameter is specified as:                          */
/*   0x0000..0x0FFF                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_VCOMAX_t tmp_slc2_mr10x4_sds_common_rxvco0_vcomax;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_VCOMAX_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_VCOMAX_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxvco0_vcomax.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_VCOMAX) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_VCOMAX_STRIDE);
      tmp_slc2_mr10x4_sds_common_rxvco0_vcomax.bf.VCOMAX = vcomax;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXVCO0_VCOMAX) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXVCO0_VCOMAX_STRIDE, tmp_slc2_mr10x4_sds_common_rxvco0_vcomax.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SET SLC0 MR10X4 SDS COMMON TXVCO0 VCOMAX    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_slc0_mr10x4_sds_common_txvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint16 vcomax)
/* INPUTS     : o Module Id                                         */
/*              o VCOMAX                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the length of time the Tuning Algorithm remains at a    */
/* particular frequency step. The value in this register, times     */
/* the period of the vco clock, equals the length of time the       */
/* Algorithm spends evaluating a particular frequency step.         */
/* Generally speaking, the longer the evaluation period, the        */
/* greater the resolution of the algorithm.                         */
/*                                                                  */
/* The [vcomax] parameter is specified as:                          */
/*   0x0000..0x0FFF                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TXVCO0_VCOMAX_t tmp_slc0_mr10x4_sds_common_txvco0_vcomax;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_txvco0_vcomax.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_VCOMAX));
  tmp_slc0_mr10x4_sds_common_txvco0_vcomax.bf.VCOMAX = vcomax;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_VCOMAX), tmp_slc0_mr10x4_sds_common_txvco0_vcomax.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SET SLC2 MR10X4 SDS COMMON TXVCO0 VCOMAX    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_set_slc2_mr10x4_sds_common_txvco0_vcomax(cs_uint16 module_id,
                                                            cs_uint16 vcomax)
/* INPUTS     : o Module Id                                         */
/*              o VCOMAX                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the length of time the Tuning Algorithm remains at a    */
/* particular frequency step. The value in this register, times     */
/* the period of the vco clock, equals the length of time the       */
/* Algorithm spends evaluating a particular frequency step.         */
/* Generally speaking, the longer the evaluation period, the        */
/* greater the resolution of the algorithm.                         */
/*                                                                  */
/* The [vcomax] parameter is specified as:                          */
/*   0x0000..0x0FFF                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TXVCO0_VCOMAX_t tmp_slc2_mr10x4_sds_common_txvco0_vcomax;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_txvco0_vcomax.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_VCOMAX));
  tmp_slc2_mr10x4_sds_common_txvco0_vcomax.bf.VCOMAX = vcomax;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXVCO0_VCOMAX), tmp_slc2_mr10x4_sds_common_txvco0_vcomax.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX PWRDN ALL   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_all(cs_uint16 module_id, 
                                                             cs_uint16 stxp_pd)
/* INPUTS     : o Module Id                                         */
/*              o STXP PD                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register contains power down bits for TX PLL.               */
/*                                                                  */
/*  The [stxp_pd] parameter is specified as:                        */
/*    0 = entire transmit section not powered down                  */
/*    1 = entire transmit section powered down                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_PWRDN_t tmp_slc0_mr10x4_sds_common_stxp0_tx_pwrdn;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_pwrdn.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_PWRDN));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_pwrdn.bf.STXP_PD = stxp_pd;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_PWRDN), tmp_slc0_mr10x4_sds_common_stxp0_tx_pwrdn.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX PWRDN ALL   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_all(cs_uint16 module_id, 
                                                             cs_uint16 stxp_pd)
/* INPUTS     : o Module Id                                         */
/*              o STXP PD                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register contains power down bits for TX PLL.               */
/*                                                                  */
/*  The [stxp_pd] parameter is specified as:                        */
/*    0 = entire transmit section not powered down                  */
/*    1 = entire transmit section powered down                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_PWRDN_t tmp_slc2_mr10x4_sds_common_stxp0_tx_pwrdn;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_pwrdn.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_PWRDN));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_pwrdn.bf.STXP_PD = stxp_pd;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_PWRDN), tmp_slc2_mr10x4_sds_common_stxp0_tx_pwrdn.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXP0 TX PWRDN PD LANE */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(cs_uint16 module_id, 
                                                                 cs_uint16 stxp_pd_lane)
/* INPUTS     : o Module Id                                         */
/*              o STXP PD LANE                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control TX PLL power down.                                       */
/*                                                                  */
/*   [stxp_pd_lane]  Power down individual lanes on the             */
/*    transmit section.                                             */
/*    0 = lane N powered                                            */
/*    1 = lane N powered down                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_PWRDN_t tmp_slc0_mr10x4_sds_common_stxp0_tx_pwrdn;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_pwrdn.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_PWRDN));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_pwrdn.bf.STXP_PD_LANE = stxp_pd_lane;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_PWRDN), tmp_slc0_mr10x4_sds_common_stxp0_tx_pwrdn.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXP0 TX PWRDN PD LANE */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(cs_uint16 module_id, 
                                                                 cs_uint16 stxp_pd_lane)
/* INPUTS     : o Module Id                                         */
/*              o STXP PD LANE                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control TX PLL power down.                                       */
/*                                                                  */
/*   [stxp_pd_lane]  Power down individual lanes on the             */
/*    transmit section.                                             */
/*    0 = lane N powered                                            */
/*    1 = lane N powered down                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_PWRDN_t tmp_slc2_mr10x4_sds_common_stxp0_tx_pwrdn;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_pwrdn.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_PWRDN));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_pwrdn.bf.STXP_PD_LANE = stxp_pd_lane;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_PWRDN), tmp_slc2_mr10x4_sds_common_stxp0_tx_pwrdn.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON SRXO SRX_PD          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_srx_pd(cs_uint16 module_id, 
                                                      cs_uint8 instance, 
                                                      cs_uint16 srx_pd)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX POWER DOWN                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Power down the entire receive slice.                             */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_pd]                                                       */
/*     0 = not powered down                                         */
/*     1 = powered down                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_t tmp_slc0_mr10x4_sds_common_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_config.bf.SRX_PD = srx_pd;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON SRXO SRX_PD          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_srx_pd(cs_uint16 module_id, 
                                                      cs_uint8 instance, 
                                                      cs_uint16 srx_pd)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX POWER DOWN                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Power down the entire receive slice.                             */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_pd]                                                       */
/*     0 = not powered down                                         */
/*     1 = powered down                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_t tmp_slc2_mr10x4_sds_common_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_config.bf.SRX_PD = srx_pd;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON RXELST0 RESYNC       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_rxelst0_resync(cs_uint16 module_id,
                                                         cs_uint8 instance, 
                                                         cs_uint16 resync)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Resync                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When set, this bit forces a resync of the elastic store read     */
/* pointers (datapath/loopback). Bit must be cleared to 0 to resume */
/* dataflow.                                                        */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [resync] parameter is specified as:                          */
/*   0..1                                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXELST0_Control_t tmp_slc0_mr10x4_sds_common_rxelst0_control;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXELST0_Control_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXELST0_Control_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_rxelst0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXELST0_Control) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXELST0_Control_STRIDE);
      tmp_slc0_mr10x4_sds_common_rxelst0_control.bf.resync = resync;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXELST0_Control) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXELST0_Control_STRIDE, tmp_slc0_mr10x4_sds_common_rxelst0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON RXELST0 RESYNC       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_rxelst0_resync(cs_uint16 module_id,
                                                         cs_uint8 instance, 
                                                         cs_uint16 resync)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Resync                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When set, this bit forces a resync of the elastic store read     */
/* pointers (datapath/loopback). Bit must be cleared to 0 to resume */
/* dataflow.                                                        */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [resync] parameter is specified as:                          */
/*   0..1                                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXELST0_Control_t tmp_slc2_mr10x4_sds_common_rxelst0_control;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXELST0_Control_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXELST0_Control_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_rxelst0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXELST0_Control) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXELST0_Control_STRIDE);
      tmp_slc2_mr10x4_sds_common_rxelst0_control.bf.resync = resync;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXELST0_Control) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXELST0_Control_STRIDE, tmp_slc2_mr10x4_sds_common_rxelst0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON TXELST0 RESYNC       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_txelst0_resync(cs_uint16 module_id,
                                                         cs_uint16 resync)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Resync                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When set, this bit forces a resync of the elastic store read     */
/* pointers (datapath/loopback). Bit must be cleared to 0 to resume */
/* dataflow.                                                        */
/*                                                                  */
/* The [resync] parameter is specified as:                          */
/*   0..1                                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TXELST0_Control_t tmp_slc0_mr10x4_sds_common_txelst0_control;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_txelst0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXELST0_Control));
  tmp_slc0_mr10x4_sds_common_txelst0_control.bf.resync = resync;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TXELST0_Control), tmp_slc0_mr10x4_sds_common_txelst0_control.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON TXELST0 RESYNC       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_txelst0_resync(cs_uint16 module_id,
                                                         cs_uint16 resync)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Resync                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When set, this bit forces a resync of the elastic store read     */
/* pointers (datapath/loopback). Bit must be cleared to 0 to resume */
/* dataflow.                                                        */
/*                                                                  */
/* The [resync] parameter is specified as:                          */
/*   0..1                                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TXELST0_Control_t tmp_slc2_mr10x4_sds_common_txelst0_control;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_txelst0_control.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXELST0_Control));
  tmp_slc2_mr10x4_sds_common_txelst0_control.bf.resync = resync;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TXELST0_Control), tmp_slc2_mr10x4_sds_common_txelst0_control.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON SRXO SRX_LPBKEN      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_srx_lpbken(cs_uint16 module_id, 
                                                          cs_uint8 instance, 
                                                          cs_uint16 srx_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX LOOPBACK ENABLE                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enable serial loop back at Equalizer input.                      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_lpbken]                                                   */
/*     0 = loopback disabled                                        */
/*     1 = loopback enabled                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_t tmp_slc0_mr10x4_sds_common_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_config.bf.SRX_LPBKEN = srx_lpbken;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON SRXO SRX_LPBKEN      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_srx_lpbken(cs_uint16 module_id, 
                                                          cs_uint8 instance, 
                                                          cs_uint16 srx_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX LOOPBACK ENABLE                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enable serial loop back at Equalizer input.                      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_lpbken]                                                   */
/*     0 = loopback disabled                                        */
/*     1 = loopback enabled                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_t tmp_slc2_mr10x4_sds_common_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_config.bf.SRX_LPBKEN = srx_lpbken;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CONFIG) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CONFIG_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON STXPO TX SPARE        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_spare(cs_uint16 module_id, 
                                                     cs_uint16 stxp_spare)
/* INPUTS     : o Module Id                                         */
/*              o STXP SPARE                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets spare control bits for the SERDES Analog front end.         */
/*                                                                  */
/*   [stxp_spare]                                                   */
/*     Transmitter spare bits:                                      */
/*     Spare<6> = 1: Driver Common mode feedback enable             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_SPARE_t tmp_slc0_mr10x4_sds_common_stxp0_tx_spare;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_SPARE));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_spare.bf.STXP_SPARE = stxp_spare;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_SPARE), tmp_slc0_mr10x4_sds_common_stxp0_tx_spare.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON STXPO TX SPARE        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_spare(cs_uint16 module_id, 
                                                     cs_uint16 stxp_spare)
/* INPUTS     : o Module Id                                         */
/*              o STXP SPARE                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets spare control bits for the SERDES Analog front end.         */
/*                                                                  */
/*   [stxp_spare]                                                   */
/*     Transmitter spare bits:                                      */
/*     Spare<6> = 1: Driver Common mode feedback enable             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_SPARE_t tmp_slc2_mr10x4_sds_common_stxp0_tx_spare;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_SPARE));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_spare.bf.STXP_SPARE = stxp_spare;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_SPARE), tmp_slc2_mr10x4_sds_common_stxp0_tx_spare.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SET SRX_CTVDIV_SEL              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_srx_ctvdiv_sel(cs_uint16 module_id, 
                                                              cs_uint8 instance, 
                                                              cs_uint16 srx_ctvdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX CTVDIV SEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Select to divide CLK_LD before reaching the digital core for use */
/* in coarse tuning.                                                */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [srx_ctvdiv_sel] parameter is specified as:                  */
/*   00 = div1                                                      */
/*   01 = div2                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKDIV_CTRL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.bf.SRX_CTVDIV_SEL = srx_ctvdiv_sel;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKDIV_CTRL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SET SRX_CTVDIV_SEL              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_srx_ctvdiv_sel(cs_uint16 module_id, 
                                                              cs_uint8 instance, 
                                                              cs_uint16 srx_ctvdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX CTVDIV SEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Select to divide CLK_LD before reaching the digital core for use */
/* in coarse tuning.                                                */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [srx_ctvdiv_sel] parameter is specified as:                  */
/*   00 = div1                                                      */
/*   01 = div2                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKDIV_CTRL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.bf.SRX_CTVDIV_SEL = srx_ctvdiv_sel;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKDIV_CTRL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SET STXP_CTRDIV_SEL             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_stxp_ctrdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctrdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o STXP CTRDIV SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Select to divide the clock reference before reaching the digital */
/* core for use in coarse tuning.                                   */
/*                                                                  */
/* The [stxp_ctrdiv_sel] parameter is specified as:                 */
/*   00 = div1                                                      */
/*   01 = div2                                                      */
/*   10 = div4                                                      */
/*   11 = div8                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_CTRDIV_SEL = stxp_ctrdiv_sel;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL), tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SET STXP_CTRDIV_SEL             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_stxp_ctrdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctrdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o STXP CTRDIV SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Select to divide the clock reference before reaching the digital */
/* core for use in coarse tuning.                                   */
/*                                                                  */
/* The [stxp_ctrdiv_sel] parameter is specified as:                 */
/*   00 = div1                                                      */
/*   01 = div2                                                      */
/*   10 = div4                                                      */
/*   11 = div8                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_CTRDIV_SEL = stxp_ctrdiv_sel;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL), tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SET STXP_CTVDIV_SEL             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_stxp0_stxp_ctvdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctvdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o STXP CTVDIV SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Select to divide CLK_LD before reaching the digital              */
/* core for use in coarse tuning.                                   */
/*                                                                  */
/* The [stxp_ctvdiv_sel] parameter is specified as:                 */
/*   00 = div1                                                      */
/*   01 = div2                                                      */
/*   10 = div4                                                      */
/*   11 = div8                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
  tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_CTVDIV_SEL = stxp_ctvdiv_sel;
  TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL), tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SET STXP_CTVDIV_SEL             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_stxp0_stxp_ctvdiv_sel(cs_uint16 module_id, 
                                                                cs_uint16 stxp_ctvdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o STXP CTVDIV SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Select to divide CLK_LD before reaching the digital              */
/* core for use in coarse tuning.                                   */
/*                                                                  */
/* The [stxp_ctvdiv_sel] parameter is specified as:                 */
/*   00 = div1                                                      */
/*   01 = div2                                                      */
/*   10 = div4                                                      */
/*   11 = div8                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
  tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_CTVDIV_SEL = stxp_ctvdiv_sel;
  TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL), tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON PRBSCHK0 ENABLE      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_prbschk0_enable(cs_uint16 module_id,
                                                          cs_uint8  instance, 
                                                          cs_uint16 enable)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Enable                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables receive PRBS monitoring function.                        */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [enable] parameter is specified as:                          */
/*   0 = disable Rx PRBS                                            */
/*   1 = enable Rx PRBS                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_t tmp_slc0_mr10x4_sds_common_prbschk0_cfg;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_prbschk0_cfg.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, PRBSCHK0_Cfg) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_STRIDE);
      tmp_slc0_mr10x4_sds_common_prbschk0_cfg.bf.enable = enable;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, PRBSCHK0_Cfg) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_STRIDE, tmp_slc0_mr10x4_sds_common_prbschk0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON PRBSCHK0 ENABLE      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_prbschk0_enable(cs_uint16 module_id,
                                                          cs_uint8  instance, 
                                                          cs_uint16 enable)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Enable                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables receive PRBS monitoring function.                        */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [enable] parameter is specified as:                          */
/*   0 = disable Rx PRBS                                            */
/*   1 = enable Rx PRBS                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_t tmp_slc2_mr10x4_sds_common_prbschk0_cfg;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_prbschk0_cfg.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, PRBSCHK0_Cfg) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_STRIDE);
      tmp_slc2_mr10x4_sds_common_prbschk0_cfg.bf.enable = enable;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, PRBSCHK0_Cfg) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_STRIDE, tmp_slc2_mr10x4_sds_common_prbschk0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON PRBSGEN0 PRBS_ENABLE */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_prbsgen0_prbs_enable(cs_uint16 module_id,
                                                               cs_uint8  instance, 
                                                               cs_uint16 prbs_enable)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Prbs Enable                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables PRBS generator.                                          */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [prbs_enable] parameter is specified as:                     */
/*   0 =  disable Tx PRBS                                           */
/*   1 =  enable Tx PRBS                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_t tmp_slc0_mr10x4_sds_common_prbsgen0_cfg;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, PRBSGEN0_Cfg) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_STRIDE);
      tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.bf.prbs_enable = prbs_enable;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, PRBSGEN0_Cfg) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_STRIDE, tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON PRBSGEN0 PRBS_ENABLE */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_prbsgen0_prbs_enable(cs_uint16 module_id,
                                                               cs_uint8  instance, 
                                                               cs_uint16 prbs_enable)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o Prbs Enable                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables PRBS generator.                                          */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..3 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* The [prbs_enable] parameter is specified as:                     */
/*   0 =  disable Tx PRBS                                           */
/*   1 =  enable Tx PRBS                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_t tmp_slc2_mr10x4_sds_common_prbsgen0_cfg;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, PRBSGEN0_Cfg) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_STRIDE);
      tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.bf.prbs_enable = prbs_enable;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, PRBSGEN0_Cfg) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_STRIDE, tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC0 MR10X4 SDS COMMON SRX0 RX CLKOUT CTRL  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(cs_uint16 module_id, cs_uint8 instance, 
                                                          cs_uint16 srx_tclko_sel)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX TCLKO SEL                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value of SRX_TCLKO_SEL.                                     */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_tclko_sel]                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_t tmp_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_STRIDE);
      tmp_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL = srx_tclko_sel;
      TEN_REG_WRITE(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL) +
      ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_STRIDE, tmp_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF SLC2 MR10X4 SDS COMMON SRX0 RX CLKOUT CTRL  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(cs_uint16 module_id, cs_uint8 instance, 
                                                          cs_uint16 srx_tclko_sel)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o SRX TCLKO SEL                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value of SRX_TCLKO_SEL.                                     */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [srx_tclko_sel]                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_t tmp_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);
  for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_STRIDE);
      tmp_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL = srx_tclko_sel;
      TEN_REG_WRITE(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL) +
      ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_STRIDE, tmp_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/* Bugzilla 23772 Start */
/********************************************************************/
/* $rtn_hdr_start  HSIF MR10 SDS COMMON PRBSCHK0 CFG                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_mr10_sds_common_prbschk0_cfg (cs_uint16 module_id,
                                                 cs_uint8  slice, 
                                                 cs_uint8  instance, 
                                                 cs_uint16 hsif,
                                                 cs_uint16 enable,
                                                 cs_uint16 invertPrbs,
                                                 cs_uint16 pattern)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Instance                                          */
/*              o HSIF                                              */
/*              o Enable                                            */
/*              o Invert Prbs                                       */
/*              o Pattern Selection                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provision receive PRBS monitoring function.                      */
/*                                                                  */
/* [module_id] specifies module ID                                  */ 
/*   0xXX00 = Module A                                              */      
/*   0xXX01 = Module B                                              */
/*                                                                  */      
/* [slice] specifies slice:                                         */      
/*   0x00 = TEN_SLICE0                                              */      
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..4 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* [hsif]  parameter is specified as:                               */
/*   0x01 = TEN_HSIF_PROTOCOL_SFI51                                 */
/*   0x05 = TEN_HSIF_PROTOCOL_SFI42_40G                             */
/*   0x06 = TEN_HSIF_PROTOCOL_XAUI                                  */
/*   0x07 = TEN_HSIF_PROTOCOL_CFP                                   */
/*                                                                  */
/* The [enable] parameter is specified as:                          */
/*   0 = disable Rx PRBS                                            */
/*   1 = enable Rx PRBS                                             */
/*                                                                  */
/* The [invertPrbs] parameter is specified as:                      */
/*   0 = Do Not invert Rx PRBS                                      */
/*   1 = invert Rx PRBS                                             */
/*                                                                  */
/* The [pattern] parameter is specified as:                         */
/*   0x00 = TEN_HSIF_PRBS_PN31                                      */
/*   0x01 = TEN_HSIF_PRBS_PN23                                      */
/*   0x02 = TEN_HSIF_PRBS_PN15                                      */
/*   0x03 = TEN_HSIF_PRBS_PN7                                       */
/*   0x04 = TEN_HSIF_PRBS_PN9                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_uint16 datawidth;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_t tmp_slc0_mr10x4_sds_common_prbschk0_cfg;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK0_Cfg_t tmp_slc1_mr10x5_sds_common_prbschk0_cfg;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_t tmp_slc2_mr10x4_sds_common_prbschk0_cfg;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK0_Cfg_t tmp_slc3_mr10x5_sds_common_prbschk0_cfg;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXELST0_Control_t tmp_slc0_mr10x4_sds_common_rxelst0_Control;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_RXELST0_Control_t tmp_slc1_mr10x5_sds_common_rxelst0_Control;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXELST0_Control_t tmp_slc2_mr10x4_sds_common_rxelst0_Control;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_RXELST0_Control_t tmp_slc3_mr10x5_sds_common_rxelst0_Control;
  T41_t *pDev = NULL;
  cs_uint16 module_num = module_id & 1;

  cs_char8 *func = "ten_hsif_mr10_sds_common_prbschk0_cfg";  
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255. ", func, slice);
    return (CS_ERROR);
  }

  if (instance != TEN_INSTANCE_ALL) {
    if ((slice == 0) || (slice == 2) || (slice == TEN_SLICE_ALL)) {
      if (instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_COUNT) {
        CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..3.", func, instance);
        return(CS_ERROR);
      }
    }
    else if ((slice == 1) || (slice == 3) || (slice == TEN_SLICE_ALL)) {
      if (instance >= TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_COUNT) {
        CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..4.", func, instance);
        return(CS_ERROR);
      }
    }  
  }
  
  /* Bugzilla 26403 Start */
  if ((hsif != TEN_HSIF_PROTOCOL_SFI51) && (hsif != TEN_HSIF_PROTOCOL_XAUI) &&
      (hsif != TEN_HSIF_PROTOCOL_SFI42_40G) && (hsif != TEN_HSIF_PROTOCOL_CFP)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() hsif %d out of range.  s/b 1, 5, 6, 7.", func, hsif);
    return (CS_ERROR);
  }
  /* Bugzilla 26403 End */

  if (enable > 1) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() enable %d out of range.  s/b 0..1.", func, enable);
    return(CS_ERROR);
  }

  if (invertPrbs > 1) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() invertPrbs %d out of range.  s/b 0..1.", func, invertPrbs);
    return(CS_ERROR);
  }

  if (pattern > TEN_HSIF_PRBS_PN9) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..1.", func, pattern);
    return(CS_ERROR);
  }

  CS_PRINT ("%s() %s, Slice %d, instance %d, %s, enable %d, invertPrbs %d, %s\n",
            func,
            ten_module_strings[module_num],
            slice,
            instance,
            ten_hsif_protocols_strings[hsif],
            enable,
            invertPrbs,
            ten_hsif_prbs_pn_strings[pattern]);


  if (hsif == TEN_HSIF_PROTOCOL_XAUI) {
    datawidth = 10;
  } else {
    datawidth = 8;
  }

  TEN_MOD_LOCK (module_id, TEN_ID_HSIF);
  if ((slice == 0) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc0_mr10x4_sds_common_prbschk0_cfg.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR (pDev, module_id, PRBSCHK0_Cfg) +
        ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_STRIDE);
        tmp_slc0_mr10x4_sds_common_prbschk0_cfg.bf.enable = enable;
        tmp_slc0_mr10x4_sds_common_prbschk0_cfg.bf.invertPrbs = invertPrbs;
        tmp_slc0_mr10x4_sds_common_prbschk0_cfg.bf.prbs_mode = pattern;
        /*tmp_slc0_mr10x4_sds_common_prbschk0_cfg.bf.datawidth = datawidth;*/
        tmp_slc0_mr10x4_sds_common_prbschk0_cfg.wrd &= 0xFF;
        tmp_slc0_mr10x4_sds_common_prbschk0_cfg.wrd |= datawidth << 8;
        TEN_REG_WRITE (TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, PRBSCHK0_Cfg) +
        ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_STRIDE, tmp_slc0_mr10x4_sds_common_prbschk0_cfg.wrd);
      
        /* Disable use lockdet so all lanes do not have to be present */
        tmp_slc0_mr10x4_sds_common_rxelst0_Control.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR (pDev, module_id, RXELST0_Control) +
        ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXELST0_Control_STRIDE);
        tmp_slc0_mr10x4_sds_common_rxelst0_Control.bf.use_lockdet = 0;
        TEN_REG_WRITE (TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RXELST0_Control) +
        ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXELST0_Control_STRIDE, tmp_slc0_mr10x4_sds_common_rxelst0_Control.wrd);
      }
    }
  }
  if ((slice == 1) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK0_Cfg_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc1_mr10x5_sds_common_prbschk0_cfg.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR (pDev, module_id, PRBSCHK0_Cfg) +
        ii * TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK0_Cfg_STRIDE);
        tmp_slc1_mr10x5_sds_common_prbschk0_cfg.bf.enable = enable;
        tmp_slc1_mr10x5_sds_common_prbschk0_cfg.bf.invertPrbs = invertPrbs;
        tmp_slc1_mr10x5_sds_common_prbschk0_cfg.bf.prbs_mode = pattern;
        /*tmp_slc1_mr10x5_sds_common_prbschk0_cfg.bf.datawidth = datawidth;*/
        tmp_slc1_mr10x5_sds_common_prbschk0_cfg.wrd &= 0xFF;
        tmp_slc1_mr10x5_sds_common_prbschk0_cfg.wrd |= datawidth << 8;
        TEN_REG_WRITE (TEN_HSIF_SLC1_MR10X5_REG_ADDR (pDev, module_id, PRBSCHK0_Cfg) +
        ii * TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK0_Cfg_STRIDE, tmp_slc1_mr10x5_sds_common_prbschk0_cfg.wrd);
      
        /* Disable use lockdet so all lanes do not have to be present */
        tmp_slc1_mr10x5_sds_common_rxelst0_Control.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR (pDev, module_id, RXELST0_Control) +
        ii * TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_RXELST0_Control_STRIDE);
        tmp_slc1_mr10x5_sds_common_rxelst0_Control.bf.use_lockdet = 0;
        TEN_REG_WRITE (TEN_HSIF_SLC1_MR10X5_REG_ADDR (pDev, module_id, RXELST0_Control) +
        ii * TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_RXELST0_Control_STRIDE, tmp_slc1_mr10x5_sds_common_rxelst0_Control.wrd);
      }
    }
  }
  if ((slice == 2) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc2_mr10x4_sds_common_prbschk0_cfg.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR (pDev, module_id, PRBSCHK0_Cfg) +
        ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_STRIDE);
        tmp_slc2_mr10x4_sds_common_prbschk0_cfg.bf.enable = enable;
        tmp_slc2_mr10x4_sds_common_prbschk0_cfg.bf.invertPrbs = invertPrbs;
        tmp_slc2_mr10x4_sds_common_prbschk0_cfg.bf.prbs_mode = pattern;
        /*tmp_slc2_mr10x4_sds_common_prbschk0_cfg.bf.datawidth = datawidth;*/
        tmp_slc2_mr10x4_sds_common_prbschk0_cfg.wrd &= 0xFF;
        tmp_slc2_mr10x4_sds_common_prbschk0_cfg.wrd |= datawidth << 8;
        TEN_REG_WRITE (TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, PRBSCHK0_Cfg) +
        ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_Cfg_STRIDE, tmp_slc2_mr10x4_sds_common_prbschk0_cfg.wrd);

        /* Disable use lockdet so all lanes do not have to be present */
        tmp_slc2_mr10x4_sds_common_rxelst0_Control.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR (pDev, module_id, RXELST0_Control) +
        ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXELST0_Control_STRIDE);
        tmp_slc2_mr10x4_sds_common_rxelst0_Control.bf.use_lockdet = 0;
        TEN_REG_WRITE (TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RXELST0_Control) +
        ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXELST0_Control_STRIDE, tmp_slc2_mr10x4_sds_common_rxelst0_Control.wrd);
      }
    }
  }
  if ((slice == 3) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK0_Cfg_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc3_mr10x5_sds_common_prbschk0_cfg.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR (pDev, module_id, PRBSCHK0_Cfg) +
        ii * TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK0_Cfg_STRIDE);
        tmp_slc3_mr10x5_sds_common_prbschk0_cfg.bf.enable = enable;
        tmp_slc3_mr10x5_sds_common_prbschk0_cfg.bf.invertPrbs = invertPrbs;
        tmp_slc3_mr10x5_sds_common_prbschk0_cfg.bf.prbs_mode = pattern;
        /*tmp_slc3_mr10x5_sds_common_prbschk0_cfg.bf.datawidth = datawidth;*/
        tmp_slc3_mr10x5_sds_common_prbschk0_cfg.wrd &= 0xFF;
        tmp_slc3_mr10x5_sds_common_prbschk0_cfg.wrd |= datawidth << 8;
        TEN_REG_WRITE (TEN_HSIF_SLC3_MR10X5_REG_ADDR (pDev, module_id, PRBSCHK0_Cfg) +
        ii * TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK0_Cfg_STRIDE, tmp_slc3_mr10x5_sds_common_prbschk0_cfg.wrd);

        /* Disable use lockdet so all lanes do not have to be present */
        tmp_slc3_mr10x5_sds_common_rxelst0_Control.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR (pDev, module_id, RXELST0_Control) +
        ii * TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_RXELST0_Control_STRIDE);
        tmp_slc3_mr10x5_sds_common_rxelst0_Control.bf.use_lockdet = 0;
        TEN_REG_WRITE (TEN_HSIF_SLC3_MR10X5_REG_ADDR (pDev, module_id, RXELST0_Control) +
        ii * TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_RXELST0_Control_STRIDE, tmp_slc3_mr10x5_sds_common_rxelst0_Control.wrd);
      }
    }
  }
  TEN_MOD_UNLOCK (module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF MR10 SDS COMMON PRBSGEN0 PRBS CFG           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_mr10_sds_common_prbsgen0_prbs_cfg (cs_uint16 module_id,
                                                      cs_uint8  slice, 
                                                      cs_uint8  instance, 
                                                      cs_uint16 hsif,
                                                      cs_uint16 enable,
                                                      cs_uint16 invertPrbs,
                                                      cs_uint16 pattern)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Instance                                          */
/*              o HSIF                                              */
/*              o Enable                                            */
/*              o Invert Prbs                                       */
/*              o Pattern Selection                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provision transmit PRBS monitoring function.                     */
/*                                                                  */
/* [module_id] specifies module ID                                  */ 
/*   0xXX00 = Module A                                              */      
/*   0xXX01 = Module B                                              */
/*                                                                  */      
/* [slice] specifies slice:                                         */      
/*   0x00 = TEN_SLICE0                                              */      
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..4 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* [hsif]  parameter is specified as:                               */
/*   0x01 = TEN_HSIF_PROTOCOL_SFI51                                 */
/*   0x05 = TEN_HSIF_PROTOCOL_SFI42_40G                             */
/*   0x06 = TEN_HSIF_PROTOCOL_XAUI                                  */
/*   0x07 = TEN_HSIF_PROTOCOL_CFP                                   */
/*                                                                  */
/* The [enable] parameter is specified as:                          */
/*   0 = disable Rx PRBS                                            */
/*   1 = enable Rx PRBS                                             */
/*                                                                  */
/* The [invertPrbs] parameter is specified as:                      */
/*   0 = Do Not invert Rx PRBS                                      */
/*   1 = invert Rx PRBS                                             */
/*                                                                  */
/* The [pattern] parameter is specified as:                         */
/*   0x00 = TEN_HSIF_PRBS_PN31                                      */
/*   0x01 = TEN_HSIF_PRBS_PN23                                      */
/*   0x02 = TEN_HSIF_PRBS_PN15                                      */
/*   0x03 = TEN_HSIF_PRBS_PN7                                       */
/*   0x04 = TEN_HSIF_PRBS_PN9                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_uint16 datawidth;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_t tmp_slc0_mr10x4_sds_common_prbsgen0_cfg;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_t tmp_slc1_mr10x5_sds_common_prbsgen0_cfg;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_t tmp_slc2_mr10x4_sds_common_prbsgen0_cfg;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_t tmp_slc3_mr10x5_sds_common_prbsgen0_cfg;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TXELST0_Control_t tmp_slc0_mr10x4_sds_common_txelst0_Control;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_TXELST0_Control_t tmp_slc1_mr10x5_sds_common_txelst0_Control;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TXELST0_Control_t tmp_slc2_mr10x4_sds_common_txelst0_Control;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_TXELST0_Control_t tmp_slc3_mr10x5_sds_common_txelst0_Control;
  T41_t *pDev = NULL;
  
  cs_uint16 module_num = module_id & 1;
  cs_char8 *func = "ten_hsif_mr10_sds_common_prbsgen0_prbs_cfg";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255. ", func, slice);
    return (CS_ERROR);
  }

  if (instance != TEN_INSTANCE_ALL) {
    if ((slice == 0) || (slice == 2) || (slice == TEN_SLICE_ALL)) {
      if (instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_COUNT) {
        CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..3.", func, instance);
        return(CS_ERROR);
      }
    }
    else if ((slice == 1) || (slice == 3) || (slice == TEN_SLICE_ALL)) {
      if (instance >= TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_COUNT) {
        CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..4.", func, instance);
        return(CS_ERROR);
      }
    }  
  }
  
  /* Bugzilla 26403 Start */
  if ((hsif != TEN_HSIF_PROTOCOL_SFI51) && (hsif != TEN_HSIF_PROTOCOL_XAUI) &&
      (hsif != TEN_HSIF_PROTOCOL_SFI42_40G) && (hsif != TEN_HSIF_PROTOCOL_CFP)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() hsif %d out of range.  s/b 1, 5, 6, 7", func, hsif);
    return (CS_ERROR);
  }
  /* Bugzilla 26403 End */

  if (enable > 1) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() enable %d out of range.  s/b 0..1.", func, enable);
    return(CS_ERROR);
  }

  if (invertPrbs > 1) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() invertPrbs %d out of range.  s/b 0..1.", func, invertPrbs);
    return(CS_ERROR);
  }

  if (pattern > TEN_HSIF_PRBS_PN9) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return(CS_ERROR);
  }

  CS_PRINT ("%s() %s, Slice %d, instance %d, enable %d, invertPrbs %d, %s\n",
            func,
            ten_module_strings[module_num],
            slice,
            instance,
            enable,
            invertPrbs,
            ten_hsif_prbs_pn_strings[pattern]);

  if (hsif == TEN_HSIF_PROTOCOL_XAUI) {
    datawidth = 10;
  } 
  else {
    datawidth = 8;
  }

  TEN_MOD_LOCK (module_id, TEN_ID_HSIF);
  if ((slice == 0) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.wrd = TEN_REG_READ (TEN_HSIF_SLC0_MR10X4_REG_ADDR (pDev, module_id, PRBSGEN0_Cfg) +
        ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_STRIDE);
        tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.bf.prbs_enable = enable;
        tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.bf.invertPrbs = invertPrbs;
        tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.bf.prbs_mode = pattern;
        /*tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.bf.datawidth = datawidth;*/
        tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.wrd &= 0xFF;
        tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.wrd |= datawidth << 8;
        TEN_REG_WRITE (TEN_HSIF_SLC0_MR10X4_REG_ADDR (pDev, module_id, PRBSGEN0_Cfg) +
        ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_STRIDE, tmp_slc0_mr10x4_sds_common_prbsgen0_cfg.wrd);
      }
    }

    /* Disable use lockdet so all lanes do not have to be present */
    tmp_slc0_mr10x4_sds_common_txelst0_Control.wrd = TEN_REG_READ (TEN_HSIF_SLC0_MR10X4_REG_ADDR (pDev, module_id, TXELST0_Control));
    tmp_slc0_mr10x4_sds_common_txelst0_Control.bf.use_lockdet = 0;
    TEN_REG_WRITE (TEN_HSIF_SLC0_MR10X4_REG_ADDR (pDev, module_id, TXELST0_Control), tmp_slc0_mr10x4_sds_common_txelst0_Control.wrd);
  }
  if ((slice == 1) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc1_mr10x5_sds_common_prbsgen0_cfg.wrd = TEN_REG_READ (TEN_HSIF_SLC1_MR10X5_REG_ADDR (pDev, module_id, PRBSGEN0_Cfg) +
        ii * TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_STRIDE);
        tmp_slc1_mr10x5_sds_common_prbsgen0_cfg.bf.prbs_enable = enable;
        tmp_slc1_mr10x5_sds_common_prbsgen0_cfg.bf.invertPrbs = invertPrbs;
        tmp_slc1_mr10x5_sds_common_prbsgen0_cfg.bf.prbs_mode = pattern;
        /*tmp_slc1_mr10x5_sds_common_prbsgen0_cfg.bf.datawidth = datawidth;*/
        tmp_slc1_mr10x5_sds_common_prbsgen0_cfg.wrd &= 0xFF;
        tmp_slc1_mr10x5_sds_common_prbsgen0_cfg.wrd |= datawidth << 8;
        TEN_REG_WRITE (TEN_HSIF_SLC1_MR10X5_REG_ADDR (pDev, module_id, PRBSGEN0_Cfg) +
        ii * TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_STRIDE, tmp_slc1_mr10x5_sds_common_prbsgen0_cfg.wrd);
      }
    }
    
    /* Disable use lockdet so all lanes do not have to be present */                                
    tmp_slc1_mr10x5_sds_common_txelst0_Control.wrd = TEN_REG_READ (TEN_HSIF_SLC1_MR10X5_REG_ADDR (pDev, module_id, TXELST0_Control));
    tmp_slc1_mr10x5_sds_common_txelst0_Control.bf.use_lockdet = 0;
    TEN_REG_WRITE (TEN_HSIF_SLC1_MR10X5_REG_ADDR (pDev, module_id, TXELST0_Control), tmp_slc1_mr10x5_sds_common_txelst0_Control.wrd);
  }
  if ((slice == 2) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR (pDev, module_id, PRBSGEN0_Cfg) +
        ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_STRIDE);
        tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.bf.prbs_enable = enable;
        tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.bf.invertPrbs = invertPrbs;
        tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.bf.prbs_mode = pattern;
        /*tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.bf.datawidth = datawidth;*/
        tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.wrd &= 0xFF;
        tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.wrd |= datawidth << 8;
        TEN_REG_WRITE (TEN_HSIF_SLC2_MR10X4_REG_ADDR (pDev, module_id, PRBSGEN0_Cfg) +
        ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSGEN0_Cfg_STRIDE, tmp_slc2_mr10x4_sds_common_prbsgen0_cfg.wrd);
      }
    }
    
    /* Disable use lockdet so all lanes do not have to be present */                                
    tmp_slc2_mr10x4_sds_common_txelst0_Control.wrd = TEN_REG_READ (TEN_HSIF_SLC2_MR10X4_REG_ADDR (pDev, module_id, TXELST0_Control));
    tmp_slc2_mr10x4_sds_common_txelst0_Control.bf.use_lockdet = 0;
    TEN_REG_WRITE (TEN_HSIF_SLC2_MR10X4_REG_ADDR (pDev, module_id, TXELST0_Control), tmp_slc2_mr10x4_sds_common_txelst0_Control.wrd);
  }
  if ((slice == 3) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc3_mr10x5_sds_common_prbsgen0_cfg.wrd = TEN_REG_READ (TEN_HSIF_SLC3_MR10X5_REG_ADDR (pDev, module_id, PRBSGEN0_Cfg) +
        ii * TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_STRIDE);
        tmp_slc3_mr10x5_sds_common_prbsgen0_cfg.bf.prbs_enable = enable;
        tmp_slc3_mr10x5_sds_common_prbsgen0_cfg.bf.invertPrbs = invertPrbs;
        tmp_slc3_mr10x5_sds_common_prbsgen0_cfg.bf.prbs_mode = pattern;
        /*tmp_slc3_mr10x5_sds_common_prbsgen0_cfg.bf.datawidth = datawidth;*/
        tmp_slc3_mr10x5_sds_common_prbsgen0_cfg.wrd &= 0xFF;
        tmp_slc3_mr10x5_sds_common_prbsgen0_cfg.wrd |= datawidth << 8;
        TEN_REG_WRITE (TEN_HSIF_SLC3_MR10X5_REG_ADDR (pDev, module_id, PRBSGEN0_Cfg) +
        ii * TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_STRIDE, tmp_slc3_mr10x5_sds_common_prbsgen0_cfg.wrd);
      }
    }
    
    /* Disable use lockdet so all lanes do not have to be present */                                
    tmp_slc3_mr10x5_sds_common_txelst0_Control.wrd = TEN_REG_READ (TEN_HSIF_SLC3_MR10X5_REG_ADDR (pDev, module_id, TXELST0_Control));
    tmp_slc3_mr10x5_sds_common_txelst0_Control.bf.use_lockdet = 0;
    TEN_REG_WRITE (TEN_HSIF_SLC3_MR10X5_REG_ADDR (pDev, module_id, TXELST0_Control), tmp_slc3_mr10x5_sds_common_txelst0_Control.wrd);
  }
  TEN_MOD_UNLOCK (module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF MR10 SDS COMMON TX CONFIG                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_mr10_sds_common_tx_config (cs_uint16 module_id, 
                                              cs_uint8  slice, 
                                              cs_uint8 instance, 
                                              cs_uint16 data_source)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Instance                                          */
/*              o Data Source                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the input source for the TX datapath.                    */
/*                                                                  */
/* [module_id] specifies module ID                                  */ 
/*   0xXX00 = Module A                                              */      
/*   0xXX01 = Module B                                              */
/*                                                                  */      
/* [slice] specifies slice:                                         */      
/*   0x00 = TEN_SLICE0                                              */      
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..4 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [data_source]                                                  */
/*     0 = TEN_HSIF_MR_DATASOURCE_DIG_TX_DIN                        */
/*     1 = TEN_HSIF_MR_DATASOURCE_PRBS                              */
/*     2 = TEN_HSIF_MR_DATASOURCE_RX_LOOPBACK                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 module_num = module_id & 1;
  cs_char8 *func = "ten_hsif_mr10_sds_common_tx_config";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255. ", func, slice);
    return (CS_ERROR);
  }

  if (instance != TEN_INSTANCE_ALL) {
    if ((slice == 0) || (slice == 2) || (slice == TEN_SLICE_ALL)) {
      if (instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_COUNT) {
        CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..3.", func, instance);
        return(CS_ERROR);
      }
    }
    else if ((slice == 1) || (slice == 3) || (slice == TEN_SLICE_ALL)) {
      if (instance >= TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_COUNT) {
        CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..4.", func, instance);
        return(CS_ERROR);
      }
    }  
  }
  
  if (data_source > TEN_HSIF_MR_DATASOURCE_RX_LOOPBACK) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() data_source %d out of range.  s/b 0..2.", func, data_source);
    return(CS_ERROR);
  }

  CS_PRINT ("%s() %s, Slice %d, instance %d, %s\n",
            func,
            ten_module_strings[module_num],
            slice,
            instance,
            ten_hsif_mr_data_source_strings[data_source]);

  if ((slice == 0) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc0_mr10x4_sds_common_tx_config (module_id, instance, data_source);
  }
  if ((slice == 1) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc1_mr10x5_sds_common_tx_config (module_id, instance, data_source);
  }
  if ((slice == 2) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc2_mr10x4_sds_common_tx_config (module_id, instance, data_source);
  }
  if ((slice == 3) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc3_mr10x5_sds_common_tx_config (module_id, instance, data_source);
  }
  
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HSIF MR10 SDS COMMON PRBSCHK0 INTSTATUS          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_hsif_mr10_sds_common_prbchk0_intstatus (cs_uint16 module_id,
                                                      cs_uint8  slice, 
                                                      cs_uint8  instance)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : PRBS Sync Status                                    */
/* DESCRIPTION:                                                     */
/* Returns the status of the PRBS monitor                           */
/* PRBS_SYNCs - When this bit is set it indicates that the receive  */
/*              PRBS monitor is currently unable to synchronize.    */
/*                                                                  */
/* [module_id] specifies module ID                                  */ 
/*   0xXX00 = Module A                                              */      
/*   0xXX01 = Module B                                              */
/*                                                                  */      
/* [slice] specifies slice:                                         */      
/*   0x00 = TEN_SLICE0                                              */      
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..4 or TEN_INSTANCE_ALL (0xFF)                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_INTSTATUS_t tmp_slc0_mr10x4_sds_common_prbschk0_instatus;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK0_INTSTATUS_t tmp_slc1_mr10x5_sds_common_prbschk0_instatus;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_INTSTATUS_t tmp_slc2_mr10x4_sds_common_prbschk0_instatus;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK0_INTSTATUS_t tmp_slc3_mr10x5_sds_common_prbschk0_instatus;
  T41_t *pDev = NULL;
  cs_uint16 prbs_sync_stat = 0;
  cs_char8 *func = "ten_hsif_mr10_sds_common_prbchk0_intstatus";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255. ", func, slice);
    return (CS_ERROR);
  }

  if (instance != TEN_INSTANCE_ALL) {
    if ((slice == 0) || (slice == 2) || (slice == TEN_SLICE_ALL)) {
      if (instance >= TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_COUNT) {
        CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..3.", func, instance);
        return(CS_ERROR);
      }
    }
    else if ((slice == 1) || (slice == 3) || (slice == TEN_SLICE_ALL)) {
      if (instance >= TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSGEN0_Cfg_COUNT) {
        CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..4.", func, instance);
        return(CS_ERROR);
      }
    }  
  }

  if ((slice == 0) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_INTSTATUS_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc0_mr10x4_sds_common_prbschk0_instatus.wrd = TEN_REG_READ (TEN_HSIF_SLC0_MR10X4_REG_ADDR (pDev, module_id, PRBSCHK0_INTSTATUS) +
        ii * TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_INTSTATUS_STRIDE);
        prbs_sync_stat |= (tmp_slc0_mr10x4_sds_common_prbschk0_instatus.bf.PRBS_SYNCs) << ii;
      }
    }
  }
  if ((slice == 1) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK0_INTSTATUS_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc1_mr10x5_sds_common_prbschk0_instatus .wrd = TEN_REG_READ (TEN_HSIF_SLC1_MR10X5_REG_ADDR (pDev, module_id, PRBSCHK0_INTSTATUS) +
        ii * TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK0_INTSTATUS_STRIDE);
        prbs_sync_stat |= (tmp_slc1_mr10x5_sds_common_prbschk0_instatus.bf.PRBS_SYNCs) << ii;
      }
    }
  }
  if ((slice == 2) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_INTSTATUS_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc2_mr10x4_sds_common_prbschk0_instatus.wrd = TEN_REG_READ (TEN_HSIF_SLC2_MR10X4_REG_ADDR (pDev, module_id, PRBSCHK0_INTSTATUS) +
        ii * TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_INTSTATUS_STRIDE);
        prbs_sync_stat |= (tmp_slc2_mr10x4_sds_common_prbschk0_instatus.bf.PRBS_SYNCs) << ii;
      }
    }
  }
  if ((slice == 3) || (slice == TEN_SLICE_ALL)) {
    for (ii=0; ii<TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK0_INTSTATUS_COUNT; ii++) {
      if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
        tmp_slc3_mr10x5_sds_common_prbschk0_instatus.wrd = TEN_REG_READ (TEN_HSIF_SLC3_MR10X5_REG_ADDR (pDev, module_id, PRBSCHK0_INTSTATUS) +
        ii * TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK0_INTSTATUS_STRIDE);
        prbs_sync_stat |= (tmp_slc3_mr10x5_sds_common_prbschk0_instatus.bf.PRBS_SYNCs) << ii;
      }
    }
  }

  return (prbs_sync_stat);
}
/* Bugzilla 23772 End */
