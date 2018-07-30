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
 * ten_glb_misc.c 
 *
 * $Id: ten_glb_misc.c,v 1.33 2013/04/01 17:17:46 khill Exp $
 *
 * APIs for GLB MISC 
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  GLB MISC GSTI                                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_set_gsti(cs_uint16 dev_id, cs_uint8 instance, 
                                cs_uint16 base1,
                                cs_uint16 base0)

/* INPUTS     : o Device Id                                         */
/*              o Instance                                          */
/*              o BASE1                                             */
/*              o BASE0                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Global Statistics unit Time Interval.                   */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..7 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [base1]                                                        */
/*     Most significant bits of Global Statistics unit 0 Time       */
/*     Interval Base, specified in clksys cycles.                   */
/*     When set to '0', the interval is infinite.                   */ 
/*                                                                  */
/*   [base0]                                                        */
/*     Least significant bits of Global Statistics unit 0 Time      */
/*     Interval Base, specified in clksys cycles.                   */
/*     When set to '0', the interval is infinite.                   */ 
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GLB_MISC_GSTI01_t tmp_misc_gsti01;
  TEN_GLB_MISC_GSTI00_t tmp_misc_gsti00;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((instance>=TEN_GLB_MISC_GSTI01_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..7.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  for (ii=0; ii<TEN_GLB_MISC_GSTI01_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_GLB_REG_ADDR(pDev, GSTI01);
      tmp_addr += ii * TEN_GLB_MISC_GSTI01_STRIDE;
      tmp_misc_gsti01.wrd = TEN_REG_READ(tmp_addr);
      tmp_misc_gsti01.bf.BASE1 = base1;
      TEN_REG_WRITE(tmp_addr, tmp_misc_gsti01.wrd);
      
      tmp_addr = TEN_GLB_REG_ADDR(pDev, GSTI00); 
      tmp_addr += ii * TEN_GLB_MISC_GSTI00_STRIDE;
      tmp_misc_gsti00.wrd = TEN_REG_READ(tmp_addr);
      tmp_misc_gsti00.bf.BASE0 = base0;
      TEN_REG_WRITE(tmp_addr, tmp_misc_gsti00.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC SET GSTI PRESCALE                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_set_gsti_prescale(cs_uint16 dev_id, 
                           cs_uint16 prescale)
/* INPUTS     : o Device Id                                         */
/*              o PRESCALE                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects pre-scale value applied to all hardware Global           */
/* Statistics Time Interval timers.                                 */
/*                                                                  */
/* [prescale]                                                       */
/* 0 = global timers enabled each clksys                            */
/* 1 = global timers enabled every 2nd clksys                       */
/* 2 = global timers enabled every 4th clksys                       */
/* 3 = global timers enabled every 8th clksys                       */
/* 4 = global timers enabled every 16th clksys                      */
/* 5 = global timers enabled every 32nd clksys                      */
/* 6 = global timers enabled every 64th clksysc                     */
/* 7 = global timers enabled every 128th clksys                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_GLB_MISC_GSTI_t tmp_misc_gsti;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  tmp_misc_gsti.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI));
  tmp_misc_gsti.bf.PRESCALE = prescale;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, GSTI), tmp_misc_gsti.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC GSTI UPDATE                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_gsti_update(cs_uint16 dev_id, 
                        cs_ctl_t sw, 
                        cs_ctl_t init)
/* INPUTS     : o Device Id                                         */
/*              o SW                                                */
/*              o INIT                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Perform GSTI update.                                             */
/*                                                                  */
/* [sw]  Global Statistics unit Software Trigger Function.          */
/* If enabled, causes a  '0' to '1' transition to update all        */
/* statistics counters tied to this unit.                           */
/*                                                                  */
/* [init]  If enabled, for each bitfield (0-7), causes a '0' to '1' */
/* transition will cause the associated Global Statistics Time      */
/* Interval timers to be set to its specified Base value and cause  */
/* a snapshot to be taken of the associated statistics counters.    */
/* If the Time Interval Base is set to '0', the interval is         */
/* infinite and no snapshot will be taken.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_GLB_MISC_GSTI_t tmp_misc_gsti;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  tmp_misc_gsti.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI));
  
  /* if enabled, perform 0 to 1 transition */
  tmp_misc_gsti.bf.SW = 0;
  tmp_misc_gsti.bf.INIT = 0;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, GSTI), tmp_misc_gsti.wrd);

  tmp_misc_gsti.bf.SW = sw;
  tmp_misc_gsti.bf.INIT = init;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, GSTI), tmp_misc_gsti.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC GSTI INIT UPDATE                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_gsti_init(cs_uint16 dev_id, 
                        cs_ctl_t init)
/* INPUTS     : o Device Id                                         */
/*              o SW                                                */
/*              o INIT                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Perform GSTI update.                                             */
/*                                                                  */
/* [init]  If enabled, for each bitfield (0-7), causes a '0' to '1' */
/* transition will cause the associated Global Statistics Time      */
/* Interval timers to be set to its specified Base value and cause  */
/* a snapshot to be taken of the associated statistics counters.    */
/* If the Time Interval Base is set to '0', the interval is         */
/* infinite and no snapshot will be taken.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_GLB_MISC_GSTI_t tmp_misc_gsti;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  tmp_misc_gsti.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI));
  
  /* if enabled, perform 0 to 1 transition */
  tmp_misc_gsti.bf.INIT = 0;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, GSTI), tmp_misc_gsti.wrd);

  tmp_misc_gsti.bf.INIT = init;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, GSTI), tmp_misc_gsti.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC GSTI SW UPDATE                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_gsti_sw(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Perform GSTI SW update.                                          */
/* Global Statistics unit Software Trigger Function.                */
/* Causes a  '0' to '1' transition to update all                    */
/* statistics counters tied to this unit.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_GLB_MISC_GSTI_t tmp_misc_gsti;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  tmp_misc_gsti.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, GSTI));
  
  /* Perform 0 to 1 transition */
  tmp_misc_gsti.bf.SW = 0;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, GSTI), tmp_misc_gsti.wrd);

  tmp_misc_gsti.bf.SW = 1;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, GSTI), tmp_misc_gsti.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC MRA1 LOSAF0                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_mra1_losaf0(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 los_siv, 
                                   cs_uint16 los_stv)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o LOS SIV                                           */
