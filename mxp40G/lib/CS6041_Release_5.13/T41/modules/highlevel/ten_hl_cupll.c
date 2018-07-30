/******************************************************************************/
/* This file contains information proprietary to Cortina Systems, Inc. */
/* (Cortina). Any use or disclosure, in whole or in part, of this information */
/* to any unauthorized party, for any purposes other than that for which it   */
/* is provided is expressly prohibited except as authorized by Cortina in     */
/* writing. Cortina reserves its rights to pursue both civil and criminal     */
/* penalties for copying or disclosure of this material without               */
/* authorization. Cortina Systems (R), Cortina (TM) and the Cortina Systems   */
/* Earth Logo are the trademarks or registered trademarks of Cortina Systems, */
/* Inc. and its subsidiaries in the U.S. and other countries. Any other       */
/* product and company names are the trademarks of their respective owners.   */
/* Copyright (C) 2006-2013 Cortina Systems, Inc. All rights reserved.         */
/******************************************************************************/

/*
 * ten_hl_cupll.c
 *
 * High Level CUPLL related code is implemented here.
 *
 * $Id: ten_hl_cupll.c,v 1.59 2013/08/16 13:26:42 khill Exp $
 *
 * Much of this file is auto-generated from cupll_config.xml; MODIFY WITH CARE.
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CUPLL CONFIG MODE T41                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_cupll_config_mode_t41(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 cupll_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o CUPLL Mode                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set up CUPLL for specified mode.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [cuppl_mode]                                                   */
/*     CUPLL_LOOP_311M_R_10M_C_9_95   = 0,                          */
/*     CUPLL_LOOP_311M_R_10M_C_11_05  = 1,                          */
/*     CUPLL_LOOP_311M_R_10M_C_11_7   = 2,                          */
/*     CUPLL_LOOP_425M_R_10M_C_9_95   = 3,                          */
/*     CUPLL_LOOP_425M_R_10M_C_11_05  = 4,                          */
/*     CUPLL_LOOP_425M_R_10M_C_11_7   = 5,                          */
/*     CUPLL_LOOP_311M_R_160M_C_9_95  = 6,                          */
/*     CUPLL_LOOP_311M_R_160M_C_11_05 = 7,                          */
/*     CUPLL_LOOP_311M_R_160M_C_11_7  = 8,                          */
/*     CUPLL_LOOP_425M_R_160M_C_9_95  = 9,                          */
/*     CUPLL_LOOP_425M_R_160M_C_11_05 = 10,                         */
/*     CUPLL_LOOP_425M_R_160M_C_11_7  = 11.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_cupll_config_mode_t41:  mod_id=0x%04X, sl=%d, cupll_mode=%d\n",
            module_id, slice, cupll_mode);
  
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 0r 0xFF.");
    return (CS_ERROR);
  }
  
  if (cupll_mode >= CUPLL_LOOP_MAX_MODE) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": cupll mode out of range.");
    return (CS_ERROR);
  }
  
  /* Assert soft resets before configuration */
  rtn |= ten_cupll_reset_t41(module_id, slice, 0xFF, CS_RESET_ASSERT);
  
  rtn |= ten_cupll_setup_t41(module_id, slice);
  
  rtn |= ten_cupll_ref_pilot_setup_1_xfi_t41(module_id, slice);
  
  switch (cupll_mode) {
  case (CUPLL_LOOP_311M_R_10M_C_9_95):
    rtn |= ten_cupll_loop_311m_r_10m_c_9_95_data_t41(module_id, slice);
    break;
  
  case (CUPLL_LOOP_311M_R_10M_C_11_05):
    rtn |= ten_cupll_loop_311m_r_10m_c_11_05_data_t41(module_id, slice);
    break;
  
  case (CUPLL_LOOP_311M_R_10M_C_11_7):
    rtn |= ten_cupll_loop_311m_r_10m_c_11_7_data_t41(module_id, slice);
    break;
  
  case (CUPLL_LOOP_425M_R_10M_C_9_95):
    rtn |= ten_cupll_loop_425m_r_10m_c_9_95_data_t41(module_id, slice);
    break;
  
  case (CUPLL_LOOP_425M_R_10M_C_11_05):
    rtn |= ten_cupll_loop_425m_r_10m_c_11_05_data_t41(module_id, slice);
    break;
   
  case (CUPLL_LOOP_425M_R_10M_C_11_7):
    rtn |= ten_cupll_loop_425m_r_10m_c_11_7_data_t41(module_id, slice);
    break;
  
  case (CUPLL_LOOP_311M_R_160M_C_9_95):
    rtn |= ten_cupll_loop_311m_r_160m_c_9_95_data_t41(module_id, slice);
    break;
  
  case (CUPLL_LOOP_311M_R_160M_C_11_05):
    rtn |= ten_cupll_loop_311m_r_160m_c_11_05_data_t41(module_id, slice);
    break;
  
  case (CUPLL_LOOP_311M_R_160M_C_11_7):
    rtn |= ten_cupll_loop_311m_r_160m_c_11_7_data_t41(module_id, slice);
    break;
  
  case (CUPLL_LOOP_425M_R_160M_C_9_95):
    rtn |= ten_cupll_loop_425m_r_160m_c_9_95_data_t41(module_id, slice);
    break;
  
  case (CUPLL_LOOP_425M_R_160M_C_11_05):
    rtn |= ten_cupll_loop_425m_r_160m_c_11_05_data_t41(module_id, slice);
    break;
  
  case (CUPLL_LOOP_425M_R_160M_C_11_7):
    rtn |= ten_cupll_loop_425m_r_160m_c_11_7_data_t41(module_id, slice);
    break;
  
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "Invalid CUPLL Mode.\n");
    rtn |= CS_ERROR;
    break;
  }
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  SET CONTROL BLOCK FOR CUPLL                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_set_cb_cupll_t41(cs_uint16 dev_id,
                               cs_uint8  source,
                               cs_uint16 k_value,
                               cs_uint32 freq,
                               cs_uint16 preloadfint,
                               cs_uint32 preloadffrac,
                               cs_uint32 pdoffset,
                               cs_uint16 holdovercount,
                               cs_uint16 k1fscale,
                               cs_uint16 k1fshift,
                               cs_uint16 z1fscale,
                               cs_uint16 z1fshift,
                               cs_uint16 p1fscale,
                               cs_uint16 p1fshift,
                               cs_uint16 p2fscale,
                               cs_uint16 p2fshift,
                               cs_uint16 p3fscale,
                               cs_uint16 p3fshift,
                               cs_uint16 k1sscale,
                               cs_uint16 k1sshift,
                               cs_uint16 z1sscale,
                               cs_uint16 z1sshift,
                               cs_uint16 p1sscale,
                               cs_uint16 p1sshift,
                               cs_uint16 p2sscale,
                               cs_uint16 p2sshift,
                               cs_uint16 p3sscale,
                               cs_uint16 p3sshift,
                               cs_uint16 resetcount,
                               cs_uint16 sdmode)
/* INPUTS     : o Device Id                                         */
/*              o Source                                            */
/*              o K Value                                           */
/*              o freq                                              */
/*              o preloadfint                                       */
/*              o preloadffrac                                      */
/*              o pdoffset                                          */
/*              o holdovercount                                     */
/*              o k1fscale                                          */
/*              o k1fshift                                          */
/*              o z1fscale                                          */
/*              o z1fshift                                          */
/*              o p1fscale                                          */
/*              o p1fshift                                          */
/*              o p2fscale                                          */
/*              o p2fshift                                          */
/*              o p3fscale                                          */
/*              o p3fshift                                          */
/*              o k1sscale                                          */
/*              o k1sshift                                          */
/*              o z1sscale                                          */
/*              o z1sshift                                          */
/*              o p1sscale                                          */
/*              o p1sshift                                          */
/*              o p2sscale                                          */
/*              o p2sshift                                          */
/*              o p3sscale                                          */
/*              o p3sshift                                          */
/*              o resetcount                                        */
/*              o sdmode                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Write Input Arguments to fields in CUPLL Control Block.          */
/*                                                                  */
/*   The [source] parameter refers to the originating source for    */
/*     TX clock. It is specified as:                                */
/*        TX_CLOCK_SOURCE_FIXED    = 0, Tx FracDiv off system GPLL. */
/*        TX_CLOCK_SOURCE_RXDIV    = 1, Recovered/synthesized clock */
/*        TX_CLOCK_SOURCE_EXT_CLK  = 2, ext, XFI_TX_CLKREF pin.     */
/*        TX_CLOCK_SOURCE_EXT_AUX  = 3, ext, XFI_AUX_LPTIME_CLKREF. */
/*        TX_CLOCK_SOURCE_PILOT    = 4, Fixed, RX internal pilot.   */
/*        TX_CLOCK_SOURCE_PILOTDIV = 5, Fixed, pilotw divider/prot. */
/*        TX_CLOCK_SOURCE_RXLINE   = 6, Fixed source via RX line.   */
/*                                                                  */
/*   The [k_value] parameter is specified as:                       */
/*     16, 32, 64                                                   */
/*                                                                  */
/*   The [freq] parameter is specified as:                          */
/*     200000000, 400000000, 311040000, 622080000                   */
/*                                                                  */
/*   The [preloadfint] parameter is specified as:                   */
/*     0x0000..0x007f                                               */
/*                                                                  */
/*   The [preloadffrac] parameter is specified as:                  */
/*     0x00000000..0xffffffff                                       */
/*                                                                  */
/*   The [pdoffset] parameter is specified as:                      */
/*     0x00000000..0x0007ffff                                       */
/*                                                                  */
/*   The [holdovercount] parameter is specified as:                 */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [k1fscale] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [k1fshift] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [z1fscale] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [z1fshift] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p1fscale] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p1fshift] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p2fscale] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p2fshift] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p3fscale] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p3fshift] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [k1sscale] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [k1sshift] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [z1sscale] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [z1sshift] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p1sscale] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p1sshift] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p2sscale] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p2sshift] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p3sscale] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [p3sshift] parameter is specified as:                      */
/*     0x0000..0x001f                                               */
/*                                                                  */
/*   The [resetcount] parameter is specified as:                    */
/*     0x0000..0x00ff                                               */
/*                                                                  */
/*   The [sdmode] parameter is specified as:                        */
/*     0x0000..0x0007                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  ten_dev_cb_t *pdevcb;

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  
   if (pdevcb) {
     pdevcb->cupll_cb.source        = source;
     pdevcb->cupll_cb.k_value       = k_value;
     pdevcb->cupll_cb.freq          = freq;
     pdevcb->cupll_cb.preloadfint   = preloadfint;
     pdevcb->cupll_cb.preloadffrac  = preloadffrac;
     pdevcb->cupll_cb.pdoffset      = pdoffset;
     pdevcb->cupll_cb.holdovercount = holdovercount;
     pdevcb->cupll_cb.k1fscale      = k1fscale;
     pdevcb->cupll_cb.k1fshift      = k1fshift;
     pdevcb->cupll_cb.z1fscale      = z1fscale;
     pdevcb->cupll_cb.z1fshift      = z1fshift;
     pdevcb->cupll_cb.p1fscale      = p1fscale;
     pdevcb->cupll_cb.p1fshift      = p1fshift;
     pdevcb->cupll_cb.p2fscale      = p2fscale;
     pdevcb->cupll_cb.p2fshift      = p2fshift;
     pdevcb->cupll_cb.p3fscale      = p3fscale;
     pdevcb->cupll_cb.p3fshift      = p3fshift;
     pdevcb->cupll_cb.k1sscale      = k1sscale;
     pdevcb->cupll_cb.k1sshift      = k1sshift;
     pdevcb->cupll_cb.z1sscale      = z1sscale;
     pdevcb->cupll_cb.z1sshift      = z1sshift;
     pdevcb->cupll_cb.p1sscale      = p1sscale;
     pdevcb->cupll_cb.p1sshift      = p1sshift;
     pdevcb->cupll_cb.p2sscale      = p2sscale;
     pdevcb->cupll_cb.p2sshift      = p2sshift;
     pdevcb->cupll_cb.p3sscale      = p3sscale;
     pdevcb->cupll_cb.p3sshift      = p3sshift;
     pdevcb->cupll_cb.resetcount    = resetcount;
     pdevcb->cupll_cb.sdmode        = sdmode;
  }
  else {
    return (CS_ERROR);
  }
 
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SET CONTROL BLOCK FOR CUPLL INTERNAL CALCULATED  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_set_cb_cupll_calc_t41(cs_uint16 dev_id,
                                    double    rate,
                                    cs_uint8  source,
                                    cs_uint16 k_value,
                                    cs_uint32 freq,
                                    cs_uint32 pdoffset)
/* INPUTS     : o Device Id                                         */
/*              o Rate                                              */
/*              o Source                                            */
/*              o K Value                                           */
/*              o freq                                              */
/*              o pdoffset                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Write Input Arguments to fields in CUPLL Control Block.          */
/*                                                                  */
/*   The [rate] parameter is specified as:                          */
/*     the line rate of the specified line or client                */
/*     0..~40G                                                      */
/*                                                                  */
/*   The [source] parameter refers to the originating source for    */
/*     TX clock. It is specified as:                                */
/*        TX_CLOCK_SOURCE_FIXED    = 0, Tx FracDiv off system GPLL. */
/*        TX_CLOCK_SOURCE_RXDIV    = 1, Recovered/synthesized clock */
/*        TX_CLOCK_SOURCE_EXT_CLK  = 2, ext, XFI_TX_CLKREF pin.     */
/*        TX_CLOCK_SOURCE_EXT_AUX  = 3, ext, XFI_AUX_LPTIME_CLKREF. */
/*        TX_CLOCK_SOURCE_PILOT    = 4, Fixed, RX internal pilot.   */
/*        TX_CLOCK_SOURCE_PILOTDIV = 5, Fixed, pilotw divider/prot. */
/*        TX_CLOCK_SOURCE_RXLINE   = 6, Fixed source via RX line.   */
/*                                                                  */
/*   The [k_value] parameter is specified as:                       */
/*     16, 32, 64                                                   */
/*                                                                  */
/*   The [freq] parameter is specified as:                          */
/*     200000000, 400000000, 311040000, 622080000                   */
/*                                                                  */
/*   The [pdoffset] parameter is specified as:                      */
/*     0x00000000..0x0007ffff                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  ten_dev_cb_t *pdevcb;

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  
   if (pdevcb) {
     pdevcb->cupll_cb.rate          = rate;
     pdevcb->cupll_cb.source        = source;
     pdevcb->cupll_cb.k_value       = k_value;
     pdevcb->cupll_cb.freq          = freq;
     pdevcb->cupll_cb.pdoffset      = pdoffset;
     /* Bugzilla 35199 Start */
     /* 0 is the correct divider setting for all CUPLL configs except */
     /* subrate which should call ten_set_cb_cupll_calc_t41_v2        */
     pdevcb->cupll_cb.subrate_div   = 0;
     /* Bugzilla 35199 End */
     pdevcb->cupll_cb.standalone    = 0; /* Bug 36866 */
  }
  else {
    return (CS_ERROR);
  }
 
  return (CS_OK);
}

