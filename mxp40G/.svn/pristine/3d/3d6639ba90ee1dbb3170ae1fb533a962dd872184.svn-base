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
 * ten_n10g_otnr.c
 *
 * N10G related code is implemented here.
 *
 * $Id: ten_n10g_otnr.c,v 1.11 2014/04/02 21:29:14 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N10G GET OTU FRAMER STATUS                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n10g_get_otu_framer_status(cs_uint16 module_id,
                                        cs_uint8 slice,
                                        cs_uint16 field)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Field                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : The requested field from the OTU Framer Status  */
/*              Register.                                       */
/* DESCRIPTION:                                                 */
/* Returns the requested field from the OTU Framer Status       */
/* Register.                                                    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [field] parameter is specified as:                       */
/*   TEN_NX0G_OTNR_OFSTAT_FSUSTS                                */
/*   TEN_NX0G_OTNR_OFSTAT_SIF                                   */
/*   TEN_NX0G_OTNR_OFSTAT_SOOF                                  */
/*   TEN_NX0G_OTNR_OFSTAT_SLOF                                  */
/*   TEN_NX0G_OTNR_OFSTAT_SPHA                                  */
/*   TEN_NX0G_OTNR_OFSTAT_FST                                   */
/*   TEN_NX0G_OTNR_OFSTAT_PN11S                                 */
/*   TEN_NX0G_OTNR_OFSTAT_ALL                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N10G_OTNR_OFSTAT_t tmp_otnr_ofstat;
  TEN_MPIF_GLOBAL_RESET_N10G_A_t tmp_global_reset_n10g_a;
  TEN_MPIF_GLOBAL_RESET_N10G_B_t tmp_global_reset_n10g_b;
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  cs_char8 *func = "ten_n10g_get_otu_framer_status";  

  TEN_N10G_VALIDATE(module_id, slice);
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s slice out of range.  s/b 0..3.", func);
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  /* Bugzilla  #30991:  Corrections needed in drl null, fix bus errors */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
    tmp_global_reset_n10g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_A));
    if (tmp_global_reset_n10g_a.bf.rx & (1<<slice)) {
      CS_PRINT("N10G slice in hard reset, return 0\n");
      return (0);
    }
  }
  else {
    tmp_global_reset_n10g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_B));
    if (tmp_global_reset_n10g_b.bf.rx & (1<<slice)) {
      CS_PRINT("N10G slice in hard reset, return 0\n");
      return (0);
    }
  }
  
  tmp_otnr_ofstat.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OFSTAT));
  switch (field) {
  case TEN_NX0G_OTNR_OFSTAT_FSUSTS :
    {
      rtn = tmp_otnr_ofstat.bf.FSUSTS;
      break;
    }
  case TEN_NX0G_OTNR_OFSTAT_SIF :
    {
      rtn = tmp_otnr_ofstat.bf.SIF;
      break;
    }
  case TEN_NX0G_OTNR_OFSTAT_SOOF :
    {
      rtn = tmp_otnr_ofstat.bf.SOOF;
      break;
    }
  case TEN_NX0G_OTNR_OFSTAT_SLOF :
    {
      rtn = tmp_otnr_ofstat.bf.SLOF;
      break;
    }
  case TEN_NX0G_OTNR_OFSTAT_SPHA :
    {
      rtn = tmp_otnr_ofstat.bf.SPHA;
      break;
    }
  case TEN_NX0G_OTNR_OFSTAT_FST :
    {
      rtn = tmp_otnr_ofstat.bf.FST;
      break;
    }
  case TEN_NX0G_OTNR_OFSTAT_PN11S :
    {
      rtn = tmp_otnr_ofstat.bf.PN11S;
      break;
    }

  case TEN_NX0G_OTNR_OFSTAT_ALL :
    {
      rtn = tmp_otnr_ofstat.wrd;
      break;
    }
  default :
    {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s select out of range.  s/b 0..6, 0xFFFF.", func);
      rtn = CS_ERROR;
      break;
    }
  }
  /* Bug #43520 - ten_n10g_get_otu_framer_status does not print debug string correctly for the case "TEN_NX0G_OTNR_OFSTAT_ALL" */
  if (field == TEN_NX0G_OTNR_OFSTAT_ALL) {
    CS_PRINT("%s() %s, %s NX0G_OTNR_OFSTAT_ALL=0x%X\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice], rtn);
  } 
  else {
    CS_PRINT("%s() %s, %s %s=0x%X\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice], ten_nx0g_otnr_strings[field], rtn);
  }  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET OTN DEWRAPPER CONFIG REGISTER       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_otnr_odwcfg(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_uint16 odu2sps,
                                   cs_uint16 mfp_len,
                                   cs_uint16 fsomd,
                                   cs_uint16 c15res_en,
                                   cs_uint16 g43md,
                                   cs_uint16 jc_plus,
                                   cs_uint16 stm64md,
                                   cs_uint16 dwmod)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o ODU2SPS                                       */
/*              o MFP LEN                                       */
/*              o FSOMD                                         */
/*              o C15RES EN                                     */
/*              o G43MD                                         */
/*              o JC PLUS                                       */
/*              o STM64MD                                       */
/*              o DWMOD                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the 10G OTN Dewrapper Configuration     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [odu2sps] parameter is specified as                      */
/*   0 = OTN Reverse-Multiplexing phase compensation enable     */
/*   1 = OTN Reverse-Multiplexing phase compensation enable     */
/*       Note: This is useful for distributing an ODU3/OTU3     */
/*       data stream across 4x10G. Must be turned off during    */
/*       normal operation or Generic Reverse-Multiplexing.      */
/*                                                              */
/* The [mfp_len] parameter is specified as:                     */
/*   0b00 = MFP 1 every 2 frames                                */
/*   0b01 = MFP 1 every 4 frames                                */
/*   0b10 = MFP 1 every 8 frames                                */
/*   0b11 = MFP 1 every 16 frames                               */
/*   Note: Used for Generic and OTN Reverse-Multiplexing phase  */
/*   compensation.                                              */
/*                                                              */
/* The [fsomd] parameter is specified as:                       */
/*   0                                                          */
/*   1 = Forward Shortened OTN mode: In this mode the dewrapper */
/*       removes the FEC redundancy portion of the data frame   */
/*       (OTU2 to ODU2) from the data stream sent towards the   */
/*       crossconnect.                                          */
/*                                                              */
/* The [c15res_en] parameter is specified as:                   */
/*   Enable extra payload bytes in column 15                    */
/*   0bxx1 = row 1 column 15 is payload                         */
/*   0bx1x = row 2 column 15 is payload                         */
/*   0b1xx = row 3 column 15 is payload                         */
/*                                                              */
/* The [g43md] parameter is specified as:                       */
/*   0                                                          */
/*   1 = G43MD mode: In this mode, The Mapping & Concatenation  */
/*       Specific Bits of the OPU Overhead (Bytes 1, 2, and 3   */
/*       of column 15 and all of column 16) are used to carry   */
/*       data. When this bit is active, C15RES_EN and JC_PLUS   */
/*       are ignored.                                           */
/*                                                              */
/* The [jc_plus] parameter is specified as:                     */
/*   Enable extra positive justification. Upto 6 PJO            */
/*   encode  NJO  PJO1  PJO2  PJO3  PJO4  PJO5  PJO6  Justif    */
/*   ------ ----- ----- ----- ----- ----- ----- ----- -----     */
/*   0b000  Stuff Data  Data  Data  Data  Data  Data   0        */
/*   0b001  Data  Data  Data  Data  Data  Data  Data  -1        */
/*   0b010  Stuff Stuff Stuff Data  Data  Data  Data  +2        */
/*   0b011  Stuff Stuff Data  Data  Data  Data  Data  +1        */
/*   0b100  Stuff Stuff Stuff Stuff Stuff Data  Data  +4        */
/*   0b101  Stuff Stuff Stuff Stuff Data  Data  Data  +3        */
/*   0b110  Stuff Stuff Stuff Stuff Stuff Stuff Stuff +6        */
/*   0b111  Stuff Stuff Stuff Stuff Stuff Stuff Data  +5        */
/*                                                              */
/* The [stm64md] parameter is specified as:                     */
/*   0                                                          */
/*   1 = STM64 mode: In this mode, the bytes in the columns     */
/*       1905 to 1920 of each row are assumed to be stuff bytes */
/*       and removed by the dewrapper                           */
/*                                                              */
/* The [dwmod] parameter is sppecified as:                      */
/*   Mode of operation for 2.5G OTN Dewrapper:                  */
/*   0b000 Dewrapper disabled (Data is passed through dewrapper */
/*         'as is')                                             */
/*   0b001 Dewrapper enabled (Justification commands are        */
/*         ignored)                                             */
/*   0b010 Dewrapper disabled.                                  */
/*   0b011 Dewrapper enabled (Justification commands are        */
/*         evaluated)                                           */
/*   0b100 Dewrapper disabled.                                  */
/*   0b101 Dewrapper enabled to remove FEC parity only (OTU2 to */
/*         ODU2)                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.ODU2SPS = odu2sps;
      tmp_otnr_odwcfg.bf.MFP_LEN = mfp_len;
      tmp_otnr_odwcfg.bf.FSOMD = fsomd;
      tmp_otnr_odwcfg.bf.C15RES_EN = c15res_en;
      tmp_otnr_odwcfg.bf.G43MD = g43md;
      tmp_otnr_odwcfg.bf.JC_PLUS = jc_plus;
      tmp_otnr_odwcfg.bf.STM64MD = stm64md;
      tmp_otnr_odwcfg.bf.DWMOD = dwmod;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET OTN DEWRAPPER CONFIG ODU2SPS        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_otnr_odwcfg_odu2sps(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_uint16 odu2sps)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o ODU2SPS                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets ODU2SPS of 10G OTN Dewrapper Configuration Register.    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [odu2sps] parameter is specified as                      */
/*   0 = OTN Reverse-Multiplexing phase compensation enable     */
/*   1 = OTN Reverse-Multiplexing phase compensation enable     */
/*       Note: This is useful for distributing an ODU3/OTU3     */
/*       data stream across 4x10G. Must be turned off during    */
/*       normal operation or Generic Reverse-Multiplexing.      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.ODU2SPS = odu2sps;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET OTN DEWRAPPER CONFIG MFP LEN        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_otnr_odwcfg_mfp_len(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_uint16 mfp_len)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o MFP LEN                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets MPF_LEN of 10G OTN Dewrapper Configuration Register.    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mfp_len] parameter is specified as:                     */
/*   0b00 = MFP 1 every 2 frames                                */
/*   0b01 = MFP 1 every 4 frames                                */
/*   0b10 = MFP 1 every 8 frames                                */
/*   0b11 = MFP 1 every 16 frames                               */
/*   Note: Used for Generic and OTN Reverse-Multiplexing phase  */
/*   compensation.                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.MFP_LEN = mfp_len;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET OTNR FIXED STUFF BYTE REGISTER      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_otnr_odwfs(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 fs)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FS                                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Fixed stuff bytes carried in OPU                             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [fs] parameter is specified as:                          */
/*   0x0000 - 0x7FFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWFS_t tmp_otnr_odwfs;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwfs.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWFS));
      tmp_otnr_odwfs.bf.FS = fs;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWFS), tmp_otnr_odwfs.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G GET OTNR FIXED STUFF BYTE REGISTER      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n10g_get_otnr_odwfs(cs_uint16 module_id,
                                 cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0x0000..0x7FFF                                  */
/* DESCRIPTION:                                                 */
/* Fixed stuff bytes carried in OPU                             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N10G_OTNR_ODWFS_t tmp_otnr_odwfs;
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;

  TEN_N10G_VALIDATE(module_id, slice);
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_otnr_odwfs.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWFS));
  rtn = tmp_otnr_odwfs.bf.FS;

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET OTNR SCRAMBLING MODE                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_descrambling(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 postdscr,
                                     cs_uint16 predscr)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o POSTDSCR                                      */
/*              o PREDSCR                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set OTNR descrambling mode.                                  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [postdscr] parameter is specified as:                    */
/*   OxU Descrambler enable POST-FEC. Used only for OTU.        */
/*   0 = Descrambler disabled (GFEC or ODU2 or test purpose)    */
/*   1 = Descrambler enabled (UFEC only)                        */
/*                                                              */
/* The [predscr] parameter is specified as:                     */
/*   OxU Descrambler enable Pre-FEC. Used for both OTU and ODU. */
/*   0 = Descrambler disabled (UFEC or test purpose)            */
/*   1 = Descrambler enabled (GFEC or ODU2)                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_OACFG0_t tmp_otnr_oacfg0;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG0));
      tmp_otnr_oacfg0.bf.POSTDSCR = postdscr;
      tmp_otnr_oacfg0.bf.PREDSCR = predscr;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG0), tmp_otnr_oacfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNR CONFIG                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnr_ocfg(cs_uint16 module_id, cs_uint8 slice,
                         cs_boolean fecmd,
                         cs_boolean fecen)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o FECMD                                             */
/*              o FECEN                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* OxU2 OTNR Configuration.                                         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [fecmd]                                                        */
/*                                                                  */
/*   [fecen]                                                        */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_OACFG0_t tmp_otnr_oacfg0;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG0));
      tmp_otnr_oacfg0.bf.FECMD = fecmd & 0x01;
      tmp_otnr_oacfg0.bf.FECEN = fecen;

      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG0), tmp_otnr_oacfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET FRAME FORMAT                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_frame_format(cs_uint16 module_id, cs_uint8 slice,
                                         cs_uint16 ncols,
                                         cs_uint16 nrows,
                                         cs_uint16 nparb,
                                         cs_uint16 npar)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o NCOLS                                         */
