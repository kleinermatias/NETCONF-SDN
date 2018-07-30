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
 * ten_hl_psi.c
 *
 * API's for PSI String Extractor/Inserter functions.
 *
 * $Id: ten_hl_psi.c,v 1.7 2014/04/03 20:17:26 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

#define TEN_PSI_MAX_SIZE 256

/* Bugzilla #20892, return CS_OK/CS_ERROR for TTI/PSI functions */

#ifndef TEN_NO_N40G
/****************************************************************/
/* $rtn_hdr_start  SET 40G INSERTED PSI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_40g_inserted_psi_unit(cs_uint16 module_id, 
                             cs_uint16 starting_unit,
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o Starting Unit                                 */
/*              o PSI String Size                               */
/*              o PSI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets PSI for the specified layer.                            */
/*                                                              */
/*   [starting_unit]  Starting Unit to be used 1..21,           */
/*           or 0xFF for recommended.  Four Units beginning     */
/*           at "Starting Unit" are used.                       */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [str] pointer to a 256 byte PSI string buffer.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii, row, col, unit, jj;
  cs_char8 tmp_psi_str[TEN_PSI_MAX_SIZE];
  cs_uint16 sicnt, tmp_psi_str_size;

  if (!psi_str) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, " : psi str is a null ptr.");
    goto RTN_EXIT;
  }

  if ( (psi_str_size < 2) || (psi_str_size > TEN_PSI_MAX_SIZE)) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, " : psi size out of range.");
    goto RTN_EXIT;
  }
  
  if ((starting_unit < 1) || (starting_unit > 21)) {
    if (starting_unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Starting Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }

  /* Bugzilla #34969, remove delays from PSI APIs */

  for (ii=0; ii<psi_str_size; ii++) {
    tmp_psi_str[ii] = psi_str[ii];
  }
  
  for (ii=psi_str_size; ii<TEN_PSI_MAX_SIZE; ii++) {
    tmp_psi_str[ii] = 0;
  }
  
  if (starting_unit == 0xFF) {
    starting_unit = 16;
  }  
  
  /* From G.709, PSI is located at row 4, column 15 */
  row = 3;
  col = 14;
  tmp_psi_str_size = psi_str_size;
  
  /* Configure the string inserter for specified layer */
  /* String inserter MFM: 
    — ‘000’ selects the programmable OTNT_MFMINT:MFM4 “MFAS event”,
    — ‘001’ selects the programmable OTNT_MFMINT:MFM5 “MFAS event”,
    — ...............................
    — ‘111’ selects the programmable OTNT_MFMINT:MFM11 “MFAS event” */
  
  /* Units 16-19 are recommended for 256 Byte PSI */ 
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    if (tmp_psi_str_size > 64) {
      sicnt = 63;
      tmp_psi_str_size -= 64;
    }
    else {
      sicnt = tmp_psi_str_size-1;
      tmp_psi_str_size = 0;
    }
      
    rtn |= ten_n40g_oohr_config_string_inserter(module_id, 
                            /* unit,  */ unit,
                            /* sicnt, */ sicnt,
                            /* simfe, */ 4 + (unit - starting_unit), /* OTNT_MFM8..11 */
                            /* sicol, */ col,
                            /* sirow  */ row);
  }

  /* Set up match unit */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n40g_otnt4x_mfmcfg(module_id,
                            /* match unit */   8 + (unit - starting_unit),  /* OTNT_MFM8..11 */
                            /* mfmcmp     */   (unit - starting_unit) * 64, /* 0, 64, 128, 192 */
                            /* mfmmsk     */   0xFF);
  }

  /* Write the inserted PSI string to OTNSM RAM */    
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    jj = 64*(unit-starting_unit);
    if (jj < TEN_PSI_MAX_SIZE) {
      rtn |= ten_n40g_otnsm_set_string_inserter(module_id, unit, &tmp_psi_str[jj]);
    }
  }
  
  /* Enable String Inserter Unit */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n40g_oohr_set_string_inserter_ie(module_id, unit, 1);
  }
  
  /* Toggle the double buffer to make string available for insertion */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n40g_oohr_string_insertion_update(module_id, unit);
  }
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SET 40G INSERTED PSI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_40g_inserted_psi(cs_uint16 module_id, 
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o PSI String Size                               */
/*              o PSI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets PSI for the specified layer.                            */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [str] pointer to a 256 byte PSI string buffer.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_set_40g_inserted_psi_unit(module_id, 
                                           0xFF,  /* use recommended unit */
                                           psi_str_size, 
                                           psi_str));
}