/* Bugzilla 35199 Start */
/********************************************************************/
/* $rtn_hdr_start  SET CONTROL BLOCK FOR CUPLL INTERNAL CALC V2     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_set_cb_cupll_calc_t41_v2(cs_uint16 dev_id,
                                    double    rate,
                                    cs_uint8  source,
                                    cs_uint16 k_value,
                                    cs_uint32 freq,
                                    cs_uint32 pdoffset,
                                    cs_uint8  subrate_div)
/* INPUTS     : o Device Id                                         */
/*              o Rate                                              */
/*              o Source                                            */
/*              o K Value                                           */
/*              o freq                                              */
/*              o pdoffset                                          */
/*              o subrate_div                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Write Input Arguments to fields in CUPLL Control Block. V2 adds  */
/* the subrate_div parameter which needs to be populated for        */
/* subrate CUPLL applications.                                      */
/*                                                                  */
/*   The [rate] parameter is specified as:                          */
/*     the line rate of the specified line or client                */
/*     0..~40G                                                      */
/*                                                                  */
/*   The [source] parameter refers to the originating source for    */
/*     TX clock. It is specified as:                                */
/*        TX_CLOCK_SOURCE_FIXED    = 0, Tx FracDiv off system GPLL. */
/*        TX_CLOCK_SOURCE_RXDIV    = 1, Recovered/synthesized clock */
/*        TX_CLOCK_SOURCE_EXT_CLK  = 2, ext, XFI_TX_CLKREF pin.     */
/*        TX_CLOCK_SOURCE_EXT_AUX  = 3, ext, XFI_AUX_LPTIME_CLKREF. */
/*        TX_CLOCK_SOURCE_PILOT    = 4, Fixed, RX internal pilot.   */
/*        TX_CLOCK_SOURCE_PILOTDIV = 5, Fixed, pilotw divider/prot. */
/*        TX_CLOCK_SOURCE_RXLINE   = 6, Fixed source via RX line.   */
/*                                                                  */
/*   The [k_value] parameter is specified as:                       */
/*     16, 32, 64                                                   */
/*                                                                  */
/*   The [freq] parameter is specified as:                          */
/*     200000000, 400000000, 311040000, 622080000                   */
/*                                                                  */
/*   The [pdoffset] parameter is specified as:                      */
/*     0x00000000..0x0007ffff                                       */
/*                                                                  */
/*   The [subrate_div] parameter is specified as:                   */
/*     Subrate clients require different settings for               */
/*     XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SPARE.               */
/*     STXP_REFCLK_DIV_SEL                                          */
/*     0 = Full rate clients                                        */
/*     1 = Half rate clients                                        */
/*     2 = Quarter rate clients                                     */
/*     3 = Eighth rate clients                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  ten_dev_cb_t *pdevcb;

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  
   if (pdevcb) {
     pdevcb->cupll_cb.rate          = rate;
     pdevcb->cupll_cb.source        = source;
     pdevcb->cupll_cb.k_value       = k_value;
     pdevcb->cupll_cb.freq          = freq;
     pdevcb->cupll_cb.pdoffset      = pdoffset;
     pdevcb->cupll_cb.subrate_div   = subrate_div;
     pdevcb->cupll_cb.standalone    = 0; /* Bug 36866 */
  }
  else {
    return (CS_ERROR);
  }
 
  return (CS_OK);
}
/* Bugzilla 35199 End */

