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
 * ten_ohpp.c 
 *
 * $Id: ten_ohpp.c,v 1.18 2013/05/16 16:25:45 jccarlis Exp $
 *
 * API's for OHPP
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SRESET                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_sreset(cs_uint16 module_id, 
                              cs_reset_action_t act)
/* INPUTS     : o Module Id                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Soft reset the OHPP SFU.                                     */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   CS_RESET_DEASSERT                                          */
/*   CS_RESET_ASSERT                                            */
/*   CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_SRESET_t tmp_sfu_sreset;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": act = 0x%04X\n", act);
      return (CS_ERROR);
  }
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_sreset.wrd = 0;
  tmp_sfu_sreset.bf.SRESET = 1;
  ten_reset_action(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, SRESET), 
                   tmp_sfu_sreset.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  OHPP SFU INSERT OTN MAINTENANCE SIGNAL       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_insert_otn_maintenance_signal(cs_uint16 module_id, 
                                                     cs_uint8 signal,
                                                     cs_uint8 width,
                                                     cs_uint8 stream)
/* INPUTS     : o Module Id                                     */
/*              o Signal                                        */
/*              o Width                                         */
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
  cs_char8 *func = "ten_ohpp_sfu_insert_otn_maintenance_signal";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  if (signal > TEN_OHPP_INSERT_LCK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  signal %d out of range.", func, signal);
    return(CS_ERROR);
  }
  if (width > TEN_OHPP_WIDTH_FRAME) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  width %d out of range.", func, width);
    return(CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, %s, stream %d\n", func, ten_module_strings[module_id&1], ten_ohpp_signals_strings[signal], ten_ohpp_widths_strings[width], stream);
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  switch (stream) {
    case 1:
    {
      TEN_OHPP_SFU_OMSACTN0_t tmp_sfu_omsactn0;
      tmp_sfu_omsactn0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN0));
      tmp_sfu_omsactn0.bf.OMSA1S = signal;
      tmp_sfu_omsactn0.bf.OMSA1W = width;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN0), tmp_sfu_omsactn0.wrd);
      break;
    }
    case 2:
    {
      TEN_OHPP_SFU_OMSACTN0_t tmp_sfu_omsactn0;
      tmp_sfu_omsactn0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN0));
      tmp_sfu_omsactn0.bf.OMSA2S = signal;
      tmp_sfu_omsactn0.bf.OMSA2W = width;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN0), tmp_sfu_omsactn0.wrd);
      break;
    }
    case 3:
    {
      TEN_OHPP_SFU_OMSACTN0_t tmp_sfu_omsactn0;
      tmp_sfu_omsactn0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN0));
      tmp_sfu_omsactn0.bf.OMSA3S = signal;
      tmp_sfu_omsactn0.bf.OMSA3W = width;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN0), tmp_sfu_omsactn0.wrd);
      break;
    }
    case 4:
    {
      TEN_OHPP_SFU_OMSACTN1_t tmp_sfu_omsactn1;
      tmp_sfu_omsactn1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN1));
      tmp_sfu_omsactn1.bf.OMSA4S = signal;
      tmp_sfu_omsactn1.bf.OMSA4W = width;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN1), tmp_sfu_omsactn1.wrd);
      break;
    }
    case 5:
    {
      TEN_OHPP_SFU_OMSACTN1_t tmp_sfu_omsactn1;
      tmp_sfu_omsactn1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN1));
      tmp_sfu_omsactn1.bf.OMSA5S = signal;
      tmp_sfu_omsactn1.bf.OMSA5W = width;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OMSACTN1), tmp_sfu_omsactn1.wrd);
      break;
    }
    default:
    {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() stream out of range.");
      ret_val = CS_ERROR;
      break;
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET IAESEL                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_iaesel(cs_uint16 module_id, 
                                  cs_uint16 iaesel, 
                                  cs_uint8 stream)
/* INPUTS     : o Module Id                                     */
/*              o IAESEL                                        */
/*              o Stream                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set OTN Build Own Frame Consequent Action Select Register.   */
/*                                                              */
/* The [iaesel] parameter is specified as:                      */
/*   When set, Build Own Frame (BOF) in OxU2 transmit stream    */
/*   is activated whenever the OXU21IAE consequent action is    */
/*   activated.                                                 */
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
  TEN_OHPP_SFU_BOFACTSEL_t tmp_sfu_bofactsel;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_bofactsel.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL));
  switch (stream) {
    case 1:
    {
      tmp_sfu_bofactsel.bf.IAESEL1 = iaesel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL), tmp_sfu_bofactsel.wrd);
      break;
    }
    case 2:
    {
      tmp_sfu_bofactsel.bf.IAESEL2 = iaesel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL), tmp_sfu_bofactsel.wrd);
      break;
    }
    case 3:
    {
      tmp_sfu_bofactsel.bf.IAESEL3 = iaesel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL), tmp_sfu_bofactsel.wrd);
      break;
    }
    case 4:
    {
      tmp_sfu_bofactsel.bf.IAESEL4 = iaesel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL), tmp_sfu_bofactsel.wrd);
      break;
    }
    case 5:
    {
      tmp_sfu_bofactsel.bf.IAESEL5 = iaesel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL), tmp_sfu_bofactsel.wrd);
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

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET MSSEL                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_mssel(cs_uint16 module_id, 
                                 cs_uint16 mssel, 
                                 cs_uint8 stream)
/* INPUTS     : o Module Id                                     */
/*              o MSSEL                                        */
/*              o Stream                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set OTN Build Own Frame Consequent Action Select Register.   */
/*                                                              */
/* The [mssel] parameter is specified as:                       */
/*   When set, Build Own Frame (BOF) in OxU2 transmit stream    */
/*   is activated whenever the OXU21IAE consequent action is    */
/*   activated.                                                 */
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
  TEN_OHPP_SFU_BOFACTSEL_t tmp_sfu_bofactsel;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_bofactsel.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL));
  switch (stream) {
    case 1:
    {
      tmp_sfu_bofactsel.bf.MSSEL1 = mssel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL), tmp_sfu_bofactsel.wrd);
      break;
    }
    case 2:
    {
      tmp_sfu_bofactsel.bf.MSSEL2 = mssel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL), tmp_sfu_bofactsel.wrd);
      break;
    }
    case 3:
    {
      tmp_sfu_bofactsel.bf.MSSEL3 = mssel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL), tmp_sfu_bofactsel.wrd);
      break;
    }
    case 4:
    {
      tmp_sfu_bofactsel.bf.MSSEL4 = mssel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL), tmp_sfu_bofactsel.wrd);
      break;
    }
    case 5:
    {
      tmp_sfu_bofactsel.bf.MSSEL5 = mssel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BOFACTSEL), tmp_sfu_bofactsel.wrd);
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

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SELECT GLOBAL TIMING SOURCE         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_select_global_timing_source(cs_uint16 module_id, 
                                                   cs_uint16 select4, 
                                                   cs_uint16 select3, 
                                                   cs_uint16 select2, 
                                                   cs_uint16 select1)
/* INPUTS     : o Module Id                                     */
/*              o Select4                                       */
/*              o Select3                                       */
/*              o Select2                                       */
/*              o Select1                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Selects one out of eight different statistics timing         */
/* generators.                                                  */
/*                                                              */
/* The [select4, select3, select2, select1] parameters are      */
/* specified as:                                                */
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
  TEN_OHPP_SFU_DOACFG1_t tmp_sfu_doacfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_doacfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG1));
  tmp_sfu_doacfg1.bf.DOASEL4 = select4;
  tmp_sfu_doacfg1.bf.DOASEL3 = select3;
  tmp_sfu_doacfg1.bf.DOASEL2 = select2;
  tmp_sfu_doacfg1.bf.DOASEL1 = select1;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG1), tmp_sfu_doacfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  OHPP SET DOE RAM                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_set_doe_ram(cs_uint16 module_id,
                               cs_uint8 instance, 
                               cs_char8 *str)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The DOE RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOE RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* String 0 is Extracted OxU3 management overhead               */
/* String 1 is Extracted management overhead from OxU2 stream   */
/* number 1                                                     */
/* String 2 is Extracted management overhead from OxU2 stream   */
/* number 2                                                     */
/* String 3 is Extracted management overhead from OxU2 stream   */
/* number 3                                                     */
/* String 4 is Extracted management overhead from OxU2 stream   */
/* number 4                                                     */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   0..4                                                       */
/*                                                              */
/* The [*str] parameter is specified as:                        */
/*   A pointer to a 512-bit string                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_char8 *tmp_str;
  TEN_OHPP_DOE_RAM_t tmp_doe_ram;
  T41_t *pDev = NULL;

  if (instance > TEN_OHPP_DO_RAM_UNIT_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
    return(CS_ERROR);
  } 
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_str = str;
  for (ii=0; ii<TEN_OHPP_DO_RAM_UNIT_SIZE; ii++) {
    tmp_doe_ram.bf.str = *tmp_str & 0xFF;
    tmp_str++;
    tmp_doe_ram.bf.str |= *tmp_str << 8;

    TEN_REG_WRITE(TEN_OHPP_DOE_REG_ADDR(pDev, module_id, DOE_RAM) + 
                  ii + (instance * TEN_OHPP_DO_RAM_UNIT_SIZE), tmp_doe_ram.wrd);
    tmp_str++;
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);
  
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SET DOE RAM BYTE                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_set_doe_ram_byte(cs_uint16 module_id,
                                    cs_uint8  string,
                                    cs_uint8  byte,
                                    cs_uint16 value)
/* INPUTS     : o Module Id                                     */
/*              o String                                        */
/*              o Byte                                          */
/*              o Value                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The DOE RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOE RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [string] parameter is specified as:                      */
/*   0 = Extracted OxU3 management overhead                     */
/*   1 = Extracted management overhead from OxU2 stream 1       */
/*   2 = Extracted management overhead from OxU2 stream 2       */
/*   3 = Extracted management overhead from OxU2 stream 3       */
/*   4 = Extracted management overhead from OxU2 stream 4       */
/*                                                              */
/* The [byte] parameter is specified as:                        */
/*   TEN_OTNOH_FAOH_BYTE1           = 0                         */
/*   TEN_OTNOH_FAOH_BYTE2           = 1                         */
/*   TEN_OTNOH_FAOH_BYTE3           = 2                         */
/*   TEN_OTNOH_FAOH_BYTE4           = 3                         */
/*   TEN_OTNOH_FAOH_BYTE5           = 4                         */
/*   TEN_OTNOH_FAOH_BYTE6           = 5                         */
/*   TEN_OTNOH_FAOH_BYTE7           = 6                         */
/*   TEN_OTNOH_OTUKOH_BYTE1         = 7                         */
/*   TEN_OTNOH_OTUKOH_BYTE2         = 8                         */
/*   TEN_OTNOH_OTUKOH_BYTE3         = 9                         */
/*   TEN_OTNOH_OTUKOH_BYTE4         = 10                        */
/*   TEN_OTNOH_OTUKOH_BYTE5         = 11                        */
/*   TEN_OTNOH_OTUKOH_BYTE6         = 12                        */
/*   TEN_OTNOH_OTUKOH_BYTE7         = 13                        */
/*   TEN_OTNOH_OPUKOH_BYTE1         = 14                        */
/*   TEN_OTNOH_OPUKOH_BYTE2         = 15                        */
/*                                                              */
/*   TEN_OTNOH_TCMACT               = 19                        */
/*   TEN_OTNOH_TCM6_BYTE1           = 20                        */
/*   TEN_OTNOH_TCM6_BYTE2           = 21                        */
/*   TEN_OTNOH_TCM6_BYTE3           = 22                        */
/*   TEN_OTNOH_TCM5_BYTE1           = 23                        */
/*   TEN_OTNOH_TCM5_BYTE2           = 24                        */
/*   TEN_OTNOH_TCM5_BYTE3           = 25                        */
/*   TEN_OTNOH_TCM4_BYTE1           = 26                        */
/*   TEN_OTNOH_TCM4_BYTE2           = 27                        */
/*   TEN_OTNOH_TCM4_BYTE3           = 28                        */
/*   TEN_OTNOH_FTFL                 = 29                        */
/*   TEN_OTNOH_OPUKOH_BYTE3         = 30                        */
/*   TEN_OTNOH_OPUKOH_BYTE4         = 31                        */
/*                                                              */
/*   TEN_OTNOH_TCM3_BYTE1           = 32                        */
/*   TEN_OTNOH_TCM3_BYTE2           = 33                        */
/*   TEN_OTNOH_TCM3_BYTE3           = 34                        */
/*   TEN_OTNOH_TCM2_BYTE1           = 35                        */
/*   TEN_OTNOH_TCM2_BYTE2           = 36                        */
/*   TEN_OTNOH_TCM2_BYTE3           = 37                        */
/*   TEN_OTNOH_TCM1_BYTE1           = 38                        */
/*   TEN_OTNOH_TCM1_BYTE2           = 39                        */
/*   TEN_OTNOH_TCM1_BYTE3           = 40                        */
/*   TEN_OTNOH_PM_BYTE1             = 41                        */
/*   TEN_OTNOH_PM_BYTE2             = 42                        */
/*   TEN_OTNOH_PM_BYTE3             = 43                        */
/*   TEN_OTNOH_EXP_BYTE1            = 44                        */
/*   TEN_OTNOH_EXP_BYTE2            = 45                        */
/*   TEN_OTNOH_OPUKOH_BYTE5         = 46                        */
/*   TEN_OTNOH_OPUKOH_BYTE6         = 47                        */
/*                                                              */
/*   TEN_OTNOH_GCC1_BYTE1           = 48                        */
/*   TEN_OTNOH_GCC1_BYTE2           = 49                        */
/*   TEN_OTNOH_GCC2_BYTE1           = 50                        */
/*   TEN_OTNOH_GCC2_BYTE2           = 51                        */
/*   TEN_OTNOH_APSPCC_BYTE1         = 52                        */
/*   TEN_OTNOH_APSPCC_BYTE2         = 53                        */
/*   TEN_OTNOH_APSPCC_BYTE3         = 54                        */
/*   TEN_OTNOH_APSPCC_BYTE4         = 55                        */
/*   TEN_OTNOH_OPUKOH_BYTE7         = 62                        */
/*   TEN_OTNOH_OPUKOH_BYTE8         = 63                        */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   0x00 - 0xFF                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_DOE_RAM_t tmp_doe_ram;
  cs_uint16 tmp_instance;
  T41_t *pDev = NULL;

  if (string > 4) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string out of range.  s/b 0..4.");
    return(CS_ERROR);
  }
  if (byte > TEN_OTNOH_OPUKOH_BYTE8) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": byte out of range.  s/b 0..63.");
    return(CS_ERROR);
  }
  if (value > 0xFF) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": value out of range.  s/b 0..0xFF.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);

  tmp_instance = (string * 32) + (byte / 2);
  tmp_doe_ram.wrd = TEN_REG_READ(TEN_OHPP_DOE_REG_ADDR(pDev, module_id, DOE_RAM) +
                                 tmp_instance * TEN_OHPP_DOE_RAM_STRIDE);
  if ((byte % 2) == 1) {
    tmp_doe_ram.bf.str = (tmp_doe_ram.bf.str & 0x00FF) | value<<8;
  }
  else {
    tmp_doe_ram.bf.str = (tmp_doe_ram.bf.str & 0xFF00) | value;
  }
  TEN_REG_WRITE(TEN_OHPP_DOE_REG_ADDR(pDev, module_id, DOE_RAM) +
                tmp_instance * TEN_OHPP_DOE_RAM_STRIDE, tmp_doe_ram.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP GET DOE RAM                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_get_doe_ram(cs_uint16 module_id,
                               cs_uint8 instance, 
                               cs_char8 *str)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The DOE RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOE RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* String 0 is Extracted OxU3 management overhead               */
/* String 1 is Extracted management overhead from OxU2 stream   */
/* number 1                                                     */
/* String 2 is Extracted management overhead from OxU2 stream   */
/* number 2                                                     */
/* String 3 is Extracted management overhead from OxU2 stream   */
/* number 3                                                     */
/* String 4 is Extracted management overhead from OxU2 stream   */
/* number 4                                                     */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   0..4                                                       */
/*                                                              */
/* The [*str] parameter is specified as:                        */
/*   A pointer to a 512-bit string                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_char8 *tmp_str = str;
  TEN_OHPP_DOE_RAM_t tmp_doe_ram;

  if (instance > TEN_OHPP_DO_RAM_UNIT_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
    return(CS_ERROR);
  } 
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  for (ii=0; ii < TEN_OHPP_DO_RAM_UNIT_SIZE; ii++) {
    tmp_doe_ram.wrd = TEN_REG_READ(TEN_OHPP_DOE_REG_ADDR(pDev, module_id, DOE_RAM) +
                                   ii + (instance * TEN_OHPP_DO_RAM_UNIT_SIZE));
    *tmp_str = (cs_char8)(tmp_doe_ram.bf.str & 0x00FF);
    tmp_str++;
    *tmp_str = (cs_char8)((tmp_doe_ram.bf.str & 0xFF00) >> 8);
    tmp_str++;
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP PRINT DOE RAM                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_print_doe_ram(cs_uint16 module_id, 
                                 cs_uint8 instance) 
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o String Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the DOE RAM for the specified instance.               */
/* The DOE RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOE RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* String 0 is the management overhead to insert into OxU3      */
/* String 1 is the management overhead to insert into OxU2 of   */
/* stream number 1                                              */
/* String 2 is the management overhead to insert into OxU2 of   */
/* stream number 2                                              */
/* String 3 is the management overhead to insert into OxU2 of   */
/* stream number 3                                              */
/* String 4 is the management overhead to insert into OxU2 of   */
/* stream number 4                                              */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   0..4                                                       */
/*                                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_char8 tmp_doe_str[TEN_OHPP_DO_RAM_UNIT_SIZE*2];

  rtn = ten_ohpp_get_doe_ram(module_id, instance, tmp_doe_str);
  if (rtn == CS_OK) {
    /*ten_drvr_str_dump(tmp_doi_str, psi_str_size);*/
    ten_drvr_str_dump((cs_char8 *)tmp_doe_str, TEN_OHPP_DO_RAM_UNIT_SIZE * 2);
  }  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP GET DOE RAM BYTE                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_ohpp_get_doe_ram_byte(cs_uint16 module_id,
                                  cs_uint8  string,
                                  cs_uint8  byte)
/* INPUTS     : o Module Id                                     */
/*              o String                                        */
/*              o Byte                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0x00-0xFF                                       */
/* DESCRIPTION:                                                 */
/* The DOE RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOE RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [string] parameter is specified as:                      */
/*   0 = Extracted OxU3 management overhead                     */
/*   1 = Extracted management overhead from OxU2 stream 1       */
/*   2 = Extracted management overhead from OxU2 stream 2       */
/*   3 = Extracted management overhead from OxU2 stream 3       */
/*   4 = Extracted management overhead from OxU2 stream 4       */
/*                                                              */
/* The [byte] parameter is specified as:                        */
/*   TEN_OTNOH_FAOH_BYTE1           = 0                         */
/*   TEN_OTNOH_FAOH_BYTE2           = 1                         */
/*   TEN_OTNOH_FAOH_BYTE3           = 2                         */
/*   TEN_OTNOH_FAOH_BYTE4           = 3                         */
/*   TEN_OTNOH_FAOH_BYTE5           = 4                         */
/*   TEN_OTNOH_FAOH_BYTE6           = 5                         */
/*   TEN_OTNOH_FAOH_BYTE7           = 6                         */
/*   TEN_OTNOH_OTUKOH_BYTE1         = 7                         */
/*   TEN_OTNOH_OTUKOH_BYTE2         = 8                         */
/*   TEN_OTNOH_OTUKOH_BYTE3         = 9                         */
/*   TEN_OTNOH_OTUKOH_BYTE4         = 10                        */
/*   TEN_OTNOH_OTUKOH_BYTE5         = 11                        */
/*   TEN_OTNOH_OTUKOH_BYTE6         = 12                        */
/*   TEN_OTNOH_OTUKOH_BYTE7         = 13                        */
/*   TEN_OTNOH_OPUKOH_BYTE1         = 14                        */
/*   TEN_OTNOH_OPUKOH_BYTE2         = 15                        */
/*                                                              */
/*   TEN_OTNOH_TCMACT               = 19                        */
/*   TEN_OTNOH_TCM6_BYTE1           = 20                        */
/*   TEN_OTNOH_TCM6_BYTE2           = 21                        */
/*   TEN_OTNOH_TCM6_BYTE3           = 22                        */
/*   TEN_OTNOH_TCM5_BYTE1           = 23                        */
/*   TEN_OTNOH_TCM5_BYTE2           = 24                        */
/*   TEN_OTNOH_TCM5_BYTE3           = 25                        */
/*   TEN_OTNOH_TCM4_BYTE1           = 26                        */
/*   TEN_OTNOH_TCM4_BYTE2           = 27                        */
/*   TEN_OTNOH_TCM4_BYTE3           = 28                        */
/*   TEN_OTNOH_FTFL                 = 29                        */
/*   TEN_OTNOH_OPUKOH_BYTE3         = 30                        */
/*   TEN_OTNOH_OPUKOH_BYTE4         = 31                        */
/*                                                              */
/*   TEN_OTNOH_TCM3_BYTE1           = 32                        */
/*   TEN_OTNOH_TCM3_BYTE2           = 33                        */
/*   TEN_OTNOH_TCM3_BYTE3           = 34                        */
/*   TEN_OTNOH_TCM2_BYTE1           = 35                        */
/*   TEN_OTNOH_TCM2_BYTE2           = 36                        */
/*   TEN_OTNOH_TCM2_BYTE3           = 37                        */
/*   TEN_OTNOH_TCM1_BYTE1           = 38                        */
/*   TEN_OTNOH_TCM1_BYTE2           = 39                        */
/*   TEN_OTNOH_TCM1_BYTE3           = 40                        */
/*   TEN_OTNOH_PM_BYTE1             = 41                        */
/*   TEN_OTNOH_PM_BYTE2             = 42                        */
/*   TEN_OTNOH_PM_BYTE3             = 43                        */
/*   TEN_OTNOH_EXP_BYTE1            = 44                        */
/*   TEN_OTNOH_EXP_BYTE2            = 45                        */
/*   TEN_OTNOH_OPUKOH_BYTE5         = 46                        */
/*   TEN_OTNOH_OPUKOH_BYTE6         = 47                        */
/*                                                              */
/*   TEN_OTNOH_GCC1_BYTE1           = 48                        */
/*   TEN_OTNOH_GCC1_BYTE2           = 49                        */
/*   TEN_OTNOH_GCC2_BYTE1           = 50                        */
/*   TEN_OTNOH_GCC2_BYTE2           = 51                        */
/*   TEN_OTNOH_APSPCC_BYTE1         = 52                        */
/*   TEN_OTNOH_APSPCC_BYTE2         = 53                        */
/*   TEN_OTNOH_APSPCC_BYTE3         = 54                        */
/*   TEN_OTNOH_APSPCC_BYTE4         = 55                        */
/*   TEN_OTNOH_OPUKOH_BYTE7         = 62                        */
/*   TEN_OTNOH_OPUKOH_BYTE8         = 63.                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_DOE_RAM_t tmp_doe_ram;
  cs_uint16 tmp_instance;
  cs_uint8 ret_val;
  T41_t *pDev = NULL;

  if (string > 4) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string out of range.  s/b 0..4.");
    return(0);
  }
  if (byte > TEN_OTNOH_OPUKOH_BYTE8) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": byte out of range.  s/b 0..63.");
    return(0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);

  tmp_instance = (string * 32) + (byte / 2);
  tmp_doe_ram.wrd = TEN_REG_READ(TEN_OHPP_DOE_REG_ADDR(pDev, module_id, DOE_RAM) +
                                 tmp_instance * TEN_OHPP_DOE_RAM_STRIDE);
  if ((byte % 2) == 1) {
    ret_val = (tmp_doe_ram.bf.str>>8)&0xFF;
  }
  else {
    ret_val = (tmp_doe_ram.bf.str)&0xFF;
  }

  return ((cs_int16)ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SET DOI RAM                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_set_doi_ram(cs_uint16 module_id,
                               cs_uint8 instance, 
                               cs_uint16 *str)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The DOI RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOI RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* String 0 is the management overhead to insert into OxU3      */
