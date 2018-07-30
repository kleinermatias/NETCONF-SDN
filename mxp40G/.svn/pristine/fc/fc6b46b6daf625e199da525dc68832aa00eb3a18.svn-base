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
 * ten_n10g_sohr.c
 *
 * N10G related code is implemented here.
 *
 * $Id: ten_n10g_sohr.c,v 1.7 2013/02/22 20:47:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N10G GET THE OVERHEAD K1/K2/S1 BYTE RECEIVED */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n10g_get_overhead_byte(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_uint16 ovrhd)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Overhead Byte Type                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : The requested overhead byte                     */
/* DESCRIPTION:                                                 */
/* Reads the received overhead byte from the SONET RX stream.   */
/* The overhead byte is read from the Framer register. Some     */
/* of these overhead bytes debounced in hardware while other    */
/* are updated with every SONET Frame received.                 */
/* Some bytes are available as filtered and extracted.          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [ovrhd] parameter is specified as following:             */
/*   TEN_OVRHD_FILTERED_K1                                      */
/*   TEN_OVRHD_FILTERED_K2                                      */
/*   TEN_OVRHD_EXTRACTED_S1.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = 0;
  
  TEN_N10G_VALIDATE(module_id, slice);
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(0);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  
  switch (ovrhd) {
  case TEN_OVRHD_FILTERED_K1:
    {
      TEN_N10G_SOHR_K12_t tmp_n10g_sohr_k12;
      tmp_n10g_sohr_k12.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, K12));
      rtn = (cs_int16)(tmp_n10g_sohr_k12.bf.K1R & 0xFF);
      break;
    }
  case TEN_OVRHD_FILTERED_K2:
    {
      TEN_N10G_SOHR_K12_t tmp_n10g_sohr_k12;
      tmp_n10g_sohr_k12.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, K12));
      rtn = (cs_int16)(tmp_n10g_sohr_k12.bf.K2R & 0xFF);
      break;
    }
  case TEN_OVRHD_EXTRACTED_S1:
    {
      TEN_N10G_SOHR_S1R_t tmp_n10g_sohr_s1r;
      tmp_n10g_sohr_s1r.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, S1R));
      rtn = (cs_int16)(tmp_n10g_sohr_s1r.bf.S1R & 0xFF);
      break;
    }
  default:
    {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..2.");
      rtn = 0;
      break;
    } 
  }
  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N10G GET MST STATUS                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n10g_get_mst_status(cs_uint16 module_id,
                                 cs_uint8 slice, 
                                 cs_uint16 field)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Field                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : The requested field from the POHR Ohpstat       */
