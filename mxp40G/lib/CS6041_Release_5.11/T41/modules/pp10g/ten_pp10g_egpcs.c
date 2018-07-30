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
 * ten_pp10g_egpcs.c
 *
 * $Id: ten_pp10g_egpcs.c,v 1.8 2013/02/22 20:48:04 jccarlis Exp $
 *
 * API's for PP10G EGPCS
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  PP10G EGPCS RX RESET                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_egpcs_rx_reset(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a logic reset of EGPCS RX.                              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act]  Reset option specified as CS_RESET_DEASSERT,            */
/*     CS_RESET_ASSERT or CS_RESET_TOGGLE.                          */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset bit(s) for 20 milliseconds and then de-assert.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_EGPCS_RX_MODE_t tmp_egpcs_rx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_egpcs_rx_mode.wrd = 0;
      tmp_egpcs_rx_mode.bf.rxrst = 1;
      ten_reset_action(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, rx_MODE), 
                       tmp_egpcs_rx_mode.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G EGPCS RX SET MODE                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_egpcs_rx_set_mode(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 align_char)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Align Char                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets EGPCS Rx Mode.                                              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [align_char]  Determines what pattern to search for when       */
/*     establishing 10bit code group boundaries.                    */
/*     When set, search for K28.5. When clear, search for comma.    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_EGPCS_RX_MODE_t tmp_egpcs_rx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_egpcs_rx_mode.wrd = TEN_REG_READ(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, rx_MODE));
      tmp_egpcs_rx_mode.bf.align_char = align_char;
      TEN_REG_WRITE(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, rx_MODE), tmp_egpcs_rx_mode.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G EGPCS RX DESRAMBLER ENABLE                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_egpcs_rx_dscr_en(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 dscr_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Dscr En                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Determines whether the frame descrambler is ON or OFF.           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dscr_en]  0: off, 1: on.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_EGPCS_RX_MODE_t tmp_egpcs_rx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_egpcs_rx_mode.wrd = TEN_REG_READ(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, rx_MODE));
      tmp_egpcs_rx_mode.bf.dscr_en = dscr_en;
      TEN_REG_WRITE(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, rx_MODE), tmp_egpcs_rx_mode.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/* Bugzilla #35713 Start */
/********************************************************************/
/* $rtn_hdr_start  PP10G EGPCS TX SRAMBLER ENABLE                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_egpcs_tx_scr_en(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 scr_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Scr En                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Determines whether the frame scrambler is ON or OFF.             */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [scr_en]  0: off, 1: on.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_EGPCS_TX_MODE_t tmp_egpcs_tx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_egpcs_tx_mode.wrd = TEN_REG_READ(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, tx_MODE));
      tmp_egpcs_tx_mode.bf.scr_en = scr_en;
      TEN_REG_WRITE(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, tx_MODE), tmp_egpcs_tx_mode.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}
/* Bugzilla #35713 End */

/********************************************************************/
/* $rtn_hdr_start  PP10G EGPCS RX SYNC STATUS                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_boolean ten_pp10g_egpcs_rx_intstatus(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE or FALSE                                       */
/* DESCRIPTION:                                                     */
/* When asserted, the FC-1 Receiver Synchronization state machine   */
/* is in one of the 'Word Synchronization Acquired' states.         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_EGPCS_RX_INTSTATUS_t tmp_egpcs_rx_intstatus;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  tmp_egpcs_rx_intstatus.wrd = TEN_REG_READ(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, slice, INTSTATUS));
  return (tmp_egpcs_rx_intstatus.bf.syncS == 1);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G EGPCS TX RESET                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_egpcs_tx_reset(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a logic reset of EGPCS TX.                              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act]  Reset option specified as CS_RESET_DEASSERT,            */
/*     CS_RESET_ASSERT or CS_RESET_TOGGLE.                          */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset bit(s) for 20 milliseconds and then de-assert.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_EGPCS_TX_MODE_t tmp_egpcs_tx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_egpcs_tx_mode.wrd = 0;
      tmp_egpcs_tx_mode.bf.txrst = 1;
      ten_reset_action(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, tx_MODE), 
                       tmp_egpcs_tx_mode.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G EGPCS TX SET MODE                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_egpcs_tx_set_mode(cs_uint16 module_id, cs_uint8 slice,
                              cs_uint16 ins_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Ins Mode                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This controls the usage of the INSPATTERN0-3 registers.          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ins_mode]  Controls the usage of the INSPATTERN0-3 registers. */
/*     Either the contents of those registers are inserted before   */
/*     or after the 10b encoder.                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_EGPCS_TX_MODE_t tmp_egpcs_tx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_egpcs_tx_mode.wrd = TEN_REG_READ(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, tx_MODE));
      tmp_egpcs_tx_mode.bf.ins_mode = ins_mode;
      TEN_REG_WRITE(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, tx_MODE), tmp_egpcs_tx_mode.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G EGPCS TX INSERT PATTERN                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_egpcs_tx_inspattern0(cs_uint16 module_id, cs_uint8 slice, 
                                         cs_uint16 pat0,
                                         cs_uint16 pat1,
                                         cs_uint16 pat2,
                                         cs_uint16 pat3)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pat0                                              */
/*              o Pat1                                              */
/*              o Pat2                                              */
/*              o Pat3                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Pattern Insertion Control Registers.                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pat0-3]  Depending on the MODE[ins_mode] setting, sets either */
/*     a special/data character or a Transmission Character.        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_EGPCS_TX_INSPATTERN0_t tmp_egpcs_tx_inspattern0;
  TEN_PP10G_EGPCS_TX_INSPATTERN1_t tmp_egpcs_tx_inspattern1;
  TEN_PP10G_EGPCS_TX_INSPATTERN2_t tmp_egpcs_tx_inspattern2;
  TEN_PP10G_EGPCS_TX_INSPATTERN3_t tmp_egpcs_tx_inspattern3;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_egpcs_tx_inspattern0.wrd = TEN_REG_READ(TEN_PP10G_EGPCS_REG_ADDR(pDev, 
                                     module_id, sl, INSPATTERN0));
      tmp_egpcs_tx_inspattern0.bf.pat0 = pat0;
      TEN_REG_WRITE(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, INSPATTERN0), 
                    tmp_egpcs_tx_inspattern0.wrd);
                    
      tmp_egpcs_tx_inspattern1.wrd = TEN_REG_READ(TEN_PP10G_EGPCS_REG_ADDR(pDev, 
                                     module_id, sl, INSPATTERN1));
      tmp_egpcs_tx_inspattern1.bf.pat1 = pat1;
      TEN_REG_WRITE(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, INSPATTERN1), 
                    tmp_egpcs_tx_inspattern1.wrd);                   
                    
      tmp_egpcs_tx_inspattern2.wrd = TEN_REG_READ(TEN_PP10G_EGPCS_REG_ADDR(pDev, 
                                     module_id, sl, INSPATTERN2));
      tmp_egpcs_tx_inspattern2.bf.pat2 = pat2;
      TEN_REG_WRITE(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, INSPATTERN2), 
                    tmp_egpcs_tx_inspattern2.wrd);             
                    
      tmp_egpcs_tx_inspattern3.wrd = TEN_REG_READ(TEN_PP10G_EGPCS_REG_ADDR(pDev, 
                                     module_id, sl, INSPATTERN3));
      tmp_egpcs_tx_inspattern3.bf.pat3 = pat3;
      TEN_REG_WRITE(TEN_PP10G_EGPCS_REG_ADDR(pDev, module_id, sl, INSPATTERN3), 
                    tmp_egpcs_tx_inspattern3.wrd);            
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}




