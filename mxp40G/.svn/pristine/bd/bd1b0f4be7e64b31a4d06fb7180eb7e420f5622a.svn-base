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
 * $Id: ten_pp10g.c,v 1.17 2013/03/07 21:43:07 jccarlis Exp $
 *
 * API's for PP10G 
 *
 */

#include "tenabo40.h"

const cs_uint16 ten_pp10g_xcode_remap_g709[TEN_PP10G_XCODE_REMAP_INDEX_MAX] = {
  0xE1,
  0x1E, /* default */
  0x2D, /* default */
  0x87,
  0x66, /* undefined, default */
  0x99,
  0xD2,
  0x33,
  0x4b,
  0xaa,
  0xb4,
  0x66,
  0xcc, /* default */
  0x55,
  0x78,
  0xFF  /* default */
};

/* Bugzilla 36089 Start */
const cs_uint16 ten_pp10g_xcode_remap_cortina[TEN_PP10G_XCODE_REMAP_INDEX_MAX] = {
  0x00, /* non-standard */
  0x1E,
  0x2D,
  0x33, /* non-standard */
  0x66,
  0x55, /* non-standard */
  0x78, /* non-standard */
  0x4B, /* non-standard */
  0x87, /* non-standard */
  0x99, /* non-standard */
  0xAA, /* non-standard */
  0xB4, /* non-standard */
  0xcc,
  0xD2, /* non-standard */
  0xE1, /* non-standard */
  0xFF
};
/* Bugzilla 36089 End */

/********************************************************************/
/* $rtn_hdr_start  PP10G GET CLKEN LINE RX                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_get_clken_line_rx(cs_uint16 module_id,
                                      cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : clken line rx value                                 */
/* DESCRIPTION:                                                     */
/* Returns clken line rx value.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MISC_CLKEN_LINE_RX_t tmp_clken_line_rx;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_clken_line_rx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, slice, CLKEN_LINE_RX));
  return (tmp_clken_line_rx.wrd);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G GET CLKEN LINE RX EN RS                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_get_clken_line_rx_en_rs(cs_uint16 module_id,
                                            cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : clken line rx_en_rs                                 */
/* DESCRIPTION:                                                     */
/* Returns clken line rx_en_rs.                                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MISC_CLKEN_LINE_RX_t tmp_clken_line_rx;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_clken_line_rx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, slice, CLKEN_LINE_RX));
  return (tmp_clken_line_rx.bf.rx_en_rs);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G CLKEN LINE RX T41                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_clken_line_rx_t41(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 rx_en_ber10b, 
                                      cs_uint16 rx_en_mon10b)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rx En Ber10b                                      */
/*              o Rx En Mon10b                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls receive line clock enables for all PP10G modules.       */
/*                                                                  */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rx_en_ber10b]  8b/10b BER clock enable.                       */
/*                                                                  */
/*   [rx_en_mon10b]   8b/10b Monitor clock enable.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 sl;
  TEN_PP10G_MISC_CLKEN_LINE_RX_t tmp_clken_line_rx;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    return (CS_OK);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_clken_line_rx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_LINE_RX));
      tmp_clken_line_rx.bf.rx_en_ber10b = rx_en_ber10b;
      tmp_clken_line_rx.bf.rx_en_mon10b = rx_en_mon10b;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_LINE_RX), tmp_clken_line_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G CLKEN LINE RX                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_clken_line_rx(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 rx_en_bypass, 
                              cs_uint16 rx_en_fc, 
                              cs_uint16 rx_en_xgpcs, 
                              cs_uint16 rx_en_xcode, 
                              cs_uint16 rx_en_mac, 
                              cs_uint16 rx_en_rs, 
                              cs_uint16 rx_en_gfp, 
                              cs_uint16 rx_en_egpcs, 
                              cs_uint16 rx_en_basex)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rx En Bypass                                      */
/*              o Rx En Fc                                          */
/*              o Rx En Xgpcs                                       */
/*              o Rx En Xcode                                       */
/*              o Rx En Mac                                         */
/*              o Rx En Rs                                          */
/*              o Rx En Gfp                                         */
/*              o Rx En Egpcs                                       */
/*              o Rx En Basex                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls receive line clock enables for all PP10G modules.       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rx_en_bypass]  Bypass receive clock enable.                   */
/*                                                                  */
/*   [rx_en_fc]  10G Fibre Channel Monitor receive clock enable.    */
/*                                                                  */
/*   [rx_en_xgpcs]  66b/64b PCS receive clock enable.               */
/*                                                                  */
/*   [rx_en_xcode]  512b/513b Transcoder receive clock enable.      */
/*                                                                  */
/*   [rx_en_mac]  MAC receive clock enable.                         */
/*                                                                  */
/*   [rx_en_rs]  RS receive clock enable                            */
/*                                                                  */
/*   [rx_en_gfp]  GFP receive clock enable.                         */
/*                                                                  */
/*   [rx_en_egpcs]  8b/10b PCS receive clock enable.                */
/*                                                                  */
/*   [rx_en_basex]  10GBASE-X / XAUI receive clock enable.          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MISC_CLKEN_LINE_RX_t tmp_clken_line_rx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_clken_line_rx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_LINE_RX));
      tmp_clken_line_rx.bf.rx_en_bypass = rx_en_bypass;
      tmp_clken_line_rx.bf.rx_en_fc = rx_en_fc;
      tmp_clken_line_rx.bf.rx_en_xgpcs = rx_en_xgpcs;
      tmp_clken_line_rx.bf.rx_en_xcode = rx_en_xcode;
      tmp_clken_line_rx.bf.rx_en_mac = rx_en_mac;
      tmp_clken_line_rx.bf.rx_en_rs = rx_en_rs;
      tmp_clken_line_rx.bf.rx_en_gfp = rx_en_gfp;
      tmp_clken_line_rx.bf.rx_en_egpcs = rx_en_egpcs;
      tmp_clken_line_rx.bf.rx_en_basex = rx_en_basex;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_LINE_RX), tmp_clken_line_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G CLKEN LINE TX                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_clken_line_tx(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 tx_en_xgpcs, 
                              cs_uint16 tx_en_xcode, 
                              cs_uint16 tx_en_mac, 
                              cs_uint16 tx_en_rs, 
                              cs_uint16 tx_en_gfp, 
                              cs_uint16 tx_en_egpcs, 
                              cs_uint16 tx_en_basex)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Tx En Xgpcs                                       */