/* Bugzilla 36358  Start */
/********************************************************************/
/* $rtn_hdr_start  SET CONTROL BLOCK FOR CUPLL STAND ALONE          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_set_cb_stand_alone_cupll_t41(cs_uint16 dev_id,
                                           double    rate,
                                           cs_uint8  source,
                                           cs_uint16 k_value,
                                           cs_uint32 freq,
                                           cs_uint32 pdoffset,
                                           cs_uint8  subrate_div,
                                           double    stand_alone_cupll_rate)
/* INPUTS     : o Device Id                                         */
/*              o Rate                                              */
/*              o Source                                            */
/*              o K Value                                           */
/*              o freq                                              */
/*              o pdoffset                                          */
/*              o subrate_div                                       */
/*              o Stand Alone CUPLL Output Rate                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Write Input Arguments to fields in CUPLL Control Block for Stand */
/* Alone CUPLL applications.                                        */
/*                                                                  */
/*   The [rate] parameter is specified as:                          */
/*     the line rate of the specified line or client                */
/*     0..~40G                                                      */
/*                                                                  */
/*   The [source] parameter refers to the originating source for    */
/*     TX clock. It is specified as:                                */
/*        TX_CLOCK_SOURCE_FIXED    = 0, Tx FracDiv off system GPLL. */
/*        TX_CLOCK_SOURCE_RXDIV    = 1, Recovered/synthesized clock */
/*        TX_CLOCK_SOURCE_EXT_CLK  = 2, ext, XFI_TX_CLKREF pin.     */
/*        TX_CLOCK_SOURCE_EXT_AUX  = 3, ext, XFI_AUX_LPTIME_CLKREF. */
/*        TX_CLOCK_SOURCE_PILOT    = 4, Fixed, RX internal pilot.   */
/*        TX_CLOCK_SOURCE_PILOTDIV = 5, Fixed, pilotw divider/prot. */
/*        TX_CLOCK_SOURCE_RXLINE   = 6, Fixed source via RX line.   */
/*                                                                  */
/*   The [k_value] parameter is specified as:                       */
/*     16, 32, 64                                                   */
/*                                                                  */
/*   The [freq] parameter is specified as:                          */
/*     200000000, 400000000, 311040000, 622080000                   */
/*                                                                  */
/*   The [pdoffset] parameter is specified as:                      */
/*     0x00000000..0x0007ffff                                       */
/*                                                                  */
/*   The [subrate_div] parameter is specified as:                   */
/*     Subrate clients require different settings for               */
/*     XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SPARE.               */
/*     STXP_REFCLK_DIV_SEL                                          */
/*     0 = Full rate clients                                        */
/*     1 = Half rate clients                                        */
/*     2 = Quarter rate clients                                     */
/*     3 = Eighth rate clients                                      */
/*                                                                  */
/*   The [stand_alone_cupll_rate] parameter is specified as:        */
/*     The desired output frequency of a Stand Alone CUPLL, at the  */
/*     TX_TCLKO pins, in hertz.                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  ten_dev_cb_t *pdevcb;

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  
   if (pdevcb) {
     pdevcb->cupll_cb.rate          = rate;
     pdevcb->cupll_cb.source        = source;
     pdevcb->cupll_cb.k_value       = k_value;
     pdevcb->cupll_cb.freq          = freq;
     pdevcb->cupll_cb.pdoffset      = pdoffset;
     pdevcb->cupll_cb.subrate_div   = subrate_div;

     pdevcb->cupll_cb.standalone    = 1;
     pdevcb->cupll_cb.stand_alone_cupll_rate = stand_alone_cupll_rate;
  }
  else {
    return (CS_ERROR);
  }
 
  return (CS_OK);
}
/* Bugzilla 36358  End */

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL MAKE SHIFT                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cupll_make_shift(double coeffin)
/* INPUTS     : o Coefficient In                                    */
/* OUTPUTS    : o Shift                                             */
/* RETURNS    : CS_UINT16                                           */
/* DESCRIPTION:                                                     */
/* Generates the "shift" value for CUPLL.                           */
/*                                                                  */
/*  [coeffin]  Specified as:                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   cs_uint16 shift=0;
   double temp = coeffin*32.0;

  /* Bug 28855: coeffin<=0 results in infinite loop, log the error, */
  /* go ahead and return 0 as the shift value */
  if (coeffin <= 0) {
    CS_HNDL_ERROR(0, ETEN_MOD_INVALID_USER_ARG, ": coeffin out of range, must be >0.0.");
    return shift;
  }

   while ((int)(temp+0.5)<16) {
       shift++;
       temp = temp*2.0;
   }
   /* printf( "shift = %lx\n",  shift); */
   return shift;
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL TWO POWER                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_uint32 ten_cupll_two_pow(cs_uint16 in)
/* INPUTS     : o In                                                */
/* OUTPUTS    : o Out = 2^In                                        */
/* RETURNS    : CS_UINT16                                           */
/* DESCRIPTION:                                                     */
/* Generates 2^In for CUPLL.                                        */
/*                                                                  */
/*  [in]  Specified as:                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 i;
  cs_uint32 out = 1;

   for(i=0;i<in;i++) {
       out *= 2;
   }
   /* printf( "ten_cupll_two_pow %d = %d\n",  in, out); */
   return out;
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CUPLL CONFIG T41                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_cupll_config_t41(cs_uint16 module_id,
                                  cs_uint8  slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provision CUPLL .                                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   Note: most parameters are passed through a control block       */
/*         data structure.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status    rtn                    = CS_OK;
  cs_uint16    sl;
  ten_dev_cb_t *pdevcb;
  cs_uint16    tmp_dev_id             = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint8     verbose                = 0;

  /* 1XXX STXP_GRO_SYNCDSYNC_CLKIN */
  /* Removed const for stand alone cupll */
  const cs_uint16 gro_refclk_sel      = 0x8;
  /* Phase Measure */
  const cs_uint16 gro_mode            = 0;
  /* Powered Up */
  const cs_uint16 gro_pd              = 0;
  /* Bugzilla 36358  Start */
  /* Removed const for stand alone cupll */
        cs_uint16 gro_refclk_div_sel  = 0x01;
  /* Bugzilla 36358  End */
  cs_uint16 gro_clk_div_sel;

  const cs_uint16 filt_tune2          = 7;
  const cs_uint16 filt_tune1          = 7;
  const cs_uint16 frac_filten         = 1;
  /* Invert */
  const cs_uint16 mmd_inv_en          = 1;

  cs_uint32 freq;
  cs_uint16 k_value;
  cs_uint16 preloadfint;
  cs_uint32 preloadffrac;
  double    preloadffrac_temp;
  /* Raw phase number */
  const cs_uint16 pdoutsel            = 0;
  const cs_uint16 countershift        = 1;
  const cs_uint16 counterctrl         = 3;
  cs_uint32 pdoffset;
  /* Reg4 (most delay) */
  const cs_uint16 holdoverselect      = 0x3;
  /* Delay = 16*2^HoldoverCount/ Fref */
  const cs_uint16 holdovercount       = 0x16;
  /* PDcalOverride Register */
  const cs_uint16 pdcalsel            = 1;
  const cs_uint16 pdcaloverride       = 0x080;
  /* lowpass filter 3 */
  const cs_uint16 filtsels            = 3;
  /* lowpass filter 2 */
  const cs_uint16 filtself            = 2;

  /* Bugzilla 35376 Start */
  const cs_uint16 resetcount          = 4;
  const cs_uint16 hiloerroren         = 0;
  const cs_uint16 fixbubble           = 1;
  const cs_uint16 timeouten           = 0;
  const cs_uint16 ringerroren         = 1;
  /* Bugzilla 35376 End */
  /* MASH121 */
  /* Bugzilla 35199 Start */
  const cs_uint16 sdmode              = 5;
  /* Bugzilla 35199 End */
  const cs_uint16 gro_spare           = 0xc0c0;
  const cs_uint16 cptstdn             = 0;
  /* Bugzilla 35199 Start */
  cs_uint16 cpcur1;
  cs_uint16 cpcur0;
  /* Bugzilla 35199 End */

  /* Set settle timer value to 15ms (at 400MHz) */
  /* Bugzilla 31474: Settle timer should be set to min of 15ms @ 425MHz */
  /*   15ms * (425MHz/4) / 256 =  6225 decimal =  0x1851 hex            */
  const cs_uint16 settle_val          = 0x1851;

  cs_boolean div_freq_by_2            = FALSE;       
  /* XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SPARE.STXP_REFCLK_DIV_SEL divider */
  /* must be used for all CUPLL System Clock rates above 400MHz                */
  const cs_uint32 freq_max            = 400000000;
  /* Bugzilla 35199 Deleted code */

  /* Bugzilla 36358  Start */
  /* Removed const        */
        double cuplldiv               = 1024;
  /* Bugzilla 36358  End */
  const double fastBW                 = 10000;
  const double fastZ                  = 480;
  const double fastP1                 = 24600;
  const double fastP2                 = 200000;
  const double fastP3                 = 100;
  const double slowBW                 = 100;
  const double slowZ                  = 0.6;
  const double slowP1                 = 246;
  const double slowP2                 = 2000;
  const double slowP3                 = 2000;
  const double pi                     = 3.14159;
  const double nomGRO                 = 10e-12;
  const double BWcorrection           = 0.7;

  double Fline;
  double Fsync;
  double Fref;
  double Fsynth;
  double synthDiv;

  double k1f;
  double z1f;
  double p1f;
  double p2f;
  double p3f;
  double k1s;
  double z1s;
  double p1s;
  double p2s;
  double p3s;

  cs_uint16 k1fscale;
  cs_uint16 k1fshift;
  cs_uint16 z1fscale;
  cs_uint16 z1fshift;
  cs_uint16 p1fscale;
  cs_uint16 p1fshift;
  cs_uint16 p2fscale;
  cs_uint16 p2fshift;
  cs_uint16 p3fscale;
  cs_uint16 p3fshift;
  cs_uint16 k1sscale;
  cs_uint16 k1sshift;
  cs_uint16 z1sscale;
  cs_uint16 z1sshift;
  cs_uint16 p1sscale;
  cs_uint16 p1sshift;
  cs_uint16 p2sscale;
  cs_uint16 p2sshift;
  cs_uint16 p3sscale;
  cs_uint16 p3sshift;

  /* Bugzilla 35199 Start */
  cs_uint8 subrate_div;
  /* Bugzilla 35199 End */
  /* Bugzilla 36358  Start      */
  /* New for stand alone CUPLL */
  cs_uint16 divider_sds_tclko     = 0;
  cs_uint16 stxp_tclko_sel        = 0;

  cs_double fvco                  = 0.0;
  /* const cs_double fvco_min        = 10000000000.0; */
  const cs_double fvco_min        = 8000000000.0;
  const cs_double fvco_max        = 12500000000.0;

  cs_double lane_rate             = 0.0;
  cs_double gro_clk_div_sel_float = 0.0;
  /* Bugzilla 36358  End */


  CS_PRINT("ten_hl_cupll_config_t41:  mod_id=0x%04X, sl=%d\n",
            module_id, slice);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 0r 0xFF.");
    return (CS_ERROR);
  }
  
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(tmp_dev_id);

   /* Control block values */
  Fline            = pdevcb->cupll_cb.rate;
  k_value          = pdevcb->cupll_cb.k_value;
  freq             = pdevcb->cupll_cb.freq;
  /* Bug 37262 code removed */
  /* Bugzilla 35199 Start */
  subrate_div      = pdevcb->cupll_cb.subrate_div;
  /* Bugzilla 35199 End */

  /* Calculate clock frequencies */
  if (freq > freq_max) {
    div_freq_by_2 = TRUE;
  }
  Fref             = div_freq_by_2 ? freq/2 : freq;


  /* Bugzilla 36358  Start */
  Fsync        = pdevcb->cupll_cb.rate;

  if (pdevcb->cupll_cb.standalone == 1) {
      /* Range check and divide jittery clock down if necessary */
      if (Fsync < 900000.0) {
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
              "Stand Alone CUPLL: Fsync=%f too low, must be >= 9MHz\n", Fsync);
          return CS_ERROR;
      } else {
          while (Fsync > 100000000.0) {
              gro_refclk_div_sel++;
              if (gro_refclk_div_sel > 0xFF) {
                  CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                      "Stand Alone CUPLL: gro_refclk_div_sel=%x too high, must be <= 0xFF\n", gro_refclk_div_sel);
                  return CS_ERROR;
              }
              Fsync = pdevcb->cupll_cb.rate/(double)gro_refclk_div_sel;
          }
      }
      
      lane_rate = pdevcb->cupll_cb.stand_alone_cupll_rate;
      /* Determine XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKOUT_CTRL.STXP_TCLKO_SEL   */
      /* and VCO frequency. VCO frequency is a function of lane_rate and */
      /* this divider.                                                   */
      do {
          if      (divider_sds_tclko ==  0) { divider_sds_tclko = 16; }
          else if (divider_sds_tclko == 16) { divider_sds_tclko = 32; }
          else if (divider_sds_tclko == 32) { divider_sds_tclko = 40; }
          else if (divider_sds_tclko == 40) { divider_sds_tclko = 64; }
          else if (divider_sds_tclko == 64) { divider_sds_tclko = 66; }
          else if (divider_sds_tclko == 66) { divider_sds_tclko = 80; }
          else if (divider_sds_tclko == 80) {
              CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                  "Stand Alone CUPLL: lane_rate=%f * tclko divider=%d too low, must be >= %fMHz\n",
                  lane_rate, divider_sds_tclko, fvco_min);
              return CS_ERROR;
          }
          if ((lane_rate*divider_sds_tclko) > fvco_max) {
              CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                  "Stand Alone CUPLL: lane_rate=%f * tclko divider=%d too high, must be <= %fMHz\n",
                  lane_rate, divider_sds_tclko, fvco_max);
              return CS_ERROR;
          }        
      } while ((lane_rate*divider_sds_tclko) < fvco_min);
      fvco = lane_rate*divider_sds_tclko;

      switch (divider_sds_tclko) {
          case 16: stxp_tclko_sel = TEN_HSIF_CFP_DIV_BY_16_REF; break;
          case 32: stxp_tclko_sel = TEN_HSIF_CFP_DIV_BY_32_REF; break;
          case 40: stxp_tclko_sel = TEN_HSIF_CFP_DIV_BY_40_REF; break;
          case 64: stxp_tclko_sel = TEN_HSIF_CFP_DIV_BY_64_REF; break;
          case 66: stxp_tclko_sel = TEN_HSIF_CFP_DIV_BY_66_REF; break;
          case 80: stxp_tclko_sel = TEN_HSIF_CFP_DIV_BY_80_REF; break;
          default:
              CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                  "Stand Alone CUPLL: Bad tclko divider: %d\n", divider_sds_tclko);
              return CS_ERROR;
              break;
      }
  
      cuplldiv = fvco/Fsync;
      Fline    = fvco;
  }

    /* Calculate clock frequencies and divider settings */
    if (pdevcb->cupll_cb.standalone == 1)  {
        /* This is the divided VCO fed into the CUPLL phase detector. The     */
        /* frequency of this clock is a function of the VCO frequency divided */
        /* by 64 and T100_SDS_COMMON_STXP0_GRO_DIV_CTRL.STXP_GRO_CLK_DIV_SEL. */
        /* The frequency of this phase detector input must match that of the  */
        /* divided input clock, lane rate.                                    */
        gro_clk_div_sel_float = (fvco/64.0) / Fsync;
        if ((gro_clk_div_sel_float-(cs_uint16)gro_clk_div_sel_float) < 0.001) {
            gro_clk_div_sel = (cs_uint16)gro_clk_div_sel_float;
        } else {
            CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                "Stand Alone CUPLL: vco=%f/64 must be evenly divided by the divided fin=%fMHz\n", fvco, Fsync);
            return CS_ERROR;
        }
    } else {
        Fsync            = Fline/cuplldiv;
        gro_clk_div_sel  = 16;
    }
    Fsynth           = Fline;
    synthDiv         = Fsynth/Fref;
    /* Bugzilla 36358  End */


  /* Make sure synthDiv is in the ballpark before recasting */
  if (synthDiv < 128) {
    /* Recast to floor the double value */
    preloadfint       = (cs_uint16) synthDiv;
    /* Subtract int from double to get fraction, multiply       */
    /* by 2^32, expressed as double to prevent compiler warning */
    preloadffrac_temp = (synthDiv-preloadfint) * 4294967296.0;
    /* Recast fractional part to int for register write */
    preloadffrac      = (cs_uint32) preloadffrac_temp;
  }
  else
  {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": synthDiv out of range.  s/b 0..127.");
    return (CS_ERROR);
  }

  k1f              = 2*pi*cuplldiv*fastBW*Fsync*nomGRO/(Fref*BWcorrection);
  z1f              = 2*pi*fastZ/Fsync;
  p1f              = 2*pi*fastP1/Fsync;
  p2f              = 2*pi*fastP2/Fsync;
  p3f              = 2*pi*fastP3/Fsync;
  k1s              = 2*pi*cuplldiv*slowBW*Fsync*nomGRO/(Fref*BWcorrection);
  z1s              = 2*pi*slowZ/Fsync;
  p1s              = 2*pi*slowP1/Fsync;
  p2s              = 2*pi*slowP2/Fsync;
  p3s              = 2*pi*slowP3/Fsync;

  k1fshift         = ten_cupll_make_shift(k1f);
  k1fscale         = (int)((k1f*ten_cupll_two_pow(k1fshift)*32)+0.5);
  k1fshift         = k1fshift - 17 + 6 - 3;
  z1fshift         = ten_cupll_make_shift(z1f);
  z1fscale         = (int)((z1f*ten_cupll_two_pow(z1fshift)*32)+0.5);
  p1fshift         = ten_cupll_make_shift(p1f);
  p1fscale         = (int)((p1f*ten_cupll_two_pow(p1fshift)*32)+0.5);
  p2fshift         = ten_cupll_make_shift(p2f);
  p2fscale         = (int)((p2f*ten_cupll_two_pow(p2fshift)*32)+0.5);
  p3fshift         = ten_cupll_make_shift(p3f);
  p3fscale         = (int)((p3f*ten_cupll_two_pow(p3fshift)*32)+0.5);
  k1sshift         = ten_cupll_make_shift(k1s);
  k1sscale         = (int)((k1s*ten_cupll_two_pow(k1sshift)*32)+0.5);
  k1sshift         = k1sshift - 17 + 6 - 3;
  z1sshift         = ten_cupll_make_shift(z1s);
  z1sscale         = (int)((z1s*ten_cupll_two_pow(z1sshift)*32)+0.5);
  p1sshift         = ten_cupll_make_shift(p1s);
  p1sscale         = (int)((p1s*ten_cupll_two_pow(p1sshift)*32)+0.5);
  p2sshift         = ten_cupll_make_shift(p2s);
  p2sscale         = (int)((p2s*ten_cupll_two_pow(p2sshift)*32)+0.5);
  p3sshift         = ten_cupll_make_shift(p3s);
  p3sscale         = (int)((p3s*ten_cupll_two_pow(p3sshift)*32)+0.5);

  /* Bug 37262 Start */
  if        (Fsync <= 25000000.0) {
      pdoffset = 800;
  } else if ((25000000.0 < Fsync) && (Fsync <= 100000000.0)) {
      pdoffset = (cs_uint32)(800.0 / (4.0*(Fsync/100000000.0)));
  } else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Fsync = %d out of range, must be <=100MHz.\n", Fsync);
    return (CS_ERROR);
  }
  /* Bug 37262 End */

  /* Bugzilla 35199 Start */
  switch (subrate_div) {
    case 1: 
      /* Half rate */
      cpcur1 = 0x55;
      cpcur0 = 0x55;
      break;
    case 2: 
      /* Quarter rate */
      cpcur1 = 0x55;
      cpcur0 = 0x55;
      break;
    case 3: 
      /* Eighth rate */
      cpcur1 = 0x77;
      cpcur0 = 0x77;
      break;
    default: 
      /* Full rate */
      cpcur1 = 0x33;
      cpcur0 = 0x33;
      break;
  }
  /* Bugzilla 35199 End */

  /* Adjust subrate_div if freq > freq_max */
  if (div_freq_by_2) {
    subrate_div += 1;
  }
  if (subrate_div > 3) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": CUPLL reference divider out of range: %d.  s/b 0..3.", subrate_div);
    return (CS_ERROR);
  }

  if (verbose == 1) {
    printf("Fline:  %f\n", Fline);
    printf("Fref:   %f\n", Fref);
    printf("Fsync:  %f\n", Fsync);
    printf("Fsynth: %f\n", Fsynth);
    printf("preloadfint:  %32x\n", preloadfint);
    printf("preloadffrac: %32x\n", preloadffrac);
    printf("subrate_div: %d\n", subrate_div);
    printf("-------------\n");
    printf("k1f     : %f\n", k1f);
    printf("z1f     : %f\n", z1f);
    printf("p1f     : %f\n", p1f);
    printf("p2f     : %f\n", p2f);
    printf("p3f     : %f\n\n", p3f);
    printf("k1s     : %f\n", k1s);
    printf("z1s     : %f\n", z1s);
    printf("p1s     : %f\n", p1s);
    printf("p2s     : %f\n", p2s);
    printf("p3s     : %f\n", p3s);
    printf("-------------\n");
    printf("k1fscale: %16x\n", k1fscale);
    printf("k1fshift: %16x\n", k1fshift);
    printf("z1fscale: %16x\n", z1fscale);
    printf("z1fshift: %16x\n", z1fshift);
    printf("p1fscale: %16x\n", p1fscale);
    printf("p1fshift: %16x\n", p1fshift);
    printf("p2fscale: %16x\n", p2fscale);
    printf("p2fshift: %16x\n", p2fshift);
    printf("p3fscale: %16x\n", p3fscale);
    printf("p3fshift: %16x\n\n", p3fshift);
    printf("k1sscale: %16x\n", k1sscale);
    printf("k1sshift: %16x\n", k1sshift);
    printf("z1sscale: %16x\n", z1sscale);
    printf("z1sshift: %16x\n", z1sshift);
    printf("p1sscale: %16x\n", p1sscale);
    printf("p1sshift: %16x\n", p1sshift);
    printf("p2sscale: %16x\n", p2sscale);
    printf("p2sshift: %16x\n", p2sshift);
    printf("p3sscale: %16x\n", p3sscale);
    printf("p3sshift: %16x\n", p3sshift);
  }
 
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      /* Bugzilla 35199 Start */
      rtn |= ten_xfi32x1_stxp0_tx_spare_refclk_div_sel_t41(module_id, sl, subrate_div);
      /* Bugzilla 35199 End */

      /* Enable clocks */
      rtn |= ten_mpif_global_clock_disable_cupll_t41(tmp_dev_id, sl, CS_ENABLE);

      /* Deassert global resets */
      rtn |= ten_mpif_global_reset_cupll_mpif_t41(tmp_dev_id, sl, CS_RESET_DEASSERT);
      rtn |= ten_mpif_global_reset_cupll_tx_t41(tmp_dev_id, sl, CS_RESET_DEASSERT);
      rtn |= ten_mpif_global_reset_cupll_holdover_t41(tmp_dev_id, TEN_HOLDOVER_ALL, CS_RESET_DEASSERT);

      /* local force = on */
      rtn |= ten_mpif_cupll_local_force_t41(tmp_dev_id, sl, 2, CS_DISABLE);
      rtn |= ten_mpif_cupll_local_force_t41(tmp_dev_id, sl, 1, CS_DISABLE);
      rtn |= ten_mpif_cupll_local_force_t41(tmp_dev_id, sl, 0, CS_ENABLE);

      /* Set up GRO */
      /* Bugzilla 36358  Start */
      if (pdevcb->cupll_cb.standalone != 1) {
          rtn |= ten_xfi32x1_stxp0_tx_config_pilot_sel(module_id, sl, 1);
      }
  
      if (pdevcb->cupll_cb.standalone == 1) {
          /* Set dividers for lock detect */
          rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(module_id, sl, 1); /* div2 */
          rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctv_div(module_id, sl, 1); /* div2 */
          /* Set divider for tclko */
          rtn |= ten_xfi32x1_stxp0_tx_clkout_ctrl_tclko_sel(module_id, sl, stxp_tclko_sel);
          /* Output enable for tclocko */
          rtn |= ten_xfi32x1_stxp0_tx_clkout_ctrl_clkouten (module_id, slice, 1);
    }
  
      rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ddiv_sel(module_id, sl, 0);
  
      if (pdevcb->cupll_cb.standalone == 1) {
          /* Stand Alone CUPLL isn't constrained to an integer divider */
          /* to match an RX lock integer divider.                      */
          rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_rdiv_sel(module_id, sl, 0x7);
      }



       /* Bugzilla 36358  Start */
      if (pdevcb->cupll_cb.standalone != 1) {
        rtn |= ten_xfi32x1_stxp0_gro_ctrl_refclk_sel_t41(module_id, sl, gro_refclk_sel);
      }
      /* Bugzilla 36358  End */
      rtn |= ten_xfi32x1_stxp0_gro_ctrl_mode_t41(module_id, sl, gro_mode);
      rtn |= ten_xfi32x1_stxp0_gro_ctrl_pd_t41(module_id, sl, gro_pd);
      rtn |= ten_xfi32x1_stxp0_gro_div_ctrl_refclk_div_sel_t41(module_id, sl, gro_refclk_div_sel);
      rtn |= ten_xfi32x1_stxp0_gro_div_ctrl_clk_div_sel_t41(module_id, sl, gro_clk_div_sel);
      
      rtn |= ten_xfi32x1_stxp0_frac_ctrl_filt_tune_t41(module_id, sl, filt_tune2, filt_tune1);
      rtn |= ten_xfi32x1_stxp0_frac_ctrl_frac_filten_t41(module_id, sl, frac_filten);
      rtn |= ten_xfi32x1_stxp0_frac_ctrl_mmd_inv_en_t41(module_id, sl, mmd_inv_en);
      rtn |= ten_xfi32x1_stxp0_frac_ctrl_frac_en_t41(module_id, sl, CS_ENABLE);

      /* Deassert soft reset */
      rtn |= ten_cupll_reset_t41(module_id, sl, TEN_XFI_CUPLL_RESET_ALL, CS_RESET_DEASSERT);
      
      /* Program CUPLL registers from control block */
      rtn |= ten_xfi_cupll_preloadfint_t41(module_id, sl, preloadfint);
      rtn |= ten_xfi_cupll_preloadffrac_t41(module_id, sl, preloadffrac);
      rtn |= ten_xfi_cupll_pdoutsel_t41(module_id, sl, pdoutsel);
      rtn |= ten_xfi_cupll_countershift_t41(module_id, sl, countershift);
      rtn |= ten_xfi_cupll_counterctrl_t41(module_id, sl, counterctrl);
      rtn |= ten_xfi_cupll_pdoffset_t41(module_id, sl, pdoffset);
      rtn |= ten_xfi_cupll_holdover_t41(module_id, sl, holdoverselect, holdovercount);
      rtn |= ten_xfi_cupll_pdcal_t41(module_id, sl, pdcalsel, pdcaloverride);
      rtn |= ten_xfi_cupll_filtsel_t41(module_id, sl, filtsels, filtself);

      rtn |= ten_xfi_cupll_freq_t41(module_id, sl, TEN_XFI_CUPLL_FREQ_K1F, k1fscale, k1fshift);
      rtn |= ten_xfi_cupll_freq_t41(module_id, sl, TEN_XFI_CUPLL_FREQ_Z1F, z1fscale, z1fshift);
      rtn |= ten_xfi_cupll_freq_t41(module_id, sl, TEN_XFI_CUPLL_FREQ_P1F, p1fscale, p1fshift);
      rtn |= ten_xfi_cupll_freq_t41(module_id, sl, TEN_XFI_CUPLL_FREQ_P2F, p2fscale, p2fshift);
      rtn |= ten_xfi_cupll_freq_t41(module_id, sl, TEN_XFI_CUPLL_FREQ_P3F, p3fscale, p3fshift);
      rtn |= ten_xfi_cupll_freq_t41(module_id, sl, TEN_XFI_CUPLL_FREQ_K1S, k1sscale, k1sshift);
      rtn |= ten_xfi_cupll_freq_t41(module_id, sl, TEN_XFI_CUPLL_FREQ_Z1S, z1sscale, z1sshift);
      rtn |= ten_xfi_cupll_freq_t41(module_id, sl, TEN_XFI_CUPLL_FREQ_P1S, p1sscale, p1sshift);
      rtn |= ten_xfi_cupll_freq_t41(module_id, sl, TEN_XFI_CUPLL_FREQ_P2S, p2sscale, p2sshift);
      rtn |= ten_xfi_cupll_freq_t41(module_id, sl, TEN_XFI_CUPLL_FREQ_P3S, p3sscale, p3sshift);

      /* Bugzilla 35376 Start */
      rtn |= ten_pdcal_ringerrorctrl_t41(tmp_dev_id, resetcount, hiloerroren, fixbubble, timeouten, ringerroren);
      /* Bugzilla 35376 End */
      rtn |= ten_xfi_cupll_ringerrorctrl_t41(module_id, sl, resetcount, hiloerroren, fixbubble, timeouten, ringerroren);
      rtn |= ten_xfi_cupll_sdmode_t41(module_id, sl, sdmode);

      /* Enable CUPLL */
      rtn |= ten_xfi_cupll_sden_t41(module_id, sl, CS_ENABLE);
      
      rtn |= ten_xfi32x1_stxp0_gro_spare_refclk_div_sel_t41(module_id, sl, gro_spare);
      
      /* Reset VCO */
      rtn |= ten_xfi32x1_txvco0_control_init(module_id, sl, CS_RESET_TOGGLE);
                               
      /* Sequence: SD is ok at this point so it isn't toggled, deassert cupll_dig last */
      rtn |= ten_cupll_reset_t41(module_id, sl, TEN_XFI_CUPLL_RESET_LOCKDET,   CS_RESET_ASSERT);
      rtn |= ten_cupll_reset_t41(module_id, sl, TEN_XFI_CUPLL_RESET_GRO,       CS_RESET_ASSERT);
      rtn |= ten_cupll_reset_t41(module_id, sl, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_ASSERT);
      rtn |= ten_cupll_reset_t41(module_id, sl, TEN_XFI_CUPLL_RESET_LOCKDET,   CS_RESET_DEASSERT);
      rtn |= ten_cupll_reset_t41(module_id, sl, TEN_XFI_CUPLL_RESET_GRO,       CS_RESET_DEASSERT);
      rtn |= ten_cupll_reset_t41(module_id, sl, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_DEASSERT);

      /* local force = off */
      rtn |= ten_mpif_cupll_local_force_t41(tmp_dev_id, sl, 2, CS_DISABLE);
      rtn |= ten_mpif_cupll_local_force_t41(tmp_dev_id, sl, 1, CS_ENABLE);
      rtn |= ten_mpif_cupll_local_force_t41(tmp_dev_id, sl, 0, CS_DISABLE);
      
      /* Force-settle timer-value */
      rtn |= ten_mpif_cupll_settle_timer_t41(tmp_dev_id, sl, settle_val);

      /* Charge pump tweaks */
      rtn |= ten_xfi32x1_stxp0_tx_cp_t41(module_id, sl, cptstdn, cpcur1, cpcur0);
    }
  }

  return (rtn);
}

