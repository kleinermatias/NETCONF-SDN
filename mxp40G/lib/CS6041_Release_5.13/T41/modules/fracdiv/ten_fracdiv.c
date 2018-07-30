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
 * ten_fracdiv.c
 *
 * FRAC DIV related code is implemented here.
 *
 * $Id: ten_fracdiv.c,v 1.8 2013/02/22 20:42:54 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV COMMON FRAC DIV STAGE 2 PRELOAD         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_common_frac_div_s2_preload(cs_uint16 dev_id, 
                                             cs_uint16 value1,
                                             cs_uint16 value0)
/* INPUTS     : o Device Id                                         */
/*              o Value1                                            */
/*              o Value0                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Fractional Dividers Stage 2 Preload configuration       */
/* registers.  This setting is common for all fractional dividers.  */
/*                                                                  */
/*   [value1]  Fractional Divider Stage 2 Preload Value1 (MSB)      */
/*                                                                  */
/*   [value0]  Fractional Divider Stage 2 Preload Value0 (LSB).     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_FRAC_DIV_COMMON_FRAC_DIV_S2PL1_t tmp_div_common_frac_div_s2pl1;
  TEN_FRAC_DIV_COMMON_FRAC_DIV_S2PL0_t tmp_div_common_frac_div_s2pl0;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  
  tmp_div_common_frac_div_s2pl0.wrd = TEN_REG_READ(TEN_FRAC_DIV_COMMON_REG_ADDR(pDev, FRAC_DIV_S2PL0));
  tmp_div_common_frac_div_s2pl0.bf.value0 = value0;
  TEN_REG_WRITE(TEN_FRAC_DIV_COMMON_REG_ADDR(pDev, FRAC_DIV_S2PL0), tmp_div_common_frac_div_s2pl0.wrd);
  
  tmp_div_common_frac_div_s2pl1.wrd = TEN_REG_READ(TEN_FRAC_DIV_COMMON_REG_ADDR(pDev, FRAC_DIV_S2PL1));
  tmp_div_common_frac_div_s2pl1.bf.value1 = value1;
  TEN_REG_WRITE(TEN_FRAC_DIV_COMMON_REG_ADDR(pDev, FRAC_DIV_S2PL1), tmp_div_common_frac_div_s2pl1.wrd);
  
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV RESET                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_reset(cs_uint16 dev_id, cs_uint8 instance, 
                                      cs_reset_action_t act)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls Fractional Dividers Reset configuration register.       */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_RESET_t tmp_div_cfg_frac_div_reset;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_div_cfg_frac_div_reset.wrd = 0;
      tmp_div_cfg_frac_div_reset.bf.value = 1;
      ten_reset_action(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, cfg_FRAC_DIV_RESET), tmp_div_cfg_frac_div_reset.wrd, act);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV ENABLE                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_enable(cs_uint16 dev_id, cs_uint8 instance, 
                                       cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Fractional Dividers Enable configuration register.      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [value]                                                        */
/*     Fractional Divider clock enable:                             */  
/*      Enabled = 1,                                                */
/*      Disabled = 0.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_ENABLE_t tmp_div_cfg_frac_div_enable;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_div_cfg_frac_div_enable.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_ENABLE));
      tmp_div_cfg_frac_div_enable.bf.value = value;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_ENABLE), tmp_div_cfg_frac_div_enable.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV N                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_n(cs_uint16 dev_id, cs_uint8 instance, 
                                       cs_uint16 value1,
                                       cs_uint16 value0)

/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Value1                                            */
/*              o Value0                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Fractional Dividers Numerator configuration registers.  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [value1]  Fractional Divider Numerator (MSB)                   */
/*                                                                  */
/*   [value0]  Fractional Divider Numerator (LSB).                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_N1_t tmp_div_cfg_frac_div_n1;
  TEN_FRAC_DIV_CFG_FRAC_DIV_N0_t tmp_div_cfg_frac_div_n0;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      
      tmp_div_cfg_frac_div_n0.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_N0) );
      tmp_div_cfg_frac_div_n0.bf.value0 = value0;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_N0), tmp_div_cfg_frac_div_n0.wrd);
      
      tmp_div_cfg_frac_div_n1.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_N1) );
      tmp_div_cfg_frac_div_n1.bf.value1 = value1;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_N1), tmp_div_cfg_frac_div_n1.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV WIDTH                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_width(cs_uint16 dev_id, cs_uint8 instance, 
                                      cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Fractional Dividers Width configuration register.       */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [value]                                                        */
/*     Fractional Divider Denominator Select:                       */
/*        (2^8)  = 00                                               */
/*        (2^16) = 01                                               */
/*        (2^24) = 1x                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_WIDTH_t tmp_div_cfg_frac_div_width;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_div_cfg_frac_div_width.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_WIDTH) );
      tmp_div_cfg_frac_div_width.bf.value = value;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_WIDTH), tmp_div_cfg_frac_div_width.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV S1EN                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_s1en(cs_uint16 dev_id, cs_uint8 instance, 
                                     cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Fractional Dividers Stage 1 Enable configuration register.  */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [value]  Fractional Divider Enable Stage 2 in Sigma Delta.     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_S1EN_t tmp_div_cfg_frac_div_s1en;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_div_cfg_frac_div_s1en.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S1EN) );
      tmp_div_cfg_frac_div_s1en.bf.value = value;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S1EN), tmp_div_cfg_frac_div_s1en.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV S2EN                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_s2en(cs_uint16 dev_id, cs_uint8 instance, 
                                     cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Fractional Dividers Stage 2 Enable configuration        */
/* register.                                                        */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [value]  Fractional Divider Enable Stage 2 in Sigma Delta.     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_S2EN_t tmp_div_cfg_frac_div_s2en;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_div_cfg_frac_div_s2en.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S2EN) );
      tmp_div_cfg_frac_div_s2en.bf.value = value;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S2EN), tmp_div_cfg_frac_div_s2en.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV STAGE 1 PRELOAD            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_s1_preload(cs_uint16 dev_id, cs_uint8 instance, 
                                               cs_uint16 value1,
                                               cs_uint16 value0)

