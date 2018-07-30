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
 * ten_n10g_pohr.c
 *
 * N10G related code is implemented here.
 *
 * $Id: ten_n10g_pohr.c,v 1.5 2013/02/22 20:47:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N10G GET THE ACCEPTED POH BYTE               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n10g_get_accepted_poh_byte(cs_uint16 module_id,
                                        cs_uint8 slice,
                                        cs_uint16 ovrhd)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Overhead Byte Type                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Accepted Byte                                   */
/* DESCRIPTION:                                                 */
/* Gets the specified accepted SONET Overhead byte.             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [ovrhd] parameter is specified as following:             */
/*   TEN_GET_POH_C2                                             */
/*   TEN_GET_POH_F2                                             */
/*   TEN_GET_POH_G1                                             */
/*   TEN_GET_POH_F3                                             */
/*   TEN_GET_POH_H4                                             */
/*   TEN_GET_POH_N1                                             */
/*   TEN_GET_POH_K3.                                            */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = 0;
  
  TEN_N10G_VALIDATE(module_id, slice);
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(0);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);

  switch (ovrhd) {
  case TEN_GET_POH_C2:
    {
      TEN_N10G_POHR_C2F2ACPTD_t tmp_n10g_pohr_c2f2acptd;
      tmp_n10g_pohr_c2f2acptd.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, C2F2ACPTD));
      rtn = (cs_int16)(tmp_n10g_pohr_c2f2acptd.bf.C2_ACPTD & 0xFF);
      break;
    }
    
  case TEN_GET_POH_F2:
    {
      TEN_N10G_POHR_C2F2ACPTD_t tmp_n10g_pohr_c2f2acptd;
      tmp_n10g_pohr_c2f2acptd.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, C2F2ACPTD));
      rtn = (cs_int16)(tmp_n10g_pohr_c2f2acptd.bf.F2_ACPTD & 0xFF);
      break;
   }
   
  case TEN_GET_POH_H4:
    {
      TEN_N10G_POHR_H4F3ACPTD_t tmp_n10g_pohr_h4f3acptd;
      tmp_n10g_pohr_h4f3acptd.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, H4F3ACPTD));
      rtn = (cs_int16)(tmp_n10g_pohr_h4f3acptd.bf.H4_ACPTD & 0xFF);
      break;
    }
    
  case TEN_GET_POH_F3:
    {
      TEN_N10G_POHR_H4F3ACPTD_t tmp_n10g_pohr_h4f3acptd;
      tmp_n10g_pohr_h4f3acptd.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, H4F3ACPTD));
      rtn = (cs_int16)(tmp_n10g_pohr_h4f3acptd.bf.F3_ACPTD & 0xFF);
      break;
    }
    
  case TEN_GET_POH_K3:
    {
      TEN_N10G_POHR_K3N1ACPTD_t tmp_n10g_pohr_k3n1acptd;
      tmp_n10g_pohr_k3n1acptd.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, K3N1ACPTD));
      rtn = (cs_int16)(tmp_n10g_pohr_k3n1acptd.bf.K3_ACPTD & 0xFF);
      break;
    }
    
  case TEN_GET_POH_N1:
    {
      TEN_N10G_POHR_K3N1ACPTD_t tmp_n10g_pohr_k3n1acptd;
      tmp_n10g_pohr_k3n1acptd.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, K3N1ACPTD));
      rtn = (cs_int16)(tmp_n10g_pohr_k3n1acptd.bf.N1_ACPTD & 0xFF);
      break;
    }
    
  case TEN_GET_POH_G1:
    {
      TEN_N10G_POHR_G1ACPTD_t tmp_n10g_pohr_g1acptd;
      tmp_n10g_pohr_g1acptd.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, G1ACPTD));
      rtn = (cs_int16)(tmp_n10g_pohr_g1acptd.bf.G1_ACPTD & 0xFF);
      break;
    }
    
  default:
    {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..6.");
      rtn = 0;
      break;
    } 
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N10G GET POH STATUS                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n10g_get_poh_status(cs_uint16 module_id,
                                 cs_uint8 slice, 
                                 cs_uint16 field)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Field                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : The requested field from the POHR Ohpstat0      */
