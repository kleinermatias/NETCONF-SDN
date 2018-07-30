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
 * ten_hl_fec.c
 *
 * API's for FEC high level configuration.
 *
 * $Id: ten_hl_fec.c,v 1.24 2013/02/22 20:44:11 jccarlis Exp $
 *
 */

#include "tenabo40.h"


typedef struct {
  cs_uint16 ncols;
  cs_uint16 npar;
  cs_uint16 nparb;
} ten_otnt_frame_format_t;

/* Datasheet, revision 1.0, Table 35 Ultra-FEC Decoder Configuration examples */
const static ten_otnt_frame_format_t rx_val[TEN_FEC_MODE_MAX_NUM] = {
/* Fixed Stuff Insertion Optional */
/*   7% */  {254, 16, 0},
/*  10% */  {261, 23, 0},
/*  15% */  {272, 34, 0},
/*  20% */  {284, 46, 0},
/*  25% */  {296, 58, 0},
/*  25% */  {299, 58, 0},
/*  26% */  {300, 62, 0},
/*   7% */  {254, 16, 0},  /* Minimum of 16x Fixed Stuff columns Insertion Enabled */
/*   7% */  {254, 16, 0},  /* 32x Fixed Stuff columns Insertion Enabled */
/* 3.4% */  {254,  8, 7},  /* Fixed Stuff Insertion Disabled */
/* 4.2% */  {254, 10, 4},
/*  12% */  {266, 28, 0},
/*  13% */  {269, 31, 0},

/* Bugzilla #32517, add new UFEC configurations */
/*      */  {0, 0, 0},
/*      */  {0, 0, 0},
/*      */  {0, 0, 0},
/*      */  {0, 0, 0},
/*   7% */  {254, 16, 0},
/*  18% */  {279, 41, 0},
/*  25% */  {294, 56, 0}
};

/* Datasheet, revision 1.0, Table 38 Ultra-FEC Encoder Configuration examples */
const static ten_otnt_frame_format_t tx_val[TEN_FEC_MODE_MAX_NUM] = {
/* Fixed Stuff Insertion Optional */
/*   7% */  {254, 16, 0},
/*  10% */  {261, 23, 0},
/*  15% */  {272, 34, 0},
/*  20% */  {284, 46, 0},
/*  25% */  {296, 58, 0},
/*  25% */  {299, 58, 0},
/*  26% */  {300, 62, 0},
/*   7% */  {254, 16, 0},  /* Minimum of 16x Fixed Stuff columns Insertion Enabled */
/*   7% */  {254, 16, 0},  /* 32x Fixed Stuff columns Insertion Enabled */
/* 3.4% */  {254,  8, 7},  /* Fixed Stuff Insertion Disabled */
/* 4.2% */  {254, 10, 4},
/*  12% */  {266, 28, 0},
/*  13% */  {269, 31, 0},

/* Bugzilla #32517, add new UFEC configurations */
/*      */  {0, 0, 0},
/*      */  {0, 0, 0},
/*      */  {0, 0, 0},
/*      */  {0, 0, 0},
/*   7% */  {254, 16, 0},
/*  18% */  {279, 41, 0},
/*  25% */  {294, 56, 0}
};

/****************************************************************/
/* $rtn_hdr_start  CONFIGURE FEC                                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_fec_config(cs_uint16 module_id,
                            cs_uint8 slice,
                            ten_fec_type_t fec_type,
                            ten_fec_action_t action,
                            ten_fec_ovhd_t overhead)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FEC Type                                      */
