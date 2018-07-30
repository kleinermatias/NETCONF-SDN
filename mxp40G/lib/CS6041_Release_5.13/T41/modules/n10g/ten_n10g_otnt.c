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
 * ten_n10g_otnt.c
 *
 * N10G OTNT related code is implemented here.
 *
 * $Id: ten_n10g_otnt.c,v 1.16 2014/03/23 23:56:17 pptawade Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET FRAME FORMAT                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_frame_format(cs_uint16 module_id, cs_uint8 slice, 
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
/* Set the Wrapper Configuration 0 & 2 Registers.               */
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
  TEN_N10G_OTNT_WRPCFG0_t tmp_otnt_wrpcfg0;
  TEN_N10G_OTNT_WRPCFG2_t tmp_otnt_wrpcfg2;
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
      tmp_otnt_wrpcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG0));
      tmp_otnt_wrpcfg0.bf.NCOLS = ncols;
      tmp_otnt_wrpcfg0.bf.NROWS = nrows;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG0), tmp_otnt_wrpcfg0.wrd);
      
      tmp_otnt_wrpcfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG2));
      tmp_otnt_wrpcfg2.bf.NPARB = nparb;
      tmp_otnt_wrpcfg2.bf.NPAR = npar;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG2), tmp_otnt_wrpcfg2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET WRAPPER CONFIGURATION REGISTER 3    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_otnt_wrpcfg3(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_uint16 stm64md, 
                                    cs_uint16 fpsynce, 
                                    cs_uint16 c15res_en, 
                                    cs_uint16 g43md, 
                                    cs_uint16 wrmd)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o STM64MD                                       */
/*              o FPSYNCE                                       */
/*              o C15RES EN                                     */
/*              o G43MD                                         */
/*              o WRMD                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set various aspects of the Wrapper Configuration 3 Register. */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [stm64md] parameter is specified as:                     */
/*   STM64 mode, inserting stuff bytes into columns 1905        */
/*   through 1920 of each row                                   */
/*   0 = STM64 mode disabled                                    */
/*   1 = STM64 mode enabled                                     */
/*                                                              */
/* The [fpsynce] parameter is specified as:                     */
/*   0                                                          */
/*   1 = The 10G Wrapper uses the 40G frame phase for           */
/*       generating the framing that the incoming data shall be */
/*       wrapped                                                */
/*                                                              */
/* The [c15res_en] parameter is specified as:                   */
/*   Enable extra payload bytes in column 15                    */
/*   0bxx1 = row 1 column 15 is payload                         */
/*   0bx1x = row 2 column 15 is payload                         */
/*   0b1xx = row 3 column 15 is payload                         */
/*                                                              */
/* The [g43md] parameter is specified as:                       */
/*   0                                                          */
/*   1 = G43MD mode: In this mode, The 'Mapping & Concatenation */
/*       Specific' Bits of the OPU Overhead (Bytes 1, 2, and 3  */
/*       of column 15 and all of column 16) are used to carry   */
/*       data. When this bit is active, C15RES_EN and JC_PLUS   */
/*       are ignored.                                           */
/*                                                              */
/* The [wrmd] parameter is specified as:                        */
/*   Mode of operation for OxU2 Wrapper:                        */
/*   0b00 = Wrapper off; bypass data and timing signals         */
/*   0b01 = Wrapper on                                          */
/*   0b10 = Wrapper off                                         */
/*   0b11 = Wrapper on; map short to long frame (ODU to OTU)    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_WRPCFG3_t tmp_otnt_wrpcfg3;
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
      tmp_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3));
      tmp_otnt_wrpcfg3.bf.STM64MD = stm64md;
      tmp_otnt_wrpcfg3.bf.FPSYNCE = fpsynce;
      tmp_otnt_wrpcfg3.bf.C15RES_EN = c15res_en;
      tmp_otnt_wrpcfg3.bf.G43MD = g43md;
      tmp_otnt_wrpcfg3.bf.WRMD = wrmd;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3), tmp_otnt_wrpcfg3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET WRAPPER CONFIGURATION REGISTER 4    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_otnt_wrpcfg4(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_uint16 jc_plus_odtu23, 
                                    cs_uint16 jc_plus_otu2, 
                                    cs_uint16 jcen_dt, 
                                    cs_uint16 jcen_odtu23, 
                                    cs_uint16 jcen_otu2)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o JC PLUS ODTU23                                */
/*              o JC PLUS OTU2                                  */
/*              o JCEN DT                                       */
/*              o JCEN ODTU23                                   */
/*              o JCEN OTU2                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the OTNT Wrapper Configuration Register */
/* 4.                                                           */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [jc_plus_odtu23] parameter is specified as:              */
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
/* The [jc_plus_otu2] parameter is specified as:                */
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
/* The [jcen_dt] parameter is specified as:                     */
/*   0                                                          */
/*   1 = The OTU3 Justification performs 35.45 ppm              */
/*       data rate adjustment (determisnistic justification)    */
/*       by occasionally inserting gaps into the first PJO      */
/*       (35.45 ppm = 239/237 : 238/236 = 56404 : 56406 )       */
/*       Note: Every 2 OTU3 frames by 35.45 ppm or every 4      */
/*       OTU2 frames by 17.6 ppm in DWNCLK mode.                */
/*                                                              */
/* The [jcen_odtu23] parameter is specified as:                 */
/*   0   ODTU23 Justification unit is disabled                  */
/*   1 = ODTU23 Justification unit is enabled                   */
/*                                                              */
/* The [jcen_otu2] parameter is specified as:                   */
/*   0 = OTU2 Justification unit is disabled                    */
/*   1 = OTU2 Justification unit is enabled                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_WRPCFG4_t tmp_otnt_wrpcfg4;
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
      tmp_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG4));
      tmp_otnt_wrpcfg4.bf.JC_PLUS_ODTU23 = jc_plus_odtu23;
      tmp_otnt_wrpcfg4.bf.JC_PLUS_OTU2 = jc_plus_otu2;
      tmp_otnt_wrpcfg4.bf.JCEN_DT = jcen_dt;
      tmp_otnt_wrpcfg4.bf.JCEN_ODTU23 = jcen_odtu23;
      tmp_otnt_wrpcfg4.bf.JCEN_OTU2 = jcen_otu2;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG4), tmp_otnt_wrpcfg4.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET FIXED STUFF BYTE REGISTER      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_wrpfs(cs_uint16 module_id,
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
  TEN_N10G_OTNT_WRPFS_t tmp_otnt_wrpfs;
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
      tmp_otnt_wrpfs.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPFS));
      tmp_otnt_wrpfs.bf.FS = fs;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPFS), tmp_otnt_wrpfs.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT SCRAMBLING                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_scrambling(cs_uint16 module_id, cs_uint8 slice, 
                         cs_uint16 postscr, 
                         cs_uint16 prescr)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o POSTSCR                                           */
