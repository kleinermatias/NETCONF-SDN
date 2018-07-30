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
 * ten_n40g_otnt4x.c
 *
 * N40G related code is implemented here.
 *
 * $Id: ten_n40g_otnt4x.c,v 1.23 2013/04/05 20:58:08 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N40G GET LOM STATUS                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_boolean ten_n40g_get_lom_status(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE (LOM occurred) or FALSE (No LOM occurred)  */
/* DESCRIPTION:                                                 */
/* This bit is set to logic one when Loss of Multiframe         */
/* Alignment Signal defect occurs.                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_LOMSTAT_t tmp_otnt4x_lomstat;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  tmp_otnt4x_lomstat.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, LOMSTAT));

  return (tmp_otnt4x_lomstat.bf.LOMS == 1);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET PTI BYTE                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_pti_byte(cs_uint16 module_id, 
                                cs_uint16 pti)
/* INPUTS     : o Module Id                                     */
/*              o Insertion PTI Byte                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Payload Type Identifier (PTI).                       */
/*                                                              */
/* The [pti] parameter is specified as following:               */
/*   Insertion PTI Byte                                         */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  TEN_N40G_OTNT4X_CFG2_t tmp_otnt4x_cfg2;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_set_pti_byte";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  CS_PRINT("%s() %s, pti=0x%X\n", func, ten_module_strings[module_id & 1], pti);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_cfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG2));
  tmp_otnt4x_cfg2.bf.PTI = pti;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG2), tmp_otnt4x_cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET WRAPPER SET FRAME FORMAT            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_frame_format(cs_uint16 module_id, 
                                           cs_uint16 ncols, 
                                           cs_uint16 nrows,
                                           cs_uint16 nparb, 
                                           cs_uint16 npar)
/* INPUTS     : o Module Id                                     */
/*              o NCOLS                                         */
/*              o NROWS                                         */
/*              o NPARB                                         */
/*              o NPAR                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* NCOLS[9:0] specifies number of columns (or bytes) per OTN    */
/* row (columns = (NCOLS+1)*16). For G.709 OTU-compliant        */
/* framing NCOLS must be set to 254 (4080 columns).             */
/* NROWS[3:0] Specifies number of rows (NROWS+1) per OTN frame. */
/* For G.709 OTUcompliant framing NROWS must be set to 3        */
/* (4 rows).                                                    */
/*                                                              */
/* NPARB[3:0] specifies the number of additional parity bytes   */
/* per OTN row (total number of parity bytes = NPAR*16 + NPARB).*/
/* In most applications NPARB has to be set to zero. Setting    */
/* NPARB to values greater than zero may be used, for example,  */
/* for mapping 10G Ethernet with 4% FEC overhead.               */
/* Note 1: Using FEC with NPARB greater than 0 will only work   */
/* with the enhanced FEC encoder/decoder but not with the       */
/* G.7B09-compliant Reed Solomon FEC encoder/decoder.           */
/* Note 2: Setting NPARB to values greater than 0 will restrict */
/* the functionality of other features. For example, OTU2 to    */
/* ODU2 dewrapping and ODU2 to OTU2 wrapping will not work with */
/* this setup.                                                  */
/* NPAR[6:0] specifies the number of FEC parity columns (or     */
/* bytes) per OTN row (parity bytes = NPAR*16). For G.709-ODU2  */
/* compliant framing NPAR must be set to 0. For G.709-OTU2      */
/* compliant framing NPAR must be set to 16. For OTU2V framing, */
/* NPAR may be set to an appropriate value between 0 and 127.   */
/* Note: The G.709-compliant Reed Solomon FEC encoder/decoder   */
/* works only with NPAR=16.                                     */
/*                                                              */
/* The [ncols] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [nrows] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [nparb] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [npar] parameter is specified as:                        */
/*   0x0000 - 0xFFFF.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG0_t tmp_otnt4x_wrpcfg0;
  TEN_N40G_OTNT4X_WRPCFG2_t tmp_otnt4x_wrpcfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_otnt4x_wrpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG0));
  tmp_otnt4x_wrpcfg0.bf.NCOLS = ncols;
  tmp_otnt4x_wrpcfg0.bf.NROWS = nrows;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG0), tmp_otnt4x_wrpcfg0.wrd);

  tmp_otnt4x_wrpcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG2));
  tmp_otnt4x_wrpcfg2.bf.NPARB = nparb;
  tmp_otnt4x_wrpcfg2.bf.NPAR = npar;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG2), tmp_otnt4x_wrpcfg2.wrd);
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET WRAPPER CONFIGURATION REGISTER 0    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_otnt4x_wrpcfg0(cs_uint16 module_id, 
                                      cs_uint16 ncols, 
                                      cs_uint16 nrows)
/* INPUTS     : o Module Id                                     */
/*              o NCOLS                                         */
/*              o NROWS                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* NCOLS[9:0] specifies number of columns (or bytes) per OTN    */
/* row (columns = (NCOLS+1)*16). For G.709 OTU-compliant        */
/* framing NCOLS must be set to 254 (4080 columns).             */
/* NROWS[3:0] Specifies number of rows (NROWS+1) per OTN frame. */
/* For G.709 OTUcompliant framing NROWS must be set to 3        */
/* (4 rows).                                                    */
/*                                                              */
/* The [ncols] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [nrows] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG0_t tmp_otnt4x_wrpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG0));
  tmp_otnt4x_wrpcfg0.bf.NCOLS = ncols;
  tmp_otnt4x_wrpcfg0.bf.NROWS = nrows;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG0), tmp_otnt4x_wrpcfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET WRAPPER CONFIGURATION REGISTER 2    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_nparb_npar(cs_uint16 module_id, 
                                         cs_uint16 nparb, 
                                         cs_uint16 npar)
/* INPUTS     : o Module Id                                     */
/*              o NPARB                                         */
/*              o NPAR                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* NPARB[3:0] specifies the number of additional parity bytes   */
/* per OTN row (total number of parity bytes = NPAR*16 + NPARB).*/
/* In most applications NPARB has to be set to zero. Setting    */
/* NPARB to values greater than zero may be used, for example,  */
/* for mapping 10G Ethernet with 4% FEC overhead.               */
/* Note 1: Using FEC with NPARB greater than 0 will only work   */
/* with the enhanced FEC encoder/decoder but not with the       */
/* G.7B09-compliant Reed Solomon FEC encoder/decoder.           */
/* Note 2: Setting NPARB to values greater than 0 will restrict */
/* the functionality of other features. For example, OTU2 to    */
/* ODU2 dewrapping and ODU2 to OTU2 wrapping will not work with */
/* this setup.                                                  */
/* NPAR[6:0] specifies the number of FEC parity columns (or     */
/* bytes) per OTN row (parity bytes = NPAR*16). For G.709-ODU2  */
/* compliant framing NPAR must be set to 0. For G.709-OTU2      */
/* compliant framing NPAR must be set to 16. For OTU2V framing, */
/* NPAR may be set to an appropriate value between 0 and 127.   */
/* Note: The G.709-compliant Reed Solomon FEC encoder/decoder   */
/* works only with NPAR=16.                                     */
/*                                                              */
/* The [nparb] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [npar] parameter is specified as:                        */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG2_t tmp_otnt4x_wrpcfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG2));
  tmp_otnt4x_wrpcfg2.bf.NPARB = nparb;
  tmp_otnt4x_wrpcfg2.bf.NPAR = npar;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG2), tmp_otnt4x_wrpcfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET WRAPPER CONFIGURATION REGISTER 3    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpcfg3(cs_uint16 module_id, 
                                      cs_uint16 stm256md, 
                                      cs_uint16 stm64md, 
                                      cs_uint16 aggrmod, 
                                      cs_uint16 wrmd)
