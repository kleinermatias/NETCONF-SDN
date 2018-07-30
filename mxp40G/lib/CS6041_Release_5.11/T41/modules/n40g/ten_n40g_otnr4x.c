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
 * ten_n40g_otnr4x.c
 *
 * N40G related code is implemented here.
 *
 * $Id: ten_n40g_otnr4x.c,v 1.15 2013/02/22 20:44:38 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N40G SET OXU FRAME FORMAT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_frame_format(cs_uint16 module_id,
                                     cs_uint16 ncols,
                                     cs_uint16 nrows,
                                     cs_uint16 nparb,
                                     cs_uint16 npar)
/* INPUTS     : o Module Id                                     */
/*              o NCOLS                                         */
/*              o NROWS                                         */
/*              o NPARB                                         */
/*              o NPAR                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* NCOLS[9:0] specifies number of columns (or bytes) per OTN    */
/* row (columns = (NCOLS+1)*16). For G.709 OTU-compliant        */
/* framing NCOLS must be set to 254 (4080 columns).             */
/* NROWS[3:0] Specifies number of rows (NROWS+1) per OTN frame. */
/* For G.709 OTUcompliant framing NROWS must be set to 3        */
/* (4 rows).                                                    */
/* NPARB[3:0] specifies the number of additional parity bytes   */
/* per OTN row (total number of parity bytes = NPAR*16 + NPARB).*/
/* In most applications NPARB has to be set to zero. Setting    */
/* NPARB to values greater than zero may be used, for example,  */
/* for mapping 10G Ethernet with 4% FEC overhead.               */
/* Note 1: Using FEC with NPARB greater than 0 will only work   */
/* with the enhanced FEC encoder/decoder but not with the       */
/* G.7B09-compliant Reed Solomon FEC encoder/decoder.           */
/* Note 2: Setting NPARB to values greater than 0 will restrict */
/* the functionality of other features. For example, OTU2 to    */
/* ODU2 dewrapping and ODU2 to OTU2 wrapping will not work with */
/* this setup.                                                  */
/* NPAR[6:0] specifies the number of FEC parity columns (or     */
/* bytes) per OTN row (parity bytes = NPAR*16). For G.709-ODU2  */
/* compliant framing NPAR must be set to 0. For G.709-OTU2      */
/* compliant framing NPAR must be set to 16. For OTU2V framing, */
/* NPAR may be set to an appropriate value between 0 and 127.   */
/* Note: The G.709-compliant Reed Solomon FEC encoder/decoder   */
/* works only with NPAR=16.                                     */
/*                                                              */
/* The [ncols] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [nrows] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [nparb] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [npar] parameter is specified as:                        */
/*   0x0000 - 0xFFFF.                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_OFCFG0_t tmp_otnr4x_ofcfg0;
  TEN_N40G_OTNR4X_OFCFG1_t tmp_otnr4x_ofcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  tmp_otnr4x_ofcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG0));
  tmp_otnr4x_ofcfg0.bf.NCOLS = ncols;
  tmp_otnr4x_ofcfg0.bf.NROWS = nrows;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG0), tmp_otnr4x_ofcfg0.wrd);

  tmp_otnr4x_ofcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG1));
  tmp_otnr4x_ofcfg1.bf.NPARB = nparb;
  tmp_otnr4x_ofcfg1.bf.NPAR = npar;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG1), tmp_otnr4x_ofcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET OXU FRAME CONFIGURATION REGISTER 0  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_otnr4x_ofcfg0(cs_uint16 module_id,
                                     cs_uint16 ncols,
                                     cs_uint16 nrows)
/* INPUTS     : o Module Id                                     */
/*              o NCOLS                                         */
/*              o NROWS                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* NCOLS[9:0] specifies number of columns (or bytes) per OTN    */
/* row (columns = (NCOLS+1)*16). For G.709 OTU-compliant        */
/* framing NCOLS must be set to 254 (4080 columns).             */
/* NROWS[3:0] Specifies number of rows (NROWS+1) per OTN frame. */
/* For G.709 OTUcompliant framing NROWS must be set to 3        */
/* (4 rows).                                                    */
/*                                                              */
/* The [ncols] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [nrows] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_OFCFG0_t tmp_otnr4x_ofcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_ofcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG0));
  tmp_otnr4x_ofcfg0.bf.NCOLS = ncols;
  tmp_otnr4x_ofcfg0.bf.NROWS = nrows;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG0), tmp_otnr4x_ofcfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET NPARB AND NPAR               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_nparb_npar(cs_uint16 module_id,
                                         cs_uint16 nparb,
                                         cs_uint16 npar)
/* INPUTS     : o Module Id                                     */
/*              o NPARB                                         */
/*              o NPAR                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* NPARB[3:0] specifies the number of additional parity bytes   */
/* per OTN row (total number of parity bytes = NPAR*16 + NPARB).*/
/* In most applications NPARB has to be set to zero. Setting    */
/* NPARB to values greater than zero may be used, for example,  */
/* for mapping 10G Ethernet with 4% FEC overhead.               */
/* Note 1: Using FEC with NPARB greater than 0 will only work   */
/* with the enhanced FEC encoder/decoder but not with the       */
/* G.7B09-compliant Reed Solomon FEC encoder/decoder.           */
/* Note 2: Setting NPARB to values greater than 0 will restrict */
/* the functionality of other features. For example, OTU2 to    */
/* ODU2 dewrapping and ODU2 to OTU2 wrapping will not work with */
/* this setup.                                                  */
/* NPAR[6:0] specifies the number of FEC parity columns (or     */
/* bytes) per OTN row (parity bytes = NPAR*16). For G.709-ODU2  */
/* compliant framing NPAR must be set to 0. For G.709-OTU2      */
/* compliant framing NPAR must be set to 16. For OTU2V framing, */
/* NPAR may be set to an appropriate value between 0 and 127.   */
/* Note: The G.709-compliant Reed Solomon FEC encoder/decoder   */
/* works only with NPAR=16.                                     */
/*                                                              */
/* The [nparb] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* The [npar] parameter is specified as:                        */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_OFCFG1_t tmp_otnr4x_ofcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_ofcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG1));
  tmp_otnr4x_ofcfg1.bf.NPARB = nparb;
  tmp_otnr4x_ofcfg1.bf.NPAR = npar;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG1), tmp_otnr4x_ofcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET OTN DEWRAPPER CONFIG REGISTER       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_odwcfg(cs_uint16 module_id,
                                     cs_uint16 fsomd,
                                     cs_uint16 stm64md,
                                     cs_uint16 stm256md,
                                     cs_uint16 aggrmod,
                                     cs_uint16 dw_enable)
