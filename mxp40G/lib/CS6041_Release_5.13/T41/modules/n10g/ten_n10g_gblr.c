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
 * ten_n10g_gblr.c
 *
 * N10G related code is implemented here.
 *
 * $Id: ten_n10g_gblr.c,v 1.8 2013/03/05 21:37:20 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N10G GET GLOBAL LOS STATUS                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_boolean ten_n10g_get_global_losf_status(cs_uint16 module_id,
                                           cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE (LOS occurred) or FALSE (No LOS occurred)  */
/* DESCRIPTION:                                                 */
/* This bit is set to logic one when Loss of Signal defect      */
/* occurs.                                                      */
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
  TEN_N10G_GBLR_GBLRStatus_t tmp_gblr_gblrstatus;
  T41_t                      *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  tmp_gblr_gblrstatus.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GBLRStatus));

  return (tmp_gblr_gblrstatus.bf.LOSF == 1) ;
}

/****************************************************************/
/* $rtn_hdr_start  N10G GET GLOBAL PSTAT STATUS                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n10g_get_global_pstat_status(cs_uint16 module_id,
                                          cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Bitmapped Status:                               */
/*                PSTAT1                                        */
/*                PSTAT0                                        */
/* DESCRIPTION:                                                 */
/* Pseudo Random Bit Sequence (PRBS) Status PSTAT[1:0]          */
/* 0x00 = No PRBS found.                                        */
/* 0x01 = PN-11                                                 */
/* 0x02 = PN-23                                                 */
/* 0x03 = PN-31                                                 */
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
  TEN_N10G_GBLR_GBLRStatus_t tmp_gblr_gblrstatus;
  T41_t                      *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  tmp_gblr_gblrstatus.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GBLRStatus));

  return (tmp_gblr_gblrstatus.bf.PSTAT) ;
}

/****************************************************************/
/* $rtn_hdr_start  N10G GET GLOBAL PF STATUS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_boolean ten_n10g_get_global_pf_status(cs_uint16 module_id,
                                         cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE (Pattern accepted) or FALSE (Not accepted) */
/* DESCRIPTION:                                                 */
/* Fixed Pattern Found. Set when the acceptance filter defined  */
/* by PAFSET has accepted the pattern specified by PATa, PATb,  */
/* MASK and FMM.                                                */
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
  TEN_N10G_GBLR_GBLRStatus_t tmp_gblr_gblrstatus;
  T41_t                      *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  tmp_gblr_gblrstatus.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GBLRStatus));

  return (tmp_gblr_gblrstatus.bf.PF == 1) ;
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET DATA PATH CONFIGURATION REGISTER    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_gblr_dpcfg(cs_uint16 module_id,
                                  cs_uint8 slice, 
                                  cs_uint16 xsel, 
                                  cs_uint16 kpasel, 
                                  cs_uint16 sbypld, 
                                  cs_uint16 sbyfrm, 
                                  cs_uint16 oby, 
                                  cs_uint16 sdhoff, 
                                  cs_uint16 otnoff)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o XSEL                                          */