/* INPUTS     : o Module Id                                     */
/*              o STM256MD                                      */
/*              o STM64MD                                       */
/*              o AGGRMOD                                       */
/*              o WRMD                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the OTNT4 X Wrapper Configuration       */
/* Register 3.                                                  */
/*                                                              */
/* The [stm256md] parameter is specified as:                    */
/*   0 = STM256 mode disabled                                   */
/*   1 = STM256 mode enabled                                    */
/*                                                              */
/* The [stm64md] parameter is specified as:                     */
/*   0 = STM64 mode disabled                                    */
/*   1 = STM64 mode enabled                                     */
/*                                                              */
/* The [aggrmod] parameter is specified as:                     */
/*   0 = Monolithic wrapping - single client                    */
/*   1 = Aggregation wrapping - quad 1/4-rate client signals    */
/*                                                              */
/* The [wrmd] parameter is:                                     */
/*   0b00 = Wrapper off; bypass data and timing signals         */
/*   0b01 = Wrapper on                                          */
/*   0b10 = Wrapper off                                         */
/*   0b11 = Wrapper on; map short to long frame (ODU to OTU)    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_otnt4x_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
  tmp_otnt4x_wrpcfg3.bf.STM256MD = stm256md;
  tmp_otnt4x_wrpcfg3.bf.STM64MD = stm64md;
  tmp_otnt4x_wrpcfg3.bf.AGGRMOD = aggrmod;
  tmp_otnt4x_wrpcfg3.bf.WRMD = wrmd;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_otnt4x_wrpcfg3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET SCRAMBLING MODE              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_scrambling(cs_uint16 module_id, 
                                     cs_uint16 postscr, 
                                     cs_uint16 prescr)
/* INPUTS     : o Module Id                                     */
/*              o POSTSCR                                       */
/*              o PRESCR                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the OTNT4X scrambling mode.                              */
/*                                                              */
/* The [postscr] parameter is specified as:                     */
/*   OxU Scrambler enable POST-FEC. Used only for OTU.          */
/*   0 = Scrambler disabled                                     */
/*   1 = Scrambler enabled                                      */
/*                                                              */
/* The [prescr] parameter is specified as:                      */
/*   OxU Scrambler enable Pre-FEC. Used for both OTU and ODU.   */
/*   0 = Scrambler disabled                                     */
/*   1 = Scrambler enabled                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_OCFG_t tmp_otnt4x_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_ocfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OCFG));
  tmp_otnt4x_ocfg.bf.POSTSCR = postscr;
  tmp_otnt4x_ocfg.bf.PRESCR = prescr;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OCFG), tmp_otnt4x_ocfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X MFMCFG                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_mfmcfg(cs_uint16 module_id, 
                                 cs_uint8 match_unit, 
                                 cs_uint16 mfmcmp, 
                                 cs_uint16 mfmmsk)
/* INPUTS     : o Module Id                                         */
/*              o Match Unit                                        */
/*              o MFMCMP                                            */
/*              o MFMMSK                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the specified MFAS Match unit.                        */
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
  TEN_N40G_OTNT4X_MFMCFG1_t tmp_otnt4x_mfmcfg1;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  
  if ((match_unit > 11) || (!match_unit)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": match unit out of range.  s/b 1..11.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  /* bugzilla #24439, klocwork */
  tmp_addr = TEN_N40G_REG_ADDR(pDev, module_id, MFMCFG1);
  tmp_addr += match_unit - 1;
  tmp_otnt4x_mfmcfg1.wrd = TEN_REG_READ(tmp_addr);
  tmp_otnt4x_mfmcfg1.bf.MFM1CMP = mfmcmp;
  tmp_otnt4x_mfmcfg1.bf.MFM1MSK = mfmmsk;
  TEN_REG_WRITE(tmp_addr, tmp_otnt4x_mfmcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X CFG4                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_cfg4(cs_uint16 module_id, 
                           cs_uint16 bipxor, 
                           cs_uint16 bipmsk)
/* INPUTS     : o Module Id                                         */
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
  TEN_N40G_OTNT4X_CFG4_t tmp_otnt4x_cfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_cfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG4));
  tmp_otnt4x_cfg4.bf.BIPXOR = bipxor;
  tmp_otnt4x_cfg4.bf.BIPMSK = bipmsk;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG4), tmp_otnt4x_cfg4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X BIPMSK                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_bipmsk(cs_uint16 module_id, 
                                 cs_uint16 bipmsk)
/* INPUTS     : o Module Id                                         */
/*              o BIPMSK                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets BIPXOR and BIPMSK Values.                                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
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
  TEN_N40G_OTNT4X_CFG4_t tmp_otnt4x_cfg4;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnt4x_bipmsk";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  CS_PRINT("%s() line %s, bipmsk=0x%X\n", func, ten_module_strings[module_id&1], bipmsk);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_cfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG4));
  tmp_otnt4x_cfg4.bf.BIPMSK = bipmsk;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG4), tmp_otnt4x_cfg4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT SET APSPCC                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_set_apspcc(cs_uint16 module_id,
                                     cs_uint8 channel, 
                                     cs_uint16 apspcc1,
                                     cs_uint16 apspcc0)


/* INPUTS     : o Module Id                                         */
/*              o Channel                                           */
/*              o APSPCC1                                           */
/*              o APSPCC0                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value to be inserted in first three APS/PCC bytes for       */
/* selected channel (when bit CFG3.APSINS0 is set).                 */
/*                                                                  */
/* The [channel] parameter is specified as                          */
/*   0 - 7                                                          */
/*                                                                  */
/* The [apspcc1] parameter is specified as                          */
/*   0x0000 - 0x00FF = Most Significant Byte                        */
/*                                                                  */
/* The [apspcc0] parameter is specified as                          */
/*   0x0000 - 0xFFFF = Least Significant Bytes                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OTNT4X_APSPCC01_t tmp_otnt_apspcc01;
  TEN_N40G_OTNT4X_APSPCC00_t tmp_otnt_apspcc00;
  T41_t *pDev = NULL;

  if (channel > 7) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": channel out of range.  s/b 0..7.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt_apspcc01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, APSPCC01) + 
                          2 * channel);
  tmp_otnt_apspcc01.bf.APSPCC01 = apspcc1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, APSPCC01) + 2 * channel, 
                                  tmp_otnt_apspcc01.wrd);
                    
  tmp_otnt_apspcc00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, APSPCC00) + 
                          2 * channel);
  tmp_otnt_apspcc00.bf.APSPCC00 = apspcc0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, APSPCC00) + 2 * channel, 
                                  tmp_otnt_apspcc00.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET WRAPPER ON/OFF                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrapper_onoff(cs_uint16 module_id, 
                                            cs_uint16 wrmd)
/* INPUTS     : o Module Id                                     */
/*              o WRMD                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the OTNT4 X Wrapper Configuration       */
/* Register 3.                                                  */
/*                                                              */
/* The [wrmd] parameter is:                                     */
/*   0b00 = Wrapper off; bypass data and timing signals         */
/*   0b01 = Wrapper on                                          */
/*   0b10 = Wrapper off                                         */
/*   0b11 = Wrapper on; map short to long frame (ODU to OTU)    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_otnt4x_wrpcfg3;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnt4x_set_wrapper_onoff";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  CS_PRINT("%s() %s, wrmd=%d\n",  func, ten_module_strings[module_id&1], wrmd);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
  tmp_otnt4x_wrpcfg3.bf.WRMD = wrmd;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_otnt4x_wrpcfg3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET WRAPPER AGGREGATION MODE            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrapper_aggrmod(cs_uint16 module_id, 
                                              cs_uint16 aggrmod)
/* INPUTS     : o Module Id                                     */
/*              o AGGRMOD                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the OTNT4 X Wrapper Configuration       */
/* Register 3.                                                  */
/*                                                              */
/* The [aggrmod] parameter is specified as:                     */
/*   0 = Monolithic wrapping - single client                    */
/*   1 = Aggregation wrapping - quad 1/4-rate client signals    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_otnt4x_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
  tmp_otnt4x_wrpcfg3.bf.AGGRMOD = aggrmod;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_otnt4x_wrpcfg3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS0 REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs0(cs_uint16 module_id, 
                                     cs_uint16 fs0)
/* INPUTS     : o Module Id                                     */
/*              o FS0                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs0] parameter is the fixed stuff bytes carried in OPU  */
/* for monolithic client wrapping or for timeslot 0 for         */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS0_t tmp_otnt4x_wrpfs0;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnt4x_set_wrpfs0";  

  CS_PRINT("%s() %s, fs0=%d\n", func, ten_module_strings[module_id&1], fs0);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS0));
  tmp_otnt4x_wrpfs0.bf.FS0 = fs0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS0), tmp_otnt4x_wrpfs0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS1 REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs1(cs_uint16 module_id, 
                                     cs_uint16 fs1)