/*              o FEC Action                                    */
/*              o FEC Overhead                                  */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the FEC.  See table 16 of the CS600X              */
/* datasheet for more detailed information about each mode.     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   10G : TEN_SLICE0, TEN_SLICE1, TEN_SLICE2, TEN_SLICE3       */
/*   40G : TEN_SLICE0                                           */
/*                                                              */
/* The [fec_type] parameter is specified as:                    */
/*   0 = TEN_FEC_GFEC_10G                                       */
/*   1 = TEN_FEC_GFEC_40G                                       */
/*   2 = TEN_FEC_UFEC_10G                                       */
/*   3 = TEN_FEC_UFEC_40G                                       */
/*                                                              */
/* The [action] parameter is specified as:                      */
/*   0 = TEN_FEC_BYPASS                                         */
/*       Use ten_n10g_otnt_scrambling() to configure scrambler  */
/*   1 = TEN_FEC_ACTIVE                                         */
/*                                                              */
/* The [overhead] parameter is specified as (UFEC ONLY):        */
/*   TEN_FEC_MODE_OTUkV             = 0,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_262         = 1,   ( 10%)               */
/*   TEN_FEC_MODE_OTUkV_273         = 2,   ( 15%)               */
/*   TEN_FEC_MODE_OTUkV_285         = 3,   ( 20%)               */
/*   TEN_FEC_MODE_OTUkV_297         = 4,   ( 25%)               */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5,   ( 25%)               */
/*   TEN_FEC_MODE_OTUkV_301         = 6,   ( 26%)               */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (3.4%)               */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10,  (4.2%)               */
/*   TEN_FEC_MODE_OTUkV_267         = 11,  ( 12%)               */
/*   TEN_FEC_MODE_OTUkV_270         = 12,  ( 13%).              */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*  For GFEC it is always fixed at 7%                           */
/*                                                              */
/*   See Table 1:  FEC Encoders/Decoders Combinations and Usage */
/*   in Module A and B on page 31 of CS600X datasheet for       */
/*   explanation of invalid combinations:                       */
/*   o If a Module A slice has a 10G UFEC, then the             */
/*     corresponding Module B 10G slice cannot also have UFEC.  */
/*     (and visa-versa for B to A).                             */
/*   o If a Module A slice has a 10G GFEC, then the             */
/*     corresponding Module B 10G slice cannot also have GFEC.  */
/*     (and visa-versa for B to A), EXCEPT for SLICE 0, which   */
/*     can have 10G GFEC on Module A SLICE0 and Module B SLICE0.*/
/*   o If 40G UFEC is enabled on Module A, then Module B cannot */
/*     select a 10G UFEC on SLICE0.                             */
/*   o If 40G UFEC is enabled on Module B, then Module A cannot */
/*     select a 10G UFEC on SLICE1.                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_char8 *func = "ten_hl_fec_config";  /* __FUNCTION__ or __func__ not available for all compilers */
  CS_PRINT("%s()  slice = %d, fec_type=%d, action=%d, overhead=%d\n", func, slice, fec_type, action, overhead);

  switch(fec_type) {
    case TEN_FEC_GFEC_10G:
      /* Configure */
      if(action == TEN_FEC_BYPASS) {
        if(ten_n10g_otnt_scrambling(module_id, slice, 0, 0) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnt_ocfg(module_id, slice, 0, 0) != CS_OK)
          return CS_ERROR;
      }
      else {

        /* Bugzilla #19353, fix bus errors */
        /* Assert block-level resets */
        if(slice  == TEN_SLICE0) {
          if(ten_gfec_40g_reset(module_id, CS_TX_AND_RX, CS_RESET_DEASSERT) != CS_OK)
            return CS_ERROR;
        }
        else {
          if(ten_gfec_10g_reset(module_id, slice-1, CS_TX_AND_RX, CS_RESET_DEASSERT) != CS_OK)
            return CS_ERROR;
        }

        if(ten_n10g_otnr_descrambling(module_id, slice, 0, 1) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnt_scrambling(module_id, slice, 1, 0) != CS_OK)
          return CS_ERROR;

        if(slice  == TEN_SLICE0) {
          if(ten_gfec_40g_stats_enable_scrambler(module_id, 1) != CS_OK)
            return CS_ERROR;
        }
        else {
          if(ten_gfec_10g_stats_enable_scrambler(module_id, slice-1, 1) != CS_OK)
            return CS_ERROR;
        }

        if(ten_n10g_otnr_ocfg(module_id, slice, 0, 1) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnt_ocfg(module_id, slice, 0, 1) != CS_OK)
          return CS_ERROR;
      }
      break;

    case TEN_FEC_GFEC_40G:
#ifdef TEN_NO_N40G
      return CS_ERROR;
#else

      if(action == TEN_FEC_BYPASS) {
        if(ten_n40g_otnt4x_scrambling(module_id, 0, 0) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnt4x_ocfg(module_id, 0, 0) != CS_OK)
          return CS_ERROR;
      }
      else {

        /* Bugzilla #19353, fix bus errors */
        /* Assert block-level resets */
        if(ten_gfec_40g_reset(module_id, CS_TX_AND_RX, CS_RESET_DEASSERT) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnt4x_scrambling(module_id, 1, 0) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnr4x_descrambling(module_id, 0, 1, 1) != CS_OK)
          return CS_ERROR;

        if(ten_gfec_40g_stats_enable_scrambler(module_id, 1) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnr4x_ocfg(module_id, 0, 1) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnt4x_ocfg(module_id, 0, 1) != CS_OK)
          return CS_ERROR;
      }

#endif
      break;

    case TEN_FEC_UFEC_10G:
#ifdef TEN_NO_UFEC
      return CS_ERROR;
#else

      if(action == TEN_FEC_BYPASS) {
        if(ten_n10g_otnt_ocfg(module_id, slice, 1, 0) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnt_scrambling(module_id, slice, 1, 0) != CS_OK)
          return CS_ERROR;
      }
      else {
        /* Bugzilla #19353, fix bus errors */
        /* Assert block-level resets */
        if(ten_ufec_reset(module_id, slice, CS_TX_AND_RX, CS_RESET_DEASSERT) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnr_set_ncols(module_id, slice, rx_val[overhead].ncols) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnr_set_nparb_npar(module_id, slice, rx_val[overhead].nparb,
                                        rx_val[overhead].npar) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnt_set_ncols(module_id, slice, tx_val[overhead].ncols) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnt_set_nparb_npar(module_id, slice, tx_val[overhead].nparb,
                                       tx_val[overhead].npar) != CS_OK)
          return CS_ERROR;

        if(ten_ufec_config_decoder(module_id, slice, overhead) != CS_OK)
          return CS_ERROR;

        if(ten_ufec_config_encoder(module_id, slice, overhead) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnr_descrambling(module_id, slice, 1, 0) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnt_scrambling(module_id, slice, 0, 1) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnr_ocfg(module_id, slice, 1, 1) != CS_OK)
          return CS_ERROR;

        if(ten_n10g_otnt_ocfg(module_id, slice, 1, 1) != CS_OK)
          return CS_ERROR;

        /* TEN_FEC_MODE_OTUkV_4080_3929(3.4%) or TEN_FEC_MODE_OTUkV_68_65(4.2%) */
        if ((overhead == TEN_FEC_MODE_OTUkV_4080_3929) ||
            (overhead == TEN_FEC_MODE_OTUkV_68_65)) {
          if(ten_hl_ufec_ed_config(module_id, slice, CS_TX_AND_RX,
                                   CS_ENABLE, rx_val[overhead].ncols) != CS_OK)
            return CS_ERROR;
        }
        else
          ten_ufec_ed_enable(module_id, slice, CS_TX_AND_RX, CS_DISABLE);
      }
#endif
      break;

    case TEN_FEC_UFEC_40G:
#ifdef TEN_NO_N40G
      return CS_ERROR;
#else
#ifdef TEN_NO_UFEC
      return CS_ERROR;
#else

      if(action == TEN_FEC_BYPASS) {
        if(ten_n40g_otnt4x_scrambling(module_id, 1, 0) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnt4x_ocfg(module_id, 1, 0) != CS_OK)
          return CS_ERROR;
      }
      else {
        /* Bugzilla #19353, fix bus errors */
        /* Assert block-level resets */
        /* Bugzilla 24339 Start */
        /*if(ten_ufec_reset(module_id, slice, CS_TX_AND_RX, CS_RESET_DEASSERT) != CS_OK)*/
        if(ten_ufec_reset(module_id, module_id & 1, CS_TX_AND_RX, CS_RESET_DEASSERT) != CS_OK)
          return CS_ERROR;
        /* Bugzilla 24339 End */

        if(ten_n40g_otnr4x_set_nparb_npar(module_id, rx_val[overhead].nparb,
                                      rx_val[overhead].npar) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnr4x_set_ncols(module_id, rx_val[overhead].ncols) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnt4x_set_nparb_npar(module_id, tx_val[overhead].nparb,
                                          tx_val[overhead].npar) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnt4x_set_ncols(module_id, tx_val[overhead].ncols) != CS_OK)
          return CS_ERROR;

        /* Bugzilla #32517, add new ufec configurations  */
        if ((overhead == TEN_FEC_MODE_OTUkV_280) || (overhead == TEN_FEC_MODE_OTUkV_295)) {
          if (ten_ufec_custom_config(module_id, overhead) != CS_OK) {
             return (CS_ERROR);
          }
        }
        else {
          /* Bugzilla 24339 Start */
          /*if(ten_ufec_config_decoder(module_id, slice, overhead) != CS_OK)*/
          if(ten_ufec_config_decoder(module_id, module_id & 1, overhead) != CS_OK)
            return CS_ERROR;

          /*if(ten_ufec_config_encoder(module_id, slice, overhead) != CS_OK)*/
          if(ten_ufec_config_encoder(module_id, module_id & 1, overhead) != CS_OK)
            return CS_ERROR;
          /* Bugzilla 24339 End */
        }
        
        if(ten_n40g_otnt4x_scrambling(module_id, 0, 1) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnr4x_descrambling(module_id, 1, 0, 1) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnt4x_ocfg(module_id, 1, 1) != CS_OK)
          return CS_ERROR;

        if(ten_n40g_otnr4x_ocfg(module_id, 1, 1) != CS_OK)
          return CS_ERROR;

        /* Bugzilla 24339 Start */
        /*if(ten_hl_ufec_ed_config(module_id, slice, CS_TX_AND_RX,
                                 CS_ENABLE, rx_val[overhead].ncols) != CS_OK)*/
        if(ten_hl_ufec_ed_config(module_id, module_id & 1, CS_TX_AND_RX,
                                 CS_ENABLE, rx_val[overhead].ncols) != CS_OK)
        /* Bugzilla 24339 End */
          return CS_ERROR;
        }
#endif
#endif
      break;

    default:
      return CS_ERROR;
  }

  /* Bugzilla 24750 Start */
  #if 0  /* DSYHYST no longer changes based uppon FEC percentage */

  /* Table 42:  For low overhead rates (4..7%), register OTNR4X_OACFG0:DSYHYST */
  /* may alternatively be set to 6 (decimal) in order to allow faster          */
  /* desynchronization.                                                        */
  /* For GFEC it is always fixed at 7%                                         */
  if (fec_type == TEN_FEC_GFEC_10G) {
    ten_n10g_otnr_oacfg0_dsyhyst(module_id, slice, 6);
  }
  else if (fec_type == TEN_FEC_GFEC_40G) {
     ten_n40g_otnr4x_oacfg0_dsyhyst(module_id, 6);
  }
  else if (fec_type == TEN_FEC_UFEC_10G) {
    if ((overhead == TEN_FEC_MODE_OTUkV) ||
        (overhead == TEN_FEC_MODE_OTUkV_SDH_A) ||
        (overhead == TEN_FEC_MODE_OTUkV_SDH_B) ||
        (overhead == TEN_FEC_MODE_OTUkV_4080_3929) ||
        (overhead == TEN_FEC_MODE_OTUkV_68_65)) {
      ten_n10g_otnr_oacfg0_dsyhyst(module_id, slice, 6);
    }
    else {
      ten_n10g_otnr_oacfg0_dsyhyst(module_id, slice, 11);
    }
  }
  else {   /* fec_type == TEN_FEC_UFEC_40G */
   if ((overhead == TEN_FEC_MODE_OTUkV) ||
        (overhead == TEN_FEC_MODE_OTUkV_SDH_A) ||
        (overhead == TEN_FEC_MODE_OTUkV_SDH_B) ||
        (overhead == TEN_FEC_MODE_OTUkV_4080_3929) ||
        (overhead == TEN_FEC_MODE_OTUkV_68_65)) {
      ten_n40g_otnr4x_oacfg0_dsyhyst(module_id, 6);
    }
    else {
      ten_n40g_otnr4x_oacfg0_dsyhyst(module_id, 11);
    }
  }
  #endif
  /* Bugzilla 24750 Start */

  return CS_OK;
}