/*              o NROWS                                         */
/*              o NPARB                                         */
/*              o NPAR                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the OTU Frame Configuration 0 & 1 Registers.             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [ncols] parameter is specified as:                       */
/*   000-3FF hex                                                */
/*                                                              */
/* The [nrows] parameter is specified as:                       */
/*   0-F hex                                                    */
/*                                                              */
/* The [nparb] parameter is specified as:                       */
/*   0-F hex                                                    */
/*                                                              */
/* The [npar] parameter is specified as:                        */
/*   00-1F hex                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_OFCFG0_t tmp_otnr_ofcfg0;
  TEN_N10G_OTNR_OFCFG1_t tmp_otnr_ofcfg1;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_ofcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OFCFG0));
      tmp_otnr_ofcfg0.bf.NCOLS = ncols;
      tmp_otnr_ofcfg0.bf.NROWS = nrows;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OFCFG0), tmp_otnr_ofcfg0.wrd);

      tmp_otnr_ofcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OFCFG1));
      tmp_otnr_ofcfg1.bf.NPARB = nparb;
      tmp_otnr_ofcfg1.bf.NPAR = npar;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OFCFG1), tmp_otnr_ofcfg1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET DWMOD                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_dwmod(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 dwmod)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o DWMOD                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the 10G OTN Dewrapper Configuration     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dwmod] parameter is sppecified as:                      */
