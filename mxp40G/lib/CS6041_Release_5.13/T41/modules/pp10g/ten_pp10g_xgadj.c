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
 * ten_pp10g_xgadj.c
 *
 * $Id: ten_pp10g_xgadj.c,v 1.12 2014/04/03 20:02:58 jccarlis Exp $
 *
 * API's for PP10G XGADJ
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX RESET                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_reset(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control XGADJ sub-block logic tx reset.                          */
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
  TEN_PP10G_XGADJ_TX_RESET_t tmp_xgadj_tx_reset;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_reset.wrd = 0;
      tmp_xgadj_tx_reset.bf.txrst = 1;
      ten_reset_action(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, tx_RESET), 
                       tmp_xgadj_tx_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX SET CONTROL                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_set_control(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 maxsize_truncate, 
                                cs_uint16 xcon_disable, 
                                cs_uint16 insert_disable, 
                                cs_uint16 translate, 
                                cs_uint16 profile, 
                                cs_uint16 sfd_check, 
                                cs_uint16 append_fcs, 
                                cs_uint16 insert_append_fcs)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Maxsize Truncate                                  */
/*              o Xcon Disable                                      */
/*              o Insert Disable                                    */
/*              o Translate                                         */
/*              o Profile                                           */
/*              o Sfd Check                                         */
/*              o Append Fcs                                        */
/*              o Insert Append Fcs                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures various aspects of the transmit direction behaviour   */
/* for xgadj tx functions.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [maxsize_truncate]  Set this configuration bit to enable       */
/*     packet truncation                                            */
/*                                                                  */
/*   [xcon_disable]  Set this bit to prevent the cross-connect      */
/*     from forwarding to the transmit PP10G.                       */
/*                                                                  */
/*   [insert_disable]  Set this bit to prevent the transmission of  */
/*     frames inserted at xgadj.                                    */
/*                                                                  */
/*   [translate]  Set this bit when the upstream client signal      */
/*     path (transitting an upstream PP10G) receives standard GFP-F */
/*     and this PP10G transmits Ethernet frames.                    */
/*                                                                  */
/*   [profile]  Identify the client signal profile employed by the  */
/*     data path through the transmit PP10G.                        */
/*                                                                  */
/*   [sfd_check]  The optional Start-of-Frame-Delimiter check       */
/*     applies only to Ethernet frames.                             */
/*                                                                  */
/*   [append_fcs]  Set this bit to direct the transmit direction    */
/*     Ethernet MAC to append an FCS to Ethernet packets            */
/*                                                                  */
/*   [insert_append_fcs]  Set this bit to direct the transmit       */
/*     direction Ethernet MAC to append an FCS to frames inserted   */
/*     for transmission.                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_TX_CNTRL0_t tmp_xgadj_tx_cntrl0;
  TEN_PP10G_XGADJ_TX_CNTRL1_t tmp_xgadj_tx_cntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_cntrl0.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, CNTRL0));
      tmp_xgadj_tx_cntrl0.bf.maxsize_truncate = maxsize_truncate;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, CNTRL0), tmp_xgadj_tx_cntrl0.wrd);

      tmp_xgadj_tx_cntrl1.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, tx_CNTRL1));
      tmp_xgadj_tx_cntrl1.bf.xcon_disable = xcon_disable;
      tmp_xgadj_tx_cntrl1.bf.insert_disable = insert_disable;
      tmp_xgadj_tx_cntrl1.bf.translate = translate;
      tmp_xgadj_tx_cntrl1.bf.profile = profile;
      tmp_xgadj_tx_cntrl1.bf.sfd_check = sfd_check;
      tmp_xgadj_tx_cntrl1.bf.append_fcs = append_fcs;
      tmp_xgadj_tx_cntrl1.bf.insert_append_fcs = insert_append_fcs;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, tx_CNTRL1), tmp_xgadj_tx_cntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX SET CONTROL                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_set_control_insert_append_fcs(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 insert_append_fcs)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Insert Append Fcs                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures various aspects of the transmit direction behaviour   */
/* for xgadj tx functions.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [insert_append_fcs]  Set this bit to direct the transmit       */
/*     direction Ethernet MAC to append an FCS to frames inserted   */
/*     for transmission.                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_TX_CNTRL1_t tmp_xgadj_tx_cntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_cntrl1.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, tx_CNTRL1));
      tmp_xgadj_tx_cntrl1.bf.insert_append_fcs = insert_append_fcs;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, tx_CNTRL1), tmp_xgadj_tx_cntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX FILLCTRL                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_fillctrl(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 fill_enable, 
                                  cs_uint16 repeat_enable)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Fill Enable                                       */
/*              o Repeat Enable                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Identifies each lane or octet of the FILLDATA register as an     */
/* XGMII control code or an XGMII data code.                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [fill_enable]                                                  */
/*     Please note that the transmit MAC also is capable of         */
/*     inserting fill words.                                        */
/*     1 = enable Insert a fill word/column when data is not        */
/*         available.                                               */
/*     0 = disable Do not insert a fill word/column when data is    */
/*         not available. GFP-F transmission generally requires     */
/*         this setting.                                            */
/*                                                                  */
/*   [repeat_enable]                                                */
/*     The transmit direction rate adjust mechanism is capable of   */
/*     repeating the last observed four octet sequence when a fill  */
/*     word/column is required. A repeated fill word is possible    */
/*     under the following conditions. The last observed column was */
/*     within an interframe gap. The last observed column does      */
/*     not include a terminate control code. The last observed      */
/*     column does not include transparently carried codes. The     */
/*     last observed column is not a column within the following    */
/*     Fibre Channel train of columns: Idle, Idle, SYNx, SYNy,      */
/*     SYNz, Idle, Idle. The last observed column does not contain  */
/*     an error control code. All other interframe gap columns are  */
/*     eligible for repetition for the purpose of positive rate     */
/*     adjustment. The observation of an interframe gap column not  */
/*     meeting the above requirements results in the                */
/*     disqualification of the repeat column for positive rate      */
/*     adjustment. This condition continues until the observation   */
/*     of a column that meets the requirements. In the event that   */
/*     positive rate adjustment is required while a repeat column   */
/*     is unavailable, the positive rate adjustment mechanism falls */
/*     back to the insertion policy provided by the fill_enable     */
/*     configuration bit within this register. This repeat_enable   */
/*     configuration bit supercedes the fill_enable configuration   */
/*     bit. It is very likely that any configuration of the         */
/*     transmit data path sets both fill_enable and repeat_enable   */
/*     or clears both fill_enable and repeat_enable. The specific   */
/*     purpose of the this repeat_enable configuration bit is to    */
/*     replicate ordered sets indicating local fault or remote      */
/*     fault during periods when the upstream data path does not    */
/*     provide data.                                                */
/*     1 = enable Enable repetition of the last observed eligible   */
/*         column when performing positive rate adjustment if the   */
/*         last observed column is eligible.                        */
/*     0 = disable Do not repeat/insert the last observed eligible  */
/*         column when performing positive rate adjustment.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_TX_FILLCTRL_t tmp_xgadj_tx_fillctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_fillctrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, FILLCTRL));
      tmp_xgadj_tx_fillctrl.bf.fill_enable = fill_enable;
      tmp_xgadj_tx_fillctrl.bf.repeat_enable = repeat_enable;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, FILLCTRL), tmp_xgadj_tx_fillctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX FILLCTRL                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_set_xgadj_tx_fillctrl(cs_uint16 module_id,
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
/* Identifies each lane or octet of the FILLDATA register as an     */
/* XGMII control code or an XGMII data code.                        */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [select] parameter is specified as:                          */
/*   TEN_PP10G_XGADJ_FILLCTRL_FILL_CONTROL      = 3                 */
/*   TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE       = 2                 */
/*   TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE     = 1                 */
/*   TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT  = 0                 */
/*                                                                  */
/* The [value] parameter is specified as:                           */
/*   For select =  TEN_PP10G_XGADJ_FILLCTRL_FILL_CONTROL            */
/*     fill_control[3:0] This field identifies the target_data      */
/*     octets as XGMII control codes or XGMII data codes.           */
/*     xxx1 - Bits 7:0 are an XGMII control code                    */
/*     xxx0 - Bits 7:0 are an XGMII data code                       */
/*     xx1x - Bits 15:8 are an XGMII control code                   */
/*     xx0x - Bits 15:8 are an XGMII data code                      */
/*     x1xx - Bits 23:16 are an XGMII control code                  */
/*     x0xx - Bits 23:16 are an XGMII data code                     */
/*     1xxx - Bits 31:24 are an XGMII control code                  */
/*     0xxx - Bits 31:24 are an XGMII data code                     */
/*       1'h0 data XGMII data code.                                 */
/*       1'h1 control XGMII control code.                           */
/*                                                                  */
/*   For select =  TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE             */
/*     Please note that the transmit MAC also is capable of         */
/*     inserting fill words.                                        */
/*     1 = enable Insert a fill word/column when data is not        */
/*         available.                                               */
/*     0 = disable Do not insert a fill word/column when data is    */
/*         not available. GFP-F transmission generally requires     */
/*         this setting.                                            */
/*                                                                  */
/*   For select =  TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE           */
/*     The transmit direction rate adjust mechanism is capable of   */
/*     repeating the last observed four octet sequence when a fill  */
/*     word/column is required. A repeated fill word is possible    */
/*     under the following conditions. The last observed column was */
/*     within an interframe gap. The last observed column does      */
/*     not include a terminate control code. The last observed      */
/*     column does not include transparently carried codes. The     */
/*     last observed column is not a column within the following    */
/*     Fibre Channel train of columns: Idle, Idle, SYNx, SYNy,      */
/*     SYNz, Idle, Idle. The last observed column does not contain  */
/*     an error control code. All other interframe gap columns are  */
/*     eligible for repetition for the purpose of positive rate     */
/*     adjustment. The observation of an interframe gap column not  */
/*     meeting the above requirements results in the                */
/*     disqualification of the repeat column for positive rate      */
/*     adjustment. This condition continues until the observation   */
/*     of a column that meets the requirements. In the event that   */
/*     positive rate adjustment is required while a repeat column   */
/*     is unavailable, the positive rate adjustment mechanism falls */
/*     back to the insertion policy provided by the fill_enable     */
/*     configuration bit within this register. This repeat_enable   */
/*     configuration bit supercedes the fill_enable configuration   */
/*     bit. It is very likely that any configuration of the         */
/*     transmit data path sets both fill_enable and repeat_enable   */
/*     or clears both fill_enable and repeat_enable. The specific   */
/*     purpose of the this repeat_enable configuration bit is to    */
/*     replicate ordered sets indicating local fault or remote      */
/*     fault during periods when the upstream data path does not    */
/*     provide data.                                                */
/*     1 = enable Enable repetition of the last observed eligible   */
/*         column when performing positive rate adjustment if the   */
/*         last observed column is eligible.                        */
/*     0 = disable Do not repeat/insert the last observed eligible  */
/*         column when performing positive rate adjustment.         */
/*                                                                  */
/*   For select =  TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT        */
/*     max_fault_repeat[9:0] This field specifies the maximum       */
/*     number of times a qualified column may be repeated when the  */
/*     qualified column is a local fault or remote fault. Configure */
/*     this field with zero to indicate no limit for repeated local */
/*     faults and repeated remote faults. Number space 1-1023       */
/*     allows the specification of a corresponding number of        */
/*     repeated emissions of a local/remote fault. The column is    */
/*     disqualified once the specified number of repetitions has    */
/*     occurred. The time out counter is reloaded each time a       */
/*     qualified local/remote fault is encountered. The specific    */
/*     purpose of this field is to support GFP-F transparent to     */
/*     Ethernet mappings when the GFP-F link uses ordered sets to   */
/*     signal local/remote faults rather than the facility provided */
/*     through CMF. Without repetition of a local/remote fault, it  */
/*     is possible for the Ethernet link partner (at the far end of */
/*     the Ethernet link) to observe link fault flapping. However,  */
/*     it also is possible for the Ethernet link partner to         */
/*     incorrectly continue to receive local/remote faults long     */
/*     after the fault condition is lifted. For that reason, it is  */
/*     necessary to limit the extent of local/remote fault          */
/*     repetition through this time-out provision. Please recall    */
/*     that the GFP-F transparent to Ethernet mapping is not        */
/*     transparent to idle columns.                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_TX_FILLCTRL_t tmp_xgadj_tx_fillctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, 0xFF.");
    return(CS_ERROR);
  }
  if (select>TEN_PP10G_XGADJ_FILLCTRL_FILL_CONTROL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_fillctrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, FILLCTRL));
      if (select == TEN_PP10G_XGADJ_FILLCTRL_FILL_CONTROL) {
        tmp_xgadj_tx_fillctrl.bf.fill_control = value;
      }
      if (select == TEN_PP10G_XGADJ_FILLCTRL_FILL_ENABLE) {
        tmp_xgadj_tx_fillctrl.bf.fill_enable = value;
      }
      if (select == TEN_PP10G_XGADJ_FILLCTRL_REPEAT_ENABLE) {
        tmp_xgadj_tx_fillctrl.bf.repeat_enable = value;
      }
      if (select == TEN_PP10G_XGADJ_FILLCTRL_MAX_FAULT_REPEAT) {
        tmp_xgadj_tx_fillctrl.bf.max_fault_repeat = value;
      }
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, FILLCTRL), tmp_xgadj_tx_fillctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX FILLDATA                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_filldata(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 fill_data1,
                                       cs_uint16 fill_data0)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Fill Data1                                        */
/*              o Fill Data0                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Identifies fill column XGMII control or XGMII data codes.  The   */
/* fill column is used to provide data to the data path when no     */
/* other data is available from the cross-connect or insertion      */
/* buffer.                                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [fill_data1]  Each octet represents one XGMII control code or  */
/*     XGMII data code.                                             */
/*                                                                  */
/*   [fill_data0]  Each octet represents one XGMII control code or  */
/*     XGMII data code.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_TX_FILLDATA1_t tmp_xgadj_tx_filldata1;
  TEN_PP10G_XGADJ_TX_FILLDATA0_t tmp_xgadj_tx_filldata0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_filldata1.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, FILLDATA1));
      tmp_xgadj_tx_filldata1.bf.fill_data1 = fill_data1;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, FILLDATA1), tmp_xgadj_tx_filldata1.wrd);

      tmp_xgadj_tx_filldata0.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, FILLDATA0));
      tmp_xgadj_tx_filldata0.bf.fill_data0 = fill_data0;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, FILLDATA0), tmp_xgadj_tx_filldata0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX MAXFRAME                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_maxframe(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 maxsize1,
                                      cs_uint16 maxsize0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Maxsize1                                          */
/*              o Maxsize0                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the maximum frame size for transmission.  The transmit      */
/* direction frame size truncation feature applies only to          */
/* Ethernet frames.                                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [maxsize1]  more significant register                          */
/*                                                                  */
/*   [maxsize0]  less significant register.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_TX_MAXFRAME1_t tmp_xgadj_tx_maxframe1;
  TEN_PP10G_XGADJ_TX_MAXFRAME0_t tmp_xgadj_tx_maxframe0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_maxframe1.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, MAXFRAME1));
      tmp_xgadj_tx_maxframe1.bf.maxsize1 = maxsize1;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, MAXFRAME1), tmp_xgadj_tx_maxframe1.wrd);

      tmp_xgadj_tx_maxframe0.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, MAXFRAME0));
      tmp_xgadj_tx_maxframe0.bf.maxsize0 = maxsize0;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, MAXFRAME0), tmp_xgadj_tx_maxframe0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX GET STATUS                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_xgadj_tx_get_status(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Gets XGADJ status information.                                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP10G_XGADJ_TX_STATUS_UNDERFLOW           1              */
/*     TEN_PP10G_XGADJ_TX_STATUS_OVERFLOW            2              */
/*     TEN_PP10G_XGADJ_TX_STATUS_ALL  (whole reg)    0xFF.          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;
  TEN_PP10G_XGADJ_TX_STATUS_t tmp_xgadj_tx_status;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_xgadj_tx_status.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, tx_STATUS));
      
  switch (select) {
  case (TEN_PP10G_XGADJ_TX_STATUS_UNDERFLOW):
    rtn = tmp_xgadj_tx_status.bf.underflow;
    break;

  case (TEN_PP10G_XGADJ_TX_STATUS_OVERFLOW):
    rtn = tmp_xgadj_tx_status.bf.overflow;
    break;

  case (TEN_PP10G_XGADJ_TX_STATUS_ALL):
    rtn = tmp_xgadj_tx_status.wrd;
    break;
  
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX INSERT FLEN                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_insert_flen(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 flen)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Flen                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the length in octets of the frame written, and also         */
/* sets av to 1.                                                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [flen]  length in octets of the frame written to the           */
/*     Insertion Buffer.  Legal values are 14 octets - 256 octets.  */
/*     For GFP-F Transparent Ordered Set frames, legal values       */
/*     are 4 octets - 256 octets, evenly divisible by 4.            */
/*     Programming an illegal value, causes the INSERT[av] to be    */
/*     automatically cleared and the frame will not be transmitted. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_TX_INSERT_t tmp_xgadj_tx_insert;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if ((flen < 4) || (flen > 256)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": flen out of range.  s/b 4..256.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_insert.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT));
      tmp_xgadj_tx_insert.bf.av = 1;
      tmp_xgadj_tx_insert.bf.flen = flen;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT), tmp_xgadj_tx_insert.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX INSERT SET AV                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_insert_set_av(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o AV                                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets av=1.                                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [av]  When set, indicates that a frame in the insertion        */
/*     buffer is ready for transmission.  Hardware clears this      */
/*     bit once the frame has been transmitted. This bit is         */
/*     asserted by software and deasserted by hardware.             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_TX_INSERT_t tmp_xgadj_tx_insert;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_insert.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT));
      tmp_xgadj_tx_insert.bf.av = 1;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT), tmp_xgadj_tx_insert.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX INSERT GET AV                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_xgadj_tx_insert_get_av(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns the value of AV.  Hardware clears this bit once the      */
/* frame has been transmitted.  This bit is asserted by software    */
/* and deasserted by hardware.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), or TEN_SLICE3 (3).                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_XGADJ_TX_INSERT_t tmp_xgadj_tx_insert;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(1);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 1);
  tmp_xgadj_tx_insert.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, INSERT));
  return (tmp_xgadj_tx_insert.bf.av);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX INSERT ACCESS 0                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_insert_access_0(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 data_0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Data 0                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* The Insertion Buffer has 128 addressable locations (256 octets). */
/* When writing(reading) this register, the internal write/read     */
/* pointer is reset to the first location and that location is      */
/* written(read). The internal write/read pointer is automatically  */
/* advanced to the next location after the write(read) is done.     */
/* Subsequent write(read) operations are performed by               */
/* writing(reading) register INSERT_ACCESS_N.                       */ 
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [data_0]  octets.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      /*  Bug #41411 - ten_pp10g_xgadj_tx_insert_access_0/n should not read/modify/write */
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT_ACCESS_0), data_0);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX INSERT ACCESS N                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_insert_access_n(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 data_n)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Data N                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When writing(reading) this register, the location addressed by   */
/* the internal write/read pointer is written(read) and the         */
/* write/read pointer is automatically advanced to the next         */
/* location. The internal write/read pointer does not advance       */
/* beyond the end of the buffer.                                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [data_n]  octets.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      /*  Bug #41411 - ten_pp10g_xgadj_tx_insert_access_0/n should not read/modify/write */
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT_ACCESS_N), data_n);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ TX INSERT FRAME                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_insert_frame(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 frame_size, 
                                    cs_char8 *frame_octets)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Frame Size                                        */