/*              o KPASEL                                        */
/*              o SBYPLD                                        */
/*              o SBYFRM                                        */
/*              o OBY                                           */
/*              o SDHOFF                                        */
/*              o OTNOFF                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Data Path Configuration Register.   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [xsel] parameter is specified as:                        */
/*   Output to the cross connect select.                        */
/*   0b00 = bypass data coming from N40G                        */
/*   0b01 = Aligned OXU2                                        */
/*   0b10 and 0b11 = Unaligned data (Either SONET or OTN        */
/*                   extracted payload)                         */
/*                                                              */
/* The [kpasel] parameter is specified as:                      */
/*   Selects input for Know Pattern Analyzer.                   */
/*   0b00 = SDH payload                                         */
/*   0b01 = OxU2 payload                                        */
/*   0b10 = Client Input                                        */
/*                                                              */
/* The [sbypld] parameter is specified as:                      */
/*   0                                                          */
/*   1 = SDH Payload Bypass Enable. Should be set when the      */
/*       output from the SDH Terminator is not needed.          */
/*                                                              */
/* The [sbyfrm] parameter is specified as:                      */
/*   0                                                          */
/*   1 = SDH Frame Bypass Enable. Should be set when the output */
/*       from the SDH Terminator is not needed.                 */
/*                                                              */
/* The [oby] parameter is specified as:                         */
/*   0                                                          */
/*   1 = OTN Bypass Enable. Should be set when receiving an     */
/*       OC-192 data stream.                                    */
/*                                                              */
/* The [sdhoff] parameter is specified as:                      */
/*   0                                                          */
/*   1 = SDH OFF. When set the SDH module is disconnected from  */
/*       the clock. This feature may be used to save power when */
/*       no SDH functionality is needed.                        */
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
  TEN_N10G_GBLR_DPCFG_t tmp_gblr_dpcfg;
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
      tmp_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG));
      tmp_gblr_dpcfg.bf.XSEL = xsel;
      tmp_gblr_dpcfg.bf.KPASEL = kpasel;
      tmp_gblr_dpcfg.bf.SBYPLD = sbypld;
      tmp_gblr_dpcfg.bf.SBYFRM = sbyfrm;
      tmp_gblr_dpcfg.bf.OBY = oby;
      tmp_gblr_dpcfg.bf.SDHOFF = sdhoff;
      tmp_gblr_dpcfg.bf.OTNOFF = otnoff;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG), tmp_gblr_dpcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET DATA PATH CFG SBYPLD                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_gblr_dpcfg_sbypld(cs_uint16 module_id,
                                         cs_uint8 slice, 
                                         cs_uint16 sbypld)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o SBYPLD                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Data Path Configuration bitfield    */
/* SBYPLD.                                                      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [sbypld] parameter is specified as:                      */
/*   0                                                          */
/*   1 = SDH Payload Bypass Enable. Should be set when the      */
/*       output from the SDH Terminator is not needed.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_DPCFG_t tmp_gblr_dpcfg;
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
      tmp_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG));
      tmp_gblr_dpcfg.bf.SBYPLD = sbypld;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG), tmp_gblr_dpcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET PRBS HYSTERESIS REGISTER            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_gblr_phys(cs_uint16 module_id,
                                 cs_uint8 slice, 
                                 cs_uint16 phys)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PHYS                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* PRBS Hysteresis. If more than PHYS bits do not match the     */
/* predicted PRBS sequence (and increment an internal error     */
/* counter beyond the PHYS threshold), a new sample of 8192     */
/* bits (64 x 128 bit words) length is taken from the           */
/* observed stream for PRBS detection. If less than PHYS of     */
/* these 8192 bits do not deviate from the predicted PRBS       */
/* sequence, the respective PRBS is considered to be found.     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [phys] parameter is specified as:                        */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_PHYS_t tmp_gblr_phys;
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
      tmp_gblr_phys.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, PHYS));
      tmp_gblr_phys.bf.PHYS = phys;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, PHYS), tmp_gblr_phys.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET KNOWN PATTER ANALYZER CONFIG 0      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_gblr_kpacfg0(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_uint16 fmm, 
                                    cs_uint16 pclr, 
                                    cs_uint16 pafrsti, 
                                    cs_uint16 pafrst, 
                                    cs_uint16 pafseti, 
                                    cs_uint16 pafset)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FMM                                           */