/*              Register.                                       */
/* DESCRIPTION:                                                 */
/* Returns the requested field from the POHR Ohpstat Register.  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [field] parameter is specified as:                       */
/*   TEN_NX0G_SOHR_OHPSTAT_AISC                                 */
/*   TEN_NX0G_SOHR_OHPSTAT_AIS                                  */
/*   TEN_NX0G_SOHR_OHPSTAT_LOPC                                 */
/*   TEN_NX0G_SOHR_OHPSTAT_LOP                                  */
/*   TEN_NX0G_SOHR_OHPSTAT_S1USTS                               */
/*   TEN_NX0G_SOHR_OHPSTAT_K12USTS                              */
/*   TEN_NX0G_SOHR_OHPSTAT_LRDI                                 */
/*   TEN_NX0G_SOHR_OHPSTAT_LAIS                                 */
/*   TEN_NX0G_SOHR_OHPSTAT_DCCMUSTS                             */
/*   TEN_NX0G_SOHR_OHPSTAT_DCCRUSTS                             */
/*   TEN_NX0G_SOHR_OHPSTAT_J0CRC                                */
/*   TEN_NX0G_SOHR_OHPSTAT_RSTIM                                */
/*   TEN_NX0G_SOHR_OHPSTAT_J0USTS                               */
/*   TEN_NX0G_SOHR_OHPSTAT_ALL.                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N10G_SOHR_OHPSTAT_t tmp_n10g_sohr_ohpstat;

  TEN_N10G_VALIDATE(module_id, slice);
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  tmp_n10g_sohr_ohpstat.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHPSTAT));
  switch (field) {
  case TEN_NX0G_SOHR_OHPSTAT_AISC:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.AISC;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_AIS:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.AIS;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_LOPC:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.LOPC;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_LOP:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.LOP;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_S1USTS:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.S1USTS;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_K12USTS:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.K12USTS;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_LRDI:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.LRDI;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_LAIS:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.LAIS;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_DCCMUSTS:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.DCCMUSTS;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_DCCRUSTS:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.DCCRUSTS;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_J0CRC:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.J0CRC;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_RSTIM:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.RSTIM;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_J0USTS:
    {
      rtn = tmp_n10g_sohr_ohpstat.bf.J0USTS;
      break;
    }
  case TEN_NX0G_SOHR_OHPSTAT_ALL:
    {
      rtn = tmp_n10g_sohr_ohpstat.wrd;
      break;
    }
  default:
    {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..12, 0xFFFF.");
      rtn = CS_ERROR;
      break;
    } 
  }

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHR SET BYTE ERROR TRANSPARENCY MODE       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_sohr_set_byte_err_trans_mode(cs_uint16 module_id, cs_uint8 slice,  
                          cs_uint16 b1trans, 
                          cs_uint16 b2trans)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o B1TRANS                                           */
/*              o B2TRANS                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the B1/B2 byte error transparency mode.               */ 
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [b1trans]   Configures the B1 byte error transparency mode.    */
/*     The errors are inserted in the data path and can used in     */
/*     the transmit part.                                           */
/*     0 = Pass-through.                                            */
/*     1 = B1 error byte is inserted.                               */
/*                                                                  */
/*   [b2trans]  Configures the B2 byte error transparency mode.     */
/*     The errors are inserted in the data path and can used        */
/*     in the transmit part.                                        */
/*     0 = Pass-through.                                            */
/*     1 = B2 error bytes are inserted                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHR_S1CFG_t tmp_sohr_s1cfg;
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
      tmp_sohr_s1cfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, S1CFG));
      tmp_sohr_s1cfg.bf.B1TRANS = b1trans;
      tmp_sohr_s1cfg.bf.B2TRANS = b2trans;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, S1CFG), tmp_sohr_s1cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHR K12CFG                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_sohr_k12cfg(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 raflen, 
                           cs_uint16 aaflen, 
                           cs_uint16 kmlen, 
                           cs_uint16 kaflen)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o RAFLEN                                            */
/*              o AAFLEN                                            */
/*              o KMLEN                                             */
/*              o KAFLEN                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets aspects of K1/K2 Bytes Configuration.                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [raflen]                                                       */
/*   Configures the number of frames in which the received K2[2:0]  */
/*   bits have to be set to the binary value '110' to cause an      */
/*   RDI indication.                                                */
/*   Setting this bit field to zero will inhibit any events.        */
/*                                                                  */
/*   [aaflen]                                                       */
/*   Configures the number of frames in which the received K2[2:0]  */
/*   bits have to be set to the binary value '111' to indicate an   */
/*   AIS event.                                                     */
/*   Setting this bit field to zero will inhibit any events.        */
/*                                                                  */
/*   [kmlen]                                                        */
/*   Configures the number of received K1/K2(b1-b5)-bytes that      */
/*   must differ from the previously accepted ones in order to      */
/*   produce an unstable event.                                     */
/*   Setting this bit field to zero will inhibit any events.        */
/*                                                                  */
/*   [kaflen]                                                       */
/*   Configures the number of identical received K1/K2(b1-b5) bytes */
/*   needed to issue a change event.                                */
/*   Setting this bit field to zero will inhibit any events.        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHR_K12CFG_t tmp_sohr_k12cfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_sohr_k12cfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, K12CFG));
      tmp_sohr_k12cfg.bf.RAFLEN = raflen;
      tmp_sohr_k12cfg.bf.AAFLEN = aaflen;
      tmp_sohr_k12cfg.bf.KMLEN = kmlen;
      tmp_sohr_k12cfg.bf.KAFLEN = kaflen;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, K12CFG), tmp_sohr_k12cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHR K12CFG KMLEN                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_sohr_k12cfg_kmlen(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 kmlen) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o KMLEN                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets aspects of K1/K2 Bytes Configuration.                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [kmlen]                                                        */