/*              o PRESCR                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets OxU scrambler enable.                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [postscr]  POST-FEC. Used only for OTU.                        */
/*     0 = Descrambler disabled (GFEC or ODU2 or test purpose)      */
/*     1 = Descrambler enabled (UFEC only)                          */
/*                                                                  */
/*   [prescr]  Pre-FEC. Used for both OTU and ODU.                  */
/*     0 = Descrambler disabled (UFEC or test purpose)              */
/*     1 = Descrambler enabled (GFEC or ODU2).                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_OCFG_t tmp_otnt_ocfg;
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
      tmp_otnt_ocfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OCFG));
      tmp_otnt_ocfg.bf.POSTSCR = postscr;
      tmp_otnt_ocfg.bf.PRESCR = prescr;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OCFG), tmp_otnt_ocfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT MFMCFG                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_mfmcfg(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint8 match_unit, 
                               cs_uint16 mfmcmp, 
                               cs_uint16 mfmmsk)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Match Unit                                        */
/*              o MFMCMP                                           */
/*              o MFMMSK                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the specified MFAS Match unit.                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [match_unit]  MFAS Match unit = 1-11                           */
/*                                                                  */
/*   [mfmcmp]  Comparison reference for MFAS Match unit             */
/*                                                                  */
/*   [mfmmsk]  Mask for MFAS Match unit.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_MFMCFG1_t tmp_otnt_mfmcfg1;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if ((match_unit > 11) || (!match_unit)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": match unit out of range.  s/b 1..11.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_N10G_REG_ADDR(pDev, module_id, sl, MFMCFG1);
      tmp_addr += match_unit - 1;
      tmp_otnt_mfmcfg1.wrd = TEN_REG_READ(tmp_addr);
      tmp_otnt_mfmcfg1.bf.MFM1CMP = mfmcmp;
      tmp_otnt_mfmcfg1.bf.MFM1MSK = mfmmsk;
      TEN_REG_WRITE(tmp_addr, tmp_otnt_mfmcfg1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  N10G OTNT CONFIG                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_ocfg(cs_uint16 module_id, cs_uint8 slice, 
                         cs_boolean fecmd, 
                         cs_boolean fecen)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o FECMD                                             */
/*              o FECEN                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* OxU2 OTNT Configuration.                                         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [fecmd]  Ultra FEC enable:                                     */
/*     0 = GFEF enabled                                             */
/*     1 = UFEC enabled                                             */
/*                                                                  */
/*   [fecen]  FEC bypass enable. Should be set to zero with ODU.    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_OCFG_t tmp_otnt_ocfg;
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
      tmp_otnt_ocfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OCFG));
      tmp_otnt_ocfg.bf.FECMD = fecmd & 0x01;
      tmp_otnt_ocfg.bf.FECEN = fecen;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OCFG), tmp_otnt_ocfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET PTI BYTE                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_pti_byte(cs_uint16 module_id,
                                     cs_uint8 slice, 
                                     cs_uint16 pti)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Insertion PTI Byte                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Specifies the Payload Type Identifier to be inserted into    */
/* row 4, column 15 (when internal MFAS counter is at '0' and   */
/* PTIE is set to enable).                                      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [pti] parameter is specified as                          */
/*   Insertion Payload Type Identifier Byte                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_CFG2_t tmp_otnt_cfg2;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n10g_otnt_set_pti_byte";  
  
  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  CS_PRINT("%s() %s, pti=%d", func, ten_module_strings[module_id & 1], pti);
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT(", SLICE_ALL\n");
  } else {  
    CS_PRINT(", %s\n", ten_slice_strings[slice]);
  }  
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG2));
      tmp_otnt_cfg2.bf.PTI = pti;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG2), tmp_otnt_cfg2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT CFG4                                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_cfg4(cs_uint16 module_id, cs_uint8 slice, 
                         cs_uint16 bipxor, 
                         cs_uint16 bipmsk)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o BIPXOR                                            */
/*              o BIPMSK                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets BIPXOR and BIPMSK Values.                                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [bipxor]  Specifies the target location for inserting the      */
/*     XORed result of the calculated BIP-8 and the value delivered */
/*     by the Centralized Overhead Processor.                       */
/*                                                                  */
/*   [bipmsk]  Specifies the target location for inserting the      */
/*     calculated BIP-8 value:                                      */
/*     When BIPMSK[0] is set, BIP-8 will be updated in the          */
/*     respective Path Monitoring frame field.                      */
/*     When BIPMSK[7] is set, BIP-8 will be updated in the          */
/*     respective Section Monitoring frame field.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_CFG4_t tmp_otnt_cfg4;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_cfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG4));
      tmp_otnt_cfg4.bf.BIPXOR = bipxor;
      tmp_otnt_cfg4.bf.BIPMSK = bipmsk;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG4), tmp_otnt_cfg4.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET BIPMSK                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_bipmsk(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 bipmsk)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o BIPMSK                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets BIPMSK Values.                                          */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/*                                                              */
/*   [bipmsk]  Specifies the target location for inserting the  */
/*     calculated BIP-8 value:                                  */
/*     When BIPMSK[0] is set, BIP-8 will be updated in the      */
/*     respective Path Monitoring frame field.                  */
/*     When BIPMSK[7] is set, BIP-8 will be updated in the      */
/*     respective Section Monitoring frame field.               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_CFG4_t tmp_otnt_cfg4;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_cfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG4));
      tmp_otnt_cfg4.bf.BIPMSK = bipmsk;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG4), tmp_otnt_cfg4.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT SET APSPCC                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_set_apspcc(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint8 channel, 
                                 cs_uint16 apspcc1,
                                 cs_uint16 apspcc0)


/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Channel                                           */
/*              o APSPCC1                                           */
/*              o APSPCC0                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value to be inserted in first three APS/PCC bytes for       */
/* selected channel (when bit CFG3.APSINS0 is set).                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [channel]  0..7                                                */
/*                                                                  */
/*   [apspcc1]  MSB                                                 */
/*                                                                  */
/*   [apspcc0]  LSB                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_APSPCC01_t tmp_otnt_apspcc01;
  TEN_N10G_OTNT_APSPCC00_t tmp_otnt_apspcc00;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if (channel > 7) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": channel out of range.  s/b 0..7.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_apspcc01.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, APSPCC01) + 
                              2 * channel);
      tmp_otnt_apspcc01.bf.APSPCC01 = apspcc1;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, APSPCC01) + 2 * channel, 
                                      tmp_otnt_apspcc01.wrd);
                    
      tmp_otnt_apspcc00.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, APSPCC00) + 
                              2 * channel);
      tmp_otnt_apspcc00.bf.APSPCC00 = apspcc0;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, APSPCC00) + 2 * channel, 
                                      tmp_otnt_apspcc00.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT GET LOM STATUS                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_boolean ten_n10g_otnt_get_lom_status(cs_uint16 module_id,
                                   cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : LOM Status (TRUE if MFAS lost, FALSE if not)    */
