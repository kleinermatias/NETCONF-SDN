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
 * ten_n40g_sdfr.c
 *
 * N40G related code is implemented here.
 *
 * $Id: ten_n40g_sdfr.c,v 1.6 2013/02/22 20:44:38 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N40G GET SONET/SDH RECEIVER STATUS           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n40g_get_sdfr_rx_status(cs_uint16 module_id,
                                     cs_uint16 field)
/* INPUTS     : o Module Id                                     */
/*              o Field                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : The requested field from the SONET/SDH Receiver */
/*              Status Register.                                */
/* DESCRIPTION:                                                 */
/* Returns the requested field from the SONET/SDH Receiver      */
/* Status Register.                                             */
/*                                                              */
/* The [field] parameter is specified as:                       */
/*   TEN_SDFR_SDFSTAT_PN11S                                     */
/*   TEN_SDFR_SDFSTAT_SD                                        */
/*   TEN_SDFR_SDFSTAT_SF                                        */
/*   TEN_SDFR_SDFSTAT_B1INVS                                    */
/*   TEN_SDFR_SDFSTAT_LOSS                                      */
/*   TEN_SDFR_SDFSTAT_LOFS                                      */
/*   TEN_SDFR_SDFSTAT_OOFS                                      */
/*   TEN_SDFR_SDFSTAT_ALL (whole reg) 0xFF.                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N40G_SDFR_SDFSTAT_t tmp_sdfr_sdfstat;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  tmp_sdfr_sdfstat.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFSTAT));
  switch (field) {
  case TEN_SDFR_SDFSTAT_PN11S :
    {
      rtn = tmp_sdfr_sdfstat.bf.PN11S;
      break;
    }
  case TEN_SDFR_SDFSTAT_SD :
    {
      rtn = tmp_sdfr_sdfstat.bf.SD;
      break;
    }
  case TEN_SDFR_SDFSTAT_SF :
    {
      rtn = tmp_sdfr_sdfstat.bf.SF;
      break;
    }
  case TEN_SDFR_SDFSTAT_B1INVS :
    {
      rtn = tmp_sdfr_sdfstat.bf.B1INVS;
      break;
    }
  case TEN_SDFR_SDFSTAT_LOSS :
    {
      rtn = tmp_sdfr_sdfstat.bf.LOSS;
      break;
    }
  case TEN_SDFR_SDFSTAT_LOFS :
    {
      rtn = tmp_sdfr_sdfstat.bf.LOFS;
      break;
    }
  case TEN_SDFR_SDFSTAT_OOFS :
    {
      rtn = tmp_sdfr_sdfstat.bf.OOFS;
      break;
    }
  case TEN_SDFR_SDFSTAT_ALL :
    {
      rtn = tmp_sdfr_sdfstat.wrd;
      break;
    }
  default :
    {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..6, 0xFF.");
      rtn = CS_ERROR;
      break;
    } 
  }
  return (rtn);
  
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET LOSS-OF-FRAME TIME SPAN CONFIG REG  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_sdfr_lofcfg1(cs_uint16 module_id, 
                                    cs_uint16 lofimou, 
                                    cs_uint16 lofimin)
/* INPUTS     : o Module Id                                     */
/*              o LOFIMOU                                       */
/*              o LOFIMIN                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This sets the contents of the Loss-Of-Frame Time Span        */
/* Configuration Register.                                      */
/*                                                              */
/* The [lofimou] parameter is specified as                      */
/*   0x00-0xFF                                                  */
/*   This bit field configures the number of consecutive frames */
/*   subject to an Out-Of-Frame alarm that triggers a reset of  */
/*   the non-OOF counter while in LOF state.                    */
/*   Note: Configuring this bit field with values of '0' or '1' */
/*   causes the state machine to ignore this threshold          */
/*   altogether.                                                */
/*                                                              */
/* The [lofimin] parameter is specified as                      */
/*   0x00-0xFF                                                  */
/*   This bit field configures the number of consecutive frames */
/*   that must be free of an Out-Of-Frame alarm while not in    */
/*   LOF state in order to trigger a reset of the OOF counter.  */
/*   Note: Configuring this bit field with values of '0' or '1' */
/*   causes the state machine to ignore this threshold          */
/*   altogether.                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_SDFR_LOFCFG1_t tmp_sdfr_lofcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_lofcfg1.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, LOFCFG1));
  tmp_sdfr_lofcfg1.bf.LOFIMOU = lofimou;
  tmp_sdfr_lofcfg1.bf.LOFIMIN = lofimin;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, LOFCFG1), tmp_sdfr_lofcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET B1 BIT ERROR THRESHOLD REGISTER     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_sdfr_b1btber(cs_uint16 module_id, 
                                    cs_uint16 b1btber)
/* INPUTS     : o Module Id                                     */
/*              o B1BTBER                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This bit field sets the threshold for B1-byte bit errors to  */
/* be compared with the bit-level parity error count in         */
/* SDFR:B1BTER and produce an interrupt in SDFR:B1BTEX (see     */
/* page SDFR_B1BTEX) if the threshold is exceeded.              */
/* Note: For non-operational purposes it may be indicated to    */
/* set the B1BTBER threshold to its maximum value of 0xFFFF     */
/* in which case the SDFR:B1BTEX interrupt will occur only if   */
/* the counter overflows (causing it to stop at its maximum     */
/* value). Conversely, by letting the SDFR:B1BTBER threshold    */
/* default to '0' the interrupt is set upon the first parity    */
/* error.                                                       */
/*                                                              */
/* The [b1btber] parameter is specified as:                     */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_SDFR_B1BTBER_t tmp_sdfr_b1btber;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_b1btber.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B1BTBER));
  tmp_sdfr_b1btber.bf.B1BTBER = b1btber;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B1BTBER), tmp_sdfr_b1btber.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET B1 BLOCK LEVEL ERROR ERROR THRESHOLD*/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_sdfr_b1blber(cs_uint16 module_id, 
                                    cs_uint16 b1blber)