/****************************************************************/
/* $rtn_hdr_start  GET 40G ACCEPTED PSI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_get_40g_accepted_psi_unit(cs_uint16 module_id, 
                             cs_uint16 starting_unit,
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o Starting Unit                                 */
/*              o PSI String Size                               */
/*              o PSI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Gets the accepted PSI.                                       */
/*                                                              */
/* The accepted PSI and the expected PSI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/*                                                              */
/*   [starting_unit]  Starting Unit to be used 1..21,           */
/*           or 0xFF for recommended.  Four Units beginning     */
/*           at "Starting Unit" are used.                       */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [str] pointer to a 256 byte PSI string buffer.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii, jj;
  cs_char8 tmp_psi_str[TEN_PSI_MAX_SIZE];
  cs_uint16 row, col, unit = 0;

  if (!psi_str) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, " : psi str is a null ptr.");
    goto RTN_EXIT;
  }

  if ( (psi_str_size < 2) || (psi_str_size > TEN_PSI_MAX_SIZE)) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, " : psi size out of range.");
    goto RTN_EXIT;
  }
  
  if ((starting_unit < 1) || (starting_unit > 21)) {
    if (starting_unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Starting Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }

  /* Bugzilla #34969, remove delays from PSI APIs */
  
  /* ‘000’ selects the programmable OOHR_MFMINT:MFM9 “MFAS event”,
     ‘001’ selects the programmable OOHR_MFMINT:MFM10 “MFAS event”,
     ...............................
     ‘111’ selects the programmable OOHR_MFMINT:MFM16 “MFAS event” */
  
  if (starting_unit == 0xFF) {
    starting_unit = 16;
  }  
  
  /* From G.709, PSI is located at row 4, column 15 */
  row = 3;
  col = 14;

  /* Units 16-19 are recommended for 256 Byte PSI */ 
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n40g_oohr_set_string_extractor_off(module_id, unit, 1);
  }  

  /* set dTIM Mode off */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n40g_oohr_set_string_extractor_dmm(module_id, unit, 0);  
  }

  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    /* Configure the string extractor for specified layer */                         
    rtn |= ten_n40g_oohr_config_string_extractor(module_id, 
                                /* unit,   */ unit,
                                /* se_mfe, */ unit - starting_unit,  /* OOHR_MFM9..12 */
                                /* se_cnt, */ 63,
                                /* se_col, */ col,
                                /* se_row, */ row, 
                                /* se_cmp, */ 0x0F);
  
    rtn |= ten_n40g_oohr_mfmcfg(module_id, 
                                /* match unit */   9 + (unit - starting_unit),  /* OOHR_MFM9..12 */
                                /* mfmcmp     */   (unit - starting_unit) * 64, /* 0, 64, 128, 192 */
                                /* mfmmsk     */   0xFF);

  }
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n40g_oohr_set_string_extractor_off(module_id, unit, 0);
  }  
  
  /* Bugzilla #34969, remove delays from PSI APIs */
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
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    /* Bugzilla #24439, klocwork */
    if ((unit - starting_unit) == 0) {
      jj = 0;
    }
    else if ((unit - starting_unit) == 1) {
      jj = 64;
    }
    else if ((unit - starting_unit) == 2) {
      jj = 128;
    }
    else {
      jj = 192;
    }
    rtn |= ten_n40g_otnsm_get_string_extractor(module_id, unit, &tmp_psi_str[jj]);
  }
  
  for (ii=0; ii<psi_str_size; ii++) {
    psi_str[ii] = tmp_psi_str[ii];
  }
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  GET 40G ACCEPTED PSI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_get_40g_accepted_psi(cs_uint16 module_id, 
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o PSI String Size                               */
/*              o PSI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Gets the accepted PSI.                                       */
/*                                                              */
/* The accepted PSI and the expected PSI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [str] pointer to a 256 byte PSI string buffer.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_get_40g_accepted_psi_unit(module_id, 
                                           0xFF,  /* use recommended unit */
                                           psi_str_size, 
                                           psi_str));
}