/* DESCRIPTION:                                                 */
/* Returns the loss of Multiframe Alignment Signal status.      */
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
  TEN_N10G_OTNT_LOMSTAT_t tmp_otnt_lomstat;
  T41_t                      *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  tmp_otnt_lomstat.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, LOMSTAT));

  return (tmp_otnt_lomstat.bf.LOMS == 1) ;
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET OTNT JUSTIFICATION COMMAND ODTU23   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_jc_odtu23(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 jc_plus_odtu23, 
                                      cs_uint16 jcen_dt, 
                                      cs_uint16 jcen_odtu23)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o JC PLUS ODTU23                                */
/*              o JCEN DT                                       */
/*              o JCEN ODTU23                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the OTNT Wrapper Configuration Register */
/* 4.                                                           */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [jc_plus_odtu23] parameter is specified as:              */
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
/* The [jcen_dt] parameter is specified as:                     */
/*   0                                                          */
/*   1 = The OTU3 Justification performs 35.45 ppm              */
/*       data rate adjustment (determisnistic justification)    */
/*       by occasionally inserting gaps into the first PJO      */
/*       (35.45 ppm = 239/237 : 238/236 = 56404 : 56406 )       */
/*       Note: Every 2 OTU3 frames by 35.45 ppm or every 4      */
/*       OTU2 frames by 17.6 ppm in DWNCLK mode.                */
/*                                                              */
/* The [jcen_odtu23] parameter is specified as:                 */
/*   0   ODTU23 Justification unit is disabled                  */
/*   1 = ODTU23 Justification unit is enabled                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_WRPCFG4_t tmp_otnt_wrpcfg4;
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
      tmp_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG4));
      tmp_otnt_wrpcfg4.bf.JC_PLUS_ODTU23 = jc_plus_odtu23;
      tmp_otnt_wrpcfg4.bf.JCEN_DT = jcen_dt;
      tmp_otnt_wrpcfg4.bf.JCEN_ODTU23 = jcen_odtu23;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG4), tmp_otnt_wrpcfg4.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET OTNT JCEN_DT                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_jcen_dt(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_uint16 jcen_dt)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o JCEN DT                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the OTNT Wrapper Configuration Register */
/* 4.                                                           */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [jcen_dt] parameter is specified as:                     */
/*   0                                                          */
/*   1 = The OTU3 Justification performs 35.45 ppm              */
/*       data rate adjustment (determisnistic justification)    */
/*       by occasionally inserting gaps into the first PJO      */
/*       (35.45 ppm = 239/237 : 238/236 = 56404 : 56406 )       */
/*       Note: Every 2 OTU3 frames by 35.45 ppm or every 4      */
/*       OTU2 frames by 17.6 ppm in DWNCLK mode.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_WRPCFG4_t tmp_otnt_wrpcfg4;
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
      tmp_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG4));
      tmp_otnt_wrpcfg4.bf.JCEN_DT = jcen_dt;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG4), tmp_otnt_wrpcfg4.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET WRAPPER MODE                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_wrmd(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_uint16 wrmd)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o WRMD                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set various aspects of the Wrapper Configuration.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [wrmd] parameter is specified as:                        */
/*   Mode of operation for OxU2 Wrapper:                        */
/*   0b00 = Wrapper off; bypass data and timing signals         */
/*   0b01 = Wrapper on                                          */
/*   0b10 = Wrapper off                                         */
/*   0b11 = Wrapper on; map short to long frame (ODU to OTU)    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_WRPCFG3_t tmp_otnt_wrpcfg3;
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
      tmp_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3));
      tmp_otnt_wrpcfg3.bf.WRMD = wrmd;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3), tmp_otnt_wrpcfg3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET G43 Mode                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_g43md(cs_uint16 module_id,
                                  cs_uint8 slice,  
                                  cs_uint16 g43md)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o G43MD                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set various aspects of the Wrapper Configuration.            */
/*                                                              */
/* The [g43md] parameter is specified as:                       */
/*   0 = G43MD off                                              */
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
  TEN_N10G_OTNT_WRPCFG3_t tmp_otnt_wrpcfg3;
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
      tmp_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3));
      tmp_otnt_wrpcfg3.bf.G43MD = g43md;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3), tmp_otnt_wrpcfg3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT DOAIE                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_doaie(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint8  byte,
                                cs_uint16 insertion)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Byte                                              */
