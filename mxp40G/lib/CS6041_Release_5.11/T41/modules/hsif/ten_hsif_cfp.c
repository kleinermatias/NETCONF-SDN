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
 * ten_hsif_cfp.c
 *
 * HSIF CFP related code is implemented here.
 *
 * $Id: ten_hsif_cfp.c,v 1.14 2013/02/22 20:49:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CONFIG T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_config_amp_pd_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                cs_uint16 srx_amp_pd)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX AMP PD                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for RX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_amp_pd]  Loop amplifier powerdown                         */
/*      0 = powered up                                              */
/*      1 = powered down.                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CONFIG_t tmp_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG));
      tmp_srx0_rx_config.bf.SRX_AMP_PD = srx_amp_pd;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG), tmp_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX SRX_PD T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_srx_pd_t41(cs_uint16 module_id,
                                         cs_uint8 slice, 
                                         cs_uint16 srx_pd)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX PD                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for RX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_pd]  Power down the entire receive slice:                 */
/*      0 = not powered down                                        */
/*      1 = powered down.                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CONFIG_t tmp_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG));
      tmp_srx0_rx_config.bf.SRX_PD = srx_pd;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG), tmp_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CONFIG BUSWIDTH T41              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_config_buswidth_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                  cs_uint16 srx_buswidth)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX BUSWIDTH                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for RX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_buswidth]  Set DEMUX bus width:                           */
/*      0 = enable 32bit mux mode                                   */
/*      1 = enable 40bit mux mode.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CONFIG_t tmp_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG));
      tmp_srx0_rx_config.bf.SRX_BUSWIDTH = srx_buswidth;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG), tmp_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CONFIG XFI EN T41                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_config_xfi_en_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                cs_uint16 srx_xfi_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX XFI EN                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects Mode. Used only in the 10G capable MR serdes.            */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* [srx_xfi_en]                                                     */
/*    0 = operates as MR serdes (sfi41/sfi42/xaui/sfi51)            */
/*    1 = operates as a 10G serdes (only RX lane 14 and TX lane 12).*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CONFIG_t tmp_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG));
      tmp_srx0_rx_config.bf.SRX_XFI_EN = srx_xfi_en;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG), tmp_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CONFIG LPBKEN T41                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_config_lpbken_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                cs_uint16 srx_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX LPBKEN                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets lpbken bit for RX.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_lpbken]  Enable serial loop back at Equalizer input.      */
/*     0 = loopback disabled                                        */
/*     1 = loopback enabled.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CONFIG_t tmp_srx0_rx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG));
      tmp_srx0_rx_config.bf.SRX_LPBKEN = srx_lpbken;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CONFIG), tmp_srx0_rx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CLKDIV CTRL FASTDIV T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_clkdiv_ctrl_fastdiv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                      cs_uint16 srx_fastdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX FASTDIV SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the divide ratio for SRX_FAST_CLK.                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_fastdiv_sel]                                              */
/*     TEN_HSIF_CFP_DIV_BY_16_REF = 0,                              */
/*     TEN_HSIF_CFP_DIV_BY_32_REF = 1,                              */
/*     TEN_HSIF_CFP_DIV_BY_64_REF = 2,                              */
/*     TEN_HSIF_CFP_DIV_BY_66_REF = 3,                              */
/*     TEN_HSIF_CFP_DIV_BY_40_REF = 4,                              */
/*     TEN_HSIF_CFP_DIV_BY_80_REF = 5.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL));
      tmp_srx0_rx_clkdiv_ctrl.bf.SRX_FASTDIV_SEL = srx_fastdiv_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL), tmp_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CLKDIV CTRL CTVDIV T41           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_clkdiv_ctrl_ctvdiv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                     cs_uint16 srx_ctvdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX CTVDIV SEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Select to divide CLK_LD before reaching the digital core for use */
/* in coarse tuning.                                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_ctvdiv_sel]                                               */
/*     div1 = 0                                                     */
/*     div2 = 1                                                     */
/*     div4 = 2                                                     */
/*     div8 = 3.                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL));
      tmp_srx0_rx_clkdiv_ctrl.bf.SRX_CTVDIV_SEL = srx_ctvdiv_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL), tmp_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CLKDIV CTRL DDIV T41             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_clkdiv_ctrl_ddiv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                   cs_uint16 srx_ddiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX DDIV SEL                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Select clock rate for receiver data path (full-rate=9.95328GHz   */
/* to 11.3GHz)                                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_ddiv_sel]                                                 */
/*     x00 = full-rate mode                                         */
/*     x01 = RX serial clock div by 2 selected                      */
/*     x10 = RX serial clock div by 4 selected                      */
/*     x11 = RX serial clock div by 8 selected.                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL));
      tmp_srx0_rx_clkdiv_ctrl.bf.SRX_DDIV_SEL = srx_ddiv_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL), tmp_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CLKDIV CTRL RDIV T41             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_clkdiv_ctrl_rdiv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                   cs_uint16 srx_rdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX RDIV SEL                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Select the serial clock divider to receive PFD for comparison    */
/* to the clock reference.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_rdiv_sel]                                                 */
/*     TEN_HSIF_CFP_DIV_BY_16_REF = 0,                              */
/*     TEN_HSIF_CFP_DIV_BY_32_REF = 1,                              */
/*     TEN_HSIF_CFP_DIV_BY_64_REF = 2,                              */
/*     TEN_HSIF_CFP_DIV_BY_66_REF = 3,                              */
/*     TEN_HSIF_CFP_DIV_BY_40_REF = 4,                              */
/*     TEN_HSIF_CFP_DIV_BY_80_REF = 5.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_srx0_rx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL));
      tmp_srx0_rx_clkdiv_ctrl.bf.SRX_RDIV_SEL = srx_rdiv_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKDIV_CTRL), tmp_srx0_rx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CLKOUT CTRL CLKINVEN T41         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_clkout_ctrl_clkinven_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                       cs_uint16 srx_clkinven)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX CLKINVEN                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive clock outputs.                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_clkinven]  Invert SRX_CLK clock to digital core:          */
/*     0 = non inverted                                             */
/*     1 = inverted.                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_t tmp_srx0_rx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKOUT_CTRL));
      tmp_srx0_rx_clkout_ctrl.bf.SRX_CLKINVEN = srx_clkinven;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKOUT_CTRL), tmp_srx0_rx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CLKOUT CTRL TCLKIEN T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_clkout_ctrl_tclkien_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                      cs_uint16 srx_tclkien)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX TCLKIEN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Test clock input enable.                                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_tclkien]                                                  */
/*     Test clock input enable:                                     */
/*     00 = LC VCO                                                  */
/*     01 = TEST CLOCK.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_t tmp_srx0_rx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKOUT_CTRL));
      tmp_srx0_rx_clkout_ctrl.bf.SRX_TCLKIEN = srx_tclkien;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKOUT_CTRL), tmp_srx0_rx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CLKOUT CTRL TCLKO T41            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_clkout_ctrl_tclko_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 srx_tclko_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX TCLKO SEL                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects signal to be sent on SRX_CLKP/N output.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_tclko_sel]                                                */
/*     Selects signal to be sent on SRX_CLKP/N output:              */
/*     0 = div16                                                    */
/*     1 = div32                                                    */
/*     2 = div64                                                    */
/*     3 = div66                                                    */
/*     4 = div40                                                    */
/*     5 = div80                                                    */
/*     6 = SRX_PILOT                                                */
/*     11= xxxx Turned-off.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_t tmp_srx0_rx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKOUT_CTRL));
      tmp_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL = srx_tclko_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CLKOUT_CTRL), tmp_srx0_rx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX CPA CPCUR T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_cpa_cpcur_t41(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 srx_cpcur1, 
                                            cs_uint16 srx_cpcur0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX CPCUR1                                        */