/* String 1 is the management overhead to insert into OxU2 of   */
/* stream number 1                                              */
/* String 2 is the management overhead to insert into OxU2 of   */
/* stream number 2                                              */
/* String 3 is the management overhead to insert into OxU2 of   */
/* stream number 3                                              */
/* String 4 is the management overhead to insert into OxU2 of   */
/* stream number 4                                              */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   0..4                                                       */
/*                                                              */
/* The [str] parameter is specified as:                         */
/*   A pointer to a 512-bit string                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_uint16 *tmp_str = str;
  TEN_OHPP_DOI_RAM_t tmp_doi_ram;
  TEN_OHPP_SFU_STATE_t tmp_sfu_state;
  cs_int16 num_write_tries;

  if (instance > TEN_OHPP_DO_RAM_UNIT_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
    return(CS_ERROR);
  } 
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  for (ii=0; ii<TEN_OHPP_DO_RAM_UNIT_SIZE; ii++) {
    tmp_doi_ram.bf.str = *tmp_str;
    
    for (num_write_tries = 0; num_write_tries < TEN_OHPP_MAX_DPA_ACCESS_ATTEMPTS; num_write_tries++) {
      /* See if FIFO of Direct Overhead Addess Insert Buffer is full */
      tmp_sfu_state.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, STATE));
      if (!tmp_sfu_state.bf.DOAIBFF) {
        /* FIFO is not full */
        TEN_REG_WRITE(TEN_OHPP_DOI_REG_ADDR(pDev, module_id, DOI_RAM) + 
                      ii + (instance * TEN_OHPP_DO_RAM_UNIT_SIZE), tmp_doi_ram.wrd);
        break;
      }
    }
    
    if (num_write_tries >= TEN_OHPP_MAX_DPA_ACCESS_ATTEMPTS) {
      /* FIFO never became available */
      TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);
      return (CS_ERROR);
    }
    
    tmp_str++;
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP clear DOI RAM BYTE                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_clear_doi_ram(cs_uint16 module_id,
                                cs_uint8  string)
/* INPUTS     : o Module Id                                     */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The DOI RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOI RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/* This API clears (sets to 0) all words in the specified       */
/* string.  Use this for initializating DOI RAM.                */
/*                                                              */
/* The [string] parameter is specified as:                      */
/*   0 = Extracted OxU3 management overhead                     */
/*   1 = Extracted management overhead from OxU2 stream 1       */
/*   2 = Extracted management overhead from OxU2 stream 2       */
/*   3 = Extracted management overhead from OxU2 stream 3       */
/*   4 = Extracted management overhead from OxU2 stream 4       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /*TEN_OHPP_DOI_RAM_t tmp_doi_ram;*/
  TEN_OHPP_SFU_STATE_t tmp_sfu_state;
  cs_int16 num_write_tries;
  T41_t *pDev = NULL;
  cs_uint16 ii;

  if (string > 4) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string out of range.  s/b 0..4.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);

  for (ii=0; ii<32;ii++) {
    for (num_write_tries = 0; num_write_tries < TEN_OHPP_MAX_DPA_ACCESS_ATTEMPTS; num_write_tries++) {
      /* See if FIFO of Direct Overhead Addess Insert Buffer is full */
      tmp_sfu_state.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, STATE));
      if (!tmp_sfu_state.bf.DOAIBFF) {
        /* FIFO is not full */ 
        TEN_REG_WRITE(TEN_OHPP_DOI_REG_ADDR(pDev, module_id, DOI_RAM) + (string * 32) + ii, 0);
        break;
      }
      else {
        CS_PRINT("DOAIBFF=1, FIFO full! write_try=%d\n", num_write_tries);
      }
    }
    if (num_write_tries >= TEN_OHPP_MAX_DPA_ACCESS_ATTEMPTS) {
      CS_PRINT("DOAIBFF=1 and write_tries exceeded\n");
      TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);
      return (CS_ERROR);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SET DOI RAM BYTE                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_set_doi_ram_byte(cs_uint16 module_id,
                                    cs_uint8  string,
                                    cs_uint8  byte,
                                    cs_uint16 value)
/* INPUTS     : o Module Id                                     */
/*              o String                                        */
/*              o Byte                                          */
/*              o Value                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The DOI RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOI RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [string] parameter is specified as:                      */
/*   0 = Extracted OxU3 management overhead                     */
/*   1 = Extracted management overhead from OxU2 stream 1       */
/*   2 = Extracted management overhead from OxU2 stream 2       */
/*   3 = Extracted management overhead from OxU2 stream 3       */
/*   4 = Extracted management overhead from OxU2 stream 4       */
/*                                                              */
/* The [byte] parameter is specified as:                        */
/*   TEN_OTNOH_FAOH_BYTE1           = 0                         */
/*   TEN_OTNOH_FAOH_BYTE2           = 1                         */
/*   TEN_OTNOH_FAOH_BYTE3           = 2                         */
/*   TEN_OTNOH_FAOH_BYTE4           = 3                         */
/*   TEN_OTNOH_FAOH_BYTE5           = 4                         */
/*   TEN_OTNOH_FAOH_BYTE6           = 5                         */
/*   TEN_OTNOH_FAOH_BYTE7           = 6                         */
/*   TEN_OTNOH_OTUKOH_BYTE1         = 7                         */
/*   TEN_OTNOH_OTUKOH_BYTE2         = 8                         */
/*   TEN_OTNOH_OTUKOH_BYTE3         = 9                         */
/*   TEN_OTNOH_OTUKOH_BYTE4         = 10                        */
/*   TEN_OTNOH_OTUKOH_BYTE5         = 11                        */
/*   TEN_OTNOH_OTUKOH_BYTE6         = 12                        */
/*   TEN_OTNOH_OTUKOH_BYTE7         = 13                        */
/*   TEN_OTNOH_OPUKOH_BYTE1         = 14                        */
/*   TEN_OTNOH_OPUKOH_BYTE2         = 15                        */
/*                                                              */
/*   TEN_OTNOH_RES_BYTE1            = 16                        */
/*   TEN_OTNOH_RES_BYTE2            = 17                        */
/*   TEN_OTNOH_RES_BYTE3            = 18                        */
/*   TEN_OTNOH_TCMACT               = 19                        */
/*   TEN_OTNOH_TCM6_BYTE1           = 20                        */
/*   TEN_OTNOH_TCM6_BYTE2           = 21                        */
/*   TEN_OTNOH_TCM6_BYTE3           = 22                        */
/*   TEN_OTNOH_TCM5_BYTE1           = 23                        */
/*   TEN_OTNOH_TCM5_BYTE2           = 24                        */
/*   TEN_OTNOH_TCM5_BYTE3           = 25                        */
/*   TEN_OTNOH_TCM4_BYTE1           = 26                        */
/*   TEN_OTNOH_TCM4_BYTE2           = 27                        */
/*   TEN_OTNOH_TCM4_BYTE3           = 28                        */
/*   TEN_OTNOH_FTFL                 = 29                        */
/*   TEN_OTNOH_OPUKOH_BYTE3         = 30                        */
/*   TEN_OTNOH_OPUKOH_BYTE4         = 31                        */
/*                                                              */
/*   TEN_OTNOH_TCM3_BYTE1           = 32                        */
/*   TEN_OTNOH_TCM3_BYTE2           = 33                        */
/*   TEN_OTNOH_TCM3_BYTE3           = 34                        */
/*   TEN_OTNOH_TCM2_BYTE1           = 35                        */
/*   TEN_OTNOH_TCM2_BYTE2           = 36                        */
/*   TEN_OTNOH_TCM2_BYTE3           = 37                        */
/*   TEN_OTNOH_TCM1_BYTE1           = 38                        */
/*   TEN_OTNOH_TCM1_BYTE2           = 39                        */
/*   TEN_OTNOH_TCM1_BYTE3           = 40                        */
/*   TEN_OTNOH_PM_BYTE1             = 41                        */
/*   TEN_OTNOH_PM_BYTE2             = 42                        */
/*   TEN_OTNOH_PM_BYTE3             = 43                        */
/*   TEN_OTNOH_EXP_BYTE1            = 44                        */
/*   TEN_OTNOH_EXP_BYTE2            = 45                        */
/*   TEN_OTNOH_OPUKOH_BYTE5         = 46                        */
/*   TEN_OTNOH_OPUKOH_BYTE6         = 47                        */
/*                                                              */
/*   TEN_OTNOH_GCC1_BYTE1           = 48                        */
/*   TEN_OTNOH_GCC1_BYTE2           = 49                        */
/*   TEN_OTNOH_GCC2_BYTE1           = 50                        */
/*   TEN_OTNOH_GCC2_BYTE2           = 51                        */
/*   TEN_OTNOH_APSPCC_BYTE1         = 52                        */
/*   TEN_OTNOH_APSPCC_BYTE2         = 53                        */
/*   TEN_OTNOH_APSPCC_BYTE3         = 54                        */
/*   TEN_OTNOH_APSPCC_BYTE4         = 55                        */
/*   TEN_OTNOH_RES_BYTE4            = 56                        */
/*   TEN_OTNOH_RES_BYTE5            = 57                        */
/*   TEN_OTNOH_RES_BYTE6            = 58                        */
/*   TEN_OTNOH_RES_BYTE7            = 59                        */
/*   TEN_OTNOH_RES_BYTE8            = 60                        */
/*   TEN_OTNOH_RES_BYTE9            = 61                        */
/*   TEN_OTNOH_OPUKOH_BYTE7         = 62                        */
/*   TEN_OTNOH_OPUKOH_BYTE8         = 63                        */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   0x00 - 0xFF                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_DOI_RAM_t tmp_doi_ram;
  TEN_OHPP_SFU_STATE_t tmp_sfu_state;
  cs_uint16 tmp_instance;
  cs_int16 num_read_tries;
  cs_int16 num_write_tries;
  T41_t *pDev = NULL;

  if (string > 4) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string out of range.  s/b 0..4.");
    return(CS_ERROR);
  }
  if (byte > TEN_OTNOH_OPUKOH_BYTE8) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": byte out of range.  s/b 0..63.");
    return(CS_ERROR);
  }
  if (value > 0xFF) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": value out of range.  s/b 0..0xFF.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);

  /* Convert form instance(string) and byte offset to chip address offset */
  tmp_instance = (string * 32) + (byte / 2);
   
  for (num_read_tries = 0; num_read_tries < TEN_OHPP_MAX_DPA_ACCESS_ATTEMPTS; num_read_tries++) {
    /* Attempt to read from Direct Overhead AccessInsert Buffer */
    tmp_doi_ram.wrd = TEN_REG_READ(TEN_OHPP_DOI_REG_ADDR(pDev, module_id, DOI_RAM) +
                                   tmp_instance * TEN_OHPP_DOI_RAM_STRIDE);

    /* See if read was successful */
    tmp_sfu_state.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, STATE));
    
    if (!tmp_sfu_state.bf.DOAIRF) {
       /* Read was successful, so retrieve and return byte */
      if ((byte % 2) == 1) {
        tmp_doi_ram.bf.str = (tmp_doi_ram.bf.str & 0x00FF) | value<<8;
      }
      else {
        tmp_doi_ram.bf.str = (tmp_doi_ram.bf.str & 0xFF00) | value;
      }
    
      for (num_write_tries = 0; num_write_tries < TEN_OHPP_MAX_DPA_ACCESS_ATTEMPTS; num_write_tries++) {
        /* See if FIFO of Direct Overhead Addess Insert Buffer is full */
        tmp_sfu_state.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, STATE));
        if (!tmp_sfu_state.bf.DOAIBFF) {
          /* FIFO is not full */ 
          TEN_REG_WRITE(TEN_OHPP_DOI_REG_ADDR(pDev, module_id, DOI_RAM) +
                  tmp_instance * TEN_OHPP_DOI_RAM_STRIDE, tmp_doi_ram.wrd);
          TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);
          return (CS_OK);
        }
      }
      break;
    }
  }
  
  /* Either read from or write to Direct Overhead Addess Insert Buffer failed */
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_ERROR);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP GET DOI RAM                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_get_doi_ram(cs_uint16 module_id,
                               cs_uint8 instance, 
                               cs_char8 *str)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The DOI RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOI RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* String 0 is the management overhead to insert into OxU3      */
/* String 1 is the management overhead to insert into OxU2 of   */
/* stream number 1                                              */
/* String 2 is the management overhead to insert into OxU2 of   */
/* stream number 2                                              */
/* String 3 is the management overhead to insert into OxU2 of   */
/* stream number 3                                              */
/* String 4 is the management overhead to insert into OxU2 of   */
/* stream number 4                                              */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   0..4                                                       */
/*                                                              */
/* The [str] parameter is specified as:                         */
/*   A pointer to a 512-bit string                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_char8 *tmp_str = str;
  TEN_OHPP_DOI_RAM_t tmp_doi_ram;
  TEN_OHPP_SFU_STATE_t tmp_sfu_state;
  cs_int16 num_read_tries;

  if (instance > TEN_OHPP_DO_RAM_UNIT_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..4.");
    return(CS_ERROR);
  } 
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  for (ii=0; ii < TEN_OHPP_DO_RAM_UNIT_SIZE; ii++) {
    for (num_read_tries = 0; num_read_tries < TEN_OHPP_MAX_DPA_ACCESS_ATTEMPTS; num_read_tries++) {
      /* Attempt to read from Direct Overhead AccessInsert Buffer */
      tmp_doi_ram.wrd = TEN_REG_READ(TEN_OHPP_DOI_REG_ADDR(pDev, module_id, DOI_RAM) +
                                     ii + (instance * TEN_OHPP_DO_RAM_UNIT_SIZE));
      /* See if read was successful */
      tmp_sfu_state.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, STATE));
      if (!tmp_sfu_state.bf.DOAIRF) {
        /* Read was successful, so add it to the string */
        *tmp_str++ = (cs_char8)(tmp_doi_ram.bf.str & 0x00FF);
        *tmp_str++ = (cs_char8)((tmp_doi_ram.bf.str & 0xFF00) >> 8);
        break;
      }
    }
    
    if (num_read_tries >= TEN_OHPP_MAX_DPA_ACCESS_ATTEMPTS) {
      /* The last read attempt failed the maximum number of times */
      TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);
      return (CS_ERROR);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP PRINT DOI RAM                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_print_doi_ram(cs_uint16 module_id, 
                                 cs_uint8 instance) 
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o String Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the DOI RAM for the specified instance.               */
/* The DOI RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOI RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* String 0 is the management overhead to insert into OxU3      */
/* String 1 is the management overhead to insert into OxU2 of   */
/* stream number 1                                              */
/* String 2 is the management overhead to insert into OxU2 of   */
/* stream number 2                                              */
/* String 3 is the management overhead to insert into OxU2 of   */
/* stream number 3                                              */
/* String 4 is the management overhead to insert into OxU2 of   */
/* stream number 4                                              */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   0..4                                                       */
/*                                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  /*cs_uint16 tmp_doi_str[TEN_OHPP_DO_RAM_UNIT_SIZE];*/
  cs_char8 tmp_doi_str[TEN_OHPP_DO_RAM_UNIT_SIZE*2];

  rtn = ten_ohpp_get_doi_ram(module_id, instance, tmp_doi_str);
  if (rtn == CS_OK) {
    /*ten_drvr_str_dump(tmp_doi_str, psi_str_size);*/
    ten_drvr_str_dump(tmp_doi_str, TEN_OHPP_DO_RAM_UNIT_SIZE * 2);
  }  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP GET DOI RAM BYTE                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_ohpp_get_doi_ram_byte(cs_uint16 module_id,
                                  cs_uint8  string,
                                  cs_uint8  byte)
/* INPUTS     : o Module Id                                     */
/*              o String                                        */
/*              o Byte                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0x00-0xFF                                       */
/* DESCRIPTION:                                                 */
/* The DOI RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOI RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [string] parameter is specified as:                      */
/*   0 = Extracted OxU3 management overhead                     */
/*   1 = Extracted management overhead from OxU2 stream 1       */
/*   2 = Extracted management overhead from OxU2 stream 2       */
/*   3 = Extracted management overhead from OxU2 stream 3       */
/*   4 = Extracted management overhead from OxU2 stream 4       */
/*                                                              */
/* The [byte] parameter is specified as:                        */
/*   TEN_OTNOH_FAOH_BYTE1           = 0                         */
/*   TEN_OTNOH_FAOH_BYTE2           = 1                         */
/*   TEN_OTNOH_FAOH_BYTE3           = 2                         */
/*   TEN_OTNOH_FAOH_BYTE4           = 3                         */
/*   TEN_OTNOH_FAOH_BYTE5           = 4                         */
/*   TEN_OTNOH_FAOH_BYTE6           = 5                         */
/*   TEN_OTNOH_FAOH_BYTE7           = 6                         */
/*   TEN_OTNOH_OTUKOH_BYTE1         = 7                         */
/*   TEN_OTNOH_OTUKOH_BYTE2         = 8                         */
/*   TEN_OTNOH_OTUKOH_BYTE3         = 9                         */
/*   TEN_OTNOH_OTUKOH_BYTE4         = 10                        */
/*   TEN_OTNOH_OTUKOH_BYTE5         = 11                        */
/*   TEN_OTNOH_OTUKOH_BYTE6         = 12                        */
/*   TEN_OTNOH_OTUKOH_BYTE7         = 13                        */
/*   TEN_OTNOH_OPUKOH_BYTE1         = 14                        */
/*   TEN_OTNOH_OPUKOH_BYTE2         = 15                        */
/*                                                              */
/*   TEN_OTNOH_TCMACT               = 19                        */
/*   TEN_OTNOH_TCM6_BYTE1           = 20                        */
/*   TEN_OTNOH_TCM6_BYTE2           = 21                        */
/*   TEN_OTNOH_TCM6_BYTE3           = 22                        */
/*   TEN_OTNOH_TCM5_BYTE1           = 23                        */
/*   TEN_OTNOH_TCM5_BYTE2           = 24                        */
/*   TEN_OTNOH_TCM5_BYTE3           = 25                        */
/*   TEN_OTNOH_TCM4_BYTE1           = 26                        */
/*   TEN_OTNOH_TCM4_BYTE2           = 27                        */
/*   TEN_OTNOH_TCM4_BYTE3           = 28                        */
/*   TEN_OTNOH_FTFL                 = 29                        */
/*   TEN_OTNOH_OPUKOH_BYTE3         = 30                        */
/*   TEN_OTNOH_OPUKOH_BYTE4         = 31                        */
/*                                                              */
/*   TEN_OTNOH_TCM3_BYTE1           = 32                        */
/*   TEN_OTNOH_TCM3_BYTE2           = 33                        */
/*   TEN_OTNOH_TCM3_BYTE3           = 34                        */
/*   TEN_OTNOH_TCM2_BYTE1           = 35                        */
/*   TEN_OTNOH_TCM2_BYTE2           = 36                        */
/*   TEN_OTNOH_TCM2_BYTE3           = 37                        */
/*   TEN_OTNOH_TCM1_BYTE1           = 38                        */
/*   TEN_OTNOH_TCM1_BYTE2           = 39                        */
/*   TEN_OTNOH_TCM1_BYTE3           = 40                        */
/*   TEN_OTNOH_PM_BYTE1             = 41                        */
/*   TEN_OTNOH_PM_BYTE2             = 42                        */
/*   TEN_OTNOH_PM_BYTE3             = 43                        */
/*   TEN_OTNOH_EXP_BYTE1            = 44                        */
/*   TEN_OTNOH_EXP_BYTE2            = 45                        */
/*   TEN_OTNOH_OPUKOH_BYTE5         = 46                        */
/*   TEN_OTNOH_OPUKOH_BYTE6         = 47                        */
/*                                                              */
/*   TEN_OTNOH_GCC1_BYTE1           = 48                        */
/*   TEN_OTNOH_GCC1_BYTE2           = 49                        */
/*   TEN_OTNOH_GCC2_BYTE1           = 50                        */
/*   TEN_OTNOH_GCC2_BYTE2           = 51                        */
/*   TEN_OTNOH_APSPCC_BYTE1         = 52                        */
/*   TEN_OTNOH_APSPCC_BYTE2         = 53                        */
/*   TEN_OTNOH_APSPCC_BYTE3         = 54                        */
/*   TEN_OTNOH_APSPCC_BYTE4         = 55                        */
/*   TEN_OTNOH_OPUKOH_BYTE7         = 62                        */
/*   TEN_OTNOH_OPUKOH_BYTE8         = 63                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_DOI_RAM_t tmp_doi_ram;
  TEN_OHPP_SFU_STATE_t tmp_sfu_state;
  cs_uint16 tmp_instance;
  T41_t *pDev = NULL;
  cs_int16 ret_val = 0;
  cs_int16 num_read_tries;

  if (string > 4) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string out of range.  s/b 0..4.");
    return(0);
  }
  if (byte > TEN_OTNOH_OPUKOH_BYTE8) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": byte out of range.  s/b 0..63.");
    return(0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);

  /* Convert form instance(string) and byte offset to chip address offset */
  tmp_instance = (string * 32) + (byte / 2);
    
  for (num_read_tries = 0; num_read_tries < TEN_OHPP_MAX_DPA_ACCESS_ATTEMPTS; num_read_tries++) {
    /* Attempt to read from Direct Overhead AccessInsert Buffer */
    tmp_doi_ram.wrd = TEN_REG_READ(TEN_OHPP_DOI_REG_ADDR(pDev, module_id, DOI_RAM) +
                                   tmp_instance * TEN_OHPP_DOI_RAM_STRIDE);
    
    /* See if read was successful */
    tmp_sfu_state.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, STATE));
    if (!tmp_sfu_state.bf.DOAIRF) {
      /* Read was successful, so retrieve and return byte */
      if ((byte % 2) == 1) {
        ret_val = (tmp_doi_ram.bf.str>>8)&0xFF;
      }
      else {
        ret_val = (tmp_doi_ram.bf.str)&0xFF;
      }

      return ((cs_int16)ret_val);
    }  
  }

  /* Read was not successful */
  CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": read from Direct Overhead AccessInsert Buffer failed.");
  return(0);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR1CFG0                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr1cfg0(cs_uint16 module_id, 
                            cs_uint16 ccr1fpl, 
                            cs_uint16 ccr1fpp, 
                            cs_uint16 ccr1col, 
                            cs_uint16 ccr1dol, 
                            cs_uint16 ccr1ln, 
                            cs_uint16 ccr1cmp)
