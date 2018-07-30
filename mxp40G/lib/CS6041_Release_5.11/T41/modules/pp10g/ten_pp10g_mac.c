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
 * ten_pp10g_mac.c
 *
 * $Id: ten_pp10g_mac.c,v 1.8 2013/02/22 20:48:04 jccarlis Exp $
 *
 * API's for PP10G MAC
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC CONTROL SOFT (LOGIC) RX RESET          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_control_sreset(cs_uint16 module_id, cs_uint8 slice,
                                          cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control MAC RX logic reset.                                      */
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
  TEN_PP10G_MAC_RX_CFG_COM_t tmp_mac_rx_cfg_com;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_cfg_com.wrd = 0;
      tmp_mac_rx_cfg_com.bf.rx_rst = 1;
      ten_reset_action(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_CFG_COM), 
                        tmp_mac_rx_cfg_com.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC CONTROL SOFT (LOGIC) TX RESET          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_control_sreset(cs_uint16 module_id, cs_uint8 slice,
                                          cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control MAC TX logic reset.                                      */
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
  TEN_PP10G_MAC_TX_CFG_COM_t tmp_mac_tx_cfg_com;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_cfg_com.wrd = 0;
      tmp_mac_tx_cfg_com.bf.tx_rst = 1;
      ten_reset_action(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_CFG_COM), 
                        tmp_mac_tx_cfg_com.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC CONTROL LOOPBACK                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_ctl_loopback(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_dir_t dir,
                                 cs_ctl_t enbl)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Enable                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control (disable/enable) the loopback in PP10G MAC.              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dir] parameter is specified as:                               */
/*     CS_RX, CS_TX or CS_TX_AND_RX                                 */
/*     RX is core_tx2rx_lb, enable loopback from CORE Transmit      */
/*     SPI4.1 input to CORE Receive SPI4.1 output.  When enabled,   */
/*     the CORE Receive 'crc_err' output signal is tied low.        */
/*     TX is core_rx2tx_lb, enable loopback from CORE Receive       */
/*     SPI4.1 output to CORE Transmit SPI4.1 input.                 */
/*     Limits of this loopback are TBD.                             */
/*                                                                  */
/*   [enbl] parameter is specified as:                              */
/*     CS_ENABLE (1) or CS_DISABLE (0)                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_CFG_COM_t tmp_mac_tx_cfg_com;
  TEN_PP10G_MAC_RX_CFG_COM_t tmp_mac_rx_cfg_com;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
     
      if ((dir == CS_TX) || (dir == CS_RX_AND_TX)) {
        tmp_mac_tx_cfg_com.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_CFG_COM));
        tmp_mac_tx_cfg_com.bf.core_rx2tx_lb = enbl ? 1 : 0; 
        TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_CFG_COM), tmp_mac_tx_cfg_com.wrd);
      }
      /* Bugzilla #24882, this is for RX direction */
      if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
        tmp_mac_rx_cfg_com.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_CFG_COM));
        tmp_mac_rx_cfg_com.bf.core_tx2rx_lb = enbl ? 1 : 0;
        TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_CFG_COM), tmp_mac_rx_cfg_com.wrd);
      }

    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX SET PROFILE                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_set_profile(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 profile)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Profile                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures common XGMAC settings.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [profile]  Identify the signal profile employed by the data    */
/*     path through the receive PP10G.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_CFG_COM_t tmp_mac_rx_cfg_com;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_cfg_com.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_CFG_COM));
      tmp_mac_rx_cfg_com.bf.profile = profile;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_CFG_COM), tmp_mac_rx_cfg_com.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX SET PROFILE                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_set_profile(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 profile)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Profile                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures common XGMAC settings.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [profile]  Identifies the client signal profile employed by    */
/*     the data path through the transmit PP10G.                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_CFG_COM_t tmp_mac_tx_cfg_com;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_cfg_com.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_CFG_COM));
      tmp_mac_tx_cfg_com.bf.profile = profile;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_CFG_COM), tmp_mac_tx_cfg_com.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX SET STATS ERR ORDER                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_set_stats_err_order(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 stats_err_order)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Stats Err Order                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the statistics error order configuration.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [stats_err_order]  Statistics error order configuration.       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_CFG_COM_t tmp_mac_rx_cfg_com;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_cfg_com.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_CFG_COM));
      tmp_mac_rx_cfg_com.bf.stats_err_order = stats_err_order;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_CFG_COM), tmp_mac_rx_cfg_com.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX IFG MODE                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_ifg_mode(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 ifg_mode_rx)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o IFG Mode Rx                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Rx Inter Frame Gap mode.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ifg_mode_rx]                                                  */ 
/*     0 = STD Supports standard IEEE 802.3ae clause 4              */
/*         InterFrameGap of minimum 40 Bit Times.                   */
/*     1 = BEST Supports non-standard best effort                   */
/*         InterFrameGap of minimum 0 Bit Times.  Incoming data     */
/*         must comply with IEEE 802.3ae section 49 64B/66B         */
/*         encoding w.r.t. Start/Terminate characters.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_CFG_RX_t tmp_mac_rx_cfg_rx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_cfg_rx.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX));
      tmp_mac_rx_cfg_rx.bf.IFG_mode_rx = ifg_mode_rx ? 1 : 0;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX), tmp_mac_rx_cfg_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX IFG MODE                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_set_tx_ifg_mode(cs_uint16 module_id, cs_uint8 slice,
                              cs_uint16 ifg_mode_tx)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o IFG Mode Tx                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Tx Inter Frame Gap mode.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ifg_mode_tx]                                                  */