/*              o SRX CPCUR0                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Charge pump current setting.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_cpcur1]                                                   */
/*     This setting is used when the SRX_FREQ msb is 1              */
/*                                                                  */
/*   [srx_cpcur0]                                                   */
/*     This setting is used when the SRX_FREQ msb is 0.             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_CPA_t tmp_srx0_rx_cpa;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_cpa.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CPA));
      tmp_srx0_rx_cpa.bf.SRX_CPCUR1 = srx_cpcur1;
      tmp_srx0_rx_cpa.bf.SRX_CPCUR0 = srx_cpcur0;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_CPA), tmp_srx0_rx_cpa.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX MISC HI GAIN T41                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_misc_hi_gain_t41(cs_uint16 module_id, cs_uint8 slice, 
                                               cs_uint16 srx_hi_gain)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX HI GAIN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Disable equalizer and for limiting amp mode.                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_hi_gain]                                                  */
/*     0 = equalizer enable                                         */
/*     1 = equalizer disabled.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_MISC_t tmp_srx0_rx_misc;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_misc.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_MISC));
      tmp_srx0_rx_misc.bf.SRX_HI_GAIN = srx_hi_gain;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_MISC), tmp_srx0_rx_misc.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SRX0 RX MISC SRX EQADJ T41               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_srx0_rx_misc_srx_eqadj_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 srx_eqadj)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SRX EQADJ                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets equalizer zero adjustment.                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [srx_eqadj]                                                    */
/*     Equalizer zero adjustment:                                   */
/*     0000 = max equalization                                      */
/*     1111 = min equalization                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_SRX0_RX_MISC_t tmp_srx0_rx_misc;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_srx0_rx_misc.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_MISC));
      tmp_srx0_rx_misc.bf.SRX_EQADJ = srx_eqadj;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, SRX0_RX_MISC), tmp_srx0_rx_misc.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RXVCO0 THRES0 T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_rxvco0_thres0_t41(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint16 freq_thres_sign0, 
                                        cs_uint16 freq_thres0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o FREQ THRES SIGN0                                  */
/*              o FREQ THRES0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets thresholds used by the VCO Coarse Tuning Algorithm to       */
/* decide if the VCO 0 is in the correct frequency range.           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [freq_thres_sign0]                                             */
/*     Positive(0) or Negative(1) sign associated with FREQ_THRES0  */
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
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXVCO0_THRES0_t tmp_rxvco0_thres0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxvco0_thres0.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_THRES0));
      tmp_rxvco0_thres0.bf.FREQ_THRES_SIGN0 = freq_thres_sign0;
      tmp_rxvco0_thres0.bf.FREQ_THRES0 = freq_thres0;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_THRES0), tmp_rxvco0_thres0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RXVCO0 THRES1 T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_rxvco0_thres1_t41(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint16 freq_thres_sign1, 
                                        cs_uint16 freq_thres1)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o FREQ THRES SIGN1                                  */
/*              o FREQ THRES1                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets thresholds used by the VCO Coarse Tuning Algorithm to       */
/* decide if the VCO 1 is in the correct frequency range.           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [freq_thres_sign1]                                             */
/*     Positive(0) or Negative(1) sign associated with FREQ_THRES1  */
/*                                                                  */
/*   [freq_thres1]                                                  */
/*     Provides some flexibility for the Coarse Tuning Algorithm    */
/*     when deciding if the VCO's operating frequency range is      */
/*     such that the PLL can capture the receive data frequency.    */
/*     Larger values of FREQ_THRES0 provide more slack in making    */
/*     this decision.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXVCO0_THRES1_t tmp_rxvco0_thres1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxvco0_thres1.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_THRES1));
      tmp_rxvco0_thres1.bf.FREQ_THRES_SIGN1 = freq_thres_sign1;
      tmp_rxvco0_thres1.bf.FREQ_THRES1 = freq_thres1;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_THRES1), tmp_rxvco0_thres1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RXVCO0 VCOMAX T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_rxvco0_vcomax_t41(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint16 vcomax)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o VCOMAX                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the length of time the Tuning Algorithm remains at a    */
/* particular frequency step.                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [vcomax]                                                       */
/*     The value in this register, times the period of the vco      */
/*     clock, equals the length of time the Algorithm spends        */
/*     evaluating a particular frequency step. Generally speaking,  */
/*     the longer the evaluation period, the greater the resolution */
/*     of the algorithm.                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXVCO0_VCOMAX_t tmp_rxvco0_vcomax;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxvco0_vcomax.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_VCOMAX));
      tmp_rxvco0_vcomax.bf.VCOMAX = vcomax;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_VCOMAX), tmp_rxvco0_vcomax.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RXVCO0 CONTROL INIT T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_rxvco0_control_init_t41(cs_uint16 module_id, cs_uint8 slice,
                                              cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls when the VCO Coarse Tuning Algorithm is re-initialized  */
/* and starts searching for the correct frequency range again.      */
/* Toggles SDS_COMMON_RXVCO0_CONTROL_INIT bit to initialize coarse  */
/* tuning.                                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act] parameter is specified as:                               */
/*   Reset option specified as CS_RESET_DEASSERT,                   */
/*   CS_RESET_ASSERT or CS_RESET_TOGGLE.                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset bit(s) for 20 milliseconds and then de-assert.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXVCO0_CONTROL_t tmp_rxvco0_control;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_cfp32x1_rxvco0_control_init_t41";  

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3 or 0xFF.", func);
    return (CS_ERROR);
  }
 
  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, "%s() act = 0x%04X\n", func, act);
      return (CS_ERROR);
  }
  
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s() %s TEN_SLICE_ALL, %s\n", func, ten_module_strings[module_id&1], ten_reset_act_strings[act]);
  } else {  
    CS_PRINT("%s() %s, %s, %s\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice], ten_reset_act_strings[act]);
  }  
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxvco0_control.wrd = 0;
      tmp_rxvco0_control.bf.INIT = 1;
      ten_reset_action(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_CONTROL), 
                       tmp_rxvco0_control.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 RXVCO0 SET SHORT OVERRIDE CONTROL T41*/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_cfp32x1_rxvco0_set_short_ovride_t41(cs_uint16 module_id,
                                                  cs_uint8 slice,  
                                                  cs_uint16 short_ovride)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o SHORT OVRIDE                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Override control of the Coarse Tuner's "Filter Short" output,*/
/* SHORT_FILTPN. Either use SHORT_FILTPN directly from the      */
/* Coarse Tuner or else use the value contained in this         */
/* register.                                                    */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* The [short_ovride] parameter is specified as:                */
/*   2'b0x USE_CT_RESULT Use the SHORT_FILTPN output of the     */
/*         coarse tuner                                         */
/*   2'b10 FORCE_OFF Force SHORT_FILTPN output off              */
/*   2'b11 FORCE_ON Force                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXVCO0_CONTROL_t tmp_rxvco0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxvco0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_CONTROL));
      tmp_rxvco0_control.bf.SHORT_OVRIDE = short_ovride;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXVCO0_CONTROL), tmp_rxvco0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RXVCO0 STATUS T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cfp32x1_rxvco0_status_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : FREQ Value                                          */
