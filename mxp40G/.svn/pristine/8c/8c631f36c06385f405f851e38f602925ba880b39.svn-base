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
 * ten_n10g_soht.c
 *
 * N10G related code is implemented here.
 *
 * $Id: ten_n10g_soht.c,v 1.11 2013/02/22 20:47:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N10G SET THE SOH BYTE                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_soh_byte(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint16 ovrhd,
                                cs_uint8 val)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Overhead Byte Type                            */
/*              o Overhead Byte Value                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SONET Overhead byte to be inserted in the transmit   */
/* stream.                                                      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [ovrhd] parameter is specified as following:             */
/*   TEN_SOH_M0 = 0,                                            */
/*   TEN_SOH_M1 = 1,                                            */
/*   TEN_SOH_DCM = 2,                                           */
/*   TEN_SOH_DCR = 3,                                           */
/*   TEN_SOH_K2 = 4,                                            */
/*   TEN_SOH_K1 = 5,                                            */
/*   TEN_SOH_OHDEF = 6,                                         */
/*   TEN_SOH_NU9 = 7,                                           */
/*   TEN_SOH_NU2 = 8,                                           */
/*   TEN_SOH_NU1 = 9,                                           */
/*   TEN_SOH_SSBITS = 10,                                       */
/*   TEN_SOH_E1 = 11,                                           */
/*   TEN_SOH_F1 = 12,                                           */
/*   TEN_SOH_S1 = 13,                                           */
/*   TEN_SOH_E2 = 14                                            */
/*                                                              */
/* The [val] parameter is specified as following:               */
/*   SONET Overhead Byte                                        */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = 0;
  cs_uint16 sl;
  
  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      switch (ovrhd) {
        case TEN_SOH_M0 :
          {
            TEN_N10G_SOHT_SOHBYTES0_t tmp_n10g_soht_sohbytes0;
            tmp_n10g_soht_sohbytes0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES0));
            tmp_n10g_soht_sohbytes0.bf.M0BYTE = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES0), tmp_n10g_soht_sohbytes0.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_M1 :
          {
            TEN_N10G_SOHT_SOHBYTES0_t tmp_n10g_soht_sohbytes0;
            tmp_n10g_soht_sohbytes0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES0));
            tmp_n10g_soht_sohbytes0.bf.M1BYTE = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES0), tmp_n10g_soht_sohbytes0.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_DCM :
          {
            TEN_N10G_SOHT_SOHBYTES1_t tmp_n10g_soht_sohbytes1;
            tmp_n10g_soht_sohbytes1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES1));
            tmp_n10g_soht_sohbytes1.bf.DCMBYTE = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES1), tmp_n10g_soht_sohbytes1.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_DCR :
          {
            TEN_N10G_SOHT_SOHBYTES1_t tmp_n10g_soht_sohbytes1;
            tmp_n10g_soht_sohbytes1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES1));
            tmp_n10g_soht_sohbytes1.bf.DCRBYTE = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES1), tmp_n10g_soht_sohbytes1.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_K2 :
          {
            TEN_N10G_SOHT_SOHBYTES2_t tmp_n10g_soht_sohbytes2;
            tmp_n10g_soht_sohbytes2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES2));
            tmp_n10g_soht_sohbytes2.bf.K2BYTE = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES2), tmp_n10g_soht_sohbytes2.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_K1 :
          {
            TEN_N10G_SOHT_SOHBYTES2_t tmp_n10g_soht_sohbytes2;
            tmp_n10g_soht_sohbytes2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES2));
            tmp_n10g_soht_sohbytes2.bf.K1BYTE = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES2), tmp_n10g_soht_sohbytes2.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_OHDEF :
          {
            TEN_N10G_SOHT_SOHBYTES3_t tmp_n10g_soht_sohbytes3;
            tmp_n10g_soht_sohbytes3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES3));
            tmp_n10g_soht_sohbytes3.bf.OHDEF = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES3), tmp_n10g_soht_sohbytes3.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_NU2 :
          {
            TEN_N10G_SOHT_SOHBYTES4_t tmp_n10g_soht_sohbytes4;
            tmp_n10g_soht_sohbytes4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES4));
            tmp_n10g_soht_sohbytes4.bf.NU2 = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES4), tmp_n10g_soht_sohbytes4.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_NU9 :
          {
            TEN_N10G_SOHT_SOHBYTES4_t tmp_n10g_soht_sohbytes4;
            tmp_n10g_soht_sohbytes4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES4));
            tmp_n10g_soht_sohbytes4.bf.NU9 = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES4), tmp_n10g_soht_sohbytes4.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_NU1 :
          {
            TEN_N10G_SOHT_SOHBYTES5_t tmp_n10g_soht_sohbytes5;
            tmp_n10g_soht_sohbytes5.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES5));
            tmp_n10g_soht_sohbytes5.bf.NU1 = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES5), tmp_n10g_soht_sohbytes5.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_SSBITS :
          {
            TEN_N10G_SOHT_SOHBYTES5_t tmp_n10g_soht_sohbytes5;
            tmp_n10g_soht_sohbytes5.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES5));
            tmp_n10g_soht_sohbytes5.bf.SSBITS = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES5), tmp_n10g_soht_sohbytes5.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_F1 :
          {
            TEN_N10G_SOHT_SOHBYTES6_t tmp_n10g_soht_sohbytes6;
            tmp_n10g_soht_sohbytes6.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES6));
            tmp_n10g_soht_sohbytes6.bf.F1 = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES6), tmp_n10g_soht_sohbytes6.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_E1 :
          {
            TEN_N10G_SOHT_SOHBYTES6_t tmp_n10g_soht_sohbytes6;
            tmp_n10g_soht_sohbytes6.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES6));
            tmp_n10g_soht_sohbytes6.bf.E1 = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES6), tmp_n10g_soht_sohbytes6.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_E2 :
          {
            TEN_N10G_SOHT_SOHBYTES7_t tmp_n10g_soht_sohbytes7;
            tmp_n10g_soht_sohbytes7.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES7));
            tmp_n10g_soht_sohbytes7.bf.E2 = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES7), tmp_n10g_soht_sohbytes7.wrd);
            rtn = CS_OK;
            break;
          }
        case TEN_SOH_S1 :
          {
            TEN_N10G_SOHT_SOHBYTES7_t tmp_n10g_soht_sohbytes7;
            tmp_n10g_soht_sohbytes7.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES7));
            tmp_n10g_soht_sohbytes7.bf.S1 = val;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, SOHBYTES7), tmp_n10g_soht_sohbytes7.wrd);
            rtn = CS_OK;
            break;
          }
        default :
          {
            CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..14.");
            rtn = CS_ERROR;
            break;
          } 
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET SOH BYTE IE                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_soh_byte_ie(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint16 ovrhd,
                                cs_uint8 ie)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Overhead Byte Type                            */
