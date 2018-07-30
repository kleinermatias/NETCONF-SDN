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
 * ten_n10g_gblt.c
 *
 * N10G related code is implemented here.
 *
 * $Id: ten_n10g_gblt.c,v 1.6 2013/02/22 20:47:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N10G SET TX GLOBAL CONFIGURATION REGISTER    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_gblt_cfgtx0(cs_uint16 module_id,
                                   cs_uint8 slice, 
                                   cs_uint16 pplf_en, 
                                   cs_uint16 cbrstmaisins, 
                                   cs_uint16 pn11auto, 
                                   cs_uint16 otnoff, 
                                   cs_uint16 oby, 
                                   cs_uint16 sby, 
                                   cs_uint16 kpgby, 
                                   cs_uint16 pktie)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PPLF EN                                       */
/*              o CBRSTMAISINS                                  */
/*              o PN11AUTO                                      */
/*              o OTNOFF                                        */
/*              o OBY                                           */
/*              o SBY                                           */
/*              o KPGBY                                         */
/*              o PKTIE                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Tx Global Configuration.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [pplf_en] parameter is specified as:                     */
/*   0                                                          */
/*   1 = Link Fail Insertion Enable. When set, allows           */
/*       consequent actions from the SFU (CBRGENAIS) to         */
/*       automatically force insertion of PP10G payload into    */
/*       data stream.                                           */
/*                                                              */
/* The [cbrstmaisins] parameter is specified as:                */
/*   0                                                          */
/*   1 = Force CBRGENAIS/STM-AIS insertion. When set, forces    */
/*       insertion of OTN payload PN-11 (CBRGENAIS) or STM-AIS  */
/*       signal into data stream.                               */
/*                                                              */
/* The [pn11auto] parameter is specified as:                    */
/*   0                                                          */
/*   1 = PN-11 Automatic Insertion Enable. When set, allows     */
/*       consequent actions from the SFU to automatically force */
/*       insertion of PN-11 for CBRGENAIS (for OTN) or STM-AIS  */
/*       (for SONET/SDH).                                       */
/*                                                              */
/* The [otnoff] parameter is specified as:                      */
/*   0                                                          */
/*   1 = OTN OFF. When set the OTN module is disconnected from  */
/*       the clock. This feature may be used to save power when */
/*       no OTN functionality is needed.                        */
/*                                                              */
/* The [oby] parameter is specified as:                         */
/*   0                                                          */
/*   1 = OTN Bypass Enable. Set when transmitting an OC-48 data */
/*       stream.                                                */
/*                                                              */
/* The [sby] parameter is specified as:                         */
/*   0                                                          */
/*   1 = SDH BYpass Enable. Set when transmitting a wrapped     */
/*       2.5 Gbit/s data stream without SDH content.            */
/*                                                              */
/* The [kpgby] parameter is specified as:                       */
/*   0                                                          */
/*   1 = KPG Bypass Enable. Set when Known Pattern Generator    */
/*       needs to be bypassed.                                  */
/*                                                              */
/* The [pktie] parameter is specified as:                       */
/*   Packet mode enable.                                        */
/*   Note: If PKTIE is set to 1, A1A2IE needs to be set for     */
/*         SONET.                                               */
/*   0 = Tx is receiving frames.                                */
/*   1 = Tx is receiving packets.                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
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
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.PPLF_EN = pplf_en;
      tmp_gblt_cfgtx0.bf.CBRSTMAISINS = cbrstmaisins;
      tmp_gblt_cfgtx0.bf.PN11AUTO = pn11auto;
      tmp_gblt_cfgtx0.bf.OTNOFF = otnoff;
      tmp_gblt_cfgtx0.bf.OBY = oby;
      tmp_gblt_cfgtx0.bf.SBY = sby;
      tmp_gblt_cfgtx0.bf.KPGBY = kpgby;
      tmp_gblt_cfgtx0.bf.PKTIE = pktie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 10G KNOWN PATTERN GENERATOR        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_config_kpg(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_ctl_t kpg_bypass,
                              cs_ctl_t kpg_auto,
                              cs_uint16 pattern,
                              cs_uint16 fpat1,
                              cs_uint16 fpat0)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o KPG Bypass Control                            */
/*              o KPG Auto Control                              */
/*              o Pattern Selection                             */
/*              o Fixed Pattern 1                               */
/*              o Fixed Pattern 0                               */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable/Disable the 10G Known Pattern Generator.  The pattern */
/* selection is either TEN_PN11, TEN_PN23, or TEN_PN31          */
/* with fpat1-0 parameters unused and set to 0, or              */
/* TEN_FIXED_PATTERN with fpat1-0 set to the fixed pattern.     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [kpg_bypass] parameter is specified as:                  */
/*   CS_DISABLE (Permits Known Pattern Generator operation) or  */
/*   CS_ENABLE (Known Pattern Generator needs to be bypassed)   */
/*                                                              */
/* The [kpg_auto] parameter is specified as:                    */
/*   CS_DISABLE (Permits Known Pattern Generator operation) or  */
/*   CS_ENABLE (Known Pattern Generator into the signal path is */
/*              sourced from the Generator Overhead and Control */
/*              Stream Framing)                                 */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   TEN_KPG_FIXED_PATTERN = 0,                                 */
/*   TEN_KPG_PN11 = 1,                                          */
/*   TEN_KPG_PN23 = 2,                                          */
/*   TEN_KPG_PN31 = 3                                           */
/*                                                              */
/* The [fpat1-0] parameter is specified as:                     */
/*   Fixed pattern for Known Pattern Generator                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
  TEN_N10G_GBLT_KPGCFG_t tmp_gblt_kpgcfg;
  TEN_N10G_GBLT_FPAT0_t tmp_gblt_fpat0;
  TEN_N10G_GBLT_FPAT1_t tmp_gblt_fpat1;
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
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.KPGBY = kpg_bypass;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);
      
      tmp_gblt_kpgcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPGCFG));
      tmp_gblt_kpgcfg.bf.KPGAUTO = kpg_auto;
      tmp_gblt_kpgcfg.bf.PATSEL = pattern;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPGCFG), tmp_gblt_kpgcfg.wrd);

      tmp_gblt_fpat0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, FPAT0));
      tmp_gblt_fpat0.bf.FPAT0 = fpat0;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, FPAT0), tmp_gblt_fpat0.wrd);

      tmp_gblt_fpat1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, FPAT1));
      tmp_gblt_fpat1.bf.FPAT1 = fpat1;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, FPAT1), tmp_gblt_fpat1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET TX GLOBAL BYPASSES                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_gblt_bypasses(cs_uint16 module_id,
                                   cs_uint8 slice, 
                                   cs_uint16 otnoff, 
                                   cs_uint16 oby, 
                                   cs_uint16 sby, 
                                   cs_uint16 kpgby)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o OTNOFF                                        */