/*              o PCLR                                          */
/*              o PAFRSTI                                       */
/*              o PAFRST                                        */
/*              o PAFSETI                                       */
/*              o PAFSET                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Known Patter Analyzer Configuration 0.                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [fmm] parameter is specified as:                         */
/*   Fixed pattern Match Method                                 */
/*   0b00 = Stream matches PATa                                 */
/*   0b01 = Stream matches PATb                                 */
/*   0b10 = Stream matches PATa or PATb                         */
/*                                                              */
/* The [pclr] parameter is specified as:                        */
/*   0                                                          */
/*   1 = Clears PSTAT status, causing the KPA to search for a   */
/*       new PRBS sequence. It clears as the bit transition     */
/*       from 0 to 1                                            */
/*                                                              */
/* The [pafrsti] parameter is specified as:                     */
/*   0x0-0x7                                                    */
/*   Threshold for rstcnti (internal counter). When in the PF   */
/*   state and FPCNT exceeds FHYS at the end of an interval,    */
/*   rstcnti is incremented. When rstcnti exceeds PAFRSTI,      */
/*   rstcnt is reset to 0. Note that rstcnti is reset to 0 as   */
/*   a result of unsuccessful pattern detection (see also       */
/*   PAFRST).                                                   */
/*                                                              */
/* The [pafrst] parameter is specified as:                      */
/*   0x0-0x7                                                    */
/*   Threshold for rstcnt (internal counter). When in the PF    */
/*   state and FPCNT does not exceed FHYS at the end of an      */
/*   interval, rstcnt is incremented and rstcnti is reset to 0. */
/*   When rstcnt exceeds PAFRST, the IDLE state is entered      */
/*   (PF=0). Note that when there are more than PAFRSTI         */
/*   consecutive intervals in which FPCNT exceeds FHYS, the     */
/*   rstcnt counter is reset to 0 (see also PAFRSTI).           */
/*                                                              */
/* The [pafseti] parameter is specified as:                     */
/*   0x0-0x7                                                    */
/*   Threshold for setcnti (internal counter). When in the IDLE */
/*   state and FPCNT does not exceed FHYS at the end of an      */
/*   interval, setcnti is incremented. When setcnti exceeds     */
/*   PAFSETI, setcnt is reset to 0. Note that setcnti is reset  */
/*   to 0 as a result of successful pattern detection (see also */
/*   PAFSET).                                                   */
/*                                                              */
/* The [pafset] parameter is specified as:                      */
/*   0x0-0x7                                                    */
/*   Threshold for setcnt (internal counter). When in the IDLE  */
/*   state and FPCNT exceeds FHYS at the end of an interval,    */
/*   setcnt is incremented and setcnti is reset to 0. When      */
/*   setcnt exceeds PAFSET, the PF state is entered (PF=1).     */
/*   Note that when there are more than PAFSETI consecutive     */
/*   intervals in which FPCNT does not exceed FHYS, the setcnt  */
/*   counter is reset to 0 (see also PAFSETI).                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_KPACFG0_t tmp_gblr_kpacfg0;
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
      tmp_gblr_kpacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG0));
      tmp_gblr_kpacfg0.bf.FMM = fmm;
      tmp_gblr_kpacfg0.bf.PCLR = pclr;
      tmp_gblr_kpacfg0.bf.PAFRSTI = pafrsti;
      tmp_gblr_kpacfg0.bf.PAFRST = pafrst;
      tmp_gblr_kpacfg0.bf.PAFSETI = pafseti;
      tmp_gblr_kpacfg0.bf.PAFSET = pafset;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG0), tmp_gblr_kpacfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET PRBS DEASSERT HYSTERESIS REGISTER   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_gblr_pdhy(cs_uint16 module_id,
                                 cs_uint8 slice, 
                                 cs_uint16 pdhy0,
                                 cs_uint16 pdhy1)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PDHY0                                         */
/*              o PDHY1                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/*                                                              */
/* DESCRIPTION:                                                 */
/* PRBS Deassert Hysteresis. If PDHY bits have failed to match  */
/* the internally generated PRBS sequence (and incremented an   */
/* internal error counter beyond the PDHY threshold), the PRBS  */
/* is regarded as lost. If PDHY is set to 0xffffffff, the KPA   */
/* state machine will not retrigger automatically but has to be */
/* reset using GBLR:PCLR.                                       */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [pdhy0] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [pdhy1] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_PDHY0_t tmp_gblr_pdhy0;
  TEN_N10G_GBLR_PDHY1_t tmp_gblr_pdhy1;
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
      tmp_gblr_pdhy0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, PDHY0));
      tmp_gblr_pdhy0.bf.PDHY0 = pdhy0;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, PDHY0), tmp_gblr_pdhy0.wrd);
      tmp_gblr_pdhy1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, PDHY1));
      tmp_gblr_pdhy1.bf.PDHY1 = pdhy1;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, PDHY1), tmp_gblr_pdhy1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 10G KPA ANALYZER                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_config_kpa(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_uint16 fmm,
                              cs_uint16 prbs_stats_time_int,
                              cs_uint16 fixed_stats_time_int)