#ifndef TEN_NO_UFEC
/****************************************************************/
/* $rtn_hdr_start  UFEC ERROR DECORELATOR CONFIG                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ufec_ed_config(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_dir_t dir,
                                cs_ctl_t ctrl,
                                cs_uint16 n_cols)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Control                                       */
/*              o Columns                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable error decorelator                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
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
/* The [n_cols] parameter is the number of columns based on the */
/* FEC percentage                                               */
/*   254  = TEN_FEC_MODE_OTUkV             (7%)                 */
/*   261  = TEN_FEC_MODE_OTUkV_262         (10%)                */
/*   272  = TEN_FEC_MODE_OTUkV_273         (15%)                */
/*   284  = TEN_FEC_MODE_OTUkV_285         (20%)                */
/*   296  = TEN_FEC_MODE_OTUkV_297         (25%)                */
/*   299  = TEN_FEC_MODE_OTUkV_5_4         (25%)                */
/*   300  = TEN_FEC_MODE_OTUkV_301         (26%)                */
/*   254  = TEN_FEC_MODE_OTUkV_SDH_A       (7%)                 */
/*   254  = TEN_FEC_MODE_OTUkV_SDH_B       (7%)                 */
/*   254  = TEN_FEC_MODE_OTUkV_4080_3929   (3.4%)               */
/*   254  = TEN_FEC_MODE_OTUkV_68_65       (4.2%)               */
/*   262  = TEN_FEC_MODE_OTUkV_263         (UFEC 7%)            */
/*   279  = TEN_FEC_MODE_OTUkV_280         (UFEC 18%)           */
/*   294  = TEN_FEC_MODE_OTUkV_295         (UFEC 25%)           */
/*                                                              */
/* The [fec_ovhd] parameter is specified as:                    */
/*   TEN_FEC_MODE_OTUkV             = 0,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_262         = 1,   ( 10%)               */
/*   TEN_FEC_MODE_OTUkV_273         = 2,   ( 15%)               */
/*   TEN_FEC_MODE_OTUkV_285         = 3,   ( 20%)               */
/*   TEN_FEC_MODE_OTUkV_297         = 4,   ( 25%)               */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5,   ( 25%)               */
/*   TEN_FEC_MODE_OTUkV_301         = 6,   ( 26%)               */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (  7%)               */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (3.4%)               */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10,  (4.2%)               */
/*   TEN_FEC_MODE_OTUkV_267         = 11,  ( 12%)               */
/*   TEN_FEC_MODE_OTUkV_270         = 12,  ( 13%).              */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_char8 *func = "ten_hl_ufec_ed_config";  /* __FUNCTION__ or __func__ not available for all compilers */

  cs_uint16 buf_5k_val = (((n_cols+1)*16*4)/32) - 1;
  cs_uint16 buf_10k_val = (((n_cols+1)*16*4)/16) - 1;
  cs_uint16 buf_15k_val = (((n_cols+1)*16*4*3)/32) - 1;

  /* Parameter Checking */
  if ((slice>=TEN_UFEC_COUNT) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() slice=%2", func, slice);
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() dir=%d", func, dir);
    return CS_ERROR;
  }
  if(ctrl > CS_ENABLE) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() ctrl=%d", func, ctrl);
    return CS_ERROR;
  }

  CS_PRINT("%s() %s, %s, %s, ctrl=%d, n_cols=%d\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           ten_dir_strings[dir],
           ctrl,
           n_cols);

  /* bugzilla #24589, lock/unlock not needed */

  ten_ufec_ed_config_buffer_size(module_id, slice, dir, 0, buf_5k_val);
  ten_ufec_ed_config_buffer_size(module_id, slice, dir, 1, buf_10k_val);
  ten_ufec_ed_config_buffer_size(module_id, slice, dir, 2, buf_15k_val);

  ten_ufec_ed_enable(module_id, slice, dir, ctrl);

  return (CS_OK);
}
#endif

/* Bugzilla 24339 Start */
/****************************************************************/
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_config_40g_fec_cb_t41 (cs_uint16 module_id,
                                     ten_fec_ovhd_t overhead,
                                     cs_boolean *provision_part,
                                     ten_fec_type_t *pfec_type)