/*      0 = STD Mode:  Insert Idle.                                 */
/*          Use pp10g_mac_tx_cfg_tx_ifg to set minimum IFG.         */
/*          Will insert 1, 2 or 3 idles to align.                   */
/*      1 = DIC Mode:  Deficit Idle Counter.                        */
/*          Minimum IFG=9. IFG oscillates between 9-15 during       */
/*          back-to-back traffic with the average being IFG=12.     */
/*      2 = DIC Mode: Deficit Idle Counter.                         */
/*          Minimum IFG=5. IFG oscillates between 5-11 during       */
/*          back-to-back traffic with the average being IFG=8.      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_CFG_TX_t tmp_mac_tx_cfg_tx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_cfg_tx.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_TX));
      tmp_mac_tx_cfg_tx.bf.IFG_mode_tx = ifg_mode_tx;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_TX), tmp_mac_tx_cfg_tx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PROGRAMMABLE IFG                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_cfg_programmable_ifg(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 ifg)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Ifg                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Programmable Inter Frame Gap.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ifg]  Programmable Inter Frame Gap.                           */
/*     Ignored unless TX IFG_mode_tx is STD.                        */
/*     Legal values are 5 and above.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  /* Bugzilla #19353, fix bus errors */
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_CFG_TX_IFG_t tmp_mac_tx_cfg_tx_ifg;
  TEN_PP10G_MISC_FUNCEN_TX_t tmp_funcen_tx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_funcen_tx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, FUNCEN_TX));
      if (tmp_funcen_tx.bf.tx_fen_mac) {
        tmp_mac_tx_cfg_tx_ifg.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_TX_IFG));
        tmp_mac_tx_cfg_tx_ifg.bf.ifg = ifg;
        TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_TX_IFG), tmp_mac_tx_cfg_tx_ifg.wrd);
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX DROP SHORT CONTROL                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_ctl_drop_short(cs_uint16 module_id, cs_uint8 slice,
                              cs_ctl_t drop_short)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Drop Short                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control (enable/disable) short frame drop.                       */
/* In Ethernet mode, short frames are less than 64 bytes long.      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [drop_short]  Short frame drop enable for frames with          */
/*     recognized Destination Address.  Frames are classified as    */
/*     being 'short' if the received frame length is shorter than   */
/*     the value programmed in the MINLEN register.                 */
/*     Specified as CS_ENABLE (1) or CS_DISABLE (0).                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_CFG_RX_t tmp_mac_rx_cfg_rx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_cfg_rx.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX));
      tmp_mac_rx_cfg_rx.bf.drop_short = drop_short ? 1 : 0;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX), tmp_mac_rx_cfg_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX MINLEN                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_minlen(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 minlen)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Minlen                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the minimum frame length that may accept by the MAC's        */
/* receiver.                                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [minlen]  Ethernet mode:  must be set to 64 (default).         */
/*     Frames received that are shorter than this value are marked  */
/*     'short' and are subject to dropping depending on the         */ 
/*     setting of ten_pp10g_mac_ctl_drop_short() API.               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_MINLEN_t tmp_mac_rx_minlen;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_minlen.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, MINLEN));
      tmp_mac_rx_minlen.bf.minlen = minlen;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, MINLEN), tmp_mac_rx_minlen.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX MAXLEN                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_maxlen(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 maxlen)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Maxlen                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the maximum frame length that will accept by the MAC's       */
/* receiver.                                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [maxlen]  Ethernet mode: set to at least 64.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_MAXLEN_t tmp_mac_rx_maxlen;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_maxlen.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, MAXLEN));
      tmp_mac_rx_maxlen.bf.maxlen = maxlen;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, MAXLEN), tmp_mac_rx_maxlen.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX MAXLEN AND XGADJ TX MAXFRAME        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_maxlen_and_xgadj_tx_maxframe(cs_uint16 module_id, 
                                                        cs_uint8 slice, 
                                                        cs_uint16 maxlen)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Maxlen                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the maximum frame length that will accept by the MAC's       */
/* receiver and sets XGADJ TX Maximum Frame Length, ie for          */
/* enabling jumbo frames.                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [maxlen]  Ethernet mode: set to at least 64.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  
  rtn |= ten_pp10g_mac_rx_maxlen(module_id, slice, maxlen);
  rtn |= ten_pp10g_xgadj_tx_maxframe(module_id, slice, 0, maxlen);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX SET MAXLEN MODE                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_set_maxlen_mode(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 maxlen_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Maxlen Mode                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Determines the interpretation of the MAXLEN configuration        */
/* register.                                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [maxlen_mode]                                                  */
/*     0 = FIX MAXLEN denotes the maximum frame length for any      */
/*     frame type (tagged or untagged).                             */
/*     1 = AUTO MAXLEN denotes the maximum untagged frame length.   */
/*     For tagged frames, the maximum frame length is calculated    */
/*     on a frame-by-frame basis.                                   */
/*     1 VLAN tag  = MAXLEN + 4,                                    */
/*     2 VLAN tags = MAXLEN + 8                                     */
/*     3 VLAN tags = MAXLEN + 12                                    */
/*     4 VLAN tags = MAXLEN+16.                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_CFG_RX_t tmp_mac_rx_cfg_rx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_cfg_rx.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX));
      tmp_mac_rx_cfg_rx.bf.maxlen_mode = maxlen_mode;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX), tmp_mac_rx_cfg_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start   PP10G MAC CONFIG RX PAUSE FRAME HANDLING        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_cfg_pause_frame(cs_uint16 module_id, cs_uint8 slice, 
                              cs_ctl_t len_chk_en_pause, 
                              cs_ctl_t pause_extract, 
                              cs_ctl_t pause_term)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Len Chk En Pause                                  */