/* INPUTS     : o Module Id                                     */
/*              o FS1                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs1] parameter is the fixed stuff bytes carried in OPU  */
/* for monolithic client wrapping or for timeslot 1 for         */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS1_t tmp_otnt4x_wrpfs1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS1));
  tmp_otnt4x_wrpfs1.bf.FS1 = fs1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS1), tmp_otnt4x_wrpfs1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS2 REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs2(cs_uint16 module_id, 
                                     cs_uint16 fs2)
/* INPUTS     : o Module Id                                     */
/*              o FS2                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs2] parameter is the fixed stuff bytes carried in OPU  */
/* for monolithic client wrapping or for timeslot 2 for         */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS2_t tmp_otnt4x_wrpfs2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS2));
  tmp_otnt4x_wrpfs2.bf.FS2 = fs2;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS2), tmp_otnt4x_wrpfs2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS3 REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs3(cs_uint16 module_id, 
                                     cs_uint16 fs3)
/* INPUTS     : o Module Id                                     */
/*              o FS3                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs3] parameter is the fixed stuff bytes carried in OPU  */
/* for monolithic client wrapping or for timeslot 3 for         */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS3_t tmp_otnt4x_wrpfs3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS3));
  tmp_otnt4x_wrpfs3.bf.FS3 = fs3;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS3), tmp_otnt4x_wrpfs3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS4 REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs4(cs_uint16 module_id, 
                                     cs_uint16 fs4)
/* INPUTS     : o Module Id                                     */
/*              o FS4                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs4] parameter is the fixed stuff bytes carried in OPU  */
/* for monolithic client wrapping or for timeslot 4 for         */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS4_t tmp_otnt4x_wrpfs4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS4));
  tmp_otnt4x_wrpfs4.bf.FS4 = fs4;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS4), tmp_otnt4x_wrpfs4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS5 REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs5(cs_uint16 module_id, 
                                     cs_uint16 fs5)
/* INPUTS     : o Module Id                                     */
/*              o FS5                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs5] parameter is the fixed stuff bytes carried in OPU  */
/* for monolithic client wrapping or for timeslot 5 for         */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS5_t tmp_otnt4x_wrpfs5;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs5.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS5));
  tmp_otnt4x_wrpfs5.bf.FS5 = fs5;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS5), tmp_otnt4x_wrpfs5.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS6 REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs6(cs_uint16 module_id, 
                                     cs_uint16 fs6)
/* INPUTS     : o Module Id                                     */
/*              o FS6                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs6] parameter is the fixed stuff bytes carried in OPU  */
/* for monolithic client wrapping or for timeslot 6 for         */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS6_t tmp_otnt4x_wrpfs6;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs6.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS6));
  tmp_otnt4x_wrpfs6.bf.FS6 = fs6;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS6), tmp_otnt4x_wrpfs6.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS7 REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs7(cs_uint16 module_id, 
                                     cs_uint16 fs7)
/* INPUTS     : o Module Id                                     */
/*              o FS7                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs7] parameter is the fixed stuff bytes carried in OPU  */
/* for monolithic client wrapping or for timeslot 7 for         */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS7_t tmp_otnt4x_wrpfs7;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs7.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS7));
  tmp_otnt4x_wrpfs7.bf.FS7 = fs7;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS7), tmp_otnt4x_wrpfs7.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS8 REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs8(cs_uint16 module_id, 
                                     cs_uint16 fs8)
/* INPUTS     : o Module Id                                     */
/*              o FS8                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs8] parameter is the fixed stuff bytes carried in OPU  */
/* for monolithic client wrapping or for timeslot 8 for         */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS8_t tmp_otnt4x_wrpfs8;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs8.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS8));
  tmp_otnt4x_wrpfs8.bf.FS8 = fs8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS8), tmp_otnt4x_wrpfs8.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS9 REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs9(cs_uint16 module_id, 
                                     cs_uint16 fs9)
/* INPUTS     : o Module Id                                     */
/*              o FS9                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs9] parameter is the fixed stuff bytes carried in OPU  */
/* for monolithic client wrapping or for timeslot 9 for         */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS9_t tmp_otnt4x_wrpfs9;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs9.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS9));
  tmp_otnt4x_wrpfs9.bf.FS9 = fs9;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS9), tmp_otnt4x_wrpfs9.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS10 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs10(cs_uint16 module_id, 
                                      cs_uint16 fs10)
/* INPUTS     : o Module Id                                     */
/*              o FS10                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs10] parameter is the fixed stuff bytes carried in OPU */
/* for monolithic client wrapping or for timeslot 10 for        */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS10_t tmp_otnt4x_wrpfs10;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs10.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS10));
  tmp_otnt4x_wrpfs10.bf.FS10 = fs10;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS10), tmp_otnt4x_wrpfs10.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS11 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs11(cs_uint16 module_id, 
                                      cs_uint16 fs11)
/* INPUTS     : o Module Id                                     */
/*              o FS11                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs11] parameter is the fixed stuff bytes carried in OPU */
/* for monolithic client wrapping or for timeslot 11 for        */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS11_t tmp_otnt4x_wrpfs11;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs11.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS11));
  tmp_otnt4x_wrpfs11.bf.FS11 = fs11;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS11), tmp_otnt4x_wrpfs11.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS12 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs12(cs_uint16 module_id, 
                                      cs_uint16 fs12)
/* INPUTS     : o Module Id                                     */
/*              o FS12                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs12] parameter is the fixed stuff bytes carried in OPU */
/* for monolithic client wrapping or for timeslot 12 for        */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS12_t tmp_otnt4x_wrpfs12;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs12.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS12));
  tmp_otnt4x_wrpfs12.bf.FS12 = fs12;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS12), tmp_otnt4x_wrpfs12.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS13 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs13(cs_uint16 module_id, 
                                      cs_uint16 fs13)
/* INPUTS     : o Module Id                                     */
/*              o FS13                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs13] parameter is the fixed stuff bytes carried in OPU */
/* for monolithic client wrapping or for timeslot 13 for        */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS13_t tmp_otnt4x_wrpfs13;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs13.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS13));
  tmp_otnt4x_wrpfs13.bf.FS13 = fs13;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS13), tmp_otnt4x_wrpfs13.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS14 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs14(cs_uint16 module_id, 
                                      cs_uint16 fs14)