/*              o LOS STV                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets external Loss of Signal Acceptance Filter for Multi-Rate    */
/* side B interface.                                                */
/*                                                                  */
/*   [instance]  Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)       */
/*                                                                  */
/*   [los_siv]  Data Loss Stable Intermitted threshold Value        */
/*                                                                  */
/*   [los_stv]  Data Loss Stable Threshold Value.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GLB_MISC_MRA1_LOSAF0_t tmp_misc_mra1_losaf0;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GLB_MISC_MRA1_LOSAF0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  for (ii=0; ii<TEN_GLB_MISC_MRA1_LOSAF0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_GLB_REG_ADDR(pDev, MRA1_LOSAF0);
      tmp_addr += ii * TEN_GLB_MISC_MRA1_LOSAF0_STRIDE;
      tmp_misc_mra1_losaf0.wrd = TEN_REG_READ(tmp_addr);
      tmp_misc_mra1_losaf0.bf.LOS_SIV = los_siv;
      tmp_misc_mra1_losaf0.bf.LOS_STV = los_stv;
      TEN_REG_WRITE(tmp_addr, tmp_misc_mra1_losaf0.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC MRA1 LOSAF1                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_mra1_losaf1(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 los_uiv, 
                                   cs_uint16 los_utv)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o LOS UIV                                           */
/*              o LOS UTV                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets external Loss of Signal Acceptance Filter for Multi-Rate    */
/* side B interface.                                                */
/*                                                                  */
/*   [instance]  Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)       */
/*                                                                  */
/*   [los_uiv]  Data Loss Unstable Intermitted threshold Value.     */
/*                                                                  */
/*   [los_utv]  Data Loss Unstable Threshold Value.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GLB_MISC_MRA1_LOSAF1_t tmp_misc_mra1_losaf1;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GLB_MISC_MRA1_LOSAF1_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  for (ii=0; ii<TEN_GLB_MISC_MRA1_LOSAF1_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_GLB_REG_ADDR(pDev, MRA1_LOSAF1);
      tmp_addr += ii * TEN_GLB_MISC_MRA1_LOSAF1_STRIDE;
      tmp_misc_mra1_losaf1.wrd = TEN_REG_READ(tmp_addr);
      tmp_misc_mra1_losaf1.bf.LOS_UIV = los_uiv;
      tmp_misc_mra1_losaf1.bf.LOS_UTV = los_utv;
      TEN_REG_WRITE(tmp_addr, tmp_misc_mra1_losaf1.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC MRB1 LOSAF0                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_mrb1_losaf0(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 los_siv, 
                                   cs_uint16 los_stv)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o LOS SIV                                           */
/*              o LOS STV                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets external Loss of Signal Acceptance Filter for Multi-Rate    */
/* side B interface.                                                */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [los_siv]  Data Loss Stable Intermitted threshold Value        */
/*                                                                  */
/*   [los_stv]  Data Loss Stable Threshold Value.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GLB_MISC_MRB1_LOSAF0_t tmp_misc_mrb1_losaf0;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GLB_MISC_MRB1_LOSAF0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  for (ii=0; ii<TEN_GLB_MISC_MRB1_LOSAF0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_GLB_REG_ADDR(pDev, MRB1_LOSAF0);
      tmp_addr += ii * TEN_GLB_MISC_MRB1_LOSAF0_STRIDE;
      tmp_misc_mrb1_losaf0.wrd = TEN_REG_READ(tmp_addr);
      tmp_misc_mrb1_losaf0.bf.LOS_SIV = los_siv;
      tmp_misc_mrb1_losaf0.bf.LOS_STV = los_stv;
      TEN_REG_WRITE(tmp_addr, tmp_misc_mrb1_losaf0.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC MRB1 LOSAF1                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_mrb1_losaf1(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 los_uiv, 
                                   cs_uint16 los_utv)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o LOS UIV                                           */
