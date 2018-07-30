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
 * ten_pp40g.c 
 *
 * $Id: ten_pp40g.c,v 1.30 2013/02/22 20:56:33 jccarlis Exp $
 *
 * API's for PP40G 
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  PP40G MISC CONTROL SRESET T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_misc_control_sreset_t41(cs_uint16 module_id, 
                                            cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control Misc Soft Reset.                                         */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_MISC_RESET_t tmp_misc_reset;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_misc_reset.wrd = 0;
  tmp_misc_reset.bf.mpif_rst = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), 
                   tmp_misc_reset.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G GET MISC SRESET T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_get_misc_sreset_t41(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 0 or 1                                              */
/* DESCRIPTION:                                                     */
/* Get Misc Soft Reset value.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_MISC_RESET_t tmp_misc_reset;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_misc_reset.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, RESET));
  return (tmp_misc_reset.bf.mpif_rst);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G LIF RX CONTROL SRESET T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_lif_rx_control_sreset_t41(cs_uint16 module_id, 
                                              cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*  Control LIF RX Soft Reset.                                      */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_LIF_RX_CNTRL_t tmp_lif_rx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_lif_rx_cntrl.wrd = 0;
  tmp_lif_rx_cntrl.bf.rxrst = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), 
                   tmp_lif_rx_cntrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PCS RX CONTROL SRESET T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_pcs_rx_control_sreset_t41(cs_uint16 module_id, 
                                              cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control PCS RX Soft Reset.                                       */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PCS_RX_CNTRL_t tmp_pcs_rx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pcs_rx_cntrl.wrd = 0;
  tmp_pcs_rx_cntrl.bf.rxrst = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_CNTRL), 
                   tmp_pcs_rx_cntrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G RS RX CONTROL SRESET T41                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_rs_rx_control_sreset_t41(cs_uint16 module_id, 
                                             cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control RS RX Soft Reset.                                        */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_RS_RX_CNTRL_t tmp_rs_rx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_rs_rx_cntrl.wrd = 0;
  tmp_rs_rx_cntrl.bf.rxrst = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL),
                   tmp_rs_rx_cntrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G MAC RX CONTROL SRESET T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_mac_rx_control_sreset_t41(cs_uint16 module_id, 
                                              cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control MAC RX Soft Reset.                                       */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_MAC_RX_CNTRL_t tmp_mac_rx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_mac_rx_cntrl.wrd = 0;
  tmp_mac_rx_cntrl.bf.rxrst = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, mac_rx_CNTRL),
                   tmp_mac_rx_cntrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PCS TX CONTROL SRESET T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_pcs_tx_control_sreset_t41(cs_uint16 module_id, 
                                              cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control PCS RX Soft Reset.                                       */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pcs_tx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pcs_tx_cntrl.wrd = 0;
  tmp_pcs_tx_cntrl.bf.tx_rst = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL),
                   tmp_pcs_tx_cntrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PBERT40G TX CONTROL SRESET T41             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_pbert40g_tx_control_sreset_t41(cs_uint16 module_id, 
                                                   cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control PBERT40G TX Soft Reset.                                  */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PBERT40G_TX_CNTRL_t tmp_pbert40g_tx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pbert40g_tx_cntrl.wrd = 0;
  tmp_pbert40g_tx_cntrl.bf.tx_rst = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, pbert40g_tx_CNTRL), 
                   tmp_pbert40g_tx_cntrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PM CONTROL SRESET T41                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_pm_control_sreset_t41(cs_uint16 module_id, 
                                          cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control PP40G PM Soft Reset.                                     */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PM_CTRL_t tmp_pm_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pm_ctrl.wrd = 0;
  tmp_pm_ctrl.bf.rst = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, CTRL),
                   tmp_pm_ctrl.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G MISC INTSTATUS RX DSK SYNCS T41            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_misc_intstatus_rx_dsk_syncs_t41(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Indicates that the receive bypass path 40G deskew block is       */
/* currently synchronized across the four 10G lanes.                */
/* Traffic is deskewed.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_MISC_INTSTATUS_t tmp_misc_intstatus;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_misc_intstatus.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_INTSTATUS));
  return (tmp_misc_intstatus.bf.rx_dsk_syncS);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G LIF RX INTSTATUS T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_lif_rx_intstatus_t41(cs_uint16 module_id, 
                                         cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns Line interface interrupt status for the                  */
/* receive direction.                                               */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP40G_LIF_RX_SELECT_OVERFLOW3S          1                */
/*     TEN_PP40G_LIF_RX_SELECT_OVERFLOW2S          2                */
/*     TEN_PP40G_LIF_RX_SELECT_OVERFLOW1S          3                */
/*     TEN_PP40G_LIF_RX_SELECT_OVERFLOW0S          4                */
/*     TEN_PP40G_LIF_RX_SELECT_OVERFLOWXS          5                */
/*       (all 4 lanes in a bitmask pattern)                         */
/*     TEN_PP40G_LIF_RX_SELECT_ALL              0xFF                */
/*       (entire 16 bit register word at once).                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_LIF_RX_INTSTATUS_t tmp_lif_rx_intstatus;
  cs_uint16 rtn;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_lif_rx_intstatus.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_INTSTATUS));
  
  switch (select) {
  case (TEN_PP40G_LIF_RX_SELECT_OVERFLOW3S):
    rtn = tmp_lif_rx_intstatus.bf.overflow3S;
    break;

  case (TEN_PP40G_LIF_RX_SELECT_OVERFLOW2S):
    rtn = tmp_lif_rx_intstatus.bf.overflow2S;
    break;

  case (TEN_PP40G_LIF_RX_SELECT_OVERFLOW1S):
    rtn = tmp_lif_rx_intstatus.bf.overflow1S;
    break;

  case (TEN_PP40G_LIF_RX_SELECT_OVERFLOW0S):
    rtn = tmp_lif_rx_intstatus.bf.overflow0S;
    break;
    
  case (TEN_PP40G_LIF_RX_SELECT_OVERFLOWXS):
    rtn = ((tmp_lif_rx_intstatus.bf.overflow3S<<3) |
           (tmp_lif_rx_intstatus.bf.overflow2S<<2) |
           (tmp_lif_rx_intstatus.bf.overflow1S<<1) |
           (tmp_lif_rx_intstatus.bf.overflow0S));
    break;
    
 case (TEN_PP40G_LIF_RX_SELECT_ALL):
    rtn = tmp_lif_rx_intstatus.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = 0;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PCS RX AMSTATUS T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_pcs_rx_amstatus_t41(cs_uint16 module_id, 
                                        cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns PCS alignment marker status for the receive direction.   */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID3            1       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID2            2       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID1            3       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID0            4       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEIDX            5       */
/*       (all 4 lanes in a bitmask pattern)                         */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK3         6       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK2         7       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK1         8       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK0         9       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCKX        10       */
/*       (all 4 lanes in a bitmask pattern)                         */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK3        11       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK2        12       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK1        13       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK0        14       */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCKX        15       */
/*       (all 4 lanes in a bitmask pattern)                         */
/*     TEN_PP40G_PCS_RX_AMSTATUS_SELECT_ALL              0xFF       */
/*       (entire 16 bit register word at once).                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PCS_RX_AMSTATUS_t tmp_pcs_rx_amstatus;
  cs_uint16 rtn;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_pcs_rx_amstatus.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, AMSTATUS));
  
  switch (select) {
  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID3):
    rtn = tmp_pcs_rx_amstatus.bf.vlaneid3;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID2):
    rtn = tmp_pcs_rx_amstatus.bf.vlaneid2;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID1):
    rtn = tmp_pcs_rx_amstatus.bf.vlaneid1;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEID0):
    rtn = tmp_pcs_rx_amstatus.bf.vlaneid0;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_VLANEIDX):
    rtn = ((tmp_pcs_rx_amstatus.bf.vlaneid3<<3) |
           (tmp_pcs_rx_amstatus.bf.vlaneid2<<2) |
           (tmp_pcs_rx_amstatus.bf.vlaneid1<<1) |
           (tmp_pcs_rx_amstatus.bf.vlaneid0));
    break;
    
  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK3):
    rtn = tmp_pcs_rx_amstatus.bf.monoamlock3;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK2):
    rtn = tmp_pcs_rx_amstatus.bf.monoamlock2;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK1):
    rtn = tmp_pcs_rx_amstatus.bf.monoamlock1;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCK0):
    rtn = tmp_pcs_rx_amstatus.bf.monoamlock0;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_MONOAMLOCKX):
    rtn = ((tmp_pcs_rx_amstatus.bf.monoamlock3<<3) |
           (tmp_pcs_rx_amstatus.bf.monoamlock2<<2) |
           (tmp_pcs_rx_amstatus.bf.monoamlock1<<1) |
           (tmp_pcs_rx_amstatus.bf.monoamlock0));
    break; /* Bugzilla 30509 splint issue */

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK3):
    rtn = tmp_pcs_rx_amstatus.bf.laneamlock3;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK2):
    rtn = tmp_pcs_rx_amstatus.bf.laneamlock2; 
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK1):
    rtn = tmp_pcs_rx_amstatus.bf.laneamlock1; 
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCK0):
    rtn = tmp_pcs_rx_amstatus.bf.laneamlock0; 
    break;
    
  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_LANEAMLOCKX):
    rtn = ((tmp_pcs_rx_amstatus.bf.laneamlock3<<3) |
           (tmp_pcs_rx_amstatus.bf.laneamlock2<<2) |
           (tmp_pcs_rx_amstatus.bf.laneamlock1<<1) |
           (tmp_pcs_rx_amstatus.bf.laneamlock0)); 
    break;
    
  case (TEN_PP40G_PCS_RX_AMSTATUS_SELECT_ALL):
    rtn = tmp_pcs_rx_amstatus.wrd; 
    break;

  default:
    rtn = 0;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    break;
  }
  return (rtn);
}
  