/*              o Insertion                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Direct Overhead Access Insert Enable for the specified      */
/* overhead byte.                                                   */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)        */
/*                                                                  */
/* [byte] parameter is specified as:                                */
/*   TEN_OTNOH_FAOH_BYTE1           = 0                             */
/*   TEN_OTNOH_FAOH_BYTE2           = 1                             */
/*   TEN_OTNOH_FAOH_BYTE3           = 2                             */
/*   TEN_OTNOH_FAOH_BYTE4           = 3                             */
/*   TEN_OTNOH_FAOH_BYTE5           = 4                             */
/*   TEN_OTNOH_FAOH_BYTE6           = 5                             */
/*   TEN_OTNOH_FAOH_BYTE7           = 6                             */
/*   TEN_OTNOH_OTUKOH_BYTE1         = 7                             */
/*   TEN_OTNOH_OTUKOH_BYTE2         = 8                             */
/*   TEN_OTNOH_OTUKOH_BYTE3         = 9                             */
/*   TEN_OTNOH_OTUKOH_BYTE4         = 10                            */
/*   TEN_OTNOH_OTUKOH_BYTE5         = 11                            */
/*   TEN_OTNOH_OTUKOH_BYTE6         = 12                            */
/*   TEN_OTNOH_OTUKOH_BYTE7         = 13                            */
/*   TEN_OTNOH_OPUKOH_BYTE1         = 14                            */
/*   TEN_OTNOH_OPUKOH_BYTE2         = 15                            */
/*                                                                  */
/*   TEN_OTNOH_RES_BYTE1            = 16                            */
/*   TEN_OTNOH_RES_BYTE2            = 17                            */
/*   TEN_OTNOH_RES_BYTE3            = 18                            */
/*   TEN_OTNOH_TCMACT               = 19                            */
/*   TEN_OTNOH_TCM6_BYTE1           = 20                            */
/*   TEN_OTNOH_TCM6_BYTE2           = 21                            */
/*   TEN_OTNOH_TCM6_BYTE3           = 22                            */
/*   TEN_OTNOH_TCM5_BYTE1           = 23                            */
/*   TEN_OTNOH_TCM5_BYTE2           = 24                            */
/*   TEN_OTNOH_TCM5_BYTE3           = 25                            */
/*   TEN_OTNOH_TCM4_BYTE1           = 26                            */
/*   TEN_OTNOH_TCM4_BYTE2           = 27                            */
/*   TEN_OTNOH_TCM4_BYTE3           = 28                            */
/*   TEN_OTNOH_FTFL                 = 29                            */
/*   TEN_OTNOH_OPUKOH_BYTE3         = 30                            */
/*   TEN_OTNOH_OPUKOH_BYTE4         = 31                            */
/*                                                                  */
/*   TEN_OTNOH_TCM3_BYTE1           = 32                            */
/*   TEN_OTNOH_TCM3_BYTE2           = 33                            */
/*   TEN_OTNOH_TCM3_BYTE3           = 34                            */
/*   TEN_OTNOH_TCM2_BYTE1           = 35                            */
/*   TEN_OTNOH_TCM2_BYTE2           = 36                            */
/*   TEN_OTNOH_TCM2_BYTE3           = 37                            */
/*   TEN_OTNOH_TCM1_BYTE1           = 38                            */
/*   TEN_OTNOH_TCM1_BYTE2           = 39                            */
/*   TEN_OTNOH_TCM1_BYTE3           = 40                            */
/*   TEN_OTNOH_PM_BYTE1             = 41                            */
/*   TEN_OTNOH_PM_BYTE2             = 42                            */
/*   TEN_OTNOH_PM_BYTE3             = 43                            */
/*   TEN_OTNOH_EXP_BYTE1            = 44                            */
/*   TEN_OTNOH_EXP_BYTE2            = 45                            */
/*   TEN_OTNOH_OPUKOH_BYTE5         = 46                            */
/*   TEN_OTNOH_OPUKOH_BYTE6         = 47                            */
/*                                                                  */
/*   TEN_OTNOH_GCC1_BYTE1           = 48                            */
/*   TEN_OTNOH_GCC1_BYTE2           = 49                            */
/*   TEN_OTNOH_GCC2_BYTE1           = 50                            */
/*   TEN_OTNOH_GCC2_BYTE2           = 51                            */
/*   TEN_OTNOH_APSPCC_BYTE1         = 52                            */
/*   TEN_OTNOH_APSPCC_BYTE2         = 53                            */
/*   TEN_OTNOH_APSPCC_BYTE3         = 54                            */
/*   TEN_OTNOH_APSPCC_BYTE4         = 55                            */
/*   TEN_OTNOH_RES_BYTE4            = 56                            */
/*   TEN_OTNOH_RES_BYTE5            = 57                            */
/*   TEN_OTNOH_RES_BYTE6            = 58                            */
/*   TEN_OTNOH_RES_BYTE7            = 59                            */
/*   TEN_OTNOH_RES_BYTE8            = 60                            */
/*   TEN_OTNOH_RES_BYTE9            = 61                            */
/*   TEN_OTNOH_OPUKOH_BYTE7         = 62                            */
/*   TEN_OTNOH_OPUKOH_BYTE8         = 63                            */
/*                                                                  */
/* [insertion]  Overhead Data Insertion Control                     */
/*   0 = Never insert overhead byte                                 */
/*   1 = Insert overhead byte when MFM1 is active                   */
/*   2 = Insert overhead byte when MFM2 is active                   */
/*   3 = Insert overhead byte when MFM3 is active.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_uint16 shift;
  cs_uint16 sl;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if ((byte > TEN_OTNOH_OPUKOH_BYTE8) || (insertion > 3)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": parm out of range.");
    rtn = CS_ERROR;
    goto RTN_EXIT;
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      if (byte < (1*8)) {
        TEN_N10G_OTNT_DOAIE0_t tmp_otnt_doaie0;

        tmp_otnt_doaie0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE0));
        shift = (byte - (0*8))*2;
        tmp_otnt_doaie0.bf.DOAIE0 &= ~(3 << shift);       /* mask */
        tmp_otnt_doaie0.bf.DOAIE0 |= insertion << shift;  /* set  */
        
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE0), tmp_otnt_doaie0.wrd);
      }
      else if (byte < (2*8)) {
        TEN_N10G_OTNT_DOAIE1_t tmp_otnt_doaie1;

        tmp_otnt_doaie1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE1));
        shift = (byte - (1*8))*2;
        tmp_otnt_doaie1.bf.DOAIE1 &= ~(3 << shift);       /* mask */
        tmp_otnt_doaie1.bf.DOAIE1 |= insertion << shift;  /* set  */
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE1), tmp_otnt_doaie1.wrd);
      }
      else if (byte < (3*8)) {
        TEN_N10G_OTNT_DOAIE2_t tmp_otnt_doaie2;

        tmp_otnt_doaie2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE2));
        shift = (byte - (2*8))*2;
        tmp_otnt_doaie2.bf.DOAIE2 &= ~(3 << shift);       /* mask */
        tmp_otnt_doaie2.bf.DOAIE2 |= insertion << shift;  /* set  */
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE2), tmp_otnt_doaie2.wrd);
      }
      else if (byte < (4*8)) {
        TEN_N10G_OTNT_DOAIE3_t tmp_otnt_doaie3;

        tmp_otnt_doaie3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE3));
        shift = (byte - (3*8))*2;
        tmp_otnt_doaie3.bf.DOAIE3 &= ~(3 << shift);       /* mask */
        tmp_otnt_doaie3.bf.DOAIE3 |= insertion << shift;  /* set  */
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE3), tmp_otnt_doaie3.wrd);
      }
      else if (byte < (5*8)) {
        TEN_N10G_OTNT_DOAIE4_t tmp_otnt_doaie4;

        tmp_otnt_doaie4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE4));
        shift = (byte - (4*8))*2;
        tmp_otnt_doaie4.bf.DOAIE4 &= ~(3 << shift);       /* mask */
        tmp_otnt_doaie4.bf.DOAIE4 |= insertion << shift;  /* set  */
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE4), tmp_otnt_doaie4.wrd);
      }
      else if (byte < (6*8)) {
        TEN_N10G_OTNT_DOAIE5_t tmp_otnt_doaie5;
        
        tmp_otnt_doaie5.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE5));
        shift = (byte - (5*8))*2;
        tmp_otnt_doaie5.bf.DOAIE5 &= ~(3 << shift);       /* mask */
        tmp_otnt_doaie5.bf.DOAIE5 |= insertion << shift;  /* set  */
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE5), tmp_otnt_doaie5.wrd);
      }
      else if (byte < (7*8)) {
        TEN_N10G_OTNT_DOAIE6_t tmp_otnt_doaie6;

        tmp_otnt_doaie6.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE6));
        shift = (byte - (6*8))*2;
        tmp_otnt_doaie6.bf.DOAIE6 &= ~(3 << shift);       /* mask */
        tmp_otnt_doaie6.bf.DOAIE6 |= insertion << shift;  /* set  */
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE6), tmp_otnt_doaie6.wrd);
      }
      else {
        TEN_N10G_OTNT_DOAIE7_t tmp_otnt_doaie7;
        
        tmp_otnt_doaie7.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE7));
        shift = (byte - (7*8))*2;
        tmp_otnt_doaie7.bf.DOAIE7 &= ~(3 << shift);       /* mask */
        tmp_otnt_doaie7.bf.DOAIE7 |= insertion << shift;  /* set  */
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DOAIE7), tmp_otnt_doaie7.wrd);
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET C15RES_EN                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_c15res_en(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 c15res_en)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o C15RES EN                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set various aspects of the Wrapper Configuration.            */
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
  TEN_N10G_OTNT_WRPCFG3_t tmp_otnt_wrpcfg3;
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
      tmp_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3));
      tmp_otnt_wrpcfg3.bf.C15RES_EN = c15res_en;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3), tmp_otnt_wrpcfg3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET STM64 Mode                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_stm64md(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_uint16 stm64md)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o STM64MD                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set various aspects of the Wrapper Configuration.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [stm64md] parameter is specified as:                     */