/*              o Frame Octets                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Inserts octets.                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [frame_size]  number of octets                                 */
/*                                                                  */
/*   [frame_octets]  frame octets.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl, ii;
  cs_char8 *tmp_str;
  T41_t *pDev = NULL;
  cs_uint32 msec_elapsed = 0;
  cs_boolean waiting_for_clear;
  TEN_PP10G_XGADJ_TX_INSERT_t tmp_xgadj_tx_insert;
  TEN_PP10G_XGADJ_TX_INSERT_ACCESS_0_t tmp_xgadj_tx_insert_access_0;
  TEN_PP10G_XGADJ_TX_INSERT_ACCESS_N_t tmp_xgadj_tx_insert_access_n;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  if ((frame_size < 4) || (frame_size > 256)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": frame size out of range.  s/b 4..256.");
    return(CS_ERROR);
  }

  if (!frame_octets) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, ": frame octets is a null ptr.");
    /* bugzilla #24439, klocwork */
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
    
      /* program the frame octets */
      tmp_str = frame_octets;
      tmp_xgadj_tx_insert_access_0.wrd = *tmp_str;
      tmp_str++;
      
      /* Bugzilla #25564, fix for older compilers */
      tmp_xgadj_tx_insert_access_0.wrd = (tmp_xgadj_tx_insert_access_0.wrd & 0x00FF);
      tmp_xgadj_tx_insert_access_0.wrd |= (((*tmp_str)<<8)&0xFF00);
      tmp_str++;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT_ACCESS_0), tmp_xgadj_tx_insert_access_0.wrd);
      
      for (ii=2; ii<frame_size; ii+=2) {
          tmp_xgadj_tx_insert_access_n.wrd = *tmp_str;
          tmp_str++;
          if (ii+1 != frame_size) {
          
            /* Bugzilla #25564, fix for older compilers */
            tmp_xgadj_tx_insert_access_n.wrd = (tmp_xgadj_tx_insert_access_n.wrd & 0x00FF); 
            tmp_xgadj_tx_insert_access_n.wrd |= (((*tmp_str)<<8)&0xFF00);
          }
          tmp_str++;
          TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT_ACCESS_N), tmp_xgadj_tx_insert_access_n.wrd);
      }
      
      /* set length and insert frame */
      tmp_xgadj_tx_insert.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT));
      tmp_xgadj_tx_insert.bf.av = 1;
      tmp_xgadj_tx_insert.bf.flen = frame_size;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT), tmp_xgadj_tx_insert.wrd);
      
      /* the 'av' bit self clears when the operation is done */
      waiting_for_clear = TRUE;
      while (waiting_for_clear) {
        tmp_xgadj_tx_insert.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, INSERT));
        if (!tmp_xgadj_tx_insert.bf.av) {
           break;
        }   
        TEN_MDELAY(TEN_PP10G_MSEC_DELAY);
        msec_elapsed += TEN_PP10G_MSEC_DELAY;
        if (msec_elapsed >= TEN_PP10G_MSEC_TIMEOUT) {
          CS_HNDL_ERROR(module_id, ETEN_MOD_REG_ACCESS_TIMEOUT, ": timeout waiting for clear.");
          waiting_for_clear = FALSE;
          break;
        }
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RESET                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_reset(cs_uint16 module_id, cs_uint8 slice,
                                   cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control XGADJ sub-block logic rx reset.                          */
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
  TEN_PP10G_XGADJ_RX_RESET_t tmp_xgadj_rx_reset;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_reset.wrd = 0;
      tmp_xgadj_rx_reset.bf.rxrst = 1;
      ten_reset_action(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, rx_RESET), 
                       tmp_xgadj_rx_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX CONTROL                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_control(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 translate, 
                               cs_uint16 rx_profile, 
                               cs_uint16 tx_profile)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Translate                                         */
/*              o Rx Profile                                        */
/*              o Tx Profile                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls variouis aspects of the receive path through the        */
/* xgadj module.                                                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [translate]                                                    */
/*                                                                  */
/*   [rx_profile]                                                   */
/*                                                                  */
/*   [tx_profile]                                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_CNTRL_t tmp_xgadj_rx_cntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_cntrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, CNTRL));
      tmp_xgadj_rx_cntrl.bf.translate = translate;
      tmp_xgadj_rx_cntrl.bf.rx_profile = rx_profile;
      tmp_xgadj_rx_cntrl.bf.tx_profile = tx_profile;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, CNTRL), tmp_xgadj_rx_cntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATE CONTROL                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_rate_control(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_uint16 idle_all,
                                   cs_uint16 frames_all,
                                   cs_uint16 client_all,
                                   cs_uint16 seq_os_all,
                                   cs_uint16 seq_os_2nd, 
                                   cs_uint16 fc_idle)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Idle All                                          */
/*              o Frames All                                        */
/*              o Client All                                        */
/*              o Seq Os All                                        */
/*              o Seq Os 2nd                                        */
/*              o Fc Idle                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register controls aspects of the receive path through the   */
/* xgadj module, specifically those that control how to discard     */
/* specific data types in response to occupancy threshold           */
/* signalling from the associated elastic store.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [idle_all]                                                     */
/*     Set to drop all idle columns or all 64B/66B blocks           */
/*     consisting only of idle columns, applying the threshold      */
/*     defined by map_idle_all. Clear to disable drop function.     */
/*                                                                  */
/*   [frames_all]                                                   */
/*     Set to drop all frames, applying the threshold defined by    */
/*     map_frames_all. Frame drop is defined as the entire frame    */
/*     extending from the first preamble column to the associated   */
/*     terminate column. Clear to disable drop function.            */
/*                                                                  */
/*   [client_all]                                                   */
/*     Set to drop the entire client signal, applying the threshold */
/*     defined by map_client_all_hi/map_client_all_lo. If servicing */
/*     a frame, the frame will be aborted in a client signal aware  */
/*     fashion. Clear to disable drop function.                     */
/*                                                                  */
/*   [seq_os_all]                                                   */
/*     Set to drop all sequence ordered set columns or all 64B/66B  */
/*     blocks consisting only of sequence ordered sets, applying    */
/*     the threshold defined by map_idle_all. Clear to disable drop */
/*     function.                                                    */
/*                                                                  */
/*   [seq_os_2nd]                                                   */
/*     Set to drop every second consecutively observed sequence     */
/*     ordered set or every second consecutively observed 64B/66B   */
/*     block consisting only of sequence ordered sets, applying the */
/*     threshold defined by map_seq_os_2nd. Clear to disable drop   */
/*     function.                                                    */
/*                                                                  */
/*   [fc_idle]                                                      */
/*     Define whether the Fibre Channel receiver interprets an      */
/*     idle as a fill word.                                         */
/*     0 = NOT_FILL_WORD, Idle is not recognized as a fill word.    */
/*     1 = FILL_WORD, Idle is recognized as a fill word.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL_t tmp_xgadj_rx_ratecntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL));
      tmp_xgadj_rx_ratecntrl.bf.idle_all = idle_all;
      tmp_xgadj_rx_ratecntrl.bf.frames_all = frames_all;
      tmp_xgadj_rx_ratecntrl.bf.client_all = client_all;
      tmp_xgadj_rx_ratecntrl.bf.seq_os_all = seq_os_all;
      tmp_xgadj_rx_ratecntrl.bf.seq_os_2nd = seq_os_2nd;
      tmp_xgadj_rx_ratecntrl.bf.fc_idle = fc_idle;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL), tmp_xgadj_rx_ratecntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATE CONTROL FRAMES ALL           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_rate_control_frames_all(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_uint16 frames_all)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Frames All                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register controls aspects of the receive path through the   */
/* xgadj module, specifically those that control how to discard     */
/* specific data types in response to occupancy threshold           */
/* signalling from the associated elastic store.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [frames_all]                                                   */
/*     Set to drop all frames, applying the threshold defined by    */
/*     map_frames_all. Frame drop is defined as the entire frame    */
/*     extending from the first preamble column to the associated   */
/*     terminate column. Clear to disable drop function.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL_t tmp_xgadj_rx_ratecntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL));
      tmp_xgadj_rx_ratecntrl.bf.frames_all = frames_all;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL), tmp_xgadj_rx_ratecntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATE CONTROL CLIENT_ALL           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_client_all(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 client_all)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Client All                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register controls aspects of the receive path through the   */
/* xgadj module, specifically those that control how to discard     */
/* specific data types in response to occupancy threshold           */
/* signalling from the associated elastic store.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [client_all]                                                   */
/*     Set to drop the entire client signal, applying the threshold */
/*     defined by map_client_all_hi/map_client_all_lo. If servicing */
/*     a frame, the frame will be aborted in a client signal aware  */
/*     fashion. Clear to disable drop function.                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL_t tmp_xgadj_rx_ratecntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL));
      tmp_xgadj_rx_ratecntrl.bf.client_all = client_all;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL), tmp_xgadj_rx_ratecntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATE CONTROL SEQ_OS_ALL           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_seq_os_all(cs_uint16 module_id,
                                     cs_uint8 slice, 
                                     cs_uint16 seq_os_all)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Seq Os All                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register controls aspects of the receive path through the   */
/* xgadj module, specifically those that control how to discard     */
/* specific data types in response to occupancy threshold           */
/* signalling from the associated elastic store.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [seq_os_all]                                                   */
/*     Set to drop all sequence ordered set columns or all 64B/66B  */
/*     blocks consisting only of sequence ordered sets, applying    */
/*     the threshold defined by map_idle_all. Clear to disable drop */
/*     function.                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL_t tmp_xgadj_rx_ratecntrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL));
      tmp_xgadj_rx_ratecntrl.bf.seq_os_all = seq_os_all;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL), tmp_xgadj_rx_ratecntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATE CONTROL 1                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_rate_control1(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 map_idle_all, 
                                    cs_uint16 map_seq_os_2nd)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Map Idle All                                      */
/*              o Map Seq Os 2nd                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls additional various aspects of the receive path through  */
/* the xgadj module, specifically those that control how to         */
/* discard specific data types in response to occupancy threshold   */
/* signalling from the associated elastic store.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [map_idle_all]                                                 */
/*     Select the cross-connect elastic store threshold crossing    */
/*     level used to trigger the discard action described in        */
/*     idle_all.                                                    */
/*     3'd0 = THRESHOLD0, Cross-connect elastic store threshold     */
/*            crossing 0.                                           */
/*     3'd1 = THRESHOLD1, Cross-connect elastic store threshold     */
/*            crossing 1.                                           */
/*     3'd2 = THRESHOLD2, Cross-connect elastic store threshold     */
/*            crossing 2.                                           */
/*     3'd3 = THRESHOLD3, Cross-connect elastic store threshold     */
/*            crossing 3.                                           */
/*     3'd4 = THRESHOLD4, Cross-connect elastic store threshold     */
/*            crossing 4.                                           */
/*     3'd6 = NEVER, Select none of the cross-connect elastic store */
/*            threshold crossings; force operation under the        */
/*            condition of never being above threshold.             */
/*     3'd7 = ALWAYS, Select none of the cross-connect elastic      */
/*            store threshold crossings; force operation under the  */
/*            condition of always being above threshold.            */
/*                                                                  */
/*   [map_seq_os_2nd]                                               */
/*     Select the cross-connect elastic store threshold crossing    */
/*     level used to trigger the discard action described in        */
/*     seq_os_2nd.                                                  */
/*     3'd0 = THRESHOLD0 Cross-connect elastic store threshold      */
/*            crossing 0.                                           */
/*     3'd1 = THRESHOLD1 Cross-connect elastic store threshold      */
/*            crossing 1.                                           */
/*     3'd2 = THRESHOLD2 Cross-connect elastic store threshold      */
/*            crossing 2.                                           */
/*     3'd3 = THRESHOLD3 Cross-connect elastic store threshold      */
/*            crossing 3.                                           */
/*     3'd4 = THRESHOLD4 Cross-connect elastic store threshold      */
/*            crossing 4.                                           */
/*     3'd6 = NEVER Select none of the cross-connect elastic store  */
/*            threshold crossings; force operation under the        */
/*            condition of never being above threshold.             */
/*     3'd7 = ALWAYS Select none of the cross-connect elastic store */
/*            threshold crossings; force operation under the        */
/*            condition of always being above threshold.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL1_t tmp_xgadj_rx_ratecntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl1.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev,
                                    module_id, sl, RATECNTRL1));
      tmp_xgadj_rx_ratecntrl1.bf.map_idle_all = map_idle_all;
      tmp_xgadj_rx_ratecntrl1.bf.map_seq_os_2nd = map_seq_os_2nd;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL1), 
                    tmp_xgadj_rx_ratecntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ MAP_IDLE_ALL                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_map_idle_all(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 map_idle_all)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Map Idle All                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls additional various aspects of the receive path through  */
/* the xgadj module, specifically those that control how to         */
/* discard specific data types in response to occupancy threshold   */
/* signalling from the associated elastic store.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [map_idle_all]                                                 */
/*     Select the cross-connect elastic store threshold crossing    */
/*     level used to trigger the discard action described in        */
/*     idle_all.                                                    */
/*     3'd0 = THRESHOLD0, Cross-connect elastic store threshold     */
/*            crossing 0.                                           */
/*     3'd1 = THRESHOLD1, Cross-connect elastic store threshold     */
/*            crossing 1.                                           */
/*     3'd2 = THRESHOLD2, Cross-connect elastic store threshold     */
/*            crossing 2.                                           */
/*     3'd3 = THRESHOLD3, Cross-connect elastic store threshold     */
/*            crossing 3.                                           */
/*     3'd4 = THRESHOLD4, Cross-connect elastic store threshold     */
/*            crossing 4.                                           */
/*     3'd6 = NEVER, Select none of the cross-connect elastic store */
/*            threshold crossings; force operation under the        */
/*            condition of never being above threshold.             */
/*     3'd7 = ALWAYS, Select none of the cross-connect elastic      */
/*            store threshold crossings; force operation under the  */
/*            condition of always being above threshold.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL1_t tmp_xgadj_rx_ratecntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl1.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev,
                                    module_id, sl, RATECNTRL1));
      tmp_xgadj_rx_ratecntrl1.bf.map_idle_all = map_idle_all;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL1), 
                    tmp_xgadj_rx_ratecntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ MAP_SEQ_OS_ALL                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_map_seq_os_all(cs_uint16 module_id,
                                         cs_uint8 slice, 
                                         cs_uint16 map_seq_os_all)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Map Seq Os All                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls additional various aspects of the receive path through  */
/* the xgadj module, specifically those that control how to         */
/* discard specific data types in response to occupancy threshold   */
/* signalling from the associated elastic store.                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [map_seq_os_all]                                               */
/*     Select the cross-connect elastic store threshold crossing    */
/*     level used to trigger the discard action described in        */
/*     seq_os_all.                                                  */
/*     3'd0 THRESHOLD0 Cross-connect elastic store threshold        */
/*          crossing 0.                                             */
/*     3'd1 THRESHOLD1 Cross-connect elastic store threshold        */
/*          crossing 1.                                             */
/*     3'd2 THRESHOLD2 Cross-connect elastic store threshold        */
/*          crossing 2.                                             */
/*     3'd3 THRESHOLD3 Cross-connect elastic store threshold        */
/*          crossing 3.                                             */
/*     3'd4 THRESHOLD4 Cross-connect elastic store threshold        */
/*          crossing 4.                                             */
/*     3'd6 NEVER Select none of the cross-connect elastic store    */
/*          threshold crossings; force operation under the          */
/*          condition of never being above threshold.               */
/*     3'd7 ALWAYS Select none of the cross-connect elastic store   */
/*          threshold crossings; force operation under the          */
/*          condition of always being above threshold.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL1_t tmp_xgadj_rx_ratecntrl1;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl1.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev,
                                    module_id, sl, RATECNTRL1));
      tmp_xgadj_rx_ratecntrl1.bf.map_seq_os_all = map_seq_os_all;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL1), 
                    tmp_xgadj_rx_ratecntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATECNTRL IDLE ALL                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_ratecntrl_idle_all(cs_uint16 module_id,
                                                cs_uint8 slice, 
                                                cs_uint16 idle_all)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Idle All                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register controls aspects of the receive path through the   */
/* xgadj module, specifically those that control how to discard     */
/* specific data types in response to occupancy threshold           */
/* signalling from the associated elastic store. The dropped entity */
/* is a column in the case of a downstream_profile of X or G. The   */
/* dropped entity is a 64B/66B block in the case of a downstream_   */
/* profile of T.                                                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [idle_all] specified as:                                       */
/*     0 = Disable drop function.                                   */
/*     1 = Drop all idle columns or all 64B/66B blocks consisting   */
/*         only of idle columns, applying the threshold defined by  */
/*         map_idle_all.                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL_t tmp_xgadj_rx_ratecntrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL));
      tmp_xgadj_rx_ratecntrl.bf.idle_all = idle_all;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL), tmp_xgadj_rx_ratecntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/* Bugzilla 37543 Start */
/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATECNTRL IDLE 2ND                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_ratecntrl_idle_2nd(cs_uint16 module_id,
                                                cs_uint8  slice, 
                                                cs_uint16 idle_2nd)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Idle 2nd                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register controls aspects of the receive path through the   */
/* xgadj module, specifically those that control how to discard     */
/* specific data types in response to occupancy threshold           */
/* signalling from the associated elastic store. The dropped entity */
/* is a column in the case of a downstream_profile of X or G. The   */
/* dropped entity is a 64B/66B block in the case of a downstream_   */
/* profile of T.                                                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [idle_2nd] specified as:                                       */
/*     0 = Disable drop function.                                   */
/*     1 = Set to drop every second consecutively observed idle     */
/*         column, applying the threshold defined by map_idle_2nd.  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL_t tmp_xgadj_rx_ratecntrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL));
      tmp_xgadj_rx_ratecntrl.bf.idle_2nd = idle_2nd;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL), tmp_xgadj_rx_ratecntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}
/* Bugzilla 37543 End */

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATECNTRL CLIENT ALL              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_ratecntrl_client_all(cs_uint16 module_id,
                                                  cs_uint8 slice, 
                                                  cs_uint16 client_all)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Client All                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register controls aspects of the receive path through the   */
/* xgadj module, specifically those that control how to discard     */
/* specific data types in response to occupancy threshold           */
/* signalling from the associated elastic store. The dropped entity */
/* is a column in the case of a downstream_profile of X or G. The   */
/* dropped entity is a 64B/66B block in the case of a downstream_   */
/* profile of T.                                                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [client_all] specified as:                                     */
/*     0 = Disable drop function.                                   */
/*     1 = Drop the entire client signal, applying the threshold    */
/*         defined by map_client_all_hi/map_client_all_lo. If       */
/*         servicing a frame, the frame will be aborted in a client */
/*         signal aware fashion.                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL_t tmp_xgadj_rx_ratecntrl;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL));
      tmp_xgadj_rx_ratecntrl.bf.client_all = client_all;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL), tmp_xgadj_rx_ratecntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATECONTROL 2                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_rate_control2(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 map_frames_all,
                                    cs_uint16 map_client_all_hi,
                                    cs_uint16 map_client_all_lo)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Map Frames All                                    */
/*              o Map client All Hi                                 */
/*              o Map client All Lo                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive path through the xgadj module,   */
/* specifically those that control how to discard specific data     */
/* types in response to occupancy threshold signalling from the     */
/* associated elastic store.                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [map_client_all_hi] selects the cross-connect elastic store    */
/*   threshold crossing level used to trigger the discard action    */
/*   described in client_all.                                       */
/*    0 = THRESHOLD0                                                */
/*    1 = THRESHOLD1                                                */
/*    2 = THRESHOLD2                                                */
/*    3 = THRESHOLD3                                                */
/*    4 = THRESHOLD4                                                */
/*    6 = NEVER                                                     */
/*    7 = ALWAYS                                                    */
/*                                                                  */
/*   [map_client_all_lo] selects the cross-connect elastic store    */
/*   threshold crossing level used to clear the discard action      */
/*   described in client_all.                                       */
/*    0 = THRESHOLD0                                                */
/*    1 = THRESHOLD1                                                */
/*    2 = THRESHOLD2                                                */
/*    3 = THRESHOLD3                                                */
/*    4 = THRESHOLD4                                                */
/*    6 = NEVER                                                     */
/*    7 = ALWAYS                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL2_t tmp_xgadj_rx_ratecntrl2;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl2.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, 
                                     module_id, sl, RATECNTRL2));
      tmp_xgadj_rx_ratecntrl2.bf.map_frames_all = map_frames_all;
      tmp_xgadj_rx_ratecntrl2.bf.map_client_all_lo = map_client_all_lo;
      tmp_xgadj_rx_ratecntrl2.bf.map_client_all_hi = map_client_all_hi;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL2), 
                    tmp_xgadj_rx_ratecntrl2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}
/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATECONTROL 2                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_rate_control2_map_frames_all(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 map_frames_all)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Map Frames All                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive path through the xgadj module,   */
/* specifically those that control how to discard specific data     */
/* types in response to occupancy threshold signalling from the     */
/* associated elastic store.                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [map_frames_all]                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL2_t tmp_xgadj_rx_ratecntrl2;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl2.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, 
                                     module_id, sl, RATECNTRL2));
      tmp_xgadj_rx_ratecntrl2.bf.map_frames_all = map_frames_all;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL2), 
                    tmp_xgadj_rx_ratecntrl2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATECONTROL 2 HI LO               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_rate_control2_hi_lo(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 map_client_all_hi,
                                    cs_uint16 map_client_all_lo)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Map client All Hi                                 */
/*              o Map client All Lo                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive path through the xgadj module,   */
/* specifically those that control how to discard specific data     */
/* types in response to occupancy threshold signalling from the     */
/* associated elastic store.                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [map_client_all_hi] selects the cross-connect elastic store    */
/*   threshold crossing level used to trigger the discard action    */
/*   described in client_all.                                       */
/*    0 = THRESHOLD0                                                */
/*    1 = THRESHOLD1                                                */
/*    2 = THRESHOLD2                                                */
/*    3 = THRESHOLD3                                                */
/*    4 = THRESHOLD4                                                */
/*    6 = NEVER                                                     */
/*    7 = ALWAYS                                                    */
/*                                                                  */
/*   [map_client_all_lo] selects the cross-connect elastic store    */
/*   threshold crossing level used to clear the discard action      */
/*   described in client_all.                                       */
/*    0 = THRESHOLD0                                                */
/*    1 = THRESHOLD1                                                */
/*    2 = THRESHOLD2                                                */
/*    3 = THRESHOLD3                                                */
/*    4 = THRESHOLD4                                                */
/*    6 = NEVER                                                     */
/*    7 = ALWAYS                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL2_t tmp_xgadj_rx_ratecntrl2;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl2.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, 
                                     module_id, sl, RATECNTRL2));
      tmp_xgadj_rx_ratecntrl2.bf.map_client_all_lo = map_client_all_lo;
      tmp_xgadj_rx_ratecntrl2.bf.map_client_all_hi = map_client_all_hi;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL2), 
                    tmp_xgadj_rx_ratecntrl2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX RATE CONTROL 3                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_rate_control3(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 min_ifg)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Min Ifg                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive path through the xgadj module,   */
/* specifically it specifies the minimum inter frame gap before     */
/* negative rate adjustment policies may be applied.                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [min_ifg]                                                      */
/*     Define the minimum IFG in bytes/octets. Negative rate        */
/*     adjustment does not commence until min_ifg octets of the IFG */
/*     have been observed following the recognized termination of   */
/*     the previous frame.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_RATECNTRL3_t tmp_xgadj_rx_ratecntrl3;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_ratecntrl3.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, 
                                    module_id, sl, RATECNTRL3));
      tmp_xgadj_rx_ratecntrl3.bf.min_ifg = min_ifg;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, RATECNTRL3), 
                    tmp_xgadj_rx_ratecntrl3.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX GET STATUS                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_xgadj_rx_get_status(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Gets XGADJ status information.                                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP10G_XGADJ_RX_STATUS_UNDERFLOW           1              */
/*     TEN_PP10G_XGADJ_RX_STATUS_OVERFLOW            2              */
/*     TEN_PP10G_XGADJ_RX_STATUS_ALL (whole reg)     0xFF.          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 rtn;
  TEN_PP10G_XGADJ_RX_STATUS_t tmp_xgadj_rx_status;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_xgadj_rx_status.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, rx_STATUS));
      
  switch (select) {
  case (TEN_PP10G_XGADJ_RX_STATUS_UNDERFLOW):
    rtn = tmp_xgadj_rx_status.bf.underflow;
    break;

  case (TEN_PP10G_XGADJ_RX_STATUS_OVERFLOW):
    rtn = tmp_xgadj_rx_status.bf.overflow;
    break;

  case (TEN_PP10G_XGADJ_RX_STATUS_ALL):
    rtn = tmp_xgadj_rx_status.wrd;
    break;
  
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ GET RX EXTR LOCK                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_xgadj_get_rx_extr_lock(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns the status of lock.  When set=1, indicates that hardware */
/* locked in a frame in the extraction buffer.  Software must       */
/* explicitly unlock the extraction buffer to allow hardware to     */
/* extract another frame.  This bit is asserted by hardware and     */
/* deasserted by software.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2) or TEN_SLICE3 (3).                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_XGADJ_RX_EXTR_t tmp_xgadj_rx_extr;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(0);
  }

  /* Bugzilla #25991, fix static analyzer tool issues */
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_xgadj_rx_extr.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, EXTR));
  return (tmp_xgadj_rx_extr.bf.lock);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX EXTR LOCK                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_extr_lock(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Deasserts lock.  When set=1, indicates that hardware             */
/* locked in a frame in the extraction buffer.  Software must       */
/* explicitly unlock the extraction buffer to allow hardware to     */
/* extract another frame.  This bit is asserted by hardware and     */
/* deasserted by software.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_EXTR_t tmp_xgadj_rx_extr;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_extr.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, EXTR));
      tmp_xgadj_rx_extr.bf.lock = 0;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, EXTR), tmp_xgadj_rx_extr.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX GET EXTR STATUS                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_int16 ten_pp10g_xgadj_rx_get_extr_status(cs_uint16 module_id, cs_uint8 slice,
                                             cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Gets fields of the extraction Status Register.                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), or TEN_SLICE3 (3)                            */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_PP10G_XGADJ_RX_EXTR_STATUS_OVR_SIZE            1         */
/*     TEN_PP10G_XGADJ_RX_EXTR_STATUS_ERR                 2         */
/*     TEN_PP10G_XGADJ_RX_EXTR_STATUS_FLEN                3         */
/*     TEN_PP10G_XGADJ_RX_EXTR_STATUS_ALL (whole reg)  0xFF.        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 rtn;
  TEN_PP10G_XGADJ_RX_EXTR_STATUS_t tmp_xgadj_rx_extr_status;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_xgadj_rx_extr_status.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, EXTR_STATUS));

  switch (select) {
  case (TEN_PP10G_XGADJ_RX_EXTR_STATUS_OVR_SIZE):
    rtn = tmp_xgadj_rx_extr_status.bf.ovr_size;
    break;

  case (TEN_PP10G_XGADJ_RX_EXTR_STATUS_ERR):
    rtn = tmp_xgadj_rx_extr_status.bf.err;
    break;

  case (TEN_PP10G_XGADJ_RX_EXTR_STATUS_FLEN):
    rtn = tmp_xgadj_rx_extr_status.bf.flen;
    break;

  case (TEN_PP10G_XGADJ_RX_EXTR_STATUS_ALL):
    rtn = tmp_xgadj_rx_extr_status.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX EXTR READ 0                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_extr_read_0(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 data_0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Data 0                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [data_0]                                                       */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_EXTR_READ_0_t tmp_xgadj_rx_extr_read_0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_extr_read_0.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, EXTR_READ_0));
      tmp_xgadj_rx_extr_read_0.bf.data_0 = data_0;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, EXTR_READ_0), tmp_xgadj_rx_extr_read_0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX EXTR READ N                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_extr_read_n(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 data_n)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Data N                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [data_n]                                                       */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_EXTR_READ_N_t tmp_xgadj_rx_extr_read_n;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_extr_read_n.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, EXTR_READ_N));
      tmp_xgadj_rx_extr_read_n.bf.data_n = data_n;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, EXTR_READ_N), tmp_xgadj_rx_extr_read_n.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX EXTR GET READ 0                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_xgadj_rx_extr_get_read_0(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : READ_0                                              */
/* DESCRIPTION:                                                     */
/* The extraction buffer has 128 locations (256 octets).            */
/* When reading this register, the internal read pointer is reset   */
/* to the first location and that location is read. The internal    */
/* read pointer is automatically advanced to the next location      */
/* after the read is done. Subsequent read operations are performed */
/* by reading register EXTR_READ_N.                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_XGADJ_RX_EXTR_READ_0_t tmp_xgadj_rx_extr_read_0;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_xgadj_rx_extr_read_0.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, EXTR_READ_0));
  return (tmp_xgadj_rx_extr_read_0.bf.data_0);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX EXTR GET READ N                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_xgadj_rx_extr_get_read_n(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : READ_N                                              */
/* DESCRIPTION:                                                     */
/* When reading this register, the location addressed by the        */
/* internal read pointer is read and the read pointer is            */
/* automatically advanced to the next location. The internal read   */
/* pointer does not advance beyond the end of the extraction        */
/* buffer.                                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_XGADJ_RX_EXTR_READ_N_t tmp_xgadj_rx_extr_read_n;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_xgadj_rx_extr_read_n.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, EXTR_READ_N));
  return (tmp_xgadj_rx_extr_read_n.bf.data_n);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX CNTRL EXTR MON ENABLE             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_cntrl_extr_mon_en(cs_uint16 module_id, cs_uint8 slice, 
                                               cs_uint16 extr_mon_en)
/* INPUTS     : o Module Id                                         */
/*              o Extr Mon En                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive path through the xgadj module.   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [extr_mon_en]                                                  */
/*     This bit is only applicable when CNTRL [extr_en]=1.          */
/*     Setting this bit makes frame extraction a monitor-only       */
/*     feature, i.e. frames matching the extraction filter are      */
/*     not terminated. When this bit is cleared, frames matching    */
/*     the extraction filter are always terminated.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_CNTRL_t tmp_xgadj_rx_cntrl;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_cntrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, CNTRL));
      tmp_xgadj_rx_cntrl.bf.extr_mon_en = extr_mon_en;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, CNTRL), tmp_xgadj_rx_cntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX CNTRL EXTR ENABLE                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_cntrl_extr_en(cs_uint16 module_id, cs_uint8 slice, 
                                           cs_uint16 extr_en)
/* INPUTS     : o Module Id                                         */
/*              o Extr Mon En                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls aspects of the receive path through the xgadj module.   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [extr_en]                                                      */
/*     Setting this bit enables the frame extraction feature. If a  */
/*     frame matches the frame extraction filter, the frame is      */
/*     captured for software to read.  Once read by software, the   */
/*     extraction buffer must be unlocked by software before        */
/*     another frame can be extracted.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_CNTRL_t tmp_xgadj_rx_cntrl;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_cntrl.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, CNTRL));
      tmp_xgadj_rx_cntrl.bf.extr_en = extr_en;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, CNTRL), tmp_xgadj_rx_cntrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX EXTR FILTER ACCESS                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_extr_filter_access(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 access, 
                                            cs_uint16 wr_rd, 
                                            cs_uint16 fltr_id)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Access                                            */
/*              o Wr Rd                                             */
/*              o Fltr Id                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls Extraction Filter Control Register.                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [access]                                                       */
/*     When set logic HIGH an access is initiated. This bit self    */
/*     clears when the operation is done.                           */ 
/*                                                                  */
/*   [wr_rd]                                                        */
/*     When set logic HIGH a write operation is performed. When     */
/*     set logic LOW a read operation is performed. The procedure   */
/*     for writing is to first write the 'EXTR_FILTER_DATA'         */
/*     register and then write the 'EXTR_FILTER_ACCESS' register.   */
/*     The procedure for reading is to first write the              */
/*     'EXTR_FILTER_ACCESS' register and then read the              */
/*     'EXTR_FILTER_DATA' register for the value.                   */
/*                                                                  */
/*   [fltr_id]                                                      */
/*     Identifies the filter component being accessed.              */
/*     See register EXTR_FILTER_DATA for filter component           */
/*     descriptions.                                                */
/*     0 = FLTR_CTL Control                                         */
/*     1 = FLTR_DA0 DA field                                        */
/*     2 = FLTR_DA1 DA field                                        */
/*     3 = FLTR_DA2 DA field                                        */
/*     4 = FLTR_LT Ethernet Length/Type (LT) field                  */
/*     5 = FLTR_ST Ethernet OAMPDU Subtype (ST) field               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_EXTR_FILTER_ACCESS_t tmp_xgadj_rx_extr_filter_access;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_extr_filter_access.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, EXTR_FILTER_ACCESS));
      tmp_xgadj_rx_extr_filter_access.bf.access = access;
      tmp_xgadj_rx_extr_filter_access.bf.wr_rd = wr_rd;
      tmp_xgadj_rx_extr_filter_access.bf.fltr_id = fltr_id;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, EXTR_FILTER_ACCESS), tmp_xgadj_rx_extr_filter_access.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX EXTR FILTER GET ACCESS            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_xgadj_rx_extr_filter_get_access(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Access bit                                          */
/* DESCRIPTION:                                                     */
/* Gets Extraction Filter Control Register access bit.              */
/* When set logic HIGH an access is initiated. This bit self        */
/* clears when the operation is done.                               */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_PP10G_XGADJ_RX_EXTR_FILTER_ACCESS_t tmp_xgadj_rx_extr_filter_access;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_xgadj_rx_extr_filter_access.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, EXTR_FILTER_ACCESS));
  return (tmp_xgadj_rx_extr_filter_access.bf.access);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX EXTR FILTER DATA                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_extr_filter_data(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 data)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Data                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets extr filter data.                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [data]                                                         */