/*              o LOS UTV                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets external Loss of Signal Acceptance Filter for Multi-Rate    */
/* side B interface.                                                */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [los_uiv]  Data Loss Unstable Intermitted threshold Value.     */
/*                                                                  */
/*   [los_utv]  Data Loss Unstable Threshold Value.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GLB_MISC_MRB1_LOSAF1_t tmp_misc_mrb1_losaf1;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GLB_MISC_MRB1_LOSAF1_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  for (ii=0; ii<TEN_GLB_MISC_MRB1_LOSAF1_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_GLB_REG_ADDR(pDev, MRB1_LOSAF1);
      tmp_addr += ii * TEN_GLB_MISC_MRB1_LOSAF1_STRIDE;
      tmp_misc_mrb1_losaf1.wrd = TEN_REG_READ(tmp_addr);
      tmp_misc_mrb1_losaf1.bf.LOS_UIV = los_uiv;
      tmp_misc_mrb1_losaf1.bf.LOS_UTV = los_utv;
      TEN_REG_WRITE(tmp_addr, tmp_misc_mrb1_losaf1.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC XFI1 LOSAF0                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_xfi1_losaf0(cs_uint16 dev_id, cs_uint8 instance, 
                                   cs_uint16 los_siv, 
                                   cs_uint16 los_stv)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o LOS SIV                                           */
/*              o LOS STV                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets External Loss of Signal Acceptance Filter for XFI           */
/* interface.                                                       */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [los_siv]  Data Loss Stable Intermitted threshold Value.       */
/*                                                                  */
/*   [los_stv]  Data Loss Stable Threshold Value.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GLB_MISC_XFI1_LOSAF0_t tmp_misc_xfi1_losaf0;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GLB_MISC_XFI1_LOSAF0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  for (ii=0; ii<TEN_GLB_MISC_XFI1_LOSAF0_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
    
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_GLB_REG_ADDR(pDev, XFI1_LOSAF0);
      tmp_addr += ii * TEN_GLB_MISC_XFI1_LOSAF0_STRIDE;
      tmp_misc_xfi1_losaf0.wrd = TEN_REG_READ(tmp_addr);
      tmp_misc_xfi1_losaf0.bf.LOS_SIV = los_siv;
      tmp_misc_xfi1_losaf0.bf.LOS_STV = los_stv;
      TEN_REG_WRITE(tmp_addr, tmp_misc_xfi1_losaf0.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC XFI1 LOSAF1                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_xfi1_losaf1(cs_uint16 dev_id, cs_uint8 instance, 
                               cs_uint16 los_uiv, 
                               cs_uint16 los_utv)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o LOS UIV                                           */