/* INPUTS     : o Module Id                                     */
/*              o CCR1FPL                                       */
/*              o CCR1FPP                                       */
/*              o CCR1COL                                       */
/*              o CCR1DOL                                       */
/*              o CCR1LN                                        */
/*              o CCR1CMP                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr1fpl] parameter is specified as:                     */
/*   Serial Frame Pulse output logic Level:                     */
/*   0 binary:Use uninverted CCFPRO[A|B] serial-port frame      */
/*     pulse output.                                            */
/*   1 binary:Invert the CCFPRO[A|B] serial-port frame pulse    */
/*     output.                                                  */
/*                                                              */
/* The [ccr1fpp] parameter is specified as:                     */
/*   Serial Frame Pulse bit Position:                           */
/*   0 binary:Have MSB of first byte in serial output data      */
/*     stream activate CCFPRO[A|B] frame pulse output.          */
/*   1 binary:Have LSB of first byte in serial output data      */
/*     stream activate CCFPRO[A|B] frame pulse output.          */
/*                                                              */
/* The [ccr1col] parameter is specified as:                     */
/*   Serial Clock Output logic Level:                           */
/*   0 binary:Use uninverted CCRCLK[A|B]1 serial-port clock     */
/*     output. Data is output at the falling clock edge.        */
/*   1 binary:Invert the CCRCLK[A|B]1 serial-port clock output. */
/*     Data is output at the rising clock edge.                 */
/*                                                              */
/* The [ccr1dol] parameter is specified as:                     */
/*   Serial Data Output logic Level:                            */
/*   0 binary:Use uninverted CCRD[A|B]1 serial data output.     */
/*   1 binary:Invert the CCRD[A|B]1 serial data output.         */
/*                                                              */
/* The [ccr1ln]  parameter is specified as:                     */
/*   Acceptance filter length for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* The [ccr1cmp] parameter is specified as:                     */
/*   User-defined comparison reference pattern for AIS.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR1CFG0_t tmp_sfu_ccr1cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr1cfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR1CFG0));
  tmp_sfu_ccr1cfg0.bf.CCR1FPL = ccr1fpl;
  tmp_sfu_ccr1cfg0.bf.CCR1FPP = ccr1fpp;
  tmp_sfu_ccr1cfg0.bf.CCR1COL = ccr1col;
  tmp_sfu_ccr1cfg0.bf.CCR1DOL = ccr1dol;
  tmp_sfu_ccr1cfg0.bf.CCR1LN = ccr1ln;
  tmp_sfu_ccr1cfg0.bf.CCR1CMP = ccr1cmp;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR1CFG0), tmp_sfu_ccr1cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR1CFG1                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr1cfg1(cs_uint16 module_id, 
                            cs_uint16 ccr1ss, 
                            cs_uint16 ccr1frq)
/* INPUTS     : o Module Id                                     */
/*              o CCR1SS                                        */
/*              o CCR1FRQ                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr1ss] parameter is specified as:                      */
/*   CCR1SS[3:0]                                                */
/*   Communication Channel Receive #1 Source Select             */
/*   configuration:                                             */
/*   0 Select OxU2 Terminator #1                                */
/*   1 Select OxU2 Terminator #2                                */
/*   2 Select OxU2 Terminator #3                                */
/*   3 Select OxU2 Terminator #4                                */
/*   4 Select STS-192 Terminator #1                             */
/*   5 Select STS-192 Terminator #2                             */
/*   6 Select STS-192 Terminator #3                             */
/*   7 Select STS-192 Terminator #4                             */
/*   8 Select OxU3 Terminator                                   */
/*                                                              */
/* The [ccr1frq] parameter is specified as:                     */
/*   CCR1FRQ[9:0]                                               */
/*   Communication Channel Receiver #1 FReQuency configuration: */
/*   Controls the speed of the CCRCLK[A|B]1 clock for the first */
/*   communication channel, based on the following formula:     */
/*   fCCRCLK = fOHSYSCLK / (2 x ( (CCR1FRQ * 4) + 1) )          */
/*   Supported operating frequency is between 64 KHz and 25 MHz.*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR1CFG1_t tmp_sfu_ccr1cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr1cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR1CFG1));
  tmp_sfu_ccr1cfg1.bf.CCR1SS = ccr1ss;
  tmp_sfu_ccr1cfg1.bf.CCR1FRQ = ccr1frq;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR1CFG1), tmp_sfu_ccr1cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR1CFG2                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr1cfg2(cs_uint16 module_id, 
                            cs_uint16 ccr1md, 
                            cs_uint16 ccr1bs)
/* INPUTS     : o Module Id                                     */
/*              o CCR1MD                                        */
/*              o CCR1BS                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr1md] parameter is specified as:                      */
/*   CCR1MD[2:0]                                                */
/*   MoDe of first Communication Channel:                       */
/*   0 Send CCR1CMP on first communication channel.             */
/*   1 One byte per frame mode. CCR1BS specifies the byte to be */
/*     sent.                                                    */
/*   2 Two bytes per frame mode supporting OTN-style GCC.       */
/*     CCR1BS specifies the first byte to be extracted.         */
/*     Contiguous transmission of the second byte is implicit.  */
/*   3 Extract DCCR bytes.                                      */
/*   4 Four bytes per frame mode. CCR1BS specifies the first    */
/*     byte to be extracted. Contiguous transmission of the     */
/*     following three bytes is implicit.                       */
/*   5 Extract DCCM bytes.                                      */
/*   6 Reserved                                                 */
/*   7 Reserved                                                 */
/*                                                              */
/* The [ccr1bs] parameter is specified as:                      */
/*   CCR1BS[12:0]                                               */
/*   Byte Selector for first Communication Channel:             */
/*   Only values for GCC0(14), GCC1(64), and GCC2(66) are       */
/*   supported.                                                 */
/*   Note: This unit may send invalid bytes if this value is    */
/*   greater than 5795 for an STS-192 stream or greater than 79 */
/*   for an OTN stream (as selected in CCR1SS).                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR1CFG2_t tmp_sfu_ccr1cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr1cfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR1CFG2));
  tmp_sfu_ccr1cfg2.bf.CCR1MD = ccr1md;
  tmp_sfu_ccr1cfg2.bf.CCR1BS = ccr1bs;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR1CFG2), tmp_sfu_ccr1cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR2CFG0                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr2cfg0(cs_uint16 module_id, 
                            cs_uint16 ccr2fpl, 
                            cs_uint16 ccr2fpp, 
                            cs_uint16 ccr2col, 
                            cs_uint16 ccr2dol, 
                            cs_uint16 ccr2ln, 
                            cs_uint16 ccr2cmp)
/* INPUTS     : o Module Id                                     */
/*              o CCR2FPL                                       */
/*              o CCR2FPP                                       */
/*              o CCR2COL                                       */
/*              o CCR2DOL                                       */
/*              o CCR2LN                                        */
/*              o CCR2CMP                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr2fpl] parameter is specified as:                     */
/*   Serial Frame Pulse output logic Level:                     */
/*   0 binary:Use uninverted CCFPRO[A|B] serial-port frame      */
/*     pulse output.                                            */
/*   1 binary:Invert the CCFPRO[A|B] serial-port frame pulse    */
/*     output.                                                  */
/*                                                              */
/* The [ccr2fpp] parameter is specified as:                     */
/*   Serial Frame Pulse bit Position:                           */
/*   0 binary:Have MSB of first byte in serial output data      */
/*     stream activate CCFPRO[A|B] frame pulse output.          */
/*   1 binary:Have LSB of first byte in serial output data      */
/*     stream activate CCFPRO[A|B] frame pulse output.          */
/*                                                              */
/* The [ccr2col] parameter is specified as:                     */
/*   Serial Clock Output logic Level:                           */
/*   0 binary:Use uninverted CCRCLK[A|B]1 serial-port clock     */
/*     output. Data is output at the falling clock edge.        */
/*   1 binary:Invert the CCRCLK[A|B]1 serial-port clock output. */
/*     Data is output at the rising clock edge.                 */
/*                                                              */
/* The [ccr2dol] parameter is specified as:                     */
/*   Serial Data Output logic Level:                            */
/*   0 binary:Use uninverted CCRD[A|B]1 serial data output.     */
/*   1 binary:Invert the CCRD[A|B]1 serial data output.         */
/*                                                              */
/* The [ccr2ln]  parameter is specified as:                     */
/*   Acceptance filter length for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* The [ccr2cmp] parameter is specified as:                     */
/*   User-defined comparison reference pattern for AIS.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR2CFG0_t tmp_sfu_ccr2cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr2cfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR2CFG0));
  tmp_sfu_ccr2cfg0.bf.CCR2FPL = ccr2fpl;
  tmp_sfu_ccr2cfg0.bf.CCR2FPP = ccr2fpp;
  tmp_sfu_ccr2cfg0.bf.CCR2COL = ccr2col;
  tmp_sfu_ccr2cfg0.bf.CCR2DOL = ccr2dol;
  tmp_sfu_ccr2cfg0.bf.CCR2LN = ccr2ln;
  tmp_sfu_ccr2cfg0.bf.CCR2CMP = ccr2cmp;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR2CFG0), tmp_sfu_ccr2cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR2CFG1                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr2cfg1(cs_uint16 module_id, 
                            cs_uint16 ccr2ss, 
                            cs_uint16 ccr2frq)
/* INPUTS     : o Module Id                                     */
/*              o CCR2SS                                        */
/*              o CCR2FRQ                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr2ss] parameter is specified as:                      */
/*   CCR2SS[3:0]                                                */
/*   Communication Channel Receive #1 Source Select             */
/*   configuration:                                             */
/*   0 Select OxU2 Terminator #1                                */
/*   1 Select OxU2 Terminator #2                                */
/*   2 Select OxU2 Terminator #3                                */
/*   3 Select OxU2 Terminator #4                                */
/*   4 Select STS-192 Terminator #1                             */
/*   5 Select STS-192 Terminator #2                             */
/*   6 Select STS-192 Terminator #3                             */
/*   7 Select STS-192 Terminator #4                             */
/*   8 Select OxU3 Terminator                                   */
/*                                                              */
/* The [ccr2frq] parameter is specified as:                     */
/*   CCR2FRQ[9:0]                                               */
/*   Communication Channel Receiver #1 FReQuency configuration: */
/*   Controls the speed of the CCRCLK[A|B]1 clock for the first */
/*   communication channel, based on the following formula:     */
/*   fCCRCLK = fOHSYSCLK / (2 x ( (CCR1FRQ * 4) + 1) )          */
/*   Supported operating frequency is between 64 KHz and 25 MHz.*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR2CFG1_t tmp_sfu_ccr2cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr2cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR2CFG1));
  tmp_sfu_ccr2cfg1.bf.CCR2SS = ccr2ss;
  tmp_sfu_ccr2cfg1.bf.CCR2FRQ = ccr2frq;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR2CFG1), tmp_sfu_ccr2cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR2CFG2                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr2cfg2(cs_uint16 module_id, 
                            cs_uint16 ccr2md, 
                            cs_uint16 ccr2bs)
/* INPUTS     : o Module Id                                     */
/*              o CCR2MD                                        */
/*              o CCR2BS                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr2md] parameter is specified as:                      */
/*   CCR2MD[2:0]                                                */
/*   MoDe of first Communication Channel:                       */
/*   0 Send CCR2CMP on first communication channel.             */
/*   1 One byte per frame mode. CCR2BS specifies the byte to be */
/*     sent.                                                    */
/*   2 Two bytes per frame mode supporting OTN-style GCC.       */
/*     CCR2BS specifies the first byte to be extracted.         */
/*     Contiguous transmission of the second byte is implicit.  */
/*   3 Extract DCCR bytes.                                      */
/*   4 Four bytes per frame mode. CCR2BS specifies the first    */
/*     byte to be extracted. Contiguous transmission of the     */
/*     following three bytes is implicit.                       */
/*   5 Extract DCCM bytes.                                      */
/*   6 Reserved                                                 */
/*   7 Reserved                                                 */
/*                                                              */
/* The [ccr2bs] parameter is specified as:                      */
/*   CCR2BS[12:0]                                               */
/*   Byte Selector for first Communication Channel:             */
/*   Only values for GCC0(14), GCC1(64), and GCC2(66) are       */
/*   supported.                                                 */
/*   Note: This unit may send invalid bytes if this value is    */
/*   greater than 5795 for an STS-192 stream or greater than 79 */
/*   for an OTN stream (as selected in CCR2SS).                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR2CFG2_t tmp_sfu_ccr2cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr2cfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR2CFG2));
  tmp_sfu_ccr2cfg2.bf.CCR2MD = ccr2md;
  tmp_sfu_ccr2cfg2.bf.CCR2BS = ccr2bs;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR2CFG2), tmp_sfu_ccr2cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR3CFG0                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr3cfg0(cs_uint16 module_id, 
                            cs_uint16 ccr3fpl, 
                            cs_uint16 ccr3fpp, 
                            cs_uint16 ccr3col, 
                            cs_uint16 ccr3dol, 
                            cs_uint16 ccr3ln, 
                            cs_uint16 ccr3cmp)
/* INPUTS     : o Module Id                                     */
/*              o CCR3FPL                                       */
/*              o CCR3FPP                                       */
/*              o CCR3COL                                       */
/*              o CCR3DOL                                       */
/*              o CCR3LN                                        */
/*              o CCR3CMP                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr3fpl] parameter is specified as:                     */
/*   Serial Frame Pulse output logic Level:                     */
/*   0 binary:Use uninverted CCFPRO[A|B] serial-port frame      */
/*     pulse output.                                            */
/*   1 binary:Invert the CCFPRO[A|B] serial-port frame pulse    */
/*     output.                                                  */
/*                                                              */
/* The [ccr3fpp] parameter is specified as:                     */
/*   Serial Frame Pulse bit Position:                           */
/*   0 binary:Have MSB of first byte in serial output data      */
/*     stream activate CCFPRO[A|B] frame pulse output.          */
/*   1 binary:Have LSB of first byte in serial output data      */
/*     stream activate CCFPRO[A|B] frame pulse output.          */
/*                                                              */
/* The [ccr3col] parameter is specified as:                     */
/*   Serial Clock Output logic Level:                           */
/*   0 binary:Use uninverted CCRCLK[A|B]1 serial-port clock     */
/*     output. Data is output at the falling clock edge.        */
/*   1 binary:Invert the CCRCLK[A|B]1 serial-port clock output. */
/*     Data is output at the rising clock edge.                 */
/*                                                              */
/* The [ccr3dol] parameter is specified as:                     */
/*   Serial Data Output logic Level:                            */
/*   0 binary:Use uninverted CCRD[A|B]1 serial data output.     */
/*   1 binary:Invert the CCRD[A|B]1 serial data output.         */
/*                                                              */
/* The [ccr3ln]  parameter is specified as:                     */
/*   Acceptance filter length for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* The [ccr3cmp] parameter is specified as:                     */
/*   User-defined comparison reference pattern for AIS.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR3CFG0_t tmp_sfu_ccr3cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr3cfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR3CFG0));
  tmp_sfu_ccr3cfg0.bf.CCR3FPL = ccr3fpl;
  tmp_sfu_ccr3cfg0.bf.CCR3FPP = ccr3fpp;
  tmp_sfu_ccr3cfg0.bf.CCR3COL = ccr3col;
  tmp_sfu_ccr3cfg0.bf.CCR3DOL = ccr3dol;
  tmp_sfu_ccr3cfg0.bf.CCR3LN = ccr3ln;
  tmp_sfu_ccr3cfg0.bf.CCR3CMP = ccr3cmp;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR3CFG0), tmp_sfu_ccr3cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR3CFG1                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr3cfg1(cs_uint16 module_id, 
                            cs_uint16 ccr3ss, 
                            cs_uint16 ccr3frq)
/* INPUTS     : o Module Id                                     */
/*              o CCR3SS                                        */
/*              o CCR3FRQ                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr3ss] parameter is specified as:                      */
/*   CCR3SS[3:0]                                                */
/*   Communication Channel Receive #1 Source Select             */
/*   configuration:                                             */
/*   0 Select OxU2 Terminator #1                                */
/*   1 Select OxU2 Terminator #2                                */
/*   2 Select OxU2 Terminator #3                                */
/*   3 Select OxU2 Terminator #4                                */
/*   4 Select STS-192 Terminator #1                             */
/*   5 Select STS-192 Terminator #2                             */
/*   6 Select STS-192 Terminator #3                             */
/*   7 Select STS-192 Terminator #4                             */
/*   8 Select OxU3 Terminator                                   */
/*                                                              */
/* The [ccr3frq] parameter is specified as:                     */
/*   CCR3FRQ[9:0]                                               */
/*   Communication Channel Receiver #1 FReQuency configuration: */
/*   Controls the speed of the CCRCLK[A|B]1 clock for the first */
/*   communication channel, based on the following formula:     */
/*   fCCRCLK = fOHSYSCLK / (2 x ( (CCR1FRQ * 4) + 1) )          */
/*   Supported operating frequency is between 64 KHz and 25 MHz.*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR3CFG1_t tmp_sfu_ccr3cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr3cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR3CFG1));
  tmp_sfu_ccr3cfg1.bf.CCR3SS = ccr3ss;
  tmp_sfu_ccr3cfg1.bf.CCR3FRQ = ccr3frq;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR3CFG1), tmp_sfu_ccr3cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR3CFG2                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr3cfg2(cs_uint16 module_id, 
                            cs_uint16 ccr3md, 
                            cs_uint16 ccr3bs)
/* INPUTS     : o Module Id                                     */
/*              o CCR3MD                                        */
/*              o CCR3BS                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr3md] parameter is specified as:                      */
/*   CCR3MD[2:0]                                                */
/*   MoDe of first Communication Channel:                       */
/*   0 Send CCR3CMP on first communication channel.             */
/*   1 One byte per frame mode. CCR3BS specifies the byte to be */
/*     sent.                                                    */
/*   2 Two bytes per frame mode supporting OTN-style GCC.       */
/*     CCR3BS specifies the first byte to be extracted.         */
/*     Contiguous transmission of the second byte is implicit.  */
/*   3 Extract DCCR bytes.                                      */
/*   4 Four bytes per frame mode. CCR3BS specifies the first    */
/*     byte to be extracted. Contiguous transmission of the     */
/*     following three bytes is implicit.                       */
/*   5 Extract DCCM bytes.                                      */
/*   6 Reserved                                                 */
/*   7 Reserved                                                 */
/*                                                              */
/* The [ccr3bs] parameter is specified as:                      */
/*   CCR3BS[12:0]                                               */
/*   Byte Selector for first Communication Channel:             */
/*   Only values for GCC0(14), GCC1(64), and GCC2(66) are       */
/*   supported.                                                 */
/*   Note: This unit may send invalid bytes if this value is    */
/*   greater than 5795 for an STS-192 stream or greater than 79 */
/*   for an OTN stream (as selected in CCR3SS).                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR3CFG2_t tmp_sfu_ccr3cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr3cfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR3CFG2));
  tmp_sfu_ccr3cfg2.bf.CCR3MD = ccr3md;
  tmp_sfu_ccr3cfg2.bf.CCR3BS = ccr3bs;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR3CFG2), tmp_sfu_ccr3cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR4CFG0                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr4cfg0(cs_uint16 module_id, 
                            cs_uint16 ccr4fpl, 
                            cs_uint16 ccr4fpp, 
                            cs_uint16 ccr4col, 
                            cs_uint16 ccr4dol, 
                            cs_uint16 ccr4ln, 
                            cs_uint16 ccr4cmp)
/* INPUTS     : o Module Id                                     */
/*              o CCR4FPL                                       */
/*              o CCR4FPP                                       */
/*              o CCR4COL                                       */
/*              o CCR4DOL                                       */
/*              o CCR4LN                                        */
/*              o CCR4CMP                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr4fpl] parameter is specified as:                     */
/*   Serial Frame Pulse output logic Level:                     */
/*   0 binary:Use uninverted CCFPRO[A|B] serial-port frame      */
/*     pulse output.                                            */
/*   1 binary:Invert the CCFPRO[A|B] serial-port frame pulse    */
/*     output.                                                  */
/*                                                              */
/* The [ccr4fpp] parameter is specified as:                     */
/*   Serial Frame Pulse bit Position:                           */
/*   0 binary:Have MSB of first byte in serial output data      */
/*     stream activate CCFPRO[A|B] frame pulse output.          */
/*   1 binary:Have LSB of first byte in serial output data      */
/*     stream activate CCFPRO[A|B] frame pulse output.          */
/*                                                              */
/* The [ccr4col] parameter is specified as:                     */
/*   Serial Clock Output logic Level:                           */
/*   0 binary:Use uninverted CCRCLK[A|B]1 serial-port clock     */
/*     output. Data is output at the falling clock edge.        */
/*   1 binary:Invert the CCRCLK[A|B]1 serial-port clock output. */
/*     Data is output at the rising clock edge.                 */
/*                                                              */
/* The [ccr4dol] parameter is specified as:                     */
/*   Serial Data Output logic Level:                            */
/*   0 binary:Use uninverted CCRD[A|B]1 serial data output.     */
/*   1 binary:Invert the CCRD[A|B]1 serial data output.         */
/*                                                              */
/* The [ccr4ln]  parameter is specified as:                     */
/*   Acceptance filter length for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* The [ccr4cmp] parameter is specified as:                     */
/*   User-defined comparison reference pattern for AIS.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR4CFG0_t tmp_sfu_ccr4cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr4cfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR4CFG0));
  tmp_sfu_ccr4cfg0.bf.CCR4FPL = ccr4fpl;
  tmp_sfu_ccr4cfg0.bf.CCR4FPP = ccr4fpp;
  tmp_sfu_ccr4cfg0.bf.CCR4COL = ccr4col;
  tmp_sfu_ccr4cfg0.bf.CCR4DOL = ccr4dol;
  tmp_sfu_ccr4cfg0.bf.CCR4LN = ccr4ln;
  tmp_sfu_ccr4cfg0.bf.CCR4CMP = ccr4cmp;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR4CFG0), tmp_sfu_ccr4cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR4CFG1                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr4cfg1(cs_uint16 module_id, 
                            cs_uint16 ccr4ss, 
                            cs_uint16 ccr4frq)
/* INPUTS     : o Module Id                                     */
/*              o CCR4SS                                        */
/*              o CCR4FRQ                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr4ss] parameter is specified as:                      */
/*   CCR4SS[3:0]                                                */
/*   Communication Channel Receive #1 Source Select             */
/*   configuration:                                             */
/*   0 Select OxU2 Terminator #1                                */
/*   1 Select OxU2 Terminator #2                                */
/*   2 Select OxU2 Terminator #3                                */
/*   3 Select OxU2 Terminator #4                                */
/*   4 Select STS-192 Terminator #1                             */
/*   5 Select STS-192 Terminator #2                             */
/*   6 Select STS-192 Terminator #3                             */
/*   7 Select STS-192 Terminator #4                             */
/*   8 Select OxU3 Terminator                                   */
/*                                                              */
/* The [ccr4frq] parameter is specified as:                     */
/*   CCR4FRQ[9:0]                                               */
/*   Communication Channel Receiver #1 FReQuency configuration: */
/*   Controls the speed of the CCRCLK[A|B]1 clock for the first */
/*   communication channel, based on the following formula:     */
/*   fCCRCLK = fOHSYSCLK / (2 x ( (CCR1FRQ * 4) + 1) )          */
/*   Supported operating frequency is between 64 KHz and 25 MHz.*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR4CFG1_t tmp_sfu_ccr4cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr4cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR4CFG1));
  tmp_sfu_ccr4cfg1.bf.CCR4SS = ccr4ss;
  tmp_sfu_ccr4cfg1.bf.CCR4FRQ = ccr4frq;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR4CFG1), tmp_sfu_ccr4cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR4CFG2                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr4cfg2(cs_uint16 module_id, 
                            cs_uint16 ccr4md, 
                            cs_uint16 ccr4bs)
/* INPUTS     : o Module Id                                     */
/*              o CCR4MD                                        */
/*              o CCR4BS                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr4md] parameter is specified as:                      */
/*   CCR4MD[2:0]                                                */
/*   MoDe of first Communication Channel:                       */
/*   0 Send CCR4CMP on first communication channel.             */
/*   1 One byte per frame mode. CCR4BS specifies the byte to be */
/*     sent.                                                    */
/*   2 Two bytes per frame mode supporting OTN-style GCC.       */
/*     CCR4BS specifies the first byte to be extracted.         */
/*     Contiguous transmission of the second byte is implicit.  */
/*   3 Extract DCCR bytes.                                      */
/*   4 Four bytes per frame mode. CCR4BS specifies the first    */
/*     byte to be extracted. Contiguous transmission of the     */
/*     following three bytes is implicit.                       */
/*   5 Extract DCCM bytes.                                      */
/*   6 Reserved                                                 */
/*   7 Reserved                                                 */
/*                                                              */
/* The [ccr4bs] parameter is specified as:                      */
/*   CCR4BS[12:0]                                               */
/*   Byte Selector for first Communication Channel:             */
/*   Only values for GCC0(14), GCC1(64), and GCC2(66) are       */
/*   supported.                                                 */
/*   Note: This unit may send invalid bytes if this value is    */
/*   greater than 5795 for an STS-192 stream or greater than 79 */
/*   for an OTN stream (as selected in CCR4SS).                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR4CFG2_t tmp_sfu_ccr4cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr4cfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR4CFG2));
  tmp_sfu_ccr4cfg2.bf.CCR4MD = ccr4md;
  tmp_sfu_ccr4cfg2.bf.CCR4BS = ccr4bs;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR4CFG2), tmp_sfu_ccr4cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR5CFG0                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr5cfg0(cs_uint16 module_id, 
                            cs_uint16 ccr5fpl, 
                            cs_uint16 ccr5fpp, 
                            cs_uint16 ccr5col, 
                            cs_uint16 ccr5dol, 
                            cs_uint16 ccr5ln, 
                            cs_uint16 ccr5cmp)
/* INPUTS     : o Module Id                                     */
/*              o CCR5FPL                                       */
/*              o CCR5FPP                                       */
/*              o CCR5COL                                       */
/*              o CCR5DOL                                       */
/*              o CCR5LN                                        */
/*              o CCR5CMP                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr5fpl] parameter is specified as:                     */
/*   Serial Frame Pulse output logic Level:                     */
/*   0 binary:Use uninverted CCFPRO[A|B] serial-port frame      */
/*     pulse output.                                            */
/*   1 binary:Invert the CCFPRO[A|B] serial-port frame pulse    */
/*     output.                                                  */
/*                                                              */
/* The [ccr5fpp] parameter is specified as:                     */
/*   Serial Frame Pulse bit Position:                           */
/*   0 binary:Have MSB of first byte in serial output data      */
/*     stream activate CCFPRO[A|B] frame pulse output.          */
/*   1 binary:Have LSB of first byte in serial output data      */
/*     stream activate CCFPRO[A|B] frame pulse output.          */
/*                                                              */
/* The [ccr5col] parameter is specified as:                     */
/*   Serial Clock Output logic Level:                           */
/*   0 binary:Use uninverted CCRCLK[A|B]1 serial-port clock     */
/*     output. Data is output at the falling clock edge.        */
/*   1 binary:Invert the CCRCLK[A|B]1 serial-port clock output. */
/*     Data is output at the rising clock edge.                 */
/*                                                              */
/* The [ccr5dol] parameter is specified as:                     */
/*   Serial Data Output logic Level:                            */
/*   0 binary:Use uninverted CCRD[A|B]1 serial data output.     */
/*   1 binary:Invert the CCRD[A|B]1 serial data output.         */
/*                                                              */
/* The [ccr5ln]  parameter is specified as:                     */
/*   Acceptance filter length for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* The [ccr5cmp] parameter is specified as:                     */
/*   User-defined comparison reference pattern for AIS.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR5CFG0_t tmp_sfu_ccr5cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr5cfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR5CFG0));
  tmp_sfu_ccr5cfg0.bf.CCR5FPL = ccr5fpl;
  tmp_sfu_ccr5cfg0.bf.CCR5FPP = ccr5fpp;
  tmp_sfu_ccr5cfg0.bf.CCR5COL = ccr5col;
  tmp_sfu_ccr5cfg0.bf.CCR5DOL = ccr5dol;
  tmp_sfu_ccr5cfg0.bf.CCR5LN = ccr5ln;
  tmp_sfu_ccr5cfg0.bf.CCR5CMP = ccr5cmp;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR5CFG0), tmp_sfu_ccr5cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR5CFG1                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr5cfg1(cs_uint16 module_id, 
                            cs_uint16 ccr5ss, 
                            cs_uint16 ccr5frq)
/* INPUTS     : o Module Id                                     */
/*              o CCR5SS                                        */
/*              o CCR5FRQ                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr5ss] parameter is specified as:                      */
/*   CCR5SS[3:0]                                                */
/*   Communication Channel Receive #1 Source Select             */
/*   configuration:                                             */
/*   0 Select OxU2 Terminator #1                                */
/*   1 Select OxU2 Terminator #2                                */
/*   2 Select OxU2 Terminator #3                                */
/*   3 Select OxU2 Terminator #4                                */
/*   4 Select STS-192 Terminator #1                             */
/*   5 Select STS-192 Terminator #2                             */
/*   6 Select STS-192 Terminator #3                             */
/*   7 Select STS-192 Terminator #4                             */
/*   8 Select OxU3 Terminator                                   */
/*                                                              */
/* The [ccr5frq] parameter is specified as:                     */
/*   CCR5FRQ[9:0]                                               */
/*   Communication Channel Receiver #1 FReQuency configuration: */
/*   Controls the speed of the CCRCLK[A|B]1 clock for the first */
/*   communication channel, based on the following formula:     */
/*   fCCRCLK = fOHSYSCLK / (2 x ( (CCR1FRQ * 4) + 1) )          */
/*   Supported operating frequency is between 64 KHz and 25 MHz.*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR5CFG1_t tmp_sfu_ccr5cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr5cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR5CFG1));
  tmp_sfu_ccr5cfg1.bf.CCR5SS = ccr5ss;
  tmp_sfu_ccr5cfg1.bf.CCR5FRQ = ccr5frq;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR5CFG1), tmp_sfu_ccr5cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCR5CFG2                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_ccr5cfg2(cs_uint16 module_id, 
                            cs_uint16 ccr5md, 
                            cs_uint16 ccr5bs)
/* INPUTS     : o Module Id                                     */
/*              o CCR5MD                                        */
/*              o CCR5BS                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Receive Configuration Register */
/*                                                              */
/* The [ccr5md] parameter is specified as:                      */
/*   CCR5MD[2:0]                                                */
/*   MoDe of first Communication Channel:                       */
/*   0 Send CCR5CMP on first communication channel.             */
/*   1 One byte per frame mode. CCR5BS specifies the byte to be */
/*     sent.                                                    */
/*   2 Two bytes per frame mode supporting OTN-style GCC.       */
/*     CCR5BS specifies the first byte to be extracted.         */
/*     Contiguous transmission of the second byte is implicit.  */
/*   3 Extract DCCR bytes.                                      */
/*   4 Four bytes per frame mode. CCR5BS specifies the first    */
/*     byte to be extracted. Contiguous transmission of the     */
/*     following three bytes is implicit.                       */
/*   5 Extract DCCM bytes.                                      */
/*   6 Reserved                                                 */
/*   7 Reserved                                                 */
/*                                                              */
/* The [ccr5bs] parameter is specified as:                      */
/*   CCR5BS[12:0]                                               */
/*   Byte Selector for first Communication Channel:             */
/*   Only values for GCC0(14), GCC1(64), and GCC2(66) are       */
/*   supported.                                                 */
/*   Note: This unit may send invalid bytes if this value is    */
/*   greater than 5795 for an STS-192 stream or greater than 79 */
/*   for an OTN stream (as selected in CCR5SS).                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCR5CFG2_t tmp_sfu_ccr5cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ccr5cfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR5CFG2));
  tmp_sfu_ccr5cfg2.bf.CCR5MD = ccr5md;
  tmp_sfu_ccr5cfg2.bf.CCR5BS = ccr5bs;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCR5CFG2), tmp_sfu_ccr5cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT1CFG0                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct1cfg0(cs_uint16 module_id, 
                            cs_uint16 cct1fpl, 
                            cs_uint16 cct1fpp, 
                            cs_uint16 cct1col, 
                            cs_uint16 cct1dol, 
                            cs_uint16 cct1ln, 
                            cs_uint16 cct1cmp)
/* INPUTS     : o Module Id                                     */
/*              o CCT1FPL                                       */
/*              o CCT1FPP                                       */
/*              o CCT1COL                                       */
/*              o CCT1DOL                                       */
/*              o CCT1LN                                        */
/*              o CCT1CMP                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct1fpl] parameter is specified as:                     */
/*   serial Frame Pulse logic Level:                            */
/*   0 binary:Use uninverted serial-port CCFPTO[A|B] frame      */
/*     pulse output.                                            */
/*   1 binary:Invert the serial-port CCFPTO[A|B] frame pulse    */
/*     output.                                                  */
/*                                                              */
/* The [cct1fpp] parameter is specified as:                     */
/*   serial Frame Pulse bit Position:                           */
/*   0 binary:Have MSB of first byte in incoming serial data    */
/*     stream activate CCFPTO[A|B] frame pulse output.          */
/*   1 binary:Have LSB of first byte in incoming serial data    */
/*     stream activate CCFPTO[A|B] frame pulse output.          */
/*                                                              */
/* The [cct1col] parameter is specified as:                     */
/*   serial Clock Output logic Level:                           */
/*   0 binary:Use uninverted CCTCLK[A|B] serial clock output.   */
/*     Incoming data is sampled on the falling clock edge.      */
/*   1 binary:Invert the CCTCLK[A|B] serial clock output.       */
/*     Incoming data is sampled on the rising clock edge.       */
/*                                                              */
/* The [cct1dol] parameter is specified as:                     */
/*   serial Data input Operating Level:                         */
/*   0 binary:Use uninverted CCTD[A|B]1 serial data input.      */
/*   1 binary:Invert the CCTD[A|B]1 serial data input.          */
/*                                                              */
/* The [cct1ln]  parameter is specified as:                     */
/*   CCT1LN[3:0]                                                */
/*   Acceptance filter LeNgth for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* The [cct1cmp] parameter is specified as:                     */
/*   CCT1CMP[7:0]                                               */
/*   Acceptance filter LeNgth for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT1CFG0_t tmp_sfu_cct1cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct1cfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT1CFG0));
  tmp_sfu_cct1cfg0.bf.CCT1FPL = cct1fpl;
  tmp_sfu_cct1cfg0.bf.CCT1FPP = cct1fpp;
  tmp_sfu_cct1cfg0.bf.CCT1COL = cct1col;
  tmp_sfu_cct1cfg0.bf.CCT1DOL = cct1dol;
  tmp_sfu_cct1cfg0.bf.CCT1LN = cct1ln;
  tmp_sfu_cct1cfg0.bf.CCT1CMP = cct1cmp;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT1CFG0), tmp_sfu_cct1cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT1CFG1                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct1cfg1(cs_uint16 module_id, 
                            cs_uint16 cct1ss, 
                            cs_uint16 cct1frq)
/* INPUTS     : o Module Id                                     */
/*              o CCT1SS                                        */
/*              o CCT1FRQ                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct1ss] parameter is specified as:                      */
/*   CCT1SS[3:0]                                                */
/*   Communication Channel Transmit #1 Sink Select              */
/*   configuration:                                             */
/*   0 Select OxU2 Generator #1                                 */
/*   1 Select OxU2 Generator #2                                 */
/*   2 Select OxU2 Generator #3                                 */
/*   3 Select OxU2 Generator #4                                 */
/*   4 Select STS-192 Generator #1                              */
/*   5 Select STS-192 Generator #2                              */
/*   6 Select STS-192 Generator #3                              */
/*   7 Select STS-192 Generator #4                              */
/*   8 Select OxU3 Generator                                    */
/*                                                              */
/* The [cct1frq] parameter is specified as:                     */
/*   CCT1FRQ[9:0]                                               */
/*   Communication Channel Transmit #1 FReQuency configuration: */
/*   Controls the speed of the CCTCLK[A|B]1 clock for the first */
/*   communication channel, based on the following formula:     */
/*   fCCTCLK = fOHSYSCLK / (8 x (CCT1FRQ + 1)).                 */
/*   Supported operating frequency is between 64 KHz and 25 MHz.*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT1CFG1_t tmp_sfu_cct1cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct1cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT1CFG1));
  tmp_sfu_cct1cfg1.bf.CCT1SS = cct1ss;
  tmp_sfu_cct1cfg1.bf.CCT1FRQ = cct1frq;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT1CFG1), tmp_sfu_cct1cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT1CFG2                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct1cfg2(cs_uint16 module_id, 
                            cs_uint16 cct1md, 
                            cs_uint16 cct1bs)
/* INPUTS     : o Module Id                                     */
/*              o CCT1MD                                        */
/*              o CCT1BS                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct1md] parameter is specified as:                      */
/*   CCT1MD[2:0]                                                */
/*   MoDe of first Communication Channel for Transmitter:       */
/*   0 Off. Do not insert into the transport stream. (The       */
/*     external transmit clock only operates while data bytes   */
/*     are being transferred.)                                  */
/*   1 One byte per frame mode; CCT1BS specifies which byte in  */
/*     the transport stream will be overwritten.                */
/*   2 Two bytes per frame mode supporting OTN-style GCC.       */
/*     CCT1BS specifies the first byte to be overwritten.       */
/*     Overwriting of the second byte is implicit.              */
/*   3 Overwrite DCCR ignoring CCT1BS.                          */
/*   4 Four bytes per frame mode. CCT1BS specifies the first    */
/*     byte to be overwritten.                                  */
/*   5 Overwrite DCCM ignoring CCT1BS.                          */
/*   6 Send CCT1VAL on first communication channel.             */
/*   7 Reserved                                                 */
/*                                                              */
/* The [cct1bs] parameter is specified as:                      */
/*   CCT1BS[12:0]                                               */
/*   Byte Selector for first Communication Channel Transmit.    */
/*   Only values for GCC0(14), GCC1(64), and GCC2(66) are       */
/*   supported.                                                 */
/*   Note: This setting may destroy arbitrary bytes if set to   */
/*   values beyond 5795 for an STS-192 stream or 79 for an OTN  */
/*   stream (as selected in CCT1SS).                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT1CFG2_t tmp_sfu_cct1cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct1cfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT1CFG2));
  tmp_sfu_cct1cfg2.bf.CCT1MD = cct1md;
  tmp_sfu_cct1cfg2.bf.CCT1BS = cct1bs;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT1CFG2), tmp_sfu_cct1cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT2CFG0                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct2cfg0(cs_uint16 module_id, 
                            cs_uint16 cct2fpl, 
                            cs_uint16 cct2fpp, 
                            cs_uint16 cct2col, 
                            cs_uint16 cct2dol, 
                            cs_uint16 cct2ln, 
                            cs_uint16 cct2cmp)
/* INPUTS     : o Module Id                                     */
/*              o CCT2FPL                                       */
/*              o CCT2FPP                                       */
/*              o CCT2COL                                       */
/*              o CCT2DOL                                       */
/*              o CCT2LN                                        */
/*              o CCT2CMP                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct2fpl] parameter is specified as:                     */
/*   serial Frame Pulse logic Level:                            */
/*   0 binary:Use uninverted serial-port CCFPTO[A|B] frame      */
/*     pulse output.                                            */
/*   1 binary:Invert the serial-port CCFPTO[A|B] frame pulse    */
/*     output.                                                  */
/*                                                              */
/* The [cct2fpp] parameter is specified as:                     */
/*   serial Frame Pulse bit Position:                           */
/*   0 binary:Have MSB of first byte in incoming serial data    */
/*     stream activate CCFPTO[A|B] frame pulse output.          */
/*   1 binary:Have LSB of first byte in incoming serial data    */
/*     stream activate CCFPTO[A|B] frame pulse output.          */
/*                                                              */
/* The [cct2col] parameter is specified as:                     */
/*   serial Clock Output logic Level:                           */
/*   0 binary:Use uninverted CCTCLK[A|B] serial clock output.   */
/*     Incoming data is sampled on the falling clock edge.      */
/*   1 binary:Invert the CCTCLK[A|B] serial clock output.       */
/*     Incoming data is sampled on the rising clock edge.       */
/*                                                              */
/* The [cct2dol] parameter is specified as:                     */
/*   serial Data input Operating Level:                         */
/*   0 binary:Use uninverted CCTD[A|B]1 serial data input.      */
/*   1 binary:Invert the CCTD[A|B]1 serial data input.          */
/*                                                              */
/* The [cct2ln]  parameter is specified as:                     */
/*   CCT2LN[3:0]                                                */
/*   Acceptance filter LeNgth for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* The [cct2cmp] parameter is specified as:                     */
/*   CCT2CMP[7:0]                                               */
/*   Acceptance filter LeNgth for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT2CFG0_t tmp_sfu_cct2cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct2cfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT2CFG0));
  tmp_sfu_cct2cfg0.bf.CCT2FPL = cct2fpl;
  tmp_sfu_cct2cfg0.bf.CCT2FPP = cct2fpp;
  tmp_sfu_cct2cfg0.bf.CCT2COL = cct2col;
  tmp_sfu_cct2cfg0.bf.CCT2DOL = cct2dol;
  tmp_sfu_cct2cfg0.bf.CCT2LN = cct2ln;
  tmp_sfu_cct2cfg0.bf.CCT2CMP = cct2cmp;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT2CFG0), tmp_sfu_cct2cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT2CFG1                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct2cfg1(cs_uint16 module_id, 
                            cs_uint16 cct2ss, 
                            cs_uint16 cct2frq)
/* INPUTS     : o Module Id                                     */
/*              o CCT2SS                                        */
/*              o CCT2FRQ                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct2ss] parameter is specified as:                      */
/*   CCT2SS[3:0]                                                */
/*   Communication Channel Transmit #1 Sink Select              */
/*   configuration:                                             */
/*   0 Select OxU2 Generator #1                                 */
/*   1 Select OxU2 Generator #2                                 */
/*   2 Select OxU2 Generator #3                                 */
/*   3 Select OxU2 Generator #4                                 */
/*   4 Select STS-192 Generator #1                              */
/*   5 Select STS-192 Generator #2                              */
/*   6 Select STS-192 Generator #3                              */
/*   7 Select STS-192 Generator #4                              */
/*   8 Select OxU3 Generator                                    */
/*                                                              */
/* The [cct2frq] parameter is specified as:                     */
/*   CCT2FRQ[9:0]                                               */
/*   Communication Channel Transmit #1 FReQuency configuration: */
/*   Controls the speed of the CCTCLK[A|B]1 clock for the first */
/*   communication channel, based on the following formula:     */
/*   fCCTCLK = fOHSYSCLK / (8 x (CCT2FRQ + 1)).                 */
/*   Supported operating frequency is between 64 KHz and 25 MHz.*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT2CFG1_t tmp_sfu_cct2cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct2cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT2CFG1));
  tmp_sfu_cct2cfg1.bf.CCT2SS = cct2ss;
  tmp_sfu_cct2cfg1.bf.CCT2FRQ = cct2frq;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT2CFG1), tmp_sfu_cct2cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT2CFG2                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct2cfg2(cs_uint16 module_id, 
                            cs_uint16 cct2md, 
                            cs_uint16 cct2bs)
/* INPUTS     : o Module Id                                     */
/*              o CCT2MD                                        */
/*              o CCT2BS                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct2md] parameter is specified as:                      */
/*   CCT2MD[2:0]                                                */
/*   MoDe of first Communication Channel for Transmitter:       */
/*   0 Off. Do not insert into the transport stream. (The       */
/*     external transmit clock only operates while data bytes   */
/*     are being transferred.)                                  */
/*   1 One byte per frame mode; CCT2BS specifies which byte in  */
/*     the transport stream will be overwritten.                */
/*   2 Two bytes per frame mode supporting OTN-style GCC.       */
/*     CCT2BS specifies the first byte to be overwritten.       */
/*     Overwriting of the second byte is implicit.              */
/*   3 Overwrite DCCR ignoring CCT2BS.                          */
/*   4 Four bytes per frame mode. CCT2BS specifies the first    */
/*     byte to be overwritten.                                  */
/*   5 Overwrite DCCM ignoring CCT2BS.                          */
/*   6 Send CCT2VAL on first communication channel.             */
/*   7 Reserved                                                 */
/*                                                              */
/* The [cct2bs] parameter is specified as:                      */
/*   CCT2BS[12:0]                                               */
/*   Byte Selector for first Communication Channel Transmit.    */
/*   Only values for GCC0(14), GCC1(64), and GCC2(66) are       */
/*   supported.                                                 */
/*   Note: This setting may destroy arbitrary bytes if set to   */
/*   values beyond 5795 for an STS-192 stream or 79 for an OTN  */
/*   stream (as selected in CCT2SS).                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT2CFG2_t tmp_sfu_cct2cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct2cfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT2CFG2));
  tmp_sfu_cct2cfg2.bf.CCT2MD = cct2md;
  tmp_sfu_cct2cfg2.bf.CCT2BS = cct2bs;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT2CFG2), tmp_sfu_cct2cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT3CFG0                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct3cfg0(cs_uint16 module_id, 
                            cs_uint16 cct3fpl, 
                            cs_uint16 cct3fpp, 
                            cs_uint16 cct3col, 
                            cs_uint16 cct3dol, 
                            cs_uint16 cct3ln, 
                            cs_uint16 cct3cmp)
/* INPUTS     : o Module Id                                     */
/*              o CCT3FPL                                       */
/*              o CCT3FPP                                       */
/*              o CCT3COL                                       */
/*              o CCT3DOL                                       */
/*              o CCT3LN                                        */
/*              o CCT3CMP                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct3fpl] parameter is specified as:                     */
/*   serial Frame Pulse logic Level:                            */
/*   0 binary:Use uninverted serial-port CCFPTO[A|B] frame      */
/*     pulse output.                                            */
/*   1 binary:Invert the serial-port CCFPTO[A|B] frame pulse    */
/*     output.                                                  */
/*                                                              */
/* The [cct3fpp] parameter is specified as:                     */
/*   serial Frame Pulse bit Position:                           */
/*   0 binary:Have MSB of first byte in incoming serial data    */
/*     stream activate CCFPTO[A|B] frame pulse output.          */
/*   1 binary:Have LSB of first byte in incoming serial data    */
/*     stream activate CCFPTO[A|B] frame pulse output.          */
/*                                                              */
/* The [cct3col] parameter is specified as:                     */
/*   serial Clock Output logic Level:                           */
/*   0 binary:Use uninverted CCTCLK[A|B] serial clock output.   */
/*     Incoming data is sampled on the falling clock edge.      */
/*   1 binary:Invert the CCTCLK[A|B] serial clock output.       */
/*     Incoming data is sampled on the rising clock edge.       */
/*                                                              */
/* The [cct3dol] parameter is specified as:                     */
/*   serial Data input Operating Level:                         */
/*   0 binary:Use uninverted CCTD[A|B]1 serial data input.      */
/*   1 binary:Invert the CCTD[A|B]1 serial data input.          */
/*                                                              */
/* The [cct3ln]  parameter is specified as:                     */
/*   CCT3LN[3:0]                                                */
/*   Acceptance filter LeNgth for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* The [cct3cmp] parameter is specified as:                     */
/*   CCT3CMP[7:0]                                               */
/*   Acceptance filter LeNgth for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT3CFG0_t tmp_sfu_cct3cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct3cfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT3CFG0));
  tmp_sfu_cct3cfg0.bf.CCT3FPL = cct3fpl;
  tmp_sfu_cct3cfg0.bf.CCT3FPP = cct3fpp;
  tmp_sfu_cct3cfg0.bf.CCT3COL = cct3col;
  tmp_sfu_cct3cfg0.bf.CCT3DOL = cct3dol;
  tmp_sfu_cct3cfg0.bf.CCT3LN = cct3ln;
  tmp_sfu_cct3cfg0.bf.CCT3CMP = cct3cmp;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT3CFG0), tmp_sfu_cct3cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT3CFG1                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct3cfg1(cs_uint16 module_id, 
                            cs_uint16 cct3ss, 
                            cs_uint16 cct3frq)
/* INPUTS     : o Module Id                                     */
/*              o CCT3SS                                        */
/*              o CCT3FRQ                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct3ss] parameter is specified as:                      */
/*   CCT3SS[3:0]                                                */
/*   Communication Channel Transmit #1 Sink Select              */
/*   configuration:                                             */
/*   0 Select OxU2 Generator #1                                 */
/*   1 Select OxU2 Generator #2                                 */
/*   2 Select OxU2 Generator #3                                 */
/*   3 Select OxU2 Generator #4                                 */
/*   4 Select STS-192 Generator #1                              */
/*   5 Select STS-192 Generator #2                              */
/*   6 Select STS-192 Generator #3                              */
/*   7 Select STS-192 Generator #4                              */
/*   8 Select OxU3 Generator                                    */
/*                                                              */
/* The [cct3frq] parameter is specified as:                     */
/*   CCT3FRQ[9:0]                                               */
/*   Communication Channel Transmit #1 FReQuency configuration: */
/*   Controls the speed of the CCTCLK[A|B]1 clock for the first */
/*   communication channel, based on the following formula:     */
/*   fCCTCLK = fOHSYSCLK / (8 x (CCT3FRQ + 1)).                 */
/*   Supported operating frequency is between 64 KHz and 25 MHz.*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT3CFG1_t tmp_sfu_cct3cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct3cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT3CFG1));
  tmp_sfu_cct3cfg1.bf.CCT3SS = cct3ss;
  tmp_sfu_cct3cfg1.bf.CCT3FRQ = cct3frq;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT3CFG1), tmp_sfu_cct3cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT3CFG2                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct3cfg2(cs_uint16 module_id, 
                            cs_uint16 cct3md, 
                            cs_uint16 cct3bs)
/* INPUTS     : o Module Id                                     */
/*              o CCT3MD                                        */
/*              o CCT3BS                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct3md] parameter is specified as:                      */
/*   CCT3MD[2:0]                                                */
/*   MoDe of first Communication Channel for Transmitter:       */
/*   0 Off. Do not insert into the transport stream. (The       */
/*     external transmit clock only operates while data bytes   */
/*     are being transferred.)                                  */
/*   1 One byte per frame mode; CCT3BS specifies which byte in  */
/*     the transport stream will be overwritten.                */
/*   2 Two bytes per frame mode supporting OTN-style GCC.       */
/*     CCT3BS specifies the first byte to be overwritten.       */
/*     Overwriting of the second byte is implicit.              */
/*   3 Overwrite DCCR ignoring CCT3BS.                          */
/*   4 Four bytes per frame mode. CCT3BS specifies the first    */
/*     byte to be overwritten.                                  */
/*   5 Overwrite DCCM ignoring CCT3BS.                          */
/*   6 Send CCT3VAL on first communication channel.             */
/*   7 Reserved                                                 */
/*                                                              */
/* The [cct3bs] parameter is specified as:                      */
/*   CCT3BS[12:0]                                               */
/*   Byte Selector for first Communication Channel Transmit.    */
/*   Only values for GCC0(14), GCC1(64), and GCC2(66) are       */
/*   supported.                                                 */
/*   Note: This setting may destroy arbitrary bytes if set to   */
/*   values beyond 5795 for an STS-192 stream or 79 for an OTN  */
/*   stream (as selected in CCT3SS).                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT3CFG2_t tmp_sfu_cct3cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct3cfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT3CFG2));
  tmp_sfu_cct3cfg2.bf.CCT3MD = cct3md;
  tmp_sfu_cct3cfg2.bf.CCT3BS = cct3bs;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT3CFG2), tmp_sfu_cct3cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT4CFG0                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct4cfg0(cs_uint16 module_id, 
                            cs_uint16 cct4fpl, 
                            cs_uint16 cct4fpp, 
                            cs_uint16 cct4col, 
                            cs_uint16 cct4dol, 
                            cs_uint16 cct4ln, 
                            cs_uint16 cct4cmp)
/* INPUTS     : o Module Id                                     */
/*              o CCT4FPL                                       */
/*              o CCT4FPP                                       */
/*              o CCT4COL                                       */
/*              o CCT4DOL                                       */
/*              o CCT4LN                                        */
/*              o CCT4CMP                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct4fpl] parameter is specified as:                     */
/*   serial Frame Pulse logic Level:                            */
/*   0 binary:Use uninverted serial-port CCFPTO[A|B] frame      */
/*     pulse output.                                            */
/*   1 binary:Invert the serial-port CCFPTO[A|B] frame pulse    */
/*     output.                                                  */
/*                                                              */
/* The [cct4fpp] parameter is specified as:                     */
/*   serial Frame Pulse bit Position:                           */
/*   0 binary:Have MSB of first byte in incoming serial data    */
/*     stream activate CCFPTO[A|B] frame pulse output.          */
/*   1 binary:Have LSB of first byte in incoming serial data    */
/*     stream activate CCFPTO[A|B] frame pulse output.          */
/*                                                              */
/* The [cct4col] parameter is specified as:                     */
/*   serial Clock Output logic Level:                           */
/*   0 binary:Use uninverted CCTCLK[A|B] serial clock output.   */
/*     Incoming data is sampled on the falling clock edge.      */
/*   1 binary:Invert the CCTCLK[A|B] serial clock output.       */
/*     Incoming data is sampled on the rising clock edge.       */
/*                                                              */
/* The [cct4dol] parameter is specified as:                     */
/*   serial Data input Operating Level:                         */
/*   0 binary:Use uninverted CCTD[A|B]1 serial data input.      */
/*   1 binary:Invert the CCTD[A|B]1 serial data input.          */
/*                                                              */
/* The [cct4ln]  parameter is specified as:                     */
/*   CCT4LN[3:0]                                                */
/*   Acceptance filter LeNgth for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* The [cct4cmp] parameter is specified as:                     */
/*   CCT4CMP[7:0]                                               */
/*   Acceptance filter LeNgth for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT4CFG0_t tmp_sfu_cct4cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct4cfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT4CFG0));
  tmp_sfu_cct4cfg0.bf.CCT4FPL = cct4fpl;
  tmp_sfu_cct4cfg0.bf.CCT4FPP = cct4fpp;
  tmp_sfu_cct4cfg0.bf.CCT4COL = cct4col;
  tmp_sfu_cct4cfg0.bf.CCT4DOL = cct4dol;
  tmp_sfu_cct4cfg0.bf.CCT4LN = cct4ln;
  tmp_sfu_cct4cfg0.bf.CCT4CMP = cct4cmp;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT4CFG0), tmp_sfu_cct4cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT4CFG1                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct4cfg1(cs_uint16 module_id, 
                            cs_uint16 cct4ss, 
                            cs_uint16 cct4frq)
/* INPUTS     : o Module Id                                     */
/*              o CCT4SS                                        */
/*              o CCT4FRQ                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct4ss] parameter is specified as:                      */
/*   CCT4SS[3:0]                                                */
/*   Communication Channel Transmit #1 Sink Select              */
/*   configuration:                                             */
/*   0 Select OxU2 Generator #1                                 */
/*   1 Select OxU2 Generator #2                                 */
/*   2 Select OxU2 Generator #3                                 */
/*   3 Select OxU2 Generator #4                                 */
/*   4 Select STS-192 Generator #1                              */
/*   5 Select STS-192 Generator #2                              */
/*   6 Select STS-192 Generator #3                              */
/*   7 Select STS-192 Generator #4                              */
/*   8 Select OxU3 Generator                                    */
/*                                                              */
/* The [cct4frq] parameter is specified as:                     */
/*   CCT4FRQ[9:0]                                               */
/*   Communication Channel Transmit #1 FReQuency configuration: */
/*   Controls the speed of the CCTCLK[A|B]1 clock for the first */
/*   communication channel, based on the following formula:     */
/*   fCCTCLK = fOHSYSCLK / (8 x (CCT4FRQ + 1)).                 */
/*   Supported operating frequency is between 64 KHz and 25 MHz.*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT4CFG1_t tmp_sfu_cct4cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct4cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT4CFG1));
  tmp_sfu_cct4cfg1.bf.CCT4SS = cct4ss;
  tmp_sfu_cct4cfg1.bf.CCT4FRQ = cct4frq;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT4CFG1), tmp_sfu_cct4cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT4CFG2                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct4cfg2(cs_uint16 module_id, 
                            cs_uint16 cct4md, 
                            cs_uint16 cct4bs)
/* INPUTS     : o Module Id                                     */
/*              o CCT4MD                                        */
/*              o CCT4BS                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct4md] parameter is specified as:                      */
/*   CCT4MD[2:0]                                                */
/*   MoDe of first Communication Channel for Transmitter:       */
/*   0 Off. Do not insert into the transport stream. (The       */
/*     external transmit clock only operates while data bytes   */
/*     are being transferred.)                                  */
/*   1 One byte per frame mode; CCT4BS specifies which byte in  */
/*     the transport stream will be overwritten.                */
/*   2 Two bytes per frame mode supporting OTN-style GCC.       */
/*     CCT4BS specifies the first byte to be overwritten.       */
/*     Overwriting of the second byte is implicit.              */
/*   3 Overwrite DCCR ignoring CCT4BS.                          */
/*   4 Four bytes per frame mode. CCT4BS specifies the first    */
/*     byte to be overwritten.                                  */
/*   5 Overwrite DCCM ignoring CCT4BS.                          */
/*   6 Send CCT4VAL on first communication channel.             */
/*   7 Reserved                                                 */
/*                                                              */
/* The [cct4bs] parameter is specified as:                      */
/*   CCT4BS[12:0]                                               */
/*   Byte Selector for first Communication Channel Transmit.    */
/*   Only values for GCC0(14), GCC1(64), and GCC2(66) are       */
/*   supported.                                                 */
/*   Note: This setting may destroy arbitrary bytes if set to   */
/*   values beyond 5795 for an STS-192 stream or 79 for an OTN  */
/*   stream (as selected in CCT4SS).                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT4CFG2_t tmp_sfu_cct4cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct4cfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT4CFG2));
  tmp_sfu_cct4cfg2.bf.CCT4MD = cct4md;
  tmp_sfu_cct4cfg2.bf.CCT4BS = cct4bs;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT4CFG2), tmp_sfu_cct4cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT5CFG0                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct5cfg0(cs_uint16 module_id, 
                            cs_uint16 cct5fpl, 
                            cs_uint16 cct5fpp, 
                            cs_uint16 cct5col, 
                            cs_uint16 cct5dol, 
                            cs_uint16 cct5ln, 
                            cs_uint16 cct5cmp)
/* INPUTS     : o Module Id                                     */
/*              o CCT5FPL                                       */
/*              o CCT5FPP                                       */
/*              o CCT5COL                                       */
/*              o CCT5DOL                                       */
/*              o CCT5LN                                        */
/*              o CCT5CMP                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct5fpl] parameter is specified as:                     */
/*   serial Frame Pulse logic Level:                            */
/*   0 binary:Use uninverted serial-port CCFPTO[A|B] frame      */
/*     pulse output.                                            */
/*   1 binary:Invert the serial-port CCFPTO[A|B] frame pulse    */
/*     output.                                                  */
/*                                                              */
/* The [cct5fpp] parameter is specified as:                     */
/*   serial Frame Pulse bit Position:                           */
/*   0 binary:Have MSB of first byte in incoming serial data    */
/*     stream activate CCFPTO[A|B] frame pulse output.          */
/*   1 binary:Have LSB of first byte in incoming serial data    */
/*     stream activate CCFPTO[A|B] frame pulse output.          */
/*                                                              */
/* The [cct5col] parameter is specified as:                     */
/*   serial Clock Output logic Level:                           */
/*   0 binary:Use uninverted CCTCLK[A|B] serial clock output.   */
/*     Incoming data is sampled on the falling clock edge.      */
/*   1 binary:Invert the CCTCLK[A|B] serial clock output.       */
/*     Incoming data is sampled on the rising clock edge.       */
/*                                                              */
/* The [cct5dol] parameter is specified as:                     */
/*   serial Data input Operating Level:                         */
/*   0 binary:Use uninverted CCTD[A|B]1 serial data input.      */
/*   1 binary:Invert the CCTD[A|B]1 serial data input.          */
/*                                                              */
/* The [cct5ln]  parameter is specified as:                     */
/*   CCT5LN[3:0]                                                */
/*   Acceptance filter LeNgth for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* The [cct5cmp] parameter is specified as:                     */
/*   CCT5CMP[7:0]                                               */
/*   Acceptance filter LeNgth for AIS, specified as a frame     */
/*   count.                                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT5CFG0_t tmp_sfu_cct5cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct5cfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT5CFG0));
  tmp_sfu_cct5cfg0.bf.CCT5FPL = cct5fpl;
  tmp_sfu_cct5cfg0.bf.CCT5FPP = cct5fpp;
  tmp_sfu_cct5cfg0.bf.CCT5COL = cct5col;
  tmp_sfu_cct5cfg0.bf.CCT5DOL = cct5dol;
  tmp_sfu_cct5cfg0.bf.CCT5LN = cct5ln;
  tmp_sfu_cct5cfg0.bf.CCT5CMP = cct5cmp;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT5CFG0), tmp_sfu_cct5cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT5CFG1                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct5cfg1(cs_uint16 module_id, 
                            cs_uint16 cct5ss, 
                            cs_uint16 cct5frq)
/* INPUTS     : o Module Id                                     */
/*              o CCT5SS                                        */
/*              o CCT5FRQ                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct5ss] parameter is specified as:                      */
/*   CCT5SS[3:0]                                                */
/*   Communication Channel Transmit #1 Sink Select              */
/*   configuration:                                             */
/*   0 Select OxU2 Generator #1                                 */
/*   1 Select OxU2 Generator #2                                 */
/*   2 Select OxU2 Generator #3                                 */
/*   3 Select OxU2 Generator #4                                 */
/*   4 Select STS-192 Generator #1                              */
/*   5 Select STS-192 Generator #2                              */
/*   6 Select STS-192 Generator #3                              */
/*   7 Select STS-192 Generator #4                              */
/*   8 Select OxU3 Generator                                    */
/*                                                              */
/* The [cct5frq] parameter is specified as:                     */
/*   CCT5FRQ[9:0]                                               */
/*   Communication Channel Transmit #1 FReQuency configuration: */
/*   Controls the speed of the CCTCLK[A|B]1 clock for the first */
/*   communication channel, based on the following formula:     */
/*   fCCTCLK = fOHSYSCLK / (8 x (CCT5FRQ + 1)).                 */
/*   Supported operating frequency is between 64 KHz and 25 MHz.*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT5CFG1_t tmp_sfu_cct5cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct5cfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT5CFG1));
  tmp_sfu_cct5cfg1.bf.CCT5SS = cct5ss;
  tmp_sfu_cct5cfg1.bf.CCT5FRQ = cct5frq;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT5CFG1), tmp_sfu_cct5cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU CCT5CFG2                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_cct5cfg2(cs_uint16 module_id, 
                            cs_uint16 cct5md, 
                            cs_uint16 cct5bs)
/* INPUTS     : o Module Id                                     */
/*              o CCT5MD                                        */
/*              o CCT5BS                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Communication Channel Transmit Configuration         */
/* Register                                                     */
/*                                                              */
/* The [cct5md] parameter is specified as:                      */
/*   CCT5MD[2:0]                                                */
/*   MoDe of first Communication Channel for Transmitter:       */
/*   0 Off. Do not insert into the transport stream. (The       */
/*     external transmit clock only operates while data bytes   */
/*     are being transferred.)                                  */
/*   1 One byte per frame mode; CCT5BS specifies which byte in  */
/*     the transport stream will be overwritten.                */
/*   2 Two bytes per frame mode supporting OTN-style GCC.       */
/*     CCT5BS specifies the first byte to be overwritten.       */
/*     Overwriting of the second byte is implicit.              */
/*   3 Overwrite DCCR ignoring CCT5BS.                          */
/*   4 Four bytes per frame mode. CCT5BS specifies the first    */
/*     byte to be overwritten.                                  */
/*   5 Overwrite DCCM ignoring CCT5BS.                          */
/*   6 Send CCT5VAL on first communication channel.             */
/*   7 Reserved                                                 */
/*                                                              */
/* The [cct5bs] parameter is specified as:                      */
/*   CCT5BS[12:0]                                               */
/*   Byte Selector for first Communication Channel Transmit.    */
/*   Only values for GCC0(14), GCC1(64), and GCC2(66) are       */
/*   supported.                                                 */
/*   Note: This setting may destroy arbitrary bytes if set to   */
/*   values beyond 5795 for an STS-192 stream or 79 for an OTN  */
/*   stream (as selected in CCT5SS).                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCT5CFG2_t tmp_sfu_cct5cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cct5cfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT5CFG2));
  tmp_sfu_cct5cfg2.bf.CCT5MD = cct5md;
  tmp_sfu_cct5cfg2.bf.CCT5BS = cct5bs;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCT5CFG2), tmp_sfu_cct5cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET CCTVAL                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_cctval(cs_uint16 module_id, 
                                  cs_uint16 cctval, 
                                  cs_uint8 channel)
/* INPUTS     : o Module Id                                     */
/*              o CCTVAL                                        */
/*              o Channel                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets Communication Channel Transmit Configuration Register.  */
/*                                                              */
/* The [cctval] parameter is specified as:                      */
/*   CCT1VAL[7:0] Value to be sent when CCTxMD is set to 6.     */
/*                                                              */
/* The [channel] parameter is specified as:                     */
/*   1..5                                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  switch (channel) {
    case 1:
    {
      TEN_OHPP_SFU_CCTVAL0_t tmp_sfu_cctval0;
      tmp_sfu_cctval0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTVAL0));
      tmp_sfu_cctval0.bf.CCT1VAL = cctval;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTVAL0), tmp_sfu_cctval0.wrd);
      break;
    }
    case 2:
    {
      TEN_OHPP_SFU_CCTVAL0_t tmp_sfu_cctval0;
      tmp_sfu_cctval0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTVAL0));
      tmp_sfu_cctval0.bf.CCT2VAL = cctval;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTVAL0), tmp_sfu_cctval0.wrd);
      break;
    }
    case 3:
    {
      TEN_OHPP_SFU_CCTVAL1_t tmp_sfu_cctval1;
      tmp_sfu_cctval1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTVAL1));
      tmp_sfu_cctval1.bf.CCT3VAL = cctval;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTVAL1), tmp_sfu_cctval1.wrd);
      break;
    }
    case 4:
    {
      TEN_OHPP_SFU_CCTVAL1_t tmp_sfu_cctval1;
      tmp_sfu_cctval1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTVAL1));
      tmp_sfu_cctval1.bf.CCT4VAL = cctval;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTVAL1), tmp_sfu_cctval1.wrd);
      break;
    }
    case 5:
    {
      TEN_OHPP_SFU_CCTVAL2_t tmp_sfu_cctval2;
      tmp_sfu_cctval2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTVAL2));
      tmp_sfu_cctval2.bf.CCT5VAL = cctval;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTVAL2), tmp_sfu_cctval2.wrd);
      break;
    }
    default :
    {
      CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": channel = 0x%04X\n", channel);
      ret_val = CS_ERROR;
      break;
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU GET CCTSTATE                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_ohpp_sfu_get_cctstate(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* CCTAIS[4:0]                                                  */
/* AIS detected on Communication Channel for Transmitter.       */
/* Bit 0 is tied to the first CCT, bit 4 to the fifth CCT.      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CCTSTATE_t tmp_sfu_cctstate;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_sfu_cctstate.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CCTSTATE));

  return (tmp_sfu_cctstate.wrd);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET OCLKCFG                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_oclkcfg(cs_uint16 module_id, 
                                   cs_uint16 tclkoinv, 
                                   cs_uint16 rclkoinv)
/* INPUTS     : o Module Id                                     */
/*              o TCLKOINV                                      */
/*              o RCLKOINV                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the OHPP Clock Configuration Register.                   */
/*                                                              */
/* The [tclkoinv] parameter is specified as:                    */
/*   Inverts the OHPP_TCLKOx_P/N clock output for the           */
/*   respective A or B side.                                    */
/*                                                              */
/* The [rclkoinv] parameter is specified as:                    */
/*   Inverts the OHPP_RCLKOx_P/N clock output for the           */
/*   respective A or B side.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_OCLKCFG_t tmp_sfu_oclkcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_oclkcfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OCLKCFG));
  tmp_sfu_oclkcfg.bf.TCLKOINV = tclkoinv;
  tmp_sfu_oclkcfg.bf.RCLKOINV = rclkoinv;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OCLKCFG), tmp_sfu_oclkcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET MSIGNAL                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_msignal(cs_uint16 module_id,
                                   cs_uint16 row,
                                   cs_uint16 value)
/* INPUTS     : o Module Id                                     */
/*              o Row                                           */
/*              o Value                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This vector is ORed with the Consequent Action bits allowing */
/* maintenance signals to be created manually.                  */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0 - 77                                                     */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   0 - 1                                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_ohpp_sfu_set_msignal";  
  
  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() row %d out of range.  s/b 0..77.", func, row);
    return(CS_ERROR);
  }
  if (value > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() value%d  out of range.  s/b 0..1.", func, value);
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s row %d, value %d\n", func, ten_module_strings[module_id&1], row, value);
    
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP); 
  if (row < 16) {
    TEN_OHPP_SFU_MSIGNAL0_t tmp_sfu_msignal;
    tmp_sfu_msignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL0));
    if (value == 1) {
      tmp_sfu_msignal.wrd |= (0x0001 << row);
    }
    else {
      tmp_sfu_msignal.wrd &= ~(0x0001 << row);
    }
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL0), tmp_sfu_msignal.wrd);
  }
  else if ((row > 15) && (row < 32)) {
    TEN_OHPP_SFU_MSIGNAL1_t tmp_sfu_msignal;
    tmp_sfu_msignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL1));
    if (value == 1) {
      tmp_sfu_msignal.wrd |= (0x0001 << (row-16));
    }
    else {
      tmp_sfu_msignal.wrd &= ~(0x0001 << (row-16));
    }    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL1), tmp_sfu_msignal.wrd);
  }
  else if ((row > 31) && (row < 48)) {
    TEN_OHPP_SFU_MSIGNAL2_t tmp_sfu_msignal;
    tmp_sfu_msignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL2));
    if (value == 1) {
      tmp_sfu_msignal.wrd |= (0x0001 << (row-32));
    }
    else {
      tmp_sfu_msignal.wrd &= ~(0x0001 << (row-32));
    }    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL2), tmp_sfu_msignal.wrd);
  }
  else if ((row > 47) && (row < 64)) {
    TEN_OHPP_SFU_MSIGNAL3_t tmp_sfu_msignal;
    tmp_sfu_msignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL3));
    if (value == 1) {
      tmp_sfu_msignal.wrd |= (0x0001 << (row-48));
    }
    else {
      tmp_sfu_msignal.wrd &= ~(0x0001 << (row-48));
    }    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL3), tmp_sfu_msignal.wrd);
  }
  else {
    TEN_OHPP_SFU_MSIGNAL4_t tmp_sfu_msignal;
    tmp_sfu_msignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL4));
    if (value == 1) {
      tmp_sfu_msignal.wrd |= (0x0001 << (row-64));
    }
    else {
      tmp_sfu_msignal.wrd &= ~(0x0001 << (row-64));
    }    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL4), tmp_sfu_msignal.wrd);
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP); 

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU GET MSIGNAL                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_ohpp_sfu_get_msignal(cs_uint16 module_id,
                                  cs_uint16 row)
