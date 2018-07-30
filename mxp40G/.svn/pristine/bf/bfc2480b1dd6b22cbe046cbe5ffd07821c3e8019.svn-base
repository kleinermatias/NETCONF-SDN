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
 * ten_n40g_gblr4x.c
 *
 * N40G related code is implemented here.
 *
 * $Id: ten_n40g_gblr4x.c,v 1.8 2013/02/22 20:44:38 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N40G GBLR4X SET DATA PATH CONFIG REGISTER    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_gblr4x_set_dpcfg0(cs_uint16 module_id, 
                                     cs_uint16 kpasel,
                                     cs_uint16 bypcfg,
                                     cs_uint16 mdpcfg, 
                                     cs_uint16 bysel,
                                     cs_uint16 oby,
                                     cs_uint16 sby)
/* INPUTS     : o Module Id                                     */
/*              o KPASEL                                        */
/*              o BYPCFG                                        */
/*              o MDPCFG                                        */
/*              o BYSEL                                         */
/*              o OBY                                           */
/*              o SBY                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Data Path Configuration Register.   */
/*                                                              */
/* The [kpasel] parameter is specified as:                      */
/*   KPA Input Select.                                          */
/*   0 = The signal to the KPA is VC-4-256 payload.             */
/*   1 = The signalto the KPA is the OPU-3 payload or the       */
/*       unaligned line interface input (as determined by OBY). */
/*                                                              */
/* The [bypcfg] parameter is specified as:                      */
/*   Bypass Configuration                                       */
/*   0 = OTN reverse multiplexing support mode                  */
/*   1 = Generic Split mode                                     */
/*                                                              */
/* The [mdpcfg] parameter is specified as:                      */
/*   Tributary Data Path Configuration                          */
/*   0b00 = OTN Deaggregation Mode                              */
/*   0b01 = Reserved                                            */
/*   0b10 = SDH Reverse Multiplexing Mode - 16-byte interleave  */
/*   0b11 = SDH Reverse Multiplexing Mode - 64-byte interleave  */
/*                                                              */
/* The [bysel] parameter is specified as:                       */
/*   Bypass Input Select.                                       */
/*   0 = The signal to the cross-connect on the bypass          */
/*       interface will be the output of the OTN aligner. When  */
/*   1 = The signal to the bypass interface will be the         */
/*       unaligned payload from the OTN de-wrapper or the       */
/*       unaligned line interface input as determined by the    */
/*       state of the OBY register.                             */
/*                                                              */
/* The [oby] parameter is specified as:                         */
/*   OTN Bypass Enable.                                         */
/*   0                                                          */
/*   1 = Bypasses all OTN and FEC processing                    */
/*                                                              */
/* The [sby] parameter is specified as:                         */
/*   SDH Bypass Enable.                                         */
/*   0                                                          */
/*   1 = The SONET/SDH framer is bypassed.                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_gblr4x_dpcfg0;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_gblr4x_set_dpcfg0";  
  CS_PRINT("%s() %s, kpasel=%d, bypcfg=%d, mdpcfg=%d, bysel=%d, oby=%d, sby=%d\n", 
           func, ten_module_strings[module_id&1], kpasel, bypcfg, mdpcfg, bysel, oby, sby);
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_gblr4x_dpcfg0.bf.KPASEL = kpasel;
  tmp_gblr4x_dpcfg0.bf.BYPCFG = bypcfg;
  tmp_gblr4x_dpcfg0.bf.MDPCFG = mdpcfg;
  tmp_gblr4x_dpcfg0.bf.BYSEL = bysel;
  tmp_gblr4x_dpcfg0.bf.OBY = oby;
  tmp_gblr4x_dpcfg0.bf.SBY = sby;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_gblr4x_dpcfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G GET GLOBAL LOS STATUS                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_boolean ten_n40g_get_global_los_status(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE (LOS occurred) or FALSE (No LOS occurred)  */