/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Fixed Pattern Match Method                    */
/*              o PRBS Statistics Time Interval                 */
/*              o Fixed Pattern Match Time Interval             */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the 10G Known Pattern Analyzer.                    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [fmm] parameter is specified as:                         */
/* (Fixed Pattern Match Method)                                 */
/*   0 = Stream matches PATa                                    */
/*   1 = Stream matches PATb                                    */
/*   2 = Stream matches PATa or PATb                            */
/*                                                              */
/* The [prbs_stats_time_int] parameter is specified as:         */
/*   0 = 1st internal timing generator                          */
/*   1 = 2nd internal timing generator                          */
/*   2 = 3rd internal timing generator                          */
/*   3 = 4th internal timing generator                          */
/*   4 = 5th internal timing generator                          */
/*   5 = 6th internal timing generator                          */
/*   6 = Software controlled timing generator                   */
/*   7 = Timing generator controlled by external hardware       */
/*                                                              */
/* The [fixed_stats_time_int] parameter is specified as:        */
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
  TEN_N10G_GBLR_KPACFG0_t tmp_gblr_kpacfg0;
  TEN_N10G_GBLR_KPACFG1_t tmp_gblr_kpacfg1;
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
      tmp_gblr_kpacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG0));
      tmp_gblr_kpacfg0.bf.FMM = fmm;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG0), tmp_gblr_kpacfg0.wrd);
      
      tmp_gblr_kpacfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG1));
      tmp_gblr_kpacfg1.bf.PTISEL = prbs_stats_time_int;
      tmp_gblr_kpacfg1.bf.FTISEL = fixed_stats_time_int;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG1), tmp_gblr_kpacfg1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 10G KPA ANALYZER FMM               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_config_kpa_fmm(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 fmm)

/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Fixed Pattern Match Method                    */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the 10G Known Pattern Analyzer.                    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [fmm] parameter is specified as:                         */
/* (Fixed Pattern Match Method)                                 */
/*   0 = Stream matches PATa                                    */
/*   1 = Stream matches PATb                                    */
/*   2 = Stream matches PATa or PATb                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_KPACFG0_t tmp_gblr_kpacfg0;
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
      tmp_gblr_kpacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG0));
      tmp_gblr_kpacfg0.bf.FMM = fmm;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG0), tmp_gblr_kpacfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 10G KPA ANALYZER PRBS INTERVAL     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_config_kpa_prbs_interval(cs_uint16 module_id,
                                            cs_uint8 slice,
                                            cs_uint16 prbs_stats_time_int)

/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PRBS Statistics Time Interval                 */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the 10G Known Pattern Analyzer.                    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [prbs_stats_time_int] parameter is specified as:         */
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
  TEN_N10G_GBLR_KPACFG1_t tmp_gblr_kpacfg1;
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
      tmp_gblr_kpacfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG1));
      tmp_gblr_kpacfg1.bf.PTISEL = prbs_stats_time_int;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG1), tmp_gblr_kpacfg1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 10G KPA ANALYZER FIXED INTERVAL    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_config_kpa_fixed_interval(cs_uint16 module_id,
                                             cs_uint8 slice,
                                             cs_uint16 fixed_stats_time_int)