/*              o Pause Extract                                     */
/*              o Pause Term                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure various controls over pause frame processing.          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [len_chk_en_pause]  Enable frame length check of pause frames. */
/*     Note that the Frame Maximum Length check is not affected by  */
/*     this setting.                                                */
/*                                                                  */
/*   [pause_extract]  Pause Quanta extraction.  When 0, the Pause   */
/*     Quanta transfer to the MAC Transmitter is disabled.  When 1, */
/*     it is enabled.                                               */
/*                                                                  */
/*   [pause_term]  Pause Frame termination. When 0, Pause frames    */
/*     are forwarded to the CORE Receiver. When 1, Pause frames     */
/*     are terminated in the MAC.                                   */ 
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_CFG_RX_t tmp_mac_rx_cfg_rx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_cfg_rx.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX));
      tmp_mac_rx_cfg_rx.bf.len_chk_en_pause = len_chk_en_pause ? 1 : 0;
      tmp_mac_rx_cfg_rx.bf.pause_extract = pause_extract ? 1 : 0;
      tmp_mac_rx_cfg_rx.bf.pause_term = pause_term ? 1 : 0;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX), tmp_mac_rx_cfg_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX CONFIG PAUSE REQUEST                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_cfg_pause_req(cs_uint16 module_id, cs_uint8 slice,
                              cs_uint16 pause_preemptive_en, 
                              cs_uint16 pause_reactive_auto_xon, 
                              cs_uint16 pause_reactive_en, 
                              cs_uint16 lf_auto_flush_en, 
                              cs_uint16 inssa, 
                              cs_uint16 ifg_mode_tx)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pause Preemptive En                               */
/*              o Pause Reactive Auto Xon                           */
/*              o Pause Reactive En                                 */
/*              o Lf Auto Flush En                                  */
/*              o InsSA                                             */
/*              o IFG Mode Tx                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure the function of pause request in the TX direction.     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pause_preemptive_en]  Enable/disable(default) the XGMAC       */
/*     pre-emptive Pause frame mode.                                */
/*                                                                  */
/*   [pause_reactive_auto_xon]  This setting applies to the         */
/*     re-active Pause frame mode.                                  */
/*                                                                  */
/*   [pause_reactive_en]  Enable/disable(default) the XGMAC         */
/*     re-active Pause frame mode.                                  */
/*                                                                  */
/*   [lf_auto_flush_en]  Enable/disable the automatic flush of      */
/*     transmit data when 'link_fault' is asserted from the         */
/*     Reconciliation Sublayer.                                     */
/*                                                                  */
/*   [inssa]  Insert Source Address field enable                    */
/*                                                                  */
/*   [ifg_mode_tx]  Inter Frame Gap mode for 10G operation.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_CFG_TX_t tmp_mac_tx_cfg_tx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_cfg_tx.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_TX));
      tmp_mac_tx_cfg_tx.bf.pause_preemptive_en = pause_preemptive_en;
      tmp_mac_tx_cfg_tx.bf.pause_reactive_auto_xon = pause_reactive_auto_xon;
      tmp_mac_tx_cfg_tx.bf.pause_reactive_en = pause_reactive_en;
      tmp_mac_tx_cfg_tx.bf.lf_auto_flush_en = lf_auto_flush_en;
      tmp_mac_tx_cfg_tx.bf.insSA = inssa;
      tmp_mac_tx_cfg_tx.bf.IFG_mode_tx = ifg_mode_tx;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_TX), tmp_mac_tx_cfg_tx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start   PP10G MAC CONTROL TX AUTO FLUSH OPTION          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_ctl_auto_flush(cs_uint16 module_id, cs_uint8 slice,
                              cs_ctl_t lf_auto_flush_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Lf Auto Flush En                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enable or disable the automatic flush of transmit data when      */