/*     filter data                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_EXTR_FILTER_DATA_t tmp_xgadj_rx_extr_filter_data;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_extr_filter_data.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, EXTR_FILTER_DATA));
      tmp_xgadj_rx_extr_filter_data.bf.data = data;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, EXTR_FILTER_DATA), tmp_xgadj_rx_extr_filter_data.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX EXTR FILTER GET DATA              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_xgadj_rx_extr_filter_get_data(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Gets extr filter data.                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_PP10G_XGADJ_RX_EXTR_FILTER_DATA_t tmp_xgadj_rx_extr_filter_data;

  if (slice >= TEN_MAX_SLICES) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_xgadj_rx_extr_filter_data.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, EXTR_FILTER_DATA));
  return (tmp_xgadj_rx_extr_filter_data.bf.data);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX EXTRACT FRAME                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_extract_frame(cs_uint16 module_id, cs_uint8 slice, 
                                           cs_uint16 *frame_size,
                                           cs_uint16 *frame_error, 
                                           cs_char8 *frame_octets)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Frame Size                                        */
/*              o Frame Error                                       */
/*              o Frame Octet                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Extracts a frame and returns frame octets and size.              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), or TEN_SLICE3 (3)                            */
/*                                                                  */
/*   [frame_size]  frame size in octets                             */
/*                                                                  */
/*   [frame_error]  frame error status                              */
/*                                                                  */
/*   [frame_octets]  frame octets.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_char8 *tmp_str;
  T41_t *pDev = NULL;
  cs_uint32 msec_elapsed = 0;
  cs_boolean waiting_for_high;
  cs_status rtn = CS_OK;
  TEN_PP10G_XGADJ_RX_EXTR_STATUS_t tmp_xgadj_rx_extr_status;
  TEN_PP10G_XGADJ_RX_EXTR_t tmp_xgadj_rx_extr;
  cs_uint16 tmp_wrd;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if ((!frame_octets) || (!frame_size) || (!frame_error)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, ": frame octets/size/err is a null ptr.");
    return (CS_ERROR);
  }
  
  /* Bugzilla #23881 */
  *frame_size = 0;
  *frame_error = 0;
  *frame_octets = 0;
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  
  /* the 'lock' bit goes high when frame is ready */
  waiting_for_high = TRUE;
  while (waiting_for_high) {
    tmp_xgadj_rx_extr.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, EXTR));
    if (tmp_xgadj_rx_extr.bf.lock == 1) {
       break;
    }   
    TEN_MDELAY(TEN_PP10G_MSEC_DELAY);
    msec_elapsed += TEN_PP10G_MSEC_DELAY;
    if (msec_elapsed >= TEN_PP10G_MSEC_TIMEOUT) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_REG_ACCESS_TIMEOUT, ": timeout waiting for lock.");
      rtn = CS_ERROR;
      goto RTN_EXIT;
      break;
    }
  }

  tmp_xgadj_rx_extr_status.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, EXTR_STATUS));
  if (tmp_xgadj_rx_extr_status.bf.ovr_size) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_REG_ACCESS_TIMEOUT, ": frame oversize > 256.");
    rtn = CS_ERROR;
    goto RTN_EXIT;
  }
  
  *frame_error = tmp_xgadj_rx_extr_status.bf.err;
  *frame_size = tmp_xgadj_rx_extr_status.bf.flen;
  if ((*frame_size < 4) || (*frame_size > 256)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": frame size out of range.  s/b 4..256.");
    rtn = CS_ERROR;
    goto RTN_EXIT;
  }
  
  tmp_str = frame_octets;
  tmp_wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, EXTR_READ_0));
  /* Bug 41533: Add support for RX XGADJ extract frames */
  *tmp_str = (cs_char8)((tmp_wrd & 0xFF00) >> 8);
  tmp_str++;
  *tmp_str = (cs_char8)(tmp_wrd & 0x00FF);
  tmp_str++;
  
  for (ii=2; ii<(*frame_size); ii+=2) {
    tmp_wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, slice, EXTR_READ_N));
    *tmp_str = (cs_char8)((tmp_wrd & 0xFF00) >> 8);
    tmp_str++;
    *tmp_str = (cs_char8)(tmp_wrd & 0x00FF);
    tmp_str++;
  }

