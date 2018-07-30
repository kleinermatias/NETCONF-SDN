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
 * ten_n10g_sofr.c
 *
 * N10G related code is implemented here.
 *
 * $Id: ten_n10g_sofr.c,v 1.10 2013/02/22 20:47:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  N10G SET SOFR J0 RAM                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_set_sofr_j0_ram(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 str_size, 
                                   cs_char8 *str)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o String Size                                       */
/*              o String                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register array contains the provisioned section trace       */
/* string that is compared with the received and as stable defined  */
/* section trace string. The J0_RAM is a 32-entry table. Each entry */
/* is 16 bits wide and occupies 1 16-bit register. The register     */
/* array can be written by the processor only when in manual mode.  */
/* In automatic mode it is updated by the hardware.                 */
/*                                                                  */
/*   NOTE:  The API will automatically pad the string entered       */
/*          by the user to 62 characters using ASCII NULL           */
/*          characters, and then add <CR> and <LF> characters       */
/*          (i.e., ‘0D’ and ‘0A’) for a total of 64 characters.     */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [str_size] parameter is specified as: size of expected J0    */
/*                                                                  */
/* The [str] parameter is specified as: a pointer to an expected    */
/*   J0 string (1..62).                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_char8 *tmp_str;
  cs_uint16 sl;
  TEN_N10G_SOFR_J0_RAM_t tmp_sofr_j0_ram;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  
  if ((!str_size) || (str_size > 62)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string size out of range.  s/b 1..62.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_str = str;
      for (ii = 0; ii < 62; ii+=2) {
        if (ii >= str_size) {
        tmp_sofr_j0_ram.bf.J0_STRNG = 0;
        } 
        else {
          tmp_sofr_j0_ram.bf.J0_STRNG = (*tmp_str)&0x00FF;
        }  
        tmp_str++;
        if ((ii+1) < str_size) {
          /* Bugzilla #25564, fix for older compilers */
          tmp_sofr_j0_ram.wrd = (tmp_sofr_j0_ram.wrd & 0x00FF);
          tmp_sofr_j0_ram.bf.J0_STRNG |= (((*tmp_str)<<8)&0xFF00);
        }  
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, J0_RAM) + 
                      ((ii / 2) * TEN_N10G_SOFR_J0_RAM_STRIDE), tmp_sofr_j0_ram.wrd);
        tmp_str++;
      }
      /* add CR-LF, LSB goes out first */
      tmp_sofr_j0_ram.bf.J0_STRNG = 0x0A0D;
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_N10G_REG_ADDR(pDev, module_id, sl, J0_RAM);
      tmp_addr += (31 * TEN_N10G_SOFR_J0_RAM_STRIDE);
      TEN_REG_WRITE(tmp_addr, tmp_sofr_j0_ram.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G GET SOFR J0 RAM                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_get_sofr_j0_ram(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_char8 *str)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o String                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register array contains the provisioned section trace       */
/* string that is compared with the received and as stable defined  */
/* section trace string. The J0_RAM is a 32-entry table. Each entry */
/* is 16 bits wide and occupies 1 16-bit register. The register     */
/* array can be written by the processor only when in manual mode.  */
/* In automatic mode it is updated by the hardware.                 */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [str] parameter is specified as: a pointer to a 64-byte      */
/*   string.                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_char8 *tmp_str = str;
  TEN_N10G_SOFR_J0_RAM_t tmp_sofr_j0_ram;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  for (ii=0; ii<TEN_N10G_SOFR_J0_RAM_COUNT; ii++) {
    tmp_sofr_j0_ram.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, J0_RAM) +
                                       (ii*TEN_N10G_SOFR_J0_RAM_STRIDE));
    *tmp_str = (cs_char8)(tmp_sofr_j0_ram.wrd & 0x00FF);
    tmp_str++;
    *tmp_str = (cs_char8)((tmp_sofr_j0_ram.wrd & 0xFF00) >> 8);
    tmp_str++;
  }
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G PRINT SOFR J0 RAM                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_print_sofr_j0_ram(cs_uint16 module_id,
                                   cs_uint8 slice)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Prints the section trace string.                                 */
/* This API is mainly for debugging purposes.                       */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn;
  T41_t *pDev = NULL;
  cs_char8 tmp_j0_str[64];
  
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  rtn = ten_n10g_get_sofr_j0_ram(module_id,
                                 slice,
                                 tmp_j0_str);
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_j0_str, 64);
  }
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SET SOFR J1 RAM                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_set_sofr_j1_ram(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 str_size, 
                                   cs_char8 *str)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o String Size                                       */