/*   Mode of operation for 2.5G OTN Dewrapper:                  */
/*   0b000 Dewrapper disabled (Data is passed through dewrapper */
/*         'as is')                                             */
/*   0b001 Dewrapper enabled (Justification commands are        */
/*         ignored)                                             */
/*   0b010 Dewrapper disabled.                                  */
/*   0b011 Dewrapper enabled (Justification commands are        */
/*         evaluated)                                           */
/*   0b100 Dewrapper disabled.                                  */
/*   0b101 Dewrapper enabled to remove FEC parity only (OTU2 to */
/*         ODU2)                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.DWMOD = dwmod;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET JC_PLUS                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_jc_plus(cs_uint16 module_id,
                                    cs_uint8 slice,
                                    cs_uint16 jc_plus)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o JC PLUS                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the 10G OTN Dewrapper Configuration     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [jc_plus] parameter is specified as:                     */
/*   Enable extra positive justification. Upto 6 PJO            */
/*   encode  NJO  PJO1  PJO2  PJO3  PJO4  PJO5  PJO6  Justif    */
/*   ------ ----- ----- ----- ----- ----- ----- ----- -----     */
/*   0b000  Stuff Data  Data  Data  Data  Data  Data   0        */
/*   0b001  Data  Data  Data  Data  Data  Data  Data  -1        */
/*   0b010  Stuff Stuff Stuff Data  Data  Data  Data  +2        */
/*   0b011  Stuff Stuff Data  Data  Data  Data  Data  +1        */
/*   0b100  Stuff Stuff Stuff Stuff Stuff Data  Data  +4        */
/*   0b101  Stuff Stuff Stuff Stuff Data  Data  Data  +3        */
/*   0b110  Stuff Stuff Stuff Stuff Stuff Stuff Stuff +6        */
/*   0b111  Stuff Stuff Stuff Stuff Stuff Stuff Data  +5        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.JC_PLUS = jc_plus;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET C15RES_EN                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_c15res_en(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint16 c15res_en)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o C15RES EN                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the 10G OTN Dewrapper Configuration     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [c15res_en] parameter is specified as:                   */
/*   Enable extra payload bytes in column 15                    */
/*   0bxx1 = row 1 column 15 is payload                         */
/*   0bx1x = row 2 column 15 is payload                         */
/*   0b1xx = row 3 column 15 is payload                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.C15RES_EN = c15res_en;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET STM64 MODE                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_stm64md(cs_uint16 module_id,
                                    cs_uint8 slice,
                                    cs_uint16 stm64md)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o STM64MD                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the 10G OTN Dewrapper Configuration     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [stm64md] parameter is specified as:                     */