/* INPUTS     : o Device Id                                     */
/*              o Overhead                                      */
/*              o Provision Part Pointer                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Check for FEC overallocation conflicts when provisioning a   */
/* 10G FEC on Slice 0                                           */
/*                                                              */
/* This API should be called only after the device corresponding*/
/* to this module has been registered.                          */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module;
  ten_dev_cb_t *pdevcb;
  ten_fec_cb_t *pfec_cb;
  cs_char8 *func = "ten_config_40g_fec_cb_t41";  /* __FUNCTION__ or __func__ not available for all compilers */

  module = TEN_MOD_ID_TO_MOD_NUM (module_id);
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);
  
  CS_PRINT("%s\n", func);
  
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR (dev_id);
  pfec_cb = &pdevcb->fec_cb;

  /* Take care of FEC disabling */
  if ((overhead == TEN_FEC_MODE_DEALLOCATE) || (overhead == TEN_FEC_MODE_ZEROFEC) || (overhead == TEN_FEC_MODE_NOFEC)) {
    /* 10G FEC is being deallocated */
    if (module == TEN_MODULE_A) {
      /* Provisioning Module A */
      if (pfec_cb->gfec0 == TEN_10G_40G_GFEC_40G_MODE) {
        pfec_cb->gfec0 = TEN_10G_40G_GFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_GFEC_40G;
      }
      else if (pfec_cb->ufec0 == TEN_40G_UFEC) {
        pfec_cb->ufec0 = TEN_UFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_UFEC_40G;
      }
      else {
        CS_PRINT("Neither GFEC nor UFEC was enabled\n");
      }
    } 
    else {
      /* Provisioning Module B */
      if (pfec_cb->gfec1 == TEN_10G_40G_GFEC_40G_MODE) {
        pfec_cb->gfec1 = TEN_10G_40G_GFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_GFEC_40G;
      }
      else if (pfec_cb->ufec1 == TEN_40G_UFEC) {
        pfec_cb->ufec1 = TEN_UFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_UFEC_40G;
      }
      else {
        CS_PRINT("Neither GFEC nor UFEC was enabled\n");
      }
    }
  }

  /* Take care of 40G FEC conflicts with 10G FECs */
  else if ((module == TEN_MODULE_A) && ((pfec_cb->gfec0 == TEN_10G_40G_GFEC_10G_MODE) ||
                                        (pfec_cb->gfec2 == TEN_10G_GFEC_MODULE_A) ||
                                        (pfec_cb->gfec3 == TEN_10G_GFEC_MODULE_A) ||
                                        (pfec_cb->gfec4 == TEN_10G_GFEC_MODULE_A) ||
                                        (pfec_cb->ufec0 == TEN_10G_UFEC_MODULE_A) ||
                                        (pfec_cb->ufec0 == TEN_10G_UFEC_MODULE_B) ||
                                        (pfec_cb->ufec1 == TEN_10G_UFEC_MODULE_A) ||
                                        (pfec_cb->ufec2 == TEN_10G_UFEC_MODULE_A) ||
                                        (pfec_cb->ufec3 == TEN_10G_UFEC_MODULE_A))) {
    /* Conflict because a 10G FEC is being use on module A */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use 40G FEC on module A when a 10G FEC is being used on module A", func);
    return (CS_ERROR);
  }
  else if ((module == TEN_MODULE_B) && ((pfec_cb->gfec1 == TEN_10G_40G_GFEC_10G_MODE) ||
                                        (pfec_cb->gfec2 == TEN_10G_GFEC_MODULE_B) ||
                                        (pfec_cb->gfec3 == TEN_10G_GFEC_MODULE_B) ||
                                        (pfec_cb->gfec4 == TEN_10G_GFEC_MODULE_B) ||
                                        (pfec_cb->ufec0 == TEN_10G_UFEC_MODULE_B) ||
                                        (pfec_cb->ufec1 == TEN_10G_UFEC_MODULE_A) ||
                                        (pfec_cb->ufec1 == TEN_10G_UFEC_MODULE_B) ||
                                        (pfec_cb->ufec2 == TEN_10G_UFEC_MODULE_B) ||
                                        (pfec_cb->ufec3 == TEN_10G_UFEC_MODULE_B))) {
    /* Conflict because 40G FEC is being use on module B */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use 40G FEC on module B when a 10G FEC is being used on module B", func);
    return (CS_ERROR);
  }

  else if (overhead == TEN_FEC_MODE_GFEC) {
    /* Provision 40G FEC for GFEC */
    if (module == TEN_MODULE_A) {
      if (pfec_cb->ufec0 == TEN_40G_UFEC) {
        /* Conflict because 40G UFEC is being used on module A */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use 40G GFEC on module A when a 40G UFEC is being used on module A", func);
        return (CS_ERROR);
      }
      /* Provisioning Module A */
      pfec_cb->gfec0 = TEN_10G_40G_GFEC_40G_MODE;
      *provision_part = TRUE;
    } else {
      if (pfec_cb->ufec1 == TEN_40G_UFEC) {
        /* Conflict because 40G UFEC is being used on module A */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use 40G GFEC on module B when a 40G UFEC is being used on module B", func);
        return (CS_ERROR);
      }
      /* Provisioning Module B */
      pfec_cb->gfec1 = TEN_10G_40G_GFEC_40G_MODE;
      *provision_part = TRUE;
    }
  }

  else {
    /* Provisioing 40G FEC for UFEC */
    if (module == TEN_MODULE_A) {
      if (pfec_cb->gfec0 == TEN_10G_40G_GFEC_40G_MODE) {
        /* Conflict because 40G GFEC is being used on module A */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use 40G UFEC on module A when a 40G GFEC is being used on module A", func);
        return (CS_ERROR);
      }
      /* Provisioning Module A */
      pfec_cb->ufec0 = TEN_40G_UFEC;
      *provision_part = TRUE;
    } 
    else {
      if (pfec_cb->gfec1 == TEN_10G_40G_GFEC_40G_MODE) {
        /* Conflict because 40G GFEC is being used on module B */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use 40G UFEC on module B when a 40G GFEC is being used on module B", func);
        return (CS_ERROR);
      }
      /* Provisioning Module B */
      pfec_cb->ufec1 = TEN_40G_UFEC;
      *provision_part = TRUE;
    }
  }
  return (CS_OK);
}

/****************************************************************/
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_config_10g_fec_cb_slot_0_t41 (cs_uint16 module_id,
                                            ten_fec_ovhd_t overhead,
                                            cs_boolean *provision_part,
                                            ten_fec_type_t *pfec_type)
/* INPUTS     : o Device Id                                     */
/*              o Overhead                                      */
/*              o Provision Part Pointer                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Check for FEC overallocation conflicts when provisioning a   */
/* 10G FEC on Slice 0                                           */
/*                                                              */
/* This API should be called only after the device corresponding*/
/* to this module has been registered.                          */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module;
  ten_dev_cb_t *pdevcb;
  ten_fec_cb_t *pfec_cb;
  cs_uint16 slice = 0;
  cs_char8 *func = "ten_config_10g_fec_cb_slot_0_t41";  /* __FUNCTION__ or __func__ not available for all compilers */

  module = TEN_MOD_ID_TO_MOD_NUM (module_id);
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR (dev_id);
  pfec_cb = &pdevcb->fec_cb;

  CS_PRINT("%s() %s, Slice %d, %s\n",
           func,
           ten_module_strings[module],
           slice,
           ten_fec_ovhd_strings[overhead]);


  /* Take care of FEC disabling */
  if ((overhead == TEN_FEC_MODE_DEALLOCATE) || (overhead == TEN_FEC_MODE_ZEROFEC) || (overhead == TEN_FEC_MODE_NOFEC)) {
    /* 10G FEC is being dealocated */
    if (module == TEN_MODULE_A) {
      /* Provisioning Module A */
      if (pfec_cb->gfec0 == TEN_10G_40G_GFEC_10G_MODE) {
        pfec_cb->gfec0 = TEN_10G_40G_GFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_GFEC_10G;
      }
      else if (pfec_cb->ufec0 == TEN_10G_UFEC_MODULE_A) {
        pfec_cb->ufec0 = TEN_UFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_UFEC_10G;
      }
      else {
        CS_PRINT("neither TEN_10G_40G_GFEC_10G_MODE or TEN_10G_UFEC_MODULE_A\n");
      }
    } else {
      /* Provisioning Module B */
      if (pfec_cb->gfec1 == TEN_10G_40G_GFEC_10G_MODE) {
        pfec_cb->gfec1 = TEN_10G_40G_GFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_GFEC_10G;
      }
      else if (pfec_cb->ufec0 == TEN_10G_UFEC_MODULE_B) {
        pfec_cb->ufec0 = TEN_UFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_UFEC_10G;
      }
      else {
         CS_PRINT("neither TEN_10G_40G_GFEC_10G_MODE or TEN_10G_UFEC_MODULE_B\n");
      }
    }
  }

  /* Take care of 10G FEC conflicts with 40G FECs */
  else if ((module == TEN_MODULE_A) && ((pfec_cb->gfec0 == TEN_10G_40G_GFEC_40G_MODE) || (pfec_cb->ufec0 == TEN_40G_UFEC))) {
    /* Conflict because 40G FEC is being use on module A */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G FEC on module A when a 40G FEC is being used on module A", func, slice);
    return (CS_ERROR);
  }
  /* Bugzilla 26179 Start */
  else if ((module == TEN_MODULE_B) && ((pfec_cb->gfec1 == TEN_10G_40G_GFEC_40G_MODE) || 
                                        (pfec_cb->ufec1 == TEN_40G_UFEC) ||  /* UFEC 1 40G is on side B only */
                                        ((pfec_cb->ufec0 == TEN_40G_UFEC) && (overhead != TEN_FEC_MODE_GFEC)) )) {
  /* Bugzilla 26179 End */
    /* Conflict because 40G FEC is being use on module B */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G FEC on module B when a 40G FEC is being used on module B", func, slice);
    return (CS_ERROR);
  }

  else if (overhead == TEN_FEC_MODE_GFEC) {
    /* Provision Slice's 10G FEC for GFEC */
    if (module == TEN_MODULE_A) {
      if (pfec_cb->ufec0 == TEN_10G_UFEC_MODULE_A) {
        /* Conflict because 40G UFEC is being used on module A */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use 10G GFEC on module A Slice 0 when a 10G UFEC is being used on module A Slice 0", func);
        return (CS_ERROR);
      }
      /* Provisioning Module A */
      pfec_cb->gfec0 = TEN_10G_40G_GFEC_10G_MODE;
      *provision_part = TRUE;
    } else {
      if (pfec_cb->ufec0 == TEN_10G_UFEC_MODULE_B) {
        /* Conflict because 40G UFEC is being used on module A */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use 10G GFEC on module B Slice 0 when a 10G UFEC is being used on module B Slice 0", func);
        return (CS_ERROR);
      }
      /* Provisioning Module B */
      pfec_cb->gfec1 = TEN_10G_40G_GFEC_10G_MODE;
      *provision_part = TRUE;
    }
  }

  else {
    /* Provisioing Slice's 10G FEC for UFEC */
    if (module == TEN_MODULE_A) {
      if (pfec_cb->gfec0 == TEN_10G_40G_GFEC_10G_MODE) {
        /* Conflict because this Slice's 10G  GFEC is being used on module A */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G UFEC on module A when 10G GFEC is being used on module B slice %d", func, slice, slice);
        return (CS_ERROR);
      }
      else if (pfec_cb->ufec0 == TEN_10G_UFEC_MODULE_B) {
        /* Conflict because this Slice's 10G  UFEC is being used on module B */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G UFEC on module A when it is being used on module B", func, slice);
        return (CS_ERROR);
      }
      /* Provisioning Module A */
      else {
        /* Provision Slice 1 module A for UFEC */
        pfec_cb->ufec0 = TEN_10G_UFEC_MODULE_A;
        *provision_part = TRUE;
      }
    } else {
      if (pfec_cb->gfec1 == TEN_10G_40G_GFEC_10G_MODE) {
        /* Conflict because this Slice's 10G  UFEC is being used on module A */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G UFEC on module B when 10G GFEC is being used on module B slice %d", func, slice, slice);
        return (CS_ERROR);
      }
      else if (pfec_cb->ufec0 == TEN_10G_UFEC_MODULE_A) {
        /* Conflict because this Slice's 10G  UFEC is being used on module A */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G UFEC on module B when it is being used on module A", func, slice);
        return (CS_ERROR);
      }
      /* Provisioning Module B */
      else {
        /* Provision Slice 1 module B for UFEC */
        pfec_cb->ufec0 = TEN_10G_UFEC_MODULE_B;
        *provision_part = TRUE;
      }
    }
  }
  return (CS_OK);
}

