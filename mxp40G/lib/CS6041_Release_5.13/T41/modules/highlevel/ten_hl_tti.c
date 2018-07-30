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
 * ten_hl_tti.c
 *
 * API's for TTI String Extractor/Inserter functions.
 *
 * $Id: ten_hl_tti.c,v 1.12 2014/04/03 20:17:57 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

/* row, col values from G.709 */
const cs_uint16 ten_tti_parms[8][3] =
{
  /*                               row  col  unit  */
  /* TEN_OOHR_SECTION_LAYER */   {   0,   7,   1},
  /* TEN_OOHR_PATH_LAYER    */   {   2,   9,   2}, 
  /* TEN_OOHR_TCM1_LAYER    */   {   2,   6,   3},
  /* TEN_OOHR_TCM2_LAYER    */   {   2,   3,   4},
  /* TEN_OOHR_TCM3_LAYER    */   {   2,   0,   5},
  /* TEN_OOHR_TCM4_LAYER    */   {   1,  10,   6},
  /* TEN_OOHR_TCM5_LAYER    */   {   1,   7,   7},
  /* TEN_OOHR_TCM6_LAYER    */   {   1,   4,   8}
};
 
/* Bugzilla #20892, return CS_OK/CS_ERROR for TTI/PSI functions */

/****************************************************************/
/* $rtn_hdr_start  SET 40G INSERTED TTI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_40g_inserted_tti_unit(cs_uint16 module_id, 
                             cs_uint16 layer, 
                             cs_uint16 unit, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Layer                                         */