/*   STM64 mode, inserting stuff bytes into columns 1905        */
/*   through 1920 of each row                                   */
/*   0 = STM64 mode disabled                                    */
/*   1 = STM64 mode enabled                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_WRPCFG3_t tmp_otnt_wrpcfg3;
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
      tmp_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3));
      tmp_otnt_wrpcfg3.bf.STM64MD = stm64md;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3), tmp_otnt_wrpcfg3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET WRAPPER CONFIGURATION REGISTER 3    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_wrpcfg5(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 stuffbt)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o STUFFBT                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set various aspects of the Wrapper Configuration 5 Register. */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [stuffbt] parameter is specified as:                     */
/*   00-FF hex                                                  */
/*   Configurable Stuff Byte Value. For specific applications   */
/*   that do not make use of data scrambling, the stuff byte    */
/*   may be set to a different value (such as AA hex) to avoid  */
/*   prolonged static all-zeros sequences in the line signal.   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_WRPCFG5_t tmp_otnt_wrpcfg5;
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
      tmp_otnt_wrpcfg5.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG5));
      tmp_otnt_wrpcfg5.bf.STUFFBT = stuffbt;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG5), tmp_otnt_wrpcfg5.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET NCOLS                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_ncols(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 ncols)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o NCOLS                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the OTNT NCOLS parameter.                                */
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
  TEN_N10G_OTNT_WRPCFG0_t tmp_otnt_wrpcfg0;
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
      tmp_otnt_wrpcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG0));
      tmp_otnt_wrpcfg0.bf.NCOLS = ncols;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG0), tmp_otnt_wrpcfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET NPARB AND NPAR                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_nparb_npar(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 nparb, 
                                       cs_uint16 npar)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o NPARB                                         */
/*              o NPAR                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the OTNT NPARB and NPAR parameters.                      */
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
/*   00-1F hex                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_WRPCFG2_t tmp_otnt_wrpcfg2;
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
      tmp_otnt_wrpcfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG2));
      tmp_otnt_wrpcfg2.bf.NPARB = nparb;
      tmp_otnt_wrpcfg2.bf.NPAR = npar;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG2), tmp_otnt_wrpcfg2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET FASIE                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_fasie(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 fasie)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FASIE                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* When set, a FAS pattern of F6F6F6282828 hex will be inserted */
/* in row 1, columns 1 through 6.                               */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [fasie] parameter is specified as:                       */
/*   When set, a FAS pattern of F6F6F6282828 hex will be        */
/*   inserted in row 1, columns 1 through 6.                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_CFG0_t tmp_otnt_cfg0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0));
      tmp_otnt_cfg0.bf.FASIE = fasie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0), tmp_otnt_cfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET PTIE                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_ptie(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 ptie)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PTIE                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* When set, enables Payload Type Identifier insertion.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [ptie] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_CFG0_t tmp_otnt_cfg0;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n10g_otnt_set_ptie";  
  
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  CS_PRINT("%s() %s, ptie=%d", func, ten_module_strings[module_id & 1], ptie);
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT(", SLICE_ALL\n");
  } else {  
    CS_PRINT(", %s\n", ten_slice_strings[slice]);
  }  


  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0));
      tmp_otnt_cfg0.bf.PTIE = ptie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0), tmp_otnt_cfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}




/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET MFASINS                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_mfasins(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 mfasins)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PTIE                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* When set, enables Payload Type Identifier insertion.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mfasins] parameter specifies when the internal MFAS     */
/* count will be inserted into the data stream.                 */
/*   0 Never                                                    */
/*   1 While in LOM state                                       */
/*   2 While not in LOM state                                   */
/*   3 Always                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_CFG0_t tmp_otnt_cfg0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0));
      tmp_otnt_cfg0.bf.MFASINS = mfasins;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0), tmp_otnt_cfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT CFG0 MFASINS                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_cfg0_mfasins(cs_uint16 module_id, cs_uint8 slice, 
                         cs_uint16 mfasins)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o MFASINS                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Specifies when the internal MFAS counter will be inserted into   */
/* the data stream.                                                 */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* [mfasins]  Specified as 0 or 1.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_CFG0_t tmp_otnt_cfg0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0));
      tmp_otnt_cfg0.bf.MFASINS = mfasins;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0), tmp_otnt_cfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT CFG0 MFALGNE                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_cfg0_mfalgne(cs_uint16 module_id, cs_uint8 slice, 
                         cs_uint16 mfalgne)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o MFALGNE                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets MFAS Alignment Enable.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [mfalgne]  Setting this bit to 1 enables the MFAS alignment    */