/*              o LOS UTV                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets External Loss of Signal Acceptance Filter for SFI           */
/* interface.                                                       */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [los_uiv]  Data Loss Unstable Intermitted threshold Value.     */
/*                                                                  */
/*   [los_utv]  Data Loss Unstable Threshold Value.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_GLB_MISC_XFI1_LOSAF1_t tmp_misc_xfi1_losaf1;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((instance >= TEN_GLB_MISC_XFI1_LOSAF1_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  for (ii=0; ii<TEN_GLB_MISC_XFI1_LOSAF1_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_GLB_REG_ADDR(pDev, XFI1_LOSAF1);
      tmp_addr += ii * TEN_GLB_MISC_XFI1_LOSAF1_STRIDE;
      tmp_misc_xfi1_losaf1.wrd = TEN_REG_READ(tmp_addr);
      tmp_misc_xfi1_losaf1.bf.LOS_UIV = los_uiv;
      tmp_misc_xfi1_losaf1.bf.LOS_UTV = los_utv;
      TEN_REG_WRITE(tmp_addr, tmp_misc_xfi1_losaf1.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC XLOS CFG CLEAR                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_xlos_cfg_clear(cs_uint16 dev_id, 
                            cs_uint16 clear)
/* INPUTS     : o Device Id                                         */
/*              o CLEAR                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets External LOS Filter common configuration clear state.       */
/*                                                                  */
/*   [clear]  When set, forces XLOS state machines into the         */
/*            clear state.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_GLB_MISC_XLOS_CFG_t tmp_misc_xlos_cfg;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  tmp_misc_xlos_cfg.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XLOS_CFG));
  tmp_misc_xlos_cfg.bf.CLEAR = clear;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, XLOS_CFG), tmp_misc_xlos_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC XLOS CFG PRESCALE                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_xlos_cfg_prescale(cs_uint16 dev_id, 
                            cs_uint16 clear, 
                            cs_uint16 prescale)
/* INPUTS     : o Device Id                                         */
/*              o CLEAR                                             */
/*              o PRESCALE                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets External LOS Filter common configuration pre-scale          */
/* value for XLOS thresholds.                                       */
/*                                                                  */
/*   [prescale]  Pre-scale value for XLOS thresholds.               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_GLB_MISC_XLOS_CFG_t tmp_misc_xlos_cfg;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  tmp_misc_xlos_cfg.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XLOS_CFG));
  tmp_misc_xlos_cfg.bf.PRESCALE = prescale;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, XLOS_CFG), tmp_misc_xlos_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC XLOS INV XFI                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_xlos_inv_xfi(cs_uint16 dev_id, 
                                    cs_uint16 xfi)
/* INPUTS     : o Device Id                                         */
/*              o XFI                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets external LOS Filter input polarity configuration XFI XLOS.  */
/*                                                                  */
/*   [xfi]  When set, XFI XLOS input is treated as active low.      */
/*          When clear, XFI XLOS input is treated as active high.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_GLB_MISC_XLOS_INV_t tmp_misc_xlos_inv;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  tmp_misc_xlos_inv.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XLOS_INV));
  tmp_misc_xlos_inv.bf.XFI = xfi;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, XLOS_INV), tmp_misc_xlos_inv.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC XLOS INV MRB                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_xlos_inv_mrb(cs_uint16 dev_id, 
                                    cs_uint16 mrb)
/* INPUTS     : o Device Id                                         */
/*              o MRB                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets external LOS Filter input polarity configuration MRB XLOS.  */
/*                                                                  */
/*   [mrb]  When set, MRB XLOS input is treated as active low.      */
/*          When clear, MRB XLOS input is treated as active high.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_GLB_MISC_XLOS_INV_t tmp_misc_xlos_inv;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  tmp_misc_xlos_inv.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XLOS_INV));
  tmp_misc_xlos_inv.bf.MRB = mrb;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, XLOS_INV), tmp_misc_xlos_inv.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  GLB MISC XLOS INV MRA                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_xlos_inv_mra(cs_uint16 dev_id, 
                            cs_uint16 mra)
/* INPUTS     : o Device Id                                         */
/*              o MRA                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets external LOS Filter input polarity configuration MRA XLOS.  */
/*                                                                  */
/*   [mra]  When set, MRA XLOS input is treated as active low.      */
/*          When clear, MRA XLOS input is treated as active high.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_GLB_MISC_XLOS_INV_t tmp_misc_xlos_inv;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  tmp_misc_xlos_inv.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XLOS_INV));
  tmp_misc_xlos_inv.bf.MRA = mra;
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, XLOS_INV), tmp_misc_xlos_inv.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}

/* Bugzilla 26510 Start */
/********************************************************************/
/* $rtn_hdr_start  GLB MISC XLOS INV MR                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GLB                                                 */
/* CHIP       : Tenabo                                              */
cs_status ten_glb_misc_xlos_inv_mr(cs_uint16 module_id, 
                                   cs_uint8 slice, 
                                   cs_uint16 active_low)
/* INPUTS     : o Module Id                                         */
/*            : o Slice                                             */
/*            : o Active Low                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets external LOS Filter input polarity configuration MR XLOS.   */
/*                                                                  */
/* [module_id_line] parameter specifies line's module ID            */
/* 16 devices can be registered and module bit indicates line       */
/* or client side of the registered device. The registered device    */
/* is identified by the dev_id bits specified below                 */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module      */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [active_low] parameter is specified as:                      */
/*   0x00 = XLOS input is treated as active low                     */
/*   0x01 = XLOS input is treated as active high                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id;
  TEN_GLB_MISC_XLOS_INV_t tmp_misc_xlos_inv;
  T41_t *pDev = NULL;
  cs_uint16 which_slices = 0;
  cs_char8 *func = "ten_glb_misc_xlos_inv_mr";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);

  if (active_low > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() active_low %d out of range.  s/b 0 or 1.", func, active_low);
    return(CS_ERROR);
  }

  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s() %s, TEN_SLICE_ALL, active_low=%d\n", func, ten_module_strings[module_id&1], active_low);
    which_slices = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    CS_PRINT("%s() %s, %s, active_low=%d\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice], active_low);
    which_slices = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, TEN_SLICE_ALL.", func, slice);
    return(CS_ERROR);
  }



  TEN_DEV_LOCK(dev_id, TEN_ID_GLB);
  tmp_misc_xlos_inv.wrd = TEN_REG_READ(TEN_GLB_REG_ADDR(pDev, XLOS_INV));
  if (module_id & 1) {
    /* Side B */
    if (active_low) {
      tmp_misc_xlos_inv.bf.MRB |= which_slices;   /* Set bit for active low */
    } else {
      tmp_misc_xlos_inv.bf.MRB &= ~which_slices;  /* Clear bit for active high */
    }
  } else {
    /* Side A */
    if (active_low) {
      tmp_misc_xlos_inv.bf.MRA |= which_slices;   /* Set bit for active low */
    } else {
      tmp_misc_xlos_inv.bf.MRA &= ~which_slices;  /* Clear bit for active high */
    }
  }
  TEN_REG_WRITE(TEN_GLB_REG_ADDR(pDev, XLOS_INV), tmp_misc_xlos_inv.wrd);
  /*TEN_MOD_UNLOCK(module_id, TEN_ID_GLB);*/
  TEN_DEV_UNLOCK(dev_id, TEN_ID_GLB);

  return (CS_OK);
}
/* Bugzilla 26510 End */