RTN_EXIT:
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ PRINT RX EXTRACT FRAME               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_print_rx_extract_frame(cs_uint16 module_id,
                                                 cs_uint8 slice)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Prints the XGADJ RX Frame.                                       */
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
  cs_status rtn = CS_OK;
  cs_char8 tmp_rx_frame[256];
  cs_uint16 tmp_frame_size;
  cs_uint16 tmp_frame_error; 
  
  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  
  rtn = ten_pp10g_xgadj_rx_extract_frame(module_id, slice,
                                         &tmp_frame_size,
                                         &tmp_frame_error, 
                                         tmp_rx_frame);
                                         
  /* Bugzilla #42300 - Fix klocwork warnings */
  if (tmp_frame_size >= 256) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": frame size out of range.  s/b 0..255.");
    return(CS_ERROR);
  }
  
  /* Bugzilla #23881, don't print if rx extract frame had an error condition. */
  if (rtn == CS_OK) {
    ten_drvr_str_dump(tmp_rx_frame, tmp_frame_size);
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ RX DISCARD ELIGIBLE                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_rx_discard_eligible(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 discard_eligible)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Discard Eligible                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* It is permitted to subject frames with one or more errors to     */
/* frame discard if the receive data path transits the receive      */
/* Ethernet MAC or the receive GFP-F receiver.                      */
/*                                                                  */
/*  [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),           */
/*    TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*  [discard_eligible]                                              */
/*    0 = NOT_ELIGIBLE, A frame with an error may not be discarded. */
/*    1 = ELIGIBLE,  A frame with an error may be discarded.        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_RX_CNTRL1_t tmp_xgadj_rx_cntrl1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_rx_cntrl1.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, rx_CNTRL1));
      tmp_xgadj_rx_cntrl1.bf.discard_eligible = discard_eligible;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, rx_CNTRL1), tmp_xgadj_rx_cntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ SET TX CNTRL1 REGISTER               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_tx_cntrl1(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 auto_fill, 
                                    cs_uint16 translate, 
                                    cs_uint16 profile, 
                                    cs_uint16 no_ipg_check)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Auto Fill                                         */
/*              o Translate                                         */
/*              o Profile                                           */
/*              o No Ipg Check                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register configures aspects of the transmit direction       */
/* behaviour for xgadj functions.                                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [auto_fill]  Set this bit to cause the transmit PP10G to       */
/*     insert fill words into the data path while the cross-connect */
/*     is unable to provide data.                                   */
/*                                                                  */
/*   [translate]  Set this bit when the upstream client signal      */
/*     path (transitting an upstream PP10G) receives standard       */
/*     GFP-F and this PP10G transmits Ethernet frames               */
/*                                                                  */
/*   [profile]  Identify the client signal profile employed by      */
/*     the data path through the transmit PP10G.                    */
/*                                                                  */
/*   [no_ipg_check]  Section 46.1.7.5.3 of IEEE 802.3-2005          */
/*     indicates that all data frames whose /S/ is not preceded     */
/*     by either four Idle characters or a Sequence ordered set,    */
/*     should not be considered a valid frame.  This configuration  */
/*     bit determines whether this requirement is observed.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_TX_CNTRL1_t tmp_xgadj_tx_cntrl1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_cntrl1.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, tx_CNTRL1));
      tmp_xgadj_tx_cntrl1.bf.auto_fill = auto_fill;
      tmp_xgadj_tx_cntrl1.bf.translate = translate;
      tmp_xgadj_tx_cntrl1.bf.profile = profile;
      tmp_xgadj_tx_cntrl1.bf.no_ipg_check = no_ipg_check;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, tx_CNTRL1), tmp_xgadj_tx_cntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XGADJ SET TX CNTRL1 BELOW_DISABLE          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xgadj_below_disable(cs_uint16 module_id,
                                        cs_uint8 slice, 
                                        cs_uint16 below_disable)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Blow Disable                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register configures aspects of the transmit direction       */
/* behaviour for xgadj functions.                                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [below_disable] Set this bit to cause the transmit PP10G to    */
/*     consider the below threshold indication from the cross-      */
/*     connect elastic store as not asserted; therefore occupancy   */
/*     of the cross-connect elastic store is considered to always   */
/*     be above the configured below threshold. Clear this bit to   */
/*     cause the transmit PP10G to observe the below threshold      */
/*     indication from the cross-connect elastic store.             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XGADJ_TX_CNTRL1_t tmp_xgadj_tx_cntrl1;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xgadj_tx_cntrl1.wrd = TEN_REG_READ(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, tx_CNTRL1));
      tmp_xgadj_tx_cntrl1.bf.below_disable = below_disable;
      TEN_REG_WRITE(TEN_PP10G_XGADJ_REG_ADDR(pDev, module_id, sl, tx_CNTRL1), tmp_xgadj_tx_cntrl1.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}