/* INPUTS     : o Module Id                                     */
/*              o FSOMD                                         */
/*              o STM64MD                                       */
/*              o STM256MD                                      */
/*              o AGGRMOD                                       */
/*              o DW ENABLE                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the contents of the OTN Dewrapper Configuration Register */
/*                                                              */
/* The [fsomd] parameter is specified as:                       */
/*   0                                                          */
/*   1 = Forward Shortened OTN mode: In this mode the dewrapper */
/*       removes the FEC redundancy portion of the data frame   */
/*       (OTU to ODU) from the data stream sent towards the     */
/*       crossconnect.                                          */
/*                                                              */
/* The [stm64md] parameter is specified as:                     */
/*   0                                                          */
/*   1 = STM64 mode: In this mode, the bytes in the columns     */
/*       1905 to 1920 of each row are assumed to be stuff bytes */
/*       and removed by the dewrapper.                          */
/*                                                              */
/* The [stm256md] parameter is specified as:                    */
/*   0                                                          */
/*   1 = STM256 mode: In this mode, the bytes in the columns    */
/*       1265 to 1280 and 2545 to 2560 of each row are assumed  */
/*       to be stuff bytes and removed by the dewrapper.        */
/*                                                              */
/* The [aggrmod] parameter is specified as:                     */
/*   Selects aggregation mode.                                  */
/*   0 = Single full-rate payload de-wrapped                    */
/*   1 = Quad 1/4 rate client signals de-wrapped                */
/*                                                              */
/* The [dw_enable] parameter is specified as:                   */
/*   0 = Data is passed through dewrapper unmodified            */
/*   1 = Enable the dewrapper                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG_t tmp_otnr4x_odwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_otnr4x_odwcfg.bf.FSOMD = fsomd;
  tmp_otnr4x_odwcfg.bf.STM64MD = stm64md;
  tmp_otnr4x_odwcfg.bf.STM256MD = stm256md;
  tmp_otnr4x_odwcfg.bf.AGGRMOD = aggrmod;
  tmp_otnr4x_odwcfg.bf.DW_ENABLE = dw_enable;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_otnr4x_odwcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET OTNR4X DESCRAMBLING MODES           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_descrambling(cs_uint16 module_id,
                                       cs_uint16 postdscr,
                                       cs_uint16 predscr,
                                       cs_uint16 alen)
/* INPUTS     : o Module Id                                     */
/*              o POSTDSCR                                      */
/*              o PREDSCR                                       */
/*              o ALEN                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the OTNR4X Descrambling Mode.                            */
/*                                                              */
/* The [postdscr] parameter is specified as:                    */
/*   OxU Descrambler enable POST-FEC. Used only for OTU.        */
/*   0 = Descrambler disabled (test-only mode)                  */
/*   1 = Descrambler enabled                                    */
/*                                                              */
/* The [predscr] parameter is specified as:                     */
/*   OxU Descrambler enable Pre-FEC. Used for both OTU and ODU. */
/*   0 = Descrambler disabled (test-only mode)                  */
/*   1 = Descrambler enabled                                    */
/*                                                              */
/* The [alen] parameter is specified as:                        */
/*   Framer (ALignment) ENable: This configuration parameters   */
/*   turns the framer on or off. If the framer is enabled, it   */
/*   searches for the FAS pattern and aligns the internal data  */
/*   stream. With the framer turned off, the data stream is     */
/*   passed through without any alignment or FAS monitoring.    */
/*   Timing signals are generated by a free-running counter     */
/*   (see NROWS, NCOLS). All other framer configuration         */
/*   parameters are ignored while the framer is off             */
/*   0 = Framer off                                             */
/*   1 = Framer on                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_OACFG0_t tmp_otnr4x_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_otnr4x_oacfg0.bf.POSTDSCR = postdscr;
  tmp_otnr4x_oacfg0.bf.PREDSCR = predscr;
  tmp_otnr4x_oacfg0.bf.ALEN = alen;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_otnr4x_oacfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET OTNR4X ALEN                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_alen(cs_uint16 module_id,
                               cs_uint16 alen)
/* INPUTS     : o Module Id                                     */
/*              o ALEN                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the OTNR4X Descrambling Mode.                            */
/*                                                              */
/* The [alen] parameter is specified as:                        */
/*   Framer (ALignment) ENable: This configuration parameters   */
/*   turns the framer on or off. If the framer is enabled, it   */
/*   searches for the FAS pattern and aligns the internal data  */
/*   stream. With the framer turned off, the data stream is     */
/*   passed through without any alignment or FAS monitoring.    */
/*   Timing signals are generated by a free-running counter     */
/*   (see NROWS, NCOLS). All other framer configuration         */
/*   parameters are ignored while the framer is off             */
/*   0 = Framer off                                             */
/*   1 = Framer on                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_OACFG0_t tmp_otnr4x_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_otnr4x_oacfg0.bf.ALEN = alen;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_otnr4x_oacfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X GET OTU FRAMER STATUS            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_n40g_otnr4x_get_otu_framer_status(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Bitmapped Status:                               */
/*                SIF                                           */
/*                SOOF                                          */
/*                SLOF                                          */
/*                SPHA                                          */
/*                FST                                           */
/*                PLOST                                         */
/*                PFND                                          */
/* DESCRIPTION:                                                 */
/* Returns the bitmapped OTU framer status.                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_OFSTAT_t tmp_otnr4x_ofstat;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_otnr4x_ofstat.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFSTAT));

  return (tmp_otnr4x_ofstat.wrd);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNR4X GET OFSTAT                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_otnr4x_get_ofstat(cs_uint16 module_id,
                                 cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns the OxU Framer Status for the selected field.            */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_N40G_OTNR4X_STATUS_SIF                 0                 */
/*     TEN_N40G_OTNR4X_STATUS_SOOF                1                 */
/*     TEN_N40G_OTNR4X_STATUS_SLOF                2                 */
/*     TEN_N40G_OTNR4X_STATUS_SPHA                3                 */
/*     TEN_N40G_OTNR4X_STATUS_FST                 4                 */
/*     TEN_N40G_OTNR4X_STATUS_PLOST               5                 */
/*     TEN_N40G_OTNR4X_STATUS_PFND                6                 */
/*     TEN_N40G_OTNR4X_STATUS_ALL              0xFF.                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 rtn;
  TEN_N40G_OTNR4X_OFSTAT_t tmp_otnr4x_ofstat;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_otnr4x_ofstat.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFSTAT));

  switch (select) {
  case (TEN_N40G_OTNR4X_STATUS_SIF):
    rtn = tmp_otnr4x_ofstat.bf.SIF;
    break;

  case (TEN_N40G_OTNR4X_STATUS_SOOF):
    rtn = tmp_otnr4x_ofstat.bf.SOOF;
    break;

  case (TEN_N40G_OTNR4X_STATUS_SLOF):
    rtn = tmp_otnr4x_ofstat.bf.SLOF;
    break;

  case (TEN_N40G_OTNR4X_STATUS_SPHA):
    rtn = tmp_otnr4x_ofstat.bf.SPHA;
    break;

  case (TEN_N40G_OTNR4X_STATUS_FST):
    rtn = tmp_otnr4x_ofstat.bf.FST;
    break;

  case (TEN_N40G_OTNR4X_STATUS_PLOST):
    rtn = tmp_otnr4x_ofstat.bf.PLOST;
    break;

  case (TEN_N40G_OTNR4X_STATUS_PFND):
    rtn = tmp_otnr4x_ofstat.bf.PFND;
    break;

 case (TEN_N40G_OTNR4X_STATUS_ALL):
    rtn = tmp_otnr4x_ofstat.wrd;
    break;

  default:
   rtn = CS_ERROR;
   CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": invalid select.");
    break;
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN0                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en0(cs_uint16 module_id,
                                         cs_uint16 c15res_en0)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN0                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for monolithic      */
