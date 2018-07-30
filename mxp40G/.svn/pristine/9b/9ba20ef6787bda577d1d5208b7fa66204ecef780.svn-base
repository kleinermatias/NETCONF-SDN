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
 * ten_n10g_gbl.c
 *
 * N10G related code is implemented here.
 *
 * $Id: ten_n10g_gbl.c,v 1.6 2013/02/22 20:47:56 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N10G SET GLOBAL SOFT (LOGIC) RESETS          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_set_global_resets(cs_uint16 module_id,
                                     cs_uint8 slice, 
                                     cs_reset_action_t act,
                                     cs_uint16 bitfield)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Reset Action                                  */
/*              o Bitfield                                      */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a soft reset on the specified (masked on)           */
/* selections. The selections that are masked off will not be   */
/* affected.                                                    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   CS_RESET_DEASSERT                                          */
/*   CS_RESET_ASSERT                                            */
/*   CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* The [bitfield] parameter is specified as:                    */
/*   TEN_N10G_GLOBAL_RESETS_RSTTX    = 0x0001,                  */
/*   TEN_N10G_GLOBAL_RESETS_RSTTXNG  = 0x0002,                  */
/*   TEN_N10G_GLOBAL_RESETS_RSTOT    = 0x0004,                  */
/*   TEN_N10G_GLOBAL_RESETS_RSTCT    = 0x0008,                  */
/*   TEN_N10G_GLOBAL_RESETS_RSTRX    = 0x0010,                  */
/*   TEN_N10G_GLOBAL_RESETS_RSTOR    = 0x0020,                  */
/*   TEN_N10G_GLOBAL_RESETS_RSTCR    = 0x0040,                  */
/*   TEN_N10G_GLOBAL_RESETS_RSTSYS   = 0x0100,                  */
/*   TEN_N10G_GLOBAL_RESETS_ALL      = 0x017F                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBL_CFG_t tmp_gbl_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": act = 0x%04X\n", act);
      return (CS_ERROR);
  }
  if (bitfield > TEN_N10G_GLOBAL_RESETS_ALL) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, ": bitfield = 0x%04X\n", bitfield);
      return (CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G); 
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gbl_cfg.wrd = bitfield;
      ten_reset_action(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG), tmp_gbl_cfg.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_BYPASS_10G_40G_TRAFFIC                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_gbl_bypcfg_rx_bypass_10g(cs_uint16 module_id,
                                            cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Traffic from 40G processor ( both the bypass bus and TDMR)               */
/*   This config allows PP40G non-intrusive monitoring                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS10G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}