/* INPUTS     : o Module Id                                     */
/*              o FS14                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs14] parameter is the fixed stuff bytes carried in OPU */
/* for monolithic client wrapping or for timeslot 14 for        */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS14_t tmp_otnt4x_wrpfs14;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs14.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS14));
  tmp_otnt4x_wrpfs14.bf.FS14 = fs14;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS14), tmp_otnt4x_wrpfs14.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPFS15 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpfs15(cs_uint16 module_id, 
                                      cs_uint16 fs15)
/* INPUTS     : o Module Id                                     */
/*              o FS15                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [fs15] parameter is the fixed stuff bytes carried in OPU */
/* for monolithic client wrapping or for timeslot 15 for        */
/* aggregation wrapping.                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPFS15_t tmp_otnt4x_wrpfs15;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpfs15.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS15));
  tmp_otnt4x_wrpfs15.bf.FS15 = fs15;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS15), tmp_otnt4x_wrpfs15.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X DOAIE                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_doaie(cs_uint16 module_id, 
                                cs_uint8  byte,
                                cs_uint16 insertion)
/* INPUTS     : o Module Id                                         */
/*              o Byte                                              */
/*              o Insertion                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Direct Overhead Access Insert Enable for the specifed       */
/* overhead byte.                                                   */
/*                                                                  */
/* The [byte] parameter is specified as:                            */
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
/*   [insertion]  Overhead Data Insertion Control                   */
/*     0 = Never insert overhead byte                               */
/*     1 = Insert overhead byte when MFM1 is active                 */
/*     2 = Insert overhead byte when MFM2 is active                 */
/*     3 = Insert overhead byte when MFM3 is active.                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_uint16 shift;
  
  if ((byte > TEN_OTNOH_OPUKOH_BYTE8) || (insertion > 3)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, " : parm out of range.");
    rtn = CS_ERROR;
    goto RTN_EXIT;
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  if (byte < (1*8)) {
    TEN_N40G_OTNT4X_DOAIE0_t tmp_otnt4x_doaie0;
    
    tmp_otnt4x_doaie0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE0));
    shift = (byte - (0*8))*2;
    tmp_otnt4x_doaie0.bf.DOAIE0 &= ~(3 << shift);       /* mask */
    tmp_otnt4x_doaie0.bf.DOAIE0 |= insertion << shift;  /* set  */
    
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE0), tmp_otnt4x_doaie0.wrd);
  }
  else if (byte < (2*8)) {
    TEN_N40G_OTNT4X_DOAIE1_t tmp_otnt4x_doaie1;
    
    tmp_otnt4x_doaie1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE1));
    shift = (byte - (1*8))*2;
    tmp_otnt4x_doaie1.bf.DOAIE1 &= ~(3 << shift);       /* mask */
    tmp_otnt4x_doaie1.bf.DOAIE1 |= insertion << shift;  /* set  */
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE1), tmp_otnt4x_doaie1.wrd);
  }
  else if (byte < (3*8)) {
    TEN_N40G_OTNT4X_DOAIE2_t tmp_otnt4x_doaie2;
    
    tmp_otnt4x_doaie2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE2));
    shift = (byte - (2*8))*2;
    tmp_otnt4x_doaie2.bf.DOAIE2 &= ~(3 << shift);       /* mask */
    tmp_otnt4x_doaie2.bf.DOAIE2 |= insertion << shift;  /* set  */
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE2), tmp_otnt4x_doaie2.wrd);
  }
  else if (byte < (4*8)) {
    TEN_N40G_OTNT4X_DOAIE3_t tmp_otnt4x_doaie3;
    
    tmp_otnt4x_doaie3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE3));
    shift = (byte - (3*8))*2;
    tmp_otnt4x_doaie3.bf.DOAIE3 &= ~(3 << shift);       /* mask */
    tmp_otnt4x_doaie3.bf.DOAIE3 |= insertion << shift;  /* set  */
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE3), tmp_otnt4x_doaie3.wrd);
  }
  else if (byte < (5*8)) {
    TEN_N40G_OTNT4X_DOAIE4_t tmp_otnt4x_doaie4;
    
    tmp_otnt4x_doaie4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE4));
    shift = (byte - (4*8))*2;
    tmp_otnt4x_doaie4.bf.DOAIE4 &= ~(3 << shift);       /* mask */
    tmp_otnt4x_doaie4.bf.DOAIE4 |= insertion << shift;  /* set  */
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE4), tmp_otnt4x_doaie4.wrd);
  }
  else if (byte < (6*8)) {
    TEN_N40G_OTNT4X_DOAIE5_t tmp_otnt4x_doaie5;
    
    tmp_otnt4x_doaie5.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE5));
    shift = (byte - (5*8))*2;
    tmp_otnt4x_doaie5.bf.DOAIE5 &= ~(3 << shift);       /* mask */
    tmp_otnt4x_doaie5.bf.DOAIE5 |= insertion << shift;  /* set  */
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE5), tmp_otnt4x_doaie5.wrd);
  }
  else if (byte < (7*8)) {
    TEN_N40G_OTNT4X_DOAIE6_t tmp_otnt4x_doaie6;
    
    tmp_otnt4x_doaie6.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE6));
    shift = (byte - (6*8))*2;
    tmp_otnt4x_doaie6.bf.DOAIE6 &= ~(3 << shift);       /* mask */
    tmp_otnt4x_doaie6.bf.DOAIE6 |= insertion << shift;  /* set  */
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE6), tmp_otnt4x_doaie6.wrd);
  }
  else {
    TEN_N40G_OTNT4X_DOAIE7_t tmp_otnt4x_doaie7;
    
    tmp_otnt4x_doaie7.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE7));
    shift = (byte - (7*8))*2;
    tmp_otnt4x_doaie7.bf.DOAIE7 &= ~(3 << shift);       /* mask */
    tmp_otnt4x_doaie7.bf.DOAIE7 |= insertion << shift;  /* set  */
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DOAIE7), tmp_otnt4x_doaie7.wrd);
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

RTN_EXIT:
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN0                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en0(cs_uint16 module_id,  
                                         cs_uint16 c15res_en0)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN0                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for monolithic      */