/*              o OBY                                           */
/*              o SBY                                           */
/*              o KPGBY                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Tx Global Configuration.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [otnoff] parameter is specified as:                      */
/*   0                                                          */
/*   1 = OTN OFF. When set the OTN module is disconnected from  */
/*       the clock. This feature may be used to save power when */
/*       no OTN functionality is needed.                        */
/*                                                              */
/* The [oby] parameter is specified as:                         */
/*   0                                                          */
/*   1 = OTN Bypass Enable. Set when transmitting an OC-48 data */
/*       stream.                                                */
/*                                                              */
/* The [sby] parameter is specified as:                         */
/*   0                                                          */
/*   1 = SDH BYpass Enable. Set when transmitting a wrapped     */
/*       2.5 Gbit/s data stream without SDH content.            */
/*                                                              */
/* The [kpgby] parameter is specified as:                       */
/*   0                                                          */
/*   1 = KPG Bypass Enable. Set when Known Pattern Generator    */
/*       needs to be bypassed.                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
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
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.OTNOFF = otnoff;
      tmp_gblt_cfgtx0.bf.OBY = oby;
      tmp_gblt_cfgtx0.bf.SBY = sby;
      tmp_gblt_cfgtx0.bf.KPGBY = kpgby;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET TX GLOBAL OTNOFF                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_gblt_otnoff(cs_uint16 module_id,
                                   cs_uint8 slice, 
                                   cs_uint16 otnoff)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o OTNOFF                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Tx Global OTNOFF.                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [otnoff] parameter is specified as:                      */
/*   0                                                          */
/*   1 = OTN OFF. When set the OTN module is disconnected from  */
/*       the clock. This feature may be used to save power when */
/*       no OTN functionality is needed.                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
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
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.OTNOFF = otnoff;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET PKTIE                               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_pktie(cs_uint16 module_id,
                             cs_uint8 slice,  
                             cs_uint16 pktie)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PKTIE                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the PKTIE bit in the Tx Global Configuration register.  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */

/* The [pktie] parameter is specified as:                       */
/*   Packet mode enable.                                        */
/*   Note: If PKTIE is set to 1, A1A2IE needs to be set for     */
/*         SONET.                                               */
/*   0 = Tx is receiving frames, PP10G is bypassed.             */
/*   1 = Tx is receiving packets.                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
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
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.PKTIE = pktie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET TX PPLF_EN                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_pplf_en(cs_uint16 module_id,
                               cs_uint8 slice, 
                               cs_uint16 pplf_en)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PPLF EN                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Tx Global Configuration.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [pplf_en] parameter is specified as:                     */
/*   0                                                          */
/*   1 = Link Fail Insertion Enable. When set, allows           */
/*       consequent actions from the SFU (CBRGENAIS) to         */
/*       automatically force insertion of PP10G payload into    */
/*       data stream.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
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
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.PPLF_EN = pplf_en;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET TX CBRSTMAISINS                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_cbrstmaisins(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_uint16 cbrstmaisins)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o CBRSTMAISINS                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Tx Global Configuration.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [cbrstmaisins] parameter is specified as:                */
/*   0                                                          */
/*   1 = Force CBRGENAIS/STM-AIS insertion. When set, forces    */
/*       insertion of OTN payload PN-11 (CBRGENAIS) or STM-AIS  */
/*       signal into data stream.                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
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
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.CBRSTMAISINS = cbrstmaisins;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET TX PN11AUTO                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_pn11auto(cs_uint16 module_id,
                                cs_uint8 slice, 
                                cs_uint16 pn11auto)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PN11AUTO                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Tx Global Configuration.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [pn11auto] parameter is specified as:                    */
/*   0                                                          */
/*   1 = PN-11 Automatic Insertion Enable. When set, allows     */
/*       consequent actions from the SFU to automatically force */
/*       insertion of PN-11 for CBRGENAIS (for OTN) or STM-AIS  */
/*       (for SONET/SDH).                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
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
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.PN11AUTO = pn11auto;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET TX SBY                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_sby(cs_uint16 module_id,
                           cs_uint8 slice, 
                           cs_uint16 sby)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o SBY                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Tx Global Configuration.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [pn11auto] parameter is specified as:                    */
/*   0                                                          */
/*   1 = SDH BYpass Enable. Set when transmitting a wrapped     */
/*       2.5 Gbit/s data stream without SDH content.            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
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
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.SBY = sby;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