/* DESCRIPTION:                                                     */
/* Returns the frequency range selected by the Coarse Tuning        */
/* Algorithm.                                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3).                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_CFP32X1_SDS_COMMON_RXVCO0_STATUS_t tmp_rxvco0_status;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_rxvco0_status.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, RXVCO0_STATUS));
  return (tmp_rxvco0_status.bf.FREQ);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 GET VC0 TUNE INTSTATUS T41           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_cfp32x1_rxvco0_intstatus_t41(cs_uint16 module_id,
                                           cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Value                                           */
/* DESCRIPTION:                                                 */
/* Returns the Current state of the Coarse Tuning Algorithm's   */
/* "SHORT_FILTPN" output signal.                                */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3.                                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_CFP32X1_SDS_COMMON_RXVCO0_INTSTATUS_t tmp_rxvco0_intstatus;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  
  tmp_rxvco0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, RXVCO0_INTSTATUS));
  return (tmp_rxvco0_intstatus.bf.SHORT_FILTPNs);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 RXLOCKD0 SET STABLE PERIOD T41       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_cfp32x1_rxlockd0_set_stable_period_t41(cs_uint16 module_id,
                                                     cs_uint8 slice, 
                                                     cs_uint16 stable_period)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o STABLE PERIOD                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Controls the Lock Detect interrupt filter.                   */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* The [stable_period] parameter is specified as:               */
/*   0 - FF hex                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXLOCKD0_FILTER_t tmp_rxlockd0_filter;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_filter.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_FILTER));
      tmp_rxlockd0_filter.bf.STABLE_PERIOD = stable_period;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_FILTER), tmp_rxlockd0_filter.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SET RXLOCKD0 DATA LOCK T41               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_set_rxlockd0_data_lock_t41(cs_uint16 module_id,
                                                 cs_uint8 slice, 
                                                 cs_uint16 data_lock)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DATA LOCK                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Clock and Data Recovery (CDR) Lock Detector Control Register.    */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [data_lock] parameter is specified as:                       */
/*   When this bit is set, use the "receive data detected" signal   */
/*   when making the lock decision. Only pertinent in ONU mode; in  */
/*   OLT mode this control bit has no effect.                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_rxlockd0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_CONTROL));
      tmp_rxlockd0_control.bf.DATA_LOCK = data_lock;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_CONTROL), tmp_rxlockd0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SET RXLOCKD0 PD MODE T41                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_set_rxlockd0_pd_mode_t41(cs_uint16 module_id,
                                               cs_uint8 slice, 
                                               cs_uint16 pd_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PD MODE                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets PD Mode.                                                    */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [pd_mode] parameter is specified as:                         */
/*   PD_MODE = 1, When FORCE_LOCK=1, the clock recovered from the   */
/*   line is the source of the receive clock.                       */
/*   PD_MODE = 0, When FORCE_LOCK=1, the local pilot is the receive */
/*   clock source. This can be used when Rx Data is out of range    */
/*   for clock recovery.                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_rxlockd0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_CONTROL));
      tmp_rxlockd0_control.bf.PD_MODE = pd_mode;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_CONTROL), tmp_rxlockd0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 SET RXLOCKD0 FORCE LOCK T41              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_set_rxlockd0_force_lock_t41(cs_uint16 module_id,
                                                  cs_uint8 slice, 
                                                  cs_uint16 force_lock)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o FORCE LOCK                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Clock and Data Recovery (CDR) Lock Detector Control Register.    */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [force_lock] parameter is specified as:                      */
/*   0..1, Force the lock state to the value "PD_MODE" when         */
/*   FORCE_LOCK is asserted.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_rxlockd0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_CONTROL));
      tmp_rxlockd0_control.bf.FORCE_LOCK = force_lock;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_CONTROL), tmp_rxlockd0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 RXLOCKD0 CHECK LOCK T41              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_cfp32x1_rxlockd0_lock_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Value                                           */
/* DESCRIPTION:                                                 */
/* Indicates status of LOCKs.                                   */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_uint16 ret_val = TRUE;
  TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_rxlockd0_intstatus;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    /* Bugzilla # , fix TEN_SLICE_ALL case */
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTSTATUS));
      ret_val &= (tmp_rxlockd0_intstatus.bf.LOCKs == 1);
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 RXLOCKD0 CHECK FILT LOCK T41         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_cfp32x1_rxlockd0_filt_lock_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Value                                           */
/* DESCRIPTION:                                                 */
/* Indicates status of FILT_LOCKs.                              */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_uint16 ret_val = TRUE;
  TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_rxlockd0_intstatus;
  cs_char8 *func = "ten_cfp32x1_rxlockd0_filt_lock_t41";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);

  if (slice < TEN_MAX_SLICES) {
    CS_PRINT("%s()  %s, %s\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice]);
  }
  else if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s()  %s SLICE_ALL\n", func, ten_module_strings[module_id&1]);
  } else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3 or 0xFF.", func, slice);
    return (0);
  }

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    /* Bugzilla # , fix TEN_SLICE_ALL case */
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTSTATUS));
      ret_val &= (tmp_rxlockd0_intstatus.bf.FILT_LOCKs == 1);
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 RXLOCKD0 CHECK DATA DETS T41         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_cfp32x1_rxlockd0_data_dets_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Value                                           */
/* DESCRIPTION:                                                 */
/* Indicates status of DATA_DETs.                               */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_uint16 ret_val = TRUE;
  TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_rxlockd0_intstatus;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    /* Bugzilla # , fix TEN_SLICE_ALL case */
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTSTATUS));
      ret_val &= (tmp_rxlockd0_intstatus.bf.DATA_DETs == 1);
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 RXLOCKD0 CHECK SHORT FILT PNS T41    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_cfp32x1_rxlockd0_short_filt_pns_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Value                                           */
/* DESCRIPTION:                                                 */
/* Indicates status of SHORT_FILT_PNs.                          */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_uint16 ret_val = TRUE;
  TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_rxlockd0_intstatus;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    /* Bugzilla # , fix TEN_SLICE_ALL case */
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTSTATUS));
      ret_val &= (tmp_rxlockd0_intstatus.bf.SHORT_FILTPNs == 1);
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 RXLOCKD0 CHECK BAD VCO CLKS T41      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_cfp32x1_rxlockd0_bad_vco_clks_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Value                                           */
/* DESCRIPTION:                                                 */
/* Indicates status of BAD_VCO_CLKs.                            */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_uint16 ret_val = TRUE;
  TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTSTATUS_t tmp_rxlockd0_intstatus;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    /* Bugzilla # , fix TEN_SLICE_ALL case */
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxlockd0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_INTSTATUS));
      ret_val &= (tmp_rxlockd0_intstatus.bf.BAD_VCO_CLKs == 1);
    }
  }
  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RXVCOLEVEL0 OSTATUS T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cfp32x1_rxvcolevel0_ostatus_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* Returns the value of the 10 bit integrator.                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3).                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_CFP32X1_SDS_COMMON_RXVCOLEVEL0_OSTATUS_t tmp_rxvcolevel0_ostatus;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_rxvcolevel0_ostatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, RXVCOLEVEL0_OSTATUS));
  return (tmp_rxvcolevel0_ostatus.bf.VCO_LEVEL_STATUS);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RXVCOLEVEL0 CSTATUS T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cfp32x1_rxvcolevel0_cstatus_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* Return the status associated with VCO_COMP_OUT input from        */