/****************************************************************/
/* $rtn_hdr_start  PRINT 40G ACCEPTED PSI UNIT                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_print_40g_accepted_psi_unit(cs_uint16 module_id, 
                                        cs_uint16 starting_unit,
                                        cs_uint16 psi_str_size)
/* INPUTS     : o Module Id                                     */
/*              o Starting Unit                                 */
/*              o String Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the accepted PSI.                                     */
/* The accepted PSI and the expected PSI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/*   [starting_unit]  Starting Unit to be used 1..21,           */
/*           or 0xFF for recommended.  Four Units beginning     */
/*           at "Starting Unit" are used.                       */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256).             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_char8 tmp_psi_str[TEN_PSI_MAX_SIZE];

  rtn = ten_hl_get_40g_accepted_psi_unit(module_id, starting_unit, 
                                         psi_str_size, tmp_psi_str);
  
  /* Bugzilla #42300 - Fix klocwork warnings */
  if (psi_str_size > 256) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of range.  s/b 1..256.");
    return(CS_ERROR);
  }
                                         
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_psi_str, psi_str_size);
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PRINT 40G ACCEPTED PSI                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_print_40g_accepted_psi(cs_uint16 module_id, 
                                        cs_uint16 psi_str_size)
/* INPUTS     : o Module Id                                     */
/*              o String Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the accepted PSI.                                     */
/* The accepted PSI and the expected PSI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256).             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_print_40g_accepted_psi_unit(module_id, 
                                        0xFF,  /* use recommended unit */
                                        psi_str_size));
}

/****************************************************************/
/* $rtn_hdr_start  SET 40G EXPECTED PSI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_40g_expected_psi_unit(cs_uint16 module_id, 
                                      cs_uint16 starting_unit,
                                      cs_uint16 psi_cmp, 
                                      cs_uint16 psi_str_size,
                                      cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o Starting Unit                                 */