/*   Configures the number of received K1/K2(b1-b5)-bytes that      */
/*   must differ from the previously accepted ones in order to      */
/*   produce an unstable event.                                     */
/*   Setting this bit field to zero will inhibit any events.        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHR_K12CFG_t tmp_sohr_k12cfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_sohr_k12cfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, K12CFG));
      tmp_sohr_k12cfg.bf.KMLEN = kmlen;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, K12CFG), tmp_sohr_k12cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SOHR SET KAFLEN                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_sohr_set_kaflen(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 kaflen)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o KAFLEN                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets aspects of K1/K2 Bytes Configuration                    */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)  */
/*                                                              */
/*   [kaflen]  Configures the number of identical received      */
/*     K1/K2(b1-b5)-bytes needed to issue a change event.       */
/*     Setting this bit field to zero will inhibit any events.  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHR_K12CFG_t tmp_sohr_k12cfg;
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
      tmp_sohr_k12cfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, K12CFG));
      tmp_sohr_k12cfg.bf.KAFLEN = kaflen;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, K12CFG), tmp_sohr_k12cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SOHR GET PIS0 STATUS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n10g_sohr_get_pis0(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint8 instance)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Instance                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register provides a Pointer Interpreter Status readout. */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), or TEN_SLICE3 (3)                        */
/*                                                              */
/*   [instance] is specified as 0 to 37.                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 rtn = CS_ERROR;

  TEN_N10G_VALIDATE(module_id, slice);
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  if ((instance >= TEN_N10G_SOHR_PIS0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..37.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  rtn = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, PIS0)+(instance*TEN_N10G_SOHR_PIS0_STRIDE));

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SOHR SET J0CFG REGISTER                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_sohr_j0cfg(cs_uint16 module_id,
                                  cs_uint8 slice, 
                                  cs_uint16 select, 
                                  cs_uint16 value)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Select                                        */