/* client or timeslot 0 in aggregation mode.                    */
/*                                                              */
/* The [c15res_en0] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN0_t tmp_otnr4x_odwc15en0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0));
  tmp_otnr4x_odwc15en0.bf.C15RES_EN0 = c15res_en0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0), tmp_otnr4x_odwc15en0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN1                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en1(cs_uint16 module_id,
                                         cs_uint16 c15res_en1)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN1                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 1 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en1] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN0_t tmp_otnr4x_odwc15en0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0));
  tmp_otnr4x_odwc15en0.bf.C15RES_EN1 = c15res_en1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0), tmp_otnr4x_odwc15en0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN2                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en2(cs_uint16 module_id,
                                         cs_uint16 c15res_en2)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN2                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 2 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en2] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN0_t tmp_otnr4x_odwc15en0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0));
  tmp_otnr4x_odwc15en0.bf.C15RES_EN2 = c15res_en2;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0), tmp_otnr4x_odwc15en0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN3                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en3(cs_uint16 module_id,
                                         cs_uint16 c15res_en3)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN3                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 3 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en3] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN0_t tmp_otnr4x_odwc15en0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0));
  tmp_otnr4x_odwc15en0.bf.C15RES_EN3 = c15res_en3;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0), tmp_otnr4x_odwc15en0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN4                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en4(cs_uint16 module_id,
                                         cs_uint16 c15res_en4)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN4                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 4 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en4] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN1_t tmp_otnr4x_odwc15en1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1));
  tmp_otnr4x_odwc15en1.bf.C15RES_EN4 = c15res_en4;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1), tmp_otnr4x_odwc15en1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN5                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en5(cs_uint16 module_id,
                                         cs_uint16 c15res_en5)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN5                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 5 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en5] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN1_t tmp_otnr4x_odwc15en1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1));
  tmp_otnr4x_odwc15en1.bf.C15RES_EN5 = c15res_en5;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1), tmp_otnr4x_odwc15en1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN6                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en6(cs_uint16 module_id,
                                         cs_uint16 c15res_en6)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN6                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 6 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en6] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN1_t tmp_otnr4x_odwc15en1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1));
  tmp_otnr4x_odwc15en1.bf.C15RES_EN6 = c15res_en6;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1), tmp_otnr4x_odwc15en1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN7                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en7(cs_uint16 module_id,
                                         cs_uint16 c15res_en7)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN7                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 7 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en7] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN1_t tmp_otnr4x_odwc15en1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1));
  tmp_otnr4x_odwc15en1.bf.C15RES_EN7 = c15res_en7;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1), tmp_otnr4x_odwc15en1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN8                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en8(cs_uint16 module_id,
                                         cs_uint16 c15res_en8)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN8                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 8 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en8] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN2_t tmp_otnr4x_odwc15en2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN2));
  tmp_otnr4x_odwc15en2.bf.C15RES_EN8 = c15res_en8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN2), tmp_otnr4x_odwc15en2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN9                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en9(cs_uint16 module_id,
                                         cs_uint16 c15res_en9)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN9                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 9 in   */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en9] parameter is specified as:                  */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN2_t tmp_otnr4x_odwc15en2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN2));
  tmp_otnr4x_odwc15en2.bf.C15RES_EN9 = c15res_en9;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN2), tmp_otnr4x_odwc15en2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN10                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en10(cs_uint16 module_id,
                                          cs_uint16 c15res_en10)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN10                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 10 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en10] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN2_t tmp_otnr4x_odwc15en2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN2));
  tmp_otnr4x_odwc15en2.bf.C15RES_EN10 = c15res_en10;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN2), tmp_otnr4x_odwc15en2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN11                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en11(cs_uint16 module_id,
                                          cs_uint16 c15res_en11)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN11                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 11 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en11] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN2_t tmp_otnr4x_odwc15en2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN2));
  tmp_otnr4x_odwc15en2.bf.C15RES_EN11 = c15res_en11;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN2), tmp_otnr4x_odwc15en2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN12                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en12(cs_uint16 module_id,
                                          cs_uint16 c15res_en12)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN12                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 12 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en12] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN3_t tmp_otnr4x_odwc15en3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN3));
  tmp_otnr4x_odwc15en3.bf.C15RES_EN12 = c15res_en12;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN3), tmp_otnr4x_odwc15en3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN13                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en13(cs_uint16 module_id,
                                          cs_uint16 c15res_en13)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN13                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 13 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en13] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN3_t tmp_otnr4x_odwc15en3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN3));
  tmp_otnr4x_odwc15en3.bf.C15RES_EN13 = c15res_en13;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN3), tmp_otnr4x_odwc15en3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN14                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en14(cs_uint16 module_id,
                                          cs_uint16 c15res_en14)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN14                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 14 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en14] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN3_t tmp_otnr4x_odwc15en3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN3));
  tmp_otnr4x_odwc15en3.bf.C15RES_EN14 = c15res_en14;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN3), tmp_otnr4x_odwc15en3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET C15RES_EN15                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_c15res_en15(cs_uint16 module_id,
                                          cs_uint16 c15res_en15)
