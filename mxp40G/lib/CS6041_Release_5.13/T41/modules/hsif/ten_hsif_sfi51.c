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
 * ten_hsif_sfi51.c
 *
 * HSIF SFI51 related code is implemented here.
 *
 * $Id: 
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  HSIF SFI5 GET RX DESKEW OFFSET0                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HSIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_hsif_sfi5_get_rx_deskew_offset0(cs_uint16 module_id, cs_uint8 instance)
/* INPUTS     : o Module Id                                         */
/*              o Instance                                          */
/*              o OFFSET                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Offset                                              */
/* DESCRIPTION:                                                     */
/* Returns read-only bits which reflect the raw status of the       */
/* deskew alignment offset being monitored.                         */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..15.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_HSIF_SFI5_RX_DESKEW_OFFSET0_t tmp_sfi5_rx_deskew_offset0;

  if (instance >= TEN_HSIF_SFI5_RX_DESKEW_OFFSET0_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..15.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_sfi5_rx_deskew_offset0.wrd = TEN_REG_READ(TEN_HSIF_SFI5_REG_ADDR(pDev, module_id, RX_DESKEW_OFFSET0) +
                                                instance * TEN_HSIF_SFI5_RX_DESKEW_OFFSET0_STRIDE);
  return (tmp_sfi5_rx_deskew_offset0.bf.OFFSET);
}