/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o PRBS Statistics Time Interval                 */
/*              o Fixed Pattern Match Time Interval             */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the 10G Known Pattern Analyzer.                    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [fixed_stats_time_int] parameter is specified as:        */
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
  TEN_N10G_GBLR_KPACFG1_t tmp_gblr_kpacfg1;
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
      tmp_gblr_kpacfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG1));
      tmp_gblr_kpacfg1.bf.FTISEL = fixed_stats_time_int;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG1), tmp_gblr_kpacfg1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  RESTART 10G KNOWN PATTERN ANALYZER           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_restart_kpa(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */

/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Restart the 10G Known Pattern Analyzer.  Clears PSTAT status,*/
/* causing the KPA to search for new PRBS sequences.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_KPACFG0_t tmp_gblr_kpacfg0;
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
      tmp_gblr_kpacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG0));
      tmp_gblr_kpacfg0.bf.PCLR = 0;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG0), tmp_gblr_kpacfg0.wrd);
      TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
      tmp_gblr_kpacfg0.bf.PCLR = 1;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG0), tmp_gblr_kpacfg0.wrd);
      TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
      tmp_gblr_kpacfg0.bf.PCLR = 0;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, KPACFG0), tmp_gblr_kpacfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE 10G FIXED PATTERN MATCH            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_config_fixed_pattern_match(cs_uint16 module_id,
                                              cs_uint8 slice,
                                              cs_uint16 pattern,
                                              cs_uint16 parm1,
                                              cs_uint16 parm0)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Pattern Selection                             */
/*              o Parameter 1                                   */
/*              o Parameter 0                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the Fixed Pattern Match.                           */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   TEN_PATTERN_A,                                             */
/*   TEN_PATTERN_B,                                             */
/*   TEN_PATTERN_MASK                                           */
/*                                                              */
/* The [parm1-0] parameter is specified as:                     */
/*   First Search Pattern for Fixed Pattern Match Unit,         */
/*   Second Search Pattern for Fixed Pattern Match Unit,        */
/*   Mask for for Fixed Pattern Match Unit                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;
 
  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      switch (pattern) {
        case TEN_PATTERN_A:
          {
            TEN_N10G_GBLR_PATa1_t tmp_gblr_pata1;
            TEN_N10G_GBLR_PATa0_t tmp_gblr_pata0;

            tmp_gblr_pata1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, PATa1));
            tmp_gblr_pata1.bf.PATa1 = parm1;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, PATa1), tmp_gblr_pata1.wrd);
        
            tmp_gblr_pata0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, PATa0));
            tmp_gblr_pata0.bf.PATa0 = parm0;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, PATa0), tmp_gblr_pata0.wrd);
            break;
          }
        case TEN_PATTERN_B:
          {
            TEN_N10G_GBLR_PATb1_t tmp_gblr_patb1;
            TEN_N10G_GBLR_PATb0_t tmp_gblr_patb0;

            tmp_gblr_patb1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, PATb1));
            tmp_gblr_patb1.bf.PATb1 = parm1;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, PATb1), tmp_gblr_patb1.wrd);
        
            tmp_gblr_patb0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, PATb0));
            tmp_gblr_patb0.bf.PATb0 = parm0;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, PATb0), tmp_gblr_patb0.wrd);
            break;
          }
        case TEN_PATTERN_MASK:
          {
            TEN_N10G_GBLR_MASK0_t tmp_gblr_mask0;
            TEN_N10G_GBLR_MASK1_t tmp_gblr_mask1;

            tmp_gblr_mask1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, MASK1));
            tmp_gblr_mask1.bf.MASK1 = parm1;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, MASK1), tmp_gblr_mask1.wrd);

            tmp_gblr_mask0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, MASK0));
            tmp_gblr_mask0.bf.MASK0 = parm0;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, MASK0), tmp_gblr_mask0.wrd);
            break;
          }
        default :
          {
            CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..2.");
            ret_val = CS_ERROR;
            break;
          }  
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N10G GBLR SET XSEL                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_gblr_set_xsel(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint16 xsel)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o XSEL                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Data Path Configuration Register.   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [xsel] parameter is specified as:                        */
/*   Output to the cross connect select.                        */
/*   0b00 = bypass data coming from N40G                        */
/*   0b01 = Aligned OXU2                                        */
/*   0b10 and 0b11 = Unaligned data (Either SONET or OTN        */
/*                   extracted payload)                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_DPCFG_t tmp_gblr_dpcfg;
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
      tmp_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG));
      tmp_gblr_dpcfg.bf.XSEL = xsel;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG), tmp_gblr_dpcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G GBLR SET KPASEL                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_gblr_set_kpasel(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 kpasel)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o KPASEL                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Data Path Configuration Register.   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [kpasel] parameter is specified as:                      */
/*   KPA SELect:  selects input for Known Pattern Analyzer.     */
/*   0 = SDH payload                                            */
/*   1 = OxU2 payload                                           */
/*   2 = Client Input.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_DPCFG_t tmp_gblr_dpcfg;
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
      tmp_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG));
      tmp_gblr_dpcfg.bf.KPASEL = kpasel;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG), tmp_gblr_dpcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G GBLR LOSCFG0                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_gblr_loscfg0(cs_uint16 module_id, cs_uint8 slice,
                            cs_uint16 loscfg)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o LOSCFG                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the LOS detector Match Method.                              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [loscfg]                                                       */
/*     0 = Stream matches all-zeros                                 */
/*     1 = Stream matches all-ones                                  */
/*     2 = Stream matches all-zeros or all-ones.                    */
/*     3 = Disable generation of dLOS.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_LOSCFG0_t tmp_gblr_loscfg0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gblr_loscfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOSCFG0));
      tmp_gblr_loscfg0.bf.LOSCFG = loscfg;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOSCFG0), tmp_gblr_loscfg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G GBLR LOSCFG1                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_gblr_loscfg1(cs_uint16 module_id, cs_uint8 slice,
                            cs_uint16 los_ihys)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o LOS IHYS                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the time period during which the incoming LOS         */
/* condition must be set to 1 in order to trigger LOS alarm.        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [los_ihys]  timing base is the Line Clock (Mhz) divided by     */
/*     LOS_STEP+1.                                                  */
/*     Time Period = {(LOS_IHYS)*(STEP+1)} * LINE CLK (sec).        */
/*     Note: Value of zero is meaningless.                          */ 
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_LOSCFG1_t tmp_gblr_loscfg1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gblr_loscfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOSCFG1));
      tmp_gblr_loscfg1.bf.LOS_IHYS = los_ihys;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOSCFG1), tmp_gblr_loscfg1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G GBLR LOSCFG2                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_gblr_loscfg2(cs_uint16 module_id, cs_uint8 slice,
                            cs_uint16 los_ohys)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o LOS OHYS                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the time period during which the incoming LOS         */
