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
 * ten_gpllx1.c
 *
 * GPLLX1 related code is implemented here.
 *
 * $Id: ten_gpllx1.c,v 1.21 2013/12/02 18:25:43 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  GPLLX1 SET STXP0 TX CONFIG                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GPLLX1                                          */
/* CHIP       : Tenabo                                          */
cs_status ten_gpllx1_set_stxp0_tx_config(cs_uint16 dev_id, cs_uint8 instance, 
                                         cs_uint16 stxp_buswidth,
                                         cs_uint16 stxp_pilot_sel)
/* INPUTS     : o Device Id                                     */
/*              o Instance                                      */
/*              o STXP Buswidth                                 */
/*              o STXP Pilot Select                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register contains various control bits for TX.          */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)              */
/*                                                              */
/* The [stxp_buswidth] parameter is specified as:               */
/*   MUX bus width at output.                                   */
/*   00 = enable 8bit mux mode                                  */
/*   01 = enable 10bit mux mode                                 */
/*   10 = reserved                                              */
/*   11 = reserved                                              */
/*                                                              */
/* The [stxp_pilot_sel] parameter is specified as:              */
/*   0 = RX ref from CLKREFP/N                                  */
/*   1 = RX ref from AUXPILOTIN                                 */
/*   4 = RX ref from AUXREFIN.                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CONFIG, ii));
      tmp_stxp0_tx_config.bf.STXP_BUSWIDTH = stxp_buswidth;
      tmp_stxp0_tx_config.bf.STXP_PILOT_SEL = stxp_pilot_sel;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CONFIG, ii), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 STXP0 TX CONFIG                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_status ten_gpllx1_stxp0_tx_config_lptime_sel(cs_uint16 dev_id, cs_uint8 instance, 
                                 cs_uint16 stxp_lptime_sel)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o STXP LPTIME SEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*   Enable Loop time mode in which one RX channel recovered        */
/*   clock is supplied as the reference for transmit.               */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [stxp_lptime_sel]                                              */
/*                                                                  */
/*     00 = STXP_CLKREFP                                            */
/*     01 = UNUSED                                                  */
/*     10 = STXP_AUXREFIN.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CONFIG, ii));
      tmp_stxp0_tx_config.bf.STXP_LPTIME_SEL = stxp_lptime_sel;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CONFIG, ii), tmp_stxp0_tx_config.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 STXP0 TX PWRDN                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_status ten_gpllx1_stxp0_tx_pwrdn(cs_uint16 dev_id, cs_uint8 instance, 
                                cs_uint16 stxp_pd_lane)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o STXP PD LANE                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls power down bits for TX PLL.                             */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [stxp_pd_lane]  Power down individual lanes on the transmit    */
/*     section.                                                     */
/*     0 = lane N powered                                           */
/*     1 = lane N powered down.                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_PWRDN_t tmp_stxp0_tx_pwrdn;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_pwrdn.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_PWRDN, ii));
      tmp_stxp0_tx_pwrdn.bf.STXP_PD_LANE = stxp_pd_lane;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_PWRDN, ii), tmp_stxp0_tx_pwrdn.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 STXP0 TX PWRDN ALL LANES                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_status ten_gpllx1_stxp0_tx_pwrdn_all(cs_uint16 dev_id,
                                        cs_uint8 instance, 
                                        cs_uint16 stxp_pd)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o STXP PD                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls power down bits for TX PLL.                             */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [stxp_pd]  Power down the entire transmit section              */
/*     0 = powered                                                  */
/*     1 = powered down                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_PWRDN_t tmp_stxp0_tx_pwrdn;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_pwrdn.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_PWRDN, ii));
      tmp_stxp0_tx_pwrdn.bf.STXP_PD = stxp_pd;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_PWRDN, ii), tmp_stxp0_tx_pwrdn.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  GPLLX1 STXP0 TX CLKDIV CTRL                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GPLLX1                                          */
/* CHIP       : Tenabo                                          */
cs_status ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(cs_uint16 dev_id, cs_uint8 instance, 
                                      cs_uint16 stxp_fastdiv_sel, 
                                      cs_uint16 stxp_ctrdiv_sel, 
                                      cs_uint16 stxp_ctvdiv_sel, 
                                      cs_uint16 stxp_ddiv_sel, 
                                      cs_uint16 stxp_rdiv_sel)