/*              o Unit                                          */
/*              o TTI String Size                               */
/*              o TTI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets TTI for the specified layer.                            */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [str] pointer to a 64 byte TTI string buffer.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii, row, col = 0;
  cs_char8 tmp_tti_str[TEN_MAX_TTI_SIZE];

  if ((layer < 1) || (layer > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Layer out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  if ((unit < 1) || (unit > 24)) {
    if (unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }
  
  if ( (!tti_str_size) || (tti_str_size > TEN_MAX_TTI_SIZE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  TTI parm out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  /* Bugzilla #34969, remove delays from TTI APIs */

  for (ii=0; ii<tti_str_size; ii++) {
    tmp_tti_str[ii] = tti_str[ii];
  }
  
  for (ii=tti_str_size; ii<TEN_MAX_TTI_SIZE; ii++) {
    tmp_tti_str[ii] = 0;
  }
  
  row = ten_tti_parms[layer-1][0];
  col = ten_tti_parms[layer-1][1];
  if (unit == 0xFF) {
    unit = ten_tti_parms[layer-1][2];
  }  

  /* Configure the string inserter for specified layer */
  /* String inserter MFM: 
    — ‘000’ selects the programmable OTNT_MFMINT:MFM4 “MFAS event”,
    — ‘001’ selects the programmable OTNT_MFMINT:MFM5 “MFAS event”,
    — ...............................
    — ‘111’ selects the programmable OTNT_MFMINT:MFM11 “MFAS event” */
  
  rtn |= ten_n40g_oohr_config_string_inserter(module_id, 
                            /* unit,  */ unit,
                            /* sicnt, */ tti_str_size - 1,
                            /* simfe, */ 3, /* MFM7 */
                            /* sicol, */ col,
                            /* sirow  */ row);
                            
  /* Set up match unit */
  rtn |= ten_n40g_otnt4x_mfmcfg(module_id, 
                              /* match unit */   7,
                              /* mfmcmp     */   0, 
                              /* mfmmsk     */   0x3F);

  /* Write the inserted TTI string to OTNSM RAM */    
  rtn |= ten_n40g_otnsm_set_string_inserter(module_id, unit, tmp_tti_str);

  /* Enable String Inserter Unit */
  rtn |= ten_n40g_oohr_set_string_inserter_ie(module_id, unit, 1);

  /* Toggle the double buffer to make string available for insertion */
  rtn |= ten_n40g_oohr_string_insertion_update(module_id, unit);

RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SET 40G INSERTED TTI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_40g_inserted_tti(cs_uint16 module_id, 
                             cs_uint16 layer, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Layer                                         */
/*              o TTI String Size                               */
/*              o TTI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets TTI for the specified layer.                            */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [str] pointer to a 64 byte TTI string buffer.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_set_40g_inserted_tti_unit(module_id, 
                                           layer, 
                                           0xFF,  /* use recommended unit */
                                           tti_str_size, 
                                           tti_str));
}

/* bugzilla #20378, add tti function to only configure, not read */
/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 40G ACCEPTED TTI UNIT              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_configure_40g_accepted_tti_unit(cs_uint16 module_id, 
                             cs_uint16 layer, 
                             cs_uint16 unit, 
                             cs_uint16 tti_str_size)
/* INPUTS     : o Module Id                                     */
/*              o Layer                                         */
/*              o Unit                                          */
/*              o TTI String Size                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the ability to accept TTI for the specified       */
/* layer.                                                       */
/*                                                              */
/* The accepted TTI and the expected TTI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 row, col = 0;

  if ((layer < 1) || (layer > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  if ((unit < 1) || (unit > 24)) {
    if (unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }
  
  if ( (!tti_str_size) || (tti_str_size > TEN_MAX_TTI_SIZE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }

  /* Bugzilla #34969, remove delays from TTI APIs */

  /* G.709, page 29 for row/col values */
  row = ten_tti_parms[layer-1][0];
  col = ten_tti_parms[layer-1][1];
  
  if (unit == 0xFF) {
    unit = ten_tti_parms[layer-1][2];
  }  
  
  rtn |= ten_n40g_oohr_set_string_extractor_off(module_id, unit, 1);

  /* set dTIM Mode off */
  rtn |= ten_n40g_oohr_set_string_extractor_dmm(module_id, unit, 0);

  /* String Extractor MFM:   
  — ‘000’ selects the programmable OOHR_MFMINT:MFM9 “MFAS event”,
  — ‘001’ selects the programmable OOHR_MFMINT:MFM10 “MFAS event”,
  — ...............................
  — ‘111’ selects the programmable OOHR_MFMINT:MFM16 “MFAS event” */
  
  /* Configure the string extractor for specified layer */                         
  rtn |= ten_n40g_oohr_config_string_extractor(module_id, 
                              /* unit,   */ unit,
                              /* se_mfe, */ 4, /* MFM 13 */
                              /* se_cnt, */ tti_str_size - 1,
                              /* se_col, */ col,
                              /* se_row, */ row, 
                              /* se_cmp, */ 0x0F);
  
  rtn |= ten_n40g_oohr_mfmcfg(module_id, 
                              /* match unit */   13,
                              /* mfmcmp     */   0, 
                              /* mfmmsk     */   0x3F);

  rtn |= ten_n40g_oohr_set_string_extractor_off(module_id, unit, 0);
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  GET 40G ACCEPTED TTI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_get_40g_accepted_tti_unit(cs_uint16 module_id, 
                             cs_uint16 layer, 
                             cs_uint16 unit, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Layer                                         */
/*              o Unit                                          */
/*              o TTI String Size                               */
/*              o TTI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Gets the accepted TTI for the specified layer.               */
/*                                                              */
/* The accepted TTI and the expected TTI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [str] pointer to a 64 byte TTI string buffer.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii;
  cs_char8 tmp_tti_str[TEN_MAX_TTI_SIZE];

  if ((layer < 1) || (layer > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  if ((unit < 1) || (unit > 24)) {
    if (unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }
  
  if ( (!tti_str_size) || (tti_str_size > TEN_MAX_TTI_SIZE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }

  /* Bugzilla #34969, remove delays from TTI APIs */
  
  if (unit == 0xFF) {
    unit = ten_tti_parms[layer-1][2];
  }  
  
  /* Bugzilla #34969, remove delays from TTI APIs */
  for (ii=0; ii<10;ii++) {
    if ((unit >= TEN_NX0G_OOHR_STATUS_SE1ST) && (unit <= TEN_NX0G_OOHR_STATUS_SE16ST)) {
      if (ten_n40g_oohr_get_string_extractor_unit_status0(module_id, unit)) {
        break;
      }
    }
    else {
      if (ten_n40g_oohr_get_string_extractor_unit_status1(module_id, unit)) {
        break;
      }
    }
    TEN_MDELAY(5);
  }
  if (ii == 10) {
    CS_PRINT("WARNING:  N40G string extractor not stable."); 
  }

  /* Get the accepted string */    
  rtn |= ten_n40g_otnsm_get_string_extractor(module_id, unit, tmp_tti_str);

  for (ii=0; ii<tti_str_size; ii++) {
    tti_str[ii] = tmp_tti_str[ii];
  }
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  GET 40G ACCEPTED TTI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_get_40g_accepted_tti(cs_uint16 module_id, 
                             cs_uint16 layer, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Layer                                         */
/*              o TTI String Size                               */
/*              o TTI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Gets the accepted TTI for the specified layer.               */
/*                                                              */
/* The accepted TTI and the expected TTI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [str] pointer to a 64 byte TTI string buffer.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_get_40g_accepted_tti_unit(module_id, 
                                      layer, 
                                      0xFF,  /* use recommended unit */
                                      tti_str_size, 
                                      tti_str));
}

/****************************************************************/
/* $rtn_hdr_start  PRINT 40G ACCEPTED TTI UNIT                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_print_40g_accepted_tti_unit(cs_uint16 module_id, 
                                        cs_uint16 layer,
                                        cs_uint16 unit,
                                        cs_uint16 tti_str_size)
/* INPUTS     : o Module Id                                     */
/*              o Layer                                         */
/*              o String Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the accepted TTI for the specified layer.             */
/* The accepted TTI and the expected TTI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_char8 tmp_tti_str[TEN_MAX_TTI_SIZE];

  rtn = ten_hl_get_40g_accepted_tti_unit(module_id, layer, unit, tti_str_size, tmp_tti_str);
  
  /* Bugzilla #42300 - Fix klocwork warnings */
  if (tti_str_size > 64) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of range.  s/b 1..64.");
    return(CS_ERROR);
  }
  
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_tti_str, tti_str_size);
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PRINT 40G ACCEPTED TTI                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_print_40g_accepted_tti(cs_uint16 module_id, 
                                        cs_uint16 layer,
                                        cs_uint16 tti_str_size)
/* INPUTS     : o Module Id                                     */
/*              o Layer                                         */
/*              o String Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the accepted TTI for the specified layer.             */
/* The accepted TTI and the expected TTI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_print_40g_accepted_tti_unit(module_id, 
                                             layer,
                                             0xFF,  /* use recommended unit */
                                             tti_str_size));
}                                        