/* INPUTS     : o Module Id                                     */
/*              o Row                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This vector is ORed with the Consequent Action bits allowing */
/* maintenance signals to be created manually.                  */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0 - 77                                                     */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_int16 ret_val;
  T41_t *pDev = NULL;
  
  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
    
  if (row < 16) {
    TEN_OHPP_SFU_MSIGNAL0_t tmp_sfu_msignal;
    tmp_sfu_msignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL0));
    ret_val = (tmp_sfu_msignal.wrd >> row) & 0x0001;
  }
  else if ((row > 15) && (row < 32)) {
    TEN_OHPP_SFU_MSIGNAL1_t tmp_sfu_msignal;
    tmp_sfu_msignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL1));
    ret_val = (tmp_sfu_msignal.wrd >> (row-16)) & 0x0001;
  }
  else if ((row > 31) && (row < 48)) {
    TEN_OHPP_SFU_MSIGNAL2_t tmp_sfu_msignal;
    tmp_sfu_msignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL2));
    ret_val = (tmp_sfu_msignal.wrd >> (row-32)) & 0x0001;
  }
  else if ((row > 47) && (row < 64)) {
    TEN_OHPP_SFU_MSIGNAL3_t tmp_sfu_msignal;
    tmp_sfu_msignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL3));
    ret_val = (tmp_sfu_msignal.wrd >> (row-48)) & 0x0001;
  }
  else {
    TEN_OHPP_SFU_MSIGNAL4_t tmp_sfu_msignal;
    tmp_sfu_msignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, MSIGNAL4));
    ret_val = (tmp_sfu_msignal.wrd >> (row-64)) & 0x0001;
  }

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU GET OSIGNAL                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_ohpp_sfu_get_osignal(cs_uint16 module_id,
                                  cs_uint16 row)
