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
 * ten_pp10g.c
 *
 * $Id: ten_pp10g_pcs.c,v 1.5 2013/02/22 20:48:04 jccarlis Exp $
 *
 * API's for PP10G PCS
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS TX SRESET                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_tx_sreset(cs_uint16 module_id, cs_uint8 slice, 
                              cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a logic reset of PCS RX.                                */
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
  TEN_PP10G_PCS_TX_TXCNTRL_t tmp_pcs_tx_txcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
        tmp_pcs_tx_txcntrl.wrd = 0;
        tmp_pcs_tx_txcntrl.bf.logicReset = 1; /* set mask bit */
        ten_reset_action(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, TXCNTRL), 
                         tmp_pcs_tx_txcntrl.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS RX SRESET                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_rx_sreset(cs_uint16 module_id, cs_uint8 slice, 
                              cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a logic reset of PCS RX.                                */
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
  TEN_PP10G_PCS_RX_RXCNTRL_t tmp_pcs_rx_rxcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
        tmp_pcs_rx_rxcntrl.wrd = 0;
        tmp_pcs_rx_rxcntrl.bf.logicReset = 1; /* set mask bit */
        ten_reset_action(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, RXCNTRL), 
                         tmp_pcs_rx_rxcntrl.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS TX LOOPBACK                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_tx_loopback(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 tx_estore_resync, 
                               cs_uint16 tx_loopback, 
                               cs_uint16 tx_loopback_data_en) 
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Tx Estore Resync                                  */
/*              o Tx Loopback                                       */
/*              o Tx Loopback Data En                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls PCS TX loopback.                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tx_estore_resync]                                             */
/*     Set this configuration bit to cause a re-synchronization of  */
/*     the elastic store looping data from the Tx direction back    */
/*     to the Rx direction.                                         */
/*                                                                  */
/*   [tx_loopback]                                                  */
/*     Set this configuration bit to loop the Tx XGMII formatted    */
/*     data back to the Rx direction.                               */
/*                                                                  */
/*   [tx_loopback_data_en]                                          */
/*     When set, tx_loopback data is sent through the TX PCS as     */
/*     well being looped back to the Rx direction.                  */
/*     This bit is only effective when tx_loopback is set.          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_TX_TXCNTRL_t tmp_pcs_tx_txcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_tx_txcntrl.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, TXCNTRL));
      tmp_pcs_tx_txcntrl.bf.tx_estore_resync = tx_estore_resync;
      tmp_pcs_tx_txcntrl.bf.tx_loopback = tx_loopback;
      tmp_pcs_tx_txcntrl.bf.tx_loopback_data_en = tx_loopback_data_en;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, TXCNTRL), tmp_pcs_tx_txcntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS TX CONTROL                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_tx_control(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 square_tx_pat, 
                               cs_uint16 pseudo_tx_inv, 
                               cs_uint16 pcs6_tx_test, 
                               cs_uint16 test_tx_err, 
                               cs_uint16 scram_tx_dis, 
                               cs_uint16 txcode_control)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Square Tx Pat                                     */
/*              o Pseudo Tx Inv                                     */
/*              o Pcs6 Tx Test                                      */
/*              o Test Tx Err                                       */
/*              o Scram Tx Dis                                      */
/*              o Txcode Control                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the transmit direction of the PCS.   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [square_tx_pat]  Square wave test pattern configuration.       */
/*     These patterns appear on the serial output.                  */
/*                                                                  */
/*   [pseudo_tx_inv]  Pseudorandom test pattern transmits inverted  */
/*     data with inverted seed.                                     */
/*                                                                  */
/*   [pcs6_tx_test]  Transmit test pattern mode control.            */
/*                                                                  */
/*   [test_tx_err]  Inject transmit error in test pattern modes.    */
/*                                                                  */
/*   [scram_tx_dis]  Set this configuration bit to disable the      */
/*     transmit scrambler.                                          */
/*                                                                  */
/*   [txcode_control]  Transmit code control.                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_TX_TXCNTRL_t tmp_pcs_tx_txcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_tx_txcntrl.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, TXCNTRL));
      tmp_pcs_tx_txcntrl.bf.square_tx_pat = square_tx_pat;
      tmp_pcs_tx_txcntrl.bf.pseudo_tx_inv = pseudo_tx_inv;
      tmp_pcs_tx_txcntrl.bf.pcs6_tx_test = pcs6_tx_test;
      tmp_pcs_tx_txcntrl.bf.test_tx_err = test_tx_err;
      tmp_pcs_tx_txcntrl.bf.scram_tx_dis = scram_tx_dis;
      tmp_pcs_tx_txcntrl.bf.txcode_control = txcode_control;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, TXCNTRL), tmp_pcs_tx_txcntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS TX PROFILE                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_tx_profile(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_uint16 txprofile)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Txprofile                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Designates the supported profile for transmit traffic.           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [txprofile]                                                    */
/*     0 = Standard Supports standard XGMII to 10GBASE-R            */
/*         transcoding.                                             */
/*     1 = Transparent Transparently carries 10GBASE-R content that */
/*         does not transcode to XGMII.  10GBASE-R content that can */
/*         be transcoded to XGMII is transcoded.  That which cannot */
/*         be transcoded to XGMII is carried in a bit transparent   */
/*         fashion.                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_TX_TXCNTRL1_t tmp_pcs_tx_txcntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_tx_txcntrl1.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, TXCNTRL1));
      tmp_pcs_tx_txcntrl1.bf.txprofile = txprofile;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, TXCNTRL1), tmp_pcs_tx_txcntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS TX SEED A                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_tx_seed_a(cs_uint16 module_id, 
                                  cs_uint8 slice, 
                                  cs_uint16 pseudo_tx_a3,
                                  cs_uint16 pseudo_tx_a2,
                                  cs_uint16 pseudo_tx_a1,
                                  cs_uint16 pseudo_tx_a0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pseudo Tx A3                                      */
/*              o Pseudo Tx A2                                      */
/*              o Pseudo Tx A1                                      */
/*              o Pseudo Tx A0                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the transmit pseudo random pattern seed A.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pseudo_tx_a3] most significant bits                           */
/*                                                                  */
/*   [pseudo_tx_a2] second most significant bits                    */
/*                                                                  */
/*   [pseudo_tx_a1] third most significant bits                     */
/*                                                                  */
/*   [pseudo_tx_a0] least significant bits.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_TX_SEED_A_3_t tmp_pcs_tx_seed_a_3;
  TEN_PP10G_PCS_TX_SEED_A_2_t tmp_pcs_tx_seed_a_2;
  TEN_PP10G_PCS_TX_SEED_A_1_t tmp_pcs_tx_seed_a_1;
  TEN_PP10G_PCS_TX_SEED_A_0_t tmp_pcs_tx_seed_a_0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_tx_seed_a_3.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_A_3));
      tmp_pcs_tx_seed_a_3.bf.pseudo_tx_A3 = pseudo_tx_a3;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_A_3), tmp_pcs_tx_seed_a_3.wrd);
      
      tmp_pcs_tx_seed_a_2.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_A_2));
      tmp_pcs_tx_seed_a_2.bf.pseudo_tx_A2 = pseudo_tx_a2;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_A_2), tmp_pcs_tx_seed_a_2.wrd);
      
      tmp_pcs_tx_seed_a_1.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_A_1));
      tmp_pcs_tx_seed_a_1.bf.pseudo_tx_A1 = pseudo_tx_a1;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_A_1), tmp_pcs_tx_seed_a_1.wrd);
      
      tmp_pcs_tx_seed_a_0.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_A_0));
      tmp_pcs_tx_seed_a_0.bf.pseudo_tx_A0 = pseudo_tx_a0;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_A_0), tmp_pcs_tx_seed_a_0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS TX SEED B                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_tx_seed_b(cs_uint16 module_id, 
                                  cs_uint8 slice, 
                                  cs_uint16 pseudo_tx_b3,
                                  cs_uint16 pseudo_tx_b2,
                                  cs_uint16 pseudo_tx_b1,
                                  cs_uint16 pseudo_tx_b0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pseudo Tx B3                                      */
/*              o Pseudo Tx B2                                      */
/*              o Pseudo Tx B1                                      */
/*              o Pseudo Tx B0                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the transmit pseudo random pattern seed B.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pseudo_tx_b3] most significant bits                           */
/*                                                                  */
/*   [pseudo_tx_b2] second most significant bits                    */
/*                                                                  */
/*   [pseudo_tx_b1] third most significant bits                     */
/*                                                                  */
/*   [pseudo_tx_b0] least significant bits.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_TX_SEED_B_3_t tmp_pcs_tx_seed_b_3;
  TEN_PP10G_PCS_TX_SEED_B_2_t tmp_pcs_tx_seed_b_2;
  TEN_PP10G_PCS_TX_SEED_B_1_t tmp_pcs_tx_seed_b_1;
  TEN_PP10G_PCS_TX_SEED_B_0_t tmp_pcs_tx_seed_b_0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_tx_seed_b_3.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_B_3));
      tmp_pcs_tx_seed_b_3.bf.pseudo_tx_B3 = pseudo_tx_b3;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_B_3), tmp_pcs_tx_seed_b_3.wrd);
      
      tmp_pcs_tx_seed_b_2.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_B_2));
      tmp_pcs_tx_seed_b_2.bf.pseudo_tx_B2 = pseudo_tx_b2;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_B_2), tmp_pcs_tx_seed_b_2.wrd);
      
      tmp_pcs_tx_seed_b_1.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_B_1));
      tmp_pcs_tx_seed_b_1.bf.pseudo_tx_B1 = pseudo_tx_b1;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_B_1), tmp_pcs_tx_seed_b_1.wrd);
      
      tmp_pcs_tx_seed_b_0.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_B_0));
      tmp_pcs_tx_seed_b_0.bf.pseudo_tx_B0 = pseudo_tx_b0;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_B_0), tmp_pcs_tx_seed_b_0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS TX SEED D                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_tx_seed_d(cs_uint16 module_id, 
                                  cs_uint8 slice, 
                                  cs_uint16 pseudo_tx_d3,
                                  cs_uint16 pseudo_tx_d2,
                                  cs_uint16 pseudo_tx_d1,
                                  cs_uint16 pseudo_tx_d0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pseudo Tx D3                                      */
/*              o Pseudo Tx D2                                      */
/*              o Pseudo Tx D1                                      */
/*              o Pseudo Tx D0                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the transmit pseudo random pattern seed D.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pseudo_tx_d3] most significant bits                           */
/*                                                                  */
/*   [pseudo_tx_d2] second most significant bits                    */
/*                                                                  */
/*   [pseudo_tx_d1] third most significant bits                     */
/*                                                                  */
/*   [pseudo_tx_d0] least significant bits.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_TX_SEED_D_3_t tmp_pcs_tx_seed_d_3;
  TEN_PP10G_PCS_TX_SEED_D_2_t tmp_pcs_tx_seed_d_2;
  TEN_PP10G_PCS_TX_SEED_D_1_t tmp_pcs_tx_seed_d_1;
  TEN_PP10G_PCS_TX_SEED_D_0_t tmp_pcs_tx_seed_d_0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_tx_seed_d_3.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_D_3));
      tmp_pcs_tx_seed_d_3.bf.pseudo_tx_D3 = pseudo_tx_d3;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_D_3), tmp_pcs_tx_seed_d_3.wrd);
      
      tmp_pcs_tx_seed_d_2.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_D_2));
      tmp_pcs_tx_seed_d_2.bf.pseudo_tx_D2 = pseudo_tx_d2;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_D_2), tmp_pcs_tx_seed_d_2.wrd);
      
      tmp_pcs_tx_seed_d_1.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_D_1));
      tmp_pcs_tx_seed_d_1.bf.pseudo_tx_D1 = pseudo_tx_d1;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_D_1), tmp_pcs_tx_seed_d_1.wrd);
      
      tmp_pcs_tx_seed_d_0.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_D_0));
      tmp_pcs_tx_seed_d_0.bf.pseudo_tx_D0 = pseudo_tx_d0;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, tx_SEED_D_0), tmp_pcs_tx_seed_d_0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS RX LOOPBACK                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_rx_loopback(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 rx_estore_resync, 
                               cs_uint16 rx_loopback)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rx Estore Resync                                  */
/*              o Rx Loopback                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls PCS RX loopback.                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rx_estore_resync]  Set this configuration bit to causes a     */
/*     re-synchronization of the elastic store used to loop data    */
/*     from the Rx direction back to the Tx direction.              */
/*                                                                  */
/*   [rx_loopback]  Set this configuration bit to loop Rx XGMII     */
/*     formatted data back to the Tx direction.                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_RX_RXCNTRL_t tmp_pcs_rx_rxcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_rx_rxcntrl.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, RXCNTRL));
      tmp_pcs_rx_rxcntrl.bf.rx_estore_resync = rx_estore_resync;
      tmp_pcs_rx_rxcntrl.bf.rx_loopback = rx_loopback;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, RXCNTRL), tmp_pcs_rx_rxcntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS RX CONTROL                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_rx_control(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 dontfilterfsig, 
                               cs_uint16 latcheach1e, 
                               cs_uint16 pseudo_rx_inv, 
                               cs_uint16 pcs6_rx_test, 
                               cs_uint16 pcs6_ddsa_enable, 
                               cs_uint16 rxprofile, 
                               cs_uint16 descram_rx_dis)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DontFilterFsig                                    */
/*              o LatchEach1e                                       */
/*              o Pseudo Rx Inv                                     */
/*              o Pcs6 Rx Test                                      */
/*              o Pcs6 Ddsa Enable                                  */
/*              o Rxprofile                                         */
/*              o Descram Rx Dis                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the receive direction of the PCS.    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dontfilterfsig]  Set this configuration bit to latch the      */
/*     /Fsig/ and Reserved0-5 codes received by the RCS 64/66       */
/*     Decoder to the XGMII bus.                                    */
/*                                                                  */
/*   [latcheach1e]    Set this configuration bit to cause the       */
/*     latching of individual 1E codes to the XGMII bus rather than */
/*     the entire XGMII transfer for block types 0x2d, 0x4b, 0x33,  */
/*     0x87, 0x99, 0xaa, 0xb4, 0xcc, 0xd2 and 0xe1.                 */
/*                                                                  */
/*   [pseudo_rx_inv]  Set this configuration bit to receive a       */
/*     pseudorandom test pattern of inverted data with inverted     */
/*     seed.                                                        */
/*                                                                  */
/*   [pcs6_rx_test]  Receive test pattern mode control.             */
/*                                                                  */
/*   [pcs6_ddsa_enable]  PCS6 data detect enable for                */
/*     synchronization algorithm                                    */
/*                                                                  */
/*   [rxprofile]   Designate the supported profile for received     */
/*     traffic.                                                     */
/*                                                                  */
/*   [descram_rx_dis]  Set this configuration bit to disable the    */
/*     receive descrambler.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_RX_RXCNTRL_t tmp_pcs_rx_rxcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_rx_rxcntrl.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, RXCNTRL));
      tmp_pcs_rx_rxcntrl.bf.dontFilterFsig = dontfilterfsig;
      tmp_pcs_rx_rxcntrl.bf.latchEach1e = latcheach1e;
      tmp_pcs_rx_rxcntrl.bf.pseudo_rx_inv = pseudo_rx_inv;
      tmp_pcs_rx_rxcntrl.bf.pcs6_rx_test = pcs6_rx_test;
      tmp_pcs_rx_rxcntrl.bf.pcs6_ddsa_enable = pcs6_ddsa_enable;
      tmp_pcs_rx_rxcntrl.bf.rxprofile = rxprofile;
      tmp_pcs_rx_rxcntrl.bf.descram_rx_dis = descram_rx_dis;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, RXCNTRL), tmp_pcs_rx_rxcntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS RX CONTROL TRANSPARENCY                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_rx_control_transparency(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 pass_invalid_blocks, 
                                cs_uint16 pass_singles)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pass Invalid Blocks                               */
/*              o Pass Singles                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the PCS concerning 10GBASE-R block           */
/* and bit transparency.  The configuration options address         */
/* the lack of standard definitions for transparency.               */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pass_invalid_blocks]  Pass invalid 10GBASE-R blocks in a bit  */
/*     transparent manner when set.                                 */
/*                                                                  */
/*   [pass_singles]  Pass single bit fields in 10GBASE-R control    */
/*     blocks when set.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_RX_RXTCNTRL_t tmp_pcs_rx_rxtcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_rx_rxtcntrl.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, RXTCNTRL));
      tmp_pcs_rx_rxtcntrl.bf.pass_invalid_blocks = pass_invalid_blocks;
      tmp_pcs_rx_rxtcntrl.bf.pass_singles = pass_singles;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, RXTCNTRL), tmp_pcs_rx_rxtcntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS RX STATUS                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_pcs_rx_status(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Selection                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns PCS receive status.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/*   [select]  TEN_PP10G_PCS_RX_PATSYNCS (0),                       */
/*             TEN_PP10G_PCS_RX_BERHIGHS (1),                       */
/*             TEN_PP10G_PCS_RX_SYNCDETS (2),                       */
/*             TEN_PP10G_PCS_RX_ALL (0xFF), (whole reg).            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_PCS_RX_RXSTATUS_t tmp_pcs_rx_rxstatus;
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_pcs_rx_rxstatus.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, slice, RXSTATUS));

  switch (select)
  {
  case (TEN_PP10G_PCS_RX_PATSYNCS):
    rtn = tmp_pcs_rx_rxstatus.bf.patsyncS;
    break;
    
  case (TEN_PP10G_PCS_RX_BERHIGHS):
    rtn = tmp_pcs_rx_rxstatus.bf.berhighS;
    break;
    
  case (TEN_PP10G_PCS_RX_SYNCDETS):
    rtn = tmp_pcs_rx_rxstatus.bf.syncdetS;
    break;
    
  case (TEN_PP10G_PCS_RX_ALL):
    rtn = tmp_pcs_rx_rxstatus.wrd;
    break;
    
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS RX SEED A                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_rx_seed_a(cs_uint16 module_id, 
                                  cs_uint8 slice, 
                                  cs_uint16 pseudo_rx_a3,
                                  cs_uint16 pseudo_rx_a2,
                                  cs_uint16 pseudo_rx_a1,
                                  cs_uint16 pseudo_rx_a0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pseudo Rx A3                                      */
/*              o Pseudo Rx A2                                      */
/*              o Pseudo Rx A1                                      */
/*              o Pseudo Rx A0                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the transmit pseudo random pattern seed A.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pseudo_rx_a3] most significant bits                           */
/*                                                                  */
/*   [pseudo_rx_a2] second most significant bits                    */
/*                                                                  */
/*   [pseudo_rx_a1] third most significant bits                     */
/*                                                                  */
/*   [pseudo_rx_a0] least significant bits.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_RX_SEED_A_3_t tmp_pcs_rx_seed_a_3;
  TEN_PP10G_PCS_RX_SEED_A_2_t tmp_pcs_rx_seed_a_2;
  TEN_PP10G_PCS_RX_SEED_A_1_t tmp_pcs_rx_seed_a_1;
  TEN_PP10G_PCS_RX_SEED_A_0_t tmp_pcs_rx_seed_a_0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_rx_seed_a_3.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_A_3));
      tmp_pcs_rx_seed_a_3.bf.pseudo_rx_A3 = pseudo_rx_a3;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_A_3), tmp_pcs_rx_seed_a_3.wrd);
      
      tmp_pcs_rx_seed_a_2.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_A_2));
      tmp_pcs_rx_seed_a_2.bf.pseudo_rx_A2 = pseudo_rx_a2;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_A_2), tmp_pcs_rx_seed_a_2.wrd);
      
      tmp_pcs_rx_seed_a_1.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_A_1));
      tmp_pcs_rx_seed_a_1.bf.pseudo_rx_A1 = pseudo_rx_a1;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_A_1), tmp_pcs_rx_seed_a_1.wrd);
      
      tmp_pcs_rx_seed_a_0.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_A_0));
      tmp_pcs_rx_seed_a_0.bf.pseudo_rx_A0 = pseudo_rx_a0;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_A_0), tmp_pcs_rx_seed_a_0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS RX SEED B                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_rx_seed_b(cs_uint16 module_id, 
                                  cs_uint8 slice, 
                                  cs_uint16 pseudo_rx_b3,
                                  cs_uint16 pseudo_rx_b2,
                                  cs_uint16 pseudo_rx_b1,
                                  cs_uint16 pseudo_rx_b0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pseudo Rx B3                                      */
/*              o Pseudo Rx B2                                      */
/*              o Pseudo Rx B1                                      */
/*              o Pseudo Rx B0                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the transmit pseudo random pattern seed B.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pseudo_rx_b3] most significant bits                           */
/*                                                                  */
/*   [pseudo_rx_b2] second most significant bits                    */
/*                                                                  */
/*   [pseudo_rx_b1] third most significant bits                     */
/*                                                                  */
/*   [pseudo_rx_b0] least significant bits.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_RX_SEED_B_3_t tmp_pcs_rx_seed_b_3;
  TEN_PP10G_PCS_RX_SEED_B_2_t tmp_pcs_rx_seed_b_2;
  TEN_PP10G_PCS_RX_SEED_B_1_t tmp_pcs_rx_seed_b_1;
  TEN_PP10G_PCS_RX_SEED_B_0_t tmp_pcs_rx_seed_b_0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_rx_seed_b_3.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_B_3));
      tmp_pcs_rx_seed_b_3.bf.pseudo_rx_B3 = pseudo_rx_b3;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_B_3), tmp_pcs_rx_seed_b_3.wrd);
      
      tmp_pcs_rx_seed_b_2.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_B_2));
      tmp_pcs_rx_seed_b_2.bf.pseudo_rx_B2 = pseudo_rx_b2;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_B_2), tmp_pcs_rx_seed_b_2.wrd);
      
      tmp_pcs_rx_seed_b_1.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_B_1));
      tmp_pcs_rx_seed_b_1.bf.pseudo_rx_B1 = pseudo_rx_b1;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_B_1), tmp_pcs_rx_seed_b_1.wrd);
      
      tmp_pcs_rx_seed_b_0.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_B_0));
      tmp_pcs_rx_seed_b_0.bf.pseudo_rx_B0 = pseudo_rx_b0;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_B_0), tmp_pcs_rx_seed_b_0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS RX SEED D                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_rx_seed_d(cs_uint16 module_id, 
                                  cs_uint8 slice, 
                                  cs_uint16 pseudo_rx_d3,
                                  cs_uint16 pseudo_rx_d2,
                                  cs_uint16 pseudo_rx_d1,
                                  cs_uint16 pseudo_rx_d0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pseudo Rx D3                                      */
/*              o Pseudo Rx D2                                      */
/*              o Pseudo Rx D1                                      */
/*              o Pseudo Rx D0                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the transmit pseudo random pattern seed D.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pseudo_rx_d3] most significant bits                           */
/*                                                                  */
/*   [pseudo_rx_d2] second most significant bits                    */
/*                                                                  */
/*   [pseudo_rx_d1] third most significant bits                     */
/*                                                                  */
/*   [pseudo_rx_d0] least significant bits.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_RX_SEED_D_3_t tmp_pcs_rx_seed_d_3;
  TEN_PP10G_PCS_RX_SEED_D_2_t tmp_pcs_rx_seed_d_2;
  TEN_PP10G_PCS_RX_SEED_D_1_t tmp_pcs_rx_seed_d_1;
  TEN_PP10G_PCS_RX_SEED_D_0_t tmp_pcs_rx_seed_d_0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_rx_seed_d_3.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_D_3));
      tmp_pcs_rx_seed_d_3.bf.pseudo_rx_D3 = pseudo_rx_d3;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_D_3), tmp_pcs_rx_seed_d_3.wrd);
      
      tmp_pcs_rx_seed_d_2.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_D_2));
      tmp_pcs_rx_seed_d_2.bf.pseudo_rx_D2 = pseudo_rx_d2;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_D_2), tmp_pcs_rx_seed_d_2.wrd);
      
      tmp_pcs_rx_seed_d_1.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_D_1));
      tmp_pcs_rx_seed_d_1.bf.pseudo_rx_D1 = pseudo_rx_d1;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_D_1), tmp_pcs_rx_seed_d_1.wrd);
      
      tmp_pcs_rx_seed_d_0.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_D_0));
      tmp_pcs_rx_seed_d_0.bf.pseudo_rx_D0 = pseudo_rx_d0;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, rx_SEED_D_0), tmp_pcs_rx_seed_d_0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G PCS RX CONTROL RXPROFILE                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_pcs_rx_control_rxprofile(cs_uint16 module_id,
                                             cs_uint8 slice,  
                                             cs_uint16 rxprofile)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rxprofile                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls various aspects of the receive direction of the PCS.    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rxprofile]   Designate the supported profile for received     */
/*     traffic.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_RX_RXCNTRL_t tmp_pcs_rx_rxcntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_rx_rxcntrl.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, RXCNTRL));
      tmp_pcs_rx_rxcntrl.bf.rxprofile = rxprofile;
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, RXCNTRL), tmp_pcs_rx_rxcntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET PCS RX BER TIMER REGISTER              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_set_pcs_rx_ber_timer(cs_uint16 module_id,
                                         cs_uint8 slice, 
                                         cs_uint16 value)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Receive PCS BER time interval.  Value is the final system PLL    */
/* clock (in Mhz) multiplied by 125.                                */
/*                                                                  */
/* NOTE:  The BER timer runs off of the system PLL clock, not the   */
/* SYS_REFCLK_IN clock.  For example, when SYS_REFCLK_IN is in the  */
/* 100MHz range, there is a 4x system PLL multiplication.  The      */
/* value provided to this API needs to use this final system        */
/* PLL clock (in Mhz) multiplied by 125.                            */
/* For backwards compatibility, any value of less than (200 * 125)  */
/* is automatically multiplied by 4.                                */
/*                                                                  */
/* Example Values:                                                  */
/* SYS_REFCLK_IN = 100Mhz, value = 100 * 4 * 125                    */
/* SYS_REFCLK_IN = 400Mhz, value = 400 * 125                        */
/* SYS_REFCLK_IN = 425Mhz, value = 425 * 125                        */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [value] parameter is specified as:                           */
/*   0x0000..0xFFFF: BER time interval base specified in clksys     */
/*   cycles. When set to '0' the interval is infinite.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_RX_BER_TIMER_t tmp_pcs_rx_ber_timer;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_rx_ber_timer.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, BER_TIMER));
      /* Bugzilla #18243 */
      /* multiply by 4 for the external clock range 77.76-106.25 MHz */
      if ((value/125) <= 200) {
        tmp_pcs_rx_ber_timer.bf.value = value * 4;
      }
      else {
          tmp_pcs_rx_ber_timer.bf.value = value;
      }
      TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, BER_TIMER), tmp_pcs_rx_ber_timer.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET PCS RX SYNOFF REGISTER                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_set_pcs_rx_synoff(cs_uint16 module_id,
                                      cs_uint8 slice, 
                                      cs_uint16 select, 
                                      cs_uint16 value)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Receive synchronization offsets register.                        */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [select] parameter is specified as:                          */