/*              Register.                                       */
/* DESCRIPTION:                                                 */
/* Returns the requested field from the POHR Ohpstat0 Register. */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [field] parameter is specified as:                       */
/*   TEN_NX0G_POHR_OHPSTAT0_G1USTS                              */
/*   TEN_NX0G_POHR_OHPSTAT0_RDIPS                               */
/*   TEN_NX0G_POHR_OHPSTAT0_VCAIS                               */
/*   TEN_NX0G_POHR_OHPSTAT0_UNEQPS                              */
/*   TEN_NX0G_POHR_OHPSTAT0_PLMS                                */
/*   TEN_NX0G_POHR_OHPSTAT0_C2USTS                              */
/*   TEN_NX0G_POHR_OHPSTAT0_SD                                  */
/*   TEN_NX0G_POHR_OHPSTAT0_SF                                  */
/*   TEN_NX0G_POHR_OHPSTAT0_J1CRC                               */
/*   TEN_NX0G_POHR_OHPSTAT0_J1ALLZERO                           */
/*   TEN_NX0G_POHR_OHPSTAT0_PTIM                                */
/*   TEN_NX0G_POHR_OHPSTAT0_J1USTS                              */
/*   TEN_NX0G_POHR_OHPSTAT0_ALL                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N10G_POHR_OHPSTAT0_t tmp_n10g_pohr_ohpstat0;

  TEN_N10G_VALIDATE(module_id, slice);
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  tmp_n10g_pohr_ohpstat0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHPSTAT0));
  switch (field) {
  case TEN_NX0G_POHR_OHPSTAT0_G1USTS :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.G1USTS;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_RDIPS :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.RDIPS;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_VCAIS :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.VCAIS;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_UNEQPS :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.UNEQPS;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_PLMS :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.PLMS;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_C2USTS :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.C2USTS;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_SD :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.SD;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_SF :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.SF;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_J1CRC :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.J1CRC;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_J1ALLZERO :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.J1ALLZERO;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_PTIM :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.PTIM;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_J1USTS :
    {
      rtn = tmp_n10g_pohr_ohpstat0.bf.J1USTS;
      break;
    }
  case TEN_NX0G_POHR_OHPSTAT0_ALL :
    {
      rtn = tmp_n10g_pohr_ohpstat0.wrd;
      break;
    }
  default:
    {
      rtn = CS_ERROR;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..11, 0xFFFF.");
    break;
    }
  }
  return (rtn);
  
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET B3 BIT ERROR THRESHOLD REGISTER     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_pohr_b3btber(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_uint16 b3btber)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o B3BTBER                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This bit field sets the threshold for B3-byte bit errors to  */
/* be compared with the bit-level parity error count in         */
/* POHR:B3BTER and produce an interrupt in POHR:B3BTEX if the   */
/* threshold is exceeded.                                       */
/* Note: For non-operational purposes it may be indicated to    */
/* set the B3BTBER threshold to its maximum value of 0xFFFF in  */
/* which case the POHR:B3BTEX interrupt will occur only if the  */
/* counter overflows (causing it to stop at its maximum value). */
/* Conversely, by letting the POHR:B3BTBER threshold default to */
/* '0' the interrupt is set upon the first parity error.        */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [b3btber] parameter is specified as:                     */
/* 0x0000-0xFFFF                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_POHR_B3BTBER_t tmp_pohr_b3btber;
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
      tmp_pohr_b3btber.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, B3BTBER));
      tmp_pohr_b3btber.bf.B3BTBER = b3btber;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, B3BTBER), tmp_pohr_b3btber.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET B3 BLOCK LEVEL ERROR ERROR THRESHOLD*/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_pohr_b3blber(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_uint16 b3blber)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o B3BLBER                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This bit field sets the threshold for B3-byte block-level    */