/*   0                                                          */
/*   1 = STM64 mode: In this mode, the bytes in the columns     */
/*       1905 to 1920 of each row are assumed to be stuff bytes */
/*       and removed by the dewrapper                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.STM64MD = stm64md;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET G43 MODE                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_g43md(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 g43md)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o G43MD                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the 10G OTN Dewrapper Configuration     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [g43md] parameter is specified as:                       */
/*   0                                                          */
/*   1 = G43MD mode: In this mode, The Mapping & Concatenation  */
/*       Specific Bits of the OPU Overhead (Bytes 1, 2, and 3   */
/*       of column 15 and all of column 16) are used to carry   */
/*       data. When this bit is active, C15RES_EN and JC_PLUS   */
/*       are ignored.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.G43MD = g43md;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET FSO MODE                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_fsomd(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 fsomd)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FSOMD                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the 10G OTN Dewrapper Configuration     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [fsomd] parameter is specified as:                       */
/*   0                                                          */
/*   1 = Forward Shortened OTN mode: In this mode the dewrapper */
/*       removes the FEC redundancy portion of the data frame   */
/*       (OTU2 to ODU2) from the data stream sent towards the   */
/*       crossconnect.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.FSOMD = fsomd;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNR SET LINKALM JCNOM                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnr_set_linkalm_jcnom(cs_uint16 module_id, cs_uint8 slice,
                           cs_uint16 linkalm_jcnom)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o LINKALM JCNOM                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets OTN Dewrapper Configuration linkalm_jcnom.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [linkalm_jcnom]                                                */