/* client or timeslot 0 in aggregation mode.                    */
/*                                                              */
/* The [c15res_en0] parameter is specified as:                  */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN0_t tmp_otnt4x_wrpc15en0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0));
  tmp_otnt4x_wrpc15en0.bf.C15RES_EN0 = c15res_en0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0), tmp_otnt4x_wrpc15en0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN1                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en1(cs_uint16 module_id,  
                                         cs_uint16 c15res_en1)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN1                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 1 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en1] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN0_t tmp_otnt4x_wrpc15en0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0));
  tmp_otnt4x_wrpc15en0.bf.C15RES_EN1 = c15res_en1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0), tmp_otnt4x_wrpc15en0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN2                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en2(cs_uint16 module_id,  
                                         cs_uint16 c15res_en2)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN2                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 2 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en2] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN0_t tmp_otnt4x_wrpc15en0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0));
  tmp_otnt4x_wrpc15en0.bf.C15RES_EN2 = c15res_en2;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0), tmp_otnt4x_wrpc15en0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN3                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en3(cs_uint16 module_id,  
                                         cs_uint16 c15res_en3)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN3                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 3 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en3] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN0_t tmp_otnt4x_wrpc15en0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0));
  tmp_otnt4x_wrpc15en0.bf.C15RES_EN3 = c15res_en3;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0), tmp_otnt4x_wrpc15en0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN4                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en4(cs_uint16 module_id, 
                                         cs_uint16 c15res_en4)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN4                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 4 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en4] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN1_t tmp_otnt4x_wrpc15en1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1));
  tmp_otnt4x_wrpc15en1.bf.C15RES_EN4 = c15res_en4;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1), tmp_otnt4x_wrpc15en1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN5                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en5(cs_uint16 module_id, 
                                         cs_uint16 c15res_en5)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN5                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 5 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en5] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN1_t tmp_otnt4x_wrpc15en1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1));
  tmp_otnt4x_wrpc15en1.bf.C15RES_EN5 = c15res_en5;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1), tmp_otnt4x_wrpc15en1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN6                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en6(cs_uint16 module_id, 
                                         cs_uint16 c15res_en6)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN6                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 6 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en6] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN1_t tmp_otnt4x_wrpc15en1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1));
  tmp_otnt4x_wrpc15en1.bf.C15RES_EN6 = c15res_en6;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1), tmp_otnt4x_wrpc15en1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN7                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en7(cs_uint16 module_id, 
                                         cs_uint16 c15res_en7)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN7                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 7 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en7] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN1_t tmp_otnt4x_wrpc15en1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1));
  tmp_otnt4x_wrpc15en1.bf.C15RES_EN7 = c15res_en7;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1), tmp_otnt4x_wrpc15en1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN8                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en8(cs_uint16 module_id, 
                                         cs_uint16 c15res_en8)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN8                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 8 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en8] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN2_t tmp_otnt4x_wrpc15en2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN2));
  tmp_otnt4x_wrpc15en2.bf.C15RES_EN8 = c15res_en8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN2), tmp_otnt4x_wrpc15en2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN9                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en9(cs_uint16 module_id, 
                                         cs_uint16 c15res_en9)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN9                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 9 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en9] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN2_t tmp_otnt4x_wrpc15en2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN2));
  tmp_otnt4x_wrpc15en2.bf.C15RES_EN9 = c15res_en9;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN2), tmp_otnt4x_wrpc15en2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN10                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en10(cs_uint16 module_id, 
                                          cs_uint16 c15res_en10)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN10                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 10 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en10] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN2_t tmp_otnt4x_wrpc15en2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN2));
  tmp_otnt4x_wrpc15en2.bf.C15RES_EN10 = c15res_en10;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN2), tmp_otnt4x_wrpc15en2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN11                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en11(cs_uint16 module_id, 
                                          cs_uint16 c15res_en11)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN11                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 11 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en11] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN2_t tmp_otnt4x_wrpc15en2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN2));
  tmp_otnt4x_wrpc15en2.bf.C15RES_EN11 = c15res_en11;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN2), tmp_otnt4x_wrpc15en2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN12                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en12(cs_uint16 module_id, 
                                          cs_uint16 c15res_en12)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN12                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 12 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en12] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN3_t tmp_otnt4x_wrpc15en3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN3));
  tmp_otnt4x_wrpc15en3.bf.C15RES_EN12 = c15res_en12;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN3), tmp_otnt4x_wrpc15en3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN13                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en13(cs_uint16 module_id, 
                                          cs_uint16 c15res_en13)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN13                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 13 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en13] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN3_t tmp_otnt4x_wrpc15en3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN3));
  tmp_otnt4x_wrpc15en3.bf.C15RES_EN13 = c15res_en13;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN3), tmp_otnt4x_wrpc15en3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN14                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en14(cs_uint16 module_id, 
                                          cs_uint16 c15res_en14)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN14                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 14 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en14] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN3_t tmp_otnt4x_wrpc15en3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN3));
  tmp_otnt4x_wrpc15en3.bf.C15RES_EN14 = c15res_en14;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN3), tmp_otnt4x_wrpc15en3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET C15RES_EN15                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_c15res_en15(cs_uint16 module_id, 
                                          cs_uint16 c15res_en15)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN15                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 15 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en15] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPC15EN3_t tmp_otnt4x_wrpc15en3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpc15en3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN3));
  tmp_otnt4x_wrpc15en3.bf.C15RES_EN15 = c15res_en15;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN3), tmp_otnt4x_wrpc15en3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPCFG4 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpcfg4(cs_uint16 module_id, 
                                      cs_uint16 jc_plus, 
                                      cs_uint16 jcen)
/* INPUTS     : o Module Id                                     */
/*              o JC PLUS                                       */
/*              o JCEN                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/*   [jc_plus]  Enable enhanced justification                   */
/*                                                              */
/*   [jcen]  Enable wrapper to generate justification commands. */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnt4x_set_wrpcfg4";  

  CS_PRINT("%s() %s, jc_plus=%d, jcen=%d\n", func, ten_module_strings[module_id&1], jc_plus, jcen);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_otnt4x_wrpcfg4.bf.JC_PLUS = jc_plus;
  tmp_otnt4x_wrpcfg4.bf.JCEN = jcen;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_otnt4x_wrpcfg4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET JC_PLUS                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_jc_plus(cs_uint16 module_id, 
                                      cs_uint16 jc_plus)
/* INPUTS     : o Module Id                                     */
/*              o JC PLUS                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the designated field in the OTN Wrapper Configuration    */
/* Register.                                                    */
/*                                                              */
/* The [jc_plus] parameter is specified as:                     */
/*   0000-1111 binary                                           */
/*   Enable enhanced justification. When set to 1, up to 6 PJO  */
/*   may be used. Bit 0 applies for monolithic client de-       */
/*   wrapping and for tributary 0 in aggregation de-wrapping.   */
/*   Bits 1-3 apply to tributaries 1-3 in aggregation de-       */
/*   wrapping only.                                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnt4x_set_jc_plus";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  CS_PRINT("%s() %s, jc_plus=%d\n",
           func,
           ten_module_strings[module_id&1],
           jc_plus);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_otnt4x_wrpcfg4.bf.JC_PLUS = jc_plus;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_otnt4x_wrpcfg4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRPCFG4 JCEN PER SLICE       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(cs_uint16 module_id, 
                                      cs_uint8 slice, 
                                      cs_uint16 jcen)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o JCEN                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set jc enable per slice.                                     */
/*                                                              */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),        */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)    */
/*                                                              */
/* [jcen]  Enable wrapper to generate justification commands.   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s, %s, jcen=%d\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           jcen);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));

  if (slice == TEN_SLICE_ALL) {
    if (jcen) {
      tmp_otnt4x_wrpcfg4.bf.JCEN = 0xF;
    }
    else {
      tmp_otnt4x_wrpcfg4.bf.JCEN = 0;
    }
  }
  else {
    if (jcen) {
      /* tmp_otnt4x_wrpcfg4.bf.JCEN |= (1<<slice); */ /* Bugzilla 22406 */
      tmp_otnt4x_wrpcfg4.bf.JCEN |= (1<<(3-slice));
    }
    else {
      /* tmp_otnt4x_wrpcfg4.bf.JCEN &= ~(1<<slice); */  /* Bugzilla 22406 */
      tmp_otnt4x_wrpcfg4.bf.JCEN &= ~(1<<(3-slice));
    }
  }
  
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_otnt4x_wrpcfg4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET NCOLS                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_ncols(cs_uint16 module_id, 
                                    cs_uint16 ncols)
