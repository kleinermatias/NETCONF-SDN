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
 * ten_n40g_gblt4x.c
 *
 * N40G related code is implemented here.
 *
 * $Id: ten_n40g_gblt4x.c,v 1.8 2013/02/22 20:44:38 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N40G SET DATA PATH CONFIGURATION REGISTER    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_gblt4x_set_cfg(cs_uint16 module_id, 
                                  cs_uint16 kpgby, 
                                  cs_uint16 sby, 
                                  cs_uint16 oby, 
                                  cs_uint16 mdpcfg)
/* INPUTS     : o Module Id                                     */
/*              o KPGBY                                         */
/*              o SBY                                           */
/*              o OBY                                           */
/*              o MDPCFG                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the contents of the Data Path Configuration Register.    */
/*                                                              */
/* The [kpgby] parameter is specified as:                       */
/*   0                                                          */
/*   1 = KPG Bypass Enable. Set when the Known Pattern          */
/*       Generator needs to be bypassed.                        */
/*                                                              */
/* The [sby] parameter is specified as:                         */
/*   0                                                          */
/*   1 = SDH Bypass Enable. Should be set when receiving an     */
/*       unwrapped 10 Gbit/s Ethernet data stream.              */
/*                                                              */
/* The [oby] parameter is specified as:                         */
/*   0                                                          */
/*   1 = OBYOTN Bypass Enable. Set when a STM-64/OC-192 data    */
/*       stream is received.                                    */
/*                                                              */
/* The [mdpcfg] parameter is specified as:                      */
/*   Main Data Path Configuration.                              */
/*   0b00 = OTN Aggregation Mode and Generic Splitting          */
/*   0b01 = OTN Reverse Multiplexing Mode                       */
/*   0b10 = SDH Reverse Multiplexing Mode - 16-byte interleave  */
/*   0b11 = SDH Reverse Multiplexing Mode - 64-byte interleave  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_gblt4x_cfg;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_gblt4x_set_cfg";  
  CS_PRINT("%s() %s, kpgby=%d, sby=%d, oby=%d, mdpcfg=%d\n", 
           func, ten_module_strings[module_id&1], kpgby, sby, oby, mdpcfg);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_gblt4x_cfg.bf.KPGBY = kpgby;
  tmp_gblt4x_cfg.bf.SBY = sby;
  tmp_gblt4x_cfg.bf.OBY = oby;
  tmp_gblt4x_cfg.bf.MDPCFG = mdpcfg;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_gblt4x_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET TX CBRSTMAISINS                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_cbrstmaisins(cs_uint16 module_id, 
                                    cs_uint16 cbrstmaisins)

/* INPUTS     : o Module Id                                     */
/*              o CBRSTMAISINS                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the contents of the Data Path Configuration Register.    */
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
  TEN_N40G_GBLT4X_CFG_t tmp_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_gblt4x_cfg.bf.CBRSTMAISINS = cbrstmaisins;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_gblt4x_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET TX DSBLDSKW                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_dsbldskw(cs_uint16 module_id, 
                                    cs_uint16 dsbldskw)
/* INPUTS     : o Module Id                                     */
/*              o DSBLDSKW                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Disable deskew function which aligns 4 incoming streams by   */
/* frame pulse.                                                 */
/*                                                              */
/* The [dsbldskw] parameter is specified as:                    */
/*   0 = default                                                */
/*   1 = Disable deskew function which aligns 4 incoming        */
/*       streams by frame pulse.  This must must be set to '1'  */
/*       during aggregation if all 4 tributaries do not         */
/*       contain an ODU2 signal.                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_gblt4x_cfg.bf.DSBLDSKW = dsbldskw;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_gblt4x_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET TX PN11AUTO                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_pn11auto(cs_uint16 module_id, 
                                    cs_uint16 pn11auto)

/* INPUTS     : o Module Id                                     */
/*              o PN11AUTO                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the contents of the Data Path Configuration Register.    */
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
  TEN_N40G_GBLT4X_CFG_t tmp_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_gblt4x_cfg.bf.PN11AUTO = pn11auto;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_gblt4x_cfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 40G KNOWN PATTERN GENERATOR        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                         */
cs_status ten_n40g_config_kpg(cs_uint16 module_id,
                              cs_uint16 kpg_bypass,
                              cs_uint16 kpg_auto,
                              cs_uint16 pattern,
                              cs_uint16 fpat7,
                              cs_uint16 fpat6,
                              cs_uint16 fpat5,
                              cs_uint16 fpat4,
                              cs_uint16 fpat3,
                              cs_uint16 fpat2,
                              cs_uint16 fpat1,
                              cs_uint16 fpat0)