/* Bugzilla 24956 Start */
/* This table holds the OTU2 line speeds for the different FEC rates */
double ten_otu2_signal_rate[TEN_FEC_MODE_MAX_NUM] =
{
  10709225320LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  11003204050LLU, /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  11465170630LLU, /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  11969134177LLU, /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  12473097721LLU, /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  12641085569LLU, /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  10709225320LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  11213188860LLU, /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  11339179746LLU, /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  10709225320LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  10709225320LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  10037273920LLU, /* TEN_FEC_MODE_NOFEC             = 15,  (FEC not present) */

  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  0,              /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  0,              /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
};

/* This table holds the OTU2e line speeds for the different FEC rates */
double ten_otu2e_signal_rate[TEN_FEC_MODE_MAX_NUM] = 
{
  11095727850LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  11400316460LLU, /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  11878955700LLU, /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  12401107590LLU, /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  12923259490LLU, /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  13097310130LLU, /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  11095727850LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  11617879746LLU, /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  11748417721LLU, /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  11095727850LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  11095727850LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  10399525320LLU, /* TEN_FEC_MODE_NOFEC             = 15   (FEC not present) */
  
  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  0,              /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  0,              /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
};

/* This table holds the OTU1e line speeds for the different FEC rates */
double ten_otu1e_signal_rate[TEN_FEC_MODE_MAX_NUM] = 
{
  11049107140LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  11352415970LLU, /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  11829044120LLU, /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  12349002100LLU, /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  12868960080LLU, /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  13042279410LLU, /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  11049107140LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  11569065126LLU, /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  11699054621LLU, /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  11049107140LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  11049107140LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  10355829830LLU, /* TEN_FEC_MODE_NOFEC             = 15   (FEC not present) */
  
  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  0,              /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  0,              /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
};

/* This table holds the OTU1f line speeds for the different FEC rates */
double ten_otu1f_signal_rate[TEN_FEC_MODE_MAX_NUM] = 
{
  11270089290LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  11579464290LLU, /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  12065625000LLU, /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  12595982140LLU, /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  13126339290LLU, /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  13303125000LLU, /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  11270089290LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  11800446428LLU, /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  11933035714LLU, /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  11270089290LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  11270089290LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  10562946430LLU, /* TEN_FEC_MODE_NOFEC             = 15   (FEC not present) */
  
  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  0,              /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  0,              /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
};


/* This table holds the OTU3 line speeds for the different FEC rates */
double ten_otu3_signal_rate[TEN_FEC_MODE_MAX_NUM] = 
{
  43018413560LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  44199311190LLU, /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  46055007457LLU, /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  48079403390LLU, /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  50103799320LLU, /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  50778597970LLU, /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  43018413560LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  45042809491LLU, /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  45548908474LLU, /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  43018413560LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  43018413560LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  40319218980LLU, /* TEN_FEC_MODE_NOFEC             = 15   (FEC not present) */
  
  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  0,              /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  0,              /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
};

/* This table holds the OTU3e line speeds for the different FEC rates */
double ten_otu3e_signal_rate[TEN_FEC_MODE_MAX_NUM] = 
{
  44570974580LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  45794560000LLU, /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  47717120000LLU, /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  49814400000LLU, /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  51912320000LLU, /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  52611264000LLU, /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  44570974580LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  46668480000LLU, /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  47192832000LLU, /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  44570974580LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  44570974580LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  41597366890LLU, /* TEN_FEC_MODE_NOFEC             = 15   (FEC not present) */
  
  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  49146311070LLU, /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  51779149160LLU, /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
};

/* This table holds the OTU3e1 line speeds for the different FEC rates */
double ten_otu3e1_signal_rate[TEN_FEC_MODE_MAX_NUM] = 
{
  44570974580LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  45794560000LLU, /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  47717120000LLU, /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  49814400000LLU, /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  51912320000LLU, /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  52611264000LLU, /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  44570974580LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  46668480000LLU, /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  47192832000LLU, /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  44570974580LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  44570974580LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  41597366890LLU, /* TEN_FEC_MODE_NOFEC             = 15   (FEC not present) */
  
  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  49146311070LLU, /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  51779149160LLU, /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
};