/*              o PSI Compare Selection Mask                    */
/*              o PSI Expected String                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the expected PSI for the specified layer.               */
/*                                                              */
/*   [starting_unit]  Starting Unit to be used 1..21,           */
/*           or 0xFF for recommended.  Four Units beginning     */
/*           at "Starting Unit" are used.                       */
/*                                                              */
/*   [psi_cmp] PSI Cmp selection Mask.                          */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [psi_str] pointer to a 256 byte PSI string buffer.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii, jj, row, col, unit = 0;
  cs_char8 tmp_psi_str[TEN_PSI_MAX_SIZE];
  cs_uint16 tmp_psi_str_size, secnt;

  if (psi_cmp > 0xF) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;
    goto RTN_EXIT;
  }
 
  if (!psi_str) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, " : psi str is a null ptr.");
    goto RTN_EXIT;
  }

  if ( (psi_str_size < 2) || (psi_str_size > TEN_PSI_MAX_SIZE)) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, " : psi size out of range.");
    goto RTN_EXIT;
  }
  
  if ((starting_unit < 1) || (starting_unit > 21)) {
    if (starting_unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Starting Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }
  
  /* Bugzilla #34969, remove delays from PSI APIs */
  
  for (ii=0; ii<psi_str_size; ii++) {
    tmp_psi_str[ii] = psi_str[ii];
  }
  
  for (ii=psi_str_size; ii<TEN_PSI_MAX_SIZE; ii++) {
    tmp_psi_str[ii] = 0;
  }
  
  if (starting_unit == 0xFF) {
    starting_unit = 16;
  }  
  
  /* From G.709, PSI is located at row 4, column 15 */
  row = 3;
  col = 14;

  /* “on-the-fly” modification of the expected string value           */
  /* Set SEnOFF (n=1…24) at value “1”, in order to allow software     */
  /* to re-program a new expected string value into the OTNSM_RAM.    */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n40g_oohr_set_string_extractor_off(module_id, unit, 1);
  }  

  /* set dTIM Mode off */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n40g_oohr_set_string_extractor_dmm(module_id, unit, 0);
  }  

  /* String Extractor MFM:   
  — ‘000’ selects the programmable OOHR_MFMINT:MFM9 “MFAS event”,
  — ‘001’ selects the programmable OOHR_MFMINT:MFM10 “MFAS event”,
  — ...............................
  — ‘111’ selects the programmable OOHR_MFMINT:MFM16 “MFAS event” */

  tmp_psi_str_size = psi_str_size;
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
   if (tmp_psi_str_size > 64) {
      secnt = 63;
      tmp_psi_str_size -= 64;
    }
    else {
      secnt = tmp_psi_str_size-1;
      tmp_psi_str_size = 0;
    }
  
    /* dTIM mode */
    rtn |= ten_n40g_oohr_config_string_extractor(module_id, 
                              /* unit,   */ unit,
                              /* se_mfe, */ unit - starting_unit, /* OOHR_MFM9..12 */
                              /* se_cnt, */ secnt,
                              /* se_col, */ col,
                              /* se_row, */ row, 
                              /* se_cmp, */ psi_cmp);

    rtn |= ten_n40g_oohr_mfmcfg(module_id, 
                              /* match unit */   9 + (unit - starting_unit),   /* OOHR_MFM9..12 */
                              /* mfmcmp     */   (unit - starting_unit) * 64,  /* 0, 64, 128, 192 */
                              /* mfmmsk     */   0xFF);

  }
                              
  /* Set the extracted string to the expected string for DTIM mode */  
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {

    /* Bugzilla #24439, klocwork */
    if ((unit - starting_unit) == 0) {
      jj = 0;
    }
    else if ((unit - starting_unit) == 1) {
      jj = 64;
    }
    else if ((unit - starting_unit) == 2) {
      jj = 128;
    }
    else {
      jj = 192;
    }
    rtn |= ten_n40g_otnsm_set_string_extractor(module_id, unit, &tmp_psi_str[jj]);
  }

  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n40g_oohr_set_string_extractor_dmm(module_id, unit, 1);
  }  
  
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n40g_oohr_set_string_extractor_off(module_id, unit, 0);
  }  
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SET 40G EXPECTED PSI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_40g_expected_psi(cs_uint16 module_id, 
                                      cs_uint16 psi_cmp, 
                                      cs_uint16 psi_str_size,
                                      cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o PSI Compare Selection Mask                    */
/*              o PSI Expected String                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the expected PSI for the specified layer.               */
/*                                                              */
/*   [psi_cmp] PSI Cmp selection Mask.                          */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [psi_str] pointer to a 256 byte PSI string buffer.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_set_40g_expected_psi_unit(module_id, 
                                           0xFF,  /* use recommended unit */
                                           psi_cmp, 
                                           psi_str_size,
                                           psi_str));
}
#endif