/*              o Overhead Byte IE                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SONET Overhead byte insertion enable.                */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [ovrhd] parameter is specified as following:             */
/*   TEN_SOH_M0 = 0,                                            */
/*   TEN_SOH_M1 = 1,                                            */
/*   TEN_SOH_DCM = 2,                                           */
/*   TEN_SOH_DCR = 3,                                           */
/*   TEN_SOH_K2 = 4,                                            */
/*   TEN_SOH_K1 = 5,                                            */
/*   TEN_SOH_OHDEF = 6,                                         */
/*   TEN_SOH_NU9 = 7,                                           */
/*   TEN_SOH_NU2 = 8,                                           */
/*   TEN_SOH_NU1 = 9,                                           */
/*   TEN_SOH_E1 = 11,                                           */
/*   TEN_SOH_F1 = 12,                                           */
/*   TEN_SOH_S1 = 13,                                           */
/*   TEN_SOH_E2 = 14                                            */
/*                                                              */
/* The [ie] parameter is specified as following:                */
/*   0 = No effect                                              */
/*   1 = SONET Overhead Byte Insertion Enable.                  */
/*                                                              */
/*   for K1/K2:                                                 */
/*   0 = Pass through                                           */
/*   1 = Insert from K1/K2 BYTE                                 */
/*   2 = Insert from OHDEF                                      */
/*   3 = Pass through.                                          */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = 0;
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN0_t tmp_soht_ohben0;
  TEN_N10G_SOHT_OHBEN1_t tmp_soht_ohben1;
  TEN_N10G_SOHT_OHBEN2_t tmp_soht_ohben2;
  
  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      switch (ovrhd) {
      case (TEN_SOH_M0):
        tmp_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2));
        tmp_soht_ohben2.bf.M0IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2), tmp_soht_ohben2.wrd);
        break;
        
      case (TEN_SOH_M1):
        tmp_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2));
        tmp_soht_ohben2.bf.M1IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2), tmp_soht_ohben2.wrd);
        break;
        
      case (TEN_SOH_DCM):
        tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
        tmp_soht_ohben0.bf.DCMIE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
        break;
        
      case (TEN_SOH_DCR):
        tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
        tmp_soht_ohben0.bf.DCRIE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
        break;

      case (TEN_SOH_K2):
        tmp_soht_ohben1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN1));
        tmp_soht_ohben1.bf.K2IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN1), tmp_soht_ohben1.wrd);
        break;
        
      case (TEN_SOH_K1):
        tmp_soht_ohben1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN1));
        tmp_soht_ohben1.bf.K1IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN1), tmp_soht_ohben1.wrd);
        break;
        
      case (TEN_SOH_OHDEF):
        tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
        tmp_soht_ohben0.bf.DEFIE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
        break;
        
      case (TEN_SOH_NU2):
        tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
        tmp_soht_ohben0.bf.NU2IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
        break;
        
      case (TEN_SOH_NU9):
        tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
        tmp_soht_ohben0.bf.NU9IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
        break;
        
      
      case (TEN_SOH_NU1):
        tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
        tmp_soht_ohben0.bf.NU1IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
        break;
      
      case (TEN_SOH_F1):
        tmp_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2));
        tmp_soht_ohben2.bf.F1IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2), tmp_soht_ohben2.wrd);
        break;
        
      case (TEN_SOH_E1):
        tmp_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2));
        tmp_soht_ohben2.bf.E1IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2), tmp_soht_ohben2.wrd);
        break;
      
      case (TEN_SOH_E2):
        tmp_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2));
        tmp_soht_ohben2.bf.E2IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2), tmp_soht_ohben2.wrd);
        break;
      
      case (TEN_SOH_S1):
        tmp_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2));
        tmp_soht_ohben2.bf.S1IE = ie;
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2), tmp_soht_ohben2.wrd);
        break;

      case (TEN_SOH_SSBITS):
      default :
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
        rtn = CS_ERROR;
        break;
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET THE POH BYTE                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_poh_byte(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint16 ovrhd,
                                cs_uint8 val)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Overhead Byte Type                            */
/*              o Overhead Byte Value                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SONET Overhead byte to be inserted in the transmit   */
/* stream.                                                      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [ovrhd] parameter is specified as following:             */
/*   TEN_SET_POH_C2 = 0,                                        */
/*   TEN_SET_POH_F2 = 1,                                        */
/*   TEN_SET_POH_G1 = 2,                                        */
/*   TEN_SET_POH_F3 = 3,                                        */
/*   TEN_SET_POH_H4 = 4,                                        */
/*   TEN_SET_POH_N1 = 5,                                        */
/*   TEN_SET_POH_K3 = 6,                                        */
/*   TEN_SET_POH_PFIXSF = 7,                                    */
/*   TEN_SET_POH_B3MSK = 8                                      */
/*                                                              */
/* The [val] parameter is specified as following:               */
/*   SONET Overhead Byte                                        */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = 0;
  cs_uint16 sl;
  
  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      switch (ovrhd) {
      case TEN_SET_POH_C2 :
        {
          TEN_N10G_SOHT_POHBYTES0_t tmp_n10g_soht_pohbytes0;
          tmp_n10g_soht_pohbytes0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES0));
          tmp_n10g_soht_pohbytes0.bf.C2BYTE = val;
          TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES0), tmp_n10g_soht_pohbytes0.wrd);
          rtn = CS_OK;
          break;
        }
      case TEN_SET_POH_F2 :
        {
          TEN_N10G_SOHT_POHBYTES1_t tmp_n10g_soht_pohbytes1;
          tmp_n10g_soht_pohbytes1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES1));
          tmp_n10g_soht_pohbytes1.bf.F2BYTE = val;
          TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES1), tmp_n10g_soht_pohbytes1.wrd);
          rtn = CS_OK;
          break;
        }
      case TEN_SET_POH_G1 :
        {
          TEN_N10G_SOHT_POHBYTES1_t tmp_n10g_soht_pohbytes1;
          tmp_n10g_soht_pohbytes1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES1));
          tmp_n10g_soht_pohbytes1.bf.G1BYTE = val;
          TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES1), tmp_n10g_soht_pohbytes1.wrd);
          rtn = CS_OK;
          break;
        }
      case TEN_SET_POH_F3 :
        {
          TEN_N10G_SOHT_POHBYTES2_t tmp_n10g_soht_pohbytes2;
          tmp_n10g_soht_pohbytes2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES2));
          tmp_n10g_soht_pohbytes2.bf.F3BYTE = val;
          TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES2), tmp_n10g_soht_pohbytes2.wrd);
          rtn = CS_OK;
          break;
        }
      case TEN_SET_POH_H4 :
        {
          TEN_N10G_SOHT_POHBYTES2_t tmp_n10g_soht_pohbytes2;
          tmp_n10g_soht_pohbytes2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES2));
          tmp_n10g_soht_pohbytes2.bf.H4BYTE = val;
          TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES2), tmp_n10g_soht_pohbytes2.wrd);
          rtn = CS_OK;
          break;
        }
      case TEN_SET_POH_N1 :
        {
          TEN_N10G_SOHT_POHBYTES3_t tmp_n10g_soht_pohbytes3;
          tmp_n10g_soht_pohbytes3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES3));
          tmp_n10g_soht_pohbytes3.bf.N1BYTE = val;
          TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES3), tmp_n10g_soht_pohbytes3.wrd);
          rtn = CS_OK;
          break;
        }
      case TEN_SET_POH_K3 :
        {
          TEN_N10G_SOHT_POHBYTES3_t tmp_n10g_soht_pohbytes3;
          tmp_n10g_soht_pohbytes3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES3));
          tmp_n10g_soht_pohbytes3.bf.K3BYTE = val;
          TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES3), tmp_n10g_soht_pohbytes3.wrd);
          rtn = CS_OK;
          break;
        }
      case TEN_SET_POH_PFIXSF :
        {
          TEN_N10G_SOHT_POHBYTES4_t tmp_n10g_soht_pohbytes4;
          tmp_n10g_soht_pohbytes4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES4));
          tmp_n10g_soht_pohbytes4.bf.PFIXSF = val;
          TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBYTES4), tmp_n10g_soht_pohbytes4.wrd);
          rtn = CS_OK;
          break;
        }
      case TEN_SET_POH_B3MSK :
        {
          TEN_N10G_SOHT_B3ERRINS_t tmp_n10g_soht_b3errins;
          tmp_n10g_soht_b3errins.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, B3ERRINS));
          tmp_n10g_soht_b3errins.bf.B3ErrMsk = val;
          TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, B3ERRINS), tmp_n10g_soht_b3errins.wrd);
          rtn = CS_OK;
          break;
        }
      default :
        {
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..8.");
          rtn = CS_ERROR;
          break;
        } 
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SET POH BYTE IE                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_poh_byte_ie(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint16 ovrhd,
                                cs_uint8 ie)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Overhead Byte Type                            */