/*              o String                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register array contains the provisioned section trace       */
/* string that is compared with the received and as stable defined  */
/* section trace string The J1_RAM is a 32-entry table. Each entry  */
/* is 16 bits wide and occupies 1 16-bit register. The register     */
/* array can be written by the processor only when in manual mode.  */
/* In automatic mode it is updated by the hardware.                 */
/*                                                                  */
/*   NOTE:  The API will automatically pad the string entered       */
/*          by the user to 62 characters using ASCII NULL           */
/*          characters, and then add <CR> and <LF> characters       */
/*          (i.e., ‘0D’ and ‘0A’) for a total of 64 characters.     */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [str_size] parameter is specified as: size of expected J1    */
/*                                                                  */
/* The [str] parameter is specified as: a pointer to an expected    */
/*   J1 string (1..62).                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_char8 *tmp_str;
  cs_uint16 sl;
  TEN_N10G_SOFR_J1_RAM_t tmp_sofr_j1_ram;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  
  if ((!str_size) || (str_size > 62)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string size out of range.  s/b 1..62.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_str = str;
      for (ii=0; ii<62; ii+=2) {
        if (ii >= str_size) {
          tmp_sofr_j1_ram.bf.J1_STRNG = 0;
        }
        else {
          tmp_sofr_j1_ram.bf.J1_STRNG = (*tmp_str)&0x00FF;
        }  

        tmp_str++;
        if ((ii+1) < str_size) {
          /* Bugzilla #25564, fix for older compilers */
          tmp_sofr_j1_ram.wrd = (tmp_sofr_j1_ram.wrd & 0x00FF);
          tmp_sofr_j1_ram.bf.J1_STRNG |= (((*tmp_str)<<8)&0xFF00);
        }  
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, J1_RAM) + 
                      ((ii / 2) * TEN_N10G_SOFR_J1_RAM_STRIDE), tmp_sofr_j1_ram.wrd);
        tmp_str++;
      }
      /* add CR-LF, LSB goes out first */
      tmp_sofr_j1_ram.bf.J1_STRNG = 0x0A0D;
      
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_N10G_REG_ADDR(pDev, module_id, sl, J1_RAM);
      tmp_addr += 31 * TEN_N10G_SOFR_J1_RAM_STRIDE;
      TEN_REG_WRITE(tmp_addr, tmp_sofr_j1_ram.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G GET SOFR J1 RAM                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_get_sofr_j1_ram(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_char8 *str)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o String                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register array contains the provisioned section trace       */
/* string that is compared with the received and as stable defined  */
/* section trace string The J1_RAM is a 32-entry table. Each entry  */
/* is 16 bits wide and occupies 1 16-bit register. The register     */
/* array can be written by the processor only when in manual mode.  */
/* In automatic mode it is updated by the hardware.                 */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [str] parameter is specified as: a pointer to a 64-byte      */
/*   string.                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_char8 *tmp_str = str;
  TEN_N10G_SOFR_J1_RAM_t tmp_sofr_j1_ram;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  for (ii=0; ii<TEN_N10G_SOFR_J1_RAM_COUNT; ii++) {
    tmp_sofr_j1_ram.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, J1_RAM) +
                                       (ii*TEN_N10G_SOFR_J1_RAM_STRIDE));
    *tmp_str = (cs_char8)(tmp_sofr_j1_ram.wrd & 0x00FF);
    tmp_str++;
    *tmp_str = (cs_char8)((tmp_sofr_j1_ram.wrd & 0xFF00) >> 8);
    tmp_str++;
  }
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G PRINT SOFR J1 RAM                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_print_sofr_j1_ram(cs_uint16 module_id,
                                   cs_uint8 slice)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Prints the J1 string.                                            */
/* This API is mainly for debugging purposes.                       */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn;
  T41_t *pDev = NULL;
  cs_char8 tmp_j1_str[64];
  
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  rtn = ten_n10g_get_sofr_j1_ram(module_id,
                                 slice,
                                 tmp_j1_str);
  
  /* Bugzilla #23881, add CS_OK check before printing */
  if (rtn == CS_OK) {
  ten_drvr_str_dump(tmp_j1_str, 64);
  }
  return (CS_OK);
}