/* Bugzilla 36358  Start */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL STAND ALONE CUPLL CONFIG T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_stand_alone_cupll_config_t41(cs_uint16 module_id,
                                              cs_uint8  slice,
                                              cs_uint8  calibrate,
                                              cs_uint8  source_clean,
                                              cs_uint8  source_jittery,
                                              cs_uint16 rx_div_mux,
                                              double    f_in_clean,
                                              double    f_in_jittery,
                                              double    f_out)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Source Clean                                      */
/*              o Source Jittery                                    */
/*              o RX DIV MUX                                        */
/*              o Frequency In Clean                                */
/*              o Frequency In Jittery                              */
/*              o Frequency Out                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provision Stand Alone CUPLL. This API takes the input and output */
/* frequencies at the input and output pins (or FracDiv) and        */
/* calculates and sets all dividers and muxes in the path.          */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0 = TEN_SLICE0                                                 */
/*   1 = TEN_SLICE1                                                 */
/*   2 = TEN_SLICE2                                                 */
/*   3 = TEN_SLICE3                                                 */
/*                                                                  */
/* The [calibrate] parameter is specified as:                       */
/*   0 = No calibration. Stand alone CUPLL bandwidth will be        */
/*       uncalibrated according to defaults or settings provided    */
/*       in register XFI_CUPLL_PDCAL.                               */
/*   1 = Stand alone CUPLL bandwidth will be calibrated.  Requires  */
/*       PDCAL block to be configured when another first XFI/CUPLL  */
/*       port is configured.                                        */
/*   2 = Stand alone CUPLL bandwidth will be calibrated.  This      */
/*       stand alone CUPLL configuration will also configure the    */
/*       PDCAL block.                                               */
/*       Note: API ten_hl_cupll_calibrate_config_t41 is used to     */
/*       configure the PDCAL block.                                 */
/*       ten_hl_cupll_calibrate_config_t41 should be called         */
/*       only once at the time a first CUPLL or standalone CUPLL    */
/*       is configured.                                             */
/*                                                                  */
/* The [source_clean] parameter is specified as:                    */
/*   The source for the "clean" reference clock.                    */
/*   0 = TX_CLKREF Pins                                             */
/*   1 = AUX_LPTIME_CLKREF Pins                                     */
/*                                                                  */
/* The [source_jittery] parameter is specified as:                  */
/*   The source for the "dirty" phase reference to be cleaned up.   */
/*   0 = TX_CLKREF Pins                                             */
/*   1 = AUX_LPTIME_CLKREF Pins                                     */
/*   2 = System Timing Mode (FracDiv)                               */
/*   3 = Local Force                                                */
/*   4 = RxDiv                                                      */
/*                                                                  */
/* The [rx_div_mux] parameter is specified as:                      */
/*     Only used for source_jittery=4 (RxDiv).                      */
/*     8:1 multiplexer pairs the selected Rx divided clock with     */
/*     the Tx:                                                      */
/*     000 = A side #1                                              */
/*     001 = A side #2                                              */
/*     010 = A side #3                                              */
/*     011 = A side #4                                              */
/*     100 = B side #1                                              */
/*     101 = B side #2                                              */
/*     110 = B side #3                                              */
/*     111 = B side #4                                              */
/*                                                                  */
/* The [f_in_clean] parameter is specified as:                      */
/*   The frequency of the "clean" reference clock, at the CLKREF    */
/*   Pins, in hertz. Typically 400000000.                           */
/*                                                                  */
/* The [f_in_jittery] parameter is specified as:                    */
/*   The frequency of the "dirty" reference clock, at the CLKREF    */
/*   Pins or FracDiv, in hertz.                                     */
/*                                                                  */
/* The [f_out] parameter is specified as:                           */
/*   The frequency of the output clock at the TX_TCLKO pins, in     */
/*   hertz.                                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_status    rtn                    = CS_OK;
  cs_uint16    tmp_dev_id             = TEN_MOD_ID_TO_DEV_ID(module_id);
  double       f_system               = 0.0;

  CS_PRINT("ten_hl_stand_alone_cupll_config_t41:  mod_id=0x%04X, sl=%d\n", module_id, slice);
  CS_PRINT("  source_clean=%d, source_jittery=%d\n", source_clean, source_jittery);
  CS_PRINT("  f_in_clean=%f\n", f_in_clean);
  CS_PRINT("  f_in_jittery=%f\n", f_in_jittery);
  CS_PRINT("  f_out=%f\n", f_out);

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  if (source_clean > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": source_clean out of range: 0..1.");
    return (CS_ERROR);
  }
  if (source_jittery > 4) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": source_jittery out of range: 0..2.");
    return (CS_ERROR);
  }
  if (source_clean == source_jittery) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": source_clean and source_jittery must differ.");
    return (CS_ERROR);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(TEN_MOD_ID_TO_DEV_ID(module_id));
  f_system = pdevcb->sysclock;
  CS_PRINT("sysclk = %f\n", f_system);


  if (source_jittery == 0) {
    /* Set muxes & dividers for dirty reference on TX_CLKREF */
    rtn |= ten_xfi32x1_stxp0_gro_ctrl_refclk_sel_t41(module_id, slice, 0);
  } else if (source_jittery == 1) {
    /* Set muxes & dividers for dirty reference on AUX_LPTIME_CLKREF */
    rtn |= ten_xfi32x1_stxp0_gro_ctrl_refclk_sel_t41(module_id, slice, 1);
  } else if (source_jittery == 2) {
    /* Set muxes & dividers  for dirty reference on FracDiv */
    rtn |= ten_hl_fracdiv_config(0, slice+4, f_system, f_in_jittery);
    /* Set to RX_DIV */
    rtn |= ten_xfi32x1_stxp0_gro_ctrl_refclk_sel_t41(module_id, slice, 8);
    /* Select divided pilot */
    rtn |= ten_mpif_rxdiv_cfg0_mode_t41(tmp_dev_id, slice+4, 2);
    /* Select own pilot */
    rtn |= ten_mpif_rxdiv_cfg0_pilot_t41(tmp_dev_id, slice+4, slice+4);
    /* Divide Pilot by 1 */
    rtn |= ten_mpif_pilot_div(tmp_dev_id, slice+4, 5);
  } else if (source_jittery == 4) {
    /* Set to RX_DIV */
    rtn |= ten_xfi32x1_stxp0_gro_ctrl_refclk_sel_t41(module_id, slice, 8);
    /* Select mode = Rx Controllable Divider */
    rtn |= ten_mpif_rxdiv_cfg0_mode_t41(tmp_dev_id, slice+4, 0);
    /* Select which port to use */
    rtn |= ten_mpif_global_reset_syncdsync(tmp_dev_id, module_id, slice, CS_TX, CS_RESET_DEASSERT);
    rtn |= ten_syncdsynctx_set_configuration_rx_div_mux(module_id, slice, rx_div_mux);
  }

  /* Configure XFI port */
  rtn |= ten_mpif_global_reset_sds_xfi(tmp_dev_id, slice, CS_TX_AND_RX, CS_RESET_ASSERT);
  TEN_MDELAY(20);
  /*rtn |= ten_hl_hsif_config_xfi(module_id, slice, TEN_HSIF_XFI_RATE_GBPS_11__1, TEN_HSIF_XFI_DIV_BY_16_REF, 1);*/
  rtn |= ten_hl_hsif_config_xfi_spare_cupll(module_id, slice, TEN_HSIF_XFI_RATE_GBPS_11__1, TEN_HSIF_XFI_DIV_BY_16_REF, 1); /*Bugzilla 35116*/
  /* Overwrite the port back to MR */
  rtn |= ten_mpif_clock_select_hsif_out(tmp_dev_id, TEN_MOD_ID_TO_MOD_NUM(module_id), slice, CS_TX_AND_RX, 0);
  rtn |= ten_hsif_provision_tx_xfiselect(module_id, slice, 0);
  rtn |= ten_hsif_provision_rx_xfiselect(module_id, slice, 0);
  /* Power down XFI RX */
  rtn |= ten_xfi32x1_srx0_rx_srx_pd(module_id, slice, 1);

  if (source_clean == 0) {
    /* Set muxes for clean reference on TX_CLKREF */
    /* switch XFI internal pilot to external tx ref clock */
    rtn |= ten_xfi32x1_stxp0_tx_config_pilot_sel(module_id, slice, 0); 
    /* loop timing required */
    rtn |= ten_xfi32x1_stxp0_tx_lptime_sel(module_id, slice, 0);
  } else if (source_clean == 1) {
    /* Set muxes for clean reference on AUX_LPTIME_CLKREF */
    /* switch XFI internal pilot to external aux_lptime clock */
    rtn |= ten_xfi32x1_stxp0_tx_config_pilot_sel(module_id, slice, 6); 
    /* loop timing required */
    rtn |= ten_xfi32x1_stxp0_tx_lptime_sel(module_id, slice, 1);
  }

  /* Program CUPLL */
  /* If local mode is specified f_in_jittery should be don't care */
  if (source_jittery == 3) {
    rtn |= ten_set_cb_stand_alone_cupll_t41(tmp_dev_id, f_out/64, 1, 64,
                                            f_in_clean, 0x320, 0, f_out);
  } else {
    rtn |= ten_set_cb_stand_alone_cupll_t41(tmp_dev_id, f_in_jittery, 1, 64,
                                            f_in_clean, 0x320, 0, f_out);
  }
  rtn |= ten_hl_cupll_config_t41(module_id, slice);
  if (calibrate == 2) {
    rtn |= ten_hl_cupll_calibrate_config_t41(tmp_dev_id, slice);
  }
  if ((calibrate == 1) || (calibrate == 2)) {
    rtn |= ten_xfi_cupll_pdcal_t41(module_id, slice, 0, 0x080);
  }

  /* If local mode is specified */
  if (source_jittery == 3) {
    rtn |= ten_mpif_cupll_local_force_t41(tmp_dev_id, slice, 2, CS_DISABLE);
    rtn |= ten_mpif_cupll_local_force_t41(tmp_dev_id, slice, 1, CS_DISABLE);
    rtn |= ten_mpif_cupll_local_force_t41(tmp_dev_id, slice, 0, CS_ENABLE);
  }
  
  /* Reset and settle the CUPLL */
  rtn |= ten_cupll_reset_t41(module_id, slice, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE);
  rtn |= ten_mpif_cupll_settle_force_t41(tmp_dev_id, slice, 2, CS_ENABLE);
  rtn |= ten_mpif_cupll_settle_force_t41(tmp_dev_id, slice, 2, CS_DISABLE);

  return (rtn);
}
/* Bugzilla 36358  End */