/* 'link_fault' is asserted from the Reconciliation Sublayer.       */           
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [lf_auto_flush_en]  CS_DISABLE (0) or CS_ENABLE (1)            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_CFG_TX_t tmp_mac_tx_cfg_tx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_cfg_tx.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_TX));
      tmp_mac_tx_cfg_tx.bf.lf_auto_flush_en = lf_auto_flush_en ? 1 : 0;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_TX), tmp_mac_tx_cfg_tx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX CFG ETHERNET MODE                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_cfg_ethernet_mode(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 sfd_check, 
                              cs_uint16 crc_err_fatal, 
                              cs_uint16 fcs_chk_en, 
                              cs_uint16 len_chk_en_pad, 
                              cs_uint16 len_chk_en, 
                              cs_uint16 promis_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Sfd Check                                         */
/*              o Crc Err Fatal                                     */
/*              o Fcs Chk En                                        */
/*              o Len Chk En Pad                                    */
/*              o Len Chk En                                        */
/*              o Promis Mode                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure various controls specific to Ethernet RX mode.         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [sfd_check]  SFD check mode.                                   */
/*                                                                  */
/*   [crc_err_fatal]  When set, the crc error status is             */
/*     contributing to the RX_ERR output to the CORE Receiver.      */
/*     When clear, the crc error status is not contributing to      */
/*     the RX_ERR output to the CORE Receiver.                      */
/*                                                                  */
/*   [fcs_chk_en]  Enable FCS check.                                */
/*                                                                  */
/*   [len_chk_en_pad]  Enable frame length check of padded frames.  */
/*     (as indicated by the Type/Length field).                     */
/*      Note that the Frame Maximum Length check is not affected    */
/*      by this setting                                             */
/*                                                                  */
/*   [len_chk_en]   Enable frame length check of                    */
/*      non-pause/non-padded frames                                 */
/*                                                                  */
/*   [promis_mode]  Promiscuous mode enable. All unicast frames     */
/*      are accepted when enabled.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_CFG_RX_t tmp_mac_rx_cfg_rx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_cfg_rx.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX));
      tmp_mac_rx_cfg_rx.bf.sfd_check = sfd_check;
      tmp_mac_rx_cfg_rx.bf.crc_err_fatal = crc_err_fatal;
      tmp_mac_rx_cfg_rx.bf.fcs_chk_en = fcs_chk_en;
      tmp_mac_rx_cfg_rx.bf.len_chk_en_pad = len_chk_en_pad;
      tmp_mac_rx_cfg_rx.bf.len_chk_en = len_chk_en;
      tmp_mac_rx_cfg_rx.bf.promis_mode = promis_mode;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX), tmp_mac_rx_cfg_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX CFG ETHERNET MODE PROMIS            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_cfg_ethernet_mode_promis(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 promis_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Promis Mode                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure various controls specific to Ethernet RX mode.         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [promis_mode]  Promiscuous mode enable. All unicast frames     */
/*      are accepted when enabled.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_CFG_RX_t tmp_mac_rx_cfg_rx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_rx_cfg_rx.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX));
      tmp_mac_rx_cfg_rx.bf.promis_mode = promis_mode;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_RX), tmp_mac_rx_cfg_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start   PP10G MAC RX GET ETHERNET LINK STATUS           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_boolean ten_pp10g_mac_rx_get_link_status(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Link Status (TRUE - Valid link is established,      */
/*              or FALSE)                                           */
/* DESCRIPTION:                                                     */
/* Get link status.  TRUE if syncdetS is 1.                         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3)                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 sl = slice;
  TEN_PP10G_PCS_RX_RXSTATUS_t tmp_pcs_rx_rxstatus;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  tmp_pcs_rx_rxstatus.wrd = TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, sl, RXSTATUS));
  return (tmp_pcs_rx_rxstatus.bf.syncdetS == 1); 
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE QUANTA                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_quanta(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 pq)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pq                                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Pause Quanta for XOFF Pause frames.                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pq]                                                           */
/*     This value is inserted in XOFF Pause frames generated from   */
/*     either the X_GEN control bit or the 'pause_req' CORE         */
/*     input.                                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PQUANTA_t tmp_mac_tx_pquanta;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_pquanta.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PQUANTA));
      tmp_mac_tx_pquanta.bf.pq = pq;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PQUANTA), tmp_mac_tx_pquanta.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX GENERATE PAUSE FRAME                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_generate_pause_frame(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 xon_xoff)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o XON XOFF                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Generate pause frame from microprocessor interface.              */
/* The pause frame is usually generated automatically, but this     */
/* API may be used for debugging purposes.                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [xon_xoff]                                                     */
/*     xon_xoff = 0, requests generation of an XOFF Pause frame.    */
/*     xon_xoff = 1, requests generation of an XON Pause frame.     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PAUSE_TX_CMD_t tmp_mac_tx_pause_tx_cmd;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_pause_tx_cmd.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, 
                                    module_id, sl, PAUSE_TX_CMD));
      tmp_mac_tx_pause_tx_cmd.bf.XON_XOFF = xon_xoff ? 1 : 0;
      
      /* toggle the gen bit to generate pause frame */
      tmp_mac_tx_pause_tx_cmd.bf.X_GEN ^= 1;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PAUSE_TX_CMD), 
                                           tmp_mac_tx_pause_tx_cmd.wrd);
      /* delay at least 20 microprocessor clock cycles */
      /* Bugzilla #28471, minimum delay */
      TEN_MDELAY(6);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX MAC ADDRESS                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_mac_address(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 addr_a,
                                  cs_uint16 addr_b,
                                  cs_uint16 addr_c)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Address A                                         */
/*              o Address B                                         */
/*              o Address C                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Specify MAC Address, a 48 bit unicast address can be used        */
/* for address filtering and/or tx source address override in       */
/* Ethernet mode application.                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [addr_a]  This is the most significant 16-bits of the 48-bit   */
/*     MAC address.  Bits [15:8] are the first byte transmitted on  */
/*     the line (first bit transmitted of this byte is bit [8]).    */
/*     Bits [7:0] are the second byte transmitted on the line       */
/*     (first bit transmitted of this byte is bit [0]).             */
/*                                                                  */
/*   [addr_b]  This is the middle significant 16-bits of the 48-bit */
/*     MAC address.  Bits [15:8] are the third byte transmitted on  */
/*     the line (first bit transmitted of this byte is bit [8]).    */
/*     Bits [7:0] are the fourth byte transmitted on the line       */
/*     (first bit transmitted of this byte is bit [0]).             */
/*                                                                  */
/*   [addr_c]  This is the least significant 16-bits of the 48-bit  */
/*     MAC address.  Bits [15:8] are the fifth byte transmitted on  */
/*     the line (first bit transmitted of this byte is bit [8]).    */
/*     Bits [7:0] are the sixth byte transmitted on the line        */
/*     (first bit transmitted of this byte is bit [0]).             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_MAC_ADDR_A_t tmp_mac_tx_mac_addr_a;
  TEN_PP10G_MAC_TX_MAC_ADDR_B_t tmp_mac_tx_mac_addr_b;
  TEN_PP10G_MAC_TX_MAC_ADDR_C_t tmp_mac_tx_mac_addr_c;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_mac_addr_a.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_MAC_ADDR_A));
      tmp_mac_tx_mac_addr_a.bf.addr = addr_a;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_MAC_ADDR_A), tmp_mac_tx_mac_addr_a.wrd);
      
      tmp_mac_tx_mac_addr_b.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_MAC_ADDR_B));
      tmp_mac_tx_mac_addr_b.bf.addr = addr_b;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_MAC_ADDR_B), tmp_mac_tx_mac_addr_b.wrd);

      tmp_mac_tx_mac_addr_c.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_MAC_ADDR_C));
      tmp_mac_tx_mac_addr_c.bf.addr = addr_c;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_MAC_ADDR_C), tmp_mac_tx_mac_addr_c.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX VLAN TAG                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_vlan_tag(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 tag1,
                                 cs_uint16 tag2,
                                 cs_uint16 tag3)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Tag1                                              */