/* INPUTS     : o Module Id                                     */
/*              o C15RES EN15                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables extra payload bytes in column 15 for timeslot 15 in  */
/* aggregation mode.                                            */
/*                                                              */
/* The [c15res_en15] parameter is specified as:                 */
/*   xx1 row 1 column 15 is payload                             */
/*   x1x row 2 column 15 is payload                             */
/*   1xx row 3 column 15 is payload                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN3_t tmp_otnr4x_odwc15en3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwc15en3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN3));
  tmp_otnr4x_odwc15en3.bf.C15RES_EN15 = c15res_en15;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN3), tmp_otnr4x_odwc15en3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET AGGRMOD                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_aggrmod(cs_uint16 module_id,
                                      cs_uint16 aggrmod)
/* INPUTS     : o Module Id                                     */
/*              o AGGRMOD                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the contents of the OTN Dewrapper Configuration Register */
/*                                                              */
/* The [aggrmod] parameter is specified as:                     */
/*   Selects aggregation mode.                                  */
/*   0 = Single full-rate payload de-wrapped                    */
/*   1 = Quad 1/4 rate client signals de-wrapped                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG_t tmp_otnr4x_odwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_otnr4x_odwcfg.bf.AGGRMOD = aggrmod;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_otnr4x_odwcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET DW_ENABLE                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_dw_enable(cs_uint16 module_id,
                                        cs_uint16 dw_enable)
/* INPUTS     : o Module Id                                     */
/*              o DW ENABLE                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the contents of the OTN Dewrapper Configuration Register */
/*                                                              */
/* The [dw_enable] parameter is specified as:                   */
/*   0 = Data is passed through dewrapper unmodified            */
/*   1 = Enable the dewrapper                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG_t tmp_otnr4x_odwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_otnr4x_odwcfg.bf.DW_ENABLE = dw_enable;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_otnr4x_odwcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET JC_PLUS                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_jc_plus(cs_uint16 module_id,
                                      cs_uint16 jc_plus)
/* INPUTS     : o Module Id                                     */
/*              o JC PLUS                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the designated field in the OTN Dewrapper Configuration  */
/* Register.                                                    */
/*                                                              */
/* The [jc_plus] parameter is specified as:                     */
/*   0000-1111 binary                                           */
/*   Enable enhanced justification. When set to 1, up to 6 PJO  */
/*   may be used. Bit 0 applies for monolithic client de-       */
/*   wrapping and for tributary 0 in aggregation de-wrapping.   */
/*   Bits 1-3 apply to tributaries 1-3 in aggregation de-       */
/*   wrapping only.                                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_otnr4x_odwcfg1;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnr4x_set_jc_plus";  

  CS_PRINT("%s() %s, jc_plus=%d\n", func, ten_module_strings[module_id&1], jc_plus);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_otnr4x_odwcfg1.bf.JC_PLUS = jc_plus;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_otnr4x_odwcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET JC_ENABLE                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_jc_enable(cs_uint16 module_id,
                                        cs_uint16 jc_enable)
/* INPUTS     : o Module Id                                     */
/*              o JC ENABLE                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the designated field in the OTN Dewrapper Configuration  */
/* Register.                                                    */
/*                                                              */
/* The [jc_enable] parameter is specified as:                   */
/*   0000-1111 binary                                           */
/*   Enable justification commands to be evaluated in de-       */
/*   wrapping. Bit 0 applies for monolithic client de-wrapping  */
/*   and for tributary 0 in aggregation de-wrapping. Bits 1-3   */
/*   apply to tributaries 1-3 in aggregation de-wrapping only.  */
/*   0 = Justification commands are ignored                     */
/*   1 = Justification commands are evaluated                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_otnr4x_odwcfg1;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnr4x_set_jc_enable";  

  CS_PRINT("%s() %s, jc_enable=%d\n", func, ten_module_strings[module_id&1], jc_enable);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_otnr4x_odwcfg1.bf.JC_ENABLE = jc_enable;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_otnr4x_odwcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET JC_PLUS PER SLICE            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_jc_plus_per_slice(cs_uint16 module_id,
                                                cs_uint8 slice,
                                                cs_uint16 jc_plus)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o JC PLUS                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set jc plus per slice in the OTN Dewrapper Configuration     */
/* Register.                                                    */
/*                                                              */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),        */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)    */
/*                                                              */
/* The [jc_plus] parameter is specified as:                     */
/*   0000-1111 binary                                           */
/*   Enable enhanced justification. When set to 1, up to 6 PJO  */
/*   may be used. Bit 0 applies for monolithic client de-       */
/*   wrapping and for tributary 0 in aggregation de-wrapping.   */
/*   Bits 1-3 apply to tributaries 1-3 in aggregation de-       */
/*   wrapping only.                                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_otnr4x_odwcfg1;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnr4x_set_jc_plus_per_slice";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  CS_PRINT("%s() %s, %s, jc_plus=%d\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           jc_plus);

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));

  if (slice == TEN_SLICE_ALL) {
    if (jc_plus) {
      tmp_otnr4x_odwcfg1.bf.JC_PLUS = 0xF;
    }
    else {
      tmp_otnr4x_odwcfg1.bf.JC_PLUS = 0;
    }
  }
  else {
    if (jc_plus) {
      /* tmp_otnr4x_odwcfg1.bf.JC_PLUS |= (1<<slice); */   /* Bugzilla 22406 */
      tmp_otnr4x_odwcfg1.bf.JC_PLUS |= (1<<(3-slice));
    }
    else {
      /* tmp_otnr4x_odwcfg1.bf.JC_PLUS &= ~(1<<slice); */  /* Bugzilla 22406 */
      tmp_otnr4x_odwcfg1.bf.JC_PLUS &= ~(1<<(3-slice));
    }
  }

  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_otnr4x_odwcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET JC_ENABLE PER SLICE          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_jc_enable_per_slice(cs_uint16 module_id,
                                                  cs_uint8 slice,
                                                  cs_uint16 jc_enable)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o JC ENABLE                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set jc enable per slice in the OTN Dewrapper Configuration   */
/* Register.                                                    */
/*                                                              */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),        */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)    */
/*                                                              */
/* The [jc_enable] parameter is specified as:                   */
/*   0000-1111 binary                                           */
/*   Enable justification commands to be evaluated in de-       */
/*   wrapping. Bit 0 applies for monolithic client de-wrapping  */
/*   and for tributary 0 in aggregation de-wrapping. Bits 1-3   */
/*   apply to tributaries 1-3 in aggregation de-wrapping only.  */
/*   0 = Justification commands are ignored                     */
/*   1 = Justification commands are evaluated                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_otnr4x_odwcfg1;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnr4x_set_jc_enable_per_slice";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  CS_PRINT("%s() %s, %s, jc_enable=%d\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           jc_enable);

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));

   if (slice == TEN_SLICE_ALL) {
    if (jc_enable) {
      tmp_otnr4x_odwcfg1.bf.JC_ENABLE = 0xF;
    }
    else {
      tmp_otnr4x_odwcfg1.bf.JC_ENABLE = 0;
    }
  }
  else {
    if (jc_enable) {
      /* tmp_otnr4x_odwcfg1.bf.JC_ENABLE |= (1<<slice); */  /* Bugzilla 22406 */
      tmp_otnr4x_odwcfg1.bf.JC_ENABLE |= (1<<(3-slice));
    }
    else {
      /* tmp_otnr4x_odwcfg1.bf.JC_ENABLE &= ~(1<<slice); */  /* Bugzilla 22406 */
      tmp_otnr4x_odwcfg1.bf.JC_ENABLE &= ~(1<<(3-slice));
    }
  }

  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_otnr4x_odwcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET LINKALM JCNOM                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnr4x_set_linkalm_jcnom(cs_uint16 module_id,
                             cs_uint16 linkalm_jcnom)
/* INPUTS     : o Module Id                                         */
/*              o LINKALM JCNOM                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets OTN Dewrapper Configuration linkalm_jcnom.                  */
/*                                                                  */
/*   [linkalm_jcnom]                                                */
/*     JC Nominal on Link/Frame Alarm. If set, this bit will cause  */
/*     the dewrapper to disable justifications and interpret all    */
/*     frames as having nominal JC when a signal fail alarm is      */
/*     detected in the OTN Link/Frame layer.  When this bit is      */
/*     not set, JC interpretation will continue according to the    */
/*     setting of JC_ENABLE in the presence of a Link/Frame layer   */
/*     alarm.                                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG_t tmp_otnr4x_odwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_otnr4x_odwcfg.bf.LINKALM_JCNOM = linkalm_jcnom;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_otnr4x_odwcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET OTNR4X SET NCOLS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_ncols(cs_uint16 module_id,
                                    cs_uint16 ncols)
/* INPUTS     : o Module Id                                     */
/*              o NCOLS                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* NCOLS[9:0] specifies number of columns (or bytes) per OTN    */
/* row (columns = (NCOLS+1)*16). For G.709 OTU-compliant        */
/* framing NCOLS must be set to 254 (4080 columns).             */
/*                                                              */
/* The [ncols] parameter is specified as:                       */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_OFCFG0_t tmp_otnr4x_ofcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_ofcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG0));
  tmp_otnr4x_ofcfg0.bf.NCOLS = ncols;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG0), tmp_otnr4x_ofcfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SELECT GLOBAL TIMING SOURCE      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_select_global_timing_source(cs_uint16 module_id,
                                                      cs_uint16 select)