/* INPUTS     : o Device Id                                     */
/*              o Instance                                      */
/*              o STXP FASTDIV SEL                              */
/*              o STXP CTRDIV SEL                               */
/*              o STXP CTVDIV SEL                               */
/*              o STXP DDIV SEL                                 */
/*              o STXP RDIV SEL                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register controls all of the TX clock dividers.         */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)              */
/*                                                              */
/* The [stxp_fastdiv_sel] parameter is specified as:            */
/*   Select the serial clock divider to transmit PFD for        */
/*   comparison to the clock reference 1.75GHz to 3.5GHz VCO    */
/*   0000 = div10                                               */
/*   0001 = div20                                               */
/*   0010 = div40                                               */
/*   0011 = div132                                              */
/*   0100 = div2                                                */
/*   0101 = div4                                                */
/*   0110 = div8                                                */
/*   0111 = div16                                               */
/*   1000 = div32                                               */
/*   1001 = div64                                               */
/*   1010 = div33                                               */
/*   1011 = div66                                               */
/*   1100 = div128                                              */
/*   1101 = div100                                              */
/*   1110 = SFI5 mux clk                                        */
/*                                                              */
/* The [stxp_ctrdiv_sel] parameter is specified as:             */
/*   Select to divide the clock reference before reaching the   */
/*   digital core for use in coarse tuning:                     */
/*   00 = div1                                                  */
/*   01 = div2                                                  */
/*   10 = div4                                                  */
/*   11 = div8                                                  */
/*                                                              */
/* The [stxp_ctvdiv_sel] parameter is specified as:             */
/*   Select to divide CLK_LD before reaching the digital core   */
/*   for use in coarse tuning                                   */
/*   00 = div1                                                  */
/*   01 = div2                                                  */
/*   10 = div4                                                  */
/*   11 = div8                                                  */
/*                                                              */
/* The [stxp_ddiv_sel] parameter is specified as:               */
/*   Select clock rate for transmit data path                   */
/*   000 = TX serial clock div by 1 selected                    */
/*   001 = TX serial clock div by 2 selected                    */
/*   010 = TX serial clock div by 4 selected                    */
/*   011 = TX serial clock div by 8 selected                    */
/*   100 = TX serial clock div by 16 selected                   */
/*   101 = TX serial clock div by 32 selected                   */
/*   110 = TX serial clock div by 64 selected                   */
/*   111 = not used                                             */
/*                                                              */
/* The [stxp_rdiv_sel] parameter is specified as:               */
/*   Select the serial clock divider to transmit PFD for        */
/*   comparison to the clock reference 1.75GHz to 3.5GHz VCO    */
/*   0000 = div10                                               */
/*   0001 = div20                                               */
/*   0010 = div40                                               */
/*   0011 = div80                                               */
/*   0100 = div2                                                */
/*   0101 = div4                                                */
/*   0110 = div8                                                */
/*   0111 = div16                                               */
/*   1000 = div32                                               */
/*   1001 = div64                                               */
/*   1010 = div33                                               */
/*   1011 = div66                                               */
/*   1100 = div128                                              */
/*   1101 = div100                                              */
/*   1110 = SFI5 mux clk                                        */
/*   1111 = External.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKDIV_CTRL, ii));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_FASTDIV_SEL = stxp_fastdiv_sel;
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_CTRDIV_SEL = stxp_ctrdiv_sel;
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_CTVDIV_SEL = stxp_ctvdiv_sel;
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_DDIV_SEL = stxp_ddiv_sel;
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL = stxp_rdiv_sel;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKDIV_CTRL, ii), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/* Bugzilla 37987 Start */
/****************************************************************/
/* $rtn_hdr_start  GPLLX1 STXP0 TX DDIV_SEL                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GPLLX1                                          */
/* CHIP       : Tenabo                                          */
cs_status ten_gpllx1_set_stxp0_tx_ddiv_sel(cs_uint16 dev_id,
                                           cs_uint8  instance, 
                                           cs_uint16 stxp_ddiv_sel)