/********************************************************************/
/* $rtn_hdr_start  CUPLL CALIBRATE CONFIG T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_cupll_calibrate_config_t41(cs_uint16 dev_id,
                                            cs_uint8  slice)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures PDCAL block to use the reference specified by slice.  */
/*                                                                  */
/*  The [slice] parameter is specified as:                          */
/*    TEN_SLICE0 (0),                                               */
/*    TEN_SLICE1 (1),                                               */
/*    TEN_SLICE2 (2),                                               */
/*    TEN_SLICE3 (3)                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status       rtn    = CS_OK;
  ten_dev_cb_t    *pdevcb;
  const double    period = 10e-12;
  cs_uint32       scale, scale_tmp;
  cs_uint32 freq;
  const cs_uint32 freq_max = 400000000;
  /* Bug 29800: Subrate line rates require freq/2 for freqs approaching 400MHz */
  cs_boolean div_freq_by_2            = FALSE;    
  cs_uint16 tmp_mod_id                = TEN_DEV_ID_TO_MOD_ID(dev_id, TEN_MODULE_B);   


  CS_PRINT("ten_hl_cupll_calibrate_config_t41:  dev_id=0x%04X, slice=%d\n",
            dev_id, slice);
  
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

   /* Send refclk to fastclk output */
   rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_fastdiv_sel(tmp_mod_id, slice, 6);

   /* PDcounter = 4, CounterShift = 1, SignInv = 0, bwsel2 = 0
      CounterCtrl = 3, bwsel1 = 0, skip = 00, monsel = 1, PDen = 1
   ten_reg_write(0,0x03e1,0x48c3); */
   rtn |= ten_pdcal_ctrl_t41(dev_id, 4, 1, 0, 0, 3, 0, 0, 0, 1, 1);

   /* Refsel = slice, CLKINV = 0, mode = 1, pd =0
   my $temp = 0x0010+0x1000*$slice;
   ten_reg_write(0,0x03e6,$temp); */
   rtn |= ten_pdcal_gro_ctrl_t41(dev_id, slice, 0, 1, 0);

   /* #PDCAL_REFDIV
   ten_reg_write(0,0x03e7,0x0100); */
   /* Default value */
   
   /* ten_reg_write(0,0x03e8,0x00C0); */
   rtn |= ten_pdcal_gro_spare_t41(dev_id, 0xC0);
   
   /* #PDCAL_RESET
   ten_reg_write(0,0x03e0,0x000F);
   ten_reg_write(0,0x03e0,0x000D);
   ten_reg_write(0,0x03e0,0x0000); */
   rtn |= ten_pdcal_reset_seq_t41(dev_id);

   /* #PDCAL_SCALE
   my $scale = int(1/($fref*$period));
   ten_reg_write(0,0x03e3,$scale); */

  /* Bugzilla 40721: Only div2 for subrates, not 8gfc */
  freq      = pdevcb->cupll_cb.freq;

  if ((freq > freq_max) ||
      /* Bugzilla 40204 Start */
      /* Bugzilla 40721: Only div2 for subrates, not 8gfc */
      ((pdevcb->cupll_cb.subrate_div > 0) && (pdevcb->cupll_cb.standalone != 1))) {
      /* Bugzilla 40204 End */
    div_freq_by_2 = TRUE;
  }

   scale_tmp = (cs_uint32) 1/(freq * period);
   scale     = div_freq_by_2 ? (scale_tmp*2) : scale_tmp;
   rtn |= ten_pdcal_scale_t41(dev_id, scale);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  CUPLL LOCKDET FILTER T41                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_cupll_lockdet_filter_t41(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 stable_period)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o STABLE PERIOD                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the Lock Detect interrupt filter.                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stable_period]                                                */
/*   Specifies the period of time where lock must be asserted       */
/*     before reporting lock via interrupt.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI_CUPLL_LOCKDET_FILTER_t tmp_cupll_lockdet_filter;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cupll_lockdet_filter.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_FILTER));
      tmp_cupll_lockdet_filter.bf.STABLE_PERIOD = stable_period;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_FILTER), tmp_cupll_lockdet_filter.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  CUPLL LOCKDET INTSTATUS FILTLOCKS T41            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cupll_lockdet_intstatus_filt_locks_t41(cs_uint16 module_id, 
                                                     cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns current state of the lock filter FSM.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI_CUPLL_LOCKDET_INTSTATUS_t tmp_cupll_lockdet_intstatus;
  T41_t *pDev = NULL;
  cs_uint16 locks = 1;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cupll_lockdet_intstatus.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_INTSTATUS));
      locks &= tmp_cupll_lockdet_intstatus.bf.FILT_LOCKs;
    }
  }
  return (locks);
}

/********************************************************************/
/* $rtn_hdr_start  CUPLL LOCKDET INTSTATUS BAD VCO CLKS T41         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cupll_lockdet_intstatus_bad_vco_clks_t41(cs_uint16 module_id, 
                                                       cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns current state of the BAD_VCO_CLK interrupt.              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI_CUPLL_LOCKDET_INTSTATUS_t tmp_cupll_lockdet_intstatus;
  T41_t *pDev = NULL;
  cs_uint16 bad_vco_clks = 1;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cupll_lockdet_intstatus.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_INTSTATUS));
      bad_vco_clks &= tmp_cupll_lockdet_intstatus.bf.BAD_VCO_CLKs;
    }
  }
  return (bad_vco_clks);
}

/********************************************************************/
/* $rtn_hdr_start  CUPLL LOCKDET INTSTATUS LOCKS T41                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_cupll_lockdet_intstatus_locks_t41(cs_uint16 module_id, 
                                                cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns current lock state of the Lock Detector.                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_XFI_CUPLL_LOCKDET_INTSTATUS_t tmp_cupll_lockdet_intstatus;
  T41_t *pDev = NULL;
  cs_uint16 locks = 1;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cupll_lockdet_intstatus.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, LOCKDET_INTSTATUS));
      locks &= tmp_cupll_lockdet_intstatus.bf.LOCKs;
    }
  }
  return (locks);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL RESET T41                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XFI                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_cupll_reset_t41(cs_uint16         module_id,
                              cs_uint8          slice, 
                              cs_uint8          select,
                              cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control CUPLL Resets.                                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [select] is specified as:                                      */