/* INPUTS     : o Module Id                                     */
/*              o Row                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This vector is ORed with the Consequent Action bits allowing */
/* maintenance signals to be created manually.                  */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0 - 77                                                     */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_int16 ret_val;
  T41_t *pDev = NULL;
  
  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
    
  if (row < 16) {
    TEN_OHPP_SFU_OSIGNAL0_t tmp_sfu_osignal;
    tmp_sfu_osignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OSIGNAL0));
    ret_val = (tmp_sfu_osignal.wrd >> row) & 0x0001;
  }
  else if ((row > 15) && (row < 32)) {
    TEN_OHPP_SFU_OSIGNAL1_t tmp_sfu_osignal;
    tmp_sfu_osignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OSIGNAL1));
    ret_val = (tmp_sfu_osignal.wrd >> (row-16)) & 0x0001;
  }
  else if ((row > 31) && (row < 48)) {
    TEN_OHPP_SFU_OSIGNAL2_t tmp_sfu_osignal;
    tmp_sfu_osignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OSIGNAL2));
    ret_val = (tmp_sfu_osignal.wrd >> (row-32)) & 0x0001;
  }
  else if ((row > 47) && (row < 64)) {
    TEN_OHPP_SFU_OSIGNAL3_t tmp_sfu_osignal;
    tmp_sfu_osignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OSIGNAL3));
    ret_val = (tmp_sfu_osignal.wrd >> (row-48)) & 0x0001;
  }
  else {
    TEN_OHPP_SFU_OSIGNAL4_t tmp_sfu_osignal;
    tmp_sfu_osignal.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, OSIGNAL4));
    ret_val = (tmp_sfu_osignal.wrd >> (row-64)) & 0x0001;
  }

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET M3BCFG                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_m3bcfg(cs_uint16 module_id, 
                                  cs_uint16 stream, 
                                  cs_uint16 m3bmsk)