/****************************************************************/
/* $rtn_hdr_start  SET 10G INSERTED PSI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_10g_inserted_psi_unit(cs_uint16 module_id,
                             cs_uint8 slice, 
                             cs_uint16 starting_unit,
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Starting Unit                                 */
/*              o PSI String Size                               */
/*              o PSI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets PSI for the specified layer.                            */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [starting_unit]  Starting Unit to be used 1..21,           */
/*           or 0xFF for recommended.  Four Units beginning     */
/*           at "Starting Unit" are used.                       */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [str] pointer to a 256 byte PSI string buffer.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii, jj, row, col, unit = 0;
  cs_char8 tmp_psi_str[TEN_PSI_MAX_SIZE];
  cs_uint16 sicnt, tmp_psi_str_size;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    goto RTN_EXIT;
  }
  
  if (!psi_str) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, " : psi str is a null ptr.");
    goto RTN_EXIT;
  }

  if ( (psi_str_size < 2) || (psi_str_size > TEN_PSI_MAX_SIZE)) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, " : psi size out of range.");
    goto RTN_EXIT;
  }
  
  if ((starting_unit < 1) || (starting_unit > 21)) {
    if (starting_unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Starting Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }

  /* Bugzilla #34969, remove delays from PSI APIs */
  
  for (ii=0; ii<psi_str_size; ii++) {
    tmp_psi_str[ii] = psi_str[ii];
  }
  
  for (ii=psi_str_size; ii<TEN_PSI_MAX_SIZE; ii++) {
    tmp_psi_str[ii] = 0;
  }
  
  if (starting_unit == 0xFF) {
    starting_unit = 16;
  }  
  
  /* From G.709, PSI is located at row 4, column 15 */
  row = 3;
  col = 14;
  tmp_psi_str_size = psi_str_size;
  
  /* Configure the string inserter for specified layer */
  /* String inserter MFM: 
    — ‘000’ selects the programmable OTNT_MFMINT:MFM4 “MFAS event”,
    — ‘001’ selects the programmable OTNT_MFMINT:MFM5 “MFAS event”,
    — ...............................
    — ‘111’ selects the programmable OTNT_MFMINT:MFM11 “MFAS event” */
  /* Units 16-19 are recommended for 256 Byte PSI */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    if (tmp_psi_str_size > 64) {
      sicnt = 63;
      tmp_psi_str_size -= 64;
    }
    else {
      sicnt = tmp_psi_str_size-1;
      tmp_psi_str_size = 0;
    }
  
    rtn |= ten_n10g_oohr_config_string_inserter(module_id, slice,
                            /* unit,  */ unit,
                            /* sicnt, */ sicnt,
                            /* simfe, */ 4 + (unit - starting_unit), /* OTNT_MFM8..MFM11 */
                            /* sicol, */ col,
                            /* sirow  */ row);
  }

  /* Set up match unit */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_otnt_mfmcfg(module_id, slice,
                            /* match unit */   8 + (unit - starting_unit),  /* OTNT_MFM8..MFM11 */
                            /* mfmcmp     */   (unit - starting_unit) * 64, /* 0, 64, 128, 192 */
                            /* mfmmsk     */   0xFF);
  }

  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    /* Write the inserted PSI string to OTNSM RAM */    

    /* Bugzilla #24439, klocwork */
    if ((unit - starting_unit) == 0) {
      jj = 0;
    }
    else if ((unit - starting_unit) == 1) {
      jj = 64;
    }
    else if ((unit - starting_unit) == 2) {
      jj = 128;
    }
    else {
      jj = 192;
    }
    rtn |= ten_n10g_otnsm_set_string_inserter(module_id, slice, unit, &tmp_psi_str[jj]);
  }
  
  /* Enable String Inserter Unit */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_oohr_set_string_inserter_ie(module_id, slice, unit, 1);
  }  

  /* Toggle the double buffer to make string available for insertion */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_oohr_string_insertion_update(module_id, slice, unit);
  }  

RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SET 10G INSERTED PSI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_10g_inserted_psi(cs_uint16 module_id,
                             cs_uint8 slice, 
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PSI String Size                               */
/*              o PSI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets PSI for the specified layer.                            */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [str] pointer to a 256 byte PSI string buffer.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_set_10g_inserted_psi_unit(module_id,
                                           slice, 
                                           0xFF,  /* use recommended unit */
                                           psi_str_size, 
                                           psi_str));
}