/* INPUTS     : o Device Id                                     */
/*              o Instance                                      */
/*              o STXP DDIV SEL                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This API sets the GPLL DDIV_SEL divider.                     */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)              */
/*                                                              */
/* The [stxp_ddiv_sel] parameter is specified as:               */
/*   Select clock rate for transmit data path                   */
/*   000 = TX serial clock div by 1 selected                    */
/*   001 = TX serial clock div by 2 selected                    */
/*   010 = TX serial clock div by 4 selected                    */
/*   011 = TX serial clock div by 8 selected                    */
/*   100 = TX serial clock div by 16 selected                   */
/*   101 = TX serial clock div by 32 selected                   */
/*   110 = TX serial clock div by 64 selected                   */
/*   111 = not used                                             */

/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKDIV_CTRL, ii));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_DDIV_SEL = stxp_ddiv_sel;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKDIV_CTRL, ii), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  GPLLX1 STXP0 TX FASTDIV_SEL                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GPLLX1                                          */
/* CHIP       : Tenabo                                          */
cs_status ten_gpllx1_set_stxp0_tx_fastdiv_sel(cs_uint16 dev_id,
                                              cs_uint8  instance, 
                                              cs_uint16 stxp_fastdiv_sel)
/* INPUTS     : o Device Id                                     */
/*              o Instance                                      */
/*              o STXP FASTDIV SEL                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This API sets the GPLL FASTDIV_SEL divider.                  */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)              */
/*                                                              */
/* The [stxp_fastdiv_sel] parameter is specified as:            */
/*   Select the serial clock divider to transmit PFD for        */
/*   comparison to the clock reference 1.75GHz to 3.5GHz VCO    */
/*   0000 = div10                                               */
/*   0001 = div20                                               */
/*   0010 = div40                                               */
/*   0011 = div132                                              */
/*   0100 = div2                                                */
/*   0101 = div4                                                */
/*   0110 = div8                                                */
/*   0111 = div16                                               */
/*   1000 = div32                                               */
/*   1001 = div64                                               */
/*   1010 = div33                                               */
/*   1011 = div66                                               */
/*   1100 = div128                                              */
/*   1101 = div100                                              */
/*   1110 = SFI5 mux clk                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKDIV_CTRL, ii));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_FASTDIV_SEL = stxp_fastdiv_sel;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKDIV_CTRL, ii), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}
/* Bugzilla 37987 End */

/****************************************************************/
/* $rtn_hdr_start  GPLLX1 STXP0 TX CLKDIV CTRL RDIV_SEL         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GPLLX1                                          */
/* CHIP       : Tenabo                                          */
cs_status ten_gpllx1_set_stxp0_tx_clkdiv_rdiv_ctrl(cs_uint16 dev_id, 
                                                   cs_uint8 instance, 
                                                   cs_uint16 stxp_rdiv_sel)
/* INPUTS     : o Device Id                                     */
/*              o Instance                                      */
/*              o STXP RDIV SEL                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register controls the TX RDIV_SEL clock divider.        */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)              */
/*                                                              */
/* The [stxp_rdiv_sel] parameter is specified as:               */
/*   Select the serial clock divider to transmit PFD for        */
/*   comparison to the clock reference 1.75GHz to 3.5GHz VCO    */
/*   0000 = div10                                               */
/*   0001 = div20                                               */
/*   0010 = div40                                               */
/*   0011 = div80                                               */
/*   0100 = div2                                                */
/*   0101 = div4                                                */
/*   0110 = div8                                                */
/*   0111 = div16                                               */
/*   1000 = div32                                               */
/*   1001 = div64                                               */
/*   1010 = div33                                               */
/*   1011 = div66                                               */
/*   1100 = div128                                              */
/*   1101 = div100                                              */
/*   1110 = SFI5 mux clk                                        */
/*   1111 = External.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKDIV_CTRL, ii));
      tmp_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL = stxp_rdiv_sel;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKDIV_CTRL, ii), tmp_stxp0_tx_clkdiv_ctrl.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  GPLLX1 SET STXP0 TX CLKOUT CTRL REGISTERS    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GPLLX1                                          */