/*      process.  The received MFAS is processed for LOM and the    */
/*      internal MFAS counter is synchronized to the received MFAS  */
/*      whenever LOM transitions from LOM=1 to LOM=0.               */
/*      Setting this bit to 0 causes the received MFAS to be        */
/*      ignored and the internal MFAS counter operates in free      */
/*      running mode. The LOM state is forced to '1' in this case.  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_CFG0_t tmp_otnt_cfg0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0));
      tmp_otnt_cfg0.bf.MFALGNE = mfalgne;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0), tmp_otnt_cfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT DMCFG1 GEN ENABLE                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_dmcfg1_gen_enable(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 dm_select, cs_uint16 dm_gen_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DM Select                                         */
/*              o DM GEN EN                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Delay Measurement generator enable.                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dm_select]                                                    */
/*     TEN_DM_NONE = 0, (Not Applicable for this API)               */
/*     TEN_DM_PM   = 1, (DMp)                                       */
/*     TEN_DM_TCM6 = 2, (DMt6)                                      */
/*     TEN_DM_TCM5 = 3, (DMt5)                                      */
/*     TEN_DM_TCM4 = 4, (DMt4)                                      */
/*     TEN_DM_TCM3 = 5, (DMt3)                                      */
/*     TEN_DM_TCM2 = 6, (DMt2)                                      */
/*     TEN_DM_TCM1 = 7, (DMt1)                                      */
/*     TEN_DM_RES  = 8, (Reserved, Unused PM&TCM LSB)               */
/*                                                                  */
/*   [dm_gen_en]                                                    */
/*     TEN_DM_INSERTED_FROM_OHPP = 0 (DM inserted from OHPP)        */
/*     TEN_DM_INTERNALLY_GENERATED = 1 (DM internally generated)    */
/*     (Not applicable to the two LSB bits)                         */
/*     TEN_DM_SET_TO_0 = 2 (DM set to 0)                            */
/*     TEN_DM_SET_TO_1 = 3 (DM set to 1)                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_OTNT_DMCFG1_t tmp_otnt_dmcfg1;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  if ((dm_select < TEN_DM_PM) || (dm_select > TEN_DM_RES)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_select out of range.  s/b 1..8.");
    return (CS_ERROR);
  }

  if (dm_gen_en > TEN_DM_SET_TO_1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_gen_en out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_dmcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCFG1));
      
      switch (dm_select) {
      case (TEN_DM_RES):
        tmp_otnt_dmcfg1.bf.DM_GEN_EN &= ~(3<<0);
        tmp_otnt_dmcfg1.bf.DM_GEN_EN |= dm_gen_en<<0;
        break;
        
      case (TEN_DM_PM):
        tmp_otnt_dmcfg1.bf.DM_GEN_EN &= ~(3<<2);
        tmp_otnt_dmcfg1.bf.DM_GEN_EN |= dm_gen_en<<2;
        break;
        
      case (TEN_DM_TCM1):
        tmp_otnt_dmcfg1.bf.DM_GEN_EN &= ~(3<<14);
        tmp_otnt_dmcfg1.bf.DM_GEN_EN |= dm_gen_en<<14;
        break;
        
      case (TEN_DM_TCM2):
        tmp_otnt_dmcfg1.bf.DM_GEN_EN &= ~(3<<12);
        tmp_otnt_dmcfg1.bf.DM_GEN_EN |= dm_gen_en<<12;
        break;
        
      case (TEN_DM_TCM3):
        tmp_otnt_dmcfg1.bf.DM_GEN_EN &= ~(3<<10);
        tmp_otnt_dmcfg1.bf.DM_GEN_EN |= dm_gen_en<<10;
        break;
        
      case (TEN_DM_TCM4):
        tmp_otnt_dmcfg1.bf.DM_GEN_EN &= ~(3<<8);
        tmp_otnt_dmcfg1.bf.DM_GEN_EN |= dm_gen_en<<8;
        break;
        
      case (TEN_DM_TCM5):
        tmp_otnt_dmcfg1.bf.DM_GEN_EN &= ~(3<<6);
        tmp_otnt_dmcfg1.bf.DM_GEN_EN |= dm_gen_en<<6;
        break;
        
      case (TEN_DM_TCM6):
        tmp_otnt_dmcfg1.bf.DM_GEN_EN &= ~(3<<4);
        tmp_otnt_dmcfg1.bf.DM_GEN_EN |= dm_gen_en<<4;
        break;
        
      default:  
      case (TEN_DM_NONE):
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_select out of range.  s/b 0..7.");
        break;
      }
      
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCFG1), tmp_otnt_dmcfg1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT DMCFG2 INSERT ENABLE                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_dmcfg2_insert_enable(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 dm_select, cs_uint16 dm_insert_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DM INSERT EN                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Delay Measurement Insertion Enable.                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dm_select]                                                    */
/*     TEN_DM_NONE = 0, (Clear All)                                 */
/*     TEN_DM_PM   = 1, (DMp)                                       */
/*     TEN_DM_TCM6 = 2, (DMt6)                                      */
/*     TEN_DM_TCM5 = 3, (DMt5)                                      */
/*     TEN_DM_TCM4 = 4, (DMt4)                                      */
/*     TEN_DM_TCM3 = 5, (DMt3)                                      */
/*     TEN_DM_TCM2 = 6, (DMt2)                                      */
/*     TEN_DM_TCM1 = 7, (DMt1)                                      */
/*     TEN_DM_RES  = 8, (Reserved, Unused PM&TCM LSB)               */
/*                                                                  */
/*   [dm_insert_en]                                                 */
/*     0 (clear)                                                    */
/*     1 (set)                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_OTNT_DMCFG2_t tmp_otnt_dmcfg2;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if (dm_select > TEN_DM_RES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_select out of range.  s/b 0..8.");
    return (CS_ERROR);
  }

  if (dm_insert_en > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_insert_en out of range.  s/b 0..1.");
    return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_dmcfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCFG2));
       
      switch (dm_select) {
      case (TEN_DM_RES):
       tmp_otnt_dmcfg2.bf.DM_INSERT_EN &= ~(1<<0);
       tmp_otnt_dmcfg2.bf.DM_INSERT_EN |= dm_insert_en<<0;
        break;
        
      case (TEN_DM_PM):
         tmp_otnt_dmcfg2.bf.DM_INSERT_EN &= ~(1<<1);
         tmp_otnt_dmcfg2.bf.DM_INSERT_EN |= dm_insert_en<<1;
        break;
        
      case (TEN_DM_TCM1):
         tmp_otnt_dmcfg2.bf.DM_INSERT_EN &= ~(1<<7);
         tmp_otnt_dmcfg2.bf.DM_INSERT_EN |= dm_insert_en<<7;
        break;
        
      case (TEN_DM_TCM2):
         tmp_otnt_dmcfg2.bf.DM_INSERT_EN &= ~(1<<6);
         tmp_otnt_dmcfg2.bf.DM_INSERT_EN |= dm_insert_en<<6;
        break;
        
      case (TEN_DM_TCM3):
         tmp_otnt_dmcfg2.bf.DM_INSERT_EN &= ~(1<<5);
         tmp_otnt_dmcfg2.bf.DM_INSERT_EN |= dm_insert_en<<5;
        break;
        
      case (TEN_DM_TCM4):
         tmp_otnt_dmcfg2.bf.DM_INSERT_EN &= ~(1<<4);
         tmp_otnt_dmcfg2.bf.DM_INSERT_EN |= dm_insert_en<<4;
        break;
        
      case (TEN_DM_TCM5):
        tmp_otnt_dmcfg2.bf.DM_INSERT_EN &= ~(1<<3);
        tmp_otnt_dmcfg2.bf.DM_INSERT_EN |= dm_insert_en<<3;
        break;
        
      case (TEN_DM_TCM6):
        tmp_otnt_dmcfg2.bf.DM_INSERT_EN &= ~(1<<2);
        tmp_otnt_dmcfg2.bf.DM_INSERT_EN |= dm_insert_en<<2;
        break;
        
      case (TEN_DM_NONE):
        tmp_otnt_dmcfg2.bf.DM_INSERT_EN = 0;
        break;
        
      default:  
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_select out of range.  s/b 0..8.");
        break;
      }
       
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCFG2), tmp_otnt_dmcfg2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT DMCSFCFG AUTO CSF ENABLE               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_dmcsfcfg_auto_csf_enable(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 auto_csf_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o AUTO CSF EN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Delay Measurement Auto CSF Enable.                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [auto_csf_en]                                                  */
/*     Enable automatic insertion from the SFU of the CSF alarm     */
/*     into bit 1 of the PSI[2] byte                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_OTNT_DMCSFCFG_t tmp_otnt_dmcsfcfg;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_dmcsfcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCSFCFG));
      tmp_otnt_dmcsfcfg.bf.AUTO_CSF_EN = auto_csf_en;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCSFCFG), tmp_otnt_dmcsfcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT DMCSFCFG CSF FORCE                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_dmcsfcfg_csf_force(cs_uint16 module_id, cs_uint8 slice, 
                                           cs_uint16 csf_force)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o CSF FORCE                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Delay Measurement CSF Force.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [csf_force]                                                    */