/********************************************************************/
/* $rtn_hdr_start  PP40G PCS RX AMSTATUS1 T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_pcs_rx_amstatus1_t41(cs_uint16 module_id, 
                                         cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns PCS alignment marker status for the receive direction    */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK3          1      */
/*     TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK2          2      */
/*     TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK1          3      */
/*     TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK0          4      */
/*     TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCKX          5      */
/*       (all 4 lanes in a bitmask pattern)                         */
/*     TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_ALL              0xFF      */
/*       (entire 16 bit register word at once).                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PCS_RX_AMSTATUS1_t tmp_pcs_rx_amstatus1;
  cs_uint16 rtn;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_pcs_rx_amstatus1.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, AMSTATUS1));
  
  switch (select) {
  case (TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK3):
    rtn = tmp_pcs_rx_amstatus1.bf.xdcamlock3;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK2):
    rtn = tmp_pcs_rx_amstatus1.bf.xdcamlock2;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK1):
    rtn = tmp_pcs_rx_amstatus1.bf.xdcamlock1;
    break;

  case (TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCK0):
    rtn = tmp_pcs_rx_amstatus1.bf.xdcamlock0;
    break;
    
  case (TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_XDCAMLOCKX):
    rtn = ((tmp_pcs_rx_amstatus1.bf.xdcamlock3<<3) |
           (tmp_pcs_rx_amstatus1.bf.xdcamlock2<<2) |
           (tmp_pcs_rx_amstatus1.bf.xdcamlock1<<1) |
           (tmp_pcs_rx_amstatus1.bf.xdcamlock0));
    break;
    
 case (TEN_PP40G_PCS_RX_AMSTATUS1_SELECT_ALL):
    rtn = tmp_pcs_rx_amstatus1.wrd;
    break;

  default:
    rtn = 0;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PCS RX INTSTATUS T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_pcs_rx_intstatus_t41(cs_uint16 module_id, 
                                         cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns PCS interrupt status for the receive direction.          */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_SKEWHIGHS           1      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_PATDETECTS          2      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_BERHIGHS            3      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_XDCAMSTATUSS        4      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_XDCBLOCKLOCKS       5      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_MONOAMSTATUSS       6      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_MONOBLOCKLOCKS      7      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEALIGNSTATUSS    8      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEAMSTATUSS       9      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK3S    10      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK2S    11      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK1S    12      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK0S    13      */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCKXS    14      */
