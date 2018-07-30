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
 * ten_ohpp_t41.c 
 *
 * $Id: ten_ohpp_t41.c,v 1.7 2013/02/22 20:48:43 jccarlis Exp $
 *
 * API's for T41 OHPP
 *
 */

#include "tenabo40.h"

/* Bugzilla 29260, New API for MS Priority support              */
/****************************************************************/
/* $rtn_hdr_start  OHPP SFU INSERT OTN MAINTENANCE SIGNAL T41   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_insert_otn_maintenance_signal_t41(cs_uint16 module_id, 
                                                         cs_uint8 signal,
                                                         cs_uint8 width,
                                                         cs_uint8 priority,
                                                         cs_uint8 stream)
/* INPUTS     : o Module Id                                     */
/*              o Signal                                        */
/*              o Width                                         */
/*              o Priority                                      */
/*              o Stream                                        */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the parameters of the Maintenance Signal to be    */
/* inserted into the specified stream. Configuration of the     */
/* Consequent Action Matrix for automatic insertion or MSignal  */
/* for manual insertion, along with any necessary enabling of   */
/* the framers to allow SFU insertion must also be performed    */
/* to insert this Maintenance Signal into the specified stream. */
/*                                                              */
/* The [signal] parameter specifies the signal:                 */
/*   0 = TEN_OHPP_INSERT_ZERO                                   */
/*       Maintenance signal insertion only allowed if OXU21MS   */
/*       is disabled in SFC. If OXU21MS turns active while      */
/*       OMSA1S is set to 00 binary all bytes will be set to    */
/*       00 hex.                                                */
/*   1 = TEN_OHPP_INSERT_AIS                                    */
/*       Insert AIS (all bytes set to FF hex).                  */
/*   2 = TEN_OHPP_INSERT_OCI                                    */
/*       Insert OCI (all bytes set to 66 hex).                  */
/*   3 = TEN_OHPP_INSERT_LCK                                    */
/*       Insert LCK (all bytes set to 55 hex).                  */
/*                                                              */
/* The [width] parameter specifies the signal:                  */
/*   0 = TEN_OHPP_WIDTH_ONLY_PAYLOAD                            */
/*       Fill OPUk payload section only, leaving OTN overhead   */
/*       row 1, columns 1 through 16 unmodified.                */
/*   1 = TEN_OHPP_WIDTH_OH_PAYLOAD                              */
/*       Fill OPUk payload and overhead section, leaving OTN    */
/*       overhead row 1, columns 1 through 14 unmodified.       */
/*   2 = TEN_OHPP_WIDTH_FRAME                                   */
/*       Fill complete OTUk frame except for FTFL and OTUk      */
/*       overhead.                                              */
/*                                                              */
/*                                                              */
/* The [priority] parameter specifies the priority of           */
/* Maintenance Signal insertion relative to the other TX OTN    */
/* Overhead insertion sources.                                  */
/*   0 = TEN_OHPP_PRIORITY_HIGH                                 */
/*       Maintenance Signal is inserted after all other Tx      */
/*       OTN Overhead insertion sources (lowest priority).      */
/*   1 = TEN_OHPP_PRIORITY_LOW                                  */
/*       Maintenance Signal is inserted before all other Tx     */
/*       OTN Overhead insertion sources (highest priority).     */
/*                                                              */
/* The [stream] parameter is specified as:                      */
/*   1 = Insert into OxU2 Overhead Stream #1                    */
/*   2 = Insert into OxU2 Overhead Stream #2                    */
/*   3 = Insert into OxU2 Overhead Stream #3                    */
/*   4 = Insert into OxU2 Overhead Stream #4                    */
/*   5 = Insert into OxU3 Overhead Stream                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;

  if ( (priority != TEN_OHPP_PRIORITY_LOW) && (priority != TEN_OHPP_PRIORITY_HIGH)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": priority out of range.");
    return(CS_ERROR);
  }

  /* All other validation is done by ten_ohpp_sfu_insert_otn_maintenance_signal() */
  ret_val = ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, stream);
  if (ret_val != CS_OK) {
    return (ret_val);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR); /* get pDev */
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  switch (stream) {
    case 1:
    {
      TEN_OHPP_SFU_OMSACTN0_t tmp_sfu_omsactn0;
      tmp_sfu_omsactn0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN0));
      tmp_sfu_omsactn0.bf.OMSA1P = priority;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN0), tmp_sfu_omsactn0.wrd);
      break;
    }
    case 2:
    {
      TEN_OHPP_SFU_OMSACTN0_t tmp_sfu_omsactn0;
      tmp_sfu_omsactn0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN0));
      tmp_sfu_omsactn0.bf.OMSA2P = priority;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN0), tmp_sfu_omsactn0.wrd);
      break;
    }
    case 3:
    {
      TEN_OHPP_SFU_OMSACTN1_t tmp_sfu_omsactn1;
      tmp_sfu_omsactn1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN1));
      tmp_sfu_omsactn1.bf.OMSA3P = priority;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN1), tmp_sfu_omsactn1.wrd);
      break;
    }
    case 4:
    {
      TEN_OHPP_SFU_OMSACTN1_t tmp_sfu_omsactn1;
      tmp_sfu_omsactn1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN1));
      tmp_sfu_omsactn1.bf.OMSA4P = priority;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN1), tmp_sfu_omsactn1.wrd);
      break;
    }
    case 5:
    {
      TEN_OHPP_SFU_OMSACTN1_t tmp_sfu_omsactn1;
      tmp_sfu_omsactn1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN1));
      tmp_sfu_omsactn1.bf.OMSA5P = priority;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN1), tmp_sfu_omsactn1.wrd);
      break;
    }
    default:
    {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": stream out of range.");
      ret_val = CS_ERROR;
      break;
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT1CFG1 CCT1MUX T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_cct1cfg1_cct1mux_t41(cs_uint16 module_id, 
                                            cs_uint16 cct1mux)
