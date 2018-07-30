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
 * ten_dm.c
 *
 * Delay Measurement (DM) related code is implemented here.
 *
 * $Id: ten_dm.c,v 1.9 2014/04/04 17:21:44 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  TEN N40G TX2RX Delay Measurement                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_tx2rx_dm(cs_uint16 module_id, cs_uint16 tcmpm)
/* INPUTS     : o Device Id                                         */
/*              o TCMPM                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Demonstate 40G Delay Measurement feature.                        */
/*                                                                  */
/*   [module_id]                                                    */
/*     0 = (dev_id<<8) | TEN_MODULE_A                               */
/*     1 = (dev_id<<8) | TEN_MODULE_B                               */
/*                                                                  */
/*   [tcmpm]                                                        */
/*     TEN_DM_PM   = 1, (DMp)                                       */
/*     TEN_DM_TCM6 = 2, (DMt6)                                      */
/*     TEN_DM_TCM5 = 3, (DMt5)                                      */
/*     TEN_DM_TCM4 = 4, (DMt4)                                      */
/*     TEN_DM_TCM3 = 5, (DMt3)                                      */
/*     TEN_DM_TCM2 = 6, (DMt2)                                      */
/*     TEN_DM_TCM1 = 7, (DMt1)                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 dmacpt_state;
  cs_uint16 timeout;
  cs_uint16 newstate;

  if ((tcmpm < TEN_DM_PM) || (tcmpm >  TEN_DM_TCM1)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "tcmpm out of range.  s/b 1..7.");
    return (CS_ERROR);
  }
  
  CS_PRINT( "Reset the DM block\n");
  ten_mpif_global_reset_dm_mpif_t41(dev_id, CS_RESET_ASSERT);
  ten_mpif_global_reset_dm_logic_t41(dev_id, CS_RESET_ASSERT);
  TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
  ten_mpif_global_reset_dm_mpif_t41(dev_id, CS_RESET_DEASSERT);
  ten_mpif_global_reset_dm_logic_t41(dev_id, CS_RESET_DEASSERT);
  
  ten_dm_intr(dev_id, 1);

  CS_PRINT("Set up Launch\n");
  ten_dm_set_dmsel_cfg_n40g_txsrc(dev_id, TEN_MOD_ID_TO_MOD_NUM(module_id));
  ten_n40g_otnt4x_dmcfg2_insert_enable(module_id, tcmpm, CS_ENABLE);
  ten_n40g_otnt4x_dmcsfcfg_sel(module_id, tcmpm);

  CS_PRINT("Set up Stop\n");
  ten_dm_set_dmsel_cfg_n40g_rxsrc(dev_id, TEN_MOD_ID_TO_MOD_NUM(module_id));
  ten_n40g_oohr_dmcsf_dm_filt(module_id, TEN_DM_FILT_0_FRMS);
  
  /* Select a single filtered DM and send to Delay Counter. */
  ten_n40g_oohr_dmcsf_cfgdm(module_id, tcmpm);
 
  CS_PRINT("******************** START TESTING ********************\n");
  
  CS_PRINT("---------- Test DM generator ----------\n");

  CS_PRINT("Select generator as Tx source\n");
  ten_n40g_otnt4x_dmcfg1_gen_enable(module_id, tcmpm, TEN_DM_INTERNALLY_GENERATED); 

  CS_PRINT("Enable DM Counter Mode\n");
  ten_dm_dmsel_cfg_cnt_stop(dev_id, TEN_DM_CNT_STOP_SAT);

  TEN_MDELAY(6); /* the above enable causes the generator state to propagate */

  dmacpt_state = ten_n40g_oohr_get_dmcsf_stat_dmacpt(module_id, tcmpm);
  CS_PRINT("Current DM Rx state=%d\n", dmacpt_state);
  newstate = dmacpt_state ? 0 : 1;
  
  CS_PRINT("Trigger generator to toggle state\n");
  ten_n40g_otnt4x_dmcsfcfg_dm_trigger(module_id);

  timeout = 5;
  CS_PRINT("Wait for DM Rx dmacpt_state=%d to newstate=%d\n", dmacpt_state, newstate);
  while ((dmacpt_state != newstate) && (timeout > 0) ) {
    dmacpt_state = ten_n40g_oohr_get_dmcsf_stat_dmacpt(module_id, tcmpm);
    CS_PRINT("DM Rx dmacpt_state=%d...\n", dmacpt_state);
    timeout--;
    CS_MDELAY(6);
  }

  if (timeout == 0) {
    CS_PRINT("DM ACPT did not toggle\n");
    return (CS_ERROR);
  }

  if (ten_dm_get_intr(dev_id)) {
    CS_PRINT("DM_INTR_DM_INT is ACTIVE\n");
  }
  else {
    CS_PRINT("DM_INTR_DM_INT is INACTIVE\n");
  }
  
  CS_PRINT("dm_delay=%d\n",  ten_dm_get_delay(dev_id));
  CS_PRINT("dm_delay_us=%f\n",  ten_dm_get_delay_us(dev_id));

  CS_PRINT("******************** STOP TESTING ********************\n");
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  TEN N10G TX2RX Delay Measurement                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_tx2rx_dm(cs_uint16 module_id, cs_uint16 slice,
                            cs_uint16 tcmpm)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o TCMPM                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Demonstate 10G Delay Measurement feature.                        */