/*       (all 4 lanes in a bitmask pattern)                         */
/*     TEN_PP40G_PCS_RX_INTSTATUS_SELECT_ALL              0xFF      */
/*       (entire 16 bit register word at once).                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PCS_RX_INTSTATUS_t tmp_pcs_rx_intstatus;
  cs_uint16 rtn;
  T41_t *pDev = NULL;
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_pcs_rx_intstatus.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_INTSTATUS));
  
  switch (select) {
  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_SKEWHIGHS):
    rtn = tmp_pcs_rx_intstatus.bf.skewhighS;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_PATDETECTS):
    rtn = tmp_pcs_rx_intstatus.bf.patdetectS;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_BERHIGHS):
    rtn = tmp_pcs_rx_intstatus.bf.berhighS;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_XDCAMSTATUSS):
    rtn = tmp_pcs_rx_intstatus.bf.xdcamstatusS;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_XDCBLOCKLOCKS):
    rtn = tmp_pcs_rx_intstatus.bf.xdcblocklockS;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_MONOAMSTATUSS):
    rtn = tmp_pcs_rx_intstatus.bf.monoamstatusS;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_MONOBLOCKLOCKS):
    rtn = tmp_pcs_rx_intstatus.bf.monoblocklockS;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEALIGNSTATUSS):
    rtn = tmp_pcs_rx_intstatus.bf.lanealignstatusS;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEAMSTATUSS):
    rtn = tmp_pcs_rx_intstatus.bf.laneamstatusS;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK3S):
    rtn = tmp_pcs_rx_intstatus.bf.laneblocklock3S;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK2S):
    rtn = tmp_pcs_rx_intstatus.bf.laneblocklock2S;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK1S):
    rtn = tmp_pcs_rx_intstatus.bf.laneblocklock1S;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCK0S):
    rtn = tmp_pcs_rx_intstatus.bf.laneblocklock0S;
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCKXS):
    rtn = ((tmp_pcs_rx_intstatus.bf.laneblocklock3S<<3) |
           (tmp_pcs_rx_intstatus.bf.laneblocklock2S<<2) |
           (tmp_pcs_rx_intstatus.bf.laneblocklock1S<<1) |
           (tmp_pcs_rx_intstatus.bf.laneblocklock0S));
    break;

  case (TEN_PP40G_PCS_RX_INTSTATUS_SELECT_ALL):
    rtn = tmp_pcs_rx_intstatus.wrd;
    break;

  default:
    rtn = 0;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    break;
  }  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PCS RX SKEWSTATUS1 SKEW T41                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_pcs_rx_skewstatus1_skew_t41(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns PCS lane skew status register. Skew measurements can     */ 
/* only be made when lane alignment marker lock (laneamstatusS)     */
/* has been found and lane deskew is enabled.                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PCS_RX_SKEWSTATUS1_t tmp_pcs_rx_skewstatus1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_pcs_rx_skewstatus1.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, SKEWSTATUS1));
  return (tmp_pcs_rx_skewstatus1.bf.skew);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PCS RX SKEWSTATUS2 LN LAST T41             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_pcs_rx_skewstatus2_ln_last_t41(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns PCS lane skew status register. Skew measurements         */
/* can only be made when lane alignment marker lock (laneamstatusS) */
/* has been found and lane deskew is enabled.                       */
/* Reports the electrical lane number that is lagging the most in   */
/* the latest skew measurement reported in SKEWSTATUS1[skew[13:0]]. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PCS_RX_SKEWSTATUS2_t tmp_pcs_rx_skewstatus2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_pcs_rx_skewstatus2.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, SKEWSTATUS2));
  return (tmp_pcs_rx_skewstatus2.bf.ln_last);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PCS RX SKEWSTATUS2 LN FIRST T41            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_pcs_rx_skewstatus2_ln_first_t41(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns PCS lane skew status register. Skew measurements         */
/* can only be made when lane alignment marker lock (laneamstatusS) */
/* has been found and lane deskew is enabled.                       */
/* Reports the electrical lane number that is the most advanced in  */
/* the latest skew measurement reported in SKEWSTATUS1[skew[13:0]]. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PCS_RX_SKEWSTATUS2_t tmp_pcs_rx_skewstatus2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_pcs_rx_skewstatus2.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, SKEWSTATUS2));
  return (tmp_pcs_rx_skewstatus2.bf.ln_first);
}
  
/********************************************************************/
/* $rtn_hdr_start  PP40G RS RX INTSTATUS T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_rs_rx_intstatus_t41(cs_uint16 module_id, 
                                        cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns RS interrupt status register for the receive direction.  */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP40G_RS_RX_INTSTATUS_SELECT_RFS                 1       */
/*     TEN_PP40G_RS_RX_INTSTATUS_SELECT_LFS                 2       */
/*     TEN_PP40G_RS_RX_INTSTATUS_SELECT_UNKNOWNORDS         3       */
/*     TEN_PP40G_RS_RX_INTSTATUS_SELECT_REMOTEORDS          4       */
/*     TEN_PP40G_RS_RX_INTSTATUS_SELECT_LOCALORDS           5       */
/*     TEN_PP40G_RS_RX_INTSTATUS_SELECT_ALL              0xFF       */
/*       (entire 16 bit register word at once).                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_RS_RX_INTSTATUS_t tmp_rs_rx_intstatus;
  cs_uint16 rtn;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_rs_rx_intstatus.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_INTSTATUS));
  
  switch (select) {
  case (TEN_PP40G_RS_RX_INTSTATUS_SELECT_RFS):
    rtn = tmp_rs_rx_intstatus.bf.rfS;
    break;

  case (TEN_PP40G_RS_RX_INTSTATUS_SELECT_LFS):
    rtn = tmp_rs_rx_intstatus.bf.lfS;
    break;

  case (TEN_PP40G_RS_RX_INTSTATUS_SELECT_UNKNOWNORDS):
    rtn = tmp_rs_rx_intstatus.bf.unknownordS;
    break;

  case (TEN_PP40G_RS_RX_INTSTATUS_SELECT_REMOTEORDS):
    rtn = tmp_rs_rx_intstatus.bf.remoteordS;
    break;

  case (TEN_PP40G_RS_RX_INTSTATUS_SELECT_LOCALORDS):
    rtn = tmp_rs_rx_intstatus.bf.localordS;
    break;

  case (TEN_PP40G_RS_RX_INTSTATUS_SELECT_ALL):
    rtn = tmp_rs_rx_intstatus.wrd;
    break;

  default:
    rtn = 0;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PCS TX INTSTATUS T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_pcs_tx_intstatus_t41(cs_uint16 module_id, 
                                         cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns PCS interrupt status register for the transmit direction */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP40G_PCS_TX_INTSTATUS_SELECT_IDLE_REQS           1      */