/* CHIP       : Tenabo                                          */
cs_status ten_gpllx1_set_stxp0_tx_clkout_ctrl(cs_uint16 dev_id, cs_uint8 instance, 
                                              cs_uint16 stxp_tclkien, 
                                              cs_uint16 stxp_clkouten, 
                                              cs_uint16 stxp_tclko_sel)
/* INPUTS     : o Device Id                                     */
/*              o Instance                                      */
/*              o STXP TCLKIEN                                  */
/*              o STXP CLKOUTEN                                 */
/*              o STXP TCLKO SEL                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register controls aspects of the transmit clock outputs.*/
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)              */
/*                                                              */
/* The [stxp_tclkien]  parameter is specified as:               */
/*   Select source for serial clock                             */
/*   00 = RINGVCO                                               */
/*   01 = LCVCO                                                 */
/*   10 = UNUSED                                                */
/*   11 = TEST CLOCK IN                                         */
/*                                                              */
/* The [stxp_clkouten]  parameter is specified as:              */
/*   Test clock output enable.                                  */
/*   0 = test clock disabled                                    */
/*   1 = test clock enabled                                     */
/*                                                              */
/* The [stxp_tclko_sel]  parameter is specified as:             */
/*   Select the serial clock divider to transmit PFD for        */
/*   comparison to the clock reference 1.75GHz to 3.5GHz VCO    */
/*   110000 div10                                               */
/*   110001 = div20                                             */
/*   110010 = div40                                             */
/*   110011 = div132                                            */
/*   110100 = div2                                              */
/*   110101 = div4                                              */
/*   110110 = div8                                              */
/*   110111 = div16                                             */
/*   111000 = div32                                             */
/*   111001 = div64                                             */
/*   111010 = div33                                             */
/*   111011 = div66                                             */
/*   111100 = div128                                            */
/*   111101 = div100                                            */
/*   111110 = SFI5 mux clk                                      */
/*   111111 = reserved                                          */
/*   ?????? = pilot tone                                        */
/*   01xxxx = serial clock                                      */
/*   10xxxx = recovered serial data.                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKOUT_CTRL, ii));
      tmp_stxp0_tx_clkout_ctrl.bf.STXP_TCLKIEN = stxp_tclkien;
      tmp_stxp0_tx_clkout_ctrl.bf.STXP_CLKOUTEN = stxp_clkouten;
      tmp_stxp0_tx_clkout_ctrl.bf.STXP_TCLKO_SEL = stxp_tclko_sel;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKOUT_CTRL, ii), tmp_stxp0_tx_clkout_ctrl.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 STXP0 TX LOOP FILTER                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_status ten_gpllx1_stxp0_tx_loop_filter(cs_uint16 dev_id, cs_uint8 instance, 
                                      cs_uint16 stxp_filtr)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o STXP FILTR                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit loop filter.                    */
/*                                                                  */
/*   [instance]  0..16 or TEN_INSTANCE_ALL (0xFF)                   */
/*                                                                  */
/*   [stxp_filtr]  Programmable PLL loop filter resistance.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_LOOP_FILTER_t tmp_stxp0_tx_loop_filter;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_loop_filter.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_LOOP_FILTER, ii));
      tmp_stxp0_tx_loop_filter.bf.STXP_FILTR = stxp_filtr;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_LOOP_FILTER, ii), tmp_stxp0_tx_loop_filter.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 STXP0 TX CP                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_status ten_gpllx1_stxp0_tx_cp(cs_uint16 dev_id, cs_uint8 instance, 
                             cs_uint16 stxp_cpcur1, 
                             cs_uint16 stxp_cpcur0)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o STXP CPCUR1                                       */
/*              o STXP CPCUR0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the transmit PLL charge pump.                */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [stxp_cpcur1]  Charge pump current setting                     */
/*                                                                  */
/*   [stxp_cpcur0]  Charge pump current setting.                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_CP_t tmp_stxp0_tx_cp;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_cp.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CP, ii));
      tmp_stxp0_tx_cp.bf.STXP_CPCUR1 = stxp_cpcur1;
      tmp_stxp0_tx_cp.bf.STXP_CPCUR0 = stxp_cpcur0; 
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CP, ii), tmp_stxp0_tx_cp.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 TXVCO0 THRES0                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_status ten_gpllx1_txvco0_thres0(cs_uint16 dev_id, cs_uint8 instance, 
                               cs_uint16 freq_thres_sign0, 
                               cs_uint16 freq_thres0)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o FREQ THRES SIGN0                                  */