/* This table holds the OTU3e2 line speeds for the different FEC rates */
double ten_otu3e2_signal_rate[TEN_FEC_MODE_MAX_NUM] = 
{
  44382911390LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  45807212395LLU, /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  47730415969LLU, /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  49828456232LLU, /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  51926496494LLU, /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  52625843248LLU, /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  44382911390LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  46681395838LLU, /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  47205905904LLU, /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  44382911390LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  44382911390LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  41611131870LLU, /* TEN_FEC_MODE_NOFEC             = 15   (FEC not present) */
  
  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  48954272790LLU, /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  51576823120LLU, /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
};

/* Bugzilla 28237 Start */
/* This table holds the OTU3e4 line speeds for the different FEC rates */
double ten_otu3e4_signal_rate[TEN_FEC_MODE_MAX_NUM] = 
{
  44723989430LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  45951706784LLU, /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  47880976916LLU, /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  49985635242LLU, /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  52090293568LLU, /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  52791846344LLU, /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  44723989430LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  46828647753LLU, /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  47354812335LLU, /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  44723989430LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  44723989430LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  41917778326LLU, /* TEN_FEC_MODE_NOFEC             = 15   (FEC not present) */
 
  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  0,              /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  0,              /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
};
/* Bugzilla 28237 End */

/* This table holds the OTU3p line speeds for the different FEC rates */
double ten_otu3p_signal_rate[TEN_FEC_MODE_MAX_NUM] = 
{
  44569554690LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  0,              /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  0,              /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  0,              /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  44569554690LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  0,              /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  0,              /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  44569554690LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  44569554690LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  /* Bug #38545: Support for ODU3+ nofec */
  41773033612LLU, /* TEN_FEC_MODE_NOFEC             = 15   (FEC not present) */
  
  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  0,              /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  0,              /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
};

/* This table holds the OTU3p2 line speeds for the different FEC rates */
double ten_otu3p2_signal_rate[TEN_FEC_MODE_MAX_NUM] = 
{
  45310329038LLU, /* TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)        */
  0,              /* TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)        */
  0,              /* TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)        */
  0,              /* TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)        */
  0,              /* TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)        */
  45310329038LLU, /* TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)        */
  0,              /* TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)       */
  0,              /* TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)       */
  0,              /* TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)        */
  0,              /* TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)        */
  45310329038LLU, /* TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)         */
  45310329038LLU, /* TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)  */
  42467328000LLU, /* TEN_FEC_MODE_NOFEC             = 15   (FEC not present) */
  
  /* Bugzilla #32517, add new UFEC configurations */
  0,              /* TEN_FEC_MODE_DEALLOCATE        = 16,  (0%, Power down)  */
  0,              /* TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)         */
  0,              /* TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)        */
  0,              /* TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)        */
  
};
/* Bugzilla 24956 End */