/*     TEN_PP40G_PCS_TX_INTSTATUS_SELECT_RF_REQS             2      */
/*     TEN_PP40G_PCS_TX_INTSTATUS_SELECT_LF_REQS             3      */
/*     TEN_PP40G_PCS_TX_INTSTATUS_SELECT_ALL              0xFF      */
/*       (entire 16 bit register word at once).                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PCS_TX_INTSTATUS_t tmp_pcs_tx_intstatus;
  cs_uint16 rtn;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  tmp_pcs_tx_intstatus.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_INTSTATUS));
  
  switch (select) {
  case (TEN_PP40G_PCS_TX_INTSTATUS_SELECT_IDLE_REQS):
    rtn = tmp_pcs_tx_intstatus.bf.idle_reqS;
    break;

  case (TEN_PP40G_PCS_TX_INTSTATUS_SELECT_RF_REQS):
    rtn = tmp_pcs_tx_intstatus.bf.rf_reqS;
    break;

  case (TEN_PP40G_PCS_TX_INTSTATUS_SELECT_LF_REQS):
    rtn = tmp_pcs_tx_intstatus.bf.lf_reqS;
    break;

  case (TEN_PP40G_PCS_TX_INTSTATUS_SELECT_ALL):
    rtn = tmp_pcs_tx_intstatus.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = 0;
    break;
  }
  return (rtn);
}
  
/********************************************************************/
/* $rtn_hdr_start  PP40G PM CLEAR T41                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_pm_clear_t41(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Initiates the PP40G PM clear process.                            */
/* Waits for pm_clear bit to self-clears when the                   */
/* operation is done.  This applies to CTRL[mode]=IEEE.             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_PP40G_PM_CLEAR_t tmp_pm_clear;
  cs_uint32 msec_elapsed = 0;
  
  /* Bugzilla #   , suspend logging information during stats clear */
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  if (TEN_MOD_COMMON_VALIDATE_INTERNAL(module_id, &pDev) == CS_ERROR) {
    g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
    return (CS_ERROR);
  }
  
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pm_clear.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CLEAR));
  tmp_pm_clear.bf.clear = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CLEAR), tmp_pm_clear.wrd);

  /* wait for self-clear */
  do {
    TEN_MDELAY(TEN_PP10G_MSEC_DELAY);
    msec_elapsed += TEN_PP10G_MSEC_DELAY;
    if (msec_elapsed >= TEN_PP10G_MSEC_TIMEOUT) {
      /* CS_HNDL_ERROR(module_id, ETEN_MOD_REG_ACCESS_TIMEOUT, ": timeout waiting for pp40g pm_clear."); */
      rtn = CS_ERROR;
      break;
    }
    tmp_pm_clear.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CLEAR));
  } while (tmp_pm_clear.bf.clear);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURES THE PP40G PACKET BERT PROTOCOL    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_set_pbert_protocol_t41(cs_uint16          module_id,
                                           ten_xcon_da_type_t da_type)
/* INPUTS     : o Module Id                                     */
/*              o Detination Address Type                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the TX/RX PP40G PACKET BERT protocol settings.    */
/*                                                              */
/* The [da_type)] parameter is specified as:                    */
/*   0 = XCON_DA_UCAST                                          */
/*   1 = XCON_DA_MCAST                                          */
/*   2 = XCON_DA_BCAST                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_PBERT40G_TX_CNTRL_t tmp_pp40g_pbert40g_tx_cntrl;
  T41_t *pDev = NULL;


  /* Parameter Checking */
  if(da_type > 2) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, 
                  ": ten_pp40g_set_pbert_protocol_t41 da_type"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  tmp_pp40g_pbert40g_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pbert40g_tx_CNTRL));
  tmp_pp40g_pbert40g_tx_cntrl.bf.eth_da = da_type;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pbert40g_tx_CNTRL), tmp_pp40g_pbert40g_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP40G PBERT ENABLE SEQUENCE NUMBER INSERT    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_pbert_insert_seq_num_t41(cs_uint16 module_id,
                                             cs_ctl_t  ctl)
/* INPUTS     : o Module Id                                     */
/*              o Enable Sequence Number in First Two Payload   */
/*                Octets                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable 16-bit sequence number insertion into first two       */
/* payload bytes.                                               */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_PBERT40G_TX_CNTRL_t tmp_pp40g_pbert40g_tx_cntrl;
  T41_t *pDev = NULL;


  /* Parameter Checking */
  if(ctl > CS_ENABLE) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, 
                  ": ten_pp40g_control_pbert_frame_payload_t41 ctl"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  tmp_pp40g_pbert40g_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pbert40g_tx_CNTRL));
  tmp_pp40g_pbert40g_tx_cntrl.bf.seq_num = ctl;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pbert40g_tx_CNTRL), tmp_pp40g_pbert40g_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);}