/*                                                                  */
/*   [module_id]                                                    */
/*     0 = (dev_id<<8) | TEN_MODULE_A                               */
/*     1 = (dev_id<<8) | TEN_MODULE_B                               */
/*                                                                  */
/*   [slice]                                                        */
/*     0x00 = TEN_SLICE0                                            */
/*     0x01 = TEN_SLICE1                                            */
/*     0x02 = TEN_SLICE2                                            */
/*     0x03 = TEN_SLICE3                                            */
/*                                                                  */
/*   [tcmpm]                                                        */
/*     TEN_DM_PM   = 1, (DMp)                                       */
/*     TEN_DM_TCM6 = 2, (DMt6)                                      */
/*     TEN_DM_TCM5 = 3, (DMt5)                                      */
/*     TEN_DM_TCM4 = 4, (DMt4)                                      */
/*     TEN_DM_TCM3 = 5, (DMt3)                                      */
/*     TEN_DM_TCM2 = 6, (DMt2)                                      */
/*     TEN_DM_TCM1 = 7, (DMt1)                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  /*                                                                                  */
  /*  DM Generation (launch)                                                          */
  /*  DM Termination (stop)                                                           */
  /*  DM Forwarding                                                                   */
  /*  DM Pass Through                                                                 */
  /*                                                                                  */
  /*   DM-->TX(launch)|--^-->|RX(launch)--XCON--TX(passthru)|--^-->|RX(passthru)--+-- */
  /*                  |      |                              |      |              |   */
  /*                  |      |                              |      |     OHPP         */
  /*                  |      |                              |      |              |   */
  /*   DM<--RX(stop)<-|<--^--|<-TX(stop)--XCON--RX(forward)-|<--^--|TX(forward)<--+-- */
  /*                                                                                  */

  /*   lch  = integer - sets the launch channel for the delay measurement, */
  /*   this channel will initiate the delay counter.                       */
  /*   sch  = integer - sets the stop channel for the delay measurement,   */
  /*   this channel will look for the DM byte in the OH (PM&TCM (R2,C3).   */

  /* my $DM_BS = 26; # DM is in row 2, col 3, which is byte #26 of OxU OHPP stream */
  /* my $DM_OH = 18; # DM is in row 2, col 3, which is byte #18 of OxU OH */

  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 dmacpt_state;
  cs_uint16 timeout;
  cs_uint16 newstate;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  if ((tcmpm < TEN_DM_PM) || (tcmpm >  TEN_DM_TCM1)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "tcmpm out of range.  s/b 1..7.");
    return (CS_ERROR);
  }
  
  CS_PRINT( "Reset the DM block\n");
  ten_mpif_global_reset_dm_mpif_t41(dev_id, CS_RESET_ASSERT);
  ten_mpif_global_reset_dm_logic_t41(dev_id, CS_RESET_ASSERT);
  TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
  ten_mpif_global_reset_dm_mpif_t41(dev_id, CS_RESET_DEASSERT);
  ten_mpif_global_reset_dm_logic_t41(dev_id, CS_RESET_DEASSERT);
  
  ten_dm_intr(dev_id, 1);

  CS_PRINT("Set up Launch\n");
  ten_dm_set_dmsel_cfg_n10g_txsrc(dev_id, TEN_MOD_ID_TO_MOD_NUM(module_id), slice);
  ten_n10g_otnt_dmcfg2_insert_enable(module_id, slice, tcmpm, CS_ENABLE);
  /* ten_n10g_otnt_dmcfg1_gen_enable(module_id, slice, tcmpm, TEN_DM_INTERNALLY_GENERATED);   */
  ten_n10g_otnt_dmcsfcfg_sel(module_id, slice, tcmpm);

  CS_PRINT("Set up Stop\n");
  ten_dm_set_dmsel_cfg_n10g_rxsrc(dev_id, TEN_MOD_ID_TO_MOD_NUM(module_id), slice);
  ten_n10g_oohr_dmcsf_dm_filt(module_id, slice, TEN_DM_FILT_0_FRMS);
  
  /* Select a single filtered DM and send to Delay Counter. */
  ten_n10g_oohr_dmcsf_cfgdm(module_id, slice, tcmpm);
 
  /* ten_n10g_otnt_set_wrmd(module_id, slice, 3);   */
  /* ten_dm_set_threshold(dev_id, 100);  */
                               
  CS_PRINT("******************** START TESTING ********************\n");
  
  CS_PRINT("---------- Test DM generator ----------\n");

  CS_PRINT("Select generator as Tx source\n");
  ten_n10g_otnt_dmcfg1_gen_enable(module_id, slice, tcmpm, TEN_DM_INTERNALLY_GENERATED); 

  CS_PRINT("Enable DM Counter Mode\n");
  ten_dm_dmsel_cfg_cnt_stop(dev_id, TEN_DM_CNT_STOP_SAT);

  CS_MDELAY(6); /* the above enable causes the generator state to propagate */

  dmacpt_state = ten_n10g_oohr_get_dmcsf_stat_dmacpt(module_id, slice, tcmpm);
  CS_PRINT("Current DM Rx state=%d\n", dmacpt_state);
  newstate = dmacpt_state ? 0 : 1;
  
  CS_PRINT("Trigger generator to toggle state\n");
  ten_n10g_otnt_dmcsfcfg_dm_trigger(module_id, slice);

  timeout = 5;
  CS_PRINT("Wait for DM Rx dmacpt_state=%d to newstate=%d\n", dmacpt_state, newstate);
  while ((dmacpt_state != newstate) && (timeout > 0) ) {
    dmacpt_state = ten_n10g_oohr_get_dmcsf_stat_dmacpt(module_id, slice, tcmpm);
    CS_PRINT("DM Rx dmacpt_state=%d...\n", dmacpt_state);
    timeout--;
    CS_MDELAY(6);
  }

  if (timeout == 0) {
    CS_PRINT("DM ACPT did not toggle\n");
    return (CS_ERROR);
  }

  if (ten_dm_get_intr(dev_id)) {
    CS_PRINT("DM_INTR_DM_INT is ACTIVE\n");
  }
  else {
    CS_PRINT("DM_INTR_DM_INT is INACTIVE\n");
  }
  
  CS_PRINT("dm_delay=%d\n",  ten_dm_get_delay(dev_id));
  CS_PRINT("dm_delay_us=%f\n",  ten_dm_get_delay_us(dev_id));

  CS_PRINT("******************** STOP TESTING ********************\n");
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  DM DMSEL CFG                                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_status ten_dm_set_dmsel_cfg_n10g_txsrc(cs_uint16 dev_id, 
                                          cs_uint16 module_num,
                                          cs_uint8  slice)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Mux select the 10 DMACK TX in N10G mode for the module num       */