/*              o Tag2                                              */
/*              o Tag3                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the additional VLAN TAG's besides 0x8100 to be               */
/* identified as VLAN tagged frames.  Thus frames can be            */
/* properly decoded and accounted for payload bytes.                */
/*                                                                  */
/* Note:  Enter 0 for unused vlan tags.                             */
/*                                                                  */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tag1]  First VLAN Tag.  VLAN_TAG1/2/3 and 0x8100 are compared */
/*     against each frame's Qtag fields in order to determine       */
/*     tagging level.  Up to 4 stackable VLANs are supported.       */
/*                                                                  */
/*   [tag2]  Second VLAN Tag.  VLAN_TAG1/2/3 and 0x8100 are         */
/*     compared against each frame's Qtag fields in order to        */
/*     determine tagging level.  Up to 4 stackable VLANs are        */
/*     supported.                                                   */
/*                                                                  */
/*   [tag3]  Third VLAN Tag. VLAN_TAG1/2/3 and 0x8100 are compared  */
/*     against each frame's Qtag fields in order to determine       */
/*     tagging level.  Up to 4 stackable VLANs are supported.       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_VLAN_TAG1_t tmp_mac_tx_vlan_tag1;
  TEN_PP10G_MAC_TX_VLAN_TAG2_t tmp_mac_tx_vlan_tag2;
  TEN_PP10G_MAC_TX_VLAN_TAG3_t tmp_mac_tx_vlan_tag3;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_vlan_tag1.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_VLAN_TAG1));
      tmp_mac_tx_vlan_tag1.bf.tag = tag1;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_VLAN_TAG1), tmp_mac_tx_vlan_tag1.wrd);
      
      tmp_mac_tx_vlan_tag2.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl,   tx_VLAN_TAG2));
      tmp_mac_tx_vlan_tag2.bf.tag = tag2;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_VLAN_TAG2), tmp_mac_tx_vlan_tag2.wrd);
      
      tmp_mac_tx_vlan_tag3.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_VLAN_TAG3));
      tmp_mac_tx_vlan_tag3.bf.tag = tag3;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, tx_VLAN_TAG3), tmp_mac_tx_vlan_tag3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX VLAN TAG                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_rx_vlan_tag(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 tag1,
                                    cs_uint16 tag2,
                                    cs_uint16 tag3)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Tag1                                              */
/*              o Tag2                                              */
/*              o Tag3                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the additional VLAN TAG's besides 0x8100 to be               */
/* identified as VLAN tagged frames.  Thus frames can be            */
/* properly decoded and accounted for payload bytes.                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tag1]  First VLAN Tag.  VLAN_TAG1/2/3 and 0x8100 are compared */
/*     against each frame's Qtag fields in order to determine       */
/*     tagging level.  Up to 4 stackable VLANs are supported.       */
/*                                                                  */
/*   [tag2]  Second VLAN Tag.  VLAN_TAG1/2/3 and 0x8100 are         */
/*     compared against each frame's Qtag fields in order to        */
/*     determine tagging level.  Up to 4 stackable VLANs are        */
/*     supported.                                                   */
/*                                                                  */
/*   [tag3]  Third VLAN Tag. VLAN_TAG1/2/3 and 0x8100 are compared  */
/*     against each frame's Qtag fields in order to determine       */
/*     tagging level.  Up to 4 stackable VLANs are supported.       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_RX_VLAN_TAG1_t tmp_mac_rx_vlan_tag1;
  TEN_PP10G_MAC_RX_VLAN_TAG2_t tmp_mac_rx_vlan_tag2;
  TEN_PP10G_MAC_RX_VLAN_TAG3_t tmp_mac_rx_vlan_tag3;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
    
      tmp_mac_rx_vlan_tag1.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_VLAN_TAG1));
      tmp_mac_rx_vlan_tag1.bf.tag = tag1;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_VLAN_TAG1), tmp_mac_rx_vlan_tag1.wrd);
        
      tmp_mac_rx_vlan_tag2.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_VLAN_TAG2));
      tmp_mac_rx_vlan_tag2.bf.tag = tag2;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_VLAN_TAG2), tmp_mac_rx_vlan_tag2.wrd);

      tmp_mac_rx_vlan_tag3.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_VLAN_TAG3));
      tmp_mac_rx_vlan_tag3.bf.tag = tag3;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, rx_VLAN_TAG3), tmp_mac_rx_vlan_tag3.wrd);

    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE ADDRESS                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_address(cs_uint16 module_id, cs_uint8 slice, 
                                         cs_uint16 addr_a,
                                         cs_uint16 addr_b,
                                         cs_uint16 addr_c)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Address A                                         */