/****************************************************************/
/* $rtn_hdr_start  CONTROL PP40H PACKET BERT LENGTHS            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_pbert_set_frame_length_t41(cs_uint16           module_id,
                                               ten_xcon_len_mode_t mode, 
                                               cs_uint16           mask,
                                               cs_uint16           min_len,
                                               cs_uint16           max_len,
                                               cs_uint8            typelength_lsb,
                                               cs_uint8            typelength_msb)
/* INPUTS     : o Module Id                                     */
/*              o Length Mode                                   */
/*              o Unit Length Mask value                        */
/*              o Minimum Octets Per Unit                       */
/*              o Maximum Octets Per Unit                       */
/*              o Type/Length Least Significant Byte            */
/*              o Type/Length Most Significant Byte             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the BERT TX unit length control where the word    */
/* *unit* is either a frame or an ordered set set by th API     */
/* ten_xcon_set_pbert_mode() traffic param                      */
/*                                                              */
/* The [mode] parameter specifies the unit length mode as:      */
/*   0 = XCON_UNIT_LEN_RANDOM                                   */
/*       Random unit length bound by MINLEN/MAXLEN/RNDMASK.     */
/*       The random unit length is generated by using 15 bits   */
/*       of a PRBS23. The 15 bits are masked by RNDMASK and then*/
/*       subjected to a MINLEN/MAXLEN filter.                   */
/*   1 = XCON_UNIT_LEN_LINEAR                                   */
/*       Incrementing unit length MINLEN -> MAXLEN              */
/*       (wrap-around to MINLEN)                                */
/*                                                              */
/* The [mask] parameter selects the random mask value and       */
/* applies only to RANDOM unit length mode                      */
/*   0 - 0x7FFF                                                 */
/*                                                              */
/* The [min_len] parameter selects the unit minimum length value*/
/* (number of octets per unit). For MODE[traffic]=OS unit       */
/* minimum length must satisfy 'minlen % 4 = 0'                 */
/* When ULEN[mode]=LIN, set MINLEN=MAXLEN for fixed length units*/
/*   0 - 0x7FFF                                                 */
/*                                                              */
/* The [max_len] paramter selects the unit maximum length value */
/* (number of octets per unit). For MODE[traffic]=OS, unit      */
/* maximum length must satisfy 'maxlen % 4 = 0'                 */ 
/* When ULEN[mode]=LIN, set MAXLEN=MINLEN for fixed length units*/
/*   0 - 0x7FFF                                                 */
/*                                                              */
/* The [typelength_lsb] parameter is specified as:              */
/*   0 - 0xFF                                                   */
/*                                                              */
/* The [typelength_msb] parameter is specified as:              */
/*   0 - 0xFF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_PBERT40G_TX_FRMLEN_t tmp_pp40g_pbert40g_tx_frmlen;
  TEN_PP40G_PBERT40G_TX_FRMLENMIN_t tmp_pp40g_pbert40g_tx_frmlenmin;
  TEN_PP40G_PBERT40G_TX_FRMLENMAX_t tmp_pp40g_pbert40g_tx_frmlenmax;
  TEN_PP40G_PBERT40G_TX_TYPELEN_t tmp_pp40g_pbert40g_tx_typelen;
  T41_t *pDev = NULL;


  /* Parameter Checking */
  if(mode > 1) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, 
                  ": ten_pp40g_control_pbert_unit_len_t41 mode"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_pp40g_pbert40g_tx_frmlen.wrd=0;     /* Bugzilla 30509, benign uninit'zed var, 2 lines */
  tmp_pp40g_pbert40g_tx_typelen.wrd=0;


  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  tmp_pp40g_pbert40g_tx_frmlen.bf.mode = mode;
  tmp_pp40g_pbert40g_tx_frmlen.bf.rndmask = mask;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FRMLEN), tmp_pp40g_pbert40g_tx_frmlen.wrd);

  tmp_pp40g_pbert40g_tx_frmlenmin.wrd = min_len;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FRMLENMIN), tmp_pp40g_pbert40g_tx_frmlenmin.wrd);

  tmp_pp40g_pbert40g_tx_frmlenmax.wrd = max_len;
  /* Bug 26717: FRMLENMIN was duplicated here, should be FRMLENMAX */
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FRMLENMAX), tmp_pp40g_pbert40g_tx_frmlenmax.wrd);

  tmp_pp40g_pbert40g_tx_typelen.bf.typelen1 = typelength_lsb;
  tmp_pp40g_pbert40g_tx_typelen.bf.typelen0 = typelength_msb;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, TYPELEN), tmp_pp40g_pbert40g_tx_typelen.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);


  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP40G PACKET BERT TRAFFIC CONTROL            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_pbert_control_traffic_t41(cs_uint16 module_id,
                                              cs_uint16 units)
/* INPUTS     : o Module Id                                     */
/*              o Number of Frames or Packets                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the number of units where the unit is either      */
/* a frame or an ordered set.                                   */
/*                                                              */
/* The [units] parameter selects number of units specified as:  */ 
/*   0 = Continuous traffic                                     */
/*   1 - 0xFFFF units                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_PBERT40G_TX_FRMCNTRL_t tmp_pp40g_pbert40g_tx_frmcntrl;
  T41_t *pDev = NULL;


  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  tmp_pp40g_pbert40g_tx_frmcntrl.wrd = units;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FRMCNTRL), tmp_pp40g_pbert40g_tx_frmcntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURES THE PP40GPACKET BERT FIXED PATTERN*/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_pbert_select_fixed_pattern_t41(cs_uint16                module_id,
                                                   ten_xcon_fixed_pattern_t type,
                                                   cs_uint8                 value_n,
                                                   cs_uint8                 value_n_plus_1)