/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Value1                                            */
/*              o Value0                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Fractional Dividers Stage 1 Preload configuration       */
/* register.                                                        */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [value1]  Fractional Divider Stage 1 Preload Value (MSB)       */
/*                                                                  */
/*   [valueo]  Fractional Divider Stage 1 Preload Value (LSB).      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_S1PL1_t tmp_div_cfg_frac_div_s1pl1;
  TEN_FRAC_DIV_CFG_FRAC_DIV_S1PL0_t tmp_div_cfg_frac_div_s1pl0;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_div_cfg_frac_div_s1pl1.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S1PL1) );
      tmp_div_cfg_frac_div_s1pl1.bf.value1 = value1;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S1PL1), tmp_div_cfg_frac_div_s1pl1.wrd);
      
      tmp_div_cfg_frac_div_s1pl0.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S1PL0) );
      tmp_div_cfg_frac_div_s1pl0.bf.value0 = value0;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_S1PL0), tmp_div_cfg_frac_div_s1pl0.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV DITHER                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_dither(cs_uint16 dev_id, cs_uint8 instance, 
                                       cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Fractional Dividers Dither Enable configuration         */
/* register.                                                        */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [value]  Fractional Divider Enable Dithering of 1st Stage in   */
/*     Sigma Delta.                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_DITHER_t tmp_div_cfg_frac_div_dither;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_div_cfg_frac_div_dither.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_DITHER));
      tmp_div_cfg_frac_div_dither.bf.value = value;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_DITHER), tmp_div_cfg_frac_div_dither.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV DS                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_ds(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Fractional Dividers Dither PRBS configuration register. */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [value]                                                        */
/*     Fractional Divider Dither PRBS Select:                       */
/*      (2^8-1)  = 00,                                              */ 
/*      (2^16-1) = 01,                                              */
/*      (2^24-1) = 1x.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_DS_t tmp_div_cfg_frac_div_ds;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_div_cfg_frac_div_ds.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_DS));
      tmp_div_cfg_frac_div_ds.bf.value = value;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_DS), tmp_div_cfg_frac_div_ds.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV INT                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_int(cs_uint16 dev_id, cs_uint8 instance, 
                                    cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Fractional Dividers Integer Divide configuration        */
/* register.                                                        */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [value]  Fractional Divider Integer Divide Value.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_INT_t tmp_div_cfg_frac_div_int;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_div_cfg_frac_div_int.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_INT));
      tmp_div_cfg_frac_div_int.bf.value = value;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_INT), tmp_div_cfg_frac_div_int.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  FRAC DIV CFG FRAC DIV CC                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : FRACDIV                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_frac_div_cfg_frac_div_cc(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Fractional Dividers Clock Control configuration         */
/* register.                                                        */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/*   [value]  Fractional Divider Output Clock Control.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_FRAC_DIV_CFG_FRAC_DIV_CC_t tmp_div_cfg_frac_div_cc;
  T41_t *pDev = NULL;

  if ((instance >= TEN_FRAC_DIV_CFG_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_FRACDIV);
  for (ii=0; ii<TEN_FRAC_DIV_CFG_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_div_cfg_frac_div_cc.wrd = TEN_REG_READ(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_CC));
      tmp_div_cfg_frac_div_cc.bf.value = value;
      TEN_REG_WRITE(TEN_FRAC_DIV_INST_REG_ADDR(pDev, ii, FRAC_DIV_CC), tmp_div_cfg_frac_div_cc.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_FRACDIV);

  return (CS_OK);
}


/********************************************************************/
/* Function: ten_get_frac_div_inst_reg_addr                       */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a non-common fracdiv register.               */
/*                                                                  */
/* Used by macro TEN_FRAC_DIV_INST_REG_ADDR. Given the base address */
/* of a non-common fracdiv register as defined in t41_registers.h,  */
/* and its instance number (0-TEN_FRAC_DIV_CFG_COUNT), calcuates    */
/* the offset and adds it to the base register's address.           */
/********************************************************************/
volatile cs_uint16 * ten_get_frac_div_inst_reg_addr(cs_reg   *pReg,
                                                    cs_uint16 inst )
{
  if (inst >= TEN_FRAC_DIV_CFG_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "gpllx1 instance %d out of range.  s/b < TEN_FRAC_DIV_CFG_COUNT.",
                  inst);
    inst = 0;
  }
  return (pReg + inst * TEN_FRAC_DIV_CFG_STRIDE);
}