/****************************************************************/
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_config_10g_fec_cb_slot123_t41 (cs_uint16 module_id,
                                             cs_uint8 slice,
                                             ten_fec_ovhd_t overhead,
                                             cs_boolean *provision_part,
                                             ten_fec_type_t *pfec_type)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Overhead                                      */
/*              o Provision Part Pointer                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Check for FEC overallocation conflicts when provisioning a   */
/* 10G fec on Slice 1, 2 or 3                                   */
/*                                                              */
/* This API should be called only after the device corresponding*/
/* to this module has been registered.                          */
/****************************************************************/
{
  /*cs_boolean deallocate_fec = FALSE;*/
  cs_uint16 dev_id;
  cs_uint16 module;
  ten_dev_cb_t *pdevcb;
  ten_fec_cb_t *pfec_cb;
  ten_10g_gfec_t *pgfec_10g;
  ten_10g_40g_ufec_t *pufec_10g;
  cs_char8 *func = "ten_config_10g_fec_cb_slot123_t41";  /* __FUNCTION__ or __func__ not available for all compilers */

  module = TEN_MOD_ID_TO_MOD_NUM (module_id);
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR (dev_id);
  pfec_cb = &pdevcb->fec_cb;


  CS_PRINT("%s() %s, Slice %d, %s\n",
           func,
           ten_module_strings[module],
           slice,
           ten_fec_ovhd_strings[overhead]);


  /* Get pointer to 10G FEC control block elements */
  switch (slice) {
    case 1:
      pgfec_10g = &pfec_cb->gfec2;
      pufec_10g = &pfec_cb->ufec1;
      break;

    case 2:
      pgfec_10g = &pfec_cb->gfec3;
      pufec_10g = &pfec_cb->ufec2;
      break;

    case 3:
      pgfec_10g = &pfec_cb->gfec4;
      pufec_10g = &pfec_cb->ufec3;
      break;

    default:
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G UFEC on module A when it is being used on module B", func, slice);
      return (CS_ERROR);
  }


  /* Take care of FEC disabling */
  if ((overhead == TEN_FEC_MODE_DEALLOCATE) || (overhead == TEN_FEC_MODE_ZEROFEC) || (overhead == TEN_FEC_MODE_NOFEC)) {
    /* 10G FEC is being dealocated */
    if (module == TEN_MODULE_A) {
      /* Provisioning Module A */
      if (*pgfec_10g == TEN_10G_GFEC_MODULE_A) {
        /* 10G GFEC is currently on Module A, so disable it */
        *pgfec_10g = TEN_10G_GFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_GFEC_10G;
      }
      else if (*pufec_10g == TEN_10G_UFEC_MODULE_A) {
        /* 10G UFEC is currently on Module A, so disable it */
        *pufec_10g = TEN_UFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_UFEC_10G;
      }
    } else {
      /* Provisioning Module B */
      if (*pgfec_10g == TEN_10G_GFEC_MODULE_B) {
        /* 10G GFEC is currently on Module B, so disable it */
        *pgfec_10g = TEN_10G_GFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_GFEC_10G;
      }
      else if (*pufec_10g == TEN_10G_UFEC_MODULE_B) {
        /* 10G UFEC is currently on Module B, so disable it */
        *pufec_10g = TEN_UFEC_DISABLED;
        *provision_part = TRUE;
        *pfec_type = TEN_FEC_UFEC_10G;
      }
    }
  }

  /* Bugzilla 26179 Start */
  /* Take care of 10G FEC conflicts with 40G FECs */
  else if ((module == TEN_MODULE_A) && ((pfec_cb->gfec0 == TEN_10G_40G_GFEC_40G_MODE) || 
                                        (pfec_cb->ufec0 == TEN_40G_UFEC) ||  /* UFEC 0 40G is on side A only */
                                        ((slice == 1) && (pfec_cb->ufec1 == TEN_40G_UFEC) && (overhead != TEN_FEC_MODE_GFEC)) )) {
  /* Bugzilla 26179 End */
    /* Conflict because 40G FEC is being use on module A */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G FEC on module A when a 40G FEC is being used on module A", func, slice);
    return (CS_ERROR);
  }
  else if ((module == TEN_MODULE_B) && ((pfec_cb->gfec1 == TEN_10G_40G_GFEC_40G_MODE) || (pfec_cb->ufec1 == TEN_40G_UFEC))) {
    /* Conflict because 40G FEC is being use on module B */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G FEC on module B when a 40G FEC is being used on module B", func, slice);
    return (CS_ERROR);
  }




  else if (overhead == TEN_FEC_MODE_GFEC) {
    if (module == TEN_MODULE_A) {
      if (*pufec_10g == TEN_10G_UFEC_MODULE_A) {
        /* Conflict because this Slice's 10G UFEC is being used on this slice */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G GFEC on module A when 10G UFEC is being used on this slice", func, slice);
        return (CS_ERROR);
      }
      else if (*pgfec_10g == TEN_10G_GFEC_MODULE_B) {
        /* Conflict because this Slice's 10G  GFEC is being used on module B */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G GFEC on module A when it is being used on module B", func, slice);
        return (CS_ERROR);
      /* Provision Slice's 10G FEC for GFEC */
      } else {
        /* Provision Slice's 10G GFEC for module A */
        *pgfec_10g = TEN_10G_GFEC_MODULE_A;
        *provision_part = TRUE;
      }
    } else {
      if (*pufec_10g == TEN_10G_UFEC_MODULE_B) {
        /* Conflict because this Slice's 10G  UFEC is being used on this slice */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G GFEC on module B when 10G UFEC is being used this slice", func, slice);
        return (CS_ERROR);
      }
      /* Provisioning Module B */
      else if (*pgfec_10g == TEN_10G_GFEC_MODULE_A) {
        /* Conflict because this Slice's 10G  GFEC is being used on module A */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G GFEC on module B when it is being used on module A", func, slice);
        return (CS_ERROR);
      } else {
        /* Provision Slice's 10G GFEC for module B */
        *pgfec_10g = TEN_10G_GFEC_MODULE_B;
        *provision_part = TRUE;
      }
    }
  }

  else {
    /* Provisioing Slice's 10G FEC for UFEC */
    if (module == TEN_MODULE_A) {
      if (*pgfec_10g == TEN_10G_GFEC_MODULE_A) {
        /* Conflict because this Slice's 10G  GFEC is being used on this slice */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G UFEC on module A when 10G GFEC is being used this slice", func, slice);
        return (CS_ERROR);
      }
      else if (*pufec_10g == TEN_10G_UFEC_MODULE_B) {
        /* Conflict because this Slice's 10G  UFEC is being used on module B */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G UFEC on module A when it is being used on module B", func, slice);
        return (CS_ERROR);
      }
      else {
        /* Provision this Slice on module A for UFEC */
        *pufec_10g = TEN_10G_UFEC_MODULE_A;
        *provision_part = TRUE;
      }
    } else {
      if (*pgfec_10g == TEN_10G_GFEC_MODULE_B) {
        /* Conflict because this Slice's 10G  GFEC is being used on this slice */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G UFEC on module B when 10G GFEC is being used this slice", func, slice);
        return (CS_ERROR);
      }
      else if (*pufec_10g == TEN_10G_UFEC_MODULE_A) {
        /* Conflict because this Slice's 10G  UFEC is being used on module A */
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Attempt to use slice %d 10G UFEC on module B when it is being used on module A", func, slice);
        return (CS_ERROR);
      }

      /* Provisioning Module B */
      else {
        /* Provision this Slice on module B for UFEC */
        *pufec_10g = TEN_10G_UFEC_MODULE_B;
        *provision_part = TRUE;
      }
    }
  }
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG FEC                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_fec_t41 (cs_uint16 module_id,
                                 cs_uint8  slice,
                                 cs_uint16 size,
                                 cs_uint16 overhead)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FEC Type                                      */
/*              o Overhead                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable error decorelator                                     */
/*                                                              */
/* [module_id] specifies module ID                              */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE_3                                             */
/*   0xFF = SLICE_ALL                                           */
/*                                                              */
/* The [size] parameter is specified as:                        */
/*   0 = TEN_SLICE_10G                                          */
/*   1 = TEN_SLICE_40G                                          */
/*                                                              */
/* The [overhead] parameter is specified as (UFEC ONLY):        */
/*   TEN_FEC_MODE_OTUkV             = 0   (  7%)                */
/*   TEN_FEC_MODE_OTUkV_262         = 1   ( 10%)                */
/*   TEN_FEC_MODE_OTUkV_273         = 2   ( 15%)                */
/*   TEN_FEC_MODE_OTUkV_285         = 3   ( 20%)                */
/*   TEN_FEC_MODE_OTUkV_297         = 4   ( 25%)                */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5   ( 25%)                */
/*   TEN_FEC_MODE_OTUkV_301         = 6   ( 26%)                */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7   (  7%)                */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8   (  7%)                */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9   (3.4%)                */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10  (4.2%)                */
/*   TEN_FEC_MODE_OTUkV_267         = 11  ( 12%)                */
/*   TEN_FEC_MODE_OTUkV_270         = 12  ( 13%)                */
/*   TEN_FEC_MODE_GFEC              = 13  (  7%)                */
/*   TEN_FEC_MODE_ZEROFEC           = 14 (7% FEC is all zeroes) */
/*   TEN_FEC_MODE_NOFEC             = 15 ( 0%, FEC not present) */
/*   TEN_FEC_MODE_DEALLOCATE        = 16                        */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*  For GFEC it is always fixed at 7%                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_fec_cb_t *pfec_cb;
  ten_dev_cb_t *pdevcb;
  cs_uint16 dev_id;
  cs_uint16 module;
  cs_uint16 fec_en;
  ten_fec_type_t fec_type;
  T41_t *pDev = NULL;
  cs_boolean deallocate_fec = FALSE;
  cs_boolean provision_part = FALSE;
  cs_uint16 action;
  cs_char8 *func = "ten_hl_config_fec_t41";  /* __FUNCTION__ or __func__ not available for all compilers */

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  module = TEN_MOD_ID_TO_MOD_NUM (module_id);
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3.", func, slice);
    return (CS_ERROR);
  }

  if (size > TEN_SLICE_40G) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() size = 0x%04X is invalid\n", func, size);
    return(CS_ERROR);
  }

  if (overhead >= TEN_FEC_MODE_MAX_NUM) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() overhead = 0x%04Xis invalid\n", func, overhead);
    return(CS_ERROR);
  }

  CS_PRINT("%s() %s, Slice %d, %s, %s\n",
           func,
           ten_module_strings[module],
           slice,
           ten_slice_mode_strings[size],
           ten_fec_ovhd_strings[overhead]);

  if (size == TEN_SLICE_40G) {
    /* 40G FEC */
    if (slice > 0) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range for 40G.  s/b 0.", func, slice);
      return (CS_ERROR);
    }

    if (overhead ==  TEN_FEC_MODE_GFEC) {
      fec_type = TEN_FEC_GFEC_40G;
    } 
    else {
      fec_type = TEN_FEC_UFEC_40G;
    }
  } 
  else {
    /* 10G FEC */
    if (overhead ==  TEN_FEC_MODE_GFEC) {
      fec_type = TEN_FEC_GFEC_10G;
    } 
    else {
      fec_type = TEN_FEC_UFEC_10G;
    }
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR (dev_id);
  pfec_cb = &pdevcb->fec_cb;

  if ((overhead == TEN_FEC_MODE_DEALLOCATE) || (overhead == TEN_FEC_MODE_ZEROFEC) || (overhead == TEN_FEC_MODE_NOFEC)) {
    deallocate_fec = TRUE;
    action = TEN_FEC_BYPASS;
    fec_en = TEN_HL_MPIF_FEC_BYPASS;
  }
  else if (overhead == TEN_FEC_MODE_GFEC) {
    action = TEN_FEC_ACTIVE;
    fec_en = TEN_HL_MPIF_FEC_EN_GFEC;
  }
  else {
    action = TEN_FEC_ACTIVE;
    fec_en = TEN_HL_MPIF_FEC_EN_UFEC;
  }

  if (deallocate_fec) {
    /* Do not have to test if */

  }

  switch (slice) {
    case 0:
      if (size == TEN_SLICE_40G) {
        if (ten_config_40g_fec_cb_t41 (module_id, overhead, &provision_part, &fec_type) == CS_ERROR) {
          /* A FEC over-allocation or allocation conflict has occurred */
          CS_PRINT("%s() A FEC over-allocation or allocation conflict has occurred\n", func);
          return (CS_ERROR);
        }

      } 
      else {
        if (ten_config_10g_fec_cb_slot_0_t41 (module_id, overhead, &provision_part, &fec_type) == CS_ERROR) {
          /* A FEC over-allocation or allocation conflict has occurred */
          CS_PRINT("%s() A FEC over-allocation or allocation conflict has occurred\n", func);
          return (CS_ERROR);
        }
      }
      break;

    case 1:
    case 2:
    case 3:
      /* Port 3 so must be a 10G FEC */
      if (ten_config_10g_fec_cb_slot123_t41 (module_id, slice, overhead, &provision_part, &fec_type) == CS_ERROR) {
        /* A FEC over-allocation or allocation conflict has occurred */
        CS_PRINT("%s() A FEC over-allocation or allocation conflict has occurred\n", func);
        return (CS_ERROR);
      }
      break;
  }
  
  if (provision_part) {
    CS_PRINT("%s() provision registers, %s, %s\n", func, ten_fec_type_strings[fec_type], ten_mpif_fec_en_strings[fec_en]);

    /* Provison FEC registers */
    ten_hl_mpif_fec_init (module_id, slice, fec_type, fec_en);

    if (fec_en > 0) {
      ten_hl_fec_config (module_id, slice, fec_type, action, overhead);
    }
    else {
      ten_hl_fec_config (module_id, slice, fec_type, TEN_FEC_BYPASS, 0);
    }
  }
  else {
    CS_PRINT("Do not provision_part\n");
  }

  if (size == TEN_SLICE_40G) {
    if (overhead == TEN_FEC_MODE_NOFEC) {
        CS_PRINT("TEN_SLICE_40G, NOFEC\n");
        /* Configure scrambler/descrambler for GFEC */
        ten_n40g_otnr4x_descrambling (module_id, 0, 1, 1);
        ten_n40g_otnt4x_scrambling (module_id, 1, 0);

        /* Bypass FEC */
        ten_n40g_otnt4x_ocfg (module_id, 0, 0);
        ten_n40g_otnr4x_ocfg (module_id, 0, 0);

        /* Set number of FEC columns to 0 and frame size for no FEC columns */
        ten_n40g_otnr4x_set_ncols (module_id, 238);
        ten_n40g_otnr4x_set_nparb_npar (module_id, 0, 0);
        ten_n40g_otnt4x_set_ncols (module_id, 238);
        ten_n40g_otnt4x_set_nparb_npar (module_id, 0, 0);
    }
    else if (overhead == TEN_FEC_MODE_ZEROFEC) {
        CS_PRINT("TEN_SLICE_40G, ZEROFEC\n");
        /* Configure scrambler/descrambler for GFEC */
        ten_n40g_otnr4x_descrambling (module_id, 0, 1, 1);
        ten_n40g_otnt4x_scrambling (module_id, 1, 0);

        /* Bypass FEC */
        ten_n40g_otnt4x_ocfg (module_id, 0, 0);
        ten_n40g_otnr4x_ocfg (module_id, 0, 0);
    }
    else {
       CS_PRINT("TEN_SLICE_40G, not ZEROFEC or NOFEC\n");
    }
  } 
  else {
    if (overhead == TEN_FEC_MODE_NOFEC) {
        CS_PRINT("TEN_SLICE_10G, NOFEC\n");
        /* Configure scrambler/descrambler for GFEC */
        ten_n10g_otnr_descrambling (module_id, slice, 0, 1);
        ten_n10g_otnt_scrambling (module_id, slice, 1, 0);

        /* Bypass FEC */
        ten_n10g_otnt_ocfg (module_id, slice, 0, 0);
        ten_n10g_otnr_ocfg (module_id, slice, 0, 0);

        /* Set number of FEC columns to 0 and frame size for no FEC columns */
        ten_n10g_otnr_set_frame_format (module_id, slice, 238, 3, 0, 0);
        ten_n10g_otnt_set_frame_format (module_id, slice, 238, 3, 0, 0);
    }
    else if (overhead == TEN_FEC_MODE_ZEROFEC) {
        CS_PRINT("TEN_SLICE_10G, ZEROFEC\n");
        /* Configure scrambler/descrambler for GFEC */
        ten_n10g_otnr_descrambling (module_id, slice, 0, 1);
        ten_n10g_otnt_scrambling (module_id, slice, 1, 0);

        /* Bypass FEC */
        ten_n10g_otnt_ocfg (module_id, slice, 0, 0);
        ten_n10g_otnr_ocfg (module_id, slice, 0, 0);
    }
    else {
      CS_PRINT("TEN_SLICE_10G, not ZEROFEC or NOFEC\n");
    }
  }
  return (CS_OK);
}