/* INPUTS     : o Module Id                                     */
/*              o B1BLBER                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This bit field sets the threshold for B1-byte block-level    */
/* errors to be compared with the parity error count in         */
/* SDFR:B1BLER and produce an interrupt in SDFR:B1BLEX (see     */
/* page SDFR_B1BLEX) if the threshold is exceeded.              */
/* Note: For non-operational purposes it may be indicated to    */
/* set the SDFR:B1BLBER threshold to its maximum value of       */
/* 0x1FFF in which case the SDFR:B1BLEX interrupt will occur    */
/* only if the counter overflows (causing it to stop at its     */
/* maximum value). Conversely, by letting the SDFR:B1BLBER      */
/* threshold default to '0' the interrupt is set upon the first */
/* parity error.                                                */
/*                                                              */
/* The [b1blber] parameter is specified as:                     */
/*   0x0000-0x1FFF                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_SDFR_B1BLBER_t tmp_sdfr_b1blber;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_b1blber.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B1BLBER));
  tmp_sdfr_b1blber.bf.B1BLBER = b1blber;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B1BLBER), tmp_sdfr_b1blber.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET B2 BIT ERROR THRESHOLD REGISTER     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_sdfr_b2btber(cs_uint16 module_id, 
                                    cs_uint16 b2btber0,
                                    cs_uint16 b2btber1)

/* INPUTS     : o Module Id                                     */
/*              o B2BTBER0                                      */
/*              o B2BTBER1                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This bit field sets the threshold for B2-byte bit errors to  */
/* be compared with the bit-level parity error count in         */
/* SDFR:B2BTER and produce an interrupt in SDFR:B2BTEX (see     */
/* page SDFR_B2BTEX) if the threshold is exceeded.              */
/* Note 1: For non-operational purposes, it may be indicated to */
/* set the B2BTBER threshold to its maximum value of 0xFFFFFF   */
/* in which case the interrupt in SDFR:B2BTEX will occur only   */
/* if the counter overflows (causing it to stop at its maximum  */
/* value). Conversely, by letting the SDFR:B2BTBER threshold    */
/* default to '0' the interrupt is set upon the first parity    */
/* error.                                                       */
/* Note 2: For STM-16/OC-48, do not use a value greater than    */
/* 0x3FFFFF.                                                    */
/*                                                              */
/* The [b2btber0] parameter is specified as:                    */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* The [b2btber1] parameter is specified as:                    */
/*   0x0000-0x00FF                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_SDFR_B2BTBER0_t tmp_sdfr_b2btber0;
  TEN_N40G_SDFR_B2BTBER1_t tmp_sdfr_b2btber1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_b2btber0.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B2BTBER0));
  tmp_sdfr_b2btber0.bf.B2BTBER0 = b2btber0;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B2BTBER0), tmp_sdfr_b2btber0.wrd);
  tmp_sdfr_b2btber1.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B2BTBER1));
  tmp_sdfr_b2btber1.bf.B2BTBER1 = b2btber1;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B2BTBER1), tmp_sdfr_b2btber1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET B2 BLOCK LEVEL ERROR ERROR THRESHOLD*/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_sdfr_b2blber(cs_uint16 module_id, 
                                    cs_uint16 b2blber0,
                                    cs_uint16 b2blber1)