/*              o Value                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* J0 Byte Main Configuration Register                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_N10G_J_BYTE_CFG_MMONCRC7ERR     = 0x0001               */
/*   TEN_N10G_J_BYTE_CFG_MMONUNSTABLE    = 0x0002               */
/*   TEN_N10G_J_BYTE_CFG_DISUPPR         = 0x0003               */
/*   TEN_N10G_J_BYTE_CFG_DISUPST         = 0x0004               */
/*   TEN_N10G_J_BYTE_CFG_MANU            = 0x0005               */
/*   TEN_N10G_J_BYTE_CFG_LEN             = 0x0006               */
/*   TEN_N10G_J_BYTE_CFG_SONET           = 0x0007               */
/*   TEN_N10G_J_BYTE_CFG_AUTO            = 0x0008               */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   For select = TEN_N10G_J_BYTE_CFG_MMONCRC7ERR               */
/*     Configures the setting of the RSTIM when the CRC-7 is    */
/*     wrong.                                                   */
/*     0 = RSTIM alarm and J0CRC7 alarm are two independent     */
/*         processes.                                           */
/*     1 = An active J0CRC7 alarm masks the RSTIM alarm.        */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_MMONUNSTABLE              */
/*     Configures the setting of RSTIM when the trace is        */
/*     unstable.                                                */
/*     0 = RSTIM alarm and J0USTS alarm are two independent     */
/*         processes. For RSTIM received trace is compared with */
/*         expected.                                            */
/*     1 = RSTIM alarm and J0USTS alarm are not independent     */
/*         processes. The RSTIM alarm changes status only when  */
/*         a trace is being accepted and differs from the       */
/*         expected or if J0USTS alarm is high (J0 trace        */
/*         unstable). RSTIM is cleared when the accepted trace  */
/*         matches the expected trace. If a write occurs on the */
/*         expected RAM; RSTIM is the result of the received    */
/*         versus the expected trace until a new accepted trace */
/*         is declared.                                         */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_DISUPPR                   */
/*     If automatic mode is selected, this bit controls the     */
/*     automatic updating of buffer SOFR_J0_RAM with the        */
/*     previously accepted section trace.                       */
/*     0 = Automatic updating by hardware enabled               */
/*     1 = Automatic updating by hardware disabled              */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_DISUPST                   */
/*     This bit controls the automatic updating of buffer       */
/*     J0EXTR with a new stable section trace.                  */
/*     0 = Automatic updating by hardware enabled               */
/*     1 = Automatic updating by hardware disabled              */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_MANU                      */
/*     This bit controls the mode in which the provisioned J0   */
/*     string is written to buffer SOFR_J0_RAM.                 */
/*     0 = Automatic mode: The J0 string previously received    */
/*         and accepted as stable is stored in register J0REQU  */
/*         automatically.                                       */
/*     1 = Manual mode: The reference section trace has to be   */
/*         provided by the processor interface. Note that       */
/*         buffer J0REQU is accessible via the processor        */
/*         interface only when bit J0MANU has been set.         */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_LEN                       */
/*     J0LEN[1:0] This register defines the section trace string*/
/*     length to be processed.                                  */
/*     0 = Trace identifier: 1 byte string length               */
/*     1 = Trace identifier: 16 bytes string length             */
/*     2 = Trace identifier: 64 bytes string length             */
/*     3 = Trace identifier: 1 byte string length               */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_SONET                     */
/*     This bit configures the expected SONET/SDH frame format. */
/*     0 = Received section trace string is processed according */
/*         to SDH rules meaning that frame start is indicated by*/
/*         logic one detected in the MSB bit of the received J0 */
/*         byte.                                                */
/*     1 = Received section trace string is processed according */
/*         to SONET rules meaning that the first byte of the    */
/*         string fo7llows the last received 0x0D/0x0A byte     */
/*         sequence.                                            */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_AUTO                      */
/*     This bit enables the automatic section trace string (J0  */
/*     byte) framing, depending on the selected SONET or SDH    */
/*     frame format.                                            */
/*     0 = Disables automatic section trace string framing.First*/
/*         byte of received string will be read by processor    */
/*         interface at any address of J0EXTR register array.   */
/*     1 = Enables automatic section trace string framing. First*/
/*         byte of received string can be read by processor     */
/*         interface at first address of J0EXTR register array. */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHR_J0CFG_t tmp_sohr_j0cfg;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    rtn = CS_ERROR;
    goto RTN_EXIT;
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_sohr_j0cfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, J0CFG));
      switch (select) {
        case TEN_N10G_J_BYTE_CFG_MMONCRC7ERR :
          {
            tmp_sohr_j0cfg.bf.J0mmOnCRC7Err = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_MMONUNSTABLE :
          {
            tmp_sohr_j0cfg.bf.J0mmOnUnstable = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_DISUPPR :
          {
            tmp_sohr_j0cfg.bf.DISUPPR = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_DISUPST :
          {
            tmp_sohr_j0cfg.bf.DISUPST = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_MANU :
          {
            tmp_sohr_j0cfg.bf.J0MANU = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_LEN :
          {
            tmp_sohr_j0cfg.bf.J0LEN = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_SONET :
          {
            tmp_sohr_j0cfg.bf.J0SONET = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_AUTO :
          {
            tmp_sohr_j0cfg.bf.J0AUTO = value;
            break;
          }
        default : 
          {
            CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, ": select out of range"); 
            rtn = CS_ERROR; 
            goto RTN_EXIT;
          }
      }
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, J0CFG), tmp_sohr_j0cfg.wrd);
    }
  }
RTN_EXIT:
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N10G GET SOHR J0EXTR                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_get_sohr_j0extr(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_char8 *str)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o String                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* J0EXTR0[15:0] This register array contains the stable section    */
/* trace string that has been received over the number of           */
/* consecutive multiframes specified in SOHR:J0INHY. The section    */
/* trace string is read in 'LSB first', that is, bits [7:0] of      */
/* J0EXTR(0) contain the LSB or, in SDH terms, the CRC-7 byte.      */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [*str] parameter is specified as:                            */
/*   A pointer to a 512-bit string                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_char8 *tmp_str = str;
  TEN_N10G_SOHR_J0EXTR0_t tmp_sohr_j0extr0;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  for (ii=0; ii < TEN_N10G_SOHR_J0EXTR0_COUNT; ii++) {
    tmp_sohr_j0extr0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, J0EXTR0) +
                                        (ii *TEN_N10G_SOHR_J0EXTR0_STRIDE));
    *tmp_str = (cs_char8)(tmp_sohr_j0extr0.wrd & 0x00FF);
    tmp_str++;
    *tmp_str = (cs_char8)((tmp_sohr_j0extr0.wrd & 0xFF00) >> 8);
    tmp_str++;
  }

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G PRINT SOHR J0EXTR                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_print_sohr_j0extr(cs_uint16 module_id,
                                     cs_uint8 slice)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Prints the J0EXTR string.                                        */
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
  cs_char8 tmp_j0_extr_str[64];
  
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  rtn = ten_n10g_get_sohr_j0extr(module_id,
                                 slice,
                                 tmp_j0_extr_str);
  /* Bugzilla #23881, add CS_OK check before printing */
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_j0_extr_str, 64);
  }
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SET SOHR J0HYS                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_set_sohr_j0hys(cs_uint16 module_id,
                                  cs_uint8  slice, 
                                  cs_uint8  select, 
                                  cs_uint8  hysteresis)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/*              o Hysteresis                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* J0 Byte Acceptance Filter Configuration Register.                */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [select] parameter is specified as:                          */