/* errors to be compared with the parity error count in         */
/* POHR:B3BLER and produce an interrupt in POHR:B3BLEX if the   */
/* threshold is exceeded.                                       */
/* Note: For non-operational purposes it may be indicated to    */
/* set the POHR:B3BLBER threshold to its maximum value of       */
/* 0x1FFF in which case the POHR:B3BLEX interrupt will occur    */
/* only if the counter overflows (causing it to stop at its     */
/* maximum value). Conversely, by letting the POHR:B3BLBER      */
/* threshold default to '0' the interrupt is set upon the first */
/* parity error.                                                */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [b3blber] parameter is specified as:                     */
/*   0x0000 - 0x1FFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_POHR_B3BLBER_t tmp_pohr_b3blber;
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
      tmp_pohr_b3blber.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, B3BLBER));
      tmp_pohr_b3blber.bf.B3BLBER = b3blber;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, B3BLBER), tmp_pohr_b3blber.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G POHR SET J1CFG REGISTER                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_pohr_j1cfg(cs_uint16 module_id,
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
/* J1 Byte Main Configuration Register                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_N10G_J_BYTE_CFG_MMONALLZERO     = 0x0000               */
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
/*   For select = TEN_N10G_J_BYTE_CFG_MMONALLZERO               */
/*     Configures the setting of the PTIM when an all-zero      */
/*     state is declared:                                       */
/*     0 = J1AllZero alarm active does not mask the PTIM alarm  */
/*     1 = J1AllZero alarm active masks the PTIM alarm.         */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_MMONCRC7ERR               */
/*     Configures the setting of the PTIM when the CRC-7 is     */
/*     wrong.                                                   */
/*     0 = PTIM alarm and J1CRC7 alarm are two independent      */
/*         processes.                                           */
/*     1 = An active J1CRC7 alarm masks the PTIM alarm.         */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_MMONUNSTABLE              */
/*     Configures the setting of PTIM when the trace is         */
/*     unstable.                                                */
/*     0 = PTIM alarm and J1USTS alarm are two independent      */
/*         processes. For PTIM received trace is compared with  */
/*         expected.                                            */
/*     1 = PTIM alarm and J1USTS alarm are not independent      */
/*         processes. The PTIM alarm changes status only when a */
/*         trace is being accepted and differs from the         */
/*         expected or if J1USTS alarm is high (J1 trace        */
/*         unstable). PTIM is cleared when the accepted trace   */
/*         matches the expected trace. If a write occurs on the */
/*         expected RAM; PTIM is the result of the received     */
/*         versus the expected trace until a new accepted trace */
/*         is declared.                                         */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_DISUPPR                   */
/*     If automatic mode is selected, this bit controls the     */
/*     automatic updating of buffer J1REQU with the previously  */
/*     accepted path trace.                                     */
/*     0 = Automatic updating by hardware enabled               */
/*     1 = Automatic updating by hardware disabled              */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_DISUPST                   */
/*     This bit controls the automatic updating of buffer       */
/*     J1EXTR with a new stable path trace.                     */
/*     0 = Automatic updating by hardware enabled               */
/*     1 = Automatic updating by hardware disabled              */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_MANU                      */
/*     This bit controls the mode in which the provisioned J1   */
/*     string is written to buffer J1REQU.                      */
/*     0 = Automatic mode: The J1 string previously received    */
/*         and accepted as stable is stored in register J1REQU  */
/*         automatically.                                       */
/*     1 = Manual mode: The reference path trace has to be      */
/*         provided by the processor interface. Note that       */
/*         buffer J1REQU is accessible via the processor        */
/*         interface only when bit J1MANU has been set.         */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_LEN                       */
/*     J1LEN[1:0] This register defines the path trace string   */
/*     length to be processed.                                  */
/*     0 = Trace identifier: 1 byte string length               */
/*     1 = Trace identifier: 16 bytes string length             */
/*     2 = Trace identifier: 64 bytes string length             */
/*     3 = Trace identifier: 1 byte string length               */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_SONET                     */
/*     This bit configures the expected SONET/SDH frame format. */
/*     0 = Received path trace string is processed according to */
/*         SDH rules meaning that frame start is indicated by a */
/*         logic one detected in the MSB bit of the received J1 */
/*         byte.                                                */
/*     1 = Received path trace string is processed according to */
/*         SONET rules meaning that the first byte of the       */
/*         string fo7llows the last received 0x0D/0x0A byte     */
/*         sequence.                                            */
/*                                                              */
/*   For select = TEN_N10G_J_BYTE_CFG_AUTO                      */
/*     This bit enables the automatic path trace string (J1     */
/*     byte) framing, depending on the selected SONET or SDH    */
/*     frame format.                                            */
/*     0 = Disables automatic path trace string framing. First  */
/*         byte of received string will be read by processor    */
/*         interface at any address of J1EXTR register array.   */
/*     1 = Enables automatic path trace string framing. First   */
/*         byte of received string can be read by processor     */
/*         interface at first address of J1EXTR register array. */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_POHR_J1CFG_t tmp_pohr_j1cfg;
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
      tmp_pohr_j1cfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, J1CFG));
      switch (select) {
        case TEN_N10G_J_BYTE_CFG_MMONALLZERO :
          {
            tmp_pohr_j1cfg.bf.J1mmOnAllZero = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_MMONCRC7ERR :
          {
            tmp_pohr_j1cfg.bf.J1mmOnCRC7Err = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_MMONUNSTABLE :
          {
            tmp_pohr_j1cfg.bf.J1mmOnUnstable = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_DISUPPR :
          {
            tmp_pohr_j1cfg.bf.DISUPPR = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_DISUPST :
          {
            tmp_pohr_j1cfg.bf.DISUPST = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_MANU :
          {
            tmp_pohr_j1cfg.bf.J1MANU = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_LEN :
          {
            tmp_pohr_j1cfg.bf.J1LEN = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_SONET :
          {
            tmp_pohr_j1cfg.bf.J1SONET = value;
            break;
          }
        case TEN_N10G_J_BYTE_CFG_AUTO :
          {
            tmp_pohr_j1cfg.bf.J1AUTO = value;
            break;
          }
        default : 
          {
            CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, ": select out of range"); 
            rtn = CS_ERROR; 
            goto RTN_EXIT;
          }
      }
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, J1CFG), tmp_pohr_j1cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

RTN_EXIT:
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N10G GET POHR J1EXTR                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_get_pohr_j1extr(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_char8 *str)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o String                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* J1EXTR0[15:0] This register array contains the stable path trace */
/* string that has been received over the number of consecutive     */
/* multiframes specified in POHR:J1INHY. The path trace string      */
/* is read in 'LSB first', that is, bits [7:0] of J1EXTR(0) contain */
/* the LSB or, in SDH terms, the CRC-7 byte.                        */
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
  TEN_N10G_POHR_J1EXTR0_t tmp_pohr_j1extr0;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  for (ii=0; ii < TEN_N10G_POHR_J1EXTR0_COUNT; ii++) {
    tmp_pohr_j1extr0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, J1EXTR0) +
                                        (ii *TEN_N10G_POHR_J1EXTR0_STRIDE));
    *tmp_str = (cs_char8)(tmp_pohr_j1extr0.bf.J1EXTR0 & 0x00FF);
    tmp_str++;
    *tmp_str = (cs_char8)((tmp_pohr_j1extr0.bf.J1EXTR0 & 0xFF00) >> 8);
    tmp_str++;
  }

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G PRINT POHR J1EXTR                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_print_pohr_j1extr(cs_uint16 module_id,
                                     cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints the J1EXTR string.                                    */
/* This API is mainly for debugging purposes.                   */
/*                                                              */
/* [slice]                                                      */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3.                                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_char8 tmp_j1extr[64];

  rtn = ten_n10g_get_pohr_j1extr(module_id, slice, tmp_j1extr);
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_j1extr, 64);
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SET POHR J1HYS                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_set_pohr_j1hys(cs_uint16 module_id,
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
/* J1 Byte Acceptance Filter Configuration Register.                */
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
/*   different received path traces needed to leave                 */
/*   (select = Out) or identical received path traces needed to     */
/*   enter (select = In) stable state.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_POHR_J1HYS_t tmp_pohr_j1hys;
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
      tmp_pohr_j1hys.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, J1HYS));
      if (select == 0) {
        tmp_pohr_j1hys.bf.J1OUTHY = hysteresis;
      }
      else {
        tmp_pohr_j1hys.bf.J1INHY = hysteresis;
      }
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, J1HYS), tmp_pohr_j1hys.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SET POHR G1 CONFIGURATION                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_set_pohr_g1_config(cs_uint16 module_id,
                                      cs_uint8  slice, 
                                      cs_uint16 select, 
                                      cs_uint16 value)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* G1 configuration (Registers 1 and 2).                            */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [select] parameter is specified as:                          */
/*   TEN_N10G_G1_CONFIG_RDIPEN         = 0x0000                     */
/*   TEN_N10G_G1_CONFIG_G1MLEN         = 0x0001                     */
/*   TEN_N10G_G1_CONFIG_G1AFLEN        = 0x0002                     */
/*   TEN_N10G_G1_CONFIG_PLMP2PRDIEN    = 0x0003                     */
/*   TEN_N10G_G1_CONFIG_LCD2PRDIEN     = 0x0004                     */
/*   TEN_N10G_G1_CONFIG_AIS2PRDIEN     = 0x0005                     */
/*   TEN_N10G_G1_CONFIG_AISC2PRDIEN    = 0x0006                     */
/*   TEN_N10G_G1_CONFIG_LOP2PRDIEN     = 0x0007                     */
/*   TEN_N10G_G1_CONFIG_LOPC2PRDIEN    = 0x0008                     */
/*   TEN_N10G_G1_CONFIG_UNEQ2PRDIEN    = 0x0009                     */
/*   TEN_N10G_G1_CONFIG_TIM2PRDIEN     = 0x000A                     */
/*                                                                  */
/* The [value] parameter is specified as:                           */
/*   For select = TEN_N10G_G1_CONFIG_RDIPEN                         */
/*     0 = Process G1 for RDI-P                                     */
/*     1 = Process G1 for E-RDI-P                                   */
/*                                                                  */
/*   For select = TEN_N10G_G1_CONFIG_G1MLEN                         */
/*     G1MLEN[3:0] This bit field configures the number of          */
/*     consecutive received G1-bytes that must differ from the      */
/*     previously accepted one in order to produce the G1 unstable. */
/*                                                                  */
/*   For select = TEN_N10G_G1_CONFIG_G1AFLEN                        */
/*     G1AFLEN[3:0] This bit field configures the number of         */
/*     consecutive identical received G1 bytes that will be         */
/*     accepted as a new G1 byte.                                   */
/*                                                                  */
/*   For select = TEN_N10G_G1_CONFIG_PLMP2PRDIEN                    */
/*     Plmp2pRdiEn[1:0] Enable and configures the reflection of     */
/*     RDI-P during PLM-P.                                          */
/*     00 = RDI-P not generate                                      */
/*     01 = RDI-P generated as a connectivity defect                */
/*     10 = RDI-P generated as a payload defect                     */
/*     11 = Reserved                                                */
/*                                                                  */
/*   For select = TEN_N10G_G1_CONFIG_LCD2PRDIEN                     */
/*     Enables generation of reflected RDI-P during LCD alarm       */
/*     active in RX 10GbE PCS.                                      */
/*     0 = Do not generate RDI-P                                    */
/*     1 = RDI-P generated as a payload defect                      */
/*                                                                  */
/*   For select = TEN_N10G_G1_CONFIG_AIS2PRDIEN                     */
/*     Enables generation of reflected RDI-P during AIS-P.          */
/*     0 = Do not generate RDI-P                                    */
/*     1 = RDI-P generated as a server defect                       */
/*                                                                  */
/*   For select = TEN_N10G_G1_CONFIG_AISC2PRDIEN                    */
/*     Enables generation of reflected RDI-P during concatenated    */
/*     AIS-P.                                                       */
/*     0 = Do not generate RDI-P                                    */
/*     1 = RDI-P generated as a server defect                       */
/*                                                                  */
/*   For select = TEN_N10G_G1_CONFIG_LOP2PRDIEN                     */
/*     Enables generation of reflected RDI-P during LOP.            */
/*     0 = Do not generate RDI-P                                    */
/*     1 = RDI-P generated as a server defect                       */
/*                                                                  */
/*   For select = TEN_N10G_G1_CONFIG_LOPC2PRDIEN                    */
/*     Enables generation of reflected RDI-P during concatenated    */
/*     LOP.                                                         */
/*     0 = Do not generate RDI-P                                    */
/*     1 = RDI-P generated as a server defect                       */
/*                                                                  */
/*   For select = TEN_N10G_G1_CONFIG_UNEQ2PRDIEN                    */
/*     Enables generation of reflected RDI-P during UNEQ.           */
/*     0 = Do not generate RDI-P                                    */
/*     1 = RDI-P generated as a connectivity defect                 */
/*                                                                  */
/*   For select = TEN_N10G_G1_CONFIG_TIM2PRDIEN                     */
/*     Enables generation of reflected RDI-P during TIM-P.          */
/*     0 = Do not generate RDI-P                                    */
/*     1 = RDI-P generated as a connectivity defect                 */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    ret_val = CS_ERROR; 
    goto RTN_EXIT;
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      switch (select) {
        case TEN_N10G_G1_CONFIG_RDIPEN :
          {
            TEN_N10G_POHR_G1CFG1_t tmp_pohr_g1cfg1;
            tmp_pohr_g1cfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG1));
            tmp_pohr_g1cfg1.bf.RDIPEN = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG1), tmp_pohr_g1cfg1.wrd);
            break;
          }
        case TEN_N10G_G1_CONFIG_G1MLEN :
          {
            TEN_N10G_POHR_G1CFG1_t tmp_pohr_g1cfg1;
            tmp_pohr_g1cfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG1));
            tmp_pohr_g1cfg1.bf.G1MLEN = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG1), tmp_pohr_g1cfg1.wrd);
            break;
          }
        case TEN_N10G_G1_CONFIG_G1AFLEN :
          {
            TEN_N10G_POHR_G1CFG1_t tmp_pohr_g1cfg1;
            tmp_pohr_g1cfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG1));
            tmp_pohr_g1cfg1.bf.G1AFLEN = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG1), tmp_pohr_g1cfg1.wrd);
            break;
          }
        case TEN_N10G_G1_CONFIG_PLMP2PRDIEN :
          {
            TEN_N10G_POHR_G1CFG2_t tmp_pohr_g1cfg2;
            tmp_pohr_g1cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2));
            tmp_pohr_g1cfg2.bf.Plmp2pRdiEn = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2), tmp_pohr_g1cfg2.wrd);
            break;
          }
        case TEN_N10G_G1_CONFIG_LCD2PRDIEN :
          {
            TEN_N10G_POHR_G1CFG2_t tmp_pohr_g1cfg2;
            tmp_pohr_g1cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2));
            tmp_pohr_g1cfg2.bf.Lcd2pRdiEn = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2), tmp_pohr_g1cfg2.wrd);
            break;
          }
        case TEN_N10G_G1_CONFIG_AIS2PRDIEN :
          {
            TEN_N10G_POHR_G1CFG2_t tmp_pohr_g1cfg2;
            tmp_pohr_g1cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2));
            tmp_pohr_g1cfg2.bf.Ais2pRdiEn = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2), tmp_pohr_g1cfg2.wrd);
            break;
          }
        case TEN_N10G_G1_CONFIG_AISC2PRDIEN :
          {
            TEN_N10G_POHR_G1CFG2_t tmp_pohr_g1cfg2;
            tmp_pohr_g1cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2));
            tmp_pohr_g1cfg2.bf.Aisc2pRdiEn = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2), tmp_pohr_g1cfg2.wrd);
            break;
          }
        case TEN_N10G_G1_CONFIG_LOP2PRDIEN :
          {
            TEN_N10G_POHR_G1CFG2_t tmp_pohr_g1cfg2;
            tmp_pohr_g1cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2));
            tmp_pohr_g1cfg2.bf.Lop2pRdiEn = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2), tmp_pohr_g1cfg2.wrd);
            break;
          }
        case TEN_N10G_G1_CONFIG_LOPC2PRDIEN :
          {
            TEN_N10G_POHR_G1CFG2_t tmp_pohr_g1cfg2;
            tmp_pohr_g1cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2));
            tmp_pohr_g1cfg2.bf.Lopc2pRdiEn = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2), tmp_pohr_g1cfg2.wrd);
            break;
          }
        case TEN_N10G_G1_CONFIG_UNEQ2PRDIEN :
          {
            TEN_N10G_POHR_G1CFG2_t tmp_pohr_g1cfg2;
            tmp_pohr_g1cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2));
            tmp_pohr_g1cfg2.bf.Uneq2pRdiEn = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2), tmp_pohr_g1cfg2.wrd);
            break;
          }
        case TEN_N10G_G1_CONFIG_TIM2PRDIEN :
          {
            TEN_N10G_POHR_G1CFG2_t tmp_pohr_g1cfg2;
            tmp_pohr_g1cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2));
            tmp_pohr_g1cfg2.bf.Tim2pRdiEn = value;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, G1CFG2), tmp_pohr_g1cfg2.wrd);
            break;
          }
        default : 
          {
            CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, ": select out of range"); 
            ret_val = CS_ERROR; 
            goto RTN_EXIT;
          }
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

RTN_EXIT:
  return (ret_val);
}