/* (A or B) and the specified slice.                                */
/*                                                                  */
/*   [module_num]                                                   */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/*   [slice]                                                        */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_DM_DMSEL_CFG_t tmp_dmsel_cfg;
  cs_uint16 tmp_src = 0;
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  if (module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "module_num out of range");
    return (CS_ERROR);
  }
  
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_DM);
  
  tmp_src = (module_num<<3);
  /* Bugzilla #42300 - Fix klocwork warnings */
  tmp_src |= (cs_uint16)slice;
  
  tmp_dmsel_cfg.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DMSEL_CFG));
  tmp_dmsel_cfg.bf.TXSRC = tmp_src;
  TEN_REG_WRITE(TEN_DM_REG_ADDR(pDev, DMSEL_CFG), tmp_dmsel_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_DM);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  DM DMSEL CFG                                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_status ten_dm_set_dmsel_cfg_n10g_rxsrc(cs_uint16 dev_id, 
                                          cs_uint16 module_num,
                                          cs_uint8  slice)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Mux select the 10 DMACK RX in N10G mode for the module num       */
/* (A or B) and the specified slice.                                */
/*                                                                  */
/*   [module_num]                                                   */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/*   [slice]                                                        */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_DM_DMSEL_CFG_t tmp_dmsel_cfg;
  cs_uint16 tmp_src = 0;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  if (module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "module_num out of range");
    return (CS_ERROR);
  }
  
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_DM);

  /* Bugzilla #42300 - Fix klocwork warnings */
  tmp_src = (cs_uint16)(module_num<<3);
  tmp_src |= (cs_int16)slice;
  
  tmp_dmsel_cfg.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DMSEL_CFG));
  tmp_dmsel_cfg.bf.RXSRC = tmp_src;
  TEN_REG_WRITE(TEN_DM_REG_ADDR(pDev, DMSEL_CFG), tmp_dmsel_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_DM);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  DM DMSEL CFG                                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_status ten_dm_set_dmsel_cfg_n40g_txsrc(cs_uint16 dev_id, 
                                          cs_uint16 module_num)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Mux select the 10 DMACK TX in N40G mode for the module num       */