/*              o Insertion Enable                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SONET Overhead byte insertion enable.                */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [ovrhd] parameter is specified as following:             */
/*     TEN_SET_POH_C2 = 0,                                      */
/*     TEN_SET_POH_F2 = 1,                                      */
/*     TEN_SET_POH_G1 = 2,                                      */
/*     TEN_SET_POH_F3 = 3,                                      */
/*     TEN_SET_POH_H4 = 4,                                      */
/*     TEN_SET_POH_N1 = 5,                                      */
/*     TEN_SET_POH_K3 = 6,                                      */
/*     TEN_SET_POH_PFIXSF = 7,                                  */
/*     TEN_SET_POH_B3MSK = 8                                    */
/*                                                              */
/* The [ie] parameter is specified as following:                */
/*   0 = Pass through.                                          */
/*   1 = Insert byte.                                           */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_uint16 sl;
  TEN_N10G_SOHT_POHBEN0_t tmp_soht_pohben0;
  
  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0));
      switch (ovrhd) {
      case (TEN_SET_POH_C2):
        tmp_soht_pohben0.bf.C2IE = ie;
        break;
        
      case (TEN_SET_POH_F2):
        tmp_soht_pohben0.bf.F2IE = ie;
        break;
        
      case (TEN_SET_POH_G1):
        tmp_soht_pohben0.bf.G1IE = ie;
        break;
        
      case (TEN_SET_POH_F3):
        tmp_soht_pohben0.bf.F3IE = ie;
        break;
        
      case (TEN_SET_POH_H4):
        tmp_soht_pohben0.bf.H4IE = ie;
        break;
        
      case (TEN_SET_POH_N1):
        tmp_soht_pohben0.bf.N1IE = ie;
        break;
        
      case (TEN_SET_POH_K3):
        tmp_soht_pohben0.bf.K3IE = ie;
        break;
        
      case (TEN_SET_POH_PFIXSF):
        tmp_soht_pohben0.bf.PFIXSFIE = ie;
        break;
        
      case (TEN_SET_POH_B3MSK):
        tmp_soht_pohben0.bf.B3IE = ie;
        break;

      default:
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..8.");
        rtn = CS_ERROR;
        break;
      }
      if (rtn == CS_OK) {
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0), tmp_soht_pohben0.wrd);
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT B2IE                                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_b2ie(cs_uint16 module_id, cs_uint8 slice, cs_uint8 instance, 
                          cs_uint16 b2ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o B2IE                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* These bits enable the insertion for each calculated B2 byte.     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [instance]  0..12, or TEN_INSTANCE_ALL (0xFF).                 */
/*      Note that bei12 has a slightly different pattern.           */
/*                                                                  */
/*   [b2ie]  enables the insertion for each calculated B2 byte.     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  cs_uint16 ii;
  TEN_N10G_SOHT_B2IE12_t tmp_soht_b2ie12;
  TEN_N10G_SOHT_B2IE0_t tmp_soht_b2ie0;
  T41_t *pDev = NULL;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if ((instance > TEN_N10G_SOHT_B2IE0_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..12.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      for (ii=0; ii<=TEN_N10G_SOHT_B2IE0_COUNT; ii++) {
        if ((instance == ii) || (instance == TEN_SLICE_ALL)) {
          if (ii == 12) {
            tmp_soht_b2ie12.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, B2IE12));
            tmp_soht_b2ie12.bf.B2IE12 = b2ie;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, B2IE12), tmp_soht_b2ie12.wrd);
          }
          else {
            tmp_soht_b2ie0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, B2IE0) + ii);
            tmp_soht_b2ie0.bf.B2IE0 = b2ie;
            TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, B2IE0) + ii, tmp_soht_b2ie0.wrd);
          }
        }
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN0 REGISTER                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_ohben0(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 b1ie,
                           cs_uint16 scren,
                           cs_uint16 a1a2rsh,
                           cs_uint16 a1a2ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o B1IE                                              */
/*              o SCREN                                             */
/*              o A1A2RSH                                           */
/*              o A1A2IE                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [b1ie]  Configures the insertion of the calculated             */
/*     BIP-8 at the B1 byte position.                               */
/*     0 = No effect.                                               */
/*     1 = Insert calculated B1 byte.                               */
/*                                                                  */
/*   [scren]  Configures the SONET/SDH scrambler operation.         */
/*     0 = Disable scrambling.                                      */
/*     1 = Enable scrambling.                                       */
/*                                                                  */
/*   [a1a2rsh]  Insert A1A2 to refresh FAS bytes received from Rx   */
/*     in case of bit error                                         */
/*                                                                  */
/*   [a1a2ie]  Configures the insertion of the Frame Alignment      */
/*     Sequence (FAS).  This bit has to be on with 10GE.            */ 
/*     0 = Pass through FAS bytes from data input.                  */
/*     1 = Insert FAS (creat a frame).                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN0_t tmp_soht_ohben0;
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
      tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
      tmp_soht_ohben0.bf.B1IE = b1ie;
      tmp_soht_ohben0.bf.SCREN = scren;
      tmp_soht_ohben0.bf.A1A2RSH = a1a2rsh;
      tmp_soht_ohben0.bf.A1A2IE = a1a2ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET B1IE                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_b1ie(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 b1ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o B1IE                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [b1ie]  Configures the insertion of the calculated             */
/*     BIP-8 at the B1 byte position.                               */
/*     0 = No effect.                                               */
/*     1 = Insert calculated B1 byte.                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN0_t tmp_soht_ohben0;
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
      tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
      tmp_soht_ohben0.bf.B1IE = b1ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET SCREN                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_scren(cs_uint16 module_id,
                                  cs_uint8 slice, 
                                  cs_uint16 scren)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o SCREN                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [scren]  Configures the SONET/SDH scrambler operation.         */
/*     0 = Disable scrambling.                                      */
/*     1 = Enable scrambling.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN0_t tmp_soht_ohben0;
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
      tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
      tmp_soht_ohben0.bf.SCREN = scren;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET A1A2IE                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_a1a2ie(cs_uint16 module_id,
                                   cs_uint8 slice, 
                                   cs_uint16 a1a2ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o A1A2IE                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [a1a2ie]  This bit configures the insertion of the Frame       */
/*     Alignment Sequence (FAS). This bit has to be on with 10GE.   */
/*     0 = Pass through FAS bytes from data input                   */
/*     1 = Insert FAS (creat a frame)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN0_t tmp_soht_ohben0;
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
      tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
      tmp_soht_ohben0.bf.A1A2IE = a1a2ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN0 J0IE                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_ohben0_j0ie(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 j0ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o J0IE                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [j0ie]  This bit configures the insertion of the section       */
/*     trace (J0 bytes).                                            */
/*     0 = No effect.                                               */
/*     1 = Insert J0 bytes cyclically from the section trace        */
/*         string buffer J0STRG.                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN0_t tmp_soht_ohben0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
      tmp_soht_ohben0.bf.J0IE = j0ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN0 J0MODE                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_ohben0_j0mode(cs_uint16 module_id,
                                          cs_uint8 slice, 
                                          cs_uint16 j0mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o J0MODE                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets J0 Insertion Mode Bits.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [j0mode]  J0MODE[1:0] If J0IE is set, these bits configure the */
/*     mode of insertion from the section trace buffer J0STRG to    */
/*     the J0 byte position.                                        */
/*       TEN_N10G_TRACE_SIZE_1_BYTE       = 0x0000                  */
/*       TEN_N10G_TRACE_SIZE_16_BYTE      = 0x0001                  */
/*       TEN_N10G_TRACE_SIZE_64_BYTE      = 0x0002                  */
/*       TEN_N10G_TRACE_SIZE_16_BYTE_CRC  = 0x0003                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN0_t tmp_soht_ohben0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (j0mode > TEN_N10G_TRACE_SIZE_16_BYTE_CRC) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": j0mode out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
      tmp_soht_ohben0.bf.J0MODE = j0mode;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN0 DEFIE                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_ohben0_defie(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 defie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DEFIE                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [defie]  Default SOH byte insertion enable. When set, all SOH  */
/*     bytes except for FAS will be replaced with the default       */
/*     byte configured for insertion in OHDEF.  This inserter has   */
/*     the lowest priority.                                         */
/*     0 = No effect.                                               */
/*     1 = Insert default byte from OHDEF.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN0_t tmp_soht_ohben0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
      tmp_soht_ohben0.bf.DEFIE = defie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN0 NU1IE                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_ohben0_nu1ie(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 nu1ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o NU1IE                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [nu1ie]  Configures the insertion of the national use bytes in */
/*     TOH row 1.  All bytes in columns 7, 8, and 9 subsequent to   */
/*     the J0 byte position are affected.  Also can enable          */
/*     incremental pattern.                                         */
/*     0 = No effect.                                               */
/*     1 = Insert byte as configured in NU1BYTE.                    */
/*     2 = Incremental pattern 00000010 00000011 .. etc.            */
/*     3 = No effect.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN0_t tmp_soht_ohben0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0));
      tmp_soht_ohben0.bf.NU1IE = nu1ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN0), tmp_soht_ohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN1 REGISTER                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_ohben1(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 b2inv, 
                           cs_uint16 b1inv, 
                           cs_uint16 b2trans, 
                           cs_uint16 b1trans)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o B2INV                                             */
/*              o B1INV                                             */
/*              o B2TRANS                                           */
/*              o B1TRANS                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [b2inv]  Configures B2 byte inversion control. Used for        */
/*     testing purposes only.                                       */
/*     0 = No effect.                                               */
/*     1 = Invert all 192 calculated BIP-8 bitwise prior to         */
/*     insertion at respective B2 byte positions.                   */
/*                                                                  */
/*   [b1inv]  Configures B1 byte inversion control. Used for        */
/*     testing purposes only.                                       */ 
/*     0 = No effect.                                               */
/*     1 = Invert calculated BIP-8 bitwise prior to insertion       */
/*     at B1 byte position.                                         */
/*                                                                  */
/*   [b2trans]  Enables B2 error transparency for all B2 bytes      */
/*     at the same time.                                            */
/*     0 = No effect                                                */
/*     1 = Insert calculated B2 bytes XORed with BIP-8 values       */
/*     from receiver.                                               */
/*                                                                  */
/*   [b1trans]  Enables B1 error transparency (default is B1 byte   */
/*     transparency) in OC-192 mode of operation.                   */
/*     0 = No effect                                                */
/*     1 = Insert calculated B1 byte XORed with BIP-8               */
/*     from receiver.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN1_t tmp_soht_ohben1;
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
      tmp_soht_ohben1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN1));
      tmp_soht_ohben1.bf.B2INV = b2inv;
      tmp_soht_ohben1.bf.B1INV = b1inv;
      tmp_soht_ohben1.bf.B2TRANS = b2trans;
      tmp_soht_ohben1.bf.B1TRANS = b1trans;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN1), tmp_soht_ohben1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN1 K2IE                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_ohben1_k2ie(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 k2ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o K2IE                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [k2ie]                                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN1_t tmp_soht_ohben1;
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
      tmp_soht_ohben1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN1));
      tmp_soht_ohben1.bf.K2IE = k2ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN1), tmp_soht_ohben1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN1 K1IE                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_ohben1_k1ie(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 k1ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o K1IE                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [k1ie]                                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN1_t tmp_soht_ohben1;
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
      tmp_soht_ohben1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN1));
      tmp_soht_ohben1.bf.K1IE = k1ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN1), tmp_soht_ohben1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN2                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_ohben2(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 m1ie, 
                           cs_uint16 m0ie) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o M1IE                                              */
/*              o M0IE                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures insertion at the M0/M1 byte position.                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [m1ie]                                                         */
/*     0 = No effect.                                               */
/*     1 = Insert from M1BYTE                                       */
/*                                                                  */
/*   [m0ie]                                                         */
/*     0 = No effect.                                               */
/*     1 = Insert from M0BYTE.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN2_t tmp_soht_ohben2;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2));
      tmp_soht_ohben2.bf.M1IE = m1ie;
      tmp_soht_ohben2.bf.M0IE = m0ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2), tmp_soht_ohben2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN3                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_ohben3(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_uint16 alt_scren)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o ALT SCREN                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Insertion Enable Bits.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [alt_scren]   This bit configures the SONET/SDH alternate      */
/*     scrambler operation.                                         */
/*     0 = Disable alternate scrambling.                            */
/*     1 = Enable alternate scrambling.                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN3_t tmp_soht_ohben3;
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
      tmp_soht_ohben3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN3));
      tmp_soht_ohben3.bf.ALT_SCREN = alt_scren;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN3), tmp_soht_ohben3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT OHBEN3 DIS A1A2 AIS                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_ohben3_dis_a1a2_ais(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 dis_a1a2_ais)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DIS A1A2 AIS                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This bit disables automatic insertion of A1A2 when AIS-L is      */
/* being inserted from the SFU. This should be set to 1 for         */
/* generation of OC-768.                                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dis_a1a2_ais]                                                 */
/*    0 = Disable alternate scrambling                              */
/*    1 = Enable alternate scrambling.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN3_t tmp_soht_ohben3;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_ohben3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN3));
      tmp_soht_ohben3.bf.DIS_A1A2_AIS = dis_a1a2_ais;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN3), tmp_soht_ohben3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT OHBEN3 DIS B1 AIS                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_ohben3_dis_b1_ais(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 dis_b1_ais)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DIS B1 AIS                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This bit disables automatic insertion of B1 when AIS-L is        */
/* being inserted from the SFU. This should be set to 1 for         */
/* generation of OC-768.                                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dis_b1_ais]                                                   */
/*    0 = Disable alternate scrambling                              */
/*    1 = Enable alternate scrambling.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN3_t tmp_soht_ohben3;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_ohben3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN3));
      tmp_soht_ohben3.bf.DIS_B1_AIS = dis_b1_ais;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN3), tmp_soht_ohben3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET B1 ERROR MASK                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_b1errmsk(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 b1errmsk)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o B1ErrMsk                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets B1 error insertion register.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [b1errmsk]  B1 error mask                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_B1ERRINS_t tmp_soht_b1errins;
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
      tmp_soht_b1errins.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, B1ERRINS));
      tmp_soht_b1errins.bf.B1ErrMsk = b1errmsk;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, B1ERRINS), tmp_soht_b1errins.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET B2 ERROR MASK                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_b2errmsk(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 b2errmsk)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o B2ErrMsk                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets B2 error insertion register.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [b2errmsk]   B2 error mask.                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_B2ERRINS_t tmp_soht_b2errins;
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
      tmp_soht_b2errins.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, B2ERRINS));
      tmp_soht_b2errins.bf.B2ErrMsk = b2errmsk;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, B2ERRINS), tmp_soht_b2errins.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT J0STRG0                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_j0strg0(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint8 instance, 
                                cs_uint16 j0strg0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o J0STRG0                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets individually numbered bytes of J0 TX String.                */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..31                                                          */
/*                                                                  */
/* The [j0strg0] parameter is specified as:                         */
/*   0x0000..0xFFFF: J0STRG0[15:0] This 64-byte array contains the  */
/*   section trace string provided by the processor for insertion   */
/*   at the J0 byte position of the TOH. When J0IE is set,          */
/*   successive bytes of the string will be transmitted cyclically  */
/*   on a frame-by-frame basis, as configured in J0MODE. The first  */
/*   byte goes in bits 7..0 of instance 0, the second byte goes in  */
/*   bits 15..8 of instance 0, the third byte goes in bits 7..0 of  */
/*   instance 1, etc.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_J0STRG0_t tmp_soht_j0strg0;
  T41_t *pDev = NULL;
  
  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (instance >= TEN_N10G_SOHT_J0STRG0_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..31.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_j0strg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, J0STRG0)
                                          + (instance*TEN_N10G_SOHT_J0STRG0_STRIDE));
      tmp_soht_j0strg0.bf.J0STRG0 = j0strg0;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, J0STRG0)
                    + (instance*TEN_N10G_SOHT_J0STRG0_STRIDE), tmp_soht_j0strg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT J0 STRING PTR                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_j0strg_ptr(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_uint16 str_size,
                                   cs_char8 *str)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o String Size                                       */
/*              o String                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Programs J0 TX String with the user-specified string,            */
/* with a string size up to 62 bytes.                               */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [str_size] parameter is specified as:                        */
/*   size of string: up to 62.                                      */
/*                                                                  */
/* The [str] parameter is specified as: a pointer to a              */
/*   an up to 62 byte string.  This string contains the section     */
/*   trace string provided by the processor for insertion           */
/*   at the J0 byte position of the TOH.  When J0IE is set,         */
/*   successive bytes of the string will be transmitted cyclically  */
/*   on a frame-by-frame basis, as configured in J0MODE. The first  */
/*   byte goes in bits 7..0 of instance 0, the second byte goes in  */
/*   bits 15..8 of instance 0, the third byte goes in bits 7..0 of  */
/*   instance 1, etc.                                               */
/*                                                                  */
/*   NOTE:  The API will automatically pad the string entered       */
/*          by the user to 62 characters using ASCII NULL (0x00)    */
/*          characters, and then add CR-LF characters (0x0D-0x0A)   */
/*          for a total of 64 characters.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_char8 *tmp_str;
  cs_uint16 sl;
  TEN_N10G_SOHT_J0STRG0_t tmp_soht_j0strg0;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  
  TEN_N10G_VALIDATE(module_id, slice);
  
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  
  if ((!str_size) || (str_size > 62)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string size out of range.  s/b 1..62.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_str = str;
      for (ii=0; ii<62; ii+=2) {
        if (ii >= str_size) {
          tmp_soht_j0strg0.bf.J0STRG0 = 0;
        }
        else {
          tmp_soht_j0strg0.bf.J0STRG0 = (*tmp_str)&0x00FF;
        }  
        tmp_str++;
        if ((ii+1) < str_size) {
          /* Bugzilla #25564, fix for older compilers */
          tmp_soht_j0strg0.wrd = (tmp_soht_j0strg0.wrd & 0x00FF);
          tmp_soht_j0strg0.bf.J0STRG0 |= (((*tmp_str)<<8)&0xFF00);
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, J0STRG0) + 
                      ((ii / 2) * TEN_N10G_SOHT_J0STRG0_STRIDE),
                      tmp_soht_j0strg0.wrd);
        tmp_str++;
      }
      /* add CR-LF, LSB goes out first */
      tmp_soht_j0strg0.bf.J0STRG0 = 0x0A0D;
            /* bugzilla #24439, klocwork */
      tmp_addr = TEN_N10G_REG_ADDR(pDev, module_id, sl, J0STRG0);
      tmp_addr += (31 * TEN_N10G_SOHT_J0STRG0_STRIDE);
      TEN_REG_WRITE(tmp_addr, tmp_soht_j0strg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT GET J0 STRING                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_get_j0strg(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_char8 *str)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o String                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns J0 TX String with the user-specified string,             */
/* with a string of 64 bytes.                                       */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [str] a pointer to a 64 byte string.                         */
/*                                                                  */
/*   NOTE:  The string entered by the user to 62 characters was     */
/*          padded using ASCII NULL (0x00) characters, and then     */
/*          CR-LF characters (0x0D-0x0A) added for a total of 64    */
/*          characters.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_char8 *tmp_str;
  TEN_N10G_SOHT_J0STRG0_t tmp_soht_j0strg0;
  T41_t *pDev = NULL;
  
  TEN_N10G_VALIDATE(module_id, slice);
  
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  tmp_str = str;
  for (ii=0; ii<64; ii+=2) {
    tmp_soht_j0strg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, J0STRG0) + 
                                        ((ii / 2) * TEN_N10G_SOHT_J0STRG0_STRIDE));
    *tmp_str =  (cs_char8)(tmp_soht_j0strg0.wrd & 0x00FF);
    tmp_str++;
    *tmp_str =  (cs_char8)((tmp_soht_j0strg0.wrd & 0xFF00)>>8);
    tmp_str++;
  }

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT PRINT J0 STRING                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_print_j0strg(cs_uint16 module_id,
                                     cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Prints J0 TX String.                                             */
/* This API is mainly for debugging purposes.                       */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_char8 tmp_str[64];
  cs_status rtn;
  
  rtn = ten_n10g_soht_get_j0strg(module_id, slice, tmp_str);
  
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_str, 64);
  }
  else {
    CS_PRINT("ten_n10g_soht_print_j0strg was unsuccessful.\n");
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT J1STRG0                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_j1strg0(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint8 instance, 
                                cs_uint16 j1strg0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o J1STRG0                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets individually numbered bytes of J1 TX String.                */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..31                                                          */
/*                                                                  */
/* The [j1strg0] parameter is specified as:                         */
/*   0x0000..0xFFFF: J1STRG0[15:0] This 64-byte array contains the  */
/*   path trace string provided by the processor for insertion      */
/*   at the J1 byte position of the TOH. When J1IE is set,          */
/*   successive bytes of the string will be transmitted cyclically  */
/*   on a frame-by-frame basis, as configured in J1MODE. The first  */
/*   byte goes in bits 7..0 of instance 0, the second byte goes in  */
/*   bits 15..8 of instance 0, the third byte goes in bits 7..0 of  */
/*   instance 1, etc.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_J1STRG0_t tmp_soht_j1strg0;
  T41_t *pDev = NULL;
  
  TEN_N10G_VALIDATE(module_id, slice);
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (instance >= TEN_N10G_SOHT_J1STRG0_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..31.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_j1strg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, J1STRG0)
                                          + (instance*TEN_N10G_SOHT_J1STRG0_STRIDE));
      tmp_soht_j1strg0.bf.J1STRG0 = j1strg0;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, J1STRG0)
                    + (instance*TEN_N10G_SOHT_J1STRG0_STRIDE), tmp_soht_j1strg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT J1 STRING PTR                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_j1strg_ptr(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_uint16 str_size,
                                   cs_char8 *str)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o String Size                                       */
/*              o String                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Programs J1 TX String with the user-specified string,            */
/* with a string size up to 62 bytes.                               */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [str_size] parameter is specified as:                        */
/*   size of string: up to 62.                                      */
/*                                                                  */
/* The [str] parameter is specified as: a pointer to a              */
/*   an up to 62 byte string.  This string contains the section     */
/*   trace string provided by the processor for insertion           */
/*   at the J1 byte position of the TOH.  When J1IE is set,         */
/*   successive bytes of the string will be transmitted cyclically  */
/*   on a frame-by-frame basis, as configured in J1MODE. The first  */
/*   byte goes in bits 7..0 of instance 0, the second byte goes in  */
/*   bits 15..8 of instance 0, the third byte goes in bits 7..0 of  */
/*   instance 1, etc.                                               */
/*                                                                  */
/*   NOTE:  The API will automatically pad the string entered       */
/*          by the user to 62 characters using ASCII NULL (0x00)    */
/*          characters, and then add CR-LF characters (0x0D-0x0A)   */
/*          for a total of 64 characters.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_char8 *tmp_str;
  cs_uint16 sl;
  TEN_N10G_SOHT_J1STRG0_t tmp_soht_j1strg0;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  
  TEN_N10G_VALIDATE(module_id, slice);
  
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  
  if ((!str_size) || (str_size > 62)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string size out of range.  s/b 1..62.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_str = str;
      for (ii=0; ii<62; ii+=2) {
        if (ii >= str_size) {
          tmp_soht_j1strg0.bf.J1STRG0 = 0; 
        }
        else {
          tmp_soht_j1strg0.bf.J1STRG0 = (*tmp_str)&0x00FF;
        }  
        tmp_str++;
        if ((ii+1) < str_size) {
          /* Bugzilla #25564, fix for older compilers */
          tmp_soht_j1strg0.wrd = (tmp_soht_j1strg0.wrd & 0x00FF);
          tmp_soht_j1strg0.bf.J1STRG0 |= (((*tmp_str)<<8)&0xFF00);
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, J1STRG0) + 
                      ((ii / 2) * TEN_N10G_SOHT_J1STRG0_STRIDE), tmp_soht_j1strg0.wrd);
        tmp_str++;
      }
      /* add CR-LF, LSB goes out first */
      tmp_soht_j1strg0.bf.J1STRG0 = 0x0A0D;
      
      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_N10G_REG_ADDR(pDev, module_id, sl, J1STRG0);
      tmp_addr += 31 * TEN_N10G_SOHT_J1STRG0_STRIDE;
      TEN_REG_WRITE(tmp_addr, tmp_soht_j1strg0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT GET J1 STRING                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_get_j1strg(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_char8 *str)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o String                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns J1 TX String with the user-specified string,             */
/* with a string of 64 bytes.                                       */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [str] a pointer to a 64 byte string.                         */
/*                                                                  */
/*   NOTE:  The string entered by the user to 62 characters was     */
/*          padded using ASCII NULL (0x00) characters, and then     */
/*          CR-LF characters (0x0D-0x0A) added for a total of 64    */
/*          characters.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_char8 *tmp_str;
  TEN_N10G_SOHT_J1STRG0_t tmp_soht_j1strg0;
  T41_t *pDev = NULL;
  
  TEN_N10G_VALIDATE(module_id, slice);
  
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if (!str) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Null Ptr.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  tmp_str = str;
  for (ii=0; ii<64; ii+=2) {
    tmp_soht_j1strg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, J1STRG0) + 
                                        ((ii / 2) * TEN_N10G_SOHT_J1STRG0_STRIDE));
    *tmp_str =  (cs_char8)(tmp_soht_j1strg0.wrd & 0x00FF);
    tmp_str++;
    *tmp_str =  (cs_char8)((tmp_soht_j1strg0.wrd & 0xFF00)>>8);
    tmp_str++;
  }

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT PRINT J1 STRING                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_print_j1strg(cs_uint16 module_id,
                                     cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Prints J1 TX String.                                             */
/* This API is mainly for debugging purposes.                       */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_char8 tmp_str[64];
  cs_status rtn;
  
  rtn = ten_n10g_soht_get_j1strg(module_id, slice, tmp_str);
  
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_str, 64);
  }
  else {
    CS_PRINT("ten_n10g_soht_print_j1strg was unsuccessful.\n");
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT POHBEN0 REGISTER                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_pohben0(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 prbsie, 
                                cs_uint16 pohie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PRBSIE                                            */
/*              o POHIE                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [prbsie]  The virtual container of the concatenated payload    */
/*     SONET/SDH frames will be replaced with PRBS as               */
/*     configured for the KPA.  First column of VC/SPE is           */
/*     dedicated to POH and the rest of the VC/SPE is PRBS. To      */
/*     insert AU pointer/concatenation and POH, POHIE has to be on. */
/*                                                                  */
/*   [pohie]  Configures the insertion of POH bytes.                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_POHBEN0_t tmp_soht_pohben0;
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
      tmp_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0));
      tmp_soht_pohben0.bf.PRBSIE = prbsie;
      tmp_soht_pohben0.bf.POHIE = pohie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0), tmp_soht_pohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT PRBSIE                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_prbsie(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 prbsie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PRBSIE                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [prbsie]  The virtual container of the concatenated payload    */
/*     SONET/SDH frames will be replaced with PRBS as               */
/*     configured for the KPA.  First column of VC/SPE is           */
/*     dedicated to POH and the rest of the VC/SPE is PRBS. To      */
/*     insert AU pointer/concatenation and POH, POHIE has to be on. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_POHBEN0_t tmp_soht_pohben0;
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
      tmp_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0));
      tmp_soht_pohben0.bf.PRBSIE = prbsie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0), tmp_soht_pohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT POHIE                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_pohie(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 pohie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o POHIE                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pohie]  Configures the insertion of POH bytes.                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_POHBEN0_t tmp_soht_pohben0;
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
      tmp_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0));
      tmp_soht_pohben0.bf.POHIE = pohie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0), tmp_soht_pohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET POHBEN0 J1IE                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_pohben0_j1ie(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 j1ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o J1IE                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [j1ie]  This bit configures the insertion of the path          */
/*     trace (J1 bytes).                                            */
/*     0 = No effect.                                               */
/*     1 = Insert J1 bytes cyclically from the path trace           */
/*         string buffer J1STRG.                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_POHBEN0_t tmp_soht_pohben0;
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
      tmp_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0));
      tmp_soht_pohben0.bf.J1IE = j1ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0), tmp_soht_pohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET POHBEN0 J1MODE                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_pohben0_j1mode(cs_uint16 module_id,
                                           cs_uint8 slice, 
                                           cs_uint16 j1mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o J1MODE                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets J1 Insertion Mode Bits.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [j1mode]  J1MODE[1:0] If J1IE is set, these bits configure the */
/*     mode of insertion from the path trace buffer J1STRG to       */
/*     the J1 byte position.                                        */
/*       TEN_N10G_TRACE_SIZE_1_BYTE       = 0x0000                  */
/*       TEN_N10G_TRACE_SIZE_16_BYTE      = 0x0001                  */
/*       TEN_N10G_TRACE_SIZE_64_BYTE      = 0x0002                  */
/*       TEN_N10G_TRACE_SIZE_16_BYTE_CRC  = 0x0003                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_POHBEN0_t tmp_soht_pohben0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (j1mode > TEN_N10G_TRACE_SIZE_16_BYTE_CRC) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": j1mode out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0));
      tmp_soht_pohben0.bf.J1MODE = j1mode;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0), tmp_soht_pohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET POHBEN0 C2IE                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_pohben0_c2ie(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 c2ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o C2IE                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [c2ie]                                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_POHBEN0_t tmp_soht_pohben0;
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
      tmp_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0));
      tmp_soht_pohben0.bf.C2IE = c2ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0), tmp_soht_pohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET POHBEN0 B3IE                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_pohben0_b3ie(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 b3ie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o B3IE                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [b3ie]                                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_POHBEN0_t tmp_soht_pohben0;
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
      tmp_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0));
      tmp_soht_pohben0.bf.B3IE = b3ie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN0), tmp_soht_pohben0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N10G SOHT SET POHBEN1                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n10g_soht_set_pohben1(cs_uint16 module_id, cs_uint8 slice, 
                            cs_uint16 ndfie)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o NDFIE                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ndfie]                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_POHBEN1_t tmp_soht_pohben1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_pohben1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN1));
      tmp_soht_pohben1.bf.NDFIE = ndfie;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, POHBEN1), tmp_soht_pohben1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN2 MAIS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_mais(cs_uint16 module_id,
                            cs_uint8  slice, 
                            cs_uint16 mais)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o MAIS                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The Line or Multiplex Section overhead and all payload will  */
/* be replaced with an all-ones pattern.                        */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mais] parameter is specified as:                        */
/*   0 = No effect.                                             */
/*   1 = Generate L/MS-AIS frames.                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN2_t tmp_soht_ohben2;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2));
      tmp_soht_ohben2.bf.MAIS = mais;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2), tmp_soht_ohben2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN2 MAISMSK                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_maismsk(cs_uint16 module_id,
                               cs_uint8  slice, 
                               cs_uint16 maismsk)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o MAISMSK                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This bit enables MS-AIS maintenance signal insertion by the  */
/* SFU.                                                         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [maismsk] parameter is specified as:                     */
/*   0 = Ignore maintenance signal insertion request.           */
/*   1 = Allow MS-AIS insertion by an SFU Consequent Action,    */
/*       forced MS-AIS insertion by the SFU using MSignal,      */
/*       or MS-AIS insertion under FPGA control through the     */
/*       Parallel Overhead Port.                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN2_t tmp_soht_ohben2;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2));
      tmp_soht_ohben2.bf.MAISMSK = maismsk;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2), tmp_soht_ohben2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SOHT SET OHBEN2 RDIMSK                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_rdimsk(cs_uint16 module_id,
                              cs_uint8  slice, 
                              cs_uint16 rdimsk)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o RDIMSK                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This bit enables RDI maintenance signal insertion by the SFU.*/
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [maismsk] parameter is specified as:                     */
/*   0 = Ignore maintenance signal insertion request.           */
/*   1 = Allow RDI insertion by an SFU Consequent Action,       */
/*       forced RDI insertion by the SFU using MSignal,         */
/*       or RDI insertion under FPGA control through the        */
/*       Parallel Overhead Port.                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_SOHT_OHBEN2_t tmp_soht_ohben2;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2));
      tmp_soht_ohben2.bf.RDIMSK = rdimsk;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OHBEN2), tmp_soht_ohben2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G SOHT FORCE AIS-P                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_soht_force_aisp(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_uint8 sts, 
                                   cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o STS Number                                    */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Forces AIS-P onto one of the 192 STS-1's.                    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [sts] parameter is specified as:                         */
/*   1 - 192                                                    */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits an AIS-P on selected STS-1's        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if ((sts == 0) || (sts > 192)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": sts out of range.  s/b 1..192.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      if (sts <16) {
        TEN_N10G_SOHT_AIS0_t tmp_soht_ais0;
        tmp_soht_ais0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS0));
        if (state == 1) {
          tmp_soht_ais0.wrd |= (0x0001 << (sts-1));
        }
        else {
          tmp_soht_ais0.wrd &= ~(0x0001 << (sts-1));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS0), tmp_soht_ais0.wrd);
      }
      else if ((sts > 15) && (sts < 31)) {
        TEN_N10G_SOHT_AIS1_t tmp_soht_ais1;
        tmp_soht_ais1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS1));
        if (state == 1) {
          tmp_soht_ais1.wrd |= (0x0001 << (sts-16));
        }
        else {
          tmp_soht_ais1.wrd &= ~(0x0001 << (sts-16));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS1), tmp_soht_ais1.wrd);
      }
      else if ((sts > 30) && (sts < 46)) {
        TEN_N10G_SOHT_AIS2_t tmp_soht_ais2;
        tmp_soht_ais2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS2));
        if (state == 1) {
          tmp_soht_ais2.wrd |= (0x0001 << (sts-31));
        }
        else {
          tmp_soht_ais2.wrd &= ~(0x0001 << (sts-31));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS2), tmp_soht_ais2.wrd);
      }
      else if ((sts > 45) && (sts < 61)) {
        TEN_N10G_SOHT_AIS3_t tmp_soht_ais3;
        tmp_soht_ais3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS3));
        if (state == 1) {
          tmp_soht_ais3.wrd |= (0x0001 << (sts-46));
        }
        else {
          tmp_soht_ais3.wrd &= ~(0x0001 << (sts-46));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS3), tmp_soht_ais3.wrd);
      }
      else if ((sts > 60) && (sts < 76)) {
        TEN_N10G_SOHT_AIS4_t tmp_soht_ais4;
        tmp_soht_ais4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS4));
        if (state == 1) {
          tmp_soht_ais4.wrd |= (0x0001 << (sts-61));
        }
        else {
          tmp_soht_ais4.wrd &= ~(0x0001 << (sts-61));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS4), tmp_soht_ais4.wrd);
      }
      else if ((sts > 75) && (sts < 91)) {
        TEN_N10G_SOHT_AIS5_t tmp_soht_ais5;
        tmp_soht_ais5.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS5));
        if (state == 1) {
          tmp_soht_ais5.wrd |= (0x0001 << (sts-76));
        }
        else {
          tmp_soht_ais5.wrd &= ~(0x0001 << (sts-76));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS5), tmp_soht_ais5.wrd);
      }
      else if ((sts > 90) && (sts < 106)) {
        TEN_N10G_SOHT_AIS6_t tmp_soht_ais6;
        tmp_soht_ais6.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS6));
        if (state == 1) {
          tmp_soht_ais6.wrd |= (0x0001 << (sts-91));
        }
        else {
          tmp_soht_ais6.wrd &= ~(0x0001 << (sts-91));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS6), tmp_soht_ais6.wrd);
      }
      else if ((sts > 105) && (sts < 121)) {
        TEN_N10G_SOHT_AIS7_t tmp_soht_ais7;
        tmp_soht_ais7.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS7));
        if (state == 1) {
          tmp_soht_ais7.wrd |= (0x0001 << (sts-106));
        }
        else {
          tmp_soht_ais7.wrd &= ~(0x0001 << (sts-106));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS7), tmp_soht_ais7.wrd);
      }
      else if ((sts > 120) && (sts < 136)) {
        TEN_N10G_SOHT_AIS8_t tmp_soht_ais8;
        tmp_soht_ais8.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS8));
        if (state == 1) {
          tmp_soht_ais8.wrd |= (0x0001 << (sts-121));
        }
        else {
          tmp_soht_ais8.wrd &= ~(0x0001 << (sts-121));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS8), tmp_soht_ais8.wrd);
      }
      else if ((sts > 135) && (sts < 151)) {
        TEN_N10G_SOHT_AIS9_t tmp_soht_ais9;
        tmp_soht_ais9.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS9));
        if (state == 1) {
          tmp_soht_ais9.wrd |= (0x0001 << (sts-136));
        }
        else {
          tmp_soht_ais9.wrd &= ~(0x0001 << (sts-136));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS9), tmp_soht_ais9.wrd);
      }
      else if ((sts > 150) && (sts < 166)) {
        TEN_N10G_SOHT_AIS10_t tmp_soht_ais10;
        tmp_soht_ais10.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS10));
        if (state == 1) {
          tmp_soht_ais10.wrd |= (0x0001 << (sts-151));
        }
        else {
          tmp_soht_ais10.wrd &= ~(0x0001 << (sts-151));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS10), tmp_soht_ais10.wrd);
      }
      else if ((sts > 165) && (sts < 181)) {
        TEN_N10G_SOHT_AIS11_t tmp_soht_ais11;
        tmp_soht_ais11.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS11));
        if (state == 1) {
          tmp_soht_ais11.wrd |= (0x0001 << (sts-166));
        }
        else {
          tmp_soht_ais11.wrd &= ~(0x0001 << (sts-166));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS11), tmp_soht_ais11.wrd);
      }
      else if (sts > 180) {
        TEN_N10G_SOHT_AIS12_t tmp_soht_ais12;
        tmp_soht_ais12.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS12));
        if (state == 1) {
          tmp_soht_ais12.wrd |= (0x0001 << (sts-181));
        }
        else {
          tmp_soht_ais12.wrd &= ~(0x0001 << (sts-181));
        }
        TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, AIS12), tmp_soht_ais12.wrd);
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}