/* the serdes.                                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3).                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_CFP32X1_SDS_COMMON_RXVCOLEVEL0_CSTATUS_t tmp_rxvcolevel0_cstatus;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_rxvcolevel0_cstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, RXVCOLEVEL0_CSTATUS));
  return (tmp_rxvcolevel0_cstatus.bf.VCO_COMP_OUT_STATUS);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STX0 TX OUTPUT CTRL DRV LOWER CM T41     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stx0_tx_output_ctrl_drv_lower_cm_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                           cs_uint16 stx_drv_lower_cm)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STX DRV LOWER CM                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure SERDES Analog Front End Adjustments.                   */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)        */
/*                                                                  */
/* [stx_drv_lower_cm]  Turns on current source to STX_DOUTP/N       */
/*   which increases the bias voltage thereby improving headroom.   */
/*   This is used primarily when STX_DOUTP/N is AC coupled.         */
/*   1111 = high bias,                                              */
/*   0000 = off.                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_t tmp_stx0_tx_output_ctrla;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stx0_tx_output_ctrla.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLA));
      tmp_stx0_tx_output_ctrla.bf.STX_DRV_LOWER_CM = stx_drv_lower_cm;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLA), tmp_stx0_tx_output_ctrla.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STX0 TX OUTPUT CTRL T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stx0_tx_output_ctrl_level_t41(cs_uint16 module_id, cs_uint8 slice,
                                                    cs_uint16 stx_level)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STX LEVEL                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure SERDES Analog Front End Adjustments.                   */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)        */
/*                                                                  */
/* [stx_level]  Output driver cursor output level adjust, binary    */
/*   weighted, 0.5mA LSB.                                           */
/*   111111 = 31mA                                                  */
/*   000000 = off.                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_t tmp_stx0_tx_output_ctrla;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stx0_tx_output_ctrla.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLA));
      tmp_stx0_tx_output_ctrla.bf.STX_LEVEL = stx_level;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLA), tmp_stx0_tx_output_ctrla.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STX0 TX OUTPUT CTRL PRE PEAK T41         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stx0_tx_output_ctrl_pre_peak_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                       cs_uint16 stx_pre_peak)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STX PRE PEAK                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure SERDES Analog Front End Adjustments.                   */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)        */
/*                                                                  */
/* [stx_pre_peak]  Output driver pre-cursor level adjust, binary    */
/*   weighted, 0.25mA LSB.                                          */
/*   11111 = 7.75mA                                                 */
/*   00000 = off.                                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_t tmp_stx0_tx_output_ctrlb;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stx0_tx_output_ctrlb.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLB));
      tmp_stx0_tx_output_ctrlb.bf.STX_PRE_PEAK = stx_pre_peak;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLB), tmp_stx0_tx_output_ctrlb.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STX0 TX OUTPUT CTRL POST PEAK T41        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stx0_tx_output_ctrl_post_peak_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                        cs_uint16 stx_post_peak)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STX POST PEAK                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure SERDES Analog Front End Adjustments.                   */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)        */
/*                                                                  */
/* [stx_post_peak]  Output driver post-cursor level adjust, binary  */
/*   weighted, 0.25mA LSB.                                          */
/*   111111 = 15.75mA                                               */
/*   00000 = off.                                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STX0_TX_OUTPUT_CTRLB_t tmp_stx0_tx_output_ctrlb;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stx0_tx_output_ctrlb.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLB));
      tmp_stx0_tx_output_ctrlb.bf.STX_POST_PEAK = stx_post_peak;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STX0_TX_OUTPUT_CTRLB), tmp_stx0_tx_output_ctrlb.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX LOOPTIME SELECT T41             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_lptime_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 stxp_lptime_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP LPTIME SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_lptime_sel]  Enable Loop time mode in which one RX       */
/*     channel recovered clock is supplied as the reference         */
/*     for transmit.                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_LPTIME_SEL = stxp_lptime_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX LOOPTIME SELECT MSB T41         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_lptime_sel_msb_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                  cs_uint16 stxp_lptime_sel_msb)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP LPTIME SEL MSB                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_lptime_sel_msb]  MSB for STXP_LPTIME_SEL.                */
/*     See description for STXP_LPTIME_SEL.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_LPTIME_SEL_MSB = stxp_lptime_sel_msb;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CONFIG PILOT SEL T41            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_config_pilot_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_pilot_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP PILOT SEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_pilot_sel]  Provide pilot tone clock to the receiver     */
/*     and the STXP_REF_LD pin                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_PILOT_SEL = stxp_pilot_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CONFIG BUSWIDTH T41             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_config_buswidth_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                   cs_uint16 stxp_buswidth)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP BUSWIDTH                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_buswidth]                                                */
/*     Set MUX bus width:                                           */
/*     x0 = enable 32bit mux mode                                   */
/*     x1 = enable 40bit mux mode.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_BUSWIDTH = stxp_buswidth;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CONFIG XFI EN T41               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_config_xfi_en_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 stxp_xfi_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP XFI EN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_xfi_en]                                                  */
/*     Mode selection. Used only in the 10G capable MR serdes:      */
/*     0 = operates as MR serdes (sfi41/sfi42/xaui/sfi51)           */
/*     1 = operates as a 10G serdes (only RX lane 14 and TX lane 12)*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_XFI_EN = stxp_xfi_en;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CONFIG LPBKEN T41               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_config_lpbken_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 stxp_lpbken)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP LPBKEN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets various control bits for TX.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_lpbken]  Power drivers to enable serial loopback.        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
      tmp_stxp0_tx_config.bf.STXP_LPBKEN = stxp_lpbken;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX PD T41                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_pd_41(cs_uint16 module_id,
                                     cs_uint8 slice, 
                                     cs_uint16 stxp_pd)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP PD                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls power down bits for TX PLL.                             */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_pd]  Power down the entire transmit section              */
/*     0 = powered                                                  */
/*     1 = powered down.                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_PWRDN_t tmp_stxp0_tx_pwrdn;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_pwrdn.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_PWRDN));
      tmp_stxp0_tx_pwrdn.bf.STXP_PD = stxp_pd;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_PWRDN), tmp_stxp0_tx_pwrdn.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX PD LANE T41                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_pd_lane_t41(cs_uint16 module_id,
                                           cs_uint8 slice, 
                                           cs_uint16 stxp_pd_lane)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP PD LANE                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls power down bits for TX PLL.                             */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_pd_lane]  Power down the entire transmit section         */
/*     0 = powered                                                  */
/*     1 = powered down.                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_PWRDN_t tmp_stxp0_tx_pwrdn;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_pwrdn.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_PWRDN));
      tmp_stxp0_tx_pwrdn.bf.STXP_PD_LANE = stxp_pd_lane;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_PWRDN), tmp_stxp0_tx_pwrdn.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CLKDIV CTRL FASTDIV T41         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_clkdiv_ctrl_fastdiv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                       cs_uint16 stxp_fastdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP FASTDIV SEL                                  */