/*              o Tx En Xcode                                       */
/*              o Tx En Mac                                         */
/*              o Tx En Rs                                          */
/*              o Tx En Gfp                                         */
/*              o Tx En Egpcs                                       */
/*              o Tx En Basex                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls transmit line clock enables for all PP10G modules.      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tx_en_xgpcs]  66b/64b PCS transmit clock enable.              */
/*                                                                  */
/*   [tx_en_xcode]  512b/513b Transcoder transmit clock enable.     */
/*                                                                  */
/*   [tx_en_mac]  MAC transmit clock enable.                        */
/*                                                                  */
/*   [tx_en_rs]  RS transmit clock enable.                          */
/*                                                                  */
/*   [tx_en_gfp]  GFP transmit clock enable.                        */
/*                                                                  */
/*   [tx_en_egpcs]  8b/10b PCS transmit clock enable.               */
/*                                                                  */
/*   [tx_en_basex]  10GBASE-X XAUI transmit clock enable.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MISC_CLKEN_LINE_TX_t tmp_clken_line_tx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_clken_line_tx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_LINE_TX));
      tmp_clken_line_tx.bf.tx_en_xgpcs = tx_en_xgpcs;
      tmp_clken_line_tx.bf.tx_en_xcode = tx_en_xcode;
      tmp_clken_line_tx.bf.tx_en_mac = tx_en_mac;
      tmp_clken_line_tx.bf.tx_en_rs = tx_en_rs;
      tmp_clken_line_tx.bf.tx_en_gfp = tx_en_gfp;
      tmp_clken_line_tx.bf.tx_en_egpcs = tx_en_egpcs;
      tmp_clken_line_tx.bf.tx_en_basex = tx_en_basex;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_LINE_TX), tmp_clken_line_tx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G CLKEN SYS RX                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_clken_sys_rx(cs_uint16 module_id, cs_uint8 slice, 
                             cs_uint16 sysrx_en_mac)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Sysrx En Mac                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls system clock enables for all PP10G modules.             */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [sysrx_en_mac]  MAC system receive clock enable.               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MISC_CLKEN_SYS_RX_t tmp_clken_sys_rx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_clken_sys_rx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_SYS_RX));
      tmp_clken_sys_rx.bf.sysrx_en_mac = sysrx_en_mac;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_SYS_RX), tmp_clken_sys_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G CLKEN SYS TX                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_clken_sys_tx(cs_uint16 module_id, cs_uint8 slice, 
                             cs_uint16 systx_en_oam, 
                             cs_uint16 systx_en_mac)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Systx En Oam                                      */
/*              o Systx En Mac                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls system clock enables for all PP10G modules.             */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [systx_en_oam]  OAMPDU Insertion transmit clock enable.        */
/*                                                                  */
/*   [systx_en_mac]  MAC system transmit clock enable.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MISC_CLKEN_SYS_TX_t tmp_clken_sys_tx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_clken_sys_tx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_SYS_TX));
      tmp_clken_sys_tx.bf.systx_en_oam = systx_en_oam;
      tmp_clken_sys_tx.bf.systx_en_mac = systx_en_mac;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_SYS_TX), tmp_clken_sys_tx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G FUNCEN RX                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_funcen_rx(cs_uint16 module_id, cs_uint8 slice, 
                          cs_uint16 rx_fen_fc, 
                          cs_uint16 rx_fen_bypass, 
                          cs_uint16 rx_fen_mac, 
                          cs_uint16 rx_fen_xcode, 
                          cs_uint16 rx_fen_egpcs, 
                          cs_uint16 rx_fen_basex, 
                          cs_uint16 rx_fen_gfp, 
                          cs_uint16 rx_fen_xgpcs)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rx Fen Fc                                         */
/*              o Rx Fen Bypass                                     */
/*              o Rx Fen Mac                                        */
/*              o Rx Fen Xcode                                      */
/*              o Rx Fen Egpcs                                      */
/*              o Rx Fen Basex                                      */
/*              o Rx Fen Gfp                                        */
/*              o Rx Fen Xgpcs                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls which functional modules are enabled within the         */
/* PP10G receive path.                                              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rx_fen_fc]  Functional enable for the Fibre Channel monitor   */
/*     module.                                                      */
/*                                                                  */
/*   [rx_fen_bypass]  Functional enable for MAC bypass              */
/*                                                                  */
/*   [rx_fen_mac]  Functional enable for MAC module                 */
/*                                                                  */
/*   [rx_fen_xcode]  Functional enable for 512b/513b                */
/*     Transcoder module                                            */
/*                                                                  */
/*   [rx_fen_egpcs]  Functional enable for EGPCS (8b/10b) module    */
/*                                                                  */
/*   [rx_fen_basex]  Functional enable for BASE-X (XAUI) module     */
/*                                                                  */
/*   [rx_fen_gfp]  Functional enable for GFP-F module               */
/*                                                                  */
/*   [rx_fen_xgpcs]  Functional enable for XGPCS (64b/66b) module.  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MISC_FUNCEN_RX_t tmp_funcen_rx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_funcen_rx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, FUNCEN_RX));
      tmp_funcen_rx.bf.rx_fen_fc = rx_fen_fc;
      tmp_funcen_rx.bf.rx_fen_bypass = rx_fen_bypass;
      tmp_funcen_rx.bf.rx_fen_mac = rx_fen_mac;
      tmp_funcen_rx.bf.rx_fen_xcode = rx_fen_xcode;
      tmp_funcen_rx.bf.rx_fen_egpcs = rx_fen_egpcs;
      tmp_funcen_rx.bf.rx_fen_basex = rx_fen_basex;
      tmp_funcen_rx.bf.rx_fen_gfp = rx_fen_gfp;
      tmp_funcen_rx.bf.rx_fen_xgpcs = rx_fen_xgpcs;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, FUNCEN_RX), tmp_funcen_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G GET FUNCEN RX                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_boolean ten_pp10g_get_funcen_rx(cs_uint16 module_id,
                                   cs_uint8 slice, 
                                   cs_uint16 select)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Returns the current functional enable state of the specified */
/* modules within the PP10G receive path.                       */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/*   [select] Specified as:                                     */
/*        TEN_PP10G_FUNCEN_XGPCS     = 0                        */
/*        TEN_PP10G_FUNCEN_GFP       = 1                        */
/*        TEN_PP10G_FUNCEN_BASEX     = 2                        */
/*        TEN_PP10G_FUNCEN_EGPCS     = 3                        */
/*        TEN_PP10G_FUNCEN_XCODE     = 4                        */
/*        TEN_PP10G_FUNCEN_MAC       = 5                        */
/*        TEN_PP10G_FUNCEN_BYPASS    = 6                        */
/*        TEN_PP10G_FUNCEN_FC        = 7                        */
/*        TEN_PP10G_FUNCEN_MON10B    = 8                        */
/*        TEN_PP10G_FUNCEN_BER10B    = 9.                       */