/*              o FREQ THRES0                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets threshold used by the VCO Coarse Tuning Algorithm to decide */
/* if the VCO 0 is in the correct frequency range.                  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [freq_thres_sign0]  Positive (0) or Negative (1) sign to be    */
/*     associated with FREQ_THRES0.                                 */
/*                                                                  */
/*   [freq_thres0]  Provides some flexibility for the Coarse        */
/*     Tuning Algorithm when deciding if the VCO's operating        */
/*     frequency range is such that the PLL can capture the         */
/*     receive data frequency.  Larger values of FREQ_THRES0        */
/*     provide more slack in making this decision.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_TXVCO0_THRES0_t tmp_txvco0_thres0;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_txvco0_thres0.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_THRES0, ii));
      tmp_txvco0_thres0.bf.FREQ_THRES_SIGN0 = freq_thres_sign0;
      tmp_txvco0_thres0.bf.FREQ_THRES0 = freq_thres0;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_THRES0, ii), tmp_txvco0_thres0.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 TXVCO0 THRES1                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_status ten_gpllx1_txvco0_thres1(cs_uint16 dev_id, cs_uint8 instance, 
                               cs_uint16 freq_thres_sign1, 
                               cs_uint16 freq_thres1)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o FREQ THRES SIGN1                                  */
/*              o FREQ THRES1                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets threshold used by the VCO Coarse Tuning Algorithm to decide */
/* if the VCO 1 is in the correct frequency range.                  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [freq_thres_sign1]  Positive (0) or Negative (1) sign to be    */
/*     associated with FREQ_THRES1.                                 */
/*                                                                  */
/*   [freq_thres1]  Provides some flexibility for the Coarse        */
/*     Tuning Algorithm when deciding if the VCO's operating        */
/*     frequency range is such that the PLL can capture the         */
/*     receive data frequency.  Larger values of FREQ_THRES1        */
/*     provide more slack in making this decision.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_TXVCO0_THRES1_t tmp_txvco0_thres1;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_txvco0_thres1.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_THRES1, ii));
      tmp_txvco0_thres1.bf.FREQ_THRES_SIGN1 = freq_thres_sign1;
      tmp_txvco0_thres1.bf.FREQ_THRES1 = freq_thres1;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_THRES1, ii), tmp_txvco0_thres1.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 TXLOCKD0 CHECK LOCK                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_boolean ten_gpllx1_txlockd0_lock(cs_uint16 dev_id, cs_uint8 instance)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Indicates if the SerDes is locked.                               */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_GPLLX1_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_txlockd0_intstatus;
  cs_char8 *func = "ten_gpllx1_txlockd0_lock";  

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, FALSE);

  if (instance < TEN_GPLLX1_SDS_COUNT) {
    CS_PRINT("%s() %s\n", func, ten_gpll_instance_strings[instance]);
  }
  else if (instance == TEN_INSTANCE_ALL) {
    CS_PRINT("%s() INSTANCE_ALL\n", func);
  } else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..16 or 0xFF.", func, instance);
    return(CS_ERROR);
  }

  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKD0_INTSTATUS, ii));
      ret_val &= ((tmp_txlockd0_intstatus.bf.FILT_LOCKs == 1) && 
                 (tmp_txlockd0_intstatus.bf.LOCKs == 1));
    }
  }

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 TXLOCKD0 CHECK FILT_LOCK                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_boolean ten_gpllx1_txlockd0_filt_lock(cs_uint16 dev_id, cs_uint8 instance)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Current state of the lock filter FSM.                            */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_GPLLX1_SDS_COMMON_TXLOCKD0_INTSTATUS_t tmp_txlockd0_intstatus;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(FALSE);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, FALSE);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_txlockd0_intstatus.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKD0_INTSTATUS, ii));
      ret_val &= tmp_txlockd0_intstatus.bf.FILT_LOCKs == 1;
    }
  }
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  GPLLX1 GET TXVC0 TUNE INTSTATUS              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HSIF                                            */
/* CHIP       : Tenabo                                          */
cs_boolean ten_gpllx1_get_txvco_tune_intstatus(cs_uint16 dev_id,
                                               cs_uint8 instance)