/* INPUTS     : o Module Id                                     */
/*              o Pattern Type                                  */
/*              o Pattern Value fpatN                           */
/*              o Pattern Value fpatN+1                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the PP40G BERT TX/RX fixed patterns               */
/*                                                              */
/* The [type] parameter specifies the pattern type as:          */
/*   0 = XCON_FIXED_PATTERN_01                                  */
/*   1 = XCON_FIXED_PATTERN_23                                  */
/*                                                              */
/* The [value_n] parameter specifies the fixed pattrern N value */
/* where N = 0,2,4,6                                            */
/*   0 - 0xFF                                                   */
/*                                                              */
/* The [value_n_plus_1] parameter specifies the fixed pattrern  */
/* N+1 value where N=1,3,5,7                                    */
/*   0 - 0xFF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_PBERT40G_TX_FPAT01_t tmp_pp40g_pbert40g_tx_fpat01;
  TEN_PP40G_PBERT40G_TX_FPAT23_t tmp_pp40g_pbert40g_tx_fpat23;
  T41_t *pDev = NULL;


  /* Parameter Checking */
  if(type > 1) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, 
                  ": ten_pp40g_pbert_select_fixed_pattern_t41 type"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_pp40g_pbert40g_tx_fpat01.wrd=0; /* Bugzilla 30509, splint, benign uninit'zed var, 2 lines */
  tmp_pp40g_pbert40g_tx_fpat23.wrd=0;

  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  if (type == 0) {
    tmp_pp40g_pbert40g_tx_fpat01.bf.fpat0 = value_n;
    tmp_pp40g_pbert40g_tx_fpat01.bf.fpat1 = value_n_plus_1;
    TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FPAT01), tmp_pp40g_pbert40g_tx_fpat01.wrd);
  }
  else {
    tmp_pp40g_pbert40g_tx_fpat23.bf.fpat2 = value_n;
    tmp_pp40g_pbert40g_tx_fpat23.bf.fpat3 = value_n_plus_1;
    TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FPAT23), tmp_pp40g_pbert40g_tx_fpat23.wrd);
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  START/STOP PP40G PACKET BERT GENERATOR       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_pbert_control_generator_t41(cs_uint16 module_id,
                                                cs_ctl_t  ctl)
/* INPUTS     : o Module Id                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Start/Stop the PP40G PACKET BERT generator.                  */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_PBERT40G_TX_GO_t tmp_pp40g_pbert40g_tx_go;
  T41_t *pDev = NULL;


  /* Parameter Checking */
  if(ctl > CS_ENABLE) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, 
                  ": ten_pp40g_pbert_control_generator_t41 ctl"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  tmp_pp40g_pbert40g_tx_go.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, GO));
  tmp_pp40g_pbert40g_tx_go.bf.go = ctl;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, GO), tmp_pp40g_pbert40g_tx_go.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON PP40G PBERT TX RESET                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_pbert_tx_reset_t41(cs_uint16         module_id,
                                       cs_reset_action_t act)
/* INPUTS     : o Module Id                                     */
/*              o Action                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Resets the TX PBERT.                                         */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   CS_RESET_DEASSERT                                          */
/*   CS_RESET_ASSERT                                            */
/*   CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_PBERT40G_TX_CNTRL_t tmp_pp40g_pbert40g_tx_cntrl;
  T41_t *pDev = NULL;


  /* Parameter Checking */
  if (act > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, 
                  ": ten_pp40g_pbert_tx_reset_t41 act");
    return (CS_ERROR); 
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_pp40g_pbert40g_tx_cntrl.wrd=0; /* Bugzilla 30509, splint, benign uninit'd complaint */

  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  tmp_pp40g_pbert40g_tx_cntrl.bf.tx_rst = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, pbert40g_tx_CNTRL), tmp_pp40g_pbert40g_tx_cntrl.wrd, act);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP40G PACKET BERT GENERATOR INTERFRAME GAP   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_pbert_control_ifg_t41(cs_uint16 module_id,
                                          cs_uint8  ifg)
/* INPUTS     : o Module Id                                     */
/*              o Count                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the PP40G PBERT IFG.                                     */
/*                                                              */
/* The [ifg] parameter is specified as:                         */
/*   0x00..0xFF                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_PBERT40G_TX_TX_IFG_t tmp_pp40g_pbert40g_tx_ifg;
  T41_t *pDev = NULL;


  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_pp40g_pbert40g_tx_ifg.wrd=0;  /* Bugzilla 30509, splint, benign uninit'd complaint */

  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  tmp_pp40g_pbert40g_tx_ifg.bf.cnt = ifg;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, TX_IFG), tmp_pp40g_pbert40g_tx_ifg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURES PP40G PBERT ERROR INSERTION       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_pbert_inject_err_t41(cs_uint16             module_id,
                                         ten_xcon_error_type_t err_type, 
                                         cs_uint16             frames)
/* INPUTS     : o Module Id                                     */
/*              o Single or Continuous                          */
/*              o Frames                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the PP40G BERT TX/RX fixed patterns               */
/*                                                              */
/* The [err_type] parameter specifies the pattern type as:      */
/*   2 = XCON_CONTINUOUS_FCS_ERROR                              */
/*   3 = XCON_SINGLE_FCS_ERROR                                  */
/*                                                              */
/* The [frames] parameter selects number of units specified as:  */ 
/*   0 = Continuous traffic                                     */
/*   1 - 0xFFFF units                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_PBERT40G_TX_ERRINS_CONT_t tmp_pp40g_pbert40g_tx_errins_cont;
  TEN_PP40G_PBERT40G_TX_ERRINS_SGL_t  tmp_pp40g_pbert40g_tx_errins_sgl;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((err_type < XCON_CONTINUOUS_FCS_ERROR) || (err_type > XCON_SINGLE_FCS_ERROR)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, 
                  ": ten_pp40g_pbert_inject_err_t41 err_type"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_pp40g_pbert40g_tx_errins_cont.wrd=0;  /* Bugzilla 30509, splint, benign uninit'd var */
  tmp_pp40g_pbert40g_tx_errins_sgl.wrd=0;   /* complaints, 2 lines.                        */

  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  if (err_type == XCON_CONTINUOUS_FCS_ERROR) {
    tmp_pp40g_pbert40g_tx_errins_cont.bf.fcs_errc = frames;
    TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, ERRINS_CONT), tmp_pp40g_pbert40g_tx_errins_cont.wrd);
  }
  else if (err_type == XCON_SINGLE_FCS_ERROR) {
    tmp_pp40g_pbert40g_tx_errins_sgl.bf.fcs_errs = frames;
    TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, ERRINS_SGL), tmp_pp40g_pbert40g_tx_errins_sgl.wrd);
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURES PP40G RX BYPASS DESKEW ENABLE     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_rx_bypass_dsk_en_t41(cs_uint16  module_id,
                                         cs_uint16  rx_dsk_en)