/*   0 = Out                                                        */
/*   1 = In                                                         */
/*                                                                  */
/* The [hysteresis] parameter is specified as:                      */
/*   0..0xF,  This bit field configures the minimum number of       */
/*   different received section traces needed to leave              */
/*   (select = Out) or identical received section traces needed to  */
/*   enter (select = In) stable state.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHR_J0HYS_t tmp_sohr_j0hys;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (select > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..1.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_sohr_j0hys.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, J0HYS));
      if (select == 0) {
        tmp_sohr_j0hys.bf.J0OUTHY = hysteresis;
      }
      else {
        tmp_sohr_j0hys.bf.J0INHY = hysteresis;
      }
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, J0HYS), tmp_sohr_j0hys.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHR DCCCFG M01MODE                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_sohr_dcccfg_m01mode(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 m01mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o M01MODE                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets DCC Bytes Configuration M01MODE.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [m01mode]                                                      */
/*     Configures the mode of error statistics monitoring based     */
/*     on M0/M1 bytes.                                              */
/*     0 = Only M1 byte selected for monitoring                     */
/*     1 = Both M0 and M1 bytes selected for monitoring.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHR_DCCCFG_t tmp_sohr_dcccfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_sohr_dcccfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DCCCFG));
      tmp_sohr_dcccfg.bf.M01MODE = m01mode;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DCCCFG), tmp_sohr_dcccfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