/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 rtn;
  TEN_PP10G_MISC_FUNCEN_RX_t tmp_funcen_rx;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (FALSE);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  tmp_funcen_rx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, slice, FUNCEN_RX));
  switch (select) {
  case TEN_PP10G_FUNCEN_XGPCS :
  {
    rtn = (tmp_funcen_rx.bf.rx_fen_xgpcs == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_GFP :
  {
    rtn = (tmp_funcen_rx.bf.rx_fen_gfp == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_BASEX :
  {
    rtn = (tmp_funcen_rx.bf.rx_fen_basex == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_EGPCS :
  {
    rtn = (tmp_funcen_rx.bf.rx_fen_egpcs == 1);
    break;
  }
   case TEN_PP10G_FUNCEN_XCODE :
  {
    rtn = (tmp_funcen_rx.bf.rx_fen_xcode == 1);
    break;
  }
 case TEN_PP10G_FUNCEN_MAC :
  {
    rtn = (tmp_funcen_rx.bf.rx_fen_mac == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_BYPASS :
  {
    rtn = (tmp_funcen_rx.bf.rx_fen_bypass == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_FC :
  {
    rtn = (tmp_funcen_rx.bf.rx_fen_fc == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_MON10B:
  {
    rtn = (tmp_funcen_rx.bf.rx_fen_mon10b == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_BER10B:
  {
    rtn = (tmp_funcen_rx.bf.rx_fen_ber10b == 1);
    break;
  }
  default :
  {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..9.");
    rtn = FALSE;
    break;
  }
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G FUNCEN TX                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_funcen_tx(cs_uint16 module_id, cs_uint8 slice, 
                          cs_uint16 tx_fen_bypass, 
                          cs_uint16 tx_fen_mac, 
                          cs_uint16 tx_fen_xcode, 
                          cs_uint16 tx_fen_egpcs, 
                          cs_uint16 tx_fen_basex, 
                          cs_uint16 tx_fen_gfp, 
                          cs_uint16 tx_fen_xgpcs)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Tx Fen Bypass                                     */
/*              o Tx Fen Mac                                        */
/*              o Tx Fen Xcode                                      */
/*              o Tx Fen Egpcs                                      */
/*              o Tx Fen Basex                                      */
/*              o Tx Fen Gfp                                        */
/*              o Tx Fen Xgpcs                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls which functional modules are enabled within the         */
/* PP10G transmit path.                                             */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tx_fen_bypass]  Functional enable for MAC bypass.             */
/*                                                                  */
/*   [tx_fen_mac]  Functional enable for MAC module.                */
/*                                                                  */
/*   [tx_fen_xcode]  Functional enable for 512b/513b Transcoder     */
/*     module                                                       */
/*                                                                  */
/*   [tx_fen_egpcs]  Functional enable for EGPCS (8b/10b) module    */
/*                                                                  */
/*   [tx_fen_basex]  Functional enable for BASE-X (XAUI) module     */
/*                                                                  */
/*   [tx_fen_gfp]  Functional enable for GFP-F module               */
/*                                                                  */
/*   [tx_fen_xgpcs]  Functional enable for XGPCS (64b/66b) module.  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MISC_FUNCEN_TX_t tmp_funcen_tx;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_funcen_tx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, FUNCEN_TX));
      tmp_funcen_tx.bf.tx_fen_bypass = tx_fen_bypass;
      tmp_funcen_tx.bf.tx_fen_mac = tx_fen_mac;
      tmp_funcen_tx.bf.tx_fen_xcode = tx_fen_xcode;
      tmp_funcen_tx.bf.tx_fen_egpcs = tx_fen_egpcs;
      tmp_funcen_tx.bf.tx_fen_basex = tx_fen_basex;
      tmp_funcen_tx.bf.tx_fen_gfp = tx_fen_gfp;
      tmp_funcen_tx.bf.tx_fen_xgpcs = tx_fen_xgpcs;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, FUNCEN_TX), tmp_funcen_tx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G GET FUNCEN TX                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : PP10G                                           */
/* CHIP       : Tenabo                                          */
cs_boolean ten_pp10g_get_funcen_tx(cs_uint16 module_id,
                                   cs_uint8 slice, 
                                   cs_uint16 select)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Returns the current functional enable state of the specified */
/* modules within the PP10G transmit path.                      */
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                           */
/*                                                              */
/*   [select] Specified as:                                     */
/*        TEN_PP10G_FUNCEN_XGPCS     = 0                        */
/*        TEN_PP10G_FUNCEN_GFP       = 1                        */
/*        TEN_PP10G_FUNCEN_BASEX     = 2                        */
/*        TEN_PP10G_FUNCEN_EGPCS     = 3                        */
/*        TEN_PP10G_FUNCEN_XCODE     = 4                        */
/*        TEN_PP10G_FUNCEN_MAC       = 5                        */
/*        TEN_PP10G_FUNCEN_BYPASS    = 6.                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 rtn;
  TEN_PP10G_MISC_FUNCEN_TX_t tmp_funcen_tx;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (FALSE);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  tmp_funcen_tx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, slice, FUNCEN_TX));
  switch (select) {
  case TEN_PP10G_FUNCEN_XGPCS :
  {
    rtn = (tmp_funcen_tx.bf.tx_fen_xgpcs == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_GFP :
  {
    rtn = (tmp_funcen_tx.bf.tx_fen_gfp == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_BASEX :
  {
    rtn = (tmp_funcen_tx.bf.tx_fen_basex == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_EGPCS :
  {
    rtn = (tmp_funcen_tx.bf.tx_fen_egpcs == 1);
    break;
  }
   case TEN_PP10G_FUNCEN_XCODE :
  {
    rtn = (tmp_funcen_tx.bf.tx_fen_xcode == 1);
    break;
  }
 case TEN_PP10G_FUNCEN_MAC :
  {
    rtn = (tmp_funcen_tx.bf.tx_fen_mac == 1);
    break;
  }
  case TEN_PP10G_FUNCEN_BYPASS :
  {
    rtn = (tmp_funcen_tx.bf.tx_fen_bypass == 1);
    break;
  }
  default :
  {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..6.");
    rtn = FALSE;
    break;
  }
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G RX PATH CTRL                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_rx_path_ctrl(cs_uint16 module_id, cs_uint8 slice, 
                             cs_uint16 rx_los_dis, 
                             cs_uint16 rx_data0_on_drop_en, 
                             cs_uint16 rx_byte_flip, 
                             cs_uint16 rx_bit_flip)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rx Los Dis                                        */
/*              o Rx Data0 On Drop En                               */
/*              o Rx Byte Flip                                      */
/*              o Rx Bit Flip                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the receive data path (from N10G).                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rx_los_dis]  Controls whether the external LOS signal can     */
/*     override the input data to the 10G PCS block during an       */
/*     LOS condition:                                               */
/*     0 = enable External LOS                                      */
/*     1 = disable External LOS.                                    */
/*                                                                  */
/*   [rx_data0_on_drop_en]  When set, receive datapath is zeroed    */
/*     out when the N10G transport framing layer Framer indicates   */
/*     AIS-L/P.                                                     */
/*                                                                  */
/*   [rx_byte_flip]  Optionally modify the byte order of 32-bit     */
/*     receive data path processed within PP10G, relative to the    */
/*     receive data path provided by N10G.                          */
/*                                                                  */
/*   [rx_bit_flip]  Optionally modify the bit order within each     */
/*     byte of the receive data path following the data path        */
/*     manipulation of rx_byte_flip.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MISC_RX_PATH_CTRL_t tmp_rx_path_ctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_rx_path_ctrl.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, RX_PATH_CTRL));
      tmp_rx_path_ctrl.bf.rx_los_dis = rx_los_dis;
      tmp_rx_path_ctrl.bf.rx_data0_on_drop_en = rx_data0_on_drop_en;
      tmp_rx_path_ctrl.bf.rx_byte_flip = rx_byte_flip;
      tmp_rx_path_ctrl.bf.rx_bit_flip = rx_bit_flip;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, RX_PATH_CTRL), tmp_rx_path_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G TX PATH CTRL                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_tx_path_ctrl(cs_uint16 module_id, cs_uint8 slice, 
                             cs_uint16 tx_sqwave_pat_en, 
                             cs_uint16 tx_sqwave_pat, 
                             cs_uint16 tx_byte_flip, 
                             cs_uint16 tx_bit_flip, 
                             cs_uint16 tx_output_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Tx Sqwave Pat En                                  */
/*              o Tx Sqwave Pat                                     */
/*              o Tx Byte Flip                                      */
/*              o Tx Bit Flip                                       */
/*              o Tx Output En                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the transmit data path as presented to N10G by PP10G.   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [tx_sqwave_pat_en]  When set, a square wave test pattern       */
/*     overrides any PCS / GFP transmit data and is output towards  */
/*      the LIF/SERDES.                                             */
/*                                                                  */
/*   [tx_sqwave_pat]  Selection of square wave test pattern         */
/*                                                                  */
/*   [tx_byte_flip]  Optionally modify the byte order of 32-bit     */
/*     transmit data path that PP10G presents to N10G, relative     */
/*     to the 32-bit transmit data path processed within PP10G.     */
/*                                                                  */
/*   [tx_bit_flip]  Optionally modify the bit order within each     */
/*     byte of the trasnsmit data path following the data path      */
/*     manipulation of tx_byte_flip.                                */
/*                                                                  */
/*   [tx_output_en]  Enable(default)/disable the transmit data      */
/*     output towards N10G and HSIF.  If disabled, the databus      */
/*     contains a constant all zero pattern.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MISC_TX_PATH_CTRL_t tmp_tx_path_ctrl;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_tx_path_ctrl.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, TX_PATH_CTRL));
      tmp_tx_path_ctrl.bf.tx_sqwave_pat_en = tx_sqwave_pat_en;
      tmp_tx_path_ctrl.bf.tx_sqwave_pat = tx_sqwave_pat;
      tmp_tx_path_ctrl.bf.tx_byte_flip = tx_byte_flip;
      tmp_tx_path_ctrl.bf.tx_bit_flip = tx_bit_flip;
      tmp_tx_path_ctrl.bf.tx_output_en = tx_output_en;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, TX_PATH_CTRL), tmp_tx_path_ctrl.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  PP10G XCODE RX CONTROL SOFT (LOGIC) RESET        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xcode_rx_reset(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control XCODE sub-block RX logic reset.                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
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
  cs_uint16 sl;
  TEN_PP10G_XCODE_RX_MODE_t tmp_xcode_rx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xcode_rx_mode.wrd = 0;
      tmp_xcode_rx_mode.bf.rxrst = 1;
      ten_reset_action(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, sl, rx_MODE), 
                       tmp_xcode_rx_mode.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XCODE TX CONTROL SOFT (LOGIC) RESET        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xcode_tx_reset(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control XCODE sub-block TX logic reset.                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
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
  cs_uint16 sl;
  TEN_PP10G_XCODE_TX_MODE_t tmp_xcode_tx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_xcode_tx_mode.wrd = 0;
      tmp_xcode_tx_mode.bf.txrst = 1;
      ten_reset_action(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, sl, tx_MODE), 
                       tmp_xcode_tx_mode.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MISC MPIF SOFT (LOGIC) RESET               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_misc_reset(cs_uint16 module_id, cs_uint8 slice, 
                               cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control MISC MPIF logic reset.                                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act] Specifies the reset option and is one of the following:  */
/*     CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.       */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset for 20 milliseconds and then de-assert the reset       */
/*     bit(s).                                                      */
/*                                                                  */
/*   Note: When set, the processor interface of all PP10G sub-      */
/*     modules is in reset. The initialization sequence of PP10G is */
/*     as follows:                                                  */
/*     1) Assert all hard reset inputs                              */
/*     2) Deassert mpif_reset hard reset input                      */
/*     3) Enable application specific required clocks via           */
/*        PP10G_MISC_CLKEN_* registers.                             */
/*     4) Release this soft reset (mpif_rst).                       */
/*     5) Deassert all remaining hard reset inputs                  */
/*     6) Configure PP10G for the required application.             */
/*     7) Release applicable soft resets in the recommended order   */
/*        (against traffic flow).                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MISC_RESET_t tmp_reset;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reset.wrd = 0;
      tmp_reset.bf.mpif_rst = 1;
      ten_reset_action(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, RESET), tmp_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MISC GET MPIF SOFT (LOGIC) RESET           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_get_misc_reset(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 0 or 1                                              */
/* DESCRIPTION:                                                     */
/* Gets MISC MPIF logic reset.                                      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_MISC_RESET_t tmp_reset;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  tmp_reset.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, slice, RESET));
  return (tmp_reset.bf.mpif_rst);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G XCODE CONFIG                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xcode_config(cs_uint16 module_id, 
                                 cs_uint8 slice,
                                 cs_dir_t dir,
                                 cs_uint16 sblock_size,
                                 cs_uint16 res_size,
                                 cs_uint16 frame_size)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Blocks within a superframe                        */
/*              o Reserved octets                                   */
/*              o Number of superblocks in a frame                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure the XCODE to select the frame type                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dir] parameter is specified as:                               */
/*     CS_RX, CS_TX or CS_TX_AND_RX                                 */
/*                                                                  */
/*   [sblock_size] configures the number of 512b blocks within a    */
/*   superframe                                                     */
/*     TEN_8_BLOCKS_PER_SUPERBLOCK_CRC24  = 0 (10GFC)               */
/*     TEN_28_BLOCKS_PER_SUPERBLOCK_CRC4  = 1 (10GE)                */
/*     TEN_32_BLOCKS_PER_SUPERBLOCK_NOCRC = 2 (10GE)                */
/*                                                                  */
/*   [res_size] configures number of RES octets added in multiples  */
/*   of 4.                                                          */
/*     TEN_16_RES_OCTETS = 0                                        */
/*     TEN_12_RES_OCTETS = 1                                        */
/*     TEN_8_RES_OCTETS  = 2                                        */
/*     TEN_4_RES_OCTETS  = 3                                        */
/*                                                                  */
/*   [frame_size] configures number of superblocks to be transmitted*/
/*   within a frame. The maximum number of superblocks configurable */
/*   is a function of the sblockSize. The total number of bytes has */
/*   to be less then the maximum GFP frame size of 64K bytes.       */
/*     0 - 63                                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XCODE_TX_MODE_t tmp_xcode_tx_mode;
  TEN_PP10G_XCODE_RX_MODE_t tmp_xcode_rx_mode;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (sblock_size > 2) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": super block size invalid");
    return(CS_ERROR);
  }
  if (res_size > 3) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": number of RES octets invalid");
    return(CS_ERROR);
  }
  if (frame_size > 63) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": frame size is invalid");
    return(CS_ERROR);
  }
  if(sblock_size == TEN_8_BLOCKS_PER_SUPERBLOCK_CRC24) {
    if(frame_size > 63) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": frame size cannot exceed 63 for 8 blocks");
      return(CS_ERROR);
    }
  }
  if(sblock_size == TEN_28_BLOCKS_PER_SUPERBLOCK_CRC4 ) {
    if(frame_size > 36) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": frame size cannot exceed 36 for 28 blocks");
      return(CS_ERROR);
    }
  }
  if(sblock_size == TEN_32_BLOCKS_PER_SUPERBLOCK_NOCRC) {
    if(frame_size > 31) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": frame size cannot exceed 31 for 32 blocks");
      return(CS_ERROR);
    }
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      if ((dir == CS_TX) || (dir == CS_RX_AND_TX)) {
        tmp_xcode_tx_mode.wrd = TEN_REG_READ(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, sl, tx_MODE));
        tmp_xcode_tx_mode.bf.sblockSize = sblock_size;
        tmp_xcode_tx_mode.bf.resSize    = res_size;
        tmp_xcode_tx_mode.bf.frameSize  = frame_size;
        TEN_REG_WRITE(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, sl, tx_MODE), tmp_xcode_tx_mode.wrd);
      }

      if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
        tmp_xcode_rx_mode.wrd = TEN_REG_READ(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, sl, rx_MODE));
        tmp_xcode_rx_mode.bf.sblockSize = sblock_size;
        tmp_xcode_rx_mode.bf.resSize    = res_size;
        tmp_xcode_rx_mode.bf.frameSize  = frame_size;
        TEN_REG_WRITE(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, sl, rx_MODE), tmp_xcode_rx_mode.wrd);
      }
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);
  return (CS_OK);
}


/********************************************************************/
/* Function: ten_get_pp10g_reg_addr()                               */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a pp10g register.                            */
/*                                                                  */
/* Used by macro TEN_PP10G_.._REG_ADDR. Given the base address of   */
/* a non-common pp10g register as defined in t41_registers.h, and    */
/* its instance number (0..TEN_PP10G_COUNT-1), calculates the       */
/* offset and adds it to the base register's address.               */
/********************************************************************/
volatile cs_reg *ten_get_pp10g_reg_addr( cs_reg  *pReg,
                                                  cs_uint16 module_id,
                                                  cs_uint8  slice )
{
  cs_uint16 instance = (module_id & 0x0001) * 4 + slice;
  if (instance >= TEN_PP10G_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "pp10g instance %d (m %d s %d) out of range. S/b < TEN_PP10G_COUNT.",
                  instance, module_id, slice);
    instance = 0;
  }
  return (pReg + instance * TEN_PP10G_STRIDE);
}


/********************************************************************/
/* $rtn_hdr_start  PP10G XCODE REMAP WRITE                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_xcode_remap_write(cs_uint16 module_id,
                                      cs_uint8  slice, 
                                      cs_dir_t  dir,
                                      cs_uint16 index, 
                                      cs_uint16 data)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Index                                             */
/*              o Data                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes to the selected XCODE Remap slot.                         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dir] parameter is specified as:                               */
/*     CS_RX, CS_TX or CS_TX_AND_RX                                 */
/*                                                                  */
/*   [index] 0..15, Selects one of 16 entries                       */
/*                                                                  */
/*   [data]  0x00..0xff                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_XCODE_TX_REMAP_ACCESS_t tmp_access;
  TEN_PP10G_XCODE_TX_REMAP_DATA_t   tmp_data;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (dir>CS_TX_AND_RX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dir out of range.");
    return(CS_ERROR);
  }
  if (index>15) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": index out of range.");
    return(CS_ERROR);
  }
  if (data>0xFF) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": data out of range.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_data.wrd         = 0;
      tmp_data.bf.data     = data;
      tmp_access.wrd       = 0;
      tmp_access.bf.IDX    = index;
      tmp_access.bf.rbw    = 1;
      tmp_access.bf.access = 1;
      if ((dir == CS_TX) || (dir == CS_RX_AND_TX)) {
        TEN_REG_WRITE(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, sl, tx_REMAP_DATA),   tmp_data.wrd);
        TEN_REG_WRITE(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, sl, tx_REMAP_ACCESS), tmp_access.wrd);
      }
      if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
        TEN_REG_WRITE(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, sl, rx_REMAP_DATA),   tmp_data.wrd);
        TEN_REG_WRITE(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, sl, rx_REMAP_ACCESS), tmp_access.wrd);
      }
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  PP10G XCODE REMAP READ                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_xcode_remap_read(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_dir_t  dir,
                                     cs_uint16 index)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Index                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Reads from the selected XCODE Remap slot.                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3)                               */
/*                                                                  */
/*   [dir] parameter is specified as:                               */
/*     CS_RX, CS_TX                                                 */
/*                                                                  */
/*   [index] 0..15, Selects one of 16 entries                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_PP10G_XCODE_TX_REMAP_ACCESS_t tmp_access;
  TEN_PP10G_XCODE_TX_REMAP_DATA_t   tmp_data;
  T41_t *pDev = NULL;

  if (slice>=TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }
  if (dir>CS_RX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dir out of range.");
    return(CS_ERROR);
  }
  if (index>15) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": index out of range.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);

  tmp_access.wrd       = 0;
  tmp_access.bf.IDX    = index;
  tmp_access.bf.rbw    = 0;
  tmp_access.bf.access = 1;
  if (dir == CS_TX) {
    TEN_REG_WRITE(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, slice, tx_REMAP_ACCESS), tmp_access.wrd);
    tmp_data.wrd = TEN_REG_READ(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, slice, tx_REMAP_DATA));
  }
  else if (dir == CS_RX) {
    /* Bug #38685 - fix compiler warnings. */
    TEN_REG_WRITE(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, slice, rx_REMAP_DATA), tmp_access.wrd);
    tmp_data.wrd = TEN_REG_READ(TEN_PP10G_XCODE_REG_ADDR(pDev, module_id, slice, rx_REMAP_DATA));
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (tmp_data.bf.data);
}

/****************************************************************/
/* $rtn_hdr_start  PP10G XCODE REMAP G709 PROVISION             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_xcode_remap_g709_provision(cs_uint16 module_id,
                                               cs_uint8  slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision PP10G TX and RX XCODE with G.709 remap table       */
/* values.                                                      */
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
  cs_uint16 i;
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_pp10g_xcode_remap_g709_provision, slice = %d\n", slice);

  for (i=0;i<TEN_PP10G_XCODE_REMAP_INDEX_MAX;i++) {
    rtn |= ten_pp10g_xcode_remap_write(module_id, slice, CS_TX_AND_RX, i, ten_pp10g_xcode_remap_g709[i]);
  }

  return(rtn);
}

/* Bugzilla 36089 Start */
/****************************************************************/
/* $rtn_hdr_start  PP10G XCODE REMAP CORTINA PROVISION          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_xcode_remap_cortina_provision(cs_uint16 module_id,
                                                  cs_uint8  slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision PP10G TX and RX XCODE with the original, pre-G.709 */
/* remap table values.                                          */
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
  cs_uint16 i;
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_pp10g_xcode_remap_cortina_provision, slice = %d\n", slice);

  for (i=0;i<TEN_PP10G_XCODE_REMAP_INDEX_MAX;i++) {
    rtn |= ten_pp10g_xcode_remap_write(module_id, slice, CS_TX_AND_RX, i, ten_pp10g_xcode_remap_cortina[i]);
  }

  return(rtn);
}
/* Bugzilla 36089 End */

/********************************************************************/
/* $rtn_hdr_start  PP10G XCODE REMAP DUMP                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_pp10g_xcode_remap_dump(cs_uint16 module_id,
                                     cs_uint8  slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Reads from the selected XCODE Remap slots on TX and RX. Prints   */
/* the contents. Verifies whether TX==RX and whether both match the */
/* industry standard.                                               */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 i;
  cs_uint16 read_val_tx;
  cs_uint16 read_val_rx;
  cs_uint16 match_tx_rx = 1;
  cs_uint16 match_std   = 1;
  cs_status rtn = CS_OK;

  CS_PRINT("ten_pp10g_xcode_remap_dump, slice = %d\n", slice);

  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND; /* don't show reg reads */

  CS_PRINT_OUTPUT("Index   TX   RX \n");
  CS_PRINT_OUTPUT("---------------\n");

  for (i=0;i<TEN_PP10G_XCODE_REMAP_INDEX_MAX;i++) {
    read_val_tx = ten_pp10g_xcode_remap_read(module_id, slice, CS_TX, i);
    read_val_rx = ten_pp10g_xcode_remap_read(module_id, slice, CS_RX, i);
    CS_PRINT_OUTPUT(" %4x %4x %4x \n", i, read_val_tx, read_val_rx);
    match_tx_rx &= (read_val_tx == read_val_rx);
    match_std   &= (read_val_tx == ten_pp10g_xcode_remap_g709[i]);
    match_std   &= (read_val_rx == ten_pp10g_xcode_remap_g709[i]);
  }

  if (match_tx_rx == 1) {
    CS_PRINT_OUTPUT("TX and RX match each other\n");
  }
  else {
    CS_PRINT_OUTPUT("TX and RX DON'T match each other\n");
  }

  if (match_std == 1) {
    CS_PRINT_OUTPUT("TX and RX both match G.709\n");
  }
  else {
    CS_PRINT_OUTPUT("TX and RX DON'T match G.709\n");
  }

  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return(rtn);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G ENABLE 8B/10B MONITOR T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mon10b_ber10b_en_t41(cs_uint16 module_id,
                                         cs_uint8  slice, 
                                         cs_ctl_t  enbl)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Enable                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables clocks and function enables for MON10B and BER10B blocks */
/* for T41 only.                                                    */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [enbl] parameter is specified as:                              */
/*     CS_ENABLE (1) or CS_DISABLE (0)                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MISC_CLKEN_LINE_RX_t tmp_clken_line_rx;
  TEN_PP10G_MISC_FUNCEN_RX_t     tmp_funcen_rx;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      /* Enable clocks */
      tmp_clken_line_rx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_LINE_RX));
      tmp_clken_line_rx.bf.rx_en_mon10b = enbl;
      tmp_clken_line_rx.bf.rx_en_ber10b = enbl;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, CLKEN_LINE_RX), tmp_clken_line_rx.wrd);
      /* Enable function */
      tmp_funcen_rx.wrd = TEN_REG_READ(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, FUNCEN_RX));
      tmp_funcen_rx.bf.rx_fen_mon10b = enbl;
      tmp_funcen_rx.bf.rx_fen_ber10b = enbl;
      TEN_REG_WRITE(TEN_PP10G_MISC_REG_ADDR(pDev, module_id, sl, FUNCEN_RX), tmp_funcen_rx.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G MON10B SOFT (LOGIC) RESET T41              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mon10b_reset_t41(cs_uint16         module_id,
                                     cs_uint8          slice, 
                                     cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control MON10B sub-block logic reset.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
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
  cs_uint16 sl;
  TEN_PP10G_MON10B_RX_RESET_t tmp_reset;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reset.wrd = 0;
      tmp_reset.bf.rxrst = 1;
      ten_reset_action(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, RESET), tmp_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G BER10B SOFT (LOGIC) RESET T41              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_ber10b_reset_t41(cs_uint16         module_id,
                                     cs_uint8          slice, 
                                     cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Control                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control BER10B sub-block logic reset.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
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
  cs_uint16 sl;
  TEN_PP10G_BER10B_RX_RESET_t tmp_reset;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reset.wrd = 0;
      tmp_reset.bf.rxrst = 1;
      ten_reset_action(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, RESET), tmp_reset.wrd, act);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET MON10B GEAR BOX CONTROLS T41           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mon10b_gb_sel_t41(cs_uint16 module_id,
                                      cs_uint8  slice, 
                                      cs_uint16 gb_sel)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Gearbox Selector                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control the input gearbox selector. For monitoring applications  */
/* where oversampling is utilized this provides the means to        */
/* monitor a sub-rate client data stream.                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [gb_sel] parameter is specified as:                            */
/*     0 = Each received data bit is input to the 10B monitor       */
/*     1 = Every 2nd received data bit is input to the 10B monitor  */
/*     2 = Every 4th received data bit is input to the 10B monitor  */
/*     3 = Reserved                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MON10B_RX_GB_t tmp_reg;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if (gb_sel>2) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": gb_sel out of range.  s/b 0..2.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reg.wrd = TEN_REG_READ(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, GB));
      tmp_reg.bf.gb_sel = gb_sel;
      TEN_REG_WRITE(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, GB), tmp_reg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET MON10B CSYMB T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mon10b_csymb_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 csymb)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Control Symbol                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure 10B Control Symbol Controls.                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [csymb] parameter is specified as:                             */
/*     Control symbol is considered legal/illegal(default). A       */
/*     received symbol which is disabled, is decoded as a symbol    */
/*     error.                                                       */
/*     Bit 11: K_28_6                                               */
/*     Bit 10: K_28_4                                               */
/*     Bit  9: K_28_3                                               */ 
/*     Bit  8: K_28_7                                               */
/*     Bit  7: K_28_1                                               */
/*     Bit  6: K_28_0                                               */
/*     Bit  5: K_23_7                                               */
/*     Bit  4: K_30_7                                               */
/*     Bit  3: K_29_7                                               */
/*     Bit  2: K_28_2                                               */
/*     Bit  1: K_27_7                                               */
/*     Bit  0: K_28_5                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MON10B_RX_CSYMB_t tmp_reg;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reg.wrd = TEN_REG_READ(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, CSYMB));
      tmp_reg.wrd = csymb;
      TEN_REG_WRITE(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, CSYMB), tmp_reg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET MON10B DATA START T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mon10b_data_start_t41(cs_uint16 module_id,
                                          cs_uint8  slice, 
                                          cs_uint16 start_k28_2)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Data Start                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* 10B Monitoring Controls. By default K27.7 marks the start of a   */
/* data frame. Optionally K28.2 can also mark the start of a data   */
/* frame.                                                           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [start_k28_2] parameter is specified as:                       */
/*     Determines whether a K28.2 marks the start of a data frame.  */
/*     1 = enable                                                   */
/*     0 = disable                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MON10B_RX_MON_t tmp_reg;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reg.wrd = TEN_REG_READ(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, MON));
      tmp_reg.bf.start_k28_2 = start_k28_2;
      TEN_REG_WRITE(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, MON), tmp_reg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET MON10B ALIGN T41                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mon10b_align_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 a_timeout_ls,
                                     cs_uint16 a_timeout_ms,
                                     cs_uint16 a_align_char,
                                     cs_uint16 a_loathr,
                                     cs_uint16 a_acqthr)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o a_timeout_ls                                      */
/*              o a_timeout_ms                                      */
/*              o a_align_char                                      */
/*              o a_loathr                                          */
/*              o a_acqthr                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* 10B Alignment Controls.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [a_timeout_ls] parameter is specified as:                      */
/*     Determines the least significant part of the timeout window  */
/*     in number of symbols. The size of the timeout window is      */
/*     a_timeout_ms + a_timeout_ls symbols. Settings are:           */
/*     0 - ls window size is 128 symbols                            */
/*     1 - ls window size is 256 symbols                            */
/*     2 - ls window size is 512 symbols                            */
/*     3 - ls window size is 1024 symbols                           */
/*                                                                  */
/*   [a_timeout_ms] parameter is specified as:                      */
/*     Determines the most significant part of the timeout window   */
/*     in number of symbols. The size of the timeout window is      */
/*     a_timeout_ms + a_timeout_ls symbols. Settings are:           */
/*     0 - ms window size is 4096 symbols                           */
/*     1 - ms window size is 8192 symbols                           */
/*     2 - ms window size is 16384 symbols                          */
/*     3 - ms window size is 32768 symbols                          */
/*                                                                  */
/*   [a_align_char] parameter is specified as:                      */
/*     Determines what pattern to search for when establishing 10B  */
/*     code group boundaries. When set, search for the 10 bit K28.5 */
/*     code group. When clear, search for the 7 bit COMMA.          */
/*                                                                  */
/*   [a_loathr] parameter is specified as:                          */
/*     Determines the number of misaligned COMMAs before loss of    */
/*     alignment (LOA) occurs and the state machine returns to      */
/*     HUNT. Legal values are 1-63.                                 */
/*                                                                  */
/*   [a_acqthr] parameter is specified as:                          */
/*     Determines the required number of same-bit-offset COMMAs     */
/*     before declaring alignment. Legal values are 2-63.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MON10B_RX_ALIGN_t  tmp_reg;
  TEN_PP10G_MON10B_RX_ALIGN2_t tmp_reg2;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reg.wrd = TEN_REG_READ(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, ALIGN));
      tmp_reg.bf.a_timeout_ls = a_timeout_ls;
      tmp_reg.bf.a_timeout_ms = a_timeout_ms;
      tmp_reg.bf.a_align_char = a_align_char;
      TEN_REG_WRITE(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, ALIGN), tmp_reg.wrd);
      tmp_reg2.wrd = TEN_REG_READ(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, ALIGN2));
      tmp_reg2.bf.a_loathr = a_loathr;
      tmp_reg2.bf.a_acqthr = a_acqthr;
      TEN_REG_WRITE(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, ALIGN2), tmp_reg2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET MON10B FORCE HUNT T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mon10b_force_hunt_t41(cs_uint16 module_id,
                                          cs_uint8  slice, 
                                          cs_uint16 a_force_hunt)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Force Hunt                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* 10B Alignment Controls.                                          */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [a_force_hunt] parameter is specified as:                      */
/*     Enable/disable(default) forcing the 10B Alignment state      */
/*     machine to the HUNT state.                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MON10B_RX_ALIGN_t  tmp_reg;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reg.wrd = TEN_REG_READ(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, ALIGN));
      tmp_reg.bf.a_force_hunt = a_force_hunt;
      TEN_REG_WRITE(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, ALIGN), tmp_reg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET MON10B SYNC T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_mon10b_sync_t41(cs_uint16 module_id,
                                     cs_uint8  slice, 
                                     cs_uint16 s_timeout_ls,
                                     cs_uint16 s_timeout_ms,
                                     cs_uint16 s_loathr,
                                     cs_uint16 s_acqthr)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o s_timeout_ls                                      */
/*              o s_timeout_ms                                      */
/*              o s_loathr                                          */
/*              o s_acqthr                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* 10B Synchronization  Controls.                                   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [s_timeout_ls] parameter is specified as:                      */
/*     Determines the least significant part of the timeout window  */
/*     in number of symbols. The size of the timeout window is      */
/*     s_timeout_ms + s_timeout_ls symbols. Settings are:           */
/*     0 - ls window size is 128 symbols                            */
/*     1 - ls window size is 256 symbols                            */
/*     2 - ls window size is 512 symbols                            */
/*     3 - ls window size is 1024 symbols                           */
/*                                                                  */
/*   [s_timeout_ms] parameter is specified as:                      */
/*     Determines the most significant part of the timeout window   */
/*     in number of symbols. The size of the timeout window is      */
/*     s_timeout_ms + s_timeout_ls symbols. Settings are:           */
/*     0 - ms window size is 4096 symbols                           */
/*     1 - ms window size is 8192 symbols                           */
/*     2 - ms window size is 16384 symbols                          */
/*     3 - ms window size is 32768 symbols                          */
/*                                                                  */
/*   [s_loathr] parameter is specified as:                          */
/*     Determines the number of misaligned COMMAs before loss of    */
/*     alignment (LOA) occurs and the state machine returns to      */
/*     HUNT. Legal values are 1-63.                                 */
/*                                                                  */
/*   [s_acqthr] parameter is specified as:                          */
/*     Determines the required number of same-bit-offset COMMAs     */
/*     before declaring alignment. Legal values are 2-63.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_MON10B_RX_SYNC_t  tmp_reg;
  TEN_PP10G_MON10B_RX_SYNC2_t tmp_reg2;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reg.wrd = TEN_REG_READ(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, SYNC));
      tmp_reg.bf.s_timeout_ls = s_timeout_ls;
      tmp_reg.bf.s_timeout_ms = s_timeout_ms;
      TEN_REG_WRITE(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, SYNC), tmp_reg.wrd);
      tmp_reg2.wrd = TEN_REG_READ(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, SYNC2));
      tmp_reg2.bf.s_loathr = s_loathr;
      tmp_reg2.bf.s_acqthr = s_acqthr;
      TEN_REG_WRITE(TEN_PP10G_MON10B_REG_ADDR(pDev, module_id, sl, SYNC2), tmp_reg2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET BER10B HIBER INTERVAL T41              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_ber10b_interval_t41(cs_uint16 module_id,
                                        cs_uint8  slice, 
                                        cs_uint16 ns,
                                        cs_uint16 nc)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Interval Set                                      */
/*              o Interval Clear                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Accumulation time interval for HiBER setting and clearing.       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ns] parameter is specified as:                                */
/*     Accumulation time interval for HiBER setting (NS). It        */
/*     configures -- in multiples of eight frames (equivalent to    */
/*     8192 symbols) -- the interval used for accumulating symbol   */
/*     errors. The HiBER interval starts running immediately upon   */
/*     initialization. The error counts are reset when the interval */
/*     starts over. The time interval is a "sliding" integration    */
/*     window for the HiBER alarm setting.                          */
/*                                                                  */
/*   [nc] parameter is specified as:                                */
/*     Accumulation time interval for HiBER clearing (NS). It       */
/*     configures -- in multiples of eight frames (equivalent to    */
/*     8192 symbols) -- the interval used for accumulating symbol   */
/*     errors. The HiBER interval starts running immediately upon   */
/*     initialization. The error counts are reset when the interval */
/*     starts over. The time interval is a "fixed" integration      */
/*     window for the HiBER alarm clearing.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BER10B_RX_NS_t tmp_reg_s;
  TEN_PP10G_BER10B_RX_NC_t tmp_reg_c;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reg_s.wrd = TEN_REG_READ(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, NS));
      tmp_reg_s.bf.ns = ns;
      TEN_REG_WRITE(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, NS), tmp_reg_s.wrd);
      tmp_reg_c.wrd = TEN_REG_READ(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, NC));
      tmp_reg_c.bf.nc = nc;
      TEN_REG_WRITE(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, NC), tmp_reg_c.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET BER10B HIBER THRESHOLD T41             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_ber10b_threshold_t41(cs_uint16 module_id,
                                         cs_uint8  slice, 
                                         cs_uint16 ts,
                                         cs_uint16 tc)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Threshold Set                                     */
/*              o Threshold Clear                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Threshold for HiBER setting and clearing.                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ts] parameter is specified as:                                */
/*     Threshold for HiBER setting (TS) based on user-supplied bit  */
/*     error rate specification.                                    */
/*                                                                  */
/*   [tc] parameter is specified as:                                */
/*     Threshold for HiBER clearing (TC) based on user-supplied bit */
/*     error rate specification.                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BER10B_RX_TS_t tmp_reg_s;
  TEN_PP10G_BER10B_RX_TC_t tmp_reg_c;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reg_s.wrd = TEN_REG_READ(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, TS));
      tmp_reg_s.bf.ts = ts;
      TEN_REG_WRITE(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, TS), tmp_reg_s.wrd);
      tmp_reg_c.wrd = TEN_REG_READ(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, TC));
      tmp_reg_c.bf.tc = tc;
      TEN_REG_WRITE(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, TC), tmp_reg_c.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  PP10G SET BER10B HIBER FILTER T41                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : PP10G                                               */
/* CHIP       : Tenabo                                              */
cs_status ten_pp10g_ber10b_filter_t41(cs_uint16 module_id,
                                      cs_uint8  slice, 
                                      cs_uint16 ms,
                                      cs_uint16 mc)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Filter Set                                        */
/*              o Filter Clear                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Acceptance filtering period for HiBER setting and clearing.      */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ms] parameter is specified as:                                */
/*     Acceptance filtering period for HiBER setting (MS). It       */
/*     configures the acceptance filtering period as a multiple     */
/*     of the interval specified in the NS (PP10G_BER10B_NS)        */
/*     register. This is the time a SET condition has to exist      */
/*     before the HiBER alarm is asserted.                          */
/*                                                                  */
/*   [mc] parameter is specified as:                                */
/*     Acceptance filtering period for HiBER clearing (MC). It      */
/*     configures the acceptance filtering period as a multiple     */
/*     of the interval specified in the NC (PP10G_BER10B_NC)        */
/*     register. This is the time a CLEAR condition has to exist    */
/*     before the HiBER alarm is deasserted.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_PP10G_BER10B_RX_MS_t tmp_reg_s;
  TEN_PP10G_BER10B_RX_MC_t tmp_reg_c;
  T41_t *pDev = NULL;

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_PP10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_reg_s.wrd = TEN_REG_READ(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, MS));
      tmp_reg_s.bf.ms = ms;
      TEN_REG_WRITE(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, MS), tmp_reg_s.wrd);
      tmp_reg_c.wrd = TEN_REG_READ(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, MC));
      tmp_reg_c.bf.mc = mc;
      TEN_REG_WRITE(TEN_PP10G_BER10B_REG_ADDR(pDev, module_id, sl, MC), tmp_reg_c.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP10G);

  return (CS_OK);
}