/*     TEN_XFI_CUPLL_RESET_CUPLL_DIG = 0                            */
/*     TEN_XFI_CUPLL_RESET_GRO       = 1                            */
/*     TEN_XFI_CUPLL_RESET_LOCKDET   = 2                            */
/*     TEN_XFI_CUPLL_RESET_SDRESET   = 3                            */
/*     TEN_XFI_CUPLL_RESET_ALL       = 0xFF                         */
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
  TEN_XFI_CUPLL_RESET_t tmp_cupll_reset;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  if ((select > TEN_XFI_CUPLL_RESET_SDRESET) && (select != TEN_XFI_CUPLL_RESET_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cupll_reset.wrd          = 0;
      tmp_cupll_reset.bf.SDreset   = ((select == TEN_XFI_CUPLL_RESET_SDRESET)   || (select == TEN_XFI_CUPLL_RESET_ALL));
      tmp_cupll_reset.bf.lockdet   = ((select == TEN_XFI_CUPLL_RESET_LOCKDET)   || (select == TEN_XFI_CUPLL_RESET_ALL));
      tmp_cupll_reset.bf.gro       = ((select == TEN_XFI_CUPLL_RESET_GRO)       || (select == TEN_XFI_CUPLL_RESET_ALL));
      tmp_cupll_reset.bf.cupll_dig = ((select == TEN_XFI_CUPLL_RESET_CUPLL_DIG) || (select == TEN_XFI_CUPLL_RESET_ALL));
      ten_reset_action(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, RESET), tmp_cupll_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL PDOUTSEL                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_pdoutsel_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 pdoutsel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PDoutsel                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects which signal will be output to the PDOUT register. This  */
/* provides monitoring of two different points inside the phase     */
/* calculator.                                                      */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [xsel] parameter is specified as:                            */
/*   0 = Raw phase number.                                          */
/*   1 = Offset corrected phase number.                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_cfg.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, CFG));
      tmp_xfi_cupll_cfg.bf.PDoutsel = pdoutsel;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, CFG), tmp_xfi_cupll_cfg.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL COUNTERSHIFT                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_countershift_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 countershift)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o CounterShift                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [countershift] parameter is specified as:                    */
/*   0                                                              */
/*   1                                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_cfg.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, CFG));
      tmp_xfi_cupll_cfg.bf.CounterShift = countershift;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, CFG), tmp_xfi_cupll_cfg.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL COUNTERCTRL                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_counterctrl_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 counterctrl)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o CounterCtrl                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [counterctrl] parameter is specified as:                     */
/*   0x0..0x3                                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_cfg.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, CFG));
      tmp_xfi_cupll_cfg.bf.CounterCtrl = counterctrl;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, CFG), tmp_xfi_cupll_cfg.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL PDOFFSET                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_pdoffset_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint32 pdoffset)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PDoutsel                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* The phase detector output has an offset added to it to move the  */
/* locked phase away from 0. This is required because the phase     */
/* detector is very non-linear near zero. The gain of the phase     */
/* detector will be controlled better at phases away from 0.        */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [pdoffset] parameter is specified as:                        */
/*   0x00000000..0x0007FFFF                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_pdoffset0.wrd =  pdoffset        & 0x0000FFFF;
      tmp_xfi_cupll_pdoffset1.wrd = (pdoffset >> 16) & 0x00000007;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL HOLDOVER                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_holdover_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 holdover_select,
                                     cs_uint16 holdover_count)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o HoldoverSelect                                    */
/*              o HoldoverCount                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the fields for the XFI_CUPLL_HOLDOVER register.             */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [holdover_select] parameter is specified as:                 */
/*   Selects which of the 4 Holdover storage registers is used when */
/*   a holdover event is detected.                                  */
/*   00 Reg1 (least delay)                                          */
/*   01 Reg2                                                        */
/*   10 Reg3                                                        */
/*   11 Reg4 (most delay)                                           */
/*                                                                  */
/* The [holdover_count] parameter is specified as:                  */
/*   Determines the delay between samples being shifted into the    */
/*   holdover memory. For a nominal reference frequency of 312.5MHz */
/*   the maximum delay is 100s. Delay = 16*2^HoldoverCount/ Fref    */
/*   0x00..0x1F                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_holdover.wrd = 0;
      tmp_xfi_cupll_holdover.bf.HoldoverSelect = holdover_select;
      tmp_xfi_cupll_holdover.bf.HoldoverCount  = holdover_count;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, HOLDOVER), tmp_xfi_cupll_holdover.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL PDCAL                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_pdcal_t41(cs_uint16 module_id,
                                  cs_uint8  slice, 
                                  cs_uint16 pdcalsel,
                                  cs_uint16 pdcaloverride)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o pdcalsel                                          */
/*              o pdcaloverride                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the fields for the XFI_CUPLL_PDCAL register.                */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [pdcalsel] parameter is specified as:                        */
/*   Determine where to get the calibration multiplier from. This   */
/*   can come either from the calibration block or from             */
/*   PDcalOverride.                                                 */
/*   1 = PDcalOverride Register                                     */
/*   0 = Calibration Block                                          */
/*                                                                  */
/* The [pdcaloverride] parameter is specified as:                   */
/*   Over ride value for the calibration word. Selected with        */
/*   PDcalSel.                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_pdcal.wrd = 0;
      tmp_xfi_cupll_pdcal.bf.PDcalSel = pdcalsel;
      tmp_xfi_cupll_pdcal.bf.PDcalOverride  = pdcaloverride;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PDCAL), tmp_xfi_cupll_pdcal.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL FILTSEL                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_filtsel_t41(cs_uint16 module_id,
                                    cs_uint8  slice, 
                                    cs_uint16 filtsels,
                                    cs_uint16 filtself)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o FiltSelS                                          */
/*              o FiltSelF                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the fields for the XFI_CUPLL_FILTSEL register.              */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [filtsels] parameter is specified as:                        */
/*   The loop filter consists of an integrator with zero followed   */
/*   by 3 lowpass filters. FiltSelF selects which filter output to  */
/*   use for the final output of the loop filter. This control is   */
/*   active in 'Slow' mode.                                         */
/*   0 = Integrator only                                            */
/*   1 = lowpass filter 1                                           */
/*   2 = lowpass filter 2                                           */
/*   3 = lowpass filter 3                                           */
/*                                                                  */
/* The [filtself] parameter is specified as:                        */
/*   The loop filter consists of an integrator with zero followed   */
/*   by 3 lowpass filters. FiltSelF selects which filter output to  */
/*   use for the final output of the loop filter. This control is   */
/*   active in 'Fast' mode.                                         */
/*   0 = Integrator only                                            */
/*   1 = lowpass filter 1                                           */
/*   2 = lowpass filter 2                                           */
/*   3 = lowpass filter 3                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_FILTSEL_t tmp_xfi_cupll_filtsel;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_filtsel.wrd = 0;
      tmp_xfi_cupll_filtsel.bf.FiltSelS = filtsels;
      tmp_xfi_cupll_filtsel.bf.FiltSelF = filtself;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, FILTSEL), tmp_xfi_cupll_filtsel.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL FREQUENCY                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_freq_t41(cs_uint16 module_id,
                                 cs_uint8  slice, 
                                 cs_uint16 select,
                                 cs_uint16 scale,
                                 cs_uint16 shift)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/*              o Scale                                             */
/*              o Shift                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the fields for the frequency registers.                     */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [select] parameter is specified as:                          */
/*   Selects the CUPLL Scale and Shift to write.                    */
/*   TEN_XFI_CUPLL_FREQ_K1F  = 0                                    */
/*   TEN_XFI_CUPLL_FREQ_Z1F  = 1                                    */
/*   TEN_XFI_CUPLL_FREQ_P1F  = 2                                    */
/*   TEN_XFI_CUPLL_FREQ_P2F  = 3                                    */
/*   TEN_XFI_CUPLL_FREQ_P3F  = 4                                    */
/*   TEN_XFI_CUPLL_FREQ_K1S  = 5                                    */
/*   TEN_XFI_CUPLL_FREQ_Z1S  = 6                                    */
/*   TEN_XFI_CUPLL_FREQ_P1S  = 7                                    */
/*   TEN_XFI_CUPLL_FREQ_P2S  = 8                                    */
/*   TEN_XFI_CUPLL_FREQ_P3S  = 9                                    */
/*                                                                  */
/* The [scale] parameter is specified as:                           */
/*   The gain as a floating point number of the form                */
/*     scale[4].scale[3:0] * 2 ^ (-shift)                           */
/*   0x00..0x1F                                                     */
/*                                                                  */
/* The [shift] parameter is specified as:                           */
/*   See scale for the equation                                     */
/*   0x00..0x1F                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_XFI_CUPLL_K1F_t tmp_cupll_k1f;
  TEN_XFI_CUPLL_Z1F_t tmp_cupll_z1f;
  TEN_XFI_CUPLL_P1F_t tmp_cupll_p1f;
  TEN_XFI_CUPLL_P2F_t tmp_cupll_p2f;
  TEN_XFI_CUPLL_P3F_t tmp_cupll_p3f;
  TEN_XFI_CUPLL_K1S_t tmp_cupll_k1s;
  TEN_XFI_CUPLL_Z1S_t tmp_cupll_z1s;
  TEN_XFI_CUPLL_P1S_t tmp_cupll_p1s;
  TEN_XFI_CUPLL_P2S_t tmp_cupll_p2s;
  TEN_XFI_CUPLL_P3S_t tmp_cupll_p3s;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      switch (select) {
        case (TEN_XFI_CUPLL_FREQ_K1F):
          tmp_cupll_k1f.wrd = 0;
          tmp_cupll_k1f.bf.K1Fscale = scale;
          tmp_cupll_k1f.bf.K1Fshift = shift;
          TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, K1F), tmp_cupll_k1f.wrd);
          break;
        case (TEN_XFI_CUPLL_FREQ_Z1F):
          tmp_cupll_z1f.wrd = 0;
          tmp_cupll_z1f.bf.Z1Fscale = scale;
          tmp_cupll_z1f.bf.Z1Fshift = shift;
          TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, Z1F), tmp_cupll_z1f.wrd);
          break;
        case (TEN_XFI_CUPLL_FREQ_P1F):
          tmp_cupll_p1f.wrd = 0;
          tmp_cupll_p1f.bf.P1Fscale = scale;
          tmp_cupll_p1f.bf.P1Fshift = shift;
          TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P1F), tmp_cupll_p1f.wrd);
          break;
        case (TEN_XFI_CUPLL_FREQ_P2F):
          tmp_cupll_p2f.wrd = 0;
          tmp_cupll_p2f.bf.P2Fscale = scale;
          tmp_cupll_p2f.bf.P2Fshift = shift;
          TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P2F), tmp_cupll_p2f.wrd);
          break;
        case (TEN_XFI_CUPLL_FREQ_P3F):
          tmp_cupll_p3f.wrd = 0;
          tmp_cupll_p3f.bf.P3Fscale = scale;
          tmp_cupll_p3f.bf.P3Fshift = shift;
          TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P3F), tmp_cupll_p3f.wrd);
          break;
        case (TEN_XFI_CUPLL_FREQ_K1S):
          tmp_cupll_k1s.wrd = 0;
          tmp_cupll_k1s.bf.K1Sscale = scale;
          tmp_cupll_k1s.bf.K1Sshift = shift;
          TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, K1S), tmp_cupll_k1s.wrd);
          break;
        case (TEN_XFI_CUPLL_FREQ_Z1S):
          tmp_cupll_z1s.wrd = 0;
          tmp_cupll_z1s.bf.Z1Sscale = scale;
          tmp_cupll_z1s.bf.Z1Sshift = shift;
          TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, Z1S), tmp_cupll_z1s.wrd);
          break;
        case (TEN_XFI_CUPLL_FREQ_P1S):
          tmp_cupll_p1s.wrd = 0;
          tmp_cupll_p1s.bf.P1Sscale = scale;
          tmp_cupll_p1s.bf.P1Sshift = shift;
          TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P1S), tmp_cupll_p1s.wrd);
          break;
        case (TEN_XFI_CUPLL_FREQ_P2S):
          tmp_cupll_p2s.wrd = 0;
          tmp_cupll_p2s.bf.P2Sscale = scale;
          tmp_cupll_p2s.bf.P2Sshift = shift;
          TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P2S), tmp_cupll_p2s.wrd);
          break;
        case (TEN_XFI_CUPLL_FREQ_P3S):
          tmp_cupll_p3s.wrd = 0;
          tmp_cupll_p3s.bf.P3Sscale = scale;
          tmp_cupll_p3s.bf.P3Sshift = shift;
          TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, P3S), tmp_cupll_p3s.wrd);
          break;
        default:
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..9");
          rtn = CS_ERROR;
          break;
      }
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL PRELOADFINT                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_preloadfint_t41(cs_uint16 module_id,
                                        cs_uint8  slice, 
                                        cs_uint16 preloadfint)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PreloadFint                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes the contents of the the XFI_CUPLL_PRELOADFINT register.   */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [preloadfint] parameter is specified as:                     */
/*   This is the integer part of the divide ratio. This value is    */
/*   used when the fractional synthesizer is used in standalone     */
/*   mode. It is also the nominal divide ratio when the clean-up    */
/*   PLL is in operation.                                           */
/*     PreloadFint + PreloadFfrac/2^32 = Fline/Fref.                */
/*   Where Fline is the serial rate and Fref is the reference       */
/*   frequency for the fractional synthesizer.                      */
/*   0x0000..0x007F                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_preloadfint.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PRELOADFINT));
      tmp_xfi_cupll_preloadfint.bf.PreloadFint = preloadfint;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL PRELOADFFRAC                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_preloadffrac_t41(cs_uint16 module_id,
                                         cs_uint8  slice, 
                                         cs_uint32 preloadffrac)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PreloadFfrac                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This is the fractional part of the divide ratio. This value is   */
/* used when the fractional synthesizer is used in standalone mode. */
/* It is also the nominal divide ratio when the clean-up PLL is in  */
/* operation.                                                       */
/*     PreloadFint + PreloadFfrac/2^32 = Fline/Fref.                */
/* Where Fline is the serial rate and Fref is the reference         */
/* frequency for the fractional synthesizer.                        */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [preloadffrac] parameter is specified as:                    */
/*   0x00000000..0xFFFFFFFF                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_preloadffrac0.bf.PreloadFfrac0 = preloadffrac & 0x0000FFFF;
      tmp_xfi_cupll_preloadffrac1.bf.PreloadFfrac1 = preloadffrac >> 16;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL SDEN                                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_sden_t41(cs_uint16 module_id,
                                 cs_uint8  slice, 
                                 cs_ctl_t  sden)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SDen                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enable Clean-up PLL.                                             */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [sden] parameter is specified as:                            */
/*   0 = CS_DISABLE                                                 */
/*   1 = CS_ENABLE                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_sd_cfg.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, SD_CFG));
      tmp_xfi_cupll_sd_cfg.bf.SDen = sden;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL SDMODE                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_sdmode_t41(cs_uint16 module_id,
                                   cs_uint8  slice, 
                                   cs_uint16 sdmode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SDmode                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Sigma Delta Mode.                                            */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [sden] parameter is specified as:                            */
/*   000 First order                                                */
/*   001 MASH11                                                     */
/*   010 MASH12                                                     */
/*   011 MASH121                                                    */
/*   1XX Reserved                                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_sd_cfg.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, SD_CFG));
      tmp_xfi_cupll_sd_cfg.bf.SDmode = sdmode;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CUPLL RINGERRORCTRL                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xfi_cupll_ringerrorctrl_t41(cs_uint16 module_id,
                                          cs_uint16 slice, 
                                          cs_uint16 resetcount, 
                                          cs_uint16 hiloerroren, 
                                          cs_uint16 fixbubble, 
                                          cs_uint16 timeouten, 
                                          cs_uint16 ringerroren)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o ResetCount                                        */
/*              o hiloErrorEn                                       */
/*              o fixBubble                                         */
/*              o TimeoutEn                                         */
/*              o RingErrorEn                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set XFI_CUPLL_RingErrorCtrl register.                            */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [resetcount] parameter is specified as:                      */
/*   Defines how long reset is held when an error condition is      */
/*   detected in the GRO.                                           */
/*   0x00..0xFF                                                     */
/*                                                                  */
/* The [hiloerroren] parameter is specified as:                     */
/*   1 = Turns on the hiloErrorEn.                                  */
/*                                                                  */
/* The [fixbubble] parameter is specified as:                       */
/*   1 = Turns on the bubble correction circuitry.                  */
/*                                                                  */
/* The [timeouten] parameter is specified as:                       */
/*   1 = Enables the timeout circuitry that checks to see if error  */
/*       conditions are persisting in the ring.                     */
/*                                                                  */
/* The [ringerroren] parameter is specified as:                     */
/*   1 = Turns on the state machine to reset the GRO when an error  */
/*       state is detected.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_XFI_CUPLL_RingErrorCtrl_t tmp_xfi_cupll_ringerrorctrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xfi_cupll_ringerrorctrl.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, RingErrorCtrl));
      tmp_xfi_cupll_ringerrorctrl.bf.ResetCount  = resetcount;
      tmp_xfi_cupll_ringerrorctrl.bf.hiloErrorEn = hiloerroren;
      tmp_xfi_cupll_ringerrorctrl.bf.fixBubble   = fixbubble;
      tmp_xfi_cupll_ringerrorctrl.bf.TimeoutEn   = timeouten;
      tmp_xfi_cupll_ringerrorctrl.bf.RingErrorEn = ringerroren;
      TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, sl, RingErrorCtrl), tmp_xfi_cupll_ringerrorctrl.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PDCAL RESET SEQUENCE T41                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PDCAL                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pdcal_reset_seq_t41(cs_uint16  dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs reset sequence on PDCAL block.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PDCAL_PDCAL_RESET_t tmp_pdcal_reset;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_PDCAL);

  tmp_pdcal_reset.wrd = 0;

  tmp_pdcal_reset.bf.preset2     = 1;
  tmp_pdcal_reset.bf.preset1     = 1;
  tmp_pdcal_reset.bf.reset_GRO   = 1;
  tmp_pdcal_reset.bf.reset_pdcal = 1;
  TEN_REG_WRITE(TEN_PDCAL_REG_ADDR(pDev, PDCAL_RESET), tmp_pdcal_reset.wrd);

  tmp_pdcal_reset.bf.preset2     = 1;
  tmp_pdcal_reset.bf.preset1     = 1;
  tmp_pdcal_reset.bf.reset_GRO   = 0;
  tmp_pdcal_reset.bf.reset_pdcal = 1;
  TEN_REG_WRITE(TEN_PDCAL_REG_ADDR(pDev, PDCAL_RESET), tmp_pdcal_reset.wrd);

  tmp_pdcal_reset.bf.preset2     = 0;
  tmp_pdcal_reset.bf.preset1     = 0;
  tmp_pdcal_reset.bf.reset_GRO   = 0;
  tmp_pdcal_reset.bf.reset_pdcal = 0;
  TEN_REG_WRITE(TEN_PDCAL_REG_ADDR(pDev, PDCAL_RESET), tmp_pdcal_reset.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_PDCAL);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PDCAL CONTROL T41                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PDCAL                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pdcal_ctrl_t41(cs_uint16 dev_id,
                             cs_uint16 PDcounter,
                             cs_uint16 CounterShift,
                             cs_uint16 SignInv,
                             cs_uint16 bwsel2,
                             cs_uint16 CounterCtrl,
                             cs_uint16 bwsel1,
                             cs_uint16 skip2,
                             cs_uint16 skip1,
                             cs_uint16 monSel,
                             cs_uint16 PDen)
/* INPUTS     : o Device Id                                         */
/*              o PDcounter                                         */
/*              o CounterShift                                      */
/*              o SignInv                                           */
/*              o bwsel2                                            */
/*              o CounterCtrl                                       */
/*              o bwsel1                                            */
/*              o skip2                                             */
/*              o skip1                                             */
/*              o monSel                                            */
/*              o PDen                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes PDCAL_PDCAL_CTRL register.                                */
/*                                                                  */
/* The [PDcounter] parameter is specified as:                       */
/*   0x0..0xF                                                       */
/*                                                                  */
/* The [CounterShift] parameter is specified as:                    */
/*   0..1                                                           */
/*                                                                  */
/* The [SignInv] parameter is specified as:                         */
/*   0..1                                                           */
/*                                                                  */
/* The [bwsel2] parameter is specified as:                          */
/*   0x0..0x3                                                       */
/*                                                                  */
/* The [CounterCtrl] parameter is specified as:                     */
/*   0x0..0x3                                                       */
/*                                                                  */
/* The [bwsel1] parameter is specified as:                          */
/*   0x0..0x3                                                       */
/*                                                                  */
/* The [skip2] parameter is specified as:                           */
/*   0..1                                                           */
/*                                                                  */
/* The [skip1] parameter is specified as:                           */
/*   0..1                                                           */
/*                                                                  */
/* The [monSel] parameter is specified as:                          */
/*   0..1                                                           */
/*                                                                  */
/* The [PDen] parameter is specified as:                            */
/*   0..1                                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PDCAL_PDCAL_CTRL_t tmp_pdcal_ctrl;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_PDCAL);

  tmp_pdcal_ctrl.wrd = 0;

  tmp_pdcal_ctrl.bf.PDcounter    = PDcounter;
  tmp_pdcal_ctrl.bf.CounterShift = CounterShift;
  tmp_pdcal_ctrl.bf.SignInv      = SignInv;
  tmp_pdcal_ctrl.bf.bwsel2       = bwsel2;
  tmp_pdcal_ctrl.bf.CounterCtrl  = CounterCtrl;
  tmp_pdcal_ctrl.bf.bwsel1       = bwsel1;
  tmp_pdcal_ctrl.bf.skip2        = skip2;
  tmp_pdcal_ctrl.bf.skip1        = skip1;
  tmp_pdcal_ctrl.bf.monSel       = monSel;
  tmp_pdcal_ctrl.bf.PDen         = PDen;
  TEN_REG_WRITE(TEN_PDCAL_REG_ADDR(pDev, PDCAL_CTRL), tmp_pdcal_ctrl.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_PDCAL);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PDCAL SCALE T41                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PDCAL                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pdcal_scale_t41(cs_uint16 dev_id,
                              cs_uint32 scale)
/* INPUTS     : o Device Id                                         */
/*              o Scale                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes PDCAL_PDCAL_SCALE registers.                              */
/*                                                                  */
/* The [scale] parameter is specified as:                           */
/*   0x0000_0000..0x0003_FFFF                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PDCAL_PDCAL_SCALE0_t tmp_pdcal_scale0;
  TEN_PDCAL_PDCAL_SCALE1_t tmp_pdcal_scale1;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_PDCAL);

  tmp_pdcal_scale0.wrd =  scale        & 0x0000FFFF;
  tmp_pdcal_scale1.wrd = (scale >> 16) & 0x00000003;
  TEN_REG_WRITE(TEN_PDCAL_REG_ADDR(pDev, PDCAL_SCALE0), tmp_pdcal_scale0.wrd);
  TEN_REG_WRITE(TEN_PDCAL_REG_ADDR(pDev, PDCAL_SCALE1), tmp_pdcal_scale1.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_PDCAL);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PDCAL GRO CONTROL T41                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PDCAL                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pdcal_gro_ctrl_t41(cs_uint16 dev_id,
                                 cs_uint16 RefSel,
                                 cs_uint16 CLKINV,
                                 cs_uint16 mode,
                                 cs_uint16 pd)
/* INPUTS     : o Device Id                                         */
/*              o RefSel                                            */
/*              o CLKINV                                            */
/*              o mode                                              */
/*              o pd                                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes PDCAL_GRO_CTRL register.                                  */
/*                                                                  */
/* The [RefSel] parameter is specified as:                          */
/*   Selects which reference frequency to use as Fin.               */
/*   00 Use reference from XFI1.                                    */
/*   01 Use reference from XFI2.                                    */
/*   10 Use reference from XFI3.                                    */
/*   11 Use reference from XFI4.                                    */
/*                                                                  */
/* The [CLKINV] parameter is specified as:                          */
/*   Used to invert the clock in case of a clock edge mistake at    */
/*   the analog/digital interface. Should always be '0'.            */
/*   0..1                                                           */
/*                                                                  */
/* The [mode] parameter is specified as:                            */
/*   Select whether to work in phase detector mode or period        */
/*   measurement mode. In the calibration block this should always  */
/*   be set to '0'.                                                 */
/*   0..1                                                           */
/*                                                                  */
/* The [pd] parameter is specified as:                              */
/*   Power Down of the analog portion of the phase detector.        */
/*   1 Powered Down                                                 */
/*   0 Running                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PDCAL_GRO_CTRL_t tmp_gro_ctrl;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_PDCAL);

  tmp_gro_ctrl.wrd = 0;

  tmp_gro_ctrl.bf.RefSel = RefSel;
  tmp_gro_ctrl.bf.CLKINV = CLKINV;
  tmp_gro_ctrl.bf.mode   = mode;
  tmp_gro_ctrl.bf.pd     = pd;
  TEN_REG_WRITE(TEN_PDCAL_REG_ADDR(pDev, GRO_CTRL), tmp_gro_ctrl.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_PDCAL);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PDCAL GRO REFDIV T41                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PDCAL                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pdcal_gro_refdiv_t41(cs_uint16 dev_id,
                                   cs_uint16 RefDiv)
/* INPUTS     : o Device Id                                         */
/*              o RefDiv                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes PDCAL_GRO_REFDIV register. Controls a divider on the      */
/* input clock. The frequency of the clock whose period will be     */
/* measured will be:                                                */
/*                 Fmeas = Fin/RefDiv                               */
/*                                                                  */
/* The [RefDiv] parameter is specified as:                          */
/*   0x00..0xFF                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PDCAL_GRO_REFDIV_t tmp_pdcal_gro_refdiv;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_PDCAL);

  tmp_pdcal_gro_refdiv.wrd       = 0;
  tmp_pdcal_gro_refdiv.bf.RefDiv = RefDiv;
  TEN_REG_WRITE(TEN_PDCAL_REG_ADDR(pDev, GRO_REFDIV), tmp_pdcal_gro_refdiv.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_PDCAL);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PDCAL GRO SPARE T41                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PDCAL                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pdcal_gro_spare_t41(cs_uint16 dev_id,
                                   cs_uint16 spare)
/* INPUTS     : o Device Id                                         */
/*              o spare                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes PDCAL_GRO_SPARE register.                                 */
/*                                                                  */
/* The [spare] parameter is specified as:                           */
/*   0x00..0xFF                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PDCAL_GRO_SPARE_t tmp_pdcal_gro_spare;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_PDCAL);

  tmp_pdcal_gro_spare.wrd       = 0;
  tmp_pdcal_gro_spare.bf.spare  = spare;
  TEN_REG_WRITE(TEN_PDCAL_REG_ADDR(pDev, GRO_SPARE), tmp_pdcal_gro_spare.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_PDCAL);

  return (CS_OK);
}

/* Bugzilla 35376 Start */
/********************************************************************/
/* $rtn_hdr_start  PDCAL RING ERROR CONTROL T41                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PDCAL                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pdcal_ringerrorctrl_t41(cs_uint16 dev_id,
                                      cs_uint16 ResetCount,
                                      cs_uint16 hiloErrorEn,
                                      cs_uint16 fixBubble,
                                      cs_uint16 TimeoutEn,
                                      cs_uint16 RingErrorEn)
/* INPUTS     : o Device Id                                         */
/*              o Reset Count                                       */
/*              o Hilo Error Enable                                 */
/*              o Fix Bubble                                        */
/*              o Timeout Enable                                    */
/*              o Ring Error Enable                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the contents of the PDCAL_RingErrorCtrl register.           */
/*                                                                  */
/* The [ResetCount] parameter is specified as:                      */
/* Defines how long reset is held when an error condition is        */
/* detected in the GRO.                                             */
/*   0x00..0xFF                                                     */
/*                                                                  */
/* The [hiloErrorEn] parameter is specified as:                     */
/*   0                                                              */
/*   1 = Turns on the hiloErrorEn.                                  */
/*                                                                  */
/* The [fixBubble] parameter is specified as:                       */
/*   0                                                              */
/*   1 = Turns on the bubble correction circuitry.                  */
/*                                                                  */
/* The [TimeoutEn] parameter is specified as:                       */
/*   0                                                              */
/*   1 = Enables the timeout circuitry that checks to see if error  */
/*       conditions are persisting in the ring.                     */
/*                                                                  */
/* The [RingErrorEn] parameter is specified as:                     */
/*   0                                                              */
/*   1 = Turns on the state machine to reset the GRO when an error  */
/*       state is detected.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PDCAL_RingErrorCtrl_t tmp_reg;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_PDCAL);

  tmp_reg.wrd = TEN_REG_READ(TEN_PDCAL_REG_ADDR(pDev, RingErrorCtrl));
  tmp_reg.bf.ResetCount   = ResetCount;
  tmp_reg.bf.hiloErrorEn  = hiloErrorEn;
  tmp_reg.bf.fixBubble    = fixBubble;
  tmp_reg.bf.TimeoutEn    = TimeoutEn;
  tmp_reg.bf.RingErrorEn  = RingErrorEn;
  TEN_REG_WRITE(TEN_PDCAL_REG_ADDR(pDev, RingErrorCtrl), tmp_reg.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_PDCAL);

  return (CS_OK);
}
/* Bugzilla 35376 End */

/* The following is auto-generated from cupll_config.xml; DO NOT MODIFY */

/******************************************************************************/
/* $rtn_hdr_start   CUPLL_TOGGLE_CUPLL_RESET                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_toggle_cupll_reset_t41(cs_uint16 module_id,
                                             cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_RESET_t tmp_xfi_cupll_reset;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_reset.wrd = 0x0000;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, RESET), tmp_xfi_cupll_reset.wrd);

  tmp_xfi_cupll_reset.wrd = 0x000F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, RESET), tmp_xfi_cupll_reset.wrd);

  tmp_xfi_cupll_reset.wrd = 0x000F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, RESET), tmp_xfi_cupll_reset.wrd);

  tmp_xfi_cupll_reset.wrd = 0x000F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, RESET), tmp_xfi_cupll_reset.wrd);

  tmp_xfi_cupll_reset.wrd = 0x000F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, RESET), tmp_xfi_cupll_reset.wrd);

  tmp_xfi_cupll_reset.wrd = 0x000F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, RESET), tmp_xfi_cupll_reset.wrd);

  tmp_xfi_cupll_reset.wrd = 0x000F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, RESET), tmp_xfi_cupll_reset.wrd);

  tmp_xfi_cupll_reset.wrd = 0x000F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, RESET), tmp_xfi_cupll_reset.wrd);

  tmp_xfi_cupll_reset.wrd = 0x000F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, RESET), tmp_xfi_cupll_reset.wrd);

  tmp_xfi_cupll_reset.wrd = 0x0000;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, RESET), tmp_xfi_cupll_reset.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_SETUP                                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_setup_t41(cs_uint16 module_id,
                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SPARE_t tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_spare;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_clkdiv_ctrl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_t tmp_xfi32x1_sds_xfi32x1_sds_common_srx0_rx_clkdiv_ctrl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_GRO_DIV_CTRL_t tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_div_ctrl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_FRAC_CTRL_t tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_frac_ctrl;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_GRO_CTRL_t tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_GRO_CTRL));
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_ctrl.bf.STXP_GRO_REFCLK_SEL = 0x8;
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_ctrl.bf.STXP_GRO_MODE = 0;
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_ctrl.bf.STXP_GRO_PD = 0;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_GRO_CTRL), tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_ctrl.wrd);

  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_div_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_GRO_DIV_CTRL));
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_div_ctrl.bf.STXP_GRO_REFCLK_DIV_SEL = 1;
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_div_ctrl.bf.STXP_GRO_CLK_DIV_SEL = 0x10;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_GRO_DIV_CTRL), tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_gro_div_ctrl.wrd);

  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_CONFIG));
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.bf.STXP_PILOT_SEL = 1;
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL = 1;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_CONFIG), tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.wrd);

  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_spare.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_SPARE));
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_spare.bf.STXP_REFCLK_DIV_SEL = 0;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_SPARE), tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_spare.wrd);

  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_CLKDIV_CTRL));
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL = 0xD;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_CLKDIV_CTRL), tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_clkdiv_ctrl.wrd);

  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_frac_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_FRAC_CTRL));
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_frac_ctrl.bf.STXP_FRAC_EN = 1;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_FRAC_CTRL), tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_frac_ctrl.wrd);

  tmp_xfi32x1_sds_xfi32x1_sds_common_srx0_rx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, SRX0_RX_CLKDIV_CTRL));
  tmp_xfi32x1_sds_xfi32x1_sds_common_srx0_rx_clkdiv_ctrl.bf.SRX_RDIV_SEL = 0x1;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, SRX0_RX_CLKDIV_CTRL), tmp_xfi32x1_sds_xfi32x1_sds_common_srx0_rx_clkdiv_ctrl.wrd);

  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_CLKDIV_CTRL));
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_FASTDIV_SEL = 0x6;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_CLKDIV_CTRL), tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_clkdiv_ctrl.wrd);

  ten_cupll_toggle_cupll_reset_t41(module_id, slice);
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_REF_PILOT_SETUP_1_XFI                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_ref_pilot_setup_1_xfi_t41(cs_uint16 module_id,
                                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_HSIF_PROTOCOL_CLK_40G_t tmp_hsif_protocol_clk_40g;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SFI52_t tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_sfi52;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_CONFIG));
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL_MSB = 1;
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL = 0;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_CONFIG), tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.wrd);

  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_sfi52.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_SFI52));
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_sfi52.bf.STXP_SFI5P2_CLKREFOUT_SEL = 1;
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_sfi52.bf.STXP_SFI5P2_PILOTOUT_SEL = 3;
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_sfi52.bf.STXP_SFI5P2_CLKREFOUTEN = 1;
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_sfi52.bf.STXP_SFI5P2_PILOTOUTEN = 1;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_SFI52), tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_sfi52.wrd);

  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_CONFIG));
  tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.bf.STXP_PILOT_SEL = 5;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, STXP0_TX_CONFIG), tmp_xfi32x1_sds_xfi32x1_sds_common_stxp0_tx_config.wrd);

  tmp_hsif_protocol_clk_40g.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, CLK_40G));
  tmp_hsif_protocol_clk_40g.bf.xfi_txsel = 2;
  tmp_hsif_protocol_clk_40g.bf.xfi_rxsel = 2;
  TEN_REG_WRITE(TEN_HSIF_REG_ADDR(pDev, module_id, CLK_40G), tmp_hsif_protocol_clk_40g.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_311M_R_10M_C_9_95_DATA                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_311m_r_10m_c_9_95_data_t41(cs_uint16 module_id,
                                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x0020;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x01D7;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0x1528;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1501;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x140B;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1005;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1102;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1102;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x1B08;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1A15;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x150C;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x1509;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x1509;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_311M_R_10M_C_11_05_DATA                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_311m_r_10m_c_11_05_data_t41(cs_uint16 module_id,
                                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x0023;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x88B1;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0x7141;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1701;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x120B;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1D06;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1E03;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1E03;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x1E08;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1715;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x130C;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x1309;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x1309;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

    TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_311M_R_10M_C_11_7_DATA                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_311m_r_10m_c_11_7_data_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x0025;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x9FCA;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0xF063;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1901;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x110B;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1C06;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1C03;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1C03;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x2008;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1615;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x120C;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x1209;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x1209;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_425M_R_10M_C_9_95_DATA                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_425m_r_10m_c_9_95_data_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x0017;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x6BF6;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0x89C2;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1F02;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x140B;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1005;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1102;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1102;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x1408;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1A15;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x150C;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x1509;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x1509;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_425M_R_10M_C_11_05_DATA                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_425m_r_10m_c_11_05_data_t41(cs_uint16 module_id,
                                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x001A;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x00A3;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0x93EE;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1101;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x120B;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1D06;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1E03;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1E03;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x1608;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1715;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x130C;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x1309;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x1309;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_425M_R_10M_C_11_7_DATA                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_425m_r_10m_c_11_7_data_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x001B;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x8834;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0xBAC0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1201;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x110B;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1C06;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1C03;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1C03;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x1708;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1615;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x120C;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x1209;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x1209;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_311M_R_160M_C_9_95_DATA                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_311m_r_160m_c_9_95_data_t41(cs_uint16 module_id,
                                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x0020;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x01D7;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0x1528;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1501;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x140F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1009;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1106;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1106;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x1B08;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1A19;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x1510;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x150D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x150D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_311M_R_160M_C_11_05_DATA                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_311m_r_160m_c_11_05_data_t41(cs_uint16 module_id,
                                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x0023;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x88B1;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0x7141;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1701;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x120F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1D0A;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1E07;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1E07;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x1E08;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1719;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x1310;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x130D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x130D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_311M_R_160M_C_11_7_DATA                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_311m_r_160m_c_11_7_data_t41(cs_uint16 module_id,
                                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x0025;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x9FCA;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0xF063;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1901;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x110F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1C0A;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1C07;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1C07;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x2008;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1619;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x1210;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x120D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x120D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_425M_R_160M_C_9_95_DATA                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_425m_r_160m_c_9_95_data_t41(cs_uint16 module_id,
                                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x0017;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x6BF6;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0x89C2;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1F02;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x140F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1009;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1106;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1106;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x1408;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1A19;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x1510;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x150D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x150D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_425M_R_160M_C_11_05_DATA                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_425m_r_160m_c_11_05_data_t41(cs_uint16 module_id,
                                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x001A;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x00A3;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0x93EE;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1101;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x120F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1D0A;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1E07;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1E07;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x1608;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1719;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x1310;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x130D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x130D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_LOOP_425M_R_160M_C_11_7_DATA                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_loop_425m_r_160m_c_11_7_data_t41(cs_uint16 module_id,
                                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_P2F_t tmp_xfi_cupll_p2f;
  TEN_XFI_CUPLL_CFG_t tmp_xfi_cupll_cfg;
  TEN_XFI_CUPLL_K1F_t tmp_xfi_cupll_k1f;
  TEN_XFI_CUPLL_PDCAL_t tmp_xfi_cupll_pdcal;
  TEN_XFI_CUPLL_PRELOADFINT_t tmp_xfi_cupll_preloadfint;
  TEN_XFI_CUPLL_K1S_t tmp_xfi_cupll_k1s;
  TEN_XFI_CUPLL_HOLDOVER_t tmp_xfi_cupll_holdover;
  TEN_XFI_CUPLL_P2S_t tmp_xfi_cupll_p2s;
  TEN_XFI_CUPLL_Z1F_t tmp_xfi_cupll_z1f;
  TEN_XFI_CUPLL_P3F_t tmp_xfi_cupll_p3f;
  TEN_XFI_CUPLL_P1F_t tmp_xfi_cupll_p1f;
  TEN_XFI_CUPLL_PDOFFSET0_t tmp_xfi_cupll_pdoffset0;
  TEN_XFI_CUPLL_P3S_t tmp_xfi_cupll_p3s;
  TEN_XFI_CUPLL_PDOFFSET1_t tmp_xfi_cupll_pdoffset1;
  TEN_XFI_CUPLL_Z1S_t tmp_xfi_cupll_z1s;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI_CUPLL_PRELOADFFRAC0_t tmp_xfi_cupll_preloadffrac0;
  TEN_XFI_CUPLL_P1S_t tmp_xfi_cupll_p1s;
  TEN_XFI_CUPLL_PRELOADFFRAC1_t tmp_xfi_cupll_preloadffrac1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_preloadfint.wrd = 0x001B;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFINT), tmp_xfi_cupll_preloadfint.wrd);

  tmp_xfi_cupll_preloadffrac1.wrd = 0x8834;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC1), tmp_xfi_cupll_preloadffrac1.wrd);

  tmp_xfi_cupll_preloadffrac0.wrd = 0xBAC0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PRELOADFFRAC0), tmp_xfi_cupll_preloadffrac0.wrd);

  tmp_xfi_cupll_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, CFG), tmp_xfi_cupll_cfg.wrd);

  tmp_xfi_cupll_pdoffset1.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET1), tmp_xfi_cupll_pdoffset1.wrd);

  tmp_xfi_cupll_pdoffset0.wrd = 0x0060;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDOFFSET0), tmp_xfi_cupll_pdoffset0.wrd);

  tmp_xfi_cupll_holdover.wrd = 0;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, HOLDOVER), tmp_xfi_cupll_holdover.wrd);

  tmp_xfi_cupll_pdcal.wrd = 0x1080;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, PDCAL), tmp_xfi_cupll_pdcal.wrd);

  tmp_xfi_cupll_k1f.wrd = 0x1201;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1F), tmp_xfi_cupll_k1f.wrd);

  tmp_xfi_cupll_z1f.wrd = 0x110F;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1F), tmp_xfi_cupll_z1f.wrd);

  tmp_xfi_cupll_p1f.wrd = 0x1C0A;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1F), tmp_xfi_cupll_p1f.wrd);

  tmp_xfi_cupll_p2f.wrd = 0x1C07;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2F), tmp_xfi_cupll_p2f.wrd);

  tmp_xfi_cupll_p3f.wrd = 0x1C07;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3F), tmp_xfi_cupll_p3f.wrd);

  tmp_xfi_cupll_k1s.wrd = 0x1708;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, K1S), tmp_xfi_cupll_k1s.wrd);

  tmp_xfi_cupll_z1s.wrd = 0x1619;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, Z1S), tmp_xfi_cupll_z1s.wrd);

  tmp_xfi_cupll_p1s.wrd = 0x1210;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P1S), tmp_xfi_cupll_p1s.wrd);

  tmp_xfi_cupll_p2s.wrd = 0x120D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P2S), tmp_xfi_cupll_p2s.wrd);

  tmp_xfi_cupll_p3s.wrd = 0x120D;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, P3S), tmp_xfi_cupll_p3s.wrd);

  tmp_xfi_cupll_sd_cfg.wrd = 0x3031;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_ENABLE_CUPLL                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_enable_cupll_t41(cs_uint16 module_id,
                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_sd_cfg.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG));
  tmp_xfi_cupll_sd_cfg.bf.SDen = 1;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  ten_cupll_toggle_cupll_reset_t41(module_id, slice);
  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_START_TUNING                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_start_tuning_t41(cs_uint16 module_id,
                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXVCO0_CONTROL_t tmp_xfi32x1_sds_xfi32x1_sds_common_rxvco0_control;
  TEN_XFI_CUPLL_SD_CFG_t tmp_xfi_cupll_sd_cfg;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXVCO0_CONTROL_t tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_xfi_cupll_sd_cfg.wrd = TEN_REG_READ(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG));
  tmp_xfi_cupll_sd_cfg.bf.SDen = 1;
  TEN_REG_WRITE(TEN_XFI_CUPLL_REG_ADDR(pDev, slice, SD_CFG), tmp_xfi_cupll_sd_cfg.wrd);

  ten_cupll_toggle_cupll_reset_t41(module_id, slice);
  tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, TXVCO0_CONTROL));
  tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control.bf.INIT = 1;
  tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control.bf.SHORT_OVRIDE = 0;
  tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control.bf.INIT = 0;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, TXVCO0_CONTROL), tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control.wrd);

  tmp_xfi32x1_sds_xfi32x1_sds_common_rxvco0_control.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, RXVCO0_CONTROL));
  tmp_xfi32x1_sds_xfi32x1_sds_common_rxvco0_control.bf.INIT = 1;
  tmp_xfi32x1_sds_xfi32x1_sds_common_rxvco0_control.bf.SHORT_OVRIDE = 0;
  tmp_xfi32x1_sds_xfi32x1_sds_common_rxvco0_control.bf.INIT = 0;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, RXVCO0_CONTROL), tmp_xfi32x1_sds_xfi32x1_sds_common_rxvco0_control.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_START_RX_CFP_TUNING                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_start_rx_cfp_tuning_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_CFP32X1_SDS_COMMON_RXVCO0_CONTROL_t tmp_cfp32x1_sds_common_rxvco0_control;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_cfp32x1_sds_common_rxvco0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, RXVCO0_CONTROL));
  tmp_cfp32x1_sds_common_rxvco0_control.bf.INIT = 1;
  tmp_cfp32x1_sds_common_rxvco0_control.bf.SHORT_OVRIDE = 0;
  tmp_cfp32x1_sds_common_rxvco0_control.bf.INIT = 0;
  TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, RXVCO0_CONTROL), tmp_cfp32x1_sds_common_rxvco0_control.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_START_CFP_TUNING                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_start_cfp_tuning_t41(cs_uint16 module_id,
                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_CFP32X1_SDS_COMMON_TXVCO0_CONTROL_t tmp_cfp32x1_sds_common_txvco0_control;
  TEN_CFP32X1_SDS_COMMON_RXVCO0_CONTROL_t tmp_cfp32x1_sds_common_rxvco0_control;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  tmp_cfp32x1_sds_common_txvco0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, TXVCO0_CONTROL));
  tmp_cfp32x1_sds_common_txvco0_control.bf.INIT = 1;
  tmp_cfp32x1_sds_common_txvco0_control.bf.SHORT_OVRIDE = 0;
  tmp_cfp32x1_sds_common_txvco0_control.bf.INIT = 0;
  TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, TXVCO0_CONTROL), tmp_cfp32x1_sds_common_txvco0_control.wrd);

  tmp_cfp32x1_sds_common_rxvco0_control.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, RXVCO0_CONTROL));
  tmp_cfp32x1_sds_common_rxvco0_control.bf.INIT = 1;
  tmp_cfp32x1_sds_common_rxvco0_control.bf.SHORT_OVRIDE = 0;
  tmp_cfp32x1_sds_common_rxvco0_control.bf.INIT = 0;
  TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, slice, RXVCO0_CONTROL), tmp_cfp32x1_sds_common_rxvco0_control.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   CUPLL_RXDIV_IS_REF                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : XFI                                                  */
/* CHIP       : Tenabo                                                        */
cs_status ten_cupll_rxdiv_is_ref_t41(cs_uint16 module_id,
                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXVCO0_CONTROL_t tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_CFP32X1);
  
  ten_cupll_toggle_cupll_reset_t41(module_id, slice);
  tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, TXVCO0_CONTROL));
  tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control.bf.INIT = 1;
  tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control.bf.INIT = 0;
  TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, slice, TXVCO0_CONTROL), tmp_xfi32x1_sds_xfi32x1_sds_common_txvco0_control.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_CFP32X1);
  return (CS_OK);
}