/*              o Address B                                         */
/*              o Address C                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Specify Destination Address used in generated pause frames.      */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [addr_a]  This is the most significant 16-bit of the 48-bit    */
/*     Pause Frame Destination Address.  Bits [15:8]: first byte    */
/*     transmitted on the line (first bit transmitted of this byte  */
/*     is bit [8]).  Bits [7:0]: second byte transmitted on the     */
/*     line (first bit transmitted of this byte is bit [0]).        */
/*                                                                  */
/*   [addr_b]  This is the middle significant 16-bit of the 48-bit  */
/*     Pause Frame Destination Address.  Bits [15:8]: third byte    */
/*     transmitted on the line (first bit transmitted of this byte  */
/*     is bit [8]).  Bits [7:0]: fourth byte transmitted on the     */
/*     line (first bit transmitted of this byte is bit [0]).        */
/*                                                                  */
/*   [addr_c]  This is the least significant 16-bit of the 48-bit   */
/*     Pause Frame Destination Address.  Bits [15:8]: fifth byte    */
/*     transmitted on the line (first bit transmitted of this byte  */
/*     is bit [8]).  Bits [7:0]: sixth byte transmitted on the      */
/*     line (first bit transmitted of this byte is bit [0]).        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PAUSE_ADDR_A_t tmp_mac_tx_pause_addr_a;
  TEN_PP10G_MAC_TX_PAUSE_ADDR_B_t tmp_mac_tx_pause_addr_b;
  TEN_PP10G_MAC_TX_PAUSE_ADDR_C_t tmp_mac_tx_pause_addr_c;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {

      tmp_mac_tx_pause_addr_a.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, 
                                    module_id, sl, PAUSE_ADDR_A));
      tmp_mac_tx_pause_addr_a.bf.addr = addr_a;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PAUSE_ADDR_A), 
                                           tmp_mac_tx_pause_addr_a.wrd);
                                           
      tmp_mac_tx_pause_addr_b.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, 
                                    module_id, sl, PAUSE_ADDR_B));
      tmp_mac_tx_pause_addr_b.bf.addr = addr_b;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PAUSE_ADDR_B), 
                                           tmp_mac_tx_pause_addr_b.wrd);                     
         
      tmp_mac_tx_pause_addr_c.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, 
                                            module_id, sl, PAUSE_ADDR_C));
      tmp_mac_tx_pause_addr_c.bf.addr = addr_c;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PAUSE_ADDR_C), 
                                           tmp_mac_tx_pause_addr_c.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX MAC GET ADDR RDONLY2                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_mac_tx_mac_get_addr_rdonly2(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Addr                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns the most significant read-only 16 bits of the TX MAC     */
/* address for the specified slice.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MAC_TX_MAC_ADDR_RDONLY2_t tmp_mac_tx_mac_addr_rdonly2;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_mac_tx_mac_addr_rdonly2.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, slice, tx_MAC_ADDR_RDONLY2));
  return (tmp_mac_tx_mac_addr_rdonly2.bf.addr);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX MAC GET ADDR RDONLY1                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_mac_tx_mac_get_addr_rdonly1(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Addr                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns the middle significant read-only 16 bits of the TX MAC   */
/* address for the specified slice.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MAC_TX_MAC_ADDR_RDONLY1_t tmp_mac_tx_mac_addr_rdonly1;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_mac_tx_mac_addr_rdonly1.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, slice, tx_MAC_ADDR_RDONLY1));
  return (tmp_mac_tx_mac_addr_rdonly1.bf.addr);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX MAC GET ADDR RDONLY0                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_mac_tx_mac_get_addr_rdonly0(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Addr                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns the least significant read-only 16 bits of the TX MAC    */
/* address for the specified slice.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MAC_TX_MAC_ADDR_RDONLY0_t tmp_mac_tx_mac_addr_rdonly0;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_mac_tx_mac_addr_rdonly0.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, slice, tx_MAC_ADDR_RDONLY0));
  return (tmp_mac_tx_mac_addr_rdonly0.bf.addr);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX MAC GET ADDR RDONLY2                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_mac_rx_mac_get_addr_rdonly2(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Addr                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns the most significant read-only 16 bits of the RX MAC     */
/* address for the specified slice.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MAC_RX_MAC_ADDR_RDONLY2_t tmp_mac_rx_mac_addr_rdonly2;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_mac_rx_mac_addr_rdonly2.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, slice, rx_MAC_ADDR_RDONLY2));
  return (tmp_mac_rx_mac_addr_rdonly2.bf.addr);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX MAC GET ADDR RDONLY1                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_mac_rx_mac_get_addr_rdonly1(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Addr                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns the middle significant read-only 16 bits of the RX MAC   */
/* address for the specified slice.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MAC_RX_MAC_ADDR_RDONLY1_t tmp_mac_rx_mac_addr_rdonly1;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_mac_rx_mac_addr_rdonly1.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, slice, rx_MAC_ADDR_RDONLY1));
  return (tmp_mac_rx_mac_addr_rdonly1.bf.addr);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC RX MAC GET ADDR RDONLY0                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_mac_rx_mac_get_addr_rdonly0(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Addr                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns the least significant read-only 16 bits of the RX MAC    */
/* address for the specified slice.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MAC_RX_MAC_ADDR_RDONLY0_t tmp_mac_rx_mac_addr_rdonly0;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_mac_rx_mac_addr_rdonly0.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, slice, rx_MAC_ADDR_RDONLY0));
  return (tmp_mac_rx_mac_addr_rdonly0.bf.addr);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE FRAME MONITOR CONTROL         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_frame_monitor_control(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 monitor, 
                               cs_uint16 check_reserved_da, 
                               cs_uint16 check_specified_da, 
                               cs_uint16 check_length)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Monitor                                           */