/*     JC Nominal on Link/Frame Alarm. If set, this bit will cause  */
/*     the dewrapper to disable justifications and interpret all    */
/*     frames as having nominal JC when a signal fail alarm is      */
/*     detected in the OTN Link/Frame layer.  When this bit is      */
/*     not set, JC interpretation will continue according to the    */
/*     setting of JC_ENABLE in the presence of a Link/Frame layer   */
/*     alarm.                                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.LINKALM_JCNOM = linkalm_jcnom;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET NCOLS                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_ncols(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 ncols)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o NCOLS                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the N10G RX NCOLS parameter.                             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [ncols] parameter is specified as:                       */
/*   000-3FF hex                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_OFCFG0_t tmp_otnr_ofcfg0;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_ofcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OFCFG0));
      tmp_otnr_ofcfg0.bf.NCOLS = ncols;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OFCFG0), tmp_otnr_ofcfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET NPARB AND NPAR                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_nparb_npar(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 nparb,
                                       cs_uint16 npar)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o NPARB                                         */
/*              o NPAR                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the N10G RX NPAR and NPARB parameters.                  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [nparb] parameter is specified as:                       */
/*   0-F hex                                                    */
/*                                                              */
/* The [npar] parameter is specified as:                        */
/*   00-7F hex                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_OFCFG1_t tmp_otnr_ofcfg1;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_ofcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OFCFG1));
      tmp_otnr_ofcfg1.bf.NPARB = nparb;
      tmp_otnr_ofcfg1.bf.NPAR = npar;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OFCFG1), tmp_otnr_ofcfg1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SELECT GLOBAL TIMING SOURCE        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_select_global_timing_source(cs_uint16 module_id,
                                                    cs_uint8 slice,
                                                    cs_uint16 select)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Selects one out of eight different statistics timing         */
