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
 * ten_n10g_otnsm.c
 *
 * N10G OTN SM related code is implemented here.
 *
 * $Id: ten_n10g_otnsm.c,v 1.9 2013/02/22 20:47:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  N10G OTNSM SET STRING INSERTER                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnsm_set_string_inserter(cs_uint16 module_id, 
                                             cs_uint8 slice,
                                             cs_uint16 instance, 
                                             cs_char8 *str)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Instance                                          */
/*              o SI String                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the string to be inserted.                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [instance]  String Inserter Unit 1..24                         */
/*                                                                  */
/*   [str] pointer to 64 byte buffer to be inserted.                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_uint16 sl;
  cs_char8 *tmp_str;
  TEN_N10G_OTNSM_RAM_t tmp_otnsm_ram;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if (!instance) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 1..24.");
    return(CS_ERROR);
  }
  
  if ((instance > TEN_NX0G_OTNSM_RAM_UNIT_NUM) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 1..24.");
    return(CS_ERROR);
  }
  
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_str = str;
      for (ii=0; ii < TEN_NX0G_OTNSM_RAM_UNIT_SIZE; ii++) {
        tmp_otnsm_ram.bf.STR = *tmp_str;
        tmp_str++;
        /* Bugzilla #25564, fix for older compilers */
        tmp_otnsm_ram.wrd = (tmp_otnsm_ram.wrd & 0x00FF);
        tmp_otnsm_ram.bf.STR |= (((*tmp_str) << 8)&0xFF00);
        TEN_REG_WRITE(TEN_N10G_OTNSM_REG_ADDR(pDev, module_id, sl, RAM) + 
                      ii + (instance + 23) * TEN_NX0G_OTNSM_RAM_UNIT_SIZE, tmp_otnsm_ram.wrd);
        tmp_str++;
      }  
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNSM SET STRING EXTRACTOR                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnsm_set_string_extractor(cs_uint16 module_id, 
                                              cs_uint8 slice,
                                              cs_uint16 instance, 
                                              cs_char8 *str)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Instance                                          */
/*              o SE String                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the string extractor (for expected comparison).             */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/*   [instance]  String Extractor Unit 1..24                        */
/*                                                                  */
/*   [str]  Pointer to 64 byte buffer.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_char8 *tmp_str = str;
  TEN_N10G_OTNSM_RAM_t tmp_otnsm_ram;

  TEN_N10G_VALIDATE(module_id, slice);
  
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  if (!instance) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 1..24.");
    return(CS_ERROR);
  }
  
  if ((instance > TEN_NX0G_OTNSM_RAM_UNIT_NUM) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 1..24.");
    return(CS_ERROR);
  }
  
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_str = str;
      for (ii=0; ii < TEN_NX0G_OTNSM_RAM_UNIT_SIZE; ii++) {
        tmp_otnsm_ram.bf.STR = *tmp_str;
        tmp_str++;
        /* Bugzilla #25564, fix for older compilers */
        tmp_otnsm_ram.wrd = (tmp_otnsm_ram.wrd & 0x00FF);
        tmp_otnsm_ram.bf.STR |= (((*tmp_str)<<8)&0xFF00);
        TEN_REG_WRITE(TEN_N10G_OTNSM_REG_ADDR(pDev, module_id, sl, RAM) + 
                      ii + (instance - 1) * TEN_NX0G_OTNSM_RAM_UNIT_SIZE, tmp_otnsm_ram.wrd);
        tmp_str++;
      }  
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNSM GET STRING EXTRACTOR                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnsm_get_string_extractor(cs_uint16 module_id, 
                                              cs_uint8 slice,
                                              cs_uint16 instance, 
                                              cs_char8 *str)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Instance                                          */
/*              o SE String                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns the 64 byte string extracted.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/*   [instance]  String Extractor Unit 1..24                        */
/*                                                                  */
/*   [str]  Pointer to 64 byte buffer.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_char8 *tmp_str = str;
  TEN_N10G_OTNSM_RAM_t tmp_otnsm_ram;

  TEN_N10G_VALIDATE(module_id, slice);
  
  /* Bugzilla #33948, only one slice can be returned at a time */
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  if (!instance) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 1..24.");
    return (CS_ERROR);
  }
  
  if ((instance > TEN_NX0G_OTNSM_RAM_UNIT_NUM) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 1..24.");
    return (CS_ERROR);
  }
  
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  /* Bugzilla #33948, only one slice can be returned at a time */
  for (ii=0; ii < TEN_NX0G_OTNSM_RAM_UNIT_SIZE; ii++) {
    tmp_otnsm_ram.wrd = TEN_REG_READ(TEN_N10G_OTNSM_REG_ADDR(pDev, module_id, slice, RAM) +
                                     ii + (instance -1) * TEN_NX0G_OTNSM_RAM_UNIT_SIZE);

    *tmp_str = (cs_char8)(tmp_otnsm_ram.bf.STR & 0x00FF);
    tmp_str++;
    *tmp_str = (cs_char8)((tmp_otnsm_ram.bf.STR & 0xFF00) >> 8);
    tmp_str++;
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