/*              o STXP RDIV SEL                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls all of the TX clock dividers.                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_fastdiv_sel]  Select the serial clock divider to         */
/*     transmit PFD for comparison to the clock reference.          */
/*     TEN_HSIF_CFP_DIV_BY_16_REF = 0,                              */
/*     TEN_HSIF_CFP_DIV_BY_32_REF = 1,                              */
/*     TEN_HSIF_CFP_DIV_BY_64_REF = 2,                              */
/*     TEN_HSIF_CFP_DIV_BY_66_REF = 3,                              */
/*     TEN_HSIF_CFP_DIV_BY_40_REF = 4,                              */
/*     TEN_HSIF_CFP_DIV_BY_80_REF = 5.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_FASTDIV_SEL = stxp_fastdiv_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CLKDIV CTRL CTRDIV T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_clkdiv_ctrl_ctrdiv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                      cs_uint16 stxp_ctrdiv_sel) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP CTRDIV SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the TX clock dividers.                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_ctrdiv_sel]                                              */
/*     Select to divide the clock reference before reaching the     */
/*     digital core for use in coarse tuning:                       */
/*     0 = div1                                                     */
/*     1 = div2                                                     */
/*     2 = div4                                                     */
/*     3 = div8.                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_cfp32x1_stxp0_tx_clkdiv_ctrl_ctrdiv_t41";  

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3 or 0xFF.", func);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, stxp_ctrdiv_sel=%d\n", func, ten_module_strings[module_id&1], stxp_ctrdiv_sel);
           


  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_CTRDIV_SEL = stxp_ctrdiv_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CLKDIV CTRL CTVDIV T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_clkdiv_ctrl_ctvdiv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                      cs_uint16 stxp_ctvdiv_sel) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP CTVDIV SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the TX clock dividers.                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_ctvdiv_sel]                                              */
/*     Select to divide CLK_LD before reaching the digital core     */
/*     for use in coarse tuning:                                    */
/*     0 = div1                                                     */
/*     1 = div2                                                     */
/*     2 = div4                                                     */
/*     3 = div8.                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_CTVDIV_SEL = stxp_ctvdiv_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CLKDIV CTRL DDIV T41            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_clkdiv_ctrl_ddiv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_ddiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP DDIV                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls all of the TX clock dividers.                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_ddiv_sel]  Select clock rate for transmit data path      */
/*     Select clock rate for receiver data path                     */
/*    (full-rate=9.95328GHz to 11.3GHz)                             */
/*    x00 = full-rate mode                                          */
/*    x01 = TX serial clock div by 2 selected                       */
/*    x10 = TX serial clock div by 4 selected                       */
/*    x11 = TX serial clock div by 8 selected.                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_DDIV_SEL = stxp_ddiv_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CLKDIV CTRL RDIV T41            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_clkdiv_ctrl_rdiv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                    cs_uint16 stxp_rdiv_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP RDIV SEL                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls all of the TX clock dividers.                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_rdiv_sel]                                                */
/*     TEN_HSIF_CFP_DIV_BY_16_REF = 0,                              */
/*     TEN_HSIF_CFP_DIV_BY_32_REF = 1,                              */
/*     TEN_HSIF_CFP_DIV_BY_64_REF = 2,                              */
/*     TEN_HSIF_CFP_DIV_BY_66_REF = 3,                              */
/*     TEN_HSIF_CFP_DIV_BY_40_REF = 4,                              */
/*     TEN_HSIF_CFP_DIV_BY_80_REF = 5.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL = stxp_rdiv_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CLKOUT CTRL TCLKIEN T41         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_clkout_ctrl_tclkien_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                       cs_uint16 stxp_tclkien)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP TCLKIEN                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit clock outputs.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_tclkien]                                                 */
/*     Test clock input enable:                                     */
/*     00 = LC VCO                                                  */
/*     01 = TEST CLOCK.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL));
      tmp_stxp0_tx_clkout_ctrl.bf.STXP_TCLKIEN = stxp_tclkien;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL), tmp_stxp0_tx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CLKOUT CTRL CLKOUTEN T41        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_clkout_ctrl_clkouten_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                        cs_uint16 stxp_clkouten)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP CLKOUTEN                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit clock outputs.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_clkouten]                                                */
/*     Test clock output enable:                                    */
/*     0 = test clock disabled                                      */
/*     1 = test clock enabled.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL));
      tmp_stxp0_tx_clkout_ctrl.bf.STXP_CLKOUTEN = stxp_clkouten;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL), tmp_stxp0_tx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CLKOUT CTRL TCLK0 SEL T41       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_clkout_ctrl_tclko_sel_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                         cs_uint16 stxp_tclko_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP TCLKO SEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit clock outputs.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_tclko_sel]                                               */
/*     Select clock to be sent on STXP_TCLKOP/N:                    */
/*     000000 = div16                                               */
/*     000001 = div32                                               */
/*     000010 = div64                                               */
/*     000011 = div66                                               */
/*     000100 = div40                                               */
/*     000101 = div80                                               */
/*     000110 = STXP_PILOT                                          */
/*     01xxxx = reserved                                            */
/*     1001xx = Data Path Divider Output.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL));
      tmp_stxp0_tx_clkout_ctrl.bf.STXP_TCLKO_SEL = stxp_tclko_sel;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKOUT_CTRL), tmp_stxp0_tx_clkout_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX LOOP FILTER T41                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_loop_filter_t41(cs_uint16 module_id, cs_uint8 slice, 
                                               cs_uint16 stxp_filtr)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP FILTR                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit loop filter.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_filtr]  Programmable PLL loop filter resistance.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_LOOP_FILTER_t tmp_stxp0_tx_loop_filter;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_loop_filter.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_LOOP_FILTER));
      tmp_stxp0_tx_loop_filter.bf.STXP_FILTR = stxp_filtr;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_LOOP_FILTER), tmp_stxp0_tx_loop_filter.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX CP CUR T41                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_cpcur_t41(cs_uint16 module_id, cs_uint8 slice, 
                                         cs_uint16 stxp_cpcur1, 
                                         cs_uint16 stxp_cpcur0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP CPCUR1                                       */
/*              o STXP CPCUR0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit PLL charge pump.                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_cpcur1]  Charge pump current setting. This setting is    */
/*     used when the STXP_FREQ msb is 1                             */
/*                                                                  */
/*   [stxp_cpcur1]  Charge pump current setting. This setting is    */
/*     used when the STXP_FREQ msb is 0.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CP_t tmp_stxp0_tx_cp;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_cp.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CP));
      tmp_stxp0_tx_cp.bf.STXP_CPCUR1 = stxp_cpcur1;
      tmp_stxp0_tx_cp.bf.STXP_CPCUR0 = stxp_cpcur0;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CP), tmp_stxp0_tx_cp.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 STXP0 TX SPARE T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_stxp0_tx_spare_ref_sel_mode_t41(cs_uint16 module_id, cs_uint8 slice, 
                                         cs_uint16 stxp_ref_sel_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STXP REF SEL MODE                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets spare control bits for the TX PLL Analog front end.         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stxp_ref_sel_mode]                                            */
/*     Reference and pilot selection mode. This control signal      */
/*     only has an impact when STXP_XFI_EN = 1, i.e. reference      */
/*     and pilot selection is always MR SERDES when STXP_XFI_EN = 0 */
/*     0 = XFI SERDES mode                                          */
/*     1 = MR SERDES mode.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_SPARE_t tmp_stxp0_tx_spare;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_stxp0_tx_spare.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SPARE));
      tmp_stxp0_tx_spare.bf.STXP_REF_SEL_MODE = stxp_ref_sel_mode;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SPARE), tmp_stxp0_tx_spare.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TXVCO0 THRES0 T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_txvco0_thres0_t41(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint16 freq_thres_sign0, 
                                        cs_uint16 freq_thres0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o FREQ THRES SIGN0                                  */
/*              o FREQ THRES0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets thresholds used by the VCO Coarse Tuning Algorithm to       */
/* decide if the VCO 0 is in the correct frequency range.           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [freq_thres_sign0]                                             */
/*     Positive(0) or Negative(1) sign associated with FREQ_THRES0  */
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
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TXVCO0_THRES0_t tmp_txvco0_thres0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txvco0_thres0.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_THRES0));
      tmp_txvco0_thres0.bf.FREQ_THRES_SIGN0 = freq_thres_sign0;
      tmp_txvco0_thres0.bf.FREQ_THRES0 = freq_thres0;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_THRES0), tmp_txvco0_thres0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TXVCO0 THRES1 T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_txvco0_thres1_t41(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint16 freq_thres_sign1, 
                                        cs_uint16 freq_thres1)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o FREQ THRES SIGN1                                  */