/****************************************************************/
/* $rtn_hdr_start  SET 40G EXPECTED TTI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_40g_expected_tti_unit(cs_uint16 module_id, 
                                      cs_uint16 layer, 
                                      cs_uint16 unit,
                                      cs_uint16 tti_cmp, 
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str)

/* INPUTS     : o Module Id                                     */
/*              o Layer                                         */
/*              o Unit                                          */
/*              o TTI Compare Selection Mask                    */
/*              o TTI Expected String                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the expected TTI for the specified layer.               */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_cmp] TTI Cmp selection Mask.                          */
/*    Select 16 byte cmp (0x0 - 0xF)                            */
/*    SAPI (TTI bytes 0 to 15),                                 */
/*    DAPI (TTI bytes 16 to 31), and/or                         */
/*    Operator Specific (TTI bytes 32 to 63)                    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [str] pointer to a 64 byte TTI string buffer.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii, row, col = 0;
  cs_char8 tmp_tti_str[TEN_MAX_TTI_SIZE];

  if (tti_cmp > 0xF) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;
    goto RTN_EXIT;
  }
 
  if ((layer < 1) || (layer > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  if ((unit < 1) || (unit > 24)) {
    if (unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }
  
  if ( (!tti_str_size) || (tti_str_size > TEN_MAX_TTI_SIZE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }

  /* Bugzilla #34969, remove delays from TTI APIs */
  
  for (ii=0; ii<tti_str_size; ii++) {
    tmp_tti_str[ii] = tti_str[ii];
  }
  
  for (ii=tti_str_size; ii<TEN_MAX_TTI_SIZE; ii++) {
    tmp_tti_str[ii] = 0;
  }
  /* G.709, page 29 for row/col values */
  row = ten_tti_parms[layer-1][0];
  col = ten_tti_parms[layer-1][1];
  if (unit == 0xFF) {
    unit = ten_tti_parms[layer-1][2];
  }   
  
  /* “on-the-fly” modification of the expected string value           */
  /* Set SEnOFF (n=1…24) at value “1”, in order to allow software     */
  /* to re-program a new expected string value into the OTNSM_RAM.    */
  rtn |= ten_n40g_oohr_set_string_extractor_off(module_id, unit, 1);

  /* set dTIM Mode off */
  rtn |= ten_n40g_oohr_set_string_extractor_dmm(module_id, unit, 0);

  /* String Extractor MFM:   
  — ‘000’ selects the programmable OOHR_MFMINT:MFM9 “MFAS event”,
  — ‘001’ selects the programmable OOHR_MFMINT:MFM10 “MFAS event”,
  — ...............................
  — ‘111’ selects the programmable OOHR_MFMINT:MFM16 “MFAS event” */
  
  /* dTIM mode */
  rtn |= ten_n40g_oohr_config_string_extractor(module_id, 
                              /* unit,   */ unit,
                              /* se_mfe, */ 4, /* MFM13 */
                              /* se_cnt, */ 0x3F,
                              /* se_col, */ col,
                              /* se_row, */ row, 
                              /* se_cmp, */ tti_cmp);
                              
  /* Set the extracted string to the expected string for DTIM mode */  
  rtn |= ten_n40g_otnsm_set_string_extractor(module_id, unit, tmp_tti_str);

  rtn |= ten_n40g_oohr_mfmcfg(module_id, 
                              /* match unit */   13,
                              /* mfmcmp     */   0, 
                              /* mfmmsk     */   0x3F);

  rtn |= ten_n40g_oohr_set_string_extractor_dmm(module_id, unit, 1);
  
  rtn |= ten_n40g_oohr_set_string_extractor_off(module_id, unit, 0);
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SET 40G EXPECTED TTI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_40g_expected_tti(cs_uint16 module_id, 
                                      cs_uint16 layer, 
                                      cs_uint16 tti_cmp, 
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str)