/* DESCRIPTION:                                                 */
/* This bit is set to logic one when Loss of Signal defect      */
/* occurs.                                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_LOSSTAT_t tmp_gblr4x_losstat;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  tmp_gblr4x_losstat.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, LOSSTAT));

  return (tmp_gblr4x_losstat.bf.LOSF == 1);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET PRBS HYSTERESIS REGISTER            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_gblr4x_phys(cs_uint16 module_id, 
                                   cs_uint16 phys)
/* INPUTS     : o Module Id                                     */
/*              o PHYS                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* PRBS Hysteresis. If more than PHYS bits do not match the     */
/* predicted PRBS sequence (and increment an internal error     */
/* counter beyond the PHYS threshold), a new sample of 8192     */
/* bits (64 x 128 bit words) length is taken from the           */
/* observed stream for PRBS detection. If less than PHYS of     */
/* these 8192 bits do not deviate from the predicted PRBS       */
/* sequence, the respective PRBS is considered to be found.     */
/*                                                              */
/* The [phys] parameter is specified as:                        */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_PHYS_t tmp_gblr4x_phys;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblr4x_phys.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PHYS));
  tmp_gblr4x_phys.bf.PHYS = phys;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PHYS), tmp_gblr4x_phys.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET PRBS DEASSERT HYSTERESIS REGISTER   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_gblr4x_pdhy(cs_uint16 module_id, 
                                   cs_uint16 pdhy1,
                                   cs_uint16 pdhy0)
/* INPUTS     : o Module Id                                     */
/*              o PDHY1                                         */
/*              o PDHY0                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* PRBS Deassert Hysteresis. If PDHY bits have failed to match  */
/* the internally generated PRBS sequence (and incremented an   */
/* internal error counter beyond the PDHY threshold), the PRBS  */
/* is regarded as lost. If PDHY is set to 0xffffffff, the KPA   */
/* state machine will not retrigger automatically but has to be */
/* reset using PCLR.                                            */
/*                                                              */
/* The [pdhy1] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [pdhy1] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_PDHY1_t tmp_gblr4x_pdhy1;
  TEN_N40G_GBLR4X_PDHY0_t tmp_gblr4x_pdhy0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblr4x_pdhy1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PDHY1));
  tmp_gblr4x_pdhy1.bf.PDHY1 = pdhy1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PDHY1), tmp_gblr4x_pdhy1.wrd);
  tmp_gblr4x_pdhy0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PDHY0));
  tmp_gblr4x_pdhy0.bf.PDHY0 = pdhy0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PDHY0), tmp_gblr4x_pdhy0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G GET 40G KPA STATUS                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_n40g_get_kpa_status(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Known Pattern Analyzer Status                   */
/* DESCRIPTION:                                                 */
/* Returns the status of the 40G known pattern analyzer:        */
/* PF = Fixed Pattern Found. Set when the acceptance filter     */
/*      defined by PAFxx has accepted the pattern specified by  */
/*      PATa, PATb, MASK and FMM.                               */
/* PSTAT[1:0] = PRBS Status                                     */
/*   0b00 = No PRBS found                                       */
/*   0b01 = PN-11                                               */
/*   0b10 = PN-23                                               */
/*   0b11 = PN-31                                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_KPASTAT_t tmp_gblr4x_kpastat;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  tmp_gblr4x_kpastat.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPASTAT));

  return (tmp_gblr4x_kpastat.wrd);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 40G KPA ANALYZER                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                         */
cs_status ten_n40g_config_kpa(cs_uint16 module_id,
                              cs_uint16 fmm,
                              cs_uint16 prbs_stats_time_int,
                              cs_uint16 fixed_stats_time_int)