/* INPUTS     : o Module Id                                     */
/*              o Stream                                        */
/*              o M3BMSK                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SFU Monitor Third Byte Mask Configuration Registers. */
/*                                                              */
/* The [stream] parameter is specified as:                      */
/*   1 - 5                                                      */
/*                                                              */
/* The [m3bmsk] parameter is specified as:                      */
/*   Monitoring 3rd Byte Mask for outgoing overhead stream.     */
/*   This parameter determines whether or not the 3rd byte of a */
/*   PM, SM or TCM is inserted. This influences BEI insertion   */
/*   through the BEI Forwarding Unit the handling of the IAE    */
/*   and BDI Consequent Action bits, and the distribution of    */
/*   maintenance information across the STAT bits. When         */
/*   M3BxMSK[0] is set, the 3rd byte of the PM section is       */
/*   generated by the BEI Forwarding Unit. When M3BxMSK[7] is   */
/*   set, the 3rd byte of the SM section is generated by the    */
/*   BEI Forwarding Unit. When M3BxMSK[n] is set the 3rd byte   */
/*   of the nth Tandem Connection Monitoring section is         */
/*   generated by the BEI Forwarding Unit.                      */
/*   1 = OxU2 Overhead Stream #1                                */
/*   2 = OxU2 Overhead Stream #2                                */
/*   3 = OxU2 Overhead Stream #3                                */
/*   4 = OxU2 Overhead Stream #4                                */
/*   5 = OxU3 Overhead Stream                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  switch (stream) {
    case 1 :
    {
      TEN_OHPP_SFU_M3BCFG0_t tmp_sfu_m3bcfg0;
      tmp_sfu_m3bcfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, M3BCFG0));
      tmp_sfu_m3bcfg0.bf.M3B1MSK = m3bmsk;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, M3BCFG0), tmp_sfu_m3bcfg0.wrd);
      break;
    }
    case 2 :
    {
      TEN_OHPP_SFU_M3BCFG0_t tmp_sfu_m3bcfg0;
      tmp_sfu_m3bcfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, M3BCFG0));
      tmp_sfu_m3bcfg0.bf.M3B2MSK = m3bmsk;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, M3BCFG0), tmp_sfu_m3bcfg0.wrd);
      break;
    }
    case 3 :
    {
      TEN_OHPP_SFU_M3BCFG1_t tmp_sfu_m3bcfg1;
      tmp_sfu_m3bcfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, M3BCFG1));
      tmp_sfu_m3bcfg1.bf.M3B3MSK = m3bmsk;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, M3BCFG1), tmp_sfu_m3bcfg1.wrd);
      break;
    }
    case 4 :
    {
      TEN_OHPP_SFU_M3BCFG1_t tmp_sfu_m3bcfg1;
      tmp_sfu_m3bcfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, M3BCFG1));
      tmp_sfu_m3bcfg1.bf.M3B4MSK = m3bmsk;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, M3BCFG1), tmp_sfu_m3bcfg1.wrd);
      break;
    }
    case 5 :
    {
      TEN_OHPP_SFU_M3BCFG2_t tmp_sfu_m3bcfg2;
      tmp_sfu_m3bcfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, M3BCFG2));
      tmp_sfu_m3bcfg2.bf.M3B5MSK = m3bmsk;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, M3BCFG2), tmp_sfu_m3bcfg2.wrd);
      break;
    }
    default :
    {
      CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": stream = 0x%04X\n", stream);
      ret_val = CS_ERROR;
      break;
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET NSTCFG                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_nstcfg(cs_uint16 module_id, 
                                  cs_uint16 stream, 
                                  cs_uint16 nstc)
/* INPUTS     : o Module Id                                     */
/*              o Stream                                        */
/*              o NSTC                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SFU TCM STAT Configuration Registers.                */
/*                                                              */
/* The [stream] parameter is specified as:                      */
/*   1 - 5                                                      */
/*                                                              */
/* The [nstc] parameter is specified as:                        */
/*   NSTCx[0] specifies whether the STAT field in the TCM1      */
/*   section of the outgoing overhead stream is set to 000      */
/*   binary (no source TC), to 001 binary (TC in use) or to 010 */
/*   binary (TC in use with IAE).                               */
/*   This is effective only if M3B1MSKx is set and no           */
/*   maintenance signal is active. The IAE decision is made     */
/*   using the appropriate FAWM signaling bit in the event      */
/*   configuration vector.                                      */
/*   NSTCx[5:1] do the same for TCM2 ... TCM6.                  */
/*   1 = OxU2 Overhead Stream #1                                */
/*   2 = OxU2 Overhead Stream #2                                */
/*   3 = OxU2 Overhead Stream #3                                */
/*   4 = OxU2 Overhead Stream #4                                */
/*   5 = OxU3 Overhead Stream                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  switch (stream) {
    case 1 :
    {
      TEN_OHPP_SFU_NSTCFG0_t tmp_sfu_nstcfg0;
      tmp_sfu_nstcfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, NSTCFG0));
      tmp_sfu_nstcfg0.bf.NSTC1 = nstc;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, NSTCFG0), tmp_sfu_nstcfg0.wrd);
      break;
    }
    case 2 :
    {
      TEN_OHPP_SFU_NSTCFG0_t tmp_sfu_nstcfg0;
      tmp_sfu_nstcfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, NSTCFG0));
      tmp_sfu_nstcfg0.bf.NSTC2 = nstc;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, NSTCFG0), tmp_sfu_nstcfg0.wrd);
      break;
    }
    case 3 :
    {
      TEN_OHPP_SFU_NSTCFG1_t tmp_sfu_nstcfg1;
      tmp_sfu_nstcfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, NSTCFG1));
      tmp_sfu_nstcfg1.bf.NSTC3 = nstc;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, NSTCFG1), tmp_sfu_nstcfg1.wrd);
      break;
    }
    case 4 :
    {
      TEN_OHPP_SFU_NSTCFG1_t tmp_sfu_nstcfg1;
      tmp_sfu_nstcfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, NSTCFG1));
      tmp_sfu_nstcfg1.bf.NSTC4 = nstc;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, NSTCFG1), tmp_sfu_nstcfg1.wrd);
      break;
    }
    case 5 :
    {
      TEN_OHPP_SFU_NSTCFG2_t tmp_sfu_nstcfg2;
      tmp_sfu_nstcfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, NSTCFG2));
      tmp_sfu_nstcfg2.bf.NSTC5 = nstc;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, NSTCFG2), tmp_sfu_nstcfg2.wrd);
      break;
    }
    default :
    {
      CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": stream = 0x%04X\n", stream);
      ret_val = CS_ERROR;
      break;
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET DIRECT IO MODE                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_direct_io_mode(cs_uint16 module_id, 
                                    cs_uint16 direct_io_mode)
/* INPUTS     : o Module Id                                     */
/*              o DIRECT_IO_MODE                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SFU Main Configuration Register.                     */
/*                                                              */
/* The [direct_io_mode] parameter is specified as:              */
/*   Selects direct SFU connection to the OHPP Parallel         */
/*   Overhead Interface I/O.  When enabled, consequent          */
/*   actions signals GPSB9 through GPSB5 (SEG78 through         */
/*   SEG74) are connected directly from the SFU to external     */
/*   POI outputs {OHPP_RCB[1:0], OHPP_RDB[7:5]} for A side,     */
/*   or OHPP_RDB[4:0] for B side.  When enabled, external       */
/*   POI inputs {OHPP_TIB, OHPP_TCLKIB, OHPP_TDB[7:5]} for A    */
/*   side, or OHPP_TDB[4:0] for B side, are connected directly  */
/*   to SFU event inputs AF[7] (CMP GAF #8) for each OxU.       */
/*   This maps to event vector bits {459, 375, 291,             */
/*   207, 123} for this side, and 492+{459, 375, 291, 207, 123} */
/*   for other side.                                            */
/*   0 = POI operates as TDM interface.                         */
/*   1 = POI operates as static SFU inputs and outputs.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CFG_t tmp_sfu_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG));
  tmp_sfu_cfg.bf.DIRECT_IO_MODE = direct_io_mode;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG), tmp_sfu_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET LSOH MODE                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_lsoh_mode(cs_uint16 module_id, 
                                     cs_uint16 lsoh_mode)
/* INPUTS     : o Module Id                                     */
/*              o LSOH_MODE                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SFU Main Configuration Register.                     */
/*                                                              */
/* The [lsoh_mode] parameter is specified as:                   */
/*   Selects the OHPP Parallel Overhead Interface data rate.    */
/*   0 = POI operates at SYSCLK rate.                           */
/*   1 = POI operates at SYSCLK/4 rate.                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CFG_t tmp_sfu_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG));
  tmp_sfu_cfg.bf.LSOH_MODE = lsoh_mode;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG), tmp_sfu_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET PHDTCTEN                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_phdtcten(cs_uint16 module_id, 
                                    cs_uint16 phdtcten)
/* INPUTS     : o Module Id                                     */
/*              o PHDTCTEN                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SFU Main Configuration Register.                     */
/*                                                              */
/* The [phdtcten] parameter is specified as:                    */
/*   Phase Detect Enable. Setting this bit enables the phase    */
/*   detect logic to detect a TIP cycle on the external         */
/*   parallel transmit data interface. If this bit is not set,  */
/*   no attempt will be made to synchronize to the incoming     */
/*   transmit data and data will be internally muxed to zero    */
/*   including the insert bit.                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CFG_t tmp_sfu_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG));
  tmp_sfu_cfg.bf.PHDTCTEN = phdtcten;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG), tmp_sfu_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET SFCMSEL                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_sfcmsel(cs_uint16 module_id, 
                                   cs_uint16 sfcmsel)
/* INPUTS     : o Module Id                                     */
/*              o SFCMSEL                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SFU Main Configuration Register.                     */
/*                                                              */
/* The [sfcmsel] parameter is specified as:                     */
/*   Signal Forwarding Controller Memory SELection. The SFC     */
/*   memory is composed of two identical memories (A & B).      */
/*   Memory A is selected for use by the Signal Forwarding Unit */
/*   when SFCMSEL = 0. The memory available for processor       */
/*   access is SFC memory B. When SFCMSEL is written to 1,      */
/*   memory A becomes available for processor access and memory */
/*   B is activated for use by the Signal Forwarding Unit. A    */
/*   small delay occurs internally whenever the memory is       */
/*   switched. After SFCMSEL is changed, a delay up to 760      */
/*   system clock cycles will pass before the memories are      */
/*   switched. The delay waits for the Signal Forwarding Unit   */
/*   to wrap to location 0 of the memory before making the      */
/*   switch. If SIGGENE is 0, the memory swap will occur        */
/*   immediately.                                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CFG_t tmp_sfu_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG));
  tmp_sfu_cfg.bf.SFCMSEL = sfcmsel;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG), tmp_sfu_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET NULOTHR                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_nulothr(cs_uint16 module_id, 
                                   cs_uint16 nulothr)
/* INPUTS     : o Module Id                                     */
/*              o NULOTHR                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SFU Main Configuration Register.                     */
/*                                                              */
/* The [nulothr] parameter is specified as:                     */
/*   Setting this bit forces the inputs to 'the other' SFU,     */
/*   that is the remote SFU in the second receiver module, to   */
/*   constant zero.                                             */
/*   NOTE: Use this bit with care because it                    */
/*   corrupts the General Purpose Signaling Insertion Unit, BEI */
/*   insertion, and M0/M1 insertion.                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CFG_t tmp_sfu_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG));
  tmp_sfu_cfg.bf.NULOTHR = nulothr;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG), tmp_sfu_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET NULTHIS                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_nulthis(cs_uint16 module_id,  
                                   cs_uint16 nulthis)
/* INPUTS     : o Module Id                                     */
/*              o NULTHIS                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SFU Main Configuration Register.                     */
/*                                                              */
/* The [nulthis] parameter is specified as:                     */
/*   Setting this bit forces the inputs to 'this' SFU, that is  */
/*   the SFU in the same receiver module, to constant zero.     */
/*   NOTE: Use this bit with care because it corrupts the       */
/*   General Purpose Signaling Insertion Unit, BEI insertion,   */
/*   and M0/M1 insertion.                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CFG_t tmp_sfu_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG));
  tmp_sfu_cfg.bf.NULTHIS = nulthis;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG), tmp_sfu_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET DOAIEN                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_doaien(cs_uint16 module_id, 
                                  cs_uint16 doaien)
/* INPUTS     : o Module Id                                     */
/*              o DOAIEN                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SFU Main Configuration Register.                     */
/*                                                              */
/* The [doaien] parameter is specified as:                      */
/*   When set, the Direct Overhead Access Insertion Unit is     */
/*   enabled. The DOAIU memory must be initialized before       */
/*   enabling this unit to avoid ECC errors.                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CFG_t tmp_sfu_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG));
  tmp_sfu_cfg.bf.DOAIEN = doaien;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG), tmp_sfu_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET SIGGENE                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_siggene(cs_uint16 module_id,  
                                   cs_uint16 siggene)
/* INPUTS     : o Module Id                                     */
/*              o SIGGENE                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SFU Main Configuration Register.                     */
/*                                                              */
/* The [siggene] parameter is specified as:                     */
/*   SIGnaling GENeration unit Enable. When this bit is set     */
/*   the Signaling Fowarding Unit is active and processing      */
/*   overhead.                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_CFG_t tmp_sfu_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG));
  tmp_sfu_cfg.bf.SIGGENE = siggene;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG), tmp_sfu_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET ADMOHEN                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_admohen(cs_uint16 module_id, 
                                   cs_uint16 admohen)
/* INPUTS     : o Module Id                                     */
/*              o ADMOHEN                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Framer Overhead Interface Enable Register.  FRMROHEN */
/* must be configured before the removal of SRESET.             */
/*                                                              */
/* The [admohen] parameter is specified as:                     */
/*   ADMOHEN[3:0] Enables internal ADMIN overhead information   */
/*   for the respective interface                               */
/*   Bit 0: Interface 1/40G KPA enable (1) or disable (0)       */
/*   Bit 1: Interface 2 enable (1) or disable (0)               */
/*   Bit 2: Interface 3 enable (1) or disable (0)               */
/*   Bit 3: Interface 4 enable (1) or disable (0)               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_FRMROHEN_t tmp_sfu_frmrohen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_frmrohen.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, FRMROHEN));
  tmp_sfu_frmrohen.bf.ADMOHEN = admohen;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, FRMROHEN), tmp_sfu_frmrohen.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET STSOHEN                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_stsohen(cs_uint16 module_id, 
                                   cs_uint16 stsohen)
/* INPUTS     : o Module Id                                     */
/*              o STSOHEN                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Framer Overhead Interface Enable Register.  FRMROHEN */
/* must be configured before the removal of SRESET.             */
/*                                                              */
/* The [stsohen] parameter is specified as:                     */
/*   STSOHEN[3:0] Enables internal overhead communication       */
/*   between OHPP and the respective STS-192 framer             */
/*   Bit 0: STS-192_1 enable (1) or disable (0)                 */
/*   Bit 1: STS-192_2 enable (1) or disable (0)                 */
/*   Bit 2: STS-192_3 enable (1) or disable (0)                 */
/*   Bit 3: STS-192_4 enable (1) or disable (0)                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_FRMROHEN_t tmp_sfu_frmrohen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_frmrohen.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, FRMROHEN));
  tmp_sfu_frmrohen.bf.STSOHEN = stsohen;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, FRMROHEN), tmp_sfu_frmrohen.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET OTNOHEN                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_otnohen(cs_uint16 module_id, 
                                   cs_uint16 otnohen)
/* INPUTS     : o Module Id                                     */
/*              o OTNOHEN                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Framer Overhead Interface Enable Register.  FRMROHEN */
/* must be configured before the removal of SRESET.             */
/*                                                              */
/* The [otnohen] parameter is specified as:                     */
/*   OTNOHEN[4:0] Enables internal overhead communication       */
/*   between OHPP and the respective OTN framer                 */
/*   Bit 0: OxU2_1 enable (1) or disable (0)                    */
/*   Bit 1: OxU2_2 enable (1) or disable (0)                    */
/*   Bit 2: OxU2_3 enable (1) or disable (0)                    */
/*   Bit 3: OxU2_4 enable (1) or disable (0)                    */
/*   Bit 4: OxU3   enable (1) or disable (0)                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_FRMROHEN_t tmp_sfu_frmrohen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_frmrohen.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, FRMROHEN));
  tmp_sfu_frmrohen.bf.OTNOHEN = otnohen;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, FRMROHEN), tmp_sfu_frmrohen.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/*****************************************************************/
/* $rtn_hdr_start  OHPP SFU GET STATE                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_ohpp_sfu_get_state(cs_uint16 module_id, 
                                cs_uint16 select)
/* INPUTS     : o Module Id                                     */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Get SFU Main Status.                                         */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_OHPP_SFU_STATE_SFCINIT  = 0                            */
/*   TEN_OHPP_SFU_STATE_SFCBANK  = 1                            */
/*   TEN_OHPP_SFU_STATE_DOAIRF   = 2                            */
/*   TEN_OHPP_SFU_STATE_DOAIBFF  = 3                            */
/*   TEN_OHPP_SFU_STATE_PHLOST   = 4                            */
/*   TEN_OHPP_SFU_STATE_ALL      = 0xFF                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_int16 ret_val;
  TEN_OHPP_SFU_STATE_t tmp_sfu_state;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  tmp_sfu_state.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, STATE));
  switch (select) {
    case TEN_OHPP_SFU_STATE_SFCINIT :
    {
      ret_val = tmp_sfu_state.bf.SFCINIT;
      break;
    }
    case TEN_OHPP_SFU_STATE_SFCBANK :
    {
      ret_val = tmp_sfu_state.bf.SFCBANK;
      break;
    }
    case TEN_OHPP_SFU_STATE_DOAIRF :
    {
      ret_val = tmp_sfu_state.bf.DOAIRF;
      break;
    }
    case TEN_OHPP_SFU_STATE_DOAIBFF :
    {
      ret_val = tmp_sfu_state.bf.DOAIBFF;
      break;
    }
    case TEN_OHPP_SFU_STATE_PHLOST :
    {
      ret_val = tmp_sfu_state.bf.PHLOST;
      break;
    }
    case TEN_OHPP_SFU_STATE_ALL :
    {
      ret_val = tmp_sfu_state.wrd;
      break;
    }
    default :
    {
      ret_val = CS_ERROR;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..4, 0xFF.");
      break;
    }
  }
  
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET DOAUM                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_doaum(cs_uint16 module_id, 
                                 cs_uint16 stream, 
                                 cs_uint16 doaum)
/* INPUTS     : o Module Id                                     */
/*              o Stream                                        */
/*              o DOAUM                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Direct Overhead Access Update Method                 */
/*                                                              */
/* The [stream] parameter is specified as:                      */
/*   0 = OxU3 data stream                                       */
/*   1 = OxU2 data stream #1                                    */
/*   2 = OxU2 data stream #2                                    */
/*   3 = OxU2 data stream #3                                    */
/*   4 = OxU2 data stream #4                                    */
/*                                                              */
/* The [doaum] parameter is specified as:                       */
/*   DOAUMx[1:0]                                                */
/*   0 = Extract full overhead to memory according to the       */
/*       current frame phase then update with each frame.       */
/*   1 = Extract once when triggered by DOAUP1.                 */
/*   2 = Extract when triggered by the acceptance filter        */
/*       configured in DOASEL then update with each frame.      */
/*   3 = Extract once when the statistics interval selected by  */
/*       DOASEL expires.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;
  TEN_OHPP_SFU_DOACFG0_t tmp_sfu_doacfg0;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_doacfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG0));
  switch (stream) {
    case 0 :
    {
      tmp_sfu_doacfg0.bf.DOAUM0 = doaum;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG0), tmp_sfu_doacfg0.wrd);
      break;
    }
    case 1 :
    {
      tmp_sfu_doacfg0.bf.DOAUM1 = doaum;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG0), tmp_sfu_doacfg0.wrd);
      break;
    }
    case 2 :
    {
      tmp_sfu_doacfg0.bf.DOAUM2 = doaum;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG0), tmp_sfu_doacfg0.wrd);
      break;
    }
    case 3 :
    {
      tmp_sfu_doacfg0.bf.DOAUM3 = doaum;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG0), tmp_sfu_doacfg0.wrd);
      break;
    }
    case 4 :
    {
      tmp_sfu_doacfg0.bf.DOAUM4 = doaum;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG0), tmp_sfu_doacfg0.wrd);
      break;
    }
    default :
    {
      ret_val = CS_ERROR;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": stream out of range.  s/b 0..4.");
      break;
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET DOASEL                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_doasel(cs_uint16 module_id, 
                                  cs_uint16 stream, 
                                  cs_uint16 doasel)
/* INPUTS     : o Module Id                                     */
/*              o Stream                                        */
/*              o DOASEL                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Direct Overhead Access Selection                     */
/*                                                              */
/* The [stream] parameter is specified as:                      */
/*   0 = OxU3 data stream                                       */
/*   1 = OxU2 data stream #1                                    */
/*   2 = OxU2 data stream #2                                    */
/*   3 = OxU2 data stream #3                                    */
/*   4 = OxU2 data stream #4                                    */
/*                                                              */
/* The [doasel] parameter is specified as:                      */
/*   DOASELx[3:0]                                               */
/*   When DOAUM is set to '0' or '1', this value is ignored.    */
/*   When DOAUM is set to '2' DOASEL=n selects the result of    */
/*   GAF8-n, where n may assume any value from 0 to 7.          */
/*   When DOAUM1 is set to '3' DOASEL1 has the following        */
/*   meaning:                                                   */
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
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  switch (stream) {
    case 0 :
    {
      TEN_OHPP_SFU_DOACFG0_t tmp_sfu_doacfg0;
      tmp_sfu_doacfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG0));
      tmp_sfu_doacfg0.bf.DOASEL0 = doasel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG0), tmp_sfu_doacfg0.wrd);
      break;
    }
    case 1 :
    {
      TEN_OHPP_SFU_DOACFG1_t tmp_sfu_doacfg1;
      tmp_sfu_doacfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG1));
      tmp_sfu_doacfg1.bf.DOASEL1 = doasel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG1), tmp_sfu_doacfg1.wrd);
      break;
    }
    case 2 :
    {
      TEN_OHPP_SFU_DOACFG1_t tmp_sfu_doacfg1;
      tmp_sfu_doacfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG1));
      tmp_sfu_doacfg1.bf.DOASEL2 = doasel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG1), tmp_sfu_doacfg1.wrd);
      break;
    }
    case 3 :
    {
      TEN_OHPP_SFU_DOACFG1_t tmp_sfu_doacfg1;
      tmp_sfu_doacfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG1));
      tmp_sfu_doacfg1.bf.DOASEL3 = doasel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG1), tmp_sfu_doacfg1.wrd);
      break;
    }
    case 4 :
    {
      TEN_OHPP_SFU_DOACFG1_t tmp_sfu_doacfg1;
      tmp_sfu_doacfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG1));
      tmp_sfu_doacfg1.bf.DOASEL4 = doasel;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG1), tmp_sfu_doacfg1.wrd);
      break;
    }
    default :
    {
      ret_val = CS_ERROR;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": stream out of range.  s/b 0..4.");
      break;
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET DOAUP                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_doaup(cs_uint16 module_id, 
                                 cs_uint16 stream, 
                                 cs_uint16 doaup)