/*              o FREQ THRES1                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets thresholds used by the VCO Coarse Tuning Algorithm to       */
/* decide if the VCO 1 is in the correct frequency range.           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [freq_thres_sign0]                                             */
/*     Positive(0) or Negative(1) sign associated with FREQ_THRES1  */
/*                                                                  */
/*   [freq_thres1]                                                  */
/*     Provides some flexibility for the Coarse Tuning Algorithm    */
/*     when deciding if the VCO's operating frequency range is      */
/*     such that the PLL can capture the receive data frequency.    */
/*     Larger values of FREQ_THRES0 provide more slack in making    */
/*     this decision.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TXVCO0_THRES1_t tmp_txvco0_thres1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txvco0_thres1.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_THRES1));
      tmp_txvco0_thres1.bf.FREQ_THRES_SIGN1 = freq_thres_sign1;
      tmp_txvco0_thres1.bf.FREQ_THRES1 = freq_thres1;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_THRES1), tmp_txvco0_thres1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TXVCO0 VCOMAX T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_txvco0_vcomax_t41(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint16 vcomax)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o VCOMAX                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the length of time the Tuning Algorithm remains at a    */
/* particular frequency step.                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [vcomax]                                                       */
/*     The value in this register, times the period of the vco      */
/*     clock, equals the length of time the Algorithm spends        */
/*     evaluating a particular frequency step. Generally speaking,  */
/*     the longer the evaluation period, the greater the resolution */
/*     of the algorithm.                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TXVCO0_VCOMAX_t tmp_txvco0_vcomax;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txvco0_vcomax.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_VCOMAX));
      tmp_txvco0_vcomax.bf.VCOMAX = vcomax;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_VCOMAX), tmp_txvco0_vcomax.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TXVCO0 CONTROL INIT T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_txvco0_control_init_t41(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls when the VCO Coarse Tuning Algorithm is re-initialized  */
/* and starts searching for the correct frequency range again.      */
/* Toggles SDS_COMMON_TXVCO0_CONTROL_INIT bit to initialize coarse  */
/* tuning.                                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act] parameter is specified as:                               */
/*   Reset option specified as CS_RESET_DEASSERT,                   */
/*   CS_RESET_ASSERT or CS_RESET_TOGGLE.                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset bit(s) for 20 milliseconds and then de-assert.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TXVCO0_CONTROL_t tmp_txvco0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }
  
  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": act = 0x%04X\n", act);
      return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txvco0_control.wrd = 0;
      tmp_txvco0_control.bf.INIT = 1;
      ten_reset_action(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_CONTROL),
                       tmp_txvco0_control.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 TXVCO0 SET SHORT OVERRIDE CONTROL T41*/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_cfp32x1_txvco0_set_short_ovride_t41(cs_uint16 module_id,
                                                  cs_uint8 slice,  
                                                  cs_uint16 short_ovride)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o SHORT OVRIDE                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Override control of the Coarse Tuner's "Filter Short" output,*/
/* SHORT_FILTPN. Either use SHORT_FILTPN directly from the      */
/* Coarse Tuner or else use the value contained in this         */
/* register.                                                    */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* The [short_ovride] parameter is specified as:                */
/*   2'b0x USE_CT_RESULT Use the SHORT_FILTPN output of the     */
/*         coarse tuner                                         */
/*   2'b10 FORCE_OFF Force SHORT_FILTPN output off              */
/*   2'b11 FORCE_ON Force                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TXVCO0_CONTROL_t tmp_txvco0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txvco0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_CONTROL));
      tmp_txvco0_control.bf.SHORT_OVRIDE = short_ovride;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCO0_CONTROL), tmp_txvco0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TXVCO0 STATUS T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cfp32x1_txvco0_status_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : FREQ value                                          */
/* DESCRIPTION:                                                     */
/* Returns the frequency range selected by the Coarse Tuning        */
/* Algorithm.                                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), or TEN_SLICE3 (3).                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_CFP32X1_SDS_COMMON_TXVCO0_STATUS_t tmp_txvco0_status;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_txvco0_status.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, TXVCO0_STATUS));
  return (tmp_txvco0_status.bf.FREQ);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TXVCO0 INTSTATUS T41                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cfp32x1_txvco0_intstatus_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* Returns the current state of the Coarse Tuning Algorithm's       */
/* "SHORT_FILTPN" output signal.                                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3).                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_CFP32X1_SDS_COMMON_TXVCO0_INTSTATUS_t tmp_txvco0_intstatus;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_txvco0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, TXVCO0_INTSTATUS));
  return (tmp_txvco0_intstatus.bf.SHORT_FILTPNs);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 TXLOCKD0 SET STABLE PERIOD T41       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_cfp32x1_txlockd0_set_stable_period_t41(cs_uint16 module_id,
                                                     cs_uint8 slice, 
                                                     cs_uint16 stable_period)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o STABLE PERIOD                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Controls the Lock Detect interrupt filter.                   */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/* The [stable_period] parameter is specified as:               */
/*   0x0 - 0xFF.                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TXLOCKD0_FILTER_t tmp_txlockd0_filter;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txlockd0_filter.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_FILTER));
      tmp_txlockd0_filter.bf.STABLE_PERIOD = stable_period;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_FILTER), tmp_txlockd0_filter.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 TXLOCKD0 CHECK LOCK T41              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_cfp32x1_txlockd0_lock_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Indicates if the SerDes is locked by checking LOCKs.         */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF). */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_uint16 ret_val = 1;
  TEN_CFP32X1_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_txlockd0_intstatus;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    /* Bugzilla # , fix TEN_SLICE_ALL case */
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTSTATUS));
      ret_val &= (tmp_txlockd0_intstatus.bf.LOCKs == 1);
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 TXLOCKD0 CHECK FILT LOCK             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_cfp32x1_txlockd0_filt_lock_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Indicates status of FILT_LOCKs.                              */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF). */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_uint16 ret_val = 1;
  TEN_CFP32X1_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_txlockd0_intstatus;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    /* Bugzilla # , fix TEN_SLICE_ALL case */
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTSTATUS));
      ret_val &= (tmp_txlockd0_intstatus.bf.FILT_LOCKs == 1);
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 TXLOCKD0 DATA DETS T41               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_cfp32x1_txlockd0_data_dets_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Current state of the "receive data detected" signal in       */
/* normal operation. (When tx to rx loopback is activated in    */
/* the digital core, this signal is forced to "1").             */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF). */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_uint16 ret_val = 1;
  TEN_CFP32X1_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_txlockd0_intstatus;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    /* Bugzilla # , fix TEN_SLICE_ALL case */
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTSTATUS));
      ret_val &= (tmp_txlockd0_intstatus.bf.DATA_DETs == 1);
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 TXLOCKD0 BAD_VCO_CLKS T41            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_cfp32x1_txlockd0_bad_vco_clks_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Indicates current state of the BAD_VCO_CLK interrupt.        */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF). */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_uint16 ret_val = 1;
  TEN_CFP32X1_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_txlockd0_intstatus;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    /* Bugzilla # , fix TEN_SLICE_ALL case */
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXLOCKD0_INTSTATUS));
      ret_val &= (tmp_txlockd0_intstatus.bf.BAD_VCO_CLKs == 1);
    }
  }
  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TXVCOLEVEL0 OSTATUS T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_txvcolevel0_ostatus_t41(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 vco_level_status)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o VCO LEVEL STATUS                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets VCO Level status register.                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [vco_level_status]  value of the 10 bit integrator.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TXVCOLEVEL0_OSTATUS_t tmp_txvcolevel0_ostatus;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txvcolevel0_ostatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCOLEVEL0_OSTATUS));
      tmp_txvcolevel0_ostatus.bf.VCO_LEVEL_STATUS = vco_level_status;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXVCOLEVEL0_OSTATUS), tmp_txvcolevel0_ostatus.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TXVCOLEVEL0 CSTATUS T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cfp32x1_txvcolevel0_cstatus_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* Returns status associated w/ VCO_COMP_OUT input from the serdes. */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3).                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_CFP32X1_SDS_COMMON_TXVCOLEVEL0_CSTATUS_t tmp_txvcolevel0_cstatus;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_txvcolevel0_cstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, TXVCOLEVEL0_CSTATUS));
  return (tmp_txvcolevel0_cstatus.bf.VCO_COMP_OUT_STATUS);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RXELST0 CONTROL USE LOCKDET T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_rxelst0_control_use_lockdet_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                      cs_uint16 use_lockdet)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Use Lockdet                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls whether the lock detector output is used to directly    */