/* INPUTS     : o Module Id                                     */
/*              o Fixed Pattern Match Method                    */
/*              o PRBS Statistics Time Interval                 */
/*              o Fixed Pattern Match Time Interval             */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the 40G Known Pattern Analyzer.                    */
/*                                                              */
/* The [fmm] parameter is specified as:                         */
/* (Fixed Pattern Match Method)                                 */
/*   0 = Stream matches PATa                                    */
/*   1 = Stream matches PATb                                    */
/*   2 = Stream matches PATa or PATb                            */
/*                                                              */
/* The [prbs_stats_time_int] parameter is specified as:         */
/*   0 = 1st internal timing generator                          */
/*   1 = 2nd internal timing generator                          */
/*   2 = 3rd internal timing generator                          */
/*   3 = 4th internal timing generator                          */
/*   4 = 5th internal timing generator                          */
/*   5 = 6th internal timing generator                          */
/*   6 = Software controlled timing generator                   */
/*   7 = Timing generator controlled by external hardware       */
/*                                                              */
/* The [fixed_stats_time_int] parameter is specified as:        */
/*   0 = 1st internal timing generator                          */
/*   1 = 2nd internal timing generator                          */
/*   2 = 3rd internal timing generator                          */
/*   3 = 4th internal timing generator                          */
/*   4 = 5th internal timing generator                          */
/*   5 = 6th internal timing generator                          */
/*   6 = Software controlled timing generator                   */
/*   7 = Timing generator controlled by external hardware       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_KPACFG0_t tmp_gblr4x_kpacfg0;
  TEN_N40G_GBLR4X_KPACFG1_t tmp_gblr4x_kpacfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_gblr4x_kpacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG0));
  tmp_gblr4x_kpacfg0.bf.FMM = fmm;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG0), tmp_gblr4x_kpacfg0.wrd);
  
  tmp_gblr4x_kpacfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG1));
  tmp_gblr4x_kpacfg1.bf.PTISEL = prbs_stats_time_int;
  tmp_gblr4x_kpacfg1.bf.FTISEL = fixed_stats_time_int;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG1), tmp_gblr4x_kpacfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G GBLR4X LOSCFG0                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_gblr4x_loscfg0(cs_uint16 module_id, 
                              cs_uint16 loscfg)
/* INPUTS     : o Module Id                                         */
/*              o LOSCFG                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the LOS detector Match Method.                              */
/*                                                                  */
/*   [loscfg]                                                       */
/*     0 = Stream matches all-zeros                                 */
/*     1 = Stream matches all-ones                                  */
/*     2 = Stream matches all-zeros or all-ones.                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_GBLR4X_LOSCFG0_t tmp_gblr4x_loscfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblr4x_loscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, LOSCFG0));
  tmp_gblr4x_loscfg0.bf.LOSCFG = loscfg;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, LOSCFG0), tmp_gblr4x_loscfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G GBLR4X LOSCFG1                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_gblr4x_loscfg1(cs_uint16 module_id, 
                              cs_uint16 los_ihys)
/* INPUTS     : o Module Id                                         */
/*              o LOS IHYS                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the time period during which the incoming LOS         */
/* condition must be set to 1 in order to trigger LOS alarm.        */
/*                                                                  */
/*   [los_ihys]  timing base is the Line Clock (Mhz) divided by     */
/*     LOS_STEP+1.                                                  */
/*     Time Period = {(LOS_IHYS)*(STEP+1)} * LINE CLK (sec).        */
/*     Note: Value of zero is meaningless.                          */ 
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_GBLR4X_LOSCFG1_t tmp_gblr4x_loscfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblr4x_loscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, LOSCFG1));
  tmp_gblr4x_loscfg1.bf.LOS_IHYS = los_ihys;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, LOSCFG1), tmp_gblr4x_loscfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G GBLR4X LOSCFG2                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_gblr4x_loscfg2(cs_uint16 module_id, 
                              cs_uint16 los_ohys)