/* INPUTS     : o Module Id                                     */
/*              o NCOLS                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* NCOLS[9:0] specifies number of columns (or bytes) per OTN    */
/* row (columns = (NCOLS+1)*16). For G.709 OTU-compliant        */
/* framing NCOLS must be set to 254 (4080 columns).             */
/*                                                              */
/* The [ncols] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG0_t tmp_otnt4x_wrpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG0));
  tmp_otnt4x_wrpcfg0.bf.NCOLS = ncols;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG0), tmp_otnt4x_wrpcfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRP0DH1 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrp0dh1(cs_uint16 module_id, 
                                      cs_uint16 dthyst01)
/* INPUTS     : o Module Id                                     */
/*              o DTHYST01                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Wrapper Detrministic Hysteresis.                         */
/*                                                              */
/*   [dthyst01] is specified as:                                */
/*     DTHYST01[1:0] DeTerministic HYSTeresis interval for      */
/*     tributary 0, used in quad aggregation mode only. The     */
/*     underlying formula is as follows:                        */
/*       DTHYST = 238 / 4 * cols ;                              */
/*     where cols = overall byte count of outgoing OxU          */
/*     frame / 16. For standard OTU framing, for example,       */
/*     cols is '255'.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRP0DH1_t tmp_otnt4x_wrp0dh1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrp0dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH1));
  tmp_otnt4x_wrp0dh1.bf.DTHYST01 = dthyst01;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH1), tmp_otnt4x_wrp0dh1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRP0DH0 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrp0dh0(cs_uint16 module_id, 
                                      cs_uint16 dthyst00)
/* INPUTS     : o Module Id                                     */
/*              o DTHYST00                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Wrapper Detrministic Hysteresis.                         */
/*                                                              */
/*   [dthyst00] is specified as:                                */
/*     DTHYST01[15:0] DeTerministic HYSTeresis interval for     */
/*     tributary 0, used in quad aggregation mode only. The     */
/*     underlying formula is as follows:                        */
/*       DTHYST = 238 / 4 * cols ;                              */
/*     where cols = overall byte count of outgoing OxU          */
/*     frame / 16. For standard OTU framing, for example,       */
/*     cols is '255'.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRP0DH0_t tmp_otnt4x_wrp0dh0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrp0dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH0));
  tmp_otnt4x_wrp0dh0.bf.DTHYST00 = dthyst00;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH0), tmp_otnt4x_wrp0dh0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRP1DH1 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrp1dh1(cs_uint16 module_id, 
                                      cs_uint16 dthyst11)
/* INPUTS     : o Module Id                                     */
/*              o DTHYST11                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Wrapper Detrministic Hysteresis.                         */
/*                                                              */
/*   [dthyst11] is specified as:                                */
/*     DTHYST01[1:0] DeTerministic HYSTeresis interval for      */
/*     tributary 1, used in quad aggregation mode only. The     */
/*     underlying formula is as follows:                        */
/*       DTHYST = 238 / 4 * cols ;                              */
/*     where cols = overall byte count of outgoing OxU          */
/*     frame / 16. For standard OTU framing, for example,       */
/*     cols is '255'.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRP1DH1_t tmp_otnt4x_wrp1dh1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrp1dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH1));
  tmp_otnt4x_wrp1dh1.bf.DTHYST11 = dthyst11;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH1), tmp_otnt4x_wrp1dh1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRP1DH0 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrp1dh0(cs_uint16 module_id, 
                                      cs_uint16 dthyst10)
/* INPUTS     : o Module Id                                     */
/*              o DTHYST10                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Wrapper Detrministic Hysteresis.                         */
/*                                                              */
/*   [dthyst10] is specified as:                                */
/*     DTHYST01[15:0] DeTerministic HYSTeresis interval for     */
/*     tributary 1, used in quad aggregation mode only. The     */
/*     underlying formula is as follows:                        */
/*       DTHYST = 238 / 4 * cols ;                              */
/*     where cols = overall byte count of outgoing OxU          */
/*     frame / 16. For standard OTU framing, for example,       */
/*     cols is '255'.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRP1DH0_t tmp_otnt4x_wrp1dh0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrp1dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH0));
  tmp_otnt4x_wrp1dh0.bf.DTHYST10 = dthyst10;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH0), tmp_otnt4x_wrp1dh0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRP2DH1 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrp2dh1(cs_uint16 module_id, 
                                      cs_uint16 dthyst21)
/* INPUTS     : o Module Id                                     */
/*              o DTHYST21                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Wrapper Detrministic Hysteresis.                         */
/*                                                              */
/*   [dthyst21] is specified as:                                */
/*     DTHYST01[1:0] DeTerministic HYSTeresis interval for      */
/*     tributary 2, used in quad aggregation mode only. The     */
/*     underlying formula is as follows:                        */
/*       DTHYST = 238 / 4 * cols ;                              */
/*     where cols = overall byte count of outgoing OxU          */
/*     frame / 16. For standard OTU framing, for example,       */
/*     cols is '255'.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRP2DH1_t tmp_otnt4x_wrp2dh1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrp2dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH1));
  tmp_otnt4x_wrp2dh1.bf.DTHYST21 = dthyst21;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH1), tmp_otnt4x_wrp2dh1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRP2DH0 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrp2dh0(cs_uint16 module_id, 
                                      cs_uint16 dthyst20)
/* INPUTS     : o Module Id                                     */
/*              o DTHYST20                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Wrapper Detrministic Hysteresis.                         */
/*                                                              */
/*   [dthyst20] is specified as:                                */
/*     DTHYST01[15:0] DeTerministic HYSTeresis interval for     */
/*     tributary 2, used in quad aggregation mode only. The     */
/*     underlying formula is as follows:                        */
/*       DTHYST = 238 / 4 * cols ;                              */
/*     where cols = overall byte count of outgoing OxU          */
/*     frame / 16. For standard OTU framing, for example,       */
/*     cols is '255'.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRP2DH0_t tmp_otnt4x_wrp2dh0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrp2dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH0));
  tmp_otnt4x_wrp2dh0.bf.DTHYST20 = dthyst20;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH0), tmp_otnt4x_wrp2dh0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRP3DH1 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrp3dh1(cs_uint16 module_id, 
                                      cs_uint16 dthyst31)
/* INPUTS     : o Module Id                                     */
/*              o DTHYST31                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Wrapper Detrministic Hysteresis.                         */
/*                                                              */
/*   [dthyst31] is specified as:                                */
/*     DTHYST01[1:0] DeTerministic HYSTeresis interval for      */
/*     tributary 3, used in quad aggregation mode only. The     */
/*     underlying formula is as follows:                        */
/*       DTHYST = 238 / 4 * cols ;                              */
/*     where cols = overall byte count of outgoing OxU          */
/*     frame / 16. For standard OTU framing, for example,       */
/*     cols is '255'.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRP3DH1_t tmp_otnt4x_wrp3dh1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrp3dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH1));
  tmp_otnt4x_wrp3dh1.bf.DTHYST31 = dthyst31;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH1), tmp_otnt4x_wrp3dh1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET WRP3DH0 REGISTER             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrp3dh0(cs_uint16 module_id, 
                                      cs_uint16 dthyst30)
/* INPUTS     : o Module Id                                     */
/*              o DTHYST30                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Wrapper Detrministic Hysteresis.                         */
/*                                                              */
/*   [dthyst30] is specified as:                                */
/*     DTHYST01[15:0] DeTerministic HYSTeresis interval for     */
/*     tributary 3, used in quad aggregation mode only. The     */
/*     underlying formula is as follows:                        */
/*       DTHYST = 238 / 4 * cols ;                              */
/*     where cols = overall byte count of outgoing OxU          */
/*     frame / 16. For standard OTU framing, for example,       */
/*     cols is '255'.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_WRP3DH0_t tmp_otnt4x_wrp3dh0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrp3dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH0));
  tmp_otnt4x_wrp3dh0.bf.DTHYST30 = dthyst30;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH0), tmp_otnt4x_wrp3dh0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/* Bugzilla 24628 Start */
/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET dthyst REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_dthyst(cs_uint16 module_id, 
                                     cs_uint8  slice,
                                     cs_uint32 dthyst)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o DTHYST                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Wrapper Detrministic Hysteresis.                         */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [slice_line]  specifies line's slice:                        */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* [dthyst] is specified as:                                    */