/*     Sets bit 1 of the PSI[2] byte                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_OTNT_DMCSFCFG_t tmp_otnt_dmcsfcfg;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_dmcsfcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCSFCFG));
      tmp_otnt_dmcsfcfg.bf.CSF_FORCE = csf_force;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCSFCFG), tmp_otnt_dmcsfcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT DMCSFCFG DM TRIGGER                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_dmcsfcfg_dm_trigger(cs_uint16 module_id, cs_uint8 slice) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Forces an Edge sensitive DM trigger.                             */
/* (0-to-1 or 1-to-0 transition).                                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_OTNT_DMCSFCFG_t tmp_otnt_dmcsfcfg;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_dmcsfcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCSFCFG));
      tmp_otnt_dmcsfcfg.bf.DM_TRIG = (tmp_otnt_dmcsfcfg.bf.DM_TRIG == 1) ? 0 : 1;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCSFCFG), tmp_otnt_dmcsfcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT DMCSFCFG SEL                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_dmcsfcfg_sel(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 dm_select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DM SEL                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets DM trigger select.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dm_select]                                                    */
/*     TEN_DM_NONE = 0, (None Selected)                             */
/*     TEN_DM_PM   = 1, (DMp)                                       */
/*     TEN_DM_TCM6 = 2, (DMt6)                                      */
/*     TEN_DM_TCM5 = 3, (DMt5)                                      */
/*     TEN_DM_TCM4 = 4, (DMt4)                                      */
/*     TEN_DM_TCM3 = 5, (DMt3)                                      */
/*     TEN_DM_TCM2 = 6, (DMt2)                                      */
/*     TEN_DM_TCM1 = 7, (DMt1)                                      */
/*     TEN_DM_RES  = 8, (Not Applicable for this API)               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_OTNT_DMCSFCFG_t tmp_otnt_dmcsfcfg;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if (dm_select > TEN_DM_TCM1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_select out of range.  s/b 0..7.");
    return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_dmcsfcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCSFCFG));
      tmp_otnt_dmcsfcfg.bf.DM_SEL = dm_select;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DMCSFCFG), tmp_otnt_dmcsfcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT STATCFG                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_statcfg(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 tcmpm, 
                                cs_uint16 tcmpmstat, 
                                cs_uint16 tcmpmstatinsmd)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o TCMPM                                             */