/* INPUTS     : o Module Id                                     */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Selects one out of eight different statistics timing         */
/* generators.                                                  */
/*                                                              */
/* The [select] parameter is specified as:                      */
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
  TEN_N40G_OTNR4X_STACFG_t tmp_otnr4x_stacfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_stacfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, STACFG));
  tmp_otnr4x_stacfg.bf.GISEL = select;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, STACFG), tmp_otnr4x_stacfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET CONFIGURATION                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_ocfg(cs_uint16 module_id,
                               cs_boolean fecmd,
                               cs_boolean fecen)
/* INPUTS     : o Module Id                                     */
/*              o FECMD                                         */
/*              o FECEN                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the OTNR4X Configuration.                                */
/*                                                              */
/* The [fecmd] parameter is specified as:                       */
/*   FECMD[1:0]                                                 */
/*   Ultra FEC enable:                                          */
/*   0 = GFEC enabled                                           */
/*   1 = UFEC enabled                                           */
/*                                                              */
/* The [fecen] parameter is specified as:                       */
/*   When set, the FEC encoding is enabled. The output stream   */
/*   will be OTU. When not set, FEC encoding is disabled.       */
/*   The output stream will be ODU.                             */
/*   0 = Do not use FEC Encoder.                                */
/*   1 = Use FEC Encoder.                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_OACFG0_t tmp_otnr4x_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_otnr4x_oacfg0.bf.FECMD = fecmd & 0x01;
  tmp_otnr4x_oacfg0.bf.FECEN = fecen;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_otnr4x_oacfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET ODWFSCFG UNSTABLE NUMBER     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_fs_mlen(cs_uint16 module_id,
                                      cs_uint16 fs_mlen)
/* INPUTS     : o Module Id                                     */
/*              o FS MLEN                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* FS_MLEN[3:0] This bit field configures the number of         */
/* received Fixed Stuff word that must differ from the          */
/* previously accepted ones in order to produce an unstable     */
/* event. Setting this bit field to zero will inhibit any       */
/* events.                                                      */
/*                                                              */
/* The [fs_mlen] parameter is specified as:                     */
/*   0x0..0xF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWFSCFG_t tmp_otnr4x_odwfscfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwfscfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSCFG));
  tmp_otnr4x_odwfscfg.bf.FS_MLEN = fs_mlen;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSCFG), tmp_otnr4x_odwfscfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET ODWFSCFG CHANGE NUMBER       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_fs_aflen(cs_uint16 module_id,
                                       cs_uint16 fs_aflen)
/* INPUTS     : o Module Id                                     */
/*              o FS AFLEN                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* FS_AFLEN[3:0] This bit field configures the number of        */
/* identical received Fixed Stuff word needed to issue a change */
/* event. Setting this bit field to zero will inhibit any       */
/* events.                                                      */
/*                                                              */
/* The [fs_aflen] parameter is specified as:                    */
/*   0x0..0xF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWFSCFG_t tmp_otnr4x_odwfscfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_odwfscfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSCFG));
  tmp_otnr4x_odwfscfg.bf.FS_AFLEN = fs_aflen;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSCFG), tmp_otnr4x_odwfscfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X SET ODWFS                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_set_odwfs(cs_uint16 module_id,
                                    cs_uint16 fs,
                                    cs_uint16 timeslot)

/* INPUTS     : o Module Id                                     */
/*              o FS                                            */
/*              o Timeslot                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Number of fixed stuff bytes carried in OPU for monolithic    */
/* client (timeslot 0) or for the specified timeslot of         */
/* aggregation de-wrapping.                                     */
/*                                                              */
/* The [fs] parameter is specified as:                          */
/*   0000-7FFF hex                                              */
/*                                                              */
/* The [timeslot] parameter is specified as:                    */
/*   0..15                                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;
  cs_char8 *func = "ten_n40g_otnr4x_set_odwfs";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s, fs=%d, timeslot=%d\n", func, ten_module_strings[module_id&1], fs, timeslot);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  switch (timeslot) {
    case 0 :
      {
        TEN_N40G_OTNR4X_ODWFS0_t tmp_otnr4x_odwfs0;
        tmp_otnr4x_odwfs0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS0));
        tmp_otnr4x_odwfs0.bf.FS0 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS0), tmp_otnr4x_odwfs0.wrd);
        break;
      }
    case 1 :
      {
        TEN_N40G_OTNR4X_ODWFS1_t tmp_otnr4x_odwfs1;
        tmp_otnr4x_odwfs1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS1));
        tmp_otnr4x_odwfs1.bf.FS1 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS1), tmp_otnr4x_odwfs1.wrd);
        break;
      }
    case 2 :
      {
        TEN_N40G_OTNR4X_ODWFS2_t tmp_otnr4x_odwfs2;
        tmp_otnr4x_odwfs2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS2));
        tmp_otnr4x_odwfs2.bf.FS2 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS2), tmp_otnr4x_odwfs2.wrd);
        break;
      }
    case 3 :
      {
        TEN_N40G_OTNR4X_ODWFS3_t tmp_otnr4x_odwfs3;
        tmp_otnr4x_odwfs3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS3));
        tmp_otnr4x_odwfs3.bf.FS3 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS3), tmp_otnr4x_odwfs3.wrd);
        break;
      }
    case 4 :
      {
        TEN_N40G_OTNR4X_ODWFS4_t tmp_otnr4x_odwfs4;
        tmp_otnr4x_odwfs4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS4));
        tmp_otnr4x_odwfs4.bf.FS4 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS4), tmp_otnr4x_odwfs4.wrd);
        break;
      }
    case 5 :
      {
        TEN_N40G_OTNR4X_ODWFS5_t tmp_otnr4x_odwfs5;
        tmp_otnr4x_odwfs5.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS5));
        tmp_otnr4x_odwfs5.bf.FS5 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS5), tmp_otnr4x_odwfs5.wrd);
        break;
      }
    case 6 :
      {
        TEN_N40G_OTNR4X_ODWFS6_t tmp_otnr4x_odwfs6;
        tmp_otnr4x_odwfs6.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS6));
        tmp_otnr4x_odwfs6.bf.FS6 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS6), tmp_otnr4x_odwfs6.wrd);
        break;
      }
    case 7 :
      {
        TEN_N40G_OTNR4X_ODWFS7_t tmp_otnr4x_odwfs7;
        tmp_otnr4x_odwfs7.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS7));
        tmp_otnr4x_odwfs7.bf.FS7 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS7), tmp_otnr4x_odwfs7.wrd);
        break;
      }
    case 8 :
      {
        TEN_N40G_OTNR4X_ODWFS8_t tmp_otnr4x_odwfs8;
        tmp_otnr4x_odwfs8.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS8));
        tmp_otnr4x_odwfs8.bf.FS8 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS8), tmp_otnr4x_odwfs8.wrd);
        break;
      }
    case 9 :
      {
        TEN_N40G_OTNR4X_ODWFS9_t tmp_otnr4x_odwfs9;
        tmp_otnr4x_odwfs9.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS9));
        tmp_otnr4x_odwfs9.bf.FS9 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS9), tmp_otnr4x_odwfs9.wrd);
        break;
      }
    case 10 :
      {
        TEN_N40G_OTNR4X_ODWFS10_t tmp_otnr4x_odwfs10;
        tmp_otnr4x_odwfs10.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS10));
        tmp_otnr4x_odwfs10.bf.FS10 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS10), tmp_otnr4x_odwfs10.wrd);
        break;
      }
    case 11 :
      {
        TEN_N40G_OTNR4X_ODWFS11_t tmp_otnr4x_odwfs11;
        tmp_otnr4x_odwfs11.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS11));
        tmp_otnr4x_odwfs11.bf.FS11 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS11), tmp_otnr4x_odwfs11.wrd);
        break;
      }
    case 12 :
      {
        TEN_N40G_OTNR4X_ODWFS12_t tmp_otnr4x_odwfs12;
        tmp_otnr4x_odwfs12.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS12));
        tmp_otnr4x_odwfs12.bf.FS12 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS12), tmp_otnr4x_odwfs12.wrd);
        break;
      }
    case 13 :
      {
        TEN_N40G_OTNR4X_ODWFS13_t tmp_otnr4x_odwfs13;
        tmp_otnr4x_odwfs13.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS13));
        tmp_otnr4x_odwfs13.bf.FS13 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS13), tmp_otnr4x_odwfs13.wrd);
        break;
      }
    case 14 :
      {
        TEN_N40G_OTNR4X_ODWFS14_t tmp_otnr4x_odwfs14;
        tmp_otnr4x_odwfs14.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS14));
        tmp_otnr4x_odwfs14.bf.FS14 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS14), tmp_otnr4x_odwfs14.wrd);
        break;
      }
    case 15 :
      {
        TEN_N40G_OTNR4X_ODWFS15_t tmp_otnr4x_odwfs15;
        tmp_otnr4x_odwfs15.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS15));
        tmp_otnr4x_odwfs15.bf.FS15 = fs;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS15), tmp_otnr4x_odwfs15.wrd);
        break;
      }
    default :
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": timeslot out of range.  s/b 0..15.");
        ret_val = CS_ERROR;
        break;
      }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X GET ODWFS                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n40g_otnr4x_get_odwfs(cs_uint16 module_id,
                                   cs_uint16 timeslot)

/* INPUTS     : o Module Id                                     */
/*              o Timeslot                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0x0000..0x7FFF                                  */
/* DESCRIPTION:                                                 */
/* Number of fixed stuff bytes carried in OPU for monolithic    */
/* client (timeslot 0) or for the specified timeslot of         */
/* aggregation de-wrapping.                                     */
/*                                                              */
/* The [timeslot] parameter is specified as:                    */
/*   0..15                                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_int16 ret_val;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  switch (timeslot) {
    case 0 :
      {
        TEN_N40G_OTNR4X_ODWFS0_t tmp_otnr4x_odwfs0;
        tmp_otnr4x_odwfs0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS0));
        ret_val = tmp_otnr4x_odwfs0.bf.FS0;
        break;
      }
    case 1 :
      {
        TEN_N40G_OTNR4X_ODWFS1_t tmp_otnr4x_odwfs1;
        tmp_otnr4x_odwfs1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS1));
        ret_val = tmp_otnr4x_odwfs1.bf.FS1;
        break;
      }
    case 2 :
      {
        TEN_N40G_OTNR4X_ODWFS2_t tmp_otnr4x_odwfs2;
        tmp_otnr4x_odwfs2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS2));
        ret_val = tmp_otnr4x_odwfs2.bf.FS2;
        break;
      }
    case 3 :
      {
        TEN_N40G_OTNR4X_ODWFS3_t tmp_otnr4x_odwfs3;
        tmp_otnr4x_odwfs3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS3));
        ret_val = tmp_otnr4x_odwfs3.bf.FS3;
        break;
      }
    case 4 :
      {
        TEN_N40G_OTNR4X_ODWFS4_t tmp_otnr4x_odwfs4;
        tmp_otnr4x_odwfs4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS4));
        ret_val = tmp_otnr4x_odwfs4.bf.FS4;
        break;
      }
    case 5 :
      {
        TEN_N40G_OTNR4X_ODWFS5_t tmp_otnr4x_odwfs5;
        tmp_otnr4x_odwfs5.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS5));
        ret_val = tmp_otnr4x_odwfs5.bf.FS5;
        break;
      }
    case 6 :
      {
        TEN_N40G_OTNR4X_ODWFS6_t tmp_otnr4x_odwfs6;
        tmp_otnr4x_odwfs6.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS6));
        ret_val = tmp_otnr4x_odwfs6.bf.FS6;
        break;
      }
    case 7 :
      {
        TEN_N40G_OTNR4X_ODWFS7_t tmp_otnr4x_odwfs7;
        tmp_otnr4x_odwfs7.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS7));
        ret_val = tmp_otnr4x_odwfs7.bf.FS7;
        break;
      }
    case 8 :
      {
        TEN_N40G_OTNR4X_ODWFS8_t tmp_otnr4x_odwfs8;
        tmp_otnr4x_odwfs8.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS8));
        ret_val = tmp_otnr4x_odwfs8.bf.FS8;
        break;
      }
    case 9 :
      {
        TEN_N40G_OTNR4X_ODWFS9_t tmp_otnr4x_odwfs9;
        tmp_otnr4x_odwfs9.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS9));
        ret_val = tmp_otnr4x_odwfs9.bf.FS9;
        break;
      }
    case 10 :
      {
        TEN_N40G_OTNR4X_ODWFS10_t tmp_otnr4x_odwfs10;
        tmp_otnr4x_odwfs10.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS10));
        ret_val = tmp_otnr4x_odwfs10.bf.FS10;
        break;
      }
    case 11 :
      {
        TEN_N40G_OTNR4X_ODWFS11_t tmp_otnr4x_odwfs11;
        tmp_otnr4x_odwfs11.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS11));
        ret_val = tmp_otnr4x_odwfs11.bf.FS11;
        break;
      }
    case 12 :
      {
        TEN_N40G_OTNR4X_ODWFS12_t tmp_otnr4x_odwfs12;
        tmp_otnr4x_odwfs12.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS12));
        ret_val = tmp_otnr4x_odwfs12.bf.FS12;
        break;
      }
    case 13 :
      {
        TEN_N40G_OTNR4X_ODWFS13_t tmp_otnr4x_odwfs13;
        tmp_otnr4x_odwfs13.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS13));
        ret_val = tmp_otnr4x_odwfs13.bf.FS13;
        break;
      }
    case 14 :
      {
        TEN_N40G_OTNR4X_ODWFS14_t tmp_otnr4x_odwfs14;
        tmp_otnr4x_odwfs14.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS14));
        ret_val = tmp_otnr4x_odwfs14.bf.FS14;
        break;
      }
    case 15 :
      {
        TEN_N40G_OTNR4X_ODWFS15_t tmp_otnr4x_odwfs15;
        tmp_otnr4x_odwfs15.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS15));
        ret_val = tmp_otnr4x_odwfs15.bf.FS15;
        break;
      }
    default :
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": timeslot out of range.  s/b 0..15.");
        ret_val = CS_ERROR;
        break;
      }
  }

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X GET ODWFSFILT                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n40g_otnr4x_get_odwfsfilt(cs_uint16 module_id,
                                       cs_uint16 timeslot)
/* INPUTS     : o Module Id                                     */
/*              o Timeslot                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0x0000..0x7FFF                                  */
/* DESCRIPTION:                                                 */
/* Filtered extracted fixed stuff indication overhead for       */
/* monolithic client or specified timeslot for aggregation      */
/* de-wrapping. The returned 16-bit value is concatenated as:   */
/*   FS_FILT[14:10] Row 1 Column16[7:3]                         */
/*   FS_FILT[9:5]   Row 2 Column16[7:3]                         */
/*   FS_FILT[4:0]   Row 3 Column16[7:3]                         */
/*                                                              */
/* The [timeslot] parameter is specified as:                    */
/*   0..15                                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_int16 ret_val;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  switch (timeslot) {
    case 0 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT0));
        break;
      }
    case 1 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT1));
        break;
      }
    case 2 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT2));
        break;
      }
    case 3 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT3));
        break;
      }
    case 4 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT4));
        break;
      }
    case 5 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT5));
        break;
      }
    case 6 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT6));
        break;
      }
    case 7 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT7));
        break;
      }
    case 8 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT8));
        break;
      }
    case 9 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT9));
        break;
      }
    case 10 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT10));
        break;
      }
    case 11 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT11));
        break;
      }
    case 12 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT12));
        break;
      }
    case 13 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT13));
        break;
      }
    case 14 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT14));
        break;
      }
    case 15 :
      {
        ret_val = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFSFILT15));
        break;
      }
    default :
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": timeslot out of range.  s/b 0..15.");
        ret_val = CS_ERROR;
        break;
      }
  }

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X GET FS UNSTABLE STATUS           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n40g_otnr4x_get_fsusts(cs_uint16 module_id,
                                    cs_uint16 timeslot)
/* INPUTS     : o Module Id                                     */
/*              o Timeslot                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0 or 1                                          */
/* DESCRIPTION:                                                 */
/* Unstable status of FS indication values.                     */
/*                                                              */
/* The [timeslot] parameter is specified as:                    */
/*   0..15                                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_FSUSTS_t tmp_otnr4x_fsusts;
  cs_int16 ret_val;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  tmp_otnr4x_fsusts.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, FSUSTS));
  switch (timeslot) {
    case 0 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS0;
        break;
      }
    case 1 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS1;
        break;
      }
    case 2 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS2;
        break;
      }
    case 3 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS3;
        break;
      }
    case 4 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS4;
        break;
      }
    case 5 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS5;
        break;
      }
    case 6 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS6;
        break;
      }
    case 7 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS7;
        break;
      }
    case 8 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS8;
        break;
      }
    case 9 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS9;
        break;
      }
    case 10 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS10;
        break;
      }
    case 11 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS11;
        break;
      }
    case 12 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS12;
        break;
      }
    case 13 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS13;
        break;
      }
    case 14 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS14;
        break;
      }
    case 15 :
      {
        ret_val = tmp_otnr4x_fsusts.bf.FSUSTS15;
        break;
      }
    default :
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": timeslot out of range.  s/b 0..15.");
        ret_val = CS_ERROR;
        break;
      }
  }

  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNR4X OACFG0 DSYHYST                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnr4x_oacfg0_dsyhyst(cs_uint16 module_id,
                             cs_uint16 dsyhyst)
/* INPUTS     : o Module Id                                         */
/*              o DSYHYST                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Framer De-Synchronization Hysteresis.                       */
/*                                                                  */
/* [dsyhyst]  After entering IF state, the framer must receive      */
/*   DSYHYST+1 consecutive invalid frames (FAS) before detecting    */
/*   an OOF (Out Of Frame) condition. The action caused by OOF      */
/*   detection depends on the setting of the ARESE configuration    */
/*   bit.                                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OTNR4X_OACFG0_t tmp_otnr4x_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_otnr4x_oacfg0.bf.DSYHYST = dsyhyst;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_otnr4x_oacfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/* Bugzilla 31127 Start */
/********************************************************************/
/* $rtn_hdr_start  N40G OTNR4X OACFG0 SYHYST                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnr4x_oacfg0_syhyst(cs_uint16 module_id,
                                        cs_uint16 syhyst)
/* INPUTS     : o Module Id                                         */
/*              o DSYHYST                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Framer Synchronization Hysteresis.                          */
/*                                                                  */
/* [dsyhyst]  After entering IF state, the framer must receive      */
/*   After entering PHALOCK state, the framer must receive SYHYST+1 */
/*   consecutive correct frames (FAS) before entering IF (In Frame) */
/*   state. If one invalid frame is received before the framer      */
/*   enters IF state, the framer returns to FS (Frame Search) state */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OTNR4X_OACFG0_t tmp_otnr4x_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_otnr4x_oacfg0.bf.SYHYST = syhyst;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_otnr4x_oacfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNR4X OBFA2 LOFCFG TDELON TDELOFF          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnr4x_obfa2_lofcfg_tdelon_tdeloff(cs_uint16 module_id,
                                      cs_uint16 tdelon, cs_uint16 tdeloff)