/* INPUTS     : o Module Id                                         */
/*              o LOS OHYS                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the time period during which the incoming LOS         */
/* condition must be set to 0 in order to clear LOS alarm.          */
/*                                                                  */
/*   [los_ohys]  timing base is the Line Clock (Mhz) divided        */
/*     by LOS_STEP+1.                                               */
/*     Time Period = {(LOS_OHYS)*(STEP+1)} * LINE CLK (sec).        */
/*     Note: Value of zero is meaningless.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_GBLR4X_LOSCFG2_t tmp_gblr4x_loscfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblr4x_loscfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, LOSCFG2));
  tmp_gblr4x_loscfg2.bf.LOS_OHYS = los_ohys;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, LOSCFG2), tmp_gblr4x_loscfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G GBLR4X LOSCFG3                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_gblr4x_loscfg3(cs_uint16 module_id, 
                              cs_uint16 los_step)
/* INPUTS     : o Module Id                                         */
/*              o LOS STEP                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets LOS time base.                                              */
/*                                                                  */
/*   [los_step]  Received Line clk(Mhz) divided by LOS_STEP+1.      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_GBLR4X_LOSCFG3_t tmp_gblr4x_loscfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblr4x_loscfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, LOSCFG3));
  tmp_gblr4x_loscfg3.bf.LOS_STEP = los_step;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, LOSCFG3), tmp_gblr4x_loscfg3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 40G KPA ANALYZER FMM               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_config_kpa_fmm(cs_uint16 module_id,
                                  cs_uint16 fmm)

/* INPUTS     : o Module Id                                     */
/*              o Fixed Pattern Match Method                    */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the 40G Known Pattern Analyzer.                    */
/*                                                              */
/* The [fmm] parameter is specified as:                         */
/* (Fixed Pattern Match Method)                                 */
/*   0 = Stream matches PATa                                    */
/*   1 = Stream matches PATb                                    */
/*   2 = Stream matches PATa or PATb                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_KPACFG0_t tmp_gblr4x_kpacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_gblr4x_kpacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG0));
  tmp_gblr4x_kpacfg0.bf.FMM = fmm;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG0), tmp_gblr4x_kpacfg0.wrd);
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 40G KPA ANALYZER PRBS INTERVAL     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_config_kpa_prbs_interval(cs_uint16 module_id,
                                            cs_uint16 prbs_stats_time_int)

/* INPUTS     : o Module Id                                     */
/*              o PRBS Statistics Time Interval                 */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the 40G Known Pattern Analyzer.                    */
/*                                                              */
/* The [prbs_stats_time_int] parameter is specified as:         */
/*   0 = 1st internal timing generator                          */
/*   1 = 2nd internal timing generator                          */
/*   2 = 3rd internal timing generator                          */
/*   3 = 4th internal timing generator                          */
/*   4 = 5th internal timing generator                          */
/*   5 = 6th internal timing generator                          */
/*   6 = Software controlled timing generator                   */
/*   7 = Timing generator controlled by external hardware       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_KPACFG1_t tmp_gblr4x_kpacfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_gblr4x_kpacfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG1));
  tmp_gblr4x_kpacfg1.bf.PTISEL = prbs_stats_time_int;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG1), tmp_gblr4x_kpacfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 40G KPA ANALYZER FIXED INTERVAL    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_config_kpa_fixed_interval(cs_uint16 module_id,
                                             cs_uint16 fixed_stats_time_int)

/* INPUTS     : o Module Id                                     */
/*              o Fixed Pattern Match Time Interval             */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the 40G Known Pattern Analyzer.                    */
/*                                                              */
/* The [fixed_stats_time_int] parameter is specified as:        */
/*   0 = 1st internal timing generator                          */
/*   1 = 2nd internal timing generator                          */
/*   2 = 3rd internal timing generator                          */
/*   3 = 4th internal timing generator                          */
/*   4 = 5th internal timing generator                          */
/*   5 = 6th internal timing generator                          */
/*   6 = Software controlled timing generator                   */
/*   7 = Timing generator controlled by external hardware       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_KPACFG1_t tmp_gblr4x_kpacfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_gblr4x_kpacfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG1));
  tmp_gblr4x_kpacfg1.bf.FTISEL = fixed_stats_time_int;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG1), tmp_gblr4x_kpacfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  RESTART 40G KNOWN PATTERN ANALYZER           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                         */
cs_status ten_n40g_restart_kpa(cs_uint16 module_id)

/* INPUTS     : o Module Id                                     */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Restart the 40G Known Pattern Analyzer.  Clears PSTAT status,*/
/* causing the KPA to search for new PRBS sequences.            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_KPACFG0_t tmp_gblr4x_kpacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblr4x_kpacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG0));
  tmp_gblr4x_kpacfg0.bf.PCLR = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG0), tmp_gblr4x_kpacfg0.wrd);
  TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
  tmp_gblr4x_kpacfg0.bf.PCLR = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG0), tmp_gblr4x_kpacfg0.wrd);
  TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
  tmp_gblr4x_kpacfg0.bf.PCLR = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPACFG0), tmp_gblr4x_kpacfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 40G FIXED PATTERN MATCH            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                         */
cs_status ten_n40g_config_fixed_pattern_match(cs_uint16 module_id,
                                              cs_uint16 pattern,
                                              cs_uint16 parm7,
                                              cs_uint16 parm6,
                                              cs_uint16 parm5,
                                              cs_uint16 parm4,
                                              cs_uint16 parm3,
                                              cs_uint16 parm2,
                                              cs_uint16 parm1,
                                              cs_uint16 parm0)