/* (A or B).                                                        */
/*                                                                  */
/*   [module_num]                                                   */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_DM_DMSEL_CFG_t tmp_dmsel_cfg;
  cs_uint16 tmp_src = 0;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  if (module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "module_num out of range");
    return (CS_ERROR);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_DM);
  
  tmp_src = (1<<2);
  tmp_src |= (module_num<<3);
  
  tmp_dmsel_cfg.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DMSEL_CFG));
  tmp_dmsel_cfg.bf.TXSRC = tmp_src;
  TEN_REG_WRITE(TEN_DM_REG_ADDR(pDev, DMSEL_CFG), tmp_dmsel_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_DM);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  DM DMSEL CFG                                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_status ten_dm_set_dmsel_cfg_n40g_rxsrc(cs_uint16 dev_id, 
                                          cs_uint16 module_num)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Mux select the 10 DMACK TX in N10G mode for the module num       */
/* (A or B).                                                        */
/*                                                                  */
/*   [module_num]                                                   */
/*   [module_num]                                                   */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_DM_DMSEL_CFG_t tmp_dmsel_cfg;
  cs_uint16 tmp_src = 0;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  if (module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "module_num out of range");
    return (CS_ERROR);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_DM);

  tmp_src = (1<<2);
  tmp_src |= (module_num<<3);
  
  tmp_dmsel_cfg.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DMSEL_CFG));
  tmp_dmsel_cfg.bf.RXSRC = tmp_src;
  TEN_REG_WRITE(TEN_DM_REG_ADDR(pDev, DMSEL_CFG), tmp_dmsel_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_DM);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  DM DMSEL CFG CNT STOP                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_status ten_dm_dmsel_cfg_cnt_stop(cs_uint16 dev_id, 
                                    cs_uint16 dm_cnt_stop)