/* INPUTS     : o Module Id                                     */
/*              o RX Deskew Enable                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables receive bypass path 40G deskew. When rx_dsk_en is    */
/* enabled, the four 10G datapaths from the receive N10G        */
/* interfaces are deskewed to remove skew introduced by the a   */
/* synchronous boundary within each N10G. Note that the deskew  */
/* must only be enabled for 40G monolithic traffic through      */
/* the receive bypass path. For all other traffic, rx_dsk_en    */
/* must be disabled. The deskewer only operates on the receive  */
/* bypass path which requires the rx_bypass bit to be enabled.  */
/* The interleaving mode of the traffic is selected with        */
/* rx_dsk_mode. The clken_dsk clock enable bit in the           */
/* PP40G_MISC_CLKEN register must be set before rx_dsk_en       */
/* is enabled for proper reset of the deskewer.                 */
/*                                                              */
/* The [rx_dsk_en] parameter is specified as:                   */ 
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_pp40g_rx_bypass_dsk_en_t41";  

  /* Parameter Checking */
  if(rx_dsk_en > CS_ENABLE) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() rx_dsk_en %d is out of range", func, rx_dsk_en); 
    return CS_ERROR; 
  }
  CS_PRINT("%s() %s, rx_dsk_en=%d\n", func, ten_module_strings[module_id & 1], rx_dsk_en);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_dsk_en = rx_dsk_en;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP40G IS BYPASSED                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_boolean ten_pp40g_is_bypassed_t41(cs_uint16  module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE (PP40G RX BYPASS is enabled) or FALSE      */
/* DESCRIPTION:                                                 */
/* Returns TRUE when TEN_PP40G_MISC_BYPASS.rx_bypass is 1.      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));

  return (tmp_pp40g_misc_bypass.bf.rx_bypass == 1);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE PP40G PACKET BERT GENERATOR   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP40G                                           */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_pbert_enable_t41(cs_uint16 module_id,
                                     cs_ctl_t  ctl)
/* INPUTS     : o Module Id                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable/Disable the PP40G PACKET BERT generator.              */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_pp40g_misc_tx_funcen;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  T41_t *pDev = NULL;


  /* Parameter Checking */
  if(ctl > CS_ENABLE) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, 
                  ": ten_pp40g_pbert_enable_t41 ctl"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  /* Enable clock */
  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  tmp_pp40g_misc_tx_clken.bf.clken_pbt = ctl;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* Enable PBERT */
  tmp_pp40g_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  tmp_pp40g_misc_tx_funcen.bf.fen_pbt = ctl;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/* Bugzilla 27126 Start */
/********************************************************************/
/* $rtn_hdr_start  PP40G RESET ALL SUBBLOCKS T41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_reset_all_subblocks_t41(cs_uint16 module_id, 
                                            cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Toggle all of the clock resets so that all errors will clear.    */
/* Toggle clock resets one at a time to prevent a power spike       */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_RX_CLKEN_t tmp_pp40g_misc_rx_clken;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  T41_t *pDev = NULL;
  /* Bug 27496: commented out variables associated with if 0 to stop compiler warnings */
  /* TEN_PP40G_PCS_RX_CNTRL_t tmp_pp40g_pcs_rx_cntrl; */
  /* TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl; */
  cs_char8 *func = "ten_pp40g_reset_all_subblocks_t41";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  if (act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() act %d > CS_RESET_TOGGLE out of range.  s/b 0..2.", func, act);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s\n", func, ten_module_strings[module_id & 1], ten_reset_act_strings[act]);

  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  
  
  /* Turn on PP40G Misc clocks */
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 1;
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  tmp_pp40g_misc_clken.bf.clken_dsk = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  tmp_pp40g_misc_clken.bf.clken_dsk = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

 #if 0
  tmp_pp40g_pcs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_CNTRL));
  /*CS_PRINT("%s() pp40g_pcs_rx_cntrl rxrst = %d\n", func, tmp_pp40g_pcs_rx_cntrl.bf.rxrst);*/
  tmp_pp40g_pcs_rx_cntrl.bf.rxrst = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_CNTRL), tmp_pp40g_pcs_rx_cntrl.wrd);

  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.tx_rst = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);
 #endif

  
  /* Toggle PP40G Misc RX clocks one at a time */
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_lif = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_dil = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_lba = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_lds = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_lro = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_mba = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_xdc = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_bds = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_bdc = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_tpc = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_nra = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_rs = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  tmp_pp40g_misc_rx_clken.wrd = 0;
  tmp_pp40g_misc_rx_clken.bf.clken_mac = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd, act);
  
  /* Toggle PP40G Misc TX clocks one at a time */
  tmp_pp40g_misc_tx_clken.wrd = 0;
  tmp_pp40g_misc_tx_clken.bf.clken_pbt = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd, act);
  tmp_pp40g_misc_tx_clken.wrd = 0;
  tmp_pp40g_misc_tx_clken.bf.clken_pra = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd, act);
  tmp_pp40g_misc_tx_clken.wrd = 0;
  tmp_pp40g_misc_tx_clken.bf.clken_bdb = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd, act);
  tmp_pp40g_misc_tx_clken.wrd = 0;
  tmp_pp40g_misc_tx_clken.bf.clken_mgb = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd, act);
  tmp_pp40g_misc_tx_clken.wrd = 0;
  tmp_pp40g_misc_tx_clken.bf.clken_xec = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd, act);
  tmp_pp40g_misc_tx_clken.wrd = 0;
  tmp_pp40g_misc_tx_clken.bf.clken_fpg = 1;
  ten_reset_action(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}
/* Bugzilla 27126 End */