/* resync the elastic store read pointers.                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [use_lockdet]  0 or 1.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXELST0_Control_t tmp_rxelst0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxelst0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXELST0_Control));
      tmp_rxelst0_control.bf.use_lockdet = use_lockdet;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXELST0_Control), tmp_rxelst0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RXELST0 CONTROL RESYNC T41               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_rxelst0_control_resync_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 resync)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Resync                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When set, forces a resync of the elastic store read pointers     */
/* (datapath/loopback).                                             */
/* Bit must be cleared to 0 to resume dataflow.                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [resync]  0 or 1.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RXELST0_Control_t tmp_rxelst0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rxelst0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXELST0_Control));
      tmp_rxelst0_control.bf.resync = resync;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXELST0_Control), tmp_rxelst0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TXELST0 CONTROL USE LOCKDET T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_txelst0_control_use_lockdet_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                      cs_uint16 use_lockdet)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Use Lockdet                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls whether the lock detector output is used to directly    */
/* resync the elastic store read pointers.                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [use_lockdet]  0 or 1.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TXELST0_Control_t tmp_txelst0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txelst0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXELST0_Control));
      tmp_txelst0_control.bf.use_lockdet = use_lockdet;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXELST0_Control), tmp_txelst0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TXELST0 CONTROL RESYNC T41               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_txelst0_control_resync_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 resync)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Resync                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When set, forces a resync of the elastic store read pointers     */
/* (datapath/loopback).                                             */
/* Bit must be cleared to 0 to resume dataflow.                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [resync]   0 or 1.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TXELST0_Control_t tmp_txelst0_control;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_txelst0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXELST0_Control));
      tmp_txelst0_control.bf.resync = resync;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TXELST0_Control), tmp_txelst0_control.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 PRBSGEN CONFIG T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_prbsgen_config_t41(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 prbs_mode, 
                               cs_uint16 invertprbs, 
                               cs_uint16 fixed_pattern, 
                               cs_uint16 prbs_enable)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Prbs Mode                                         */
/*              o InvertPrbs                                        */
/*              o Fixed Pattern                                     */
/*              o Prbs Enable                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the  PRBS Generator.                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [prbs_mode]  Selects PRBS generation polynomial.               */
/*                                                                  */
/*   [invertprbs]  Inverts the transmit PRBS pattern.               */
/*                                                                  */
/*   [fixed_pattern]  When set to 1, Enables transmitting a fixed   */
/*      repeating pattern from the FixedPat register.               */
/*                                                                  */
/*   [prbs_enable]  Enables PRBS generator.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  
  TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Cfg_t tmp_prbsgen0_cfg;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbsgen0_cfg.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Cfg));
      tmp_prbsgen0_cfg.bf.prbs_mode = prbs_mode;
      tmp_prbsgen0_cfg.bf.invertPrbs = invertprbs;
      tmp_prbsgen0_cfg.bf.fixed_pattern = fixed_pattern;
      tmp_prbsgen0_cfg.bf.prbs_enable = prbs_enable;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Cfg), tmp_prbsgen0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 PRBSGEN ENABLE T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_prbsgen_enable_t41(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 prbs_enable)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Prbs Enable                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables the PRBS Generator.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [prbs_enable]  Enables PRBS generator.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Cfg_t tmp_prbsgen0_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbsgen0_cfg.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Cfg));
      tmp_prbsgen0_cfg.bf.prbs_enable = prbs_enable;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Cfg), tmp_prbsgen0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 PRBSGEN CONTROL T41                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_prbsgen_control_t41(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 inserterror, 
                                cs_uint16 insertonebiterror, 
                                cs_uint16 inserterroronce, 
                                cs_uint16 insertonebiterroronce)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o InsertError                                       */
/*              o InsertOneBitError                                 */
/*              o InsertErrorOnce                                   */
/*              o InsertOneBitErrorOnce                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the PRBS Generator.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [inserterror]  Continuously injects word errors into the       */
/*     transmit PRBS pattern until cleared.                         */
/*                                                                  */
/*   [insertonebiterror]  Continuously injects one bit error per    */
/*     word into the transmit PRBS pattern until cleared.           */
/*                                                                  */
/*   [inserterroronce]  Injects only one word error into the        */
/*     transmit PRBS pattern.  The error is injected on the rising  */
/*     edge of this bit.                                            */
/*                                                                  */
/*   [insertonebiterroronce]  Injects only one bit error into the   */
/*     transmit PRBS pattern.  The error is injected on the rising  */
/*     edge of this bit.                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Ctrl_t tmp_prbsgen0_ctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbsgen0_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Ctrl));
      tmp_prbsgen0_ctrl.bf.insertError = inserterror;
      tmp_prbsgen0_ctrl.bf.insertOneBitError = insertonebiterror;
      tmp_prbsgen0_ctrl.bf.insertErrorOnce = inserterroronce;
      tmp_prbsgen0_ctrl.bf.insertOneBitErrorOnce = insertonebiterroronce;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Ctrl), tmp_prbsgen0_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 PRBSGEN SET FIXED0 PATTERN T41           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_prbsgen_set_fixed0_pattern_t41(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 value1,
                                              cs_uint16 value0)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o VALUE1                                            */
/*              o VALUE0                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets pattern to transmit when fixed_pattern is set.              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [value1]  Data pattern to transmit.                            */
/*                                                                  */
/*   [value0]  Data pattern to transmit.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Fixed0_Pattern1_t tmp_prbsgen0_fixed0_pattern1;
  TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Fixed0_Pattern0_t tmp_prbsgen0_fixed0_pattern0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbsgen0_fixed0_pattern1.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed0_Pattern1));
      tmp_prbsgen0_fixed0_pattern1.bf.VALUE1 = value1;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed0_Pattern1), tmp_prbsgen0_fixed0_pattern1.wrd);
      
      tmp_prbsgen0_fixed0_pattern0.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed0_Pattern0));
      tmp_prbsgen0_fixed0_pattern0.bf.VALUE0 = value0;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed0_Pattern0), tmp_prbsgen0_fixed0_pattern0.wrd);
      
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 PRBSGEN FIXED1 PATTERN T41               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_prbsgen_fixed1_pattern_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 value1,
                                                 cs_uint16 value0)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o VALUE1                                            */