/****************************************************************/
/* $rtn_hdr_start  GET 10G ACCEPTED PSI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_get_10g_accepted_psi_unit(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint16 starting_unit,
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Starting Unit                                 */
/*              o PSI String Size                               */
/*              o PSI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Gets the accepted PSI.                                       */
/* The accepted PSI and the expected PSI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*                                                              */
/*   [starting_unit]  Starting Unit to be used 1..21,           */
/*           or 0xFF for recommended.  Four Units beginning     */
/*           at "Starting Unit" are used.                       */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [str] pointer to a 256 byte PSI string buffer.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii, jj;
  cs_char8 tmp_psi_str[TEN_PSI_MAX_SIZE];
  cs_uint16 row, col, unit;
  
  /* Bugzilla #33948, only one slice can be returned at a time */
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    goto RTN_EXIT;
  }

  if (!psi_str) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, " : psi str is a null ptr.");
    goto RTN_EXIT;
  }

  if ( (psi_str_size < 2) || (psi_str_size > TEN_PSI_MAX_SIZE)) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, " : psi size out of range.");
    goto RTN_EXIT;
  }
  
  if ((starting_unit < 1) || (starting_unit > 21)) {
    if (starting_unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Starting Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }

  /* Bugzilla #34969, remove delays from PSI APIs */
  
  /* ‘000’ selects the programmable OOHR_MFMINT:MFM9 “MFAS event”,
     ‘001’ selects the programmable OOHR_MFMINT:MFM10 “MFAS event”,
     ...............................
     ‘111’ selects the programmable OOHR_MFMINT:MFM16 “MFAS event” */
  
  if (starting_unit == 0xFF) {
    starting_unit = 16;
  }  
  
  /* From G.709, PSI is located at row 4, column 15 */
  row = 3;
  col = 14;

  /* Units 16-19 are recommended for 256 Byte PSI */ 
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_oohr_set_string_extractor_off(module_id, slice, unit, 1);
  }
  
  /* set dTIM Mode off */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_oohr_set_string_extractor_dmm(module_id, slice, unit, 0);
  }  

  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_oohr_config_string_extractor(module_id,
                                 slice,
                              /* unit,   */ unit,
                              /* se_mfe, */ unit - starting_unit,  /* OOHR_MFM9..12 */
                              /* se_cnt, */ 63,
                              /* se_col, */ col,
                              /* se_row, */ row, 
                              /* se_cmp, */ 0x0F);
                              
    /* Bugzilla #20887, specify the correct match unit */
    rtn |= ten_n10g_oohr_mfmcfg(module_id, 
                                 slice,  
                              /* match unit */   9 + (unit - starting_unit),         /* OOHR_MFM9..12 */
                              /* mfmcmp     */   (unit - starting_unit) * 64,  /* 0, 64, 128, 192 */
                              /* mfmmsk     */   0xFF);
  }
  
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_oohr_set_string_extractor_off(module_id, slice, unit, 0);
  }  
  
  /* Bugzilla #34969, remove delays from PSI APIs */
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
    CS_PRINT("WARNING:  N10G string extractor not stable."); 
  }
  
  /* Get the accepted string */    
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    jj = 64*(unit-starting_unit);
    if (jj < TEN_PSI_MAX_SIZE) {
      rtn |= ten_n10g_otnsm_get_string_extractor(module_id, slice,unit, &tmp_psi_str[jj]);
    }  
  }  
 
  for (ii=0; ii<psi_str_size; ii++) {
    psi_str[ii] = tmp_psi_str[ii];
  }
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  GET 10G ACCEPTED PSI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_get_10g_accepted_psi(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint16 psi_str_size, 
                             cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PSI String Size                               */
/*              o PSI String                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Gets the accepted PSI.                                       */
/* The accepted PSI and the expected PSI are mutually exclusive */
/* and only one or the other can be used at one time.           */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [str] pointer to a 256 byte PSI string buffer.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_get_10g_accepted_psi_unit(module_id, 
                                           slice, 
                                           0xFF,  /* use recommended unit */
                                           psi_str_size, 
                                           psi_str));
}