/* INPUTS     : o Device Id                                     */
/*              o Instance                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Returns the Current state of the Coarse Tuning Algorithm's   */
/* "SHORT_FILTPN" output signal.                                */
/*                                                              */
/* Specified as 0..16 or TEN_INSTANCE_ALL (0xFF).               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_boolean ret_val = TRUE;
  TEN_GPLLX1_SDS_COMMON_TXVCO0_INTSTATUS_t tmp_txvco0_intstatus;
  cs_uint16 ii;
  volatile cs_reg *tmp_addr;

  /* bugzilla #24260 start, check for valid instance */
  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF or 0xFF.");
    return (FALSE);
  }
  /* bugzilla #24260 end, check for valid instance */
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, FALSE);

  /* bugzilla #24260, also allow for TEN_INSTANCE_ALL */
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_INTSTATUS, instance);
      tmp_txvco0_intstatus.wrd = TEN_REG_READ(tmp_addr);
      ret_val &= (tmp_txvco0_intstatus.bf.SHORT_FILTPNs == 1);
    }
  }
  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 SET TXVCO0 VCOMAX                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_status ten_gpllx1_set_txvco0_vcomax(cs_uint16 dev_id,
                                       cs_uint8  instance, 
                                       cs_uint16 vcomax)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o VCOMAX                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the length of time the Tuning Algorithm remains at a    */
/* particular frequency step.                                       */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..16 or TEN_INSTANCE_ALL (0xFF)                               */
/*                                                                  */
/* The [vcomax] parameter is specified as:                          */
/*   0x0000..0x0FFF                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_TXVCO0_VCOMAX_t tmp_txvco0_vcomax;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_txvco0_vcomax.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_VCOMAX, ii));
      tmp_txvco0_vcomax.bf.VCOMAX = vcomax;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_VCOMAX, ii), tmp_txvco0_vcomax.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 SET TXVCO0 INIT                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_status ten_gpllx1_set_txvco0_init(cs_uint16 dev_id,
                                     cs_uint8  instance, 
                                     cs_uint16 init)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o INIT                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When this bit is asserted, the VCO Coarse Tuning Algorithm is    */
/* re-initialized and starts searching for the correct frequency    */
/* range again.                                                     */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..16 or TEN_INSTANCE_ALL (0xFF)                               */
/*                                                                  */
/* The [init] parameter is specified as:                            */
/*   0..1                                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_TXVCO0_CONTROL_t tmp_txvco0_control;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_gpllx1_set_txvco0_init";

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (instance < TEN_GPLLX1_SDS_COUNT) {
    CS_PRINT("%s, init=%d\n", ten_gpll_instance_strings[instance], init);
  }
  else if (instance == TEN_INSTANCE_ALL) {
    CS_PRINT("INSTANCE_ALL, init=%d\n", init);
  } else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..16 or 0xFF.", func, instance);
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_txvco0_control.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_CONTROL, ii));
      tmp_txvco0_control.bf.INIT = init;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, TXVCO0_CONTROL, ii), tmp_txvco0_control.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  GPLLX1 SET STXP0 STXP CLKOUTEN               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GPLLX1                                          */
/* CHIP       : Tenabo                                          */
cs_status ten_gpllx1_set_stxp0_stxp_clkouten(cs_uint16 dev_id,
                                             cs_uint8 instance, 
                                             cs_uint16 stxp_clkouten)
/* INPUTS     : o Device Id                                     */
/*              o Instance                                      */
/*              o STXP CLKOUTEN                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register controls aspects of the transmit clock outputs.*/
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)              */
/*                                                              */
/* The [stxp_clkouten]  parameter is specified as:              */
/*   Test clock output enable.                                  */
/*   0 = test clock disabled                                    */
/*   1 = test clock enabled                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_stxp0_tx_clkout_ctrl;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKOUT_CTRL, ii));
      tmp_stxp0_tx_clkout_ctrl.bf.STXP_CLKOUTEN = stxp_clkouten;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_CLKOUT_CTRL, ii), tmp_stxp0_tx_clkout_ctrl.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GPLLX1 TXLOCKD0 FILTER                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GPLLX1                                              */