/********************************************************************/
/* $rtn_hdr_start  PP40G PCS RX BERTIMER CALCULATE PERIOD           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_pcs_rx_bertimer_calculate_period(cs_uint16 module_id, 
                                                     cs_uint16 sys_clk,
                                                     cs_uint16 timer_period,
                                                     cs_int16  range_percentage)
/* INPUTS     : o Module Id                                         */
/*              o Sys Clock                                         */
/*              o PP40G Mode                                        */
/*              o Percentage Range                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Calculates and sets the period of the BER timer.                 */
/*                                                                  */
/* [sysclk] parameter specifies the sysclk frequency in MHz.        */
/*   For example, 400.                                              */
/*   NOTE:  sys_clk values less than 200 are multiplied by 4 to     */
/*          use internal clock, not external clock.                 */
/*                                                                  */
/* [timer_period] parameter is specified as:                        */
/*   1250(us) = Serial/parallel 40GE                                */
/*   1250(us) = Serial 64b/66b                                      */
/*    250(us) = 1024b/1027b                                         */
/*                                                                  */
/* [range_percentage] modifies the period.  This parameter can      */
/*  be from +1% to -25%.  For example, the period can be 25%        */
/*  smaller, which makes the check optimistic, ie, less likely to   */
/*  trigger at the same rate due to fewer errors accumulated.       */ 
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 internal_sysclk;
  cs_uint32 timer_value;
  cs_status rtn = CS_OK;
  double timer_period_double;
  
  CS_PRINT("ten_pp40g_pcs_rx_bertimer_calculate_period\n");
  
  if ((range_percentage < (-25)) || (range_percentage > 1)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "range percentage s/b -25%..+1%.");
    return (CS_ERROR);
  }
  
  if (sys_clk < 200) {
    internal_sysclk = sys_clk * 4;
  }
  else {
     internal_sysclk = sys_clk;
  }

  CS_PRINT("internal_sysclk  = %d\n", internal_sysclk);
  CS_PRINT("timer_period     = %d\n", timer_period);
  if (range_percentage != 0) {
    timer_period_double = (range_percentage/100.0) * timer_period;
    timer_period_double += timer_period;
    timer_period_double += 0.5;
    timer_period = (cs_uint16)timer_period_double;
    CS_PRINT("adj timer_period = %d\n", timer_period);
  }

  /* Provision PCS RX BER Timer */
  timer_value = ((timer_period * internal_sysclk) - 1) / 32;
  CS_PRINT("timer_value = %d, 0x%04X\n", timer_value, timer_value);

  rtn |= ten_pp40g_pcs_rx_bertimer(module_id, (cs_uint16)timer_value);
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G PCS RX BERTIMER                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_pcs_rx_bertimer(cs_uint16 module_id, 
                                    cs_uint16 timer_value)
/* INPUTS     : o Module Id                                         */
/*              o Timer Value                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Determines the period of the BER timer.                          */
/*                                                                  */
/* [timer_value]                                                    */
/*   This timer value is used by the BER monitors in the            */
/*   serial/parallel 40GE, serial 64b/66b and 1024b/1027b           */
/*   receive paths.                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP40G_PCS_RX_BERTIMER_t tmp_pcs_rx_bertimer;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pcs_rx_bertimer.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BERTIMER));
  tmp_pcs_rx_bertimer.bf.timer_value = timer_value;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BERTIMER), tmp_pcs_rx_bertimer.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}




/********************************************************************/
/* Function: ten_get_pp40g_reg_addr()                               */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a pp40g register.                            */
/*                                                                  */
/* Used by macro TEN_PP40G_REG_ADDR. Given the base address of a    */
/* non-common pp40g register as defined in t41_registers.h, and     */
/* its instance number (0..TEN_PP40G_COUNT-1), calculates the       */
/* offset and adds it to the base register's address.               */
/********************************************************************/
volatile cs_reg *ten_get_pp40g_reg_addr( cs_reg  *pReg,
                                                  cs_uint16 instance )
{
  if (instance >= TEN_PP40G_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "pp40g instance %d out of range. S/b < TEN_PP40G_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_PP40G_STRIDE);
}


/********************************************************************/
/* $rtn_hdr_start  PP40G GET MISC INTERRUPT RX DSK SYNCI T41        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_get_misc_interrupt_rx_dsk_synci_t41(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/*              o Rx Dsk SyncI                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Synci                                               */
/* DESCRIPTION:                                                     */
/* When asserted, this bit indicates a change in synchronization    */
/* status of the receive bypass 40G deskew block. The current       */
/* deskew status is available in the PP40G_MISC_INTSTATUS register. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_PP40G_MISC_INTERRUPT_t tmp_misc_interrupt;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_misc_interrupt.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_INTERRUPT));
  return (tmp_misc_interrupt.bf.rx_dsk_syncI);
}


/********************************************************************/
/* $rtn_hdr_start  PP40G SET MISC INTERRUPT X DSK SYNCI T41         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp40g_misc_interrupt_rx_dsk_synci_t41(cs_uint16 module_id, 
                                                    cs_uint16 rx_dsk_synci) 
/* INPUTS     : o Module Id                                         */
/*              o Rx Dsk SyncI                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Write 1 to clear rx_dsk_synci.                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_PP40G_MISC_INTERRUPT_t tmp_misc_interrupt;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_misc_interrupt.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_INTERRUPT));
  tmp_misc_interrupt.bf.rx_dsk_syncI = rx_dsk_synci;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_INTERRUPT), tmp_misc_interrupt.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G GET MISC TX FUNCEN PBT                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_get_misc_tx_funcen_pbt(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=PBERT functional enable, 0=disabled               */
/* DESCRIPTION:                                                     */
/* Returns the current state of fen_pbt (PBERT functional enable).  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_misc_tx_funcen;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  return (tmp_misc_tx_funcen.bf.fen_pbt);
}

/********************************************************************/
/* $rtn_hdr_start  PP40G GET MISC TX CLKEN PBT                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP40G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp40g_misc_tx_clken_pbt(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=PBERT clock enable, 0=disabled                    */
/* DESCRIPTION:                                                     */
/* Returns the current state of clken_pbt (PBERT clock enable).     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_misc_tx_clken;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  return (tmp_misc_tx_clken.bf.clken_pbt);
}

/******************************************************************************/
/* $rtn_hdr_start   PP40G_SET_PP40G_MPIF_RESET                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_set_pp40g_mpif_reset_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Remove PP40G MPIF reset                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RESET_t tmp_pp40g_misc_reset;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_reset.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, RESET));
  tmp_pp40g_misc_reset.bf.mpif_rst = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), tmp_pp40g_misc_reset.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_MISC_CLKEN CLEAR                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_misc_clken_clear(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/* Deassert PP40G TX/RX clock enables.                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 0;
  tmp_pp40g_misc_clken.bf.clken_tx = 0;
  tmp_pp40g_misc_clken.bf.clken_pm = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}