/* generators.                                                  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [select] parameter is specified as:                      */
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
  cs_uint16 sl;
  TEN_N10G_OTNR_STACFG_t tmp_otnr_stacfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_stacfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, STACFG));
      tmp_otnr_stacfg.bf.GISEL = select;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, STACFG), tmp_otnr_stacfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET ODWFSCFG UNSTABLE NUMBER       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_fs_mlen(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 fs_mlen)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FS MLEN                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* FS_MLEN[3:0] This bit field configures the number of         */
/* received Fixed Stuff word that must differ from the          */
/* previously accepted ones in order to produce an unstable     */
/* event. Setting this bit field to zero will inhibit any       */
/* events.                                                      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [fs_mlen] parameter is specified as:                     */
/*   0x0..0xF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWFSCFG_t tmp_otnr_odwfscfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwfscfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWFSCFG));
      tmp_otnr_odwfscfg.bf.FS_MLEN = fs_mlen;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWFSCFG), tmp_otnr_odwfscfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR SET ODWFSCFG CHANGE NUMBER         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_set_fs_aflen(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 fs_aflen)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FS AFLEN                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* FS_AFLEN[3:0] This bit field configures the number of        */
/* identical received Fixed Stuff word needed to issue a change */
/* event. Setting this bit field to zero will inhibit any       */
/* events.                                                      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [fs_aflen] parameter is specified as:                    */
/*   0x0..0xF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWFSCFG_t tmp_otnr_odwfscfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_odwfscfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWFSCFG));
      tmp_otnr_odwfscfg.bf.FS_AFLEN = fs_aflen;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWFSCFG), tmp_otnr_odwfscfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR GET ODWFSFILT                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n10g_otnr_get_odwfsfilt(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0x0000-0x7FFF                                   */