/*   TEN_PP10G_PCS_RX_SYNOFF_SYNC_BER     = 0                       */
/*   TEN_PP10G_PCS_RX_SYNOFF_SYNC_INVALID = 1                       */
/*   TEN_PP10G_PCS_RX_SYNOFF_SYNC_VALID   = 2                       */
/*                                                                  */
/* The [value] parameter is specified as:                           */
/*   For select = TEN_PP10G_PCS_RX_SYNOFF_SYNC_BER                  */
/*     0x0..0xF: Synchronization Bir Error Rate Count Offset        */
/*                                                                  */
/*   For select = TEN_PP10G_PCS_RX_SYNOFF_SYNC_INVALID              */
/*     0x0..0xF: Synchronization Invalid Count Offset               */
/*                                                                  */
/*   For select = TEN_PP10G_PCS_RX_SYNOFF_SYNC_VALID                */
/*     0x0..0xF: Synchronization Valid Count Offset                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_PCS_RX_SYNOFF_t tmp_pcs_rx_synoff;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    rtn = CS_ERROR;
    goto RTN_EXIT;
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_pcs_rx_synoff.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, SYNOFF));
      switch (select) {
        case TEN_PP10G_PCS_RX_SYNOFF_SYNC_BER :
          {
            tmp_pcs_rx_synoff.bf.sync_ber_off = value;
            TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, SYNOFF), tmp_pcs_rx_synoff.wrd);
            break;
          }
        case TEN_PP10G_PCS_RX_SYNOFF_SYNC_INVALID :
          {
            tmp_pcs_rx_synoff.bf.sync_invalid_off = value;
            TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, SYNOFF), tmp_pcs_rx_synoff.wrd);
            break;
          }
        case TEN_PP10G_PCS_RX_SYNOFF_SYNC_VALID :
          {
            tmp_pcs_rx_synoff.bf.sync_valid_off = value;
            TEN_REG_WRITE(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, SYNOFF), tmp_pcs_rx_synoff.wrd);
            break;
          }
        default : 
          {
            CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, ": select out of range"); 
            rtn = CS_ERROR; 
          }
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

RTN_EXIT:
  return (rtn);
}