/* INPUTS     : o Module Id                                         */
/*              o TDELON                                            */
/*              o TDELOFF                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value for LOF Acceptance Filter Configuration #1 and #2 for */
/* OBFA2 (OTN Byte Framer Alligner 2)                               */
/*                                                                  */
/*   [tdelon]  TDELON Value                                         */
/*                                                                  */
/*   [tdelon]  TDELOFF Value.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OTNR4X_OBFA2_LOFCFG0_t tmp_otnr4x_obfa2_lofcfg0;
  TEN_N40G_OTNR4X_OBFA2_LOFCFG1_t tmp_otnr4x_obfa2_lofcfg1;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnr4x_obfa2_lofcfg_tdelon_tdeloff";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  /* Bug #37958 - Bus errors occur in T40 but not T41 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_PRINT("%s() %s, tdelon=%d, tdeloff=%d\n",
             func,
             ten_module_strings[module_id & 1],
             tdelon,
             tdeloff);

    TEN_MOD_LOCK(module_id, TEN_ID_N40G);
    tmp_otnr4x_obfa2_lofcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_LOFCFG0));
    tmp_otnr4x_obfa2_lofcfg0.bf.TDELON = tdelon;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_LOFCFG0), tmp_otnr4x_obfa2_lofcfg0.wrd);

    tmp_otnr4x_obfa2_lofcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_LOFCFG1));
    tmp_otnr4x_obfa2_lofcfg1.bf.TDELOFF = tdeloff;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_LOFCFG1), tmp_otnr4x_obfa2_lofcfg1.wrd);
    TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  }
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OTNR4X OBFA2 LOMCFG TDELON TDELOFF          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnr4x_obfa2_lomcfg_tdelon_tdeloff(cs_uint16 module_id,
                                      cs_uint16 tdelon, cs_uint16 tdeloff)
/* INPUTS     : o Module Id                                         */
/*              o TDELON                                            */
/*              o TDELOFF                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value for LOM Acceptance Filter Configuration #1 and #2 for */
/* OBFA2 (OTN Byte Framer Alligner 2)                               */
/*                                                                  */
/*   [tdelon]  TDELON Value                                         */
/*                                                                  */
/*   [tdelon]  TDELOFF Value.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OTNR4X_OBFA2_LOMCFG0_t tmp_otnr4x_obfa2_lomcfg0;
  TEN_N40G_OTNR4X_OBFA2_LOMCFG1_t tmp_otnr4x_obfa2_lomcfg1;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnr4x_obfa2_lomcfg_tdelon_tdeloff";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  /* Bug #37958 - Bus errors occur in T40 but not T41 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_PRINT("%s() %s, tdelon=%d, tdeloff=%d\n",
             func,
             ten_module_strings[module_id & 1],
             tdelon,
             tdeloff);
  
    TEN_MOD_LOCK(module_id, TEN_ID_N40G);
    tmp_otnr4x_obfa2_lomcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_LOMCFG0));
    tmp_otnr4x_obfa2_lomcfg0.bf.TDELON = tdelon;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_LOMCFG0), tmp_otnr4x_obfa2_lomcfg0.wrd);

    tmp_otnr4x_obfa2_lomcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_LOMCFG1));
    tmp_otnr4x_obfa2_lomcfg1.bf.TDELOFF = tdeloff;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_LOMCFG1), tmp_otnr4x_obfa2_lomcfg1.wrd);
    TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  }
  return (CS_OK);
}
/* Bugzilla 31127 End */