/* DESCRIPTION:                                                 */
/* Filtered fixed stuff byte.  The returned 16-bit value is     */
/* concatenated as:                                             */
/*   FS_FILT[14:10] Row 1 Column16[7:3]                         */
/*   FS_FILT[9:5]   Row 2 Column16[7:3]                         */
/*   FS_FILT[4:0]   Row 3 Column16[7:3]                         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3.                                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_ODWFSFILT_t tmp_otnr_odwfsfilt;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if (slice == sl) {
      tmp_otnr_odwfsfilt.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWFSFILT));
    }
  }
  return (tmp_otnr_odwfsfilt.wrd);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNR OACFG0 DSYHYST                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnr_oacfg0_dsyhyst(cs_uint16 module_id, cs_uint8 slice,
                           cs_uint16 dsyhyst)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DSYHYST                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dsyhyst]                                                      */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_OACFG0_t tmp_otnr_oacfg0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG0));
      tmp_otnr_oacfg0.bf.DSYHYST = dsyhyst;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG0), tmp_otnr_oacfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNR LOFCFG TDELON TDELOFF                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnr_lofcfg_tdelon_tdeloff(cs_uint16 module_id, cs_uint8 slice,
                                              cs_uint16 tdelon, cs_uint16 tdeloff)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o TDELON                                            */
/*              o TDELOFF                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value for LOF Acceptance Filter Configuration #1 and #2.    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tdelon]  TDELON Value                                         */
/*                                                                  */
/*   [tdelon]  TDELOFF Value.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNR_LOFCFG0_t tmp_otnr_lofcfg0;
  TEN_N10G_OTNR_LOFCFG1_t tmp_otnr_lofcfg1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_lofcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOFCFG0));
      tmp_otnr_lofcfg0.bf.TDELON = tdelon;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOFCFG0), tmp_otnr_lofcfg0.wrd);

      tmp_otnr_lofcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOFCFG1));
      tmp_otnr_lofcfg1.bf.TDELOFF = tdeloff;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOFCFG1), tmp_otnr_lofcfg1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G PN11 PATTERN INSERTION SEQUENCE             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_pn11_pattern_select_t41(cs_uint16 module_id,
                                           cs_uint8 slice,
                                           cs_uint16 pn11_type)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PN11 Type                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Although a standard OTUj(V)-AIS signal (j=2, 2e, 1e, etc) is an  */
/* unframed PN11 sequence over the entire OTUj(V) bandwidth, for    */
/* non-standard operation it is possible to configure the Rx OTUj(V)*/
/* frame region on which the PN11 sequence is expected to be        */
/* automatically detected. This API configures the expected region  */
/* carrying the PN11 sequence.                                      */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/*   [pn11_type] specifies the PN11 pattern insertion type          */
/*      TEN_PN11_OTUKAIS      = 0                                   */
/*         OTUj(V)-AIS: The entire Rx OTUj(V) signal carries an     */
/*         unframed PN11 sequence                                   */
/*      TEN_PN11_FRAMED       = 1                                   */
/*         “Framed” OTUj(V)-AIS: The entire Rx OTUj(V) signal except*/
/*         the FAS and FEC bytes carry a PN11 sequence.             */
/*      TEN_PN11_ENTIRE_ODUK  = 2                                   */
/*          “ODUj-PN11”: Only the Rx OPUj payload, as well as Rx    */
/*          OPUj and ODUj overhead carry a PN11 sequence (all SM    */
/*          and FEC bytes are valid fields) (all SM and FEC bytes   */
/*          are valid fields)                                       */
/*      TEN_PN11_ENTIRE_OPUK  = 3                                   */
/*          “OPUj-PN11”: Only the Rx OPUj payload and overhead carry*/
/*          a PN11 sequence (column 15 through 3824). All Rx SM     */
/*          bytes, ODUj overhead and FEC bytes are valid fields.    */
/*      TEN_PN11_OPUK_PAYLOAD = 4                                   */
/*          “Payload-PN11”: Only the Rx OPUj payload carry a PN11   */
/*          sequence (column 17 through 3824). All Rx OxUj Overhead */
/*          bytes and FEC bytes are not overwritten with the PN-11. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return (CS_OK);
}