/* Bugzilla 24956 Start */
/****************************************************************/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
double ten_calculate_signal_rate (cs_uint16 traffic_type, cs_uint16 fec)
/* INPUTS     : o Traffic Type                                  */
/*              o Fec                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : signal rate                                     */
/* DESCRIPTION:                                                 */
/* Get the signal rate for the given traffic type and FEC.  The */
/* signal rate returned is devided by 100 so that it will fit   */
/* into 32 bits.                                                */ 
/*                                                              */
/* [traffic_type] parameter specifies the traffic type          */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0,                 */
/*   TEN_TRAFFIC_TYPE_OTU3                 = 1,                 */
/*   TEN_TRAFFIC_TYPE_OTU3E                = 2,                 */
/*   TEN_TRAFFIC_TYPE_OTU3E1               = 2,                 */
/*   TEN_TRAFFIC_TYPE_OTU3P                = 3,                 */
/*   TEN_TRAFFIC_TYPE_ODTU23               = 4,                 */
/*   TEN_TRAFFIC_TYPE_OTU2                 = 5,                 */
/*   TEN_TRAFFIC_TYPE_OTU2E                = 6,                 */
/*   TEN_TRAFFIC_TYPE_OTU1F                = 7,                 */
/*   TEN_TRAFFIC_TYPE_OC192                = 8,                 */
/*   TEN_TRAFFIC_TYPE_10GE_WAN             = 9,                 */
/*   TEN_TRAFFIC_TYPE_10GE_6_2             = 10,                */
/*   TEN_TRAFFIC_TYPE_10GE_7_1             = 11,                */
/*   TEN_TRAFFIC_TYPE_10GE_7_3             = 12,                */
/*   TEN_TRAFFIC_TYPE_10GFC                = 13,                */
/*   TEN_TRAFFIC_TYPE_8GFC                 = 14,                */
/*   TEN_TRAFFIC_TYPE_4GFC                 = 15,                */
/*   TEN_TRAFFIC_TYPE_2GFC                 = 16,                */
/*   TEN_TRAFFIC_TYPE_1GFC                 = 17,                */
/*   TEN_TRAFFIC_TYPE_5GB_IB               = 18,                */
/*   TEN_TRAFFIC_TYPE_OTU3_NOFEC           = 19,                */
/*   TEN_TRAFFIC_TYPE_10GE                 = 20,                */
/*   TEN_TRAFFIC_TYPE_40GELAN              = 21,                */
/*   TEN_TRAFFIC_TYPE_OC768                = 22,                */
/*   TEN_TRAFFIC_TYPE_OTU3E3               = 23,                */
/*   TEN_TRAFFIC_TYPE_CBR40G_50188149150   = 24,                */
/*   TEN_TRAFFIC_TYPE_OTU3P2               = 25,                */
/*   TEN_TRAFFIC_TYPE_10GE_6_1             = 26,                */
/*   TEN_TRAFFIC_TYPE_10GE_7_2             = 27,                */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28,                */
/*   TEN_TRAFFIC_TYPE_OTU1E                = 29,                */
/*   TEN_TRAFFIC_TYPE_10GE_RA              = 30,                */
/*   TEN_TRAFFIC_TYPE_OC192_OTU2           = 31,                */
/*   TEN_TRAFFIC_TYPE_OC768_OTU3           = 32,                */
/*   TEN_TRAFFIC_TYPE_10GE_TC              = 33,                */
/*   TEN_TRAFFIC_TYPE_OTU2F                = 34,                */
/*   TEN_TRAFFIC_TYPE_OTU3E2               = 35,                */
/*   TEN_TRAFFIC_TYPE_OTU2P                = 36,                */
/*   TEN_TRAFFIC_TYPE_ODUFLEX              = 37,                */
/*   TEN_TRAFFIC_TYPE_ODTU	               = 38,                */
/*   TEN_TRAFFIC_TYPE_10G_IB               = 39,                */
/*   TEN_TRAFFIC_TYPE_12_5G_IB	           = 40,                */
/*   TEN_TRAFFIC_TYPE_SERIAL_40GE          = 41,                */
/*   TEN_TRAFFIC_TYPE_PARALLEL_40GE        = 42,                */
/*   TEN_TRAFFIC_TYPE_TC_40GE              = 43,                */
/*   TEN_TRAFFIC_TYPE_S64_66_40GE          = 44,                */
/*   TEN_TRAFFIC_TYPE_BYPASS               = 45,                */
/*   TEN_TRAFFIC_TYPE_10GFC_TC             = 46                 */
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                 */
/*   TEN_TRAFFIC_TYPE_4GFC_RA              = 48                 */
/*   TEN_TRAFFIC_TYPE_2GFC_RA              = 49                 */
/*   TEN_TRAFFIC_TYPE_1GFC_RA              = 50                 */
/*   TEN_TRAFFIC_TYPE_8GFC_ENH             = 51                 */
/*   TEN_TRAFFIC_TYPE_4GFC_ENH             = 52                 */
/*   TEN_TRAFFIC_TYPE_2GFC_ENH             = 53                 */
/*   TEN_TRAFFIC_TYPE_1GFC_ENH             = 54                 */
/*   TEN_TRAFFIC_TYPE_OTU3E4               = 55                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF            = 56                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_G709        = 57                 */
/*   TEN_TRAFFIC_TYPE_2GISC                = 59                 */
/*   TEN_TRAFFIC_TYPE_1GE                  = 63                 */
/*   TEN_TRAFFIC_TYPE_FDR10_IB             = 64                 */
/*                                                              */
/* The [line_fec] parameter is specified as:                    */
/*   TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)           */
/*   TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)           */
/*   TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)           */
/*   TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)           */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)           */
/*   TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)           */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)          */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)          */
/*   TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)           */
/*   TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)           */
/*   TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)            */
/*   TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)     */
/*   TEN_FEC_MODE_NOFEC             = 15   (FEC not present).   */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*                                                              */
/****************************************************************/
{
  double signal_rate = 0;
  cs_char8 *func = "ten_calculate_signal_rate";  

  CS_PRINT("%s() %s, %s\n",
           func,
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_fec_ovhd_strings[fec]);

        
  switch (traffic_type) {
    case  TEN_TRAFFIC_TYPE_OTU3:
    case  TEN_TRAFFIC_TYPE_OTU3_NOFEC:
    case  TEN_TRAFFIC_TYPE_OC768_OTU3:
      signal_rate = ten_otu3_signal_rate[fec];
      break;
    case  TEN_TRAFFIC_TYPE_OTU3E:
    /*case  TEN_TRAFFIC_TYPE_OTU3E1:*/
      /*signal_rate = ten_otu3e1_signal_rate[fec];*/
      signal_rate = ten_otu3e_signal_rate[fec];
      break;
    case  TEN_TRAFFIC_TYPE_OTU3P:
      signal_rate = ten_otu3p_signal_rate[fec];
      break;
    case  TEN_TRAFFIC_TYPE_OTU3P2:
      signal_rate = ten_otu3p2_signal_rate[fec];
      break;
    case  TEN_TRAFFIC_TYPE_OTU3E2:
      signal_rate = ten_otu3e2_signal_rate[fec];
      break;
    case  TEN_TRAFFIC_TYPE_OTU3E3:
      signal_rate = 54330731160LLU;
      break;
    /* Bugzilla 28237 Start */
    case  TEN_TRAFFIC_TYPE_OTU3E4:
      signal_rate = ten_otu3e4_signal_rate[fec];
      break;
    /* Bugzilla 28237 End */
    case  TEN_TRAFFIC_TYPE_OC768:
      signal_rate = 39813120000LLU;
      break;
    case  TEN_TRAFFIC_TYPE_CBR40G_50188149150:
      signal_rate = 50188149150LLU;
      break;
      

    case  TEN_TRAFFIC_TYPE_OTU2:
    case  TEN_TRAFFIC_TYPE_OC192_OTU2:
    case  TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2:
      signal_rate = ten_otu2_signal_rate[fec];
      break;
    case  TEN_TRAFFIC_TYPE_OTU2E:
      signal_rate = ten_otu2e_signal_rate[fec];
      break;
    case  TEN_TRAFFIC_TYPE_OTU1F:
      signal_rate = ten_otu1f_signal_rate[fec];
      break;
    case  TEN_TRAFFIC_TYPE_OTU2F:
      signal_rate = 0;
      break;
    case  TEN_TRAFFIC_TYPE_OTU1E:
      signal_rate = ten_otu1e_signal_rate[fec];
      break;


    case  TEN_TRAFFIC_TYPE_OC192:
    case  TEN_TRAFFIC_TYPE_10GE_WAN:
      signal_rate = 9953280000LLU;
      break;
    case  TEN_TRAFFIC_TYPE_10GE_6_1:
    case  TEN_TRAFFIC_TYPE_10GE_6_2:
    case  TEN_TRAFFIC_TYPE_10GE_7_1:
    case  TEN_TRAFFIC_TYPE_10GE_7_2:
    case  TEN_TRAFFIC_TYPE_10GE_7_3:
    case  TEN_TRAFFIC_TYPE_10GE:
    case  TEN_TRAFFIC_TYPE_10GE_RA:
    case  TEN_TRAFFIC_TYPE_10GE_TC:
    case  TEN_TRAFFIC_TYPE_10GE_GFPF:  /* Bugzilla 29991 */
    case  TEN_TRAFFIC_TYPE_FDR10_IB:   /* Bugzilla 39242 */
      signal_rate = 10312500000LLU;
      break;
    case TEN_TRAFFIC_TYPE_1GE:  /* Bugzilla 38871 */
      signal_rate = 1250000000LLU;
      break;
    case  TEN_TRAFFIC_TYPE_1GFC:
    case  TEN_TRAFFIC_TYPE_1GFC_RA:
    case  TEN_TRAFFIC_TYPE_1GFC_ENH:
      signal_rate = 1062500000LLU;
      break;
    case  TEN_TRAFFIC_TYPE_2GFC:
    case  TEN_TRAFFIC_TYPE_2GFC_RA:
    case  TEN_TRAFFIC_TYPE_2GFC_ENH:
    case  TEN_TRAFFIC_TYPE_2GISC:
      signal_rate = 2125000000LLU;
      break;
    case  TEN_TRAFFIC_TYPE_4GFC:
    case  TEN_TRAFFIC_TYPE_4GFC_RA:
    case  TEN_TRAFFIC_TYPE_4GFC_ENH:
      signal_rate = 4250000000LLU;
      break;
    case  TEN_TRAFFIC_TYPE_8GFC:
    case  TEN_TRAFFIC_TYPE_8GFC_RA:
    case  TEN_TRAFFIC_TYPE_8GFC_ENH:
      signal_rate = 8500000000LLU;
      break;
    case  TEN_TRAFFIC_TYPE_10GFC:
    case  TEN_TRAFFIC_TYPE_10GFC_TC:  /* Bugzilla 24360 */
      signal_rate = 10518750000LLU;
      break;
    default:
      CS_PRINT("%s() traffic_type %d not supported \n", func, traffic_type);
      
      signal_rate = 0;
      break;
    
  }

  CS_PRINT("%s() signal_rate =%f\n",  func,  signal_rate);

  return (signal_rate);
}
/* Bugzilla 24956 End */