/****************************************************************/
/* $rtn_hdr_start  PRINT 10G ACCEPTED PSI UNIT                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_print_10g_accepted_psi_unit(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 starting_unit,
                                        cs_uint16 psi_str_size)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Starting Unit                                 */
/*              o String Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the accepted PSI for the specified layer.             */
/* The accepted PSI and the expected PSI are mutually exclusive */
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
/*   [starting_unit]  Starting Unit to be used 1..21,           */
/*           or 0xFF for recommended.  Four Units beginning     */
/*           at "Starting Unit" are used.                       */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256).             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_char8 tmp_psi_str[TEN_PSI_MAX_SIZE];

  rtn = ten_hl_get_10g_accepted_psi_unit(module_id, slice, starting_unit, 
                                         psi_str_size, tmp_psi_str);
                                         
  /* Bugzilla #42300 - Fix klocwork warnings */
  if (psi_str_size > 256) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": out of range.  s/b 2..256.");
    return(CS_ERROR);
  }
                                         
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_psi_str, psi_str_size);
  }  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PRINT 10G ACCEPTED PSI                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_print_10g_accepted_psi(cs_uint16 module_id, 
                                        cs_uint8 slice, 
                                        cs_uint16 psi_str_size)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o String Size                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the accepted PSI for the specified layer.             */
/* The accepted PSI and the expected PSI are mutually exclusive */
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
/*   [psi_str_size] PSI string byte count (2..256).             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_print_10g_accepted_psi_unit(module_id, 
                                             slice,
                                             0xFF,  /* use recommended unit */
                                             psi_str_size));
}

/****************************************************************/
/* $rtn_hdr_start  SET 10G EXPECTED PSI UNIT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_10g_expected_psi_unit(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 starting_unit,
                                      cs_uint16 psi_cmp, 
                                      cs_uint16 psi_str_size,
                                      cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Starting Unit                                 */