/* INPUTS     : o Module Id                                     */
/*              o Layer                                         */
/*              o TTI Compare Selection Mask                    */
/*              o TTI Expected String                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the expected TTI for the specified layer.               */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*   [tti_cmp] TTI Cmp selection Mask.                          */
/*    Select 16 byte cmp (0x0 - 0xF)                            */
/*    SAPI (TTI bytes 0 to 15),                                 */
/*    DAPI (TTI bytes 16 to 31), and/or                         */
/*    Operator Specific (TTI bytes 32 to 63)                    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [str] pointer to a 64 byte TTI string buffer.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_set_40g_expected_tti_unit(module_id, 
                                      layer, 
                                      0xFF,  /* use recommended unit */
                                      tti_cmp, 
                                      tti_str_size,
                                      tti_str));
}

/****************************************************************/
/* $rtn_hdr_start  SET 40G STRING HYSTERESIS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_40g_string_hysteresis(cs_uint16 module_id, 
                                        cs_uint8 sesiv, 
                                        cs_uint8 sestv, 
                                        cs_uint8 seuiv,  
                                        cs_uint8 seutv)
/* INPUTS     : o Module Id                                     */
/*              o Stable Intermitted Threshold                  */
/*              o Stable Threshold                              */
/*              o Unstable Intermitted Theshold                 */
/*              o Unstable Threshold                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the 40G String hysteresis.                              */
/*                                                              */
/*   [sesiv]  String Extraction Stable Intermitted              */
/*            Threshold Value                                   */
/*                                                              */
/*   [seuiv]  String Extraction Stable Threshold Value.         */
/*                                                              */
/*   [seutv]  String Extraction Unstable Intermitted            */
/*            Threshold Value                                   */
/*                                                              */
/*   [sestv]  String Extraction Unstable Threshold Value.       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;

  rtn |= ten_n40g_set_oohr_cfg6(module_id, sesiv, sestv);
  if (rtn != CS_OK) goto RTN_EXIT;
  
  rtn |= ten_n40g_set_oohr_cfg7(module_id, seuiv, seutv);
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SET 10G INSERTED TTI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_10g_inserted_tti_unit(cs_uint16 module_id,
                                           cs_uint8 slice, 
                                           cs_uint16 layer, 
                                           cs_uint16 unit,
                                           cs_uint16 tti_str_size, 
                                           cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o TTI String Size                               */