/* INPUTS     : o Module Id                                     */
/*              o KPG Bypass Control                            */
/*              o KPG Auto Control                              */
/*              o Pattern Selection                             */
/*              o Fixed Pattern 7                               */
/*              o Fixed Pattern 6                               */
/*              o Fixed Pattern 5                               */
/*              o Fixed Pattern 4                               */
/*              o Fixed Pattern 3                               */
/*              o Fixed Pattern 2                               */
/*              o Fixed Pattern 1                               */
/*              o Fixed Pattern 0                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable/Disable the 10G Known Pattern Generator.  The pattern */
/* selection is either TEN_PN11, TEN_PN23, or TEN_PN31          */
/* with fpat1-0 parameters unused and set to 0, or              */
/* TEN_FIXED_PATTERN with fpat1-0 set to the fixed pattern.     */
/*                                                              */
/* The [kpg_bypass] parameter is specified as:                  */
/*   CS_DISABLE = enables the Known Pattern Generator output to */
/*     be sent to the OTN Wrapper as payload (OBY=0) or output  */
/*     directly to the line interface (OBY=1). Data from the    */
/*     XCON/N10G is ignored.                                    */
/*   CS_ENABLE = enables data from the XCON/N10G or the 40G     */
/*     SONET/SDH Generator to be used as OTN Wrapper payload or */
/*     output directly to the line interface.                   */
/*   Note: For KPG insertion into SONET/SDH payload, this bit   */
/*     must be set to '1' (CS_ENABLE).                          */
/*                                                              */
/* The [kpg_auto] parameter is specified as:                    */
/*   CS_DISABLE = Permits Known Pattern Generator operation     */
/*   CS_ENABLE  = KPGBY is ignored and the decision whether to  */
/*     bypass or include the Known Pattern Generator into the   */
/*     signal path is sourced from the Generator Overhead and   */
/*     Control Stream Framing (also referred to as FPGA data    */
/*     stream): The KPG is bypassed when bit '0' in byte '1'of  */
/*     that stream is set to '0'.                               */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   TEN_KPG_FIXED_PATTERN = 0,                                 */
/*   TEN_KPG_PN11 = 1,                                          */
/*   TEN_KPG_PN23 = 2,                                          */
/*   TEN_KPG_PN31 = 3                                           */
/*                                                              */
/* The [fpat7-0] parameter is specified as:                     */
/*   Fixed pattern for Known Pattern Generator                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_gblt4x_cfg;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_gblt4x_kpgcfg;
  TEN_N40G_GBLT4X_FPAT7_t tmp_gblt4x_fpat7;
  TEN_N40G_GBLT4X_FPAT6_t tmp_gblt4x_fpat6;
  TEN_N40G_GBLT4X_FPAT5_t tmp_gblt4x_fpat5;
  TEN_N40G_GBLT4X_FPAT4_t tmp_gblt4x_fpat4;
  TEN_N40G_GBLT4X_FPAT3_t tmp_gblt4x_fpat3;
  TEN_N40G_GBLT4X_FPAT2_t tmp_gblt4x_fpat2;
  TEN_N40G_GBLT4X_FPAT1_t tmp_gblt4x_fpat1;
  TEN_N40G_GBLT4X_FPAT0_t tmp_gblt4x_fpat0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_gblt4x_cfg.bf.KPGBY = kpg_bypass;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_gblt4x_cfg.wrd);
  
  tmp_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
  tmp_gblt4x_kpgcfg.bf.KPGAUTO = kpg_auto;
  tmp_gblt4x_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_gblt4x_kpgcfg.wrd);
  
  tmp_gblt4x_fpat7.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, FPAT7));
  tmp_gblt4x_fpat7.bf.FPAT7 = fpat7;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, FPAT7), tmp_gblt4x_fpat7.wrd);
  
  tmp_gblt4x_fpat6.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, FPAT6));
  tmp_gblt4x_fpat6.bf.FPAT6 = fpat6;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, FPAT6), tmp_gblt4x_fpat6.wrd);
  
  tmp_gblt4x_fpat5.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, FPAT5));
  tmp_gblt4x_fpat5.bf.FPAT5 = fpat5;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, FPAT5), tmp_gblt4x_fpat5.wrd);
  
  tmp_gblt4x_fpat4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, FPAT4));
  tmp_gblt4x_fpat4.bf.FPAT4 = fpat4;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, FPAT4), tmp_gblt4x_fpat4.wrd);
  
  tmp_gblt4x_fpat3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, FPAT3));
  tmp_gblt4x_fpat3.bf.FPAT3 = fpat3;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, FPAT3), tmp_gblt4x_fpat3.wrd);
  
  tmp_gblt4x_fpat2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, FPAT2));
  tmp_gblt4x_fpat2.bf.FPAT2 = fpat2;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, FPAT2), tmp_gblt4x_fpat2.wrd);
  
  tmp_gblt4x_fpat1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, FPAT1));
  tmp_gblt4x_fpat1.bf.FPAT1 = fpat1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, FPAT1), tmp_gblt4x_fpat1.wrd);
  
  tmp_gblt4x_fpat0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, FPAT0));
  tmp_gblt4x_fpat0.bf.FPAT0 = fpat0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, FPAT0), tmp_gblt4x_fpat0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}