/* INPUTS     : o Module Id                                     */
/*              o B2BLBER0                                      */
/*              o B2BLBER1                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This bit field sets the threshold for B2-byte block-level    */
/* errors to be compared with the parity error count in         */
/* SDFR:B2BLER and produce an interrupt in SDFR:B2BLEX (see     */
/* page SDFR_B2BLEX) if the threshold is exceeded.              */
/* Note 1: For non-operational purposes, it may be indicated to */
/* set the SDFR:B2BLBER threshold to its maximum value of       */
/* 0x7FFFF in which case the interrupt in SDFR:B2BLEX will      */
/* occur only if the counter overflows (causing it to stop at   */
/* its maximum value). Conversely, by letting the SDFR:B2BLBER  */
/* threshold default to '0' the interrupt is set upon the first */
/* parity error.                                                */
/* Note 2: For STM-16/OC-48, do not use a value greater than    */
/* 0x1FFFF.                                                     */
/*                                                              */
/* The [b2blber0] parameter is specified as:                    */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* The [b2blber1] parameter is specified as:                    */
/*   0x0000-0x0007                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_SDFR_B2BLBER0_t tmp_sdfr_b2blber0;
  TEN_N40G_SDFR_B2BLBER1_t tmp_sdfr_b2blber1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_b2blber0.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B2BLBER0));
  tmp_sdfr_b2blber0.bf.B2BLBER0 = b2blber0;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B2BLBER0), tmp_sdfr_b2blber0.wrd);
  tmp_sdfr_b2blber1.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B2BLBER1));
  tmp_sdfr_b2blber1.bf.B2BLBER1 = b2blber1;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, B2BLBER1), tmp_sdfr_b2blber1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G ENABLE SDH/SONET DESCRAMBLER            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_sdfr_enable_descrambler(cs_uint16 module_id, 
                                           cs_uint16 scren)
/* INPUTS     : o Module Id                                     */
/*              o SCREN                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable the SDH/SONET Descrambler.                            */
/*                                                              */
/* The [scren] parameter is specified as:                       */
/*   0 = Descrambler disabled                                   */
/*   1 = Descrambler enabled                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_SDFR_SDFCFG_t tmp_sdfr_sdfcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_sdfcfg.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG));
  tmp_sdfr_sdfcfg.bf.SCREN = scren;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG), tmp_sdfr_sdfcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SDFR SET SDFCFG REGISTER                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_sdfr_set_sdfcfg(cs_uint16 module_id, 
                                   cs_uint16 scren, 
                                   cs_uint16 oofhy, 
                                   cs_uint16 fawwup, 
                                   cs_uint16 fawwdw)
/* INPUTS     : o Module Id                                     */
/*              o SCREN                                         */
/*              o OOFHY                                         */
/*              o FAWWUP                                        */
/*              o FAWWDW                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets aspects of SONET/SDH Receiver Configuration             */
/*                                                              */
/*   [scren]  This bit controls the SDH/SONET descrambler:      */
/*     0 = Descrambler disabled                                 */
/*     1 = Descrambler enabled                                  */
/*                                                              */
/*   [oofhy]  This bit field configures the number of           */
/*     consecutive frames with erroneous frame alignment        */
/*     sequences (FAS) that have to be detected before the      */
/*     aligner enters OOF state after having received a         */
/*     frame with a correct FAS.                                */
/*                                                              */
/*   [fawwup]  This bit field configures the search pattern     */
/*     that is used while not in In-Frame state in order to     */
/*     find the Frame Alignment Sequence (FAS) within the       */
/*     incoming data.                                           */
/*     0 = Search for pattern f6f6 2828 hex                     */
/*     1 = Search for pattern 6f6f6 28282 hex                   */
/*     2 = Search for pattern f6f6f6 282828 hex                 */
/*     3 = Search for pattern 6f6f6f6 2828282 hex               */
/*     4 = Search for pattern f6f6f6f6 28282828 hex             */
/*                                                              */
/*   [fawwdw]  This bit field configures the reference          */
/*     pattern that is used while in In-Frame state to check    */
/*     that the Frame Alignment Sequence (FAS) occurs at        */
/*     its expected position within the incoming data stream.   */
/*     0 = Compare with pattern f6f6 2828 hex                   */
/*     1 = Compare with pattern 6f6f6 28282 hex                 */
/*     2 = Compare with pattern f6f6f6 282828 hex               */
/*     3 = Compare with pattern 6f6f6f6 2828282 hex             */
/*     4 = Compare with pattern f6f6f6f6 28282828 hex.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_SDFR_SDFCFG_t tmp_sdfr_sdfcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_sdfcfg.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG));
  tmp_sdfr_sdfcfg.bf.SCREN = scren;
  tmp_sdfr_sdfcfg.bf.OOFHY = oofhy;
  tmp_sdfr_sdfcfg.bf.FAWWUP = fawwup;
  tmp_sdfr_sdfcfg.bf.FAWWDW = fawwdw;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG), tmp_sdfr_sdfcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SDFR SET SDFCFG FAWWUP AND FAWWDN       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_sdfr_set_sdfcfg_fawwup_fawwdw(cs_uint16 module_id, 
                                   cs_uint16 fawwup, 
                                   cs_uint16 fawwdw)
/* INPUTS     : o Module Id                                     */
/*              o FAWWUP                                        */
/*              o FAWWDW                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets fawwup and fawwdw.                                      */
/*                                                              */
/*   [fawwup]  This bit field configures the search pattern     */
/*     that is used while not in In-Frame state in order to     */
/*     find the Frame Alignment Sequence (FAS) within the       */
/*     incoming data.                                           */
/*     0 = Search for pattern f6f6 2828 hex                     */
/*     1 = Search for pattern 6f6f6 28282 hex                   */
/*     2 = Search for pattern f6f6f6 282828 hex                 */
/*     3 = Search for pattern 6f6f6f6 2828282 hex               */
/*     4 = Search for pattern f6f6f6f6 28282828 hex             */
/*                                                              */
/*   [fawwdw]  This bit field configures the reference          */
/*     pattern that is used while in In-Frame state to check    */
/*     that the Frame Alignment Sequence (FAS) occurs at        */
/*     its expected position within the incoming data stream.   */
/*     0 = Compare with pattern f6f6 2828 hex                   */
/*     1 = Compare with pattern 6f6f6 28282 hex                 */
/*     2 = Compare with pattern f6f6f6 282828 hex               */
/*     3 = Compare with pattern 6f6f6f6 2828282 hex             */
/*     4 = Compare with pattern f6f6f6f6 28282828 hex.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_SDFR_SDFCFG_t tmp_sdfr_sdfcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_sdfcfg.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG));
  tmp_sdfr_sdfcfg.bf.FAWWUP = fawwup;
  tmp_sdfr_sdfcfg.bf.FAWWDW = fawwdw;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG), tmp_sdfr_sdfcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SDFR SET SDFCFG1 REGISTER               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_sdfr_set_sdfcfg1(cs_uint16 module_id, 
                                    cs_uint16 altscr)
/* INPUTS     : o Module Id                                     */
/*              o ALTSCR                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets aspects of SONET/SDH Receiver Configuration             */
/*                                                              */
/*   [altscr]  This bit is used to enable                       */
/*     pseudo-STS-768/STM-256 descrambling for STS-192/STM-64   */
/*     frames.  Has no effect on STS-768/STM-256 frames.        */
/*     0 = Normal standards-compliant scrambling.               */
/*     1 = Enable alternate descrambling. All data except last  */
/*     16 A1 and first 16 A2 bytes are descrambled.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_SDFR_SDFCFG1_t tmp_sdfr_sdfcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_sdfcfg1.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG1));
  tmp_sdfr_sdfcfg1.bf.ALTSCR = altscr;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG1), tmp_sdfr_sdfcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SDFR SELECT GLOBAL TIMING SOURCE        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_sdfr_select_global_timing_source(cs_uint16 module_id, 
                                                    cs_uint16 select)
/* INPUTS     : o Module Id                                     */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Selects one out of eight different statistics timing         */
/* generators.                                                  */
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
  TEN_N40G_SDFR_LOFCFG2_t tmp_sdfr_lofcfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_lofcfg2.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, LOFCFG2));
  tmp_sdfr_lofcfg2.bf.EOFGCFG = select;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, LOFCFG2), tmp_sdfr_lofcfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G SDFR LOFCFG2 M0BYTE                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_sdfr_lofcfg2_m0byte(cs_uint16 module_id, 
                            cs_uint16 m0byte)
/* INPUTS     : o Module Id                                         */
/*              o M0BYTE                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Determines whether the reflected M1 byte alone or both           */
/* reflected M0 and M1 bytes are included in the calculation        */
/* of error statistics.                                             */
/*                                                                  */
/*   [m0byte]                                                       */
/*      0 = Use M1 byte only as input to error statistics.          */
/*      1 = Use both M0 and M1 bytes as inputs to error statistics. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_SDFR_LOFCFG2_t tmp_sdfr_lofcfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_sdfr_lofcfg2.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, LOFCFG2));
  tmp_sdfr_lofcfg2.bf.M0BYTE = m0byte;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, LOFCFG2), tmp_sdfr_lofcfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}