/*              o PSI Compare Selection Mask                    */
/*              o PSI String Size                               */
/*              o PSI Expected String                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the expected PSI for the specified layer.               */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [starting_unit]  Starting Unit to be used 1..21,           */
/*           or 0xFF for recommended.  Four Units beginning     */
/*           at "Starting Unit" are used.                       */
/*                                                              */
/*   [psi_cmp] PSI Cmp selection Mask.                          */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [psi_str] pointer to a 256 byte PSI string buffer.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii, jj, row, col, unit = 0;
  cs_char8 tmp_psi_str[TEN_PSI_MAX_SIZE];
  cs_uint16 tmp_psi_str_size, secnt;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    goto RTN_EXIT;
  }

  if (psi_cmp > 0xF) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Parameter out of range.");
    rtn = CS_ERROR;
    goto RTN_EXIT;
  }
 
  if (!psi_str) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, " : psi str is a null ptr.");
    goto RTN_EXIT;
  }

  if ( (psi_str_size < 2) || (psi_str_size > TEN_PSI_MAX_SIZE)) {
    rtn = CS_ERROR;  
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, " : psi size out of range.");
    goto RTN_EXIT;
  }
  
  if ((starting_unit < 1) || (starting_unit > 21)) {
    if (starting_unit != 0xFF) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ":  Starting Unit out of range.");
      rtn = CS_ERROR;  
      goto RTN_EXIT;
    }
  }

  /* Bugzilla #34969, remove delays from PSI APIs */
  
  for (ii=0; ii<psi_str_size; ii++) {
    tmp_psi_str[ii] = psi_str[ii];
  }
  
  for (ii=psi_str_size; ii<TEN_PSI_MAX_SIZE; ii++) {
    tmp_psi_str[ii] = 0;
  }
  
  if (starting_unit == 0xFF) {
    starting_unit = 16;
  }  
  
  /* From G.709, PSI is located at row 4, column 15 */
  row = 3;
  col = 14;

  /* “on-the-fly” modification of the expected string value           */
  /* Set SEnOFF (n=1…24) at value “1”, in order to allow software     */
  /* to re-program a new expected string value into the OTNSM_RAM.    */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_oohr_set_string_extractor_off(module_id, slice, unit, 1);
  }  

  /* set dTIM Mode off */
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_oohr_set_string_extractor_dmm(module_id, slice, unit, 0);
  }  

  /* String Extractor MFM:   
  — ‘000’ selects the programmable OOHR_MFMINT:MFM9 “MFAS event”,
  — ‘001’ selects the programmable OOHR_MFMINT:MFM10 “MFAS event”,
  — ...............................
  — ‘111’ selects the programmable OOHR_MFMINT:MFM16 “MFAS event” */

  tmp_psi_str_size = psi_str_size;
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    if (tmp_psi_str_size > 64) {
      secnt = 63;
      tmp_psi_str_size -= 64;
    } else {
      secnt = tmp_psi_str_size-1;
      tmp_psi_str_size = 0;
    }

    /* configure for dTIM mode */
    rtn |= ten_n10g_oohr_config_string_extractor(module_id, slice,  
                              /* unit,   */ unit,
                              /* se_mfe, */ unit - starting_unit,   /* OOHR_MFM9..12 */
                              /* se_cnt, */ secnt,
                              /* se_col, */ col,
                              /* se_row, */ row, 
                              /* se_cmp, */ psi_cmp);

    rtn |= ten_n10g_oohr_mfmcfg(module_id, slice,  
                              /* match unit */   9 + (unit - starting_unit),  /* OOHR_MFM9..12 */
                              /* mfmcmp     */   (unit - starting_unit) * 64, /* 0, 64, 128, 192 */
                              /* mfmmsk     */   0xFF);
  }

  /* Set the extracted string to the expected string for DTIM mode */  
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
  
    /* Bugzilla #24439, klocwork */
    if ((unit - starting_unit) == 0) {
      jj = 0;
    }
    else if ((unit - starting_unit) == 1) {
      jj = 64;
    }
    else if ((unit - starting_unit) == 2) {
      jj = 128;
    }
    else {
      jj = 192;
    }
  
    rtn |= ten_n10g_otnsm_set_string_extractor(module_id, slice, unit, &tmp_psi_str[jj]);
  }

  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_oohr_set_string_extractor_dmm(module_id, slice, unit, 1);
  }
                              
  for (unit=starting_unit; unit<(starting_unit+4); unit++) {
    rtn |= ten_n10g_oohr_set_string_extractor_off(module_id, slice, unit, 0);
  }  
  
RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SET 10G EXPECTED PSI                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_set_10g_expected_psi(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 psi_cmp, 
                                      cs_uint16 psi_str_size,
                                      cs_char8 *psi_str)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PSI Compare Selection Mask                    */
/*              o PSI String Size                               */
/*              o PSI Expected String                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the expected PSI for the specified layer.               */
/*                                                              */
/*   [slice] parameter is specified as:                         */
/*     0x00 = TEN_SLICE0                                        */
/*     0x01 = TEN_SLICE1                                        */
/*     0x02 = TEN_SLICE2                                        */
/*     0x03 = TEN_SLICE3                                        */
/*     0xFF = TEN_SLICE_ALL                                     */
/*                                                              */
/*   [psi_cmp] PSI Cmp selection Mask.                          */
/*                                                              */
/*   [psi_str_size] PSI string byte count (2..256)              */
/*                                                              */
/*   [psi_str] pointer to a 256 byte PSI string buffer.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_hl_set_10g_expected_psi_unit(module_id,
                                           slice, 
                                           0xFF,  /* use recommended unit */
                                           psi_cmp, 
                                           psi_str_size,
                                           psi_str));
}