/* condition must be set to 0 in order to clear LOS alarm.          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [los_ohys]  timing base is the Line Clock (Mhz) divided        */
/*     by LOS_STEP+1.                                               */
/*     Time Period = {(LOS_OHYS)*(STEP+1)} * LINE CLK (sec).        */
/*     Note: Value of zero is meaningless.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_LOSCFG2_t tmp_gblr_loscfg2;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gblr_loscfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOSCFG2));
      tmp_gblr_loscfg2.bf.LOS_OHYS = los_ohys;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOSCFG2), tmp_gblr_loscfg2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G GBLR LOSCFG3                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_gblr_loscfg3(cs_uint16 module_id, cs_uint8 slice,
                            cs_uint16 los_step)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o LOS STEP                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets LOS time base.                                              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [los_step]  Received Line clk(Mhz) divided by LOS_STEP+1.      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_LOSCFG3_t tmp_gblr_loscfg3;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gblr_loscfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOSCFG3));
      tmp_gblr_loscfg3.bf.LOS_STEP = los_step;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, LOSCFG3), tmp_gblr_loscfg3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G GET GBLR DPCFG SDHOFF                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_n10g_get_gblr_dpcfg_sdhoff(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Value                                           */
/* DESCRIPTION:                                                 */
/* Gets Data Path Configuration SDHOFF.                         */
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
  TEN_N10G_GBLR_DPCFG_t tmp_gblr_dpcfg;
  T41_t *pDev = NULL;

  TEN_N10G_VALIDATE(module_id, slice);
  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  return (tmp_gblr_dpcfg.bf.SDHOFF);
}