/*              o TCMPMSTAT                                         */
/*              o TCMPMSTATINSMD                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets STAT Overhead Configuration.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tcmpm]                                                        */
/*      TEN_OOHR_PATH_LAYER = 2                                     */
/*      TEN_OOHR_TCM1_LAYER = 3                                     */
/*      TEN_OOHR_TCM2_LAYER = 4                                     */
/*      TEN_OOHR_TCM3_LAYER = 5                                     */
/*      TEN_OOHR_TCM4_LAYER = 6                                     */
/*      TEN_OOHR_TCM5_LAYER = 7                                     */
/*      TEN_OOHR_TCM6_LAYER = 8                                     */
/*                                                                  */
/*   [tcmpmstat]                                                    */
/*      Value is inserted into the STAT field of the TCMPM overhead */
/*      when TCMPMSTATINSMD={4..7}, otherwise set to '0'.           */
/*                                                                  */
/*   [tcmpmstatinsmd]                                               */
/*      TCM1 STAT field insertion mode.                             */
/*      Note: CFG3.MS_OH_INS must be set to '1' for modes           */
/*      which enable MS pattern insertion (modes 1, 3, 5, and 7).   */
/*      Use API ten_n10g_otnt_cfg3_ms_oh_ins.                       */
/*      0 = Insertion from OHPP,otherwise pass-through from RX      */
/*      1 = MS pattern if MS insertion asserted by SFU,             */
/*          otherwise pass-through                                  */
/*      2 = '010' if IAE consequent action asserted by SFU,         */
/*          otherwise pass-through                                  */ 
/*      3 = '010' if IAE consequent action asserted by SFU,         */
/*          otherwise MS pattern if MS insertion asserted by SFU,   */
/*          otherwise pass-through.                                 */
/*      4 = TCM1STAT                                                */
/*      5 = MS pattern if MS insertion asserted by SFU,             */
/*          otherwise TCM1STAT                                      */
/*      6 = '010' if IAE consequent action asserted by SFU,         */
/*           otherwise TCM1STAT                                     */
/*      7 = '010' if IAE consequent action asserted by SFU,         */
/*           otherwise MS pattern if MS insertion asserted by SFU,  */
/*           otherwise TCM1STAT.                                    */ 
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_OTNT_STATCFG0_t tmp_otnt_statcfg0;
  TEN_N10G_OTNT_STATCFG1_t tmp_otnt_statcfg1;
  TEN_N10G_OTNT_STATCFG2_t tmp_otnt_statcfg2;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
 
  if ((tcmpm < TEN_OOHR_PATH_LAYER) || (tcmpm > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": tcmpm out of range.  s/b 2..8.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
    
      switch (tcmpm) {
      case (TEN_OOHR_PATH_LAYER):
        tmp_otnt_statcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG0));
        tmp_otnt_statcfg0.bf.PMSTATINSMD = tcmpmstatinsmd;
        tmp_otnt_statcfg0.bf.PMSTAT = tcmpmstat;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG0), tmp_otnt_statcfg0.wrd);
        break;
      
      case (TEN_OOHR_TCM1_LAYER):
        tmp_otnt_statcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG0));
        tmp_otnt_statcfg0.bf.TCM1STATINSMD = tcmpmstatinsmd;
        tmp_otnt_statcfg0.bf.TCM1STAT = tcmpmstat;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG0), tmp_otnt_statcfg0.wrd);
        break;
      
      case (TEN_OOHR_TCM2_LAYER):
        tmp_otnt_statcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG0));
        tmp_otnt_statcfg0.bf.TCM2STAT = tcmpmstat;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG0), tmp_otnt_statcfg0.wrd);
        
        tmp_otnt_statcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG1));
        tmp_otnt_statcfg1.bf.TCM2STATINSMD = tcmpmstatinsmd;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG1), tmp_otnt_statcfg1.wrd);
        break;
      
      case (TEN_OOHR_TCM3_LAYER):
        tmp_otnt_statcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG1));
        tmp_otnt_statcfg1.bf.TCM3STATINSMD = tcmpmstatinsmd;
        tmp_otnt_statcfg1.bf.TCM3STAT = tcmpmstat;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG1), tmp_otnt_statcfg1.wrd);
        break;
      
      case (TEN_OOHR_TCM4_LAYER):
        tmp_otnt_statcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG1));
        tmp_otnt_statcfg1.bf.TCM4STATINSMD = tcmpmstatinsmd;
        tmp_otnt_statcfg1.bf.TCM4STAT = tcmpmstat;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG1), tmp_otnt_statcfg1.wrd);
        break;
      
      case (TEN_OOHR_TCM5_LAYER):
        tmp_otnt_statcfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG2));
        tmp_otnt_statcfg2.bf.TCM5STATINSMD = tcmpmstatinsmd;
        tmp_otnt_statcfg2.bf.TCM5STAT = tcmpmstat;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG2), tmp_otnt_statcfg2.wrd);
        break;
      
      case (TEN_OOHR_TCM6_LAYER):
        tmp_otnt_statcfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG2));
        tmp_otnt_statcfg2.bf.TCM6STATINSMD = tcmpmstatinsmd;
        tmp_otnt_statcfg2.bf.TCM6STAT = tcmpmstat;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, STATCFG2), tmp_otnt_statcfg2.wrd);
        break;
        
      default:
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": tcmpm out of range.");
        break;
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G OTNT CFG3 MS OH INS                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_cfg3_ms_oh_ins(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 ms_oh_ins)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o MS OH INS                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control Maintenance Signal Overhead Insertion Enable.            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ms_oh_ins]                                                    */
/*    0 = Insert MS pattern in payload only                         */
/*    1 = Insert MS pattern in payload and ODUk/OPUk overhead       */
/*        (Overhead insertion from OHPP or registers still has      */
/*         higher priority)                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_OTNT_CFG3_t tmp_otnt_cfg3;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_cfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG3));
      tmp_otnt_cfg3.bf.MS_OH_INS = ms_oh_ins;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG3), tmp_otnt_cfg3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}
  
/********************************************************************/
/* $rtn_hdr_start  N10G OTNT CFG3 APS INS EN                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_otnt_cfg3_aps_ins_en(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint8 aps_chan_num, 
                                        cs_uint16 aps_ins_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Aps Chan Num                                      */
/*              o Aps Ins En                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure Aps Insert Enable                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [aps_chan_num]                                                 */
/*     Channel number 0 to 7                                        */
/*                                                                  */
/*   [aps_ins_en]                                                   */
/*     0 = Insert disable                                           */
/*     1 = Insert enable                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_OTNT_CFG3_t tmp_otnt_cfg3;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range. s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnt_cfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG3));

      switch (aps_chan_num) {
          case 0:
              tmp_otnt_cfg3.bf.APSIE0 = aps_ins_en;
              break;

          case 1:
              tmp_otnt_cfg3.bf.APSIE1 = aps_ins_en;
              break;

          case 2: 
              tmp_otnt_cfg3.bf.APSIE2 = aps_ins_en;
              break;

          case 3:  
              tmp_otnt_cfg3.bf.APSIE3 = aps_ins_en;
              break;

          case 4: 
              tmp_otnt_cfg3.bf.APSIE4 = aps_ins_en;
              break;

          case 5:  
              tmp_otnt_cfg3.bf.APSIE5 = aps_ins_en;
              break;

          case 6:  
              tmp_otnt_cfg3.bf.APSIE6 = aps_ins_en;
              break;

          case 7: 
              tmp_otnt_cfg3.bf.APSIE7 = aps_ins_en;
              break;

          default:
              TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
              CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": aps_chan_num out of range. s/b 0..7.");
              return (CS_ERROR);
      }

      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG3), tmp_otnt_cfg3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/* Bugzilla 43359 Start */
/****************************************************************/
/* $rtn_hdr_start  N10G OTNT SET MST FPSYNC                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnt_set_mst_fpsync(cs_uint16 module_id,
                                       cs_uint8 slice, 
                                       cs_uint16 mst_fpsynce)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o MST_FPSYNCE                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* 10G wrapper uses 40G TX frame phase to generate framing that */
/* the incoming data shall be wrapped in                        */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mst_fpsynce] parameter is specified as:                 */
/*   0 = Do not use 40G TX frame phase                          */
/*   1 = Use 40G TX frame phase                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_OTNT_WRPCFG3_t tmp_otnt_wrpcfg3;
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
      tmp_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3));
      tmp_otnt_wrpcfg3.bf.MST_FPSYNCE = mst_fpsynce;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3), tmp_otnt_wrpcfg3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}
/* Bugzilla 43359 End */