/*              o Check Reserved Da                                 */
/*              o Check Specified Da                                */
/*              o Check Length                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the configuration of the PAUSE Frame         */
/* Monitor function which observes and tracks PAUSE frames          */
/* that do not originate from the PAUSE Frame Request function of   */
/* this PP10G.                                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [monitor]  Determines whether transitting PAUSE frames are     */
/*     monitored:                                                   */
/*     ENABLE (1) = Enable monitoring.                              */
/*     DISABLE (0) = Disable monitoring                             */
/*                                                                  */
/*   [check_reserved_da]  Checked against the reserved multicast    */
/*     destination address specified in IEEE Std 802.3-2005 Clause  */
/*     31B1, namely 01_80_C2_00_00_01.                              */
/*     CHECK (1) = Compare to reserved multicast DA                 */
/*     NO_CHECK (0) = Do not compare to reserved multicast DA       */
/*                                                                  */
/*   [check_specified_da]  Determines whether transitting PAUSE     */
/*     frames are checked against the singlecast DA specified       */
/*     in register PFMSCDA.                                         */
/*     CHECK (1) = Compare to specified singlecast DA               */
/*     NO_CHECK (0) = Do not compare to specified singlecase DA     */
/*                                                                  */
/*   [check_length]  Checked for the correct length.  Pause frames  */
/*     are expected to be minimum sized packets of 64 bytes         */
/*     (or 60bytes with the FCS).                                   */
/*     CHECK (1) = Check Pause Frame length to be 64/60 octets.     */
/*     NO_CHECK (0) =  Do not check the pause frame length          */ 
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PFMCTRL_t tmp_mac_tx_pfmctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_pfmctrl.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PFMCTRL));
      tmp_mac_tx_pfmctrl.bf.monitor = monitor;
      tmp_mac_tx_pfmctrl.bf.check_reserved_da = check_reserved_da;
      tmp_mac_tx_pfmctrl.bf.check_specified_da = check_specified_da;
      tmp_mac_tx_pfmctrl.bf.check_length = check_length;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PFMCTRL), tmp_mac_tx_pfmctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE FRAME MONITOR SCDA1           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_mac_tx_pfmscda1(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Address                                             */
/* DESCRIPTION:                                                     */
/* This register provides a singlecast destination address for      */
/* optional matching to the destination address of PAUSE frames     */
/* transitting this PP10G.  This is the most significant 16-bits    */
/* of the 48-bit address.                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3).                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MAC_TX_PFMSCDA1_t tmp_mac_tx_pfmscda1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_mac_tx_pfmscda1.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, slice, PFMSCDA1));
  return (tmp_mac_tx_pfmscda1.bf.da_match1);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE FRAME MONITOR SCDA2           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_mac_tx_pfmscda2(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Address                                             */
/* DESCRIPTION:                                                     */
/* This register provides a singlecast destination address for      */
/* optional matching to the destination address of PAUSE frames     */
/* transitting this PP10G.  This is the most middle 16-bits         */
/* of the 48-bit address.                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3).                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MAC_TX_PFMSCDA2_t tmp_mac_tx_pfmscda2;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_mac_tx_pfmscda2.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, slice, PFMSCDA2));
  return (tmp_mac_tx_pfmscda2.bf.da_match2);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE FRAME MONITOR SCDA3           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_mac_tx_pfmscda3(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Address                                             */
/* DESCRIPTION:                                                     */
/* This register provides a singlecast destination address for      */
/* optional matching to the destination address of PAUSE frames     */
/* transitting this PP10G.  This is the least significant 16-bits   */
/* of the 48-bit address.                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3).                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MAC_TX_PFMSCDA3_t tmp_mac_tx_pfmscda3;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_mac_tx_pfmscda3.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, slice, PFMSCDA3));
  return (tmp_mac_tx_pfmscda3.bf.da_match3);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE FRAME REQUEST GEN             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_frame_request_gen(cs_uint16 module_id, 
                               cs_uint8 slice, 
                               cs_uint16 upper_threshold_zero, 
                               cs_uint16 lower_threshold_one)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Upper Threshold Zero                              */
/*              o Lower Threshold One                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the configuration of the PAUSE Frame Request */
/* Generator function which generates requests for the insertion    */
/* contains the quanta increment to be used for each of the         */
/* two buffer thresholdof PAUSE frames in the transmit              */
/* direction as a means of flow control.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [upper_threshold_zero]  This configuration field forces the    */
/*     upper threshold crossing flag provided by XCON to always     */
/*     be a zero.                                                   */
/*                                                                  */
/*   [lower_threshold_one]  This configuration field forces the     */
/*     lower threshold crossing flag provided by XCON to            */
/*     always be a one.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PFGCTRL_t tmp_mac_tx_pfgctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_pfgctrl.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PFGCTRL));
      tmp_mac_tx_pfgctrl.bf.upper_threshold_zero = upper_threshold_zero;
      tmp_mac_tx_pfgctrl.bf.lower_threshold_one = lower_threshold_one;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PFGCTRL), tmp_mac_tx_pfgctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE REQUEST GEN FRAME INS RATE    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_request_gen_frame_ins_rate(cs_uint16 module_id, 
                               cs_uint8 slice, 
                               cs_uint16 rate)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rate                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Specifies the pause frame insertion rate.                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rate]  This value specifies the pause frame insertion rate.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PRGRATE_t tmp_mac_tx_prgrate;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_prgrate.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PRGRATE));
      tmp_mac_tx_prgrate.bf.rate = rate;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PRGRATE), tmp_mac_tx_prgrate.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE REQUEST GEN CRITICAL TIME MIN */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_request_gen_critical_time_min(cs_uint16 module_id, 
                               cs_uint8 slice, 
                               cs_uint16 crit_time_min)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Crit Time Min                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Specifies the time (in clock cycles*8) between a pause frame     */
/* insertion and detection that is considered a pause frame         */
/* collision.                                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [crit_time_min]  Value in clock cycles*8.                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PRGTMIN_t tmp_mac_tx_prgtmin;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_prgtmin.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PRGTMIN));
      tmp_mac_tx_prgtmin.bf.crit_time_min = crit_time_min;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PRGTMIN), tmp_mac_tx_prgtmin.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE REQUEST GEN DETECTED QUANTA LIMIT */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_request_gen_detected_quanta_limit(cs_uint16 module_id, 
                                cs_uint8 slice, 
                                cs_uint16 quanta_limit)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Quanta Limit                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Specifies the maximum number of detected pause quanta that       */
/* are subtracted from the quanta_counter.                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [quanta_limit]  This value specifies the maximum number of     */
/*     detected pause quanta.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PRGDQLIM_t tmp_mac_tx_prgdqlim;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_prgdqlim.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PRGDQLIM));
      tmp_mac_tx_prgdqlim.bf.quanta_limit = quanta_limit;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PRGDQLIM), tmp_mac_tx_prgdqlim.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE REQUEST GEN QUANTA INCREMENT  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_request_gen_quanta_increment(cs_uint16 module_id, 
                               cs_uint8 slice, 
                               cs_uint16 quantum_upper, 
                               cs_uint16 quantum_lower)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Quantum Upper                                     */
/*              o Quantum Lower                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Specifies the quanta increment to be used for each of the        */
/* two buffer thresholds.                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [quantum_upper]  This value is used as the quanta increment    */
/*     when the buffer occupancy is above the upper threshold.      */
/*                                                                  */
/*   [quantum_lower]  This value is used as the quanta increment    */
/*     when the buffer occupancy is above the lower threshold,      */
/*     but below the upper threshold.                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PRGQINC_t tmp_mac_tx_prgqinc;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_prgqinc.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PRGQINC));
      tmp_mac_tx_prgqinc.bf.quantum_upper = quantum_upper;
      tmp_mac_tx_prgqinc.bf.quantum_lower = quantum_lower;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PRGQINC), tmp_mac_tx_prgqinc.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX CONFIG PAUSE ENABLE                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_cfg_pause_en(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 pause_preemptive_en, 
                                        cs_uint16 pause_reactive_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Pause Preemptive En                               */
/*              o Pause Reactive En                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure the function of pause request in the TX direction.     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [pause_preemptive_en]  Enable/disable(default) the XGMAC       */
/*     pre-emptive Pause frame mode.                                */
/*                                                                  */
/*   [pause_reactive_en]  Enable/disable(default) the XGMAC         */
/*     re-active Pause frame mode.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_CFG_TX_t tmp_mac_tx_cfg_tx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_cfg_tx.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_TX));
      tmp_mac_tx_cfg_tx.bf.pause_preemptive_en = pause_preemptive_en;
      tmp_mac_tx_cfg_tx.bf.pause_reactive_en = pause_reactive_en;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, CFG_TX), tmp_mac_tx_cfg_tx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE FRAME MONITOR                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_frame_monitor(cs_uint16 module_id,
                                               cs_uint8 slice, 
                                               cs_uint16 monitor)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Monitor                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the configuration of the PAUSE Frame         */
/* Monitor function which observes and tracks PAUSE frames          */
/* that do not originate from the PAUSE Frame Request function of   */
/* this PP10G.                                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [monitor]  Determines whether transitting PAUSE frames are     */
/*     monitored:                                                   */
/*     ENABLE (1) = Enable monitoring.                              */
/*     DISABLE (0) = Disable monitoring                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PFMCTRL_t tmp_mac_tx_pfmctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_pfmctrl.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PFMCTRL));
      tmp_mac_tx_pfmctrl.bf.monitor = monitor;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PFMCTRL), tmp_mac_tx_pfmctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE FRAME REQUEST LT1             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_frame_request_lt1(cs_uint16 module_id, 
                               cs_uint8 slice, 
                               cs_uint16 lower_threshold_one)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Lower Threshold One                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the configuration of the PAUSE Frame Request */
/* Generator function which generates requests for the insertion    */
/* contains the quanta increment to be used for each of the         */
/* two buffer thresholdof PAUSE frames in the transmit              */
/* direction as a means of flow control.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [lower_threshold_one]  This configuration field forces the     */
/*     lower threshold crossing flag provided by XCON to always     */
/*     be a one.                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PFGCTRL_t tmp_mac_tx_pfgctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_pfgctrl.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PFGCTRL));
      tmp_mac_tx_pfgctrl.bf.lower_threshold_one = lower_threshold_one;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PFGCTRL), tmp_mac_tx_pfgctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MAC TX PAUSE XOFF DELAY                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mac_tx_pause_xoff_delay(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint16 inter_xoff_delay)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Inter Xoff Delay                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This setting applies to the re-active Pause frame mode.          */
/* It controls the interval between XOFF Pause frame transmission   */
/* when the MAC's pause request input is asserted.                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [inter_xoff_delay]                                             */
/*     The unit is 0.5 * PQUANTA. 'inter_xoff_delay'=0 sets the     */
/*     delay to be 0.5*PQUANTA, 'inter_xoff_delay'=1 sets the delay */
/*     to be 1.0*PQUANTA, etc.                                      */ 
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MAC_TX_PAUSE_XOFF_DELAY_t tmp_mac_tx_pause_xoff_delay;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_mac_tx_pause_xoff_delay.wrd = TEN_REG_READ(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PAUSE_XOFF_DELAY));
      tmp_mac_tx_pause_xoff_delay.bf.inter_xoff_delay = inter_xoff_delay;
      TEN_REG_WRITE(TEN_PP10G_MAC_REG_ADDR(pDev, module_id, sl, PAUSE_XOFF_DELAY), tmp_mac_tx_pause_xoff_delay.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}