/*              o VALUE0                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets pattern to transmit when fixed_pattern is set.              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [value1]  Data pattern to transmit.                            */
/*                                                                  */
/*   [value0]  Data pattern to transmit.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Fixed1_Pattern1_t tmp_prbsgen0_fixed1_pattern1;
  TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Fixed1_Pattern0_t tmp_prbsgen0_fixed1_pattern0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
    
      tmp_prbsgen0_fixed1_pattern1.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed1_Pattern1));
      tmp_prbsgen0_fixed1_pattern1.bf.VALUE1 = value1;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed1_Pattern1), tmp_prbsgen0_fixed1_pattern1.wrd);
      
      tmp_prbsgen0_fixed1_pattern0.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed1_Pattern0));
      tmp_prbsgen0_fixed1_pattern0.bf.VALUE0 = value0;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Fixed1_Pattern0), tmp_prbsgen0_fixed1_pattern0.wrd);
      
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 PRBSGEN SET REPEAT PATTERN T41           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_prbsgen_set_repeat_pattern_t41(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 repeat1, 
                                          cs_uint16 repeat0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Repeat1                                           */
/*              o Repeat0                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the number of times to transmit patterns when fixed_pattern */
/* is selected.                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [repeat1]  Number of times to repeat pattern 1                 */
/*                                                                  */
/*   [repeat0]  Number of times to repeat pattern 0                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_PRBSGEN0_Repeat_Pattern_t tmp_prbsgen0_repeat_pattern;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbsgen0_repeat_pattern.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Repeat_Pattern));
      tmp_prbsgen0_repeat_pattern.bf.repeat1 = repeat1;
      tmp_prbsgen0_repeat_pattern.bf.repeat0 = repeat0;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSGEN0_Repeat_Pattern), tmp_prbsgen0_repeat_pattern.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 PRBSCHK CONFIG T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_prbschk_config_t41(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 prbs_mode, 
                               cs_uint16 invertprbs)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Prbs Mode                                         */
/*              o InvertPrbs                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the PRBS checker.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [prbs_mode]  Selects PRBS generation polynomial.               */
/*                                                                  */
/*   [invertprbs]  Inverts the receive bit pattern.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_PRBSCHK0_Cfg_t tmp_prbschk0_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbschk0_cfg.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Cfg));
      tmp_prbschk0_cfg.bf.prbs_mode = prbs_mode;
      tmp_prbschk0_cfg.bf.invertPrbs = invertprbs;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Cfg), tmp_prbschk0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 PRBSCHK ENABLE T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_prbschk_enable_t41(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 enable)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Enable                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables the PRBS checker.                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [enable]  Enables receive PRBS monitoring function.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_PRBSCHK0_Cfg_t tmp_prbschk0_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbschk0_cfg.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Cfg));
      tmp_prbschk0_cfg.bf.enable = enable;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Cfg), tmp_prbschk0_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 PRBSCHK CONTROL HUNT T41                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_prbschk_control_hunt_t41(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 loadprbsstate)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o LoadPrbsState                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Causes the PRBS monitor to synchronize to the input stream.      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [loadprbsstate]  When set to one, the PRBS monitor enters the  */
/*     HUNT state and will stay in this state until the bit is      */
/*     cleared.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_PRBSCHK0_Ctrl_t tmp_prbschk0_ctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_prbschk0_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Ctrl));
      tmp_prbschk0_ctrl.bf.loadPrbsState = loadprbsstate;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, PRBSCHK0_Ctrl), tmp_prbschk0_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 PRBSCHK GET STATUS T41                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cfp32x1_prbschk_get_status_t41(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE or FALSE                                       */
/* DESCRIPTION:                                                     */
/* Indicates that the receive PRBS monitor is synchronized.         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3).                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_CFP32X1_SDS_COMMON_PRBSCHK0_INTSTATUS_t tmp_prbschk0_intstatus;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_prbschk0_intstatus.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, 
                               slice, PRBSCHK0_INTSTATUS));
  /*  When this bit is set it indicates that the receive  */
  /*  PRBS monitor is currently unable to synchronize.    */
  return (tmp_prbschk0_intstatus.bf.PRBS_SYNCs == 0);
}

/****************************************************************/
/* $rtn_hdr_start  CFP32X1 BIT INVERSION T41                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : CFP32X1                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_cfp32x1_tx0_config_bitinv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 invert)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Invert                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Invert the bit polarity of all TX data bits.                 */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/*   [invert] specifies whether or not to invert TX data bits   */
/*     0 = Do not invert                                        */
/*     1 = Invert.                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TX0_Config_t tmp_tx0_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }
  if(invert > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": invert out of range  s/b 0..1.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_tx0_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TX0_Config));
      tmp_tx0_config.bf.bitinv = invert;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TX0_Config), tmp_tx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 TX0 CONFIG DATA SOURCE T41               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_tx0_config_data_source_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 data_source)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Data Source                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Contains tx configuration for lane 0.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [data_source]  selects the input source for the TX  datapath.  */
/*     00 = DIG_TX_DIN                                              */
/*     01 = PRBS                                                    */
/*     10 = RX Loopback Data                                        */
/*     11 = Reserved.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_TX0_Config_t tmp_tx0_config;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_tx0_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TX0_Config));
      tmp_tx0_config.bf.data_source = data_source;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TX0_Config), tmp_tx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RX0 CONFIG BITINV T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_rx0_config_bitinv_t41(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 bitinv)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Bitinv                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets rx configuration for lane 0.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [bitinv]  Inverts the polarity of all rx data bits when set.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RX0_Config_t tmp_rx0_config;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rx0_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RX0_Config));
      tmp_rx0_config.bf.bitinv = bitinv;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RX0_Config), tmp_rx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RX0 CONFIG DATA SOURCE T41               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_cfp32x1_rx0_config_data_source_t41(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 data_source)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Data Source                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Contains rx configuration for lane 0.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [data_source]  Selects the input source for the RX datapath.   */
/*     0 = SRX_DOUT (Serdes data)                                   */
/*     1 = TX Loopback Data.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_CFP32X1_SDS_COMMON_RX0_Config_t tmp_rx0_config;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rx0_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RX0_Config));
      tmp_rx0_config.bf.data_source = data_source;
      TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RX0_Config), tmp_rx0_config.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/* Bugzilla 26403 Start */
/********************************************************************/
/* $rtn_hdr_start  CFP32X1 RX0 GET PRBSCK0 COUNT T41                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : CFP32X1                                             */
/* CHIP       : Tenabo                                              */
cs_uint32 ten_cfp32x1_rx0_get_prbsck0_count_t41 (cs_uint16 module_id, cs_uint8 slice) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Get CFP32X1 SDS Common PRBS Count                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint32 count;
  TEN_CFP32X1_SDS_COMMON_PRBSCHK0_Count0_t tmp_prbschk0_count0_t;
  TEN_CFP32X1_SDS_COMMON_PRBSCHK0_Count1_t tmp_prbschk0_count1_t;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_cfp32x1_rx0_get_prbsck0_count_t41";  

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3.", func);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s\n", func, ten_module_strings[module_id & 1], ten_slice_strings[slice]);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  tmp_prbschk0_count1_t.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, PRBSCHK0_Count1));
  tmp_prbschk0_count0_t.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, PRBSCHK0_Count0));

  count = (tmp_prbschk0_count0_t.wrd) | (tmp_prbschk0_count1_t.wrd << 16);

  CS_PRINT("%s() count = 0x%X\n", func, count);

  return (count);
}
/* Bugzilla 26403 End */