/*   DeTerministic HYSTeresis interval for tributary (3-slice), */
/*   used in quad aggregation mode only.                        */
/*   The underlying formula is as follows:                      */
/*     DTHYST = 238 / 4 * cols ;                                */
/*   where cols = overall byte count of outgoing OxU            */
/*   frame / 16. For standard OTU framing, for example,         */
/*   cols is '255'.                                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_n40g_otnt4x_set_dthyst";  


  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255. ", func, slice);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, dthyst=%d\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           dthyst);



  /* Hysteresis value for DT Just */
  if ((slice == 0) || (slice == TEN_SLICE_ALL)) {
    /* Tributary 3 */
    rtn |= ten_n40g_otnt4x_set_wrp3dh1(module_id, (cs_uint16)(dthyst >> 16));
    rtn |= ten_n40g_otnt4x_set_wrp3dh0(module_id, (cs_uint16)(dthyst & 0xFFFF));
  }
  if ((slice == 1) || (slice == TEN_SLICE_ALL)) {
    /* Tributary 2 */
    rtn |= ten_n40g_otnt4x_set_wrp2dh1(module_id, (cs_uint16)(dthyst >> 16));
    rtn |= ten_n40g_otnt4x_set_wrp2dh0(module_id, (cs_uint16)(dthyst & 0xFFFF));
  }
  if ((slice == 2) || (slice == TEN_SLICE_ALL)) {
    /* Tributary 1 */
    rtn |= ten_n40g_otnt4x_set_wrp1dh1(module_id, (cs_uint16)(dthyst >> 16));
    rtn |= ten_n40g_otnt4x_set_wrp1dh0(module_id, (cs_uint16)(dthyst & 0xFFFF));
  }
  if ((slice == 3) || (slice == TEN_SLICE_ALL)) {
    /* Tributary 0 */
    rtn |= ten_n40g_otnt4x_set_wrp0dh1(module_id, (cs_uint16)(dthyst >> 16));
    rtn |= ten_n40g_otnt4x_set_wrp0dh0(module_id, (cs_uint16)(dthyst & 0xFFFF));
  }
  
  return (rtn);
}
/* Bugzilla 24628 End */

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET CONFIGURATION                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_ocfg(cs_uint16 module_id, 
                               cs_boolean fecmd, 
                               cs_boolean fecen)
/* INPUTS     : o Module Id                                     */
/*              o FECMD                                         */
/*              o FECEN                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the OTNT4X Configuration.                                */
/*                                                              */
/* The [fecmd] parameter is specified as:                       */
/*   FECMD[1:0]                                                 */
/*   Ultra FEC enable:                                          */
/*   0 = GFEC enabled                                           */
/*   1 = UFEC enabled                                           */
/*                                                              */
/* The [fecen] parameter is specified as:                       */
/*   When set, the FEC encoding is enabled. The output stream   */
/*   will be OTU. When not set, FEC encoding is disabled.       */
/*   The output stream will be ODU.                             */
/*   0 = Do not use FEC Encoder.                                */
/*   1 = Use FEC Encoder.                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_OCFG_t tmp_otnt4x_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_ocfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OCFG));
  tmp_otnt4x_ocfg.bf.FECMD = fecmd & 0x01;
  tmp_otnt4x_ocfg.bf.FECEN = fecen;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OCFG), tmp_otnt4x_ocfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET WRAPPER CONFIGURATION REGISTER 3    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_wrpcfg5(cs_uint16 module_id, 
                                      cs_uint16 stuffbt)
/* INPUTS     : o Module Id                                     */
/*              o STUFFBT                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set various aspects of the Wrapper Configuration 5 Register. */
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
  TEN_N40G_OTNT4X_WRPCFG5_t tmp_otnt4x_wrpcfg5;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg5.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG5));
  tmp_otnt4x_wrpcfg5.bf.STUFFBT = stuffbt;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG5), tmp_otnt4x_wrpcfg5.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET FASIE                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_fasie(cs_uint16 module_id, 
                                    cs_uint16 fasie)
/* INPUTS     : o Module Id                                     */
/*              o FASIE                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* When set, a FAS pattern of F6F6F6282828 hex will be inserted */
/* in row 1, columns 1 through 6.                               */
/*                                                              */
/* The [fasie] parameter is specified as:                       */
/*   When set, a FAS pattern of F6F6F6282828 hex will be        */
/*   inserted in row 1, columns 1 through 6.                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_CFG0_t tmp_otnt4x_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_cfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG0));
  tmp_otnt4x_cfg0.bf.FASIE = fasie;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG0), tmp_otnt4x_cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNT4X SET PTIE                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnt4x_set_ptie(cs_uint16 module_id,
                                   cs_uint16 ptie)
/* INPUTS     : o Module Id                                     */
/*              o PTIE                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* When set, enables Payload Type Identifier insertion.         */
/*                                                              */
/* The [ptie] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNT4X_CFG0_t tmp_otnt4x_cfg0;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnt4x_set_ptie";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  CS_PRINT("%s() %s, ptie=%d\n", func, ten_module_strings[module_id & 1], ptie);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_cfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG0));
  tmp_otnt4x_cfg0.bf.PTIE = ptie;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG0), tmp_otnt4x_cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X WRPCFG1 T41                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_wrpcfg1_t41(cs_uint16 module_id, 
                                      cs_uint16 jchyst)
/* INPUTS     : o Module Id                                         */
/*              o JCHYST                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Wrapper Configuration Register 1.                           */
/*                                                                  */
/*   [jchyst]                                                       */
/*    For monolithic wrapping with asynchronous mapping enabled,    */
/*    this configuration parameter specifies the minimum number     */
/*    of frames required between any two generated justification    */
/*    commands. This register is also used for tributary 0 of the   */
/*    GMP aggregation wrapper.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_N40G_OTNT4X_WRPCFG1_t tmp_otnt4x_wrpcfg1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt4x_wrpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1));
  tmp_otnt4x_wrpcfg1.bf.JCHYST = jchyst;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1), tmp_otnt4x_wrpcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X DMCFG1 GEN ENABLE                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_dmcfg1_gen_enable(cs_uint16 module_id, 
                                            cs_uint16 dm_select, cs_uint16 dm_gen_en)
/* INPUTS     : o Module Id                                         */
/*              o DM Select                                         */
/*              o DM GEN EN                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Delay Measurement generator enable.                          */
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
  TEN_N40G_OTNT4X_DMCFG1_t tmp_otnt_dmcfg1;

  if ((dm_select < TEN_DM_PM) || (dm_select > TEN_DM_RES)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_select out of range.  s/b 1..8.");
    return (CS_ERROR);
  }

  if (dm_gen_en > TEN_DM_SET_TO_1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_gen_en out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt_dmcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DMCFG1));
  
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
  
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DMCFG1), tmp_otnt_dmcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X DMCFG2 INSERT ENABLE                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_dmcfg2_insert_enable(cs_uint16 module_id, 
                                               cs_uint16 dm_select, cs_uint16 dm_insert_en)
/* INPUTS     : o Module Id                                         */
/*              o DM INSERT EN                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Delay Measurement Insertion Enable.                          */
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
  TEN_N40G_OTNT4X_DMCFG2_t tmp_otnt_dmcfg2;

  if (dm_select > TEN_DM_RES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_select out of range.  s/b 0..8.");
    return (CS_ERROR);
  }

  if (dm_insert_en > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_insert_en out of range.  s/b 0..1.");
    return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt_dmcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DMCFG2));
   
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
   
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DMCFG2), tmp_otnt_dmcfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X DMCSFCFG AUTO CSF ENABLE             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_dmcsfcfg_auto_csf_enable(cs_uint16 module_id, 
                                                   cs_uint16 auto_csf_en)