/* INPUTS     : o Device Id                                         */
/*              o DM CNT STOP                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets DM Delay Counter configuration.                             */
/*                                                                  */
/*   [dm_cnt_stop]                                                  */
/*    TEN_DM_CNT_STOP_SAT (0) = DM delay counter saturate at        */
/*      maximum if DMACK is not received.                           */
/*    TEN_DM_CNT_STOP_THR (1) = DM delay counter stops when         */
/*      DM_DELAY = DM_THRESH.                                       */
/*    TEN_DM_CNT_STOP_ROV (2) = DM delay counter rollover and keeps */
/*      running but stops upon receiving DMRX.                      */
/*    EN_DM_CNT_STOP_FRC (3) = Force stop.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_DM_DMSEL_CFG_t tmp_dmsel_cfg;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  if ( dm_cnt_stop > TEN_DM_CNT_STOP_FRC) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "dm_cnt_stop out of range");
    return (CS_ERROR);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_DM);
  tmp_dmsel_cfg.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DMSEL_CFG));
  tmp_dmsel_cfg.bf.DM_CNT_STOP = dm_cnt_stop;
  TEN_REG_WRITE(TEN_DM_REG_ADDR(pDev, DMSEL_CFG), tmp_dmsel_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_DM);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  DM SET THRESHOLD                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_status ten_dm_set_threshold(cs_uint16 dev_id, 
                               cs_uint32 dm_thresh)
/* INPUTS     : o Device Id                                         */
/*              o DM THRESH                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures DM threshold.                                         */
/* DM threshold time period = 16xCLKSYS*DM_THRESH                   */
/*                                                                  */
/*   [dm_thresh]                                                    */
/*    32 bit value for DM_DM_THRESH_CFG1/DM_DM_THRESH_CFG0          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_DM_DM_THRESH_CFG1_t tmp_dm_thresh_cfg1;
  TEN_DM_DM_THRESH_CFG0_t tmp_dm_thresh_cfg0;
  cs_uint16 tmp_dm_thresh;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_DM);
  tmp_dm_thresh_cfg1.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DM_THRESH_CFG1));
  tmp_dm_thresh = (cs_uint16)((dm_thresh >> 16) & 0x0000FFFF);
  tmp_dm_thresh_cfg1.bf.DM_THRESH1 = tmp_dm_thresh;
  TEN_REG_WRITE(TEN_DM_REG_ADDR(pDev, DM_THRESH_CFG1), tmp_dm_thresh_cfg1.wrd);
  
  tmp_dm_thresh_cfg0.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DM_THRESH_CFG0));
  tmp_dm_thresh = (cs_uint16)(dm_thresh & 0x0000FFFF);
  tmp_dm_thresh_cfg0.bf.DM_THRESH0 = tmp_dm_thresh;
  TEN_REG_WRITE(TEN_DM_REG_ADDR(pDev, DM_THRESH_CFG0), tmp_dm_thresh_cfg0.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_DM);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  DM GET DELAY                                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_uint32 ten_dm_get_delay(cs_uint16 dev_id) 
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 32 bit Delay                                        */
/* DESCRIPTION:                                                     */
/* Returns 32 bit value of DM time period from start to end         */
/* measured by T=16*CLKSYS.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_DM_DM_DELAY0_t tmp_dm_delay0;
  TEN_DM_DM_DELAY1_t tmp_dm_delay1;
  cs_uint32 dm_delay;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);
  
  tmp_dm_delay1.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DM_DELAY1));
  dm_delay = (cs_uint32)tmp_dm_delay1.bf.DM_DELAY1;
  dm_delay<<=16;
  dm_delay&=0xFFFF0000;
  
  tmp_dm_delay0.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DM_DELAY0));
  dm_delay |= (cs_uint32)(tmp_dm_delay0.wrd) & 0x0000FFFF;
  
  CS_PRINT("Read the DM Counter Delay = 0x%08X (%0d)\n", dm_delay, dm_delay);
  return (dm_delay);
}

/********************************************************************/
/* $rtn_hdr_start  DM GET DELAY US                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
double ten_dm_get_delay_us(cs_uint16 dev_id) 
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Double                                              */
/* DESCRIPTION:                                                     */
/* Returns a cs_double value for DM time in microseconds (us).      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_DM_DM_DELAY0_t tmp_dm_delay0;
  TEN_DM_DM_DELAY1_t tmp_dm_delay1;
  cs_uint32 dm_delay;
  cs_double dm_delay_us;
  ten_dev_cb_t *pdevcb;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  tmp_dm_delay1.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DM_DELAY1));
  dm_delay = (cs_uint32)tmp_dm_delay1.bf.DM_DELAY1;
  dm_delay<<=16;
  dm_delay&=0xFFFF0000;
  
  tmp_dm_delay0.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, DM_DELAY0));
  dm_delay |= (cs_uint32)(tmp_dm_delay0.wrd) & 0x0000FFFF;
  CS_PRINT("sysclock=%d\n", pdevcb->sysclock);
  dm_delay_us = (1000000 * 16.0 * dm_delay) / pdevcb->sysclock;
  CS_PRINT("Read the DM Counter Delay = 0x%08X (%0d) (%f usec)\n", dm_delay, dm_delay, dm_delay_us);
  return (dm_delay_us);
}

/********************************************************************/
/* $rtn_hdr_start  DM INTR                                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_status ten_dm_intr(cs_uint16 dev_id, 
                      cs_uint16 dm_int)
/* INPUTS     : o Device Id                                         */
/*              o DM INT                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This interrupt is triggered when DM_DELAY time period exceeds    */
/* DM_THRESH time period.                                           */
/* Note: This interrupt will not trigger in Threshold Stop mode     */
/* (DM_CNT_STOP=1) because DM_DELAY will never exceed DM_THRESH.    */
/*                                                                  */
/*   [dm_int]                                                       */
/*   (R):RW1C, Write '1' to clear.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_DM_INTR_t tmp_intr;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_DM);
  tmp_intr.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, INTR));
  tmp_intr.bf.DM_INT = dm_int;
  TEN_REG_WRITE(TEN_DM_REG_ADDR(pDev, INTR), tmp_intr.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_DM);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  DM GET INTR                                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : DM                                                  */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_dm_get_intr(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This interrupt is triggered when DM_DELAY time period exceeds    */
/* DM_THRESH time period.                                           */
/* Note: This interrupt will not trigger in Threshold Stop mode     */
/* (DM_CNT_STOP=1) because DM_DELAY will never exceed DM_THRESH.    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_DM_INTR_t tmp_intr;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);
  tmp_intr.wrd = TEN_REG_READ(TEN_DM_REG_ADDR(pDev, INTR));
  return (tmp_intr.bf.DM_INT);
}