/* INPUTS     : o Module Id                                     */
/*              o Stream                                        */
/*              o DOAUP                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Direct Overhead Access Extraction Trigger            */
/*                                                              */
/* The [stream] parameter is specified as:                      */
/*   0 = OxU3 data stream                                       */
/*   1 = OxU2 data stream #1                                    */
/*   2 = OxU2 data stream #2                                    */
/*   3 = OxU2 data stream #3                                    */
/*   4 = OxU2 data stream #4                                    */
/*                                                              */
/* The [doaup] parameter is specified as:                       */
/*   Triggers the extraction of all 64 overhead bytes from the  */
/*   data stream. The data is available after 24 &micro;s. The  */
/*   bit must be cleared by software and set again to cause     */
/*   an additional trigger.                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;
  TEN_OHPP_SFU_DOACFG2_t tmp_sfu_doacfg2;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_doacfg2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG2));
  switch (stream) {
    case 0 :
    {
      tmp_sfu_doacfg2.bf.DOAUP0 = doaup;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG2), tmp_sfu_doacfg2.wrd);
      break;
    }
    case 1 :
    {
      tmp_sfu_doacfg2.bf.DOAUP1 = doaup;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG2), tmp_sfu_doacfg2.wrd);
      break;
    }
    case 2 :
    {
      tmp_sfu_doacfg2.bf.DOAUP2 = doaup;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG2), tmp_sfu_doacfg2.wrd);
      break;
    }
    case 3 :
    {
      tmp_sfu_doacfg2.bf.DOAUP3 = doaup;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG2), tmp_sfu_doacfg2.wrd);
      break;
    }
    case 4 :
    {
      tmp_sfu_doacfg2.bf.DOAUP4 = doaup;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, DOACFG2), tmp_sfu_doacfg2.wrd);
      break;
    }
    default :
    {
      ret_val = CS_ERROR;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": stream out of range.  s/b 0..4.");
      break;
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET GPB CFG                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_gpbcfg(cs_uint16 module_id, 
                                  cs_uint16 instance,
                                  cs_uint16 config,
                                  cs_uint16 g0bval, 
                                  cs_uint16 g0sink)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o Config                                        */