/* CHIP       : Tenabo                                              */
cs_status ten_gpllx1_txlockd0_filter(cs_uint16 dev_id, cs_uint8 instance, 
                                 cs_uint16 stable_period)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o STABLE PERIOD                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the Lock Detect interrupt filter.                       */
/*                                                                  */
/*   [instance]  0..16 or TEN_INSTANCE_ALL (0xFF).                  */
/*                                                                  */
/*   [stable_period]  Specifies the period of time where lock must  */
/*      be asserted before reporting lock via interrupt.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GPLLX1_SDS_COMMON_TXLOCKD0_FILTER_t tmp_txlockd0_filter;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);
  for (ii=0; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_txlockd0_filter.wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKD0_FILTER, ii));
      tmp_txlockd0_filter.bf.STABLE_PERIOD = stable_period;
      TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, TXLOCKD0_FILTER, ii), tmp_txlockd0_filter.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);

  return (CS_OK);
}

/****************************************************************/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GPLLX1                                          */
/* CHIP       : Tenabo                                          */
cs_status ten_set_vco_coarse_tuning (cs_uint16 dev_id, cs_uint8 instance) 
/* INPUTS     : o Device Id                                     */
/*              o Instance                                      */
/*              o STXP CLKOUTEN                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set VCO course tuning                                        */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)              */
/*                                                              */
/****************************************************************/
{
  cs_char8 *func = "ten_set_vco_coarse_tuning";  

  if (instance < TEN_GPLLX1_SDS_COUNT) {
    CS_PRINT("%s() %s\n", func, ten_gpll_instance_strings[instance]);
  }
  else if (instance == TEN_INSTANCE_ALL) {
    CS_PRINT("%s() INSTANCE_ALL\n", func);
  } else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..16 or 0xFF.", func, instance);
    return(CS_ERROR);
  }

  if (ten_dev_is_t41(dev_id)) {
    /* use default value */
    
    /* Bug 40945 - Change to GPLL and MR SERDES settings */
    CS_PRINT("%s() vco_coarse_tuning for T41\n", func, dev_id, instance);
    ten_gpllx1_set_txvco0_vcomax (dev_id, instance, 0x0FFF);
    ten_gpllx1_txvco0_thres0 (dev_id, instance, 0, 0xFF); /* TXVCO_THRES0  VCO Coarse Tuning Algorithm Threshold for VCO 0 */
    ten_gpllx1_txvco0_thres1 (dev_id, instance, 0, 0xFF); /* TXVCO_THRES1  VCO Coarse Tuning Algorithm Threshold for VCO 1 */
  }
  else { 
    CS_PRINT("%s() vco_coarse_tuning for T40\n", func, dev_id, instance);
    ten_gpllx1_set_txvco0_vcomax (dev_id, instance,   0x03ff);
    ten_gpllx1_txvco0_thres0 (dev_id, instance, 0, 0);  /* TXVCO_THRES0  VCO Coarse Tuning Algorithm Threshold for VCO 0 */
    ten_gpllx1_txvco0_thres1 (dev_id, instance, 0, 0x0091); /* TXVCO_THRES1  VCO Coarse Tuning Algorithm Threshold for VCO 1 */
  }

  return (CS_OK);
}


/********************************************************************/
/* Function: ten_get_gpllx1_inst_reg_addr                           */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a gpllx1 register.                           */
/*                                                                  */
/* Used by macro TEN_GPLLX1_INST_REG_ADDR. Given the base address   */
/* of a non-common gpllx1 register as defined in t41_registers.h,   */
/* and its instance number (0-TEN_GPLLX1_SDS_COUNT), calcuates      */
/* the offset and adds it to the base register's address.           */
/********************************************************************/
volatile cs_reg *ten_get_gpllx1_inst_reg_addr( cs_reg   *pReg,
                                               cs_uint16 instance )
{
  if (instance >= TEN_GPLLX1_SDS_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "gpllx1 instance %d out of range. S/b < TEN_GPLLX1_SDS_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_GPLLX1_SDS_STRIDE);
}