/********************************************************************/
/* $rtn_hdr_start  N40G OTNR4X LOFCFG TDELON TDELOFF                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(cs_uint16 module_id,
                              cs_uint16 tdelon, cs_uint16 tdeloff)
/* INPUTS     : o Module Id                                         */
/*              o TDELON                                            */
/*              o TDELOFF                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value for LOF Acceptance Filter Configuration #1 and #2.    */
/*                                                                  */
/*   [tdelon]  TDELON Value                                         */
/*                                                                  */
/*   [tdelon]  TDELOFF Value.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OTNR4X_LOFCFG0_t tmp_otnr4x_lofcfg0;
  TEN_N40G_OTNR4X_LOFCFG1_t tmp_otnr4x_lofcfg1;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnr4x_lofcfg_tdelon_tdeloff";  

  CS_PRINT("%s() %s, tdelon=%d, tdeloff=%d\n",
           func,
           ten_module_strings[module_id & 1],
           tdelon,
           tdeloff);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_otnr4x_lofcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, LOFCFG0));
  tmp_otnr4x_lofcfg0.bf.TDELON = tdelon;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, LOFCFG0), tmp_otnr4x_lofcfg0.wrd);

  tmp_otnr4x_lofcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, LOFCFG1));
  tmp_otnr4x_lofcfg1.bf.TDELOFF = tdeloff;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, LOFCFG1), tmp_otnr4x_lofcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G PN11 PATTERN INSERTION SEQUENCE             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_pn11_pattern_select_t41(cs_uint16 module_id,
                                           cs_uint16 pn11_type)
/* INPUTS     : o Module Id                                         */
/*              o PN11 Type                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Although a standard OTU3(e)(V)-AIS signal is an unframed PN11    */
/* sequence over the entire OTU3(e) bandwidth, for non-standard     */
/* operation it is possible to configure the Rx OTU3(e)(V) frame    */
/* region on which the PN11 sequence is expected to be automatically*/
/* detected. This API configures the expected region carrying the   */
/* PN11 sequence.                                                   */
/*                                                                  */
/*   [pn11_type] specifies the PN11 pattern insertion type          */
/*      TEN_PN11_OTUKAIS      = 0                                   */
/*         OTU3(e)(V)-AIS: The entire Rx OTU3(e)(V) signal carries  */
/*         an unframed PN11 sequence                                */
/*      TEN_PN11_FRAMED       = 1                                   */
/*         “Framed” OTU3(e)(V)-AIS: The entire Rx OTU3(e)(V) signal */
/*         except the FAS and FEC bytes carry a PN11 sequence       */
/*      TEN_PN11_ENTIRE_ODUK  = 2                                   */
/*          “ODU3(e)-PN11”: Only the Rx OPU3(e) payload, as well as */
/*          Rx OPU3(e) and ODU3(e) overhead carry a PN11 sequence   */
/*          (all SM and FEC bytes are valid fields)                 */
/*      TEN_PN11_ENTIRE_OPUK  = 3                                   */
/*          “OPU3(e)-PN11”: Only the Rx OPU3(e) payload and overhead*/
/*          carry a PN11 sequence (column 15 through 3824). All Rx  */
/*          SM bytes, ODU3(e) overhead and FEC bytes are valid      */
/*          fields.                                                 */
/*      TEN_PN11_OPUK_PAYLOAD = 4                                   */
/*          “Payload-PN11”: Only the Rx OPU3(e) payload carry a PN11*/
/*          sequence (column 17 through 3824). All Rx OxU3(e)       */
/*          Overhead bytes and FEC bytes are not overwritten with   */
/*          the PN-11.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return (CS_OK);
}

/* Bugzilla 27668 Start */
/****************************************************************/
/* $rtn_hdr_start  N40G PROVISION MFAS TRANSLATION              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_mfas_translation_en (cs_uint16 module_id,
                                        cs_dir_t dir, 
                                        cs_ctl_t ctrl)
/* INPUTS     : o Module Id                                     */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision MFAS translation table for generation of           */
/* compliant MFAS sequence after FEC modification               */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctrl] parameter is specified as:                        */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_FEC_EDMFCFG_t tmp_otnr4x_fec_edmfcfg;
  TEN_N40G_OTNT4X_FEC_EDMFCFG_t tmp_otnt4x_fec_edmfcfg;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_mfas_translation_en";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() dir=%d", func, dir); 
    return CS_ERROR;
  }
  if(ctrl > CS_ENABLE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() ctrl=%d", func, ctrl); 
    return CS_ERROR;
  }
  
  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_id&1],
           ten_dir_strings[dir],
           ten_ctrl_strings[ctrl]);
  

  /* Register setting */
  TEN_MOD_LOCK (module_id, TEN_ID_N40G);
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_otnr4x_fec_edmfcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnr4x_FEC_EDMFCFG));
    if (ctrl == CS_ENABLE)
      tmp_otnr4x_fec_edmfcfg.bf.MF_TRANS_EN = 1;
    else
      tmp_otnr4x_fec_edmfcfg.bf.MF_TRANS_EN = 0;

    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnr4x_FEC_EDMFCFG), tmp_otnr4x_fec_edmfcfg.wrd);
  }
        
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_otnt4x_fec_edmfcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_FEC_EDMFCFG));
    if (ctrl == CS_ENABLE)
      tmp_otnt4x_fec_edmfcfg.bf.MF_TRANS_EN = 1;
    else
      tmp_otnt4x_fec_edmfcfg.bf.MF_TRANS_EN = 0;
    
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_FEC_EDMFCFG), tmp_otnt4x_fec_edmfcfg.wrd);
  }
  TEN_MOD_UNLOCK (module_id, TEN_ID_N40G);

  return (CS_OK);
}
/* Bugzilla 27668 End */