/****************************************************************/
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_init_fec_cb (cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Initializes the device control block for the FECs.  All FECs */
/* start out as unalocated                                      */
/*                                                              */
/* This API should be called only after the device corresponding*/
/* to this module has been registered.                          */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /* 10G/40G GFEC blocks */
  pdevcb->fec_cb.gfec0 = TEN_10G_40G_GFEC_DISABLED;
  pdevcb->fec_cb.gfec1 = TEN_10G_40G_GFEC_DISABLED;

  /* 10G GFEC blocks */
  pdevcb->fec_cb.gfec2 = TEN_10G_GFEC_DISABLED;
  pdevcb->fec_cb.gfec3 = TEN_10G_GFEC_DISABLED;
  pdevcb->fec_cb.gfec4 = TEN_10G_GFEC_DISABLED;

  /* 10G/40G UFEC blocks */
  pdevcb->fec_cb.ufec0 = TEN_UFEC_DISABLED;
  pdevcb->fec_cb.ufec1 = TEN_UFEC_DISABLED;

  /* 10G UFEC blocks */
  pdevcb->fec_cb.ufec2 = TEN_UFEC_DISABLED;
  pdevcb->fec_cb.ufec3 = TEN_UFEC_DISABLED;

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  DEV PRINT FEC CB                             */
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_print_fec_cb_41 (cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Print the device control block for the FECs.                 */
/*                                                              */
/* This API should be called only after the device corresponding*/
/* to this module has been registered.                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;

  cs_char8 *func = "ten_dev_print_fec_cb_41";  /* __FUNCTION__ or __func__ not available for all compilers */
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /* 10G/40G GFEC blocks */
  CS_PRINT_OUTPUT("%s()\n", func);
  CS_PRINT_OUTPUT("    Module 0 GFEC0: %s\n", ten_10g_40g_gfec_strings[pdevcb->fec_cb.gfec0]);
  CS_PRINT_OUTPUT("    Module 1 GFEC1: %s\n", ten_10g_40g_gfec_strings[pdevcb->fec_cb.gfec1]);

  /* 10G GFEC blocks */
  CS_PRINT_OUTPUT("    Slice 1  GFEC2: %s\n", ten_10g_gfec_strings[pdevcb->fec_cb.gfec2]);
  CS_PRINT_OUTPUT("    Slice 2  GFEC3: %s\n", ten_10g_gfec_strings[pdevcb->fec_cb.gfec3]);
  CS_PRINT_OUTPUT("    Slice 3  GFEC4: %s\n", ten_10g_gfec_strings[pdevcb->fec_cb.gfec4]);

  /* 10G/40G UFEC blocks */
  CS_PRINT_OUTPUT("    Module 0/Slice 0 UFEC0: %s\n", ten_10g_40g_ufec_strings[pdevcb->fec_cb.ufec0]);
  CS_PRINT_OUTPUT("    Module 1/Slice 1 UFEC1: %s\n", ten_10g_40g_ufec_strings[pdevcb->fec_cb.ufec1]);

  /* 10G UFEC blocks */
  CS_PRINT_OUTPUT("    Slice 2  UFEC2: %s\n", ten_10g_40g_ufec_strings[pdevcb->fec_cb.ufec2]);
  CS_PRINT_OUTPUT("    Slice 3  UFEC3: %s\n", ten_10g_40g_ufec_strings[pdevcb->fec_cb.ufec3]);

  return (CS_OK);
}
/* Bugzilla 24339 End */

/****************************************************************/
/* $rtn_hdr_start  UFEC GET FEC USAGE STATUS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : FEC                                             */
/* CHIP       : Tenabo                                          */
cs_int16 ten_hl_get_fec_usage_status (cs_uint16 module_id,
                                      cs_uint8 slice,
                                      ten_fec_type_t fec_type)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o FEC Type                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    :  1 - Allocated; 0 - Not Allocated               */
/*              -1 - Invalid combination                        */
/* DESCRIPTION:                                                 */
/* Returns the status whether the FEC has been already allocated*/
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0    = SLICE_0                                             */
/*   1    = SLICE_1                                             */
/*   2    = SLICE_2                                             */
/*   3    = SLICE 3                                             */
/*                                                              */
/* The [fec_type] parameter is specified as:                    */
/*   0 = TEN_FEC_GFEC_10G                                       */
/*   1 = TEN_FEC_GFEC_40G                                       */
/*   2 = TEN_FEC_UFEC_10G                                       */
/*   3 = TEN_FEC_UFEC_40G                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module;
  TEN_MPIF_GLOBAL_RESET_GFEC_t tmp_global_reset_gfec;
  TEN_MPIF_GLOBAL_RESET_UFEC_t tmp_global_reset_ufec;
  TEN_MPIF_GFEC_CFG_t tmp_gfec_cfg;
  TEN_MPIF_UFEC_CFG_t tmp_ufec_cfg;
  cs_int16 ret_val = 0;

  T41_t *pDev = NULL;

  cs_char8 *func = "ten_hl_get_fec_usage_status";  /* __FUNCTION__ or __func__ not available for all compilers */
  CS_PRINT("%s()  slice = %d, fec_type=%d\n", func, slice, fec_type);

  module = TEN_MOD_ID_TO_MOD_NUM (module_id);
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  tmp_global_reset_gfec.wrd  = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GFEC));
  tmp_gfec_cfg.wrd =  TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GFEC_CFG));

  tmp_global_reset_ufec.wrd  = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_UFEC));
  tmp_ufec_cfg.wrd =  TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, UFEC_CFG));

  switch(fec_type) {
    case TEN_FEC_GFEC_10G:
      switch(slice) {
          case 0:
            if(module == 0) {
              if(tmp_gfec_cfg.bf.rxa_10g == 1) { /* 10G GFEC on A0 */
                if((tmp_global_reset_gfec.bf.Four0g_rx & 1) == 0)
                  ret_val = 1;
              }
            }
            else {
              if(tmp_gfec_cfg.bf.rxb_10g == 1) { /* 10G GFEC on B0 */
                if((tmp_global_reset_gfec.bf.Four0g_rx & 2) == 0)
                  ret_val = 1;
              }
            }
            break;

          case 1:
            if(module == 0) {
              if((tmp_gfec_cfg.bf.rx_b & 1) == 0) { /* 10G GFEC is on A1 */
                if((tmp_global_reset_gfec.bf.One0g_rx & 1) == 0)
                  ret_val = 1;
              }
            }
            else {
              if((tmp_gfec_cfg.bf.rx_b & 1) == 1) { /* 10G GFEC is on B1 */
                if((tmp_global_reset_gfec.bf.One0g_rx & 1) == 0)
                  ret_val = 1;
              }
            }
            break;

          case 2:
            if(module == 0) {
              if((tmp_gfec_cfg.bf.rx_b & 2) == 0) { /* 10G GFEC is on A2 */
                if((tmp_global_reset_gfec.bf.One0g_rx & 2) == 0)
                  ret_val = 1;
              }
            }
            else {
              if((tmp_gfec_cfg.bf.rx_b & 2) == 2) { /* 10G GFEC is on B2 */
                if((tmp_global_reset_gfec.bf.One0g_rx & 2) == 0)
                  ret_val = 1;
              }
            }
            break;

          case 3:
            if(module == 0) {
              if((tmp_gfec_cfg.bf.rx_b & 4) == 0) { /* 10G GFEC is on A3 */
                if((tmp_global_reset_gfec.bf.One0g_rx & 4) == 0)
                  ret_val = 1;
              }
            }
            else {
              if((tmp_gfec_cfg.bf.rx_b & 4) == 4) { /* 10G GFEC is on B3 */
                if((tmp_global_reset_gfec.bf.One0g_rx & 4) == 0)
                  ret_val = 1;
              }
            }
            break;

          default:
            CS_HNDL_ERROR(module, ETEN_MOD_INVALID_USER_ARG, ":  Invalid slice.");
            ret_val = CS_ERROR;
      }
      break;

    case TEN_FEC_GFEC_40G:
      switch(slice) {
          case 0:
            if(module == 0) {
              if(tmp_gfec_cfg.bf.rxa_10g == 0) { /* 40G GFEC on A0 */
                if((tmp_global_reset_gfec.bf.Four0g_rx & 1) == 0)
                  ret_val = 1;
              }
            }
            else {
              if(tmp_gfec_cfg.bf.rxb_10g == 0) { /* 40G GFEC on B0 */
                if((tmp_global_reset_gfec.bf.Four0g_rx & 2) == 0)
                  ret_val = 1;
              }
            }
            break;

          default:
            CS_HNDL_ERROR(module, ETEN_MOD_INVALID_USER_ARG, ":  Invalid slice.");
            ret_val = CS_ERROR;
            break;
      }
      break;

    case TEN_FEC_UFEC_10G:
      switch(slice) {
          case 0:
            if(module == 0) {
              if(tmp_ufec_cfg.bf.rx1_10g == 1) { /* 10G UFEC on A0 */
                if((tmp_ufec_cfg.bf.rx_b & 1) == 0) {
                  if((tmp_global_reset_ufec.bf.rx & 1) == 0)
                    ret_val = 1;
                }
              }
            }
            else {
              if((tmp_ufec_cfg.bf.rx_b & 1) == 1) { /* 10G UFEC on B0 */
                if((tmp_global_reset_ufec.bf.rx & 1) == 0)
                  ret_val = 1;
              }
            }
            break;

          case 1:
            if(module == 0) {
              if((tmp_ufec_cfg.bf.rx_b & 2) == 0) {  /* 10G UFEC on A1 */
                if((tmp_global_reset_ufec.bf.rx & 2) == 0)
                  ret_val = 1;
              }
            }
            else {
              if(tmp_ufec_cfg.bf.rx2_10g == 1) { /* 10G UFEC on B1 */
                if((tmp_ufec_cfg.bf.rx_b & 2) == 1) {
                  if((tmp_global_reset_ufec.bf.rx & 2) == 0)
                    ret_val = 1;
                }
              }
            }
            break;

          case 2:
            if(module == 0) {
              if((tmp_ufec_cfg.bf.rx_b & 4) == 0) {  /* 10G UFEC on A2 */
                if((tmp_global_reset_ufec.bf.rx & 4) == 0)
                  ret_val = 1;
              }
            }
            else {
              if((tmp_ufec_cfg.bf.rx_b & 2) == 1) {  /* 10G UFEC on B2 */
                if((tmp_global_reset_ufec.bf.rx & 4) == 0)
                  ret_val = 1;
              }
            }
            break;

          case 3:
            if(module == 0) {
              if((tmp_ufec_cfg.bf.rx_b & 8) == 0) {  /* 10G UFEC on A3 */
                if((tmp_global_reset_ufec.bf.rx & 8) == 0)
                  ret_val = 1;
              }
            }
            else {
              if((tmp_ufec_cfg.bf.rx_b & 8) == 1) {  /* 10G UFEC on B3 */
                if((tmp_global_reset_ufec.bf.rx & 8) == 0)
                  ret_val = 1;
              }
            }
            break;

          default:
            CS_HNDL_ERROR(module, ETEN_MOD_INVALID_USER_ARG, ":  Invalid slice.");
            ret_val = CS_ERROR;
            break;
      }
      break;

    case TEN_FEC_UFEC_40G:
      switch(slice) {
          case 0:
            if(module == 0) {
              if(tmp_ufec_cfg.bf.rx1_10g == 0) { /* 40G UFEC on A0 */
                if((tmp_global_reset_ufec.bf.rx & 1) == 0)
                  ret_val = 1;
              }
            }
            break;

          case 1:
            if(module == 1) {
              if(tmp_ufec_cfg.bf.rx2_10g == 0) { /* 40G UFEC on B1 */
                if((tmp_global_reset_ufec.bf.rx & 2) == 0)
                  ret_val = 1;
              }
            }
            break;

          default:
            CS_HNDL_ERROR(module, ETEN_MOD_INVALID_USER_ARG, ":  Invalid slice.");
            ret_val = CS_ERROR;
            break;
      }
      break;

    default:
      ret_val = CS_ERROR;
      break;
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (ret_val);
}