/*              o TTI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets TTI for the specified layer.                            */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [str] pointer to a 64 byte TTI string buffer.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii, row, col;
  cs_char8 tmp_tti_str[TEN_MAX_TTI_SIZE];
  ten_mod_cb_t *ppcb;
  cs_uint8 sl;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    goto RTN_EXIT;
  }
  
  if ((layer < 1) || (layer > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  if ((unit < 1) || (unit > 24)) {
    if (unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }
  
  if ( (!tti_str_size) || (tti_str_size > TEN_MAX_TTI_SIZE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  
  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return (CS_ERROR);
  } 
  
  /* Bugzilla #34969, remove delays from TTI APIs */
  
  for (ii=0; ii<tti_str_size; ii++) {
    tmp_tti_str[ii] = tti_str[ii];
  }

  for (ii=tti_str_size; ii<TEN_MAX_TTI_SIZE; ii++) {
    tmp_tti_str[ii] = 0;
  }
  
  /* Bugzilla #33514  */
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      for (ii=0; ii<tti_str_size; ii++) {
        ppcb->inserted_tti_10g[sl][layer-1][ii] = tti_str[ii];
      }
    } 
  }
  
  row = ten_tti_parms[layer-1][0];
  col = ten_tti_parms[layer-1][1];
  if (unit == 0xFF) {
    unit = ten_tti_parms[layer-1][2];
  }  
  
  /* Configure the string inserter for specified layer */
  /* String inserter MFM: 
    — ‘000’ selects the programmable OTNT_MFMINT:MFM4 “MFAS event”,
    — ‘001’ selects the programmable OTNT_MFMINT:MFM5 “MFAS event”,
    — ...............................
    — ‘111’ selects the programmable OTNT_MFMINT:MFM11 “MFAS event” */
  /* Configure the string inserter for specified layer */                         
  
  rtn |= ten_n10g_oohr_config_string_inserter(module_id,
                               slice,
                            /* unit,  */ unit,
                            /* sicnt, */ tti_str_size - 1,
                            /* simfe, */ 3, /* MFM7 */
                            /* sicol, */ col,
                            /* sirow  */ row);
                            
  /* Set up match unit */
  rtn |= ten_n10g_otnt_mfmcfg(module_id,
                       slice,
                       /* match unit */   7,
                       /* mfmcmp     */   0, 
                       /* mfmmsk     */   0x3F);

  /* Write the inserted TTI string to OTNSM RAM */    
  rtn |= ten_n10g_otnsm_set_string_inserter(module_id, slice, unit, tmp_tti_str);

  /* Enable String Inserter Unit */
  rtn |= ten_n10g_oohr_set_string_inserter_ie(module_id, slice, unit, 1);

  /* Toggle the double buffer to make string available for insertion */
  rtn |= ten_n10g_oohr_string_insertion_update(module_id, slice, unit);

RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PRINT 10G INSERTED TTI                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_print_10g_inserted_tti(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 layer,
                                        cs_uint16 tti_str_size)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o Size                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the inserted TTI for the specified layer.             */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64).              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_char8 tmp_tti_str[TEN_MAX_TTI_SIZE];
  cs_status rtn;
  
  rtn = ten_hl_get_10g_inserted_tti(module_id, slice, layer,
                                    tti_str_size, tmp_tti_str);
  
  /* Bugzilla #42300 - Fix klocwork warnings */
  if (tti_str_size > 64) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of range.  s/b 1..64.");
    return(CS_ERROR);
  }
  
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_tti_str, tti_str_size);
  }
  else {
    CS_PRINT("ten_hl_print_10g_inserted_tti was unsuccessful.\n");
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  GET 10G INSERTED TTI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_get_10g_inserted_tti(cs_uint16 module_id, 
                                      cs_uint8 slice, 
                                      cs_uint16 layer,
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o Size                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Gets the inserted TTI for the specified layer.               */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [tti_str] pointer to a 64 byte TTI string buffer.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  ten_mod_cb_t *ppcb;
  cs_uint16 ii;
  
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  if ((layer < 1) || (layer > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Parameter out of range.");
    return (CS_ERROR);
  }
  
  if ( (!tti_str_size) || (tti_str_size > TEN_MAX_TTI_SIZE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    return (CS_ERROR);
  }
  
  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  
  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return (CS_ERROR);
  } 
  
  for (ii=0; ii<tti_str_size; ii++) {
    tti_str[ii] = ppcb->inserted_tti_10g[slice][layer-1][ii];
  }  

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SET 10G INSERTED TTI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_10g_inserted_tti(cs_uint16 module_id,
                             cs_uint8 slice, 
                             cs_uint16 layer, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o TTI String Size                               */
/*              o TTI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets TTI for the specified layer.                            */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [str] pointer to a 64 byte TTI string buffer.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_set_10g_inserted_tti_unit(module_id,
                                      slice, 
                                      layer, 
                                      0xFF,  /* use recommended unit */
                                      tti_str_size, 
                                      tti_str));
}

/* bugzilla #20378, add tti function to only configure, not read */
/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 10G ACCEPTED TTI UNIT              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_configure_10g_accepted_tti_unit(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint16 layer, 
                             cs_uint16 unit,
                             cs_uint16 tti_str_size) 
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o TTI String Size                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the ability to accept TTI for the specified       */
/* layer.                                                       */
/*                                                              */
/* The accepted TTI and the expected TTI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 row, col;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    goto RTN_EXIT;
  }

  if ((layer < 1) || (layer > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  if ((unit < 1) || (unit > 24)) {
    if (unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }
  
  if ( (!tti_str_size) || (tti_str_size > TEN_MAX_TTI_SIZE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }  
  
  /* Bugzilla #34969, remove delays from TTI APIs */
  
  /* G.709, page 29 for row/col values */
  row = ten_tti_parms[layer-1][0];
  col = ten_tti_parms[layer-1][1];
  /* Bugzilla #36441 - Accepted TTI string issue with API ten_hl_configure_10g_accepted_tti_uni */
  if (unit == 0xFF) {
    unit = ten_tti_parms[layer-1][2];
  }
  
  rtn |= ten_n10g_oohr_set_string_extractor_off(module_id, slice, unit, 1);

  /* set dTIM Mode off */
  rtn |= ten_n10g_oohr_set_string_extractor_dmm(module_id, slice, unit, 0);

  /* String Extractor MFM:   
  — ‘000’ selects the programmable OOHR_MFMINT:MFM9 “MFAS event”,
  — ‘001’ selects the programmable OOHR_MFMINT:MFM10 “MFAS event”,
  — ...............................
  — ‘111’ selects the programmable OOHR_MFMINT:MFM16 “MFAS event” */
  
  /* Configure the string inserter for specified layer */
  rtn |= ten_n10g_oohr_config_string_extractor(module_id,
                                 slice,
                              /* unit,   */ unit,
                              /* se_mfe, */ 4, /* MFM13 */
                              /* se_cnt, */ tti_str_size - 1,
                              /* se_col, */ col,
                              /* se_row, */ row, 
                              /* se_cmp, */ 0x0F);
  
  rtn |= ten_n10g_oohr_mfmcfg(module_id, 
                                 slice,  
                              /* match unit */   13,
                              /* mfmcmp     */   0, 
                              /* mfmmsk     */   0x3F);

  rtn |= ten_n10g_oohr_set_string_extractor_off(module_id, slice, unit, 0);
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  GET 10G ACCEPTED TTI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_get_10g_accepted_tti_unit(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint16 layer, 
                             cs_uint16 unit,
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o TTI String Size                               */
/*              o TTI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Gets the accepted TTI for the specified layer.               */
/* The accepted TTI and the expected TTI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [str] pointer to a 64 byte TTI string buffer.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii;
  cs_char8 tmp_tti_str[TEN_MAX_TTI_SIZE];

  /* Bugzilla #33948, only one slice can be returned at a time */
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    goto RTN_EXIT;
  }

  if ((layer < 1) || (layer > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  if ((unit < 1) || (unit > 24)) {
    if (unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }
  
  if ( (!tti_str_size) || (tti_str_size > TEN_MAX_TTI_SIZE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }  
  
  /* Bugzilla #34969, remove delays from TTI APIs */
  
  /* Bugzilla #24737, use unit passed in if not 0xFF */
  if(unit == 0xFF){
    unit = ten_tti_parms[layer-1][2];
  }
  
  /* Bugzilla #34969, remove delays from TTI APIs */
  for (ii=0; ii<10;ii++) {
    if ((unit >= TEN_NX0G_OOHR_STATUS_SE1ST) && (unit <= TEN_NX0G_OOHR_STATUS_SE16ST)) {
      if (ten_n10g_oohr_get_string_extractor_unit_status0(module_id, slice, unit)) {
        break;
      }
    }
    else {
      if (ten_n10g_oohr_get_string_extractor_unit_status1(module_id, slice, unit)) {
        break;
      }
    }
    TEN_MDELAY(5);
  }
  if (ii == 10) {
    CS_PRINT("WARNING:  N10G string extractor not stable.\n"); 
  }

  /* Get the accepted string */    
  rtn |= ten_n10g_otnsm_get_string_extractor(module_id, slice, unit, tmp_tti_str);
 
  for (ii=0; ii<tti_str_size; ii++) {
    tti_str[ii] = tmp_tti_str[ii];
  }
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  GET 10G ACCEPTED TTI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_get_10g_accepted_tti(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint16 layer, 
                             cs_uint16 tti_str_size, 
                             cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o TTI String Size                               */
/*              o TTI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Gets the accepted TTI for the specified layer.               */
/* The accepted TTI and the expected TTI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [str] pointer to a 64 byte TTI string buffer.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_get_10g_accepted_tti_unit(module_id, 
                                           slice, 
                                           layer, 
                                           0xFF,
                                           tti_str_size, 
                                           tti_str));
}

/****************************************************************/
/* $rtn_hdr_start  PRINT 10G ACCEPTED TTI UNIT                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_print_10g_accepted_tti_unit(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 layer,
                                        cs_uint16 unit,
                                        cs_uint16 tti_str_size)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o String Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the accepted TTI for the specified layer.             */
/* The accepted TTI and the expected TTI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64).              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_char8 tmp_tti_str[TEN_MAX_TTI_SIZE];
  /* Bugzilla #24737, use unit parameter */
  rtn = ten_hl_get_10g_accepted_tti_unit(module_id, slice, layer, unit, tti_str_size, tmp_tti_str);
  
  /* Bugzilla #42300 - Fix klocwork warnings */
  if (tti_str_size > 64) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of range.  s/b 1..64.");
    return(CS_ERROR);
  }
  
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_tti_str, tti_str_size);
  }  

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PRINT 10G ACCEPTED TTI                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_print_10g_accepted_tti(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 layer,
                                        cs_uint16 tti_str_size)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o String Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the accepted TTI for the specified layer.             */
/* The accepted TTI and the expected TTI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64).              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_print_10g_accepted_tti_unit(module_id, 
                                             slice, 
                                             layer,
                                             0xFF, 
                                             tti_str_size));
}

/****************************************************************/
/* $rtn_hdr_start  SET 10G EXPECTED TTI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_10g_expected_tti_unit(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 layer, 
                                      cs_uint16 unit, 
                                      cs_uint16 tti_cmp, 
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o Unit                                          */
/*              o TTI Compare Selection Mask                    */
/*              o TTI String Size                               */
/*              o TTI Expected String                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the expected TTI for the specified layer.               */

/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [unit]  Unit to be used 1..24, or 0xFF for recommended.    */
/*                                                              */
/*   [tti_cmp] TTI Cmp selection Mask.                          */
/*    Select 16 byte cmp (0x0 - 0xF)                            */
/*    SAPI (TTI bytes 0 to 15),                                 */
/*    DAPI (TTI bytes 16 to 31), and/or                         */
/*    Operator Specific (TTI bytes 32 to 63)                    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [tti_str] pointer to a 64 byte TTI string buffer.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii, row, col;
  cs_char8 tmp_tti_str[TEN_MAX_TTI_SIZE];
  ten_mod_cb_t *ppcb;
  cs_uint8 sl;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    goto RTN_EXIT;
  }

  if (tti_cmp > 0xF) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;
    goto RTN_EXIT;
  }
 
  if ((layer < 1) || (layer > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  if ((unit < 1) || (unit > 24)) {
    if (unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }
  
  if ( (!tti_str_size) || (tti_str_size > TEN_MAX_TTI_SIZE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;  
    goto RTN_EXIT;
  }
  
  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  
  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return (CS_ERROR);
  } 
  
  /* Bugzilla #34969, remove delays from TTI APIs */
  
  for (ii=0; ii<tti_str_size; ii++) {
    tmp_tti_str[ii] = tti_str[ii];
  }
  
  for (ii=tti_str_size; ii<TEN_MAX_TTI_SIZE; ii++) {
    tmp_tti_str[ii] = 0;
  }
  
  /* Bugzilla #33514  */
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      for (ii=0; ii<tti_str_size; ii++) {
        ppcb->expected_tti_10g[sl][layer-1][ii] = tti_str[ii];
      }
    } 
  }
  
  /* G.709, page 29 for row/col values */
  row = ten_tti_parms[layer-1][0];
  col = ten_tti_parms[layer-1][1];
  if (unit == 0xFF) {
    unit = ten_tti_parms[layer-1][2];
  }   
  
  /* “on-the-fly” modification of the expected string value           */
  /* Set SEnOFF (n=1…24) at value “1”, in order to allow software     */
  /* to re-program a new expected string value into the OTNSM_RAM.    */
  rtn |= ten_n10g_oohr_set_string_extractor_off(module_id, slice, unit, 1);

  /* set dTIM Mode off */
  rtn |= ten_n10g_oohr_set_string_extractor_dmm(module_id, slice, unit, 0);

  /* String Extractor MFM:   
  — ‘000’ selects the programmable OOHR_MFMINT:MFM9 “MFAS event”,
  — ‘001’ selects the programmable OOHR_MFMINT:MFM10 “MFAS event”,
  — ...............................
  — ‘111’ selects the programmable OOHR_MFMINT:MFM16 “MFAS event” */
  
  /* dTIM mode */
  rtn |= ten_n10g_oohr_config_string_extractor(module_id, slice,  
                              /* unit,   */ unit,
                              /* se_mfe, */ 4, /* MFM13 */
                              /* se_cnt, */ 0x3F,
                              /* se_col, */ col,
                              /* se_row, */ row, 
                              /* se_cmp, */ tti_cmp);
                              
  /* Set the extracted string to the expected string for DTIM mode */  
  rtn |= ten_n10g_otnsm_set_string_extractor(module_id, slice, unit, tmp_tti_str);

  rtn |= ten_n10g_oohr_mfmcfg(module_id, slice,  
                              /* match unit */   13,
                              /* mfmcmp     */   0, 
                              /* mfmmsk     */   0x3F);

  rtn |= ten_n10g_oohr_set_string_extractor_dmm(module_id, slice, unit, 1);
  
  rtn |= ten_n10g_oohr_set_string_extractor_off(module_id, slice, unit, 0);
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PRINT 10G EXPECTED TTI                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_print_10g_expected_tti(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 layer,
                                        cs_uint16 tti_str_size)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o Size                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the expected TTI for the specified layer.             */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64).              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_char8 tmp_tti_str[TEN_MAX_TTI_SIZE];
  cs_status rtn;
  
  rtn = ten_hl_get_10g_expected_tti(module_id, slice, layer,
                                    tti_str_size, tmp_tti_str);
  
  
  /* Bugzilla #42300 - Fix klocwork warnings */
  if (tti_str_size > 64) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of range.  s/b 1..64.");
    return(CS_ERROR);
  }
  
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_tti_str, tti_str_size);
  }
  else {
    CS_PRINT("ten_hl_print_10g_expected_tti was unsuccessful.\n");
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  GET 10G EXPECTED TTI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_get_10g_expected_tti(cs_uint16 module_id, 
                                      cs_uint8 slice, 
                                      cs_uint16 layer,
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o Size                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Gets the expected TTI for the specified layer.               */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [tti_str] pointer to a 64 byte TTI string buffer.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  ten_mod_cb_t *ppcb;
  cs_uint16 ii;
  
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  if ((layer < 1) || (layer > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Parameter out of range.");
    return (CS_ERROR);
  }
  
  if ( (!tti_str_size) || (tti_str_size > TEN_MAX_TTI_SIZE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    return (CS_ERROR);
  }
  
  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  
  if (!ppcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.\n");
    return (CS_ERROR);
  } 
  
  for (ii=0; ii<tti_str_size; ii++) {
    tti_str[ii] = ppcb->expected_tti_10g[slice][layer-1][ii];
  }  

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SET 10G EXPECTED TTI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_10g_expected_tti(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 layer, 
                                      cs_uint16 tti_cmp, 
                                      cs_uint16 tti_str_size,
                                      cs_char8 *tti_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Layer                                         */
/*              o TTI Compare Selection Mask                    */
/*              o TTI String Size                               */
/*              o TTI Expected String                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the expected TTI for the specified layer.               */

/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [layer]  Layer Selection                                   */
/*      TEN_OOHR_SECTION_LAYER = 1                              */
/*      TEN_OOHR_PATH_LAYER = 2                                 */
/*      TEN_OOHR_TCM1_LAYER = 3                                 */
/*      TEN_OOHR_TCM2_LAYER = 4                                 */
/*      TEN_OOHR_TCM3_LAYER = 5                                 */
/*      TEN_OOHR_TCM4_LAYER = 6                                 */
/*      TEN_OOHR_TCM5_LAYER = 7                                 */
/*      TEN_OOHR_TCM6_LAYER = 8                                 */
/*                                                              */
/*   [tti_cmp] TTI Cmp selection Mask.                          */
/*    Select 16 byte cmp (0x0 - 0xF)                            */
/*    SAPI (TTI bytes 0 to 15),                                 */
/*    DAPI (TTI bytes 16 to 31), and/or                         */
/*    Operator Specific (TTI bytes 32 to 63)                    */
/*                                                              */
/*   [tti_str_size] TTI string byte count (1..64)               */
/*                                                              */
/*   [tti_str] pointer to a 64 byte TTI string buffer.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_set_10g_expected_tti_unit(module_id,
                                           slice, 
                                           layer, 
                                           0xFF,  /* use recommended unit */
                                           tti_cmp, 
                                           tti_str_size,
                                           tti_str));
}

/****************************************************************/
/* $rtn_hdr_start  SET 10G STRING HYSTERESIS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_10g_string_hysteresis(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint8 sesiv, 
                                        cs_uint8 sestv, 
                                        cs_uint8 seuiv,  
                                        cs_uint8 seutv)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Stable Intermitted Threshold                  */
/*              o Stable Threshold                              */
/*              o Unstable Intermitted Theshold                 */
/*              o Unstable Threshold                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the 10G String hysteresis.                              */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [sesiv]  String Extraction Stable Intermitted              */
/*            Threshold Value                                   */
/*                                                              */
/*   [seuiv]  String Extraction Stable Threshold Value.         */
/*                                                              */
/*   [seutv]  String Extraction Unstable Intermitted            */
/*            Threshold Value                                   */
/*                                                              */
/*   [sestv]  String Extraction Unstable Threshold Value.       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    goto RTN_EXIT;
  }

  rtn |= ten_n10g_set_oohr_cfg6(module_id, slice, sesiv, sestv);
  if (rtn != CS_OK) {
    goto RTN_EXIT;
  }
  
  rtn |= ten_n10g_set_oohr_cfg7(module_id, slice, seuiv, seutv);
  
RTN_EXIT:
  return (rtn);
}