/*              o G0BVAL                                        */
/*              o G0SINK                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the General Purpose Byte Inserter Configuration         */
/* Register.                                                    */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   0 - 9                                                      */
/*                                                              */
/* The [config] parameter is specified as:                      */
/*   1 - 4                                                      */
/*                                                              */
/* The [g0bval] parameter is specified as:                      */
/*   G0BVAL[7:0]                                                */
/*   Byte value for the source bytes to be processed by the GPB */
/*   inserter. This value overwrites the sink byte selected in  */
/*   G0BSELx and G0SINKx.                                       */
/*                                                              */
/* The [g0sink] parameter is specified as:                      */
/*   G0SINK[3:0]                                                */
/*   Selects the overhead generator sink for the source bytes   */
/*   to be processed by the GPB inserter:                       */
/*   0 Select OxU2 Generator #1                                 */
/*   1 Select OxU2 Generator #2                                 */
/*   2 Select OxU2 Generator #3                                 */
/*   3 Select OxU2 Generator #4                                 */
/*   4 Select STS-192 Generator #1                              */
/*   5 Select STS-192 Generator #2                              */
/*   6 Select STS-192 Generator #3                              */
/*   7 Select STS-192 Generator #4                              */
/*   8 Select OxU3 Generator                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_GPB0CFG1_t tmp_sfu_gpb0cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_gpb0cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GPB0CFG1)
                                      + (instance * TEN_OHPP_GPB_INSTANCE_STRIDE)
                                      + ((config - 1) * TEN_OHPP_GPB_REGISTER_STRIDE));
  tmp_sfu_gpb0cfg.bf.G0BVAL1 = g0bval;
  tmp_sfu_gpb0cfg.bf.G0SINK1 = g0sink;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GPB0CFG1)
                                      + (instance * TEN_OHPP_GPB_INSTANCE_STRIDE)
                                      + ((config - 1) * TEN_OHPP_GPB_REGISTER_STRIDE),
                                      tmp_sfu_gpb0cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SFU SET GPB SEL1                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_sfu_set_gpbsel(cs_uint16 module_id, 
                                  cs_uint16 instance,
                                  cs_uint16 config,
                                  cs_uint16 g0bsel)
/* INPUTS     : o Module Id                                     */
/*              o Instance                                      */
/*              o Config                                        */
/*              o G0BSEL1                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the General Purpose Byte Inserter Select Register.      */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   0 - 9                                                      */
/*                                                              */
/* The [config] parameter is specified as:                      */
/*   1 - 4                                                      */
/*                                                              */
/* The [g0bsel1] parameter is specified as:                     */
/*   G0BSEL1[12:0]                                              */
/*   Selects the sink byte for the source bytes to be processed */
/*   by the GPB inserter.                                       */
/*   Note: Values beyond 5795 for an STS-192 or 79 for the OTN  */
/*   target stream selected in G0SINK1 disable insertion        */
/*   altogether (default).                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_OHPP_SFU_GPB0SEL1_t tmp_sfu_gpb0sel;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_gpb0sel.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GPB0SEL1)
                                      + (instance * TEN_OHPP_GPB_INSTANCE_STRIDE)
                                      + ((config - 1) * TEN_OHPP_GPB_REGISTER_STRIDE));
  tmp_sfu_gpb0sel.bf.G0BSEL1 = g0bsel;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GPB0SEL1)
                                      + (instance * TEN_OHPP_GPB_INSTANCE_STRIDE)
                                      + ((config - 1) * TEN_OHPP_GPB_REGISTER_STRIDE),
                                      tmp_sfu_gpb0sel.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SET SFC RAM                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_set_sfc_ram(cs_uint16 module_id,
                               cs_uint8 row, 
                               cs_uint16 *str)
/* INPUTS     : o Module Id                                     */
/*              o Row                                           */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The SFC RAM stores 78 instances of a 1024-bit segment.       */
/* Segment 0 begins at address zero, segment 1 at address 0x40, */
/* etc.                                                         */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0..77                                                      */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* The [*str] parameter is specified as:                        */
/*   A pointer to a 1024-bit segment                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_uint16 *tmp_str = str;
  TEN_OHPP_SFC_RAM_t tmp_sfc_ram;

  if (row > TEN_OHPP_SFC_RAM_UNIT_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77.");
    return(CS_ERROR);
  } 
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  for (ii=0; ii<TEN_OHPP_SFC_RAM_UNIT_SIZE; ii++) {   
    tmp_sfc_ram.bf.str = *tmp_str;
    TEN_REG_WRITE(TEN_OHPP_SFC_REG_ADDR(pDev, module_id, SFC_RAM) + 
                  ii + (row * TEN_OHPP_SFC_RAM_UNIT_SIZE), tmp_sfc_ram.wrd);
    tmp_str++;
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SET SFC RAM BY BIT                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_set_sfc_ram_bit(cs_uint16 module_id,
                                   cs_uint16 row, 
                                   cs_uint16 bit,
                                   cs_uint8  value)
/* INPUTS     : o Module Id                                     */
/*              o Row                                           */
/*              o Bit                                           */
/*              o Value                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The SFC RAM stores 78 instances of a 1024-bit segment.       */
/* Segment 0 begins at address zero, segment 1 at address 0x40, */
/* etc.                                                         */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0..77                                                      */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* The [bit] parameter is specified as:                         */
/*   0..983 for CS600X (T40                                     */
/*   0..1023 for CS604X (T41)                                   */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   0..1                                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_uint32 temp_convert;
  cs_uint32 temp_instance;
  cs_uint16 temp_bit_offset;
  TEN_OHPP_SFC_RAM_t tmp_sfc_ram;
  T41_t *pDev = NULL;

  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77.");
    return(CS_ERROR);
  } 
  
  /* Bugzilla #21917, allow more bits for T41 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    if (bit >= TEN_CONSEQUENT_ACTION_BIT_COUNT_T41) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bit out of range.  s/b 0..1023.");
      return(CS_ERROR);
    }
  } 
  else {
    if (bit >= TEN_CONSEQUENT_ACTION_BIT_COUNT) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bit out of range.  s/b 0..983.");
      return(CS_ERROR);
    } 
  }
  
  /* Bugzilla #30134, remove old T40 check for TEN_CONSEQUENT_ACTION_BIT_COUNT */
  
  if (value > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": value out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);

  temp_convert = (row * 1024) + bit;
  temp_instance = temp_convert / 16;
  temp_bit_offset = temp_convert % 16;

  for (ii=0; ii<TEN_OHPP_SFC_RAM_COUNT; ii++) {
    if (temp_instance == ii) {
      tmp_sfc_ram.wrd = TEN_REG_READ(TEN_OHPP_SFC_REG_ADDR(pDev, module_id, SFC_RAM) +
                                     ii * TEN_OHPP_SFC_RAM_STRIDE);
      if (value == 1) {
        tmp_sfc_ram.bf.str |= (1 << temp_bit_offset);
      }
      else {
        tmp_sfc_ram.bf.str &= ~(1 << temp_bit_offset);
      }
      TEN_REG_WRITE(TEN_OHPP_SFC_REG_ADDR(pDev, module_id, SFC_RAM) +
                                          ii * TEN_OHPP_SFC_RAM_STRIDE, tmp_sfc_ram.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP GET SFC RAM                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_get_sfc_ram(cs_uint16 module_id,
                               cs_uint8 row, 
                               cs_uint16 *str)
/* INPUTS     : o Module Id                                     */
/*              o Row                                           */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The SFC RAM stores 78 instances of a 1024-bit segment.       */
/* Segment 0 begins at address zero, segment 1 at address 0x40, */
/* etc.                                                         */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0..77                                                      */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* The [*str] parameter is specified as:                        */
/*   A pointer to a 1024-bit segment                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_uint16 *tmp_str = str;
  TEN_OHPP_SFC_RAM_t tmp_sfc_ram;

  if (row > TEN_OHPP_SFC_RAM_UNIT_NUM) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77");
    return(CS_ERROR);
  } 
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  for (ii=0; ii<TEN_OHPP_SFC_RAM_UNIT_SIZE; ii++) {   
    tmp_sfc_ram.wrd = TEN_REG_READ(TEN_OHPP_SFC_REG_ADDR(pDev, module_id, SFC_RAM) +
                                   ii + (row * TEN_OHPP_SFC_RAM_UNIT_SIZE));
    *tmp_str = tmp_sfc_ram.bf.str;
    tmp_str++;
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP GET SFC RAM BY BIT                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_ohpp_get_sfc_ram_bit(cs_uint16 module_id,
                                  cs_uint16 row, 
                                  cs_uint16 bit)
/* INPUTS     : o Module Id                                     */
/*              o Row                                           */
/*              o Bit                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0, 1, or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The SFC RAM stores 78 instances of a 1024-bit segment.       */
/* Segment 0 begins at address zero, segment 1 at address 0x40, */
/* etc.                                                         */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0..77                                                      */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* The [bit] parameter is specified as:                         */
/*   0..983                                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_uint32 temp_convert;
  cs_uint32 temp_instance;
  cs_uint16 temp_bit_offset;
  T41_t *pDev = NULL;
  cs_int16 ret_val = CS_ERROR;
  TEN_OHPP_SFC_RAM_t tmp_sfc_ram;

  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77.");
    return(CS_ERROR);
  } 
  
  /* Bugzilla #21917, allow more bits for T41 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    if (bit >= TEN_CONSEQUENT_ACTION_BIT_COUNT_T41) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bit out of range.  s/b 0..1023.");
      return(CS_ERROR);
    }
  } 
  else {
    if (bit >= TEN_CONSEQUENT_ACTION_BIT_COUNT) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bit out of range.  s/b 0..983.");
      return(CS_ERROR);
    } 
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);

  temp_convert = (row * 1024) + bit;
  temp_instance = temp_convert / 16;
  temp_bit_offset = temp_convert % 16;

  for (ii=0; ii<TEN_OHPP_SFC_RAM_COUNT; ii++) {
    if (temp_instance == ii) {
      tmp_sfc_ram.wrd = TEN_REG_READ(TEN_OHPP_SFC_REG_ADDR(pDev, module_id, SFC_RAM) +
                                     ii * TEN_OHPP_SFC_RAM_STRIDE);
      ret_val = 0x0001 & (tmp_sfc_ram.bf.str >> temp_bit_offset);
      break;
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SET SHADOW SFC RAM                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_set_shadow_sfc_ram(cs_uint16 module_id,
                                      cs_uint16 bank,
                                      cs_uint8 row, 
                                      cs_uint16 *str)
/* INPUTS     : o Module Id                                     */
/*              o Bank                                          */
/*              o Row                                           */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The SFC RAM stores 78 instances of a 1024-bit segment.       */
/* Segment 0 begins at address zero, segment 1 at address 0x40, */
/* etc.                                                         */
/* Note: Bits set in the Shadow SFC RAM do not get written to   */
/* the physical SFC RAM until the API                           */
/* ten_hl_ohpp_commit_shadow_sfc_ram is called.                */
/*                                                              */
/* The [bank] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0..77                                                      */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* The [*str] parameter is specified as:                        */
/*   A pointer to a 1024-bit segment                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_mod_cb_t *ppcb;
  cs_uint16 ii;
  cs_uint32 err_code = 0;
  cs_uint16 *tmp_str = str;

  if (bank > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bank out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77.");
    return(CS_ERROR);
  } 
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }

  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);

  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return(CS_ERROR);
  }  
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  for (ii=0; ii<TEN_OHPP_SFC_RAM_UNIT_SIZE; ii++) {   
    if (bank == 0) {
      ppcb->ten_shadow_sfc_ram_0[(row * TEN_OHPP_SFC_RAM_UNIT_SIZE)+ii] = *tmp_str;
    }
    else {
      ppcb->ten_shadow_sfc_ram_1[(row * TEN_OHPP_SFC_RAM_UNIT_SIZE)+ii] = *tmp_str;
    }
    tmp_str++;
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SET SHADOW SFC RAM BY BIT               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_set_shadow_sfc_ram_bit(cs_uint16 module_id,
                                          cs_uint16 bank,
                                          cs_uint16 row, 
                                          cs_uint16 bit,
                                          cs_uint8  value)
/* INPUTS     : o Module Id                                     */
/*              o Bank                                          */
/*              o Row                                           */
/*              o Bit                                           */
/*              o Value                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The SFC RAM stores 78 instances of a 1024-bit segment.       */
/* Segment 0 begins at address zero, segment 1 at address 0x40, */
/* etc. This API sets the contents of a Shadow RAM for the SFC  */
/* RAM.                                                         */
/* Note: Bits set in the Shadow SFC RAM do not get written to   */
/* the physical SFC RAM until the API                           */
/* ten_hl_ohpp_commit_shadow_sfc_ram is called.                */
/*                                                              */
/* The [bank] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0..77                                                      */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* The [bit] parameter is specified as:                         */
/*   0..983                                                     */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   0..1                                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_mod_cb_t *ppcb;
  cs_uint16 ii;
  cs_uint32 temp_convert;
  cs_uint32 temp_instance;
  cs_uint16 temp_bit_offset;
  cs_uint16 tmp_sfc_ram;
  cs_uint32 err_code = 0;

  if (bank > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bank out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77.");
    return(CS_ERROR);
  } 
  
  /* Bugzilla #21917, allow more bits for T41 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    if (bit >= TEN_CONSEQUENT_ACTION_BIT_COUNT_T41) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bit out of range.  s/b 0..1023.");
      return(CS_ERROR);
    }
  } 
  else {
    if (bit >= TEN_CONSEQUENT_ACTION_BIT_COUNT) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bit out of range.  s/b 0..983.");
      return(CS_ERROR);
    } 
  }
  
  if (value > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": value out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }

  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  
  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return(CS_ERROR);
  } 
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);

  temp_convert = (row * 1024) + bit;
  temp_instance = temp_convert / 16;
  temp_bit_offset = temp_convert % 16;

  for (ii=0; ii<TEN_OHPP_SFC_RAM_COUNT; ii++) {
    if (temp_instance == ii) {

      if (bank == 0) {
        tmp_sfc_ram = ppcb->ten_shadow_sfc_ram_0[ii];
      }
      else {
        tmp_sfc_ram = ppcb->ten_shadow_sfc_ram_1[ii];
      }

      if (value == 1) {
        tmp_sfc_ram |= (1 << temp_bit_offset);
      }
      else {
        tmp_sfc_ram &= ~(1 << temp_bit_offset);
      }

      if (bank == 0) {
        ppcb->ten_shadow_sfc_ram_0[ii] = tmp_sfc_ram;
      }
      else {
        ppcb->ten_shadow_sfc_ram_1[ii] = tmp_sfc_ram;
      }

      break;
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP GET SHADOW SFC RAM                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_get_shadow_sfc_ram(cs_uint16 module_id,
                                      cs_uint16 bank,
                                      cs_uint8 row, 
                                      cs_uint16 *str)
/* INPUTS     : o Module Id                                     */
/*              o Bank                                          */
/*              o Row                                           */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The SFC RAM stores 78 instances of a 1024-bit segment.       */
/* Segment 0 begins at address zero, segment 1 at address 0x40, */
/* etc.                                                         */
/* Note: Bits set in the Shadow SFC RAM do not get written to   */
/* the physical SFC RAM until the API                           */
/* ten_hl_ohpp_commit_shadow_sfc_ram is called.                */
/*                                                              */
/* The [bank] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0..77                                                      */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* The [*str] parameter is specified as:                        */
/*   A pointer to a 1024-bit segment                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_mod_cb_t *ppcb;
  cs_uint16 ii;
  cs_uint32 err_code = 0;
  cs_uint16 *tmp_str = str;

  if (bank > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bank out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77.");
    return(CS_ERROR);
  } 
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }

  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
 
  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return(CS_ERROR);
  } 

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  for (ii=0; ii<TEN_OHPP_SFC_RAM_UNIT_SIZE; ii++) {   
    if (bank == 0) {
      *tmp_str = ppcb->ten_shadow_sfc_ram_0[(row * TEN_OHPP_SFC_RAM_UNIT_SIZE)+ii];
    }
    else {
      *tmp_str = ppcb->ten_shadow_sfc_ram_1[(row * TEN_OHPP_SFC_RAM_UNIT_SIZE)+ii];
    }
    tmp_str++;
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP GET SHADOW SFC RAM BY BIT               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_ohpp_get_shadow_sfc_ram_bit(cs_uint16 module_id,
                                         cs_uint16 bank,
                                         cs_uint16 row, 
                                         cs_uint16 bit)
/* INPUTS     : o Module Id                                     */
/*              o Bank                                          */
/*              o Row                                           */
/*              o Bit                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0, 1, or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The SFC RAM stores 78 instances of a 1024-bit segment.       */
/* Segment 0 begins at address zero, segment 1 at address 0x40, */
/* etc. This API gets the contents of a Shadow RAM for the SFC  */
/* RAM.                                                         */
/* Note: This API only gets the contents of the Shadow SFC RAM, */
/* not the physical SFC RAM.                                    */
/*                                                              */
/* The [bank] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0..77                                                      */
/*   See ten_ohpp_data.h for the 78 enums.                      */
/*                                                              */
/* The [bit] parameter is specified as:                         */
/*   0..983                                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_mod_cb_t *ppcb;
  cs_uint32 err_code = 0;
  cs_int16 ret_val = CS_ERROR;
  cs_uint16 ii;
  cs_uint32 temp_convert;
  cs_uint32 temp_instance;
  cs_uint16 temp_bit_offset;
  cs_uint16 tmp_sfc_ram;

  if (bank > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bank out of range.  s/b 0..1.");
    return (CS_ERROR);
  } 
  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row %d out of range.  s/b 0..77.", row);
    return (CS_ERROR);
  } 
  
  /* Bugzilla #21917, allow more bits for T41 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    if (bit >= TEN_CONSEQUENT_ACTION_BIT_COUNT_T41) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bit out of range.  s/b 0..1023.");
      return (CS_ERROR);
    }
  } 
  else {
    if (bit >= TEN_CONSEQUENT_ACTION_BIT_COUNT) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bit out of range.  s/b 0..983.");
      return(CS_ERROR);
    } 
  }
  
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }

  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  
  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return(CS_ERROR);
  } 
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);

  temp_convert = (row * 1024) + bit;
  temp_instance = temp_convert / 16;
  temp_bit_offset = temp_convert % 16;

  for (ii=0; ii<TEN_OHPP_SFC_RAM_COUNT; ii++) {
    if (temp_instance == ii) {

      if (bank == 0) {
        tmp_sfc_ram = ppcb->ten_shadow_sfc_ram_0[ii];
      }
      else {
        tmp_sfc_ram = ppcb->ten_shadow_sfc_ram_1[ii];
      }

      ret_val = 0x0001 & (tmp_sfc_ram >> temp_bit_offset);

      break;
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP COPY SHADOW SFC RAM TO PHYSICAL SFC RAM */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_copy_shadow_sfc_ram(cs_uint16 module_id,
                                       cs_uint16 bank)
/* INPUTS     : o Module Id                                     */
/*              o Bank                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Copies all of the specified Shadow SFC RAM data structure to */
/* the inactive physical SFC RAM bank.                          */
/* Note: This API is to be either called indirectly by the      */
/* ten_hl_ohpp_commit_shadow_sfc_ram or called directly by code */
/* that is tracking which physical SFC RAM bank is active if    */
/* the Shadow SFC RAM is to be kept correctly synchronized      */
/* with the physical SFC RAM.                                   */
/*                                                              */
/* The [bank] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{

  ten_mod_cb_t *ppcb;
  cs_uint16 ii;
  T41_t *pDev = NULL;

  if (bank > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bank out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  
  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return(CS_ERROR);
  } 
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);

  if (bank == 0) {
    for (ii=0; ii<TEN_OHPP_SFC_RAM_COUNT; ii++) {
      TEN_REG_WRITE(TEN_OHPP_SFC_REG_ADDR(pDev, module_id, SFC_RAM) +
                                          ii * TEN_OHPP_SFC_RAM_STRIDE,
                                          ppcb->ten_shadow_sfc_ram_0[ii]);
    }
    ten_shadow_ram_cb(module_id, bank, ppcb->ten_shadow_sfc_ram_0, 
						          TEN_OHPP_SFC_RAM_COUNT);
  }
  else {
    for (ii=0; ii<TEN_OHPP_SFC_RAM_COUNT; ii++) {
      TEN_REG_WRITE(TEN_OHPP_SFC_REG_ADDR(pDev, module_id, SFC_RAM) +
                                          ii * TEN_OHPP_SFC_RAM_STRIDE,
                                          ppcb->ten_shadow_sfc_ram_1[ii]);
    }
    ten_shadow_ram_cb(module_id, bank, ppcb->ten_shadow_sfc_ram_1, 
						          TEN_OHPP_SFC_RAM_COUNT);
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/* Bugzilla 21101: SFU Config dump enhancements */
/****************************************************************/
/* $rtn_hdr_start  OHPP COMPARE SHADOW SFC RAM TO PHYSICAL RAM  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_ohpp_compare_shadow_sfc_ram(cs_uint16 module_id,
                                         cs_uint16 bank)
/* INPUTS     : o Module Id                                     */
/*              o Bank                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 1, 0, or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Compares  the specified (bank) Shadow SFC RAM data structure */
/* to the inactive physical SFC RAM bank. 1 = compare passed.   */
/*                                                              */
/* The [bank] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{

  ten_mod_cb_t *ppcb;
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_int16 rtn_val = 1;

  if (bank > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bank out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  
  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return(CS_ERROR);
  } 
  
  if (bank == 0) {
    for (ii=0; ii<TEN_OHPP_SFC_RAM_COUNT; ii++) {
      if (TEN_REG_READ(TEN_OHPP_SFC_REG_ADDR(pDev, module_id, SFC_RAM) + ii * TEN_OHPP_SFC_RAM_STRIDE)
          != ppcb->ten_shadow_sfc_ram_0[ii]) {
        rtn_val = 0;
      }
    }
  }
  else {
    for (ii=0; ii<TEN_OHPP_SFC_RAM_COUNT; ii++) {
      if (TEN_REG_READ(TEN_OHPP_SFC_REG_ADDR(pDev, module_id, SFC_RAM) + ii * TEN_OHPP_SFC_RAM_STRIDE)
          != ppcb->ten_shadow_sfc_ram_1[ii]) {
        rtn_val = 0;
      }
    }
  }
  
  return (rtn_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP CLEAR SHADOW SFC RAM                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : OHPP                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_ohpp_clear_shadow_sfc_ram(cs_uint16 module_id,
                                        cs_uint16 bank)
/* INPUTS     : o Module Id                                     */
/*              o Bank                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the entire data structure for the specified Shadow SFC   */
/* RAM bank to zeros.                                           */
/*                                                              */
/* The [bank] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{

  ten_mod_cb_t *ppcb;
  cs_uint16 ii;
  cs_uint32 err_code = 0;

  if (bank > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bank out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }

  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  
  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return(CS_ERROR);
  } 
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);

  for (ii=0; ii<TEN_OHPP_SFC_RAM_COUNT; ii++) {
    if (bank == 0) {
      ppcb->ten_shadow_sfc_ram_0[ii] = 0;
    }
    else {
      ppcb->ten_shadow_sfc_ram_1[ii] = 0;
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SET SFU BEICFG                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_set_sfu_beicfg(cs_uint16 module_id, 
                                  cs_uint16 beisrc, 
                                  cs_uint8  stream)
/* INPUTS     : o Module Id                                         */
/*              o BEISRC                                            */
/*              o Stream                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Specifies the OTN overhead stream to be used for calculating     */
/* BEI for the specified outgoing OxU2 stream, which is             */
/* accomplished by comparing the internally calculated BIP-8        */
/* with all eight BIP-8 values received in PM, TCM and SM.          */
/* Selection of a single source for all eight BEI values is         */
/* supported for each destination stream. BEI insertion into        */
/* the data stream depends on whether insertion of the third        */
/* monitoring byte is enabled. For details, see M3B1MSK in the      */
/* SFU_CFG0 register.                                               */
/*                                                                  */
/* The [beisrc] parameter is specified as:                          */
/*   0..15                                                          */
/*    0 = Select OxU3 Terminator from local path.                   */
/*    1 = Select OxU2 Terminator #1 from local path.                */
/*    2 = Select OxU2 Terminator #2 from local path.                */
/*    3 = Select OxU2 Terminator #3 from local path.                */
/*    4 = Select OxU2 Terminator #4 from local path.                */
/*    5 = Reserved                                                  */
/*    6 = Reserved                                                  */
/*    7 = Reserved                                                  */
/*    8 = Select OxU3 Terminator from other path.                   */
/*    9 = Select OxU2 Terminator #1 from other path.                */
/*   10 = Select OxU2 Terminator #2 from other path.                */
/*   11 = Select OxU2 Terminator #3 from other path.                */
/*   12 = Select OxU2 Terminator #4 from other path.                */
/*   13 = Reserved                                                  */
/*   14 = Reserved                                                  */
/*   15 = Reserved                                                  */
/*                                                                  */
/* The [stream] parameter is specified as:                          */
/*   1 = OxU2 Overhead Stream #1                                    */
/*   2 = OxU2 Overhead Stream #2                                    */
/*   3 = OxU2 Overhead Stream #3                                    */
/*   4 = OxU2 Overhead Stream #4                                    */
/*   5 = OxU3 Overhead Stream                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  switch (stream) {
    case 1:
    {
      TEN_OHPP_SFU_BEICFG0_t tmp_sfu_beicfg0;
      tmp_sfu_beicfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG0));
      tmp_sfu_beicfg0.bf.BEI1SRC = beisrc;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG0), tmp_sfu_beicfg0.wrd);
      break;
    }
    case 2:
    {
      TEN_OHPP_SFU_BEICFG0_t tmp_sfu_beicfg0;
      tmp_sfu_beicfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG0));
      tmp_sfu_beicfg0.bf.BEI2SRC = beisrc;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG0), tmp_sfu_beicfg0.wrd);
      break;
    }
    case 3:
    {
      TEN_OHPP_SFU_BEICFG0_t tmp_sfu_beicfg0;
      tmp_sfu_beicfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG0));
      tmp_sfu_beicfg0.bf.BEI3SRC = beisrc;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG0), tmp_sfu_beicfg0.wrd);
      break;
    }
    case 4:
    {
      TEN_OHPP_SFU_BEICFG0_t tmp_sfu_beicfg0;
      tmp_sfu_beicfg0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG0));
      tmp_sfu_beicfg0.bf.BEI4SRC = beisrc;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG0), tmp_sfu_beicfg0.wrd);
      break;
    }
    case 5:
    {
      TEN_OHPP_SFU_BEICFG1_t tmp_sfu_beicfg1;
      tmp_sfu_beicfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG1));
      tmp_sfu_beicfg1.bf.BEI5SRC = beisrc;
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG1), tmp_sfu_beicfg1.wrd);
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
/* $rtn_hdr_start  OHPP SFU BEICFG1 BEPSEL                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_beicfg1_bipsel(cs_uint16 module_id, 
                                      cs_uint16 bipsel)
/* INPUTS     : o Module Id                                         */
/*              o BIPSEL                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Backward Error Indication Forwarding Unit Configuration.         */
/* Selects the BEI calculation method performed on the received     */
/* BIP-8 Bytes of the Monitoring OH (SM, TCM, PM) and the OTN       */
/* Rx Stream Byte 3.                                                */
/*                                                                  */
/*   [bipsel]                                                       */
/*    0 = OxU3 Terminator from local path                           */
/*    1 = OxU2 Terminator #1 from local path                        */
/*    2 = OxU2 Terminator #2 from local path                        */
/*    3 = OxU2 Terminator #3 from local path                        */
/*    4 = OxU2 Terminator #4 from local path                        */
/*    5 = OxU3 Terminator from other path                           */
/*    6 = OxU2 Terminator #1 from other path                        */
/*    7 = OxU2 Terminator #2 from other path                        */
/*    8 = OxU2 Terminator #3 from other path                        */
/*    9 = OxU2 Terminator #4 from other path.                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_OHPP_SFU_BEICFG1_t tmp_sfu_beicfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  if (bipsel > 9) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": stream out of range.");
    return (CS_ERROR);
  } 
  
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_beicfg1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG1));
  tmp_sfu_beicfg1.bf.BIPSEL = bipsel;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEICFG1), tmp_sfu_beicfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU BEIOVRD                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_beiovrd(cs_uint16 module_id, 
                               cs_uint16 stream, 
                               cs_uint16 beiovrden)
/* INPUTS     : o Module Id                                         */
/*              o Stream                                            */
/*              o BEIOVRDEN                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets BEI Defect Override Enables.                                */
/*                                                                  */
/* [stream] parameter is specified as:                              */
/*   0 = OxU3 Overhead Stream                                       */
/*   1 = OxU2 Overhead Stream #1                                    */
/*   2 = OxU2 Overhead Stream #2                                    */
/*   3 = OxU2 Overhead Stream #3                                    */
/*   4 = OxU2 Overhead Stream #4                                    */
/*                                                                  */
/* [beiovrden]                                                      */
/*   BEIOVRDEN0 for OxU3 enables the respective BEI receive value   */
/*   to be overridden with a fixed value of b'1011' whenever a      */
/*   dIAE defect is active. If the respective dIAE is inactive,     */
/*   the BEI value is not overridden. The BEI value will not be     */
/*   overridden if BEIOVRDEN0[] = 0. This function occurs before    */
/*   the BEI mask is applied in the the CFG0 and CFG1 registers.    */
/*   bit 1: TCM1 BEI overriden if TCM1 dIAE active                  */
/*   bit 2: TCM2 BEI overriden if TCM2 dIAE active                  */
/*   bit 3: TCM3 BEI overriden if TCM3 dIAE active                  */
/*   bit 4: TCM4 BEI overriden if TCM4 dIAE active                  */
/*   bit 5: TCM5 BEI overriden if TCM5 dIAE active                  */
/*   bit 6: TCM6 BEI overriden if TCM6 dIAE active                  */
/*   bit 7: SM BEI overriden if SM dIAE active.                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_OHPP_SFU_BEIOVRD0_t tmp_sfu_beiovrd0;
  TEN_OHPP_SFU_BEIOVRD1_t tmp_sfu_beiovrd1;
  TEN_OHPP_SFU_BEIOVRD2_t tmp_sfu_beiovrd2;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  
  switch (stream) {
  case (0):
    tmp_sfu_beiovrd0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEIOVRD0));
    tmp_sfu_beiovrd0.bf.BEIOVRDEN0 = beiovrden;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEIOVRD0), tmp_sfu_beiovrd0.wrd);
    break;
  
  case (1):
    tmp_sfu_beiovrd0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEIOVRD0));
    tmp_sfu_beiovrd0.bf.BEIOVRDEN1 = beiovrden;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEIOVRD0), tmp_sfu_beiovrd0.wrd);
    break;
  
  case (2):
    tmp_sfu_beiovrd1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEIOVRD1));
    tmp_sfu_beiovrd1.bf.BEIOVRDEN2 = beiovrden;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEIOVRD1), tmp_sfu_beiovrd1.wrd);
    break;
  
  case (3):
    tmp_sfu_beiovrd1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEIOVRD1));
    tmp_sfu_beiovrd1.bf.BEIOVRDEN3 = beiovrden;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEIOVRD1), tmp_sfu_beiovrd1.wrd);
    break;
  
  case (4):
    tmp_sfu_beiovrd2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEIOVRD2));
    tmp_sfu_beiovrd2.bf.BEIOVRDEN4 = beiovrden;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, BEIOVRD2), tmp_sfu_beiovrd2.wrd);
    break;
    
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": stream out of range.");
    rtn = CS_ERROR;
    break;
  }  
    
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU SWITCH BANK                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_switch_bank(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Switch SFU Bank.                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 bank;
  
  bank = ten_ohpp_sfu_get_state(module_id, 1) ^ 1;
  CS_PRINT("Switching to SFU: module_id =%d, bank =%d\n", module_id, bank);
  rtn = ten_ohpp_sfu_set_sfcmsel(module_id, bank);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU GSFU CFG                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_gsfu_cfg(cs_uint16 module_id, 
                                cs_uint16 unit, 
                                cs_uint16 gs_dst, 
                                cs_uint16 gs_path, 
                                cs_uint16 gs_src)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o GS DST                                            */
/*              o GS PATH                                           */
/*              o GS SRC                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the General Forwarding Unit Configuration Register.   */
/*                                                                  */
/*   [unit]  (T41)  1..13 = General Forwarding Unit Selection       */
/*           (T40)  1..8  = General Forwarding Unit Selection       */
/*                                                                  */
/*   [gs_dst]  Selects the generator for the first General          */
/*     Purpose Forwarding Unit:                                     */
/*     0 = OxU2 Generator #1                                        */
/*     1 = OxU2 Generator #2                                        */
/*     2 = OxU2 Generator #3                                        */
/*     3 = OxU2 Generator #4                                        */
/*     4 = STS-192 Generator #1                                     */
/*     5 = STS-192 Generator #2                                     */
/*     6 = STS-192 Generator #3                                     */
/*     7 = STS-192 Generator #4                                     */
/*     8 = OxU3 Generator                                           */
/*                                                                  */
/*   [gs_path]  Selects the terminator for the first General        */
/*     Purpose Forwarding Unit:                                     */
/*     0 = Selects the local ('this') path (default).               */
/*     1 = Selects the terminator from the other (second) path      */
/*                                                                  */
/*   [gs_src]  Selects the terminator for the first General         */
/*     Purpose Signal Forwarding Unit.                              */
/*     0 = OxU2 Terminator #1                                       */
/*     1 = OxU2 Terminator #2                                       */
/*     2 = OxU2 Terminator #3                                       */
/*     3 = OxU2 Terminator #4                                       */
/*     4 = STS-192 Terminator #1                                    */
/*     5 = STS-192 Terminator #2                                    */
/*     6 = STS-192 Terminator #3                                    */
/*     7 = STS-192 Terminator #4                                    */
/*     8 = OxU3 Terminator.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_OHPP_SFU_GSFU1CFG_t tmp_sfu_gsfu1cfg;
  TEN_OHPP_SFU_GSFU9CFG_t tmp_sfu_gsfu9cfg;
  T41_t *pDev = NULL;
 
  /* Bugzilla #27206, allow range 1..13 for T41 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    if ((!unit) || (unit > 13)) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..13.");
      return (CS_ERROR);
    }
  }
  else {
    if ((!unit) || (unit > 8)) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..8.");
      return (CS_ERROR);
    }
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  
  if (unit < 9) {
    tmp_sfu_gsfu1cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU1CFG)+(unit-1)*3);
    tmp_sfu_gsfu1cfg.bf.GS1DST = gs_dst;
    tmp_sfu_gsfu1cfg.bf.GS1PATH = gs_path;
    tmp_sfu_gsfu1cfg.bf.GS1SRC = gs_src;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU1CFG)+(unit-1)*3, tmp_sfu_gsfu1cfg.wrd);
  }
  else {
    tmp_sfu_gsfu9cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU9CFG)+(unit-9)*3);
    tmp_sfu_gsfu9cfg.bf.GS9DST = gs_dst;
    tmp_sfu_gsfu9cfg.bf.GS9PATH = gs_path;
    tmp_sfu_gsfu9cfg.bf.GS9SRC = gs_src;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU9CFG)+(unit-9)*3, tmp_sfu_gsfu9cfg.wrd);
  }
                
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU GSFU SBS                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_gsfu_sbs(cs_uint16 module_id, 
                                cs_uint16 unit, 
                                cs_uint16 gs_sbs)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o GS SBS                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Source Byte Selector for the specified General Purpose      */
/* Signal Forwarding Unit.                                          */
/*                                                                  */
/*   [unit]  (T41)  1..13 = General Forwarding Unit Selection       */
/*           (T40)  1..8  = General Forwarding Unit Selection       */
/*                                                                  */
/*   [gs_sbs]  Note: The General Purpose Forwarding Unit may convey */
/*     invalid information if this value is greater than 5795 for   */
/*     an STS-192 stream or greater than 79 for an OTN stream,      */
/*     as selected in GS_SRC.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_OHPP_SFU_GSFU1SBS_t tmp_sfu_gsfu1sbs;
  TEN_OHPP_SFU_GSFU9SBS_t tmp_sfu_gsfu9sbs;

  T41_t *pDev = NULL;

  /* Bugzilla #27206, allow range 1..13 for T41 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    if ((!unit) || (unit > 13)) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..13.");
      return (CS_ERROR);
    }
  }
  else {
    if ((!unit) || (unit > 8)) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..8.");
      return (CS_ERROR);
    }
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  
  if (unit < 9) {
    tmp_sfu_gsfu1sbs.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU1SBS)+(unit-1)*3);
    tmp_sfu_gsfu1sbs.bf.GS1SBS = gs_sbs;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU1SBS)+(unit-1)*3, tmp_sfu_gsfu1sbs.wrd);
  }
  else {
    tmp_sfu_gsfu9sbs.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU9SBS)+(unit-9)*3);
    tmp_sfu_gsfu9sbs.bf.GS9SBS = gs_sbs;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU9SBS)+(unit-9)*3, tmp_sfu_gsfu9sbs.wrd);
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU GSFU DBS                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_gsfu_dbs(cs_uint16 module_id, 
                                cs_uint16 unit, 
                                cs_uint16 gs_dbs)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o GS DBS                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Destination Byte Selector for the specified General     */
/* Purpose Signal Forwarding Unit.                                  */
/*                                                                  */
/*   [unit]  (T41)  1..13 = General Forwarding Unit Selection       */
/*           (T40)  1..8  = General Forwarding Unit Selection       */
/*                                                                  */
/*   [gs_dbs]  Note: The GSS unit does not insert any byte if this  */
/*     value is greater than 5795 for an STS-192 stream or greater  */
/*     than 79 for an OTN stream, as selected in GS_DST.  To        */
/*     disable insertion, the value must be out of range (default). */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_OHPP_SFU_GSFU1DBS_t tmp_sfu_gsfu1dbs;
  TEN_OHPP_SFU_GSFU9DBS_t tmp_sfu_gsfu9dbs;

  T41_t *pDev = NULL;
  
  /* Bugzilla #27206, allow range 1..13 for T41 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    if ((!unit) || (unit > 13)) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..13.");
      return (CS_ERROR);
    }
  }
  else {
    if ((!unit) || (unit > 8)) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..8.");
      return (CS_ERROR);
    }
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  
  if (unit < 9) {
    tmp_sfu_gsfu1dbs.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU1DBS)+(unit-1)*3);
    tmp_sfu_gsfu1dbs.bf.GS1DBS = gs_dbs;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU1DBS)+(unit-1)*3, tmp_sfu_gsfu1dbs.wrd);
  }
  else {
    tmp_sfu_gsfu9dbs.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU9DBS)+(unit-9)*3);
    tmp_sfu_gsfu9dbs.bf.GS9DBS = gs_dbs;
    TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, GSFU9DBS)+(unit-9)*3, tmp_sfu_gsfu9dbs.wrd);
  }    
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CA DISABLE0                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_ca_disable0(cs_uint16 module_id, 
                                   cs_uint16 odis)
/* INPUTS     : o Module Id                                         */
/*              o ODIS                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Consequent Action Disable Register.                         */
/*                                                                  */
/*   [odis]                                                         */
/*   This vector disables the Consequent Action bits SEG16-SEG1.    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CA_DISABLE0_t tmp_sfu_ca_disable0;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ca_disable0.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CA_DISABLE0));
  tmp_sfu_ca_disable0.bf.ODIS = odis;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CA_DISABLE0), tmp_sfu_ca_disable0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CA DISABLE1                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_ca_disable1(cs_uint16 module_id, 
                                   cs_uint16 odis)
/* INPUTS     : o Module Id                                         */
/*              o ODIS                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Consequent Action Disable Register.                         */
/*                                                                  */
/*   [odis]                                                         */
/*   This vector disables the Consequent Action bits SEG32-SEG17.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CA_DISABLE1_t tmp_sfu_ca_disable1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ca_disable1.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CA_DISABLE1));
  tmp_sfu_ca_disable1.bf.ODIS = odis;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CA_DISABLE1), tmp_sfu_ca_disable1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CA DISABLE2                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_ca_disable2(cs_uint16 module_id, 
                                   cs_uint16 odis)
/* INPUTS     : o Module Id                                         */
/*              o ODIS                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Consequent Action Disable Register.                         */
/*                                                                  */
/*   [odis]                                                         */
/*    This vector disables the Consequent Action bits SEG48-SEG33.  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CA_DISABLE2_t tmp_sfu_ca_disable2;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ca_disable2.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CA_DISABLE2));
  tmp_sfu_ca_disable2.bf.ODIS = odis;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CA_DISABLE2), tmp_sfu_ca_disable2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CA DISABLE3                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_ca_disable3(cs_uint16 module_id, 
                                   cs_uint16 odis)
/* INPUTS     : o Module Id                                         */
/*              o ODIS                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Consequent Action Disable Register.                         */
/*                                                                  */
/*   [odis]                                                         */
/*   This vector disables the Consequent Action bits SEG64-SEG49.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CA_DISABLE3_t tmp_sfu_ca_disable3;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ca_disable3.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CA_DISABLE3));
  tmp_sfu_ca_disable3.bf.ODIS = odis;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CA_DISABLE3), tmp_sfu_ca_disable3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  OHPP SFU CA DISABLE4                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : OHPP                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_ohpp_sfu_ca_disable4(cs_uint16 module_id, 
                                   cs_uint16 odis)
/* INPUTS     : o Module Id                                         */
/*              o ODIS                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Consequent Action Disable Register.                         */
/*                                                                  */
/*   [odis]                                                         */
/*   This vector disables the Consequent Action bits SEG78-SEG65.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_OHPP_SFU_CA_DISABLE4_t tmp_sfu_ca_disable4;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_OHPP);
  tmp_sfu_ca_disable4.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CA_DISABLE4));
  tmp_sfu_ca_disable4.bf.ODIS = odis;
  TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CA_DISABLE4), tmp_sfu_ca_disable4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_OHPP);

  return (CS_OK);
}