/* INPUTS     : o Module Id                                     */
/*              o Pattern Selection                             */
/*              o Parameter 7                                   */
/*              o Parameter 6                                   */
/*              o Parameter 5                                   */
/*              o Parameter 4                                   */
/*              o Parameter 3                                   */
/*              o Parameter 2                                   */
/*              o Parameter 1                                   */
/*              o Parameter 0                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the Fixed Pattern Match.                           */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   TEN_PATTERN_A,                                             */
/*   TEN_PATTERN_B,                                             */
/*   TEN_PATTERN_MASK                                           */
/*                                                              */
/* The [parm7-0] parameter is specified as:                     */
/*   First Search Pattern for Fixed Pattern Match Unit,         */
/*   Second Search Pattern for Fixed Pattern Match Unit,        */
/*   Mask for for Fixed Pattern Match Unit                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;
 
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
 
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  switch (pattern) {
    case TEN_PATTERN_A:
      {
        TEN_N40G_GBLR4X_PATa7_t tmp_gblr4x_pata7;
        TEN_N40G_GBLR4X_PATa6_t tmp_gblr4x_pata6;
        TEN_N40G_GBLR4X_PATa5_t tmp_gblr4x_pata5;
        TEN_N40G_GBLR4X_PATa4_t tmp_gblr4x_pata4;
        TEN_N40G_GBLR4X_PATa3_t tmp_gblr4x_pata3;
        TEN_N40G_GBLR4X_PATa2_t tmp_gblr4x_pata2;
        TEN_N40G_GBLR4X_PATa1_t tmp_gblr4x_pata1;
        TEN_N40G_GBLR4X_PATa0_t tmp_gblr4x_pata0;

        tmp_gblr4x_pata7.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATa7));
        tmp_gblr4x_pata7.bf.PATa7 = parm7;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATa7), tmp_gblr4x_pata7.wrd);
        
        tmp_gblr4x_pata6.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATa6));
        tmp_gblr4x_pata6.bf.PATa6 = parm6;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATa6), tmp_gblr4x_pata6.wrd);
        
        tmp_gblr4x_pata5.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATa5));
        tmp_gblr4x_pata5.bf.PATa5 = parm5;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATa5), tmp_gblr4x_pata5.wrd);
        
        tmp_gblr4x_pata4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATa4));
        tmp_gblr4x_pata4.bf.PATa4 = parm4;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATa4), tmp_gblr4x_pata4.wrd);
        
        tmp_gblr4x_pata3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATa3));
        tmp_gblr4x_pata3.bf.PATa3 = parm3;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATa3), tmp_gblr4x_pata3.wrd);
        
        tmp_gblr4x_pata2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATa2));
        tmp_gblr4x_pata2.bf.PATa2 = parm2;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATa2), tmp_gblr4x_pata2.wrd);
        
        tmp_gblr4x_pata1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATa1));
        tmp_gblr4x_pata1.bf.PATa1 = parm1;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATa1), tmp_gblr4x_pata1.wrd);
        
        tmp_gblr4x_pata0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATa0));
        tmp_gblr4x_pata0.bf.PATa0 = parm0;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATa0), tmp_gblr4x_pata0.wrd);
        break;
      }
    case TEN_PATTERN_B:
      {
        TEN_N40G_GBLR4X_PATb7_t tmp_gblr4x_patb7;
        TEN_N40G_GBLR4X_PATb6_t tmp_gblr4x_patb6;
        TEN_N40G_GBLR4X_PATb5_t tmp_gblr4x_patb5;
        TEN_N40G_GBLR4X_PATb4_t tmp_gblr4x_patb4;
        TEN_N40G_GBLR4X_PATb3_t tmp_gblr4x_patb3;
        TEN_N40G_GBLR4X_PATb2_t tmp_gblr4x_patb2;
        TEN_N40G_GBLR4X_PATb1_t tmp_gblr4x_patb1;
        TEN_N40G_GBLR4X_PATb0_t tmp_gblr4x_patb0;

        tmp_gblr4x_patb7.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATb7));
        tmp_gblr4x_patb7.bf.PATb7 = parm7;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATb7), tmp_gblr4x_patb7.wrd);
        
        tmp_gblr4x_patb6.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATb6));
        tmp_gblr4x_patb6.bf.PATb6 = parm6;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATb6), tmp_gblr4x_patb6.wrd);
        
        tmp_gblr4x_patb5.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATb5));
        tmp_gblr4x_patb5.bf.PATb5 = parm5;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATb5), tmp_gblr4x_patb5.wrd);
        
        tmp_gblr4x_patb4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATb4));
        tmp_gblr4x_patb4.bf.PATb4 = parm4;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATb4), tmp_gblr4x_patb4.wrd);
        
        tmp_gblr4x_patb3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATb3));
        tmp_gblr4x_patb3.bf.PATb3 = parm3;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATb3), tmp_gblr4x_patb3.wrd);
        
        tmp_gblr4x_patb2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATb2));
        tmp_gblr4x_patb2.bf.PATb2 = parm2;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATb2), tmp_gblr4x_patb2.wrd);
        
        tmp_gblr4x_patb1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATb1));
        tmp_gblr4x_patb1.bf.PATb1 = parm1;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATb1), tmp_gblr4x_patb1.wrd);
        
        tmp_gblr4x_patb0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, PATb0));
        tmp_gblr4x_patb0.bf.PATb0 = parm0;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, PATb0), tmp_gblr4x_patb0.wrd);
        break;
      }
    case TEN_PATTERN_MASK:
      {
        TEN_N40G_GBLR4X_MASK7_t tmp_gblr4x_mask7;
        TEN_N40G_GBLR4X_MASK6_t tmp_gblr4x_mask6;
        TEN_N40G_GBLR4X_MASK5_t tmp_gblr4x_mask5;
        TEN_N40G_GBLR4X_MASK4_t tmp_gblr4x_mask4;
        TEN_N40G_GBLR4X_MASK3_t tmp_gblr4x_mask3;
        TEN_N40G_GBLR4X_MASK2_t tmp_gblr4x_mask2;
        TEN_N40G_GBLR4X_MASK1_t tmp_gblr4x_mask1;
        TEN_N40G_GBLR4X_MASK0_t tmp_gblr4x_mask0;

        tmp_gblr4x_mask7.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, MASK7));
        tmp_gblr4x_mask7.bf.MASK7 = parm7;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, MASK7), tmp_gblr4x_mask7.wrd);

        tmp_gblr4x_mask6.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, MASK6));
        tmp_gblr4x_mask6.bf.MASK6 = parm6;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, MASK6), tmp_gblr4x_mask6.wrd);

        tmp_gblr4x_mask5.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, MASK5));
        tmp_gblr4x_mask5.bf.MASK5 = parm5;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, MASK5), tmp_gblr4x_mask5.wrd);

        tmp_gblr4x_mask4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, MASK4));
        tmp_gblr4x_mask4.bf.MASK4 = parm4;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, MASK4), tmp_gblr4x_mask4.wrd);

        tmp_gblr4x_mask3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, MASK3));
        tmp_gblr4x_mask3.bf.MASK3 = parm3;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, MASK3), tmp_gblr4x_mask3.wrd);

        tmp_gblr4x_mask2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, MASK2));
        tmp_gblr4x_mask2.bf.MASK2 = parm2;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, MASK2), tmp_gblr4x_mask2.wrd);

        tmp_gblr4x_mask1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, MASK1));
        tmp_gblr4x_mask1.bf.MASK1 = parm1;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, MASK1), tmp_gblr4x_mask1.wrd);

        tmp_gblr4x_mask0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, MASK0));
        tmp_gblr4x_mask0.bf.MASK0 = parm0;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, MASK0), tmp_gblr4x_mask0.wrd);
        break;
      }
    default :
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..2.");
        ret_val = CS_ERROR;
        break;
      }  
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N40G BYPASS FRAMER                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_bypass_framer(cs_uint16 module_id,
                                 cs_ctl_t byp_enbl)
/* INPUTS     : o Module Id                                     */
/*              o Enable                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Bypass or allow the N40G framer                              */
/*                                                              */
/* The [byp_enbl] parameter enables error correction            */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  tmp_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_gblr4x_dpcfg0.bf.SBY = byp_enbl;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G GBLR4X SET KPASEL                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_gblr4x_set_kpasel(cs_uint16 module_id, 
                                     cs_uint16 kpasel)
/* INPUTS     : o Module Id                                     */
/*              o KPASEL                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Data Path Configuration Register.   */
/*                                                              */
/* The [kpasel] parameter is specified as:                      */
/*   KPA Input Select.                                          */
/*   0 = The signal to the KPA is VC-4-256 payload.             */
/*   1 = The signalto the KPA is the OPU-3 payload or the       */
/*       unaligned line interface input (as determined by OBY). */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_gblr4x_dpcfg0.bf.KPASEL = kpasel;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_gblr4x_dpcfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