/* INPUTS     : o Module Id                                         */
/*              o CCT1MUX                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Communication Channel Transmit #1 CC Mux configuration.     */
/*                                                                  */
/*   [cct1mux]                                                      */
/*     Enables muxed contiguous CC Overhead bytes.                  */
/*     OxU: GCC0, GCC1, and GCC2 stream (expects 6 bytes).          */
/*     When set, enables the inclusion of GCC1 and GCC2             */
/*     if CCT1MD == 2.                                              */
/*     STS-192: DCCR, DCCM (D1-D12) stream (expects 12 bytes).      */
/*     When set, enables the inclusion of DCCM (D4-D12)             */
/*     if CCT1MD == 3.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CCT1CFG1_t tmp_sfu_cct1cfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct1cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT1CFG1));
  tmp_sfu_cct1cfg1.bf.CCT1MUX = cct1mux;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT1CFG1), tmp_sfu_cct1cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT2CFG1 CCT2MUX T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_cct2cfg1_cct2mux_t41(cs_uint16 module_id, 
                                            cs_uint16 cct2mux)
/* INPUTS     : o Module Id                                         */
/*              o CCT2MUX                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Communication Channel Transmit #2 CC Mux configuration.     */
/*                                                                  */
/*   [cct2mux]                                                      */
/*     Enables muxed contiguous CC Overhead bytes.                  */
/*     OxU: GCC0, GCC1, and GCC2 stream (expects 6 bytes).          */
/*     When set, enables the inclusion of GCC1 and GCC2             */
/*     if CCT2MD == 2.                                              */
/*     STS-192: DCCR, DCCM (D1-D12) stream (expects 12 bytes).      */
/*     When set, enables the inclusion of DCCM (D4-D12)             */
/*     if CCT2MD == 3.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CCT2CFG1_t tmp_sfu_cct2cfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct2cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT2CFG1));
  tmp_sfu_cct2cfg1.bf.CCT2MUX = cct2mux;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT2CFG1), tmp_sfu_cct2cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT3CFG1 CCT3MUX T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_cct3cfg1_cct3mux_t41(cs_uint16 module_id, 
                                            cs_uint16 cct3mux)
/* INPUTS     : o Module Id                                         */
/*              o CCT3MUX                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Communication Channel Transmit #3 CC Mux configuration.     */
/*                                                                  */
/*   [cct3mux]                                                      */
/*     Enables muxed contiguous CC Overhead bytes.                  */
/*     OxU: GCC0, GCC1, and GCC2 stream (expects 6 bytes).          */
/*     When set, enables the inclusion of GCC1 and GCC2             */
/*     if CCT3MD == 2.                                              */
/*     STS-192: DCCR, DCCM (D1-D12) stream (expects 12 bytes).      */
/*     When set, enables the inclusion of DCCM (D4-D12)             */
/*     if CCT3MD == 3.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CCT3CFG1_t tmp_sfu_cct3cfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct3cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT3CFG1));
  tmp_sfu_cct3cfg1.bf.CCT3MUX = cct3mux;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT3CFG1), tmp_sfu_cct3cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT4CFG1 CCT4MUX T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_cct4cfg1_cct4mux_t41(cs_uint16 module_id, 
                                            cs_uint16 cct4mux)
/* INPUTS     : o Module Id                                         */
/*              o CCT4MUX                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Communication Channel Transmit #4 CC Mux configuration.     */
/*                                                                  */
/*   [cct4mux]                                                      */
/*     Enables muxed contiguous CC Overhead bytes.                  */
/*     OxU: GCC0, GCC1, and GCC2 stream (expects 6 bytes).          */
/*     When set, enables the inclusion of GCC1 and GCC2             */
/*     if CCT4MD == 2.                                              */
/*     STS-192: DCCR, DCCM (D1-D12) stream (expects 12 bytes).      */
/*     When set, enables the inclusion of DCCM (D4-D12)             */
/*     if CCT4MD == 3.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CCT4CFG1_t tmp_sfu_cct4cfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct4cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT4CFG1));
  tmp_sfu_cct4cfg1.bf.CCT4MUX = cct4mux;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT4CFG1), tmp_sfu_cct4cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT5CFG1 CCT5MUX T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_cct5cfg1_cct5mux_t41(cs_uint16 module_id, 
                                            cs_uint16 cct5mux)
/* INPUTS     : o Module Id                                         */
/*              o CCT5MUX                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Communication Channel Transmit #5 CC Mux configuration.     */
/*                                                                  */
/*   [cct5mux]                                                      */
/*     Enables muxed contiguous CC Overhead bytes.                  */
/*     OxU: GCC0, GCC1, and GCC2 stream (expects 6 bytes).          */
/*     When set, enables the inclusion of GCC1 and GCC2             */
/*     if CCT5MD == 2.                                              */
/*     STS-192: DCCR, DCCM (D1-D12) stream (expects 12 bytes).      */
/*     When set, enables the inclusion of DCCM (D4-D12)             */
/*     if CCT5MD == 3.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CCT5CFG1_t tmp_sfu_cct5cfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct5cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT5CFG1));
  tmp_sfu_cct5cfg1.bf.CCT5MUX = cct5mux;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT5CFG1), tmp_sfu_cct5cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR1CFG1 CCR1MUX T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_ccr1cfg1_ccr1mux_t41(cs_uint16 module_id, 
                                            cs_uint16 ccr1mux)
/* INPUTS     : o Module Id                                         */
/*              o CCR1MUX                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Communication Channel Receive #1 CC Mux configuration.      */
/*                                                                  */
/*   [ccr1mux]                                                      */
/*     Enables muxed contiguous CC Overhead bytes.                  */
/*     OxU: GCC0, GCC1, and GCC2 stream (outputs 6 bytes).          */
/*     When set, enables the inclusion of GCC1 and GCC2             */
/*     if CCT1MD == 2.                                              */
/*     STS-192: DCCR, DCCM (D1-D12) stream (outputs 12 bytes).      */
/*     When set, enables the inclusion of DCCM (D4-D12)             */
/*     if CCT1MD == 3.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CCR1CFG1_t tmp_sfu_ccr1cfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr1cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR1CFG1));
  tmp_sfu_ccr1cfg1.bf.CCR1MUX = ccr1mux;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR1CFG1), tmp_sfu_ccr1cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR2CFG1 CCR2MUX T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_ccr2cfg1_ccr2mux_t41(cs_uint16 module_id, 
                                            cs_uint16 ccr2mux)
/* INPUTS     : o Module Id                                         */
/*              o CCR2MUX                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Communication Channel Receive #2 CC Mux configuration.      */
/*                                                                  */
/*   [ccr2mux]                                                      */
/*     Enables muxed contiguous CC Overhead bytes.                  */
/*     OxU: GCC0, GCC1, and GCC2 stream (outputs 6 bytes).          */
/*     When set, enables the inclusion of GCC1 and GCC2             */
/*     if CCT2MD == 2.                                              */
/*     STS-192: DCCR, DCCM (D1-D12) stream (outputs 12 bytes).      */
/*     When set, enables the inclusion of DCCM (D4-D12)             */
/*     if CCT2MD == 3.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CCR2CFG1_t tmp_sfu_ccr2cfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr2cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR2CFG1));
  tmp_sfu_ccr2cfg1.bf.CCR2MUX = ccr2mux;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR2CFG1), tmp_sfu_ccr2cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR3CFG1 CCR3MUX T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_ccr3cfg1_ccr3mux_t41(cs_uint16 module_id, 
                                            cs_uint16 ccr3mux)
/* INPUTS     : o Module Id                                         */
/*              o CCR3MUX                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Communication Channel Receive #3 CC Mux configuration.      */
/*                                                                  */
/*   [ccr3mux]                                                      */
/*     Enables muxed contiguous CC Overhead bytes.                  */
/*     OxU: GCC0, GCC1, and GCC2 stream (outputs 6 bytes).          */
/*     When set, enables the inclusion of GCC1 and GCC2             */
/*     if CCT3MD == 2.                                              */
/*     STS-192: DCCR, DCCM (D1-D12) stream (outputs 12 bytes).      */
/*     When set, enables the inclusion of DCCM (D4-D12)             */
/*     if CCT3MD == 3.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CCR3CFG1_t tmp_sfu_ccr3cfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr3cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR3CFG1));
  tmp_sfu_ccr3cfg1.bf.CCR3MUX = ccr3mux;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR3CFG1), tmp_sfu_ccr3cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR4CFG1 CCR4MUX T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_ccr4cfg1_ccr4mux_t41(cs_uint16 module_id, 
                                            cs_uint16 ccr4mux)
/* INPUTS     : o Module Id                                         */
/*              o CCR4MUX                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Communication Channel Receive #4 CC Mux configuration.      */
/*                                                                  */
/*   [ccr4mux]                                                      */
/*     Enables muxed contiguous CC Overhead bytes.                  */
/*     OxU: GCC0, GCC1, and GCC2 stream (outputs 6 bytes).          */
/*     When set, enables the inclusion of GCC1 and GCC2             */
/*     if CCT4MD == 2.                                              */
/*     STS-192: DCCR, DCCM (D1-D12) stream (outputs 12 bytes).      */
/*     When set, enables the inclusion of DCCM (D4-D12)             */
/*     if CCT4MD == 3.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CCR4CFG1_t tmp_sfu_ccr4cfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr4cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR4CFG1));
  tmp_sfu_ccr4cfg1.bf.CCR4MUX = ccr4mux;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR4CFG1), tmp_sfu_ccr4cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR5CFG1 CCR5MUX T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_ccr5cfg1_ccr5mux_t41(cs_uint16 module_id, 
                                            cs_uint16 ccr5mux)
/* INPUTS     : o Module Id                                         */
/*              o CCR5MUX                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Communication Channel Receive #5 CC Mux configuration.      */
/*                                                                  */
/*   [ccr5mux]                                                      */
/*     Enables muxed contiguous CC Overhead bytes.                  */
/*     OxU: GCC0, GCC1, and GCC2 stream (outputs 6 bytes).          */
/*     When set, enables the inclusion of GCC1 and GCC2             */
/*     if CCT5MD == 2.                                              */
/*     STS-192: DCCR, DCCM (D1-D12) stream (outputs 12 bytes).      */
/*     When set, enables the inclusion of DCCM (D4-D12)             */
/*     if CCT5MD == 3.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CCR5CFG1_t tmp_sfu_ccr5cfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr5cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR5CFG1));
  tmp_sfu_ccr5cfg1.bf.CCR5MUX = ccr5mux;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR5CFG1), tmp_sfu_ccr5cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