/* INPUTS     : o Module Id                                         */
/*              o AUTO CSF EN                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Delay Measurement Auto CSF Enable.                           */
/*                                                                  */
/*   [auto_csf_en]                                                  */
/*     Enable automatic insertion from the SFU of the CSF alarm     */
/*     into bit 1 of the PSI[2] byte                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_N40G_OTNT4X_DMCSFCFG_t tmp_otnt_dmcsfcfg;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt_dmcsfcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DMCSFCFG));
  tmp_otnt_dmcsfcfg.bf.AUTO_CSF_EN = auto_csf_en;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DMCSFCFG), tmp_otnt_dmcsfcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X DMCSFCFG CSF FORCE                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_dmcsfcfg_csf_force(cs_uint16 module_id, 
                                             cs_uint16 csf_force)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o CSF FORCE                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Delay Measurement CSF Force.                                 */
/*                                                                  */
/*   [csf_force]                                                    */
/*     Sets bit 1 of the PSI[2] byte                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_N40G_OTNT4X_DMCSFCFG_t tmp_otnt_dmcsfcfg;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt_dmcsfcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DMCSFCFG));
  tmp_otnt_dmcsfcfg.bf.CSF_FORCE = csf_force;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DMCSFCFG), tmp_otnt_dmcsfcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X DMCSFCFG DM TRIGGER                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_dmcsfcfg_dm_trigger(cs_uint16 module_id) 
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Forces an Edge sensitive DM trigger.                             */
/* (0-to-1 or 1-to-0 transition).                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_N40G_OTNT4X_DMCSFCFG_t tmp_otnt_dmcsfcfg;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt_dmcsfcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DMCSFCFG));
  tmp_otnt_dmcsfcfg.bf.DM_TRIG = (tmp_otnt_dmcsfcfg.bf.DM_TRIG == 1) ? 0 : 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DMCSFCFG), tmp_otnt_dmcsfcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT4X DMCSFCFG SEL                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt4x_dmcsfcfg_sel(cs_uint16 module_id, 
                                       cs_uint16 dm_select)
/* INPUTS     : o Module Id                                         */
/*              o DM SEL                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets DM trigger select.                                          */
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
  TEN_N40G_OTNT4X_DMCSFCFG_t tmp_otnt_dmcsfcfg;

  if (dm_select > TEN_DM_TCM1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_select out of range.  s/b 0..7.");
    return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt_dmcsfcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DMCSFCFG));
  tmp_otnt_dmcsfcfg.bf.DM_SEL = dm_select;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DMCSFCFG), tmp_otnt_dmcsfcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT STATCFG                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt_statcfg(cs_uint16 module_id,
                                cs_uint16 tcmpm, 
                                cs_uint16 tcmpmstat, 
                                cs_uint16 tcmpmstatinsmd)
/* INPUTS     : o Module Id                                         */
/*              o TCMPM                                             */
/*              o TCMPMSTAT                                         */
/*              o TCMPMSTATINSMD                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets STAT Overhead Configuration.                                */
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
/*      Use API ten_n40g_otnt_cfg3_ms_oh_ins.                       */
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
  TEN_N40G_OTNT4X_STATCFG0_t tmp_otnt_statcfg0;
  TEN_N40G_OTNT4X_STATCFG1_t tmp_otnt_statcfg1;
  TEN_N40G_OTNT4X_STATCFG2_t tmp_otnt_statcfg2;

  if ((tcmpm < TEN_OOHR_PATH_LAYER) || (tcmpm > TEN_OOHR_TCM6_LAYER)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": tcmpm out of range.  s/b 2..8.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
    
  switch (tcmpm) {
  case (TEN_OOHR_PATH_LAYER):
    tmp_otnt_statcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG0));
    tmp_otnt_statcfg0.bf.PMSTATINSMD = tcmpmstatinsmd;
    tmp_otnt_statcfg0.bf.PMSTAT = tcmpmstat;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG0), tmp_otnt_statcfg0.wrd);
    break;
  
  case (TEN_OOHR_TCM1_LAYER):
    tmp_otnt_statcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG0));
    tmp_otnt_statcfg0.bf.TCM1STATINSMD = tcmpmstatinsmd;
    tmp_otnt_statcfg0.bf.TCM1STAT = tcmpmstat;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG0), tmp_otnt_statcfg0.wrd);
    break;
  
  case (TEN_OOHR_TCM2_LAYER):
    tmp_otnt_statcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG0));
    tmp_otnt_statcfg0.bf.TCM2STAT = tcmpmstat;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG0), tmp_otnt_statcfg0.wrd);
    
    tmp_otnt_statcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG1));
    tmp_otnt_statcfg1.bf.TCM2STATINSMD = tcmpmstatinsmd;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG1), tmp_otnt_statcfg1.wrd);
    break;
  
  case (TEN_OOHR_TCM3_LAYER):
    tmp_otnt_statcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG1));
    tmp_otnt_statcfg1.bf.TCM3STATINSMD = tcmpmstatinsmd;
    tmp_otnt_statcfg1.bf.TCM3STAT = tcmpmstat;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG1), tmp_otnt_statcfg1.wrd);
    break;
  
  case (TEN_OOHR_TCM4_LAYER):
    tmp_otnt_statcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG1));
    tmp_otnt_statcfg1.bf.TCM4STATINSMD = tcmpmstatinsmd;
    tmp_otnt_statcfg1.bf.TCM4STAT = tcmpmstat;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG1), tmp_otnt_statcfg1.wrd);
    break;
  
  case (TEN_OOHR_TCM5_LAYER):
    tmp_otnt_statcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG2));
    tmp_otnt_statcfg2.bf.TCM5STATINSMD = tcmpmstatinsmd;
    tmp_otnt_statcfg2.bf.TCM5STAT = tcmpmstat;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG2), tmp_otnt_statcfg2.wrd);
    break;
  
  case (TEN_OOHR_TCM6_LAYER):
    tmp_otnt_statcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG2));
    tmp_otnt_statcfg2.bf.TCM6STATINSMD = tcmpmstatinsmd;
    tmp_otnt_statcfg2.bf.TCM6STAT = tcmpmstat;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, STATCFG2), tmp_otnt_statcfg2.wrd);
    break;
    
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": tcmpm out of range.");
    break;
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT CFG3 MS OH INS                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt_cfg3_ms_oh_ins(cs_uint16 module_id, 
                                       cs_uint16 ms_oh_ins)
/* INPUTS     : o Module Id                                         */
/*              o MS OH INS                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control Maintenance Signal Overhead Insertion Enable.            */
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
  TEN_N40G_OTNT4X_CFG3_t tmp_otnt_cfg3;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  tmp_otnt_cfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG3));
  tmp_otnt_cfg3.bf.MS_OH_INS = ms_oh_ins;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG3), tmp_otnt_cfg3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNT CFG3 APS INS EN                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnt_cfg3_aps_ins_en(cs_uint16 module_id,
                                        cs_uint8 aps_chan_num, 
                                        cs_uint16 aps_ins_en)
/* INPUTS     : o Module Id                                         */
/*              o Aps Chan Num                                      */
/*              o Aps Ins En                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure Aps Insert Enable                                      */
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
  TEN_N40G_OTNT4X_CFG3_t tmp_otnt_cfg3;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnt_cfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG3));

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
     TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": aps_chan_num out of range. s/b 0..7.");
     return (CS_ERROR);
  }

  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG3), tmp_otnt_cfg3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}




